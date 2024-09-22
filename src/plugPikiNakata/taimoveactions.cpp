#include "TAI/MoveActions.h"
#include "teki.h"

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
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80134560
 * Size:	000028
 */
bool TaiMoveNestPositionAction::act(Teki& teki)
{
	teki.moveNestPosition();
	return false;
}

/*
 * --INFO--
 * Address:	80134588
 * Size:	000078
 */
void TaiStopMoveAction::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r5, r13, 0x11B0
	  stw       r0, 0x4(r1)
	  subi      r6, r13, 0x11AC
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  addi      r3, r1, 0x1C
	  subi      r4, r13, 0x11B4
	  bl        -0xFD490
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x1C
	  addi      r5, r1, 0x20
	  addi      r6, r1, 0x24
	  bl        -0xD6F34
	  addi      r3, r1, 0x10
	  subi      r4, r13, 0x11C0
	  subi      r5, r13, 0x11BC
	  subi      r6, r13, 0x11B8
	  bl        -0xFD4B8
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x10
	  addi      r5, r1, 0x14
	  addi      r6, r1, 0x18
	  bl        -0xD6F5C
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134600
 * Size:	00001C
 */
void TaiStartFlyingAction::start(Teki& teki)
{
	teki.setCreatureFlag(CF_Unk7);
	teki.resetCreatureFlag(CF_Unk2);
}

/*
 * --INFO--
 * Address:	8013461C
 * Size:	00001C
 */
void TaiFinishFlyingAction::start(Teki& teki)
{
	teki.resetCreatureFlag(CF_Unk7);
	teki.setCreatureFlag(CF_Unk2);
}

/*
 * --INFO--
 * Address:	80134638
 * Size:	000080
 */
bool TaiMakeVelocityDirectionAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  addi      r3, r1, 0x1C
	  bl        -0x177FC
	  addi      r3, r31, 0x368
	  lwz       r12, 0x368(r31)
	  addi      r4, r1, 0x1C
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x24(r1)
	  lfs       f1, 0x1C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f1, f1, f1
	  fadds     f1, f1, f0
	  bl        -0x126A40
	  lfs       f0, -0x5BB0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x68
	  lfs       f1, 0x1C(r1)
	  lfs       f2, 0x24(r1)
	  bl        -0x16890
	  stfs      f1, 0xA0(r31)

	.loc_0x68:
	  lwz       r0, 0x34(r1)
	  li        r3, 0
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801346B8
 * Size:	000080
 */
bool TaiMakeAccelerationDirectionAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  addi      r3, r1, 0x1C
	  bl        -0x1787C
	  addi      r3, r31, 0x378
	  lwz       r12, 0x378(r31)
	  addi      r4, r1, 0x1C
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x24(r1)
	  lfs       f1, 0x1C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f1, f1, f1
	  fadds     f1, f1, f0
	  bl        -0x126AC0
	  lfs       f0, -0x5BB0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x68
	  lfs       f1, 0x1C(r1)
	  lfs       f2, 0x24(r1)
	  bl        -0x16910
	  stfs      f1, 0xA0(r31)

	.loc_0x68:
	  lwz       r0, 0x34(r1)
	  li        r3, 0
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134738
 * Size:	0000D0
 */
bool TaiMakingNextVelocityAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  addi      r3, r1, 0x20
	  stw       r31, 0x34(r1)
	  addi      r31, r4, 0
	  lwz       r5, 0x3150(r13)
	  lfs       f31, 0x28C(r5)
	  bl        -0x17908
	  addi      r3, r31, 0x358
	  lwz       r12, 0x358(r31)
	  addi      r4, r1, 0x20
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x20(r1)
	  li        r3, 0
	  lfs       f0, 0x94(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x20(r1)
	  lfs       f1, 0x24(r1)
	  lfs       f0, 0x98(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x24(r1)
	  lfs       f1, 0x28(r1)
	  lfs       f0, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x5BAC(r2)
	  lfs       f1, 0x20(r1)
	  fdivs     f2, f0, f31
	  fmuls     f0, f1, f2
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x24(r1)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x28(r1)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x20(r1)
	  stfs      f0, 0x70(r31)
	  lfs       f0, 0x24(r1)
	  stfs      f0, 0x74(r31)
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x78(r31)
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134808
 * Size:	0000D0
 */
bool TaiMakingNextDriveAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x14
	  bl        -0x179D4
	  addi      r3, r31, 0x358
	  lwz       r12, 0x358(r31)
	  addi      r4, r1, 0x14
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x14(r1)
	  addi      r3, r1, 0x14
	  lfs       f0, 0x94(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r1)
	  lfs       f1, 0x18(r1)
	  lfs       f0, 0x98(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x18(r1)
	  lfs       f1, 0x1C(r1)
	  lfs       f0, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1C(r1)
	  bl        -0x17860
	  lfs       f1, 0x8(r30)
	  li        r3, 0
	  lfs       f0, 0x14(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x14(r1)
	  lfs       f0, 0x18(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x1C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x14(r1)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x18(r1)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x1C(r1)
	  stfs      f0, 0xAC(r31)
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
 * Address:	801348D8
 * Size:	000034
 */
bool TaiAccelerationAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x460(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013490C
 * Size:	000034
 */
bool TaiParabolaAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x45C(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134940
 * Size:	000034
 */
bool TaiCircleMoveAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x464(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134974
 * Size:	000034
 */
bool TaiHorizontalSinWaveAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x468(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801349A8
 * Size:	0000A8
 */
bool TaiClampMaxHeightAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x10
	  bl        -0x17B74
	  addi      r3, r31, 0x358
	  lwz       r12, 0x358(r31)
	  addi      r4, r1, 0x10
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        0x13F78
	  lfs       f2, 0x8(r30)
	  lfs       f0, 0x14(r1)
	  fadds     f1, f2, f1
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x8C
	  mr        r3, r31
	  bl        0x13F5C
	  lfs       f0, 0x8(r30)
	  addi      r3, r31, 0x358
	  addi      r4, r1, 0x10
	  fadds     f0, f0, f1
	  stfs      f0, 0x14(r1)
	  lwz       r12, 0x358(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x90

	.loc_0x8C:
	  li        r3, 0

	.loc_0x90:
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
 * Address:	80134A50
 * Size:	0000A8
 */
bool TaiClampMinHeightAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x10
	  bl        -0x17C1C
	  addi      r3, r31, 0x358
	  lwz       r12, 0x358(r31)
	  addi      r4, r1, 0x10
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        0x13ED0
	  lfs       f2, 0x8(r30)
	  lfs       f0, 0x14(r1)
	  fadds     f1, f2, f1
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x8C
	  mr        r3, r31
	  bl        0x13EB4
	  lfs       f0, 0x8(r30)
	  addi      r3, r31, 0x358
	  addi      r4, r1, 0x10
	  fadds     f0, f0, f1
	  stfs      f0, 0x14(r1)
	  lwz       r12, 0x358(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x90

	.loc_0x8C:
	  li        r3, 0

	.loc_0x90:
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
 * Address:	80134AF8
 * Size:	00008C
 */
bool TaiClampMinVelocityYAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x10
	  bl        -0x17CC4
	  addi      r3, r31, 0x368
	  lwz       r12, 0x368(r31)
	  addi      r4, r1, 0x10
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x14(r1)
	  lfs       f1, 0x8(r30)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x70
	  stfs      f1, 0x14(r1)
	  addi      r3, r31, 0x368
	  addi      r4, r1, 0x10
	  lwz       r12, 0x368(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x74

	.loc_0x70:
	  li        r3, 0

	.loc_0x74:
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
 * Address:	80134B84
 * Size:	000020
 */
void TaiImpassableAction::start(Teki& teki) { resetPosition(teki); }

/*
 * --INFO--
 * Address:	80134BA4
 * Size:	0000AC
 */
bool TaiImpassableAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  mr        r30, r3
	  lfs       f2, 0x9C(r4)
	  lfs       f3, 0x390(r4)
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x94(r31)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f1, f1, f0
	  bl        -0x126FA4
	  lfs       f0, 0x10(r30)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x68
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0xAC
	  li        r3, 0
	  b         .loc_0x94

	.loc_0x68:
	  lwz       r0, 0x8(r30)
	  lfs       f0, -0x5BB0(r2)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r31, r0
	  lfs       f1, 0x3C4(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x90
	  li        r3, 0
	  b         .loc_0x94

	.loc_0x90:
	  li        r3, 0x1

	.loc_0x94:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr

	.loc_0xAC:
	*/
}

/*
 * --INFO--
 * Address:	80134C50
 * Size:	000030
 */
void TaiImpassableAction::resetPosition(Teki& teki)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x94(r4)
	  stfs      f0, 0x388(r4)
	  lfs       f0, 0x98(r4)
	  stfs      f0, 0x38C(r4)
	  lfs       f0, 0x9C(r4)
	  stfs      f0, 0x390(r4)
	  lwz       r0, 0x8(r3)
	  lfs       f0, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r4, r0
	  stfs      f0, 0x3C4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134C80
 * Size:	000044
 */
void TaiRandomWanderingRouteAction::start(Teki& teki)
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
	  bl        -0xC2C
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x15C
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
 * Address:	80134CC4
 * Size:	000004
 */
void TaiRandomWanderingRouteAction::finish(Teki& teki) { }

/*
 * --INFO--
 * Address:	80134CC8
 * Size:	00013C
 */
bool TaiRandomWanderingRouteAction::act(Teki& teki)
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
	  bl        -0xB78
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x124

	.loc_0x48:
	  lwz       r5, 0x34C(r31)
	  cmpwi     r5, 0
	  bne-      .loc_0x68
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x13C
	  li        r3, 0
	  b         .loc_0x124

	.loc_0x68:
	  lwz       r4, 0x348(r31)
	  cmpw      r5, r4
	  ble-      .loc_0x98
	  lwz       r3, 0x354(r31)
	  subi      r0, r4, 0x1
	  cmpw      r3, r0
	  ble-      .loc_0x98
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x13C
	  li        r3, 0
	  b         .loc_0x124

	.loc_0x98:
	  lwz       r4, 0x354(r31)
	  subi      r0, r5, 0x1
	  cmpw      r4, r0
	  ble-      .loc_0xBC
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x13C
	  li        r3, 0
	  b         .loc_0x124

	.loc_0xBC:
	  mr        r3, r31
	  bl        0x13DF4
	  mr.       r4, r3
	  bne-      .loc_0xE0
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x13C
	  li        r3, 0
	  b         .loc_0x124

	.loc_0xE0:
	  lbz       r0, 0x38(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x100
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x13C
	  li        r3, 0
	  b         .loc_0x124

	.loc_0x100:
	  lfs       f1, 0xC(r30)
	  mr        r3, r31
	  bl        0x12620
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x120
	  lwz       r3, 0x354(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x354(r31)

	.loc_0x120:
	  li        r3, 0

	.loc_0x124:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x13C:
	*/
}

/*
 * --INFO--
 * Address:	80134E04
 * Size:	000070
 */
void TaiRandomWanderingRouteAction::makeTargetPosition(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r4, 0
	  addi      r4, r30, 0x94
	  addi      r3, r30, 0
	  bl        0x13CC0
	  lwz       r31, 0x10(r3)
	  lwz       r3, 0x302C(r13)
	  lwz       r4, 0x350(r30)
	  bl        -0x94D2C
	  subi      r3, r3, 0x1
	  bl        -0x16598
	  addi      r5, r3, 0
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  li        r6, 0
	  bl        0x13BFC
	  li        r0, 0
	  stw       r0, 0x354(r30)
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
 * Address:	80134E74
 * Size:	000088
 */
bool TaiTracingAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  bl        -0xD24
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x70

	.loc_0x48:
	  lwz       r3, 0x418(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0x5C
	  li        r3, 0
	  b         .loc_0x70

	.loc_0x5C:
	  lfs       f1, 0xC(r30)
	  addi      r4, r3, 0x94
	  mr        r3, r31
	  bl        0x12514
	  li        r3, 0

	.loc_0x70:
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
 * Address:	80134EFC
 * Size:	000004
 */
void TaiGoingHomeAction::finish(Teki& teki) { }

/*
 * --INFO--
 * Address:	80134F00
 * Size:	000078
 */
bool TaiGoingHomeAction::act(Teki& teki)
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
	  bl        -0xDB0
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x60

	.loc_0x48:
	  lwz       r4, 0x2C8(r31)
	  mr        r3, r31
	  lfs       f1, 0xC(r30)
	  addi      r4, r4, 0x10
	  bl        0x12498
	  li        r3, 0

	.loc_0x60:
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
 * Address:	80134F78
 * Size:	000044
 */
bool TaiDirectTurnAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x418(r4)
	  cmplwi    r3, 0
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x34

	.loc_0x20:
	  addi      r0, r3, 0x94
	  addi      r3, r4, 0
	  mr        r4, r0
	  bl        -0xAA568
	  li        r3, 0

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134FBC
 * Size:	00014C
 */
bool TaiTurningAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  stw       r30, 0x70(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x6C(r1)
	  addi      r29, r3, 0
	  bl        -0xE70
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r30
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x4C
	  li        r3, 0
	  b         .loc_0x130

	.loc_0x4C:
	  lwz       r31, 0x418(r30)
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  bne-      .loc_0x64
	  li        r3, 0x1
	  b         .loc_0x130

	.loc_0x64:
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x5C(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x5C(r1)
	  subi      r0, r3, 0x295C
	  stw       r0, 0x5C(r1)
	  addi      r3, r1, 0x5C
	  stw       r30, 0x60(r1)
	  bl        0x14E44
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xA4
	  li        r3, 0x1
	  b         .loc_0x130

	.loc_0xA4:
	  lwz       r3, 0x2CC(r30)
	  li        r4, 0
	  bl        -0x15874
	  lwz       r3, 0x2CC(r30)
	  lfs       f0, 0x2C(r3)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0xC8
	  li        r3, 0
	  b         .loc_0x130

	.loc_0xC8:
	  lfs       f0, -0x5BB0(r2)
	  stfs      f0, 0x4C(r1)
	  stfs      f0, 0x48(r1)
	  stfs      f0, 0x44(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x94(r30)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r30)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x98(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x38(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x38(r1)
	  stfs      f0, 0x44(r1)
	  stfs      f1, 0x48(r1)
	  stfs      f3, 0x4C(r1)
	  lfs       f1, 0x44(r1)
	  lfs       f2, 0x4C(r1)
	  bl        -0x172CC
	  stfs      f1, 0x394(r30)
	  mr        r3, r30
	  lfs       f1, 0x394(r30)
	  lfs       f2, 0xC(r29)
	  bl        0x124E4

	.loc_0x130:
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80135108
 * Size:	00015C
 */
bool TaiTurningAwayAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  stw       r30, 0x70(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x6C(r1)
	  addi      r29, r3, 0
	  bl        -0xFBC
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r30
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x4C
	  li        r3, 0
	  b         .loc_0x140

	.loc_0x4C:
	  lwz       r31, 0x418(r30)
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  bne-      .loc_0x64
	  li        r3, 0x1
	  b         .loc_0x140

	.loc_0x64:
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x5C(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x5C(r1)
	  subi      r0, r3, 0x295C
	  stw       r0, 0x5C(r1)
	  addi      r3, r1, 0x5C
	  stw       r30, 0x60(r1)
	  bl        0x14CF8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xA4
	  li        r3, 0x1
	  b         .loc_0x140

	.loc_0xA4:
	  lwz       r3, 0x2CC(r30)
	  li        r4, 0
	  bl        -0x159C0
	  lwz       r3, 0x2CC(r30)
	  lfs       f0, 0x2C(r3)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0xC8
	  li        r3, 0
	  b         .loc_0x140

	.loc_0xC8:
	  lfs       f0, -0x5BB0(r2)
	  stfs      f0, 0x4C(r1)
	  stfs      f0, 0x48(r1)
	  stfs      f0, 0x44(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x94(r30)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r30)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x98(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x38(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x38(r1)
	  stfs      f0, 0x44(r1)
	  stfs      f1, 0x48(r1)
	  stfs      f3, 0x4C(r1)
	  lfs       f1, 0x44(r1)
	  lfs       f2, 0x4C(r1)
	  bl        -0x17418
	  stfs      f1, 0x394(r30)
	  mr        r3, r30
	  lfs       f1, 0x394(r30)
	  lfs       f0, -0x1CA4(r13)
	  fadds     f0, f1, f0
	  stfs      f0, 0x394(r30)
	  lfs       f1, 0x394(r30)
	  lfs       f2, 0xC(r29)
	  bl        0x12388

	.loc_0x140:
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80135264
 * Size:	000194
 */
bool TaiTraceTurningAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB0(r1)
	  stw       r31, 0xAC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xA8(r1)
	  addi      r30, r3, 0
	  stw       r29, 0xA4(r1)
	  bl        -0x1118
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x4C
	  li        r3, 0
	  b         .loc_0x178

	.loc_0x4C:
	  lwz       r29, 0x418(r31)
	  cmplwi    r29, 0
	  addi      r4, r29, 0
	  bne-      .loc_0x64
	  li        r3, 0x1
	  b         .loc_0x178

	.loc_0x64:
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x98(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x98(r1)
	  subi      r0, r3, 0x295C
	  stw       r0, 0x98(r1)
	  addi      r3, r1, 0x98
	  stw       r31, 0x9C(r1)
	  bl        0x14B9C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xA4
	  li        r3, 0x1
	  b         .loc_0x178

	.loc_0xA4:
	  lwz       r3, 0x2CC(r31)
	  li        r4, 0
	  bl        -0x15B1C
	  lwz       r3, 0x2CC(r31)
	  lfs       f0, 0x2C(r3)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0xC8
	  li        r3, 0
	  b         .loc_0x178

	.loc_0xC8:
	  addi      r29, r29, 0x94
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        0x11FC8
	  lwz       r3, 0x2C4(r31)
	  lfs       f2, -0x5BA8(r2)
	  lwz       r3, 0x84(r3)
	  lfs       f0, -0x1CA8(r13)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f3, 0x98(r3)
	  fmuls     f2, f3, f2
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x110
	  li        r3, 0x1
	  b         .loc_0x178

	.loc_0x110:
	  lfs       f0, -0x5BB0(r2)
	  stfs      f0, 0x80(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f0, 0x78(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x94(r31)
	  lfs       f4, 0x8(r29)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r31)
	  lfs       f2, 0x4(r29)
	  lfs       f1, 0x98(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x68(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x68(r1)
	  stfs      f0, 0x78(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f3, 0x80(r1)
	  lfs       f1, 0x78(r1)
	  lfs       f2, 0x80(r1)
	  bl        -0x175BC
	  stfs      f1, 0x394(r31)
	  mr        r3, r31
	  lfs       f1, 0x394(r31)
	  lfs       f2, 0xC(r30)
	  bl        0x121F4

	.loc_0x178:
	  lwz       r0, 0xB4(r1)
	  lwz       r31, 0xAC(r1)
	  lwz       r30, 0xA8(r1)
	  lwz       r29, 0xA4(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801353F8
 * Size:	0000D0
 */
bool TaiOutOfTraceAngleAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r30, 0x60(r1)
	  mr        r30, r4
	  lwz       r31, 0x418(r4)
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0xB8

	.loc_0x30:
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x58(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x58(r1)
	  subi      r0, r3, 0x295C
	  stw       r0, 0x58(r1)
	  addi      r3, r1, 0x58
	  stw       r30, 0x5C(r1)
	  bl        0x14A3C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x70
	  li        r3, 0
	  b         .loc_0xB8

	.loc_0x70:
	  addi      r4, r31, 0x94
	  addi      r3, r30, 0
	  bl        0x11E90
	  lwz       r3, 0x2C4(r30)
	  lfs       f2, -0x5BA8(r2)
	  lwz       r3, 0x84(r3)
	  lfs       f0, -0x1CA8(r13)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f3, 0x98(r3)
	  fmuls     f2, f3, f2
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xB4
	  li        r3, 0
	  b         .loc_0xB8

	.loc_0xB4:
	  li        r3, 0x1

	.loc_0xB8:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801354C8
 * Size:	000130
 */
bool TaiTurningToTargetPositionAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x78(r1)
	  addi      r30, r3, 0
	  bl        -0x1378
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x118

	.loc_0x48:
	  lwz       r3, 0x2CC(r31)
	  li        r4, 0
	  bl        -0x15D24
	  lwz       r3, 0x2CC(r31)
	  lfs       f0, 0x2C(r3)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x6C
	  li        r3, 0
	  b         .loc_0x118

	.loc_0x6C:
	  addi      r3, r31, 0
	  addi      r4, r31, 0x388
	  bl        0x11DC4
	  lwz       r3, 0x2C4(r31)
	  lfs       f2, -0x5BA8(r2)
	  lwz       r3, 0x84(r3)
	  lfs       f0, -0x1CA8(r13)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f3, 0x98(r3)
	  fmuls     f2, f3, f2
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xB0
	  li        r3, 0x1
	  b         .loc_0x118

	.loc_0xB0:
	  lfs       f0, -0x5BB0(r2)
	  stfs      f0, 0x6C(r1)
	  stfs      f0, 0x68(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x94(r31)
	  lfs       f4, 0x390(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r31)
	  lfs       f2, 0x38C(r31)
	  lfs       f1, 0x98(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x5C(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x5C(r1)
	  stfs      f0, 0x64(r1)
	  stfs      f1, 0x68(r1)
	  stfs      f3, 0x6C(r1)
	  lfs       f1, 0x64(r1)
	  lfs       f2, 0x6C(r1)
	  bl        -0x177C0
	  stfs      f1, 0x394(r31)
	  mr        r3, r31
	  lfs       f1, 0x394(r31)
	  lfs       f2, 0xC(r30)
	  bl        0x11FF0

	.loc_0x118:
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
 * Address:	801355F8
 * Size:	00002C
 */
bool TaiRotatingAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lfs       f1, 0x8(r3)
	  mr        r3, r4
	  bl        0x12088
	  li        r3, 0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80135624
 * Size:	0000AC
 */
bool TaiRunningAwayToTargetDirectionAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stfd      f30, 0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x30(r1)
	  addi      r30, r3, 0
	  bl        -0x14DC
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x50
	  li        r3, 0
	  b         .loc_0x8C

	.loc_0x50:
	  lfs       f30, 0x394(r31)
	  fmr       f1, f30
	  bl        0xE64D8
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE6660
	  lfs       f0, 0xC(r30)
	  li        r3, 0
	  lfs       f3, -0x11A8(r13)
	  fmuls     f2, f0, f1
	  fmuls     f1, f0, f3
	  fmuls     f0, f0, f31
	  stfs      f2, 0xA4(r31)
	  stfs      f1, 0xA8(r31)
	  stfs      f0, 0xAC(r31)

	.loc_0x8C:
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
 * Address:	801356D0
 * Size:	00036C
 */
bool TaiRunningAwayAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x128(r1)
	  stfd      f31, 0x120(r1)
	  stfd      f30, 0x118(r1)
	  stfd      f29, 0x110(r1)
	  stmw      r23, 0xEC(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  bl        -0x1588
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r30
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x50
	  li        r3, 0
	  b         .loc_0x34C

	.loc_0x50:
	  lfs       f1, -0x5BB0(r2)
	  addi      r3, r1, 0xD8
	  fmr       f2, f1
	  fmr       f3, f1
	  bl        -0x18854
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0xD0(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0xD0(r1)
	  subi      r0, r3, 0x295C
	  stw       r0, 0xD0(r1)
	  addi      r3, r1, 0xB4
	  addi      r4, r1, 0xC8
	  stw       r30, 0xD4(r1)
	  lwz       r5, 0x2C4(r30)
	  lwz       r5, 0x84(r5)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f30, 0x18(r5)
	  bl        -0x19F00
	  lfs       f1, -0x5BB0(r2)
	  fmr       f3, f30
	  lfs       f2, -0x5BA4(r2)
	  addi      r3, r1, 0xB4
	  fmr       f4, f1
	  bl        -0x19E74
	  lwz       r31, 0x3068(r13)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5BB0(r2)
	  addi      r23, r3, 0
	  addi      r27, r30, 0x94
	  addi      r26, r1, 0x50
	  addi      r25, r1, 0x4C
	  addi      r24, r1, 0x48
	  b         .loc_0x29C

	.loc_0xF8:
	  cmpwi     r23, -0x1
	  bne-      .loc_0x120
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x13C

	.loc_0x120:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r23
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x13C:
	  cmplwi    r28, 0
	  addi      r4, r28, 0
	  beq-      .loc_0x2F8
	  addi      r3, r1, 0xD0
	  bl        0x14674
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x280
	  stfs      f31, 0x70(r1)
	  addi      r28, r28, 0x94
	  addi      r4, r24, 0
	  stfs      f31, 0x6C(r1)
	  addi      r5, r25, 0
	  addi      r6, r26, 0
	  stfs      f31, 0x68(r1)
	  addi      r3, r1, 0x68
	  lfs       f1, 0x8(r28)
	  lfs       f0, 0x8(r27)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x50(r1)
	  lfs       f1, 0x4(r28)
	  lfs       f0, 0x4(r27)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4C(r1)
	  lfs       f1, 0x0(r28)
	  lfs       f0, 0x0(r27)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x48(r1)
	  bl        -0xD81EC
	  lfs       f1, 0x68(r1)
	  lfs       f0, 0x6C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x70(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x127C5C
	  fcmpo     cr0, f1, f30
	  fmr       f29, f1
	  cror      2, 0, 0x2
	  bne-      .loc_0x280
	  addi      r3, r1, 0x9C
	  bl        -0x18A60
	  lfs       f1, 0x0(r27)
	  addi      r3, r1, 0x9C
	  lfs       f0, 0x0(r28)
	  lfs       f3, 0x4(r27)
	  lfs       f2, 0x4(r28)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r27)
	  lfs       f1, 0x8(r28)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x9C(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0xA0(r1)
	  stfs      f0, 0xA4(r1)
	  bl        -0x188D4
	  addi      r3, r1, 0xB4
	  fmr       f1, f29
	  bl        -0x19F4C
	  lfs       f0, 0x9C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0xA0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xA0(r1)
	  lfs       f0, 0xA4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xA4(r1)
	  lfs       f1, 0xD8(r1)
	  lfs       f0, 0x9C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xD8(r1)
	  lfs       f1, 0xDC(r1)
	  lfs       f0, 0xA0(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xDC(r1)
	  lfs       f1, 0xE0(r1)
	  lfs       f0, 0xA4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE0(r1)

	.loc_0x280:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r23
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r23, r3

	.loc_0x29C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r23
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2C4
	  li        r0, 0x1
	  b         .loc_0x2F0

	.loc_0x2C4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r23
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2EC
	  li        r0, 0x1
	  b         .loc_0x2F0

	.loc_0x2EC:
	  li        r0, 0

	.loc_0x2F0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xF8

	.loc_0x2F8:
	  lfs       f0, -0x5BB0(r2)
	  addi      r3, r1, 0xD8
	  stfs      f0, 0xDC(r1)
	  bl        -0x189BC
	  lfs       f1, 0xC(r29)
	  li        r3, 0
	  lfs       f0, 0xD8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xD8(r1)
	  lfs       f0, 0xDC(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0xE0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xE0(r1)
	  lfs       f0, 0xD8(r1)
	  stfs      f0, 0xA4(r30)
	  lfs       f0, 0xDC(r1)
	  stfs      f0, 0xA8(r30)
	  lfs       f0, 0xE0(r1)
	  stfs      f0, 0xAC(r30)

	.loc_0x34C:
	  lmw       r23, 0xEC(r1)
	  lwz       r0, 0x12C(r1)
	  lfd       f31, 0x120(r1)
	  lfd       f30, 0x118(r1)
	  lfd       f29, 0x110(r1)
	  addi      r1, r1, 0x128
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80135A3C
 * Size:	000044
 */
bool TaiWatchOffTerritoryCenterAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x2C8(r4)
	  addi      r4, r5, 0x10
	  bl        0x118AC
	  lfs       f2, -0x5BA0(r2)
	  lfs       f0, -0x1CA4(r13)
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm    r3,r0,2,31,31
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80135A80
 * Size:	000020
 */
void TaiTargetNestAction::start(Teki& teki)
{
	// float from pointer and vec3f?
	// void* ptr = teki._2C8;
	// teki._388.x = ptr->_10;
	// teki._388.y = ptr->_04;
	// teki._388.z = ptr->_08;
	/*
	.loc_0x0:
	  lwz       r3, 0x2C8(r4)
	  lfsu      f0, 0x10(r3)
	  stfs      f0, 0x388(r4)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x38C(r4)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x390(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80135AA0
 * Size:	000180
 */
bool TaiHeadOnCollisionAvoidanceAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x15C
	  lwz       r3, 0x8(r4)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x37
	  bne-      .loc_0x15C
	  lwz       r31, 0x4(r4)
	  lwz       r3, 0x320(r3)
	  lwz       r0, 0x320(r31)
	  cmpw      r3, r0
	  bne-      .loc_0x15C
	  addi      r3, r1, 0x44
	  bl        -0x18CA0
	  lfs       f30, 0xA0(r31)
	  fmr       f1, f30
	  bl        0xE6054
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE61DC
	  stfs      f1, 0x44(r1)
	  addi      r3, r1, 0x38
	  lfs       f0, -0x11A8(r13)
	  stfs      f0, 0x48(r1)
	  stfs      f31, 0x4C(r1)
	  bl        -0x18CD0
	  lfs       f1, -0x5BB0(r2)
	  addi      r3, r1, 0x2C
	  lfs       f2, -0x5BAC(r2)
	  fmr       f3, f1
	  bl        -0x18C5C
	  lfs       f0, 0x48(r1)
	  addi      r3, r1, 0x38
	  lfs       f2, 0x34(r1)
	  lfs       f3, 0x4C(r1)
	  lfs       f1, 0x30(r1)
	  fmuls     f5, f0, f2
	  lfs       f6, 0x2C(r1)
	  fmuls     f4, f3, f1
	  lfs       f7, 0x44(r1)
	  fmuls     f0, f0, f6
	  fmuls     f1, f7, f1
	  fsubs     f4, f5, f4
	  fmuls     f3, f3, f6
	  fmuls     f2, f7, f2
	  fsubs     f0, f1, f0
	  stfs      f4, 0x38(r1)
	  fsubs     f1, f3, f2
	  stfs      f1, 0x3C(r1)
	  stfs      f0, 0x40(r1)
	  bl        -0x18B70
	  lfs       f1, 0x8(r30)
	  lfs       f0, 0x38(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x40(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x40(r1)
	  lfs       f1, 0x38(r1)
	  lfs       f0, 0xA4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x38(r1)
	  lfs       f1, 0x3C(r1)
	  lfs       f0, 0xA8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C(r1)
	  lfs       f1, 0x40(r1)
	  lfs       f0, 0xAC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0x38(r1)
	  stfs      f0, 0x70(r31)
	  lfs       f0, 0x3C(r1)
	  stfs      f0, 0x74(r31)
	  lfs       f0, 0x40(r1)
	  stfs      f0, 0x78(r31)

	.loc_0x15C:
	  lwz       r0, 0x74(r1)
	  li        r3, 0
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}
