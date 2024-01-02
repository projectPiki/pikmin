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
	Vector3f vec;
	float dummy[4]; // Match stack allocation
	unknown1();
	if (_00 < 100.0f) {
		vec.y          = Vector3f_diffY(argA, argB);
		vec.x          = Vector3f_diffX(argA, argB);
		vec.z          = Vector3f_diffZ(argA, argB);
		float distance = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
		_00 += distance;
	
	}
	return unknown2();

}
