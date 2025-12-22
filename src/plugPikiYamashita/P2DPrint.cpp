#include "Colour.h"
#include "DebugLog.h"
#include "Dolphin/gx.h"
#include "P2D/Font.h"
#include "P2D/Print.h"
#include "stl/stdlib.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(31)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("P2DPrint")

P2DPrint::P2DPrint(P2DFont* font, int spacing, int leading, Colour topColour, Colour bottomColour)
{
	private_initiate(font, spacing, leading, topColour, bottomColour);
}

void P2DPrint::private_initiate(P2DFont* font, int spacing, int leading, Colour topColour, Colour bottomColour)
{
	mFont        = font;
	mFontSpacing = spacing;
	mFontLeading = 32;

	if (mFont) {
		mFontLeading = (leading != 0x80000000) ? leading : mFont->getLeading();
	}

	mFontGradientActive = true;
	mSkipEscCtrlCodes   = false;
	locate(0, 0);
	mFontTopColour    = topColour;
	mFontBottomColour = bottomColour;
	mFontTabWidth     = (mFont) ? s16(4 * mFont->getWidth()) : s16(80);

	if (mFont) {
		setFontSize();
		mFont->setGX();
	} else {
		PRINT("font is NULL.\n");
		ERROR("font is NULL\n");
		mFontWidth  = 0x80000000;
		mFontHeight = 0x80000000;
	}

	initchar();
}

void P2DPrint::locate(int x, int y)
{
	mInitX         = x;
	mInitY         = y;
	mCursorX       = x;
	mCursorY       = y;
	mCurrCharWidth = 0.0f;
}

void P2DPrint::setFontSize()
{
	if (mFont) {
		mFontWidth  = mFont->getWidth();
		mFontHeight = mFont->getHeight();
	}
}

void P2DPrint::initchar()
{
	mCharTopColour      = mFontTopColour;
	mCharBottomColour   = mFontBottomColour;
	mCharSpacing        = mFontSpacing;
	mCharLeading        = mFontLeading;
	mCharGradientActive = mFontGradientActive;
	mCharTabWidth       = mFontTabWidth;
	mCharWidth          = mFontWidth;
	mCharHeight         = mFontHeight;
}

void P2DPrint::printReturn(const char* textBuffer, int boxWidth, int boxHeight, P2DTextBoxHBinding hBind, P2DTextBoxVBinding vBind,
                           int xOffset, int yOffset)
{
	initchar();
	u32 textLen = strlen(textBuffer);

	// can't print more than 1024 characters of text at a time!
	if (textLen > 0x400) {
		textLen = 0x400;
	}

	u16 xPosBuffer[0x401];
	TSize size;

	f32 blockHeight = parse((u8*)textBuffer, textLen, boxWidth, xPosBuffer, size, false);
	blockHeight += mFontHeight;
	switch (vBind) {
	case TBOXVBIND_Top:
		break;

	case TBOXVBIND_Bottom:
		yOffset += boxHeight - int(blockHeight + 0.5f);
		break;

	case TBOXVBIND_Center:
		yOffset += (boxHeight - int(blockHeight + 0.5f)) / 2;
		break;
	}

	for (int i = 0; xPosBuffer[i] != 0xFFFF; i++) {
		switch (hBind) {
		case TBOXHBIND_Left:
			xPosBuffer[i] = 0;
			break;

		case TBOXHBIND_Right:
			xPosBuffer[i] = boxWidth - xPosBuffer[i];
			break;

		case TBOXHBIND_Center:
			xPosBuffer[i] = (boxWidth - xPosBuffer[i]) / 2;
			break;
		}
	}

	initchar();
	mCursorX += xOffset;
	mCursorY += (yOffset + mFontHeight);
	parse((u8*)textBuffer, textLen, boxWidth, xPosBuffer, size, true);
}

