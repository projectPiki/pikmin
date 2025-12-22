#include "zen/DrawCountDown.h"
#include "DebugLog.h"
#include "Interface.h"
#include "P2D/Picture.h"
#include "SoundMgr.h"
#include "nlib/Math.h"
#include "sysNew.h"
#include "zen/Math.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(17)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("drawCountDown")

const int zen::DrawCountDown::countPicsNum = 11;

/**
 * @TODO: Documentation
 */
zen::DrawCountDown::DrawCountDown()
{
	mScreen       = new DrawScreen("screen/blo/count.blo", nullptr, false, false);
	mCurrentDigit = 0;
	mNumberPics   = new P2DPicture*[countPicsNum];

	char buf[8];
	for (int i = 0; i < countPicsNum; i++) {
		sprintf(buf, "cd%02d", 10 - i);
		P2DPane* pane = mScreen->getScreenPtr()->search(P2DPaneLibrary::makeTag(buf), true);
		if (pane->getTypeID() == PANETYPE_Picture) {
			mNumberPics[i] = (P2DPicture*)pane;
			mNumberPics[i]->setAlpha(0);
			mNumberPics[i]->hide();
			mNumberPics[i]->setOffset(mNumberPics[i]->getWidth() >> 1, mNumberPics[i]->getHeight() >> 1);
		} else {
			PRINT("not picture pane.\n");
			ERROR("not picture pane.\n");
		}
	}

	P2DPane* pane = mScreen->getScreenPtr()->search('gath', true);
	if (pane->getTypeID() == PANETYPE_Picture) {
		mGatherYourPikminPane = (P2DPicture*)pane;
		mGatherYourPikminPane->hide();
	} else {
		PRINT("not picture pane.\n");
		ERROR("not picture pane.\n");
	}

	mCountDownStartHour = 18.0f; // start countdown at 6pm
	mCountDownEndHour   = 19.0f; // end countdown (and day) at 7pm
	mDefaultTextAlpha   = 127;

	setRate(0.8f, 0.06f, 0.04f);
	mDefaultTextColor.set(255, 153, 0, 255);    // orange
	mPopWhiteTextColor.set(255, 255, 255, 255); // white
	mDoPlaySound = true;
}

/**
 * @TODO: Documentation
 */
void zen::DrawCountDown::setRate(f32 hiddenRate, f32 fadeInRate, f32 fadeOutRate)
{
	if (hiddenRate + fadeInRate + fadeOutRate > 1.0f) {
		PRINT("ERROR! rate over 1.0\n");
		ERROR("ERROR! rate over 1.0\n");
	}
	mHiddenRate  = hiddenRate;
	mFadeInRate  = fadeInRate;
	mFadeOutRate = fadeOutRate;
}

/**
 * @TODO: Documentation
 */
void zen::DrawCountDown::init(f32 startHour, f32 endHour, f32* clockPtr)
{
	mTimePtr            = clockPtr;
	mCountDownStartHour = startHour;
	mCountDownEndHour   = endHour;
	mCurrentDigit       = nullptr;
	mDefaultTextAlpha   = 127;
	setRate(0.8f, 0.06f, 0.04f);
	mDoPlaySound = true;
	for (int i = 0; i < countPicsNum; i++) {
		mNumberPics[i]->setAlpha(0);
		mNumberPics[i]->hide();
	}

	mGatherYourPikminPane->hide();
	mPrevDigit = -1;
}

/**
 * @TODO: Documentation
 */
