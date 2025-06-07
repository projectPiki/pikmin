#include "types.h"
#include "hvqm4.h"

/*

Initial code attempts + comments + function arguments/naming guides taken from
http://github.com/Tilka/hvqm4
with many thanks.

Variable names are mostly from Bakuten Shoot Beyblade 2002.

*/

typedef void (*MotionCompFunc)(u8* cP, int cWidth, u8* tP, int tWidth);

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
	block[0] = block[1] = block[2] = block[3] = dc;
	block += blockWidth;

	block[0] = block[1] = block[2] = block[3] = dc;
	block += blockWidth;

	block[0] = block[1] = block[2] = block[3] = dc;
	block += blockWidth;

	block[0] = block[1] = block[2] = block[3] = dc;
	block += blockWidth;
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

	FORCE_DONT_INLINE;

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
static inline s32 GetAotBasis(VideoState* ws, u8* basisOut, s32* pscl, u8* nestTop, int nestWidth, int p)
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

	value       = *nP;
	basisOut[0] = value;
	min = max = value;

	nP += step_x;

	value       = *nP;
	basisOut[1] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value       = *nP;
	basisOut[2] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value       = *nP;
	basisOut[3] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestTop += step_y;
	nP = nestTop;

	value       = *nP;
	basisOut[4] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value       = *nP;
	basisOut[5] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value       = *nP;
	basisOut[6] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value       = *nP;
	basisOut[7] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestTop += step_y;
	nP = nestTop;

	value       = *nP;
	basisOut[8] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value       = *nP;
	basisOut[9] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value        = *nP;
	basisOut[10] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value        = *nP;
	basisOut[11] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestTop += step_y;
	nP = nestTop;

	value        = *nP;
	basisOut[12] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value        = *nP;
	basisOut[13] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value        = *nP;
	basisOut[14] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value        = *nP;
	basisOut[15] = value;
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
static inline s32 GetMCAotBasis(VideoState* ws, u8* basisOut, s32* pscl, u8* nestTop, int nestWidth, int p)
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

	value       = (*nP >> 4) & 0xF;
	basisOut[0] = value;
	min = max = value;

	nP += step_x;

	value       = (*nP >> 4) & 0xF;
	basisOut[1] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value       = (*nP >> 4) & 0xF;
	basisOut[2] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value       = (*nP >> 4) & 0xF;
	basisOut[3] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestTop += step_y;
	nP = nestTop;

	value       = (*nP >> 4) & 0xF;
	basisOut[4] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value       = (*nP >> 4) & 0xF;
	basisOut[5] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value       = (*nP >> 4) & 0xF;
	basisOut[6] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value       = (*nP >> 4) & 0xF;
	basisOut[7] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestTop += step_y;
	nP = nestTop;

	value       = (*nP >> 4) & 0xF;
	basisOut[8] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value       = (*nP >> 4) & 0xF;
	basisOut[9] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value        = (*nP >> 4) & 0xF;
	basisOut[10] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value        = (*nP >> 4) & 0xF;
	basisOut[11] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestTop += step_y;
	nP = nestTop;

	value        = (*nP >> 4) & 0xF;
	basisOut[12] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value        = (*nP >> 4) & 0xF;
	basisOut[13] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value        = (*nP >> 4) & 0xF;
	basisOut[14] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nP += step_x;

	value        = (*nP >> 4) & 0xF;
	basisOut[15] = value;
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

static inline s32 GetAotSum(VideoState* ws, s32* sum, u8 nbasis, u8* nestTop, int nestWidth, int p)
{
	s32 prev_scl;
	s32 scl;
	u8 bas[16];

	sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = sum[6] = sum[7] = sum[8] = sum[9] = sum[10] = sum[11] = sum[12] = sum[13]
	    = sum[14] = sum[15] = prev_scl = 0;

	while (nbasis--) {
		scl = GetMCAotBasis(ws, bas, &prev_scl, nestTop, nestWidth, p);
		sum[0] += scl * bas[0];
		sum[1] += scl * bas[1];
		sum[2] += scl * bas[2];
		sum[3] += scl * bas[3];
		sum[4] += scl * bas[4];
		sum[5] += scl * bas[5];
		sum[6] += scl * bas[6];
		sum[7] += scl * bas[7];
		sum[8] += scl * bas[8];
		sum[9] += scl * bas[9];
		sum[10] += scl * bas[10];
		sum[11] += scl * bas[11];
		sum[12] += scl * bas[12];
		sum[13] += scl * bas[13];
		sum[14] += scl * bas[14];
		sum[15] += scl * bas[15];
	}
	return (sum[0] + sum[1] + sum[2] + sum[3] + sum[4] + sum[5] + sum[6] + sum[7] + sum[8] + sum[9] + sum[10] + sum[11] + sum[12] + sum[13]
	        + sum[14] + sum[15])
	    >> 4;
}

