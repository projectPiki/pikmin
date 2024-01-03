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
	_00 = 0.0f;
	_04 = 0.0f;
}

/*
 * --INFO--
 * Address:	800CD814
 * Size:	000018
 */
void OdoMeter::start(f32 argA, f32 argB)
{
	_0C = argA;
	_04 = argA;
	_08 = argB;
	_00 = 0.0f;
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
	f32 dummy[4]; // Match stack allocation
	unknown1();
	if (_00 < 100.0f) {
#ifdef __DECOMP_NON_MATCHING
		Vector3f vec;
		vec.sub2(argA, argB);
		f32 distance = vec.length();
#else
		vec.y        = Vector3f_diffY(argA, argB);
		vec.x        = Vector3f_diffX(argA, argB);
		vec.z        = Vector3f_diffZ(argA, argB);
		f32 distance = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
#endif
		_00 += distance;
	}
	return unknown2();
}
