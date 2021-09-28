

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
 * Address:	801B6338
 * Size:	001FCC
 */
void zen::DrawGameInfo::DrawGameInfo(zen::DrawGameInfo::playModeFlag)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x438(r1)
  stfd      f31, 0x430(r1)
  stmw      r21, 0x404(r1)
  li        r25, 0
  addi      r31, r3, 0
  addi      r28, r4, 0
  stw       r25, 0xC(r3)
  lis       r3, 0x802E
  addi      r29, r3, 0x9B0
  sth       r25, 0x10(r31)
  addi      r3, r31, 0x18
  sth       r25, 0x12(r31)
  sth       r25, 0x14(r31)
  bl        0x3B180
  li        r3, 0x104
  bl        -0x16F378
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x10C
  stw       r30, 0x3B4(r1)
  addi      r21, r30, 0xC
  addi      r3, r1, 0x38C
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        -0x2D80
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x38C
  addi      r3, r21, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        -0x59FC
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r21)
  addi      r4, r29, 0x238
  li        r5, 0x1
  stb       r25, 0xEC(r21)
  li        r6, 0x1
  li        r7, 0x1
  stw       r25, 0xF0(r21)
  stw       r25, 0xF4(r21)
  lwz       r24, 0x3B4(r1)
  lfs       f0, -0x48C8(r2)
  addi      r3, r24, 0xC
  stfs      f0, 0x4(r24)
  lfs       f0, -0x48C4(r2)
  stfs      f0, 0x8(r24)
  stw       r25, 0x0(r24)
  bl        -0x3810
  lha       r5, 0x26(r24)
  lha       r4, 0x2A(r24)
  lha       r3, 0x24(r24)
  lha       r0, 0x28(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xC4(r24)
  extsh     r0, r4
  sth       r0, 0xC6(r24)

.loc_0x10C:
  stw       r30, 0x0(r31)
  li        r3, 0x104
  bl        -0x16F448
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x1E0
  stw       r30, 0x3B0(r1)
  addi      r21, r30, 0xC
  addi      r3, r1, 0x380
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        -0x2E50
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x380
  addi      r3, r21, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        -0x5ACC
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r21)
  li        r0, 0
  addi      r4, r29, 0x250
  stb       r0, 0xEC(r21)
  li        r5, 0x1
  li        r6, 0x1
  stw       r0, 0xF0(r21)
  li        r7, 0x1
  stw       r0, 0xF4(r21)
  lwz       r24, 0x3B0(r1)
  lfs       f0, -0x48C8(r2)
  addi      r3, r24, 0xC
  stfs      f0, 0x4(r24)
  lfs       f0, -0x48C4(r2)
  stfs      f0, 0x8(r24)
  stw       r0, 0x0(r24)
  bl        -0x38E4
  lha       r5, 0x26(r24)
  lha       r4, 0x2A(r24)
  lha       r3, 0x24(r24)
  lha       r0, 0x28(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xC4(r24)
  extsh     r0, r4
  sth       r0, 0xC6(r24)

.loc_0x1E0:
  cmpwi     r28, 0x1
  stw       r30, 0x4(r31)
  beq-      .loc_0x2D4
  bge-      .loc_0x3A8
  cmpwi     r28, 0
  bge-      .loc_0x1FC
  b         .loc_0x3A8

.loc_0x1FC:
  li        r3, 0x104
  bl        -0x16F534
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x2CC
  stw       r30, 0x3AC(r1)
  addi      r21, r30, 0xC
  addi      r3, r1, 0x374
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        -0x2F3C
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x374
  addi      r3, r21, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        -0x5BB8
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r21)
  li        r0, 0
  addi      r4, r29, 0x268
  stb       r0, 0xEC(r21)
  li        r5, 0x1
  li        r6, 0x1
  stw       r0, 0xF0(r21)
  li        r7, 0x1
  stw       r0, 0xF4(r21)
  lwz       r24, 0x3AC(r1)
  lfs       f0, -0x48C8(r2)
  addi      r3, r24, 0xC
  stfs      f0, 0x4(r24)
  lfs       f0, -0x48C4(r2)
  stfs      f0, 0x8(r24)
  stw       r0, 0x0(r24)
  bl        -0x39D0
  lha       r5, 0x26(r24)
  lha       r4, 0x2A(r24)
  lha       r3, 0x24(r24)
  lha       r0, 0x28(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xC4(r24)
  extsh     r0, r4
  sth       r0, 0xC6(r24)

.loc_0x2CC:
  stw       r30, 0x8(r31)
  b         .loc_0x3A8

.loc_0x2D4:
  li        r3, 0x104
  bl        -0x16F60C
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x3A4
  stw       r30, 0x3A8(r1)
  addi      r21, r30, 0xC
  addi      r3, r1, 0x368
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        -0x3014
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x368
  addi      r3, r21, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        -0x5C90
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r21)
  li        r0, 0
  addi      r4, r29, 0x280
  stb       r0, 0xEC(r21)
  li        r5, 0x1
  li        r6, 0x1
  stw       r0, 0xF0(r21)
  li        r7, 0x1
  stw       r0, 0xF4(r21)
  lwz       r24, 0x3A8(r1)
  lfs       f0, -0x48C8(r2)
  addi      r3, r24, 0xC
  stfs      f0, 0x4(r24)
  lfs       f0, -0x48C4(r2)
  stfs      f0, 0x8(r24)
  stw       r0, 0x0(r24)
  bl        -0x3AA8
  lha       r5, 0x26(r24)
  lha       r4, 0x2A(r24)
  lha       r3, 0x24(r24)
  lha       r0, 0x28(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xC4(r24)
  extsh     r0, r4
  sth       r0, 0xC6(r24)

.loc_0x3A4:
  stw       r30, 0x8(r31)

.loc_0x3A8:
  addi      r0, r31, 0xC
  stw       r0, 0x31A0(r13)
  lis       r3, 0x7069
  addi      r4, r3, 0x6B69
  lwz       r3, 0x8(r31)
  li        r5, 0x1
  lwzu      r12, 0xC(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r30, r3, 0
  mr.       r24, r30
  beq-      .loc_0x4CC
  li        r3, 0x58
  bl        -0x16F714
  addi      r27, r3, 0
  mr.       r25, r27
  beq-      .loc_0x4C0
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r27)
  addi      r4, r24, 0
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x6040
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  lis       r3, 0x802E
  stw       r0, 0x0(r27)
  addi      r0, r3, 0x10EC
  stw       r0, 0x0(r27)
  li        r26, 0
  rlwinm    r0,r26,2,0,29
  lfs       f0, 0x1980(r13)
  add       r23, r29, r0
  addi      r22, r27, 0
  stfs      f0, 0x4(r27)
  addi      r21, r26, 0
  addi      r23, r23, 0x1EC

.loc_0x444:
  lwz       r3, 0x0(r23)
  li        r4, 0x1
  li        r5, 0x1
  bl        0x3BE58
  cmplwi    r3, 0
  stw       r3, 0x8(r22)
  addi      r26, r26, 0x1
  cmpwi     r26, 0x13
  addi      r23, r23, 0x4
  addi      r22, r22, 0x4
  addi      r21, r21, 0x4
  blt+      .loc_0x444
  lbz       r0, 0xF1(r30)
  lwz       r3, 0x8(r27)
  cmplwi    r0, 0
  ble-      .loc_0x488
  stw       r3, 0xEC(r30)

.loc_0x488:
  lha       r4, 0x18(r30)
  li        r0, 0
  lha       r3, 0x1C(r30)
  lha       r5, 0x1A(r30)
  sub       r3, r3, r4
  lha       r4, 0x1E(r30)
  srawi     r3, r3, 0x1
  sub       r5, r4, r5
  extsh     r4, r3
  srawi     r3, r5, 0x1
  sth       r4, 0xB8(r30)
  extsh     r3, r3
  sth       r3, 0xBA(r30)
  stw       r0, 0x54(r27)

.loc_0x4C0:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x6164

.loc_0x4CC:
  lwz       r5, 0x8(r31)
  lis       r3, 0x775F
  addi      r4, r3, 0x3030
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lhz       r0, 0x8(r3)
  cmplwi    r0, 0x12
  bne-      .loc_0x538
  li        r5, 0
  stb       r5, 0x3D0(r1)
  li        r4, 0x99
  li        r0, 0xFF
  stb       r5, 0x3D1(r1)
  stb       r5, 0x3D2(r1)
  stb       r5, 0x3D3(r1)
  lwz       r5, 0x3D0(r1)
  stw       r5, 0x10C(r3)
  stb       r4, 0x3C8(r1)
  stb       r0, 0x3C9(r1)
  stb       r4, 0x3CA(r1)
  stb       r0, 0x3CB(r1)
  lwz       r0, 0x3C8(r1)
  stw       r0, 0x108(r3)

.loc_0x538:
  lwz       r5, 0x8(r31)
  lis       r3, 0x785F
  addi      r4, r3, 0x3030
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lhz       r0, 0x8(r3)
  cmplwi    r0, 0x12
  bne-      .loc_0x5A4
  li        r5, 0
  stb       r5, 0x3C0(r1)
  li        r4, 0x99
  li        r0, 0xFF
  stb       r5, 0x3C1(r1)
  stb       r5, 0x3C2(r1)
  stb       r5, 0x3C3(r1)
  lwz       r5, 0x3C0(r1)
  stw       r5, 0x10C(r3)
  stb       r4, 0x3B8(r1)
  stb       r0, 0x3B9(r1)
  stb       r4, 0x3BA(r1)
  stb       r0, 0x3BB(r1)
  lwz       r0, 0x3B8(r1)
  stw       r0, 0x108(r3)

.loc_0x5A4:
  lwz       r5, 0x8(r31)
  lis       r3, 0x775F
  addi      r4, r3, 0x3031
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r21, r3, 0
  li        r3, 0xC
  bl        -0x16F904
  addi      r24, r3, 0
  mr.       r22, r24
  beq-      .loc_0x620
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r24)
  addi      r4, r21, 0
  addi      r3, r22, 0x4
  li        r5, 0x12
  bl        -0x6230
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  lis       r3, 0x802E
  stw       r0, 0x0(r24)
  addi      r0, r3, 0x10A4
  stw       r0, 0x0(r24)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0x4(r24)
  stfs      f0, 0x8(r24)

.loc_0x620:
  addi      r3, r21, 0
  addi      r4, r22, 0
  bl        -0x62C4
  lwz       r5, 0x8(r31)
  lis       r3, 0x635F
  addi      r4, r3, 0x6D6C
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x18
  bl        -0x16F98C
  mr.       r25, r3
  beq-      .loc_0x76C
  lwz       r5, 0x31A0(r13)
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r26, r5, 0x4
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x62BC
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  bl        0x8D20
  stw       r26, 0x4(r25)
  li        r0, 0x64
  lis       r3, 0x802E
  stw       r0, 0x8(r25)
  addi      r0, r3, 0x1054
  li        r4, 0
  stw       r0, 0x0(r25)
  stb       r4, 0x14(r25)
  lwz       r3, 0x4(r25)
  lha       r0, 0x0(r3)
  sth       r0, 0x10(r25)
  sth       r4, 0x12(r25)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0xC(r25)
  lbz       r0, 0x14(r25)
  cmplwi    r0, 0
  beq-      .loc_0x710
  addi      r3, r25, 0x4
  bl        0x1B28
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x73C
  stw       r0, 0xEC(r24)
  b         .loc_0x73C

.loc_0x710:
  addi      r3, r25, 0x4
  bl        0x1AF8
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x73C
  stw       r0, 0xEC(r24)

.loc_0x73C:
  lha       r5, 0x1A(r24)
  lha       r4, 0x1E(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r24)
  extsh     r0, r4
  sth       r0, 0xBA(r24)

.loc_0x76C:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x6410
  lwz       r5, 0x8(r31)
  lis       r3, 0x635F
  addi      r4, r3, 0x6D63
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x18
  bl        -0x16FAD8
  mr.       r25, r3
  beq-      .loc_0x8B8
  lwz       r5, 0x31A0(r13)
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r26, r5, 0x4
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x6408
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  bl        0x8BD4
  stw       r26, 0x4(r25)
  li        r0, 0xA
  lis       r3, 0x802E
  stw       r0, 0x8(r25)
  addi      r0, r3, 0x1054
  li        r4, 0
  stw       r0, 0x0(r25)
  stb       r4, 0x14(r25)
  lwz       r3, 0x4(r25)
  lha       r0, 0x0(r3)
  sth       r0, 0x10(r25)
  sth       r4, 0x12(r25)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0xC(r25)
  lbz       r0, 0x14(r25)
  cmplwi    r0, 0
  beq-      .loc_0x85C
  addi      r3, r25, 0x4
  bl        0x19DC
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x888
  stw       r0, 0xEC(r24)
  b         .loc_0x888

.loc_0x85C:
  addi      r3, r25, 0x4
  bl        0x19AC
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x888
  stw       r0, 0xEC(r24)

.loc_0x888:
  lha       r5, 0x1A(r24)
  lha       r4, 0x1E(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r24)
  extsh     r0, r4
  sth       r0, 0xBA(r24)

.loc_0x8B8:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x655C
  lwz       r5, 0x8(r31)
  lis       r3, 0x635F
  addi      r4, r3, 0x6D72
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x18
  bl        -0x16FC24
  mr.       r25, r3
  beq-      .loc_0xA04
  lwz       r5, 0x31A0(r13)
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r26, r5, 0x4
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x6554
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  bl        0x8A88
  stw       r26, 0x4(r25)
  li        r0, 0x1
  lis       r3, 0x802E
  stw       r0, 0x8(r25)
  addi      r0, r3, 0x1054
  li        r4, 0
  stw       r0, 0x0(r25)
  stb       r4, 0x14(r25)
  lwz       r3, 0x4(r25)
  lha       r0, 0x0(r3)
  sth       r0, 0x10(r25)
  sth       r4, 0x12(r25)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0xC(r25)
  lbz       r0, 0x14(r25)
  cmplwi    r0, 0
  beq-      .loc_0x9A8
  addi      r3, r25, 0x4
  bl        0x1890
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x9D4
  stw       r0, 0xEC(r24)
  b         .loc_0x9D4

