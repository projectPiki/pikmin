

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
 * Address:	8019719C
 * Size:	00010C
 */
void zen::ogScrFileSelectMgr::setOperateMode_Copy()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x5
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  addi      r30, r3, 0
  bl        -0xE104
  lha       r0, 0x134(r30)
  li        r3, 0
  cmpw      r3, r0
  beq-      .loc_0x38
  stw       r3, 0x119C(r30)
  b         .loc_0x5C

.loc_0x38:
  li        r3, 0x1
  cmpw      r3, r0
  beq-      .loc_0x4C
  stw       r3, 0x119C(r30)
  b         .loc_0x5C

.loc_0x4C:
  li        r3, 0x2
  cmpw      r3, r0
  beq-      .loc_0x5C
  stw       r3, 0x119C(r30)

.loc_0x5C:
  lwz       r0, 0x119C(r30)
  lis       r31, 0x7A30
  lwz       r4, 0x2BC(r30)
  addi      r3, r30, 0xA4
  rlwinm    r0,r0,2,0,29
  add       r7, r30, r0
  lwz       r5, 0x448(r30)
  lfs       f1, 0x104(r7)
  addi      r6, r31, 0x306C
  lfs       f2, 0x11C(r7)
  bl        0x43A1C
  lwz       r0, 0x119C(r30)
  addi      r3, r30, 0xD4
  lwz       r4, 0x2BC(r30)
  addi      r6, r31, 0x3072
  rlwinm    r0,r0,2,0,29
  add       r7, r30, r0
  lwz       r5, 0x448(r30)
  lfs       f1, 0x110(r7)
  lfs       f2, 0x128(r7)
  bl        0x439F4
  lwz       r5, 0x448(r30)
  li        r31, 0x1
  addi      r3, r30, 0
  lbz       r0, 0xC(r5)
  rlwimi    r0,r31,7,24,24
  li        r4, 0
  stb       r0, 0xC(r5)
  bl        -0xF7A4
  stb       r31, 0x11A0(r30)
  addi      r3, r30, 0xA4
  lfs       f1, -0x4D88(r2)
  lfs       f2, -0x4D84(r2)
  bl        0x4399C
  lfs       f1, -0x4D88(r2)
  addi      r3, r30, 0xD4
  lfs       f2, -0x4D84(r2)
  bl        0x4398C
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
 * Address:	........
 * Size:	00006C
 */
