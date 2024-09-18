#include "Interactions.h"
#include "Navi.h"
#include "NaviProp.h"
#include "NaviState.h"

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
 * Address:	800F82E8
 * Size:	00009C
 */
void Navi::viewDraw(Graphics&, Matrix4f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  li        r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  lis       r4, 0x803A
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x3B4(r30)
	  subi      r4, r4, 0x77C0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r29, 0x834
	  bl        0x278D4
	  lwz       r3, 0x82C(r29)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0xC3034
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r12, 0xFC(r12)
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
 * Address:	800F8384
 * Size:	00005C
 */
void Navi::viewStartTrembleMotion(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0xC
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x10
	  bl        0x26BB4
	  addi      r31, r3, 0
	  addi      r3, r1, 0x18
	  li        r4, 0xC
	  bl        0x26BA4
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r30, 0x834
	  bl        0x276A4
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
 * Address:	800F83E0
 * Size:	000028
 */
void Navi::viewKill()
{
	/*
	.loc_0x0:
	  lwz       r6, 0x2C0(r3)
	  li        r0, 0
	  lwz       r5, 0x94(r6)
	  lwz       r4, 0x98(r6)
	  stw       r5, 0x94(r3)
	  stw       r4, 0x98(r3)
	  lwz       r4, 0x9C(r6)
	  stw       r4, 0x9C(r3)
	  stw       r0, 0x2C0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F8408
 * Size:	000008
 */
void Navi::viewGetBottomRadius()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x63A8(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F8410
 * Size:	000008
 */
void Navi::viewGetHeight()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x63A4(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F8418
 * Size:	000028
 */
void Navi::isNuking()
{
	/*
	.loc_0x0:
	  lwz       r3, 0xADC(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x14
	  lwz       r0, 0x4(r3)
	  b         .loc_0x18

	.loc_0x14:
	  li        r0, -0x1

	.loc_0x18:
	  subfic    r0, r0, 0x5
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void Navi::startMovie(bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800F8440
 * Size:	0000B0
 */
void StateMachine<Navi>::transit(Navi*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r5,2,0,29
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  mr        r29, r4
	  stw       r28, 0x18(r1)
	  mr        r28, r3
	  lwz       r31, 0xADC(r4)
	  lwz       r3, 0x14(r3)
	  cmplwi    r31, 0
	  lwzx      r30, r3, r0
	  mr        r3, r31
	  beq-      .loc_0x5C
	  lwz       r12, 0x0(r3)
	  mr        r4, r29
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r31)
	  stw       r0, 0x18(r28)

	.loc_0x5C:
	  lwz       r0, 0xC(r28)
	  cmpw      r30, r0
	  blt-      .loc_0x6C

	.loc_0x68:
	  b         .loc_0x68

	.loc_0x6C:
	  lwz       r3, 0x4(r28)
	  rlwinm    r0,r30,2,0,29
	  addi      r4, r29, 0
	  lwzx      r3, r3, r0
	  stw       r3, 0xADC(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F84F0
 * Size:	000004
 */
void AState<Navi>::init(Navi*) { }

/*
 * --INFO--
 * Address:	800F84F4
 * Size:	000004
 */
void AState<Navi>::cleanup(Navi*) { }

/*
 * --INFO--
 * Address:	800F84F8
 * Size:	000038
 */
void Navi::startMovieInf()
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  li        r5, 0x16
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x320(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void Navi::movieMode()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800F8530
 * Size:	000014
 */
void Navi::incPlatePiki()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x710(r3)
	  lwz       r3, 0x78(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x78(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F8544
 * Size:	000014
 */
void Navi::decPlatePiki()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x710(r3)
	  lwz       r3, 0x78(r4)
	  subi      r0, r3, 0x1
	  stw       r0, 0x78(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F8558
 * Size:	00000C
 */
void Navi::getPlatePikis()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x710(r3)
	  lwz       r3, 0x78(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F8564
 * Size:	00000C
 */
void Navi::startDayEnd()
{
	// Generated from stw r0, 0x6C0(r3)
	// _6C0 = 1;
}

/*
 * --INFO--
 * Address:	800F8570
 * Size:	000410
 */
void Navi::updateDayEnd(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stmw      r26, 0xB0(r1)
	  mr        r27, r3
	  addi      r28, r4, 0
	  lwz       r0, 0x6C0(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x28C
	  li        r0, 0
	  stw       r0, 0x6C0(r27)
	  lwz       r3, 0x0(r28)
	  lwz       r0, 0x4(r28)
	  stw       r3, 0x94(r27)
	  stw       r0, 0x98(r27)
	  lwz       r0, 0x8(r28)
	  stw       r0, 0x9C(r27)
	  lwz       r3, 0x0(r28)
	  lwz       r0, 0x4(r28)
	  stw       r3, 0x790(r27)
	  stw       r0, 0x794(r27)
	  lwz       r0, 0x8(r28)
	  stw       r0, 0x798(r27)
	  lwz       r3, 0x710(r27)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r27, 0
	  li        r4, 0
	  bl        0x5E00
	  lwz       r31, 0x3068(r13)
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x63A0(r2)
	  mr        r30, r3
	  b         .loc_0x230

	.loc_0xA4:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xC8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE0

	.loc_0xC8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xE0:
	  mr        r29, r3
	  lwz       r3, 0x490(r3)
	  addi      r4, r29, 0
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x4FC(r29)
	  cmplwi    r0, 0xB
	  beq-      .loc_0x214
	  lwz       r5, 0x504(r29)
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x2B4BC
	  li        r26, 0
	  stw       r26, 0x33C(r29)
	  stfs      f31, 0x348(r29)
	  stfs      f31, 0x344(r29)
	  stb       r26, 0x340(r29)
	  stb       r26, 0x330(r29)
	  lwz       r3, 0x338(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x148
	  bl        -0x14344
	  stw       r26, 0x338(r29)

	.loc_0x148:
	  lwz       r3, 0x504(r29)
	  li        r26, 0
	  addi      r0, r3, 0x94
	  stw       r0, 0x33C(r29)
	  stb       r26, 0x340(r29)
	  stb       r26, 0x330(r29)
	  lwz       r3, 0x338(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x174
	  bl        -0x14370
	  stw       r26, 0x338(r29)

	.loc_0x174:
	  lwz       r3, 0x4F8(r29)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x18C
	  li        r5, 0
	  b         .loc_0x198

	.loc_0x18C:
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r5, r3, r0

	.loc_0x198:
	  lwz       r3, 0x504(r29)
	  li        r4, 0x1
	  lwz       r0, 0x58(r5)
	  lwz       r5, 0x710(r3)
	  rlwinm    r3,r0,5,0,26
	  lwz       r0, 0x80(r5)
	  addi      r3, r3, 0xC
	  lfsu      f0, 0x94(r5)
	  add       r3, r0, r3
	  lfs       f1, 0x0(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x90(r1)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x4(r5)
	  fadds     f0, f1, f0
	  stfs      f0, 0x94(r1)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x8(r5)
	  fadds     f0, f1, f0
	  stfs      f0, 0x98(r1)
	  lwz       r3, 0x90(r1)
	  lwz       r0, 0x94(r1)
	  stw       r3, 0x94(r29)
	  stw       r0, 0x98(r29)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0x9C(r29)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r29)
	  lfs       f2, 0x9C(r29)
	  bl        -0x90878
	  stfs      f1, 0x98(r29)

	.loc_0x214:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x230:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x258
	  li        r0, 0x1
	  b         .loc_0x284

	.loc_0x258:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x280
	  li        r0, 0x1
	  b         .loc_0x284

	.loc_0x280:
	  li        r0, 0

	.loc_0x284:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xA4

	.loc_0x28C:
	  lwz       r3, 0x710(r27)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2E4(r27)
	  li        r0, 0
	  addi      r3, r27, 0
	  stb       r0, 0x48(r4)
	  li        r4, 0
	  lwz       r5, 0x2E4(r27)
	  stb       r0, 0x47(r5)
	  bl        0x5BC0
	  lwz       r3, 0x94(r27)
	  lwz       r0, 0x98(r27)
	  stw       r3, 0x790(r27)
	  stw       r0, 0x794(r27)
	  lwz       r0, 0x9C(r27)
	  stw       r0, 0x798(r27)
	  lwz       r3, 0x0(r28)
	  lwz       r0, 0x4(r28)
	  stw       r3, 0x94(r27)
	  stw       r0, 0x98(r27)
	  lwz       r0, 0x8(r28)
	  stw       r0, 0x9C(r27)
	  lfs       f1, 0x0(r28)
	  lfs       f0, 0x790(r27)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x60(r1)
	  stfs      f0, 0x74(r1)
	  lfs       f1, 0x4(r28)
	  lfs       f0, 0x794(r27)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x78(r1)
	  lfs       f1, 0x8(r28)
	  lfs       f0, 0x798(r27)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x7C(r1)
	  lwz       r3, 0x74(r1)
	  lwz       r0, 0x78(r1)
	  stw       r3, 0x70(r27)
	  stw       r0, 0x74(r27)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0x78(r27)
	  lfs       f1, 0x70(r27)
	  lfs       f0, 0x74(r27)
	  lfs       f3, 0x78(r27)
	  fmuls     f2, f1, f1
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x3C4
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x44(r1)

	.loc_0x3C4:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, -0x6388(r2)
	  lfs       f1, 0x28C(r3)
	  lfs       f0, 0x70(r27)
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0x70(r27)
	  lfs       f0, 0x74(r27)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x74(r27)
	  lfs       f0, 0x78(r27)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x78(r27)
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lmw       r26, 0xB0(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F8980
 * Size:	000228
 */
void Navi::enterAllPikis()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x568(r1)
	  stmw      r26, 0x550(r1)
	  addi      r29, r1, 0x224
	  addi      r30, r3, 0
	  addi      r27, r29, 0
	  li        r26, 0

	.loc_0x20:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r26
	  bl        -0x5FF0
	  addi      r26, r26, 0x1
	  stw       r3, 0x0(r27)
	  cmpwi     r26, 0x3
	  addi      r27, r27, 0x4
	  blt+      .loc_0x20
	  lis       r3, 0x802C
	  addi      r28, r3, 0xA4
	  li        r26, 0

	.loc_0x4C:
	  lwz       r0, 0x0(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x6C
	  addi      r4, r28, 0
	  crclr     6, 0x6
	  addi      r5, r26, 0
	  addi      r3, r1, 0x124
	  bl        0x11DBB0

	.loc_0x6C:
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x3
	  addi      r29, r29, 0x4
	  blt+      .loc_0x4C
	  lwz       r29, 0x3068(r13)
	  li        r31, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r27, r3, 0
	  addi      r28, r1, 0x230
	  b         .loc_0x130

	.loc_0xA4:
	  cmpwi     r27, -0x1
	  bne-      .loc_0xC8
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE0

	.loc_0xC8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xE0:
	  mr        r26, r3
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x114
	  lhz       r0, 0x4FC(r26)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x114
	  rlwinm    r0,r31,2,0,29
	  stwx      r26, r28, r0
	  addi      r31, r31, 0x1

	.loc_0x114:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x130:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x158
	  li        r0, 0x1
	  b         .loc_0x184

	.loc_0x158:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x180
	  li        r0, 0x1
	  b         .loc_0x184

	.loc_0x180:
	  li        r0, 0

	.loc_0x184:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xA4
	  lis       r3, 0x802C
	  addi      r27, r1, 0x230
	  addi      r28, r3, 0xB4
	  addi      r29, r1, 0x224
	  li        r26, 0
	  b         .loc_0x20C

	.loc_0x1A4:
	  lwz       r3, 0x0(r27)
	  lhz       r5, 0x510(r3)
	  cmplwi    r5, 0x3
	  blt-      .loc_0x1C4
	  addi      r4, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x18
	  bl        0x11DA58

	.loc_0x1C4:
	  lwz       r3, 0x0(r27)
	  lhz       r0, 0x510(r3)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r29, r0
	  stw       r0, 0x708(r30)
	  lwz       r0, 0x708(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x204
	  lwz       r3, 0x0(r27)
	  bl        -0x30614
	  cmpwi     r3, 0x3
	  beq-      .loc_0x204
	  lwz       r3, 0x0(r27)
	  li        r4, 0xB
	  li        r5, 0
	  bl        -0x2B9B4

	.loc_0x204:
	  addi      r27, r27, 0x4
	  addi      r26, r26, 0x1

	.loc_0x20C:
	  cmpw      r26, r31
	  blt+      .loc_0x1A4
	  lmw       r26, 0x550(r1)
	  lwz       r0, 0x56C(r1)
	  addi      r1, r1, 0x568
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F8BA8
 * Size:	000C20
 */
NaviProp::NaviProp()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r4, 0x6C8
	  subi      r4, r13, 0x2D7C
	  stwu      r1, -0x450(r1)
	  stw       r31, 0x44C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x448(r1)
	  stw       r29, 0x444(r1)
	  stw       r28, 0x440(r1)
	  li        r28, 0
	  stw       r0, 0x54(r3)
	  addi      r3, r1, 0x228
	  stw       r28, 0x0(r31)
	  bl        -0xA810C
	  lwz       r0, 0x228(r1)
	  addi      r5, r1, 0x128
	  addi      r4, r31, 0
	  stw       r0, 0x128(r1)
	  addi      r3, r31, 0x4
	  bl        -0x9A17C
	  lis       r3, 0x802A
	  addi      r30, r3, 0x6098
	  stw       r30, 0xC(r31)
	  addi      r3, r1, 0x230
	  subi      r4, r13, 0x2D78
	  lfs       f0, -0x6384(r2)
	  stfs      f0, 0x10(r31)
	  bl        -0xA8144
	  lwz       r0, 0x230(r1)
	  addi      r5, r1, 0x124
	  addi      r4, r31, 0
	  stw       r0, 0x124(r1)
	  addi      r3, r31, 0x14
	  bl        -0x9A1B4
	  stw       r30, 0x1C(r31)
	  addi      r3, r1, 0x238
	  subi      r4, r13, 0x2D74
	  lfs       f0, -0x6384(r2)
	  stfs      f0, 0x20(r31)
	  bl        -0xA8174
	  lwz       r0, 0x238(r1)
	  addi      r5, r1, 0x120
	  addi      r4, r31, 0
	  stw       r0, 0x120(r1)
	  addi      r3, r31, 0x24
	  bl        -0x9A1E4
	  stw       r30, 0x2C(r31)
	  addi      r3, r1, 0x240
	  subi      r4, r13, 0x2D70
	  lfs       f0, -0x6380(r2)
	  stfs      f0, 0x30(r31)
	  bl        -0xA81A4
	  lwz       r0, 0x240(r1)
	  addi      r5, r1, 0x11C
	  addi      r4, r31, 0
	  stw       r0, 0x11C(r1)
	  addi      r3, r31, 0x34
	  bl        -0x9A214
	  stw       r30, 0x3C(r31)
	  addi      r3, r1, 0x248
	  subi      r4, r13, 0x2D6C
	  lfs       f0, -0x637C(r2)
	  stfs      f0, 0x40(r31)
	  bl        -0xA81D4
	  lwz       r0, 0x248(r1)
	  addi      r5, r1, 0x118
	  addi      r4, r31, 0
	  stw       r0, 0x118(r1)
	  addi      r3, r31, 0x44
	  bl        -0x9A244
	  stw       r30, 0x4C(r31)
	  lis       r3, 0x802C
	  addi      r0, r3, 0x464
	  lfs       f0, -0x6378(r2)
	  addi      r5, r1, 0x220
	  addi      r3, r31, 0x5C
	  stfs      f0, 0x50(r31)
	  addi      r4, r31, 0x58
	  stw       r0, 0x54(r31)
	  stw       r28, 0x58(r31)
	  lwz       r0, -0x2D68(r13)
	  stw       r0, 0x250(r1)
	  lwz       r0, 0x250(r1)
	  stw       r0, 0x220(r1)
	  bl        -0x9A280
	  stw       r30, 0x64(r31)
	  addi      r5, r1, 0x21C
	  addi      r3, r31, 0x6C
	  lfs       f0, -0x6374(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x68(r31)
	  lwz       r0, -0x2D64(r13)
	  stw       r0, 0x258(r1)
	  lwz       r0, 0x258(r1)
	  stw       r0, 0x21C(r1)
	  bl        -0x9A2AC
	  stw       r30, 0x74(r31)
	  addi      r5, r1, 0x218
	  addi      r3, r31, 0x7C
	  lfs       f0, -0x6370(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x78(r31)
	  lwz       r0, -0x2D60(r13)
	  stw       r0, 0x260(r1)
	  lwz       r0, 0x260(r1)
	  stw       r0, 0x218(r1)
	  bl        -0x9A2D8
	  stw       r30, 0x84(r31)
	  addi      r5, r1, 0x214
	  addi      r3, r31, 0x8C
	  lfs       f0, -0x636C(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x88(r31)
	  lwz       r0, -0x2D5C(r13)
	  stw       r0, 0x268(r1)
	  lwz       r0, 0x268(r1)
	  stw       r0, 0x214(r1)
	  bl        -0x9A304
	  stw       r30, 0x94(r31)
	  addi      r5, r1, 0x210
	  addi      r3, r31, 0x9C
	  lfs       f0, -0x6368(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x98(r31)
	  lwz       r0, -0x2D58(r13)
	  stw       r0, 0x270(r1)
	  lwz       r0, 0x270(r1)
	  stw       r0, 0x210(r1)
	  bl        -0x9A330
	  stw       r30, 0xA4(r31)
	  addi      r5, r1, 0x20C
	  addi      r3, r31, 0xAC
	  lfs       f0, -0x6364(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0xA8(r31)
	  lwz       r0, -0x2D54(r13)
	  stw       r0, 0x278(r1)
	  lwz       r0, 0x278(r1)
	  stw       r0, 0x20C(r1)
	  bl        -0x9A35C
	  stw       r30, 0xB4(r31)
	  addi      r5, r1, 0x208
	  addi      r3, r31, 0xBC
	  lfs       f0, -0x6360(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0xB8(r31)
	  lwz       r0, -0x2D50(r13)
	  stw       r0, 0x280(r1)
	  lwz       r0, 0x280(r1)
	  stw       r0, 0x208(r1)
	  bl        -0x9A388
	  stw       r30, 0xC4(r31)
	  addi      r5, r1, 0x204
	  addi      r3, r31, 0xCC
	  lfs       f0, -0x635C(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0xC8(r31)
	  lwz       r0, -0x2D4C(r13)
	  stw       r0, 0x288(r1)
	  lwz       r0, 0x288(r1)
	  stw       r0, 0x204(r1)
	  bl        -0x9A3B4
	  stw       r30, 0xD4(r31)
	  addi      r5, r1, 0x200
	  addi      r3, r31, 0xDC
	  lfs       f0, -0x6358(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0xD8(r31)
	  lwz       r0, -0x2D48(r13)
	  stw       r0, 0x290(r1)
	  lwz       r0, 0x290(r1)
	  stw       r0, 0x200(r1)
	  bl        -0x9A3E0
	  stw       r30, 0xE4(r31)
	  addi      r5, r1, 0x1FC
	  addi      r3, r31, 0xEC
	  lfs       f0, -0x6354(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0xE8(r31)
	  lwz       r0, -0x2D44(r13)
	  stw       r0, 0x298(r1)
	  lwz       r0, 0x298(r1)
	  stw       r0, 0x1FC(r1)
	  bl        -0x9A40C
	  stw       r30, 0xF4(r31)
	  addi      r5, r1, 0x1F8
	  addi      r3, r31, 0xFC
	  lfs       f0, -0x6388(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0xF8(r31)
	  lwz       r0, -0x2D40(r13)
	  stw       r0, 0x2A0(r1)
	  lwz       r0, 0x2A0(r1)
	  stw       r0, 0x1F8(r1)
	  bl        -0x9A438
	  stw       r30, 0x104(r31)
	  addi      r5, r1, 0x1F4
	  addi      r3, r31, 0x10C
	  lfs       f0, -0x6350(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x108(r31)
	  lwz       r0, -0x2D3C(r13)
	  stw       r0, 0x2A8(r1)
	  lwz       r0, 0x2A8(r1)
	  stw       r0, 0x1F4(r1)
	  bl        -0x9A464
	  stw       r30, 0x114(r31)
	  addi      r5, r1, 0x1F0
	  addi      r3, r31, 0x11C
	  lfs       f0, -0x637C(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x118(r31)
	  lwz       r0, -0x2D38(r13)
	  stw       r0, 0x2B0(r1)
	  lwz       r0, 0x2B0(r1)
	  stw       r0, 0x1F0(r1)
	  bl        -0x9A490
	  stw       r30, 0x124(r31)
	  addi      r5, r1, 0x1EC
	  addi      r3, r31, 0x12C
	  lfs       f0, -0x634C(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x128(r31)
	  lwz       r0, -0x2D34(r13)
	  stw       r0, 0x2B8(r1)
	  lwz       r0, 0x2B8(r1)
	  stw       r0, 0x1EC(r1)
	  bl        -0x9A4BC
	  stw       r30, 0x134(r31)
	  addi      r5, r1, 0x1E8
	  addi      r3, r31, 0x13C
	  lfs       f0, -0x6388(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x138(r31)
	  lwz       r0, -0x2D30(r13)
	  stw       r0, 0x2C0(r1)
	  lwz       r0, 0x2C0(r1)
	  stw       r0, 0x1E8(r1)
	  bl        -0x9A4E8
	  stw       r30, 0x144(r31)
	  addi      r5, r1, 0x1E4
	  addi      r3, r31, 0x14C
	  lfs       f0, -0x6374(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x148(r31)
	  lwz       r0, -0x2D2C(r13)
	  stw       r0, 0x2C8(r1)
	  lwz       r0, 0x2C8(r1)
	  stw       r0, 0x1E4(r1)
	  bl        -0x9A514
	  stw       r30, 0x154(r31)
	  addi      r5, r1, 0x1E0
	  addi      r3, r31, 0x15C
	  lfs       f0, -0x6348(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x158(r31)
	  lwz       r0, -0x2D28(r13)
	  stw       r0, 0x2D0(r1)
	  lwz       r0, 0x2D0(r1)
	  stw       r0, 0x1E0(r1)
	  bl        -0x9A540
	  stw       r30, 0x164(r31)
	  addi      r5, r1, 0x1DC
	  addi      r3, r31, 0x16C
	  lfs       f0, -0x6344(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x168(r31)
	  lwz       r0, -0x2D24(r13)
	  stw       r0, 0x2D8(r1)
	  lwz       r0, 0x2D8(r1)
	  stw       r0, 0x1DC(r1)
	  bl        -0x9A56C
	  stw       r30, 0x174(r31)
	  addi      r5, r1, 0x1D8
	  addi      r3, r31, 0x17C
	  lfs       f0, -0x6340(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x178(r31)
	  lwz       r0, -0x2D20(r13)
	  stw       r0, 0x2E0(r1)
	  lwz       r0, 0x2E0(r1)
	  stw       r0, 0x1D8(r1)
	  bl        -0x9A598
	  stw       r30, 0x184(r31)
	  addi      r5, r1, 0x1D4
	  addi      r3, r31, 0x18C
	  lfs       f0, -0x6368(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x188(r31)
	  lwz       r0, -0x2D1C(r13)
	  stw       r0, 0x2E8(r1)
	  lwz       r0, 0x2E8(r1)
	  stw       r0, 0x1D4(r1)
	  bl        -0x9A5C4
	  stw       r30, 0x194(r31)
	  addi      r5, r1, 0x1D0
	  addi      r3, r31, 0x19C
	  lfs       f0, -0x633C(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x198(r31)
	  lwz       r0, -0x2D18(r13)
	  stw       r0, 0x2F0(r1)
	  lwz       r0, 0x2F0(r1)
	  stw       r0, 0x1D0(r1)
	  bl        -0x9A5F0
	  stw       r30, 0x1A4(r31)
	  addi      r5, r1, 0x1CC
	  addi      r3, r31, 0x1AC
	  lfs       f0, -0x6370(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x1A8(r31)
	  lwz       r0, -0x2D14(r13)
	  stw       r0, 0x2F8(r1)
	  lwz       r0, 0x2F8(r1)
	  stw       r0, 0x1CC(r1)
	  bl        -0x9A61C
	  stw       r30, 0x1B4(r31)
	  addi      r5, r1, 0x1C8
	  addi      r3, r31, 0x1BC
	  lfs       f0, -0x6388(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x1B8(r31)
	  lwz       r0, -0x2D10(r13)
	  stw       r0, 0x300(r1)
	  lwz       r0, 0x300(r1)
	  stw       r0, 0x1C8(r1)
	  bl        -0x9A648
	  stw       r30, 0x1C4(r31)
	  addi      r5, r1, 0x1C4
	  addi      r3, r31, 0x1CC
	  lfs       f0, -0x633C(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x1C8(r31)
	  lwz       r0, -0x2D0C(r13)
	  stw       r0, 0x308(r1)
	  lwz       r0, 0x308(r1)
	  stw       r0, 0x1C4(r1)
	  bl        -0x9A674
	  lis       r3, 0x802A
	  addi      r29, r3, 0x60C4
	  stw       r29, 0x1D4(r31)
	  li        r28, 0x1
	  addi      r5, r1, 0x1C0
	  stw       r28, 0x1D8(r31)
	  addi      r3, r31, 0x1DC
	  addi      r4, r31, 0x58
	  lwz       r0, -0x2D08(r13)
	  stw       r0, 0x310(r1)
	  lwz       r0, 0x310(r1)
	  stw       r0, 0x1C0(r1)
	  bl        -0x9A6A8
	  stw       r30, 0x1E4(r31)
	  addi      r5, r1, 0x1BC
	  addi      r3, r31, 0x1EC
	  lfs       f0, -0x6338(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x1E8(r31)
	  lwz       r0, -0x2D04(r13)
	  stw       r0, 0x318(r1)
	  lwz       r0, 0x318(r1)
	  stw       r0, 0x1BC(r1)
	  bl        -0x9A6D4
	  stw       r30, 0x1F4(r31)
	  addi      r5, r1, 0x1B8
	  addi      r3, r31, 0x1FC
	  lfs       f0, -0x6334(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x1F8(r31)
	  lwz       r0, -0x2D00(r13)
	  stw       r0, 0x320(r1)
	  lwz       r0, 0x320(r1)
	  stw       r0, 0x1B8(r1)
	  bl        -0x9A700
	  stw       r30, 0x204(r31)
	  addi      r5, r1, 0x1B4
	  addi      r3, r31, 0x20C
	  lfs       f0, -0x636C(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x208(r31)
	  lwz       r0, -0x2CFC(r13)
	  stw       r0, 0x328(r1)
	  lwz       r0, 0x328(r1)
	  stw       r0, 0x1B4(r1)
	  bl        -0x9A72C
	  stw       r30, 0x214(r31)
	  addi      r5, r1, 0x1B0
	  addi      r3, r31, 0x21C
	  lfs       f0, -0x6330(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x218(r31)
	  lwz       r0, -0x2CF8(r13)
	  stw       r0, 0x330(r1)
	  lwz       r0, 0x330(r1)
	  stw       r0, 0x1B0(r1)
	  bl        -0x9A758
	  stw       r30, 0x224(r31)
	  addi      r5, r1, 0x1AC
	  addi      r3, r31, 0x22C
	  lfs       f0, -0x632C(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x228(r31)
	  lwz       r0, -0x2CF4(r13)
	  stw       r0, 0x338(r1)
	  lwz       r0, 0x338(r1)
	  stw       r0, 0x1AC(r1)
	  bl        -0x9A784
	  stw       r30, 0x234(r31)
	  addi      r5, r1, 0x1A8
	  addi      r3, r31, 0x23C
	  lfs       f0, -0x6328(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x238(r31)
	  lwz       r0, -0x2CF0(r13)
	  stw       r0, 0x340(r1)
	  lwz       r0, 0x340(r1)
	  stw       r0, 0x1A8(r1)
	  bl        -0x9A7B0
	  stw       r30, 0x244(r31)
	  addi      r5, r1, 0x1A4
	  addi      r3, r31, 0x24C
	  lfs       f0, -0x6364(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x248(r31)
	  lwz       r0, -0x2CEC(r13)
	  stw       r0, 0x348(r1)
	  lwz       r0, 0x348(r1)
	  stw       r0, 0x1A4(r1)
	  bl        -0x9A7DC
	  stw       r30, 0x254(r31)
	  addi      r5, r1, 0x1A0
	  addi      r3, r31, 0x25C
	  lfs       f0, -0x6324(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x258(r31)
	  lwz       r0, -0x2CE8(r13)
	  stw       r0, 0x350(r1)
	  lwz       r0, 0x350(r1)
	  stw       r0, 0x1A0(r1)
	  bl        -0x9A808
	  stw       r30, 0x264(r31)
	  addi      r5, r1, 0x19C
	  addi      r3, r31, 0x26C
	  lfs       f0, -0x6320(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x268(r31)
	  lwz       r0, -0x2CE4(r13)
	  stw       r0, 0x358(r1)
	  lwz       r0, 0x358(r1)
	  stw       r0, 0x19C(r1)
	  bl        -0x9A834
	  stw       r30, 0x274(r31)
	  addi      r5, r1, 0x198
	  addi      r3, r31, 0x27C
	  lfs       f0, -0x631C(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x278(r31)
	  lwz       r0, -0x2CE0(r13)
	  stw       r0, 0x360(r1)
	  lwz       r0, 0x360(r1)
	  stw       r0, 0x198(r1)
	  bl        -0x9A860
	  stw       r30, 0x284(r31)
	  addi      r5, r1, 0x194
	  addi      r3, r31, 0x28C
	  lfs       f0, -0x6338(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x288(r31)
	  lwz       r0, -0x2CDC(r13)
	  stw       r0, 0x368(r1)
	  lwz       r0, 0x368(r1)
	  stw       r0, 0x194(r1)
	  bl        -0x9A88C
	  stw       r30, 0x294(r31)
	  addi      r5, r1, 0x190
	  addi      r3, r31, 0x29C
	  lfs       f0, -0x6334(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x298(r31)
	  lwz       r0, -0x2CD8(r13)
	  stw       r0, 0x370(r1)
	  lwz       r0, 0x370(r1)
	  stw       r0, 0x190(r1)
	  bl        -0x9A8B8
	  stw       r30, 0x2A4(r31)
	  addi      r5, r1, 0x18C
	  addi      r3, r31, 0x2AC
	  lfs       f0, -0x6338(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x2A8(r31)
	  lwz       r0, -0x2CD4(r13)
	  stw       r0, 0x378(r1)
	  lwz       r0, 0x378(r1)
	  stw       r0, 0x18C(r1)
	  bl        -0x9A8E4
	  stw       r30, 0x2B4(r31)
	  addi      r5, r1, 0x188
	  addi      r3, r31, 0x2BC
	  lfs       f0, -0x6334(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x2B8(r31)
	  lwz       r0, -0x2CD0(r13)
	  stw       r0, 0x380(r1)
	  lwz       r0, 0x380(r1)
	  stw       r0, 0x188(r1)
	  bl        -0x9A910
	  stw       r30, 0x2C4(r31)
	  addi      r5, r1, 0x184
	  addi      r3, r31, 0x2CC
	  lfs       f0, -0x6338(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x2C8(r31)
	  lwz       r0, -0x2CCC(r13)
	  stw       r0, 0x388(r1)
	  lwz       r0, 0x388(r1)
	  stw       r0, 0x184(r1)
	  bl        -0x9A93C
	  stw       r30, 0x2D4(r31)
	  addi      r5, r1, 0x180
	  addi      r3, r31, 0x2DC
	  lfs       f0, -0x6334(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x2D8(r31)
	  lwz       r0, -0x2CC8(r13)
	  stw       r0, 0x390(r1)
	  lwz       r0, 0x390(r1)
	  stw       r0, 0x180(r1)
	  bl        -0x9A968
	  stw       r30, 0x2E4(r31)
	  addi      r5, r1, 0x17C
	  addi      r3, r31, 0x2EC
	  lfs       f0, -0x6318(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x2E8(r31)
	  lwz       r0, -0x2CC4(r13)
	  stw       r0, 0x398(r1)
	  lwz       r0, 0x398(r1)
	  stw       r0, 0x17C(r1)
	  bl        -0x9A994
	  stw       r30, 0x2F4(r31)
	  addi      r5, r1, 0x178
	  addi      r3, r31, 0x2FC
	  lfs       f0, -0x6388(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x2F8(r31)
	  lwz       r0, -0x2CC0(r13)
	  stw       r0, 0x3A0(r1)
	  lwz       r0, 0x3A0(r1)
	  stw       r0, 0x178(r1)
	  bl        -0x9A9C0
	  stw       r30, 0x304(r31)
	  addi      r5, r1, 0x174
	  addi      r3, r31, 0x30C
	  lfs       f0, -0x6384(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x308(r31)
	  lwz       r0, -0x2CBC(r13)
	  stw       r0, 0x3A8(r1)
	  lwz       r0, 0x3A8(r1)
	  stw       r0, 0x174(r1)
	  bl        -0x9A9EC
	  stw       r30, 0x314(r31)
	  addi      r5, r1, 0x170
	  addi      r3, r31, 0x31C
	  lfs       f0, -0x6378(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x318(r31)
	  lwz       r0, -0x2CB8(r13)
	  stw       r0, 0x3B0(r1)
	  lwz       r0, 0x3B0(r1)
	  stw       r0, 0x170(r1)
	  bl        -0x9AA18
	  stw       r30, 0x324(r31)
	  addi      r5, r1, 0x16C
	  addi      r3, r31, 0x32C
	  lfs       f0, -0x63A4(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x328(r31)
	  lwz       r0, -0x2CB4(r13)
	  stw       r0, 0x3B8(r1)
	  lwz       r0, 0x3B8(r1)
	  stw       r0, 0x16C(r1)
	  bl        -0x9AA44
	  stw       r30, 0x334(r31)
	  addi      r5, r1, 0x168
	  addi      r3, r31, 0x33C
	  lfs       f0, -0x637C(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x338(r31)
	  lwz       r0, -0x2CB0(r13)
	  stw       r0, 0x3C0(r1)
	  lwz       r0, 0x3C0(r1)
	  stw       r0, 0x168(r1)
	  bl        -0x9AA70
	  stw       r30, 0x344(r31)
	  addi      r5, r1, 0x164
	  addi      r3, r31, 0x34C
	  lfs       f0, -0x6314(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x348(r31)
	  lwz       r0, -0x2CAC(r13)
	  stw       r0, 0x3C8(r1)
	  lwz       r0, 0x3C8(r1)
	  stw       r0, 0x164(r1)
	  bl        -0x9AA9C
	  stw       r30, 0x354(r31)
	  addi      r5, r1, 0x160
	  addi      r3, r31, 0x35C
	  lfs       f0, -0x6310(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x358(r31)
	  lwz       r0, -0x2CA8(r13)
	  stw       r0, 0x3D0(r1)
	  lwz       r0, 0x3D0(r1)
	  stw       r0, 0x160(r1)
	  bl        -0x9AAC8
	  stw       r30, 0x364(r31)
	  addi      r5, r1, 0x15C
	  addi      r3, r31, 0x36C
	  lfs       f0, -0x637C(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x368(r31)
	  lwz       r0, -0x2CA4(r13)
	  stw       r0, 0x3D8(r1)
	  lwz       r0, 0x3D8(r1)
	  stw       r0, 0x15C(r1)
	  bl        -0x9AAF4
	  stw       r30, 0x374(r31)
	  addi      r5, r1, 0x158
	  addi      r3, r31, 0x37C
	  lfs       f0, -0x630C(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x378(r31)
	  lwz       r0, -0x2CB0(r13)
	  stw       r0, 0x3E0(r1)
	  lwz       r0, 0x3E0(r1)
	  stw       r0, 0x158(r1)
	  bl        -0x9AB20
	  stw       r30, 0x384(r31)
	  addi      r5, r1, 0x154
	  addi      r3, r31, 0x38C
	  lfs       f0, -0x6308(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x388(r31)
	  lwz       r0, -0x2CA0(r13)
	  stw       r0, 0x3E8(r1)
	  lwz       r0, 0x3E8(r1)
	  stw       r0, 0x154(r1)
	  bl        -0x9AB4C
	  stw       r30, 0x394(r31)
	  addi      r5, r1, 0x150
	  addi      r3, r31, 0x39C
	  lfs       f0, -0x6304(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x398(r31)
	  lwz       r0, -0x2C9C(r13)
	  stw       r0, 0x3F0(r1)
	  lwz       r0, 0x3F0(r1)
	  stw       r0, 0x150(r1)
	  bl        -0x9AB78
	  stw       r30, 0x3A4(r31)
	  addi      r5, r1, 0x14C
	  addi      r3, r31, 0x3AC
	  lfs       f0, -0x6300(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x3A8(r31)
	  lwz       r0, -0x2C98(r13)
	  stw       r0, 0x3F8(r1)
	  lwz       r0, 0x3F8(r1)
	  stw       r0, 0x14C(r1)
	  bl        -0x9ABA4
	  stw       r30, 0x3B4(r31)
	  addi      r5, r1, 0x148
	  addi      r3, r31, 0x3BC
	  lfs       f0, -0x6370(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x3B8(r31)
	  lwz       r0, -0x2C94(r13)
	  stw       r0, 0x400(r1)
	  lwz       r0, 0x400(r1)
	  stw       r0, 0x148(r1)
	  bl        -0x9ABD0
	  stw       r30, 0x3C4(r31)
	  addi      r5, r1, 0x144
	  addi      r3, r31, 0x3CC
	  lfs       f0, -0x6368(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x3C8(r31)
	  lwz       r0, -0x2C90(r13)
	  stw       r0, 0x408(r1)
	  lwz       r0, 0x408(r1)
	  stw       r0, 0x144(r1)
	  bl        -0x9ABFC
	  stw       r30, 0x3D4(r31)
	  addi      r5, r1, 0x140
	  addi      r3, r31, 0x3DC
	  lfs       f0, -0x6388(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x3D8(r31)
	  lwz       r0, -0x2C8C(r13)
	  stw       r0, 0x410(r1)
	  lwz       r0, 0x410(r1)
	  stw       r0, 0x140(r1)
	  bl        -0x9AC28
	  stw       r30, 0x3E4(r31)
	  addi      r5, r1, 0x13C
	  addi      r3, r31, 0x3EC
	  lfs       f0, -0x63A4(r2)
	  addi      r4, r31, 0x58
	  stfs      f0, 0x3E8(r31)
	  lwz       r0, -0x2C88(r13)
	  stw       r0, 0x418(r1)
	  lwz       r0, 0x418(r1)
	  stw       r0, 0x13C(r1)
	  bl        -0x9AC54
	  stw       r29, 0x3F4(r31)
	  addi      r5, r1, 0x138
	  addi      r3, r31, 0x3FC
	  stw       r28, 0x3F8(r31)
	  addi      r4, r31, 0x58
	  lwz       r0, -0x2C84(r13)
	  stw       r0, 0x420(r1)
	  lwz       r0, 0x420(r1)
	  stw       r0, 0x138(r1)
	  bl        -0x9AC7C
	  stw       r29, 0x404(r31)
	  li        r0, 0x4
	  addi      r5, r1, 0x134
	  stw       r0, 0x408(r31)
	  addi      r3, r31, 0x40C
	  addi      r4, r31, 0x58
	  lwz       r0, -0x2C80(r13)
	  stw       r0, 0x428(r1)
	  lwz       r0, 0x428(r1)
	  stw       r0, 0x134(r1)
	  bl        -0x9ACA8
	  stw       r29, 0x414(r31)
	  li        r28, 0x3
	  addi      r5, r1, 0x130
	  stw       r28, 0x418(r31)
	  addi      r3, r31, 0x41C
	  addi      r4, r31, 0x58
	  lwz       r0, -0x2C7C(r13)
	  stw       r0, 0x430(r1)
	  lwz       r0, 0x430(r1)
	  stw       r0, 0x130(r1)
	  bl        -0x9ACD4
	  stw       r29, 0x424(r31)
	  addi      r5, r1, 0x12C
	  addi      r3, r31, 0x42C
	  stw       r28, 0x428(r31)
	  addi      r4, r31, 0x58
	  lwz       r0, -0x2C78(r13)
	  stw       r0, 0x438(r1)
	  lwz       r0, 0x438(r1)
	  stw       r0, 0x12C(r1)
	  bl        -0x9ACFC
	  stw       r29, 0x434(r31)
	  li        r0, 0x64
	  addi      r3, r31, 0
	  stw       r0, 0x438(r31)
	  lfs       f0, -0x6388(r2)
	  stfs      f0, 0x10(r31)
	  lfs       f0, -0x6384(r2)
	  stfs      f0, 0x30(r31)
	  lfs       f0, -0x6360(r2)
	  stfs      f0, 0x40(r31)
	  lwz       r0, 0x454(r1)
	  lwz       r31, 0x44C(r1)
	  lwz       r30, 0x448(r1)
	  lwz       r29, 0x444(r1)
	  lwz       r28, 0x440(r1)
	  addi      r1, r1, 0x450
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F97C8
 * Size:	000020
 */
bool Navi::isBuried()
{
	/*
	.loc_0x0:
	  lwz       r3, 0xADC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x13
	  bne-      .loc_0x18
	  li        r3, 0x1
	  blr

	.loc_0x18:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F97E8
 * Size:	000020
 */
bool Navi::isVisible()
{
	/*
	.loc_0x0:
	  lwz       r3, 0xADC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x1D
	  bne-      .loc_0x18
	  li        r3, 0
	  blr

	.loc_0x18:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F9808
 * Size:	000020
 */
bool Navi::isRopable()
{
	/*
	.loc_0x0:
	  lwz       r3, 0xADC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0xB
	  bne-      .loc_0x18
	  li        r3, 0
	  blr

	.loc_0x18:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void Navi::startDamage()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800F9828
 * Size:	000004
 */
void AState<Navi>::resume(Navi*) { }

/*
 * --INFO--
 * Address:	800F9834
 * Size:	000234
 */
void Navi::startDamageEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x6365
	  stw       r0, 0x4(r1)
	  addi      r4, r4, 0x6E74
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x44(r1)
	  stw       r28, 0x40(r1)
	  lwz       r3, 0x220(r3)
	  bl        -0x70150
	  mr.       r31, r3
	  beq-      .loc_0x214
	  lfs       f2, 0x58(r30)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x80
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0xE
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  b         .loc_0xF8

	.loc_0x80:
	  lis       r3, 0x803A
	  subi      r28, r3, 0x2848
	  lwz       r3, 0x1DC(r28)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xF8
	  lwz       r3, 0x224(r30)
	  lfs       f1, -0x6380(r2)
	  lfs       f0, 0x3C8(r3)
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xF8
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1D
	  addi      r3, r3, 0x54
	  bl        -0x77430
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xF8
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1D
	  addi      r3, r3, 0x54
	  bl        -0x771BC
	  lwz       r3, 0x1E8(r28)
	  li        r4, 0
	  li        r5, 0x18
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xF8:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x4
	  li        r6, 0
	  li        r7, 0
	  bl        0xA31F8
	  mr        r28, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x5
	  li        r6, 0
	  li        r7, 0
	  bl        0xA31DC
	  mr.       r29, r3
	  beq-      .loc_0x164
	  lfs       f0, -0x2C74(r13)
	  lfs       f1, -0x2C70(r13)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, -0x2C6C(r13)
	  stfs      f1, 0x20(r1)
	  stfs      f0, 0x24(r1)
	  lwz       r3, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r3, 0x1DC(r29)
	  stw       r0, 0x1E0(r29)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x1E4(r29)

	.loc_0x164:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x6
	  li        r6, 0
	  li        r7, 0
	  bl        0xA318C
	  cmplwi    r3, 0
	  beq-      .loc_0x18C
	  addi      r0, r31, 0x4
	  stw       r0, 0x18(r3)

	.loc_0x18C:
	  stw       r28, 0x2D4(r30)
	  stw       r29, 0x2D8(r30)
	  stw       r3, 0x2DC(r30)
	  lwz       r3, -0x62FC(r2)
	  lwz       r0, -0x62F8(r2)
	  stw       r3, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  bl        0x11E694
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x62E8(r2)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x62F4(r2)
	  addi      r4, r1, 0x28
	  stw       r0, 0x38(r1)
	  lfs       f2, -0x6388(r2)
	  addi      r5, r30, 0x94
	  lfd       f1, 0x38(r1)
	  lfs       f0, -0x6314(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x62F0(r2)
	  lwz       r3, 0x30D8(r13)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r4, r0
	  bl        0x2A59C
	  li        r3, 0x13D
	  bl        -0x54668

	.loc_0x214:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  lwz       r28, 0x40(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F9A68
 * Size:	000120
 */
void Navi::finishDamage()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  stb       r0, 0x2B4(r3)
	  lwz       r3, 0xADC(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x40
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x40:
	  lfs       f2, 0x58(r30)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x80
	  lwz       r3, 0x320(r30)
	  addi      r4, r30, 0
	  li        r5, 0x1D
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  b         .loc_0xF8

	.loc_0x80:
	  lis       r3, 0x803A
	  subi      r31, r3, 0x2848
	  lwz       r3, 0x1DC(r31)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xF8
	  lwz       r3, 0x224(r30)
	  lfs       f1, -0x6380(r2)
	  lfs       f0, 0x3C8(r3)
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xF8
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1D
	  addi      r3, r3, 0x54
	  bl        -0x77664
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xF8
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1D
	  addi      r3, r3, 0x54
	  bl        -0x773F0
	  lwz       r3, 0x1E8(r31)
	  li        r4, 0
	  li        r5, 0x18
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xF8:
	  li        r0, 0
	  stw       r0, 0x2DC(r30)
	  stw       r0, 0x2D8(r30)
	  stw       r0, 0x2D4(r30)
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
 * Address:	800F9B88
 * Size:	000004
 */
void AState<Navi>::restart(Navi*) { }

/*
 * --INFO--
 * Address:	800F9B8C
 * Size:	000668
 */
Navi::Navi(CreatureProp* props, int)
    : Creature(props)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r26, 0x30(r1)
	  addi      r31, r3, 0
	  addi      r29, r4, 0
	  addi      r28, r5, 0
	  addi      r30, r6, 0x98
	  bl        -0x6ECD8
	  lis       r3, 0x802B
	  subi      r0, r3, 0x246C
	  lis       r3, 0x802C
	  stw       r0, 0x2B8(r31)
	  addi      r0, r3, 0x3B0
	  stw       r0, 0x2BC(r31)
	  li        r27, 0
	  lis       r3, 0x802C
	  stw       r27, 0x2C0(r31)
	  addi      r3, r3, 0x510
	  addi      r4, r3, 0x114
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x120
	  addi      r3, r31, 0x2C4
	  stw       r4, 0x2B8(r31)
	  stw       r0, 0x2BC(r31)
	  bl        -0x2C3F0
	  addi      r3, r31, 0x324
	  bl        -0x906CC
	  stw       r27, 0x6C4(r31)
	  addi      r3, r31, 0x834
	  stw       r27, 0x6C8(r31)
	  stw       r27, 0x6CC(r31)
	  stw       r27, 0x6D0(r31)
	  lfs       f8, -0x63A0(r2)
	  stfs      f8, 0x6DC(r31)
	  fmr       f7, f8
	  fmr       f6, f8
	  stfs      f8, 0x6D8(r31)
	  fmr       f5, f8
	  fmr       f4, f8
	  stfs      f8, 0x6D4(r31)
	  fmr       f3, f8
	  stfs      f8, 0x6EC(r31)
	  fmr       f2, f8
	  fmr       f1, f8
	  stfs      f8, 0x6E8(r31)
	  fmr       f0, f8
	  stfs      f8, 0x6E4(r31)
	  stfs      f7, 0x6F8(r31)
	  stfs      f7, 0x6F4(r31)
	  stfs      f7, 0x6F0(r31)
	  stfs      f6, 0x748(r31)
	  stfs      f6, 0x744(r31)
	  stfs      f6, 0x740(r31)
	  stfs      f5, 0x754(r31)
	  stfs      f5, 0x750(r31)
	  stfs      f5, 0x74C(r31)
	  stfs      f4, 0x760(r31)
	  stfs      f4, 0x75C(r31)
	  stfs      f4, 0x758(r31)
	  stfs      f3, 0x76C(r31)
	  stfs      f3, 0x768(r31)
	  stfs      f3, 0x764(r31)
	  stfs      f2, 0x78C(r31)
	  stfs      f2, 0x788(r31)
	  stfs      f2, 0x784(r31)
	  stfs      f1, 0x798(r31)
	  stfs      f1, 0x794(r31)
	  stfs      f1, 0x790(r31)
	  stfs      f8, 0x7A4(r31)
	  stfs      f8, 0x7A0(r31)
	  stfs      f8, 0x79C(r31)
	  stfs      f0, 0x7CC(r31)
	  stfs      f0, 0x7C8(r31)
	  stfs      f0, 0x7C4(r31)
	  stw       r27, 0x7D8(r31)
	  stfs      f8, 0x824(r31)
	  stfs      f8, 0x820(r31)
	  stfs      f8, 0x81C(r31)
	  bl        0x25BD4
	  lis       r3, 0x8009
	  subi      r4, r3, 0x5808
	  addi      r3, r31, 0x8E0
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x6
	  bl        0x11AD88
	  lis       r3, 0x8003
	  addi      r4, r3, 0x5B24
	  addi      r3, r31, 0x938
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x20
	  bl        0x11AD6C
	  li        r0, 0x4
	  stw       r0, 0x700(r31)
	  addi      r4, r30, 0x28
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x735E0
	  stw       r27, 0x334(r31)
	  subi      r0, r13, 0x2C2C
	  li        r3, 0x24
	  stw       r27, 0x330(r31)
	  stw       r27, 0x32C(r31)
	  stw       r0, 0x328(r31)
	  bl        -0xB2D30
	  mr.       r26, r3
	  beq-      .loc_0x20C
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r26)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r26)
	  addi      r3, r26, 0
	  subi      r4, r13, 0x2C2C
	  stw       r27, 0x10(r26)
	  stw       r27, 0xC(r26)
	  stw       r27, 0x8(r26)
	  bl        -0xD4E98
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r26)
	  addi      r3, r26, 0
	  subi      r4, r13, 0x2C2C
	  bl        -0xB9648
	  lis       r3, 0x802C
	  addi      r0, r3, 0x358
	  stw       r0, 0x0(r26)
	  stw       r31, 0x20(r26)

	.loc_0x20C:
	  stw       r26, 0x6B8(r31)
	  addi      r4, r30, 0x28
	  lfs       f0, -0x62E0(r2)
	  stfs      f0, 0x504(r31)
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x73564
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2C28
	  bl        -0x73680
	  li        r3, 0x18
	  bl        -0xB2DBC
	  cmplwi    r3, 0
	  beq-      .loc_0x2B0
	  lis       r4, 0x802B
	  addi      r0, r4, 0x600
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x5F4
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5E8
	  lis       r4, 0x802B
	  stw       r0, 0x8(r3)
	  addi      r5, r4, 0x5AC
	  stw       r5, 0x0(r3)
	  addi      r0, r5, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x25F0
	  addi      r0, r5, 0x18
	  stw       r0, 0x8(r3)
	  addi      r6, r4, 0xC
	  addi      r5, r4, 0x18
	  stw       r4, 0x0(r3)
	  addi      r4, r31, 0x70
	  li        r0, 0
	  stw       r6, 0x4(r3)
	  stw       r5, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)
	  stw       r0, 0x14(r3)

	.loc_0x2B0:
	  stw       r3, 0x314(r31)
	  li        r3, 0x18
	  bl        -0xB2E40
	  cmplwi    r3, 0
	  beq-      .loc_0x330
	  lis       r4, 0x802B
	  addi      r0, r4, 0x600
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x5F4
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5E8
	  lis       r4, 0x802B
	  stw       r0, 0x8(r3)
	  addi      r5, r4, 0x5AC
	  stw       r5, 0x0(r3)
	  addi      r0, r5, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r6, r4, 0x2660
	  addi      r0, r5, 0x18
	  stw       r0, 0x8(r3)
	  addi      r5, r6, 0xC
	  addi      r4, r6, 0x18
	  stw       r6, 0x0(r3)
	  li        r0, 0
	  stw       r5, 0x4(r3)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  stw       r0, 0x14(r3)
	  stw       r0, 0x10(r3)

	.loc_0x330:
	  stw       r3, 0x318(r31)
	  li        r3, 0x10
	  bl        -0xB2EC0
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x34C
	  bl        0x1A494

	.loc_0x34C:
	  stw       r26, 0x774(r31)
	  li        r3, 0x10
	  bl        -0xB2EDC
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x368
	  bl        0x1A478

	.loc_0x368:
	  stw       r26, 0x778(r31)
	  li        r3, 0x10
	  bl        -0xB2EF8
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x384
	  bl        0x1A45C

	.loc_0x384:
	  stw       r26, 0x77C(r31)
	  li        r3, 0x10
	  bl        -0xB2F14
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x3A0
	  bl        0x1A440

	.loc_0x3A0:
	  stw       r26, 0x780(r31)
	  li        r3, 0x14
	  bl        -0xB2F30
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x3BC
	  bl        0x19220

	.loc_0x3BC:
	  stw       r26, 0x31C(r31)
	  subi      r4, r13, 0x2C28
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x7370C
	  li        r0, 0
	  stw       r0, 0x710(r31)
	  li        r3, 0x14
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0xAD8(r31)
	  stw       r28, 0x92C(r31)
	  stb       r0, 0xACC(r31)
	  stw       r0, 0xAD0(r31)
	  stfs      f0, 0x738(r31)
	  stb       r0, 0x718(r31)
	  stw       r0, 0x720(r31)
	  stw       r0, 0x71C(r31)
	  stw       r0, 0xADC(r31)
	  lwz       r0, 0x92C(r31)
	  lwz       r4, 0x3120(r13)
	  rlwinm    r0,r0,2,0,29
	  add       r4, r4, r0
	  lwz       r0, 0x48(r4)
	  stw       r0, 0x82C(r31)
	  bl        -0xB2FA0
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x430
	  li        r4, 0x5
	  bl        -0x71388

	.loc_0x430:
	  stw       r26, 0x220(r31)
	  li        r5, 0
	  li        r6, 0
	  lwz       r4, 0x82C(r31)
	  lwz       r3, 0x220(r31)
	  lwz       r4, 0x0(r4)
	  bl        -0x70470
	  lwz       r8, 0x82C(r31)
	  addi      r3, r31, 0x834
	  lwz       r6, 0x3120(r13)
	  lwz       r4, 0x24(r8)
	  addi      r5, r8, 0x14
	  lwz       r7, 0x50(r6)
	  addi      r6, r8, 0x4
	  bl        0x258E8
	  li        r0, 0
	  stw       r0, 0xABC(r31)
	  cmplwi    r31, 0
	  addi      r26, r31, 0
	  lfs       f1, -0x63A0(r2)
	  stfs      f1, 0xAB8(r31)
	  stfs      f1, 0xAC4(r31)
	  lfs       f0, 0x3C8(r29)
	  stfs      f0, 0x58(r31)
	  lfs       f0, -0x2C68(r13)
	  stfs      f0, 0x790(r31)
	  lfs       f0, -0x2C64(r13)
	  stfs      f0, 0x794(r31)
	  lfs       f0, -0x2C60(r13)
	  stfs      f0, 0x798(r31)
	  stfs      f1, 0x814(r31)
	  lfs       f0, -0x6388(r2)
	  stfs      f0, 0x818(r31)
	  stw       r0, 0x810(r31)
	  stw       r0, 0x80C(r31)
	  beq-      .loc_0x4C4
	  addi      r26, r26, 0x2B8

	.loc_0x4C4:
	  addi      r3, r1, 0x18
	  li        r4, 0x2
	  bl        0x24F00
	  addi      r27, r3, 0
	  addi      r5, r26, 0
	  addi      r3, r1, 0x20
	  li        r4, 0x2
	  bl        0x24F20
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r27, 0
	  bl        0x7F4
	  lfs       f0, -0x6388(r2)
	  li        r3, 0x60
	  stfs      f0, 0x7C(r31)
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x84(r31)
	  lfs       f0, -0x2C5C(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, -0x2C58(r13)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, -0x2C54(r13)
	  stfs      f0, 0x90(r31)
	  lfs       f0, -0x2C50(r13)
	  stfs      f0, 0x94(r31)
	  lfs       f0, -0x2C4C(r13)
	  stfs      f0, 0x98(r31)
	  lfs       f0, -0x2C48(r13)
	  stfs      f0, 0x9C(r31)
	  lfs       f0, -0x2C44(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x2C40(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x2C3C(r13)
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x2C38(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x2C34(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x2C30(r13)
	  stfs      f0, 0xAC(r31)
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x268(r31)
	  bl        -0xB30F8
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x588
	  addi      r4, r28, 0x1
	  bl        0x1BA7C

	.loc_0x588:
	  stw       r26, 0x2E4(r31)
	  addi      r4, r30, 0x34
	  lfs       f0, -0x62E0(r2)
	  stfs      f0, 0x26C(r31)
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x739F0
	  li        r3, 0x1C
	  bl        -0xB312C
	  cmplwi    r3, 0
	  beq-      .loc_0x5D0
	  lis       r4, 0x802C
	  addi      r0, r4, 0x1E0
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  lis       r4, 0x802C
	  stw       r0, 0x18(r3)
	  addi      r0, r4, 0x1A64
	  stw       r0, 0x0(r3)

	.loc_0x5D0:
	  stw       r3, 0x320(r31)
	  mr        r4, r31
	  lwz       r3, 0x320(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x34
	  bl        -0x73938
	  li        r27, 0
	  stw       r27, 0x828(r31)
	  li        r6, -0x202
	  li        r0, 0x36
	  stb       r27, 0x724(r31)
	  addi      r3, r31, 0x1B8
	  addi      r4, r31, 0x8E0
	  lfs       f0, -0x63A0(r2)
	  li        r5, 0x6
	  stfs      f0, 0x800(r31)
	  stb       r27, 0x7FC(r31)
	  stw       r27, 0x928(r31)
	  lwz       r7, 0xC8(r31)
	  and       r6, r7, r6
	  stw       r6, 0xC8(r31)
	  stw       r0, 0x6C(r31)
	  bl        -0x16544
	  stw       r27, 0x72C(r31)
	  mr        r3, r31
	  stw       r27, 0x730(r31)
	  stw       r27, 0x734(r31)
	  stw       r27, 0x7D8(r31)
	  stw       r27, 0x770(r31)
	  lwz       r0, 0x4C(r1)
	  lmw       r26, 0x30(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void Navi::Locus::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800FA1F4
 * Size:	000054
 */
void Navi::startKontroller()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, -0x5F88(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x2C
	  lwz       r3, 0x2E4(r3)
	  li        r5, 0x384
	  lwz       r4, 0x3118(r13)
	  bl        0x1BA40
	  b         .loc_0x44

	.loc_0x2C:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x44
	  lwz       r3, 0x2E4(r3)
	  li        r5, 0x384
	  lwz       r4, 0x3118(r13)
	  bl        0x1BA74

	.loc_0x44:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FA248
 * Size:	000040
 */
void Navi::rideUfo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stb       r0, 0x2E0(r3)
	  lwz       r3, 0x774(r3)
	  bl        0x1A2AC
	  lwz       r3, 0x778(r31)
	  bl        0x1A2A4
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FA288
 * Size:	000408
 */
void Navi::reset()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x2
	  mtctr     r0
	  li        r0, 0x5
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stfd      f30, 0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0
	  mr        r6, r31
	  stw       r30, 0x30(r1)
	  stw       r5, 0x2DC(r3)
	  li        r3, 0x1
	  stw       r5, 0x2D8(r31)
	  stw       r5, 0x2D4(r31)
	  stw       r5, 0x304(r31)
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x2F4(r31)
	  stfs      f0, 0x2F8(r31)
	  lwz       r4, 0xC8(r31)
	  oris      r4, r4, 0x40
	  stw       r4, 0xC8(r31)
	  stb       r5, 0x830(r31)
	  stb       r5, 0x2E0(r31)
	  stb       r5, 0x2E1(r31)
	  stw       r5, 0x2EC(r31)
	  stb       r5, 0x7E4(r31)
	  stb       r5, 0x7E5(r31)
	  stw       r5, 0x2FC(r31)
	  stfs      f0, 0x300(r31)
	  stb       r5, 0x308(r31)
	  stw       r5, 0x30C(r31)
	  stw       r5, 0x310(r31)
	  stw       r3, 0x6FC(r31)
	  stw       r0, 0x700(r31)
	  lfs       f0, -0x2C20(r13)
	  stfs      f0, 0x79C(r31)
	  lfs       f0, -0x2C1C(r13)
	  stfs      f0, 0x7A0(r31)
	  lfs       f0, -0x2C18(r13)
	  stfs      f0, 0x7A4(r31)

	.loc_0xAC:
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x938(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x93C(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x940(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x944(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x948(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x94C(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x950(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x954(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x958(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x95C(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x960(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x964(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x968(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x96C(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x970(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x974(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x978(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x97C(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x980(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x984(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x988(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x98C(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x990(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x994(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x998(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x99C(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x9A0(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x9A4(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x9A8(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x9AC(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x9B0(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x9B4(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x9B8(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x9BC(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x9C0(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x9C4(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x9C8(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x9CC(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x9D0(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x9D4(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x9D8(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x9DC(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x9E0(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x9E4(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x9E8(r6)
	  lfs       f0, -0x2C14(r13)
	  stfs      f0, 0x9EC(r6)
	  lfs       f0, -0x2C10(r13)
	  stfs      f0, 0x9F0(r6)
	  lfs       f0, -0x2C0C(r13)
	  stfs      f0, 0x9F4(r6)
	  addi      r6, r6, 0xC0
	  bdnz+     .loc_0xAC
	  lwz       r3, 0x2F64(r13)
	  addi      r4, r31, 0x6C4
	  li        r5, 0
	  bl        -0xCAB9C
	  li        r0, 0
	  stb       r0, 0x70C(r31)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r3, 0x320(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0xCC
	  bl        -0xB34F0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x284
	  lwz       r4, 0x2F00(r13)
	  bl        -0x54DE4

	.loc_0x284:
	  stw       r30, 0x710(r31)
	  li        r30, 0
	  addi      r4, r31, 0x94
	  stb       r30, 0x719(r31)
	  lwz       r3, 0x710(r31)
	  bl        -0x54B98
	  stw       r30, 0x7B4(r31)
	  stw       r30, 0x7B0(r31)
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x7A8(r31)
	  lfs       f0, -0x2C08(r13)
	  stfs      f0, 0x784(r31)
	  lfs       f0, -0x2C04(r13)
	  stfs      f0, 0x788(r31)
	  lfs       f0, -0x2C00(r13)
	  stfs      f0, 0x78C(r31)
	  stb       r30, 0x724(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f3, -0x6384(r2)
	  lfs       f2, 0x398(r4)
	  lfs       f0, 0x3A8(r4)
	  lfs       f1, 0xA0(r31)
	  fadds     f0, f2, f0
	  fmuls     f30, f3, f0
	  bl        0x1215E8
	  fmuls     f31, f30, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x121770
	  fmuls     f0, f30, f1
	  stfs      f0, 0x6D4(r31)
	  lfs       f0, -0x2BFC(r13)
	  stfs      f0, 0x6D8(r31)
	  stfs      f31, 0x6DC(r31)
	  lfs       f1, 0x6D4(r31)
	  lfs       f0, 0x6D8(r31)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x6DC(r31)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x38C
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0x24(r1)
	  lfs       f4, 0x24(r1)

	.loc_0x38C:
	  stfs      f4, 0x6E0(r31)
	  li        r0, 0
	  li        r4, 0x15
	  lwz       r5, 0x6D4(r31)
	  lwz       r3, 0x6D8(r31)
	  stw       r5, 0x6E4(r31)
	  stw       r3, 0x6E8(r31)
	  lwz       r3, 0x6DC(r31)
	  stw       r3, 0x6EC(r31)
	  lfs       f0, -0x2BF8(r13)
	  stfs      f0, 0x6F0(r31)
	  lfs       f0, -0x2BF4(r13)
	  stfs      f0, 0x6F4(r31)
	  lfs       f0, -0x2BF0(r13)
	  stfs      f0, 0x6F8(r31)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x7DC(r31)
	  stw       r0, 0x7F8(r31)
	  lwz       r3, 0x774(r31)
	  bl        0x19DFC
	  lwz       r3, 0x778(r31)
	  li        r4, 0x16
	  bl        0x19DF0
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lfd       f30, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FA690
 * Size:	00000C
 */
f32 Navi::getSize()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x224(r3)
	  lfs       f1, 0x208(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FA69C
 * Size:	000048
 */
f32 Navi::getiMass()
{
	/*
	.loc_0x0:
	  lwz       r4, 0xADC(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x14
	  lwz       r4, 0x4(r4)
	  b         .loc_0x18

	.loc_0x14:
	  li        r4, -0x1

	.loc_0x18:
	  subi      r0, r4, 0x5
	  cmplwi    r0, 0x1
	  bgt-      .loc_0x2C
	  lfs       f1, -0x63A0(r2)
	  blr

	.loc_0x2C:
	  cmpwi     r4, 0x1D
	  bne-      .loc_0x3C
	  lfs       f1, -0x6388(r2)
	  blr

	.loc_0x3C:
	  lwz       r3, 0x224(r3)
	  lfs       f1, 0x228(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FA6E4
 * Size:	00018C
 */
void Navi::findNextThrowPiki()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stfd      f30, 0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  stw       r28, 0x28(r1)
	  addi      r28, r3, 0
	  stw       r0, 0x7F8(r3)
	  lwz       r31, 0x710(r3)
	  lfs       f31, -0x6370(r2)
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x108

	.loc_0x54:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x78
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x90

	.loc_0x78:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x90:
	  fmr       f1, f31
	  addi      r29, r3, 0
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        -0x6CEF4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xEC
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0x6D91C
	  fmr       f30, f1
	  fcmpo     cr0, f30, f31
	  bge-      .loc_0xEC
	  mr        r3, r29
	  bl        -0x32258
	  cmpwi     r3, 0
	  bne-      .loc_0xEC
	  mr        r3, r29
	  bl        -0x3039C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xEC
	  stw       r29, 0x7F8(r28)
	  fmr       f31, f30

	.loc_0xEC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x108:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x130
	  li        r0, 0x1
	  b         .loc_0x15C

	.loc_0x130:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x158
	  li        r0, 0x1
	  b         .loc_0x15C

	.loc_0x158:
	  li        r0, 0

	.loc_0x15C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x54
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lfd       f30, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FA870
 * Size:	000038
 */
void Navi::startMotion(PaniMotionInfo&, PaniMotionInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x834
	  bl        0x251E0
	  li        r0, -0x1
	  stw       r0, 0x7E0(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FA8A8
 * Size:	000050
 */
void Navi::enableMotionBlend()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0x88C
	  lwz       r0, 0x8D0(r3)
	  stw       r0, 0x7E0(r3)
	  addi      r3, r1, 0x1C
	  bl        0x2468C
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  bl        0x248E8
	  lfs       f0, -0x63A4(r2)
	  stfs      f0, 0x2C(r31)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void Navi::doMotionBlend()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800FA8F8
 * Size:	0003BC
 */
void Navi::updateWalkAnimation()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x188(r1)
	  stfd      f31, 0x180(r1)
	  stfd      f30, 0x178(r1)
	  stw       r31, 0x174(r1)
	  stw       r30, 0x170(r1)
	  stw       r29, 0x16C(r1)
	  mr        r29, r3
	  stw       r28, 0x168(r1)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x218(r3)
	  stfs      f0, 0x270(r29)
	  lfs       f1, 0x94(r29)
	  lfs       f0, 0x79C(r29)
	  lfs       f2, 0x9C(r29)
	  fsubs     f3, f1, f0
	  lfs       f0, 0x7A4(r29)
	  lfs       f1, -0x63A0(r2)
	  fsubs     f2, f2, f0
	  fmuls     f0, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f0, f0, f1
	  fadds     f4, f2, f0
	  fcmpo     cr0, f4, f1
	  ble-      .loc_0xC0
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0xB8(r1)
	  lfs       f4, 0xB8(r1)

	.loc_0xC0:
	  lwz       r3, 0x2DEC(r13)
	  addi      r31, r29, 0x88C
	  lbz       r0, 0x30(r29)
	  lfs       f0, 0x28C(r3)
	  cmplwi    r0, 0
	  lwz       r4, 0x8D0(r29)
	  fdivs     f3, f4, f0
	  beq-      .loc_0xE4
	  lfs       f3, -0x63A0(r2)

	.loc_0xE4:
	  lwz       r0, 0x158(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x394
	  cmpwi     r4, 0x3
	  beq-      .loc_0x12C
	  cmpwi     r4, 0x2
	  beq-      .loc_0x12C
	  cmpwi     r4, 0xB
	  beq-      .loc_0x12C
	  cmpwi     r4, 0
	  beq-      .loc_0x12C
	  cmpwi     r4, 0x1
	  beq-      .loc_0x12C
	  cmplwi    r0, 0
	  bne-      .loc_0x394
	  lfs       f0, -0x6338(r2)
	  stfs      f0, 0x6BC(r29)
	  b         .loc_0x394

	.loc_0x12C:
	  lwz       r5, 0x224(r29)
	  li        r6, 0
	  lfs       f2, 0xA0(r29)
	  lfs       f1, 0x7DC(r29)
	  lfs       f0, 0x248(r5)
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f3, f0
	  fabs      f1, f1
	  bge-      .loc_0x16C
	  lfs       f0, -0x62DC(r2)
	  li        r30, 0x3
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x164
	  li        r30, 0xB

	.loc_0x164:
	  lfs       f31, -0x6338(r2)
	  b         .loc_0x200

	.loc_0x16C:
	  lfs       f0, 0x258(r5)
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x184
	  lfs       f31, -0x6338(r2)
	  li        r30, 0xB
	  b         .loc_0x200

	.loc_0x184:
	  lfs       f1, 0x268(r5)
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0x1BC
	  fsubs     f2, f3, f0
	  lfs       f3, 0x288(r5)
	  fsubs     f1, f1, f0
	  lfs       f0, 0x298(r5)
	  addi      r6, r29, 0
	  fdivs     f1, f2, f1
	  li        r30, 0x2
	  fsubs     f0, f0, f3
	  fmuls     f0, f1, f0
	  fadds     f31, f3, f0
	  b         .loc_0x200

	.loc_0x1BC:
	  lfs       f0, 0x278(r5)
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x1F4
	  fsubs     f2, f3, f1
	  lfs       f3, 0x2A8(r5)
	  fsubs     f1, f0, f1
	  lfs       f0, 0x2B8(r5)
	  addi      r6, r29, 0
	  fdivs     f1, f2, f1
	  li        r30, 0
	  fsubs     f0, f0, f3
	  fmuls     f0, f1, f0
	  fadds     f31, f3, f0
	  b         .loc_0x200

	.loc_0x1F4:
	  lfs       f31, 0x2C8(r5)
	  addi      r6, r29, 0
	  li        r30, 0x1

	.loc_0x200:
	  cmpw      r30, r4
	  beq-      .loc_0x26C
	  cmpwi     r4, 0x3
	  bne-      .loc_0x220
	  cmpwi     r30, 0xB
	  beq-      .loc_0x220
	  li        r0, 0x4
	  stw       r0, 0x700(r29)

	.loc_0x220:
	  cmpwi     r4, 0xB
	  beq-      .loc_0x238
	  cmpwi     r30, 0x3
	  bne-      .loc_0x238
	  li        r0, 0x4
	  stw       r0, 0x700(r29)

	.loc_0x238:
	  lwz       r0, 0x6FC(r29)
	  cmpw      r30, r0
	  beq-      .loc_0x254
	  li        r0, 0
	  stw       r0, 0x700(r29)
	  stw       r30, 0x6FC(r29)
	  b         .loc_0x260

	.loc_0x254:
	  lwz       r3, 0x700(r29)
	  addi      r0, r3, 0x1
	  stw       r0, 0x700(r29)

	.loc_0x260:
	  lwz       r0, 0x700(r29)
	  cmpwi     r0, 0x4
	  blt-      .loc_0x394

	.loc_0x26C:
	  cmpw      r4, r30
	  beq-      .loc_0x390
	  cmpwi     r4, 0x3
	  beq-      .loc_0x294
	  cmpwi     r4, 0xB
	  beq-      .loc_0x294
	  cmpwi     r30, 0x3
	  beq-      .loc_0x294
	  cmpwi     r30, 0xB
	  bne-      .loc_0x310

	.loc_0x294:
	  lwz       r0, 0x7E0(r29)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x2E4
	  cmplwi    r6, 0
	  addi      r5, r6, 0
	  beq-      .loc_0x2B0
	  addi      r5, r5, 0x2B8

	.loc_0x2B0:
	  addi      r4, r30, 0
	  addi      r3, r1, 0x130
	  bl        0x243DC
	  addi      r3, r1, 0x138
	  addi      r4, r30, 0
	  bl        0x2439C
	  addi      r3, r29, 0x834
	  addi      r4, r1, 0x138
	  addi      r5, r1, 0x130
	  bl        0x24E9C
	  li        r0, -0x1
	  stw       r0, 0x7E0(r29)
	  b         .loc_0x390

	.loc_0x2E4:
	  cmplwi    r6, 0
	  addi      r5, r6, 0
	  beq-      .loc_0x2F4
	  addi      r5, r5, 0x2B8

	.loc_0x2F4:
	  addi      r4, r30, 0
	  addi      r3, r1, 0x128
	  bl        0x24398
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  bl        0x245C0
	  b         .loc_0x390

	.loc_0x310:
	  lwz       r0, 0x7E0(r29)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x35C
	  cmplwi    r6, 0
	  addi      r5, r6, 0
	  beq-      .loc_0x32C
	  addi      r5, r5, 0x2B8

	.loc_0x32C:
	  addi      r4, r30, 0
	  addi      r3, r1, 0x118
	  bl        0x24360
	  addi      r31, r3, 0
	  addi      r4, r30, 0
	  addi      r3, r1, 0x120
	  bl        0x2431C
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        0x5D14
	  b         .loc_0x390

	.loc_0x35C:
	  addi      r28, r31, 0x2C
	  cmplwi    r6, 0
	  lfs       f30, 0x2C(r31)
	  mr        r5, r6
	  beq-      .loc_0x374
	  addi      r5, r5, 0x2B8

	.loc_0x374:
	  addi      r4, r30, 0
	  addi      r3, r1, 0x110
	  bl        0x24318
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  bl        0x24540
	  stfs      f30, 0x0(r28)

	.loc_0x390:
	  stfs      f31, 0x6BC(r29)

	.loc_0x394:
	  lwz       r0, 0x18C(r1)
	  lfd       f31, 0x180(r1)
	  lfd       f30, 0x178(r1)
	  lwz       r31, 0x174(r1)
	  lwz       r30, 0x170(r1)
	  lwz       r29, 0x16C(r1)
	  lwz       r28, 0x168(r1)
	  addi      r1, r1, 0x188
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FACB4
 * Size:	000034
 */
void Navi::postUpdate(int, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r5, r5, 0x2848
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x1D8(r5)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x24
	  bl        -0x6F54C

	.loc_0x24:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FACE8
 * Size:	000500
 */
void Navi::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1E0(r1)
	  stfd      f31, 0x1D8(r1)
	  stfd      f30, 0x1D0(r1)
	  stfd      f29, 0x1C8(r1)
	  stw       r31, 0x1C4(r1)
	  mr        r31, r3
	  stw       r30, 0x1C0(r1)
	  lwz       r0, 0x28C(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x54
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x92CC0
	  lfs       f0, 0x98(r31)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x54
	  stfs      f1, 0x98(r31)

	.loc_0x54:
	  li        r0, 0
	  lis       r3, 0x803A
	  stw       r0, 0x2FC(r31)
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,25,25
	  beq-      .loc_0x8C
	  lfs       f0, -0x2BEC(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x2BE8(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x2BE4(r13)
	  stfs      f0, 0xC4(r31)
	  b         .loc_0x4DC

	.loc_0x8C:
	  lbz       r0, 0x7E4(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x10C
	  lwz       r3, 0xADC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xAC
	  lwz       r0, 0x4(r3)
	  b         .loc_0xB0

	.loc_0xAC:
	  li        r0, -0x1

	.loc_0xB0:
	  cmpwi     r0, 0x5
	  beq-      .loc_0x10C
	  cmpwi     r0, 0x6
	  beq-      .loc_0x10C
	  lbz       r3, 0x7E6(r31)
	  addi      r0, r3, 0x1
	  stb       r0, 0x7E6(r31)
	  lwz       r3, 0x224(r31)
	  lbz       r4, 0x7E6(r31)
	  lwz       r0, 0x438(r3)
	  cmpw      r4, r0
	  ble-      .loc_0x10C
	  li        r30, 0
	  stb       r30, 0x7E4(r31)
	  stb       r30, 0x7E5(r31)
	  lwz       r3, 0x30D8(r13)
	  lwz       r3, 0x20(r3)
	  bl        0x28298
	  lwz       r3, 0x30D8(r13)
	  li        r0, 0x1
	  lwz       r3, 0x20(r3)
	  stb       r0, 0x30(r3)
	  stb       r30, 0x7E6(r31)

	.loc_0x10C:
	  lwz       r3, 0x28C(r31)
	  li        r0, -0x1
	  cmplwi    r3, 0
	  beq-      .loc_0x124
	  bl        0x1B27C
	  mr        r0, r3

	.loc_0x124:
	  cmpwi     r0, 0x5
	  bne-      .loc_0x1D0
	  lbz       r0, 0x308(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x1C4
	  lfs       f1, -0x63A0(r2)
	  addi      r0, r31, 0x94
	  lfs       f0, -0x6388(r2)
	  addi      r4, r1, 0x18C
	  stfs      f1, 0x194(r1)
	  stfs      f1, 0x190(r1)
	  stfs      f1, 0x18C(r1)
	  stfs      f1, 0x168(r1)
	  stfs      f1, 0x1A0(r1)
	  stfs      f1, 0x164(r1)
	  stfs      f1, 0x19C(r1)
	  stfs      f1, 0x160(r1)
	  stfs      f1, 0x198(r1)
	  stfs      f1, 0x174(r1)
	  stw       r0, 0x1AC(r1)
	  stfs      f1, 0x170(r1)
	  stfs      f0, 0x1B0(r1)
	  stfs      f1, 0x16C(r1)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x160(r1)
	  stw       r0, 0x164(r1)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x168(r1)
	  stfs      f0, 0x184(r1)
	  lwz       r3, 0x318(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x11
	  addi      r4, r1, 0x160
	  bl        0x19440
	  li        r3, 0x148
	  bl        -0x55ACC

	.loc_0x1C4:
	  li        r0, 0x1
	  stb       r0, 0x308(r31)
	  b         .loc_0x200

	.loc_0x1D0:
	  lbz       r0, 0x308(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1F8
	  li        r0, 0
	  stb       r0, 0x308(r31)
	  lwz       r3, 0x318(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x1F8:
	  li        r0, 0
	  stb       r0, 0x308(r31)

	.loc_0x200:
	  addi      r3, r31, 0x6C4
	  li        r4, 0
	  bl        -0xCBE54
	  lfs       f3, 0x6E4(r31)
	  lfs       f2, 0x6D4(r31)
	  lfs       f1, 0x6E8(r31)
	  lfs       f0, 0x6D8(r31)
	  fsubs     f31, f3, f2
	  lfs       f2, 0x6EC(r31)
	  fsubs     f30, f1, f0
	  lfs       f0, 0x6DC(r31)
	  fmuls     f1, f31, f31
	  fsubs     f29, f2, f0
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xED2EC
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x260
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x260:
	  lfs       f0, -0x63A0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2E4
	  lwz       r4, 0x2DEC(r13)
	  lwz       r3, 0x224(r31)
	  lfs       f2, 0x28C(r4)
	  lfs       f0, 0x3B8(r3)
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x28C
	  fmr       f0, f1

	.loc_0x28C:
	  fmuls     f2, f31, f0
	  fmuls     f1, f30, f0
	  fmuls     f0, f29, f0
	  stfs      f2, 0x7C(r1)
	  lfs       f3, 0x6D4(r31)
	  lfs       f2, 0x7C(r1)
	  fadds     f2, f3, f2
	  stfs      f2, 0x9C(r1)
	  lfs       f2, 0x9C(r1)
	  stfs      f2, 0xE4(r1)
	  lfs       f2, 0x6D8(r31)
	  fadds     f1, f2, f1
	  stfs      f1, 0xE8(r1)
	  lfs       f1, 0x6DC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0xEC(r1)
	  lwz       r3, 0xE4(r1)
	  lwz       r0, 0xE8(r1)
	  stw       r3, 0x6D4(r31)
	  stw       r0, 0x6D8(r31)
	  lwz       r0, 0xEC(r1)
	  stw       r0, 0x6DC(r31)

	.loc_0x2E4:
	  lwz       r3, 0x710(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x6EC
	  lwz       r4, 0x94(r31)
	  addi      r3, r31, 0x834
	  lwz       r0, 0x98(r31)
	  stw       r4, 0x79C(r31)
	  stw       r0, 0x7A0(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x7A4(r31)
	  lfs       f1, 0x6BC(r31)
	  bl        0x24B3C
	  lwz       r3, 0x2E4(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0xA0(r31)
	  mr        r3, r31
	  stfs      f0, 0x7DC(r31)
	  bl        -0x6FE24
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x93514
	  lfs       f3, 0x794(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x790(r31)
	  lfs       f0, 0x94(r31)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x798(r31)
	  fsubs     f4, f1, f0
	  lfs       f0, 0x9C(r31)
	  fmuls     f1, f3, f3
	  fsubs     f3, f2, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f2, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x3F4
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0x78(r1)
	  lfs       f4, 0x78(r1)

	.loc_0x3F4:
	  lfs       f0, -0x6324(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x4DC
	  lwz       r3, 0x28C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x4DC
	  lfs       f0, 0x94(r31)
	  lfs       f3, -0x6388(r2)
	  stfs      f0, 0x134(r1)
	  lfs       f2, -0x62D8(r2)
	  lfs       f1, 0x98(r31)
	  lfs       f0, -0x2BE0(r13)
	  fadds     f1, f3, f1
	  stfs      f1, 0x138(r1)
	  lfs       f1, 0x9C(r31)
	  stfs      f1, 0x13C(r1)
	  lfs       f1, 0x70(r31)
	  fmuls     f1, f2, f1
	  stfs      f1, 0x128(r1)
	  stfs      f0, 0x12C(r1)
	  lfs       f0, 0x78(r31)
	  fmuls     f0, f2, f0
	  stfs      f0, 0x130(r1)
	  bl        0x1AF48
	  cmpwi     r3, 0
	  blt-      .loc_0x4DC
	  cmpwi     r3, 0x3
	  bgt-      .loc_0x4DC
	  lfs       f0, -0x63A0(r2)
	  addi      r3, r3, 0x3
	  addi      r4, r1, 0xFC
	  stfs      f0, 0x104(r1)
	  stfs      f0, 0x100(r1)
	  stfs      f0, 0xFC(r1)
	  stfs      f0, 0x110(r1)
	  stfs      f0, 0x10C(r1)
	  stfs      f0, 0x108(r1)
	  lwz       r0, 0x134(r1)
	  lwz       r5, 0x138(r1)
	  stw       r0, 0xFC(r1)
	  lwz       r0, 0x13C(r1)
	  stw       r5, 0x100(r1)
	  lwz       r5, 0x128(r1)
	  stw       r0, 0x104(r1)
	  lwz       r0, 0x12C(r1)
	  stw       r5, 0x108(r1)
	  stw       r0, 0x10C(r1)
	  lwz       r0, 0x130(r1)
	  stw       r0, 0x110(r1)
	  lfs       f0, -0x6388(r2)
	  stfs      f0, 0x120(r1)
	  bl        0x19138
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x790(r31)
	  stw       r0, 0x794(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x798(r31)

	.loc_0x4DC:
	  lwz       r0, 0x1E4(r1)
	  lfd       f31, 0x1D8(r1)
	  lfd       f30, 0x1D0(r1)
	  lfd       f29, 0x1C8(r1)
	  lwz       r31, 0x1C4(r1)
	  lwz       r30, 0x1C0(r1)
	  addi      r1, r1, 0x1E0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FB1E8
 * Size:	0001F4
 */
void Navi::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x50(r1)
	  mr        r30, r4
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x7
	  bne-      .loc_0xB0
	  lwz       r3, 0x28C(r31)
	  li        r0, 0
	  cmplwi    r3, 0
	  beq-      .loc_0x40
	  bl        0x1AE60
	  mr        r0, r3

	.loc_0x40:
	  cmpwi     r0, 0x3
	  beq-      .loc_0x8C
	  bge-      .loc_0x64
	  cmpwi     r0, 0x1
	  beq-      .loc_0x7C
	  bge-      .loc_0x84
	  cmpwi     r0, 0
	  bge-      .loc_0x74
	  b         .loc_0xA4

	.loc_0x64:
	  cmpwi     r0, 0x5
	  beq-      .loc_0x94
	  bge-      .loc_0xA4
	  b         .loc_0x9C

	.loc_0x74:
	  li        r3, 0x1
	  b         .loc_0xA8

	.loc_0x7C:
	  li        r3, 0x3
	  b         .loc_0xA8

	.loc_0x84:
	  li        r3, 0
	  b         .loc_0xA8

	.loc_0x8C:
	  li        r3, 0x2
	  b         .loc_0xA8

	.loc_0x94:
	  li        r3, 0x4
	  b         .loc_0xA8

	.loc_0x9C:
	  li        r3, 0x5
	  b         .loc_0xA8

	.loc_0xA4:
	  li        r3, 0x1

	.loc_0xA8:
	  li        r4, 0
	  bl        -0xE3174

	.loc_0xB0:
	  li        r0, 0x4
	  stw       r0, 0x3C(r1)
	  addi      r3, r31, 0
	  addi      r4, r1, 0x3C
	  stw       r30, 0x40(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x2B4(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1DC
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x1DC
	  li        r0, 0
	  stb       r0, 0x2B4(r31)
	  lwz       r3, 0xADC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x114
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x114:
	  lfs       f2, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x154
	  lwz       r3, 0x320(r31)
	  addi      r4, r31, 0
	  li        r5, 0x1D
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  b         .loc_0x1CC

	.loc_0x154:
	  lis       r3, 0x803A
	  subi      r30, r3, 0x2848
	  lwz       r3, 0x1DC(r30)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x1CC
	  lwz       r3, 0x224(r31)
	  lfs       f1, -0x6380(r2)
	  lfs       f0, 0x3C8(r3)
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x1CC
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1D
	  addi      r3, r3, 0x54
	  bl        -0x78EB8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1CC
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1D
	  addi      r3, r3, 0x54
	  bl        -0x78C44
	  lwz       r3, 0x1E8(r30)
	  li        r4, 0
	  li        r5, 0x18
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1CC:
	  li        r0, 0
	  stw       r0, 0x2DC(r31)
	  stw       r0, 0x2D8(r31)
	  stw       r0, 0x2D4(r31)

	.loc_0x1DC:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FB3DC
 * Size:	0007C4
 */
void Navi::callPikis(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F8(r1)
	  stfd      f31, 0x1F0(r1)
	  fmr       f31, f1
	  stfd      f30, 0x1E8(r1)
	  stfd      f29, 0x1E0(r1)
	  stfd      f28, 0x1D8(r1)
	  stmw      r25, 0x1BC(r1)
	  mr        r31, r3
	  lwz       r27, 0x3068(r13)
	  lwz       r12, 0x0(r27)
	  mr        r3, r27
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f30, -0x6388(r2)
	  lis       r4, 0x802B
	  lfs       f29, -0x63A0(r2)
	  addi      r26, r3, 0
	  subi      r29, r5, 0x3064
	  subi      r30, r4, 0x2E74
	  b         .loc_0x3BC

	.loc_0x60:
	  cmpwi     r26, -0x1
	  bne-      .loc_0x84
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x9C

	.loc_0x84:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x9C:
	  mr        r25, r3
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3A0
	  lfs       f3, 0x9C(r25)
	  lfs       f2, 0x6F8(r31)
	  lfs       f1, 0x94(r25)
	  lfs       f0, 0x6F0(r31)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f28, f1, f0
	  fcmpo     cr0, f28, f29
	  ble-      .loc_0xF8
	  fsqrte    f0, f28
	  fmul      f0, f28, f0
	  frsp      f0, f0
	  stfs      f0, 0xF0(r1)
	  lfs       f28, 0xF0(r1)

	.loc_0xF8:
	  fcmpo     cr0, f28, f31
	  cror      2, 0x1, 0x2
	  beq-      .loc_0x3A0
	  mr        r3, r25
	  bl        -0x32F90
	  addi      r28, r3, 0
	  cmpwi     r28, 0x18
	  bne-      .loc_0x128
	  lwz       r3, 0x52C(r25)
	  li        r0, 0x1
	  stb       r0, 0x28(r3)
	  b         .loc_0x14C

	.loc_0x128:
	  cmpwi     r28, 0x16
	  bne-      .loc_0x13C
	  lwz       r3, 0x52C(r25)
	  stfs      f29, 0x14(r3)
	  b         .loc_0x14C

	.loc_0x13C:
	  cmpwi     r28, 0x19
	  bne-      .loc_0x14C
	  lwz       r3, 0x52C(r25)
	  stfs      f29, 0x10(r3)

	.loc_0x14C:
	  lwz       r0, 0x504(r25)
	  cmplw     r0, r31
	  beq-      .loc_0x160
	  cmplwi    r0, 0
	  bne-      .loc_0x308

	.loc_0x160:
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x308
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x308
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x308
	  lhz       r0, 0x4FC(r25)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x1D0
	  mr        r3, r25
	  bl        -0x3304C
	  cmpwi     r3, 0x1F
	  bne-      .loc_0x308

	.loc_0x1D0:
	  lbz       r0, 0x409(r25)
	  cmplwi    r0, 0
	  beq-      .loc_0x308
	  cmpwi     r28, 0x3
	  beq-      .loc_0x308
	  cmpwi     r28, 0x8
	  beq-      .loc_0x308
	  cmpwi     r28, 0x18
	  beq-      .loc_0x308
	  cmpwi     r28, 0x1C
	  beq-      .loc_0x308
	  cmpwi     r28, 0x1A
	  beq-      .loc_0x308
	  cmpwi     r28, 0x21
	  beq-      .loc_0x308
	  fcmpo     cr0, f28, f31
	  bge-      .loc_0x308
	  lbz       r0, 0x2B4(r25)
	  cmplwi    r0, 0
	  bne-      .loc_0x2F8
	  cmpwi     r28, 0x16
	  beq-      .loc_0x2F8
	  cmpwi     r28, 0x13
	  beq-      .loc_0x2F8
	  lhz       r0, 0x524(r25)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x250
	  lhz       r0, 0x510(r25)
	  cmplwi    r0, 0x1
	  beq-      .loc_0x250
	  mr        r3, r25
	  bl        -0x3370C

	.loc_0x250:
	  cmpwi     r28, 0x1F
	  stw       r31, 0x504(r25)
	  bne-      .loc_0x268
	  lwz       r3, 0x52C(r25)
	  li        r0, 0
	  stb       r0, 0x1D(r3)

	.loc_0x268:
	  lhz       r0, 0x4FC(r25)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x2D8
	  lwz       r0, 0x2AC(r25)
	  cmplwi    r0, 0
	  beq-      .loc_0x2D8
	  stw       r29, 0x174(r1)
	  addi      r4, r1, 0x174
	  stw       r25, 0x178(r1)
	  stw       r30, 0x174(r1)
	  stfs      f30, 0x17C(r1)
	  lwz       r28, 0x2AC(r25)
	  lwz       r12, 0x0(r28)
	  mr        r3, r28
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0xA
	  stw       r0, 0x16C(r1)
	  li        r0, 0
	  addi      r4, r28, 0
	  stw       r0, 0x170(r1)
	  addi      r5, r1, 0x16C
	  lwz       r3, 0x2E8(r28)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x2D8:
	  lwz       r3, 0x490(r25)
	  addi      r4, r25, 0
	  li        r5, 0x1A
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x324

	.loc_0x2F8:
	  stw       r31, 0x504(r25)
	  li        r0, 0x1
	  stb       r0, 0x4A0(r25)
	  b         .loc_0x324

	.loc_0x308:
	  fcmpo     cr0, f28, f31
	  bge-      .loc_0x324
	  lhz       r0, 0x4FC(r25)
	  cmplwi    r0, 0x1
	  beq-      .loc_0x324
	  mr        r3, r25
	  bl        -0x331A8

	.loc_0x324:
	  lwz       r3, 0x2F80(r13)
	  lwz       r0, 0x100(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x3A0
	  lwz       r0, 0x92C(r31)
	  lwz       r3, 0x43C(r25)
	  cmpw      r0, r3
	  beq-      .loc_0x34C
	  cmpwi     r3, -0x1
	  bne-      .loc_0x3A0

	.loc_0x34C:
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3A0
	  mr        r3, r25
	  bl        -0x331F4
	  cmpwi     r3, 0x2
	  bne-      .loc_0x3A0
	  fcmpo     cr0, f28, f31
	  bge-      .loc_0x3A0
	  stw       r31, 0x504(r25)
	  addi      r4, r25, 0
	  li        r5, 0x5
	  lwz       r3, 0x490(r25)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x3A0:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x3BC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3E4
	  li        r0, 0x1
	  b         .loc_0x410

	.loc_0x3E4:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x40C
	  li        r0, 0x1
	  b         .loc_0x410

	.loc_0x40C:
	  li        r0, 0

	.loc_0x410:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x60
	  lwz       r3, 0x30AC(r13)
	  lwz       r25, 0x64(r3)
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f30, -0x63A0(r2)
	  mr        r26, r3
	  b         .loc_0x5AC

	.loc_0x440:
	  cmpwi     r26, -0x1
	  bne-      .loc_0x464
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x47C

	.loc_0x464:
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x47C:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0xF
	  bne-      .loc_0x590
	  lfs       f3, 0x9C(r3)
	  mr        r27, r3
	  lfs       f2, 0x6F8(r31)
	  lfs       f1, 0x94(r3)
	  lfs       f0, 0x6F0(r31)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f28, f1, f0
	  fcmpo     cr0, f28, f30
	  ble-      .loc_0x4CC
	  fsqrte    f0, f28
	  fmul      f0, f28, f0
	  frsp      f0, f0
	  stfs      f0, 0xE4(r1)
	  lfs       f28, 0xE4(r1)

	.loc_0x4CC:
	  lwz       r3, 0x2F80(r13)
	  lwz       r0, 0x100(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x590
	  mr        r3, r27
	  bl        -0xF2F0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x590
	  fcmpo     cr0, f28, f31
	  bge-      .loc_0x590
	  li        r0, 0x1
	  lwz       r3, 0x3068(r13)
	  stb       r0, 0x306D(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  mr.       r28, r3
	  stb       r0, 0x306D(r13)
	  beq-      .loc_0x590
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        -0x2F8C0
	  mr        r3, r28
	  lwz       r4, 0x3CC(r27)
	  bl        -0x32098
	  mr        r3, r28
	  lwz       r4, 0x3D0(r27)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  addi      r4, r27, 0x94
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x490(r28)
	  addi      r4, r28, 0
	  li        r5, 0x5
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r27, 0
	  li        r4, 0
	  bl        -0x70C88

	.loc_0x590:
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x5AC:
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5D4
	  li        r0, 0x1
	  b         .loc_0x600

	.loc_0x5D4:
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x5FC
	  li        r0, 0x1
	  b         .loc_0x600

	.loc_0x5FC:
	  li        r0, 0

	.loc_0x600:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x440
	  lwz       r28, 0x3160(r13)
	  cmplwi    r28, 0
	  beq-      .loc_0x7A0
	  lwz       r12, 0x0(r28)
	  mr        r3, r28
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f30, -0x63A0(r2)
	  lis       r4, 0x802B
	  addi      r27, r3, 0
	  subi      r26, r5, 0x3064
	  subi      r25, r4, 0x331C
	  b         .loc_0x744

	.loc_0x644:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x668
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x680

	.loc_0x668:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x680:
	  lfs       f3, 0x9C(r3)
	  mr        r29, r3
	  lfs       f2, 0x6F8(r31)
	  lfs       f1, 0x94(r3)
	  lfs       f0, 0x6F0(r31)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f28, f1, f0
	  fcmpo     cr0, f28, f30
	  ble-      .loc_0x6C4
	  fsqrte    f0, f28
	  fmul      f0, f28, f0
	  frsp      f0, f0
	  stfs      f0, 0xD8(r1)
	  lfs       f28, 0xD8(r1)

	.loc_0x6C4:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x728
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x728
	  fcmpo     cr0, f28, f31
	  bge-      .loc_0x728
	  stw       r26, 0x128(r1)
	  addi      r3, r29, 0
	  addi      r4, r1, 0x128
	  stw       r31, 0x12C(r1)
	  stw       r25, 0x128(r1)
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x728:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x744:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x76C
	  li        r0, 0x1
	  b         .loc_0x798

	.loc_0x76C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x794
	  li        r0, 0x1
	  b         .loc_0x798

	.loc_0x794:
	  li        r0, 0

	.loc_0x798:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x644

	.loc_0x7A0:
	  lmw       r25, 0x1BC(r1)
	  lwz       r0, 0x1FC(r1)
	  lfd       f31, 0x1F0(r1)
	  lfd       f30, 0x1E8(r1)
	  lfd       f29, 0x1E0(r1)
	  lfd       f28, 0x1D8(r1)
	  addi      r1, r1, 0x1F8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FBBA0
 * Size:	00037C
 */
void Navi::callDebugs(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF0(r1)
	  stfd      f31, 0xE8(r1)
	  stfd      f30, 0xE0(r1)
	  stfd      f29, 0xD8(r1)
	  stfd      f28, 0xD0(r1)
	  fmr       f28, f1
	  stw       r31, 0xCC(r1)
	  mr        r31, r3
	  stw       r30, 0xC8(r1)
	  stw       r29, 0xC4(r1)
	  lwz       r30, 0x3068(r13)
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x63A0(r2)
	  mr        r29, r3
	  lfd       f30, -0x6398(r2)
	  lfd       f29, -0x6390(r2)
	  b         .loc_0x16C

	.loc_0x5C:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x80
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x98

	.loc_0x80:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x98:
	  lfs       f2, 0x6F4(r31)
	  lfs       f3, 0x98(r3)
	  lfs       f1, 0x94(r3)
	  lfs       f0, 0x6F0(r31)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x9C(r3)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x6F8(r31)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f31
	  ble-      .loc_0x128
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f29, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x5C(r1)
	  lfs       f2, 0x5C(r1)

	.loc_0x128:
	  fcmpo     cr0, f2, f28
	  bge-      .loc_0x150
	  li        r0, 0x1
	  stb       r0, 0x3060(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stb       r0, 0x3060(r13)

	.loc_0x150:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x16C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x194
	  li        r0, 0x1
	  b         .loc_0x1C0

	.loc_0x194:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1BC
	  li        r0, 0x1
	  b         .loc_0x1C0

	.loc_0x1BC:
	  li        r0, 0

	.loc_0x1C0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x5C
	  lwz       r29, 0x3160(r13)
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f29, -0x63A0(r2)
	  mr        r30, r3
	  lfd       f30, -0x6398(r2)
	  lfd       f31, -0x6390(r2)
	  b         .loc_0x2F4

	.loc_0x1F4:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x218
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x230

	.loc_0x218:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x230:
	  lfs       f3, 0x98(r3)
	  lfs       f2, 0x6F4(r31)
	  lfs       f1, 0x94(r3)
	  lfs       f0, 0x6F0(r31)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x9C(r3)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x6F8(r31)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x2C0
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
	  stfs      f0, 0x54(r1)
	  lfs       f2, 0x54(r1)

	.loc_0x2C0:
	  fcmpo     cr0, f2, f28
	  bge-      .loc_0x2D8
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl

	.loc_0x2D8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x2F4:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x31C
	  li        r0, 0x1
	  b         .loc_0x348

	.loc_0x31C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x344
	  li        r0, 0x1
	  b         .loc_0x348

	.loc_0x344:
	  li        r0, 0

	.loc_0x348:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x1F4
	  lwz       r0, 0xF4(r1)
	  lfd       f31, 0xE8(r1)
	  lfd       f30, 0xE0(r1)
	  lfd       f29, 0xD8(r1)
	  lfd       f28, 0xD0(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  lwz       r29, 0xC4(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FBF1C
 * Size:	0007DC
 */
void Navi::releasePikis()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x4E0(r1)
	  stfd      f31, 0x4D8(r1)
	  stfd      f30, 0x4D0(r1)
	  stfd      f29, 0x4C8(r1)
	  stfd      f28, 0x4C0(r1)
	  stfd      f27, 0x4B8(r1)
	  stfd      f26, 0x4B0(r1)
	  stfd      f25, 0x4A8(r1)
	  stmw      r22, 0x480(r1)
	  mr        r30, r3
	  li        r31, 0
	  lwz       r29, 0x710(r3)
	  lwz       r12, 0x0(r29)
	  addi      r3, r29, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r3, 0
	  addi      r23, r1, 0x13C
	  b         .loc_0x1B4

	.loc_0x58:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x7C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x94

	.loc_0x7C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x94:
	  mr        r22, r3
	  bl        -0x33A60
	  addi      r24, r3, 0
	  addi      r3, r22, 0
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x198
	  lhz       r0, 0x4FC(r22)
	  cmplwi    r0, 0
	  beq-      .loc_0x198
	  cmpwi     r24, 0x13
	  beq-      .loc_0x198
	  cmpwi     r24, 0x1C
	  beq-      .loc_0x198
	  cmpwi     r24, 0x8
	  beq-      .loc_0x198
	  cmpwi     r24, 0x1A
	  beq-      .loc_0x198
	  cmpwi     r24, 0x6
	  beq-      .loc_0x198
	  cmpwi     r24, 0x7
	  beq-      .loc_0x198
	  cmpwi     r24, 0x3
	  beq-      .loc_0x198
	  cmpwi     r24, 0x4
	  beq-      .loc_0x198
	  cmpwi     r24, 0x21
	  beq-      .loc_0x198
	  cmpwi     r24, 0x18
	  beq-      .loc_0x198
	  cmpwi     r24, 0x1D
	  beq-      .loc_0x198
	  cmpwi     r24, 0x16
	  beq-      .loc_0x198
	  mr        r3, r22
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x198
	  lwz       r0, 0xC8(r22)
	  rlwinm.   r0,r0,0,20,20
	  bne-      .loc_0x198
	  cmpwi     r28, -0x1
	  bne-      .loc_0x174
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x18C

	.loc_0x174:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x18C:
	  rlwinm    r0,r31,2,0,29
	  stwx      r3, r23, r0
	  addi      r31, r31, 0x1

	.loc_0x198:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x1B4:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1DC
	  li        r0, 0x1
	  b         .loc_0x208

	.loc_0x1DC:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x204
	  li        r0, 0x1
	  b         .loc_0x208

	.loc_0x204:
	  li        r0, 0

	.loc_0x208:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x58
	  cmpwi     r31, 0
	  beq-      .loc_0x7AC
	  lfs       f0, -0x63A0(r2)
	  addi      r25, r1, 0x10C
	  addi      r26, r1, 0xFC
	  lfs       f1, -0x2BDC(r13)
	  stfs      f0, 0x114(r1)
	  li        r0, 0
	  stfs      f0, 0x110(r1)
	  addi      r29, r26, 0
	  addi      r27, r25, 0
	  stfs      f0, 0x10C(r1)
	  li        r23, 0
	  stfs      f0, 0x120(r1)
	  stfs      f0, 0x11C(r1)
	  stfs      f0, 0x118(r1)
	  stfs      f0, 0x12C(r1)
	  stfs      f0, 0x128(r1)
	  stfs      f0, 0x124(r1)
	  stfs      f0, 0x138(r1)
	  stfs      f0, 0x134(r1)
	  stfs      f0, 0x130(r1)
	  stfs      f1, 0x10C(r1)
	  lfs       f0, -0x2BD8(r13)
	  lfs       f2, -0x2BD4(r13)
	  stfs      f0, 0x110(r1)
	  stfs      f2, 0x114(r1)
	  stw       r0, 0xFC(r1)
	  stfs      f1, 0x118(r1)
	  stfs      f0, 0x11C(r1)
	  stfs      f2, 0x120(r1)
	  stw       r0, 0x100(r1)
	  stfs      f1, 0x124(r1)
	  stfs      f0, 0x128(r1)
	  stfs      f2, 0x12C(r1)
	  stw       r0, 0x104(r1)
	  stfs      f1, 0x130(r1)
	  stfs      f0, 0x134(r1)
	  stfs      f2, 0x138(r1)
	  stw       r0, 0x108(r1)

	.loc_0x2B0:
	  addi      r28, r1, 0x13C
	  li        r24, 0
	  b         .loc_0x3C0

	.loc_0x2BC:
	  cmplwi    r23, 0x1
	  bgt-      .loc_0x318
	  lwz       r3, 0x0(r28)
	  lhz       r0, 0x510(r3)
	  cmpw      r23, r0
	  bne-      .loc_0x3B8
	  lwz       r3, 0x0(r29)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x0(r28)
	  lfs       f1, 0x0(r27)
	  lfsu      f0, 0x94(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r27)
	  lfs       f1, 0x4(r27)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r27)
	  lfs       f1, 0x8(r27)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r27)
	  b         .loc_0x3B8

	.loc_0x318:
	  lwz       r3, 0x0(r28)
	  lhz       r0, 0x510(r3)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x3B8
	  bl        -0x343D4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x378
	  lwz       r3, 0x108(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x108(r1)
	  lwz       r3, 0x0(r28)
	  lfs       f1, 0x130(r1)
	  lfsu      f0, 0x94(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x130(r1)
	  lfs       f1, 0x134(r1)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x134(r1)
	  lfs       f1, 0x138(r1)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x138(r1)
	  b         .loc_0x3B8

	.loc_0x378:
	  lwz       r3, 0x104(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x104(r1)
	  lwz       r3, 0x0(r28)
	  lfs       f1, 0x124(r1)
	  lfsu      f0, 0x94(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x124(r1)
	  lfs       f1, 0x128(r1)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x128(r1)
	  lfs       f1, 0x12C(r1)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x12C(r1)

	.loc_0x3B8:
	  addi      r28, r28, 0x4
	  addi      r24, r24, 0x1

	.loc_0x3C0:
	  cmpw      r24, r31
	  blt+      .loc_0x2BC
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0x4
	  addi      r29, r29, 0x4
	  addi      r27, r27, 0xC
	  blt+      .loc_0x2B0
	  addi      r27, r1, 0xEC
	  lfs       f27, -0x6388(r2)
	  lfd       f28, -0x62E8(r2)
	  mr        r24, r26
	  lfs       f29, -0x63A0(r2)
	  mr        r28, r25
	  lfd       f30, -0x6398(r2)
	  lfd       f31, -0x6390(r2)
	  mr        r29, r27
	  lfs       f25, -0x6348(r2)
	  li        r22, 0
	  lis       r23, 0x4330

	.loc_0x40C:
	  lwz       r0, 0x0(r24)
	  cmpwi     r0, 0
	  ble-      .loc_0x4F4
	  xoris     r0, r0, 0x8000
	  lfs       f0, 0x0(r28)
	  stw       r0, 0x47C(r1)
	  stw       r23, 0x478(r1)
	  lfd       f1, 0x478(r1)
	  fsubs     f1, f1, f28
	  fdivs     f1, f27, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r28)
	  lfs       f0, 0x4(r28)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r28)
	  lfs       f0, 0x8(r28)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r28)
	  lwz       r0, 0x0(r24)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x46C(r1)
	  stw       r23, 0x468(r1)
	  lfd       f0, 0x468(r1)
	  stw       r0, 0x474(r1)
	  fsubs     f0, f0, f28
	  stw       r23, 0x470(r1)
	  lfd       f1, 0x470(r1)
	  fcmpo     cr0, f0, f29
	  fsubs     f26, f1, f28
	  ble-      .loc_0x4D4
	  fsqrte    f1, f26
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f26, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f26, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f26, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f26, f0
	  frsp      f0, f0
	  stfs      f0, 0x94(r1)
	  lfs       f26, 0x94(r1)

	.loc_0x4D4:
	  lwz       r3, 0x13C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  fmuls     f0, f25, f1
	  fmuls     f0, f0, f26
	  stfs      f0, 0x0(r29)

	.loc_0x4F4:
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x4
	  addi      r24, r24, 0x4
	  addi      r28, r28, 0xC
	  addi      r29, r29, 0x4
	  blt+      .loc_0x40C
	  lfs       f27, -0x63A0(r2)
	  li        r22, 0
	  lfs       f26, -0x62D4(r2)
	  lfs       f31, -0x636C(r2)

	.loc_0x51C:
	  lwz       r0, 0x0(r26)
	  cmpwi     r0, 0
	  ble-      .loc_0x5C0
	  lfs       f3, 0x0(r25)
	  lfs       f2, 0x94(r30)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x98(r30)
	  fsubs     f25, f3, f2
	  lfs       f2, 0x8(r25)
	  fsubs     f28, f1, f0
	  lfs       f0, 0x9C(r30)
	  fmuls     f1, f25, f25
	  fsubs     f29, f2, f0
	  fmuls     f0, f28, f28
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xEE83C
	  fcmpu     cr0, f27, f1
	  beq-      .loc_0x578
	  fdivs     f25, f25, f1
	  fdivs     f28, f28, f1
	  fdivs     f29, f29, f1

	.loc_0x578:
	  lfs       f0, 0x0(r27)
	  fsubs     f0, f1, f0
	  fsubs     f0, f0, f31
	  fcmpo     cr0, f0, f26
	  bge-      .loc_0x5C0
	  fsubs     f0, f26, f0
	  lfs       f3, 0x0(r25)
	  fmuls     f2, f25, f0
	  fmuls     f1, f28, f0
	  fmuls     f0, f29, f0
	  fadds     f2, f3, f2
	  stfs      f2, 0x0(r25)
	  lfs       f2, 0x4(r25)
	  fadds     f1, f2, f1
	  stfs      f1, 0x4(r25)
	  lfs       f1, 0x8(r25)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r25)

	.loc_0x5C0:
	  addi      r29, r22, 0x1
	  mulli     r0, r29, 0xC
	  addi      r24, r1, 0x10C
	  rlwinm    r3,r29,2,0,29
	  addi      r23, r1, 0xFC
	  addi      r28, r1, 0xEC
	  add       r23, r23, r3
	  add       r24, r24, r0
	  add       r28, r28, r3
	  b         .loc_0x6D0

	.loc_0x5E8:
	  lwz       r0, 0x0(r26)
	  cmpwi     r0, 0
	  ble-      .loc_0x6C0
	  lwz       r0, 0x0(r23)
	  cmpwi     r0, 0
	  ble-      .loc_0x6C0
	  lfs       f3, 0x0(r25)
	  lfs       f2, 0x0(r24)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x4(r24)
	  fsubs     f25, f3, f2
	  lfs       f2, 0x8(r25)
	  fsubs     f28, f1, f0
	  lfs       f0, 0x8(r24)
	  fmuls     f1, f25, f25
	  fsubs     f29, f2, f0
	  fmuls     f0, f28, f28
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xEE914
	  fcmpu     cr0, f27, f1
	  beq-      .loc_0x650
	  fdivs     f25, f25, f1
	  fdivs     f28, f28, f1
	  fdivs     f29, f29, f1

	.loc_0x650:
	  lfs       f2, 0x0(r27)
	  lfs       f0, 0x0(r28)
	  fsubs     f1, f1, f2
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f0, f26
	  bge-      .loc_0x6C0
	  fsubs     f1, f26, f0
	  lfs       f0, 0x0(r25)
	  fmuls     f3, f25, f1
	  fmuls     f2, f28, f1
	  fmuls     f1, f29, f1
	  fadds     f0, f0, f3
	  stfs      f0, 0x0(r25)
	  lfs       f0, 0x4(r25)
	  fadds     f0, f0, f2
	  stfs      f0, 0x4(r25)
	  lfs       f0, 0x8(r25)
	  fadds     f0, f0, f1
	  stfs      f0, 0x8(r25)
	  lfs       f0, 0x0(r24)
	  fsubs     f0, f0, f3
	  stfs      f0, 0x0(r24)
	  lfs       f0, 0x4(r24)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x4(r24)
	  lfs       f0, 0x8(r24)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x8(r24)

	.loc_0x6C0:
	  addi      r23, r23, 0x4
	  addi      r24, r24, 0xC
	  addi      r28, r28, 0x4
	  addi      r29, r29, 0x1

	.loc_0x6D0:
	  cmpwi     r29, 0x4
	  blt+      .loc_0x5E8
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x4
	  addi      r26, r26, 0x4
	  addi      r25, r25, 0xC
	  addi      r27, r27, 0x4
	  blt+      .loc_0x51C
	  li        r25, 0
	  lis       r3, 0x803A
	  rlwinm    r0,r25,2,0,29
	  addi      r27, r1, 0x13C
	  add       r27, r27, r0
	  addi      r24, r1, 0xEC
	  subi      r23, r3, 0x24E0
	  b         .loc_0x7A4

	.loc_0x710:
	  lwz       r3, 0x0(r27)
	  addi      r5, r30, 0
	  li        r4, 0
	  bl        -0x2F46C
	  lwz       r3, 0x0(r27)
	  lhz       r22, 0x510(r3)
	  bl        -0x347D4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x738
	  li        r22, 0x3

	.loc_0x738:
	  lwz       r3, 0x0(r27)
	  lwz       r3, 0x4F8(r3)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x754
	  li        r3, 0
	  b         .loc_0x760

	.loc_0x754:
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0

	.loc_0x760:
	  mulli     r5, r22, 0xC
	  rlwinm    r0,r22,2,0,29
	  addi      r4, r1, 0x10C
	  lfsx      f1, r24, r0
	  add       r4, r4, r5
	  bl        -0x41FC4
	  lwz       r0, 0x230(r23)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x79C
	  lwz       r3, 0x0(r27)
	  lwz       r0, 0x43C(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x79C
	  li        r0, 0
	  stw       r0, 0x504(r3)

	.loc_0x79C:
	  addi      r27, r27, 0x4
	  addi      r25, r25, 0x1

	.loc_0x7A4:
	  cmpw      r25, r31
	  blt+      .loc_0x710

	.loc_0x7AC:
	  lmw       r22, 0x480(r1)
	  lwz       r0, 0x4E4(r1)
	  lfd       f31, 0x4D8(r1)
	  lfd       f30, 0x4D0(r1)
	  lfd       f29, 0x4C8(r1)
	  lfd       f28, 0x4C0(r1)
	  lfd       f27, 0x4B8(r1)
	  lfd       f26, 0x4B0(r1)
	  lfd       f25, 0x4A8(r1)
	  addi      r1, r1, 0x4E0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FC6F8
 * Size:	0000C4
 */
void Navi::doAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x2848
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x1D8(r4)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0xB0
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x7A8(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x7A8(r31)
	  lfs       f1, 0x7A8(r31)
	  lfs       f0, -0x63A0(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x90
	  lwz       r0, 0x7B4(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x88
	  mr        r3, r31
	  lwz       r4, 0x7B0(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xB8(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stw       r0, 0x7B0(r31)
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x7A8(r31)
	  b         .loc_0x90

	.loc_0x88:
	  lfs       f0, -0x637C(r2)
	  stfs      f0, 0x7A8(r31)

	.loc_0x90:
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stw       r0, 0x7B4(r31)

	.loc_0xB0:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FC7BC
 * Size:	00003C
 */
void StateMachine<Navi>::exec(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0xADC(r4)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x2C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x3C(r12)
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
 * Address:	800FC7F8
 * Size:	000004
 */
void AState<Navi>::exec(Navi*) { }

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void Navi::doAttack()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void Navi::insideOnyon()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800FC7FC
 * Size:	000A40
 */
void Navi::procActionButton()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2E8(r1)
	  stfd      f31, 0x2E0(r1)
	  stfd      f30, 0x2D8(r1)
	  stfd      f29, 0x2D0(r1)
	  stfd      f28, 0x2C8(r1)
	  stfd      f27, 0x2C0(r1)
	  stfd      f26, 0x2B8(r1)
	  stfd      f25, 0x2B0(r1)
	  stmw      r27, 0x29C(r1)
	  mr        r29, r3
	  lwz       r3, 0xADC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x2E0
	  lwz       r30, 0x301C(r13)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x63A0(r2)
	  mr        r31, r3
	  lfd       f30, -0x6398(r2)
	  lfd       f29, -0x6390(r2)
	  lfs       f28, -0x6338(r2)
	  lfs       f26, -0x62E0(r2)
	  b         .loc_0x284

	.loc_0x74:
	  cmpwi     r31, -0x1
	  bne-      .loc_0x98
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xB0

	.loc_0x98:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xB0:
	  lwz       r4, 0x55C(r3)
	  mr        r28, r3
	  lwz       r0, 0x5C(r4)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x268
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x114(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x268
	  mr        r3, r28
	  bl        -0x673A8
	  cmpwi     r3, 0
	  bne-      .loc_0x268
	  lwz       r3, 0x30AC(r13)
	  bl        -0x9CB8
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  addi      r3, r1, 0x1F0
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0x9C(r28)
	  lfs       f2, 0x1F8(r1)
	  lfs       f1, 0x94(r28)
	  lfs       f0, 0x1F0(r1)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f2, f1, f0
	  fcmpo     cr0, f2, f31
	  ble-      .loc_0x18C
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f29, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x16C(r1)
	  lfs       f2, 0x16C(r1)

	.loc_0x18C:
	  fcmpo     cr0, f2, f28
	  bge-      .loc_0x1A0
	  lhz       r0, 0x570(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x268

	.loc_0x1A0:
	  lfs       f3, 0x9C(r28)
	  lfs       f2, 0x9C(r29)
	  lfs       f1, 0x94(r28)
	  lfs       f0, 0x94(r29)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f27, f1, f0
	  fcmpo     cr0, f27, f31
	  ble-      .loc_0x21C
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f29, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0x168(r1)
	  lfs       f27, 0x168(r1)

	.loc_0x21C:
	  mr        r3, r28
	  bl        -0x66C74
	  fsubs     f0, f27, f1
	  fcmpo     cr0, f0, f26
	  cror      2, 0, 0x2
	  bne-      .loc_0x268
	  lwz       r3, 0x55C(r28)
	  lwz       r3, 0x2C(r3)
	  bl        -0x67F24
	  stw       r28, 0x304(r29)
	  addi      r4, r29, 0
	  li        r5, 0xF
	  lwz       r3, 0x320(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0xA10

	.loc_0x268:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x284:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2AC
	  li        r0, 0x1
	  b         .loc_0x2D8

	.loc_0x2AC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2D4
	  li        r0, 0x1
	  b         .loc_0x2D8

	.loc_0x2D4:
	  li        r0, 0

	.loc_0x2D8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x74

	.loc_0x2E0:
	  lis       r3, 0x803A
	  subi      r4, r3, 0x2848
	  lwz       r3, 0x1DC(r4)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x3F0
	  lwz       r3, 0xADC(r29)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x3F0
	  lwz       r3, 0x20(r4)
	  lfs       f0, -0x6360(r2)
	  lfs       f1, 0x20(r3)
	  lfs       f2, 0x2F0(r4)
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x3F0
	  lwz       r3, 0x30AC(r13)
	  bl        -0x9EEC
	  cmplwi    r3, 0
	  beq-      .loc_0x3F0
	  lfs       f3, 0x9C(r3)
	  lfs       f0, 0x9C(r29)
	  lfs       f2, 0x94(r3)
	  lfs       f1, 0x94(r29)
	  fsubs     f3, f3, f0
	  lfs       f0, -0x63A0(r2)
	  fsubs     f2, f2, f1
	  fmuls     f1, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f4, f2, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x3BC
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0x158(r1)
	  lfs       f4, 0x158(r1)

	.loc_0x3BC:
	  lfs       f0, -0x6304(r2)
	  fcmpo     cr0, f4, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x3F0
	  lwz       r3, 0x320(r29)
	  addi      r4, r29, 0
	  li        r5, 0xE
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0xA10

	.loc_0x3F0:
	  li        r30, 0
	  lfs       f26, -0x62D0(r2)

	.loc_0x3F8:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r30
	  bl        -0xA244
	  cmplwi    r3, 0
	  beq-      .loc_0x444
	  lfs       f3, 0x94(r3)
	  lfs       f2, 0x94(r29)
	  lfs       f1, 0x9C(r3)
	  lfs       f0, 0x9C(r29)
	  fsubs     f2, f3, f2
	  fsubs     f0, f1, f0
	  fmuls     f1, f2, f2
	  fmuls     f0, f0, f0
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f26
	  cror      2, 0, 0x2
	  bne-      .loc_0x444
	  li        r0, 0x1
	  b         .loc_0x454

	.loc_0x444:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x3
	  blt+      .loc_0x3F8
	  li        r0, 0

	.loc_0x454:
	  lwz       r3, 0x30AC(r13)
	  rlwinm.   r0,r0,0,24,31
	  li        r30, 0
	  lwz       r31, 0x64(r3)
	  beq-      .loc_0x474
	  lwz       r3, 0x224(r29)
	  lfs       f28, 0x68(r3)
	  b         .loc_0x47C

	.loc_0x474:
	  lwz       r3, 0x224(r29)
	  lfs       f28, 0x88(r3)

	.loc_0x47C:
	  lbz       r0, 0x7E5(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x490
	  lwz       r3, 0x224(r29)
	  lfs       f28, 0x78(r3)

	.loc_0x490:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f29, -0x63A0(r2)
	  mr        r28, r3
	  lfd       f30, -0x6398(r2)
	  lfd       f31, -0x6390(r2)
	  lfs       f26, -0x62CC(r2)
	  b         .loc_0x5F0

	.loc_0x4BC:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x4E0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4F8

	.loc_0x4E0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x4F8:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0xF
	  bne-      .loc_0x5D4
	  fmr       f1, f28
	  addi      r27, r3, 0
	  addi      r3, r29, 0
	  addi      r4, r27, 0
	  bl        -0x6F480
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x5D4
	  lfs       f3, 0x9C(r27)
	  lfs       f2, 0x9C(r29)
	  lfs       f1, 0x94(r27)
	  lfs       f0, 0x94(r29)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x98(r27)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x98(r29)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fadds     f27, f1, f0
	  fcmpo     cr0, f27, f29
	  ble-      .loc_0x5A8
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0x140(r1)
	  lfs       f27, 0x140(r1)

	.loc_0x5A8:
	  fabs      f25, f2
	  mr        r3, r27
	  bl        -0x107E0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5D4
	  fcmpo     cr0, f27, f28
	  bge-      .loc_0x5D4
	  fcmpo     cr0, f25, f26
	  bge-      .loc_0x5D4
	  fmr       f28, f27
	  mr        r30, r27

	.loc_0x5D4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x5F0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x618
	  li        r0, 0x1
	  b         .loc_0x644

	.loc_0x618:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x640
	  li        r0, 0x1
	  b         .loc_0x644

	.loc_0x640:
	  li        r0, 0

	.loc_0x644:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x4BC
	  cmplwi    r30, 0
	  beq-      .loc_0xA0C
	  lbz       r0, -0x2D80(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x7E4
	  lfs       f0, -0x63A0(r2)
	  addi      r3, r1, 0x1BC
	  li        r4, 0xB
	  stfs      f0, 0x814(r29)
	  bl        0x220EC
	  addi      r3, r1, 0x1C4
	  li        r4, 0xB
	  bl        0x220E0
	  addi      r3, r29, 0x834
	  addi      r4, r1, 0x1C4
	  addi      r5, r1, 0x1BC
	  bl        0x22BE0
	  li        r0, -0x1
	  stw       r0, 0x7E0(r29)
	  lfs       f3, 0x9C(r30)
	  lfs       f2, 0x9C(r29)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x94(r29)
	  fsubs     f30, f3, f2
	  lfs       f2, 0x98(r30)
	  fsubs     f29, f1, f0
	  lfs       f0, 0x98(r29)
	  fsubs     f28, f2, f0
	  fmr       f2, f30
	  fmr       f1, f29
	  bl        0x11EB38
	  bl        -0xC493C
	  lfs       f2, 0xA0(r29)
	  bl        -0xC4918
	  lfs       f3, -0x63A4(r2)
	  fmuls     f2, f29, f29
	  fmuls     f0, f28, f28
	  fdivs     f1, f1, f3
	  stfs      f1, 0x7D0(r29)
	  fadds     f1, f2, f0
	  fmuls     f3, f30, f30
	  lfs       f0, -0x63A0(r2)
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x758
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0x120(r1)
	  lfs       f4, 0x120(r1)

	.loc_0x758:
	  lfs       f1, -0x6388(r2)
	  li        r3, 0x2
	  lfs       f0, -0x636C(r2)
	  li        r0, 0
	  fdivs     f1, f1, f4
	  lfs       f2, -0x62C8(r2)
	  addi      r4, r29, 0
	  li        r5, 0x6
	  fsubs     f0, f4, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  fmuls     f2, f29, f0
	  fmuls     f1, f28, f0
	  fmuls     f0, f30, f0
	  stfs      f2, 0x114(r1)
	  lfs       f2, 0x114(r1)
	  stfs      f2, 0x1A4(r1)
	  stfs      f1, 0x1A8(r1)
	  stfs      f0, 0x1AC(r1)
	  lwz       r7, 0x1A4(r1)
	  lwz       r6, 0x1A8(r1)
	  stw       r7, 0x7C4(r29)
	  stw       r6, 0x7C8(r29)
	  lwz       r6, 0x1AC(r1)
	  stw       r6, 0x7CC(r29)
	  stw       r3, 0x7B8(r29)
	  stw       r30, 0x7C0(r29)
	  stw       r0, 0x7BC(r29)
	  lwz       r3, 0x320(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0xA10

	.loc_0x7E4:
	  li        r0, 0x1
	  lwz       r3, 0x3068(r13)
	  stb       r0, 0x306D(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  mr.       r27, r3
	  stb       r0, 0x306D(r13)
	  beq-      .loc_0xA0C
	  addi      r3, r27, 0
	  addi      r4, r29, 0
	  bl        -0x30FD0
	  mr        r3, r27
	  lwz       r4, 0x3CC(r30)
	  bl        -0x337A8
	  mr        r3, r27
	  lwz       r4, 0x3D0(r30)
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  addi      r4, r30, 0x94
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r27, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  bl        -0x2FE94
	  lwz       r3, 0x490(r27)
	  addi      r4, r27, 0
	  li        r5, 0x4
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x723A8
	  lfs       f0, -0x63A0(r2)
	  addi      r3, r1, 0x194
	  li        r4, 0xB
	  stfs      f0, 0x814(r29)
	  bl        0x21EBC
	  addi      r3, r1, 0x19C
	  li        r4, 0xB
	  bl        0x21EB0
	  addi      r3, r29, 0x834
	  addi      r4, r1, 0x19C
	  addi      r5, r1, 0x194
	  bl        0x229B0
	  li        r0, -0x1
	  stw       r0, 0x7E0(r29)
	  lfs       f3, 0x9C(r27)
	  lfs       f2, 0x9C(r29)
	  lfs       f1, 0x94(r27)
	  lfs       f0, 0x94(r29)
	  fsubs     f30, f3, f2
	  lfs       f2, 0x98(r27)
	  fsubs     f29, f1, f0
	  lfs       f0, 0x98(r29)
	  fsubs     f28, f2, f0
	  fmr       f2, f30
	  fmr       f1, f29
	  bl        0x11E908
	  bl        -0xC4B6C
	  lfs       f2, 0xA0(r29)
	  bl        -0xC4B48
	  lfs       f3, -0x63A4(r2)
	  fmuls     f2, f29, f29
	  fmuls     f0, f28, f28
	  fdivs     f1, f1, f3
	  stfs      f1, 0x7D0(r29)
	  fadds     f1, f2, f0
	  fmuls     f3, f30, f30
	  lfs       f0, -0x63A0(r2)
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x988
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0x110(r1)
	  lfs       f4, 0x110(r1)

	.loc_0x988:
	  lfs       f1, -0x6388(r2)
	  li        r0, 0x2
	  lfs       f0, -0x636C(r2)
	  mr        r4, r29
	  fdivs     f1, f1, f4
	  lfs       f2, -0x62C8(r2)
	  li        r5, 0x6
	  fsubs     f0, f4, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  fmuls     f2, f29, f0
	  fmuls     f1, f28, f0
	  fmuls     f0, f30, f0
	  stfs      f2, 0x104(r1)
	  lfs       f2, 0x104(r1)
	  stfs      f2, 0x17C(r1)
	  stfs      f1, 0x180(r1)
	  stfs      f0, 0x184(r1)
	  lwz       r6, 0x17C(r1)
	  lwz       r3, 0x180(r1)
	  stw       r6, 0x7C4(r29)
	  stw       r3, 0x7C8(r29)
	  lwz       r3, 0x184(r1)
	  stw       r3, 0x7CC(r29)
	  stw       r0, 0x7B8(r29)
	  stw       r27, 0x7BC(r29)
	  lwz       r3, 0x320(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0xA10

	.loc_0xA0C:
	  li        r3, 0

	.loc_0xA10:
	  lmw       r27, 0x29C(r1)
	  lwz       r0, 0x2EC(r1)
	  lfd       f31, 0x2E0(r1)
	  lfd       f30, 0x2D8(r1)
	  lfd       f29, 0x2D0(r1)
	  lfd       f28, 0x2C8(r1)
	  lfd       f27, 0x2C0(r1)
	  lfd       f26, 0x2B8(r1)
	  lfd       f25, 0x2B0(r1)
	  addi      r1, r1, 0x2E8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FD23C
 * Size:	00003C
 */
void Navi::offwallCallback(DynCollObject*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x7
	  stwu      r1, -0x18(r1)
	  stw       r0, 0x10(r1)
	  stw       r4, 0x14(r1)
	  addi      r4, r1, 0x10
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FD278
 * Size:	000058
 */
void Navi::wallCallback(Plane&, DynCollObject*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0x1
	  stw       r0, 0x4(r1)
	  li        r0, 0x6
	  stwu      r1, -0x20(r1)
	  stw       r4, 0x7AC(r3)
	  stw       r6, 0x7B4(r3)
	  stw       r5, 0x7B0(r3)
	  lfs       f0, -0x637C(r2)
	  stfs      f0, 0x7A8(r3)
	  stw       r0, 0x14(r1)
	  stw       r4, 0x18(r1)
	  addi      r4, r1, 0x14
	  stw       r5, 0x1C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FD2D0
 * Size:	000004
 */
void Navi::jumpCallback() { }

/*
 * --INFO--
 * Address:	800FD2D4
 * Size:	00004C
 */
bool Navi::isAtari()
{
	/*
	.loc_0x0:
	  lwz       r3, 0xADC(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x14
	  lwz       r4, 0x4(r3)
	  b         .loc_0x18

	.loc_0x14:
	  li        r4, -0x1

	.loc_0x18:
	  cmpwi     r4, 0x7
	  li        r3, 0
	  addi      r0, r3, 0
	  beq-      .loc_0x34
	  cmpwi     r4, 0x13
	  beq-      .loc_0x34
	  li        r0, 0x1

	.loc_0x34:
	  rlwinm.   r0,r0,0,24,31
	  beqlr-
	  cmpwi     r4, 0xC
	  beqlr-
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FD320
 * Size:	00004C
 */
bool Navi::ignoreAtari(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x38
	  mr        r3, r4
	  bl        -0x34DE8
	  cmpwi     r3, 0xE
	  beq-      .loc_0x30
	  cmpwi     r3, 0xC
	  bne-      .loc_0x38

	.loc_0x30:
	  li        r3, 0x1
	  b         .loc_0x3C

	.loc_0x38:
	  li        r3, 0

	.loc_0x3C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FD36C
 * Size:	000050
 */
void Navi::bounceCallback()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x38(r1)
	  lfs       f0, -0x2BD0(r13)
	  addi      r4, r1, 0x24
	  stw       r0, 0x24(r1)
	  lfs       f1, -0x2BCC(r13)
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x2BC8(r13)
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FD3BC
 * Size:	0001D8
 */
void Navi::letPikiWork()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  mr        r29, r3
	  stw       r28, 0x50(r1)
	  lwz       r28, 0x710(r3)
	  lwz       r12, 0x0(r28)
	  mr        r3, r28
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r4, r3, 0
	  cmpwi     r4, -0x1
	  bne-      .loc_0x60
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x74

	.loc_0x60:
	  lwz       r12, 0x0(r28)
	  mr        r3, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  cmplwi    r3, 0
	  addi      r31, r3, 0
	  beq-      .loc_0x1B8
	  lwz       r3, 0x2FC(r29)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x26
	  bne-      .loc_0x10C
	  mr        r28, r3
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10C
	  addi      r4, r28, 0
	  addi      r3, r1, 0x1C
	  bl        -0x5E914
	  lfs       f1, 0x1C(r1)
	  mr        r3, r31
	  lfs       f0, 0x20(r1)
	  mr        r4, r28
	  stfs      f1, 0x34(r1)
	  addi      r5, r1, 0x34
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x24(r1)
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x34(r1)
	  lfs       f1, -0x62C4(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x38(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r1)
	  bl        -0x3286C
	  b         .loc_0x1B8

	.loc_0x10C:
	  lwz       r6, 0x2FC(r29)
	  li        r3, 0x1
	  addi      r4, r3, 0
	  lwz       r0, 0x6C(r6)
	  addi      r5, r3, 0
	  cmpwi     r0, 0x16
	  beq-      .loc_0x134
	  cmpwi     r0, 0x17
	  beq-      .loc_0x134
	  li        r5, 0

	.loc_0x134:
	  rlwinm.   r0,r5,0,24,31
	  bne-      .loc_0x14C
	  lwz       r0, 0x6C(r6)
	  cmpwi     r0, 0x18
	  beq-      .loc_0x14C
	  li        r4, 0

	.loc_0x14C:
	  rlwinm.   r0,r4,0,24,31
	  bne-      .loc_0x164
	  lwz       r0, 0x6C(r6)
	  cmpwi     r0, 0x19
	  beq-      .loc_0x164
	  li        r3, 0

	.loc_0x164:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x180
	  lis       r4, 0x6761
	  lwz       r3, 0x220(r6)
	  addi      r4, r4, 0x7465
	  bl        -0x73E24
	  mr        r30, r3

	.loc_0x180:
	  lwz       r3, 0x2FC(r29)
	  li        r28, 0
	  li        r0, 0x1
	  stw       r3, 0x28(r1)
	  addi      r3, r31, 0
	  addi      r4, r1, 0x28
	  stw       r30, 0x2C(r1)
	  stw       r28, 0x30(r1)
	  stb       r0, 0x830(r29)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r28, 0x830(r29)

	.loc_0x1B8:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  lwz       r28, 0x50(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FD594
 * Size:	000370
 */
void Navi::collisionCallback(CollEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF8(r1)
	  stfd      f31, 0xF0(r1)
	  stfd      f30, 0xE8(r1)
	  stfd      f29, 0xE0(r1)
	  stfd      f28, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  stw       r30, 0xD0(r1)
	  addi      r30, r3, 0
	  stw       r29, 0xCC(r1)
	  stw       r28, 0xC8(r1)
	  addi      r28, r4, 0
	  lwz       r0, 0x2FC(r3)
	  lwz       r3, 0x0(r4)
	  cmplw     r3, r0
	  addi      r31, r3, 0
	  beq-      .loc_0x15C
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x26
	  beq-      .loc_0x78
	  bge-      .loc_0x6C
	  cmpwi     r0, 0x1A
	  bge-      .loc_0x15C
	  cmpwi     r0, 0x16
	  bge-      .loc_0x110
	  b         .loc_0x15C

	.loc_0x6C:
	  cmpwi     r0, 0x34
	  beq-      .loc_0x110
	  b         .loc_0x15C

	.loc_0x78:
	  addi      r29, r31, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x110
	  lbz       r0, 0x3C8(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x340
	  mr        r3, r30
	  bl        -0x733F4
	  cmplw     r3, r29
	  bne-      .loc_0x340
	  addi      r3, r1, 0x78
	  addi      r4, r30, 0
	  bl        -0x733EC
	  lfs       f31, 0x78(r1)
	  mr        r4, r29
	  lfs       f30, 0x7C(r1)
	  addi      r3, r1, 0x6C
	  lfs       f29, 0x80(r1)
	  bl        -0x5EB0C
	  lfs       f1, 0x6C(r1)
	  lfs       f0, 0x70(r1)
	  fmuls     f2, f31, f1
	  lfs       f3, 0x74(r1)
	  fmuls     f1, f30, f0
	  lfs       f0, -0x62C0(r2)
	  fmuls     f3, f29, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x110
	  b         .loc_0x340
	  b         .loc_0x340

	.loc_0x110:
	  lwz       r0, 0x2FC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x124
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x300(r30)

	.loc_0x124:
	  stw       r31, 0x2FC(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x300(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x300(r30)
	  lfs       f1, 0x300(r30)
	  lfs       f0, -0x6384(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x15C
	  mr        r3, r30
	  bl        -0x328
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x300(r30)

	.loc_0x15C:
	  li        r0, 0x3
	  stw       r0, 0xA8(r1)
	  addi      r3, r30, 0
	  addi      r4, r1, 0xA8
	  lwz       r0, 0x0(r28)
	  stw       r0, 0xAC(r1)
	  lwz       r0, 0x4(r28)
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0x8(r28)
	  stw       r0, 0xB4(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xADC(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x1A8
	  lwz       r29, 0x4(r3)
	  b         .loc_0x1AC

	.loc_0x1A8:
	  li        r29, -0x1

	.loc_0x1AC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x340
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x260
	  bge-      .loc_0x1E4
	  cmpwi     r0, 0x3
	  bge-      .loc_0x1F0
	  b         .loc_0x340

	.loc_0x1E4:
	  cmpwi     r0, 0x6
	  bge-      .loc_0x340
	  b         .loc_0x234

	.loc_0x1F0:
	  lwz       r0, 0x64(r31)
	  cmplwi    r0, 0
	  mr        r3, r31
	  bl        -0x72F3C
	  li        r0, 0x2
	  stw       r0, 0x9C(r1)
	  addi      r4, r1, 0x9C
	  stw       r3, 0xA0(r1)
	  addi      r3, r30, 0x8
	  bl        -0x69770
	  lwz       r5, 0x734(r30)
	  addi      r3, r31, 0
	  li        r4, 0
	  addi      r0, r5, 0x1
	  stw       r0, 0x734(r30)
	  bl        -0x72AE0
	  b         .loc_0x340

	.loc_0x234:
	  lwz       r3, 0x734(r30)
	  cmpwi     r3, 0
	  ble-      .loc_0x340
	  lwz       r0, 0x3CC(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x340
	  subi      r0, r3, 0x1
	  stw       r0, 0x734(r30)
	  mr        r3, r31
	  bl        -0x101B8
	  b         .loc_0x340

	.loc_0x260:
	  lwz       r0, 0x734(r30)
	  cmpwi     r0, 0
	  ble-      .loc_0x340
	  cmpwi     r29, 0x22
	  beq-      .loc_0x340
	  lis       r3, 0x803A
	  lwz       r5, 0x3D0(r31)
	  subi      r3, r3, 0x24E0
	  crclr     6, 0x6
	  addi      r3, r3, 0x1B0
	  subi      r4, r13, 0x2BC0
	  bl        0x118D78
	  lfs       f3, 0x94(r30)
	  lfs       f2, 0x94(r31)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x98(r31)
	  fsubs     f29, f3, f2
	  lfs       f2, 0x9C(r30)
	  fsubs     f30, f1, f0
	  lfs       f0, 0x9C(r31)
	  fmuls     f1, f29, f29
	  fsubs     f28, f2, f0
	  fmuls     f0, f30, f30
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xEFC1C
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2E4
	  fdivs     f29, f29, f1
	  fdivs     f30, f30, f1
	  fdivs     f28, f28, f1

	.loc_0x2E4:
	  lfs       f1, 0xA0(r31)
	  bl        0x11E2D8
	  fmr       f31, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x11E460
	  lfs       f0, -0x2BC4(r13)
	  fmuls     f2, f1, f29
	  fmuls     f3, f31, f28
	  lfs       f1, -0x62BC(r2)
	  fmuls     f0, f0, f30
	  fadds     f0, f2, f0
	  fadds     f31, f3, f0
	  bl        0x11E2AC
	  fcmpo     cr0, f31, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x340
	  lwz       r3, 0x320(r30)
	  addi      r4, r30, 0
	  li        r5, 0x22
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x340:
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  lfd       f30, 0xE8(r1)
	  lfd       f29, 0xE0(r1)
	  lfd       f28, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  lwz       r29, 0xCC(r1)
	  lwz       r28, 0xC8(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FD904
 * Size:	000004
 */
void Navi::doKill() { }

/*
 * --INFO--
 * Address:	800FD908
 * Size:	0001E8
 */
void Navi::reviseController(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stfd      f29, 0x70(r1)
	  stfd      f28, 0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r4
	  stw       r30, 0x60(r1)
	  mr        r30, r3
	  lfs       f2, 0x0(r4)
	  lfs       f1, 0x4(r4)
	  fmuls     f2, f2, f2
	  lfs       f3, 0x8(r4)
	  fmuls     f1, f1, f1
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f31, f3, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0xB0
	  fsqrte    f1, f31
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0x28(r1)
	  lfs       f31, 0x28(r1)

	.loc_0xB0:
	  lfs       f1, 0x0(r31)
	  lfs       f2, 0x8(r31)
	  bl        0x11E038
	  bl        -0xC543C
	  lwz       r4, 0x224(r30)
	  lis       r3, 0x4330
	  lfs       f3, -0x62B8(r2)
	  lfs       f2, 0x328(r4)
	  lfs       f0, -0x6384(r2)
	  fmuls     f4, f3, f2
	  lfd       f3, -0x62E8(r2)
	  lfs       f2, -0x62B4(r2)
	  fmuls     f0, f0, f4
	  fadds     f0, f1, f0
	  fdivs     f0, f0, f4
	  fctiwz    f0, f0
	  stfd      f0, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x54(r1)
	  stw       r3, 0x50(r1)
	  lfd       f0, 0x50(r1)
	  fsubs     f0, f0, f3
	  fmuls     f29, f4, f0
	  fdivs     f0, f29, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x44(r1)
	  stw       r3, 0x40(r1)
	  lfd       f0, 0x40(r1)
	  fsubs     f0, f0, f3
	  fmuls     f0, f2, f0
	  fsubs     f28, f29, f0
	  fsubs     f1, f2, f28
	  bl        0x11E2A0
	  fmr       f30, f1
	  fmr       f1, f28
	  bl        0x11E294
	  fadds     f30, f1, f30
	  lfs       f1, -0x62B4(r2)
	  bl        0x11E288
	  fdivs     f3, f1, f30
	  lfs       f2, -0x6388(r2)
	  lwz       r4, 0x224(r30)
	  lfs       f0, 0x388(r4)
	  fdivs     f1, f2, f3
	  fmuls     f31, f31, f1
	  fcmpo     cr0, f31, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x184
	  fmr       f31, f2

	.loc_0x184:
	  lfs       f0, 0x368(r4)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x194
	  lfs       f31, -0x63A0(r2)

	.loc_0x194:
	  stfs      f3, 0x30B0(r13)
	  fmr       f1, f29
	  bl        0x11E0B0
	  fmuls     f30, f31, f1
	  fmr       f1, f29
	  bl        0x11E238
	  fmuls     f0, f31, f1
	  stfs      f0, 0x0(r31)
	  lfs       f0, -0x2BBC(r13)
	  stfs      f0, 0x4(r31)
	  stfs      f30, 0x8(r31)
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  lfd       f29, 0x70(r1)
	  lfd       f28, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FDAF0
 * Size:	0008FC
 */
void Navi::makeVelocity(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x390(r1)
	  stfd      f31, 0x388(r1)
	  stfd      f30, 0x380(r1)
	  stfd      f29, 0x378(r1)
	  stfd      f28, 0x370(r1)
	  stfd      f27, 0x368(r1)
	  stfd      f26, 0x360(r1)
	  stfd      f25, 0x358(r1)
	  stfd      f24, 0x350(r1)
	  stw       r31, 0x34C(r1)
	  stw       r30, 0x348(r1)
	  mr        r30, r4
	  stw       r29, 0x344(r1)
	  mr        r29, r3
	  stw       r28, 0x340(r1)
	  lwz       r5, 0x2DEC(r13)
	  lfs       f1, 0x738(r3)
	  lfs       f0, 0x28C(r5)
	  fadds     f0, f1, f0
	  stfs      f0, 0x738(r3)
	  lwz       r3, 0x2E4(r3)
	  lwz       r3, 0x20(r3)
	  rlwinm.   r0,r3,0,18,18
	  bne-      .loc_0x80
	  rlwinm.   r0,r3,0,19,19
	  bne-      .loc_0x80
	  rlwinm.   r0,r3,0,17,17
	  bne-      .loc_0x80
	  rlwinm.   r0,r3,0,15,15
	  beq-      .loc_0x88

	.loc_0x80:
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x738(r29)

	.loc_0x88:
	  lwz       r3, 0x2E4(r29)
	  bl        -0xBD0A8
	  fneg      f24, f1
	  lwz       r3, 0x2E4(r29)
	  bl        -0xBD0EC
	  fmr       f3, f24
	  lfs       f2, -0x63A0(r2)
	  addi      r3, r1, 0x32C
	  bl        0x1F344
	  lfs       f1, 0x32C(r1)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xC8
	  stfs      f0, 0x32C(r1)
	  b         .loc_0xDC

	.loc_0xC8:
	  lfs       f0, -0x62C4(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xDC
	  stfs      f0, 0x32C(r1)

	.loc_0xDC:
	  lfs       f1, 0x334(r1)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xF8
	  stfs      f0, 0x334(r1)
	  b         .loc_0x10C

	.loc_0xF8:
	  lfs       f0, -0x62C4(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x10C
	  stfs      f0, 0x334(r1)

	.loc_0x10C:
	  addi      r3, r29, 0
	  addi      r4, r1, 0x32C
	  bl        -0x2FC
	  lwz       r3, 0x74C(r29)
	  lwz       r0, 0x750(r29)
	  stw       r3, 0x740(r29)
	  stw       r0, 0x744(r29)
	  lwz       r0, 0x754(r29)
	  stw       r0, 0x748(r29)
	  lwz       r3, 0x32C(r1)
	  lwz       r0, 0x330(r1)
	  stw       r3, 0x74C(r29)
	  stw       r0, 0x750(r29)
	  lwz       r0, 0x334(r1)
	  stw       r0, 0x754(r29)
	  lwz       r3, 0x2E8(r29)
	  lfs       f1, 0x184(r3)
	  lfs       f2, 0x17C(r3)
	  bl        0x201C4
	  fmr       f0, f1
	  lfs       f1, -0x63A0(r2)
	  lfs       f2, -0x6388(r2)
	  addi      r3, r1, 0x298
	  fmr       f3, f1
	  fmr       f24, f0
	  bl        0x1F27C
	  fmr       f1, f24
	  addi      r4, r3, 0
	  addi      r3, r1, 0x2A4
	  bl        0x1E010
	  addi      r28, r3, 0
	  addi      r3, r1, 0x258
	  bl        0x1ED84
	  addi      r31, r3, 0
	  addi      r4, r28, 0
	  bl        0x1F048
	  rlwinm.   r0,r30,0,24,31
	  bne-      .loc_0x1BC
	  lfs       f0, -0x2BB8(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x2BB4(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x2BB0(r13)
	  stfs      f0, 0xAC(r29)

	.loc_0x1BC:
	  addi      r3, r31, 0
	  addi      r4, r1, 0x32C
	  bl        0x1EFF0
	  rlwinm.   r0,r30,0,24,31
	  bne-      .loc_0x460
	  addi      r3, r1, 0x318
	  addi      r4, r29, 0
	  bl        -0x6D044
	  lwz       r0, 0x320(r1)
	  lfs       f24, -0x6388(r2)
	  cmpwi     r0, 0
	  ble-      .loc_0x224
	  xoris     r0, r0, 0x8000
	  lfd       f2, -0x62E8(r2)
	  stw       r0, 0x33C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x62B0(r2)
	  stw       r0, 0x338(r1)
	  lfs       f0, -0x637C(r2)
	  lfd       f1, 0x338(r1)
	  fsubs     f1, f1, f2
	  fmuls     f1, f3, f1
	  fsubs     f24, f24, f1
	  fcmpo     cr0, f24, f0
	  bge-      .loc_0x224
	  fmr       f24, f0

	.loc_0x224:
	  lwz       r3, 0x710(r29)
	  bl        -0x58398
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2B0
	  lwz       r3, 0x224(r29)
	  lfs       f0, 0x32C(r1)
	  lfs       f3, 0xE8(r3)
	  lfs       f2, 0x334(r1)
	  fmuls     f1, f0, f3
	  lfs       f0, 0x330(r1)
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f3
	  stfs      f1, 0x1B0(r1)
	  lfs       f1, 0x1B0(r1)
	  stfs      f1, 0x240(r1)
	  stfs      f0, 0x244(r1)
	  stfs      f2, 0x248(r1)
	  lfs       f0, 0x240(r1)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x1A0(r1)
	  lfs       f0, 0x1A0(r1)
	  stfs      f0, 0x24C(r1)
	  lfs       f0, 0x244(r1)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x250(r1)
	  lfs       f0, 0x248(r1)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x254(r1)
	  lwz       r3, 0x24C(r1)
	  lwz       r0, 0x250(r1)
	  stw       r3, 0xA4(r29)
	  stw       r0, 0xA8(r29)
	  lwz       r0, 0x254(r1)
	  stw       r0, 0xAC(r29)
	  b         .loc_0x328

	.loc_0x2B0:
	  lwz       r3, 0x224(r29)
	  lfs       f0, 0x32C(r1)
	  lfs       f3, 0xD8(r3)
	  lfs       f2, 0x334(r1)
	  fmuls     f1, f0, f3
	  lfs       f0, 0x330(r1)
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f3
	  stfs      f1, 0x194(r1)
	  lfs       f1, 0x194(r1)
	  stfs      f1, 0x228(r1)
	  stfs      f0, 0x22C(r1)
	  stfs      f2, 0x230(r1)
	  lfs       f0, 0x228(r1)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x184(r1)
	  lfs       f0, 0x184(r1)
	  stfs      f0, 0x234(r1)
	  lfs       f0, 0x22C(r1)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x238(r1)
	  lfs       f0, 0x230(r1)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x23C(r1)
	  lwz       r3, 0x234(r1)
	  lwz       r0, 0x238(r1)
	  stw       r3, 0xA4(r29)
	  stw       r0, 0xA8(r29)
	  lwz       r0, 0x23C(r1)
	  stw       r0, 0xAC(r29)

	.loc_0x328:
	  lwz       r0, 0x28C(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x460
	  lfs       f1, 0xA4(r29)
	  lfs       f0, 0xA8(r29)
	  fmuls     f2, f1, f1
	  lfs       f3, 0xAC(r29)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x3B8
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0x130(r1)
	  lfs       f0, 0x130(r1)

	.loc_0x3B8:
	  lwz       r3, 0x28C(r29)
	  addi      r6, r1, 0xDC
	  lfs       f3, 0xA4(r29)
	  addi      r5, r1, 0xD8
	  lfs       f2, 0x18(r3)
	  lfs       f1, 0xA8(r29)
	  addi      r7, r3, 0x18
	  lfs       f0, 0x1C(r3)
	  fmuls     f2, f3, f2
	  lfs       f4, 0xAC(r29)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x20(r3)
	  lfs       f0, 0x20(r3)
	  fmuls     f3, f4, f3
	  addi      r4, r1, 0xD4
	  fadds     f1, f2, f1
	  addi      r3, r1, 0x210
	  fadds     f1, f3, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xD8(r1)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xD4(r1)
	  bl        -0xC6DF4
	  lfs       f3, 0xA4(r29)
	  lfs       f2, 0x210(r1)
	  lfs       f1, 0xA8(r29)
	  lfs       f0, 0x214(r1)
	  fsubs     f3, f3, f2
	  lfs       f2, 0xAC(r29)
	  fsubs     f4, f1, f0
	  lfs       f0, 0x218(r1)
	  fmuls     f1, f3, f3
	  fsubs     f2, f2, f0
	  fmuls     f0, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF030C

	.loc_0x460:
	  addi      r3, r31, 0
	  addi      r4, r29, 0x74C
	  bl        0x1ED4C
	  lfs       f1, 0x32C(r1)
	  lfs       f0, 0x330(r1)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x334(r1)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f28, f3, f1
	  fcmpo     cr0, f28, f0
	  ble-      .loc_0x4F0
	  fsqrte    f1, f28
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f28, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f28, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f28, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f28, f0
	  frsp      f0, f0
	  stfs      f0, 0x11C(r1)
	  lfs       f28, 0x11C(r1)

	.loc_0x4F0:
	  lfs       f24, 0x32C(r1)
	  lfs       f25, 0x330(r1)
	  fmuls     f1, f24, f24
	  lfs       f26, 0x334(r1)
	  fmuls     f0, f25, f25
	  fmuls     f2, f26, f26
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF03C0
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x52C
	  fdivs     f24, f24, f1
	  fdivs     f25, f25, f1
	  fdivs     f26, f26, f1

	.loc_0x52C:
	  lwz       r4, 0x224(r29)
	  addi      r6, r1, 0xF8
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r1, 0xF4
	  lfs       f0, 0x3B8(r4)
	  lfs       f30, 0x28C(r3)
	  addi      r4, r1, 0xF0
	  fmuls     f31, f26, f0
	  addi      r3, r1, 0x1F4
	  fmuls     f25, f25, f0
	  fmuls     f24, f24, f0
	  fmuls     f2, f31, f30
	  fmuls     f1, f25, f30
	  fmuls     f0, f24, f30
	  stfs      f2, 0xF8(r1)
	  stfs      f1, 0xF4(r1)
	  stfs      f0, 0xF0(r1)
	  bl        -0xC6F44
	  lfs       f1, 0x1F4(r1)
	  lfs       f0, 0x6D4(r29)
	  lfs       f3, 0x1F8(r1)
	  lfs       f2, 0x6D8(r29)
	  fadds     f0, f1, f0
	  lfs       f1, 0x6DC(r29)
	  lfs       f4, 0x1FC(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x2E4(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x2E8(r1)
	  stfs      f0, 0x2EC(r1)
	  lfs       f0, 0x2E4(r1)
	  lfs       f27, 0x2E8(r1)
	  fmuls     f2, f0, f0
	  lfs       f26, 0x2EC(r1)
	  fmuls     f1, f27, f27
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f26, f26
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x628
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0x10C(r1)
	  lfs       f4, 0x10C(r1)

	.loc_0x628:
	  lwz       r3, 0x224(r29)
	  lfs       f0, 0x3A8(r3)
	  fcmpo     cr0, f4, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x6F8
	  lfs       f29, 0x2E4(r1)
	  fmuls     f0, f27, f27
	  fmuls     f2, f26, f26
	  fmuls     f1, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF0504
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x670
	  fdivs     f29, f29, f1
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1

	.loc_0x670:
	  fmuls     f1, f29, f24
	  addi      r6, r1, 0xEC
	  fmuls     f0, f27, f25
	  addi      r5, r1, 0xE8
	  fmuls     f2, f26, f31
	  fadds     f0, f1, f0
	  addi      r4, r1, 0xE4
	  addi      r3, r1, 0x1E8
	  fadds     f0, f2, f0
	  fmuls     f2, f26, f0
	  fmuls     f1, f27, f0
	  fmuls     f0, f29, f0
	  stfs      f2, 0xEC(r1)
	  stfs      f1, 0xE8(r1)
	  stfs      f0, 0xE4(r1)
	  bl        -0xC7080
	  lfs       f1, 0x1E8(r1)
	  lfs       f0, 0x1EC(r1)
	  fsubs     f1, f24, f1
	  lfs       f3, 0x1F0(r1)
	  fsubs     f0, f25, f0
	  lfs       f2, 0x6D4(r29)
	  fsubs     f4, f31, f3
	  fmuls     f3, f1, f30
	  fmuls     f1, f0, f30
	  fmuls     f4, f4, f30
	  fadds     f0, f3, f2
	  stfs      f0, 0x2E4(r1)
	  lfs       f0, 0x6D8(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2E8(r1)
	  lfs       f0, 0x6DC(r29)
	  fadds     f0, f4, f0
	  stfs      f0, 0x2EC(r1)

	.loc_0x6F8:
	  lwz       r3, 0x2E4(r1)
	  lwz       r0, 0x2E8(r1)
	  stw       r3, 0x6D4(r29)
	  stw       r0, 0x6D8(r29)
	  lwz       r0, 0x2EC(r1)
	  stw       r0, 0x6DC(r29)
	  lfs       f1, 0x2E4(r1)
	  lfs       f0, 0x2E8(r1)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x2EC(r1)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x794
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0xFC(r1)
	  lfs       f4, 0xFC(r1)

	.loc_0x794:
	  stfs      f4, 0x6E0(r29)
	  lwz       r3, 0x2E4(r1)
	  lwz       r0, 0x2E8(r1)
	  stw       r3, 0x6E4(r29)
	  stw       r0, 0x6E8(r29)
	  lwz       r0, 0x2EC(r1)
	  stw       r0, 0x6EC(r29)
	  lwz       r3, 0x224(r29)
	  lfs       f0, 0x368(r3)
	  fcmpo     cr0, f28, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x7CC
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x738(r29)

	.loc_0x7CC:
	  lwz       r4, 0x224(r29)
	  li        r0, 0
	  lfs       f1, 0x738(r29)
	  lfs       f0, 0x348(r4)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x7EC
	  li        r0, 0x1

	.loc_0x7EC:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x804
	  bne-      .loc_0x88C
	  lfs       f0, 0x368(r4)
	  fcmpo     cr0, f28, f0
	  ble-      .loc_0x88C

	.loc_0x804:
	  lfs       f0, 0x378(r4)
	  fcmpo     cr0, f28, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x88C
	  lfs       f0, -0x2BAC(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x2BA8(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x2BA4(r13)
	  stfs      f0, 0xAC(r29)
	  lfs       f1, 0x6D4(r29)
	  lfs       f2, 0x6DC(r29)
	  bl        0x11D6D4
	  bl        -0xC5DA0
	  lfs       f2, 0xA0(r29)
	  bl        -0xC5D7C
	  lfs       f2, -0x6360(r2)
	  lfs       f0, 0xA0(r29)
	  fmuls     f1, f2, f1
	  fadds     f0, f0, f1
	  stfs      f0, 0xA0(r29)
	  lfs       f1, 0xA0(r29)
	  bl        -0xC5DC4
	  stfs      f1, 0xA0(r29)
	  lfs       f0, -0x2BA0(r13)
	  stfs      f0, 0x88(r29)
	  lfs       f0, 0xA0(r29)
	  stfs      f0, 0x8C(r29)
	  lfs       f0, -0x2B9C(r13)
	  stfs      f0, 0x90(r29)
	  lwz       r0, 0xC8(r29)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r29)
	  b         .loc_0x898

	.loc_0x88C:
	  lwz       r0, 0xC8(r29)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0xC8(r29)

	.loc_0x898:
	  lfs       f1, -0x2B98(r13)
	  mr        r3, r29
	  lfs       f0, -0x2B94(r13)
	  li        r4, 0
	  stfs      f1, 0x32C(r1)
	  stfs      f0, 0x330(r1)
	  lfs       f0, -0x2B90(r13)
	  stfs      f0, 0x334(r1)
	  bl        .loc_0x8FC
	  lwz       r0, 0x394(r1)
	  lfd       f31, 0x388(r1)
	  lfd       f30, 0x380(r1)
	  lfd       f29, 0x378(r1)
	  lfd       f28, 0x370(r1)
	  lfd       f27, 0x368(r1)
	  lfd       f26, 0x360(r1)
	  lfd       f25, 0x358(r1)
	  lfd       f24, 0x350(r1)
	  lwz       r31, 0x34C(r1)
	  lwz       r30, 0x348(r1)
	  lwz       r29, 0x344(r1)
	  lwz       r28, 0x340(r1)
	  addi      r1, r1, 0x390
	  mtlr      r0
	  blr

	.loc_0x8FC:
	*/
}

/*
 * --INFO--
 * Address:	800FE3EC
 * Size:	000858
 */
void Navi::makeCStick(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1E8(r1)
	  stfd      f31, 0x1E0(r1)
	  stfd      f30, 0x1D8(r1)
	  stfd      f29, 0x1D0(r1)
	  stfd      f28, 0x1C8(r1)
	  stfd      f27, 0x1C0(r1)
	  stfd      f26, 0x1B8(r1)
	  stw       r31, 0x1B4(r1)
	  mr        r31, r3
	  stw       r30, 0x1B0(r1)
	  mr        r30, r4
	  stw       r29, 0x1AC(r1)
	  stw       r28, 0x1A8(r1)
	  lwz       r3, 0x2E8(r3)
	  lfs       f1, 0x184(r3)
	  lfs       f2, 0x17C(r3)
	  bl        0x1F9D4
	  fmr       f0, f1
	  lfs       f1, -0x63A0(r2)
	  lfs       f2, -0x6388(r2)
	  addi      r3, r1, 0x124
	  fmr       f3, f1
	  fmr       f27, f0
	  bl        0x1EA8C
	  fmr       f1, f27
	  addi      r4, r3, 0
	  addi      r3, r1, 0x130
	  bl        0x1D820
	  addi      r28, r3, 0
	  addi      r3, r1, 0xE4
	  bl        0x1E594
	  addi      r29, r3, 0
	  addi      r4, r28, 0
	  bl        0x1E858
	  lwz       r3, 0x2E4(r31)
	  bl        -0xBD93C
	  fneg      f27, f1
	  lwz       r3, 0x2E4(r31)
	  bl        -0xBD980
	  fmr       f3, f27
	  lfs       f2, -0x63A0(r2)
	  addi      r3, r1, 0x18C
	  bl        0x1EA40
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0xD4
	  lfs       f0, -0x2B8C(r13)
	  lfs       f1, -0x2B88(r13)
	  stfs      f0, 0x18C(r1)
	  lfs       f0, -0x2B84(r13)
	  stfs      f1, 0x190(r1)
	  stfs      f0, 0x194(r1)

	.loc_0xD4:
	  addi      r3, r31, 0
	  addi      r4, r1, 0x18C
	  bl        -0xBC0
	  lwz       r4, 0x710(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x158
	  lwz       r3, 0xADC(r31)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x19
	  beq-      .loc_0x158
	  cmpwi     r0, 0x1D
	  beq-      .loc_0x158
	  lwz       r0, 0x74(r4)
	  cmpwi     r0, 0
	  ble-      .loc_0x148
	  lfs       f2, -0x62AC(r2)
	  lfs       f1, 0x18C(r1)
	  lfs       f0, 0x194(r1)
	  fmuls     f1, f2, f1
	  lwz       r3, 0x3030(r13)
	  fmuls     f0, f2, f0
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  stfd      f1, 0x1A0(r1)
	  stfd      f0, 0x198(r1)
	  lwz       r4, 0x1A4(r1)
	  lwz       r5, 0x19C(r1)
	  bl        -0x5AF84
	  b         .loc_0x158

	.loc_0x148:
	  lwz       r3, 0x3030(r13)
	  li        r4, 0
	  li        r5, 0
	  bl        -0x5AF98

	.loc_0x158:
	  lfs       f0, 0x18C(r1)
	  mr        r3, r29
	  lfs       f1, -0x6388(r2)
	  addi      r4, r1, 0x18C
	  fmuls     f0, f0, f1
	  stfs      f0, 0x18C(r1)
	  lfs       f0, 0x190(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x190(r1)
	  lfs       f0, 0x194(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x194(r1)
	  bl        0x1E730
	  lfs       f0, -0x2B80(r13)
	  stfs      f0, 0x764(r31)
	  lfs       f0, -0x2B7C(r13)
	  stfs      f0, 0x768(r31)
	  lfs       f0, -0x2B78(r13)
	  stfs      f0, 0x76C(r31)
	  lfs       f1, 0x18C(r1)
	  lfs       f0, 0x190(r1)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x194(r1)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x228
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0xAC(r1)
	  lfs       f4, 0xAC(r1)

	.loc_0x228:
	  lfs       f0, -0x62A8(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x3D4
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x738(r31)
	  lwz       r3, 0x18C(r1)
	  lwz       r0, 0x190(r1)
	  stw       r3, 0x764(r31)
	  stw       r0, 0x768(r31)
	  lwz       r0, 0x194(r1)
	  stw       r0, 0x76C(r31)
	  lfs       f1, 0x18C(r1)
	  lfs       f2, 0x194(r1)
	  bl        0x11D3B0
	  lwz       r3, 0x710(r31)
	  fmr       f31, f1
	  lfs       f26, 0xAC(r3)
	  bl        0x11D4FC
	  fmr       f29, f1
	  fmr       f1, f31
	  bl        0x11D684
	  fmr       f28, f1
	  lfs       f30, -0x2B74(r13)
	  fmr       f1, f26
	  bl        0x11D4E0
	  fmr       f27, f1
	  fmr       f1, f26
	  bl        0x11D668
	  lfs       f0, -0x2B70(r13)
	  fmuls     f2, f28, f1
	  fmuls     f3, f29, f27
	  lfs       f1, -0x62A4(r2)
	  fmuls     f0, f30, f0
	  fadds     f0, f2, f0
	  fadds     f27, f3, f0
	  bl        0x11D4B4
	  fcmpo     cr0, f27, f1
	  ble-      .loc_0x2DC
	  fmr       f1, f31
	  fmr       f2, f26
	  bl        -0xC6100
	  lfs       f0, -0x62A0(r2)
	  fmuls     f0, f0, f1
	  fadds     f1, f26, f0
	  b         .loc_0x2E0

	.loc_0x2DC:
	  fmr       f1, f31

	.loc_0x2E0:
	  bl        -0xC6144
	  fmr       f29, f1
	  stfs      f29, 0x714(r31)
	  lfs       f1, 0x18C(r1)
	  lfs       f0, 0x190(r1)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x194(r1)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x370
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0xA8(r1)
	  lfs       f4, 0xA8(r1)

	.loc_0x370:
	  lfs       f0, -0x62A8(r2)
	  lfs       f1, -0x629C(r2)
	  fsubs     f2, f4, f0
	  lfs       f0, -0x6298(r2)
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x398
	  lfs       f1, -0x6388(r2)
	  b         .loc_0x3A4

	.loc_0x398:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x6294(r2)
	  fmuls     f1, f1, f0

	.loc_0x3A4:
	  lwz       r3, 0x710(r31)
	  lwz       r4, 0x78(r3)
	  bl        -0x58128
	  fmr       f1, f29
	  lwz       r3, 0x710(r31)
	  addi      r4, r31, 0x94
	  addi      r5, r31, 0x70
	  bl        -0x58E20
	  li        r0, 0
	  stb       r0, 0x718(r31)
	  stb       r0, 0x724(r31)
	  b         .loc_0x808

	.loc_0x3D4:
	  lbz       r0, 0x718(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x3E8
	  li        r0, 0x1
	  stb       r0, 0x724(r31)

	.loc_0x3E8:
	  lbz       r0, 0x718(r31)
	  lfs       f1, -0x6290(r2)
	  lfs       f0, 0xA0(r31)
	  cmplwi    r0, 0
	  fadds     f28, f1, f0
	  bne-      .loc_0x4CC
	  lfs       f1, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fmuls     f2, f1, f1
	  lfs       f3, 0xAC(r31)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x484
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0xA4(r1)
	  lfs       f4, 0xA4(r1)

	.loc_0x484:
	  lfs       f0, -0x6304(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x4CC
	  lwz       r3, 0xADC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x4A4
	  lwz       r0, 0x4(r3)
	  b         .loc_0x4A8

	.loc_0x4A4:
	  li        r0, -0x1

	.loc_0x4A8:
	  cmpwi     r0, 0x2
	  beq-      .loc_0x4CC
	  lfs       f28, 0x714(r31)
	  addi      r4, r31, 0x94
	  lwz       r3, 0x710(r31)
	  addi      r5, r31, 0x70
	  fmr       f1, f28
	  bl        -0x58F24
	  b         .loc_0x4D4

	.loc_0x4CC:
	  li        r0, 0x1
	  stb       r0, 0x718(r31)

	.loc_0x4D4:
	  lwz       r3, 0x710(r31)
	  lfs       f1, -0x63A0(r2)
	  lwz       r4, 0x78(r3)
	  bl        -0x5825C
	  lwz       r29, 0x710(r31)
	  lfs       f27, -0x628C(r2)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f29, -0x63A0(r2)
	  mr        r28, r3
	  lfd       f30, -0x6398(r2)
	  lfd       f31, -0x6390(r2)
	  b         .loc_0x624

	.loc_0x514:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x53C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x558

	.loc_0x53C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x558:
	  mr        r3, r30
	  bl        -0x363F4
	  subi      r0, r3, 0xB
	  cmplwi    r0, 0x1
	  ble-      .loc_0x608
	  lfs       f3, 0x98(r30)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x94(r31)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x9C(r30)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x9C(r31)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x5FC
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
	  stfs      f0, 0x98(r1)
	  lfs       f2, 0x98(r1)

	.loc_0x5FC:
	  fcmpo     cr0, f2, f27
	  bge-      .loc_0x608
	  fmr       f27, f2

	.loc_0x608:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x624:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x64C
	  li        r0, 0x1
	  b         .loc_0x678

	.loc_0x64C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x674
	  li        r0, 0x1
	  b         .loc_0x678

	.loc_0x674:
	  li        r0, 0

	.loc_0x678:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x514
	  lwz       r4, 0x224(r31)
	  lfs       f0, 0x1E8(r4)
	  fcmpo     cr0, f27, f0
	  bge-      .loc_0x6BC
	  lwz       r0, 0x71C(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x6AC
	  lwz       r3, 0x720(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x720(r31)
	  b         .loc_0x724

	.loc_0x6AC:
	  li        r0, 0
	  stw       r0, 0x720(r31)
	  stw       r0, 0x71C(r31)
	  b         .loc_0x724

	.loc_0x6BC:
	  lfs       f0, 0x1F8(r4)
	  fcmpo     cr0, f27, f0
	  bge-      .loc_0x6F8
	  lwz       r0, 0x71C(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x6E4
	  lwz       r3, 0x720(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x720(r31)
	  b         .loc_0x724

	.loc_0x6E4:
	  li        r0, 0
	  stw       r0, 0x720(r31)
	  li        r0, 0x1
	  stw       r0, 0x71C(r31)
	  b         .loc_0x724

	.loc_0x6F8:
	  lwz       r0, 0x71C(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x714
	  lwz       r3, 0x720(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x720(r31)
	  b         .loc_0x724

	.loc_0x714:
	  li        r0, 0
	  stw       r0, 0x720(r31)
	  li        r0, 0x2
	  stw       r0, 0x71C(r31)

	.loc_0x724:
	  lwz       r0, 0x71C(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x73C
	  li        r0, 0x1
	  stb       r0, 0x719(r31)
	  b         .loc_0x808

	.loc_0x73C:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x7C0
	  li        r0, 0x1
	  stb       r0, 0x719(r31)
	  lwz       r3, 0x710(r31)
	  lfsu      f3, 0x5C(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x98(r31)
	  lfs       f2, 0x4(r3)
	  fsubs     f27, f3, f1
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x9C(r31)
	  fsubs     f28, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f27, f27
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF0F34
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x7A0
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1

	.loc_0x7A0:
	  fmr       f1, f27
	  fmr       f2, f28
	  bl        0x11CE64
	  lwz       r3, 0x710(r31)
	  addi      r4, r31, 0x94
	  addi      r5, r31, 0x70
	  bl        -0x59058
	  b         .loc_0x808

	.loc_0x7C0:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x808
	  li        r30, 0
	  stb       r30, 0x724(r31)
	  lbz       r0, 0x719(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x7F4
	  fmr       f1, f28
	  lwz       r3, 0x710(r31)
	  addi      r4, r31, 0x94
	  addi      r5, r31, 0x70
	  bl        -0x58844
	  stb       r30, 0x719(r31)

	.loc_0x7F4:
	  fmr       f1, f28
	  lwz       r3, 0x710(r31)
	  addi      r4, r31, 0x94
	  addi      r5, r31, 0x70
	  bl        -0x59264

	.loc_0x808:
	  lwz       r3, 0x18C(r1)
	  lwz       r0, 0x190(r1)
	  stw       r3, 0x758(r31)
	  stw       r0, 0x75C(r31)
	  lwz       r0, 0x194(r1)
	  stw       r0, 0x760(r31)
	  lwz       r0, 0x1EC(r1)
	  lfd       f31, 0x1E0(r1)
	  lfd       f30, 0x1D8(r1)
	  lfd       f29, 0x1D0(r1)
	  lfd       f28, 0x1C8(r1)
	  lfd       f27, 0x1C0(r1)
	  lfd       f26, 0x1B8(r1)
	  lwz       r31, 0x1B4(r1)
	  lwz       r30, 0x1B0(r1)
	  lwz       r29, 0x1AC(r1)
	  lwz       r28, 0x1A8(r1)
	  addi      r1, r1, 0x1E8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FEC44
 * Size:	0005A8
 */
void Navi::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x180(r1)
	  stfd      f31, 0x178(r1)
	  stfd      f30, 0x170(r1)
	  stw       r31, 0x16C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x168(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x164(r1)
	  bl        0x668
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x584
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x30(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C
	  lwz       r3, 0x2F00(r13)
	  addi      r4, r30, 0x94
	  bl        -0x9893C

	.loc_0x5C:
	  lwz       r3, 0x710(r30)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0xA0(r30)
	  bl        0x11D02C
	  lfs       f1, 0xA0(r30)
	  bl        0x11CE90
	  lfs       f1, 0x6D4(r30)
	  li        r4, 0x1
	  lfs       f0, 0x94(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0x88(r1)
	  stfs      f0, 0xA0(r1)
	  lfs       f1, 0x6D8(r30)
	  lfs       f0, 0x98(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA4(r1)
	  lfs       f1, 0x6DC(r30)
	  lfs       f0, 0x9C(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA8(r1)
	  lwz       r3, 0xA0(r1)
	  lwz       r0, 0xA4(r1)
	  stw       r3, 0x6F0(r30)
	  stw       r0, 0x6F4(r30)
	  lwz       r0, 0xA8(r1)
	  stw       r0, 0x6F8(r30)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x6F0(r30)
	  lfs       f2, 0x6F8(r30)
	  bl        -0x96E24
	  lfs       f0, -0x6388(r2)
	  li        r4, 0x1
	  fadds     f0, f0, f1
	  stfs      f0, 0x6F4(r30)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x6F0(r30)
	  lfs       f2, 0x6F8(r30)
	  bl        -0x96B70
	  addi      r29, r3, 0
	  addi      r3, r1, 0xD4
	  bl        -0xC0F98
	  lfs       f1, 0x6F0(r30)
	  lfs       f0, 0x94(r30)
	  lfs       f3, 0x6F4(r30)
	  lfs       f2, 0x98(r30)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x6F8(r30)
	  lfs       f1, 0x9C(r30)
	  fsubs     f2, f3, f2
	  stfs      f0, 0xC8(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0xCC(r1)
	  stfs      f0, 0xD0(r1)
	  lfs       f1, 0xC8(r1)
	  lfs       f0, 0xCC(r1)
	  lfs       f2, 0xD0(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF1168
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x198
	  lfs       f0, 0xC8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0xCC(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xCC(r1)
	  lfs       f0, 0xD0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xD0(r1)

	.loc_0x198:
	  lfs       f1, -0x2B6C(r13)
	  cmplwi    r29, 0
	  lfs       f0, -0x2B68(r13)
	  stfs      f1, 0xBC(r1)
	  stfs      f0, 0xC0(r1)
	  lfs       f0, -0x2B64(r13)
	  stfs      f0, 0xC4(r1)
	  beq-      .loc_0x224
	  lwz       r3, 0x18(r29)
	  lwz       r0, 0x1C(r29)
	  stw       r3, 0xBC(r1)
	  stw       r0, 0xC0(r1)
	  lwz       r0, 0x20(r29)
	  stw       r0, 0xC4(r1)
	  lfs       f1, 0xBC(r1)
	  lfs       f0, 0xC0(r1)
	  lfs       f2, 0xC4(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF11F4
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x224
	  lfs       f0, 0xBC(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xC0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xC4(r1)

	.loc_0x224:
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0xB8(r1)
	  stfs      f0, 0xB4(r1)
	  lwz       r0, 0xBC(r1)
	  lwz       r3, 0xC0(r1)
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0xC4(r1)
	  stw       r3, 0xB4(r1)
	  lfs       f6, 0xC8(r1)
	  stw       r0, 0xB8(r1)
	  lfs       f0, 0xB8(r1)
	  lfs       f2, 0xCC(r1)
	  fmuls     f4, f0, f6
	  lfs       f5, 0xB4(r1)
	  lfs       f3, 0xD0(r1)
	  fmuls     f0, f0, f2
	  lfs       f7, 0xB0(r1)
	  fmuls     f1, f5, f3
	  fmuls     f3, f7, f3
	  fmuls     f2, f7, f2
	  fsubs     f0, f1, f0
	  fmuls     f1, f5, f6
	  fsubs     f3, f4, f3
	  stfs      f0, 0xB0(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0xB4(r1)
	  stfs      f0, 0xB8(r1)
	  lfs       f1, 0xB0(r1)
	  lfs       f0, 0xB4(r1)
	  lfs       f2, 0xB8(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF12B4
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2E4
	  lfs       f0, 0xB0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xB0(r1)
	  lfs       f0, 0xB4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xB4(r1)
	  lfs       f0, 0xB8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xB8(r1)

	.loc_0x2E4:
	  lwz       r0, 0xB0(r1)
	  lwz       r3, 0xB4(r1)
	  stw       r0, 0xC8(r1)
	  lwz       r0, 0xB8(r1)
	  stw       r3, 0xCC(r1)
	  lfs       f6, 0xBC(r1)
	  stw       r0, 0xD0(r1)
	  lfs       f0, 0xD0(r1)
	  lfs       f31, 0xC0(r1)
	  lfs       f5, 0xCC(r1)
	  fmuls     f4, f0, f6
	  lfs       f30, 0xC4(r1)
	  fmuls     f0, f0, f31
	  lfs       f2, 0xC8(r1)
	  fmuls     f1, f5, f30
	  fmuls     f3, f2, f30
	  fmuls     f2, f2, f31
	  fsubs     f0, f1, f0
	  fmuls     f1, f5, f6
	  fsubs     f3, f4, f3
	  stfs      f0, 0xC8(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0xCC(r1)
	  stfs      f0, 0xD0(r1)
	  lfs       f1, 0xC8(r1)
	  lfs       f0, 0xCC(r1)
	  lfs       f2, 0xD0(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF1368
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x398
	  lfs       f0, 0xC8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0xCC(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xCC(r1)
	  lfs       f0, 0xD0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xD0(r1)

	.loc_0x398:
	  lfs       f0, 0xB0(r1)
	  lfs       f1, 0xBC(r1)
	  stfs      f0, 0xD4(r1)
	  lfs       f0, 0xC8(r1)
	  lfs       f2, 0xB4(r1)
	  stfs      f2, 0xE4(r1)
	  lfs       f2, 0xB8(r1)
	  stfs      f2, 0xF4(r1)
	  stfs      f1, 0xD8(r1)
	  stfs      f31, 0xE8(r1)
	  stfs      f30, 0xF8(r1)
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0xCC(r1)
	  stfs      f0, 0xEC(r1)
	  lfs       f0, 0xD0(r1)
	  stfs      f0, 0xFC(r1)
	  lwz       r3, 0xD4(r1)
	  lwz       r0, 0xD8(r1)
	  stw       r3, 0x228(r30)
	  stw       r0, 0x22C(r30)
	  lwz       r3, 0xDC(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r3, 0x230(r30)
	  stw       r0, 0x234(r30)
	  lwz       r3, 0xE4(r1)
	  lwz       r0, 0xE8(r1)
	  stw       r3, 0x238(r30)
	  stw       r0, 0x23C(r30)
	  lwz       r3, 0xEC(r1)
	  lwz       r0, 0xF0(r1)
	  stw       r3, 0x240(r30)
	  stw       r0, 0x244(r30)
	  lwz       r3, 0xF4(r1)
	  lwz       r0, 0xF8(r1)
	  stw       r3, 0x248(r30)
	  stw       r0, 0x24C(r30)
	  lwz       r3, 0xFC(r1)
	  lwz       r0, 0x100(r1)
	  stw       r3, 0x250(r30)
	  stw       r0, 0x254(r30)
	  lwz       r3, 0x104(r1)
	  lwz       r0, 0x108(r1)
	  stw       r3, 0x258(r30)
	  stw       r0, 0x25C(r30)
	  lwz       r3, 0x10C(r1)
	  lwz       r0, 0x110(r1)
	  stw       r3, 0x260(r30)
	  stw       r0, 0x264(r30)
	  lfs       f0, 0x6F0(r30)
	  stfs      f0, 0x234(r30)
	  lfs       f0, 0x6F4(r30)
	  stfs      f0, 0x244(r30)
	  lfs       f0, 0x6F8(r30)
	  stfs      f0, 0x254(r30)
	  lwz       r0, 0x310(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0x584
	  lwz       r3, 0xADC(r30)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x19
	  beq-      .loc_0x584
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x120
	  addi      r3, r3, 0x1E0
	  bl        -0xC102C
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x120
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x6C4
	  bl        -0xCFF94
	  lwz       r3, 0x2F64(r13)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  bl        -0xCECCC
	  lwz       r3, 0x7F8(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x510
	  lwz       r0, 0x508(r3)
	  stw       r0, 0xAC(r1)
	  b         .loc_0x524

	.loc_0x510:
	  li        r0, 0xFF
	  stb       r0, 0xAC(r1)
	  stb       r0, 0xAD(r1)
	  stb       r0, 0xAE(r1)
	  stb       r0, 0xAF(r1)

	.loc_0x524:
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2F60(r13)
	  mr        r29, r3
	  lwz       r0, 0xAC(r1)
	  li        r6, 0
	  lwz       r3, 0x44(r4)
	  mr        r4, r31
	  stw       r0, 0x2C(r3)
	  lwz       r3, 0x2F60(r13)
	  lwz       r5, 0x2E4(r31)
	  bl        -0xCED3C
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r29, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x584:
	  lwz       r0, 0x184(r1)
	  lfd       f31, 0x178(r1)
	  lfd       f30, 0x170(r1)
	  lwz       r31, 0x16C(r1)
	  lwz       r30, 0x168(r1)
	  lwz       r29, 0x164(r1)
	  addi      r1, r1, 0x180
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FF1EC
 * Size:	0000E8
 */
void Navi::demoDraw(Graphics&, Matrix4f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lfs       f1, -0x6288(r2)
	  lfs       f0, 0x94(r3)
	  lfs       f3, -0x6368(r2)
	  lfs       f2, 0x98(r3)
	  fadds     f0, f1, f0
	  lfs       f4, -0x62CC(r2)
	  lfs       f1, 0x9C(r3)
	  fadds     f2, f3, f2
	  stfs      f0, 0x6A0(r3)
	  fadds     f0, f4, f1
	  stfs      f2, 0x6A4(r3)
	  stfs      f0, 0x6A8(r3)
	  lfs       f2, -0x63A4(r2)
	  lfs       f1, 0x98(r3)
	  lfs       f0, 0x94(r3)
	  fadds     f1, f2, f1
	  stfs      f0, 0x6AC(r3)
	  stfs      f1, 0x6B0(r3)
	  lfs       f0, 0x9C(r3)
	  stfs      f0, 0x6B4(r3)
	  lwz       r3, 0x82C(r3)
	  lwz       r5, 0x2E4(r31)
	  lwz       r3, 0x0(r3)
	  bl        -0xCEDFC
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0x7578C
	  lis       r4, 0x616E
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x7465
	  bl        -0x75B78
	  lwz       r5, 0x4(r3)
	  addi      r4, r30, 0x784
	  lwz       r0, 0x8(r3)
	  stw       r5, 0x784(r30)
	  stw       r0, 0x788(r30)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0x78C(r30)
	  lwz       r3, 0x774(r30)
	  bl        0x1517C
	  lwz       r3, 0x778(r30)
	  addi      r4, r30, 0x784
	  bl        0x15170
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
 * Address:	800FF2D4
 * Size:	0002D8
 */
void Navi::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stw       r31, 0xB4(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xB0(r1)
	  mr        r30, r3
	  lbz       r0, 0x2E1(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x2C0
	  lwz       r3, 0xADC(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x3C
	  lwz       r0, 0x4(r3)
	  b         .loc_0x40

	.loc_0x3C:
	  li        r0, -0x1

	.loc_0x40:
	  cmpwi     r0, 0x7
	  beq-      .loc_0x5C
	  lwz       r3, 0x224(r30)
	  lfs       f0, 0xF8(r3)
	  stfs      f0, 0x7C(r30)
	  stfs      f0, 0x80(r30)
	  stfs      f0, 0x84(r30)

	.loc_0x5C:
	  lwz       r0, 0x158(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x104
	  lwz       r3, 0x114(r30)
	  lwz       r0, 0x118(r30)
	  stw       r3, 0x228(r30)
	  stw       r0, 0x22C(r30)
	  lwz       r3, 0x11C(r30)
	  lwz       r0, 0x120(r30)
	  stw       r3, 0x230(r30)
	  stw       r0, 0x234(r30)
	  lwz       r3, 0x124(r30)
	  lwz       r0, 0x128(r30)
	  stw       r3, 0x238(r30)
	  stw       r0, 0x23C(r30)
	  lwz       r3, 0x12C(r30)
	  lwz       r0, 0x130(r30)
	  stw       r3, 0x240(r30)
	  stw       r0, 0x244(r30)
	  lwz       r3, 0x134(r30)
	  lwz       r0, 0x138(r30)
	  stw       r3, 0x248(r30)
	  stw       r0, 0x24C(r30)
	  lwz       r3, 0x13C(r30)
	  lwz       r0, 0x140(r30)
	  stw       r3, 0x250(r30)
	  stw       r0, 0x254(r30)
	  lwz       r3, 0x144(r30)
	  lwz       r0, 0x148(r30)
	  stw       r3, 0x258(r30)
	  stw       r0, 0x25C(r30)
	  lwz       r3, 0x14C(r30)
	  lwz       r0, 0x150(r30)
	  stw       r3, 0x260(r30)
	  stw       r0, 0x264(r30)
	  lfs       f2, 0x9C(r30)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x94(r30)
	  stfs      f0, 0x234(r30)
	  stfs      f1, 0x244(r30)
	  stfs      f2, 0x254(r30)
	  b         .loc_0x198

	.loc_0x104:
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0xC12F4
	  lwz       r3, 0x228(r30)
	  lwz       r0, 0x22C(r30)
	  stw       r3, 0x114(r30)
	  stw       r0, 0x118(r30)
	  lwz       r3, 0x230(r30)
	  lwz       r0, 0x234(r30)
	  stw       r3, 0x11C(r30)
	  stw       r0, 0x120(r30)
	  lwz       r3, 0x238(r30)
	  lwz       r0, 0x23C(r30)
	  stw       r3, 0x124(r30)
	  stw       r0, 0x128(r30)
	  lwz       r3, 0x240(r30)
	  lwz       r0, 0x244(r30)
	  stw       r3, 0x12C(r30)
	  stw       r0, 0x130(r30)
	  lwz       r3, 0x248(r30)
	  lwz       r0, 0x24C(r30)
	  stw       r3, 0x134(r30)
	  stw       r0, 0x138(r30)
	  lwz       r3, 0x250(r30)
	  lwz       r0, 0x254(r30)
	  stw       r3, 0x13C(r30)
	  stw       r0, 0x140(r30)
	  lwz       r3, 0x258(r30)
	  lwz       r0, 0x25C(r30)
	  stw       r3, 0x144(r30)
	  stw       r0, 0x148(r30)
	  lwz       r3, 0x260(r30)
	  lwz       r0, 0x264(r30)
	  stw       r3, 0x14C(r30)
	  stw       r0, 0x150(r30)

	.loc_0x198:
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x58
	  addi      r3, r3, 0x1E0
	  bl        -0xC13C8
	  addi      r3, r30, 0x834
	  bl        0x20760
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r30)
	  lfs       f2, 0x9C(r30)
	  bl        -0x9771C
	  lwz       r3, 0x82C(r30)
	  addi      r6, r30, 0x838
	  li        r8, 0
	  lwz       r3, 0x0(r3)
	  li        r5, 0
	  lwz       r4, 0x58(r3)
	  cmpwi     r4, 0
	  mtctr     r4
	  ble-      .loc_0x264

	.loc_0x208:
	  lwz       r4, 0x1C(r3)
	  lwzx      r4, r4, r5
	  lwz       r7, 0x0(r4)
	  cmplwi    r7, 0
	  beq-      .loc_0x25C
	  addic.    r4, r4, 0x4
	  beq-      .loc_0x25C
	  lfs       f0, 0x0(r4)
	  fctiwz    f0, f0
	  stfd      f0, 0xA0(r1)
	  lwz       r4, 0xA4(r1)
	  stfd      f0, 0xA8(r1)
	  cmpwi     r4, 0
	  lwz       r9, 0xAC(r1)
	  blt-      .loc_0x250
	  lwz       r4, 0x30(r7)
	  cmpw      r9, r4
	  blt-      .loc_0x25C

	.loc_0x250:
	  lwz       r4, 0x44(r6)
	  cmpwi     r4, 0
	  li        r8, 0x1

	.loc_0x25C:
	  addi      r5, r5, 0x4
	  bdnz+     .loc_0x208

	.loc_0x264:
	  rlwinm.   r0,r8,0,24,31
	  bne-      .loc_0x27C
	  addi      r4, r31, 0
	  addi      r5, r1, 0x58
	  li        r6, 0
	  bl        -0xCA238

	.loc_0x27C:
	  mr        r3, r30
	  bl        0x17BC
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,29,29
	  bne-      .loc_0x2C0
	  lbz       r0, 0x2E0(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x2C0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0xFC(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C0:
	  lwz       r0, 0xBC(r1)
	  lwz       r31, 0xB4(r1)
	  lwz       r30, 0xB0(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FF5AC
 * Size:	0001FC
 */
void Navi::renderCircle(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stfd      f31, 0xD8(r1)
	  stfd      f30, 0xD0(r1)
	  stfd      f29, 0xC8(r1)
	  stfd      f28, 0xC0(r1)
	  stfd      f27, 0xB8(r1)
	  stw       r31, 0xB4(r1)
	  mr        r31, r3
	  stw       r30, 0xB0(r1)
	  stw       r29, 0xAC(r1)
	  stw       r28, 0xA8(r1)
	  lwz       r0, 0xABC(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x70
	  bge-      .loc_0x98
	  cmpwi     r0, 0
	  bge-      .loc_0x50
	  b         .loc_0x98

	.loc_0x50:
	  lwz       r3, 0x224(r31)
	  lfs       f1, 0xAC0(r31)
	  lfs       f0, 0x98(r3)
	  lfs       f2, 0xA8(r3)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f31, f2, f0
	  b         .loc_0xB4

	.loc_0x70:
	  lwz       r4, 0x224(r31)
	  lfs       f2, 0xAB8(r31)
	  lfs       f1, 0xB8(r4)
	  lfs       f0, 0x98(r4)
	  fdivs     f1, f2, f1
	  lfs       f3, 0xA8(r4)
	  fsubs     f0, f0, f3
	  fmuls     f0, f1, f0
	  fadds     f31, f3, f0
	  b         .loc_0xB4

	.loc_0x98:
	  lwz       r3, 0x224(r31)
	  lfs       f1, 0xAC0(r31)
	  lfs       f0, 0x98(r3)
	  lfs       f2, 0xA8(r3)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f31, f2, f0

	.loc_0xB4:
	  stfs      f31, 0xAC8(r31)
	  lbz       r0, 0x30B8(r13)
	  extsb.    r0, r0
	  bne-      .loc_0xD4
	  lfs       f0, -0x63A0(r2)
	  li        r0, 0x1
	  stb       r0, 0x30B8(r13)
	  stfs      f0, 0x30B4(r13)

	.loc_0xD4:
	  lfs       f2, -0x6284(r2)
	  lfs       f1, 0x30B4(r13)
	  lfs       f0, -0x6280(r2)
	  fadds     f1, f2, f1
	  stfs      f1, 0x30B4(r13)
	  lfs       f1, 0x30B4(r13)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xFC
	  fsubs     f0, f1, f0
	  stfs      f0, 0x30B4(r13)

	.loc_0xFC:
	  lfs       f29, -0x627C(r2)
	  mr        r29, r31
	  lfd       f30, -0x62E8(r2)
	  li        r28, 0
	  lis       r30, 0x4330

	.loc_0x110:
	  xoris     r0, r28, 0x8000
	  lfs       f0, 0x30B4(r13)
	  stw       r0, 0xA4(r1)
	  stw       r30, 0xA0(r1)
	  lfd       f1, 0xA0(r1)
	  fsubs     f1, f1, f30
	  fmuls     f27, f29, f1
	  fadds     f27, f27, f0
	  fmr       f1, f27
	  bl        0x11C474
	  fmuls     f28, f31, f1
	  fmr       f1, f27
	  bl        0x11C5FC
	  lfs       f0, 0x6F0(r31)
	  fmuls     f1, f31, f1
	  li        r4, 0x1
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0x6F4(r31)
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0x6F8(r31)
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x88(r1)
	  lfs       f3, 0x90(r1)
	  fadds     f0, f0, f1
	  lfs       f2, 0x8C(r1)
	  lfs       f1, -0x2B60(r13)
	  fadds     f3, f3, f28
	  fadds     f1, f2, f1
	  stfs      f0, 0x88(r1)
	  stfs      f1, 0x8C(r1)
	  stfs      f3, 0x90(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x88(r1)
	  lfs       f2, 0x90(r1)
	  bl        -0x97840
	  stfs      f1, 0x8C(r1)
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x18
	  lwz       r3, 0x88(r1)
	  lwz       r0, 0x8C(r1)
	  stw       r3, 0x938(r29)
	  stw       r0, 0x93C(r29)
	  lwz       r0, 0x90(r1)
	  stw       r0, 0x940(r29)
	  addi      r29, r29, 0xC
	  blt+      .loc_0x110
	  lwz       r0, 0xE4(r1)
	  lfd       f31, 0xD8(r1)
	  lfd       f30, 0xD0(r1)
	  lfd       f29, 0xC8(r1)
	  lfd       f28, 0xC0(r1)
	  lfd       f27, 0xB8(r1)
	  lwz       r31, 0xB4(r1)
	  lwz       r30, 0xB0(r1)
	  lwz       r29, 0xAC(r1)
	  lwz       r28, 0xA8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FF7A8
 * Size:	000004
 */
void Navi::refresh2d(Graphics&) { }

/*
 * --INFO--
 * Address:	800FF7AC
 * Size:	00003C
 */
void Navi::sendMsg(Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r6, r3
	  stw       r0, 0x4(r1)
	  addi      r5, r4, 0
	  addi      r4, r6, 0
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x320(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FF7E8
 * Size:	00003C
 */
void StateMachine<Navi>::procMsg(Navi*, Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0xADC(r4)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x2C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
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
 * Address:	800FF824
 * Size:	000118
 */
void Receiver<Navi>::procMsg(Navi*, Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x0(r5)
	  cmplwi    r0, 0xA
	  bgt-      .loc_0x108
	  lis       r6, 0x802C
	  addi      r6, r6, 0xD8
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r6, r0
	  mtctr     r0
	  bctr
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x108:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FF93C
 * Size:	000004
 */
void Receiver<Navi>::procGroundMsg(Navi*, MsgGround*) { }

/*
 * --INFO--
 * Address:	800FF940
 * Size:	000004
 */
void Receiver<Navi>::procUserMsg(Navi*, MsgUser*) { }

/*
 * --INFO--
 * Address:	800FF944
 * Size:	000004
 */
void Receiver<Navi>::procOffWallMsg(Navi*, MsgOffWall*) { }

/*
 * --INFO--
 * Address:	800FF948
 * Size:	000004
 */
void Receiver<Navi>::procWallMsg(Navi*, MsgWall*) { }

/*
 * --INFO--
 * Address:	800FF94C
 * Size:	000004
 */
void Receiver<Navi>::procDamageMsg(Navi*, MsgDamage*) { }

/*
 * --INFO--
 * Address:	800FF950
 * Size:	000004
 */
void Receiver<Navi>::procAnimMsg(Navi*, MsgAnim*) { }

/*
 * --INFO--
 * Address:	800FF954
 * Size:	000004
 */
void Receiver<Navi>::procCollideMsg(Navi*, MsgCollide*) { }

/*
 * --INFO--
 * Address:	800FF958
 * Size:	000004
 */
void Receiver<Navi>::procTargetMsg(Navi*, MsgTarget*) { }

/*
 * --INFO--
 * Address:	800FF95C
 * Size:	000004
 */
void Receiver<Navi>::procHangMsg(Navi*, MsgHang*) { }

/*
 * --INFO--
 * Address:	800FF960
 * Size:	000004
 */
void Receiver<Navi>::procStickMsg(Navi*, MsgStick*) { }

/*
 * --INFO--
 * Address:	800FF964
 * Size:	000004
 */
void Receiver<Navi>::procBounceMsg(Navi*, MsgBounce*) { }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void Navi::procDamage(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800FF968
 * Size:	000074
 */
void Navi::stimulate(Interaction&)
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
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x58
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5C

	.loc_0x58:
	  li        r3, 0

	.loc_0x5C:
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
 * Address:	800FF9DC
 * Size:	0000C4
 */
bool InteractGeyzer::actNavi(Navi*)
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
	  lbz       r0, 0x2B4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  li        r3, 0
	  b         .loc_0xAC

	.loc_0x30:
	  lwz       r3, 0xADC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  lwz       r0, 0x4(r3)
	  b         .loc_0x48

	.loc_0x44:
	  li        r0, -0x1

	.loc_0x48:
	  cmpwi     r0, 0x14
	  bne-      .loc_0x58
	  li        r3, 0
	  b         .loc_0xAC

	.loc_0x58:
	  cmpwi     r0, 0x18
	  bne-      .loc_0x68
	  li        r3, 0
	  b         .loc_0xAC

	.loc_0x68:
	  lwz       r3, 0x320(r31)
	  addi      r4, r31, 0
	  li        r5, 0x14
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0x16D8
	  lwz       r4, 0x8(r30)
	  lwz       r0, 0xC(r30)
	  stw       r4, 0x20(r3)
	  stw       r0, 0x24(r3)
	  lwz       r0, 0x10(r30)
	  stw       r0, 0x28(r3)
	  li        r3, 0x1

	.loc_0xAC:
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
 * Address:	800FFAA0
 * Size:	0000FC
 */
bool InteractBury::actNavi(Navi*)
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
	  lwz       r3, 0x320(r4)
	  bl        0x1680
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x48
	  li        r3, 0
	  b         .loc_0xE4

	.loc_0x48:
	  lwz       r3, 0x320(r31)
	  addi      r4, r31, 0
	  li        r5, 0x13
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7D234
	  lfs       f1, 0x58(r31)
	  mr        r3, r31
	  lfs       f0, 0xC(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  bl        -0x62F8
	  lwz       r4, 0x224(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA3ACC
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xE0
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  addi      r4, r31, 0
	  li        r5, 0x1D
	  lwz       r3, 0x320(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0xE0:
	  li        r3, 0x1

	.loc_0xE4:
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
 * Address:	800FFB9C
 * Size:	000094
 */
bool InteractWind::actNavi(Navi*)
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
	  lwz       r3, 0x320(r4)
	  bl        0x1584
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x7C

	.loc_0x48:
	  lwz       r4, 0xC(r30)
	  li        r3, 0x1
	  lwz       r0, 0x10(r30)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x14(r30)
	  stw       r0, 0x78(r31)
	  lwz       r4, 0xC(r30)
	  lwz       r0, 0x10(r30)
	  stw       r4, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x14(r30)
	  stw       r0, 0xAC(r31)

	.loc_0x7C:
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
 * Address:	800FFC30
 * Size:	000114
 */
bool InteractSuck::actNavi(Navi*)
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
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x40
	  li        r3, 0
	  b         .loc_0xFC

	.loc_0x40:
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0x14C8
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0x14BC
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7C
	  li        r3, 0
	  b         .loc_0xFC

	.loc_0x7C:
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA3C58
	  lwz       r3, 0x3178(r13)
	  li        r4, 0xF
	  li        r5, 0
	  li        r6, 0
	  bl        0x7D068
	  mr        r3, r31
	  bl        -0x64B4
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xF8
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  addi      r4, r31, 0
	  li        r5, 0x1D
	  lwz       r3, 0x320(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0xF8:
	  li        r3, 0x1

	.loc_0xFC:
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
 * Address:	800FFD44
 * Size:	0001A4
 */
bool InteractAttack::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r4
	  stw       r30, 0x58(r1)
	  addi      r30, r3, 0
	  lbz       r0, 0x2B4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x18C

	.loc_0x30:
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0x13C4
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x60
	  li        r0, 0
	  b         .loc_0x94

	.loc_0x60:
	  mr        r3, r31
	  bl        -0x6574
	  li        r0, 0x1
	  stb       r0, 0x2B4(r31)
	  lwz       r3, 0xADC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x90
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl

	.loc_0x90:
	  li        r0, 0x1

	.loc_0x94:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0xA4
	  li        r3, 0
	  b         .loc_0x18C

	.loc_0xA4:
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7CF50
	  li        r3, 0x13D
	  bl        -0x5AA24
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA3DB0
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x108
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  b         .loc_0x148

	.loc_0x108:
	  addi      r3, r1, 0x44
	  li        r4, 0xA
	  bl        0x1F104
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x124
	  addi      r5, r5, 0x2B8

	.loc_0x124:
	  addi      r3, r1, 0x4C
	  li        r4, 0xA
	  bl        0x1F11C
	  addi      r3, r31, 0x834
	  addi      r4, r1, 0x4C
	  addi      r5, r1, 0x44
	  bl        0x1FBE8
	  li        r0, -0x1
	  stw       r0, 0x7E0(r31)

	.loc_0x148:
	  addi      r3, r1, 0x34
	  li        r4, 0xA
	  bl        0x1F0C4
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x164
	  addi      r5, r5, 0x2B8

	.loc_0x164:
	  addi      r3, r1, 0x3C
	  li        r4, 0xA
	  bl        0x1F0DC
	  addi      r3, r31, 0x834
	  addi      r4, r1, 0x3C
	  addi      r5, r1, 0x34
	  bl        0x1FBA8
	  li        r0, -0x1
	  stw       r0, 0x7E0(r31)
	  li        r3, 0x1

	.loc_0x18C:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FFEE8
 * Size:	000110
 */
bool InteractPress::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lbz       r0, 0x2B4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  li        r3, 0
	  b         .loc_0xF8

	.loc_0x30:
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0x1220
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x60
	  li        r3, 0
	  b         .loc_0xF8

	.loc_0x60:
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7CDF0
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA3F08
	  lfs       f0, -0x2B5C(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x2B58(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x2B54(r13)
	  stfs      f0, 0xAC(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xD0
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)

	.loc_0xD0:
	  mr        r3, r31
	  bl        -0x6788
	  lwz       r3, 0x320(r31)
	  addi      r4, r31, 0
	  li        r5, 0x7
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1

	.loc_0xF8:
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
 * Address:	800FFFF8
 * Size:	0001B8
 */
bool InteractSwallow::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r4
	  lwz       r3, 0x320(r4)
	  bl        0x1130
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x40
	  li        r0, 0
	  b         .loc_0x74

	.loc_0x40:
	  mr        r3, r31
	  bl        -0x6808
	  li        r0, 0x1
	  stb       r0, 0x2B4(r31)
	  lwz       r3, 0xADC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl

	.loc_0x70:
	  li        r0, 0x1

	.loc_0x74:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x84
	  li        r3, 0
	  b         .loc_0x1A4

	.loc_0x84:
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0x10BC
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB4
	  li        r3, 0
	  b         .loc_0x1A4

	.loc_0xB4:
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7CC8C
	  lfs       f1, 0x58(r31)
	  li        r3, 0x13D
	  lfs       f0, -0x63A4(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  bl        -0x5ACF8
	  mr        r3, r31
	  bl        -0x68A8
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x10C
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  b         .loc_0x14C

	.loc_0x10C:
	  addi      r3, r1, 0x44
	  li        r4, 0xA
	  bl        0x1EE4C
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x128
	  addi      r5, r5, 0x2B8

	.loc_0x128:
	  addi      r3, r1, 0x4C
	  li        r4, 0xA
	  bl        0x1EE64
	  addi      r3, r31, 0x834
	  addi      r4, r1, 0x4C
	  addi      r5, r1, 0x44
	  bl        0x1F930
	  li        r0, -0x1
	  stw       r0, 0x7E0(r31)

	.loc_0x14C:
	  addi      r3, r1, 0x34
	  li        r4, 0xA
	  bl        0x1EE0C
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x168
	  addi      r5, r5, 0x2B8

	.loc_0x168:
	  addi      r3, r1, 0x3C
	  li        r4, 0xA
	  bl        0x1EE24
	  addi      r3, r31, 0x834
	  addi      r4, r1, 0x3C
	  addi      r5, r1, 0x34
	  bl        0x1F8F0
	  li        r0, -0x1
	  stw       r0, 0x7E0(r31)
	  addi      r3, r31, 0x1E0
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA4120
	  li        r3, 0x1

	.loc_0x1A4:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801001B0
 * Size:	000118
 */
bool InteractBomb::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x30(r1)
	  addi      r30, r3, 0
	  lwz       r3, 0x320(r4)
	  bl        0xF70
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x100

	.loc_0x48:
	  lwz       r3, 0xADC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  lwz       r0, 0x4(r3)
	  b         .loc_0x60

	.loc_0x5C:
	  li        r0, -0x1

	.loc_0x60:
	  cmpwi     r0, 0x21
	  bne-      .loc_0x70
	  li        r3, 0
	  b         .loc_0x100

	.loc_0x70:
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7CB18
	  li        r3, 0x13D
	  bl        -0x5AE5C
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA41E8
	  mr        r3, r31
	  bl        -0x6A30
	  lfs       f0, -0x6368(r2)
	  stfs      f0, 0x704(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xE0
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)

	.loc_0xE0:
	  lwz       r3, 0x320(r31)
	  addi      r4, r31, 0
	  li        r5, 0x8
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1

	.loc_0x100:
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
 * Address:	801002C8
 * Size:	000080
 */
void Navi::orimaDamaged()
{
	/*
	.loc_0x0:
	  lwz       r4, 0xADC(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x14
	  lwz       r4, 0x4(r4)
	  b         .loc_0x18

	.loc_0x14:
	  li        r4, -0x1

	.loc_0x18:
	  lbz       r0, 0x2B4(r3)
	  li        r3, 0x1
	  addi      r5, r3, 0
	  cmplwi    r0, 0
	  addi      r6, r3, 0
	  addi      r0, r3, 0
	  bne-      .loc_0x40
	  cmpwi     r4, 0x8
	  beq-      .loc_0x40
	  li        r0, 0

	.loc_0x40:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x54
	  cmpwi     r4, 0x7
	  beq-      .loc_0x54
	  li        r6, 0

	.loc_0x54:
	  rlwinm.   r0,r6,0,24,31
	  bne-      .loc_0x68
	  cmpwi     r4, 0x12
	  beq-      .loc_0x68
	  li        r5, 0

	.loc_0x68:
	  rlwinm.   r0,r5,0,24,31
	  bnelr-
	  cmpwi     r4, 0x13
	  beqlr-
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80100348
 * Size:	000144
 */
bool InteractFlick::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r4
	  stw       r30, 0x30(r1)
	  addi      r30, r3, 0
	  lwz       r4, 0xADC(r4)
	  cmplwi    r4, 0
	  beq-      .loc_0x30
	  lwz       r0, 0x4(r4)
	  b         .loc_0x34

	.loc_0x30:
	  li        r0, -0x1

	.loc_0x34:
	  cmpwi     r0, 0x21
	  bne-      .loc_0x44
	  li        r3, 0
	  b         .loc_0x12C

	.loc_0x44:
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0xDAC
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  li        r3, 0
	  b         .loc_0x12C

	.loc_0x74:
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x63A0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xA4
	  lwz       r3, 0x3178(r13)
	  li        r4, 0xA
	  li        r5, 0
	  li        r6, 0
	  bl        0x7C96C
	  mr        r3, r31
	  bl        -0x6BB0
	  b         .loc_0xB8

	.loc_0xA4:
	  lwz       r3, 0x3178(r13)
	  li        r4, 0xA
	  li        r5, 0
	  li        r6, 0
	  bl        0x7C94C

	.loc_0xB8:
	  li        r3, 0x13D
	  bl        -0x5B028
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0xC(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA43B4
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x704(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x10C
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)

	.loc_0x10C:
	  lwz       r3, 0x320(r31)
	  addi      r4, r31, 0
	  li        r5, 0x8
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1

	.loc_0x12C:
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
 * Address:	8010048C
 * Size:	0000F0
 */
bool InteractBubble::actNavi(Navi*)
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
	  lwz       r3, 0x320(r4)
	  bl        0xC94
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x48
	  li        r3, 0
	  b         .loc_0xD8

	.loc_0x48:
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA4480
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7C840
	  li        r3, 0x13E
	  bl        -0x5B134
	  mr        r3, r31
	  bl        -0x6CE4
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xB0
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)

	.loc_0xB0:
	  lfs       f0, -0x6314(r2)
	  addi      r4, r31, 0
	  li        r5, 0x8
	  stfs      f0, 0x704(r31)
	  lwz       r3, 0x320(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1

	.loc_0xD8:
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
 * Address:	8010057C
 * Size:	0000F0
 */
bool InteractFire::actNavi(Navi*)
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
	  lwz       r3, 0x320(r4)
	  bl        0xBA4
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x48
	  li        r3, 0
	  b         .loc_0xD8

	.loc_0x48:
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA4570
	  mr        r3, r31
	  bl        -0x6DB8
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7C748
	  li        r3, 0x13E
	  bl        -0x5B22C
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xB0
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)

	.loc_0xB0:
	  lfs       f0, -0x6314(r2)
	  addi      r4, r31, 0
	  li        r5, 0x8
	  stfs      f0, 0x704(r31)
	  lwz       r3, 0x320(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1

	.loc_0xD8:
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
 * Address:	8010066C
 * Size:	0000C0
 */
void Navi::dump()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r3, 0
	  lbz       r0, 0x3060(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x68
	  lwz       r0, 0xADC(r31)
	  cmplwi    r0, 0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xAC

	.loc_0x68:
	  lwz       r0, 0xADC(r31)
	  cmplwi    r0, 0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl

	.loc_0xAC:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010072C
 * Size:	000234
 */
void Navi::throwPiki(Piki*, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x130(r1)
	  stfd      f31, 0x128(r1)
	  stfd      f30, 0x120(r1)
	  stfd      f29, 0x118(r1)
	  stfd      f28, 0x110(r1)
	  stw       r31, 0x10C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x108(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x104(r1)
	  addi      r29, r3, 0
	  lwz       r3, 0x4F8(r4)
	  li        r4, 0
	  bl        -0x3B424
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x2
	  li        r5, 0
	  li        r6, 0
	  bl        0x7C5CC
	  lfs       f2, 0x94(r29)
	  lfs       f0, -0x2B50(r13)
	  lfs       f1, -0x2B4C(r13)
	  fadds     f2, f2, f0
	  lfs       f0, -0x2B48(r13)
	  stfs      f2, 0xAC(r1)
	  lfs       f2, 0xAC(r1)
	  stfs      f2, 0xDC(r1)
	  lfs       f2, 0x98(r29)
	  fadds     f1, f2, f1
	  stfs      f1, 0xE0(r1)
	  lfs       f1, 0x9C(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE4(r1)
	  lwz       r3, 0xDC(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r3, 0x94(r30)
	  stw       r0, 0x98(r30)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x9C(r30)
	  lfs       f1, 0x8(r31)
	  lfs       f0, 0x9C(r30)
	  lfs       f3, 0x0(r31)
	  fsubs     f2, f1, f0
	  lfs       f1, 0x94(r30)
	  lfs       f0, -0x63A0(r2)
	  fsubs     f1, f3, f1
	  fmuls     f3, f2, f2
	  fmuls     f4, f1, f1
	  fadds     f31, f4, f3
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0xE8
	  fsqrte    f0, f31
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f31, 0xA8(r1)

	.loc_0xE8:
	  bl        0x11B1E4
	  fmr       f30, f1
	  bl        -0xC8294
	  stfs      f1, 0xA0(r30)
	  lwz       r4, 0x224(r29)
	  lhz       r0, 0x510(r30)
	  lfs       f1, -0x6384(r2)
	  lfs       f0, 0x1B8(r4)
	  cmplwi    r0, 0x2
	  fmuls     f4, f1, f0
	  bne-      .loc_0x11C
	  lfs       f1, 0x1A8(r4)
	  b         .loc_0x13C

	.loc_0x11C:
	  lfs       f1, 0x800(r29)
	  lfs       f0, 0x158(r4)
	  lfs       f2, 0x198(r4)
	  fdivs     f1, f1, f0
	  lfs       f0, 0x188(r4)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f1, f2, f0

	.loc_0x13C:
	  lfs       f0, -0x6314(r2)
	  fdivs     f3, f1, f4
	  lwz       r3, 0x2F80(r13)
	  lfs       f2, -0x6384(r2)
	  lfs       f1, 0x30(r3)
	  fmuls     f0, f0, f4
	  fmuls     f2, f2, f1
	  fmr       f1, f30
	  fdivs     f28, f31, f0
	  fmuls     f0, f4, f2
	  fadds     f29, f3, f0
	  bl        0x11B2C0
	  fmuls     f31, f28, f1
	  fmr       f1, f30
	  bl        0x11B448
	  fmuls     f0, f28, f1
	  stfs      f0, 0x70(r30)
	  stfs      f29, 0x74(r30)
	  stfs      f31, 0x78(r30)
	  lfs       f1, 0x70(r30)
	  lfs       f0, 0x70(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x80(r1)
	  stfs      f0, 0xB8(r1)
	  lfs       f1, 0x74(r30)
	  lfs       f0, 0x74(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0xBC(r1)
	  lfs       f1, 0x78(r30)
	  lfs       f0, 0x78(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lwz       r3, 0xB8(r1)
	  lwz       r0, 0xBC(r1)
	  stw       r3, 0x70(r30)
	  stw       r0, 0x74(r30)
	  lwz       r0, 0xC0(r1)
	  stw       r0, 0x78(r30)
	  lwz       r3, 0x70(r30)
	  lwz       r0, 0x74(r30)
	  stw       r3, 0xA4(r30)
	  stw       r0, 0xA8(r30)
	  lwz       r0, 0x78(r30)
	  stw       r0, 0xAC(r30)
	  lfs       f0, -0x2B44(r13)
	  stfs      f0, 0xBC(r30)
	  lfs       f0, -0x2B40(r13)
	  stfs      f0, 0xC0(r30)
	  lfs       f0, -0x2B3C(r13)
	  stfs      f0, 0xC4(r30)
	  lwz       r0, 0x134(r1)
	  lfd       f31, 0x128(r1)
	  lfd       f30, 0x120(r1)
	  lfd       f29, 0x118(r1)
	  lfd       f28, 0x110(r1)
	  lwz       r31, 0x10C(r1)
	  lwz       r30, 0x108(r1)
	  lwz       r29, 0x104(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001DC
 */
void Navi::throwLocus(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80100960
 * Size:	00005C
 */
void Navi::swapMotion(PaniMotionInfo&, PaniMotionInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  stfd      f30, 0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0x864
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0x8B8
	  lfs       f31, 0x864(r3)
	  lfs       f30, 0x8B8(r3)
	  addi      r3, r3, 0x834
	  bl        0x1F0D8
	  stfs      f31, 0x0(r31)
	  stfs      f30, 0x0(r30)
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lfd       f30, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002D4
 */
void Navi::renderParabola(Graphics&, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801009BC
 * Size:	000014
 */
void Navi::finishLook()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  li        r0, 0xA
	  stb       r0, 0x2F0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801009D0
 * Size:	000340
 */
void Navi::updateLook()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stfd      f29, 0x58(r1)
	  stfd      f28, 0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r3
	  lwz       r3, 0x2EC(r3)
	  lfs       f29, -0x62A8(r2)
	  cmplwi    r3, 0
	  beq-      .loc_0xEC
	  lfs       f3, 0x8(r3)
	  lfs       f1, 0x9C(r31)
	  lfs       f2, 0x0(r3)
	  lfs       f0, 0x94(r31)
	  fsubs     f28, f3, f1
	  lfs       f1, 0x4(r3)
	  fsubs     f30, f2, f0
	  lfs       f0, 0x98(r31)
	  fmr       f2, f28
	  fsubs     f31, f1, f0
	  fmr       f1, f30
	  bl        0x11AFC8
	  fmuls     f3, f30, f30
	  lfs       f0, -0x63A0(r2)
	  fmuls     f2, f28, f28
	  fmr       f30, f1
	  fadds     f4, f3, f2
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xD8
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
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
	  stfs      f0, 0x28(r1)
	  lfs       f4, 0x28(r1)

	.loc_0xD8:
	  fmr       f2, f4
	  fmr       f1, f31
	  bl        0x11AF48
	  fmr       f31, f1
	  b         .loc_0x170

	.loc_0xEC:
	  lfs       f28, -0x6360(r2)
	  lfs       f1, -0x63A0(r2)
	  lfs       f2, 0x2F4(r31)
	  bl        -0xC8514
	  fmuls     f0, f1, f28
	  lfs       f1, 0x2F4(r31)
	  fadds     f1, f1, f0
	  bl        -0xC8550
	  stfs      f1, 0x2F4(r31)
	  lfs       f1, -0x63A0(r2)
	  lfs       f2, 0x2F8(r31)
	  bl        -0xC8534
	  fmuls     f0, f1, f28
	  lfs       f1, 0x2F8(r31)
	  fadds     f1, f1, f0
	  bl        -0xC8570
	  stfs      f1, 0x2F8(r31)
	  lfs       f1, 0x2F4(r31)
	  lfs       f0, -0x637C(r2)
	  fabs      f1, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x31C
	  lfs       f1, 0x2F8(r31)
	  fabs      f1, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x31C
	  li        r0, 0
	  stw       r0, 0x2EC(r31)
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x2F8(r31)
	  stfs      f0, 0x2F4(r31)
	  stb       r0, 0x2F0(r31)
	  b         .loc_0x31C

	.loc_0x170:
	  lfs       f1, 0x2F4(r31)
	  lfs       f0, 0xA0(r31)
	  fadds     f1, f1, f0
	  bl        -0xC85C4
	  fmr       f2, f1
	  lfs       f0, 0xA0(r31)
	  fsubs     f1, f30, f0
	  fmr       f28, f2
	  bl        -0xC85D8
	  lfs       f0, -0x6290(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1CC
	  lfs       f2, 0x2F4(r31)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x1BC
	  fsubs     f0, f2, f1
	  lfs       f1, -0x6280(r2)
	  fsubs     f1, f1, f0
	  b         .loc_0x200

	.loc_0x1BC:
	  fmr       f1, f30
	  fmr       f2, f28
	  bl        -0xC85E0
	  b         .loc_0x200

	.loc_0x1CC:
	  lfs       f2, 0x2F4(r31)
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x1F4
	  fsubs     f1, f2, f1
	  lfs       f2, -0x6280(r2)
	  lfs       f0, -0x62C4(r2)
	  fsubs     f1, f2, f1
	  fmuls     f1, f1, f0
	  b         .loc_0x200

	.loc_0x1F4:
	  fmr       f1, f30
	  fmr       f2, f28
	  bl        -0xC8618

	.loc_0x200:
	  fabs      f2, f1
	  lfs       f0, -0x6278(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x214
	  lfs       f1, -0x63A0(r2)

	.loc_0x214:
	  fmuls     f0, f1, f29
	  lfs       f1, 0x2F4(r31)
	  fadds     f1, f1, f0
	  bl        -0xC8668
	  stfs      f1, 0x2F4(r31)
	  lfs       f2, 0x2F4(r31)
	  lfs       f1, -0x62A4(r2)
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x24C
	  lfs       f0, -0x6290(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x24C
	  stfs      f1, 0x2F4(r31)
	  b         .loc_0x26C

	.loc_0x24C:
	  lfs       f1, -0x6274(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x26C
	  lfs       f0, -0x6290(r2)
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x26C
	  stfs      f1, 0x2F4(r31)

	.loc_0x26C:
	  fmr       f1, f31
	  lfs       f2, 0x2F8(r31)
	  bl        -0xC8690
	  fabs      f2, f1
	  lfs       f0, -0x6278(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x28C
	  lfs       f1, -0x63A0(r2)

	.loc_0x28C:
	  fmuls     f0, f1, f29
	  lfs       f1, 0x2F8(r31)
	  fadds     f1, f1, f0
	  bl        -0xC86E0
	  stfs      f1, 0x2F8(r31)
	  lfs       f2, 0x2F8(r31)
	  lfs       f1, -0x6270(r2)
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x2C4
	  lfs       f0, -0x6290(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x2C4
	  stfs      f1, 0x2F8(r31)
	  b         .loc_0x2E4

	.loc_0x2C4:
	  lfs       f1, -0x626C(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x2E4
	  lfs       f0, -0x6290(r2)
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2E4
	  stfs      f1, 0x2F8(r31)

	.loc_0x2E4:
	  lbz       r3, 0x2F0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x31C
	  subi      r0, r3, 0x1
	  stb       r0, 0x2F0(r31)
	  lbz       r0, 0x2F0(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x31C
	  li        r0, 0
	  stw       r0, 0x2EC(r31)
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x2F8(r31)
	  stfs      f0, 0x2F4(r31)
	  stb       r0, 0x2F0(r31)

	.loc_0x31C:
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lfd       f29, 0x58(r1)
	  lfd       f28, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80100D10
 * Size:	00037C
 */
void Navi::updateHeadMatrix()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F0(r1)
	  stfd      f31, 0x1E8(r1)
	  stfd      f30, 0x1E0(r1)
	  stfd      f29, 0x1D8(r1)
	  stw       r31, 0x1D4(r1)
	  stw       r30, 0x1D0(r1)
	  mr        r30, r3
	  lwz       r0, 0x2EC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x3C
	  lbz       r0, 0x2F0(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x358

	.loc_0x3C:
	  mr        r3, r30
	  bl        -0x380
	  lwz       r3, 0x82C(r30)
	  li        r4, 0x2
	  lwz       r3, 0x0(r3)
	  bl        -0xCBD78
	  lwz       r5, 0x0(r3)
	  addi      r4, r1, 0x14C
	  lwz       r0, 0x4(r3)
	  stw       r5, 0x18C(r1)
	  stw       r0, 0x190(r1)
	  lwz       r5, 0x8(r3)
	  lwz       r0, 0xC(r3)
	  stw       r5, 0x194(r1)
	  stw       r0, 0x198(r1)
	  lwz       r5, 0x10(r3)
	  lwz       r0, 0x14(r3)
	  stw       r5, 0x19C(r1)
	  stw       r0, 0x1A0(r1)
	  lwz       r5, 0x18(r3)
	  lwz       r0, 0x1C(r3)
	  stw       r5, 0x1A4(r1)
	  stw       r0, 0x1A8(r1)
	  lwz       r5, 0x20(r3)
	  lwz       r0, 0x24(r3)
	  stw       r5, 0x1AC(r1)
	  stw       r0, 0x1B0(r1)
	  lwz       r5, 0x28(r3)
	  lwz       r0, 0x2C(r3)
	  stw       r5, 0x1B4(r1)
	  stw       r0, 0x1B8(r1)
	  lwz       r5, 0x30(r3)
	  lwz       r0, 0x34(r3)
	  stw       r5, 0x1BC(r1)
	  stw       r0, 0x1C0(r1)
	  lwz       r5, 0x38(r3)
	  lwz       r0, 0x3C(r3)
	  addi      r3, r1, 0x18C
	  stw       r5, 0x1C4(r1)
	  stw       r0, 0x1C8(r1)
	  bl        -0xC29B0
	  addi      r3, r1, 0xCC
	  bl        -0xC3038
	  lfs       f0, 0x2F8(r30)
	  fneg      f1, f0
	  bl        0x11AEE8
	  lfs       f0, 0x2F8(r30)
	  fmr       f29, f1
	  fneg      f1, f0
	  bl        0x11AD44
	  fmr       f30, f1
	  lfs       f1, 0x2F4(r30)
	  bl        0x11AECC
	  fmr       f31, f1
	  lfs       f1, 0x2F4(r30)
	  bl        0x11AD2C
	  fneg      f2, f29
	  stfs      f30, 0xCC(r1)
	  lfs       f0, -0x63A0(r2)
	  fmuls     f5, f1, f29
	  fmuls     f4, f1, f30
	  stfs      f2, 0xD0(r1)
	  fneg      f3, f31
	  fmuls     f2, f31, f29
	  addi      r3, r1, 0x18C
	  stfs      f0, 0xD4(r1)
	  fmuls     f0, f31, f30
	  stfs      f5, 0xDC(r1)
	  addi      r4, r1, 0xCC
	  stfs      f4, 0xE0(r1)
	  addi      r5, r1, 0x10C
	  stfs      f3, 0xE4(r1)
	  stfs      f2, 0xEC(r1)
	  stfs      f0, 0xF0(r1)
	  stfs      f1, 0xF4(r1)
	  bl        -0xC2DA4
	  lwz       r3, 0x82C(r30)
	  li        r4, 0x2
	  lwz       r3, 0x0(r3)
	  bl        -0xCBEA0
	  lwz       r4, 0x10C(r1)
	  li        r31, 0x3
	  lwz       r0, 0x110(r1)
	  stw       r4, 0x0(r3)
	  stw       r0, 0x4(r3)
	  lwz       r4, 0x114(r1)
	  lwz       r0, 0x118(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r4, 0x11C(r1)
	  lwz       r0, 0x120(r1)
	  stw       r4, 0x10(r3)
	  stw       r0, 0x14(r3)
	  lwz       r4, 0x124(r1)
	  lwz       r0, 0x128(r1)
	  stw       r4, 0x18(r3)
	  stw       r0, 0x1C(r3)
	  lwz       r4, 0x12C(r1)
	  lwz       r0, 0x130(r1)
	  stw       r4, 0x20(r3)
	  stw       r0, 0x24(r3)
	  lwz       r4, 0x134(r1)
	  lwz       r0, 0x138(r1)
	  stw       r4, 0x28(r3)
	  stw       r0, 0x2C(r3)
	  lwz       r4, 0x13C(r1)
	  lwz       r0, 0x140(r1)
	  stw       r4, 0x30(r3)
	  stw       r0, 0x34(r3)
	  lwz       r4, 0x144(r1)
	  lwz       r0, 0x148(r1)
	  stw       r4, 0x38(r3)
	  stw       r0, 0x3C(r3)

	.loc_0x200:
	  lwz       r3, 0x82C(r30)
	  mr        r4, r31
	  lwz       r3, 0x0(r3)
	  bl        -0xCBF34
	  lwz       r6, 0x0(r3)
	  addi      r4, r1, 0x8C
	  lwz       r0, 0x4(r3)
	  addi      r5, r1, 0x4C
	  stw       r6, 0x8C(r1)
	  stw       r0, 0x90(r1)
	  lwz       r6, 0x8(r3)
	  lwz       r0, 0xC(r3)
	  stw       r6, 0x94(r1)
	  stw       r0, 0x98(r1)
	  lwz       r6, 0x10(r3)
	  lwz       r0, 0x14(r3)
	  stw       r6, 0x9C(r1)
	  stw       r0, 0xA0(r1)
	  lwz       r6, 0x18(r3)
	  lwz       r0, 0x1C(r3)
	  stw       r6, 0xA4(r1)
	  stw       r0, 0xA8(r1)
	  lwz       r6, 0x20(r3)
	  lwz       r0, 0x24(r3)
	  stw       r6, 0xAC(r1)
	  stw       r0, 0xB0(r1)
	  lwz       r6, 0x28(r3)
	  lwz       r0, 0x2C(r3)
	  stw       r6, 0xB4(r1)
	  stw       r0, 0xB8(r1)
	  lwz       r6, 0x30(r3)
	  lwz       r0, 0x34(r3)
	  stw       r6, 0xBC(r1)
	  stw       r0, 0xC0(r1)
	  lwz       r6, 0x38(r3)
	  lwz       r0, 0x3C(r3)
	  addi      r3, r1, 0x14C
	  stw       r6, 0xC4(r1)
	  stw       r0, 0xC8(r1)
	  bl        -0xC2ED8
	  addi      r3, r1, 0x10C
	  addi      r4, r1, 0x4C
	  addi      r5, r1, 0xC
	  bl        -0xC2EE8
	  lwz       r3, 0x82C(r30)
	  mr        r4, r31
	  lwz       r3, 0x0(r3)
	  bl        -0xCBFE4
	  lwz       r4, 0xC(r1)
	  addi      r31, r31, 0x1
	  lwz       r0, 0x10(r1)
	  cmpwi     r31, 0x6
	  stw       r4, 0x0(r3)
	  stw       r0, 0x4(r3)
	  lwz       r4, 0x14(r1)
	  lwz       r0, 0x18(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r4, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r4, 0x10(r3)
	  stw       r0, 0x14(r3)
	  lwz       r4, 0x24(r1)
	  lwz       r0, 0x28(r1)
	  stw       r4, 0x18(r3)
	  stw       r0, 0x1C(r3)
	  lwz       r4, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  stw       r4, 0x20(r3)
	  stw       r0, 0x24(r3)
	  lwz       r4, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  stw       r4, 0x28(r3)
	  stw       r0, 0x2C(r3)
	  lwz       r4, 0x3C(r1)
	  lwz       r0, 0x40(r1)
	  stw       r4, 0x30(r3)
	  stw       r0, 0x34(r3)
	  lwz       r4, 0x44(r1)
	  lwz       r0, 0x48(r1)
	  stw       r4, 0x38(r3)
	  stw       r0, 0x3C(r3)
	  ble+      .loc_0x200
	  lwz       r3, 0x82C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xCBA70

	.loc_0x358:
	  lwz       r0, 0x1F4(r1)
	  lfd       f31, 0x1E8(r1)
	  lfd       f30, 0x1E0(r1)
	  lfd       f29, 0x1D8(r1)
	  lwz       r31, 0x1D4(r1)
	  lwz       r30, 0x1D0(r1)
	  addi      r1, r1, 0x1F0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010108C
 * Size:	000024
 */
void NaviDrawer::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x20(r3)
	  bl        -0x1DC8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801010B0
 * Size:	000004
 */
void PelletView::viewInit() { }

/*
 * --INFO--
 * Address:	801010B4
 * Size:	000004
 */
void PelletView::viewStartExplodeMotion(f32) { }

/*
 * --INFO--
 * Address:	801010B8
 * Size:	000044
 */
void NaviProp::read(RandomAccessStream&)
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
	  bl        -0xA253C
	  addi      r3, r30, 0x58
	  addi      r4, r31, 0
	  bl        -0xA2548
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
 * Address:	801010FC
 * Size:	000008
 */
bool Navi::mayIstick() { return 0x0; }

/*
 * --INFO--
 * Address:	80101104
 * Size:	000008
 */
f32 Navi::getShadowSize()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x62E0(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010110C
 * Size:	000004
 */
void StateMachine<Navi>::init(Navi*) { }
