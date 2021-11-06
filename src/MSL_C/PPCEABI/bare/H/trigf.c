

/*
 * --INFO--
 * Address:	8021BAD0
 * Size:	000044
 */
void tanf(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stfd      f31, 0x18(r1)
  stfd      f30, 0x10(r1)
  fmr       f30, f1
  bl        .loc_0x44
  fmr       f31, f1
  fmr       f1, f30
  bl        0x40
  fdivs     f1, f1, f31
  lwz       r0, 0x24(r1)
  lfd       f31, 0x18(r1)
  lfd       f30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x20
  blr       

.loc_0x44:
*/
}

/*
 * --INFO--
 * Address:	8021BB14
 * Size:	000020
 */
void cos(float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x34
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021BB34
 * Size:	000020
 */
void sin(float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x1A8
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021BB54
 * Size:	000194
 */
void cosf(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x802F
  stw       r0, 0x4(r1)
  subi      r3, r3, 0x6B50
  stwu      r1, -0x28(r1)
  stfd      f31, 0x20(r1)
  stw       r31, 0x1C(r1)
  stfs      f1, 0x8(r1)
  lfs       f0, -0x39F0(r2)
  lwz       r0, 0x8(r1)
  lfs       f6, 0x8(r1)
  rlwinm.   r0,r0,0,0,0
  fmuls     f1, f0, f6
  beq-      .loc_0x50
  lfs       f0, -0x39EC(r2)
  fsubs     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x10(r1)
  lwz       r4, 0x14(r1)
  b         .loc_0x64

.loc_0x50:
  lfs       f0, -0x39EC(r2)
  fadds     f0, f0, f1
  fctiwz    f0, f0
  stfd      f0, 0x10(r1)
  lwz       r4, 0x14(r1)

.loc_0x64:
  rlwinm    r0,r4,1,0,30
  lfd       f1, -0x39E0(r2)
  xoris     r0, r0, 0x8000
  lfs       f2, 0x0(r3)
  stw       r0, 0x14(r1)
  lis       r0, 0x4330
  lfs       f3, 0x4(r3)
  rlwinm    r31,r4,0,30,31
  stw       r0, 0x10(r1)
  lfs       f4, 0x8(r3)
  lfd       f0, 0x10(r1)
  lfs       f5, 0xC(r3)
  fsubs     f0, f0, f1
  fsubs     f0, f6, f0
  fmadds    f0, f2, f6, f0
  fmadds    f0, f3, f6, f0
  fmadds    f0, f4, f6, f0
  fmadds    f31, f5, f6, f0
  fmr       f1, f31
  bl        -0x4DC
  lfs       f0, -0x39E8(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xE0
  lis       r3, 0x8022
  rlwinm    r4,r31,3,0,28
  addi      r0, r3, 0x2D08
  add       r3, r0, r4
  lfs       f1, 0x0(r3)
  lfs       f0, 0x4(r3)
  fnmsubs   f1, f31, f1, f0
  b         .loc_0x17C

.loc_0xE0:
  rlwinm.   r0,r31,0,31,31
  fmuls     f4, f31, f31
  beq-      .loc_0x138
  lis       r3, 0x8022
  addi      r4, r3, 0x2D28
  lfs       f2, 0x4(r4)
  lis       r3, 0x8022
  lfs       f1, 0xC(r4)
  addi      r0, r3, 0x2D08
  lfs       f0, 0x14(r4)
  fmadds    f3, f2, f4, f1
  lfs       f2, 0x1C(r4)
  lfs       f1, 0x24(r4)
  rlwinm    r4,r31,3,0,28
  add       r3, r0, r4
  fmadds    f3, f4, f3, f0
  lfs       f0, 0x0(r3)
  fmadds    f2, f4, f3, f2
  fnmadds   f1, f4, f2, f1
  fmuls     f1, f31, f1
  fmuls     f1, f1, f0
  b         .loc_0x17C

.loc_0x138:
  lis       r3, 0x8022
  addi      r4, r3, 0x2D28
  lfs       f2, 0x0(r4)
  lis       r3, 0x8022
  lfs       f1, 0x8(r4)
  addi      r3, r3, 0x2D08
  rlwinm    r0,r31,3,0,28
  fmadds    f3, f2, f4, f1
  lfs       f0, 0x10(r4)
  lfs       f2, 0x18(r4)
  add       r3, r3, r0
  lfs       f1, 0x20(r4)
  fmadds    f3, f4, f3, f0
  lfs       f0, 0x4(r3)
  fmadds    f2, f4, f3, f2
  fmadds    f1, f4, f2, f1
  fmuls     f1, f1, f0

.loc_0x17C:
  lwz       r0, 0x2C(r1)
  lfd       f31, 0x20(r1)
  lwz       r31, 0x1C(r1)
  mtlr      r0
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	8021BCE8
 * Size:	0001A4
 */
void sinf(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x802F
  stw       r0, 0x4(r1)
  subi      r3, r3, 0x6B50
  stwu      r1, -0x28(r1)
  stfd      f31, 0x20(r1)
  stw       r31, 0x1C(r1)
  stfs      f1, 0x8(r1)
  lfs       f0, -0x39F0(r2)
  lwz       r0, 0x8(r1)
  lfs       f6, 0x8(r1)
  rlwinm.   r0,r0,0,0,0
  fmuls     f1, f0, f6
  beq-      .loc_0x50
  lfs       f0, -0x39EC(r2)
  fsubs     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x10(r1)
  lwz       r4, 0x14(r1)
  b         .loc_0x64

.loc_0x50:
  lfs       f0, -0x39EC(r2)
  fadds     f0, f0, f1
  fctiwz    f0, f0
  stfd      f0, 0x10(r1)
  lwz       r4, 0x14(r1)

.loc_0x64:
  rlwinm    r0,r4,1,0,30
  lfd       f1, -0x39E0(r2)
  xoris     r0, r0, 0x8000
  lfs       f2, 0x0(r3)
  stw       r0, 0x14(r1)
  lis       r0, 0x4330
  lfs       f3, 0x4(r3)
  rlwinm    r31,r4,0,30,31
  stw       r0, 0x10(r1)
  lfs       f4, 0x8(r3)
  lfd       f0, 0x10(r1)
  lfs       f5, 0xC(r3)
  fsubs     f0, f0, f1
  fsubs     f0, f6, f0
  fmadds    f0, f2, f6, f0
  fmadds    f0, f3, f6, f0
  fmadds    f0, f4, f6, f0
  fmadds    f31, f5, f6, f0
  fmr       f1, f31
  bl        -0x670
  lfs       f0, -0x39E8(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xF0
  lis       r3, 0x8022
  rlwinm    r4,r31,3,0,28
  addi      r0, r3, 0x2D08
  add       r3, r0, r4
  lfs       f1, 0x4(r3)
  lis       r4, 0x8022
  addi      r4, r4, 0x2D28
  lfs       f0, 0x0(r3)
  fmuls     f1, f31, f1
  lfs       f2, 0x24(r4)
  fmadds    f1, f2, f1, f0
  b         .loc_0x18C

.loc_0xF0:
  rlwinm.   r0,r31,0,31,31
  fmuls     f4, f31, f31
  beq-      .loc_0x144
  lis       r3, 0x8022
  addi      r4, r3, 0x2D28
  lfs       f2, 0x0(r4)
  lis       r3, 0x8022
  lfs       f1, 0x8(r4)
  addi      r0, r3, 0x2D08
  lfs       f0, 0x10(r4)
  fmadds    f3, f2, f4, f1
  lfs       f2, 0x18(r4)
  lfs       f1, 0x20(r4)
  rlwinm    r4,r31,3,0,28
  add       r3, r0, r4
  fmadds    f3, f4, f3, f0
  lfs       f0, 0x0(r3)
  fmadds    f2, f4, f3, f2
  fmadds    f1, f4, f2, f1
  fmuls     f1, f1, f0
  b         .loc_0x18C

.loc_0x144:
  lis       r3, 0x8022
  addi      r4, r3, 0x2D28
  lfs       f2, 0x4(r4)
  lis       r3, 0x8022
  lfs       f1, 0xC(r4)
  addi      r3, r3, 0x2D08
  rlwinm    r0,r31,3,0,28
  fmadds    f3, f2, f4, f1
  lfs       f0, 0x14(r4)
  lfs       f2, 0x1C(r4)
  add       r3, r3, r0
  lfs       f1, 0x24(r4)
  fmadds    f3, f4, f3, f0
  lfs       f0, 0x4(r3)
  fmadds    f2, f4, f3, f2
  fmadds    f1, f4, f2, f1
  fmuls     f1, f31, f1
  fmuls     f1, f1, f0

.loc_0x18C:
  lwz       r0, 0x2C(r1)
  lfd       f31, 0x20(r1)
  lwz       r31, 0x1C(r1)
  mtlr      r0
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	8021BE8C
 * Size:	000030
 */
void __sinit_trigf_c(void)
{
/*
.loc_0x0:
  lis       r3, 0x8022
  addi      r4, r3, 0x2CF8
  lfs       f0, 0x0(r4)
  lis       r3, 0x802F
  stfsu     f0, -0x6B50(r3)
  lfs       f0, 0x4(r4)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r4)
  stfs      f0, 0x8(r3)
  lfs       f0, 0xC(r4)
  stfs      f0, 0xC(r3)
  blr
*/
}
