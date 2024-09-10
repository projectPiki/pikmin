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
 * Address:	801C1140
 * Size:	001474
 */
zen::DrawAccount::DrawAccount()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r6, 0
	  li        r7, 0
	  stwu      r1, -0x238(r1)
	  stw       r31, 0x234(r1)
	  stw       r30, 0x230(r1)
	  stw       r29, 0x22C(r1)
	  stw       r28, 0x228(r1)
	  stw       r3, 0x8(r1)
	  lis       r3, 0x802E
	  addi      r4, r3, 0x15C4
	  lwz       r3, 0x8(r1)
	  bl        -0x1C04
	  lwz       r28, 0x8(r1)
	  lis       r3, 0x802E
	  addi      r0, r3, 0x160C
	  stw       r0, 0x0(r28)
	  li        r31, 0
	  lis       r4, 0x726F
	  sth       r31, 0x108(r28)
	  addi      r3, r28, 0x4
	  addi      r4, r4, 0x6F74
	  sth       r31, 0x10A(r28)
	  li        r5, 0x1
	  sth       r31, 0x10C(r28)
	  sth       r31, 0x10E(r28)
	  sth       r31, 0x110(r28)
	  stb       r31, 0x11C(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0x100(r28)
	  lfs       f0, -0x46AC(r2)
	  stfs      f0, 0x104(r28)
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x114(r28)
	  li        r4, 0
	  li        r5, -0x3E8
	  lwz       r3, 0x114(r28)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r28, 0x4
	  lwz       r12, 0x4(r28)
	  lis       r4, 0x626C
	  addi      r4, r4, 0x616B
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x118(r28)
	  li        r4, 0
	  lwz       r3, 0x118(r28)
	  bl        -0x194C
	  addi      r3, r28, 0x4
	  lwz       r12, 0x4(r28)
	  lis       r4, 0x636C
	  addi      r4, r4, 0x5F30
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  addi      r30, r3, 0
	  li        r3, 0x18
	  bl        -0x17A24C
	  mr.       r29, r3
	  beq-      .loc_0x21C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r29)
	  addi      r4, r30, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x10B74
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r29)
	  addi      r3, r29, 0x4
	  bl        -0x1B98
	  addi      r0, r28, 0x108
	  stw       r0, 0x4(r29)
	  li        r0, 0x64
	  lis       r3, 0x802E
	  stw       r0, 0x8(r29)
	  addi      r0, r3, 0x1054
	  stw       r0, 0x0(r29)
	  stb       r31, 0x14(r29)
	  lwz       r3, 0x4(r29)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r29)
	  sth       r31, 0x12(r29)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r29)
	  lbz       r0, 0x14(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C0
	  addi      r3, r29, 0x4
	  bl        -0x8D90
	  lbz       r0, 0xF1(r30)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1EC
	  stw       r0, 0xEC(r30)
	  b         .loc_0x1EC

	.loc_0x1C0:
	  addi      r3, r29, 0x4
	  bl        -0x8DC0
	  lbz       r0, 0xF1(r30)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1EC
	  stw       r0, 0xEC(r30)

	.loc_0x1EC:
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

	.loc_0x21C:
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  bl        -0x10CC8
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x6363
	  addi      r4, r3, 0x5F30
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17A390
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0x368
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x10CBC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x1CE0
	  addi      r0, r30, 0x108
	  stw       r0, 0x4(r28)
	  li        r0, 0xA
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x30C
	  addi      r3, r29, 0x4
	  bl        -0x8EDC
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x338
	  stw       r0, 0xEC(r31)
	  b         .loc_0x338

	.loc_0x30C:
	  addi      r3, r29, 0x4
	  bl        -0x8F0C
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x338
	  stw       r0, 0xEC(r31)

	.loc_0x338:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0x368:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x10E14
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x6372
	  addi      r4, r3, 0x5F30
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17A4DC
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0x4B4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x10E08
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x1E2C
	  addi      r0, r30, 0x108
	  stw       r0, 0x4(r28)
	  li        r0, 0x1
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x458
	  addi      r3, r29, 0x4
	  bl        -0x9028
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x484
	  stw       r0, 0xEC(r31)
	  b         .loc_0x484

	.loc_0x458:
	  addi      r3, r29, 0x4
	  bl        -0x9058
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x484
	  stw       r0, 0xEC(r31)

	.loc_0x484:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0x4B4:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x10F60
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x636C
	  addi      r4, r3, 0x5F31
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17A628
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0x600
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x10F54
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x1F78
	  addi      r0, r30, 0x10A
	  stw       r0, 0x4(r28)
	  li        r0, 0x64
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x5A4
	  addi      r3, r29, 0x4
	  bl        -0x9174
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x5D0
	  stw       r0, 0xEC(r31)
	  b         .loc_0x5D0

	.loc_0x5A4:
	  addi      r3, r29, 0x4
	  bl        -0x91A4
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x5D0
	  stw       r0, 0xEC(r31)

	.loc_0x5D0:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0x600:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x110AC
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x6363
	  addi      r4, r3, 0x5F31
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17A774
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0x74C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x110A0
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x20C4
	  addi      r0, r30, 0x10A
	  stw       r0, 0x4(r28)
	  li        r0, 0xA
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x6F0
	  addi      r3, r29, 0x4
	  bl        -0x92C0
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x71C
	  stw       r0, 0xEC(r31)
	  b         .loc_0x71C

	.loc_0x6F0:
	  addi      r3, r29, 0x4
	  bl        -0x92F0
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x71C
	  stw       r0, 0xEC(r31)

	.loc_0x71C:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0x74C:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x111F8
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x6372
	  addi      r4, r3, 0x5F31
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17A8C0
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0x898
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x111EC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x2210
	  addi      r0, r30, 0x10A
	  stw       r0, 0x4(r28)
	  li        r0, 0x1
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x83C
	  addi      r3, r29, 0x4
	  bl        -0x940C
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x868
	  stw       r0, 0xEC(r31)
	  b         .loc_0x868

	.loc_0x83C:
	  addi      r3, r29, 0x4
	  bl        -0x943C
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x868
	  stw       r0, 0xEC(r31)

	.loc_0x868:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0x898:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x11344
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x636C
	  addi      r4, r3, 0x5F32
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17AA0C
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0x9E4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x11338
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x235C
	  addi      r0, r30, 0x10C
	  stw       r0, 0x4(r28)
	  li        r0, 0x64
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x988
	  addi      r3, r29, 0x4
	  bl        -0x9558
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x9B4
	  stw       r0, 0xEC(r31)
	  b         .loc_0x9B4

	.loc_0x988:
	  addi      r3, r29, 0x4
	  bl        -0x9588
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x9B4
	  stw       r0, 0xEC(r31)

	.loc_0x9B4:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0x9E4:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x11490
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x6363
	  addi      r4, r3, 0x5F32
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17AB58
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0xB30
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x11484
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x24A8
	  addi      r0, r30, 0x10C
	  stw       r0, 0x4(r28)
	  li        r0, 0xA
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0xAD4
	  addi      r3, r29, 0x4
	  bl        -0x96A4
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xB00
	  stw       r0, 0xEC(r31)
	  b         .loc_0xB00

	.loc_0xAD4:
	  addi      r3, r29, 0x4
	  bl        -0x96D4
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xB00
	  stw       r0, 0xEC(r31)

	.loc_0xB00:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0xB30:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x115DC
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x6372
	  addi      r4, r3, 0x5F32
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17ACA4
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0xC7C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x115D0
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x25F4
	  addi      r0, r30, 0x10C
	  stw       r0, 0x4(r28)
	  li        r0, 0x1
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0xC20
	  addi      r3, r29, 0x4
	  bl        -0x97F0
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xC4C
	  stw       r0, 0xEC(r31)
	  b         .loc_0xC4C

	.loc_0xC20:
	  addi      r3, r29, 0x4
	  bl        -0x9820
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xC4C
	  stw       r0, 0xEC(r31)

	.loc_0xC4C:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0xC7C:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x11728
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x636C
	  addi      r4, r3, 0x5F33
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17ADF0
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0xDC8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x1171C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x2740
	  addi      r0, r30, 0x10E
	  stw       r0, 0x4(r28)
	  li        r0, 0x64
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0xD6C
	  addi      r3, r29, 0x4
	  bl        -0x993C
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xD98
	  stw       r0, 0xEC(r31)
	  b         .loc_0xD98

	.loc_0xD6C:
	  addi      r3, r29, 0x4
	  bl        -0x996C
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xD98
	  stw       r0, 0xEC(r31)

	.loc_0xD98:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0xDC8:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x11874
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x6363
	  addi      r4, r3, 0x5F33
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17AF3C
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0xF14
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x11868
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x288C
	  addi      r0, r30, 0x10E
	  stw       r0, 0x4(r28)
	  li        r0, 0xA
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0xEB8
	  addi      r3, r29, 0x4
	  bl        -0x9A88
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xEE4
	  stw       r0, 0xEC(r31)
	  b         .loc_0xEE4

	.loc_0xEB8:
	  addi      r3, r29, 0x4
	  bl        -0x9AB8
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xEE4
	  stw       r0, 0xEC(r31)

	.loc_0xEE4:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0xF14:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x119C0
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x6372
	  addi      r4, r3, 0x5F33
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17B088
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0x1060
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x119B4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x29D8
	  addi      r0, r30, 0x10E
	  stw       r0, 0x4(r28)
	  li        r0, 0x1
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x1004
	  addi      r3, r29, 0x4
	  bl        -0x9BD4
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1030
	  stw       r0, 0xEC(r31)
	  b         .loc_0x1030

	.loc_0x1004:
	  addi      r3, r29, 0x4
	  bl        -0x9C04
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1030
	  stw       r0, 0xEC(r31)

	.loc_0x1030:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0x1060:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x11B0C
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x636C
	  addi      r4, r3, 0x5F34
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17B1D4
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0x11AC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x11B00
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x2B24
	  addi      r0, r30, 0x110
	  stw       r0, 0x4(r28)
	  li        r0, 0x64
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x1150
	  addi      r3, r29, 0x4
	  bl        -0x9D20
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x117C
	  stw       r0, 0xEC(r31)
	  b         .loc_0x117C

	.loc_0x1150:
	  addi      r3, r29, 0x4
	  bl        -0x9D50
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x117C
	  stw       r0, 0xEC(r31)

	.loc_0x117C:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0x11AC:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x11C58
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x6363
	  addi      r4, r3, 0x5F34
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17B320
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0x12F8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x11C4C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x2C70
	  addi      r0, r30, 0x110
	  stw       r0, 0x4(r28)
	  li        r0, 0xA
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x129C
	  addi      r3, r29, 0x4
	  bl        -0x9E6C
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x12C8
	  stw       r0, 0xEC(r31)
	  b         .loc_0x12C8

	.loc_0x129C:
	  addi      r3, r29, 0x4
	  bl        -0x9E9C
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x12C8
	  stw       r0, 0xEC(r31)

	.loc_0x12C8:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0x12F8:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x11DA4
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x6372
	  addi      r4, r3, 0x5F34
	  addi      r3, r30, 0x4
	  lwz       r12, 0x4(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17B46C
	  addi      r28, r3, 0
	  mr.       r29, r28
	  beq-      .loc_0x1444
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r28)
	  addi      r4, r31, 0
	  addi      r3, r29, 0x4
	  li        r5, 0x12
	  bl        -0x11D98
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r28)
	  addi      r3, r29, 0x4
	  bl        -0x2DBC
	  addi      r0, r30, 0x110
	  stw       r0, 0x4(r28)
	  li        r0, 0x1
	  lis       r3, 0x802E
	  stw       r0, 0x8(r28)
	  addi      r0, r3, 0x1054
	  li        r4, 0
	  stw       r0, 0x0(r28)
	  stb       r4, 0x14(r28)
	  lwz       r3, 0x4(r28)
	  lha       r0, 0x0(r3)
	  sth       r0, 0x10(r28)
	  sth       r4, 0x12(r28)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0xC(r28)
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x13E8
	  addi      r3, r29, 0x4
	  bl        -0x9FB8
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1414
	  stw       r0, 0xEC(r31)
	  b         .loc_0x1414

	.loc_0x13E8:
	  addi      r3, r29, 0x4
	  bl        -0x9FE8
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1414
	  stw       r0, 0xEC(r31)

	.loc_0x1414:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0x1444:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x11EF0
	  lwz       r3, 0x8(r1)
	  lwz       r0, 0x23C(r1)
	  lwz       r31, 0x234(r1)
	  lwz       r30, 0x230(r1)
	  lwz       r29, 0x22C(r1)
	  lwz       r28, 0x228(r1)
	  addi      r1, r1, 0x238
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
zen::DrawScreen::~DrawScreen()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801C25B4
 * Size:	000124
 */
