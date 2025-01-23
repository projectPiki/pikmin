#include "TAI/ReactionActions.h"
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
 * Address:	8013EBD8
 * Size:	00001C
 */
bool TaiDeadAction::act(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x58(r4)
	  lfs       f0, -0x59E0(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EBF4
 * Size:	00000C
 */
void TaiLifeZeroAction::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x59E0(r2)
	  stfs      f0, 0x58(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EC00
 * Size:	000014
 */
void TaiLifeDamageAction::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x58(r4)
	  lfs       f0, 0x8(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EC14
 * Size:	000030
 */
void TaiDyeAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x178(r12)
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
 * Address:	8013EC44
 * Size:	000058
 */
void TaiStartDyingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  addi      r3, r31, 0
	  bl        0x720C
	  mr        r3, r31
	  bl        0x7000
	  mr        r3, r31
	  bl        0x6FD4
	  mr        r3, r31
	  lwz       r4, -0x9D0(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EC9C
 * Size:	000024
 */
void TaiSpawnItemsAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x71BC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013ECC0
 * Size:	000024
 */
void TaiCreateDeadEffectAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x6F94
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013ECE4
 * Size:	00004C
 */
void TaiDyingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0xACE0
	  mr        r3, r31
	  lwz       r4, -0x9C4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x59E0(r2)
	  stfs      f0, 0x58(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013ED30
 * Size:	00004C
 */
bool TaiDyingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2CC(r4)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x38
	  mr        r3, r4
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x178(r12)
	  mtlr      r12
	  blrl
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
 * Address:	8013ED7C
 * Size:	00000C
 */
void TaiDamageCountResetAction::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x59E0(r2)
	  stfs      f0, 0x340(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013ED88
 * Size:	000040
 */
bool TaiDamageCountAction::act(Teki&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x8(r3)
	  lfd       f1, -0x59D8(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f2, 0x340(r4)
	  stw       r3, 0x14(r1)
	  stw       r0, 0x10(r1)
	  lfd       f0, 0x10(r1)
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EDC8
 * Size:	000018
 */
bool TaiDamageScaleAction::act(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x8(r3)
	  li        r3, 0
	  lfs       f1, 0x33C(r4)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x33C(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EDE0
 * Size:	000024
 */
bool TaiDamageAction::act(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x33C(r4)
	  lfs       f0, -0x59E0(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x1C
	  li        r3, 0
	  blr

	.loc_0x1C:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EE04
 * Size:	000088
 */
bool TaiSimultaneousDamageAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r4
	  lfs       f0, -0x59E0(r2)
	  lfs       f1, 0x33C(r4)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x74

	.loc_0x30:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x18C(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2C4(r31)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r4, 0x84(r4)
	  lwz       r12, 0x190(r12)
	  lwz       r4, 0x4(r4)
	  mtlr      r12
	  lwz       r4, 0x0(r4)
	  lfs       f2, 0x7C(r4)
	  lfs       f1, 0x78(r4)
	  blrl
	  li        r3, 0x1

	.loc_0x74:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EE8C
 * Size:	0000D8
 */
bool TaiCounterattackSimultaneousDamageAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  mr        r30, r4
	  lfs       f0, -0x59E0(r2)
	  lfs       f1, 0x33C(r4)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x34
	  li        r3, 0
	  b         .loc_0xC0

	.loc_0x34:
	  lwz       r31, 0x41C(r30)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x7BFC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7C
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  beq-      .loc_0x68
	  bl        -0x5AB7C
	  li        r0, 0
	  stw       r0, 0x418(r30)

	.loc_0x68:
	  stw       r31, 0x418(r30)
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x7C
	  bl        -0x5ABA8

	.loc_0x7C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x18C(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2C4(r30)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r4, 0x84(r4)
	  lwz       r12, 0x190(r12)
	  lwz       r4, 0x4(r4)
	  mtlr      r12
	  lwz       r4, 0x0(r4)
	  lfs       f2, 0x7C(r4)
	  lfs       f1, 0x78(r4)
	  blrl
	  li        r3, 0x1

	.loc_0xC0:
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
 * Address:	8013EF64
 * Size:	000040
 */
void TaiDamagingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0xAF60
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x18C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EFA4
 * Size:	000020
 */
bool TaiDamagingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2CC(r4)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x18
	  li        r3, 0x1
	  blr

	.loc_0x18:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013EFC4
 * Size:	000098
 */
bool TaiTargetNearestAssailantAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lfs       f0, -0x59E0(r2)
	  lfs       f1, 0x33C(r4)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x80

	.loc_0x34:
	  lwz       r31, 0x41C(r30)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x7AC4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7C
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  beq-      .loc_0x68
	  bl        -0x5ACB4
	  li        r0, 0
	  stw       r0, 0x418(r30)

	.loc_0x68:
	  stw       r31, 0x418(r30)
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x7C
	  bl        -0x5ACE0

	.loc_0x7C:
	  li        r3, 0x1

	.loc_0x80:
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
 * Address:	8013F05C
 * Size:	00013C
 */
bool TaiTargetNearestCollisionAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  stw       r28, 0x50(r1)
	  lwz       r0, 0x0(r4)
	  lwz       r31, 0x4(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x11C

	.loc_0x34:
	  lis       r3, 0x802B
	  lwz       r30, 0x8(r4)
	  subi      r7, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r7, 0x38(r1)
	  addi      r6, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r6, 0x38(r1)
	  subi      r0, r3, 0x27F0
	  stw       r0, 0x38(r1)
	  lis       r5, 0x802D
	  subi      r0, r5, 0x295C
	  lwz       r8, 0x4(r4)
	  addi      r3, r1, 0x3C
	  addi      r4, r30, 0
	  stw       r7, 0x3C(r1)
	  addi      r28, r1, 0x38
	  li        r29, 0
	  stw       r6, 0x3C(r1)
	  stw       r0, 0x3C(r1)
	  stw       r8, 0x40(r1)
	  lwz       r12, 0x3C(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC4
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC4
	  li        r29, 0x1

	.loc_0xC4:
	  rlwinm.   r0,r29,0,24,31
	  bne-      .loc_0xD4
	  li        r3, 0
	  b         .loc_0x11C

	.loc_0xD4:
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        0x7990
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x118
	  lwz       r3, 0x418(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x104
	  beq-      .loc_0x104
	  bl        -0x5ADE8
	  li        r0, 0
	  stw       r0, 0x418(r31)

	.loc_0x104:
	  stw       r30, 0x418(r31)
	  lwz       r3, 0x418(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x118
	  bl        -0x5AE14

	.loc_0x118:
	  li        r3, 0x1

	.loc_0x11C:
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
 * Address:	8013F198
 * Size:	000040
 */
bool TaiStickedAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  addi      r3, r1, 0x18
	  bl        -0xAE524
	  lwz       r4, 0x20(r1)
	  li        r3, 0
	  eqv       r0, r4, r3
	  subc      r3, r3, r4
	  rlwinm    r0,r0,1,31,31
	  addze     r3, r0
	  rlwinm    r3,r3,0,31,31
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013F1D8
 * Size:	000050
 */
bool TaiSmashedAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x3C
	  lwz       r3, 0x8(r4)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x3C
	  bl        -0x76CAC
	  cmpwi     r3, 0xE
	  bne-      .loc_0x3C
	  li        r3, 0x1
	  b         .loc_0x40

	.loc_0x3C:
	  li        r3, 0

	.loc_0x40:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013F228
 * Size:	000070
 */
void TaiBeingPressedAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r4, -0x9B0(r13)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9C4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9C8(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013F298
 * Size:	00001C
 */
bool TaiPressedAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013F2B4
 * Size:	00001C
 */
void TaiWarnAction::start(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x6C(r3)
	  stfs      f0, 0x3D4(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013F2D0
 * Size:	000034
 */
bool TaiDangerLifeAction::act(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x33C(r4)
	  li        r0, 0
	  lfs       f0, -0x59E0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2C
	  lfs       f1, 0x58(r4)
	  lfs       f0, 0x8(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x2C
	  li        r0, 0x1

	.loc_0x2C:
	  mr        r3, r0
	  blr
	*/
}
