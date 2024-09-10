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
 * Address:	80082818
 * Size:	0006D8
 */
void Navi::demoCheck()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x24E0
	  stwu      r1, -0x170(r1)
	  stfd      f31, 0x168(r1)
	  stfd      f30, 0x160(r1)
	  stfd      f29, 0x158(r1)
	  stfd      f28, 0x150(r1)
	  stfd      f27, 0x148(r1)
	  stmw      r27, 0x134(r1)
	  mr        r31, r3
	  lwz       r4, 0xA8(r4)
	  lwz       r3, 0x2F6C(r13)
	  lhz       r30, 0x26(r4)
	  bl        -0x23E0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x84
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x10
	  addi      r3, r3, 0x54
	  bl        -0x3A8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x84
	  cmpwi     r30, 0x1
	  bgt-      .loc_0x84
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x10
	  li        r5, 0
	  addi      r3, r3, 0x54
	  bl        -0x374
	  li        r3, 0x1
	  b         .loc_0x6B0

	.loc_0x84:
	  cmpwi     r30, 0
	  bne-      .loc_0xF4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0
	  addi      r3, r3, 0x54
	  bl        -0x3EC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xF4
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0x1
	  bl        0x700F4
	  mr.       r28, r3
	  beq-      .loc_0xF4
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        0xA5A4
	  lwz       r3, 0x2F70(r13)
	  lfs       f0, 0x30(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xF4
	  lwz       r3, 0x2F6C(r13)
	  addi      r5, r28, 0
	  li        r4, 0
	  addi      r3, r3, 0x54
	  bl        -0x3E4
	  li        r3, 0x1
	  b         .loc_0x6B0

	.loc_0xF4:
	  cmpwi     r30, 0x2
	  bne-      .loc_0x17C
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2
	  addi      r3, r3, 0x54
	  bl        -0x45C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x17C
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0
	  bl        0x70084
	  mr.       r28, r3
	  beq-      .loc_0x17C
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        0xA534
	  lwz       r3, 0x2F70(r13)
	  lfs       f0, 0x30(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x17C
	  lwz       r3, 0x2F6C(r13)
	  addi      r5, r28, 0
	  li        r4, 0x2
	  addi      r3, r3, 0x54
	  bl        -0x454
	  mr        r3, r28
	  lfs       f1, -0x75F8(r2)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x6B0

	.loc_0x17C:
	  cmpwi     r30, 0x1
	  bne-      .loc_0x204
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1
	  addi      r3, r3, 0x54
	  bl        -0x4E4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x204
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0x2
	  bl        0x6FFFC
	  mr.       r28, r3
	  beq-      .loc_0x204
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        0xA4AC
	  lwz       r3, 0x2F70(r13)
	  lfs       f0, 0x30(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x204
	  lwz       r3, 0x2F6C(r13)
	  addi      r5, r28, 0
	  li        r4, 0x1
	  addi      r3, r3, 0x54
	  bl        -0x4DC
	  mr        r3, r28
	  lfs       f1, -0x75F8(r2)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x6B0

	.loc_0x204:
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x3
	  addi      r3, r3, 0x54
	  bl        -0x564
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2D8
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x25C4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2D8
	  lwz       r3, 0x30AC(r13)
	  addi      r4, r31, 0x94
	  li        r5, 0
	  lwz       r3, 0x64(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  mr.       r28, r3
	  beq-      .loc_0x2D8
	  lwz       r0, 0x28C(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x2D8
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x6
	  bne-      .loc_0x2D8
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        0xA3DC
	  lwz       r3, 0x2F70(r13)
	  lfs       f0, 0x40(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x2D8
	  lwz       r3, 0x2F6C(r13)
	  addi      r5, r28, 0
	  li        r4, 0x3
	  addi      r3, r3, 0x54
	  bl        -0x5AC
	  lwz       r6, 0x2F70(r13)
	  mr        r5, r28
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x7
	  lfs       f1, 0x50(r6)
	  addi      r3, r3, 0x54
	  bl        -0x364
	  li        r3, 0x1
	  b         .loc_0x6B0

	.loc_0x2D8:
	  cmpwi     r30, 0
	  bne-      .loc_0x4A4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xC
	  addi      r3, r3, 0x54
	  bl        -0x640
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x4A4
	  lwz       r29, 0x301C(r13)
	  lwz       r4, 0x2F70(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lfs       f28, 0x70(r4)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x75F4(r2)
	  mr        r30, r3
	  lfd       f30, -0x75F0(r2)
	  lfd       f29, -0x75E8(r2)
	  b         .loc_0x448

	.loc_0x32C:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x350
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x368

	.loc_0x350:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x368:
	  lwz       r4, 0x55C(r3)
	  mr        r28, r3
	  lwz       r0, 0x5C(r4)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x42C
	  lfs       f3, 0x9C(r28)
	  lfs       f2, 0x9C(r31)
	  lfs       f1, 0x94(r28)
	  lfs       f0, 0x94(r31)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f27, f1, f0
	  fcmpo     cr0, f27, f31
	  ble-      .loc_0x3F8
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f29, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0xB8(r1)
	  lfs       f27, 0xB8(r1)

	.loc_0x3F8:
	  mr        r3, r28
	  bl        0x13194
	  fsubs     f0, f27, f1
	  fcmpo     cr0, f0, f28
	  cror      2, 0, 0x2
	  bne-      .loc_0x42C
	  lwz       r3, 0x2F6C(r13)
	  addi      r5, r28, 0
	  li        r4, 0xC
	  addi      r3, r3, 0x54
	  bl        -0x71C
	  li        r3, 0x1
	  b         .loc_0x6B0

	.loc_0x42C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x448:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x470
	  li        r0, 0x1
	  b         .loc_0x49C

	.loc_0x470:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x498
	  li        r0, 0x1
	  b         .loc_0x49C

	.loc_0x498:
	  li        r0, 0

	.loc_0x49C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x32C

	.loc_0x4A4:
	  lwz       r30, 0x301C(r13)
	  lwz       r4, 0x2F70(r13)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lfs       f28, 0x70(r4)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f29, -0x75F4(r2)
	  mr        r28, r3
	  lfd       f30, -0x75F0(r2)
	  lfd       f31, -0x75E8(r2)
	  b         .loc_0x650

	.loc_0x4D8:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x4FC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x514

	.loc_0x4FC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x514:
	  lwz       r4, 0x55C(r3)
	  mr        r27, r3
	  lwz       r0, 0x5C(r4)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x634
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x114(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x634
	  lfs       f3, 0x9C(r27)
	  lfs       f2, 0x9C(r31)
	  lfs       f1, 0x94(r27)
	  lfs       f0, 0x94(r31)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f27, f1, f0
	  fcmpo     cr0, f27, f29
	  ble-      .loc_0x5C0
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f27, 0xA8(r1)

	.loc_0x5C0:
	  mr        r3, r27
	  bl        0x12FCC
	  fsubs     f0, f27, f1
	  fcmpo     cr0, f0, f28
	  cror      2, 0, 0x2
	  bne-      .loc_0x634
	  lwz       r3, 0x55C(r27)
	  lwz       r3, 0x2C(r3)
	  bl        0x11D1C
	  lwz       r5, 0x2F6C(r13)
	  addi      r29, r3, 0
	  addi      r4, r29, 0x20
	  addi      r3, r5, 0x54
	  bl        -0x948
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x634
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0x3
	  sth       r0, 0x1E2(r3)
	  extsh     r0, r29
	  addi      r5, r27, 0
	  sth       r0, 0x1E0(r3)
	  addi      r4, r29, 0x20
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x54
	  bl        -0x924
	  li        r3, 0x1
	  b         .loc_0x6B0

	.loc_0x634:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x650:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x678
	  li        r0, 0x1
	  b         .loc_0x6A4

	.loc_0x678:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x6A0
	  li        r0, 0x1
	  b         .loc_0x6A4

	.loc_0x6A0:
	  li        r0, 0

	.loc_0x6A4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x4D8
	  li        r3, 0

	.loc_0x6B0:
	  lmw       r27, 0x134(r1)
	  lwz       r0, 0x174(r1)
	  lfd       f31, 0x168(r1)
	  lfd       f30, 0x160(r1)
	  lfd       f29, 0x158(r1)
	  lfd       f28, 0x150(r1)
	  lfd       f27, 0x148(r1)
	  addi      r1, r1, 0x170
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80082EF0
 * Size:	00024C
 */
void Piki::demoCheck()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB0(r1)
	  stfd      f31, 0xA8(r1)
	  stfd      f30, 0xA0(r1)
	  stfd      f29, 0x98(r1)
	  stfd      f28, 0x90(r1)
	  stfd      f27, 0x88(r1)
	  stw       r31, 0x84(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x40C
	  stw       r30, 0x80(r1)
	  stw       r29, 0x7C(r1)
	  stw       r28, 0x78(r1)
	  bl        0x22530
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x218
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r3, 0xA8(r3)
	  lhz       r0, 0x26(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x218
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xC
	  addi      r3, r3, 0x54
	  bl        -0xA94
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x218
	  lwz       r30, 0x301C(r13)
	  lwz       r4, 0x2F70(r13)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lfs       f28, 0x70(r4)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f29, -0x75F4(r2)
	  mr        r29, r3
	  lfd       f30, -0x75F0(r2)
	  lfd       f31, -0x75E8(r2)
	  b         .loc_0x1BC

	.loc_0xA8:
	  cmpwi     r29, -0x1
	  bne-      .loc_0xCC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE4

	.loc_0xCC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xE4:
	  lwz       r4, 0x55C(r3)
	  mr        r28, r3
	  lwz       r0, 0x5C(r4)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x1A0
	  lfs       f3, 0x9C(r28)
	  lfs       f2, 0x9C(r31)
	  lfs       f1, 0x94(r28)
	  lfs       f0, 0x94(r31)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f27, f1, f0
	  fcmpo     cr0, f27, f29
	  ble-      .loc_0x174
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0x44(r1)
	  lfs       f27, 0x44(r1)

	.loc_0x174:
	  mr        r3, r28
	  bl        0x12D40
	  fsubs     f0, f27, f1
	  fcmpo     cr0, f0, f28
	  cror      2, 0, 0x2
	  bne-      .loc_0x1A0
	  lwz       r3, 0x2F6C(r13)
	  addi      r5, r28, 0
	  li        r4, 0xC
	  addi      r3, r3, 0x54
	  bl        -0xB70

	.loc_0x1A0:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x1BC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1E4
	  li        r0, 0x1
	  b         .loc_0x210

	.loc_0x1E4:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x20C
	  li        r0, 0x1
	  b         .loc_0x210

	.loc_0x20C:
	  li        r0, 0

	.loc_0x210:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xA8

	.loc_0x218:
	  lwz       r0, 0xB4(r1)
	  lfd       f31, 0xA8(r1)
	  lfd       f30, 0xA0(r1)
	  lfd       f29, 0x98(r1)
	  lfd       f28, 0x90(r1)
	  lfd       f27, 0x88(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  lwz       r29, 0x7C(r1)
	  lwz       r28, 0x78(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}
