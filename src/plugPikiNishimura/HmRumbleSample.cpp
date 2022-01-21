#include "HmRumble.h"

/*
 * --INFO--
 * Address:	8017D680
 * Size:	000014
 */
RumbleSample::RumbleSample(int param_1)
{
	_00 = 0.0f;
	_04 = 0.0f;
	_08 = param_1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
// void RumbleSample::init()
// {
// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	8017D694
 * Size:	000028
 */
void RumbleSample::simpleStop() { PADControlMotor(_08, 2); }

/*
 * --INFO--
 * Address:	8017D6BC
 * Size:	000088
 */
void RumbleSample::simpleStart(float param_1)
{
	_00 = param_1;
	_04 += _00;
	if (_00 <= 0.0f) {
		PADControlMotor(_08, 2);
	} else if (_04 < 1.0f) {
		PADControlMotor(_08, 0);
	} else {
		_04 -= 1.0f;
		PADControlMotor(_08, 1);
	}
}
