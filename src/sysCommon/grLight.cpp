#include "Light.h"
#include "Camera.h"

static char file[] = __FILE__;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80029A48
 * Size:	000200
 */
Light::Light()
    : CoreNode("light")
{
	_1C9 = 0;
	_1D8.set(0.0f, 0.0f, 0.0f);
	_240 = 60.0f;
	_244 = 1.0f;
	_248 = 1000.0f;
	_14  = 770;
	_24  = 3;
	_18  = 3005.0f;
	_1C  = 0.5036f;
	_28  = 2;
	_20  = 45.0f;
	_2C  = 0.0f;
	_30  = 0.0f;
	_34  = 0.99559999f;
	_38  = 1.0f;
	_3C  = 0.0f;
	_40  = 0.0f;
	_48  = 0.15f;
	_44  = 0.05f;
	_54.set(0.0f, 100.0f, 0.0f);
	_60.set(0.0f, -1.0f, 0.0f);
	_6C = 255;
	_6D = 255;
	_6E = 255;
	_6F = 255;

	setLightDistAttn(_18, _1C, _24);
}

/*
 * --INFO--
 * Address:	80029C5C
 * Size:	0000E4
 */
void Light::setLightDistAttn(f32 p1, f32 p2, int p3)
{
	_18 = p1;
	_1C = p2;
	_24 = p3;

	if (p1 < 0.0f) {
		p3 = 0;
	}
	if (p2 <= 0.0f || p2 >= 1.0f) {
		p3 = 0;
	}

	f32 val1;
	f32 val3;
	f32 val2;
	switch (p3) {
	case 1:
		val1 = 1.0f;
		val2 = 0.0f;
		val3 = (1.0f - p2) / (p2 * p1);
		break;
	case 2:
		val1 = 1.0f;
		val3 = 0.5f * (1.0f - p2) / (p2 * p1);
		val2 = 0.5f * (1.0f - p2) / (p1 * (p2 * p1));
		break;
	case 3:
		val1 = 1.0f;
		val3 = 0.0f;
		val2 = (1.0f - p2) / (p1 * (p2 * p1));
		break;
	case 0:
	default:
		val1 = 1.0f;
		val3 = 0.0f;
		val2 = 0.0f;
		break;
	}

	_2C = val1;
	_30 = val3;
	_34 = val2;
	_70 = 1;
}

/*
 * --INFO--
 * Address:	80029D40
 * Size:	000188
 */