void zen::DrawCountDown::update()
{
	f32 time = getClock();
	if (time >= mCountDownStartHour && time < mCountDownEndHour) {
		time           = (time - mCountDownStartHour) / (mCountDownEndHour - mCountDownStartHour);
		f32 spacing    = 1.0f / f32(countPicsNum);
		int counter    = time / spacing;                       // how many BEEPs have we done, basically
		f32 currRatio  = (time - spacing * counter) / spacing; // how far are we to the next BEEP
		f32 digitScale = counter * 0.1f + 0.7f;                // digits get bigger as we get closer to 0
		int digit      = 11 - counter;                         // what digit are we actually displaying (kinda, 11 is '10')

		// when we reach '1', send some message
		if (digit != mPrevDigit && digit == 2) {
			gameflow.mGameInterface->message(MOVIECMD_CountDownLastSecond, 0);
		}
		// don't show the Gather your Pikmin! message in challenge mode
		if (!gameflow.mIsChallengeMode) {
			mGatherYourPikminPane->show();
		} else {
			mGatherYourPikminPane->hide();
		}

		// hide by default in case we're changing digits
		if (mCurrentDigit) {
			mCurrentDigit->hide();
		}

		mCurrentDigit = mNumberPics[counter];
		mCurrentDigit->show();
		f32 t, tComp;

		// threshold 1
		if (currRatio < mHiddenRate) {
			mCurrentDigit->setAlpha(0);

			// only display gather text after the first number has popped up
			if (counter > 0) {
				mGatherYourPikminPane->setWhite(mDefaultTextColor);
				mGatherYourPikminPane->setAlpha(mDefaultTextAlpha);
			} else {
				mGatherYourPikminPane->setAlpha(0);
			}

			mDoPlaySound = true;
		} else if (currRatio < mFadeInRate + mHiddenRate) {
			t     = NMathF::sin((currRatio - mHiddenRate) * 90.0f / mFadeInRate * PI / 180.0f);
			tComp = 1.0f - t;
			mCurrentDigit->setAlpha(RoundOff(mDefaultTextAlpha * t));
			mCurrentDigit->setScale(digitScale * t, digitScale * t, 1.0f);
			mGatherYourPikminPane->setWhite(Colour(colorMerge(mPopWhiteTextColor.r, t, mDefaultTextColor.r, tComp),
			                                       colorMerge(mPopWhiteTextColor.g, t, mDefaultTextColor.g, tComp),
			                                       colorMerge(mPopWhiteTextColor.b, t, mDefaultTextColor.b, tComp), 255));
			if (counter > 0) {
				mGatherYourPikminPane->setAlpha(mDefaultTextAlpha);
			} else {
				mGatherYourPikminPane->setAlpha(RoundOff(mDefaultTextAlpha * t));
			}

			if (mDoPlaySound) {
				SeSystem::playSysSe(SYSSE_COUNTDOWN);
				mDoPlaySound = false;
			}

		} else if (currRatio > 1.0f - mFadeOutRate) {
			t     = (currRatio - (1.0f - mFadeOutRate)) / mFadeOutRate;
			tComp = 1.0f - t;
			mCurrentDigit->setAlpha(RoundOff(mDefaultTextAlpha * tComp));
			mCurrentDigit->setScale(digitScale * (t * 0.5f + 1.0f), digitScale * (t * 0.5f + 1.0f), 1.0f);
			mGatherYourPikminPane->setWhite(Colour(colorMerge(mPopWhiteTextColor.r, tComp, mDefaultTextColor.r, t),
			                                       colorMerge(mPopWhiteTextColor.g, tComp, mDefaultTextColor.g, t),
			                                       colorMerge(mPopWhiteTextColor.b, tComp, mDefaultTextColor.b, t), 255));
			if (counter == 10) {
				u8 alpha = RoundOff(mDefaultTextAlpha * (1.0f - t));
				mGatherYourPikminPane->setAlpha(alpha);
			} else {
				mGatherYourPikminPane->setAlpha(mDefaultTextAlpha);
			}
		} else {
			mCurrentDigit->setAlpha(mDefaultTextAlpha);
			mCurrentDigit->setScale(digitScale);
			mGatherYourPikminPane->setWhite(mPopWhiteTextColor);
			mGatherYourPikminPane->setAlpha(mDefaultTextAlpha);
		}

		mPrevDigit = digit;

	} else {
		// we're not in countdown range, hide everything
		mGatherYourPikminPane->hide();
		for (int i = 0; i < countPicsNum; i++) {
			mNumberPics[i]->hide();
		}
	}

	mScreen->update();
}

/**
 * @TODO: Documentation
 */
void zen::DrawCountDown::draw(Graphics&)
{
	mScreen->draw();
}
