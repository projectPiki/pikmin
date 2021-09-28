

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
 * Address:	800B5688
 * Size:	00006C
 */
void ActChase::ActChase(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r3, 0x8(r1)
  lwz       r3, 0x8(r1)
  bl        0xE728
  lis       r3, 0x802B
  lwz       r30, 0x8(r1)
  addi      r0, r3, 0x61E0
  stw       r0, 0x0(r30)
  li        r31, 0
  stw       r31, 0x14(r30)
  lwz       r3, 0x14(r30)
  cmplwi    r3, 0
  beq-      .loc_0x50
  bl        0x2EC9C
  stw       r31, 0x14(r30)

.loc_0x50:
  lwz       r3, 0x8(r1)
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
 * Address:	800B56F4
 * Size:	000004
 */
void ActChase::Initialiser::initialise(Action *)
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	800B56F8
 * Size:	0000D4
 */
void ActChase::init(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  addi      r31, r4, 0
  stw       r30, 0x30(r1)
  addi      r30, r3, 0
  bl        0x16295C
  xoris     r0, r3, 0x8000
  lfd       f4, -0x6F18(r2)
  stw       r0, 0x2C(r1)
  lis       r0, 0x4330
  lfs       f3, -0x6F24(r2)
  stw       r0, 0x28(r1)
  lfs       f2, -0x6F28(r2)
  lfd       f1, 0x28(r1)
  lfs       f0, -0x6F1C(r2)
  fsubs     f4, f1, f4
  lfs       f1, -0x6F20(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x18(r30)
  lwz       r3, 0x14(r30)
  cmplwi    r3, 0
  beq-      .loc_0x7C
  beq-      .loc_0x7C
  bl        0x2EC04
  li        r0, 0
  stw       r0, 0x14(r30)

.loc_0x7C:
  stw       r31, 0x14(r30)
  lwz       r3, 0x14(r30)
  cmplwi    r3, 0
  beq-      .loc_0x90
  bl        0x2EBD8

.loc_0x90:
  addi      r3, r1, 0x14
  li        r4, 0
  bl        0x697C8
  addi      r31, r3, 0
  addi      r3, r1, 0x1C
  li        r4, 0
  bl        0x697B8
  mr        r4, r3
  lwz       r3, 0xC(r30)
  mr        r5, r31
  bl        0x15228
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800B57CC
 * Size:	000040
 */
void ActChase::cleanup()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lwz       r3, 0x14(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2C
  bl        0x2EB80
  li        r0, 0
  stw       r0, 0x14(r31)

.loc_0x2C:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800B580C
 * Size:	00023C
 */
void ActChase::exec()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x90(r1)
  stfd      f31, 0x88(r1)
  stfd      f30, 0x80(r1)
  stw       r31, 0x7C(r1)
  stw       r30, 0x78(r1)
  mr        r30, r3
  lwz       r31, 0x14(r3)
  lwz       r12, 0x0(r31)
  mr        r3, r31
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x48
  li        r3, 0x1
  b         .loc_0x21C

.loc_0x48:
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x18(r30)
  lfs       f0, 0x28C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x18(r30)
  lwz       r4, 0xC(r30)
  lwz       r3, 0x500(r4)
  cmplwi    r3, 0
  beq-      .loc_0x80
  lwz       r0, 0x14(r30)
  cmplw     r3, r0
  bne-      .loc_0x80
  li        r3, 0x2
  b         .loc_0x21C

.loc_0x80:
  lfs       f0, 0x18(r30)
  lfs       f5, -0x6F10(r2)
  fcmpo     cr0, f0, f5
  bge-      .loc_0x98
  li        r3, 0x1
  b         .loc_0x21C

.loc_0x98:
  lfs       f0, -0x4B98(r13)
  stfs      f0, 0xA4(r4)
  lfs       f0, -0x4B94(r13)
  stfs      f0, 0xA8(r4)
  lfs       f0, -0x4B90(r13)
  stfs      f0, 0xAC(r4)
  lwz       r3, 0xC(r30)
  lfsu      f0, 0x94(r3)
  lfs       f1, 0x94(r31)
  lfs       f3, 0x98(r31)
  lfs       f2, 0x4(r3)
  fsubs     f0, f1, f0
  lfs       f4, 0x9C(r31)
  lfs       f1, 0x8(r3)
  fsubs     f2, f3, f2
  stfs      f0, 0x5C(r1)
  fsubs     f0, f4, f1
  stfs      f2, 0x60(r1)
  stfs      f0, 0x64(r1)
  stfs      f5, 0x60(r1)
  lfs       f1, 0x5C(r1)
  lfs       f0, 0x60(r1)
  lfs       f2, 0x64(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f4, f2, f0
  fcmpo     cr0, f4, f5
  ble-      .loc_0x168
  fsqrte    f1, f4
  lfd       f3, -0x6F08(r2)
  lfd       f2, -0x6F00(r2)
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
  stfs      f0, 0x38(r1)
  lfs       f4, 0x38(r1)

.loc_0x168:
  lfs       f0, -0x6F10(r2)
  fcmpo     cr0, f4, f0
  ble-      .loc_0x1A4
  lfs       f1, -0x6F28(r2)
  lfs       f0, 0x5C(r1)
  fdivs     f3, f1, f4
  lfs       f1, 0x60(r1)
  lfs       f2, 0x64(r1)
  fmuls     f0, f0, f3
  fmuls     f4, f1, f3
  fmuls     f1, f2, f3
  stfs      f0, 0x5C(r1)
  stfs      f4, 0x60(r1)
  stfs      f1, 0x64(r1)
  b         .loc_0x208

.loc_0x1A4:
  bl        0x1626C0
  xoris     r0, r3, 0x8000
  lfd       f4, -0x6F18(r2)
  stw       r0, 0x74(r1)
  lis       r0, 0x4330
  lfs       f3, -0x6F24(r2)
  stw       r0, 0x70(r1)
  lfs       f2, -0x6F28(r2)
  lfd       f1, 0x70(r1)
  lfs       f0, -0x6EF8(r2)
  fsubs     f4, f1, f4
  lfs       f1, -0x6F1C(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fmuls     f30, f1, f0
  fmr       f1, f30
  bl        0x1662F4
  fmr       f31, f1
  fmr       f1, f30
  bl        0x166154
  stfs      f1, 0x5C(r1)
  lfs       f0, -0x4B8C(r13)
  stfs      f0, 0x60(r1)
  stfs      f31, 0x64(r1)

.loc_0x208:
  lwz       r3, 0xC(r30)
  addi      r4, r1, 0x5C
  lfs       f1, -0x6F28(r2)
  bl        0x163B8
  li        r3, 0

.loc_0x21C:
  lwz       r0, 0x94(r1)
  lfd       f31, 0x88(r1)
  lfd       f30, 0x80(r1)
  lwz       r31, 0x7C(r1)
  lwz       r30, 0x78(r1)
  addi      r1, r1, 0x90
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800B5A48
 * Size:	000064
 */
void ActChase::~ActChase()
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
  beq-      .loc_0x48
  lis       r3, 0x802B
  addi      r0, r3, 0x61E0
  stw       r0, 0x0(r30)
  addi      r3, r30, 0
  li        r4, 0
  bl        0xE38C
  extsh.    r0, r31
  ble-      .loc_0x48
  mr        r3, r30
  bl        -0x6E8E0

.loc_0x48:
  mr        r3, r30
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}