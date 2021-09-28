

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
 * Address:	801E7AB0
 * Size:	0001F8
 */
void zen::DrawCountDown::DrawCountDown()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x70(r1)
  stw       r31, 0x6C(r1)
  stw       r30, 0x68(r1)
  stw       r29, 0x64(r1)
  addi      r29, r3, 0
  li        r3, 0x100
  bl        -0x1A0ACC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x48
  lis       r4, 0x802E
  addi      r4, r4, 0x5A38
  li        r5, 0
  li        r6, 0
  li        r7, 0
  bl        -0x28580

.loc_0x48:
  stw       r30, 0x0(r29)
  li        r31, 0
  li        r3, 0x2C
  stw       r31, 0xC(r29)
  bl        -0x1A0B04
  stw       r3, 0x8(r29)
  li        r30, 0

.loc_0x64:
  addi      r3, r1, 0x54
  crclr     6, 0x6
  subfic    r5, r30, 0xA
  addi      r4, r13, 0x2680
  bl        0x2EA74
  lwz       r3, 0x0(r29)
  li        r5, 0x1
  lwzu      r12, 0x4(r3)
  lbz       r0, 0x55(r1)
  lwz       r12, 0x34(r12)
  lbz       r4, 0x54(r1)
  rlwinm    r0,r0,16,0,15
  lbz       r6, 0x56(r1)
  mtlr      r12
  rlwimi    r0,r4,24,0,7
  lbz       r7, 0x57(r1)
  rlwimi    r0,r6,8,16,23
  or        r4, r7, r0
  blrl      
  lhz       r0, 0x8(r3)
  cmplwi    r0, 0x12
  bne-      .loc_0x120
  lwz       r5, 0x8(r29)
  li        r4, 0
  stwx      r3, r5, r31
  lwz       r3, 0x8(r29)
  lwzx      r3, r3, r31
  stb       r4, 0xF0(r3)
  lwz       r3, 0x8(r29)
  lwzx      r3, r3, r31
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x8(r29)
  lwzx      r5, r3, r31
  lha       r3, 0x18(r5)
  lha       r0, 0x1C(r5)
  lha       r4, 0x1A(r5)
  sub       r0, r0, r3
  lha       r3, 0x1E(r5)
  srawi     r0, r0, 0x1
  sub       r4, r3, r4
  extsh     r3, r0
  srawi     r0, r4, 0x1
  sth       r3, 0xB8(r5)
  extsh     r0, r0
  sth       r0, 0xBA(r5)

.loc_0x120:
  addi      r30, r30, 0x1
  cmpwi     r30, 0xB
  addi      r31, r31, 0x4
  blt+      .loc_0x64
  lwz       r5, 0x0(r29)
  lis       r3, 0x6761
  addi      r4, r3, 0x7468
  lwz       r12, 0x4(r5)
  addi      r3, r5, 0x4
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lhz       r0, 0x8(r3)
  cmplwi    r0, 0x12
  bne-      .loc_0x178
  stw       r3, 0x4(r29)
  li        r4, 0
  lwz       r3, 0x4(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)

.loc_0x178:
  lfs       f0, -0x40A0(r2)
  li        r0, 0x7F
  addi      r3, r29, 0
  stfs      f0, 0x10(r29)
  lfs       f0, -0x409C(r2)
  stfs      f0, 0x14(r29)
  stb       r0, 0x24(r29)
  lfs       f1, -0x4098(r2)
  lfs       f2, -0x4094(r2)
  lfs       f3, -0x4090(r2)
  bl        .loc_0x1F8
  li        r5, 0xFF
  stb       r5, 0x25(r29)
  li        r0, 0x99
  li        r4, 0
  stb       r0, 0x26(r29)
  li        r0, 0x1
  addi      r3, r29, 0
  stb       r4, 0x27(r29)
  stb       r5, 0x28(r29)
  stb       r5, 0x29(r29)
  stb       r5, 0x2A(r29)
  stb       r5, 0x2B(r29)
  stb       r5, 0x2C(r29)
  stb       r0, 0x2D(r29)
  lwz       r0, 0x74(r1)
  lwz       r31, 0x6C(r1)
  lwz       r30, 0x68(r1)
  lwz       r29, 0x64(r1)
  addi      r1, r1, 0x70
  mtlr      r0
  blr       

