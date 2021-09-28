

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
 * Address:	........
 * Size:	00005C
 */
void GetAtanTable(float, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011DB48
 * Size:	0002C0
 */
void atan(float, float)
{
/*
.loc_0x0:
  stwu      r1, -0x28(r1)
  lis       r3, 0x802C
  addi      r3, r3, 0x4378
  lfs       f0, -0x5FC0(r2)
  fcmpo     cr0, f2, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x164
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0xC0
  fcmpo     cr0, f1, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x78
  fcmpu     cr0, f0, f1
  bne-      .loc_0x44
  lhz       r0, 0x1C(r3)
  b         .loc_0x70

.loc_0x44:
  fdivs     f0, f2, f1
  lfs       f1, -0x5FB8(r2)
  lfs       f2, -0x5FBC(r2)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x20(r1)
  lwz       r0, 0x24(r1)
  rlwinm    r0,r0,1,0,30
  add       r3, r3, r0
  lhz       r0, 0x1C(r3)

.loc_0x70:
  rlwinm    r3,r0,0,16,31
  b         .loc_0x2B4

.loc_0x78:
  fcmpu     cr0, f0, f2
  bne-      .loc_0x88
  lhz       r0, 0x1C(r3)
  b         .loc_0xB4

.loc_0x88:
  fdivs     f0, f1, f2
  lfs       f1, -0x5FB8(r2)
  lfs       f2, -0x5FBC(r2)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x20(r1)
  lwz       r0, 0x24(r1)
  rlwinm    r0,r0,1,0,30
  add       r3, r3, r0
  lhz       r0, 0x1C(r3)

.loc_0xB4:
  rlwinm    r0,r0,0,16,31
  subfic    r3, r0, 0x4000
  b         .loc_0x2B4

.loc_0xC0:
  fneg      f1, f1
  fcmpo     cr0, f1, f2
  bge-      .loc_0x114
  fcmpu     cr0, f0, f2
  bne-      .loc_0xDC
  lhz       r0, 0x1C(r3)
  b         .loc_0x108

.loc_0xDC:
  fdivs     f0, f1, f2
  lfs       f1, -0x5FB8(r2)
  lfs       f2, -0x5FBC(r2)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x20(r1)
  lwz       r0, 0x24(r1)
  rlwinm    r0,r0,1,0,30
  add       r3, r3, r0
  lhz       r0, 0x1C(r3)

.loc_0x108:
  rlwinm    r3,r0,0,16,31
  addi      r3, r3, 0x4000
  b         .loc_0x2B4

.loc_0x114:
  fcmpu     cr0, f0, f1
  bne-      .loc_0x124
  lhz       r0, 0x1C(r3)
  b         .loc_0x150

.loc_0x124:
  fdivs     f0, f2, f1
  lfs       f1, -0x5FB8(r2)
  lfs       f2, -0x5FBC(r2)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x20(r1)
  lwz       r0, 0x24(r1)
  rlwinm    r0,r0,1,0,30
  add       r3, r3, r0
  lhz       r0, 0x1C(r3)

.loc_0x150:
  lis       r3, 0x1
  rlwinm    r4,r0,0,16,31
  subi      r0, r3, 0x8000
  sub       r3, r0, r4
  b         .loc_0x2B4

.loc_0x164:
  fcmpo     cr0, f1, f0
  fneg      f2, f2
  bge-      .loc_0x21C
  fneg      f1, f1
  fcmpo     cr0, f1, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x1CC
  fcmpu     cr0, f0, f1
  bne-      .loc_0x190
  lhz       r0, 0x1C(r3)
  b         .loc_0x1BC

.loc_0x190:
  fdivs     f0, f2, f1
  lfs       f1, -0x5FB8(r2)
  lfs       f2, -0x5FBC(r2)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x20(r1)
  lwz       r0, 0x24(r1)
  rlwinm    r0,r0,1,0,30
  add       r3, r3, r0
  lhz       r0, 0x1C(r3)

.loc_0x1BC:
  rlwinm    r3,r0,0,16,31
  addis     r3, r3, 0x1
  subi      r3, r3, 0x8000
  b         .loc_0x2B4

.loc_0x1CC:
  fcmpu     cr0, f0, f2
  bne-      .loc_0x1DC
  lhz       r0, 0x1C(r3)
  b         .loc_0x208

.loc_0x1DC:
  fdivs     f0, f1, f2
  lfs       f1, -0x5FB8(r2)
  lfs       f2, -0x5FBC(r2)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x20(r1)
  lwz       r0, 0x24(r1)
  rlwinm    r0,r0,1,0,30
  add       r3, r3, r0
  lhz       r0, 0x1C(r3)

.loc_0x208:
  lis       r3, 0x1
  rlwinm    r4,r0,0,16,31
  subi      r0, r3, 0x4000
  sub       r3, r0, r4
  b         .loc_0x2B4

.loc_0x21C:
  fcmpo     cr0, f1, f2
  bge-      .loc_0x270
  fcmpu     cr0, f0, f2
  bne-      .loc_0x234
  lhz       r0, 0x1C(r3)
  b         .loc_0x260

.loc_0x234:
  fdivs     f0, f1, f2
  lfs       f1, -0x5FB8(r2)
  lfs       f2, -0x5FBC(r2)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x20(r1)
  lwz       r0, 0x24(r1)
  rlwinm    r0,r0,1,0,30
  add       r3, r3, r0
  lhz       r0, 0x1C(r3)

.loc_0x260:
  rlwinm    r3,r0,0,16,31
  addis     r3, r3, 0x1
  subi      r3, r3, 0x4000
  b         .loc_0x2B4

.loc_0x270:
  fcmpu     cr0, f0, f1
  bne-      .loc_0x280
  lhz       r0, 0x1C(r3)
  b         .loc_0x2AC

.loc_0x280:
  fdivs     f0, f2, f1
  lfs       f1, -0x5FB8(r2)
  lfs       f2, -0x5FBC(r2)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x20(r1)
  lwz       r0, 0x24(r1)
  rlwinm    r0,r0,1,0,30
  add       r3, r3, r0
  lhz       r0, 0x1C(r3)

.loc_0x2AC:
  rlwinm    r0,r0,0,16,31
  neg       r3, r0

.loc_0x2B4:
  rlwinm    r3,r3,0,16,31
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void NMathF::remainder(float, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011DE08
 * Size:	000058
 */
void NMathF::atan2(float, float)
{
/*
.loc_0x0:
  fmr       f0, f2
  mflr      r0
  stw       r0, 0x4(r1)
  fmr       f2, f1
  fmr       f1, f0
  stwu      r1, -0x18(r1)
  bl        -0x2D8
  rlwinm    r0,r3,0,16,31
  lfd       f3, -0x5FA8(r2)
  stw       r0, 0x14(r1)
  lis       r0, 0x4330
  lfs       f1, -0x5FB0(r2)
  stw       r0, 0x10(r1)
  lfs       f0, -0x5FB4(r2)
  lfd       f2, 0x10(r1)
  fsubs     f2, f2, f3
  fdivs     f1, f2, f1
  fmuls     f1, f0, f1
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}