#include "DebugLog.h"
#include "Dolphin/gx.h"
#include "P2D/Font.h"
#include "P2D/Print.h"
#include "P2D/Stream.h"
#include "P2D/TextBox.h"
#include "sysNew.h"
#include "zen/Math.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(33)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("P2DTextBox")

/*
 * --INFO--
 * Address:	801B44AC
 * Size:	000038
 */
void P2DTextBox::makeResident()
{
	mFont->makeResident();
}

/*
 * --INFO--
 * Address:	801B44E4
 * Size:	000050
 */
void P2DTextBox::loadResource()
{
	mFont = new P2DFont(mFontString);
}

/*
 * --INFO--
 * Address:	801B4534
 * Size:	00020C
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

/*
 * --INFO--
 * Address:	801B4740
 * Size:	000068
 */
void P2DTextBox::drawSelf(int param1, int param2)
{
	Matrix4f matrix;
	matrix.makeIdentity();
	drawSelf(param1, param2, &matrix);
}

/*
 * --INFO--
 * Address:	801B47A8
 * Size:	000198
 */
void P2DTextBox::drawSelf(int param1, int param2, Matrix4f* mtx)
{
	if (mFont == nullptr) {
		printTagName(false);
		ERROR("逝ってよし！");
	}

	P2DPrint print(mFont, mSpacing, mLeading, mCharColor, mGradColor);

	print.setFontSize(mFontWidth, mFontHeight);

	Matrix4f worldmat;
	mtx->multiplyTo(mWorldMtx, worldmat);

	GXLoadPosMtxImm(worldmat.mMtx, 0);

	print.locate(param1, param2);
	print.printReturn(mText, getWidth(), getHeight(), mAlignmentH, mAlignmentV, mOffsetX, mOffsetY);

	mCursorX = zen::RoundOff(print.mCursorX);
	mCursorY = zen::RoundOff(print.mCursorY);
}
