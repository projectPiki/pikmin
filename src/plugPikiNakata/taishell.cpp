

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
 * Address:	80141FD0
 * Size:	000084
 */
void TaiShellSoundTable::TaiShellSoundTable()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x5
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  bl        -0x22F7C
  li        r30, 0
  li        r31, 0
  b         .loc_0x58

.loc_0x30:
  li        r3, 0x4
  bl        -0xFB000
  cmplwi    r3, 0
  beq-      .loc_0x48
  addi      r0, r30, 0x67
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
 * Address:	80142054
 * Size:	00018C
 */
void TaiShellParameters::TaiShellParameters()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x15
  stw       r0, 0x4(r1)
  li        r5, 0x33
  stwu      r1, -0x58(r1)
  stw       r31, 0x54(r1)
  addi      r31, r3, 0
  bl        0x9CD8
  lis       r3, 0x802D
  subi      r0, r3, 0x3718
  stw       r0, 0x0(r31)
  li        r5, 0x14
  lis       r4, 0x802D
  lwz       r6, 0x84(r31)
  li        r0, 0x32
  lis       r3, 0x802D
  lwz       r6, 0x0(r6)
  mulli     r5, r5, 0xC
  lwz       r6, 0x8(r6)
  subi      r4, r4, 0x3BFC
  add       r6, r6, r5
  stw       r4, 0x0(r6)
  li        r9, 0
  li        r4, 0x1E
  stw       r9, 0x4(r6)
  mulli     r5, r0, 0xC
  stw       r4, 0x8(r6)
  subi      r4, r3, 0x3BE8
  lwz       r3, 0x84(r31)
  li        r7, 0x1
  li        r6, -0x1
  lwz       r8, 0x4(r3)
  li        r0, 0x5
  addi      r3, r31, 0
  lwz       r8, 0x8(r8)
  add       r5, r8, r5
  stw       r4, 0x0(r5)
  lfs       f0, -0x5940(r2)
  stfs      f0, 0x4(r5)
  lfs       f0, -0x593C(r2)
  stfs      f0, 0x8(r5)
  lwz       r4, 0x84(r31)
  lwz       r5, 0x0(r4)
  lwz       r5, 0x0(r5)
  stw       r7, 0x4(r5)
  lwz       r5, 0x0(r4)
  lwz       r5, 0x0(r5)
  stw       r6, 0xC(r5)
  lwz       r5, 0x0(r4)
  lwz       r5, 0x0(r5)
  stw       r9, 0x8(r5)
  lwz       r5, 0x4(r4)
  lfs       f2, -0x5938(r2)
  lwz       r5, 0x0(r5)
  stfs      f2, 0x0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f2, 0x4(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5934(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x8(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5930(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x20(r5)
  lwz       r5, 0x4(r4)
  lfs       f1, -0x592C(r2)
  lwz       r5, 0x0(r5)
  stfs      f1, 0x48(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5928(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x58(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f1, 0x5C(r5)
  lwz       r5, 0x4(r4)
  lfs       f1, -0x5924(r2)
  lwz       r5, 0x0(r5)
  stfs      f1, 0x4C(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f2, 0xAC(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5920(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xB0(r5)
  lwz       r5, 0x0(r4)
  lwz       r5, 0x0(r5)
  stw       r0, 0x50(r5)
  lwz       r4, 0x4(r4)
  lwz       r4, 0x0(r4)
  stfs      f1, 0xC8(r4)
  lwz       r0, 0x5C(r1)
  lwz       r31, 0x54(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801421E0
 * Size:	0004F4
 */
void TaiShellStrategy::TaiShellStrategy(TekiParameters *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0xA0(r1)
  stmw      r24, 0x80(r1)
  addi      r28, r4, 0
  addi      r30, r3, 0
  li        r4, 0x5
  bl        -0x1AE1C
  lis       r3, 0x802D
  subi      r0, r3, 0x37CC
  stw       r0, 0x0(r30)
  li        r3, 0x8
  bl        -0xFB210
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x64
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r29)
  li        r0, -0x1
  lis       r3, 0x802C
  stw       r0, 0x0(r29)
  addi      r0, r3, 0x6A60
  stw       r0, 0x4(r29)

.loc_0x64:
  li        r3, 0x8
  bl        -0xFB244
  addi      r31, r3, 0
  mr.       r0, r31
  beq-      .loc_0x98
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r31)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r31)
  subi      r0, r3, 0x3810
  stw       r0, 0x4(r31)

.loc_0x98:
  li        r3, 0x8
  bl        -0xFB278
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0xCC
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x3854
  stw       r0, 0x4(r27)

.loc_0xCC:
  li        r3, 0xC
  bl        -0xFB2AC
  addi      r26, r3, 0
  mr.       r0, r26
  beq-      .loc_0x114
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r26)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r26)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r26)
  li        r4, 0x2
  subi      r0, r3, 0x6A8C
  stw       r4, 0x8(r26)
  stw       r0, 0x4(r26)

.loc_0x114:
  li        r3, 0x8
  bl        -0xFB2F4
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x148
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r25)
  li        r0, 0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r25)
  subi      r0, r3, 0x389C
  stw       r0, 0x4(r25)

.loc_0x148:
  li        r3, 0xC
  bl        -0xFB328
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x164
  li        r4, 0x4
  bl        -0x1B2A8

.loc_0x164:
  li        r0, 0
  lwz       r3, 0x8(r24)
  rlwinm    r0,r0,2,0,29
  stwx      r31, r3, r0
  li        r0, 0x1
  li        r4, 0x2
  lwz       r3, 0x8(r24)
  rlwinm    r0,r0,2,0,29
  li        r5, 0x3
  stwx      r27, r3, r0
  rlwinm    r4,r4,2,0,29
  rlwinm    r0,r5,2,0,29
  lwz       r5, 0x8(r24)
  li        r3, 0xC
  stwx      r26, r5, r4
  lwz       r4, 0x8(r24)
  stwx      r25, r4, r0
  lwz       r4, 0x8(r30)
  stw       r24, 0x0(r4)
  bl        -0xFB38C
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x1F4
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r24)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r24)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r24)
  li        r4, 0xA
  subi      r0, r3, 0x6A8C
  stw       r4, 0x8(r24)
  stw       r0, 0x4(r24)

.loc_0x1F4:
  li        r3, 0x14
  bl        -0xFB3D4
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x24C
  lwz       r5, 0x84(r28)
  lis       r4, 0x802C
  lis       r3, 0x802D
  lwz       r6, 0x4(r5)
  addi      r5, r4, 0x6620
  li        r4, 0x2
  lwz       r6, 0x0(r6)
  subi      r3, r3, 0x35D8
  li        r0, 0
  lfs       f0, 0xC8(r6)
  stw       r5, 0x4(r25)
  stw       r4, 0x0(r25)
  stw       r3, 0x4(r25)
  stw       r0, 0x8(r25)
  stfs      f0, 0xC(r25)
  lfs       f0, -0x5940(r2)
  stfs      f0, 0x10(r25)

.loc_0x24C:
  li        r3, 0xC
  bl        -0xFB42C
  addi      r26, r3, 0
  mr.       r3, r26
  beq-      .loc_0x268
  li        r4, 0x3
  bl        -0x1B3AC

.loc_0x268:
  li        r0, 0
  lwz       r3, 0x8(r26)
  rlwinm    r0,r0,2,0,29
  stwx      r31, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r4, 0x8(r26)
  rlwinm    r3,r0,2,0,29
  rlwinm    r0,r5,2,0,29
  stwx      r24, r4, r3
  li        r3, 0xC
  lwz       r4, 0x8(r26)
  stwx      r25, r4, r0
  lwz       r4, 0x8(r30)
  stw       r26, 0x4(r4)
  bl        -0xFB480
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x2E8
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r24)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r24)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r24)
  li        r4, 0xB
  subi      r0, r3, 0x6A8C
  stw       r4, 0x8(r24)
  stw       r0, 0x4(r24)

