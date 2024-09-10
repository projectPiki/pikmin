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
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80149BC0
 * Size:	000054
 */
void TekiPikiStateCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x28
	  li        r3, 0
	  b         .loc_0x40

	.loc_0x28:
	  mr        r3, r4
	  bl        -0x81698
	  lwz       r0, 0x4(r31)
	  sub       r0, r3, r0
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31

	.loc_0x40:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149C14
 * Size:	00002C
 */
void TekiStateCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x37
	  beq-      .loc_0x14
	  li        r3, 0
	  blr

	.loc_0x14:
	  lwz       r4, 0x324(r4)
	  lwz       r0, 0x4(r3)
	  sub       r0, r0, r4
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149C40
 * Size:	00002C
 */
void TekiTypeCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x37
	  beq-      .loc_0x14
	  li        r3, 0
	  blr

	.loc_0x14:
	  lwz       r4, 0x320(r4)
	  lwz       r0, 0x4(r3)
	  sub       r0, r0, r4
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149C6C
 * Size:	000030
 */
void TekiFreeCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x9C(r12)
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
 * Address:	80149C9C
 * Size:	000014
 */
void TekiNaviCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x6C(r4)
	  subfic    r0, r0, 0x36
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149CB0
 * Size:	000020
 */
void TekiNaviPikiCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x6C(r4)
	  li        r3, 0x1
	  cmpwi     r0, 0x36
	  beqlr-
	  cmpwi     r0, 0
	  beqlr-
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149CD0
 * Size:	000024
 */
void TekiPelletCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x6C(r4)
	  bl        -0x5AC4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149CF4
 * Size:	0000A8
 */
void TekiPositionDistanceCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  lfs       f0, -0x5868(r2)
	  stfs      f0, 0x38(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  lfs       f1, 0x94(r4)
	  lfs       f0, 0x4(r31)
	  lfs       f4, 0x9C(r4)
	  fsubs     f0, f1, f0
	  lfs       f3, 0xC(r31)
	  lfs       f2, 0x98(r4)
	  lfs       f1, 0x8(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x28(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f3, 0x38(r1)
	  lfs       f1, 0x30(r1)
	  lfs       f0, 0x34(r1)
	  lfs       f2, 0x38(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x13C130
	  lfs       f0, 0x10(r31)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149D9C
 * Size:	000070
 */
void TekiPositionCircleDistanceCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0x94
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  fmr       f2, f1
	  lfs       f1, 0x10(r30)
	  addi      r4, r31, 0
	  addi      r3, r30, 0x4
	  bl        -0x5BB0
	  lfs       f0, -0x5868(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31
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
 * Address:	80149E0C
 * Size:	000070
 */
void TekiPositionSphereDistanceCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0x94
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  fmr       f2, f1
	  lfs       f1, 0x10(r30)
	  addi      r4, r31, 0
	  addi      r3, r30, 0x4
	  bl        -0x5BBC
	  lfs       f0, -0x5868(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31
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
 * Address:	80149E7C
 * Size:	000014
 */
void TekiStickingCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x184(r4)
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149E90
 * Size:	0000A8
 */
void TekiRecognitionCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r31, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x60
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x60
	  li        r30, 0x1

	.loc_0x60:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x88
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x88
	  li        r31, 0x1

	.loc_0x88:
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149F38
 * Size:	000014
 */
void TekiCreaturePointerCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x4(r3)
	  sub       r0, r4, r0
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149F4C
 * Size:	0000E4
 */
void TekiDistanceCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  lwz       r3, 0x4(r3)
	  lfs       f1, 0x8(r30)
	  bl        -0x33C0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x38
	  li        r3, 0
	  b         .loc_0xCC

	.loc_0x38:
	  lwz       r3, 0x4(r30)
	  addi      r6, r1, 0x2C
	  lfs       f0, -0x5868(r2)
	  addi      r5, r1, 0x28
	  addi      r8, r3, 0x94
	  stfs      f0, 0x40(r1)
	  addi      r4, r1, 0x24
	  stfs      f0, 0x3C(r1)
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r3, r1, 0x38
	  lfs       f1, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2C(r1)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x28(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x24(r1)
	  bl        -0xEC950
	  lfs       f1, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x40(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x13C3C0
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31

	.loc_0xCC:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A030
 * Size:	000070
 */
void TekiSphereDistanceCondition::satisfy(Creature*)
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
	  lwz       r3, 0x4(r3)
	  lfs       f1, 0x8(r30)
	  bl        -0x3484
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x38
	  li        r3, 0
	  b         .loc_0x58

	.loc_0x38:
	  lwz       r3, 0x4(r30)
	  mr        r4, r31
	  bl        -0xBE550
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31

	.loc_0x58:
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
 * Address:	8014A0A0
 * Size:	000018
 */
void TekiStickerCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x184(r4)
	  lwz       r0, 0x4(r3)
	  sub       r0, r0, r4
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A0B8
 * Size:	000144
 */
void TekiLowerRangeCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stfd      f30, 0x88(r1)
	  stw       r31, 0x84(r1)
	  stw       r30, 0x80(r1)
	  addi      r30, r4, 0
	  li        r4, 0
	  stw       r29, 0x7C(r1)
	  mr        r29, r3
	  lwz       r31, 0x4(r3)
	  lwz       r3, 0x2C8(r31)
	  lwz       r3, 0x34(r3)
	  bl        -0x26EE0
	  lwz       r3, 0x2C4(r31)
	  fmr       f30, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x26EF4
	  lwz       r3, 0x2C4(r31)
	  fmr       f31, f1
	  li        r4, 0x2D
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x27C48
	  fmuls     f0, f31, f30
	  lwz       r3, 0x4(r29)
	  mr        r4, r30
	  fmuls     f30, f1, f0
	  fmr       f1, f30
	  bl        -0x3584
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x90
	  li        r3, 0
	  b         .loc_0x120

	.loc_0x90:
	  lwz       r3, 0x4(r29)
	  addi      r6, r1, 0x54
	  lfs       f0, -0x5868(r2)
	  addi      r5, r1, 0x50
	  addi      r8, r3, 0x94
	  stfs      f0, 0x6C(r1)
	  addi      r4, r1, 0x4C
	  stfs      f0, 0x68(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r3, r1, 0x64
	  lfs       f1, 0x9C(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x54(r1)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x50(r1)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4C(r1)
	  bl        -0xECB14
	  lfs       f1, 0x64(r1)
	  lfs       f0, 0x68(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x6C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x13C584
	  fcmpo     cr0, f1, f30
	  cror      2, 0, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31

	.loc_0x120:
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  lwz       r29, 0x7C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A1FC
 * Size:	000024
 */
void TekiAttackableCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  bl        -0x30C0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A220
 * Size:	000024
 */
void TekiVisibleCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  bl        -0x351C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A244
 * Size:	00003C
 */
void TekiVisibleHeightCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x4(r3)
	  lfs       f1, 0x98(r4)
	  lwz       r3, 0x2C4(r5)
	  lfs       f0, 0x98(r5)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f2, 0x70(r3)
	  fadds     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x34
	  li        r3, 0
	  blr

	.loc_0x34:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A280
 * Size:	0000BC
 */
void TekiLowerCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r10, r5, 0xF68
	  lis       r5, 0x802C
	  stwu      r1, -0x80(r1)
	  addi      r9, r5, 0x6964
	  lis       r6, 0x802D
	  lwz       r11, 0x4(r3)
	  lis       r5, 0x802C
	  addi      r0, r5, 0x6890
	  stw       r10, 0x5C(r1)
	  lis       r7, 0x802D
	  subi      r6, r6, 0x2A4C
	  stw       r10, 0x64(r1)
	  addi      r8, r1, 0x5C
	  lis       r5, 0x802C
	  stw       r9, 0x5C(r1)
	  subi      r7, r7, 0x2A84
	  stw       r6, 0x5C(r1)
	  addi      r6, r5, 0x685C
	  addi      r5, r1, 0x6C
	  stw       r9, 0x64(r1)
	  stw       r0, 0x64(r1)
	  addi      r0, r1, 0x64
	  stw       r11, 0x60(r1)
	  addi      r11, r1, 0x74
	  stw       r8, 0x68(r1)
	  lwz       r8, 0x4(r3)
	  mr        r3, r11
	  stw       r10, 0x74(r1)
	  stw       r10, 0x6C(r1)
	  stw       r9, 0x74(r1)
	  stw       r9, 0x6C(r1)
	  stw       r6, 0x74(r1)
	  stw       r7, 0x6C(r1)
	  stw       r5, 0x78(r1)
	  stw       r8, 0x70(r1)
	  stw       r0, 0x7C(r1)
	  lwz       r12, 0x0(r11)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x84(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A33C
 * Size:	00005C
 */
void TekiAngleCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r4, r4, 0x94
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  lwz       r3, 0x4(r3)
	  bl        -0x3058
	  lfs       f3, 0x8(r31)
	  lfs       f2, -0x5864(r2)
	  lfs       f0, -0x1CA8(r13)
	  fmuls     f2, f3, f2
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x44
	  li        r3, 0
	  b         .loc_0x48

	.loc_0x44:
	  li        r3, 0x1

	.loc_0x48:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}
