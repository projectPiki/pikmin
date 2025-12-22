#include "zen/ogStart.h"
#include "DebugLog.h"
#include "P2D/Graph.h"
#include "P2D/Screen.h"
#include "sysNew.h"
#include "zen/DrawCommon.h"

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
DEFINE_PRINT("TODO: Replace")

/**
 * @TODO: Documentation
 */
zen::ogScrStartMgr::ogScrStartMgr()
{
	mPressStartScreen = new P2DScreen();
	mPressStartScreen->set("screen/blo/press_s.blo", true, true, true);
	mRootPane  = mPressStartScreen->search('root', true);
	mFadeTimer = 0.0f;
	mState     = START_NULL;
	mExitState = START_Exit;
}

/**
 * @TODO: Documentation
 */
void zen::ogScrStartMgr::start()
{
	mState     = START_Oscillate;
	mFadeTimer = 0.0f;
	P2DPaneLibrary::setFamilyAlpha(mPressStartScreen, 0);
}

/**
 * @TODO: Documentation
 */
void zen::ogScrStartMgr::stop()
{
	if (mState == START_Oscillate) {
		mExitState = START_Exit;
		mState     = START_FadeOut;
		mFadeTimer = 0.0f;
	}
}

/**
 * @TODO: Documentation
 */
zen::ogScrStartMgr::StartStatus zen::ogScrStartMgr::update(Controller* controller)
{
	// not active
	if (mState == START_NULL) {
		return mState;
	}

	mPressStartScreen->update();
	mFadeTimer += gsys->getFrameTime();

	// this never gets triggered
	if (mState == START_FadeIn) {
		if (mFadeTimer < 0.25f) {
			P2DPaneLibrary::setFamilyAlpha(mPressStartScreen, (255.0f * mFadeTimer) / 0.25f);
		} else {
			P2DPaneLibrary::setFamilyAlpha(mPressStartScreen, 255);
			mState     = START_Oscillate;
			mFadeTimer = 0.0f;
		}
		return mState;
	}

	// triggered if we hit START
	if (mState == START_FadeOut) {
		if (mFadeTimer < 0.25f) {
			P2DPaneLibrary::setFamilyAlpha(mPressStartScreen, 255 - u8(255.0f * mFadeTimer / 0.25f));
		} else {
			P2DPaneLibrary::setFamilyAlpha(mPressStartScreen, 0);
			mState     = mExitState;
			mFadeTimer = 0.0f;
		}
		return mState;
	}

	// after fade out
	if (mState == START_Exit) {
		mState = START_NULL;
		return mState;
	}

	// normal state
	if (mState == START_Oscillate) {
		if (mFadeTimer > 1.0f) {
			mFadeTimer -= 1.0f;
		}

		P2DPaneLibrary::setFamilyAlpha(mPressStartScreen, 255.0f * (0.5f - 0.5f * cosf(TAU * mFadeTimer)));

		if (controller->keyClick(KBBTN_START)) {
			mExitState = START_Exit;
			mState     = START_FadeOut;
			mFadeTimer = 0.0f;
		}
	}

	return mState;
}

/**
 * @TODO: Documentation
 */
void zen::ogScrStartMgr::draw(Graphics& gfx)
{
	if (mState == START_NULL) {
		return;
	}

	P2DPerspGraph perspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	perspGraph.setPort();
	mPressStartScreen->draw(0, 0, &perspGraph);
}
