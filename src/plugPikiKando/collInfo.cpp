

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
 * Address:	80086CC4
 * Size:	0002DC
 */
void Cylinder::get2dDist(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x190(r1)
  stfd      f31, 0x188(r1)
  stfd      f30, 0x180(r1)
  stfd      f29, 0x178(r1)
  stfd      f28, 0x170(r1)
  stfd      f27, 0x168(r1)
  stfd      f26, 0x160(r1)
  stw       r31, 0x15C(r1)
  mr        r31, r4
  stw       r30, 0x158(r1)
  mr        r30, r3
  lfs       f3, 0x10(r3)
  lfs       f2, 0x4(r3)
  lfs       f1, 0xC(r3)
  fsubs     f30, f3, f2
  lfs       f0, 0x0(r3)
  lfs       f2, 0x14(r3)
  fsubs     f31, f1, f0
  lfs       f0, 0x8(r3)
  fsubs     f29, f2, f0
  fmr       f27, f30
  fmr       f28, f31
  fmr       f26, f29
  fmuls     f0, f27, f27
  fmuls     f1, f28, f28
  fmuls     f2, f26, f26
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x790FC
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x94
  fdivs     f28, f28, f1
  fdivs     f27, f27, f1
  fdivs     f26, f26, f1

.loc_0x94:
  lfs       f8, 0x0(r31)
  lfs       f9, 0x0(r30)
  lfs       f5, 0x8(r31)
  lfs       f6, 0x8(r30)
  fsubs     f0, f8, f9
  lfs       f4, 0x4(r31)
  lfs       f7, 0x4(r30)
  fsubs     f3, f5, f6
  lfs       f2, -0x75C0(r2)
  stfs      f0, 0xC0(r1)
  fsubs     f0, f4, f7
  fmuls     f4, f26, f3
  lfs       f3, 0xC0(r1)
  fmuls     f0, f27, f0
  fmuls     f3, f28, f3
  fadds     f0, f3, f0
  fadds     f0, f4, f0
  fdivs     f3, f0, f1
  fcmpo     cr0, f3, f2
  bge-      .loc_0x15C
  fsubs     f0, f6, f5
  fsubs     f1, f9, f8
  fmuls     f0, f0, f0
  fmuls     f1, f1, f1
  fadds     f1, f1, f0
  fcmpo     cr0, f1, f2
  ble-      .loc_0x2AC
  fsqrte    f2, f1
  lfd       f4, -0x75B8(r2)
  lfd       f3, -0x75B0(r2)
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fmul      f0, f1, f0
  fsub      f0, f3, f0
  fmul      f2, f2, f0
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fmul      f0, f1, f0
  fsub      f0, f3, f0
  fmul      f2, f2, f0
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fmul      f0, f1, f0
  fsub      f0, f3, f0
  fmul      f0, f2, f0
  fmul      f0, f1, f0
  frsp      f0, f0
  stfs      f0, 0xBC(r1)
  lfs       f1, 0xBC(r1)
  b         .loc_0x2AC

.loc_0x15C:
  lfs       f0, -0x75A8(r2)
  fcmpo     cr0, f3, f0
  ble-      .loc_0x1E8
  lfs       f1, 0x14(r30)
  lfs       f0, 0xC(r30)
  fsubs     f1, f1, f5
  fsubs     f3, f0, f8
  fmuls     f0, f1, f1
  fmuls     f1, f3, f3
  fadds     f1, f1, f0
  fcmpo     cr0, f1, f2
  ble-      .loc_0x2AC
  fsqrte    f2, f1
  lfd       f4, -0x75B8(r2)
  lfd       f3, -0x75B0(r2)
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fmul      f0, f1, f0
  fsub      f0, f3, f0
  fmul      f2, f2, f0
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fmul      f0, f1, f0
  fsub      f0, f3, f0
  fmul      f2, f2, f0
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fmul      f0, f1, f0
  fsub      f0, f3, f0
  fmul      f0, f2, f0
  fmul      f0, f1, f0
  frsp      f0, f0
  stfs      f0, 0xB8(r1)
  lfs       f1, 0xB8(r1)
  b         .loc_0x2AC

.loc_0x1E8:
  fmuls     f2, f29, f3
  addi      r6, r1, 0x94
  fmuls     f1, f30, f3
  addi      r5, r1, 0x90
  fmuls     f0, f31, f3
  stfs      f2, 0x94(r1)
  addi      r4, r1, 0x8C
  addi      r3, r1, 0xCC
  stfs      f1, 0x90(r1)
  stfs      f0, 0x8C(r1)
  bl        -0x4FDB8
  lfs       f3, 0xD4(r1)
  lfs       f2, 0x8(r30)
  lfs       f1, 0xCC(r1)
  fadds     f4, f3, f2
  lfs       f0, 0x0(r30)
  lfs       f3, 0x8(r31)
  fadds     f2, f1, f0
  lfs       f1, 0x0(r31)
  fsubs     f3, f4, f3
  lfs       f0, -0x75C0(r2)
  fsubs     f2, f2, f1
  fmuls     f1, f3, f3
  fmuls     f2, f2, f2
  fadds     f1, f2, f1
  fcmpo     cr0, f1, f0
  ble-      .loc_0x2AC
  fsqrte    f2, f1
  lfd       f4, -0x75B8(r2)
  lfd       f3, -0x75B0(r2)
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fmul      f0, f1, f0
  fsub      f0, f3, f0
  fmul      f2, f2, f0
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fmul      f0, f1, f0
  fsub      f0, f3, f0
  fmul      f2, f2, f0
  fmul      f0, f2, f2
  fmul      f2, f4, f2
  fmul      f0, f1, f0
  fsub      f0, f3, f0
  fmul      f0, f2, f0
  fmul      f0, f1, f0
  frsp      f0, f0
  stfs      f0, 0xB0(r1)
  lfs       f1, 0xB0(r1)

.loc_0x2AC:
  lwz       r0, 0x194(r1)
  lfd       f31, 0x188(r1)
  lfd       f30, 0x180(r1)
  lfd       f29, 0x178(r1)
  lfd       f28, 0x170(r1)
  lfd       f27, 0x168(r1)
  lfd       f26, 0x160(r1)
  lwz       r31, 0x15C(r1)
  lwz       r30, 0x158(r1)
  addi      r1, r1, 0x190
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80086FA0
 * Size:	0003C0
 */
void Cylinder::collide(const Sphere &, Vector3f &, float &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x190(r1)
  stfd      f31, 0x188(r1)
  stfd      f30, 0x180(r1)
  stfd      f29, 0x178(r1)
  stfd      f28, 0x170(r1)
  stfd      f27, 0x168(r1)
  stfd      f26, 0x160(r1)
  stw       r31, 0x15C(r1)
  mr        r31, r6
  stw       r30, 0x158(r1)
  mr        r30, r5
  stw       r29, 0x154(r1)
  mr        r29, r4
  stw       r28, 0x150(r1)
  mr        r28, r3
  lfs       f3, 0x10(r3)
  lfs       f2, 0x4(r3)
  lfs       f1, 0xC(r3)
  fsubs     f27, f3, f2
  lfs       f0, 0x0(r3)
  lfs       f2, 0x14(r3)
  fsubs     f28, f1, f0
  lfs       f0, 0x8(r3)
  fsubs     f26, f2, f0
  fmr       f30, f27
  fmr       f31, f28
  fmr       f29, f26
  fmuls     f0, f30, f30
  fmuls     f1, f31, f31
  fadds     f0, f1, f0
  fmuls     f1, f29, f29
  fadds     f1, f1, f0
  bl        -0x793E8
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0xA4
  fdivs     f31, f31, f1
  fdivs     f30, f30, f1
  fdivs     f29, f29, f1

.loc_0xA4:
  lfs       f3, 0x0(r29)
  addi      r6, r1, 0x88
  lfs       f0, 0x0(r28)
  addi      r5, r1, 0x84
  lfs       f2, -0x75A4(r2)
  fsubs     f3, f3, f0
  lfs       f0, -0x75C0(r2)
  fmuls     f5, f2, f1
  addi      r4, r1, 0x80
  addi      r3, r1, 0xF0
  stfs      f3, 0xC4(r1)
  lfs       f6, 0xC4(r1)
  lfs       f4, 0x4(r29)
  lfs       f3, 0x4(r28)
  fmuls     f6, f31, f6
  lfs       f8, 0x8(r29)
  fsubs     f3, f4, f3
  lfs       f7, 0x8(r28)
  lfs       f4, 0xC(r29)
  fsubs     f7, f8, f7
  stfs      f0, 0x12C(r1)
  fmuls     f3, f30, f3
  stfs      f0, 0x128(r1)
  fmuls     f7, f29, f7
  stfs      f0, 0x124(r1)
  fadds     f0, f6, f3
  fadds     f0, f7, f0
  fdivs     f29, f0, f1
  fsubs     f0, f29, f2
  fmuls     f3, f26, f29
  fmuls     f2, f27, f29
  fabs      f6, f0
  fmuls     f0, f28, f29
  stfs      f3, 0x88(r1)
  fmuls     f1, f1, f6
  stfs      f2, 0x84(r1)
  stfs      f0, 0x80(r1)
  fsubs     f0, f1, f4
  fsubs     f30, f5, f0
  bl        -0x4FFC4
  lfs       f2, 0xF0(r1)
  lfs       f1, 0x0(r28)
  lfs       f0, 0x0(r29)
  fadds     f1, f2, f1
  lfs       f3, 0x8(r28)
  lfs       f4, 0xF8(r1)
  lfs       f2, 0x4(r28)
  fsubs     f0, f1, f0
  lfs       f1, 0xF4(r1)
  fadds     f3, f4, f3
  stfs      f0, 0x124(r1)
  fadds     f1, f1, f2
  lfs       f0, 0x4(r29)
  fsubs     f0, f1, f0
  stfs      f0, 0x128(r1)
  lfs       f0, 0x8(r29)
  fsubs     f0, f3, f0
  stfs      f0, 0x12C(r1)
  lfs       f1, 0x124(r1)
  lfs       f0, 0x128(r1)
  fmuls     f2, f1, f1
  lfs       f3, 0x12C(r1)
  fmuls     f1, f0, f0
  lfs       f0, -0x75C0(r2)
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x210
  fsqrte    f1, f4
  lfd       f3, -0x75B8(r2)
  lfd       f2, -0x75B0(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f4, f0
  frsp      f0, f0
  stfs      f0, 0x90(r1)
  lfs       f4, 0x90(r1)

.loc_0x210:
  lfs       f0, -0x75C0(r2)
  lfs       f2, 0xC(r29)
  lfs       f1, 0x18(r28)
  fcmpo     cr0, f30, f0
  fadds     f1, f2, f1
  fsubs     f31, f1, f4
  cror      2, 0x1, 0x2
  bne-      .loc_0x298
  fcmpo     cr0, f30, f31
  bge-      .loc_0x298
  fcmpo     cr0, f31, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x298
  lfs       f0, -0x75A4(r2)
  fcmpo     cr0, f29, f0
  bge-      .loc_0x254
  fneg      f30, f30

.loc_0x254:
  fmuls     f2, f28, f30
  li        r3, 0x1
  fmuls     f1, f27, f30
  fmuls     f0, f26, f30
  stfs      f2, 0xAC(r1)
  lfs       f2, 0xAC(r1)
  stfs      f2, 0xE4(r1)
  stfs      f1, 0xE8(r1)
  stfs      f0, 0xEC(r1)
  lwz       r4, 0xE4(r1)
  lwz       r0, 0xE8(r1)
  stw       r4, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r0, 0xEC(r1)
  stw       r0, 0x8(r30)
  stfs      f29, 0x0(r31)
  b         .loc_0x388

.loc_0x298:
  lfs       f1, -0x75C0(r2)
  fcmpo     cr0, f29, f1
  cror      2, 0x1, 0x2
  bne-      .loc_0x384
  lfs       f0, -0x75A8(r2)
  fcmpo     cr0, f29, f0
  cror      2, 0, 0x2
  bne-      .loc_0x384
  fcmpo     cr0, f31, f1
  cror      2, 0x1, 0x2
  bne-      .loc_0x384
  lwz       r3, 0x124(r1)
  lwz       r0, 0x128(r1)
  stw       r3, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r0, 0x12C(r1)
  stw       r0, 0x8(r30)
  lfs       f1, 0x0(r30)
  lfs       f0, 0x4(r30)
  lfs       f2, 0x8(r30)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x7965C
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x330
  lfs       f0, 0x0(r30)
  fdivs     f0, f0, f1
  stfs      f0, 0x0(r30)
  lfs       f0, 0x4(r30)
  fdivs     f0, f0, f1
  stfs      f0, 0x4(r30)
  lfs       f0, 0x8(r30)
  fdivs     f0, f0, f1
  stfs      f0, 0x8(r30)

.loc_0x330:
  fneg      f1, f31
  lfs       f0, 0x0(r30)
  li        r3, 0x1
  fmuls     f0, f0, f1
  stfs      f0, 0x9C(r1)
  lfs       f0, 0x9C(r1)
  stfs      f0, 0xD8(r1)
  lfs       f0, 0x4(r30)
  fmuls     f0, f0, f1
  stfs      f0, 0xDC(r1)
  lfs       f0, 0x8(r30)
  fmuls     f0, f0, f1
  stfs      f0, 0xE0(r1)
  lwz       r4, 0xD8(r1)
  lwz       r0, 0xDC(r1)
  stw       r4, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r0, 0xE0(r1)
  stw       r0, 0x8(r30)
  stfs      f29, 0x0(r31)
  b         .loc_0x388

.loc_0x384:
  li        r3, 0

.loc_0x388:
  lwz       r0, 0x194(r1)
  lfd       f31, 0x188(r1)
  lfd       f30, 0x180(r1)
  lfd       f29, 0x178(r1)
  lfd       f28, 0x170(r1)
  lfd       f27, 0x168(r1)
  lfd       f26, 0x160(r1)
  lwz       r31, 0x15C(r1)
  lwz       r30, 0x158(r1)
  lwz       r29, 0x154(r1)
  lwz       r28, 0x150(r1)
  addi      r1, r1, 0x190
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80087360
 * Size:	00002C
 */
void Tube::getYRatio(float)
{
/*
.loc_0x0:
  lfs       f2, 0x10(r3)
  lfs       f3, 0x4(r3)
  lfs       f0, -0x75C0(r2)
  fsubs     f2, f2, f3
  fcmpu     cr0, f0, f2
  beq-      .loc_0x24
  fsubs     f0, f1, f3
  fdivs     f1, f0, f2
  blr       

.loc_0x24:
  lfs       f1, -0x75A0(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	8008738C
 * Size:	00033C
 */
void Tube::collide(const Sphere &, Vector3f &, float &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x178(r1)
  stfd      f31, 0x170(r1)
  stfd      f30, 0x168(r1)
  stfd      f29, 0x160(r1)
  stfd      f28, 0x158(r1)
  stfd      f27, 0x150(r1)
  stfd      f26, 0x148(r1)
  stw       r31, 0x144(r1)
  mr        r31, r6
  stw       r30, 0x140(r1)
  mr        r30, r5
  stw       r29, 0x13C(r1)
  mr        r29, r4
  stw       r28, 0x138(r1)
  mr        r28, r3
  lfs       f3, 0x10(r3)
  lfs       f2, 0x4(r3)
  lfs       f1, 0xC(r3)
  fsubs     f27, f3, f2
  lfs       f0, 0x0(r3)
  lfs       f2, 0x14(r3)
  fsubs     f28, f1, f0
  lfs       f0, 0x8(r3)
  fsubs     f26, f2, f0
  fmr       f30, f27
  fmr       f31, f28
  fmr       f29, f26
  fmuls     f0, f30, f30
  fmuls     f1, f31, f31
  fadds     f0, f1, f0
  fmuls     f1, f29, f29
  fadds     f1, f1, f0
  bl        -0x797D4
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0xA4
  fdivs     f31, f31, f1
  fdivs     f30, f30, f1
  fdivs     f29, f29, f1

.loc_0xA4:
  lfs       f2, 0x0(r29)
  addi      r6, r1, 0x80
  lfs       f0, 0x0(r28)
  addi      r5, r1, 0x7C
  addi      r4, r1, 0x78
  fsubs     f2, f2, f0
  lfs       f0, -0x75C0(r2)
  addi      r3, r1, 0xD0
  stfs      f2, 0xB0(r1)
  lfs       f3, 0x4(r29)
  lfs       f2, 0x4(r28)
  lfs       f4, 0xB0(r1)
  fsubs     f2, f3, f2
  lfs       f6, 0x8(r29)
  lfs       f5, 0x8(r28)
  fmuls     f3, f31, f4
  fsubs     f4, f6, f5
  fmuls     f2, f30, f2
  stfs      f0, 0x110(r1)
  stfs      f0, 0x10C(r1)
  fmuls     f4, f29, f4
  fadds     f2, f3, f2
  stfs      f0, 0x108(r1)
  fadds     f0, f4, f2
  fdivs     f29, f0, f1
  fmuls     f2, f26, f29
  fmuls     f1, f27, f29
  fmuls     f0, f28, f29
  stfs      f2, 0x80(r1)
  stfs      f1, 0x7C(r1)
  stfs      f0, 0x78(r1)
  bl        -0x50390
  lfs       f2, 0xD0(r1)
  lfs       f1, 0x0(r28)
  lfs       f0, 0x0(r29)
  fadds     f1, f2, f1
  lfs       f3, 0x8(r28)
  lfs       f4, 0xD8(r1)
  lfs       f2, 0x4(r28)
  fsubs     f0, f1, f0
  lfs       f1, 0xD4(r1)
  fadds     f3, f4, f3
  stfs      f0, 0x108(r1)
  fadds     f1, f1, f2
  lfs       f0, 0x4(r29)
  fsubs     f0, f1, f0
  stfs      f0, 0x10C(r1)
  lfs       f0, 0x8(r29)
  fsubs     f0, f3, f0
  stfs      f0, 0x110(r1)
  lfs       f1, 0x108(r1)
  lfs       f0, 0x10C(r1)
  fmuls     f2, f1, f1
  lfs       f3, 0x110(r1)
  fmuls     f1, f0, f0
  lfs       f0, -0x75C0(r2)
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f6, f3, f1
  fcmpo     cr0, f6, f0
  ble-      .loc_0x1F0
  fsqrte    f1, f6
  lfd       f3, -0x75B8(r2)
  lfd       f2, -0x75B0(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f6, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f6, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f6, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f6, f0
  frsp      f0, f0
  stfs      f0, 0x88(r1)
  lfs       f6, 0x88(r1)

.loc_0x1F0:
  lfs       f4, -0x75A8(r2)
  lfs       f1, 0x1C(r28)
  fsubs     f3, f4, f29
  lfs       f2, 0x18(r28)
  lfs       f0, -0x75C0(r2)
  fmuls     f1, f1, f29
  lfs       f5, 0xC(r29)
  fmuls     f2, f3, f2
  fcmpo     cr0, f29, f0
  fadds     f1, f2, f1
  fadds     f1, f5, f1
  cror      2, 0x1, 0x2
  fsubs     f26, f1, f6
  bne-      .loc_0x300
  fcmpo     cr0, f29, f4
  cror      2, 0, 0x2
  bne-      .loc_0x300
  fcmpo     cr0, f26, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x300
  lwz       r3, 0x108(r1)
  lwz       r0, 0x10C(r1)
  stw       r3, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r0, 0x110(r1)
  stw       r0, 0x8(r30)
  lfs       f1, 0x0(r30)
  lfs       f0, 0x4(r30)
  lfs       f2, 0x8(r30)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x799C4
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x2AC
  lfs       f0, 0x0(r30)
  fdivs     f0, f0, f1
  stfs      f0, 0x0(r30)
  lfs       f0, 0x4(r30)
  fdivs     f0, f0, f1
  stfs      f0, 0x4(r30)
  lfs       f0, 0x8(r30)
  fdivs     f0, f0, f1
  stfs      f0, 0x8(r30)

.loc_0x2AC:
  fneg      f1, f26
  lfs       f0, 0x0(r30)
  li        r3, 0x1
  fmuls     f0, f0, f1
  stfs      f0, 0x94(r1)
  lfs       f0, 0x94(r1)
  stfs      f0, 0xC4(r1)
  lfs       f0, 0x4(r30)
  fmuls     f0, f0, f1
  stfs      f0, 0xC8(r1)
  lfs       f0, 0x8(r30)
  fmuls     f0, f0, f1
  stfs      f0, 0xCC(r1)
  lwz       r4, 0xC4(r1)
  lwz       r0, 0xC8(r1)
  stw       r4, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r0, 0xCC(r1)
  stw       r0, 0x8(r30)
  stfs      f29, 0x0(r31)
  b         .loc_0x304

.loc_0x300:
  li        r3, 0

.loc_0x304:
  lwz       r0, 0x17C(r1)
  lfd       f31, 0x170(r1)
  lfd       f30, 0x168(r1)
  lfd       f29, 0x160(r1)
  lfd       f28, 0x158(r1)
  lfd       f27, 0x150(r1)
  lfd       f26, 0x148(r1)
  lwz       r31, 0x144(r1)
  lwz       r30, 0x140(r1)
  lwz       r29, 0x13C(r1)
  lwz       r28, 0x138(r1)
  addi      r1, r1, 0x178
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800876C8
 * Size:	0000E4
 */
void Cylinder::getPosRatio(const Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xC0(r1)
  stfd      f31, 0xB8(r1)
  stfd      f30, 0xB0(r1)
  stfd      f29, 0xA8(r1)
  stw       r31, 0xA4(r1)
  mr        r31, r4
  stw       r30, 0xA0(r1)
  mr        r30, r3
  lfs       f3, 0xC(r3)
  lfs       f2, 0x0(r3)
  lfs       f1, 0x10(r3)
  lfs       f0, 0x4(r3)
  fsubs     f31, f3, f2
  lfs       f2, 0x14(r3)
  fsubs     f30, f1, f0
  lfs       f0, 0x8(r3)
  fmuls     f1, f31, f31
  fsubs     f29, f2, f0
  fmuls     f0, f30, f30
  fmuls     f2, f29, f29
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x79AE8
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x7C
  fdivs     f31, f31, f1
  fdivs     f30, f30, f1
  fdivs     f29, f29, f1

.loc_0x7C:
  lfs       f2, 0x0(r31)
  lfs       f0, 0x0(r30)
  fsubs     f0, f2, f0
  stfs      f0, 0x54(r1)
  lfs       f2, 0x4(r31)
  lfs       f0, 0x4(r30)
  lfs       f3, 0x54(r1)
  fsubs     f0, f2, f0
  lfs       f5, 0x8(r31)
  lfs       f4, 0x8(r30)
  fmuls     f2, f31, f3
  fsubs     f3, f5, f4
  fmuls     f0, f30, f0
  fmuls     f3, f29, f3
  fadds     f0, f2, f0
  fadds     f0, f3, f0
  fdivs     f1, f0, f1
  lwz       r0, 0xC4(r1)
  lfd       f31, 0xB8(r1)
  lfd       f30, 0xB0(r1)
  lfd       f29, 0xA8(r1)
  lwz       r31, 0xA4(r1)
  lwz       r30, 0xA0(r1)
  addi      r1, r1, 0xC0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800877AC
 * Size:	0000E4
 */
void Tube::getPosRatio(const Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xC0(r1)
  stfd      f31, 0xB8(r1)
  stfd      f30, 0xB0(r1)
  stfd      f29, 0xA8(r1)
  stw       r31, 0xA4(r1)
  mr        r31, r4
  stw       r30, 0xA0(r1)
  mr        r30, r3
  lfs       f3, 0xC(r3)
  lfs       f2, 0x0(r3)
  lfs       f1, 0x10(r3)
  lfs       f0, 0x4(r3)
  fsubs     f31, f3, f2
  lfs       f2, 0x14(r3)
  fsubs     f30, f1, f0
  lfs       f0, 0x8(r3)
  fmuls     f1, f31, f31
  fsubs     f29, f2, f0
  fmuls     f0, f30, f30
  fmuls     f2, f29, f29
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x79BCC
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x7C
  fdivs     f31, f31, f1
  fdivs     f30, f30, f1
  fdivs     f29, f29, f1

.loc_0x7C:
  lfs       f2, 0x0(r31)
  lfs       f0, 0x0(r30)
  fsubs     f0, f2, f0
  stfs      f0, 0x54(r1)
  lfs       f2, 0x4(r31)
  lfs       f0, 0x4(r30)
  lfs       f3, 0x54(r1)
  fsubs     f0, f2, f0
  lfs       f5, 0x8(r31)
  lfs       f4, 0x8(r30)
  fmuls     f2, f31, f3
  fsubs     f3, f5, f4
  fmuls     f0, f30, f0
  fmuls     f3, f29, f3
  fadds     f0, f2, f0
  fadds     f0, f3, f0
  fdivs     f1, f0, f1
  lwz       r0, 0xC4(r1)
  lfd       f31, 0xB8(r1)
  lfd       f30, 0xB0(r1)
  lfd       f29, 0xA8(r1)
  lwz       r31, 0xA4(r1)
  lwz       r30, 0xA0(r1)
  addi      r1, r1, 0xC0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void Tube::getRatioRadius(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80087890
 * Size:	000238
 */
void Tube::getPosGradient(Vector3f &, float, Vector3f &, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x170(r1)
  stfd      f31, 0x168(r1)
  stfd      f30, 0x160(r1)
  stfd      f29, 0x158(r1)
  stfd      f28, 0x150(r1)
  stfd      f27, 0x148(r1)
  stfd      f26, 0x140(r1)
  stfd      f25, 0x138(r1)
  fmr       f25, f1
  stw       r31, 0x134(r1)
  addi      r31, r6, 0
  stw       r30, 0x130(r1)
  addi      r30, r5, 0
  stw       r29, 0x12C(r1)
  addi      r29, r4, 0
  stw       r28, 0x128(r1)
  addi      r28, r3, 0
  addi      r4, r28, 0
  addi      r3, r1, 0xEC
  bl        .loc_0x238
  lfs       f26, 0xEC(r1)
  lfs       f1, 0x0(r29)
  lfs       f27, 0xF0(r1)
  lfs       f0, 0x4(r29)
  fsubs     f31, f1, f26
  lfs       f28, 0xF4(r1)
  fsubs     f30, f0, f27
  lfs       f0, 0x8(r29)
  fmuls     f1, f31, f31
  fsubs     f29, f0, f28
  fmuls     f0, f30, f30
  fmuls     f2, f29, f29
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x79CE0
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0xAC
  fdivs     f31, f31, f1
  fdivs     f30, f30, f1
  fdivs     f29, f29, f1

.loc_0xAC:
  lfs       f4, 0x1C(r28)
  addi      r6, r1, 0x6C
  lfs       f1, -0x75A8(r2)
  addi      r5, r1, 0x68
  fmuls     f0, f29, f4
  lfs       f3, 0x18(r28)
  fsubs     f2, f1, f25
  fmuls     f1, f4, f25
  addi      r4, r1, 0x64
  stfs      f0, 0x6C(r1)
  fmuls     f2, f3, f2
  addi      r3, r1, 0xC8
  lfs       f0, 0x1C(r28)
  fadds     f25, f2, f1
  fmuls     f0, f30, f0
  stfs      f0, 0x68(r1)
  lfs       f0, 0x1C(r28)
  fmuls     f0, f31, f0
  stfs      f0, 0x64(r1)
  bl        -0x5086C
  fmuls     f2, f31, f25
  lfs       f8, 0x14(r28)
  fmuls     f1, f30, f25
  lfs       f7, 0xD0(r1)
  fmuls     f0, f29, f25
  fadds     f2, f26, f2
  lfs       f6, 0x10(r28)
  lfs       f4, 0xC(r28)
  fadds     f1, f27, f1
  lfs       f5, 0xCC(r1)
  stfs      f2, 0x94(r1)
  fadds     f0, f28, f0
  lfs       f3, 0xC8(r1)
  fadds     f5, f6, f5
  lfs       f2, 0x94(r1)
  fadds     f3, f4, f3
  stfs      f2, 0xBC(r1)
  fadds     f2, f8, f7
  stfs      f1, 0xC0(r1)
  stfs      f0, 0xC4(r1)
  lwz       r3, 0xBC(r1)
  lwz       r0, 0xC0(r1)
  stw       r3, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r0, 0xC4(r1)
  stw       r0, 0x8(r30)
  lfs       f0, 0x0(r30)
  fsubs     f0, f3, f0
  stfs      f0, 0x88(r1)
  lfs       f0, 0x88(r1)
  stfs      f0, 0xB0(r1)
  lfs       f0, 0x4(r30)
  fsubs     f0, f5, f0
  stfs      f0, 0xB4(r1)
  lfs       f0, 0x8(r30)
  fsubs     f0, f2, f0
  stfs      f0, 0xB8(r1)
  lwz       r3, 0xB0(r1)
  lwz       r0, 0xB4(r1)
  stw       r3, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0xB8(r1)
  stw       r0, 0x8(r31)
  lfs       f1, 0x0(r31)
  lfs       f0, 0x4(r31)
  lfs       f2, 0x8(r31)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x79E18
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x1FC
  lfs       f0, 0x0(r31)
  fdivs     f0, f0, f1
  stfs      f0, 0x0(r31)
  lfs       f0, 0x4(r31)
  fdivs     f0, f0, f1
  stfs      f0, 0x4(r31)
  lfs       f0, 0x8(r31)
  fdivs     f0, f0, f1
  stfs      f0, 0x8(r31)

.loc_0x1FC:
  lwz       r0, 0x174(r1)
  lfd       f31, 0x168(r1)
  lfd       f30, 0x160(r1)
  lfd       f29, 0x158(r1)
  lfd       f28, 0x150(r1)
  lfd       f27, 0x148(r1)
  lfd       f26, 0x140(r1)
  lfd       f25, 0x138(r1)
  lwz       r31, 0x134(r1)
  lwz       r30, 0x130(r1)
  lwz       r29, 0x12C(r1)
  lwz       r28, 0x128(r1)
  addi      r1, r1, 0x170
  mtlr      r0
  blr       

.loc_0x238:
*/
}

/*
 * --INFO--
 * Address:	80087AC8
 * Size:	0000F8
 */
void Tube::setPos(float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x88(r1)
  stfd      f31, 0x80(r1)
  addi      r0, r1, 0x28
  addi      r6, r1, 0x30
  stfd      f30, 0x78(r1)
  addi      r5, r1, 0x2C
  stfd      f29, 0x70(r1)
  stfd      f28, 0x68(r1)
  fmr       f28, f1
  stw       r31, 0x64(r1)
  addi      r31, r3, 0
  addi      r3, r1, 0x38
  lfs       f30, 0x8(r4)
  lfs       f0, 0x14(r4)
  lfs       f29, 0x0(r4)
  fsubs     f0, f0, f30
  lfs       f31, 0x4(r4)
  stfs      f0, 0x30(r1)
  lfs       f1, 0x10(r4)
  lfs       f0, 0x4(r4)
  fsubs     f0, f1, f0
  stfs      f0, 0x2C(r1)
  lfs       f1, 0xC(r4)
  lfs       f0, 0x0(r4)
  mr        r4, r0
  fsubs     f0, f1, f0
  stfs      f0, 0x28(r1)
  bl        -0x50A20
  lfs       f2, 0x40(r1)
  addi      r6, r1, 0x24
  lfs       f1, 0x3C(r1)
  addi      r5, r1, 0x20
  lfs       f0, 0x38(r1)
  fmuls     f2, f2, f28
  addi      r4, r1, 0x1C
  fmuls     f1, f1, f28
  addi      r3, r1, 0x44
  fmuls     f0, f0, f28
  stfs      f2, 0x24(r1)
  stfs      f1, 0x20(r1)
  stfs      f0, 0x1C(r1)
  bl        -0x50A58
  lfs       f0, 0x44(r1)
  lfs       f1, 0x48(r1)
  fadds     f0, f29, f0
  lfs       f2, 0x4C(r1)
  fadds     f3, f31, f1
  fadds     f1, f30, f2
  stfs      f0, 0x0(r31)
  stfs      f3, 0x4(r31)
  stfs      f1, 0x8(r31)
  lwz       r0, 0x8C(r1)
  lfd       f31, 0x80(r1)
  lfd       f30, 0x78(r1)
  lfd       f29, 0x70(r1)
  lfd       f28, 0x68(r1)
  lwz       r31, 0x64(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void CollPartUpdater::updateCollPart(CollPart *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80087BC0
 * Size:	000124
 */
void CollPart::isStickable()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stw       r31, 0x4C(r1)
  mr        r31, r3
  lbz       r0, 0x51(r3)
  cmplwi    r0, 0
  bne-      .loc_0x28
  li        r3, 0
  b         .loc_0x110

.loc_0x28:
  lbz       r3, 0x5C(r31)
  cmplwi    r3, 0x3
  bne-      .loc_0xB4
  addi      r3, r1, 0x3C
  addi      r4, r31, 0
  bl        0x2E0
  lis       r4, 0x632A
  addi      r3, r1, 0x3C
  addi      r4, r4, 0x2A2A
  li        r5, 0x2A
  bl        -0x43D28
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x7C
  addi      r3, r1, 0x30
  addi      r4, r31, 0
  bl        0x2B8
  addi      r3, r1, 0x24
  addi      r4, r31, 0
  bl        0x270
  li        r3, 0
  b         .loc_0x110

.loc_0x7C:
  addi      r3, r1, 0x18
  addi      r4, r31, 0
  bl        0x298
  lis       r4, 0x732A
  addi      r3, r1, 0x18
  addi      r4, r4, 0x2A2A
  li        r5, 0x2A
  bl        -0x43D70
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0xAC
  li        r3, 0
  b         .loc_0x110

.loc_0xAC:
  li        r3, 0x1
  b         .loc_0x110

.loc_0xB4:
  subi      r0, r3, 0x5
  rlwinm    r0,r0,0,24,31
  cmplwi    r0, 0x1
  li        r0, 0x1
  ble-      .loc_0xCC
  li        r0, 0

.loc_0xCC:
  rlwinm.   r0,r0,0,24,31
  bne-      .loc_0xDC
  cmplwi    r3, 0
  bne-      .loc_0x10C

.loc_0xDC:
  addi      r3, r1, 0xC
  addi      r4, r31, 0
  bl        0x238
  lis       r4, 0x732A
  addi      r3, r1, 0xC
  addi      r4, r4, 0x2A2A
  li        r5, 0x2A
  bl        -0x43DD0
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x10C
  li        r3, 0x1
  b         .loc_0x110

.loc_0x10C:
  li        r3, 0

.loc_0x110:
  lwz       r0, 0x54(r1)
  lwz       r31, 0x4C(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80087CE4
 * Size:	00005C
 */
void CollPart::isClimbable()
{
/*
.loc_0x0:
  mflr      r0
  mr        r4, r3
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  lbz       r0, 0x5C(r3)
  cmplwi    r0, 0x3
  bne-      .loc_0x48
  addi      r3, r1, 0xC
  bl        0x1D8
  lis       r4, 0x632A
  addi      r3, r1, 0xC
  addi      r4, r4, 0x2A2A
  li        r5, 0x2A
  bl        -0x43E30
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x48
  li        r3, 0x1
  b         .loc_0x4C

.loc_0x48:
  li        r3, 0

.loc_0x4C:
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void CollPart::isDamagable()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80087D40
 * Size:	000050
 */
void CollPart::isBouncy()
{
/*
.loc_0x0:
  mflr      r0
  addi      r4, r3, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  addi      r3, r1, 0xC
  bl        0x188
  lis       r4, 0x622A
  addi      r3, r1, 0xC
  addi      r4, r4, 0x2A2A
  li        r5, 0x2A
  bl        -0x43E80
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x3C
  li        r3, 0x1
  b         .loc_0x40

.loc_0x3C:
  li        r3, 0

.loc_0x40:
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80087D90
 * Size:	000034
 */
void CollPart::getChildCount()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x58(r3)
  cmplwi    r3, 0
  beq-      .loc_0x20
  bl        -0x47728
  b         .loc_0x24

.loc_0x20:
  li        r3, -0x1

.loc_0x24:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80087DC4
 * Size:	000028
 */
void CollPart::getChild()
{
/*
.loc_0x0:
  lha       r0, 0x54(r3)
  cmpwi     r0, -0x1
  beq-      .loc_0x20
  lwz       r3, 0x60(r3)
  mulli     r0, r0, 0x68
  lwz       r3, 0x4(r3)
  add       r3, r3, r0
  blr       

.loc_0x20:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	80087DEC
 * Size:	00005C
 */
void CollPart::getChildAt(int)
{
/*
.loc_0x0:
  cmpwi     r4, 0
  lha       r0, 0x54(r3)
  mtctr     r4
  ble-      .loc_0x38

.loc_0x10:
  cmpwi     r0, -0x1
  bne-      .loc_0x20
  li        r3, 0
  blr       

.loc_0x20:
  mulli     r4, r0, 0x68
  lwz       r5, 0x60(r3)
  lwz       r5, 0x4(r5)
  addi      r0, r4, 0x52
  lhax      r0, r5, r0
  bdnz+     .loc_0x10

.loc_0x38:
  cmpwi     r0, -0x1
  bne-      .loc_0x48
  li        r3, 0
  blr       

.loc_0x48:
  lwz       r3, 0x60(r3)
  mulli     r0, r0, 0x68
  lwz       r3, 0x4(r3)
  add       r3, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void CollPart::getNext()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80087E48
 * Size:	00003C
 */
void CollPart::CollPart()
{
/*
.loc_0x0:
  lfs       f0, -0x75C0(r2)
  li        r5, 0x1
  li        r4, -0x1
  stfs      f0, 0xC(r3)
  li        r0, 0
  stfs      f0, 0x8(r3)
  stfs      f0, 0x4(r3)
  stb       r5, 0x50(r3)
  sth       r4, 0x54(r3)
  sth       r4, 0x52(r3)
  stw       r0, 0x58(r3)
  stw       r0, 0x60(r3)
  stw       r0, 0x64(r3)
  stb       r5, 0x51(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80087E84
 * Size:	00001C
 */
void CollPart::getTypeString()
{
/*
.loc_0x0:
  lbz       r4, 0x5C(r3)
  lis       r3, 0x802B
  subi      r0, r3, 0xFAC
  rlwinm    r3,r4,2,0,29
  add       r3, r0, r3
  lwz       r3, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80087EA0
 * Size:	00003C
 */
void CollPart::getID()
{
/*
.loc_0x0:
  mflr      r0
  addi      r6, r3, 0
  stw       r0, 0x4(r1)
  addi      r3, r6, 0x4
  li        r5, 0x5
  stwu      r1, -0x8(r1)
  lwz       r4, 0x58(r4)
  lwzu      r0, 0x14(r4)
  stw       r0, 0x0(r6)
  addi      r4, r4, 0x4
  bl        0x18CAFC
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80087EDC
 * Size:	00003C
 */
void CollPart::getCode()
{
/*
.loc_0x0:
  mflr      r0
  addi      r6, r3, 0
  stw       r0, 0x4(r1)
  addi      r3, r6, 0x4
  li        r5, 0x5
  stwu      r1, -0x8(r1)
  lwz       r4, 0x58(r4)
  lwzu      r0, 0x20(r4)
  stw       r0, 0x0(r6)
  addi      r4, r4, 0x4
  bl        0x18CAC0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80087F18
 * Size:	000164
 */
void CollPart::getMatrix()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xA0(r1)
  stw       r31, 0x9C(r1)
  mr        r31, r4
  stw       r30, 0x98(r1)
  addi      r30, r3, 0
  lwz       r6, 0x10(r4)
  lis       r4, 0x803D
  lwz       r5, 0x14(r31)
  addi      r0, r4, 0x15B0
  mr        r3, r0
  stw       r6, 0x58(r1)
  addi      r4, r1, 0x58
  stw       r5, 0x5C(r1)
  addi      r5, r1, 0x18
  lwz       r6, 0x18(r31)
  lwz       r0, 0x1C(r31)
  stw       r6, 0x60(r1)
  stw       r0, 0x64(r1)
  lwz       r6, 0x20(r31)
  lwz       r0, 0x24(r31)
  stw       r6, 0x68(r1)
  stw       r0, 0x6C(r1)
  lwz       r6, 0x28(r31)
  lwz       r0, 0x2C(r31)
  stw       r6, 0x70(r1)
  stw       r0, 0x74(r1)
  lwz       r6, 0x30(r31)
  lwz       r0, 0x34(r31)
  stw       r6, 0x78(r1)
  stw       r0, 0x7C(r1)
  lwz       r6, 0x38(r31)
  lwz       r0, 0x3C(r31)
  stw       r6, 0x80(r1)
  stw       r0, 0x84(r1)
  lwz       r6, 0x40(r31)
  lwz       r0, 0x44(r31)
  stw       r6, 0x88(r1)
  stw       r0, 0x8C(r1)
  lwz       r6, 0x48(r31)
  lwz       r0, 0x4C(r31)
  stw       r6, 0x90(r1)
  stw       r0, 0x94(r1)
  bl        -0x49EF4
  lfs       f0, 0x4(r31)
  stfs      f0, 0x24(r1)
  lfs       f0, 0x8(r31)
  stfs      f0, 0x34(r1)
  lfs       f0, 0xC(r31)
  stfs      f0, 0x44(r1)
  lwz       r3, 0x18(r1)
  lwz       r0, 0x1C(r1)
  stw       r3, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r3, 0x20(r1)
  lwz       r0, 0x24(r1)
  stw       r3, 0x8(r30)
  stw       r0, 0xC(r30)
  lwz       r3, 0x28(r1)
  lwz       r0, 0x2C(r1)
  stw       r3, 0x10(r30)
  stw       r0, 0x14(r30)
  lwz       r3, 0x30(r1)
  lwz       r0, 0x34(r1)
  stw       r3, 0x18(r30)
  stw       r0, 0x1C(r30)
  lwz       r3, 0x38(r1)
  lwz       r0, 0x3C(r1)
  stw       r3, 0x20(r30)
  stw       r0, 0x24(r30)
  lwz       r3, 0x40(r1)
  lwz       r0, 0x44(r1)
  stw       r3, 0x28(r30)
  stw       r0, 0x2C(r30)
  lwz       r3, 0x48(r1)
  lwz       r0, 0x4C(r1)
  stw       r3, 0x30(r30)
  stw       r0, 0x34(r30)
  lwz       r3, 0x50(r1)
  lwz       r0, 0x54(r1)
  stw       r3, 0x38(r30)
  stw       r0, 0x3C(r30)
  lwz       r0, 0xA4(r1)
  lwz       r31, 0x9C(r1)
  lwz       r30, 0x98(r1)
  addi      r1, r1, 0xA0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8008807C
 * Size:	0004A4
 */
void CollPart::update(Graphics &, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  addi      r31, r5, 0
  stw       r30, 0x40(r1)
  addi      r30, r4, 0
  stw       r29, 0x3C(r1)
  mr        r29, r3
  stw       r28, 0x38(r1)
  lbz       r0, 0x50(r3)
  cmplwi    r0, 0
  beq-      .loc_0x484
  lbz       r0, 0x5C(r29)
  cmplwi    r0, 0x3
  beq-      .loc_0x484
  lwz       r28, 0x64(r29)
  cmplwi    r28, 0
  beq-      .loc_0x98
  lwz       r12, 0x0(r28)
  mr        r4, r28
  addi      r3, r1, 0x14
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x14(r1)
  mr        r3, r28
  lwz       r0, 0x18(r1)
  stw       r4, 0x4(r29)
  stw       r0, 0x8(r29)
  lwz       r0, 0x1C(r1)
  stw       r0, 0xC(r29)
  lwz       r12, 0x0(r28)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x0(r29)
  b         .loc_0x1F8

.loc_0x98:
  lwz       r5, 0x58(r29)
  addi      r4, r30, 0
  addi      r6, r29, 0x4
  lwz       r3, 0x34(r5)
  lwz       r0, 0x38(r5)
  stw       r3, 0x4(r29)
  stw       r0, 0x8(r29)
  lwz       r0, 0x3C(r5)
  stw       r0, 0xC(r29)
  lwz       r5, 0x58(r29)
  lwz       r3, 0x44(r5)
  lwz       r5, 0x30(r5)
  bl        -0x52880
  lwz       r5, 0x58(r29)
  lis       r3, 0x803D
  addi      r4, r3, 0x15B0
  lfs       f0, 0x40(r5)
  fmuls     f0, f1, f0
  stfs      f0, 0x0(r29)
  lwz       r5, 0x2E4(r30)
  lwz       r3, 0x220(r5)
  lwz       r0, 0x224(r5)
  stw       r3, 0x0(r4)
  stw       r0, 0x4(r4)
  lwz       r3, 0x228(r5)
  lwz       r0, 0x22C(r5)
  stw       r3, 0x8(r4)
  stw       r0, 0xC(r4)
  lwz       r3, 0x230(r5)
  lwz       r0, 0x234(r5)
  stw       r3, 0x10(r4)
  stw       r0, 0x14(r4)
  lwz       r3, 0x238(r5)
  lwz       r0, 0x23C(r5)
  stw       r3, 0x18(r4)
  stw       r0, 0x1C(r4)
  lwz       r3, 0x240(r5)
  lwz       r0, 0x244(r5)
  stw       r3, 0x20(r4)
  stw       r0, 0x24(r4)
  lwz       r3, 0x248(r5)
  lwz       r0, 0x24C(r5)
  stw       r3, 0x28(r4)
  stw       r0, 0x2C(r4)
  lwz       r3, 0x250(r5)
  lwz       r0, 0x254(r5)
  stw       r3, 0x30(r4)
  stw       r0, 0x34(r4)
  lwz       r3, 0x258(r5)
  lwz       r0, 0x25C(r5)
  stw       r3, 0x38(r4)
  stw       r0, 0x3C(r4)
  lwz       r4, 0x58(r29)
  lwz       r3, 0x44(r4)
  lwz       r4, 0x30(r4)
  bl        -0x53208
  lwz       r4, 0x0(r3)
  lwz       r0, 0x4(r3)
  stw       r4, 0x10(r29)
  stw       r0, 0x14(r29)
  lwz       r4, 0x8(r3)
  lwz       r0, 0xC(r3)
  stw       r4, 0x18(r29)
  stw       r0, 0x1C(r29)
  lwz       r4, 0x10(r3)
  lwz       r0, 0x14(r3)
  stw       r4, 0x20(r29)
  stw       r0, 0x24(r29)
  lwz       r4, 0x18(r3)
  lwz       r0, 0x1C(r3)
  stw       r4, 0x28(r29)
  stw       r0, 0x2C(r29)
  lwz       r4, 0x20(r3)
  lwz       r0, 0x24(r3)
  stw       r4, 0x30(r29)
  stw       r0, 0x34(r29)
  lwz       r4, 0x28(r3)
  lwz       r0, 0x2C(r3)
  stw       r4, 0x38(r29)
  stw       r0, 0x3C(r29)
  lwz       r4, 0x30(r3)
  lwz       r0, 0x34(r3)
  stw       r4, 0x40(r29)
  stw       r0, 0x44(r29)
  lwz       r4, 0x38(r3)
  lwz       r0, 0x3C(r3)
  stw       r4, 0x48(r29)
  stw       r0, 0x4C(r29)

.loc_0x1F8:
  rlwinm.   r0,r31,0,24,31
  beq-      .loc_0x484
  mr        r3, r30
  lwz       r12, 0x3B4(r30)
  li        r4, 0
  li        r5, 0
  lwz       r12, 0xCC(r12)
  mtlr      r12
  blrl      
  mr        r3, r30
  lwz       r12, 0x3B4(r30)
  li        r4, 0
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x5C(r29)
  addi      r31, r3, 0
  cmpwi     r0, 0x3
  beq-      .loc_0x35C
  bge-      .loc_0x264
  cmpwi     r0, 0x1
  beq-      .loc_0x278
  bge-      .loc_0x320
  cmpwi     r0, 0
  bge-      .loc_0x2B0
  b         .loc_0x394

.loc_0x264:
  cmpwi     r0, 0x7
  bge-      .loc_0x394
  cmpwi     r0, 0x5
  bge-      .loc_0x2E8
  b         .loc_0x394

.loc_0x278:
  li        r6, 0xFF
  stb       r6, 0x30(r1)
  li        r0, 0xB4
  addi      r4, r1, 0x30
  stb       r0, 0x31(r1)
  mr        r3, r30
  li        r5, 0x1
  stb       r0, 0x32(r1)
  stb       r6, 0x33(r1)
  lwz       r12, 0x3B4(r30)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x394

.loc_0x2B0:
  li        r6, 0xFF
  stb       r6, 0x2C(r1)
  li        r0, 0
  addi      r4, r1, 0x2C
  stb       r0, 0x2D(r1)
  mr        r3, r30
  li        r5, 0x1
  stb       r0, 0x2E(r1)
  stb       r6, 0x2F(r1)
  lwz       r12, 0x3B4(r30)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x394

.loc_0x2E8:
  li        r6, 0xFF
  stb       r6, 0x28(r1)
  li        r0, 0
  addi      r4, r1, 0x28
  stb       r0, 0x29(r1)
  mr        r3, r30
  li        r5, 0x1
  stb       r6, 0x2A(r1)
  stb       r6, 0x2B(r1)
  lwz       r12, 0x3B4(r30)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x394

.loc_0x320:
  li        r6, 0xFF
  stb       r6, 0x24(r1)
  li        r0, 0xD7
  addi      r4, r1, 0x24
  stb       r0, 0x25(r1)
  li        r0, 0x14
  addi      r3, r30, 0
  stb       r0, 0x26(r1)
  li        r5, 0x1
  stb       r6, 0x27(r1)
  lwz       r12, 0x3B4(r30)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x394

.loc_0x35C:
  li        r0, 0x32
  stb       r0, 0x20(r1)
  li        r0, 0x96
  addi      r4, r1, 0x20
  stb       r0, 0x21(r1)
  li        r0, 0xFF
  addi      r3, r30, 0
  stb       r0, 0x22(r1)
  li        r5, 0x1
  stb       r0, 0x23(r1)
  lwz       r12, 0x3B4(r30)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      

.loc_0x394:
  mr        r3, r30
  lwz       r4, 0x2E4(r30)
  lwz       r12, 0x3B4(r30)
  li        r5, 0
  addi      r4, r4, 0x1E0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x5C(r29)
  cmplwi    r0, 0x5
  bne-      .loc_0x404
  lha       r0, 0x52(r29)
  cmpwi     r0, -0x1
  beq-      .loc_0x3E0
  lwz       r3, 0x60(r29)
  mulli     r0, r0, 0x68
  lwz       r3, 0x4(r3)
  add       r5, r3, r0
  b         .loc_0x3E4

.loc_0x3E0:
  li        r5, 0

.loc_0x3E4:
  lwz       r6, 0x2E4(r30)
  mr        r3, r30
  lfs       f1, 0x0(r29)
  addi      r4, r29, 0x4
  addi      r5, r5, 0x4
  addi      r6, r6, 0x1E0
  bl        -0x5F2C4
  b         .loc_0x468

.loc_0x404:
  cmplwi    r0, 0x6
  bne-      .loc_0x450
  lha       r0, 0x54(r29)
  cmpwi     r0, -0x1
  beq-      .loc_0x42C
  lwz       r3, 0x60(r29)
  mulli     r0, r0, 0x68
  lwz       r3, 0x4(r3)
  add       r5, r3, r0
  b         .loc_0x430

.loc_0x42C:
  li        r5, 0

.loc_0x430:
  lwz       r6, 0x2E4(r30)
  mr        r3, r30
  lfs       f1, 0x0(r29)
  addi      r4, r29, 0x4
  addi      r5, r5, 0x4
  addi      r6, r6, 0x1E0
  bl        -0x5F310
  b         .loc_0x468

.loc_0x450:
  lwz       r5, 0x2E4(r30)
  mr        r3, r30
  lfs       f1, 0x0(r29)
  addi      r4, r29, 0x4
  addi      r5, r5, 0x1E0
  bl        -0x5F070

.loc_0x468:
  mr        r3, r30
  lwz       r12, 0x3B4(r30)
  addi      r4, r31, 0
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      

.loc_0x484:
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  lwz       r30, 0x40(r1)
  lwz       r29, 0x3C(r1)
  lwz       r28, 0x38(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A4
 */
void CollPart::collide(Creature *, Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000158
 */
void CollPart::collide(Vector3f &, float, Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80088520
 * Size:	00066C
 */
void CollPart::collide(CollPart *, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0x1
  stwu      r1, -0x1D8(r1)
  stw       r31, 0x1D4(r1)
  addi      r31, r5, 0
  stw       r30, 0x1D0(r1)
  addi      r30, r4, 0
  stw       r29, 0x1CC(r1)
  mr        r29, r3
  lbz       r3, 0x5C(r3)
  cmplwi    r3, 0x1
  beq-      .loc_0x40
  cmplwi    r3, 0
  beq-      .loc_0x40
  li        r0, 0

.loc_0x40:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x17C
  lbz       r4, 0x5C(r30)
  li        r0, 0x1
  cmplwi    r4, 0x1
  beq-      .loc_0x64
  cmplwi    r4, 0
  beq-      .loc_0x64
  li        r0, 0

.loc_0x64:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x17C
  lfs       f1, 0x4(r30)
  lfs       f0, 0x4(r29)
  lfs       f3, 0x8(r30)
  lfs       f2, 0x8(r29)
  fsubs     f0, f1, f0
  lfs       f4, 0xC(r30)
  lfs       f1, 0xC(r29)
  fsubs     f2, f3, f2
  stfs      f0, 0x1BC(r1)
  fsubs     f0, f4, f1
  stfs      f2, 0x1C0(r1)
  stfs      f0, 0x1C4(r1)
  lfs       f1, 0x1BC(r1)
  lfs       f0, 0x1C0(r1)
  lfs       f2, 0x1C4(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x7A99C
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0xF0
  lfs       f0, 0x1BC(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x1BC(r1)
  lfs       f0, 0x1C0(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x1C0(r1)
  lfs       f0, 0x1C4(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x1C4(r1)

.loc_0xF0:
  lfs       f2, 0x0(r29)
  lfs       f0, 0x0(r30)
  fadds     f0, f2, f0
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0x64C
  lwz       r4, 0x1BC(r1)
  li        r3, 0x1
  lwz       r0, 0x1C0(r1)
  stw       r4, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0x1C4(r1)
  stw       r0, 0x8(r31)
  lfs       f3, 0x0(r29)
  lfs       f2, 0x0(r30)
  lfs       f0, 0x0(r31)
  fadds     f2, f3, f2
  fsubs     f1, f2, f1
  fmuls     f0, f0, f1
  stfs      f0, 0x74(r1)
  lfs       f0, 0x74(r1)
  stfs      f0, 0xA0(r1)
  lfs       f0, 0x4(r31)
  fmuls     f0, f0, f1
  stfs      f0, 0xA4(r1)
  lfs       f0, 0x8(r31)
  fmuls     f0, f0, f1
  stfs      f0, 0xA8(r1)
  lwz       r4, 0xA0(r1)
  lwz       r0, 0xA4(r1)
  stw       r4, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0xA8(r1)
  stw       r0, 0x8(r31)
  b         .loc_0x650

.loc_0x17C:
  cmplwi    r3, 0x4
  bne-      .loc_0x270
  lbz       r4, 0x5C(r30)
  li        r0, 0x1
  cmplwi    r4, 0x1
  beq-      .loc_0x1A0
  cmplwi    r4, 0
  beq-      .loc_0x1A0
  li        r0, 0

.loc_0x1A0:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x270
  lha       r0, 0x54(r29)
  cmpwi     r0, -0x1
  beq-      .loc_0x1C8
  lwz       r3, 0x60(r29)
  mulli     r0, r0, 0x68
  lwz       r3, 0x4(r3)
  add       r7, r3, r0
  b         .loc_0x1CC

.loc_0x1C8:
  li        r7, 0

.loc_0x1CC:
  lfs       f2, 0x0(r29)
  addi      r3, r1, 0x198
  lfs       f1, 0x4(r29)
  addi      r4, r1, 0x188
  lfs       f0, -0x75C0(r2)
  stfs      f1, 0x198(r1)
  addi      r5, r1, 0x17C
  addi      r6, r1, 0x178
  lfs       f1, 0x8(r29)
  stfs      f1, 0x19C(r1)
  lfs       f1, 0xC(r29)
  stfs      f1, 0x1A0(r1)
  lfs       f1, 0x4(r7)
  stfs      f1, 0x1A4(r1)
  lfs       f1, 0x8(r7)
  stfs      f1, 0x1A8(r1)
  lfs       f1, 0xC(r7)
  stfs      f1, 0x1AC(r1)
  stfs      f2, 0x1B0(r1)
  lfs       f2, 0x0(r30)
  lfs       f1, 0x4(r30)
  stfs      f1, 0x188(r1)
  lfs       f1, 0x8(r30)
  stfs      f1, 0x18C(r1)
  lfs       f1, 0xC(r30)
  stfs      f0, 0x184(r1)
  stfs      f1, 0x190(r1)
  stfs      f0, 0x180(r1)
  stfs      f2, 0x194(r1)
  stfs      f0, 0x17C(r1)
  bl        -0x17C4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x64C
  lwz       r4, 0x17C(r1)
  li        r3, 0x1
  lwz       r0, 0x180(r1)
  stw       r4, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0x184(r1)
  stw       r0, 0x8(r31)
  b         .loc_0x650

.loc_0x270:
  cmplwi    r3, 0x1
  li        r0, 0x1
  ble-      .loc_0x280
  li        r0, 0

.loc_0x280:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x38C
  lbz       r0, 0x5C(r30)
  cmplwi    r0, 0x4
  bne-      .loc_0x38C
  lha       r0, 0x54(r30)
  cmpwi     r0, -0x1
  beq-      .loc_0x2B4
  lwz       r3, 0x60(r30)
  mulli     r0, r0, 0x68
  lwz       r3, 0x4(r3)
  add       r7, r3, r0
  b         .loc_0x2B8

.loc_0x2B4:
  li        r7, 0

.loc_0x2B8:
  lfs       f2, 0x0(r30)
  addi      r3, r1, 0x158
  lfs       f1, 0x4(r30)
  addi      r4, r1, 0x148
  lfs       f0, -0x75C0(r2)
  stfs      f1, 0x158(r1)
  addi      r5, r1, 0x13C
  addi      r6, r1, 0x138
  lfs       f1, 0x8(r30)
  stfs      f1, 0x15C(r1)
  lfs       f1, 0xC(r30)
  stfs      f1, 0x160(r1)
  lfs       f1, 0x4(r7)
  stfs      f1, 0x164(r1)
  lfs       f1, 0x8(r7)
  stfs      f1, 0x168(r1)
  lfs       f1, 0xC(r7)
  stfs      f1, 0x16C(r1)
  stfs      f2, 0x170(r1)
  lfs       f2, 0x0(r29)
  lfs       f1, 0x4(r29)
  stfs      f1, 0x148(r1)
  lfs       f1, 0x8(r29)
  stfs      f1, 0x14C(r1)
  lfs       f1, 0xC(r29)
  stfs      f1, 0x150(r1)
  stfs      f2, 0x154(r1)
  stfs      f0, 0x144(r1)
  stfs      f0, 0x140(r1)
  stfs      f0, 0x13C(r1)
  bl        -0x18B0
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x64C
  lfs       f0, 0x13C(r1)
  li        r3, 0x1
  lfs       f1, -0x5E50(r13)
  fmuls     f0, f0, f1
  stfs      f0, 0x68(r1)
  lfs       f0, 0x68(r1)
  stfs      f0, 0x94(r1)
  lfs       f0, 0x140(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x98(r1)
  lfs       f0, 0x144(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x9C(r1)
  lwz       r4, 0x94(r1)
  lwz       r0, 0x98(r1)
  stw       r4, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0x9C(r1)
  stw       r0, 0x8(r31)
  b         .loc_0x650

.loc_0x38C:
  subi      r0, r3, 0x5
  rlwinm    r0,r0,0,24,31
  cmplwi    r0, 0x1
  li        r0, 0x1
  ble-      .loc_0x3A4
  li        r0, 0

.loc_0x3A4:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x4D8
  lbz       r4, 0x5C(r30)
  li        r0, 0x1
  cmplwi    r4, 0x1
  beq-      .loc_0x3C8
  cmplwi    r4, 0
  beq-      .loc_0x3C8
  li        r0, 0

.loc_0x3C8:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x4D8
  cmplwi    r3, 0x5
  bne-      .loc_0x404
  lha       r0, 0x52(r29)
  cmpwi     r0, -0x1
  beq-      .loc_0x3F8
  lwz       r3, 0x60(r29)
  mulli     r0, r0, 0x68
  lwz       r3, 0x4(r3)
  add       r0, r3, r0
  b         .loc_0x3FC

.loc_0x3F8:
  li        r0, 0

.loc_0x3FC:
  mr        r7, r0
  b         .loc_0x42C

.loc_0x404:
  lha       r0, 0x54(r29)
  cmpwi     r0, -0x1
  beq-      .loc_0x424
  lwz       r3, 0x60(r29)
  mulli     r0, r0, 0x68
  lwz       r3, 0x4(r3)
  add       r0, r3, r0
  b         .loc_0x428

.loc_0x424:
  li        r0, 0

.loc_0x428:
  mr        r7, r0

.loc_0x42C:
  lfs       f3, 0x0(r7)
  addi      r3, r1, 0x118
  lfs       f2, 0x0(r29)
  addi      r4, r1, 0x108
  lfs       f1, 0x4(r29)
  lfs       f0, -0x75C0(r2)
  addi      r5, r1, 0xFC
  stfs      f1, 0x118(r1)
  addi      r6, r1, 0xF8
  lfs       f1, 0x8(r29)
  stfs      f1, 0x11C(r1)
  lfs       f1, 0xC(r29)
  stfs      f1, 0x120(r1)
  lfs       f1, 0x4(r7)
  stfs      f1, 0x124(r1)
  lfs       f1, 0x8(r7)
  stfs      f1, 0x128(r1)
  lfs       f1, 0xC(r7)
  stfs      f1, 0x12C(r1)
  stfs      f2, 0x130(r1)
  stfs      f3, 0x134(r1)
  lfs       f2, 0x0(r30)
  lfs       f1, 0x4(r30)
  stfs      f1, 0x108(r1)
  lfs       f1, 0x8(r30)
  stfs      f1, 0x10C(r1)
  lfs       f1, 0xC(r30)
  stfs      f0, 0x104(r1)
  stfs      f1, 0x110(r1)
  stfs      f0, 0x100(r1)
  stfs      f2, 0x114(r1)
  stfs      f0, 0xFC(r1)
  bl        -0x1640
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x64C
  lwz       r4, 0xFC(r1)
  li        r3, 0x1
  lwz       r0, 0x100(r1)
  stw       r4, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0x104(r1)
  stw       r0, 0x8(r31)
  b         .loc_0x650

.loc_0x4D8:
  cmplwi    r3, 0x1
  li        r0, 0x1
  ble-      .loc_0x4E8
  li        r0, 0

.loc_0x4E8:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x64C
  lbz       r3, 0x5C(r30)
  li        r0, 0x1
  cmplwi    r3, 0x5
  beq-      .loc_0x50C
  cmplwi    r3, 0x6
  beq-      .loc_0x50C
  li        r0, 0

.loc_0x50C:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x64C
  cmplwi    r3, 0x5
  bne-      .loc_0x548
  lha       r0, 0x52(r30)
  cmpwi     r0, -0x1
  beq-      .loc_0x53C
  lwz       r3, 0x60(r30)
  mulli     r0, r0, 0x68
  lwz       r3, 0x4(r3)
  add       r0, r3, r0
  b         .loc_0x540

.loc_0x53C:
  li        r0, 0

.loc_0x540:
  mr        r7, r0
  b         .loc_0x570

.loc_0x548:
  lha       r0, 0x54(r30)
  cmpwi     r0, -0x1
  beq-      .loc_0x568
  lwz       r3, 0x60(r30)
  mulli     r0, r0, 0x68
  lwz       r3, 0x4(r3)
  add       r0, r3, r0
  b         .loc_0x56C

.loc_0x568:
  li        r0, 0

.loc_0x56C:
  mr        r7, r0

.loc_0x570:
  lfs       f3, 0x0(r7)
  addi      r3, r1, 0xD8
  lfs       f2, 0x0(r30)
  addi      r4, r1, 0xC8
  lfs       f1, 0x4(r30)
  lfs       f0, -0x75C0(r2)
  addi      r5, r1, 0xBC
  stfs      f1, 0xD8(r1)
  addi      r6, r1, 0xB8
  lfs       f1, 0x8(r30)
  stfs      f1, 0xDC(r1)
  lfs       f1, 0xC(r30)
  stfs      f1, 0xE0(r1)
  lfs       f1, 0x4(r7)
  stfs      f1, 0xE4(r1)
  lfs       f1, 0x8(r7)
  stfs      f1, 0xE8(r1)
  lfs       f1, 0xC(r7)
  stfs      f1, 0xEC(r1)
  stfs      f2, 0xF0(r1)
  stfs      f3, 0xF4(r1)
  lfs       f2, 0x0(r29)
  lfs       f1, 0x4(r29)
  stfs      f1, 0xC8(r1)
  lfs       f1, 0x8(r29)
  stfs      f1, 0xCC(r1)
  lfs       f1, 0xC(r29)
  stfs      f1, 0xD0(r1)
  stfs      f2, 0xD4(r1)
  stfs      f0, 0xC4(r1)
  stfs      f0, 0xC0(r1)
  stfs      f0, 0xBC(r1)
  bl        -0x1784
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x64C
  lfs       f0, 0xBC(r1)
  li        r3, 0x1
  lfs       f1, -0x5E4C(r13)
  fmuls     f0, f0, f1
  stfs      f0, 0x5C(r1)
  lfs       f0, 0x5C(r1)
  stfs      f0, 0x88(r1)
  lfs       f0, 0xC0(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x8C(r1)
  lfs       f0, 0xC4(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x90(r1)
  lwz       r4, 0x88(r1)
  lwz       r0, 0x8C(r1)
  stw       r4, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0x90(r1)
  stw       r0, 0x8(r31)
  b         .loc_0x650

.loc_0x64C:
  li        r3, 0

.loc_0x650:
  lwz       r0, 0x1DC(r1)
  lwz       r31, 0x1D4(r1)
  lwz       r30, 0x1D0(r1)
  lwz       r29, 0x1CC(r1)
  addi      r1, r1, 0x1D8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80088B8C
 * Size:	0000A4
 */
void CollPart::makeTube(Tube &)
{
/*
.loc_0x0:
  lbz       r0, 0x5C(r3)
  cmplwi    r0, 0x5
  bne-      .loc_0x38
  lha       r0, 0x52(r3)
  cmpwi     r0, -0x1
  beq-      .loc_0x2C
  lwz       r5, 0x60(r3)
  mulli     r0, r0, 0x68
  lwz       r5, 0x4(r5)
  add       r0, r5, r0
  b         .loc_0x30

.loc_0x2C:
  li        r0, 0

.loc_0x30:
  mr        r6, r0
  b         .loc_0x60

.loc_0x38:
  lha       r0, 0x54(r3)
  cmpwi     r0, -0x1
  beq-      .loc_0x58
  lwz       r5, 0x60(r3)
  mulli     r0, r0, 0x68
  lwz       r5, 0x4(r5)
  add       r0, r5, r0
  b         .loc_0x5C

.loc_0x58:
  li        r0, 0

.loc_0x5C:
  mr        r6, r0

.loc_0x60:
  lwz       r5, 0x4(r3)
  lwz       r0, 0x8(r3)
  stw       r5, 0x0(r4)
  stw       r0, 0x4(r4)
  lwz       r0, 0xC(r3)
  stw       r0, 0x8(r4)
  lfs       f0, 0x0(r3)
  stfs      f0, 0x18(r4)
  lwz       r3, 0x4(r6)
  lwz       r0, 0x8(r6)
  stw       r3, 0xC(r4)
  stw       r0, 0x10(r4)
  lwz       r0, 0xC(r6)
  stw       r0, 0x14(r4)
  lfs       f0, 0x0(r6)
  stfs      f0, 0x1C(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void CollPart::makeSphere(Sphere &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CollPart::makeCylinder(Cylinder &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void CollPart::samePlatShape(Shape *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80088C30
 * Size:	0000A0
 */
void CollInfo::CollInfo(int)
{
/*
.loc_0x0:
  mflr      r0
  cmpwi     r4, 0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  addi      r30, r3, 0
  stw       r0, 0x10(r3)
  sth       r0, 0xC(r3)
  bne-      .loc_0x40
  li        r0, 0xA
  sth       r0, 0xE(r30)
  li        r0, 0x1
  stb       r0, 0x0(r30)
  b         .loc_0x84

.loc_0x40:
  sth       r4, 0xE(r30)
  stb       r0, 0x0(r30)
  lhz       r31, 0xE(r30)
  mulli     r3, r31, 0x68
  addi      r3, r3, 0x8
  bl        -0x41C80
  lis       r4, 0x8008
  addi      r4, r4, 0x7E48
  addi      r7, r31, 0
  li        r5, 0
  li        r6, 0x68
  bl        0x18BF8C
  stw       r3, 0x4(r30)
  lhz       r0, 0xE(r30)
  rlwinm    r3,r0,2,0,29
  bl        -0x41CA8
  stw       r3, 0x8(r30)

.loc_0x84:
  mr        r3, r30
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80088CD0
 * Size:	000034
 */
void CollInfo::enableStick()
{
/*
.loc_0x0:
  li        r7, 0
  li        r6, 0
  li        r5, 0x1
  b         .loc_0x24

.loc_0x10:
  lwz       r4, 0x4(r3)
  addi      r0, r6, 0x51
  addi      r7, r7, 0x1
  stbx      r5, r4, r0
  addi      r6, r6, 0x68

.loc_0x24:
  lhz       r0, 0xC(r3)
  cmpw      r7, r0
  blt+      .loc_0x10
  blr
*/
}

/*
 * --INFO--
 * Address:	80088D04
 * Size:	000034
 */
void CollInfo::disableStick()
{
/*
.loc_0x0:
  li        r6, 0
  addi      r5, r6, 0
  li        r7, 0
  b         .loc_0x24

.loc_0x10:
  lwz       r4, 0x4(r3)
  addi      r0, r6, 0x51
  addi      r7, r7, 0x1
  stbx      r5, r4, r0
  addi      r6, r6, 0x68

.loc_0x24:
  lhz       r0, 0xC(r3)
  cmpw      r7, r0
  blt+      .loc_0x10
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void CollInfo::startUpdate(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A8
 */
void CollInfo::startUpdateRec(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void CollInfo::stopUpdate(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A8
 */
void CollInfo::stopUpdateRec(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80088D38
 * Size:	0001C0
 */
void CollInfo::checkCollisionSpecial(Vector3f &, float, CndCollPart *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xC0(r1)
  stfd      f31, 0xB8(r1)
  stfd      f30, 0xB0(r1)
  fmr       f30, f1
  stmw      r23, 0x8C(r1)
  mr        r24, r3
  addi      r25, r4, 0
  addi      r26, r5, 0
  addi      r31, r1, 0x34
  addi      r30, r1, 0x30
  addi      r29, r1, 0x2C
  li        r27, 0
  li        r28, 0
  lfs       f31, -0x75C0(r2)
  stfs      f31, 0x80(r1)
  stfs      f31, 0x7C(r1)
  b         .loc_0x194

.loc_0x4C:
  lwz       r0, 0x4(r24)
  add       r3, r0, r28
  lbz       r0, 0x5C(r3)
  addi      r23, r3, 0
  cmplwi    r0, 0x2
  bne-      .loc_0x18C
  cmplwi    r26, 0
  beq-      .loc_0x8C
  mr        r3, r26
  lwz       r12, 0x0(r26)
  mr        r4, r23
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x18C

.loc_0x8C:
  lbz       r0, 0x5C(r23)
  cmplwi    r0, 0x4
  beq-      .loc_0x178
  lfs       f1, 0x8(r25)
  mr        r4, r29
  lfs       f0, 0xC(r23)
  addi      r5, r30, 0
  addi      r6, r31, 0
  fsubs     f0, f1, f0
  addi      r3, r1, 0x5C
  stfs      f0, 0x34(r1)
  lfs       f1, 0x4(r25)
  lfs       f0, 0x8(r23)
  fsubs     f0, f1, f0
  stfs      f0, 0x30(r1)
  lfs       f1, 0x0(r25)
  lfs       f0, 0x4(r23)
  fsubs     f0, f1, f0
  stfs      f0, 0x2C(r1)
  bl        -0x51CF4
  lfs       f1, 0x5C(r1)
  lfs       f0, 0x60(r1)
  stfs      f1, 0x4C(r1)
  stfs      f0, 0x50(r1)
  lfs       f0, 0x64(r1)
  stfs      f0, 0x54(r1)
  lfs       f1, 0x4C(r1)
  lfs       f0, 0x50(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x54(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x7B20C
  fcmpu     cr0, f31, f1
  beq-      .loc_0x144
  lfs       f0, 0x4C(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x4C(r1)
  lfs       f0, 0x50(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x50(r1)
  lfs       f0, 0x54(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x54(r1)

.loc_0x144:
  lfs       f0, 0x0(r23)
  fadds     f0, f0, f30
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0x178
  lwz       r0, 0x4C(r1)
  li        r4, 0x1
  lwz       r3, 0x50(r1)
  stw       r0, 0x78(r1)
  lwz       r0, 0x54(r1)
  stw       r3, 0x7C(r1)
  stw       r0, 0x80(r1)
  b         .loc_0x17C

.loc_0x178:
  li        r4, 0

.loc_0x17C:
  rlwinm.   r0,r4,0,24,31
  beq-      .loc_0x18C
  mr        r3, r23
  b         .loc_0x1A4

.loc_0x18C:
  addi      r28, r28, 0x68
  addi      r27, r27, 0x1

.loc_0x194:
  lhz       r0, 0xC(r24)
  cmpw      r27, r0
  blt+      .loc_0x4C
  li        r3, 0

.loc_0x1A4:
  lmw       r23, 0x8C(r1)
  lwz       r0, 0xC4(r1)
  lfd       f31, 0xB8(r1)
  lfd       f30, 0xB0(r1)
  addi      r1, r1, 0xC0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80088EF8
 * Size:	000008
 */
void CndCollPart::satisfy(CollPart *)
{
/*
.loc_0x0:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void CollInfo::checkCollisionSpecialRec(int, Vector3f &, float, CndCollPart *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80088F00
 * Size:	000028
 */
void CollInfo::checkCollision(Creature *, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r6, r5, 0
  stw       r0, 0x4(r1)
  li        r5, 0
  stwu      r1, -0x8(r1)
  bl        .loc_0x28
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr       

.loc_0x28:
*/
}

/*
 * --INFO--
 * Address:	80088F28
 * Size:	000624
 */
void CollInfo::checkCollisionRec(Creature *, int, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x160(r1)
  stfd      f31, 0x158(r1)
  stmw      r27, 0x144(r1)
  addi      r27, r5, 0
  addi      r29, r3, 0
  mulli     r0, r27, 0x68
  addi      r30, r4, 0
  addi      r31, r6, 0
  lwz       r3, 0x4(r3)
  add       r3, r3, r0
  lbz       r0, 0x5C(r3)
  addi      r28, r3, 0
  cmplwi    r0, 0x4
  beq-      .loc_0x1B8
  mr        r4, r30
  lwz       r12, 0x0(r30)
  addi      r3, r1, 0x128
  lwz       r12, 0x58(r12)
  mtlr      r12
  blrl      
  lfs       f1, 0x130(r1)
  addi      r6, r1, 0x7C
  lfs       f0, 0xC(r28)
  addi      r5, r1, 0x78
  lfs       f2, 0x12C(r1)
  fsubs     f0, f1, f0
  lfs       f1, 0x128(r1)
  addi      r4, r1, 0x74
  addi      r3, r1, 0x11C
  stfs      f0, 0x7C(r1)
  lfs       f0, 0x8(r28)
  fsubs     f0, f2, f0
  stfs      f0, 0x78(r1)
  lfs       f0, 0x4(r28)
  fsubs     f0, f1, f0
  stfs      f0, 0x74(r1)
  bl        -0x51EA4
  lfs       f1, 0x11C(r1)
  lfs       f0, 0x120(r1)
  stfs      f1, 0x10C(r1)
  stfs      f0, 0x110(r1)
  lfs       f0, 0x124(r1)
  stfs      f0, 0x114(r1)
  lfs       f1, 0x10C(r1)
  lfs       f0, 0x110(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x114(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x7B3BC
  fmr       f31, f1
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f31
  beq-      .loc_0x10C
  lfs       f0, 0x10C(r1)
  fdivs     f0, f0, f31
  stfs      f0, 0x10C(r1)
  lfs       f0, 0x110(r1)
  fdivs     f0, f0, f31
  stfs      f0, 0x110(r1)
  lfs       f0, 0x114(r1)
  fdivs     f0, f0, f31
  stfs      f0, 0x114(r1)

.loc_0x10C:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lfs       f0, 0x0(r28)
  fadds     f0, f0, f1
  fcmpo     cr0, f31, f0
  cror      2, 0, 0x2
  bne-      .loc_0x1B8
  lwz       r4, 0x10C(r1)
  mr        r3, r30
  lwz       r0, 0x110(r1)
  stw       r4, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0x114(r1)
  stw       r0, 0x8(r31)
  lwz       r12, 0x0(r30)
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lfs       f2, 0x0(r28)
  li        r4, 0x1
  lfs       f0, 0x0(r31)
  fadds     f1, f2, f1
  fsubs     f1, f1, f31
  fmuls     f0, f0, f1
  stfs      f0, 0xF8(r1)
  lfs       f0, 0xF8(r1)
  stfs      f0, 0x134(r1)
  lfs       f0, 0x4(r31)
  fmuls     f0, f0, f1
  stfs      f0, 0x138(r1)
  lfs       f0, 0x8(r31)
  fmuls     f0, f0, f1
  stfs      f0, 0x13C(r1)
  lwz       r3, 0x134(r1)
  lwz       r0, 0x138(r1)
  stw       r3, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0x13C(r1)
  stw       r0, 0x8(r31)
  b         .loc_0x1BC

.loc_0x1B8:
  li        r4, 0

.loc_0x1BC:
  rlwinm.   r0,r4,0,24,31
  beq-      .loc_0x3F0
  lbz       r0, 0x5C(r28)
  cmplwi    r0, 0x1
  beq-      .loc_0x1D8
  mr        r3, r28
  b         .loc_0x60C

.loc_0x1D8:
  cmplwi    r0, 0x4
  bne-      .loc_0x1E8
  li        r3, 0
  b         .loc_0x60C

.loc_0x1E8:
  lha       r28, 0x54(r28)
  lwz       r3, 0x4(r29)
  mulli     r0, r28, 0x68
  add       r27, r3, r0
  lbz       r0, 0x5C(r27)
  cmplwi    r0, 0x4
  beq-      .loc_0x370
  mr        r4, r30
  lwz       r12, 0x0(r30)
  addi      r3, r1, 0xE0
  lwz       r12, 0x58(r12)
  mtlr      r12
  blrl      
  lfs       f1, 0xE8(r1)
  addi      r6, r1, 0x4C
  lfs       f0, 0xC(r27)
  addi      r5, r1, 0x48
  lfs       f2, 0xE4(r1)
  fsubs     f0, f1, f0
  lfs       f1, 0xE0(r1)
  addi      r4, r1, 0x44
  addi      r3, r1, 0xD4
  stfs      f0, 0x4C(r1)
  lfs       f0, 0x8(r27)
  fsubs     f0, f2, f0
  stfs      f0, 0x48(r1)
  lfs       f0, 0x4(r27)
  fsubs     f0, f1, f0
  stfs      f0, 0x44(r1)
  bl        -0x52068
  lfs       f1, 0xD4(r1)
  lfs       f0, 0xD8(r1)
  stfs      f1, 0xC4(r1)
  stfs      f0, 0xC8(r1)
  lfs       f0, 0xDC(r1)
  stfs      f0, 0xCC(r1)
  lfs       f1, 0xC4(r1)
  lfs       f0, 0xC8(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0xCC(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x7B580
  fmr       f31, f1
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f31
  beq-      .loc_0x2B8
  addi      r3, r1, 0xC4
  fmr       f1, f31
  bl        .loc_0x624

.loc_0x2B8:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lfs       f0, 0x0(r27)
  fadds     f0, f0, f1
  fcmpo     cr0, f31, f0
  cror      2, 0, 0x2
  bne-      .loc_0x370
  lwz       r4, 0xC4(r1)
  mr        r3, r30
  lwz       r0, 0xC8(r1)
  stw       r4, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0xCC(r1)
  stw       r0, 0x8(r31)
  lwz       r12, 0x0(r30)
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lfs       f2, 0x0(r27)
  addi      r6, r1, 0x68
  lfs       f0, 0x8(r31)
  addi      r5, r1, 0x64
  fadds     f1, f2, f1
  addi      r4, r1, 0x60
  addi      r3, r1, 0xEC
  fsubs     f1, f1, f31
  fmuls     f0, f0, f1
  stfs      f0, 0x68(r1)
  lfs       f0, 0x4(r31)
  fmuls     f0, f0, f1
  stfs      f0, 0x64(r1)
  lfs       f0, 0x0(r31)
  fmuls     f0, f0, f1
  stfs      f0, 0x60(r1)
  bl        -0x52158
  lwz       r3, 0xEC(r1)
  li        r4, 0x1
  lwz       r0, 0xF0(r1)
  stw       r3, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0xF4(r1)
  stw       r0, 0x8(r31)
  b         .loc_0x374

.loc_0x370:
  li        r4, 0

.loc_0x374:
  rlwinm.   r0,r4,0,24,31
  beq-      .loc_0x3B8
  lbz       r0, 0x5C(r27)
  cmplwi    r0, 0x1
  beq-      .loc_0x38C
  b         .loc_0x3E8

.loc_0x38C:
  cmplwi    r0, 0x4
  bne-      .loc_0x39C
  li        r27, 0
  b         .loc_0x3E8

.loc_0x39C:
  lha       r5, 0x54(r27)
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r6, r31, 0
  bl        .loc_0x0
  mr        r27, r3
  b         .loc_0x3E8

.loc_0x3B8:
  cmpwi     r28, 0
  beq-      .loc_0x3E4
  lha       r5, 0x52(r27)
  cmpwi     r5, -0x1
  beq-      .loc_0x3E4
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r6, r31, 0
  bl        .loc_0x0
  mr        r27, r3
  b         .loc_0x3E8

.loc_0x3E4:
  li        r27, 0

.loc_0x3E8:
  mr        r3, r27
  b         .loc_0x60C

.loc_0x3F0:
  cmpwi     r27, 0
  beq-      .loc_0x608
  lha       r28, 0x52(r28)
  cmpwi     r28, -0x1
  beq-      .loc_0x608
  mulli     r0, r28, 0x68
  lwz       r3, 0x4(r29)
  add       r27, r3, r0
  lbz       r0, 0x5C(r27)
  cmplwi    r0, 0x4
  beq-      .loc_0x588
  mr        r4, r30
  lwz       r12, 0x0(r30)
  addi      r3, r1, 0xA4
  lwz       r12, 0x58(r12)
  mtlr      r12
  blrl      
  lfs       f1, 0xAC(r1)
  addi      r6, r1, 0x40
  lfs       f0, 0xC(r27)
  addi      r5, r1, 0x3C
  lfs       f2, 0xA8(r1)
  fsubs     f0, f1, f0
  lfs       f1, 0xA4(r1)
  addi      r4, r1, 0x38
  addi      r3, r1, 0x98
  stfs      f0, 0x40(r1)
  lfs       f0, 0x8(r27)
  fsubs     f0, f2, f0
  stfs      f0, 0x3C(r1)
  lfs       f0, 0x4(r27)
  fsubs     f0, f1, f0
  stfs      f0, 0x38(r1)
  bl        -0x52280
  lfs       f1, 0x98(r1)
  lfs       f0, 0x9C(r1)
  stfs      f1, 0x88(r1)
  stfs      f0, 0x8C(r1)
  lfs       f0, 0xA0(r1)
  stfs      f0, 0x90(r1)
  lfs       f1, 0x88(r1)
  lfs       f0, 0x8C(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x90(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x7B798
  fmr       f31, f1
  lfs       f0, -0x75C0(r2)
  fcmpu     cr0, f0, f31
  beq-      .loc_0x4D0
  addi      r3, r1, 0x88
  fmr       f1, f31
  bl        .loc_0x624

.loc_0x4D0:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lfs       f0, 0x0(r27)
  fadds     f0, f0, f1
  fcmpo     cr0, f31, f0
  cror      2, 0, 0x2
  bne-      .loc_0x588
  lwz       r4, 0x88(r1)
  mr        r3, r30
  lwz       r0, 0x8C(r1)
  stw       r4, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0x90(r1)
  stw       r0, 0x8(r31)
  lwz       r12, 0x0(r30)
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lfs       f2, 0x0(r27)
  addi      r6, r1, 0x58
  lfs       f0, 0x8(r31)
  addi      r5, r1, 0x54
  fadds     f1, f2, f1
  addi      r4, r1, 0x50
  addi      r3, r1, 0xB0
  fsubs     f1, f1, f31
  fmuls     f0, f0, f1
  stfs      f0, 0x58(r1)
  lfs       f0, 0x4(r31)
  fmuls     f0, f0, f1
  stfs      f0, 0x54(r1)
  lfs       f0, 0x0(r31)
  fmuls     f0, f0, f1
  stfs      f0, 0x50(r1)
  bl        -0x52370
  lwz       r3, 0xB0(r1)
  li        r4, 0x1
  lwz       r0, 0xB4(r1)
  stw       r3, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0xB8(r1)
  stw       r0, 0x8(r31)
  b         .loc_0x58C

.loc_0x588:
  li        r4, 0

.loc_0x58C:
  rlwinm.   r0,r4,0,24,31
  beq-      .loc_0x5D0
  lbz       r0, 0x5C(r27)
  cmplwi    r0, 0x1
  beq-      .loc_0x5A4
  b         .loc_0x600

.loc_0x5A4:
  cmplwi    r0, 0x4
  bne-      .loc_0x5B4
  li        r27, 0
  b         .loc_0x600

.loc_0x5B4:
  lha       r5, 0x54(r27)
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r6, r31, 0
  bl        .loc_0x0
  mr        r27, r3
  b         .loc_0x600

.loc_0x5D0:
  cmpwi     r28, 0
  beq-      .loc_0x5FC
  lha       r5, 0x52(r27)
  cmpwi     r5, -0x1
  beq-      .loc_0x5FC
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r6, r31, 0
  bl        .loc_0x0
  mr        r27, r3
  b         .loc_0x600

.loc_0x5FC:
  li        r27, 0

.loc_0x600:
  mr        r3, r27
  b         .loc_0x60C

.loc_0x608:
  li        r3, 0

.loc_0x60C:
  lmw       r27, 0x144(r1)
  lwz       r0, 0x164(r1)
  lfd       f31, 0x158(r1)
  addi      r1, r1, 0x160
  mtlr      r0
  blr       

.loc_0x624:
*/
}

/*
 * --INFO--
 * Address:	8008954C
 * Size:	000028
 */
void Vector3f::div(float)
{
/*
.loc_0x0:
  lfs       f0, 0x0(r3)
  fdivs     f0, f0, f1
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r3)
  fdivs     f0, f0, f1
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r3)
  fdivs     f0, f0, f1
  stfs      f0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80089574
 * Size:	000034
 */
void CollInfo::checkCollision(CollInfo *, CollPart **, CollPart **, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r9, r7, 0
  stw       r0, 0x4(r1)
  addi      r7, r5, 0
  addi      r8, r6, 0
  stwu      r1, -0x8(r1)
  li        r5, 0
  li        r6, 0
  bl        .loc_0x34
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr       

.loc_0x34:
*/
}

/*
 * --INFO--
 * Address:	800895A8
 * Size:	000160
 */
void CollInfo::checkCollisionRec(CollInfo *, int, int, CollPart **, CollPart **, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stmw      r23, 0x2C(r1)
  addi      r31, r5, 0
  addi      r23, r6, 0
  addi      r30, r4, 0
  mulli     r4, r31, 0x68
  mulli     r0, r23, 0x68
  addi      r29, r3, 0
  addi      r26, r9, 0
  lwz       r5, 0x4(r3)
  addi      r24, r7, 0
  lwz       r3, 0x4(r30)
  addi      r25, r8, 0
  add       r28, r5, r4
  add       r27, r3, r0
  addi      r3, r28, 0
  addi      r4, r27, 0
  addi      r5, r26, 0
  bl        -0x10D8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD4
  lbz       r3, 0x5C(r28)
  cmplwi    r3, 0x1
  beq-      .loc_0x84
  lbz       r0, 0x5C(r27)
  cmplwi    r0, 0x1
  beq-      .loc_0x84
  stw       r28, 0x0(r24)
  li        r3, 0x1
  stw       r27, 0x0(r25)
  b         .loc_0x14C

.loc_0x84:
  cmplwi    r3, 0x1
  bne-      .loc_0xB0
  lha       r5, 0x54(r28)
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r6, r23, 0
  addi      r7, r24, 0
  addi      r8, r25, 0
  addi      r9, r26, 0
  bl        .loc_0x0
  b         .loc_0x14C

.loc_0xB0:
  lha       r6, 0x54(r27)
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r5, r31, 0
  addi      r7, r24, 0
  addi      r8, r25, 0
  addi      r9, r26, 0
  bl        .loc_0x0
  b         .loc_0x14C

.loc_0xD4:
  cmpwi     r31, 0
  beq-      .loc_0x108
  lha       r5, 0x52(r28)
  cmpwi     r5, -0x1
  beq-      .loc_0x108
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r6, r23, 0
  addi      r7, r24, 0
  addi      r8, r25, 0
  addi      r9, r26, 0
  bl        .loc_0x0
  b         .loc_0x14C

.loc_0x108:
  cmpwi     r23, 0
  beq-      .loc_0x13C
  lha       r6, 0x52(r27)
  cmpwi     r6, -0x1
  beq-      .loc_0x13C
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r5, r31, 0
  addi      r7, r24, 0
  addi      r8, r25, 0
  addi      r9, r26, 0
  bl        .loc_0x0
  b         .loc_0x14C

.loc_0x13C:
  li        r0, 0
  stw       r0, 0x0(r24)
  li        r3, 0
  stw       r0, 0x0(r25)

.loc_0x14C:
  lmw       r23, 0x2C(r1)
  lwz       r0, 0x54(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80089708
 * Size:	000008
 */
void CollInfo::getBoundingSphere()
{
/*
.loc_0x0:
  lwz       r3, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80089710
 * Size:	000060
 */
void CollInfo::getSphere(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r4, 0
  stw       r30, 0x20(r1)
  addi      r30, r3, 0
  bl        0x7C0
  cmpwi     r3, -0x1
  bne-      .loc_0x3C
  addi      r3, r1, 0x10
  addi      r4, r31, 0
  bl        -0x458AC
  li        r3, 0
  b         .loc_0x48

.loc_0x3C:
  mulli     r0, r3, 0x68
  lwz       r3, 0x4(r30)
  add       r3, r3, r0

.loc_0x48:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80089770
 * Size:	00017C
 */
void CollInfo::getNearestCollPart(Vector3f &, unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xA8(r1)
  stfd      f31, 0xA0(r1)
  stfd      f30, 0x98(r1)
  stfd      f29, 0x90(r1)
  stfd      f28, 0x88(r1)
  stmw      r23, 0x64(r1)
  mr        r23, r3
  mr        r24, r4
  addi      r25, r5, 0
  addi      r29, r1, 0x48
  addi      r31, r1, 0x44
  li        r28, 0
  li        r27, 0
  li        r30, 0
  lfs       f28, -0x759C(r2)
  lfs       f29, -0x75C0(r2)
  lfd       f30, -0x75B8(r2)
  lfd       f31, -0x75B0(r2)
  b         .loc_0x148

.loc_0x54:
  lwz       r0, 0x4(r23)
  add       r3, r0, r30
  lbz       r0, 0x5C(r3)
  addi      r26, r3, 0
  cmplwi    r0, 0x3
  beq-      .loc_0x140
  lwz       r4, 0x58(r26)
  addi      r3, r29, 0
  lwzu      r0, 0x20(r4)
  li        r5, 0x5
  stw       r0, 0x44(r1)
  addi      r4, r4, 0x4
  bl        0x18B1D0
  addi      r3, r31, 0
  addi      r4, r25, 0
  li        r5, 0x2A
  bl        -0x4591C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x140
  lfs       f3, 0x4(r24)
  lfs       f2, 0x8(r26)
  lfs       f1, 0x0(r24)
  lfs       f0, 0x4(r26)
  fsubs     f3, f3, f2
  lfs       f2, 0x8(r24)
  fsubs     f4, f1, f0
  lfs       f1, 0xC(r26)
  fmuls     f0, f3, f3
  fsubs     f2, f2, f1
  fmuls     f1, f4, f4
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f2, f2, f0
  fcmpo     cr0, f2, f29
  ble-      .loc_0x130
  fsqrte    f1, f2
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f0, f1, f0
  fmul      f0, f2, f0
  frsp      f0, f0
  stfs      f0, 0x34(r1)
  lfs       f2, 0x34(r1)

.loc_0x130:
  fcmpo     cr0, f28, f2
  ble-      .loc_0x140
  fmr       f28, f2
  mr        r28, r26

.loc_0x140:
  addi      r30, r30, 0x68
  addi      r27, r27, 0x1

.loc_0x148:
  lhz       r0, 0xC(r23)
  cmpw      r27, r0
  blt+      .loc_0x54
  mr        r3, r28
  lmw       r23, 0x64(r1)
  lwz       r0, 0xAC(r1)
  lfd       f31, 0xA0(r1)
  lfd       f30, 0x98(r1)
  lfd       f29, 0x90(r1)
  lfd       f28, 0x88(r1)
  addi      r1, r1, 0xA8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800898EC
 * Size:	000130
 */
void CollInfo::getRandomCollPart(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x270(r1)
  stmw      r23, 0x24C(r1)
  addi      r28, r3, 0
  addi      r29, r4, 0
  addi      r24, r1, 0x1C
  addi      r26, r1, 0x18
  addi      r27, r1, 0x2C
  li        r31, 0
  li        r30, 0
  li        r25, 0
  b         .loc_0x98

.loc_0x34:
  lwz       r0, 0x4(r28)
  add       r23, r0, r25
  lbz       r0, 0x5C(r23)
  cmplwi    r0, 0x3
  beq-      .loc_0x90
  lwz       r4, 0x58(r23)
  addi      r3, r24, 0
  lwzu      r0, 0x20(r4)
  li        r5, 0x5
  stw       r0, 0x18(r1)
  addi      r4, r4, 0x4
  bl        0x18B078
  addi      r3, r26, 0
  addi      r4, r29, 0
  li        r5, 0x2A
  bl        -0x45A74
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x90
  cmpwi     r31, 0x80
  bge-      .loc_0x90
  rlwinm    r0,r31,2,0,29
  stwx      r23, r27, r0
  addi      r31, r31, 0x1

.loc_0x90:
  addi      r25, r25, 0x68
  addi      r30, r30, 0x1

.loc_0x98:
  lhz       r0, 0xC(r28)
  cmpw      r30, r0
  blt+      .loc_0x34
  cmpwi     r31, 0
  ble-      .loc_0x118
  bl        0x18E6D8
  xoris     r0, r3, 0x8000
  lfd       f4, -0x7590(r2)
  stw       r0, 0x244(r1)
  lis       r4, 0x4330
  xoris     r0, r31, 0x8000
  lfs       f0, -0x7598(r2)
  stw       r4, 0x240(r1)
  lfs       f2, -0x75A8(r2)
  addi      r3, r1, 0x2C
  lfd       f1, 0x240(r1)
  stw       r0, 0x23C(r1)
  fsubs     f3, f1, f4
  lfs       f1, -0x7594(r2)
  stw       r4, 0x238(r1)
  fdivs     f3, f3, f0
  lfd       f0, 0x238(r1)
  fmuls     f2, f2, f3
  fsubs     f0, f0, f4
  fmuls     f0, f0, f2
  fmuls     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x230(r1)
  lwz       r0, 0x234(r1)
  rlwinm    r0,r0,2,0,29
  lwzx      r3, r3, r0
  b         .loc_0x11C

.loc_0x118:
  li        r3, 0

.loc_0x11C:
  lmw       r23, 0x24C(r1)
  lwz       r0, 0x274(r1)
  addi      r1, r1, 0x270
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80089A1C
 * Size:	0000D0
 */
void CollInfo::getPlatform(DynCollObject *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  addi      r3, r4, 0
  lwz       r12, 0x0(r4)
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x38
  li        r3, 0
  b         .loc_0xBC

.loc_0x38:
  lhz       r0, 0xC(r31)
  li        r9, 0
  li        r6, 0
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0xB8

.loc_0x50:
  lwz       r8, 0x4(r31)
  li        r5, 0
  addi      r4, r5, 0
  add       r7, r8, r6
  lbz       r0, 0x5C(r7)
  cmplwi    r0, 0x3
  bne-      .loc_0x7C
  lwz       r0, 0x58(r7)
  cmplwi    r0, 0
  beq-      .loc_0x7C
  li        r4, 0x1

.loc_0x7C:
  rlwinm.   r0,r4,0,24,31
  beq-      .loc_0x98
  lwz       r4, 0x58(r7)
  lwz       r0, 0x48(r4)
  cmplw     r0, r3
  bne-      .loc_0x98
  li        r5, 0x1

.loc_0x98:
  rlwinm.   r0,r5,0,24,31
  beq-      .loc_0xAC
  mulli     r0, r9, 0x68
  add       r3, r8, r0
  b         .loc_0xBC

.loc_0xAC:
  addi      r6, r6, 0x68
  addi      r9, r9, 0x1
  bdnz+     .loc_0x50

.loc_0xB8:
  li        r3, 0

.loc_0xBC:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80089AEC
 * Size:	000064
 */
void CollInfo::updateInfo(Graphics &, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r27, 0x1C(r1)
  li        r30, 0
  mulli     r31, r30, 0x68
  addi      r27, r3, 0
  addi      r28, r4, 0
  addi      r29, r5, 0
  b         .loc_0x44

.loc_0x28:
  lwz       r0, 0x4(r27)
  addi      r4, r28, 0
  addi      r5, r29, 0
  add       r3, r0, r31
  bl        -0x1AA8
  addi      r31, r31, 0x68
  addi      r30, r30, 0x1

.loc_0x44:
  lhz       r0, 0xC(r27)
  cmpw      r30, r0
  blt+      .loc_0x28
  lmw       r27, 0x1C(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80089B50
 * Size:	000014
 */
void CollInfo::hasInfo()
{
/*
.loc_0x0:
  lhz       r0, 0xC(r3)
  neg       r3, r0
  subic     r0, r3, 0x1
  subfe     r3, r0, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	80089B64
 * Size:	0000A4
 */
void CollInfo::initInfo(Shape *, CollPart *, unsigned long *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lbz       r0, 0x0(r3)
  cmplwi    r0, 0
  beq-      .loc_0x3C
  stw       r5, 0x4(r31)
  stw       r6, 0x8(r31)
  lwz       r0, 0x4(r31)
  cmplwi    r0, 0
  beq-      .loc_0x3C
  lwz       r0, 0x8(r31)
  cmplwi    r0, 0

.loc_0x3C:
  li        r6, 0
  li        r5, 0
  b         .loc_0x5C

.loc_0x48:
  lwz       r3, 0x4(r31)
  addi      r0, r5, 0x60
  addi      r6, r6, 0x1
  stwx      r31, r3, r0
  addi      r5, r5, 0x68

.loc_0x5C:
  lhz       r0, 0xE(r31)
  cmpw      r6, r0
  blt+      .loc_0x48
  stw       r4, 0x10(r31)
  li        r0, 0
  addi      r3, r31, 0
  lwz       r4, 0xF8(r4)
  li        r5, 0
  li        r6, 0x1
  sth       r0, 0xC(r31)
  bl        0x148
  mr        r3, r31
  bl        0x340
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void CollInfo::dumpInfo()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void CollInfo::makeTubes(unsigned long, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80089C08
 * Size:	0000B0
 */
void CollInfo::makeTubesChild(unsigned long, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  addi      r31, r5, 0
  stw       r30, 0x30(r1)
  addi      r30, r4, 0
  stw       r29, 0x2C(r1)
  addi      r29, r3, 0
  bl        0x2C0
  cmpwi     r3, -0x1
  bne-      .loc_0x44
  addi      r3, r1, 0x14
  addi      r4, r30, 0
  bl        -0x45DAC
  li        r0, 0
  b         .loc_0x50

.loc_0x44:
  mulli     r0, r3, 0x68
  lwz       r3, 0x4(r29)
  add       r0, r3, r0

.loc_0x50:
  cmpwi     r31, 0
  mtctr     r31
  mr        r5, r0
  li        r0, 0x6
  ble-      .loc_0x94

.loc_0x64:
  lha       r3, 0x54(r5)
  cmpwi     r3, -0x1
  beq-      .loc_0x84
  lwz       r4, 0x60(r5)
  mulli     r3, r3, 0x68
  lwz       r4, 0x4(r4)
  add       r3, r4, r3
  b         .loc_0x88

.loc_0x84:
  li        r3, 0

.loc_0x88:
  stb       r0, 0x5C(r5)
  mr        r5, r3
  bdnz+     .loc_0x64

.loc_0x94:
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80089CB8
 * Size:	000078
 */
void CollInfo::setUpdater(unsigned long, CollPartUpdater *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  addi      r31, r5, 0
  stw       r30, 0x30(r1)
  addi      r30, r4, 0
  stw       r29, 0x2C(r1)
  addi      r29, r3, 0
  bl        0x210
  cmpwi     r3, -0x1
  bne-      .loc_0x44
  addi      r3, r1, 0x14
  addi      r4, r30, 0
  bl        -0x45E5C
  li        r3, 0
  b         .loc_0x50

.loc_0x44:
  mulli     r0, r3, 0x68
  lwz       r3, 0x4(r29)
  add       r3, r3, r0

.loc_0x50:
  cmplwi    r3, 0
  beq-      .loc_0x5C
  stw       r31, 0x64(r3)

.loc_0x5C:
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80089D30
 * Size:	0001BC
 */
void CollInfo::createPart(ObjCollInfo *, int, bool)
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
  mr.       r29, r4
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  beq-      .loc_0x19C
  lwz       r0, 0x2C(r29)
  cmplwi    r0, 0x2
  bne-      .loc_0x8C
  lhz       r3, 0xC(r28)
  li        r0, 0x3
  lwz       r4, 0x4(r28)
  mulli     r3, r3, 0x68
  add       r8, r4, r3
  stw       r29, 0x58(r8)
  lhz       r3, 0xC(r28)
  lwz       r7, 0x14(r29)
  lwz       r5, 0x8(r28)
  addi      r4, r3, 0x1
  rlwinm    r3,r3,2,0,29
  sth       r4, 0xC(r28)
  stwx      r7, r5, r3
  stb       r0, 0x5C(r8)
  lwz       r4, 0xC(r29)
  cmplwi    r4, 0
  beq-      .loc_0x19C
  addi      r3, r28, 0
  addi      r5, r30, 0
  bl        .loc_0x0
  b         .loc_0x19C

.loc_0x8C:
  lhz       r3, 0xC(r28)
  lhz       r0, 0xE(r28)
  cmplw     r3, r0
  blt-      .loc_0xA0
  b         .loc_0x19C

.loc_0xA0:
  mulli     r0, r3, 0x68
  lwz       r3, 0x4(r28)
  add       r31, r3, r0
  stw       r29, 0x58(r31)
  cmpwi     r30, 0
  lhz       r4, 0xC(r28)
  lwz       r7, 0x14(r29)
  lwz       r5, 0x8(r28)
  addi      r3, r4, 0x1
  rlwinm    r0,r4,2,0,29
  sth       r3, 0xC(r28)
  stwx      r7, r5, r0
  bne-      .loc_0xEC
  lhz       r0, 0xC(r28)
  cmplwi    r0, 0x1
  ble-      .loc_0xEC
  li        r0, 0x2
  stb       r0, 0x5C(r31)
  b         .loc_0x144

.loc_0xEC:
  lwz       r0, 0x10(r29)
  cmplwi    r0, 0
  beq-      .loc_0x12C
  lis       r4, 0x6379
  addi      r3, r29, 0x14
  addi      r4, r4, 0x6C2A
  li        r5, 0x2A
  bl        -0x45F50
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x120
  li        r0, 0x4
  stb       r0, 0x5C(r31)
  b         .loc_0x144

.loc_0x120:
  li        r0, 0x1
  stb       r0, 0x5C(r31)
  b         .loc_0x144

.loc_0x12C:
  cmpwi     r30, 0
  bgt-      .loc_0x13C
  rlwinm.   r0,r6,0,24,31
  beq-      .loc_0x144

.loc_0x13C:
  li        r0, 0
  stb       r0, 0x5C(r31)

.loc_0x144:
  lwz       r4, 0x10(r29)
  cmplwi    r4, 0
  beq-      .loc_0x180
  lbz       r0, 0x5C(r31)
  cmplwi    r0, 0x2
  bne-      .loc_0x170
  addi      r3, r28, 0
  addi      r5, r30, 0
  li        r6, 0
  bl        .loc_0x0
  b         .loc_0x180

.loc_0x170:
  addi      r3, r28, 0
  addi      r5, r30, 0x1
  li        r6, 0
  bl        .loc_0x0

.loc_0x180:
  lwz       r4, 0xC(r29)
  cmplwi    r4, 0
  beq-      .loc_0x19C
  addi      r3, r28, 0
  addi      r5, r30, 0
  li        r6, 0
  bl        .loc_0x0

.loc_0x19C:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  lwz       r28, 0x18(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80089EEC
 * Size:	000044
 */
void CollInfo::getId2Index(unsigned long)
{
/*
.loc_0x0:
  lhz       r0, 0xC(r3)
  li        r7, 0
  li        r6, 0
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0x3C

.loc_0x18:
  lwz       r5, 0x8(r3)
  lwzx      r0, r5, r6
  cmplw     r4, r0
  bne-      .loc_0x30
  mr        r3, r7
  blr       

.loc_0x30:
  addi      r6, r6, 0x4
  addi      r7, r7, 0x1
  bdnz+     .loc_0x18

.loc_0x3C:
  li        r3, -0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void CollInfo::getIndex(ObjCollInfo *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80089F30
 * Size:	0000F8
 */
void CollInfo::makeTree()
{
/*
.loc_0x0:
  li        r4, 0
  li        r8, 0
  b         .loc_0xE8

.loc_0xC:
  lwz       r10, 0x4(r3)
  add       r11, r10, r8
  lwz       r9, 0x58(r11)
  lwz       r5, 0xC(r9)
  cmplwi    r5, 0
  beq-      .loc_0x68
  cmpwi     r0, 0
  mtctr     r0
  li        r6, 0
  addi      r7, r6, 0
  ble-      .loc_0x58

.loc_0x38:
  addi      r0, r7, 0x58
  lwzx      r0, r10, r0
  cmplw     r0, r5
  bne-      .loc_0x4C
  b         .loc_0x5C

.loc_0x4C:
  addi      r7, r7, 0x68
  addi      r6, r6, 0x1
  bdnz+     .loc_0x38

.loc_0x58:
  li        r6, -0x1

.loc_0x5C:
  extsh     r0, r6
  sth       r0, 0x52(r11)
  b         .loc_0x70

.loc_0x68:
  li        r0, -0x1
  sth       r0, 0x52(r11)

.loc_0x70:
  lwz       r9, 0x10(r9)
  cmplwi    r9, 0
  beq-      .loc_0xD0
  lhz       r0, 0xC(r3)
  li        r6, 0
  addi      r7, r6, 0
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0xB8

.loc_0x94:
  lwz       r5, 0x4(r3)
  addi      r0, r7, 0x58
  lwzx      r0, r5, r0
  cmplw     r0, r9
  bne-      .loc_0xAC
  b         .loc_0xBC

.loc_0xAC:
  addi      r7, r7, 0x68
  addi      r6, r6, 0x1
  bdnz+     .loc_0x94

.loc_0xB8:
  li        r6, -0x1

.loc_0xBC:
  lwz       r5, 0x4(r3)
  extsh     r6, r6
  addi      r0, r8, 0x54
  sthx      r6, r5, r0
  b         .loc_0xE0

.loc_0xD0:
  lwz       r5, 0x4(r3)
  addi      r0, r8, 0x54
  li        r6, -0x1
  sthx      r6, r5, r0

.loc_0xE0:
  addi      r8, r8, 0x68
  addi      r4, r4, 0x1

.loc_0xE8:
  lhz       r0, 0xC(r3)
  cmpw      r4, r0
  blt+      .loc_0xC
  blr
*/
}

/*
 * --INFO--
 * Address:	8008A028
 * Size:	000004
 */
void __sinit_collInfo_cpp(void)
{
/*
.loc_0x0:
  blr
*/
}