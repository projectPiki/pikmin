#include "Animator.h"
#include "Ayu.h"
#include "Parameters.h"
#include "String.h"

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
 * Address:	........
 * Size:	000084
 */
void AnimInfo::initAnimData(AnimData*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80050024
 * Size:	0000DC
 */
void AnimInfo::checkAnimData()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  addi      r0, r29, 0x38
	  lwz       r5, 0x44(r3)
	  b         .loc_0x48

	.loc_0x28:
	  lwz       r3, 0x68(r29)
	  lwz       r4, 0x0(r5)
	  lwz       r3, 0x30(r3)
	  subi      r3, r3, 0x1
	  cmpw      r4, r3
	  ble-      .loc_0x44
	  stw       r3, 0x0(r5)

	.loc_0x44:
	  lwz       r5, 0xC(r5)

	.loc_0x48:
	  cmplw     r5, r0
	  bne+      .loc_0x28
	  lwz       r30, 0x64(r29)
	  addi      r31, r29, 0x58
	  b         .loc_0x84

	.loc_0x5C:
	  mr        r3, r29
	  bl        0x364
	  lwz       r0, 0x0(r30)
	  cmpw      r0, r3
	  blt-      .loc_0x80
	  mr        r3, r29
	  bl        0x350
	  subi      r0, r3, 0x1
	  stw       r0, 0x0(r30)

	.loc_0x80:
	  lwz       r30, 0xC(r30)

	.loc_0x84:
	  cmplw     r30, r31
	  bne+      .loc_0x5C
	  lwz       r5, 0x54(r29)
	  addi      r0, r29, 0x48
	  b         .loc_0xB8

	.loc_0x98:
	  lwz       r3, 0x68(r29)
	  lwz       r4, 0x0(r5)
	  lwz       r3, 0x30(r3)
	  subi      r3, r3, 0x1
	  cmpw      r4, r3
	  ble-      .loc_0xB4
	  stw       r3, 0x0(r5)

	.loc_0xB4:
	  lwz       r5, 0xC(r5)

	.loc_0xB8:
	  cmplw     r5, r0
	  bne+      .loc_0x98
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
 * Address:	80050100
 * Size:	00027C
 */
AnimInfo::AnimInfo(AnimMgr*, AnimData*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r6, 0x738C
	  stwu      r1, -0x58(r1)
	  stmw      r27, 0x44(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  lis       r3, 0x8022
	  li        r30, 0
	  subi      r31, r13, 0x7628
	  addi      r29, r5, 0
	  addi      r4, r27, 0x14
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x802A
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x60F8
	  addi      r3, r1, 0x20
	  stw       r30, 0x10(r27)
	  addi      r5, r3, 0
	  addi      r3, r27, 0x18
	  stw       r30, 0xC(r27)
	  stw       r30, 0x8(r27)
	  stw       r31, 0x4(r27)
	  stw       r0, 0x0(r27)
	  stw       r30, 0x14(r27)
	  lwz       r0, -0x7624(r13)
	  stw       r0, 0x28(r1)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x20(r1)
	  bl        0xE904
	  lis       r3, 0x802A
	  addi      r0, r3, 0x60C4
	  stw       r0, 0x20(r27)
	  li        r0, 0x2
	  addi      r5, r1, 0x1C
	  stw       r0, 0x24(r27)
	  addi      r3, r27, 0x28
	  addi      r4, r27, 0x14
	  lwz       r0, -0x7620(r13)
	  stw       r0, 0x30(r1)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x1C(r1)
	  bl        0xE8D0
	  lis       r3, 0x802A
	  addi      r0, r3, 0x6098
	  stw       r0, 0x30(r27)
	  addi      r4, r27, 0x38
	  addi      r3, r27, 0x58
	  lfs       f0, -0x7B20(r2)
	  addi      r0, r27, 0x48
	  stfs      f0, 0x34(r27)
	  stw       r30, 0x38(r27)
	  sth       r30, 0x3C(r27)
	  stb       r30, 0x3E(r27)
	  stb       r30, 0x3F(r27)
	  stw       r30, 0x44(r27)
	  stw       r30, 0x40(r27)
	  stw       r30, 0x48(r27)
	  sth       r30, 0x4C(r27)
	  stb       r30, 0x4E(r27)
	  stb       r30, 0x4F(r27)
	  stw       r30, 0x54(r27)
	  stw       r30, 0x50(r27)
	  stw       r30, 0x58(r27)
	  sth       r30, 0x5C(r27)
	  stb       r30, 0x5E(r27)
	  stb       r30, 0x5F(r27)
	  stw       r30, 0x64(r27)
	  stw       r30, 0x60(r27)
	  stw       r30, 0x10(r27)
	  stw       r30, 0xC(r27)
	  stw       r30, 0x8(r27)
	  stw       r31, 0x4(r27)
	  stw       r28, 0x70(r27)
	  stw       r4, 0x44(r27)
	  stw       r4, 0x40(r27)
	  stw       r3, 0x64(r27)
	  stw       r3, 0x60(r27)
	  stw       r0, 0x54(r27)
	  stw       r0, 0x50(r27)
	  lwz       r3, 0x4(r29)
	  bl        0x1C91C0
	  subic.    r4, r3, 0x1
	  addi      r0, r4, 0x1
	  mtctr     r0
	  blt-      .loc_0x180

	.loc_0x160:
	  lwz       r3, 0x4(r29)
	  lbzx      r0, r3, r4
	  cmplwi    r0, 0x2F
	  beq-      .loc_0x180
	  cmplwi    r0, 0x5C
	  beq-      .loc_0x180
	  subi      r4, r4, 0x1
	  bdnz+     .loc_0x160

	.loc_0x180:
	  lwz       r0, 0x4(r29)
	  add       r3, r4, r0
	  addi      r3, r3, 0x1
	  bl        -0xFF4C
	  stw       r3, 0x4(r27)
	  li        r3, 0x10
	  stw       r29, 0x68(r27)
	  bl        -0x9298
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x1C8
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  sth       r0, 0x4(r6)
	  stb       r0, 0x6(r6)
	  stb       r0, 0x7(r6)
	  stw       r0, 0xC(r6)
	  stw       r0, 0x8(r6)

	.loc_0x1C8:
	  li        r28, 0
	  stw       r28, 0x0(r6)
	  li        r3, 0x10
	  lwz       r5, 0x40(r27)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x92EC
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x218
	  stw       r28, 0x0(r6)
	  sth       r28, 0x4(r6)
	  stb       r28, 0x6(r6)
	  stb       r28, 0x7(r6)
	  stw       r28, 0xC(r6)
	  stw       r28, 0x8(r6)

	.loc_0x218:
	  lwz       r4, 0x68(r27)
	  mr        r3, r27
	  lwz       r4, 0x30(r4)
	  subi      r0, r4, 0x1
	  stw       r0, 0x0(r6)
	  lwz       r5, 0x40(r27)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x324
	  li        r0, 0x5
	  stw       r0, 0x24(r27)
	  mr        r3, r27
	  bl        0x4BC
	  mr        r3, r27
	  bl        .loc_0x27C
	  mr        r3, r27
	  lmw       r27, 0x44(r1)
	  lwz       r0, 0x5C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr

	.loc_0x27C:
	*/
}

/*
 * --INFO--
 * Address:	8005037C
 * Size:	000048
 */
void AnimInfo::setIndex()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r4, 0x70(r31)
	  lwz       r5, 0x68(r31)
	  addi      r4, r4, 0x34
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x4(r4)
	  lwz       r5, 0x4(r5)
	  bl        -0x10F5C
	  stw       r3, 0x6C(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800503C4
 * Size:	000024
 */
void AnimInfo::setAnimFlags(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  stw       r4, 0x24(r3)
	  bl        0x440
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800503E8
 * Size:	000024
 */
void AnimInfo::countAKeys()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x44(r3)
	  addi      r0, r3, 0x38
	  li        r3, 0
	  b         .loc_0x18

	.loc_0x10:
	  lwz       r4, 0xC(r4)
	  addi      r3, r3, 0x1

	.loc_0x18:
	  cmplw     r4, r0
	  bne+      .loc_0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005040C
 * Size:	000024
 */
void AnimInfo::countIKeys()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x64(r3)
	  addi      r0, r3, 0x58
	  li        r3, 0
	  b         .loc_0x18

	.loc_0x10:
	  lwz       r4, 0xC(r4)
	  addi      r3, r3, 0x1

	.loc_0x18:
	  cmplw     r4, r0
	  bne+      .loc_0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80050430
 * Size:	000024
 */
void AnimInfo::countEKeys()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x54(r3)
	  addi      r0, r3, 0x48
	  li        r3, 0
	  b         .loc_0x18

	.loc_0x10:
	  lwz       r4, 0xC(r4)
	  addi      r3, r3, 0x1

	.loc_0x18:
	  cmplw     r4, r0
	  bne+      .loc_0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80050454
 * Size:	000038
 */
void AnimInfo::getInfoKey(int)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x64(r3)
	  addi      r0, r3, 0x58
	  li        r3, 0
	  b         .loc_0x28

	.loc_0x10:
	  cmpw      r3, r4
	  bne-      .loc_0x20
	  mr        r3, r5
	  blr

	.loc_0x20:
	  lwz       r5, 0xC(r5)
	  addi      r3, r3, 0x1

	.loc_0x28:
	  cmplw     r5, r0
	  bne+      .loc_0x10
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005048C
 * Size:	000038
 */
void AnimInfo::getEventKey(int)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x54(r3)
	  addi      r0, r3, 0x48
	  li        r3, 0
	  b         .loc_0x28

	.loc_0x10:
	  cmpw      r3, r4
	  bne-      .loc_0x20
	  mr        r3, r5
	  blr

	.loc_0x20:
	  lwz       r5, 0xC(r5)
	  addi      r3, r3, 0x1

	.loc_0x28:
	  cmplw     r5, r0
	  bne+      .loc_0x10
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800504C4
 * Size:	000038
 */
void AnimInfo::getKeyValue(int)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x44(r3)
	  addi      r0, r3, 0x38
	  li        r3, 0
	  b         .loc_0x28

	.loc_0x10:
	  cmpw      r3, r4
	  bne-      .loc_0x20
	  lwz       r3, 0x0(r5)
	  blr

	.loc_0x20:
	  lwz       r5, 0xC(r5)
	  addi      r3, r3, 0x1

	.loc_0x28:
	  cmplw     r5, r0
	  bne+      .loc_0x10
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800504FC
 * Size:	0002F8
 */
void AnimInfo::doread(RandomAccessStream&, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x58(r1)
	  stmw      r26, 0x40(r1)
	  addi      r31, r4, 0
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  addi      r29, r5, 0
	  addi      r4, r1, 0x38
	  stw       r0, 0x3C(r1)
	  stw       r0, 0x38(r1)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3C(r1)
	  bl        -0x10200
	  stw       r3, 0x4(r30)
	  addi      r4, r31, 0
	  addi      r3, r30, 0x14
	  bl        0xE648
	  addi      r3, r30, 0x38
	  stw       r3, 0x44(r30)
	  addi      r4, r30, 0x58
	  addi      r0, r30, 0x48
	  stw       r3, 0x40(r30)
	  mr        r3, r31
	  stw       r4, 0x64(r30)
	  stw       r4, 0x60(r30)
	  stw       r0, 0x54(r30)
	  stw       r0, 0x50(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr.       r27, r3
	  beq-      .loc_0x110
	  addi      r28, r27, 0
	  rlwinm    r3,r27,4,0,27
	  addi      r3, r3, 0x8
	  bl        -0x959C
	  lis       r4, 0x8005
	  addi      r4, r4, 0x7F4
	  addi      r7, r28, 0
	  li        r5, 0
	  li        r6, 0x10
	  bl        0x1C4670
	  addi      r28, r3, 0
	  li        r26, 0
	  b         .loc_0x108

	.loc_0xCC:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r28)
	  addi      r26, r26, 0x1
	  lwz       r4, 0x40(r30)
	  lwz       r0, 0xC(r4)
	  stw       r0, 0xC(r28)
	  stw       r4, 0x8(r28)
	  lwz       r3, 0xC(r4)
	  stw       r28, 0x8(r3)
	  stw       r28, 0xC(r4)
	  addi      r28, r28, 0x10

	.loc_0x108:
	  cmpw      r26, r27
	  blt+      .loc_0xCC

	.loc_0x110:
	  cmpwi     r29, 0x1
	  blt-      .loc_0x1F4
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr.       r26, r3
	  beq-      .loc_0x1F4
	  addi      r28, r26, 0
	  rlwinm    r3,r26,4,0,27
	  addi      r3, r3, 0x8
	  bl        -0x9638
	  lis       r4, 0x8005
	  addi      r4, r4, 0x7F4
	  addi      r7, r28, 0
	  li        r5, 0
	  li        r6, 0x10
	  bl        0x1C45D4
	  addi      r28, r3, 0
	  li        r27, 0
	  b         .loc_0x1EC

	.loc_0x168:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r28)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x4(r28)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x7(r28)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x6(r28)
	  addi      r27, r27, 0x1
	  lwz       r4, 0x60(r30)
	  lwz       r0, 0xC(r4)
	  stw       r0, 0xC(r28)
	  stw       r4, 0x8(r28)
	  lwz       r3, 0xC(r4)
	  stw       r28, 0x8(r3)
	  stw       r28, 0xC(r4)
	  addi      r28, r28, 0x10

	.loc_0x1EC:
	  cmpw      r27, r26
	  blt+      .loc_0x168

	.loc_0x1F4:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr.       r26, r3
	  beq-      .loc_0x2E4
	  addi      r28, r26, 0
	  rlwinm    r3,r26,4,0,27
	  addi      r3, r3, 0x8
	  bl        -0x9714
	  lis       r4, 0x8005
	  addi      r4, r4, 0x7F4
	  addi      r7, r28, 0
	  li        r5, 0
	  li        r6, 0x10
	  bl        0x1C44F8
	  addi      r28, r3, 0
	  li        r27, 0
	  b         .loc_0x2DC

	.loc_0x244:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r28)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x4(r28)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x7(r28)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x6(r28)
	  lha       r0, 0x4(r28)
	  cmpwi     r0, 0x3
	  blt-      .loc_0x2B8
	  li        r0, 0
	  sth       r0, 0x4(r28)

	.loc_0x2B8:
	  lwz       r4, 0x50(r30)
	  addi      r27, r27, 0x1
	  lwz       r0, 0xC(r4)
	  stw       r0, 0xC(r28)
	  stw       r4, 0x8(r28)
	  lwz       r3, 0xC(r4)
	  stw       r28, 0x8(r3)
	  stw       r28, 0xC(r4)
	  addi      r28, r28, 0x10

	.loc_0x2DC:
	  cmpw      r27, r26
	  blt+      .loc_0x244

	.loc_0x2E4:
	  lmw       r26, 0x40(r1)
	  lwz       r0, 0x5C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800507F4
 * Size:	000020
 */
AnimKey::AnimKey()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  sth       r0, 0x4(r3)
	  stb       r0, 0x6(r3)
	  stb       r0, 0x7(r3)
	  stw       r0, 0xC(r3)
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80050814
 * Size:	000010
 */
void AnimInfo::updateAnimFlags()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x24(r3)
	  lwz       r3, 0x68(r3)
	  stw       r0, 0x24(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80050824
 * Size:	000080
 */
void AnimInfo::addKeyFrame()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  li        r3, 0x10
	  bl        -0x9838
	  cmplwi    r3, 0
	  beq-      .loc_0x40
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  sth       r0, 0x4(r3)
	  stb       r0, 0x6(r3)
	  stb       r0, 0x7(r3)
	  stw       r0, 0xC(r3)
	  stw       r0, 0x8(r3)

	.loc_0x40:
	  lwz       r4, 0x68(r31)
	  lwz       r4, 0x30(r4)
	  subi      r0, r4, 0x1
	  stw       r0, 0x0(r3)
	  lwz       r5, 0x40(r31)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r3)
	  stw       r5, 0x8(r3)
	  lwz       r4, 0xC(r5)
	  stw       r3, 0x8(r4)
	  stw       r3, 0xC(r5)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800508A4
 * Size:	000234
 */
AnimMgr::AnimMgr(Shape*, char*, int, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r8, 0x8022
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stmw      r22, 0x98(r1)
	  addi      r22, r3, 0
	  addi      r27, r8, 0x738C
	  lis       r3, 0x8022
	  addi      r28, r3, 0x737C
	  lis       r3, 0x802A
	  addi      r0, r3, 0x6034
	  li        r29, 0
	  lis       r8, 0x802A
	  addi      r23, r4, 0
	  addi      r4, r8, 0x5FCC
	  addi      r3, r1, 0x54
	  addi      r24, r5, 0
	  stw       r27, 0x0(r22)
	  addi      r5, r3, 0
	  addi      r25, r6, 0
	  stw       r28, 0x0(r22)
	  addi      r26, r7, 0
	  addi      r3, r22, 0x18
	  stw       r29, 0x10(r22)
	  stw       r29, 0xC(r22)
	  stw       r29, 0x8(r22)
	  stw       r4, 0x4(r22)
	  addi      r4, r22, 0x14
	  stw       r0, 0x0(r22)
	  stw       r29, 0x14(r22)
	  lwz       r0, -0x761C(r13)
	  stw       r0, 0x5C(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r0, 0x54(r1)
	  bl        0xE154
	  lis       r3, 0x802A
	  addi      r30, r3, 0x60C4
	  stw       r30, 0x20(r22)
	  li        r31, 0x2
	  lis       r3, 0x802A
	  stw       r31, 0x24(r22)
	  addi      r0, r3, 0x5FD8
	  addi      r5, r1, 0x50
	  lwz       r6, -0x7618(r13)
	  addi      r3, r22, 0x28
	  stw       r0, 0x6C(r1)
	  addi      r4, r22, 0x14
	  stw       r6, 0x94(r1)
	  lwz       r0, 0x94(r1)
	  stw       r29, 0x68(r1)
	  stw       r0, 0x50(r1)
	  bl        0xE110
	  lis       r3, 0x802A
	  addi      r0, r3, 0x606C
	  stw       r0, 0x30(r22)
	  li        r3, 0x41
	  bl        0x160
	  stw       r3, 0x38(r22)
	  li        r0, 0x40
	  lis       r3, 0x802A
	  stw       r0, 0x34(r22)
	  subi      r5, r13, 0x7628
	  addi      r0, r3, 0x60F8
	  lwz       r7, 0x68(r1)
	  addi      r3, r1, 0x44
	  lwz       r6, 0x6C(r1)
	  subi      r4, r13, 0x7624
	  stw       r7, 0x34(r22)
	  stw       r6, 0x38(r22)
	  stw       r27, 0x40(r22)
	  stw       r28, 0x40(r22)
	  stw       r29, 0x50(r22)
	  stw       r29, 0x4C(r22)
	  stw       r29, 0x48(r22)
	  stw       r5, 0x44(r22)
	  stw       r0, 0x40(r22)
	  stw       r29, 0x54(r22)
	  bl        .loc_0x234
	  lwz       r0, 0x44(r1)
	  addi      r27, r22, 0x54
	  addi      r5, r1, 0x3C
	  stw       r0, 0x3C(r1)
	  addi      r4, r27, 0
	  addi      r3, r22, 0x58
	  bl        0xE08C
	  stw       r30, 0x60(r22)
	  addi      r3, r1, 0x4C
	  subi      r4, r13, 0x7620
	  stw       r31, 0x64(r22)
	  bl        .loc_0x234
	  lwz       r0, 0x4C(r1)
	  addi      r5, r1, 0x38
	  addi      r4, r27, 0
	  stw       r0, 0x38(r1)
	  addi      r3, r22, 0x68
	  bl        0xE060
	  lis       r3, 0x802A
	  addi      r0, r3, 0x6098
	  stw       r0, 0x70(r22)
	  subi      r7, r13, 0x7630
	  rlwinm    r6,r25,0,17,31
	  lfs       f0, -0x7B20(r2)
	  subi      r0, r13, 0x7614
	  addi      r3, r22, 0
	  stfs      f0, 0x74(r22)
	  addi      r4, r24, 0
	  addi      r5, r26, 0
	  stw       r29, 0x78(r22)
	  sth       r29, 0x7C(r22)
	  stb       r29, 0x7E(r22)
	  stb       r29, 0x7F(r22)
	  stw       r29, 0x84(r22)
	  stw       r29, 0x80(r22)
	  stw       r29, 0x88(r22)
	  sth       r29, 0x8C(r22)
	  stb       r29, 0x8E(r22)
	  stb       r29, 0x8F(r22)
	  stw       r29, 0x94(r22)
	  stw       r29, 0x90(r22)
	  stw       r29, 0x98(r22)
	  sth       r29, 0x9C(r22)
	  stb       r29, 0x9E(r22)
	  stb       r29, 0x9F(r22)
	  stw       r29, 0xA4(r22)
	  stw       r29, 0xA0(r22)
	  stw       r29, 0xA8(r22)
	  stw       r29, 0xB0(r22)
	  stw       r7, 0x4(r22)
	  stw       r23, 0x3C(r22)
	  stw       r6, 0xB4(r22)
	  stw       r29, 0x50(r22)
	  stw       r29, 0x4C(r22)
	  stw       r29, 0x48(r22)
	  stw       r0, 0x44(r22)
	  bl        0x48
	  mr        r3, r22
	  lmw       r22, 0x98(r1)
	  lwz       r0, 0xC4(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr

	.loc_0x234:
	*/
}

/*
 * --INFO--
 * Address:	80050AE4
 * Size:	000020
 */
void* operator new[](u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x9AEC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80050B04
 * Size:	0001E8
 */
void AnimMgr::loadAnims(char*, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x350(r1)
	  stmw      r27, 0x33C(r1)
	  addi      r30, r3, 0
	  addi      r29, r5, 0
	  beq-      .loc_0x1D4
	  addi      r3, r30, 0
	  addi      r5, r4, 0
	  subi      r4, r13, 0x7628
	  li        r6, 0x1
	  bl        -0x10494
	  lwz       r0, 0xB4(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x1D4
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        -0x11B2C
	  lwz       r3, 0x50(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x60
	  li        r0, 0
	  b         .loc_0x64

	.loc_0x60:
	  li        r0, 0x1

	.loc_0x64:
	  mr        r27, r0
	  addi      r28, r3, 0
	  addi      r31, r30, 0x34
	  b         .loc_0xA8

	.loc_0x74:
	  lwz       r5, 0x4(r31)
	  addi      r3, r1, 0x230
	  lwz       r6, 0x4(r28)
	  crclr     6, 0x6
	  subi      r4, r13, 0x760C
	  bl        0x1C5A0C
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x230
	  bl        -0x117EC
	  cmplwi    r3, 0
	  bne-      .loc_0xA4
	  addi      r27, r27, 0x1

	.loc_0xA4:
	  lwz       r28, 0xC(r28)

	.loc_0xA8:
	  cmplwi    r28, 0
	  bne+      .loc_0x74
	  cmpwi     r27, 0
	  beq-      .loc_0x11C
	  lwz       r0, 0x3C(r30)
	  cmplwi    r29, 0
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x1FC(r3)
	  beq-      .loc_0xD4
	  mr        r4, r29
	  b         .loc_0xDC

	.loc_0xD4:
	  lwz       r3, 0x3C(r30)
	  lwz       r4, 0x4(r3)

	.loc_0xDC:
	  crclr     6, 0x6
	  addi      r3, r1, 0x130
	  bl        0x1C59B0
	  cmplwi    r29, 0
	  bne-      .loc_0x10C
	  addi      r3, r1, 0x130
	  bl        0x1C8814
	  addi      r0, r1, 0x12D
	  crclr     6, 0x6
	  add       r3, r0, r3
	  subi      r4, r13, 0x7604
	  bl        0x1C598C

	.loc_0x10C:
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x130
	  li        r5, 0
	  bl        -0x10E48

	.loc_0x11C:
	  lis       r3, 0x802A
	  lwz       r27, 0x50(r30)
	  addi      r29, r3, 0x5FE4
	  b         .loc_0x1CC

	.loc_0x12C:
	  lwz       r5, 0x4(r31)
	  addi      r3, r1, 0x30
	  lwz       r6, 0x4(r27)
	  crclr     6, 0x6
	  subi      r4, r13, 0x760C
	  bl        0x1C5954
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r1, 0x30
	  lwz       r4, 0x3C(r30)
	  li        r6, 0x1
	  bl        -0x11768
	  stw       r3, 0x68(r27)
	  lwz       r5, 0x68(r27)
	  cmplwi    r5, 0
	  beq-      .loc_0x19C
	  lwz       r4, 0x70(r27)
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r4, 0x34
	  lwz       r5, 0x4(r5)
	  lwz       r4, 0x4(r4)
	  bl        -0x11834
	  stw       r3, 0x6C(r27)
	  mr        r3, r27
	  lwz       r0, 0x24(r27)
	  lwz       r4, 0x68(r27)
	  stw       r0, 0x24(r4)
	  bl        -0xC74
	  b         .loc_0x1C8

	.loc_0x19C:
	  li        r3, 0x44
	  bl        -0x9CA0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x1BC
	  lwz       r4, 0x3C(r30)
	  lwz       r5, 0x58(r4)
	  bl        -0x23620

	.loc_0x1BC:
	  stw       r28, 0x68(r27)
	  lwz       r3, 0x68(r27)
	  stw       r29, 0x4(r3)

	.loc_0x1C8:
	  lwz       r27, 0xC(r27)

	.loc_0x1CC:
	  cmplwi    r27, 0
	  bne+      .loc_0x12C

	.loc_0x1D4:
	  lmw       r27, 0x33C(r1)
	  lwz       r0, 0x354(r1)
	  addi      r1, r1, 0x350
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80050CEC
 * Size:	00008C
 */
AnimInfo* AnimMgr::addAnimation(char*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x18(r1)
	  addi      r28, r3, 0
	  li        r3, 0x74
	  bl        -0x9D14
	  mr.       r31, r3
	  beq-      .loc_0x5C
	  lwz       r3, 0x2DEC(r13)
	  mr        r5, r29
	  lwz       r4, 0x3C(r28)
	  mr        r6, r30
	  bl        -0x11844
	  addi      r5, r3, 0
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  bl        -0xC44

	.loc_0x5C:
	  addi      r4, r31, 0
	  addi      r3, r28, 0x40
	  bl        -0x10778
	  mr        r3, r31
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
 * Address:	........
 * Size:	0000A4
 */
void AnimMgr::findAnim(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80050D78
 * Size:	000020
 */
void AnimMgr::countAnims()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x50(r3)
	  li        r3, 0
	  b         .loc_0x14

	.loc_0xC:
	  lwz       r4, 0xC(r4)
	  addi      r3, r3, 0x1

	.loc_0x14:
	  cmplwi    r4, 0
	  bne+      .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80050D98
 * Size:	0001D8
 */
void AnimMgr::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stmw      r18, 0x30(r1)
	  addi      r20, r4, 0
	  addi      r19, r3, 0
	  addi      r3, r20, 0
	  lwz       r12, 0x4(r20)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r20, 0
	  lwz       r12, 0x4(r20)
	  mr        r22, r0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r26, r3, 0
	  addi      r4, r20, 0
	  addi      r3, r19, 0x14
	  bl        0xDDA8
	  li        r0, 0
	  stw       r0, 0x50(r19)
	  lis       r7, 0x8022
	  lis       r6, 0x8022
	  stw       r0, 0x4C(r19)
	  lis       r5, 0x802A
	  lis       r4, 0x802A
	  stw       r0, 0x48(r19)
	  subi      r0, r13, 0x7628
	  lis       r3, 0x802A
	  stw       r0, 0x44(r19)
	  addi      r27, r7, 0x738C
	  addi      r28, r6, 0x737C
	  lfs       f31, -0x7B20(r2)
	  addi      r30, r5, 0x60F8
	  addi      r24, r1, 0x1C
	  addi      r31, r4, 0x60C4
	  addi      r23, r1, 0x18
	  addi      r18, r3, 0x6098
	  li        r21, 0
	  b         .loc_0x1B8

	.loc_0xB0:
	  li        r3, 0x74
	  bl        -0x9E48
	  mr.       r25, r3
	  beq-      .loc_0x194
	  stw       r27, 0x0(r25)
	  li        r29, 0
	  subi      r0, r13, 0x7628
	  stw       r28, 0x0(r25)
	  addi      r3, r1, 0x24
	  subi      r4, r13, 0x7624
	  stw       r29, 0x10(r25)
	  stw       r29, 0xC(r25)
	  stw       r29, 0x8(r25)
	  stw       r0, 0x4(r25)
	  stw       r30, 0x0(r25)
	  stw       r29, 0x14(r25)
	  bl        -0x3B0
	  lwz       r0, 0x24(r1)
	  addi      r5, r24, 0
	  addi      r3, r25, 0x18
	  stw       r0, 0x1C(r1)
	  addi      r4, r25, 0x14
	  bl        0xDBE0
	  stw       r31, 0x20(r25)
	  li        r0, 0x2
	  addi      r3, r1, 0x2C
	  stw       r0, 0x24(r25)
	  subi      r4, r13, 0x7620
	  bl        -0x3E0
	  lwz       r0, 0x2C(r1)
	  addi      r5, r23, 0
	  addi      r3, r25, 0x28
	  stw       r0, 0x18(r1)
	  addi      r4, r25, 0x14
	  bl        0xDBB0
	  stw       r18, 0x30(r25)
	  stfs      f31, 0x34(r25)
	  stw       r29, 0x38(r25)
	  sth       r29, 0x3C(r25)
	  stb       r29, 0x3E(r25)
	  stb       r29, 0x3F(r25)
	  stw       r29, 0x44(r25)
	  stw       r29, 0x40(r25)
	  stw       r29, 0x48(r25)
	  sth       r29, 0x4C(r25)
	  stb       r29, 0x4E(r25)
	  stb       r29, 0x4F(r25)
	  stw       r29, 0x54(r25)
	  stw       r29, 0x50(r25)
	  stw       r29, 0x58(r25)
	  sth       r29, 0x5C(r25)
	  stb       r29, 0x5E(r25)
	  stb       r29, 0x5F(r25)
	  stw       r29, 0x64(r25)
	  stw       r29, 0x60(r25)
	  stw       r29, 0x68(r25)
	  stw       r29, 0x70(r25)

	.loc_0x194:
	  stw       r19, 0x70(r25)
	  addi      r3, r25, 0
	  addi      r4, r20, 0
	  addi      r5, r22, 0
	  bl        -0xA40
	  addi      r3, r19, 0x40
	  addi      r4, r25, 0
	  bl        -0x10970
	  addi      r21, r21, 0x1

	.loc_0x1B8:
	  cmpw      r21, r26
	  blt+      .loc_0xB0
	  lmw       r18, 0x30(r1)
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80050F70
 * Size:	00021C
 */
void Animator::startAnim(int, int, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x160(r1)
	  stmw      r25, 0x144(r1)
	  mr        r27, r3
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  addi      r31, r7, 0
	  lwz       r25, 0x0(r3)
	  li        r3, 0
	  lwz       r26, 0x50(r25)
	  b         .loc_0x8C

	.loc_0x34:
	  cmpw      r3, r29
	  bne-      .loc_0x84
	  lwz       r0, 0x68(r26)
	  cmplwi    r0, 0
	  bne-      .loc_0x98
	  lwz       r6, 0x4(r26)
	  addi      r3, r1, 0x34
	  lwz       r5, 0x38(r25)
	  crclr     6, 0x6
	  subi      r4, r13, 0x760C
	  bl        0x1C55CC
	  lwz       r3, 0x3C(r25)
	  addi      r4, r1, 0x34
	  li        r5, 0x1
	  bl        -0x1C1E8
	  stw       r3, 0x68(r26)
	  lwz       r0, 0x24(r26)
	  lwz       r3, 0x68(r26)
	  stw       r0, 0x24(r3)
	  b         .loc_0x98

	.loc_0x84:
	  lwz       r26, 0xC(r26)
	  addi      r3, r3, 0x1

	.loc_0x8C:
	  cmplwi    r26, 0
	  bne+      .loc_0x34
	  li        r26, 0

	.loc_0x98:
	  cmpwi     r30, -0x1
	  stw       r26, 0x28(r27)
	  bne-      .loc_0xB8
	  lwz       r0, 0x1C(r27)
	  cmpw      r0, r29
	  bne-      .loc_0xB8
	  lwz       r30, 0x20(r27)
	  b         .loc_0x110

	.loc_0xB8:
	  lwz       r5, 0x28(r27)
	  li        r4, 0
	  lwz       r3, 0x44(r5)
	  addi      r0, r5, 0x38
	  b         .loc_0xE4

	.loc_0xCC:
	  cmpw      r4, r30
	  bne-      .loc_0xDC
	  lwz       r0, 0x0(r3)
	  b         .loc_0xF0

	.loc_0xDC:
	  lwz       r3, 0xC(r3)
	  addi      r4, r4, 0x1

	.loc_0xE4:
	  cmplw     r3, r0
	  bne+      .loc_0xCC
	  li        r0, 0

	.loc_0xF0:
	  xoris     r0, r0, 0x8000
	  lfd       f1, -0x7B18(r2)
	  stw       r0, 0x13C(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x138(r1)
	  lfd       f0, 0x138(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x2C(r27)

	.loc_0x110:
	  lfs       f2, 0x2C(r27)
	  lfs       f0, -0x7B1C(r2)
	  fcmpo     cr0, f2, f0
	  blt-      .loc_0x154
	  lwz       r3, 0x28(r27)
	  lis       r0, 0x4330
	  lfd       f1, -0x7B18(r2)
	  lwz       r3, 0x68(r3)
	  lwz       r3, 0x30(r3)
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x13C(r1)
	  stw       r0, 0x138(r1)
	  lfd       f0, 0x138(r1)
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x15C

	.loc_0x154:
	  lfs       f0, -0x7B1C(r2)
	  stfs      f0, 0x2C(r27)

	.loc_0x15C:
	  lwz       r5, 0x28(r27)
	  li        r4, 0
	  lwz       r6, 0x44(r5)
	  addi      r0, r5, 0x38
	  addi      r3, r6, 0
	  b         .loc_0x17C

	.loc_0x174:
	  lwz       r3, 0xC(r3)
	  addi      r4, r4, 0x1

	.loc_0x17C:
	  cmplw     r3, r0
	  bne+      .loc_0x174
	  cmpw      r31, r4
	  blt-      .loc_0x1B0
	  addi      r3, r6, 0
	  addi      r0, r5, 0x38
	  li        r4, 0
	  b         .loc_0x1A4

	.loc_0x19C:
	  lwz       r3, 0xC(r3)
	  addi      r4, r4, 0x1

	.loc_0x1A4:
	  cmplw     r3, r0
	  bne+      .loc_0x19C
	  subi      r31, r4, 0x1

	.loc_0x1B0:
	  addi      r3, r6, 0
	  addi      r0, r5, 0x38
	  li        r4, 0
	  b         .loc_0x1C8

	.loc_0x1C0:
	  lwz       r3, 0xC(r3)
	  addi      r4, r4, 0x1

	.loc_0x1C8:
	  cmplw     r3, r0
	  bne+      .loc_0x1C0
	  cmpw      r30, r4
	  blt-      .loc_0x1F8
	  addi      r0, r5, 0x38
	  li        r3, 0
	  b         .loc_0x1EC

	.loc_0x1E4:
	  lwz       r6, 0xC(r6)
	  addi      r3, r3, 0x1

	.loc_0x1EC:
	  cmplw     r6, r0
	  bne+      .loc_0x1E4
	  subi      r30, r3, 0x1

	.loc_0x1F8:
	  stw       r29, 0x1C(r27)
	  stw       r28, 0x18(r27)
	  stw       r30, 0x20(r27)
	  stw       r31, 0x24(r27)
	  lwz       r0, 0x164(r1)
	  lmw       r25, 0x144(r1)
	  addi      r1, r1, 0x160
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005118C
 * Size:	000004
 */
void Animator::finishLoop() { }

/*
 * --INFO--
 * Address:	80051190
 * Size:	000030
 */
void Animator::finishOneShot()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x8(r3)
	  lwz       r5, 0xC(r3)
	  lwz       r6, 0x10(r3)
	  lwz       r7, 0x14(r3)
	  bl        -0x23C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800511C0
 * Size:	00005C
 */
void Animator::updateContext()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lis       r0, 0x4330
	  lwz       r5, 0x28(r3)
	  lwz       r4, 0x4(r3)
	  lwz       r5, 0x68(r5)
	  stw       r5, 0x0(r4)
	  lfs       f0, 0x2C(r3)
	  lwz       r4, 0x4(r3)
	  stfs      f0, 0x4(r4)
	  lwz       r4, 0x28(r3)
	  lfs       f2, 0x2C(r3)
	  lwz       r4, 0x68(r4)
	  lfd       f1, -0x7B18(r2)
	  lwz       r3, 0x30(r4)
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x14(r1)
	  stw       r0, 0x10(r1)
	  lfd       f0, 0x10(r1)
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005121C
 * Size:	00023C
 */
void Animator::animate(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  lwz       r6, 0x28(r3)
	  lwz       r0, 0x24(r6)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x28
	  b         .loc_0x2C

	.loc_0x28:
	  lfs       f1, 0x34(r6)

	.loc_0x2C:
	  lwz       r7, 0x44(r6)
	  addi      r0, r6, 0x38
	  lwz       r5, 0x20(r31)
	  li        r4, 0
	  addi      r3, r7, 0
	  b         .loc_0x5C

	.loc_0x44:
	  cmpw      r4, r5
	  bne-      .loc_0x54
	  lwz       r0, 0x0(r3)
	  b         .loc_0x68

	.loc_0x54:
	  lwz       r3, 0xC(r3)
	  addi      r4, r4, 0x1

	.loc_0x5C:
	  cmplw     r3, r0
	  bne+      .loc_0x44
	  li        r0, 0

	.loc_0x68:
	  xoris     r0, r0, 0x8000
	  lfd       f2, -0x7B18(r2)
	  stw       r0, 0x4C(r1)
	  lis       r0, 0x4330
	  lwz       r4, 0x24(r31)
	  li        r3, 0
	  stw       r0, 0x48(r1)
	  addi      r0, r6, 0x38
	  lfd       f0, 0x48(r1)
	  fsubs     f3, f0, f2
	  b         .loc_0xAC

	.loc_0x94:
	  cmpw      r3, r4
	  bne-      .loc_0xA4
	  lwz       r0, 0x0(r7)
	  b         .loc_0xB8

	.loc_0xA4:
	  lwz       r7, 0xC(r7)
	  addi      r3, r3, 0x1

	.loc_0xAC:
	  cmplw     r7, r0
	  bne+      .loc_0x94
	  li        r0, 0

	.loc_0xB8:
	  xoris     r3, r0, 0x8000
	  lwz       r0, 0x18(r31)
	  stw       r3, 0x4C(r1)
	  lis       r3, 0x4330
	  lfd       f2, -0x7B18(r2)
	  cmpwi     r0, 0
	  stw       r3, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f4, f0, f2
	  beq-      .loc_0x1EC
	  fcmpo     cr0, f4, f3
	  ble-      .loc_0x174
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x2C(r31)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x2C(r31)
	  lfs       f1, 0x2C(r31)
	  fcmpo     cr0, f1, f4
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x164
	  lwz       r0, 0x18(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x140
	  fsubs     f0, f4, f3
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2C(r31)
	  lfs       f0, 0x2C(r31)
	  fcmpo     cr0, f0, f4
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1EC
	  stfs      f3, 0x2C(r31)
	  b         .loc_0x1EC

	.loc_0x140:
	  lfs       f0, -0x7B10(r2)
	  mr        r3, r31
	  fsubs     f0, f4, f0
	  stfs      f0, 0x2C(r31)
	  lwz       r12, 0x30(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1EC

	.loc_0x164:
	  fcmpo     cr0, f1, f3
	  bge-      .loc_0x1EC
	  stfs      f3, 0x2C(r31)
	  b         .loc_0x1EC

	.loc_0x174:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x2C(r31)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x2C(r31)
	  lfs       f1, 0x2C(r31)
	  fcmpo     cr0, f1, f4
	  bge-      .loc_0x1E0
	  lwz       r0, 0x18(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1C4
	  fsubs     f0, f3, f4
	  fadds     f0, f1, f0
	  stfs      f0, 0x2C(r31)
	  lfs       f0, 0x2C(r31)
	  fcmpo     cr0, f0, f4
	  bge-      .loc_0x1EC
	  stfs      f4, 0x2C(r31)
	  b         .loc_0x1EC

	.loc_0x1C4:
	  stfs      f4, 0x2C(r31)
	  mr        r3, r31
	  lwz       r12, 0x30(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1EC

	.loc_0x1E0:
	  fcmpo     cr0, f1, f3
	  ble-      .loc_0x1EC
	  stfs      f3, 0x2C(r31)

	.loc_0x1EC:
	  lfs       f0, 0x2C(r31)
	  fctiwz    f0, f0
	  stfd      f0, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stfd      f0, 0x48(r1)
	  cmpwi     r0, 0
	  lwz       r4, 0x4C(r1)
	  blt-      .loc_0x220
	  lwz       r3, 0x28(r31)
	  lwz       r3, 0x68(r3)
	  lwz       r0, 0x30(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x228

	.loc_0x220:
	  lfs       f0, -0x7B1C(r2)
	  stfs      f0, 0x2C(r31)

	.loc_0x228:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80051458
 * Size:	000008
 */
void Animator::changeContext(AnimContext* a1)
{
	// Generated from stw r4, 0x4(r3)
	// _04 = a1;
}

/*
 * --INFO--
 * Address:	80051460
 * Size:	000008
 */
int Parm<String>::size() { return sizeof(String); }

/*
 * --INFO--
 * Address:	80051468
 * Size:	000008
 */
int Parm<f32>::size() { return sizeof(f32); }

/*
 * --INFO--
 * Address:	80051470
 * Size:	000008
 */
int Parm<int>::size() { return sizeof(int); }
