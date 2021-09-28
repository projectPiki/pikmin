

/*
 * --INFO--
 * Address:	8021BEBC
 * Size:	000090
 */
void sqrt(void)
{
/*
.loc_0x0:
  lfd       f0, -0x39D8(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x60
  fsqrte    f2, f1
  lfd       f4, -0x39D0(r2)
  lfd       f3, -0x39C8(r2)
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fnmsub    f0, f1, f0, f3
  fmul      f2, f2, f0
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fnmsub    f0, f1, f0, f3
  fmul      f2, f2, f0
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fnmsub    f0, f1, f0, f3
  fmul      f2, f2, f0
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fnmsub    f0, f1, f0, f3
  fmul      f0, f2, f0
  fmul      f1, f1, f0
  blr       

.loc_0x60:
  fcmpu     cr0, f0, f1
  bne-      .loc_0x70
  fmr       f1, f0
  blr       

.loc_0x70:
  fcmpu     cr0, f1, f0
  beq-      .loc_0x84
  lis       r3, 0x802F
  lfs       f1, -0x6B88(r3)
  blr       

.loc_0x84:
  lis       r3, 0x802F
  lfs       f1, -0x6B84(r3)
  blr
*/
}