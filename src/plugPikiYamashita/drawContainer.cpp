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
 * Address:	801BA600
 * Size:	002CAC
 */
zen::DrawContainer::DrawContainer()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  li        r6, 0x280
	  stwu      r1, -0x570(r1)
	  li        r7, 0x1E0
	  stmw      r15, 0x52C(r1)
	  stw       r3, 0x8(r1)
	  lis       r3, 0x803D
	  addi      r25, r3, 0x2308
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x802E
	  addi      r24, r3, 0x1118
	  addi      r28, r30, 0x4
	  addi      r3, r1, 0x4C8
	  bl        -0x7018
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x4C8
	  addi      r3, r28, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        -0x9C94
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r28)
	  li        r29, 0
	  addi      r3, r30, 0x104
	  stb       r29, 0xEC(r28)
	  li        r4, 0
	  stw       r29, 0xF0(r28)
	  stw       r29, 0xF4(r28)
	  bl        0x5C88
	  stw       r29, 0x194(r30)
	  li        r0, 0x1
	  li        r3, 0x50
	  stw       r29, 0x1A0(r30)
	  stb       r29, 0x1DC(r30)
	  stw       r0, 0x174(r30)
	  stw       r29, 0x178(r30)
	  stw       r29, 0x17C(r30)
	  stw       r29, 0x180(r30)
	  stw       r29, 0x184(r30)
	  stw       r29, 0x188(r30)
	  stw       r29, 0x18C(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0x190(r30)
	  stfs      f0, 0x170(r30)
	  stw       r29, 0x198(r30)
	  stw       r29, 0x19C(r30)
	  stw       r29, 0x1A0(r30)
	  bl        -0x1736D0
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x144
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r30)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0
	  addi      r4, r24, 0x24
	  stw       r29, 0x10(r30)
	  stw       r29, 0xC(r30)
	  stw       r29, 0x8(r30)
	  bl        -0x19583C
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0
	  addi      r4, r24, 0x24
	  bl        -0x179FEC
	  lis       r3, 0x8023
	  subi      r0, r3, 0x714C
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0
	  li        r4, 0x1
	  bl        -0x179D90

	.loc_0x144:
	  lwz       r4, 0x8(r1)
	  li        r3, 0xE4
	  stw       r30, 0x100(r4)
	  lwz       r0, 0x100(r4)
	  stw       r0, 0x104(r4)
	  bl        -0x173754
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x188
	  lfs       f1, -0x47D4(r2)
	  li        r4, 0
	  lfs       f2, -0x47D0(r2)
	  li        r5, 0
	  lfs       f3, -0x47CC(r2)
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        -0xA5F4

	.loc_0x188:
	  lwz       r3, 0x8(r1)
	  addi      r4, r24, 0x34
	  li        r5, 0
	  stw       r26, 0xFC(r3)
	  addi      r3, r3, 0x4
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0x7BA4
	  li        r3, 0x2C
	  bl        -0x1737A8
	  mr.       r29, r3
	  beq-      .loc_0x3D4
	  li        r0, 0xB
	  stw       r0, 0x4(r29)
	  lwz       r0, 0x4(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x1737C4
	  stw       r3, 0x8(r29)
	  lwz       r0, 0x4(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x1737D4
	  stw       r3, 0xC(r29)
	  lwz       r0, 0x4(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x1737E4
	  stw       r3, 0x10(r29)
	  lwz       r0, 0x4(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x1737F4
	  stw       r3, 0x14(r29)
	  lwz       r0, 0x4(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x173804
	  stw       r3, 0x18(r29)
	  lwz       r0, 0x4(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x173814
	  stw       r3, 0x1C(r29)
	  li        r0, -0x1
	  li        r31, 0
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0x20(r29)
	  stfs      f0, 0x24(r29)
	  stw       r0, 0x0(r29)

	.loc_0x238:
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x4BC
	  addi      r4, r13, 0x1A54
	  bl        0x5BD50
	  lbz       r7, 0x4BD(r1)
	  mr        r5, r31
	  lbz       r0, 0x4BC(r1)
	  addi      r3, r1, 0x4BC
	  rlwinm    r7,r7,16,0,15
	  lbz       r4, 0x4BE(r1)
	  rlwimi    r7,r0,24,0,7
	  lbz       r6, 0x4BF(r1)
	  crclr     6, 0x6
	  rlwimi    r7,r4,8,16,23
	  or        r28, r6, r7
	  addi      r4, r13, 0x1A5C
	  bl        0x5BD1C
	  lbz       r0, 0x4BD(r1)
	  mr        r3, r29
	  lbz       r4, 0x4BC(r1)
	  mr        r6, r31
	  rlwinm    r0,r0,16,0,15
	  rlwimi    r0,r4,24,0,7
	  lbz       r5, 0x4BE(r1)
	  lbz       r7, 0x4BF(r1)
	  li        r4, 0x1
	  rlwimi    r0,r5,8,16,23
	  lwz       r30, 0x8(r1)
	  or        r8, r7, r0
	  addi      r7, r28, 0
	  addi      r5, r30, 0x4
	  bl        0x2BCC
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x4BC
	  addi      r4, r13, 0x1A64
	  bl        0x5BCCC
	  lbz       r7, 0x4BD(r1)
	  mr        r5, r31
	  lbz       r0, 0x4BC(r1)
	  addi      r3, r1, 0x4BC
	  rlwinm    r7,r7,16,0,15
	  lbz       r4, 0x4BE(r1)
	  rlwimi    r7,r0,24,0,7
	  lbz       r6, 0x4BF(r1)
	  crclr     6, 0x6
	  rlwimi    r7,r4,8,16,23
	  or        r28, r6, r7
	  addi      r4, r13, 0x1A6C
	  bl        0x5BC98
	  lbz       r7, 0x4BD(r1)
	  mr        r3, r29
	  lbz       r0, 0x4BC(r1)
	  mr        r6, r31
	  rlwinm    r7,r7,16,0,15
	  lbz       r4, 0x4BE(r1)
	  rlwimi    r7,r0,24,0,7
	  lbz       r5, 0x4BF(r1)
	  rlwimi    r7,r4,8,16,23
	  or        r8, r5, r7
	  addi      r7, r28, 0
	  addi      r5, r30, 0x4
	  li        r4, 0
	  bl        0x2B4C
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x4BC
	  addi      r4, r13, 0x1A74
	  bl        0x5BC4C
	  lbz       r7, 0x4BD(r1)
	  mr        r5, r31
	  lbz       r0, 0x4BC(r1)
	  addi      r3, r1, 0x4BC
	  rlwinm    r7,r7,16,0,15
	  lbz       r4, 0x4BE(r1)
	  rlwimi    r7,r0,24,0,7
	  lbz       r6, 0x4BF(r1)
	  crclr     6, 0x6
	  rlwimi    r7,r4,8,16,23
	  or        r28, r6, r7
	  addi      r4, r13, 0x1A7C
	  bl        0x5BC18
	  lbz       r7, 0x4BD(r1)
	  mr        r3, r29
	  lbz       r0, 0x4BC(r1)
	  mr        r6, r31
	  rlwinm    r7,r7,16,0,15
	  lbz       r4, 0x4BE(r1)
	  rlwimi    r7,r0,24,0,7
	  lbz       r5, 0x4BF(r1)
	  rlwimi    r7,r4,8,16,23
	  or        r8, r5, r7
	  addi      r7, r28, 0
	  addi      r5, r30, 0x4
	  li        r4, 0x2
	  bl        0x2ACC
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0xB
	  blt+      .loc_0x238
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        0x2A20

	.loc_0x3D4:
	  lwz       r26, 0x8(r1)
	  li        r3, 0x28
	  stw       r29, 0x1B4(r26)
	  bl        -0x1739DC
	  addi      r31, r3, 0
	  mr.       r28, r31
	  beq-      .loc_0x598
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  lis       r4, 0x7061
	  addi      r4, r4, 0x6C6C
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lfs       f1, -0x47D8(r2)
	  addi      r4, r1, 0x31C
	  lis       r29, 0x4330
	  stfs      f1, 0xC(r31)
	  fmr       f0, f1
	  mr        r5, r4
	  stfs      f1, 0x8(r31)
	  mr        r6, r4
	  stfs      f1, 0x4(r31)
	  stfs      f1, 0x18(r31)
	  stfs      f1, 0x14(r31)
	  stfs      f1, 0x10(r31)
	  stfs      f0, 0x24(r31)
	  stfs      f0, 0x20(r31)
	  stfs      f0, 0x1C(r31)
	  stw       r3, 0x0(r31)
	  lwz       r3, 0x0(r31)
	  lfd       f2, -0x47A8(r2)
	  lha       r0, 0x18(r3)
	  lha       r3, 0x1A(r3)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x524(r1)
	  xoris     r0, r3, 0x8000
	  stw       r29, 0x520(r1)
	  stw       r0, 0x51C(r1)
	  lfd       f0, 0x520(r1)
	  stw       r29, 0x518(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x518(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x4(r31)
	  stfs      f0, 0x8(r31)
	  lfs       f0, 0x1A48(r13)
	  stfs      f0, 0xC(r31)
	  lfs       f0, -0x47D0(r2)
	  stfs      f0, 0x31C(r1)
	  lwz       r3, 0x0(r31)
	  addi      r3, r3, 0xC0
	  bl        -0x15D41C
	  lfs       f2, -0x47C8(r2)
	  lfs       f1, 0x4(r28)
	  lfs       f0, 0x8(r28)
	  fadds     f1, f2, f1
	  lwz       r3, 0x0(r28)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  fctiwz    f1, f1
	  stfd      f0, 0x508(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f1, 0x510(r1)
	  mtlr      r12
	  lwz       r5, 0x50C(r1)
	  lwz       r4, 0x514(r1)
	  blrl
	  lwz       r3, 0x0(r31)
	  addi      r3, r3, 0x18
	  bl        -0x25BC
	  lwz       r4, 0x0(r31)
	  addi      r17, r3, 0
	  addi      r3, r4, 0x18
	  bl        -0x25DC
	  srawi     r0, r3, 0x1
	  lwz       r3, 0x0(r31)
	  extsh     r4, r0
	  srawi     r0, r17, 0x4
	  sth       r4, 0xB8(r3)
	  extsh     r0, r0
	  sth       r0, 0xBA(r3)
	  li        r4, 0x7A
	  lwz       r3, 0x0(r28)
	  lfs       f1, -0x47D8(r2)
	  bl        -0x34320
	  lwz       r4, 0x0(r31)
	  lfd       f2, -0x47A8(r2)
	  lha       r3, 0x1A(r4)
	  lha       r0, 0x18(r4)
	  xoris     r3, r3, 0x8000
	  lfs       f3, 0x1A4C(r13)
	  stw       r3, 0x504(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x4FC(r1)
	  stw       r29, 0x500(r1)
	  stw       r29, 0x4F8(r1)
	  lfd       f1, 0x500(r1)
	  lfd       f0, 0x4F8(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fadds     f1, f3, f1
	  stfs      f0, 0x10(r31)
	  stfs      f1, 0x14(r31)
	  lfs       f0, 0x1A38(r13)
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x1A3C(r13)
	  stfs      f0, 0x1C(r31)
	  lfs       f0, 0x1A40(r13)
	  stfs      f0, 0x20(r31)
	  lfs       f0, 0x1A44(r13)
	  stfs      f0, 0x24(r31)

	.loc_0x598:
	  lwz       r29, 0x8(r1)
	  lis       r3, 0x6D61
	  addi      r4, r3, 0x7275
	  stw       r31, 0x1A4(r29)
	  addi      r3, r29, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x1A8(r29)
	  lis       r4, 0x6375
	  li        r3, 0x1
	  lwz       r6, 0x1A8(r29)
	  li        r26, 0
	  lis       r0, 0x4330
	  lbz       r5, 0xC(r6)
	  rlwimi    r5,r3,7,24,24
	  addi      r3, r29, 0x4
	  stb       r5, 0xC(r6)
	  addi      r4, r4, 0x5F6C
	  li        r5, 0x1
	  lwz       r6, 0x1A8(r29)
	  stb       r26, 0xF0(r6)
	  lfs       f1, -0x47C4(r2)
	  lwz       r6, 0x1A8(r29)
	  fmr       f0, f1
	  stfs      f1, 0xC0(r6)
	  stfs      f1, 0xC4(r6)
	  stfs      f0, 0xC8(r6)
	  lwz       r6, 0x1A8(r29)
	  lfd       f1, -0x47A8(r2)
	  lha       r6, 0x18(r6)
	  xoris     r6, r6, 0x8000
	  stw       r6, 0x4FC(r1)
	  stw       r0, 0x4F8(r1)
	  lfd       f0, 0x4F8(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x1AC(r29)
	  lwz       r6, 0x1A8(r29)
	  lha       r6, 0x1A(r6)
	  xoris     r6, r6, 0x8000
	  stw       r6, 0x504(r1)
	  stw       r0, 0x500(r1)
	  lfd       f0, 0x500(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x1B0(r29)
	  lwz       r6, 0x1A8(r29)
	  lha       r7, 0x18(r6)
	  lha       r0, 0x1C(r6)
	  lha       r8, 0x1A(r6)
	  sub       r7, r0, r7
	  lha       r0, 0x1E(r6)
	  srawi     r7, r7, 0x1
	  sub       r0, r0, r8
	  extsh     r7, r7
	  srawi     r0, r0, 0x1
	  sth       r7, 0xB8(r6)
	  extsh     r0, r0
	  sth       r0, 0xBA(r6)
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r3, 0
	  li        r3, 0x1C
	  bl        -0x173C9C
	  addi      r31, r3, 0
	  mr.       r28, r31
	  beq-      .loc_0x7B0
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r31)
	  addi      r4, r30, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xA5C8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r31)
	  addi      r3, r28, 0x4
	  bl        0x4A14
	  addi      r0, r29, 0x198
	  stw       r0, 0x4(r31)
	  li        r0, 0x64
	  lis       r3, 0x802D
	  stw       r0, 0x8(r31)
	  addi      r0, r3, 0x2FE4
	  stw       r0, 0x0(r31)
	  stb       r26, 0x18(r31)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r31)
	  stw       r26, 0x14(r31)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r31)
	  lbz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x754
	  addi      r3, r28, 0x4
	  bl        -0x3C2D0
	  lbz       r0, 0xF1(r30)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x780
	  stw       r0, 0xEC(r30)
	  b         .loc_0x780

	.loc_0x754:
	  addi      r3, r28, 0x4
	  bl        -0x3C300
	  lbz       r0, 0xF1(r30)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x780
	  stw       r0, 0xEC(r30)

	.loc_0x780:
	  lha       r5, 0x1A(r30)
	  lha       r4, 0x1E(r30)
	  lha       r3, 0x18(r30)
	  lha       r0, 0x1C(r30)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r30)
	  extsh     r0, r4
	  sth       r0, 0xBA(r30)

	.loc_0x7B0:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0xA71C
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x6375
	  addi      r4, r3, 0x5F63
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x173DE4
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x8FC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xA710
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x48CC
	  addi      r0, r26, 0x198
	  stw       r0, 0x4(r30)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r30)
	  stb       r4, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r30)
	  stw       r4, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x8A0
	  addi      r3, r28, 0x4
	  bl        -0x3C41C
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x8CC
	  stw       r0, 0xEC(r29)
	  b         .loc_0x8CC

	.loc_0x8A0:
	  addi      r3, r28, 0x4
	  bl        -0x3C44C
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x8CC
	  stw       r0, 0xEC(r29)

	.loc_0x8CC:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0x8FC:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xA868
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x6375
	  addi      r4, r3, 0x5F72
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x173F30
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0xA48
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xA85C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x4780
	  addi      r0, r26, 0x198
	  stw       r0, 0x4(r30)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r30)
	  stb       r4, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r30)
	  stw       r4, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x9EC
	  addi      r3, r28, 0x4
	  bl        -0x3C568
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xA18
	  stw       r0, 0xEC(r29)
	  b         .loc_0xA18

	.loc_0x9EC:
	  addi      r3, r28, 0x4
	  bl        -0x3C598
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xA18
	  stw       r0, 0xEC(r29)

	.loc_0xA18:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0xA48:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xA9B4
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x6375
	  addi      r4, r3, 0x736C
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x17407C
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0xB98
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xA9A8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x4634
	  addi      r0, r26, 0x198
	  stw       r0, 0x4(r30)
	  li        r0, 0x64
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r3, 0x1
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  stb       r3, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x10(r30)
	  stw       r0, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xB3C
	  addi      r3, r28, 0x4
	  bl        -0x3C6B8
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xB68
	  stw       r0, 0xEC(r29)
	  b         .loc_0xB68

	.loc_0xB3C:
	  addi      r3, r28, 0x4
	  bl        -0x3C6E8
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xB68
	  stw       r0, 0xEC(r29)

	.loc_0xB68:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0xB98:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xAB04
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x6375
	  addi      r4, r3, 0x7363
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x1741CC
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0xCE8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xAAF8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x44E4
	  addi      r0, r26, 0x198
	  stw       r0, 0x4(r30)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r3, 0x1
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  stb       r3, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x10(r30)
	  stw       r0, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xC8C
	  addi      r3, r28, 0x4
	  bl        -0x3C808
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xCB8
	  stw       r0, 0xEC(r29)
	  b         .loc_0xCB8

	.loc_0xC8C:
	  addi      r3, r28, 0x4
	  bl        -0x3C838
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xCB8
	  stw       r0, 0xEC(r29)

	.loc_0xCB8:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0xCE8:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xAC54
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x6375
	  addi      r4, r3, 0x7372
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x17431C
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0xE34
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xAC48
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x4394
	  addi      r0, r26, 0x198
	  stw       r0, 0x4(r30)
	  li        r4, 0x1
	  lis       r3, 0x802D
	  stw       r4, 0x8(r30)
	  addi      r3, r3, 0x2FE4
	  li        r0, 0
	  stw       r3, 0x0(r30)
	  stb       r4, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x10(r30)
	  stw       r0, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xDD8
	  addi      r3, r28, 0x4
	  bl        -0x3C954
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xE04
	  stw       r0, 0xEC(r29)
	  b         .loc_0xE04

	.loc_0xDD8:
	  addi      r3, r28, 0x4
	  bl        -0x3C984
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xE04
	  stw       r0, 0xEC(r29)

	.loc_0xE04:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0xE34:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xADA0
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x636C
	  addi      r4, r3, 0x5F6C
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x174468
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0xF80
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xAD94
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x4248
	  addi      r0, r26, 0x19C
	  stw       r0, 0x4(r30)
	  li        r0, 0x64
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r30)
	  stb       r4, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r30)
	  stw       r4, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xF24
	  addi      r3, r28, 0x4
	  bl        -0x3CAA0
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xF50
	  stw       r0, 0xEC(r29)
	  b         .loc_0xF50

	.loc_0xF24:
	  addi      r3, r28, 0x4
	  bl        -0x3CAD0
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xF50
	  stw       r0, 0xEC(r29)

	.loc_0xF50:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0xF80:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xAEEC
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x636C
	  addi      r4, r3, 0x5F63
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x1745B4
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x10CC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xAEE0
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x40FC
	  addi      r0, r26, 0x19C
	  stw       r0, 0x4(r30)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r30)
	  stb       r4, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r30)
	  stw       r4, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x1070
	  addi      r3, r28, 0x4
	  bl        -0x3CBEC
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x109C
	  stw       r0, 0xEC(r29)
	  b         .loc_0x109C

	.loc_0x1070:
	  addi      r3, r28, 0x4
	  bl        -0x3CC1C
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x109C
	  stw       r0, 0xEC(r29)

	.loc_0x109C:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0x10CC:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xB038
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x636C
	  addi      r4, r3, 0x5F72
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x174700
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x1218
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xB02C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x3FB0
	  addi      r0, r26, 0x19C
	  stw       r0, 0x4(r30)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r30)
	  stb       r4, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r30)
	  stw       r4, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x11BC
	  addi      r3, r28, 0x4
	  bl        -0x3CD38
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x11E8
	  stw       r0, 0xEC(r29)
	  b         .loc_0x11E8

	.loc_0x11BC:
	  addi      r3, r28, 0x4
	  bl        -0x3CD68
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x11E8
	  stw       r0, 0xEC(r29)

	.loc_0x11E8:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0x1218:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xB184
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x636C
	  addi      r4, r3, 0x736C
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x17484C
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x1368
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xB178
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x3E64
	  addi      r0, r26, 0x19C
	  stw       r0, 0x4(r30)
	  li        r0, 0x64
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r3, 0x1
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  stb       r3, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x10(r30)
	  stw       r0, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x130C
	  addi      r3, r28, 0x4
	  bl        -0x3CE88
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1338
	  stw       r0, 0xEC(r29)
	  b         .loc_0x1338

	.loc_0x130C:
	  addi      r3, r28, 0x4
	  bl        -0x3CEB8
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1338
	  stw       r0, 0xEC(r29)

	.loc_0x1338:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0x1368:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xB2D4
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x636C
	  addi      r4, r3, 0x7363
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x17499C
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x14B8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xB2C8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x3D14
	  addi      r0, r26, 0x19C
	  stw       r0, 0x4(r30)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r3, 0x1
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  stb       r3, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x10(r30)
	  stw       r0, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x145C
	  addi      r3, r28, 0x4
	  bl        -0x3CFD8
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1488
	  stw       r0, 0xEC(r29)
	  b         .loc_0x1488

	.loc_0x145C:
	  addi      r3, r28, 0x4
	  bl        -0x3D008
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1488
	  stw       r0, 0xEC(r29)

	.loc_0x1488:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0x14B8:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xB424
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x636C
	  addi      r4, r3, 0x7372
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x174AEC
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x1604
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xB418
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x3BC4
	  addi      r0, r26, 0x19C
	  stw       r0, 0x4(r30)
	  li        r4, 0x1
	  lis       r3, 0x802D
	  stw       r4, 0x8(r30)
	  addi      r3, r3, 0x2FE4
	  li        r0, 0
	  stw       r3, 0x0(r30)
	  stb       r4, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x10(r30)
	  stw       r0, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x15A8
	  addi      r3, r28, 0x4
	  bl        -0x3D124
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x15D4
	  stw       r0, 0xEC(r29)
	  b         .loc_0x15D4

	.loc_0x15A8:
	  addi      r3, r28, 0x4
	  bl        -0x3D154
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x15D4
	  stw       r0, 0xEC(r29)

	.loc_0x15D4:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0x1604:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xB570
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x6363
	  addi      r4, r3, 0x5F6C
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x174C38
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x1750
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xB564
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x3A78
	  addi      r0, r26, 0x1A0
	  stw       r0, 0x4(r30)
	  li        r0, 0x64
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r30)
	  stb       r4, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r30)
	  stw       r4, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x16F4
	  addi      r3, r28, 0x4
	  bl        -0x3D270
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1720
	  stw       r0, 0xEC(r29)
	  b         .loc_0x1720

	.loc_0x16F4:
	  addi      r3, r28, 0x4
	  bl        -0x3D2A0
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1720
	  stw       r0, 0xEC(r29)

	.loc_0x1720:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0x1750:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xB6BC
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x6363
	  addi      r4, r3, 0x5F63
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x174D84
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x189C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xB6B0
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x392C
	  addi      r0, r26, 0x1A0
	  stw       r0, 0x4(r30)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r30)
	  stb       r4, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r30)
	  stw       r4, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x1840
	  addi      r3, r28, 0x4
	  bl        -0x3D3BC
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x186C
	  stw       r0, 0xEC(r29)
	  b         .loc_0x186C

	.loc_0x1840:
	  addi      r3, r28, 0x4
	  bl        -0x3D3EC
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x186C
	  stw       r0, 0xEC(r29)

	.loc_0x186C:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0x189C:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xB808
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x6363
	  addi      r4, r3, 0x5F72
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x174ED0
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x19E8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xB7FC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x37E0
	  addi      r0, r26, 0x1A0
	  stw       r0, 0x4(r30)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r30)
	  stb       r4, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r30)
	  stw       r4, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x198C
	  addi      r3, r28, 0x4
	  bl        -0x3D508
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x19B8
	  stw       r0, 0xEC(r29)
	  b         .loc_0x19B8

	.loc_0x198C:
	  addi      r3, r28, 0x4
	  bl        -0x3D538
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x19B8
	  stw       r0, 0xEC(r29)

	.loc_0x19B8:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0x19E8:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xB954
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x6363
	  addi      r4, r3, 0x736C
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x17501C
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x1B38
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xB948
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x3694
	  addi      r0, r26, 0x1A0
	  stw       r0, 0x4(r30)
	  li        r0, 0x64
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r3, 0x1
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  stb       r3, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x10(r30)
	  stw       r0, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x1ADC
	  addi      r3, r28, 0x4
	  bl        -0x3D658
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1B08
	  stw       r0, 0xEC(r29)
	  b         .loc_0x1B08

	.loc_0x1ADC:
	  addi      r3, r28, 0x4
	  bl        -0x3D688
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1B08
	  stw       r0, 0xEC(r29)

	.loc_0x1B08:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0x1B38:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xBAA4
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x6363
	  addi      r4, r3, 0x7363
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x17516C
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x1C88
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xBA98
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x3544
	  addi      r0, r26, 0x1A0
	  stw       r0, 0x4(r30)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x2FE4
	  li        r3, 0x1
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  stb       r3, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x10(r30)
	  stw       r0, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C2C
	  addi      r3, r28, 0x4
	  bl        -0x3D7A8
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1C58
	  stw       r0, 0xEC(r29)
	  b         .loc_0x1C58

	.loc_0x1C2C:
	  addi      r3, r28, 0x4
	  bl        -0x3D7D8
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1C58
	  stw       r0, 0xEC(r29)

	.loc_0x1C58:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0x1C88:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xBBF4
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x6363
	  addi      r4, r3, 0x7372
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  li        r3, 0x1C
	  bl        -0x1752BC
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x1DD4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xBBE8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0x4
	  bl        0x33F4
	  addi      r0, r26, 0x1A0
	  stw       r0, 0x4(r30)
	  li        r4, 0x1
	  lis       r3, 0x802D
	  stw       r4, 0x8(r30)
	  addi      r3, r3, 0x2FE4
	  li        r0, 0
	  stw       r3, 0x0(r30)
	  stb       r4, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x10(r30)
	  stw       r0, 0x14(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x1D78
	  addi      r3, r28, 0x4
	  bl        -0x3D8F4
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1DA4
	  stw       r0, 0xEC(r29)
	  b         .loc_0x1DA4

	.loc_0x1D78:
	  addi      r3, r28, 0x4
	  bl        -0x3D924
	  lbz       r0, 0xF1(r29)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1DA4
	  stw       r0, 0xEC(r29)

	.loc_0x1DA4:
	  lha       r5, 0x1A(r29)
	  lha       r4, 0x1E(r29)
	  lha       r3, 0x18(r29)
	  lha       r0, 0x1C(r29)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r29)
	  extsh     r0, r4
	  sth       r0, 0xBA(r29)

	.loc_0x1DD4:
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0xBD40
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x795F
	  addi      r4, r3, 0x635F
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r3, 0
	  li        r3, 0x20
	  bl        -0x175408
	  addi      r29, r3, 0
	  mr.       r28, r29
	  beq-      .loc_0x1EC8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r29)
	  addi      r4, r30, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xBD34
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r29)
	  lis       r3, 0x802E
	  addi      r7, r3, 0x139C
	  stw       r26, 0x4(r29)
	  li        r8, 0x1
	  li        r0, 0x3
	  lfs       f0, -0x47D8(r2)
	  addi      r3, r24, 0x4C
	  li        r4, 0x1
	  stfs      f0, 0x10(r29)
	  li        r5, 0x1
	  lfs       f0, -0x47C0(r2)
	  stfs      f0, 0x14(r29)
	  lha       r6, 0x18(r30)
	  stw       r6, 0x8(r29)
	  lha       r6, 0x1A(r30)
	  stw       r6, 0xC(r29)
	  stb       r8, 0x18(r29)
	  stw       r0, 0x1C(r29)
	  stw       r7, 0x0(r29)
	  bl        0x36150
	  stw       r3, 0x31A8(r13)
	  addi      r3, r24, 0x58
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x3613C
	  stw       r3, 0x31AC(r13)
	  addi      r3, r28, 0x4
	  bl        0xED8
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        0xE04
	  lwz       r0, 0x1C(r29)
	  cmpwi     r0, 0x3

	.loc_0x1EC8:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0xBE34
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x795F
	  addi      r4, r3, 0x6C5F
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r3, 0
	  li        r3, 0x20
	  bl        -0x1754FC
	  mr.       r29, r3
	  beq-      .loc_0x1F90
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r29)
	  addi      r4, r28, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0xBE24
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r29)
	  lis       r3, 0x802E
	  li        r0, 0x1
	  stw       r26, 0x4(r29)
	  li        r5, 0x3
	  addi      r4, r3, 0x134C
	  lfs       f0, -0x47D8(r2)
	  addi      r3, r29, 0x4
	  stfs      f0, 0x10(r29)
	  lfs       f0, -0x47C0(r2)
	  stfs      f0, 0x14(r29)
	  lha       r6, 0x18(r28)
	  stw       r6, 0x8(r29)
	  lha       r6, 0x1A(r28)
	  stw       r6, 0xC(r29)
	  stb       r0, 0x18(r29)
	  stw       r5, 0x1C(r29)
	  stw       r4, 0x0(r29)
	  bl        0xE10
	  lwz       r0, 0x1C(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x1F90
	  li        r0, 0
	  stb       r0, 0xF0(r28)

	.loc_0x1F90:
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        -0xBEFC
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x795F
	  addi      r4, r3, 0x725F
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r3, 0
	  li        r3, 0x20
	  bl        -0x1755C4
	  mr.       r29, r3
	  beq-      .loc_0x2058
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r29)
	  addi      r4, r28, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0xBEEC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r29)
	  lis       r3, 0x802E
	  li        r0, 0x1
	  stw       r26, 0x4(r29)
	  li        r5, 0x3
	  addi      r4, r3, 0x134C
	  lfs       f0, -0x47D8(r2)
	  addi      r3, r29, 0x4
	  stfs      f0, 0x10(r29)
	  lfs       f0, -0x47BC(r2)
	  stfs      f0, 0x14(r29)
	  lha       r6, 0x18(r28)
	  stw       r6, 0x8(r29)
	  lha       r6, 0x1A(r28)
	  stw       r6, 0xC(r29)
	  stb       r0, 0x18(r29)
	  stw       r5, 0x1C(r29)
	  stw       r4, 0x0(r29)
	  bl        0xD48
	  lwz       r0, 0x1C(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x2058
	  li        r0, 0
	  stb       r0, 0xF0(r28)

	.loc_0x2058:
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        -0xBFC4
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x7973
	  addi      r4, r3, 0x635F
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r3, 0
	  li        r3, 0x20
	  bl        -0x17568C
	  addi      r29, r3, 0
	  mr.       r28, r29
	  beq-      .loc_0x214C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r29)
	  addi      r4, r30, 0
	  addi      r3, r28, 0x4
	  li        r5, 0x12
	  bl        -0xBFB8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r29)
	  lis       r3, 0x802E
	  addi      r7, r3, 0x139C
	  stw       r26, 0x4(r29)
	  li        r8, 0x1
	  li        r0, 0x3
	  lfs       f0, -0x47D8(r2)
	  addi      r3, r24, 0x4C
	  li        r4, 0x1
	  stfs      f0, 0x10(r29)
	  li        r5, 0x1
	  lfs       f0, -0x47C0(r2)
	  stfs      f0, 0x14(r29)
	  lha       r6, 0x18(r30)
	  stw       r6, 0x8(r29)
	  lha       r6, 0x1A(r30)
	  stw       r6, 0xC(r29)
	  stb       r8, 0x18(r29)
	  stw       r0, 0x1C(r29)
	  stw       r7, 0x0(r29)
	  bl        0x35ECC
	  stw       r3, 0x31A8(r13)
	  addi      r3, r24, 0x58
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x35EB8
	  stw       r3, 0x31AC(r13)
	  addi      r3, r28, 0x4
	  bl        0xC54
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        0xB80
	  lwz       r0, 0x1C(r29)
	  cmpwi     r0, 0x3

	.loc_0x214C:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0xC0B8
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x7973
	  addi      r4, r3, 0x6C5F
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r3, 0
	  li        r3, 0x20
	  bl        -0x175780
	  mr.       r29, r3
	  beq-      .loc_0x2214
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r29)
	  addi      r4, r28, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0xC0A8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r29)
	  lis       r3, 0x802E
	  li        r0, 0x1
	  stw       r26, 0x4(r29)
	  li        r5, 0x3
	  addi      r4, r3, 0x134C
	  lfs       f0, -0x47D8(r2)
	  addi      r3, r29, 0x4
	  stfs      f0, 0x10(r29)
	  lfs       f0, -0x47C0(r2)
	  stfs      f0, 0x14(r29)
	  lha       r6, 0x18(r28)
	  stw       r6, 0x8(r29)
	  lha       r6, 0x1A(r28)
	  stw       r6, 0xC(r29)
	  stb       r0, 0x18(r29)
	  stw       r5, 0x1C(r29)
	  stw       r4, 0x0(r29)
	  bl        0xB8C
	  lwz       r0, 0x1C(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x2214
	  li        r0, 0
	  stb       r0, 0xF0(r28)

	.loc_0x2214:
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        -0xC180
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x7973
	  addi      r4, r3, 0x725F
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r3, 0
	  li        r3, 0x20
	  bl        -0x175848
	  mr.       r29, r3
	  beq-      .loc_0x22DC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r29)
	  addi      r4, r28, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0xC170
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r29)
	  lis       r3, 0x802E
	  li        r0, 0x1
	  stw       r26, 0x4(r29)
	  li        r5, 0x3
	  addi      r4, r3, 0x134C
	  lfs       f0, -0x47D8(r2)
	  addi      r3, r29, 0x4
	  stfs      f0, 0x10(r29)
	  lfs       f0, -0x47BC(r2)
	  stfs      f0, 0x14(r29)
	  lha       r6, 0x18(r28)
	  stw       r6, 0x8(r29)
	  lha       r6, 0x1A(r28)
	  stw       r6, 0xC(r29)
	  stb       r0, 0x18(r29)
	  stw       r5, 0x1C(r29)
	  stw       r4, 0x0(r29)
	  bl        0xAC4
	  lwz       r0, 0x1C(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x22DC
	  li        r0, 0
	  stb       r0, 0xF0(r28)

	.loc_0x22DC:
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        -0xC248
	  lwz       r26, 0x8(r1)
	  lis       r3, 0x636F
	  addi      r4, r3, 0x6E74
	  addi      r3, r26, 0x4
	  lwz       r12, 0x4(r26)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x4D0(r1)
	  li        r3, 0x18
	  bl        -0x175910
	  mr.       r31, r3
	  beq-      .loc_0x2BD0
	  lis       r3, 0x802D
	  lwz       r4, 0x4D0(r1)
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0x4
	  li        r5, 0x12
	  bl        -0xC238
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  lis       r3, 0x802E
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x12E8
	  stw       r0, 0x0(r31)
	  addi      r29, r25, 0
	  li        r30, 0
	  stw       r26, 0x14(r31)

	.loc_0x2360:
	  addi      r3, r1, 0x394
	  crclr     6, 0x6
	  addi      r4, r24, 0x64
	  addi      r5, r30, 0x1
	  bl        0x59C28
	  addi      r3, r1, 0x394
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x35C60
	  addi      r30, r30, 0x1
	  stw       r3, 0x0(r29)
	  cmpwi     r30, 0x15
	  addi      r29, r29, 0x4
	  blt+      .loc_0x2360
	  li        r3, 0x10
	  bl        -0x175998
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x23F0
	  li        r0, 0
	  stw       r0, 0x0(r28)
	  li        r0, 0x14
	  stw       r0, 0x4(r28)
	  lwz       r26, 0x4(r28)
	  rlwinm    r3,r26,3,0,28
	  addi      r3, r3, 0x8
	  bl        -0x1759C4
	  lis       r4, 0x801C
	  subi      r4, r4, 0x2D54
	  addi      r7, r26, 0
	  li        r5, 0
	  li        r6, 0x8
	  bl        0x58248
	  stw       r3, 0x8(r28)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r28)

	.loc_0x23F0:
	  stw       r28, 0x8(r31)
	  addi      r18, r25, 0x28
	  li        r4, 0
	  lwz       r3, 0x8(r31)
	  lwz       r5, 0x28(r25)
	  lfs       f1, -0x47B8(r2)
	  bl        0x4698
	  addi      r17, r25, 0x24
	  lwz       r3, 0x8(r31)
	  lwz       r5, 0x24(r25)
	  li        r4, 0x1
	  lfs       f1, -0x47B4(r2)
	  bl        0x4680
	  addi      r16, r25, 0x20
	  lwz       r3, 0x8(r31)
	  lwz       r5, 0x20(r25)
	  li        r4, 0x2
	  lfs       f1, -0x47B4(r2)
	  bl        0x4668
	  addi      r15, r25, 0x1C
	  lwz       r3, 0x8(r31)
	  lwz       r5, 0x1C(r25)
	  li        r4, 0x3
	  lfs       f1, -0x47B4(r2)
	  bl        0x4650
	  addi      r0, r25, 0x18
	  lwz       r3, 0x8(r31)
	  stw       r0, 0x4D8(r1)
	  lfs       f1, -0x47B4(r2)
	  lwz       r4, 0x4D8(r1)
	  lwz       r5, 0x0(r4)
	  li        r4, 0x4
	  bl        0x4630
	  addi      r0, r25, 0x14
	  lwz       r3, 0x8(r31)
	  stw       r0, 0x4DC(r1)
	  lfs       f1, -0x47B4(r2)
	  lwz       r4, 0x4DC(r1)
	  lwz       r5, 0x0(r4)
	  li        r4, 0x5
	  bl        0x4610
	  addi      r0, r25, 0x10
	  lwz       r3, 0x8(r31)
	  stw       r0, 0x4E0(r1)
	  lfs       f1, -0x47B4(r2)
	  lwz       r4, 0x4E0(r1)
	  lwz       r5, 0x0(r4)
	  li        r4, 0x6
	  bl        0x45F0
	  addi      r0, r25, 0xC
	  lwz       r3, 0x8(r31)
	  stw       r0, 0x4E4(r1)
	  lfs       f1, -0x47B4(r2)
	  lwz       r4, 0x4E4(r1)
	  lwz       r5, 0x0(r4)
	  li        r4, 0x7
	  bl        0x45D0
	  addi      r0, r25, 0x8
	  lwz       r3, 0x8(r31)
	  stw       r0, 0x4E8(r1)
	  lfs       f1, -0x47B4(r2)
	  lwz       r4, 0x4E8(r1)
	  lwz       r5, 0x0(r4)
	  li        r4, 0x8
	  bl        0x45B0
	  addi      r0, r25, 0x4
	  lwz       r3, 0x8(r31)
	  stw       r0, 0x4EC(r1)
	  lfs       f1, -0x47B4(r2)
	  lwz       r4, 0x4EC(r1)
	  lwz       r5, 0x0(r4)
	  li        r4, 0x9
	  bl        0x4590
	  lwz       r3, 0x8(r31)
	  li        r4, 0xA
	  lwz       r5, 0x0(r25)
	  lfs       f1, -0x47B0(r2)
	  bl        0x457C
	  lwz       r5, 0x4EC(r1)
	  li        r4, 0xB
	  lwz       r3, 0x8(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4564
	  lwz       r5, 0x4E8(r1)
	  li        r4, 0xC
	  lwz       r3, 0x8(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47AC(r2)
	  bl        0x454C
	  lwz       r5, 0x4E4(r1)
	  li        r4, 0xD
	  lwz       r3, 0x8(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4534
	  lwz       r5, 0x4E0(r1)
	  li        r4, 0xE
	  lwz       r3, 0x8(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47AC(r2)
	  bl        0x451C
	  lwz       r5, 0x4DC(r1)
	  li        r4, 0xF
	  lwz       r3, 0x8(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4504
	  lwz       r5, 0x4D8(r1)
	  li        r4, 0x10
	  lwz       r3, 0x8(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47AC(r2)
	  bl        0x44EC
	  lwz       r3, 0x8(r31)
	  li        r4, 0x11
	  lwz       r5, 0x0(r15)
	  lfs       f1, -0x47AC(r2)
	  bl        0x44D8
	  lwz       r3, 0x8(r31)
	  li        r4, 0x12
	  lwz       r5, 0x0(r16)
	  lfs       f1, -0x47AC(r2)
	  bl        0x44C4
	  lwz       r3, 0x8(r31)
	  li        r4, 0x13
	  lwz       r5, 0x0(r17)
	  lfs       f1, -0x47AC(r2)
	  bl        0x44B0
	  li        r3, 0x10
	  bl        -0x175BF4
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x264C
	  li        r0, 0
	  stw       r0, 0x0(r28)
	  li        r0, 0x14
	  stw       r0, 0x4(r28)
	  lwz       r26, 0x4(r28)
	  rlwinm    r3,r26,3,0,28
	  addi      r3, r3, 0x8
	  bl        -0x175C20
	  lis       r4, 0x801C
	  subi      r4, r4, 0x2D54
	  addi      r7, r26, 0
	  li        r5, 0
	  li        r6, 0x8
	  bl        0x57FEC
	  stw       r3, 0x8(r28)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r28)

	.loc_0x264C:
	  stw       r28, 0xC(r31)
	  li        r4, 0
	  lwz       r3, 0xC(r31)
	  lwz       r5, 0x0(r18)
	  lfs       f1, -0x47B8(r2)
	  bl        0x4440
	  addi      r29, r25, 0x2C
	  lwz       r3, 0xC(r31)
	  lwz       r5, 0x2C(r25)
	  li        r4, 0x1
	  lfs       f1, -0x47B4(r2)
	  bl        0x4428
	  addi      r30, r25, 0x30
	  lwz       r3, 0xC(r31)
	  lwz       r5, 0x30(r25)
	  li        r4, 0x2
	  lfs       f1, -0x47B4(r2)
	  bl        0x4410
	  addi      r27, r25, 0x34
	  lwz       r3, 0xC(r31)
	  lwz       r5, 0x34(r25)
	  li        r4, 0x3
	  lfs       f1, -0x47B4(r2)
	  bl        0x43F8
	  addi      r26, r25, 0x38
	  lwz       r3, 0xC(r31)
	  lwz       r5, 0x38(r25)
	  li        r4, 0x4
	  lfs       f1, -0x47B4(r2)
	  bl        0x43E0
	  addi      r23, r25, 0x3C
	  lwz       r3, 0xC(r31)
	  lwz       r5, 0x3C(r25)
	  li        r4, 0x5
	  lfs       f1, -0x47B4(r2)
	  bl        0x43C8
	  addi      r22, r25, 0x40
	  lwz       r3, 0xC(r31)
	  lwz       r5, 0x40(r25)
	  li        r4, 0x6
	  lfs       f1, -0x47B4(r2)
	  bl        0x43B0
	  addi      r21, r25, 0x44
	  lwz       r3, 0xC(r31)
	  lwz       r5, 0x44(r25)
	  li        r4, 0x7
	  lfs       f1, -0x47B4(r2)
	  bl        0x4398
	  addi      r20, r25, 0x48
	  lwz       r3, 0xC(r31)
	  lwz       r5, 0x48(r25)
	  li        r4, 0x8
	  lfs       f1, -0x47B4(r2)
	  bl        0x4380
	  addi      r19, r25, 0x4C
	  lwz       r3, 0xC(r31)
	  lwz       r5, 0x4C(r25)
	  li        r4, 0x9
	  lfs       f1, -0x47B4(r2)
	  bl        0x4368
	  addi      r0, r25, 0x50
	  lwz       r3, 0xC(r31)
	  stw       r0, 0x4D4(r1)
	  lfs       f1, -0x47B0(r2)
	  lwz       r4, 0x4D4(r1)
	  lwz       r5, 0x0(r4)
	  li        r4, 0xA
	  bl        0x4348
	  lwz       r3, 0xC(r31)
	  li        r4, 0xB
	  lwz       r5, 0x0(r19)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4334
	  lwz       r3, 0xC(r31)
	  li        r4, 0xC
	  lwz       r5, 0x0(r20)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4320
	  lwz       r3, 0xC(r31)
	  li        r4, 0xD
	  lwz       r5, 0x0(r21)
	  lfs       f1, -0x47AC(r2)
	  bl        0x430C
	  lwz       r3, 0xC(r31)
	  li        r4, 0xE
	  lwz       r5, 0x0(r22)
	  lfs       f1, -0x47AC(r2)
	  bl        0x42F8
	  lwz       r3, 0xC(r31)
	  li        r4, 0xF
	  lwz       r5, 0x0(r23)
	  lfs       f1, -0x47AC(r2)
	  bl        0x42E4
	  lwz       r3, 0xC(r31)
	  li        r4, 0x10
	  lwz       r5, 0x0(r26)
	  lfs       f1, -0x47AC(r2)
	  bl        0x42D0
	  lwz       r3, 0xC(r31)
	  li        r4, 0x11
	  lwz       r5, 0x0(r27)
	  lfs       f1, -0x47AC(r2)
	  bl        0x42BC
	  lwz       r3, 0xC(r31)
	  li        r4, 0x12
	  lwz       r5, 0x0(r30)
	  lfs       f1, -0x47AC(r2)
	  bl        0x42A8
	  lwz       r3, 0xC(r31)
	  li        r4, 0x13
	  lwz       r5, 0x0(r29)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4294
	  li        r3, 0x10
	  bl        -0x175E10
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x2870
	  li        r0, 0
	  stw       r0, 0x0(r28)
	  li        r0, 0x28
	  stw       r0, 0x4(r28)
	  lwz       r0, 0x4(r28)
	  stw       r0, 0x4F0(r1)
	  lwz       r0, 0x4F0(r1)
	  rlwinm    r3,r0,3,0,28
	  addi      r3, r3, 0x8
	  bl        -0x175E44
	  lis       r4, 0x801C
	  lwz       r7, 0x4F0(r1)
	  subi      r4, r4, 0x2D54
	  li        r5, 0
	  li        r6, 0x8
	  bl        0x57DC8
	  stw       r3, 0x8(r28)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0xC(r28)

	.loc_0x2870:
	  stw       r28, 0x10(r31)
	  li        r4, 0
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r18)
	  lfs       f1, -0x47B0(r2)
	  bl        0x421C
	  lwz       r3, 0x10(r31)
	  li        r4, 0x1
	  lwz       r5, 0x0(r17)
	  lfs       f1, -0x47B4(r2)
	  bl        0x4208
	  lwz       r3, 0x10(r31)
	  li        r4, 0x2
	  lwz       r5, 0x0(r16)
	  lfs       f1, -0x47B4(r2)
	  bl        0x41F4
	  lwz       r3, 0x10(r31)
	  li        r4, 0x3
	  lwz       r5, 0x0(r15)
	  lfs       f1, -0x47B4(r2)
	  bl        0x41E0
	  lwz       r5, 0x4D8(r1)
	  li        r4, 0x4
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47B4(r2)
	  bl        0x41C8
	  lwz       r5, 0x4DC(r1)
	  li        r4, 0x5
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47B4(r2)
	  bl        0x41B0
	  lwz       r5, 0x4E0(r1)
	  li        r4, 0x6
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47B4(r2)
	  bl        0x4198
	  lwz       r5, 0x4E4(r1)
	  li        r4, 0x7
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47B4(r2)
	  bl        0x4180
	  lwz       r5, 0x4E8(r1)
	  li        r4, 0x8
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47B4(r2)
	  bl        0x4168
	  lwz       r5, 0x4EC(r1)
	  li        r4, 0x9
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47B4(r2)
	  bl        0x4150
	  lwz       r3, 0x10(r31)
	  li        r4, 0xA
	  lwz       r5, 0x0(r25)
	  lfs       f1, -0x47B8(r2)
	  bl        0x413C
	  lwz       r5, 0x4EC(r1)
	  li        r4, 0xB
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4124
	  lwz       r5, 0x4E8(r1)
	  li        r4, 0xC
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47AC(r2)
	  bl        0x410C
	  lwz       r5, 0x4E4(r1)
	  li        r4, 0xD
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47AC(r2)
	  bl        0x40F4
	  lwz       r5, 0x4E0(r1)
	  li        r4, 0xE
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47AC(r2)
	  bl        0x40DC
	  lwz       r5, 0x4DC(r1)
	  li        r4, 0xF
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47AC(r2)
	  bl        0x40C4
	  lwz       r5, 0x4D8(r1)
	  li        r4, 0x10
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47AC(r2)
	  bl        0x40AC
	  lwz       r3, 0x10(r31)
	  li        r4, 0x11
	  lwz       r5, 0x0(r15)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4098
	  lwz       r3, 0x10(r31)
	  li        r4, 0x12
	  lwz       r5, 0x0(r16)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4084
	  lwz       r3, 0x10(r31)
	  li        r4, 0x13
	  lwz       r5, 0x0(r17)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4070
	  lwz       r3, 0x10(r31)
	  li        r4, 0x14
	  lwz       r5, 0x0(r18)
	  lfs       f1, -0x47AC(r2)
	  bl        0x405C
	  lwz       r3, 0x10(r31)
	  li        r4, 0x15
	  lwz       r5, 0x0(r29)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4048
	  lwz       r3, 0x10(r31)
	  li        r4, 0x16
	  lwz       r5, 0x0(r30)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4034
	  lwz       r3, 0x10(r31)
	  li        r4, 0x17
	  lwz       r5, 0x0(r27)
	  lfs       f1, -0x47AC(r2)
	  bl        0x4020
	  lwz       r3, 0x10(r31)
	  li        r4, 0x18
	  lwz       r5, 0x0(r26)
	  lfs       f1, -0x47AC(r2)
	  bl        0x400C
	  lwz       r3, 0x10(r31)
	  li        r4, 0x19
	  lwz       r5, 0x0(r23)
	  lfs       f1, -0x47AC(r2)
	  bl        0x3FF8
	  lwz       r3, 0x10(r31)
	  li        r4, 0x1A
	  lwz       r5, 0x0(r22)
	  lfs       f1, -0x47AC(r2)
	  bl        0x3FE4
	  lwz       r3, 0x10(r31)
	  li        r4, 0x1B
	  lwz       r5, 0x0(r21)
	  lfs       f1, -0x47AC(r2)
	  bl        0x3FD0
	  lwz       r3, 0x10(r31)
	  li        r4, 0x1C
	  lwz       r5, 0x0(r20)
	  lfs       f1, -0x47AC(r2)
	  bl        0x3FBC
	  lwz       r3, 0x10(r31)
	  li        r4, 0x1D
	  lwz       r5, 0x0(r19)
	  lfs       f1, -0x47AC(r2)
	  bl        0x3FA8
	  lwz       r5, 0x4D4(r1)
	  li        r4, 0x1E
	  lwz       r3, 0x10(r31)
	  lwz       r5, 0x0(r5)
	  lfs       f1, -0x47B8(r2)
	  bl        0x3F90
	  lwz       r3, 0x10(r31)
	  li        r4, 0x1F
	  lwz       r5, 0x0(r19)
	  lfs       f1, -0x47B4(r2)
	  bl        0x3F7C
	  lwz       r3, 0x10(r31)
	  li        r4, 0x20
	  lwz       r5, 0x0(r20)
	  lfs       f1, -0x47B4(r2)
	  bl        0x3F68
	  lwz       r3, 0x10(r31)
	  li        r4, 0x21
	  lwz       r5, 0x0(r21)
	  lfs       f1, -0x47B4(r2)
	  bl        0x3F54
	  lwz       r3, 0x10(r31)
	  li        r4, 0x22
	  lwz       r5, 0x0(r22)
	  lfs       f1, -0x47B4(r2)
	  bl        0x3F40
	  lwz       r3, 0x10(r31)
	  li        r4, 0x23
	  lwz       r5, 0x0(r23)
	  lfs       f1, -0x47B4(r2)
	  bl        0x3F2C
	  lwz       r3, 0x10(r31)
	  li        r4, 0x24
	  lwz       r5, 0x0(r26)
	  lfs       f1, -0x47B4(r2)
	  bl        0x3F18
	  lwz       r3, 0x10(r31)
	  li        r4, 0x25
	  lwz       r5, 0x0(r27)
	  lfs       f1, -0x47B4(r2)
	  bl        0x3F04
	  lwz       r3, 0x10(r31)
	  li        r4, 0x26
	  lwz       r5, 0x0(r30)
	  lfs       f1, -0x47B4(r2)
	  bl        0x3EF0
	  lwz       r3, 0x10(r31)
	  li        r4, 0x27
	  lwz       r5, 0x0(r29)
	  lfs       f1, -0x47B4(r2)
	  bl        0x3EDC
	  li        r0, 0
	  stw       r0, 0x4(r31)

	.loc_0x2BD0:
	  lwz       r3, 0x4D0(r1)
	  mr        r4, r31
	  bl        -0xCB3C
	  addi      r3, r24, 0x74
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x353F8
	  lwz       r29, 0x8(r1)
	  li        r4, 0x1
	  li        r5, 0x1
	  stw       r3, 0x1B8(r29)
	  addi      r3, r24, 0x8C
	  bl        0x353E0
	  stw       r3, 0x1BC(r29)
	  addi      r3, r24, 0xA4
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x353CC
	  stw       r3, 0x1C0(r29)
	  addi      r3, r24, 0xBC
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x353B8
	  stw       r3, 0x1C4(r29)
	  addi      r3, r24, 0xD4
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x353A4
	  stw       r3, 0x1C8(r29)
	  addi      r3, r24, 0xEC
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x35390
	  stw       r3, 0x1CC(r29)
	  addi      r3, r24, 0x104
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x3537C
	  stw       r3, 0x1D0(r29)
	  addi      r3, r24, 0x11C
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x35368
	  stw       r3, 0x1D4(r29)
	  addi      r3, r24, 0x134
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x35354
	  stw       r3, 0x1D8(r29)
	  mr        r3, r29
	  lmw       r15, 0x52C(r1)
	  lwz       r0, 0x574(r1)
	  addi      r1, r1, 0x570
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BD2AC
 * Size:	000014
 */
zen::TexAnim::AnimData::AnimData()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BD2C0
 * Size:	0000C8
 */
void zen::ArrowCenterCallBack::setTexture(P2DPicture*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x4(r3)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  bne-      .loc_0x60
	  lwz       r0, 0x198(r5)
	  cmpwi     r0, 0
	  ble-      .loc_0x40
	  lwz       r0, 0x19C(r5)
	  cmpwi     r0, 0
	  ble-      .loc_0x34
	  li        r0, 0x2
	  stw       r0, 0x1C(r3)
	  b         .loc_0x60

	.loc_0x34:
	  li        r0, 0x1
	  stw       r0, 0x1C(r3)
	  b         .loc_0x60

	.loc_0x40:
	  lwz       r0, 0x19C(r5)
	  cmpwi     r0, 0
	  ble-      .loc_0x58
	  li        r0, 0
	  stw       r0, 0x1C(r3)
	  b         .loc_0x60

	.loc_0x58:
	  li        r0, 0x3
	  stw       r0, 0x1C(r3)

	.loc_0x60:
	  lwz       r0, 0x1C(r3)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x74
	  cmpwi     r0, 0x2
	  bne-      .loc_0x80

	.loc_0x74:
	  li        r0, 0
	  stb       r0, 0x18(r3)
	  b         .loc_0xC0

	.loc_0x80:
	  li        r0, 0x1
	  stb       r0, 0x18(r3)
	  lwz       r0, 0x1C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xAC
	  lbz       r0, 0xF1(r4)
	  lwz       r5, 0x31A8(r13)
	  cmplwi    r0, 0
	  ble-      .loc_0xC0
	  stw       r5, 0xEC(r4)
	  b         .loc_0xC0

	.loc_0xAC:
	  lbz       r0, 0xF1(r4)
	  lwz       r5, 0x31AC(r13)
	  cmplwi    r0, 0
	  ble-      .loc_0xC0
	  stw       r5, 0xEC(r4)

	.loc_0xC0:
	  lwz       r3, 0x1C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BD388
 * Size:	000068
 */
void zen::ArrowBasicCallBack::judgeArrowType()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x0(r3)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x60
	  lwz       r0, 0x198(r4)
	  cmpwi     r0, 0
	  ble-      .loc_0x40
	  lwz       r0, 0x19C(r4)
	  cmpwi     r0, 0
	  ble-      .loc_0x34
	  li        r0, 0x2
	  stw       r0, 0x18(r3)
	  b         .loc_0x60

	.loc_0x34:
	  li        r0, 0x1
	  stw       r0, 0x18(r3)
	  b         .loc_0x60

	.loc_0x40:
	  lwz       r0, 0x19C(r4)
	  cmpwi     r0, 0
	  ble-      .loc_0x58
	  li        r0, 0
	  stw       r0, 0x18(r3)
	  b         .loc_0x60

	.loc_0x58:
	  li        r0, 0x3
	  stw       r0, 0x18(r3)

	.loc_0x60:
	  lwz       r3, 0x18(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BD3F0
 * Size:	000094
 */
void zen::MessageMgr::init(zen::DrawContainer::containerType)
{
	/*
	.loc_0x0:
	  stw       r4, 0x28(r3)
	  li        r0, 0xB
	  li        r4, -0x1
	  mtctr     r0
	  lfs       f0, -0x47D8(r2)
	  li        r5, 0
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x24(r3)
	  stw       r4, 0x0(r3)

	.loc_0x24:
	  lwz       r4, 0x8(r3)
	  li        r0, 0
	  lwzx      r4, r4, r5
	  stb       r0, 0xF7(r4)
	  stb       r0, 0xFB(r4)
	  lwz       r4, 0xC(r3)
	  lwzx      r4, r4, r5
	  stb       r0, 0xF7(r4)
	  stb       r0, 0xFB(r4)
	  lwz       r4, 0x10(r3)
	  lwzx      r4, r4, r5
	  stb       r0, 0xF7(r4)
	  stb       r0, 0xFB(r4)
	  lwz       r4, 0x14(r3)
	  lwzx      r4, r4, r5
	  stb       r0, 0xF7(r4)
	  stb       r0, 0xFB(r4)
	  lwz       r4, 0x18(r3)
	  lwzx      r4, r4, r5
	  stb       r0, 0xF7(r4)
	  stb       r0, 0xFB(r4)
	  lwz       r4, 0x1C(r3)
	  lwzx      r4, r4, r5
	  addi      r5, r5, 0x4
	  stb       r0, 0xF7(r4)
	  stb       r0, 0xFB(r4)
	  bdnz+     .loc_0x24
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BD484
 * Size:	000150
 */
void zen::MessageMgr::setTextBox(zen::DrawContainer::containerType, P2DScreen&, int, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  addi      r30, r5, 0
	  addi      r31, r3, 0
	  mr        r26, r4
	  addi      r3, r30, 0
	  addi      r27, r6, 0
	  addi      r28, r8, 0
	  addi      r4, r7, 0
	  li        r5, 0x1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  mr        r29, r0
	  addi      r4, r28, 0
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lis       r4, 0x7061
	  mr        r28, r0
	  lwz       r12, 0x34(r12)
	  addi      r4, r4, 0x6C6C
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  addi      r30, r3, 0
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        0x2684
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x2678
	  cmpwi     r26, 0x1
	  beq-      .loc_0xCC
	  bge-      .loc_0xC0
	  cmpwi     r26, 0
	  bge-      .loc_0xE4
	  b         .loc_0x110

	.loc_0xC0:
	  cmpwi     r26, 0x3
	  bge-      .loc_0x110
	  b         .loc_0xFC

	.loc_0xCC:
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r27,2,0,29
	  stwx      r29, r3, r0
	  lwz       r3, 0xC(r31)
	  stwx      r28, r3, r0
	  b         .loc_0x110

	.loc_0xE4:
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r27,2,0,29
	  stwx      r29, r3, r0
	  lwz       r3, 0x14(r31)
	  stwx      r28, r3, r0
	  b         .loc_0x110

	.loc_0xFC:
	  lwz       r3, 0x18(r31)
	  rlwinm    r0,r27,2,0,29
	  stwx      r29, r3, r0
	  lwz       r3, 0x1C(r31)
	  stwx      r28, r3, r0

	.loc_0x110:
	  lbz       r0, 0xC(r29)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r29)
	  stb       r3, 0xF7(r29)
	  stb       r3, 0xFB(r29)
	  lbz       r0, 0xC(r28)
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r28)
	  stb       r3, 0xF7(r28)
	  stb       r3, 0xFB(r28)
	  lwz       r0, 0x3C(r1)
	  lmw       r26, 0x20(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BD5D4
 * Size:	0004B8
 */
void zen::DrawContainer::start(zen::DrawContainer::containerType, int, int, int, int, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stmw      r21, 0xDC(r1)
	  mr        r24, r3
	  addi      r25, r4, 0
	  addi      r26, r5, 0
	  addi      r27, r6, 0
	  addi      r28, r7, 0
	  addi      r29, r8, 0
	  addi      r30, r9, 0
	  addi      r31, r10, 0
	  lbz       r0, 0x1DC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x4A4
	  addi      r3, r24, 0x4
	  bl        0x2190
	  lis       r3, 0x802D
	  addi      r23, r3, 0x3004
	  stw       r23, 0x98(r1)
	  addi      r3, r1, 0x9C
	  li        r4, 0
	  li        r5, 0x10
	  bl        -0xCF30
	  lis       r3, 0x802D
	  stw       r23, 0x80(r1)
	  addi      r23, r3, 0x2FF4
	  lis       r3, 0x802E
	  stw       r23, 0x98(r1)
	  addi      r0, r3, 0x139C
	  stw       r0, 0x98(r1)
	  addi      r3, r1, 0x84
	  li        r4, 0
	  li        r5, 0x10
	  bl        -0xCF5C
	  lis       r3, 0x802E
	  stw       r23, 0x80(r1)
	  addi      r0, r3, 0x12E8
	  stw       r0, 0x80(r1)
	  addi      r3, r1, 0x7C
	  bl        0x207C
	  lwz       r3, 0x31A8(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0xC0:
	  lwz       r3, 0x31AC(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xDC
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0xDC:
	  lis       r3, 0x803D
	  addi      r22, r3, 0x2308
	  li        r23, 0

	.loc_0xE8:
	  lwz       r3, 0x0(r22)
	  cmplwi    r3, 0
	  beq-      .loc_0x104
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x104:
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0x15
	  addi      r22, r22, 0x4
	  blt+      .loc_0xE8
	  lis       r4, 0x803D
	  lis       r3, 0x803D
	  addi      r22, r4, 0x2360
	  addi      r21, r3, 0x2388
	  li        r23, 0

	.loc_0x128:
	  lwz       r3, 0x0(r22)
	  cmplwi    r3, 0
	  beq-      .loc_0x144
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x144:
	  lwz       r3, 0x0(r21)
	  cmplwi    r3, 0
	  beq-      .loc_0x160
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x160:
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0xA
	  addi      r22, r22, 0x4
	  addi      r21, r21, 0x4
	  blt+      .loc_0x128
	  li        r0, 0x1
	  stb       r0, 0x1DC(r24)
	  li        r23, 0
	  addi      r3, r24, 0
	  stw       r23, 0x0(r24)
	  stw       r25, 0x174(r24)
	  stw       r26, 0x178(r24)
	  stw       r27, 0x17C(r24)
	  stw       r23, 0x194(r24)
	  stw       r23, 0x1A0(r24)
	  stw       r28, 0x180(r24)
	  stw       r29, 0x184(r24)
	  stw       r30, 0x188(r24)
	  stw       r31, 0x18C(r24)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0x170(r24)
	  bl        0x468
	  lwz       r25, 0x1A4(r24)
	  lfs       f0, -0x47D0(r2)
	  lwz       r3, 0x0(r25)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lfs       f2, -0x47C8(r2)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x8(r25)
	  fadds     f1, f2, f1
	  lwz       r3, 0x0(r25)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  fctiwz    f1, f1
	  stfd      f0, 0xC8(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f1, 0xD0(r1)
	  mtlr      r12
	  lwz       r5, 0xCC(r1)
	  lwz       r4, 0xD4(r1)
	  blrl
	  lwz       r6, 0x0(r25)
	  li        r4, 0x7A
	  lha       r3, 0x18(r6)
	  lha       r0, 0x1C(r6)
	  lha       r5, 0x1A(r6)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r6)
	  srawi     r0, r0, 0x1
	  sub       r5, r3, r5
	  extsh     r3, r0
	  srawi     r0, r5, 0x4
	  sth       r3, 0xB8(r6)
	  extsh     r0, r0
	  sth       r0, 0xBA(r6)
	  lwz       r3, 0x0(r25)
	  lfs       f1, -0x47D8(r2)
	  bl        -0x37014
	  lwz       r6, 0x0(r25)
	  lis       r3, 0x4330
	  lfd       f2, -0x47A8(r2)
	  li        r4, -0x1
	  lha       r5, 0x1A(r6)
	  lha       r0, 0x18(r6)
	  xoris     r5, r5, 0x8000
	  lfs       f3, 0x1A4C(r13)
	  stw       r5, 0xC4(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xBC(r1)
	  stw       r3, 0xC0(r1)
	  stw       r3, 0xB8(r1)
	  lfd       f1, 0xC0(r1)
	  lfd       f0, 0xB8(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fadds     f1, f3, f1
	  stfs      f0, 0x10(r25)
	  stfs      f1, 0x14(r25)
	  lfs       f0, 0x1A38(r13)
	  stfs      f0, 0x18(r25)
	  lfs       f0, 0x1A3C(r13)
	  stfs      f0, 0x1C(r25)
	  lfs       f0, 0x1A40(r13)
	  stfs      f0, 0x20(r25)
	  lfs       f0, 0x1A44(r13)
	  stfs      f0, 0x24(r25)
	  lwz       r25, 0x1B4(r24)
	  lwz       r0, 0x174(r24)
	  mr        r3, r25
	  stw       r0, 0x28(r25)
	  lfs       f1, -0x47D8(r2)
	  bl        .loc_0x4B8
	  li        r0, 0xB
	  mtctr     r0

	.loc_0x2E0:
	  lwz       r3, 0x8(r25)
	  li        r0, 0
	  lwzx      r3, r3, r23
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lwz       r3, 0xC(r25)
	  lwzx      r3, r3, r23
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lwz       r3, 0x10(r25)
	  lwzx      r3, r3, r23
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lwz       r3, 0x14(r25)
	  lwzx      r3, r3, r23
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lwz       r3, 0x18(r25)
	  lwzx      r3, r3, r23
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lwz       r3, 0x1C(r25)
	  lwzx      r3, r3, r23
	  addi      r23, r23, 0x4
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  bdnz+     .loc_0x2E0
	  addi      r3, r24, 0x4
	  lwz       r12, 0x4(r24)
	  lis       r4, 0x7032
	  addi      r4, r4, 0x3634
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lwz       r0, 0x174(r24)
	  lis       r4, 0x7773
	  lwz       r6, 0x104(r3)
	  addi      r4, r4, 0x3863
	  rlwinm    r0,r0,2,0,29
	  add       r5, r24, r0
	  lwz       r0, 0x1B8(r5)
	  li        r5, 0x1
	  stw       r0, 0x0(r6)
	  lwz       r6, 0x108(r3)
	  stw       r0, 0x0(r6)
	  lwz       r6, 0x10C(r3)
	  stw       r0, 0x0(r6)
	  lwz       r6, 0x110(r3)
	  addi      r3, r24, 0x4
	  stw       r0, 0x0(r6)
	  lwz       r12, 0x4(r24)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x174(r24)
	  lbz       r0, 0xF1(r3)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r24, r4
	  cmplwi    r0, 0
	  lwz       r0, 0x1C4(r4)
	  ble-      .loc_0x3DC
	  stw       r0, 0xEC(r3)

	.loc_0x3DC:
	  addi      r3, r24, 0x4
	  lwz       r12, 0x4(r24)
	  lis       r4, 0x7032
	  addi      r4, r4, 0x6334
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lwz       r4, 0x174(r24)
	  lbz       r0, 0xF1(r3)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r24, r4
	  cmplwi    r0, 0
	  lwz       r0, 0x1D0(r4)
	  ble-      .loc_0x41C
	  stw       r0, 0xEC(r3)

	.loc_0x41C:
	  addi      r3, r24, 0x4
	  lwz       r12, 0x4(r24)
	  lis       r4, 0x7773
	  addi      r4, r4, 0x3875
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lwz       r4, 0x174(r24)
	  lbz       r0, 0xF1(r3)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r24, r4
	  cmplwi    r0, 0
	  lwz       r0, 0x1C4(r4)
	  ble-      .loc_0x45C
	  stw       r0, 0xEC(r3)

	.loc_0x45C:
	  addi      r3, r24, 0x4
	  lwz       r12, 0x4(r24)
	  lis       r4, 0x7773
	  addi      r4, r4, 0x386C
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lwz       r4, 0x174(r24)
	  lbz       r0, 0xF1(r3)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r24, r4
	  cmplwi    r0, 0
	  lwz       r0, 0x1C4(r4)
	  ble-      .loc_0x49C
	  stw       r0, 0xEC(r3)

	.loc_0x49C:
	  li        r3, 0x116
	  bl        -0x118700

	.loc_0x4A4:
	  lmw       r21, 0xDC(r1)
	  lwz       r0, 0x10C(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr

	.loc_0x4B8:
	*/
}

/*
 * --INFO--
 * Address:	801BDA8C
 * Size:	000164
 */
void zen::MessageMgr::setMessage(zen::MessageMgr::messageFlag, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  fmr       f31, f1
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  stw       r30, 0x30(r1)
	  addi      r30, r4, 0
	  lwz       r0, 0x0(r3)
	  cmpw      r0, r30
	  beq-      .loc_0x4C
	  cmpwi     r30, 0xA
	  bge-      .loc_0x4C
	  cmpwi     r30, 0x4
	  bge-      .loc_0x44
	  b         .loc_0x4C

	.loc_0x44:
	  li        r3, 0x119
	  bl        -0x118760

	.loc_0x4C:
	  lfs       f0, -0x47D8(r2)
	  cmpwi     r30, -0x1
	  stfs      f0, 0x20(r31)
	  stfs      f31, 0x24(r31)
	  stw       r30, 0x0(r31)
	  beq-      .loc_0x148
	  lwz       r0, 0x28(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x8C
	  bge-      .loc_0x80
	  cmpwi     r0, 0
	  bge-      .loc_0xCC
	  b         .loc_0x148

	.loc_0x80:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x148
	  b         .loc_0x10C

	.loc_0x8C:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0xC(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x148

	.loc_0xCC:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x148

	.loc_0x10C:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x18(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x1C(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x148:
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
 * Address:	801BDBF0
 * Size:	000038
 */
void zen::DrawContainer::setDispParam()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x178(r3)
	  lwz       r0, 0x194(r3)
	  add       r0, r4, r0
	  stw       r0, 0x198(r3)
	  lwz       r4, 0x194(r3)
	  lwz       r0, 0x180(r3)
	  sub       r0, r0, r4
	  stw       r0, 0x19C(r3)
	  lwz       r0, 0x194(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x30
	  neg       r0, r0

	.loc_0x30:
	  stw       r0, 0x1A0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void zen::DrawContainer::waitStatus()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000404
 */
void zen::DrawContainer::startStatus()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801BDC28
 * Size:	000C20
 */
void zen::DrawContainer::operationStatus()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x198(r1)
	  stw       r31, 0x194(r1)
	  stw       r30, 0x190(r1)
	  mr        r30, r3
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, -0x47B8(r2)
	  lfs       f0, 0x28C(r4)
	  lfs       f2, 0x170(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x170(r3)
	  lfs       f1, 0x170(r3)
	  lfs       f0, -0x47A0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x4C
	  fsubs     f0, f1, f0
	  stfs      f0, 0x170(r30)

	.loc_0x4C:
	  lwz       r31, 0x1A4(r30)
	  lis       r4, 0x4330
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0x158(r1)
	  stfs      f0, 0x154(r1)
	  stfs      f0, 0x150(r1)
	  stfs      f0, 0x164(r1)
	  stfs      f0, 0x160(r1)
	  stfs      f0, 0x15C(r1)
	  lfs       f0, 0x1A50(r13)
	  lfs       f1, 0x20(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r31)
	  lfs       f1, 0x10(r31)
	  lfs       f0, 0x1C(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x15C(r1)
	  lfs       f1, 0x14(r31)
	  lfs       f0, 0x20(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x160(r1)
	  lfs       f0, 0x1A30(r13)
	  stfs      f0, 0x164(r1)
	  lwz       r3, 0x0(r31)
	  lfd       f2, -0x47A8(r2)
	  lha       r0, 0x18(r3)
	  lfs       f1, 0x15C(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x18C(r1)
	  stw       r4, 0x188(r1)
	  lfd       f0, 0x188(r1)
	  fsubs     f0, f0, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x150(r1)
	  lwz       r3, 0x0(r31)
	  lfs       f1, 0x160(r1)
	  lha       r0, 0x1A(r3)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x184(r1)
	  stw       r4, 0x180(r1)
	  lfd       f0, 0x180(r1)
	  fsubs     f0, f0, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x154(r1)
	  lfs       f1, 0x150(r1)
	  lfs       f0, 0x154(r1)
	  lfs       f2, 0x158(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B0104
	  lfs       f0, -0x47D8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x248
	  lfs       f1, 0x150(r1)
	  lfs       f0, 0x154(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x158(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B0134
	  lfs       f0, -0x47D8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x164
	  addi      r3, r1, 0x150
	  bl        -0x13483C

	.loc_0x164:
	  lfs       f0, 0x150(r1)
	  lis       r3, 0x4330
	  lfs       f1, 0x1A4C(r13)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x150(r1)
	  lfs       f0, 0x154(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x154(r1)
	  lfs       f0, 0x158(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x158(r1)
	  lwz       r4, 0x0(r31)
	  lfd       f2, -0x47A8(r2)
	  lha       r0, 0x18(r4)
	  lfs       f1, 0x150(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x184(r1)
	  stw       r3, 0x180(r1)
	  lfd       f0, 0x180(r1)
	  fsubs     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x15C(r1)
	  lha       r0, 0x1A(r4)
	  lfs       f1, 0x154(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x18C(r1)
	  stw       r3, 0x188(r1)
	  lfd       f0, 0x188(r1)
	  fsubs     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x160(r1)
	  lfs       f1, 0x15C(r1)
	  lfs       f0, 0x10(r31)
	  lfs       f3, 0x160(r1)
	  lfs       f2, 0x14(r31)
	  fsubs     f0, f1, f0
	  fsubs     f1, f3, f2
	  stfs      f0, 0x1C(r31)
	  stfs      f1, 0x20(r31)
	  lfs       f0, 0x1A34(r13)
	  stfs      f0, 0x24(r31)
	  lwz       r3, 0x15C(r1)
	  lwz       r0, 0x160(r1)
	  stw       r3, 0x10(r31)
	  stw       r0, 0x14(r31)
	  lwz       r0, 0x164(r1)
	  stw       r0, 0x18(r31)
	  lfs       f1, 0x154(r1)
	  lfs       f0, 0x150(r1)
	  fneg      f1, f1
	  fneg      f2, f0
	  bl        -0xA0050
	  lfs       f0, -0x4790(r2)
	  li        r4, 0x7A
	  lwz       r3, 0x0(r31)
	  fadds     f1, f0, f1
	  bl        -0x37660

	.loc_0x248:
	  lfs       f1, -0x4778(r2)
	  lfs       f0, 0x170(r30)
	  fmuls     f1, f1, f0
	  bl        0x5DE6C
	  lfs       f0, -0x47D4(r2)
	  lfs       f2, 0x1B0(r30)
	  fmuls     f1, f0, f1
	  lfs       f0, -0x47D8(r2)
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x284
	  lfs       f0, -0x4798(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x28C

	.loc_0x284:
	  lfs       f0, -0x4798(r2)
	  fsubs     f0, f1, f0

	.loc_0x28C:
	  fctiwz    f0, f0
	  lfs       f1, 0x170(r30)
	  stfd      f0, 0x180(r1)
	  lwz       r31, 0x184(r1)
	  bl        0x5DE24
	  lfs       f0, -0x4774(r2)
	  lfs       f2, 0x1AC(r30)
	  fmuls     f1, f0, f1
	  lfs       f0, -0x47D8(r2)
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2CC
	  lfs       f0, -0x4798(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x2D4

	.loc_0x2CC:
	  lfs       f0, -0x4798(r2)
	  fsubs     f0, f1, f0

	.loc_0x2D4:
	  lwz       r3, 0x1A8(r30)
	  fctiwz    f0, f0
	  mr        r5, r31
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x180(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x184(r1)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x108(r30)
	  rlwinm.   r0,r4,0,12,12
	  bne-      .loc_0x314
	  lwz       r3, 0x100(r30)
	  lwz       r3, 0x28(r3)
	  rlwinm.   r0,r3,0,12,12
	  beq-      .loc_0x350

	.loc_0x314:
	  lwz       r3, 0x100(r30)
	  lwz       r0, 0x28(r3)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x330
	  lfs       f0, -0x47D0(r2)
	  stfs      f0, 0x190(r30)
	  b         .loc_0x3A0

	.loc_0x330:
	  lfs       f0, 0x190(r30)
	  lfs       f1, -0x47D0(r2)
	  fadds     f0, f0, f1
	  fcmpo     cr0, f0, f1
	  stfs      f0, 0x190(r30)
	  ble-      .loc_0x3A0
	  stfs      f1, 0x190(r30)
	  b         .loc_0x3A0

	.loc_0x350:
	  rlwinm.   r0,r4,0,10,10
	  bne-      .loc_0x360
	  rlwinm.   r0,r3,0,10,10
	  beq-      .loc_0x398

	.loc_0x360:
	  rlwinm.   r0,r3,0,10,10
	  beq-      .loc_0x374
	  lfs       f0, -0x4770(r2)
	  stfs      f0, 0x190(r30)
	  b         .loc_0x3A0

	.loc_0x374:
	  lfs       f1, 0x190(r30)
	  lfs       f0, -0x47D0(r2)
	  fsubs     f1, f1, f0
	  stfs      f1, 0x190(r30)
	  lfs       f0, -0x4770(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x3A0
	  stfs      f0, 0x190(r30)
	  b         .loc_0x3A0

	.loc_0x398:
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0x190(r30)

	.loc_0x3A0:
	  lfs       f1, 0x190(r30)
	  lfs       f0, -0x47D8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3C0
	  lfs       f0, -0x4798(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x3C8

	.loc_0x3C0:
	  lfs       f0, -0x4798(r2)
	  fsubs     f0, f1, f0

	.loc_0x3C8:
	  fctiwz    f0, f0
	  lwz       r3, 0x194(r30)
	  stfd      f0, 0x180(r1)
	  lwz       r0, 0x184(r1)
	  add       r0, r3, r0
	  stw       r0, 0x194(r30)
	  lwz       r4, 0x180(r30)
	  cmpwi     r4, 0
	  bne-      .loc_0x52C
	  lwz       r0, 0x178(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x52C
	  lwz       r0, 0x194(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0xB4C
	  lwz       r31, 0x1B4(r30)
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0x9
	  beq-      .loc_0x41C
	  li        r3, 0x119
	  bl        -0x118CCC

	.loc_0x41C:
	  lfs       f0, -0x47D8(r2)
	  li        r0, 0x9
	  stfs      f0, 0x20(r31)
	  lfs       f0, -0x4778(r2)
	  stfs      f0, 0x24(r31)
	  stw       r0, 0x0(r31)
	  lwz       r0, 0x28(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x45C
	  bge-      .loc_0x450
	  cmpwi     r0, 0
	  bge-      .loc_0x49C
	  b         .loc_0x518

	.loc_0x450:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x518
	  b         .loc_0x4DC

	.loc_0x45C:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0xC(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x518

	.loc_0x49C:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x518

	.loc_0x4DC:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x18(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x1C(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x518:
	  li        r0, 0
	  stw       r0, 0x194(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0x190(r30)
	  b         .loc_0xB4C

	.loc_0x52C:
	  lwz       r3, 0x194(r30)
	  cmpwi     r3, 0
	  ble-      .loc_0x7A0
	  cmpw      r4, r3
	  bge-      .loc_0x664
	  stw       r4, 0x194(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0x190(r30)
	  lwz       r31, 0x1B4(r30)
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0x7
	  beq-      .loc_0x564
	  li        r3, 0x119
	  bl        -0x118E14

	.loc_0x564:
	  lfs       f0, -0x47D8(r2)
	  li        r0, 0x7
	  stfs      f0, 0x20(r31)
	  lfs       f0, -0x4778(r2)
	  stfs      f0, 0x24(r31)
	  stw       r0, 0x0(r31)
	  lwz       r0, 0x28(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x5A4
	  bge-      .loc_0x598
	  cmpwi     r0, 0
	  bge-      .loc_0x5E4
	  b         .loc_0xB4C

	.loc_0x598:
	  cmpwi     r0, 0x3
	  bge-      .loc_0xB4C
	  b         .loc_0x624

	.loc_0x5A4:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0xC(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0x5E4:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0x624:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x18(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x1C(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0x664:
	  lwz       r4, 0x178(r30)
	  lwz       r5, 0x17C(r30)
	  add       r0, r4, r3
	  cmpw      r0, r5
	  ble-      .loc_0xB4C
	  sub       r0, r5, r4
	  stw       r0, 0x194(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0x190(r30)
	  lwz       r31, 0x1B4(r30)
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x6A0
	  li        r3, 0x119
	  bl        -0x118F50

	.loc_0x6A0:
	  lfs       f0, -0x47D8(r2)
	  li        r0, 0x4
	  stfs      f0, 0x20(r31)
	  lfs       f0, -0x4778(r2)
	  stfs      f0, 0x24(r31)
	  stw       r0, 0x0(r31)
	  lwz       r0, 0x28(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x6E0
	  bge-      .loc_0x6D4
	  cmpwi     r0, 0
	  bge-      .loc_0x720
	  b         .loc_0xB4C

	.loc_0x6D4:
	  cmpwi     r0, 0x3
	  bge-      .loc_0xB4C
	  b         .loc_0x760

	.loc_0x6E0:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0xC(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0x720:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0x760:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x18(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x1C(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0x7A0:
	  lwz       r5, 0x178(r30)
	  add.      r0, r5, r3
	  bge-      .loc_0x8D4
	  neg       r0, r5
	  stw       r0, 0x194(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0x190(r30)
	  lwz       r31, 0x1B4(r30)
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0x8
	  beq-      .loc_0x7D4
	  li        r3, 0x119
	  bl        -0x119084

	.loc_0x7D4:
	  lfs       f0, -0x47D8(r2)
	  li        r0, 0x8
	  stfs      f0, 0x20(r31)
	  lfs       f0, -0x4778(r2)
	  stfs      f0, 0x24(r31)
	  stw       r0, 0x0(r31)
	  lwz       r0, 0x28(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x814
	  bge-      .loc_0x808
	  cmpwi     r0, 0
	  bge-      .loc_0x854
	  b         .loc_0xB4C

	.loc_0x808:
	  cmpwi     r0, 0x3
	  bge-      .loc_0xB4C
	  b         .loc_0x894

	.loc_0x814:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0xC(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0x854:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0x894:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x18(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x1C(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0x8D4:
	  lwz       r5, 0x184(r30)
	  sub       r0, r4, r3
	  cmpw      r0, r5
	  ble-      .loc_0xA10
	  sub       r0, r5, r4
	  neg       r0, r0
	  stw       r0, 0x194(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0x190(r30)
	  lwz       r31, 0x1B4(r30)
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0x5
	  beq-      .loc_0x910
	  li        r3, 0x119
	  bl        -0x1191C0

	.loc_0x910:
	  lfs       f0, -0x47D8(r2)
	  li        r0, 0x5
	  stfs      f0, 0x20(r31)
	  lfs       f0, -0x4778(r2)
	  stfs      f0, 0x24(r31)
	  stw       r0, 0x0(r31)
	  lwz       r0, 0x28(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x950
	  bge-      .loc_0x944
	  cmpwi     r0, 0
	  bge-      .loc_0x990
	  b         .loc_0xB4C

	.loc_0x944:
	  cmpwi     r0, 0x3
	  bge-      .loc_0xB4C
	  b         .loc_0x9D0

	.loc_0x950:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0xC(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0x990:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0x9D0:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x18(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x1C(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0xA10:
	  lwz       r4, 0x188(r30)
	  lwz       r5, 0x18C(r30)
	  sub       r0, r4, r3
	  cmpw      r0, r5
	  ble-      .loc_0xB4C
	  sub       r0, r5, r4
	  neg       r0, r0
	  stw       r0, 0x194(r30)
	  lfs       f0, -0x47D8(r2)
	  stfs      f0, 0x190(r30)
	  lwz       r31, 0x1B4(r30)
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0x6
	  beq-      .loc_0xA50
	  li        r3, 0x119
	  bl        -0x119300

	.loc_0xA50:
	  lfs       f0, -0x47D8(r2)
	  li        r0, 0x6
	  stfs      f0, 0x20(r31)
	  lfs       f0, -0x4778(r2)
	  stfs      f0, 0x24(r31)
	  stw       r0, 0x0(r31)
	  lwz       r0, 0x28(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xA90
	  bge-      .loc_0xA84
	  cmpwi     r0, 0
	  bge-      .loc_0xAD0
	  b         .loc_0xB4C

	.loc_0xA84:
	  cmpwi     r0, 0x3
	  bge-      .loc_0xB4C
	  b         .loc_0xB10

	.loc_0xA90:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0xC(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0xAD0:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xB4C

	.loc_0xB10:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x18(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x1C(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xB4C:
	  lwz       r3, 0x194(r30)
	  cmpwi     r3, 0
	  bge-      .loc_0xB5C
	  neg       r3, r3

	.loc_0xB5C:
	  lwz       r0, 0x1A0(r30)
	  cmpw      r0, r3
	  beq-      .loc_0xB70
	  li        r3, 0x118
	  bl        -0x119420

	.loc_0xB70:
	  lwz       r3, 0x178(r30)
	  lwz       r0, 0x194(r30)
	  add       r0, r3, r0
	  stw       r0, 0x198(r30)
	  lwz       r3, 0x194(r30)
	  lwz       r0, 0x180(r30)
	  sub       r0, r0, r3
	  stw       r0, 0x19C(r30)
	  lwz       r0, 0x194(r30)
	  cmpwi     r0, 0
	  bge-      .loc_0xBA0
	  neg       r0, r0

	.loc_0xBA0:
	  stw       r0, 0x1A0(r30)
	  lis       r3, 0x100
	  addi      r0, r3, 0x1000
	  lwz       r3, 0x100(r30)
	  lwz       r3, 0x28(r3)
	  and.      r0, r3, r0
	  beq-      .loc_0xBD4
	  lfs       f0, -0x47D8(r2)
	  li        r0, 0x3
	  li        r3, 0x117
	  stfs      f0, 0x170(r30)
	  stw       r0, 0x0(r30)
	  bl        -0x119484

	.loc_0xBD4:
	  lwz       r3, 0x100(r30)
	  lwz       r0, 0x28(r3)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0xC04
	  lfs       f0, -0x47D8(r2)
	  li        r4, 0x3
	  li        r0, 0
	  stfs      f0, 0x170(r30)
	  li        r3, 0x117
	  stw       r4, 0x0(r30)
	  stw       r0, 0x194(r30)
	  bl        -0x1194B4

	.loc_0xC04:
	  lwz       r0, 0x19C(r1)
	  li        r3, 0
	  lwz       r31, 0x194(r1)
	  lwz       r30, 0x190(r1)
	  addi      r1, r1, 0x198
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000384
 */
void zen::DrawContainer::endStatus()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801BE848
 * Size:	00052C
 */
void zen::DrawContainer::update(int&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stmw      r24, 0x90(r1)
	  mr        r27, r3
	  addi      r29, r4, 0
	  li        r28, 0
	  lbz       r0, 0x1DC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x508
	  lwz       r3, 0x100(r27)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r27, 0x104
	  bl        0x1B14
	  lwz       r0, 0x0(r27)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x200
	  bge-      .loc_0x6C
	  cmpwi     r0, 0
	  beq-      .loc_0x78
	  bge-      .loc_0xB4
	  b         .loc_0x2CC

	.loc_0x6C:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x2CC
	  b         .loc_0x210

	.loc_0x78:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x170(r27)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x170(r27)
	  lfs       f1, 0x170(r27)
	  lfs       f0, -0x479C(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xAC
	  lfs       f0, -0x47D8(r2)
	  li        r0, 0x1
	  stfs      f0, 0x170(r27)
	  stw       r0, 0x0(r27)

	.loc_0xAC:
	  li        r28, 0
	  b         .loc_0x2CC

	.loc_0xB4:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x170(r27)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x170(r27)
	  lfs       f2, 0x170(r27)
	  lfs       f1, -0x4798(r2)
	  lfs       f0, -0x47D0(r2)
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xE4
	  fmr       f1, f0

	.loc_0xE4:
	  lfs       f0, -0x4794(r2)
	  fmuls     f1, f0, f1
	  bl        0x5D220
	  fneg      f0, f1
	  lfs       f1, -0x47D0(r2)
	  lfs       f2, -0x4798(r2)
	  li        r4, 0x1
	  lwz       r3, 0x1A4(r27)
	  fadds     f0, f1, f0
	  fmuls     f31, f2, f0
	  fsubs     f30, f1, f31
	  fmr       f1, f31
	  fmr       f2, f30
	  bl        .loc_0x52C
	  lfs       f0, -0x478C(r2)
	  lwz       r3, 0x1A8(r27)
	  fmuls     f0, f0, f31
	  fctiwz    f0, f0
	  stfd      f0, 0x88(r1)
	  lwz       r0, 0x8C(r1)
	  stb       r0, 0xF0(r3)
	  lfs       f0, -0x4794(r2)
	  fmuls     f1, f0, f30
	  bl        0x5D1CC
	  lfs       f2, -0x47D0(r2)
	  lwz       r3, 0x1A8(r27)
	  fsubs     f0, f2, f1
	  fadds     f0, f2, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lfs       f1, 0x1B0(r27)
	  lfs       f0, -0x47D8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x180
	  lfs       f0, -0x4798(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x188

	.loc_0x180:
	  lfs       f0, -0x4798(r2)
	  fsubs     f0, f1, f0

	.loc_0x188:
	  lfs       f2, 0x1AC(r27)
	  fctiwz    f1, f0
	  lfs       f0, -0x47D8(r2)
	  fcmpo     cr0, f2, f0
	  stfd      f1, 0x88(r1)
	  lwz       r5, 0x8C(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1B4
	  lfs       f0, -0x4798(r2)
	  fadds     f0, f0, f2
	  b         .loc_0x1BC

	.loc_0x1B4:
	  lfs       f0, -0x4798(r2)
	  fsubs     f0, f2, f0

	.loc_0x1BC:
	  lwz       r3, 0x1A8(r27)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x88(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x8C(r1)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x47D0(r2)
	  fcmpu     cr0, f0, f31
	  bne-      .loc_0x1F8
	  lfs       f0, -0x47D8(r2)
	  li        r0, 0x2
	  stfs      f0, 0x170(r27)
	  stw       r0, 0x0(r27)

	.loc_0x1F8:
	  li        r28, 0
	  b         .loc_0x2CC

	.loc_0x200:
	  mr        r3, r27
	  bl        -0xE24
	  mr        r28, r3
	  b         .loc_0x2CC

	.loc_0x210:
	  lwz       r3, 0x2DEC(r13)
	  li        r28, 0
	  lfs       f1, 0x170(r27)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x170(r27)
	  lfs       f2, 0x170(r27)
	  lfs       f1, -0x4798(r2)
	  lfs       f0, -0x47D0(r2)
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x244
	  fmr       f1, f0

	.loc_0x244:
	  lfs       f0, -0x4794(r2)
	  fmuls     f1, f0, f1
	  bl        0x5D0C0
	  fneg      f0, f1
	  lfs       f1, -0x47D0(r2)
	  lfs       f2, -0x4798(r2)
	  li        r4, 0x3
	  lwz       r3, 0x1A4(r27)
	  fadds     f0, f1, f0
	  fmuls     f31, f2, f0
	  fsubs     f30, f1, f31
	  fmr       f1, f31
	  fmr       f2, f30
	  bl        .loc_0x52C
	  lfs       f0, -0x478C(r2)
	  lwz       r3, 0x1A8(r27)
	  fmuls     f0, f0, f30
	  fctiwz    f0, f0
	  stfd      f0, 0x88(r1)
	  lwz       r0, 0x8C(r1)
	  stb       r0, 0xF0(r3)
	  lfs       f0, -0x4778(r2)
	  lfs       f1, -0x47D0(r2)
	  fmuls     f0, f0, f31
	  lwz       r3, 0x1A8(r27)
	  fcmpu     cr0, f1, f31
	  fadds     f0, f1, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  bne-      .loc_0x2CC
	  li        r0, 0
	  stb       r0, 0x1DC(r27)
	  li        r28, 0x1

	.loc_0x2CC:
	  lwz       r0, 0x194(r27)
	  li        r26, 0
	  stw       r0, 0x0(r29)
	  lwz       r29, 0x1B4(r27)
	  lfs       f2, -0x47D8(r2)
	  lfs       f0, 0x24(r29)
	  lwz       r24, 0x19C(r27)
	  fcmpo     cr0, f0, f2
	  lwz       r25, 0x198(r27)
	  lwz       r4, 0x100(r27)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x328
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x20(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r29)
	  lfs       f1, 0x20(r29)
	  lfs       f0, 0x24(r29)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x328
	  stfs      f2, 0x20(r29)
	  li        r26, 0x1

	.loc_0x328:
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0xA
	  bne-      .loc_0x350
	  lwz       r0, 0x20(r4)
	  andis.    r0, r0, 0x28
	  beq-      .loc_0x350
	  lfs       f1, -0x47D8(r2)
	  addi      r3, r29, 0
	  li        r4, -0x1
	  bl        -0x1108

	.loc_0x350:
	  rlwinm.   r0,r26,0,24,31
	  beq-      .loc_0x400
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0x4
	  bge-      .loc_0x3F0
	  cmpwi     r0, -0x1
	  bge-      .loc_0x370
	  b         .loc_0x3F0

	.loc_0x370:
	  bne-      .loc_0x3DC
	  cmpwi     r25, 0
	  ble-      .loc_0x3AC
	  cmpwi     r24, 0
	  ble-      .loc_0x398
	  lfs       f1, -0x476C(r2)
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        -0x114C
	  b         .loc_0x400

	.loc_0x398:
	  lfs       f1, -0x476C(r2)
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x1160
	  b         .loc_0x400

	.loc_0x3AC:
	  cmpwi     r24, 0
	  ble-      .loc_0x3C8
	  lfs       f1, -0x476C(r2)
	  addi      r3, r29, 0
	  li        r4, 0x2
	  bl        -0x117C
	  b         .loc_0x400

	.loc_0x3C8:
	  lfs       f1, -0x4770(r2)
	  addi      r3, r29, 0
	  li        r4, 0x3
	  bl        -0x1190
	  b         .loc_0x400

	.loc_0x3DC:
	  lfs       f1, -0x4770(r2)
	  addi      r3, r29, 0
	  li        r4, 0xA
	  bl        -0x11A4
	  b         .loc_0x400

	.loc_0x3F0:
	  lfs       f1, -0x47D8(r2)
	  addi      r3, r29, 0
	  li        r4, -0x1
	  bl        -0x11B8

	.loc_0x400:
	  lwz       r0, 0x28(r29)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x428
	  bge-      .loc_0x41C
	  cmpwi     r0, 0
	  bge-      .loc_0x434
	  b         .loc_0x448

	.loc_0x41C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x448
	  b         .loc_0x440

	.loc_0x428:
	  lwz       r30, 0x8(r29)
	  lwz       r31, 0xC(r29)
	  b         .loc_0x448

	.loc_0x434:
	  lwz       r30, 0x10(r29)
	  lwz       r31, 0x14(r29)
	  b         .loc_0x448

	.loc_0x440:
	  lwz       r30, 0x18(r29)
	  lwz       r31, 0x1C(r29)

	.loc_0x448:
	  li        r5, 0
	  b         .loc_0x4F0

	.loc_0x450:
	  lwz       r0, 0x0(r29)
	  lwz       r3, 0x0(r30)
	  cmpw      r5, r0
	  lbz       r6, 0xF7(r3)
	  bne-      .loc_0x49C
	  lbz       r0, 0xC(r3)
	  li        r4, 0x1
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  cmplwi    r6, 0xEB
	  lwz       r3, 0x0(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  bge-      .loc_0x494
	  addi      r4, r6, 0x14
	  b         .loc_0x4CC

	.loc_0x494:
	  li        r4, 0xFF
	  b         .loc_0x4CC

	.loc_0x49C:
	  cmplwi    r6, 0x14
	  ble-      .loc_0x4AC
	  subi      r4, r6, 0x14
	  b         .loc_0x4CC

	.loc_0x4AC:
	  lbz       r0, 0xC(r3)
	  li        r4, 0
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x0(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x4CC:
	  lwz       r3, 0x0(r30)
	  addi      r5, r5, 0x1
	  addi      r30, r30, 0x4
	  stb       r4, 0xF7(r3)
	  stb       r4, 0xFB(r3)
	  lwz       r3, 0x0(r31)
	  addi      r31, r31, 0x4
	  stb       r4, 0xF7(r3)
	  stb       r4, 0xFB(r3)

	.loc_0x4F0:
	  lwz       r0, 0x4(r29)
	  cmpw      r5, r0
	  blt+      .loc_0x450
	  addi      r3, r27, 0x4
	  bl        -0xC1F8
	  b         .loc_0x50C

	.loc_0x508:
	  li        r28, 0x1

	.loc_0x50C:
	  mr        r3, r28
	  lmw       r24, 0x90(r1)
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr

	.loc_0x52C:
	*/
}

/*
 * --INFO--
 * Address:	801BED74
 * Size:	0003C4
 */
void zen::WindowPaneMgr::update(zen::WindowPaneMgr::modeFlag, f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r4, 0x2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB0(r1)
	  stfd      f31, 0xA8(r1)
	  stfd      f30, 0xA0(r1)
	  stw       r31, 0x9C(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0x180
	  bge-      .loc_0x38
	  cmpwi     r4, 0
	  beq-      .loc_0x180
	  bge-      .loc_0x44
	  b         .loc_0x180

	.loc_0x38:
	  cmpwi     r4, 0x4
	  bge-      .loc_0x180
	  b         .loc_0xE4

	.loc_0x44:
	  lfs       f3, 0x8(r31)
	  lfs       f0, -0x47D8(r2)
	  fmuls     f4, f3, f1
	  fmuls     f3, f3, f2
	  fadds     f3, f4, f3
	  fcmpo     cr0, f3, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x70
	  lfs       f0, -0x4798(r2)
	  fadds     f0, f0, f3
	  b         .loc_0x78

	.loc_0x70:
	  lfs       f0, -0x4798(r2)
	  fsubs     f0, f3, f0

	.loc_0x78:
	  lfs       f6, 0x4(r31)
	  fctiwz    f5, f0
	  lfs       f3, -0x47C8(r2)
	  fmuls     f4, f6, f1
	  lfs       f0, -0x47D8(r2)
	  fadds     f1, f3, f6
	  stfd      f5, 0x90(r1)
	  fmuls     f1, f1, f2
	  lwz       r5, 0x94(r1)
	  fadds     f1, f4, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xB8
	  lfs       f0, -0x4798(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xC0

	.loc_0xB8:
	  lfs       f0, -0x4798(r2)
	  fsubs     f0, f1, f0

	.loc_0xC0:
	  lwz       r3, 0x0(r31)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x90(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x94(r1)
	  mtlr      r12
	  blrl
	  b         .loc_0x180

	.loc_0xE4:
	  lfs       f3, 0x8(r31)
	  lfs       f0, -0x47D8(r2)
	  fmuls     f4, f3, f2
	  fmuls     f3, f3, f1
	  fadds     f3, f4, f3
	  fcmpo     cr0, f3, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x110
	  lfs       f0, -0x4798(r2)
	  fadds     f0, f0, f3
	  b         .loc_0x118

	.loc_0x110:
	  lfs       f0, -0x4798(r2)
	  fsubs     f0, f3, f0

	.loc_0x118:
	  lfs       f6, 0x4(r31)
	  fctiwz    f5, f0
	  lfs       f3, -0x47C8(r2)
	  fmuls     f4, f6, f2
	  lfs       f0, -0x47D8(r2)
	  fsubs     f2, f6, f3
	  stfd      f5, 0x90(r1)
	  fmuls     f1, f2, f1
	  lwz       r5, 0x94(r1)
	  fadds     f1, f4, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x158
	  lfs       f0, -0x4798(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x160

	.loc_0x158:
	  lfs       f0, -0x4798(r2)
	  fsubs     f0, f1, f0

	.loc_0x160:
	  lwz       r3, 0x0(r31)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x90(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x94(r1)
	  mtlr      r12
	  blrl

	.loc_0x180:
	  lfs       f0, -0x47D8(r2)
	  lis       r3, 0x4330
	  stfs      f0, 0x74(r1)
	  stfs      f0, 0x70(r1)
	  stfs      f0, 0x6C(r1)
	  lfs       f1, 0x1A50(r13)
	  lfs       f2, 0x20(r31)
	  fadds     f1, f2, f1
	  stfs      f1, 0x20(r31)
	  lfs       f2, 0x10(r31)
	  lfs       f1, 0x1C(r31)
	  fadds     f1, f2, f1
	  stfs      f1, 0x6C(r1)
	  lfs       f2, 0x14(r31)
	  lfs       f1, 0x20(r31)
	  fadds     f1, f2, f1
	  stfs      f1, 0x70(r1)
	  lfs       f1, 0x1A30(r13)
	  stfs      f1, 0x74(r1)
	  lwz       r5, 0x0(r31)
	  lfd       f4, -0x47A8(r2)
	  lha       r4, 0x18(r5)
	  lha       r0, 0x1A(r5)
	  xoris     r4, r4, 0x8000
	  lfs       f5, 0x6C(r1)
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x94(r1)
	  lfs       f2, 0x70(r1)
	  stw       r0, 0x8C(r1)
	  stw       r3, 0x90(r1)
	  stw       r3, 0x88(r1)
	  lfd       f3, 0x90(r1)
	  lfd       f1, 0x88(r1)
	  fsubs     f3, f3, f4
	  fsubs     f1, f1, f4
	  fsubs     f30, f5, f3
	  fsubs     f31, f2, f1
	  fmuls     f2, f30, f30
	  fmuls     f1, f31, f31
	  fadds     f6, f2, f1
	  fadds     f5, f0, f6
	  fcmpo     cr0, f5, f0
	  ble-      .loc_0x284
	  fsqrte    f2, f5
	  lfd       f4, -0x4788(r2)
	  lfd       f3, -0x4780(r2)
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f5, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f5, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f5, f1
	  fsub      f1, f3, f1
	  fmul      f1, f2, f1
	  fmul      f1, f5, f1
	  frsp      f1, f1
	  stfs      f1, 0x4C(r1)
	  lfs       f5, 0x4C(r1)

	.loc_0x284:
	  lfs       f1, -0x47D8(r2)
	  fcmpu     cr0, f1, f5
	  beq-      .loc_0x3A8
	  fmuls     f0, f0, f0
	  fadds     f1, f0, f6
	  bl        -0x1B13CC
	  lfs       f0, -0x47D8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2B0
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1

	.loc_0x2B0:
	  lwz       r4, 0x0(r31)
	  lis       r3, 0x4330
	  lfs       f0, 0x1A4C(r13)
	  lha       r0, 0x18(r4)
	  fmuls     f30, f30, f0
	  lfd       f3, -0x47A8(r2)
	  xoris     r0, r0, 0x8000
	  fmuls     f31, f31, f0
	  stw       r0, 0x8C(r1)
	  stw       r3, 0x88(r1)
	  fneg      f1, f31
	  fneg      f2, f30
	  lfd       f0, 0x88(r1)
	  fsubs     f0, f0, f3
	  fadds     f0, f30, f0
	  stfs      f0, 0x6C(r1)
	  lha       r0, 0x1A(r4)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x94(r1)
	  stw       r3, 0x90(r1)
	  lfd       f0, 0x90(r1)
	  fsubs     f0, f0, f3
	  fadds     f0, f31, f0
	  stfs      f0, 0x70(r1)
	  lfs       f3, 0x6C(r1)
	  lfs       f0, 0x10(r31)
	  lfs       f5, 0x70(r1)
	  lfs       f4, 0x14(r31)
	  fsubs     f0, f3, f0
	  fsubs     f3, f5, f4
	  stfs      f0, 0x1C(r31)
	  stfs      f3, 0x20(r31)
	  lfs       f0, 0x1A34(r13)
	  stfs      f0, 0x24(r31)
	  lwz       r3, 0x6C(r1)
	  lwz       r0, 0x70(r1)
	  stw       r3, 0x10(r31)
	  stw       r0, 0x14(r31)
	  lwz       r0, 0x74(r1)
	  stw       r0, 0x18(r31)
	  bl        -0xA12BC
	  lwz       r4, 0x0(r31)
	  li        r3, 0x7A
	  lfs       f0, -0x4790(r2)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r3,5,25,26
	  fadds     f0, f0, f1
	  stb       r0, 0xC(r4)
	  stfs      f0, 0xBC(r4)
	  lfs       f1, 0xBC(r4)
	  lfs       f0, -0x47D8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x394
	  lfs       f0, -0x47A0(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0xBC(r4)
	  b         .loc_0x3A8

	.loc_0x394:
	  lfs       f0, -0x47A0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x3A8
	  fsubs     f0, f1, f0
	  stfs      f0, 0xBC(r4)

	.loc_0x3A8:
	  lwz       r0, 0xB4(r1)
	  lfd       f31, 0xA8(r1)
	  lfd       f30, 0xA0(r1)
	  lwz       r31, 0x9C(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BF138
 * Size:	00005C
 */
void zen::DrawContainer::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lbz       r0, 0x1DC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x48
	  lwz       r3, 0xFC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0xFC(r31)
	  addi      r3, r31, 0x4
	  li        r4, 0
	  li        r5, 0
	  bl        -0xC2A8

	.loc_0x48:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BF194
 * Size:	000108
 */
void zen::StickCallBack::invoke(P2DPane*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  mr        r29, r3
	  lwz       r3, 0x14(r3)
	  lwz       r0, 0x198(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x4C
	  lwz       r0, 0x19C(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x44
	  lwz       r30, 0x10(r29)
	  b         .loc_0x64

	.loc_0x44:
	  lwz       r30, 0xC(r29)
	  b         .loc_0x64

	.loc_0x4C:
	  lwz       r0, 0x19C(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x60
	  lwz       r30, 0x8(r29)
	  b         .loc_0x64

	.loc_0x60:
	  li        r30, 0

	.loc_0x64:
	  lwz       r3, 0x4(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  bl        0x1EC0
	  lwz       r0, 0x4(r29)
	  cmplw     r0, r30
	  beq-      .loc_0xD8
	  cmplwi    r30, 0
	  beq-      .loc_0xA8
	  lwz       r0, 0x0(r30)
	  lwz       r4, 0x8(r30)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r0, r4, r0
	  cmplw     r3, r0
	  bne-      .loc_0xD8
	  stw       r30, 0x4(r29)
	  b         .loc_0xD8

	.loc_0xA8:
	  li        r0, 0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r29)
	  addi      r3, r3, 0x2308
	  lwz       r3, 0x28(r3)
	  b         .loc_0xD8

	.loc_0xC0:
	  cmplwi    r30, 0
	  beq-      .loc_0xCC
	  stw       r30, 0x4(r29)

	.loc_0xCC:
	  lis       r3, 0x803D
	  addi      r3, r3, 0x2308
	  lwz       r3, 0x28(r3)

	.loc_0xD8:
	  lbz       r0, 0xF1(r31)
	  cmplwi    r0, 0
	  ble-      .loc_0xE8
	  stw       r3, 0xEC(r31)

	.loc_0xE8:
	  lwz       r0, 0x4C(r1)
	  li        r3, 0x1
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BF29C
 * Size:	000178
 */
void zen::ArrowLRCallBack::invoke(P2DPane*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r3
	  stw       r30, 0x48(r1)
	  mr        r30, r4
	  lwz       r3, 0x4(r3)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x7C
	  lwz       r0, 0x198(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x5C
	  lwz       r0, 0x19C(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x50
	  li        r0, 0x2
	  stw       r0, 0x1C(r31)
	  b         .loc_0x7C

	.loc_0x50:
	  li        r0, 0x1
	  stw       r0, 0x1C(r31)
	  b         .loc_0x7C

	.loc_0x5C:
	  lwz       r0, 0x19C(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x74
	  li        r0, 0
	  stw       r0, 0x1C(r31)
	  b         .loc_0x7C

	.loc_0x74:
	  li        r0, 0x3
	  stw       r0, 0x1C(r31)

	.loc_0x7C:
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x94
	  li        r0, 0x1
	  stb       r0, 0x18(r31)
	  b         .loc_0x9C

	.loc_0x94:
	  li        r0, 0
	  stb       r0, 0x18(r31)

	.loc_0x9C:
	  lfs       f1, 0x10(r31)
	  lfs       f0, 0x14(r31)
	  lbz       r3, 0xF0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r31)
	  lfs       f1, 0x10(r31)
	  lfs       f0, -0x47D8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xCC
	  lfs       f0, -0x47A0(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r31)

	.loc_0xCC:
	  lfs       f1, 0x10(r31)
	  lfs       f0, -0x47A0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xE4
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r31)

	.loc_0xE4:
	  lbz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x108
	  cmplwi    r3, 0xEB
	  bge-      .loc_0x100
	  addi      r0, r3, 0x14
	  b         .loc_0x11C

	.loc_0x100:
	  li        r0, 0xFF
	  b         .loc_0x11C

	.loc_0x108:
	  cmplwi    r3, 0x28
	  ble-      .loc_0x118
	  subi      r0, r3, 0x28
	  b         .loc_0x11C

	.loc_0x118:
	  li        r0, 0

	.loc_0x11C:
	  stb       r0, 0xF0(r30)
	  lfs       f1, 0x10(r31)
	  bl        0x5C928
	  lfs       f0, -0x4768(r2)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  fmuls     f0, f0, f1
	  lwz       r5, 0xC(r31)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x8(r31)
	  fctiwz    f0, f0
	  mtlr      r12
	  stfd      f0, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  add       r5, r5, r0
	  blrl
	  lwz       r0, 0x54(r1)
	  li        r3, 0x1
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801BF414
 * Size:	000160
 */
void zen::ArrowCenterCallBack::invoke(P2DPane*)
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
	  addi      r3, r30, 0x4
	  bl        -0x20AC
	  lwz       r0, 0x1C(r30)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x38
	  cmpwi     r0, 0x2
	  bne-      .loc_0x44

	.loc_0x38:
	  li        r0, 0
	  stb       r0, 0x18(r30)
	  b         .loc_0x84

	.loc_0x44:
	  li        r0, 0x1
	  stb       r0, 0x18(r30)
	  lwz       r0, 0x1C(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x70
	  lbz       r0, 0xF1(r31)
	  lwz       r3, 0x31A8(r13)
	  cmplwi    r0, 0
	  ble-      .loc_0x84
	  stw       r3, 0xEC(r31)
	  b         .loc_0x84

	.loc_0x70:
	  lbz       r0, 0xF1(r31)
	  lwz       r3, 0x31AC(r13)
	  cmplwi    r0, 0
	  ble-      .loc_0x84
	  stw       r3, 0xEC(r31)

	.loc_0x84:
	  lfs       f1, 0x10(r30)
	  lfs       f0, 0x14(r30)
	  lbz       r3, 0xF0(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r30)
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x47D8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB4
	  lfs       f0, -0x47A0(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r30)

	.loc_0xB4:
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x47A0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xCC
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r30)

	.loc_0xCC:
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xF0
	  cmplwi    r3, 0xEB
	  bge-      .loc_0xE8
	  addi      r0, r3, 0x14
	  b         .loc_0x104

	.loc_0xE8:
	  li        r0, 0xFF
	  b         .loc_0x104

	.loc_0xF0:
	  cmplwi    r3, 0x28
	  ble-      .loc_0x100
	  subi      r0, r3, 0x28
	  b         .loc_0x104

	.loc_0x100:
	  li        r0, 0

	.loc_0x104:
	  stb       r0, 0xF0(r31)
	  lfs       f1, 0x10(r30)
	  bl        0x5C7C8
	  lfs       f0, -0x4768(r2)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  fmuls     f0, f0, f1
	  lwz       r5, 0xC(r30)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x8(r30)
	  fctiwz    f0, f0
	  mtlr      r12
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  add       r5, r5, r0
	  blrl
	  lwz       r0, 0x2C(r1)
	  li        r3, 0x1
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}
