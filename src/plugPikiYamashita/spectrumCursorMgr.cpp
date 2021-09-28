

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
 * Size:	000054
 */
void zen::SpectrumCursorMgr::setMirror(P2DPane *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801DA814
 * Size:	000394
 */
void zen::SpectrumCursorMgr::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xC0(r1)
  stfd      f31, 0xB8(r1)
  stfd      f30, 0xB0(r1)
  stfd      f29, 0xA8(r1)
  stfd      f28, 0xA0(r1)
  stw       r31, 0x9C(r1)
  stw       r30, 0x98(r1)
  stw       r29, 0x94(r1)
  mr        r29, r3
  lwz       r3, 0x0(r3)
  lfs       f28, -0x41B0(r2)
  subi      r0, r3, 0x1
  lfs       f29, -0x41AC(r2)
  lfs       f30, -0x41B8(r2)
  mr        r30, r0
  lfs       f31, -0x41B4(r2)
  rlwinm    r31,r0,2,0,29
  b         .loc_0x128

.loc_0x50:
  lwz       r0, 0x4(r29)
  add       r4, r0, r31
  lwz       r3, 0x0(r4)
  lwz       r4, -0x4(r4)
  lwz       r12, 0x0(r3)
  lha       r5, 0x1A(r4)
  lwz       r12, 0x14(r12)
  lha       r4, 0x18(r4)
  mtlr      r12
  blrl      
  lwz       r0, 0x4(r29)
  li        r3, 0x79
  add       r5, r0, r31
  lwz       r4, -0x4(r5)
  lwz       r5, 0x0(r5)
  lfs       f0, 0xBC(r4)
  lbz       r0, 0xC(r5)
  rlwimi    r0,r3,5,25,26
  stb       r0, 0xC(r5)
  stfs      f0, 0xBC(r5)
  lfs       f0, 0xBC(r5)
  fcmpo     cr0, f0, f28
  bge-      .loc_0xB8
  fadds     f0, f0, f29
  stfs      f0, 0xBC(r5)
  b         .loc_0xC8

.loc_0xB8:
  fcmpo     cr0, f0, f29
  ble-      .loc_0xC8
  fsubs     f0, f0, f29
  stfs      f0, 0xBC(r5)

.loc_0xC8:
  lwz       r3, 0x4(r29)
  lwzx      r3, r3, r31
  lfs       f0, 0xBC(r3)
  fcmpo     cr0, f0, f30
  ble-      .loc_0xF0
  fcmpo     cr0, f0, f31
  bge-      .loc_0xF0
  li        r4, 0x2
  bl        -0x1AF08
  b         .loc_0xF8

.loc_0xF0:
  li        r4, 0
  bl        -0x1AF14

.loc_0xF8:
  lwz       r4, 0x4(r29)
  subi      r30, r30, 0x1
  lwz       r3, 0x0(r4)
  lwzx      r4, r4, r31
  subi      r31, r31, 0x4
  addi      r5, r3, 0xC0
  lwz       r3, 0xC0(r3)
  lwz       r0, 0x4(r5)
  stw       r3, 0xC0(r4)
  stw       r0, 0xC4(r4)
  lwz       r0, 0x8(r5)
  stw       r0, 0xC8(r4)

.loc_0x128:
  cmpwi     r30, 0
  bgt+      .loc_0x50
  lfs       f1, 0x8(r29)
  lfs       f0, 0xC(r29)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x224
  lwz       r3, 0x2DEC(r13)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r29)
  lfs       f0, 0x8(r29)
  lfs       f1, 0xC(r29)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x164
  stfs      f1, 0x8(r29)

.loc_0x164:
  lfs       f1, 0x8(r29)
  lfs       f0, 0xC(r29)
  lfs       f2, -0x41B8(r2)
  fdivs     f0, f1, f0
  fmuls     f1, f2, f0
  bl        0x4135C
  lfs       f2, -0x41A8(r2)
  lfs       f0, 0x1C(r29)
  fsubs     f5, f2, f1
  lfs       f2, 0x14(r29)
  fmuls     f3, f0, f1
  lfs       f0, -0x41B0(r2)
  fmuls     f2, f2, f5
  fadds     f2, f3, f2
  fcmpo     cr0, f2, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x1B4
  lfs       f0, -0x41A4(r2)
  fadds     f2, f0, f2
  b         .loc_0x1BC

.loc_0x1B4:
  lfs       f0, -0x41A4(r2)
  fsubs     f2, f2, f0

