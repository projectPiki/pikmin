#ifndef _HVQM4_H
#define _HVQM4_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// HVQM4 DECODER FUNCTIONS AND STRUCTS (C) ////////////
// Names from Tilka/hvqm4, presumably from Disney PK debug originally.
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
	struct VideoState* state; // _00
	u16 width;                // _04
	u16 height;               // _06
	u8 h_samp;                // _08
	u8 v_samp;                // _09
} SeqObj;

/**
 * @brief TODO
 *
 * @note Size: 0x7.
 */
typedef struct VideoInfo {
	u16 hres;      // _00
	u16 vres;      // _02
	u8 h_samp;     // _04
	u8 v_samp;     // _05
	u8 video_mode; // _06
} VideoInfo;

// Private structs? Maybe move these to a priv header/the .c file itself

/**
 * @brief TODO
 *
 * @note Size: 0x2.
 */
typedef struct BlockData {
	u8 value; // _00
	u8 type;  // _01
} BlockData;

/**
 * @brief TODO
 *
 * @note Size: 0x1008.
 */
typedef struct Tree {
	u32 pos;             // _00
	int root;            // _04
	u32 array[2][0x200]; // _08
} Tree;

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
typedef struct BitBuffer {
	const void* ptr; // _00
	u32 size;        // _04
	u32 value;       // _08
	int bit;         // _0C
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
	BlockData* border;     // _00, beginning of plane incl. border
	BlockData* payload;    // _04, beginning of non-border plane data
	u16 h_blocks;          // _08
	u16 v_blocks;          // _0A
	u16 h_blocks_safe;     // _0C
	u16 v_blocks_safe;     // _0E
	u16 mcb_offset[4];     // _10
	u32 pb_offset[4];      // _18
	u16 width_in_samples;  // _28
	u16 height_in_samples; // _2A
	u32 size_in_samples;   // _2C
	u8 width_shift;        // _30
	u8 height_shift;       // _31
	u8 pb_per_mcb_x;       // _32
	u8 pb_per_mcb_y;       // _33
	u8 blocks_per_mcb;     // _34
	u8 padding[3];         // _35
} HVQPlaneDesc;

/**
 * @brief TODO
 *
 * @note Size: 0x15.
 */
typedef struct StackState {
	u32 plane_idx;              // _00
	const BlockData* line_prev; // _04
	const BlockData* line_curr; // _08
	const BlockData* line_next; // _0C
	BlockData next;             // _10
	BlockData curr;             // _12
	u8 value_prev;              // _14
} StackState;

/**
 * @brief TODO
 *
 * @note Size: 0x3CD0.
 */
typedef struct VideoState {
	HVQPlaneDesc planes[HVQM_PLANE_COUNT];             // _00
	Tree trees[6];                                     // _A8
	BitBufferWithTree dc_values[HVQM_PLANE_COUNT];     // _60D8, DC values
	BitBufferWithTree dc_rle[HVQM_PLANE_COUNT];        // _6114, DC run lengths
	BitBufferWithTree bufTree0[HVQM_PLANE_COUNT];      // _6150
	BitBufferWithTree basis_num[HVQM_LUMA_CHROMA];     // _618C
	BitBufferWithTree basis_num_run[HVQM_LUMA_CHROMA]; // _61B4
	BitBuffer fixvl[HVQM_PLANE_COUNT];                 // _61DC, uncompressed high-entropy data
	BitBufferWithTree mv_h;                            // _620C, horizontal motion vectors
	BitBufferWithTree mv_v;                            // _6220, vertical motion vectors
	BitBufferWithTree mcb_proc;                        // _6234, macroblock proc
	BitBufferWithTree mcb_type;                        // _6248, macroblock type
	u16 h_nest_size;                                   // _625C
	u16 v_nest_size;                                   // _625E
	u8 is_landscape;                                   // _6260
	u8 nest_data[70 * 38];                             // _6261
	u16 dc_max;                                        // _6CC6
	u16 dc_min;                                        // _6CC8
	u8 unk_shift;                                      // _6CCA
	u8 dc_shift;                                       // _6CCB
	u8 mc_residual_bits_h[2];                          // _6CCC, num res bits to read from mv_h, past + future
	u8 mc_residual_bits_v[2];                          // _6CCE, num res bits to read from mv_v, past + future
} VideoState;

/**
 * @brief TODO
 *
 * @note Size: 0x34.
 */
typedef struct MCPlane {
	u32 rle;                    // _00
	u32 pb_dc;                  // _04
	BlockData* payload_cur_blk; // _08
	BlockData* payload_cur_row; // _0C
	void* present;              // _10
	void* top;                  // _14
	void* target;               // _18
	void* past;                 // _1C
	void* future;               // _20
	u16 h_mcb_stride;           // _24
	u32 v_mcb_stride;           // _28
	u32 pb_per_mcb_x;           // _2C
	u32 stride;                 // _30
} MCPlane;

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
typedef struct RLDecoder {
	u32 value; // _00
	u32 count; // _04
} RLDecoder;

// Global functions.
void HVQM4InitDecoder();
void HVQM4InitSeqObj(SeqObj* seqObj, VideoInfo* videoInfo);
u32 HVQM4BuffSize(SeqObj* seqObj);
void HVQM4SetBuffer(SeqObj* seqObj, void* workBuffer);
void HVQM4DecodeIpic(SeqObj* seqObj, u8 const* frame, void* present);
void HVQM4DecodePpic(SeqObj* seqObj, u8 const* frame, void* present, void* past);
void HVQM4DecodeBpic(SeqObj* seqObj, u8 const* frame, void* present, void* past, void* future);

/////////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
