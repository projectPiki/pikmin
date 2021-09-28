

/*
 * --INFO--
 * Address:	8021A9B0
 * Size:	000818
 */
void __ieee754_pow(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x8022
  stw       r0, 0x4(r1)
  stwu      r1, -0x88(r1)
  stfd      f31, 0x80(r1)
  stmw      r25, 0x64(r1)
  addi      r31, r3, 0x2B78
  stfd      f2, 0x10(r1)
  lwz       r29, 0x10(r1)
  stfd      f1, 0x8(r1)
  lwz       r4, 0x14(r1)
  rlwinm    r28,r29,0,1,31
  lwz       r30, 0x8(r1)
  or.       r0, r28, r4
  lwz       r25, 0xC(r1)
  rlwinm    r26,r30,0,1,31
  bne-      .loc_0x4C
  lfd       f1, -0x3B78(r2)
  b         .loc_0x800

.loc_0x4C:
  lis       r0, 0x7FF0
  cmpw      r26, r0
  bgt-      .loc_0x8C
  subis     r0, r26, 0x7FF0
  cmplwi    r0, 0
  bne-      .loc_0x6C
  cmplwi    r25, 0
  bne-      .loc_0x8C

.loc_0x6C:
  lis       r0, 0x7FF0
  cmpw      r28, r0
  bgt-      .loc_0x8C
  subis     r0, r28, 0x7FF0
  cmplwi    r0, 0
  bne-      .loc_0x9C
  cmplwi    r4, 0
  beq-      .loc_0x9C

.loc_0x8C:
  lfd       f1, 0x8(r1)
  lfd       f0, 0x10(r1)
  fadd      f1, f1, f0
  b         .loc_0x800

.loc_0x9C:
  cmpwi     r30, 0
  li        r27, 0
  bge-      .loc_0x11C
  lis       r0, 0x4340
  cmpw      r28, r0
  blt-      .loc_0xBC
  li        r27, 0x2
  b         .loc_0x11C

.loc_0xBC:
  lis       r0, 0x3FF0
  cmpw      r28, r0
  blt-      .loc_0x11C
  srawi     r3, r28, 0x14
  subi      r0, r3, 0x3FF
  cmpwi     r0, 0x14
  ble-      .loc_0xF8
  subfic    r0, r0, 0x34
  srw       r3, r4, r0
  slw       r0, r3, r0
  cmplw     r4, r0
  bne-      .loc_0x11C
  rlwinm    r0,r3,0,31,31
  subfic    r27, r0, 0x2
  b         .loc_0x11C

.loc_0xF8:
  cmplwi    r4, 0
  bne-      .loc_0x11C
  subfic    r0, r0, 0x14
  sraw      r3, r28, r0
  slw       r0, r3, r0
  cmpw      r28, r0
  bne-      .loc_0x11C
  rlwinm    r0,r3,0,31,31
  subfic    r27, r0, 0x2

.loc_0x11C:
  cmplwi    r4, 0
  bne-      .loc_0x1EC
  subis     r0, r28, 0x7FF0
  cmplwi    r0, 0
  bne-      .loc_0x188
  subis     r0, r26, 0x3FF0
  or.       r0, r0, r25
  bne-      .loc_0x148
  lfd       f0, 0x10(r1)
  fsub      f1, f0, f0
  b         .loc_0x800

.loc_0x148:
  lis       r0, 0x3FF0
  cmpw      r26, r0
  blt-      .loc_0x16C
  cmpwi     r29, 0
  blt-      .loc_0x164
  lfd       f1, 0x10(r1)
  b         .loc_0x800

.loc_0x164:
  lfd       f1, -0x3B70(r2)
  b         .loc_0x800

.loc_0x16C:
  cmpwi     r29, 0
  bge-      .loc_0x180
  lfd       f0, 0x10(r1)
  fneg      f1, f0
  b         .loc_0x800

.loc_0x180:
  lfd       f1, -0x3B70(r2)
  b         .loc_0x800

.loc_0x188:
  subis     r0, r28, 0x3FF0
  cmplwi    r0, 0
  bne-      .loc_0x1B4
  cmpwi     r29, 0
  bge-      .loc_0x1AC
  lfd       f1, -0x3B78(r2)
  lfd       f0, 0x8(r1)
  fdiv      f1, f1, f0
  b         .loc_0x800

.loc_0x1AC:
  lfd       f1, 0x8(r1)
  b         .loc_0x800

.loc_0x1B4:
  subis     r0, r29, 0x4000
  cmplwi    r0, 0
  bne-      .loc_0x1CC
  lfd       f0, 0x8(r1)
  fmul      f1, f0, f0
  b         .loc_0x800

.loc_0x1CC:
  subis     r0, r29, 0x3FE0
  cmplwi    r0, 0
  bne-      .loc_0x1EC
  cmpwi     r30, 0
  blt-      .loc_0x1EC
  lfd       f1, 0x8(r1)
  bl        0x1328
  b         .loc_0x800

.loc_0x1EC:
  lfd       f1, 0x8(r1)
  bl        -0x490
  cmplwi    r25, 0
  stfd      f1, 0x48(r1)
  bne-      .loc_0x280
  subis     r0, r26, 0x7FF0
  cmplwi    r0, 0
  beq-      .loc_0x220
  cmpwi     r26, 0
  beq-      .loc_0x220
  subis     r0, r26, 0x3FF0
  cmplwi    r0, 0
  bne-      .loc_0x280

.loc_0x220:
  lfd       f1, 0x48(r1)
  cmpwi     r29, 0
  stfd      f1, 0x50(r1)
  bge-      .loc_0x23C
  lfd       f0, -0x3B78(r2)
  fdiv      f0, f0, f1
  stfd      f0, 0x50(r1)

.loc_0x23C:
  cmpwi     r30, 0
  bge-      .loc_0x278
  subis     r0, r26, 0x3FF0
  or.       r0, r0, r27
  bne-      .loc_0x264
  lfd       f0, 0x50(r1)
  fsub      f0, f0, f0
  fdiv      f0, f0, f0
  stfd      f0, 0x50(r1)
  b         .loc_0x278

.loc_0x264:
  cmpwi     r27, 0x1
  bne-      .loc_0x278
  lfd       f0, 0x50(r1)
  fneg      f0, f0
  stfd      f0, 0x50(r1)

.loc_0x278:
  lfd       f1, 0x50(r1)
  b         .loc_0x800

.loc_0x280:
  srawi     r3, r30, 0x1F
  addi      r0, r3, 0x1
  or.       r3, r0, r27
  bne-      .loc_0x2A4
  li        r0, 0x21
  stw       r0, 0x3490(r13)
  lis       r3, 0x802F
  lfs       f1, -0x6B88(r3)
  b         .loc_0x800

.loc_0x2A4:
  lis       r3, 0x41E0
  cmpw      r28, r3
  ble-      .loc_0x3B4
  lis       r3, 0x43F0
  cmpw      r28, r3
  ble-      .loc_0x304
  lis       r3, 0x3FF0
  subi      r4, r3, 0x1
  cmpw      r26, r4
  bgt-      .loc_0x2E4
  cmpwi     r29, 0
  bge-      .loc_0x2DC
  lfd       f1, -0x3B68(r2)
  b         .loc_0x800

.loc_0x2DC:
  lfd       f1, -0x3B70(r2)
  b         .loc_0x800

.loc_0x2E4:
  cmpw      r26, r3
  blt-      .loc_0x304
  cmpwi     r29, 0
  ble-      .loc_0x2FC
  lfd       f1, -0x3B68(r2)
  b         .loc_0x800

.loc_0x2FC:
  lfd       f1, -0x3B70(r2)
  b         .loc_0x800

.loc_0x304:
  lis       r3, 0x3FF0
  subi      r4, r3, 0x1
  cmpw      r26, r4
  bge-      .loc_0x32C
  cmpwi     r29, 0
  bge-      .loc_0x324
  lfd       f1, -0x3B68(r2)
  b         .loc_0x800

.loc_0x324:
  lfd       f1, -0x3B70(r2)
  b         .loc_0x800

.loc_0x32C:
  cmpw      r26, r3
  ble-      .loc_0x34C
  cmpwi     r29, 0
  ble-      .loc_0x344
  lfd       f1, -0x3B68(r2)
  b         .loc_0x800

.loc_0x344:
  lfd       f1, -0x3B70(r2)
  b         .loc_0x800

.loc_0x34C:
  lfd       f1, 0x8(r1)
  li        r3, 0
  lfd       f0, -0x3B78(r2)
  lfd       f2, -0x3B38(r2)
  fsub      f4, f1, f0
  lfd       f1, -0x3B40(r2)
  lfd       f0, -0x3B48(r2)
  lfd       f3, -0x3B50(r2)
  stfd      f4, 0x28(r1)
  lfd       f5, -0x3B60(r2)
  lfd       f6, 0x28(r1)
  lfd       f4, -0x3B58(r2)
  fnmsub    f1, f2, f6, f1
  fmul      f2, f6, f6
  fnmsub    f0, f6, f1, f0
  fmul      f1, f5, f6
  fmul      f0, f2, f0
  fmul      f0, f3, f0
  fmsub     f2, f4, f6, f0
  fadd      f0, f1, f2
  stfd      f0, 0x30(r1)
  stw       r3, 0x34(r1)
  lfd       f0, 0x30(r1)
  fsub      f0, f0, f1
  fsub      f0, f2, f0
  b         .loc_0x5A0

.loc_0x3B4:
  lis       r3, 0x10
  cmpw      r26, r3
  li        r8, 0
  bge-      .loc_0x3DC
  lfd       f1, 0x48(r1)
  li        r8, -0x35
  lfd       f0, -0x3B30(r2)
  fmul      f0, f1, f0
  stfd      f0, 0x48(r1)
  lwz       r26, 0x48(r1)

.loc_0x3DC:
  lis       r3, 0x4
  rlwinm    r5,r26,0,12,31
  subi      r3, r3, 0x6772
  srawi     r4, r26, 0x14
  add       r8, r4, r8
  cmpw      r5, r3
  oris      r4, r5, 0x3FF0
  subi      r8, r8, 0x3FF
  bgt-      .loc_0x408
  li        r7, 0
  b         .loc_0x42C

.loc_0x408:
  lis       r3, 0xC
  subi      r3, r3, 0x4986
  cmpw      r5, r3
  bge-      .loc_0x420
  li        r7, 0x1
  b         .loc_0x42C

.loc_0x420:
  subis     r4, r4, 0x10
  li        r7, 0
  addi      r8, r8, 0x1

.loc_0x42C:
  stw       r4, 0x48(r1)
  rlwinm    r3,r7,3,0,28
  add       r6, r31, r3
  lfd       f2, -0x3B78(r2)
  lfd       f11, 0x48(r1)
  lfd       f3, 0x0(r6)
  srawi     r3, r4, 0x1
  lfd       f0, -0x3B70(r2)
  oris      r3, r3, 0x2000
  fadd      f1, f11, f3
  fsub      f8, f11, f3
  addis     r5, r3, 0x8
  rlwinm    r3,r7,18,0,13
  stfd      f0, 0x18(r1)
  fdiv      f13, f2, f1
  add       r3, r5, r3
  lfd       f4, -0x3B00(r2)
  stw       r3, 0x18(r1)
  xoris     r4, r8, 0x8000
  fmul      f0, f8, f13
  lfd       f3, -0x3B08(r2)
  lfd       f1, -0x3B10(r2)
  li        r5, 0
  lfd       f2, -0x3B18(r2)
  fmul      f31, f0, f0
  stfd      f0, 0x20(r1)
  lfd       f6, 0x18(r1)
  lis       r3, 0x4330
  stw       r5, 0x24(r1)
  fmadd     f3, f4, f31, f3
  lfd       f4, 0x0(r6)
  lfd       f12, 0x20(r1)
  fsub      f10, f6, f4
  stw       r4, 0x5C(r1)
  fmadd     f3, f31, f3, f1
  lfd       f1, -0x3B20(r2)
  lfd       f5, -0x3B28(r2)
  fnmsub    f9, f12, f6, f8
  lfd       f7, -0x3AF8(r2)
  fmadd     f2, f31, f3, f2
  stw       r3, 0x58(r1)
  lfd       f3, -0x3AE0(r2)
  fsub      f10, f11, f10
  lfd       f4, -0x3AE8(r2)
  fmadd     f8, f31, f2, f1
  lfd       f2, -0x3A70(r2)
  lfd       f1, 0x58(r1)
  fnmsub    f10, f12, f10, f9
  lfd       f6, -0x3AF0(r2)
  fmadd     f5, f31, f8, f5
  fmul      f9, f31, f31
  fmul      f10, f13, f10
  fmul      f9, f9, f5
  fmul      f11, f12, f12
  fadd      f8, f12, f0
  fsub      f1, f1, f2
  fadd      f5, f7, f11
  fmadd     f9, f10, f8, f9
  fadd      f2, f5, f9
  stfd      f2, 0x18(r1)
  stw       r5, 0x1C(r1)
  lfd       f5, 0x18(r1)
  fsub      f2, f5, f7
  fmul      f8, f12, f5
  fsub      f2, f2, f11
  fsub      f2, f9, f2
  fmul      f0, f2, f0
  fmadd     f2, f10, f5, f0
  fadd      f0, f8, f2
  stfd      f0, 0x40(r1)
  stw       r5, 0x44(r1)
  lfd       f7, 0x40(r1)
  lfd       f5, 0x20(r6)
  fsub      f0, f7, f8
  stfd      f1, 0x28(r1)
  fmul      f6, f6, f7
  fsub      f1, f2, f0
  lfd       f0, 0x10(r6)
  lfd       f2, 0x28(r1)
  fmul      f1, f3, f1
  fmadd     f1, f4, f7, f1
  fadd      f3, f5, f1
  fadd      f1, f6, f3
  fadd      f0, f1, f0
  fadd      f0, f2, f0
  stfd      f0, 0x30(r1)
  stw       r5, 0x34(r1)
  lfd       f1, 0x30(r1)
  lfd       f0, 0x10(r6)
  fsub      f1, f1, f2
  fsub      f0, f1, f0
  fsub      f0, f0, f6
  fsub      f0, f3, f0

.loc_0x5A0:
  subi      r3, r27, 0x1
  lfd       f31, -0x3B78(r2)
  or.       r0, r0, r3
  bne-      .loc_0x5B4
  lfd       f31, -0x3AD8(r2)

.loc_0x5B4:
  lfd       f2, 0x10(r1)
  li        r3, 0
  lfd       f3, 0x30(r1)
  lis       r0, 0x4090
  stfd      f2, 0x38(r1)
  fmul      f1, f2, f0
  stw       r3, 0x3C(r1)
  lfd       f4, 0x38(r1)
  fmul      f0, f4, f3
  fsub      f2, f2, f4
  stfd      f0, 0x40(r1)
  fmadd     f8, f3, f2, f1
  lfd       f2, 0x40(r1)
  fadd      f0, f8, f2
  stfd      f0, 0x50(r1)
  lwz       r5, 0x50(r1)
  lwz       r6, 0x54(r1)
  cmpw      r5, r0
  blt-      .loc_0x644
  subis     r0, r5, 0x4090
  or.       r0, r0, r6
  beq-      .loc_0x61C
  lfd       f1, -0x3AD0(r2)
  fmul      f0, f1, f31
  fmul      f1, f1, f0
  b         .loc_0x800

.loc_0x61C:
  lfd       f1, -0x3AC8(r2)
  lfd       f0, 0x50(r1)
  fadd      f1, f1, f8
  fsub      f0, f0, f2
  fcmpo     cr0, f1, f0
  ble-      .loc_0x69C
  lfd       f1, -0x3AD0(r2)
  fmul      f0, f1, f31
  fmul      f1, f1, f0
  b         .loc_0x800

.loc_0x644:
  lis       r3, 0x4091
  rlwinm    r4,r5,0,1,31
  subi      r0, r3, 0x3400
  cmpw      r4, r0
  blt-      .loc_0x69C
  addis     r3, r5, 0x3F6F
  addi      r0, r3, 0x3400
  or.       r0, r0, r6
  beq-      .loc_0x678
  lfd       f1, -0x3AC0(r2)
  fmul      f0, f1, f31
  fmul      f1, f1, f0
  b         .loc_0x800

.loc_0x678:
  lfd       f0, 0x50(r1)
  fsub      f0, f0, f2
  fcmpo     cr0, f8, f0
  cror      2, 0, 0x2
  bne-      .loc_0x69C
  lfd       f1, -0x3AC0(r2)
  fmul      f0, f1, f31
  fmul      f1, f1, f0
  b         .loc_0x800

.loc_0x69C:
  rlwinm    r4,r5,0,1,31
  lis       r0, 0x3FE0
  rlwinm    r3,r5,12,21,31
  subi      r6, r3, 0x3FF
  cmpw      r4, r0
  li        r3, 0
  ble-      .loc_0x714
  lis       r4, 0x10
  lfd       f0, -0x3B70(r2)
  addi      r0, r6, 0x1
  sraw      r0, r4, r0
  stfd      f0, 0x28(r1)
  add       r7, r5, r0
  rlwinm    r3,r7,12,21,31
  subi      r6, r3, 0x3FF
  subi      r0, r4, 0x1
  sraw      r0, r0, r6
  andc      r3, r7, r0
  rlwinm    r0,r7,0,12,31
  stw       r3, 0x28(r1)
  oris      r3, r0, 0x10
  subfic    r0, r6, 0x14
  cmpwi     r5, 0
  sraw      r3, r3, r0
  bge-      .loc_0x704
  neg       r3, r3

.loc_0x704:
  lfd       f1, 0x40(r1)
  lfd       f0, 0x28(r1)
  fsub      f0, f1, f0
  stfd      f0, 0x40(r1)

.loc_0x714:
  lfd       f2, 0x40(r1)
  li        r0, 0
  lfd       f1, -0x3AA8(r2)
  rlwinm    r4,r3,20,0,11
  fadd      f0, f8, f2
  lfd       f10, -0x3AB8(r2)
  lfd       f9, -0x3AB0(r2)
  stfd      f0, 0x28(r1)
  lfd       f6, -0x3A80(r2)
  stw       r0, 0x2C(r1)
  lfd       f0, -0x3A88(r2)
  lfd       f11, 0x28(r1)
  lfd       f5, -0x3A90(r2)
  fsub      f3, f11, f2
  lfd       f4, -0x3A98(r2)
  fmul      f7, f1, f11
  lfd       f2, -0x3AA0(r2)
  lfd       f1, -0x3A78(r2)
  fsub      f8, f8, f3
  lfd       f3, -0x3B78(r2)
  fmul      f10, f10, f11
  fmadd     f11, f9, f8, f7
  fadd      f7, f10, f11
  stfd      f7, 0x50(r1)
  lfd       f9, 0x50(r1)
  fmul      f7, f9, f9
  fsub      f8, f9, f10
  stfd      f7, 0x28(r1)
  fsub      f8, f11, f8
  lfd       f7, 0x28(r1)
  fmadd     f6, f6, f7, f0
  fmadd     f0, f9, f8, f8
  fmadd     f5, f7, f6, f5
  fmadd     f4, f7, f5, f4
  fmadd     f2, f7, f4, f2
  fmul      f2, f7, f2
  fsub      f2, f9, f2
  stfd      f2, 0x30(r1)
  lfd       f4, 0x30(r1)
  fmul      f2, f9, f4
  fsub      f1, f4, f1
  fdiv      f1, f2, f1
  fsub      f0, f1, f0
  fsub      f0, f0, f9
  fsub      f0, f3, f0
  stfd      f0, 0x50(r1)
  lwz       r0, 0x50(r1)
  add       r0, r0, r4
  srawi.    r0, r0, 0x14
  bgt-      .loc_0x7EC
  lfd       f1, 0x50(r1)
  bl        .loc_0x818
  stfd      f1, 0x50(r1)
  b         .loc_0x7F8

.loc_0x7EC:
  lwz       r0, 0x50(r1)
  add       r0, r0, r4
  stw       r0, 0x50(r1)

.loc_0x7F8:
  lfd       f0, 0x50(r1)
  fmul      f1, f31, f0

.loc_0x800:
  lmw       r25, 0x64(r1)
  lwz       r0, 0x8C(r1)
  lfd       f31, 0x80(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr       

.loc_0x818:
*/
}

/*
 * --INFO--
 * Address:	8021B1C8
 * Size:	000020
 */
void scalbn(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x39C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}