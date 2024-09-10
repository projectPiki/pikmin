#include "types.h"

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
 * Address:	800C30A8
 * Size:	000054
 */
ActWeed::ActWeed(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        0xD10
	  lis       r3, 0x802B
	  subi      r0, r3, 0x246C
	  lis       r3, 0x802B
	  stw       r0, 0x14(r31)
	  addi      r3, r3, 0x7DEC
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x64
	  addi      r3, r31, 0
	  stw       r0, 0x14(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C30FC
 * Size:	000058
 */
void ActWeed::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x20(r3)
	  beq-      .loc_0x3C
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x22
	  bne-      .loc_0x3C
	  stw       r4, 0x24(r31)
	  lwz       r3, 0x24(r31)
	  bl        0x215B8

	.loc_0x3C:
	  mr        r3, r31
	  bl        0xA4
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C3154
 * Size:	000060
 */
void ActWeed::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lhz       r0, 0x18(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x3C
	  bge-      .loc_0x28
	  cmpwi     r0, 0
	  bge-      .loc_0x34
	  b         .loc_0x4C

	.loc_0x28:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x4C
	  b         .loc_0x44

	.loc_0x34:
	  bl        0xC8
	  b         .loc_0x50

	.loc_0x3C:
	  bl        0x2AC
	  b         .loc_0x50

	.loc_0x44:
	  bl        0x544
	  b         .loc_0x50

	.loc_0x4C:
	  li        r3, 0

	.loc_0x50:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C31B4
 * Size:	00002C
 */
void ActWeed::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x24(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x1C
	  bl        0x21538

	.loc_0x1C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C31E0
 * Size:	000070
 */
void ActWeed::initApproach()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  sth       r0, 0x18(r3)
	  lwz       r3, 0x24(r3)
	  bl        0x2260C
	  stw       r3, 0x20(r30)
	  addi      r3, r1, 0xC
	  li        r4, 0x2
	  bl        0x5BD44
	  addi      r31, r3, 0
	  addi      r3, r1, 0x14
	  li        r4, 0x2
	  bl        0x5BD34
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x77A4
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C3250
 * Size:	0001E0
 */
void ActWeed::exeApproach()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  stw       r30, 0x68(r1)
	  mr        r30, r3
	  lwz       r4, 0x20(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x3C
	  lwz       r4, 0xC(r30)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x1C4

	.loc_0x3C:
	  lbz       r0, 0xC(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x90
	  li        r0, 0
	  sth       r0, 0x18(r30)
	  lwz       r3, 0x24(r30)
	  bl        0x2256C
	  stw       r3, 0x20(r30)
	  addi      r3, r1, 0x38
	  li        r4, 0x2
	  bl        0x5BCA4
	  addi      r31, r3, 0
	  addi      r3, r1, 0x30
	  li        r4, 0x2
	  bl        0x5BC94
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x7704
	  li        r3, 0
	  b         .loc_0x1C4

	.loc_0x90:
	  lwz       r3, 0xC(r30)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x0(r4)
	  lfs       f3, 0x4(r4)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r4)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x58(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x5C(r1)
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x58(r1)
	  lfs       f1, 0x60(r1)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x6AB0(r2)
	  fmuls     f1, f1, f1
	  fadds     f31, f2, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x13C
	  fsqrte    f1, f31
	  lfd       f3, -0x6AA8(r2)
	  lfd       f2, -0x6AA0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0x2C(r1)
	  lfs       f31, 0x2C(r1)

	.loc_0x13C:
	  lfs       f1, 0x58(r1)
	  lfs       f0, 0x5C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x60(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xB576C
	  lfs       f0, -0x6AB0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x190
	  lfs       f0, 0x58(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x5C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x60(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x60(r1)

	.loc_0x190:
	  lfs       f0, -0x6A98(r2)
	  fcmpo     cr0, f31, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x1B0
	  mr        r3, r30
	  bl        .loc_0x1E0
	  li        r3, 0
	  b         .loc_0x1C4

	.loc_0x1B0:
	  lwz       r3, 0xC(r30)
	  addi      r4, r1, 0x58
	  lfs       f1, -0x6A94(r2)
	  bl        0x89CC
	  li        r3, 0

	.loc_0x1C4:
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr

	.loc_0x1E0:
	*/
}

/*
 * --INFO--
 * Address:	800C3430
 * Size:	00000C
 */
void ActWeed::initAdjust()
{
	// Generated from sth r0, 0x18(r3)
	_18 = 1;
}

/*
 * --INFO--
 * Address:	800C343C
 * Size:	000214
 */
void ActWeed::exeAdjust()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  stw       r30, 0x68(r1)
	  mr        r30, r3
	  lwz       r4, 0x20(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x3C
	  lwz       r4, 0xC(r30)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x1F8

	.loc_0x3C:
	  lbz       r0, 0xC(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x90
	  li        r0, 0
	  sth       r0, 0x18(r30)
	  lwz       r3, 0x24(r30)
	  bl        0x22380
	  stw       r3, 0x20(r30)
	  addi      r3, r1, 0x38
	  li        r4, 0x2
	  bl        0x5BAB8
	  addi      r31, r3, 0
	  addi      r3, r1, 0x30
	  li        r4, 0x2
	  bl        0x5BAA8
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x7518
	  li        r3, 0
	  b         .loc_0x1F8

	.loc_0x90:
	  lwz       r3, 0xC(r30)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x0(r4)
	  lfs       f3, 0x4(r4)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r4)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x58(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x5C(r1)
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x58(r1)
	  lfs       f1, 0x60(r1)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x6AB0(r2)
	  fmuls     f1, f1, f1
	  fadds     f31, f2, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x13C
	  fsqrte    f1, f31
	  lfd       f3, -0x6AA8(r2)
	  lfd       f2, -0x6AA0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0x2C(r1)
	  lfs       f31, 0x2C(r1)

	.loc_0x13C:
	  lfs       f1, 0x58(r1)
	  lfs       f0, 0x5C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x60(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xB5958
	  lfs       f0, -0x6AB0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x190
	  lfs       f0, 0x58(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x5C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x60(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x60(r1)

	.loc_0x190:
	  lfs       f0, -0x6A90(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x1E4
	  mr        r3, r30
	  bl        .loc_0x214
	  lwz       r4, 0xC(r30)
	  li        r3, 0
	  lfs       f0, -0x4420(r13)
	  stfsu     f0, 0xA4(r4)
	  lfs       f0, -0x441C(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x4418(r13)
	  stfs      f0, 0x8(r4)
	  lwz       r4, 0xC(r30)
	  lfs       f0, -0x4414(r13)
	  stfsu     f0, 0x70(r4)
	  lfs       f0, -0x4410(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x440C(r13)
	  stfs      f0, 0x8(r4)
	  b         .loc_0x1F8

	.loc_0x1E4:
	  lwz       r3, 0xC(r30)
	  addi      r4, r1, 0x58
	  lfs       f1, -0x6A8C(r2)
	  bl        0x87AC
	  li        r3, 0

	.loc_0x1F8:
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr

	.loc_0x214:
	*/
}

/*
 * --INFO--
 * Address:	800C3650
 * Size:	00008C
 */
void ActWeed::initNuking()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x2
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r3
	  sth       r0, 0x18(r3)
	  mr        r30, r29
	  beq-      .loc_0x30
	  addi      r30, r30, 0x14

	.loc_0x30:
	  addi      r3, r1, 0xC
	  li        r4, 0x5
	  bl        0x5B8D0
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x14
	  li        r4, 0x5
	  bl        0x5B8F0
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x732C
	  li        r0, 0x4
	  sth       r0, 0x28(r29)
	  li        r0, 0
	  stb       r0, 0x2A(r29)
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
 * Address:	800C36DC
 * Size:	0000E0
 */
void ActWeed::exeNuking()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  mr        r30, r3
	  lbz       r0, 0x2A(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x6C
	  li        r0, 0
	  sth       r0, 0x18(r30)
	  lwz       r3, 0x24(r30)
	  bl        0x22104
	  stw       r3, 0x20(r30)
	  addi      r3, r1, 0x14
	  li        r4, 0x2
	  bl        0x5B83C
	  addi      r31, r3, 0
	  addi      r3, r1, 0xC
	  li        r4, 0x2
	  bl        0x5B82C
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x729C
	  li        r3, 0
	  b         .loc_0xC8

	.loc_0x6C:
	  lwz       r3, 0xC(r30)
	  lfs       f0, -0x4408(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4404(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4400(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r30)
	  lfs       f0, -0x43FC(r13)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x43F8(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x43F4(r13)
	  stfs      f0, 0x8(r3)
	  lbz       r0, 0x2A(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xC4
	  lwz       r4, 0xC(r30)
	  li        r0, 0xA
	  li        r3, 0x2
	  stb       r0, 0x400(r4)
	  b         .loc_0xC8

	.loc_0xC4:
	  li        r3, 0

	.loc_0xC8:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C37BC
 * Size:	0002B4
 */
void ActWeed::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stfd      f30, 0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x60(r1)
	  stw       r29, 0x5C(r1)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x40
	  bge-      .loc_0x290
	  cmpwi     r0, 0
	  bge-      .loc_0x27C
	  b         .loc_0x290

	.loc_0x40:
	  lhz       r0, 0x18(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x290
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x5C
	  addi      r4, r4, 0x14

	.loc_0x5C:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x5C2A0
	  lwz       r3, 0x20(r31)
	  lbz       r0, 0xC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x88
	  li        r0, 0
	  stb       r0, 0xC(r3)
	  li        r0, 0x2
	  b         .loc_0x8C

	.loc_0x88:
	  li        r0, 0x1

	.loc_0x8C:
	  cmpwi     r0, 0
	  beq-      .loc_0x9C
	  cmpwi     r0, 0x2
	  bne-      .loc_0x290

	.loc_0x9C:
	  lwz       r3, 0xC(r31)
	  li        r5, 0xB2
	  lwz       r4, 0x24(r31)
	  bl        -0x392B0
	  lwz       r3, 0x3180(r13)
	  li        r4, 0xCA
	  lwz       r5, 0x20(r31)
	  li        r6, 0
	  li        r7, 0
	  bl        0xD92BC
	  lwz       r3, 0x3180(r13)
	  li        r4, 0xC9
	  lwz       r5, 0x20(r31)
	  li        r6, 0
	  li        r7, 0
	  bl        0xD92A4
	  lwz       r3, 0x3180(r13)
	  li        r4, 0xC8
	  lwz       r5, 0x20(r31)
	  li        r6, 0
	  li        r7, 0
	  bl        0xD928C
	  cmplwi    r3, 0
	  beq-      .loc_0x12C
	  lfs       f0, -0x43F0(r13)
	  lfs       f1, -0x43EC(r13)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, -0x43E8(r13)
	  stfs      f1, 0x20(r1)
	  stfs      f0, 0x24(r1)
	  lwz       r4, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0x12C:
	  lwz       r4, 0x24(r31)
	  lhz       r3, 0x3D0(r4)
	  subi      r0, r3, 0x1
	  sth       r0, 0x3D0(r4)
	  bl        0x154778
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6A68(r2)
	  stw       r0, 0x54(r1)
	  lis       r30, 0x4330
	  lfs       f2, -0x6A84(r2)
	  stw       r30, 0x50(r1)
	  lfs       f1, -0x6A88(r2)
	  lfd       f3, 0x50(r1)
	  lfs       f0, -0x6A80(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x290
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0x6
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r29, r3
	  beq-      .loc_0x290
	  lwz       r3, 0x20(r31)
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x40(r1)
	  lfs       f1, 0x8(r3)
	  lfs       f0, -0x6A7C(r2)
	  stfs      f1, 0x44(r1)
	  lfs       f1, 0x40(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x40(r1)
	  bl        0x1546F0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6A68(r2)
	  stw       r0, 0x54(r1)
	  lfs       f3, -0x6A84(r2)
	  stw       r30, 0x50(r1)
	  lfs       f2, -0x6A88(r2)
	  lfd       f1, 0x50(r1)
	  lfs       f0, -0x6A74(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6A78(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f30, f1, f0
	  fmr       f1, f30
	  bl        0x158194
	  lfs       f0, -0x6A70(r2)
	  fmuls     f31, f0, f1
	  fmr       f1, f30
	  bl        0x158318
	  lfs       f2, -0x6A70(r2)
	  mr        r3, r29
	  lfs       f0, -0x6A6C(r2)
	  addi      r4, r1, 0x3C
	  fmuls     f1, f2, f1
	  stfs      f1, 0x28(r1)
	  stfs      f0, 0x2C(r1)
	  stfs      f31, 0x30(r1)
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x28(r1)
	  mr        r3, r29
	  lwz       r0, 0x2C(r1)
	  li        r4, 0
	  stw       r5, 0x70(r29)
	  stw       r0, 0x74(r29)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x78(r29)
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x290

	.loc_0x27C:
	  lhz       r0, 0x18(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x290
	  li        r0, 0x1
	  stb       r0, 0x2A(r31)

	.loc_0x290:
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lfd       f30, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C3A70
 * Size:	00006C
 */
ActWeed::~ActWeed()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x50
	  lis       r3, 0x802B
	  addi      r3, r3, 0x7DEC
	  stw       r3, 0x0(r30)
	  addi      r0, r3, 0x64
	  addi      r3, r30, 0
	  stw       r0, 0x14(r30)
	  li        r4, 0
	  bl        0x35C
	  extsh.    r0, r31
	  ble-      .loc_0x50
	  mr        r3, r30
	  bl        -0x7C910

	.loc_0x50:
	  mr        r3, r30
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
 * Address:	800C3ADC
 * Size:	000008
 */
void ActWeed::@20 @animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  subi      r3, r3, 0x14
	  b         -0x324
	*/
}
