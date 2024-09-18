#include "RumbleMgr.h"
#include "Dolphin/pad.h"

/*
 * --INFO--
 * Address:	8017D680
 * Size:	000014
 */
RumbleSample::RumbleSample(int chan)
{
	_00      = 0.0f;
	_04      = 0.0f;
	mChannel = chan;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void RumbleSample::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017D694
 * Size:	000028
 */
void RumbleSample::simpleStop() { PADStopMotorHard(mChannel); }

/*
 * --INFO--
 * Address:	8017D6BC
 * Size:	000088
 */
void RumbleSample::simpleStart(f32 param_1)
{
	_00 = param_1;
	_04 += _00;
	if (_00 <= 0.0f) {
		PADStopMotorHard(mChannel);

	} else if (_04 < 1.0f) {
		PADStopMotor(mChannel);

	} else {
		_04 -= 1.0f;
		PADStartMotor(mChannel);
	}
}
