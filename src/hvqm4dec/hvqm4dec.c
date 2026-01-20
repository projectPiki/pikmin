#include "hvqm4.h"
#include <stddef.h>

/*
 * Initial code attempts + comments + function arguments/naming guides taken from
 * Bakuten Shoot Beyblade 2002 and http://github.com/Tilka/hvqm4
 * with very many thanks from all of the projectPiki decompilation team.
 */

typedef void (*MotionCompFunc)(u8* cP, int cWidth, u8* tP, int tWidth);

static u8 clipTable[0x200];
static int divTable[0x10];
static int mcdivTable[0x200];

static int readTree_signed;
static u32 readTree_scale;

// Color plane indices for YUV color space
#define Y_IDX 0
#define U_IDX 1
#define V_IDX 2

// Simplified indices for luma vs chroma operations
#define LUMA_IDX   0
#define CHROMA_IDX 1

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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000014
 */
static void set_border(_tagHVQData* p)
{
	p->dcv = 0x7F;
	p->bnm = 0xFF;
}

/**
 * @TODO: Documentation
 */
static void setHVQPlaneDesc(SeqObj* obj, int id, u8 h_samp, u8 v_samp)
{
	HVQPlaneDesc* p = &((VideoState*)obj->ws)->pln[id];
	p->h_shift      = (h_samp == 2) ? 1 : 0;
	p->plane_width  = obj->frame_width >> p->h_shift;
	p->v_shift      = (v_samp == 2) ? 1 : 0;
	p->plane_height = obj->frame_height >> p->v_shift;
	p->plane_size   = p->plane_width * p->plane_height;

	// pixels per 2x2 block
	p->hvqblk_h    = 2 >> p->h_shift;           // 1..2
	p->hvqblk_v    = 2 >> p->v_shift;           // 1..2
	p->nblocks_mcb = p->hvqblk_h * p->hvqblk_v; // 1..4

	// number of 4x4 blocks
	p->nblocks_h = obj->frame_width / (h_samp * 4);
	p->nblocks_v = obj->frame_height / (v_samp * 4);

	// number of 4x4 blocks + border
	p->nblocks_hb = p->nblocks_h + 2;
	p->nblocks_vb = p->nblocks_v + 2;

	// offset of blocks in MCB
	p->bibUscan[0] = 0;
	p->bibUscan[3] = 1;
	p->bibUscan[2] = (p->bibUscan[1] = p->nblocks_hb) + 1;

	p->imgUscan[0] = 0;
	p->imgUscan[3] = 4;
	p->imgUscan[2] = (p->imgUscan[1] = p->plane_width << 2) + 4;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
static void setCode(BitBuffer* const str, u8* top)
{
	u32 size = read32(top, 0);

	str->size = size;
	if (size == 0) {
		str->ptr = NULL;
	} else {
		str->ptr = top + 4;
	}

	str->shift = -1;
}

/**
 * @TODO: Documentation
 */
static inline int getBit(BitBuffer* str)
{
	u32 value;
	int bit;

	if ((bit = str->shift) < 0) {
		value = str->word = *((u32*)str->ptr)++;
		bit               = 31;
	} else {
		value = str->word;
	}

	value      = value >> bit & 1;
	str->shift = bit - 1;
	return value;
}

/**
 * @TODO: Documentation
 */
static inline s16 getByte(BitBuffer* str)
{
	u32 value;
	int bit;
	if ((bit = str->shift) >= 7) {
		value = str->word;
		value >>= bit - 7;
		bit -= 8;
	} else {
		value = str->word;
		value <<= 7 - bit;
		str->word = *((u32*)str->ptr)++;
		value |= str->word >> (bit + 25);
		bit += 24;
	}
	str->shift = bit;
	value &= 0xFF;
	return value;
}

/**
 * @TODO: Documentation
 */
static s16 _readTree(Tree* const dst, BitBuffer* const str)
{
	int _FAKE[2]; // Doesn't exist, but used to match stack alignment
	int node;
	s16 no;
	s16 val;

	if (getBit(str)) {
		// Branch node (0/1)
		node               = dst->node_number++;
		dst->leaf[0][node] = _readTree(dst, str);
		dst->leaf[1][node] = _readTree(dst, str);
		return node;
	} else {
		// Leaf node (0-255)
		no  = getByte(str);
		val = no;

		if (readTree_signed && no > 0x7F) {
			val -= 0x100;
		}

		val <<= readTree_scale;
		dst->leaf[0][no] = val;
		return no;
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000140
 */
static void readTree(BitBufferWithTree* const code, int is_signed, int scale)
{
	BitBuffer* str = &code->str;
	Tree* tree     = code->tree;

	readTree_signed   = is_signed;
	readTree_scale    = scale;
	tree->node_number = 0x100;
	if (str->size != 0) {
		tree->tree_root = _readTree(tree, str);
	} else {
		tree->tree_root = 0;
	}
}

/**
 * @TODO: Documentation
 */
static inline int decodeHuff(BitBufferWithTree* code)
{
	Tree* tree     = code->tree;
	BitBuffer* str = &code->str;
	int point      = tree->tree_root;

	while (point >= 0x100) {
		point = tree->leaf[getBit(str)][point];
	}

	return tree->leaf[0][point];
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000084
 */
static inline int decodeUOvfSym(BitBufferWithTree* code, int range_max)
{
	int ret = 0;
	int num;

	do {
		num = decodeHuff(code);
		ret += num;
	} while (num >= range_max);

	return ret;
}

/**
 * @TODO: Documentation
 */
static void Ipic_BasisNumDec(VideoState* ws)
{
	s16 label;
	int runln;
	_tagHVQData* ydat;
	_tagHVQData* udat;
	_tagHVQData* vdat;
	int i, j;
	int h_block, v_block;
	BitBufferWithTree* symcode;
	BitBufferWithTree* runcode;

	runln   = 0;
	ydat    = ws->pln[Y_IDX].blockInfoTop;
	symcode = &ws->bsnum[LUMA_IDX];
	runcode = &ws->bsrun[LUMA_IDX];
	h_block = ws->pln[LUMA_IDX].nblocks_h;
	v_block = ws->pln[LUMA_IDX].nblocks_v;

	for (j = v_block; j > 0; j--) {
		for (i = h_block; i > 0; i--) {
			if (runln == 0) {
				label = decodeHuff(symcode);
				if (label == 0)
					runln = decodeHuff(runcode);
				ydat++->bnm = label & 0xFF;
			} else {
				ydat++->bnm = 0;
				runln--;
			}
		}
		// skip borders
		ydat += 2;
	}

	runln   = 0;
	udat    = ws->pln[U_IDX].blockInfoTop;
	vdat    = ws->pln[V_IDX].blockInfoTop;
	symcode = &ws->bsnum[CHROMA_IDX];
	runcode = &ws->bsrun[CHROMA_IDX];
	h_block = ws->pln[CHROMA_IDX].nblocks_h;
	v_block = ws->pln[CHROMA_IDX].nblocks_v;
	for (i = v_block; i > 0; i--) {
		for (j = h_block; j > 0; j--) {
			if (runln == 0) {
				label = decodeHuff(symcode);
				if (label == 0)
					runln = decodeHuff(runcode);
				udat++->bnm = (label >> 0) & 0xF;
				vdat++->bnm = (label >> 4) & 0xF;
			} else {
				udat++->bnm = 0;
				vdat++->bnm = 0;
				runln--;
			}
		}

		udat += 2;
		vdat += 2;
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

/**
 * @TODO: Documentation
 */
static void IpicDcvDec(VideoState* ws)
{
	int c;
	_tagHVQData* curr;
	_tagHVQData* prev;
	int run;
	int pred;
	int h_block, v_block;
	int nblocks_hb;
	int i, j;

	for (c = 0; c < HVQM_PLANE_COUNT; c++) {
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

/**
 * @TODO: Documentation
 */
static void MakeNest(VideoState* ws, int x, int y)
{
	int h_block, nblocks_hb, v_block;
	_tagHVQData* src;
	int h_dc_orderly, v_dc_orderly;
	int h_dc_reverse, v_dc_reverse;
	int h_nest_blank, v_nest_blank;
	int i, j;
	u8* nestP;
	u8* backP;
	_tagHVQData* dP;
	u8* nP;

	h_block    = ws->pln[Y_IDX].nblocks_h;
	nblocks_hb = ws->pln[Y_IDX].nblocks_hb;
	v_block    = ws->pln[Y_IDX].nblocks_v;
	src        = ws->pln[Y_IDX].blockInfoTop + (y * nblocks_hb + x);

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

/**
 * @TODO: Documentation
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
	int u_d = u - d;
	int l_r = l - r;

	int v1 = u_d + l_r;
	int v2 = u_d - l_r;

	int c2 = c * 2;
	int c3 = c * 8 + 4;

	int t1 = u + l - c2;
	int t2 = u + r - c2;
	int t3 = d + r - c2;
	int t4 = l + d - c2;

	int t5 = u - l;
	int t6 = u - r;
	int t7 = d - r;
	int t8 = d - l;

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

	block[0] = clipTable[(c3 + v1 + t1 >> 3) + 0x80];
	block[1] = clipTable[(c3 + v1 + t5 >> 3) + 0x80];
	block[2] = clipTable[(c3 + v2 + t6 >> 3) + 0x80];
	block[3] = clipTable[(c3 + v2 + t2 >> 3) + 0x80];
	block += blockWidth;

	// ( 8*V - B + 2*L -   R + 4) / 8
	// (10*V - B       -   R + 4) / 8
	// (10*V - B -   L       + 4) / 8
	// ( 8*V - B -   L + 2*R + 4) / 8

	block[0] = clipTable[(c3 + v1 - t5 >> 3) + 0x80];
	block[1] = clipTable[(c3 - t3 >> 3) + 0x80];
	block[2] = clipTable[(c3 - t4 >> 3) + 0x80];
	block[3] = clipTable[(c3 + v2 - t6 >> 3) + 0x80];
	block += blockWidth;

	// ( 8*V - T + 2*L - R + 4) / 8
	// (10*V - T       - R + 4) / 8
	// (10*V - T - L

	block[0] = clipTable[(c3 - v2 - t8 >> 3) + 0x80];
	block[1] = clipTable[(c3 - t2 >> 3) + 0x80];
	block[2] = clipTable[(c3 - t1 >> 3) + 0x80];
	block[3] = clipTable[(c3 - v1 - t7 >> 3) + 0x80];
	block += blockWidth;

	block[0] = clipTable[(c3 - v2 + t4 >> 3) + 0x80];
	block[1] = clipTable[(c3 - v2 + t8 >> 3) + 0x80];
	block[2] = clipTable[(c3 - v1 + t7 >> 3) + 0x80];
	block[3] = clipTable[(c3 - v1 + t3 >> 3) + 0x80];
	block += blockWidth;
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
static inline s32 GetAotBasis(VideoState* ws, u8 basisOut[16], s32* pscl, u8* nestTop, int nestWidth, int p)
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

/**
 * @TODO: Documentation
 */
static inline s32 GetMCAotBasis(VideoState* ws, u8 basisOut[16], s32* pscl, u8* nestTop, int nestWidth, int p)
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

static inline s32 GetAotSum(VideoState* ws, long sum[16], u8 nbasis, u8* nestTop, int nestWidth, int p)
{
	long prev_scl;
	long scl;
	u8 bas[16];

	sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = sum[6] = sum[7] = sum[8] = sum[9] = sum[10] = sum[11] = sum[12] = sum[13]
	    = sum[14] = sum[15] = prev_scl = 0;

	while (nbasis--) {
		scl = GetAotBasis(ws, bas, &prev_scl, nestTop, nestWidth, p);
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

static inline s32 GetMCAotSum(VideoState* ws, s32 sum[16], u8 nbasis, u8* nestTop, int nestWidth, int p)
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

/**
 * @note: AOT = Adaptive Orthogonal Transform, apparently
 */
static void IntraAotBlock(VideoState* ws, u8* blk, int blkWidth, u8 dcv, u8 nbasis, int p)
{
	long sum[16];
	int avr;
	long mns;

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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
static void initMCHandler(VideoState* ws, MCHandler* mch, u8* lin_top, u8* forw, u8* back)
{
	int i;
	MCPlane* mcplane;
	HVQPlaneDesc* plane;
	_tagHVQData* block;

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
static void resetMCHandler(VideoState* state, MCHandler* mch, u8* lin_top)
{
	int i;
	MCPlane* pmc;

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
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

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
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

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
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

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
		pmc = &mch->pln[i];
		pmc->lin_top += pmc->down_macro_pix;
		pmc->data = pmc->data_top = pmc->data_top + pmc->hvqblk_v;
	}
}

// select which frame to use as an MC reference
static void setMCTarget(MCHandler* mch, int direct)
{
	if (direct == 0) {
		mch->pln[Y_IDX].targ = mch->pln[Y_IDX].forw;
		mch->pln[U_IDX].targ = mch->pln[U_IDX].forw;
		mch->pln[V_IDX].targ = mch->pln[V_IDX].forw;
	} else {
		mch->pln[Y_IDX].targ = mch->pln[Y_IDX].back;
		mch->pln[U_IDX].targ = mch->pln[U_IDX].back;
		mch->pln[V_IDX].targ = mch->pln[V_IDX].back;
	}
}

/**
 * @note Copy 4x4 samples without interpolation.
 */
static inline void _MotionComp_00(u8* cP, int cWidth, u8* tP, int tWidth)
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

/**
 * @note Offset vertically by half a sample
 */
static inline void _MotionComp_01(u8* cP, int cWidth, u8* tP, int tWidth)
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

/**
 * @note Offset vertically by half a sample
 */
static inline void _MotionComp_10(u8* cP, int cWidth, u8* tP, int tWidth)
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

/**
 * @note Offset by half a sample in both directions
 */
static inline void _MotionComp_11(u8* cP, int cWidth, u8* tP, int tWidth)
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

/**
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

	for (c = 0; c < HVQM_PLANE_COUNT; c++) {
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

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
		pmc           = &mch->pln[i];
		pmc->prev_dcv = 0x7F;
	}
}

/**
 * @TODO: Documentation
 */
static void decode_PB_cc(VideoState* ws, MCHandler* mc, int proctype, int mcbtype)
{
	u8 cc;
	_tagHVQData* dataP;
	_tagHVQData* ydat;
	_tagHVQData* udat;
	_tagHVQData* vdat;
	HVQPlaneDesc* sip;
	u16* bofsP;
	int p, i, j;
	int blocks;
	BitBufferWithTree* symcode;
	BitBufferWithTree* runcode;
	s16 sym;

	cc = (mcbtype << 5) | (proctype << 4);
	if (proctype == 1) {
		for (p = 0; p < HVQM_PLANE_COUNT; p++) {
			dataP  = mc->pln[p].data;
			bofsP  = ws->pln[p].bibUscan;
			blocks = ws->pln[p].nblocks_mcb;
			for (i = 0; i < blocks; i++) {
				dataP[*bofsP++].bnm = cc;
			}
		}
	} else {
		// luma
		ydat    = mc->pln[Y_IDX].data;
		sip     = &ws->pln[LUMA_IDX];
		symcode = &ws->bsnum[LUMA_IDX];
		runcode = &ws->bsrun[LUMA_IDX];
		bofsP   = sip->bibUscan;
		blocks  = sip->nblocks_mcb;
		for (i = 0; i < blocks; i++) {
			j = *bofsP++;
			if (mc->pln[Y_IDX].bsrunleng == 0) {
				sym = decodeHuff(symcode);
				if (sym == 0) {
					ydat[j].bnm              = cc;
					mc->pln[Y_IDX].bsrunleng = decodeHuff(runcode);
				} else {
					ydat[j].bnm = cc | sym;
				}
			} else {
				ydat[j].bnm = cc;
				mc->pln[Y_IDX].bsrunleng--;
			}
		}
		// chroma
		udat    = mc->pln[U_IDX].data;
		vdat    = mc->pln[V_IDX].data;
		sip     = &ws->pln[CHROMA_IDX];
		symcode = &ws->bsnum[CHROMA_IDX];
		runcode = &ws->bsrun[CHROMA_IDX];
		bofsP   = sip->bibUscan;
		blocks  = sip->nblocks_mcb;
		for (i = 0; i < blocks; i++) {
			j = *bofsP++;
			if (mc->pln[U_IDX].bsrunleng == 0) {
				sym = decodeHuff(symcode);
				if (sym == 0) {
					udat[j].bnm              = cc;
					vdat[j].bnm              = cc;
					mc->pln[U_IDX].bsrunleng = decodeHuff(runcode);
				} else {
					udat[j].bnm = cc | ((sym >> 0) & 0xF);
					vdat[j].bnm = cc | ((sym >> 4) & 0xF);
				}
			} else {
				udat[j].bnm = cc;
				vdat[j].bnm = cc;
				mc->pln[U_IDX].bsrunleng--;
			}
		}
	}
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
static void MCBlockDecMCNest(VideoState* ws, MCHandler* mch, int tx, int ty)
{
	int c, i;
	u8* nestP = mch->pln[Y_IDX].targ + ((tx >> 1) - 32) + ((ty >> 1) - 16) * ws->pln[Y_IDX].plane_width;
	for (c = 0; c < HVQM_PLANE_COUNT; c++) {
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
					PrediAotBlock(ws, cP, tP, sip->plane_width, nbasis, nestP, ws->pln[Y_IDX].plane_width, c, (tx & 1) << 1 | (ty & 1));
				}
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
static void MCBlockDecDCNest(VideoState* ws, MCHandler* mch)
{
	int c;
	for (c = 0; c < HVQM_PLANE_COUNT; c++) {
		MCPlane* pmc       = &mch->pln[c];
		_tagHVQData* dataP = pmc->data;
		int plane_width    = ws->pln[c].plane_width;
		int w              = ws->pln[c].nblocks_hb;
		u16* bofsP         = ws->pln[c].bibUscan;
		u32* iofsP         = ws->pln[c].imgUscan;
		int blocks         = ws->pln[c].nblocks_mcb;
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
		v += getBit(&code->str) << i;
	}
	*vec += v;
	// signed wrap to -range .. range-1
	if (*vec >= range) {
		*vec -= range << 1;
	} else if (*vec < -range) {
		*vec += range << 1;
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000C8
 */
static void initMCBproc(BitBufferWithTree* code, RLDecoder* flag)
{
	if (code->str.ptr) {
		flag->status = getBit(&code->str);
		flag->runlng = decodeUOvfSym(code, 0xFF);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000A4
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000110
 */
static void initMCBtype(BitBufferWithTree* code, RLDecoder* flag)
{
	int value;
	if (code->str.ptr) {
		flag->status = getBit(&code->str) << 1;
		flag->status |= getBit(&code->str);
		flag->runlng = decodeUOvfSym(code, 0xFF);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F8
 */
static int getMCBtype(BitBufferWithTree* code, RLDecoder* flag)
{
	static const u32 mcbtypetrans[2][3] = {
		{ 1, 2, 0 },
		{ 2, 0, 1 },
	};

	if (flag->runlng == 0) {
		// only three possible values, so when the value changes,
		// a single bit decides which other value to select
		// bit == 0 -> increment
		// bit == 1 -> decrement
		// then wrap to range 0..2
		flag->status = mcbtypetrans[getBit(&code->str)][flag->status];
		flag->runlng = decodeUOvfSym(code, 0xFF);
	}
	flag->runlng--;
	return flag->status;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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
			cc = mch.pln[Y_IDX].data->bnm;
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

/**
 * @TODO: Documentation
 */
void HVQM4InitDecoder()
{
	init_global_constants();
}

/**
 * @TODO: Documentation
 */
void HVQM4InitSeqObj(SeqObj* obj, VideoInfo* header)
{
	obj->frame_width  = header->width;
	obj->frame_height = header->height;
	obj->h_samp       = header->h_sampling_rate;
	obj->v_samp       = header->v_sampling_rate;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void HVQM4SetBuffer(SeqObj* obj, void* buf)
{
	VideoState* ws;
	_tagHVQData* bp;
	int c, i;
	_tagHVQData* p;

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

	ws->bsnum[LUMA_IDX].tree = ws->bsnum[CHROMA_IDX].tree = &ws->num_tree;
	ws->bsrun[LUMA_IDX].tree = ws->bsrun[CHROMA_IDX].tree = &ws->zrn_tree;

	ws->dcval[Y_IDX].tree = ws->dcval[U_IDX].tree = ws->dcval[V_IDX].tree = &ws->dcv_tree;
	ws->dcrun[Y_IDX].tree = ws->dcrun[U_IDX].tree = ws->dcrun[V_IDX].tree = &ws->zrn_tree; // same as bsrun
	ws->scale[Y_IDX].tree = ws->scale[U_IDX].tree = ws->scale[V_IDX].tree = &ws->scl_tree;
	ws->mvecx.tree = ws->mvecy.tree = &ws->vec_tree;
	ws->mcaot.tree = ws->mstat.tree = &ws->mrn_tree;

	bp = (_tagHVQData*)((u8*)buf + sizeof(VideoState));
	for (c = 0; c < HVQM_PLANE_COUNT; c++) {
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

/**
 * @TODO: Documentation
 */
void HVQM4DecodeIpic(SeqObj* obj, void* code, void* outbuf)
{
	VideoState* ws;
	u8* body;
	int i;

	ws             = (VideoState*)obj->ws;
	ws->aotscale_q = read8(code, 1);
	body           = (u8*)code + 0x48;

	setCode(&ws->bsnum[LUMA_IDX].str, body + read32(code, 0x8));
	setCode(&ws->bsrun[LUMA_IDX].str, body + read32(code, 0xC));
	setCode(&ws->bsnum[CHROMA_IDX].str, body + read32(code, 0x10));
	setCode(&ws->bsrun[CHROMA_IDX].str, body + read32(code, 0x14));
	setCode(&ws->dcval[Y_IDX].str, body + read32(code, 0x18));
	setCode(&ws->scale[Y_IDX].str, body + read32(code, 0x1C));
	setCode(&ws->aotcd[Y_IDX], body + read32(code, 0x20));
	setCode(&ws->dcval[U_IDX].str, body + read32(code, 0x24));
	setCode(&ws->scale[U_IDX].str, body + read32(code, 0x28));
	setCode(&ws->aotcd[U_IDX], body + read32(code, 0x2C));
	setCode(&ws->dcval[V_IDX].str, body + read32(code, 0x30));
	setCode(&ws->scale[V_IDX].str, body + read32(code, 0x34));
	setCode(&ws->aotcd[V_IDX], body + read32(code, 0x38));
	setCode(&ws->dcrun[Y_IDX].str, body + read32(code, 0x3C));
	setCode(&ws->dcrun[U_IDX].str, body + read32(code, 0x40));
	setCode(&ws->dcrun[V_IDX].str, body + read32(code, 0x44));

	// multiple BitBufferWithTree instances share the same Tree,
	// the first BitBuffer of each group contains the Tree itself
	readTree(&ws->bsnum[LUMA_IDX], 0, 0);
	readTree(&ws->bsrun[LUMA_IDX], 0, 0);
	readTree(&ws->dcval[Y_IDX], 1, read8(code, 0));
	readTree(&ws->scale[Y_IDX], 0, 2);

	ws->dc_max = +0x7F << read8(code, 0);
	ws->dc_min = -0x80 << read8(code, 0);

	// 4x4 block types
	Ipic_BasisNumDec(ws);
	// 4x4 block DC values
	IpicDcvDec(ws);
	// 70x38 nest copied from upper 4 bits of DC values somewhere in the luma plane
	MakeNest(ws, read16(code, 4), read16(code, 6));

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
		IpicPlaneDec(ws, i, outbuf);
		outbuf = (u8*)outbuf + ws->pln[i].plane_size;
	}
}

/**
 * @TODO: Documentation
 */
void HVQM4DecodePpic(SeqObj* obj, void* code, void* outbuf, void* ref1)
{
	HVQM4DecodeBpic(obj, code, outbuf, ref1, outbuf);
}

/**
 * @TODO: Documentation
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

	setCode(&ws->bsnum[LUMA_IDX].str, body + read32(code, 0x08));
	setCode(&ws->bsrun[LUMA_IDX].str, body + read32(code, 0x0C));
	setCode(&ws->bsnum[CHROMA_IDX].str, body + read32(code, 0x10));
	setCode(&ws->bsrun[CHROMA_IDX].str, body + read32(code, 0x14));
	setCode(&ws->dcval[Y_IDX].str, body + read32(code, 0x18));
	setCode(&ws->scale[Y_IDX].str, body + read32(code, 0x1C));
	setCode(&ws->aotcd[Y_IDX], body + read32(code, 0x20));
	setCode(&ws->dcval[U_IDX].str, body + read32(code, 0x24));
	setCode(&ws->scale[U_IDX].str, body + read32(code, 0x28));
	setCode(&ws->aotcd[U_IDX], body + read32(code, 0x2C));
	setCode(&ws->dcval[V_IDX].str, body + read32(code, 0x30));
	setCode(&ws->scale[V_IDX].str, body + read32(code, 0x34));
	setCode(&ws->aotcd[V_IDX], body + read32(code, 0x38));
	setCode(&ws->mvecx.str, body + read32(code, 0x3C));
	setCode(&ws->mvecy.str, body + read32(code, 0x40));
	setCode(&ws->mstat.str, body + read32(code, 0x44));
	setCode(&ws->mcaot.str, body + read32(code, 0x48));

	readTree(&ws->bsnum[LUMA_IDX], 0, 0);
	readTree(&ws->bsrun[LUMA_IDX], 0, 0);
	readTree(&ws->dcval[Y_IDX], 1, read8(code, 0));
	readTree(&ws->scale[Y_IDX], 0, 2);
	readTree(&ws->mvecx, 1, 0);
	readTree(&ws->mstat, 0, 0);

	ws->dc_max = +0x7F << read8(code, 0);
	ws->dc_min = -0x80 << read8(code, 0);

	BpicPlaneDec(obj, outbuf, ref2, ref1);
}