f32 P2DPrint::parse(const u8* textBuffer, int textLen, int maxWidth, u16* outXPosBuffer, P2DPrint::TSize& textSize, bool doDraw)
{
	const u8* textStart = textBuffer;
	u16 charNum         = 0;
	f32 startX          = mCursorX;
	f32 startY          = mCursorY;
	f32 currLineWidth   = 0.0f;
	f32 blockHeight     = 0.0f;
	int currChar        = *textBuffer++;
	f32 minX            = mCursorX;
	f32 maxX            = minX;
	f32 minY            = mCursorY;
	f32 maxY            = minY;
	GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_NONE, GX_AF_NONE);
	mFont->setGradColor(mCharTopColour, mCharBottomColour);
	mFont->loadFontTexture();

	while (true) {
		bool isDrawableChar = true;
		if (currChar == 0 || (u32)textBuffer - (u32)textStart > textLen) {
			if (!doDraw && outXPosBuffer) {
				outXPosBuffer[charNum] = (currLineWidth + 0.5f);
			}
			break;
		}

		if (!mSkipEscCtrlCodes && currChar < ASCII_PRINTABLE_MIN) {
			if (currChar == 0x1B) { // escape character
				u16 escCode = doEscapeCode(&textBuffer);
				if (escCode == 'HM') {
					if (!doDraw && outXPosBuffer) {
						outXPosBuffer[charNum] = (currLineWidth + 0.5f);
					}
					mCursorY = startY;
					mCursorX = startX;
					charNum++;
					currLineWidth = 0.0f;
				} else if (escCode != 0) {
					isDrawableChar = false;
				}
			} else {
				doCtrlCode(currChar);
				isDrawableChar = false;
				if (currChar == 0xA) { // line feed
					if (!doDraw && outXPosBuffer) {
						outXPosBuffer[charNum] = (currLineWidth + 0.5f);
					}
					charNum++;
					mCursorX      = startX;
					currLineWidth = 0.0f;
				}
			}
		} else {
			bool isMultiByteChar = false;
			if (mFont->getFontType() == OS_FONT_ENCODE_SJIS) {
				currChar = (currChar << 8) | *textBuffer++;
				if ((u32)textBuffer - (u32)textStart <= textLen) {
					isMultiByteChar = true;
				} else {
					continue;
				}
#if defined(VERSION_GPIP01_00)
			} else if (mFont->getFontType() == OS_FONT_ENCODE_UNK2 && (currChar < 0xa0 && currChar >= 0x80) && *textBuffer != 0) {
#else
			} else if (mFont->getFontType() == OS_FONT_ENCODE_UNK2 && currChar >= ASCII_PRINTABLE_MAX && *textBuffer != 0) {
#endif
				currChar = (currChar << 8) | *textBuffer++;
				if ((u32)textBuffer - (u32)textStart <= textLen) {
					isMultiByteChar = true;
				} else {
					continue;
				}
			}

			mCurrCharWidth = mFont->getWidth(currChar, mCharWidth);

			if (mCursorX + mCurrCharWidth - startX > maxWidth && mCursorX > startX) {
				textBuffer -= (isMultiByteChar) ? 2 : 1;
				mCursorY += mCharLeading;
				if (!doDraw && outXPosBuffer) {
					outXPosBuffer[charNum] = (currLineWidth + 0.5f);
				}
				charNum++;
				mCursorX       = startX;
				currLineWidth  = 0.0f;
				isDrawableChar = false;
			} else {
				if (doDraw) {
					if (outXPosBuffer) {
						f32 x = ((s16*)outXPosBuffer)[charNum] + mCursorX;
						mFont->drawChar(x, mCursorY, currChar, mCharWidth, mCharHeight);
					} else {
						mFont->drawChar(mCursorX, mCursorY, currChar, mCharWidth, mCharHeight);
					}
				}

				mCursorX += mCurrCharWidth;
			}
		}

		if (isDrawableChar) {
			if (mCursorX - startX > currLineWidth) {
				currLineWidth = mCursorX - startX;
			}
			mCursorX += mCharSpacing;
			mCurrCharWidth += mCharSpacing;
			f32 descent = f32(mCharHeight) / mFont->getHeight() * mFont->getDescent();
			if (blockHeight < mCursorY + descent) {
				blockHeight = mCursorY + descent;
			}
			if (mCursorX > maxX) {
				maxX = mCursorX;
			}
			if (mCursorX < minX) {
				minX = mCursorX;
			}
			if (mCursorY > maxY) {
				maxY = mCursorY;
			}
			if (mCursorY < minY) {
				minY = mCursorY;
			}
		}
		currChar = *textBuffer++;
	}

	if (outXPosBuffer) {
		u16 next            = charNum + 1;
		outXPosBuffer[next] = -1;
	}

	textSize.mTotalWidth      = maxX - minX;
	textSize.mTotalHeight     = mFont->getLeading() + (maxY - minY);
	textSize.mWidthFromStart  = maxX - startX;
	textSize.mHeightFromStart = mFont->getLeading() + (maxY - startY);
	if (!doDraw) {
		mCursorX = startX;
		mCursorY = startY;
	}

	return blockHeight;
}

