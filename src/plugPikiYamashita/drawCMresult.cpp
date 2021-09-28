

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
 * Address:	801EEB68
 * Size:	000A54
 */
void zen::DrawCMresult::DrawCMresult()
{
/*
.loc_0x0:
  mflr      r0
  li        r7, 0
  stw       r0, 0x4(r1)
  li        r6, -0x1
  lis       r4, 0x802E
  stwu      r1, -0x120(r1)
  stmw      r27, 0x10C(r1)
  addi      r31, r3, 0
  lis       r3, 0x8022
  addi      r5, r3, 0x2758
  addi      r29, r4, 0x6E88
  li        r3, 0x4C4
  lfs       f0, -0x3E38(r2)
  stfs      f0, 0x28(r31)
  stfs      f0, 0x24(r31)
  stfs      f0, 0x20(r31)
  stw       r7, 0x1C(r31)
  stw       r6, 0x2C(r31)
  lwz       r4, 0x0(r5)
  lwz       r0, 0x4(r5)
  stw       r4, 0x30(r31)
  stw       r0, 0x34(r31)
  lwz       r0, 0x8(r5)
  stw       r0, 0x38(r31)
  stw       r7, 0x48(r31)
  stw       r6, 0x4C(r31)
  lwz       r4, 0x0(r5)
  lwz       r0, 0x4(r5)
  stw       r4, 0x50(r31)
  stw       r0, 0x54(r31)
  lwz       r0, 0x8(r5)
  stw       r0, 0x58(r31)
  stw       r7, 0x64(r31)
  stw       r7, 0x68(r31)
  stw       r7, 0x6C(r31)
  stw       r7, 0x70(r31)
  lwz       r4, 0x0(r5)
  lwz       r0, 0x4(r5)
  stw       r4, 0x78(r31)
  stw       r0, 0x7C(r31)
  lwz       r0, 0x8(r5)
  stw       r0, 0x80(r31)
  stw       r7, 0x74(r31)
  bl        -0x1A7C10
  addi      r27, r3, 0
  mr.       r3, r27
  beq-      .loc_0xCC
  li        r4, 0x8
  li        r5, 0x80
  li        r6, 0x80
  bl        -0x5370

.loc_0xCC:
  stw       r27, 0x90(r31)
  li        r3, 0x100
  bl        -0x1A7C38
  addi      r27, r3, 0
  mr.       r3, r27
  beq-      .loc_0xF8
  addi      r4, r29, 0x24
  li        r5, 0
  li        r6, 0x1
  li        r7, 0x1
  bl        -0x2F6E8

.loc_0xF8:
  stw       r27, 0x10(r31)
  li        r3, 0x100
  bl        -0x1A7C64
  addi      r27, r3, 0
  mr.       r3, r27
  beq-      .loc_0x124
  addi      r4, r29, 0x3C
  li        r5, 0
  li        r6, 0x1
  li        r7, 0x1
  bl        -0x2F714

.loc_0x124:
  stw       r27, 0x14(r31)
  li        r3, 0x100
  bl        -0x1A7C90
  addi      r27, r3, 0
  mr.       r3, r27
  beq-      .loc_0x150
  addi      r4, r29, 0x54
  li        r5, 0
  li        r6, 0x1
  li        r7, 0x1
  bl        -0x2F740

.loc_0x150:
  stw       r27, 0x18(r31)
  li        r3, 0x15C
  lwz       r6, 0x10(r31)
  lwz       r5, 0x14(r31)
  lwz       r4, 0x18(r31)
  addi      r30, r6, 0x4
  addi      r28, r5, 0x4
  addi      r29, r4, 0x4
  bl        -0x1A7CD4
  addi      r27, r3, 0
  mr.       r3, r27
  beq-      .loc_0x184
  bl        0x6818

.loc_0x184:
  stw       r27, 0x9C(r31)
  addi      r3, r28, 0
  lis       r4, 0x7261
  lwz       r12, 0x0(r28)
  addi      r4, r4, 0x6E6B
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r12, 0x0(r3)
  li        r4, 0x152
  li        r5, 0x66
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lis       r4, 0x6265
  addi      r4, r4, 0x7374
  lwz       r12, 0x34(r12)
  li        r5, 0x1
  mtlr      r12
  blrl      
  lwz       r12, 0x0(r3)
  li        r4, 0x1B1
  li        r5, 0x2C
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  addi      r3, r31, 0x1C
  addi      r4, r30, 0
  bl        -0x18E8
  addi      r3, r31, 0x48
  addi      r4, r28, 0
  bl        -0x1370
  addi      r3, r31, 0x68
  addi      r4, r29, 0
  bl        -0x86C
  lfs       f0, -0x3E38(r2)
  lis       r4, 0x6269
  li        r29, 0
  stfs      f0, 0x94(r31)
  li        r0, -0x1
  addi      r3, r30, 0
  stw       r29, 0x84(r31)
  addi      r4, r4, 0x676C
  li        r5, 0x1
  stw       r29, 0x88(r31)
  stw       r0, 0x8C(r31)
  lwz       r12, 0x0(r30)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r28, r3, 0
  li        r3, 0x1C
  bl        -0x1A7DC4
  mr.       r27, r3
  beq-      .loc_0x36C
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r27)
  addi      r4, r28, 0
  addi      r3, r27, 0x4
  li        r5, 0x12
  bl        -0x3E6EC
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r27)
  addi      r3, r27, 0x4
  bl        -0x2F710
  addi      r0, r31, 0x88
  stw       r0, 0x4(r27)
  li        r0, 0x64
  lis       r3, 0x802D
  stw       r0, 0x8(r27)
  addi      r0, r3, 0x2FE4
  stw       r0, 0x0(r27)
  stb       r29, 0x18(r27)
  lwz       r3, 0x4(r27)
  lwz       r0, 0x0(r3)
  stw       r0, 0x10(r27)
  stw       r29, 0x14(r27)
  lfs       f0, -0x3E38(r2)
  stfs      f0, 0xC(r27)
  lbz       r0, 0x18(r27)
  cmplwi    r0, 0
  beq-      .loc_0x310
  addi      r3, r27, 0x4
  bl        -0x703F4
  lbz       r0, 0xF1(r28)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x33C
  stw       r0, 0xEC(r28)
  b         .loc_0x33C

.loc_0x310:
  addi      r3, r27, 0x4
  bl        -0x70424
  lbz       r0, 0xF1(r28)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x33C
  stw       r0, 0xEC(r28)

.loc_0x33C:
  lha       r5, 0x1A(r28)
  lha       r4, 0x1E(r28)
  lha       r3, 0x18(r28)
  lha       r0, 0x1C(r28)
  sub       r4, r4, r5
  srawi     r4, r4, 0x1
  sub       r0, r0, r3
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r28)
  extsh     r0, r4
  sth       r0, 0xBA(r28)

.loc_0x36C:
  addi      r3, r28, 0
  addi      r4, r27, 0
  bl        -0x3E840
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lis       r4, 0x6269
  addi      r4, r4, 0x6763
  lwz       r12, 0x34(r12)
  li        r5, 0x1
  mtlr      r12
  blrl      
  addi      r29, r3, 0
  li        r3, 0x1C
  bl        -0x1A7F04
  mr.       r27, r3
  beq-      .loc_0x4B0
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r27)
  addi      r4, r29, 0
  addi      r3, r27, 0x4
  li        r5, 0x12
  bl        -0x3E82C
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r27)
  addi      r3, r27, 0x4
  bl        -0x2F850
  addi      r0, r31, 0x88
  stw       r0, 0x4(r27)
  li        r0, 0xA
  lis       r3, 0x802D
  stw       r0, 0x8(r27)
  addi      r0, r3, 0x2FE4
  li        r4, 0
  stw       r0, 0x0(r27)
  stb       r4, 0x18(r27)
  lwz       r3, 0x4(r27)
  lwz       r0, 0x0(r3)
  stw       r0, 0x10(r27)
  stw       r4, 0x14(r27)
  lfs       f0, -0x3E38(r2)
  stfs      f0, 0xC(r27)
  lbz       r0, 0x18(r27)
  cmplwi    r0, 0
  beq-      .loc_0x454
  addi      r3, r27, 0x4
  bl        -0x70538
  lbz       r0, 0xF1(r29)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x480
  stw       r0, 0xEC(r29)
  b         .loc_0x480

.loc_0x454:
  addi      r3, r27, 0x4
  bl        -0x70568
  lbz       r0, 0xF1(r29)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x480
  stw       r0, 0xEC(r29)

.loc_0x480:
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

.loc_0x4B0:
  addi      r3, r29, 0
  addi      r4, r27, 0
  bl        -0x3E984
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lis       r4, 0x6269
  addi      r4, r4, 0x6772
  lwz       r12, 0x34(r12)
  li        r5, 0x1
  mtlr      r12
  blrl      
  addi      r29, r3, 0
  li        r3, 0x1C
  bl        -0x1A8048
  mr.       r27, r3
  beq-      .loc_0x5F4
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r27)
  addi      r4, r29, 0
  addi      r3, r27, 0x4
  li        r5, 0x12
  bl        -0x3E970
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r27)
  addi      r3, r27, 0x4
  bl        -0x2F994
  addi      r0, r31, 0x88
  stw       r0, 0x4(r27)
  li        r0, 0x1
  lis       r3, 0x802D
  stw       r0, 0x8(r27)
  addi      r0, r3, 0x2FE4
  li        r4, 0
  stw       r0, 0x0(r27)
  stb       r4, 0x18(r27)
  lwz       r3, 0x4(r27)
  lwz       r0, 0x0(r3)
  stw       r0, 0x10(r27)
  stw       r4, 0x14(r27)
  lfs       f0, -0x3E38(r2)
  stfs      f0, 0xC(r27)
  lbz       r0, 0x18(r27)
  cmplwi    r0, 0
  beq-      .loc_0x598
  addi      r3, r27, 0x4
  bl        -0x7067C
  lbz       r0, 0xF1(r29)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x5C4
  stw       r0, 0xEC(r29)
  b         .loc_0x5C4

.loc_0x598:
  addi      r3, r27, 0x4
  bl        -0x706AC
  lbz       r0, 0xF1(r29)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x5C4
  stw       r0, 0xEC(r29)

.loc_0x5C4:
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

.loc_0x5F4:
  addi      r3, r29, 0
  addi      r4, r27, 0
  bl        -0x3EAC8
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lis       r4, 0x7362
  addi      r4, r4, 0x696C
  lwz       r12, 0x34(r12)
  li        r5, 0x1
  mtlr      r12
  blrl      
  addi      r29, r3, 0
  li        r3, 0x1C
  bl        -0x1A818C
  mr.       r27, r3
  beq-      .loc_0x73C
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r27)
  addi      r4, r29, 0
  addi      r3, r27, 0x4
  li        r5, 0x12
  bl        -0x3EAB4
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r27)
  addi      r3, r27, 0x4
  bl        -0x2FAD8
  addi      r0, r31, 0x88
  stw       r0, 0x4(r27)
  li        r0, 0x64
  lis       r3, 0x802D
  stw       r0, 0x8(r27)
  addi      r0, r3, 0x2FE4
  li        r3, 0x1
  stw       r0, 0x0(r27)
  li        r0, 0
  stb       r3, 0x18(r27)
  lwz       r3, 0x4(r27)
  lwz       r3, 0x0(r3)
  stw       r3, 0x10(r27)
  stw       r0, 0x14(r27)
  lfs       f0, -0x3E38(r2)
  stfs      f0, 0xC(r27)
  lbz       r0, 0x18(r27)
  cmplwi    r0, 0
  beq-      .loc_0x6E0
  addi      r3, r27, 0x4
  bl        -0x707C4
  lbz       r0, 0xF1(r29)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x70C
  stw       r0, 0xEC(r29)
  b         .loc_0x70C

.loc_0x6E0:
  addi      r3, r27, 0x4
  bl        -0x707F4
  lbz       r0, 0xF1(r29)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x70C
  stw       r0, 0xEC(r29)

.loc_0x70C:
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

.loc_0x73C:
  addi      r3, r29, 0
  addi      r4, r27, 0
  bl        -0x3EC10
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lis       r4, 0x7362
  addi      r4, r4, 0x6963
  lwz       r12, 0x34(r12)
  li        r5, 0x1
  mtlr      r12
  blrl      
  addi      r29, r3, 0
  li        r3, 0x1C
  bl        -0x1A82D4
  mr.       r27, r3
  beq-      .loc_0x884
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r27)
  addi      r4, r29, 0
  addi      r3, r27, 0x4
  li        r5, 0x12
  bl        -0x3EBFC
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r27)
  addi      r3, r27, 0x4
  bl        -0x2FC20
  addi      r0, r31, 0x88
  stw       r0, 0x4(r27)
  li        r0, 0xA
  lis       r3, 0x802D
  stw       r0, 0x8(r27)
  addi      r0, r3, 0x2FE4
  li        r3, 0x1
  stw       r0, 0x0(r27)
  li        r0, 0
  stb       r3, 0x18(r27)
  lwz       r3, 0x4(r27)
  lwz       r3, 0x0(r3)
  stw       r3, 0x10(r27)
  stw       r0, 0x14(r27)
  lfs       f0, -0x3E38(r2)
  stfs      f0, 0xC(r27)
  lbz       r0, 0x18(r27)
  cmplwi    r0, 0
  beq-      .loc_0x828
  addi      r3, r27, 0x4
  bl        -0x7090C
  lbz       r0, 0xF1(r29)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x854
  stw       r0, 0xEC(r29)
  b         .loc_0x854

.loc_0x828:
  addi      r3, r27, 0x4
  bl        -0x7093C
  lbz       r0, 0xF1(r29)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x854
  stw       r0, 0xEC(r29)

.loc_0x854:
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

.loc_0x884:
  addi      r3, r29, 0
  addi      r4, r27, 0
  bl        -0x3ED58
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lis       r4, 0x7362
  addi      r4, r4, 0x6972
  lwz       r12, 0x34(r12)
  li        r5, 0x1
  mtlr      r12
  blrl      
  addi      r29, r3, 0
  li        r3, 0x1C
  bl        -0x1A841C
  mr.       r27, r3
  beq-      .loc_0x9C8
  lis       r3, 0x802D
  addi      r0, r3, 0x3004
  stw       r0, 0x0(r27)
  addi      r4, r29, 0
  addi      r3, r27, 0x4
  li        r5, 0x12
  bl        -0x3ED44
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  stw       r0, 0x0(r27)
  addi      r3, r27, 0x4
  bl        -0x2FD68
  addi      r0, r31, 0x88
  stw       r0, 0x4(r27)
  li        r4, 0x1
  lis       r3, 0x802D
  stw       r4, 0x8(r27)
  addi      r3, r3, 0x2FE4
  li        r0, 0
  stw       r3, 0x0(r27)
  stb       r4, 0x18(r27)
  lwz       r3, 0x4(r27)
  lwz       r3, 0x0(r3)
  stw       r3, 0x10(r27)
  stw       r0, 0x14(r27)
  lfs       f0, -0x3E38(r2)
  stfs      f0, 0xC(r27)
  lbz       r0, 0x18(r27)
  cmplwi    r0, 0
  beq-      .loc_0x96C
  addi      r3, r27, 0x4
  bl        -0x70A50
  lbz       r0, 0xF1(r29)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2388
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x998
  stw       r0, 0xEC(r29)
  b         .loc_0x998

.loc_0x96C:
  addi      r3, r27, 0x4
  bl        -0x70A80
  lbz       r0, 0xF1(r29)
  lis       r4, 0x803D
  rlwinm    r5,r3,2,0,29
  addi      r3, r4, 0x2360
  add       r3, r3, r5
  cmplwi    r0, 0
  lwz       r0, 0x0(r3)
  ble-      .loc_0x998
  stw       r0, 0xEC(r29)

.loc_0x998:
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

.loc_0x9C8:
  addi      r3, r29, 0
  addi      r4, r27, 0
  bl        -0x3EE9C
  li        r3, 0x10
  bl        -0x1A853C
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0xA2C
  lis       r3, 0x802E
  addi      r0, r3, 0x6F84
  stw       r0, 0x0(r27)
  li        r4, 0
  lis       r3, 0x802E
  stb       r4, 0x8(r27)
  addi      r0, r3, 0x6F78
  li        r3, 0x14
  stw       r4, 0x4(r27)
  stw       r0, 0x0(r27)
  bl        -0x1A8574
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0xA28
  mr        r4, r30
  bl        -0x57664

.loc_0xA28:
  stw       r28, 0xC(r27)

.loc_0xA2C:
  stw       r27, 0x98(r31)
  addi      r3, r31, 0
  li        r4, 0
  bl        0x3FC
  mr        r3, r31
  lmw       r27, 0x10C(r1)
  lwz       r0, 0x124(r1)
  addi      r1, r1, 0x120
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EF5BC
 * Size:	0000CC
 */
void zen::DrawCMresult::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  addi      r12, r30, 0x4
  bl        0x25754
  nop       
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x34
  li        r31, 0x1

.loc_0x34:
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0x4
  beq-      .loc_0xB0
  lwz       r3, 0x10(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x14(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x18(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  addi      r3, r30, 0x1C
  bl        -0x2064
  addi      r3, r30, 0x48
  bl        -0x164C
  addi      r3, r30, 0x68
  bl        -0xEB0
  lwz       r3, 0x90(r30)
  bl        -0x5ACC
  lwz       r3, 0x98(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0xB0:
  mr        r3, r31
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
 * Address:	801EF688
 * Size:	000050
 */
void zen::DrawCMresultAlpha::update()
{
/*
.loc_0x0:
  lwz       r0, 0x4(r3)
  cmpwi     r0, 0x2
  beq-      .loc_0x34
  bge-      .loc_0x48
  cmpwi     r0, 0x1
  bge-      .loc_0x1C
  b         .loc_0x48

.loc_0x1C:
  lbz       r4, 0x8(r3)
  cmplwi    r4, 0xFF
  bge-      .loc_0x48
  addi      r0, r4, 0x1
  stb       r0, 0x8(r3)
  b         .loc_0x48

.loc_0x34:
  lbz       r4, 0x8(r3)
  cmplwi    r4, 0
  beq-      .loc_0x48
  subi      r0, r4, 0x1
  stb       r0, 0x8(r3)

.loc_0x48:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EF6D8
 * Size:	000098
 */
void zen::DrawCMresult::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r4
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r3, 0x10(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x14(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x18(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x98(r30)
  lwz       r3, 0xC(r4)
  lbz       r4, 0x8(r4)
  bl        -0x56E90
  lwz       r3, 0x90(r30)
  mr        r4, r31
  bl        -0x5B9C
  lwz       r3, 0x9C(r30)
  mr        r4, r31
  bl        0x5F80
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
 * Address:	801EF770
 * Size:	000170
 */
void zen::DrawCMresult::start(const GameChalQuickInfo &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  stw       r30, 0x30(r1)
  addi      r30, r4, 0
  li        r4, 0x1
  stw       r29, 0x2C(r1)
  mr        r29, r3
  stw       r28, 0x28(r1)
  lwz       r3, 0x90(r3)
  bl        -0x5AC8
  addi      r3, r29, 0x1C
  lfs       f1, -0x3E38(r2)
  bl        -0x21A0
  lwz       r4, 0x6C(r29)
  li        r5, 0
  addi      r3, r29, 0x48
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  bl        -0x1714
  li        r28, 0
  rlwinm    r0,r28,2,0,29
  add       r31, r30, r0

.loc_0x64:
  lwz       r5, 0xC(r31)
  addi      r4, r28, 0
  addi      r3, r29, 0x48
  bl        -0x1520
  addi      r28, r28, 0x1
  cmplwi    r28, 0x5
  addi      r31, r31, 0x4
  blt+      .loc_0x64
  lwz       r0, 0x4(r30)
  li        r31, 0
  addi      r3, r29, 0
  stw       r0, 0x84(r29)
  li        r4, 0x1
  stw       r31, 0x88(r29)
  lwz       r0, 0x8(r30)
  stw       r0, 0x8C(r29)
  bl        0x188

.loc_0xA8:
  addi      r5, r31, 0
  crclr     6, 0x6
  addi      r3, r1, 0x1C
  addi      r4, r13, 0x28D0
  bl        0x26D70
  lwz       r3, 0x10(r29)
  li        r5, 0x1
  lwzu      r12, 0x4(r3)
  lbz       r0, 0x1D(r1)
  lwz       r12, 0x34(r12)
  lbz       r4, 0x1C(r1)
  rlwinm    r0,r0,16,0,15
  lbz       r6, 0x1E(r1)
  mtlr      r12
  rlwimi    r0,r4,24,0,7
  lbz       r7, 0x1F(r1)
  rlwimi    r0,r6,8,16,23
  or        r4, r7, r0
  blrl      
  lwz       r0, 0x0(r30)
  cmplw     r31, r0
  bne-      .loc_0x114
  lbz       r0, 0xC(r3)
  li        r4, 0x1
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x124

.loc_0x114:
  lbz       r0, 0xC(r3)
  li        r4, 0
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)

.loc_0x124:
  addi      r31, r31, 0x1
  cmplwi    r31, 0x5
  blt+      .loc_0xA8
  lwz       r3, 0x9C(r29)
  bl        0x5F30
  mr        r3, r29
  bl        .loc_0x170
  lwz       r3, 0x98(r29)
  li        r0, 0
  stb       r0, 0x8(r3)
  stw       r0, 0x4(r3)
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  lwz       r28, 0x28(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr       

.loc_0x170:
*/
}

/*
 * --INFO--
 * Address:	801EF8E0
 * Size:	0000BC
 */
void zen::DrawCMresult::makeResident()
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
  lwz       r3, 0x10(r3)
  addi      r3, r3, 0x4
  bl        -0x30160
  lwz       r3, 0x14(r29)
  addi      r3, r3, 0x4
  bl        -0x3016C
  lwz       r3, 0x18(r29)
  addi      r3, r3, 0x4
  bl        -0x30178
  lis       r4, 0x803D
  lis       r3, 0x803D
  addi      r30, r4, 0x2360
  addi      r29, r3, 0x2388
  li        r31, 0

.loc_0x54:
  lwz       r3, 0x0(r30)
  cmplwi    r3, 0
  beq-      .loc_0x70
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      

.loc_0x70:
  lwz       r3, 0x0(r29)
  cmplwi    r3, 0
  beq-      .loc_0x8C
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      

.loc_0x8C:
  addi      r31, r31, 0x1
  cmpwi     r31, 0xA
  addi      r30, r30, 0x4
  addi      r29, r29, 0x4
  blt+      .loc_0x54
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
 * Address:	801EF99C
 * Size:	00016C
 */
void zen::DrawCMresult::setMode(zen::DrawCMresult::modeFlag)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  stw       r30, 0x18(r1)
  stw       r4, 0x0(r3)
  lis       r3, 0x802E
  addi      r30, r3, 0x6E88
  lwz       r0, 0x0(r31)
  cmpwi     r0, 0x3
  beq-      .loc_0xDC
  bge-      .loc_0x4C
  cmpwi     r0, 0x1
  beq-      .loc_0x78
  bge-      .loc_0xB8
  cmpwi     r0, 0
  bge-      .loc_0x5C
  b         .loc_0x154

.loc_0x4C:
  cmpwi     r0, 0x5
  beq-      .loc_0x134
  bge-      .loc_0x154
  b         .loc_0x110

.loc_0x5C:
  lwz       r3, 0x6C(r30)
  lwz       r0, 0x70(r30)
  stw       r3, 0x4(r31)
  stw       r0, 0x8(r31)
  lwz       r0, 0x74(r30)
  stw       r0, 0xC(r31)
  b         .loc_0x154

.loc_0x78:
  lfs       f0, -0x3E38(r2)
  li        r4, 0
  li        r5, -0x1E0
  stfs      f0, 0x94(r31)
  lwz       r3, 0x78(r30)
  lwz       r0, 0x7C(r30)
  stw       r3, 0x4(r31)
  stw       r0, 0x8(r31)
  lwz       r0, 0x80(r30)
  stw       r0, 0xC(r31)
  lwz       r3, 0x10(r31)
  lwzu      r12, 0x4(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  b         .loc_0x154

.loc_0xB8:
  lfs       f0, -0x3E38(r2)
  stfs      f0, 0x94(r31)
  lwz       r3, 0x84(r30)
  lwz       r0, 0x88(r30)
  stw       r3, 0x4(r31)
  stw       r0, 0x8(r31)
  lwz       r0, 0x8C(r30)
  stw       r0, 0xC(r31)
  b         .loc_0x154

.loc_0xDC:
  lwz       r0, 0x84(r31)
  cmpwi     r0, 0
  bne-      .loc_0xF4
  addi      r3, r31, 0x48
  lfs       f1, -0x3E34(r2)
  bl        -0x1978

.loc_0xF4:
  lwz       r3, 0x90(r30)
  lwz       r0, 0x94(r30)
  stw       r3, 0x4(r31)
  stw       r0, 0x8(r31)
  lwz       r0, 0x98(r30)
  stw       r0, 0xC(r31)
  b         .loc_0x154

.loc_0x110:
  lwz       r3, 0x9C(r31)
  bl        0x5D4C
  lwz       r3, 0x9C(r30)
  lwz       r0, 0xA0(r30)
  stw       r3, 0x4(r31)
  stw       r0, 0x8(r31)
  lwz       r0, 0xA4(r30)
  stw       r0, 0xC(r31)
  b         .loc_0x154

.loc_0x134:
  li        r0, 0x3
  stw       r0, 0x0(r31)
  lwz       r3, 0xA8(r30)
  lwz       r0, 0xAC(r30)
  stw       r3, 0x4(r31)
  stw       r0, 0x8(r31)
  lwz       r0, 0xB0(r30)
  stw       r0, 0xC(r31)

.loc_0x154:
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
 * Address:	801EFB08
 * Size:	000008
 */
void zen::DrawCMresult::modeSleep(Controller *)
{
/*
.loc_0x0:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EFB10
 * Size:	00004C
 */
void zen::DrawCMresult::modeWaitAppear(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r4, 0x2DEC(r13)
  lfs       f1, 0x94(r3)
  lfs       f0, 0x28C(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x94(r3)
  lfs       f1, 0x94(r3)
  lfs       f0, -0x3E30(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x38
  li        r4, 0x2
  bl        -0x1A8

.loc_0x38:
  li        r3, 0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EFB5C
 * Size:	0000D8
 */
void zen::DrawCMresult::modeAppear(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stfd      f31, 0x40(r1)
  stw       r31, 0x3C(r1)
  mr        r31, r3
  lwz       r4, 0x2DEC(r13)
  lfs       f1, 0x94(r3)
  lfs       f0, 0x28C(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x94(r3)
  lfs       f1, 0x94(r3)
  lfs       f0, -0x3E34(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x54
  stfs      f0, 0x94(r31)
  addi      r3, r31, 0
  li        r4, 0x3
  lfs       f31, -0x3E38(r2)
  bl        -0x20C
  b         .loc_0x6C

.loc_0x54:
  fdivs     f0, f1, f0
  lfs       f1, -0x3E2C(r2)
  fmuls     f1, f1, f0
  bl        0x2C12C
  lfs       f0, -0x3E34(r2)
  fsubs     f31, f0, f1

.loc_0x6C:
  lfs       f1, -0x3E28(r2)
  lfs       f0, -0x3E38(r2)
  fmuls     f1, f1, f31
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x90
  lfs       f0, -0x3E24(r2)
  fadds     f0, f0, f1
  b         .loc_0x98

.loc_0x90:
  lfs       f0, -0x3E24(r2)
  fsubs     f0, f1, f0

.loc_0x98:
  fctiwz    f0, f0
  lwz       r3, 0x10(r31)
  lwzu      r12, 0x4(r3)
  li        r4, 0
  stfd      f0, 0x30(r1)
  lwz       r12, 0x14(r12)
  lwz       r5, 0x34(r1)
  mtlr      r12
  blrl      
  lwz       r0, 0x4C(r1)
  li        r3, 0
  lfd       f31, 0x40(r1)
  lwz       r31, 0x3C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EFC34
 * Size:	0000FC
 */
void zen::DrawCMresult::modeOperation(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r3
  lwz       r5, 0x88(r3)
  lwz       r0, 0x84(r3)
  cmpw      r5, r0
  bge-      .loc_0x88
  lis       r3, 0x100
  lwz       r4, 0x28(r4)
  addi      r0, r3, 0x1000
  and.      r0, r4, r0
  beq-      .loc_0x58
  li        r3, 0x111
  bl        -0x14A8FC
  lwz       r0, 0x84(r31)
  addi      r3, r31, 0x48
  stw       r0, 0x88(r31)
  lfs       f1, -0x3E34(r2)
  bl        -0x1B70
  b         .loc_0x7C

.loc_0x58:
  addi      r0, r5, 0x1
  stw       r0, 0x88(r31)
  lwz       r3, 0x88(r31)
  lwz       r0, 0x84(r31)
  cmpw      r3, r0
  bne-      .loc_0x7C
  addi      r3, r31, 0x48
  lfs       f1, -0x3E34(r2)
  bl        -0x1B98

.loc_0x7C:
  li        r3, 0x118
  bl        -0x14A940
  b         .loc_0xE4

.loc_0x88:
  lwz       r3, 0x64(r31)
  rlwinm.   r0,r3,0,30,30
  beq-      .loc_0xC0
  lis       r3, 0x100
  lwz       r4, 0x28(r4)
  addi      r0, r3, 0x1000
  and.      r0, r4, r0
  beq-      .loc_0xE4
  li        r3, 0x111
  bl        -0x14A96C
  addi      r3, r31, 0
  li        r4, 0x4
  bl        -0x350
  b         .loc_0xE4

.loc_0xC0:
  rlwinm.   r0,r3,0,31,31
  beq-      .loc_0xE4
  addi      r3, r31, 0x68
  bl        -0x14E8
  lwz       r4, 0x98(r31)
  li        r0, 0x1
  addi      r3, r31, 0
  stw       r0, 0x4(r4)
  bl        0xC0

.loc_0xE4:
  lwz       r0, 0x2C(r1)
  li        r3, 0
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EFD30
 * Size:	0000A4
 */
void zen::DrawCMresult::modeSave(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  mr        r30, r3
  lwz       r3, 0x9C(r3)
  bl        0x57FC
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x88
  lwz       r3, 0x9C(r30)
  lwz       r0, 0x0(r3)
  cmpwi     r0, 0x8
  beq-      .loc_0x74
  bge-      .loc_0x50
  cmpwi     r0, 0x6
  beq-      .loc_0x5C
  bge-      .loc_0x64
  b         .loc_0x88

.loc_0x50:
  cmpwi     r0, 0xA
  bge-      .loc_0x88
  b         .loc_0x84

.loc_0x5C:
  li        r31, 0x1
  b         .loc_0x88

.loc_0x64:
  addi      r3, r30, 0
  li        r4, 0x4
  bl        -0x400
  b         .loc_0x88

.loc_0x74:
  addi      r3, r30, 0
  li        r4, 0x5
  bl        -0x410
  b         .loc_0x88

.loc_0x84:
  li        r31, 0x1

.loc_0x88:
  mr        r3, r31
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
 * Address:	801EFDD4
 * Size:	000378
 */
void zen::DrawCMresult::createRankInEffect()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x150(r1)
  stw       r31, 0x14C(r1)
  stw       r30, 0x148(r1)
  stw       r29, 0x144(r1)
  mr        r29, r3
  lwz       r0, 0x8C(r3)
  cmpwi     r0, 0
  blt-      .loc_0x35C
  lwz       r5, 0x10(r29)
  lis       r3, 0x6269
  addi      r4, r3, 0x5F77
  lwz       r12, 0x4(r5)
  addi      r3, r5, 0x4
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lha       r4, 0x1A(r3)
  mr        r30, r3
  lha       r0, 0x1E(r3)
  lis       r31, 0x4330
  lha       r6, 0x18(r3)
  sub       r3, r0, r4
  lha       r0, 0x1C(r30)
  srawi     r3, r3, 0x1
  lfd       f3, -0x3E20(r2)
  add       r3, r4, r3
  lfs       f0, 0x28D8(r13)
  subfic    r3, r3, 0x1E0
  sub       r0, r0, r6
  srawi     r0, r0, 0x1
  add       r0, r6, r0
  xoris     r0, r0, 0x8000
  stw       r0, 0x134(r1)
  xoris     r0, r3, 0x8000
  addi      r5, r1, 0xD4
  stw       r31, 0x130(r1)
  li        r4, 0xE
  li        r6, 0
  lfd       f1, 0x130(r1)
  li        r7, 0
  stw       r0, 0x13C(r1)
  fsubs     f1, f1, f3
  stw       r31, 0x138(r1)
  stfs      f1, 0xD0(r1)
  lfd       f2, 0x138(r1)
  lfs       f1, 0xD0(r1)
  fsubs     f2, f2, f3
  stfs      f1, 0xD4(r1)
  stfs      f2, 0xD8(r1)
  stfs      f0, 0xDC(r1)
  lwz       r3, 0x90(r29)
  bl        -0x6370
  lha       r4, 0x1A(r30)
  addi      r5, r1, 0xC4
  lha       r0, 0x1E(r30)
  li        r7, 0
  lha       r6, 0x18(r30)
  sub       r3, r0, r4
  lha       r0, 0x1C(r30)
  srawi     r3, r3, 0x1
  lfd       f3, -0x3E20(r2)
  add       r3, r4, r3
  lfs       f0, 0x28DC(r13)
  subfic    r3, r3, 0x1E0
  sub       r0, r0, r6
  srawi     r0, r0, 0x1
  add       r0, r6, r0
  xoris     r0, r0, 0x8000
  stw       r0, 0x124(r1)
  xoris     r0, r3, 0x8000
  li        r4, 0xD
  stw       r31, 0x120(r1)
  li        r6, 0
  lfd       f1, 0x120(r1)
  stw       r0, 0x12C(r1)
  fsubs     f1, f1, f3
  stw       r31, 0x128(r1)
  stfs      f1, 0xC0(r1)
  lfd       f2, 0x128(r1)
  lfs       f1, 0xC0(r1)
  fsubs     f2, f2, f3
  stfs      f1, 0xC4(r1)
  stfs      f2, 0xC8(r1)
  stfs      f0, 0xCC(r1)
  lwz       r3, 0x90(r29)
  bl        -0x63F8
  lha       r4, 0x1A(r30)
  addi      r5, r1, 0xB4
  lha       r0, 0x1E(r30)
  li        r7, 0
  lha       r6, 0x18(r30)
  sub       r3, r0, r4
  lha       r0, 0x1C(r30)
  srawi     r3, r3, 0x1
  lfd       f3, -0x3E20(r2)
  add       r3, r4, r3
  lfs       f0, 0x28E0(r13)
  subfic    r3, r3, 0x1E0
  sub       r0, r0, r6
  srawi     r0, r0, 0x1
  add       r0, r6, r0
  xoris     r0, r0, 0x8000
  stw       r0, 0x114(r1)
  xoris     r0, r3, 0x8000
  li        r4, 0xC
  stw       r31, 0x110(r1)
  li        r6, 0
  lfd       f1, 0x110(r1)
  stw       r0, 0x11C(r1)
  fsubs     f1, f1, f3
  stw       r31, 0x118(r1)
  stfs      f1, 0xB0(r1)
  lfd       f2, 0x118(r1)
  lfs       f1, 0xB0(r1)
  fsubs     f2, f2, f3
  stfs      f1, 0xB4(r1)
  stfs      f2, 0xB8(r1)
  stfs      f0, 0xBC(r1)
  lwz       r3, 0x90(r29)
  bl        -0x6480
  lwz       r5, 0x8C(r29)
  addi      r3, r1, 0xE0
  crclr     6, 0x6
  addi      r4, r13, 0x28EC
  addi      r5, r5, 0x1
  bl        0x265C4
  lwz       r3, 0x14(r29)
  li        r5, 0x1
  lwzu      r12, 0x4(r3)
  lbz       r0, 0xE1(r1)
  lwz       r12, 0x34(r12)
  lbz       r4, 0xE0(r1)
  rlwinm    r0,r0,16,0,15
  lbz       r6, 0xE2(r1)
  mtlr      r12
  rlwimi    r0,r4,24,0,7
  lbz       r7, 0xE3(r1)
  rlwimi    r0,r6,8,16,23
  or        r4, r7, r0
  blrl      
  addi      r30, r3, 0
  addi      r4, r1, 0xEC
  addi      r5, r1, 0xE8
  bl        -0x304EC
  lha       r3, 0x18(r30)
  addi      r5, r1, 0xA4
  lha       r0, 0x1C(r30)
  li        r6, 0
  lwz       r4, 0xEC(r1)
  sub       r0, r0, r3
  lwz       r9, 0xE8(r1)
  srawi     r0, r0, 0x1
  lfd       f3, -0x3E20(r2)
  add       r0, r4, r0
  lfs       f0, 0x28E4(r13)
  stw       r0, 0xEC(r1)
  li        r4, 0x10
  li        r7, 0
  lha       r8, 0x1A(r30)
  lha       r3, 0x1E(r30)
  lwz       r0, 0xEC(r1)
  sub       r3, r3, r8
  srawi     r3, r3, 0x1
  add       r3, r9, r3
  xoris     r0, r0, 0x8000
  stw       r3, 0xE8(r1)
  stw       r0, 0x10C(r1)
  lwz       r0, 0xE8(r1)
  stw       r31, 0x108(r1)
  subfic    r0, r0, 0x1E0
  lfd       f1, 0x108(r1)
  xoris     r0, r0, 0x8000
  stw       r0, 0x104(r1)
  fsubs     f1, f1, f3
  stw       r31, 0x100(r1)
  stfs      f1, 0xA0(r1)
  lfd       f1, 0x100(r1)
  lfs       f2, 0xA0(r1)
  fsubs     f1, f1, f3
  stfs      f2, 0xA4(r1)
  stfs      f1, 0xA8(r1)
  stfs      f0, 0xAC(r1)
  lwz       r3, 0x90(r29)
  bl        -0x6580
  lwz       r3, 0xEC(r1)
  addi      r5, r1, 0x90
  lwz       r0, 0xE8(r1)
  li        r4, 0xF
  xoris     r3, r3, 0x8000
  stw       r3, 0xFC(r1)
  subfic    r0, r0, 0x1E0
  xoris     r0, r0, 0x8000
  lfd       f3, -0x3E20(r2)
  stw       r31, 0xF8(r1)
  lfs       f0, 0x28E8(r13)
  li        r6, 0
  lfd       f1, 0xF8(r1)
  li        r7, 0
  stw       r0, 0xF4(r1)
  fsubs     f1, f1, f3
  stw       r31, 0xF0(r1)
  stfs      f1, 0x8C(r1)
  lfd       f1, 0xF0(r1)
  lfs       f2, 0x8C(r1)
  fsubs     f1, f1, f3
  stfs      f2, 0x90(r1)
  stfs      f1, 0x94(r1)
  stfs      f0, 0x98(r1)
  lwz       r3, 0x90(r29)
  bl        -0x65E8
  li        r3, 0x12C
  bl        -0x14ADB8

.loc_0x35C:
  lwz       r0, 0x154(r1)
  lwz       r31, 0x14C(r1)
  lwz       r30, 0x148(r1)
  lwz       r29, 0x144(r1)
  addi      r1, r1, 0x150
  mtlr      r0
  blr
*/
}