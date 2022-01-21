

/*
 * --INFO--
 * Address:	8021197C
 * Size:	00001C
 */
void GXInitLightAttn(void)
{
	/*
	.loc_0x0:
	  stfs      f1, 0x10(r3)
	  stfs      f2, 0x14(r3)
	  stfs      f3, 0x18(r3)
	  stfs      f4, 0x1C(r3)
	  stfs      f5, 0x20(r3)
	  stfs      f6, 0x24(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void GXInitLightAttnA(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void GXGetLightAttnA(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void GXInitLightAttnK(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void GXGetLightAttnK(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000180
 */
void GXInitLightSpot(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void GXInitLightDistAttn(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80211998
 * Size:	000010
 */
void GXInitLightPos(void)
{
	/*
	.loc_0x0:
	  stfs      f1, 0x28(r3)
	  stfs      f2, 0x2C(r3)
	  stfs      f3, 0x30(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void GXGetLightPos(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802119A8
 * Size:	00001C
 */
void GXInitLightDir(void)
{
	/*
	.loc_0x0:
	  fneg      f4, f1
	  fneg      f1, f2
	  fneg      f0, f3
	  stfs      f4, 0x34(r3)
	  stfs      f1, 0x38(r3)
	  stfs      f0, 0x3C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void GXGetLightDir(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802119C4
 * Size:	0000D4
 */
void GXInitSpecularDir(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  fneg      f0, f1
	  fneg      f1, f2
	  lfs       f5, -0x3C9C(r2)
	  fmuls     f6, f0, f0
	  lfs       f4, -0x3CA0(r2)
	  fsubs     f2, f5, f3
	  fmuls     f5, f1, f1
	  fmuls     f7, f2, f2
	  fadds     f5, f6, f5
	  fadds     f8, f7, f5
	  fcmpo     cr0, f8, f4
	  ble-      .loc_0x8C
	  fsqrte    f5, f8
	  lfd       f7, -0x3C98(r2)
	  lfd       f6, -0x3C90(r2)
	  fmul      f4, f5, f5
	  fmul      f5, f7, f5
	  fmul      f4, f8, f4
	  fsub      f4, f6, f4
	  fmul      f5, f5, f4
	  fmul      f4, f5, f5
	  fmul      f5, f7, f5
	  fmul      f4, f8, f4
	  fsub      f4, f6, f4
	  fmul      f5, f5, f4
	  fmul      f4, f5, f5
	  fmul      f5, f7, f5
	  fmul      f4, f8, f4
	  fsub      f4, f6, f4
	  fmul      f4, f5, f4
	  fmul      f4, f8, f4
	  frsp      f4, f4
	  stfs      f4, 0x18(r1)
	  lfs       f8, 0x18(r1)

	.loc_0x8C:
	  lfs       f4, -0x3C9C(r2)
	  fneg      f3, f3
	  fdivs     f6, f4, f8
	  fmuls     f5, f0, f6
	  fmuls     f4, f1, f6
	  fmuls     f2, f2, f6
	  stfs      f5, 0x34(r3)
	  stfs      f4, 0x38(r3)
	  stfs      f2, 0x3C(r3)
	  lfs       f4, -0x3C88(r2)
	  fmuls     f2, f4, f0
	  fmuls     f1, f4, f1
	  fmuls     f0, f4, f3
	  stfs      f2, 0x28(r3)
	  stfs      f1, 0x2C(r3)
	  stfs      f0, 0x30(r3)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void GXInitSpecularDirHA(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80211A98
 * Size:	000028
 */
void GXInitLightColor(void)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x1(r4)
	  lbz       r5, 0x0(r4)
	  lbz       r6, 0x2(r4)
	  rlwinm    r0,r0,16,0,15
	  rlwimi    r0,r5,24,0,7
	  lbz       r4, 0x3(r4)
	  rlwimi    r0,r6,8,16,23
	  or        r0, r4, r0
	  stw       r0, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void GXGetLightColor(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80211AC0
 * Size:	000144
 */
void GXLoadLightObjImm(void)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0x10
	  beq-      .loc_0x80
	  bge-      .loc_0x3C
	  cmpwi     r4, 0x4
	  beq-      .loc_0x70
	  bge-      .loc_0x30
	  cmpwi     r4, 0x2
	  beq-      .loc_0x68
	  bge-      .loc_0xA0
	  cmpwi     r4, 0x1
	  bge-      .loc_0x60
	  b         .loc_0xA0

	.loc_0x30:
	  cmpwi     r4, 0x8
	  beq-      .loc_0x78
	  b         .loc_0xA0

	.loc_0x3C:
	  cmpwi     r4, 0x40
	  beq-      .loc_0x90
	  bge-      .loc_0x54
	  cmpwi     r4, 0x20
	  beq-      .loc_0x88
	  b         .loc_0xA0

	.loc_0x54:
	  cmpwi     r4, 0x80
	  beq-      .loc_0x98
	  b         .loc_0xA0

	.loc_0x60:
	  li        r0, 0
	  b         .loc_0xA4

	.loc_0x68:
	  li        r0, 0x1
	  b         .loc_0xA4

	.loc_0x70:
	  li        r0, 0x2
	  b         .loc_0xA4

	.loc_0x78:
	  li        r0, 0x3
	  b         .loc_0xA4

	.loc_0x80:
	  li        r0, 0x4
	  b         .loc_0xA4

	.loc_0x88:
	  li        r0, 0x5
	  b         .loc_0xA4

	.loc_0x90:
	  li        r0, 0x6
	  b         .loc_0xA4

	.loc_0x98:
	  li        r0, 0x7
	  b         .loc_0xA4

	.loc_0xA0:
	  li        r0, 0

	.loc_0xA4:
	  rlwinm    r5,r0,4,0,27
	  lwz       r4, 0x2A68(r13)
	  addi      r0, r5, 0x600
	  li        r5, 0x10
	  lis       r6, 0xCC01
	  stb       r5, -0x8000(r6)
	  oris      r0, r0, 0xF
	  li        r5, 0
	  stw       r0, -0x8000(r6)
	  stw       r5, -0x8000(r6)
	  stw       r5, -0x8000(r6)
	  stw       r5, -0x8000(r6)
	  lwz       r0, 0xC(r3)
	  stw       r0, -0x8000(r6)
	  lfs       f0, 0x10(r3)
	  stfs      f0, -0x8000(r6)
	  lfs       f0, 0x14(r3)
	  stfs      f0, -0x8000(r6)
	  lfs       f0, 0x18(r3)
	  stfs      f0, -0x8000(r6)
	  lfs       f0, 0x1C(r3)
	  stfs      f0, -0x8000(r6)
	  lfs       f0, 0x20(r3)
	  stfs      f0, -0x8000(r6)
	  lfs       f0, 0x24(r3)
	  stfs      f0, -0x8000(r6)
	  lfs       f0, 0x28(r3)
	  stfs      f0, -0x8000(r6)
	  lfs       f0, 0x2C(r3)
	  stfs      f0, -0x8000(r6)
	  lfs       f0, 0x30(r3)
	  stfs      f0, -0x8000(r6)
	  lfs       f0, 0x34(r3)
	  stfs      f0, -0x8000(r6)
	  lfs       f0, 0x38(r3)
	  stfs      f0, -0x8000(r6)
	  lfs       f0, 0x3C(r3)
	  stfs      f0, -0x8000(r6)
	  sth       r5, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void GXLoadLightObjIndx(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80211C04
 * Size:	000168
 */
void GXSetChanAmbColor(void)
{
	/*
	.loc_0x0:
	  cmpwi     r3, 0x3
	  beq-      .loc_0xB4
	  bge-      .loc_0x24
	  cmpwi     r3, 0x1
	  beq-      .loc_0x68
	  bge-      .loc_0x9C
	  cmpwi     r3, 0
	  bge-      .loc_0x34
	  blr

	.loc_0x24:
	  cmpwi     r3, 0x5
	  beq-      .loc_0xFC
	  bgelr-
	  b         .loc_0xCC

	.loc_0x34:
	  lwz       r5, 0x2A68(r13)
	  li        r3, 0
	  lbz       r6, 0x2(r4)
	  lwz       r7, 0xA8(r5)
	  lbz       r5, 0x1(r4)
	  lbz       r0, 0x0(r4)
	  rlwinm    r7,r7,0,24,31
	  rlwimi    r7,r6,8,16,23
	  rlwinm    r4,r5,16,0,15
	  rlwimi    r4,r7,0,16,31
	  rlwinm    r7,r0,24,0,7
	  rlwimi    r7,r4,0,8,31
	  b         .loc_0x130

	.loc_0x68:
	  lwz       r5, 0x2A68(r13)
	  li        r3, 0x1
	  lbz       r6, 0x2(r4)
	  lwz       r7, 0xAC(r5)
	  lbz       r5, 0x1(r4)
	  lbz       r0, 0x0(r4)
	  rlwinm    r7,r7,0,24,31
	  rlwimi    r7,r6,8,16,23
	  rlwinm    r4,r5,16,0,15
	  rlwimi    r4,r7,0,16,31
	  rlwinm    r7,r0,24,0,7
	  rlwimi    r7,r4,0,8,31
	  b         .loc_0x130

	.loc_0x9C:
	  lwz       r5, 0x2A68(r13)
	  li        r3, 0
	  lbz       r7, 0x3(r4)
	  lwz       r0, 0xA8(r5)
	  rlwimi    r7,r0,0,0,23
	  b         .loc_0x130

	.loc_0xB4:
	  lwz       r5, 0x2A68(r13)
	  li        r3, 0x1
	  lbz       r7, 0x3(r4)
	  lwz       r0, 0xAC(r5)
	  rlwimi    r7,r0,0,0,23
	  b         .loc_0x130

	.loc_0xCC:
	  lbz       r0, 0x2(r4)
	  li        r3, 0
	  lbz       r7, 0x3(r4)
	  rlwinm    r6,r0,8,0,23
	  lbz       r5, 0x1(r4)
	  lbz       r0, 0x0(r4)
	  rlwimi    r6,r7,0,24,31
	  rlwinm    r4,r5,16,0,15
	  rlwimi    r4,r6,0,16,31
	  rlwinm    r7,r0,24,0,7
	  rlwimi    r7,r4,0,8,31
	  b         .loc_0x130

	.loc_0xFC:
	  lbz       r0, 0x2(r4)
	  li        r3, 0x1
	  lbz       r7, 0x3(r4)
	  rlwinm    r6,r0,8,0,23
	  lbz       r5, 0x1(r4)
	  lbz       r0, 0x0(r4)
	  rlwimi    r6,r7,0,24,31
	  rlwinm    r4,r5,16,0,15
	  rlwimi    r4,r6,0,16,31
	  rlwinm    r7,r0,24,0,7
	  rlwimi    r7,r4,0,8,31
	  b         .loc_0x130
	  blr

	.loc_0x130:
	  li        r0, 0x10
	  lwz       r4, 0x2A68(r13)
	  lis       r6, 0xCC01
	  stb       r0, -0x8000(r6)
	  addi      r0, r3, 0x100A
	  li        r5, 0
	  stw       r0, -0x8000(r6)
	  rlwinm    r0,r3,2,0,29
	  stw       r7, -0x8000(r6)
	  sth       r5, 0x2(r4)
	  lwz       r3, 0x2A68(r13)
	  add       r3, r3, r0
	  stw       r7, 0xA8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80211D6C
 * Size:	000168
 */
void GXSetChanMatColor(void)
{
	/*
	.loc_0x0:
	  cmpwi     r3, 0x3
	  beq-      .loc_0xB4
	  bge-      .loc_0x24
	  cmpwi     r3, 0x1
	  beq-      .loc_0x68
	  bge-      .loc_0x9C
	  cmpwi     r3, 0
	  bge-      .loc_0x34
	  blr

	.loc_0x24:
	  cmpwi     r3, 0x5
	  beq-      .loc_0xFC
	  bgelr-
	  b         .loc_0xCC

	.loc_0x34:
	  lwz       r5, 0x2A68(r13)
	  li        r3, 0
	  lbz       r6, 0x2(r4)
	  lwz       r7, 0xB0(r5)
	  lbz       r5, 0x1(r4)
	  lbz       r0, 0x0(r4)
	  rlwinm    r7,r7,0,24,31
	  rlwimi    r7,r6,8,16,23
	  rlwinm    r4,r5,16,0,15
	  rlwimi    r4,r7,0,16,31
	  rlwinm    r7,r0,24,0,7
	  rlwimi    r7,r4,0,8,31
	  b         .loc_0x130

	.loc_0x68:
	  lwz       r5, 0x2A68(r13)
	  li        r3, 0x1
	  lbz       r6, 0x2(r4)
	  lwz       r7, 0xB4(r5)
	  lbz       r5, 0x1(r4)
	  lbz       r0, 0x0(r4)
	  rlwinm    r7,r7,0,24,31
	  rlwimi    r7,r6,8,16,23
	  rlwinm    r4,r5,16,0,15
	  rlwimi    r4,r7,0,16,31
	  rlwinm    r7,r0,24,0,7
	  rlwimi    r7,r4,0,8,31
	  b         .loc_0x130

	.loc_0x9C:
	  lwz       r5, 0x2A68(r13)
	  li        r3, 0
	  lbz       r7, 0x3(r4)
	  lwz       r0, 0xB0(r5)
	  rlwimi    r7,r0,0,0,23
	  b         .loc_0x130

	.loc_0xB4:
	  lwz       r5, 0x2A68(r13)
	  li        r3, 0x1
	  lbz       r7, 0x3(r4)
	  lwz       r0, 0xB4(r5)
	  rlwimi    r7,r0,0,0,23
	  b         .loc_0x130

	.loc_0xCC:
	  lbz       r0, 0x2(r4)
	  li        r3, 0
	  lbz       r7, 0x3(r4)
	  rlwinm    r6,r0,8,0,23
	  lbz       r5, 0x1(r4)
	  lbz       r0, 0x0(r4)
	  rlwimi    r6,r7,0,24,31
	  rlwinm    r4,r5,16,0,15
	  rlwimi    r4,r6,0,16,31
	  rlwinm    r7,r0,24,0,7
	  rlwimi    r7,r4,0,8,31
	  b         .loc_0x130

	.loc_0xFC:
	  lbz       r0, 0x2(r4)
	  li        r3, 0x1
	  lbz       r7, 0x3(r4)
	  rlwinm    r6,r0,8,0,23
	  lbz       r5, 0x1(r4)
	  lbz       r0, 0x0(r4)
	  rlwimi    r6,r7,0,24,31
	  rlwinm    r4,r5,16,0,15
	  rlwimi    r4,r6,0,16,31
	  rlwinm    r7,r0,24,0,7
	  rlwimi    r7,r4,0,8,31
	  b         .loc_0x130
	  blr

	.loc_0x130:
	  li        r0, 0x10
	  lwz       r4, 0x2A68(r13)
	  lis       r6, 0xCC01
	  stb       r0, -0x8000(r6)
	  addi      r0, r3, 0x100C
	  li        r5, 0
	  stw       r0, -0x8000(r6)
	  rlwinm    r0,r3,2,0,29
	  stw       r7, -0x8000(r6)
	  sth       r5, 0x2(r4)
	  lwz       r3, 0x2A68(r13)
	  add       r3, r3, r0
	  stw       r7, 0xB0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80211ED4
 * Size:	00004C
 */
void GXSetNumChans(void)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r7,r3,0,24,31
	  rlwinm    r0,r3,4,20,27
	  addi      r6, r4, 0x204
	  lwz       r5, 0x204(r4)
	  li        r3, 0x10
	  lis       r4, 0xCC01
	  rlwinm    r5,r5,0,28,24
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  li        r0, 0x1009
	  stb       r3, -0x8000(r4)
	  lwz       r3, 0x2A68(r13)
	  stw       r0, -0x8000(r4)
	  stw       r7, -0x8000(r4)
	  lwz       r0, 0x4F0(r3)
	  ori       r0, r0, 0x4
	  stw       r0, 0x4F0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80211F20
 * Size:	0001E4
 */
void GXSetChanCtrl(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x38(r1)
	  cmpwi     r3, 0x4
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  stw       r28, 0x28(r1)
	  bne-      .loc_0x24
	  li        r11, 0
	  b         .loc_0x38

	.loc_0x24:
	  cmpwi     r3, 0x5
	  bne-      .loc_0x34
	  li        r11, 0x1
	  b         .loc_0x38

	.loc_0x34:
	  mr        r11, r3

	.loc_0x38:
	  rlwinm    r4,r4,1,23,30
	  or        r10, r4, r6
	  rlwinm    r0,r7,0,31,31
	  neg       r6, r0
	  subic     r4, r6, 0x1
	  rlwinm    r0,r7,0,30,30
	  neg       r12, r0
	  subfe     r6, r4, r6
	  subic     r4, r12, 0x1
	  subfe     r4, r4, r12
	  rlwinm    r0,r7,0,29,29
	  neg       r28, r0
	  subic     r0, r28, 0x1
	  rlwinm    r12,r7,0,28,28
	  subfe     r0, r0, r28
	  neg       r29, r12
	  subic     r28, r29, 0x1
	  rlwinm    r12,r7,0,27,27
	  neg       r30, r12
	  subfe     r28, r28, r29
	  subic     r29, r30, 0x1
	  rlwinm    r12,r7,0,26,26
	  neg       r31, r12
	  subfe     r29, r29, r30
	  subic     r30, r31, 0x1
	  rlwinm    r12,r7,0,25,25
	  subfe     r30, r30, r31
	  neg       r31, r12
	  subic     r12, r31, 0x1
	  rlwinm    r10,r10,0,26,24
	  rlwinm    r5,r5,6,0,25
	  or        r5, r10, r5
	  rlwinm    r10,r5,0,30,28
	  rlwinm    r5,r6,2,0,29
	  or        r5, r10, r5
	  rlwinm    r5,r5,0,29,27
	  rlwinm    r4,r4,3,0,28
	  or        r4, r5, r4
	  rlwinm    r4,r4,0,28,26
	  rlwinm    r0,r0,4,0,27
	  or        r0, r4, r0
	  rlwinm    r4,r0,0,27,25
	  rlwinm    r0,r28,5,0,26
	  or        r0, r4, r0
	  rlwinm    r4,r0,0,21,19
	  rlwinm    r0,r29,11,0,20
	  or        r0, r4, r0
	  rlwinm    r4,r0,0,20,18
	  rlwinm    r0,r30,12,0,19
	  or        r0, r4, r0
	  rlwinm    r7,r7,0,24,24
	  subfe     r31, r12, r31
	  neg       r12, r7
	  subic     r7, r12, 0x1
	  rlwinm    r4,r0,0,19,17
	  rlwinm    r0,r31,13,0,18
	  or        r0, r4, r0
	  subfe     r7, r7, r12
	  rlwinm    r4,r0,0,18,16
	  rlwinm    r0,r7,14,0,17
	  cmpwi     r9, 0
	  or        r6, r4, r0
	  bne-      .loc_0x138
	  li        r8, 0

	.loc_0x138:
	  subfic    r5, r9, 0x2
	  lwz       r4, 0x2A68(r13)
	  subic     r0, r5, 0x1
	  subfe     r10, r0, r5
	  neg       r5, r9
	  subic     r0, r5, 0x1
	  subfe     r7, r0, r5
	  rlwinm    r5,r6,0,25,22
	  rlwinm    r0,r8,7,0,24
	  or        r8, r5, r0
	  li        r6, 0x10
	  lis       r5, 0xCC01
	  stb       r6, -0x8000(r5)
	  addi      r0, r11, 0x100E
	  rlwinm    r9,r8,0,23,21
	  rlwinm    r8,r10,9,0,22
	  stw       r0, -0x8000(r5)
	  or        r0, r9, r8
	  rlwinm    r8,r0,0,22,20
	  rlwinm    r0,r7,10,0,21
	  or        r7, r8, r0
	  stw       r7, -0x8000(r5)
	  li        r0, 0
	  cmpwi     r3, 0x4
	  sth       r0, 0x2(r4)
	  bne-      .loc_0x1B4
	  stb       r6, -0x8000(r5)
	  li        r0, 0x1010
	  stw       r0, -0x8000(r5)
	  stw       r7, -0x8000(r5)
	  b         .loc_0x1CC

	.loc_0x1B4:
	  cmpwi     r3, 0x5
	  bne-      .loc_0x1CC
	  stb       r6, -0x8000(r5)
	  li        r0, 0x1011
	  stw       r0, -0x8000(r5)
	  stw       r7, -0x8000(r5)

	.loc_0x1CC:
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  blr
	*/
}
