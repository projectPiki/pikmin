

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
 * Address:	8007B7C8
 * Size:	0001A0
 */
void InteractBomb::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x70(r1)
  stfd      f31, 0x68(r1)
  stfd      f30, 0x60(r1)
  stw       r31, 0x5C(r1)
  addi      r31, r4, 0
  stw       r30, 0x58(r1)
  addi      r30, r3, 0
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x48
  li        r3, 0
  b         .loc_0x180

.loc_0x48:
  mr        r3, r31
  bl        0x4CD40
  cmpwi     r3, 0x18
  beq-      .loc_0x64
  subi      r0, r3, 0x6
  cmplwi    r0, 0x1
  bgt-      .loc_0x6C

.loc_0x64:
  li        r3, 0
  b         .loc_0x180

.loc_0x6C:
  cmpwi     r3, 0x16
  bne-      .loc_0x7C
  li        r3, 0
  b         .loc_0x180

.loc_0x7C:
  lwz       r0, 0xC8(r31)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0xB0
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x1B
  addi      r3, r3, 0x54
  bl        0x6C68
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0xB0
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x1B
  addi      r3, r3, 0x54
  bl        0x6EDC

.loc_0xB0:
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x18
  addi      r3, r3, 0x70
  bl        0x817C
  lwz       r4, 0x4(r30)
  addi      r3, r31, 0
  li        r5, 0x1A
  bl        0xED20
  lfs       f1, 0x58(r31)
  addi      r3, r31, 0x1E0
  lfs       f0, 0x8(r30)
  fsubs     f0, f1, f0
  stfs      f0, 0x58(r31)
  lwz       r4, 0x224(r31)
  lfs       f1, 0x58(r31)
  lfs       f2, 0xB8(r4)
  bl        -0x1F844
  lwz       r3, 0x4(r30)
  lfsu      f3, 0x94(r3)
  lfs       f1, 0x94(r31)
  lfs       f0, 0x98(r31)
  lfs       f2, 0x4(r3)
  fsubs     f31, f3, f1
  lfs       f1, 0x8(r3)
  fsubs     f2, f2, f0
  lfs       f0, 0x9C(r31)
  fsubs     f30, f1, f0
  fmuls     f0, f2, f2
  fmuls     f1, f31, f31
  fmuls     f2, f30, f30
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x6DCB8
  lfs       f0, -0x76B8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x148
  fdivs     f31, f31, f1
  fdivs     f30, f30, f1

