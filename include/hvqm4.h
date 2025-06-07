#ifndef _HVQM4_H
#define _HVQM4_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

/*
 * Initial code attempts + comments + function arguments/naming guides taken from
 * http://github.com/Tilka/hvqm4 with very many thanks from all of the Pikmin team.
 */

#define HVQM_PLANE_COUNT 3 // apparently
#define HVQM_LUMA_CHROMA 2 // apparently

/**
 * @brief Video sequence decoder context
 * @note Size: 0xA.
 */
typedef struct HVQM4Decoder {
	void* workSpace;  // _00, decoder's working memory
	u16 frameWidth;   // _04
	u16 frameHeight;  // _06
	u8 horizSampling; // _08, horizontal chroma subsampling
	u8 vertSampling;  // _09, vertical chroma subsampling
} HVQM4Decoder;

/**
 * @brief Video stream metadata
 * @note Size: 0x7.
 */
typedef struct HVQM4Info {
	u16 width;            // _00
	u16 height;           // _02
	u8 horizSamplingRate; // _04, horizontal chroma subsampling rate
	u8 vertSamplingRate;  // _05, vertical chroma subsampling rate
	u8 pad[2];            // _06
} HVQM4Info;

/**
 * @brief 4x4 block metadata
 * @note Size: 0x2
 */
typedef struct QuantBlock {
	u8 dcValue;  // _00, DC coefficient
	u8 basisNum; // _01, basis function index / block type
} QuantBlock;

/**
 * @brief Huffman decoding tree
 * @note Size: 0x1008.
 */
typedef struct HuffmanTree {
	int nodeCount;           // _00, the current total allocation count
	int rootNode;            // _04, tree root node index
	int leafNodes[2][0x200]; // _08, binary tree [bit][index]
} HuffmanTree;

/**
 * @brief Bitstream reading buffer
 * @note Size: 0x10.
 */
typedef struct Bitstream {
	u8* dataPtr;     // _00, current read position
	u32 size;        // _04, remaining data size
	u32 cachedBits;  // _08
	int bitPosition; // _0C, current bit position in cache
} Bitstream;

/**
 * @brief Bitstream with associated Huffman tree
 * @note Size: 0x14.
 */
typedef struct CodedStream {
	Bitstream buf;     // _00
	HuffmanTree* tree; // _10
} CodedStream;

/**
 * @brief Color plane descriptor
 * @note Size: 0x38.
 */
typedef struct HVQPlaneDesc {
	QuantBlock* blockBuffer;    // _00, full block data including borders
	QuantBlock* blockDataStart; // _04, start of non-border block data
	u16 blocksHoriz;            // _08
	u16 blocksVert;             // _0A
	u16 blocksHorizWithBorder;  // _0C
	u16 blocksVertWithBorder;   // _0E
	u16 blockScanOrder[4];      // _10, block scanning pattern
	u32 pixelScanOrder[4];      // _18, pixel scanning pattern
	u16 planeWidth;             // _28
	u16 planeHeight;            // _2A
	u32 planePixelCount;        // _2C
	u8 horizShift;              // _30
	u8 vertShift;               // _31
	u8 mcBlockWidth;            // _32
	u8 mcBlockHeight;           // _33
	u8 blocksPerMacroblock;     // _34
} HVQPlaneDesc;

/**
 * @brief Block decoding context
 * @note Size: 0x15.
 */
typedef struct HVQMBlockDecodeContext {
	int planeIndex;           // _00, current color plane
	const QuantBlock* topRow; // _04, previous row blocks
	const QuantBlock* midRow; // _08, current row blocks
	const QuantBlock* botRow; // _0C, next row blocks
	QuantBlock rightBlock;    // _10
	QuantBlock currBlock;     // _12
	u8 leftDcValue;           // _14, left neighbor DC value
} HVQMBlockDecodeContext;

/**
 * @brief Main video decoder state
 * @note Size: 0x3CD0.
 */