void zen::ogScrFileSelectMgr::MoveCpyCursor(int, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801972A8
 * Size:	0003A8
 */
void zen::ogScrFileSelectMgr::CopyEffectStart()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x2A
  stw       r0, 0x4(r1)
  li        r6, 0
  li        r7, 0
  stwu      r1, -0x120(r1)
  stw       r31, 0x11C(r1)
  lis       r31, 0x4330
  addi      r5, r1, 0xC0
  stw       r30, 0x118(r1)
  addi      r30, r3, 0
  stw       r29, 0x114(r1)
  lfs       f5, -0x4D80(r2)
  stfs      f5, 0xC8(r1)
  stfs      f5, 0xC4(r1)
  stfs      f5, 0xC0(r1)
  stfs      f5, 0xBC(r1)
  stfs      f5, 0xB8(r1)
  lha       r3, 0x134(r3)
  lwz       r0, 0x119C(r30)
  rlwinm    r3,r3,2,0,29
  lfs       f1, 0xE18(r13)
  add       r8, r30, r3
  lfs       f0, 0xE1C(r13)
  rlwinm    r0,r0,2,0,29
  lwz       r9, 0x3B0(r8)
  add       r3, r30, r0
  lwz       r10, 0x3D4(r3)
  stfs      f1, 0xC0(r1)
  stfs      f0, 0xC4(r1)
  lfs       f0, 0xE20(r13)
  stfs      f0, 0xC8(r1)
  lha       r8, 0x18(r9)
  lha       r0, 0x1C(r9)
  xoris     r3, r8, 0x8000
  lfd       f4, -0x4D70(r2)
  sub       r0, r0, r8
  stw       r3, 0x10C(r1)
  xoris     r0, r0, 0x8000
  lfs       f3, -0x4D7C(r2)
  stw       r0, 0x104(r1)
  lfs       f2, -0x4D78(r2)
  stw       r31, 0x100(r1)
  lfd       f0, 0x100(r1)
  stw       r31, 0x108(r1)
  fsubs     f0, f0, f4
  lfd       f1, 0x108(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  stfs      f0, 0xC0(r1)
  lha       r8, 0x1A(r9)
  lha       r0, 0x1E(r9)
  xoris     r3, r8, 0x8000
  sub       r0, r0, r8
  stw       r3, 0xFC(r1)
  xoris     r0, r0, 0x8000
  stw       r0, 0xF4(r1)
  stw       r31, 0xF0(r1)
  lfd       f0, 0xF0(r1)
  stw       r31, 0xF8(r1)
  fsubs     f0, f0, f4
  lfd       f1, 0xF8(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  fsubs     f0, f2, f0
  stfs      f0, 0xC4(r1)
  stfs      f5, 0x98(r1)
  stfs      f5, 0x94(r1)
  stfs      f5, 0x90(r1)
  lfs       f0, 0x84(r10)
  stfs      f0, 0x90(r1)
  lfs       f0, 0x94(r10)
  stfs      f0, 0x94(r1)
  lfs       f0, 0xA4(r10)
  stfs      f0, 0x98(r1)
  lwz       r0, 0x90(r1)
  lwz       r3, 0x94(r1)
  stw       r0, 0xB4(r1)
  lwz       r0, 0x98(r1)
  stw       r3, 0xB8(r1)
  stw       r0, 0xBC(r1)
  lfs       f0, 0xB8(r1)
  fsubs     f0, f2, f0
  stfs      f0, 0xB8(r1)
  lwz       r3, 0x0(r30)
  bl        0x52738
  stw       r3, 0x4(r30)
  lwz       r29, 0x4(r30)
  mr        r3, r29
  bl        -0x827A4
  lfs       f1, 0xBC(r1)
  addi      r6, r1, 0x68
  lfs       f0, 0x8(r3)
  addi      r5, r1, 0x64
  addi      r4, r1, 0x60
  fsubs     f0, f1, f0
  lfs       f1, 0xB4(r1)
  stfs      f0, 0x68(r1)
  lfs       f2, 0xB8(r1)
  lfs       f0, 0x4(r3)
  fsubs     f0, f2, f0
  stfs      f0, 0x64(r1)
  lfs       f0, 0x0(r3)
  addi      r3, r1, 0x84
  fsubs     f0, f1, f0
  stfs      f0, 0x60(r1)
  bl        -0x16033C
  lfs       f0, 0x84(r1)
  addi      r5, r1, 0xC0
  li        r4, 0x29
  stfs      f0, 0x170(r29)
  li        r6, 0
  li        r7, 0
  lfs       f0, 0x88(r1)
  stfs      f0, 0x174(r29)
  lfs       f0, 0x8C(r1)
  stfs      f0, 0x178(r29)
  lfs       f0, -0x4D74(r2)
  stfs      f0, 0x17C(r29)
  lwz       r0, 0x84(r29)
  oris      r0, r0, 0x10
  stw       r0, 0x84(r29)
  lha       r3, 0x134(r30)
  lwz       r0, 0x119C(r30)
  rlwinm    r3,r3,2,0,29
  lfs       f1, 0xE24(r13)
  add       r8, r30, r3
  lfs       f0, 0xE28(r13)
  rlwinm    r0,r0,2,0,29
  lwz       r9, 0x3BC(r8)
  add       r3, r30, r0
  lwz       r10, 0x3E0(r3)
  stfs      f1, 0xC0(r1)
  stfs      f0, 0xC4(r1)
  lfs       f0, 0xE2C(r13)
  stfs      f0, 0xC8(r1)
  lha       r8, 0x18(r9)
  lha       r0, 0x1C(r9)
  xoris     r3, r8, 0x8000
  lfd       f4, -0x4D70(r2)
  sub       r0, r0, r8
  stw       r3, 0xEC(r1)
  xoris     r0, r0, 0x8000
  lfs       f3, -0x4D7C(r2)
  stw       r0, 0xE4(r1)
  lfs       f2, -0x4D78(r2)
  stw       r31, 0xE0(r1)
  lfd       f0, 0xE0(r1)
  stw       r31, 0xE8(r1)
  fsubs     f0, f0, f4
  lfd       f1, 0xE8(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  stfs      f0, 0xC0(r1)
  lha       r8, 0x1A(r9)
  lha       r0, 0x1E(r9)
  xoris     r3, r8, 0x8000
  sub       r0, r0, r8
  stw       r3, 0xDC(r1)
  xoris     r0, r0, 0x8000
  stw       r0, 0xD4(r1)
  stw       r31, 0xD0(r1)
  lfd       f0, 0xD0(r1)
  stw       r31, 0xD8(r1)
  fsubs     f0, f0, f4
  lfd       f1, 0xD8(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  fsubs     f0, f2, f0
  stfs      f0, 0xC4(r1)
  lfs       f0, -0x4D80(r2)
  stfs      f0, 0x80(r1)
  stfs      f0, 0x7C(r1)
  stfs      f0, 0x78(r1)
  lfs       f0, 0x84(r10)
  stfs      f0, 0x78(r1)
  lfs       f0, 0x94(r10)
  stfs      f0, 0x7C(r1)
  lfs       f0, 0xA4(r10)
  stfs      f0, 0x80(r1)
  lwz       r0, 0x78(r1)
  lwz       r3, 0x7C(r1)
  stw       r0, 0xB4(r1)
  lwz       r0, 0x80(r1)
  stw       r3, 0xB8(r1)
  stw       r0, 0xBC(r1)
  lfs       f0, 0xB8(r1)
  fsubs     f0, f2, f0
  stfs      f0, 0xB8(r1)
  lwz       r3, 0x0(r30)
  bl        0x5258C
  stw       r3, 0x8(r30)
  lwz       r29, 0x8(r30)
  mr        r3, r29
  bl        -0x82950
  lfs       f1, 0xBC(r1)
  addi      r6, r1, 0x5C
  lfs       f0, 0x8(r3)
  addi      r5, r1, 0x58
  addi      r4, r1, 0x54
  fsubs     f0, f1, f0
  lfs       f1, 0xB4(r1)
  stfs      f0, 0x5C(r1)
  lfs       f2, 0xB8(r1)
  lfs       f0, 0x4(r3)
  fsubs     f0, f2, f0
  stfs      f0, 0x58(r1)
  lfs       f0, 0x0(r3)
  addi      r3, r1, 0x6C
  fsubs     f0, f1, f0
  stfs      f0, 0x54(r1)
  bl        -0x1604E8
  lfs       f0, 0x6C(r1)
  stfs      f0, 0x170(r29)
  lfs       f0, 0x70(r1)
  stfs      f0, 0x174(r29)
  lfs       f0, 0x74(r1)
  stfs      f0, 0x178(r29)
  lfs       f0, -0x4D74(r2)
  stfs      f0, 0x17C(r29)
  lwz       r0, 0x84(r29)
  oris      r0, r0, 0x10
  stw       r0, 0x84(r29)
  lwz       r0, 0x124(r1)
  lwz       r31, 0x11C(r1)
  lwz       r30, 0x118(r1)
  lwz       r29, 0x114(r1)
  addi      r1, r1, 0x120
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80197650
 * Size:	000488
 */
void zen::ogScrFileSelectMgr::OperateCopy(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB8(r1)
  stw       r31, 0xB4(r1)
  mr        r31, r3
  stw       r30, 0xB0(r1)
  stw       r29, 0xAC(r1)
  lbz       r0, 0x1198(r3)
  cmplwi    r0, 0
  beq-      .loc_0x88
  lwz       r3, 0x300(r31)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x118C(r31)
  lfs       f0, 0x28C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x118C(r31)
  lfs       f1, 0x118C(r31)
  lfs       f0, -0x4D80(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x46C
  li        r30, 0
  stb       r30, 0x1198(r31)
  addi      r3, r31, 0
  li        r4, 0
  bl        -0xFA34
  lwz       r3, 0x300(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r30,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x46C

.loc_0x88:
  lbz       r0, 0x1197(r31)
  cmplwi    r0, 0
  beq-      .loc_0x218
  lwz       r3, 0x2F8(r31)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x2CC(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lfs       f1, 0x118C(r31)
  lfs       f0, -0x4D68(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xF4
  fsubs     f1, f1, f0
  lfs       f0, -0x4D60(r2)
  lwz       r3, 0x2CC(r31)
  lfs       f2, -0x4D64(r2)
  fdivs     f0, f1, f0
  lha       r29, 0x1A(r3)
  fmuls     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0xA0(r1)
  lwz       r30, 0xA4(r1)
  b         .loc_0x14C

.loc_0xF4:
  lfs       f2, -0x4D60(r2)
  fcmpo     cr0, f1, f2
  bge-      .loc_0x140
  fsubs     f0, f1, f2
  lwz       r3, 0x2CC(r31)
  lfs       f1, -0x4D64(r2)
  lwz       r12, 0x0(r3)
  fdivs     f0, f0, f2
  lwz       r12, 0x14(r12)
  lha       r29, 0x1A(r3)
  mtlr      r12
  mr        r5, r29
  fmuls     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0xA0(r1)
  lwz       r30, 0xA4(r1)
  mr        r4, r30
  blrl      
  b         .loc_0x14C

.loc_0x140:
  lwz       r3, 0x2CC(r31)
  lha       r30, 0x18(r3)
  lha       r29, 0x1A(r3)

.loc_0x14C:
  lwz       r3, 0x2CC(r31)
  addi      r4, r30, 0
  addi      r5, r29, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x118C(r31)
  lfs       f0, 0x28C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x118C(r31)
  lfs       f1, 0x118C(r31)
  lfs       f0, -0x4D80(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x46C
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r3, r3, 0x24
  bl        -0x123D8C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x46C
  li        r3, 0x129
  bl        -0xF2484
  mr        r3, r31
  bl        -0x10070
  mr        r3, r31
  bl        -0xD420
  li        r4, 0
  stb       r4, 0x1197(r31)
  li        r0, 0x1
  stb       r0, 0x1198(r31)
  lfs       f0, -0x4D88(r2)
  stfs      f0, 0x118C(r31)
  lwz       r3, 0x2F8(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x2CC(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x4(r31)
  lwz       r0, 0x80(r3)
  ori       r0, r0, 0x2
  stw       r0, 0x80(r3)
  lwz       r3, 0x8(r31)
  lwz       r0, 0x80(r3)
  ori       r0, r0, 0x2
  stw       r0, 0x80(r3)
  b         .loc_0x46C

.loc_0x218:
  lbz       r0, 0x11A0(r31)
  cmplwi    r0, 0
  beq-      .loc_0x3AC
  lwz       r3, 0x28(r4)
  rlwinm.   r0,r3,0,18,18
  beq-      .loc_0x248
  li        r3, 0x11D
  bl        -0xF2510
  addi      r3, r31, 0
  li        r4, 0
  bl        -0xFC04
  b         .loc_0x46C

.loc_0x248:
  rlwinm.   r0,r3,0,19,19
  beq-      .loc_0x2CC
  li        r3, 0x111
  bl        -0xF2530
  li        r0, 0
  stb       r0, 0x11A0(r31)
  li        r5, 0x1
  addi      r3, r31, 0xA4
  lwz       r4, 0x2D8(r31)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  lwz       r4, 0x2D0(r31)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  lwz       r5, 0x2D4(r31)
  lwz       r4, 0x2D0(r31)
  lbz       r0, 0xF7(r5)
  stb       r0, 0xF0(r4)
  lfs       f1, -0x4D80(r2)
  lfs       f2, -0x4D84(r2)
  bl        0x43328
  lfs       f1, -0x4D80(r2)
  addi      r3, r31, 0xD4
  lfs       f2, -0x4D84(r2)
  bl        0x43318
  mr        r3, r31
  bl        -0xFD44
  addi      r3, r31, 0
  li        r4, 0x6
  bl        -0xE860
  b         .loc_0x46C

.loc_0x2CC:
  rlwinm.   r0,r3,0,9,9
  beq-      .loc_0x33C
  li        r0, 0x3
  mtctr     r0
  li        r29, 0

.loc_0x2E0:
  lha       r0, 0x134(r31)
  cmpw      r29, r0
  beq-      .loc_0x2FC
  li        r3, 0x112
  bl        -0xF25CC
  stw       r29, 0x119C(r31)
  b         .loc_0x304

.loc_0x2FC:
  addi      r29, r29, 0x1
  bdnz+     .loc_0x2E0

.loc_0x304:
  lwz       r0, 0x119C(r31)
  addi      r3, r31, 0xA4
  lfs       f3, -0x4D84(r2)
  rlwinm    r0,r0,2,0,29
  add       r30, r31, r0
  lfs       f1, 0x104(r30)
  lfs       f2, 0x11C(r30)
  bl        0x43238
  lfs       f1, 0x110(r30)
  addi      r3, r31, 0xD4
  lfs       f2, 0x128(r30)
  lfs       f3, -0x4D84(r2)
  bl        0x43224
  b         .loc_0x46C

.loc_0x33C:
  rlwinm.   r0,r3,0,11,11
  beq-      .loc_0x46C
  li        r0, 0x3
  mtctr     r0
  li        r29, 0x2

.loc_0x350:
  lha       r0, 0x134(r31)
  cmpw      r29, r0
  beq-      .loc_0x36C
  li        r3, 0x112
  bl        -0xF263C
  stw       r29, 0x119C(r31)
  b         .loc_0x374

.loc_0x36C:
  subi      r29, r29, 0x1
  bdnz+     .loc_0x350

.loc_0x374:
  lwz       r0, 0x119C(r31)
  addi      r3, r31, 0xA4
  lfs       f3, -0x4D84(r2)
  rlwinm    r0,r0,2,0,29
  add       r30, r31, r0
  lfs       f1, 0x104(r30)
  lfs       f2, 0x11C(r30)
  bl        0x431C8
  lfs       f1, 0x110(r30)
  addi      r3, r31, 0xD4
  lfs       f2, 0x128(r30)
  lfs       f3, -0x4D84(r2)
  bl        0x431B4
  b         .loc_0x46C

.loc_0x3AC:
  lwz       r3, 0x26C(r31)
  bl        -0xBA8
  addi      r30, r3, 0
  cmpwi     r30, 0x4
  blt-      .loc_0x3C8
  mr        r3, r31
  bl        -0xFD9C

.loc_0x3C8:
  cmpwi     r30, 0x4
  bne-      .loc_0x3E8
  li        r3, 0x11D
  bl        -0xF26B0
  addi      r3, r31, 0
  li        r4, 0
  bl        -0xFDA4
  b         .loc_0x46C

.loc_0x3E8:
  cmpwi     r30, 0x5
  bne-      .loc_0x458
  li        r0, 0x1
  stb       r0, 0x1197(r31)
  li        r3, 0x128
  lfs       f0, -0x4D5C(r2)
  stfs      f0, 0x118C(r31)
  bl        -0xF26E0
  lha       r3, 0x134(r31)
  lis       r4, 0x803A
  lwz       r0, 0x119C(r31)
  subi      r6, r4, 0x2848
  mulli     r4, r3, 0x28
  mulli     r3, r0, 0x28
  addi      r4, r4, 0x2C
  addi      r5, r3, 0x2C
  addi      r3, r6, 0x24
  add       r4, r31, r4
  add       r5, r31, r5
  bl        -0x1225D0
  mr        r3, r31
  bl        -0x7E4
  lwz       r3, 0x314(r31)
  li        r4, 0
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x46C

.loc_0x458:
  cmpwi     r30, 0x6
  bne-      .loc_0x46C
  addi      r3, r31, 0
  li        r4, 0
  bl        -0xFE2C

.loc_0x46C:
  lwz       r0, 0xBC(r1)
  lwz       r31, 0xB4(r1)
  lwz       r30, 0xB0(r1)
  lwz       r29, 0xAC(r1)
  addi      r1, r1, 0xB8
  mtlr      r0
  blr
*/
}