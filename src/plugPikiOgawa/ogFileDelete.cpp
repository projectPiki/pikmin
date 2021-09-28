

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
 * Address:	80197AD8
 * Size:	000064
 */
void zen::ogScrFileSelectMgr::setOperateMode_Delete()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x2
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  bl        -0xEA3C
  mr        r3, r31
  bl        -0xFF34
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x10040
  lfs       f1, -0x4D58(r2)
  addi      r3, r31, 0xA4
  lfs       f2, -0x4D54(r2)
  bl        0x43104
  lfs       f1, -0x4D58(r2)
  addi      r3, r31, 0xD4
  lfs       f2, -0x4D54(r2)
  bl        0x430F4
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000178
 */
void zen::ogScrFileSelectMgr::DeleteEffectStart()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80197B3C
 * Size:	0003EC
 */
void zen::ogScrFileSelectMgr::OperateDelete(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xE0(r1)
  stw       r31, 0xDC(r1)
  mr        r31, r3
  stw       r30, 0xD8(r1)
  stw       r29, 0xD4(r1)
  lbz       r0, 0x1196(r3)
  cmplwi    r0, 0
  beq-      .loc_0x64
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x1188(r31)
  lfs       f0, 0x28C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x1188(r31)
  lfs       f1, 0x1188(r31)
  lfs       f0, -0x4D58(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x3D0
  li        r0, 0
  stb       r0, 0x1196(r31)
  addi      r3, r31, 0
  li        r4, 0
  bl        -0xFF0C
  b         .loc_0x3D0

.loc_0x64:
  lbz       r0, 0x1195(r31)
  cmplwi    r0, 0
  beq-      .loc_0x1E0
  lwz       r3, 0x2CC(r31)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lfs       f1, 0x1188(r31)
  lfs       f0, -0x4D38(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xC0
  fsubs     f1, f1, f0
  lfs       f0, -0x4D30(r2)
  lwz       r3, 0x2CC(r31)
  lfs       f2, -0x4D34(r2)
  fdivs     f0, f1, f0
  lha       r29, 0x1A(r3)
  fmuls     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0xC8(r1)
  lwz       r30, 0xCC(r1)
  b         .loc_0x118

.loc_0xC0:
  lfs       f2, -0x4D30(r2)
  fcmpo     cr0, f1, f2
  bge-      .loc_0x10C
  fsubs     f0, f1, f2
  lwz       r3, 0x2CC(r31)
  lfs       f1, -0x4D34(r2)
  lwz       r12, 0x0(r3)
  fdivs     f0, f0, f2
  lwz       r12, 0x14(r12)
  lha       r29, 0x1A(r3)
  mtlr      r12
  mr        r5, r29
  fmuls     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0xC8(r1)
  lwz       r30, 0xCC(r1)
  mr        r4, r30
  blrl      
  b         .loc_0x118

.loc_0x10C:
  lwz       r3, 0x2CC(r31)
  lha       r30, 0x18(r3)
  lha       r29, 0x1A(r3)

.loc_0x118:
  lwz       r3, 0x2CC(r31)
  addi      r4, r30, 0
  addi      r5, r29, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x1188(r31)
  lfs       f0, 0x28C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x1188(r31)
  lbz       r0, 0x1199(r31)
  cmplwi    r0, 0
  bne-      .loc_0x18C
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r3, r3, 0x24
  bl        -0x124240
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x18C
  li        r0, 0x1
  stb       r0, 0x1199(r31)
  mr        r3, r31
  bl        -0x10524
  mr        r3, r31
  bl        -0xD8D4
  li        r3, 0x129
  bl        -0xF2950

.loc_0x18C:
  lbz       r0, 0x1199(r31)
  cmplwi    r0, 0
  beq-      .loc_0x3D0
  lfs       f1, 0x1188(r31)
  lfs       f0, -0x4D58(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x3D0
  li        r6, 0
  stb       r6, 0x1195(r31)
  li        r0, 0x1
  addi      r3, r31, 0
  stb       r0, 0x1196(r31)
  li        r4, 0x4
  lfs       f0, -0x4D2C(r2)
  stfs      f0, 0x1188(r31)
  lwz       r5, 0x2CC(r31)
  lbz       r0, 0xC(r5)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r5)
  bl        -0xEC60
  b         .loc_0x3D0

.loc_0x1E0:
  lwz       r3, 0x26C(r31)
  bl        -0xEC8
  addi      r30, r3, 0
  cmpwi     r30, 0x4
  blt-      .loc_0x1FC
  mr        r3, r31
  bl        -0x100BC

.loc_0x1FC:
  cmpwi     r30, 0x4
  bne-      .loc_0x21C
  li        r3, 0x11D
  bl        -0xF29D0
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x100C4
  b         .loc_0x3D0

.loc_0x21C:
  cmpwi     r30, 0x5
  bne-      .loc_0x3BC
  li        r3, 0x128
  bl        -0xF29F0
  lha       r0, 0x134(r31)
  lis       r3, 0x803A
  subi      r5, r3, 0x2848
  mulli     r3, r0, 0x28
  addi      r4, r3, 0x2C
  addi      r3, r5, 0x24
  add       r4, r31, r4
  bl        -0x1225BC
  addi      r3, r31, 0
  li        r4, 0x3
  bl        -0xECDC
  lfs       f0, -0x4D58(r2)
  lis       r9, 0x4330
  addi      r5, r1, 0x68
  stfs      f0, 0x70(r1)
  li        r4, 0x2C
  li        r6, 0
  stfs      f0, 0x6C(r1)
  li        r7, 0
  stfs      f0, 0x68(r1)
  stfs      f0, 0x7C(r1)
  stfs      f0, 0x78(r1)
  lfs       f1, 0xE30(r13)
  stfs      f0, 0x74(r1)
  lfs       f0, 0xE34(r13)
  stfs      f1, 0x68(r1)
  stfs      f0, 0x6C(r1)
  lfs       f0, 0xE38(r13)
  stfs      f0, 0x70(r1)
  lha       r0, 0x134(r31)
  lfd       f4, -0x4D40(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4D50(r2)
  add       r3, r31, r0
  lfs       f2, -0x4D4C(r2)
  lwz       r8, 0x3B0(r3)
  lha       r3, 0x18(r8)
  lha       r0, 0x1C(r8)
  lha       r8, 0x18(r8)
  sub       r0, r0, r3
  xoris     r0, r0, 0x8000
  stw       r0, 0xC4(r1)
  xoris     r0, r8, 0x8000
  stw       r9, 0xC0(r1)
  stw       r0, 0xCC(r1)
  lfd       f0, 0xC0(r1)
  stw       r9, 0xC8(r1)
  fsubs     f0, f0, f4
  lfd       f1, 0xC8(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  stfs      f0, 0x68(r1)
  lha       r0, 0x134(r31)
  rlwinm    r0,r0,2,0,29
  add       r3, r31, r0
  lwz       r10, 0x3B0(r3)
  lha       r8, 0x1A(r10)
  lha       r3, 0x1A(r10)
  lha       r0, 0x1E(r10)
  xoris     r8, r8, 0x8000
  stw       r8, 0xBC(r1)
  sub       r0, r0, r3
  xoris     r0, r0, 0x8000
  stw       r9, 0xB8(r1)
  stw       r0, 0xB4(r1)
  lfd       f0, 0xB8(r1)
  stw       r9, 0xB0(r1)
  fsubs     f1, f0, f4
  lfd       f0, 0xB0(r1)
  fsubs     f0, f0, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  fsubs     f0, f2, f0
  stfs      f0, 0x6C(r1)
  lwz       r3, 0x0(r31)
  bl        0x51CA4
  lfs       f0, 0x68(r1)
  addi      r5, r1, 0x74
  lfs       f2, -0x4D4C(r2)
  li        r4, 0x2B
  stfs      f0, 0x74(r1)
  lfs       f0, -0x4D48(r2)
  li        r6, 0
  lfs       f1, 0x6C(r1)
  li        r7, 0
  fsubs     f1, f2, f1
  fsubs     f0, f1, f0
  stfs      f0, 0x78(r1)
  lfs       f0, 0xE3C(r13)
  stfs      f0, 0x7C(r1)
  lwz       r3, 0x0(r31)
  bl        0x51C64
  lfs       f0, -0x4D28(r2)
  li        r3, 0x1
  li        r0, 0
  stfs      f0, 0x1188(r31)
  stb       r3, 0x1195(r31)
  stb       r0, 0x1199(r31)
  b         .loc_0x3D0

.loc_0x3BC:
  cmpwi     r30, 0x6
  bne-      .loc_0x3D0
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x1027C

.loc_0x3D0:
  lwz       r0, 0xE4(r1)
  lwz       r31, 0xDC(r1)
  lwz       r30, 0xD8(r1)
  lwz       r29, 0xD4(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr
*/
}