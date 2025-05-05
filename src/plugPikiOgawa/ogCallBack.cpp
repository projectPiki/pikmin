#include "zen/TextColorCallBack.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("OgCallBackSection")

/*
 * --INFO--
 * Address:	80198D2C
 * Size:	0000EC
 */
zen::TextColorCallBack::TextColorCallBack(P2DPane* pane)
    : P2DPaneCallBack(pane, PANETYPE_TextBox)
{
	mTextBox = (P2DTextBox*)pane;
	_08      = false;
	_0C      = 1.0f;
	_10      = 0.0f;
	_14      = mTextBox->getCharColor();
	_18      = mTextBox->getGradColor();
	_1C      = _14;
	_20      = _18;
}

/*
 * --INFO--
 * Address:	80198E18
 * Size:	0000C4
 */
void zen::TextColorCallBack::setTargetColor(Colour& col1, Colour& col2, f32 a1)
{
	_1C = col1;
	_20 = col2;
	_0C = a1;
	_10 = 0.0f;
	if (a1 > 0.0f) {
		_08 = true;
		_14 = mTextBox->getCharColor();
		_18 = mTextBox->getGradColor();
	} else {
		_08 = false;
		_14 = col1;
		_18 = col2;
		mTextBox->setCharColor(col1);
		mTextBox->setGradColor(col2);
	}
}

/*
 * --INFO--
 * Address:	80198EDC
 * Size:	000538
 */
bool zen::TextColorCallBack::invoke(P2DPane* pane)
{
	if (_08) {
		Colour color1;
		Colour color2;

		_10 += gsys->getFrameTime();
		if (_10 > _0C) {
			_08 = false;
			_10 = _0C;
		}
		f32 in   = _10 / _0C;
		f32 out  = 1.0f - in;
		color1.r = colorMerge(_1C.r, in, _14.r, out);
		color1.g = colorMerge(_1C.g, in, _14.g, out);
		color1.b = colorMerge(_1C.b, in, _14.b, out);
		color1.a = mTextBox->getAlphaChar();
		color2.r = colorMerge(_20.r, in, _18.r, out);
		color2.g = colorMerge(_20.g, in, _18.g, out);
		color2.b = colorMerge(_20.b, in, _18.b, out);
		color2.a = mTextBox->getAlphaChar();
		mTextBox->setCharColor(color1);
		mTextBox->setGradColor(color2);
	}
	return true;
}