.loc_0x1BC:
  lfs       f0, 0x18(r29)
  fctiwz    f4, f2
  lfs       f2, 0x10(r29)
  fmuls     f3, f0, f1
  lfs       f0, -0x41B0(r2)
  fmuls     f1, f2, f5
  stfd      f4, 0x88(r1)
  fadds     f1, f3, f1
  lwz       r5, 0x8C(r1)
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x1F8
  lfs       f0, -0x41A4(r2)
  fadds     f0, f0, f1
  b         .loc_0x200

.loc_0x1F8:
  lfs       f0, -0x41A4(r2)
  fsubs     f0, f1, f0

.loc_0x200:
  lwz       r3, 0x4(r29)
  fctiwz    f0, f0
  lwz       r3, 0x0(r3)
  stfd      f0, 0x88(r1)
  lwz       r12, 0x0(r3)
  lwz       r4, 0x8C(r1)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      

.loc_0x224:
  lfs       f1, 0x20(r29)
  lfs       f0, 0x24(r29)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x2A0
  lwz       r3, 0x2DEC(r13)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x20(r29)
  lfs       f0, 0x20(r29)
  lfs       f1, 0x24(r29)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x258
  stfs      f1, 0x20(r29)

.loc_0x258:
  lfs       f1, 0x20(r29)
  lfs       f0, 0x24(r29)
  lfs       f2, -0x41B8(r2)
  fdivs     f0, f1, f0
  fmuls     f1, f2, f0
  bl        0x41268
  lfs       f2, -0x41A8(r2)
  lfs       f0, 0x2C(r29)
  fsubs     f2, f2, f1
  lfs       f3, 0x28(r29)
  lwz       r3, 0x4(r29)
  fmuls     f0, f0, f1
  fmuls     f1, f3, f2
  lwz       r3, 0x0(r3)
  fadds     f0, f1, f0
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)

.loc_0x2A0:
  lwz       r3, 0x2DEC(r13)
  lwz       r4, 0x4(r29)
  lfs       f1, -0x41A0(r2)
  lfs       f0, 0x28C(r3)
  lwz       r4, 0x0(r4)
  fmuls     f0, f1, f0
  lfs       f1, -0x41AC(r2)
  lfs       f2, 0xBC(r4)
  fadds     f0, f2, f0
  fcmpo     cr0, f0, f1
  fmr       f2, f0
  ble-      .loc_0x2D8
  fsubs     f2, f2, f1
  b         .loc_0x2E8

.loc_0x2D8:
  lfs       f0, -0x41B0(r2)
  fcmpo     cr0, f2, f0
  bge-      .loc_0x2E8
  fadds     f2, f2, f1