static inline s32 GetMCAotSum(VideoState* ws, s32* sum, u8 nbasis, u8* nestTop, int nestWidth, int p)
{
	s32 prev_scl;
	s32 scl;
	u8 bas[16];

	sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = sum[6] = sum[7] = sum[8] = sum[9] = sum[10] = sum[11] = sum[12] = sum[13]
	    = sum[14] = sum[15] = prev_scl = 0;

	while (nbasis--) {
		scl = GetMCAotBasis(ws, bas, &prev_scl, nestTop, nestWidth, p);
		sum[0] += scl * bas[0];
		sum[1] += scl * bas[1];
		sum[2] += scl * bas[2];
		sum[3] += scl * bas[3];
		sum[4] += scl * bas[4];
		sum[5] += scl * bas[5];
		sum[6] += scl * bas[6];
		sum[7] += scl * bas[7];
		sum[8] += scl * bas[8];
		sum[9] += scl * bas[9];
		sum[10] += scl * bas[10];
		sum[11] += scl * bas[11];
		sum[12] += scl * bas[12];
		sum[13] += scl * bas[13];
		sum[14] += scl * bas[14];
		sum[15] += scl * bas[15];
	}
	return (sum[0] + sum[1] + sum[2] + sum[3] + sum[4] + sum[5] + sum[6] + sum[7] + sum[8] + sum[9] + sum[10] + sum[11] + sum[12] + sum[13]
	        + sum[14] + sum[15])
	    >> 4;
}

/*
 * --INFO--
 * Address:	8001FE1C
 * Size:	0003D0
 *
 * @note: AOT = Adaptive Orthogonal Transform, apparently
 */
static void IntraAotBlock(VideoState* ws, u8* blk, int blkWidth, u8 dcv, u8 nbasis, int p)
{
	s32 sum[16];
	s32 mns;
	int avr;

	if (nbasis == 6) {
		OrgBlock(ws, blk, blkWidth, p);
	} else {
		mns = ws->aotscale_q;
		// block types 1..5 serve as number of bases to use, 9..15 are unused
		avr = (dcv << mns) - GetAotSum(ws, sum, nbasis, ws->nestBuf, ws->nestsize_h, p);

		blk[0] = clipTable[((sum[0] + avr) >> mns) + 0x80];
		blk[1] = clipTable[((sum[1] + avr) >> mns) + 0x80];
		blk[2] = clipTable[((sum[2] + avr) >> mns) + 0x80];
		blk[3] = clipTable[((sum[3] + avr) >> mns) + 0x80];
		blk += blkWidth;

		blk[0] = clipTable[((sum[4] + avr) >> mns) + 0x80];
		blk[1] = clipTable[((sum[5] + avr) >> mns) + 0x80];
		blk[2] = clipTable[((sum[6] + avr) >> mns) + 0x80];
		blk[3] = clipTable[((sum[7] + avr) >> mns) + 0x80];
		blk += blkWidth;

		blk[0] = clipTable[((sum[8] + avr) >> mns) + 0x80];
		blk[1] = clipTable[((sum[9] + avr) >> mns) + 0x80];
		blk[2] = clipTable[((sum[10] + avr) >> mns) + 0x80];
		blk[3] = clipTable[((sum[11] + avr) >> mns) + 0x80];
		blk += blkWidth;

		blk[0] = clipTable[((sum[12] + avr) >> mns) + 0x80];
		blk[1] = clipTable[((sum[13] + avr) >> mns) + 0x80];
		blk[2] = clipTable[((sum[14] + avr) >> mns) + 0x80];
		blk[3] = clipTable[((sum[15] + avr) >> mns) + 0x80];
		blk += blkWidth;
	}
}

/*
 * --INFO--
 * Address:	80020668
 * Size:	000144
 */
static void IpicBlockDec(VideoState* ws, u8* block, int blockWidth, StackState* inter)
{
	if (inter->curr.bnm == 0) {
		u8 c_dc = inter->curr.dcv;
		u8 u_dc = inter->upp->bnm & 0x77 ? c_dc : inter->upp->dcv;
		u8 d_dc = inter->low->bnm & 0x77 ? c_dc : inter->low->dcv;
		u8 r_dc = inter->right.bnm & 0x77 ? c_dc : inter->right.dcv;
		// the left value is tracked manually, the logic is equivalent with the other surrounding values
		WeightImBlock(block, blockWidth, c_dc, u_dc, d_dc, inter->l_dcv, r_dc);
		inter->l_dcv = c_dc;
	} else if (inter->curr.bnm == 8) {
		u8 dc = inter->curr.dcv;
		dcBlock(block, blockWidth, dc);
		inter->l_dcv = dc;
	} else {
		IntraAotBlock(ws, block, blockWidth, inter->curr.dcv, inter->curr.bnm, inter->id);
		// don't use the current DC value to predict the next one
		inter->l_dcv = inter->right.dcv;
	}
	// next block
	inter->upp++;
	inter->low++;
}

/*
 * --INFO--
 * Address:	800207AC
 * Size:	0000D4
 */
