#include "types.h"

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
 * Address:	........
 * Size:	000028
 */
void Creature::startFixPosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008A040
 * Size:	000010
 */
void Creature::finishFixPosition()
{
	/*
	.loc_0x0:
	  lwz       r0, 0xC8(r3)
	  rlwinm    r0,r0,0,11,9
	  stw       r0, 0xC8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A050
 * Size:	000048
 */
void Creature::isTerrible()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0x1
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x37
	  beq-      .loc_0x30
	  bl        0x238
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x30
	  li        r31, 0

	.loc_0x30:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A098
 * Size:	0000D8
 */
void Creature::load(RandomAccessStream&, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  lwz       r3, 0x6C(r3)
	  bl        0xA978
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x90
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x94(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x98(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x9C(r29)

	.loc_0x90:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x54(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A170
 * Size:	0000D8
 */
void Creature::save(RandomAccessStream&, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  lwz       r3, 0x6C(r3)
	  bl        0xA8A0
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x90
	  mr        r3, r30
	  lfs       f1, 0x94(r29)
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lfs       f1, 0x98(r29)
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lfs       f1, 0x9C(r29)
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x90:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A248
 * Size:	00001C
 */
void Creature::getCollidePlatformCreature()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x280(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x14
	  lwz       r3, 0x28(r3)
	  blr

	.loc_0x14:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A264
 * Size:	000044
 */
void Creature::getCollidePlatformNormal()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x284(r4)
	  cmplwi    r4, 0
	  bne-      .loc_0x28
	  lfs       f0, -0x5E48(r13)
	  stfs      f0, 0x0(r3)
	  lfs       f0, -0x5E44(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x5E40(r13)
	  stfs      f0, 0x8(r3)
	  blr

	.loc_0x28:
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A2A8
 * Size:	000024
 */
void Creature::isBoss()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x27
	  blt-      .loc_0x1C
	  cmpwi     r0, 0x32
	  bgt-      .loc_0x1C
	  li        r3, 0x1
	  blr

	.loc_0x1C:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A2CC
 * Size:	000048
 */
void Creature::enableStick()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x220(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  bl        -0x79C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x34
	  lwz       r3, 0x220(r31)
	  bl        -0x162C

	.loc_0x34:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A314
 * Size:	000048
 */
void Creature::disableStick()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x220(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  bl        -0x7E4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x34
	  lwz       r3, 0x220(r31)
	  bl        -0x1640

	.loc_0x34:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A35C
 * Size:	000070
 */
void Creature::getNearestCollPart(Vector3f&, unsigned long)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  lwz       r3, 0x220(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  bl        -0x83C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x50
	  lwz       r3, 0x220(r29)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  bl        -0xC34
	  b         .loc_0x54

	.loc_0x50:
	  li        r3, 0

	.loc_0x54:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A3CC
 * Size:	000060
 */
void Creature::getRandomCollPart(unsigned long)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x220(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  bl        -0x8A4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x44
	  lwz       r3, 0x220(r30)
	  mr        r4, r31
	  bl        -0xB1C
	  b         .loc_0x48

	.loc_0x44:
	  li        r3, 0

	.loc_0x48:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A42C
 * Size:	0000D8
 */
void Creature::getBoundingSphereCentre()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x220(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xA8
	  mr        r3, r0
	  bl        -0x908
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA8
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x36
	  beq-      .loc_0x84
	  cmpwi     r0, 0
	  beq-      .loc_0x84
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x84
	  addi      r3, r31, 0x40
	  bl        0x9D08
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x84
	  lfs       f0, 0x94(r31)
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x9C(r31)
	  stfs      f0, 0x8(r30)
	  b         .loc_0xC0

	.loc_0x84:
	  lwz       r3, 0x220(r31)
	  bl        -0xDAC
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x8(r30)
	  b         .loc_0xC0

	.loc_0xA8:
	  mr        r4, r31
	  lwz       r12, 0x0(r31)
	  mr        r3, r30
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0xC0:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A504
 * Size:	0000B0
 */
void Creature::getBoundingSphereRadius()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x220(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x84
	  bl        -0x9D8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x84
	  lwz       r3, 0x220(r30)
	  bl        -0xE30
	  lwz       r0, 0x6C(r30)
	  addi      r31, r3, 0
	  cmpwi     r0, 0x36
	  beq-      .loc_0x7C
	  cmpwi     r0, 0
	  beq-      .loc_0x7C
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x7C
	  addi      r3, r30, 0x40
	  bl        0x9C2C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7C
	  lfs       f1, -0x7588(r2)
	  lfs       f0, 0x0(r31)
	  fmuls     f1, f1, f0
	  b         .loc_0x98

	.loc_0x7C:
	  lfs       f1, 0x0(r31)
	  b         .loc_0x98

	.loc_0x84:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl

	.loc_0x98:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A5B4
 * Size:	000038
 */
void Creature::playEventSound(Creature*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x28
	  lwz       r3, 0x2C(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x28
	  mr        r4, r5
	  bl        0x197F8

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A5EC
 * Size:	000038
 */
void Creature::stopEventSound(Creature*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x28
	  lwz       r3, 0x2C(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x28
	  mr        r4, r5
	  bl        0x19894

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void Creature::insideSphere(Sphere&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008A624
 * Size:	0000F4
 */
void Creature::getCentre()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  mr        r30, r4
	  stw       r29, 0x44(r1)
	  addi      r29, r3, 0
	  lwz       r0, 0x220(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xC0
	  mr        r3, r0
	  bl        -0xB04
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC0
	  lis       r4, 0x6365
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x6E74
	  bl        -0xF5C
	  lwz       r0, 0x6C(r30)
	  addi      r31, r3, 0
	  cmpwi     r0, 0x36
	  beq-      .loc_0x9C
	  cmpwi     r0, 0
	  beq-      .loc_0x9C
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x9C
	  addi      r3, r30, 0x40
	  bl        0x9AF8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9C
	  lfs       f0, 0x94(r30)
	  stfs      f0, 0x0(r29)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x4(r29)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x8(r29)
	  b         .loc_0xD8

	.loc_0x9C:
	  cmplwi    r31, 0
	  beq-      .loc_0xC0
	  lfs       f0, 0x4(r31)
	  stfs      f0, 0x0(r29)
	  lfs       f0, 0x8(r31)
	  stfs      f0, 0x4(r29)
	  lfs       f0, 0xC(r31)
	  stfs      f0, 0x8(r29)
	  b         .loc_0xD8

	.loc_0xC0:
	  lfs       f1, 0x98(r30)
	  lfs       f2, 0x9C(r30)
	  lfs       f0, 0x94(r30)
	  stfs      f0, 0x0(r29)
	  stfs      f1, 0x4(r29)
	  stfs      f2, 0x8(r29)

	.loc_0xD8:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A718
 * Size:	000074
 */
void Creature::getCentreSize()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x220(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  bl        -0xBE8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x4C
	  lis       r4, 0x6365
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x6E74
	  bl        -0x1040
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  lfs       f1, 0x0(r3)
	  b         .loc_0x60

	.loc_0x4C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl

	.loc_0x60:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A78C
 * Size:	00006C
 */
void Creature::getStandType()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x28C(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x3C
	  lwz       r3, 0x280(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  lwz       r0, 0x28(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x2C
	  li        r3, 0x1
	  blr

	.loc_0x2C:
	  li        r3, 0x2
	  blr

	.loc_0x34:
	  li        r3, 0x3
	  blr

	.loc_0x3C:
	  lwz       r3, 0x280(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x64
	  lwz       r0, 0x28(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C
	  li        r3, 0x1
	  blr

	.loc_0x5C:
	  li        r3, 0x2
	  blr

	.loc_0x64:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A7F8
 * Size:	00005C
 */
SearchData::SearchData()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  stw       r31, 0x0(r3)
	  stw       r31, 0x8(r3)
	  lwz       r3, 0x0(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  bl        0x59B44
	  stw       r31, 0x0(r30)

	.loc_0x38:
	  lfs       f0, -0x7570(r2)
	  mr        r3, r30
	  stfs      f0, 0x4(r30)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A854
 * Size:	000020
 */
void Creature::getGeneratorID()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x64(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x14
	  lwz       r3, 0x58(r3)
	  blr

	.loc_0x14:
	  lis       r3, 0x6E75
	  addi      r3, r3, 0x6C6C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A874
 * Size:	000028
 */
void Creature::stimulate(Interaction&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x6C(r3)
	  bl        0xA1B4
	  li        r3, 0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A89C
 * Size:	000138
 */
void Creature::setStateGrabbed(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x2C(r1)
	  mr        r29, r3
	  lwz       r3, 0x2A8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x11C

	.loc_0x34:
	  beq-      .loc_0x48
	  beq-      .loc_0x48
	  bl        0x59A94
	  li        r0, 0
	  stw       r0, 0x2A8(r29)

	.loc_0x48:
	  stw       r30, 0x2A8(r29)
	  lwz       r3, 0x2A8(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  bl        0x59A68

	.loc_0x5C:
	  lwz       r0, 0x2AC(r30)
	  addi      r31, r30, 0x2AC
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x84
	  bl        0x59A58
	  li        r0, 0
	  stw       r0, 0x0(r31)

	.loc_0x84:
	  stw       r29, 0x0(r31)
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x98
	  bl        0x59A2C

	.loc_0x98:
	  lwz       r5, 0xE0(r29)
	  addi      r4, r1, 0x18
	  lwz       r0, 0xE4(r29)
	  addi      r3, r29, 0x100
	  stw       r5, 0xF0(r29)
	  stw       r0, 0xF4(r29)
	  lwz       r5, 0xE8(r29)
	  lwz       r0, 0xEC(r29)
	  stw       r5, 0xF8(r29)
	  stw       r0, 0xFC(r29)
	  lfs       f0, -0x5E3C(r13)
	  lfs       f1, -0x5E38(r13)
	  stfs      f0, 0x18(r1)
	  lfs       f0, -0x5E34(r13)
	  stfs      f1, 0x1C(r1)
	  stfs      f0, 0x20(r1)
	  bl        -0x5268C
	  lfs       f0, -0x7584(r2)
	  stfs      f0, 0x110(r29)
	  lwz       r0, 0x6C(r29)
	  cmpwi     r0, 0xE
	  beq-      .loc_0x118
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl

	.loc_0x118:
	  li        r3, 0x1

	.loc_0x11C:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008A9D4
 * Size:	000068
 */
void Creature::resetStateGrabbed()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x2A8(r3)
	  addi      r31, r3, 0x2AC
	  lwz       r3, 0x2AC(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  bl        0x5996C
	  li        r0, 0
	  stw       r0, 0x0(r31)

	.loc_0x38:
	  lwz       r3, 0x2A8(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  bl        0x59954
	  li        r0, 0
	  stw       r0, 0x2A8(r30)

	.loc_0x50:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008AA3C
 * Size:	000048
 */
void Creature::turnTo(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lfs       f3, 0x0(r4)
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x8(r4)
	  lfs       f0, 0x9C(r3)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x190F90
	  stfs      f1, 0xA0(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void Creature::adjustDistance(Vector3f&, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008AA84
 * Size:	000180
 */
void Creature::init()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r30, 0x1B8
	  bl        0x593F4
	  addi      r3, r30, 0x114
	  bl        -0x4CCEC
	  addi      r3, r30, 0x228
	  bl        -0x4CCF4
	  lfs       f1, -0x7584(r2)
	  lis       r4, 0xFFF0
	  lis       r3, 0xFFFE
	  stfs      f1, 0xE0(r30)
	  li        r31, 0
	  li        r5, -0x1
	  stfs      f1, 0xE4(r30)
	  subi      r4, r4, 0x2901
	  subi      r0, r3, 0x21
	  stfs      f1, 0xE8(r30)
	  mr        r3, r30
	  lfs       f0, -0x756C(r2)
	  stfs      f0, 0xEC(r30)
	  stb       r31, 0x60(r30)
	  stw       r31, 0xC8(r30)
	  stw       r5, 0x1A0(r30)
	  lwz       r5, 0xC8(r30)
	  rlwinm    r5,r5,0,13,11
	  stw       r5, 0xC8(r30)
	  stw       r31, 0x21C(r30)
	  lwz       r5, 0xC8(r30)
	  ori       r5, r5, 0x1000
	  stw       r5, 0xC8(r30)
	  lwz       r5, 0xC8(r30)
	  and       r4, r5, r4
	  stw       r4, 0xC8(r30)
	  stfs      f1, 0xD0(r30)
	  stw       r31, 0x2A8(r30)
	  stw       r31, 0x2AC(r30)
	  lwz       r4, 0xC8(r30)
	  and       r0, r4, r0
	  stw       r0, 0xC8(r30)
	  bl        0x5981C
	  stb       r31, 0x2B4(r30)
	  li        r0, -0x4D1
	  lwz       r3, 0xC8(r30)
	  ori       r3, r3, 0xC
	  stw       r3, 0xC8(r30)
	  lwz       r3, 0xC8(r30)
	  and       r0, r3, r0
	  stw       r0, 0xC8(r30)
	  lfs       f0, -0x5E30(r13)
	  stfs      f0, 0xBC(r30)
	  lfs       f0, -0x5E2C(r13)
	  stfs      f0, 0xC0(r30)
	  lfs       f0, -0x5E28(r13)
	  stfs      f0, 0xC4(r30)
	  lfs       f0, -0x5E24(r13)
	  stfs      f0, 0x1AC(r30)
	  lfs       f0, -0x5E20(r13)
	  stfs      f0, 0x1B0(r30)
	  lfs       f0, -0x5E1C(r13)
	  stfs      f0, 0x1B4(r30)
	  stw       r31, 0x184(r30)
	  stw       r31, 0x188(r30)
	  stw       r31, 0x190(r30)
	  stw       r31, 0x18C(r30)
	  stw       r31, 0x180(r30)
	  lwz       r0, 0xC8(r30)
	  rlwinm    r0,r0,0,18,15
	  stw       r0, 0xC8(r30)
	  stw       r31, 0x154(r30)
	  stw       r31, 0x158(r30)
	  lfs       f0, -0x7584(r2)
	  stfs      f0, 0x15C(r30)
	  stw       r31, 0x164(r30)
	  stw       r31, 0x160(r30)
	  lwz       r0, 0x3044(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x168
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x15C
	  li        r0, 0x1
	  stb       r0, 0x170(r30)

	.loc_0x15C:
	  addi      r3, r30, 0x168
	  lwz       r4, 0x3044(r13)
	  bl        0x1A8BC

	.loc_0x168:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008AC04
 * Size:	000064
 */
void Creature::init(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        -0x19C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stw       r0, 0x1A4(r30)
	  lwz       r0, 0xC8(r30)
	  rlwinm    r0,r0,0,17,15
	  stw       r0, 0xC8(r30)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Creature::getAtariType()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008AC68
 * Size:	000034
 */
void Creature::resetPosition(Vector3f&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0x94(r3)
	  stw       r0, 0x98(r3)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x9C(r3)
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0x1AC(r3)
	  stw       r0, 0x1B0(r3)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x1B4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008AC9C
 * Size:	000044
 */
void Creature::detachGenerator()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x64(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x30
	  mr        r4, r31
	  bl        0x514DC
	  li        r0, 0
	  stw       r0, 0x64(r31)

	.loc_0x30:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008ACE0
 * Size:	0001F8
 */
void Creature::kill(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x64(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  mr        r4, r31
	  bl        0x51480
	  li        r0, 0
	  stw       r0, 0x64(r31)

	.loc_0x48:
	  lwz       r30, 0x2AC(r31)
	  cmplwi    r30, 0
	  beq-      .loc_0xE8
	  lwz       r3, 0x2A8(r30)
	  addi      r29, r3, 0x2AC
	  lwz       r3, 0x2AC(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x74
	  bl        0x59624
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0x74:
	  lwz       r3, 0x2A8(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  bl        0x5960C
	  li        r0, 0
	  stw       r0, 0x2A8(r30)

	.loc_0x8C:
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0xE
	  bne-      .loc_0xE8
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xE8
	  li        r0, 0xA
	  stw       r0, 0x2C(r1)
	  li        r0, 0x1
	  addi      r4, r30, 0
	  stw       r0, 0x30(r1)
	  addi      r5, r1, 0x2C
	  stw       r0, 0x2D0(r30)
	  lwz       r3, 0x2E8(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0xE8:
	  lwz       r0, 0x3044(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xFC
	  addi      r3, r31, 0x168
	  bl        0x1A6FC

	.loc_0xFC:
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x110
	  cmpwi     r0, 0x36
	  bne-      .loc_0x118

	.loc_0x110:
	  addi      r3, r31, 0x40
	  bl        0x936C

	.loc_0x118:
	  addi      r3, r31, 0x1B8
	  bl        0x5905C
	  lwz       r0, 0x184(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x134
	  mr        r3, r31
	  bl        0x5BCC

	.loc_0x134:
	  lwz       r0, 0x180(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x178
	  b         .loc_0x16C

	.loc_0x144:
	  lwz       r4, 0xC8(r3)
	  rlwinm.   r0,r4,0,17,17
	  beq-      .loc_0x158
	  bl        0x5A48
	  b         .loc_0x16C

	.loc_0x158:
	  rlwinm.   r0,r4,0,16,16
	  beq-      .loc_0x168
	  bl        0x51DC
	  b         .loc_0x16C

	.loc_0x168:
	  bl        0x5B94

	.loc_0x16C:
	  lwz       r3, 0x180(r31)
	  cmplwi    r3, 0
	  bne+      .loc_0x144

	.loc_0x178:
	  lwz       r0, 0x158(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x18C
	  mr        r3, r31
	  bl        0x5D84

	.loc_0x18C:
	  lwz       r0, 0x154(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1AC
	  b         .loc_0x1A0

	.loc_0x19C:
	  bl        0x5D70

	.loc_0x1A0:
	  lwz       r3, 0x154(r31)
	  cmplwi    r3, 0
	  bne+      .loc_0x19C

	.loc_0x1AC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x10C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1D0
	  bl        0x190D4

	.loc_0x1D0:
	  lwz       r3, 0x2F28(r13)
	  mr        r4, r31
	  bl        -0xF7A4
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008AED8
 * Size:	0002C0
 */
Creature::Creature(CreatureProp*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  bl        0x59440
	  addi      r3, r29, 0x8
	  bl        0x90A8
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF2C
	  stw       r0, 0x0(r29)
	  addi      r3, r29, 0x40
	  lfs       f0, -0x7584(r2)
	  stfs      f0, 0x24(r29)
	  stfs      f0, 0x20(r29)
	  stfs      f0, 0x1C(r29)
	  bl        0x9174
	  lfs       f0, -0x7584(r2)
	  addi      r3, r29, 0x168
	  stfs      f0, 0x78(r29)
	  stfs      f0, 0x74(r29)
	  stfs      f0, 0x70(r29)
	  stfs      f0, 0x84(r29)
	  stfs      f0, 0x80(r29)
	  stfs      f0, 0x7C(r29)
	  stfs      f0, 0x90(r29)
	  stfs      f0, 0x8C(r29)
	  stfs      f0, 0x88(r29)
	  stfs      f0, 0x9C(r29)
	  stfs      f0, 0x98(r29)
	  stfs      f0, 0x94(r29)
	  stfs      f0, 0xAC(r29)
	  stfs      f0, 0xA8(r29)
	  stfs      f0, 0xA4(r29)
	  stfs      f0, 0xB8(r29)
	  stfs      f0, 0xB4(r29)
	  stfs      f0, 0xB0(r29)
	  stfs      f0, 0xC4(r29)
	  stfs      f0, 0xC0(r29)
	  stfs      f0, 0xBC(r29)
	  stfs      f0, 0xDC(r29)
	  stfs      f0, 0xD8(r29)
	  stfs      f0, 0xD4(r29)
	  stfs      f0, 0xE8(r29)
	  stfs      f0, 0xE4(r29)
	  stfs      f0, 0xE0(r29)
	  stfs      f0, 0xF8(r29)
	  stfs      f0, 0xF4(r29)
	  stfs      f0, 0xF0(r29)
	  stfs      f0, 0x108(r29)
	  stfs      f0, 0x104(r29)
	  stfs      f0, 0x100(r29)
	  bl        0x1A490
	  addi      r3, r29, 0x174
	  bl        0x1A488
	  lfs       f0, -0x7584(r2)
	  addi      r3, r29, 0x1B8
	  stfs      f0, 0x19C(r29)
	  stfs      f0, 0x198(r29)
	  stfs      f0, 0x194(r29)
	  stfs      f0, 0x1B4(r29)
	  stfs      f0, 0x1B0(r29)
	  stfs      f0, 0x1AC(r29)
	  bl        0x58C30
	  addi      r3, r29, 0x1E0
	  bl        -0x2F04C
	  lfs       f1, -0x7584(r2)
	  li        r31, 0
	  li        r0, -0x1
	  stfs      f1, 0x27C(r29)
	  addi      r4, r1, 0x10
	  addi      r3, r29, 0xE0
	  stfs      f1, 0x278(r29)
	  stfs      f1, 0x274(r29)
	  stfs      f1, 0x2A4(r29)
	  stfs      f1, 0x2A0(r29)
	  stfs      f1, 0x29C(r29)
	  stw       r31, 0x2A8(r29)
	  stw       r31, 0x2AC(r29)
	  stw       r0, 0x6C(r29)
	  stw       r31, 0x2C(r29)
	  stw       r31, 0xC8(r29)
	  lwz       r0, 0xC8(r29)
	  rlwinm    r0,r0,0,26,24
	  stw       r0, 0xC8(r29)
	  stw       r31, 0x220(r29)
	  stw       r31, 0x28C(r29)
	  stb       r31, 0x30(r29)
	  lwz       r0, 0xC8(r29)
	  rlwinm    r0,r0,0,16,14
	  stw       r0, 0xC8(r29)
	  stw       r31, 0x34(r29)
	  stw       r31, 0x284(r29)
	  stw       r31, 0x288(r29)
	  stw       r31, 0x64(r29)
	  lfs       f0, -0x5E18(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x5E14(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x5E10(r13)
	  stfs      f0, 0xAC(r29)
	  lfs       f0, -0x5E0C(r13)
	  stfs      f0, 0xB0(r29)
	  lfs       f0, -0x5E08(r13)
	  stfs      f0, 0xB4(r29)
	  lfs       f0, -0x5E04(r13)
	  stfs      f0, 0xB8(r29)
	  lfs       f0, -0x5E00(r13)
	  stfs      f0, 0x70(r29)
	  lfs       f0, -0x5DFC(r13)
	  stfs      f0, 0x74(r29)
	  lfs       f0, -0x5DF8(r13)
	  stfs      f0, 0x78(r29)
	  lfs       f0, -0x5DF4(r13)
	  stfs      f0, 0x88(r29)
	  lfs       f0, -0x5DF0(r13)
	  stfs      f0, 0x8C(r29)
	  lfs       f0, -0x5DEC(r13)
	  stfs      f0, 0x90(r29)
	  lfs       f0, -0x5DE8(r13)
	  stfs      f0, 0x94(r29)
	  lfs       f0, -0x5DE4(r13)
	  stfs      f0, 0x98(r29)
	  lfs       f0, -0x5DE0(r13)
	  stfs      f0, 0x9C(r29)
	  lfs       f0, -0x5DDC(r13)
	  stfs      f0, 0x7C(r29)
	  lfs       f0, -0x5DD8(r13)
	  stfs      f0, 0x80(r29)
	  lfs       f0, -0x5DD4(r13)
	  stfs      f0, 0x84(r29)
	  stfs      f1, 0xA0(r29)
	  lfs       f0, -0x7568(r2)
	  stfs      f0, 0x26C(r29)
	  lfs       f0, -0x7564(r2)
	  stfs      f0, 0x270(r29)
	  stw       r30, 0x224(r29)
	  stw       r31, 0x28(r29)
	  lwz       r0, 0xC8(r29)
	  rlwinm    r0,r0,0,23,21
	  stw       r0, 0xC8(r29)
	  lfs       f0, -0x5DD0(r13)
	  lfs       f1, -0x5DCC(r13)
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0x5DC8(r13)
	  stfs      f1, 0x14(r1)
	  stfs      f0, 0x18(r1)
	  bl        -0x52E48
	  lfs       f0, -0x5DC4(r13)
	  li        r0, -0x22
	  addi      r3, r29, 0
	  stfs      f0, 0xD4(r29)
	  lfs       f0, -0x5DC0(r13)
	  stfs      f0, 0xD8(r29)
	  lfs       f0, -0x5DBC(r13)
	  stfs      f0, 0xDC(r29)
	  lwz       r4, 0xC8(r29)
	  and       r0, r4, r0
	  stw       r0, 0xC8(r29)
	  stw       r31, 0x2A8(r29)
	  stw       r31, 0x2AC(r29)
	  stb       r31, 0x2B4(r29)
	  stw       r31, 0x280(r29)
	  stw       r31, 0x290(r29)
	  stw       r31, 0x298(r29)
	  stw       r31, 0x2B0(r29)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008B198
 * Size:	000070
 */
void Creature::updateStatic()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x24
	  bl        0x18D34

	.loc_0x24:
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  bl        0x935C
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  li        r5, 0
	  bl        0x93E8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x108(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        0x78C
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008B208
 * Size:	000580
 */
void Creature::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stfd      f31, 0xA0(r1)
	  stfd      f30, 0x98(r1)
	  stfd      f29, 0x90(r1)
	  stfd      f28, 0x88(r1)
	  stw       r31, 0x84(r1)
	  mr        r31, r3
	  stw       r30, 0x80(r1)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  bl        0x18CB0

	.loc_0x38:
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  bl        0x92D8
	  lwz       r0, 0x6C(r31)
	  li        r30, 0
	  cmpwi     r0, 0
	  beq-      .loc_0x5C
	  cmpwi     r0, 0x36
	  bne-      .loc_0x60

	.loc_0x5C:
	  li        r30, 0x1

	.loc_0x60:
	  addi      r5, r30, 0
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  bl        0x9348
	  rlwinm.   r0,r30,0,24,31
	  bne-      .loc_0xA0
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,11,11
	  bne-      .loc_0xA0
	  addi      r3, r31, 0x40
	  bl        0x8F00
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA0
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x558

	.loc_0xA0:
	  li        r0, 0
	  stw       r0, 0x1A4(r31)
	  stw       r0, 0x1A8(r31)
	  lwz       r0, 0x2B0(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xD4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x108(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        0x6A4

	.loc_0xD4:
	  lwz       r0, 0x2A8(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x558
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,16,16
	  beq-      .loc_0x12C
	  lwz       r4, 0x180(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x110
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x9C(r31)

	.loc_0x110:
	  lwz       r0, 0x184(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x558
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,17,15
	  stw       r0, 0xC8(r31)
	  b         .loc_0x558

	.loc_0x12C:
	  lwz       r0, 0x158(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x140
	  mr        r3, r31
	  bl        0x66D8

	.loc_0x140:
	  mr        r3, r31
	  bl        0x3180
	  lwz       r0, 0x184(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x17C
	  mr        r3, r31
	  bl        0x4BF0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x170
	  mr        r3, r31
	  bl        0x5A94
	  b         .loc_0x558

	.loc_0x170:
	  mr        r3, r31
	  bl        0x5CDC
	  b         .loc_0x558

	.loc_0x17C:
	  lwz       r3, 0x28C(r31)
	  li        r0, -0x1
	  cmplwi    r3, 0
	  beq-      .loc_0x194
	  bl        0x8ACEC
	  mr        r0, r3

	.loc_0x194:
	  cmpwi     r0, 0x5
	  bne-      .loc_0x1E0
	  lbz       r0, 0x60(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x1BC
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl

	.loc_0x1BC:
	  lbz       r3, 0x60(r31)
	  addi      r0, r3, 0x1
	  stb       r0, 0x60(r31)
	  lbz       r0, 0x60(r31)
	  cmplwi    r0, 0xF0
	  ble-      .loc_0x208
	  li        r0, 0xF0
	  stb       r0, 0x60(r31)
	  b         .loc_0x208

	.loc_0x1E0:
	  lbz       r0, 0x60(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x208
	  li        r0, 0
	  stb       r0, 0x60(r31)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl

	.loc_0x208:
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,13,13
	  bne-      .loc_0x558
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r31
	  lfs       f0, 0x70(r31)
	  lfs       f31, 0x28C(r4)
	  stfs      f0, 0x74(r1)
	  fmr       f1, f31
	  lfs       f0, 0x74(r31)
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x78(r31)
	  stfs      f0, 0x7C(r1)
	  lwz       r4, 0xBC(r31)
	  lwz       r0, 0xC0(r31)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xC4(r31)
	  stw       r0, 0x78(r31)
	  bl        0x3180
	  lfs       f1, 0xBC(r31)
	  lfs       f0, 0xC0(r31)
	  fmuls     f2, f1, f1
	  lfs       f3, 0xC4(r31)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x7584(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x2DC
	  fsqrte    f1, f4
	  lfd       f3, -0x7580(r2)
	  lfd       f2, -0x7578(r2)
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
	  stfs      f0, 0x4C(r1)
	  lfs       f4, 0x4C(r1)

	.loc_0x2DC:
	  lfs       f0, -0x7584(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x344
	  lwz       r3, 0xC8(r31)
	  rlwinm.   r0,r3,0,9,9
	  beq-      .loc_0x344
	  rlwinm.   r0,r3,0,10,10
	  beq-      .loc_0x344
	  lwz       r3, 0x28C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x344
	  bl        0x8AB7C
	  cmpwi     r3, 0
	  bne-      .loc_0x344
	  lfs       f1, -0x7560(r2)
	  bl        0x1907C8
	  lwz       r3, 0x28C(r31)
	  lfs       f0, 0x1C(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x344
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x1C(r31)
	  stw       r0, 0x20(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x24(r31)

	.loc_0x344:
	  lwz       r4, 0x74(r1)
	  fmr       f1, f31
	  lwz       r0, 0x78(r1)
	  mr        r3, r31
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0x78(r31)
	  bl        0x3070
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,9,9
	  beq-      .loc_0x534
	  lwz       r3, 0x28C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x474
	  bl        0x8AB04
	  cmpwi     r3, 0
	  bne-      .loc_0x474
	  lfs       f1, -0x7560(r2)
	  bl        0x190750
	  lwz       r3, 0x28C(r31)
	  lfs       f0, 0x1C(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x474
	  lfs       f1, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fmuls     f2, f1, f1
	  lfs       f3, 0xAC(r31)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x7584(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x428
	  fsqrte    f1, f4
	  lfd       f3, -0x7580(r2)
	  lfd       f2, -0x7578(r2)
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
	  stfs      f0, 0x48(r1)
	  lfs       f4, 0x48(r1)

	.loc_0x428:
	  lfs       f0, -0x755C(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x464
	  lwz       r3, 0xC8(r31)
	  rlwinm.   r0,r3,0,10,10
	  bne-      .loc_0x480
	  oris      r0, r3, 0x20
	  stw       r0, 0xC8(r31)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x1C(r31)
	  stw       r0, 0x20(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x24(r31)
	  b         .loc_0x480

	.loc_0x464:
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,11,9
	  stw       r0, 0xC8(r31)
	  b         .loc_0x480

	.loc_0x474:
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,11,9
	  stw       r0, 0xC8(r31)

	.loc_0x480:
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,10,10
	  beq-      .loc_0x534
	  lfs       f3, 0x1C(r31)
	  lfs       f2, 0x94(r31)
	  lfs       f1, 0x20(r31)
	  lfs       f0, 0x98(r31)
	  fsubs     f30, f3, f2
	  lfs       f2, 0x24(r31)
	  fsubs     f29, f1, f0
	  lfs       f0, 0x9C(r31)
	  fmuls     f1, f30, f30
	  fsubs     f28, f2, f0
	  fmuls     f0, f29, f29
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x7DA8C
	  lfs       f0, -0x7584(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x4E0
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1
	  fdivs     f28, f28, f1

	.loc_0x4E0:
	  lfs       f0, -0x7558(r2)
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0x4F0
	  lfs       f1, -0x7584(r2)

	.loc_0x4F0:
	  lfs       f0, -0x7584(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x534
	  lfs       f0, -0x7568(r2)
	  fmuls     f0, f0, f1
	  fmuls     f2, f30, f0
	  fmuls     f1, f29, f0
	  fmuls     f0, f28, f0
	  stfs      f2, 0x74(r1)
	  stfs      f1, 0x78(r1)
	  stfs      f0, 0x7C(r1)
	  lwz       r3, 0x74(r1)
	  lwz       r0, 0x78(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0x78(r31)

	.loc_0x534:
	  lfs       f0, -0x5DB8(r13)
	  fmr       f1, f31
	  mr        r3, r31
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x5DB4(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x5DB0(r13)
	  stfs      f0, 0xC4(r31)
	  bl        0x2B70

	.loc_0x558:
	  lwz       r0, 0xAC(r1)
	  lfd       f31, 0xA0(r1)
	  lfd       f30, 0x98(r1)
	  lfd       f29, 0x90(r1)
	  lfd       f28, 0x88(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008B788
 * Size:	0001F4
 */
void Creature::postUpdate(int, float)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  fmr       f31, f1
	  stw       r31, 0x4C(r1)
	  mr        r31, r3
	  stw       r30, 0x48(r1)
	  stw       r29, 0x44(r1)
	  lwz       r0, 0x6C(r3)
	  li        r3, 0
	  cmpwi     r0, 0
	  beq-      .loc_0x3C
	  cmpwi     r0, 0x36
	  bne-      .loc_0x40

	.loc_0x3C:
	  li        r3, 0x1

	.loc_0x40:
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x64
	  addi      r3, r31, 0x40
	  bl        0x89BC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x64
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x1D4

	.loc_0x64:
	  lwz       r0, 0x2A8(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x1D4
	  mr        r3, r31
	  fmr       f1, f31
	  bl        0x43C
	  lwz       r3, 0x280(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x164
	  lwz       r0, 0x28(r3)
	  cmplwi    r0, 0
	  mr        r30, r0
	  beq-      .loc_0x164
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x164
	  lwz       r3, 0x220(r30)
	  li        r29, 0
	  cmplwi    r3, 0
	  beq-      .loc_0xE0
	  bl        -0x1CFC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE0
	  lwz       r3, 0x220(r30)
	  lwz       r4, 0x280(r31)
	  bl        -0x1E44
	  mr        r29, r3

	.loc_0xE0:
	  stw       r30, 0x28(r1)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r31, 0x34(r1)
	  stw       r0, 0x38(r1)
	  stw       r29, 0x2C(r1)
	  stw       r29, 0x3C(r1)
	  stw       r0, 0x30(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x130
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r1, 0x34
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl

	.loc_0x130:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x164
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  addi      r4, r1, 0x28
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl

	.loc_0x164:
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x1AC(r31)
	  stw       r0, 0x1B0(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x1B4(r31)
	  lwz       r30, 0x2AC(r31)
	  cmplwi    r30, 0
	  beq-      .loc_0x1D4
	  lwz       r12, 0x0(r31)
	  mr        r4, r31
	  mr        r5, r30
	  lwz       r12, 0x100(r12)
	  addi      r3, r1, 0x1C
	  mtlr      r12
	  blrl
	  lwz       r3, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r3, 0x94(r30)
	  stw       r0, 0x98(r30)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x9C(r30)
	  lwz       r3, 0x88(r31)
	  lwz       r0, 0x8C(r31)
	  stw       r3, 0x88(r30)
	  stw       r0, 0x8C(r30)
	  lwz       r0, 0x90(r31)
	  stw       r0, 0x90(r30)

	.loc_0x1D4:
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008B97C
 * Size:	0000B4
 */
void Creature::updateAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x2A8(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xA0
	  lbz       r0, 0x2B4(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x68
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,20,20
	  bne-      .loc_0x68
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x68
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x104(r12)
	  mtlr      r12
	  blrl

	.loc_0x68:
	  lwz       r3, 0xC8(r31)
	  rlwinm.   r0,r3,0,25,25
	  bne-      .loc_0x7C
	  rlwinm.   r0,r3,0,29,29
	  beq-      .loc_0xA0

	.loc_0x7C:
	  rlwinm.   r0,r3,0,26,26
	  bne-      .loc_0xA0
	  lbz       r0, 0x2B4(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xA0
	  rlwinm.   r0,r3,0,20,20
	  bne-      .loc_0xA0
	  mr        r3, r31
	  bl        0x15E4

	.loc_0xA0:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008BA30
 * Size:	0000F0
 */
void centreDist(Creature*, Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0x2C
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r4, r31
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0x38
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0x3C(r1)
	  lfs       f2, 0x30(r1)
	  lfs       f1, 0x38(r1)
	  lfs       f0, 0x2C(r1)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x40(r1)
	  fsubs     f4, f1, f0
	  lfs       f0, 0x34(r1)
	  fmuls     f1, f3, f3
	  fsubs     f3, f2, f0
	  lfs       f0, -0x7584(r2)
	  fmuls     f2, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xDC
	  fsqrte    f2, f1
	  lfd       f4, -0x7580(r2)
	  lfd       f3, -0x7578(r2)
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f0, f2, f0
	  fmul      f0, f1, f0
	  frsp      f0, f0
	  stfs      f0, 0x28(r1)
	  lfs       f1, 0x28(r1)

	.loc_0xDC:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void sphereDistQuick(Creature*, Creature*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008BB20
 * Size:	00011C
 */
void sphereDist(Creature*, Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stfd      f31, 0x78(r1)
	  stfd      f30, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r4
	  stw       r30, 0x68(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x54
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r4, r30
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x48
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, 0x48(r1)
	  lfs       f0, 0x54(r1)
	  lfs       f1, 0x4C(r1)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x58(r1)
	  fsubs     f0, f1, f0
	  stfs      f2, 0x24(r1)
	  lfs       f1, 0x24(r1)
	  stfs      f1, 0x3C(r1)
	  stfs      f0, 0x40(r1)
	  lfs       f1, 0x50(r1)
	  lfs       f0, 0x5C(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x3C(r1)
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x40(r1)
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x44(r1)
	  stfs      f0, 0x38(r1)
	  lfs       f1, 0x30(r1)
	  lfs       f0, 0x34(r1)
	  lfs       f2, 0x38(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x7DFA0
	  mr        r3, r31
	  fmr       f30, f1
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f31, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f1, f31
	  lwz       r0, 0x84(r1)
	  lfd       f31, 0x78(r1)
	  lwz       r31, 0x6C(r1)
	  fsubs     f1, f30, f0
	  lfd       f30, 0x70(r1)
	  lwz       r30, 0x68(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008BC3C
 * Size:	0006E8
 */
void Creature::collisionCheck(float)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x120(r1)
	  stfd      f31, 0x118(r1)
	  stfd      f30, 0x110(r1)
	  fmr       f30, f1
	  stfd      f29, 0x108(r1)
	  stfd      f28, 0x100(r1)
	  stfd      f27, 0xF8(r1)
	  stmw      r25, 0xDC(r1)
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x6C0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x84(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x6C0
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,26,26
	  bne-      .loc_0x6C0
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0xAC(r1)
	  subi      r0, r3, 0x5A14
	  stw       r0, 0xAC(r1)
	  addi      r30, r31, 0x1B8
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r29, r1, 0xAC
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0xFC

	.loc_0xA8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r29)
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x158
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0xFC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x124
	  li        r0, 0x1
	  b         .loc_0x150

	.loc_0x124:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x14C
	  li        r0, 0x1
	  b         .loc_0x150

	.loc_0x14C:
	  li        r0, 0

	.loc_0x150:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xA8

	.loc_0x158:
	  lfs       f29, -0x7554(r2)
	  lfs       f31, -0x7584(r2)
	  b         .loc_0x664

	.loc_0x164:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x18C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x1A8

	.loc_0x18C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x1A8:
	  lwz       r12, 0x0(r28)
	  mr        r3, r28
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x56C
	  lwz       r0, 0x2AC(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1D8
	  cmplw     r0, r28
	  beq-      .loc_0x56C

	.loc_0x1D8:
	  lwz       r4, 0x2A8(r31)
	  neg       r0, r4
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,24,31
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  rlwinm.   r0,r0,27,24,31
	  beq-      .loc_0x200
	  cmplw     r4, r28
	  beq-      .loc_0x56C

	.loc_0x200:
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x56C
	  lwz       r0, 0x2A8(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x56C
	  stfs      f31, 0xC8(r1)
	  li        r26, 0
	  li        r25, 0
	  stfs      f31, 0xC4(r1)
	  stfs      f31, 0xC0(r1)
	  lwz       r3, 0x220(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x244
	  bl        -0x2320
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x244
	  lwz       r26, 0x220(r31)

	.loc_0x244:
	  lwz       r0, 0x220(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x264
	  lwz       r3, 0x220(r28)
	  bl        -0x2340
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x264
	  lwz       r25, 0x220(r28)

	.loc_0x264:
	  cmplwi    r26, 0
	  bne-      .loc_0x484
	  cmplwi    r25, 0
	  bne-      .loc_0x484
	  mr        r4, r28
	  lwz       r12, 0x0(r28)
	  addi      r3, r1, 0x88
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r4, r31
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0x7C
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, 0x7C(r1)
	  lfs       f0, 0x88(r1)
	  lfs       f1, 0x80(r1)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x8C(r1)
	  fsubs     f0, f1, f0
	  stfs      f2, 0x44(r1)
	  lfs       f1, 0x44(r1)
	  stfs      f1, 0x70(r1)
	  stfs      f0, 0x74(r1)
	  lfs       f1, 0x84(r1)
	  lfs       f0, 0x90(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x70(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x74(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0x6C(r1)
	  lfs       f1, 0x64(r1)
	  lfs       f0, 0x68(r1)
	  lfs       f2, 0x6C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x7E310
	  mr        r3, r28
	  fmr       f28, f1
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  fmr       f27, f1
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f1, f27
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0x56C
	  mr        r4, r28
	  lwz       r12, 0x0(r28)
	  addi      r3, r1, 0x94
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r4, r31
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0xA0
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, 0xA0(r1)
	  lfs       f0, 0x94(r1)
	  lfs       f1, 0xA4(r1)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x98(r1)
	  fsubs     f0, f1, f0
	  stfs      f2, 0xC0(r1)
	  stfs      f0, 0xC4(r1)
	  lfs       f1, 0xA8(r1)
	  lfs       f0, 0x9C(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xC8(r1)
	  lfs       f1, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  lfs       f2, 0xC8(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x7E3D0
	  fmr       f27, f1
	  fcmpu     cr0, f31, f27
	  beq-      .loc_0x408
	  lfs       f0, 0xC0(r1)
	  fdivs     f0, f0, f27
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  fdivs     f0, f0, f27
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0xC8(r1)
	  fdivs     f0, f0, f27
	  stfs      f0, 0xC8(r1)

	.loc_0x408:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  fmr       f28, f1
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f4, f1, f28
	  lfs       f0, 0xC0(r1)
	  lfs       f2, 0xC4(r1)
	  fmr       f1, f30
	  lfs       f3, 0xC8(r1)
	  fsubs     f4, f4, f27
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  addi      r7, r1, 0xC0
	  fneg      f4, f4
	  li        r5, 0
	  li        r6, 0
	  fmuls     f0, f0, f4
	  fmuls     f5, f2, f4
	  fmuls     f2, f3, f4
	  stfs      f0, 0xC0(r1)
	  stfs      f5, 0xC4(r1)
	  stfs      f2, 0xC8(r1)
	  bl        0x189C
	  b         .loc_0x56C

	.loc_0x484:
	  cmplwi    r26, 0
	  beq-      .loc_0x4C8
	  cmplwi    r25, 0
	  bne-      .loc_0x4C8
	  addi      r3, r26, 0
	  addi      r4, r28, 0
	  addi      r5, r1, 0xC0
	  bl        -0x31DC
	  mr.       r5, r3
	  beq-      .loc_0x56C
	  fmr       f1, f30
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  addi      r7, r1, 0xC0
	  li        r6, 0
	  bl        0x1858
	  b         .loc_0x56C

	.loc_0x4C8:
	  cmplwi    r26, 0
	  bne-      .loc_0x530
	  cmplwi    r25, 0
	  beq-      .loc_0x530
	  addi      r3, r25, 0
	  addi      r4, r31, 0
	  addi      r5, r1, 0xC0
	  bl        -0x3220
	  mr.       r6, r3
	  beq-      .loc_0x56C
	  lfs       f0, 0xC0(r1)
	  fmr       f1, f30
	  mr        r3, r31
	  fmuls     f0, f0, f29
	  addi      r4, r28, 0
	  addi      r7, r1, 0xC0
	  li        r5, 0
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  fmuls     f0, f0, f29
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0xC8(r1)
	  fmuls     f0, f0, f29
	  stfs      f0, 0xC8(r1)
	  bl        0x17F0
	  b         .loc_0x56C

	.loc_0x530:
	  addi      r3, r26, 0
	  addi      r4, r25, 0
	  addi      r5, r1, 0xB4
	  addi      r6, r1, 0xB0
	  addi      r7, r1, 0xC0
	  bl        -0x2C0C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x56C
	  fmr       f1, f30
	  lwz       r5, 0xB4(r1)
	  lwz       r6, 0xB0(r1)
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  addi      r7, r1, 0xC0
	  bl        0x17B0

	.loc_0x56C:
	  cmplwi    r29, 0
	  beq-      .loc_0x648
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x5E8

	.loc_0x594:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r29)
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x664
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x5E8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x610
	  li        r0, 0x1
	  b         .loc_0x63C

	.loc_0x610:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x638
	  li        r0, 0x1
	  b         .loc_0x63C

	.loc_0x638:
	  li        r0, 0

	.loc_0x63C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x594
	  b         .loc_0x664

	.loc_0x648:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x664:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x68C
	  li        r0, 0x1
	  b         .loc_0x6B8

	.loc_0x68C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x6B4
	  li        r0, 0x1
	  b         .loc_0x6B8

	.loc_0x6B4:
	  li        r0, 0

	.loc_0x6B8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x164

	.loc_0x6C0:
	  lmw       r25, 0xDC(r1)
	  lwz       r0, 0x124(r1)
	  lfd       f31, 0x118(r1)
	  lfd       f30, 0x110(r1)
	  lfd       f29, 0x108(r1)
	  lfd       f28, 0x100(r1)
	  lfd       f27, 0xF8(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008C324
 * Size:	0000A0
 */
void Creature::getCatchPos(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x38(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x7550(r2)
	  fmuls     f30, f0, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x18F7EC
	  fmuls     f31, f30, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x18F974
	  fmuls     f4, f30, f1
	  lfs       f0, 0x94(r31)
	  lfs       f3, 0x9C(r31)
	  lfs       f2, -0x5DAC(r13)
	  lfs       f1, 0x98(r31)
	  fadds     f0, f4, f0
	  fadds     f2, f2, f1
	  fadds     f1, f31, f3
	  stfs      f0, 0x0(r30)
	  stfs      f2, 0x4(r30)
	  stfs      f1, 0x8(r30)
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008C3C4
 * Size:	000008
 */
u32 Creature::needShadow() { return 0x1; }

/*
 * --INFO--
 * Address:	8008C3CC
 * Size:	000040
 */
void Creature::getShadowSize()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x7C(r31)
	  lwz       r0, 0x1C(r1)
	  fmuls     f1, f0, f1
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000164
 */
void showTri(Graphics&, Vector3f&, CollTriInfo*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008C40C
 * Size:	0002B4
 */
void recTraceShadowTris(Graphics&, Vector3f&, CollTriInfo*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x3
	  mtctr     r0
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  addi      r6, r1, 0x7C
	  stmw      r26, 0xB0(r1)
	  mr        r29, r5
	  addi      r28, r4, 0
	  mr        r27, r3
	  addi      r4, r29, 0
	  addi      r5, r1, 0x58
	  lfs       f1, -0x7558(r2)
	  lfs       f0, 0x2FF8(r13)
	  lfs       f2, -0x7584(r2)
	  fdivs     f0, f1, f0
	  lfs       f1, -0x754C(r2)
	  stfs      f2, 0x60(r1)
	  lfs       f3, -0x7548(r2)
	  stfs      f2, 0x5C(r1)
	  stfs      f2, 0x58(r1)
	  fmuls     f4, f1, f0
	  stfs      f2, 0x6C(r1)
	  stfs      f2, 0x68(r1)
	  stfs      f2, 0x64(r1)
	  stfs      f2, 0x78(r1)
	  stfs      f2, 0x74(r1)
	  stfs      f2, 0x70(r1)

	.loc_0x74:
	  lwz       r3, 0x2F00(r13)
	  lfs       f6, -0x5DA8(r13)
	  lfs       f0, 0x18(r29)
	  lwz       r3, 0x60(r3)
	  lwzu      r0, 0x4(r4)
	  fmuls     f0, f0, f6
	  lfs       f1, 0x1C(r29)
	  lfs       f2, 0x20(r29)
	  mulli     r0, r0, 0xC
	  lwz       r3, 0x23C(r3)
	  fmuls     f5, f1, f6
	  stfs      f0, 0x54(r1)
	  fmuls     f1, f2, f6
	  add       r3, r3, r0
	  lfs       f0, 0x54(r1)
	  stfs      f0, 0xA0(r1)
	  stfs      f5, 0xA4(r1)
	  stfs      f1, 0xA8(r1)
	  lfs       f1, 0xA0(r1)
	  lfs       f0, 0x0(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x48(r1)
	  stfs      f0, 0x94(r1)
	  lfs       f1, 0xA4(r1)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0xA8(r1)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x94(r1)
	  lwz       r0, 0x98(r1)
	  stw       r3, 0x0(r5)
	  stw       r0, 0x4(r5)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x8(r5)
	  lfs       f1, 0x0(r5)
	  lfs       f0, 0x0(r28)
	  lfs       f2, 0x8(r5)
	  addi      r5, r5, 0xC
	  fsubs     f0, f1, f0
	  lfs       f1, 0x8(r28)
	  fsubs     f1, f2, f1
	  fmuls     f0, f4, f0
	  fmuls     f1, f4, f1
	  fadds     f0, f3, f0
	  fadds     f1, f3, f1
	  stfs      f0, 0x0(r6)
	  stfs      f1, 0x4(r6)
	  addi      r6, r6, 0x8
	  bdnz+     .loc_0x74
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  addi      r4, r1, 0x58
	  addi      r6, r1, 0x7C
	  lwz       r12, 0xA0(r12)
	  li        r5, 0
	  li        r7, 0x3
	  mtlr      r12
	  blrl
	  lis       r3, 0x803D
	  lfs       f31, -0x7548(r2)
	  addi      r26, r3, 0x15F0
	  addi      r31, r29, 0
	  addi      r30, r29, 0
	  li        r29, 0

	.loc_0x184:
	  lfs       f3, 0x28(r31)
	  lfs       f2, 0x0(r28)
	  lfs       f1, 0x2C(r31)
	  lfs       f0, 0x4(r28)
	  fmuls     f3, f3, f2
	  lfs       f4, 0x30(r31)
	  fmuls     f2, f1, f0
	  lfs       f0, 0x8(r28)
	  lfs       f1, 0x34(r31)
	  fmuls     f4, f4, f0
	  lfs       f0, 0x2FF8(r13)
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x288
	  lha       r0, 0x12(r30)
	  cmpwi     r0, 0
	  blt-      .loc_0x288
	  lwz       r4, 0x2F00(r13)
	  mulli     r0, r0, 0x58
	  lwz       r3, 0x2FF4(r13)
	  lwz       r4, 0x60(r4)
	  addi      r6, r3, 0x18
	  lwz       r3, 0x16C(r4)
	  lfs       f3, 0x0(r6)
	  add       r5, r3, r0
	  lfs       f1, 0x4(r6)
	  lfs       f2, 0x18(r5)
	  lfs       f0, 0x1C(r5)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x8(r6)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x20(r5)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x288
	  lwz       r4, 0x2FF0(r13)
	  addi      r3, r26, 0
	  li        r6, 0
	  cmpwi     r4, 0
	  mtctr     r4
	  ble-      .loc_0x254

	.loc_0x238:
	  lwz       r0, 0x0(r3)
	  cmplw     r0, r5
	  bne-      .loc_0x24C
	  li        r6, 0x1
	  b         .loc_0x254

	.loc_0x24C:
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0x238

	.loc_0x254:
	  rlwinm.   r0,r6,0,24,31
	  bne-      .loc_0x288
	  cmpwi     r4, 0x32
	  bge-      .loc_0x288
	  lwz       r7, 0x2FF0(r13)
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  addi      r6, r7, 0x1
	  rlwinm    r0,r7,2,0,29
	  stw       r6, 0x2FF0(r13)
	  add       r6, r26, r0
	  stw       r5, 0x0(r6)
	  bl        .loc_0x0

	.loc_0x288:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x3
	  addi      r31, r31, 0x10
	  addi      r30, r30, 0x2
	  blt+      .loc_0x184
	  lmw       r26, 0xB0(r1)
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void calcShadowTris(Graphics&, Vector3f&, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008C6C0
 * Size:	0007BC
 */
void Creature::drawShadow(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x450(r1)
	  stfd      f31, 0x448(r1)
	  stfd      f30, 0x440(r1)
	  stfd      f29, 0x438(r1)
	  stfd      f28, 0x430(r1)
	  stfd      f27, 0x428(r1)
	  stfd      f26, 0x420(r1)
	  stfd      f25, 0x418(r1)
	  stfd      f24, 0x410(r1)
	  stw       r31, 0x40C(r1)
	  mr        r31, r4
	  stw       r30, 0x408(r1)
	  mr        r30, r3
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x90(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x784
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x784
	  mr        r4, r30
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x310
	  lwz       r12, 0x68(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x310(r1)
	  mr        r3, r30
	  lfs       f0, 0x314(r1)
	  stfs      f1, 0x3F0(r1)
	  stfs      f0, 0x3F4(r1)
	  lfs       f0, 0x318(r1)
	  stfs      f0, 0x3F8(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  fmr       f31, f1
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x3F0(r1)
	  li        r4, 0x1
	  lfs       f2, 0x3F8(r1)
	  bl        -0x245A0
	  cmplwi    r3, 0
	  beq-      .loc_0x784
	  lfs       f7, 0x3F0(r1)
	  li        r5, 0x1
	  lfs       f1, 0x18(r3)
	  li        r4, 0
	  lfs       f6, 0x3F8(r1)
	  lfs       f0, 0x20(r3)
	  fmuls     f4, f7, f1
	  lfs       f2, 0x24(r3)
	  fmuls     f3, f6, f0
	  lfs       f1, 0x1C(r3)
	  lfs       f0, -0x7584(r2)
	  fadds     f3, f4, f3
	  fsubs     f2, f3, f2
	  fneg      f2, f2
	  fdivs     f5, f2, f1
	  b         .loc_0x140

	.loc_0x104:
	  lfs       f2, 0x28(r3)
	  lfs       f1, 0x2C(r3)
	  fmuls     f3, f2, f7
	  lfs       f4, 0x30(r3)
	  fmuls     f2, f1, f5
	  lfs       f1, 0x34(r3)
	  fmuls     f4, f4, f6
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x138
	  li        r5, 0

	.loc_0x138:
	  addi      r3, r3, 0x10
	  addi      r4, r4, 0x1

	.loc_0x140:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x150
	  cmpwi     r4, 0x3
	  blt+      .loc_0x104

	.loc_0x150:
	  lfs       f0, -0x7544(r2)
	  lfs       f1, 0x3F4(r1)
	  fsubs     f0, f5, f0
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0x784
	  lfs       f0, -0x7540(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x714
	  lfs       f30, -0x7584(r2)
	  fsubs     f26, f1, f5
	  stfs      f7, 0x35C(r1)
	  stfs      f30, 0x370(r1)
	  stfs      f30, 0x36C(r1)
	  stfs      f30, 0x368(r1)
	  stfs      f30, 0x37C(r1)
	  stfs      f30, 0x378(r1)
	  stfs      f30, 0x374(r1)
	  stfs      f30, 0x388(r1)
	  stfs      f30, 0x384(r1)
	  stfs      f30, 0x380(r1)
	  stfs      f30, 0x394(r1)
	  stfs      f30, 0x390(r1)
	  stfs      f30, 0x38C(r1)
	  stfs      f30, 0x3A0(r1)
	  stfs      f30, 0x39C(r1)
	  stfs      f30, 0x398(r1)
	  stfs      f30, 0x3AC(r1)
	  stfs      f30, 0x3A8(r1)
	  stfs      f30, 0x3A4(r1)
	  stfs      f1, 0x360(r1)
	  stfs      f6, 0x364(r1)
	  lfs       f0, -0x753C(r2)
	  fadds     f0, f0, f5
	  stfs      f0, 0x360(r1)
	  lfs       f0, -0x7538(r2)
	  fcmpo     cr0, f26, f0
	  bge-      .loc_0x1F0
	  fdivs     f0, f26, f0
	  lfs       f1, -0x756C(r2)
	  fsubs     f30, f1, f0

	.loc_0x1F0:
	  lfs       f0, -0x7584(r2)
	  fcmpo     cr0, f30, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x784
	  lfs       f0, -0x7534(r2)
	  li        r0, 0xFF
	  stb       r0, 0x30C(r1)
	  addi      r4, r1, 0x30C
	  fmuls     f0, f0, f30
	  stb       r0, 0x30D(r1)
	  mr        r3, r31
	  li        r5, 0x1
	  fctiwz    f0, f0
	  stb       r0, 0x30E(r1)
	  stfd      f0, 0x400(r1)
	  lwz       r0, 0x404(r1)
	  stb       r0, 0x30F(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0x340(r31)
	  lfs       f2, 0x3F4(r1)
	  lfs       f1, 0x33C(r31)
	  lfs       f0, 0x3F0(r1)
	  fsubs     f5, f3, f2
	  lfs       f8, -0x5DA0(r13)
	  fsubs     f6, f1, f0
	  lfs       f7, -0x5DA4(r13)
	  lfs       f3, 0x344(r31)
	  lfs       f0, 0x3F8(r1)
	  fmuls     f1, f5, f8
	  fmuls     f2, f6, f7
	  lfs       f9, -0x5D9C(r13)
	  fsubs     f4, f3, f0
	  lfs       f0, -0x7584(r2)
	  fadds     f1, f2, f1
	  fmuls     f2, f4, f9
	  fadds     f1, f2, f1
	  fmuls     f3, f1, f7
	  fmuls     f2, f1, f8
	  fmuls     f1, f1, f9
	  fsubs     f3, f3, f6
	  fsubs     f2, f2, f5
	  fsubs     f1, f1, f4
	  fneg      f29, f3
	  fneg      f28, f2
	  fneg      f27, f1
	  fmuls     f2, f29, f29
	  fmuls     f1, f28, f28
	  fmuls     f3, f27, f27
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x324
	  fsqrte    f2, f1
	  lfd       f4, -0x7580(r2)
	  lfd       f3, -0x7578(r2)
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f0, f2, f0
	  fmul      f0, f1, f0
	  frsp      f0, f0
	  stfs      f0, 0x168(r1)
	  lfs       f0, 0x168(r1)

	.loc_0x324:
	  lfs       f0, -0x7584(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x38C
	  fsqrte    f2, f1
	  lfd       f4, -0x7580(r2)
	  lfd       f3, -0x7578(r2)
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f0, f2, f0
	  fmul      f0, f1, f0
	  frsp      f0, f0
	  stfs      f0, 0x164(r1)
	  lfs       f3, 0x164(r1)
	  b         .loc_0x390

	.loc_0x38C:
	  fmr       f3, f1

	.loc_0x390:
	  lfs       f2, -0x7530(r2)
	  lfs       f0, -0x7558(r2)
	  fmuls     f2, f3, f2
	  fcmpo     cr0, f2, f0
	  fmr       f24, f2
	  ble-      .loc_0x3AC
	  fmr       f24, f0

	.loc_0x3AC:
	  lfs       f0, -0x7558(r2)
	  fcmpo     cr0, f26, f0
	  bge-      .loc_0x3C8
	  fdivs     f0, f26, f0
	  lfs       f2, -0x756C(r2)
	  fsubs     f0, f2, f0
	  b         .loc_0x3CC

	.loc_0x3C8:
	  lfs       f0, -0x7584(r2)

	.loc_0x3CC:
	  fmuls     f24, f24, f0
	  bl        -0x7EE50
	  lfs       f0, -0x7584(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x3EC
	  fdivs     f29, f29, f1
	  fdivs     f28, f28, f1
	  fdivs     f27, f27, f1

	.loc_0x3EC:
	  lfs       f0, 0x35C(r1)
	  fneg      f11, f29
	  lfs       f2, -0x7558(r2)
	  fsubs     f0, f0, f29
	  lfs       f3, -0x756C(r2)
	  fdivs     f2, f24, f2
	  lfs       f9, -0x7548(r2)
	  stfs      f0, 0x35C(r1)
	  lfs       f10, -0x5D98(r13)
	  lfs       f0, 0x360(r1)
	  fsubs     f1, f3, f30
	  fsubs     f0, f0, f28
	  fmuls     f8, f9, f2
	  fadds     f1, f3, f1
	  stfs      f0, 0x360(r1)
	  fadds     f13, f3, f8
	  fmuls     f12, f31, f1
	  lfs       f0, 0x364(r1)
	  fsubs     f0, f0, f27
	  fmuls     f4, f27, f12
	  fmuls     f10, f10, f12
	  stfs      f0, 0x364(r1)
	  fmuls     f11, f11, f12
	  fneg      f25, f4
	  lwz       r0, 0x35C(r1)
	  fneg      f1, f11
	  stfs      f9, 0x3B0(r1)
	  fmuls     f6, f29, f12
	  stfs      f25, 0x210(r1)
	  fmuls     f5, f28, f12
	  stfs      f9, 0x3B4(r1)
	  fadds     f9, f12, f24
	  fmuls     f30, f10, f13
	  lfs       f2, 0x210(r1)
	  stw       r0, 0x368(r1)
	  lwz       r3, 0x360(r1)
	  fneg      f7, f10
	  fadds     f0, f1, f4
	  lwz       r0, 0x364(r1)
	  stw       r3, 0x36C(r1)
	  fmuls     f31, f4, f13
	  fadds     f1, f7, f5
	  fadds     f7, f2, f6
	  lfs       f2, -0x7584(r2)
	  stw       r0, 0x370(r1)
	  fmuls     f26, f11, f13
	  stfs      f7, 0x204(r1)
	  fmuls     f7, f27, f9
	  lfs       f12, 0x204(r1)
	  fmuls     f8, f28, f9
	  stfs      f2, 0x3B8(r1)
	  fneg      f24, f30
	  stfs      f2, 0x3BC(r1)
	  fmuls     f9, f29, f9
	  stfs      f12, 0x2C0(r1)
	  stfs      f1, 0x2C4(r1)
	  stfs      f0, 0x2C8(r1)
	  lfs       f13, 0x35C(r1)
	  lfs       f12, 0x2C0(r1)
	  fadds     f12, f13, f12
	  stfs      f12, 0x1F8(r1)
	  lfs       f12, 0x1F8(r1)
	  stfs      f12, 0x2CC(r1)
	  lfs       f12, 0x360(r1)
	  lfs       f13, 0x2C4(r1)
	  fadds     f13, f12, f13
	  stfs      f13, 0x2D0(r1)
	  lfs       f13, 0x364(r1)
	  lfs       f27, 0x2C8(r1)
	  fadds     f28, f13, f27
	  stfs      f31, 0x1F4(r1)
	  lfs       f27, 0x1F4(r1)
	  stfs      f28, 0x2D4(r1)
	  fneg      f27, f27
	  lwz       r0, 0x2CC(r1)
	  stfs      f2, 0x3C0(r1)
	  lwz       r3, 0x2D0(r1)
	  stw       r0, 0x374(r1)
	  lwz       r0, 0x2D4(r1)
	  stfs      f27, 0x1E8(r1)
	  stw       r3, 0x378(r1)
	  lfs       f27, 0x1E8(r1)
	  stw       r0, 0x37C(r1)
	  stfs      f3, 0x3C4(r1)
	  stfs      f27, 0x290(r1)
	  stfs      f24, 0x294(r1)
	  fneg      f24, f26
	  fadds     f10, f10, f5
	  fadds     f5, f11, f4
	  stfs      f24, 0x298(r1)
	  fsubs     f24, f26, f7
	  fsubs     f28, f31, f9
	  lfs       f11, 0x290(r1)
	  fsubs     f27, f30, f8
	  fsubs     f26, f11, f9
	  fadds     f11, f4, f6
	  fadds     f9, f12, f10
	  stfs      f26, 0x1DC(r1)
	  fadds     f4, f25, f6
	  fadds     f5, f13, f5
	  lfs       f10, 0x1DC(r1)
	  stfs      f10, 0x29C(r1)
	  lfs       f6, 0x294(r1)
	  fsubs     f6, f6, f8
	  stfs      f6, 0x2A0(r1)
	  lfs       f6, 0x298(r1)
	  fsubs     f6, f6, f7
	  stfs      f6, 0x2A4(r1)
	  lfs       f7, 0x35C(r1)
	  lfs       f6, 0x29C(r1)
	  fadds     f6, f7, f6
	  stfs      f6, 0x1D0(r1)
	  lfs       f6, 0x1D0(r1)
	  stfs      f6, 0x2A8(r1)
	  lfs       f6, 0x2A0(r1)
	  fadds     f6, f12, f6
	  stfs      f6, 0x2AC(r1)
	  lfs       f6, 0x2A4(r1)
	  fadds     f7, f13, f6
	  stfs      f28, 0x1B8(r1)
	  stfs      f3, 0x3C8(r1)
	  lfs       f6, 0x1B8(r1)
	  stfs      f7, 0x2B0(r1)
	  lwz       r0, 0x2A8(r1)
	  lwz       r3, 0x2AC(r1)
	  stw       r0, 0x380(r1)
	  lwz       r0, 0x2B0(r1)
	  stw       r3, 0x384(r1)
	  stw       r0, 0x388(r1)
	  stfs      f3, 0x3CC(r1)
	  stfs      f6, 0x26C(r1)
	  stfs      f27, 0x270(r1)
	  stfs      f24, 0x274(r1)
	  lfs       f8, 0x35C(r1)
	  lfs       f6, 0x26C(r1)
	  fadds     f6, f8, f6
	  stfs      f6, 0x1AC(r1)
	  lfs       f6, 0x1AC(r1)
	  stfs      f6, 0x278(r1)
	  lfs       f6, 0x270(r1)
	  fadds     f6, f12, f6
	  stfs      f6, 0x27C(r1)
	  lfs       f6, 0x274(r1)
	  fadds     f7, f13, f6
	  stfs      f11, 0x1A0(r1)
	  lfs       f6, 0x1A0(r1)
	  stfs      f7, 0x280(r1)
	  fadds     f6, f8, f6
	  lwz       r4, 0x278(r1)
	  lwz       r3, 0x27C(r1)
	  stfs      f6, 0x194(r1)
	  lwz       r0, 0x280(r1)
	  lfs       f6, 0x194(r1)
	  stw       r4, 0x38C(r1)
	  stfs      f6, 0x254(r1)
	  stfs      f9, 0x258(r1)
	  stfs      f5, 0x25C(r1)
	  stw       r3, 0x390(r1)
	  lwz       r4, 0x254(r1)
	  stw       r0, 0x394(r1)
	  lwz       r3, 0x258(r1)
	  stfs      f3, 0x3D0(r1)
	  lwz       r0, 0x25C(r1)
	  stfs      f2, 0x3D4(r1)
	  stw       r4, 0x398(r1)
	  stfs      f4, 0x17C(r1)
	  stw       r3, 0x39C(r1)
	  lfs       f3, 0x17C(r1)
	  stfs      f2, 0x3D8(r1)
	  stw       r0, 0x3A0(r1)
	  stfs      f2, 0x3DC(r1)
	  stfs      f3, 0x230(r1)
	  stfs      f1, 0x234(r1)
	  stfs      f0, 0x238(r1)
	  lfs       f1, 0x35C(r1)
	  mr        r3, r31
	  lfs       f0, 0x230(r1)
	  addi      r4, r1, 0x368
	  addi      r6, r1, 0x3B0
	  fadds     f0, f1, f0
	  li        r5, 0
	  li        r7, 0x6
	  stfs      f0, 0x170(r1)
	  lfs       f0, 0x170(r1)
	  stfs      f0, 0x23C(r1)
	  lfs       f0, 0x234(r1)
	  fadds     f0, f12, f0
	  stfs      f0, 0x240(r1)
	  lfs       f0, 0x238(r1)
	  fadds     f0, f13, f0
	  stfs      f0, 0x244(r1)
	  lwz       r0, 0x23C(r1)
	  lwz       r8, 0x240(r1)
	  stw       r0, 0x3A4(r1)
	  lwz       r0, 0x244(r1)
	  stw       r8, 0x3A8(r1)
	  stw       r0, 0x3AC(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x784

	.loc_0x714:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  fmr       f24, f1
	  stw       r0, 0x2FF0(r13)
	  li        r4, 0x1
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x3F0(r1)
	  lfs       f2, 0x3F8(r1)
	  bl        -0x24C2C
	  mr.       r5, r3
	  beq-      .loc_0x784
	  lwz       r4, 0x2FF0(r13)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x15F0
	  stw       r5, 0x2FF4(r13)
	  addi      r6, r4, 0x1
	  rlwinm    r3,r4,2,0,29
	  stfs      f24, 0x2FF8(r13)
	  add       r4, r0, r3
	  stw       r6, 0x2FF0(r13)
	  mr        r3, r31
	  stw       r5, 0x0(r4)
	  addi      r4, r1, 0x3F0
	  bl        -0xA34

	.loc_0x784:
	  lwz       r0, 0x454(r1)
	  lfd       f31, 0x448(r1)
	  lfd       f30, 0x440(r1)
	  lfd       f29, 0x438(r1)
	  lfd       f28, 0x430(r1)
	  lfd       f27, 0x428(r1)
	  lfd       f26, 0x420(r1)
	  lfd       f25, 0x418(r1)
	  lfd       f24, 0x410(r1)
	  lwz       r31, 0x40C(r1)
	  lwz       r30, 0x408(r1)
	  addi      r1, r1, 0x450
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008CE7C
 * Size:	000094
 */
void qdist2(Creature*, Creature*)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lfs       f3, 0x94(r3)
	  lfs       f0, 0x94(r4)
	  lfs       f2, 0x9C(r3)
	  lfs       f1, 0x9C(r4)
	  fsubs     f3, f3, f0
	  lfs       f0, -0x7584(r2)
	  fsubs     f1, f2, f1
	  fmuls     f2, f3, f3
	  fmuls     f1, f1, f1
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x8C
	  fsqrte    f2, f1
	  lfd       f4, -0x7580(r2)
	  lfd       f3, -0x7578(r2)
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f1, f0
	  fsub      f0, f3, f0
	  fmul      f0, f2, f0
	  fmul      f0, f1, f0
	  frsp      f0, f0
	  stfs      f0, 0x10(r1)
	  lfs       f1, 0x10(r1)

	.loc_0x8C:
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008CF10
 * Size:	0000EC
 */
void circleDist(Creature*, Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stfd      f30, 0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x10
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r4, r31
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0x1C
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r4, r30
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x28
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r4, r30
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x34
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x34(r1)
	  lfs       f2, 0x30(r1)
	  lfs       f3, 0x1C(r1)
	  lfs       f4, 0x18(r1)
	  bl        -0x54978
	  mr        r3, r31
	  fmr       f30, f1
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f31, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fsubs     f0, f30, f1
	  lwz       r0, 0x5C(r1)
	  lfd       f30, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  fsubs     f1, f0, f31
	  lfd       f31, 0x50(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008CFFC
 * Size:	000540
 */
void Creature::moveVelocity()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x310(r1)
	  stfd      f31, 0x308(r1)
	  stfd      f30, 0x300(r1)
	  stfd      f29, 0x2F8(r1)
	  stfd      f28, 0x2F0(r1)
	  stfd      f27, 0x2E8(r1)
	  stfd      f26, 0x2E0(r1)
	  stfd      f25, 0x2D8(r1)
	  stfd      f24, 0x2D0(r1)
	  stfd      f23, 0x2C8(r1)
	  stfd      f22, 0x2C0(r1)
	  stw       r31, 0x2BC(r1)
	  mr        r31, r3
	  stw       r30, 0x2B8(r1)
	  lwz       r3, 0x28C(r3)
	  lfs       f30, -0x5D94(r13)
	  cmplwi    r3, 0
	  lfs       f23, 0xA4(r31)
	  lfs       f22, 0xA8(r31)
	  lfs       f31, 0xAC(r31)
	  lfs       f29, -0x5D90(r13)
	  lfs       f28, -0x5D8C(r13)
	  beq-      .loc_0x360
	  fmuls     f2, f23, f23
	  lfsu      f27, 0x18(r3)
	  fmuls     f1, f22, f22
	  lfs       f0, -0x7584(r2)
	  fmuls     f3, f31, f31
	  fadds     f1, f2, f1
	  lfs       f26, 0x4(r3)
	  lfs       f25, 0x8(r3)
	  fadds     f24, f3, f1
	  fcmpo     cr0, f24, f0
	  ble-      .loc_0xE8
	  fsqrte    f1, f24
	  lfd       f3, -0x7580(r2)
	  lfd       f2, -0x7578(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f24, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f24, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f24, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f24, f0
	  frsp      f0, f0
	  stfs      f0, 0x138(r1)
	  lfs       f24, 0x138(r1)

	.loc_0xE8:
	  fmuls     f1, f23, f27
	  addi      r6, r1, 0xF0
	  fmuls     f0, f22, f26
	  addi      r5, r1, 0xEC
	  fmuls     f2, f31, f25
	  fadds     f0, f1, f0
	  addi      r4, r1, 0xE8
	  addi      r3, r1, 0x250
	  fadds     f0, f2, f0
	  fmuls     f2, f25, f0
	  fmuls     f1, f26, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0xF0(r1)
	  stfs      f1, 0xEC(r1)
	  stfs      f0, 0xE8(r1)
	  bl        -0x56004
	  lfs       f0, 0x250(r1)
	  lfs       f1, 0x254(r1)
	  fsubs     f23, f23, f0
	  lfs       f0, 0x258(r1)
	  fsubs     f22, f22, f1
	  fsubs     f31, f31, f0
	  fmuls     f1, f23, f23
	  fmuls     f0, f22, f22
	  fmuls     f2, f31, f31
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x7F510
	  lfs       f0, -0x7584(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x170
	  fdivs     f23, f23, f1
	  fdivs     f22, f22, f1
	  fdivs     f31, f31, f1

	.loc_0x170:
	  fmuls     f23, f23, f24
	  lwz       r3, 0x28C(r31)
	  fmuls     f22, f22, f24
	  fmuls     f31, f31, f24
	  bl        0x88F10
	  mr.       r30, r3
	  bne-      .loc_0x230
	  lfs       f0, -0x753C(r2)
	  fcmpo     cr0, f24, f0
	  bge-      .loc_0x360
	  lwz       r4, 0x2F80(r13)
	  addi      r6, r1, 0xE4
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r1, 0xE0
	  lfs       f1, 0x30(r4)
	  lfs       f0, 0x28C(r3)
	  addi      r4, r1, 0xDC
	  lfs       f28, -0x5D84(r13)
	  addi      r3, r1, 0x240
	  fmuls     f0, f1, f0
	  lfs       f24, -0x5D88(r13)
	  fmuls     f2, f28, f25
	  fneg      f30, f0
	  fmuls     f1, f24, f27
	  fmuls     f0, f30, f26
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fmuls     f2, f25, f0
	  fmuls     f1, f26, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0xE4(r1)
	  stfs      f1, 0xE0(r1)
	  stfs      f0, 0xDC(r1)
	  bl        -0x560D4
	  lfs       f2, 0x240(r1)
	  lfs       f1, 0x244(r1)
	  lfs       f0, 0x248(r1)
	  fsubs     f2, f24, f2
	  fsubs     f1, f30, f1
	  lfs       f3, -0x5D80(r13)
	  fsubs     f0, f28, f0
	  fneg      f2, f2
	  fneg      f1, f1
	  fneg      f0, f0
	  fmuls     f30, f2, f3
	  fmuls     f29, f1, f3
	  fmuls     f28, f0, f3
	  b         .loc_0x360

	.loc_0x230:
	  lwz       r4, 0x2F80(r13)
	  addi      r6, r1, 0xD8
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r1, 0xD4
	  lfs       f1, 0x30(r4)
	  lfs       f0, 0x28C(r3)
	  addi      r4, r1, 0xD0
	  lfs       f28, -0x5D78(r13)
	  addi      r3, r1, 0x230
	  fmuls     f0, f1, f0
	  lfs       f24, -0x5D7C(r13)
	  fmuls     f2, f28, f25
	  fneg      f30, f0
	  fmuls     f1, f24, f27
	  fmuls     f0, f30, f26
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fmuls     f2, f25, f0
	  fmuls     f1, f26, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0xD8(r1)
	  stfs      f1, 0xD4(r1)
	  stfs      f0, 0xD0(r1)
	  bl        -0x5616C
	  lfs       f0, 0x230(r1)
	  lfs       f1, 0x234(r1)
	  fsubs     f24, f24, f0
	  lfs       f0, 0x238(r1)
	  fsubs     f27, f30, f1
	  fsubs     f28, f28, f0
	  fmuls     f1, f24, f24
	  fmuls     f0, f27, f27
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x7F678
	  lfs       f0, -0x7584(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2D8
	  fdivs     f24, f24, f1
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1

	.loc_0x2D8:
	  cmpwi     r30, 0x2
	  bne-      .loc_0x2EC
	  lwz       r3, 0x2F80(r13)
	  lfs       f25, 0x150(r3)
	  b         .loc_0x2F4

	.loc_0x2EC:
	  lwz       r3, 0x2F80(r13)
	  lfs       f25, 0x140(r3)

	.loc_0x2F4:
	  lwz       r3, 0x2F80(r13)
	  addi      r6, r1, 0xC8
	  lwz       r7, 0x2DEC(r13)
	  addi      r5, r1, 0xC4
	  lfs       f0, 0x30(r3)
	  addi      r8, r3, 0x30
	  lfs       f26, 0x28C(r7)
	  fmuls     f0, f28, f0
	  addi      r4, r1, 0xC0
	  addi      r3, r1, 0x214
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0x0(r8)
	  fmuls     f0, f27, f0
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0x0(r8)
	  fmuls     f0, f24, f0
	  stfs      f0, 0xC0(r1)
	  bl        -0x56218
	  lfs       f2, 0x214(r1)
	  lfs       f1, 0x218(r1)
	  lfs       f0, 0x21C(r1)
	  fmuls     f2, f2, f26
	  fmuls     f1, f1, f26
	  fmuls     f0, f0, f26
	  fmuls     f30, f2, f25
	  fmuls     f29, f1, f25
	  fmuls     f28, f0, f25

	.loc_0x360:
	  lfs       f1, 0xB4(r31)
	  lfs       f0, 0xB0(r31)
	  fadds     f4, f22, f1
	  lfs       f5, 0xB8(r31)
	  lfs       f1, 0x74(r31)
	  fadds     f3, f23, f0
	  lfs       f2, 0x70(r31)
	  fsubs     f0, f4, f1
	  lfs       f4, 0x78(r31)
	  fadds     f5, f31, f5
	  lfs       f1, -0x7584(r2)
	  fsubs     f6, f3, f2
	  fsubs     f5, f5, f4
	  fmuls     f3, f6, f6
	  fmuls     f2, f0, f0
	  fmuls     f4, f5, f5
	  fadds     f2, f3, f2
	  fadds     f7, f4, f2
	  fcmpo     cr0, f7, f1
	  ble-      .loc_0x408
	  fsqrte    f2, f7
	  lfd       f4, -0x7580(r2)
	  lfd       f3, -0x7578(r2)
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f7, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f7, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f7, f1
	  fsub      f1, f3, f1
	  fmul      f1, f2, f1
	  fmul      f1, f7, f1
	  frsp      f1, f1
	  stfs      f1, 0x100(r1)
	  lfs       f1, 0x100(r1)

	.loc_0x408:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x224(r31)
	  lfs       f3, 0x28C(r3)
	  fmuls     f2, f6, f3
	  fmuls     f1, f0, f3
	  fmuls     f0, f5, f3
	  stfs      f2, 0x15C(r1)
	  lfs       f2, 0x15C(r1)
	  stfs      f2, 0x1E0(r1)
	  stfs      f1, 0x1E4(r1)
	  stfs      f0, 0x1E8(r1)
	  lfs       f2, -0x756C(r2)
	  lfs       f1, 0x40(r4)
	  lfs       f0, 0x1E0(r1)
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0xF4(r1)
	  lfs       f0, 0xF4(r1)
	  stfs      f0, 0x1EC(r1)
	  lfs       f0, 0x1E4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1F0(r1)
	  lfs       f0, 0x1E8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1F4(r1)
	  lfs       f1, 0x70(r31)
	  lfs       f0, 0x1EC(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x148(r1)
	  lfs       f0, 0x148(r1)
	  stfs      f0, 0x1F8(r1)
	  lfs       f1, 0x74(r31)
	  lfs       f0, 0x1F0(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1FC(r1)
	  lfs       f1, 0x78(r31)
	  lfs       f0, 0x1F4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x200(r1)
	  lwz       r3, 0x1F8(r1)
	  lwz       r0, 0x1FC(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x200(r1)
	  stw       r0, 0x78(r31)
	  lfs       f0, 0x70(r31)
	  fadds     f0, f0, f30
	  stfs      f0, 0x13C(r1)
	  lfs       f0, 0x13C(r1)
	  stfs      f0, 0x1D0(r1)
	  lfs       f0, 0x74(r31)
	  fadds     f0, f0, f29
	  stfs      f0, 0x1D4(r1)
	  lfs       f0, 0x78(r31)
	  fadds     f0, f0, f28
	  stfs      f0, 0x1D8(r1)
	  lwz       r3, 0x1D0(r1)
	  lwz       r0, 0x1D4(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x1D8(r1)
	  stw       r0, 0x78(r31)
	  lwz       r0, 0x314(r1)
	  lfd       f31, 0x308(r1)
	  lfd       f30, 0x300(r1)
	  lfd       f29, 0x2F8(r1)
	  lfd       f28, 0x2F0(r1)
	  lfd       f27, 0x2E8(r1)
	  lfd       f26, 0x2E0(r1)
	  lfd       f25, 0x2D8(r1)
	  lfd       f24, 0x2D0(r1)
	  lfd       f23, 0x2C8(r1)
	  lfd       f22, 0x2C0(r1)
	  lwz       r31, 0x2BC(r1)
	  lwz       r30, 0x2B8(r1)
	  addi      r1, r1, 0x310
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008D53C
 * Size:	000008
 */
u32 Creature::getAvoid(Vector3f&, Vector3f&) { return 0x0; }

/*
 * --INFO--
 * Address:	8008D544
 * Size:	00034C
 */
void Creature::renderAtari(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2A8(r1)
	  stfd      f31, 0x2A0(r1)
	  stfd      f30, 0x298(r1)
	  stw       r31, 0x294(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x290(r1)
	  mr        r30, r3
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x34
	  beq-      .loc_0xF0
	  lfs       f1, -0x5D68(r13)
	  addi      r5, r1, 0xA0
	  lfs       f0, -0x5D74(r13)
	  addi      r4, r1, 0xAC
	  stfs      f1, 0xA0(r1)
	  lfs       f1, -0x5D64(r13)
	  addi      r3, r1, 0x250
	  stfs      f0, 0xAC(r1)
	  addi      r6, r30, 0x94
	  lfs       f0, -0x5D70(r13)
	  stfs      f1, 0xA4(r1)
	  lfs       f1, -0x5D60(r13)
	  stfs      f0, 0xB0(r1)
	  lfs       f0, -0x5D6C(r13)
	  stfs      f1, 0xA8(r1)
	  stfs      f0, 0xB4(r1)
	  bl        -0x4F4C0
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r1, 0x250
	  addi      r5, r1, 0x210
	  addi      r3, r3, 0x1E0
	  bl        -0x4F4F4
	  li        r5, 0
	  stb       r5, 0x9C(r1)
	  li        r0, 0xFF
	  addi      r4, r1, 0x9C
	  stb       r0, 0x9D(r1)
	  mr        r3, r31
	  stb       r5, 0x9E(r1)
	  li        r5, 0x1
	  stb       r0, 0x9F(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0xD0(r30)
	  addi      r4, r1, 0x90
	  lfs       f0, -0x5D5C(r13)
	  mr        r3, r31
	  fneg      f1, f1
	  stfs      f0, 0x90(r1)
	  addi      r5, r1, 0x210
	  lfs       f0, -0x5D58(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0x270(r30)
	  bl        -0x641BC
	  b         .loc_0x32C

	.loc_0xF0:
	  lbz       r0, 0x43C(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x270
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x7548(r2)
	  addi      r6, r1, 0x74
	  lfs       f3, 0x2D0(r30)
	  addi      r4, r1, 0x80
	  lfs       f2, -0x5D54(r13)
	  fmuls     f31, f0, f1
	  addi      r3, r1, 0x1C4
	  stfs      f2, 0x204(r1)
	  fneg      f30, f3
	  addi      r5, r30, 0xE0
	  stfs      f31, 0x208(r1)
	  lfs       f0, -0x5D50(r13)
	  stfs      f0, 0x20C(r1)
	  lfs       f1, -0x5D40(r13)
	  lfs       f0, -0x5D4C(r13)
	  stfs      f1, 0x74(r1)
	  lfs       f1, -0x5D3C(r13)
	  stfs      f0, 0x80(r1)
	  lfs       f0, -0x5D48(r13)
	  stfs      f1, 0x78(r1)
	  lfs       f1, -0x5D38(r13)
	  stfs      f0, 0x84(r1)
	  lfs       f0, -0x5D44(r13)
	  stfs      f1, 0x7C(r1)
	  stfs      f0, 0x88(r1)
	  bl        -0x4E9B4
	  addi      r3, r1, 0x204
	  addi      r4, r1, 0x1C4
	  bl        -0x55F78
	  lfs       f1, 0x204(r1)
	  addi      r5, r1, 0x5C
	  lfs       f0, 0x94(r30)
	  addi      r4, r1, 0x68
	  lfs       f3, 0x208(r1)
	  lfs       f2, 0x98(r30)
	  fadds     f0, f1, f0
	  lfs       f4, 0x20C(r1)
	  addi      r3, r1, 0x178
	  lfs       f1, 0x9C(r30)
	  fadds     f2, f3, f2
	  stfs      f0, 0x204(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x204
	  stfs      f2, 0x208(r1)
	  stfs      f0, 0x20C(r1)
	  lfs       f1, -0x5D28(r13)
	  lfs       f0, -0x5D34(r13)
	  stfs      f1, 0x5C(r1)
	  lfs       f1, -0x5D24(r13)
	  stfs      f0, 0x68(r1)
	  lfs       f0, -0x5D30(r13)
	  stfs      f1, 0x60(r1)
	  lfs       f1, -0x5D20(r13)
	  stfs      f0, 0x6C(r1)
	  lfs       f0, -0x5D2C(r13)
	  stfs      f1, 0x64(r1)
	  stfs      f0, 0x70(r1)
	  bl        -0x4F644
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r1, 0x178
	  addi      r5, r1, 0x138
	  addi      r3, r3, 0x1E0
	  bl        -0x4F678
	  li        r6, 0xFF
	  stb       r6, 0x58(r1)
	  li        r0, 0
	  addi      r4, r1, 0x58
	  stb       r0, 0x59(r1)
	  mr        r3, r31
	  li        r5, 0x1
	  stb       r0, 0x5A(r1)
	  stb       r6, 0x5B(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x5D1C(r13)
	  fadds     f1, f31, f30
	  lfs       f2, -0x5D18(r13)
	  addi      r4, r1, 0x4C
	  stfs      f0, 0x4C(r1)
	  lfs       f0, -0x5D14(r13)
	  stfs      f2, 0x50(r1)
	  mr        r3, r31
	  addi      r5, r1, 0x138
	  stfs      f0, 0x54(r1)
	  bl        -0x6433C
	  b         .loc_0x32C

	.loc_0x270:
	  lfs       f1, -0x5D04(r13)
	  addi      r5, r1, 0x34
	  lfs       f0, -0x5D10(r13)
	  addi      r4, r1, 0x40
	  stfs      f1, 0x34(r1)
	  lfs       f1, -0x5D00(r13)
	  addi      r3, r1, 0xF8
	  stfs      f0, 0x40(r1)
	  addi      r6, r30, 0x94
	  lfs       f0, -0x5D0C(r13)
	  stfs      f1, 0x38(r1)
	  lfs       f1, -0x5CFC(r13)
	  stfs      f0, 0x44(r1)
	  lfs       f0, -0x5D08(r13)
	  stfs      f1, 0x3C(r1)
	  stfs      f0, 0x48(r1)
	  bl        -0x4F700
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r1, 0xF8
	  addi      r5, r1, 0xB8
	  addi      r3, r3, 0x1E0
	  bl        -0x4F734
	  li        r5, 0
	  stb       r5, 0x30(r1)
	  li        r0, 0xFF
	  addi      r4, r1, 0x30
	  stb       r0, 0x31(r1)
	  mr        r3, r31
	  stb       r5, 0x32(r1)
	  li        r5, 0x1
	  stb       r0, 0x33(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0xD0(r30)
	  addi      r4, r1, 0x24
	  lfs       f0, -0x5CF8(r13)
	  mr        r3, r31
	  fneg      f1, f1
	  stfs      f0, 0x24(r1)
	  addi      r5, r1, 0xB8
	  lfs       f0, -0x5CF4(r13)
	  stfs      f1, 0x28(r1)
	  stfs      f0, 0x2C(r1)
	  lfs       f1, 0x270(r30)
	  bl        -0x643FC

	.loc_0x32C:
	  lwz       r0, 0x2AC(r1)
	  lfd       f31, 0x2A0(r1)
	  lfd       f30, 0x298(r1)
	  lwz       r31, 0x294(r1)
	  lwz       r30, 0x290(r1)
	  addi      r1, r1, 0x2A8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008D890
 * Size:	000054
 */
void roughCull(Creature*, Creature*, float)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x40
	  lbz       r0, -0x5F06(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x40
	  addi      r3, r3, 0x40
	  addi      r4, r4, 0x40
	  bl        0x6B34
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x40
	  li        r3, 0x1
	  b         .loc_0x44

	.loc_0x40:
	  li        r3, 0

	.loc_0x44:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008D8E4
 * Size:	000070
 */
void Creature::stickUpdate()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x158(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x2C
	  mr        r3, r31
	  bl        0x4114
	  b         .loc_0x5C

	.loc_0x2C:
	  lwz       r0, 0x184(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C
	  mr        r3, r31
	  bl        0x2630
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x54
	  mr        r3, r31
	  bl        0x34D4
	  b         .loc_0x5C

	.loc_0x54:
	  mr        r3, r31
	  bl        0x371C

	.loc_0x5C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
