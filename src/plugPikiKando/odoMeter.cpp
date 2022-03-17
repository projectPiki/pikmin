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
 */
bool OdoMeter::moving(Vector3f& argA, Vector3f& argB)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x60(r1)
	  lfs       f1, 0x4(r3)
	  lfs       f0, -0x69B8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x24
	  lwz       r6, 0x2DEC(r13)
	  lfs       f0, 0x28C(r6)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4(r3)

	.loc_0x24:
	  lfs       f1, 0x0(r3)
	  lfs       f0, -0x69B4(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xDC
	  lfs       f3, 0x4(r4)
	  lfs       f2, 0x4(r5)
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0x0(r5)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x8(r4)
	  fsubs     f4, f1, f0
	  lfs       f0, 0x8(r5)
	  fmuls     f1, f3, f3
	  fsubs     f3, f2, f0
	  lfs       f0, -0x69B8(r2)
	  fmuls     f2, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xD0
	  fsqrte    f1, f4
	  lfd       f3, -0x69B0(r2)
	  lfd       f2, -0x69A8(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x38(r1)
	  lfs       f4, 0x38(r1)

	.loc_0xD0:
	  lfs       f0, 0x0(r3)
	  fadds     f0, f0, f4
	  stfs      f0, 0x0(r3)

	.loc_0xDC:
	  lfs       f0, 0x4(r3)
	  lfs       f2, -0x69B8(r2)
	  fcmpo     cr0, f0, f2
	  cror      2, 0, 0x2
	  bne-      .loc_0x118
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x8(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x10C
	  stfs      f2, 0x0(r3)
	  li        r3, 0
	  b         .loc_0x11C

	.loc_0x10C:
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f2, 0x0(r3)

	.loc_0x118:
	  li        r3, 0x1

	.loc_0x11C:
	  addi      r1, r1, 0x60
	  blr
	*/
}