u16 P2DPrint::doEscapeCode(const u8** textPtr)
{
	const u8* inputStr = *textPtr;
	if (**textPtr == 0 || *(*textPtr + 1) == 0) {
		return 0;
	}
	u16 code = ((*textPtr)[0] << 8) | (*textPtr)[1];
	(*textPtr) += 2;

	switch (code) {
	case 'CU':                                    // cursor up
		mCursorY -= getNumber(textPtr, 1, 0, 10); // default 1, 0 if invalid
		break;

	case 'CD':                                    // cursor down
		mCursorY += getNumber(textPtr, 1, 0, 10); // default 1, 0 if invalid
		break;

	case 'CL':                                    // cursor left
		mCursorX -= getNumber(textPtr, 1, 0, 10); // default 1, 0 if invalid
		break;

	case 'CR':                                    // cursor right
		mCursorX += getNumber(textPtr, 1, 0, 10); // default 1, 0 if invalid
		break;

	case 'LU': // current line up
		mCursorY -= mCharLeading;
		break;

	case 'LD': // current line down
		mCursorY += mCharLeading;
		break;

	case 'ST':                                                            // string terminator
		s32 width = getNumber(textPtr, mCharTabWidth, mCharTabWidth, 10); // default tab, tab if invalid
		if (width > 0) {
			mCharTabWidth = width;
		}
		break;

	case 'CA': { // char color, preserve alpha
		// set char top colour (default font top colour, no change if invalid format)
		u32ToColour(getNumber(textPtr, ColourTou32(mFontTopColour), ColourTou32(mCharTopColour), 16), &mCharTopColour);
		mFont->setGradColor(mCharTopColour, (mCharGradientActive) ? mCharBottomColour : mCharTopColour);
	} break;

	case 'GA': { // grad color, preserve alpha
		// set char bottom colour (default font bottom colour, no change if invalid format)
		u32ToColour(getNumber(textPtr, ColourTou32(mFontBottomColour), ColourTou32(mCharBottomColour), 16), &mCharBottomColour);
		mFont->setGradColor(mCharTopColour, (mCharGradientActive) ? mCharBottomColour : mCharTopColour);
	} break;

	case 'CC': { // char color, use font alpha
		// set char top colour (default font top colour, no change if invalid format)
		u32ToColour(getNumber(textPtr, ColourTou32(mFontTopColour), ColourTou32(mCharTopColour), 16), &mCharTopColour);
		u8 alpha            = mFont->getAlpha();
		mCharTopColour.a    = alpha;
		mCharBottomColour.a = alpha;
		mFont->setGradColor(mCharTopColour, (mCharGradientActive) ? mCharBottomColour : mCharTopColour);
	} break;

	case 'GC': { // grad color, use font alpha
		// set char bottom colour (default font bottom colour, no change if invalid format)
		u32ToColour(getNumber(textPtr, ColourTou32(mFontBottomColour), ColourTou32(mCharBottomColour), 16), &mCharBottomColour);
		u8 alpha            = mFont->getAlpha();
		mCharTopColour.a    = alpha;
		mCharBottomColour.a = alpha;
		mFont->setGradColor(mCharTopColour, (mCharGradientActive) ? mCharBottomColour : mCharTopColour);
	} break;

	case 'FX': {                                                    // fix x (change width)
		int width = getNumber(textPtr, mFontWidth, mCharWidth, 10); // default = font width, invalid = no change
		if (width >= 0) {
			mCharWidth = width;
		}
	} break;

	case 'FY':                                                         // fix y (change height)
		int height = getNumber(textPtr, mFontHeight, mCharHeight, 10); // default = font height, invalid = no change
		if (height >= 0) {
			mCharHeight = height;
		}
		break;

	case 'SH':                                                             // scale horizontal
		mCharSpacing = getNumber(textPtr, mFontSpacing, mCharSpacing, 10); // default = font spacing, invalid = no change
		break;

	case 'SV':                                                             // scale vertical
		mCharLeading = getNumber(textPtr, mFontLeading, mCharLeading, 10); // default = font leading, invalid = no change
		break;

	case 'GM': { // gradient marker? switch gradient on/off
		mCharGradientActive
		    = getNumber(textPtr, !mCharGradientActive, mCharGradientActive, 10) != 0; // default = switch to opposite, invalid = no change
		mFont->setGradColor(mCharTopColour, (mCharGradientActive) ? mCharBottomColour : mCharTopColour);
	} break;

	case 'HM': // ??
		break;

	default:
		(*textPtr) -= 2; // reset string
		code = 0;
		break;
	}

	return code;
}