.loc_0x1F8:
*/
}

/*
 * --INFO--
 * Address:	801E7CA8
 * Size:	000010
 */
void zen::DrawCountDown::setRate(float, float, float)
{
/*
.loc_0x0:
  stfs      f1, 0x18(r3)
  stfs      f2, 0x1C(r3)
  stfs      f3, 0x20(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801E7CB8
 * Size:	0001A8
 */
void zen::DrawCountDown::init(float, float, float *)
{
/*
.loc_0x0:
  stw       r4, 0x30(r3)
  li        r0, 0
  li        r6, 0x7F
  stfs      f1, 0x10(r3)
  li        r5, 0x1
  li        r4, 0x8
  stfs      f2, 0x14(r3)
  stw       r0, 0xC(r3)
  stb       r6, 0x24(r3)
  lfs       f0, -0x4098(r2)
  stfs      f0, 0x18(r3)
  lfs       f0, -0x4094(r2)
  stfs      f0, 0x1C(r3)
  lfs       f0, -0x4090(r2)
  stfs      f0, 0x20(r3)
  stb       r5, 0x2D(r3)
  lwz       r5, 0x8(r3)
  lwz       r5, 0x0(r5)
  stb       r0, 0xF0(r5)
  lwz       r5, 0x8(r3)
  lwz       r6, 0x0(r5)
  lbz       r5, 0xC(r6)
  rlwimi    r5,r0,7,24,24
  stb       r5, 0xC(r6)
  lwz       r5, 0x8(r3)
  lwz       r5, 0x4(r5)
  stb       r0, 0xF0(r5)
  lwz       r5, 0x8(r3)
  lwz       r6, 0x4(r5)
  lbz       r5, 0xC(r6)
  rlwimi    r5,r0,7,24,24
  stb       r5, 0xC(r6)
  lwz       r5, 0x8(r3)
  lwz       r5, 0x8(r5)
  stb       r0, 0xF0(r5)
  lwz       r5, 0x8(r3)
  lwz       r6, 0x8(r5)
  lbz       r5, 0xC(r6)
  rlwimi    r5,r0,7,24,24
  stb       r5, 0xC(r6)
  lwz       r5, 0x8(r3)
  lwz       r5, 0xC(r5)
  stb       r0, 0xF0(r5)
  lwz       r5, 0x8(r3)
  lwz       r6, 0xC(r5)
  lbz       r5, 0xC(r6)
  rlwimi    r5,r0,7,24,24
  stb       r5, 0xC(r6)
  lwz       r5, 0x8(r3)
  lwz       r5, 0x10(r5)
  stb       r0, 0xF0(r5)
  lwz       r5, 0x8(r3)
  lwz       r6, 0x10(r5)
  lbz       r5, 0xC(r6)
  rlwimi    r5,r0,7,24,24
  stb       r5, 0xC(r6)
  lwz       r5, 0x8(r3)
  lwz       r5, 0x14(r5)
  stb       r0, 0xF0(r5)
  lwz       r5, 0x8(r3)
  lwz       r6, 0x14(r5)
  lbz       r5, 0xC(r6)
  rlwimi    r5,r0,7,24,24
  stb       r5, 0xC(r6)
  lwz       r5, 0x8(r3)
  lwz       r5, 0x18(r5)
  stb       r0, 0xF0(r5)
  lwz       r5, 0x8(r3)
  lwz       r6, 0x18(r5)
  lbz       r5, 0xC(r6)
  rlwimi    r5,r0,7,24,24
  stb       r5, 0xC(r6)
  lwz       r5, 0x8(r3)
  lwz       r5, 0x1C(r5)
  stb       r0, 0xF0(r5)
  lwz       r5, 0x8(r3)
  lwz       r6, 0x1C(r5)
  lbz       r5, 0xC(r6)
  rlwimi    r5,r0,7,24,24
  stb       r5, 0xC(r6)
  b         .loc_0x19C

.loc_0x144:
  subfic    r5, r4, 0xB
  cmpwi     r4, 0xB
  mtctr     r5
  bge-      .loc_0x17C

.loc_0x154:
  lwz       r4, 0x8(r3)
  lwzx      r4, r4, r6
  stb       r0, 0xF0(r4)
  lwz       r4, 0x8(r3)
  lwzx      r5, r4, r6
  addi      r6, r6, 0x4
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  bdnz+     .loc_0x154

.loc_0x17C:
  lwz       r5, 0x4(r3)
  li        r6, 0
  li        r0, -0x1
  lbz       r4, 0xC(r5)
  rlwimi    r4,r6,7,24,24
  stb       r4, 0xC(r5)
  stw       r0, 0x34(r3)
  blr       

.loc_0x19C:
  rlwinm    r6,r4,2,0,29
  b         .loc_0x144
  blr
*/
}

/*
 * --INFO--
 * Address:	801E7E60
 * Size:	000A70
 */
void zen::DrawCountDown::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x160(r1)
  stfd      f31, 0x158(r1)
  stfd      f30, 0x150(r1)
  stw       r31, 0x14C(r1)
  stw       r30, 0x148(r1)
  stw       r29, 0x144(r1)
  mr        r29, r3
  lwz       r3, 0x30(r3)
  cmplwi    r3, 0
  beq-      .loc_0x38
  lfs       f0, 0x0(r3)
  b         .loc_0x44

.loc_0x38:
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lfs       f0, 0x2F0(r3)

.loc_0x44:
  lfs       f2, 0x10(r29)
  fcmpo     cr0, f0, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x944
  lfs       f3, 0x14(r29)
  fcmpo     cr0, f0, f3
  bge-      .loc_0x944
  fsubs     f1, f0, f2
  lfs       f5, -0x408C(r2)
  fsubs     f0, f3, f2
  lis       r3, 0x4330
  lfd       f4, -0x4068(r2)
  fdivs     f6, f1, f0
  lfs       f1, -0x4084(r2)
  lfs       f2, -0x4088(r2)
  lwz       r0, 0x34(r29)
  fdivs     f0, f6, f5
  fctiwz    f0, f0
  stfd      f0, 0x138(r1)
  lwz       r30, 0x13C(r1)
  xoris     r4, r30, 0x8000
  stw       r4, 0x134(r1)
  subfic    r31, r30, 0xB
  cmpw      r31, r0
  stw       r3, 0x130(r1)
  lfd       f0, 0x130(r1)
  stw       r4, 0x12C(r1)
  fsubs     f0, f0, f4
  stw       r3, 0x128(r1)
  fmuls     f3, f5, f0
  lfd       f0, 0x128(r1)
  fsubs     f0, f0, f4
  fsubs     f3, f6, f3
  fmuls     f0, f1, f0
  fdivs     f30, f3, f5
  fadds     f31, f2, f0
  beq-      .loc_0x104
  cmpwi     r31, 0x2
  bne-      .loc_0x104
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r3, 0x1E8(r3)
  li        r4, 0xF
  li        r5, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x104:
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r0, 0x2B4(r3)
  cmpwi     r0, 0
  bne-      .loc_0x130
  lwz       r3, 0x4(r29)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x144

.loc_0x130:
  lwz       r3, 0x4(r29)
  li        r4, 0
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)

