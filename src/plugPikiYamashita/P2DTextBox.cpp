#include "DebugLog.h"
#include "Dolphin/gx.h"
#include "P2D/Font.h"
#include "P2D/Print.h"
#include "P2D/Stream.h"
#include "P2D/TextBox.h"
#include "sysNew.h"
#include "zen/Math.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(33)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("P2DTextBox")

/**
 * @todo: Documentation
 */
void P2DTextBox::makeResident()
{
	mFont->makeResident();
}

/**
 * @todo: Documentation
 */
void P2DTextBox::loadResource()
{
	mFont = new P2DFont(mFontString);
}

/**
 * @todo: Documentation
 */
P2DTextBox::P2DTextBox(P2DPane* pane, RandomAccessStream* ramStream, u16 param3)
    : P2DPane(pane, ramStream, param3)
{
	mText = nullptr;

	P2DStream stream(ramStream);
	mFontString = stream.getResource('FONT');

	stream.getColour(&mCharColor);
	stream.getColour(&mGradColor);

	u8 hBinding = ramStream->readByte();
	mAlignmentH = (P2DTextBoxHBinding)(hBinding & ~0x80);

	u8 vBinding = ramStream->readByte();
	mAlignmentV = (P2DTextBoxVBinding)(vBinding & ~0x0);

	if (!(hBinding & 0x80)) {
		PRINT("flag is not found.\n");
		ERROR("blo data is old");
	} else {
		mSpacing    = (int)ramStream->readShort();
		mLeading    = (int)ramStream->readShort();
		mFontWidth  = (int)ramStream->readShort();
		mFontHeight = (int)ramStream->readShort();
	}

	s16 length = ramStream->readShort();

	mText = new char[length + 1];
	ramStream->read(mText, length);
	mText[length] = '\0';
	stream.align(4);

	mOffsetX = 0;
	mOffsetY = 0;
	mFont    = nullptr;
}

/**
 * @todo: Documentation
 */
void P2DTextBox::drawSelf(int param1, int param2)
{
	Matrix4f matrix;
	matrix.makeIdentity();
	drawSelf(param1, param2, &matrix);
}

/**
 * @todo: Documentation
 */
void P2DTextBox::drawSelf(int param1, int param2, immut Matrix4f* mtx)
{
	if (mFont == nullptr) {
		printTagName(false);
		ERROR("逝ってよし！\n"); // "Go away!"
	}

	P2DPrint print(mFont, mSpacing, mLeading, mCharColor, mGradColor);

	print.setFontSize(mFontWidth, mFontHeight);

	Matrix4f worldmat;
	mtx->multiplyTo(mWorldMtx, worldmat);

	GXLoadPosMtxImm(worldmat.mMtx, 0);

	print.locate(param1, param2);
	// The P2DTextBox `getWidth` and `getHeight` inlines would make sense here, but Yamashita disagrees.
	print.printReturn(mText, mBounds.getWidth(), mBounds.getHeight(), mAlignmentH, mAlignmentV, mOffsetX, mOffsetY);

	mCursorX = zen::RoundOff(print.getCursorH());
	mCursorY = zen::RoundOff(print.getCursorV());
}
