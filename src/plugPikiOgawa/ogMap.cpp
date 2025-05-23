#include "zen/ogMap.h"
#include "zen/ogSub.h"
#include "P2D/Screen.h"
#include "P2D/TextBox.h"
#include "P2D/Graph.h"
#include "std/Math.h"
#include "sysNew.h"
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
DEFINE_PRINT("")

/*
 * --INFO--
 * Address:	80182DE0
 * Size:	0000D4
 */
void zen::ogScrMapMgr::start(s16 p1)
{
	mMode  = p1;
	mState = Initialising;

	if (mMode == Initialising) {
		mCurrentScreen = mTest2Screen;
		mPic1          = mCurrentScreen->search('pic1', true);
		mPic1PositionX = mPic1->getPosH();
		mPic1PositionY = mPic1->getPosV();
		mTypingTextMgr->start();

	} else {
		mCurrentScreen = mTestScreen;
	}

	mScreenPosX = 0;
	mScreenPosY = 0;
}

/*
 * --INFO--
 * Address:	80182EB4
 * Size:	0001CC
 */
zen::ogScrMapMgr::ogScrMapMgr()
{
	mTestScreen = new P2DScreen();
	mTestScreen->set("screen/blo/test.blo", true, true, true);

	mTest2Screen = new P2DScreen();
	mTest2Screen->set("screen/blo/test2.blo", true, true, true);

	P2DTextBox* textBox = static_cast<P2DTextBox*>(mTest2Screen->search('tx00', true));
	mTypingTextMgr      = new TypingTextMgr(textBox);

	mCursorPane = (P2DPicture*)mTest2Screen->search('curs', true);
	mFrameTimer = 0.0f;
	mState      = Inactive;
}

/*
 * --INFO--
 * Address:	80183080
 * Size:	00029C
 */
zen::ogScrMapMgr::MapStatus zen::ogScrMapMgr::update(Controller* controller)
{
	if (mState == Inactive) {
		return mState;
	}

	mFrameTimer += gsys->getFrameTime();
	mCurrentScreen->update();

	if (mState == Initialising) {
		mState = Active;
		return mState;
	}

	if (mState == Exiting) {
		mState = Finished;
		return mState;
	}

	if (mState == Finished) {
		mState = Inactive;
		return mState;
	}

	if (controller->keyClick(KBBTN_B)) {
		mState = Exiting;
	}

	if (mMode == Initialising) {
		mTypingTextMgr->update();
		mTypingTextMgr->transCursor(mCursorPane);

		f32 scale  = sinf(fmod(mFrameTimer, 1.0f) * TAU) + 1.0f;
		int width  = mPic1->getWidth();
		int height = mPic1->getHeight();
		mPic1->setScale(scale);
		mPic1->setOffset(width / 2, height / 2);
		mPic1->move(mPic1PositionX, mPic1PositionY);

		if (controller->keyDown(KBBTN_MSTICK_LEFT)) {
			mPic1PositionX -= 4.0f;
		}

		if (controller->keyDown(KBBTN_MSTICK_RIGHT)) {
			mPic1PositionX += 4.0f;
		}

		if (controller->keyDown(KBBTN_MSTICK_UP)) {
			mPic1PositionY -= 4.0f;
		}

		if (controller->keyDown(KBBTN_MSTICK_DOWN)) {
			mPic1PositionY += 4.0f;
		}
	}

	mCurrentScreen->move(mScreenPosX, mScreenPosY);

	if (controller->keyDown(KBBTN_CSTICK_LEFT)) {
		mScreenPosX -= 4;
	}

	if (controller->keyDown(KBBTN_CSTICK_RIGHT)) {
		mScreenPosX += 4;
	}

	if (controller->keyDown(KBBTN_CSTICK_UP)) {
		mScreenPosY -= 4;
	}

	if (controller->keyDown(KBBTN_CSTICK_DOWN)) {
		mScreenPosY += 4;
	}

	return mState;
}

/*
 * --INFO--
 * Address:	8018337C
 * Size:	00008C
 */
void zen::ogScrMapMgr::draw(Graphics& gfx)
{
	if (mState == Inactive) {
		return;
	}

	P2DPerspGraph perspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	perspGraph.setPort();
	mCurrentScreen->draw(0, 0, &perspGraph);
}
