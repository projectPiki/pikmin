

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
 * Address:	80176104
 * Size:	0001AC
 */
void KoganeAi::createWaterEffect()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0xF
  stw       r0, 0x4(r1)
  li        r6, 0
  li        r7, 0
  stwu      r1, -0x70(r1)
  stw       r31, 0x6C(r1)
  mr        r31, r3
  lwz       r5, 0xC(r31)
  lwz       r3, 0x3180(r13)
  addi      r5, r5, 0x94
  bl        0x26A08
  lwz       r0, 0xC(r31)
  addi      r5, r1, 0x5C
  lwz       r3, 0x8(r31)
  li        r4, 0xE
  li        r7, 0
  stw       r0, 0x4(r3)
  lfs       f0, 0x500(r13)
  lfs       f1, 0x504(r13)
  stfs      f0, 0x5C(r1)
  lfs       f0, 0x508(r13)
  stfs      f1, 0x60(r1)
  lwz       r3, 0x3180(r13)
  stfs      f0, 0x64(r1)
  lwz       r6, 0x8(r31)
  bl        0x269CC
  cmplwi    r3, 0
  beq-      .loc_0xB0
  lwz       r4, 0xC(r31)
  addi      r0, r4, 0x94
  stw       r0, 0x18(r3)
  lfs       f0, 0x50C(r13)
  lfs       f1, 0x510(r13)
  stfs      f0, 0x50(r1)
  lfs       f0, 0x514(r13)
  stfs      f1, 0x54(r1)
  stfs      f0, 0x58(r1)
  lwz       r4, 0x50(r1)
  lwz       r0, 0x54(r1)
  stw       r4, 0x1DC(r3)
  stw       r0, 0x1E0(r3)
  lwz       r0, 0x58(r1)
  stw       r0, 0x1E4(r3)

.loc_0xB0:
  lfs       f0, 0x518(r13)
  addi      r5, r1, 0x44
  lfs       f1, 0x51C(r13)
  li        r4, 0xC
  stfs      f0, 0x44(r1)
  lfs       f0, 0x520(r13)
  li        r7, 0
  stfs      f1, 0x48(r1)
  lwz       r3, 0x3180(r13)
  stfs      f0, 0x4C(r1)
  lwz       r6, 0x8(r31)
  bl        0x26958
  cmplwi    r3, 0
  beq-      .loc_0x124
  lwz       r4, 0xC(r31)
  addi      r0, r4, 0x94
  stw       r0, 0x18(r3)
  lfs       f0, 0x524(r13)
  lfs       f1, 0x528(r13)
  stfs      f0, 0x38(r1)
  lfs       f0, 0x52C(r13)
  stfs      f1, 0x3C(r1)
  stfs      f0, 0x40(r1)
  lwz       r4, 0x38(r1)
  lwz       r0, 0x3C(r1)
  stw       r4, 0x1DC(r3)
  stw       r0, 0x1E0(r3)
  lwz       r0, 0x40(r1)
  stw       r0, 0x1E4(r3)

.loc_0x124:
  lfs       f0, 0x530(r13)
  addi      r5, r1, 0x2C
  lfs       f1, 0x534(r13)
  li        r4, 0xD
  stfs      f0, 0x2C(r1)
  lfs       f0, 0x538(r13)
  li        r7, 0
  stfs      f1, 0x30(r1)
  lwz       r3, 0x3180(r13)
  stfs      f0, 0x34(r1)
  lwz       r6, 0x8(r31)
  bl        0x268E4
  cmplwi    r3, 0
  beq-      .loc_0x198
  lwz       r4, 0xC(r31)
  addi      r0, r4, 0x94
  stw       r0, 0x18(r3)
  lfs       f0, 0x53C(r13)
  lfs       f1, 0x540(r13)
  stfs      f0, 0x20(r1)
  lfs       f0, 0x544(r13)
  stfs      f1, 0x24(r1)
  stfs      f0, 0x28(r1)
  lwz       r4, 0x20(r1)
  lwz       r0, 0x24(r1)
  stw       r4, 0x1DC(r3)
  stw       r0, 0x1E0(r3)
  lwz       r0, 0x28(r1)
  stw       r0, 0x1E4(r3)

.loc_0x198:
  lwz       r0, 0x74(r1)
  lwz       r31, 0x6C(r1)
  addi      r1, r1, 0x70
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801762B0
 * Size:	000038
 */
