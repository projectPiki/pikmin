

/*
 * --INFO--
 * Address:	8021B268
 * Size:	000240
 */
void atan(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x8022
  stw       r0, 0x4(r1)
  lis       r0, 0x4410
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0x2BA8
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  stfd      f1, 0x8(r1)
  lwz       r30, 0x8(r1)
  rlwinm    r29,r30,0,1,31
  cmpw      r29, r0
  blt-      .loc_0x94
  lis       r0, 0x7FF0
  cmpw      r29, r0
  bgt-      .loc_0x5C
  subis     r0, r29, 0x7FF0
  cmplwi    r0, 0
  bne-      .loc_0x68
  lwz       r0, 0xC(r1)
  cmpwi     r0, 0
  beq-      .loc_0x68

.loc_0x5C:
  lfd       f0, 0x8(r1)
  fadd      f1, f0, f0
  b         .loc_0x224

.loc_0x68:
  cmpwi     r30, 0
  ble-      .loc_0x80
  lfd       f1, 0x18(r31)
  lfd       f0, 0x38(r31)
  fadd      f1, f1, f0
  b         .loc_0x224

.loc_0x80:
  lfd       f1, 0x18(r31)
  lfd       f0, 0x38(r31)
  fneg      f1, f1
  fsub      f1, f1, f0
  b         .loc_0x224

.loc_0x94:
  lis       r0, 0x3FDC
  cmpw      r29, r0
  bge-      .loc_0xD0
  lis       r0, 0x3E20
  cmpw      r29, r0
  bge-      .loc_0xC8
  lfd       f2, -0x3A68(r2)
  lfd       f1, 0x8(r1)
  lfd       f0, -0x3A60(r2)
  fadd      f2, f2, f1
  fcmpo     cr0, f2, f0
  ble-      .loc_0xC8
  b         .loc_0x224

.loc_0xC8:
  li        r0, -0x1
  b         .loc_0x180

.loc_0xD0:
  lfd       f1, 0x8(r1)
  bl        -0xC2C
  lis       r0, 0x3FF3
  stfd      f1, 0x8(r1)
  cmpw      r29, r0
  bge-      .loc_0x138
  lis       r0, 0x3FE6
  cmpw      r29, r0
  bge-      .loc_0x118
  lfd       f3, 0x8(r1)
  li        r0, 0
  lfd       f2, -0x3A58(r2)
  lfd       f1, -0x3A60(r2)
  fadd      f0, f2, f3
  fmsub     f1, f2, f3, f1
  fdiv      f0, f1, f0
  stfd      f0, 0x8(r1)
  b         .loc_0x180

.loc_0x118:
  lfd       f2, 0x8(r1)
  li        r0, 0x1
  lfd       f0, -0x3A60(r2)
  fsub      f1, f2, f0
  fadd      f0, f0, f2
  fdiv      f0, f1, f0
  stfd      f0, 0x8(r1)
  b         .loc_0x180

.loc_0x138:
  lis       r3, 0x4004
  subi      r0, r3, 0x8000
  cmpw      r29, r0
  bge-      .loc_0x16C
  lfd       f3, 0x8(r1)
  li        r0, 0x2
  lfd       f2, -0x3A50(r2)
  lfd       f0, -0x3A60(r2)
  fsub      f1, f3, f2
  fmadd     f0, f2, f3, f0
  fdiv      f0, f1, f0
  stfd      f0, 0x8(r1)
  b         .loc_0x180

.loc_0x16C:
  lfd       f1, -0x3A48(r2)
  li        r0, 0x3
  lfd       f0, 0x8(r1)
  fdiv      f0, f1, f0
  stfd      f0, 0x8(r1)

.loc_0x180:
  lfd       f10, 0x8(r1)
  cmpwi     r0, 0
  lfd       f5, 0x90(r31)
  fmul      f12, f10, f10
  lfd       f0, 0x80(r31)
  lfd       f8, 0x70(r31)
  lfd       f4, 0x88(r31)
  lfd       f3, 0x78(r31)
  fmul      f11, f12, f12
  lfd       f7, 0x60(r31)
  lfd       f2, 0x68(r31)
  lfd       f6, 0x50(r31)
  lfd       f1, 0x58(r31)
  fmadd     f9, f11, f5, f0
  lfd       f5, 0x40(r31)
  lfd       f0, 0x48(r31)
  fmadd     f3, f11, f4, f3
  fmadd     f4, f11, f9, f8
  fmadd     f2, f11, f3, f2
  fmadd     f3, f11, f4, f7
  fmadd     f1, f11, f2, f1
  fmadd     f2, f11, f3, f6
  fmadd     f0, f11, f1, f0
  fmadd     f1, f11, f2, f5
  fmul      f2, f11, f0
  fmul      f0, f12, f1
  bge-      .loc_0x1F8
  fadd      f0, f0, f2
  fnmsub    f1, f10, f0, f10
  b         .loc_0x224

.loc_0x1F8:
  rlwinm    r0,r0,3,0,28
  fadd      f1, f0, f2
  add       r3, r31, r0
  lfdx      f2, r31, r0
  lfd       f0, 0x20(r3)
  cmpwi     r30, 0
  fmsub     f0, f10, f1, f0
  fsub      f0, f0, f10
  fsub      f1, f2, f0
  bge-      .loc_0x224
  fneg      f1, f1

.loc_0x224:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  blr
*/
}
