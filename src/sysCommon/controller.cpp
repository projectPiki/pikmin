

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
 * Address:	800409B0
 * Size:	000024
 */
void Controller::reset(unsigned long)
{
/*
.loc_0x0:
  li        r0, -0x1
  stw       r0, 0x3C(r3)
  li        r0, 0
  stb       r0, 0x44(r3)
  stw       r4, 0x38(r3)
  stw       r0, 0x40(r3)
  stw       r0, 0x20(r3)
  stw       r0, 0x24(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800409D4
 * Size:	00009C
 */
void Controller::updateCont(unsigned long)
{
/*
.loc_0x0:
  lwz       r5, 0x20(r3)
  li        r0, 0
  stw       r5, 0x24(r3)
  stw       r0, 0x20(r3)
  lbz       r0, 0x44(r3)
  cmplwi    r0, 0
  bne-      .loc_0x20
  stw       r4, 0x20(r3)

.loc_0x20:
  lwz       r4, 0x20(r3)
  lwz       r0, 0x24(r3)
  andc      r0, r4, r0
  stw       r0, 0x28(r3)
  lwz       r4, 0x24(r3)
  lwz       r0, 0x20(r3)
  andc      r0, r4, r0
  stw       r0, 0x2C(r3)
  lwz       r4, 0x40(r3)
  cmplwi    r4, 0
  beq-      .loc_0x78
  subic.    r0, r4, 0x1
  stw       r0, 0x40(r3)
  beqlr-    
  lwz       r4, 0x34(r3)
  lwz       r0, 0x28(r3)
  and.      r0, r4, r0
  stw       r0, 0x30(r3)
  beqlr-    
  li        r0, 0
  stw       r0, 0x40(r3)
  blr       

.loc_0x78:
  li        r0, 0
  stw       r0, 0x30(r3)
  lwz       r0, 0x28(r3)
  cmplwi    r0, 0
  stw       r0, 0x34(r3)
  beqlr-    
  li        r0, 0xA
  stw       r0, 0x40(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80040A70
 * Size:	00002C
 */
void Controller::update()
{
/*
.loc_0x0:
  mflr      r0
  addi      r4, r3, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0x2DEC(r13)
  addi      r3, r5, 0x27C
  bl        0x6838
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80040A9C
 * Size:	000038
 */
void Controller::getMainStickX()
{
/*
.loc_0x0:
  stwu      r1, -0x18(r1)
  lis       r0, 0x4330
  lbz       r3, 0x45(r3)
  lfd       f2, -0x7C00(r2)
  extsb     r3, r3
  lfs       f0, -0x7C08(r2)
  xoris     r3, r3, 0x8000
  stw       r3, 0x14(r1)
  stw       r0, 0x10(r1)
  lfd       f1, 0x10(r1)
  fsubs     f1, f1, f2
  fdivs     f1, f1, f0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	80040AD4
 * Size:	000038
 */
void Controller::getMainStickY()
{
/*
.loc_0x0:
  stwu      r1, -0x18(r1)
  lis       r0, 0x4330
  lbz       r3, 0x46(r3)
  lfd       f2, -0x7C00(r2)
  extsb     r3, r3
  lfs       f0, -0x7C08(r2)
  xoris     r3, r3, 0x8000
  stw       r3, 0x14(r1)
  stw       r0, 0x10(r1)
  lfd       f1, 0x10(r1)
  fsubs     f1, f1, f2
  fdivs     f1, f1, f0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	80040B0C
 * Size:	000038
 */
void Controller::getSubStickX()
{
/*
.loc_0x0:
  stwu      r1, -0x18(r1)
  lis       r0, 0x4330
  lbz       r3, 0x47(r3)
  lfd       f2, -0x7C00(r2)
  extsb     r3, r3
  lfs       f0, -0x7C08(r2)
  xoris     r3, r3, 0x8000
  stw       r3, 0x14(r1)
  stw       r0, 0x10(r1)
  lfd       f1, 0x10(r1)
  fsubs     f1, f1, f2
  fdivs     f1, f1, f0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	80040B44
 * Size:	000038
 */
void Controller::getSubStickY()
{
/*
.loc_0x0:
  stwu      r1, -0x18(r1)
  lis       r0, 0x4330
  lbz       r3, 0x48(r3)
  lfd       f2, -0x7C00(r2)
  extsb     r3, r3
  lfs       f0, -0x7C08(r2)
  xoris     r3, r3, 0x8000
  stw       r3, 0x14(r1)
  stw       r0, 0x10(r1)
  lfd       f1, 0x10(r1)
  fsubs     f1, f1, f2
  fdivs     f1, f1, f0
  addi      r1, r1, 0x18
  blr
*/
}