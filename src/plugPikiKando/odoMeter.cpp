#include "types.h"
#include "system.h"
#include "odoMeter.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
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
 * Address:	800CD804
 * Size:	000010
 */
OdoMeter::OdoMeter()
{
	_00 = 0.0;
	_04 = 0.0;
}

/*
 * --INFO--
 * Address:	800CD814
 * Size:	000018
 */
void OdoMeter::start(float argA, float argB)
{
	_0C = argA;
	_04 = argA;
	_08 = argB;
	_00 = 0.0;
}

/*
 * --INFO--
 * Address:	800CD82C
 * Size:	000124
 * TODO
 */
bool OdoMeter::moving(Vector3f& argA, Vector3f& argB)
{
	float dummy[4]; // Match stack allocation

	unknown1();

	if (_00 < 100.0f) {
		// THIS IS VECTOR3F::DISTANCE!!! WHAT THE FUUUUUUUUUU
		Vector3f vec;
		vec.sub2(argA, argB);
		f32 distance = vec.length();
		_00 += distance;
	}

	return unknown2();
}
