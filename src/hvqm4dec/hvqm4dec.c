#include "types.h"
#include "hvqm4.h"

/*

Initial code attempts + comments + function arguments/naming guides taken from
http://github.com/Tilka/hvqm4
with many thanks.

Variable names are mostly from Bakuten Shoot Beyblade 2002.

*/

static u8 clipTable[0x200];
static int divTable[0x10];
static int mcdivTable[0x200];

static int readTree_signed;
static u32 readTree_scale;

// some things are per plane (luma, 2x chroma)
#define PLANE_COUNT 3
// some things are only split between luma and chroma
#define LUMA_CHROMA 2
#define LUMA_IDX    0
#define CHROMA_IDX  1

#define read8(buf, offset)  (*(u8*)((u8*)(buf) + (offset)))
#define read16(buf, offset) (*(u16*)((u8*)(buf) + (offset)))
#define read32(buf, offset) (*(u32*)((u8*)(buf) + (offset)))

static inline u8 saturate(int x)
{
	if (x < 0) {
		return 0;
	} else if (x > 0xFF) {
		return 0xFF;
	} else {
		return x;
	}
}

static inline u8 sat_mean8(int u)
{
	return saturate((u + 4) / 8);
}

/*
 * --INFO--
 * Address:	8001EC3C
 * Size:	000360
 */