.loc_0x2E8:
  li        r3, 0xC
  bl        -0xFB4C8
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x330
  lwz       r5, 0x84(r28)
  lis       r4, 0x802C
  lis       r3, 0x802D
  lwz       r6, 0x0(r5)
  addi      r5, r4, 0x6620
  li        r4, 0x3
  lwz       r6, 0x0(r6)
  subi      r0, r3, 0x6B60
  lwz       r3, 0x50(r6)
  stw       r5, 0x4(r25)
  stw       r4, 0x0(r25)
  stw       r0, 0x4(r25)
  stw       r3, 0x8(r25)

.loc_0x330:
  li        r3, 0xC
  bl        -0xFB510
  addi      r26, r3, 0
  mr.       r3, r26
  beq-      .loc_0x34C
  li        r4, 0x3
  bl        -0x1B490

.loc_0x34C:
  li        r0, 0
  lwz       r3, 0x8(r26)
  rlwinm    r0,r0,2,0,29
  stwx      r31, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r4, 0x8(r26)
  rlwinm    r3,r0,2,0,29
  rlwinm    r0,r5,2,0,29
  stwx      r25, r4, r3
  li        r3, 0x8
  lwz       r4, 0x8(r26)
  stwx      r24, r4, r0
  lwz       r4, 0x8(r30)
  stw       r26, 0x8(r4)
  bl        -0xFB564
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x3B8
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r24)
  li        r0, 0x4
  lis       r3, 0x802D
  stw       r0, 0x0(r24)
  subi      r0, r3, 0x38FC
  stw       r0, 0x4(r24)

.loc_0x3B8:
  li        r3, 0x8
  bl        -0xFB598
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x3EC
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r25)
  li        r0, 0
  lis       r3, 0x802C
  stw       r0, 0x0(r25)
  addi      r0, r3, 0x6DDC
  stw       r0, 0x4(r25)

.loc_0x3EC:
  li        r3, 0xC
  bl        -0xFB5CC
  addi      r26, r3, 0
  mr.       r3, r26
  beq-      .loc_0x408
  li        r4, 0x3
  bl        -0x1B54C

