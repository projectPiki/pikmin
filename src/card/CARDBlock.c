

/*
 * --INFO--
 * Address:	802094AC
 * Size:	000008
 */
void __CARDGetFatBlock(void)
{
/*
.loc_0x0:
  lwz       r3, 0x88(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	802094B4
 * Size:	0000D4
 */
void WriteCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr.       r30, r4
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  mulli     r5, r29, 0x108
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  add       r31, r0, r5
  blt-      .loc_0x78
  lwz       r3, 0x80(r31)
  lwz       r0, 0x88(r31)
  addi      r4, r3, 0x6000
  cmplw     r0, r4
  addis     r5, r3, 0x1
  subi      r5, r5, 0x8000
  bne-      .loc_0x64
  stw       r5, 0x88(r31)
  addi      r3, r5, 0
  li        r5, 0x2000
  bl        -0x2060FC
  b         .loc_0x78

.loc_0x64:
  stw       r4, 0x88(r31)
  addi      r3, r4, 0
  addi      r4, r5, 0
  li        r5, 0x2000
  bl        -0x206114

.loc_0x78:
  lwz       r0, 0xD0(r31)
  cmplwi    r0, 0
  bne-      .loc_0x90
  addi      r3, r31, 0
  addi      r4, r30, 0
  bl        -0x620

.loc_0x90:
  lwz       r0, 0xD8(r31)
  cmplwi    r0, 0
  mr        r12, r0
  beq-      .loc_0xB8
  li        r0, 0
  mtlr      r12
  stw       r0, 0xD8(r31)
  addi      r3, r29, 0
  addi      r4, r30, 0
  blrl      

.loc_0xB8:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	80209588
 * Size:	0000C8
 */
void EraseCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r3, 0
  lis       r3, 0x803D
  stw       r30, 0x20(r1)
  mulli     r5, r31, 0x108
  stw       r29, 0x1C(r1)
  addi      r0, r3, 0x3420
  mr.       r29, r4
  add       r30, r0, r5
  blt-      .loc_0x6C
  lwz       r5, 0x88(r30)
  lis       r3, 0x8021
  lwz       r0, 0x80(r30)
  subi      r7, r3, 0x6B4C
  lwz       r3, 0xC(r30)
  sub       r0, r5, r0
  rlwinm    r0,r0,19,13,31
  mullw     r4, r3, r0
  addi      r6, r5, 0
  addi      r3, r31, 0
  li        r5, 0x2000
  bl        -0x1B8
  mr.       r29, r3
  bge-      .loc_0xAC

.loc_0x6C:
  lwz       r0, 0xD0(r30)
  cmplwi    r0, 0
  bne-      .loc_0x84
  addi      r3, r30, 0
  addi      r4, r29, 0
  bl        -0x6E8

.loc_0x84:
  lwz       r0, 0xD8(r30)
  cmplwi    r0, 0
  mr        r12, r0
  beq-      .loc_0xAC
  li        r0, 0
  mtlr      r12
  stw       r0, 0xD8(r30)
  addi      r3, r31, 0
  addi      r4, r29, 0
  blrl      

.loc_0xAC:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	80209650
 * Size:	000118
 */
void __CARDAllocBlock(void)
{
/*
.loc_0x0:
  mflr      r0
  mulli     r7, r3, 0x108
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  lis       r6, 0x803D
  addi      r0, r6, 0x3420
  stw       r31, 0x1C(r1)
  add       r9, r0, r7
  stw       r30, 0x18(r1)
  lwz       r0, 0x0(r9)
  cmpwi     r0, 0
  bne-      .loc_0x38
  li        r3, -0x3
  b         .loc_0x100

.loc_0x38:
  lwz       r8, 0x88(r9)
  lhz       r0, 0x6(r8)
  cmplw     r0, r4
  bge-      .loc_0x50
  li        r3, -0x9
  b         .loc_0x100

.loc_0x50:
  sub       r0, r0, r4
  sth       r0, 0x6(r8)
  lis       r6, 0x1
  subi      r12, r6, 0x1
  lhz       r11, 0x8(r8)
  addi      r0, r12, 0
  li        r30, 0
  b         .loc_0xE8

.loc_0x70:
  lhz       r10, 0x10(r9)
  addi      r30, r30, 0x1
  rlwinm    r6,r30,0,16,31
  subi      r7, r10, 0x5
  cmpw      r7, r6
  bge-      .loc_0x90
  li        r3, -0x6
  b         .loc_0x100

.loc_0x90:
  addi      r11, r11, 0x1
  rlwinm    r6,r11,0,16,31
  cmplwi    r6, 0x5
  blt-      .loc_0xA8
  cmplw     r6, r10
  blt-      .loc_0xAC

.loc_0xA8:
  li        r11, 0x5

.loc_0xAC:
  rlwinm    r6,r11,1,15,30
  add       r7, r8, r6
  lhz       r6, 0x0(r7)
  cmplwi    r6, 0
  bne-      .loc_0xE8
  rlwinm    r6,r12,0,16,31
  cmplwi    r6, 0xFFFF
  bne-      .loc_0xD4
  mr        r12, r11
  b         .loc_0xDC

.loc_0xD4:
  rlwinm    r6,r31,1,15,30
  sthx      r11, r8, r6

.loc_0xDC:
  sth       r0, 0x0(r7)
  addi      r31, r11, 0
  subi      r4, r4, 0x1

.loc_0xE8:
  cmplwi    r4, 0
  bne+      .loc_0x70
  sth       r11, 0x8(r8)
  mr        r4, r8
  sth       r12, 0xBE(r9)
  bl        0xB8

.loc_0x100:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	80209768
 * Size:	00009C
 */
void __CARDFreeBlock(void)
{
/*
.loc_0x0:
  mflr      r0
  mulli     r7, r3, 0x108
  stw       r0, 0x4(r1)
  lis       r6, 0x803D
  stwu      r1, -0x8(r1)
  addi      r0, r6, 0x3420
  add       r9, r0, r7
  lwz       r0, 0x0(r9)
  cmpwi     r0, 0
  bne-      .loc_0x30
  li        r3, -0x3
  b         .loc_0x8C

.loc_0x30:
  lwz       r8, 0x88(r9)
  li        r7, 0
  b         .loc_0x78

.loc_0x3C:
  rlwinm    r4,r4,0,16,31
  cmplwi    r4, 0x5
  blt-      .loc_0x54
  lhz       r0, 0x10(r9)
  cmplw     r4, r0
  blt-      .loc_0x5C

.loc_0x54:
  li        r3, -0x6
  b         .loc_0x8C

.loc_0x5C:
  rlwinm    r0,r4,1,0,30
  add       r6, r8, r0
  lhz       r4, 0x0(r6)
  sth       r7, 0x0(r6)
  lhz       r6, 0x6(r8)
  addi      r0, r6, 0x1
  sth       r0, 0x6(r8)

.loc_0x78:
  rlwinm    r0,r4,0,16,31
  cmplwi    r0, 0xFFFF
  bne+      .loc_0x3C
  mr        r4, r8
  bl        .loc_0x9C

.loc_0x8C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr       

.loc_0x9C:
*/
}

/*
 * --INFO--
 * Address:	80209804
 * Size:	0000AC
 */
void __CARDUpdateFatBlock(void)
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
  addi      r5, r29, 0
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  addi      r6, r29, 0x2
  lhz       r3, 0x4(r4)
  mulli     r4, r28, 0x108
  addi      r0, r3, 0x1
  lis       r3, 0x803D
  sth       r0, 0x4(r29)
  addi      r0, r3, 0x3420
  add       r31, r0, r4
  addi      r3, r29, 0x4
  li        r4, 0x1FFC
  bl        0x2BC
  addi      r3, r29, 0
  li        r4, 0x2000
  bl        -0x12C48
  stw       r30, 0xD8(r31)
  lis       r3, 0x8021
  subi      r5, r3, 0x6A78
  lwz       r0, 0x80(r31)
  mr        r3, r28
  lwz       r4, 0xC(r31)
  sub       r0, r29, r0
  rlwinm    r0,r0,19,13,31
  mullw     r4, r4, r0
  bl        -0xBA4
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  lwz       r28, 0x18(r1)
  addi      r1, r1, 0x28
  blr
*/
}