void Light::setLightSpot(f32, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lfs       f0, -0x7D70(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x38
	  lfs       f0, -0x7D44(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x3C

	.loc_0x38:
	  li        r31, 0

	.loc_0x3C:
	  lfs       f2, -0x7D40(r2)
	  lfs       f0, -0x7D3C(r2)
	  fmuls     f1, f2, f1
	  fdivs     f1, f1, f0
	  bl        0x1F1DC8
	  cmplwi    r31, 0x6
	  bgt-      .loc_0x150
	  lis       r3, 0x8023
	  subi      r3, r3, 0x7D54
	  rlwinm    r0,r31,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lfs       f0, -0x7D38(r2)
	  lfs       f2, -0x7D64(r2)
	  fmuls     f5, f0, f1
	  lfs       f3, -0x7D70(r2)
	  b         .loc_0x15C
	  lfs       f0, -0x7D68(r2)
	  fneg      f2, f1
	  lfs       f3, -0x7D70(r2)
	  fsubs     f1, f0, f1
	  fdivs     f5, f2, f1
	  fdivs     f2, f0, f1
	  b         .loc_0x15C
	  lfs       f0, -0x7D68(r2)
	  fneg      f2, f1
	  lfs       f5, -0x7D70(r2)
	  fsubs     f1, f0, f1
	  fdivs     f2, f2, f1
	  fdivs     f3, f0, f1
	  b         .loc_0x15C
	  lfs       f0, -0x7D68(r2)
	  lfs       f3, -0x7D34(r2)
	  fsubs     f4, f0, f1
	  lfs       f0, -0x7D30(r2)
	  fsubs     f2, f1, f3
	  fmuls     f4, f4, f4
	  fmuls     f1, f1, f2
	  fdivs     f2, f3, f4
	  fdivs     f5, f1, f4
	  fdivs     f3, f0, f4
	  b         .loc_0x15C
	  lfs       f0, -0x7D68(r2)
	  lfs       f3, -0x7D2C(r2)
	  fsubs     f4, f0, f1
	  lfs       f2, -0x7D28(r2)
	  fadds     f0, f0, f1
	  fmuls     f1, f3, f1
	  fmuls     f4, f4, f4
	  fmuls     f0, f2, f0
	  fdivs     f5, f1, f4
	  fdivs     f2, f0, f4
	  fdivs     f3, f3, f4
	  b         .loc_0x15C
	  lfs       f4, -0x7D68(r2)
	  lfs       f0, -0x7D34(r2)
	  fsubs     f5, f4, f1
	  lfs       f2, -0x7D28(r2)
	  fmuls     f3, f0, f1
	  lfs       f0, -0x7D24(r2)
	  fmuls     f2, f2, f1
	  fmuls     f5, f5, f5
	  fmuls     f1, f3, f1
	  fdivs     f2, f2, f5
	  fdivs     f1, f1, f5
	  fdivs     f3, f0, f5
	  fsubs     f5, f4, f1
	  b         .loc_0x15C

	.loc_0x150:
	  lfs       f2, -0x7D70(r2)
	  lfs       f5, -0x7D68(r2)
	  fmr       f3, f2

	.loc_0x15C:
	  stfs      f5, 0x38(r30)
	  li        r0, 0x1
	  stfs      f2, 0x3C(r30)
	  stfs      f3, 0x40(r30)
	  stw       r0, 0x70(r30)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Light::setLightParallel()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000218
 */
void Light::calcLightSizes()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void Light::calcLightMapRadius()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void Light::calcLightObjRadius()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001C4
 */
void Light::refresh(Graphics&, LFlareGroup*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80029EC8
 * Size:	0000D0
 */
void Light::update()
{
	switch (_14 & 0xFF) {
	case 1:
		_2C = 1.0f;
		_30 = _34 = 0.0f;
		_38       = 1.0f;
		_3C = _40 = 0.0f;
		_70       = 1;
		break;
	case 2:
		setLightDistAttn(_18, _1C, _24);
		_38 = 1.0f;
		_3C = _40 = 0.0f;
		break;
	case 3:
		setLightSpot(_20, _28);
		_2C = 1.0f;
		_30 = _34 = 0.0f;
		break;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x14(r3)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x2
	  beq-      .loc_0x6C
	  bge-      .loc_0x34
	  cmpwi     r0, 0x1
	  bge-      .loc_0x40
	  b         .loc_0xBC

	.loc_0x34:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xBC
	  b         .loc_0x98

	.loc_0x40:
	  lfs       f1, -0x7D68(r2)
	  li        r0, 0x1
	  stfs      f1, 0x2C(r31)
	  lfs       f0, -0x7D70(r2)
	  stfs      f0, 0x34(r31)
	  stfs      f0, 0x30(r31)
	  stfs      f1, 0x38(r31)
	  stfs      f0, 0x40(r31)
	  stfs      f0, 0x3C(r31)
	  stw       r0, 0x70(r31)
	  b         .loc_0xBC

	.loc_0x6C:
	  lfs       f1, 0x18(r31)
	  mr        r3, r31
	  lfs       f2, 0x1C(r31)
	  lwz       r4, 0x24(r31)
	  bl        -0x2E8
	  lfs       f0, -0x7D68(r2)
	  stfs      f0, 0x38(r31)
	  lfs       f0, -0x7D70(r2)
	  stfs      f0, 0x40(r31)
	  stfs      f0, 0x3C(r31)
	  b         .loc_0xBC

	.loc_0x98:
	  lfs       f1, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0x28(r31)
	  bl        -0x22C
	  lfs       f0, -0x7D68(r2)
	  stfs      f0, 0x2C(r31)
	  lfs       f0, -0x7D70(r2)
	  stfs      f0, 0x34(r31)
	  stfs      f0, 0x30(r31)

	.loc_0xBC:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
