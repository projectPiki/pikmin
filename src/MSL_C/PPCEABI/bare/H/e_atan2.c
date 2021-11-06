

/*
 * --INFO--
 * Address:	8021A718
 * Size:	000298
 */
void __ieee754_atan2(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x7FF0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stfd      f2, 0x10(r1)
  lwz       r8, 0x14(r1)
  stfd      f1, 0x8(r1)
  neg       r0, r8
  lwz       r4, 0x10(r1)
  or        r0, r8, r0
  lwz       r5, 0x8(r1)
  rlwinm    r6,r4,0,1,31
  lwz       r9, 0xC(r1)
  rlwinm    r0,r0,1,31,31
  or        r0, r6, r0
  cmplw     r0, r3
  rlwinm    r7,r5,0,1,31
  bgt-      .loc_0x64
  neg       r0, r9
  or        r0, r9, r0
  rlwinm    r0,r0,1,31,31
  or        r0, r7, r0
  cmplw     r0, r3
  ble-      .loc_0x74

.loc_0x64:
  lfd       f1, 0x10(r1)
  lfd       f0, 0x8(r1)
  fadd      f1, f1, f0
  b         .loc_0x284

.loc_0x74:
  subis     r0, r4, 0x3FF0
  or.       r0, r0, r8
  bne-      .loc_0x8C
  lfd       f1, 0x8(r1)
  bl        0xACC
  b         .loc_0x284

.loc_0x8C:
  or.       r0, r7, r9
  rlwinm    r0,r4,2,30,30
  mr        r31, r0
  rlwimi    r31,r5,1,31,31
  bne-      .loc_0xDC
  cmpwi     r31, 0x2
  beq-      .loc_0xCC
  bge-      .loc_0xB8
  cmpwi     r31, 0
  bge-      .loc_0xC4
  b         .loc_0xDC

.loc_0xB8:
  cmpwi     r31, 0x4
  bge-      .loc_0xDC
  b         .loc_0xD4

.loc_0xC4:
  lfd       f1, 0x8(r1)
  b         .loc_0x284

.loc_0xCC:
  lfd       f1, -0x3BD0(r2)
  b         .loc_0x284

.loc_0xD4:
  lfd       f1, -0x3BC8(r2)
  b         .loc_0x284

.loc_0xDC:
  or.       r0, r6, r8
  bne-      .loc_0xFC
  cmpwi     r5, 0
  bge-      .loc_0xF4
  lfd       f1, -0x3BC0(r2)
  b         .loc_0x284

.loc_0xF4:
  lfd       f1, -0x3BB8(r2)
  b         .loc_0x284

.loc_0xFC:
  subis     r0, r6, 0x7FF0
  cmplwi    r0, 0
  bne-      .loc_0x1A4
  subis     r0, r7, 0x7FF0
  cmplwi    r0, 0
  bne-      .loc_0x15C
  cmpwi     r31, 0x2
  beq-      .loc_0x14C
  bge-      .loc_0x130
  cmpwi     r31, 0
  beq-      .loc_0x13C
  bge-      .loc_0x144
  b         .loc_0x1A4

.loc_0x130:
  cmpwi     r31, 0x4
  bge-      .loc_0x1A4
  b         .loc_0x154

.loc_0x13C:
  lfd       f1, -0x3BB0(r2)
  b         .loc_0x284

.loc_0x144:
  lfd       f1, -0x3BA8(r2)
  b         .loc_0x284

.loc_0x14C:
  lfd       f1, -0x3BA0(r2)
  b         .loc_0x284

.loc_0x154:
  lfd       f1, -0x3B98(r2)
  b         .loc_0x284

.loc_0x15C:
  cmpwi     r31, 0x2
  beq-      .loc_0x194
  bge-      .loc_0x178
  cmpwi     r31, 0
  beq-      .loc_0x184
  bge-      .loc_0x18C
  b         .loc_0x1A4

.loc_0x178:
  cmpwi     r31, 0x4
  bge-      .loc_0x1A4
  b         .loc_0x19C

.loc_0x184:
  lfd       f1, -0x3B90(r2)
  b         .loc_0x284

.loc_0x18C:
  lfd       f1, -0x3B88(r2)
  b         .loc_0x284

.loc_0x194:
  lfd       f1, -0x3BD0(r2)
  b         .loc_0x284

.loc_0x19C:
  lfd       f1, -0x3BC8(r2)
  b         .loc_0x284

.loc_0x1A4:
  subis     r0, r7, 0x7FF0
  cmplwi    r0, 0
  bne-      .loc_0x1C8
  cmpwi     r5, 0
  bge-      .loc_0x1C0
  lfd       f1, -0x3BC0(r2)
  b         .loc_0x284

.loc_0x1C0:
  lfd       f1, -0x3BB8(r2)
  b         .loc_0x284

.loc_0x1C8:
  sub       r0, r7, r6
  srawi     r0, r0, 0x14
  cmpwi     r0, 0x3C
  ble-      .loc_0x1E4
  lfd       f0, -0x3BB8(r2)
  stfd      f0, 0x18(r1)
  b         .loc_0x218

.loc_0x1E4:
  cmpwi     r4, 0
  bge-      .loc_0x200
  cmpwi     r0, -0x3C
  bge-      .loc_0x200
  lfd       f0, -0x3B90(r2)
  stfd      f0, 0x18(r1)
  b         .loc_0x218

.loc_0x200:
  lfd       f1, 0x8(r1)
  lfd       f0, 0x10(r1)
  fdiv      f1, f1, f0
  bl        -0x214
  bl        0x940
  stfd      f1, 0x18(r1)

.loc_0x218:
  cmpwi     r31, 0x1
  beq-      .loc_0x244
  bge-      .loc_0x230
  cmpwi     r31, 0
  bge-      .loc_0x23C
  b         .loc_0x270

.loc_0x230:
  cmpwi     r31, 0x3
  bge-      .loc_0x270
  b         .loc_0x258

.loc_0x23C:
  lfd       f1, 0x18(r1)
  b         .loc_0x284

.loc_0x244:
  lwz       r0, 0x18(r1)
  xoris     r0, r0, 0x8000
  stw       r0, 0x18(r1)
  lfd       f1, 0x18(r1)
  b         .loc_0x284

.loc_0x258:
  lfd       f1, 0x18(r1)
  lfd       f0, -0x3B80(r2)
  lfd       f2, -0x3BD0(r2)
  fsub      f0, f1, f0
  fsub      f1, f2, f0
  b         .loc_0x284

.loc_0x270:
  lfd       f2, 0x18(r1)
  lfd       f1, -0x3B80(r2)
  lfd       f0, -0x3BD0(r2)
  fsub      f1, f2, f1
  fsub      f1, f1, f0

.loc_0x284:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}
