#ifndef _HVQM4_H
#define _HVQM4_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// HVQM4 DECODER FUNCTIONS AND STRUCTS (C) ////////////
// Names from Tilka/hvqm4 (presumably from Disney PK debug originally) and Bakuten Shoot Beyblade 2002.
// Versioning is a bit weird, so take with a grain of salt. Should be close to correct though.

#define HVQM_PLANE_COUNT 3 // apparently
#define HVQM_LUMA_CHROMA 2 // apparently

// Structs.

/**
 * @brief TODO
 *
 * @note Size: 0xA.
 */
typedef struct SeqObj {
	void* ws;         // _00
	u16 frame_width;  // _04
	u16 frame_height; // _06
	u8 h_samp;        // _08
	u8 v_samp;        // _09
} SeqObj;

/**
 * @brief TODO
 *
 * @note Size: 0x7.
 */
typedef struct VideoInfo {
	u16 width;          // _00
	u16 height;         // _02
	u8 h_sampling_rate; // _04
	u8 v_sampling_rate; // _05
	u8 pad[2];          // _06
} VideoInfo;

// Private structs? Maybe move these to a priv header/the .c file itself

/**
 * @brief TODO
 *
 * @note Size: 0x2.
 * @note Originaln name: _tagHVQData
 */
typedef struct BlockData {
	u8 dcv; // _00, DC value
	u8 bnm; // _01, block number
} BlockData;

/**
 * @brief TODO
 *
 * @note Size: 0x1008.
 */
typedef struct Tree {
	int node_number;    // _00
	int tree_root;      // _04
	int leaf[2][0x200]; // _08
} Tree;

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
typedef struct BitBuffer {
	u8* ptr;   // _00
	u32 size;  // _04
	u32 value; // _08
	int bit;   // _0C
} BitBuffer;

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
typedef struct BitBufferWithTree {
	BitBuffer buf; // _00
	Tree* tree;    // _10
} BitBufferWithTree;

/**
 * @brief TODO
 *
 * @note Size: 0x38.
 */
typedef struct HVQPlaneDesc {
	BlockData* blockInfoBuf; // _00, beginning of plane incl. border
	BlockData* blockInfoTop; // _04, beginning of non-border plane data
	u16 nblocks_h;           // _08, not including border
	u16 nblocks_v;           // _0A, not including border
	u16 nblocks_hb;          // _0C, including border
	u16 nblocks_vb;          // _0E, including border
	u16 bibUscan[4];         // _10
	u32 imgUscan[4];         // _18
	u16 plane_width;         // _28, in samples
	u16 plane_height;        // _2A, in samples
	u32 plane_size;          // _2C, in samples
	u8 h_shift;              // _30
	u8 v_shift;              // _31
	u8 hvqblk_h;             // _32
	u8 hvqblk_v;             // _33
	u8 nblocks_mcb;          // _34
} HVQPlaneDesc;

/**
 * @brief TODO
 *
 * @note Size: 0x15.
 */
typedef struct StackState {
	int id;               // _00, plane index
	const BlockData* upp; // _04, previous line
	const BlockData* mid; // _08, current line
	const BlockData* low; // _0C, next line
	BlockData right;      // _10
	BlockData curr;       // _12
	u8 l_dcv;             // _14
} StackState;

/**
 * @brief TODO
 *
 * @note Size: 0x3CD0.
 */
typedef struct VideoState {
	HVQPlaneDesc pln[HVQM_PLANE_COUNT];        // _0000
	Tree dcv_tree;                             // _00A8
	Tree zrn_tree;                             // _10B0
	Tree scl_tree;                             // _20B8
	Tree num_tree;                             // _30C0
	Tree vec_tree;                             // _40C8
	Tree mrn_tree;                             // _50D0
	BitBufferWithTree dcval[HVQM_PLANE_COUNT]; // _60D8, DC values
	BitBufferWithTree dcrun[HVQM_PLANE_COUNT]; // _6114, DC run lengths
	BitBufferWithTree scale[HVQM_PLANE_COUNT]; // _6150
	BitBufferWithTree bsnum[HVQM_LUMA_CHROMA]; // _618C
	BitBufferWithTree bsrun[HVQM_LUMA_CHROMA]; // _61B4
	BitBuffer aotcd[HVQM_PLANE_COUNT];         // _61DC, uncompressed high-entropy data
	BitBufferWithTree mvecx;                   // _620C, horizontal motion vectors
	BitBufferWithTree mvecy;                   // _6220, vertical motion vectors
	BitBufferWithTree mcaot;                   // _6234, macroblock proc
	BitBufferWithTree mstat;                   // _6248, macroblock type
	u16 nestsize_h;                            // _625C
	u16 nestsize_v;                            // _625E
	u8 landscape;                              // _6260
	u8 nestBuf[70 * 38];                       // _6261
	int dc_max;                                // _6CC8
	int dc_min;                                // _6CCC
	u8 aotscale_q;                             // _6CD0
	u8 dc_scale_q;                             // _6CD1
	u8 fcode[2][2];                            // _6CD2, num res bits to read from mvecx/mvecy, past/future
} VideoState;

/**
 * @brief TODO
 *
 * @note Size: 0x34.
 * @note Original name: _tagPlnMCHandler
 */
typedef struct MCPlane {
	int bsrunleng;       // _00
	int prev_dcv;        // _04
	BlockData* data;     // _08
	BlockData* data_top; // _0C
	u8* lin_top;         // _10
	u8* blk_top;         // _14
	u8* targ;            // _18
	u8* forw;            // _1C
	u8* back;            // _20
	u16 next_macro_pix;  // _24
	u32 down_macro_pix;  // _28
	int hvqblk_h;        // _2C
	int hvqblk_v;        // _30
} MCPlane;

/**
 * @brief TODO
 *
 * @note Size: 0x9C.
 * @note Original name: _tagMCHander
 */
typedef struct MCHandler {
	MCPlane pln[HVQM_PLANE_COUNT]; // _00
} MCHandler;

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
typedef struct RLDecoder {
	u32 value; // _00
	u32 count; // _04
} RLDecoder;

void HVQM4InitDecoder();
void HVQM4InitSeqObj(SeqObj* obj, VideoInfo* header);
u32 HVQM4BuffSize(SeqObj* obj);
void HVQM4SetBuffer(SeqObj* obj, void* buf);
void HVQM4DecodeIpic(SeqObj* obj, void* code, void* outbuf);
void HVQM4DecodePpic(SeqObj* obj, void* code, void* outbuf, void* ref1);
void HVQM4DecodeBpic(SeqObj* obj, void* code, void* outbuf, void* ref2, void* ref1);

/////////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
