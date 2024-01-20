#include "types.h"
#include "Controller.h"
#include "system.h"
#include "dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
	OSReport("controller.cpp");
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800409B0
 * Size:	000024
 */
void Controller::reset(u32 arg1)
{
	_3C        = -1;
	_44        = false;
	_38        = arg1;
	_40        = 0;
	_20        = 0;
	mPrevInput = 0;
}

/*
 * --INFO--
 * Address:	800409D4
 * Size:	00009C
 */
void Controller::updateCont(u32 arg1)
{
	mPrevInput = _20;
	_20        = 0;

	if (!_44) {
		_20 = arg1;
	}

	_28 = _20 & ~mPrevInput;
	_2C = mPrevInput & ~_20;

	if (_40) {
		if (--_40) {
			if (_30 = _34 & _28) {
				_40 = 0;
				return;
			}
		}
	} else {
		_30 = 0;
		if (!(_34 = _28)) {
			return;
		}

		_40 = 10;
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
f32 Controller::getMainStickX() { return _45 / 74.0f; }

/*
 * --INFO--
 * Address:	80040AD4
 * Size:	000038
 */
f32 Controller::getMainStickY() { return _46 / 74.0f; }

/*
 * --INFO--
 * Address:	80040B0C
 * Size:	000038
 */
f32 Controller::getSubStickX() { return _47 / 74.0f; }

/*
 * --INFO--
 * Address:	80040B44
 * Size:	000038
 */
f32 Controller::getSubStickY() { return _48 / 74.0f; }
