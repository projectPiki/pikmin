

/*
 * --INFO--
 * Address:	8000CFC0
 * Size:	000030
 */
void Bank_InstChange(Bank_ *, unsigned long)
{
/*
.loc_0x0:
  stwu      r1, -0x18(r1)
  cmplwi    r3, 0
  stw       r4, 0xC(r1)
  lwz       r0, 0xC(r1)
  bne-      .loc_0x1C
  li        r3, 0
  b         .loc_0x28

.loc_0x1C:
  rlwinm    r0,r0,2,0,29
  add       r3, r3, r0
  lwz       r3, 0x4(r3)

.loc_0x28:
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void Bank_VoiceChange(Bank_ *, unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000D000
 * Size:	000030
 */
void Bank_PercChange(Bank_ *, unsigned long)
{
/*
.loc_0x0:
  stwu      r1, -0x18(r1)
  cmplwi    r3, 0
  stw       r4, 0xC(r1)
  lwz       r0, 0xC(r1)
  bne-      .loc_0x1C
  li        r3, 0
  b         .loc_0x28

.loc_0x1C:
  rlwinm    r0,r0,2,0,29
  add       r3, r3, r0
  lwz       r3, 0x4(r3)

.loc_0x28:
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	8000D040
 * Size:	00005C
 */
void Bank_GetInstKeymap(Inst_ *, unsigned char)
{
/*
.loc_0x0:
  cmplwi    r3, 0
  bne-      .loc_0x10
  li        r3, 0
  blr       

.loc_0x10:
  lwz       r0, 0x28(r3)
  rlwinm    r6,r4,0,24,31
  li        r7, 0
  li        r4, 0
  mtctr     r0
  cmplwi    r0, 0
  ble-      .loc_0x54

.loc_0x2C:
  addi      r0, r4, 0x2C
  lwzx      r5, r3, r0
  lbz       r0, 0x0(r5)
  cmplw     r6, r0
  bgt-      .loc_0x48
  mr        r3, r7
  blr       

.loc_0x48:
  addi      r7, r7, 0x1
  addi      r4, r4, 0x4
  bdnz+     .loc_0x2C

.loc_0x54:
  li        r3, -0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8000D0A0
 * Size:	000090
 */
void Bank_GetInstVmap(Inst_ *, unsigned char, unsigned char)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr.       r31, r3
  stb       r5, 0xD(r1)
  bne-      .loc_0x24
  li        r3, 0
  b         .loc_0x7C

.loc_0x24:
  mr        r3, r31
  bl        -0x88
  cmpwi     r3, -0x1
  beq-      .loc_0x7C
  rlwinm    r0,r3,2,0,29
  lbz       r5, 0xD(r1)
  add       r3, r31, r0
  li        r4, 0
  lwz       r6, 0x2C(r3)
  lwz       r0, 0x4(r6)
  mtctr     r0
  cmplwi    r0, 0
  ble-      .loc_0x78

.loc_0x58:
  addi      r0, r4, 0x8
  lwzx      r3, r6, r0
  lbz       r0, 0x0(r3)
  cmplw     r5, r0
  bgt-      .loc_0x70
  b         .loc_0x7C

.loc_0x70:
  addi      r4, r4, 0x4
  bdnz+     .loc_0x58

.loc_0x78:
  li        r3, 0

.loc_0x7C:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000D140
 * Size:	000068
 */
void Bank_GetPercVmap(Perc_ *, unsigned char, unsigned char)
{
/*
.loc_0x0:
  cmplwi    r3, 0
  bne-      .loc_0x10
  li        r3, 0
  blr       

.loc_0x10:
  rlwinm    r0,r4,2,22,29
  add       r3, r3, r0
  lwz       r6, 0x88(r3)
  cmplwi    r6, 0
  bne-      .loc_0x2C
  li        r3, 0
  blr       

.loc_0x2C:
  lwz       r0, 0x10(r6)
  rlwinm    r5,r5,0,24,31
  li        r4, 0
  mtctr     r0
  cmplwi    r0, 0
  ble-      .loc_0x60

.loc_0x44:
  addi      r0, r4, 0x14
  lwzx      r3, r6, r0
  lbz       r0, 0x0(r3)
  cmplw     r5, r0
  blelr-    
  addi      r4, r4, 0x4
  bdnz+     .loc_0x44

.loc_0x60:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void Bank_GetVoiceMap(Voice_ *, unsigned short)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000D1C0
 * Size:	000104
 */
void Bank_SenseToOfs(Sense_ *, unsigned char)
{
/*
.loc_0x0:
  cmplwi    r3, 0
  stwu      r1, -0x28(r1)
  bne-      .loc_0x14
  lfs       f1, -0x7F98(r2)
  b         .loc_0xFC

.loc_0x14:
  lbz       r5, 0x2(r3)
  cmplwi    r5, 0x7F
  beq-      .loc_0x28
  cmplwi    r5, 0
  bne-      .loc_0x64

.loc_0x28:
  rlwinm    r4,r4,0,24,31
  lis       r0, 0x4330
  stw       r4, 0x24(r1)
  lfs       f4, 0x4(r3)
  stw       r0, 0x20(r1)
  lfs       f0, 0x8(r3)
  lfd       f3, -0x7F90(r2)
  lfd       f2, 0x20(r1)
  fsubs     f1, f0, f4
  lfs       f0, -0x7F94(r2)
  fsubs     f2, f2, f3
  fmuls     f1, f2, f1
  fdivs     f0, f1, f0
  fadds     f1, f4, f0
  b         .loc_0xFC

.loc_0x64:
  rlwinm    r0,r4,0,24,31
  cmplw     r0, r5
  bge-      .loc_0xB0
  stw       r0, 0x24(r1)
  lis       r0, 0x4330
  lfd       f2, -0x7F90(r2)
  stw       r5, 0x1C(r1)
  lfs       f4, 0x4(r3)
  stw       r0, 0x20(r1)
  lfs       f0, -0x7F98(r2)
  stw       r0, 0x18(r1)
  lfd       f1, 0x20(r1)
  fsubs     f3, f0, f4
  lfd       f0, 0x18(r1)
  fsubs     f1, f1, f2
  fsubs     f0, f0, f2
  fdivs     f0, f1, f0
  fmadds    f1, f3, f0, f4
  b         .loc_0xFC

.loc_0xB0:
  sub       r4, r0, r5
  subfic    r0, r5, 0x7F
  xoris     r4, r4, 0x8000
  xoris     r0, r0, 0x8000
  stw       r4, 0x1C(r1)
  lis       r4, 0x4330
  lfd       f2, -0x7F88(r2)
  stw       r0, 0x24(r1)
  lfs       f0, 0x8(r3)
  stw       r4, 0x18(r1)
  lfs       f4, -0x7F98(r2)
  stw       r4, 0x20(r1)
  lfd       f1, 0x18(r1)
  fsubs     f3, f0, f4
  lfd       f0, 0x20(r1)
  fsubs     f1, f1, f2
  fsubs     f0, f0, f2
  fdivs     f0, f1, f0
  fmadds    f1, f3, f0, f4

.loc_0xFC:
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	8000D2E0
 * Size:	000048
 */
void Bank_RandToOfs(Rand_ *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  bne-      .loc_0x20
  lfs       f1, -0x7F98(r2)
  b         .loc_0x34

.loc_0x20:
  bl        0x540
  lfs       f2, 0x8(r31)
  lfs       f0, 0x4(r31)
  fmuls     f1, f1, f2
  fadds     f1, f1, f0

.loc_0x34:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000D340
 * Size:	0003F8
 */
void Bank_OscToOfs(Osc_ *, Oscbuf_ *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr.       r31, r3
  bne-      .loc_0x24
  lfs       f1, -0x7F98(r2)
  stfs      f1, 0x8(r4)
  b         .loc_0x3E4

.loc_0x24:
  lbz       r0, 0x0(r4)
  cmplwi    r0, 0x4
  bne-      .loc_0x118
  lwz       r3, 0x8(r31)
  lwz       r0, 0xC(r31)
  cmplw     r3, r0
  beq-      .loc_0x58
  li        r0, 0
  sth       r0, 0x2(r4)
  lfs       f0, -0x7F80(r2)
  stfs      f0, 0x4(r4)
  lfs       f0, 0x8(r4)
  stfs      f0, 0xC(r4)

.loc_0x58:
  lwz       r0, 0xC(r31)
  cmplwi    r0, 0
  bne-      .loc_0x78
  lhz       r0, 0x14(r4)
  cmplwi    r0, 0
  bne-      .loc_0x78
  li        r0, 0x10
  sth       r0, 0x14(r4)

.loc_0x78:
  lhz       r0, 0x14(r4)
  cmplwi    r0, 0
  beq-      .loc_0x110
  li        r3, 0x8
  lis       r0, 0x4330
  stb       r3, 0x0(r4)
  lhz       r3, 0x14(r4)
  rlwinm    r3,r3,18,30,31
  stb       r3, 0x1(r4)
  lfs       f1, -0x8000(r13)
  lfs       f0, -0x7F7C(r2)
  lhz       r3, 0x14(r4)
  fdivs     f1, f1, f0
  lfs       f0, -0x7F78(r2)
  rlwinm    r3,r3,0,18,31
  lfd       f3, -0x7F88(r2)
  xoris     r3, r3, 0x8000
  stw       r3, 0x1C(r1)
  stw       r0, 0x18(r1)
  lfd       f2, 0x18(r1)
  fdivs     f0, f1, f0
  fsubs     f1, f2, f3
  fmuls     f1, f1, f0
  stfs      f1, 0x4(r4)
  lfs       f1, 0x4(r4)
  lfs       f0, -0x7F98(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xEC
  stfs      f0, 0x4(r4)

.loc_0xEC:
  lfs       f0, -0x7F80(r2)
  stfs      f0, 0xC(r4)
  lfs       f2, 0xC(r4)
  lfs       f1, 0x8(r4)
  lfs       f0, 0x4(r4)
  fsubs     f1, f2, f1
  fdivs     f0, f1, f0
  stfs      f0, 0x10(r4)
  b         .loc_0x118

.loc_0x110:
  li        r0, 0x5
  stb       r0, 0x0(r4)

.loc_0x118:
  lbz       r0, 0x0(r4)
  cmplwi    r0, 0x6
  bne-      .loc_0x144
  li        r3, 0
  li        r0, 0x7
  sth       r3, 0x2(r4)
  lfs       f0, -0x7F80(r2)
  stfs      f0, 0x4(r4)
  lfs       f0, 0x8(r4)
  stfs      f0, 0xC(r4)
  stb       r0, 0x0(r4)

.loc_0x144:
  lbz       r5, 0x0(r4)
  cmplwi    r5, 0x5
  bne-      .loc_0x158
  lwz       r8, 0xC(r31)
  b         .loc_0x174

.loc_0x158:
  cmplwi    r5, 0x7
  bne-      .loc_0x170
  lis       r3, 0x8022
  addi      r0, r3, 0x5018
  mr        r8, r0
  b         .loc_0x174

.loc_0x170:
  lwz       r8, 0x8(r31)

.loc_0x174:
  cmplwi    r8, 0
  bne-      .loc_0x190
  cmplwi    r5, 0x8
  beq-      .loc_0x190
  lfs       f1, -0x7F98(r2)
  stfs      f1, 0x8(r4)
  b         .loc_0x3E4

.loc_0x190:
  cmplwi    r5, 0
  bne-      .loc_0x1A0
  lfs       f1, -0x7F98(r2)
  b         .loc_0x3E4

.loc_0x1A0:
  cmplwi    r5, 0x3
  bne-      .loc_0x1BC
  lfs       f2, 0x8(r4)
  lfs       f1, 0x10(r31)
  lfs       f0, 0x14(r31)
  fmadds    f1, f2, f1, f0
  b         .loc_0x3E4

.loc_0x1BC:
  cmplwi    r5, 0x1
  bne-      .loc_0x1EC
  li        r3, 0x2
  li        r0, 0
  stb       r3, 0x0(r4)
  sth       r0, 0x2(r4)
  lfs       f0, -0x7F80(r2)
  stfs      f0, 0x4(r4)
  stfs      f0, 0xC(r4)
  sth       r0, 0x14(r4)
  lfs       f1, 0x4(r31)
  b         .loc_0x1F0

.loc_0x1EC:
  lfs       f1, 0x4(r31)

.loc_0x1F0:
  lbz       r0, 0x0(r4)
  cmplwi    r0, 0x7
  bne-      .loc_0x200
  lfs       f1, -0x7F98(r2)

.loc_0x200:
  lfs       f0, 0x4(r4)
  lis       r5, 0x4330
  fsubs     f0, f0, f1
  stfs      f0, 0x4(r4)
  lfd       f8, -0x7F88(r2)
  lfs       f7, -0x7F74(r2)
  lfd       f6, -0x7F90(r2)
  lfs       f5, -0x7F7C(r2)
  lfs       f4, -0x7F78(r2)
  lfs       f0, -0x7F80(r2)
  b         .loc_0x350

.loc_0x22C:
  lhz       r0, 0x2(r4)
  lfs       f1, 0xC(r4)
  mulli     r3, r0, 0x3
  stfs      f1, 0x8(r4)
  lbz       r0, 0x0(r4)
  cmplwi    r0, 0x8
  bne-      .loc_0x254
  li        r0, 0
  stb       r0, 0x0(r4)
  b         .loc_0x360

.loc_0x254:
  rlwinm    r0,r3,1,0,30
  add       r3, r8, r0
  lha       r6, 0x0(r3)
  lha       r7, 0x2(r3)
  cmpwi     r6, 0xD
  lha       r3, 0x4(r3)
  bne-      .loc_0x278
  sth       r3, 0x2(r4)
  b         .loc_0x350

.loc_0x278:
  cmpwi     r6, 0xF
  bne-      .loc_0x28C
  li        r0, 0
  stb       r0, 0x0(r4)
  b         .loc_0x360

.loc_0x28C:
  cmpwi     r6, 0xE
  bne-      .loc_0x2B0
  li        r0, 0x3
  stb       r0, 0x0(r4)
  lfs       f2, 0x8(r4)
  lfs       f1, 0x10(r31)
  lfs       f0, 0x14(r31)
  fmadds    f1, f2, f1, f0
  b         .loc_0x3E4

.loc_0x2B0:
  extsh.    r0, r7
  stb       r6, 0x1(r4)
  bne-      .loc_0x2E8
  xoris     r0, r3, 0x8000
  stw       r0, 0x1C(r1)
  stw       r5, 0x18(r1)
  lfd       f1, 0x18(r1)
  fsubs     f1, f1, f8
  fdivs     f1, f1, f7
  stfs      f1, 0xC(r4)
  lhz       r3, 0x2(r4)
  addi      r0, r3, 0x1
  sth       r0, 0x2(r4)
  b         .loc_0x350

.loc_0x2E8:
  lfs       f1, -0x8000(r13)
  xoris     r0, r3, 0x8000
  stw       r0, 0x14(r1)
  rlwinm    r0,r7,0,16,31
  fdivs     f2, f1, f5
  stw       r5, 0x10(r1)
  lfd       f1, 0x10(r1)
  stw       r0, 0x1C(r1)
  stw       r5, 0x18(r1)
  lfd       f3, 0x18(r1)
  fdivs     f2, f2, f4
  fsubs     f1, f1, f8
  fsubs     f3, f3, f6
  fdivs     f1, f1, f7
  fmuls     f3, f3, f2
  stfs      f3, 0x4(r4)
  stfs      f1, 0xC(r4)
  lfs       f3, 0xC(r4)
  lfs       f2, 0x8(r4)
  lfs       f1, 0x4(r4)
  fsubs     f2, f3, f2
  fdivs     f1, f2, f1
  stfs      f1, 0x10(r4)
  lhz       r3, 0x2(r4)
  addi      r0, r3, 0x1
  sth       r0, 0x2(r4)

.loc_0x350:
  lfs       f1, 0x4(r4)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  beq+      .loc_0x22C

.loc_0x360:
  lfs       f2, 0x10(r4)
  lfs       f1, 0x4(r4)
  lfs       f0, 0xC(r4)
  fnmsubs   f0, f2, f1, f0
  stfs      f0, 0x8(r4)
  fmr       f1, f0
  lbz       r0, 0x1(r4)
  cmpwi     r0, 0x1
  beq-      .loc_0x398
  bge-      .loc_0x38C
  b         .loc_0x3D8

.loc_0x38C:
  cmpwi     r0, 0x3
  bge-      .loc_0x3D8
  b         .loc_0x3B8

.loc_0x398:
  lfs       f0, -0x7F80(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x3AC
  fmuls     f1, f1, f1
  b         .loc_0x3D8

.loc_0x3AC:
  fneg      f0, f1
  fmuls     f1, f0, f1
  b         .loc_0x3D8

.loc_0x3B8:
  lfs       f0, -0x7F80(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x3CC
  bl        0x51C
  b         .loc_0x3D8

.loc_0x3CC:
  fneg      f1, f1
  bl        0x510
  fneg      f1, f1

.loc_0x3D8:
  lfs       f2, 0x10(r31)
  lfs       f0, 0x14(r31)
  fmadds    f1, f1, f2, f0

.loc_0x3E4:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}