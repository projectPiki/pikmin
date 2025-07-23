#ifndef _HVQM4_H
#define _HVQM4_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

/*
 * Hybrid Vector Quantization Movie 4 (HVQM4) Video Decoder
 * An expired patent for it: https://patents.google.com/patent/US6714687B2/
 *
 * == Frame Structure ==
 * Video frames are divided into 4x4 pixel blocks, which are grouped into 8x8 macroblocks.
 * The codec supports three frame types:
 * - I-frames: Standalone frames using spatial compression only
 * - P-frames: Predicted from one previous frame
 * - B-frames: Predicted from both previous and future frames
 *
 * == Color Format ==
 * YUV color space with configurable chroma subsampling (4:4:4 or 4:2:0)
 * Each plane (Y/U/V) is processed independently with a 1-block border added.
 *
 * == Compression Methods ==
 * 1. DC Prediction: Each 4x4 block stores a DC (average) value, predicted from neighbors
 * 2. AOT (Adaptive Orthogonal Transform): Blocks encoded as weighted sums of basis patterns
 *    - Basis patterns sampled from a 70x38 "nest" (downsampled frame DC values)
 *    - Block types 1-5 use 1-5 basis patterns, type 6 is raw pixels
 * 3. Motion Compensation: P/B frames encode motion vectors at half-pixel precision
 *    - Macroblocks can be intra-coded or motion-compensated
 *    - Residuals after motion compensation use AOT
 *
 * == Bitstream Layout ==
 * Frame data contains:
 * - Header with offsets to data sections
 * - Huffman-coded trees for symbols
 * - Block type information (basis count per block)
 * - DC values (delta-coded with run-length encoding)
 * - AOT data (nest positions and scaling factors)
 * - Motion vectors (P/B frames only)
 *
 * == Key Data Structures ==
 * - SeqObj: Sequence parameters (dimensions, subsampling)
 * - VideoState: Decoder state and working buffers
 * - BlockData: Per-block metadata (DC value, basis count)
 * - BitBuffer: Bitstream reader with optional Huffman tree
 *
 * The decoder processes blocks in raster scan order, maintaining neighbor information for prediction.
 * Motion compensation uses bilinear interpolation for half-pixel positions.
 *
 * Initial code attempts + comments + function arguments/naming guides taken from
 * Bakuten Shoot Beyblade 2002 and http://github.com/Tilka/hvqm4
 * with very many thanks from all of the projectPiki decompilation team.
 */

#define HVQM_PLANE_COUNT (3)
#define HVQM_LUMA_CHROMA (2)

/**
 * @brief Video sequence decoder context
 * @note Size: 0xA (unaligned), 0xC (aligned)
 */
typedef struct SeqObj {
	void* ws;         // _00, decoder's working memory
	u16 frame_width;  // _04
	u16 frame_height; // _06
	u8 h_samp;        // _08, horizontal chroma subsampling
	u8 v_samp;        // _09, vertical chroma subsampling
} SeqObj;

/**
 * @brief Video stream metadata
 * @note Size: 0x8
 */
typedef struct VideoInfo {
	u16 width;          // _00
	u16 height;         // _02
	u8 h_sampling_rate; // _04, horizontal chroma subsampling rate
	u8 v_sampling_rate; // _05, vertical chroma subsampling rate
	u8 pad[2];          // _06, padding for alignment
} VideoInfo;

/**
 * @brief 4x4 block metadata
 * @note Size: 0x2 (unaligned), 0x4 (aligned)
 */
typedef struct _tagHVQData {
	u8 dcv; // _00, DC coefficient value
	u8 bnm; // _01, basis function index / block type
} _tagHVQData;

/**
 * @brief Huffman decoding tree
 * @note Size: 0x1008
 */
typedef struct Tree {
	int node_number;  // _00, the current total allocation count
	int tree_root;    // _04, tree root node index
	int leaf[2][512]; // _08, binary tree nodes [0/1 branch][node index]
} Tree;

/**
 * @brief Bitstream reading buffer
 * @note Size: 0x10
 */
typedef struct BitBuffer {
	u8* ptr;   // _00, current read position
	u32 size;  // _04, remaining data size
	u32 word;  // _08, cached bit value
	int shift; // _0C, current bit position in cache
} BitBuffer;

/**
 * @brief Bitstream with associated Huffman tree
 * @note Size: 0x14
 */
typedef struct BitBufferWithTree {
	BitBuffer str; // _00
	Tree* tree;    // _10
} BitBufferWithTree;

/**
 * @brief Color plane descriptor
 * @note Size: 0x35 (unaligned), 0x38 (aligned)
 */
typedef struct HVQPlaneDesc {
	_tagHVQData* blockInfoBuf; // _00, beginning of plane incl. border
	_tagHVQData* blockInfoTop; // _04, beginning of non-border plane data
	u16 nblocks_h;             // _08, not including border
	u16 nblocks_v;             // _0A, not including border
	u16 nblocks_hb;            // _0C, including border
	u16 nblocks_vb;            // _0E, including border
	u16 bibUscan[4];           // _10, block-in-block scanning offsets for 2x2
	u32 imgUscan[4];           // _18, pixel offset pattern for 4x4 blocks
	u16 plane_width;           // _28, in samples
	u16 plane_height;          // _2A, in samples
	u32 plane_size;            // _2C, in samples
	u8 h_shift;                // _30
	u8 v_shift;                // _31
	u8 hvqblk_h;               // _32, Macroblock width
	u8 hvqblk_v;               // _33, Macroblock height
	u8 nblocks_mcb;            // _34, blocks per macroblock
} HVQPlaneDesc;