static void init_global_constants()
{
	int i;
	int n;

	for (i = 0, n = -0x80; i < 0x200; i++, n++) {
		clipTable[i] = saturate(n);
	}

	divTable[0] = 0;
	for (i = 1; i < 0x10; i++) {
		divTable[i] = 0x1000 / (i * 16) * 16;
	}

	mcdivTable[0] = 0;
	for (i = 1; i < 0x200; i++) {
		mcdivTable[i] = 0x1000 / i;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
static void set_border(BlockData* p)
{
	p->dcv = 0x7F;
	p->bnm = 0xFF;
}

/*
 * --INFO--
 * Address:	8001EF9C
 * Size:	00011C
 */
static void setHVQPlaneDesc(SeqObj* obj, int id, u8 h_samp, u8 v_samp)
{
	u32 mcb, pb;
	HVQPlaneDesc* plane = &((VideoState*)obj->ws)->pln[id];
	plane->h_shift      = (h_samp == 2) ? 1 : 0;
	plane->plane_width  = obj->frame_width >> plane->h_shift;
	plane->v_shift      = (v_samp == 2) ? 1 : 0;
	plane->plane_height = obj->frame_height >> plane->v_shift;
	plane->plane_size   = plane->plane_width * plane->plane_height;

	// pixels per 2x2 block
	plane->hvqblk_h    = 2 >> plane->h_shift;               // 1..2
	plane->hvqblk_v    = 2 >> plane->v_shift;               // 1..2
	plane->nblocks_mcb = plane->hvqblk_h * plane->hvqblk_v; // 1..4
	// number of 4x4 blocks
	plane->nblocks_h = obj->frame_width / (h_samp * 4);
	plane->nblocks_v = obj->frame_height / (v_samp * 4);
	// number of 4x4 blocks + border
	plane->nblocks_hb = plane->nblocks_h + 2;
	plane->nblocks_vb = plane->nblocks_v + 2;
	// offset of blocks in MCB
	plane->bibUscan[0] = 0;
	plane->bibUscan[3] = 1;
	mcb                = plane->nblocks_hb;
	plane->bibUscan[1] = mcb;
	plane->bibUscan[2] = mcb + 1;

	plane->imgUscan[0] = 0;
	plane->imgUscan[3] = 4;
	pb                 = plane->plane_width << 2;
	plane->imgUscan[1] = pb;
	plane->imgUscan[2] = pb + 4;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
static void setCode(BitBuffer* dst, u8* top)
{
	u32 size  = read32(top, 0);
	dst->size = size;
	if (size == 0) {
		dst->ptr = NULL;
	} else {
		dst->ptr = top + 4;
	}
	dst->bit = -1;
}

/*
 * --INFO--
 * Address:	8001F7E8
 * Size:	000040
 */
static inline int getBit(BitBuffer* buf)
{
	u32 value;
	int bit;
	if ((bit = buf->bit) < 0) {
		value = buf->value = *((u32*)buf->ptr)++;
		bit                = 31;
	} else {
		value = buf->value;
	}
	value    = value >> bit & 1;
	buf->bit = bit - 1;
	return value;
}

/*
 * --INFO--
 * Address:	8001F384
 * Size:	000064
 */
static inline s16 getByte(BitBuffer* buf)
{
	u32 value;
	int bit;
	if ((bit = buf->bit) >= 7) {
		value = buf->value;
		value >>= bit - 7;
		bit -= 8;
	} else {
		value = buf->value;
		value <<= 7 - bit;
		buf->value = *((u32*)buf->ptr)++;
		value |= buf->value >> (bit + 25);
		bit += 24;
	}
	buf->bit = bit;
	value &= 0xFF;
	return value;
}
/*
 * --INFO--
 * Address:	8001F0B8
 * Size:	0002CC
 */
static s16 _readTree(Tree* dst, BitBuffer* src)
{
	int badCompiler[2];
	if (getBit(src)) {
		// recurse
		int node_number = dst->node_number++;
		// read the 0 side of the tree
		dst->leaf[0][node_number] = _readTree(dst, src);
		// read the 1 side of the tree
		dst->leaf[1][node_number] = _readTree(dst, src);
		return node_number;
	} else {
		// leaf node
		s16 byte   = getByte(src);
		s16 symbol = byte;
		if (readTree_signed && byte > 0x7F)
			symbol -= 0x100;
		symbol <<= readTree_scale;
		dst->leaf[0][byte] = symbol;
		return byte;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
static void readTree(BitBufferWithTree* buf_with_tree, int is_signed, int scale)
{
	Tree* tree     = buf_with_tree->tree;
	BitBuffer* buf = &buf_with_tree->buf;

	readTree_signed   = is_signed;
	readTree_scale    = scale;
	tree->node_number = 0x100;
	if (buf->size != 0) {
		tree->tree_root = _readTree(tree, buf);
	} else {
		tree->tree_root = 0;
	}
}

/*
 * --INFO--
 * Address:	8001F828
 * Size:	000070
 */
static inline int decodeHuff(BitBufferWithTree* buf)
{
	Tree* tree        = buf->tree;
	BitBuffer* buffer = &buf->buf;
	int pos           = tree->tree_root;
	while (pos >= 0x100) {
		pos = tree->leaf[getBit(buffer)][pos];
	}
	return tree->leaf[0][pos];
}

// used for DC values
static inline int decodeSOvfSym(BitBufferWithTree* buf, int range_min, int range_max)
{
	int ret = 0;
	int num;
	do {
		num = decodeHuff(buf);
		ret += num;
	} while (!(range_min < num && num < range_max));
	return ret;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
static inline int decodeUOvfSym(BitBufferWithTree* buf, int range_max)
{
	int ret = 0;
	int num;
	do {
		num = decodeHuff(buf);
		ret += num;
	} while (num >= range_max);
	return ret;
}

/*
 * --INFO--
 * Address:	8001F3E8
 * Size:	0002C4
 */
static void Ipic_BasisNumDec(VideoState* ws)
{
	s16 sym;
	int runln;
	BlockData* y_dat;
	BlockData* u_dat;
	BlockData* v_dat;
	int i, j;
	int h_block, v_block;
	BitBufferWithTree* symcode;
	BitBufferWithTree* runcode;

	runln   = 0;
	y_dat   = ws->pln[LUMA_IDX].blockInfoTop;
	symcode = &ws->bsnum[LUMA_IDX];
	runcode = &ws->bsrun[LUMA_IDX];
	h_block = ws->pln[LUMA_IDX].nblocks_h;
	v_block = ws->pln[LUMA_IDX].nblocks_v;
	for (j = v_block; j > 0; j--) {
		for (i = h_block; i > 0; i--) {
			if (runln == 0) {
				sym = decodeHuff(symcode);
				if (sym == 0)
					runln = decodeHuff(runcode);
				y_dat++->bnm = sym & 0xFF;
			} else {
				y_dat++->bnm = 0;
				runln--;
			}
		}
		// skip borders
		y_dat += 2;
	}

	runln   = 0;
	symcode = &ws->bsnum[CHROMA_IDX];
	runcode = &ws->bsrun[CHROMA_IDX];
	u_dat   = ws->pln[1].blockInfoTop;
	v_dat   = ws->pln[2].blockInfoTop;
	h_block = ws->pln[CHROMA_IDX].nblocks_h;
	v_block = ws->pln[CHROMA_IDX].nblocks_v;
	for (i = v_block; i > 0; i--) {
		for (j = h_block; j > 0; j--) {
			if (runln == 0) {
				sym = decodeHuff(symcode);
				if (sym == 0)
					runln = decodeHuff(runcode);
				u_dat++->bnm = (sym >> 0) & 0xF;
				v_dat++->bnm = (sym >> 4) & 0xF;
			} else {
				u_dat++->bnm = 0;
				v_dat++->bnm = 0;
				runln--;
			}
		}
		u_dat += 2;
		v_dat += 2;
	}
}

static inline int getDeltaDC(VideoState* ws, int c, int* runln)
{
	int d;

	if (*runln == 0) {
		d = decodeSOvfSym(&ws->dcval[c], ws->dc_min, ws->dc_max);
		// successive zeroes are run-length encoded
		if (d == 0)
			*runln = decodeHuff(&ws->dcrun[c]);
		return d;
	} else {
		(*runln)--;
		return 0;
	}
}

/*
 * --INFO--
 * Address:	8001F6AC
 * Size:	00013C
 */
static void IpicDcvDec(VideoState* ws)
{
	int c;
	BlockData* curr;
	BlockData* prev;
	int run;
	int pred;
	int nblocks_hb;
	int h_block, v_block;
	int i, j;

	for (c = 0; c < PLANE_COUNT; c++) {
		h_block    = ws->pln[c].nblocks_h;
		v_block    = ws->pln[c].nblocks_v;
		nblocks_hb = ws->pln[c].nblocks_hb;
		curr       = ws->pln[c].blockInfoTop;
		run        = 0;
		for (j = v_block; j > 0; j--) {
			// pointer to previous line
			prev = curr - nblocks_hb;
			!prev;
			// first prediction on a line is only the previous line's value
			pred = prev->dcv;
			for (i = h_block; i > 0; i--) {
				u8 curr_dcv;
				u8 prev_dcv;

				curr_dcv = pred + getDeltaDC(ws, c, &run);
				prev++;
				prev_dcv    = prev->dcv;
				curr++->dcv = curr_dcv;
				// next prediction on this line is the mean of left (current) and top values
				// +---+---+
				// |   | T |
				// +---+---+
				// | L | P |
				// +---+---+
				pred = (prev_dcv + curr_dcv + 1) >> 1;
			}
			// skip right border of this line and left border of next line
			curr += 2;
		}
	}
}

/*
 * --INFO--
 * Address:	8001F898
 * Size:	0003A4
 */
static void MakeNest(VideoState* ws, int x, int y)
{
	int h_block, nblocks_hb, v_block;
	BlockData* src;
	int h_dc_orderly, v_dc_orderly;
	int h_dc_reverse, v_dc_reverse;
	int h_nest_blank, v_nest_blank;
	int i, j;
	u8* nestP;
	u8* backP;
	BlockData* dP;
	u8* nP;

	h_block    = ws->pln[0].nblocks_h;
	nblocks_hb = ws->pln[0].nblocks_hb;
	v_block    = ws->pln[0].nblocks_v;
	src        = ws->pln[0].blockInfoTop + (y * nblocks_hb + x);

	if (h_block < ws->nestsize_h) {
		// special case if the video is less than 280 pixels wide (assuming landscape mode)
		h_dc_orderly = h_block;
		if ((h_dc_reverse = ws->nestsize_h - h_block) > h_block)
			h_dc_reverse = h_block;
		h_nest_blank = ws->nestsize_h - (h_dc_orderly + h_dc_reverse);
	} else {
		h_dc_orderly = ws->nestsize_h;
		h_dc_reverse = h_nest_blank = 0;
	}

	if (v_block < ws->nestsize_v) {
		// special case if the video is less than 152 pixels high
		v_dc_orderly = v_block;
		if ((v_dc_reverse = ws->nestsize_v - v_block) > v_block)
			v_dc_reverse = v_block;
		v_nest_blank = ws->nestsize_v - (v_dc_orderly + v_dc_reverse);
	} else {
		v_dc_orderly = ws->nestsize_v;
		v_dc_reverse = v_nest_blank = 0;
	}

	nP = ws->nestBuf;
	for (j = v_dc_orderly; j > 0; j--) {
		dP = src;
		for (i = h_dc_orderly; i > 0; i--) {
			*nP++ = (dP->dcv >> 4) & 0xF;
			dP++;
		}
		// if the video is too small, mirror it
		for (i = h_dc_reverse; i > 0; i--) {
			dP--;
			*nP++ = (dP->dcv >> 4) & 0xF;
		}
		// if it is still too small, null out the rest
		for (i = h_nest_blank; i > 0; i--)
			*nP++ = 0;
		src += nblocks_hb;
	}

	// handle vertical mirroring
	nestP = nP - ws->nestsize_h;
	for (j = v_dc_reverse; j > 0; j--) {
		backP = nestP;
		for (i = ws->nestsize_h; i > 0; i--) {
			*nP++ = *backP++;
		}
		nestP -= ws->nestsize_h;
	}

	// and vertical nulling
	for (j = v_nest_blank; j > 0; j--) {
		for (i = ws->nestsize_h; i > 0; i--) {
			*nP++ = 0;
		}
	}
}

/*
 * --INFO--
 * Address:	8001FC3C
 * Size:	000198
 */
static void WeightImBlock(u8* block, int blockWidth, u8 c, u8 u, u8 d, u8 l, u8 r)
{
	/*

+---+---+---+
|   | T |   |
+---+---+---+
| L | D | R |
+---+---+---+
|   | B |   |
+---+---+---+

 */
	// int u_d; // r6
	// int l_r; // r8
	// int v1; // r9
	// int v2; // r11
	// int c2; // r28
	// int c3; // r12
	// int t1; // r31
	// int t2; // r30
	// int t3; // r29
	// int t4; // r28
	// int t5; // r27
	// int t6; // r26
	// int t7; // r23
	// int t8; // r11

	int tmb = u - d;
	int lmr = l - r;
	int vph = tmb + lmr;
	int vmh = tmb - lmr;

	int v2 = c * 2;
	int v8 = c * 8;

	int tpl = (u + l) - v2;
	int tpr = (u + r) - v2;
	int bpr = (d + r) - v2;
	int bpl = (d + l) - v2;

	int tml = u - l;
	int tmr = u - r;
	int bmr = d - r;
	int bml = d - l;

	// V:
	// 6  8  8 6
	// 8 10 10 8
	// 8 10 10 8
	// 6  8  8 6
	//
	// T:
	//  2  2  2  2
	//  0  0  0  0
	// -1 -1 -1 -1
	// -1 -1 -1 -1
	//
	// B/L/R: like T but rotated accordingly

	// (6*V + 2*T - B + 2*L -   R + 4) / 8
	// (8*V + 2*T - B       -   R + 4) / 8
	// (8*V + 2*T - B -   L       + 4) / 8
	// (6*V + 2*T - B -   L + 2*R + 4) / 8

	block[0] = clipTable[v8 + vph + tpl];
	block[1] = clipTable[v8 + vph + tml];
	block[2] = clipTable[v8 + vmh + tmr];
	block[3] = clipTable[v8 + vmh + tpr];

	block += blockWidth;

	// ( 8*V - B + 2*L -   R + 4) / 8
	// (10*V - B       -   R + 4) / 8
	// (10*V - B -   L       + 4) / 8
	// ( 8*V - B -   L + 2*R + 4) / 8

	block[0] = clipTable[v8 + vph - tml];
	block[1] = clipTable[v8 - bpr];
	block[2] = clipTable[v8 - bpl];
	block[3] = clipTable[v8 + vmh - tmr];

	block += blockWidth;

	// ( 8*V - T + 2*L - R + 4) / 8
	// (10*V - T       - R + 4) / 8
	// (10*V - T - L

	block[0] = clipTable[v8 - vmh - bml];
	block[1] = clipTable[v8 - tpr];
	block[2] = clipTable[v8 - tpl];
	block[3] = clipTable[v8 - vph - bmr];

	block += blockWidth;

	block[0] = clipTable[v8 - vmh + bpl];
	block[1] = clipTable[v8 - vmh + bml];
	block[2] = clipTable[v8 - vph + bmr];
	block[3] = clipTable[v8 - vph + bpr];

	/*
	.loc_0x0:
	  stwu      r1, -0x40(r1)
	  rlwinm    r10,r7,0,24,31
	  rlwinm    r11,r5,3,21,28
	  stmw      r23, 0x1C(r1)
	  rlwinm    r24,r6,0,24,31
	  rlwinm    r0,r8,0,24,31
	  rlwinm    r7,r9,0,24,31
	  rlwinm    r28,r5,1,23,30
	  add       r5, r24, r0
	  lis       r6, 0x8039
	  sub       r8, r24, r10
	  sub       r23, r0, r7
	  addi      r12, r11, 0x4
	  subi      r6, r6, 0x4300
	  add       r9, r8, r23
	  sub       r31, r5, r28
	  sub       r11, r8, r23
	  add       r5, r12, r9
	  add       r23, r31, r5
	  add       r8, r24, r7
	  sub       r30, r8, r28
	  sub       r27, r24, r0
	  sub       r26, r24, r7
	  add       r24, r10, r7
	  addi      r6, r6, 0x80
	  srawi     r23, r23, 0x3
	  sub       r29, r24, r28
	  lbzx      r24, r6, r23
	  add       r23, r27, r5
	  add       r25, r0, r10
	  stb       r24, 0x0(r3)
	  srawi     r23, r23, 0x3
	  lbzx      r24, r6, r23
	  add       r8, r12, r11
	  add       r23, r26, r8
	  stb       r24, 0x1(r3)
	  srawi     r23, r23, 0x3
	  add       r24, r30, r8
	  lbzx      r23, r6, r23
	  sub       r28, r25, r28
	  srawi     r25, r24, 0x3
	  sub       r24, r5, r27
	  stb       r23, 0x2(r3)
	  sub       r5, r12, r11
	  lbzx      r25, r6, r25
	  sub       r11, r10, r0
	  srawi     r24, r24, 0x3
	  stb       r25, 0x3(r3)
	  add       r27, r3, r4
	  sub       r0, r12, r29
	  lbzx      r25, r6, r24
	  srawi     r3, r0, 0x3
	  sub       r0, r12, r28
	  srawi     r24, r0, 0x3
	  stb       r25, 0x0(r27)
	  sub       r0, r8, r26
	  lbzx      r26, r6, r3
	  srawi     r25, r0, 0x3
	  sub       r3, r10, r7
	  stb       r26, 0x1(r27)
	  sub       r8, r5, r11
	  srawi     r26, r8, 0x3
	  lbzx      r8, r6, r24
	  sub       r7, r12, r30
	  srawi     r10, r7, 0x3
	  stb       r8, 0x2(r27)
	  sub       r0, r12, r9
	  sub       r7, r12, r31
	  lbzx      r12, r6, r25
	  srawi     r9, r7, 0x3
	  sub       r7, r0, r3
	  stb       r12, 0x3(r27)
	  add       r27, r27, r4
	  srawi     r8, r7, 0x3
	  lbzx      r12, r6, r26
	  add       r7, r28, r5
	  add       r3, r3, r0
	  stb       r12, 0x0(r27)
	  srawi     r7, r7, 0x3
	  add       r5, r11, r5
	  lbzx      r10, r6, r10
	  srawi     r5, r5, 0x3
	  srawi     r3, r3, 0x3
	  stb       r10, 0x1(r27)
	  add       r0, r29, r0
	  srawi     r0, r0, 0x3
	  lbzx      r9, r6, r9
	  stb       r9, 0x2(r27)
	  lbzx      r8, r6, r8
	  stb       r8, 0x3(r27)
	  add       r27, r27, r4
	  lbzx      r4, r6, r7
	  stb       r4, 0x0(r27)
	  lbzx      r4, r6, r5
	  stb       r4, 0x1(r27)
	  lbzx      r3, r6, r3
	  stb       r3, 0x2(r27)
	  lbzx      r0, r6, r0
	  stb       r0, 0x3(r27)
	  lmw       r23, 0x1C(r1)
	  addi      r1, r1, 0x40
	  blr
	*/
}

// 4x4 block of single value
static void dcBlock(u8* block, int blockWidth, u8 dc)
{
	int i;

	for (i = 0; i < 4; i++) {
		block[0] = block[1] = block[2] = block[3] = dc;
		block += blockWidth;
	}
}

/*
 * --INFO--
 * Address:	8001FDD4
 * Size:	000048
 */
static void OrgBlock(VideoState* ws, u8* block, int blockWidth, int p)
{
	// TODO: unrolled loop?
	// int i;
	BitBuffer* buf;
	u32* ptr;
	u32 temp1;
	u32 temp2;
	u32 temp3;

	buf                          = &ws->aotcd[p];
	ptr                          = (u32*)buf->ptr;
	temp1                        = ptr[1];
	temp2                        = ptr[2];
	temp3                        = ptr[3];
	*(u32*)(block)               = ptr[0];
	*(u32*)(block += blockWidth) = temp1;
	*(u32*)(block += blockWidth) = temp2;
	*(u32*)(block += blockWidth) = temp3;
	buf->ptr                     = (u8*)ptr + 16;
}

/*
 * --INFO--
 * Address:	800201EC
 * Size:	00047C
 */
static inline u32 GetAotBasis(VideoState* ws, u8 basisOut[4][4], s32* pscl, u8* nestTop, int nestWidth, int p)
{
	u16 code;
	int step_x, step_y;
	u8 min, max;
	u8* nP;
	u8 value;

	code = *ws->aotcd[p].ptr++ << 8;
	code |= *ws->aotcd[p].ptr++;

	// the nest size 70x38 is chosen to allow for
	// 6/5-bit coordinates (0..63 x 0..31) + largest sampling pattern (6x6) = 0..69 x 0..37
	// 0x003F: offset70 : 6
	// 0x07C0: offset38 : 5
	// 0x0800: stride70 : 1
	// 0x1000: stride38 : 1
	// 0x6000: offset   : 2
	// 0x8000: negated  : 1

	// compute the offset inside the nest
	// offset70 = code & 0x3F;
	// offset38 = (code >> 6) & 0x1F;
	// stride70 = (code >> 11) & 1;
	// stride38 = (code >> 12) & 1;
	if (ws->landscape) {
		nestTop += ((code >> 6) & 0x1F) * nestWidth + (code & 0x3F);
		step_x = 1 << ((code >> 11) & 1);
		step_y = nestWidth << ((code >> 12) & 1);
	} else {
		nestTop += (code & 0x3F) * nestWidth + ((code >> 6) & 0x1F);
		step_x = 1 << ((code >> 12) & 1);
		step_y = nestWidth << ((code >> 11) & 1);
	}

	nP = nestTop;

	value          = *nP;
	basisOut[0][0] = value;
	min = max = value;

	nP += step_x;

	value          = *nP;
	basisOut[0][1] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = *nP;
	basisOut[0][2] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = *nP;
	basisOut[0][3] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestTop += step_y;
	nP = nestTop;

	value          = *nP;
	basisOut[1][0] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = *nP;
	basisOut[1][1] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = *nP;
	basisOut[1][2] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = *nP;
	basisOut[1][3] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestTop += step_y;
	nP = nestTop;

	value          = *nP;
	basisOut[2][0] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = *nP;
	basisOut[2][1] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = *nP;
	basisOut[2][2] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = *nP;
	basisOut[2][3] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestTop += step_y;
	nP = nestTop;

	value          = *nP;
	basisOut[3][0] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = *nP;
	basisOut[3][1] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = *nP;
	basisOut[3][2] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = *nP;
	basisOut[3][3] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	*pscl += decodeHuff(&ws->scale[p]);
	if (code & 0x8000) {
		return -divTable[max - min] * (*pscl + ((code >> 13) & 3));
	} else {
		return divTable[max - min] * (*pscl + ((code >> 13) & 3));
	}
}

/*
 * --INFO--
 * Address:	80022700
 * Size:	0004C4
 */
static inline u32 GetMCAotBasis(VideoState* ws, u8 basisOut[4][4], s32* pscl, u8* nestTop, int nestWidth, int p)
{
	// the only difference to GetAotBasis() seems to be the ">> 4 & 0xF"

	u16 code;
	int step_x, step_y;
	u8 min, max;
	u8* nP;
	u8 value;

	code = *ws->aotcd[p].ptr++ << 8;
	code |= *ws->aotcd[p].ptr++;

	if (ws->landscape) {
		nestTop += ((code >> 6) & 0x1F) * nestWidth + (code & 0x3F);
		step_x = 1 << ((code >> 11) & 1);
		step_y = nestWidth << ((code >> 12) & 1);
	} else {
		nestTop += (code & 0x3F) * nestWidth + ((code >> 6) & 0x1F);
		step_x = 1 << ((code >> 12) & 1);
		step_y = nestWidth << ((code >> 11) & 1);
	}

	nP = nestTop;

	value          = (*nP >> 4) & 0xF;
	basisOut[0][0] = value;
	min = max = value;

	nP += step_x;

	value          = (*nP >> 4) & 0xF;
	basisOut[0][1] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = (*nP >> 4) & 0xF;
	basisOut[0][2] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = (*nP >> 4) & 0xF;
	basisOut[0][3] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestTop += step_y;
	nP = nestTop;

	value          = (*nP >> 4) & 0xF;
	basisOut[1][0] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = (*nP >> 4) & 0xF;
	basisOut[1][1] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = (*nP >> 4) & 0xF;
	basisOut[1][2] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = (*nP >> 4) & 0xF;
	basisOut[1][3] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestTop += step_y;
	nP = nestTop;

	value          = (*nP >> 4) & 0xF;
	basisOut[2][0] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = (*nP >> 4) & 0xF;
	basisOut[2][1] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = (*nP >> 4) & 0xF;
	basisOut[2][2] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = (*nP >> 4) & 0xF;
	basisOut[2][3] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestTop += step_y;
	nP = nestTop;

	value          = (*nP >> 4) & 0xF;
	basisOut[3][0] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = (*nP >> 4) & 0xF;
	basisOut[3][1] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = (*nP >> 4) & 0xF;
	basisOut[3][2] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value          = (*nP >> 4) & 0xF;
	basisOut[3][3] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	*pscl += decodeHuff(&ws->scale[p]);
	if (code & 0x8000) {
		return -divTable[max - min] * (*pscl + ((code >> 13) & 3));
	} else {
		return divTable[max - min] * (*pscl + ((code >> 13) & 3));
	}
}

static inline int GetAotSum(VideoState* state, int result[4][4], u8 num_bases, u8 const* nestBuf, u32 nest_stride, u32 plane_idx)
{
	int x, y, k;
	u8 basis[4][4];
	s32 temp;
	u32 factor;
	int sum;
	int mean;

	for (y = 0; y < 4; ++y)
		for (x = 0; x < 4; ++x)
			result[y][x] = 0;
	temp = 0;
	for (k = 0; k < num_bases; ++k) {
		factor = GetAotBasis(state, basis, &temp, nestBuf, nest_stride, plane_idx);
		for (y = 0; y < 4; ++y)
			for (x = 0; x < 4; ++x)
				result[y][x] += factor * basis[y][x];
	}
	sum = 0;
	for (y = 0; y < 4; ++y)
		for (x = 0; x < 4; ++x)
			sum += result[y][x];
	mean = sum >> 4;
	return mean;
}

static inline int GetMCAotSum(VideoState* state, int result[4][4], u8 num_bases, u8 const* nestBuf, u32 nest_stride, u32 plane_idx)
{
	int i, j, k;
	s32 temp;
	u8 byte_result[4][4];
	u32 factor;
	int sum;
	int mean;

	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			result[i][j] = 0;

	temp = 0;
	for (k = 0; k < num_bases; ++k) {
		factor = GetMCAotBasis(state, byte_result, &temp, nestBuf, nest_stride, plane_idx);
		for (i = 0; i < 4; ++i)
			for (j = 0; j < 4; ++j)
				result[i][j] += factor * byte_result[i][j];
	}
	sum = 0;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			sum += result[i][j];
	mean = sum >> 4;
	return mean;
}

/*
 * --INFO--
 * Address:	8001FE1C
 * Size:	0003D0
 *
 * @note: AOT = Adaptive Orthogonal Transform, apparently
 */
static void IntraAotBlock(VideoState* state, u8* dst, u32 stride, u8 targetAverage, u8 blockType, u32 planeIdx)
{
	int result[4][4];
	int aotAverage, delta;
	int x, y, value;

	if (blockType == 6) {
		OrgBlock(state, dst, stride, planeIdx);
		return;
	}
	// block types 1..5 serve as number of bases to use, 9..15 are unused
	aotAverage = GetAotSum(state, result, blockType, state->nestBuf, state->nestsize_h, planeIdx);
	delta      = (targetAverage << state->aotscale_q) - aotAverage;
	for (y = 0; y < 4; ++y) {
		for (x = 0; x < 4; ++x) {
			value               = ((result[y][x] + delta) >> state->aotscale_q);
			dst[y * stride + x] = saturate(value);
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r7,0,24,31
	  cmplwi    r0, 0x6
	  stwu      r1, -0x100(r1)
	  stmw      r15, 0xBC(r1)
	  addi      r21, r3, 0
	  addi      r30, r4, 0
	  stw       r5, 0x74(r1)
	  stb       r6, 0x78(r1)
	  stw       r8, 0x7C(r1)
	  bne-      .loc_0x48
	  lwz       r5, 0x74(r1)
	  addi      r3, r21, 0
	  lwz       r6, 0x7C(r1)
	  addi      r4, r30, 0
	  bl        -0x88
	  b         .loc_0x3BC

	.loc_0x48:
	  lhz       r0, 0x625C(r21)
	  li        r31, 0
	  lbz       r19, 0x6CD0(r21)
	  addi      r29, r7, 0
	  stw       r0, 0x98(r1)
	  li        r0, 0
	  stw       r0, 0x1C(r1)
	  addi      r15, r31, 0
	  addi      r16, r31, 0
	  stw       r31, 0x94(r1)
	  addi      r17, r31, 0
	  addi      r18, r31, 0
	  stw       r31, 0x90(r1)
	  stw       r31, 0x8C(r1)
	  stw       r31, 0x88(r1)
	  stw       r31, 0x84(r1)
	  stw       r31, 0x80(r1)
	  stw       r31, 0xB4(r1)
	  stw       r31, 0xB0(r1)
	  stw       r31, 0xAC(r1)
	  stw       r31, 0xA8(r1)
	  stw       r31, 0xA4(r1)
	  b         .loc_0x1E8

	.loc_0xA4:
	  lwz       r7, 0x98(r1)
	  mr        r3, r21
	  lwz       r8, 0x7C(r1)
	  addi      r4, r1, 0x20
	  addi      r5, r1, 0x1C
	  addi      r6, r21, 0x6261
	  bl        .loc_0x3D0
	  lbz       r5, 0x20(r1)
	  lbz       r4, 0x21(r1)
	  mullw     r5, r3, r5
	  lbz       r8, 0x25(r1)
	  lbz       r9, 0x24(r1)
	  lbz       r7, 0x26(r1)
	  lbz       r26, 0x27(r1)
	  mullw     r4, r3, r4
	  stw       r5, 0x9C(r1)
	  lbz       r6, 0x28(r1)
	  lbz       r5, 0x29(r1)
	  lbz       r0, 0x22(r1)
	  stw       r4, 0xA0(r1)
	  mullw     r25, r3, r8
	  lwz       r8, 0x9C(r1)
	  lbz       r4, 0x2D(r1)
	  lbz       r10, 0x23(r1)
	  lbz       r12, 0x2A(r1)
	  add       r18, r18, r8
	  lwz       r8, 0xA0(r1)
	  mullw     r9, r3, r9
	  lbz       r28, 0x2B(r1)
	  lbz       r27, 0x2C(r1)
	  lbz       r11, 0x2F(r1)
	  add       r17, r17, r8
	  lwz       r8, 0xA4(r1)
	  mullw     r24, r3, r7
	  add       r8, r8, r9
	  stw       r8, 0xA4(r1)
	  mullw     r23, r3, r6
	  lwz       r8, 0xA8(r1)
	  mullw     r20, r3, r0
	  lbz       r0, 0x2E(r1)
	  add       r8, r8, r25
	  stw       r8, 0xA8(r1)
	  mullw     r22, r3, r5
	  lwz       r8, 0xAC(r1)
	  add       r8, r8, r24
	  stw       r8, 0xAC(r1)
	  mullw     r10, r3, r10
	  lwz       r8, 0xB0(r1)
	  mullw     r26, r3, r26
	  add       r8, r8, r26
	  stw       r8, 0xB0(r1)
	  mullw     r5, r3, r12
	  lwz       r8, 0xB4(r1)
	  add       r8, r8, r23
	  stw       r8, 0xB4(r1)
	  mullw     r6, r3, r28
	  lwz       r8, 0x80(r1)
	  add       r8, r8, r22
	  stw       r8, 0x80(r1)
	  mullw     r7, r3, r27
	  lwz       r8, 0x84(r1)
	  add       r8, r8, r5
	  lwz       r5, 0x88(r1)
	  mullw     r4, r3, r4
	  stw       r8, 0x84(r1)
	  add       r5, r5, r6
	  stw       r5, 0x88(r1)
	  mullw     r0, r3, r0
	  lwz       r5, 0x8C(r1)
	  add       r5, r5, r7
	  stw       r5, 0x8C(r1)
	  mullw     r3, r3, r11
	  lwz       r5, 0x90(r1)
	  add       r5, r5, r4
	  lwz       r4, 0x94(r1)
	  stw       r5, 0x90(r1)
	  add       r16, r16, r20
	  add       r4, r4, r0
	  stw       r4, 0x94(r1)
	  add       r15, r15, r10
	  add       r31, r31, r3

	.loc_0x1E8:
	  rlwinm.   r0,r29,0,24,31
	  subi      r29, r29, 0x1
	  bne+      .loc_0xA4
	  add       r0, r17, r16
	  lwz       r8, 0xB0(r1)
	  add       r3, r0, r15
	  lwz       r0, 0xA4(r1)
	  add       r3, r3, r0
	  lwz       r0, 0xA8(r1)
	  add       r3, r3, r0
	  lwz       r0, 0xAC(r1)
	  add       r3, r3, r0
	  lwz       r0, 0xB0(r1)
	  add       r3, r3, r0
	  lwz       r0, 0xB4(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x80(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x84(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x88(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x8C(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x90(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x94(r1)
	  add       r0, r3, r0
	  add       r0, r0, r31
	  add       r4, r18, r0
	  lbz       r0, 0x78(r1)
	  lis       r3, 0x8039
	  srawi     r4, r4, 0x4
	  slw       r0, r0, r19
	  sub       r0, r0, r4
	  subi      r3, r3, 0x4300
	  add       r4, r18, r0
	  addi      r3, r3, 0x80
	  sraw      r4, r4, r19
	  lbzx      r4, r3, r4
	  add       r5, r17, r0
	  sraw      r5, r5, r19
	  stb       r4, 0x0(r30)
	  add       r4, r16, r0
	  sraw      r4, r4, r19
	  lbzx      r6, r3, r5
	  add       r5, r15, r0
	  sraw      r7, r5, r19
	  lwz       r5, 0xA4(r1)
	  stb       r6, 0x1(r30)
	  add       r5, r5, r0
	  lbzx      r4, r3, r4
	  sraw      r6, r5, r19
	  lwz       r5, 0xA8(r1)
	  add       r8, r8, r0
	  stb       r4, 0x2(r30)
	  add       r5, r5, r0
	  lwz       r4, 0xAC(r1)
	  lbzx      r7, r3, r7
	  sraw      r5, r5, r19
	  add       r4, r4, r0
	  stb       r7, 0x3(r30)
	  sraw      r4, r4, r19
	  lwz       r7, 0x74(r1)
	  sraw      r8, r8, r19
	  lbzx      r6, r3, r6
	  add       r30, r30, r7
	  lwz       r7, 0xB4(r1)
	  stb       r6, 0x0(r30)
	  add       r7, r7, r0
	  lwz       r6, 0x84(r1)
	  lbzx      r5, r3, r5
	  sraw      r11, r7, r19
	  lwz       r7, 0x80(r1)
	  add       r6, r6, r0
	  stb       r5, 0x1(r30)
	  add       r7, r7, r0
	  lwz       r5, 0x8C(r1)
	  lbzx      r4, r3, r4
	  sraw      r7, r7, r19
	  sraw      r10, r6, r19
	  lwz       r6, 0x88(r1)
	  stb       r4, 0x2(r30)
	  add       r6, r6, r0
	  lwz       r4, 0x94(r1)
	  lbzx      r8, r3, r8
	  sraw      r6, r6, r19
	  add       r5, r5, r0
	  stb       r8, 0x3(r30)
	  sraw      r9, r5, r19
	  lwz       r8, 0x74(r1)
	  add       r4, r4, r0
	  lwz       r5, 0x90(r1)
	  add       r30, r30, r8
	  lbzx      r8, r3, r11
	  add       r5, r5, r0
	  stb       r8, 0x0(r30)
	  sraw      r5, r5, r19
	  sraw      r4, r4, r19
	  lbzx      r7, r3, r7
	  add       r0, r31, r0
	  sraw      r0, r0, r19
	  stb       r7, 0x1(r30)
	  lbzx      r7, r3, r10
	  stb       r7, 0x2(r30)
	  lbzx      r6, r3, r6
	  stb       r6, 0x3(r30)
	  lwz       r6, 0x74(r1)
	  add       r30, r30, r6
	  lbzx      r6, r3, r9
	  stb       r6, 0x0(r30)
	  lbzx      r5, r3, r5
	  stb       r5, 0x1(r30)
	  lbzx      r4, r3, r4
	  stb       r4, 0x2(r30)
	  lbzx      r0, r3, r0
	  stb       r0, 0x3(r30)

	.loc_0x3BC:
	  lmw       r15, 0xBC(r1)
	  lwz       r0, 0x104(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr

	.loc_0x3D0:
	*/
}

/*
 * --INFO--
 * Address:	80020668
 * Size:	000144
 */
static void IpicBlockDec(VideoState* state, u8* dst, u32 stride, StackState* stackState)
{
	u8 top, bottom, right;
	u8 value;

	if (stackState->curr.bnm == 0) {
		value  = stackState->curr.dcv;
		top    = stackState->upp->bnm & 0x77 ? value : stackState->upp->dcv;
		bottom = stackState->low->bnm & 0x77 ? value : stackState->low->dcv;
		right  = stackState->right.bnm & 0x77 ? value : stackState->right.dcv;
		// the left value is tracked manually, the logic is equivalent with the other surrounding values
		WeightImBlock(dst, stride, value, top, bottom, stackState->l_dcv, right);
		stackState->l_dcv = value;
	} else if (stackState->curr.bnm == 8) {
		value = stackState->curr.dcv;
		dcBlock(dst, stride, value);
		stackState->l_dcv = value;
	} else {
		IntraAotBlock(state, dst, stride, stackState->curr.dcv, stackState->curr.bnm, stackState->id);
		// don't use the current DC value to predict the next one
		stackState->l_dcv = stackState->right.dcv;
	}
	// next block
	++stackState->upp;
	++stackState->low;
}

/*
 * --INFO--
 * Address:	800207AC
 * Size:	0000D4
 */
static void IpicLineDec(VideoState* state, u8* dst, u32 stride, StackState* stackState, u32 hBlocks)
{
	int i;

	stackState->right = *stackState->mid;
	stackState->l_dcv = stackState->mid->dcv;

	for (i = hBlocks - 1; i > 0; i--) {
		stackState->curr  = stackState->right;
		stackState->right = *++stackState->mid;
		IpicBlockDec(state, dst, stride, stackState);
		dst += 4;
	}

	stackState->curr = stackState->right;
	stackState->mid += 3;
	IpicBlockDec(state, dst, stride, stackState);
	stackState->upp += 2;
	stackState->low += 2;
}

/*
 * --INFO--
 * Address:	80020880
 * Size:	0000DC
 */
static void IpicPlaneDec(VideoState* state, int plane_idx, u8* dst)
{
	HVQPlaneDesc* plane;
	BlockData** payload_ptr;
	u32 plane_width;
	u32 stride;
	u32 dst_stride;
	u32 nblocks_h;
	u32 nblocks_hb;
	BlockData* blockInfoTop;
	int i;
	StackState stack_state;

	plane       = &state->pln[plane_idx];
	plane_width = plane->plane_width;
	nblocks_h   = plane->nblocks_h;
	nblocks_hb  = plane->nblocks_hb;
	payload_ptr = &plane->blockInfoTop;

	stack_state.id  = plane_idx;
	blockInfoTop    = *payload_ptr;
	stack_state.upp = blockInfoTop;
	stack_state.mid = blockInfoTop;
	stack_state.low = blockInfoTop + nblocks_hb;

	// blocks are 4x4 so advance dst by 4 lines
	dst_stride = plane_width * 4;
	stride     = plane_width;

	// first line
	IpicLineDec(state, dst, stride, &stack_state, nblocks_h);
	dst += dst_stride;
	// middle lines
	stack_state.upp = *payload_ptr;
	for (i = plane->nblocks_v - 2; i > 0; i--) {
		IpicLineDec(state, dst, stride, &stack_state, nblocks_h);
		dst += dst_stride;
	}
	// last line
	stack_state.low = stack_state.mid;
	IpicLineDec(state, dst, stride, &stack_state, nblocks_h);

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mulli     r0, r4, 0x38
	  stwu      r1, -0x50(r1)
	  stmw      r25, 0x34(r1)
	  addi      r25, r3, 0
	  add       r31, r25, r0
	  mr        r26, r5
	  addi      r30, r31, 0x4
	  lhz       r8, 0x28(r31)
	  lhz       r27, 0x8(r31)
	  lhz       r0, 0xC(r31)
	  mr        r28, r8
	  addi      r5, r28, 0
	  stw       r4, 0x14(r1)
	  rlwinm    r0,r0,1,0,30
	  addi      r4, r26, 0
	  lwz       r6, 0x4(r31)
	  addi      r7, r27, 0
	  rlwinm    r29,r8,2,0,29
	  stw       r6, 0x18(r1)
	  add       r0, r6, r0
	  stw       r6, 0x1C(r1)
	  addi      r6, r1, 0x14
	  stw       r0, 0x20(r1)
	  bl        -0x138
	  lwz       r0, 0x0(r30)
	  add       r26, r26, r29
	  stw       r0, 0x18(r1)
	  lhz       r3, 0xA(r31)
	  subi      r30, r3, 0x2
	  b         .loc_0xA0

	.loc_0x80:
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  addi      r5, r28, 0
	  addi      r7, r27, 0
	  addi      r6, r1, 0x14
	  bl        -0x168
	  add       r26, r26, r29
	  subi      r30, r30, 0x1

	.loc_0xA0:
	  cmpwi     r30, 0
	  bgt+      .loc_0x80
	  lwz       r0, 0x1C(r1)
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  stw       r0, 0x20(r1)
	  addi      r5, r28, 0
	  addi      r7, r27, 0
	  addi      r6, r1, 0x14
	  bl        -0x198
	  lmw       r25, 0x34(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8002095C
 * Size:	00008C
 */
static void initMCHandler(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], u8* lin_top, u8* forw, u8* back)
{
	int i;
	MCPlane* mcplane;
	HVQPlaneDesc* plane;
	BlockData* block;

	for (i = 0; i < PLANE_COUNT; i++) {
		mcplane            = &mcplanes[i];
		plane              = &state->pln[i];
		mcplane->bsrunleng = 0;
		mcplane->prev_dcv  = 0x7F;
		mcplane->lin_top   = lin_top;
		mcplane->forw      = forw;
		mcplane->back      = back;

		block             = plane->blockInfoTop;
		mcplane->data     = block;
		mcplane->data_top = block;

		mcplane->next_macro_pix = 8 >> plane->h_shift;
		mcplane->down_macro_pix = (8 >> plane->v_shift) * plane->plane_width;
		mcplane->hvqblk_h       = plane->hvqblk_h;
		mcplane->hvqblk_v       = plane->nblocks_hb * plane->hvqblk_v;

		lin_top += plane->plane_size;
		forw += plane->plane_size;
		back += plane->plane_size;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
static void resetMCHandler(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], u8* lin_top)
{
	int i;

	for (i = 0; i < PLANE_COUNT; ++i) {
		mcplanes[i].lin_top  = lin_top;
		mcplanes[i].data_top = mcplanes[i].data = state->pln[i].blockInfoTop;
		lin_top += state->pln[i].plane_size;
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800209E8
 * Size:	00009C
 *
 * @note Copy 4x4 samples without interpolation.
 */
inline void _MotionComp_00(void* dst, u32 dstStride, const void* src, u32 srcStride)
{
	u8* s = (u8*)src;
	u8* d = (u8*)dst;

	d[0] = s[0];
	d[1] = s[1];
	d[2] = s[2];
	d[3] = s[3];
	s += srcStride;
	d += dstStride;

	d[0] = s[0];
	d[1] = s[1];
	d[2] = s[2];
	d[3] = s[3];
	s += srcStride;
	d += dstStride;

	d[0] = s[0];
	d[1] = s[1];
	d[2] = s[2];
	d[3] = s[3];
	s += srcStride;
	d += dstStride;

	d[0] = s[0];
	d[1] = s[1];
	d[2] = s[2];
	d[3] = s[3];
	s += srcStride;
	d += dstStride;
}

/*
 * --INFO--
 * Address:	80020A84
 * Size:	0001AC
 *
 * @note Offset vertically by half a sample
 */
inline void _MotionComp_01(void* dst, u32 dstStride, const void* src, u32 srcStride)
{
	u8* s = (u8*)src;
	u8* n = (u8*)src + srcStride;
	u8* d = (u8*)dst;

	d[0] = (s[0] + n[0] + 1) >> 1;
	d[1] = (s[1] + n[1] + 1) >> 1;
	d[2] = (s[2] + n[2] + 1) >> 1;
	d[3] = (s[3] + n[3] + 1) >> 1;
	s += srcStride;
	n += srcStride;
	d += dstStride;

	d[0] = (s[0] + n[0] + 1) >> 1;
	d[1] = (s[1] + n[1] + 1) >> 1;
	d[2] = (s[2] + n[2] + 1) >> 1;
	d[3] = (s[3] + n[3] + 1) >> 1;
	s += srcStride;
	n += srcStride;
	d += dstStride;

	d[0] = (s[0] + n[0] + 1) >> 1;
	d[1] = (s[1] + n[1] + 1) >> 1;
	d[2] = (s[2] + n[2] + 1) >> 1;
	d[3] = (s[3] + n[3] + 1) >> 1;
	s += srcStride;
	n += srcStride;
	d += dstStride;

	d[0] = (s[0] + n[0] + 1) >> 1;
	d[1] = (s[1] + n[1] + 1) >> 1;
	d[2] = (s[2] + n[2] + 1) >> 1;
	d[3] = (s[3] + n[3] + 1) >> 1;
	s += srcStride;
	n += srcStride;
	d += dstStride;
}

/*
 * --INFO--
 * Address:	80020C30
 * Size:	00019C
 *
 * @note Offset vertically by half a sample
 */
inline void _MotionComp_10(void* dst, u32 dstStride, const void* src, u32 srcStride)
{
	u8* s = (u8*)src;
	u8* d = (u8*)dst;

	d[0] = (s[0] + s[1] + 1) >> 1;
	d[1] = (s[1] + s[2] + 1) >> 1;
	d[2] = (s[2] + s[3] + 1) >> 1;
	d[3] = (s[3] + s[4] + 1) >> 1;
	s += srcStride;
	d += dstStride;

	d[0] = (s[0] + s[1] + 1) >> 1;
	d[1] = (s[1] + s[2] + 1) >> 1;
	d[2] = (s[2] + s[3] + 1) >> 1;
	d[3] = (s[3] + s[4] + 1) >> 1;
	s += srcStride;
	d += dstStride;

	d[0] = (s[0] + s[1] + 1) >> 1;
	d[1] = (s[1] + s[2] + 1) >> 1;
	d[2] = (s[2] + s[3] + 1) >> 1;
	d[3] = (s[3] + s[4] + 1) >> 1;
	s += srcStride;
	d += dstStride;

	d[0] = (s[0] + s[1] + 1) >> 1;
	d[1] = (s[1] + s[2] + 1) >> 1;
	d[2] = (s[2] + s[3] + 1) >> 1;
	d[3] = (s[3] + s[4] + 1) >> 1;
	s += srcStride;
	d += dstStride;
}

/*
 * --INFO--
 * Address:	80020DCC
 * Size:	0002AC
 *
 * @note Offset by half a sample in both directions
 */
inline void _MotionComp_11(void* dst, u32 dstStride, const void* src, u32 srcStride)
{
	u8* s = (u8*)src;
	u8* n = (u8*)src + srcStride;
	u8* d = (u8*)dst;

	d[0] = (s[0] + s[1] + n[0] + n[1] + 2) >> 2;
	d[1] = (s[1] + s[2] + n[1] + n[2] + 2) >> 2;
	d[2] = (s[2] + s[3] + n[2] + n[3] + 2) >> 2;
	d[3] = (s[3] + s[4] + n[3] + n[4] + 2) >> 2;
	s += srcStride;
	d += dstStride;
	n += srcStride;
	d[0] = (s[0] + s[1] + n[0] + n[1] + 2) >> 2;
	d[1] = (s[1] + s[2] + n[1] + n[2] + 2) >> 2;
	d[2] = (s[2] + s[3] + n[2] + n[3] + 2) >> 2;
	d[3] = (s[3] + s[4] + n[3] + n[4] + 2) >> 2;
	s += srcStride;
	d += dstStride;
	n += srcStride;
	d[0] = (s[0] + s[1] + n[0] + n[1] + 2) >> 2;
	d[1] = (s[1] + s[2] + n[1] + n[2] + 2) >> 2;
	d[2] = (s[2] + s[3] + n[2] + n[3] + 2) >> 2;
	d[3] = (s[3] + s[4] + n[3] + n[4] + 2) >> 2;
	s += srcStride;
	d += dstStride;
	n += srcStride;
	d[0] = (s[0] + s[1] + n[0] + n[1] + 2) >> 2;
	d[1] = (s[1] + s[2] + n[1] + n[2] + 2) >> 2;
	d[2] = (s[2] + s[3] + n[2] + n[3] + 2) >> 2;
	d[3] = (s[3] + s[4] + n[3] + n[4] + 2) >> 2;
	s += srcStride;
	d += dstStride;
	n += srcStride;
}

/*
 * --INFO--
 * Address:	80021078
 * Size:	000A00
 *
 * @note hpel = half-pixel offset. DX = horizontal, DY = vertical.
 */
static void MotionComp(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], int arg2, int arg3)
{
	int i, j;
	u32* imgUscan;
	u8* src;
	int num_blocks;
	int offset;

	if (!(arg2 & 1)) {
		if (!(arg3 & 1)) {
			for (i = 0; i < HVQM_PLANE_COUNT; i++) {
				src = mcplanes[i].targ
				    + ((arg2 >> state->pln[i].h_shift + 1) + (arg3 >> state->pln[i].v_shift + 1) * state->pln[i].plane_width);
				imgUscan   = state->pln[i].imgUscan;
				num_blocks = state->pln[i].nblocks_mcb;
				for (j = 0; j < num_blocks; j++) {
					offset = *imgUscan++;
					_MotionComp_00(mcplanes[i].blk_top + offset, state->pln[i].plane_width, src + offset, state->pln[i].plane_width);
				}
			}
		} else {
			for (i = 0; i < HVQM_PLANE_COUNT; i++) {
				src = mcplanes[i].targ
				    + ((arg2 >> state->pln[i].h_shift + 1) + (arg3 >> state->pln[i].v_shift + 1) * state->pln[i].plane_width);
				imgUscan   = state->pln[i].imgUscan;
				num_blocks = state->pln[i].nblocks_mcb;
				for (j = 0; j < num_blocks; j++) {
					offset = *imgUscan++;
					_MotionComp_01(mcplanes[i].blk_top + offset, state->pln[i].plane_width, src + offset, state->pln[i].plane_width);
				}
			}
		}
	} else {
		if (!(arg3 & 1)) {
			for (i = 0; i < HVQM_PLANE_COUNT; i++) {
				src = mcplanes[i].targ
				    + ((arg2 >> state->pln[i].h_shift + 1) + (arg3 >> state->pln[i].v_shift + 1) * state->pln[i].plane_width);
				imgUscan   = state->pln[i].imgUscan;
				num_blocks = state->pln[i].nblocks_mcb;
				for (j = 0; j < num_blocks; j++) {
					offset = *imgUscan++;
					_MotionComp_10(mcplanes[i].blk_top + offset, state->pln[i].plane_width, src + offset, state->pln[i].plane_width);
				}
			}
		} else {
			for (i = 0; i < HVQM_PLANE_COUNT; i++) {
				src = mcplanes[i].targ
				    + ((arg2 >> state->pln[i].h_shift + 1) + (arg3 >> state->pln[i].v_shift + 1) * state->pln[i].plane_width);
				imgUscan   = state->pln[i].imgUscan;
				num_blocks = state->pln[i].nblocks_mcb;
				for (j = 0; j < num_blocks; j++) {
					offset = *imgUscan++;
					_MotionComp_11(mcplanes[i].blk_top + offset, state->pln[i].plane_width, src + offset, state->pln[i].plane_width);
				}
			}
		}
	}
	/*
	.loc_0x0:
	  stwu      r1, -0x48(r1)
	  rlwinm.   r0,r5,0,31,31
	  stmw      r27, 0x34(r1)
	  bne-      .loc_0x4C0
	  rlwinm.   r0,r6,0,31,31
	  bne-      .loc_0x2A0
	  li        r7, 0

	.loc_0x1C:
	  lbz       r10, 0x30(r3)
	  addi      r8, r3, 0x18
	  lbz       r9, 0x31(r3)
	  addi      r0, r10, 0x1
	  lbz       r12, 0x34(r3)
	  sraw      r11, r5, r0
	  lhz       r0, 0x28(r3)
	  addi      r9, r9, 0x1
	  lwz       r10, 0x18(r4)
	  sraw      r9, r6, r9
	  mullw     r0, r9, r0
	  add       r0, r0, r10
	  cmpwi     r12, 0
	  addi      r10, r12, 0
	  add       r0, r11, r0
	  ble-      .loc_0x288
	  rlwinm.   r9,r10,31,1,31
	  mtctr     r9
	  beq-      .loc_0x1D0

	.loc_0x68:
	  lwz       r12, 0x0(r8)
	  lwz       r11, 0x14(r4)
	  add       r29, r0, r12
	  lhz       r27, 0x28(r3)
	  lbz       r9, 0x0(r29)
	  add       r28, r11, r12
	  add       r12, r29, r27
	  stb       r9, 0x0(r28)
	  add       r11, r28, r27
	  lbz       r9, 0x1(r29)
	  stb       r9, 0x1(r28)
	  lbz       r9, 0x2(r29)
	  stb       r9, 0x2(r28)
	  lbz       r9, 0x3(r29)
	  stb       r9, 0x3(r28)
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  stb       r9, 0x3(r11)
	  lwz       r12, 0x4(r8)
	  addi      r8, r8, 0x8
	  lwz       r11, 0x14(r4)
	  add       r29, r0, r12
	  lhz       r27, 0x28(r3)
	  lbz       r9, 0x0(r29)
	  add       r28, r11, r12
	  add       r12, r29, r27
	  stb       r9, 0x0(r28)
	  add       r11, r28, r27
	  lbz       r9, 0x1(r29)
	  stb       r9, 0x1(r28)
	  lbz       r9, 0x2(r29)
	  stb       r9, 0x2(r28)
	  lbz       r9, 0x3(r29)
	  stb       r9, 0x3(r28)
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  stb       r9, 0x3(r11)
	  bdnz+     .loc_0x68
	  andi.     r10, r10, 0x1
	  beq-      .loc_0x288

	.loc_0x1D0:
	  mtctr     r10

	.loc_0x1D4:
	  lwz       r12, 0x0(r8)
	  addi      r8, r8, 0x4
	  lwz       r11, 0x14(r4)
	  add       r29, r0, r12
	  lhz       r27, 0x28(r3)
	  lbz       r9, 0x0(r29)
	  add       r28, r11, r12
	  add       r12, r29, r27
	  stb       r9, 0x0(r28)
	  add       r11, r28, r27
	  lbz       r9, 0x1(r29)
	  stb       r9, 0x1(r28)
	  lbz       r9, 0x2(r29)
	  stb       r9, 0x2(r28)
	  lbz       r9, 0x3(r29)
	  stb       r9, 0x3(r28)
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  stb       r9, 0x3(r11)
	  bdnz+     .loc_0x1D4

	.loc_0x288:
	  addi      r7, r7, 0x1
	  cmpwi     r7, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x1C
	  b         .loc_0x9F4

	.loc_0x2A0:
	  li        r10, 0

	.loc_0x2A4:
	  lbz       r8, 0x30(r3)
	  addi      r12, r3, 0x18
	  lbz       r7, 0x31(r3)
	  addi      r0, r8, 0x1
	  lbz       r27, 0x34(r3)
	  sraw      r8, r5, r0
	  lhz       r0, 0x28(r3)
	  addi      r7, r7, 0x1
	  lwz       r9, 0x18(r4)
	  sraw      r7, r6, r7
	  mtctr     r27
	  mullw     r0, r7, r0
	  add       r11, r0, r9
	  cmpwi     r27, 0
	  add       r11, r8, r11
	  ble-      .loc_0x4A8

	.loc_0x2E4:
	  lwz       r28, 0x0(r12)
	  addi      r12, r12, 0x4
	  lhz       r0, 0x28(r3)
	  add       r30, r11, r28
	  lwz       r8, 0x14(r4)
	  add       r7, r30, r0
	  lbz       r27, 0x0(r30)
	  lbz       r9, 0x0(r7)
	  add       r31, r8, r28
	  addi      r8, r7, 0
	  addi      r9, r9, 0x1
	  add       r9, r27, r9
	  srawi     r9, r9, 0x1
	  stb       r9, 0x0(r31)
	  add       r9, r31, r0
	  lbz       r27, 0x1(r7)
	  lbz       r28, 0x1(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x1(r31)
	  lbz       r27, 0x2(r7)
	  lbz       r28, 0x2(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x2(r31)
	  lbz       r27, 0x3(r7)
	  add       r7, r7, r0
	  lbz       r28, 0x3(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x3(r31)
	  lbz       r27, 0x0(r7)
	  lbz       r28, 0x0(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x0(r9)
	  lbz       r27, 0x1(r7)
	  lbz       r28, 0x1(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x1(r9)
	  lbz       r27, 0x2(r7)
	  lbz       r28, 0x2(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x2(r9)
	  lbz       r27, 0x3(r7)
	  add       r7, r7, r0
	  lbz       r28, 0x3(r8)
	  add       r8, r8, r0
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x3(r9)
	  add       r9, r9, r0
	  lbz       r27, 0x0(r7)
	  lbz       r28, 0x0(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x0(r9)
	  lbz       r27, 0x1(r7)
	  lbz       r28, 0x1(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x1(r9)
	  lbz       r27, 0x2(r7)
	  lbz       r28, 0x2(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x2(r9)
	  lbz       r27, 0x3(r7)
	  lbz       r28, 0x3(r8)
	  add       r8, r8, r0
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x3(r9)
	  add       r7, r7, r0
	  lbz       r28, 0x0(r8)
	  lbz       r27, 0x0(r7)
	  add       r9, r9, r0
	  addi      r0, r27, 0x1
	  add       r0, r28, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r9)
	  lbz       r27, 0x1(r7)
	  lbz       r28, 0x1(r8)
	  addi      r0, r27, 0x1
	  add       r0, r28, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r9)
	  lbz       r27, 0x2(r7)
	  lbz       r28, 0x2(r8)
	  addi      r0, r27, 0x1
	  add       r0, r28, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r9)
	  lbz       r7, 0x3(r7)
	  lbz       r8, 0x3(r8)
	  addi      r0, r7, 0x1
	  add       r0, r8, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r9)
	  bdnz+     .loc_0x2E4

	.loc_0x4A8:
	  addi      r10, r10, 0x1
	  cmpwi     r10, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x2A4
	  b         .loc_0x9F4

	.loc_0x4C0:
	  rlwinm.   r0,r6,0,31,31
	  bne-      .loc_0x6D8
	  li        r9, 0

	.loc_0x4CC:
	  lbz       r8, 0x30(r3)
	  addi      r11, r3, 0x18
	  lbz       r7, 0x31(r3)
	  addi      r0, r8, 0x1
	  lbz       r12, 0x34(r3)
	  sraw      r8, r5, r0
	  lhz       r0, 0x28(r3)
	  addi      r7, r7, 0x1
	  lwz       r10, 0x18(r4)
	  sraw      r7, r6, r7
	  mtctr     r12
	  mullw     r0, r7, r0
	  add       r10, r0, r10
	  cmpwi     r12, 0
	  add       r10, r8, r10
	  ble-      .loc_0x6C0

	.loc_0x50C:
	  lwz       r12, 0x0(r11)
	  addi      r11, r11, 0x4
	  lwz       r8, 0x14(r4)
	  add       r30, r10, r12
	  lhz       r0, 0x28(r3)
	  lbz       r7, 0x1(r30)
	  add       r12, r8, r12
	  lbz       r27, 0x0(r30)
	  add       r8, r30, r0
	  addi      r7, r7, 0x1
	  add       r7, r27, r7
	  srawi     r7, r7, 0x1
	  stb       r7, 0x0(r12)
	  add       r7, r12, r0
	  lbz       r27, 0x2(r30)
	  lbz       r28, 0x1(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x1(r12)
	  lbz       r27, 0x3(r30)
	  lbz       r28, 0x2(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x2(r12)
	  lbz       r27, 0x4(r30)
	  lbz       r28, 0x3(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x3(r12)
	  lbz       r12, 0x1(r8)
	  lbz       r27, 0x0(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x0(r7)
	  lbz       r12, 0x2(r8)
	  lbz       r27, 0x1(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x1(r7)
	  lbz       r12, 0x3(r8)
	  lbz       r27, 0x2(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x2(r7)
	  lbz       r12, 0x4(r8)
	  lbz       r27, 0x3(r8)
	  add       r8, r8, r0
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x3(r7)
	  add       r7, r7, r0
	  lbz       r12, 0x1(r8)
	  lbz       r27, 0x0(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x0(r7)
	  lbz       r12, 0x2(r8)
	  lbz       r27, 0x1(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x1(r7)
	  lbz       r12, 0x3(r8)
	  lbz       r27, 0x2(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x2(r7)
	  lbz       r12, 0x4(r8)
	  lbz       r27, 0x3(r8)
	  add       r8, r8, r0
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x3(r7)
	  add       r7, r7, r0
	  lbz       r12, 0x1(r8)
	  lbz       r27, 0x0(r8)
	  addi      r0, r12, 0x1
	  add       r0, r27, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r7)
	  lbz       r12, 0x2(r8)
	  lbz       r27, 0x1(r8)
	  addi      r0, r12, 0x1
	  add       r0, r27, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r7)
	  lbz       r12, 0x3(r8)
	  lbz       r27, 0x2(r8)
	  addi      r0, r12, 0x1
	  add       r0, r27, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r7)
	  lbz       r12, 0x4(r8)
	  lbz       r8, 0x3(r8)
	  addi      r0, r12, 0x1
	  add       r0, r8, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r7)
	  bdnz+     .loc_0x50C

	.loc_0x6C0:
	  addi      r9, r9, 0x1
	  cmpwi     r9, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x4CC
	  b         .loc_0x9F4

	.loc_0x6D8:
	  li        r10, 0

	.loc_0x6DC:
	  lbz       r8, 0x30(r3)
	  addi      r12, r3, 0x18
	  lbz       r7, 0x31(r3)
	  addi      r0, r8, 0x1
	  lbz       r27, 0x34(r3)
	  sraw      r8, r5, r0
	  lhz       r0, 0x28(r3)
	  addi      r7, r7, 0x1
	  lwz       r9, 0x18(r4)
	  sraw      r7, r6, r7
	  mtctr     r27
	  mullw     r0, r7, r0
	  add       r11, r0, r9
	  cmpwi     r27, 0
	  add       r11, r8, r11
	  ble-      .loc_0x9E0

	.loc_0x71C:
	  lwz       r28, 0x0(r12)
	  addi      r12, r12, 0x4
	  lhz       r0, 0x28(r3)
	  add       r30, r11, r28
	  lwz       r8, 0x14(r4)
	  add       r7, r30, r0
	  lbz       r9, 0x1(r30)
	  lbz       r27, 0x0(r7)
	  add       r31, r8, r28
	  lbz       r28, 0x1(r7)
	  addi      r8, r7, 0
	  add       r9, r9, r27
	  add       r9, r9, r28
	  lbz       r27, 0x0(r30)
	  addi      r9, r9, 0x2
	  add       r9, r27, r9
	  srawi     r9, r9, 0x2
	  stb       r9, 0x0(r31)
	  add       r9, r31, r0
	  lbz       r28, 0x1(r7)
	  lbz       r27, 0x2(r30)
	  lbz       r29, 0x2(r7)
	  add       r27, r27, r28
	  lbz       r28, 0x1(r30)
	  add       r27, r27, r29
	  addi      r27, r27, 0x2
	  add       r27, r28, r27
	  srawi     r27, r27, 0x2
	  stb       r27, 0x1(r31)
	  lbz       r28, 0x2(r7)
	  lbz       r27, 0x3(r30)
	  lbz       r29, 0x3(r7)
	  add       r27, r27, r28
	  lbz       r28, 0x2(r30)
	  add       r27, r27, r29
	  addi      r27, r27, 0x2
	  add       r27, r28, r27
	  srawi     r27, r27, 0x2
	  stb       r27, 0x2(r31)
	  lbz       r29, 0x4(r30)
	  lbz       r28, 0x3(r7)
	  lbz       r27, 0x4(r7)
	  add       r7, r7, r0
	  add       r29, r29, r28
	  lbz       r30, 0x3(r30)
	  add       r29, r29, r27
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x3(r31)
	  lbz       r30, 0x0(r7)
	  lbz       r29, 0x1(r8)
	  lbz       r31, 0x1(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x0(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x0(r9)
	  lbz       r30, 0x1(r7)
	  lbz       r29, 0x2(r8)
	  lbz       r31, 0x2(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x1(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x1(r9)
	  lbz       r30, 0x2(r7)
	  lbz       r29, 0x3(r8)
	  lbz       r31, 0x3(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x2(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x2(r9)
	  lbz       r30, 0x3(r7)
	  lbz       r29, 0x4(r8)
	  lbz       r31, 0x4(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x3(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x3(r9)
	  add       r7, r7, r0
	  add       r8, r8, r0
	  lbz       r30, 0x0(r7)
	  lbz       r29, 0x1(r8)
	  add       r9, r9, r0
	  lbz       r31, 0x1(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x0(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x0(r9)
	  lbz       r30, 0x1(r7)
	  lbz       r29, 0x2(r8)
	  lbz       r31, 0x2(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x1(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x1(r9)
	  lbz       r30, 0x2(r7)
	  lbz       r29, 0x3(r8)
	  lbz       r31, 0x3(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x2(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x2(r9)
	  lbz       r30, 0x3(r7)
	  lbz       r29, 0x4(r8)
	  lbz       r31, 0x4(r7)
	  add       r7, r7, r0
	  add       r29, r29, r30
	  lbz       r30, 0x3(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x3(r9)
	  add       r8, r8, r0
	  add       r9, r9, r0
	  lbz       r29, 0x0(r7)
	  lbz       r0, 0x1(r8)
	  lbz       r31, 0x1(r7)
	  add       r0, r0, r29
	  lbz       r30, 0x0(r8)
	  add       r29, r0, r31
	  addi      r0, r29, 0x2
	  add       r0, r30, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x0(r9)
	  lbz       r29, 0x1(r7)
	  lbz       r0, 0x2(r8)
	  lbz       r31, 0x2(r7)
	  add       r0, r0, r29
	  lbz       r30, 0x1(r8)
	  add       r29, r0, r31
	  addi      r0, r29, 0x2
	  add       r0, r30, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x1(r9)
	  lbz       r30, 0x2(r7)
	  lbz       r0, 0x3(r8)
	  lbz       r29, 0x3(r7)
	  add       r0, r0, r30
	  lbz       r31, 0x2(r8)
	  add       r30, r0, r29
	  addi      r0, r30, 0x2
	  add       r0, r31, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x2(r9)
	  lbz       r30, 0x3(r7)
	  lbz       r0, 0x4(r8)
	  lbz       r7, 0x4(r7)
	  add       r0, r0, r30
	  lbz       r8, 0x3(r8)
	  add       r7, r0, r7
	  addi      r0, r7, 0x2
	  add       r0, r8, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x3(r9)
	  bdnz+     .loc_0x71C

	.loc_0x9E0:
	  addi      r10, r10, 0x1
	  cmpwi     r10, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x6DC

	.loc_0x9F4:
	  lmw       r27, 0x34(r1)
	  addi      r1, r1, 0x48
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80021A78
 * Size:	00041C
 */
static void decode_PB_cc(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], int proc, u32 type)
{
	u32 block_type;
	int i, j;
	BlockData* blockInfoTop;
	HVQPlaneDesc* plane;
	HVQPlaneDesc* planeY;
	MCPlane* mcplaneY;
	BlockData* ptr;
	s16 huff;
	HVQPlaneDesc* planeU;
	MCPlane* mcplaneU;
	MCPlane* mcplaneV;
	BlockData* ptrU;
	BlockData* ptrV;

	block_type = (type << 5) | (proc << 4);
	if (proc == 1) {
		for (i = 0; i < PLANE_COUNT; ++i) {
			blockInfoTop = mcplanes[i].data;
			plane        = &state->pln[i];
			for (j = 0; j < plane->nblocks_mcb; ++j)
				blockInfoTop[plane->bibUscan[j]].bnm = block_type;
		}
		return;
	} else {
		// luma
		planeY   = &state->pln[0];
		mcplaneY = &mcplanes[0];
		for (i = 0; i < planeY->nblocks_mcb; ++i) {
			ptr = mcplaneY->data;
			if (mcplaneY->bsrunleng) {
				ptr[planeY->bibUscan[i]].bnm = block_type;
				--mcplaneY->bsrunleng;
			} else {
				huff = decodeHuff(&state->bsnum[LUMA_IDX]);
				if (huff)
					ptr[planeY->bibUscan[i]].bnm = block_type | huff;
				else {
					ptr[planeY->bibUscan[i]].bnm = block_type;
					mcplaneY->bsrunleng          = decodeHuff(&state->bsrun[0]);
				}
			}
		}
		// chroma
		planeU   = &state->pln[1];
		mcplaneU = &mcplanes[1];
		mcplaneV = &mcplanes[2];
		for (i = 0; i < planeU->nblocks_mcb; ++i) {
			ptrU = mcplaneU->data;
			ptrV = mcplaneV->data;
			if (mcplaneU->bsrunleng) {
				ptrU[planeU->bibUscan[i]].bnm = block_type;
				ptrV[planeU->bibUscan[i]].bnm = block_type;
				--mcplaneU->bsrunleng;
			} else {
				huff = decodeHuff(&state->bsnum[CHROMA_IDX]);
				if (huff) {
					ptrU[planeU->bibUscan[i]].bnm = block_type | ((huff >> 0) & 0xF);
					ptrV[planeU->bibUscan[i]].bnm = block_type | ((huff >> 4) & 0xF);
				} else {
					ptrU[planeU->bibUscan[i]].bnm = block_type;
					ptrV[planeU->bibUscan[i]].bnm = block_type;
					mcplaneU->bsrunleng           = decodeHuff(&state->bsrun[1]);
				}
			}
		}
	}

	/*
	.loc_0x0:
	  stwu      r1, -0x60(r1)
	  cmpwi     r5, 0x1
	  rlwinm    r6,r6,5,0,26
	  stw       r31, 0x5C(r1)
	  rlwinm    r0,r5,4,0,27
	  or        r7, r6, r0
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  bne-      .loc_0x12C
	  li        r9, 0

	.loc_0x28:
	  lbz       r5, 0x34(r3)
	  addi      r8, r3, 0x10
	  lwz       r6, 0x8(r4)
	  li        r10, 0
	  cmpwi     r5, 0
	  ble-      .loc_0x114
	  cmpwi     r5, 0x8
	  subi      r11, r5, 0x8
	  ble-      .loc_0xEC
	  addi      r0, r11, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r11, 0
	  mtctr     r0
	  ble-      .loc_0xEC

	.loc_0x60:
	  lhz       r0, 0x0(r8)
	  addi      r10, r10, 0x8
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0x2(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0x4(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0x6(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0x8(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0xA(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0xC(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0xE(r8)
	  addi      r8, r8, 0x10
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  bdnz+     .loc_0x60

	.loc_0xEC:
	  sub       r0, r5, r10
	  cmpw      r10, r5
	  mtctr     r0
	  bge-      .loc_0x114

	.loc_0xFC:
	  lhz       r0, 0x0(r8)
	  addi      r8, r8, 0x2
	  rlwinm    r5,r0,1,0,30
	  addi      r0, r5, 0x1
	  stbx      r7, r6, r0
	  bdnz+     .loc_0xFC

	.loc_0x114:
	  addi      r9, r9, 0x1
	  cmpwi     r9, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x28
	  b         .loc_0x408

	.loc_0x12C:
	  lbz       r0, 0x34(r3)
	  addi      r8, r3, 0x618C
	  lwz       r6, 0x8(r4)
	  addi      r9, r3, 0x61B4
	  cmpwi     r0, 0
	  mtctr     r0
	  addi      r5, r3, 0x10
	  rlwinm    r0,r7,0,24,31
	  ble-      .loc_0x28C

	.loc_0x150:
	  lwz       r10, 0x0(r4)
	  lhz       r12, 0x0(r5)
	  addi      r5, r5, 0x2
	  cmpwi     r10, 0
	  bne-      .loc_0x270
	  lwz       r29, 0x10(r8)
	  lwz       r31, 0x4(r29)
	  b         .loc_0x1BC

	.loc_0x170:
	  lwz       r30, 0xC(r8)
	  cmpwi     r30, 0
	  bge-      .loc_0x198
	  lwz       r11, 0x0(r8)
	  li        r30, 0x1F
	  addi      r10, r11, 0x4
	  stw       r10, 0x0(r8)
	  lwz       r10, 0x0(r11)
	  stw       r10, 0x8(r8)
	  b         .loc_0x19C

	.loc_0x198:
	  lwz       r10, 0x8(r8)

	.loc_0x19C:
	  srw       r11, r10, r30
	  subi      r10, r30, 0x1
	  stw       r10, 0xC(r8)
	  rlwinm    r11,r11,11,20,20
	  rlwinm    r10,r31,2,0,29
	  add       r10, r11, r10
	  addi      r10, r10, 0x8
	  lwzx      r31, r29, r10

	.loc_0x1BC:
	  cmpwi     r31, 0x100
	  bge+      .loc_0x170
	  rlwinm    r10,r31,2,0,29
	  addi      r10, r10, 0x8
	  lwzx      r10, r29, r10
	  extsh     r11, r10
	  extsh.    r10, r11
	  bne-      .loc_0x25C
	  rlwinm    r10,r12,1,0,30
	  addi      r10, r10, 0x1
	  stbx      r7, r6, r10
	  lwz       r29, 0x10(r9)
	  lwz       r12, 0x4(r29)
	  b         .loc_0x240

	.loc_0x1F4:
	  lwz       r30, 0xC(r9)
	  cmpwi     r30, 0
	  bge-      .loc_0x21C
	  lwz       r11, 0x0(r9)
	  li        r30, 0x1F
	  addi      r10, r11, 0x4
	  stw       r10, 0x0(r9)
	  lwz       r10, 0x0(r11)
	  stw       r10, 0x8(r9)
	  b         .loc_0x220

	.loc_0x21C:
	  lwz       r10, 0x8(r9)

	.loc_0x220:
	  srw       r11, r10, r30
	  subi      r10, r30, 0x1
	  stw       r10, 0xC(r9)
	  rlwinm    r11,r11,11,20,20
	  rlwinm    r10,r12,2,0,29
	  add       r10, r11, r10
	  addi      r10, r10, 0x8
	  lwzx      r12, r29, r10

	.loc_0x240:
	  cmpwi     r12, 0x100
	  bge+      .loc_0x1F4
	  rlwinm    r10,r12,2,0,29
	  addi      r10, r10, 0x8
	  lwzx      r10, r29, r10
	  stw       r10, 0x0(r4)
	  b         .loc_0x288

	.loc_0x25C:
	  rlwinm    r10,r12,1,0,30
	  or        r11, r0, r11
	  addi      r10, r10, 0x1
	  stbx      r11, r6, r10
	  b         .loc_0x288

	.loc_0x270:
	  rlwinm    r10,r12,1,0,30
	  addi      r10, r10, 0x1
	  stbx      r7, r6, r10
	  lwz       r10, 0x0(r4)
	  subi      r10, r10, 0x1
	  stw       r10, 0x0(r4)

	.loc_0x288:
	  bdnz+     .loc_0x150

	.loc_0x28C:
	  addi      r11, r3, 0x38
	  lwz       r8, 0x3C(r4)
	  lbz       r10, 0x6C(r3)
	  addi      r5, r3, 0x61A0
	  lwz       r9, 0x70(r4)
	  addi      r6, r3, 0x61C8
	  cmpwi     r10, 0
	  mtctr     r10
	  addi      r3, r11, 0x10
	  ble-      .loc_0x408

	.loc_0x2B4:
	  lwz       r10, 0x34(r4)
	  lhz       r12, 0x0(r3)
	  addi      r3, r3, 0x2
	  cmpwi     r10, 0
	  bne-      .loc_0x3E8
	  lwz       r29, 0x10(r5)
	  lwz       r31, 0x4(r29)
	  b         .loc_0x320

	.loc_0x2D4:
	  lwz       r30, 0xC(r5)
	  cmpwi     r30, 0
	  bge-      .loc_0x2FC
	  lwz       r11, 0x0(r5)
	  li        r30, 0x1F
	  addi      r10, r11, 0x4
	  stw       r10, 0x0(r5)
	  lwz       r10, 0x0(r11)
	  stw       r10, 0x8(r5)
	  b         .loc_0x300

	.loc_0x2FC:
	  lwz       r10, 0x8(r5)

	.loc_0x300:
	  srw       r11, r10, r30
	  subi      r10, r30, 0x1
	  stw       r10, 0xC(r5)
	  rlwinm    r11,r11,11,20,20
	  rlwinm    r10,r31,2,0,29
	  add       r10, r11, r10
	  addi      r10, r10, 0x8
	  lwzx      r31, r29, r10

	.loc_0x320:
	  cmpwi     r31, 0x100
	  bge+      .loc_0x2D4
	  rlwinm    r10,r31,2,0,29
	  addi      r10, r10, 0x8
	  lwzx      r10, r29, r10
	  extsh     r30, r10
	  extsh.    r10, r30
	  bne-      .loc_0x3C4
	  rlwinm    r10,r12,1,0,30
	  addi      r10, r10, 0x1
	  stbx      r7, r8, r10
	  stbx      r7, r9, r10
	  lwz       r29, 0x10(r6)
	  lwz       r12, 0x4(r29)
	  b         .loc_0x3A8

	.loc_0x35C:
	  lwz       r30, 0xC(r6)
	  cmpwi     r30, 0
	  bge-      .loc_0x384
	  lwz       r11, 0x0(r6)
	  li        r30, 0x1F
	  addi      r10, r11, 0x4
	  stw       r10, 0x0(r6)
	  lwz       r10, 0x0(r11)
	  stw       r10, 0x8(r6)
	  b         .loc_0x388

	.loc_0x384:
	  lwz       r10, 0x8(r6)

	.loc_0x388:
	  srw       r11, r10, r30
	  subi      r10, r30, 0x1
	  stw       r10, 0xC(r6)
	  rlwinm    r11,r11,11,20,20
	  rlwinm    r10,r12,2,0,29
	  add       r10, r11, r10
	  addi      r10, r10, 0x8
	  lwzx      r12, r29, r10

	.loc_0x3A8:
	  cmpwi     r12, 0x100
	  bge+      .loc_0x35C
	  rlwinm    r10,r12,2,0,29
	  addi      r10, r10, 0x8
	  lwzx      r10, r29, r10
	  stw       r10, 0x34(r4)
	  b         .loc_0x404

	.loc_0x3C4:
	  rlwinm    r11,r30,0,28,31
	  rlwinm    r29,r12,1,0,30
	  rlwinm    r10,r30,28,28,31
	  or        r12, r0, r11
	  addi      r11, r29, 0x1
	  stbx      r12, r8, r11
	  or        r10, r0, r10
	  stbx      r10, r9, r11
	  b         .loc_0x404

	.loc_0x3E8:
	  rlwinm    r10,r12,1,0,30
	  addi      r10, r10, 0x1
	  stbx      r7, r8, r10
	  stbx      r7, r9, r10
	  lwz       r10, 0x34(r4)
	  subi      r10, r10, 0x1
	  stw       r10, 0x34(r4)

	.loc_0x404:
	  bdnz+     .loc_0x2B4

	.loc_0x408:
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x60
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80021E94
 * Size:	00086C
 */
static void PrediAotBlock(VideoState* state, u8* dst, const u8* src, u32 stride, u8 blockType, u8* nestData, u32 hNestSize, u32 planeIdx,
                          u32 hpeldx, u32 hpeldy)
{
	int result[4][4];
	u32 aot_sum;
	u8 mdst[4][4];
	int i, j, y, x;
	u32 diff[4][4];
	u32 min, max, value, mean, addend, factor;
	u32 const dst_stride = 4;

	aot_sum = GetMCAotSum(state, result, blockType - 1, (const u8*)nestData, hNestSize, planeIdx);

	// MotionComp((u8*)mdst, dst_stride, src, stride, hpeldx, hpeldy);
	mean = 8;
	for (y = 0; y < 4; ++y)
		for (x = 0; x < 4; ++x)
			mean += mdst[y][x];
	mean /= 16;
	min = max = mdst[0][0] - mean;
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			value = diff[i][j] = mdst[i][j] - mean;
			min                = value < min ? value : min;
			max                = value > max ? value : max;
		}
	}
	addend = (decodeSOvfSym(&state->dcval[planeIdx], state->dc_min, state->dc_max) >> state->dc_scale_q << state->aotscale_q) - aot_sum;
	factor = (decodeSOvfSym(&state->dcval[planeIdx], state->dc_min, state->dc_max) >> state->dc_scale_q);
	factor *= mcdivTable[max - min];
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			result[i][j] += addend + diff[i][j] * factor;

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			value               = (result[i][j] >> state->aotscale_q) + mdst[i][j];
			dst[i * stride + j] = saturate(value);
		}
	}

	/*
	.loc_0x0:
	mflr      r0
	lis       r11, 0x8039
	stw       r0, 0x4(r1)
	li        r0, 0
	stwu      r1, -0x120(r1)
	stmw      r16, 0xE0(r1)
	addi      r23, r3, 0
	lwz       r17, 0x128(r1)
	addi      r24, r4, 0
	addi      r20, r5, 0
	addi      r25, r6, 0
	addi      r19, r8, 0
	addi      r18, r9, 0
	addi      r26, r10, 0
	subi      r22, r11, 0x4300
	subi      r27, r7, 0x1
	stw       r0, 0x38(r1)
	stw       r0, 0xDC(r1)
	stw       r0, 0xD8(r1)
	stw       r0, 0xD4(r1)
	stw       r0, 0xD0(r1)
	stw       r0, 0xCC(r1)
	stw       r0, 0xC8(r1)
	stw       r0, 0xC4(r1)
	stw       r0, 0xC0(r1)
	stw       r0, 0xBC(r1)
	stw       r0, 0xB8(r1)
	stw       r0, 0xB4(r1)
	stw       r0, 0xB0(r1)
	stw       r0, 0xAC(r1)
	stw       r0, 0xA8(r1)
	stw       r0, 0xA4(r1)
	stw       r0, 0xA0(r1)
	b         .loc_0x1E4

	.loc_0x88:
	addi      r3, r23, 0
	addi      r6, r19, 0
	addi      r7, r18, 0
	addi      r8, r26, 0
	addi      r4, r1, 0x3C
	addi      r5, r1, 0x38
	bl        .loc_0x86C
	lbz       r4, 0x3C(r1)
	lbz       r0, 0x3D(r1)
	mullw     r4, r3, r4
	lwz       r5, 0xA0(r1)
	add       r4, r5, r4
	stw       r4, 0xA0(r1)
	mullw     r0, r3, r0
	lwz       r4, 0xA4(r1)
	add       r0, r4, r0
	stw       r0, 0xA4(r1)
	lbz       r0, 0x3E(r1)
	lwz       r4, 0xA8(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xA8(r1)
	lbz       r0, 0x3F(r1)
	lwz       r4, 0xAC(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xAC(r1)
	lbz       r0, 0x40(r1)
	lwz       r4, 0xB0(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xB0(r1)
	lbz       r0, 0x41(r1)
	lwz       r4, 0xB4(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xB4(r1)
	lbz       r0, 0x42(r1)
	lwz       r4, 0xB8(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xB8(r1)
	lbz       r0, 0x43(r1)
	lwz       r4, 0xBC(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xBC(r1)
	lbz       r0, 0x44(r1)
	lwz       r4, 0xC0(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xC0(r1)
	lbz       r0, 0x45(r1)
	lwz       r4, 0xC4(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xC4(r1)
	lbz       r0, 0x46(r1)
	lwz       r4, 0xC8(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xC8(r1)
	lbz       r0, 0x47(r1)
	lwz       r4, 0xCC(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xCC(r1)
	lbz       r0, 0x48(r1)
	lwz       r4, 0xD0(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xD0(r1)
	lbz       r0, 0x49(r1)
	lwz       r4, 0xD4(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xD4(r1)
	lbz       r0, 0x4A(r1)
	lwz       r4, 0xD8(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xD8(r1)
	lbz       r0, 0x4B(r1)
	lwz       r4, 0xDC(r1)
	mullw     r0, r3, r0
	add       r0, r4, r0
	stw       r0, 0xDC(r1)

	.loc_0x1E4:
	rlwinm.   r0,r27,0,24,31
	subi      r27, r27, 0x1
	bne+      .loc_0x88
	lwz       r5, 0xA8(r1)
	lis       r3, 0x8022
	lwz       r0, 0xA4(r1)
	rlwinm    r4,r17,2,0,29
	lwz       r6, 0xAC(r1)
	add       r0, r0, r5
	lwz       r5, 0xB0(r1)
	add       r0, r0, r6
	lwz       r6, 0xB4(r1)
	add       r0, r0, r5
	lwz       r5, 0xB8(r1)
	add       r0, r0, r6
	lwz       r6, 0xBC(r1)
	add       r0, r0, r5
	lwz       r5, 0xC0(r1)
	add       r0, r0, r6
	lwz       r6, 0xC4(r1)
	add       r0, r0, r5
	lwz       r5, 0xC8(r1)
	add       r0, r0, r6
	lwz       r6, 0xCC(r1)
	add       r0, r0, r5
	lwz       r5, 0xD0(r1)
	add       r0, r0, r6
	lwz       r6, 0xD4(r1)
	add       r5, r0, r5
	lwz       r7, 0xD8(r1)
	addi      r0, r3, 0x72C0
	lwz       r8, 0xDC(r1)
	add       r5, r5, r6
	lwz       r6, 0xA0(r1)
	add       r3, r0, r4
	add       r0, r5, r7
	lwz       r12, 0x0(r3)
	add       r0, r0, r8
	add       r0, r6, r0
	mtlr      r12
	addi      r5, r20, 0
	addi      r6, r25, 0
	srawi     r29, r0, 0x4
	addi      r3, r1, 0x90
	li        r4, 0x4
	blrl
	lbz       r3, 0x92(r1)
	lbz       r0, 0x91(r1)
	lbz       r4, 0x93(r1)
	add       r6, r0, r3
	lbz       r5, 0x94(r1)
	add       r7, r6, r4
	lbz       r6, 0x95(r1)
	add       r8, r7, r5
	lbz       r7, 0x96(r1)
	add       r9, r8, r6
	lbz       r8, 0x97(r1)
	add       r10, r9, r7
	lbz       r9, 0x98(r1)
	add       r11, r10, r8
	lbz       r10, 0x99(r1)
	add       r12, r11, r9
	lbz       r11, 0x9A(r1)
	add       r17, r12, r10
	lbz       r12, 0x9B(r1)
	add       r17, r17, r11
	lbz       r18, 0x9C(r1)
	add       r17, r17, r12
	lbz       r19, 0x9D(r1)
	add       r17, r17, r18
	lbz       r20, 0x9E(r1)
	add       r17, r17, r19
	lbz       r21, 0x9F(r1)
	add       r17, r17, r20
	lbz       r16, 0x90(r1)
	add       r17, r17, r21
	addi      r17, r17, 0x8
	add       r17, r16, r17
	srawi     r17, r17, 0x4
	sub       r27, r16, r17
	sub       r0, r0, r17
	stw       r27, 0x50(r1)
	cmpw      r0, r27
	stw       r0, 0x54(r1)
	mr        r28, r27
	bge-      .loc_0x344
	mr        r27, r0
	b         .loc_0x34C

	.loc_0x344:
	ble-      .loc_0x34C
	mr        r28, r0

	.loc_0x34C:
	sub       r0, r3, r17
	cmpw      r0, r27
	stw       r0, 0x58(r1)
	bge-      .loc_0x364
	mr        r27, r0
	b         .loc_0x370

	.loc_0x364:
	cmpw      r0, r28
	ble-      .loc_0x370
	mr        r28, r0

	.loc_0x370:
	sub       r0, r4, r17
	cmpw      r0, r27
	stw       r0, 0x5C(r1)
	bge-      .loc_0x388
	mr        r27, r0
	b         .loc_0x394

	.loc_0x388:
	cmpw      r0, r28
	ble-      .loc_0x394
	mr        r28, r0

	.loc_0x394:
	sub       r0, r5, r17
	cmpw      r0, r27
	stw       r0, 0x60(r1)
	bge-      .loc_0x3AC
	mr        r27, r0
	b         .loc_0x3B8

	.loc_0x3AC:
	cmpw      r0, r28
	ble-      .loc_0x3B8
	mr        r28, r0

	.loc_0x3B8:
	sub       r0, r6, r17
	cmpw      r0, r27
	stw       r0, 0x64(r1)
	bge-      .loc_0x3D0
	mr        r27, r0
	b         .loc_0x3DC

	.loc_0x3D0:
	cmpw      r0, r28
	ble-      .loc_0x3DC
	mr        r28, r0

	.loc_0x3DC:
	sub       r0, r7, r17
	cmpw      r0, r27
	stw       r0, 0x68(r1)
	bge-      .loc_0x3F4
	mr        r27, r0
	b         .loc_0x400

	.loc_0x3F4:
	cmpw      r0, r28
	ble-      .loc_0x400
	mr        r28, r0

	.loc_0x400:
	sub       r0, r8, r17
	cmpw      r0, r27
	stw       r0, 0x6C(r1)
	bge-      .loc_0x418
	mr        r27, r0
	b         .loc_0x424

	.loc_0x418:
	cmpw      r0, r28
	ble-      .loc_0x424
	mr        r28, r0

	.loc_0x424:
	sub       r0, r9, r17
	cmpw      r0, r27
	stw       r0, 0x70(r1)
	bge-      .loc_0x43C
	mr        r27, r0
	b         .loc_0x448

	.loc_0x43C:
	cmpw      r0, r28
	ble-      .loc_0x448
	mr        r28, r0

	.loc_0x448:
	sub       r0, r10, r17
	cmpw      r0, r27
	stw       r0, 0x74(r1)
	bge-      .loc_0x460
	mr        r27, r0
	b         .loc_0x46C

	.loc_0x460:
	cmpw      r0, r28
	ble-      .loc_0x46C
	mr        r28, r0

	.loc_0x46C:
	sub       r0, r11, r17
	cmpw      r0, r27
	stw       r0, 0x78(r1)
	bge-      .loc_0x484
	mr        r27, r0
	b         .loc_0x490

	.loc_0x484:
	cmpw      r0, r28
	ble-      .loc_0x490
	mr        r28, r0

	.loc_0x490:
	sub       r0, r12, r17
	cmpw      r0, r27
	stw       r0, 0x7C(r1)
	bge-      .loc_0x4A8
	mr        r27, r0
	b         .loc_0x4B4

	.loc_0x4A8:
	cmpw      r0, r28
	ble-      .loc_0x4B4
	mr        r28, r0

	.loc_0x4B4:
	sub       r0, r18, r17
	cmpw      r0, r27
	stw       r0, 0x80(r1)
	bge-      .loc_0x4CC
	mr        r27, r0
	b         .loc_0x4D8

	.loc_0x4CC:
	cmpw      r0, r28
	ble-      .loc_0x4D8
	mr        r28, r0

	.loc_0x4D8:
	sub       r0, r19, r17
	cmpw      r0, r27
	stw       r0, 0x84(r1)
	bge-      .loc_0x4F0
	mr        r27, r0
	b         .loc_0x4FC

	.loc_0x4F0:
	cmpw      r0, r28
	ble-      .loc_0x4FC
	mr        r28, r0

	.loc_0x4FC:
	sub       r0, r20, r17
	cmpw      r0, r27
	stw       r0, 0x88(r1)
	bge-      .loc_0x514
	mr        r27, r0
	b         .loc_0x520

	.loc_0x514:
	cmpw      r0, r28
	ble-      .loc_0x520
	mr        r28, r0

	.loc_0x520:
	sub       r0, r21, r17
	cmpw      r0, r27
	stw       r0, 0x8C(r1)
	bge-      .loc_0x538
	mr        r27, r0
	b         .loc_0x544

	.loc_0x538:
	cmpw      r0, r28
	ble-      .loc_0x544
	mr        r28, r0

	.loc_0x544:
	mulli     r0, r26, 0x14
	lbz       r26, 0x6CD0(r23)
	lwz       r19, 0x6CC8(r23)
	lwz       r20, 0x6CCC(r23)
	add       r31, r23, r0
	addi      r30, r31, 0x60D8
	addi      r18, r30, 0
	li        r21, 0

	.loc_0x564:
	lwz       r17, 0x60E8(r31)
	lwz       r16, 0x4(r17)
	b         .loc_0x58C

	.loc_0x570:
	mr        r3, r18
	bl        -0x2C20
	rlwinm    r3,r3,11,0,20
	rlwinm    r0,r16,2,0,29
	add       r3, r3, r0
	addi      r0, r3, 0x8
	lwzx      r16, r17, r0

	.loc_0x58C:
	cmpwi     r16, 0x100
	bge+      .loc_0x570
	rlwinm    r3,r16,2,0,29
	addi      r0, r3, 0x8
	lwzx      r0, r17, r0
	cmpw      r20, r0
	add       r21, r21, r0
	bge+      .loc_0x564
	cmpw      r0, r19
	bge+      .loc_0x564
	lbz       r0, 0x6CD1(r23)
	li        r19, 0
	lwz       r18, 0x6CC8(r23)
	sraw      r0, r21, r0
	lwz       r20, 0x6CCC(r23)
	slw       r0, r0, r26
	sub       r29, r0, r29

	.loc_0x5D0:
	lwz       r17, 0x60E8(r31)
	lwz       r16, 0x4(r17)
	b         .loc_0x5F8

	.loc_0x5DC:
	mr        r3, r30
	bl        -0x2C8C
	rlwinm    r3,r3,11,0,20
	rlwinm    r0,r16,2,0,29
	add       r3, r3, r0
	addi      r0, r3, 0x8
	lwzx      r16, r17, r0

	.loc_0x5F8:
	cmpwi     r16, 0x100
	bge+      .loc_0x5DC
	rlwinm    r3,r16,2,0,29
	addi      r0, r3, 0x8
	lwzx      r0, r17, r0
	cmpw      r20, r0
	add       r19, r19, r0
	bge+      .loc_0x5D0
	cmpw      r0, r18
	bge+      .loc_0x5D0
	sub       r3, r28, r27
	lbz       r0, 0x6CD1(r23)
	rlwinm    r3,r3,2,0,29
	add       r3, r22, r3
	lwz       r4, 0x240(r3)
	sraw      r0, r19, r0
	li        r3, 0x2
	mullw     r0, r4, r0
	mtctr     r3
	addi      r5, r1, 0xA0
	addi      r4, r5, 0
	addi      r3, r1, 0x50

	.loc_0x650:
	lwz       r6, 0x0(r3)
	lwz       r7, 0x0(r4)
	mullw     r6, r0, r6
	add       r6, r6, r7
	add       r6, r29, r6
	stw       r6, 0x0(r4)
	lwz       r6, 0x4(r3)
	lwz       r7, 0x4(r4)
	mullw     r6, r0, r6
	add       r6, r6, r7
	add       r6, r29, r6
	stw       r6, 0x4(r4)
	lwz       r6, 0x8(r3)
	lwz       r7, 0x8(r4)
	mullw     r6, r0, r6
	add       r6, r6, r7
	add       r6, r29, r6
	stw       r6, 0x8(r4)
	lwz       r6, 0xC(r3)
	lwz       r7, 0xC(r4)
	mullw     r6, r0, r6
	add       r6, r6, r7
	add       r6, r29, r6
	stw       r6, 0xC(r4)
	lwz       r6, 0x10(r3)
	lwz       r7, 0x10(r4)
	mullw     r6, r0, r6
	add       r6, r6, r7
	add       r6, r29, r6
	stw       r6, 0x10(r4)
	lwz       r6, 0x14(r3)
	lwz       r7, 0x14(r4)
	mullw     r6, r0, r6
	add       r6, r6, r7
	add       r6, r29, r6
	stw       r6, 0x14(r4)
	lwz       r6, 0x18(r3)
	lwz       r7, 0x18(r4)
	mullw     r6, r0, r6
	add       r6, r6, r7
	add       r6, r29, r6
	stw       r6, 0x18(r4)
	lwz       r6, 0x1C(r3)
	addi      r3, r3, 0x20
	lwz       r7, 0x1C(r4)
	mullw     r6, r0, r6
	add       r6, r6, r7
	add       r6, r29, r6
	stw       r6, 0x1C(r4)
	addi      r4, r4, 0x20
	bdnz+     .loc_0x650
	li        r0, 0x2
	mtctr     r0
	addi      r4, r1, 0x90
	addi      r3, r1, 0xA0
	li        r6, 0

	.loc_0x730:
	lwz       r0, 0x0(r5)
	addi      r11, r6, 0x1
	lbz       r7, 0x0(r4)
	addi      r9, r6, 0x2
	sraw      r0, r0, r26
	add       r7, r7, r0
	addi      r0, r7, 0x80
	lbzx      r0, r22, r0
	addi      r7, r6, 0x3
	rlwinm    r10,r9,2,0,29
	stb       r0, 0x0(r24)
	rlwinm    r11,r11,2,0,29
	rlwinm    r8,r7,2,0,29
	lwzx      r0, r3, r11
	addi      r11, r6, 0x5
	lbz       r7, 0x1(r4)
	addi      r9, r6, 0x6
	sraw      r0, r0, r26
	add       r7, r7, r0
	addi      r0, r7, 0x80
	lbzx      r0, r22, r0
	addi      r7, r6, 0x7
	rlwinm    r11,r11,2,0,29
	stb       r0, 0x1(r24)
	addi      r6, r6, 0x8
	lwzx      r0, r3, r10
	rlwinm    r10,r9,2,0,29
	lbz       r9, 0x2(r4)
	sraw      r0, r0, r26
	add       r9, r9, r0
	addi      r0, r9, 0x80
	lbzx      r0, r22, r0
	stb       r0, 0x2(r24)
	lwzx      r0, r3, r8
	rlwinm    r8,r7,2,0,29
	lbz       r7, 0x3(r4)
	sraw      r0, r0, r26
	add       r7, r7, r0
	addi      r0, r7, 0x80
	lbzx      r0, r22, r0
	stb       r0, 0x3(r24)
	add       r24, r24, r25
	lwz       r0, 0x10(r5)
	addi      r5, r5, 0x20
	lbz       r7, 0x4(r4)
	sraw      r0, r0, r26
	add       r7, r7, r0
	addi      r0, r7, 0x80
	lbzx      r0, r22, r0
	stb       r0, 0x0(r24)
	lwzx      r0, r3, r11
	lbz       r7, 0x5(r4)
	sraw      r0, r0, r26
	add       r7, r7, r0
	addi      r0, r7, 0x80
	lbzx      r0, r22, r0
	stb       r0, 0x1(r24)
	lwzx      r0, r3, r10
	lbz       r9, 0x6(r4)
	sraw      r0, r0, r26
	add       r9, r9, r0
	addi      r0, r9, 0x80
	lbzx      r0, r22, r0
	stb       r0, 0x2(r24)
	lwzx      r0, r3, r8
	lbz       r7, 0x7(r4)
	addi      r4, r4, 0x8
	sraw      r0, r0, r26
	add       r7, r7, r0
	addi      r0, r7, 0x80
	lbzx      r0, r22, r0
	stb       r0, 0x3(r24)
	add       r24, r24, r25
	bdnz+     .loc_0x730
	lmw       r16, 0xE0(r1)
	lwz       r0, 0x124(r1)
	addi      r1, r1, 0x120
	mtlr      r0
	blr

	.loc_0x86C:
	*/
}

/*
 * --INFO--
 * Address:	80022BC4
 * Size:	000164
 */
static void MCBlockDecMCNest(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT], int x, int y)
{
	u32 hpel_dx, hpel_dy;
	int plane_idx;
	MCPlane* mcplane;
	HVQPlaneDesc* plane;
	int i;
	BlockData const* ptr;
	u8 block_type;
	u8* dst;
	u32 stride;
	u8* nestBuf;
	u32 plane_dx, plane_dy;
	const u8* src;
	u32 strideY;

	if (state->landscape)
		nestBuf = mcplanes[0].targ + x / 2 + (y / 2 - 16) * state->pln[0].plane_width - 32;
	else
		nestBuf = mcplanes[0].targ + x / 2 + (y / 2 - 32) * state->pln[0].plane_width - 16;
	hpel_dx = x & 1;
	hpel_dy = y & 1;
	for (plane_idx = 0; plane_idx < PLANE_COUNT; ++plane_idx) {
		mcplane = &mcplanes[plane_idx];
		plane   = &state->pln[plane_idx];
		for (i = 0; i < plane->nblocks_mcb; ++i) {
			ptr        = mcplane->data;
			block_type = ptr[plane->bibUscan[i]].bnm & 0xF;
			// dst is a 4x4 region
			dst    = mcplane->blk_top + plane->imgUscan[i];
			stride = plane->plane_width;
			if (block_type == 6) {
				OrgBlock(state, dst, stride, plane_idx);
			} else {
				plane_dx = x >> plane->h_shift;
				plane_dy = y >> plane->v_shift;
				src      = mcplane->targ + (plane_dy >> 1) * plane->plane_width + (plane_dx >> 1) + plane->imgUscan[i];
				if (block_type == 0) {
					// MotionComp(dst, stride, src, stride, hpel_dx, hpel_dy);
				} else {
					strideY = state->pln[0].plane_width;
					PrediAotBlock(state, dst, src, stride, block_type, nestBuf, strideY, plane_idx, hpel_dx, hpel_dy);
				}
			}
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r18, 0x28(r1)
	  addi      r18, r6, 0
	  addi      r19, r5, 0
	  addi      r31, r3, 0
	  rlwinm    r27,r18,0,31,31
	  srawi     r6, r19, 0x1
	  rlwimi    r27,r19,1,30,30
	  addi      r30, r4, 0
	  addi      r29, r31, 0
	  li        r26, 0
	  lhz       r0, 0x28(r3)
	  srawi     r3, r18, 0x1
	  subi      r5, r3, 0x10
	  lwz       r7, 0x18(r4)
	  mullw     r0, r5, r0
	  add       r5, r6, r7
	  add       r20, r5, r0
	  lis       r3, 0x8022
	  rlwinm    r5,r27,2,0,29
	  addi      r0, r3, 0x72C0
	  add       r28, r0, r5
	  subi      r20, r20, 0x20

	.loc_0x64:
	  lbz       r4, 0x30(r29)
	  addi      r23, r29, 0x10
	  lbz       r3, 0x31(r29)
	  addi      r22, r29, 0x18
	  addi      r0, r4, 0x1
	  sraw      r4, r19, r0
	  lhz       r0, 0x28(r29)
	  addi      r3, r3, 0x1
	  lwz       r5, 0x18(r30)
	  sraw      r3, r18, r3
	  lbz       r21, 0x34(r29)
	  mullw     r0, r3, r0
	  add       r24, r0, r5
	  add       r24, r4, r24
	  li        r25, 0
	  b         .loc_0x134

	.loc_0xA4:
	  lhz       r0, 0x0(r23)
	  addi      r23, r23, 0x2
	  lwz       r5, 0x0(r22)
	  addi      r22, r22, 0x4
	  rlwinm    r3,r0,1,0,30
	  lwz       r4, 0x8(r30)
	  addi      r3, r3, 0x1
	  lwz       r0, 0x14(r30)
	  lbzx      r3, r4, r3
	  add       r4, r0, r5
	  rlwinm    r7,r3,0,28,31
	  cmplwi    r7, 0x6
	  bne-      .loc_0xEC
	  lhz       r5, 0x28(r29)
	  addi      r3, r31, 0
	  addi      r6, r26, 0
	  bl        -0x2ED4
	  b         .loc_0x130

	.loc_0xEC:
	  cmplwi    r7, 0
	  add       r5, r24, r5
	  bne-      .loc_0x114
	  lwz       r12, 0x0(r28)
	  mr        r3, r4
	  lhz       r6, 0x28(r29)
	  mtlr      r12
	  addi      r4, r6, 0
	  blrl
	  b         .loc_0x130

	.loc_0x114:
	  stw       r27, 0x8(r1)
	  mr        r3, r31
	  addi      r8, r20, 0
	  lhz       r6, 0x28(r29)
	  addi      r10, r26, 0
	  lhz       r9, 0x28(r31)
	  bl        -0xE5C

	.loc_0x130:
	  addi      r25, r25, 0x1

	.loc_0x134:
	  cmpw      r25, r21
	  blt+      .loc_0xA4
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x3
	  addi      r30, r30, 0x34
	  addi      r29, r29, 0x38
	  blt+      .loc_0x64
	  lmw       r18, 0x28(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80022D28
 * Size:	000158
 */
static void MCBlockDecDCNest(VideoState* state, MCPlane mcplanes[HVQM_PLANE_COUNT])
{
	int plane_idx;
	BlockData* ptr;
	HVQPlaneDesc* plane;
	u32 stride, value, type;
	int line, block_idx;
	int j;
	u8* dst;
	u8 top, left, right, bottom;

	for (plane_idx = 0; plane_idx < PLANE_COUNT; ++plane_idx) {
		ptr    = mcplanes[plane_idx].data;
		plane  = &state->pln[plane_idx];
		stride = plane->plane_width;
		line   = plane->nblocks_hb;
		for (j = 0; j < plane->nblocks_mcb; ++j) {
			// dst is a 4x4 region
			dst       = mcplanes[plane_idx].blk_top + plane->imgUscan[j];
			block_idx = plane->bibUscan[j];
			value     = ptr[block_idx].dcv;
			// block type:
			// 0: weighted
			// 6: literal block
			// 8: single value
			type = ptr[block_idx].bnm & 0xF;
			// see also IpicBlockDec
			if (type == 0) {
				top    = ptr[block_idx - line].bnm & 0x77 ? value : ptr[block_idx - line].dcv;
				left   = ptr[block_idx - 1].bnm & 0x77 ? value : ptr[block_idx - 1].dcv;
				right  = ptr[block_idx + 1].bnm & 0x77 ? value : ptr[block_idx + 1].dcv;
				bottom = ptr[block_idx + line].bnm & 0x77 ? value : ptr[block_idx + line].dcv;
				WeightImBlock(dst, stride, value, top, bottom, left, right);
			} else if (type == 8) {
				//	dcBlock(dst, stride, value);
			} else {
				IntraAotBlock(state, dst, stride, value, type, plane_idx);
			}
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r21, 0x1C(r1)
	  addi      r23, r3, 0
	  addi      r22, r4, 0
	  addi      r21, r23, 0
	  li        r31, 0

	.loc_0x20:
	  lwz       r30, 0x8(r22)
	  addi      r27, r21, 0x10
	  lhz       r29, 0x28(r21)
	  addi      r26, r21, 0x18
	  lhz       r28, 0xC(r21)
	  lbz       r25, 0x34(r21)
	  li        r24, 0
	  b         .loc_0x128

	.loc_0x40:
	  lhz       r0, 0x0(r27)
	  addi      r27, r27, 0x2
	  lwz       r4, 0x0(r26)
	  addi      r26, r26, 0x4
	  rlwinm    r3,r0,1,0,30
	  add       r3, r30, r3
	  lwz       r6, 0x14(r22)
	  lbz       r5, 0x1(r3)
	  lbz       r10, 0x0(r3)
	  add       r4, r6, r4
	  rlwinm    r5,r5,0,28,31
	  addi      r7, r5, 0
	  rlwinm.   r5,r5,0,24,31
	  bne-      .loc_0x110
	  sub       r5, r0, r28
	  rlwinm    r5,r5,1,0,30
	  add       r6, r30, r5
	  lbz       r5, 0x1(r6)
	  andi.     r5, r5, 0x77
	  beq-      .loc_0x98
	  mr        r6, r10
	  b         .loc_0x9C

	.loc_0x98:
	  lbz       r6, 0x0(r6)

	.loc_0x9C:
	  lbz       r5, -0x1(r3)
	  andi.     r5, r5, 0x77
	  beq-      .loc_0xB0
	  mr        r7, r10
	  b         .loc_0xB4

	.loc_0xB0:
	  lbz       r7, -0x2(r3)

	.loc_0xB4:
	  lbz       r5, 0x3(r3)
	  addi      r8, r7, 0
	  andi.     r5, r5, 0x77
	  beq-      .loc_0xCC
	  mr        r3, r10
	  b         .loc_0xD0

	.loc_0xCC:
	  lbz       r3, 0x2(r3)

	.loc_0xD0:
	  add       r0, r0, r28
	  rlwinm    r0,r0,1,0,30
	  add       r5, r30, r0
	  lbz       r0, 0x1(r5)
	  addi      r9, r3, 0
	  andi.     r0, r0, 0x77
	  beq-      .loc_0xF4
	  mr        r0, r10
	  b         .loc_0xF8

	.loc_0xF4:
	  lbz       r0, 0x0(r5)

	.loc_0xF8:
	  addi      r3, r4, 0
	  mr        r7, r0
	  addi      r4, r29, 0
	  addi      r5, r10, 0
	  bl        -0x31F4
	  b         .loc_0x124

	.loc_0x110:
	  addi      r3, r23, 0
	  addi      r5, r29, 0
	  addi      r6, r10, 0
	  addi      r8, r31, 0
	  bl        -0x302C

	.loc_0x124:
	  addi      r24, r24, 0x1

	.loc_0x128:
	  cmpw      r24, r25
	  blt+      .loc_0x40
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x3
	  addi      r22, r22, 0x34
	  addi      r21, r21, 0x38
	  blt+      .loc_0x20
	  lmw       r21, 0x1C(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
static void initMCBproc(BitBufferWithTree* buftree, RLDecoder* proc)
{
	if (buftree->buf.ptr) {
		proc->value = getBit(&buftree->buf);
		proc->count = decodeUOvfSym(buftree, 0xFF);
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
static u32 getMCBproc(BitBufferWithTree* buftree, RLDecoder* proc)
{
	if (proc->count == 0) {
		proc->value ^= 1;
		proc->count = decodeUOvfSym(buftree, 0xFF);
	}
	--proc->count;
	return proc->value;

	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
static void initMCBtype(BitBufferWithTree* buftree, RLDecoder* type)
{
	u32 value;
	if (buftree->buf.ptr) {
		value       = getBit(&buftree->buf) << 1;
		type->value = value | getBit(&buftree->buf);
		type->count = decodeUOvfSym(buftree, 0xFF);
	}

	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
static u32 getMCBtype(BitBufferWithTree* buftree, RLDecoder* type)
{
	const static u32 mcbtypetrans[2][3] = {
		{ 1, 2, 0 },
		{ 2, 0, 1 },
	};

	u32 bit;

	if (type->count == 0) {
		// only three possible values, so when the value changes,
		// a single bit decides which other value to select
		// bit == 0 -> increment
		// bit == 1 -> decrement
		// then wrap to range 0..2
		bit         = getBit(&buftree->buf);
		type->value = mcbtypetrans[bit][type->value];
		type->count = decodeUOvfSym(buftree, 0xFF);
	}
	--type->count;
	return type->value;

	// UNUSED FUNCTION
}

static void getMVector(int* result, BitBufferWithTree* buf, u32 residual_bits)
{
	int i;

	int max_val_plus_1 = 1 << (residual_bits + 5);
	// quantized value
	int value = decodeHuff(buf) << residual_bits;
	// residual bits
	for (i = residual_bits - 1; i >= 0; --i)
		value += getBit(&buf->buf) << i;
	*result += value;
	// signed wrap to -max_val_plus_1 .. max_val_plus_1-1
	if (*result >= max_val_plus_1)
		*result -= max_val_plus_1 << 1;
	else if (*result < -max_val_plus_1)
		*result += max_val_plus_1 << 1;
}

// select which frame to use as an MC reference
static void setMCTarget(MCPlane mcplanes[PLANE_COUNT], u32 reference_frame)
{
	if (reference_frame == 0) {
		mcplanes[0].targ = mcplanes[0].forw;
		mcplanes[1].targ = mcplanes[1].forw;
		mcplanes[2].targ = mcplanes[2].forw;
	} else {
		mcplanes[0].targ = mcplanes[0].back;
		mcplanes[1].targ = mcplanes[1].back;
		mcplanes[2].targ = mcplanes[2].back;
	}
}

// advance one 8x8 block to the right
// (8x8 in seqobj size units, which are presumably pixels)
static void setMCNextBlk(MCPlane mcplanes[PLANE_COUNT])
{
	int i;
	for (i = 0; i < PLANE_COUNT; ++i) {
		mcplanes[i].blk_top += mcplanes[i].next_macro_pix;
		mcplanes[i].data += mcplanes[i].hvqblk_h;
	}
}

// move to the next row of 8x8 blocks
// (8x8 in seqobj size units, which are presumably pixels)
static void setMCDownBlk(MCPlane mcplanes[PLANE_COUNT])
{
	int i;
	MCPlane* mcplane;
	BlockData* first_block_on_next_row;

	for (i = 0; i < PLANE_COUNT; ++i) {
		mcplane = &mcplanes[i];
		mcplane->lin_top += mcplane->down_macro_pix;
		first_block_on_next_row = mcplane->data_top + mcplane->hvqblk_v;
		mcplane->data_top       = first_block_on_next_row;
		mcplane->data           = first_block_on_next_row;
	}
}

static void setMCTop(MCPlane mcplanes[PLANE_COUNT])
{
	int i;

	for (i = 0; i < PLANE_COUNT; ++i)
		mcplanes[i].blk_top = mcplanes[i].lin_top;
}

static void reset_prev_dcv(MCPlane mcplanes[PLANE_COUNT])
{
	int i;
	for (i = 0; i < PLANE_COUNT; ++i)
		mcplanes[i].prev_dcv = 0x7F;
}

static void decode_prev_dcv(VideoState* state, MCPlane mcplanes[PLANE_COUNT])
{
	int i, j;
	HVQPlaneDesc* plane;
	MCPlane* mcplane;
	BlockData* blockInfoTop;

	for (i = 0; i < PLANE_COUNT; ++i) {
		plane   = &state->pln[i];
		mcplane = &mcplanes[i];
		for (j = 0; j < plane->nblocks_mcb; ++j) {
			mcplane->prev_dcv += decodeSOvfSym(&state->dcval[i], state->dc_min, state->dc_max);
			blockInfoTop                         = mcplane->data;
			blockInfoTop[plane->bibUscan[j]].dcv = mcplane->prev_dcv;
		}
	}
}

/*
 * --INFO--
 * Address:	80022E80
 * Size:	000430
 */
static void spread_PB_descMap(SeqObj* seqObj, MCPlane mcplanes[HVQM_PLANE_COUNT])
{
	int i, j;
	struct RLDecoder proc;
	struct RLDecoder type;
	VideoState* state = (VideoState*)seqObj->ws;
	initMCBproc(&state->mcaot, &proc);
	initMCBtype(&state->mstat, &type);
	for (i = 0; i < seqObj->frame_height; i += 8) {
		setMCTop(mcplanes);
		for (j = 0; j < seqObj->frame_width; j += 8) {
			getMCBtype(&state->mstat, &type);
			if (type.value == 0) {
				decode_prev_dcv(state, mcplanes);
				decode_PB_cc(state, mcplanes, 0, type.value);
			} else {
				reset_prev_dcv(mcplanes);
				decode_PB_cc(state, mcplanes, getMCBproc(&state->mcaot, &proc), type.value);
			}
			setMCNextBlk(mcplanes);
			// for all pln
			//     top             += next_macro_pix
			//     data += hvqblk_h
		}
		setMCDownBlk(mcplanes);
		// for all pln
		//     lin_top += down_macro_pix
		//     data_top += stride;
		//     data = data_top
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stmw      r14, 0x90(r1)
	  mr        r16, r4
	  stw       r3, 0x78(r1)
	  lwz       r3, 0x78(r1)
	  lwz       r5, 0x0(r3)
	  lwz       r3, 0x6234(r5)
	  addi      r27, r5, 0
	  cmplwi    r3, 0
	  beq-      .loc_0x84
	  lwz       r4, 0x6240(r27)
	  cmpwi     r4, 0
	  bge-      .loc_0x54
	  addi      r0, r3, 0x4
	  stw       r0, 0x6234(r27)
	  li        r4, 0x1F
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x623C(r27)
	  b         .loc_0x58

	.loc_0x54:
	  lwz       r0, 0x623C(r27)

	.loc_0x58:
	  srw       r0, r0, r4
	  subi      r3, r4, 0x1
	  rlwinm    r0,r0,0,31,31
	  stw       r3, 0x6240(r27)
	  li        r17, 0
	  stw       r0, 0x84(r1)

	.loc_0x70:
	  addi      r3, r27, 0x6234
	  bl        -0x36CC
	  cmpwi     r3, 0xFF
	  add       r17, r17, r3
	  bge+      .loc_0x70

	.loc_0x84:
	  lwz       r3, 0x6248(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x12C
	  lwz       r4, 0x6254(r27)
	  cmpwi     r4, 0
	  bge-      .loc_0xB4
	  addi      r0, r3, 0x4
	  stw       r0, 0x6248(r27)
	  li        r4, 0x1F
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x6250(r27)
	  b         .loc_0xB8

	.loc_0xB4:
	  lwz       r3, 0x6250(r27)

	.loc_0xB8:
	  subi      r0, r4, 0x1
	  stw       r0, 0x6254(r27)
	  srw       r0, r3, r4
	  rlwinm    r0,r0,1,30,30
	  lwz       r4, 0x6254(r27)
	  stw       r0, 0x88(r1)
	  cmpwi     r4, 0
	  bge-      .loc_0xF4
	  lwz       r3, 0x6248(r27)
	  li        r4, 0x1F
	  addi      r0, r3, 0x4
	  stw       r0, 0x6248(r27)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x6250(r27)
	  b         .loc_0xF8

	.loc_0xF4:
	  lwz       r0, 0x6250(r27)

	.loc_0xF8:
	  srw       r3, r0, r4
	  subi      r0, r4, 0x1
	  stw       r0, 0x6254(r27)
	  rlwinm    r3,r3,0,31,31
	  lwz       r0, 0x88(r1)
	  li        r18, 0
	  or        r0, r0, r3
	  stw       r0, 0x88(r1)

	.loc_0x118:
	  addi      r3, r27, 0x6248
	  bl        -0x3774
	  cmpwi     r3, 0xFF
	  add       r18, r18, r3
	  bge+      .loc_0x118

	.loc_0x12C:
	  lis       r3, 0x8022
	  addi      r0, r3, 0x22A0
	  stw       r0, 0x8C(r1)
	  li        r0, 0
	  addi      r15, r16, 0x34
	  stw       r0, 0x7C(r1)
	  addi      r14, r16, 0x68
	  b         .loc_0x408

	.loc_0x14C:
	  lwz       r3, 0x10(r16)
	  li        r0, 0
	  stw       r0, 0x80(r1)
	  stw       r3, 0x14(r16)
	  lwz       r0, 0x10(r15)
	  stw       r0, 0x14(r15)
	  lwz       r0, 0x10(r14)
	  stw       r0, 0x14(r14)
	  b         .loc_0x370

	.loc_0x170:
	  cmpwi     r18, 0
	  bne-      .loc_0x1EC
	  lwz       r3, 0x6254(r27)
	  cmpwi     r3, 0
	  bge-      .loc_0x1A0
	  lwz       r4, 0x6248(r27)
	  li        r3, 0x1F
	  addi      r0, r4, 0x4
	  stw       r0, 0x6248(r27)
	  lwz       r0, 0x0(r4)
	  stw       r0, 0x6250(r27)
	  b         .loc_0x1A4

	.loc_0x1A0:
	  lwz       r0, 0x6250(r27)

	.loc_0x1A4:
	  srw       r0, r0, r3
	  rlwinm    r0,r0,0,31,31
	  mulli     r4, r0, 0xC
	  subi      r0, r3, 0x1
	  stw       r0, 0x6254(r27)
	  li        r18, 0
	  lwz       r0, 0x8C(r1)
	  add       r3, r0, r4
	  lwz       r0, 0x88(r1)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x88(r1)

	.loc_0x1D8:
	  addi      r3, r27, 0x6248
	  bl        -0x3834
	  cmpwi     r3, 0xFF
	  add       r18, r18, r3
	  bge+      .loc_0x1D8

	.loc_0x1EC:
	  lwz       r0, 0x88(r1)
	  subi      r18, r18, 0x1
	  cmpwi     r0, 0
	  bne-      .loc_0x2A4
	  addi      r31, r16, 0
	  addi      r21, r27, 0
	  addi      r20, r27, 0
	  li        r19, 0

	.loc_0x20C:
	  lbz       r22, 0x34(r21)
	  addi      r23, r20, 0x60D8
	  addi      r28, r21, 0x10
	  li        r29, 0
	  b         .loc_0x26C

	.loc_0x220:
	  lhz       r24, 0x0(r28)
	  li        r30, 0
	  lwz       r26, 0x6CC8(r27)
	  addi      r28, r28, 0x2
	  lwz       r25, 0x6CCC(r27)

	.loc_0x234:
	  mr        r3, r23
	  bl        -0x3890
	  cmpw      r25, r3
	  add       r30, r30, r3
	  bge+      .loc_0x234
	  cmpw      r3, r26
	  bge+      .loc_0x234
	  lwz       r0, 0x4(r31)
	  rlwinm    r3,r24,1,0,30
	  addi      r29, r29, 0x1
	  add       r0, r0, r30
	  stw       r0, 0x4(r31)
	  lwz       r4, 0x8(r31)
	  stbx      r0, r4, r3

	.loc_0x26C:
	  cmpw      r29, r22
	  blt+      .loc_0x220
	  addi      r19, r19, 0x1
	  cmpwi     r19, 0x3
	  addi      r31, r31, 0x34
	  addi      r21, r21, 0x38
	  addi      r20, r20, 0x14
	  blt+      .loc_0x20C
	  lwz       r6, 0x88(r1)
	  addi      r3, r27, 0
	  addi      r4, r16, 0
	  li        r5, 0
	  bl        -0x16A4
	  b         .loc_0x2F8

	.loc_0x2A4:
	  li        r0, 0x7F
	  stw       r0, 0x4(r16)
	  cmpwi     r17, 0
	  stw       r0, 0x38(r16)
	  stw       r0, 0x6C(r16)
	  bne-      .loc_0x2E0
	  lwz       r0, 0x84(r1)
	  li        r17, 0
	  xori      r0, r0, 0x1
	  stw       r0, 0x84(r1)

	.loc_0x2CC:
	  addi      r3, r27, 0x6234
	  bl        -0x3928
	  cmpwi     r3, 0xFF
	  add       r17, r17, r3
	  bge+      .loc_0x2CC

	.loc_0x2E0:
	  lwz       r5, 0x84(r1)
	  addi      r3, r27, 0
	  lwz       r6, 0x88(r1)
	  addi      r4, r16, 0
	  subi      r17, r17, 0x1
	  bl        -0x16FC

	.loc_0x2F8:
	  lwz       r3, 0x14(r16)
	  lhz       r0, 0x24(r16)
	  add       r0, r3, r0
	  stw       r0, 0x14(r16)
	  lwz       r0, 0x2C(r16)
	  lwz       r3, 0x8(r16)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0x8(r16)
	  lwz       r3, 0x14(r15)
	  lhz       r0, 0x24(r15)
	  add       r0, r3, r0
	  stw       r0, 0x14(r15)
	  lwz       r0, 0x2C(r15)
	  lwz       r3, 0x8(r15)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0x8(r15)
	  lwz       r3, 0x14(r14)
	  lhz       r0, 0x24(r14)
	  add       r0, r3, r0
	  stw       r0, 0x14(r14)
	  lwz       r0, 0x2C(r14)
	  lwz       r3, 0x8(r14)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  lwz       r3, 0x80(r1)
	  stw       r0, 0x8(r14)
	  addi      r3, r3, 0x8
	  stw       r3, 0x80(r1)

	.loc_0x370:
	  lwz       r3, 0x78(r1)
	  lwz       r0, 0x80(r1)
	  lhz       r3, 0x4(r3)
	  cmpw      r0, r3
	  blt+      .loc_0x170
	  lwz       r3, 0x10(r16)
	  lwz       r0, 0x28(r16)
	  add       r0, r3, r0
	  stw       r0, 0x10(r16)
	  lwz       r0, 0x30(r16)
	  lwz       r3, 0xC(r16)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xC(r16)
	  stw       r0, 0x8(r16)
	  lwz       r3, 0x10(r15)
	  lwz       r0, 0x28(r15)
	  add       r0, r3, r0
	  stw       r0, 0x10(r15)
	  lwz       r0, 0x30(r15)
	  lwz       r3, 0xC(r15)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xC(r15)
	  stw       r0, 0x8(r15)
	  lwz       r3, 0x10(r14)
	  lwz       r0, 0x28(r14)
	  add       r0, r3, r0
	  stw       r0, 0x10(r14)
	  lwz       r0, 0x30(r14)
	  lwz       r3, 0xC(r14)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  lwz       r3, 0x7C(r1)
	  stw       r0, 0xC(r14)
	  addi      r3, r3, 0x8
	  stw       r0, 0x8(r14)
	  stw       r3, 0x7C(r1)

	.loc_0x408:
	  lwz       r3, 0x78(r1)
	  lwz       r0, 0x7C(r1)
	  lhz       r3, 0x6(r3)
	  cmpw      r0, r3
	  blt+      .loc_0x14C
	  lmw       r14, 0x90(r1)
	  lwz       r0, 0xDC(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800232B0
 * Size:	00043C
 */
static void BpicPlaneDec(SeqObj* seqObj, u8* lin_top, u8* forw, u8* back)
{

	VideoState* state;
	int mvecx, mvecy;
	int reference_frame;
	u8 bits;
	int new_reference_frame;
	int x, y;
	int mcaot;
	MCPlane mcplanes[PLANE_COUNT];
	u32 badCompiler[4];

	state = (VideoState*)seqObj->ws;
	initMCHandler(state, mcplanes, lin_top, forw, back);
	spread_PB_descMap(seqObj, mcplanes);
	resetMCHandler(state, mcplanes, lin_top);
	reference_frame = -1;
	// MC blocks are 8x8 pixels
	for (y = 0; y < seqObj->frame_height; y += 8) {
		setMCTop(mcplanes);
		for (x = 0; x < seqObj->frame_width; x += 8) {
			bits = mcplanes[0].data->bnm;
			// 0: intra
			// 1: inter - past
			// 2: inter - future
			// see getMCBtype()
			new_reference_frame = (bits >> 5) & 3;
			if (new_reference_frame == 0) {
				// intra
				MCBlockDecDCNest(state, mcplanes);
			} else {
				// inter
				--new_reference_frame;
				// check if we need to update the reference frame pointers
				if (new_reference_frame != reference_frame) {
					reference_frame = new_reference_frame;
					setMCTarget(mcplanes, reference_frame);
					mvecx = 0;
					mvecy = 0;
				}
				getMVector(&mvecx, &state->mvecx, state->fcode[0][reference_frame]);
				getMVector(&mvecy, &state->mvecy, state->fcode[1][reference_frame]);

				// compute half-pixel position of reference macroblock
				// see getMCBproc()
				mcaot = (bits >> 4) & 1;
				if (mcaot == 0)
					MCBlockDecMCNest(state, mcplanes, (x << 1) + mvecx, (y << 1) + mvecy);
				else
					MotionComp(state, mcplanes, (x << 1) + mvecx, (y << 1) + mvecy);
			}
			setMCNextBlk(mcplanes);
		}
		setMCDownBlk(mcplanes);
	}

	/*
	.loc_0x0:
	  mflr      r0
	  addi      r7, r6, 0
	  stw       r0, 0x4(r1)
	  addi      r0, r5, 0
	  mr        r6, r0
	  stwu      r1, -0x150(r1)
	  stmw      r15, 0x10C(r1)
	  addi      r15, r4, 0
	  mr        r19, r3
	  addi      r5, r15, 0
	  addi      r4, r1, 0x68
	  lwz       r25, 0x0(r3)
	  addi      r3, r25, 0
	  bl        -0x2988
	  addi      r3, r19, 0
	  addi      r4, r1, 0x68
	  bl        -0x470
	  stw       r15, 0x78(r1)
	  li        r20, 0
	  rlwinm    r28,r20,1,0,30
	  lwz       r0, 0x4(r25)
	  addi      r31, r25, 0x620C
	  addi      r30, r25, 0x6220
	  stw       r0, 0x70(r1)
	  li        r22, -0x1
	  stw       r0, 0x74(r1)
	  lwz       r0, 0x2C(r25)
	  add       r3, r15, r0
	  stw       r3, 0xAC(r1)
	  lwz       r0, 0x3C(r25)
	  stw       r0, 0xA4(r1)
	  stw       r0, 0xA8(r1)
	  lwz       r0, 0x64(r25)
	  add       r3, r3, r0
	  stw       r3, 0xE0(r1)
	  lwz       r0, 0x74(r25)
	  stw       r0, 0xD8(r1)
	  stw       r0, 0xDC(r1)
	  b         .loc_0x41C

	.loc_0x9C:
	  lwz       r0, 0x78(r1)
	  li        r21, 0
	  rlwinm    r29,r21,1,0,30
	  stw       r0, 0x7C(r1)
	  lwz       r0, 0xAC(r1)
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r0, 0xE4(r1)
	  b         .loc_0x390

	.loc_0xC0:
	  lwz       r3, 0x70(r1)
	  lbz       r27, 0x1(r3)
	  rlwinm.   r3,r27,27,30,31
	  bne-      .loc_0xE0
	  addi      r3, r25, 0
	  addi      r4, r1, 0x68
	  bl        -0x660
	  b         .loc_0x31C

	.loc_0xE0:
	  subi      r0, r3, 0x1
	  cmpw      r0, r22
	  beq-      .loc_0x134
	  cmpwi     r0, 0
	  mr        r22, r0
	  bne-      .loc_0x114
	  lwz       r0, 0x84(r1)
	  stw       r0, 0x80(r1)
	  lwz       r0, 0xB8(r1)
	  stw       r0, 0xB4(r1)
	  lwz       r0, 0xEC(r1)
	  stw       r0, 0xE8(r1)
	  b         .loc_0x12C

	.loc_0x114:
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x80(r1)
	  lwz       r0, 0xBC(r1)
	  stw       r0, 0xB4(r1)
	  lwz       r0, 0xF0(r1)
	  stw       r0, 0xE8(r1)

	.loc_0x12C:
	  li        r23, 0
	  li        r24, 0

	.loc_0x134:
	  add       r26, r25, r22
	  lwz       r15, 0x621C(r25)
	  lbz       r16, 0x6CD2(r26)
	  li        r3, 0x1
	  lwz       r17, 0x4(r15)
	  addi      r0, r16, 0x5
	  slw       r18, r3, r0
	  b         .loc_0x170

	.loc_0x154:
	  mr        r3, r31
	  bl        -0x3C20
	  rlwinm    r3,r3,11,0,20
	  rlwinm    r0,r17,2,0,29
	  add       r3, r3, r0
	  addi      r0, r3, 0x8
	  lwzx      r17, r15, r0

	.loc_0x170:
	  cmpwi     r17, 0x100
	  bge+      .loc_0x154
	  subic.    r4, r16, 0x1
	  rlwinm    r3,r17,2,0,29
	  addi      r3, r3, 0x8
	  addi      r0, r4, 0x1
	  lwzx      r3, r15, r3
	  mtctr     r0
	  slw       r5, r3, r16
	  blt-      .loc_0x1E4

	.loc_0x198:
	  lwz       r6, 0x6218(r25)
	  cmpwi     r6, 0
	  bge-      .loc_0x1C0
	  lwz       r3, 0x620C(r25)
	  li        r6, 0x1F
	  addi      r0, r3, 0x4
	  stw       r0, 0x620C(r25)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x6214(r25)
	  b         .loc_0x1C4

	.loc_0x1C0:
	  lwz       r0, 0x6214(r25)

	.loc_0x1C4:
	  srw       r0, r0, r6
	  rlwinm    r0,r0,0,31,31
	  slw       r0, r0, r4
	  subi      r3, r6, 0x1
	  stw       r3, 0x6218(r25)
	  add       r5, r5, r0
	  subi      r4, r4, 0x1
	  bdnz+     .loc_0x198

	.loc_0x1E4:
	  add       r24, r24, r5
	  cmpw      r24, r18
	  blt-      .loc_0x1FC
	  rlwinm    r0,r18,1,0,30
	  sub       r24, r24, r0
	  b         .loc_0x210

	.loc_0x1FC:
	  neg       r0, r18
	  cmpw      r24, r0
	  bge-      .loc_0x210
	  rlwinm    r0,r18,1,0,30
	  add       r24, r24, r0

	.loc_0x210:
	  lbz       r15, 0x6CD4(r26)
	  li        r3, 0x1
	  lwz       r16, 0x6230(r25)
	  addi      r0, r15, 0x5
	  lwz       r17, 0x4(r16)
	  slw       r18, r3, r0
	  b         .loc_0x248

	.loc_0x22C:
	  mr        r3, r30
	  bl        -0x3CF8
	  rlwinm    r3,r3,11,0,20
	  rlwinm    r0,r17,2,0,29
	  add       r3, r3, r0
	  addi      r0, r3, 0x8
	  lwzx      r17, r16, r0

	.loc_0x248:
	  cmpwi     r17, 0x100
	  bge+      .loc_0x22C
	  subic.    r4, r15, 0x1
	  rlwinm    r3,r17,2,0,29
	  addi      r3, r3, 0x8
	  addi      r0, r4, 0x1
	  lwzx      r3, r16, r3
	  mtctr     r0
	  slw       r5, r3, r15
	  blt-      .loc_0x2BC

	.loc_0x270:
	  lwz       r6, 0x622C(r25)
	  cmpwi     r6, 0
	  bge-      .loc_0x298
	  lwz       r3, 0x6220(r25)
	  li        r6, 0x1F
	  addi      r0, r3, 0x4
	  stw       r0, 0x6220(r25)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x6228(r25)
	  b         .loc_0x29C

	.loc_0x298:
	  lwz       r0, 0x6228(r25)

	.loc_0x29C:
	  srw       r0, r0, r6
	  rlwinm    r0,r0,0,31,31
	  slw       r0, r0, r4
	  subi      r3, r6, 0x1
	  stw       r3, 0x622C(r25)
	  add       r5, r5, r0
	  subi      r4, r4, 0x1
	  bdnz+     .loc_0x270

	.loc_0x2BC:
	  add       r23, r23, r5
	  cmpw      r23, r18
	  blt-      .loc_0x2D4
	  rlwinm    r0,r18,1,0,30
	  sub       r23, r23, r0
	  b         .loc_0x2E8

	.loc_0x2D4:
	  neg       r0, r18
	  cmpw      r23, r0
	  bge-      .loc_0x2E8
	  rlwinm    r0,r18,1,0,30
	  add       r23, r23, r0

	.loc_0x2E8:
	  rlwinm.   r0,r27,28,31,31
	  bne-      .loc_0x308
	  addi      r3, r25, 0
	  addi      r4, r1, 0x68
	  add       r5, r29, r24
	  add       r6, r28, r23
	  bl        -0x9EC
	  b         .loc_0x31C

	.loc_0x308:
	  addi      r3, r25, 0
	  addi      r4, r1, 0x68
	  add       r5, r29, r24
	  add       r6, r28, r23
	  bl        -0x2550

	.loc_0x31C:
	  lwz       r3, 0x7C(r1)
	  addi      r29, r29, 0x10
	  lhz       r0, 0x8C(r1)
	  addi      r21, r21, 0x8
	  add       r0, r3, r0
	  stw       r0, 0x7C(r1)
	  lwz       r0, 0x94(r1)
	  lwz       r3, 0x70(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0x70(r1)
	  lwz       r3, 0xB0(r1)
	  lhz       r0, 0xC0(r1)
	  add       r0, r3, r0
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0xC8(r1)
	  lwz       r3, 0xA4(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xA4(r1)
	  lwz       r3, 0xE4(r1)
	  lhz       r0, 0xF4(r1)
	  add       r0, r3, r0
	  stw       r0, 0xE4(r1)
	  lwz       r0, 0xFC(r1)
	  lwz       r3, 0xD8(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xD8(r1)

	.loc_0x390:
	  lhz       r0, 0x4(r19)
	  cmpw      r21, r0
	  blt+      .loc_0xC0
	  lwz       r3, 0x78(r1)
	  addi      r28, r28, 0x10
	  lwz       r0, 0x90(r1)
	  addi      r20, r20, 0x8
	  add       r0, r3, r0
	  stw       r0, 0x78(r1)
	  lwz       r0, 0x98(r1)
	  lwz       r3, 0x74(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0x74(r1)
	  stw       r0, 0x70(r1)
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xC4(r1)
	  add       r0, r3, r0
	  stw       r0, 0xAC(r1)
	  lwz       r0, 0xCC(r1)
	  lwz       r3, 0xA8(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xA8(r1)
	  stw       r0, 0xA4(r1)
	  lwz       r3, 0xE0(r1)
	  lwz       r0, 0xF8(r1)
	  add       r0, r3, r0
	  stw       r0, 0xE0(r1)
	  lwz       r0, 0x100(r1)
	  lwz       r3, 0xDC(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xDC(r1)
	  stw       r0, 0xD8(r1)

	.loc_0x41C:
	  lhz       r0, 0x6(r19)
	  cmpw      r20, r0
	  blt+      .loc_0x9C
	  lmw       r15, 0x10C(r1)
	  lwz       r0, 0x154(r1)
	  addi      r1, r1, 0x150
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800236EC
 * Size:	000020
 */
void HVQM4InitDecoder()
{
	init_global_constants();
}

/*
 * --INFO--
 * Address:	8002370C
 * Size:	000024
 */
void HVQM4InitSeqObj(SeqObj* obj, VideoInfo* header)
{
	obj->frame_width  = header->width;
	obj->frame_height = header->height;
	obj->h_samp       = header->h_sampling_rate;
	obj->v_samp       = header->v_sampling_rate;
}

/*
 * --INFO--
 * Address:	80023730
 * Size:	000074
 */
u32 HVQM4BuffSize(SeqObj* obj)
{
	const int nblocks_h    = obj->frame_width / 4;
	const int uv_nblocks_h = obj->h_samp == 2 ? nblocks_h >> 1 : nblocks_h;
	const int nblocks_v    = obj->frame_height / 4;
	const int uv_nblocks_v = obj->v_samp == 2 ? nblocks_v >> 1 : nblocks_v;

	const int y_blocks   = (nblocks_h + 2) * (nblocks_v + 2);
	const int unblocks_v = (uv_nblocks_h + 2) * (uv_nblocks_v + 2);
	return sizeof(VideoState) + (y_blocks + unblocks_v * 2) * sizeof(u16);
}

/*
 * --INFO--
 * Address:	800237A4
 * Size:	000464
 */
void HVQM4SetBuffer(SeqObj* obj, void* buf)
{
	VideoState* ws;
	BlockData* bp;
	int c, i;
	BlockData* p;

	ws      = (VideoState*)buf;
	obj->ws = buf;

	setHVQPlaneDesc(obj, 0, 1, 1);
	setHVQPlaneDesc(obj, 1, obj->h_samp, obj->v_samp);
	setHVQPlaneDesc(obj, 2, obj->h_samp, obj->v_samp);

	if ((ws->landscape = obj->frame_width >= obj->frame_height) != 0) {
		ws->nestsize_h = 70;
		ws->nestsize_v = 38;
	} else {
		ws->nestsize_h = 38;
		ws->nestsize_v = 70;
	}

	ws->bsnum[0].tree = ws->bsnum[1].tree = &ws->num_tree;
	ws->bsrun[0].tree = ws->bsrun[1].tree = &ws->zrn_tree;

	ws->dcval[0].tree = ws->dcval[1].tree = ws->dcval[2].tree = &ws->dcv_tree;
	ws->dcrun[0].tree = ws->dcrun[1].tree = ws->dcrun[2].tree = &ws->zrn_tree; // reuse!
	ws->scale[0].tree = ws->scale[1].tree = ws->scale[2].tree = &ws->scl_tree;
	ws->mvecx.tree = ws->mvecy.tree = &ws->vec_tree;
	ws->mcaot.tree = ws->mstat.tree = &ws->mrn_tree;

	bp = (BlockData*)((u8*)buf + sizeof(VideoState));
	for (c = 0; c < PLANE_COUNT; c++) {
		ws->pln[c].blockInfoBuf = bp;
		// skip top border (stride) and left border (1)
		ws->pln[c].blockInfoTop = bp + ws->pln[c].nblocks_hb + 1;
		bp += ws->pln[c].nblocks_hb * ws->pln[c].nblocks_vb;

		// set horizontal borders
		p = ws->pln[c].blockInfoBuf;
		for (i = ws->pln[c].nblocks_hb; i > 0; i--) {
			set_border(p);
			p++;
		}

		p = bp;
		for (i = ws->pln[c].nblocks_hb; i > 0; i--) {
			p--;
			set_border(p);
		}

		// set vertical borders
		p = ws->pln[c].blockInfoBuf + ws->pln[c].nblocks_hb;
		for (i = ws->pln[c].nblocks_vb - 2; i > 0; i--) {
			set_border(p);
			p += ws->pln[c].nblocks_hb;
		}

		p = ws->pln[c].blockInfoBuf + ws->pln[c].nblocks_hb * 2 - 1;
		for (i = ws->pln[c].nblocks_vb - 2; i > 0; i--) {
			set_border(p);
			p += ws->pln[c].nblocks_hb;
		}
	}
}

/*
 * --INFO--
 * Address:	80023C08
 * Size:	000510
 */
void HVQM4DecodeIpic(SeqObj* obj, void* code, void* outbuf)
{
	VideoState* ws;
	u8* body;
	int i;

	ws             = (VideoState*)obj->ws;
	ws->aotscale_q = read8(code, 1);
	body           = (u8*)code + 0x48;

	setCode(&ws->bsnum[0].buf, body + read32(code, 0x8));
	setCode(&ws->bsrun[0].buf, body + read32(code, 0xC));
	setCode(&ws->bsnum[1].buf, body + read32(code, 0x10));
	setCode(&ws->bsrun[1].buf, body + read32(code, 0x14));
	setCode(&ws->dcval[0].buf, body + read32(code, 0x18));
	setCode(&ws->scale[0].buf, body + read32(code, 0x1C));
	setCode(&ws->aotcd[0], body + read32(code, 0x20));
	setCode(&ws->dcval[1].buf, body + read32(code, 0x24));
	setCode(&ws->scale[1].buf, body + read32(code, 0x28));
	setCode(&ws->aotcd[1], body + read32(code, 0x2C));
	setCode(&ws->dcval[2].buf, body + read32(code, 0x30));
	setCode(&ws->scale[2].buf, body + read32(code, 0x34));
	setCode(&ws->aotcd[2], body + read32(code, 0x38));
	setCode(&ws->dcrun[0].buf, body + read32(code, 0x3C));
	setCode(&ws->dcrun[1].buf, body + read32(code, 0x40));
	setCode(&ws->dcrun[2].buf, body + read32(code, 0x44));

	// multiple BitBufferWithTree instances share the same Tree,
	// the first BitBuffer of each group contains the Tree itself
	readTree(&ws->bsnum[0], 0, 0);
	readTree(&ws->bsrun[0], 0, 0);
	readTree(&ws->dcval[0], 1, read8(code, 0));
	readTree(&ws->scale[0], 0, 2);

	ws->dc_max = +0x7F << read8(code, 0);
	ws->dc_min = -0x80 << read8(code, 0);

	// 4x4 block types
	Ipic_BasisNumDec(ws);
	// 4x4 block DC values
	IpicDcvDec(ws);
	// 70x38 nest copied from upper 4 bits of DC values somewhere in the luma plane
	MakeNest(ws, read16(code, 4), read16(code, 6));

	for (i = 0; i < PLANE_COUNT; ++i) {
		IpicPlaneDec(ws, i, outbuf);
		outbuf = (u8*)outbuf + ws->pln[i].plane_size;
	}
}

/*
 * --INFO--
 * Address:	80024118
 * Size:	000024
 */
void HVQM4DecodePpic(SeqObj* obj, void* code, void* outbuf, void* ref1)
{
	HVQM4DecodeBpic(obj, code, outbuf, ref1, outbuf);
}

/*
 * --INFO--
 * Address:	8002413C
 * Size:	0005A8
 */
void HVQM4DecodeBpic(SeqObj* obj, void* code, void* outbuf, void* ref2, void* ref1)
{
	VideoState* ws;
	u8* body;

	ws              = (VideoState*)obj->ws;
	ws->aotscale_q  = read8(code, 1);
	ws->dc_scale_q  = read8(code, 0);
	ws->fcode[0][0] = read8(code, 2);
	ws->fcode[1][0] = read8(code, 3);
	ws->fcode[0][1] = read8(code, 4);
	ws->fcode[1][1] = read8(code, 5);
	// offsets 6 and 7 are unused

	body = (u8*)code + 0x4C;

	setCode(&ws->bsnum[0].buf, body + read32(code, 0x08));
	setCode(&ws->bsrun[0].buf, body + read32(code, 0x0C));
	setCode(&ws->bsnum[1].buf, body + read32(code, 0x10));
	setCode(&ws->bsrun[1].buf, body + read32(code, 0x14));
	setCode(&ws->dcval[0].buf, body + read32(code, 0x18));
	setCode(&ws->scale[0].buf, body + read32(code, 0x1C));
	setCode(&ws->aotcd[0], body + read32(code, 0x20));
	setCode(&ws->dcval[1].buf, body + read32(code, 0x24));
	setCode(&ws->scale[1].buf, body + read32(code, 0x28));
	setCode(&ws->aotcd[1], body + read32(code, 0x2C));
	setCode(&ws->dcval[2].buf, body + read32(code, 0x30));
	setCode(&ws->scale[2].buf, body + read32(code, 0x34));
	setCode(&ws->aotcd[2], body + read32(code, 0x38));
	setCode(&ws->mvecx.buf, body + read32(code, 0x3C));
	setCode(&ws->mvecy.buf, body + read32(code, 0x40));
	setCode(&ws->mstat.buf, body + read32(code, 0x44));
	setCode(&ws->mcaot.buf, body + read32(code, 0x48));

	readTree(&ws->bsnum[0], 0, 0);
	readTree(&ws->bsrun[0], 0, 0);
	readTree(&ws->dcval[0], 1, read8(code, 0));
	readTree(&ws->scale[0], 0, 2);
	readTree(&ws->mvecx, 1, 0);
	readTree(&ws->mstat, 0, 0);

	ws->dc_max = +0x7F << read8(code, 0);
	ws->dc_min = -0x80 << read8(code, 0);

	BpicPlaneDec(obj, outbuf, ref2, ref1);
}
