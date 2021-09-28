

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
 * Size:	0000F0
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800B77AC
 * Size:	000054
 */
void ActDecoy::ActDecoy(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  bl        0xC60C
  lis       r3, 0x802B
  subi      r0, r3, 0x246C
  lis       r3, 0x802B
  stw       r0, 0x14(r31)
  addi      r3, r3, 0x642C
  stw       r3, 0x0(r31)
  addi      r0, r3, 0x64
  addi      r3, r31, 0
  stw       r0, 0x14(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800B7800
 * Size:	000178
 */
void ActDecoy::findTeki()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stfd      f31, 0x48(r1)
  stfd      f30, 0x40(r1)
  stmw      r27, 0x2C(r1)
  mr        r27, r3
  li        r28, 0
  lwz       r30, 0x3160(r13)
  lfs       f31, -0x6E80(r2)
  lwz       r12, 0x0(r30)
  addi      r3, r30, 0
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r29, r3
  b         .loc_0xFC

.loc_0x44:
  cmpwi     r29, -0x1
  bne-      .loc_0x6C
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3
  b         .loc_0x88

.loc_0x6C:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3

.loc_0x88:
  lwz       r4, 0xC(r27)
  mr        r3, r31
  bl        -0x2AA14
  lwz       r12, 0x0(r31)
  fmr       f30, f1
  mr        r3, r31
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xE0
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xE0
  fcmpo     cr0, f30, f31
  bge-      .loc_0xE0
  fmr       f31, f30
  mr        r28, r31

.loc_0xE0:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0xFC:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x124
  li        r0, 0x1
  b         .loc_0x150

.loc_0x124:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x14C
  li        r0, 0x1
  b         .loc_0x150

.loc_0x14C:
  li        r0, 0

.loc_0x150:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x44
  mr        r3, r28
  lmw       r27, 0x2C(r1)
  lwz       r0, 0x54(r1)
  lfd       f31, 0x48(r1)
  lfd       f30, 0x40(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001EC
 */
void ActDecoy::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800B7978
 * Size:	00005C
 */
void ActDecoy::init(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  addi      r30, r3, 0
  addi      r3, r1, 0x10
  bl        0x675C0
  addi      r31, r3, 0
  addi      r3, r1, 0x18
  li        r4, 0
  bl        0x675B0
  mr        r4, r3
  lwz       r3, 0xC(r30)
  mr        r5, r31
  bl        0x13020
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
 * Address:	800B79D4
 * Size:	000004
 */
void ActDecoy::cleanup()
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	800B79D8
 * Size:	000004
 */
void ActDecoy::animationKeyUpdated(PaniAnimKeyEvent &)
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	800B79DC
 * Size:	000514
 */
void ActDecoy::exec()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x168(r1)
  stfd      f31, 0x160(r1)
  stfd      f30, 0x158(r1)
  stfd      f29, 0x150(r1)
  stfd      f28, 0x148(r1)
  stw       r31, 0x144(r1)
  mr        r31, r3
  stw       r30, 0x140(r1)
  stw       r29, 0x13C(r1)
  bl        -0x208
  mr.       r29, r3
  beq-      .loc_0x68
  mr        r3, r29
  lwz       r4, 0xC(r31)
  bl        -0x2ABA0
  lfs       f0, -0x6E78(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x5C
  li        r0, 0
  stw       r0, 0x18(r31)
  b         .loc_0xB0

.loc_0x5C:
  li        r0, 0x2
  stw       r0, 0x18(r31)
  b         .loc_0xB0

.loc_0x68:
  lwz       r0, 0x18(r31)
  cmpwi     r0, 0x3
  beq-      .loc_0xA8
  lfs       f0, -0x6E74(r2)
  addi      r3, r1, 0xC0
  li        r4, 0x3
  stfs      f0, 0x1C(r31)
  bl        0x674F8
  addi      r30, r3, 0
  addi      r3, r1, 0xB8
  li        r4, 0x3
  bl        0x674E8
  mr        r4, r3
  lwz       r3, 0xC(r31)
  mr        r5, r30
  bl        0x12F58

.loc_0xA8:
  li        r0, 0x3
  stw       r0, 0x18(r31)

.loc_0xB0:
  lwz       r0, 0x18(r31)
  cmpwi     r0, 0x2
  beq-      .loc_0x11C
  bge-      .loc_0xCC
  cmpwi     r0, 0
  beq-      .loc_0x288
  b         .loc_0x4E4

.loc_0xCC:
  cmpwi     r0, 0x4
  bge-      .loc_0x4E4
  lwz       r3, 0xC(r31)
  lfs       f0, -0x4AC0(r13)
  stfsu     f0, 0xA4(r3)
  lfs       f0, -0x4ABC(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x4AB8(r13)
  stfs      f0, 0x8(r3)
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x1C(r31)
  lfs       f0, 0x28C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x1C(r31)
  lfs       f1, 0x1C(r31)
  lfs       f0, -0x6E7C(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x4E4
  li        r3, 0x2
  b         .loc_0x4E8

.loc_0x11C:
  lwz       r3, 0xC(r31)
  lfsu      f1, 0x94(r3)
  lfs       f0, 0x94(r29)
  lfs       f3, 0x4(r3)
  lfs       f2, 0x98(r29)
  fsubs     f0, f1, f0
  lfs       f4, 0x8(r3)
  lfs       f1, 0x9C(r29)
  fsubs     f2, f3, f2
  stfs      f0, 0x128(r1)
  fsubs     f0, f4, f1
  stfs      f2, 0x12C(r1)
  stfs      f0, 0x130(r1)
  lfs       f1, 0x128(r1)
  lfs       f3, 0x130(r1)
  lfs       f0, 0x12C(r1)
  fmuls     f2, f1, f1
  fmuls     f3, f3, f3
  fmuls     f1, f0, f0
  lfs       f0, -0x6E7C(r2)
  fadds     f1, f2, f1
  fadds     f5, f3, f1
  fcmpo     cr0, f5, f0
  ble-      .loc_0x1D4
  fsqrte    f1, f5
  lfd       f3, -0x6E70(r2)
  lfd       f2, -0x6E68(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f5, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f5, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f5, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f5, f0
  frsp      f0, f0
  stfs      f0, 0x94(r1)
  lfs       f5, 0x94(r1)

.loc_0x1D4:
  lfs       f1, -0x6E60(r2)
  lfs       f0, 0x128(r1)
  fdivs     f3, f1, f5
  lfs       f1, 0x12C(r1)
  lfs       f2, 0x130(r1)
  fmuls     f0, f0, f3
  fmuls     f4, f1, f3
  fmuls     f1, f2, f3
  stfs      f0, 0x128(r1)
  stfs      f4, 0x12C(r1)
  stfs      f1, 0x130(r1)
  lfs       f0, -0x6E5C(r2)
  fcmpo     cr0, f5, f0
  bge-      .loc_0x274
  lfs       f0, -0x6E78(r2)
  fcmpo     cr0, f5, f0
  ble-      .loc_0x274
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x128(r1)
  lfs       f28, 0x28C(r3)
  lfs       f2, 0x130(r1)
  bl        0x163DF4
  lwz       r3, 0xC(r31)
  lfs       f2, 0xA0(r3)
  bl        -0x7F65C
  fmuls     f1, f1, f28
  lfs       f0, -0x6E58(r2)
  lwz       r3, 0xC(r31)
  fmuls     f1, f0, f1
  lfs       f0, 0xA0(r3)
  fadds     f0, f0, f1
  stfs      f0, 0xA0(r3)
  lwz       r3, 0xC(r31)
  lfs       f0, -0x4AB4(r13)
  stfsu     f0, 0xA4(r3)
  lfs       f0, -0x4AB0(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x4AAC(r13)
  stfs      f0, 0x8(r3)
  b         .loc_0x4E4

.loc_0x274:
  lwz       r3, 0xC(r31)
  addi      r4, r1, 0x128
  lfs       f1, -0x6E54(r2)
  bl        0x1417C
  b         .loc_0x4E4

.loc_0x288:
  lwz       r3, 0x3120(r13)
  bl        0x5F75C
  lwz       r4, 0xC(r31)
  lfsu      f3, 0x94(r4)
  lfs       f1, 0x94(r3)
  lfs       f0, 0x98(r3)
  lfs       f2, 0x4(r4)
  fsubs     f31, f3, f1
  lfs       f1, 0x8(r4)
  fsubs     f30, f2, f0
  lfs       f0, 0x9C(r3)
  fsubs     f29, f1, f0
  fmuls     f1, f31, f31
  fmuls     f0, f30, f30
  fmuls     f2, f29, f29
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0xAA068
  lfs       f0, -0x6E7C(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x2E8
  fdivs     f31, f31, f1
  fdivs     f30, f30, f1
  fdivs     f29, f29, f1

.loc_0x2E8:
  lwz       r3, 0xC(r31)
  lfsu      f1, 0x94(r3)
  lfs       f0, 0x94(r29)
  lfs       f3, 0x4(r3)
  lfs       f2, 0x98(r29)
  fsubs     f0, f1, f0
  lfs       f4, 0x8(r3)
  lfs       f1, 0x9C(r29)
  fsubs     f2, f3, f2
  stfs      f0, 0x10C(r1)
  fsubs     f0, f4, f1
  stfs      f2, 0x110(r1)
  stfs      f0, 0x114(r1)
  lfs       f1, 0x10C(r1)
  lfs       f3, 0x114(r1)
  lfs       f0, 0x110(r1)
  fmuls     f2, f1, f1
  fmuls     f3, f3, f3
  fmuls     f1, f0, f0
  lfs       f0, -0x6E7C(r2)
  fadds     f1, f2, f1
  fadds     f28, f3, f1
  fcmpo     cr0, f28, f0
  ble-      .loc_0x3A0
  fsqrte    f1, f28
  lfd       f3, -0x6E70(r2)
  lfd       f2, -0x6E68(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f28, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f28, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f28, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f28, f0
  frsp      f0, f0
  stfs      f0, 0x7C(r1)
  lfs       f28, 0x7C(r1)

.loc_0x3A0:
  lfs       f1, -0x6E50(r2)
  addi      r6, r1, 0x68
  lfs       f0, 0x10C(r1)
  addi      r5, r1, 0x64
  fdivs     f3, f1, f28
  lfs       f1, 0x110(r1)
  addi      r4, r1, 0x60
  lfs       f2, 0x114(r1)
  addi      r3, r1, 0xCC
  fmuls     f0, f0, f3
  fmuls     f4, f1, f3
  fmuls     f1, f2, f3
  stfs      f0, 0x10C(r1)
  stfs      f4, 0x110(r1)
  stfs      f1, 0x114(r1)
  lfs       f1, 0x10C(r1)
  lfs       f0, 0x110(r1)
  lfs       f2, 0x114(r1)
  fmuls     f1, f1, f31
  fmuls     f0, f0, f30
  fmuls     f2, f2, f29
  fadds     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x6C(r1)
  lwz       r0, 0x6C(r1)
  rlwinm    r0,r0,0,1,31
  stw       r0, 0x6C(r1)
  lfs       f0, 0x6C(r1)
  fmuls     f2, f29, f0
  fmuls     f1, f30, f0
  fmuls     f0, f31, f0
  stfs      f2, 0x68(r1)
  stfs      f1, 0x64(r1)
  stfs      f0, 0x60(r1)
  bl        -0x80CE8
  lfs       f5, -0x4AA8(r13)
  lfs       f0, 0xCC(r1)
  lfs       f2, 0xD0(r1)
  fmuls     f0, f0, f5
  lfs       f1, 0x10C(r1)
  lfs       f4, 0xD4(r1)
  fmuls     f2, f2, f5
  lfs       f3, 0x110(r1)
  fadds     f0, f1, f0
  lfs       f1, 0x114(r1)
  fmuls     f4, f4, f5
  fadds     f2, f3, f2
  stfs      f0, 0x10C(r1)
  fadds     f0, f1, f4
  stfs      f2, 0x110(r1)
  stfs      f0, 0x114(r1)
  lfs       f1, 0x10C(r1)
  lfs       f0, 0x110(r1)
  lfs       f2, 0x114(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0xAA228
  lfs       f0, -0x6E7C(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x4C0
  lfs       f0, 0x10C(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x10C(r1)
  lfs       f0, 0x110(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x110(r1)
  lfs       f0, 0x114(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x114(r1)

.loc_0x4C0:
  lwz       r3, 0xC(r31)
  addi      r4, r1, 0x10C
  lfs       f1, -0x6E50(r2)
  bl        0x13F30
  lfs       f0, -0x6E78(r2)
  fcmpo     cr0, f28, f0
  ble-      .loc_0x4E4
  li        r0, 0x2
  stw       r0, 0x18(r31)

.loc_0x4E4:
  li        r3, 0

.loc_0x4E8:
  lwz       r0, 0x16C(r1)
  lfd       f31, 0x160(r1)
  lfd       f30, 0x158(r1)
  lfd       f29, 0x150(r1)
  lfd       f28, 0x148(r1)
  lwz       r31, 0x144(r1)
  lwz       r30, 0x140(r1)
  lwz       r29, 0x13C(r1)
  addi      r1, r1, 0x168
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800B7EF0
 * Size:	00006C
 */
void ActDecoy::~ActDecoy()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  mr.       r30, r3
  beq-      .loc_0x50
  lis       r3, 0x802B
  addi      r3, r3, 0x642C
  stw       r3, 0x0(r30)
  addi      r0, r3, 0x64
  addi      r3, r30, 0
  stw       r0, 0x14(r30)
  li        r4, 0
  bl        0xBEDC
  extsh.    r0, r31
  ble-      .loc_0x50
  mr        r3, r30
  bl        -0x70D90

.loc_0x50:
  mr        r3, r30
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800B7F5C
 * Size:	000008
 */
void ActDecoy::@20@animationKeyUpdated(PaniAnimKeyEvent &)
{
/*
.loc_0x0:
  subi      r3, r3, 0x14
  b         -0x588
*/
}