void zen::DrawAccount::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lbz       r0, 0x11C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x10C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x100(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x100(r31)
	  lfs       f0, 0x100(r31)
	  lfs       f1, 0x104(r31)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x4C
	  stfs      f1, 0x100(r31)

	.loc_0x4C:
	  lfs       f2, -0x46A8(r2)
	  lfs       f1, 0x100(r31)
	  lfs       f0, 0x104(r31)
	  fmuls     f1, f2, f1
	  fdivs     f1, f1, f0
	  bl        0x59540
	  lfs       f3, -0x46A0(r2)
	  lfs       f4, -0x46A4(r2)
	  fsubs     f2, f3, f1
	  lfs       f1, -0x469C(r2)
	  lfs       f0, -0x46B0(r2)
	  fmuls     f31, f4, f2
	  fsubs     f2, f3, f31
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x98
	  fadds     f0, f4, f1
	  b         .loc_0x9C

	.loc_0x98:
	  fsubs     f0, f1, f4

	.loc_0x9C:
	  lwz       r3, 0x114(r31)
	  fctiwz    f0, f0
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x20(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r5, 0x24(r1)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x4698(r2)
	  lfs       f0, -0x46B0(r2)
	  fmuls     f1, f1, f31
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xE4
	  lfs       f0, -0x46A4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xEC

	.loc_0xE4:
	  lfs       f0, -0x46A4(r2)
	  fsubs     f0, f1, f0

	.loc_0xEC:
	  fctiwz    f0, f0
	  lwz       r3, 0x118(r31)
	  stfd      f0, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  rlwinm    r4,r0,0,24,31
	  bl        -0x2DDC
	  mr        r3, r31
	  bl        -0x3040

	.loc_0x10C:
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C26D8
 * Size:	00002C
 */
void zen::DrawAccount::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x11C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C
	  bl        -0x3050

	.loc_0x1C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C2704
 * Size:	000078
 */
void zen::DrawAccount::start(zen::AccountData&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, -0x3E8
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  li        r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  stb       r0, 0x11C(r3)
	  lfs       f0, -0x46B0(r2)
	  stfs      f0, 0x100(r3)
	  lwz       r3, 0x114(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x4(r31)
	  stw       r3, 0x108(r30)
	  stw       r0, 0x10C(r30)
	  lhz       r0, 0x8(r31)
	  sth       r0, 0x110(r30)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