static void IpicLineDec(VideoState* ws, u8* block, int blockWidth, StackState* inter, int lineWidth)
{
	int i;

	inter->right = *inter->mid;
	inter->l_dcv = inter->mid->dcv;

	for (i = lineWidth - 1; i > 0; i--) {
		inter->curr  = inter->right;
		inter->right = *++inter->mid;
		IpicBlockDec(ws, block, blockWidth, inter);
		block += 4;
	}

	inter->curr = inter->right;
	inter->mid += 3;
	IpicBlockDec(ws, block, blockWidth, inter);
	inter->upp += 2;
	inter->low += 2;
}

/*
 * --INFO--
 * Address:	80020880
 * Size:	0000DC
 */
static void IpicPlaneDec(VideoState* ws, int p, u8* outbuf)
{
	StackState inter;
	int imgWidth;
	int downblock;
	int h_block;
	int nblocks_hb;
	int j;

	imgWidth   = ws->pln[p].plane_width;
	downblock  = ws->pln[p].plane_width * 4; // blocks are 4x4 so advance outbuf by 4 lines
	h_block    = ws->pln[p].nblocks_h;
	nblocks_hb = ws->pln[p].nblocks_hb;

	inter.id  = p;
	inter.low = (inter.mid = inter.upp = ws->pln[p].blockInfoTop) + nblocks_hb;

	// first line
	IpicLineDec(ws, outbuf, imgWidth, &inter, h_block);
	outbuf += downblock;
	// middle lines
	inter.upp = ws->pln[p].blockInfoTop;
	for (j = ws->pln[p].nblocks_v - 2; j > 0; j--) {
		IpicLineDec(ws, outbuf, imgWidth, &inter, h_block);
		outbuf += downblock;
	}
	// last line
	inter.low = inter.mid;
	IpicLineDec(ws, outbuf, imgWidth, &inter, h_block);
}

/*
 * --INFO--
 * Address:	8002095C
 * Size:	00008C
 */
