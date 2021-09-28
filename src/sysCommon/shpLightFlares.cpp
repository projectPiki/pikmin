

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
 * Address:	........
 * Size:	00011C
 */
void LightFlare::loadini(CmdStream *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void LightFlare::saveini(char *, RandomAccessStream &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E8
 */
void LightGroup::saveini(char *, RandomAccessStream &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80035B38
 * Size:	000420
 */
void LightGroup::loadini(CmdStream *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r7, 0x8022
  stw       r0, 0x4(r1)
  lis       r6, 0x8022
  lis       r5, 0x8023
  stwu      r1, -0x50(r1)
  lis       r8, 0x8023
  lis       r9, 0x8023
  stfd      f31, 0x48(r1)
  stmw      r24, 0x28(r1)
  addi      r30, r3, 0
  addi      r31, r4, 0
  addi      r27, r7, 0x738C
  addi      r26, r6, 0x737C
  subi      r25, r5, 0x7864
  subi      r28, r8, 0x761C
  subi      r29, r9, 0x7628
  lfs       f31, -0x7CB0(r2)
  b         .loc_0x3CC

.loc_0x4C:
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB524
  addi      r3, r31, 0
  subi      r4, r13, 0x7B30
  bl        0xB83C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x8C
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB504
  crclr     6, 0x6
  addi      r5, r30, 0x18
  subi      r4, r13, 0x7B28
  bl        0x1E24D8
  b         .loc_0x3CC

.loc_0x8C:
  addi      r3, r31, 0
  subi      r4, r13, 0x7B24
  bl        0xB808
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xC0
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB4D0
  crclr     6, 0x6
  addi      r5, r30, 0x14
  subi      r4, r13, 0x7B28
  bl        0x1E24A4
  b         .loc_0x3CC

.loc_0xC0:
  addi      r3, r31, 0
  subi      r4, r13, 0x7B1C
  bl        0xB7D4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x12C
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB49C
  crclr     6, 0x6
  addi      r5, r30, 0x24
  subi      r4, r13, 0x7B40
  bl        0x1E2470
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB480
  crclr     6, 0x6
  addi      r5, r30, 0x28
  subi      r4, r13, 0x7B40
  bl        0x1E2454
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB464
  crclr     6, 0x6
  addi      r5, r30, 0x2C
  subi      r4, r13, 0x7B40
  bl        0x1E2438
  b         .loc_0x3CC

.loc_0x12C:
  addi      r3, r31, 0
  subi      r4, r13, 0x7B18
  bl        0xB768
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1D4
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB430
  crclr     6, 0x6
  addi      r5, r1, 0x20
  subi      r4, r13, 0x7B28
  bl        0x1E2404
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB414
  crclr     6, 0x6
  addi      r5, r1, 0x1C
  subi      r4, r13, 0x7B28
  bl        0x1E23E8
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB3F8
  crclr     6, 0x6
  addi      r5, r1, 0x18
  subi      r4, r13, 0x7B28
  bl        0x1E23CC
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB3DC
  crclr     6, 0x6
  addi      r5, r1, 0x14
  subi      r4, r13, 0x7B28
  bl        0x1E23B0
  lwz       r0, 0x20(r1)
  lwz       r5, 0x14(r1)
  lwz       r4, 0x18(r1)
  lwz       r3, 0x1C(r1)
  stb       r0, 0x30(r30)
  stb       r3, 0x31(r30)
  stb       r4, 0x32(r30)
  stb       r5, 0x33(r30)
  b         .loc_0x3CC

.loc_0x1D4:
  addi      r3, r31, 0
  subi      r4, r13, 0x7B10
  bl        0xB6C0
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x224
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB388
  addi      r24, r3, 0
  subi      r4, r13, 0x7B38
  bl        0x1E3490
  cmpwi     r3, 0
  beq-      .loc_0x218
  mr        r3, r24
  bl        0xA5FC
  stw       r3, 0x34(r30)
  b         .loc_0x3CC

.loc_0x218:
  li        r0, 0
  stw       r0, 0x34(r30)
  b         .loc_0x3CC

.loc_0x224:
  addi      r3, r31, 0
  addi      r4, r29, 0
  bl        0xB670
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x274
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB338
  addi      r24, r3, 0
  subi      r4, r13, 0x7B38
  bl        0x1E3440
  cmpwi     r3, 0
  beq-      .loc_0x268
  mr        r3, r24
  bl        0xA5AC
  stw       r3, 0x38(r30)
  b         .loc_0x3CC

.loc_0x268:
  li        r0, 0
  stw       r0, 0x38(r30)
  b         .loc_0x3CC

.loc_0x274:
  addi      r3, r31, 0
  addi      r4, r28, 0
  bl        0xB620
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x3CC
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB2E8
  li        r3, 0x24
  bl        0x11234
  cmplwi    r3, 0
  beq-      .loc_0x2D4
  stw       r27, 0x0(r3)
  li        r4, 0
  subi      r0, r13, 0x7B08
  stw       r26, 0x0(r3)
  stw       r4, 0x10(r3)
  stw       r4, 0xC(r3)
  stw       r4, 0x8(r3)
  stw       r0, 0x4(r3)
  stw       r25, 0x0(r3)
  stfs      f31, 0x20(r3)
  stfs      f31, 0x1C(r3)
  stfs      f31, 0x18(r3)

.loc_0x2D4:
  mr        r24, r3
  b         .loc_0x384

.loc_0x2DC:
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB294
  addi      r3, r31, 0
  subi      r4, r13, 0x7B48
  bl        0xB5AC
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x31C
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB274
  crclr     6, 0x6
  addi      r5, r24, 0x14
  subi      r4, r13, 0x7B40
  bl        0x1E2248
  b         .loc_0x384

.loc_0x31C:
  addi      r3, r31, 0
  subi      r4, r13, 0x7B3C
  bl        0xB578
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x384
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB240
  crclr     6, 0x6
  addi      r5, r24, 0x18
  subi      r4, r13, 0x7B40
  bl        0x1E2214
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB224
  crclr     6, 0x6
  addi      r5, r24, 0x1C
  subi      r4, r13, 0x7B40
  bl        0x1E21F8
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB208
  crclr     6, 0x6
  addi      r5, r24, 0x20
  subi      r4, r13, 0x7B40
  bl        0x1E21DC

.loc_0x384:
  mr        r3, r31
  bl        0xAE98
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x3A4
  mr        r3, r31
  bl        0xB5B8
  rlwinm.   r0,r3,0,24,31
  beq+      .loc_0x2DC

.loc_0x3A4:
  mr        r3, r31
  bl        0xAE78
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x3C0
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB1BC

.loc_0x3C0:
  addi      r3, r30, 0x40
  addi      r4, r24, 0
  bl        0xA6D8

.loc_0x3CC:
  mr        r3, r31
  bl        0xAE50
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x3EC
  mr        r3, r31
  bl        0xB570
  rlwinm.   r0,r3,0,24,31
  beq+      .loc_0x4C

.loc_0x3EC:
  mr        r3, r31
  bl        0xAE30
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x408
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xB174

.loc_0x408:
  lmw       r24, 0x28(r1)
  lwz       r0, 0x54(r1)
  lfd       f31, 0x48(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80035F58
 * Size:	0001CC
 */
void LightGroup::refresh(Graphics &, Matrix4f *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x68(r1)
  stfd      f31, 0x60(r1)
  stfd      f30, 0x58(r1)
  stfd      f29, 0x50(r1)
  stfd      f28, 0x48(r1)
  stw       r31, 0x44(r1)
  mr        r31, r3
  stw       r30, 0x40(r1)
  stw       r29, 0x3C(r1)
  stw       r28, 0x38(r1)
  lwz       r0, 0x50(r3)
  cmplwi    r0, 0
  beq-      .loc_0x19C
  lwz       r0, 0x68(r31)
  cmplwi    r0, 0
  beq-      .loc_0x19C
  lwz       r4, 0x1C(r31)
  addis     r0, r4, 0x1
  cmplwi    r0, 0xFFFF
  bne-      .loc_0x60
  mr        r29, r5
  b         .loc_0x6C

.loc_0x60:
  lwz       r3, 0x64(r31)
  bl        -0xFD4
  mr        r29, r3

.loc_0x6C:
  lwz       r28, 0x50(r31)
  lfs       f29, -0x7CB0(r2)
  lfd       f30, -0x7CA8(r2)
  lfd       f31, -0x7CA0(r2)
  lfs       f28, -0x7C98(r2)
  b         .loc_0x194

.loc_0x84:
  lfs       f0, 0x18(r28)
  addi      r4, r29, 0
  addi      r3, r1, 0x28
  stfs      f0, 0x28(r1)
  lfs       f0, 0x1C(r28)
  stfs      f0, 0x2C(r1)
  lfs       f0, 0x20(r28)
  stfs      f0, 0x30(r1)
  bl        0x1750
  lfs       f1, 0x0(r29)
  lfs       f0, 0x4(r29)
  fmuls     f1, f1, f1
  lfs       f2, 0x8(r29)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f2, f2, f0
  fcmpo     cr0, f2, f29
  ble-      .loc_0x120
  fsqrte    f1, f2
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f0, f1, f0
  fmul      f0, f2, f0
  frsp      f0, f0
  stfs      f0, 0x1C(r1)
  lfs       f2, 0x1C(r1)

.loc_0x120:
  lfs       f0, 0x14(r28)
  lwz       r3, 0x2DEC(r13)
  fmuls     f0, f0, f2
  stfs      f0, 0x20(r1)
  stfs      f0, 0x24(r1)
  lwz       r30, 0x68(r31)
  bl        0x99E4
  cmplwi    r3, 0
  beq-      .loc_0x190
  lwz       r0, 0x30(r31)
  stw       r0, 0x0(r3)
  lwz       r4, 0x28(r1)
  lwz       r0, 0x2C(r1)
  stw       r4, 0x4(r3)
  stw       r0, 0x8(r3)
  lwz       r0, 0x30(r1)
  stw       r0, 0xC(r3)
  lwz       r4, 0x20(r1)
  lwz       r0, 0x24(r1)
  stw       r4, 0x10(r3)
  stw       r0, 0x14(r3)
  stfs      f29, 0x18(r3)
  stfs      f29, 0x1C(r3)
  stfs      f28, 0x20(r3)
  stfs      f28, 0x24(r3)
  lwz       r0, 0x20(r30)
  stw       r0, 0x28(r3)
  stw       r3, 0x20(r30)

.loc_0x190:
  lwz       r28, 0xC(r28)

.loc_0x194:
  cmplwi    r28, 0
  bne+      .loc_0x84

.loc_0x19C:
  lwz       r0, 0x6C(r1)
  lfd       f31, 0x60(r1)
  lfd       f30, 0x58(r1)
  lfd       f29, 0x50(r1)
  lfd       f28, 0x48(r1)
  lwz       r31, 0x44(r1)
  lwz       r30, 0x40(r1)
  lwz       r29, 0x3C(r1)
  lwz       r28, 0x38(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
}