.loc_0x408:
  li        r0, 0
  lwz       r3, 0x8(r26)
  rlwinm    r0,r0,2,0,29
  stwx      r31, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r4, 0x8(r26)
  rlwinm    r3,r0,2,0,29
  rlwinm    r0,r5,2,0,29
  stwx      r24, r4, r3
  li        r3, 0xC
  lwz       r4, 0x8(r26)
  stwx      r25, r4, r0
  lwz       r4, 0x8(r30)
  stw       r26, 0xC(r4)
  bl        -0xFB620
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x488
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r24)
  li        r0, 0
  lis       r3, 0x802D
  stw       r0, 0x0(r24)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r24)
  li        r4, 0xD
  subi      r0, r3, 0x6A8C
  stw       r4, 0x8(r24)
  stw       r0, 0x4(r24)

.loc_0x488:
  li        r3, 0xC
  bl        -0xFB668
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x4A4
  li        r4, 0x3
  bl        -0x1B5E8

.loc_0x4A4:
  li        r0, 0
  lwz       r3, 0x8(r25)
  rlwinm    r0,r0,2,0,29
  stwx      r31, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r4, 0x8(r25)
  rlwinm    r3,r0,2,0,29
  rlwinm    r0,r5,2,0,29
  stwx      r24, r4, r3
  mr        r3, r30
  lwz       r4, 0x8(r25)
  stwx      r29, r4, r0
  lwz       r4, 0x8(r30)
  stw       r25, 0x10(r4)
  lwz       r0, 0xA4(r1)
  lmw       r24, 0x80(r1)
  addi      r1, r1, 0xA0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801426D4
 * Size:	00008C
 */