/**
 * @brief Block decoding context
 * @note Size: 0x15 (unaligned), 0x18 (aligned)
 */
typedef struct StackState {
	int id;                 // _00, current colour plane index
	const _tagHVQData* upp; // _04, previous line
	const _tagHVQData* mid; // _08, current line
	const _tagHVQData* low; // _0C, next line
	_tagHVQData right;      // _10
	_tagHVQData curr;       // _12
	u8 l_dcv;               // _14, left neighbor DC value, used for prediction
} StackState;

/**
 * @brief Main video decoder state
 * @note Size: 0x3CD0
 */
typedef struct VideoState {
	HVQPlaneDesc pln[HVQM_PLANE_COUNT];        // _0000, YUV plane descriptors
	Tree dcv_tree;                             // _00A8, DC value Huffman tree
	Tree zrn_tree;                             // _10B0, zero run-length tree
	Tree scl_tree;                             // _20B8, scale factor tree
	Tree num_tree;                             // _30C0, basis number tree
	Tree vec_tree;                             // _40C8, motion vector tree
	Tree mrn_tree;                             // _50D0, macroblock run tree
	BitBufferWithTree dcval[HVQM_PLANE_COUNT]; // _60D8, DC coefficient streams
	BitBufferWithTree dcrun[HVQM_PLANE_COUNT]; // _6114, DC run-length streams
	BitBufferWithTree scale[HVQM_PLANE_COUNT]; // _6150, AOT scale streams
	BitBufferWithTree bsnum[HVQM_LUMA_CHROMA]; // _618C, basis function indices
	BitBufferWithTree bsrun[HVQM_LUMA_CHROMA]; // _61B4, basis run-lengths
	BitBuffer aotcd[HVQM_PLANE_COUNT];         // _61DC, AOT coefficient data
	BitBufferWithTree mvecx;                   // _620C, horizontal motion vectors
	BitBufferWithTree mvecy;                   // _6220, vertical motion vectors
	BitBufferWithTree mcaot;                   // _6234, macroblock processing flags
	BitBufferWithTree mstat;                   // _6248, macroblock type flags
	u16 nestsize_h;                            // _625C, reference nest width
	u16 nestsize_v;                            // _625E, reference nest height
	u8 landscape;                              // _6260, orientation flag
	u8 nestBuf[70 * 38];                       // _6261, downsampled reference
	int dc_max;                                // _6CC8, DC coefficient max
	int dc_min;                                // _6CCC, DC coefficient min
	u8 aotscale_q;                             // _6CD0, AOT quantization shift
	u8 dc_scale_q;                             // _6CD1, DC quantization shift
	u8 fcode[2][2];                            // _6CD2, motion vector precision [axis:0=x,1=y][ref:0=past,1=future]
} VideoState;

/**
 * @brief Motion compensation plane handler
 * @note Size: 0x34
 */
typedef struct _tagPlnMCHandler {
	int bsrunleng;         // _00, basis run-length (V plane uses U plane's value)
	int prev_dcv;          // _04
	_tagHVQData* data;     // _08, block data start address
	_tagHVQData* data_top; // _0C, row start address
	u8* lin_top;           // _10, frame line start address
	u8* blk_top;           // _14, block row start address
	u8* targ;              // _18, target frame pointer (selected from forw/back)
	u8* forw;              // _1C, forward reference frame
	u8* back;              // _20, backward reference frame
	u16 next_macro_pix;    // _24, horizontal macroblock step size
	u32 down_macro_pix;    // _28, vertical macroblock step size
	int hvqblk_h;          // _2C, horizontal macroblock size
	int hvqblk_v;          // _30, vertical macroblock size
} MCPlane;

/**
 * @brief Motion compensation handler
 * @note Size: 0x9C
 */
typedef struct _tagMCHander {
	MCPlane pln[HVQM_PLANE_COUNT]; // _00, handlers for Y/U/V planes
} MCHandler;

/**
 * @brief Run-length decoder state
 * @note Size: 0x8
 */
typedef struct RLDecoder {
	int status; // _00
	int runlng; // _04, remaining run-length
} RLDecoder;

void HVQM4InitDecoder();
void HVQM4InitSeqObj(SeqObj* obj, VideoInfo* header);
u32 HVQM4BuffSize(SeqObj* obj);
void HVQM4SetBuffer(SeqObj* obj, void* buf);
void HVQM4DecodeIpic(SeqObj* obj, void* code, void* outbuf);
void HVQM4DecodePpic(SeqObj* obj, void* code, void* outbuf, void* ref1);
void HVQM4DecodeBpic(SeqObj* obj, void* code, void* outbuf, void* ref2, void* ref1);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