.loc_0x9A8:
  addi      r3, r25, 0x4
  bl        0x1860
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x9D4
  stw       r0, 0xEC(r24)

.loc_0x9D4:
  lha       r5, 0x1A(r24)
  lha       r4, 0x1E(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r24)
  extsh     r0, r4
  sth       r0, 0xBA(r24)

.loc_0xA04:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x66A8
  lwz       r5, 0x8(r31)
  lis       r3, 0x635F
  addi      r4, r3, 0x6C6C
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x18
  bl        -0x16FD70
  mr.       r25, r3
  beq-      .loc_0xB50
  lwz       r5, 0x31A0(r13)
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r26, r5, 0x6
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x66A0
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  bl        0x893C
  stw       r26, 0x4(r25)
  li        r0, 0x64
  lis       r3, 0x802E
  stw       r0, 0x8(r25)
  addi      r0, r3, 0x1054
  li        r4, 0
  stw       r0, 0x0(r25)
  stb       r4, 0x14(r25)
  lwz       r3, 0x4(r25)
  lha       r0, 0x0(r3)
  sth       r0, 0x10(r25)
  sth       r4, 0x12(r25)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0xC(r25)
  lbz       r0, 0x14(r25)
  cmplwi    r0, 0
  beq-      .loc_0xAF4
  addi      r3, r25, 0x4
  bl        0x1744
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0xB20
  stw       r0, 0xEC(r24)
  b         .loc_0xB20

.loc_0xAF4:
  addi      r3, r25, 0x4
  bl        0x1714
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0xB20
  stw       r0, 0xEC(r24)

.loc_0xB20:
  lha       r5, 0x1A(r24)
  lha       r4, 0x1E(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r24)
  extsh     r0, r4
  sth       r0, 0xBA(r24)

.loc_0xB50:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x67F4
  lwz       r5, 0x8(r31)
  lis       r3, 0x635F
  addi      r4, r3, 0x6C63
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x18
  bl        -0x16FEBC
  mr.       r25, r3
  beq-      .loc_0xC9C
  lwz       r5, 0x31A0(r13)
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r26, r5, 0x6
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x67EC
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  bl        0x87F0
  stw       r26, 0x4(r25)
  li        r0, 0xA
  lis       r3, 0x802E
  stw       r0, 0x8(r25)
  addi      r0, r3, 0x1054
  li        r4, 0
  stw       r0, 0x0(r25)
  stb       r4, 0x14(r25)
  lwz       r3, 0x4(r25)
  lha       r0, 0x0(r3)
  sth       r0, 0x10(r25)
  sth       r4, 0x12(r25)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0xC(r25)
  lbz       r0, 0x14(r25)
  cmplwi    r0, 0
  beq-      .loc_0xC40
  addi      r3, r25, 0x4
  bl        0x15F8
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0xC6C
  stw       r0, 0xEC(r24)
  b         .loc_0xC6C

.loc_0xC40:
  addi      r3, r25, 0x4
  bl        0x15C8
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0xC6C
  stw       r0, 0xEC(r24)

.loc_0xC6C:
  lha       r5, 0x1A(r24)
  lha       r4, 0x1E(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r24)
  extsh     r0, r4
  sth       r0, 0xBA(r24)

.loc_0xC9C:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x6940
  lwz       r5, 0x8(r31)
  lis       r3, 0x635F
  addi      r4, r3, 0x6C72
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x18
  bl        -0x170008
  mr.       r25, r3
  beq-      .loc_0xDE8
  lwz       r5, 0x31A0(r13)
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r26, r5, 0x6
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x6938
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  bl        0x86A4
  stw       r26, 0x4(r25)
  li        r0, 0x1
  lis       r3, 0x802E
  stw       r0, 0x8(r25)
  addi      r0, r3, 0x1054
  li        r4, 0
  stw       r0, 0x0(r25)
  stb       r4, 0x14(r25)
  lwz       r3, 0x4(r25)
  lha       r0, 0x0(r3)
  sth       r0, 0x10(r25)
  sth       r4, 0x12(r25)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0xC(r25)
  lbz       r0, 0x14(r25)
  cmplwi    r0, 0
  beq-      .loc_0xD8C
  addi      r3, r25, 0x4
  bl        0x14AC
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0xDB8
  stw       r0, 0xEC(r24)
  b         .loc_0xDB8

.loc_0xD8C:
  addi      r3, r25, 0x4
  bl        0x147C
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0xDB8
  stw       r0, 0xEC(r24)

.loc_0xDB8:
  lha       r5, 0x1A(r24)
  lha       r4, 0x1E(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r24)
  extsh     r0, r4
  sth       r0, 0xBA(r24)

.loc_0xDE8:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x6A8C
  lwz       r5, 0x8(r31)
  lis       r3, 0x635F
  addi      r4, r3, 0x736C
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x18
  bl        -0x170154
  mr.       r25, r3
  beq-      .loc_0xF34
  lwz       r5, 0x31A0(r13)
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r26, r5, 0x8
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x6A84
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  bl        0x8558
  stw       r26, 0x4(r25)
  li        r0, 0x3E8
  lis       r3, 0x802E
  stw       r0, 0x8(r25)
  addi      r0, r3, 0x1054
  li        r4, 0
  stw       r0, 0x0(r25)
  stb       r4, 0x14(r25)
  lwz       r3, 0x4(r25)
  lha       r0, 0x0(r3)
  sth       r0, 0x10(r25)
  sth       r4, 0x12(r25)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0xC(r25)
  lbz       r0, 0x14(r25)
  cmplwi    r0, 0
  beq-      .loc_0xED8
  addi      r3, r25, 0x4
  bl        0x1360
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0xF04
  stw       r0, 0xEC(r24)
  b         .loc_0xF04

.loc_0xED8:
  addi      r3, r25, 0x4
  bl        0x1330
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0xF04
  stw       r0, 0xEC(r24)

.loc_0xF04:
  lha       r5, 0x1A(r24)
  lha       r4, 0x1E(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r24)
  extsh     r0, r4
  sth       r0, 0xBA(r24)

.loc_0xF34:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x6BD8
  lwz       r5, 0x8(r31)
  lis       r3, 0x635F
  addi      r4, r3, 0x7363
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x18
  bl        -0x1702A0
  mr.       r25, r3
  beq-      .loc_0x1080
  lwz       r5, 0x31A0(r13)
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r26, r5, 0x8
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x6BD0
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  bl        0x840C
  stw       r26, 0x4(r25)
  li        r0, 0x64
  lis       r3, 0x802E
  stw       r0, 0x8(r25)
  addi      r0, r3, 0x1054
  li        r4, 0
  stw       r0, 0x0(r25)
  stb       r4, 0x14(r25)
  lwz       r3, 0x4(r25)
  lha       r0, 0x0(r3)
  sth       r0, 0x10(r25)
  sth       r4, 0x12(r25)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0xC(r25)
  lbz       r0, 0x14(r25)
  cmplwi    r0, 0
  beq-      .loc_0x1024
  addi      r3, r25, 0x4
  bl        0x1214
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x1050
  stw       r0, 0xEC(r24)
  b         .loc_0x1050

.loc_0x1024:
  addi      r3, r25, 0x4
  bl        0x11E4
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x1050
  stw       r0, 0xEC(r24)

.loc_0x1050:
  lha       r5, 0x1A(r24)
  lha       r4, 0x1E(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r24)
  extsh     r0, r4
  sth       r0, 0xBA(r24)

.loc_0x1080:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x6D24
  lwz       r5, 0x8(r31)
  lis       r3, 0x635F
  addi      r4, r3, 0x7372
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x18
  bl        -0x1703EC
  mr.       r25, r3
  beq-      .loc_0x11CC
  lwz       r5, 0x31A0(r13)
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r26, r5, 0x8
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x6D1C
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  bl        0x82C0
  stw       r26, 0x4(r25)
  li        r0, 0xA
  lis       r3, 0x802E
  stw       r0, 0x8(r25)
  addi      r0, r3, 0x1054
  li        r4, 0
  stw       r0, 0x0(r25)
  stb       r4, 0x14(r25)
  lwz       r3, 0x4(r25)
  lha       r0, 0x0(r3)
  sth       r0, 0x10(r25)
  sth       r4, 0x12(r25)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0xC(r25)
  lbz       r0, 0x14(r25)
  cmplwi    r0, 0
  beq-      .loc_0x1170
  addi      r3, r25, 0x4
  bl        0x10C8
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x119C
  stw       r0, 0xEC(r24)
  b         .loc_0x119C

.loc_0x1170:
  addi      r3, r25, 0x4
  bl        0x1098
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x119C
  stw       r0, 0xEC(r24)

.loc_0x119C:
  lha       r5, 0x1A(r24)
  lha       r4, 0x1E(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r24)
  extsh     r0, r4
  sth       r0, 0xBA(r24)

.loc_0x11CC:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x6E70
  lwz       r5, 0x8(r31)
  lis       r3, 0x635F
  addi      r4, r3, 0x7331
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x18
  bl        -0x170538
  mr.       r25, r3
  beq-      .loc_0x1318
  lwz       r5, 0x31A0(r13)
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r26, r5, 0x8
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x6E68
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  bl        0x8174
  stw       r26, 0x4(r25)
  li        r0, 0x1
  lis       r3, 0x802E
  stw       r0, 0x8(r25)
  addi      r0, r3, 0x1054
  li        r4, 0
  stw       r0, 0x0(r25)
  stb       r4, 0x14(r25)
  lwz       r3, 0x4(r25)
  lha       r0, 0x0(r3)
  sth       r0, 0x10(r25)
  sth       r4, 0x12(r25)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0xC(r25)
  lbz       r0, 0x14(r25)
  cmplwi    r0, 0
  beq-      .loc_0x12BC
  addi      r3, r25, 0x4
  bl        0xF7C
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x12E8
  stw       r0, 0xEC(r24)
  b         .loc_0x12E8

.loc_0x12BC:
  addi      r3, r25, 0x4
  bl        0xF4C
  lbz       r0, 0xF1(r24)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x12E8
  stw       r0, 0xEC(r24)

.loc_0x12E8:
  lha       r5, 0x1A(r24)
  lha       r4, 0x1E(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r24)
  extsh     r0, r4
  sth       r0, 0xBA(r24)

.loc_0x1318:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x6FBC
  lwz       r5, 0x0(r31)
  lis       r3, 0x7374
  addi      r4, r3, 0x6174
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r5, 0x0(r31)
  addi      r30, r3, 0
  lis       r4, 0x676F
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  addi      r4, r4, 0x616C
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r5, 0x0(r31)
  addi      r29, r3, 0
  lis       r4, 0x7375
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  addi      r4, r4, 0x6E69
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  addi      r24, r3, 0
  beq-      .loc_0x14E4
  cmplwi    r30, 0
  beq-      .loc_0x14E4
  cmplwi    r29, 0
  beq-      .loc_0x14E4
  li        r3, 0x28
  bl        -0x1706EC
  addi      r27, r3, 0
  mr.       r21, r27
  beq-      .loc_0x14CC
  addi      r4, r30, 0x18
  addi      r3, r1, 0x31C
  bl        -0x40BC
  addi      r4, r29, 0x18
  addi      r3, r1, 0x324
  bl        -0x40C8
  lha       r4, 0x31C(r1)
  lis       r8, 0x4330
  lha       r0, 0x320(r1)
  lis       r3, 0x802D
  lfd       f3, -0x48B0(r2)
  add       r0, r4, r0
  srawi     r0, r0, 0x1
  fmr       f2, f3
  xoris     r0, r0, 0x8000
  fmr       f1, f3
  stw       r0, 0x3FC(r1)
  addi      r0, r3, 0x3004
  stw       r8, 0x3F8(r1)
  addi      r3, r21, 0x14
  li        r4, 0
  lfd       f0, 0x3F8(r1)
  li        r5, 0x10
  fsubs     f0, f0, f3
  stfs      f0, 0x0(r27)
  lha       r7, 0x31E(r1)
  lha       r6, 0x322(r1)
  add       r6, r7, r6
  srawi     r6, r6, 0x1
  xoris     r6, r6, 0x8000
  stw       r6, 0x3F4(r1)
  stw       r8, 0x3F0(r1)
  lfd       f0, 0x3F0(r1)
  fsubs     f0, f0, f3
  stfs      f0, 0x4(r27)
  lha       r7, 0x324(r1)
  lha       r6, 0x328(r1)
  add       r6, r7, r6
  srawi     r6, r6, 0x1
  xoris     r6, r6, 0x8000
  stw       r6, 0x3EC(r1)
  stw       r8, 0x3E8(r1)
  lfd       f0, 0x3E8(r1)
  fsubs     f0, f0, f2
  stfs      f0, 0x8(r27)
  lha       r7, 0x326(r1)
  lha       r6, 0x32A(r1)
  add       r6, r7, r6
  srawi     r6, r6, 0x1
  xoris     r6, r6, 0x8000
  stw       r6, 0x3E4(r1)
  stw       r8, 0x3E0(r1)
  lfd       f0, 0x3E0(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0xC(r27)
  stw       r0, 0x10(r27)
  bl        -0x70E0
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  lis       r3, 0x802E
  stw       r0, 0x10(r27)
  addi      r3, r3, 0xFC8
  stw       r3, 0x14(r27)
  addi      r0, r3, 0x8
  stw       r0, 0x10(r27)

.loc_0x14CC:
  cmplwi    r27, 0
  beq-      .loc_0x14D8
  addi      r27, r27, 0x10

.loc_0x14D8:
  addi      r3, r24, 0
  addi      r4, r27, 0
  bl        -0x717C

.loc_0x14E4:
  lwz       r5, 0x0(r31)
  lis       r3, 0x7375
  addi      r4, r3, 0x6E63
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  mr.       r21, r3
  beq-      .loc_0x156C
  li        r3, 0x8
  bl        -0x170848
  addi      r24, r3, 0
  mr.       r22, r24
  beq-      .loc_0x1560
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r24)
  addi      r4, r21, 0
  addi      r3, r22, 0x4
  li        r5, 0x12
  bl        -0x7174
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  lis       r3, 0x802E
  stw       r0, 0x0(r24)
  addi      r0, r3, 0xF78
  stw       r0, 0x0(r24)
  li        r0, 0
  sth       r0, 0x4(r24)

