

/*
 * --INFO--
 * Address:	80014BC0
 * Size:	0000CC
 */
void Jam_PitchToCent(void)
{
/*
.loc_0x0:
  stwu      r1, -0x30(r1)
  lis       r0, 0x4330
  lfs       f0, -0x7EC8(r2)
  lfd       f3, -0x7EB8(r2)
  fmuls     f1, f0, f1
  lfs       f0, -0x7EC4(r2)
  fmuls     f2, f1, f2
  fctiwz    f1, f2
  fcmpo     cr0, f2, f0
  stfd      f1, 0x20(r1)
  lwz       r3, 0x24(r1)
  stfd      f1, 0x28(r1)
  extsh     r3, r3
  xoris     r3, r3, 0x8000
  lwz       r4, 0x2C(r1)
  stw       r3, 0x1C(r1)
  stw       r0, 0x18(r1)
  lfd       f1, 0x18(r1)
  fsubs     f1, f1, f3
  fsubs     f1, f2, f1
  bge-      .loc_0x68
  fcmpu     cr0, f0, f1
  beq-      .loc_0x68
  lfs       f0, -0x7EC0(r2)
  subi      r4, r4, 0x1
  fadds     f1, f1, f0

.loc_0x68:
  lfs       f0, -0x7EC0(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x80
  fsubs     f1, f1, f0
  addi      r4, r4, 0x1

.loc_0x80:
  lfs       f0, -0x7EBC(r2)
  extsh     r0, r4
  lis       r4, 0x8022
  lis       r3, 0x8022
  fmuls     f0, f0, f1
  addi      r5, r4, 0x4E18
  rlwinm    r4,r0,2,0,29
  addi      r0, r3, 0x5728
  add       r3, r5, r4
  fctiwz    f0, f0
  lfs       f1, 0xF0(r3)
  stfd      f0, 0x18(r1)
  lwz       r3, 0x1C(r1)
  rlwinm    r3,r3,2,14,29
  add       r3, r0, r3
  lfs       f0, 0x0(r3)
  fmuls     f1, f1, f0
  addi      r1, r1, 0x30
  blr
*/
}
