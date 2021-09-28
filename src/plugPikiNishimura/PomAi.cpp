

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
 * Address:	80178558
 * Size:	000074
 */
void PomAi::PomAi(Pom *)
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
  addi      r0, r3, 0xD94
  li        r3, 0x8
  stw       r0, 0x0(r31)
  stw       r4, 0x4(r31)
  bl        -0x131588
  cmplwi    r3, 0
  beq-      .loc_0x58
  lis       r4, 0x802B
  addi      r0, r4, 0x600
  lis       r4, 0x802D
  stw       r0, 0x0(r3)
  addi      r0, r4, 0xDF0
  stw       r0, 0x0(r3)

.loc_0x58:
  stw       r3, 0x20(r31)
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
 * Address:	801785CC
 * Size:	000194
 */
void PomAi::initAI(Pom *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x98(r1)
  stw       r31, 0x94(r1)
  mr        r31, r3
  stw       r30, 0x90(r1)
  stw       r4, 0x4(r3)
  lwz       r4, 0x4(r3)
  lwz       r3, 0x224(r4)
  lwz       r0, 0x2C0(r3)
  cmpwi     r0, 0x2
  bge-      .loc_0x78
  li        r0, 0x2
  stw       r0, 0x2E4(r4)
  addi      r5, r31, 0
  addi      r3, r1, 0x70
  lwz       r6, 0x4(r31)
  li        r4, 0xA
  stw       r0, 0x2E8(r6)
  bl        -0x5968C
  lwz       r5, 0x4(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x59468
  lwz       r3, 0x4(r31)
  bl        -0xEE364
  lfs       f0, -0x5218(r2)
  lwz       r3, 0x4(r31)
  stfs      f0, 0x368(r3)
  b         .loc_0xB0

.loc_0x78:
  li        r0, 0x1
  stw       r0, 0x2E4(r4)
  addi      r5, r31, 0
  addi      r3, r1, 0x68
  lwz       r6, 0x4(r31)
  li        r4, 0x2
  stw       r0, 0x2E8(r6)
  bl        -0x596D4
  lwz       r5, 0x4(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x594B0
  lwz       r3, 0x4(r31)
  bl        -0xEE364

.loc_0xB0:
  lfs       f0, -0x5214(r2)
  li        r3, 0x1
  lwz       r4, 0x4(r31)
  li        r0, 0
  stfs      f0, 0x2D8(r4)
  stb       r3, 0x8(r31)
  stb       r0, 0x9(r31)
  stb       r0, 0xA(r31)
  stw       r0, 0xC(r31)
  stw       r0, 0x10(r31)
  lwz       r3, 0x4(r31)
  lwz       r4, 0x224(r3)
  addi      r3, r4, 0x270
  lwz       r0, 0x280(r4)
  lwz       r3, 0x0(r3)
  sub       r3, r0, r3
  addic.    r30, r3, 0x1
  ble-      .loc_0xFC
  b         .loc_0x100

.loc_0xFC:
  neg       r30, r30

.loc_0x100:
  bl        0x9F9A4
  xoris     r0, r3, 0x8000
  lwz       r3, 0x4(r31)
  stw       r0, 0x8C(r1)
  lis       r4, 0x4330
  xoris     r0, r30, 0x8000
  lwz       r3, 0x224(r3)
  stw       r4, 0x88(r1)
  lfd       f4, -0x5200(r2)
  lfd       f0, 0x88(r1)
  stw       r0, 0x84(r1)
  fsubs     f1, f0, f4
  lfs       f0, -0x520C(r2)
  stw       r4, 0x80(r1)
  lfs       f2, -0x5210(r2)
  fdivs     f3, f1, f0
  lfd       f0, 0x80(r1)
  lfs       f1, -0x5208(r2)
  lwz       r3, 0x270(r3)
  fsubs     f0, f0, f4
  fmuls     f2, f2, f3
  fmuls     f0, f1, f0
  fmuls     f0, f0, f2
  fctiwz    f0, f0
  stfd      f0, 0x78(r1)
  lwz       r0, 0x7C(r1)
  add       r0, r3, r0
  stw       r0, 0x14(r31)
  lfs       f0, -0x5204(r2)
  stfs      f0, 0x1C(r31)
  stfs      f0, 0x18(r31)
  lwz       r0, 0x9C(r1)
  lwz       r31, 0x94(r1)
  lwz       r30, 0x90(r1)
  addi      r1, r1, 0x98
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80178760
 * Size:	00007C
 */
void PomAi::animationKeyUpdated(PaniAnimKeyEvent &)
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
  bl        0x74
  b         .loc_0x6C

.loc_0x54:
  bl        0x88
  b         .loc_0x6C

.loc_0x5C:
  bl        0x94
  b         .loc_0x6C

.loc_0x64:
  lwz       r4, 0x4(r4)
  bl        0x150

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
 * Address:	801787DC
 * Size:	000044
 */
void PomAi::keyAction0()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r4, 0x4(r3)
  lwz       r0, 0x2E4(r4)
  cmpwi     r0, 0x5
  bne-      .loc_0x24
  bl        0x584
  b         .loc_0x34

.loc_0x24:
  cmpwi     r0, 0x2
  bne-      .loc_0x34
  mr        r3, r4
  bl        -0xEE540

.loc_0x34:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80178820
 * Size:	00001C
 */
void PomAi::keyAction1()
{
/*
.loc_0x0:
  lwz       r4, 0x4(r3)
  lwz       r0, 0x2E4(r4)
  cmpwi     r0, 0x2
  bnelr-    
  li        r0, 0
  stb       r0, 0xA(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PomAi::keyAction2()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PomAi::keyAction3()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017883C
 * Size:	000014
 */
void PomAi::keyLoopEnd()
{
/*
.loc_0x0:
  lwz       r4, 0x4(r3)
  lwz       r3, 0x2EC(r4)
  addi      r0, r3, 0x1
  stw       r0, 0x2EC(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	80178850
 * Size:	0000C8
 */
void PomAi::keyFinished()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r3
  lwz       r3, 0x4(r3)
  lwz       r0, 0x2E4(r3)
  cmpwi     r0, 0
  bne-      .loc_0xA8
  li        r0, 0
  stb       r0, 0x2B8(r3)
  li        r4, 0x3F
  li        r6, 0
  lwz       r3, 0x4(r31)
  li        r7, 0
  stb       r0, 0x2B9(r3)
  lwz       r5, 0x4(r31)
  lwz       r3, 0x3180(r13)
  addi      r5, r5, 0x94
  bl        0x2429C
  lwz       r5, 0x4(r31)
  li        r4, 0x3E
  lwz       r3, 0x3180(r13)
  li        r6, 0
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x24280
  lwz       r5, 0x4(r31)
  li        r4, 0x3D
  lwz       r3, 0x3180(r13)
  li        r6, 0
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x24264
  addi      r3, r31, 0
  li        r4, 0
  bl        .loc_0xC8
  lwz       r3, 0x4(r31)
  li        r5, 0x1
  lfs       f1, -0x51F8(r2)
  addi      r4, r3, 0x94
  bl        -0x2A7E4

.loc_0xA8:
  lwz       r3, 0x4(r31)
  li        r0, 0x1
  stb       r0, 0x2BD(r3)
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr       

.loc_0xC8:
*/
}

/*
 * --INFO--
 * Address:	80178918
 * Size:	000044
 */
void PomAi::playSound(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x4(r3)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x34
  lis       r5, 0x802D
  rlwinm    r4,r4,2,0,29
  addi      r0, r5, 0xD18
  add       r4, r0, r4
  lwz       r4, 0x0(r4)
  bl        -0xD4B78

.loc_0x34:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017895C
 * Size:	000038
 */
void PomAi::killCallBackEffect(bool)
{
/*
.loc_0x0:
  mflr      r0
  addi      r6, r4, 0
  stw       r0, 0x4(r1)
  li        r5, 0
  stwu      r1, -0x8(r1)
  lwz       r0, 0x20(r3)
  lwz       r3, 0x3180(r13)
  mr        r4, r0
  addi      r3, r3, 0x14
  bl        0x28CDC
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80178994
 * Size:	0001B4
 */
void PomAi::collidePetal(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  addi      r31, r4, 0
  stw       r30, 0x38(r1)
  mr        r30, r3
  lbz       r0, 0x8(r3)
  cmplwi    r0, 0
  bne-      .loc_0x19C
  lwz       r3, 0x4(r30)
  lwz       r0, 0x2E4(r3)
  cmpwi     r0, 0x2
  bne-      .loc_0xE4
  lfs       f1, 0x368(r3)
  lfs       f0, -0x51F4(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xE4
  lfs       f1, 0x70(r31)
  lfs       f0, 0x74(r31)
  fmuls     f2, f1, f1
  lfs       f3, 0x78(r31)
  fmuls     f1, f0, f0
  lfs       f0, -0x5204(r2)
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0xCC
  fsqrte    f1, f4
  lfd       f3, -0x51F0(r2)
  lfd       f2, -0x51E8(r2)
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

.loc_0xCC:
  lfs       f0, -0x51E0(r2)
  fcmpo     cr0, f4, f0
  ble-      .loc_0xE4
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        .loc_0x1B4

.loc_0xE4:
  lwz       r3, 0x4(r30)
  lbz       r0, 0x2BD(r3)
  cmplwi    r0, 0
  beq-      .loc_0x19C
  lwz       r0, 0x2E4(r3)
  cmpwi     r0, 0x3
  bne-      .loc_0x19C
  lfs       f1, 0x70(r31)
  lfs       f0, 0x74(r31)
  fmuls     f2, f1, f1
  lfs       f3, 0x78(r31)
  fmuls     f1, f0, f0
  lfs       f0, -0x5204(r2)
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x184
  fsqrte    f1, f4
  lfd       f3, -0x51F0(r2)
  lfd       f2, -0x51E8(r2)
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
  stfs      f0, 0x24(r1)
  lfs       f4, 0x24(r1)

.loc_0x184:
  lfs       f0, -0x51E0(r2)
  fcmpo     cr0, f4, f0
  ble-      .loc_0x19C
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        .loc_0x1B4

.loc_0x19C:
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr       

.loc_0x1B4:
*/
}

/*
 * --INFO--
 * Address:	80178B48
 * Size:	000060
 */
void PomAi::setCollideSound(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, 0x1
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  stb       r31, 0x8(r3)
  lwz       r0, 0x6C(r4)
  cmpwi     r0, 0
  bne-      .loc_0x44
  mr        r3, r4
  bl        -0xB0624
  cmpwi     r3, 0xE
  beq-      .loc_0x48
  stb       r31, 0x9(r30)
  b         .loc_0x48

.loc_0x44:
  stb       r31, 0x9(r30)

.loc_0x48:
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
 * Size:	000044
 */
void PomAi::setEveryFrame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void PomAi::checkSwayAndScale()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void PomAi::calcSwayAndScale()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void PomAi::setInitPosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80178BA8
 * Size:	0001D4
 */
void PomAi::killStickPiki()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stmw      r27, 0x3C(r1)
  mr        r28, r3
  li        r29, 0
  lwz       r4, 0x4(r3)
  addi      r3, r1, 0x28
  bl        -0xE7F44
  addi      r31, r1, 0x28
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0x160

.loc_0x44:
  cmpwi     r30, -0x1
  bne-      .loc_0x6C
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r27, r3
  b         .loc_0x88

.loc_0x6C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r27, r3

.loc_0x88:
  cmplwi    r27, 0
  addi      r3, r27, 0
  beq-      .loc_0x144
  lwz       r12, 0x0(r3)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x144
  lwz       r0, 0x6C(r27)
  cmpwi     r0, 0
  bne-      .loc_0x144
  cmpwi     r30, -0x1
  bne-      .loc_0xDC
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0xF4

.loc_0xDC:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0xF4:
  lwz       r5, 0x4(r28)
  lwz       r4, 0x224(r5)
  lwz       r0, 0x2A0(r4)
  cmpwi     r0, 0
  beq-      .loc_0x124
  lhz       r4, 0x510(r3)
  lwz       r0, 0x3BC(r5)
  cmpw      r4, r0
  bne-      .loc_0x124
  li        r4, 0
  bl        -0xEDFE4
  b         .loc_0x138

.loc_0x124:
  li        r0, 0x1
  stb       r0, 0x584(r3)
  li        r4, 0
  bl        -0xEDFF8
  addi      r29, r29, 0x1

.loc_0x138:
  cmpwi     r30, 0
  blt-      .loc_0x144
  subi      r30, r30, 0x1

.loc_0x144:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x160:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x188
  li        r0, 0x1
  b         .loc_0x1B4

.loc_0x188:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x1B0
  li        r0, 0x1
  b         .loc_0x1B4

.loc_0x1B0:
  li        r0, 0

.loc_0x1B4:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x44
  mr        r3, r29
  lmw       r27, 0x3C(r1)
  lwz       r0, 0x54(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80178D7C
 * Size:	000228
 */
void PomAi::createPikiHead()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xA0(r1)
  stfd      f31, 0x98(r1)
  stfd      f30, 0x90(r1)
  stfd      f29, 0x88(r1)
  stfd      f28, 0x80(r1)
  stfd      f27, 0x78(r1)
  stfd      f26, 0x70(r1)
  stfd      f25, 0x68(r1)
  stfd      f24, 0x60(r1)
  stfd      f23, 0x58(r1)
  stmw      r27, 0x44(r1)
  mr        r31, r3
  bl        -0x20C
  mr        r29, r3
  lwz       r3, 0x3120(r13)
  bl        -0x619FC
  lwz       r4, 0x4(r31)
  lfs       f1, 0x94(r3)
  lfs       f3, 0x94(r4)
  lfs       f2, 0x9C(r4)
  lfs       f0, 0x9C(r3)
  fsubs     f1, f3, f1
  fsubs     f2, f2, f0
  bl        0xA2C18
  lwz       r3, 0x4(r31)
  li        r28, 0
  lfs       f2, -0x51D8(r2)
  lis       r30, 0x4330
  lwz       r3, 0x224(r3)
  lfs       f4, -0x51DC(r2)
  lfs       f3, 0x250(r3)
  lfs       f0, -0x51D4(r2)
  fdivs     f3, f3, f2
  lfs       f2, -0x5208(r2)
  lfs       f25, -0x51D0(r2)
  lfd       f26, -0x5200(r2)
  lfs       f27, -0x520C(r2)
  fmuls     f3, f4, f3
  lfs       f28, -0x5210(r2)
  lfs       f29, -0x51CC(r2)
  fmuls     f0, f0, f3
  fsubs     f30, f1, f3
  fmuls     f31, f2, f0
  b         .loc_0x1A4

.loc_0xB8:
  lwz       r3, 0x30AC(r13)
  li        r4, 0xF
  lwz       r12, 0x0(r3)
  lwz       r12, 0x78(r12)
  mtlr      r12
  blrl      
  mr.       r27, r3
  beq-      .loc_0x1A0
  lwz       r5, 0x4(r31)
  addi      r3, r27, 0
  lfsu      f0, 0x94(r5)
  addi      r4, r1, 0x24
  stfs      f0, 0x24(r1)
  lfs       f0, 0x4(r5)
  stfs      f0, 0x28(r1)
  lfs       f0, 0x8(r5)
  stfs      f0, 0x2C(r1)
  lfs       f0, 0x28(r1)
  fadds     f0, f0, f25
  stfs      f0, 0x28(r1)
  lwz       r12, 0x0(r27)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x4(r31)
  mr        r3, r27
  lwz       r4, 0x3BC(r4)
  bl        -0x8C400
  bl        0x9F1CC
  xoris     r0, r3, 0x8000
  stw       r0, 0x3C(r1)
  stw       r30, 0x38(r1)
  lfd       f0, 0x38(r1)
  fsubs     f0, f0, f26
  fdivs     f0, f0, f27
  fmuls     f0, f28, f0
  fmuls     f0, f31, f0
  fadds     f23, f30, f0
  fmr       f1, f23
  bl        0xA2C84
  fmuls     f24, f29, f1
  fmr       f1, f23
  bl        0xA2E0C
  fmuls     f0, f29, f1
  addi      r3, r27, 0
  li        r4, 0
  stfs      f0, 0x70(r27)
  lfs       f0, 0x658(r13)
  stfs      f0, 0x74(r27)
  stfs      f24, 0x78(r27)
  lwz       r12, 0x0(r27)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x2E8(r27)
  addi      r4, r27, 0
  li        r5, 0
  bl        -0xFB7C0

.loc_0x1A0:
  addi      r28, r28, 0x1

.loc_0x1A4:
  cmpw      r28, r29
  blt+      .loc_0xB8
  lwz       r6, 0x4(r31)
  li        r4, 0xA
  lwz       r3, 0x3178(r13)
  li        r5, 0
  addi      r6, r6, 0x94
  bl        0x3E98
  lwz       r3, 0x4(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x1E4
  lis       r4, 0x802D
  addi      r4, r4, 0xD18
  lwz       r4, 0xC(r4)
  bl        -0xD518C

.loc_0x1E4:
  lwz       r3, 0x10(r31)
  addi      r0, r3, 0x1
  stw       r0, 0x10(r31)
  lwz       r0, 0xA4(r1)
  lfd       f31, 0x98(r1)
  lfd       f30, 0x90(r1)
  lfd       f29, 0x88(r1)
  lfd       f28, 0x80(r1)
  lfd       f27, 0x78(r1)
  lfd       f26, 0x70(r1)
  lfd       f25, 0x68(r1)
  lfd       f24, 0x60(r1)
  lfd       f23, 0x58(r1)
  lmw       r27, 0x44(r1)
  addi      r1, r1, 0xA0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void PomAi::emitPomOpenEffect(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000198
 */
void PomAi::createPomOpenEffect()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80178FA4
 * Size:	0001DC
 */
void PomAi::calcPetalStickers()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x80(r1)
  stmw      r25, 0x64(r1)
  mr        r28, r3
  lwz       r4, 0x4(r3)
  lbz       r0, 0x3B8(r4)
  cmplwi    r0, 0
  beq-      .loc_0x38
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x2D0(r4)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x2D0(r4)

.loc_0x38:
  lwz       r5, 0x4(r28)
  lwz       r3, 0x224(r5)
  lwz       r0, 0x2B0(r3)
  cmpwi     r0, 0
  beq-      .loc_0x1C8
  lis       r4, 0x736C
  lwz       r3, 0x220(r5)
  addi      r4, r4, 0x6F74
  bl        -0xEF8EC
  lwz       r4, 0x4(r28)
  addi      r29, r3, 0
  addi      r3, r1, 0x50
  bl        -0xE8388
  addi      r31, r1, 0x50
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lis       r5, 0x802B
  lis       r4, 0x802B
  addi      r30, r3, 0
  subi      r26, r5, 0x3064
  subi      r27, r4, 0x3244
  b         .loc_0x16C

.loc_0x9C:
  cmpwi     r30, -0x1
  bne-      .loc_0xC4
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r25, r3
  b         .loc_0xE0

.loc_0xC4:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r25, r3

.loc_0xE0:
  cmplwi    r25, 0
  beq-      .loc_0x150
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x150
  lwz       r0, 0xC8(r25)
  rlwinm.   r0,r0,0,16,16
  bne-      .loc_0x150
  addi      r3, r29, 0
  li        r4, 0
  bl        -0xF12D0
  lwz       r5, 0x4(r28)
  li        r0, 0
  addi      r4, r1, 0x34
  stw       r26, 0x34(r1)
  stw       r5, 0x38(r1)
  stw       r27, 0x34(r1)
  stw       r0, 0x3C(r1)
  stw       r3, 0x40(r1)
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0xA0(r12)
  mtlr      r12
  blrl      

.loc_0x150:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x16C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x194
  li        r0, 0x1
  b         .loc_0x1C0

.loc_0x194:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x1BC
  li        r0, 0x1
  b         .loc_0x1C0

.loc_0x1BC:
  li        r0, 0

.loc_0x1C0:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x9C

.loc_0x1C8:
  lmw       r25, 0x64(r1)
  lwz       r0, 0x84(r1)
  addi      r1, r1, 0x80
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void PomAi::resultFlagOn()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void PomAi::resultFlagSeen()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void PomAi::isMotionFinishTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void PomAi::deadTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void PomAi::petalOpenTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PomAi::petalShakeTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void PomAi::petalCloseTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001BC
 */
void PomAi::dischargeTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void PomAi::initDie(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80179180
 * Size:	000200
 */
void PomAi::initWait(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x58(r1)
  stw       r31, 0x54(r1)
  mr        r31, r3
  addi      r5, r31, 0
  stw       r30, 0x50(r1)
  stw       r29, 0x4C(r1)
  stw       r28, 0x48(r1)
  lwz       r3, 0x4(r3)
  stw       r4, 0x2E8(r3)
  addi      r3, r1, 0x20
  li        r4, 0x2
  lwz       r6, 0x4(r31)
  stb       r0, 0x2BD(r6)
  bl        -0x5A234
  lwz       r5, 0x4(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x5A010
  addi      r3, r1, 0x38
  lwz       r4, 0x4(r31)
  bl        -0xE8558
  addi      r29, r1, 0x38
  addi      r3, r29, 0
  lwz       r12, 0x0(r29)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r28, r3
  b         .loc_0x178

.loc_0x80:
  cmpwi     r28, -0x1
  bne-      .loc_0xA8
  mr        r3, r29
  lwz       r12, 0x0(r29)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0xC4

.loc_0xA8:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0xC4:
  cmplwi    r30, 0
  beq-      .loc_0x15C
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x15C
  lwz       r0, 0x6C(r30)
  cmpwi     r0, 0
  bne-      .loc_0x15C
  cmpwi     r28, -0x1
  bne-      .loc_0x118
  mr        r3, r29
  lwz       r12, 0x0(r29)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x130

.loc_0x118:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x130:
  lwz       r4, 0x4(r31)
  lhz       r3, 0x510(r3)
  lwz       r0, 0x3BC(r4)
  cmpw      r3, r0
  bne-      .loc_0x15C
  addi      r3, r30, 0
  li        r4, 0
  bl        -0xEE5EC
  cmpwi     r28, 0
  blt-      .loc_0x15C
  subi      r28, r28, 0x1

.loc_0x15C:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r28, r3

.loc_0x178:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1A0
  li        r0, 0x1
  b         .loc_0x1CC

.loc_0x1A0:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x1C8
  li        r0, 0x1
  b         .loc_0x1CC

.loc_0x1C8:
  li        r0, 0

.loc_0x1CC:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x80
  lwz       r3, 0x4(r31)
  li        r0, 0
  stb       r0, 0x3B8(r3)
  lwz       r0, 0x5C(r1)
  lwz       r31, 0x54(r1)
  lwz       r30, 0x50(r1)
  lwz       r29, 0x4C(r1)
  lwz       r28, 0x48(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E4
 */
void PomAi::initPetalOpen(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void PomAi::initPetalShake(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void PomAi::initPetalClose(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80179380
 * Size:	0001CC
 */
void PomAi::initDischarge(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x78(r1)
  stmw      r25, 0x5C(r1)
  mr        r29, r3
  addi      r5, r29, 0
  lwz       r3, 0x4(r3)
  stw       r4, 0x2E8(r3)
  addi      r3, r1, 0x20
  li        r4, 0xC
  lwz       r6, 0x4(r29)
  stb       r0, 0x2BD(r6)
  bl        -0x5A428
  lwz       r5, 0x4(r29)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x5A204
  lwz       r5, 0x4(r29)
  lis       r3, 0x736C
  addi      r4, r3, 0x6F74
  lwz       r3, 0x220(r5)
  bl        -0xEFCC8
  lwz       r4, 0x4(r29)
  addi      r30, r3, 0
  addi      r3, r1, 0x44
  bl        -0xE8764
  addi      r31, r1, 0x44
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lis       r5, 0x802B
  lis       r4, 0x802B
  addi      r26, r3, 0
  subi      r27, r5, 0x3064
  subi      r28, r4, 0x3244
  b         .loc_0x15C

.loc_0x9C:
  cmpwi     r26, -0x1
  bne-      .loc_0xC0
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0xD8

.loc_0xC0:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r26
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0xD8:
  cmplwi    r3, 0
  addi      r25, r3, 0
  beq-      .loc_0x140
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x140
  addi      r3, r30, 0
  li        r4, 0
  bl        -0xF169C
  lwz       r5, 0x4(r29)
  li        r0, 0
  addi      r4, r1, 0x28
  stw       r27, 0x28(r1)
  stw       r5, 0x2C(r1)
  stw       r28, 0x28(r1)
  stw       r0, 0x30(r1)
  stw       r3, 0x34(r1)
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0xA0(r12)
  mtlr      r12
  blrl      

.loc_0x140:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r26
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r26, r3

.loc_0x15C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r26
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x184
  li        r0, 0x1
  b         .loc_0x1B0

.loc_0x184:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r26
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x1AC
  li        r0, 0x1
  b         .loc_0x1B0

.loc_0x1AC:
  li        r0, 0

.loc_0x1B0:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x9C
  lmw       r25, 0x5C(r1)
  lwz       r0, 0x7C(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void PomAi::dieState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PomAi::waitState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void PomAi::openState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void PomAi::shakeState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void PomAi::closeState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PomAi::dischargeState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017954C
 * Size:	000898
 */
void PomAi::update()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802D
  stw       r0, 0x4(r1)
  stwu      r1, -0x218(r1)
  stw       r31, 0x214(r1)
  addi      r31, r3, 0
  stw       r30, 0x210(r1)
  addi      r30, r4, 0xD18
  stw       r29, 0x20C(r1)
  lwz       r3, 0x4(r3)
  bl        -0x2A528
  lwz       r0, 0xC(r31)
  addi      r29, r3, 0
  cmpw      r29, r0
  ble-      .loc_0x98
  lwz       r3, 0x4(r31)
  li        r4, 0x79
  lfs       f1, 0x18(r31)
  li        r6, 0
  lwz       r3, 0x224(r3)
  li        r7, 0
  lfs       f0, 0x210(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x18(r31)
  lwz       r5, 0x4(r31)
  lwz       r3, 0x3180(r13)
  addi      r5, r5, 0x94
  bl        0x23580
  lwz       r3, 0x4(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x88
  lwz       r4, 0x14(r30)
  bl        -0xD5800

.loc_0x88:
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x2D
  addi      r3, r3, 0x70
  bl        -0xF5B90

.loc_0x98:
  stw       r29, 0xC(r31)
  lfs       f1, 0x1C(r31)
  lfs       f0, 0x18(r31)
  fadds     f0, f1, f0
  stfs      f0, 0x1C(r31)
  lfs       f1, -0x5210(r2)
  lfs       f0, 0x1C(r31)
  lwz       r3, 0x4(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0x7C(r3)
  lfs       f0, 0x1C(r31)
  lwz       r3, 0x4(r31)
  fadds     f0, f1, f0
  stfs      f0, 0x80(r3)
  lfs       f0, 0x1C(r31)
  lwz       r3, 0x4(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0x84(r3)
  lwz       r3, 0x4(r31)
  lfs       f1, 0x18(r31)
  lwz       r3, 0x224(r3)
  lfs       f0, 0x220(r3)
  fmuls     f0, f1, f0
  stfs      f0, 0x18(r31)
  lwz       r3, 0x4(r31)
  lfs       f0, 0x1C(r31)
  lwz       r3, 0x224(r3)
  fneg      f1, f0
  lfs       f2, 0x18(r31)
  lfs       f0, 0x230(r3)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x18(r31)
  lwz       r3, 0x4(r31)
  addi      r4, r3, 0x300
  lfs       f0, 0x300(r3)
  stfs      f0, 0x94(r3)
  lfs       f0, 0x304(r3)
  lwz       r3, 0x4(r31)
  stfs      f0, 0x98(r3)
  lfs       f0, 0x8(r4)
  lwz       r3, 0x4(r31)
  stfs      f0, 0x9C(r3)
  lwz       r3, 0x4(r31)
  bl        -0x2A2D4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x164
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x2D
  addi      r3, r3, 0x70
  bl        -0xF5CAC

.loc_0x164:
  lwz       r3, 0x4(r31)
  lwz       r0, 0x2E4(r3)
  cmpwi     r0, 0x3
  beq-      .loc_0x4FC
  bge-      .loc_0x190
  cmpwi     r0, 0x1
  beq-      .loc_0x1E8
  bge-      .loc_0x3C4
  cmpwi     r0, 0
  bge-      .loc_0x1A0
  b         .loc_0x87C

.loc_0x190:
  cmpwi     r0, 0x5
  beq-      .loc_0x800
  bge-      .loc_0x87C
  b         .loc_0x634

.loc_0x1A0:
  lbz       r0, 0x2BD(r3)
  cmplwi    r0, 0
  beq-      .loc_0x87C
  lfs       f1, 0x2D4(r3)
  lfs       f0, -0x5210(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x1CC
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10C(r12)
  mtlr      r12
  blrl      

.loc_0x1CC:
  lwz       r4, 0x4(r31)
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x2D4(r4)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x2D4(r4)
  b         .loc_0x87C

.loc_0x1E8:
  lwz       r4, 0x224(r3)
  lwz       r0, 0x2C0(r4)
  cmpwi     r0, 0
  beq-      .loc_0x200
  lbz       r0, 0x3B8(r3)
  b         .loc_0x204

.loc_0x200:
  li        r0, 0x1

.loc_0x204:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x87C
  li        r0, 0x2
  stw       r0, 0x2E8(r3)
  li        r0, 0
  addi      r5, r31, 0
  lwz       r6, 0x4(r31)
  addi      r3, r1, 0x1F8
  li        r4, 0xA
  stb       r0, 0x2BD(r6)
  bl        -0x5A7EC
  lwz       r5, 0x4(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x5A5C8
  li        r0, 0x1
  stb       r0, 0xA(r31)
  lis       r3, 0x706F
  addi      r0, r31, 0xA
  lwz       r5, 0x20(r31)
  addi      r4, r3, 0x6D31
  stw       r0, 0x4(r5)
  lwz       r3, 0x4(r31)
  lwz       r3, 0x220(r3)
  bl        -0xF00A0
  lwz       r5, 0x4(r31)
  mr        r29, r3
  lwz       r3, 0x3180(r13)
  li        r4, 0x31
  lwz       r6, 0x20(r31)
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x23368
  cmplwi    r3, 0
  beq-      .loc_0x298
  addi      r0, r29, 0x4
  stw       r0, 0x18(r3)

.loc_0x298:
  lwz       r5, 0x4(r31)
  lis       r3, 0x706F
  addi      r4, r3, 0x6D32
  lwz       r3, 0x220(r5)
  bl        -0xF00E4
  lwz       r5, 0x4(r31)
  mr        r29, r3
  lwz       r3, 0x3180(r13)
  li        r4, 0x31
  lwz       r6, 0x20(r31)
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x23324
  cmplwi    r3, 0
  beq-      .loc_0x2DC
  addi      r0, r29, 0x4
  stw       r0, 0x18(r3)

.loc_0x2DC:
  lwz       r5, 0x4(r31)
  lis       r3, 0x706F
  addi      r4, r3, 0x6D33
  lwz       r3, 0x220(r5)
  bl        -0xF0128
  lwz       r5, 0x4(r31)
  mr        r29, r3
  lwz       r3, 0x3180(r13)
  li        r4, 0x31
  lwz       r6, 0x20(r31)
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x232E0
  cmplwi    r3, 0
  beq-      .loc_0x320
  addi      r0, r29, 0x4
  stw       r0, 0x18(r3)

.loc_0x320:
  lwz       r5, 0x4(r31)
  lis       r3, 0x706F
  addi      r4, r3, 0x6D34
  lwz       r3, 0x220(r5)
  bl        -0xF016C
  lwz       r5, 0x4(r31)
  mr        r29, r3
  lwz       r3, 0x3180(r13)
  li        r4, 0x31
  lwz       r6, 0x20(r31)
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x2329C
  cmplwi    r3, 0
  beq-      .loc_0x364
  addi      r0, r29, 0x4
  stw       r0, 0x18(r3)

.loc_0x364:
  lwz       r5, 0x4(r31)
  lis       r3, 0x706F
  addi      r4, r3, 0x6D35
  lwz       r3, 0x220(r5)
  bl        -0xF01B0
  lwz       r5, 0x4(r31)
  mr        r29, r3
  lwz       r3, 0x3180(r13)
  li        r4, 0x31
  lwz       r6, 0x20(r31)
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x23258
  cmplwi    r3, 0
  beq-      .loc_0x3A8
  addi      r0, r29, 0x4
  stw       r0, 0x18(r3)

.loc_0x3A8:
  lfs       f0, -0x5204(r2)
  li        r0, 0
  lwz       r3, 0x4(r31)
  stfs      f0, 0x2D0(r3)
  stb       r0, 0x8(r31)
  stb       r0, 0x9(r31)
  b         .loc_0x87C

.loc_0x3C4:
  mr        r3, r31
  bl        -0x970
  lwz       r5, 0x4(r31)
  lwz       r4, 0x224(r5)
  addi      r3, r4, 0x260
  lwz       r3, 0x0(r3)
  cmpwi     r3, 0
  beq-      .loc_0x41C
  lwz       r0, 0xC(r31)
  cmpw      r0, r3
  blt-      .loc_0x3F8
  li        r0, 0x1
  b         .loc_0x438

.loc_0x3F8:
  lfs       f0, -0x5204(r2)
  lfs       f1, 0x240(r4)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x434
  lfs       f0, 0x2D0(r5)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x434
  li        r0, 0x1
  b         .loc_0x438

.loc_0x41C:
  lfs       f1, 0x2D0(r5)
  lfs       f0, 0x240(r4)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x434
  li        r0, 0x1
  b         .loc_0x438

.loc_0x434:
  li        r0, 0

.loc_0x438:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x48C
  li        r0, 0x4
  stw       r0, 0x2E8(r5)
  li        r29, 0
  addi      r5, r31, 0
  lwz       r6, 0x4(r31)
  addi      r3, r1, 0x1F0
  li        r4, 0xB
  stb       r29, 0x2BD(r6)
  lwz       r6, 0x4(r31)
  stw       r29, 0x2EC(r6)
  bl        -0x5AA28
  lwz       r5, 0x4(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x5A804
  lwz       r3, 0x4(r31)
  bl        -0xEF6B8
  stb       r29, 0xA(r31)
  b         .loc_0x87C

.loc_0x48C:
  lbz       r0, 0x8(r31)
  cmplwi    r0, 0
  beq-      .loc_0x87C
  li        r0, 0x3
  stw       r0, 0x2E8(r5)
  li        r29, 0
  addi      r5, r31, 0
  lwz       r6, 0x4(r31)
  addi      r3, r1, 0x1E8
  li        r4, 0xD
  stb       r29, 0x2BD(r6)
  bl        -0x5AA78
  lwz       r5, 0x4(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x5A854
  stb       r29, 0x8(r31)
  lbz       r0, 0x9(r31)
  cmplwi    r0, 0
  beq-      .loc_0x87C
  stb       r29, 0x9(r31)
  lwz       r3, 0x4(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x87C
  lwz       r4, 0x0(r30)
  bl        -0xD5C70
  b         .loc_0x87C

.loc_0x4FC:
  mr        r3, r31
  bl        -0xAA8
  lwz       r5, 0x4(r31)
  lwz       r4, 0x224(r5)
  addi      r3, r4, 0x260
  lwz       r3, 0x0(r3)
  cmpwi     r3, 0
  beq-      .loc_0x554
  lwz       r0, 0xC(r31)
  cmpw      r0, r3
  blt-      .loc_0x530
  li        r0, 0x1
  b         .loc_0x570

.loc_0x530:
  lfs       f0, -0x5204(r2)
  lfs       f1, 0x240(r4)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x56C
  lfs       f0, 0x2D0(r5)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x56C
  li        r0, 0x1
  b         .loc_0x570

.loc_0x554:
  lfs       f1, 0x2D0(r5)
  lfs       f0, 0x240(r4)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x56C
  li        r0, 0x1
  b         .loc_0x570

.loc_0x56C:
  li        r0, 0

.loc_0x570:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x5C4
  li        r0, 0x4
  stw       r0, 0x2E8(r5)
  li        r29, 0
  addi      r5, r31, 0
  lwz       r6, 0x4(r31)
  addi      r3, r1, 0x1E0
  li        r4, 0xB
  stb       r29, 0x2BD(r6)
  lwz       r6, 0x4(r31)
  stw       r29, 0x2EC(r6)
  bl        -0x5AB60
  lwz       r5, 0x4(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x5A93C
  lwz       r3, 0x4(r31)
  bl        -0xEF7F0
  stb       r29, 0xA(r31)
  b         .loc_0x87C

.loc_0x5C4:
  lbz       r0, 0x8(r31)
  cmplwi    r0, 0
  beq-      .loc_0x87C
  li        r0, 0x3
  stw       r0, 0x2E8(r5)
  li        r29, 0
  addi      r5, r31, 0
  lwz       r6, 0x4(r31)
  addi      r3, r1, 0x1D8
  li        r4, 0xD
  stb       r29, 0x2BD(r6)
  bl        -0x5ABB0
  lwz       r5, 0x4(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x5A98C
  stb       r29, 0x8(r31)
  lbz       r0, 0x9(r31)
  cmplwi    r0, 0
  beq-      .loc_0x87C
  stb       r29, 0x9(r31)
  lwz       r3, 0x4(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x87C
  lwz       r4, 0x0(r30)
  bl        -0xD5DA8
  b         .loc_0x87C

.loc_0x634:
  lwz       r4, 0x224(r3)
  lwz       r3, 0x2EC(r3)
  lwz       r0, 0x290(r4)
  cmpw      r3, r0
  blt-      .loc_0x668
  addi      r5, r31, 0
  addi      r3, r1, 0x1D0
  li        r4, -0x1
  bl        -0x5AC14
  lwz       r5, 0x4(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x5A980

.loc_0x668:
  lwz       r4, 0x4(r31)
  lbz       r0, 0x2BD(r4)
  cmplwi    r0, 0
  beq-      .loc_0x87C
  addi      r3, r1, 0x1B4
  bl        -0xE8F44
  addi      r0, r1, 0x1B4
  stw       r0, 0x1C8(r1)
  li        r0, 0
  addi      r3, r1, 0x1C4
  stw       r0, 0x1CC(r1)
  bl        -0xE9E24
  b         .loc_0x778

.loc_0x69C:
  lwz       r4, 0x1C4(r1)
  cmpwi     r4, -0x1
  bne-      .loc_0x6C8
  lwz       r3, 0x1C8(r1)
  li        r4, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r29, r3
  b         .loc_0x6E0

.loc_0x6C8:
  lwz       r3, 0x1C8(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0x6E0:
  lwz       r12, 0x0(r29)
  mr        r3, r29
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x770
  lwz       r0, 0x6C(r29)
  cmpwi     r0, 0
  bne-      .loc_0x770
  lwz       r4, 0x1C4(r1)
  cmpwi     r4, -0x1
  bne-      .loc_0x730
  lwz       r3, 0x1C8(r1)
  li        r4, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x744

.loc_0x730:
  lwz       r3, 0x1C8(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x744:
  lwz       r5, 0x4(r31)
  lwz       r4, 0x224(r5)
  lwz       r0, 0x2A0(r4)
  cmpwi     r0, 0
  beq-      .loc_0x768
  lhz       r3, 0x510(r3)
  lwz       r0, 0x3BC(r5)
  cmpw      r3, r0
  beq-      .loc_0x770

.loc_0x768:
  li        r0, 0x1
  b         .loc_0x7D8

.loc_0x770:
  addi      r3, r1, 0x1C4
  bl        -0xEA028

.loc_0x778:
  lwz       r3, 0x1C8(r1)
  lwz       r4, 0x1C4(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x7A0
  li        r0, 0x1
  b         .loc_0x7CC

.loc_0x7A0:
  lwz       r3, 0x1C8(r1)
  lwz       r4, 0x1C4(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x7C8
  li        r0, 0x1
  b         .loc_0x7CC

.loc_0x7C8:
  li        r0, 0

.loc_0x7CC:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x69C
  li        r0, 0

.loc_0x7D8:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x7F0
  addi      r3, r31, 0
  li        r4, 0x5
  bl        -0x9B4
  b         .loc_0x87C

.loc_0x7F0:
  addi      r3, r31, 0
  li        r4, 0x1
  bl        -0xBC4
  b         .loc_0x87C

.loc_0x800:
  lbz       r0, 0x2BD(r3)
  cmplwi    r0, 0
  beq-      .loc_0x87C
  lwz       r4, 0x10(r31)
  lwz       r0, 0x14(r31)
  cmpw      r4, r0
  blt-      .loc_0x824
  li        r0, 0x1
  b         .loc_0x828

.loc_0x824:
  li        r0, 0

.loc_0x828:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x870
  li        r0, 0
  stw       r0, 0x2E8(r3)
  addi      r5, r31, 0
  addi      r3, r1, 0x1AC
  lwz       r6, 0x4(r31)
  li        r4, 0
  stb       r0, 0x2BD(r6)
  lfs       f0, -0x5204(r2)
  lwz       r6, 0x4(r31)
  stfs      f0, 0x2D4(r6)
  bl        -0x5AE18
  lwz       r5, 0x4(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x5ABF4
  b         .loc_0x87C

.loc_0x870:
  addi      r3, r31, 0
  li        r4, 0x1
  bl        -0xC44

.loc_0x87C:
  lwz       r0, 0x21C(r1)
  lwz       r31, 0x214(r1)
  lwz       r30, 0x210(r1)
  lwz       r29, 0x20C(r1)
  addi      r1, r1, 0x218
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80179DE4
 * Size:	000024
 */
void PomGenOpenStarCallBack::invoke(zen::particleGenerator *)
{
/*
.loc_0x0:
  lwz       r3, 0x4(r3)
  lbz       r0, 0x0(r3)
  cmplwi    r0, 0
  bne-      .loc_0x1C
  lwz       r0, 0x80(r4)
  ori       r0, r0, 0x2
  stw       r0, 0x80(r4)

.loc_0x1C:
  li        r3, 0x1
  blr
*/
}