#include "zen/ZenController.h"
#include "DebugLog.h"
#include "sysNew.h"

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
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
bool zen::KeyRepeat::update(Controller* controller)
{
	bool res = false;
	if (controller->keyDown(mButton) && _0C) {
		_04 += gsys->getFrameTime();
	} else {
		_04 = 0.0f;
		_08 = repeatTime;
	}

	_0C = controller->keyDown(mButton);

	if (_04 > _08) {
		res = true;
		_04 = 0.0f;
		_08 *= 0.65f;
	}

	if (controller->keyClick(mButton)) {
		res = true;
	}

	return res;
}

f32 zen::KeyRepeat::repeatTime;

/*
 * --INFO--
 * Address:	801C0310
 * Size:	000094
 */
zen::ZenController::ZenController(Controller* controller)
{
	mController  = controller;
	mRepeatInput = 0;
	for (int i = 0; i < 25; i++) {
		mKeyRepeats[i] = new KeyRepeat(1 << i);
	}

	setRepeatTime(0.5f);
}

/*
 * --INFO--
 * Address:	801C03A4
 * Size:	0000F8
 */
void zen::ZenController::update()
{
	mRepeatInput = 0;
	if (mController) {
		for (int i = 0; i < 25; i++) {
			if (mKeyRepeats[i]->update(mController)) {
				mRepeatInput |= (1 << i);
				PRINT("    %d flag up %08x\n", i, mRepeatInput);
			}
		}
	}
}