static void initMCHandler(VideoState* ws, MCHandler* mch, u8* lin_top, u8* forw, u8* back)
{
	int i;
	MCPlane* mcplane;
	HVQPlaneDesc* plane;
	BlockData* block;

	for (i = 0; i < PLANE_COUNT; i++) {
		mcplane            = &mch->pln[i];
		plane              = &ws->pln[i];
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
static void resetMCHandler(VideoState* state, MCHandler* mch, u8* lin_top)
{
	int i;
	MCPlane* pmc;

	for (i = 0; i < PLANE_COUNT; i++) {
		pmc           = &mch->pln[i];
		pmc->lin_top  = lin_top;
		pmc->data_top = pmc->data = state->pln[i].blockInfoTop;
		lin_top += state->pln[i].plane_size;
	}
}

static void setMCTop(MCHandler* mch)
{
	int i;
	MCPlane* pmc;

	for (i = 0; i < PLANE_COUNT; i++) {
		pmc          = &mch->pln[i];
		pmc->blk_top = pmc->lin_top;
	}
}

// advance one 8x8 block to the right
// (8x8 in seqobj size units, which are presumably pixels)
static void setMCNextBlk(MCHandler* mch)
{
	int i;
	MCPlane* pmc;

	for (i = 0; i < PLANE_COUNT; i++) {
		pmc = &mch->pln[i];
		pmc->blk_top += pmc->next_macro_pix;
		pmc->data += pmc->hvqblk_h;
	}
}

// move to the next row of 8x8 blocks
// (8x8 in seqobj size units, which are presumably pixels)
static void setMCDownBlk(MCHandler* mch)
{
	int i;
	MCPlane* pmc;

	for (i = 0; i < PLANE_COUNT; i++) {
		pmc = &mch->pln[i];
		pmc->lin_top += pmc->down_macro_pix;
		pmc->data = pmc->data_top = pmc->data_top + pmc->hvqblk_v;
	}
}

// select which frame to use as an MC reference
static void setMCTarget(MCHandler* mch, int direct)
{
	if (direct == 0) {
		mch->pln[0].targ = mch->pln[0].forw;
		mch->pln[1].targ = mch->pln[1].forw;
		mch->pln[2].targ = mch->pln[2].forw;
	} else {
		mch->pln[0].targ = mch->pln[0].back;
		mch->pln[1].targ = mch->pln[1].back;
		mch->pln[2].targ = mch->pln[2].back;
	}
}

/*
 * --INFO--
 * Address:	800209E8
 * Size:	00009C
 *
 * @note Copy 4x4 samples without interpolation.
 */
inline void _MotionComp_00(u8* cP, int cWidth, u8* tP, int tWidth)
{
	cP[0] = tP[0];
	cP[1] = tP[1];
	cP[2] = tP[2];
	cP[3] = tP[3];
	tP += tWidth;
	cP += cWidth;

	cP[0] = tP[0];
	cP[1] = tP[1];
	cP[2] = tP[2];
	cP[3] = tP[3];
	tP += tWidth;
	cP += cWidth;

	cP[0] = tP[0];
	cP[1] = tP[1];
	cP[2] = tP[2];
	cP[3] = tP[3];
	tP += tWidth;
	cP += cWidth;

	cP[0] = tP[0];
	cP[1] = tP[1];
	cP[2] = tP[2];
	cP[3] = tP[3];
	tP += tWidth;
	cP += cWidth;
}

/*
 * --INFO--
 * Address:	80020A84
 * Size:	0001AC
 *
 * @note Offset vertically by half a sample
 */
inline void _MotionComp_01(u8* cP, int cWidth, u8* tP, int tWidth)
{
	u8* up = (u8*)tP;
	u8* dn = (u8*)tP + tWidth;

	cP[0] = (up[0] + dn[0] + 1) >> 1;
	cP[1] = (up[1] + dn[1] + 1) >> 1;
	cP[2] = (up[2] + dn[2] + 1) >> 1;
	cP[3] = (up[3] + dn[3] + 1) >> 1;
	up += tWidth;
	dn += tWidth;
	cP += cWidth;

	cP[0] = (up[0] + dn[0] + 1) >> 1;
	cP[1] = (up[1] + dn[1] + 1) >> 1;
	cP[2] = (up[2] + dn[2] + 1) >> 1;
	cP[3] = (up[3] + dn[3] + 1) >> 1;
	up += tWidth;
	dn += tWidth;
	cP += cWidth;

	cP[0] = (up[0] + dn[0] + 1) >> 1;
	cP[1] = (up[1] + dn[1] + 1) >> 1;
	cP[2] = (up[2] + dn[2] + 1) >> 1;
	cP[3] = (up[3] + dn[3] + 1) >> 1;
	up += tWidth;
	dn += tWidth;
	cP += cWidth;

	cP[0] = (up[0] + dn[0] + 1) >> 1;
	cP[1] = (up[1] + dn[1] + 1) >> 1;
	cP[2] = (up[2] + dn[2] + 1) >> 1;
	cP[3] = (up[3] + dn[3] + 1) >> 1;
	up += tWidth;
	dn += tWidth;
	cP += cWidth;
}

/*
 * --INFO--
 * Address:	80020C30
 * Size:	00019C
 *
 * @note Offset vertically by half a sample
 */
inline void _MotionComp_10(u8* cP, int cWidth, u8* tP, int tWidth)
{
	cP[0] = (tP[0] + tP[1] + 1) >> 1;
	cP[1] = (tP[1] + tP[2] + 1) >> 1;
	cP[2] = (tP[2] + tP[3] + 1) >> 1;
	cP[3] = (tP[3] + tP[4] + 1) >> 1;
	tP += tWidth;
	cP += cWidth;

	cP[0] = (tP[0] + tP[1] + 1) >> 1;
	cP[1] = (tP[1] + tP[2] + 1) >> 1;
	cP[2] = (tP[2] + tP[3] + 1) >> 1;
	cP[3] = (tP[3] + tP[4] + 1) >> 1;
	tP += tWidth;
	cP += cWidth;

	cP[0] = (tP[0] + tP[1] + 1) >> 1;
	cP[1] = (tP[1] + tP[2] + 1) >> 1;
	cP[2] = (tP[2] + tP[3] + 1) >> 1;
	cP[3] = (tP[3] + tP[4] + 1) >> 1;
	tP += tWidth;
	cP += cWidth;

	cP[0] = (tP[0] + tP[1] + 1) >> 1;
	cP[1] = (tP[1] + tP[2] + 1) >> 1;
	cP[2] = (tP[2] + tP[3] + 1) >> 1;
	cP[3] = (tP[3] + tP[4] + 1) >> 1;
	tP += tWidth;
	cP += cWidth;
}

/*
 * --INFO--
 * Address:	80020DCC
 * Size:	0002AC
 *
 * @note Offset by half a sample in both directions
 */
inline void _MotionComp_11(u8* cP, int cWidth, u8* tP, int tWidth)
{
	u8* up = (u8*)tP;
	u8* dn = (u8*)tP + tWidth;

	cP[0] = (up[0] + up[1] + dn[0] + dn[1] + 2) >> 2;
	cP[1] = (up[1] + up[2] + dn[1] + dn[2] + 2) >> 2;
	cP[2] = (up[2] + up[3] + dn[2] + dn[3] + 2) >> 2;
	cP[3] = (up[3] + up[4] + dn[3] + dn[4] + 2) >> 2;
	up += tWidth;
	cP += cWidth;
	dn += tWidth;

	cP[0] = (up[0] + up[1] + dn[0] + dn[1] + 2) >> 2;
	cP[1] = (up[1] + up[2] + dn[1] + dn[2] + 2) >> 2;
	cP[2] = (up[2] + up[3] + dn[2] + dn[3] + 2) >> 2;
	cP[3] = (up[3] + up[4] + dn[3] + dn[4] + 2) >> 2;
	up += tWidth;
	cP += cWidth;
	dn += tWidth;

	cP[0] = (up[0] + up[1] + dn[0] + dn[1] + 2) >> 2;
	cP[1] = (up[1] + up[2] + dn[1] + dn[2] + 2) >> 2;
	cP[2] = (up[2] + up[3] + dn[2] + dn[3] + 2) >> 2;
	cP[3] = (up[3] + up[4] + dn[3] + dn[4] + 2) >> 2;
	up += tWidth;
	cP += cWidth;
	dn += tWidth;

	cP[0] = (up[0] + up[1] + dn[0] + dn[1] + 2) >> 2;
	cP[1] = (up[1] + up[2] + dn[1] + dn[2] + 2) >> 2;
	cP[2] = (up[2] + up[3] + dn[2] + dn[3] + 2) >> 2;
	cP[3] = (up[3] + up[4] + dn[3] + dn[4] + 2) >> 2;
	up += tWidth;
	cP += cWidth;
	dn += tWidth;
}

static void _MotionComp(u8* cP, int cWidth, u8* tP, int tWidth, int selector)
{
	static MotionCompFunc func[] = { _MotionComp_00, _MotionComp_01, _MotionComp_10, _MotionComp_11 };
	func[selector](cP, cWidth, tP, tWidth);
}

/*
 * --INFO--
 * Address:	80021078
 * Size:	000A00
 *
 * @note hpel = half-pixel offset. DX = horizontal, DY = vertical.
 */

static void MotionComp(VideoState* state, MCHandler* mch, int tx, int ty)
{
	int c, i;
	MCPlane* pmc;
	HVQPlaneDesc* sip;
	u8* t_top;
	u32* iofsP;
	int blocks;
	u8* cP;
	u8* tP;
	int offset;

	if (!(tx & 1)) {
		if (!(ty & 1)) {
			for (c = 0; c < HVQM_PLANE_COUNT; c++) {
				pmc    = &mch->pln[c];
				t_top  = pmc->targ + ((tx >> state->pln[c].h_shift + 1) + (ty >> state->pln[c].v_shift + 1) * state->pln[c].plane_width);
				iofsP  = state->pln[c].imgUscan;
				blocks = state->pln[c].nblocks_mcb;
				for (i = 0; i < blocks; i++) {
					offset = *iofsP++;
					cP     = pmc->blk_top + offset;
					tP     = t_top + offset;
					_MotionComp_00(cP, state->pln[c].plane_width, tP, state->pln[c].plane_width);
				}
			}
		} else {
			for (c = 0; c < HVQM_PLANE_COUNT; c++) {
				pmc    = &mch->pln[c];
				t_top  = pmc->targ + ((tx >> state->pln[c].h_shift + 1) + (ty >> state->pln[c].v_shift + 1) * state->pln[c].plane_width);
				iofsP  = state->pln[c].imgUscan;
				blocks = state->pln[c].nblocks_mcb;
				for (i = 0; i < blocks; i++) {
					offset = *iofsP++;
					cP     = pmc->blk_top + offset;
					tP     = t_top + offset;
					_MotionComp_01(cP, state->pln[c].plane_width, tP, state->pln[c].plane_width);
				}
			}
		}
	} else {
		if (!(ty & 1)) {
			for (c = 0; c < HVQM_PLANE_COUNT; c++) {
				pmc    = &mch->pln[c];
				t_top  = pmc->targ + ((tx >> state->pln[c].h_shift + 1) + (ty >> state->pln[c].v_shift + 1) * state->pln[c].plane_width);
				iofsP  = state->pln[c].imgUscan;
				blocks = state->pln[c].nblocks_mcb;
				for (i = 0; i < blocks; i++) {
					offset = *iofsP++;
					cP     = pmc->blk_top + offset;
					tP     = t_top + offset;
					_MotionComp_10(cP, state->pln[c].plane_width, tP, state->pln[c].plane_width);
				}
			}
		} else {
			for (c = 0; c < HVQM_PLANE_COUNT; c++) {
				pmc    = &mch->pln[c];
				t_top  = pmc->targ + ((tx >> state->pln[c].h_shift + 1) + (ty >> state->pln[c].v_shift + 1) * state->pln[c].plane_width);
				iofsP  = state->pln[c].imgUscan;
				blocks = state->pln[c].nblocks_mcb;
				for (i = 0; i < blocks; i++) {
					offset = *iofsP++;
					cP     = pmc->blk_top + offset;
					tP     = t_top + offset;
					_MotionComp_11(cP, state->pln[c].plane_width, tP, state->pln[c].plane_width);
				}
			}
		}
	}
}

static void decode_PB_dc(VideoState* ws, MCHandler* mch)
{
	int c, i, j;
	int blocks;
	MCPlane* pmc;
	u16* bofsP;

	for (c = 0; c < PLANE_COUNT; c++) {
		pmc    = &mch->pln[c];
		bofsP  = ws->pln[c].bibUscan;
		blocks = ws->pln[c].nblocks_mcb;
		for (i = 0; i < blocks; i++) {
			j                = *bofsP++;
			pmc->data[j].dcv = pmc->prev_dcv = pmc->prev_dcv + decodeSOvfSym(&ws->dcval[c], ws->dc_min, ws->dc_max);
		}
	}
}

static void reset_PB_dc(VideoState* ws, MCHandler* mch)
{
	int i;
	MCPlane* pmc;

	for (i = 0; i < PLANE_COUNT; i++) {
		pmc           = &mch->pln[i];
		pmc->prev_dcv = 0x7F;
	}
}

/*
 * --INFO--
 * Address:	80021A78
 * Size:	00041C
 */
static void decode_PB_cc(VideoState* ws, MCHandler* mc, int proctype, int mcbtype)
{
	u8 cc;
	BlockData* dataP;
	BlockData* ydat;
	BlockData* udat;
	BlockData* vdat;
	HVQPlaneDesc* sip;
	u16* bofsP;
	int p, i, j;
	int blocks;
	BitBufferWithTree* symcode;
	BitBufferWithTree* runcode;
	s16 sym;

	cc = (mcbtype << 5) | (proctype << 4);
	if (proctype == 1) {
		for (p = 0; p < PLANE_COUNT; p++) {
			dataP  = mc->pln[p].data;
			bofsP  = ws->pln[p].bibUscan;
			blocks = ws->pln[p].nblocks_mcb;
			for (i = 0; i < blocks; i++) {
				dataP[*bofsP++].bnm = cc;
			}
		}
	} else {
		// luma
		ydat    = mc->pln[0].data;
		sip     = &ws->pln[LUMA_IDX];
		symcode = &ws->bsnum[LUMA_IDX];
		runcode = &ws->bsrun[LUMA_IDX];
		bofsP   = sip->bibUscan;
		blocks  = sip->nblocks_mcb;
		for (i = 0; i < blocks; i++) {
			j = *bofsP++;
			if (mc->pln[0].bsrunleng == 0) {
				sym = decodeHuff(symcode);
				if (sym == 0) {
					ydat[j].bnm          = cc;
					mc->pln[0].bsrunleng = decodeHuff(runcode);
				} else {
					ydat[j].bnm = cc | sym;
				}
			} else {
				ydat[j].bnm = cc;
				mc->pln[0].bsrunleng--;
			}
		}
		// chroma
		udat    = mc->pln[1].data;
		vdat    = mc->pln[2].data;
		sip     = &ws->pln[CHROMA_IDX];
		symcode = &ws->bsnum[CHROMA_IDX];
		runcode = &ws->bsrun[CHROMA_IDX];
		bofsP   = sip->bibUscan;
		blocks  = sip->nblocks_mcb;
		for (i = 0; i < blocks; i++) {
			j = *bofsP++;
			if (mc->pln[1].bsrunleng == 0) {
				sym = decodeHuff(symcode);
				if (sym == 0) {
					udat[j].bnm          = cc;
					vdat[j].bnm          = cc;
					mc->pln[1].bsrunleng = decodeHuff(runcode);
				} else {
					udat[j].bnm = cc | ((sym >> 0) & 0xF);
					vdat[j].bnm = cc | ((sym >> 4) & 0xF);
				}
			} else {
				udat[j].bnm = cc;
				vdat[j].bnm = cc;
				mc->pln[1].bsrunleng--;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80021E94
 * Size:	00086C
 */
static void PrediAotBlock(VideoState* ws, u8* blk, u8* mblk, int blkWidth, u8 nbasis, u8* nestPtr, int nestWidth, int p, int selector)
{
	s32 sum[16];
	u8 mvc[16];
	int mov[16];
	s32 avr;
	s32 scl;
	s32 dcv;
	s32 value;
	s32 mean;
	int max, min;
	int i, j;
	int mns;

	avr = GetMCAotSum(ws, sum, nbasis - 1, nestPtr, nestWidth, p);
	_MotionComp(mvc, 4, mblk, blkWidth, selector);

	mean = (mvc[0] + mvc[1] + mvc[2] + mvc[3] + mvc[4] + mvc[5] + mvc[6] + mvc[7] + mvc[8] + mvc[9] + mvc[10] + mvc[11] + mvc[12] + mvc[13]
	        + mvc[14] + mvc[15] + 8)
	    >> 4;

	max = min = mvc[0] - mean;
	mov[0]    = min;

	value  = mvc[1] - mean;
	mov[1] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value  = mvc[2] - mean;
	mov[2] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value  = mvc[3] - mean;
	mov[3] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value  = mvc[4] - mean;
	mov[4] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value  = mvc[5] - mean;
	mov[5] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value  = mvc[6] - mean;
	mov[6] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value  = mvc[7] - mean;
	mov[7] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value  = mvc[8] - mean;
	mov[8] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value  = mvc[9] - mean;
	mov[9] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value   = mvc[10] - mean;
	mov[10] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value   = mvc[11] - mean;
	mov[11] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value   = mvc[12] - mean;
	mov[12] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value   = mvc[13] - mean;
	mov[13] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value   = mvc[14] - mean;
	mov[14] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	value   = mvc[15] - mean;
	mov[15] = value;
	if (value < min) {
		min = value;
	} else if (value > max) {
		max = value;
	}

	mns = ws->aotscale_q;
	avr = (decodeSOvfSym(&ws->dcval[p], ws->dc_min, ws->dc_max) >> ws->dc_scale_q << mns) - avr;
	scl = (decodeSOvfSym(&ws->dcval[p], ws->dc_min, ws->dc_max) >> ws->dc_scale_q) * mcdivTable[max - min];

	// This loop is probably not manually unrolled, but it helps fake-match the stack size
	for (i = 0; i < 16; i += 8) {
		sum[i + 0] += avr + mov[i + 0] * scl;
		sum[i + 1] += avr + mov[i + 1] * scl;
		sum[i + 2] += avr + mov[i + 2] * scl;
		sum[i + 3] += avr + mov[i + 3] * scl;
		sum[i + 4] += avr + mov[i + 4] * scl;
		sum[i + 5] += avr + mov[i + 5] * scl;
		sum[i + 6] += avr + mov[i + 6] * scl;
		sum[i + 7] += avr + mov[i + 7] * scl;
	}

	j = 0;
	for (i = 0; i < 4; i++) {
		blk[0] = clipTable[mvc[j] + (sum[j] >> mns) + 0x80];
		j++;
		blk[1] = clipTable[mvc[j] + (sum[j] >> mns) + 0x80];
		j++;
		blk[2] = clipTable[mvc[j] + (sum[j] >> mns) + 0x80];
		j++;
		blk[3] = clipTable[mvc[j] + (sum[j] >> mns) + 0x80];
		j++;
		blk += blkWidth;
	}
}

/*
 * --INFO--
 * Address:	80022BC4
 * Size:	000164
 */
static void MCBlockDecMCNest(VideoState* ws, MCHandler* mch, int tx, int ty)
{
	int c, i;
	u8* nestP = mch->pln[0].targ + ((tx >> 1) - 32) + ((ty >> 1) - 16) * ws->pln[0].plane_width;
	for (c = 0; c < PLANE_COUNT; c++) {
		MCPlane* pmc      = &mch->pln[c];
		HVQPlaneDesc* sip = &ws->pln[c];
		int plane_dx      = (tx >> sip->h_shift + 1);
		int plane_dy      = (ty >> sip->v_shift + 1);
		u8* t_top         = pmc->targ + (plane_dx + plane_dy * sip->plane_width);
		u16* bofsP        = sip->bibUscan;
		u32* iofsP        = sip->imgUscan;
		int blocks        = sip->nblocks_mcb;
		for (i = 0; i < blocks; i++) {
			int offset = *iofsP++;
			int j      = *bofsP++;
			u8 nbasis  = pmc->data[j].bnm & 0xF;
			// cP is a 4x4 region
			u8* cP = pmc->blk_top + offset;
			!nbasis;
			if (nbasis == 6) {
				OrgBlock(ws, cP, sip->plane_width, c);
			} else {
				u8* tP = t_top + offset;
				if (nbasis == 0) {
					_MotionComp(cP, sip->plane_width, tP, sip->plane_width, (tx & 1) << 1 | (ty & 1));
				} else {
					PrediAotBlock(ws, cP, tP, sip->plane_width, nbasis, nestP, ws->pln[0].plane_width, c, (tx & 1) << 1 | (ty & 1));
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80022D28
 * Size:	000158
 */
static void MCBlockDecDCNest(VideoState* ws, MCHandler* mch)
{
	int c;
	for (c = 0; c < PLANE_COUNT; c++) {
		MCPlane* pmc     = &mch->pln[c];
		BlockData* dataP = pmc->data;
		int plane_width  = ws->pln[c].plane_width;
		int w            = ws->pln[c].nblocks_hb;
		u16* bofsP       = ws->pln[c].bibUscan;
		u32* iofsP       = ws->pln[c].imgUscan;
		int blocks       = ws->pln[c].nblocks_mcb;
		int i;
		for (i = 0; i < blocks; i++) {
			// dst is a 4x4 region
			int bofs = *bofsP++;
			u8* cP   = pmc->blk_top + *iofsP++;
			u8 dc    = dataP[bofs].dcv;
			// block type:
			// 0: weighted
			// 6: literal block
			// 8: single value
			u8 nbasis = dataP[bofs].bnm & 0xF;
			int j;
			// see also IpicBlockDec
			if (nbasis == 0) {
				u8 u_dc = dataP[bofs - w].bnm & 0x77 ? dc : dataP[bofs - w].dcv;
				u8 l_dc = dataP[bofs - 1].bnm & 0x77 ? dc : dataP[bofs - 1].dcv;
				u8 r_dc = dataP[bofs + 1].bnm & 0x77 ? dc : dataP[bofs + 1].dcv;
				u8 d_dc = dataP[bofs + w].bnm & 0x77 ? dc : dataP[bofs + w].dcv;
				WeightImBlock(cP, plane_width, dc, u_dc, d_dc, l_dc, r_dc);
			} else {
				IntraAotBlock(ws, cP, plane_width, dc, nbasis, c);
			}
		}
	}
}

static void getMVector(int* vec, BitBufferWithTree* code, int fcode)
{
	int range;
	int v;
	int i;

	range = 1 << (fcode + 5);
	// quantized value
	v = decodeHuff(code) << fcode;
	// residual bits
	for (i = fcode - 1; i >= 0; i--) {
		v += getBit(&code->buf) << i;
	}
	*vec += v;
	// signed wrap to -range .. range-1
	if (*vec >= range) {
		*vec -= range << 1;
	} else if (*vec < -range) {
		*vec += range << 1;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
static void initMCBproc(BitBufferWithTree* code, RLDecoder* flag)
{
	if (code->buf.ptr) {
		flag->status = getBit(&code->buf);
		flag->runlng = decodeUOvfSym(code, 0xFF);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
static int getMCBproc(BitBufferWithTree* code, RLDecoder* flag)
{
	if (flag->runlng == 0) {
		flag->status ^= 1;
		flag->runlng = decodeUOvfSym(code, 0xFF);
	}
	flag->runlng--;
	return flag->status;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
static void initMCBtype(BitBufferWithTree* code, RLDecoder* flag)
{
	int value;
	if (code->buf.ptr) {
		flag->status = getBit(&code->buf) << 1;
		flag->status |= getBit(&code->buf);
		flag->runlng = decodeUOvfSym(code, 0xFF);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
static int getMCBtype(BitBufferWithTree* code, RLDecoder* flag)
{
	const static u32 mcbtypetrans[2][3] = {
		{ 1, 2, 0 },
		{ 2, 0, 1 },
	};

	if (flag->runlng == 0) {
		// only three possible values, so when the value changes,
		// a single bit decides which other value to select
		// bit == 0 -> increment
		// bit == 1 -> decrement
		// then wrap to range 0..2
		flag->status = mcbtypetrans[getBit(&code->buf)][flag->status];
		flag->runlng = decodeUOvfSym(code, 0xFF);
	}
	flag->runlng--;
	return flag->status;
}

/*
 * --INFO--
 * Address:	80022E80
 * Size:	000430
 */
static void spread_PB_descMap(SeqObj* obj, MCHandler* mch)
{
	VideoState* ws = (VideoState*)obj->ws;
	struct RLDecoder proc;
	struct RLDecoder type;
	int i, j;

	initMCBproc(&ws->mcaot, &proc);
	initMCBtype(&ws->mstat, &type);
	for (j = 0; j < obj->frame_height; j += 8) {
		setMCTop(mch);
		for (i = 0; i < obj->frame_width; i += 8) {
			getMCBtype(&ws->mstat, &type);
			if (type.status == 0) {
				decode_PB_dc(ws, mch);
				decode_PB_cc(ws, mch, 0, type.status);
			} else {
				reset_PB_dc(ws, mch);
				decode_PB_cc(ws, mch, getMCBproc(&ws->mcaot, &proc), type.status);
			}
			setMCNextBlk(mch);
		}
		setMCDownBlk(mch);
	}
}

/*
 * --INFO--
 * Address:	800232B0
 * Size:	00043C
 */
static void BpicPlaneDec(SeqObj* seqObj, u8* lin_top, u8* forw, u8* back)
{
	VideoState* ws;
	MCHandler mch;
	int vx, vy;
	int dir;
	int i, j;
	u8 cc;
	u8 mtype;
	int d;

	ws = (VideoState*)seqObj->ws;
	initMCHandler(ws, &mch, lin_top, forw, back);
	spread_PB_descMap(seqObj, &mch);
	resetMCHandler(ws, &mch, lin_top);
	dir = -1;
	// MC blocks are 8x8 pixels
	for (j = 0; j < seqObj->frame_height; j += 8) {
		setMCTop(&mch);
		for (i = 0; i < seqObj->frame_width; i += 8) {
			cc = mch.pln[0].data->bnm;
			// 0: intra
			// 1: inter - past
			// 2: inter - future
			// see getMCBtype()
			d = (cc >> 5) & 3;
			if (d == 0) {
				// intra
				MCBlockDecDCNest(ws, &mch);
			} else {
				// check if we need to update the reference frame pointers
				if (--d != dir) {
					dir = d;
					setMCTarget(&mch, dir);
					vx = vy = 0;
				}
				getMVector(&vx, &ws->mvecx, ws->fcode[0][dir]);
				getMVector(&vy, &ws->mvecy, ws->fcode[1][dir]);

				// compute half-pixel position of reference macroblock
				// see getMCBproc()
				mtype = (cc >> 4) & 1;
				if (mtype == 0)
					MCBlockDecMCNest(ws, &mch, (i << 1) + vx, (j << 1) + vy);
				else
					MotionComp(ws, &mch, (i << 1) + vx, (j << 1) + vy);
			}
			setMCNextBlk(&mch);
		}
		setMCDownBlk(&mch);
	}
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

	for (i = 0; i < PLANE_COUNT; i++) {
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
