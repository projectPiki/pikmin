#include "jaudio/sample.h"
#include "Dolphin/os.h"

// unused typedefs
typedef enum DECODER_FORMAT {
	DECODE_Unk0,
} DECODER_FORMAT;

typedef struct SD_ SD_;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void Limit16(s32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000064
 */
void Jac_mixcopy(s16*, s16*, s16*, s32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void Jac_imixcopy(s16* ta, s16* tb, s16* td, s32 s)
{
	for (s; s > 0; s--) {
		*td++ = *ta++;
		*td++ = *tb++;
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void Jac_bcopyW(s16*, s16*, s32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void Jac_bcopyfast(u32* src, u32* dest, u32 size)
{
	u32 copy1, copy2, copy3, copy4;
	for (size = size / (4 * sizeof(u32)); size != 0; size--) {
		copy1   = *src++;
		copy2   = *src++;
		copy3   = *src++;
		copy4   = *src++;
		*dest++ = copy1;
		*dest++ = copy2;
		*dest++ = copy3;
		*dest++ = copy4;
	}
}

/**
 * @TODO: Documentation
 */
void Jac_bcopy(void* src, void* dest, s32 size)
{
	u8 alignedSrc, alignedDst;
	u32* usrc;
	u32* udest;

	u8* bsrc  = (u8*)src;
	u8* bdest = (u8*)dest;

	alignedSrc = (reinterpret_cast<u32>(bsrc) & 0x03);
	alignedDst = (reinterpret_cast<u32>(bdest) & 0x03);
	if ((alignedSrc) == (alignedDst) && (size & 0x0f) == 0) {
		Jac_bcopyfast((u32*)src, (u32*)dest, size);
	} else if ((alignedSrc) == (alignedDst) && (size >= 16)) {
		if ((alignedSrc) != 0) {
			for (alignedSrc = 4 - alignedSrc; (alignedSrc) != 0; alignedSrc--) {
				*bdest++ = (u32) * (bsrc)++;
				size--;
			}
		}

		udest = (u32*)bdest;
		usrc  = (u32*)bsrc;

		for (; size >= 4; size -= 4) {
			*udest++ = *usrc++;
		}

		if (size != 0) {
			bdest = (u8*)udest;
			bsrc  = (u8*)usrc;

			for (; size > 0; size--) {
				*bdest++ = (u32)*bsrc++;
			}
		}
	} else {
		for (; size > 0; size--) {
			*bdest++ = (u32)*bsrc++;
		}
	}
}

/**
 * @TODO: Documentation
 */
void Jac_bzerofast(u32* dest, u32 size)
{
	for (size = size / (4 * sizeof(u32)); size != 0; size--) {
		*dest++ = 0;
		*dest++ = 0;
		*dest++ = 0;
		*dest++ = 0;
	}
}

/**
 * @TODO: Documentation
 */
void Jac_bzero(void* dest, s32 size)
{
	u32* udest;
	u8* bdest         = (u8*)dest;
	u8 alignedbitsDst = reinterpret_cast<u32>(bdest) & 0x3;
	if (alignedbitsDst == 0) {
		if ((size & 0x1f) == 0) {
			DCZeroRange(dest, size);
			return;
		}
		if ((size & 0xf) == 0) {
			Jac_bzerofast((u32*)dest, size);
			return;
		}
	}

	if (size >= 16) {
		if (alignedbitsDst != 0) {
			for (alignedbitsDst = 4 - alignedbitsDst; alignedbitsDst != 0; alignedbitsDst--) {
				*bdest++ = 0;
				size--;
			}
		}

		udest = (u32*)bdest;
		for (; size >= 4; size -= 4) {
			*udest++ = 0;
		}

		if (size != 0) {
			bdest = (u8*)udest;
			for (; size > 0; size--) {
				*bdest++ = 0;
			}
		}
	} else {
		for (; size > 0; size--) {
			*bdest++ = 0;
		}
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00005C
 */
void SampleDecoder_Alloc(u8*, s32, DECODER_FORMAT, s32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00010C
 */
void SampleDecoder_Init(SD_*, s32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0001FC
 */
void SampleGet(SD_*, s32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00022C
 */
void SampleDecoder(SD_*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000104
 */
void DecodeADPCM(u8*, s16*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000104
 */
void DecodeADPCM2(u8*, s16*)
{
	// UNUSED FUNCTION
}
