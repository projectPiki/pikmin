

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
 * Address:	800EDDD0
 * Size:	0000DC
 */
void SeedItem::SeedItem(CreatureProp *, Shape **)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r5, 0
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  bl        -0x62F14
  lis       r3, 0x802C
  subi      r0, r3, 0x2980
  lis       r3, 0x8009
  stw       r0, 0x0(r30)
  subi      r4, r3, 0x5808
  addi      r3, r30, 0x2BC
  li        r5, 0
  li        r6, 0xC
  li        r7, 0x3
  bl        0x126C5C
  lfs       f0, -0x64C8(r2)
  li        r0, 0x4
  addi      r3, r30, 0x1B8
  stfs      f0, 0x2F8(r30)
  addi      r4, r30, 0x2BC
  li        r5, 0x3
  stfs      f0, 0x2F4(r30)
  stfs      f0, 0x2F0(r30)
  lwz       r6, 0x0(r31)
  stw       r6, 0x2E8(r30)
  lwz       r6, 0x4(r31)
  stw       r6, 0x2EC(r30)
  lwz       r6, 0x2E8(r30)
  stw       r6, 0x2E4(r30)
  lfs       f0, -0x64C4(r2)
  stfs      f0, 0x7C(r30)
  stfs      f0, 0x80(r30)
  stfs      f0, 0x84(r30)
  stw       r0, 0x68(r30)
  lwz       r0, 0xC8(r30)
  rlwinm    r0,r0,0,23,21
  stw       r0, 0xC8(r30)
  lwz       r0, 0xC8(r30)
  ori       r0, r0, 0x11
  stw       r0, 0xC8(r30)
  bl        -0xA1FC
  li        r0, 0x2
  stw       r0, 0x6C(r30)
  li        r0, 0x3
  addi      r3, r30, 0
  stw       r0, 0x2B8(r30)
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EDEAC
 * Size:	000008
 */
