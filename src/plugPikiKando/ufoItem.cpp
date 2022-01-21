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
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E7018
 * Size:	0000B4
 */
void UfoItem::insideSafeArea(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  mr        r31, r4
	  lfs       f3, 0x9C(r3)
	  lfs       f4, 0x8(r4)
	  lfs       f2, 0x0(r4)
	  lfs       f1, 0x94(r3)
	  fsubs     f3, f4, f3
	  lfs       f0, -0x6640(r2)
	  fsubs     f2, f2, f1
	  fmuls     f1, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x4C
	  li        r3, 0
	  b         .loc_0xA0

	.loc_0x4C:
	  mr        r4, r3
	  lwz       r12, 0x0(r3)
	  addi      r3, r1, 0x3C
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0x44(r1)
	  lfs       f0, 0x8(r31)
	  lfs       f2, 0x3C(r1)
	  lfs       f1, 0x0(r31)
	  fsubs     f3, f3, f0
	  lfs       f0, -0x663C(r2)
	  fsubs     f2, f2, f1
	  fmuls     f1, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x9C
	  li        r3, 0
	  b         .loc_0xA0

	.loc_0x9C:
	  li        r3, 0x1

	.loc_0xA0:
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E70CC
 * Size:	000124
 */
void UfoItem::setSpotTurn(bool)
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
	  addi      r4, r30, 0
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x10
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x10(r1)
	  lis       r3, 0x676F
	  lfs       f1, 0x14(r1)
	  addi      r4, r3, 0x6C31
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x18(r1)
	  stfs      f1, 0x24(r1)
	  stfs      f0, 0x28(r1)
	  lwz       r3, 0x220(r30)
	  bl        -0x5DA14
	  rlwinm.   r0,r31,0,24,31
	  bne-      .loc_0xB4
	  lbz       r0, 0x3CA(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xB4
	  lwz       r4, 0x3CC(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x94
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xBA470
	  li        r0, 0
	  stw       r0, 0x3CC(r30)

	.loc_0x94:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x20
	  li        r4, 0x1
	  li        r6, 0
	  li        r7, 0
	  bl        0xB59C4
	  stw       r3, 0x3CC(r30)
	  b         .loc_0x108

	.loc_0xB4:
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x108
	  lbz       r0, 0x3CA(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x108
	  lwz       r4, 0x3CC(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0xEC
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xBA418
	  li        r0, 0
	  stw       r0, 0x3CC(r30)

	.loc_0xEC:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x20
	  li        r4, 0x2
	  li        r6, 0
	  li        r7, 0
	  bl        0xB596C
	  stw       r3, 0x3CC(r30)

	.loc_0x108:
	  stb       r31, 0x3CA(r30)
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
 * Address:	800E71F0
 * Size:	00014C
 */
void UfoItem::setSpotActive(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x50(r1)
	  li        r30, 0
	  stb       r30, 0x3CA(r3)
	  addi      r3, r1, 0x1C
	  stb       r4, 0x3C9(r31)
	  mr        r4, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x1C(r1)
	  lis       r3, 0x676F
	  lfs       f1, 0x20(r1)
	  addi      r4, r3, 0x6C31
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0x24(r1)
	  stfs      f1, 0x44(r1)
	  stfs      f0, 0x48(r1)
	  lwz       r3, 0x220(r31)
	  bl        -0x5DB40
	  lbz       r0, 0x3C9(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xF0
	  lwz       r4, 0x3CC(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x90
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xBA34C
	  stw       r30, 0x3CC(r31)

	.loc_0x90:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x40
	  li        r4, 0x1
	  li        r6, 0
	  li        r7, 0
	  bl        0xB58A4
	  stw       r3, 0x3CC(r31)
	  lwz       r4, 0x3D0(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xD0
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xBA310
	  li        r0, 0
	  stw       r0, 0x3D0(r31)

	.loc_0xD0:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x40
	  li        r4, 0x3
	  li        r6, 0
	  li        r7, 0
	  bl        0xB5864
	  stw       r3, 0x3D0(r31)
	  b         .loc_0x134

	.loc_0xF0:
	  lwz       r4, 0x3CC(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x110
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xBA2CC
	  stw       r30, 0x3CC(r31)

	.loc_0x110:
	  lwz       r4, 0x3D0(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x134
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xBA2AC
	  li        r0, 0
	  stw       r0, 0x3D0(r31)

	.loc_0x134:
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
 * Address:	800E733C
 * Size:	0000B8
 */
void UfoItem::setTroubleEffect(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,24,31
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  stb       r4, 0x428(r3)
	  beq-      .loc_0x60
	  lfs       f0, -0x6638(r2)
	  li        r0, -0x1
	  addi      r3, r29, 0
	  stfs      f0, 0x42C(r29)
	  li        r4, 0
	  stw       r0, 0x430(r29)
	  bl        .loc_0xB8
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        .loc_0xB8
	  addi      r3, r29, 0
	  li        r4, 0x5
	  bl        .loc_0xB8
	  b         .loc_0x9C

	.loc_0x60:
	  addi      r30, r29, 0
	  li        r29, 0
	  li        r31, 0

	.loc_0x6C:
	  lwz       r4, 0x4C4(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x8C
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xBA204
	  stw       r31, 0x4C4(r30)

	.loc_0x8C:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x6
	  addi      r30, r30, 0x4
	  blt+      .loc_0x6C

	.loc_0x9C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0xB8:
	*/
}

/*
 * --INFO--
 * Address:	800E73F4
 * Size:	0000D4
 */
void UfoItem::startTroubleEffectOne(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r8, r5, 0x25A4
	  mulli     r5, r4, 0xC
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  rlwinm    r31,r4,2,0,29
	  li        r7, 0
	  stw       r30, 0x38(r1)
	  addi      r30, r5, 0x47C
	  stw       r29, 0x34(r1)
	  addi      r29, r1, 0x14
	  add       r29, r29, r31
	  stw       r28, 0x30(r1)
	  mr        r28, r3
	  add       r30, r28, r30
	  lwz       r6, 0x0(r8)
	  lwz       r0, 0x4(r8)
	  lwz       r3, 0x3180(r13)
	  stw       r6, 0x14(r1)
	  li        r6, 0
	  stw       r0, 0x18(r1)
	  lwz       r5, 0x8(r8)
	  lwz       r0, 0xC(r8)
	  stw       r5, 0x1C(r1)
	  addi      r5, r30, 0
	  stw       r0, 0x20(r1)
	  lwz       r4, 0x10(r8)
	  lwz       r0, 0x14(r8)
	  stw       r4, 0x24(r1)
	  stw       r0, 0x28(r1)
	  lwz       r4, 0x0(r29)
	  bl        0xB56C0
	  add       r4, r28, r31
	  stw       r3, 0x4C4(r4)
	  lwz       r3, 0x4C4(r4)
	  stw       r30, 0x18(r3)
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0x10B
	  bne-      .loc_0xB4
	  addi      r3, r28, 0
	  addi      r4, r28, 0
	  li        r5, 0xDF
	  bl        -0x5CEF0

	.loc_0xB4:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  lwz       r28, 0x30(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E74C8
 * Size:	00024C
 */
void UfoItem::updateTroubleEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  mr        r31, r3
	  stw       r30, 0x70(r1)
	  lbz       r0, 0x428(r3)
	  lis       r3, 0x8022
	  addi      r4, r3, 0x2598
	  cmplwi    r0, 0
	  beq-      .loc_0x234
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x6634(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x42C(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x42C(r31)
	  lwz       r3, 0x430(r31)
	  lwz       r0, -0x36A8(r13)
	  addi      r6, r3, 0x1
	  cmpw      r6, r0
	  bge-      .loc_0x210
	  lis       r3, 0x802C
	  lfs       f1, 0x42C(r31)
	  rlwinm    r5,r6,2,0,29
	  subi      r0, r3, 0x4014
	  add       r3, r0, r5
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x210
	  stw       r6, 0x430(r31)
	  lwz       r0, 0x430(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x124
	  bge-      .loc_0xA0
	  cmpwi     r0, 0
	  bge-      .loc_0xAC
	  b         .loc_0x210

	.loc_0xA0:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x210
	  b         .loc_0x19C

	.loc_0xAC:
	  lwz       r6, 0xC(r4)
	  addi      r30, r31, 0x494
	  lwz       r0, 0x10(r4)
	  mr        r5, r30
	  lwz       r3, 0x3180(r13)
	  stw       r6, 0x50(r1)
	  li        r6, 0
	  li        r7, 0
	  stw       r0, 0x54(r1)
	  lwz       r8, 0x14(r4)
	  lwz       r0, 0x18(r4)
	  stw       r8, 0x58(r1)
	  stw       r0, 0x5C(r1)
	  lwz       r8, 0x1C(r4)
	  lwz       r0, 0x20(r4)
	  stw       r8, 0x60(r1)
	  stw       r0, 0x64(r1)
	  lwz       r4, 0x58(r1)
	  bl        0xB557C
	  stw       r3, 0x4CC(r31)
	  lwz       r3, 0x4CC(r31)
	  stw       r30, 0x18(r3)
	  lwz       r0, 0x58(r1)
	  cmpwi     r0, 0x10B
	  bne-      .loc_0x210
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xDF
	  bl        -0x5D030
	  b         .loc_0x210

	.loc_0x124:
	  lwz       r6, 0xC(r4)
	  addi      r30, r31, 0x4AC
	  lwz       r0, 0x10(r4)
	  mr        r5, r30
	  lwz       r3, 0x3180(r13)
	  stw       r6, 0x38(r1)
	  li        r6, 0
	  li        r7, 0
	  stw       r0, 0x3C(r1)
	  lwz       r8, 0x14(r4)
	  lwz       r0, 0x18(r4)
	  stw       r8, 0x40(r1)
	  stw       r0, 0x44(r1)
	  lwz       r8, 0x1C(r4)
	  lwz       r0, 0x20(r4)
	  stw       r8, 0x48(r1)
	  stw       r0, 0x4C(r1)
	  lwz       r4, 0x48(r1)
	  bl        0xB5504
	  stw       r3, 0x4D4(r31)
	  lwz       r3, 0x4D4(r31)
	  stw       r30, 0x18(r3)
	  lwz       r0, 0x48(r1)
	  cmpwi     r0, 0x10B
	  bne-      .loc_0x210
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xDF
	  bl        -0x5D0A8
	  b         .loc_0x210

	.loc_0x19C:
	  lwz       r6, 0xC(r4)
	  addi      r30, r31, 0x4A0
	  lwz       r0, 0x10(r4)
	  mr        r5, r30
	  lwz       r3, 0x3180(r13)
	  stw       r6, 0x20(r1)
	  li        r6, 0
	  li        r7, 0
	  stw       r0, 0x24(r1)
	  lwz       r8, 0x14(r4)
	  lwz       r0, 0x18(r4)
	  stw       r8, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  lwz       r8, 0x1C(r4)
	  lwz       r0, 0x20(r4)
	  stw       r8, 0x30(r1)
	  stw       r0, 0x34(r1)
	  lwz       r4, 0x2C(r1)
	  bl        0xB548C
	  stw       r3, 0x4D0(r31)
	  lwz       r3, 0x4D0(r31)
	  stw       r30, 0x18(r3)
	  lwz       r0, 0x2C(r1)
	  cmpwi     r0, 0x10B
	  bne-      .loc_0x210
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xDF
	  bl        -0x5D120

	.loc_0x210:
	  lfs       f1, 0x42C(r31)
	  lfs       f0, -0x6630(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x234
	  li        r0, -0x1
	  stw       r0, 0x430(r31)
	  lfs       f0, -0x6638(r2)
	  stfs      f0, 0x42C(r31)

	.loc_0x234:
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E7714
 * Size:	00012C
 */
void UfoItem::startConeEffect(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  addi      r31, r3, 0
	  addi      r4, r31, 0
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0x24
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x24(r1)
	  mr        r4, r31
	  lfs       f1, 0x28(r1)
	  addi      r3, r1, 0x18
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x2C(r1)
	  stfs      f1, 0x6C(r1)
	  stfs      f0, 0x70(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x6638(r2)
	  li        r0, 0x18
	  lfs       f3, 0x18(r1)
	  addi      r4, r1, 0x30
	  stfs      f0, 0x38(r1)
	  lfs       f2, 0x1C(r1)
	  stfs      f0, 0x34(r1)
	  lfs       f1, 0x20(r1)
	  stfs      f3, 0x5C(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f2, 0x60(r1)
	  stfs      f0, 0x44(r1)
	  stfs      f1, 0x64(r1)
	  stfs      f0, 0x40(r1)
	  stfs      f0, 0x3C(r1)
	  lwz       r3, 0x68(r1)
	  lwz       r5, 0x6C(r1)
	  stw       r3, 0x30(r1)
	  lwz       r3, 0x70(r1)
	  stw       r5, 0x34(r1)
	  lwz       r5, 0x5C(r1)
	  stw       r3, 0x38(r1)
	  lwz       r3, 0x60(r1)
	  stw       r5, 0x3C(r1)
	  stw       r3, 0x40(r1)
	  lwz       r3, 0x64(r1)
	  stw       r3, 0x44(r1)
	  lfs       f0, -0x662C(r2)
	  stfs      f0, 0x54(r1)
	  stw       r0, 0x52C(r31)
	  lwz       r3, 0x52C(r31)
	  bl        0x2CAF4
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0xEC
	  addi      r5, r5, 0x2B8

	.loc_0xEC:
	  addi      r3, r1, 0x10
	  li        r4, 0x1
	  bl        0x37784
	  addi      r5, r3, 0
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x2500
	  lfs       f1, -0x6634(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x2528
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E7840
 * Size:	000024
 */
void UfoItem::finishConeEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x52C(r3)
	  bl        0x2CAD4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void UfoItem::initLevelFlag(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E7864
 * Size:	000158
 */
void UfoItem::startLevelFlag(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  bl        .loc_0x158
	  lfs       f0, 0x94(r30)
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x9C(r30)
	  lwz       r3, 0x2F6C(r13)
	  stfs      f0, 0x3C(r1)
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0x5
	  bne-      .loc_0xDC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x34
	  li        r4, 0xF0
	  li        r6, 0
	  li        r7, 0
	  bl        0xB5278
	  lfs       f0, -0x36A4(r13)
	  addi      r5, r1, 0x34
	  lfs       f1, -0x36A0(r13)
	  li        r4, 0xF1
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x369C(r13)
	  li        r6, 0
	  stfs      f1, 0x2C(r1)
	  li        r7, 0
	  stfs      f0, 0x30(r1)
	  lwz       r8, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r8, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x1E4(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0xB5230
	  lfs       f0, -0x3698(r13)
	  lfs       f1, -0x3694(r13)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, -0x3690(r13)
	  stfs      f1, 0x20(r1)
	  stfs      f0, 0x24(r1)
	  lwz       r4, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x1E4(r3)
	  b         .loc_0x134

	.loc_0xDC:
	  lfs       f1, 0x38(r1)
	  addi      r5, r1, 0x34
	  lfs       f0, -0x6628(r2)
	  li        r4, 0x12B
	  li        r6, 0
	  fadds     f0, f1, f0
	  li        r7, 0
	  stfs      f0, 0x38(r1)
	  lwz       r3, 0x3180(r13)
	  bl        0xB51D4
	  lfs       f0, -0x368C(r13)
	  lfs       f1, -0x3688(r13)
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0x3684(r13)
	  stfs      f1, 0x14(r1)
	  stfs      f0, 0x18(r1)
	  lwz       r4, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x18(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0x134:
	  addi      r3, r30, 0x524
	  addi      r4, r31, 0
	  bl        0x253C
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr

	.loc_0x158:
	*/
}

/*
 * --INFO--
 * Address:	800E79BC
 * Size:	000078
 */
void UfoItem::lightLevelFlag(int)
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
	  mr.       r29, r4
	  lfs       f31, -0x6638(r2)
	  ble-      .loc_0x2C
	  lfs       f31, -0x6634(r2)

	.loc_0x2C:
	  li        r30, 0
	  rlwinm    r0,r30,4,0,27
	  add       r31, r3, r0

	.loc_0x38:
	  addi      r3, r31, 0x58C
	  addi      r4, r29, 0
	  bl        0x3E4
	  addi      r30, r30, 0x1
	  stfs      f31, 0x594(r31)
	  cmpwi     r30, 0x4
	  addi      r31, r31, 0x10
	  blt+      .loc_0x38
	  lwz       r0, 0x2C(r1)
	  lfd       f31, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E7A34
 * Size:	000390
 */
void UfoItem::setJetEffect(int, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r4, 0
	  stw       r0, 0x4(r1)
	  lis       r6, 0x802C
	  stwu      r1, -0xA0(r1)
	  stmw      r21, 0x74(r1)
	  addi      r21, r3, 0
	  addi      r25, r5, 0
	  subi      r29, r6, 0x4020
	  ble-      .loc_0x320
	  extsh     r0, r4
	  lis       r3, 0x8022
	  sth       r0, 0x4DC(r21)
	  addi      r6, r3, 0x25BC
	  lwz       r5, 0x0(r6)
	  lis       r3, 0x8022
	  lwz       r0, 0x4(r6)
	  addi      r4, r3, 0x25D4
	  lwz       r3, 0x2F6C(r13)
	  stw       r5, 0x54(r1)
	  li        r23, 0
	  addi      r7, r3, 0x10
	  stw       r0, 0x58(r1)
	  lwz       r3, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r3, 0x5C(r1)
	  stw       r0, 0x60(r1)
	  lwz       r3, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r3, 0x64(r1)
	  stw       r0, 0x68(r1)
	  lbz       r5, 0x0(r7)
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  subi      r24, r5, 0x2
	  stw       r3, 0x44(r1)
	  stw       r0, 0x48(r1)
	  lwz       r3, 0x8(r4)
	  lwz       r0, 0xC(r4)
	  stw       r3, 0x4C(r1)
	  stw       r0, 0x50(r1)
	  lbz       r0, 0x0(r7)
	  cmplwi    r0, 0x1
	  bgt-      .loc_0xB8
	  li        r24, 0x4
	  li        r23, 0x1

	.loc_0xB8:
	  addi      r27, r21, 0
	  li        r28, 0
	  li        r22, 0

	.loc_0xC4:
	  li        r30, 0
	  addi      r26, r27, 0

	.loc_0xCC:
	  lwz       r4, 0x4E0(r26)
	  cmplwi    r4, 0
	  beq-      .loc_0xEC
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xB9AAC
	  stw       r22, 0x4E0(r26)

	.loc_0xEC:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x4
	  addi      r26, r26, 0x4
	  blt+      .loc_0xCC
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x4
	  addi      r27, r27, 0x10
	  blt+      .loc_0xC4
	  li        r22, 0
	  rlwinm    r31,r25,0,24,31

	.loc_0x114:
	  li        r25, 0
	  mullw     r27, r25, r23
	  rlwinm    r0,r25,2,0,29
	  addi      r28, r1, 0x44
	  addi      r26, r21, 0
	  add       r28, r28, r0

	.loc_0x12C:
	  lwz       r3, 0x220(r21)
	  lwz       r4, 0x0(r28)
	  bl        -0x5E458
	  cmpwi     r22, 0x2
	  addi      r30, r3, 0
	  beq-      .loc_0x218
	  bge-      .loc_0x158
	  cmpwi     r22, 0
	  beq-      .loc_0x164
	  bge-      .loc_0x1A4
	  b         .loc_0x2F8

	.loc_0x158:
	  cmpwi     r22, 0x4
	  bge-      .loc_0x2F8
	  b         .loc_0x270

	.loc_0x164:
	  add       r0, r24, r27
	  lwz       r3, 0x3180(r13)
	  rlwinm    r0,r0,4,0,27
	  add       r4, r29, r0
	  lwz       r4, 0x24(r4)
	  addi      r5, r30, 0x4
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4F80
	  stw       r3, 0x4EC(r26)
	  lwz       r3, 0x4EC(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F8
	  addi      r0, r30, 0x4
	  stw       r0, 0x18(r3)
	  b         .loc_0x2F8

	.loc_0x1A4:
	  add       r0, r24, r27
	  lwz       r3, 0x3180(r13)
	  rlwinm    r0,r0,4,0,27
	  add       r4, r29, r0
	  lwz       r4, 0x28(r4)
	  addi      r5, r30, 0x4
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4F40
	  stw       r3, 0x4E8(r26)
	  lwz       r3, 0x4E8(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F8
	  addi      r0, r30, 0x4
	  stw       r0, 0x18(r3)
	  lfs       f0, -0x3680(r13)
	  lfs       f1, -0x367C(r13)
	  stfs      f0, 0x38(r1)
	  lfs       f0, -0x3678(r13)
	  stfs      f1, 0x3C(r1)
	  stfs      f0, 0x40(r1)
	  lwz       r4, 0x4E8(r26)
	  lwz       r3, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  stw       r3, 0x1DC(r4)
	  stw       r0, 0x1E0(r4)
	  lwz       r0, 0x40(r1)
	  stw       r0, 0x1E4(r4)
	  b         .loc_0x2F8

	.loc_0x218:
	  cmplwi    r31, 0
	  beq-      .loc_0x2F8
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0x5
	  beq-      .loc_0x2F8
	  add       r0, r24, r27
	  lwz       r3, 0x3180(r13)
	  rlwinm    r0,r0,4,0,27
	  add       r4, r29, r0
	  lwz       r4, 0x2C(r4)
	  addi      r5, r30, 0x4
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4EB4
	  stw       r3, 0x4E4(r26)
	  lwz       r3, 0x4E4(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F8
	  addi      r0, r30, 0x4
	  stw       r0, 0x18(r3)
	  b         .loc_0x2F8

	.loc_0x270:
	  cmplwi    r31, 0
	  beq-      .loc_0x2F8
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0x5
	  beq-      .loc_0x2F8
	  add       r0, r24, r27
	  lwz       r3, 0x3180(r13)
	  rlwinm    r0,r0,4,0,27
	  add       r4, r29, r0
	  lwz       r4, 0x30(r4)
	  addi      r5, r30, 0x4
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4E5C
	  stw       r3, 0x4E0(r26)
	  lwz       r3, 0x4E0(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F8
	  addi      r0, r30, 0x4
	  stw       r0, 0x18(r3)
	  lfs       f0, -0x3674(r13)
	  lfs       f1, -0x3670(r13)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, -0x366C(r13)
	  stfs      f1, 0x30(r1)
	  stfs      f0, 0x34(r1)
	  lwz       r4, 0x4E0(r26)
	  lwz       r3, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  stw       r3, 0x1DC(r4)
	  stw       r0, 0x1E0(r4)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0x1E4(r4)

	.loc_0x2F8:
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0x4
	  add       r27, r27, r23
	  addi      r26, r26, 0x10
	  addi      r28, r28, 0x4
	  blt+      .loc_0x12C
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x4
	  blt+      .loc_0x114
	  b         .loc_0x37C

	.loc_0x320:
	  li        r25, 0
	  addi      r24, r21, 0
	  addi      r22, r25, 0

	.loc_0x32C:
	  li        r26, 0
	  addi      r23, r24, 0

	.loc_0x334:
	  lwz       r4, 0x4E0(r23)
	  cmplwi    r4, 0
	  beq-      .loc_0x354
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xB9844
	  stw       r22, 0x4E0(r23)

	.loc_0x354:
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x4
	  addi      r23, r23, 0x4
	  blt+      .loc_0x334
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0x4
	  addi      r24, r24, 0x10
	  blt+      .loc_0x32C
	  li        r0, 0
	  sth       r0, 0x4DC(r21)

	.loc_0x37C:
	  lmw       r21, 0x74(r1)
	  lwz       r0, 0xA4(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E7DC4
 * Size:	00001C
 */
UfoItem::LightAnimator::LightAnimator()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  lfs       f0, -0x6638(r2)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  sth       r0, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E7DE0
 * Size:	000058
 */
void UfoItem::LightAnimator::start(int)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  cmpwi     r4, 0
	  sth       r4, 0xC(r3)
	  ble-      .loc_0x40
	  subi      r0, r4, 0x1
	  lfd       f1, -0x6618(r2)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x6624(r2)
	  stw       r0, 0x14(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x10(r1)
	  lfd       f0, 0x10(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f2, f0
	  stfs      f0, 0x4(r3)
	  b         .loc_0x48

	.loc_0x40:
	  lfs       f0, -0x6620(r2)
	  stfs      f0, 0x4(r3)

	.loc_0x48:
	  lfs       f0, -0x6634(r2)
	  stfs      f0, 0x8(r3)
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void UfoItem::LightAnimator::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E7E38
 * Size:	000064
 */
void UfoItem::getGoalPos()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x671E0
	  lis       r4, 0x676F
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x6C31
	  bl        -0x5E758
	  lfsu      f0, 0x4(r3)
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x8(r30)
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
 * Address:	800E7E9C
 * Size:	000044
 */
void UfoItem::getGoalPosRadius()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x6723C
	  lis       r4, 0x676F
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x6C31
	  bl        -0x5E7B4
	  lfs       f1, 0x0(r3)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E7EE0
 * Size:	000084
 */
void UfoItem::getSuckPos()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  lis       r31, 0x7375
	  stw       r30, 0x20(r1)
	  addi      r30, r31, 0x6330
	  stw       r29, 0x1C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x18(r1)
	  mr        r28, r3
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x67298
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x40
	  addi      r30, r31, 0x6331

	.loc_0x40:
	  lwz       r3, 0x220(r29)
	  mr        r4, r30
	  bl        -0x5E818
	  lfsu      f0, 0x4(r3)
	  stfs      f0, 0x0(r28)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x4(r28)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x8(r28)
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
 * Address:	800E7F64
 * Size:	0000BC
 */
void UfoItem::suckMe(Pellet*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x67304
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x54
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x34
	  addi      r5, r5, 0x2B8

	.loc_0x34:
	  addi      r3, r1, 0x18
	  li        r4, 0
	  bl        0x36FEC
	  addi      r5, r3, 0
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x1D68
	  b         .loc_0x80

	.loc_0x54:
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x64
	  addi      r5, r5, 0x2B8

	.loc_0x64:
	  addi      r3, r1, 0x10
	  li        r4, 0x1
	  bl        0x36FBC
	  addi      r5, r3, 0
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x1D38

	.loc_0x80:
	  lwz       r3, 0x3120(r13)
	  bl        0x2F3DC
	  lfs       f1, -0x6634(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x1D58
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xDA
	  bl        -0x5DA54
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E8020
 * Size:	0000AC
 */
void UfoItem::startYozora()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0xC
	  bl        0x36F1C
	  addi      r5, r3, 0
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x1CCC
	  lfs       f1, -0x6638(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x1CF4
	  lwz       r4, 0x2F6C(r13)
	  lis       r3, 0x8022
	  addi      r8, r3, 0x25E4
	  lbz       r0, 0x10(r4)
	  addi      r4, r1, 0x14
	  lwz       r5, 0x0(r8)
	  mr        r3, r31
	  lwz       r6, 0x4(r8)
	  rlwinm    r0,r0,2,0,29
	  stw       r5, 0x14(r1)
	  li        r5, 0x1
	  stw       r6, 0x18(r1)
	  lwz       r7, 0x8(r8)
	  lwz       r6, 0xC(r8)
	  stw       r7, 0x1C(r1)
	  stw       r6, 0x20(r1)
	  lwz       r7, 0x10(r8)
	  lwz       r6, 0x14(r8)
	  stw       r7, 0x24(r1)
	  stw       r6, 0x28(r1)
	  lwzx      r4, r4, r0
	  bl        -0x680
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E80CC
 * Size:	0000AC
 */
void UfoItem::startGalaxy()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0xC
	  bl        0x36E70
	  addi      r5, r3, 0
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x1C20
	  lfs       f1, -0x6638(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x1C48
	  lwz       r4, 0x2F6C(r13)
	  lis       r3, 0x8022
	  addi      r8, r3, 0x25FC
	  lbz       r0, 0x10(r4)
	  addi      r4, r1, 0x14
	  lwz       r5, 0x0(r8)
	  mr        r3, r31
	  lwz       r6, 0x4(r8)
	  rlwinm    r0,r0,2,0,29
	  stw       r5, 0x14(r1)
	  li        r5, 0
	  stw       r6, 0x18(r1)
	  lwz       r7, 0x8(r8)
	  lwz       r6, 0xC(r8)
	  stw       r7, 0x1C(r1)
	  stw       r6, 0x20(r1)
	  lwz       r7, 0x10(r8)
	  lwz       r6, 0x14(r8)
	  stw       r7, 0x24(r1)
	  stw       r6, 0x28(r1)
	  lwzx      r4, r4, r0
	  bl        -0x72C
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E8178
 * Size:	000130
 */
void UfoItem::finishSuck(Pellet*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  mr        r30, r4
	  stw       r29, 0x3C(r1)
	  mr        r29, r3
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x67D2C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xC0
	  mr        r4, r29
	  lwz       r12, 0x0(r29)
	  addi      r3, r1, 0x10
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x10(r1)
	  addi      r5, r1, 0x28
	  lfs       f1, 0x14(r1)
	  li        r4, 0x11F
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x18(r1)
	  li        r6, 0
	  stfs      f1, 0x2C(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x30(r1)
	  bl        0xB4948
	  mr.       r31, r3
	  beq-      .loc_0xC0
	  lfs       f1, 0xA0(r29)
	  bl        0x133954
	  fmr       f31, f1
	  lfs       f1, 0xA0(r29)
	  bl        0x133ADC
	  stfs      f1, 0x1C(r1)
	  lfs       f0, -0x3668(r13)
	  stfs      f0, 0x20(r1)
	  stfs      f31, 0x24(r1)
	  lwz       r3, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r3, 0xA0(r31)
	  stw       r0, 0xA4(r31)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0xA8(r31)

	.loc_0xC0:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x10(r3)
	  stb       r0, 0x520(r29)
	  lwz       r4, 0x55C(r30)
	  lwz       r0, 0x130(r4)
	  cmpwi     r0, -0x1
	  beq-      .loc_0xF0
	  lwz       r3, 0x2F6C(r13)
	  li        r5, 0
	  lwz       r4, 0x2C(r4)
	  bl        -0x66F48
	  b         .loc_0x100

	.loc_0xF0:
	  lwz       r3, 0x2F6C(r13)
	  li        r5, 0x1
	  lwz       r4, 0x2C(r4)
	  bl        -0x66F5C

	.loc_0x100:
	  lfs       f1, -0x6634(r2)
	  addi      r3, r29, 0x524
	  li        r4, 0
	  bl        0x1ACC
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E82A8
 * Size:	000454
 */
void UfoItem::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x524
	  stw       r30, 0x40(r1)
	  addi      r30, r4, 0
	  li        r4, 0
	  bl        0x1A94
	  cmpwi     r3, 0xB
	  bge-      .loc_0x44
	  cmpwi     r3, 0x2
	  bge-      .loc_0x43C
	  cmpwi     r3, 0
	  bge-      .loc_0x98
	  b         .loc_0x43C

	.loc_0x44:
	  cmpwi     r3, 0x10
	  beq-      .loc_0x54
	  bge-      .loc_0x43C
	  b         .loc_0x18C

	.loc_0x54:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x70
	  bge-      .loc_0x43C
	  cmpwi     r0, 0
	  bge-      .loc_0x84
	  b         .loc_0x43C

	.loc_0x70:
	  lfs       f1, -0x6638(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x1A2C
	  b         .loc_0x43C

	.loc_0x84:
	  lfs       f1, -0x6638(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x1A18
	  b         .loc_0x43C

	.loc_0x98:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xC0
	  bge-      .loc_0xB4
	  cmpwi     r0, 0
	  bge-      .loc_0xD4
	  b         .loc_0x43C

	.loc_0xB4:
	  cmpwi     r0, 0x8
	  beq-      .loc_0xF0
	  b         .loc_0x43C

	.loc_0xC0:
	  lfs       f1, -0x6638(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x19DC
	  b         .loc_0x43C

	.loc_0xD4:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x67390
	  lfs       f1, -0x6638(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x19C0
	  b         .loc_0x43C

	.loc_0xF0:
	  lwz       r0, 0x4(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x14C
	  bge-      .loc_0x43C
	  cmpwi     r0, 0
	  beq-      .loc_0x110
	  b         .loc_0x43C
	  b         .loc_0x43C

	.loc_0x110:
	  cmpwi     r3, 0
	  bne-      .loc_0x43C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x149
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4764
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x14A
	  li        r6, 0
	  li        r7, 0
	  bl        0xB474C
	  b         .loc_0x43C

	.loc_0x14C:
	  cmpwi     r3, 0
	  bne-      .loc_0x170
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x79
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4728
	  b         .loc_0x43C

	.loc_0x170:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x79
	  li        r6, 0
	  li        r7, 0
	  bl        0xB470C
	  b         .loc_0x43C

	.loc_0x18C:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x8
	  beq-      .loc_0x1A8
	  bge-      .loc_0x43C
	  cmpwi     r0, 0
	  beq-      .loc_0x43C
	  b         .loc_0x43C

	.loc_0x1A8:
	  lwz       r0, 0x4(r30)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x258
	  bge-      .loc_0x1D0
	  cmpwi     r0, 0x1
	  beq-      .loc_0x278
	  bge-      .loc_0x238
	  cmpwi     r0, 0
	  bge-      .loc_0x1DC
	  b         .loc_0x43C

	.loc_0x1D0:
	  cmpwi     r0, 0x9
	  beq-      .loc_0x390
	  b         .loc_0x43C

	.loc_0x1DC:
	  lwz       r4, 0x2F6C(r13)
	  lis       r3, 0x8022
	  addi      r8, r3, 0x2614
	  lbz       r0, 0x10(r4)
	  addi      r4, r1, 0x24
	  lwz       r5, 0x0(r8)
	  mr        r3, r31
	  lwz       r6, 0x4(r8)
	  rlwinm    r0,r0,2,0,29
	  stw       r5, 0x24(r1)
	  li        r5, 0
	  stw       r6, 0x28(r1)
	  lwz       r7, 0x8(r8)
	  lwz       r6, 0xC(r8)
	  stw       r7, 0x2C(r1)
	  stw       r6, 0x30(r1)
	  lwz       r7, 0x10(r8)
	  lwz       r6, 0x14(r8)
	  stw       r7, 0x34(r1)
	  stw       r6, 0x38(r1)
	  lwzx      r4, r4, r0
	  bl        -0xAA4
	  b         .loc_0x43C

	.loc_0x238:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x11(r3)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x43C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        0xB94
	  b         .loc_0x43C

	.loc_0x258:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x11(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x43C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        0xA5C
	  b         .loc_0x43C

	.loc_0x278:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x10(r3)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x314
	  bge-      .loc_0x2A0
	  cmpwi     r0, 0x2
	  bge-      .loc_0x2E0
	  cmpwi     r0, 0
	  bge-      .loc_0x2AC
	  b         .loc_0x390

	.loc_0x2A0:
	  cmpwi     r0, 0x6
	  bge-      .loc_0x390
	  b         .loc_0x348

	.loc_0x2AC:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x103
	  li        r6, 0
	  li        r7, 0
	  bl        0xB45D0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x14B
	  li        r6, 0
	  li        r7, 0
	  bl        0xB45B8
	  b         .loc_0x390

	.loc_0x2E0:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x104
	  li        r6, 0
	  li        r7, 0
	  bl        0xB459C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x14B
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4584
	  b         .loc_0x390

	.loc_0x314:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x105
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4568
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x14B
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4550
	  b         .loc_0x390

	.loc_0x348:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x108
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4534
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x107
	  li        r6, 0
	  li        r7, 0
	  bl        0xB451C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x106
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4504

	.loc_0x390:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0x5
	  bne-      .loc_0x43C
	  lis       r4, 0x6763
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x656E
	  bl        -0x5EF44
	  mr        r31, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x11C
	  li        r6, 0
	  li        r7, 0
	  bl        0xB44C8
	  addi      r31, r31, 0x4
	  stw       r31, 0x18(r3)
	  addi      r5, r31, 0
	  li        r4, 0x11B
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        0xB44A8
	  stw       r31, 0x18(r3)
	  addi      r5, r31, 0
	  li        r4, 0x11A
	  lfs       f0, -0x3664(r13)
	  li        r6, 0
	  lfs       f1, -0x3660(r13)
	  li        r7, 0
	  stfs      f0, 0x18(r1)
	  lfs       f0, -0x365C(r13)
	  stfs      f1, 0x1C(r1)
	  stfs      f0, 0x20(r1)
	  lwz       r8, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stw       r8, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x20(r1)
	  stw       r0, 0x1E4(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0xB445C
	  stw       r31, 0x18(r3)

	.loc_0x43C:
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
 * Address:	800E86FC
 * Size:	000008
 */
u32 UfoItem::needShadow() { return 0x0; }

/*
 * --INFO--
 * Address:	800E8704
 * Size:	0001F4
 */
UfoItem::UfoItem(CreatureProp*, UfoShapeObject*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  addi      r5, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  li        r4, 0x1E
	  bl        0xD180
	  lis       r3, 0x802C
	  subi      r3, r3, 0x3E80
	  stw       r3, 0x0(r30)
	  addi      r0, r3, 0x114
	  lis       r3, 0x802C
	  stw       r0, 0x2B8(r30)
	  subi      r4, r3, 0x3CD0
	  addi      r0, r4, 0x114
	  stw       r4, 0x0(r30)
	  lis       r3, 0x800F
	  subi      r4, r3, 0x7708
	  stw       r0, 0x2B8(r30)
	  addi      r3, r30, 0x3D4
	  li        r5, 0
	  li        r6, 0x1C
	  li        r7, 0x3
	  bl        0x12C300
	  lfs       f0, -0x6638(r2)
	  lis       r3, 0x8003
	  addi      r4, r3, 0x5B24
	  stfs      f0, 0x43C(r30)
	  addi      r3, r30, 0x47C
	  li        r5, 0
	  stfs      f0, 0x438(r30)
	  li        r6, 0xC
	  li        r7, 0x6
	  stfs      f0, 0x434(r30)
	  stfs      f0, 0x448(r30)
	  stfs      f0, 0x444(r30)
	  stfs      f0, 0x440(r30)
	  stfs      f0, 0x454(r30)
	  stfs      f0, 0x450(r30)
	  stfs      f0, 0x44C(r30)
	  stfs      f0, 0x460(r30)
	  stfs      f0, 0x45C(r30)
	  stfs      f0, 0x458(r30)
	  stfs      f0, 0x46C(r30)
	  stfs      f0, 0x468(r30)
	  stfs      f0, 0x464(r30)
	  stfs      f0, 0x478(r30)
	  stfs      f0, 0x474(r30)
	  stfs      f0, 0x470(r30)
	  bl        0x12C298
	  addi      r3, r30, 0x524
	  bl        0x1438
	  lfs       f0, -0x6638(r2)
	  addi      r3, r30, 0x560
	  stfs      f0, 0x538(r30)
	  stfs      f0, 0x534(r30)
	  stfs      f0, 0x530(r30)
	  stfs      f0, 0x544(r30)
	  stfs      f0, 0x540(r30)
	  stfs      f0, 0x53C(r30)
	  stfs      f0, 0x554(r30)
	  stfs      f0, 0x550(r30)
	  stfs      f0, 0x54C(r30)
	  bl        -0x44BB4
	  lis       r3, 0x800E
	  addi      r4, r3, 0x7DC4
	  addi      r3, r30, 0x58C
	  li        r5, 0
	  li        r6, 0x10
	  li        r7, 0x4
	  bl        0x12C244
	  li        r0, 0
	  stw       r0, 0x4C4(r30)
	  li        r4, 0xF
	  stw       r0, 0x4C8(r30)
	  stw       r0, 0x4CC(r30)
	  stw       r0, 0x4D0(r30)
	  stw       r0, 0x4D4(r30)
	  stw       r0, 0x4D8(r30)
	  stw       r31, 0x55C(r30)
	  lfs       f0, -0x3658(r13)
	  stfs      f0, 0x7C(r30)
	  lfs       f0, -0x3654(r13)
	  stfs      f0, 0x80(r30)
	  lfs       f0, -0x3650(r13)
	  stfs      f0, 0x84(r30)
	  stw       r0, 0x588(r30)
	  lwz       r3, 0x0(r31)
	  bl        -0xB8FC0
	  stw       r3, 0x58C(r30)
	  li        r4, 0x34
	  lwz       r0, 0x588(r30)
	  stw       r0, 0x0(r3)
	  stw       r3, 0x588(r30)
	  lwz       r3, 0x0(r31)
	  bl        -0xB8FDC
	  stw       r3, 0x59C(r30)
	  li        r4, 0x33
	  lwz       r0, 0x588(r30)
	  stw       r0, 0x0(r3)
	  stw       r3, 0x588(r30)
	  lwz       r3, 0x0(r31)
	  bl        -0xB8FF8
	  stw       r3, 0x5AC(r30)
	  li        r4, 0x28
	  lwz       r0, 0x588(r30)
	  stw       r0, 0x0(r3)
	  stw       r3, 0x588(r30)
	  lwz       r3, 0x0(r31)
	  bl        -0xB9014
	  stw       r3, 0x5BC(r30)
	  lwz       r0, 0x588(r30)
	  stw       r0, 0x0(r3)
	  stw       r3, 0x588(r30)
	  mr        r3, r30
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
 * Address:	800E88F8
 * Size:	000014
 */
UfoItem::Spot::Spot()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x6638(r2)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E890C
 * Size:	000008
 */
u32 UfoItem::ignoreAtari(Creature*) { return 0x0; }

/*
 * --INFO--
 * Address:	800E8914
 * Size:	0000C0
 */
void UfoItem::startTakeoff()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r5, 0x2F6C(r13)
	  lwzu      r3, 0x262C(r4)
	  lbz       r5, 0x10(r5)
	  lwz       r0, 0x4(r4)
	  subic.    r5, r5, 0x1
	  stw       r3, 0x14(r1)
	  stw       r0, 0x18(r1)
	  mr        r6, r5
	  lwz       r3, 0x8(r4)
	  lwz       r0, 0xC(r4)
	  stw       r3, 0x1C(r1)
	  stw       r0, 0x20(r1)
	  lwz       r0, 0x10(r4)
	  stw       r0, 0x24(r1)
	  bge-      .loc_0x58
	  li        r6, 0

	.loc_0x58:
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x68
	  addi      r5, r5, 0x2B8

	.loc_0x68:
	  rlwinm    r0,r6,2,0,29
	  addi      r3, r1, 0x14
	  lwzx      r4, r3, r0
	  addi      r3, r1, 0xC
	  bl        0x36600
	  addi      r5, r3, 0
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x137C
	  lfs       f1, -0x6634(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x13A4
	  lwz       r3, 0x52C(r31)
	  bl        0x2B970
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x678FC
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E89D4
 * Size:	0002BC
 */
void UfoItem::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x38(r1)
	  stb       r0, 0x3CA(r3)
	  stb       r0, 0x3C8(r3)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x68588
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x44
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x16D4
	  b         .loc_0x68

	.loc_0x44:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x16E4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xE9
	  li        r6, 0
	  li        r7, 0
	  bl        0xB4100

	.loc_0x68:
	  li        r0, 0x15
	  stw       r0, 0x52C(r31)
	  li        r0, 0
	  mr        r3, r31
	  stw       r0, 0x4E0(r31)
	  li        r4, 0
	  li        r5, 0
	  stw       r0, 0x4E4(r31)
	  stw       r0, 0x4E8(r31)
	  stw       r0, 0x4EC(r31)
	  stw       r0, 0x4F0(r31)
	  stw       r0, 0x4F4(r31)
	  stw       r0, 0x4F8(r31)
	  stw       r0, 0x4FC(r31)
	  stw       r0, 0x500(r31)
	  stw       r0, 0x504(r31)
	  stw       r0, 0x508(r31)
	  stw       r0, 0x50C(r31)
	  stw       r0, 0x510(r31)
	  stw       r0, 0x514(r31)
	  stw       r0, 0x518(r31)
	  stw       r0, 0x51C(r31)
	  bl        -0x1060
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x4D4
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x5E0
	  li        r0, 0x1
	  stb       r0, 0x5CC(r31)
	  addi      r0, r31, 0x560
	  addi      r4, r31, 0
	  stw       r0, 0x2C(r31)
	  li        r5, 0x7
	  lwz       r3, 0x2C(r31)
	  bl        -0x44D98
	  li        r3, 0x14
	  bl        -0xA1AD0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x118
	  li        r4, 0x10
	  bl        -0x5FEB8

	.loc_0x118:
	  stw       r30, 0x220(r31)
	  li        r5, 0
	  li        r6, 0
	  lwz       r4, 0x55C(r31)
	  lwz       r3, 0x220(r31)
	  lwz       r4, 0x0(r4)
	  bl        -0x5EFA0
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  addi      r5, r31, 0x94
	  li        r6, 0
	  bl        -0x47A34
	  lwz       r0, 0x10(r3)
	  mr        r3, r31
	  stw       r0, 0x558(r31)
	  lwz       r12, 0x0(r31)
	  lfs       f1, -0x6634(r2)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x94(r31)
	  li        r4, 0x1
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x54C(r31)
	  stw       r0, 0x550(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x554(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x80C64
	  stfs      f1, 0x550(r31)
	  addi      r3, r31, 0x524
	  lwz       r5, 0x30AC(r13)
	  lwz       r4, 0x55C(r31)
	  lwz       r5, 0x94(r5)
	  bl        0x10F4
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x67F10
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F0
	  addi      r3, r1, 0x28
	  li        r4, 0
	  bl        0x363BC
	  addi      r5, r3, 0
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x116C
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xE0
	  bl        -0x5E608
	  b         .loc_0x21C

	.loc_0x1F0:
	  addi      r3, r1, 0x20
	  li        r4, 0x1
	  bl        0x3638C
	  addi      r5, r3, 0
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0x113C
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xDE
	  bl        -0x5E638

	.loc_0x21C:
	  addi      r3, r31, 0x524
	  bl        0x1180
	  lwz       r4, 0x2F6C(r13)
	  mr        r3, r31
	  lbz       r30, 0x10(r4)
	  mr        r4, r30
	  bl        -0x124C
	  addi      r3, r31, 0x524
	  addi      r4, r30, 0
	  bl        0x11A8
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x687A8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x298
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x1A40
	  lfs       f2, -0x6638(r2)
	  stfs      f2, 0x3E4(r31)
	  lfs       f1, -0x6610(r2)
	  stfs      f1, 0x3E0(r31)
	  stfs      f2, 0x3E8(r31)
	  lfs       f0, -0x660C(r2)
	  stfs      f0, 0x400(r31)
	  stfs      f1, 0x3FC(r31)
	  stfs      f2, 0x404(r31)
	  lfs       f0, -0x6608(r2)
	  stfs      f0, 0x41C(r31)
	  stfs      f1, 0x418(r31)
	  stfs      f2, 0x420(r31)
	  b         .loc_0x2A4

	.loc_0x298:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x1A84

	.loc_0x2A4:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E8C90
 * Size:	000008
 */
void UfoItem::getSize()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x6604(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E8C98
 * Size:	000008
 */
void UfoItem::getiMass()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x6638(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E8CA0
 * Size:	0000B0
 */
void UfoItem::accessible()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  addi      r3, r30, 0x524
	  bl        0x10A0
	  lis       r4, 0x803A
	  lfs       f0, -0x6600(r2)
	  subi      r5, r4, 0x2848
	  lwz       r4, 0x20(r5)
	  mr        r31, r3
	  lfs       f2, 0x2F0(r5)
	  lfs       f1, 0x20(r4)
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x54
	  li        r3, 0
	  b         .loc_0x98

	.loc_0x54:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x68884
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x94
	  cmpwi     r31, 0x1
	  beq-      .loc_0x74
	  cmpwi     r31, 0x10
	  bne-      .loc_0x94

	.loc_0x74:
	  lwz       r3, 0x528(r30)
	  lfs       f0, -0x6638(r2)
	  lfs       f1, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x94
	  li        r3, 0x1
	  b         .loc_0x98

	.loc_0x94:
	  li        r3, 0

	.loc_0x98:
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
 * Address:	800E8D50
 * Size:	000170
 */
void UfoItem::startAccess()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  addi      r31, r3, 0
	  addi      r4, r31, 0
	  stb       r0, 0x3C8(r3)
	  addi      r3, r1, 0x50
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x50(r1)
	  mr        r4, r31
	  lfs       f1, 0x54(r1)
	  addi      r3, r1, 0x5C
	  stfs      f0, 0xC(r1)
	  lfs       f0, 0x58(r1)
	  stfs      f1, 0x10(r1)
	  stfs      f0, 0x14(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x6638(r2)
	  li        r0, 0x18
	  lfs       f3, 0x5C(r1)
	  addi      r4, r1, 0x24
	  stfs      f0, 0x2C(r1)
	  lfs       f2, 0x60(r1)
	  stfs      f0, 0x28(r1)
	  lfs       f1, 0x64(r1)
	  stfs      f3, 0x18(r1)
	  stfs      f0, 0x24(r1)
	  stfs      f2, 0x1C(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f1, 0x20(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  lwz       r3, 0xC(r1)
	  lwz       r5, 0x10(r1)
	  stw       r3, 0x24(r1)
	  lwz       r3, 0x14(r1)
	  stw       r5, 0x28(r1)
	  lwz       r5, 0x18(r1)
	  stw       r3, 0x2C(r1)
	  lwz       r3, 0x1C(r1)
	  stw       r5, 0x30(r1)
	  stw       r3, 0x34(r1)
	  lwz       r3, 0x20(r1)
	  stw       r3, 0x38(r1)
	  lfs       f0, -0x662C(r2)
	  stfs      f0, 0x48(r1)
	  stw       r0, 0x52C(r31)
	  lwz       r3, 0x52C(r31)
	  bl        0x2B4B0
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0xF4
	  addi      r5, r5, 0x2B8

	.loc_0xF4:
	  addi      r3, r1, 0x68
	  li        r4, 0x1
	  bl        0x36140
	  addi      r5, r3, 0
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0xEBC
	  lfs       f1, -0x6634(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0xEE4
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x130
	  addi      r5, r5, 0x2B8

	.loc_0x130:
	  addi      r3, r1, 0x70
	  li        r4, 0x10
	  bl        0x36104
	  addi      r5, r3, 0
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0xE80
	  lfs       f1, -0x6634(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0xEA8
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E8EC0
 * Size:	000048
 */
void UfoItem::finishAccess()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stb       r0, 0x3C8(r3)
	  lwz       r3, 0x52C(r3)
	  bl        0x2B444
	  lfs       f1, -0x6634(r2)
	  addi      r3, r31, 0x524
	  li        r4, 0
	  bl        0xE60
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E8F08
 * Size:	00006C
 */
void UfoItem::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x1A54
	  lfs       f0, -0x364C(r13)
	  mr        r3, r31
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x3648(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x3644(r13)
	  stfs      f0, 0x78(r31)
	  bl        0xCCB8
	  addi      r3, r31, 0x524
	  bl        0x1164
	  lwz       r3, 0x54C(r31)
	  lwz       r0, 0x550(r31)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x554(r31)
	  stw       r0, 0x9C(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E8F74
 * Size:	000118
 */
void UfoItem::setPca1Effect(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,24,31
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r3, 0
	  stb       r4, 0x548(r3)
	  beq-      .loc_0x104
	  lfs       f0, -0x3640(r13)
	  addi      r3, r1, 0x28
	  lfs       f1, -0x363C(r13)
	  addi      r4, r31, 0x228
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x3638(r13)
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  bl        -0xB19A8
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x530
	  li        r4, 0x11D
	  li        r6, 0
	  li        r7, 0
	  bl        0xB3B6C
	  lfs       f0, -0x3634(r13)
	  addi      r5, r31, 0x530
	  lfs       f1, -0x3630(r13)
	  li        r4, 0x11E
	  stfs      f0, 0x1C(r1)
	  lfs       f0, -0x362C(r13)
	  li        r6, 0
	  stfs      f1, 0x20(r1)
	  li        r7, 0
	  stfs      f0, 0x24(r1)
	  lwz       r8, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r8, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x1E4(r3)
	  lwz       r8, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r8, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0xA8(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0xB3B0C
	  lfs       f0, -0x3628(r13)
	  lfs       f1, -0x3624(r13)
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0x3620(r13)
	  stfs      f1, 0x14(r1)
	  stfs      f0, 0x18(r1)
	  lwz       r4, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x18(r1)
	  stw       r0, 0x1E4(r3)
	  lwz       r4, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0xA8(r3)

	.loc_0x104:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E908C
 * Size:	000118
 */
void UfoItem::setPca2Effect(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,24,31
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r3, 0
	  stb       r4, 0x549(r3)
	  beq-      .loc_0x104
	  lfs       f0, -0x361C(r13)
	  addi      r3, r1, 0x28
	  lfs       f1, -0x3618(r13)
	  addi      r4, r31, 0x228
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x3614(r13)
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  bl        -0xB1AC0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x53C
	  li        r4, 0x11D
	  li        r6, 0
	  li        r7, 0
	  bl        0xB3A54
	  lfs       f0, -0x3610(r13)
	  addi      r5, r31, 0x53C
	  lfs       f1, -0x360C(r13)
	  li        r4, 0x11E
	  stfs      f0, 0x1C(r1)
	  lfs       f0, -0x3608(r13)
	  li        r6, 0
	  stfs      f1, 0x20(r1)
	  li        r7, 0
	  stfs      f0, 0x24(r1)
	  lwz       r8, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r8, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x1E4(r3)
	  lwz       r8, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r8, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0xA8(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0xB39F4
	  lfs       f0, -0x3604(r13)
	  lfs       f1, -0x3600(r13)
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0x35FC(r13)
	  stfs      f1, 0x14(r1)
	  stfs      f0, 0x18(r1)
	  lwz       r4, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x18(r1)
	  stw       r0, 0x1E4(r3)
	  lwz       r4, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0xA8(r3)

	.loc_0x104:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E91A4
 * Size:	0000E4
 */
void UfoItem::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r4, 0
	  addi      r6, r1, 0x10
	  stw       r30, 0x60(r1)
	  mr        r30, r3
	  addi      r4, r30, 0x7C
	  lfs       f0, 0x94(r3)
	  addi      r3, r30, 0x228
	  addi      r5, r30, 0x88
	  stfs      f0, 0x10(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x14(r1)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x18(r1)
	  bl        -0xAB0F4
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x94
	  lfs       f1, -0x65FC(r2)
	  bl        -0xA7C74
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x70
	  lwz       r0, 0xC8(r30)
	  oris      r0, r0, 0x8
	  stw       r0, 0xC8(r30)
	  b         .loc_0x7C

	.loc_0x70:
	  lwz       r0, 0xC8(r30)
	  rlwinm    r0,r0,0,13,11
	  stw       r0, 0xC8(r30)

	.loc_0x7C:
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x1C
	  addi      r3, r3, 0x1E0
	  bl        -0xAB15C
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x1C
	  lwz       r12, 0xFC(r12)
	  mtlr      r12
	  blrl
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
 * Address:	800E9288
 * Size:	000504
 */
void UfoItem::demoDraw(Graphics&, Matrix4f*)
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
	  stfd      f27, 0xC0(r1)
	  stmw      r26, 0xA8(r1)
	  mr        r30, r3
	  mr        r31, r4
	  addi      r26, r5, 0
	  addi      r28, r30, 0
	  li        r27, 0
	  lis       r29, 0x4330
	  lfs       f31, -0x6624(r2)
	  lfd       f30, -0x6618(r2)
	  lfs       f29, -0x662C(r2)

	.loc_0x48:
	  lhz       r3, 0x598(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0xD8
	  subi      r0, r3, 0x1
	  lwz       r3, 0x2DEC(r13)
	  xoris     r0, r0, 0x8000
	  lfs       f1, 0x594(r28)
	  stw       r0, 0xA4(r1)
	  lfs       f0, 0x28C(r3)
	  stw       r29, 0xA0(r1)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x590(r28)
	  lfd       f2, 0xA0(r1)
	  fsubs     f2, f2, f30
	  fadds     f0, f1, f0
	  fmuls     f28, f31, f2
	  stfs      f0, 0x590(r28)
	  fadds     f0, f31, f28
	  lfs       f1, 0x590(r28)
	  fsubs     f0, f0, f29
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xD8
	  lwz       r3, 0x30AC(r13)
	  bl        0x9908
	  lhz       r0, 0x598(r28)
	  cmplwi    r0, 0x5
	  bge-      .loc_0xC8
	  addi      r4, r3, 0
	  li        r5, 0xE2
	  bl        -0x5ED94
	  b         .loc_0xD4

	.loc_0xC8:
	  addi      r4, r3, 0
	  li        r5, 0xE5
	  bl        -0x5EDA4

	.loc_0xD4:
	  stfs      f28, 0x590(r28)

	.loc_0xD8:
	  lwz       r3, 0x58C(r28)
	  addi      r4, r28, 0x590
	  bl        -0xBA2CC
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x4
	  addi      r28, r28, 0x10
	  blt+      .loc_0x48
	  addi      r3, r30, 0x524
	  bl        0xDA8
	  lwz       r3, 0x55C(r30)
	  addi      r4, r31, 0
	  addi      r5, r26, 0
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0xB4084
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x138
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x164

	.loc_0x138:
	  lwz       r3, 0x55C(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  lwz       r3, 0x0(r3)
	  lwz       r6, 0x588(r30)
	  bl        -0xB8F68
	  lwz       r5, 0x55C(r30)
	  mr        r4, r31
	  lwz       r3, 0x2F6C(r13)
	  lwz       r5, 0x0(r5)
	  bl        -0x67AD4

	.loc_0x164:
	  lfs       f0, -0x6638(r2)
	  mr        r4, r31
	  addi      r6, r1, 0x94
	  stfs      f0, 0x9C(r1)
	  li        r5, 0x30
	  stfs      f0, 0x98(r1)
	  stfs      f0, 0x94(r1)
	  lfs       f1, -0x35F8(r13)
	  lfs       f0, -0x35F4(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x35F0(r13)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x55C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xB3B64
	  lwz       r3, 0x94(r1)
	  mr        r4, r31
	  lwz       r0, 0x98(r1)
	  addi      r6, r1, 0x94
	  li        r5, 0x31
	  stw       r3, 0x53C(r30)
	  stw       r0, 0x540(r30)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x544(r30)
	  lfs       f1, -0x35EC(r13)
	  lfs       f0, -0x35E8(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x35E4(r13)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x55C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xB3BAC
	  lwz       r3, 0x94(r1)
	  lwz       r0, 0x98(r1)
	  stw       r3, 0x530(r30)
	  stw       r0, 0x534(r30)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x538(r30)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x6901C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x364
	  lfs       f1, -0x35E0(r13)
	  mr        r4, r31
	  lfs       f0, -0x35DC(r13)
	  addi      r6, r1, 0x94
	  stfs      f1, 0x94(r1)
	  li        r5, 0x2
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x35D8(r13)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x55C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xB3C04
	  lwz       r3, 0x94(r1)
	  mr        r4, r31
	  lwz       r0, 0x98(r1)
	  addi      r6, r1, 0x94
	  li        r5, 0x2
	  stw       r3, 0x47C(r30)
	  stw       r0, 0x480(r30)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x484(r30)
	  lfs       f1, -0x35D4(r13)
	  lfs       f0, -0x35D0(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x35CC(r13)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x55C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xB3C4C
	  lwz       r3, 0x94(r1)
	  mr        r4, r31
	  lwz       r0, 0x98(r1)
	  addi      r6, r1, 0x94
	  li        r5, 0x29
	  stw       r3, 0x488(r30)
	  stw       r0, 0x48C(r30)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x490(r30)
	  lwz       r3, 0x47C(r30)
	  lwz       r0, 0x480(r30)
	  stw       r3, 0x494(r30)
	  stw       r0, 0x498(r30)
	  lwz       r0, 0x484(r30)
	  stw       r0, 0x49C(r30)
	  lwz       r3, 0x488(r30)
	  lwz       r0, 0x48C(r30)
	  stw       r3, 0x4A0(r30)
	  stw       r0, 0x4A4(r30)
	  lwz       r0, 0x490(r30)
	  stw       r0, 0x4A8(r30)
	  lfs       f1, -0x35C8(r13)
	  lfs       f0, -0x35C4(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x35C0(r13)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x55C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xB3CC4
	  lwz       r3, 0x94(r1)
	  mr        r4, r31
	  lwz       r0, 0x98(r1)
	  addi      r6, r1, 0x94
	  li        r5, 0x2
	  stw       r3, 0x4AC(r30)
	  stw       r0, 0x4B0(r30)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x4B4(r30)
	  lfs       f1, -0x35BC(r13)
	  lfs       f0, -0x35B8(r13)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, -0x35B4(r13)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x55C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xB3D0C
	  lwz       r3, 0x94(r1)
	  lwz       r0, 0x98(r1)
	  stw       r3, 0x4B8(r30)
	  stw       r0, 0x4BC(r30)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x4C0(r30)

	.loc_0x364:
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0x5FB0C
	  lfs       f29, -0x65F8(r2)
	  mr        r28, r30
	  lfs       f30, -0x65F4(r2)
	  li        r27, 0
	  lfs       f31, -0x6638(r2)
	  lis       r29, 0x676F

	.loc_0x38C:
	  lwz       r3, 0x220(r30)
	  addi      r4, r29, 0x6C31
	  bl        -0x5FF0C
	  mr.       r31, r3
	  beq-      .loc_0x450
	  lbz       r0, 0x3CA(r30)
	  lfs       f1, 0xA0(r30)
	  lfs       f0, 0x3E4(r28)
	  cmplwi    r0, 0
	  fadds     f27, f1, f0
	  beq-      .loc_0x3E8
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x3E8(r28)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f29, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x3E8(r28)
	  lfs       f0, 0x3E8(r28)
	  fcmpo     cr0, f0, f30
	  ble-      .loc_0x3E0
	  stfs      f31, 0x3E8(r28)

	.loc_0x3E0:
	  lfs       f0, 0x3E8(r28)
	  fadds     f27, f27, f0

	.loc_0x3E8:
	  fmr       f1, f27
	  bl        0x1324E0
	  lfs       f0, 0x3E0(r28)
	  fmuls     f28, f0, f1
	  fmr       f1, f27
	  bl        0x132664
	  lfs       f0, 0x3E0(r28)
	  lfs       f2, 0x4(r31)
	  fmuls     f1, f0, f1
	  lfs       f0, -0x35B0(r13)
	  fadds     f1, f2, f1
	  stfs      f1, 0x44(r1)
	  lfs       f1, 0x44(r1)
	  stfs      f1, 0x6C(r1)
	  lfs       f1, 0x8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0xC(r31)
	  fadds     f0, f0, f28
	  stfs      f0, 0x74(r1)
	  lwz       r3, 0x6C(r1)
	  lwz       r0, 0x70(r1)
	  stw       r3, 0x3D4(r28)
	  stw       r0, 0x3D8(r28)
	  lwz       r0, 0x74(r1)
	  stw       r0, 0x3DC(r28)

	.loc_0x450:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x3
	  addi      r28, r28, 0x1C
	  blt+      .loc_0x38C
	  lbz       r0, 0x5CC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x4DC
	  mr        r4, r30
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x60
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  addi      r5, r1, 0x60
	  li        r6, 0
	  bl        -0x48638
	  lwz       r0, 0x10(r3)
	  addi      r4, r30, 0
	  addi      r3, r1, 0x54
	  stw       r0, 0x558(r30)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x54(r1)
	  li        r0, 0
	  lfs       f1, 0x58(r1)
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x5C(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f0, 0x80(r1)
	  stb       r0, 0x5CC(r30)

	.loc_0x4DC:
	  lmw       r26, 0xA8(r1)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lfd       f29, 0xD0(r1)
	  lfd       f28, 0xC8(r1)
	  lfd       f27, 0xC0(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E978C
 * Size:	000008
 */
void UfoItem::getRouteIndex()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x558(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E9794
 * Size:	000008
 */
u32 UfoItem::isVisible() { return 0x1; }

/*
 * --INFO--
 * Address:	800E979C
 * Size:	000008
 */
u32 UfoItem::isAlive() { return 0x1; }

/*
 * --INFO--
 * Address:	800E97A4
 * Size:	000008
 */
void UfoItem::@696 @animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  subi      r3, r3, 0x2B8
	  b         -0x1500
	*/
}
