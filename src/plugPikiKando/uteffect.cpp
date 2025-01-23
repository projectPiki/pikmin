#include "UtEffect.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	80113164
 * Size:	000068
 */
SlimeEffect::SlimeEffect()
{
	/*
	.loc_0x0:
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
	  addi      r0, r5, 0x18
	  addi      r6, r4, 0x2CE0
	  stw       r0, 0x8(r3)
	  addi      r5, r6, 0xC
	  addi      r4, r6, 0x18
	  stw       r6, 0x0(r3)
	  li        r0, 0
	  stw       r5, 0x4(r3)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801131CC
 * Size:	00001C
 */
void SlimeEffect::stop()
{
	/*
	.loc_0x0:
	  lwz       r3, 0xC(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801131E8
 * Size:	00001C
 */
void SlimeEffect::restart()
{
	/*
	.loc_0x0:
	  lwz       r3, 0xC(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x10
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80113204
 * Size:	000090
 */
void SlimeEffect::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r0, 0x28(r4)
	  stw       r0, 0x10(r3)
	  lwz       r3, 0x10(r3)
	  lfsu      f0, 0x94(r3)
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x20(r1)
	  lwz       r0, 0xC(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x7C
	  cmplwi    r31, 0
	  addi      r7, r31, 0
	  beq-      .loc_0x54
	  addi      r7, r7, 0x4

	.loc_0x54:
	  lwz       r3, 0x3180(r13)
	  addi      r6, r31, 0
	  addi      r5, r1, 0x18
	  li        r4, 0x24
	  bl        0x898D0
	  stw       r3, 0xC(r31)
	  lwz       r4, 0x10(r31)
	  lwz       r3, 0xC(r31)
	  addi      r0, r4, 0x94
	  stw       r0, 0x18(r3)

	.loc_0x7C:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80113294
 * Size:	00009C
 */
bool SlimeEffect::invoke(zen::particleGenerator*, zen::particleMdl*)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x58(r1)
	  lwz       r0, 0xC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x90
	  cmplwi    r5, 0
	  beq-      .loc_0x90
	  lwz       r3, 0x10(r3)
	  lfsu      f0, 0x70(r3)
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x50(r1)
	  lfs       f0, -0x60B0(r2)
	  stfs      f0, 0x4C(r1)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x48(r1)
	  lfs       f2, 0x28C(r3)
	  lfs       f1, 0x4C(r1)
	  fmuls     f0, f0, f2
	  lfs       f4, -0x24C0(r13)
	  fmuls     f3, f1, f2
	  lfs       f1, 0x50(r1)
	  fmuls     f0, f0, f4
	  fmuls     f2, f1, f2
	  fmuls     f1, f3, f4
	  stfs      f0, 0x48(r1)
	  fmuls     f0, f2, f4
	  stfs      f1, 0x4C(r1)
	  stfs      f0, 0x50(r1)
	  lwz       r3, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  stw       r3, 0x34(r5)
	  stw       r0, 0x38(r5)
	  lwz       r0, 0x50(r1)
	  stw       r0, 0x3C(r5)

	.loc_0x90:
	  li        r3, 0x1
	  addi      r1, r1, 0x58
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80113330
 * Size:	00004C
 */
void SlimeEffect::kill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r4, 0xC(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x38
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8E268
	  li        r0, 0
	  stw       r0, 0xC(r31)

	.loc_0x38:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011337C
 * Size:	000F54
 */
UtEffectMgr::UtEffectMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  li        r3, 0x70
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  bl        -0xCC398
	  stw       r3, 0x3114(r13)
	  li        r3, 0xC
	  bl        -0xCC3A4
	  mr.       r5, r3
	  beq-      .loc_0x94
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
	  addi      r7, r4, 0x5AC
	  stw       r7, 0x0(r3)
	  addi      r0, r7, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r6, r4, 0x2C74
	  addi      r0, r7, 0x18
	  stw       r0, 0x8(r3)
	  addi      r4, r6, 0xC
	  addi      r0, r6, 0x18
	  stw       r6, 0x0(r3)
	  stw       r4, 0x4(r3)
	  stw       r0, 0x8(r3)

	.loc_0x94:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        .loc_0xF54
	  li        r3, 0x1C
	  bl        -0xCC41C
	  mr.       r29, r3
	  beq-      .loc_0x12C
	  lwz       r3, 0x3120(r13)
	  li        r4, 0
	  bl        0x4004
	  lis       r4, 0x802B
	  addi      r0, r4, 0x600
	  lis       r4, 0x802B
	  stw       r0, 0x0(r29)
	  addi      r0, r4, 0x5F4
	  lis       r4, 0x802B
	  stw       r0, 0x4(r29)
	  addi      r0, r4, 0x5E8
	  lis       r4, 0x802B
	  stw       r0, 0x8(r29)
	  addi      r5, r4, 0x5AC
	  stw       r5, 0x0(r29)
	  addi      r0, r5, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r29)
	  addi      r6, r4, 0x2C08
	  addi      r0, r5, 0x18
	  stw       r0, 0x8(r29)
	  addi      r5, r6, 0xC
	  addi      r4, r6, 0x18
	  stw       r6, 0x0(r29)
	  li        r0, 0
	  stw       r5, 0x4(r29)
	  stw       r4, 0x8(r29)
	  stw       r3, 0xC(r29)
	  stw       r0, 0x18(r29)
	  stw       r0, 0x14(r29)
	  stw       r0, 0x10(r29)

	.loc_0x12C:
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0x1
	  bl        .loc_0xF54
	  li        r3, 0x1C
	  bl        -0xCC4B8
	  mr.       r29, r3
	  beq-      .loc_0x1C8
	  lwz       r3, 0x3120(r13)
	  li        r4, 0x1
	  bl        0x3F68
	  lis       r4, 0x802B
	  addi      r0, r4, 0x600
	  lis       r4, 0x802B
	  stw       r0, 0x0(r29)
	  addi      r0, r4, 0x5F4
	  lis       r4, 0x802B
	  stw       r0, 0x4(r29)
	  addi      r0, r4, 0x5E8
	  lis       r4, 0x802B
	  stw       r0, 0x8(r29)
	  addi      r5, r4, 0x5AC
	  stw       r5, 0x0(r29)
	  addi      r0, r5, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r29)
	  addi      r6, r4, 0x2C08
	  addi      r0, r5, 0x18
	  stw       r0, 0x8(r29)
	  addi      r5, r6, 0xC
	  addi      r4, r6, 0x18
	  stw       r6, 0x0(r29)
	  li        r0, 0
	  stw       r5, 0x4(r29)
	  stw       r4, 0x8(r29)
	  stw       r3, 0xC(r29)
	  stw       r0, 0x18(r29)
	  stw       r0, 0x14(r29)
	  stw       r0, 0x10(r29)

	.loc_0x1C8:
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0x2
	  bl        .loc_0xF54
	  li        r3, 0xC
	  bl        -0xCC554
	  mr.       r5, r3
	  beq-      .loc_0x244
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
	  addi      r7, r4, 0x5AC
	  stw       r7, 0x0(r3)
	  addi      r0, r7, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r6, r4, 0x2B9C
	  addi      r0, r7, 0x18
	  stw       r0, 0x8(r3)
	  addi      r4, r6, 0xC
	  addi      r0, r6, 0x18
	  stw       r6, 0x0(r3)
	  stw       r4, 0x4(r3)
	  stw       r0, 0x8(r3)

	.loc_0x244:
	  addi      r3, r31, 0
	  li        r4, 0x3
	  bl        .loc_0xF54
	  li        r3, 0xC
	  bl        -0xCC5CC
	  mr.       r5, r3
	  beq-      .loc_0x2BC
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
	  addi      r7, r4, 0x5AC
	  stw       r7, 0x0(r3)
	  addi      r0, r7, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r6, r4, 0x2B2C
	  addi      r0, r7, 0x18
	  stw       r0, 0x8(r3)
	  addi      r4, r6, 0xC
	  addi      r0, r6, 0x18
	  stw       r6, 0x0(r3)
	  stw       r4, 0x4(r3)
	  stw       r0, 0x8(r3)

	.loc_0x2BC:
	  addi      r3, r31, 0
	  li        r4, 0x5
	  bl        .loc_0xF54
	  li        r3, 0xC
	  bl        -0xCC644
	  mr.       r5, r3
	  beq-      .loc_0x334
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
	  addi      r7, r4, 0x5AC
	  stw       r7, 0x0(r3)
	  addi      r0, r7, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r6, r4, 0x2AB8
	  addi      r0, r7, 0x18
	  stw       r0, 0x8(r3)
	  addi      r4, r6, 0xC
	  addi      r0, r6, 0x18
	  stw       r6, 0x0(r3)
	  stw       r4, 0x4(r3)
	  stw       r0, 0x8(r3)

	.loc_0x334:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        .loc_0xF54
	  li        r3, 0xC
	  bl        -0xCC6BC
	  mr.       r5, r3
	  beq-      .loc_0x3AC
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
	  addi      r7, r4, 0x5AC
	  stw       r7, 0x0(r3)
	  addi      r0, r7, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r6, r4, 0x2A48
	  addi      r0, r7, 0x18
	  stw       r0, 0x8(r3)
	  addi      r4, r6, 0xC
	  addi      r0, r6, 0x18
	  stw       r6, 0x0(r3)
	  stw       r4, 0x4(r3)
	  stw       r0, 0x8(r3)

	.loc_0x3AC:
	  addi      r3, r31, 0
	  li        r4, 0x6
	  bl        .loc_0xF54
	  li        r3, 0x18
	  bl        -0xCC734
	  mr.       r30, r3
	  beq-      .loc_0x484
	  lwz       r3, 0x3120(r13)
	  li        r4, 0
	  bl        0x3CEC
	  lis       r4, 0x802B
	  addi      r0, r4, 0x600
	  lis       r4, 0x802B
	  stw       r0, 0x0(r30)
	  addi      r0, r4, 0x5F4
	  lis       r4, 0x802B
	  stw       r0, 0x4(r30)
	  addi      r0, r4, 0x5E8
	  lis       r4, 0x802B
	  stw       r0, 0x8(r30)
	  addi      r5, r4, 0x5AC
	  stw       r5, 0x0(r30)
	  addi      r0, r5, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r30)
	  addi      r0, r5, 0x18
	  addi      r6, r4, 0x29D8
	  stw       r0, 0x8(r30)
	  addi      r5, r6, 0xC
	  addi      r4, r6, 0x18
	  stw       r6, 0x0(r30)
	  addi      r29, r3, 0
	  li        r0, 0x18
	  stw       r5, 0x4(r30)
	  stw       r4, 0x8(r30)
	  stw       r29, 0xC(r30)
	  stw       r0, 0x10(r30)
	  lwz       r0, 0x10(r30)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xCC7C0
	  cmplwi    r29, 0
	  stw       r3, 0x14(r30)
	  beq-      .loc_0x484
	  li        r5, 0
	  addi      r6, r5, 0
	  addi      r4, r5, 0
	  b         .loc_0x478

	.loc_0x468:
	  lwz       r3, 0x14(r30)
	  addi      r5, r5, 0x1
	  stwx      r4, r3, r6
	  addi      r6, r6, 0x4

	.loc_0x478:
	  lwz       r0, 0x10(r30)
	  cmpw      r5, r0
	  blt+      .loc_0x468

	.loc_0x484:
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  li        r4, 0x7
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCC810
	  mr.       r5, r3
	  beq-      .loc_0x510
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0x2D
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x510:
	  addi      r3, r31, 0
	  li        r4, 0x9
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCC898
	  mr.       r5, r3
	  beq-      .loc_0x598
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0x2E
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x598:
	  addi      r3, r31, 0
	  li        r4, 0xA
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCC920
	  mr.       r5, r3
	  beq-      .loc_0x620
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0xDE
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x620:
	  addi      r3, r31, 0
	  li        r4, 0xB
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCC9A8
	  mr.       r5, r3
	  beq-      .loc_0x6A8
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0xDF
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x6A8:
	  addi      r3, r31, 0
	  li        r4, 0xC
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCCA30
	  mr.       r5, r3
	  beq-      .loc_0x730
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0xD2
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x730:
	  addi      r3, r31, 0
	  li        r4, 0xD
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCCAB8
	  mr.       r5, r3
	  beq-      .loc_0x7B8
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0xD1
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x7B8:
	  addi      r3, r31, 0
	  li        r4, 0xE
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCCB40
	  mr.       r5, r3
	  beq-      .loc_0x840
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0xDD
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x840:
	  addi      r3, r31, 0
	  li        r4, 0xF
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCCBC8
	  mr.       r5, r3
	  beq-      .loc_0x8C8
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0xDC
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x8C8:
	  addi      r3, r31, 0
	  li        r4, 0x10
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCCC50
	  mr.       r5, r3
	  beq-      .loc_0x950
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0xF
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x950:
	  addi      r3, r31, 0
	  li        r4, 0x11
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCCCD8
	  mr.       r5, r3
	  beq-      .loc_0x9D8
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0xE
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x9D8:
	  addi      r3, r31, 0
	  li        r4, 0x12
	  bl        .loc_0xF54
	  li        r3, 0xC
	  bl        -0xCCD60
	  mr.       r5, r3
	  beq-      .loc_0xA50
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
	  addi      r7, r4, 0x5AC
	  stw       r7, 0x0(r3)
	  addi      r0, r7, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r6, r4, 0x2908
	  addi      r0, r7, 0x18
	  stw       r0, 0x8(r3)
	  addi      r4, r6, 0xC
	  addi      r0, r6, 0x18
	  stw       r6, 0x0(r3)
	  stw       r4, 0x4(r3)
	  stw       r0, 0x8(r3)

	.loc_0xA50:
	  addi      r3, r31, 0
	  li        r4, 0x13
	  bl        .loc_0xF54
	  li        r3, 0xC
	  bl        -0xCCDD8
	  mr.       r5, r3
	  beq-      .loc_0xAC8
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
	  addi      r7, r4, 0x5AC
	  stw       r7, 0x0(r3)
	  addi      r0, r7, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r6, r4, 0x289C
	  addi      r0, r7, 0x18
	  stw       r0, 0x8(r3)
	  addi      r4, r6, 0xC
	  addi      r0, r6, 0x18
	  stw       r6, 0x0(r3)
	  stw       r4, 0x4(r3)
	  stw       r0, 0x8(r3)

	.loc_0xAC8:
	  addi      r3, r31, 0
	  li        r4, 0x14
	  bl        .loc_0xF54
	  li        r3, 0x34
	  bl        -0xCCE50
	  mr.       r5, r3
	  beq-      .loc_0xB94
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r0, r6, 0x18
	  addi      r7, r4, 0x282C
	  stw       r0, 0x8(r3)
	  lis       r4, 0x802C
	  addi      r6, r4, 0x27F0
	  stw       r7, 0x0(r3)
	  addi      r4, r7, 0xC
	  addi      r0, r7, 0x18
	  stw       r4, 0x4(r3)
	  li        r9, 0
	  li        r8, 0x146
	  stw       r0, 0x8(r3)
	  li        r7, 0x147
	  addi      r4, r6, 0xC
	  lfs       f0, -0x60B0(r2)
	  addi      r0, r6, 0x18
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  stfs      f0, 0x18(r3)
	  stw       r9, 0x28(r3)
	  stw       r9, 0x24(r3)
	  stw       r8, 0x2C(r3)
	  stw       r7, 0x30(r3)
	  stw       r6, 0x0(r3)
	  stw       r4, 0x4(r3)
	  stw       r0, 0x8(r3)

	.loc_0xB94:
	  addi      r3, r31, 0
	  li        r4, 0x15
	  bl        .loc_0xF54
	  li        r3, 0x28
	  bl        -0xCCF1C
	  mr.       r5, r3
	  beq-      .loc_0xC30
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r0, r6, 0x18
	  addi      r7, r4, 0x2744
	  stw       r0, 0x8(r3)
	  addi      r6, r7, 0xC
	  addi      r4, r7, 0x18
	  stw       r7, 0x0(r3)
	  li        r0, 0
	  stw       r6, 0x4(r3)
	  stw       r4, 0x8(r3)
	  lfs       f0, -0x60B0(r2)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  stfs      f0, 0x18(r3)
	  stw       r0, 0x24(r3)

	.loc_0xC30:
	  addi      r3, r31, 0
	  li        r4, 0x16
	  bl        .loc_0xF54
	  li        r3, 0x34
	  bl        -0xCCFB8
	  mr.       r5, r3
	  beq-      .loc_0xCE0
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r0, r6, 0x18
	  addi      r4, r4, 0x282C
	  stw       r0, 0x8(r3)
	  addi      r0, r4, 0xC
	  addi      r7, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r6, 0
	  li        r4, 0x122
	  stw       r0, 0x4(r3)
	  li        r0, 0x123
	  stw       r7, 0x8(r3)
	  lfs       f0, -0x60B0(r2)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  stfs      f0, 0x18(r3)
	  stw       r6, 0x28(r3)
	  stw       r6, 0x24(r3)
	  stw       r4, 0x2C(r3)
	  stw       r0, 0x30(r3)

	.loc_0xCE0:
	  addi      r3, r31, 0
	  li        r4, 0x17
	  bl        .loc_0xF54
	  li        r3, 0x34
	  bl        -0xCD068
	  mr.       r5, r3
	  beq-      .loc_0xD90
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r0, r6, 0x18
	  addi      r4, r4, 0x282C
	  stw       r0, 0x8(r3)
	  addi      r0, r4, 0xC
	  addi      r7, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r6, 0
	  li        r4, 0x122
	  stw       r0, 0x4(r3)
	  li        r0, 0x123
	  stw       r7, 0x8(r3)
	  lfs       f0, -0x60B0(r2)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  stfs      f0, 0x18(r3)
	  stw       r6, 0x28(r3)
	  stw       r6, 0x24(r3)
	  stw       r4, 0x2C(r3)
	  stw       r0, 0x30(r3)

	.loc_0xD90:
	  addi      r3, r31, 0
	  li        r4, 0x18
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCD118
	  mr.       r5, r3
	  beq-      .loc_0xE18
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0x2A
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0xE18:
	  addi      r3, r31, 0
	  li        r4, 0x19
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCD1A0
	  mr.       r5, r3
	  beq-      .loc_0xEA0
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0x29
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0xEA0:
	  addi      r3, r31, 0
	  li        r4, 0x1A
	  bl        .loc_0xF54
	  li        r3, 0x14
	  bl        -0xCD228
	  mr.       r5, r3
	  beq-      .loc_0xF28
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
	  addi      r6, r4, 0x5AC
	  stw       r6, 0x0(r3)
	  addi      r0, r6, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x2978
	  addi      r0, r6, 0x18
	  stw       r0, 0x8(r3)
	  addi      r7, r4, 0xC
	  addi      r6, r4, 0x18
	  stw       r4, 0x0(r3)
	  li        r4, 0x28
	  li        r0, 0
	  stw       r7, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0xF28:
	  addi      r3, r31, 0
	  li        r4, 0x1B
	  bl        .loc_0xF54
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0xF54:
	*/
}

/*
 * --INFO--
 * Address:	801142D0
 * Size:	000010
 */
void UtEffectMgr::registerEffect(int, KEffect*)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x3114(r13)
	  rlwinm    r0,r4,2,0,29
	  stwx      r5, r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801142E0
 * Size:	000044
 */
void UtEffectMgr::cast(int, EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r3,2,0,29
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x3114(r13)
	  lwzx      r0, r5, r0
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x34
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114324
 * Size:	000044
 */
void UtEffectMgr::kill(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r3,2,0,29
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x3114(r13)
	  lwzx      r0, r4, r0
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x34
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114368
 * Size:	000034
 */
PermanentEffect::PermanentEffect()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x60B0(r2)
	  li        r0, 0
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x0(r3)
	  stw       r0, 0xC(r3)
	  lfs       f0, -0x2490(r13)
	  stfs      f0, 0x0(r3)
	  lfs       f0, -0x248C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x2488(r13)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011439C
 * Size:	00008C
 */
void PermanentEffect::init(Vector3f&, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r8, r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  lwz       r0, 0xC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x78
	  lwz       r3, 0x0(r4)
	  mr        r5, r31
	  lwz       r0, 0x4(r4)
	  li        r6, 0
	  li        r7, 0
	  stw       r3, 0x0(r31)
	  stw       r0, 0x4(r31)
	  lwz       r0, 0x8(r4)
	  mr        r4, r8
	  stw       r0, 0x8(r31)
	  lwz       r3, 0x3180(r13)
	  bl        0x8874C
	  stw       r3, 0xC(r31)
	  lwz       r3, 0xC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x78
	  stw       r31, 0x18(r3)
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x1
	  stw       r0, 0x80(r3)

	.loc_0x78:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114428
 * Size:	000034
 */
void PermanentEffect::updatePos(Vector3f&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x8(r3)
	  lwz       r3, 0xC(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,0,30
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011445C
 * Size:	000080
 */
void PermanentEffect::changeEffect(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r0, 0xC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  lwz       r3, 0x3180(r13)
	  mr        r4, r0
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8D130

	.loc_0x3C:
	  lwz       r3, 0x3180(r13)
	  addi      r4, r31, 0
	  addi      r5, r30, 0
	  li        r6, 0
	  li        r7, 0
	  bl        0x8868C
	  stw       r3, 0xC(r30)
	  lwz       r3, 0xC(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  stw       r30, 0x18(r3)

	.loc_0x68:
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
 * Address:	801144DC
 * Size:	00001C
 */
void PermanentEffect::stop()
{
	/*
	.loc_0x0:
	  lwz       r3, 0xC(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801144F8
 * Size:	00001C
 */
void PermanentEffect::restart()
{
	/*
	.loc_0x0:
	  lwz       r3, 0xC(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x10
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114514
 * Size:	00004C
 */
void PermanentEffect::kill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r4, 0xC(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x38
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8D084
	  li        r0, 0
	  stw       r0, 0xC(r31)

	.loc_0x38:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114560
 * Size:	000080
 */
void FreeLightEffect::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lwz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x68
	  lhz       r0, 0xC(r30)
	  li        r6, 0
	  lwz       r3, 0x3180(r13)
	  li        r7, 0
	  lwz       r5, 0x20(r31)
	  subfic    r4, r0, 0x2A
	  bl        0x88598
	  stw       r3, 0x10(r30)
	  lwz       r3, 0x10(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  lfs       f0, 0xF0(r3)
	  stfs      f0, 0x14(r30)
	  lwz       r0, 0x20(r31)
	  lwz       r3, 0x10(r30)
	  stw       r0, 0x18(r3)

	.loc_0x68:
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
 * Address:	801145E0
 * Size:	00001C
 */
void FreeLightEffect::stop()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x10(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801145FC
 * Size:	00001C
 */
void FreeLightEffect::restart()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x10(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x10
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114618
 * Size:	00001C
 */
void FreeLightEffect::setScale(f32)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x10(r3)
	  cmplwi    r4, 0
	  beqlr-
	  lfs       f0, 0x14(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xF0(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114634
 * Size:	00004C
 */
void FreeLightEffect::kill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r4, 0x10(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x38
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8CF64
	  li        r0, 0
	  stw       r0, 0x10(r31)

	.loc_0x38:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114680
 * Size:	000134
 */
void RippleEffect::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x60(r1)
	  mr        r30, r3
	  lwz       r0, 0xC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x118
	  lfs       f31, 0x24(r31)
	  li        r4, 0xD
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  lwz       r5, 0x20(r31)
	  li        r7, 0
	  bl        0x88474
	  stw       r3, 0x10(r30)
	  lwz       r3, 0x10(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xA4
	  lfs       f0, 0xF0(r3)
	  lwz       r0, 0x20(r31)
	  fmuls     f0, f31, f0
	  stw       r0, 0x18(r3)
	  lfs       f1, -0x2484(r13)
	  lfs       f2, -0x2480(r13)
	  stfs      f1, 0x4C(r1)
	  lfs       f1, -0x247C(r13)
	  stfs      f2, 0x50(r1)
	  stfs      f1, 0x54(r1)
	  lwz       r4, 0x10(r30)
	  lwz       r3, 0x4C(r1)
	  lwz       r0, 0x50(r1)
	  stw       r3, 0x1DC(r4)
	  stw       r0, 0x1E0(r4)
	  lwz       r0, 0x54(r1)
	  stw       r0, 0x1E4(r4)
	  lwz       r3, 0x10(r30)
	  stfs      f0, 0xF0(r3)

	.loc_0xA4:
	  lwz       r3, 0x3180(r13)
	  li        r4, 0xE
	  lwz       r5, 0x20(r31)
	  li        r6, 0
	  li        r7, 0
	  bl        0x88400
	  stw       r3, 0xC(r30)
	  lwz       r3, 0xC(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x118
	  lfs       f0, 0xF0(r3)
	  lwz       r0, 0x20(r31)
	  fmuls     f0, f31, f0
	  stw       r0, 0x18(r3)
	  lfs       f1, -0x2478(r13)
	  lfs       f2, -0x2474(r13)
	  stfs      f1, 0x40(r1)
	  lfs       f1, -0x2470(r13)
	  stfs      f2, 0x44(r1)
	  stfs      f1, 0x48(r1)
	  lwz       r4, 0xC(r30)
	  lwz       r3, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stw       r3, 0x1DC(r4)
	  stw       r0, 0x1E0(r4)
	  lwz       r0, 0x48(r1)
	  stw       r0, 0x1E4(r4)
	  lwz       r3, 0xC(r30)
	  stfs      f0, 0xF0(r3)

	.loc_0x118:
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801147B4
 * Size:	000094
 */
void RippleEffect::kill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r4, 0x10(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x38
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8CDE4
	  li        r0, 0
	  stw       r0, 0x10(r31)

	.loc_0x38:
	  lwz       r4, 0x14(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x5C
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8CDC0
	  li        r0, 0
	  stw       r0, 0x14(r31)

	.loc_0x5C:
	  lwz       r4, 0xC(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x80
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8CD9C
	  li        r0, 0
	  stw       r0, 0xC(r31)

	.loc_0x80:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114848
 * Size:	000034
 */
void RippleEffect::stop()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x10(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x18
	  lwz       r0, 0x80(r4)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r4)

	.loc_0x18:
	  lwz       r3, 0xC(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011487C
 * Size:	000034
 */
void RippleEffect::restart()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x10(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x18
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x10
	  stw       r0, 0x80(r4)

	.loc_0x18:
	  lwz       r3, 0xC(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x10
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801148B0
 * Size:	00001C
 */
void BurnEffect::stop()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x10(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801148CC
 * Size:	00001C
 */
void BurnEffect::restart()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x10(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x10
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801148E8
 * Size:	00014C
 */
void BurnEffect::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x78(r1)
	  mr        r30, r3
	  lwz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x134
	  lwz       r3, 0x3180(r13)
	  mr        r6, r30
	  lwz       r5, 0x20(r31)
	  li        r4, 0x2B
	  li        r7, 0
	  bl        0x88214
	  stw       r3, 0x10(r30)
	  lwz       r3, 0x10(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xC8
	  lwz       r0, 0x20(r31)
	  stw       r0, 0x18(r3)
	  lfs       f0, -0x246C(r13)
	  lfs       f1, -0x2468(r13)
	  stfs      f0, 0x54(r1)
	  lfs       f0, -0x2464(r13)
	  stfs      f1, 0x58(r1)
	  stfs      f0, 0x5C(r1)
	  lwz       r4, 0x10(r30)
	  lwz       r3, 0x54(r1)
	  lwz       r0, 0x58(r1)
	  stw       r3, 0x1DC(r4)
	  stw       r0, 0x1E0(r4)
	  lwz       r0, 0x5C(r1)
	  stw       r0, 0x1E4(r4)
	  lwz       r3, 0xC(r30)
	  lfs       f0, -0x60AC(r2)
	  lfs       f1, 0x0(r3)
	  lfs       f2, -0x60B0(r2)
	  lfs       f3, 0x8(r3)
	  fmuls     f1, f1, f0
	  lwz       r3, 0x10(r30)
	  fmuls     f2, f2, f0
	  fmuls     f3, f3, f0
	  stfs      f1, 0x138(r3)
	  stfs      f2, 0x13C(r3)
	  stfs      f3, 0x140(r3)
	  lwz       r0, 0x84(r3)
	  oris      r0, r0, 0x2
	  stw       r0, 0x84(r3)

	.loc_0xC8:
	  lwz       r3, 0x3180(r13)
	  mr        r6, r30
	  lwz       r5, 0x20(r31)
	  li        r4, 0x2C
	  li        r7, 0
	  bl        0x88174
	  stw       r3, 0x14(r30)
	  lwz       r3, 0x14(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x134
	  lwz       r0, 0x20(r31)
	  stw       r0, 0x18(r3)
	  lwz       r3, 0xC(r30)
	  lfs       f0, -0x60AC(r2)
	  lfs       f1, 0x0(r3)
	  lfs       f2, -0x60B0(r2)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x8(r3)
	  lwz       r3, 0x14(r30)
	  fmuls     f2, f2, f0
	  fmuls     f3, f3, f0
	  stfs      f1, 0x138(r3)
	  stfs      f2, 0x13C(r3)
	  stfs      f3, 0x140(r3)
	  lwz       r0, 0x84(r3)
	  oris      r0, r0, 0x2
	  stw       r0, 0x84(r3)

	.loc_0x134:
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114A34
 * Size:	000070
 */
void BurnEffect::kill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r4, 0x10(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x38
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8CB64
	  li        r0, 0
	  stw       r0, 0x10(r31)

	.loc_0x38:
	  lwz       r4, 0x14(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x5C
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8CB40
	  li        r0, 0
	  stw       r0, 0x14(r31)

	.loc_0x5C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114AA4
 * Size:	000008
 */
bool BurnEffect::invoke(zen::particleGenerator*)
{
	return true;
}

/*
 * --INFO--
 * Address:	80114AAC
 * Size:	0001C4
 */
void UfoSuikomiEffect::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stfd      f29, 0xA8(r1)
	  stfd      f28, 0xA0(r1)
	  stfd      f27, 0x98(r1)
	  stfd      f26, 0x90(r1)
	  stw       r31, 0x8C(r1)
	  stw       r30, 0x88(r1)
	  mr        r30, r3
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0xC(r3)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x14(r3)
	  lwz       r3, 0xC(r4)
	  lwz       r0, 0x10(r4)
	  stw       r3, 0x18(r30)
	  stw       r0, 0x1C(r30)
	  lwz       r0, 0x14(r4)
	  stw       r0, 0x20(r30)
	  lwz       r0, 0x24(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x194
	  cmplwi    r30, 0
	  addi      r7, r30, 0
	  beq-      .loc_0x7C
	  addi      r7, r7, 0x4

	.loc_0x7C:
	  lwz       r3, 0x3180(r13)
	  addi      r6, r30, 0
	  addi      r5, r30, 0xC
	  li        r4, 0x148
	  bl        0x88000
	  stw       r3, 0x24(r30)
	  lfs       f26, 0x20(r30)
	  lfs       f0, 0x14(r30)
	  lfs       f27, 0x1C(r30)
	  lfs       f1, 0x10(r30)
	  fsubs     f29, f26, f0
	  lwz       r31, 0x24(r30)
	  lfs       f28, 0x18(r30)
	  fsubs     f30, f27, f1
	  lfs       f0, 0xC(r30)
	  mr        r3, r31
	  fsubs     f31, f28, f0
	  bl        .loc_0x1C4
	  lfs       f0, 0x8(r3)
	  addi      r6, r1, 0x3C
	  addi      r5, r1, 0x38
	  fsubs     f0, f26, f0
	  addi      r4, r1, 0x34
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x4(r3)
	  fsubs     f0, f27, f0
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x0(r3)
	  addi      r3, r1, 0x48
	  fsubs     f0, f28, f0
	  stfs      f0, 0x34(r1)
	  bl        -0xDDA88
	  lfs       f2, 0x48(r1)
	  fmuls     f1, f31, f31
	  fmuls     f0, f30, f30
	  stfs      f2, 0x170(r31)
	  fmuls     f2, f29, f29
	  lfs       f3, 0x4C(r1)
	  fadds     f0, f1, f0
	  stfs      f3, 0x174(r31)
	  fadds     f1, f2, f0
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x178(r31)
	  lfs       f0, -0x60A8(r2)
	  stfs      f0, 0x17C(r31)
	  lwz       r0, 0x84(r31)
	  oris      r0, r0, 0x10
	  stw       r0, 0x84(r31)
	  bl        -0x106FA8
	  lfs       f0, -0x60B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x158
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x158:
	  lwz       r3, 0x24(r30)
	  stfs      f31, 0x144(r3)
	  stfs      f30, 0x148(r3)
	  stfs      f29, 0x14C(r3)
	  lfs       f0, -0x60A4(r2)
	  stfs      f0, 0x150(r3)
	  lfs       f0, -0x60A0(r2)
	  stfs      f0, 0x154(r3)
	  lfs       f0, -0x609C(r2)
	  stfs      f0, 0x158(r3)
	  lfs       f0, -0x6098(r2)
	  stfs      f0, 0x15C(r3)
	  lwz       r0, 0x84(r3)
	  oris      r0, r0, 0x4
	  stw       r0, 0x84(r3)

	.loc_0x194:
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lfd       f29, 0xA8(r1)
	  lfd       f28, 0xA0(r1)
	  lfd       f27, 0x98(r1)
	  lfd       f26, 0x90(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr

	.loc_0x1C4:
	*/
}

/*
 * --INFO--
 * Address:	80114C8C
 * Size:	00004C
 */
void UfoSuikomiEffect::kill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r4, 0x24(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x38
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8C90C
	  li        r0, 0
	  stw       r0, 0x24(r31)

	.loc_0x38:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114CD8
 * Size:	0000E0
 */
void WhistleTemplate::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0xC(r3)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x14(r3)
	  lwz       r3, 0xC(r4)
	  lwz       r0, 0x10(r4)
	  stw       r3, 0x18(r31)
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x14(r4)
	  stw       r0, 0x20(r31)
	  lwz       r0, 0x24(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xCC
	  lwz       r0, 0x28(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  b         .loc_0xCC

	.loc_0x60:
	  cmplwi    r31, 0
	  addi      r7, r31, 0
	  beq-      .loc_0x70
	  addi      r7, r7, 0x4

	.loc_0x70:
	  lwz       r3, 0x3180(r13)
	  mr        r6, r31
	  lwz       r4, 0x2C(r31)
	  addi      r5, r31, 0x18
	  bl        0x87DE0
	  cmplwi    r31, 0
	  stw       r3, 0x24(r31)
	  mr        r7, r31
	  beq-      .loc_0x98
	  addi      r7, r7, 0x4

	.loc_0x98:
	  lwz       r3, 0x3180(r13)
	  mr        r6, r31
	  lwz       r4, 0x30(r31)
	  addi      r5, r31, 0x18
	  bl        0x87DB8
	  stw       r3, 0x28(r31)
	  lwz       r4, 0x24(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xCC
	  lbz       r0, 0x68(r4)
	  li        r3, 0x1
	  rlwimi    r0,r3,5,26,26
	  stb       r0, 0x68(r4)

	.loc_0xCC:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114DB8
 * Size:	000070
 */
void WhistleTemplate::kill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r4, 0x24(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x38
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8C7E0
	  li        r0, 0
	  stw       r0, 0x24(r31)

	.loc_0x38:
	  lwz       r4, 0x28(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x5C
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8C7BC
	  li        r0, 0
	  stw       r0, 0x28(r31)

	.loc_0x5C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80114E28
 * Size:	00034C
 */
bool WhistleTemplate::invoke(zen::particleGenerator*, zen::particleMdl*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r6, r3
	  stw       r0, 0x4(r1)
	  lis       r4, 0x4330
	  stwu      r1, -0x130(r1)
	  stfd      f31, 0x128(r1)
	  stw       r31, 0x124(r1)
	  mr        r31, r5
	  stw       r30, 0x120(r1)
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x18(r3)
	  lfs       f3, 0x10(r3)
	  lfs       f2, 0x1C(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x14(r3)
	  lfs       f1, 0x20(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x100(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x104(r1)
	  stfs      f0, 0x108(r1)
	  lha       r3, 0x2E(r5)
	  lha       r0, 0x2C(r5)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x6088(r2)
	  stw       r3, 0x11C(r1)
	  xoris     r0, r0, 0x8000
	  lwz       r3, 0x18(r6)
	  stw       r0, 0x114(r1)
	  lwz       r0, 0x1C(r6)
	  stw       r4, 0x118(r1)
	  stw       r4, 0x110(r1)
	  lfd       f1, 0x118(r1)
	  lfd       f0, 0x110(r1)
	  fsubs     f1, f1, f2
	  stw       r3, 0x18(r5)
	  fsubs     f0, f0, f2
	  stw       r0, 0x1C(r5)
	  fdivs     f31, f1, f0
	  lwz       r0, 0x20(r6)
	  stw       r0, 0x20(r5)
	  lfs       f0, 0x100(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x58(r1)
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x104(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x108(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x84(r1)
	  lwz       r3, 0x7C(r1)
	  lwz       r0, 0x80(r1)
	  stw       r3, 0xC(r5)
	  stw       r0, 0x10(r5)
	  lwz       r0, 0x84(r1)
	  stw       r0, 0x14(r5)
	  lfs       f1, -0x6094(r2)
	  lfs       f0, 0x1C(r6)
	  lfs       f2, 0x10(r6)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x2F0
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0xC(r6)
	  lfs       f2, 0x14(r6)
	  bl        -0xACD60
	  lfs       f0, -0x60B0(r2)
	  mr        r30, r3
	  li        r3, 0x8
	  stfs      f0, 0xD8(r1)
	  stfs      f0, 0xDC(r1)
	  stfs      f0, 0xE0(r1)
	  stfs      f0, 0xE4(r1)
	  stfs      f0, 0xE8(r1)
	  stfs      f0, 0xEC(r1)
	  stfs      f0, 0xF0(r1)
	  stfs      f0, 0xF4(r1)
	  b         .loc_0x310

	.loc_0x144:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x160

	.loc_0x154:
	  stfs      f0, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x154

	.loc_0x160:
	  lfs       f1, -0x6090(r2)
	  li        r3, 0x8
	  lfs       f0, -0x60B0(r2)
	  stfs      f1, 0xF8(r1)
	  stfs      f1, 0xE8(r1)
	  stfs      f1, 0xD8(r1)
	  stfs      f0, 0xB4(r1)
	  stfs      f0, 0xB8(r1)
	  stfs      f0, 0xBC(r1)
	  stfs      f0, 0xC0(r1)
	  stfs      f0, 0xC4(r1)
	  stfs      f0, 0xC8(r1)
	  stfs      f0, 0xCC(r1)
	  stfs      f0, 0xD0(r1)
	  b         .loc_0x320

	.loc_0x19C:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x1B8

	.loc_0x1AC:
	  stfs      f0, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x1AC

	.loc_0x1B8:
	  lfs       f0, -0x60B0(r2)
	  lfs       f2, -0x6090(r2)
	  stfs      f0, 0xAC(r1)
	  lfs       f1, 0x100(r1)
	  stfs      f2, 0xD4(r1)
	  fmuls     f1, f1, f1
	  stfs      f0, 0x9C(r1)
	  stfs      f2, 0xC4(r1)
	  stfs      f0, 0xA8(r1)
	  stfs      f0, 0x98(r1)
	  stfs      f2, 0xB4(r1)
	  stfs      f0, 0xA4(r1)
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x104(r1)
	  lfs       f2, 0x108(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1073EC
	  lfs       f0, -0x60B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x238
	  lfs       f0, 0x100(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x100(r1)
	  lfs       f0, 0x104(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x104(r1)
	  lfs       f0, 0x108(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x108(r1)

	.loc_0x238:
	  addi      r3, r1, 0x100
	  addi      r4, r1, 0xD8
	  bl        0x86A78
	  lfs       f3, -0x2498(r13)
	  addi      r3, r1, 0x70
	  lfs       f0, 0x18(r30)
	  addi      r4, r1, 0xB4
	  lfs       f2, 0x20(r30)
	  lfs       f1, 0x1C(r30)
	  fmuls     f0, f0, f3
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x54(r1)
	  stfs      f0, 0x70(r1)
	  stfs      f1, 0x74(r1)
	  stfs      f2, 0x78(r1)
	  bl        0x86A3C
	  addi      r3, r1, 0xA4
	  addi      r4, r1, 0xD8
	  bl        -0xDD7F4
	  addi      r3, r1, 0x94
	  addi      r4, r1, 0xB4
	  bl        -0xDD800
	  fmr       f1, f31
	  addi      r3, r1, 0xA4
	  addi      r4, r1, 0x94
	  li        r5, 0
	  bl        -0xDCF4C
	  addi      r3, r1, 0xA4
	  addi      r4, r31, 0x5C
	  bl        -0xDD058
	  addi      r3, r1, 0xA4
	  addi      r4, r31, 0x34
	  bl        -0xDD0E4
	  lfs       f0, 0x34(r31)
	  lfs       f1, -0x60AC(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r31)
	  lfs       f0, 0x38(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r31)
	  lfs       f0, 0x3C(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r31)
	  b         .loc_0x308

	.loc_0x2F0:
	  lfs       f0, 0x100(r1)
	  stfs      f0, 0x5C(r31)
	  lfs       f0, 0x104(r1)
	  stfs      f0, 0x60(r31)
	  lfs       f0, 0x108(r1)
	  stfs      f0, 0x64(r31)

	.loc_0x308:
	  li        r3, 0
	  b         .loc_0x330

	.loc_0x310:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0xD8
	  add       r4, r4, r0
	  b         .loc_0x144

	.loc_0x320:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0xB4
	  add       r4, r4, r0
	  b         .loc_0x19C

	.loc_0x330:
	  lwz       r0, 0x134(r1)
	  lfd       f31, 0x128(r1)
	  lwz       r31, 0x124(r1)
	  lwz       r30, 0x120(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115174
 * Size:	0000D8
 */
void BombEffectLight::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  addi      r5, r31, 0
	  lwz       r3, 0x3180(r13)
	  li        r4, 0x20
	  bl        0x8799C
	  cmplwi    r3, 0
	  beq-      .loc_0x64
	  lfs       f0, -0x24A4(r13)
	  lfs       f1, -0x24A0(r13)
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0x249C(r13)
	  stfs      f1, 0x14(r1)
	  stfs      f0, 0x18(r1)
	  lwz       r4, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x18(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0x64:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x17
	  li        r6, 0
	  li        r7, 0
	  bl        0x8794C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x18
	  li        r6, 0
	  li        r7, 0
	  bl        0x87934
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x19
	  li        r6, 0
	  li        r7, 0
	  bl        0x8791C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x1A
	  li        r6, 0
	  li        r7, 0
	  bl        0x87904
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011524C
 * Size:	000004
 */
void BombEffectLight::kill()
{
}

/*
 * --INFO--
 * Address:	80115250
 * Size:	0000F0
 */
void BombEffect::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  addi      r5, r31, 0
	  lwz       r3, 0x3180(r13)
	  li        r4, 0x20
	  bl        0x878C0
	  cmplwi    r3, 0
	  beq-      .loc_0x64
	  lfs       f0, -0x24B0(r13)
	  lfs       f1, -0x24AC(r13)
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0x24A8(r13)
	  stfs      f1, 0x14(r1)
	  stfs      f0, 0x18(r1)
	  lwz       r4, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x18(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0x64:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x1F
	  li        r6, 0
	  li        r7, 0
	  bl        0x87870
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x21
	  li        r6, 0
	  li        r7, 0
	  bl        0x87858
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x1E
	  li        r6, 0
	  li        r7, 0
	  bl        0x87840
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x22
	  li        r6, 0
	  li        r7, 0
	  bl        0x87828
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x23
	  li        r6, 0
	  li        r7, 0
	  bl        0x87810
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115340
 * Size:	000004
 */
void BombEffect::kill()
{
}

/*
 * --INFO--
 * Address:	80115344
 * Size:	000044
 */
void SimpleEffect::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r4
	  stw       r0, 0x4(r1)
	  li        r6, 0
	  li        r7, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x3180(r13)
	  lwz       r4, 0xC(r31)
	  bl        0x877CC
	  stw       r3, 0x10(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115388
 * Size:	000038
 */
void SimpleEffect::kill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x10(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x28
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8C218

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801153C0
 * Size:	000008
 */
bool NaviFue::invoke(zen::particleGenerator*)
{
	return true;
}

/*
 * --INFO--
 * Address:	801153C8
 * Size:	0000C0
 */
void NaviFue::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  stw       r28, 0x18(r1)
	  mr        r28, r3
	  lwz       r3, 0x14(r3)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xA0
	  li        r29, 0
	  mulli     r31, r29, 0xC
	  li        r30, 0
	  b         .loc_0x94

	.loc_0x40:
	  lwz       r0, 0xC(r28)
	  addi      r5, r31, 0x938
	  lwz       r3, 0x3180(r13)
	  addi      r6, r28, 0
	  add       r5, r0, r5
	  li        r4, 0x14
	  li        r7, 0
	  bl        0x87714
	  lwz       r4, 0x14(r28)
	  stwx      r3, r4, r30
	  lwz       r3, 0x14(r28)
	  lwzx      r4, r3, r30
	  cmplwi    r4, 0
	  beq-      .loc_0x88
	  lwz       r3, 0xC(r28)
	  addi      r0, r31, 0x938
	  add       r0, r3, r0
	  stw       r0, 0x18(r4)

	.loc_0x88:
	  addi      r31, r31, 0xC
	  addi      r30, r30, 0x4
	  addi      r29, r29, 0x1

	.loc_0x94:
	  lwz       r0, 0x10(r28)
	  cmpw      r29, r0
	  blt+      .loc_0x40

	.loc_0xA0:
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
 * Address:	80115488
 * Size:	0000B4
 */
void NaviFue::kill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stfd      f31, 0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r3, 0x14(r3)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x90
	  li        r30, 0
	  lfs       f31, -0x60B0(r2)
	  addi      r31, r30, 0
	  li        r29, 0
	  b         .loc_0x84

	.loc_0x48:
	  lwz       r3, 0x14(r28)
	  lwzx      r3, r3, r30
	  cmplwi    r3, 0
	  beq-      .loc_0x74
	  stfs      f31, 0xB8(r3)
	  li        r5, 0
	  lwz       r3, 0x14(r28)
	  lwz       r6, 0x3180(r13)
	  lwzx      r4, r3, r30
	  addi      r3, r6, 0x14
	  bl        0x8C0CC

	.loc_0x74:
	  lwz       r3, 0x14(r28)
	  addi      r29, r29, 0x1
	  stwx      r31, r3, r30
	  addi      r30, r30, 0x4

	.loc_0x84:
	  lwz       r0, 0x10(r28)
	  cmpw      r29, r0
	  blt+      .loc_0x48

	.loc_0x90:
	  lwz       r0, 0x2C(r1)
	  lfd       f31, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011553C
 * Size:	000034
 */
void SmokeTreeEffect::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0x13
	  li        r6, 0
	  stwu      r1, -0x8(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  bl        0x875DC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115570
 * Size:	000034
 */
void SmokeRockEffect::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0x11
	  li        r6, 0
	  stwu      r1, -0x8(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  bl        0x875A8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801155A4
 * Size:	000034
 */
void SmokeGrassEffect::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0x12
	  li        r6, 0
	  stwu      r1, -0x8(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  bl        0x87574
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801155D8
 * Size:	000034
 */
void SmokeSoilEffect::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0x13
	  li        r6, 0
	  stwu      r1, -0x8(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  bl        0x87540
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011560C
 * Size:	0000FC
 */
void NaviWhistle::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  lwz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xE8
	  lwz       r0, 0x14(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xE8
	  lwz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  b         .loc_0xE8

	.loc_0x3C:
	  lwz       r5, 0xC(r31)
	  mr        r6, r31
	  lwz       r3, 0x3180(r13)
	  li        r4, 0xB
	  addi      r5, r5, 0x784
	  li        r7, 0
	  bl        0x874D8
	  cmplwi    r31, 0
	  stw       r3, 0x10(r31)
	  mr        r7, r31
	  beq-      .loc_0x6C
	  addi      r7, r7, 0x4

	.loc_0x6C:
	  lwz       r4, 0xC(r31)
	  mr        r6, r31
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x784
	  li        r4, 0xA
	  bl        0x874AC
	  cmplwi    r31, 0
	  stw       r3, 0x14(r31)
	  mr        r7, r31
	  beq-      .loc_0x98
	  addi      r7, r7, 0x4

	.loc_0x98:
	  lwz       r4, 0xC(r31)
	  mr        r6, r31
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x784
	  li        r4, 0x9
	  bl        0x87480
	  stw       r3, 0x18(r31)
	  lwz       r4, 0x10(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xCC
	  lwz       r3, 0xC(r31)
	  addi      r0, r3, 0x784
	  stw       r0, 0x18(r4)

	.loc_0xCC:
	  lwz       r4, 0x14(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xE8
	  lbz       r0, 0x68(r4)
	  li        r3, 0x1
	  rlwimi    r0,r3,5,26,26
	  stb       r0, 0x68(r4)

	.loc_0xE8:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115708
 * Size:	000094
 */
void NaviWhistle::kill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r4, 0x10(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x38
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8BE90
	  li        r0, 0
	  stw       r0, 0x10(r31)

	.loc_0x38:
	  lwz       r4, 0x14(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x5C
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8BE6C
	  li        r0, 0
	  stw       r0, 0x14(r31)

	.loc_0x5C:
	  lwz       r4, 0x18(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x80
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x8BE48
	  li        r0, 0
	  stw       r0, 0x18(r31)

	.loc_0x80:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011579C
 * Size:	000364
 */
bool NaviWhistle::invoke(zen::particleGenerator*, zen::particleMdl*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x4330
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x138(r1)
	  stfd      f31, 0x130(r1)
	  stw       r31, 0x12C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x128(r1)
	  lwz       r4, 0xC(r3)
	  addi      r5, r4, 0x784
	  lfs       f0, 0x784(r4)
	  lfsu      f1, 0x6F0(r4)
	  lfs       f2, 0x4(r5)
	  lfs       f3, 0x4(r4)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r4)
	  lfs       f1, 0x8(r5)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x108(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x10C(r1)
	  stfs      f0, 0x110(r1)
	  lha       r4, 0x2E(r31)
	  lha       r0, 0x2C(r31)
	  xoris     r4, r4, 0x8000
	  lfd       f2, -0x6088(r2)
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x124(r1)
	  lwz       r5, 0xC(r3)
	  stw       r0, 0x11C(r1)
	  lwz       r4, 0x784(r5)
	  stw       r6, 0x120(r1)
	  lwz       r0, 0x788(r5)
	  stw       r6, 0x118(r1)
	  lfd       f1, 0x120(r1)
	  lfd       f0, 0x118(r1)
	  fsubs     f1, f1, f2
	  stw       r4, 0x18(r31)
	  fsubs     f0, f0, f2
	  stw       r0, 0x1C(r31)
	  fdivs     f31, f1, f0
	  lwz       r0, 0x78C(r5)
	  stw       r0, 0x20(r31)
	  lfs       f0, 0x108(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x60(r1)
	  stfs      f0, 0x84(r1)
	  lfs       f0, 0x10C(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0x110(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x8C(r1)
	  lwz       r4, 0x84(r1)
	  lwz       r0, 0x88(r1)
	  stw       r4, 0xC(r31)
	  stw       r0, 0x10(r31)
	  lwz       r0, 0x8C(r1)
	  stw       r0, 0x14(r31)
	  lwz       r5, 0xC(r3)
	  lfs       f1, -0x6094(r2)
	  lfs       f0, 0x98(r5)
	  lfs       f2, 0x6F4(r5)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x308
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x6F0(r5)
	  lfs       f2, 0x6F8(r5)
	  bl        -0xAD6E0
	  mr.       r30, r3
	  bne-      .loc_0x130
	  li        r3, 0
	  b         .loc_0x348

	.loc_0x130:
	  lfs       f0, -0x60B0(r2)
	  li        r3, 0x8
	  stfs      f0, 0xE0(r1)
	  stfs      f0, 0xE4(r1)
	  stfs      f0, 0xE8(r1)
	  stfs      f0, 0xEC(r1)
	  stfs      f0, 0xF0(r1)
	  stfs      f0, 0xF4(r1)
	  stfs      f0, 0xF8(r1)
	  stfs      f0, 0xFC(r1)
	  b         .loc_0x328

	.loc_0x15C:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x178

	.loc_0x16C:
	  stfs      f0, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x16C

	.loc_0x178:
	  lfs       f1, -0x6090(r2)
	  li        r3, 0x8
	  lfs       f0, -0x60B0(r2)
	  stfs      f1, 0x100(r1)
	  stfs      f1, 0xF0(r1)
	  stfs      f1, 0xE0(r1)
	  stfs      f0, 0xBC(r1)
	  stfs      f0, 0xC0(r1)
	  stfs      f0, 0xC4(r1)
	  stfs      f0, 0xC8(r1)
	  stfs      f0, 0xCC(r1)
	  stfs      f0, 0xD0(r1)
	  stfs      f0, 0xD4(r1)
	  stfs      f0, 0xD8(r1)
	  b         .loc_0x338

	.loc_0x1B4:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x1D0

	.loc_0x1C4:
	  stfs      f0, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x1C4

	.loc_0x1D0:
	  lfs       f0, -0x60B0(r2)
	  lfs       f2, -0x6090(r2)
	  stfs      f0, 0xB4(r1)
	  lfs       f1, 0x108(r1)
	  stfs      f2, 0xDC(r1)
	  fmuls     f1, f1, f1
	  stfs      f0, 0xA4(r1)
	  stfs      f2, 0xCC(r1)
	  stfs      f0, 0xB0(r1)
	  stfs      f0, 0xA0(r1)
	  stfs      f2, 0xBC(r1)
	  stfs      f0, 0xAC(r1)
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0x10C(r1)
	  lfs       f2, 0x110(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x107D78
	  lfs       f0, -0x60B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x250
	  lfs       f0, 0x108(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x108(r1)
	  lfs       f0, 0x10C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x10C(r1)
	  lfs       f0, 0x110(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x110(r1)

	.loc_0x250:
	  addi      r3, r1, 0x108
	  addi      r4, r1, 0xE0
	  bl        0x860EC
	  lfs       f3, -0x2494(r13)
	  addi      r3, r1, 0x78
	  lfs       f0, 0x18(r30)
	  addi      r4, r1, 0xBC
	  lfs       f2, 0x20(r30)
	  lfs       f1, 0x1C(r30)
	  fmuls     f0, f0, f3
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x58(r1)
	  stfs      f0, 0x78(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f2, 0x80(r1)
	  bl        0x860B0
	  addi      r3, r1, 0xAC
	  addi      r4, r1, 0xE0
	  bl        -0xDE180
	  addi      r3, r1, 0x9C
	  addi      r4, r1, 0xBC
	  bl        -0xDE18C
	  fmr       f1, f31
	  addi      r3, r1, 0xAC
	  addi      r4, r1, 0x9C
	  li        r5, 0
	  bl        -0xDD8D8
	  addi      r3, r1, 0xAC
	  addi      r4, r31, 0x5C
	  bl        -0xDD9E4
	  addi      r3, r1, 0xAC
	  addi      r4, r31, 0x34
	  bl        -0xDDA70
	  lfs       f0, 0x34(r31)
	  lfs       f1, -0x60AC(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r31)
	  lfs       f0, 0x38(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r31)
	  lfs       f0, 0x3C(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r31)
	  b         .loc_0x320

	.loc_0x308:
	  lfs       f0, 0x108(r1)
	  stfs      f0, 0x5C(r31)
	  lfs       f0, 0x10C(r1)
	  stfs      f0, 0x60(r31)
	  lfs       f0, 0x110(r1)
	  stfs      f0, 0x64(r31)

	.loc_0x320:
	  li        r3, 0
	  b         .loc_0x348

	.loc_0x328:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0xE0
	  add       r4, r4, r0
	  b         .loc_0x15C

	.loc_0x338:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0xBC
	  add       r4, r4, r0
	  b         .loc_0x1B4

	.loc_0x348:
	  lwz       r0, 0x13C(r1)
	  lfd       f31, 0x130(r1)
	  lwz       r31, 0x12C(r1)
	  lwz       r30, 0x128(r1)
	  addi      r1, r1, 0x138
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115B00
 * Size:	000038
 */
bool GoalEffect::invoke(zen::particleGenerator*)
{
	/*
	.loc_0x0:
	  lha       r0, 0x90(r4)
	  cmpwi     r0, 0x32
	  blt-      .loc_0x30
	  lfs       f1, -0x24B8(r13)
	  lfs       f2, -0x24B4(r13)
	  lfs       f0, -0x24BC(r13)
	  stfs      f0, 0x12C(r4)
	  stfs      f1, 0x130(r4)
	  stfs      f2, 0x134(r4)
	  lwz       r0, 0x84(r4)
	  rlwinm    r0,r0,0,16,14
	  stw       r0, 0x84(r4)

	.loc_0x30:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115B38
 * Size:	00003C
 */
void GoalEffect::emit(EffectParm&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr.       r6, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  addi      r7, r6, 0
	  beq-      .loc_0x1C
	  addi      r7, r7, 0x4

	.loc_0x1C:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0
	  li        r4, 0xE1
	  bl        0x86FD8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
