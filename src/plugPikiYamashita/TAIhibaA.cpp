#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801D4800
 * Size:	000084
 */
TAIhibaASoundTable::TAIhibaASoundTable()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x7
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  bl        -0xB57AC
  li        r30, 0
  li        r31, 0
  b         .loc_0x58

.loc_0x30:
  li        r3, 0x4
  bl        -0x18D830
  cmplwi    r3, 0
  beq-      .loc_0x48
  addi      r0, r30, 0x3C
  stw       r0, 0x0(r3)

.loc_0x48:
  lwz       r4, 0x4(r29)
  addi      r30, r30, 0x1
  stwx      r3, r4, r31
  addi      r31, r31, 0x4

.loc_0x58:
  lwz       r0, 0x0(r29)
  cmpw      r30, r0
  blt+      .loc_0x30
  mr        r3, r29
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
 * Address:	801D4884
 * Size:	0002F8
 */
TAIhibaAParameters::TAIhibaAParameters()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x14
  stw       r0, 0x4(r1)
  li        r5, 0x34
  stwu      r1, -0xC0(r1)
  stw       r31, 0xBC(r1)
  addi      r31, r3, 0
  bl        -0x88B58
  lis       r3, 0x802E
  addi      r0, r3, 0x4A5C
  stw       r0, 0x0(r31)
  li        r6, 0x32
  lis       r5, 0x802E
  lwz       r4, 0x84(r31)
  li        r0, 0x33
  lis       r3, 0x802E
  lwz       r7, 0x4(r4)
  mulli     r6, r6, 0xC
  lwz       r7, 0x8(r7)
  mulli     r0, r0, 0xC
  add       r10, r7, r6
  addi      r5, r5, 0x464C
  stw       r5, 0x0(r10)
  add       r11, r7, r0
  addi      r3, r3, 0x465C
  lfs       f6, -0x42E0(r2)
  li        r9, -0x1
  li        r8, 0x5
  stfs      f6, 0x4(r10)
  li        r7, 0x2
  li        r6, 0xA
  lfs       f1, -0x42DC(r2)
  li        r5, 0x3
  li        r0, 0
  stfs      f1, 0x8(r10)
  stw       r3, 0x0(r11)
  stfs      f6, 0x4(r11)
  stfs      f1, 0x8(r11)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x42D8(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xC8(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x42D4(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xCC(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r9, 0xC(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r8, 0x24(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r7, 0x28(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r8, 0x2C(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r6, 0x30(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r5, 0x34(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r5, 0x38(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r5, 0x3C(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r5, 0x40(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r0, 0x8(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x8(r3)
  lwz       r3, 0x4(r4)
  lfs       f5, -0x42D0(r2)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x4(r3)
  lwz       r3, 0x4(r4)
  lfs       f1, -0x42CC(r2)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x0(r3)
  lwz       r3, 0x4(r4)
  lfs       f4, -0x42C8(r2)
  lwz       r3, 0x0(r3)
  stfs      f4, 0xC(r3)
  lwz       r3, 0x4(r4)
  lfs       f3, -0x42C4(r2)
  lwz       r3, 0x0(r3)
  stfs      f3, 0x10(r3)
  lwz       r5, 0x4(r4)
  mr        r3, r31
  lfs       f0, -0x42C0(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x14(r5)
  lwz       r5, 0x4(r4)
  lfs       f2, -0x42BC(r2)
  lwz       r5, 0x0(r5)
  stfs      f2, 0x18(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x42B8(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x1C(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f1, 0x70(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x42B4(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x20(r5)
  lwz       r5, 0x4(r4)
  lfs       f1, -0x42B0(r2)
  lwz       r5, 0x0(r5)
  stfs      f1, 0x24(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f1, 0x28(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x42AC(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x2C(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f1, 0x30(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f2, 0x3C(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f3, 0x40(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x42A8(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x78(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x42A4(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x7C(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f5, 0x80(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x42A0(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x84(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x88(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f4, 0x8C(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x429C(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x90(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x4298(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x94(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x4294(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x44(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x4290(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x48(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x428C(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x98(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f6, 0x58(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f4, 0x5C(r5)
  lwz       r4, 0x4(r4)
  lwz       r4, 0x0(r4)
  stfs      f6, 0x60(r4)
  lwz       r0, 0xC4(r1)
  lwz       r31, 0xBC(r1)
  addi      r1, r1, 0xC0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801D4B7C
 * Size:	0001E8
 */
TAIhibaAStrategy::TAIhibaAStrategy()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x3
  stw       r0, 0x4(r1)
  li        r5, 0
  stwu      r1, -0x40(r1)
  stmw      r26, 0x28(r1)
  addi      r31, r3, 0
  bl        0x14ABC
  lis       r3, 0x802E
  addi      r0, r3, 0x4854
  stw       r0, 0x0(r31)
  li        r3, 0x8
  bl        -0x18DBA8
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x60
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r30)
  li        r0, 0x1
  lis       r3, 0x802E
  stw       r0, 0x0(r30)
  addi      r0, r3, 0x4994
  stw       r0, 0x4(r30)

.loc_0x60:
  li        r3, 0x8
  bl        -0x18DBDC
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x94
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r29)
  li        r0, -0x1
  lis       r3, 0x802E
  stw       r0, 0x0(r29)
  subi      r0, r3, 0x6EC
  stw       r0, 0x4(r29)

.loc_0x94:
  li        r3, 0xC
  bl        -0x18DC10
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0xDC
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, 0x2
  lis       r3, 0x802E
  stw       r0, 0x0(r28)
  subi      r0, r3, 0x149C
  lis       r3, 0x802E
  stw       r0, 0x4(r28)
  addi      r0, r3, 0x4938
  lfs       f0, -0x42E0(r2)
  stfs      f0, 0x8(r28)
  stw       r0, 0x4(r28)

.loc_0xDC:
  li        r3, 0xC
  bl        -0x18DC58
  cmplwi    r3, 0
  beq-      .loc_0xF8
  li        r4, -0x1
  li        r5, 0x2
  bl        -0x27F90

.loc_0xF8:
  li        r3, 0xC
  bl        -0x18DC74
  addi      r27, r3, 0
  mr.       r3, r27
  beq-      .loc_0x124
  li        r4, 0x1
  li        r5, 0x8
  bl        -0x27FB0
  lis       r3, 0x802E
  addi      r0, r3, 0x48D0
  stw       r0, 0x4(r27)

.loc_0x124:
  li        r3, 0xC
  bl        -0x18DCA0
  addi      r26, r3, 0
  mr.       r3, r26
  beq-      .loc_0x140
  li        r4, 0x1
  bl        -0xADC20

.loc_0x140:
  li        r0, 0
  lwz       r3, 0x8(r26)
  rlwinm    r0,r0,2,0,29
  stwx      r30, r3, r0
  li        r3, 0xC
  lwz       r4, 0x8(r31)
  stw       r26, 0x0(r4)
  bl        -0x18DCD4
  addi      r26, r3, 0
  mr.       r3, r26
  beq-      .loc_0x174
  li        r4, 0x2
  bl        -0xADC54

.loc_0x174:
  li        r0, 0
  lwz       r3, 0x8(r26)
  rlwinm    r0,r0,2,0,29
  stwx      r29, r3, r0
  li        r0, 0x1
  rlwinm    r0,r0,2,0,29
  lwz       r4, 0x8(r26)
  li        r3, 0xC
  stwx      r28, r4, r0
  lwz       r4, 0x8(r31)
  stw       r26, 0x4(r4)
  bl        -0x18DD18
  addi      r26, r3, 0
  mr.       r3, r26
  beq-      .loc_0x1B8
  li        r4, 0x1
  bl        -0xADC98

.loc_0x1B8:
  li        r0, 0
  lwz       r3, 0x8(r26)
  rlwinm    r0,r0,2,0,29
  stwx      r27, r3, r0
  mr        r3, r31
  lwz       r4, 0x8(r31)
  stw       r26, 0x8(r4)
  lwz       r0, 0x44(r1)
  lmw       r26, 0x28(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801D4D64
 * Size:	000188
 */
void TAIhibaAStrategy::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB8(r1)
  stw       r31, 0xB4(r1)
  stw       r30, 0xB0(r1)
  stw       r29, 0xAC(r1)
  mr        r29, r4
  lwz       r4, 0x2C8(r4)
  lfs       f0, 0x10(r4)
  addi      r5, r4, 0x10
  mr        r4, r29
  stfs      f0, 0x94(r29)
  lfs       f0, 0x4(r5)
  stfs      f0, 0x98(r29)
  lfs       f0, 0x8(r5)
  stfs      f0, 0x9C(r29)
  bl        0x149A4
  lwz       r31, 0x498(r29)
  cmplwi    r31, 0
  beq-      .loc_0x16C
  lwz       r0, 0x80(r31)
  rlwinm.   r0,r0,0,30,30
  bne-      .loc_0x164
  lis       r4, 0x6862
  lwz       r3, 0x220(r29)
  addi      r4, r4, 0x6C70
  bl        -0x14B6BC
  mr.       r30, r3
  beq-      .loc_0x14C
  addi      r3, r1, 0x20
  addi      r4, r30, 0
  bl        -0x14CEC8
  lwz       r3, 0x20(r1)
  lwz       r0, 0x24(r1)
  stw       r3, 0x60(r1)
  lwz       r3, 0x28(r1)
  stw       r0, 0x64(r1)
  lwz       r0, 0x2C(r1)
  stw       r3, 0x68(r1)
  lwz       r3, 0x30(r1)
  stw       r0, 0x6C(r1)
  lwz       r0, 0x34(r1)
  stw       r3, 0x70(r1)
  lwz       r3, 0x38(r1)
  stw       r0, 0x74(r1)
  lwz       r0, 0x3C(r1)
  stw       r3, 0x78(r1)
  lwz       r3, 0x40(r1)
  stw       r0, 0x7C(r1)
  lwz       r0, 0x44(r1)
  stw       r3, 0x80(r1)
  lwz       r3, 0x48(r1)
  stw       r0, 0x84(r1)
  lwz       r0, 0x4C(r1)
  stw       r3, 0x88(r1)
  lwz       r3, 0x50(r1)
  stw       r0, 0x8C(r1)
  lwz       r0, 0x54(r1)
  stw       r3, 0x90(r1)
  lwz       r3, 0x58(r1)
  stw       r0, 0x94(r1)
  lwz       r0, 0x5C(r1)
  stw       r3, 0x98(r1)
  stw       r0, 0x9C(r1)
  lwz       r3, 0x4(r30)
  lwz       r0, 0x8(r30)
  stw       r3, 0xC(r31)
  stw       r0, 0x10(r31)
  lwz       r0, 0xC(r30)
  stw       r0, 0x14(r31)
  lfs       f0, 0x64(r1)
  lfs       f1, 0x74(r1)
  stfs      f0, 0x14(r1)
  lfs       f0, 0x84(r1)
  stfs      f1, 0x18(r1)
  stfs      f0, 0x1C(r1)
  lwz       r3, 0x14(r1)
  lwz       r0, 0x18(r1)
  stw       r3, 0xA0(r31)
  stw       r0, 0xA4(r31)
  lwz       r0, 0x1C(r1)
  stw       r0, 0xA8(r31)
  b         .loc_0x16C

.loc_0x14C:
  lwz       r3, 0x80(r31)
  li        r0, 0
  ori       r3, r3, 0x2
  stw       r3, 0x80(r31)
  stw       r0, 0x498(r29)
  b         .loc_0x16C

.loc_0x164:
  li        r0, 0
  stw       r0, 0x498(r29)

.loc_0x16C:
  lwz       r0, 0xBC(r1)
  lwz       r31, 0xB4(r1)
  lwz       r30, 0xB0(r1)
  lwz       r29, 0xAC(r1)
  addi      r1, r1, 0xB8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801D4EEC
 * Size:	00003C
 */
void TAIhibaAStrategy::draw(Teki &, Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r6, 0x2C8(r4)
  lfsu      f0, 0x10(r6)
  stfs      f0, 0x94(r4)
  lfs       f0, 0x4(r6)
  stfs      f0, 0x98(r4)
  lfs       f0, 0x8(r6)
  stfs      f0, 0x9C(r4)
  bl        0x1498C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801D4F28
 * Size:	0006FC
 */
void TAIhibaAAnimation::makeDefaultAnimations()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xD8(r1)
  stw       r31, 0xD4(r1)
  mr        r31, r3
  stw       r30, 0xD0(r1)
  lwz       r0, 0x4(r3)
  lis       r3, 0x802E
  addi      r30, r3, 0x4630
  cmplwi    r0, 0
  beq-      .loc_0x6E4
  lwz       r6, 0x3160(r13)
  mr        r3, r31
  lwz       r5, 0x2DEC(r13)
  addi      r4, r30, 0x3C
  lwz       r6, 0x124(r6)
  lwz       r0, 0x0(r6)
  stw       r0, 0x1FC(r5)
  bl        -0x319DC
  addi      r3, r31, 0
  addi      r4, r30, 0x58
  bl        -0x319E8
  addi      r3, r31, 0
  addi      r4, r30, 0x78
  bl        -0x319F4
  li        r3, 0x10
  bl        -0x18DF8C
  addi      r6, r3, 0
  mr.       r0, r6
  beq-      .loc_0x8C
  li        r0, 0
  stw       r0, 0x0(r6)
  stb       r0, 0x6(r6)
  stw       r0, 0x8(r6)
  stw       r0, 0xC(r6)

.loc_0x8C:
  lwz       r4, 0x8(r31)
  li        r3, 0x10
  lwz       r5, 0x60(r4)
  lwz       r0, 0xC(r5)
  stw       r0, 0xC(r6)
  stw       r5, 0x8(r6)
  lwz       r4, 0xC(r5)
  stw       r6, 0x8(r4)
  stw       r6, 0xC(r5)
  bl        -0x18DFD4
  addi      r7, r3, 0
  mr.       r0, r7
  beq-      .loc_0xD8
  li        r3, 0x1
  stw       r3, 0x0(r7)
  li        r0, 0
  stb       r3, 0x6(r7)
  stw       r0, 0x8(r7)
  stw       r0, 0xC(r7)

.loc_0xD8:
  lwz       r5, 0x8(r31)
  addi      r3, r31, 0
  addi      r4, r30, 0x98
  lwz       r6, 0x60(r5)
  lwz       r0, 0xC(r6)
  stw       r0, 0xC(r7)
  stw       r6, 0x8(r7)
  lwz       r5, 0xC(r6)
  stw       r7, 0x8(r5)
  stw       r7, 0xC(r6)
  bl        -0x31A94
  li        r3, 0x10
  bl        -0x18E02C
  addi      r6, r3, 0
  mr.       r0, r6
  beq-      .loc_0x12C
  li        r0, 0
  stw       r0, 0x0(r6)
  stb       r0, 0x6(r6)
  stw       r0, 0x8(r6)
  stw       r0, 0xC(r6)

.loc_0x12C:
  lwz       r4, 0x8(r31)
  li        r3, 0x10
  lwz       r5, 0x60(r4)
  lwz       r0, 0xC(r5)
  stw       r0, 0xC(r6)
  stw       r5, 0x8(r6)
  lwz       r4, 0xC(r5)
  stw       r6, 0x8(r4)
  stw       r6, 0xC(r5)
  bl        -0x18E074
  addi      r7, r3, 0
  mr.       r0, r7
  beq-      .loc_0x178
  li        r3, 0x1
  stw       r3, 0x0(r7)
  li        r0, 0
  stb       r3, 0x6(r7)
  stw       r0, 0x8(r7)
  stw       r0, 0xC(r7)

.loc_0x178:
  lwz       r5, 0x8(r31)
  addi      r3, r31, 0
  addi      r4, r30, 0xB8
  lwz       r6, 0x60(r5)
  lwz       r0, 0xC(r6)
  stw       r0, 0xC(r7)
  stw       r6, 0x8(r7)
  lwz       r5, 0xC(r6)
  stw       r7, 0x8(r5)
  stw       r7, 0xC(r6)
  bl        -0x31B34
  lwz       r3, 0x8(r31)
  li        r4, 0x6
  bl        -0x184D10
  lwz       r3, 0x8(r31)
  li        r0, 0x7
  lwz       r3, 0x40(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x8(r31)
  bl        -0x1848C8
  lwz       r3, 0x8(r31)
  li        r0, 0x1B
  lwz       r3, 0x40(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x8(r31)
  bl        -0x1848E0
  li        r3, 0x10
  bl        -0x18E108
  addi      r6, r3, 0
  mr.       r0, r6
  beq-      .loc_0x20C
  li        r0, 0x1
  stw       r0, 0x0(r6)
  li        r0, 0
  stb       r0, 0x6(r6)
  stw       r0, 0x8(r6)
  stw       r0, 0xC(r6)

.loc_0x20C:
  lwz       r4, 0x8(r31)
  li        r3, 0x10
  lwz       r5, 0x60(r4)
  lwz       r0, 0xC(r5)
  stw       r0, 0xC(r6)
  stw       r5, 0x8(r6)
  lwz       r4, 0xC(r5)
  stw       r6, 0x8(r4)
  stw       r6, 0xC(r5)
  bl        -0x18E154
  addi      r7, r3, 0
  mr.       r0, r7
  beq-      .loc_0x25C
  li        r0, 0x2
  stw       r0, 0x0(r7)
  li        r3, 0x1
  li        r0, 0
  stb       r3, 0x6(r7)
  stw       r0, 0x8(r7)
  stw       r0, 0xC(r7)

.loc_0x25C:
  lwz       r5, 0x8(r31)
  addi      r3, r31, 0
  addi      r4, r30, 0xD8
  lwz       r6, 0x60(r5)
  lwz       r0, 0xC(r6)
  stw       r0, 0xC(r7)
  stw       r6, 0x8(r7)
  lwz       r5, 0xC(r6)
  stw       r7, 0x8(r5)
  stw       r7, 0xC(r6)
  bl        -0x31C18
  lwz       r3, 0x8(r31)
  li        r4, 0x6
  bl        -0x184DF4
  lwz       r3, 0x8(r31)
  li        r0, 0x7
  lwz       r3, 0x40(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x8(r31)
  bl        -0x1849AC
  lwz       r3, 0x8(r31)
  li        r0, 0x1B
  lwz       r3, 0x40(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x8(r31)
  bl        -0x1849C4
  li        r3, 0x10
  bl        -0x18E1EC
  addi      r6, r3, 0
  mr.       r0, r6
  beq-      .loc_0x2F0
  li        r0, 0x1
  stw       r0, 0x0(r6)
  li        r0, 0
  stb       r0, 0x6(r6)
  stw       r0, 0x8(r6)
  stw       r0, 0xC(r6)

.loc_0x2F0:
  lwz       r4, 0x8(r31)
  li        r3, 0x10
  lwz       r5, 0x60(r4)
  lwz       r0, 0xC(r5)
  stw       r0, 0xC(r6)
  stw       r5, 0x8(r6)
  lwz       r4, 0xC(r5)
  stw       r6, 0x8(r4)
  stw       r6, 0xC(r5)
  bl        -0x18E238
  addi      r7, r3, 0
  mr.       r0, r7
  beq-      .loc_0x340
  li        r0, 0x2
  stw       r0, 0x0(r7)
  li        r3, 0x1
  li        r0, 0
  stb       r3, 0x6(r7)
  stw       r0, 0x8(r7)
  stw       r0, 0xC(r7)

.loc_0x340:
  lwz       r5, 0x8(r31)
  addi      r3, r31, 0
  addi      r4, r30, 0xF8
  lwz       r6, 0x60(r5)
  lwz       r0, 0xC(r6)
  stw       r0, 0xC(r7)
  stw       r6, 0x8(r7)
  lwz       r5, 0xC(r6)
  stw       r7, 0x8(r5)
  stw       r7, 0xC(r6)
  bl        -0x31CFC
  lwz       r3, 0x8(r31)
  li        r4, 0x6
  bl        -0x184ED8
  lwz       r3, 0x8(r31)
  li        r0, 0xA
  lwz       r3, 0x40(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x8(r31)
  bl        -0x184A90
  lwz       r3, 0x8(r31)
  li        r0, 0x28
  lwz       r3, 0x40(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x8(r31)
  bl        -0x184AA8
  li        r3, 0x10
  bl        -0x18E2D0
  addi      r6, r3, 0
  mr.       r0, r6
  beq-      .loc_0x3D4
  li        r0, 0x1
  stw       r0, 0x0(r6)
  li        r0, 0
  stb       r0, 0x6(r6)
  stw       r0, 0x8(r6)
  stw       r0, 0xC(r6)

.loc_0x3D4:
  lwz       r4, 0x8(r31)
  li        r3, 0x10
  lwz       r5, 0x60(r4)
  lwz       r0, 0xC(r5)
  stw       r0, 0xC(r6)
  stw       r5, 0x8(r6)
  lwz       r4, 0xC(r5)
  stw       r6, 0x8(r4)
  stw       r6, 0xC(r5)
  bl        -0x18E31C
  addi      r7, r3, 0
  mr.       r0, r7
  beq-      .loc_0x424
  li        r0, 0x2
  stw       r0, 0x0(r7)
  li        r3, 0x1
  li        r0, 0
  stb       r3, 0x6(r7)
  stw       r0, 0x8(r7)
  stw       r0, 0xC(r7)

.loc_0x424:
  lwz       r5, 0x8(r31)
  addi      r3, r31, 0
  addi      r4, r30, 0x118
  lwz       r6, 0x60(r5)
  lwz       r0, 0xC(r6)
  stw       r0, 0xC(r7)
  stw       r6, 0x8(r7)
  lwz       r5, 0xC(r6)
  stw       r7, 0x8(r5)
  stw       r7, 0xC(r6)
  bl        -0x31DE0
  lwz       r3, 0x8(r31)
  li        r4, 0x6
  bl        -0x184FBC
  lwz       r3, 0x8(r31)
  li        r0, 0xA
  lwz       r3, 0x40(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x8(r31)
  bl        -0x184B74
  lwz       r3, 0x8(r31)
  li        r0, 0x28
  lwz       r3, 0x40(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x8(r31)
  bl        -0x184B8C
  li        r3, 0x10
  bl        -0x18E3B4
  addi      r6, r3, 0
  mr.       r0, r6
  beq-      .loc_0x4B8
  li        r0, 0x1
  stw       r0, 0x0(r6)
  li        r0, 0
  stb       r0, 0x6(r6)
  stw       r0, 0x8(r6)
  stw       r0, 0xC(r6)

.loc_0x4B8:
  lwz       r4, 0x8(r31)
  li        r3, 0x10
  lwz       r5, 0x60(r4)
  lwz       r0, 0xC(r5)
  stw       r0, 0xC(r6)
  stw       r5, 0x8(r6)
  lwz       r4, 0xC(r5)
  stw       r6, 0x8(r4)
  stw       r6, 0xC(r5)
  bl        -0x18E400
  addi      r7, r3, 0
  mr.       r0, r7
  beq-      .loc_0x508
  li        r0, 0x2
  stw       r0, 0x0(r7)
  li        r3, 0x1
  li        r0, 0
  stb       r3, 0x6(r7)
  stw       r0, 0x8(r7)
  stw       r0, 0xC(r7)

.loc_0x508:
  lwz       r5, 0x8(r31)
  addi      r3, r31, 0
  addi      r4, r30, 0x138
  lwz       r6, 0x60(r5)
  lwz       r0, 0xC(r6)
  stw       r0, 0xC(r7)
  stw       r6, 0x8(r7)
  lwz       r5, 0xC(r6)
  stw       r7, 0x8(r5)
  stw       r7, 0xC(r6)
  bl        -0x31EC4
  lwz       r3, 0x8(r31)
  li        r0, 0x3A
  lwz       r3, 0x40(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x8(r31)
  bl        -0x184C4C
  li        r3, 0x10
  bl        -0x18E474
  addi      r7, r3, 0
  mr.       r0, r7
  beq-      .loc_0x57C
  li        r0, 0x1
  stw       r0, 0x0(r7)
  li        r3, 0x2
  li        r0, 0
  stb       r3, 0x6(r7)
  stw       r0, 0x8(r7)
  stw       r0, 0xC(r7)

.loc_0x57C:
  lwz       r5, 0x8(r31)
  addi      r3, r31, 0
  addi      r4, r30, 0x158
  lwz       r6, 0x60(r5)
  lwz       r0, 0xC(r6)
  stw       r0, 0xC(r7)
  stw       r6, 0x8(r7)
  lwz       r5, 0xC(r6)
  stw       r7, 0x8(r5)
  stw       r7, 0xC(r6)
  bl        -0x31F38
  lwz       r3, 0x8(r31)
  li        r0, 0x8
  lwz       r3, 0x40(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x8(r31)
  bl        -0x184CC0
  lwz       r3, 0x8(r31)
  li        r0, 0x2B
  lwz       r3, 0x40(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x8(r31)
  bl        -0x184CD8
  li        r3, 0x10
  bl        -0x18E500
  addi      r6, r3, 0
  mr.       r0, r6
  beq-      .loc_0x604
  li        r0, 0x1
  stw       r0, 0x0(r6)
  li        r0, 0
  stb       r0, 0x6(r6)
  stw       r0, 0x8(r6)
  stw       r0, 0xC(r6)

.loc_0x604:
  lwz       r4, 0x8(r31)
  li        r3, 0x10
  lwz       r5, 0x60(r4)
  lwz       r0, 0xC(r5)
  stw       r0, 0xC(r6)
  stw       r5, 0x8(r6)
  lwz       r4, 0xC(r5)
  stw       r6, 0x8(r4)
  stw       r6, 0xC(r5)
  bl        -0x18E54C
  addi      r7, r3, 0
  mr.       r0, r7
  beq-      .loc_0x654
  li        r0, 0x2
  stw       r0, 0x0(r7)
  li        r3, 0x1
  li        r0, 0
  stb       r3, 0x6(r7)
  stw       r0, 0x8(r7)
  stw       r0, 0xC(r7)

.loc_0x654:
  lwz       r5, 0x8(r31)
  addi      r3, r31, 0
  addi      r4, r30, 0x178
  lwz       r6, 0x60(r5)
  lwz       r0, 0xC(r6)
  stw       r0, 0xC(r7)
  stw       r6, 0x8(r7)
  lwz       r5, 0xC(r6)
  stw       r7, 0x8(r5)
  stw       r7, 0xC(r6)
  bl        -0x32010
  lwz       r3, 0x8(r31)
  li        r0, 0x20
  lwz       r3, 0x40(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x8(r31)
  bl        -0x184D98
  li        r3, 0x10
  bl        -0x18E5C0
  cmplwi    r3, 0
  beq-      .loc_0x6C4
  li        r0, 0x1
  stw       r0, 0x0(r3)
  li        r4, 0x2
  li        r0, 0
  stb       r4, 0x6(r3)
  stw       r0, 0x8(r3)
  stw       r0, 0xC(r3)

.loc_0x6C4:
  lwz       r4, 0x8(r31)
  lwz       r5, 0x60(r4)
  lwz       r0, 0xC(r5)
  stw       r0, 0xC(r3)
  stw       r5, 0x8(r3)
  lwz       r4, 0xC(r5)
  stw       r3, 0x8(r4)
  stw       r3, 0xC(r5)

.loc_0x6E4:
  lwz       r0, 0xDC(r1)
  lwz       r31, 0xD4(r1)
  lwz       r30, 0xD0(r1)
  addi      r1, r1, 0xD8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801D5624
 * Size:	00003C
 */
void TAIAfireAttackHibaA::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r4
  bl        -0x28934
  lfs       f0, -0x42E0(r2)
  li        r0, 0
  stfs      f0, 0x478(r31)
  stw       r0, 0x498(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801D5660
 * Size:	0002E4
 */
void TAIAfireAttackHibaA::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x180(r1)
  stfd      f31, 0x178(r1)
  stfd      f30, 0x170(r1)
  stw       r31, 0x16C(r1)
  li        r31, 0
  stw       r30, 0x168(r1)
  stw       r29, 0x164(r1)
  addi      r29, r4, 0
  bl        -0x287D0
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2BC
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x478(r29)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x478(r29)
  lwz       r0, 0x3A8(r29)
  cmpwi     r0, 0x5
  bne-      .loc_0x234
  lwz       r0, 0x498(r29)
  cmplwi    r0, 0
  bne-      .loc_0x234
  lis       r4, 0x6862
  lwz       r3, 0x220(r29)
  addi      r4, r4, 0x6C70
  bl        -0x14BFBC
  mr.       r30, r3
  beq-      .loc_0x234
  addi      r3, r1, 0xC8
  addi      r4, r30, 0
  bl        -0x14D7C8
  lwz       r3, 0xC8(r1)
  li        r4, 0xC
  lwz       r0, 0xCC(r1)
  stw       r3, 0x120(r1)
  lwz       r3, 0xD0(r1)
  stw       r0, 0x124(r1)
  lwz       r0, 0xD4(r1)
  stw       r3, 0x128(r1)
  lwz       r3, 0xD8(r1)
  stw       r0, 0x12C(r1)
  lwz       r0, 0xDC(r1)
  stw       r3, 0x130(r1)
  lwz       r3, 0xE0(r1)
  stw       r0, 0x134(r1)
  lwz       r0, 0xE4(r1)
  stw       r3, 0x138(r1)
  lwz       r3, 0xE8(r1)
  stw       r0, 0x13C(r1)
  lwz       r0, 0xEC(r1)
  stw       r3, 0x140(r1)
  lwz       r3, 0xF0(r1)
  stw       r0, 0x144(r1)
  lwz       r0, 0xF4(r1)
  stw       r3, 0x148(r1)
  lwz       r3, 0xF8(r1)
  stw       r0, 0x14C(r1)
  lwz       r0, 0xFC(r1)
  stw       r3, 0x150(r1)
  lwz       r3, 0x100(r1)
  stw       r0, 0x154(r1)
  lwz       r0, 0x104(r1)
  stw       r3, 0x158(r1)
  lfs       f0, -0x42E0(r2)
  stw       r0, 0x15C(r1)
  stfs      f0, 0x11C(r1)
  stfs      f0, 0x118(r1)
  stfs      f0, 0x114(r1)
  lfs       f1, 0x124(r1)
  lfs       f0, 0x134(r1)
  stfs      f1, 0x114(r1)
  stfs      f0, 0x118(r1)
  lfs       f0, 0x144(r1)
  stfs      f0, 0x11C(r1)
  lwz       r3, 0x2C4(r29)
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  bl        -0xB32C8
  lwz       r3, 0x2C4(r29)
  fmr       f30, f1
  li        r4, 0x33
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  bl        -0xB32E0
  lfs       f2, 0x11C(r1)
  fmr       f31, f1
  lfs       f3, 0x2248(r13)
  addi      r6, r1, 0x84
  lfs       f0, 0x114(r1)
  fmuls     f2, f2, f3
  fmuls     f0, f0, f3
  addi      r5, r1, 0x80
  addi      r4, r1, 0x7C
  stfs      f2, 0x84(r1)
  addi      r3, r1, 0xB0
  lfs       f1, 0x118(r1)
  fmuls     f1, f1, f3
  stfs      f0, 0x7C(r1)
  stfs      f1, 0x80(r1)
  bl        -0x19E6D8
  lfs       f0, 0xB0(r1)
  fmr       f1, f31
  lfs       f3, 0xB4(r1)
  fmr       f2, f30
  stfs      f0, 0x98(r1)
  lfs       f0, 0xB8(r1)
  stfs      f3, 0x9C(r1)
  addi      r7, r1, 0x98
  lfs       f3, -0x4288(r2)
  mr        r5, r29
  stfs      f0, 0xA0(r1)
  lfs       f4, -0x4284(r2)
  addi      r3, r29, 0x528
  addi      r4, r29, 0x4CC
  addi      r6, r30, 0x4
  addi      r8, r13, 0x31B8
  bl        -0x10EA0
  lwz       r0, 0x498(r29)
  cmplwi    r0, 0
  bne-      .loc_0x234
  lwz       r3, 0x3180(r13)
  addi      r6, r29, 0x528
  addi      r5, r30, 0x4
  li        r4, 0xE3
  li        r7, 0
  bl        -0x38D24
  mr.       r30, r3
  beq-      .loc_0x230
  lwz       r6, 0x114(r1)
  mr        r3, r29
  lwz       r0, 0x118(r1)
  addi      r4, r29, 0
  li        r5, 0x3C
  stw       r6, 0xA0(r30)
  stw       r0, 0xA4(r30)
  lwz       r0, 0x11C(r1)
  stw       r0, 0xA8(r30)
  bl        -0x14B2D8

.loc_0x230:
  stw       r30, 0x498(r29)

.loc_0x234:
  lwz       r3, 0x2C4(r29)
  lfs       f1, 0x478(r29)
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  lwz       r3, 0x0(r3)
  lfs       f0, 0xCC(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x2AC
  cmplwi    r29, 0
  addi      r5, r29, 0
  beq-      .loc_0x264
  lwz       r5, 0x2C0(r29)

.loc_0x264:
  addi      r3, r1, 0xA8
  li        r4, -0x1
  bl        -0xB6940
  mr        r4, r3
  lwz       r3, 0x2CC(r29)
  bl        -0xB66A8
  lwz       r5, 0x498(r29)
  cmplwi    r5, 0
  beq-      .loc_0x2AC
  lwz       r4, 0x80(r5)
  li        r0, 0
  addi      r3, r29, 0
  ori       r4, r4, 0x2
  stw       r4, 0x80(r5)
  addi      r4, r29, 0
  li        r5, 0x3C
  stw       r0, 0x498(r29)
  bl        -0x14B31C

.loc_0x2AC:
  lwz       r0, 0x3A8(r29)
  cmpwi     r0, 0
  bne-      .loc_0x2BC
  li        r31, 0x1

.loc_0x2BC:
  mr        r3, r31
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
 * Address:	801D5944
 * Size:	000018
 */
void TAIAtimerReactionHibaA::getFrameMax(Teki &)
{
/*
.loc_0x0:
  lwz       r3, 0x2C4(r4)
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  lwz       r3, 0x0(r3)
  lfs       f1, 0xC8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801D595C
 * Size:	000064
 */
void TAIAinitHibaA::start(Teki &)
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
  lwz       r4, -0x9C8(r13)
  lwz       r12, 0x1D0(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC8(r31)
  addi      r3, r31, 0
  ori       r0, r0, 0x200
  stw       r0, 0xC8(r31)
  lwz       r12, 0x0(r31)
  lwz       r4, -0x9C0(r13)
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
 * Address:	801D59C0
 * Size:	000008
 */
u32  TAIAinitHibaA::act(Teki &)
{
	return 0x1;
}

/*
 * --INFO--
 * Address:	801D59C8
 * Size:	000010
 */
void __sinit_TAIhibaA_cpp(void)
{
/*
.loc_0x0:
  lis       r3, 0x802E
  addi      r0, r3, 0x4ADC
  stw       r0, 0x31B8(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	801D59D8
 * Size:	000068
 */
void TAIeffectAttackEventCallBackHibaA::hitCreature(TAIeffectAttackParam *, Creature *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x802B
  stw       r0, 0x4(r1)
  subi      r0, r3, 0x3064
  lis       r3, 0x802B
  stwu      r1, -0x30(r1)
  lwz       r6, 0x2DEC(r13)
  lfs       f1, 0x34(r4)
  addi      r4, r1, 0x20
  lfs       f0, 0x28C(r6)
  stw       r0, 0x20(r1)
  subi      r0, r3, 0x30D8
  fmuls     f0, f1, f0
  mr        r3, r5
  stw       r5, 0x24(r1)
  stw       r0, 0x20(r1)
  stfs      f0, 0x28(r1)
  lwz       r12, 0x0(r5)
  lwz       r12, 0xA0(r12)
  mtlr      r12
  blrl      
  li        r3, 0
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801D5A40
 * Size:	000154
 */
void TAIeffectAttackEventCallBackHibaA::hitMap(TAIeffectAttackParam *)
{
/*
.loc_0x0:
  mflr      r0
  li        r7, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x68(r1)
  stw       r31, 0x64(r1)
  addi      r5, r1, 0x2C
  li        r31, 0
  stw       r30, 0x60(r1)
  addi      r30, r4, 0
  li        r4, 0
  lfs       f0, -0x42E0(r2)
  stfs      f0, 0x34(r1)
  stfs      f0, 0x30(r1)
  stfs      f0, 0x2C(r1)
  stfs      f0, 0x40(r1)
  stfs      f0, 0x3C(r1)
  stfs      f0, 0x38(r1)
  stb       r7, 0x4C(r1)
  lwz       r3, 0x10(r30)
  lwz       r0, 0x14(r30)
  stw       r3, 0x2C(r1)
  stw       r0, 0x30(r1)
  lwz       r0, 0x18(r30)
  stw       r0, 0x34(r1)
  lwz       r3, 0x1C(r30)
  lwz       r0, 0x20(r30)
  stw       r3, 0x38(r1)
  stw       r0, 0x3C(r1)
  lwz       r0, 0x24(r30)
  stw       r0, 0x40(r1)
  lfs       f1, -0x429C(r2)
  lfs       f0, -0x42D0(r2)
  stfs      f1, 0x44(r1)
  lwz       r6, 0x2DEC(r13)
  stw       r7, 0x50(r1)
  lwz       r3, 0x2F00(r13)
  stfs      f0, 0x48(r1)
  lfs       f1, 0x28C(r6)
  bl        -0x16CC84
  lfs       f0, 0x1C(r30)
  lfs       f2, 0x38(r1)
  fcmpu     cr0, f0, f2
  bne-      .loc_0xCC
  lfs       f1, 0x20(r30)
  lfs       f0, 0x3C(r1)
  fcmpu     cr0, f1, f0
  bne-      .loc_0xCC
  lfs       f1, 0x24(r30)
  lfs       f0, 0x40(r1)
  fcmpu     cr0, f1, f0
  beq-      .loc_0x138

.loc_0xCC:
  lfs       f0, 0x3C(r1)
  fmuls     f1, f2, f2
  lfs       f2, 0x40(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x1C7EE8
  lfs       f0, -0x42E0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x11C
  lfs       f0, 0x38(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x38(r1)
  lfs       f0, 0x3C(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x3C(r1)
  lfs       f0, 0x40(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x40(r1)

.loc_0x11C:
  lwz       r3, 0x38(r1)
  li        r31, 0x1
  lwz       r0, 0x3C(r1)
  stw       r3, 0x1C(r30)
  stw       r0, 0x20(r30)
  lwz       r0, 0x40(r1)
  stw       r0, 0x24(r30)

.loc_0x138:
  mr        r3, r31
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
 * Address:	801D5B94
 * Size:	0001DC
 */
void TAIeffectAttackEventCallBackHibaA::ptclHitMap(zen::particleGenerator *, TAIeffectAttackParam *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xC8(r1)
  stfd      f31, 0xC0(r1)
  stfd      f30, 0xB8(r1)
  stfd      f29, 0xB0(r1)
  stfd      f28, 0xA8(r1)
  stfd      f27, 0xA0(r1)
  stmw      r24, 0x80(r1)
  mr        r25, r5
  addi      r24, r4, 0
  lbz       r0, 0x4C(r5)
  rlwinm.   r0,r0,25,31,31
  bne-      .loc_0x1B4
  lwz       r28, 0x28(r24)
  addi      r31, r1, 0x50
  lfs       f29, -0x42E0(r2)
  addi      r30, r1, 0x5C
  lwz       r27, 0x8(r28)
  lfd       f30, -0x4280(r2)
  addi      r29, r1, 0x68
  lfd       f31, -0x4278(r2)
  lfs       f28, -0x42D0(r2)
  lfs       f27, -0x4270(r2)
  b         .loc_0x1AC

.loc_0x64:
  lwz       r7, 0x18(r24)
  lwz       r26, 0x8(r27)
  cmplwi    r7, 0
  beq-      .loc_0x78
  b         .loc_0x7C

.loc_0x78:
  addi      r7, r24, 0xC

.loc_0x7C:
  lfs       f0, 0x10(r25)
  addi      r3, r29, 0
  addi      r4, r30, 0
  stfs      f0, 0x50(r1)
  addi      r5, r31, 0
  addi      r6, r1, 0x74
  lfs       f0, 0x14(r25)
  stfs      f0, 0x54(r1)
  lfs       f0, 0x18(r25)
  stfs      f0, 0x58(r1)
  lfs       f0, 0x0(r7)
  stfs      f0, 0x5C(r1)
  lfs       f0, 0x4(r7)
  stfs      f0, 0x60(r1)
  lfs       f0, 0x8(r7)
  stfs      f0, 0x64(r1)
  lfs       f1, 0xC(r27)
  lfs       f0, 0x18(r27)
  lfs       f4, 0x14(r27)
  lfs       f3, 0x20(r27)
  fadds     f0, f1, f0
  lfs       f2, 0x10(r27)
  lfs       f1, 0x1C(r27)
  fadds     f3, f4, f3
  stfs      f0, 0x40(r1)
  fadds     f1, f2, f1
  lfs       f0, 0x40(r1)
  stfs      f0, 0x68(r1)
  stfs      f1, 0x6C(r1)
  stfs      f3, 0x70(r1)
  bl        -0x3A368
  lfs       f0, 0x74(r1)
  fcmpo     cr0, f0, f28
  cror      2, 0x1, 0x2
  bne-      .loc_0x1A8
  lfs       f1, 0x34(r27)
  lfs       f0, 0x38(r27)
  fmuls     f1, f1, f1
  lfs       f2, 0x3C(r27)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f2, f2, f0
  fcmpo     cr0, f2, f29
  ble-      .loc_0x180
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
  stfs      f0, 0x38(r1)
  lfs       f2, 0x38(r1)

.loc_0x180:
  fmuls     f4, f27, f2
  lfs       f0, 0x1C(r25)
  lfs       f1, 0x20(r25)
  lfs       f2, 0x24(r25)
  fmuls     f0, f0, f4
  fmuls     f3, f1, f4
  fmuls     f1, f2, f4
  stfs      f0, 0x34(r27)
  stfs      f3, 0x38(r27)
  stfs      f1, 0x3C(r27)

.loc_0x1A8:
  mr        r27, r26

.loc_0x1AC:
  cmplw     r27, r28
  bne+      .loc_0x64

.loc_0x1B4:
  lmw       r24, 0x80(r1)
  lwz       r0, 0xCC(r1)
  lfd       f31, 0xC0(r1)
  lfd       f30, 0xB8(r1)
  lfd       f29, 0xB0(r1)
  lfd       f28, 0xA8(r1)
  lfd       f27, 0xA0(r1)
  addi      r1, r1, 0xC8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801D5D70
 * Size:	0000E0
 */
void TAIeffectAttackEventCallBackHibaA::hitCheckCulling(zen::particleGenerator *, TAIeffectAttackParam *, Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  li        r31, 0
  stw       r30, 0x38(r1)
  addi      r30, r6, 0
  addi      r3, r30, 0
  stw       r29, 0x34(r1)
  addi      r29, r5, 0
  stw       r28, 0x30(r1)
  addi      r28, r4, 0
  lwz       r12, 0x0(r30)
  lwz       r12, 0x5C(r12)
  mtlr      r12
  blrl      
  lfs       f0, 0x8(r29)
  lwz       r4, 0x18(r28)
  fadds     f3, f0, f1
  cmplwi    r4, 0
  beq-      .loc_0x5C
  mr        r3, r4
  b         .loc_0x60

.loc_0x5C:
  addi      r3, r28, 0xC

.loc_0x60:
  lfs       f2, 0x94(r30)
  lfs       f1, 0x0(r3)
  lfs       f0, -0x42E0(r2)
  fsubs     f1, f2, f1
  fcmpo     cr0, f1, f0
  bge-      .loc_0x7C
  fneg      f1, f1

.loc_0x7C:
  fcmpo     cr0, f1, f3
  bge-      .loc_0xBC
  cmplwi    r4, 0
  beq-      .loc_0x90
  b         .loc_0x94

.loc_0x90:
  addi      r4, r28, 0xC

.loc_0x94:
  lfs       f2, 0x9C(r30)
  lfs       f1, 0x8(r4)
  lfs       f0, -0x42E0(r2)
  fsubs     f1, f2, f1
  fcmpo     cr0, f1, f0
  bge-      .loc_0xB0
  fneg      f1, f1

.loc_0xB0:
  fcmpo     cr0, f1, f3
  bge-      .loc_0xBC
  li        r31, 0x1

.loc_0xBC:
  mr        r3, r31
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
