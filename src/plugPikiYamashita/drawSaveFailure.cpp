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
 * Address:	801F3560
 * Size:	0000F4
 */
zen::DrawSaveFailure::DrawSaveFailure()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  li        r3, 0x100
	  stw       r30, 0x40(r1)
	  bl        -0x1AC578
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x44
	  lis       r4, 0x802E
	  addi      r4, r4, 0x71E0
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x3402C

	.loc_0x44:
	  stw       r30, 0x0(r31)
	  lis       r3, 0x7361
	  addi      r4, r3, 0x7878
	  lwz       r3, 0x0(r31)
	  li        r5, 0x1
	  addi      r30, r3, 0x4
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x10(r31)
	  lis       r4, 0x6261
	  addi      r3, r30, 0
	  lwz       r8, 0x10(r31)
	  addi      r4, r4, 0x636B
	  li        r5, 0x1
	  lha       r6, 0x18(r8)
	  lha       r0, 0x1C(r8)
	  lha       r7, 0x1A(r8)
	  sub       r0, r0, r6
	  lha       r6, 0x1E(r8)
	  srawi     r0, r0, 0x1
	  sub       r7, r6, r7
	  extsh     r6, r0
	  srawi     r0, r7, 0x1
	  sth       r6, 0xB8(r8)
	  extsh     r0, r0
	  sth       r0, 0xBA(r8)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x14(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x2A0
	  mr        r3, r31
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
 * Address:	801F3654
 * Size:	0001F0
 */
void zen::DrawSaveFailure::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  li        r31, 0
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xF4
	  bge-      .loc_0x40
	  cmpwi     r0, 0
	  beq-      .loc_0x4C
	  bge-      .loc_0x54
	  b         .loc_0x1BC

	.loc_0x40:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x1BC
	  b         .loc_0x120

	.loc_0x4C:
	  li        r31, 0x1
	  b         .loc_0x1BC

	.loc_0x54:
	  mr        r3, r30
	  lfs       f1, 0xC(r30)
	  bl        0x2BC
	  fmr       f31, f1
	  lfs       f0, -0x3D70(r2)
	  fcmpu     cr0, f0, f31
	  bne-      .loc_0x80
	  addi      r3, r30, 0
	  li        r4, 0x2
	  bl        0x208
	  b         .loc_0x1BC

	.loc_0x80:
	  lfs       f0, -0x3D6C(r2)
	  fmuls     f1, f0, f31
	  bl        0x28478
	  lfs       f2, -0x3D70(r2)
	  fneg      f0, f1
	  lwz       r3, 0x10(r30)
	  fsubs     f1, f2, f31
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lfs       f1, -0x3D68(r2)
	  lfs       f0, -0x3D64(r2)
	  fmuls     f1, f1, f31
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xD4
	  lfs       f0, -0x3D60(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xDC

	.loc_0xD4:
	  lfs       f0, -0x3D60(r2)
	  fsubs     f0, f1, f0

	.loc_0xDC:
	  fctiwz    f0, f0
	  lwz       r3, 0x14(r30)
	  stfd      f0, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x1BC

	.loc_0xF4:
	  lis       r3, 0x100
	  lwz       r4, 0x28(r4)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0x1BC
	  addi      r3, r30, 0
	  li        r4, 0x3
	  bl        0x170
	  li        r3, 0x111
	  bl        -0x14E3F8
	  b         .loc_0x1BC

	.loc_0x120:
	  mr        r3, r30
	  lfs       f1, 0xC(r30)
	  bl        0x1F0
	  lfs       f0, -0x3D70(r2)
	  fcmpu     cr0, f0, f1
	  bne-      .loc_0x148
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x140
	  b         .loc_0x1BC

	.loc_0x148:
	  fsubs     f31, f0, f1
	  lfs       f0, -0x3D5C(r2)
	  fmuls     f1, f0, f31
	  bl        0x283AC
	  lfs       f2, -0x3D70(r2)
	  fneg      f0, f1
	  lwz       r3, 0x10(r30)
	  fsubs     f1, f2, f31
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lfs       f1, -0x3D68(r2)
	  lfs       f0, -0x3D64(r2)
	  fmuls     f1, f1, f31
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1A0
	  lfs       f0, -0x3D60(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x1A8

	.loc_0x1A0:
	  lfs       f0, -0x3D60(r2)
	  fsubs     f0, f1, f0

	.loc_0x1A8:
	  fctiwz    f0, f0
	  lwz       r3, 0x14(r30)
	  stfd      f0, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stb       r0, 0xF0(r3)

	.loc_0x1BC:
	  lwz       r3, 0x0(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F3844
 * Size:	00003C
 */
void zen::DrawSaveFailure::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x2C
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F3880
 * Size:	000054
 */
void zen::DrawSaveFailure::open(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stfd      f31, 0x18(r1)
	  fmr       f31, f1
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        .loc_0x54
	  stfs      f31, 0xC(r31)
	  li        r3, 0x12A
	  bl        -0x14E538
	  lwz       r3, 0x0(r31)
	  addi      r3, r3, 0x4
	  bl        -0x34114
	  lwz       r0, 0x24(r1)
	  lfd       f31, 0x18(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0x54:
	*/
}

/*
 * --INFO--
 * Address:	801F38D4
 * Size:	000098
 */
void zen::DrawSaveFailure::setMode(zen::DrawSaveFailure::modeFlag)
{
	/*
	.loc_0x0:
	  stw       r4, 0x4(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x68
	  bge-      .loc_0x24
	  cmpwi     r0, 0
	  beq-      .loc_0x30
	  bge-      .loc_0x5C
	  blr

	.loc_0x24:
	  cmpwi     r0, 0x4
	  bgelr-
	  b         .loc_0x8C

	.loc_0x30:
	  lfs       f0, -0x3D64(r2)
	  li        r0, 0
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0xC(r3)
	  lwz       r4, 0x10(r3)
	  stfs      f0, 0xC0(r4)
	  stfs      f0, 0xC4(r4)
	  stfs      f0, 0xC8(r4)
	  lwz       r3, 0x14(r3)
	  stb       r0, 0xF0(r3)
	  blr

	.loc_0x5C:
	  lfs       f0, -0x3D64(r2)
	  stfs      f0, 0x8(r3)
	  blr

	.loc_0x68:
	  lwz       r4, 0x10(r3)
	  li        r0, 0xB4
	  lfs       f0, -0x3D70(r2)
	  stfs      f0, 0xC0(r4)
	  stfs      f0, 0xC4(r4)
	  stfs      f0, 0xC8(r4)
	  lwz       r3, 0x14(r3)
	  stb       r0, 0xF0(r3)
	  blr

	.loc_0x8C:
	  lfs       f0, -0x3D64(r2)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F396C
 * Size:	000034
 */
void zen::DrawSaveFailure::calcFrame(f32)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f2, 0x8(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f2, f0
	  stfs      f0, 0x8(r3)
	  lfs       f0, 0x8(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x2C
	  stfs      f1, 0x8(r3)
	  lfs       f1, -0x3D70(r2)
	  blr

	.loc_0x2C:
	  fdivs     f1, f0, f1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F39A0
 * Size:	000098
 */
void zen::DrawSaveFailure::init()
{
	/*
	.loc_0x0:
	  li        r4, 0
	  stw       r4, 0x4(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x68
	  bge-      .loc_0x28
	  cmpwi     r0, 0
	  beq-      .loc_0x34
	  bge-      .loc_0x5C
	  blr

	.loc_0x28:
	  cmpwi     r0, 0x4
	  bgelr-
	  b         .loc_0x8C

	.loc_0x34:
	  lfs       f0, -0x3D64(r2)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0xC(r3)
	  lwz       r5, 0x10(r3)
	  stfs      f0, 0xC0(r5)
	  stfs      f0, 0xC4(r5)
	  stfs      f0, 0xC8(r5)
	  lwz       r3, 0x14(r3)
	  stb       r4, 0xF0(r3)
	  blr

	.loc_0x5C:
	  lfs       f0, -0x3D64(r2)
	  stfs      f0, 0x8(r3)
	  blr

	.loc_0x68:
	  lwz       r4, 0x10(r3)
	  li        r0, 0xB4
	  lfs       f0, -0x3D70(r2)
	  stfs      f0, 0xC0(r4)
	  stfs      f0, 0xC4(r4)
	  stfs      f0, 0xC8(r4)
	  lwz       r3, 0x14(r3)
	  stb       r0, 0xF0(r3)
	  blr

	.loc_0x8C:
	  lfs       f0, -0x3D64(r2)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}