.loc_0x1560:
  addi      r3, r21, 0
  addi      r4, r22, 0
  bl        -0x7204

.loc_0x156C:
  lwz       r5, 0x0(r31)
  lis       r3, 0x7375
  addi      r4, r3, 0x6E31
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  mr.       r24, r3
  beq-      .loc_0x1630
  li        r3, 0xC
  bl        -0x1708D0
  addi      r27, r3, 0
  mr.       r25, r27
  beq-      .loc_0x1624
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r27)
  addi      r4, r24, 0
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x71FC
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r27)
  addi      r3, r24, 0x18
  bl        0xC24
  addi      r26, r3, 0
  addi      r3, r24, 0x18
  bl        0xC08
  srawi     r0, r3, 0x1
  extsh     r3, r0
  srawi     r0, r26, 0x1
  sth       r3, 0xB8(r24)
  extsh     r0, r0
  sth       r0, 0xBA(r24)
  addi      r3, r24, 0
  li        r4, 0x2
  lfs       f1, -0x48C0(r2)
  bl        -0x31138
  lfs       f0, -0x48BC(r2)
  lis       r3, 0x802E
  addi      r0, r3, 0xF2C
  stfs      f0, 0x4(r27)
  stw       r0, 0x0(r27)

.loc_0x1624:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x72C8