typedef struct VideoState {
	HVQPlaneDesc planes[HVQM_PLANE_COUNT];         // _0000, YUV plane descriptors
	HuffmanTree dcValueTree;                       // _00A8, DC value Huffman tree
	HuffmanTree zeroRunTree;                       // _10B0, zero run-length tree
	HuffmanTree scaleTree;                         // _20B8, scale factor tree
	HuffmanTree numberTree;                        // _30C0, basis number tree
	HuffmanTree vectorTree;                        // _40C8, motion vector tree
	HuffmanTree macroRunTree;                      // _50D0, macroblock run tree
	CodedStream dcValues[HVQM_PLANE_COUNT];        // _60D8, DC coefficient streams
	CodedStream dcRunLengths[HVQM_PLANE_COUNT];    // _6114, DC run-length streams
	CodedStream scalingFactors[HVQM_PLANE_COUNT];  // _6150, AOT scale streams
	CodedStream basisNumbers[HVQM_LUMA_CHROMA];    // _618C, basis function indices
	CodedStream basisRunLengths[HVQM_LUMA_CHROMA]; // _61B4, basis run-lengths
	Bitstream aotData[HVQM_PLANE_COUNT];           // _61DC, AOT coefficient data
	CodedStream motionVectorsX;                    // _620C, horizontal motion vectors
	CodedStream motionVectorsY;                    // _6220, vertical motion vectors
	CodedStream macroProcessor;                    // _6234, macroblock processing flags
	CodedStream macroTypes;                        // _6248, macroblock type flags
	u16 nestWidth;                                 // _625C, reference nest width
	u16 nestHeight;                                // _625E, reference nest height
	u8 isLandscape;                                // _6260, orientation flag
	u8 nestBuffer[70 * 38];                        // _6261, downsampled reference
	int dcRangeMax;                                // _6CC8, DC coefficient max
	int dcRangeMin;                                // _6CCC, DC coefficient min
	u8 aotQuantShift;                              // _6CD0, AOT quantization shift
	u8 dcQuantShift;                               // _6CD1, DC quantization shift
	u8 motionPrecision[2][2];                      // _6CD2, motion vector precision [x/y][past/future]
} VideoState;

/**
 * @brief Motion compensation plane handler
 * @note Size: 0x34.
 */
typedef struct MCPlane {
	int basisRunLength;        // _00, only for Y and U (the V plane shares the U plane's value)
	int previousDcValue;       // _04
	QuantBlock* blockData;     // _08
	QuantBlock* blockRowStart; // _0C
	u8* frameTop;              // _10
	u8* blockTop;              // _14
	u8* targetFrame;           // _18
	u8* forwardRef;            // _1C
	u8* backwardRef;           // _20
	u16 horizMacroStep;        // _24
	u32 vertMacroStep;         // _28
	int mcBlocksHoriz;         // _2C
	int mcBLocksVert;          // _30
} MCPlane;

/**
 * @brief Motion compensation handler
 * @note Size: 0x9C.
 */
typedef struct MCHandler {
	MCPlane colorPlanes[HVQM_PLANE_COUNT]; // _00, handlers for Y/U/V planes
} MCHandler;

/**
 * @brief Run-length decoder state
 * @note Size: 0x8.
 */
typedef struct RLDecoder {
	int status;       // _00
	int remainingRun; // _04, remaining run length 
} RLDecoder;

void HVQM4InitDecoder();
void HVQM4InitSeqObj(HVQM4Decoder* obj, HVQM4Info* header);
u32 HVQM4BuffSize(HVQM4Decoder* obj);
void HVQM4SetBuffer(HVQM4Decoder* obj, void* buf);
void HVQM4DecodeIpic(HVQM4Decoder* obj, void* code, void* outbuf);
void HVQM4DecodePpic(HVQM4Decoder* obj, void* code, void* outbuf, void* ref1);
void HVQM4DecodeBpic(HVQM4Decoder* obj, void* code, void* outbuf, void* ref2, void* ref1);

/////////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
