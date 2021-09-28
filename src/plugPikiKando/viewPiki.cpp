

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
 * Address:	800D8894
 * Size:	000028
 */
void PikiShapeObject::exitCourse()
{
/*
.loc_0x0:
  li        r0, 0x1
  lis       r3, 0x803D
  stb       r0, -0x3B90(r13)
  addi      r3, r3, 0x1E48
  li        r0, 0
  stw       r0, 0xC(r3)
  stw       r0, 0x8(r3)
  stw       r0, 0x4(r3)
  stw       r0, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800D88BC
 * Size:	000028
 */
void PikiShapeObject::init()
{
/*
.loc_0x0:
  li        r0, 0x1
  lis       r3, 0x803D
  stb       r0, -0x3B90(r13)
  addi      r3, r3, 0x1E48
  li        r0, 0
  stw       r0, 0xC(r3)
  stw       r0, 0x8(r3)
  stw       r0, 0x4(r3)
  stw       r0, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void PikiShapeObject::create(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800D88E4
 * Size:	00003C
 */
void PikiShapeObject::getAnimMgr()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lbz       r0, -0x3B90(r13)
  cmplwi    r0, 0
  beq-      .loc_0x1C
  bl        .loc_0x3C

.loc_0x1C:
  lis       r3, 0x803D
  addi      r3, r3, 0x1E48
  lwz       r3, 0x0(r3)
  lwz       r3, 0x24(r3)
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr       

.loc_0x3C:
*/
}

/*
 * --INFO--
 * Address:	800D8920
 * Size:	0001B4
 */
void PikiShapeObject::initOnce()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802C
  stw       r0, 0x4(r1)
  lis       r3, 0x803D
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0x1E48
  li        r3, 0x28
  stw       r30, 0x10(r1)
  subi      r30, r4, 0x5CE0
  stw       r29, 0xC(r1)
  stw       r28, 0x8(r1)
  bl        -0x9194C
  addi      r29, r3, 0
  mr.       r28, r29
  beq-      .loc_0x60
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r30, 0x2C
  li        r5, 0x1
  bl        -0x85C60
  addi      r4, r3, 0
  addi      r3, r28, 0
  bl        .loc_0x1B4

.loc_0x60:
  stw       r29, 0x0(r31)
  li        r3, 0xB8
  bl        -0x91984
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x94
  lwz       r4, 0x0(r31)
  lis       r6, 0x1
  addi      r5, r30, 0x40
  lwz       r4, 0x0(r4)
  subi      r6, r6, 0x8000
  li        r7, 0
  bl        -0x8810C

.loc_0x94:
  lwz       r4, 0x0(r31)
  lis       r3, 0x803A
  subi      r29, r3, 0x2848
  stw       r28, 0x24(r4)
  addi      r3, r29, 0
  addi      r4, r30, 0x54
  lwz       r5, 0x0(r31)
  lwz       r5, 0x24(r5)
  bl        -0x85C74
  li        r3, 0x28
  bl        -0x919D8
  mr.       r28, r3
  beq-      .loc_0xE4
  addi      r3, r29, 0
  addi      r4, r30, 0x60
  li        r5, 0x1
  bl        -0x85CE4
  addi      r4, r3, 0
  addi      r3, r28, 0
  bl        .loc_0x1B4

.loc_0xE4:
  addi      r4, r31, 0x4
  stw       r28, 0x4(r31)
  li        r3, 0x28
  lwz       r5, 0x0(r31)
  lwz       r4, 0x0(r4)
  lwz       r0, 0x24(r5)
  stw       r0, 0x24(r4)
  bl        -0x91A1C
  mr.       r28, r3
  beq-      .loc_0x12C
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r30, 0x74
  li        r5, 0x1
  bl        -0x85D2C
  addi      r4, r3, 0
  addi      r3, r28, 0
  bl        .loc_0x1B4

.loc_0x12C:
  addi      r4, r31, 0x8
  stw       r28, 0x8(r31)
  li        r3, 0x28
  lwz       r5, 0x0(r31)
  lwz       r4, 0x0(r4)
  lwz       r0, 0x24(r5)
  stw       r0, 0x24(r4)
  bl        -0x91A64
  mr.       r28, r3
  beq-      .loc_0x174
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r30, 0x88
  li        r5, 0x1
  bl        -0x85D74
  addi      r4, r3, 0
  addi      r3, r28, 0
  bl        .loc_0x1B4

.loc_0x174:
  addi      r3, r31, 0xC
  stw       r28, 0xC(r31)
  li        r0, 0
  lwz       r4, 0x0(r31)
  lwz       r3, 0x0(r3)
  lwz       r4, 0x24(r4)
  stw       r4, 0x24(r3)
  stb       r0, -0x3B90(r13)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  lwz       r29, 0xC(r1)
  lwz       r28, 0x8(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr       

.loc_0x1B4:
*/
}

/*
 * --INFO--
 * Address:	800D8AD4
 * Size:	00009C
 */
void PikiShapeObject::PikiShapeObject(Shape *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x8023
  stw       r0, 0x4(r1)
  subi      r0, r5, 0x7730
  li        r6, 0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  addi      r5, r31, 0x4
  stw       r0, 0x10(r3)
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  stw       r6, 0x4(r31)
  lfs       f1, -0x6818(r2)
  stfs      f1, 0x8(r31)
  lfs       f0, -0x6814(r2)
  stfs      f0, 0xC(r31)
  stw       r0, 0x20(r31)
  stw       r6, 0x14(r31)
  stfs      f1, 0x18(r31)
  stfs      f0, 0x1C(r31)
  stw       r4, 0x0(r31)
  li        r4, 0
  lwz       r0, 0x308(r3)
  lwz       r3, 0x0(r31)
  stw       r0, 0x24(r3)
  stw       r6, 0x24(r31)
  lwz       r3, 0x0(r31)
  bl        -0xA3AE0
  lwz       r3, 0x0(r31)
  addi      r5, r31, 0x14
  li        r4, 0x1
  bl        -0xA3AF0
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800D8B70
 * Size:	000020
 */
void ViewPiki::isKinoko()
{
/*
.loc_0x0:
  lis       r4, 0x803D
  lwz       r5, 0x588(r3)
  addi      r3, r4, 0x1E48
  lwz       r0, 0xC(r3)
  sub       r0, r0, r5
  cntlzw    r0, r0
  rlwinm    r3,r0,27,5,31
  blr
*/
}

/*
 * --INFO--
 * Address:	800D8B90
 * Size:	000128
 */
void ViewPiki::changeShape(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r4, 0
  cmpwi     r31, -0x1
  stw       r30, 0x20(r1)
  addi      r30, r3, 0
  bne-      .loc_0x28
  lwz       r31, 0x4B8(r30)

.loc_0x28:
  lis       r4, 0x802C
  lwz       r3, 0x2FE8(r13)
  subi      r4, r4, 0x5CC4
  bl        -0x5248C
  lbz       r0, -0x3B90(r13)
  cmplwi    r0, 0
  beq-      .loc_0x48
  bl        -0x2B4

.loc_0x48:
  lis       r4, 0x802C
  lwz       r3, 0x2FE8(r13)
  subi      r4, r4, 0x5CC4
  bl        -0x5239C
  lis       r3, 0x803D
  rlwinm    r4,r31,2,0,29
  addi      r0, r3, 0x1E48
  add       r3, r0, r4
  lwz       r0, 0x0(r3)
  addi      r3, r30, 0x354
  stw       r0, 0x588(r30)
  lwz       r5, 0x588(r30)
  addi      r4, r5, 0x14
  addi      r5, r5, 0x4
  bl        0x46D48
  lwz       r4, 0x588(r30)
  li        r5, 0
  lwz       r3, 0x220(r30)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0x4F0C4
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lwz       r12, 0x120(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD0
  mr        r3, r30
  lhz       r4, 0x510(r30)
  bl        -0xF280
  li        r0, 0
  stw       r0, 0x598(r30)
  b         .loc_0xE8

.loc_0xD0:
  mr        r3, r30
  lwz       r4, 0x520(r30)
  lwz       r12, 0x0(r30)
  lwz       r12, 0x130(r12)
  mtlr      r12
  blrl      

.loc_0xE8:
  lfs       f0, -0x6810(r2)
  addi      r3, r30, 0
  addi      r4, r31, 0x1
  stfs      f0, 0x7C(r30)
  stfs      f0, 0x80(r30)
  stfs      f0, 0x84(r30)
  lwz       r12, 0x0(r30)
  lwz       r12, 0x134(r12)
  mtlr      r12
  blrl      
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
 * Address:	800D8CB8
 * Size:	000060
 */
void ViewPiki::ViewPiki(CreatureProp *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        -0xD368
  lis       r3, 0x802C
  subi      r3, r3, 0x5B98
  stw       r3, 0x0(r31)
  addi      r3, r3, 0x114
  li        r0, 0
  stw       r3, 0x2B8(r31)
  mr        r3, r31
  lfs       f0, -0x6818(r2)
  stfs      f0, 0x594(r31)
  stfs      f0, 0x590(r31)
  stfs      f0, 0x58C(r31)
  stw       r0, 0x588(r31)
  stw       r0, 0x520(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800D8D18
 * Size:	0000B4
 */
void ViewPiki::initBirth()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r3, 0
  stw       r0, 0x598(r3)
  lis       r3, 0x802C
  subi      r4, r3, 0x5CC4
  lwz       r3, 0x2FE8(r13)
  bl        -0x52608
  lbz       r0, -0x3B90(r13)
  cmplwi    r0, 0
  beq-      .loc_0x3C
  bl        -0x430

.loc_0x3C:
  lis       r4, 0x802C
  lwz       r3, 0x2FE8(r13)
  subi      r4, r4, 0x5CC4
  bl        -0x52518
  lis       r3, 0x803D
  lwz       r0, 0x1E48(r3)
  addi      r3, r31, 0x354
  stw       r0, 0x588(r31)
  lwz       r8, 0x588(r31)
  lwz       r6, 0x3068(r13)
  lwz       r4, 0x24(r8)
  addi      r5, r8, 0x14
  lwz       r7, 0x64(r6)
  addi      r6, r8, 0x4
  bl        0x46B50
  lfs       f0, -0x6810(r2)
  addi      r3, r31, 0
  li        r4, 0
  stfs      f0, 0x7C(r31)
  stfs      f0, 0x80(r31)
  stfs      f0, 0x84(r31)
  lwz       r12, 0x0(r31)
  lwz       r12, 0x130(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800D8DCC
 * Size:	00026C
 */
void ViewPiki::init(Shape *, MapMgr *, Navi *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802C
  stw       r0, 0x4(r1)
  subi      r4, r4, 0x5CC4
  stwu      r1, -0x78(r1)
  stfd      f31, 0x70(r1)
  stw       r31, 0x6C(r1)
  addi      r31, r6, 0
  stw       r30, 0x68(r1)
  addi      r30, r3, 0
  stw       r29, 0x64(r1)
  stw       r28, 0x60(r1)
  lwz       r3, 0x2FE8(r13)
  bl        -0x526C8
  lbz       r0, -0x3B90(r13)
  cmplwi    r0, 0
  beq-      .loc_0x48
  bl        -0x4F0

.loc_0x48:
  lis       r4, 0x802C
  lwz       r3, 0x2FE8(r13)
  subi      r4, r4, 0x5CC4
  bl        -0x525D8
  lis       r3, 0x803D
  lwz       r4, 0x1E48(r3)
  li        r0, 0
  li        r3, 0x14
  stw       r4, 0x588(r30)
  stw       r0, 0x598(r30)
  bl        -0x91E38
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x88
  li        r4, 0x4
  bl        -0x50220

.loc_0x88:
  stw       r29, 0x220(r30)
  li        r5, 0
  li        r6, 0
  lwz       r4, 0x588(r30)
  lwz       r3, 0x220(r30)
  lwz       r4, 0x0(r4)
  bl        -0x4F308
  lwz       r8, 0x588(r30)
  addi      r3, r30, 0x354
  lwz       r6, 0x3068(r13)
  lwz       r4, 0x24(r8)
  addi      r5, r8, 0x14
  lwz       r7, 0x64(r6)
  addi      r6, r8, 0x4
  bl        0x46A50
  lwz       r5, 0x3068(r13)
  mr        r3, r30
  lfs       f1, -0x6810(r2)
  li        r4, 0x1
  lwz       r5, 0x68(r5)
  lfs       f0, 0x138(r5)
  fmuls     f1, f1, f0
  stfs      f1, 0x7C(r30)
  stfs      f1, 0x80(r30)
  stfs      f1, 0x84(r30)
  lwz       r12, 0x0(r30)
  lwz       r12, 0x134(r12)
  mtlr      r12
  blrl      
  cmplwi    r30, 0
  addi      r28, r30, 0
  beq-      .loc_0x10C
  addi      r28, r28, 0x2B8

.loc_0x10C:
  addi      r3, r1, 0x3C
  li        r4, 0x16
  bl        0x46078
  addi      r29, r3, 0
  addi      r5, r28, 0
  addi      r3, r1, 0x44
  li        r4, 0x16
  bl        0x46098
  addi      r4, r3, 0
  addi      r5, r29, 0
  addi      r3, r30, 0x354
  bl        0x46B64
  lfs       f0, -0x3B8C(r13)
  stfs      f0, 0x7C(r30)
  lfs       f0, -0x3B88(r13)
  stfs      f0, 0x80(r30)
  lfs       f0, -0x3B84(r13)
  stfs      f0, 0x84(r30)
  lfs       f0, -0x3B80(r13)
  stfs      f0, 0x88(r30)
  lfs       f0, -0x3B7C(r13)
  stfs      f0, 0x8C(r30)
  lfs       f0, -0x3B78(r13)
  stfs      f0, 0x90(r30)
  bl        0x13F138
  xoris     r0, r3, 0x8000
  lfd       f3, -0x6800(r2)
  stw       r0, 0x5C(r1)
  lis       r29, 0x4330
  lfs       f1, -0x680C(r2)
  stw       r29, 0x58(r1)
  lfs       f0, -0x6810(r2)
  lfd       f2, 0x58(r1)
  fsubs     f2, f2, f3
  fdivs     f1, f2, f1
  fmuls     f31, f0, f1
  bl        0x13F108
  xoris     r0, r3, 0x8000
  lfs       f1, -0x6804(r2)
  stw       r0, 0x54(r1)
  addi      r3, r30, 0x228
  lfd       f5, -0x6800(r2)
  fsubs     f0, f31, f1
  stw       r29, 0x50(r1)
  lfs       f2, -0x6808(r2)
  addi      r4, r30, 0x7C
  lfd       f3, 0x50(r1)
  lfs       f4, -0x680C(r2)
  fmuls     f0, f2, f0
  fsubs     f5, f3, f5
  lfs       f3, -0x6810(r2)
  addi      r5, r30, 0x88
  addi      r6, r30, 0x94
  fdivs     f4, f5, f4
  fmuls     f3, f3, f4
  fsubs     f1, f3, f1
  fmuls     f1, f2, f1
  stfs      f1, 0x94(r30)
  lfs       f1, -0x3B74(r13)
  stfs      f1, 0x98(r30)
  stfs      f0, 0x9C(r30)
  bl        -0x9AED8
  lfs       f0, -0x6818(r2)
  addi      r3, r30, 0
  addi      r4, r31, 0
  stfs      f0, 0x268(r30)
  bl        -0xCF9C
  lwz       r3, 0x94(r30)
  lwz       r0, 0x98(r30)
  stw       r3, 0x1AC(r30)
  stw       r0, 0x1B0(r30)
  lwz       r0, 0x9C(r30)
  stw       r0, 0x1B4(r30)
  lwz       r3, 0x94(r30)
  lwz       r0, 0x98(r30)
  stw       r3, 0x58C(r30)
  stw       r0, 0x590(r30)
  lwz       r0, 0x9C(r30)
  stw       r0, 0x594(r30)
  lwz       r0, 0x7C(r1)
  lfd       f31, 0x70(r1)
  lwz       r31, 0x6C(r1)
  lwz       r30, 0x68(r1)
  lwz       r29, 0x64(r1)
  lwz       r28, 0x60(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800D9038
 * Size:	000064
 */
void ViewPiki::setFlower(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r4
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r12, 0x0(r30)
  lwz       r12, 0x120(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x4C
  stw       r31, 0x520(r30)
  rlwinm    r0,r31,2,0,29
  lwz       r3, 0x3068(r13)
  add       r3, r3, r0
  lwz       r0, 0x3C(r3)
  stw       r0, 0x598(r30)

.loc_0x4C:
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
 * Address:	800D909C
 * Size:	000004
 */
void ViewPiki::setLeaves(int)
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	800D90A0
 * Size:	00017C
 */
void ViewPiki::postUpdate(int, float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x80(r1)
  stfd      f31, 0x78(r1)
  fmr       f31, f1
  stw       r31, 0x74(r1)
  addi      r31, r4, 0
  stw       r30, 0x70(r1)
  mr        r30, r3
  lhz       r5, 0x4FC(r3)
  cmplwi    r5, 0
  bne-      .loc_0x40
  lwz       r3, 0x3068(r13)
  lhz       r0, 0x70(r3)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x160

.loc_0x40:
  cmplwi    r5, 0x1
  bne-      .loc_0x58
  lwz       r3, 0x3068(r13)
  lhz       r0, 0x70(r3)
  rlwinm.   r0,r0,0,30,30
  beq-      .loc_0x160

.loc_0x58:
  lwz       r3, 0x3068(r13)
  lhz       r4, 0x70(r3)
  rlwinm.   r0,r4,0,29,29
  beq-      .loc_0x160
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r3, 0x1DC(r3)
  lbz       r0, 0x124(r3)
  cmplwi    r0, 0
  beq-      .loc_0x150
  rlwinm.   r0,r4,0,28,28
  beq-      .loc_0x150
  lwz       r3, 0x30AC(r13)
  bl        0x19B0C
  lwz       r12, 0x0(r3)
  mr        r4, r3
  addi      r3, r1, 0x44
  lwz       r12, 0x15C(r12)
  mtlr      r12
  blrl      
  lfs       f3, 0x98(r30)
  lfs       f2, 0x48(r1)
  lfs       f1, 0x94(r30)
  lfs       f0, 0x44(r1)
  fsubs     f3, f3, f2
  lfs       f2, 0x9C(r30)
  fsubs     f4, f1, f0
  lfs       f0, 0x4C(r1)
  fmuls     f1, f3, f3
  fsubs     f3, f2, f0
  lfs       f0, -0x6818(r2)
  fmuls     f2, f4, f4
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x144
  fsqrte    f1, f4
  lfd       f3, -0x67F8(r2)
  lfd       f2, -0x67F0(r2)
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
  stfs      f0, 0x30(r1)
  lfs       f4, 0x30(r1)

.loc_0x144:
  lfs       f0, -0x67E8(r2)
  fcmpo     cr0, f4, f0
  bgt-      .loc_0x160

.loc_0x150:
  fmr       f1, f31
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        -0x4DA74

.loc_0x160:
  lwz       r0, 0x84(r1)
  lfd       f31, 0x78(r1)
  lwz       r31, 0x74(r1)
  lwz       r30, 0x70(r1)
  addi      r1, r1, 0x80
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800D921C
 * Size:	000408
 */
void ViewPiki::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x100(r1)
  stw       r31, 0xFC(r1)
  mr        r31, r3
  lhz       r4, 0x4FC(r3)
  cmplwi    r4, 0
  bne-      .loc_0x4C
  lwz       r3, 0x3068(r13)
  lhz       r0, 0x70(r3)
  rlwinm.   r0,r0,0,31,31
  bne-      .loc_0x4C
  lfs       f0, -0x3B70(r13)
  stfs      f0, 0xBC(r31)
  lfs       f0, -0x3B6C(r13)
  stfs      f0, 0xC0(r31)
  lfs       f0, -0x3B68(r13)
  stfs      f0, 0xC4(r31)
  b         .loc_0x3F4

.loc_0x4C:
  cmplwi    r4, 0x1
  bne-      .loc_0x80
  lwz       r3, 0x3068(r13)
  lhz       r0, 0x70(r3)
  rlwinm.   r0,r0,0,30,30
  bne-      .loc_0x80
  lfs       f0, -0x3B64(r13)
  stfs      f0, 0xBC(r31)
  lfs       f0, -0x3B60(r13)
  stfs      f0, 0xC0(r31)
  lfs       f0, -0x3B5C(r13)
  stfs      f0, 0xC4(r31)
  b         .loc_0x3F4

.loc_0x80:
  lwz       r3, 0x3068(r13)
  lhz       r4, 0x70(r3)
  rlwinm.   r0,r4,0,29,29
  bne-      .loc_0xAC
  lfs       f0, -0x3B58(r13)
  stfs      f0, 0xBC(r31)
  lfs       f0, -0x3B54(r13)
  stfs      f0, 0xC0(r31)
  lfs       f0, -0x3B50(r13)
  stfs      f0, 0xC4(r31)
  b         .loc_0x3F4

.loc_0xAC:
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r3, 0x1DC(r3)
  lbz       r0, 0x124(r3)
  cmplwi    r0, 0
  beq-      .loc_0x1B0
  rlwinm.   r0,r4,0,28,28
  beq-      .loc_0x1B0
  lwz       r3, 0x30AC(r13)
  bl        0x1994C
  lwz       r12, 0x0(r3)
  mr        r4, r3
  addi      r3, r1, 0x78
  lwz       r12, 0x15C(r12)
  mtlr      r12
  blrl      
  lfs       f3, 0x98(r31)
  lfs       f2, 0x7C(r1)
  lfs       f1, 0x94(r31)
  lfs       f0, 0x78(r1)
  fsubs     f3, f3, f2
  lfs       f2, 0x9C(r31)
  fsubs     f4, f1, f0
  lfs       f0, 0x80(r1)
  fmuls     f1, f3, f3
  fsubs     f3, f2, f0
  lfs       f0, -0x6818(r2)
  fmuls     f2, f4, f4
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x188
  fsqrte    f1, f4
  lfd       f3, -0x67F8(r2)
  lfd       f2, -0x67F0(r2)
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
  stfs      f0, 0x4C(r1)
  lfs       f4, 0x4C(r1)

.loc_0x188:
  lfs       f0, -0x67E8(r2)
  fcmpo     cr0, f4, f0
  ble-      .loc_0x1B0
  lfs       f0, -0x3B4C(r13)
  stfs      f0, 0xBC(r31)
  lfs       f0, -0x3B48(r13)
  stfs      f0, 0xC0(r31)
  lfs       f0, -0x3B44(r13)
  stfs      f0, 0xC4(r31)
  b         .loc_0x3F4

.loc_0x1B0:
  mr        r3, r31
  bl        -0xF834
  li        r0, 0
  stw       r0, 0x1A4(r31)
  mr        r3, r31
  bl        -0x4E1D8
  mr        r3, r31
  bl        -0xC87C
  lhz       r4, 0x510(r31)
  cmplwi    r4, 0
  bne-      .loc_0x1F0
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r0, 0x1D8(r3)
  rlwinm.   r0,r0,0,28,28
  bne-      .loc_0x3F4

.loc_0x1F0:
  cmplwi    r4, 0x1
  bne-      .loc_0x20C
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r0, 0x1D8(r3)
  rlwinm.   r0,r0,0,27,27
  bne-      .loc_0x3F4

.loc_0x20C:
  cmplwi    r4, 0x2
  bne-      .loc_0x228
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r0, 0x1D8(r3)
  rlwinm.   r0,r0,0,26,26
  bne-      .loc_0x3F4

.loc_0x228:
  lwz       r0, -0x5F04(r13)
  cmpwi     r0, 0
  bne-      .loc_0x3F4
  lwz       r0, 0x28C(r31)
  cmplwi    r0, 0
  beq-      .loc_0x3F4
  bl        0x13EC14
  xoris     r0, r3, 0x8000
  lfd       f4, -0x6800(r2)
  stw       r0, 0xF4(r1)
  lis       r0, 0x4330
  lfs       f2, -0x680C(r2)
  stw       r0, 0xF0(r1)
  lfs       f1, -0x6810(r2)
  lfd       f3, 0xF0(r1)
  lfs       f0, -0x67E4(r2)
  fsubs     f3, f3, f4
  fdivs     f2, f3, f2
  fmuls     f1, f1, f2
  fcmpo     cr0, f1, f0
  ble-      .loc_0x3F4
  lfs       f3, 0x590(r31)
  lfs       f2, 0x98(r31)
  lfs       f1, 0x58C(r31)
  lfs       f0, 0x94(r31)
  fsubs     f3, f3, f2
  lfs       f2, 0x594(r31)
  fsubs     f4, f1, f0
  lfs       f0, 0x9C(r31)
  fmuls     f1, f3, f3
  fsubs     f3, f2, f0
  lfs       f0, -0x6818(r2)
  fmuls     f2, f4, f4
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x318
  fsqrte    f1, f4
  lfd       f3, -0x67F8(r2)
  lfd       f2, -0x67F0(r2)
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
  stfs      f0, 0x48(r1)
  lfs       f4, 0x48(r1)

.loc_0x318:
  lfs       f0, -0x67E0(r2)
  fcmpo     cr0, f4, f0
  ble-      .loc_0x3F4
  lfs       f0, 0x94(r31)
  lfs       f4, -0x6810(r2)
  stfs      f0, 0xC8(r1)
  lfs       f3, -0x67DC(r2)
  lfs       f0, 0x98(r31)
  lfs       f1, -0x3B40(r13)
  fadds     f2, f4, f0
  lfs       f0, -0x6818(r2)
  stfs      f2, 0xCC(r1)
  lfs       f2, 0x9C(r31)
  stfs      f2, 0xD0(r1)
  lfs       f2, 0x70(r31)
  fmuls     f2, f3, f2
  stfs      f2, 0xBC(r1)
  stfs      f1, 0xC0(r1)
  lfs       f1, 0x78(r31)
  stfs      f0, 0x98(r1)
  fmuls     f1, f3, f1
  stfs      f0, 0x94(r1)
  stfs      f0, 0x90(r1)
  stfs      f0, 0xA4(r1)
  stfs      f1, 0xC4(r1)
  stfs      f0, 0xA0(r1)
  stfs      f0, 0x9C(r1)
  lwz       r0, 0xC8(r1)
  lwz       r3, 0xCC(r1)
  stw       r0, 0x90(r1)
  lwz       r0, 0xD0(r1)
  stw       r3, 0x94(r1)
  lwz       r3, 0xBC(r1)
  stw       r0, 0x98(r1)
  lwz       r0, 0xC0(r1)
  stw       r3, 0x9C(r1)
  stw       r0, 0xA0(r1)
  lwz       r0, 0xC4(r1)
  stw       r0, 0xA4(r1)
  stfs      f4, 0xB4(r1)
  lwz       r3, 0x28C(r31)
  bl        0x3CAA8
  cmpwi     r3, 0
  blt-      .loc_0x3DC
  cmpwi     r3, 0x3
  bgt-      .loc_0x3DC
  addi      r3, r3, 0x3
  addi      r4, r1, 0x90
  bl        0x3ACEC

.loc_0x3DC:
  lwz       r3, 0x94(r31)
  lwz       r0, 0x98(r31)
  stw       r3, 0x58C(r31)
  stw       r0, 0x590(r31)
  lwz       r0, 0x9C(r31)
  stw       r0, 0x594(r31)

.loc_0x3F4:
  lwz       r0, 0x104(r1)
  lwz       r31, 0xFC(r1)
  addi      r1, r1, 0x100
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800D9624
 * Size:	0000A0
 */
void Piki::startHimaLook(Vector3f *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  mr        r30, r3
  stw       r4, 0x33C(r3)
  stb       r31, 0x340(r3)
  stb       r31, 0x330(r3)
  lwz       r3, 0x338(r3)
  cmplwi    r3, 0
  beq-      .loc_0x3C
  bl        0xAD14
  stw       r31, 0x338(r30)

.loc_0x3C:
  li        r0, 0x1
  stb       r0, 0x330(r30)
  bl        0x13EA08
  xoris     r0, r3, 0x8000
  lfd       f4, -0x6800(r2)
  stw       r0, 0x1C(r1)
  lis       r0, 0x4330
  lfs       f3, -0x680C(r2)
  stw       r0, 0x18(r1)
  lfs       f2, -0x6810(r2)
  lfd       f1, 0x18(r1)
  lfs       f0, -0x67D4(r2)
  fsubs     f4, f1, f4
  lfs       f1, -0x67D8(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x334(r30)
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
 * Address:	800D96C4
 * Size:	000018
 */
void Piki::finishLook()
{
/*
.loc_0x0:
  li        r4, 0
  stw       r4, 0x33C(r3)
  li        r0, 0xA
  stb       r0, 0x340(r3)
  stb       r4, 0x330(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800D96DC
 * Size:	000014
 */
void Piki::isLooking()
{
/*
.loc_0x0:
  lwz       r0, 0x33C(r3)
  neg       r3, r0
  subic     r0, r3, 0x1
  subfe     r3, r0, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	800D96F0
 * Size:	000378
 */
void Piki::updateLook()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x70(r1)
  stfd      f31, 0x68(r1)
  stfd      f30, 0x60(r1)
  stfd      f29, 0x58(r1)
  stfd      f28, 0x50(r1)
  stw       r31, 0x4C(r1)
  stw       r30, 0x48(r1)
  mr        r30, r3
  lwz       r3, 0x33C(r3)
  lfs       f29, -0x67D0(r2)
  cmplwi    r3, 0
  beq-      .loc_0xF0
  lfs       f3, 0x8(r3)
  lfs       f1, 0x9C(r30)
  lfs       f2, 0x0(r3)
  lfs       f0, 0x94(r30)
  fsubs     f28, f3, f1
  lfs       f1, 0x4(r3)
  fsubs     f30, f2, f0
  lfs       f0, 0x98(r30)
  fmr       f2, f28
  fsubs     f31, f1, f0
  fmr       f1, f30
  bl        0x1422A4
  fmuls     f3, f30, f30
  lfs       f0, -0x6818(r2)
  fmuls     f2, f28, f28
  fmr       f30, f1
  fadds     f4, f3, f2
  fcmpo     cr0, f4, f0
  ble-      .loc_0xDC
  fsqrte    f1, f4
  lfd       f3, -0x67F8(r2)
  lfd       f2, -0x67F0(r2)
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
  stfs      f0, 0x28(r1)
  lfs       f4, 0x28(r1)

.loc_0xDC:
  fmr       f2, f4
  fmr       f1, f31
  bl        0x142224
  fmr       f31, f1
  b         .loc_0x18C

.loc_0xF0:
  lfs       f28, -0x67CC(r2)
  lfs       f1, -0x6818(r2)
  lfs       f2, 0x344(r30)
  bl        -0xA1238
  fmuls     f0, f1, f28
  lfs       f1, 0x344(r30)
  fadds     f1, f1, f0
  bl        -0xA1274
  stfs      f1, 0x344(r30)
  lfs       f1, -0x6818(r2)
  lfs       f2, 0x348(r30)
  bl        -0xA1258
  fmuls     f0, f1, f28
  lfs       f1, 0x348(r30)
  fadds     f1, f1, f0
  bl        -0xA1294
  stfs      f1, 0x348(r30)
  lfs       f1, 0x344(r30)
  lfs       f0, -0x67C8(r2)
  fabs      f1, f1
  fcmpo     cr0, f1, f0
  bge-      .loc_0x350
  lfs       f1, 0x348(r30)
  fabs      f1, f1
  fcmpo     cr0, f1, f0
  bge-      .loc_0x350
  li        r31, 0
  stw       r31, 0x33C(r30)
  lfs       f0, -0x6818(r2)
  stfs      f0, 0x348(r30)
  stfs      f0, 0x344(r30)
  stb       r31, 0x340(r30)
  stb       r31, 0x330(r30)
  lwz       r3, 0x338(r30)
  cmplwi    r3, 0
  beq-      .loc_0x350
  bl        0xAAFC
  stw       r31, 0x338(r30)
  b         .loc_0x350

.loc_0x18C:
  lfs       f1, 0x344(r30)
  lfs       f0, 0xA0(r30)
  fadds     f1, f1, f0
  bl        -0xA1300
  fmr       f2, f1
  lfs       f0, 0xA0(r30)
  fsubs     f1, f30, f0
  fmr       f28, f2
  bl        -0xA1314
  lfs       f0, -0x67C4(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x1E8
  lfs       f2, 0x344(r30)
  fcmpo     cr0, f2, f0
  ble-      .loc_0x1D8
  fsubs     f0, f2, f1
  lfs       f1, -0x67C0(r2)
  fsubs     f1, f1, f0
  b         .loc_0x21C

.loc_0x1D8:
  fmr       f1, f30
  fmr       f2, f28
  bl        -0xA131C
  b         .loc_0x21C

.loc_0x1E8:
  lfs       f2, 0x344(r30)
  fcmpo     cr0, f2, f0
  cror      2, 0, 0x2
  bne-      .loc_0x210
  fsubs     f1, f2, f1
  lfs       f2, -0x67C0(r2)
  lfs       f0, -0x67BC(r2)
  fsubs     f1, f2, f1
  fmuls     f1, f1, f0
  b         .loc_0x21C

.loc_0x210:
  fmr       f1, f30
  fmr       f2, f28
  bl        -0xA1354

.loc_0x21C:
  fabs      f2, f1
  lfs       f0, -0x67B8(r2)
  fcmpo     cr0, f2, f0
  bge-      .loc_0x230
  lfs       f1, -0x6818(r2)

.loc_0x230:
  fmuls     f0, f1, f29
  lfs       f1, 0x344(r30)
  fadds     f1, f1, f0
  bl        -0xA13A4
  stfs      f1, 0x344(r30)
  lfs       f2, 0x344(r30)
  lfs       f1, -0x67B4(r2)
  fcmpo     cr0, f2, f1
  ble-      .loc_0x268
  lfs       f0, -0x67C4(r2)
  fcmpo     cr0, f2, f0
  bge-      .loc_0x268
  stfs      f1, 0x344(r30)
  b         .loc_0x288

.loc_0x268:
  lfs       f1, -0x67B0(r2)
  fcmpo     cr0, f2, f1
  bge-      .loc_0x288
  lfs       f0, -0x67C4(r2)
  fcmpo     cr0, f2, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x288
  stfs      f1, 0x344(r30)

.loc_0x288:
  fmr       f1, f31
  lfs       f2, 0x348(r30)
  bl        -0xA13CC
  fabs      f2, f1
  lfs       f0, -0x67B8(r2)
  fcmpo     cr0, f2, f0
  bge-      .loc_0x2A8
  lfs       f1, -0x6818(r2)

.loc_0x2A8:
  fmuls     f0, f1, f29
  lfs       f1, 0x348(r30)
  fadds     f1, f1, f0
  bl        -0xA141C
  stfs      f1, 0x348(r30)
  lfs       f2, 0x348(r30)
  lfs       f1, -0x67AC(r2)
  fcmpo     cr0, f2, f1
  ble-      .loc_0x2E0
  lfs       f0, -0x67C4(r2)
  fcmpo     cr0, f2, f0
  bge-      .loc_0x2E0
  stfs      f1, 0x348(r30)
  b         .loc_0x300

.loc_0x2E0:
  lfs       f1, -0x67A8(r2)
  fcmpo     cr0, f2, f1
  bge-      .loc_0x300
  lfs       f0, -0x67C4(r2)
  fcmpo     cr0, f2, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x300
  stfs      f1, 0x348(r30)

.loc_0x300:
  lbz       r3, 0x340(r30)
  cmplwi    r3, 0
  beq-      .loc_0x350
  subi      r0, r3, 0x1
  stb       r0, 0x340(r30)
  lbz       r0, 0x340(r30)
  cmplwi    r0, 0
  bne-      .loc_0x350
  li        r31, 0
  stw       r31, 0x33C(r30)
  lfs       f0, -0x6818(r2)
  stfs      f0, 0x348(r30)
  stfs      f0, 0x344(r30)
  stb       r31, 0x340(r30)
  stb       r31, 0x330(r30)
  lwz       r3, 0x338(r30)
  cmplwi    r3, 0
  beq-      .loc_0x350
  bl        0xA934
  stw       r31, 0x338(r30)

.loc_0x350:
  lwz       r0, 0x74(r1)
  lfd       f31, 0x68(r1)
  lfd       f30, 0x60(r1)
  lfd       f29, 0x58(r1)
  lfd       f28, 0x50(r1)
  lwz       r31, 0x4C(r1)
  lwz       r30, 0x48(r1)
  addi      r1, r1, 0x70
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800D9A68
 * Size:	000678
 */
void ViewPiki::demoDraw(Graphics &, Matrix4f *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x190(r1)
  stmw      r26, 0x178(r1)
  addi      r27, r3, 0
  addi      r28, r4, 0
  lfs       f0, -0x6818(r2)
  stfs      f0, 0x16C(r1)
  stfs      f0, 0x168(r1)
  lwz       r0, -0x5F04(r13)
  stfs      f0, 0x164(r1)
  cmpwi     r0, 0x2
  ble-      .loc_0x44
  addi      r3, r27, 0x174
  bl        -0x34648
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD4

.loc_0x44:
  lfs       f1, -0x3B3C(r13)
  mr        r4, r28
  lfs       f0, -0x3B38(r13)
  addi      r6, r1, 0x164
  stfs      f1, 0x164(r1)
  li        r5, 0
  stfs      f0, 0x168(r1)
  lfs       f0, -0x3B34(r13)
  stfs      f0, 0x16C(r1)
  lwz       r3, 0x588(r27)
  lwz       r3, 0x0(r3)
  bl        -0xA4214
  lwz       r3, 0x164(r1)
  mr        r4, r28
  lwz       r0, 0x168(r1)
  addi      r6, r1, 0x164
  li        r5, 0x1
  stw       r3, 0x44C(r27)
  stw       r0, 0x450(r27)
  lwz       r0, 0x16C(r1)
  stw       r0, 0x454(r27)
  lfs       f1, -0x3B30(r13)
  lfs       f0, -0x3B2C(r13)
  stfs      f1, 0x164(r1)
  stfs      f0, 0x168(r1)
  lfs       f0, -0x3B28(r13)
  stfs      f0, 0x16C(r1)
  lwz       r3, 0x588(r27)
  lwz       r3, 0x0(r3)
  bl        -0xA425C
  lwz       r3, 0x164(r1)
  lwz       r0, 0x168(r1)
  stw       r3, 0x458(r27)
  stw       r0, 0x45C(r27)
  lwz       r0, 0x16C(r1)
  stw       r0, 0x460(r27)

.loc_0xD4:
  lwz       r0, 0x520(r27)
  cmpwi     r0, 0x1
  bne-      .loc_0xFC
  lfs       f1, -0x3B24(r13)
  lfs       f0, -0x3B20(r13)
  stfs      f1, 0x164(r1)
  stfs      f0, 0x168(r1)
  lfs       f0, -0x3B1C(r13)
  stfs      f0, 0x16C(r1)
  b         .loc_0x138

.loc_0xFC:
  cmpwi     r0, 0x2
  bne-      .loc_0x120
  lfs       f1, -0x3B18(r13)
  lfs       f0, -0x3B14(r13)
  stfs      f1, 0x164(r1)
  stfs      f0, 0x168(r1)
  lfs       f0, -0x3B10(r13)
  stfs      f0, 0x16C(r1)
  b         .loc_0x138

.loc_0x120:
  lfs       f1, -0x3B0C(r13)
  lfs       f0, -0x3B08(r13)
  stfs      f1, 0x164(r1)
  stfs      f0, 0x168(r1)
  lfs       f0, -0x3B04(r13)
  stfs      f0, 0x16C(r1)

.loc_0x138:
  lwz       r3, 0x588(r27)
  addi      r4, r28, 0
  addi      r6, r1, 0x164
  lwz       r3, 0x0(r3)
  li        r5, 0x6
  bl        -0xA42F0
  lwz       r3, 0x164(r1)
  lwz       r0, 0x168(r1)
  stw       r3, 0x464(r27)
  stw       r0, 0x468(r27)
  lwz       r0, 0x16C(r1)
  stw       r0, 0x46C(r27)
  lbz       r0, 0x2B4(r27)
  cmplwi    r0, 0
  beq-      .loc_0x21C
  bl        0x13E494
  xoris     r0, r3, 0x8000
  lfd       f4, -0x6800(r2)
  stw       r0, 0x174(r1)
  lis       r0, 0x4330
  lfs       f2, -0x680C(r2)
  stw       r0, 0x170(r1)
  lfs       f1, -0x6810(r2)
  lfd       f3, 0x170(r1)
  lfs       f0, -0x6804(r2)
  fsubs     f3, f3, f4
  fdivs     f2, f3, f2
  fmuls     f1, f1, f2
  fcmpo     cr0, f1, f0
  ble-      .loc_0x21C
  li        r0, 0xFF
  stb       r0, 0x38(r1)
  stb       r0, 0x39(r1)
  stb       r0, 0x3A(r1)
  stb       r0, 0x3B(r1)
  lwz       r3, 0x588(r27)
  lwz       r3, 0x0(r3)
  lwz       r4, 0x44(r3)
  lwz       r0, 0x4C(r4)
  rlwinm.   r0,r0,0,30,30
  beq-      .loc_0x210
  lbz       r0, 0x38(r1)
  lwz       r3, 0x90(r4)
  sth       r0, 0x0(r3)
  lbz       r0, 0x39(r1)
  lwz       r3, 0x90(r4)
  sth       r0, 0x2(r3)
  lbz       r0, 0x3A(r1)
  lwz       r3, 0x90(r4)
  sth       r0, 0x4(r3)
  lbz       r0, 0x3B(r1)
  lwz       r3, 0x90(r4)
  sth       r0, 0x6(r3)
  b         .loc_0x270

.loc_0x210:
  lwz       r0, 0x38(r1)
  stw       r0, 0x2C(r4)
  b         .loc_0x270

.loc_0x21C:
  lwz       r3, 0x588(r27)
  lwz       r3, 0x0(r3)
  lwz       r4, 0x44(r3)
  lwz       r0, 0x4C(r4)
  rlwinm.   r0,r0,0,30,30
  beq-      .loc_0x268
  lbz       r0, 0x508(r27)
  lwz       r3, 0x90(r4)
  sth       r0, 0x0(r3)
  lbz       r0, 0x509(r27)
  lwz       r3, 0x90(r4)
  sth       r0, 0x2(r3)
  lbz       r0, 0x50A(r27)
  lwz       r3, 0x90(r4)
  sth       r0, 0x4(r3)
  lbz       r0, 0x50B(r27)
  lwz       r3, 0x90(r4)
  sth       r0, 0x6(r3)
  b         .loc_0x270

.loc_0x268:
  lwz       r0, 0x508(r27)
  stw       r0, 0x2C(r4)

.loc_0x270:
  lwz       r0, 0xC8(r27)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x294
  lwz       r3, 0x588(r27)
  mr        r4, r28
  lwz       r5, 0x2E4(r28)
  li        r6, 0
  lwz       r3, 0x0(r3)
  bl        -0xA988C

.loc_0x294:
  lbz       r0, 0x424(r27)
  cmplwi    r0, 0
  beq-      .loc_0x2AC
  lwz       r3, 0x428(r27)
  addi      r4, r27, 0x44C
  bl        0x3A718

.loc_0x2AC:
  lwz       r0, 0xC8(r27)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x310
  lwz       r0, -0x5F04(r13)
  cmpwi     r0, 0x3
  bge-      .loc_0x310
  lwz       r0, 0x598(r27)
  cmplwi    r0, 0
  beq-      .loc_0x310
  lwz       r3, 0x588(r27)
  li        r4, 0x6
  lwz       r3, 0x0(r3)
  bl        -0xA4D5C
  lwz       r12, 0x3B4(r28)
  addi      r4, r3, 0
  addi      r3, r28, 0
  lwz       r12, 0x74(r12)
  li        r5, 0
  mtlr      r12
  blrl      
  lwz       r3, 0x598(r27)
  mr        r4, r28
  lwz       r5, 0x2E4(r28)
  li        r6, 0
  bl        -0xA9908

.loc_0x310:
  lhz       r0, 0x4FC(r27)
  cmplwi    r0, 0x1
  bne-      .loc_0x5CC
  lbz       r0, 0x2FA8(r13)
  cmplwi    r0, 0
  beq-      .loc_0x5CC
  lwz       r12, 0x3B4(r28)
  lis       r4, 0x803A
  mr        r3, r28
  lwz       r12, 0x74(r12)
  subi      r4, r4, 0x77C0
  li        r5, 0
  mtlr      r12
  blrl      
  lwz       r3, 0x4F8(r27)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0x360
  li        r31, 0
  b         .loc_0x36C

.loc_0x360:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r31, r3, r0

.loc_0x36C:
  cmplwi    r31, 0
  beq-      .loc_0x5CC
  lfs       f0, 0x94(r27)
  lis       r0, 0x4330
  addi      r3, r28, 0
  stfs      f0, 0x154(r1)
  li        r4, 0
  li        r5, 0
  lfs       f0, 0x98(r27)
  stfs      f0, 0x158(r1)
  lfs       f0, 0x9C(r27)
  lfd       f1, -0x6800(r2)
  stfs      f0, 0x15C(r1)
  lfs       f2, -0x67A0(r2)
  lwz       r7, 0x58(r31)
  lfs       f3, -0x67A4(r2)
  xoris     r6, r7, 0x8000
  lfs       f4, 0x158(r1)
  stw       r6, 0x174(r1)
  mr        r30, r7
  stw       r0, 0x170(r1)
  lfd       f0, 0x170(r1)
  fsubs     f0, f0, f1
  fmuls     f0, f2, f0
  fadds     f0, f3, f0
  fadds     f0, f4, f0
  stfs      f0, 0x158(r1)
  lwz       r12, 0x3B4(r28)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lwz       r12, 0x3B4(r28)
  addi      r0, r3, 0
  lis       r4, 0x803A
  lwz       r12, 0x74(r12)
  addi      r3, r28, 0
  subi      r4, r4, 0x77C0
  mtlr      r12
  mr        r29, r0
  li        r5, 0
  blrl      
  lhz       r0, 0x2C(r31)
  cmplwi    r0, 0x2
  bne-      .loc_0x458
  li        r6, 0xFF
  stb       r6, 0x34(r1)
  li        r0, 0xA
  addi      r4, r1, 0x34
  stb       r0, 0x35(r1)
  li        r0, 0x32
  addi      r3, r28, 0
  stb       r0, 0x36(r1)
  li        r5, 0x1
  stb       r6, 0x37(r1)
  lwz       r12, 0x3B4(r28)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x4C8

.loc_0x458:
  cmplwi    r0, 0
  bne-      .loc_0x498
  li        r0, 0xC8
  stb       r0, 0x30(r1)
  li        r0, 0xFF
  addi      r4, r1, 0x30
  stb       r0, 0x31(r1)
  mr        r3, r28
  li        r5, 0x1
  stb       r0, 0x32(r1)
  stb       r0, 0x33(r1)
  lwz       r12, 0x3B4(r28)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x4C8

.loc_0x498:
  li        r0, 0xFF
  stb       r0, 0x2C(r1)
  addi      r4, r1, 0x2C
  addi      r3, r28, 0
  stb       r0, 0x2D(r1)
  li        r5, 0x1
  stb       r0, 0x2E(r1)
  stb       r0, 0x2F(r1)
  lwz       r12, 0x3B4(r28)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      

.loc_0x4C8:
  lis       r3, 0x8022
  addi      r6, r3, 0x2580
  lwz       r5, 0x0(r6)
  mr        r3, r28
  lwz       r0, 0x4(r6)
  li        r4, 0
  stw       r5, 0x13C(r1)
  stw       r0, 0x140(r1)
  lwz       r5, 0x8(r6)
  lwz       r0, 0xC(r6)
  stw       r5, 0x144(r1)
  stw       r0, 0x148(r1)
  lwz       r5, 0x10(r6)
  lwz       r0, 0x14(r6)
  stw       r5, 0x14C(r1)
  stw       r0, 0x150(r1)
  lwz       r12, 0x3B4(r28)
  lhz       r31, 0x2E(r31)
  lwz       r12, 0x60(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x2E4(r28)
  addi      r26, r3, 0
  addi      r3, r1, 0x154
  addi      r4, r4, 0x1E0
  bl        -0xA2848
  rlwinm    r0,r31,2,0,29
  crclr     6, 0x6
  addi      r3, r1, 0x13C
  lwzx      r5, r3, r0
  addi      r6, r30, 0
  addi      r3, r1, 0x3C
  subi      r4, r13, 0x3AE8
  bl        0x13C5E4
  lwz       r3, 0x2DEC(r13)
  addi      r4, r1, 0x3C
  lwz       r3, 0x10(r3)
  bl        -0xB1E90
  lwz       r12, 0x3B4(r28)
  srawi     r0, r3, 0x1
  lwz       r4, 0x2DEC(r13)
  addze     r0, r0
  lwz       r12, 0xF0(r12)
  lwz       r4, 0x10(r4)
  addi      r3, r28, 0
  mtlr      r12
  neg       r6, r0
  addi      r5, r1, 0x154
  crclr     6, 0x6
  addi      r8, r1, 0x3C
  li        r7, 0
  blrl      
  mr        r3, r28
  lwz       r12, 0x3B4(r28)
  mr        r4, r26
  lwz       r12, 0x60(r12)
  mtlr      r12
  blrl      
  mr        r3, r28
  lwz       r12, 0x3B4(r28)
  addi      r4, r29, 0
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      

.loc_0x5CC:
  lbz       r0, 0x2FA8(r13)
  cmplwi    r0, 0
  beq-      .loc_0x664
  lwz       r3, 0x4F8(r27)
  cmplwi    r3, 0
  beq-      .loc_0x664
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0x5F8
  li        r0, 0
  b         .loc_0x604

.loc_0x5F8:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r0, r3, r0

.loc_0x604:
  cmplwi    r0, 0
  beq-      .loc_0x664
  lwz       r12, 0x3B4(r28)
  lis       r4, 0x803A
  mr        r3, r28
  lwz       r12, 0x74(r12)
  subi      r4, r4, 0x77C0
  li        r5, 0
  mtlr      r12
  blrl      
  lwz       r3, 0x4F8(r27)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0x644
  li        r3, 0
  b         .loc_0x650

.loc_0x644:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0x650:
  lwz       r12, 0x0(r3)
  mr        r4, r28
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      

.loc_0x664:
  lmw       r26, 0x178(r1)
  lwz       r0, 0x194(r1)
  addi      r1, r1, 0x190
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void printMatrix(char *, Matrix4f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DA0E0
 * Size:	000B48
 */
void ViewPiki::refresh(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x410(r1)
  stfd      f31, 0x408(r1)
  stfd      f30, 0x400(r1)
  stfd      f29, 0x3F8(r1)
  stw       r31, 0x3F4(r1)
  stw       r30, 0x3F0(r1)
  addi      r30, r4, 0
  stw       r29, 0x3EC(r1)
  mr        r29, r3
  lhz       r5, 0x510(r3)
  cmplwi    r5, 0
  bne-      .loc_0x4C
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r0, 0x1D8(r3)
  rlwinm.   r0,r0,0,28,28
  bne-      .loc_0xB20

.loc_0x4C:
  cmplwi    r5, 0x1
  bne-      .loc_0x68
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r0, 0x1D8(r3)
  rlwinm.   r0,r0,0,27,27
  bne-      .loc_0xB20

.loc_0x68:
  cmplwi    r5, 0x2
  bne-      .loc_0x84
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r0, 0x1D8(r3)
  rlwinm.   r0,r0,0,26,26
  bne-      .loc_0xB20

.loc_0x84:
  lhz       r4, 0x4FC(r29)
  cmplwi    r4, 0
  bne-      .loc_0xA0
  lwz       r3, 0x3068(r13)
  lhz       r0, 0x70(r3)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0xB20

.loc_0xA0:
  cmplwi    r4, 0x1
  bne-      .loc_0xB8
  lwz       r3, 0x3068(r13)
  lhz       r0, 0x70(r3)
  rlwinm.   r0,r0,0,30,30
  beq-      .loc_0xB20

.loc_0xB8:
  lwz       r3, 0x3068(r13)
  lhz       r4, 0x70(r3)
  rlwinm.   r0,r4,0,29,29
  beq-      .loc_0xB20
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r3, 0x1DC(r3)
  lbz       r0, 0x124(r3)
  cmplwi    r0, 0
  beq-      .loc_0x1B0
  rlwinm.   r0,r4,0,28,28
  beq-      .loc_0x1B0
  lwz       r3, 0x30AC(r13)
  bl        0x18A6C
  lwz       r12, 0x0(r3)
  mr        r4, r3
  addi      r3, r1, 0x12C
  lwz       r12, 0x15C(r12)
  mtlr      r12
  blrl      
  lfs       f3, 0x98(r29)
  lfs       f2, 0x130(r1)
  lfs       f1, 0x94(r29)
  lfs       f0, 0x12C(r1)
  fsubs     f3, f3, f2
  lfs       f2, 0x9C(r29)
  fsubs     f4, f1, f0
  lfs       f0, 0x134(r1)
  fmuls     f1, f3, f3
  fsubs     f3, f2, f0
  lfs       f0, -0x6818(r2)
  fmuls     f2, f4, f4
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x1A4
  fsqrte    f1, f4
  lfd       f3, -0x67F8(r2)
  lfd       f2, -0x67F0(r2)
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
  stfs      f0, 0x80(r1)
  lfs       f4, 0x80(r1)

.loc_0x1A4:
  lfs       f0, -0x67E8(r2)
  fcmpo     cr0, f4, f0
  bgt-      .loc_0xB20

.loc_0x1B0:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lfs       f0, -0x67D8(r2)
  addi      r4, r29, 0x94
  lwz       r3, 0x2E4(r30)
  fmuls     f1, f0, f1
  bl        -0x98D30
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x1F0
  lwz       r0, 0xC8(r29)
  oris      r0, r0, 0x8
  stw       r0, 0xC8(r29)
  b         .loc_0x2BC

.loc_0x1F0:
  lwz       r0, 0xC8(r29)
  rlwinm    r0,r0,0,13,11
  stw       r0, 0xC8(r29)
  lbz       r0, -0x5F18(r13)
  cmplwi    r0, 0
  beq-      .loc_0x2B4
  lwz       r3, 0x2E4(r30)
  lfs       f2, 0x98(r29)
  addi      r3, r3, 0x164
  lfs       f0, 0x94(r29)
  lfs       f3, 0x4(r3)
  lfs       f1, 0x0(r3)
  fsubs     f4, f3, f2
  lfs       f2, 0x8(r3)
  fsubs     f5, f1, f0
  lfs       f1, 0x9C(r29)
  lfs       f0, -0x6818(r2)
  fsubs     f3, f2, f1
  fmuls     f2, f5, f5
  fmuls     f1, f4, f4
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x2AC
  fsqrte    f1, f4
  lfd       f3, -0x67F8(r2)
  lfd       f2, -0x67F0(r2)
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
  stfs      f0, 0x7C(r1)
  lfs       f4, 0x7C(r1)

.loc_0x2AC:
  stfs      f4, 0x528(r29)
  b         .loc_0x2BC

.loc_0x2B4:
  lfs       f0, -0x679C(r2)
  stfs      f0, 0x528(r29)

.loc_0x2BC:
  mr        r3, r29
  bl        -0x11E4C
  cmpwi     r3, 0x21
  bne-      .loc_0x330
  lwz       r3, 0x3068(r13)
  lfs       f2, 0x48C(r29)
  lwz       r3, 0x68(r3)
  lfs       f0, 0x178(r3)
  lfs       f1, 0x168(r3)
  lfs       f5, 0xA8(r3)
  fsubs     f0, f1, f0
  fcmpo     cr0, f2, f0
  ble-      .loc_0x2FC
  lfs       f3, -0x67A0(r2)
  lfs       f0, -0x6798(r2)
  b         .loc_0x31C

.loc_0x2FC:
  fdivs     f4, f2, f0
  lfs       f3, -0x6810(r2)
  lfs       f1, -0x67E4(r2)
  lfs       f2, -0x6798(r2)
  fsubs     f0, f3, f4
  fadds     f3, f3, f4
  fmuls     f0, f1, f0
  fadds     f0, f2, f0

.loc_0x31C:
  fmuls     f1, f5, f3
  fmuls     f0, f5, f0
  stfs      f1, 0x7C(r29)
  stfs      f0, 0x80(r29)
  stfs      f1, 0x84(r29)

.loc_0x330:
  lwz       r0, 0x184(r29)
  cmplwi    r0, 0
  beq-      .loc_0x34C
  mr        r3, r29
  bl        -0x4A4D0
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x394

.loc_0x34C:
  lwz       r0, 0x158(r29)
  cmplwi    r0, 0
  bne-      .loc_0x394
  lwz       r0, 0x184(r29)
  cmplwi    r0, 0
  beq-      .loc_0x4C0
  lwz       r3, 0x188(r29)
  cmplwi    r3, 0
  beq-      .loc_0x4C0
  lbz       r3, 0x5C(r3)
  li        r0, 0x1
  cmplwi    r3, 0x5
  beq-      .loc_0x38C
  cmplwi    r3, 0x6
  beq-      .loc_0x38C
  li        r0, 0

.loc_0x38C:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x4C0

.loc_0x394:
  lwz       r3, 0x114(r29)
  lwz       r0, 0x118(r29)
  stw       r3, 0x228(r29)
  stw       r0, 0x22C(r29)
  lwz       r3, 0x11C(r29)
  lwz       r0, 0x120(r29)
  stw       r3, 0x230(r29)
  stw       r0, 0x234(r29)
  lwz       r3, 0x124(r29)
  lwz       r0, 0x128(r29)
  stw       r3, 0x238(r29)
  stw       r0, 0x23C(r29)
  lwz       r3, 0x12C(r29)
  lwz       r0, 0x130(r29)
  stw       r3, 0x240(r29)
  stw       r0, 0x244(r29)
  lwz       r3, 0x134(r29)
  lwz       r0, 0x138(r29)
  stw       r3, 0x248(r29)
  stw       r0, 0x24C(r29)
  lwz       r3, 0x13C(r29)
  lwz       r0, 0x140(r29)
  stw       r3, 0x250(r29)
  stw       r0, 0x254(r29)
  lwz       r3, 0x144(r29)
  lwz       r0, 0x148(r29)
  stw       r3, 0x258(r29)
  stw       r0, 0x25C(r29)
  lwz       r3, 0x14C(r29)
  lwz       r0, 0x150(r29)
  stw       r3, 0x260(r29)
  stw       r0, 0x264(r29)
  lfs       f1, 0x228(r29)
  lfs       f0, 0x7C(r29)
  fmuls     f0, f1, f0
  stfs      f0, 0x228(r29)
  lfs       f1, 0x22C(r29)
  lfs       f0, 0x80(r29)
  fmuls     f0, f1, f0
  stfs      f0, 0x22C(r29)
  lfs       f1, 0x230(r29)
  lfs       f0, 0x84(r29)
  fmuls     f0, f1, f0
  stfs      f0, 0x230(r29)
  lfs       f1, 0x238(r29)
  lfs       f0, 0x7C(r29)
  fmuls     f0, f1, f0
  stfs      f0, 0x238(r29)
  lfs       f1, 0x23C(r29)
  lfs       f0, 0x80(r29)
  fmuls     f0, f1, f0
  stfs      f0, 0x23C(r29)
  lfs       f1, 0x240(r29)
  lfs       f0, 0x84(r29)
  fmuls     f0, f1, f0
  stfs      f0, 0x240(r29)
  lfs       f1, 0x248(r29)
  lfs       f0, 0x7C(r29)
  fmuls     f0, f1, f0
  stfs      f0, 0x248(r29)
  lfs       f1, 0x24C(r29)
  lfs       f0, 0x80(r29)
  fmuls     f0, f1, f0
  stfs      f0, 0x24C(r29)
  lfs       f1, 0x250(r29)
  lfs       f0, 0x84(r29)
  fmuls     f0, f1, f0
  stfs      f0, 0x250(r29)
  lfs       f2, 0x9C(r29)
  lfs       f1, 0x98(r29)
  lfs       f0, 0x94(r29)
  stfs      f0, 0x234(r29)
  stfs      f1, 0x244(r29)
  stfs      f2, 0x254(r29)
  b         .loc_0x554

.loc_0x4C0:
  addi      r3, r29, 0x228
  addi      r4, r29, 0x7C
  addi      r5, r29, 0x88
  addi      r6, r29, 0x94
  bl        -0x9C4BC
  lwz       r3, 0x228(r29)
  lwz       r0, 0x22C(r29)
  stw       r3, 0x114(r29)
  stw       r0, 0x118(r29)
  lwz       r3, 0x230(r29)
  lwz       r0, 0x234(r29)
  stw       r3, 0x11C(r29)
  stw       r0, 0x120(r29)
  lwz       r3, 0x238(r29)
  lwz       r0, 0x23C(r29)
  stw       r3, 0x124(r29)
  stw       r0, 0x128(r29)
  lwz       r3, 0x240(r29)
  lwz       r0, 0x244(r29)
  stw       r3, 0x12C(r29)
  stw       r0, 0x130(r29)
  lwz       r3, 0x248(r29)
  lwz       r0, 0x24C(r29)
  stw       r3, 0x134(r29)
  stw       r0, 0x138(r29)
  lwz       r3, 0x250(r29)
  lwz       r0, 0x254(r29)
  stw       r3, 0x13C(r29)
  stw       r0, 0x140(r29)
  lwz       r3, 0x258(r29)
  lwz       r0, 0x25C(r29)
  stw       r3, 0x144(r29)
  stw       r0, 0x148(r29)
  lwz       r3, 0x260(r29)
  lwz       r0, 0x264(r29)
  stw       r3, 0x14C(r29)
  stw       r0, 0x150(r29)

.loc_0x554:
  lwz       r3, 0x2E4(r30)
  addi      r4, r29, 0x228
  addi      r5, r1, 0x394
  addi      r3, r3, 0x1E0
  bl        -0x9C570
  mr        r3, r29
  bl        -0x120F8
  cmpwi     r3, 0x8
  bne-      .loc_0x724
  lwz       r4, 0x4A4(r29)
  cmplwi    r4, 0
  beq-      .loc_0x724
  lwz       r3, 0x10(r4)
  lwz       r0, 0x14(r4)
  lfs       f0, -0x6818(r2)
  stw       r3, 0x344(r1)
  stw       r0, 0x348(r1)
  lwz       r3, 0x18(r4)
  lwz       r0, 0x1C(r4)
  stw       r3, 0x34C(r1)
  stw       r0, 0x350(r1)
  lwz       r3, 0x20(r4)
  lwz       r0, 0x24(r4)
  stw       r3, 0x354(r1)
  stw       r0, 0x358(r1)
  lwz       r3, 0x28(r4)
  lwz       r0, 0x2C(r4)
  stw       r3, 0x35C(r1)
  stw       r0, 0x360(r1)
  lwz       r3, 0x30(r4)
  lwz       r0, 0x34(r4)
  stw       r3, 0x364(r1)
  stw       r0, 0x368(r1)
  lwz       r3, 0x38(r4)
  lwz       r0, 0x3C(r4)
  stw       r3, 0x36C(r1)
  stw       r0, 0x370(r1)
  lwz       r3, 0x40(r4)
  lwz       r0, 0x44(r4)
  stw       r3, 0x374(r1)
  stw       r0, 0x378(r1)
  lwz       r3, 0x48(r4)
  lwz       r0, 0x4C(r4)
  stw       r3, 0x37C(r1)
  stw       r0, 0x380(r1)
  lfs       f2, 0x344(r1)
  lfs       f1, 0x348(r1)
  lfs       f3, 0x34C(r1)
  fmuls     f2, f2, f2
  fmuls     f1, f1, f1
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x688
  fsqrte    f1, f4
  lfd       f3, -0x67F8(r2)
  lfd       f2, -0x67F0(r2)
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
  stfs      f0, 0x74(r1)
  lfs       f4, 0x74(r1)

.loc_0x688:
  lfs       f1, -0x6810(r2)
  lfs       f0, -0x6818(r2)
  fdivs     f2, f1, f4
  fcmpo     cr0, f2, f0
  fmr       f4, f2
  cror      2, 0, 0x2
  bne-      .loc_0x6A8
  fmr       f4, f1

.loc_0x6A8:
  lfs       f1, -0x3AD4(r13)
  addi      r6, r1, 0xB0
  lfs       f0, -0x3AE0(r13)
  addi      r5, r1, 0xBC
  stfs      f4, 0xC8(r1)
  lfs       f3, -0x3AD0(r13)
  addi      r4, r1, 0xC8
  stfs      f1, 0xB0(r1)
  addi      r3, r1, 0x304
  lfs       f1, -0x3ADC(r13)
  stfs      f0, 0xBC(r1)
  lfs       f2, -0x3ACC(r13)
  stfs      f3, 0xB4(r1)
  lfs       f0, -0x3AD8(r13)
  stfs      f1, 0xC0(r1)
  stfs      f4, 0xCC(r1)
  stfs      f2, 0xB8(r1)
  stfs      f0, 0xC4(r1)
  stfs      f4, 0xD0(r1)
  bl        -0x9C6E0
  addi      r3, r1, 0x344
  addi      r4, r1, 0x304
  addi      r5, r1, 0x394
  bl        -0x9C710
  lwz       r4, 0x4A4(r29)
  lwz       r3, 0x4(r4)
  lwz       r0, 0x8(r4)
  stw       r3, 0x94(r29)
  stw       r0, 0x98(r29)
  lwz       r0, 0xC(r4)
  stw       r0, 0x9C(r29)

.loc_0x724:
  addi      r3, r29, 0x354
  bl        0x453FC
  lwz       r3, 0x588(r29)
  addi      r4, r30, 0
  addi      r5, r1, 0x394
  lwz       r3, 0x0(r3)
  li        r6, 0
  bl        -0xA550C
  lbz       r3, -0x5F18(r13)
  cmplwi    r3, 0
  beq-      .loc_0x76C
  lfs       f1, 0x528(r29)
  lfs       f0, -0x6794(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x76C
  lwz       r0, 0xC8(r29)
  rlwinm.   r0,r0,0,12,12
  beq-      .loc_0x774

.loc_0x76C:
  cmplwi    r3, 0
  bne-      .loc_0xAF4

.loc_0x774:
  lwz       r0, 0x33C(r29)
  cmplwi    r0, 0
  bne-      .loc_0x78C
  lbz       r0, 0x340(r29)
  cmplwi    r0, 0
  beq-      .loc_0xAF4

.loc_0x78C:
  mr        r3, r29
  bl        -0x1231C
  cmpwi     r3, 0x8
  beq-      .loc_0xAF4
  lhz       r0, 0x4FC(r29)
  cmplwi    r0, 0xC
  beq-      .loc_0xAF4
  mr        r3, r29
  bl        -0x119C
  lwz       r3, 0x588(r29)
  li        r4, 0x2
  lwz       r3, 0x0(r3)
  bl        -0xA58B4
  lwz       r5, 0x0(r3)
  addi      r4, r1, 0x284
  lwz       r0, 0x4(r3)
  lfs       f1, -0x6818(r2)
  stw       r5, 0x2C4(r1)
  lfs       f0, -0x6810(r2)
  stw       r0, 0x2C8(r1)
  lwz       r5, 0x8(r3)
  lwz       r0, 0xC(r3)
  stw       r5, 0x2CC(r1)
  stw       r0, 0x2D0(r1)
  lwz       r5, 0x10(r3)
  lwz       r0, 0x14(r3)
  stw       r5, 0x2D4(r1)
  stw       r0, 0x2D8(r1)
  lwz       r5, 0x18(r3)
  lwz       r0, 0x1C(r3)
  stw       r5, 0x2DC(r1)
  stw       r0, 0x2E0(r1)
  lwz       r5, 0x20(r3)
  lwz       r0, 0x24(r3)
  stw       r5, 0x2E4(r1)
  stw       r0, 0x2E8(r1)
  lwz       r5, 0x28(r3)
  lwz       r0, 0x2C(r3)
  stw       r5, 0x2EC(r1)
  stw       r0, 0x2F0(r1)
  lwz       r5, 0x30(r3)
  lwz       r0, 0x34(r3)
  stw       r5, 0x2F4(r1)
  stw       r0, 0x2F8(r1)
  lwz       r5, 0x38(r3)
  lwz       r0, 0x3C(r3)
  addi      r3, r1, 0x2C4
  stw       r5, 0x2FC(r1)
  stw       r0, 0x300(r1)
  stfs      f1, 0x2FC(r1)
  stfs      f1, 0x2F8(r1)
  stfs      f1, 0x2F4(r1)
  stfs      f0, 0x300(r1)
  bl        -0x9C504
  addi      r3, r1, 0x204
  bl        -0x9CB8C
  lfs       f0, 0x348(r29)
  fneg      f1, f0
  bl        0x141394
  lfs       f0, 0x348(r29)
  fmr       f29, f1
  fneg      f1, f0
  bl        0x1411F0
  fmr       f31, f1
  lfs       f1, 0x344(r29)
  bl        0x141378
  fmr       f30, f1
  lfs       f1, 0x344(r29)
  bl        0x1411D8
  fneg      f2, f29
  stfs      f31, 0x204(r1)
  lfs       f0, -0x6818(r2)
  fmuls     f5, f1, f29
  fmuls     f4, f1, f31
  stfs      f2, 0x208(r1)
  fneg      f3, f30
  fmuls     f2, f30, f29
  addi      r3, r1, 0x2C4
  stfs      f0, 0x20C(r1)
  fmuls     f0, f30, f31
  stfs      f5, 0x214(r1)
  addi      r4, r1, 0x204
  stfs      f4, 0x218(r1)
  addi      r5, r1, 0x244
  stfs      f3, 0x21C(r1)
  stfs      f2, 0x224(r1)
  stfs      f0, 0x228(r1)
  stfs      f1, 0x22C(r1)
  bl        -0x9C8F8
  lwz       r3, 0x588(r29)
  li        r4, 0x2
  lwz       r3, 0x0(r3)
  bl        -0xA59F4
  lwz       r4, 0x244(r1)
  li        r31, 0x3
  lwz       r0, 0x248(r1)
  stw       r4, 0x0(r3)
  stw       r0, 0x4(r3)
  lwz       r4, 0x24C(r1)
  lwz       r0, 0x250(r1)
  stw       r4, 0x8(r3)
  stw       r0, 0xC(r3)
  lwz       r4, 0x254(r1)
  lwz       r0, 0x258(r1)
  stw       r4, 0x10(r3)
  stw       r0, 0x14(r3)
  lwz       r4, 0x25C(r1)
  lwz       r0, 0x260(r1)
  stw       r4, 0x18(r3)
  stw       r0, 0x1C(r3)
  lwz       r4, 0x264(r1)
  lwz       r0, 0x268(r1)
  stw       r4, 0x20(r3)
  stw       r0, 0x24(r3)
  lwz       r4, 0x26C(r1)
  lwz       r0, 0x270(r1)
  stw       r4, 0x28(r3)
  stw       r0, 0x2C(r3)
  lwz       r4, 0x274(r1)
  lwz       r0, 0x278(r1)
  stw       r4, 0x30(r3)
  stw       r0, 0x34(r3)
  lwz       r4, 0x27C(r1)
  lwz       r0, 0x280(r1)
  stw       r4, 0x38(r3)
  stw       r0, 0x3C(r3)
  lfs       f30, -0x6818(r2)
  lfs       f31, -0x6810(r2)

.loc_0x98C:
  lwz       r3, 0x588(r29)
  mr        r4, r31
  lwz       r3, 0x0(r3)
  bl        -0xA5A90
  lwz       r6, 0x0(r3)
  addi      r4, r1, 0x1C4
  lwz       r0, 0x4(r3)
  addi      r5, r1, 0x184
  stw       r6, 0x1C4(r1)
  stw       r0, 0x1C8(r1)
  lwz       r6, 0x8(r3)
  lwz       r0, 0xC(r3)
  stw       r6, 0x1CC(r1)
  stw       r0, 0x1D0(r1)
  lwz       r6, 0x10(r3)
  lwz       r0, 0x14(r3)
  stw       r6, 0x1D4(r1)
  stw       r0, 0x1D8(r1)
  lwz       r6, 0x18(r3)
  lwz       r0, 0x1C(r3)
  stw       r6, 0x1DC(r1)
  stw       r0, 0x1E0(r1)
  lwz       r6, 0x20(r3)
  lwz       r0, 0x24(r3)
  stw       r6, 0x1E4(r1)
  stw       r0, 0x1E8(r1)
  lwz       r6, 0x28(r3)
  lwz       r0, 0x2C(r3)
  stw       r6, 0x1EC(r1)
  stw       r0, 0x1F0(r1)
  lwz       r6, 0x30(r3)
  lwz       r0, 0x34(r3)
  stw       r6, 0x1F4(r1)
  stw       r0, 0x1F8(r1)
  lwz       r6, 0x38(r3)
  lwz       r0, 0x3C(r3)
  addi      r3, r1, 0x284
  stw       r6, 0x1FC(r1)
  stw       r0, 0x200(r1)
  stfs      f30, 0x1FC(r1)
  stfs      f30, 0x1F8(r1)
  stfs      f30, 0x1F4(r1)
  stfs      f31, 0x200(r1)
  bl        -0x9CA44
  addi      r3, r1, 0x244
  addi      r4, r1, 0x184
  addi      r5, r1, 0x144
  bl        -0x9CA54
  lwz       r3, 0x588(r29)
  mr        r4, r31
  lwz       r3, 0x0(r3)
  bl        -0xA5B50
  lwz       r4, 0x144(r1)
  addi      r31, r31, 0x1
  lwz       r0, 0x148(r1)
  cmpwi     r31, 0x6
  stw       r4, 0x0(r3)
  stw       r0, 0x4(r3)
  lwz       r4, 0x14C(r1)
  lwz       r0, 0x150(r1)
  stw       r4, 0x8(r3)
  stw       r0, 0xC(r3)
  lwz       r4, 0x154(r1)
  lwz       r0, 0x158(r1)
  stw       r4, 0x10(r3)
  stw       r0, 0x14(r3)
  lwz       r4, 0x15C(r1)
  lwz       r0, 0x160(r1)
  stw       r4, 0x18(r3)
  stw       r0, 0x1C(r3)
  lwz       r4, 0x164(r1)
  lwz       r0, 0x168(r1)
  stw       r4, 0x20(r3)
  stw       r0, 0x24(r3)
  lwz       r4, 0x16C(r1)
  lwz       r0, 0x170(r1)
  stw       r4, 0x28(r3)
  stw       r0, 0x2C(r3)
  lwz       r4, 0x174(r1)
  lwz       r0, 0x178(r1)
  stw       r4, 0x30(r3)
  stw       r0, 0x34(r3)
  lwz       r4, 0x17C(r1)
  lwz       r0, 0x180(r1)
  stw       r4, 0x38(r3)
  stw       r0, 0x3C(r3)
  ble+      .loc_0x98C
  lwz       r3, 0x588(r29)
  lwz       r3, 0x0(r3)
  bl        -0xA55DC

.loc_0xAF4:
  lwz       r3, 0x220(r29)
  addi      r4, r30, 0
  li        r5, 0
  bl        -0x510F4
  mr        r3, r29
  lwz       r12, 0x0(r29)
  addi      r4, r30, 0
  li        r5, 0
  lwz       r12, 0xFC(r12)
  mtlr      r12
  blrl      

.loc_0xB20:
  lwz       r0, 0x414(r1)
  lfd       f31, 0x408(r1)
  lfd       f30, 0x400(r1)
  lfd       f29, 0x3F8(r1)
  lwz       r31, 0x3F4(r1)
  lwz       r30, 0x3F0(r1)
  lwz       r29, 0x3EC(r1)
  addi      r1, r1, 0x410
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void ViewPiki::refresh2d(Graphics &, int)
{
	// UNUSED FUNCTION
}