.loc_0x1630:
  cmplwi    r30, 0
  beq-      .loc_0x17C4
  cmplwi    r29, 0
  beq-      .loc_0x17C4
  lwz       r5, 0x0(r31)
  lis       r3, 0x7375
  addi      r4, r3, 0x6E32
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  mr.       r24, r3
  beq-      .loc_0x17C4
  li        r3, 0x18
  bl        -0x1709A4
  addi      r27, r3, 0
  mr.       r25, r27
  beq-      .loc_0x17B8
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r27)
  addi      r4, r24, 0
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x72D0
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r27)
  addi      r4, r30, 0x18
  addi      r3, r1, 0x30C
  bl        -0x439C
  addi      r4, r29, 0x18
  addi      r3, r1, 0x314
  bl        -0x43A8
  lha       r4, 0x30C(r1)
  lis       r5, 0x4330
  lha       r0, 0x310(r1)
  addi      r3, r24, 0x18
  lfd       f1, -0x48B0(r2)
  add       r0, r4, r0
  srawi     r0, r0, 0x1
  xoris     r0, r0, 0x8000
  stw       r0, 0x3E4(r1)
  stw       r5, 0x3E0(r1)
  lfd       f0, 0x3E0(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x4(r27)
  lha       r4, 0x30E(r1)
  lha       r0, 0x312(r1)
  add       r0, r4, r0
  srawi     r0, r0, 0x1
  xoris     r0, r0, 0x8000
  stw       r0, 0x3EC(r1)
  stw       r5, 0x3E8(r1)
  lfd       f0, 0x3E8(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x8(r27)
  lha       r4, 0x314(r1)
  lha       r0, 0x318(r1)
  add       r0, r4, r0
  srawi     r0, r0, 0x1
  xoris     r0, r0, 0x8000
  stw       r0, 0x3F4(r1)
  stw       r5, 0x3F0(r1)
  lfd       f0, 0x3F0(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0xC(r27)
  lha       r4, 0x316(r1)
  lha       r0, 0x31A(r1)
  add       r0, r4, r0
  srawi     r0, r0, 0x1
  xoris     r0, r0, 0x8000
  stw       r0, 0x3FC(r1)
  stw       r5, 0x3F8(r1)
  lfd       f0, 0x3F8(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x10(r27)
  bl        0xA90
  addi      r26, r3, 0
  addi      r3, r24, 0x18
  bl        0xA74
  srawi     r0, r3, 0x1
  extsh     r3, r0
  srawi     r0, r26, 0x1
  sth       r3, 0xB8(r24)
  extsh     r0, r0
  sth       r0, 0xBA(r24)
  addi      r3, r24, 0
  li        r4, 0x2
  lfs       f1, -0x48C8(r2)
  bl        -0x312CC
  lfs       f0, -0x48B8(r2)
  lis       r3, 0x802E
  addi      r0, r3, 0xEDC
  stfs      f0, 0x14(r27)
  stw       r0, 0x0(r27)

.loc_0x17B8:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x745C

.loc_0x17C4:
  cmplwi    r30, 0
  beq-      .loc_0x191C
  cmplwi    r29, 0
  beq-      .loc_0x191C
  lwz       r5, 0x0(r31)
  lis       r3, 0x6D6F
  addi      r4, r3, 0x6F6E
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  mr.       r24, r3
  beq-      .loc_0x191C
  li        r3, 0x18
  bl        -0x170B38
  addi      r27, r3, 0
  mr.       r25, r27
  beq-      .loc_0x1910
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r27)
  addi      r4, r24, 0
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x7464
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r27)
  addi      r4, r30, 0x18
  addi      r3, r1, 0x2FC
  bl        -0x4530
  addi      r4, r29, 0x18
  addi      r3, r1, 0x304
  bl        -0x453C
  lha       r4, 0x2FC(r1)
  lis       r3, 0x802E
  lha       r0, 0x300(r1)
  lis       r5, 0x4330
  lfd       f1, -0x48B0(r2)
  add       r0, r4, r0
  srawi     r0, r0, 0x1
  xoris     r0, r0, 0x8000
  stw       r0, 0x3E4(r1)
  addi      r0, r3, 0xE70
  stw       r5, 0x3E0(r1)
  lfd       f0, 0x3E0(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x4(r27)
  lha       r4, 0x2FE(r1)
  lha       r3, 0x302(r1)
  add       r3, r4, r3
  srawi     r3, r3, 0x1
  xoris     r3, r3, 0x8000
  stw       r3, 0x3EC(r1)
  stw       r5, 0x3E8(r1)
  lfd       f0, 0x3E8(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x8(r27)
  lha       r4, 0x304(r1)
  lha       r3, 0x308(r1)
  add       r3, r4, r3
  srawi     r3, r3, 0x1
  xoris     r3, r3, 0x8000
  stw       r3, 0x3F4(r1)
  stw       r5, 0x3F0(r1)
  lfd       f0, 0x3F0(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0xC(r27)
  lha       r4, 0x306(r1)
  lha       r3, 0x30A(r1)
  add       r3, r4, r3
  srawi     r3, r3, 0x1
  xoris     r3, r3, 0x8000
  stw       r3, 0x3FC(r1)
  stw       r5, 0x3F8(r1)
  lfd       f0, 0x3F8(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x10(r27)
  stw       r0, 0x0(r27)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0x14(r27)

.loc_0x1910:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x75B4

.loc_0x191C:
  lwz       r5, 0x4(r31)
  lis       r3, 0x6C69
  addi      r4, r3, 0x5F69
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0xC
  bl        -0x170C7C
  mr.       r25, r3
  beq-      .loc_0x19C8
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  li        r4, 0
  li        r5, 0x10
  bl        -0x75A4
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  lis       r3, 0x802E
  stw       r0, 0x0(r25)
  addi      r0, r3, 0xE0C
  stw       r0, 0x0(r25)
  li        r0, 0
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0x4(r25)
  stb       r0, 0x8(r25)
  lha       r5, 0x1A(r24)
  lha       r4, 0x1E(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r24)
  extsh     r0, r4
  sth       r0, 0xBA(r24)

.loc_0x19C8:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x766C
  lwz       r5, 0x4(r31)
  lis       r3, 0x6E61
  addi      r4, r3, 0x5F69
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0xC
  bl        -0x170D34
  mr.       r25, r3
  beq-      .loc_0x1A80
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  li        r4, 0
  li        r5, 0x10
  bl        -0x765C
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  lis       r3, 0x802E
  stw       r0, 0x0(r25)
  addi      r0, r3, 0xE0C
  stw       r0, 0x0(r25)
  li        r0, 0
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0x4(r25)
  stb       r0, 0x8(r25)
  lha       r5, 0x1A(r24)
  lha       r4, 0x1E(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r24)
  extsh     r0, r4
  sth       r0, 0xBA(r24)

.loc_0x1A80:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x7724
  lwz       r5, 0x4(r31)
  lis       r3, 0x6E61
  addi      r4, r3, 0x7669
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r21, r3, 0
  li        r3, 0x4
  bl        -0x170DEC
  addi      r24, r3, 0
  mr.       r22, r24
  beq-      .loc_0x1AFC
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r24)
  addi      r4, r21, 0
  addi      r3, r22, 0x4
  li        r5, 0x12
  bl        -0x7718
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  lis       r3, 0x802E
  stw       r0, 0x0(r24)
  addi      r0, r3, 0xDC4
  stw       r0, 0x0(r24)

.loc_0x1AFC:
  addi      r3, r21, 0
  addi      r4, r22, 0
  bl        -0x77A0
  lwz       r5, 0x4(r31)
  lis       r3, 0x6C69
  addi      r4, r3, 0x6665
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x8
  bl        -0x170E68
  addi      r27, r3, 0
  mr.       r25, r27
  beq-      .loc_0x1C64
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r27)
  addi      r4, r24, 0
  addi      r3, r25, 0x4
  li        r5, 0x10
  bl        -0x7794
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  lis       r3, 0x802E
  stw       r0, 0x0(r27)
  addi      r0, r3, 0xD7C
  stw       r0, 0x0(r27)
  li        r3, 0x1C
  bl        -0x170EB0
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x1C60
  lha       r4, 0x18(r24)
  lis       r30, 0x4330
  lha       r0, 0x1C(r24)
  addi      r3, r24, 0x18
  lfd       f1, -0x48B0(r2)
  sub       r0, r0, r4
  srawi     r0, r0, 0x1
  xoris     r0, r0, 0x8000
  stw       r0, 0x3E4(r1)
  stw       r30, 0x3E0(r1)
  lfd       f0, 0x3E0(r1)
  fsubs     f31, f0, f1
  bl        0x640
  addi      r26, r3, 0
  addi      r3, r24, 0x18
  bl        0x624
  srawi     r0, r3, 0x1
  lfd       f4, -0x48B0(r2)
  xoris     r0, r0, 0x8000
  lfs       f0, 0x1984(r13)
  stw       r0, 0x3EC(r1)
  srawi     r0, r26, 0x1
  xoris     r3, r0, 0x8000
  lfs       f1, -0x48C8(r2)
  stw       r30, 0x3E8(r1)
  li        r0, 0
  stw       r3, 0x3F4(r1)
  lfd       f2, 0x3E8(r1)
  stw       r30, 0x3F0(r1)
  fsubs     f3, f2, f4
  lfd       f2, 0x3F0(r1)
  fsubs     f2, f2, f4
  stfs      f3, 0x394(r1)
  stfs      f2, 0x398(r1)
  stfs      f0, 0x39C(r1)
  stfs      f1, 0x10(r29)
  stfs      f1, 0xC(r29)
  stfs      f1, 0x8(r29)
  lwz       r4, 0x394(r1)
  lwz       r3, 0x398(r1)
  stw       r4, 0x8(r29)
  stw       r3, 0xC(r29)
  lwz       r3, 0x39C(r1)
  stw       r3, 0x10(r29)
  stfs      f31, 0x14(r29)
  lfs       f0, 0x1A28(r13)
  fctiwz    f0, f0
  stfd      f0, 0x3F8(r1)
  lwz       r3, 0x3FC(r1)
  subi      r3, r3, 0x1
  stw       r3, 0x0(r29)
  stfs      f1, 0x4(r29)
  stw       r0, 0x18(r29)

.loc_0x1C60:
  stw       r29, 0x4(r27)

.loc_0x1C64:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x7908
  lwz       r5, 0x4(r31)
  lis       r3, 0x7069
  addi      r4, r3, 0x6E31
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x14
  bl        -0x170FD0
  mr.       r25, r3
  beq-      .loc_0x1D28
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x78F8
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  lis       r3, 0x802E
  stw       r0, 0x0(r25)
  addi      r0, r3, 0xD34
  stw       r0, 0x0(r25)
  li        r0, 0
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0x8(r25)
  stfs      f0, 0x4(r25)
  stb       r0, 0x10(r25)
  stw       r0, 0xC(r25)
  stb       r0, 0xF0(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  lha       r4, 0x1A(r24)
  sub       r0, r0, r3
  lha       r3, 0x1E(r24)
  srawi     r0, r0, 0x1
  sub       r4, r3, r4
  extsh     r3, r0
  srawi     r0, r4, 0x1
  sth       r3, 0xB8(r24)
  extsh     r0, r0
  sth       r0, 0xBA(r24)

.loc_0x1D28:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x79CC
  lwz       r5, 0x4(r31)
  lis       r3, 0x7069
  addi      r4, r3, 0x6E32
  addi      r3, r5, 0xC
  lwz       r12, 0xC(r5)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r24, r3, 0
  li        r3, 0x14
  bl        -0x171094
  mr.       r25, r3
  beq-      .loc_0x1DEC
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x79BC
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  lis       r3, 0x802E
  stw       r0, 0x0(r25)
  addi      r0, r3, 0xD34
  stw       r0, 0x0(r25)
  li        r0, 0
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0x8(r25)
  stfs      f0, 0x4(r25)
  stb       r0, 0x10(r25)
  stw       r0, 0xC(r25)
  stb       r0, 0xF0(r24)
  lha       r3, 0x18(r24)
  lha       r0, 0x1C(r24)
  lha       r4, 0x1A(r24)
  sub       r0, r0, r3
  lha       r3, 0x1E(r24)
  srawi     r0, r0, 0x1
  sub       r4, r3, r4
  extsh     r3, r0
  srawi     r0, r4, 0x1
  sth       r3, 0xB8(r24)
  extsh     r0, r0
  sth       r0, 0xBA(r24)

.loc_0x1DEC:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x7A90
  cmpwi     r28, 0
  bne-      .loc_0x1FB0
  lwz       r3, 0x8(r31)
  lis       r25, 0x6463
  lwzu      r12, 0xC(r3)
  addi      r4, r25, 0x5F63
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x8(r31)
  addi      r24, r3, 0
  li        r5, 0x1
  lwz       r12, 0xC(r4)
  addi      r3, r4, 0xC
  addi      r4, r25, 0x5F6C
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x8(r31)
  addi      r27, r3, 0
  li        r5, 0x1
  lwz       r12, 0xC(r4)
  addi      r3, r4, 0xC
  addi      r4, r25, 0x5F72
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x8(r31)
  addi      r28, r3, 0
  li        r5, 0x1
  lwz       r12, 0xC(r4)
  addi      r3, r4, 0xC
  addi      r4, r25, 0x7363
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x8(r31)
  addi      r29, r3, 0
  li        r5, 0x1
  lwz       r12, 0xC(r4)
  addi      r3, r4, 0xC
  addi      r4, r25, 0x736C
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x8(r31)
  addi      r30, r3, 0
  li        r5, 0x1
  lwz       r12, 0xC(r4)
  addi      r3, r4, 0xC
  addi      r4, r25, 0x7372
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r26, r3, 0
  li        r3, 0x1C
  bl        -0x171210
  mr.       r25, r3
  beq-      .loc_0x1FA4
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  li        r4, 0
  li        r5, 0x10
  bl        -0x7B38
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r25)
  addi      r3, r25, 0x4
  bl        0x74A4
  lis       r3, 0x802E
  addi      r0, r3, 0xCE8
  stw       r0, 0x0(r25)
  addi      r4, r24, 0
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x7B38
  addi      r4, r27, 0
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x7B48
  addi      r4, r28, 0
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x7B58
  addi      r4, r29, 0
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x7B68
  addi      r4, r30, 0
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x7B78
  addi      r4, r26, 0
  addi      r3, r25, 0x4
  li        r5, 0x12
  bl        -0x7B88
  stw       r24, 0x4(r25)
  mr        r3, r25
  stw       r27, 0x8(r25)
  stw       r28, 0xC(r25)
  stw       r29, 0x10(r25)
  stw       r30, 0x14(r25)
  stw       r26, 0x18(r25)
  bl        .loc_0x1FCC

.loc_0x1FA4:
  addi      r3, r24, 0
  addi      r4, r25, 0
  bl        -0x7C48

.loc_0x1FB0:
  mr        r3, r31
  lmw       r21, 0x404(r1)
  lwz       r0, 0x43C(r1)
  lfd       f31, 0x430(r1)
  addi      r1, r1, 0x438
  mtlr      r0
  blr       

.loc_0x1FCC:
*/
}

/*
 * --INFO--
 * Address:	801B8304
 * Size:	000220
 */
void @unnamed@::DateCallBack::setTex()
{
/*
.loc_0x0:
  lis       r4, 0x803A
  subi      r4, r4, 0x2848
  lwz       r0, 0x2FC(r4)
  cmpwi     r0, 0x9
  ble-      .loc_0x160
  lwz       r6, 0x4(r3)
  lis       r4, 0x6666
  addi      r4, r4, 0x6667
  lbz       r5, 0xC(r6)
  li        r7, 0
  rlwimi    r5,r7,7,24,24
  stb       r5, 0xC(r6)
  mulhw     r4, r4, r0
  lwz       r6, 0x8(r3)
  lbz       r5, 0xC(r6)
  li        r7, 0x1
  rlwimi    r5,r7,7,24,24
  stb       r5, 0xC(r6)
  srawi     r4, r4, 0x2
  rlwinm    r5,r4,1,31,31
  lwz       r7, 0x8(r3)
  add       r4, r4, r5
  lis       r6, 0x803D
  lbz       r5, 0xF1(r7)
  rlwinm    r4,r4,2,0,29
  addi      r6, r6, 0x2360
  add       r6, r6, r4
  cmplwi    r5, 0
  lwz       r5, 0x0(r6)
  ble-      .loc_0x7C
  stw       r5, 0xEC(r7)

.loc_0x7C:
  lis       r5, 0x6666
  lwz       r8, 0xC(r3)
  addi      r5, r5, 0x6667
  mulhw     r5, r5, r0
  lbz       r7, 0xC(r8)
  srawi     r5, r5, 0x2
  li        r6, 0x1
  rlwimi    r7,r6,7,24,24
  rlwinm    r6,r5,1,31,31
  stb       r7, 0xC(r8)
  add       r5, r5, r6
  mulli     r6, r5, 0xA
  lwz       r7, 0xC(r3)
  lbz       r5, 0xF1(r7)
  sub       r0, r0, r6
  lis       r6, 0x803D
  rlwinm    r8,r0,2,0,29
  addi      r0, r6, 0x2360
  add       r6, r0, r8
  cmplwi    r5, 0
  lwz       r0, 0x0(r6)
  ble-      .loc_0xD8
  stw       r0, 0xEC(r7)

.loc_0xD8:
  lwz       r6, 0x10(r3)
  lis       r5, 0x803D
  addi      r0, r5, 0x2388
  lbz       r5, 0xC(r6)
  li        r7, 0
  rlwimi    r5,r7,7,24,24
  stb       r5, 0xC(r6)
  li        r6, 0x1
  add       r4, r0, r4
  lwz       r5, 0x14(r3)
  lbz       r0, 0xC(r5)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r5)
  lwz       r5, 0x14(r3)
  lwz       r4, 0x0(r4)
  lbz       r0, 0xF1(r5)
  cmplwi    r0, 0
  ble-      .loc_0x124
  stw       r4, 0xEC(r5)

.loc_0x124:
  lwz       r5, 0x18(r3)
  lis       r4, 0x803D
  addi      r0, r4, 0x2388
  lbz       r4, 0xC(r5)
  li        r6, 0x1
  rlwimi    r4,r6,7,24,24
  stb       r4, 0xC(r5)
  add       r4, r0, r8
  lwz       r5, 0x18(r3)
  lwz       r3, 0x0(r4)
  lbz       r0, 0xF1(r5)
  cmplwi    r0, 0
  blelr-    
  stw       r3, 0xEC(r5)
  blr       

.loc_0x160:
  lwz       r6, 0x4(r3)
  lis       r4, 0x803D
  li        r7, 0x1
  lbz       r5, 0xC(r6)
  rlwimi    r5,r7,7,24,24
  rlwinm    r8,r0,2,0,29
  stb       r5, 0xC(r6)
  addi      r0, r4, 0x2360
  add       r4, r0, r8
  lwz       r5, 0x4(r3)
  lwz       r4, 0x0(r4)
  lbz       r0, 0xF1(r5)
  cmplwi    r0, 0
  ble-      .loc_0x19C
  stw       r4, 0xEC(r5)

.loc_0x19C:
  lwz       r5, 0x8(r3)
  lis       r4, 0x803D
  addi      r0, r4, 0x2388
  lbz       r4, 0xC(r5)
  li        r7, 0
  rlwimi    r4,r7,7,24,24
  stb       r4, 0xC(r5)
  li        r6, 0x1
  add       r4, r0, r8
  lwz       r5, 0xC(r3)
  lbz       r0, 0xC(r5)
  rlwimi    r0,r7,7,24,24
  stb       r0, 0xC(r5)
  lwz       r5, 0x10(r3)
  lbz       r0, 0xC(r5)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r5)
  lwz       r5, 0x10(r3)
  lwz       r4, 0x0(r4)
  lbz       r0, 0xF1(r5)
  cmplwi    r0, 0
  ble-      .loc_0x1F8
  stw       r4, 0xEC(r5)

.loc_0x1F8:
  lwz       r4, 0x14(r3)
  li        r5, 0
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  lwz       r3, 0x18(r3)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801B8524
 * Size:	000010
 */
void PUTRect::getWidth() const
{
/*
.loc_0x0:
  lha       r4, 0x0(r3)
  lha       r0, 0x4(r3)
  sub       r3, r0, r4
  blr
*/
}

/*
 * --INFO--
 * Address:	801B8534
 * Size:	000010
 */
void PUTRect::getHeight() const
{
/*
.loc_0x0:
  lha       r4, 0x2(r3)
  lha       r0, 0x6(r3)
  sub       r3, r0, r4
  blr
*/
}

/*
 * --INFO--
 * Address:	801B8544
 * Size:	00003C
 */
void zen::FigureTex<short>::getNumber()
{
/*
.loc_0x0:
  lwz       r5, 0x0(r3)
  lis       r4, 0x6666
  addi      r0, r4, 0x6667
  lwz       r3, 0x4(r3)
  lha       r4, 0x0(r5)
  divw      r4, r4, r3
  mulhw     r0, r0, r4
  srawi     r0, r0, 0x2
  rlwinm    r3,r0,1,31,31
  add       r0, r0, r3
  mulli     r0, r0, 0xA
  sub.      r3, r4, r0
  bgelr-    
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801B8580
 * Size:	000454
 */
void zen::DrawGameInfo::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x88(r1)
  stw       r31, 0x84(r1)
  mr        r31, r3
  stw       r30, 0x80(r1)
  stw       r29, 0x7C(r1)
  lwz       r30, 0x0(r3)
  addi      r3, r30, 0xC
  bl        -0x5A54
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0x2
  beq-      .loc_0xE8
  bge-      .loc_0x48
  cmpwi     r0, 0
  beq-      .loc_0x54
  bge-      .loc_0x68
  b         .loc_0x178

.loc_0x48:
  cmpwi     r0, 0x4
  bge-      .loc_0x178
  b         .loc_0xFC

.loc_0x54:
  lbz       r0, 0x18(r30)
  li        r3, 0
  rlwimi    r0,r3,7,24,24
  stb       r0, 0x18(r30)
  b         .loc_0x178

.loc_0x68:
  lwz       r3, 0x2DEC(r13)
  li        r29, 0
  lfs       f1, 0x4(r30)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r30)
  lfs       f0, 0x4(r30)
  lfs       f1, 0x8(r30)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x98
  stfs      f1, 0x4(r30)
  li        r29, 0x1

.loc_0x98:
  lfs       f1, 0x4(r30)
  lfs       f0, 0x8(r30)
  lfs       f2, -0x48A4(r2)
  fdivs     f1, f1, f0
  lfs       f3, -0x48C0(r2)
  lfs       f0, -0x48A0(r2)
  fmuls     f1, f2, f1
  fmuls     f1, f3, f1
  fdivs     f1, f1, f0
  bl        0x636AC
  rlwinm.   r0,r29,0,24,31
  beq-      .loc_0xD0
  li        r0, 0x2
  stw       r0, 0x0(r30)

.loc_0xD0:
  lfs       f0, -0x489C(r2)
  fsubs     f0, f0, f1
  stfs      f0, 0xCC(r30)
  stfs      f0, 0xD0(r30)
  stfs      f0, 0xD4(r30)
  b         .loc_0x178

.loc_0xE8:
  lfs       f0, -0x4898(r2)
  stfs      f0, 0xCC(r30)
  stfs      f0, 0xD0(r30)
  stfs      f0, 0xD4(r30)
  b         .loc_0x178

.loc_0xFC:
  lwz       r3, 0x2DEC(r13)
  li        r29, 0
  lfs       f1, 0x4(r30)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r30)
  lfs       f0, 0x4(r30)
  lfs       f1, 0x8(r30)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x12C
  stfs      f1, 0x4(r30)
  li        r29, 0x1

.loc_0x12C:
  lfs       f1, 0x4(r30)
  lfs       f0, 0x8(r30)
  lfs       f2, -0x48A4(r2)
  fdivs     f1, f1, f0
  lfs       f3, -0x48C0(r2)
  lfs       f0, -0x48A0(r2)
  fmuls     f1, f2, f1
  fmuls     f1, f3, f1
  fdivs     f1, f1, f0
  bl        0x63618
  rlwinm.   r0,r29,0,24,31
  beq-      .loc_0x164
  li        r0, 0
  stw       r0, 0x0(r30)

.loc_0x164:
  lfs       f0, -0x4898(r2)
  fadds     f0, f0, f1
  stfs      f0, 0xCC(r30)
  stfs      f0, 0xD0(r30)
  stfs      f0, 0xD4(r30)

.loc_0x178:
  lwz       r30, 0x4(r31)
  addi      r3, r30, 0xC
  bl        -0x5BB0
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0x2
  beq-      .loc_0x244
  bge-      .loc_0x1A4
  cmpwi     r0, 0
  beq-      .loc_0x1B0
  bge-      .loc_0x1C4
  b         .loc_0x2D4

.loc_0x1A4:
  cmpwi     r0, 0x4
  bge-      .loc_0x2D4
  b         .loc_0x258

.loc_0x1B0:
  lbz       r0, 0x18(r30)
  li        r3, 0
  rlwimi    r0,r3,7,24,24
  stb       r0, 0x18(r30)
  b         .loc_0x2D4

.loc_0x1C4:
  lwz       r3, 0x2DEC(r13)
  li        r29, 0
  lfs       f1, 0x4(r30)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r30)
  lfs       f0, 0x4(r30)
  lfs       f1, 0x8(r30)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x1F4
  stfs      f1, 0x4(r30)
  li        r29, 0x1

.loc_0x1F4:
  lfs       f1, 0x4(r30)
  lfs       f0, 0x8(r30)
  lfs       f2, -0x48A4(r2)
  fdivs     f1, f1, f0
  lfs       f3, -0x48C0(r2)
  lfs       f0, -0x48A0(r2)
  fmuls     f1, f2, f1
  fmuls     f1, f3, f1
  fdivs     f1, f1, f0
  bl        0x63550
  rlwinm.   r0,r29,0,24,31
  beq-      .loc_0x22C
  li        r0, 0x2
  stw       r0, 0x0(r30)

.loc_0x22C:
  lfs       f0, -0x489C(r2)
  fsubs     f0, f0, f1
  stfs      f0, 0xCC(r30)
  stfs      f0, 0xD0(r30)
  stfs      f0, 0xD4(r30)
  b         .loc_0x2D4

.loc_0x244:
  lfs       f0, -0x4898(r2)
  stfs      f0, 0xCC(r30)
  stfs      f0, 0xD0(r30)
  stfs      f0, 0xD4(r30)
  b         .loc_0x2D4

.loc_0x258:
  lwz       r3, 0x2DEC(r13)
  li        r29, 0
  lfs       f1, 0x4(r30)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r30)
  lfs       f0, 0x4(r30)
  lfs       f1, 0x8(r30)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x288
  stfs      f1, 0x4(r30)
  li        r29, 0x1

.loc_0x288:
  lfs       f1, 0x4(r30)
  lfs       f0, 0x8(r30)
  lfs       f2, -0x48A4(r2)
  fdivs     f1, f1, f0
  lfs       f3, -0x48C0(r2)
  lfs       f0, -0x48A0(r2)
  fmuls     f1, f2, f1
  fmuls     f1, f3, f1
  fdivs     f1, f1, f0
  bl        0x634BC
  rlwinm.   r0,r29,0,24,31
  beq-      .loc_0x2C0
  li        r0, 0
  stw       r0, 0x0(r30)

.loc_0x2C0:
  lfs       f0, -0x4898(r2)
  fadds     f0, f0, f1
  stfs      f0, 0xCC(r30)
  stfs      f0, 0xD0(r30)
  stfs      f0, 0xD4(r30)

.loc_0x2D4:
  lwz       r30, 0x8(r31)
  addi      r3, r30, 0xC
  bl        -0x5D0C
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0x2
  beq-      .loc_0x3A0
  bge-      .loc_0x300
  cmpwi     r0, 0
  beq-      .loc_0x30C
  bge-      .loc_0x320
  b         .loc_0x430

.loc_0x300:
  cmpwi     r0, 0x4
  bge-      .loc_0x430
  b         .loc_0x3B4

.loc_0x30C:
  lbz       r0, 0x18(r30)
  li        r3, 0
  rlwimi    r0,r3,7,24,24
  stb       r0, 0x18(r30)
  b         .loc_0x430

.loc_0x320:
  lwz       r3, 0x2DEC(r13)
  li        r29, 0
  lfs       f1, 0x4(r30)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r30)
  lfs       f0, 0x4(r30)
  lfs       f1, 0x8(r30)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x350
  stfs      f1, 0x4(r30)
  li        r29, 0x1