void KoganeAi::killCallBackEffect(bool)
{
/*
.loc_0x0:
  mflr      r0
  addi      r6, r4, 0
  stw       r0, 0x4(r1)
  li        r5, 0
  stwu      r1, -0x8(r1)
  lwz       r0, 0x8(r3)
  lwz       r3, 0x3180(r13)
  mr        r4, r0
  addi      r3, r3, 0x14
  bl        0x2B388
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801762E8
 * Size:	000074
 */
void KoganeAi::KoganeAi(Kogane *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x802B
  stw       r0, 0x4(r1)
  subi      r0, r5, 0x246C
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  lis       r3, 0x802D
  stw       r0, 0x0(r31)
  addi      r0, r3, 0x9F8
  li        r3, 0x8
  stw       r0, 0x0(r31)
  stw       r4, 0xC(r31)
  bl        -0x12F318
  cmplwi    r3, 0
  beq-      .loc_0x58
  lis       r4, 0x802B
  addi      r0, r4, 0x600
  lis       r4, 0x802D
  stw       r0, 0x0(r3)
  addi      r0, r4, 0xA54
  stw       r0, 0x0(r3)

.loc_0x58:
  stw       r3, 0x8(r31)
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
 * Address:	8017635C
 * Size:	000110
 */
void KoganeAi::initAI(Kogane *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0x1
  stwu      r1, -0x70(r1)
  stfd      f31, 0x68(r1)
  stw       r31, 0x64(r1)
  mr        r31, r3
  addi      r5, r31, 0
  stw       r4, 0xC(r3)
  li        r4, 0x6
  lwz       r6, 0xC(r3)
  addi      r3, r1, 0x50
  lfs       f0, 0x548(r13)
  stfsu     f0, 0x7C(r6)
  lfs       f0, 0x54C(r13)
  stfs      f0, 0x4(r6)
  lfs       f0, 0x550(r13)
  stfs      f0, 0x8(r6)
  lwz       r6, 0xC(r31)
  stw       r0, 0x2E4(r6)
  lwz       r6, 0xC(r31)
  stw       r0, 0x2E8(r6)
  bl        -0x57428
  lwz       r5, 0xC(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x57204
  li        r3, 0
  stb       r3, 0x4(r31)
  li        r0, -0x1
  stw       r3, 0x10(r31)
  stw       r0, 0x14(r31)
  lwz       r3, 0xC(r31)
  lfs       f0, -0x52A0(r2)
  lwz       r4, 0x224(r3)
  lfs       f2, 0x2B0(r4)
  lfs       f1, 0x2A0(r4)
  fsubs     f31, f2, f1
  fcmpo     cr0, f31, f0
  ble-      .loc_0xA4
  b         .loc_0xA8

.loc_0xA4:
  fneg      f31, f31

.loc_0xA8:
  bl        0xA1C6C
  xoris     r0, r3, 0x8000
  lfs       f0, -0x5294(r2)
  stw       r0, 0x5C(r1)
  lis       r0, 0x4330
  lwz       r3, 0xC(r31)
  fmuls     f0, f0, f31
  stw       r0, 0x58(r1)
  lwz       r3, 0x224(r3)
  lfd       f2, -0x5290(r2)
  lfd       f1, 0x58(r1)
  lfs       f3, -0x5298(r2)
  fsubs     f4, f1, f2
  lfs       f2, -0x529C(r2)
  lfs       f1, 0x2A0(r3)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x18(r31)
  lwz       r0, 0x74(r1)
  lfd       f31, 0x68(r1)
  lwz       r31, 0x64(r1)
  addi      r1, r1, 0x70
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017646C
 * Size:	00007C
 */
void KoganeAi::animationKeyUpdated(PaniAnimKeyEvent &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x0(r4)
  cmpwi     r0, 0x2
  beq-      .loc_0x4C
  bge-      .loc_0x2C
  cmpwi     r0, 0
  beq-      .loc_0x5C
  bge-      .loc_0x44
  b         .loc_0x6C

.loc_0x2C:
  cmpwi     r0, 0x7
  beq-      .loc_0x64
  bge-      .loc_0x6C
  cmpwi     r0, 0x6
  bge-      .loc_0x54
  b         .loc_0x6C

.loc_0x44:
  bl        .loc_0x7C
  b         .loc_0x6C

.loc_0x4C:
  bl        0x8C
  b         .loc_0x6C

.loc_0x54:
  bl        0x12C
  b         .loc_0x6C

.loc_0x5C:
  bl        0x138
  b         .loc_0x6C

.loc_0x64:
  lwz       r4, 0x4(r4)
  bl        0x154

.loc_0x6C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr       

.loc_0x7C:
*/
}

/*
 * --INFO--
 * Address:	801764E8
 * Size:	00005C
 */
void KoganeAi::keyAction0()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0xC(r3)
  lwz       r0, 0x2E4(r5)
  cmpwi     r0, 0x4
  bne-      .loc_0x24
  bl        0x9D8
  b         .loc_0x4C

.loc_0x24:
  cmpwi     r0, 0x2
  bne-      .loc_0x4C
  lwz       r4, 0x14(r3)
  cmpwi     r4, 0
  blt-      .loc_0x4C
  lwz       r3, 0x3180(r13)
  addi      r5, r5, 0x94
  li        r6, 0
  li        r7, 0
  bl        0x26608

.loc_0x4C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80176544
 * Size:	0000A8
 */
void KoganeAi::keyAction1()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lwz       r4, 0xC(r3)
  lwz       r0, 0x2E4(r4)
  cmpwi     r0, 0x4
  bne-      .loc_0x94
  lbz       r0, 0x4(r31)
  cmplwi    r0, 0
  beq-      .loc_0x64
  lwz       r3, 0x3180(r13)
  addi      r5, r4, 0x94
  li        r4, 0xF
  li        r6, 0
  li        r7, 0
  bl        0x265B0
  lwz       r6, 0xC(r31)
  li        r4, 0xF
  lwz       r3, 0x3178(r13)
  li        r5, 0
  addi      r6, r6, 0x94
  bl        0x6834
  b         .loc_0x94

.loc_0x64:
  lwz       r3, 0x3180(r13)
  addi      r5, r4, 0x94
  li        r4, 0x78
  li        r6, 0
  li        r7, 0
  bl        0x2657C
  lwz       r6, 0xC(r31)
  li        r4, 0xF
  lwz       r3, 0x3178(r13)
  li        r5, 0
  addi      r6, r6, 0x94
  bl        0x6800

.loc_0x94:
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
 * Size:	000004
 */
void KoganeAi::keyAction2()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void KoganeAi::keyAction3()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801765EC
 * Size:	000014
 */
void KoganeAi::keyLoopEnd()
{
/*
.loc_0x0:
  lwz       r4, 0xC(r3)
  lwz       r3, 0x2EC(r4)
  addi      r0, r3, 0x1
  stw       r0, 0x2EC(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	80176600
 * Size:	000028
 */
void KoganeAi::keyFinished()
{
/*
.loc_0x0:
  lwz       r4, 0xC(r3)
  li        r0, 0x1
  stb       r0, 0x2BD(r4)
  lwz       r3, 0xC(r3)
  lwz       r0, 0x2E4(r3)
  cmpwi     r0, 0x4
  bnelr-    
  li        r0, 0
  stb       r0, 0x3B9(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80176628
 * Size:	00003C
 */
void KoganeAi::playSound(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0xC(r3)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2C
  rlwinm    r0,r4,2,0,29
  addi      r4, r13, 0x4F8
  lwzx      r4, r4, r0
  bl        -0xD2880

.loc_0x2C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void KoganeAi::setEveryFrame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80176664
 * Size:	0000DC
 */
void KoganeAi::setMapAttribute()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r3, 0xC(r3)
  addi      r4, r3, 0x94
  bl        -0x27314
  addi      r31, r3, 0
  cmplwi    r31, 0x6
  bgt-      .loc_0xB4
  lis       r3, 0x802D
  addi      r3, r3, 0x9BC
  rlwinm    r0,r31,2,0,29
  lwzx      r0, r3, r0
  mtctr     r0
  bctr      
  li        r0, 0x13
  stw       r0, 0x14(r30)
  b         .loc_0xB4
  li        r0, 0x11
  stw       r0, 0x14(r30)
  b         .loc_0xB4
  li        r0, 0x12
  stw       r0, 0x14(r30)
  b         .loc_0xB4
  li        r0, 0x10
  stw       r0, 0x14(r30)
  b         .loc_0xB4
  li        r0, 0x13
  stw       r0, 0x14(r30)
  b         .loc_0xB4
  lbz       r0, 0x4(r30)
  cmplwi    r0, 0
  bne-      .loc_0xB4
  li        r0, 0x1
  stb       r0, 0x4(r30)
  li        r0, -0x1
  addi      r3, r30, 0
  stw       r0, 0x14(r30)
  bl        -0x604
  b         .loc_0xB4
  li        r0, 0x13
  stw       r0, 0x14(r30)

.loc_0xB4:
  cmpwi     r31, 0x5
  beq-      .loc_0xC4
  li        r0, 0
  stb       r0, 0x4(r30)

.loc_0xC4:
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
 * Address:	........
 * Size:	000028
 */
void KoganeAi::checkAppearTimeCounter()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void KoganeAi::calcScaleUp()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80176740
 * Size:	0001E8
 */
void KoganeAi::setNewTargetPosition()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xC8(r1)
  stfd      f31, 0xC0(r1)
  stfd      f30, 0xB8(r1)
  stfd      f29, 0xB0(r1)
  stw       r31, 0xAC(r1)
  stw       r30, 0xA8(r1)
  mr        r30, r3
  lwz       r3, 0xC(r3)
  lfs       f0, -0x52A0(r2)
  lwz       r4, 0x224(r3)
  lfs       f31, 0xA0(r3)
  lfs       f2, 0x270(r4)
  lfs       f1, 0x260(r4)
  fsubs     f30, f2, f1
  fcmpo     cr0, f30, f0
  ble-      .loc_0x4C
  b         .loc_0x50

.loc_0x4C:
  fneg      f30, f30

.loc_0x50:
  bl        0xA18E0
  xoris     r0, r3, 0x8000
  lfs       f0, -0x5294(r2)
  stw       r0, 0xA4(r1)
  lis       r0, 0x4330
  fmuls     f3, f0, f30
  lwz       r3, 0xC(r30)
  stw       r0, 0xA0(r1)
  lfd       f2, -0x5290(r2)
  lfd       f1, 0xA0(r1)
  lfs       f0, -0x5298(r2)
  fsubs     f4, f1, f2
  lwz       r4, 0x224(r3)
  lfs       f6, -0x529C(r2)
  lfs       f2, 0x290(r4)
  fdivs     f7, f4, f0
  lfs       f1, 0x280(r4)
  lfs       f4, 0x260(r4)
  lfs       f0, -0x52A0(r2)
  lfs       f5, -0x5288(r2)
  fmuls     f6, f6, f7
  fsubs     f29, f2, f1
  fmuls     f1, f3, f6
  fcmpo     cr0, f29, f0
  fadds     f0, f4, f1
  fmuls     f30, f5, f0
  ble-      .loc_0xC0
  b         .loc_0xC4

.loc_0xC0:
  fneg      f29, f29

.loc_0xC4:
  bl        0xA186C
  xoris     r0, r3, 0x8000
  lfs       f0, -0x5294(r2)
  stw       r0, 0xA4(r1)
  lis       r31, 0x4330
  lwz       r3, 0xC(r30)
  fmuls     f1, f0, f29
  stw       r31, 0xA0(r1)
  lfd       f2, -0x5290(r2)
  lfd       f0, 0xA0(r1)
  lfs       f4, -0x5298(r2)
  fsubs     f5, f0, f2
  lwz       r3, 0x224(r3)
  lfs       f3, -0x529C(r2)
  lfs       f2, 0x280(r3)
  fdivs     f4, f5, f4
  lfs       f0, -0x52A0(r2)
  stfs      f0, 0x90(r1)
  stfs      f0, 0x8C(r1)
  stfs      f0, 0x88(r1)
  fmuls     f0, f3, f4
  fmuls     f0, f1, f0
  fadds     f29, f2, f0
  bl        0xA1810
  xoris     r0, r3, 0x8000
  lfd       f4, -0x5290(r2)
  stw       r0, 0x9C(r1)
  lfs       f3, -0x5298(r2)
  stw       r31, 0x98(r1)
  lfs       f2, -0x529C(r2)
  lfd       f0, 0x98(r1)
  lfs       f1, -0x5294(r2)
  fsubs     f4, f0, f4
  lfs       f0, -0x5284(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f1, f1, f2
  fcmpo     cr0, f1, f0
  ble-      .loc_0x168
  fadds     f31, f31, f30
  b         .loc_0x16C

.loc_0x168:
  fsubs     f31, f31, f30

.loc_0x16C:
  fmr       f1, f31
  bl        0xA52A4
  lwz       r3, 0xC(r30)
  fmuls     f2, f29, f1
  fmr       f1, f31
  lfs       f0, 0x9C(r3)
  fadds     f30, f0, f2
  bl        0xA5420
  lwz       r4, 0xC(r30)
  fmuls     f2, f29, f1
  lfs       f0, 0x554(r13)
  lfs       f1, 0x94(r4)
  fadds     f1, f1, f2
  stfs      f1, 0x88(r1)
  stfs      f0, 0x8C(r1)
  stfs      f30, 0x90(r1)
  lwz       r3, 0x88(r1)
  lwz       r0, 0x8C(r1)
  stw       r3, 0x30C(r4)
  stw       r0, 0x310(r4)
  lwz       r0, 0x90(r1)
  stw       r0, 0x314(r4)
  lwz       r0, 0xCC(r1)
  lfd       f31, 0xC0(r1)
  lfd       f30, 0xB8(r1)
  lfd       f29, 0xB0(r1)
  lwz       r31, 0xAC(r1)
  lwz       r30, 0xA8(r1)
  addi      r1, r1, 0xC8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80176928
 * Size:	00022C
 */
void KoganeAi::setRouteTargetPosition()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x7465
  stw       r0, 0x4(r1)
  addi      r4, r4, 0x7374
  li        r6, 0
  stwu      r1, -0xE0(r1)
  stfd      f31, 0xD8(r1)
  stfd      f30, 0xD0(r1)
  stfd      f29, 0xC8(r1)
  stfd      f28, 0xC0(r1)
  stw       r31, 0xBC(r1)
  mr        r31, r3
  stw       r30, 0xB8(r1)
  lwz       r5, 0xC(r31)
  lwz       r3, 0x302C(r13)
  addi      r5, r5, 0x94
  bl        -0xD5880
  lwz       r4, 0xC(r31)
  lfs       f2, 0x0(r3)
  lfs       f1, 0x94(r4)
  lfs       f3, 0x8(r3)
  lfs       f0, 0x9C(r4)
  fsubs     f1, f2, f1
  fsubs     f2, f3, f0
  bl        0xA5070
  lwz       r3, 0xC(r31)
  fmr       f31, f1
  lfs       f0, -0x52A0(r2)
  lwz       r4, 0x224(r3)
  lfs       f2, 0x270(r4)
  lfs       f1, 0x260(r4)
  fsubs     f30, f2, f1
  fcmpo     cr0, f30, f0
  ble-      .loc_0x8C
  b         .loc_0x90

.loc_0x8C:
  fneg      f30, f30

.loc_0x90:
  bl        0xA16B8
  xoris     r0, r3, 0x8000
  lfs       f0, -0x5294(r2)
  stw       r0, 0xB4(r1)
  lis       r0, 0x4330
  fmuls     f3, f0, f30
  lwz       r3, 0xC(r31)
  stw       r0, 0xB0(r1)
  lfd       f2, -0x5290(r2)
  lfd       f1, 0xB0(r1)
  lfs       f0, -0x5298(r2)
  fsubs     f4, f1, f2
  lwz       r4, 0x224(r3)
  lfs       f6, -0x529C(r2)
  lfs       f2, 0x290(r4)
  fdivs     f7, f4, f0
  lfs       f1, 0x280(r4)
  lfs       f4, 0x260(r4)
  lfs       f0, -0x52A0(r2)
  lfs       f5, -0x5288(r2)
  fmuls     f6, f6, f7
  fsubs     f29, f2, f1
  fmuls     f1, f3, f6
  fcmpo     cr0, f29, f0
  fadds     f0, f4, f1
  fmuls     f30, f5, f0
  ble-      .loc_0x100
  b         .loc_0x104

.loc_0x100:
  fneg      f29, f29

.loc_0x104:
  bl        0xA1644
  xoris     r0, r3, 0x8000
  lfs       f0, -0x5294(r2)
  stw       r0, 0xB4(r1)
  lis       r30, 0x4330
  lwz       r3, 0xC(r31)
  fmuls     f1, f0, f29
  stw       r30, 0xB0(r1)
  lfd       f2, -0x5290(r2)
  lfd       f0, 0xB0(r1)
  lfs       f4, -0x5298(r2)
  fsubs     f5, f0, f2
  lwz       r3, 0x224(r3)
  lfs       f3, -0x529C(r2)
  lfs       f2, 0x280(r3)
  fdivs     f4, f5, f4
  lfs       f0, -0x52A0(r2)
  stfs      f0, 0x94(r1)
  stfs      f0, 0x90(r1)
  stfs      f0, 0x8C(r1)
  fmuls     f0, f3, f4
  fmuls     f0, f1, f0
  fadds     f28, f2, f0
  bl        0xA15E8
  xoris     r0, r3, 0x8000
  lfd       f4, -0x5290(r2)
  stw       r0, 0xAC(r1)
  lfs       f3, -0x5298(r2)
  stw       r30, 0xA8(r1)
  lfs       f2, -0x529C(r2)
  lfd       f0, 0xA8(r1)
  lfs       f1, -0x5294(r2)
  fsubs     f4, f0, f4
  lfs       f0, -0x5284(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f1, f1, f2
  fcmpo     cr0, f1, f0
  ble-      .loc_0x1A8
  fadds     f29, f31, f30
  b         .loc_0x1AC

.loc_0x1A8:
  fsubs     f29, f31, f30

.loc_0x1AC:
  fmr       f1, f29
  bl        0xA507C
  lwz       r3, 0xC(r31)
  fmuls     f2, f28, f1
  fmr       f1, f29
  lfs       f0, 0x9C(r3)
  fadds     f30, f0, f2
  bl        0xA51F8
  lwz       r4, 0xC(r31)
  fmuls     f2, f28, f1
  lfs       f0, 0x558(r13)
  lfs       f1, 0x94(r4)
  fadds     f1, f1, f2
  stfs      f1, 0x8C(r1)
  stfs      f0, 0x90(r1)
  stfs      f30, 0x94(r1)
  lwz       r3, 0x8C(r1)
  lwz       r0, 0x90(r1)
  stw       r3, 0x30C(r4)
  stw       r0, 0x310(r4)
  lwz       r0, 0x94(r1)
  stw       r0, 0x314(r4)
  lwz       r0, 0xE4(r1)
  lfd       f31, 0xD8(r1)
  lfd       f30, 0xD0(r1)
  lfd       f29, 0xC8(r1)
  lfd       f28, 0xC0(r1)
  lwz       r31, 0xBC(r1)
  lwz       r30, 0xB8(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void KoganeAi::makeTargetRandom()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void KoganeAi::makeStopMoving()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80176B54
 * Size:	0001A8
 */
void KoganeAi::birthItemPellet(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stfd      f31, 0x58(r1)
  stfd      f30, 0x50(r1)
  stw       r31, 0x4C(r1)
  mr        r31, r4
  stw       r30, 0x48(r1)
  mr        r30, r3
  lwz       r3, 0xC(r3)
  lfs       f1, 0xA0(r3)
  bl        0xA5168
  lwz       r3, 0xC(r30)
  fneg      f31, f1
  lfs       f1, 0xA0(r3)
  bl        0xA4FC4
  lwz       r5, 0xC(r30)
  lis       r3, 0x6365
  fneg      f30, f1
  addi      r4, r3, 0x6E74
  lwz       r3, 0x220(r5)
  bl        -0xED498
  lfsu      f0, 0x4(r3)
  stfs      f0, 0x28(r1)
  lfs       f0, 0x4(r3)
  stfs      f0, 0x2C(r1)
  lfs       f0, 0x8(r3)
  stfs      f0, 0x30(r1)
  lfs       f2, -0x5280(r2)
  lfs       f3, 0x28(r1)
  fmuls     f1, f2, f31
  fmuls     f0, f2, f30
  fadds     f1, f3, f1
  stfs      f1, 0x28(r1)
  lfs       f1, 0x2C(r1)
  fadds     f1, f1, f2
  stfs      f1, 0x2C(r1)
  lfs       f1, 0x30(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x30(r1)
  lwz       r3, 0xC(r30)
  lwz       r0, 0x2F8(r3)
  cmpwi     r0, 0
  mr        r4, r0
  blt-      .loc_0xBC
  cmpwi     r0, 0x2
  ble-      .loc_0x100

.loc_0xBC:
  bl        0xA1460
  xoris     r0, r3, 0x8000
  lfd       f4, -0x5290(r2)
  stw       r0, 0x44(r1)
  lis       r0, 0x4330
  lfs       f2, -0x5298(r2)
  stw       r0, 0x40(r1)
  lfs       f1, -0x529C(r2)
  lfd       f3, 0x40(r1)
  lfs       f0, -0x527C(r2)
  fsubs     f3, f3, f4
  fdivs     f2, f3, f2
  fmuls     f1, f1, f2
  fmuls     f0, f0, f1
  fctiwz    f0, f0
  stfd      f0, 0x38(r1)
  lwz       r4, 0x3C(r1)

.loc_0x100:
  lwz       r3, 0x301C(r13)
  mr        r5, r31
  bl        -0xDE724
  mr.       r31, r3
  beq-      .loc_0x188
  mr        r3, r31
  lwz       r12, 0x0(r31)
  addi      r4, r1, 0x28
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lfs       f0, -0x5278(r2)
  addi      r3, r31, 0
  li        r4, 0
  fmuls     f1, f0, f31
  fmuls     f0, f0, f30
  stfs      f1, 0x70(r31)
  lfs       f1, 0x574(r13)
  stfs      f1, 0x74(r31)
  stfs      f0, 0x78(r31)
  lwz       r5, 0xC(r30)
  lfs       f0, 0xA0(r5)
  stfs      f0, 0xA0(r31)
  lwz       r12, 0x0(r31)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0xC(r30)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x188
  addi      r4, r13, 0x4F8
  lwz       r4, 0x4(r4)
  bl        -0xD2F08

.loc_0x188:
  lwz       r0, 0x64(r1)
  lfd       f31, 0x58(r1)
  lfd       f30, 0x50(r1)
  lwz       r31, 0x4C(r1)
  lwz       r30, 0x48(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80176CFC
 * Size:	0001E0
 */
void KoganeAi::birthItemWater(int, float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x88(r1)
  stfd      f31, 0x80(r1)
  stfd      f30, 0x78(r1)
  stfd      f29, 0x70(r1)
  stfd      f28, 0x68(r1)
  stfd      f27, 0x60(r1)
  stfd      f26, 0x58(r1)
  stfd      f25, 0x50(r1)
  stmw      r26, 0x38(r1)
  addi      r27, r4, 0
  cmpwi     r27, 0x1
  addi      r26, r3, 0
  bne-      .loc_0x4C
  lwz       r3, 0xC(r26)
  lfs       f29, -0x52A0(r2)
  lfs       f30, 0xA0(r3)
  b         .loc_0x90

.loc_0x4C:
  ble-      .loc_0x90
  subi      r0, r27, 0x1
  lfs       f0, -0x5274(r2)
  xoris     r0, r0, 0x8000
  lwz       r3, 0xC(r26)
  stw       r0, 0x34(r1)
  lis       r0, 0x4330
  lfd       f2, -0x5290(r2)
  fmuls     f4, f0, f1
  stw       r0, 0x30(r1)
  lfs       f1, -0x5284(r2)
  lfd       f0, 0x30(r1)
  fmuls     f1, f1, f4
  lfs       f3, 0xA0(r3)
  fsubs     f0, f0, f2
  fsubs     f30, f3, f1
  fdivs     f29, f4, f0

.loc_0x90:
  cmpwi     r27, 0
  ble-      .loc_0x1B0
  lfs       f26, -0x5270(r2)
  li        r29, 0
  lfd       f31, -0x5290(r2)
  lis       r30, 0x4330
  lfs       f25, -0x5280(r2)
  lis       r31, 0x6365
  b         .loc_0x1A8

.loc_0xB4:
  xoris     r0, r29, 0x8000
  stw       r0, 0x34(r1)
  stw       r30, 0x30(r1)
  lfd       f0, 0x30(r1)
  fsubs     f0, f0, f31
  fmuls     f0, f0, f29
  fadds     f27, f30, f0
  fmr       f1, f27
  bl        0xA4F18
  fneg      f28, f1
  fmr       f1, f27
  bl        0xA4D78
  lwz       r3, 0xC(r26)
  fneg      f27, f1
  addi      r4, r31, 0x6E74
  lwz       r3, 0x220(r3)
  bl        -0xED6E0
  lfsu      f2, 0x4(r3)
  fmuls     f1, f25, f28
  fmuls     f0, f25, f27
  li        r4, 0x6
  stfs      f2, 0x1C(r1)
  lfs       f2, 0x4(r3)
  stfs      f2, 0x20(r1)
  lfs       f2, 0x8(r3)
  stfs      f2, 0x24(r1)
  lfs       f2, 0x1C(r1)
  fadds     f1, f2, f1
  stfs      f1, 0x1C(r1)
  lfs       f1, 0x20(r1)
  fadds     f1, f1, f25
  stfs      f1, 0x20(r1)
  lfs       f1, 0x24(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x24(r1)
  lwz       r3, 0x30AC(r13)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x78(r12)
  mtlr      r12
  blrl      
  mr.       r28, r3
  beq-      .loc_0x1A4
  mr        r3, r28
  lwz       r12, 0x0(r28)
  addi      r4, r1, 0x1C
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  fmuls     f1, f26, f28
  mr        r3, r28
  fmuls     f0, f26, f27
  li        r4, 0
  stfs      f1, 0x70(r28)
  lfs       f1, 0x578(r13)
  stfs      f1, 0x74(r28)
  stfs      f0, 0x78(r28)
  lwz       r12, 0x0(r28)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      

.loc_0x1A4:
  addi      r29, r29, 0x1

.loc_0x1A8:
  cmpw      r29, r27
  blt+      .loc_0xB4

.loc_0x1B0:
  lmw       r26, 0x38(r1)
  lwz       r0, 0x8C(r1)
  lfd       f31, 0x80(r1)
  lfd       f30, 0x78(r1)
  lfd       f29, 0x70(r1)
  lfd       f28, 0x68(r1)
  lfd       f27, 0x60(r1)
  lfd       f26, 0x58(r1)
  lfd       f25, 0x50(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80176EDC
 * Size:	0000C4
 */
void KoganeAi::createPellet()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  lwz       r4, 0x10(r3)
  addi      r0, r4, 0x1
  stw       r0, 0x10(r3)
  lwz       r5, 0x10(r3)
  cmpwi     r5, 0x8
  bgt-      .loc_0xB4
  lis       r4, 0x8022
  addi      r7, r4, 0x2748
  lwz       r6, 0x0(r7)
  subi      r4, r5, 0x1
  lwz       r5, 0x4(r7)
  srawi     r0, r4, 0x2
  addze     r0, r0
  stw       r6, 0x10(r1)
  rlwinm    r0,r0,2,0,29
  subc      r0, r4, r0
  stw       r5, 0x14(r1)
  rlwinm    r0,r0,2,0,29
  addi      r4, r1, 0x10
  lwz       r6, 0x8(r7)
  lwz       r5, 0xC(r7)
  stw       r6, 0x18(r1)
  stw       r5, 0x1C(r1)
  lwzx      r0, r4, r0
  cmpwi     r0, 0x1
  beq-      .loc_0x9C
  bge-      .loc_0x84
  cmpwi     r0, 0
  bge-      .loc_0x90
  b         .loc_0xB4

.loc_0x84:
  cmpwi     r0, 0x3
  bge-      .loc_0xB4
  b         .loc_0xA8

.loc_0x90:
  li        r4, 0
  bl        -0x41C
  b         .loc_0xB4

.loc_0x9C:
  li        r4, 0x1
  bl        -0x428
  b         .loc_0xB4

.loc_0xA8:
  lfs       f1, -0x526C(r2)
  li        r4, 0x2
  bl        -0x290

.loc_0xB4:
  lwz       r0, 0x24(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void KoganeAi::resultFlagOn()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void KoganeAi::dieTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void KoganeAi::isMotionFinishTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80176FA0
 * Size:	0003A0
 */
void KoganeAi::appearTransit()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x88(r1)
  stfd      f31, 0x80(r1)
  stmw      r27, 0x6C(r1)
  mr        r31, r3
  lwz       r3, 0xC(r3)
  lbz       r0, 0x3B8(r3)
  cmplwi    r0, 0
  bne-      .loc_0x1CC
  lwz       r28, 0x3120(r13)
  mr        r3, r28
  lwz       r12, 0x0(r28)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lfs       f31, -0x52A0(r2)
  mr        r27, r3
  b         .loc_0x170

.loc_0x4C:
  cmpwi     r27, -0x1
  bne-      .loc_0x74
  mr        r3, r28
  lwz       r12, 0x0(r28)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0x90

.loc_0x74:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r27
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x90:
  addi      r29, r30, 0
  addi      r3, r29, 0
  lwz       r12, 0x0(r29)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x154
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x154
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x154
  lwz       r4, 0xC(r31)
  lfs       f1, 0x94(r29)
  lwz       r3, 0x224(r4)
  lfs       f2, 0x9C(r29)
  lfs       f3, 0x94(r4)
  addi      r29, r3, 0x210
  lfs       f4, 0x9C(r4)
  bl        -0x13EA7C
  lfs       f0, 0x0(r29)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x154
  lwz       r4, 0xC(r31)
  lfs       f1, 0x98(r30)
  lfs       f0, 0x98(r4)
  lwz       r3, 0x224(r4)
  fsubs     f1, f1, f0
  addi      r3, r3, 0x210
  fcmpo     cr0, f1, f31
  ble-      .loc_0x138
  b         .loc_0x13C

.loc_0x138:
  fneg      f1, f1

.loc_0x13C:
  lfs       f0, 0x0(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x154
  li        r0, 0x1
  stb       r0, 0x3B8(r4)
  b         .loc_0x1CC

.loc_0x154:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r27
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r27, r3

.loc_0x170:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r27
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x198
  li        r0, 0x1
  b         .loc_0x1C4

.loc_0x198:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r27
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x1C0
  li        r0, 0x1
  b         .loc_0x1C4

.loc_0x1C0:
  li        r0, 0

.loc_0x1C4:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x4C

.loc_0x1CC:
  lwz       r3, 0xC(r31)
  lbz       r0, 0x3B8(r3)
  cmplwi    r0, 0
  bne-      .loc_0x380
  lwz       r27, 0x3068(r13)
  mr        r3, r27
  lwz       r12, 0x0(r27)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lfs       f31, -0x52A0(r2)
  mr        r28, r3
  b         .loc_0x324

.loc_0x200:
  cmpwi     r28, -0x1
  bne-      .loc_0x228
  mr        r3, r27
  lwz       r12, 0x0(r27)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0x244

.loc_0x228:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x244:
  addi      r29, r30, 0
  addi      r3, r29, 0
  lwz       r12, 0x0(r29)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x308
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x308
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x308
  lwz       r4, 0xC(r31)
  lfs       f1, 0x94(r29)
  lwz       r3, 0x224(r4)
  lfs       f2, 0x9C(r29)
  lfs       f3, 0x94(r4)
  addi      r29, r3, 0x210
  lfs       f4, 0x9C(r4)
  bl        -0x13EC30
  lfs       f0, 0x0(r29)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x308
  lwz       r4, 0xC(r31)
  lfs       f1, 0x98(r30)
  lfs       f0, 0x98(r4)
  lwz       r3, 0x224(r4)
  fsubs     f1, f1, f0
  addi      r3, r3, 0x210
  fcmpo     cr0, f1, f31
  ble-      .loc_0x2EC
  b         .loc_0x2F0

.loc_0x2EC:
  fneg      f1, f1

.loc_0x2F0:
  lfs       f0, 0x0(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x308
  li        r0, 0x1
  stb       r0, 0x3B8(r4)
  b         .loc_0x380

.loc_0x308:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r28
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r28, r3

.loc_0x324:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r28
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x34C
  li        r0, 0x1
  b         .loc_0x378

.loc_0x34C:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x374
  li        r0, 0x1
  b         .loc_0x378

.loc_0x374:
  li        r0, 0

.loc_0x378:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x200

.loc_0x380:
  lwz       r3, 0xC(r31)
  lmw       r27, 0x6C(r1)
  lbz       r3, 0x3B8(r3)
  lwz       r0, 0x8C(r1)
  lfd       f31, 0x80(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void KoganeAi::startWalkTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void KoganeAi::stopWalkTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void KoganeAi::changeTargetTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void KoganeAi::createPelletTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void KoganeAi::initDie(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002CC
 */
void KoganeAi::initAppear(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00045C
 */
void KoganeAi::initWalkRandom(int, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000164
 */
void KoganeAi::initStopWalk(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80177340
 * Size:	0001D4
 */
void KoganeAi::initCreate(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x80(r1)
  stfd      f31, 0x78(r1)
  stfd      f30, 0x70(r1)
  stw       r31, 0x6C(r1)
  mr        r31, r3
  addi      r5, r31, 0
  lwz       r3, 0xC(r3)
  stw       r4, 0x2E8(r3)
  addi      r3, r1, 0x3C
  li        r4, 0x1
  lwz       r6, 0xC(r31)
  stb       r0, 0x2BD(r6)
  bl        -0x583F0
  lwz       r5, 0xC(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x581CC
  lwz       r3, 0xC(r31)
  lfs       f0, -0x525C(r2)
  lfs       f1, 0xA0(r3)
  fadds     f30, f0, f1
  bl        0xA47B4
  lwz       r3, 0xC(r31)
  fmr       f31, f1
  lfs       f1, 0xA0(r3)
  bl        0xA4938
  stfs      f1, 0x5C(r1)
  fmr       f1, f30
  lfs       f0, 0x57C(r13)
  stfs      f0, 0x60(r1)
  stfs      f31, 0x64(r1)
  bl        0xA478C
  fmr       f31, f1
  fmr       f1, f30
  bl        0xA4914
  stfs      f1, 0x50(r1)
  li        r4, 0x59
  lfs       f0, 0x580(r13)
  li        r6, 0
  li        r7, 0
  stfs      f0, 0x54(r1)
  stfs      f31, 0x58(r1)
  lfs       f0, 0x50(r1)
  lwz       r3, 0x3180(r13)
  fneg      f0, f0
  stfs      f0, 0x44(r1)
  lfs       f0, 0x54(r1)
  fneg      f0, f0
  stfs      f0, 0x48(r1)
  lfs       f0, 0x58(r1)
  fneg      f0, f0
  stfs      f0, 0x4C(r1)
  lwz       r5, 0xC(r31)
  addi      r5, r5, 0x94
  bl        0x25714
  cmplwi    r3, 0
  beq-      .loc_0x108
  lwz       r4, 0x5C(r1)
  lwz       r0, 0x60(r1)
  stw       r4, 0xA0(r3)
  stw       r0, 0xA4(r3)
  lwz       r0, 0x64(r1)
  stw       r0, 0xA8(r3)

.loc_0x108:
  lwz       r5, 0xC(r31)
  li        r4, 0x58
  lwz       r3, 0x3180(r13)
  li        r6, 0
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x256D8
  cmplwi    r3, 0
  beq-      .loc_0x144
  lwz       r4, 0x50(r1)
  lwz       r0, 0x54(r1)
  stw       r4, 0xA0(r3)
  stw       r0, 0xA4(r3)
  lwz       r0, 0x58(r1)
  stw       r0, 0xA8(r3)

.loc_0x144:
  lwz       r5, 0xC(r31)
  li        r4, 0x57
  lwz       r3, 0x3180(r13)
  li        r6, 0
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x2569C
  cmplwi    r3, 0
  beq-      .loc_0x180
  lwz       r4, 0x44(r1)
  lwz       r0, 0x48(r1)
  stw       r4, 0xA0(r3)
  stw       r0, 0xA4(r3)
  lwz       r0, 0x4C(r1)
  stw       r0, 0xA8(r3)

.loc_0x180:
  lwz       r6, 0xC(r31)
  li        r4, 0xF
  lwz       r3, 0x3178(r13)
  li        r5, 0
  addi      r6, r6, 0x94
  bl        0x5900
  lwz       r3, 0xC(r31)
  bl        -0x2811C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1B8
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x2B
  addi      r3, r3, 0x70
  bl        -0xF3AF4

.loc_0x1B8:
  lwz       r0, 0x84(r1)
  lfd       f31, 0x78(r1)
  lfd       f30, 0x70(r1)
  lwz       r31, 0x6C(r1)
  addi      r1, r1, 0x80
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void KoganeAi::dieState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000180
 */
void KoganeAi::walkRandomState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void KoganeAi::stopWalkState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void KoganeAi::createState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80177514
 * Size:	0008A4
 */
void KoganeAi::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x238(r1)
  stfd      f31, 0x230(r1)
  stw       r31, 0x22C(r1)
  mr        r31, r3
  stw       r30, 0x228(r1)
  bl        -0xECC
  lwz       r4, 0xC(r31)
  lwz       r0, 0x2E4(r4)
  cmpwi     r0, 0x1
  beq-      .loc_0x44
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x2D4(r4)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x2D4(r4)

.loc_0x44:
  lwz       r4, 0xC(r31)
  lwz       r0, 0x2E4(r4)
  cmpwi     r0, 0x2
  beq-      .loc_0x208
  bge-      .loc_0x68
  cmpwi     r0, 0
  beq-      .loc_0x78
  bge-      .loc_0x104
  b         .loc_0x888

.loc_0x68:
  cmpwi     r0, 0x4
  beq-      .loc_0x760
  bge-      .loc_0x888
  b         .loc_0x5D0

.loc_0x78:
  addi      r5, r4, 0x7C
  lfs       f2, -0x52A0(r2)
  lfs       f3, 0x7C(r4)
  fcmpo     cr0, f3, f2
  ble-      .loc_0xD4
  lwz       r4, 0x224(r4)
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x230(r4)
  lfs       f0, 0x28C(r3)
  fmuls     f0, f1, f0
  fsubs     f0, f3, f0
  stfs      f0, 0x0(r5)
  lwz       r3, 0xC(r31)
  lfsu      f0, 0x7C(r3)
  fcmpo     cr0, f0, f2
  bge-      .loc_0xBC
  stfs      f2, 0x0(r3)

.loc_0xBC:
  lwz       r3, 0xC(r31)
  lfs       f0, 0x7C(r3)
  stfs      f0, 0x84(r3)
  lwz       r3, 0xC(r31)
  stfs      f0, 0x80(r3)
  b         .loc_0x888

.loc_0xD4:
  lwz       r3, 0x3180(r13)
  addi      r5, r4, 0x94
  li        r4, 0x78
  li        r6, 0
  li        r7, 0
  bl        0x2553C
  lwz       r3, 0xC(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10C(r12)
  mtlr      r12
  blrl      
  b         .loc_0x888

.loc_0x104:
  mr        r3, r31
  bl        -0x67C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x888
  lwz       r3, 0xC(r31)
  li        r4, 0x2
  li        r0, 0
  stw       r4, 0x2E8(r3)
  addi      r5, r31, 0
  addi      r3, r1, 0x214
  lwz       r6, 0xC(r31)
  li        r4, 0x6
  stb       r0, 0x2BD(r6)
  lfs       f0, -0x5264(r2)
  lwz       r6, 0xC(r31)
  stfs      f0, 0x2D8(r6)
  lfs       f0, -0x52A0(r2)
  lwz       r6, 0xC(r31)
  stfs      f0, 0x2D0(r6)
  bl        -0x586D8
  lwz       r5, 0xC(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x584B4
  lwz       r3, 0xC(r31)
  lfs       f1, 0x8C(r3)
  bl        0xA4668
  lfs       f0, -0x5260(r2)
  lwz       r3, 0xC(r31)
  fmuls     f1, f0, f1
  lfs       f0, 0x94(r3)
  fadds     f0, f0, f1
  stfs      f0, 0x94(r3)
  lwz       r3, 0xC(r31)
  lfs       f1, 0x8C(r3)
  bl        0xA44B0
  lfs       f0, -0x5260(r2)
  li        r0, 0x1
  lwz       r4, 0xC(r31)
  mr        r3, r31
  fmuls     f1, f0, f1
  lfs       f0, 0x9C(r4)
  fadds     f0, f0, f1
  stfs      f0, 0x9C(r4)
  lwz       r4, 0xC(r31)
  stb       r0, 0x2BB(r4)
  lwz       r4, 0xC(r31)
  stb       r0, 0x2BE(r4)
  bl        -0xF98
  lwz       r3, 0xC(r31)
  bl        -0x28320
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1E8
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x2B
  addi      r3, r3, 0x70
  bl        -0xF3CF8

.loc_0x1E8:
  lwz       r5, 0xC(r31)
  li        r4, 0x78
  lwz       r3, 0x3180(r13)
  li        r6, 0
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x25424
  b         .loc_0x888

.loc_0x208:
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x2D0(r4)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x2D0(r4)
  lwz       r3, 0xC(r31)
  lwz       r4, 0x224(r3)
  lfs       f1, 0x250(r4)
  bl        -0x2938C
  lwz       r3, 0xC(r31)
  addi      r4, r3, 0x30C
  lfs       f0, 0x94(r3)
  lfs       f1, 0x30C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0xA4(r3)
  lfs       f0, -0x52A0(r2)
  lwz       r3, 0xC(r31)
  stfs      f0, 0xA8(r3)
  lwz       r3, 0xC(r31)
  lfs       f1, 0x8(r4)
  lfs       f0, 0x9C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0xAC(r3)
  lwz       r3, 0xC(r31)
  addi      r30, r3, 0xA4
  lfs       f1, 0xA4(r3)
  lfs       f0, 0xA8(r3)
  lfs       f2, 0xAC(r3)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x169B60
  lfs       f0, -0x52A0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x2A4
  mr        r3, r30
  bl        -0xEE268

.loc_0x2A4:
  lwz       r4, 0xC(r31)
  lwz       r3, 0x224(r4)
  lfsu      f0, 0xA4(r4)
  lfs       f1, 0x240(r3)
  fmuls     f0, f0, f1
  stfs      f0, 0x0(r4)
  lfs       f0, 0x4(r4)
  fmuls     f0, f0, f1
  stfs      f0, 0x4(r4)
  lfs       f0, 0x8(r4)
  fmuls     f0, f0, f1
  stfs      f0, 0x8(r4)
  lwz       r3, 0xC(r31)
  lwz       r4, 0x224(r3)
  addi      r5, r3, 0x7C
  lfs       f2, 0x7C(r3)
  lfs       f0, 0x2F0(r4)
  fcmpo     cr0, f2, f0
  bge-      .loc_0x338
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x220(r4)
  lfs       f0, 0x28C(r3)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x0(r5)
  lwz       r4, 0xC(r31)
  lwz       r3, 0x224(r4)
  lfsu      f1, 0x7C(r4)
  lfs       f0, 0x2F0(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x324
  stfs      f0, 0x0(r4)

.loc_0x324:
  lwz       r3, 0xC(r31)
  lfs       f0, 0x7C(r3)
  stfs      f0, 0x84(r3)
  lwz       r3, 0xC(r31)
  stfs      f0, 0x80(r3)

.loc_0x338:
  lwz       r4, 0xC(r31)
  lfs       f0, 0x18(r31)
  lfs       f1, 0x2D4(r4)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x354
  li        r0, 0x1
  b         .loc_0x358

.loc_0x354:
  li        r0, 0

.loc_0x358:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x394
  li        r0, 0
  stw       r0, 0x2E8(r4)
  lwz       r3, 0xC(r31)
  stb       r0, 0x2BD(r3)
  lwz       r3, 0xC(r31)
  bl        -0x284C8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x888
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x2B
  addi      r3, r3, 0x70
  bl        -0xF3EA0
  b         .loc_0x888

.loc_0x394:
  lbz       r0, 0x3B9(r4)
  cmplwi    r0, 0
  beq-      .loc_0x3B0
  addi      r3, r31, 0
  li        r4, 0x4
  bl        -0x57C
  b         .loc_0x888

.loc_0x3B0:
  lfs       f3, 0x94(r4)
  lfs       f1, 0x30C(r4)
  lfs       f2, 0x314(r4)
  lfs       f4, 0x9C(r4)
  bl        -0x13F2AC
  lfs       f0, -0x5268(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x3D8
  li        r0, 0x1
  b         .loc_0x3DC

.loc_0x3D8:
  li        r0, 0

.loc_0x3DC:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x520
  lwz       r3, 0xC(r31)
  li        r4, 0x3
  li        r0, 0
  stw       r4, 0x2E8(r3)
  addi      r5, r31, 0
  addi      r3, r1, 0x20C
  lwz       r6, 0xC(r31)
  li        r4, 0x2
  stb       r0, 0x2BD(r6)
  lfs       f0, -0x52A0(r2)
  lwz       r6, 0xC(r31)
  stfs      f0, 0x2D0(r6)
  bl        -0x5899C
  lwz       r5, 0xC(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x58778
  lwz       r3, 0xC(r31)
  lfs       f0, 0x55C(r13)
  stfsu     f0, 0xA4(r3)
  lfs       f0, 0x560(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x564(r13)
  stfs      f0, 0x8(r3)
  lwz       r3, 0xC(r31)
  lfs       f0, 0x568(r13)
  stfsu     f0, 0x70(r3)
  lfs       f0, 0x56C(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x570(r13)
  stfs      f0, 0x8(r3)
  lwz       r3, 0xC(r31)
  lfs       f0, -0x52A0(r2)
  lwz       r4, 0x224(r3)
  lfs       f2, 0x2D0(r4)
  lfs       f1, 0x2C0(r4)
  fsubs     f31, f2, f1
  fcmpo     cr0, f31, f0
  ble-      .loc_0x484
  b         .loc_0x488

.loc_0x484:
  fneg      f31, f31

.loc_0x488:
  bl        0xA06D4
  xoris     r0, r3, 0x8000
  lfs       f0, -0x5294(r2)
  stw       r0, 0x224(r1)
  lis       r0, 0x4330
  lwz       r3, 0xC(r31)
  fmuls     f0, f0, f31
  stw       r0, 0x220(r1)
  lwz       r3, 0x224(r3)
  lfd       f2, -0x5290(r2)
  lfd       f1, 0x220(r1)
  lfs       f3, -0x5298(r2)
  fsubs     f4, f1, f2
  lfs       f2, -0x529C(r2)
  lfs       f1, 0x2C0(r3)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x1C(r31)
  lwz       r4, 0x14(r31)
  cmpwi     r4, 0
  blt-      .loc_0x4FC
  lwz       r5, 0xC(r31)
  li        r6, 0
  lwz       r3, 0x3180(r13)
  li        r7, 0
  addi      r5, r5, 0x94
  bl        0x2512C

.loc_0x4FC:
  lwz       r3, 0xC(r31)
  bl        -0x28654
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x888
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x2B
  addi      r3, r3, 0x70
  bl        -0xF402C
  b         .loc_0x888

.loc_0x520:
  lwz       r4, 0xC(r31)
  lwz       r3, 0x224(r4)
  lfs       f1, 0x2D0(r4)
  lfs       f0, 0x2E0(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x540
  li        r0, 0x1
  b         .loc_0x558

.loc_0x540:
  lbz       r0, 0x2BF(r4)
  cmplwi    r0, 0
  beq-      .loc_0x554
  li        r0, 0x1
  b         .loc_0x558

.loc_0x554:
  li        r0, 0

.loc_0x558:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x888
  li        r0, 0x2
  stw       r0, 0x2E8(r4)
  li        r0, 0
  addi      r3, r31, 0
  lwz       r4, 0xC(r31)
  stb       r0, 0x2BD(r4)
  lfs       f0, -0x52A0(r2)
  lwz       r4, 0xC(r31)
  stfs      f0, 0x2D0(r4)
  bl        -0x1170
  lwz       r4, 0x14(r31)
  cmpwi     r4, 0
  blt-      .loc_0x5AC
  lwz       r5, 0xC(r31)
  li        r6, 0
  lwz       r3, 0x3180(r13)
  li        r7, 0
  addi      r5, r5, 0x94
  bl        0x2507C

.loc_0x5AC:
  lwz       r3, 0xC(r31)
  bl        -0x28704
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x888
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x2B
  addi      r3, r3, 0x70
  bl        -0xF40DC
  b         .loc_0x888

.loc_0x5D0:
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x2D0(r4)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x2D0(r4)
  lwz       r3, 0xC(r31)
  lwz       r4, 0x224(r3)
  addi      r5, r3, 0x7C
  lfs       f2, 0x7C(r3)
  lfs       f0, 0x2F0(r4)
  fcmpo     cr0, f2, f0
  bge-      .loc_0x648
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x220(r4)
  lfs       f0, 0x28C(r3)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x0(r5)
  lwz       r4, 0xC(r31)
  lwz       r3, 0x224(r4)
  lfsu      f1, 0x7C(r4)
  lfs       f0, 0x2F0(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x634
  stfs      f0, 0x0(r4)

.loc_0x634:
  lwz       r3, 0xC(r31)
  lfs       f0, 0x7C(r3)
  stfs      f0, 0x84(r3)
  lwz       r3, 0xC(r31)
  stfs      f0, 0x80(r3)

.loc_0x648:
  lwz       r3, 0xC(r31)
  lfs       f0, 0x18(r31)
  lfs       f1, 0x2D4(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x664
  li        r0, 0x1
  b         .loc_0x668

.loc_0x664:
  li        r0, 0

.loc_0x668:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x6A4
  li        r0, 0
  stw       r0, 0x2E8(r3)
  lwz       r3, 0xC(r31)
  stb       r0, 0x2BD(r3)
  lwz       r3, 0xC(r31)
  bl        -0x287D8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x888
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x2B
  addi      r3, r3, 0x70
  bl        -0xF41B0
  b         .loc_0x888

.loc_0x6A4:
  lbz       r0, 0x3B9(r3)
  cmplwi    r0, 0
  beq-      .loc_0x6C0
  addi      r3, r31, 0
  li        r4, 0x4
  bl        -0x88C
  b         .loc_0x888

.loc_0x6C0:
  lfs       f1, 0x2D0(r3)
  lfs       f0, 0x1C(r31)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x888
  li        r0, 0x2
  stw       r0, 0x2E8(r3)
  li        r0, 0
  addi      r5, r31, 0
  lwz       r6, 0xC(r31)
  addi      r3, r1, 0x1FC
  li        r4, 0x6
  stb       r0, 0x2BD(r6)
  lfs       f0, -0x52A0(r2)
  lwz       r6, 0xC(r31)
  stfs      f0, 0x2D0(r6)
  bl        -0x58C84
  lwz       r5, 0xC(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x58A60
  mr        r3, r31
  bl        -0x14E8
  lwz       r4, 0x14(r31)
  cmpwi     r4, 0
  blt-      .loc_0x73C
  lwz       r5, 0xC(r31)
  li        r6, 0
  lwz       r3, 0x3180(r13)
  li        r7, 0
  addi      r5, r5, 0x94
  bl        0x24EEC

.loc_0x73C:
  lwz       r3, 0xC(r31)
  bl        -0x28894
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x888
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x2B
  addi      r3, r3, 0x70
  bl        -0xF426C
  b         .loc_0x888

.loc_0x760:
  lfs       f1, -0x5258(r2)
  lfs       f0, 0xA4(r4)
  fmuls     f0, f0, f1
  stfs      f0, 0xA4(r4)
  lfs       f0, 0xA8(r4)
  fmuls     f0, f0, f1
  stfs      f0, 0xA8(r4)
  lfs       f0, 0xAC(r4)
  fmuls     f0, f0, f1
  stfs      f0, 0xAC(r4)
  lwz       r3, 0xC(r31)
  lwz       r4, 0x224(r3)
  addi      r5, r3, 0x7C
  lfs       f2, 0x7C(r3)
  lfs       f0, 0x2F0(r4)
  fcmpo     cr0, f2, f0
  bge-      .loc_0x7EC
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x220(r4)
  lfs       f0, 0x28C(r3)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x0(r5)
  lwz       r4, 0xC(r31)
  lwz       r3, 0x224(r4)
  lfsu      f1, 0x7C(r4)
  lfs       f0, 0x2F0(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x7D8
  stfs      f0, 0x0(r4)

.loc_0x7D8:
  lwz       r3, 0xC(r31)
  lfs       f0, 0x7C(r3)
  stfs      f0, 0x84(r3)
  lwz       r3, 0xC(r31)
  stfs      f0, 0x80(r3)

.loc_0x7EC:
  lwz       r3, 0xC(r31)
  lbz       r0, 0x2BD(r3)
  cmplwi    r0, 0
  beq-      .loc_0x888
  li        r0, 0x2
  stw       r0, 0x2E8(r3)
  li        r0, 0
  addi      r5, r31, 0
  lwz       r6, 0xC(r31)
  addi      r3, r1, 0x1F4
  li        r4, 0x6
  stb       r0, 0x2BD(r6)
  lfs       f0, -0x52A0(r2)
  lwz       r6, 0xC(r31)
  stfs      f0, 0x2D0(r6)
  bl        -0x58DB0
  lwz       r5, 0xC(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x58B8C
  mr        r3, r31
  bl        -0x1614
  lwz       r4, 0x14(r31)
  cmpwi     r4, 0
  blt-      .loc_0x868
  lwz       r5, 0xC(r31)
  li        r6, 0
  lwz       r3, 0x3180(r13)
  li        r7, 0
  addi      r5, r5, 0x94
  bl        0x24DC0

.loc_0x868:
  lwz       r3, 0xC(r31)
  bl        -0x289C0
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x888
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x2B
  addi      r3, r3, 0x70
  bl        -0xF4398

.loc_0x888:
  lwz       r0, 0x23C(r1)
  lfd       f31, 0x230(r1)
  lwz       r31, 0x22C(r1)
  lwz       r30, 0x228(r1)
  addi      r1, r1, 0x238
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80177DB8
 * Size:	000028
 */
void KoganeGenRippleCallBack::invoke(zen::particleGenerator *)
{
/*
.loc_0x0:
  lwz       r3, 0x4(r3)
  lwz       r3, 0x3BC(r3)
  lbz       r0, 0x4(r3)
  cmplwi    r0, 0
  bne-      .loc_0x20
  lwz       r0, 0x80(r4)
  ori       r0, r0, 0x2
  stw       r0, 0x80(r4)

.loc_0x20:
  li        r3, 0x1
  blr
*/
}