void TaiShellStrategy::createEffect(Teki &, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r5, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  bl        0xAAD0
  lwz       r0, 0x3180(r13)
  cmplwi    r0, 0
  beq-      .loc_0x74
  cmpwi     r31, 0
  bne-      .loc_0x74
  addi      r3, r1, 0x14
  bl        -0x258B8
  addi      r3, r30, 0
  addi      r4, r1, 0x14
  bl        0x3E98
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x14
  li        r4, 0xE0
  li        r6, 0
  li        r7, 0
  bl        0x5A408
  lwz       r3, 0x3178(r13)
  addi      r6, r1, 0x14
  li        r4, 0x4
  li        r5, 0
  bl        0x3A690

.loc_0x74:
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
 * Address:	80142760
 * Size:	0001F4
 */
void TaiShellStrategy::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  li        r6, 0
  stw       r0, 0x4(r1)
  li        r7, 0
  stwu      r1, -0x78(r1)
  stw       r31, 0x74(r1)
  mr        r31, r4
  addi      r5, r1, 0x50
  stw       r30, 0x70(r1)
  addi      r30, r3, 0
  li        r4, 0x5C
  lfs       f0, -0xB80(r13)
  lfs       f1, -0xB7C(r13)
  stfs      f0, 0x50(r1)
  lfs       f0, -0xB78(r13)
  stfs      f1, 0x54(r1)
  lwz       r3, 0x3180(r13)
  stfs      f0, 0x58(r1)
  bl        0x5A390
  lwz       r5, 0x3D8(r31)
  mr        r4, r31
  stw       r3, 0x0(r5)
  mr        r3, r30
  bl        -0x1B328
  mr        r3, r31
  lwz       r4, -0x9C0(r13)
  lwz       r12, 0x0(r31)
  lwz       r12, 0x1D0(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r4, -0x9CC(r13)
  lwz       r12, 0x0(r31)
  lwz       r12, 0x1D0(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x2C8(r31)
  li        r30, 0xD
  lwz       r3, 0x34(r4)
  lwz       r3, 0x0(r3)
  lwz       r3, 0x0(r3)
  lwz       r0, 0x10(r3)
  cmpwi     r0, 0x1
  bne-      .loc_0xE4
  addi      r4, r4, 0x28
  lwz       r3, 0x2F6C(r13)
  lwz       r4, 0x0(r4)
  bl        -0xC340C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xE0
  lwz       r5, 0x2C8(r31)
  lis       r3, 0x6E6F
  addi      r4, r3, 0x6E65
  addi      r3, r5, 0x28
  bl        -0xFE974
  b         .loc_0xE4

.loc_0xE0:
  li        r30, 0xE

.loc_0xE4:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x194(r12)
  mtlr      r12
  blrl      
  mr.       r30, r3
  beq-      .loc_0x1DC
  addi      r3, r1, 0x5C
  bl        -0x25A14
  addi      r3, r31, 0
  addi      r4, r1, 0x5C
  bl        0x3D3C
  lwz       r4, 0x2C8(r31)
  lwz       r3, 0x2C8(r30)
  addi      r4, r4, 0x28
  lwz       r4, 0x0(r4)
  addi      r3, r3, 0x28
  bl        -0xFE9C8
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x5C(r1)
  lwz       r0, 0x60(r1)
  stw       r3, 0x94(r30)
  stw       r0, 0x98(r30)
  lwz       r0, 0x64(r1)
  stw       r0, 0x9C(r30)
  lfs       f0, 0xA0(r31)
  stfs      f0, 0xA0(r30)
  lwz       r3, 0x420(r31)
  cmplwi    r3, 0
  beq-      .loc_0x184
  beq-      .loc_0x184
  bl        -0x5E56C
  li        r0, 0
  stw       r0, 0x420(r31)

.loc_0x184:
  stw       r30, 0x420(r31)
  lwz       r3, 0x420(r31)
  cmplwi    r3, 0
  beq-      .loc_0x198
  bl        -0x5E598

.loc_0x198:
  lwz       r3, 0x418(r30)
  cmplwi    r3, 0
  beq-      .loc_0x1B4
  beq-      .loc_0x1B4
  bl        -0x5E59C
  li        r0, 0
  stw       r0, 0x418(r30)

.loc_0x1B4:
  stw       r31, 0x418(r30)
  lwz       r3, 0x418(r30)
  cmplwi    r3, 0
  beq-      .loc_0x1C8
  bl        -0x5E5C8

.loc_0x1C8:
  lwz       r5, 0x2C8(r31)
  lis       r3, 0x6E6F
  addi      r4, r3, 0x6E65
  addi      r3, r5, 0x28
  bl        -0xFEA74

.loc_0x1DC:
  lwz       r0, 0x7C(r1)
  lwz       r31, 0x74(r1)
  lwz       r30, 0x70(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80142954
 * Size:	0000D0
 */
void TaiShellStrategy::draw(Teki &, Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  stw       r31, 0x74(r1)
  addi      r31, r5, 0
  stw       r30, 0x70(r1)
  addi      r30, r4, 0
  stw       r29, 0x6C(r1)
  addi      r29, r3, 0
  addi      r3, r30, 0
  bl        0x705C
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r5, r31, 0
  bl        0xA838
  lwz       r3, 0x3D8(r30)
  lwz       r0, 0x0(r3)
  cmplwi    r0, 0
  beq-      .loc_0xB4
  lwz       r3, 0x410(r30)
  lwz       r0, -0x9AC(r13)
  and.      r0, r3, r0
  bne-      .loc_0x6C
  addi      r3, r30, 0
  li        r4, 0
  bl        0x7064
  b         .loc_0xB4

.loc_0x6C:
  addi      r3, r30, 0
  li        r4, 0
  bl        0x7030
  lwz       r3, 0x2E4(r31)
  addi      r4, r1, 0x24
  addi      r3, r3, 0x1E0
  bl        -0x10459C
  addi      r3, r1, 0x18
  bl        -0x25B8C
  addi      r3, r30, 0
  addi      r4, r1, 0x18
  addi      r6, r1, 0x24
  li        r5, 0x6
  bl        0x6E54
  addi      r3, r30, 0
  addi      r5, r1, 0x18
  li        r4, 0
  bl        0x703C

.loc_0xB4:
  lwz       r0, 0x7C(r1)
  lwz       r31, 0x74(r1)
  lwz       r30, 0x70(r1)
  lwz       r29, 0x6C(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80142A24
 * Size:	000038
 */
void TaiShellSetPositionAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0x420(r4)
  lwz       r0, -0x9C4(r13)
  lwz       r6, 0x410(r5)
  and.      r0, r6, r0
  beq-      .loc_0x24
  bl        .loc_0x38

.loc_0x24:
  li        r3, 0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr       

.loc_0x38:
*/
}

/*
 * --INFO--
 * Address:	80142A5C
 * Size:	000078
 */
void TaiShellSetPositionAction::setPosition(Teki &, Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r5, 0
  addi      r3, r1, 0x14
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  bl        -0x25C28
  addi      r3, r30, 0
  addi      r4, r1, 0x14
  bl        0x3B28
  lwz       r3, 0x2F00(r13)
  li        r4, 0x1
  lfs       f1, 0x14(r1)
  lfs       f2, 0x1C(r1)
  bl        -0xDAB98
  stfs      f1, 0x18(r1)
  lwz       r3, 0x14(r1)
  lwz       r0, 0x18(r1)
  stw       r3, 0x94(r31)
  stw       r0, 0x98(r31)
  lwz       r0, 0x1C(r1)
  stw       r0, 0x9C(r31)
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
 * Address:	80142AD4
 * Size:	0001A8
 */
void TaiShellSaveItemPositionAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x108(r1)
  stfd      f31, 0x100(r1)
  stfd      f30, 0xF8(r1)
  stfd      f29, 0xF0(r1)
  stw       r31, 0xEC(r1)
  stw       r30, 0xE8(r1)
  mr        r30, r4
  stw       r29, 0xE4(r1)
  addi      r29, r3, 0
  lwz       r5, 0x2CC(r4)
  li        r4, 0x2
  lfs       f29, 0x2C(r5)
  mr        r3, r5
  bl        -0x2331C
  fcmpo     cr0, f29, f1
  ble-      .loc_0x50
  li        r3, 0
  b         .loc_0x180

.loc_0x50:
  lwz       r3, 0x420(r30)
  lwz       r0, 0x2BC(r3)
  cmplwi    r0, 0
  mr        r31, r0
  bne-      .loc_0x6C
  li        r3, 0
  b         .loc_0x180

.loc_0x6C:
  addi      r3, r1, 0xC4
  bl        -0x25CF0
  addi      r3, r30, 0
  addi      r4, r1, 0xC4
  bl        0x3A60
  lfs       f3, 0xCC(r1)
  lfs       f2, 0x9C(r31)
  lfs       f1, 0xC4(r1)
  lfs       f0, 0x94(r31)
  fsubs     f2, f3, f2
  fsubs     f1, f1, f0
  fmuls     f0, f2, f2
  fmuls     f1, f1, f1
  fadds     f1, f1, f0
  bl        -0x134F38
  lwz       r3, 0x2C8(r30)
  fmr       f29, f1
  li        r4, 0
  lwz       r3, 0x34(r3)
  bl        -0x1F97C
  lwz       r3, 0x2C4(r30)
  fmr       f31, f1
  li        r4, 0x1
  lwz       r3, 0x84(r3)
  bl        -0x1F990
  lwz       r3, 0x2C4(r30)
  fmr       f30, f1
  li        r4, 0x8
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  bl        -0x206E4
  fmuls     f0, f30, f31
  fmuls     f0, f1, f0
  fcmpo     cr0, f29, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x138
  lwz       r3, 0x2C8(r30)
  li        r4, 0
  lwz       r3, 0x34(r3)
  bl        -0x1F9CC
  lwz       r3, 0x2C4(r30)
  li        r4, 0x1
  lwz       r3, 0x84(r3)
  bl        -0x1F9DC
  lwz       r3, 0x2C4(r30)
  li        r4, 0x8
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  bl        -0x2072C
  li        r3, 0
  b         .loc_0x180

.loc_0x138:
  lwz       r3, 0x2C8(r30)
  li        r4, 0
  lwz       r3, 0x34(r3)
  bl        -0x1FA08
  lwz       r3, 0x2C4(r30)
  li        r4, 0x1
  lwz       r3, 0x84(r3)
  bl        -0x1FA18
  lwz       r3, 0x2C4(r30)
  li        r4, 0x8
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  bl        -0x20768
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r5, r31, 0
  bl        .loc_0x1A8
  li        r3, 0

.loc_0x180:
  lwz       r0, 0x10C(r1)
  lfd       f31, 0x100(r1)
  lfd       f30, 0xF8(r1)
  lfd       f29, 0xF0(r1)
  lwz       r31, 0xEC(r1)
  lwz       r30, 0xE8(r1)
  lwz       r29, 0xE4(r1)
  addi      r1, r1, 0x108
  mtlr      r0
  blr       

.loc_0x1A8:
*/
}

/*
 * --INFO--
 * Address:	80142C7C
 * Size:	000078
 */
void TaiShellSaveItemPositionAction::setPosition(Teki &, Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r5, 0
  addi      r3, r1, 0x14
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  bl        -0x25E48
  addi      r3, r30, 0
  addi      r4, r1, 0x14
  bl        0x3908
  lwz       r3, 0x2F00(r13)
  li        r4, 0x1
  lfs       f1, 0x14(r1)
  lfs       f2, 0x1C(r1)
  bl        -0xDADB8
  stfs      f1, 0x18(r1)
  lwz       r3, 0x14(r1)
  lwz       r0, 0x18(r1)
  stw       r3, 0x94(r31)
  stw       r0, 0x98(r31)
  lwz       r0, 0x1C(r1)
  stw       r0, 0x9C(r31)
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
 * Address:	80142CF4
 * Size:	000104
 */
void TaiShellNaviPikiInsideAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xA0(r1)
  stfd      f31, 0x98(r1)
  addi      r3, r1, 0x7C
  stfd      f30, 0x90(r1)
  stw       r31, 0x8C(r1)
  addi      r31, r4, 0
  bl        -0x25EC0
  addi      r3, r31, 0
  addi      r4, r1, 0x7C
  bl        0x3890
  lwz       r3, 0x2C8(r31)
  li        r4, 0
  lwz       r3, 0x34(r3)
  bl        -0x1FB20
  lwz       r3, 0x2C4(r31)
  fmr       f30, f1
  li        r4, 0x1
  lwz       r3, 0x84(r3)
  bl        -0x1FB34
  lwz       r3, 0x2C4(r31)
  fmr       f31, f1
  li        r4, 0x8
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  bl        -0x20888
  lfs       f2, 0x7C(r1)
  fmuls     f0, f31, f30
  lis       r6, 0x802B
  stfs      f2, 0x5C(r1)
  lis       r5, 0x802C
  lfs       f2, 0x80(r1)
  lis       r3, 0x802D
  fmuls     f0, f1, f0
  stfs      f2, 0x60(r1)
  subi      r0, r3, 0x285C
  subi      r6, r6, 0xF68
  lfs       f1, 0x84(r1)
  addi      r5, r5, 0x6964
  stfs      f1, 0x64(r1)
  addi      r4, r1, 0x68
  mr        r3, r31
  stw       r6, 0x68(r1)
  lfs       f1, -0x5940(r2)
  stw       r5, 0x68(r1)
  stw       r0, 0x68(r1)
  stfs      f1, 0x74(r1)
  stfs      f1, 0x70(r1)
  stfs      f1, 0x6C(r1)
  lfs       f1, 0x5C(r1)
  stfs      f1, 0x6C(r1)
  lfs       f1, 0x60(r1)
  stfs      f1, 0x70(r1)
  lfs       f1, 0x64(r1)
  stfs      f1, 0x74(r1)
  stfs      f0, 0x78(r1)
  bl        0x5514
  lwz       r0, 0xA4(r1)
  lfd       f31, 0x98(r1)
  lfd       f30, 0x90(r1)
  lwz       r31, 0x8C(r1)
  addi      r1, r1, 0xA0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80142DF8
 * Size:	0001D0
 */
void TaiShellEatAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  lis       r6, 0x802D
  stw       r0, 0x4(r1)
  lis       r5, 0x802C
  lis       r3, 0x802B
  stwu      r1, -0x110(r1)
  addi      r7, r5, 0x6890
  subi      r8, r6, 0x2A4C
  stfd      f31, 0x108(r1)
  addi      r5, r1, 0xB8
  addi      r0, r1, 0xB0
  stfd      f30, 0x100(r1)
  stfd      f29, 0xF8(r1)
  stw       r31, 0xF4(r1)
  stw       r30, 0xF0(r1)
  stw       r29, 0xEC(r1)
  subi      r29, r3, 0xF68
  lis       r3, 0x802C
  stw       r28, 0xE8(r1)
  addi      r30, r3, 0x6964
  lis       r3, 0x802C
  stw       r29, 0xD8(r1)
  addi      r31, r3, 0x685C
  lis       r3, 0x802D
  stw       r29, 0xA8(r1)
  subi      r6, r3, 0x295C
  addi      r28, r4, 0
  stw       r29, 0xB0(r1)
  addi      r4, r1, 0xA8
  addi      r3, r1, 0xCC
  stw       r29, 0xB8(r1)
  stw       r30, 0xD8(r1)
  stw       r30, 0xA8(r1)
  stw       r30, 0xB0(r1)
  stw       r30, 0xB8(r1)
  stw       r31, 0xD8(r1)
  stw       r8, 0xA8(r1)
  stw       r7, 0xB0(r1)
  stw       r6, 0xB8(r1)
  stw       r5, 0xDC(r1)
  stw       r28, 0xAC(r1)
  stw       r4, 0xB4(r1)
  stw       r28, 0xBC(r1)
  stw       r0, 0xE0(r1)
  bl        -0x26054
  addi      r3, r28, 0
  addi      r4, r1, 0xCC
  bl        0x36FC
  lwz       r3, 0x2C8(r28)
  li        r4, 0
  bl        -0x1B00C
  fmr       f29, f1
  lwz       r3, 0x2C4(r28)
  li        r4, 0x1
  bl        -0x1B004
  lwz       r3, 0x2C4(r28)
  fmr       f30, f1
  li        r4, 0x8
  lwz       r3, 0x84(r3)
  bl        -0x1FCD4
  lfs       f2, 0xCC(r1)
  lis       r4, 0x802D
  subi      r0, r4, 0x285C
  lfs       f0, 0xD0(r1)
  stfs      f2, 0x88(r1)
  fmr       f31, f1
  addi      r5, r1, 0x8C
  stfs      f0, 0x8C(r1)
  addi      r6, r1, 0x90
  addi      r3, r1, 0x98
  lfs       f0, 0xD4(r1)
  addi      r4, r1, 0x88
  stfs      f0, 0x90(r1)
  stw       r29, 0x94(r1)
  lfs       f0, -0x5940(r2)
  stw       r30, 0x94(r1)
  stw       r0, 0x94(r1)
  stfs      f0, 0xA0(r1)
  stfs      f0, 0x9C(r1)
  stfs      f0, 0x98(r1)
  bl        -0xE58AC
  lis       r3, 0x802B
  stw       r29, 0xC0(r1)
  subi      r0, r3, 0x3064
  fmuls     f0, f30, f29
  stw       r0, 0x78(r1)
  lis       r3, 0x802B
  subi      r3, r3, 0x3244
  stw       r30, 0xC0(r1)
  fmuls     f0, f31, f0
  addi      r5, r1, 0xD8
  stw       r28, 0x7C(r1)
  li        r0, 0
  addi      r6, r1, 0x94
  stw       r3, 0x78(r1)
  addi      r4, r1, 0x78
  mr        r3, r28
  stw       r31, 0xC0(r1)
  stw       r5, 0xC4(r1)
  addi      r5, r1, 0xC0
  stw       r0, 0x80(r1)
  stfs      f0, 0xA4(r1)
  stw       r6, 0xC8(r1)
  stw       r0, 0x84(r1)
  bl        0x4B80
  lwz       r0, 0x114(r1)
  lfd       f31, 0x108(r1)
  lfd       f30, 0x100(r1)
  lfd       f29, 0xF8(r1)
  lwz       r31, 0xF4(r1)
  lwz       r30, 0xF0(r1)
  lwz       r29, 0xEC(r1)
  lwz       r28, 0xE8(r1)
  addi      r1, r1, 0x110
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80142FC8
 * Size:	000084
 */
void TaiPearlSoundTable::TaiPearlSoundTable()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x5
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  bl        -0x23F74
  li        r30, 0
  li        r31, 0
  b         .loc_0x58

.loc_0x30:
  li        r3, 0x4
  bl        -0xFBFF8
  cmplwi    r3, 0
  beq-      .loc_0x48
  addi      r0, r30, 0x67
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
 * Address:	8014304C
 * Size:	000148
 */
void TaiPearlParameters::TaiPearlParameters()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x14
  stw       r0, 0x4(r1)
  li        r5, 0x32
  stwu      r1, -0x68(r1)
  stw       r31, 0x64(r1)
  addi      r31, r3, 0
  bl        0x8CE0
  lis       r3, 0x802D
  subi      r0, r3, 0x3A14
  stw       r0, 0x0(r31)
  li        r7, 0x1
  li        r6, 0x3
  lwz       r4, 0x84(r31)
  li        r0, -0x1
  addi      r3, r31, 0
  lwz       r5, 0x0(r4)
  lwz       r5, 0x0(r5)
  stw       r7, 0x0(r5)
  lwz       r5, 0x0(r4)
  lwz       r5, 0x0(r5)
  stw       r6, 0x18(r5)
  lwz       r5, 0x0(r4)
  lwz       r5, 0x0(r5)
  stw       r0, 0xC(r5)
  lwz       r5, 0x0(r4)
  lwz       r5, 0x0(r5)
  stw       r7, 0x48(r5)
  lwz       r5, 0x4(r4)
  lfs       f1, -0x5938(r2)
  lwz       r5, 0x0(r5)
  stfs      f1, 0x0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f1, 0x4(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x591C(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x8(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5918(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x78(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5914(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x7C(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x593C(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x44(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5910(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x48(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x590C(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x50(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x54(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5908(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xA4(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5904(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xA8(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f1, 0xAC(r5)
  lwz       r4, 0x4(r4)
  lfs       f0, -0x5900(r2)
  lwz       r4, 0x0(r4)
  stfs      f0, 0xB0(r4)
  lwz       r0, 0x6C(r1)
  lwz       r31, 0x64(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80143194
 * Size:	00014C
 */
void TaiRocpearlParameters::TaiRocpearlParameters()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x14
  stw       r0, 0x4(r1)
  li        r5, 0x32
  stwu      r1, -0x68(r1)
  stw       r31, 0x64(r1)
  addi      r31, r3, 0
  bl        0x8B98
  lis       r3, 0x802D
  subi      r0, r3, 0x3A7C
  stw       r0, 0x0(r31)
  li        r8, 0
  li        r7, 0x3
  lwz       r4, 0x84(r31)
  li        r6, -0x1
  li        r0, 0x1
  lwz       r5, 0x0(r4)
  mr        r3, r31
  lwz       r5, 0x0(r5)
  stw       r8, 0x0(r5)
  lwz       r5, 0x0(r4)
  lwz       r5, 0x0(r5)
  stw       r7, 0x18(r5)
  lwz       r5, 0x0(r4)
  lwz       r5, 0x0(r5)
  stw       r6, 0xC(r5)
  lwz       r5, 0x0(r4)
  lwz       r5, 0x0(r5)
  stw       r0, 0x48(r5)
  lwz       r5, 0x4(r4)
  lfs       f1, -0x5938(r2)
  lwz       r5, 0x0(r5)
  stfs      f1, 0x0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f1, 0x4(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x591C(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x8(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5918(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x78(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5914(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x7C(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x593C(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x44(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5910(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x48(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x592C(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x50(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x54(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5908(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x9C(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5904(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xA0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f1, 0xAC(r5)
  lwz       r4, 0x4(r4)
  lfs       f0, -0x5900(r2)
  lwz       r4, 0x0(r4)
  stfs      f0, 0xB0(r4)
  lwz       r0, 0x6C(r1)
  lwz       r31, 0x64(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801432E0
 * Size:	00036C
 */
void TaiPearlStrategy::TaiPearlStrategy(TekiParameters *)
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x3
  stw       r0, 0x4(r1)
  li        r5, 0x2
  stwu      r1, -0x60(r1)
  stmw      r23, 0x3C(r1)
  addi      r31, r3, 0
  bl        -0x1BF18
  lis       r3, 0x802D
  subi      r0, r3, 0x3B38
  stw       r0, 0x0(r31)
  li        r3, 0x8
  bl        -0xFC30C
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x60
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r30)
  li        r0, 0
  lis       r3, 0x802D
  stw       r0, 0x0(r30)
  subi      r0, r3, 0x42D8
  stw       r0, 0x4(r30)

.loc_0x60:
  li        r3, 0x8
  bl        -0xFC340
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x94
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r29)
  li        r0, 0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r29)
  subi      r0, r3, 0x4580
  stw       r0, 0x4(r29)

.loc_0x94:
  li        r3, 0xC
  bl        -0xFC374
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0xDC
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r28)
  li        r4, 0
  subi      r0, r3, 0x447C
  stw       r4, 0x8(r28)
  stw       r0, 0x4(r28)

.loc_0xDC:
  li        r3, 0x8
  bl        -0xFC3BC
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0x110
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x43FC
  stw       r0, 0x4(r27)

.loc_0x110:
  li        r3, 0xC
  bl        -0xFC3F0
  addi      r26, r3, 0
  mr.       r0, r26
  beq-      .loc_0x14C
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r26)
  li        r0, -0x1
  lis       r3, 0x802C
  stw       r0, 0x0(r26)
  addi      r3, r3, 0x7FDC
  li        r0, 0x5B
  stw       r3, 0x4(r26)
  stw       r0, 0x8(r26)

.loc_0x14C:
  li        r3, 0x8
  bl        -0xFC42C
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x180
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r25)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r25)
  subi      r0, r3, 0x3BA4
  stw       r0, 0x4(r25)

.loc_0x180:
  li        r3, 0x10
  bl        -0xFC460
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x1C4
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r24)
  li        r0, -0x1
  lis       r3, 0x802C
  stw       r0, 0x0(r24)
  addi      r3, r3, 0x6B14
  li        r0, 0
  stw       r3, 0x4(r24)
  lwz       r3, -0x9D0(r13)
  stw       r3, 0x8(r24)
  stb       r0, 0xC(r24)

.loc_0x1C4:
  li        r3, 0xC
  bl        -0xFC4A4
  addi      r23, r3, 0
  mr.       r3, r23
  beq-      .loc_0x1E0
  li        r4, 0x5
  bl        -0x1C424

.loc_0x1E0:
  li        r0, 0
  lwz       r3, 0x8(r23)
  rlwinm    r0,r0,2,0,29
  stwx      r25, r3, r0
  li        r0, 0x1
  li        r4, 0x2
  lwz       r3, 0x8(r23)
  rlwinm    r0,r0,2,0,29
  li        r6, 0x3
  stwx      r27, r3, r0
  li        r0, 0x4
  rlwinm    r3,r4,2,0,29
  lwz       r5, 0x8(r23)
  rlwinm    r4,r6,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r28, r5, r3
  li        r3, 0xC
  lwz       r5, 0x8(r23)
  stwx      r24, r5, r4
  lwz       r4, 0x8(r23)
  stwx      r26, r4, r0
  lwz       r4, 0x8(r31)
  stw       r23, 0x0(r4)
  bl        -0xFC518
  addi      r23, r3, 0
  mr.       r0, r23
  beq-      .loc_0x274
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r23)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r23)
  subi      r3, r3, 0x6A6C
  li        r0, 0x2
  stw       r3, 0x4(r23)
  stw       r0, 0x8(r23)

.loc_0x274:
  li        r3, 0xC
  bl        -0xFC554
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x290
  li        r4, 0x3
  bl        -0x1C4D4

.loc_0x290:
  li        r0, 0
  lwz       r3, 0x8(r24)
  rlwinm    r0,r0,2,0,29
  stwx      r30, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r4, 0x8(r24)
  rlwinm    r3,r0,2,0,29
  rlwinm    r0,r5,2,0,29
  stwx      r29, r4, r3
  li        r3, 0xC
  lwz       r4, 0x8(r24)
  stwx      r23, r4, r0
  lwz       r4, 0x8(r31)
  stw       r24, 0x8(r4)
  bl        -0xFC5A8
  addi      r23, r3, 0
  mr.       r0, r23
  beq-      .loc_0x310
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r23)
  li        r0, 0x2
  lis       r3, 0x802D
  stw       r0, 0x0(r23)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r23)
  li        r4, 0x1
  subi      r0, r3, 0x4650
  stw       r4, 0x8(r23)
  stw       r0, 0x4(r23)

.loc_0x310:
  li        r3, 0xC
  bl        -0xFC5F0
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x32C
  li        r4, 0x2
  bl        -0x1C570

.loc_0x32C:
  li        r0, 0
  lwz       r3, 0x8(r24)
  rlwinm    r0,r0,2,0,29
  stwx      r30, r3, r0
  li        r0, 0x1
  rlwinm    r0,r0,2,0,29
  lwz       r4, 0x8(r24)
  mr        r3, r31
  stwx      r23, r4, r0
  lwz       r4, 0x8(r31)
  stw       r24, 0x4(r4)
  lwz       r0, 0x64(r1)
  lmw       r23, 0x3C(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014364C
 * Size:	000020
 */
void TaiPearlStrategy::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x1C1C4
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014366C
 * Size:	000064
 */
void TaiPearlTresureSoundAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  lwz       r0, 0x418(r4)
  cmplwi    r0, 0
  beq-      .loc_0x50
  mr        r31, r0
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  li        r4, 0x69
  lwz       r12, 0x1C0(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0x89
  lwz       r12, 0x1C0(r12)
  mtlr      r12
  blrl      

.loc_0x50:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}