.loc_0x350:
  lfs       f1, 0x4(r30)
  lfs       f0, 0x8(r30)
  lfs       f2, -0x48A4(r2)
  fdivs     f1, f1, f0
  lfs       f3, -0x48C0(r2)
  lfs       f0, -0x48A0(r2)
  fmuls     f1, f2, f1
  fmuls     f1, f3, f1
  fdivs     f1, f1, f0
  bl        0x633F4
  rlwinm.   r0,r29,0,24,31
  beq-      .loc_0x388
  li        r0, 0x2
  stw       r0, 0x0(r30)

.loc_0x388:
  lfs       f0, -0x489C(r2)
  fsubs     f0, f0, f1
  stfs      f0, 0xCC(r30)
  stfs      f0, 0xD0(r30)
  stfs      f0, 0xD4(r30)
  b         .loc_0x430

.loc_0x3A0:
  lfs       f0, -0x4898(r2)
  stfs      f0, 0xCC(r30)
  stfs      f0, 0xD0(r30)
  stfs      f0, 0xD4(r30)
  b         .loc_0x430

.loc_0x3B4:
  lwz       r3, 0x2DEC(r13)
  li        r29, 0
  lfs       f1, 0x4(r30)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r30)
  lfs       f0, 0x4(r30)
  lfs       f1, 0x8(r30)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x3E4
  stfs      f1, 0x4(r30)
  li        r29, 0x1

.loc_0x3E4:
  lfs       f1, 0x4(r30)
  lfs       f0, 0x8(r30)
  lfs       f2, -0x48A4(r2)
  fdivs     f1, f1, f0
  lfs       f3, -0x48C0(r2)
  lfs       f0, -0x48A0(r2)
  fmuls     f1, f2, f1
  fmuls     f1, f3, f1
  fdivs     f1, f1, f0
  bl        0x63360
  rlwinm.   r0,r29,0,24,31
  beq-      .loc_0x41C
  li        r0, 0
  stw       r0, 0x0(r30)

.loc_0x41C:
  lfs       f0, -0x4898(r2)
  fadds     f0, f0, f1
  stfs      f0, 0xCC(r30)
  stfs      f0, 0xD0(r30)
  stfs      f0, 0xD4(r30)

