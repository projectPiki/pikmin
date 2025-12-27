#include "Dolphin/os.h"
#include "Dolphin/vi.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000108
 */
void GetFontCode(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000174
 */
void Decode(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void GetFontSize(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
u16 OSGetFontEncode(void)
{
	static u16 fontEncode = 0xFFFF;
	if (fontEncode <= 1) {
		return fontEncode;
	}
	switch (__OSTVMode) {
	case VI_NTSC:
		fontEncode = (__VIRegs[VI_DTV_STAT] & 2) ? OS_FONT_ENCODE_SJIS : OS_FONT_ENCODE_ANSI;
		break;

	case VI_PAL:
	case VI_MPAL:
	case VI_DEBUG:
	case VI_DEBUG_PAL:
	case VI_EURGB60:
	default:
		fontEncode = OS_FONT_ENCODE_ANSI;
	}

	return fontEncode;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00008C
 */
void ReadROM(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00016C
 */
void ReadFont(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000EC
 */
u32 OSLoadFont(OSFontHeader* fontInfo, void* temp)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0002CC
 */
char* OSGetFontTexel(const char*, void*, s32, s32, s32*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0003B0
 */
void ExpandFontSheet(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0001A4
 */
BOOL OSInitFont(OSFontHeader* font)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000178
 */
char* OSGetFontTexture(const char* string, void** image, s32* x, s32* y, s32* width)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000108
 */
char* OSGetFontWidth(const char* string, s32* width)
{
	// UNUSED FUNCTION
}
