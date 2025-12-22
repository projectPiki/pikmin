#include "zen/AlphaWipe.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "zen/Math.h"

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
DEFINE_PRINT("alphaWipe")

/**
 * @TODO: Documentation
 */
zen::AlphaWipe::AlphaWipe()
{
	mState          = STATE_Inactive;
	mFlags          = 0;
	mWipeType       = TYPE_Normal;
	mStartWipeTimer = 0.0f;
	mWipeDuration   = 1.0f;
	mStartColor.set(255, 255, 255, 255);
	mEndColor.set(255, 255, 255, 255);
}

/**
 * @TODO: Documentation
 */
void zen::AlphaWipe::update()
{
	if (mState == STATE_Active) {
		mStartWipeTimer += gsys->getFrameTime();
		mEndWipeTimer += gsys->getFrameTime();

		f32 startFactor;
		if (mStartWipeTimer > mWipeDuration) {
			mStartWipeTimer = mWipeDuration;
			startFactor     = 1.0f;
		} else {
			startFactor = mStartWipeTimer / mWipeDuration;
		}

		f32 endFactor;
		if (mEndWipeTimer > mWipeDuration) {
			mEndWipeTimer = mWipeDuration;
			endFactor     = 1.0f;
		} else if (mEndWipeTimer < 0.0f) {
			endFactor = 0.0f;
		} else {
			endFactor = mEndWipeTimer / mWipeDuration;
		}

		f32 startAlpha;
		f32 endAlpha;
		if (mFlags & DIR_Increasing) {
			startAlpha = 255.0f * startFactor;
			endAlpha   = 255.0f * endFactor;
			if (endFactor == 1.0f) {
				// we're done increasing, time to decrease
				mFlags &= ~DIR_Increasing;
				mFlags |= DIR_Decreasing;
				mStartWipeTimer = 0.0f;
				mEndWipeTimer   = -mDelayPeriod;
			}
		} else if (mFlags & DIR_Decreasing) {
			startAlpha = (1.0f - startFactor) * 255.0f;
			endAlpha   = (1.0f - endFactor) * 255.0f;

			if (endFactor == 1.0f) {
				// we've increased and decreased, end the wipe
				mFlags &= ~DIR_Decreasing;
				mState = STATE_Inactive;
			}
		}

		switch (mWipeType) {
		case TYPE_Normal:
			mStartColor.a = zen::RoundOff(startAlpha);
			mEndColor.a   = zen::RoundOff(endAlpha);
			break;
		case TYPE_Reverse:
			// flip the color order
			mStartColor.a = zen::RoundOff(endAlpha);
			mEndColor.a   = zen::RoundOff(startAlpha);
			break;
		}
	}
}

/**
 * @TODO: Documentation
 */
void zen::AlphaWipe::draw(Graphics& gfx)
{
	if (mState == STATE_Active) {
		Matrix4f mtx;
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setColour(mStartColor, true);
		gfx.setAuxColour(mEndColor);
		gfx.fillRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	}
}

/**
 * @TODO: Documentation
 */
void zen::AlphaWipe::start(f32 totalDuration, f32 delay, zen::AlphaWipe::typeFlag type)
{
	totalDuration *= 0.5f; // have to increase AND decrease
	mState          = STATE_Active;
	mFlags          = DIR_Increasing;
	mStartWipeTimer = 0.0f;
	mWipeDuration   = totalDuration;
	if (delay < 0.0f) {
		delay = 0.0f;
	}
	mDelayPeriod   = delay;
	mEndWipeTimer  = -delay;
	mTotalDuration = totalDuration;
	mWipeType      = type;
	mStartColor.a  = 0;
	mEndColor.a    = 0;
}
