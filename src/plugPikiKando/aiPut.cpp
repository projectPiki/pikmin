#include "PikiAI.h"
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
 * Address:	800BE9F4
 * Size:	0000A0
 */
void ActPutBomb::procCollideMsg(Piki*, MsgCollide*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  lhz       r0, 0x18(r3)
	  cmplwi    r0, 0x4
	  bne-      .loc_0x84
	  lwz       r31, 0x4(r5)
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x36
	  bne-      .loc_0x84
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x84
	  lwz       r0, 0x180(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x84
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x2
	  li        r5, 0
	  li        r6, 0
	  bl        0xBE2E0
	  li        r0, 0x1
	  stb       r0, 0x1B(r29)
	  stw       r31, 0x504(r30)

	.loc_0x84:
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
 * Address:	800BEA94
 * Size:	000088
 */
ActPutBomb::ActPutBomb(Piki* piki)
    : Action(piki, false)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  extsh.    r0, r4
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0x30
	  addi      r0, r31, 0x28
	  lis       r3, 0x802B
	  stw       r0, 0x14(r31)
	  subi      r0, r3, 0x246C
	  stw       r0, 0x28(r31)

	.loc_0x30:
	  addi      r3, r31, 0
	  addi      r4, r5, 0
	  li        r5, 0x1
	  bl        0x5300
	  lis       r3, 0x802B
	  addi      r3, r3, 0x75D4
	  stw       r3, 0x0(r31)
	  addi      r6, r3, 0x68
	  addi      r4, r31, 0x28
	  lwz       r5, 0x14(r31)
	  subi      r0, r13, 0x46A8
	  addi      r3, r31, 0
	  stw       r6, 0x0(r5)
	  lwz       r5, 0x14(r31)
	  sub       r4, r4, r5
	  stw       r4, 0x4(r5)
	  stw       r0, 0x10(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BEB1C
 * Size:	00048C
 */
Creature* ActPutBomb::findTeki()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stfd      f31, 0x78(r1)
	  stw       r31, 0x74(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x70(r1)
	  stw       r29, 0x6C(r1)
	  stw       r28, 0x68(r1)
	  lwz       r28, 0x3160(r13)
	  cmplwi    r28, 0
	  bne-      .loc_0x3C
	  li        r0, 0
	  stw       r0, 0x24(r31)
	  b         .loc_0x468

	.loc_0x3C:
	  lwz       r3, 0xC(r31)
	  li        r0, 0
	  lwz       r4, 0x224(r3)
	  mr        r3, r28
	  lfs       f31, 0x4B8(r4)
	  stw       r0, 0x24(r31)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x140

	.loc_0x6C:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x94
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xB0

	.loc_0x94:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xB0:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x124
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x124
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x124
	  mr        r3, r30
	  lwz       r4, 0xC(r31)
	  bl        -0x31DAC
	  fcmpo     cr0, f1, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x124
	  fmr       f31, f1
	  stw       r30, 0x24(r31)

	.loc_0x124:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x140:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x168
	  li        r0, 0x1
	  b         .loc_0x194

	.loc_0x168:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x190
	  li        r0, 0x1
	  b         .loc_0x194

	.loc_0x190:
	  li        r0, 0

	.loc_0x194:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x6C
	  lwz       r29, 0x3168(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x29C

	.loc_0x1BC:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x1E4
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x200

	.loc_0x1E4:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x200:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x280
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x280
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x280
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0x31
	  beq-      .loc_0x280
	  mr        r3, r30
	  lwz       r4, 0xC(r31)
	  bl        -0x31F08
	  fcmpo     cr0, f1, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x280
	  fmr       f31, f1
	  stw       r30, 0x24(r31)

	.loc_0x280:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x29C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2C4
	  li        r0, 0x1
	  b         .loc_0x2F0

	.loc_0x2C4:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
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
	  beq+      .loc_0x1BC
	  lwz       r3, 0x30AC(r13)
	  lwz       r28, 0x68(r3)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x40C

	.loc_0x31C:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x344
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x360

	.loc_0x344:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x360:
	  lwz       r5, 0x6C(r30)
	  li        r3, 0x1
	  addi      r4, r3, 0
	  cmpwi     r5, 0x16
	  addi      r0, r3, 0
	  beq-      .loc_0x384
	  cmpwi     r5, 0x17
	  beq-      .loc_0x384
	  li        r0, 0

	.loc_0x384:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x398
	  cmpwi     r5, 0x18
	  beq-      .loc_0x398
	  li        r4, 0

	.loc_0x398:
	  rlwinm.   r0,r4,0,24,31
	  bne-      .loc_0x3AC
	  cmpwi     r5, 0x19
	  beq-      .loc_0x3AC
	  li        r3, 0

	.loc_0x3AC:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3F0
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3F0
	  mr        r3, r30
	  lwz       r4, 0xC(r31)
	  bl        -0x32078
	  fcmpo     cr0, f1, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x3F0
	  fmr       f31, f1
	  stw       r30, 0x24(r31)

	.loc_0x3F0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x40C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x434
	  li        r0, 0x1
	  b         .loc_0x460

	.loc_0x434:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x45C
	  li        r0, 0x1
	  b         .loc_0x460

	.loc_0x45C:
	  li        r0, 0

	.loc_0x460:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x31C

	.loc_0x468:
	  lwz       r0, 0x84(r1)
	  lfd       f31, 0x78(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  lwz       r28, 0x68(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BEFA8
 * Size:	0001C0
 */
void ActPutBomb::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x5
	  stwu      r1, -0xC0(r1)
	  stw       r31, 0xBC(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xB8(r1)
	  stw       r29, 0xB4(r1)
	  stb       r4, 0x1B(r3)
	  sth       r0, 0x18(r3)
	  lwz       r3, 0xC(r3)
	  stb       r4, 0x408(r3)
	  lwz       r3, 0x2F80(r13)
	  lwz       r0, 0x130(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x120
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x120
	  mr        r3, r31
	  bl        -0x4E4
	  lwz       r3, 0x24(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xA0
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x37
	  beq-      .loc_0x8C
	  bl        -0x34D74
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x8C
	  mr        r3, r31
	  bl        .loc_0x1C0
	  b         .loc_0xB0

	.loc_0x8C:
	  li        r0, 0x1
	  sth       r0, 0x18(r31)
	  mr        r3, r31
	  bl        0x470
	  b         .loc_0xB0

	.loc_0xA0:
	  li        r0, 0x4
	  sth       r0, 0x18(r31)
	  mr        r3, r31
	  bl        0x894

	.loc_0xB0:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x39C(r3)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x1A4
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0xD0
	  lwz       r29, 0x14(r31)

	.loc_0xD0:
	  addi      r3, r1, 0xA0
	  li        r4, 0x4
	  bl        0x5FED8
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0xA8
	  li        r4, 0x4
	  bl        0x5FEF8
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xB934
	  lfs       f0, -0x6BEC(r2)
	  lwz       r3, 0xC(r31)
	  stfs      f0, 0x384(r3)
	  lwz       r3, 0xC(r31)
	  stfs      f0, 0x3D8(r3)
	  lwz       r3, 0xC(r31)
	  bl        0xBB4C
	  b         .loc_0x1A4

	.loc_0x120:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A4
	  lwz       r0, 0x39C(r3)
	  cmpwi     r0, 0x4
	  bne-      .loc_0x148
	  mr        r3, r31
	  bl        0x890
	  b         .loc_0x1A4

	.loc_0x148:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x158
	  lwz       r29, 0x14(r31)

	.loc_0x158:
	  addi      r3, r1, 0x90
	  li        r4, 0x4
	  bl        0x5FE50
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x98
	  li        r4, 0x4
	  bl        0x5FE70
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xB8AC
	  lfs       f0, -0x6BEC(r2)
	  mr        r3, r31
	  lwz       r4, 0xC(r31)
	  stfs      f0, 0x384(r4)
	  lwz       r4, 0xC(r31)
	  stfs      f0, 0x3D8(r4)
	  bl        0x830

	.loc_0x1A4:
	  lwz       r0, 0xC4(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  lwz       r29, 0xB4(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr

	.loc_0x1C0:
	*/
}

/*
 * --INFO--
 * Address:	800BF168
 * Size:	00000C
 */
void ActPutBomb::initSet()
{
	// Generated from sth r0, 0x18(r3)
	// _18 = 2;
}

/*
 * --INFO--
 * Address:	800BF174
 * Size:	0001D8
 */
int ActPutBomb::exeSet()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stfd      f30, 0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r3
	  lwz       r3, 0xC(r3)
	  bl        0x8CDC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x40
	  lwz       r4, 0xC(r31)
	  li        r0, 0x7
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x1BC

	.loc_0x40:
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x24(r31)
	  lfsu      f1, 0x94(r3)
	  lfsu      f0, 0x94(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x4(r4)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0x8(r4)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x50(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x54(r1)
	  stfs      f0, 0x58(r1)
	  lwz       r3, 0x24(r31)
	  lwz       r4, 0xC(r31)
	  bl        -0x32378
	  fmr       f30, f1
	  lfs       f1, 0x50(r1)
	  lfs       f2, 0x58(r1)
	  bl        0x15C7F4
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x86C5C
	  fmr       f31, f1
	  lfs       f0, -0x6BE8(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f0, f0, f31
	  lfs       f1, 0xA0(r3)
	  fadds     f1, f1, f0
	  bl        -0x86CA4
	  lwz       r3, 0xC(r31)
	  stfs      f1, 0xA0(r3)
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x528(r3)
	  fcmpo     cr0, f30, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x154
	  fabs      f1, f31
	  lfs       f0, -0x6BE4(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x154
	  mr        r3, r31
	  bl        .loc_0x1D8
	  lis       r3, 0x802B
	  lwz       r4, 0xC(r31)
	  subi      r0, r3, 0x3064
	  lfs       f0, -0x6BE0(r2)
	  stw       r0, 0x44(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x2E74
	  stw       r4, 0x48(r1)
	  addi      r4, r1, 0x44
	  stw       r0, 0x44(r1)
	  stfs      f0, 0x4C(r1)
	  lwz       r3, 0xC(r31)
	  lwz       r31, 0x2AC(r3)
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E8(r31)
	  mr        r4, r31
	  li        r5, 0x2
	  bl        -0x41B64
	  li        r3, 0x2
	  b         .loc_0x1BC

	.loc_0x154:
	  lfs       f1, 0x50(r1)
	  lfs       f0, 0x54(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x58(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xB16A8
	  lfs       f0, -0x6BF0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1A8
	  lfs       f0, 0x50(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x54(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x58(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x58(r1)

	.loc_0x1A8:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x50
	  lfs       f1, -0x6BDC(r2)
	  bl        0xCAB0
	  li        r3, 0

	.loc_0x1BC:
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lfd       f30, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr

	.loc_0x1D8:
	*/
}

/*
 * --INFO--
 * Address:	800BF34C
 * Size:	000164
 */
void ActPutBomb::warnPikis()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r25, 0x44(r1)
	  addi      r30, r3, 0
	  lwz       r31, 0x3068(r13)
	  lwz       r12, 0x0(r31)
	  addi      r3, r31, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802B
	  addi      r26, r3, 0
	  subi      r28, r5, 0x3064
	  subi      r29, r4, 0x2DBC
	  addi      r27, r1, 0x2C
	  b         .loc_0xF4

	.loc_0x48:
	  cmpwi     r26, -0x1
	  bne-      .loc_0x6C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x84

	.loc_0x6C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x84:
	  lwz       r4, 0xC(r30)
	  addi      r25, r3, 0
	  cmplw     r3, r4
	  beq-      .loc_0xD8
	  mr        r3, r25
	  bl        -0x32568
	  lwz       r5, 0xC(r30)
	  lwz       r3, 0x224(r5)
	  lfs       f0, 0x508(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xD8
	  stw       r28, 0x2C(r1)
	  addi      r3, r25, 0
	  addi      r4, r27, 0
	  stw       r5, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0xD8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0xF4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x11C
	  li        r0, 0x1
	  b         .loc_0x148

	.loc_0x11C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x144
	  li        r0, 0x1
	  b         .loc_0x148

	.loc_0x144:
	  li        r0, 0

	.loc_0x148:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x48
	  lmw       r25, 0x44(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BF4B0
 * Size:	00016C
 */
void ActPutBomb::initAim()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x60(r1)
	  stmw      r27, 0x4C(r1)
	  addi      r31, r3, 0
	  sth       r0, 0x18(r3)
	  li        r0, 0
	  addi      r3, r1, 0x30
	  lwz       r4, 0x3068(r13)
	  stw       r4, 0x34(r1)
	  stw       r0, 0x38(r1)
	  bl        -0x2F724
	  lis       r4, 0x802B
	  lis       r3, 0x802B
	  subi      r29, r4, 0x3064
	  subi      r30, r3, 0x2DBC
	  addi      r27, r1, 0x3C
	  b         .loc_0xE4

	.loc_0x4C:
	  lwz       r4, 0x30(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x74
	  lwz       r3, 0x34(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x88

	.loc_0x74:
	  lwz       r3, 0x34(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x88:
	  lwz       r4, 0xC(r31)
	  addi      r28, r3, 0
	  cmplw     r3, r4
	  beq-      .loc_0xDC
	  mr        r3, r28
	  bl        -0x326D0
	  lwz       r5, 0xC(r31)
	  lwz       r3, 0x224(r5)
	  lfs       f0, 0x508(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xDC
	  stw       r29, 0x3C(r1)
	  addi      r3, r28, 0
	  addi      r4, r27, 0
	  stw       r5, 0x40(r1)
	  stw       r30, 0x3C(r1)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0xDC:
	  addi      r3, r1, 0x30
	  bl        -0x2F8F8

	.loc_0xE4:
	  lwz       r3, 0x34(r1)
	  lwz       r4, 0x30(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10C
	  li        r0, 0x1
	  b         .loc_0x138

	.loc_0x10C:
	  lwz       r3, 0x34(r1)
	  lwz       r4, 0x30(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x134
	  li        r0, 0x1
	  b         .loc_0x138

	.loc_0x134:
	  li        r0, 0

	.loc_0x138:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x4C
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x518(r3)
	  stfs      f0, 0x1C(r31)
	  lfs       f0, -0x6BF0(r2)
	  stfs      f0, 0x20(r31)
	  lwz       r0, 0x64(r1)
	  lmw       r27, 0x4C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BF61C
 * Size:	0002CC
 */
int ActPutBomb::exeAim()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stfd      f31, 0x98(r1)
	  stfd      f30, 0x90(r1)
	  stw       r31, 0x8C(r1)
	  mr        r31, r3
	  lwz       r3, 0x24(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x54
	  lwz       r3, 0x24(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x64

	.loc_0x54:
	  mr        r3, r31
	  bl        .loc_0x2CC
	  li        r3, 0
	  b         .loc_0x2B0

	.loc_0x64:
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x24(r31)
	  lfsu      f1, 0x94(r3)
	  lfsu      f0, 0x94(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x4(r4)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0x8(r4)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x7C(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x80(r1)
	  stfs      f0, 0x84(r1)
	  lwz       r3, 0x24(r31)
	  lwz       r4, 0xC(r31)
	  bl        -0x32844
	  fmr       f31, f1
	  lfs       f1, 0x7C(r1)
	  lfs       f2, 0x84(r1)
	  bl        0x15C328
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x87128
	  fmr       f30, f1
	  lfs       f0, -0x6BE8(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f0, f0, f30
	  lfs       f1, 0xA0(r3)
	  fadds     f1, f1, f0
	  bl        -0x87170
	  lwz       r3, 0xC(r31)
	  stfs      f1, 0xA0(r3)
	  lfs       f1, 0x1C(r31)
	  lfs       f0, -0x6BF0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x108
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1C(r31)

	.loc_0x108:
	  lwz       r3, 0x24(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r31)
	  fsubs     f31, f31, f1
	  lwz       r4, 0x224(r3)
	  lfs       f0, 0x4C8(r4)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x198
	  lfs       f0, 0x4D8(r4)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x198
	  fabs      f1, f30
	  lfs       f0, -0x6BE4(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x174
	  lfs       f1, 0x1C(r31)
	  lfs       f0, -0x6BF0(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x174
	  mr        r3, r31
	  bl        0x170
	  li        r3, 0
	  b         .loc_0x2B0

	.loc_0x174:
	  lwz       r4, 0xC(r31)
	  li        r3, 0
	  lfs       f0, -0x46A0(r13)
	  stfsu     f0, 0xA4(r4)
	  lfs       f0, -0x469C(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x4698(r13)
	  stfs      f0, 0x8(r4)
	  b         .loc_0x2B0

	.loc_0x198:
	  lfs       f1, 0x7C(r1)
	  lfs       f0, 0x80(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x84(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xB1B94
	  lfs       f0, -0x6BF0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1EC
	  lfs       f0, 0x7C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x80(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x84(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x84(r1)

	.loc_0x1EC:
	  fabs      f1, f1
	  lfs       f0, -0x6BC8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x218
	  lfs       f1, -0x4694(r13)
	  lfs       f0, -0x4690(r13)
	  stfs      f1, 0x7C(r1)
	  stfs      f0, 0x80(r1)
	  lfs       f0, -0x468C(r13)
	  stfs      f0, 0x84(r1)

	.loc_0x218:
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x4C8(r3)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x294
	  lfs       f0, 0x7C(r1)
	  lfs       f1, -0x6BC4(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x80(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x84(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x84(r1)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x20(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f1, 0x20(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x4E8(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x29C
	  li        r0, 0x2
	  sth       r0, 0x18(r31)
	  li        r3, 0
	  b         .loc_0x2B0

	.loc_0x294:
	  lfs       f0, -0x6BF0(r2)
	  stfs      f0, 0x20(r31)

	.loc_0x29C:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x7C
	  lfs       f1, -0x6BDC(r2)
	  bl        0xC514
	  li        r3, 0

	.loc_0x2B0:
	  lwz       r0, 0xA4(r1)
	  lfd       f31, 0x98(r1)
	  lfd       f30, 0x90(r1)
	  lwz       r31, 0x8C(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr

	.loc_0x2CC:
	*/
}

/*
 * --INFO--
 * Address:	800BF8E8
 * Size:	00000C
 */
void ActPutBomb::initWait()
{
	// Generated from sth r0, 0x18(r3)
	// _18 = 4;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
int ActPutBomb::exeWait()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800BF8F4
 * Size:	000084
 */
void ActPutBomb::initThrow()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r3
	  stb       r0, 0x1A(r3)
	  mr        r30, r29
	  beq-      .loc_0x30
	  lwz       r30, 0x14(r29)

	.loc_0x30:
	  addi      r3, r1, 0xC
	  li        r4, 0xF
	  bl        0x5F62C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x14
	  li        r4, 0xF
	  bl        0x5F64C
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0xB088
	  li        r0, 0
	  sth       r0, 0x18(r29)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BF978
 * Size:	00014C
 */
void ActPutBomb::initPut()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stw       r31, 0x64(r1)
	  mr.       r31, r3
	  stw       r30, 0x60(r1)
	  stw       r29, 0x5C(r1)
	  addi      r29, r31, 0
	  beq-      .loc_0x2C
	  lwz       r29, 0x14(r31)

	.loc_0x2C:
	  addi      r3, r1, 0x20
	  li        r4, 0xF
	  bl        0x5F5AC
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x28
	  li        r4, 0xF
	  bl        0x5F5CC
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xB008
	  lis       r3, 0x802B
	  lwz       r4, 0xC(r31)
	  subi      r0, r3, 0x3064
	  lfs       f0, -0x6BE0(r2)
	  stw       r0, 0x4C(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x2E74
	  stw       r4, 0x50(r1)
	  addi      r4, r1, 0x4C
	  stw       r0, 0x4C(r1)
	  stfs      f0, 0x54(r1)
	  lwz       r3, 0xC(r31)
	  lwz       r29, 0x2AC(r3)
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r31)
	  lfs       f1, 0xA0(r3)
	  bl        0x15C130
	  lfs       f0, -0x6BC0(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f31, f0, f1
	  lfs       f1, 0xA0(r3)
	  bl        0x15C2B0
	  lfs       f2, -0x6BC0(r2)
	  li        r0, 0xA
	  lfs       f0, 0x70(r29)
	  li        r30, 0
	  fmuls     f1, f2, f1
	  mr        r4, r29
	  addi      r5, r1, 0x30
	  fadds     f0, f0, f1
	  stfs      f0, 0x70(r29)
	  lfs       f1, 0x74(r29)
	  lfs       f0, -0x6BBC(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x74(r29)
	  lfs       f0, 0x78(r29)
	  fadds     f0, f0, f31
	  stfs      f0, 0x78(r29)
	  stw       r0, 0x30(r1)
	  stw       r30, 0x34(r1)
	  lwz       r3, 0x2E8(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0x1A(r31)
	  li        r0, 0x3
	  sth       r0, 0x18(r31)
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BFAC4
 * Size:	00023C
 */
int ActPutBomb::exeThrow()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  mr        r31, r3
	  stw       r30, 0x88(r1)
	  lfs       f0, -0x467C(r13)
	  lwz       r3, 0xC(r3)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4678(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4674(r13)
	  stfs      f0, 0x8(r3)
	  lbz       r0, 0x1A(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x220
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x218
	  lwz       r4, 0x24(r31)
	  addi      r3, r1, 0x38
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x38(r1)
	  li        r30, 0
	  lfs       f0, 0x3C(r1)
	  stfs      f1, 0x78(r1)
	  lfs       f1, 0x40(r1)
	  stfs      f0, 0x7C(r1)
	  lfs       f0, -0x6BF0(r2)
	  stfs      f1, 0x80(r1)
	  lwz       r3, 0x24(r31)
	  lfsu      f1, 0x70(r3)
	  stfs      f1, 0x6C(r1)
	  lfs       f1, 0x4(r3)
	  stfs      f1, 0x70(r1)
	  lfs       f1, 0x8(r3)
	  stfs      f0, 0x68(r1)
	  stfs      f0, 0x64(r1)
	  stfs      f1, 0x74(r1)
	  stfs      f0, 0x60(r1)
	  lwz       r3, 0x24(r31)
	  lwz       r3, 0x220(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xE4
	  bl        -0x36034
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE4
	  lwz       r5, 0x24(r31)
	  lis       r3, 0x6265
	  addi      r4, r3, 0x6174
	  lwz       r3, 0x220(r5)
	  bl        -0x36490
	  mr        r30, r3

	.loc_0xE4:
	  cmplwi    r30, 0
	  bne-      .loc_0xFC
	  lis       r4, 0x2A2A
	  lwz       r3, 0x24(r31)
	  addi      r4, r4, 0x2A2A
	  bl        -0x357F0

	.loc_0xFC:
	  cmplwi    r30, 0
	  beq-      .loc_0x11C
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x8(r30)
	  stw       r3, 0x78(r1)
	  stw       r0, 0x7C(r1)
	  lwz       r0, 0xC(r30)
	  stw       r0, 0x80(r1)

	.loc_0x11C:
	  lwz       r4, 0xC(r31)
	  addi      r3, r1, 0x60
	  lwz       r12, 0x0(r4)
	  lwz       r5, 0x2AC(r4)
	  lwz       r12, 0x100(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0xC(r31)
	  addi      r3, r1, 0x2C
	  addi      r4, r1, 0x60
	  lwz       r7, 0x224(r5)
	  addi      r5, r1, 0x78
	  addi      r6, r1, 0x6C
	  lfs       f1, 0x4F8(r7)
	  bl        0x530CC
	  lfs       f1, 0x2C(r1)
	  lis       r3, 0x802B
	  lis       r4, 0x802B
	  lfs       f0, 0x30(r1)
	  stfs      f1, 0x50(r1)
	  subi      r5, r4, 0x3064
	  lfs       f1, 0x34(r1)
	  stfs      f0, 0x54(r1)
	  subi      r0, r3, 0x2E74
	  lfs       f0, -0x6BE0(r2)
	  addi      r4, r1, 0x44
	  stfs      f1, 0x58(r1)
	  lwz       r3, 0xC(r31)
	  stw       r5, 0x44(r1)
	  stw       r3, 0x48(r1)
	  stw       r0, 0x44(r1)
	  stfs      f0, 0x4C(r1)
	  lwz       r3, 0xC(r31)
	  lwz       r31, 0x2AC(r3)
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x50(r1)
	  mr        r30, r31
	  lwz       r3, 0x54(r1)
	  li        r0, 0
	  addi      r4, r30, 0
	  stw       r5, 0x70(r31)
	  li        r5, 0x1
	  stw       r3, 0x74(r31)
	  lwz       r3, 0x58(r1)
	  stw       r3, 0x78(r31)
	  lwz       r6, 0x50(r1)
	  lwz       r3, 0x54(r1)
	  stw       r6, 0xA4(r31)
	  stw       r3, 0xA8(r31)
	  lwz       r3, 0x58(r1)
	  stw       r3, 0xAC(r31)
	  stw       r0, 0x2D0(r31)
	  lwz       r3, 0x2E8(r31)
	  bl        -0x4256C
	  lwz       r0, 0xC8(r30)
	  li        r3, 0x2
	  rlwinm    r0,r0,0,10,8
	  stw       r0, 0xC8(r30)
	  b         .loc_0x224

	.loc_0x218:
	  li        r3, 0x1
	  b         .loc_0x224

	.loc_0x220:
	  li        r3, 0

	.loc_0x224:
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
int ActPutBomb::exePut()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800BFD00
 * Size:	000210
 */
int ActPutBomb::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r3
	  stw       r30, 0x60(r1)
	  stw       r29, 0x5C(r1)
	  lbz       r0, 0x1B(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C
	  lwz       r3, 0xC(r31)
	  bl        0x8828
	  cmpwi     r3, 0x1A
	  beq-      .loc_0x54
	  lwz       r4, 0xC(r31)
	  li        r5, 0x1A
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x54:
	  li        r3, 0
	  b         .loc_0x1F4

	.loc_0x5C:
	  lhz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xD4
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x39C(r3)
	  cmpwi     r0, 0x4
	  beq-      .loc_0xD4
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x88
	  lwz       r29, 0x14(r31)

	.loc_0x88:
	  addi      r3, r1, 0x48
	  li        r4, 0x4
	  bl        0x5F1C8
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x50
	  li        r4, 0x4
	  bl        0x5F1E8
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xAC24
	  lfs       f0, -0x6BEC(r2)
	  lwz       r3, 0xC(r31)
	  stfs      f0, 0x384(r3)
	  lwz       r3, 0xC(r31)
	  stfs      f0, 0x3D8(r3)
	  lwz       r3, 0xC(r31)
	  bl        0xAE3C

	.loc_0xD4:
	  lhz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x104
	  lwz       r3, 0xC(r31)
	  bl        0x808C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x104
	  lwz       r4, 0xC(r31)
	  li        r0, 0x7
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x1F4

	.loc_0x104:
	  lhz       r0, 0x18(r31)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x134
	  bge-      .loc_0x124
	  cmpwi     r0, 0
	  beq-      .loc_0x1AC
	  bge-      .loc_0x140
	  b         .loc_0x1F0

	.loc_0x124:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x14C
	  bge-      .loc_0x1F0
	  b         .loc_0x1B8

	.loc_0x134:
	  mr        r3, r31
	  bl        -0xCC4
	  b         .loc_0x1F4

	.loc_0x140:
	  mr        r3, r31
	  bl        -0x828
	  b         .loc_0x1F4

	.loc_0x14C:
	  lwz       r4, 0xC(r31)
	  mr        r3, r31
	  lfs       f0, -0x4688(r13)
	  stfsu     f0, 0xA4(r4)
	  lfs       f0, -0x4684(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x4680(r13)
	  stfs      f0, 0x8(r4)
	  bl        -0x1350
	  lwz       r0, 0x24(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A4
	  li        r0, 0x1
	  sth       r0, 0x18(r31)
	  mr        r3, r31
	  bl        -0xB3C
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x518(r3)
	  stfs      f0, 0x1C(r31)
	  lfs       f0, -0x6BF0(r2)
	  stfs      f0, 0x20(r31)

	.loc_0x1A4:
	  li        r3, 0
	  b         .loc_0x1F4

	.loc_0x1AC:
	  mr        r3, r31
	  bl        -0x3EC
	  b         .loc_0x1F4

	.loc_0x1B8:
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4670(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x466C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4668(r13)
	  stfs      f0, 0x8(r3)
	  lbz       r0, 0x1A(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1E8
	  li        r3, 0x2
	  b         .loc_0x1F4

	.loc_0x1E8:
	  li        r3, 0
	  b         .loc_0x1F4

	.loc_0x1F0:
	  li        r3, 0x2

	.loc_0x1F4:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BFF10
 * Size:	000038
 */
void ActPutBomb::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beqlr-
	  bgelr-
	  cmpwi     r0, 0
	  bltlr-
	  lhz       r0, 0x18(r3)
	  cmplwi    r0, 0x3
	  beq-      .loc_0x2C
	  cmplwi    r0, 0
	  bnelr-

	.loc_0x2C:
	  li        r0, 0x1
	  stb       r0, 0x1A(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BFF48
 * Size:	000004
 */
void ActPutBomb::cleanup()
{
}

/*
 * --INFO--
 * Address:	800BFF4C
 * Size:	00005C
 */
ActPutItem::ActPutItem(Piki* piki)
    : Action(piki, false)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        0x3E6C
	  lis       r3, 0x802B
	  addi      r0, r3, 0x7534
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  lfs       f0, -0x6BF0(r2)
	  stfs      f0, 0x1C(r31)
	  stfs      f0, 0x18(r31)
	  stfs      f0, 0x14(r31)
	  stw       r0, 0x20(r31)
	  stw       r0, 0x20(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BFFA8
 * Size:	00040C
 */
void ActPutItem::findPos()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stfd      f31, 0x100(r1)
	  stfd      f30, 0xF8(r1)
	  stfd      f29, 0xF0(r1)
	  stfd      f28, 0xE8(r1)
	  stfd      f27, 0xE0(r1)
	  stw       r31, 0xDC(r1)
	  li        r31, 0
	  stw       r30, 0xD8(r1)
	  mr        r30, r3
	  stw       r29, 0xD4(r1)
	  stw       r28, 0xD0(r1)
	  lwz       r29, 0x30AC(r13)
	  lfs       f28, -0x6BBC(r2)
	  lwz       r12, 0x0(r29)
	  addi      r3, r29, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x6BF0(r2)
	  mr        r28, r3
	  lfd       f30, -0x6BD8(r2)
	  lfd       f29, -0x6BD0(r2)
	  b         .loc_0x170

	.loc_0x68:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x8C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xA4

	.loc_0x8C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xA4:
	  lwz       r4, 0x20(r30)
	  lfs       f3, 0x98(r3)
	  addi      r4, r4, 0x94
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x4(r4)
	  lfs       f0, 0x0(r4)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x9C(r3)
	  fsubs     f1, f1, f0
	  lfs       f0, 0x8(r4)
	  fsubs     f2, f2, f0
	  fmuls     f1, f1, f1
	  fmuls     f0, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f31
	  ble-      .loc_0x13C
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
	  stfs      f0, 0x68(r1)
	  lfs       f2, 0x68(r1)

	.loc_0x13C:
	  fcmpo     cr0, f2, f28
	  fmr       f27, f2
	  cror      2, 0, 0x2
	  bne-      .loc_0x154
	  mr        r31, r3
	  fmr       f28, f2

	.loc_0x154:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x170:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x198
	  li        r0, 0x1
	  b         .loc_0x1C4

	.loc_0x198:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1C0
	  li        r0, 0x1
	  b         .loc_0x1C4

	.loc_0x1C0:
	  li        r0, 0

	.loc_0x1C4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x68
	  cmplwi    r31, 0
	  beq-      .loc_0x3BC
	  lfs       f29, -0x6BF0(r2)
	  lfd       f30, -0x6BD8(r2)
	  lfd       f31, -0x6BD0(r2)
	  b         .loc_0x3A4

	.loc_0x1E4:
	  lwz       r28, 0x30AC(r13)
	  li        r31, 0
	  lfs       f28, -0x6BBC(r2)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x31C

	.loc_0x20C:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x230
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x248

	.loc_0x230:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x248:
	  lwz       r4, 0x20(r30)
	  lfs       f3, 0x98(r3)
	  addi      r4, r4, 0x94
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x4(r4)
	  lfs       f0, 0x0(r4)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x9C(r3)
	  fsubs     f1, f1, f0
	  lfs       f0, 0x8(r4)
	  fsubs     f2, f2, f0
	  fmuls     f1, f1, f1
	  fmuls     f0, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x2E0
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
	  stfs      f0, 0x60(r1)
	  lfs       f2, 0x60(r1)

	.loc_0x2E0:
	  fcmpo     cr0, f2, f28
	  cror      2, 0, 0x2
	  bne-      .loc_0x300
	  fcmpo     cr0, f2, f27
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x300
	  mr        r31, r3
	  fmr       f28, f2

	.loc_0x300:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x31C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x344
	  li        r0, 0x1
	  b         .loc_0x370

	.loc_0x344:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x36C
	  li        r0, 0x1
	  b         .loc_0x370

	.loc_0x36C:
	  li        r0, 0

	.loc_0x370:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x20C
	  cmplwi    r31, 0
	  bne-      .loc_0x3A0
	  lwz       r4, 0x20(r30)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x14(r30)
	  stw       r0, 0x18(r30)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x1C(r30)
	  b         .loc_0x3D8

	.loc_0x3A0:
	  fmr       f27, f28

	.loc_0x3A4:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x40C
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x1E4
	  b         .loc_0x3D8

	.loc_0x3BC:
	  lwz       r4, 0x20(r30)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x14(r30)
	  stw       r0, 0x18(r30)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x1C(r30)

	.loc_0x3D8:
	  lwz       r0, 0x10C(r1)
	  lfd       f31, 0x100(r1)
	  lfd       f30, 0xF8(r1)
	  lfd       f29, 0xF0(r1)
	  lfd       f28, 0xE8(r1)
	  lfd       f27, 0xE0(r1)
	  lwz       r31, 0xDC(r1)
	  lwz       r30, 0xD8(r1)
	  lwz       r29, 0xD4(r1)
	  lwz       r28, 0xD0(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr

	.loc_0x40C:
	*/
}

/*
 * --INFO--
 * Address:	800C03B4
 * Size:	000340
 */
bool ActPutItem::findAdjacent(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x148(r1)
	  stfd      f31, 0x140(r1)
	  stfd      f30, 0x138(r1)
	  stfd      f29, 0x130(r1)
	  stfd      f28, 0x128(r1)
	  stfd      f27, 0x120(r1)
	  stfd      f26, 0x118(r1)
	  stfd      f25, 0x110(r1)
	  stfd      f24, 0x108(r1)
	  stfd      f23, 0x100(r1)
	  stfd      f22, 0xF8(r1)
	  stfd      f21, 0xF0(r1)
	  stfd      f20, 0xE8(r1)
	  stfd      f19, 0xE0(r1)
	  stmw      r25, 0xC4(r1)
	  mr        r31, r3
	  addi      r25, r4, 0
	  lwz       r5, 0x20(r3)
	  lwz       r12, 0x0(r5)
	  addi      r3, r5, 0
	  lfs       f26, 0x94(r5)
	  lwz       r12, 0x3C(r12)
	  lfs       f25, 0x98(r5)
	  mtlr      r12
	  lfs       f24, 0x9C(r5)
	  blrl
	  mr        r3, r25
	  fmr       f19, f1
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x6BB8(r2)
	  fadds     f1, f1, f19
	  lfs       f27, -0x6BF0(r2)
	  li        r27, 0
	  lis       r30, 0x4330
	  stfs      f27, 0xA4(r1)
	  fmuls     f20, f0, f1
	  stfs      f27, 0xA0(r1)
	  stfs      f27, 0x9C(r1)
	  lfd       f30, -0x6BD8(r2)
	  lfd       f31, -0x6BD0(r2)
	  lfs       f28, -0x6BB4(r2)
	  lfd       f29, -0x6BB0(r2)

	.loc_0xBC:
	  xoris     r0, r27, 0x8000
	  stw       r0, 0xBC(r1)
	  stw       r30, 0xB8(r1)
	  lfd       f0, 0xB8(r1)
	  fsubs     f0, f0, f29
	  fmuls     f21, f28, f0
	  fmr       f1, f21
	  bl        0x15B6C8
	  fmr       f19, f1
	  fmr       f1, f21
	  bl        0x15B850
	  fmuls     f2, f1, f20
	  lfs       f1, -0x4664(r13)
	  fmuls     f0, f19, f20
	  li        r26, 0
	  fmuls     f1, f1, f20
	  fadds     f2, f26, f2
	  fadds     f1, f25, f1
	  fadds     f0, f24, f0
	  stfs      f2, 0x9C(r1)
	  stfs      f1, 0xA0(r1)
	  stfs      f0, 0xA4(r1)
	  lwz       r29, 0x30AC(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f23, 0xA4(r1)
	  mr        r28, r3
	  lfs       f22, 0xA0(r1)
	  b         .loc_0x264

	.loc_0x13C:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x160
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x178

	.loc_0x160:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x178:
	  lfs       f2, 0x98(r3)
	  mr        r25, r3
	  lfs       f1, 0x94(r3)
	  lfs       f0, 0x9C(r1)
	  fsubs     f3, f2, f22
	  lfs       f2, 0x9C(r3)
	  fsubs     f1, f1, f0
	  fsubs     f2, f2, f23
	  fmuls     f0, f3, f3
	  fmuls     f1, f1, f1
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f21, f2, f0
	  fcmpo     cr0, f21, f27
	  ble-      .loc_0x204
	  fsqrte    f1, f21
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f21, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f21, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f21, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f21, f0
	  frsp      f0, f0
	  stfs      f0, 0x44(r1)
	  lfs       f21, 0x44(r1)

	.loc_0x204:
	  lwz       r3, 0x20(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r25
	  fmr       f19, f1
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f1, f19
	  fcmpo     cr0, f21, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x248
	  li        r26, 0x1
	  b         .loc_0x2C0

	.loc_0x248:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x264:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x28C
	  li        r0, 0x1
	  b         .loc_0x2B8

	.loc_0x28C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2B4
	  li        r0, 0x1
	  b         .loc_0x2B8

	.loc_0x2B4:
	  li        r0, 0

	.loc_0x2B8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x13C

	.loc_0x2C0:
	  rlwinm.   r0,r26,0,24,31
	  bne-      .loc_0x2E8
	  lwz       r4, 0x9C(r1)
	  li        r3, 0x1
	  lwz       r0, 0xA0(r1)
	  stw       r4, 0x14(r31)
	  stw       r0, 0x18(r31)
	  lwz       r0, 0xA4(r1)
	  stw       r0, 0x1C(r31)
	  b         .loc_0x2F8

	.loc_0x2E8:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x8
	  blt+      .loc_0xBC
	  li        r3, 0

	.loc_0x2F8:
	  lmw       r25, 0xC4(r1)
	  lwz       r0, 0x14C(r1)
	  lfd       f31, 0x140(r1)
	  lfd       f30, 0x138(r1)
	  lfd       f29, 0x130(r1)
	  lfd       f28, 0x128(r1)
	  lfd       f27, 0x120(r1)
	  lfd       f26, 0x118(r1)
	  lfd       f25, 0x110(r1)
	  lfd       f24, 0x108(r1)
	  lfd       f23, 0x100(r1)
	  lfd       f22, 0xF8(r1)
	  lfd       f21, 0xF0(r1)
	  lfd       f20, 0xE8(r1)
	  lfd       f19, 0xE0(r1)
	  addi      r1, r1, 0x148
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C06F4
 * Size:	00006C
 */
void ActPutItem::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x20(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  beq-      .loc_0x38
	  bl        0x23C4C
	  li        r0, 0
	  stw       r0, 0x20(r30)

	.loc_0x38:
	  stw       r31, 0x20(r30)
	  lwz       r3, 0x20(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  bl        0x23C20

	.loc_0x4C:
	  mr        r3, r30
	  bl        -0x79C
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
 * Address:	800C0760
 * Size:	000178
 */
int ActPutItem::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  lwz       r3, 0xC(r3)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x14(r31)
	  lfs       f3, 0x18(r31)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x1C(r31)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x4C(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x50(r1)
	  stfs      f0, 0x54(r1)
	  lfs       f1, 0x4C(r1)
	  lfs       f0, 0x50(r1)
	  lfs       f2, 0x54(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xB2B8C
	  fmr       f31, f1
	  lfs       f0, -0x6BF0(r2)
	  fcmpu     cr0, f0, f31
	  beq-      .loc_0xA4
	  lfs       f0, 0x4C(r1)
	  fdivs     f0, f0, f31
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x50(r1)
	  fdivs     f0, f0, f31
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x54(r1)
	  fdivs     f0, f0, f31
	  stfs      f0, 0x54(r1)

	.loc_0xA4:
	  lwz       r3, 0x20(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  cror      2, 0, 0x2
	  bne-      .loc_0x14C
	  lwz       r5, 0xC(r31)
	  lis       r3, 0x802B
	  lfs       f0, -0x4660(r13)
	  subi      r0, r3, 0x2E74
	  addi      r6, r5, 0xA4
	  stfs      f0, 0xA4(r5)
	  lis       r4, 0x802B
	  subi      r5, r4, 0x3064
	  lfs       f0, -0x465C(r13)
	  addi      r4, r1, 0x3C
	  stfs      f0, 0x4(r6)
	  lfs       f0, -0x4658(r13)
	  stfs      f0, 0x8(r6)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4654(r13)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x4650(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x464C(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x6BE0(r2)
	  stw       r5, 0x3C(r1)
	  stw       r3, 0x40(r1)
	  stw       r0, 0x3C(r1)
	  stfs      f0, 0x44(r1)
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x2AC(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x2
	  b         .loc_0x160

	.loc_0x14C:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x4C
	  lfs       f1, -0x6BDC(r2)
	  bl        0xB520
	  li        r3, 0

	.loc_0x160:
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C08D8
 * Size:	000040
 */
void ActPutItem::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x20(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C
	  bl        0x23A74
	  li        r0, 0
	  stw       r0, 0x20(r31)

	.loc_0x2C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C0918
 * Size:	000064
 */
ActPutItem::~ActPutItem()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x48
	  lis       r3, 0x802B
	  addi      r0, r3, 0x7534
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x34BC
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x797B0

	.loc_0x48:
	  mr        r3, r30
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
 * Address:	800C097C
 * Size:	000080
 */
ActPutBomb::~ActPutBomb()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x64
	  lis       r3, 0x802B
	  addi      r3, r3, 0x75D4
	  stw       r3, 0x0(r30)
	  addi      r6, r3, 0x68
	  addi      r0, r30, 0x28
	  lwz       r5, 0x14(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  stw       r6, 0x0(r5)
	  lwz       r5, 0x14(r30)
	  sub       r0, r0, r5
	  stw       r0, 0x4(r5)
	  bl        0x343C
	  extsh.    r0, r31
	  ble-      .loc_0x64
	  mr        r3, r30
	  bl        -0x79830

	.loc_0x64:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
