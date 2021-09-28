

/*
 * --INFO--
 * Address:	8021B570
 * Size:	000178
 */
void ldexp(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  stfd      f1, 0x8(r1)
  lfd       f1, 0x8(r1)
  bl        -0x3A4
  cmpwi     r3, 0x2
  ble-      .loc_0x38
  lfd       f0, -0x3A38(r2)
  lfd       f1, 0x8(r1)
  fcmpu     cr0, f0, f1
  bne-      .loc_0x40

.loc_0x38:
  lfd       f1, 0x8(r1)
  b         .loc_0x164

.loc_0x40:
  lwz       r0, 0x8(r1)
  lwz       r6, 0xC(r1)
  rlwinm.   r3,r0,12,21,31
  mr        r5, r0
  addi      r4, r3, 0
  bne-      .loc_0xA4
  rlwinm    r0,r5,0,1,31
  or.       r0, r6, r0
  bne-      .loc_0x68
  b         .loc_0x164

.loc_0x68:
  lfd       f0, -0x3A30(r2)
  lis       r3, 0xFFFF
  addi      r0, r3, 0x3CB0
  fmul      f0, f1, f0
  cmpw      r31, r0
  stfd      f0, 0x8(r1)
  lwz       r0, 0x8(r1)
  rlwinm    r3,r0,12,21,31
  mr        r5, r0
  subi      r4, r3, 0x36
  bge-      .loc_0xA4
  lfd       f1, -0x3A28(r2)
  lfd       f0, 0x8(r1)
  fmul      f1, f1, f0
  b         .loc_0x164

.loc_0xA4:
  cmpwi     r4, 0x7FF
  bne-      .loc_0xB8
  lfd       f0, 0x8(r1)
  fadd      f1, f0, f0
  b         .loc_0x164

.loc_0xB8:
  add       r4, r4, r31
  cmpwi     r4, 0x7FE
  ble-      .loc_0xDC
  lfd       f1, -0x3A20(r2)
  lfd       f2, 0x8(r1)
  bl        -0x194
  lfd       f0, -0x3A20(r2)
  fmul      f1, f0, f1
  b         .loc_0x164

.loc_0xDC:
  cmpwi     r4, 0
  ble-      .loc_0xFC
  rlwinm    r3,r5,0,12,0
  rlwinm    r0,r4,20,0,11
  or        r0, r3, r0
  stw       r0, 0x8(r1)
  lfd       f1, 0x8(r1)
  b         .loc_0x164

.loc_0xFC:
  cmpwi     r4, -0x36
  bgt-      .loc_0x144
  lis       r3, 0x1
  subi      r0, r3, 0x3CB0
  cmpw      r31, r0
  ble-      .loc_0x12C
  lfd       f1, -0x3A20(r2)
  lfd       f2, 0x8(r1)
  bl        -0x1E4
  lfd       f0, -0x3A20(r2)
  fmul      f1, f0, f1
  b         .loc_0x164

.loc_0x12C:
  lfd       f1, -0x3A28(r2)
  lfd       f2, 0x8(r1)
  bl        -0x1FC
  lfd       f0, -0x3A28(r2)
  fmul      f1, f0, f1
  b         .loc_0x164

.loc_0x144:
  addi      r0, r4, 0x36
  lfd       f1, -0x3A18(r2)
  rlwinm    r3,r5,0,12,0
  rlwinm    r0,r0,20,0,11
  or        r0, r3, r0
  stw       r0, 0x8(r1)
  lfd       f0, 0x8(r1)
  fmul      f1, f1, f0

.loc_0x164:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}