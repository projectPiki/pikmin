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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void zen::TextColorCallBack::setTargetColor(immut Colour& tCharColor, immut Colour& tGradColor, f32 duration)
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

/**
 * @TODO: Documentation
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
		characterColor.r = colorBlend(mTargetCharColor.r, in, mInitialCharColor.r, out);
		characterColor.g = colorBlend(mTargetCharColor.g, in, mInitialCharColor.g, out);
		characterColor.b = colorBlend(mTargetCharColor.b, in, mInitialCharColor.b, out);
		characterColor.a = mTextBox->getAlphaChar();

		gradientColor.r = colorBlend(mTargetGradColor.r, in, mInitialGradColor.r, out);
		gradientColor.g = colorBlend(mTargetGradColor.g, in, mInitialGradColor.g, out);
		gradientColor.b = colorBlend(mTargetGradColor.b, in, mInitialGradColor.b, out);
		gradientColor.a = mTextBox->getAlphaChar();

		mTextBox->setCharColor(characterColor);
		mTextBox->setGradColor(gradientColor);
	}

	return true;
}