void P2DPrint::doCtrlCode(int inputChar)
{
	switch (inputChar) {
	case 0x8: // backspace
		mCursorX -= mCurrCharWidth;
		mCurrCharWidth = 0.0f;
		break;

	case 0x9: // horizontal tab
		int width = mCharTabWidth;
		if (width > 0) {
			f32 oldX       = mCursorX;
			mCursorX       = f32(width + width * ((int)mCursorX / width));
			mCurrCharWidth = mCursorX - oldX;
		}
		break;

	case 0xA: // line feed
		mCurrCharWidth = 0.0f;
		mCursorX       = mInitX;
		mCursorY       = mCursorY + mCharLeading;
		break;

	case 0xD: // carriage return
		mCurrCharWidth = 0.0f;
		mCursorX       = mInitX;
		break;

	case 0x1C: // file separator
		mCursorX += 1.0f;
		break;

	case 0x1D: // group separator
		mCursorX -= 1.0f;
		break;

	case 0x1E: // record separator
		mCursorY -= 1.0f;
		break;

	case 0x1F: // unit separator
		mCursorY += 1.0f;
		break;
	}
}

s32 P2DPrint::getNumber(const u8** strPtr, s32 defaultValue, s32 invalidValue, int base)
{
	const char* inputStr = (const char*)*strPtr;
	s32 value            = defaultValue;

	// number needs to be enclosed with []s to be valid
	if (*inputStr != '[') {
		return defaultValue;
	}

	(*strPtr)++;
	value = 0;
	char* endStr;

	if (base == 10) { // base 10, we're expecting a straight value
		value = strtol((char*)*strPtr, &endStr, base);

	} else if (base == 16) { // base 16, we're expecting a colour, either as rgb or rgba
		value = strtoul((char*)*strPtr, &endStr, base);

		// RBGA is valid length 8 format.
		if ((u32)endStr - (u32)*strPtr != 8) {
			// only other valid format is RGB, length 6.
			if ((u32)endStr - (u32)*strPtr == 6) {
				value = (value << 8) | 0xFF; // set alpha to max
			} else {
				// invalid format!
				*strPtr = (const u8*)inputStr;
				return invalidValue;
			}
		}
	}

	// number needs to be enclosed with []s to be valid
	if (endStr[0] != ']') {
		// invalid format!
		*strPtr = (const u8*)inputStr;
		return invalidValue;
	}

	// no number found, string didn't change
	if ((char*)*strPtr == (char*)endStr) {
		// *strPtr = (const u8*)endStr + 1; // advance string
		value = defaultValue;
	}

	*strPtr = (const u8*)endStr + 1; // advance string past number (and brackets)
	return value;
}