.loc_0x148:
  fmr       f1, f31
  fmr       f2, f30
  bl        0x1A00E0
  stfs      f1, 0x49C(r31)
  addi      r4, r31, 0
  li        r5, 0x16
  lfs       f0, -0x76B4(r2)
  stfs      f0, 0x498(r31)
  lwz       r3, 0x490(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  li        r3, 0x1

.loc_0x180:
  lwz       r0, 0x74(r1)
  lfd       f31, 0x68(r1)
  lfd       f30, 0x60(r1)
  lwz       r31, 0x5C(r1)
  lwz       r30, 0x58(r1)
  addi      r1, r1, 0x70
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007B968
 * Size:	0000C0
 */
void InteractBury::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x40
  li        r3, 0
  b         .loc_0xA8

.loc_0x40:
  addi      r3, r31, 0x94
  bl        0x4ABAC
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x60
  lwz       r3, 0x28C(r31)
  bl        0x9A6EC
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x68

.loc_0x60:
  li        r3, 0
  b         .loc_0xA8

.loc_0x68:
  lbz       r0, 0x8(r30)
  cmplwi    r0, 0
  beq-      .loc_0x88
  lwz       r0, 0x520(r31)
  cmpwi     r0, 0x2
  bge-      .loc_0x88
  li        r0, 0x2
  stw       r0, 0x520(r31)

.loc_0x88:
  lwz       r3, 0x490(r31)
  addi      r4, r31, 0
  li        r5, 0x2
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  li        r3, 0x1

.loc_0xA8:
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
 * Address:	8007BA28
 * Size:	00006C
 */
void InteractThrowAway::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x38
  li        r3, 0
  b         .loc_0x58

.loc_0x38:
  lwz       r3, 0x490(r31)
  addi      r4, r31, 0
  li        r5, 0x1E
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  li        r3, 0x1

.loc_0x58:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007BA94
 * Size:	000080
 */
void InteractChangeColor::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x40
  li        r3, 0
  b         .loc_0x68

.loc_0x40:
  mr        r3, r31
  lwz       r4, 0x8(r30)
  lwz       r12, 0x0(r31)
  lwz       r12, 0x12C(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r4, 0x8(r30)
  bl        0x4DEDC
  li        r3, 0x1

.loc_0x68:
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
 * Address:	8007BB14
 * Size:	000004
 */
void Piki::changeShape(int)
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	8007BB18
 * Size:	000074
 */
void InteractChangeHappa::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x40
  li        r3, 0
  b         .loc_0x5C

.loc_0x40:
  mr        r3, r31
  lwz       r4, 0x8(r30)
  lwz       r12, 0x0(r31)
  lwz       r12, 0x130(r12)
  mtlr      r12
  blrl      
  li        r3, 0x1

.loc_0x5C:
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
 * Address:	8007BB8C
 * Size:	000004
 */
void Piki::setFlower(int)
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	8007BB90
 * Size:	000120
 */
void InteractSpore::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r3, 0
  stw       r30, 0x28(r1)
  addi      r30, r4, 0
  addi      r3, r30, 0
  lwz       r12, 0x0(r30)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x40
  li        r3, 0
  b         .loc_0x108

.loc_0x40:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lwz       r12, 0x120(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x104
  lwz       r0, 0x2AC(r30)
  lwz       r31, 0x4(r31)
  cmplwi    r0, 0
  beq-      .loc_0xA8
  lis       r3, 0x802B
  lfs       f0, -0x76B0(r2)
  subi      r0, r3, 0x3064
  stw       r0, 0x18(r1)
  lis       r3, 0x802B
  subi      r0, r3, 0x2E74
  stw       r30, 0x1C(r1)
  addi      r4, r1, 0x18
  stw       r0, 0x18(r1)
  stfs      f0, 0x20(r1)
  lwz       r3, 0x2AC(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0xA0(r12)
  mtlr      r12
  blrl      

.loc_0xA8:
  stw       r31, 0x4A8(r30)
  li        r4, 0
  lwz       r3, 0x4F8(r30)
  bl        0x49700
  lwz       r3, 0x4F8(r30)
  li        r0, 0x16
  addi      r4, r31, 0
  sth       r0, 0x8(r3)
  lwz       r3, 0x4F8(r30)
  lha       r0, 0x8(r3)
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  add       r3, r3, r0
  bl        0x480B8
  lwz       r3, 0x490(r30)
  addi      r4, r30, 0
  li        r5, 0x1D
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  li        r3, 0x1
  b         .loc_0x108

.loc_0x104:
  li        r3, 0

.loc_0x108:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007BCB0
 * Size:	0000B4
 */
void InteractBubble::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x38
  li        r3, 0
  b         .loc_0xA0

.loc_0x38:
  mr        r3, r31
  bl        0x4C868
  subi      r0, r3, 0x6
  cmplwi    r0, 0x1
  ble-      .loc_0x54
  cmpwi     r3, 0xA
  bne-      .loc_0x5C

.loc_0x54:
  li        r3, 0
  b         .loc_0xA0

.loc_0x5C:
  lhz       r0, 0x510(r31)
  cmplwi    r0, 0
  beq-      .loc_0x9C
  lwz       r5, 0x504(r31)
  addi      r3, r31, 0
  li        r4, 0
  bl        0x514A8
  lwz       r3, 0x490(r31)
  addi      r4, r31, 0
  li        r5, 0xA
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  li        r3, 0x1
  b         .loc_0xA0

.loc_0x9C:
  li        r3, 0

.loc_0xA0:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007BD64
 * Size:	00007C
 */
void InteractFire::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x38
  li        r3, 0
  b         .loc_0x68

.loc_0x38:
  lhz       r0, 0x510(r31)
  cmplwi    r0, 0x1
  beq-      .loc_0x54
  mr        r3, r31
  bl        0x4C0E0
  li        r3, 0x1
  b         .loc_0x68

.loc_0x54:
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x27
  addi      r3, r3, 0x70
  bl        0x7C3C
  li        r3, 0

.loc_0x68:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007BDE0
 * Size:	000008
 */
void InteractWind::actCommon(Creature *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007BDE8
 * Size:	000108
 */
void InteractWind::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x40
  li        r3, 0
  b         .loc_0xF0

.loc_0x40:
  mr        r3, r31
  bl        0x4C728
  cmpwi     r3, 0x6
  beq-      .loc_0x5C
  subi      r0, r3, 0x18
  cmplwi    r0, 0x1
  bgt-      .loc_0x64

.loc_0x5C:
  li        r3, 0
  b         .loc_0xF0

.loc_0x64:
  lwz       r0, 0x184(r31)
  cmplwi    r0, 0
  beq-      .loc_0x78
  li        r3, 0
  b         .loc_0xF0

.loc_0x78:
  lhz       r0, 0x4FC(r31)
  cmpwi     r0, 0xB
  beq-      .loc_0x8C
  cmpwi     r0, 0xC
  bne-      .loc_0x94

.loc_0x8C:
  li        r3, 0
  b         .loc_0xF0

.loc_0x94:
  lwz       r3, 0x4F8(r31)
  lwz       r4, 0x18(r30)
  bl        0x494C0
  lwz       r3, 0x490(r31)
  addi      r4, r31, 0
  li        r5, 0x19
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0xC(r30)
  li        r3, 0x1
  lwz       r0, 0x10(r30)
  stw       r4, 0x70(r31)
  stw       r0, 0x74(r31)
  lwz       r0, 0x14(r30)
  stw       r0, 0x78(r31)
  lwz       r4, 0xC(r30)
  lwz       r0, 0x10(r30)
  stw       r4, 0xA4(r31)
  stw       r0, 0xA8(r31)
  lwz       r0, 0x14(r30)
  stw       r0, 0xAC(r31)

.loc_0xF0:
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
 * Address:	8007BEF0
 * Size:	00005C
 */
void InteractFlick::actCommon(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r4
  lwz       r0, 0xC8(r4)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x28
  mr        r3, r31
  bl        0x14108

.loc_0x28:
  lwz       r0, 0x184(r31)
  cmplwi    r0, 0
  beq-      .loc_0x44
  mr        r3, r31
  bl        0x14950
  mr        r3, r31
  bl        0x14AAC

.loc_0x44:
  lwz       r0, 0x24(r1)
  li        r3, 0x1
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007BF4C
 * Size:	0000EC
 */
void InteractFlick::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x40
  li        r3, 0
  b         .loc_0xD4

.loc_0x40:
  mr        r3, r31
  bl        0x4C5C4
  cmpwi     r3, 0x16
  bne-      .loc_0x58
  li        r3, 0
  b         .loc_0xD4

.loc_0x58:
  lwz       r4, 0x4(r30)
  addi      r3, r31, 0
  li        r5, 0x1A
  bl        0xE604
  lfs       f1, 0x58(r31)
  addi      r3, r31, 0x1E0
  lfs       f0, 0xC(r30)
  fsubs     f0, f1, f0
  stfs      f0, 0x58(r31)
  lwz       r4, 0x224(r31)
  lfs       f1, 0x58(r31)
  lfs       f2, 0xB8(r4)
  bl        -0x1FF60
  lfs       f1, 0x10(r30)
  lfs       f0, -0x76AC(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xA8
  lfs       f0, 0xA0(r31)
  stfs      f0, 0x49C(r31)
  b         .loc_0xAC

.loc_0xA8:
  stfs      f1, 0x49C(r31)

.loc_0xAC:
  lfs       f0, 0x8(r30)
  addi      r4, r31, 0
  li        r5, 0x16
  stfs      f0, 0x498(r31)
  lwz       r3, 0x490(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  li        r3, 0x1

.loc_0xD4:
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
 * Address:	8007C038
 * Size:	000008
 */
void InteractSlimeAttack::actCommon(Creature *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C040
 * Size:	00018C
 */
void InteractAttack::getDamagePortion()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  lwz       r4, 0xC(r3)
  cmplwi    r4, 0
  beq-      .loc_0x170
  addi      r3, r1, 0xC
  bl        0xBE78
  addi      r30, r1, 0xC
  lis       r31, 0x2A2A
  addi      r3, r30, 0
  addi      r4, r31, 0x2A30
  li        r5, 0x2A
  bl        -0x38194
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x50
  li        r3, 0
  b         .loc_0x174

.loc_0x50:
  addi      r3, r30, 0
  addi      r4, r31, 0x2A31
  li        r5, 0x2A
  bl        -0x381B4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x70
  li        r3, 0x1
  b         .loc_0x174

.loc_0x70:
  addi      r3, r30, 0
  addi      r4, r31, 0x2A32
  li        r5, 0x2A
  bl        -0x381D4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x90
  li        r3, 0x2
  b         .loc_0x174

.loc_0x90:
  addi      r3, r30, 0
  addi      r4, r31, 0x2A33
  li        r5, 0x2A
  bl        -0x381F4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xB0
  li        r3, 0x3
  b         .loc_0x174

.loc_0xB0:
  addi      r3, r30, 0
  addi      r4, r31, 0x2A34
  li        r5, 0x2A
  bl        -0x38214
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD0
  li        r3, 0x4
  b         .loc_0x174

.loc_0xD0:
  addi      r3, r30, 0
  addi      r4, r31, 0x2A35
  li        r5, 0x2A
  bl        -0x38234
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xF0
  li        r3, 0x5
  b         .loc_0x174

.loc_0xF0:
  addi      r3, r30, 0
  addi      r4, r31, 0x2A36
  li        r5, 0x2A
  bl        -0x38254
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x110
  li        r3, 0x6
  b         .loc_0x174

.loc_0x110:
  addi      r3, r30, 0
  addi      r4, r31, 0x2A37
  li        r5, 0x2A
  bl        -0x38274
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x130
  li        r3, 0x7
  b         .loc_0x174

.loc_0x130:
  addi      r3, r30, 0
  addi      r4, r31, 0x2A38
  li        r5, 0x2A
  bl        -0x38294
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x150
  li        r3, 0x8
  b         .loc_0x174

.loc_0x150:
  addi      r3, r30, 0
  addi      r4, r31, 0x2A39
  li        r5, 0x2A
  bl        -0x382B4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x170
  li        r3, 0x9
  b         .loc_0x174

.loc_0x170:
  li        r3, -0x1

.loc_0x174:
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
 * Address:	8007C1CC
 * Size:	000044
 */
void InteractAttack::actCommon(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  mr        r3, r4
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x0(r4)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x30
  li        r3, 0
  b         .loc_0x34

.loc_0x30:
  li        r3, 0x1

.loc_0x34:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C210
 * Size:	000008
 */
void Creature::isVisible()
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C218
 * Size:	000188
 */
void InteractAttack::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  stw       r30, 0x30(r1)
  addi      r30, r3, 0
  stw       r29, 0x2C(r1)
  addi      r29, r4, 0
  addi      r3, r29, 0
  lwz       r12, 0x0(r29)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x44
  li        r3, 0
  b         .loc_0x16C

.loc_0x44:
  mr        r3, r29
  bl        0x4C2F4
  addi      r31, r3, 0
  subi      r0, r31, 0x6
  cmplwi    r0, 0x1
  bgt-      .loc_0x64
  li        r3, 0
  b         .loc_0x16C

.loc_0x64:
  cmpwi     r31, 0x16
  bne-      .loc_0x74
  li        r3, 0
  b         .loc_0x16C

.loc_0x74:
  lwz       r4, 0x4(r30)
  addi      r3, r29, 0
  li        r5, 0x1A
  bl        0xE31C
  mr        r3, r29
  bl        0x4DD00
  lfs       f1, 0x58(r29)
  addi      r3, r29, 0x1E0
  lfs       f0, 0x8(r30)
  fsubs     f0, f1, f0
  stfs      f0, 0x58(r29)
  lwz       r4, 0x224(r29)
  lfs       f1, 0x58(r29)
  lfs       f2, 0xB8(r4)
  bl        -0x20250
  cmpwi     r31, 0x22
  bne-      .loc_0xD4
  lwz       r3, 0x490(r29)
  addi      r4, r29, 0
  li        r5, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      

.loc_0xD4:
  lfs       f0, -0x63F0(r13)
  stfs      f0, 0xA4(r29)
  lfs       f0, -0x63EC(r13)
  stfs      f0, 0xA8(r29)
  lfs       f0, -0x63E8(r13)
  stfs      f0, 0xAC(r29)
  lfs       f1, 0x58(r29)
  lfs       f0, -0x76B8(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0x128
  mr        r3, r29
  bl        0x4DD14
  lwz       r3, 0x490(r29)
  addi      r4, r29, 0
  li        r5, 0x6
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  b         .loc_0x168

.loc_0x128:
  cmplwi    r29, 0
  addi      r30, r29, 0
  beq-      .loc_0x138
  addi      r30, r30, 0x2B8

.loc_0x138:
  addi      r3, r1, 0x18
  li        r4, 0xA
  bl        0xA2C00
  addi      r31, r3, 0
  addi      r5, r30, 0
  addi      r3, r1, 0x20
  li        r4, 0xA
  bl        0xA2C20
  addi      r4, r3, 0
  addi      r3, r29, 0
  addi      r5, r31, 0
  bl        0x4E65C

.loc_0x168:
  li        r3, 0x1

.loc_0x16C:
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
 * Address:	8007C3A0
 * Size:	000008
 */
void InteractSwallow::actCommon(Creature *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C3A8
 * Size:	0002F0
 */
void InteractSwallow::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  stmw      r27, 0x64(r1)
  addi      r31, r4, 0
  addi      r30, r3, 0
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x4F8(r31)
  li        r4, 0
  bl        0x48F68
  lwz       r3, 0x4F8(r31)
  li        r0, 0xF
  li        r4, 0
  sth       r0, 0x8(r3)
  lwz       r3, 0x4F8(r31)
  lha       r0, 0x8(r3)
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  add       r3, r3, r0
  bl        0x47920
  li        r0, 0
  sth       r0, 0x4FC(r31)
  lwz       r0, 0xC(r30)
  cmplwi    r0, 0
  bne-      .loc_0x98
  lwz       r4, 0x4(r30)
  addi      r3, r31, 0
  li        r5, 0x16
  bl        0xE18C
  addi      r3, r31, 0
  li        r4, 0
  bl        0xE8AC
  li        r3, 0x1
  b         .loc_0x2DC

.loc_0x98:
  mr        r3, r31
  stw       r0, 0x4A4(r31)
  bl        0x4C10C
  lwz       r0, 0x8(r30)
  cmpwi     r0, 0
  bne-      .loc_0xE0
  addi      r3, r1, 0x30
  li        r4, 0x46
  bl        0xA2AF8
  addi      r29, r3, 0
  addi      r3, r1, 0x38
  li        r4, 0x46
  bl        0xA2AE8
  addi      r4, r3, 0
  addi      r3, r31, 0
  addi      r5, r29, 0
  bl        0x4E558
  b         .loc_0x10C

.loc_0xE0:
  addi      r3, r1, 0x20
  li        r4, 0x1D
  bl        0xA2AC8
  addi      r29, r3, 0
  addi      r3, r1, 0x28
  li        r4, 0x1D
  bl        0xA2AB8
  addi      r4, r3, 0
  addi      r3, r31, 0
  addi      r5, r29, 0
  bl        0x4E528

.loc_0x10C:
  lwz       r3, 0x490(r31)
  addi      r4, r31, 0
  li        r5, 0x8
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x184(r31)
  cmplwi    r0, 0
  beq-      .loc_0x150
  lwz       r0, 0xC8(r31)
  rlwinm.   r0,r0,0,16,16
  bne-      .loc_0x150
  mr        r3, r31
  bl        0x1438C
  mr        r3, r31
  bl        0x144E8

.loc_0x150:
  lwz       r4, 0x4(r30)
  mr        r3, r31
  lwz       r5, 0xC(r30)
  bl        0x13A94
  lwz       r0, 0xC8(r31)
  rlwinm.   r0,r0,0,16,16
  bne-      .loc_0x17C
  li        r0, 0
  stw       r0, 0x4A4(r31)
  li        r3, 0
  b         .loc_0x2DC

.loc_0x17C:
  addi      r3, r1, 0x50
  lwz       r4, 0x4(r30)
  bl        0x14758
  addi      r29, r1, 0x50
  addi      r3, r29, 0
  lwz       r12, 0x0(r29)
  li        r27, 0
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r28, r3
  b         .loc_0x218

.loc_0x1AC:
  cmpwi     r28, -0x1
  bne-      .loc_0x1D0
  mr        r3, r29
  lwz       r12, 0x0(r29)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x1E8

.loc_0x1D0:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x1E8:
  cmplw     r3, r31
  bne-      .loc_0x1F4
  li        r27, 0x1

.loc_0x1F4:
  lwz       r0, 0xC8(r3)
  rlwinm.   r0,r0,0,16,16
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r28, r3

.loc_0x218:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x240
  li        r0, 0x1
  b         .loc_0x26C

.loc_0x240:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x268
  li        r0, 0x1
  b         .loc_0x26C

.loc_0x268:
  li        r0, 0

.loc_0x26C:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x1AC
  rlwinm.   r0,r27,0,24,31
  bne-      .loc_0x294
  lwz       r3, 0x4(r30)
  lwz       r3, 0x180(r3)
  b         .loc_0x28C

.loc_0x288:
  lwz       r3, 0x18C(r3)

.loc_0x28C:
  cmplwi    r3, 0
  bne+      .loc_0x288

.loc_0x294:
  lwz       r4, 0x4(r30)
  addi      r3, r31, 0
  li        r5, 0x16
  bl        0xDF6C
  lhz       r0, 0x426(r31)
  cmplwi    r0, 0
  beq-      .loc_0x2D0
  li        r30, 0
  sth       r30, 0x426(r31)
  lwz       r3, 0x430(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  stb       r30, 0x424(r31)

.loc_0x2D0:
  li        r0, 0
  sth       r0, 0x426(r31)
  li        r3, 0x1

.loc_0x2DC:
  lmw       r27, 0x64(r1)
  lwz       r0, 0x7C(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C698
 * Size:	000008
 */
void Condition::satisfy(Creature *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C6A0
 * Size:	000048
 */
void InteractKill::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x8(r3)
  cmpwi     r0, 0x1
  bne-      .loc_0x28
  addi      r3, r4, 0
  li        r4, 0x1
  bl        0xE620
  b         .loc_0x34

.loc_0x28:
  addi      r3, r4, 0
  li        r4, 0
  bl        0xE610

.loc_0x34:
  li        r3, 0x1
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C6E8
 * Size:	00002C
 */
void InteractKill::actNavi(Navi *)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r4, 0
  stw       r0, 0x4(r1)
  li        r4, 0
  stwu      r1, -0x8(r1)
  bl        0xE5E4
  li        r3, 0x1
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C714
 * Size:	000138
 */
void InteractPress::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  stw       r30, 0x38(r1)
  addi      r30, r4, 0
  stw       r29, 0x34(r1)
  addi      r29, r3, 0
  addi      r3, r30, 0
  bl        0x4BE1C
  cmpwi     r3, 0x21
  bne-      .loc_0x38
  li        r3, 0
  b         .loc_0x11C

.loc_0x38:
  lwz       r4, 0x4(r29)
  addi      r3, r30, 0
  li        r5, 0x1B
  bl        0xDE5C
  mr        r3, r30
  bl        0x4B710
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xA4
  lwz       r31, 0x2AC(r30)
  mr        r3, r31
  bl        0xE260
  lwz       r0, 0x6C(r31)
  cmpwi     r0, 0xE
  bne-      .loc_0xA4
  li        r0, 0xA
  stw       r0, 0x24(r1)
  li        r0, 0x1
  addi      r4, r31, 0
  stw       r0, 0x28(r1)
  li        r0, 0
  addi      r5, r1, 0x24
  stw       r0, 0x2D0(r31)
  lwz       r3, 0x2E8(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      

.loc_0xA4:
  lwz       r5, 0x504(r30)
  addi      r3, r30, 0
  li        r4, 0
  bl        0x50A08
  lwz       r3, 0x490(r30)
  addi      r4, r30, 0
  li        r5, 0x21
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x224(r30)
  addi      r3, r30, 0x1E0
  lfs       f0, 0x168(r4)
  stfs      f0, 0x48C(r30)
  lfs       f1, 0x58(r30)
  lfs       f0, 0x8(r29)
  fsubs     f0, f1, f0
  stfs      f0, 0x58(r30)
  lwz       r4, 0x224(r30)
  lfs       f1, 0x58(r30)
  lfs       f2, 0xB8(r4)
  bl        -0x2079C
  lfs       f0, -0x63E4(r13)
  li        r3, 0x1
  stfs      f0, 0xA4(r30)
  lfs       f0, -0x63E0(r13)
  stfs      f0, 0xA8(r30)
  lfs       f0, -0x63DC(r13)
  stfs      f0, 0xAC(r30)

.loc_0x11C:
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  lwz       r29, 0x34(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C84C
 * Size:	000008
 */
void InteractFlute::actTeki(Teki *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C854
 * Size:	000008
 */
void Interaction::actCommon(Creature *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C85C
 * Size:	000008
 */
void Interaction::actPiki(Piki *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C864
 * Size:	000008
 */
void Interaction::actNavi(Navi *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C86C
 * Size:	000008
 */
void Interaction::actBoss(Boss *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C874
 * Size:	000008
 */
void Interaction::actPellet(Pellet *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C87C
 * Size:	000008
 */
void Interaction::actHinderRock(HinderRock *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C884
 * Size:	000008
 */
void Interaction::actBridge(Bridge *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C88C
 * Size:	000008
 */
void Interaction::actItem(ItemCreature *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C894
 * Size:	000008
 */
void Interaction::actTeki(Teki *)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}