#include "Controller.h"

#include "DebugLog.h"
#include "Dolphin/os.h"
#include "system.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT(nullptr);

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void Controller::update()
{
	gsys->mControllerMgr.updateController(this);
}

/**
 * @todo: Documentation
 */
f32 Controller::getMainStickX()
{
	return mMainStickX / 74.0f;
}

/**
 * @todo: Documentation
 */
f32 Controller::getMainStickY()
{
	return mMainStickY / 74.0f;
}

/**
 * @todo: Documentation
 */
f32 Controller::getSubStickX()
{
	return mSubStickX / 74.0f;
}

/**
 * @todo: Documentation
 */
f32 Controller::getSubStickY()
{
	return mSubStickY / 74.0f;
}