.loc_0x430:
  addi      r3, r31, 0x18
  bl        0x38B4C
  lwz       r0, 0x8C(r1)
  lwz       r31, 0x84(r1)
  lwz       r30, 0x80(r1)
  lwz       r29, 0x7C(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801B89D4
 * Size:	0000F0
 */
void zen::DrawGameInfo::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x100(r1)
  stw       r31, 0xFC(r1)
  addi      r31, r4, 0
  stw       r30, 0xF8(r1)
  addi      r30, r3, 0
  addi      r3, r30, 0x18
  bl        0x38BB4
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0
  lwz       r12, 0xB8(r12)
  mtlr      r12
  blrl      
  li        r3, 0
  li        r4, 0x7
  li        r5, 0
  bl        0x5B3B4
  lfs       f1, -0x4894(r2)
  addi      r3, r1, 0x10
  lfs       f2, -0x4898(r2)
  li        r4, 0
  lfs       f3, -0x4890(r2)
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        -0x88B0
  addi      r3, r1, 0x10
  bl        -0x87A8
  lwz       r3, 0x0(r30)
  addi      r6, r1, 0x10
  li        r4, 0
  addi      r3, r3, 0xC
  li        r5, 0
  bl        -0x5B8C
  lwz       r3, 0x4(r30)
  addi      r6, r1, 0x10
  li        r4, 0
  addi      r3, r3, 0xC
  li        r5, 0
  bl        -0x5BA4
  lwz       r3, 0x8(r30)
  addi      r6, r1, 0x10
  li        r4, 0
  addi      r3, r3, 0xC
  li        r5, 0
  bl        -0x5BBC
  lis       r3, 0x802E
  addi      r0, r3, 0x698
  lis       r3, 0x802E
  stw       r0, 0x10(r1)
  addi      r0, r3, 0x5D4
  stw       r0, 0x10(r1)
  lwz       r0, 0x104(r1)
  lwz       r31, 0xFC(r1)
  lwz       r30, 0xF8(r1)
  addi      r1, r1, 0x100
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void zen::DrawGameInfo::upperDisplayOn()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void zen::DrawGameInfo::upperDisplayOff()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void zen::DrawGameInfo::lowerDisplayOn()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void zen::DrawGameInfo::lowerDisplayOff()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B8AC4
 * Size:	00007C
 */
void zen::DrawGameInfo::upperFrameIn(float, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  rlwinm.   r0,r4,0,24,31
  stwu      r1, -0x28(r1)
  stfd      f31, 0x20(r1)
  fmr       f31, f1
  stw       r31, 0x1C(r1)
  mr        r31, r3
  beq-      .loc_0x30
  lwz       r3, 0x0(r31)
  addi      r3, r3, 0xC
  bl        0x6CB4

.loc_0x30:
  lwz       r4, 0x0(r31)
  li        r3, 0x1
  stw       r3, 0x0(r4)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0x4(r4)
  stfs      f31, 0x8(r4)
  lbz       r0, 0x18(r4)
  rlwimi    r0,r3,7,24,24
  stb       r0, 0x18(r4)
  lfs       f0, -0x489C(r2)
  stfs      f0, 0xCC(r4)
  stfs      f0, 0xD0(r4)
  stfs      f0, 0xD4(r4)
  lwz       r0, 0x2C(r1)
  lfd       f31, 0x20(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801B8B40
 * Size:	000080
 */
void zen::DrawGameInfo::upperFrameOut(float, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  rlwinm.   r0,r4,0,24,31
  stwu      r1, -0x28(r1)
  stfd      f31, 0x20(r1)
  fmr       f31, f1
  stw       r31, 0x1C(r1)
  mr        r31, r3
  beq-      .loc_0x30
  lwz       r3, 0x0(r31)
  addi      r3, r3, 0xC
  bl        0x6C38

.loc_0x30:
  lwz       r4, 0x0(r31)
  li        r0, 0x3
  li        r3, 0x1
  stw       r0, 0x0(r4)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0x4(r4)
  stfs      f31, 0x8(r4)
  lbz       r0, 0x18(r4)
  rlwimi    r0,r3,7,24,24
  stb       r0, 0x18(r4)
  lfs       f0, -0x4898(r2)
  stfs      f0, 0xCC(r4)
  stfs      f0, 0xD0(r4)
  stfs      f0, 0xD4(r4)
  lwz       r0, 0x2C(r1)
  lfd       f31, 0x20(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801B8BC0
 * Size:	0000B0
 */
void zen::DrawGameInfo::lowerFrameIn(float, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  rlwinm.   r0,r4,0,24,31
  stwu      r1, -0x30(r1)
  stfd      f31, 0x28(r1)
  fmr       f31, f1
  stw       r31, 0x24(r1)
  mr        r31, r3
  beq-      .loc_0x3C
  lwz       r3, 0x4(r31)
  addi      r3, r3, 0xC
  bl        0x6BB8
  lwz       r3, 0x8(r31)
  addi      r3, r3, 0xC
  bl        0x6BAC

.loc_0x3C:
  lwz       r4, 0x4(r31)
  li        r3, 0x1
  stw       r3, 0x0(r4)
  lfs       f1, -0x48C8(r2)
  stfs      f1, 0x4(r4)
  stfs      f31, 0x8(r4)
  lbz       r0, 0x18(r4)
  rlwimi    r0,r3,7,24,24
  stb       r0, 0x18(r4)
  lfs       f0, -0x489C(r2)
  stfs      f0, 0xCC(r4)
  stfs      f0, 0xD0(r4)
  stfs      f0, 0xD4(r4)
  lwz       r4, 0x8(r31)
  stw       r3, 0x0(r4)
  stfs      f1, 0x4(r4)
  stfs      f31, 0x8(r4)
  lbz       r0, 0x18(r4)
  rlwimi    r0,r3,7,24,24
  stb       r0, 0x18(r4)
  stfs      f0, 0xCC(r4)
  stfs      f0, 0xD0(r4)
  stfs      f0, 0xD4(r4)
  lwz       r0, 0x34(r1)
  lfd       f31, 0x28(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801B8C70
 * Size:	0000B4
 */
void zen::DrawGameInfo::lowerFrameOut(float, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  rlwinm.   r0,r4,0,24,31
  stwu      r1, -0x30(r1)
  stfd      f31, 0x28(r1)
  fmr       f31, f1
  stw       r31, 0x24(r1)
  mr        r31, r3
  beq-      .loc_0x3C
  lwz       r3, 0x4(r31)
  addi      r3, r3, 0xC
  bl        0x6B08
  lwz       r3, 0x8(r31)
  addi      r3, r3, 0xC
  bl        0x6AFC

.loc_0x3C:
  lwz       r5, 0x4(r31)
  li        r4, 0x3
  li        r3, 0x1
  stw       r4, 0x0(r5)
  lfs       f1, -0x48C8(r2)
  stfs      f1, 0x4(r5)
  stfs      f31, 0x8(r5)
  lbz       r0, 0x18(r5)
  rlwimi    r0,r3,7,24,24
  stb       r0, 0x18(r5)
  lfs       f0, -0x4898(r2)
  stfs      f0, 0xCC(r5)
  stfs      f0, 0xD0(r5)
  stfs      f0, 0xD4(r5)
  lwz       r5, 0x8(r31)
  stw       r4, 0x0(r5)
  stfs      f1, 0x4(r5)
  stfs      f31, 0x8(r5)
  lbz       r0, 0x18(r5)
  rlwimi    r0,r3,7,24,24
  stb       r0, 0x18(r5)
  stfs      f0, 0xCC(r5)
  stfs      f0, 0xD0(r5)
  stfs      f0, 0xD4(r5)
  lwz       r0, 0x34(r1)
  lfd       f31, 0x28(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void zen::DrawGameInfo::isUpperFrameIn()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void zen::DrawGameInfo::isUpperFrameOut()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void zen::DrawGameInfo::isLowerFrameIn()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void zen::DrawGameInfo::isLowerFrameOut()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B8D24
 * Size:	000224
 */
void @unnamed@::DateCallBack::invoke(P2DPane *)
{
/*
.loc_0x0:
  lis       r4, 0x803A
  subi      r4, r4, 0x2848
  lwz       r0, 0x2FC(r4)
  cmpwi     r0, 0x9
  ble-      .loc_0x160
  lwz       r6, 0x4(r3)
  lis       r4, 0x6666
  addi      r4, r4, 0x6667
  lbz       r5, 0xC(r6)
  li        r7, 0
  rlwimi    r5,r7,7,24,24
  stb       r5, 0xC(r6)
  mulhw     r4, r4, r0
  lwz       r6, 0x8(r3)
  lbz       r5, 0xC(r6)
  li        r7, 0x1
  rlwimi    r5,r7,7,24,24
  stb       r5, 0xC(r6)
  srawi     r4, r4, 0x2
  rlwinm    r5,r4,1,31,31
  lwz       r7, 0x8(r3)
  add       r4, r4, r5
  lis       r6, 0x803D
  lbz       r5, 0xF1(r7)
  rlwinm    r4,r4,2,0,29
  addi      r6, r6, 0x2360
  add       r6, r6, r4
  cmplwi    r5, 0
  lwz       r5, 0x0(r6)
  ble-      .loc_0x7C
  stw       r5, 0xEC(r7)

.loc_0x7C:
  lis       r5, 0x6666
  lwz       r8, 0xC(r3)
  addi      r5, r5, 0x6667
  mulhw     r5, r5, r0
  lbz       r7, 0xC(r8)
  srawi     r5, r5, 0x2
  li        r6, 0x1
  rlwimi    r7,r6,7,24,24
  rlwinm    r6,r5,1,31,31
  stb       r7, 0xC(r8)
  add       r5, r5, r6
  mulli     r6, r5, 0xA
  lwz       r7, 0xC(r3)
  lbz       r5, 0xF1(r7)
  sub       r0, r0, r6
  lis       r6, 0x803D
  rlwinm    r8,r0,2,0,29
  addi      r0, r6, 0x2360
  add       r6, r0, r8
  cmplwi    r5, 0
  lwz       r0, 0x0(r6)
  ble-      .loc_0xD8
  stw       r0, 0xEC(r7)

.loc_0xD8:
  lwz       r6, 0x10(r3)
  lis       r5, 0x803D
  addi      r0, r5, 0x2388
  lbz       r5, 0xC(r6)
  li        r7, 0
  rlwimi    r5,r7,7,24,24
  stb       r5, 0xC(r6)
  li        r6, 0x1
  add       r4, r0, r4
  lwz       r5, 0x14(r3)
  lbz       r0, 0xC(r5)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r5)
  lwz       r5, 0x14(r3)
  lwz       r4, 0x0(r4)
  lbz       r0, 0xF1(r5)
  cmplwi    r0, 0
  ble-      .loc_0x124
  stw       r4, 0xEC(r5)

.loc_0x124:
  lwz       r5, 0x18(r3)
  lis       r4, 0x803D
  addi      r0, r4, 0x2388
  lbz       r4, 0xC(r5)
  li        r6, 0x1
  rlwimi    r4,r6,7,24,24
  stb       r4, 0xC(r5)
  add       r4, r0, r8
  lwz       r5, 0x18(r3)
  lwz       r3, 0x0(r4)
  lbz       r0, 0xF1(r5)
  cmplwi    r0, 0
  ble-      .loc_0x21C
  stw       r3, 0xEC(r5)
  b         .loc_0x21C

.loc_0x160:
  lwz       r6, 0x4(r3)
  lis       r4, 0x803D
  li        r7, 0x1
  lbz       r5, 0xC(r6)
  rlwimi    r5,r7,7,24,24
  rlwinm    r8,r0,2,0,29
  stb       r5, 0xC(r6)
  addi      r0, r4, 0x2360
  add       r4, r0, r8
  lwz       r5, 0x4(r3)
  lwz       r4, 0x0(r4)
  lbz       r0, 0xF1(r5)
  cmplwi    r0, 0
  ble-      .loc_0x19C
  stw       r4, 0xEC(r5)

.loc_0x19C:
  lwz       r5, 0x8(r3)
  lis       r4, 0x803D
  addi      r0, r4, 0x2388
  lbz       r4, 0xC(r5)
  li        r7, 0
  rlwimi    r4,r7,7,24,24
  stb       r4, 0xC(r5)
  li        r6, 0x1
  add       r4, r0, r8
  lwz       r5, 0xC(r3)
  lbz       r0, 0xC(r5)
  rlwimi    r0,r7,7,24,24
  stb       r0, 0xC(r5)
  lwz       r5, 0x10(r3)
  lbz       r0, 0xC(r5)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r5)
  lwz       r5, 0x10(r3)
  lwz       r4, 0x0(r4)
  lbz       r0, 0xF1(r5)
  cmplwi    r0, 0
  ble-      .loc_0x1F8
  stw       r4, 0xEC(r5)

.loc_0x1F8:
  lwz       r4, 0x14(r3)
  li        r5, 0
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  lwz       r3, 0x18(r3)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)

.loc_0x21C:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	801B8F48
 * Size:	000234
 */
void @unnamed@::LifePinchCallBack::invoke(P2DPane *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  addi      r31, r4, 0
  stw       r30, 0x38(r1)
  mr        r30, r3
  li        r3, 0
  lwz       r0, 0x3120(r13)
  lfs       f3, -0x48C8(r2)
  cmplwi    r0, 0
  beq-      .loc_0x4C
  mr        r3, r0
  li        r4, 0
  bl        -0xA1B48
  lwz       r4, 0x224(r3)
  lfs       f1, 0x58(r3)
  lfs       f0, 0x3C8(r4)
  fdivs     f3, f1, f0

.loc_0x4C:
  lfs       f0, -0x48C8(r2)
  fcmpo     cr0, f3, f0
  ble-      .loc_0xD8
  lfs       f0, -0x48C4(r2)
  fcmpo     cr0, f3, f0
  bge-      .loc_0xD8
  lfs       f1, 0x4(r30)
  lfs       f0, -0x488C(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x84
  lfs       f0, -0x4888(r2)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r30)
  b         .loc_0x8C

.loc_0x84:
  lfs       f0, -0x4884(r2)
  stfs      f0, 0x4(r30)

.loc_0x8C:
  lfs       f0, -0x48C4(r2)
  lfs       f2, -0x4894(r2)
  fsubs     f1, f0, f3
  lfs       f3, -0x48C0(r2)
  lfs       f4, -0x4880(r2)
  lfs       f0, -0x48A0(r2)
  fmuls     f1, f2, f1
  lfs       f2, 0x8(r30)
  fmuls     f1, f3, f1
  fadds     f1, f4, f1
  fdivs     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x8(r30)
  bl        -0xB8D40
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x168
  li        r0, 0x3
  stw       r0, 0xC(r30)
  b         .loc_0x168

.loc_0xD8:
  li        r0, 0
  stw       r0, 0xC(r30)
  lbz       r0, 0x10(r30)
  cmplwi    r0, 0
  bne-      .loc_0x128
  cmplwi    r3, 0
  beq-      .loc_0x128
  lfs       f1, 0x58(r3)
  lfs       f0, -0x48C8(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x128
  bl        -0xB8D84
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x128
  li        r0, 0x1
  stb       r0, 0x10(r30)
  lfs       f0, -0x4884(r2)
  stfs      f0, 0x4(r30)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0x8(r30)

.loc_0x128:
  lfs       f1, 0x4(r30)
  lfd       f0, -0x4878(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x148
  lfs       f0, -0x4888(r2)
  fsubs     f0, f1, f0
  stfs      f0, 0x4(r30)
  b         .loc_0x158

.loc_0x148:
  lfs       f0, -0x48C8(r2)
  li        r0, 0
  stfs      f0, 0x4(r30)
  stb       r0, 0x10(r30)

.loc_0x158:
  lfs       f1, 0x8(r30)
  lfs       f0, -0x4870(r2)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r30)

.loc_0x168:
  lfs       f1, 0x8(r30)
  lfs       f0, -0x48A8(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x19C
  fsubs     f0, f1, f0
  li        r0, 0
  stfs      f0, 0x8(r30)
  stb       r0, 0x10(r30)
  lwz       r0, 0xC(r30)
  cmpwi     r0, 0
  ble-      .loc_0x19C
  li        r3, 0x11A
  bl        -0x113D6C

.loc_0x19C:
  lfs       f1, 0x8(r30)
  bl        0x62A6C
  lfs       f0, -0x4898(r2)
  lfs       f2, 0x4(r30)
  fsubs     f1, f0, f1
  lfs       f3, -0x48C4(r2)
  lfs       f0, -0x48C8(r2)
  fmuls     f1, f2, f1
  fmuls     f1, f3, f1
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x1D4
  fadds     f0, f3, f1
  b         .loc_0x1D8

.loc_0x1D4:
  fsubs     f0, f1, f3

.loc_0x1D8:
  fctiwz    f0, f0
  stfd      f0, 0x30(r1)
  lwz       r0, 0x34(r1)
  stb       r0, 0xF0(r31)
  lfs       f1, -0x48C4(r2)
  lfs       f0, 0x8(r30)
  fmuls     f1, f1, f0
  bl        0x62A18
  lfs       f3, -0x4898(r2)
  li        r3, 0x1
  lfs       f2, -0x486C(r2)
  fsubs     f0, f3, f1
  fmuls     f0, f2, f0
  fadds     f0, f3, f0
  stfs      f0, 0xC0(r31)
  stfs      f0, 0xC4(r31)
  stfs      f0, 0xC8(r31)
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
 * Address:	801B917C
 * Size:	000008
 */
void @unnamed@::LifeIconCallBack::invoke(P2DPane *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	801B9184
 * Size:	000028
 */
void @unnamed@::LifeIconCallBack::draw(P2DPane *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x4(r3)
  bl        0x1400
  li        r3, 0x1
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801B91AC
 * Size:	00006C
 */
void @unnamed@::NaviTexCallBack::invoke(P2DPane *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  lwz       r3, 0x3120(r13)
  cmplwi    r3, 0
  beq-      .loc_0x54
  li        r4, 0
  bl        -0xA1D98
  lfs       f1, -0x48C8(r2)
  lfs       f0, 0x58(r3)
  fcmpu     cr0, f1, f0
  bne-      .loc_0x54
  lbz       r3, 0xF0(r31)
  cmplwi    r3, 0x3
  ble-      .loc_0x4C
  subi      r0, r3, 0x3
  b         .loc_0x50

.loc_0x4C:
  li        r0, 0

.loc_0x50:
  stb       r0, 0xF0(r31)

.loc_0x54:
  lwz       r0, 0x1C(r1)
  li        r3, 0x1
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801B9218
 * Size:	000108
 */
void @unnamed@::NaviIconCallBack::invoke(P2DPane *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r4, 0
  stw       r30, 0x28(r1)
  addi      r30, r3, 0
  li        r3, 0
  lwz       r0, 0x3120(r13)
  cmplwi    r0, 0
  beq-      .loc_0x38
  mr        r3, r0
  li        r4, 0
  bl        -0xA1E14

.loc_0x38:
  lbz       r0, 0x8(r30)
  cmplwi    r0, 0
  beq-      .loc_0xC0
  lfs       f1, 0x4(r30)
  lfs       f0, -0x4868(r2)
  fadds     f1, f1, f0
  stfs      f1, 0x4(r30)
  lfs       f0, -0x4864(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x80
  li        r0, 0
  stb       r0, 0x8(r30)
  lfs       f0, -0x4898(r2)
  stfs      f0, 0xC0(r31)
  stfs      f0, 0xC4(r31)
  stfs      f0, 0xC8(r31)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0x4(r30)

.loc_0x80:
  lfs       f1, 0x4(r30)
  bl        0x62A4C
  lfs       f2, 0x4(r30)
  lfs       f0, -0x4864(r2)
  lfs       f3, -0x4898(r2)
  fdivs     f0, f2, f0
  lfs       f2, -0x4860(r2)
  fsubs     f0, f3, f0
  fmuls     f0, f2, f0
  fmuls     f0, f0, f1
  fsubs     f1, f3, f0
  fadds     f0, f3, f0
  stfs      f1, 0xC0(r31)
  stfs      f0, 0xC4(r31)
  stfs      f3, 0xC8(r31)
  b         .loc_0xEC

.loc_0xC0:
  cmplwi    r3, 0
  beq-      .loc_0xEC
  lfs       f1, 0x58(r3)
  lfs       f0, -0x48C8(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xEC
  bl        -0xB9028
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xEC
  li        r0, 0x1
  stb       r0, 0x8(r30)

.loc_0xEC:
  lwz       r0, 0x34(r1)
  li        r3, 0x1
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801B9320
 * Size:	0002D4
 */
void @unnamed@::MoonIconCallBack::invoke(P2DPane *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x803A
  stw       r0, 0x4(r1)
  subi      r5, r5, 0x2848
  stwu      r1, -0x60(r1)
  stfd      f31, 0x58(r1)
  stw       r31, 0x54(r1)
  addi      r31, r5, 0x2F0
  stw       r30, 0x50(r1)
  addi      r30, r4, 0
  stw       r29, 0x4C(r1)
  addi      r29, r3, 0
  lfs       f0, -0x485C(r2)
  lfs       f1, 0x2F0(r5)
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x68
  lfs       f0, -0x4858(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0x68
  lbz       r0, 0xC(r30)
  li        r3, 0
  rlwimi    r0,r3,7,24,24
  stb       r0, 0xC(r30)
  b         .loc_0x2B0

.loc_0x68:
  lfs       f31, -0x4884(r2)
  li        r3, 0x1
  lbz       r0, 0xC(r30)
  rlwimi    r0,r3,7,24,24
  stb       r0, 0xC(r30)
  lfs       f2, 0x0(r31)
  lfs       f1, -0x485C(r2)
  fcmpo     cr0, f2, f1
  cror      2, 0x1, 0x2
  bne-      .loc_0xB8
  lfs       f0, -0x4858(r2)
  fcmpo     cr0, f2, f0
  cror      2, 0, 0x2
  bne-      .loc_0xB8
  fsubs     f2, f2, f1
  lfs       f1, -0x4854(r2)
  lfs       f0, -0x4898(r2)
  fdivs     f4, f2, f1
  fsubs     f5, f0, f4
  b         .loc_0xE8

.loc_0xB8:
  lfs       f0, -0x485C(r2)
  fcmpo     cr0, f2, f0
  bge-      .loc_0xD0
  lfs       f0, -0x4888(r2)
  fadds     f2, f2, f0
  b         .loc_0xD8

.loc_0xD0:
  lfs       f0, -0x4858(r2)
  fsubs     f2, f2, f0

.loc_0xD8:
  lfs       f1, -0x4854(r2)
  lfs       f0, -0x4898(r2)
  fdivs     f5, f2, f1
  fsubs     f4, f0, f5

.loc_0xE8:
  lfs       f0, 0x8(r29)
  lfs       f1, 0x10(r29)
  fmuls     f2, f0, f5
  lfs       f0, -0x48C8(r2)
  fmuls     f1, f1, f4
  lha       r3, 0x18(r30)
  lha       r0, 0x1C(r30)
  fadds     f1, f2, f1
  sub       r0, r0, r3
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x124
  lfs       f0, -0x48C4(r2)
  fadds     f1, f0, f1
  b         .loc_0x12C

.loc_0x124:
  lfs       f0, -0x48C4(r2)
  fsubs     f1, f1, f0

.loc_0x12C:
  lfs       f0, 0x4(r29)
  fctiwz    f3, f1
  lfs       f1, 0xC(r29)
  fmuls     f2, f0, f5
  lfs       f0, -0x48C8(r2)
  fmuls     f1, f1, f4
  stfd      f3, 0x40(r1)
  fadds     f1, f2, f1
  lwz       r5, 0x44(r1)
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x168
  lfs       f0, -0x48C4(r2)
  fadds     f0, f0, f1
  b         .loc_0x170

.loc_0x168:
  lfs       f0, -0x48C4(r2)
  fsubs     f0, f1, f0

.loc_0x170:
  fctiwz    f0, f0
  mr        r3, r30
  lwz       r12, 0x0(r30)
  srawi     r4, r0, 0x1
  srawi     r0, r0, 0x1
  stfd      f0, 0x40(r1)
  sub       r5, r5, r0
  lwz       r12, 0x14(r12)
  lwz       r0, 0x44(r1)
  mtlr      r12
  sub       r4, r0, r4
  blrl      
  lfs       f1, 0x14(r29)
  lfs       f0, -0x4850(r2)
  fadds     f0, f1, f0
  stfs      f0, 0x14(r29)
  lfs       f1, -0x48A8(r2)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x1C8
  lfs       f0, 0x14(r29)
  fsubs     f0, f0, f1
  stfs      f0, 0x14(r29)

.loc_0x1C8:
  lfs       f1, 0x14(r29)
  bl        0x627FC
  lha       r5, 0x1A(r30)
  mr        r3, r30
  lha       r0, 0x1E(r30)
  li        r4, 0x7A
  lfs       f0, -0x484C(r2)
  sub       r6, r0, r5
  lha       r5, 0x18(r30)
  lha       r0, 0x1C(r30)
  srawi     r6, r6, 0x1
  fmuls     f1, f0, f1
  lfs       f0, -0x4848(r2)
  sub       r0, r0, r5
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r30)
  extsh     r0, r6
  fsubs     f1, f1, f0
  sth       r0, 0xBA(r30)
  bl        -0x32D2C
  lfs       f2, 0x0(r31)
  lfs       f0, -0x4844(r2)
  fcmpo     cr0, f2, f0
  ble-      .loc_0x250
  lfs       f0, -0x485C(r2)
  fcmpo     cr0, f2, f0
  cror      2, 0, 0x2
  bne-      .loc_0x250
  fsubs     f1, f0, f2
  lfs       f0, -0x48C4(r2)
  fdivs     f0, f1, f0
  fmuls     f31, f31, f0
  b         .loc_0x27C

.loc_0x250:
  lfs       f1, -0x4858(r2)
  fcmpo     cr0, f2, f1
  ble-      .loc_0x27C
  lfs       f0, -0x4840(r2)
  fcmpo     cr0, f2, f0
  cror      2, 0, 0x2
  bne-      .loc_0x27C
  fsubs     f1, f2, f1
  lfs       f0, -0x48C4(r2)
  fdivs     f0, f1, f0
  fmuls     f31, f31, f0

.loc_0x27C:
  lfs       f0, -0x48C8(r2)
  fcmpo     cr0, f31, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x298
  lfs       f0, -0x48C4(r2)
  fadds     f0, f0, f31
  b         .loc_0x2A0

.loc_0x298:
  lfs       f0, -0x48C4(r2)
  fsubs     f0, f31, f0

.loc_0x2A0:
  fctiwz    f0, f0
  stfd      f0, 0x40(r1)
  lwz       r0, 0x44(r1)
  stb       r0, 0xF0(r30)

.loc_0x2B0:
  lwz       r0, 0x64(r1)
  li        r3, 0x1
  lfd       f31, 0x58(r1)
  lwz       r31, 0x54(r1)
  lwz       r30, 0x50(r1)
  lwz       r29, 0x4C(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801B95F4
 * Size:	0002E4
 */
void @unnamed@::SunIcon2CallBack::invoke(P2DPane *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x803A
  stw       r0, 0x4(r1)
  subi      r5, r5, 0x2848
  stwu      r1, -0x80(r1)
  stfd      f31, 0x78(r1)
  stw       r31, 0x74(r1)
  stw       r30, 0x70(r1)
  addi      r30, r5, 0x2F0
  stw       r29, 0x6C(r1)
  addi      r29, r4, 0
  stw       r28, 0x68(r1)
  addi      r28, r3, 0
  lfs       f1, -0x485C(r2)
  lfs       f2, 0x2F0(r5)
  fcmpo     cr0, f2, f1
  cror      2, 0x1, 0x2
  bne-      .loc_0x70
  lfs       f0, -0x4858(r2)
  fcmpo     cr0, f2, f0
  cror      2, 0, 0x2
  bne-      .loc_0x70
  fsubs     f2, f2, f1
  lfs       f1, -0x4854(r2)
  lfs       f0, -0x4898(r2)
  fdivs     f4, f2, f1
  fsubs     f5, f0, f4
  b         .loc_0xA0

.loc_0x70:
  lfs       f0, -0x485C(r2)
  fcmpo     cr0, f2, f0
  bge-      .loc_0x88
  lfs       f0, -0x4888(r2)
  fadds     f2, f2, f0
  b         .loc_0x90

.loc_0x88:
  lfs       f0, -0x4858(r2)
  fsubs     f2, f2, f0

.loc_0x90:
  lfs       f1, -0x4854(r2)
  lfs       f0, -0x4898(r2)
  fdivs     f5, f2, f1
  fsubs     f4, f0, f5

.loc_0xA0:
  lfs       f0, 0x8(r28)
  lfs       f1, 0x10(r28)
  fmuls     f2, f0, f5
  lfs       f0, -0x48C8(r2)
  fmuls     f1, f1, f4
  lha       r3, 0x18(r29)
  lha       r0, 0x1C(r29)
  fadds     f1, f2, f1
  sub       r0, r0, r3
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0xDC
  lfs       f0, -0x48C4(r2)
  fadds     f1, f0, f1
  b         .loc_0xE4

.loc_0xDC:
  lfs       f0, -0x48C4(r2)
  fsubs     f1, f1, f0

.loc_0xE4:
  lfs       f0, 0x4(r28)
  fctiwz    f3, f1
  lfs       f1, 0xC(r28)
  fmuls     f2, f0, f5
  lfs       f0, -0x48C8(r2)
  fmuls     f1, f1, f4
  stfd      f3, 0x60(r1)
  fadds     f1, f2, f1
  lwz       r5, 0x64(r1)
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x120
  lfs       f0, -0x48C4(r2)
  fadds     f0, f0, f1
  b         .loc_0x128

.loc_0x120:
  lfs       f0, -0x48C4(r2)
  fsubs     f0, f1, f0

.loc_0x128:
  fctiwz    f0, f0
  mr        r3, r29
  lwz       r12, 0x0(r29)
  srawi     r4, r0, 0x1
  srawi     r0, r0, 0x1
  stfd      f0, 0x60(r1)
  sub       r5, r5, r0
  lwz       r12, 0x14(r12)
  lwz       r0, 0x64(r1)
  mtlr      r12
  sub       r4, r0, r4
  blrl      
  lfs       f1, 0x0(r30)
  mr        r31, r29
  lfs       f0, -0x485C(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x2AC
  lfs       f0, -0x4858(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0x2AC
  lbz       r0, 0xC(r31)
  li        r3, 0x1
  rlwimi    r0,r3,7,24,24
  lis       r3, 0x803A
  stb       r0, 0xC(r31)
  subi      r3, r3, 0x2848
  lwz       r0, 0x338(r3)
  cmpwi     r0, 0
  bne-      .loc_0x2BC
  lfs       f1, -0x489C(r2)
  lfs       f0, 0xBC(r29)
  fmuls     f1, f1, f0
  bl        0x62544
  lha       r5, 0x1A(r29)
  fmr       f31, f1
  lha       r4, 0x1E(r29)
  lha       r3, 0x18(r29)
  lha       r0, 0x1C(r29)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  lfs       f1, 0x14(r28)
  sub       r0, r0, r3
  lfs       f0, 0xBC(r29)
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r31)
  extsh     r0, r4
  fadds     f1, f1, f0
  addi      r3, r31, 0
  sth       r0, 0xBA(r31)
  li        r4, 0x2
  bl        -0x32FE4
  lfs       f0, -0x4838(r2)
  lfs       f1, -0x483C(r2)
  fmuls     f0, f0, f31
  fadds     f0, f1, f0
  stfs      f0, 0xC0(r31)
  stfs      f0, 0xC4(r31)
  stfs      f0, 0xC8(r31)
  lfs       f1, -0x4830(r2)
  lfs       f3, 0x0(r30)
  lfs       f0, -0x482C(r2)
  fmuls     f1, f1, f31
  lfs       f2, -0x4834(r2)
  fcmpo     cr0, f3, f0
  fadds     f2, f2, f1
  bge-      .loc_0x254
  lfs       f1, -0x485C(r2)
  lfs       f0, -0x48C4(r2)
  fsubs     f1, f3, f1
  fdivs     f0, f1, f0
  fmuls     f2, f2, f0
  b         .loc_0x274

.loc_0x254:
  lfs       f0, -0x4828(r2)
  fcmpo     cr0, f3, f0
  ble-      .loc_0x274
  lfs       f1, -0x4858(r2)
  lfs       f0, -0x48C4(r2)
  fsubs     f1, f1, f3
  fdivs     f0, f1, f0
  fmuls     f2, f2, f0

.loc_0x274:
  lfs       f0, -0x48C8(r2)
  fcmpo     cr0, f2, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x290
  lfs       f0, -0x48C4(r2)
  fadds     f0, f0, f2
  b         .loc_0x298

.loc_0x290:
  lfs       f0, -0x48C4(r2)
  fsubs     f0, f2, f0

.loc_0x298:
  fctiwz    f0, f0
  stfd      f0, 0x60(r1)
  lwz       r0, 0x64(r1)
  stb       r0, 0xF0(r31)
  b         .loc_0x2BC

.loc_0x2AC:
  lbz       r0, 0xC(r31)
  li        r3, 0
  rlwimi    r0,r3,7,24,24
  stb       r0, 0xC(r31)

.loc_0x2BC:
  lwz       r0, 0x84(r1)
  li        r3, 0x1
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
 * Address:	801B98D8
 * Size:	0001B8
 */
void @unnamed@::SunIcon1CallBack::invoke(P2DPane *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x803A
  stw       r0, 0x4(r1)
  subi      r5, r5, 0x2848
  stwu      r1, -0x70(r1)
  stfd      f31, 0x68(r1)
  stw       r31, 0x64(r1)
  stw       r30, 0x60(r1)
  addi      r30, r5, 0x2F0
  stw       r29, 0x5C(r1)
  addi      r29, r4, 0
  addi      r31, r29, 0
  stw       r28, 0x58(r1)
  addi      r28, r3, 0
  lfs       f0, -0x485C(r2)
  lfs       f1, 0x2F0(r5)
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x180
  lfs       f0, -0x4858(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0x180
  lbz       r0, 0xC(r31)
  li        r3, 0x1
  rlwimi    r0,r3,7,24,24
  stb       r0, 0xC(r31)
  lwz       r0, 0x338(r5)
  cmpwi     r0, 0
  bne-      .loc_0x190
  lfs       f1, -0x489C(r2)
  lfs       f0, 0xBC(r29)
  fmuls     f1, f1, f0
  bl        0x6238C
  lha       r5, 0x1A(r29)
  fmr       f31, f1
  lha       r4, 0x1E(r29)
  lha       r3, 0x18(r29)
  lha       r0, 0x1C(r29)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  lfs       f1, 0x4(r28)
  sub       r0, r0, r3
  lfs       f0, 0xBC(r29)
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r31)
  extsh     r0, r4
  fadds     f1, f1, f0
  addi      r3, r31, 0
  sth       r0, 0xBA(r31)
  li        r4, 0x2
  bl        -0x3319C
  lfs       f0, -0x4838(r2)
  lfs       f1, -0x483C(r2)
  fmuls     f0, f0, f31
  fadds     f0, f1, f0
  stfs      f0, 0xC0(r31)
  stfs      f0, 0xC4(r31)
  stfs      f0, 0xC8(r31)
  lfs       f1, -0x4830(r2)
  lfs       f3, 0x0(r30)
  lfs       f0, -0x482C(r2)
  fmuls     f1, f1, f31
  lfs       f2, -0x4834(r2)
  fcmpo     cr0, f3, f0
  fadds     f2, f2, f1
  bge-      .loc_0x128
  lfs       f1, -0x485C(r2)
  lfs       f0, -0x48C4(r2)
  fsubs     f1, f3, f1
  fdivs     f0, f1, f0
  fmuls     f2, f2, f0
  b         .loc_0x148

.loc_0x128:
  lfs       f0, -0x4828(r2)
  fcmpo     cr0, f3, f0
  ble-      .loc_0x148
  lfs       f1, -0x4858(r2)
  lfs       f0, -0x48C4(r2)
  fsubs     f1, f1, f3
  fdivs     f0, f1, f0
  fmuls     f2, f2, f0

.loc_0x148:
  lfs       f0, -0x48C8(r2)
  fcmpo     cr0, f2, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x164
  lfs       f0, -0x48C4(r2)
  fadds     f0, f0, f2
  b         .loc_0x16C

.loc_0x164:
  lfs       f0, -0x48C4(r2)
  fsubs     f0, f2, f0

.loc_0x16C:
  fctiwz    f0, f0
  stfd      f0, 0x50(r1)
  lwz       r0, 0x54(r1)
  stb       r0, 0xF0(r31)
  b         .loc_0x190

.loc_0x180:
  lbz       r0, 0xC(r31)
  li        r3, 0
  rlwimi    r0,r3,7,24,24
  stb       r0, 0xC(r31)

.loc_0x190:
  lwz       r0, 0x74(r1)
  li        r3, 0x1
  lfd       f31, 0x68(r1)
  lwz       r31, 0x64(r1)
  lwz       r30, 0x60(r1)
  lwz       r29, 0x5C(r1)
  lwz       r28, 0x58(r1)
  addi      r1, r1, 0x70
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801B9A90
 * Size:	000078
 */
void @unnamed@::SunCapsuleCallBack::invoke(P2DPane *)
{
/*
.loc_0x0:
  stwu      r1, -0x30(r1)
  lis       r5, 0x8039
  addi      r0, r5, 0x840
  lhz       r6, 0x4(r3)
  addi      r5, r6, 0x7FF
  sth       r5, 0x4(r3)
  lhz       r3, 0x4(r3)
  lfs       f2, -0x4820(r2)
  rlwinm    r3,r3,30,18,29
  lfs       f3, -0x4824(r2)
  add       r3, r0, r3
  lfs       f0, -0x48C8(r2)
  lfs       f1, 0x0(r3)
  fmuls     f1, f2, f1
  fadds     f1, f3, f1
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x54
  lfs       f0, -0x48C4(r2)
  fadds     f0, f0, f1
  b         .loc_0x5C

.loc_0x54:
  lfs       f0, -0x48C4(r2)
  fsubs     f0, f1, f0

.loc_0x5C:
  fctiwz    f0, f0
  li        r3, 0x1
  stfd      f0, 0x28(r1)
  lwz       r0, 0x2C(r1)
  stb       r0, 0xF0(r4)
  addi      r1, r1, 0x30
  blr
*/
}

/*
 * --INFO--
 * Address:	801B9B08
 * Size:	00014C
 */
void @unnamed@::SunBaseCallBack::invoke(P2DPane *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x803A
  stw       r0, 0x4(r1)
  subi      r5, r5, 0x2848
  stwu      r1, -0x28(r1)
  lfs       f1, -0x485C(r2)
  lfs       f2, 0x2F0(r5)
  fcmpo     cr0, f2, f1
  cror      2, 0x1, 0x2
  bne-      .loc_0x50
  lfs       f0, -0x4858(r2)
  fcmpo     cr0, f2, f0
  cror      2, 0, 0x2
  bne-      .loc_0x50
  fsubs     f2, f2, f1
  lfs       f1, -0x4854(r2)
  lfs       f0, -0x4898(r2)
  fdivs     f4, f2, f1
  fsubs     f5, f0, f4
  b         .loc_0x80

.loc_0x50:
  lfs       f0, -0x485C(r2)
  fcmpo     cr0, f2, f0
  bge-      .loc_0x68
  lfs       f0, -0x4888(r2)
  fadds     f2, f2, f0
  b         .loc_0x70

.loc_0x68:
  lfs       f0, -0x4858(r2)
  fsubs     f2, f2, f0

.loc_0x70:
  lfs       f1, -0x4854(r2)
  lfs       f0, -0x4898(r2)
  fdivs     f5, f2, f1
  fsubs     f4, f0, f5

.loc_0x80:
  lfs       f0, 0x4(r3)
  lfs       f1, 0xC(r3)
  fmuls     f2, f0, f5
  lfs       f0, -0x48C8(r2)
  fmuls     f1, f1, f4
  lha       r5, 0x18(r4)
  lha       r0, 0x1C(r4)
  fadds     f1, f2, f1
  sub       r0, r0, r5
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0xBC
  lfs       f0, -0x48C4(r2)
  fadds     f1, f0, f1
  b         .loc_0xC4

.loc_0xBC:
  lfs       f0, -0x48C4(r2)
  fsubs     f1, f1, f0

.loc_0xC4:
  lfs       f0, 0x0(r3)
  fctiwz    f3, f1
  lfs       f1, 0x8(r3)
  fmuls     f2, f0, f5
  lfs       f0, -0x48C8(r2)
  fmuls     f1, f1, f4
  stfd      f3, 0x20(r1)
  fadds     f1, f2, f1
  lwz       r5, 0x24(r1)
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x100
  lfs       f0, -0x48C4(r2)
  fadds     f0, f0, f1
  b         .loc_0x108

.loc_0x100:
  lfs       f0, -0x48C4(r2)
  fsubs     f0, f1, f0

.loc_0x108:
  fctiwz    f0, f0
  mr        r3, r4
  lwz       r12, 0x0(r4)
  srawi     r4, r0, 0x1
  srawi     r0, r0, 0x1
  stfd      f0, 0x20(r1)
  sub       r5, r5, r0
  lwz       r12, 0x14(r12)
  lwz       r0, 0x24(r1)
  mtlr      r12
  sub       r4, r0, r4
  blrl      
  li        r3, 0x1
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801B9C54
 * Size:	000194
 */
void @unnamed@::MapPikminWindowCallBack::invoke(P2DPane *)
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
  lwz       r5, 0x2DEC(r13)
  lfs       f1, 0x8(r3)
  lfs       f0, 0x28C(r5)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r3)
  lfs       f1, 0x8(r3)
  lfs       f0, -0x489C(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x48
  fsubs     f0, f1, f0
  stfs      f0, 0x8(r30)

.loc_0x48:
  lwz       r3, 0x31A0(r13)
  lha       r0, 0x6(r3)
  cmpwi     r0, 0x64
  bne-      .loc_0x84
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x4(r30)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r30)
  lfs       f1, 0x4(r30)
  lfs       f0, -0x4898(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xAC
  stfs      f0, 0x4(r30)
  b         .loc_0xAC

.loc_0x84:
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x4(r30)
  lfs       f0, 0x28C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x4(r30)
  lfs       f1, 0x4(r30)
  lfs       f0, -0x48C8(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xAC
  stfs      f0, 0x4(r30)

.loc_0xAC:
  lfs       f1, 0x8(r30)
  lfs       f0, -0x48C4(r2)
  lfs       f2, -0x48A8(r2)
  fmuls     f0, f1, f0
  fmuls     f1, f2, f0
  bl        0x61FD4
  lfs       f4, -0x4898(r2)
  lfs       f5, -0x48C4(r2)
  fadds     f0, f4, f1
  lfs       f6, 0x4(r30)
  lfs       f2, -0x481C(r2)
  lfs       f1, -0x4884(r2)
  fmuls     f3, f5, f0
  lfs       f0, -0x48C8(r2)
  fmuls     f6, f6, f3
  fsubs     f3, f4, f6
  fmuls     f4, f2, f6
  fmuls     f1, f1, f3
  fadds     f1, f4, f1
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x10C
  fadds     f0, f5, f1
  b         .loc_0x110

.loc_0x10C:
  fsubs     f0, f1, f5

.loc_0x110:
  lfs       f1, -0x4884(r2)
  fctiwz    f2, f0
  lfs       f0, -0x48C8(r2)
  fmuls     f1, f1, f3
  stfd      f2, 0x58(r1)
  fadds     f1, f4, f1
  lwz       r0, 0x5C(r1)
  rlwinm    r5,r0,0,24,31
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x148
  lfs       f0, -0x48C4(r2)
  fadds     f0, f0, f1
  b         .loc_0x150

.loc_0x148:
  lfs       f0, -0x48C4(r2)
  fsubs     f0, f1, f0

.loc_0x150:
  fctiwz    f0, f0
  li        r4, 0xFF
  stb       r4, 0x4C(r1)
  li        r3, 0x1
  stfd      f0, 0x58(r1)
  lwz       r0, 0x5C(r1)
  stb       r0, 0x4D(r1)
  stb       r5, 0x4E(r1)
  stb       r4, 0x4F(r1)
  lwz       r0, 0x4C(r1)
  stw       r0, 0x108(r31)
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
 * Address:	801B9DE8
 * Size:	000118
 */
void @unnamed@::PikiIconCallBack::invoke(P2DPane *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stfd      f31, 0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r4
  stw       r30, 0x20(r1)
  mr        r30, r3
  lwz       r5, 0x2DEC(r13)
  lfs       f1, 0x4(r3)
  lfs       f0, 0x28C(r5)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r3)
  lfs       f0, 0x4(r3)
  lfs       f1, 0x1980(r13)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x48
  stfs      f1, 0x4(r30)

.loc_0x48:
  lfs       f2, 0x4(r30)
  lfs       f1, 0x1980(r13)
  lfs       f0, -0x4818(r2)
  fdivs     f31, f2, f1
  fmuls     f1, f0, f31
  bl        0x61D10
  lfs       f3, -0x4898(r2)
  lfs       f2, -0x4860(r2)
  fsubs     f0, f3, f31
  fmuls     f0, f2, f0
  fmuls     f0, f0, f1
  fadds     f0, f3, f0
  stfs      f0, 0xC0(r31)
  stfs      f0, 0xC4(r31)
  stfs      f0, 0xC8(r31)
  lwz       r3, 0x31A0(r13)
  lwz       r0, 0x0(r3)
  cmpwi     r0, 0
  blt-      .loc_0x9C
  cmpwi     r0, 0x13
  blt-      .loc_0xA4

.loc_0x9C:
  li        r0, 0
  stw       r0, 0x0(r3)

.loc_0xA4:
  lwz       r3, 0x31A0(r13)
  lbz       r0, 0xF1(r31)
  lwz       r3, 0x0(r3)
  cmplwi    r0, 0
  rlwinm    r0,r3,2,0,29
  add       r3, r30, r0
  lwz       r0, 0x8(r3)
  ble-      .loc_0xC8
  stw       r0, 0xEC(r31)

.loc_0xC8:
  lwz       r3, 0x31A0(r13)
  lwz       r0, 0x54(r30)
  lwz       r3, 0x0(r3)
  cmpw      r0, r3
  beq-      .loc_0xEC
  cmpwi     r3, 0
  beq-      .loc_0xEC
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0x4(r30)

.loc_0xEC:
  lwz       r4, 0x31A0(r13)
  li        r3, 0x1
  lwz       r0, 0x0(r4)
  stw       r0, 0x54(r30)
  lwz       r0, 0x34(r1)
  lfd       f31, 0x28(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801B9F00
 * Size:	0001F8
 */
void zen::NumberPicCallBack<short>::invoke(P2DPane *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x68(r1)
  stfd      f31, 0x60(r1)
  stw       r31, 0x5C(r1)
  addi      r31, r4, 0
  stw       r30, 0x58(r1)
  mr        r30, r3
  lha       r5, 0x10(r3)
  lis       r3, 0x6666
  lwz       r7, 0x8(r30)
  addi      r0, r3, 0x6667
  divw      r4, r5, r7
  mulhw     r0, r0, r4
  srawi     r0, r0, 0x2
  rlwinm    r3,r0,1,31,31
  add       r0, r0, r3
  mulli     r0, r0, 0xA
  sub.      r6, r4, r0
  bge-      .loc_0x54
  li        r6, 0

.loc_0x54:
  lwz       r4, 0x4(r30)
  lis       r3, 0x6666
  addi      r0, r3, 0x6667
  lha       r3, 0x0(r4)
  divw      r5, r3, r7
  mulhw     r0, r0, r5
  srawi     r0, r0, 0x2
  rlwinm    r3,r0,1,31,31
  add       r0, r0, r3
  mulli     r0, r0, 0xA
  sub.      r0, r5, r0
  bge-      .loc_0x88
  li        r0, 0

.loc_0x88:
  cmpw      r0, r6
  beq-      .loc_0x114
  lbz       r0, 0x14(r30)
  cmplwi    r0, 0
  beq-      .loc_0xCC
  addi      r3, r30, 0x4
  bl        .loc_0x1F8
  lbz       r0, 0xF1(r31)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0xF8
  stw       r0, 0xEC(r31)
  b         .loc_0xF8

.loc_0xCC:
  addi      r3, r30, 0x4
  bl        .loc_0x1F8
  lbz       r0, 0xF1(r31)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0xF8
  stw       r0, 0xEC(r31)

.loc_0xF8:
  lwz       r3, 0x4(r30)
  lha       r4, 0x10(r30)
  lha       r0, 0x0(r3)
  sub       r0, r0, r4
  sth       r0, 0x12(r30)
  lfs       f0, -0x48C8(r2)
  stfs      f0, 0xC(r30)

.loc_0x114:
  lha       r0, 0x12(r30)
  cmpwi     r0, 0
  beq-      .loc_0x1CC
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0xC(r30)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0xC(r30)
  lfs       f1, 0xC(r30)
  lfs       f0, -0x48C4(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x150
  stfs      f0, 0xC(r30)
  li        r0, 0
  sth       r0, 0x12(r30)

.loc_0x150:
  lfs       f1, 0xC(r30)
  lfs       f0, -0x48C4(r2)
  lha       r0, 0x12(r30)
  fdivs     f2, f1, f0
  lfs       f0, -0x4898(r2)
  lfs       f1, -0x4814(r2)
  cmpwi     r0, 0
  fsubs     f0, f0, f2
  fmuls     f31, f1, f0
  ble-      .loc_0x1A4
  lfs       f0, -0x4818(r2)
  fmuls     f1, f0, f2
  bl        0x61AD4
  lfs       f2, -0x4898(r2)
  fadds     f0, f2, f1
  fmuls     f0, f31, f0
  fadds     f0, f2, f0
  stfs      f0, 0xC0(r31)
  stfs      f0, 0xC4(r31)
  stfs      f2, 0xC8(r31)
  b         .loc_0x1CC

.loc_0x1A4:
  lfs       f0, -0x4818(r2)
  fmuls     f1, f0, f2
  bl        0x61AA8
  lfs       f2, -0x4898(r2)
  fadds     f0, f2, f1
  fmuls     f0, f31, f0
  fsubs     f0, f2, f0
  stfs      f0, 0xC0(r31)
  stfs      f0, 0xC4(r31)
  stfs      f2, 0xC8(r31)

.loc_0x1CC:
  lwz       r4, 0x4(r30)
  li        r3, 0x1
  lha       r0, 0x0(r4)
  sth       r0, 0x10(r30)
  lwz       r0, 0x6C(r1)
  lfd       f31, 0x60(r1)
  lwz       r31, 0x5C(r1)
  lwz       r30, 0x58(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr       

.loc_0x1F8:
*/
}

/*
 * --INFO--
 * Address:	801BA0F8
 * Size:	00003C
 */
void zen::FigureTex<short>::getNumber(short &)
{
/*
.loc_0x0:
  lha       r5, 0x0(r4)
  lis       r4, 0x6666
  lwz       r3, 0x4(r3)
  addi      r0, r4, 0x6667
  divw      r4, r5, r3
  mulhw     r0, r0, r4
  srawi     r0, r0, 0x2
  rlwinm    r3,r0,1,31,31
  add       r0, r0, r3
  mulli     r0, r0, 0xA
  sub.      r0, r4, r0
  mr        r3, r0
  bgelr-    
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801BA134
 * Size:	000008
 */
void @unnamed@::SunBaseCallBack::@16@invoke(P2DPane *)
{
/*
.loc_0x0:
  subi      r3, r3, 0x10
  b         -0x630
*/
}