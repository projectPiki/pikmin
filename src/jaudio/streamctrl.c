

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void Jac_PlayStreamBGM(long, long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Jac_StopStreamBGM(long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void Jac_VolMoveStreamBGM(long, long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800067E0
 * Size:	00039C
 */
void StreamMain()
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x8022
  stw       r0, 0x4(r1)
  lis       r4, 0x802F
  stwu      r1, -0x48(r1)
  stmw      r28, 0x38(r1)
  addi      r31, r3, 0x2DE0
  subi      r30, r4, 0x6940
  lwz       r0, 0x80(r31)
  cmplwi    r0, 0x7
  bgt-      .loc_0x388
  lis       r3, 0x8022
  rlwinm    r0,r0,2,0,29
  addi      r3, r3, 0x2E8C
  lwzx      r0, r3, r0
  mtctr     r0
  bctr      
  lwz       r0, 0x84(r31)
  li        r29, -0x1
  addi      r28, r31, 0x88
  stw       r0, 0x88(r31)
  stw       r29, 0x84(r31)
  lwz       r0, 0x88(r31)
  cmpwi     r0, -0x1
  bne-      .loc_0x70
  li        r0, 0
  stw       r0, 0x80(r31)
  b         .loc_0x388

.loc_0x70:
  rlwinm    r0,r0,4,0,27
  addi      r4, r30, 0
  add       r3, r31, r0
  bl        0x1F8AB0
  cmpwi     r3, 0
  bne-      .loc_0x98
  stw       r29, 0x0(r28)
  li        r0, 0
  stw       r0, 0x80(r31)
  b         .loc_0x388

.loc_0x98:
  lwz       r0, 0x34(r30)
  li        r3, 0x1
  stw       r0, 0xA8(r31)
  lwz       r0, 0xA8(r31)
  rlwinm    r0,r0,24,8,31
  mulli     r0, r0, 0xE0
  stw       r0, 0xA8(r31)
  bl        0x1FFA68
  lwz       r0, 0x90(r31)
  cmpwi     r0, 0
  bne-      .loc_0xD0
  lfs       f0, 0x8C(r31)
  stfs      f0, 0xA4(r31)
  b         .loc_0xD8

.loc_0xD0:
  lfs       f0, -0x7FE0(r2)
  stfs      f0, 0xA4(r31)

.loc_0xD8:
  addi      r28, r31, 0xA4
  lfs       f0, 0xA4(r31)
  fctiwz    f0, f0
  stfd      f0, 0x30(r1)
  lwz       r0, 0x34(r1)
  rlwinm    r3,r0,0,24,31
  bl        0x1FFB38
  lfs       f0, 0x0(r28)
  fctiwz    f0, f0
  stfd      f0, 0x28(r1)
  lwz       r0, 0x2C(r1)
  rlwinm    r3,r0,0,24,31
  bl        0x1FFB4C
  addi      r3, r30, 0
  li        r4, 0
  li        r5, 0
  li        r6, 0
  bl        0x1F8F4C
  li        r0, 0x2
  stw       r0, 0x80(r31)
  b         .loc_0x388
  bl        0x1FB004
  cmpwi     r3, 0
  bne-      .loc_0x388
  bl        0x1FF7E0
  li        r3, 0x1
  bl        0x1FF800
  li        r0, 0x3
  stw       r0, 0x80(r31)
  b         .loc_0x388
  bl        0x1FF7B8
  stw       r3, 0x1C(r1)
  bl        0x1FF7D8
  addi      r4, r31, 0x90
  lwz       r0, 0x90(r31)
  cmpwi     r0, 0
  beq-      .loc_0x1E0
  xoris     r0, r0, 0x8000
  addi      r28, r31, 0xA4
  stw       r0, 0x2C(r1)
  lis       r0, 0x4330
  lfs       f3, 0x8C(r31)
  stw       r0, 0x28(r1)
  lfs       f2, 0xA4(r31)
  lfd       f1, -0x7FE8(r2)
  lfd       f0, 0x28(r1)
  fsubs     f3, f3, f2
  fsubs     f0, f0, f1
  fdivs     f3, f3, f0
  fadds     f0, f2, f3
  stfs      f0, 0xA4(r31)
  lwz       r3, 0x0(r4)
  subi      r0, r3, 0x1
  stw       r0, 0x0(r4)
  lfs       f0, 0xA4(r31)
  fctiwz    f0, f0
  stfd      f0, 0x30(r1)
  lwz       r0, 0x34(r1)
  rlwinm    r3,r0,0,24,31
  bl        0x1FFA64
  lfs       f0, 0x0(r28)
  fctiwz    f0, f0
  stfd      f0, 0x20(r1)
  lwz       r0, 0x24(r1)
  rlwinm    r3,r0,0,24,31
  bl        0x1FFA78

.loc_0x1E0:
  addi      r4, r31, 0xA0
  lwz       r0, 0xA0(r31)
  cmpwi     r0, 0
  beq-      .loc_0x264
  xoris     r0, r0, 0x8000
  addi      r28, r31, 0xA4
  stw       r0, 0x24(r1)
  lis       r0, 0x4330
  lfs       f3, 0x9C(r31)
  stw       r0, 0x20(r1)
  lfs       f2, 0xA4(r31)
  lfd       f1, -0x7FE8(r2)
  lfd       f0, 0x20(r1)
  fsubs     f3, f3, f2
  fsubs     f0, f0, f1
  fdivs     f3, f3, f0
  fadds     f0, f2, f3
  stfs      f0, 0xA4(r31)
  lwz       r3, 0x0(r4)
  subi      r0, r3, 0x1
  stw       r0, 0x0(r4)
  lfs       f0, 0xA4(r31)
  fctiwz    f0, f0
  stfd      f0, 0x28(r1)
  lwz       r0, 0x2C(r1)
  rlwinm    r3,r0,0,24,31
  bl        0x1FF9E0
  lfs       f0, 0x0(r28)
  fctiwz    f0, f0
  stfd      f0, 0x30(r1)
  lwz       r0, 0x34(r1)
  rlwinm    r3,r0,0,24,31
  bl        0x1FF9F4

.loc_0x264:
  lwz       r0, -0x7FF8(r13)
  lwz       r4, 0x1C(r1)
  lwz       r3, 0xA8(r31)
  mulli     r0, r0, 0x78
  sub       r3, r3, r4
  cmplw     r3, r0
  bge-      .loc_0x388
  li        r3, 0x5
  li        r0, 0x78
  stw       r3, 0x80(r31)
  stw       r0, 0x98(r31)
  b         .loc_0x388
  bl        0x1FF674
  addi      r5, r31, 0x98
  lwz       r4, 0x98(r31)
  cmpwi     r4, 0
  beq-      .loc_0x328
  lwz       r0, 0xA8(r31)
  sub.      r0, r0, r3
  beq-      .loc_0x328
  xoris     r0, r4, 0x8000
  addi      r28, r31, 0xA4
  stw       r0, 0x24(r1)
  lis       r0, 0x4330
  lfs       f2, 0xA4(r31)
  stw       r0, 0x20(r1)
  lfd       f1, -0x7FE8(r2)
  fneg      f3, f2
  lfd       f0, 0x20(r1)
  fsubs     f0, f0, f1
  fdivs     f3, f3, f0
  fadds     f0, f2, f3
  stfs      f0, 0xA4(r31)
  lwz       r3, 0x0(r5)
  subi      r0, r3, 0x1
  stw       r0, 0x0(r5)
  lfs       f0, 0xA4(r31)
  fctiwz    f0, f0
  stfd      f0, 0x28(r1)
  lwz       r0, 0x2C(r1)
  rlwinm    r3,r0,0,24,31
  bl        0x1FF920
  lfs       f0, 0x0(r28)
  fctiwz    f0, f0
  stfd      f0, 0x30(r1)
  lwz       r0, 0x34(r1)
  rlwinm    r3,r0,0,24,31
  bl        0x1FF934
  b         .loc_0x388

.loc_0x328:
  addi      r3, r30, 0x3C
  bl        0x1FACF8
  li        r0, 0x6
  stw       r0, 0x80(r31)
  b         .loc_0x388
  bl        0x1FADF4
  cmpwi     r3, 0
  bne-      .loc_0x388
  li        r3, 0
  bl        0x1FF5F4
  li        r0, 0x7
  stw       r0, 0x80(r31)
  b         .loc_0x388
  bl        0x1FADD4
  cmpwi     r3, 0
  bne-      .loc_0x388
  mr        r3, r30
  bl        0x1F8888
  li        r3, -0x1
  li        r0, 0x1
  stw       r3, 0x88(r31)
  li        r3, 0
  stw       r0, 0x80(r31)
  bl        0x1FF5BC

.loc_0x388:
  lmw       r28, 0x38(r1)
  lwz       r0, 0x4C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}