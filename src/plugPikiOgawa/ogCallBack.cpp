#include "DebugLog.h"
#include "zen/TextColorCallBack.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

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
	mTextBox            = (P2DTextBox*)pane;
	mIsTransitionActive = false;
	mTransitionDuration = 1.0f;
	mElapsedTime        = 0.0f;
	mInitialCharColor   = mTextBox->getCharColor();
	mInitialGradColor   = mTextBox->getGradColor();
	mTargetCharColor    = mInitialCharColor;
	mTargetGradColor    = mInitialGradColor;
}

/*
 * --INFO--
 * Address:	80198E18
 * Size:	0000C4
 */
void zen::TextColorCallBack::setTargetColor(Colour& tCharColor, Colour& tGradColor, f32 duration)
{
	mTargetCharColor    = tCharColor;
	mTargetGradColor    = tGradColor;
	mTransitionDuration = duration;
	mElapsedTime        = 0.0f;

	if (duration > 0.0f) {
		mIsTransitionActive = true;
		mInitialCharColor   = mTextBox->getCharColor();
		mInitialGradColor   = mTextBox->getGradColor();
	} else {
		mIsTransitionActive = false;
		mInitialCharColor   = tCharColor;
		mInitialGradColor   = tGradColor;
		mTextBox->setCharColor(tCharColor);
		mTextBox->setGradColor(tGradColor);
	}
}

/*
 * --INFO--
 * Address:	80198EDC
 * Size:	000538
 */
bool zen::TextColorCallBack::invoke(P2DPane* pane)
{
	if (mIsTransitionActive) {
		Colour characterColor;
		Colour gradientColor;

		// Calculate the elapsed time and clamp it to the transition duration
		mElapsedTime += gsys->getFrameTime();
		if (mElapsedTime > mTransitionDuration) {
			mIsTransitionActive = false;
			mElapsedTime        = mTransitionDuration;
		}

		// Calculate the interpolation factor (in) and its complement (out)
		// and interpolate the character and gradient colors
		f32 in           = mElapsedTime / mTransitionDuration;
		f32 out          = 1.0f - in;
		characterColor.r = colorMerge(mTargetCharColor.r, in, mInitialCharColor.r, out);
		characterColor.g = colorMerge(mTargetCharColor.g, in, mInitialCharColor.g, out);
		characterColor.b = colorMerge(mTargetCharColor.b, in, mInitialCharColor.b, out);
		characterColor.a = mTextBox->getAlphaChar();

		gradientColor.r = colorMerge(mTargetGradColor.r, in, mInitialGradColor.r, out);
		gradientColor.g = colorMerge(mTargetGradColor.g, in, mInitialGradColor.g, out);
		gradientColor.b = colorMerge(mTargetGradColor.b, in, mInitialGradColor.b, out);
		gradientColor.a = mTextBox->getAlphaChar();

		mTextBox->setCharColor(characterColor);
		mTextBox->setGradColor(gradientColor);
	}

	return true;
}
