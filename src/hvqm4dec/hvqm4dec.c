#include "types.h"
#include "hvqm4.h"

/*
 * Initial code attempts + comments + function arguments/naming guides taken from
 * http://github.com/Tilka/hvqm4 with very many thanks from all of the Pikmin team.
 */

typedef void (*MotionCompFunc)(u8* cP, int cWidth, u8* tP, int tWidth);

static u8 clipTable[0x200];
static int divTable[0x10];
static int mcdivTable[0x200];

static int readTree_signed;
static u32 readTree_scale;

// Color plane indices for YUV color space
#define LUMA_Y_PLANE   (0)
#define CHROMA_U_PLANE (1)
#define CHROMA_V_PLANE (2)

// Simplified indices for luma vs chroma operations
#define LUMA_INDEX   (0)
#define CHROMA_INDEX (1)

#define read8(buf, offset)  (*(u8*)((u8*)(buf) + (offset)))
#define read16(buf, offset) (*(u16*)((u8*)(buf) + (offset)))
#define read32(buf, offset) (*(u32*)((u8*)(buf) + (offset)))

/*
 * @brief Clamps an integer value to the range of a byte (0-255).
 */
static inline u8 clampToByte(int value)
{
	if (value < 0) {
		return 0;
	} else if (value > 0xFF) {
		return 0xFF;
	} else {
		return value;
	}
}

/*
 * --INFO--
 * Address:	8001EC3C
 * Size:	000360
 */