void SeedItem::getSize()
{
/*
.loc_0x0:
  lfs       f1, -0x64C0(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	800EDEB4
 * Size:	000044
 */
void SeedItem::init(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        -0x632C4
  addi      r3, r31, 0x1B8
  addi      r4, r31, 0x2BC
  li        r5, 0x3
  bl        -0xA258
  li        r0, 0x3
  stw       r0, 0x2B8(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void SeedItem::startBirth()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void SeedItem::startSown()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800EDEF8
 * Size:	000014
 */
void SeedItem::isVisible()
{
/*
.loc_0x0:
  lwz       r0, 0x2B8(r3)
  subfic    r3, r0, 0x2
  subic     r0, r3, 0x1
  subfe     r3, r0, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	800EDF0C
 * Size:	000008
 */
void SeedItem::isAtari()
{
/*
.loc_0x0:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EDF14
 * Size:	00003C
 */
void SeedItem::doKill()
{
/*
.loc_0x0:
  mflr      r0
  mr        r4, r3
  stw       r0, 0x4(r1)
  li        r0, 0x2
  stwu      r1, -0x8(r1)
  stw       r0, 0x2B8(r3)
  lwz       r3, 0x30AC(r13)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x7C(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EDF50
 * Size:	00023C
 */
void SeedItem::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB0(r1)
  stfd      f31, 0xA8(r1)
  stfd      f30, 0xA0(r1)
  stfd      f29, 0x98(r1)
  stfd      f28, 0x90(r1)
  stfd      f27, 0x88(r1)
  stw       r31, 0x84(r1)
  stw       r30, 0x80(r1)
  mr        r30, r3
  lwz       r0, 0x2B8(r3)
  cmpwi     r0, 0
  bne-      .loc_0x208
  lwz       r3, 0x3120(r13)
  bl        0x29438
  lfs       f0, 0x94(r30)
  mr        r31, r3
  lfs       f1, 0x94(r3)
  lfs       f2, 0x9C(r3)
  fsubs     f30, f1, f0
  lfs       f0, 0x9C(r30)
  lfs       f1, -0x64C8(r2)
  fsubs     f31, f2, f0
  fmuls     f0, f30, f30
  fmuls     f2, f31, f31
  fadds     f0, f0, f1
  fadds     f29, f2, f0
  fcmpo     cr0, f29, f1
  ble-      .loc_0xD0
  fsqrte    f1, f29
  lfd       f3, -0x64B8(r2)
  lfd       f2, -0x64B0(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f29, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f29, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f29, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f29, f0
  frsp      f0, f0
  stfs      f0, 0x40(r1)
  lfs       f29, 0x40(r1)

.loc_0xD0:
  lfs       f0, -0x64A8(r2)
  fcmpo     cr0, f29, f0
  bge-      .loc_0xEC
  lfs       f27, -0x64A4(r2)
  lfs       f28, -0x64BC(r2)
  lfs       f3, -0x64A0(r2)
  b         .loc_0x140

.loc_0xEC:
  lfs       f5, -0x64BC(r2)
  fcmpo     cr0, f29, f5
  bge-      .loc_0x134
  fsubs     f1, f29, f0
  lfs       f0, -0x6498(r2)
  lfs       f3, -0x649C(r2)
  lfs       f2, -0x6494(r2)
  fdivs     f6, f1, f0
  lfs       f0, -0x6490(r2)
  lfs       f4, -0x64A4(r2)
  lfs       f1, -0x64A0(r2)
  fmuls     f3, f3, f6
  fmuls     f2, f2, f6
  fmuls     f0, f0, f6
  fadds     f27, f4, f3
  fadds     f28, f5, f2
  fadds     f3, f1, f0
  b         .loc_0x140

.loc_0x134:
  lfs       f27, -0x648C(r2)
  lfs       f28, -0x6488(r2)
  lfs       f3, -0x6484(r2)

.loc_0x140:
  lwz       r3, 0x2DEC(r13)
  lfs       f1, -0x6480(r2)
  lfs       f0, 0x28C(r3)
  lfs       f2, 0xA0(r30)
  fmuls     f0, f1, f0
  fmuls     f0, f3, f0
  fadds     f0, f2, f0
  stfs      f0, 0xA0(r30)
  lfs       f1, 0xA0(r30)
  bl        -0xB5B2C
  stfs      f1, 0xA0(r30)
  lfs       f0, -0x32F0(r13)
  stfs      f0, 0x88(r30)
  lfs       f0, 0xA0(r30)
  stfs      f0, 0x8C(r30)
  lfs       f0, -0x32EC(r13)
  stfs      f0, 0x90(r30)
  lfs       f0, -0x64A0(r2)
  fdivs     f0, f0, f29
  fmuls     f1, f30, f0
  fmuls     f0, f31, f0
  fmuls     f1, f28, f1
  fmuls     f0, f28, f0
  stfs      f1, 0x70(r30)
  stfs      f0, 0x78(r30)
  lfs       f0, 0x98(r30)
  fcmpo     cr0, f0, f27
  bge-      .loc_0x1E4
  lfs       f3, 0x74(r30)
  lfs       f0, -0x648C(r2)
  fcmpo     cr0, f3, f0
  bge-      .loc_0x1E4
  lwz       r4, 0x2F80(r13)
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x30(r4)
  lfs       f0, 0x28C(r3)
  lfs       f2, -0x647C(r2)
  fmuls     f0, f1, f0
  fmuls     f0, f2, f0
  fadds     f0, f3, f0
  stfs      f0, 0x74(r30)

.loc_0x1E4:
  lfs       f0, -0x6478(r2)
  fcmpo     cr0, f29, f0
  bge-      .loc_0x208
  lwz       r5, 0x72C(r31)
  addi      r3, r30, 0
  li        r4, 0
  addi      r0, r5, 0x1
  stw       r0, 0x72C(r31)
  bl        -0x63474

.loc_0x208:
  mr        r3, r30
  bl        -0x627E0
  lwz       r0, 0xB4(r1)
  lfd       f31, 0xA8(r1)
  lfd       f30, 0xA0(r1)
  lfd       f29, 0x98(r1)
  lfd       f28, 0x90(r1)
  lfd       f27, 0x88(r1)
  lwz       r31, 0x84(r1)
  lwz       r30, 0x80(r1)
  addi      r1, r1, 0xB0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EE18C
 * Size:	000010
 */
void SeedItem::doAI()
{
/*
.loc_0x0:
  lwz       r0, 0x2B8(r3)
  cmpwi     r0, 0x2
  beqlr-    
  blr
*/
}

/*
 * --INFO--
 * Address:	800EE19C
 * Size:	000138
 */
void SeedItem::refresh(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xA0(r1)
  stw       r31, 0x9C(r1)
  addi      r31, r4, 0
  stw       r30, 0x98(r1)
  mr        r30, r3
  lwz       r0, 0x2B8(r3)
  cmpwi     r0, 0x2
  beq-      .loc_0x120
  addi      r3, r30, 0x228
  addi      r4, r30, 0x7C
  addi      r5, r30, 0x88
  addi      r6, r30, 0x94
  bl        -0xB00E0
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r30, 0x228
  addi      r5, r1, 0x14
  lwz       r12, 0x70(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0x14
  li        r5, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  addi      r0, r30, 0x94
  lwz       r4, 0x2E4(r31)
  neg       r3, r0
  subic     r0, r3, 0x1
  subfe     r0, r0, r3
  stb       r0, 0x154(r4)
  lbz       r0, 0x154(r4)
  cmplwi    r0, 0
  beq-      .loc_0xB0
  lwz       r3, 0x94(r30)
  lwz       r0, 0x98(r30)
  stw       r3, 0x158(r4)
  stw       r0, 0x15C(r4)
  lwz       r0, 0x9C(r30)
  stw       r0, 0x160(r4)

.loc_0xB0:
  lwz       r3, 0x2F00(r13)
  lfs       f1, 0x94(r30)
  lfs       f2, 0x9C(r30)
  bl        -0x864C0
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0x1
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x2E4(r30)
  mr        r4, r31
  lwz       r5, 0x2E4(r31)
  li        r6, 0
  bl        -0xBDE1C
  lwz       r4, 0x2E4(r31)
  li        r0, 0
  stb       r0, 0x154(r4)
  lbz       r0, 0x154(r4)
  cmplwi    r0, 0
  beq-      .loc_0x120
  lwz       r3, 0x0(r0)
  lwz       r0, 0x4(r0)
  stw       r3, 0x158(r4)
  stw       r0, 0x15C(r4)
  lwz       r0, 0x8(r0)
  stw       r0, 0x160(r4)

.loc_0x120:
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
 * Address:	800EE2D4
 * Size:	00003C
 */
void SeedItem::stimulate(Interaction &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  addi      r0, r3, 0
  addi      r3, r4, 0
  stwu      r1, -0x8(r1)
  lwz       r12, 0x0(r4)
  mr        r4, r0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  li        r3, 0x1
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EE310
 * Size:	000008
 */
void SeedItem::getHeight()
{
/*
.loc_0x0:
  lfs       f1, -0x64C8(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	800EE318
 * Size:	000008
 */
void SeedItem::getiMass()
{
/*
.loc_0x0:
  lfs       f1, -0x648C(r2)
  blr
*/
}