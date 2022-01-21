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
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8012E6C8
 * Size:	000108
 */
TaiIwagonParameters::TaiIwagonParameters()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x14
	  stw       r0, 0x4(r1)
	  li        r5, 0x32
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  bl        0x1D664
	  lis       r3, 0x802D
	  subi      r0, r3, 0x7D30
	  stw       r0, 0x0(r31)
	  li        r5, -0x1
	  li        r0, 0x1
	  lwz       r6, 0x84(r31)
	  mr        r3, r31
	  lwz       r4, 0x0(r6)
	  lwz       r4, 0x0(r4)
	  stw       r5, 0xC(r4)
	  lwz       r4, 0x0(r6)
	  lwz       r4, 0x0(r4)
	  stw       r0, 0x8(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f2, -0x5CF0(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f2, 0x8(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f1, -0x5CEC(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f1, 0x4(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r4, 0x0(r4)
	  stfs      f2, 0x0(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f0, -0x5CE8(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x48(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f0, -0x5CE4(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x4C(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f0, -0x5CE0(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x50(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r4, 0x0(r4)
	  stfs      f2, 0x54(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r4, 0x0(r4)
	  stfs      f2, 0x30(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f0, -0x5CDC(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x64(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r4, 0x0(r4)
	  stfs      f1, 0xAC(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f0, -0x5CD8(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0xB0(r4)
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E7D0
 * Size:	000084
 */
TaiIwagonSoundTable::TaiIwagonSoundTable()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0xF77C
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0xE7800
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x64
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
 * Address:	8012E854
 * Size:	0004C0
 */
TaiIwagonStrategy::TaiIwagonStrategy(TekiParameters*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stmw      r21, 0x6C(r1)
	  addi      r21, r4, 0
	  addi      r31, r3, 0
	  li        r4, 0x2
	  bl        -0x7490
	  lis       r3, 0x802D
	  subi      r0, r3, 0x7DAC
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  bl        -0xE7884
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x64
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6140
	  stw       r0, 0x4(r30)

	.loc_0x64:
	  li        r3, 0xC
	  bl        -0xE78B8
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xAC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r29)
	  li        r4, 0
	  subi      r0, r3, 0x447C
	  stw       r4, 0x8(r29)
	  stw       r0, 0x4(r29)

	.loc_0xAC:
	  li        r3, 0xC
	  bl        -0xE7900
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xE8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r28)
	  addi      r3, r3, 0x7F58
	  li        r0, 0
	  stw       r3, 0x4(r28)
	  stw       r0, 0x8(r28)

	.loc_0xE8:
	  li        r3, 0xC
	  bl        -0xE793C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x124
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r27)
	  addi      r3, r3, 0x6A9C
	  li        r0, 0x64
	  stw       r3, 0x4(r27)
	  stw       r0, 0x8(r27)

	.loc_0x124:
	  li        r3, 0x10
	  bl        -0xE7978
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x168
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r26)
	  addi      r3, r3, 0x6B14
	  li        r0, 0
	  stw       r3, 0x4(r26)
	  lwz       r3, -0x9D0(r13)
	  stw       r3, 0x8(r26)
	  stb       r0, 0xC(r26)

	.loc_0x168:
	  li        r3, 0xC
	  bl        -0xE79BC
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x184
	  li        r4, 0x5
	  bl        -0x793C

	.loc_0x184:
	  li        r0, 0
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r25)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x3
	  stwx      r29, r3, r0
	  li        r0, 0x4
	  rlwinm    r3,r4,2,0,29
	  lwz       r5, 0x8(r25)
	  rlwinm    r4,r6,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r26, r5, r3
	  li        r3, 0x14
	  lwz       r5, 0x8(r25)
	  stwx      r28, r5, r4
	  lwz       r4, 0x8(r25)
	  stwx      r27, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r25, 0x0(r4)
	  bl        -0xE7A30
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x230
	  lwz       r5, 0x84(r21)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, 0
	  lwz       r6, 0x0(r6)
	  subi      r0, r3, 0x35D8
	  lfs       f0, 0x64(r6)
	  stw       r5, 0x4(r25)
	  stw       r4, 0x0(r25)
	  stw       r0, 0x4(r25)
	  stw       r4, 0x8(r25)
	  stfs      f0, 0xC(r25)
	  lfs       f0, -0x5CD4(r2)
	  stfs      f0, 0x10(r25)

	.loc_0x230:
	  li        r3, 0xC
	  bl        -0xE7A84
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x26C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r26)
	  addi      r3, r3, 0x6AD8
	  li        r0, 0x64
	  stw       r3, 0x4(r26)
	  stw       r0, 0x8(r26)

	.loc_0x26C:
	  li        r3, 0x8
	  bl        -0xE7AC0
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x2A0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x4580
	  stw       r0, 0x4(r27)

	.loc_0x2A0:
	  li        r3, 0x8
	  bl        -0xE7AF4
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x2D4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0
	  lis       r3, 0x802C
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x7DCC
	  stw       r0, 0x4(r28)

	.loc_0x2D4:
	  li        r3, 0xC
	  bl        -0xE7B28
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x31C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0
	  lis       r3, 0x802C
	  stw       r0, 0x0(r29)
	  addi      r0, r3, 0x7D8C
	  lis       r3, 0x802C
	  stw       r0, 0x4(r29)
	  addi      r3, r3, 0x7CE0
	  li        r0, 0x2
	  stw       r3, 0x4(r29)
	  stw       r0, 0x8(r29)

	.loc_0x31C:
	  li        r3, 0x8
	  bl        -0xE7B70
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x350
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r30)
	  addi      r0, r3, 0x67B8
	  stw       r0, 0x4(r30)

	.loc_0x350:
	  li        r3, 0x8
	  bl        -0xE7BA4
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x384
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, 0
	  lis       r3, 0x802D
	  stw       r0, 0x0(r24)
	  subi      r0, r3, 0x7E34
	  stw       r0, 0x4(r24)

	.loc_0x384:
	  li        r3, 0xC
	  bl        -0xE7BD8
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x3C0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r23)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r23)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0x6
	  stw       r3, 0x4(r23)
	  stw       r0, 0x8(r23)

	.loc_0x3C0:
	  li        r3, 0x8
	  bl        -0xE7C14
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0x3F4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r22)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r22)
	  subi      r0, r3, 0x7DF0
	  stw       r0, 0x4(r22)

	.loc_0x3F4:
	  li        r3, 0xC
	  bl        -0xE7C48
	  addi      r21, r3, 0
	  mr.       r3, r21
	  beq-      .loc_0x410
	  li        r4, 0x9
	  bl        -0x7BC8

	.loc_0x410:
	  li        r0, 0
	  lwz       r3, 0x8(r21)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r21)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r28, r3, r0
	  li        r6, 0x4
	  li        r7, 0x5
	  lwz       r3, 0x8(r21)
	  rlwinm    r0,r4,2,0,29
	  li        r8, 0x6
	  stwx      r29, r3, r0
	  li        r9, 0x7
	  li        r10, 0x8
	  lwz       r4, 0x8(r21)
	  rlwinm    r0,r5,2,0,29
	  rlwinm    r3,r6,2,0,29
	  stwx      r25, r4, r0
	  rlwinm    r6,r7,2,0,29
	  rlwinm    r5,r8,2,0,29
	  lwz       r7, 0x8(r21)
	  rlwinm    r4,r9,2,0,29
	  rlwinm    r0,r10,2,0,29
	  stwx      r30, r7, r3
	  mr        r3, r31
	  lwz       r7, 0x8(r21)
	  stwx      r24, r7, r6
	  lwz       r6, 0x8(r21)
	  stwx      r23, r6, r5
	  lwz       r5, 0x8(r21)
	  stwx      r26, r5, r4
	  lwz       r4, 0x8(r21)
	  stwx      r22, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r21, 0x4(r4)
	  lwz       r0, 0x9C(r1)
	  lmw       r21, 0x6C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012ED14
 * Size:	000114
 */
void TaiIwagonStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r4
	  stw       r30, 0x60(r1)
	  mr        r30, r3
	  lwz       r4, 0x2C8(r4)
	  lwz       r3, 0x34(r4)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x10(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x74
	  lfs       f0, -0x151C(r13)
	  addi      r5, r1, 0x4C
	  lfs       f1, -0x1518(r13)
	  li        r4, 0x5A
	  stfs      f0, 0x4C(r1)
	  lfs       f0, -0x1514(r13)
	  li        r6, 0
	  stfs      f1, 0x50(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x54(r1)
	  bl        0x6DDC0
	  lwz       r4, 0x3D8(r31)
	  stw       r3, 0x0(r4)
	  b         .loc_0xB4

	.loc_0x74:
	  cmpwi     r0, 0x1
	  bne-      .loc_0xB4
	  lfs       f0, -0x1510(r13)
	  addi      r5, r1, 0x40
	  lfs       f1, -0x150C(r13)
	  li        r4, 0x93
	  stfs      f0, 0x40(r1)
	  lfs       f0, -0x1508(r13)
	  li        r6, 0
	  stfs      f1, 0x44(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x48(r1)
	  bl        0x6DD7C
	  lwz       r4, 0x3D8(r31)
	  stw       r3, 0x0(r4)

	.loc_0xB4:
	  lwz       r3, 0x3D8(r31)
	  lwz       r3, 0x0(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xCC
	  addi      r0, r31, 0x94
	  stw       r0, 0x18(r3)

	.loc_0xCC:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x1AC34
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x7960
	  mr        r3, r31
	  lwz       r4, -0x9CC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
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
 * Address:	8012EE28
 * Size:	000070
 */
void TaiIwagonDustEffectAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  lwz       r3, 0x28C(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  bl        -0x18DC8
	  cmpwi     r3, 0x5
	  beq-      .loc_0x3C
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x1AB9C
	  b         .loc_0x58

	.loc_0x3C:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x1ABB0
	  b         .loc_0x58

	.loc_0x4C:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x1ABA0

	.loc_0x58:
	  lwz       r0, 0x1C(r1)
	  li        r3, 0
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012EE98
 * Size:	00001C
 */
void TaiIwagonRollingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x70(r4)
	  stfs      f0, 0x398(r4)
	  lfs       f0, 0x74(r4)
	  stfs      f0, 0x39C(r4)
	  lfs       f0, 0x78(r4)
	  stfs      f0, 0x3A0(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012EEB4
 * Size:	000020
 */
void TaiIwagonRollingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x398(r4)
	  li        r3, 0
	  stfs      f0, 0xA4(r4)
	  lfs       f0, 0x39C(r4)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, 0x3A0(r4)
	  stfs      f0, 0xAC(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012EED4
 * Size:	000118
 */
TaiIwagenParameters::TaiIwagenParameters()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x14
	  stw       r0, 0x4(r1)
	  li        r5, 0x33
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  bl        0x1CE58
	  lis       r3, 0x802D
	  subi      r0, r3, 0x7E88
	  stw       r0, 0x0(r31)
	  li        r0, 0x32
	  lis       r3, 0x802D
	  lwz       r4, 0x84(r31)
	  mulli     r6, r0, 0xC
	  lwz       r7, 0x4(r4)
	  subi      r5, r3, 0x7FEC
	  lwz       r7, 0x8(r7)
	  li        r0, 0x2
	  addi      r3, r31, 0
	  add       r6, r7, r6
	  stw       r5, 0x0(r6)
	  lfs       f2, -0x5CD4(r2)
	  stfs      f2, 0x4(r6)
	  lfs       f1, -0x5CEC(r2)
	  stfs      f1, 0x8(r6)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r0, 0xC(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0x8(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5CD0(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x4(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x0(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5CCC(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x34(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0x38(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5CC8(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x58(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5CC4(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x5C(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5CC0(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x60(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0xAC(r5)
	  lwz       r4, 0x4(r4)
	  lfs       f0, -0x5CBC(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0xC8(r4)
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012EFEC
 * Size:	000210
 */
TaiIwagenStrategy::TaiIwagenStrategy(TekiParameters*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x44(r1)
	  stw       r28, 0x40(r1)
	  addi      r28, r4, 0
	  li        r4, 0x3
	  bl        -0x7C34
	  lis       r3, 0x802D
	  subi      r0, r3, 0x7F40
	  stw       r0, 0x0(r30)
	  li        r3, 0x14
	  bl        -0xE8028
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x94
	  lwz       r5, 0x84(r28)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, 0x1
	  lwz       r6, 0x0(r6)
	  subi      r3, r3, 0x35D8
	  li        r0, 0
	  lfs       f0, 0x34(r6)
	  stw       r5, 0x4(r31)
	  stw       r4, 0x0(r31)
	  stw       r3, 0x4(r31)
	  stw       r0, 0x8(r31)
	  stfs      f0, 0xC(r31)
	  lfs       f0, -0x5CBC(r2)
	  stfs      f0, 0x10(r31)

	.loc_0x94:
	  li        r3, 0xC
	  bl        -0xE8080
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xB0
	  li        r4, 0x1
	  bl        -0x8000

	.loc_0xB0:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r31, r3, r0
	  li        r3, 0x8
	  lwz       r4, 0x8(r30)
	  stw       r29, 0x0(r4)
	  bl        -0xE80B4
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0xFC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r31)
	  li        r0, 0x2
	  lis       r3, 0x802D
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x7FAC
	  stw       r0, 0x4(r31)

	.loc_0xFC:
	  li        r3, 0xC
	  bl        -0xE80E8
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x138
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0x8
	  stw       r3, 0x4(r29)
	  stw       r0, 0x8(r29)

	.loc_0x138:
	  li        r3, 0xC
	  bl        -0xE8124
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x154
	  li        r4, 0x2
	  bl        -0x80A4

	.loc_0x154:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r28)
	  li        r3, 0xC
	  stwx      r31, r4, r0
	  lwz       r4, 0x8(r30)
	  stw       r28, 0x4(r4)
	  bl        -0xE8168
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1B8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x6B20
	  stw       r0, 0x4(r28)
	  lwz       r0, -0x9A0(r13)
	  stw       r0, 0x8(r28)

	.loc_0x1B8:
	  li        r3, 0xC
	  bl        -0xE81A4
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x1D4
	  li        r4, 0x1
	  bl        -0x8124

	.loc_0x1D4:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  mr        r3, r30
	  lwz       r4, 0x8(r30)
	  stw       r29, 0x8(r4)
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
 * Address:	8012F1FC
 * Size:	00007C
 */
void TaiIwagenStrategy::draw(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lwz       r0, 0x324(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x2C
	  lwz       r0, 0x324(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x60

	.loc_0x2C:
	  lwz       r4, 0x2D0(r31)
	  li        r0, 0
	  lwz       r6, 0x0(r4)
	  mr        r4, r31
	  lwz       r6, 0x5C(r6)
	  stw       r0, 0x13C(r6)
	  bl        0x1DF84
	  lwz       r3, 0x2D0(r31)
	  li        r0, 0x1
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x5C(r3)
	  stw       r0, 0x13C(r3)
	  b         .loc_0x68

	.loc_0x60:
	  mr        r4, r31
	  bl        0x1DF64

	.loc_0x68:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012F278
 * Size:	000044
 */
void TaiIwagenStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x7DF8
	  mr        r3, r31
	  lwz       r4, -0x9C0(r13)
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
 * Address:	8012F2BC
 * Size:	000078
 */
void TaiIwagenShootingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r5, r13, 0x1528
	  stw       r0, 0x4(r1)
	  subi      r6, r13, 0x1524
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  addi      r3, r1, 0x1C
	  subi      r4, r13, 0x152C
	  bl        -0xF81C4
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x1C
	  addi      r5, r1, 0x20
	  addi      r6, r1, 0x24
	  bl        -0xD1C68
	  addi      r3, r1, 0x10
	  subi      r4, r13, 0x1538
	  subi      r5, r13, 0x1534
	  subi      r6, r13, 0x1530
	  bl        -0xF81EC
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x10
	  addi      r5, r1, 0x14
	  addi      r6, r1, 0x18
	  bl        -0xD1C90
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012F334
 * Size:	000198
 */
void TaiIwagenShootingAction::act(Teki&)
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
	  stw       r31, 0xBC(r1)
	  stw       r30, 0xB8(r1)
	  mr        r30, r4
	  lwz       r0, -0x99C(r13)
	  lwz       r3, 0x414(r4)
	  and.      r0, r3, r0
	  beq-      .loc_0x16C
	  lwz       r4, 0x2C4(r30)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r4, 0x84(r4)
	  lwz       r12, 0x194(r12)
	  lwz       r4, 0x0(r4)
	  mtlr      r12
	  lwz       r4, 0x0(r4)
	  lwz       r4, 0xC(r4)
	  blrl
	  mr.       r31, r3
	  bne-      .loc_0x70
	  li        r3, 0x1
	  b         .loc_0x170

	.loc_0x70:
	  lwz       r3, 0x2C4(r30)
	  li        r4, 0x32
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xCEE0
	  lwz       r4, 0x2C8(r31)
	  li        r0, 0
	  addi      r3, r30, 0
	  lwz       r5, 0x34(r4)
	  addi      r4, r1, 0xA8
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x0(r5)
	  lwz       r5, 0x2C8(r31)
	  lwz       r5, 0x34(r5)
	  lwz       r5, 0x0(r5)
	  lwz       r5, 0x0(r5)
	  stw       r0, 0x10(r5)
	  lfs       f0, -0x5CD4(r2)
	  stfs      f0, 0xB0(r1)
	  stfs      f0, 0xAC(r1)
	  stfs      f0, 0xA8(r1)
	  bl        0x171B4
	  lwz       r3, 0xA8(r1)
	  lwz       r0, 0xAC(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0xB0(r1)
	  stw       r0, 0x9C(r31)
	  lfs       f30, 0xA0(r30)
	  fmr       f1, f30
	  bl        0xEC734
	  fmr       f29, f1
	  fmr       f1, f30
	  bl        0xEC8BC
	  lwz       r3, 0x2C8(r30)
	  fmr       f30, f1
	  lfs       f28, -0x1520(r13)
	  li        r4, 0x1
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xCF74
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  li        r4, 0x18
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xCF8C
	  fmuls     f0, f1, f31
	  addi      r3, r31, 0
	  li        r4, 0
	  fmuls     f1, f30, f0
	  fmuls     f28, f28, f0
	  fmuls     f0, f29, f0
	  stfs      f1, 0x70(r31)
	  stfs      f28, 0x74(r31)
	  stfs      f0, 0x78(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x170

	.loc_0x16C:
	  li        r3, 0

	.loc_0x170:
	  lwz       r0, 0xE4(r1)
	  lfd       f31, 0xD8(r1)
	  lfd       f30, 0xD0(r1)
	  lfd       f29, 0xC8(r1)
	  lfd       f28, 0xC0(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}
