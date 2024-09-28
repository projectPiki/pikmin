#include "TAI/Tank.h"
#include "TAI/Areaction.h"

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
 * Address:	801A35D0
 * Size:	000084
 */
TAItankSoundTable::TAItankSoundTable()
    : PaniSoundTable(7)
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
	  bl        -0x8457C
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0x15C600
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
 * Address:	801A3654
 * Size:	000364
 */
TAItankParameters::TAItankParameters()
    : TekiParameters(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802E
	  stw       r0, 0x4(r1)
	  li        r5, 0x36
	  stwu      r1, -0xD0(r1)
	  stw       r31, 0xCC(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xC8(r1)
	  subi      r30, r4, 0x2390
	  li        r4, 0x14
	  bl        -0x57934
	  lis       r3, 0x802E
	  subi      r0, r3, 0x1C24
	  stw       r0, 0x0(r31)
	  li        r6, 0x32
	  li        r5, 0x33
	  lwz       r4, 0x84(r31)
	  li        r3, 0x34
	  li        r0, 0x35
	  lwz       r7, 0x4(r4)
	  mulli     r6, r6, 0xC
	  lwz       r8, 0x8(r7)
	  mulli     r5, r5, 0xC
	  add       r7, r8, r6
	  addi      r6, r30, 0xC
	  stw       r6, 0x0(r7)
	  mulli     r3, r3, 0xC
	  lfs       f5, -0x4BA8(r2)
	  mulli     r0, r0, 0xC
	  stfs      f5, 0x4(r7)
	  lfs       f2, -0x4BA4(r2)
	  add       r6, r8, r5
	  addi      r5, r30, 0x20
	  stfs      f2, 0x8(r7)
	  add       r11, r8, r3
	  addi      r10, r30, 0x34
	  stw       r5, 0x0(r6)
	  add       r12, r8, r0
	  addi      r3, r30, 0x40
	  stfs      f5, 0x4(r6)
	  li        r0, 0x1
	  li        r9, -0x1
	  lfs       f4, -0x4BA0(r2)
	  li        r8, 0x5
	  li        r7, 0x2
	  stfs      f4, 0x8(r6)
	  li        r6, 0xA
	  li        r5, 0x3
	  stw       r10, 0x0(r11)
	  stfs      f5, 0x4(r11)
	  stfs      f2, 0x8(r11)
	  stw       r3, 0x0(r12)
	  stfs      f5, 0x4(r12)
	  lfs       f3, -0x4B9C(r2)
	  stfs      f3, 0x8(r12)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0xC8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B98(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xCC(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x4B94(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0xD4(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x0(r3)
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
	  stw       r0, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B90(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x4B8C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B88(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x10(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B84(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B80(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B7C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x20(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x24(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x4B78(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x28(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B74(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x2C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x30(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B70(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x3C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B6C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x78(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B68(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x7C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B64(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x80(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B60(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x84(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x88(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x8C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x90(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4B5C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x94(r3)
	  lwz       r5, 0x4(r4)
	  li        r0, 0
	  lfs       f1, -0x4B58(r2)
	  mr        r3, r31
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x44(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0x48(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4B54(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x98(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x50(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4B50(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x54(r5)
	  lwz       r4, 0x0(r4)
	  lwz       r4, 0x0(r4)
	  stw       r0, 0x8(r4)
	  lwz       r0, 0xD4(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A39B8
 * Size:	000C14
 */
TAItankStrategy::TAItankStrategy()
    : YaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0xC
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  stwu      r1, -0xE8(r1)
	  stmw      r14, 0xA0(r1)
	  addi      r31, r3, 0
	  bl        0x45C80
	  lis       r3, 0x802E
	  subi      r0, r3, 0x216C
	  stw       r0, 0x0(r31)
	  li        r3, 0x2C
	  bl        -0x15C9E4
	  lis       r4, 0x8003
	  addi      r4, r4, 0x5B24
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x3
	  bl        0x71228
	  lfs       f0, 0x1210(r13)
	  mr        r5, r3
	  addi      r23, r5, 0
	  stfs      f0, 0x0(r3)
	  li        r3, 0x8
	  lfs       f0, 0x1214(r13)
	  stfs      f0, 0x4(r5)
	  lfs       f0, 0x1218(r13)
	  stfs      f0, 0x8(r5)
	  lfs       f0, 0x121C(r13)
	  stfs      f0, 0xC(r5)
	  lfs       f0, 0x1220(r13)
	  stfs      f0, 0x10(r5)
	  lfs       f0, 0x1224(r13)
	  stfs      f0, 0x14(r5)
	  lfs       f0, 0x1228(r13)
	  stfs      f0, 0x18(r5)
	  lfs       f0, 0x122C(r13)
	  stfs      f0, 0x1C(r5)
	  lfs       f0, 0x1230(r13)
	  stfs      f0, 0x20(r5)
	  bl        -0x15CA54
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xD0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0
	  lis       r3, 0x802E
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0xCB4
	  stw       r0, 0x4(r29)

	.loc_0xD0:
	  li        r3, 0xC
	  bl        -0x15CA88
	  stw       r3, 0x9C(r1)
	  lwz       r3, 0x9C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x104
	  li        r4, -0x1
	  li        r5, 0
	  bl        0x91AC
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  lwz       r3, 0x9C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x104:
	  li        r3, 0xC
	  bl        -0x15CABC
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x140
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r30)
	  subi      r3, r3, 0xE10
	  li        r0, 0x1
	  stw       r3, 0x4(r30)
	  stb       r0, 0x8(r30)

	.loc_0x140:
	  li        r3, 0x8
	  bl        -0x15CAF8
	  stw       r3, 0x98(r1)
	  lwz       r0, 0x98(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x184
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x98(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x98(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6EC
	  lwz       r3, 0x98(r1)
	  stw       r0, 0x4(r3)

	.loc_0x184:
	  li        r3, 0x24
	  bl        -0x15CB3C
	  stw       r3, 0x94(r1)
	  lwz       r3, 0x94(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x1CC
	  addi      r8, r23, 0
	  li        r4, -0x1
	  li        r5, 0x6
	  li        r6, 0x4
	  li        r7, 0x4
	  li        r9, 0x3
	  li        r10, 0x1
	  bl        0x6B5C
	  lis       r3, 0x802E
	  subi      r0, r3, 0x1CF4
	  lwz       r3, 0x94(r1)
	  stw       r0, 0x4(r3)

	.loc_0x1CC:
	  li        r3, 0x8
	  bl        -0x15CB84
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x200
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r23)
	  li        r0, 0x3
	  lis       r3, 0x802E
	  stw       r0, 0x0(r23)
	  subi      r0, r3, 0x124
	  stw       r0, 0x4(r23)

	.loc_0x200:
	  li        r3, 0x8
	  bl        -0x15CBB8
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x234
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, 0x3
	  lis       r3, 0x802E
	  stw       r0, 0x0(r25)
	  subi      r0, r3, 0xEC
	  stw       r0, 0x4(r25)

	.loc_0x234:
	  li        r3, 0x10
	  bl        -0x15CBEC
	  stw       r3, 0x90(r1)
	  lwz       r3, 0x90(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x274
	  li        r4, 0x5
	  li        r5, 0x2
	  bl        0x90D4
	  lis       r3, 0x802E
	  subi      r0, r3, 0x7D4
	  lwz       r3, 0x90(r1)
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x90(r1)
	  lfs       f0, -0x4B4C(r2)
	  stfs      f0, 0xC(r3)

	.loc_0x274:
	  li        r3, 0x10
	  bl        -0x15CC2C
	  stw       r3, 0x8C(r1)
	  lwz       r3, 0x8C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x2B4
	  li        r4, 0x2
	  li        r5, 0x5
	  bl        0x9094
	  lis       r3, 0x802E
	  subi      r0, r3, 0x7D4
	  lwz       r3, 0x8C(r1)
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x8C(r1)
	  lfs       f0, -0x4BA8(r2)
	  stfs      f0, 0xC(r3)

	.loc_0x2B4:
	  li        r3, 0x8
	  bl        -0x15CC6C
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x2F4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, 0x6
	  lis       r3, 0x802E
	  stw       r0, 0x0(r19)
	  subi      r0, r3, 0x160
	  lis       r3, 0x802E
	  stw       r0, 0x4(r19)
	  subi      r0, r3, 0x1D98
	  stw       r0, 0x4(r19)

	.loc_0x2F4:
	  li        r3, 0x18
	  bl        -0x15CCAC
	  addi      r22, r3, 0
	  mr.       r3, r22
	  beq-      .loc_0x340
	  li        r4, 0x7
	  li        r5, 0x4
	  bl        0x9018
	  lis       r3, 0x802E
	  subi      r0, r3, 0x6D0
	  stw       r0, 0x4(r22)
	  li        r4, 0x4
	  lis       r3, 0x802E
	  stw       r4, 0xC(r22)
	  li        r0, 0x1
	  subi      r3, r3, 0x780
	  stw       r4, 0x10(r22)
	  stb       r0, 0x14(r22)
	  stw       r3, 0x4(r22)

	.loc_0x340:
	  li        r3, 0x8
	  bl        -0x15CCF8
	  addi      r15, r3, 0
	  mr.       r0, r15
	  beq-      .loc_0x374
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r15)
	  li        r0, 0x4
	  lis       r3, 0x802E
	  stw       r0, 0x0(r15)
	  subi      r0, r3, 0x1A0
	  stw       r0, 0x4(r15)

	.loc_0x374:
	  li        r3, 0x8
	  bl        -0x15CD2C
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x3C0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r21)
	  li        r0, 0x7
	  lis       r3, 0x802E
	  stw       r0, 0x0(r21)
	  addi      r0, r3, 0xDC
	  lis       r3, 0x802E
	  stw       r0, 0x4(r21)
	  addi      r0, r3, 0x60
	  lis       r3, 0x802E
	  stw       r0, 0x4(r21)
	  subi      r0, r3, 0x1E14
	  stw       r0, 0x4(r21)

	.loc_0x3C0:
	  li        r3, 0xC
	  bl        -0x15CD78
	  stw       r3, 0x88(r1)
	  lwz       r3, 0x88(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x404
	  li        r4, 0x7
	  li        r5, 0x7
	  bl        0x8F48
	  lis       r3, 0x802E
	  subi      r0, r3, 0x888
	  lwz       r3, 0x88(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x1EC4
	  lwz       r3, 0x88(r1)
	  stw       r0, 0x4(r3)

	.loc_0x404:
	  li        r3, 0x4
	  bl        -0x15CDBC
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x430
	  lis       r3, 0x802E
	  subi      r0, r3, 0x1F24
	  lis       r3, 0x802E
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x1F30
	  stw       r0, 0x0(r26)

	.loc_0x430:
	  li        r3, 0x10
	  bl        -0x15CDE8
	  addi      r14, r3, 0
	  mr.       r3, r14
	  beq-      .loc_0x46C
	  li        r4, 0x8
	  li        r5, 0x8
	  bl        0x8EDC
	  lis       r3, 0x802E
	  addi      r0, r3, 0x410
	  stw       r0, 0x4(r14)
	  lis       r3, 0x802E
	  subi      r0, r3, 0x1F84
	  stw       r26, 0xC(r14)
	  stw       r0, 0x4(r14)

	.loc_0x46C:
	  li        r3, 0xC
	  bl        -0x15CE24
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x4A8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, 0x9
	  lis       r3, 0x802E
	  stw       r0, 0x0(r26)
	  addi      r3, r3, 0x3CC
	  li        r0, -0x1
	  stw       r3, 0x4(r26)
	  stw       r0, 0x8(r26)

	.loc_0x4A8:
	  li        r3, 0xC
	  bl        -0x15CE60
	  stw       r3, 0x84(r1)
	  lwz       r3, 0x84(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x4EC
	  li        r4, 0x7
	  li        r5, 0x9
	  bl        0x8DD4
	  lis       r3, 0x802E
	  addi      r0, r3, 0x34C
	  lwz       r3, 0x84(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x201C
	  lwz       r3, 0x84(r1)
	  stw       r0, 0x4(r3)

	.loc_0x4EC:
	  li        r3, 0xC
	  bl        -0x15CEA4
	  stw       r3, 0x80(r1)
	  lwz       r3, 0x80(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x520
	  li        r4, 0xB
	  li        r5, 0xA
	  bl        0x8E1C
	  lis       r3, 0x802E
	  subi      r0, r3, 0x720
	  lwz       r3, 0x80(r1)
	  stw       r0, 0x4(r3)

	.loc_0x520:
	  li        r3, 0xC
	  bl        -0x15CED8
	  stw       r3, 0x7C(r1)
	  lwz       r3, 0x7C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x554
	  li        r4, 0x2
	  li        r5, 0xA
	  bl        0x8DE8
	  lis       r3, 0x802E
	  subi      r0, r3, 0x978
	  lwz       r3, 0x7C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x554:
	  li        r3, 0x8
	  bl        -0x15CF0C
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x588
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, 0xB
	  lis       r3, 0x802E
	  stw       r0, 0x0(r17)
	  subi      r0, r3, 0x20A4
	  stw       r0, 0x4(r17)

	.loc_0x588:
	  li        r3, 0x24
	  bl        -0x15CF40
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x5F4
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r28)
	  lis       r4, 0x6173
	  li        r0, -0x1
	  lis       r5, 0x802E
	  stw       r0, 0x0(r28)
	  addi      r0, r5, 0x4BA8
	  stw       r0, 0x4(r28)
	  addi      r5, r4, 0x6933
	  addi      r0, r4, 0x6934
	  stw       r5, 0x8(r1)
	  addi      r9, r4, 0x6931
	  addi      r10, r4, 0x6932
	  stw       r0, 0xC(r1)
	  li        r4, 0x44
	  li        r5, 0x1
	  lwz       r7, 0x22F0(r13)
	  li        r6, 0x3E
	  lfs       f1, -0x4B48(r2)
	  li        r8, 0x4
	  bl        0x31EA8

	.loc_0x5F4:
	  li        r3, 0x8
	  bl        -0x15CFAC
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x628
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x2
	  lis       r3, 0x802E
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x20E4
	  stw       r0, 0x4(r27)

	.loc_0x628:
	  li        r3, 0x8
	  bl        -0x15CFE0
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x65C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, 0x5
	  lis       r3, 0x802E
	  stw       r0, 0x0(r16)
	  subi      r0, r3, 0x124
	  stw       r0, 0x4(r16)

	.loc_0x65C:
	  li        r3, 0x8
	  bl        -0x15D014
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x690
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, 0x5
	  lis       r3, 0x802E
	  stw       r0, 0x0(r18)
	  subi      r0, r3, 0xEC
	  stw       r0, 0x4(r18)

	.loc_0x690:
	  li        r3, 0x8
	  bl        -0x15D048
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x6C4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, 0x2
	  lis       r3, 0x802E
	  stw       r0, 0x0(r20)
	  subi      r0, r3, 0x211C
	  stw       r0, 0x4(r20)

	.loc_0x6C4:
	  li        r3, 0xC
	  bl        -0x15D07C
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x6E0
	  li        r4, 0x1
	  bl        -0x7CFFC

	.loc_0x6E0:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x4(r4)
	  bl        -0x15D0B0
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x714
	  li        r4, 0x2
	  bl        -0x7D030

	.loc_0x714:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x9C(r1)
	  stwx      r0, r3, r4
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x98(r1)
	  lwz       r5, 0x8(r27)
	  li        r3, 0xC
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x0(r4)
	  bl        -0x15D0FC
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x760
	  li        r4, 0x7
	  bl        -0x7D07C

	.loc_0x760:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r27)
	  li        r3, 0x2
	  li        r6, 0x3
	  stwx      r30, r4, r0
	  rlwinm    r4,r3,2,0,29
	  li        r0, 0x4
	  lwz       r3, 0x94(r1)
	  lwz       r5, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r3, r5, r4
	  li        r8, 0x5
	  rlwinm    r4,r6,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r7, 0x6
	  rlwinm    r5,r8,2,0,29
	  stwx      r25, r3, r4
	  rlwinm    r6,r7,2,0,29
	  li        r3, 0xC
	  lwz       r4, 0x8(r27)
	  stwx      r23, r4, r0
	  lwz       r4, 0x8(r27)
	  stwx      r26, r4, r5
	  lwz       r4, 0x8(r27)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x8(r4)
	  bl        -0x15D194
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x7F8
	  li        r4, 0x5
	  bl        -0x7D114

	.loc_0x7F8:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r4,r4,2,0,29
	  li        r5, 0x3
	  stwx      r30, r3, r4
	  li        r4, 0x4
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r27)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r26, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0x90(r1)
	  lwz       r6, 0x8(r27)
	  stwx      r0, r6, r5
	  lwz       r5, 0x8(r27)
	  stwx      r28, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r27, 0xC(r4)
	  bl        -0x15D20C
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x870
	  li        r4, 0x3
	  bl        -0x7D18C

	.loc_0x870:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r5,r4,2,0,29
	  stwx      r30, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0x8C(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x10(r4)
	  bl        -0x15D264
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x8C8
	  li        r4, 0x7
	  bl        -0x7D1E4

	.loc_0x8C8:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  li        r0, 0x1
	  li        r3, 0x2
	  lwz       r4, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r30, r4, r0
	  li        r0, 0x4
	  li        r7, 0x5
	  lwz       r4, 0x8(r27)
	  rlwinm    r3,r3,2,0,29
	  li        r6, 0x6
	  stwx      r26, r4, r3
	  rlwinm    r4,r5,2,0,29
	  rlwinm    r5,r0,2,0,29
	  lwz       r3, 0x8(r27)
	  rlwinm    r7,r7,2,0,29
	  rlwinm    r0,r6,2,0,29
	  stwx      r19, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r27)
	  stwx      r22, r4, r5
	  lwz       r4, 0x8(r27)
	  stwx      r15, r4, r7
	  lwz       r4, 0x8(r27)
	  stwx      r28, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x14(r4)
	  bl        -0x15D2F8
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x95C
	  li        r4, 0x8
	  bl        -0x7D278

	.loc_0x95C:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r0, 0x3
	  li        r6, 0x5
	  stwx      r30, r3, r5
	  li        r4, 0x2
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r7, 0x4
	  rlwinm    r0,r0,2,0,29
	  stwx      r17, r3, r5
	  li        r4, 0x6
	  li        r5, 0x7
	  lwz       r3, 0x8(r27)
	  rlwinm    r8,r6,2,0,29
	  rlwinm    r6,r5,2,0,29
	  lwz       r5, 0x88(r1)
	  stwx      r26, r3, r0
	  rlwinm    r0,r4,2,0,29
	  lwz       r4, 0x8(r27)
	  rlwinm    r7,r7,2,0,29
	  li        r3, 0xC
	  stwx      r5, r4, r7
	  lwz       r4, 0x8(r27)
	  stwx      r21, r4, r8
	  lwz       r4, 0x8(r27)
	  stwx      r15, r4, r0
	  lwz       r4, 0x8(r27)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x18(r4)
	  bl        -0x15D3A0
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0xA04
	  li        r4, 0x5
	  bl        -0x7D320

	.loc_0xA04:
	  li        r0, 0
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r29, r3, r0
	  li        r0, 0x4
	  rlwinm    r4,r4,2,0,29
	  lwz       r3, 0x8(r26)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r26)
	  stwx      r14, r4, r5
	  lwz       r5, 0x98(r1)
	  lwz       r4, 0x8(r26)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r26, 0x1C(r4)
	  bl        -0x15D418
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0xA7C
	  li        r4, 0x3
	  bl        -0x7D398

	.loc_0xA7C:
	  li        r0, 0
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  stwx      r16, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r26)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r26)
	  stwx      r20, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r26, 0x20(r4)
	  bl        -0x15D46C
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0xAD0
	  li        r4, 0x4
	  bl        -0x7D3EC

	.loc_0xAD0:
	  li        r0, 0
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  li        r4, 0x1
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r26)
	  li        r0, 0x2
	  rlwinm    r6,r0,2,0,29
	  lwz       r0, 0x84(r1)
	  stwx      r30, r3, r5
	  li        r4, 0x3
	  rlwinm    r5,r4,2,0,29
	  lwz       r4, 0x8(r26)
	  li        r3, 0xC
	  stwx      r0, r4, r6
	  lwz       r4, 0x8(r26)
	  stwx      r28, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r26, 0x24(r4)
	  bl        -0x15D4D4
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0xB38
	  li        r4, 0x5
	  bl        -0x7D454

	.loc_0xB38:
	  li        r0, 0
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  lwz       r6, 0x80(r1)
	  stwx      r29, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x3
	  stwx      r30, r3, r0
	  li        r0, 0x4
	  rlwinm    r5,r5,2,0,29
	  lwz       r3, 0x8(r26)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r17, r3, r5
	  li        r3, 0xC
	  lwz       r5, 0x8(r26)
	  stwx      r6, r5, r4
	  lwz       r4, 0x8(r26)
	  stwx      r28, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r26, 0x28(r4)
	  bl        -0x15D54C
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0xBB0
	  li        r4, 0x4
	  bl        -0x7D4CC

	.loc_0xBB0:
	  li        r0, 0
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x3
	  stwx      r30, r3, r0
	  rlwinm    r5,r4,2,0,29
	  rlwinm    r4,r6,2,0,29
	  lwz       r0, 0x7C(r1)
	  lwz       r6, 0x8(r26)
	  mr        r3, r31
	  stwx      r0, r6, r5
	  lwz       r5, 0x8(r26)
	  stwx      r28, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r26, 0x2C(r4)
	  lmw       r14, 0xA0(r1)
	  lwz       r0, 0xEC(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A45CC
 * Size:	000120
 */
void TAItankStrategy::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r4
	  stw       r30, 0x30(r1)
	  bl        0x45160
	  lis       r4, 0x6B75
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x7469
	  bl        -0x11AEE8
	  lfs       f1, 0xA0(r31)
	  mr        r30, r3
	  bl        0x77550
	  lfs       f0, 0xA0(r31)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x776D4
	  stfs      f1, 0x20(r1)
	  lfs       f0, 0x1234(r13)
	  stfs      f0, 0x24(r1)
	  stfs      f31, 0x28(r1)
	  lwz       r4, 0x498(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xB0
	  lwz       r0, 0x80(r4)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x80
	  li        r0, 0
	  stw       r0, 0x498(r31)
	  b         .loc_0xB0

	.loc_0x80:
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x8(r30)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0xC(r30)
	  stw       r0, 0x14(r4)
	  lwz       r3, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r3, 0xA0(r4)
	  stw       r0, 0xA4(r4)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0xA8(r4)

	.loc_0xB0:
	  lwz       r4, 0x49C(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x104
	  lwz       r0, 0x80(r4)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0xD4
	  li        r0, 0
	  stw       r0, 0x49C(r31)
	  b         .loc_0x104

	.loc_0xD4:
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x8(r30)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0xC(r30)
	  stw       r0, 0x14(r4)
	  lwz       r3, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r3, 0xA0(r4)
	  stw       r0, 0xA4(r4)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0xA8(r4)

	.loc_0x104:
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A46EC
 * Size:	0000C4
 */
bool TAItankStrategy::interact(Teki&, TekiInteractionKey&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x28
	  b         .loc_0xA8

	.loc_0x28:
	  lwz       r3, 0x410(r30)
	  lwz       r0, -0x9B4(r13)
	  lwz       r4, 0x4(r5)
	  and.      r0, r3, r0
	  bne-      .loc_0x6C
	  lfs       f1, 0x33C(r30)
	  lfs       f0, 0x8(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x33C(r30)
	  lwz       r3, 0x410(r30)
	  lwz       r0, -0x9A4(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0x6C
	  lfs       f1, 0x340(r30)
	  lfs       f0, -0x4B64(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x340(r30)

	.loc_0x6C:
	  lwz       r3, 0x41C(r30)
	  lwz       r31, 0x4(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  beq-      .loc_0x8C
	  bl        -0xC0400
	  li        r0, 0
	  stw       r0, 0x41C(r30)

	.loc_0x8C:
	  stw       r31, 0x41C(r30)
	  lwz       r3, 0x41C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xA0
	  bl        -0xC042C

	.loc_0xA0:
	  li        r3, 0x1
	  b         .loc_0xAC

	.loc_0xA8:
	  li        r3, 0x1

	.loc_0xAC:
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
 * Address:	801A47B0
 * Size:	0006FC
 */
void TAItankAnimation::makeDefaultAnimations()
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
	  subi      r30, r3, 0x2390
	  cmplwi    r0, 0
	  beq-      .loc_0x6E4
	  lwz       r6, 0x3160(r13)
	  mr        r3, r31
	  lwz       r5, 0x2DEC(r13)
	  addi      r4, r30, 0x58
	  lwz       r6, 0x114(r6)
	  lwz       r0, 0x0(r6)
	  stw       r0, 0x1FC(r5)
	  bl        -0x1264
	  addi      r3, r31, 0
	  addi      r4, r30, 0x74
	  bl        -0x1270
	  addi      r3, r31, 0
	  addi      r4, r30, 0x94
	  bl        -0x127C
	  li        r3, 0x10
	  bl        -0x15D814
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
	  bl        -0x15D85C
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
	  addi      r4, r30, 0xB0
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x131C
	  li        r3, 0x10
	  bl        -0x15D8B4
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
	  bl        -0x15D8FC
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
	  addi      r4, r30, 0xCC
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x13BC
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x154598
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x154150
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x154168
	  li        r3, 0x10
	  bl        -0x15D990
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
	  bl        -0x15D9DC
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
	  addi      r4, r30, 0xEC
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x14A0
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x15467C
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x154234
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x15424C
	  li        r3, 0x10
	  bl        -0x15DA74
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
	  bl        -0x15DAC0
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
	  addi      r4, r30, 0x10C
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x1584
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x154760
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x154318
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x154330
	  li        r3, 0x10
	  bl        -0x15DB58
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
	  bl        -0x15DBA4
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
	  addi      r4, r30, 0x128
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x1668
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x154844
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1543FC
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x154414
	  li        r3, 0x10
	  bl        -0x15DC3C
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
	  bl        -0x15DC88
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
	  addi      r4, r30, 0x144
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x174C
	  lwz       r3, 0x8(r31)
	  li        r0, 0x3A
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1544D4
	  li        r3, 0x10
	  bl        -0x15DCFC
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
	  addi      r4, r30, 0x164
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x17C0
	  lwz       r3, 0x8(r31)
	  li        r0, 0x8
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x154548
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x154560
	  li        r3, 0x10
	  bl        -0x15DD88
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
	  bl        -0x15DDD4
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
	  addi      r4, r30, 0x180
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x1898
	  lwz       r3, 0x8(r31)
	  li        r0, 0x20
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x154620
	  li        r3, 0x10
	  bl        -0x15DE48
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
 * Address:	801A4EAC
 * Size:	000008
 */
bool TAIAnoReaction::act(Teki&) { return true; }

/*
 * --INFO--
 * Address:	801A4EB4
 * Size:	00000C
 */
void TAIAinitTank::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x4B44(r2)
	  stfs      f0, 0x270(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A4EC0
 * Size:	000008
 */
bool TAIAinitTank::act(Teki&) { return true; }

/*
 * --INFO--
 * Address:	801A4EC8
 * Size:	0000C8
 */
bool TAIAoutsideTerritory::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r8, r4, 0x94
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  addi      r6, r1, 0x48
	  addi      r5, r1, 0x44
	  lwz       r7, 0x2C4(r4)
	  lwz       r3, 0x2C8(r4)
	  addi      r4, r1, 0x40
	  lwz       r7, 0x84(r7)
	  addi      r9, r3, 0x10
	  lfs       f0, -0x4BA8(r2)
	  lwz       r7, 0x4(r7)
	  lwz       r3, 0x0(r7)
	  lfs       f31, 0x3C(r3)
	  addi      r3, r1, 0x58
	  stfs      f0, 0x60(r1)
	  stfs      f0, 0x5C(r1)
	  stfs      f0, 0x58(r1)
	  lfs       f1, 0x8(r8)
	  lfs       f0, 0x8(r9)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x48(r1)
	  lfs       f1, 0x4(r8)
	  lfs       f0, 0x4(r9)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x44(r1)
	  lfs       f1, 0x0(r8)
	  lfs       f0, 0x0(r9)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x40(r1)
	  bl        -0x1478BC
	  lfs       f1, 0x58(r1)
	  lfs       f0, 0x5C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x60(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19732C
	  fcmpo     cr0, f1, f31
	  mfcr      r0
	  rlwinm    r3,r0,2,31,31
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A4F90
 * Size:	000010
 */
f32 TAIAflickingTank::getFlickDirection(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x4B30(r2)
	  lfs       f0, 0xA0(r4)
	  fadds     f1, f1, f0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A4FA0
 * Size:	00004C
 */
void TAIAfireBreathTank::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x9B14
	  mr        r3, r31
	  bl        -0x2574
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x38
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x35
	  addi      r3, r3, 0x70
	  bl        -0x1215D4

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
 * Address:	801A4FEC
 * Size:	000018
 */
f32 TAIAfireBreathTank::getPreviousAnimSpeed(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xCC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A5004
 * Size:	000018
 */
f32 TAIAfireBreathTank::getAttackAnimSpeed(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xCC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A501C
 * Size:	000288
 */
bool FireEffect::invoke(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stfd      f31, 0xD8(r1)
	  stfd      f30, 0xD0(r1)
	  stw       r31, 0xCC(r1)
	  stw       r30, 0xC8(r1)
	  mr        r30, r4
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x264
	  lis       r4, 0x6B75
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x7469
	  bl        -0x11B944
	  lfs       f1, 0xA0(r30)
	  mr        r31, r3
	  bl        0x76AF4
	  lfs       f0, 0xA0(r30)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x76C78
	  stfs      f1, 0xB8(r1)
	  li        r4, 0x1
	  lfs       f0, 0x1200(r13)
	  stfs      f0, 0xBC(r1)
	  stfs      f31, 0xC0(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x4(r31)
	  lfs       f2, 0xC(r31)
	  bl        -0x13D190
	  lfs       f0, 0x8(r31)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x264
	  lfs       f0, -0x4BA8(r2)
	  li        r4, 0xC
	  stfs      f0, 0xB4(r1)
	  stfs      f0, 0xB0(r1)
	  stfs      f0, 0xAC(r1)
	  lfs       f3, 0x1204(r13)
	  lfs       f0, 0xB8(r1)
	  lfs       f30, 0xBC(r1)
	  fmuls     f0, f0, f3
	  lfs       f1, 0x4(r31)
	  lfs       f31, 0xC0(r1)
	  fmuls     f4, f30, f3
	  lfs       f2, 0x8(r31)
	  fadds     f0, f1, f0
	  lfs       f1, 0xC(r31)
	  fmuls     f3, f31, f3
	  fadds     f2, f2, f4
	  stfs      f0, 0xAC(r1)
	  fadds     f0, f1, f3
	  stfs      f2, 0xB0(r1)
	  stfs      f0, 0xB4(r1)
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x82C30
	  lfs       f4, 0x1208(r13)
	  addi      r6, r1, 0x4C
	  lfs       f0, 0xB8(r1)
	  addi      r5, r1, 0x48
	  fmuls     f3, f31, f4
	  fmuls     f2, f30, f4
	  addi      r4, r1, 0x44
	  fmuls     f0, f0, f4
	  addi      r3, r1, 0x74
	  fmr       f31, f1
	  stfs      f3, 0x4C(r1)
	  stfs      f2, 0x48(r1)
	  stfs      f0, 0x44(r1)
	  bl        -0x16E020
	  lfs       f2, 0x7C(r1)
	  addi      r6, r1, 0x58
	  lfs       f3, 0x120C(r13)
	  addi      r5, r1, 0x54
	  lfs       f1, 0x78(r1)
	  lfs       f0, 0x74(r1)
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  addi      r4, r1, 0x50
	  fmuls     f0, f0, f3
	  stfs      f2, 0x58(r1)
	  addi      r3, r1, 0x80
	  stfs      f1, 0x54(r1)
	  stfs      f0, 0x50(r1)
	  bl        -0x16E05C
	  lfs       f0, 0x80(r1)
	  fmr       f2, f31
	  lfs       f1, 0x84(r1)
	  addi      r7, r1, 0x64
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x88(r1)
	  stfs      f1, 0x68(r1)
	  mr        r5, r30
	  lfs       f1, -0x4B4C(r2)
	  addi      r3, r30, 0x528
	  stfs      f0, 0x6C(r1)
	  lfs       f3, -0x4B80(r2)
	  addi      r4, r30, 0x4CC
	  lfs       f4, -0x4B58(r2)
	  addi      r6, r1, 0xAC
	  addi      r8, r13, 0x3188
	  bl        0x1F7DC
	  lwz       r3, 0x3180(r13)
	  addi      r6, r30, 0x528
	  addi      r5, r31, 0x4
	  li        r4, 0x64
	  li        r7, 0
	  bl        -0x869C
	  cmplwi    r3, 0
	  stw       r3, 0x498(r30)
	  beq-      .loc_0x1F8
	  lwz       r4, 0x4(r31)
	  lwz       r0, 0x8(r31)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0xC(r31)
	  stw       r0, 0x14(r3)
	  lwz       r4, 0xB8(r1)
	  lwz       r0, 0xBC(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0xC0(r1)
	  stw       r0, 0xA8(r3)

	.loc_0x1F8:
	  addi      r0, r30, 0x4CC
	  stw       r0, 0x534(r30)
	  addi      r6, r30, 0x530
	  addi      r5, r31, 0x4
	  lwz       r3, 0x3180(r13)
	  li        r4, 0x63
	  li        r7, 0
	  bl        -0x86F8
	  cmplwi    r3, 0
	  stw       r3, 0x49C(r30)
	  beq-      .loc_0x264
	  lwz       r6, 0x4(r31)
	  mr        r4, r30
	  lwz       r0, 0x8(r31)
	  li        r5, 0x3C
	  stw       r6, 0xC(r3)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0xC(r31)
	  stw       r0, 0x14(r3)
	  lwz       r6, 0xB8(r1)
	  lwz       r0, 0xBC(r1)
	  stw       r6, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0xC0(r1)
	  stw       r0, 0xA8(r3)
	  mr        r3, r30
	  bl        -0x11ACC8

	.loc_0x264:
	  lwz       r0, 0xE4(r1)
	  li        r3, 0x1
	  lfd       f31, 0xD8(r1)
	  lfd       f30, 0xD0(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A52A4
 * Size:	000020
 */
bool TAIAstepBackTank::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x5ADC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A52C4
 * Size:	000018
 */
f32 TAIAstepBackTank::getVelocity(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xD0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A52DC
 * Size:	000020
 */
void TAIAoutsideOptionalRangeTank::setTargetPosition(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x8124
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A52FC
 * Size:	000018
 */
f32 TAIAoutsideOptionalRangeTank::getOptionalRange(Teki&)
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
 * Address:	801A5314
 * Size:	000020
 */
bool TAIAattackableAngleTarget::judge(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x88FC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A5334
 * Size:	000020
 */
bool TAIApatrolTank::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x56B8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A5354
 * Size:	000018
 */
f32 TAIApatrolTank::getTimeout(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xD4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A536C
 * Size:	000018
 */
f32 TAIAturnToTarget::getTurnVelocity(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0x14(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A5384
 * Size:	000010
 */
void __sinit_TAItank_cpp(void)
{
	/*
	.loc_0x0:
	  lis       r3, 0x802E
	  subi      r0, r3, 0x1BA4
	  stw       r0, 0x3188(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A5394
 * Size:	00006C
 */
bool TAIeffectAttackEventCallBackTank::hitCreature(TAIeffectAttackParam*, Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r6, 0x3064
	  lis       r3, 0x802B
	  stwu      r1, -0x30(r1)
	  lwz       r7, 0x2DEC(r13)
	  lfs       f1, 0x34(r4)
	  lfs       f0, 0x28C(r7)
	  lwz       r4, 0x38(r4)
	  fmuls     f0, f1, f0
	  stw       r0, 0x20(r1)
	  subi      r0, r3, 0x30D8
	  addi      r3, r5, 0
	  stw       r4, 0x24(r1)
	  addi      r4, r1, 0x20
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
 * Address:	801A5400
 * Size:	000154
 */
bool TAIeffectAttackEventCallBackTank::hitMap(TAIeffectAttackParam*)
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
	  lfs       f0, -0x4BA8(r2)
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
	  lfs       f1, -0x4B2C(r2)
	  lfs       f0, -0x4B64(r2)
	  stfs      f1, 0x44(r1)
	  lwz       r6, 0x2DEC(r13)
	  stw       r7, 0x50(r1)
	  lwz       r3, 0x2F00(r13)
	  stfs      f0, 0x48(r1)
	  lfs       f1, 0x28C(r6)
	  bl        -0x13C644
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
	  bl        -0x1978A8
	  lfs       f0, -0x4BA8(r2)
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
 * Address:	801A5554
 * Size:	000048
 */
void TAIeffectAttackEventCallBackTank::playEventSound(zen::particleGenerator*, TAIeffectAttackParam*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x38(r5)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  lha       r5, 0x1C8(r4)
	  lha       r4, 0x90(r4)
	  subi      r0, r5, 0x2
	  cmpw      r4, r0
	  bne-      .loc_0x38
	  addi      r4, r3, 0
	  li        r5, 0x3C
	  bl        -0x11AF9C

	.loc_0x38:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A559C
 * Size:	0001D8
 */
void TAIeffectAttackEventCallBackTank::ptclHitMap(zen::particleGenerator*, TAIeffectAttackParam*)
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
	  bne-      .loc_0x1B0
	  lwz       r28, 0x28(r24)
	  addi      r31, r1, 0x50
	  lfs       f29, -0x4BA8(r2)
	  addi      r30, r1, 0x5C
	  lwz       r27, 0x8(r28)
	  lfd       f30, -0x4B40(r2)
	  addi      r29, r1, 0x68
	  lfd       f31, -0x4B38(r2)
	  lfs       f28, -0x4B64(r2)
	  lfs       f27, -0x4B28(r2)
	  b         .loc_0x1A8

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
	  bl        -0x9D70
	  lfs       f0, 0x74(r1)
	  fcmpo     cr0, f0, f28
	  ble-      .loc_0x1A4
	  lfs       f1, 0x34(r27)
	  lfs       f0, 0x38(r27)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x3C(r27)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x17C
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

	.loc_0x17C:
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

	.loc_0x1A4:
	  mr        r27, r26

	.loc_0x1A8:
	  cmplw     r27, r28
	  bne+      .loc_0x64

	.loc_0x1B0:
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
