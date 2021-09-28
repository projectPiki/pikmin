

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
 * Address:	80143BF0
 * Size:	000084
 */
void Teki::Teki()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  extsh.    r0, r4
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  beq-      .loc_0x30
  addi      r0, r31, 0x538
  lis       r3, 0x802B
  stw       r0, 0x2C0(r31)
  subi      r0, r3, 0x246C
  stw       r0, 0x538(r31)

.loc_0x30:
  addi      r3, r31, 0
  li        r4, 0
  bl        0x5EB2C
  lis       r3, 0x802D
  subi      r3, r3, 0x33D8
  stw       r3, 0x0(r31)
  addi      r6, r3, 0x1F4
  addi      r4, r3, 0x114
  lwz       r5, 0x2C0(r31)
  addi      r0, r31, 0x538
  addi      r3, r31, 0
  stw       r6, 0x0(r5)
  stw       r4, 0x2B8(r31)
  lwz       r4, 0x2C0(r31)
  sub       r0, r0, r4
  stw       r0, 0x4(r4)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80143C74
 * Size:	00008C
 */
void YTeki::init(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  bl        0xCA8
  lfs       f0, -0x58B8(r2)
  li        r3, 0
  li        r5, 0x8
  stfs      f0, 0x478(r31)
  stw       r3, 0x498(r31)
  stw       r3, 0x49C(r31)
  stw       r3, 0x4A0(r31)
  stw       r3, 0x4A4(r31)
  stw       r3, 0x4A8(r31)
  stw       r3, 0x4AC(r31)
  stw       r3, 0x4B0(r31)
  stw       r3, 0x4B4(r31)
  b         .loc_0x6C

.loc_0x4C:
  subfic    r0, r5, 0x9
  cmpwi     r5, 0x9
  mtctr     r0
  bge-      .loc_0x78

.loc_0x5C:
  stw       r3, 0x498(r4)
  addi      r4, r4, 0x4
  bdnz+     .loc_0x5C
  b         .loc_0x78

.loc_0x6C:
  rlwinm    r0,r5,2,0,29
  add       r4, r31, r0
  b         .loc_0x4C

.loc_0x78:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80143D00
 * Size:	000008
 */
void BTeki::setTekiOptions(int)
{
/*
.loc_0x0:
  stw       r4, 0x410(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80143D08
 * Size:	00000C
 */
void BTeki::clearTekiOptions()
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x410(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80143D14
 * Size:	000010
 */
void BTeki::setAnimationKeyOption(int)
{
/*
.loc_0x0:
  lwz       r0, 0x414(r3)
  or        r0, r0, r4
  stw       r0, 0x414(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80143D24
 * Size:	000010
 */
void BTeki::clearAnimationKeyOption(int)
{
/*
.loc_0x0:
  lwz       r0, 0x414(r3)
  andc      r0, r0, r4
  stw       r0, 0x414(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80143D34
 * Size:	000008
 */
void BTeki::setAnimationKeyOptions(int)
{
/*
.loc_0x0:
  stw       r4, 0x414(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80143D3C
 * Size:	00000C
 */
void BTeki::clearAnimationKeyOptions()
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x414(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80143D48
 * Size:	000018
 */
void BTeki::getShadowSize()
{
/*
.loc_0x0:
  lwz       r3, 0x2C4(r3)
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  lwz       r3, 0x0(r3)
  lfs       f1, 0x48(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80143D60
 * Size:	00001C
 */
void BTeki::isVisible()
{
/*
.loc_0x0:
  lwz       r3, 0x410(r3)
  lwz       r0, -0x9D4(r13)
  and       r0, r3, r0
  neg       r3, r0
  subic     r0, r3, 0x1
  subfe     r3, r0, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	80143D7C
 * Size:	00001C
 */
void BTeki::isOrganic()
{
/*
.loc_0x0:
  lwz       r3, 0x410(r3)
  lwz       r0, -0x9C0(r13)
  and       r0, r3, r0
  neg       r3, r0
  subic     r0, r3, 0x1
  subfe     r3, r0, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	80143D98
 * Size:	00001C
 */
void BTeki::isAtari()
{
/*
.loc_0x0:
  lwz       r3, 0x410(r3)
  lwz       r0, -0x9C8(r13)
  and       r0, r3, r0
  neg       r3, r0
  subic     r0, r3, 0x1
  subfe     r3, r0, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	80143DB4
 * Size:	00001C
 */
void BTeki::isAlive()
{
/*
.loc_0x0:
  lwz       r3, 0x410(r3)
  lwz       r0, -0x9C4(r13)
  and       r0, r3, r0
  neg       r3, r0
  subic     r0, r3, 0x1
  subfe     r3, r0, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	80143DD0
 * Size:	00001C
 */
void BTeki::needShadow()
{
/*
.loc_0x0:
  lwz       r3, 0x410(r3)
  lwz       r0, -0x9D0(r13)
  and       r0, r3, r0
  neg       r3, r0
  subic     r0, r3, 0x1
  subfe     r3, r0, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	80143DEC
 * Size:	000014
 */
void BTeki::@1336@4@animationKeyUpdated(PaniAnimKeyEvent &)
{
/*
.loc_0x0:
  li        r11, 0x4
  lwzx      r11, r3, r11
  add       r3, r3, r11
  subi      r3, r3, 0x538
  b         0x13E4
*/
}

/*
 * --INFO--
 * Address:	80143E00
 * Size:	000008
 */
void BTeki::@696@viewGetScale()
{
/*
.loc_0x0:
  subi      r4, r4, 0x2B8
  b         0x23C
*/
}

/*
 * --INFO--
 * Address:	80143E08
 * Size:	000008
 */
void BTeki::@696@viewGetHeight()
{
/*
.loc_0x0:
  subi      r3, r3, 0x2B8
  b         0x268
*/
}

/*
 * --INFO--
 * Address:	80143E10
 * Size:	000008
 */
void BTeki::@696@viewGetBottomRadius()
{
/*
.loc_0x0:
  subi      r3, r3, 0x2B8
  b         0x248
*/
}

/*
 * --INFO--
 * Address:	80143E18
 * Size:	000008
 */
void BTeki::@696@viewDoAnimation()
{
/*
.loc_0x0:
  subi      r3, r3, 0x2B8
  b         0x1AC
*/
}

/*
 * --INFO--
 * Address:	80143E20
 * Size:	000008
 */
void BTeki::@696@viewFinishMotion()
{
/*
.loc_0x0:
  subi      r3, r3, 0x2B8
  b         0x1D0
*/
}

/*
 * --INFO--
 * Address:	80143E28
 * Size:	000008
 */
void BTeki::@696@viewSetMotionSpeed(float)
{
/*
.loc_0x0:
  subi      r3, r3, 0x2B8
  b         0x194
*/
}

/*
 * --INFO--
 * Address:	80143E30
 * Size:	000008
 */
void BTeki::@696@viewStartTrembleMotion(float)
{
/*
.loc_0x0:
  subi      r3, r3, 0x2B8
  b         0x128
*/
}

/*
 * --INFO--
 * Address:	80143E38
 * Size:	000008
 */
void BTeki::@696@viewDraw(Graphics &, Matrix4f &)
{
/*
.loc_0x0:
  subi      r3, r3, 0x2B8
  b         0x250
*/
}

/*
 * --INFO--
 * Address:	80143E40
 * Size:	000008
 */
void BTeki::@696@viewKill()
{
/*
.loc_0x0:
  subi      r3, r3, 0x2B8
  b         0x2EC
*/
}