.loc_0x2E8:
  lbz       r0, 0xC(r4)
  li        r3, 0x79
  rlwimi    r0,r3,5,25,26
  stb       r0, 0xC(r4)
  stfs      f2, 0xBC(r4)
  lfs       f1, 0xBC(r4)
  lfs       f0, -0x41B0(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x31C
  lfs       f0, -0x41AC(r2)
  fadds     f0, f1, f0
  stfs      f0, 0xBC(r4)
  b         .loc_0x330

.loc_0x31C:
  lfs       f0, -0x41AC(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x330
  fsubs     f0, f1, f0
  stfs      f0, 0xBC(r4)

.loc_0x330:
  lwz       r3, 0x4(r29)
  lfs       f0, -0x41B8(r2)
  lwz       r3, 0x0(r3)
  lfs       f1, 0xBC(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x360
  lfs       f0, -0x41B4(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x360
  li        r4, 0x2
  bl        -0x1B178
  b         .loc_0x368

.loc_0x360:
  li        r4, 0
  bl        -0x1B184

.loc_0x368:
  lwz       r0, 0xC4(r1)
  lfd       f31, 0xB8(r1)
  lfd       f30, 0xB0(r1)
  lfd       f29, 0xA8(r1)
  lfd       f28, 0xA0(r1)
  lwz       r31, 0x9C(r1)
  lwz       r30, 0x98(r1)
  lwz       r29, 0x94(r1)
  addi      r1, r1, 0xC0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801DABA8
 * Size:	000070
 */
void zen::SpectrumCursorMgr::move(float, float, float)
{
/*
.loc_0x0:
  stwu      r1, -0x40(r1)
  lis       r5, 0x4330
  lfs       f0, -0x41B0(r2)
  stfs      f0, 0x8(r3)
  stfs      f3, 0xC(r3)
  lwz       r4, 0x4(r3)
  lfd       f3, -0x4198(r2)
  lwz       r4, 0x0(r4)
  lha       r0, 0x18(r4)
  xoris     r0, r0, 0x8000
  stw       r0, 0x3C(r1)
  stw       r5, 0x38(r1)
  lfd       f0, 0x38(r1)
  fsubs     f0, f0, f3
  stfs      f0, 0x10(r3)
  lwz       r4, 0x4(r3)
  lwz       r4, 0x0(r4)
  lha       r0, 0x1A(r4)
  xoris     r0, r0, 0x8000
  stw       r0, 0x34(r1)
  stw       r5, 0x30(r1)
  lfd       f0, 0x30(r1)
  fsubs     f0, f0, f3
  stfs      f0, 0x14(r3)
  stfs      f1, 0x18(r3)
  stfs      f2, 0x1C(r3)
  addi      r1, r1, 0x40
  blr
*/
}

/*
 * --INFO--
 * Address:	801DAC18
 * Size:	000024
 */
void zen::SpectrumCursorMgr::scale(float, float)
{
/*
.loc_0x0:
  lfs       f0, -0x41B0(r2)
  stfs      f0, 0x20(r3)
  stfs      f2, 0x24(r3)
  lwz       r4, 0x4(r3)
  lwz       r4, 0x0(r4)
  lfs       f0, 0xC0(r4)
  stfs      f0, 0x28(r3)
  stfs      f1, 0x2C(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801DAC3C
 * Size:	000374
 */
void zen::SpectrumCursorMgr::init(P2DScreen *, P2DPane *, unsigned long, float, float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x118(r1)
  stfd      f31, 0x110(r1)
  stfd      f30, 0x108(r1)
  stfd      f29, 0x100(r1)
  stfd      f28, 0xF8(r1)
  stfd      f27, 0xF0(r1)
  stfd      f26, 0xE8(r1)
  fmr       f26, f2
  stfd      f25, 0xE0(r1)
  fmr       f25, f1
  stmw      r25, 0xC4(r1)
  addi      r28, r5, 0
  addi      r29, r6, 0
  addi      r27, r4, 0
  mr        r26, r3
  addi      r4, r29, 0
  stw       r0, 0x0(r3)
  lwz       r5, 0x0(r3)
  bl        0x474
  stw       r3, 0x94(r1)
  b         .loc_0x80

.loc_0x60:
  lwz       r5, 0x0(r26)
  addi      r3, r26, 0
  addi      r4, r29, 0
  addi      r0, r5, 0x1
  stw       r0, 0x0(r26)
  lwz       r5, 0x0(r26)
  bl        0x450
  stw       r3, 0x94(r1)

.loc_0x80:
  lwz       r12, 0x0(r27)
  mr        r3, r27
  lbz       r0, 0x95(r1)
  li        r5, 0
  lwz       r12, 0x34(r12)
  lbz       r4, 0x94(r1)
  rlwinm    r0,r0,16,0,15
  lbz       r6, 0x96(r1)
  mtlr      r12
  rlwimi    r0,r4,24,0,7
  lbz       r7, 0x97(r1)
  rlwimi    r0,r6,8,16,23
  or        r4, r7, r0
  blrl      
  cmplwi    r3, 0
  bne+      .loc_0x60
  lwz       r0, 0x0(r26)
  rlwinm    r3,r0,2,0,29
  bl        -0x193D00
  stw       r3, 0x4(r26)
  lis       r25, 0x4330
  lwz       r3, 0x0(r26)
  lfs       f28, -0x4190(r2)
  subi      r0, r3, 0x1
  lfs       f29, -0x41A8(r2)
  lfd       f30, -0x4198(r2)
  mr        r30, r0
  lfs       f31, -0x41A4(r2)
  rlwinm    r31,r0,2,0,29
  lfs       f27, -0x41B0(r2)
  b         .loc_0x260

.loc_0xFC:
  addi      r3, r26, 0
  addi      r4, r29, 0
  addi      r5, r30, 0
  bl        0x3C0
  stw       r3, 0x94(r1)
  addi      r3, r27, 0
  li        r5, 0x1
  lwz       r12, 0x0(r27)
  lbz       r0, 0x95(r1)
  lwz       r12, 0x34(r12)
  lbz       r4, 0x94(r1)
  rlwinm    r0,r0,16,0,15
  lbz       r6, 0x96(r1)
  mtlr      r12
  rlwimi    r0,r4,24,0,7
  lbz       r4, 0x97(r1)
  rlwimi    r0,r6,8,16,23
  or        r4, r4, r0
  blrl      
  lhz       r0, 0x8(r3)
  cmplwi    r0, 0x12
  bne-      .loc_0x258
  lwz       r5, 0x4(r26)
  mr        r4, r28
  stwx      r3, r5, r31
  lwz       r3, 0x4(r26)
  lwzx      r3, r3, r31
  bl        -0x1B204
  lwz       r3, 0x4(r26)
  li        r4, 0x1
  cmpwi     r30, 0
  lwzx      r6, r3, r31
  lha       r3, 0x18(r6)
  lha       r0, 0x1C(r6)
  lha       r5, 0x1A(r6)
  sub       r0, r0, r3
  lha       r3, 0x1E(r6)
  srawi     r0, r0, 0x1
  sub       r5, r3, r5
  extsh     r3, r0
  srawi     r0, r5, 0x1
  sth       r3, 0xB8(r6)
  extsh     r0, r0
  sth       r0, 0xBA(r6)
  lwz       r3, 0x4(r26)
  lwzx      r3, r3, r31
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x4(r26)
  lwzx      r3, r3, r31
  stfs      f27, 0xC0(r3)
  stfs      f27, 0xC4(r3)
  stfs      f27, 0xC8(r3)
  bne-      .loc_0x1EC
  lwz       r3, 0x4(r26)
  li        r4, 0xFF
  lwzx      r3, r3, r31
  bl        -0x1B548
  b         .loc_0x258

.loc_0x1EC:
  lwz       r0, 0x0(r26)
  xoris     r3, r30, 0x8000
  stw       r3, 0xBC(r1)
  xoris     r0, r0, 0x8000
  stw       r0, 0xB4(r1)
  stw       r25, 0xB8(r1)
  stw       r25, 0xB0(r1)
  lfd       f1, 0xB8(r1)
  lfd       f0, 0xB0(r1)
  fsubs     f1, f1, f30
  fsubs     f0, f0, f30
  fdivs     f0, f1, f0
  fsubs     f0, f29, f0
  fmuls     f0, f28, f0
  fcmpo     cr0, f0, f27
  cror      2, 0x1, 0x2
  bne-      .loc_0x238
  fadds     f0, f31, f0
  b         .loc_0x23C

.loc_0x238:
  fsubs     f0, f0, f31

.loc_0x23C:
  fctiwz    f0, f0
  lwz       r3, 0x4(r26)
  lwzx      r3, r3, r31
  stfd      f0, 0xB0(r1)
  lwz       r0, 0xB4(r1)
  rlwinm    r4,r0,0,24,31
  bl        -0x1B5B8

.loc_0x258:
  subi      r31, r31, 0x4
  subi      r30, r30, 0x1

.loc_0x260:
  cmpwi     r30, 0
  bge+      .loc_0xFC
  fmr       f1, f25
  mr        r3, r26
  fmr       f2, f26
  bl        .loc_0x374
  mr        r3, r26
  lfs       f1, -0x41B0(r2)
  bl        0x1FC
  lwz       r3, 0x4(r26)
  lis       r4, 0x4330
  lfs       f4, -0x41B0(r2)
  lwz       r3, 0x0(r3)
  lha       r0, 0x1A(r3)
  lha       r3, 0x18(r3)
  xoris     r0, r0, 0x8000
  stfs      f4, 0x8(r26)
  xoris     r3, r3, 0x8000
  stfs      f4, 0xC(r26)
  lwz       r5, 0x4(r26)
  stw       r3, 0xAC(r1)
  lwz       r3, 0x0(r5)
  stw       r4, 0xA8(r1)
  lha       r3, 0x18(r3)
  stw       r0, 0xA4(r1)
  xoris     r0, r3, 0x8000
  lfd       f3, -0x4198(r2)
  stw       r0, 0xB4(r1)
  lfd       f0, 0xA8(r1)
  stw       r4, 0xB0(r1)
  fsubs     f1, f0, f3
  lfd       f0, 0xB0(r1)
  stw       r4, 0xA0(r1)
  fsubs     f2, f0, f3
  lfd       f0, 0xA0(r1)
  stfs      f2, 0x10(r26)
  fsubs     f0, f0, f3
  lwz       r3, 0x4(r26)
  lwz       r3, 0x0(r3)
  lha       r0, 0x1A(r3)
  xoris     r0, r0, 0x8000
  stw       r0, 0xBC(r1)
  stw       r4, 0xB8(r1)
  lfd       f2, 0xB8(r1)
  fsubs     f2, f2, f3
  stfs      f2, 0x14(r26)
  stfs      f1, 0x18(r26)
  stfs      f0, 0x1C(r26)
  stfs      f4, 0x20(r26)
  lfs       f0, -0x41A4(r2)
  stfs      f0, 0x24(r26)
  lwz       r3, 0x4(r26)
  lwz       r3, 0x0(r3)
  lfs       f0, 0xC0(r3)
  stfs      f0, 0x28(r26)
  lfs       f0, -0x41A8(r2)
  stfs      f0, 0x2C(r26)
  lwz       r0, 0x11C(r1)
  lfd       f31, 0x110(r1)
  lfd       f30, 0x108(r1)
  lfd       f29, 0x100(r1)
  lfd       f28, 0xF8(r1)
  lfd       f27, 0xF0(r1)
  lfd       f26, 0xE8(r1)
  lfd       f25, 0xE0(r1)
  lmw       r25, 0xC4(r1)
  addi      r1, r1, 0x118
  mtlr      r0
  blr       

.loc_0x374:
*/
}

/*
 * --INFO--
 * Address:	801DAFB0
 * Size:	000108
 */
void zen::SpectrumCursorMgr::initPos(float, float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stfd      f31, 0x58(r1)
  stfd      f30, 0x50(r1)
  stfd      f29, 0x48(r1)
  stfd      f28, 0x40(r1)
  stfd      f27, 0x38(r1)
  fmr       f27, f2
  stfd      f26, 0x30(r1)
  fmr       f26, f1
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  li        r30, 0
  rlwinm    r31,r30,2,0,29
  stw       r29, 0x24(r1)
  mr        r29, r3
  lfs       f30, -0x41A4(r2)
  lfs       f31, -0x41B0(r2)
  fadds     f29, f30, f27
  fadds     f28, f30, f26
  b         .loc_0xC0

.loc_0x58:
  fcmpo     cr0, f27, f31
  cror      2, 0x1, 0x2
  bne-      .loc_0x6C
  fmr       f0, f29
  b         .loc_0x70

.loc_0x6C:
  fsubs     f0, f27, f30

.loc_0x70:
  fctiwz    f0, f0
  fcmpo     cr0, f26, f31
  stfd      f0, 0x18(r1)
  lwz       r5, 0x1C(r1)
  cror      2, 0x1, 0x2
  bne-      .loc_0x90
  fmr       f0, f28
  b         .loc_0x94

.loc_0x90:
  fsubs     f0, f26, f30

.loc_0x94:
  lwz       r3, 0x4(r29)
  fctiwz    f0, f0
  lwzx      r3, r3, r31
  stfd      f0, 0x18(r1)
  lwz       r12, 0x0(r3)
  lwz       r4, 0x1C(r1)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  addi      r31, r31, 0x4
  addi      r30, r30, 0x1

.loc_0xC0:
  lwz       r0, 0x0(r29)
  cmpw      r30, r0
  blt+      .loc_0x58
  stfs      f26, 0x18(r29)
  stfs      f27, 0x1C(r29)
  lwz       r0, 0x64(r1)
  lfd       f31, 0x58(r1)
  lfd       f30, 0x50(r1)
  lfd       f29, 0x48(r1)
  lfd       f28, 0x40(r1)
  lfd       f27, 0x38(r1)
  lfd       f26, 0x30(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  lwz       r29, 0x24(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801DB0B8
 * Size:	00004C
 */
void zen::SpectrumCursorMgr::initScale(float)
{
/*
.loc_0x0:
  lfs       f0, -0x41B0(r2)
  li        r6, 0
  li        r5, 0
  stfs      f0, 0x8(r3)
  stfs      f0, 0xC(r3)
  b         .loc_0x34

.loc_0x18:
  lwz       r4, 0x4(r3)
  addi      r6, r6, 0x1
  lwzx      r4, r4, r5
  addi      r5, r5, 0x4
  stfs      f1, 0xC0(r4)
  stfs      f1, 0xC4(r4)
  stfs      f1, 0xC8(r4)

.loc_0x34:
  lwz       r0, 0x0(r3)
  cmpw      r6, r0
  blt+      .loc_0x18
  stfs      f1, 0x28(r3)
  stfs      f1, 0x2C(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801DB104
 * Size:	000048
 */
void zen::SpectrumCursorMgr::makeTag(unsigned long, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  crclr     6, 0x6
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r4, 0
  addi      r3, r1, 0x14
  addi      r4, r13, 0x2468
  bl        0x3B474
  rlwinm    r0,r31,8,24,31
  stb       r0, 0x14(r1)
  stb       r31, 0x17(r1)
  lwz       r3, 0x14(r1)
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}