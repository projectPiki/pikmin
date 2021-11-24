#include "HmRumble.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

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
void RumbleSample::simpleStop()
{
	PADControlMotor(_08, 2);
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x2
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x8(r3)
  bl        PADControlMotor
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017D6BC
 * Size:	000088
 */
void RumbleSample::simpleStart(float param_1)
{
	_00 = param_1;
	_04 += _00;
	if (0.0f <= _00) {
		PADControlMotor(_08, 2);
	}
	else {
		if (1.0f < _04) {
			PADControlMotor(_08, 0);

		}
		else {
			_04 -= 1.0f;
			PADControlMotor(_08, 1);
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  stfs      f1, 0x0(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x0(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r3)
	  lfs       f1, 0x0(r3)
	  lfs       f0, lbl_803EB0F0@sda21(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x44
	  lwz       r3, 0x8(r3)
	  li        r4, 0x2
	  bl        PADControlMotor
	  b         .loc_0x78

	.loc_0x44:
	  lfs       f1, 0x4(r3)
	  lfs       f0, lbl_803EB0F4@sda21(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x64
	  lwz       r3, 0x8(r3)
	  li        r4, 0
	  bl        PADControlMotor
	  b         .loc_0x78

	.loc_0x64:
	  fsubs     f0, f1, f0
	  li        r4, 0x1
	  stfs      f0, 0x4(r3)
	  lwz       r3, 0x8(r3)
	  bl        PADControlMotor

	.loc_0x78:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
