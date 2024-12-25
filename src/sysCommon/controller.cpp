#include "types.h"
#include "Controller.h"
#include "system.h"
#include "dolphin/os.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("");

/*
 * --INFO--
 * Address:	800409B0
 * Size:	000024
 */
void Controller::reset(u32 playerNum)
{
	_3C                 = -1;
	mIsControllerFrozen = false;
	mPlayerNum          = playerNum;
	mInputDelay         = 0;
	mCurrentInput       = 0;
	mPrevInput          = 0;
}

/*
 * --INFO--
 * Address:	800409D4
 * Size:	00009C
 */
void Controller::updateCont(u32 keyStatus)
{
	mPrevInput    = mCurrentInput;
	mCurrentInput = 0;

	if (!mIsControllerFrozen) {
		mCurrentInput = keyStatus;
	}

	mInputPressed  = mCurrentInput & ~mPrevInput;
	mInputReleased = mPrevInput & ~mCurrentInput;

	if (mInputDelay) {
		if (--mInputDelay) {
			if (mButtonState = mButtonMask & mInputPressed) {
				mInputDelay = 0;
				return;
			}
		}
	} else {
		mButtonState = 0;

		if (!(mButtonMask = mInputPressed)) {
			return;
		}

		mInputDelay = 10;
	}
}

/*
 * --INFO--
 * Address:	80040A70
 * Size:	00002C
 */
void Controller::update() { gsys->mControllerMgr.updateController(this); }

/*
 * --INFO--
 * Address:	80040A9C
 * Size:	000038
 */
f32 Controller::getMainStickX() { return mMainStickX / 74.0f; }

/*
 * --INFO--
 * Address:	80040AD4
 * Size:	000038
 */
f32 Controller::getMainStickY() { return mMainStickY / 74.0f; }

/*
 * --INFO--
 * Address:	80040B0C
 * Size:	000038
 */
f32 Controller::getSubStickX() { return mSubStickX / 74.0f; }

/*
 * --INFO--
 * Address:	80040B44
 * Size:	000038
 */
f32 Controller::getSubStickY() { return mSubStickY / 74.0f; }