static void init_global_constants()
{
	int tableIndex;
	int signedValue;

	// Build pixel clamping table with 256-entry offset for signed access
	for (tableIndex = 0, signedValue = -0x80; tableIndex < 0x200; tableIndex++, signedValue++) {
		clipTable[tableIndex] = clampToByte(signedValue);
	}

	// Build division table for block operations
	divTable[0] = 0;
	for (tableIndex = 1; tableIndex < 0x10; tableIndex++) {
		divTable[tableIndex] = 0x1000 / (tableIndex * 16) * 16;
	}

	// Building motion compensation division table
	mcdivTable[0] = 0;
	for (tableIndex = 1; tableIndex < 0x200; tableIndex++) {
		mcdivTable[tableIndex] = 0x1000 / tableIndex;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
static void set_border(QuantBlock* p)
{
	p->dcValue  = 0x7F;
	p->basisNum = 0xFF;
}

/*
 * --INFO--
 * Address:	8001EF9C
 * Size:	00011C
 */
static void setHVQPlaneDesc(HVQM4Decoder* obj, int planeId, u8 horizSampling, u8 vertSampling)
{
	u32 macroBlockOffset, pixelBlockOffset;
	HVQPlaneDesc* plane = &((VideoState*)obj->workSpace)->planes[planeId];

	// Calculate downsampling shifts
	plane->horizShift      = (horizSampling == 2) ? 1 : 0;
	plane->planeWidth      = obj->frameWidth >> plane->horizShift;
	plane->vertShift       = (vertSampling == 2) ? 1 : 0;
	plane->planeHeight     = obj->frameHeight >> plane->vertShift;
	plane->planePixelCount = plane->planeWidth * plane->planeHeight;

	// Calculate block dimensions accounting for subsampling
	plane->mcBlockWidth        = 2 >> plane->horizShift;                     // 1 or 2 pixels
	plane->mcBlockHeight       = 2 >> plane->vertShift;                      // 1 or 2 pixels
	plane->blocksPerMacroblock = plane->mcBlockWidth * plane->mcBlockHeight; // 1 to 4 pixels

	// Calculate 4x4 block counts
	plane->blocksHoriz = obj->frameWidth / (horizSampling * 4);
	plane->blocksVert  = obj->frameHeight / (vertSampling * 4);

	// Add border blocks for edge handling
	plane->blocksHorizWithBorder = plane->blocksHoriz + 2;
	plane->blocksVertWithBorder  = plane->blocksVert + 2;

	// Setup block scanning patterns for motion compensation
	plane->blockScanOrder[0] = 0;
	plane->blockScanOrder[3] = 1;
	macroBlockOffset         = plane->blocksHorizWithBorder;
	plane->blockScanOrder[1] = macroBlockOffset;
	plane->blockScanOrder[2] = macroBlockOffset + 1;

	plane->pixelScanOrder[0] = 0;
	plane->pixelScanOrder[3] = 4;
	pixelBlockOffset         = plane->planeWidth << 2;
	plane->pixelScanOrder[1] = pixelBlockOffset;
	plane->pixelScanOrder[2] = pixelBlockOffset + 4;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
static void setCode(Bitstream* stream, u8* dataStart)
{
	u32 size     = read32(dataStart, 0);
	stream->size = size;
	if (size == 0) {
		stream->dataPtr = NULL;
	} else {
		stream->dataPtr = dataStart + 4;
	}

	stream->bitPosition = -1;
}

/*
 * --INFO--
 * Address:	8001F7E8
 * Size:	000040
 */
static inline int getBit(Bitstream* stream)
{
	u32 value;
	int bitPos;

	if ((bitPos = stream->bitPosition) < 0) {
		value = stream->cachedBits = *((u32*)stream->dataPtr)++;
		bitPos                     = 31;
	} else {
		value = stream->cachedBits;
	}

	value               = value >> bitPos & 1;
	stream->bitPosition = bitPos - 1;
	return value;
}

/*
 * --INFO--
 * Address:	8001F384
 * Size:	000064
 */
static inline s16 getByte(Bitstream* stream)
{
	u32 value;
	int bitPos;

	if ((bitPos = stream->bitPosition) >= 7) {
		value = stream->cachedBits;
		value >>= bitPos - 7;
		bitPos -= 8;
	} else {
		value = stream->cachedBits;
		value <<= 7 - bitPos;
		stream->cachedBits = *((u32*)stream->dataPtr)++;
		value |= stream->cachedBits >> (bitPos + 25);
		bitPos += 24;
	}

	stream->bitPosition = bitPos;
	value &= 0xFF;
	return value;
}
/*
 * --INFO--
 * Address:	8001F0B8
 * Size:	0002CC
 */
static s16 _readTree(HuffmanTree* tree, Bitstream* stream)
{
	int badCompiler[2];

	if (getBit(stream)) {
		// Internal node - read both children
		int nodeId                 = tree->nodeCount++;
		tree->leafNodes[0][nodeId] = _readTree(tree, stream);
		tree->leafNodes[1][nodeId] = _readTree(tree, stream);
		return nodeId;
	} else {
		// Leaf node - read symbol value
		s16 byte   = getByte(stream);
		s16 symbol = byte;

		if (readTree_signed && byte > 0x7F) {
			symbol -= 0x100;
		}

		symbol <<= readTree_scale;
		tree->leafNodes[0][byte] = symbol;
		return byte;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
static void readTree(CodedStream* stream, int isSigned, int scale)
{
	HuffmanTree* tree = stream->tree;
	Bitstream* buf    = &stream->buf;

	readTree_signed = isSigned;
	readTree_scale  = scale;
	tree->nodeCount = 0x100;
	if (buf->size != 0) {
		tree->rootNode = _readTree(tree, buf);
	} else {
		tree->rootNode = 0;
	}
}

/*
 * --INFO--
 * Address:	8001F828
 * Size:	000070
 */
static inline int decodeHuff(CodedStream* stream)
{
	HuffmanTree* tree = stream->tree;
	Bitstream* buffer = &stream->buf;
	int pos           = tree->rootNode;

	while (pos >= 0x100) {
		pos = tree->leafNodes[getBit(buffer)][pos];
	}

	return tree->leafNodes[0][pos];
}

// Decode signed overflow symbol with range checking
static inline int decodeSignedOverflowSym(CodedStream* stream, int min, int max)
{
	int value = 0;
	int num;

	do {
		num = decodeHuff(stream);
		value += num;
	} while (!(min < num && num < max));

	return value;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
static inline int decodeUnsignedOverflowSym(CodedStream* stream, int max)
{
	int value = 0;
	int num;

	do {
		num = decodeHuff(stream);
		value += num;
	} while (num >= max);

	return value;
}

/*
 * --INFO--
 * Address:	8001F3E8
 * Size:	0002C4
 */
static void Ipic_BasisNumDec(VideoState* vs)
{
	s16 symbolVal;
	int runLength;
	QuantBlock* lumaBlockData;
	QuantBlock* uData;
	QuantBlock* vData;
	int i, j;
	int horizBlocks, vertBlocks;
	CodedStream* symbolEncoder;
	CodedStream* runLengthEncoder;

	// Process luma plane
	runLength        = 0;
	lumaBlockData    = vs->planes[LUMA_Y_PLANE].blockDataStart;
	symbolEncoder    = &vs->basisNumbers[LUMA_INDEX];
	runLengthEncoder = &vs->basisRunLengths[LUMA_INDEX];
	horizBlocks      = vs->planes[LUMA_INDEX].blocksHoriz;
	vertBlocks       = vs->planes[LUMA_INDEX].blocksVert;

	// Decode basis numbers for luma plane
	for (j = vertBlocks; j > 0; j--) {
		for (i = horizBlocks; i > 0; i--) {
			if (runLength == 0) {
				symbolVal = decodeHuff(symbolEncoder);
				if (symbolVal == 0) {
					runLength = decodeHuff(runLengthEncoder);
				}

				lumaBlockData++->basisNum = symbolVal & 0xFF;
			} else {
				lumaBlockData++->basisNum = 0;
				runLength--;
			}
		}

		// Skip right border of this line and left border of next line
		lumaBlockData += 2;
	}

	// Process chroma planes
	runLength        = 0;
	uData            = vs->planes[CHROMA_U_PLANE].blockDataStart;
	vData            = vs->planes[CHROMA_V_PLANE].blockDataStart;
	symbolEncoder    = &vs->basisNumbers[CHROMA_INDEX];
	runLengthEncoder = &vs->basisRunLengths[CHROMA_INDEX];
	horizBlocks      = vs->planes[CHROMA_INDEX].blocksHoriz;
	vertBlocks       = vs->planes[CHROMA_INDEX].blocksVert;

	// Decode basis numbers for chroma planes
	for (i = vertBlocks; i > 0; i--) {
		for (j = horizBlocks; j > 0; j--) {
			if (runLength == 0) {
				symbolVal = decodeHuff(symbolEncoder);
				if (symbolVal == 0) {
					runLength = decodeHuff(runLengthEncoder);
				}

				uData++->basisNum = (symbolVal >> 0) & 0xF;
				vData++->basisNum = (symbolVal >> 4) & 0xF;
			} else {
				uData++->basisNum = 0;
				vData++->basisNum = 0;
				runLength--;
			}
		}

		// Skip right border of this line and left border of next line
		uData += 2;
		vData += 2;
	}
}

// Extract DC coefficient delta with run-length decoding
static inline int extractDcDelta(VideoState* vs, int planeIndex, int* currentRunLength)
{
	int delta;

	if (*currentRunLength == 0) {
		delta = decodeSignedOverflowSym(&vs->dcValues[planeIndex], vs->dcRangeMin, vs->dcRangeMax);

		// Zero values are run-length encoded
		if (delta == 0) {
			*currentRunLength = decodeHuff(&vs->dcRunLengths[planeIndex]);
		}

		return delta;
	}

	(*currentRunLength)--;
	return 0;
}

/*
 * --INFO--
 * Address:	8001F6AC
 * Size:	00013C
 */
static void IpicDcvDec(VideoState* vs)
{
	int planeIndex;
	QuantBlock* currBlock;
	QuantBlock* prevBlock;
	int runLength;
	int predictedValue;
	int blocksPerRow;
	int horizBlocks, vertBlocks;
	int i, j;

	for (planeIndex = 0; planeIndex < HVQM_PLANE_COUNT; planeIndex++) {
		horizBlocks  = vs->planes[planeIndex].blocksHoriz;
		vertBlocks   = vs->planes[planeIndex].blocksVert;
		blocksPerRow = vs->planes[planeIndex].blocksHorizWithBorder;

		currBlock = vs->planes[planeIndex].blockDataStart;
		runLength = 0;

		for (j = vertBlocks; j > 0; j--) {
			prevBlock = currBlock - blocksPerRow;
			!prevBlock;
			predictedValue = prevBlock->dcValue;

			for (i = horizBlocks; i > 0; i--) {
				u8 currDcVal;
				u8 prevDcVal;

				currDcVal = predictedValue + extractDcDelta(vs, planeIndex, &runLength);
				prevBlock++;
				prevDcVal            = prevBlock->dcValue;
				currBlock++->dcValue = currDcVal;

				/*
				 * The next prediction is the rounded average of the DC value
				 * from the block to the left (L) and the block above (T).
				 * +------+------+
				 * |      |   T  |
				 * +------+------+
				 * |   L  | Next |
				 * +------+------+
				 */
				predictedValue = (prevDcVal + currDcVal + 1) >> 1;
			}

			// Skip right border of this line and left border of next line
			currBlock += 2;
		}
	}
}

/*
 * --INFO--
 * Address:	8001F898
 * Size:	0003A4
 */
static void MakeNest(VideoState* vs, int nestX, int nestY)
{
	int h_block, nblocks_hb, v_block;
	QuantBlock* src;
	int h_dc_orderly, v_dc_orderly;
	int h_dc_reverse, v_dc_reverse;
	int h_nest_blank, v_nest_blank;
	int i, j;
	u8* nestP;
	u8* backP;
	QuantBlock* dP;
	u8* nP;

	h_block    = vs->planes[LUMA_Y_PLANE].blocksHoriz;
	nblocks_hb = vs->planes[LUMA_Y_PLANE].blocksHorizWithBorder;
	v_block    = vs->planes[LUMA_Y_PLANE].blocksVert;
	src        = vs->planes[LUMA_Y_PLANE].blockDataStart + (nestY * nblocks_hb + nestX);

	// Handle cases where video is smaller than nest size
	if (h_block < vs->nestWidth) {
		h_dc_orderly = h_block;
		if ((h_dc_reverse = vs->nestWidth - h_block) > h_block)
			h_dc_reverse = h_block;
		h_nest_blank = vs->nestWidth - (h_dc_orderly + h_dc_reverse);
	} else {
		h_dc_orderly = vs->nestWidth;
		h_dc_reverse = h_nest_blank = 0;
	}

	if (v_block < vs->nestHeight) {
		v_dc_orderly = v_block;
		if ((v_dc_reverse = vs->nestHeight - v_block) > v_block)
			v_dc_reverse = v_block;
		v_nest_blank = vs->nestHeight - (v_dc_orderly + v_dc_reverse);
	} else {
		v_dc_orderly = vs->nestHeight;
		v_dc_reverse = v_nest_blank = 0;
	}

	// Copy forward section
	nP = vs->nestBuffer;
	for (j = v_dc_orderly; j > 0; j--) {
		dP = src;
		for (i = h_dc_orderly; i > 0; i--) {
			*nP++ = (dP->dcValue >> 4) & 0xF;
			dP++;
		}

		// Mirror horizontally if needed
		for (i = h_dc_reverse; i > 0; i--) {
			dP--;
			*nP++ = (dP->dcValue >> 4) & 0xF;
		}

		// Fill remaining with zeros
		for (i = h_nest_blank; i > 0; i--) {
			*nP++ = 0;
		}

		src += nblocks_hb;
	}

	// Mirror vertically if needed
	nestP = nP - vs->nestWidth;
	for (j = v_dc_reverse; j > 0; j--) {
		backP = nestP;
		for (i = vs->nestWidth; i > 0; i--) {
			*nP++ = *backP++;
		}
		nestP -= vs->nestWidth;
	}

	// Fill remaining rows with zeros
	for (j = v_nest_blank; j > 0; j--) {
		for (i = vs->nestWidth; i > 0; i--) {
			*nP++ = 0;
		}
	}
}

/*
 * --INFO--
 * Address:	8001FC3C
 * Size:	000198
 */
static void WeightImBlock(u8* block, int stride, u8 centerDC, u8 topDC, u8 bottomDC, u8 leftDC, u8 rightDC)
{
	// Gradient calculations for bilinear interpolation
	int verticalGradient   = topDC - bottomDC;
	int horizontalGradient = leftDC - rightDC;

	int diagonalSum  = verticalGradient + horizontalGradient;
	int diagonalDiff = verticalGradient - horizontalGradient;

	int centerDouble   = centerDC * 2;
	int centerWeighted = centerDC * 8 + 4;

	int topLeftWeight     = topDC + leftDC - centerDouble;
	int topRightWeight    = topDC + rightDC - centerDouble;
	int bottomRightWeight = bottomDC + rightDC - centerDouble;
	int bottomLeftWeight  = leftDC + bottomDC - centerDouble;

	int topLeftDiff     = topDC - leftDC;
	int topRightDiff    = topDC - rightDC;
	int bottomRightDiff = bottomDC - rightDC;
	int bottomLeftDiff  = bottomDC - leftDC;

	// Apply weighted interpolation matrix weights form a smooth gradient across the 4x4 block
	block[0] = clipTable[(centerWeighted + diagonalSum + topLeftWeight >> 3) + 0x80];
	block[1] = clipTable[(centerWeighted + diagonalSum + topLeftDiff >> 3) + 0x80];
	block[2] = clipTable[(centerWeighted + diagonalDiff + topRightDiff >> 3) + 0x80];
	block[3] = clipTable[(centerWeighted + diagonalDiff + topRightWeight >> 3) + 0x80];
	block += stride;

	block[0] = clipTable[(centerWeighted + diagonalSum - topLeftDiff >> 3) + 0x80];
	block[1] = clipTable[(centerWeighted - bottomRightWeight >> 3) + 0x80];
	block[2] = clipTable[(centerWeighted - bottomLeftWeight >> 3) + 0x80];
	block[3] = clipTable[(centerWeighted + diagonalDiff - topRightDiff >> 3) + 0x80];
	block += stride;

	block[0] = clipTable[(centerWeighted - diagonalDiff - bottomLeftDiff >> 3) + 0x80];
	block[1] = clipTable[(centerWeighted - topRightWeight >> 3) + 0x80];
	block[2] = clipTable[(centerWeighted - topLeftWeight >> 3) + 0x80];
	block[3] = clipTable[(centerWeighted - diagonalSum - bottomRightDiff >> 3) + 0x80];
	block += stride;

	block[0] = clipTable[(centerWeighted - diagonalDiff + bottomLeftWeight >> 3) + 0x80];
	block[1] = clipTable[(centerWeighted - diagonalDiff + bottomLeftDiff >> 3) + 0x80];
	block[2] = clipTable[(centerWeighted - diagonalSum + bottomRightDiff >> 3) + 0x80];
	block[3] = clipTable[(centerWeighted - diagonalSum + bottomRightWeight >> 3) + 0x80];
	block += stride;
}

// Fill 4x4 block with single DC value
static void dcBlock(u8* block, int stride, u8 dc)
{
	block[0] = block[1] = block[2] = block[3] = dc;
	block += stride;

	block[0] = block[1] = block[2] = block[3] = dc;
	block += stride;

	block[0] = block[1] = block[2] = block[3] = dc;
	block += stride;

	block[0] = block[1] = block[2] = block[3] = dc;
	block += stride;
}

/*
 * --INFO--
 * Address:	8001FDD4
 * Size:	000048
 */
static void OrgBlock(VideoState* vs, u8* block, int blockWidth, int p)
{
	Bitstream* srcData;
	u32* srcPtr;
	u32 row1Data;
	u32 row2Data;
	u32 row3Data;

	FORCE_DONT_INLINE;

	srcData  = &vs->aotData[p];
	srcPtr   = (u32*)srcData->dataPtr;
	row1Data = srcPtr[1];
	row2Data = srcPtr[2];
	row3Data = srcPtr[3];

	*(u32*)(block)               = srcPtr[0];
	*(u32*)(block += blockWidth) = row1Data;
	*(u32*)(block += blockWidth) = row2Data;
	*(u32*)(block += blockWidth) = row3Data;

	srcData->dataPtr = (u8*)srcPtr + 16;
}

/*
 * --INFO--
 * Address:	800201EC
 * Size:	00047C
 */
static inline s32 GetAotBasis(VideoState* vs, u8 basisOut[16], s32* scaleAccum, u8* nestRef, int nestStride, int planeIndex)
{
	u16 controlCode;
	int sampleStepX, sampleStepY;
	u8 min, max;
	u8* nestSample;
	u8 value;

	controlCode = *vs->aotData[planeIndex].dataPtr++ << 8;
	controlCode |= *vs->aotData[planeIndex].dataPtr++;

	/*
	 * Decode sampling pattern from control bits
	 * Bits 0-5: X offset (6 bits)
	 * Bits 6-10: Y offset (5 bits)
	 * Bit 11: X stride (1 or 2)
	 * Bit 12: Y stride (1 or 2)
	 * Bits 13-14: Scale offset
	 * Bit 15: Negation flag
	 */
	if (vs->isLandscape) {
		nestRef += ((controlCode >> 6) & 0x1F) * nestStride + (controlCode & 0x3F);
		sampleStepX = 1 << ((controlCode >> 11) & 1);
		sampleStepY = nestStride << ((controlCode >> 12) & 1);
	} else {
		nestRef += (controlCode & 0x3F) * nestStride + ((controlCode >> 6) & 0x1F);
		sampleStepX = 1 << ((controlCode >> 12) & 1);
		sampleStepY = nestStride << ((controlCode >> 11) & 1);
	}

	nestSample = nestRef;

	// Sample 4x4 basis pattern and track min/max
	value       = *nestSample;
	basisOut[0] = value;
	min = max = value;

	nestSample += sampleStepX;

	value       = *nestSample;
	basisOut[1] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	/* Continue sampling remaining 14 values... */
	/* [Code continues with same pattern for indices 2-15] */

	nestSample += sampleStepX;

	value       = *nestSample;
	basisOut[2] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestSample += sampleStepX;

	value       = *nestSample;
	basisOut[3] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestRef += sampleStepY;
	nestSample = nestRef;

	value       = *nestSample;
	basisOut[4] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestSample += sampleStepX;

	value       = *nestSample;
	basisOut[5] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestSample += sampleStepX;

	value       = *nestSample;
	basisOut[6] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestSample += sampleStepX;

	value       = *nestSample;
	basisOut[7] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestRef += sampleStepY;
	nestSample = nestRef;

	value       = *nestSample;
	basisOut[8] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestSample += sampleStepX;

	value       = *nestSample;
	basisOut[9] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestSample += sampleStepX;

	value        = *nestSample;
	basisOut[10] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestSample += sampleStepX;

	value        = *nestSample;
	basisOut[11] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestRef += sampleStepY;
	nestSample = nestRef;

	value        = *nestSample;
	basisOut[12] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestSample += sampleStepX;

	value        = *nestSample;
	basisOut[13] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestSample += sampleStepX;

	value        = *nestSample;
	basisOut[14] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	nestSample += sampleStepX;

	value        = *nestSample;
	basisOut[15] = value;
	if (value > max) {
		max = value;
	} else if (value < min) {
		min = value;
	}

	*scaleAccum += decodeHuff(&vs->scalingFactors[planeIndex]);
	if (controlCode & 0x8000) {
		return -divTable[max - min] * (*scaleAccum + ((controlCode >> 13) & 3));
	} else {
		return divTable[max - min] * (*scaleAccum + ((controlCode >> 13) & 3));
	}
}

/*
 * --INFO--
 * Address:	80022700
 * Size:	0004C4
 */
static inline s32 GetMCAotBasis(VideoState* vs, u8 basisOut[16], s32* scaleAccum, u8* nestRef, int nestStride, int planeIndex)
{
	// Similar to extract_aot_basis but samples 4-bit values

	u16 controlCode;
	int sampleStepX, sampleStepY;
	u8 min, max;
	u8* nestSample;
	u8 sampleValue;

	controlCode = *vs->aotData[planeIndex].dataPtr++ << 8;
	controlCode |= *vs->aotData[planeIndex].dataPtr++;

	if (vs->isLandscape) {
		nestRef += ((controlCode >> 6) & 0x1F) * nestStride + (controlCode & 0x3F);
		sampleStepX = 1 << ((controlCode >> 11) & 1);
		sampleStepY = nestStride << ((controlCode >> 12) & 1);
	} else {
		nestRef += (controlCode & 0x3F) * nestStride + ((controlCode >> 6) & 0x1F);
		sampleStepX = 1 << ((controlCode >> 12) & 1);
		sampleStepY = nestStride << ((controlCode >> 11) & 1);
	}

	nestSample = nestRef;

	sampleValue = (*nestSample >> 4) & 0xF;
	basisOut[0] = sampleValue;
	min = max = sampleValue;

	nestSample += sampleStepX;

	sampleValue = (*nestSample >> 4) & 0xF;
	basisOut[1] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestSample += sampleStepX;

	sampleValue = (*nestSample >> 4) & 0xF;
	basisOut[2] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestSample += sampleStepX;

	sampleValue = (*nestSample >> 4) & 0xF;
	basisOut[3] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestRef += sampleStepY;
	nestSample = nestRef;

	sampleValue = (*nestSample >> 4) & 0xF;
	basisOut[4] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestSample += sampleStepX;

	sampleValue = (*nestSample >> 4) & 0xF;
	basisOut[5] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestSample += sampleStepX;

	sampleValue = (*nestSample >> 4) & 0xF;
	basisOut[6] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestSample += sampleStepX;

	sampleValue = (*nestSample >> 4) & 0xF;
	basisOut[7] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestRef += sampleStepY;
	nestSample = nestRef;

	sampleValue = (*nestSample >> 4) & 0xF;
	basisOut[8] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestSample += sampleStepX;

	sampleValue = (*nestSample >> 4) & 0xF;
	basisOut[9] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestSample += sampleStepX;

	sampleValue  = (*nestSample >> 4) & 0xF;
	basisOut[10] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestSample += sampleStepX;

	sampleValue  = (*nestSample >> 4) & 0xF;
	basisOut[11] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestRef += sampleStepY;
	nestSample = nestRef;

	sampleValue  = (*nestSample >> 4) & 0xF;
	basisOut[12] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestSample += sampleStepX;

	sampleValue  = (*nestSample >> 4) & 0xF;
	basisOut[13] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestSample += sampleStepX;

	sampleValue  = (*nestSample >> 4) & 0xF;
	basisOut[14] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	nestSample += sampleStepX;

	sampleValue  = (*nestSample >> 4) & 0xF;
	basisOut[15] = sampleValue;
	if (sampleValue > max) {
		max = sampleValue;
	} else if (sampleValue < min) {
		min = sampleValue;
	}

	*scaleAccum += decodeHuff(&vs->scalingFactors[planeIndex]);
	if (controlCode & 0x8000) {
		return -divTable[max - min] * (*scaleAccum + ((controlCode >> 13) & 3));
	} else {
		return divTable[max - min] * (*scaleAccum + ((controlCode >> 13) & 3));
	}
}

static inline s32 GetAotSum(VideoState* ws, s32 sum[16], u8 basisCount, u8* nestRef, int nestStride, int planeIndex)
{
	s32 previousScale;
	s32 currentScale;
	u8 accum[16];

	sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = sum[6] = sum[7] = sum[8] = sum[9] = sum[10] = sum[11] = sum[12] = sum[13]
	    = sum[14] = sum[15] = previousScale = 0;

	while (basisCount--) {
		currentScale = GetAotBasis(ws, accum, &previousScale, nestRef, nestStride, planeIndex);
		sum[0] += currentScale * accum[0];
		sum[1] += currentScale * accum[1];
		sum[2] += currentScale * accum[2];
		sum[3] += currentScale * accum[3];
		sum[4] += currentScale * accum[4];
		sum[5] += currentScale * accum[5];
		sum[6] += currentScale * accum[6];
		sum[7] += currentScale * accum[7];
		sum[8] += currentScale * accum[8];
		sum[9] += currentScale * accum[9];
		sum[10] += currentScale * accum[10];
		sum[11] += currentScale * accum[11];
		sum[12] += currentScale * accum[12];
		sum[13] += currentScale * accum[13];
		sum[14] += currentScale * accum[14];
		sum[15] += currentScale * accum[15];
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

/*
 * --INFO--
 * Address:	8001FE1C
 * Size:	0003D0
 * @note AOT = Adaptive Orthogonal Transform
 */
static void IntraAotBlock(VideoState* vs, u8* outPixels, int pixelStride, u8 dcValue, u8 basisCount, int planeIndex)
{
	s32 sum[16];
	s32 quantShift;
	int averageValue;

	if (basisCount == 6) {
		// Basis count 6 means copy original pixels
		OrgBlock(vs, outPixels, pixelStride, planeIndex);
	} else {
		// Apply AOT with DC offset
		quantShift   = vs->aotQuantShift;
		averageValue = (dcValue << quantShift) - GetAotSum(vs, sum, basisCount, vs->nestBuffer, vs->nestWidth, planeIndex);

		outPixels[0] = clipTable[((sum[0] + averageValue) >> quantShift) + 0x80];
		outPixels[1] = clipTable[((sum[1] + averageValue) >> quantShift) + 0x80];
		outPixels[2] = clipTable[((sum[2] + averageValue) >> quantShift) + 0x80];
		outPixels[3] = clipTable[((sum[3] + averageValue) >> quantShift) + 0x80];
		outPixels += pixelStride;

		outPixels[0] = clipTable[((sum[4] + averageValue) >> quantShift) + 0x80];
		outPixels[1] = clipTable[((sum[5] + averageValue) >> quantShift) + 0x80];
		outPixels[2] = clipTable[((sum[6] + averageValue) >> quantShift) + 0x80];
		outPixels[3] = clipTable[((sum[7] + averageValue) >> quantShift) + 0x80];
		outPixels += pixelStride;

		outPixels[0] = clipTable[((sum[8] + averageValue) >> quantShift) + 0x80];
		outPixels[1] = clipTable[((sum[9] + averageValue) >> quantShift) + 0x80];
		outPixels[2] = clipTable[((sum[10] + averageValue) >> quantShift) + 0x80];
		outPixels[3] = clipTable[((sum[11] + averageValue) >> quantShift) + 0x80];
		outPixels += pixelStride;

		outPixels[0] = clipTable[((sum[12] + averageValue) >> quantShift) + 0x80];
		outPixels[1] = clipTable[((sum[13] + averageValue) >> quantShift) + 0x80];
		outPixels[2] = clipTable[((sum[14] + averageValue) >> quantShift) + 0x80];
		outPixels[3] = clipTable[((sum[15] + averageValue) >> quantShift) + 0x80];
		outPixels += pixelStride;
	}
}

/*
 * --INFO--
 * Address:	80020668
 * Size:	000144
 */
static void IpicBlockDec(VideoState* vs, u8* outPixels, int pixelStride, HVQMBlockDecodeContext* decodeCtx)
{
	if (decodeCtx->currBlock.basisNum == 0) {
		// Smooth interpolated block
		u8 c_dc = decodeCtx->currBlock.dcValue;
		u8 u_dc = decodeCtx->topRow->basisNum & 0x77 ? c_dc : decodeCtx->topRow->dcValue;
		u8 d_dc = decodeCtx->botRow->basisNum & 0x77 ? c_dc : decodeCtx->botRow->dcValue;
		u8 r_dc = decodeCtx->rightBlock.basisNum & 0x77 ? c_dc : decodeCtx->rightBlock.dcValue;

		// Left DC is tracked separately for efficiency
		WeightImBlock(outPixels, pixelStride, c_dc, u_dc, d_dc, decodeCtx->leftDcValue, r_dc);
		decodeCtx->leftDcValue = c_dc;
	} else if (decodeCtx->currBlock.basisNum == 8) {
		// Constant DC block
		u8 dc = decodeCtx->currBlock.dcValue;
		dcBlock(outPixels, pixelStride, dc);
		decodeCtx->leftDcValue = dc;
	} else {
		// AOT-coded block, which doesn't propagate DC
		IntraAotBlock(vs, outPixels, pixelStride, decodeCtx->currBlock.dcValue, decodeCtx->currBlock.basisNum, decodeCtx->planeIndex);
		decodeCtx->leftDcValue = decodeCtx->rightBlock.dcValue;
	}

	decodeCtx->topRow++;
	decodeCtx->botRow++;
}

/*
 * --INFO--
 * Address:	800207AC
 * Size:	0000D4
 */
static void IpicLineDec(VideoState* vs, u8* outPixels, int pixelStride, HVQMBlockDecodeContext* decodeCtx, int rowWidth)
{
	int i;

	decodeCtx->rightBlock  = *decodeCtx->midRow;
	decodeCtx->leftDcValue = decodeCtx->midRow->dcValue;

	for (i = rowWidth - 1; i > 0; i--) {
		decodeCtx->currBlock  = decodeCtx->rightBlock;
		decodeCtx->rightBlock = *++decodeCtx->midRow;
		IpicBlockDec(vs, outPixels, pixelStride, decodeCtx);
		outPixels += 4;
	}

	decodeCtx->currBlock = decodeCtx->rightBlock;
	decodeCtx->midRow += 3;
	IpicBlockDec(vs, outPixels, pixelStride, decodeCtx);
	decodeCtx->topRow += 2;
	decodeCtx->botRow += 2;
}

/*
 * --INFO--
 * Address:	80020880
 * Size:	0000DC
 */
static void IpicPlaneDec(VideoState* vs, int planeIndex, u8* outputBuf)
{
	HVQMBlockDecodeContext blockContext;
	int imageWidth;
	int lineOffset;
	int horizBlocks;
	int blocksPerRow;
	int rowIndex;

	imageWidth   = vs->planes[planeIndex].planeWidth;
	lineOffset  = vs->planes[planeIndex].planeWidth * 4;
	horizBlocks    = vs->planes[planeIndex].blocksHoriz;
	blocksPerRow = vs->planes[planeIndex].blocksHorizWithBorder;

	blockContext.planeIndex = planeIndex;
	blockContext.botRow     = (blockContext.midRow = blockContext.topRow = vs->planes[planeIndex].blockDataStart) + blocksPerRow;

	// First row (no top neighbors)
	IpicLineDec(vs, outputBuf, imageWidth, &blockContext, horizBlocks);
	outputBuf += lineOffset;

	// Middle rows
	blockContext.topRow = vs->planes[planeIndex].blockDataStart;
	for (rowIndex = vs->planes[planeIndex].blocksVert - 2; rowIndex > 0; rowIndex--) {
		IpicLineDec(vs, outputBuf, imageWidth, &blockContext, horizBlocks);
		outputBuf += lineOffset;
	}

	// Last row (reuse current as bottom)
	blockContext.botRow = blockContext.midRow;
	IpicLineDec(vs, outputBuf, imageWidth, &blockContext, horizBlocks);
}

/*
 * --INFO--
 * Address:	8002095C
 * Size:	00008C
 */
static void initMCHandler(VideoState* vs, MCHandler* mch, u8* lin_top, u8* forw, u8* back)
{
	int i;
	MCPlane* mcplane;
	HVQPlaneDesc* plane;
	QuantBlock* block;

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
		mcplane                  = &mch->colorPlanes[i];
		plane                    = &vs->planes[i];
		mcplane->basisRunLength  = 0;
		mcplane->previousDcValue = 0x7F;
		mcplane->frameTop        = lin_top;
		mcplane->forwardRef      = forw;
		mcplane->backwardRef     = back;

		block                  = plane->blockDataStart;
		mcplane->blockData     = block;
		mcplane->blockRowStart = block;

		mcplane->horizMacroStep = 8 >> plane->horizShift;
		mcplane->vertMacroStep  = (8 >> plane->vertShift) * plane->planeWidth;
		mcplane->mcBlocksHoriz  = plane->mcBlockWidth;
		mcplane->mcBLocksVert   = plane->blocksHorizWithBorder * plane->mcBlockHeight;

		lin_top += plane->planePixelCount;
		forw += plane->planePixelCount;
		back += plane->planePixelCount;
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

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
		pmc                = &mch->colorPlanes[i];
		pmc->frameTop      = lin_top;
		pmc->blockRowStart = pmc->blockData = state->planes[i].blockDataStart;
		lin_top += state->planes[i].planePixelCount;
	}
}

static void setMCTop(MCHandler* mch)
{
	int i;
	MCPlane* pmc;

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
		pmc           = &mch->colorPlanes[i];
		pmc->blockTop = pmc->frameTop;
	}
}

// advance one 8x8 block to the right
// (8x8 in seqobj size units, which are presumably pixels)
static void setMCNextBlk(MCHandler* mch)
{
	int i;
	MCPlane* pmc;

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
		pmc = &mch->colorPlanes[i];
		pmc->blockTop += pmc->horizMacroStep;
		pmc->blockData += pmc->mcBlocksHoriz;
	}
}

// move to the next row of 8x8 blocks
// (8x8 in seqobj size units, which are presumably pixels)
static void setMCDownBlk(MCHandler* mch)
{
	int i;
	MCPlane* pmc;

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
		pmc = &mch->colorPlanes[i];
		pmc->frameTop += pmc->vertMacroStep;
		pmc->blockData = pmc->blockRowStart = pmc->blockRowStart + pmc->mcBLocksVert;
	}
}

// select which frame to use as an MC reference
static void setMCTarget(MCHandler* mch, int direct)
{
	if (direct == 0) {
		mch->colorPlanes[LUMA_Y_PLANE].targetFrame   = mch->colorPlanes[LUMA_Y_PLANE].forwardRef;
		mch->colorPlanes[CHROMA_U_PLANE].targetFrame = mch->colorPlanes[CHROMA_U_PLANE].forwardRef;
		mch->colorPlanes[CHROMA_V_PLANE].targetFrame = mch->colorPlanes[CHROMA_V_PLANE].forwardRef;
	} else {
		mch->colorPlanes[LUMA_Y_PLANE].targetFrame   = mch->colorPlanes[LUMA_Y_PLANE].backwardRef;
		mch->colorPlanes[CHROMA_U_PLANE].targetFrame = mch->colorPlanes[CHROMA_U_PLANE].backwardRef;
		mch->colorPlanes[CHROMA_V_PLANE].targetFrame = mch->colorPlanes[CHROMA_V_PLANE].backwardRef;
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
				pmc   = &mch->colorPlanes[c];
				t_top = pmc->targetFrame
				      + ((tx >> state->planes[c].horizShift + 1) + (ty >> state->planes[c].vertShift + 1) * state->planes[c].planeWidth);
				iofsP  = state->planes[c].pixelScanOrder;
				blocks = state->planes[c].blocksPerMacroblock;
				for (i = 0; i < blocks; i++) {
					offset = *iofsP++;
					cP     = pmc->blockTop + offset;
					tP     = t_top + offset;
					_MotionComp_00(cP, state->planes[c].planeWidth, tP, state->planes[c].planeWidth);
				}
			}
		} else {
			for (c = 0; c < HVQM_PLANE_COUNT; c++) {
				pmc   = &mch->colorPlanes[c];
				t_top = pmc->targetFrame
				      + ((tx >> state->planes[c].horizShift + 1) + (ty >> state->planes[c].vertShift + 1) * state->planes[c].planeWidth);
				iofsP  = state->planes[c].pixelScanOrder;
				blocks = state->planes[c].blocksPerMacroblock;
				for (i = 0; i < blocks; i++) {
					offset = *iofsP++;
					cP     = pmc->blockTop + offset;
					tP     = t_top + offset;
					_MotionComp_01(cP, state->planes[c].planeWidth, tP, state->planes[c].planeWidth);
				}
			}
		}
	} else {
		if (!(ty & 1)) {
			for (c = 0; c < HVQM_PLANE_COUNT; c++) {
				pmc   = &mch->colorPlanes[c];
				t_top = pmc->targetFrame
				      + ((tx >> state->planes[c].horizShift + 1) + (ty >> state->planes[c].vertShift + 1) * state->planes[c].planeWidth);
				iofsP  = state->planes[c].pixelScanOrder;
				blocks = state->planes[c].blocksPerMacroblock;
				for (i = 0; i < blocks; i++) {
					offset = *iofsP++;
					cP     = pmc->blockTop + offset;
					tP     = t_top + offset;
					_MotionComp_10(cP, state->planes[c].planeWidth, tP, state->planes[c].planeWidth);
				}
			}
		} else {
			for (c = 0; c < HVQM_PLANE_COUNT; c++) {
				pmc   = &mch->colorPlanes[c];
				t_top = pmc->targetFrame
				      + ((tx >> state->planes[c].horizShift + 1) + (ty >> state->planes[c].vertShift + 1) * state->planes[c].planeWidth);
				iofsP  = state->planes[c].pixelScanOrder;
				blocks = state->planes[c].blocksPerMacroblock;
				for (i = 0; i < blocks; i++) {
					offset = *iofsP++;
					cP     = pmc->blockTop + offset;
					tP     = t_top + offset;
					_MotionComp_11(cP, state->planes[c].planeWidth, tP, state->planes[c].planeWidth);
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
		pmc    = &mch->colorPlanes[c];
		bofsP  = ws->planes[c].blockScanOrder;
		blocks = ws->planes[c].blocksPerMacroblock;
		for (i = 0; i < blocks; i++) {
			j                         = *bofsP++;
			pmc->blockData[j].dcValue = pmc->previousDcValue
			    = pmc->previousDcValue + decodeSignedOverflowSym(&ws->dcValues[c], ws->dcRangeMin, ws->dcRangeMax);
		}
	}
}

static void reset_PB_dc(VideoState* ws, MCHandler* mch)
{
	int i;
	MCPlane* pmc;

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
		pmc                  = &mch->colorPlanes[i];
		pmc->previousDcValue = 0x7F;
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
	QuantBlock* dataP;
	QuantBlock* ydat;
	QuantBlock* udat;
	QuantBlock* vdat;
	HVQPlaneDesc* sip;
	u16* bofsP;
	int p, i, j;
	int blocks;
	CodedStream* symcode;
	CodedStream* runcode;
	s16 sym;

	cc = (mcbtype << 5) | (proctype << 4);
	if (proctype == 1) {
		for (p = 0; p < HVQM_PLANE_COUNT; p++) {
			dataP  = mc->colorPlanes[p].blockData;
			bofsP  = ws->planes[p].blockScanOrder;
			blocks = ws->planes[p].blocksPerMacroblock;
			for (i = 0; i < blocks; i++) {
				dataP[*bofsP++].basisNum = cc;
			}
		}
	} else {
		// luma
		ydat    = mc->colorPlanes[LUMA_Y_PLANE].blockData;
		sip     = &ws->planes[LUMA_INDEX];
		symcode = &ws->basisNumbers[LUMA_INDEX];
		runcode = &ws->basisRunLengths[LUMA_INDEX];
		bofsP   = sip->blockScanOrder;
		blocks  = sip->blocksPerMacroblock;
		for (i = 0; i < blocks; i++) {
			j = *bofsP++;
			if (mc->colorPlanes[LUMA_Y_PLANE].basisRunLength == 0) {
				sym = decodeHuff(symcode);
				if (sym == 0) {
					ydat[j].basisNum                             = cc;
					mc->colorPlanes[LUMA_Y_PLANE].basisRunLength = decodeHuff(runcode);
				} else {
					ydat[j].basisNum = cc | sym;
				}
			} else {
				ydat[j].basisNum = cc;
				mc->colorPlanes[LUMA_Y_PLANE].basisRunLength--;
			}
		}
		// chroma
		udat    = mc->colorPlanes[CHROMA_U_PLANE].blockData;
		vdat    = mc->colorPlanes[CHROMA_V_PLANE].blockData;
		sip     = &ws->planes[CHROMA_INDEX];
		symcode = &ws->basisNumbers[CHROMA_INDEX];
		runcode = &ws->basisRunLengths[CHROMA_INDEX];
		bofsP   = sip->blockScanOrder;
		blocks  = sip->blocksPerMacroblock;
		for (i = 0; i < blocks; i++) {
			j = *bofsP++;
			if (mc->colorPlanes[CHROMA_U_PLANE].basisRunLength == 0) {
				sym = decodeHuff(symcode);
				if (sym == 0) {
					udat[j].basisNum                               = cc;
					vdat[j].basisNum                               = cc;
					mc->colorPlanes[CHROMA_U_PLANE].basisRunLength = decodeHuff(runcode);
				} else {
					udat[j].basisNum = cc | ((sym >> 0) & 0xF);
					vdat[j].basisNum = cc | ((sym >> 4) & 0xF);
				}
			} else {
				udat[j].basisNum = cc;
				vdat[j].basisNum = cc;
				mc->colorPlanes[CHROMA_U_PLANE].basisRunLength--;
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

	mns = ws->aotQuantShift;
	avr = (decodeSignedOverflowSym(&ws->dcValues[p], ws->dcRangeMin, ws->dcRangeMax) >> ws->dcQuantShift << mns) - avr;
	scl = (decodeSignedOverflowSym(&ws->dcValues[p], ws->dcRangeMin, ws->dcRangeMax) >> ws->dcQuantShift) * mcdivTable[max - min];

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
	u8* nestP = mch->colorPlanes[LUMA_Y_PLANE].targetFrame + ((tx >> 1) - 32) + ((ty >> 1) - 16) * ws->planes[LUMA_Y_PLANE].planeWidth;
	for (c = 0; c < HVQM_PLANE_COUNT; c++) {
		MCPlane* pmc      = &mch->colorPlanes[c];
		HVQPlaneDesc* sip = &ws->planes[c];
		int plane_dx      = (tx >> sip->horizShift + 1);
		int plane_dy      = (ty >> sip->vertShift + 1);
		u8* t_top         = pmc->targetFrame + (plane_dx + plane_dy * sip->planeWidth);
		u16* bofsP        = sip->blockScanOrder;
		u32* iofsP        = sip->pixelScanOrder;
		int blocks        = sip->blocksPerMacroblock;
		for (i = 0; i < blocks; i++) {
			int offset = *iofsP++;
			int j      = *bofsP++;
			u8 nbasis  = pmc->blockData[j].basisNum & 0xF;
			// cP is a 4x4 region
			u8* cP = pmc->blockTop + offset;
			!nbasis;
			if (nbasis == 6) {
				OrgBlock(ws, cP, sip->planeWidth, c);
			} else {
				u8* tP = t_top + offset;
				if (nbasis == 0) {
					_MotionComp(cP, sip->planeWidth, tP, sip->planeWidth, (tx & 1) << 1 | (ty & 1));
				} else {
					PrediAotBlock(ws, cP, tP, sip->planeWidth, nbasis, nestP, ws->planes[LUMA_Y_PLANE].planeWidth, c,
					              (tx & 1) << 1 | (ty & 1));
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
	for (c = 0; c < HVQM_PLANE_COUNT; c++) {
		MCPlane* pmc      = &mch->colorPlanes[c];
		QuantBlock* dataP = pmc->blockData;
		int plane_width   = ws->planes[c].planeWidth;
		int w             = ws->planes[c].blocksHorizWithBorder;
		u16* bofsP        = ws->planes[c].blockScanOrder;
		u32* iofsP        = ws->planes[c].pixelScanOrder;
		int blocks        = ws->planes[c].blocksPerMacroblock;
		int i;
		for (i = 0; i < blocks; i++) {
			// dst is a 4x4 region
			int bofs = *bofsP++;
			u8* cP   = pmc->blockTop + *iofsP++;
			u8 dc    = dataP[bofs].dcValue;
			// block type:
			// 0: weighted
			// 6: literal block
			// 8: single value
			u8 nbasis = dataP[bofs].basisNum & 0xF;
			int j;
			// see also IpicBlockDec
			if (nbasis == 0) {
				u8 u_dc = dataP[bofs - w].basisNum & 0x77 ? dc : dataP[bofs - w].dcValue;
				u8 l_dc = dataP[bofs - 1].basisNum & 0x77 ? dc : dataP[bofs - 1].dcValue;
				u8 r_dc = dataP[bofs + 1].basisNum & 0x77 ? dc : dataP[bofs + 1].dcValue;
				u8 d_dc = dataP[bofs + w].basisNum & 0x77 ? dc : dataP[bofs + w].dcValue;
				WeightImBlock(cP, plane_width, dc, u_dc, d_dc, l_dc, r_dc);
			} else {
				IntraAotBlock(ws, cP, plane_width, dc, nbasis, c);
			}
		}
	}
}

static void getMVector(int* vec, CodedStream* code, int fcode)
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
static void initMCBproc(CodedStream* code, RLDecoder* flag)
{
	if (code->buf.dataPtr) {
		flag->status       = getBit(&code->buf);
		flag->remainingRun = decodeUnsignedOverflowSym(code, 0xFF);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
static int getMCBproc(CodedStream* code, RLDecoder* flag)
{
	if (flag->remainingRun == 0) {
		flag->status ^= 1;
		flag->remainingRun = decodeUnsignedOverflowSym(code, 0xFF);
	}
	flag->remainingRun--;
	return flag->status;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
static void initMCBtype(CodedStream* code, RLDecoder* flag)
{
	int value;
	if (code->buf.dataPtr) {
		flag->status = getBit(&code->buf) << 1;
		flag->status |= getBit(&code->buf);
		flag->remainingRun = decodeUnsignedOverflowSym(code, 0xFF);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
static int getMCBtype(CodedStream* code, RLDecoder* flag)
{
	const static u32 mcbtypetrans[2][3] = {
		{ 1, 2, 0 },
		{ 2, 0, 1 },
	};

	if (flag->remainingRun == 0) {
		// only three possible values, so when the value changes,
		// a single bit decides which other value to select
		// bit == 0 -> increment
		// bit == 1 -> decrement
		// then wrap to range 0..2
		flag->status       = mcbtypetrans[getBit(&code->buf)][flag->status];
		flag->remainingRun = decodeUnsignedOverflowSym(code, 0xFF);
	}
	flag->remainingRun--;
	return flag->status;
}

/*
 * --INFO--
 * Address:	80022E80
 * Size:	000430
 */
static void spread_PB_descMap(HVQM4Decoder* obj, MCHandler* mch)
{
	VideoState* ws = (VideoState*)obj->workSpace;
	struct RLDecoder proc;
	struct RLDecoder type;
	int i, j;

	initMCBproc(&ws->macroProcessor, &proc);
	initMCBtype(&ws->macroTypes, &type);
	for (j = 0; j < obj->frameHeight; j += 8) {
		setMCTop(mch);
		for (i = 0; i < obj->frameWidth; i += 8) {
			getMCBtype(&ws->macroTypes, &type);
			if (type.status == 0) {
				decode_PB_dc(ws, mch);
				decode_PB_cc(ws, mch, 0, type.status);
			} else {
				reset_PB_dc(ws, mch);
				decode_PB_cc(ws, mch, getMCBproc(&ws->macroProcessor, &proc), type.status);
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
static void BpicPlaneDec(HVQM4Decoder* seqObj, u8* lin_top, u8* forw, u8* back)
{
	VideoState* ws;
	MCHandler mch;
	int vx, vy;
	int dir;
	int i, j;
	u8 cc;
	u8 mtype;
	int d;

	ws = (VideoState*)seqObj->workSpace;
	initMCHandler(ws, &mch, lin_top, forw, back);
	spread_PB_descMap(seqObj, &mch);
	resetMCHandler(ws, &mch, lin_top);
	dir = -1;
	// MC blocks are 8x8 pixels
	for (j = 0; j < seqObj->frameHeight; j += 8) {
		setMCTop(&mch);
		for (i = 0; i < seqObj->frameWidth; i += 8) {
			cc = mch.colorPlanes[LUMA_Y_PLANE].blockData->basisNum;
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
				getMVector(&vx, &ws->motionVectorsX, ws->motionPrecision[0][dir]);
				getMVector(&vy, &ws->motionVectorsY, ws->motionPrecision[1][dir]);

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
void HVQM4InitSeqObj(HVQM4Decoder* obj, HVQM4Info* header)
{
	obj->frameWidth    = header->width;
	obj->frameHeight   = header->height;
	obj->horizSampling = header->horizSamplingRate;
	obj->vertSampling  = header->vertSamplingRate;
}

/*
 * --INFO--
 * Address:	80023730
 * Size:	000074
 */
u32 HVQM4BuffSize(HVQM4Decoder* obj)
{
	const int nblocks_h    = obj->frameWidth / 4;
	const int uv_nblocks_h = obj->horizSampling == 2 ? nblocks_h >> 1 : nblocks_h;
	const int nblocks_v    = obj->frameHeight / 4;
	const int uv_nblocks_v = obj->vertSampling == 2 ? nblocks_v >> 1 : nblocks_v;

	const int y_blocks   = (nblocks_h + 2) * (nblocks_v + 2);
	const int unblocks_v = (uv_nblocks_h + 2) * (uv_nblocks_v + 2);
	return sizeof(VideoState) + (y_blocks + unblocks_v * 2) * sizeof(u16);
}

/*
 * --INFO--
 * Address:	800237A4
 * Size:	000464
 */
void HVQM4SetBuffer(HVQM4Decoder* obj, void* buf)
{
	VideoState* ws;
	QuantBlock* bp;
	int c, i;
	QuantBlock* p;

	ws             = (VideoState*)buf;
	obj->workSpace = buf;

	setHVQPlaneDesc(obj, 0, 1, 1);
	setHVQPlaneDesc(obj, 1, obj->horizSampling, obj->vertSampling);
	setHVQPlaneDesc(obj, 2, obj->horizSampling, obj->vertSampling);

	if ((ws->isLandscape = obj->frameWidth >= obj->frameHeight) != 0) {
		ws->nestWidth  = 70;
		ws->nestHeight = 38;
	} else {
		ws->nestWidth  = 38;
		ws->nestHeight = 70;
	}

	ws->basisNumbers[LUMA_INDEX].tree = ws->basisNumbers[CHROMA_INDEX].tree = &ws->numberTree;
	ws->basisRunLengths[LUMA_INDEX].tree = ws->basisRunLengths[CHROMA_INDEX].tree = &ws->zeroRunTree;

	ws->dcValues[LUMA_Y_PLANE].tree = ws->dcValues[CHROMA_U_PLANE].tree = ws->dcValues[CHROMA_V_PLANE].tree = &ws->dcValueTree;
	ws->dcRunLengths[LUMA_Y_PLANE].tree = ws->dcRunLengths[CHROMA_U_PLANE].tree = ws->dcRunLengths[CHROMA_V_PLANE].tree
	    = &ws->zeroRunTree; // same as bsrun
	ws->scalingFactors[LUMA_Y_PLANE].tree = ws->scalingFactors[CHROMA_U_PLANE].tree = ws->scalingFactors[CHROMA_V_PLANE].tree
	    = &ws->scaleTree;
	ws->motionVectorsX.tree = ws->motionVectorsY.tree = &ws->vectorTree;
	ws->macroProcessor.tree = ws->macroTypes.tree = &ws->macroRunTree;

	bp = (QuantBlock*)((u8*)buf + sizeof(VideoState));
	for (c = 0; c < HVQM_PLANE_COUNT; c++) {
		ws->planes[c].blockBuffer = bp;
		// skip top border (stride) and left border (1)
		ws->planes[c].blockDataStart = bp + ws->planes[c].blocksHorizWithBorder + 1;
		bp += ws->planes[c].blocksHorizWithBorder * ws->planes[c].blocksVertWithBorder;

		// set horizontal borders
		p = ws->planes[c].blockBuffer;
		for (i = ws->planes[c].blocksHorizWithBorder; i > 0; i--) {
			set_border(p);
			p++;
		}

		p = bp;
		for (i = ws->planes[c].blocksHorizWithBorder; i > 0; i--) {
			p--;
			set_border(p);
		}

		// set vertical borders
		p = ws->planes[c].blockBuffer + ws->planes[c].blocksHorizWithBorder;
		for (i = ws->planes[c].blocksVertWithBorder - 2; i > 0; i--) {
			set_border(p);
			p += ws->planes[c].blocksHorizWithBorder;
		}

		p = ws->planes[c].blockBuffer + ws->planes[c].blocksHorizWithBorder * 2 - 1;
		for (i = ws->planes[c].blocksVertWithBorder - 2; i > 0; i--) {
			set_border(p);
			p += ws->planes[c].blocksHorizWithBorder;
		}
	}
}

/*
 * --INFO--
 * Address:	80023C08
 * Size:	000510
 */
void HVQM4DecodeIpic(HVQM4Decoder* obj, void* code, void* outbuf)
{
	VideoState* ws;
	u8* body;
	int i;

	ws                = (VideoState*)obj->workSpace;
	ws->aotQuantShift = read8(code, 1);
	body              = (u8*)code + 0x48;

	setCode(&ws->basisNumbers[LUMA_INDEX].buf, body + read32(code, 0x8));
	setCode(&ws->basisRunLengths[LUMA_INDEX].buf, body + read32(code, 0xC));
	setCode(&ws->basisNumbers[CHROMA_INDEX].buf, body + read32(code, 0x10));
	setCode(&ws->basisRunLengths[CHROMA_INDEX].buf, body + read32(code, 0x14));
	setCode(&ws->dcValues[LUMA_Y_PLANE].buf, body + read32(code, 0x18));
	setCode(&ws->scalingFactors[LUMA_Y_PLANE].buf, body + read32(code, 0x1C));
	setCode(&ws->aotData[LUMA_Y_PLANE], body + read32(code, 0x20));
	setCode(&ws->dcValues[CHROMA_U_PLANE].buf, body + read32(code, 0x24));
	setCode(&ws->scalingFactors[CHROMA_U_PLANE].buf, body + read32(code, 0x28));
	setCode(&ws->aotData[CHROMA_U_PLANE], body + read32(code, 0x2C));
	setCode(&ws->dcValues[CHROMA_V_PLANE].buf, body + read32(code, 0x30));
	setCode(&ws->scalingFactors[CHROMA_V_PLANE].buf, body + read32(code, 0x34));
	setCode(&ws->aotData[CHROMA_V_PLANE], body + read32(code, 0x38));
	setCode(&ws->dcRunLengths[LUMA_Y_PLANE].buf, body + read32(code, 0x3C));
	setCode(&ws->dcRunLengths[CHROMA_U_PLANE].buf, body + read32(code, 0x40));
	setCode(&ws->dcRunLengths[CHROMA_V_PLANE].buf, body + read32(code, 0x44));

	// multiple BitBufferWithTree instances share the same Tree,
	// the first BitBuffer of each group contains the Tree itself
	readTree(&ws->basisNumbers[LUMA_INDEX], 0, 0);
	readTree(&ws->basisRunLengths[LUMA_INDEX], 0, 0);
	readTree(&ws->dcValues[LUMA_Y_PLANE], 1, read8(code, 0));
	readTree(&ws->scalingFactors[LUMA_Y_PLANE], 0, 2);

	ws->dcRangeMax = +0x7F << read8(code, 0);
	ws->dcRangeMin = -0x80 << read8(code, 0);

	// 4x4 block types
	Ipic_BasisNumDec(ws);
	// 4x4 block DC values
	IpicDcvDec(ws);
	// 70x38 nest copied from upper 4 bits of DC values somewhere in the luma plane
	MakeNest(ws, read16(code, 4), read16(code, 6));

	for (i = 0; i < HVQM_PLANE_COUNT; i++) {
		IpicPlaneDec(ws, i, outbuf);
		outbuf = (u8*)outbuf + ws->planes[i].planePixelCount;
	}
}

/*
 * --INFO--
 * Address:	80024118
 * Size:	000024
 */
void HVQM4DecodePpic(HVQM4Decoder* obj, void* code, void* outbuf, void* ref1)
{
	HVQM4DecodeBpic(obj, code, outbuf, ref1, outbuf);
}

/*
 * --INFO--
 * Address:	8002413C
 * Size:	0005A8
 */
void HVQM4DecodeBpic(HVQM4Decoder* obj, void* code, void* outbuf, void* ref2, void* ref1)
{
	VideoState* ws;
	u8* body;

	ws                        = (VideoState*)obj->workSpace;
	ws->aotQuantShift         = read8(code, 1);
	ws->dcQuantShift          = read8(code, 0);
	ws->motionPrecision[0][0] = read8(code, 2);
	ws->motionPrecision[1][0] = read8(code, 3);
	ws->motionPrecision[0][1] = read8(code, 4);
	ws->motionPrecision[1][1] = read8(code, 5);
	// offsets 6 and 7 are unused

	body = (u8*)code + 0x4C;

	setCode(&ws->basisNumbers[LUMA_INDEX].buf, body + read32(code, 0x08));
	setCode(&ws->basisRunLengths[LUMA_INDEX].buf, body + read32(code, 0x0C));
	setCode(&ws->basisNumbers[CHROMA_INDEX].buf, body + read32(code, 0x10));
	setCode(&ws->basisRunLengths[CHROMA_INDEX].buf, body + read32(code, 0x14));
	setCode(&ws->dcValues[LUMA_Y_PLANE].buf, body + read32(code, 0x18));
	setCode(&ws->scalingFactors[LUMA_Y_PLANE].buf, body + read32(code, 0x1C));
	setCode(&ws->aotData[LUMA_Y_PLANE], body + read32(code, 0x20));
	setCode(&ws->dcValues[CHROMA_U_PLANE].buf, body + read32(code, 0x24));
	setCode(&ws->scalingFactors[CHROMA_U_PLANE].buf, body + read32(code, 0x28));
	setCode(&ws->aotData[CHROMA_U_PLANE], body + read32(code, 0x2C));
	setCode(&ws->dcValues[CHROMA_V_PLANE].buf, body + read32(code, 0x30));
	setCode(&ws->scalingFactors[CHROMA_V_PLANE].buf, body + read32(code, 0x34));
	setCode(&ws->aotData[CHROMA_V_PLANE], body + read32(code, 0x38));
	setCode(&ws->motionVectorsX.buf, body + read32(code, 0x3C));
	setCode(&ws->motionVectorsY.buf, body + read32(code, 0x40));
	setCode(&ws->macroTypes.buf, body + read32(code, 0x44));
	setCode(&ws->macroProcessor.buf, body + read32(code, 0x48));

	readTree(&ws->basisNumbers[LUMA_INDEX], 0, 0);
	readTree(&ws->basisRunLengths[LUMA_INDEX], 0, 0);
	readTree(&ws->dcValues[LUMA_Y_PLANE], 1, read8(code, 0));
	readTree(&ws->scalingFactors[LUMA_Y_PLANE], 0, 2);
	readTree(&ws->motionVectorsX, 1, 0);
	readTree(&ws->macroTypes, 0, 0);

	ws->dcRangeMax = +0x7F << read8(code, 0);
	ws->dcRangeMin = -0x80 << read8(code, 0);

	BpicPlaneDec(obj, outbuf, ref2, ref1);
}
