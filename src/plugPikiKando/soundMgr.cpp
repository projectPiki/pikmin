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
 * Address:	800A3C5C
 * Size:	000070
 */
SeContext::SeContext()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x7268(r2)
	  lis       r4, 0x1
	  li        r6, -0x1
	  stfs      f0, 0x18(r3)
	  li        r5, 0
	  subi      r0, r4, 0x1
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0x24(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  stw       r6, 0x8(r3)
	  stw       r5, 0x4(r3)
	  sth       r0, 0xC(r3)
	  lfs       f0, -0x5270(r13)
	  stfs      f0, 0x10(r3)
	  lfs       f0, -0x526C(r13)
	  stfs      f0, 0x14(r3)
	  lfs       f0, -0x5268(r13)
	  stfs      f0, 0x18(r3)
	  lfs       f0, -0x5264(r13)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, -0x5260(r13)
	  stfs      f0, 0x20(r3)
	  lfs       f0, -0x525C(r13)
	  stfs      f0, 0x24(r3)
	  stw       r5, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A3CCC
 * Size:	000068
 */
SeContext::SeContext(Creature*, int)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x7268(r2)
	  li        r6, -0x1
	  li        r0, 0
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0x24(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0x4(r3)
	  sth       r5, 0xC(r3)
	  lfs       f0, -0x5258(r13)
	  stfs      f0, 0x10(r3)
	  lfs       f0, -0x5254(r13)
	  stfs      f0, 0x14(r3)
	  lfs       f0, -0x5250(r13)
	  stfs      f0, 0x18(r3)
	  lfs       f0, -0x524C(r13)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, -0x5248(r13)
	  stfs      f0, 0x20(r3)
	  lfs       f0, -0x5244(r13)
	  stfs      f0, 0x24(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A3D34
 * Size:	00009C
 */
void SeContext::setContext(Creature*, int)
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
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x38
	  mr        r3, r29
	  bl        0x218

	.loc_0x38:
	  li        r0, -0x1
	  stw       r0, 0x8(r29)
	  li        r0, 0
	  stw       r30, 0x4(r29)
	  sth       r31, 0xC(r29)
	  lfs       f0, -0x5240(r13)
	  stfs      f0, 0x10(r29)
	  lfs       f0, -0x523C(r13)
	  stfs      f0, 0x14(r29)
	  lfs       f0, -0x5238(r13)
	  stfs      f0, 0x18(r29)
	  lfs       f0, -0x5234(r13)
	  stfs      f0, 0x1C(r29)
	  lfs       f0, -0x5230(r13)
	  stfs      f0, 0x20(r29)
	  lfs       f0, -0x522C(r13)
	  stfs      f0, 0x24(r29)
	  stw       r0, 0x0(r29)
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
 * Address:	........
 * Size:	000044
 */
void SeContext::getPos()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void SeContext::getObjType()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void SeContext::createEvent(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A3DD0
 * Size:	0000D4
 */
void SeContext::playSound(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  mr        r30, r3
	  lwz       r3, 0x3038(r13)
	  bl        0x14D8
	  lwz       r0, 0x8(r30)
	  addi      r31, r3, 0
	  cmpwi     r0, -0x1
	  bne-      .loc_0x9C
	  lwz       r3, 0x4(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  lfsu      f0, 0x94(r3)
	  addi      r4, r1, 0x24
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x2C(r1)
	  b         .loc_0x78

	.loc_0x5C:
	  lfs       f0, 0x1C(r30)
	  addi      r4, r1, 0x24
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x20(r30)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x24(r30)
	  stfs      f0, 0x2C(r1)

	.loc_0x78:
	  lwz       r3, 0x3038(r13)
	  addi      r5, r30, 0x10
	  bl        0x1378
	  lwz       r3, 0x3038(r13)
	  mr        r4, r30
	  lhz       r5, 0xC(r30)
	  addi      r6, r30, 0x10
	  bl        0x398
	  stw       r3, 0x8(r30)

	.loc_0x9C:
	  lwz       r3, 0x8(r30)
	  cmpwi     r3, -0x1
	  beq-      .loc_0xBC
	  mr        r4, r31
	  bl        -0x8C35C
	  lwz       r3, 0x3038(r13)
	  lwz       r0, 0x64(r3)
	  stw       r0, 0x0(r30)

	.loc_0xBC:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A3EA4
 * Size:	000048
 */
void SeContext::stopSound(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x3038(r13)
	  bl        0x1408
	  lwz       r0, 0x8(r31)
	  addi      r4, r3, 0
	  cmpwi     r0, -0x1
	  beq-      .loc_0x34
	  mr        r3, r0
	  bl        -0x8C0D4

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
 * Address:	800A3EEC
 * Size:	000094
 */
void SeContext::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x80
	  lwz       r3, 0x4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  lfsu      f0, 0x94(r3)
	  addi      r4, r1, 0x1C
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x24(r1)
	  b         .loc_0x68

	.loc_0x4C:
	  lfs       f0, 0x1C(r31)
	  addi      r4, r1, 0x1C
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x20(r31)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x24(r31)
	  stfs      f0, 0x24(r1)

	.loc_0x68:
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x10
	  bl        0x126C
	  lwz       r3, 0x8(r31)
	  addi      r4, r31, 0x10
	  bl        -0x8C4A8

	.loc_0x80:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A3F80
 * Size:	000058
 */
void SeContext::releaseEvent()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r5, 0x8(r3)
	  cmpwi     r5, -0x1
	  beq-      .loc_0x38
	  lwz       r3, 0x3038(r13)
	  mr        r4, r31
	  bl        0x820
	  li        r0, -0x1
	  stw       r0, 0x8(r31)
	  b         .loc_0x44

	.loc_0x38:
	  li        r0, -0x1
	  stw       r0, 0x8(r31)
	  li        r3, 0

	.loc_0x44:
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
 * Size:	000030
 */
void SeContext::dump()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A3FD8
 * Size:	000120
 */
SeSystem::SeSystem()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  li        r3, 0x1
	  stw       r30, 0x28(r1)
	  li        r30, 0x10
	  stw       r29, 0x24(r1)
	  lfs       f0, -0x7268(r2)
	  stfs      f0, 0x50(r31)
	  stfs      f0, 0x4C(r31)
	  stfs      f0, 0x48(r31)
	  stb       r3, 0x75(r31)
	  stw       r0, 0x54(r31)
	  stw       r30, 0x58(r31)
	  lwz       r29, 0x58(r31)
	  mulli     r3, r29, 0x28
	  addi      r3, r3, 0x8
	  bl        -0x5D024
	  lis       r4, 0x800A
	  addi      r4, r4, 0x3C5C
	  addi      r7, r29, 0
	  li        r5, 0
	  li        r6, 0x28
	  bl        0x170BE8
	  stw       r3, 0x5C(r31)
	  stw       r30, 0x6C(r31)
	  lwz       r29, 0x6C(r31)
	  rlwinm    r3,r29,3,0,28
	  addi      r3, r3, 0x8
	  bl        -0x5D054
	  lis       r4, 0x800A
	  addi      r4, r4, 0x40F8
	  addi      r7, r29, 0
	  li        r5, 0
	  li        r6, 0x8
	  bl        0x170BB8
	  stw       r3, 0x70(r31)
	  li        r0, 0x14B
	  addi      r3, r31, 0x4
	  stw       r0, 0x0(r31)
	  bl        -0x662C8
	  li        r3, 0x54
	  bl        -0x5D088
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xC8
	  bl        -0x598

	.loc_0xC8:
	  stw       r29, 0x60(r31)
	  lis       r3, 0x803A
	  lis       r4, 0x802B
	  lwz       r5, 0x60(r31)
	  subi      r3, r3, 0x2848
	  addi      r4, r4, 0x4DB0
	  bl        -0x51358
	  lfs       f0, -0x7264(r2)
	  mr        r3, r31
	  stfs      f0, 0x44(r31)
	  bl        0x44
	  li        r0, 0
	  stb       r0, 0x74(r31)
	  mr        r3, r31
	  stw       r0, 0x64(r31)
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
 * Address:	800A40F8
 * Size:	000014
 */
SeSystem::Event::Event()
{
	/*
	.loc_0x0:
	  li        r0, -0x1
	  stw       r0, 0x0(r3)
	  li        r0, 0
	  stw       r0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A410C
 * Size:	000078
 */
void SeSystem::initEvent()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x8C0E0
	  li        r5, 0
	  stw       r5, 0x68(r31)
	  addi      r6, r5, 0
	  li        r7, 0
	  li        r4, -0x1
	  b         .loc_0x4C

	.loc_0x30:
	  lwz       r3, 0x70(r31)
	  addi      r0, r6, 0x4
	  addi      r7, r7, 0x1
	  stwx      r4, r3, r6
	  addi      r6, r6, 0x8
	  lwz       r3, 0x70(r31)
	  stwx      r5, r3, r0

	.loc_0x4C:
	  lwz       r0, 0x6C(r31)
	  cmpw      r7, r0
	  blt+      .loc_0x30
	  li        r0, 0
	  stb       r0, 0x75(r31)
	  stw       r0, 0x64(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A4184
 * Size:	000078
 */
void SeSystem::resetSystem()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x8C158
	  li        r5, 0
	  stw       r5, 0x68(r31)
	  addi      r6, r5, 0
	  addi      r7, r5, 0
	  li        r4, -0x1
	  b         .loc_0x4C

	.loc_0x30:
	  lwz       r3, 0x70(r31)
	  addi      r0, r7, 0x4
	  addi      r6, r6, 0x1
	  stwx      r4, r3, r7
	  addi      r7, r7, 0x8
	  lwz       r3, 0x70(r31)
	  stwx      r5, r3, r0

	.loc_0x4C:
	  lwz       r0, 0x6C(r31)
	  cmpw      r6, r0
	  blt+      .loc_0x30
	  li        r0, 0
	  stb       r0, 0x75(r31)
	  stw       r0, 0x64(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A41FC
 * Size:	00020C
 */
void SeSystem::createEvent(SeContext*, int, SVector_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r27, 0x34(r1)
	  mr        r28, r3
	  addi      r29, r4, 0
	  addi      r30, r5, 0
	  addi      r31, r6, 0
	  lbz       r0, 0x75(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  li        r3, -0x1
	  b         .loc_0x1F8

	.loc_0x34:
	  lwz       r0, 0x68(r28)
	  li        r3, -0x1
	  lwz       r4, 0x6C(r28)
	  cmpw      r0, r4
	  bge-      .loc_0xA8
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x8C8AC
	  cmpwi     r3, -0x1
	  bne-      .loc_0x84
	  mr        r3, r28
	  bl        0xB44
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x7C

	.loc_0x78:
	  bdnz-     .loc_0x78

	.loc_0x7C:
	  li        r3, -0x1
	  b         .loc_0x1F8

	.loc_0x84:
	  lwz       r4, 0x68(r28)
	  lwz       r5, 0x70(r28)
	  addi      r0, r4, 0x1
	  rlwinm    r4,r4,3,0,28
	  stw       r0, 0x68(r28)
	  add       r4, r5, r4
	  stw       r3, 0x0(r4)
	  stw       r29, 0x4(r4)
	  b         .loc_0x1F8

	.loc_0xA8:
	  lfs       f1, 0x0(r31)
	  cmpwi     r4, 0
	  lfs       f0, 0x4(r31)
	  mtctr     r4
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  lfs       f2, 0x8(r31)
	  li        r6, -0x1
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  li        r7, 0
	  li        r5, 0
	  fadds     f3, f2, f0
	  ble-      .loc_0x130

	.loc_0xE0:
	  lwz       r4, 0x70(r28)
	  addi      r0, r5, 0x4
	  lwzx      r4, r4, r0
	  cmplwi    r4, 0
	  beq-      .loc_0x124
	  lfs       f1, 0x10(r4)
	  lfs       f0, 0x14(r4)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x18(r4)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fcmpo     cr0, f0, f3
	  ble-      .loc_0x124
	  fmr       f3, f0
	  mr        r6, r7

	.loc_0x124:
	  addi      r5, r5, 0x8
	  addi      r7, r7, 0x1
	  bdnz+     .loc_0xE0

	.loc_0x130:
	  cmpwi     r6, -0x1
	  beq-      .loc_0x1F8
	  lwz       r3, 0x70(r28)
	  rlwinm    r0,r6,3,0,28
	  add       r3, r3, r0
	  lwz       r27, 0x4(r3)
	  lwz       r5, 0x8(r27)
	  cmpwi     r5, -0x1
	  beq-      .loc_0x170
	  lwz       r3, 0x3038(r13)
	  mr        r4, r27
	  bl        0x470
	  li        r0, -0x1
	  stw       r0, 0x8(r27)
	  mr        r27, r3
	  b         .loc_0x17C

	.loc_0x170:
	  li        r0, -0x1
	  stw       r0, 0x8(r27)
	  li        r27, 0

	.loc_0x17C:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x8C9E0
	  addi      r31, r3, 0
	  cmpwi     r31, -0x1
	  bne-      .loc_0x1BC
	  rlwinm.   r0,r27,0,24,31
	  beq-      .loc_0x1BC
	  mr        r3, r28
	  bl        0xA04
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x1BC

	.loc_0x1B8:
	  bdnz-     .loc_0x1B8

	.loc_0x1BC:
	  lwz       r0, 0x68(r28)
	  addi      r3, r31, 0
	  lwz       r4, 0x70(r28)
	  rlwinm    r0,r0,3,0,28
	  stwx      r31, r4, r0
	  lwz       r0, 0x68(r28)
	  lwz       r4, 0x70(r28)
	  rlwinm    r0,r0,3,0,28
	  add       r4, r4, r0
	  stw       r29, 0x4(r4)
	  lwz       r4, 0x68(r28)
	  addi      r0, r4, 0x1
	  stw       r0, 0x68(r28)
	  stw       r31, 0x8(r29)
	  sth       r30, 0xC(r29)

	.loc_0x1F8:
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A4408
 * Size:	00002C
 */
void SeSystem::playPikiSound(int, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r6, r5, 0
	  stw       r0, 0x4(r1)
	  addi      r5, r4, 0
	  li        r4, 0x6
	  stwu      r1, -0x8(r1)
	  bl        .loc_0x2C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x2C:
	*/
}

/*
 * --INFO--
 * Address:	800A4434
 * Size:	000394
 */
void SeSystem::playSoundDirect(int, int, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stfd      f29, 0xD0(r1)
	  stfd      f28, 0xC8(r1)
	  stmw      r25, 0xAC(r1)
	  mr        r27, r3
	  mr        r28, r4
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  li        r26, -0x1
	  li        r25, 0
	  li        r31, 0
	  lfs       f28, -0x7260(r2)
	  lfs       f29, -0x7268(r2)
	  lfd       f30, -0x7258(r2)
	  lfd       f31, -0x7250(r2)
	  b         .loc_0x144

	.loc_0x50:
	  lwz       r0, 0x70(r27)
	  add       r3, r0, r31
	  lwz       r5, 0x4(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0x13C
	  lhz       r0, 0xC(r5)
	  cmpw      r0, r28
	  bne-      .loc_0x13C
	  lwz       r4, 0x4(r5)
	  cmplwi    r4, 0
	  beq-      .loc_0x8C
	  addi      r3, r1, 0x7C
	  addi      r4, r4, 0x94
	  bl        -0x31374
	  b         .loc_0x98

	.loc_0x8C:
	  addi      r3, r1, 0x7C
	  addi      r4, r5, 0x1C
	  bl        -0x31384

	.loc_0x98:
	  lfs       f3, 0x80(r1)
	  lfs       f2, 0x4(r30)
	  lfs       f1, 0x7C(r1)
	  lfs       f0, 0x0(r30)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x84(r1)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x8(r30)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x128
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x70(r1)
	  lfs       f2, 0x70(r1)

	.loc_0x128:
	  fcmpo     cr0, f2, f28
	  cror      2, 0, 0x2
	  bne-      .loc_0x13C
	  mr        r26, r25
	  fmr       f28, f2

	.loc_0x13C:
	  addi      r31, r31, 0x8
	  addi      r25, r25, 0x1

	.loc_0x144:
	  lwz       r0, 0x68(r27)
	  cmpw      r25, r0
	  blt+      .loc_0x50
	  cmpwi     r26, -0x1
	  beq-      .loc_0x1FC
	  lwz       r5, 0x70(r27)
	  rlwinm    r0,r26,3,0,28
	  lwz       r3, 0x3038(r13)
	  addi      r4, r29, 0
	  add       r5, r5, r0
	  lwz       r28, 0x4(r5)
	  bl        0xD20
	  lwz       r0, 0x8(r28)
	  addi      r27, r3, 0
	  cmpwi     r0, -0x1
	  bne-      .loc_0x1D8
	  lwz       r4, 0x4(r28)
	  cmplwi    r4, 0
	  beq-      .loc_0x1A4
	  addi      r3, r1, 0x64
	  addi      r4, r4, 0x94
	  bl        -0x31488
	  addi      r4, r1, 0x64
	  b         .loc_0x1B4

	.loc_0x1A4:
	  addi      r3, r1, 0x64
	  addi      r4, r28, 0x1C
	  bl        -0x3149C
	  addi      r4, r1, 0x64

	.loc_0x1B4:
	  lwz       r3, 0x3038(r13)
	  addi      r5, r28, 0x10
	  bl        0xBD8
	  lwz       r3, 0x3038(r13)
	  mr        r4, r28
	  lhz       r5, 0xC(r28)
	  addi      r6, r28, 0x10
	  bl        -0x408
	  stw       r3, 0x8(r28)

	.loc_0x1D8:
	  lwz       r3, 0x8(r28)
	  cmpwi     r3, -0x1
	  beq-      .loc_0x370
	  mr        r4, r27
	  bl        -0x8CAFC
	  lwz       r3, 0x3038(r13)
	  lwz       r0, 0x64(r3)
	  stw       r0, 0x0(r28)
	  b         .loc_0x370

	.loc_0x1FC:
	  lwz       r6, 0x54(r27)
	  lwz       r3, 0x58(r27)
	  addi      r4, r6, 0x1
	  lwz       r5, 0x5C(r27)
	  divw      r0, r4, r3
	  mullw     r0, r0, r3
	  mulli     r3, r6, 0x28
	  sub       r0, r4, r0
	  add       r31, r5, r3
	  stw       r0, 0x54(r27)
	  mr        r4, r31
	  lwz       r5, 0x8(r31)
	  cmpwi     r5, -0x1
	  beq-      .loc_0x248
	  lwz       r3, 0x3038(r13)
	  bl        .loc_0x394
	  li        r0, -0x1
	  stw       r0, 0x8(r31)
	  b         .loc_0x250

	.loc_0x248:
	  li        r0, -0x1
	  stw       r0, 0x8(r31)

	.loc_0x250:
	  lwz       r5, 0x8(r31)
	  cmpwi     r5, -0x1
	  beq-      .loc_0x280
	  mr        r4, r31
	  beq-      .loc_0x278
	  lwz       r3, 0x3038(r13)
	  bl        .loc_0x394
	  li        r0, -0x1
	  stw       r0, 0x8(r31)
	  b         .loc_0x280

	.loc_0x278:
	  li        r0, -0x1
	  stw       r0, 0x8(r31)

	.loc_0x280:
	  li        r0, -0x1
	  stw       r0, 0x8(r31)
	  li        r0, 0
	  mr        r4, r29
	  stw       r0, 0x4(r31)
	  sth       r28, 0xC(r31)
	  lfs       f0, -0x5240(r13)
	  stfs      f0, 0x10(r31)
	  lfs       f0, -0x523C(r13)
	  stfs      f0, 0x14(r31)
	  lfs       f0, -0x5238(r13)
	  stfs      f0, 0x18(r31)
	  lfs       f0, -0x5234(r13)
	  stfs      f0, 0x1C(r31)
	  lfs       f0, -0x5230(r13)
	  stfs      f0, 0x20(r31)
	  lfs       f0, -0x522C(r13)
	  stfs      f0, 0x24(r31)
	  stw       r0, 0x0(r31)
	  lwz       r3, 0x0(r30)
	  lwz       r0, 0x4(r30)
	  stw       r3, 0x1C(r31)
	  stw       r0, 0x20(r31)
	  lwz       r0, 0x8(r30)
	  stw       r0, 0x24(r31)
	  lwz       r3, 0x3038(r13)
	  bl        0xBA8
	  lwz       r0, 0x8(r31)
	  addi      r27, r3, 0
	  cmpwi     r0, -0x1
	  bne-      .loc_0x350
	  lwz       r4, 0x4(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x31C
	  addi      r3, r1, 0x50
	  addi      r4, r4, 0x94
	  bl        -0x31600
	  addi      r4, r1, 0x50
	  b         .loc_0x32C

	.loc_0x31C:
	  addi      r3, r1, 0x50
	  addi      r4, r31, 0x1C
	  bl        -0x31614
	  addi      r4, r1, 0x50

	.loc_0x32C:
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x10
	  bl        0xA60
	  lwz       r3, 0x3038(r13)
	  mr        r4, r31
	  lhz       r5, 0xC(r31)
	  addi      r6, r31, 0x10
	  bl        -0x580
	  stw       r3, 0x8(r31)

	.loc_0x350:
	  lwz       r3, 0x8(r31)
	  cmpwi     r3, -0x1
	  beq-      .loc_0x370
	  mr        r4, r27
	  bl        -0x8CC74
	  lwz       r3, 0x3038(r13)
	  lwz       r0, 0x64(r3)
	  stw       r0, 0x0(r31)

	.loc_0x370:
	  lmw       r25, 0xAC(r1)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lfd       f29, 0xD0(r1)
	  lfd       f28, 0xC8(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr

	.loc_0x394:
	*/
}

/*
 * --INFO--
 * Address:	800A47C8
 * Size:	000108
 */
void SeSystem::destroyEvent(SeContext*, s32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  stw       r28, 0x20(r1)
	  addi      r28, r5, 0
	  bl        .loc_0x108
	  addi      r29, r3, 0
	  cmpwi     r29, -0x1
	  beq-      .loc_0xE4
	  bl        -0x8C77C
	  addi      r30, r3, 0
	  addi      r3, r28, 0
	  bl        -0x8C868
	  bl        -0x8C78C
	  cmpw      r30, r3
	  bne-      .loc_0x68
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x68

	.loc_0x64:
	  bdnz-     .loc_0x64

	.loc_0x68:
	  lwz       r3, 0x68(r31)
	  addi      r5, r29, 0
	  rlwinm    r4,r29,3,0,28
	  subi      r0, r3, 0x1
	  stw       r0, 0x68(r31)
	  b         .loc_0xA8

	.loc_0x80:
	  lwz       r0, 0x70(r31)
	  addi      r5, r5, 0x1
	  add       r3, r0, r4
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x0(r3)
	  lwz       r0, 0x70(r31)
	  add       r3, r0, r4
	  lwz       r0, 0xC(r3)
	  addi      r4, r4, 0x8
	  stw       r0, 0x4(r3)

	.loc_0xA8:
	  lwz       r0, 0x68(r31)
	  cmpw      r5, r0
	  blt+      .loc_0x80
	  lwz       r3, 0x70(r31)
	  rlwinm    r0,r0,3,0,28
	  li        r4, -0x1
	  stwx      r4, r3, r0
	  li        r5, 0
	  li        r3, 0x1
	  lwz       r0, 0x68(r31)
	  lwz       r4, 0x70(r31)
	  rlwinm    r0,r0,3,0,28
	  add       r4, r4, r0
	  stw       r5, 0x4(r4)
	  b         .loc_0xE8

	.loc_0xE4:
	  li        r3, 0

	.loc_0xE8:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x108:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void SeSystem::getEvent(s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A48D0
 * Size:	000048
 */
void SeSystem::getEvent(SeContext*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x68(r3)
	  li        r7, 0
	  li        r6, 0
	  cmpwi     r0, 0
	  mtctr     r0
	  ble-      .loc_0x40

	.loc_0x18:
	  lwz       r5, 0x70(r3)
	  addi      r0, r6, 0x4
	  lwzx      r0, r5, r0
	  cmplw     r0, r4
	  bne-      .loc_0x34
	  mr        r3, r7
	  blr

	.loc_0x34:
	  addi      r6, r6, 0x8
	  addi      r7, r7, 0x1
	  bdnz+     .loc_0x18

	.loc_0x40:
	  li        r3, -0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A4918
 * Size:	0001B8
 */
void SeSystem::draw3d(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  li        r0, 0xFF
	  stwu      r1, -0x148(r1)
	  stfd      f31, 0x140(r1)
	  stw       r31, 0x13C(r1)
	  addi      r31, r4, 0
	  addi      r4, r1, 0x1C
	  stw       r30, 0x138(r1)
	  addi      r30, r3, 0
	  mr        r3, r31
	  stw       r29, 0x134(r1)
	  li        r29, 0
	  stw       r28, 0x130(r1)
	  stb       r0, 0x1C(r1)
	  stb       r29, 0x1D(r1)
	  stb       r29, 0x1E(r1)
	  stb       r0, 0x1F(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lfs       f31, -0x7248(r2)
	  li        r28, 0
	  b         .loc_0x188

	.loc_0xC0:
	  lwz       r3, 0x70(r30)
	  addi      r0, r29, 0x4
	  lwzx      r3, r3, r0
	  cmplwi    r3, 0
	  beq-      .loc_0x180
	  lwz       r4, 0x4(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0xF0
	  lfs       f0, 0x94(r4)
	  lfs       f1, 0x98(r4)
	  lfs       f2, 0x9C(r4)
	  b         .loc_0xFC

	.loc_0xF0:
	  lfs       f0, 0x1C(r3)
	  lfs       f1, 0x20(r3)
	  lfs       f2, 0x24(r3)

	.loc_0xFC:
	  stfs      f0, 0x20(r1)
	  addi      r3, r1, 0x20
	  stfs      f1, 0x24(r1)
	  stfs      f2, 0x28(r1)
	  lfs       f0, 0x24(r1)
	  fadds     f0, f0, f31
	  stfs      f0, 0x24(r1)
	  lwz       r4, 0x2E4(r31)
	  addi      r4, r4, 0x1E0
	  bl        -0x6D2EC
	  addi      r5, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x2C
	  subi      r4, r13, 0x5228
	  bl        0x171B4C
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x2C
	  lwz       r3, 0x10(r3)
	  bl        -0x7C928
	  lwz       r12, 0x3B4(r31)
	  srawi     r0, r3, 0x1
	  lwz       r4, 0x2DEC(r13)
	  addze     r0, r0
	  lwz       r12, 0xF0(r12)
	  lwz       r4, 0x10(r4)
	  addi      r3, r31, 0
	  mtlr      r12
	  neg       r6, r0
	  addi      r5, r1, 0x20
	  crclr     6, 0x6
	  addi      r8, r1, 0x2C
	  li        r7, 0
	  blrl

	.loc_0x180:
	  addi      r29, r29, 0x8
	  addi      r28, r28, 0x1

	.loc_0x188:
	  lwz       r0, 0x6C(r30)
	  cmpw      r28, r0
	  blt+      .loc_0xC0
	  lwz       r0, 0x14C(r1)
	  lfd       f31, 0x140(r1)
	  lwz       r31, 0x13C(r1)
	  lwz       r30, 0x138(r1)
	  lwz       r29, 0x134(r1)
	  lwz       r28, 0x130(r1)
	  addi      r1, r1, 0x148
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A4AD0
 * Size:	0002D0
 */
void SeSystem::draw2d(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x170(r1)
	  stmw      r24, 0x150(r1)
	  li        r25, 0xFF
	  addi      r27, r4, 0
	  addi      r26, r3, 0
	  addi      r31, r5, 0x1E10
	  addi      r4, r1, 0x18
	  mr        r3, r27
	  li        r5, 0x1
	  stb       r25, 0x18(r1)
	  stb       r25, 0x19(r1)
	  stb       r25, 0x1A(r1)
	  stb       r25, 0x1B(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r5, 0x37
	  stb       r5, 0x14(r1)
	  li        r0, 0x80
	  addi      r4, r1, 0x14
	  stb       r5, 0x15(r1)
	  mr        r3, r27
	  stb       r5, 0x16(r1)
	  li        r5, 0x1
	  stb       r0, 0x17(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x6C(r26)
	  li        r0, 0x14
	  li        r3, 0x3C
	  stw       r0, 0x40(r1)
	  rlwinm    r4,r4,4,0,27
	  li        r0, 0x226
	  stw       r3, 0x44(r1)
	  addi      r5, r4, 0x78
	  addi      r3, r27, 0
	  stw       r0, 0x48(r1)
	  addi      r4, r1, 0x40
	  stw       r5, 0x4C(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl
	  stb       r25, 0x10(r1)
	  addi      r4, r1, 0x10
	  addi      r3, r27, 0
	  stb       r25, 0x11(r1)
	  li        r5, 0x1
	  stb       r25, 0x12(r1)
	  stb       r25, 0x13(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x68(r26)
	  addi      r3, r1, 0x50
	  lwz       r6, 0x6C(r26)
	  addi      r4, r31, 0x2FB0
	  lfs       f1, 0x48(r26)
	  lfs       f2, 0x4C(r26)
	  crset     6, 0x6
	  lfs       f3, 0x50(r26)
	  lwz       r7, 0x64(r26)
	  bl        0x171998
	  mr        r3, r27
	  lwz       r4, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r27)
	  addi      r7, r1, 0x50
	  lwz       r4, 0x10(r4)
	  crclr     6, 0x6
	  lwz       r12, 0xEC(r12)
	  li        r5, 0x1E
	  mtlr      r12
	  li        r6, 0x46
	  blrl
	  lis       r3, 0x8022
	  addi      r4, r3, 0x2418
	  lwz       r3, 0x0(r4)
	  addi      r25, r1, 0x1C
	  lwz       r0, 0x4(r4)
	  li        r29, 0x5A
	  li        r28, 0
	  stw       r3, 0x1C(r1)
	  li        r30, 0
	  stw       r0, 0x20(r1)
	  lwz       r3, 0x8(r4)
	  lwz       r0, 0xC(r4)
	  stw       r3, 0x24(r1)
	  stw       r0, 0x28(r1)
	  lwz       r3, 0x10(r4)
	  lwz       r0, 0x14(r4)
	  stw       r3, 0x2C(r1)
	  stw       r0, 0x30(r1)
	  lwz       r3, 0x18(r4)
	  lwz       r0, 0x1C(r4)
	  stw       r3, 0x34(r1)
	  stw       r0, 0x38(r1)
	  lwz       r0, 0x20(r4)
	  stw       r0, 0x3C(r1)
	  b         .loc_0x2B0

	.loc_0x1C4:
	  lwz       r0, 0x70(r26)
	  add       r3, r0, r30
	  lwz       r24, 0x4(r3)
	  cmplwi    r24, 0
	  beq-      .loc_0x25C
	  lwz       r3, 0x4(r24)
	  cmplwi    r3, 0
	  beq-      .loc_0x1F0
	  lwz       r3, 0x6C(r3)
	  bl        -0x10280
	  b         .loc_0x1F4

	.loc_0x1F0:
	  subi      r3, r13, 0x51D8

	.loc_0x1F4:
	  lhz       r0, 0xC(r24)
	  mr        r5, r28
	  lwz       r9, 0x0(r24)
	  addi      r6, r3, 0
	  rlwinm    r8,r0,2,0,29
	  lwz       r0, 0x64(r26)
	  addi      r3, r1, 0x50
	  lwz       r7, 0x8(r24)
	  addi      r4, r31, 0x2FE4
	  lwzx      r8, r25, r8
	  sub       r9, r0, r9
	  crclr     6, 0x6
	  bl        0x1718A4
	  mr        r3, r27
	  lwz       r4, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r27)
	  mr        r6, r29
	  lwz       r4, 0x10(r4)
	  addi      r7, r1, 0x50
	  lwz       r12, 0xEC(r12)
	  crclr     6, 0x6
	  li        r5, 0x37
	  mtlr      r12
	  blrl
	  addi      r29, r29, 0x10
	  b         .loc_0x2A8

	.loc_0x25C:
	  lwz       r6, 0x0(r3)
	  addi      r5, r28, 0
	  addi      r7, r24, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x50
	  addi      r4, r31, 0x2FFC
	  bl        0x171854
	  mr        r3, r27
	  lwz       r4, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r27)
	  mr        r6, r29
	  lwz       r4, 0x10(r4)
	  addi      r7, r1, 0x50
	  lwz       r12, 0xEC(r12)
	  crclr     6, 0x6
	  li        r5, 0x37
	  mtlr      r12
	  blrl
	  addi      r29, r29, 0x10

	.loc_0x2A8:
	  addi      r30, r30, 0x8
	  addi      r28, r28, 0x1

	.loc_0x2B0:
	  lwz       r0, 0x6C(r26)
	  cmpw      r28, r0
	  blt+      .loc_0x1C4
	  lmw       r24, 0x150(r1)
	  lwz       r0, 0x174(r1)
	  addi      r1, r1, 0x170
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A4DA0
 * Size:	0000B8
 */
void SeSystem::dumpEvents()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  li        r31, 0
	  stw       r30, 0xA0(r1)
	  li        r30, 0
	  stw       r29, 0x9C(r1)
	  addi      r29, r3, 0
	  b         .loc_0x58

	.loc_0x28:
	  lwz       r0, 0x70(r29)
	  add       r3, r0, r31
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  lwz       r3, 0x6C(r3)
	  bl        -0x103B4

	.loc_0x50:
	  addi      r31, r31, 0x8
	  addi      r30, r30, 0x1

	.loc_0x58:
	  lwz       r0, 0x6C(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x28
	  addi      r3, r1, 0x14
	  bl        -0x8CD48
	  mr        r31, r3
	  bl        -0x8CD90
	  cmplwi    r31, 0
	  ble-      .loc_0x9C
	  rlwinm.   r0,r31,29,3,31
	  mtctr     r0
	  beq-      .loc_0x94

	.loc_0x88:
	  bdnz-     .loc_0x88
	  andi.     r31, r31, 0x7
	  beq-      .loc_0x9C

	.loc_0x94:
	  mtctr     r31

	.loc_0x98:
	  bdnz-     .loc_0x98

	.loc_0x9C:
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  lwz       r29, 0x9C(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A4E58
 * Size:	000368
 */
void SeSystem::update(Graphics&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stfd      f31, 0xA0(r1)
	  stmw      r26, 0x88(r1)
	  mr        r31, r3
	  lbz       r0, 0x75(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x350
	  lwz       r6, 0x0(r5)
	  addi      r3, r1, 0x78
	  lwz       r0, 0x4(r5)
	  stw       r6, 0x48(r31)
	  stw       r0, 0x4C(r31)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x50(r31)
	  lwz       r6, 0x2E4(r4)
	  addi      r4, r1, 0x6C
	  lwz       r5, 0x1E0(r6)
	  lwz       r0, 0x1E4(r6)
	  stw       r5, 0x4(r31)
	  stw       r0, 0x8(r31)
	  lwz       r5, 0x1E8(r6)
	  lwz       r0, 0x1EC(r6)
	  stw       r5, 0xC(r31)
	  stw       r0, 0x10(r31)
	  lwz       r5, 0x1F0(r6)
	  lwz       r0, 0x1F4(r6)
	  stw       r5, 0x14(r31)
	  stw       r0, 0x18(r31)
	  lwz       r5, 0x1F8(r6)
	  lwz       r0, 0x1FC(r6)
	  stw       r5, 0x1C(r31)
	  stw       r0, 0x20(r31)
	  lwz       r5, 0x200(r6)
	  lwz       r0, 0x204(r6)
	  stw       r5, 0x24(r31)
	  stw       r0, 0x28(r31)
	  lwz       r5, 0x208(r6)
	  lwz       r0, 0x20C(r6)
	  stw       r5, 0x2C(r31)
	  stw       r0, 0x30(r31)
	  lwz       r5, 0x210(r6)
	  lwz       r0, 0x214(r6)
	  stw       r5, 0x34(r31)
	  stw       r0, 0x38(r31)
	  lwz       r5, 0x218(r6)
	  lwz       r0, 0x21C(r6)
	  stw       r5, 0x3C(r31)
	  stw       r0, 0x40(r31)
	  lfs       f0, -0x7268(r2)
	  stfs      f0, 0x80(r1)
	  stfs      f0, 0x74(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f0, 0x70(r1)
	  stfs      f0, 0x78(r1)
	  stfs      f0, 0x6C(r1)
	  bl        -0x8D6DC
	  li        r28, 0
	  li        r29, 0
	  b         .loc_0x170

	.loc_0xF4:
	  lwz       r0, 0x5C(r31)
	  add       r30, r0, r29
	  lwz       r0, 0x8(r30)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x168
	  lwz       r3, 0x4(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x134
	  lfsu      f0, 0x94(r3)
	  addi      r4, r1, 0x54
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x5C(r1)
	  b         .loc_0x150

	.loc_0x134:
	  lfs       f0, 0x1C(r30)
	  addi      r4, r1, 0x54
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x20(r30)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x24(r30)
	  stfs      f0, 0x5C(r1)

	.loc_0x150:
	  lwz       r3, 0x3038(r13)
	  addi      r5, r30, 0x10
	  bl        0x218
	  lwz       r3, 0x8(r30)
	  addi      r4, r30, 0x10
	  bl        -0x8D4FC

	.loc_0x168:
	  addi      r29, r29, 0x28
	  addi      r28, r28, 0x1

	.loc_0x170:
	  lwz       r0, 0x58(r31)
	  cmpw      r28, r0
	  blt+      .loc_0xF4
	  lwz       r0, 0x3168(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x338
	  lwz       r3, 0x3120(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x338
	  bl        0x723D8
	  cmplwi    r3, 0
	  beq-      .loc_0x338
	  lwz       r3, 0x3120(r13)
	  bl        0x723C8
	  lwz       r30, 0x3168(r13)
	  addi      r28, r3, 0
	  lwz       r4, 0x3038(r13)
	  li        r27, 0
	  lwz       r12, 0x0(r30)
	  lwz       r4, 0x60(r4)
	  addi      r3, r30, 0
	  lwz       r12, 0xC(r12)
	  lfs       f31, 0x50(r4)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x270

	.loc_0x1DC:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x200
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x218

	.loc_0x200:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x218:
	  mr        r26, r3
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x114(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x254
	  addi      r3, r26, 0
	  addi      r4, r28, 0
	  bl        -0x18218
	  fcmpo     cr0, f1, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x254
	  mr        r27, r26
	  fmr       f31, f1

	.loc_0x254:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x270:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x298
	  li        r0, 0x1
	  b         .loc_0x2C4

	.loc_0x298:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2C0
	  li        r0, 0x1
	  b         .loc_0x2C4

	.loc_0x2C0:
	  li        r0, 0

	.loc_0x2C4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x1DC
	  lbz       r0, 0x74(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x308
	  cmplwi    r27, 0
	  beq-      .loc_0x2F8
	  lwz       r3, 0x3038(r13)
	  lwz       r3, 0x60(r3)
	  lfs       f0, 0x50(r3)
	  fcmpo     cr0, f31, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x350

	.loc_0x2F8:
	  bl        -0x8BA30
	  li        r0, 0
	  stb       r0, 0x74(r31)
	  b         .loc_0x350

	.loc_0x308:
	  cmplwi    r27, 0
	  beq-      .loc_0x350
	  lwz       r3, 0x3038(r13)
	  lwz       r3, 0x60(r3)
	  lfs       f0, 0x40(r3)
	  fcmpo     cr0, f31, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x350
	  bl        -0x8BAA0
	  li        r0, 0x1
	  stb       r0, 0x74(r31)
	  b         .loc_0x350

	.loc_0x338:
	  lbz       r0, 0x74(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x350
	  bl        -0x8BA7C
	  li        r0, 0
	  stb       r0, 0x74(r31)

	.loc_0x350:
	  lmw       r26, 0x88(r1)
	  lwz       r0, 0xAC(r1)
	  lfd       f31, 0xA0(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A51C0
 * Size:	000008
 */
u32 Boss::isBossBgm() { return 0x0; }

/*
 * --INFO--
 * Address:	800A51C8
 * Size:	0000FC
 */
void SeSystem::calcCameraPos(Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x34
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x8(r4)
	  addi      r4, r30, 0x4
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x48(r30)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x4C(r30)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x50(r30)
	  stfs      f0, 0x30(r1)
	  bl        -0x6DAD0
	  addi      r3, r1, 0x28
	  addi      r4, r30, 0x4
	  bl        -0x6DADC
	  lfs       f1, 0x34(r1)
	  lfs       f0, 0x28(r1)
	  lfs       f3, 0x38(r1)
	  lfs       f2, 0x2C(r1)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x3C(r1)
	  lfs       f1, 0x30(r1)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x34(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x38(r1)
	  stfs      f0, 0x3C(r1)
	  lwz       r3, 0x3038(r13)
	  lfs       f3, -0x7244(r2)
	  lwz       r3, 0x60(r3)
	  lfs       f0, 0x34(r1)
	  lfs       f2, 0x30(r3)
	  lfs       f1, 0x38(r1)
	  fdivs     f3, f3, f2
	  lfs       f2, 0x3C(r1)
	  fmuls     f0, f0, f3
	  fmuls     f4, f1, f3
	  fmuls     f1, f2, f3
	  stfs      f0, 0x34(r1)
	  stfs      f4, 0x38(r1)
	  stfs      f1, 0x3C(r1)
	  lwz       r3, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  stw       r3, 0x0(r31)
	  stw       r0, 0x4(r31)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x8(r31)
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A52C4
 * Size:	000018
 */
void SeSystem::getJacID(int)
{
	/*
	.loc_0x0:
	  mulli     r0, r4, 0x14
	  lis       r3, 0x802B
	  addi      r3, r3, 0x33D4
	  add       r3, r3, r0
	  lwz       r3, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void SeSystem::getSoundName(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void SeSystem::getEventType(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SeSystem::isLoopType(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A52DC
 * Size:	000098
 */
void SeSystem::exitCourse()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  stb       r0, 0x75(r3)
	  bl        -0x55C
	  li        r31, 0
	  stb       r31, 0x74(r30)
	  bl        -0x8D2C8
	  stw       r31, 0x68(r30)
	  addi      r5, r31, 0
	  addi      r6, r31, 0
	  li        r4, -0x1
	  b         .loc_0x60

	.loc_0x44:
	  lwz       r3, 0x70(r30)
	  addi      r0, r6, 0x4
	  addi      r5, r5, 0x1
	  stwx      r4, r3, r6
	  addi      r6, r6, 0x8
	  lwz       r3, 0x70(r30)
	  stwx      r31, r3, r0

	.loc_0x60:
	  lwz       r0, 0x6C(r30)
	  cmpw      r5, r0
	  blt+      .loc_0x44
	  li        r3, 0
	  stb       r3, 0x75(r30)
	  li        r0, 0x1
	  stw       r3, 0x64(r30)
	  stb       r0, 0x75(r30)
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
 * Address:	800A5374
 * Size:	000034
 */
void SeSystem::playSysSe(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mulli     r0, r3, 0x14
	  stwu      r1, -0x8(r1)
	  lis       r3, 0x802B
	  addi      r3, r3, 0x33D4
	  add       r3, r3, r0
	  lwz       r3, 0x4(r3)
	  bl        -0x8E7F4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A53A8
 * Size:	000034
 */
void SeSystem::stopSysSe(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mulli     r0, r3, 0x14
	  stwu      r1, -0x8(r1)
	  lis       r3, 0x802B
	  addi      r3, r3, 0x33D4
	  add       r3, r3, r0
	  lwz       r3, 0x4(r3)
	  bl        -0x8E488
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A53DC
 * Size:	000034
 */
void SeSystem::playPlayerSe(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mulli     r0, r3, 0x14
	  stwu      r1, -0x8(r1)
	  lis       r3, 0x802B
	  addi      r3, r3, 0x33D4
	  add       r3, r3, r0
	  lwz       r3, 0x4(r3)
	  bl        -0x8D05C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A5410
 * Size:	000034
 */
void SeSystem::stopPlayerSe(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mulli     r0, r3, 0x14
	  stwu      r1, -0x8(r1)
	  lis       r3, 0x802B
	  addi      r3, r3, 0x33D4
	  add       r3, r3, r0
	  lwz       r3, 0x4(r3)
	  bl        -0x8CDB0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
