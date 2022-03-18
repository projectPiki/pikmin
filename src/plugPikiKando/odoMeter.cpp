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
	A = 0.0;
	B = 0.0;
}

/*
 * --INFO--
 * Address:	800CD814
 * Size:	000018
 */
void OdoMeter::start(float argA, float argB)
{
	D = argA;
	B = argA;
	C = argB;
	A = 0.0;
}

/*
 * --INFO--
 * Address:	800CD82C
 * Size:	000124
 * This function has some silly inlining.
 * The following, while likely fake, matches the stack.
 */
bool OdoMeter::moving(Vector3f& argA, Vector3f& argB)
{
	float dummy[4]; // useless padding variable for stack allocation match
	Vector3f vec;
	odoGsys();
	if (A < 100.0f) {
		vec.y          = vecdiffY(argA, argB);
		vec.x          = vecdiffX(argA, argB);
		vec.z          = vecdiffZ(argA, argB);
		float newthing = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
		A += newthing;
	}
	return odoRet();
}
