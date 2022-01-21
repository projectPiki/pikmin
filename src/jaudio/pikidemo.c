

/*
 * --INFO--
 * Address:	8001A0E0
 * Size:	000010
 */
void Jac_DemoSceneInit(void)
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x2D40(r13)
	  stb       r0, 0x2D4F(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001A100
 * Size:	000018
 */
void Jac_DemoCheckFrameCall()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2D50(r13)
	  cmplwi    r4, 0
	  beqlr-
	  subi      r0, r4, 0x1
	  stw       r0, 0x2D50(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001A120
 * Size:	000050
 */
void Jac_DemoEventUnPauseCheck()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r3, 0x2D4F(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x3C
	  subi      r0, r3, 0x1
	  stb       r0, 0x2D4F(r13)
	  lbz       r0, 0x2D4F(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x3C
	  lis       r3, 0x2
	  bl        -0x9AF0
	  li        r4, 0x1
	  bl        -0x8B38

	.loc_0x3C:
	  bl        -0x5C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001A180
 * Size:	000048
 */
void Jac_DemoCheck()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x2D50(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x40
	  lwz       r0, 0x2D44(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x40
	  lwz       r0, 0x2D48(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x40
	  li        r3, 0
	  blr

	.loc_0x40:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001A1E0
 * Size:	000080
 */
void Jac_DemoWalkCheck()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x2D50(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x14
	  li        r3, 0
	  blr

	.loc_0x14:
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x40
	  lwz       r0, 0x2D44(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x40
	  lwz       r0, 0x2D48(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x40
	  li        r3, 0x1
	  blr

	.loc_0x40:
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, 0x59
	  beq-      .loc_0x70
	  bge-      .loc_0x64
	  cmpwi     r0, 0x2C
	  bge-      .loc_0x78
	  cmpwi     r0, 0x28
	  bge-      .loc_0x70
	  b         .loc_0x78

	.loc_0x64:
	  cmpwi     r0, 0x64
	  beq-      .loc_0x70
	  b         .loc_0x78

	.loc_0x70:
	  li        r3, 0x1
	  blr

	.loc_0x78:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001A260
 * Size:	00007C
 */
void Jac_DemoCheckEvent(unsigned char)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0xEC
	  cmpwi     r3, 0
	  beq-      .loc_0x68
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, 0x57
	  beq-      .loc_0x3C
	  bge-      .loc_0x44
	  cmpwi     r0, 0x20
	  bge-      .loc_0x44
	  cmpwi     r0, 0x1C
	  bge-      .loc_0x3C
	  b         .loc_0x44

	.loc_0x3C:
	  li        r3, 0
	  b         .loc_0x6C

	.loc_0x44:
	  mulli     r0, r0, 0xC
	  lis       r3, 0x8022
	  addi      r3, r3, 0x69B0
	  add       r3, r3, r0
	  lbz       r0, 0x2(r3)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x68
	  li        r3, 0
	  b         .loc_0x6C

	.loc_0x68:
	  li        r3, 0x1

	.loc_0x6C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001A2E0
 * Size:	00016C
 */
void DoSequence(unsigned long, unsigned long)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r28, 0x20(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x8022
	  mulli     r5, r31, 0xC
	  addi      r0, r3, 0x69B0
	  add       r30, r0, r5
	  stw       r4, 0xC(r1)
	  lwz       r28, 0x8(r30)
	  cmplwi    r28, 0
	  bne-      .loc_0x40
	  li        r0, -0x1
	  stw       r0, -0x7F0C(r13)
	  b         .loc_0x158

	.loc_0x40:
	  lwz       r29, 0xC(r1)

	.loc_0x44:
	  lwz       r0, -0x7F0C(r13)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r28, r0
	  stw       r0, 0x1C(r1)
	  lhz       r0, 0x1C(r1)
	  cmplw     r0, r29
	  bgt-      .loc_0x158
	  lhz       r3, 0x1E(r1)
	  cmplwi    r3, 0xFFF9
	  bne-      .loc_0x9C
	  cmpwi     r31, 0x18
	  beq-      .loc_0x90
	  bge-      .loc_0x148
	  cmpwi     r31, 0x14
	  beq-      .loc_0x84
	  b         .loc_0x148

	.loc_0x84:
	  li        r3, 0x11
	  bl        0xB38
	  b         .loc_0x148

	.loc_0x90:
	  li        r3, 0x1A
	  bl        0xB2C
	  b         .loc_0x148

	.loc_0x9C:
	  cmplwi    r3, 0xFFFA
	  bne-      .loc_0xEC
	  lbz       r3, 0x3(r30)
	  rlwinm.   r0,r3,0,24,24
	  beq-      .loc_0xBC
	  rlwinm    r3,r3,0,28,31
	  bl        -0x374
	  b         .loc_0x148

	.loc_0xBC:
	  lis       r3, 0x3
	  bl        -0x9D40
	  stw       r3, 0x2D34(r13)
	  li        r4, 0
	  lbz       r0, 0x3(r30)
	  lwz       r3, 0x2D34(r13)
	  rlwinm    r5,r0,0,28,31
	  bl        -0xA038
	  lbz       r0, 0x3(r30)
	  rlwinm    r0,r0,0,28,31
	  stw       r0, 0x2D38(r13)
	  b         .loc_0x148

	.loc_0xEC:
	  cmplwi    r3, 0xFFFF
	  bne-      .loc_0xFC
	  bl        0x9CC
	  b         .loc_0x158

	.loc_0xFC:
	  cmplwi    r3, 0xFFFE
	  bne-      .loc_0x110
	  li        r0, -0x1
	  stw       r0, -0x7F0C(r13)
	  b         .loc_0x158

	.loc_0x110:
	  cmplwi    r3, 0xFFFD
	  bne-      .loc_0x124
	  li        r0, -0x1
	  stw       r0, -0x7F0C(r13)
	  b         .loc_0x158

	.loc_0x124:
	  cmplwi    r3, 0xFFFC
	  bne-      .loc_0x134
	  bl        0x734
	  b         .loc_0x148

	.loc_0x134:
	  cmplwi    r3, 0xFFFB
	  bne-      .loc_0x144
	  bl        0x6A4
	  b         .loc_0x148

	.loc_0x144:
	  bl        0x5FC

	.loc_0x148:
	  lwz       r3, -0x7F0C(r13)
	  addi      r0, r3, 0x1
	  stw       r0, -0x7F0C(r13)
	  b         .loc_0x44

	.loc_0x158:
	  lmw       r28, 0x20(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001A460
 * Size:	000044
 */
void Jac_PlayDemoSequenceDirect(unsigned long)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x3
	  bl        -0x9E18
	  stw       r3, 0x2D34(r13)
	  rlwinm    r5,r31,0,16,31
	  li        r4, 0
	  lwz       r3, 0x2D34(r13)
	  bl        -0xA10C
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001A4C0
 * Size:	000050
 */
void Jac_InitDemoSystem()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x1
	  stw       r0, 0x4(r1)
	  addi      r3, r3, 0xF
	  stwu      r1, -0x8(r1)
	  bl        -0x9E74
	  stw       r3, 0x2D30(r13)
	  lwz       r4, 0x2D30(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x40
	  lis       r3, 0x8036
	  li        r5, 0x2
	  addi      r3, r3, 0x4618
	  bl        0x14AC
	  li        r0, 0x1
	  stw       r0, 0x2D3C(r13)

	.loc_0x40:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001A520
 * Size:	0004F0
 */
void Jac_StartDemo(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r29, 0x54(r1)
	  stw       r3, 0x8(r1)
	  lis       r3, 0x8022
	  addi      r31, r3, 0x64B0
	  lwz       r29, 0x8(r1)
	  mulli     r0, r29, 0xC
	  cmplwi    r29, 0x50
	  add       r30, r31, r0
	  addi      r30, r30, 0x500
	  blt-      .loc_0x68
	  cmpwi     r29, 0x5F
	  bge-      .loc_0x54
	  cmpwi     r29, 0x50
	  beq-      .loc_0x68
	  blt-      .loc_0x4DC
	  cmpwi     r29, 0x57
	  bge-      .loc_0x68
	  b         .loc_0x4DC

	.loc_0x54:
	  cmpwi     r29, 0x73
	  bge-      .loc_0x4DC
	  cmpwi     r29, 0x71
	  bge-      .loc_0x68
	  b         .loc_0x4DC

	.loc_0x68:
	  cmpwi     r29, 0x3C
	  bge-      .loc_0x80
	  cmpwi     r29, 0x38
	  bge-      .loc_0x4DC
	  b         .loc_0x80
	  b         .loc_0x4DC

	.loc_0x80:
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x94
	  cmplw     r29, r0
	  beq-      .loc_0x4DC

	.loc_0x94:
	  bl        -0xD54
	  cmpwi     r3, 0x1
	  bne-      .loc_0xB8
	  cmpwi     r29, 0x28
	  bge-      .loc_0xB8
	  cmpwi     r29, 0x24
	  bge-      .loc_0x4DC
	  b         .loc_0xB8
	  b         .loc_0x4DC

	.loc_0xB8:
	  lwz       r0, 0x2D3C(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0xD4
	  bl        -0x124
	  lwz       r0, 0x2D3C(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x4DC

	.loc_0xD4:
	  li        r3, 0x4
	  bl        -0x3C38
	  cmpwi     r29, 0x28
	  bge-      .loc_0x128
	  cmpwi     r29, 0x19
	  beq-      .loc_0x168
	  bge-      .loc_0x108
	  cmpwi     r29, 0x14
	  beq-      .loc_0x218
	  bge-      .loc_0x1B4
	  cmpwi     r29, 0x12
	  bge-      .loc_0x168
	  b         .loc_0x218

	.loc_0x108:
	  cmpwi     r29, 0x20
	  bge-      .loc_0x11C
	  cmpwi     r29, 0x1C
	  bge-      .loc_0x20C
	  b         .loc_0x218

	.loc_0x11C:
	  cmpwi     r29, 0x24
	  bge-      .loc_0x218
	  b         .loc_0x1D4

	.loc_0x128:
	  cmpwi     r29, 0x57
	  beq-      .loc_0x20C
	  bge-      .loc_0x158
	  cmpwi     r29, 0x4F
	  beq-      .loc_0x1B4
	  bge-      .loc_0x14C
	  cmpwi     r29, 0x2C
	  bge-      .loc_0x218
	  b         .loc_0x1F0

	.loc_0x14C:
	  cmpwi     r29, 0x51
	  bge-      .loc_0x218
	  b         .loc_0x168

	.loc_0x158:
	  cmpwi     r29, 0x59
	  beq-      .loc_0x1F0
	  bge-      .loc_0x218
	  b         .loc_0x1D4

	.loc_0x168:
	  lbz       r0, 0x2D4E(r13)
	  cmpwi     r0, 0x7
	  beq-      .loc_0x19C
	  bge-      .loc_0x184
	  cmpwi     r0, 0x4
	  beq-      .loc_0x190
	  b         .loc_0x218

	.loc_0x184:
	  cmpwi     r0, 0x1D
	  beq-      .loc_0x1A8
	  b         .loc_0x218

	.loc_0x190:
	  li        r0, 0x12
	  stw       r0, 0x8(r1)
	  b         .loc_0x218

	.loc_0x19C:
	  li        r0, 0x13
	  stw       r0, 0x8(r1)
	  b         .loc_0x218

	.loc_0x1A8:
	  li        r0, 0x19
	  stw       r0, 0x8(r1)
	  b         .loc_0x218

	.loc_0x1B4:
	  lbz       r0, 0x2D4C(r13)
	  lbzx      r0, r31, r0
	  cmplwi    r0, 0
	  bne-      .loc_0x218
	  li        r0, 0x65
	  addi      r30, r31, 0x9BC
	  stw       r0, 0x8(r1)
	  b         .loc_0x218

	.loc_0x1D4:
	  bl        -0xE94
	  cmpwi     r3, 0
	  beq-      .loc_0x218
	  li        r0, 0x66
	  addi      r30, r31, 0x9C8
	  stw       r0, 0x8(r1)
	  b         .loc_0x218

	.loc_0x1F0:
	  lbz       r0, 0x2D4D(r13)
	  cmplwi    r0, 0x3
	  bne-      .loc_0x218
	  li        r0, 0x64
	  addi      r30, r31, 0x9B0
	  stw       r0, 0x8(r1)
	  b         .loc_0x218

	.loc_0x20C:
	  li        r3, 0
	  bl        -0x2390
	  bl        -0xFD4

	.loc_0x218:
	  lbz       r0, 0x0(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x22C
	  li        r3, 0x19
	  bl        -0x3BA8

	.loc_0x22C:
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x244
	  bl        0x708
	  lwz       r3, 0x8(r1)
	  bl        0x740

	.loc_0x244:
	  lwz       r0, 0x2D40(r13)
	  lwz       r31, 0x8(r1)
	  cmplwi    r0, 0
	  stw       r31, -0x7F10(r13)
	  bne-      .loc_0x260
	  mr        r3, r31
	  bl        0x8E4

	.loc_0x260:
	  lbz       r0, 0x1(r30)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x2F0
	  bge-      .loc_0x288
	  cmpwi     r0, 0x1
	  beq-      .loc_0x300
	  bge-      .loc_0x2AC
	  cmpwi     r0, 0
	  bge-      .loc_0x298
	  b         .loc_0x300

	.loc_0x288:
	  cmpwi     r0, 0x5
	  beq-      .loc_0x2DC
	  bge-      .loc_0x300
	  b         .loc_0x2C0

	.loc_0x298:
	  li        r3, 0
	  bl        -0x1C3C
	  li        r3, 0x1
	  bl        -0x1C44
	  b         .loc_0x300

	.loc_0x2AC:
	  lfs       f1, -0x7E18(r2)
	  li        r3, 0x1
	  li        r4, 0xF
	  bl        -0x11D8
	  b         .loc_0x300

	.loc_0x2C0:
	  li        r3, 0
	  li        r4, 0xF
	  bl        -0x1CA8
	  li        r3, 0x1
	  li        r4, 0xF
	  bl        -0x1CB4
	  b         .loc_0x300

	.loc_0x2DC:
	  lfs       f1, -0x7E14(r2)
	  li        r3, 0x1
	  li        r4, 0x1E
	  bl        -0x1208
	  b         .loc_0x300

	.loc_0x2F0:
	  lfs       f1, -0x7E10(r2)
	  li        r3, 0x1
	  li        r4, 0x8
	  bl        -0x121C

	.loc_0x300:
	  lbz       r0, 0x2(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x320
	  bge-      .loc_0x314
	  b         .loc_0x354

	.loc_0x314:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x354
	  b         .loc_0x344

	.loc_0x320:
	  li        r0, 0
	  lis       r3, 0x2
	  stb       r0, 0x2D4F(r13)
	  bl        -0xA1EC
	  stw       r3, 0x48(r1)
	  li        r4, 0x1
	  lwz       r3, 0x48(r1)
	  bl        -0x937C
	  b         .loc_0x354

	.loc_0x344:
	  bl        -0x2824
	  li        r3, 0
	  li        r4, 0
	  bl        -0x2670

	.loc_0x354:
	  cmpwi     r31, 0x2
	  bge-      .loc_0x364
	  cmpwi     r31, 0
	  bge-      .loc_0x370

	.loc_0x364:
	  lwz       r0, 0x2D40(r13)
	  cmplwi    r0, 0x3
	  blt+      .loc_0x364

	.loc_0x370:
	  li        r0, 0
	  cmplwi    r31, 0x14
	  stw       r0, 0x2D40(r13)
	  bne-      .loc_0x3A8
	  li        r0, 0x1
	  li        r3, 0x11
	  stw       r0, 0x2D40(r13)
	  bl        0x5F4
	  lwz       r0, 0x2D40(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x3A8

	.loc_0x39C:
	  lwz       r0, 0x2D40(r13)
	  cmplwi    r0, 0x3
	  blt+      .loc_0x39C

	.loc_0x3A8:
	  cmplwi    r31, 0x18
	  bne-      .loc_0x3D8
	  li        r0, 0x1
	  li        r3, 0x1A
	  stw       r0, 0x2D40(r13)
	  bl        0x5C4
	  lwz       r0, 0x2D40(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x3D8

	.loc_0x3CC:
	  lwz       r0, 0x2D40(r13)
	  cmplwi    r0, 0x3
	  blt+      .loc_0x3CC

	.loc_0x3D8:
	  lbz       r3, 0x3(r30)
	  rlwinm    r0,r3,0,25,31
	  cmpwi     r0, 0x40
	  beq-      .loc_0x454
	  bge-      .loc_0x3F4
	  cmpwi     r0, 0
	  beq-      .loc_0x454

	.loc_0x3F4:
	  rlwinm.   r0,r3,0,24,24
	  beq-      .loc_0x414
	  lwz       r0, 0x8(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x454
	  rlwinm    r3,r3,0,28,31
	  bl        -0x90C
	  b         .loc_0x454

	.loc_0x414:
	  rlwinm.   r0,r3,0,28,31
	  beq-      .loc_0x454
	  lwz       r0, 0x8(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x454
	  lis       r3, 0x3
	  bl        -0xA2EC
	  stw       r3, 0x2D34(r13)
	  li        r4, 0
	  lbz       r0, 0x3(r30)
	  lwz       r3, 0x2D34(r13)
	  rlwinm    r5,r0,0,28,31
	  bl        -0xA5E4
	  lbz       r0, 0x3(r30)
	  rlwinm    r0,r0,0,28,31
	  stw       r0, 0x2D38(r13)

	.loc_0x454:
	  li        r0, -0x1
	  li        r3, 0
	  stw       r0, -0x7F08(r13)
	  stw       r3, -0x7F0C(r13)
	  lbz       r0, 0x4(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x49C
	  bge-      .loc_0x484
	  cmpwi     r0, 0
	  beq-      .loc_0x49C
	  bge-      .loc_0x490
	  b         .loc_0x49C

	.loc_0x484:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x49C
	  b         .loc_0x498

	.loc_0x490:
	  stw       r3, -0x7F08(r13)
	  b         .loc_0x49C

	.loc_0x498:
	  stw       r3, -0x7F08(r13)

	.loc_0x49C:
	  lwz       r3, 0x2D30(r13)
	  rlwinm    r5,r31,0,16,31
	  li        r4, 0
	  bl        -0xA648
	  lwz       r0, -0x7F08(r13)
	  cmpwi     r0, 0
	  blt-      .loc_0x4C8
	  lwz       r3, 0x2D30(r13)
	  rlwinm    r5,r31,0,16,31
	  li        r4, 0x1
	  bl        -0xA664

	.loc_0x4C8:
	  li        r3, 0
	  li        r4, 0
	  bl        -0x27F0
	  li        r3, 0x5
	  bl        -0x4038

	.loc_0x4DC:
	  lmw       r29, 0x54(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001AA20
 * Size:	000040
 */
void Jac_DemoSound(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  lwz       r0, -0x7F10(r13)
	  stw       r3, 0x8(r1)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x30
	  lwz       r0, 0x8(r1)
	  lis       r3, 0x8036
	  addi      r3, r3, 0x4618
	  rlwinm    r4,r0,0,16,31
	  bl        0xFB4

	.loc_0x30:
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001AA60
 * Size:	00004C
 */
void Jac_DemoFrame(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r4, r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, -0x7F10(r13)
	  cmpwi     r5, -0x1
	  bne-      .loc_0x24
	  li        r3, 0
	  b         .loc_0x3C

	.loc_0x24:
	  lwz       r0, -0x7F0C(r13)
	  cmpwi     r0, 0
	  blt-      .loc_0x38
	  mr        r3, r5
	  bl        -0x7B4

	.loc_0x38:
	  li        r3, 0x1

	.loc_0x3C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001AAC0
 * Size:	00007C
 */
void Jac_BgmAnimEndRecover()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x69B0
	  stwu      r1, -0x8(r1)
	  lwz       r4, -0x7F10(r13)
	  mulli     r3, r4, 0xC
	  add       r3, r0, r3
	  lbz       r0, 0x1(r3)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x5C
	  bge-      .loc_0x3C
	  cmpwi     r0, 0x2
	  bge-      .loc_0x48
	  b         .loc_0x6C

	.loc_0x3C:
	  cmpwi     r0, 0x5
	  beq-      .loc_0x48
	  b         .loc_0x6C

	.loc_0x48:
	  lfs       f1, -0x7E14(r2)
	  li        r3, 0x2
	  li        r4, 0x46
	  bl        -0x1514
	  b         .loc_0x6C

	.loc_0x5C:
	  lfs       f1, -0x7E14(r2)
	  li        r3, 0x2
	  li        r4, 0x46
	  bl        -0x1528

	.loc_0x6C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001AB40
 * Size:	00005C
 */
void Jac_BgmAnimEndStop()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x69B0
	  stwu      r1, -0x8(r1)
	  lwz       r4, -0x7F10(r13)
	  mulli     r3, r4, 0xC
	  add       r3, r0, r3
	  lbz       r3, 0x3(r3)
	  cmpwi     r3, 0
	  beq-      .loc_0x4C
	  rlwinm.   r0,r3,0,26,26
	  bne-      .loc_0x4C
	  rlwinm.   r0,r3,0,24,24
	  beq-      .loc_0x48
	  rlwinm    r3,r3,0,28,31
	  bl        -0xC40
	  b         .loc_0x4C

	.loc_0x48:
	  bl        0x18

	.loc_0x4C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001ABA0
 * Size:	0000D0
 */
void Jac_DemoBGMForceStop()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0xA550
	  stw       r3, 0x2D34(r13)
	  li        r4, 0
	  li        r5, 0
	  lwz       r3, 0x2D34(r13)
	  bl        -0xA844
	  lwz       r0, 0x2D38(r13)
	  cmplwi    r0, 0xA
	  bgt-      .loc_0xB8
	  lis       r3, 0x8022
	  rlwinm    r0,r0,2,0,29
	  addi      r3, r3, 0x6F14
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  li        r3, 0xD
	  li        r4, 0x7
	  bl        -0xE3D4
	  b         .loc_0xB8
	  li        r3, 0xD
	  li        r4, 0x3
	  bl        -0xE3E4
	  b         .loc_0xB8
	  li        r3, 0xD
	  li        r4, 0x4
	  bl        -0xE3F4
	  b         .loc_0xB8
	  li        r3, 0xD
	  li        r4, 0x5
	  bl        -0xE404
	  b         .loc_0xB8
	  li        r3, 0xD
	  li        r4, 0x6
	  bl        -0xE414
	  b         .loc_0xB8
	  li        r3, 0xD
	  li        r4, 0x1
	  bl        -0xE424
	  b         .loc_0xB8
	  li        r3, 0xD
	  li        r4, 0x8
	  bl        -0xE434

	.loc_0xB8:
	  li        r0, 0
	  stw       r0, 0x2D38(r13)
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001AC80
 * Size:	000108
 */
void __Jac_FinishDemo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, -0x1
	  beq-      .loc_0xF4
	  mulli     r4, r0, 0xC
	  lis       r3, 0x8022
	  addi      r0, r3, 0x69B0
	  add       r31, r0, r4
	  lbz       r0, 0x1(r31)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x68
	  bge-      .loc_0x48
	  cmpwi     r0, 0x2
	  bge-      .loc_0x54
	  b         .loc_0x78

	.loc_0x48:
	  cmpwi     r0, 0x5
	  beq-      .loc_0x54
	  b         .loc_0x78

	.loc_0x54:
	  lfs       f1, -0x7E0C(r2)
	  li        r3, 0
	  li        r4, 0x46
	  bl        -0x16E0
	  b         .loc_0x78

	.loc_0x68:
	  lfs       f1, -0x7E0C(r2)
	  li        r3, 0
	  li        r4, 0x46
	  bl        -0x16F4

	.loc_0x78:
	  lbz       r0, 0x2(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xA4
	  bge-      .loc_0x8C
	  b         .loc_0xAC

	.loc_0x8C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0xAC
	  li        r3, 0
	  li        r4, 0
	  bl        -0x2B1C
	  b         .loc_0xAC

	.loc_0xA4:
	  li        r0, 0x6
	  stb       r0, 0x2D4F(r13)

	.loc_0xAC:
	  lbz       r3, 0x3(r31)
	  cmpwi     r3, 0
	  beq-      .loc_0xD8
	  rlwinm.   r0,r3,0,26,26
	  bne-      .loc_0xD8
	  rlwinm.   r0,r3,0,24,24
	  beq-      .loc_0xD4
	  rlwinm    r3,r3,0,28,31
	  bl        -0xE0C
	  b         .loc_0xD8

	.loc_0xD4:
	  bl        -0x1B4

	.loc_0xD8:
	  lwz       r3, 0x2D30(r13)
	  li        r4, 0
	  li        r5, 0
	  bl        -0xA9E4
	  li        r0, -0x1
	  stw       r0, -0x7F10(r13)
	  stw       r0, -0x7F0C(r13)

	.loc_0xF4:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001ADA0
 * Size:	0000A8
 */
void Jac_FinishDemo(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x6
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  lwz       r0, -0x7F10(r13)
	  stw       r0, 0x10(r1)
	  bl        -0x43F8
	  bl        -0x13C
	  lwz       r0, 0x10(r1)
	  cmpwi     r0, 0
	  blt-      .loc_0x90
	  cmpwi     r0, 0x18
	  beq-      .loc_0x90
	  bge-      .loc_0x5C
	  cmpwi     r0, 0x11
	  beq-      .loc_0x90
	  bge-      .loc_0x50
	  cmpwi     r0, 0x1
	  beq-      .loc_0x90
	  b         .loc_0x88

	.loc_0x50:
	  cmpwi     r0, 0x14
	  beq-      .loc_0x90
	  b         .loc_0x88

	.loc_0x5C:
	  cmpwi     r0, 0x57
	  beq-      .loc_0x7C
	  bge-      .loc_0x88
	  cmpwi     r0, 0x20
	  bge-      .loc_0x88
	  cmpwi     r0, 0x1C
	  bge-      .loc_0x7C
	  b         .loc_0x88

	.loc_0x7C:
	  li        r0, 0x64
	  stw       r0, 0x2D50(r13)
	  b         .loc_0x90

	.loc_0x88:
	  li        r0, 0
	  stw       r0, 0x2D40(r13)

	.loc_0x90:
	  li        r3, 0x7
	  bl        -0x4474
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001AE60
 * Size:	000020
 */
void Jac_FinishDemo_NoErase()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x1EC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001AE80
 * Size:	000020
 */
void __Loaded(unsigned long)
{
	/*
	.loc_0x0:
	  lis       r4, 0x8000
	  rlwinm    r3,r3,0,0,15
	  addi      r0, r4, 0x1
	  cmpw      r3, r0
	  bgelr-
	  li        r0, 0x3
	  stw       r0, 0x2D40(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001AEA0
 * Size:	0001AC
 */
void __Prepare_BGM(unsigned long)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mulli     r5, r3, 0xC
	  stw       r0, 0x4(r1)
	  lis       r4, 0x8022
	  cmplwi    r3, 0x50
	  addi      r0, r4, 0x69B0
	  stwu      r1, -0x8(r1)
	  add       r4, r0, r5
	  blt-      .loc_0x70
	  cmpwi     r3, 0x64
	  bge-      .loc_0x4C
	  cmpwi     r3, 0x57
	  bge-      .loc_0x40
	  cmpwi     r3, 0x50
	  beq-      .loc_0x70
	  b         .loc_0x19C

	.loc_0x40:
	  cmpwi     r3, 0x5F
	  bge-      .loc_0x19C
	  b         .loc_0x70

	.loc_0x4C:
	  cmpwi     r3, 0x71
	  bge-      .loc_0x60
	  cmpwi     r3, 0x67
	  bge-      .loc_0x19C
	  b         .loc_0x70

	.loc_0x60:
	  cmpwi     r3, 0x73
	  bge-      .loc_0x19C
	  b         .loc_0x70
	  b         .loc_0x19C

	.loc_0x70:
	  cmpwi     r3, 0x3C
	  bge-      .loc_0x88
	  cmpwi     r3, 0x38
	  bge-      .loc_0x19C
	  b         .loc_0x88
	  b         .loc_0x19C

	.loc_0x88:
	  lbz       r4, 0x3(r4)
	  rlwinm    r0,r4,0,25,31
	  cmpwi     r0, 0x40
	  beq-      .loc_0x188
	  bge-      .loc_0xA4
	  cmpwi     r0, 0
	  beq-      .loc_0x188

	.loc_0xA4:
	  rlwinm.   r0,r4,0,24,24
	  beq-      .loc_0xC0
	  rlwinm    r3,r4,0,28,31
	  bl        -0xFD0
	  li        r0, 0x3
	  stw       r0, 0x2D40(r13)
	  b         .loc_0x19C

	.loc_0xC0:
	  rlwinm.   r0,r4,0,25,25
	  beq-      .loc_0xD4
	  li        r0, 0x3
	  stw       r0, 0x2D40(r13)
	  b         .loc_0x19C

	.loc_0xD4:
	  rlwinm    r0,r4,0,28,31
	  cmplwi    r0, 0xA
	  bgt-      .loc_0x174
	  lis       r4, 0x8022
	  rlwinm    r0,r0,2,0,29
	  addi      r4, r4, 0x6F40
	  lwzx      r0, r4, r0
	  mtctr     r0
	  bctr
	  li        r3, 0xD
	  li        r4, 0x7
	  bl        -0xE8C0
	  b         .loc_0x174
	  li        r3, 0xD
	  li        r4, 0x3
	  bl        -0xE8D0
	  b         .loc_0x174
	  li        r3, 0xD
	  li        r4, 0x4
	  bl        -0xE8E0
	  b         .loc_0x174
	  li        r3, 0xD
	  li        r4, 0x5
	  bl        -0xE8F0
	  b         .loc_0x174
	  li        r3, 0xD
	  li        r4, 0x6
	  bl        -0xE900
	  b         .loc_0x174
	  li        r3, 0xD
	  li        r4, 0x1
	  bl        -0xE910
	  b         .loc_0x174
	  li        r3, 0xD
	  li        r4, 0x8
	  bl        -0xE920
	  b         .loc_0x174
	  li        r0, 0x3
	  stw       r0, 0x2D40(r13)
	  b         .loc_0x19C

	.loc_0x174:
	  cmpwi     r3, 0
	  bne-      .loc_0x188
	  li        r0, 0
	  stw       r0, 0x2D40(r13)
	  b         .loc_0x19C

	.loc_0x188:
	  lis       r4, 0x8002
	  lis       r3, 0x8000
	  subi      r5, r4, 0x5180
	  li        r4, 0
	  bl        -0x130B8

	.loc_0x19C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001B060
 * Size:	0000A8
 */
void Jac_PrepareDemo(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  cmplwi    r3, 0x50
	  blt-      .loc_0x68
	  cmpwi     r3, 0x64
	  bge-      .loc_0x44
	  cmpwi     r3, 0x57
	  bge-      .loc_0x38
	  cmpwi     r3, 0x50
	  beq-      .loc_0x68
	  b         .loc_0x98

	.loc_0x38:
	  cmpwi     r3, 0x5F
	  bge-      .loc_0x98
	  b         .loc_0x68

	.loc_0x44:
	  cmpwi     r3, 0x71
	  bge-      .loc_0x58
	  cmpwi     r3, 0x67
	  bge-      .loc_0x98
	  b         .loc_0x68

	.loc_0x58:
	  cmpwi     r3, 0x73
	  bge-      .loc_0x98
	  b         .loc_0x68
	  b         .loc_0x98

	.loc_0x68:
	  cmpwi     r3, 0x3C
	  bge-      .loc_0x80
	  cmpwi     r3, 0x38
	  bge-      .loc_0x98
	  b         .loc_0x80
	  b         .loc_0x98

	.loc_0x80:
	  lwz       r0, 0x2D40(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x94
	  li        r0, 0x1
	  stw       r0, 0x2D40(r13)

	.loc_0x94:
	  bl        -0x254

	.loc_0x98:
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001B120
 * Size:	0000D0
 */
void Jac_StartPartsFindDemo(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  lwz       r0, 0x2D44(r13)
	  stw       r3, 0x8(r1)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x38
	  cmpwi     r31, 0
	  beq-      .loc_0xBC
	  li        r3, 0x1E
	  bl        -0x45B0
	  b         .loc_0xBC

	.loc_0x38:
	  li        r0, 0
	  lis       r3, 0x2
	  stb       r0, 0x2D4F(r13)
	  bl        -0xAB04
	  li        r4, 0x1
	  bl        -0x9C8C
	  li        r3, 0
	  li        r4, 0
	  bl        -0x2F78
	  bl        -0x2B7C
	  cmpwi     r31, 0
	  beq-      .loc_0x9C
	  lfs       f1, -0x7E08(r2)
	  li        r3, 0x1
	  li        r4, 0xF
	  bl        -0x1B94
	  lwz       r0, 0x8(r1)
	  cmplwi    r0, 0
	  bne-      .loc_0x90
	  li        r3, 0x24
	  bl        -0x4608
	  b         .loc_0xB4

	.loc_0x90:
	  li        r3, 0x1E
	  bl        -0x4614
	  b         .loc_0xB4

	.loc_0x9C:
	  lfs       f1, -0x7E14(r2)
	  li        r3, 0x1
	  li        r4, 0x1E
	  bl        -0x1BC8
	  li        r3, 0x1F
	  bl        -0x4630

	.loc_0xB4:
	  li        r0, 0x1
	  stw       r0, 0x2D44(r13)

	.loc_0xBC:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001B200
 * Size:	00004C
 */
void Jac_FinishPartsFindDemo(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x2D44(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x3C
	  li        r0, 0x3
	  lfs       f1, -0x7E0C(r2)
	  stb       r0, 0x2D4F(r13)
	  li        r3, 0
	  li        r4, 0x46
	  bl        -0x1C2C
	  bl        -0x2BF0
	  li        r0, 0
	  stw       r0, 0x2D44(r13)

	.loc_0x3C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001B260
 * Size:	000084
 */
void Jac_StartTextDemo(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x2D48(r13)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x74
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x74
	  lwz       r0, 0x2D44(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x34
	  b         .loc_0x74

	.loc_0x34:
	  li        r0, 0
	  lis       r3, 0x2
	  stb       r0, 0x2D4F(r13)
	  bl        -0xAC40
	  li        r4, 0x1
	  bl        -0x9DC8
	  li        r3, 0
	  li        r4, 0
	  bl        -0x30B4
	  bl        -0x2CB8
	  lfs       f1, -0x7E14(r2)
	  li        r3, 0x1
	  li        r4, 0x1E
	  bl        -0x1CC8
	  li        r0, 0x1
	  stw       r0, 0x2D48(r13)

	.loc_0x74:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001B300
 * Size:	000068
 */
void Jac_FinishTextDemo(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x2D48(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x58
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x58
	  lwz       r0, 0x2D44(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x34
	  b         .loc_0x58

	.loc_0x34:
	  li        r0, 0x3
	  stb       r0, 0x2D4F(r13)
	  bl        -0x2CFC
	  lfs       f1, -0x7E0C(r2)
	  li        r3, 0
	  li        r4, 0x46
	  bl        -0x1D4C
	  li        r0, 0
	  stw       r0, 0x2D48(r13)

	.loc_0x58:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001B380
 * Size:	000018
 */
void Jac_SetDemoPartsID(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x10(r1)
	  stw       r3, 0x8(r1)
	  lwz       r0, 0x8(r1)
	  stb       r0, 0x2D4C(r13)
	  addi      r1, r1, 0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001B3A0
 * Size:	000018
 */
void Jac_SetDemoOnyons(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x10(r1)
	  stw       r3, 0x8(r1)
	  lwz       r0, 0x8(r1)
	  stb       r0, 0x2D4D(r13)
	  addi      r1, r1, 0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001B3C0
 * Size:	000018
 */
void Jac_SetDemoPartsCount(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x10(r1)
	  stw       r3, 0x8(r1)
	  lwz       r0, 0x8(r1)
	  stb       r0, 0x2D4E(r13)
	  addi      r1, r1, 0x10
	  blr
	*/
}