.loc_0x144:
  lwz       r4, 0xC(r29)
  cmplwi    r4, 0
  beq-      .loc_0x160
  lbz       r0, 0xC(r4)
  li        r3, 0
  rlwimi    r0,r3,7,24,24
  stb       r0, 0xC(r4)

.loc_0x160:
  lwz       r3, 0x8(r29)
  rlwinm    r0,r30,2,0,29
  li        r4, 0x1
  lwzx      r0, r3, r0
  stw       r0, 0xC(r29)
  lwz       r3, 0xC(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lfs       f1, 0x18(r29)
  fcmpo     cr0, f30, f1
  bge-      .loc_0x1D4
  lwz       r3, 0xC(r29)
  li        r0, 0
  cmpwi     r30, 0
  stb       r0, 0xF0(r3)
  ble-      .loc_0x1C0
  lwz       r3, 0x4(r29)
  lwz       r0, 0x25(r29)
  stw       r0, 0x108(r3)
  lbz       r0, 0x24(r29)
  lwz       r3, 0x4(r29)
  stb       r0, 0xF0(r3)
  b         .loc_0x1C8

.loc_0x1C0:
  lwz       r3, 0x4(r29)
  stb       r0, 0xF0(r3)

.loc_0x1C8:
  li        r0, 0x1
  stb       r0, 0x2D(r29)
  b         .loc_0x93C

.loc_0x1D4:
  lfs       f4, 0x1C(r29)
  fadds     f0, f4, f1
  fcmpo     cr0, f30, f0
  bge-      .loc_0x584
  fsubs     f1, f30, f1
  lfs       f2, -0x407C(r2)
  lfs       f3, -0x4080(r2)
  lfs       f0, -0x4078(r2)
  fmuls     f1, f2, f1
  fdivs     f1, f1, f4
  fmuls     f1, f3, f1
  fdivs     f1, f1, f0
  bl        0x33C84
  lbz       r3, 0x24(r29)
  lis       r0, 0x4330
  lfs       f0, -0x4074(r2)
  stw       r3, 0x12C(r1)
  lfd       f4, -0x4060(r2)
  fsubs     f0, f0, f1
  stw       r0, 0x128(r1)
  lfs       f2, -0x4070(r2)
  lfd       f3, 0x128(r1)
  fsubs     f3, f3, f4
  fmuls     f3, f3, f1
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x24C
  lfs       f2, -0x406C(r2)
  fadds     f2, f2, f3
  b         .loc_0x254

.loc_0x24C:
  lfs       f2, -0x406C(r2)
  fsubs     f2, f3, f2

.loc_0x254:
  fctiwz    f2, f2
  lwz       r3, 0xC(r29)
  fmuls     f3, f31, f1
  lis       r0, 0x4330
  stfd      f2, 0x128(r1)
  lwz       r4, 0x12C(r1)
  stb       r4, 0xF0(r3)
  lwz       r3, 0xC(r29)
  stfs      f3, 0xC0(r3)
  stfs      f3, 0xC4(r3)
  lfs       f2, -0x4074(r2)
  stfs      f2, 0xC8(r3)
  lbz       r3, 0x27(r29)
  lbz       r4, 0x2B(r29)
  stw       r3, 0x13C(r1)
  lfd       f5, -0x4060(r2)
  stw       r4, 0x134(r1)
  lfs       f2, -0x4070(r2)
  stw       r0, 0x130(r1)
  stw       r0, 0x138(r1)
  lfd       f4, 0x130(r1)
  lfd       f3, 0x138(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x304
  stw       r4, 0x12C(r1)
  lfs       f4, -0x406C(r2)
  stw       r3, 0x134(r1)
  stw       r0, 0x128(r1)
  stw       r0, 0x130(r1)
  lfd       f3, 0x128(r1)
  lfd       f2, 0x130(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f3, f3, f1
  fmuls     f2, f2, f0
  fadds     f2, f3, f2
  fadds     f2, f4, f2
  b         .loc_0x338

.loc_0x304:
  stw       r4, 0x12C(r1)
  lfs       f2, -0x406C(r2)
  stw       r3, 0x134(r1)
  stw       r0, 0x128(r1)
  stw       r0, 0x130(r1)
  lfd       f4, 0x128(r1)
  lfd       f3, 0x130(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fsubs     f2, f3, f2

.loc_0x338:
  lbz       r5, 0x26(r29)
  fctiwz    f6, f2
  lbz       r6, 0x2A(r29)
  lis       r0, 0x4330
  stw       r5, 0x13C(r1)
  lfd       f5, -0x4060(r2)
  stw       r6, 0x134(r1)
  lfs       f2, -0x4070(r2)
  stw       r0, 0x130(r1)
  stw       r0, 0x138(r1)
  lfd       f4, 0x130(r1)
  lfd       f3, 0x138(r1)
  fsubs     f4, f4, f5
  stfd      f6, 0x128(r1)
  fsubs     f3, f3, f5
  lwz       r3, 0x12C(r1)
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  rlwinm    r4,r3,0,24,31
  fadds     f3, f4, f3
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x3CC
  stw       r6, 0x12C(r1)
  lfs       f4, -0x406C(r2)
  stw       r5, 0x134(r1)
  stw       r0, 0x128(r1)
  stw       r0, 0x130(r1)
  lfd       f3, 0x128(r1)
  lfd       f2, 0x130(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f3, f3, f1
  fmuls     f2, f2, f0
  fadds     f2, f3, f2
  fadds     f2, f4, f2
  b         .loc_0x400

.loc_0x3CC:
  stw       r6, 0x12C(r1)
  lfs       f2, -0x406C(r2)
  stw       r5, 0x134(r1)
  stw       r0, 0x128(r1)
  stw       r0, 0x130(r1)
  lfd       f4, 0x128(r1)
  lfd       f3, 0x130(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fsubs     f2, f3, f2

.loc_0x400:
  lbz       r6, 0x25(r29)
  fctiwz    f6, f2
  lbz       r7, 0x29(r29)
  lis       r0, 0x4330
  stw       r6, 0x13C(r1)
  lfd       f5, -0x4060(r2)
  stw       r7, 0x134(r1)
  lfs       f2, -0x4070(r2)
  stw       r0, 0x130(r1)
  stw       r0, 0x138(r1)
  lfd       f4, 0x130(r1)
  lfd       f3, 0x138(r1)
  fsubs     f4, f4, f5
  stfd      f6, 0x128(r1)
  fsubs     f3, f3, f5
  lwz       r3, 0x12C(r1)
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  rlwinm    r5,r3,0,24,31
  fadds     f3, f4, f3
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x494
  stw       r7, 0x12C(r1)
  lfs       f4, -0x406C(r2)
  stw       r6, 0x134(r1)
  stw       r0, 0x128(r1)
  stw       r0, 0x130(r1)
  lfd       f3, 0x128(r1)
  lfd       f2, 0x130(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f3, f3, f1
  fmuls     f0, f2, f0
  fadds     f0, f3, f0
  fadds     f0, f4, f0
  b         .loc_0x4C8

.loc_0x494:
  stw       r7, 0x12C(r1)
  lfs       f2, -0x406C(r2)
  stw       r6, 0x134(r1)
  stw       r0, 0x128(r1)
  stw       r0, 0x130(r1)
  lfd       f4, 0x128(r1)
  lfd       f3, 0x130(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f0, f3, f0
  fadds     f0, f4, f0
  fsubs     f0, f0, f2

.loc_0x4C8:
  fctiwz    f0, f0
  li        r0, 0xFF
  cmpwi     r30, 0
  stfd      f0, 0x128(r1)
  lwz       r3, 0x12C(r1)
  stb       r3, 0x114(r1)
  stb       r5, 0x115(r1)
  stb       r4, 0x116(r1)
  stb       r0, 0x117(r1)
  lwz       r3, 0x4(r29)
  lwz       r0, 0x114(r1)
  stw       r0, 0x108(r3)
  ble-      .loc_0x50C
  lbz       r0, 0x24(r29)
  lwz       r3, 0x4(r29)
  stb       r0, 0xF0(r3)
  b         .loc_0x564

.loc_0x50C:
  lbz       r3, 0x24(r29)
  lis       r0, 0x4330
  lfd       f3, -0x4060(r2)
  stw       r3, 0x12C(r1)
  lfs       f0, -0x4070(r2)
  stw       r0, 0x128(r1)
  lfd       f2, 0x128(r1)
  fsubs     f2, f2, f3
  fmuls     f1, f2, f1
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x548
  lfs       f0, -0x406C(r2)
  fadds     f0, f0, f1
  b         .loc_0x550

.loc_0x548:
  lfs       f0, -0x406C(r2)
  fsubs     f0, f1, f0

.loc_0x550:
  fctiwz    f0, f0
  lwz       r3, 0x4(r29)
  stfd      f0, 0x128(r1)
  lwz       r0, 0x12C(r1)
  stb       r0, 0xF0(r3)

.loc_0x564:
  lbz       r0, 0x2D(r29)
  cmplwi    r0, 0
  beq-      .loc_0x93C
  li        r3, 0x115
  bl        -0x143060
  li        r0, 0
  stb       r0, 0x2D(r29)
  b         .loc_0x93C

.loc_0x584:
  lfs       f1, -0x4074(r2)
  lfs       f2, 0x20(r29)
  fsubs     f0, f1, f2
  fcmpo     cr0, f30, f0
  ble-      .loc_0x908
  fsubs     f0, f30, f0
  lbz       r3, 0x24(r29)
  lis       r0, 0x4330
  lfd       f4, -0x4060(r2)
  stw       r3, 0x12C(r1)
  fdivs     f0, f0, f2
  stw       r0, 0x128(r1)
  lfs       f2, -0x4070(r2)
  lfd       f3, 0x128(r1)
  fsubs     f1, f1, f0
  fsubs     f3, f3, f4
  fmuls     f3, f3, f1
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x5E0
  lfs       f2, -0x406C(r2)
  fadds     f2, f2, f3
  b         .loc_0x5E8

.loc_0x5E0:
  lfs       f2, -0x406C(r2)
  fsubs     f2, f3, f2

.loc_0x5E8:
  fctiwz    f2, f2
  lwz       r3, 0xC(r29)
  lis       r0, 0x4330
  stfd      f2, 0x128(r1)
  lwz       r4, 0x12C(r1)
  stb       r4, 0xF0(r3)
  lfs       f6, -0x406C(r2)
  lfs       f3, -0x4074(r2)
  fmuls     f2, f6, f0
  lwz       r3, 0xC(r29)
  fadds     f2, f3, f2
  fmuls     f2, f31, f2
  stfs      f2, 0xC0(r3)
  stfs      f2, 0xC4(r3)
  stfs      f3, 0xC8(r3)
  lbz       r3, 0x27(r29)
  lbz       r4, 0x2B(r29)
  stw       r3, 0x13C(r1)
  lfd       f5, -0x4060(r2)
  stw       r4, 0x134(r1)
  lfs       f2, -0x4070(r2)
  stw       r0, 0x130(r1)
  stw       r0, 0x138(r1)
  lfd       f4, 0x130(r1)
  lfd       f3, 0x138(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x6A0
  stw       r4, 0x12C(r1)
  stw       r3, 0x134(r1)
  stw       r0, 0x128(r1)
  stw       r0, 0x130(r1)
  lfd       f3, 0x128(r1)
  lfd       f2, 0x130(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f3, f3, f1
  fmuls     f2, f2, f0
  fadds     f2, f3, f2
  fadds     f2, f6, f2
  b         .loc_0x6D0

.loc_0x6A0:
  stw       r4, 0x12C(r1)
  stw       r3, 0x134(r1)
  stw       r0, 0x128(r1)
  stw       r0, 0x130(r1)
  lfd       f3, 0x128(r1)
  lfd       f2, 0x130(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f3, f3, f1
  fmuls     f2, f2, f0
  fadds     f2, f3, f2
  fsubs     f2, f2, f6

.loc_0x6D0:
  lbz       r5, 0x26(r29)
  fctiwz    f6, f2
  lbz       r6, 0x2A(r29)
  lis       r0, 0x4330
  stw       r5, 0x13C(r1)
  lfd       f5, -0x4060(r2)
  stw       r6, 0x134(r1)
  lfs       f2, -0x4070(r2)
  stw       r0, 0x130(r1)
  stw       r0, 0x138(r1)
  lfd       f4, 0x130(r1)
  lfd       f3, 0x138(r1)
  fsubs     f4, f4, f5
  stfd      f6, 0x128(r1)
  fsubs     f3, f3, f5
  lwz       r3, 0x12C(r1)
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  rlwinm    r4,r3,0,24,31
  fadds     f3, f4, f3
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x764
  stw       r6, 0x12C(r1)
  lfs       f4, -0x406C(r2)
  stw       r5, 0x134(r1)
  stw       r0, 0x128(r1)
  stw       r0, 0x130(r1)
  lfd       f3, 0x128(r1)
  lfd       f2, 0x130(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f3, f3, f1
  fmuls     f2, f2, f0
  fadds     f2, f3, f2
  fadds     f2, f4, f2
  b         .loc_0x798

.loc_0x764:
  stw       r6, 0x12C(r1)
  lfs       f2, -0x406C(r2)
  stw       r5, 0x134(r1)
  stw       r0, 0x128(r1)
  stw       r0, 0x130(r1)
  lfd       f4, 0x128(r1)
  lfd       f3, 0x130(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fsubs     f2, f3, f2

.loc_0x798:
  lbz       r6, 0x25(r29)
  fctiwz    f6, f2
  lbz       r7, 0x29(r29)
  lis       r0, 0x4330
  stw       r6, 0x13C(r1)
  lfd       f5, -0x4060(r2)
  stw       r7, 0x134(r1)
  lfs       f2, -0x4070(r2)
  stw       r0, 0x130(r1)
  stw       r0, 0x138(r1)
  lfd       f4, 0x130(r1)
  lfd       f3, 0x138(r1)
  fsubs     f4, f4, f5
  stfd      f6, 0x128(r1)
  fsubs     f3, f3, f5
  lwz       r3, 0x12C(r1)
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  rlwinm    r5,r3,0,24,31
  fadds     f3, f4, f3
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x82C
  stw       r7, 0x12C(r1)
  lfs       f4, -0x406C(r2)
  stw       r6, 0x134(r1)
  stw       r0, 0x128(r1)
  stw       r0, 0x130(r1)
  lfd       f3, 0x128(r1)
  lfd       f2, 0x130(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f3, f3, f1
  fmuls     f1, f2, f0
  fadds     f1, f3, f1
  fadds     f1, f4, f1
  b         .loc_0x860

.loc_0x82C:
  stw       r7, 0x12C(r1)
  lfs       f2, -0x406C(r2)
  stw       r6, 0x134(r1)
  stw       r0, 0x128(r1)
  stw       r0, 0x130(r1)
  lfd       f4, 0x128(r1)
  lfd       f3, 0x130(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f1, f3, f0
  fadds     f1, f4, f1
  fsubs     f1, f1, f2

.loc_0x860:
  fctiwz    f1, f1
  li        r0, 0xFF
  cmpwi     r30, 0xA
  stfd      f1, 0x128(r1)
  lwz       r3, 0x12C(r1)
  stb       r3, 0x10C(r1)
  stb       r5, 0x10D(r1)
  stb       r4, 0x10E(r1)
  stb       r0, 0x10F(r1)
  lwz       r3, 0x4(r29)
  lwz       r0, 0x10C(r1)
  stw       r0, 0x108(r3)
  bne-      .loc_0x8F8
  lbz       r3, 0x24(r29)
  lis       r0, 0x4330
  lfs       f1, -0x4074(r2)
  stw       r3, 0x12C(r1)
  lfd       f3, -0x4060(r2)
  fsubs     f1, f1, f0
  stw       r0, 0x128(r1)
  lfs       f0, -0x4070(r2)
  lfd       f2, 0x128(r1)
  fsubs     f2, f2, f3
  fmuls     f1, f2, f1
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x8D8
  lfs       f0, -0x406C(r2)
  fadds     f0, f0, f1
  b         .loc_0x8E0

.loc_0x8D8:
  lfs       f0, -0x406C(r2)
  fsubs     f0, f1, f0

.loc_0x8E0:
  fctiwz    f0, f0
  lwz       r3, 0x4(r29)
  stfd      f0, 0x128(r1)
  lwz       r0, 0x12C(r1)
  stb       r0, 0xF0(r3)
  b         .loc_0x93C

.loc_0x8F8:
  lbz       r0, 0x24(r29)
  lwz       r3, 0x4(r29)
  stb       r0, 0xF0(r3)
  b         .loc_0x93C

.loc_0x908:
  lbz       r0, 0x24(r29)
  lwz       r3, 0xC(r29)
  stb       r0, 0xF0(r3)
  lwz       r3, 0xC(r29)
  stfs      f31, 0xC0(r3)
  stfs      f31, 0xC4(r3)
  stfs      f31, 0xC8(r3)
  lwz       r3, 0x4(r29)
  lwz       r0, 0x29(r29)
  stw       r0, 0x108(r3)
  lbz       r0, 0x24(r29)
  lwz       r3, 0x4(r29)
  stb       r0, 0xF0(r3)

.loc_0x93C:
  stw       r31, 0x34(r29)
  b         .loc_0xA2C

.loc_0x944:
  lwz       r5, 0x4(r29)
  li        r0, 0
  li        r3, 0x8
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r4, 0x8(r29)
  lwz       r5, 0x0(r4)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r4, 0x8(r29)
  lwz       r5, 0x4(r4)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r4, 0x8(r29)
  lwz       r5, 0x8(r4)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r4, 0x8(r29)
  lwz       r5, 0xC(r4)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r4, 0x8(r29)
  lwz       r5, 0x10(r4)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r4, 0x8(r29)
  lwz       r5, 0x14(r4)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r4, 0x8(r29)
  lwz       r5, 0x18(r4)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r4, 0x8(r29)
  lwz       r5, 0x1C(r4)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  b         .loc_0xA44

.loc_0xA00:
  subfic    r4, r3, 0xB
  cmpwi     r3, 0xB
  mtctr     r4
  bge-      .loc_0xA2C

.loc_0xA10:
  lwz       r3, 0x8(r29)
  lwzx      r4, r3, r5
  addi      r5, r5, 0x4
  lbz       r3, 0xC(r4)
  rlwimi    r3,r0,7,24,24
  stb       r3, 0xC(r4)
  bdnz+     .loc_0xA10

.loc_0xA2C:
  lwz       r3, 0x0(r29)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0xA4C

.loc_0xA44:
  rlwinm    r5,r3,2,0,29
  b         .loc_0xA00

.loc_0xA4C:
  lwz       r0, 0x164(r1)
  lfd       f31, 0x158(r1)
  lfd       f30, 0x150(r1)
  lwz       r31, 0x14C(r1)
  lwz       r30, 0x148(r1)
  lwz       r29, 0x144(r1)
  addi      r1, r1, 0x160
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801E88D0
 * Size:	000030
 */
void zen::DrawCountDown::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x0(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}