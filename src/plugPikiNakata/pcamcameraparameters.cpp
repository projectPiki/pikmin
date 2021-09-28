

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
 * Address:	801249C4
 * Size:	000A78
 */
void PcamCameraParameters::PcamCameraParameters()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x8022
  stw       r0, 0x4(r1)
  addi      r0, r4, 0x738C
  lis       r4, 0x802C
  stwu      r1, -0x108(r1)
  stmw      r27, 0xF4(r1)
  addi      r28, r3, 0
  addi      r31, r4, 0x55D8
  lis       r3, 0x8022
  li        r27, 0
  subi      r4, r13, 0x1A48
  stw       r0, 0x0(r28)
  addi      r0, r3, 0x737C
  addi      r3, r28, 0
  stw       r0, 0x0(r28)
  stw       r27, 0x10(r28)
  stw       r27, 0xC(r28)
  stw       r27, 0x8(r28)
  bl        -0xFFB3C
  lis       r3, 0x8023
  subi      r0, r3, 0x71E0
  stw       r0, 0x0(r28)
  addi      r3, r28, 0
  subi      r4, r13, 0x1A48
  bl        -0xE42EC
  lis       r3, 0x802C
  addi      r0, r3, 0x5B30
  stw       r0, 0x0(r28)
  li        r3, 0x14
  bl        -0xDDA38
  lis       r4, 0x8012
  addi      r4, r4, 0x5454
  li        r5, 0
  li        r6, 0xC
  li        r7, 0x1
  bl        0xF01D4
  li        r0, 0
  mulli     r29, r0, 0xC
  add       r4, r3, r29
  addi      r0, r31, 0x34
  stw       r0, 0x0(r4)
  addi      r30, r3, 0
  li        r0, 0x1
  stw       r27, 0x4(r4)
  li        r3, 0x29C
  stw       r0, 0x8(r4)
  bl        -0xDDA7C
  lis       r4, 0x8012
  addi      r4, r4, 0x543C
  li        r5, 0
  li        r6, 0xC
  li        r7, 0x37
  bl        0xF0190
  add       r6, r3, r29
  addi      r0, r31, 0x44
  stw       r0, 0x0(r6)
  li        r0, 0x1
  mulli     r4, r0, 0xC
  lfs       f8, -0x5EB0(r2)
  stfs      f8, 0x4(r6)
  li        r0, 0x2
  mulli     r5, r0, 0xC
  lfs       f7, -0x5EAC(r2)
  stfs      f7, 0x8(r6)
  add       r6, r3, r4
  addi      r0, r31, 0x58
  stw       r0, 0x0(r6)
  li        r0, 0x3
  mulli     r4, r0, 0xC
  lfs       f6, -0x5EA8(r2)
  stfs      f6, 0x4(r6)
  li        r0, 0x4
  mulli     r8, r0, 0xC
  lfs       f5, -0x5EA4(r2)
  stfs      f5, 0x8(r6)
  add       r5, r3, r5
  addi      r0, r31, 0x68
  stw       r0, 0x0(r5)
  li        r0, 0x5
  mulli     r7, r0, 0xC
  stfs      f8, 0x4(r5)
  lfs       f4, -0x5EA0(r2)
  li        r0, 0x6
  mulli     r6, r0, 0xC
  stfs      f4, 0x8(r5)
  add       r9, r3, r4
  addi      r0, r31, 0x78
  stw       r0, 0x0(r9)
  li        r0, 0x7
  mulli     r5, r0, 0xC
  lfs       f3, -0x5E9C(r2)
  stfs      f3, 0x4(r9)
  li        r0, 0x8
  mulli     r4, r0, 0xC
  lfs       f2, -0x5E98(r2)
  stfs      f2, 0x8(r9)
  add       r8, r3, r8
  addi      r0, r31, 0x94
  stw       r0, 0x0(r8)
  add       r9, r3, r7
  add       r10, r3, r4
  stfs      f6, 0x4(r8)
  li        r0, 0x9
  mulli     r0, r0, 0xC
  lfs       f1, -0x5E94(r2)
  stfs      f1, 0x8(r8)
  addi      r7, r31, 0xB0
  add       r8, r3, r6
  stw       r7, 0x0(r9)
  add       r7, r3, r5
  add       r11, r3, r0
  stfs      f6, 0x4(r9)
  addi      r6, r31, 0xC0
  addi      r5, r31, 0xD4
  lfs       f0, -0x5E90(r2)
  addi      r4, r31, 0xE8
  addi      r0, r31, 0xF8
  stfs      f0, 0x8(r9)
  mr        r29, r3
  stw       r6, 0x0(r8)
  stfs      f8, 0x4(r8)
  stfs      f7, 0x8(r8)
  stw       r5, 0x0(r7)
  stfs      f6, 0x4(r7)
  stfs      f5, 0x8(r7)
  stw       r4, 0x0(r10)
  stfs      f8, 0x4(r10)
  stfs      f4, 0x8(r10)
  stw       r0, 0x0(r11)
  stfs      f3, 0x4(r11)
  li        r0, 0xA
  stfs      f2, 0x8(r11)
  mulli     r0, r0, 0xC
  add       r4, r3, r0
  addi      r0, r31, 0x114
  stw       r0, 0x0(r4)
  li        r0, 0xB
  mulli     r0, r0, 0xC
  stfs      f6, 0x4(r4)
  stfs      f1, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x134
  stw       r0, 0x0(r4)
  li        r0, 0xC
  mulli     r0, r0, 0xC
  stfs      f6, 0x4(r4)
  stfs      f0, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x144
  stw       r0, 0x0(r4)
  li        r0, 0xD
  mulli     r0, r0, 0xC
  stfs      f8, 0x4(r4)
  stfs      f7, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x158
  stw       r0, 0x0(r4)
  li        r0, 0xE
  mulli     r0, r0, 0xC
  stfs      f6, 0x4(r4)
  stfs      f5, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x168
  stw       r0, 0x0(r4)
  li        r0, 0xF
  mulli     r0, r0, 0xC
  stfs      f8, 0x4(r4)
  stfs      f4, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x174
  stw       r0, 0x0(r4)
  li        r0, 0x10
  mulli     r0, r0, 0xC
  stfs      f3, 0x4(r4)
  stfs      f2, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x190
  stw       r0, 0x0(r4)
  li        r0, 0x11
  mulli     r0, r0, 0xC
  stfs      f6, 0x4(r4)
  stfs      f1, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x1AC
  stw       r0, 0x0(r4)
  li        r0, 0x12
  mulli     r0, r0, 0xC
  stfs      f6, 0x4(r4)
  stfs      f0, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x1BC
  stw       r0, 0x0(r4)
  li        r0, 0x13
  mulli     r0, r0, 0xC
  stfs      f8, 0x4(r4)
  stfs      f7, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x1D0
  stw       r0, 0x0(r4)
  stfs      f6, 0x4(r4)
  stfs      f5, 0x8(r4)
  li        r0, 0x14
  mulli     r0, r0, 0xC
  add       r4, r3, r0
  addi      r0, r31, 0x1E0
  stw       r0, 0x0(r4)
  li        r0, 0x15
  mulli     r0, r0, 0xC
  stfs      f8, 0x4(r4)
  stfs      f4, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x1F0
  stw       r0, 0x0(r4)
  li        r0, 0x16
  mulli     r0, r0, 0xC
  stfs      f3, 0x4(r4)
  stfs      f2, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x20C
  stw       r0, 0x0(r4)
  li        r0, 0x17
  mulli     r0, r0, 0xC
  stfs      f6, 0x4(r4)
  stfs      f1, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x228
  stw       r0, 0x0(r4)
  li        r0, 0x18
  mulli     r0, r0, 0xC
  stfs      f6, 0x4(r4)
  stfs      f0, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x238
  stw       r0, 0x0(r4)
  li        r0, 0x19
  mulli     r0, r0, 0xC
  stfs      f8, 0x4(r4)
  stfs      f7, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x250
  stw       r0, 0x0(r4)
  li        r0, 0x1A
  mulli     r0, r0, 0xC
  stfs      f6, 0x4(r4)
  stfs      f5, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x264
  stw       r0, 0x0(r4)
  li        r0, 0x1B
  mulli     r0, r0, 0xC
  stfs      f8, 0x4(r4)
  stfs      f4, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x274
  stw       r0, 0x0(r4)
  li        r0, 0x1C
  mulli     r0, r0, 0xC
  stfs      f3, 0x4(r4)
  stfs      f2, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x294
  stw       r0, 0x0(r4)
  li        r0, 0x1D
  mulli     r0, r0, 0xC
  stfs      f6, 0x4(r4)
  stfs      f1, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x2B4
  stw       r0, 0x0(r4)
  li        r0, 0x1E
  mulli     r0, r0, 0xC
  stfs      f6, 0x4(r4)
  stfs      f0, 0x8(r4)
  add       r5, r3, r0
  addi      r0, r31, 0x2C8
  stw       r0, 0x0(r5)
  li        r0, 0x1F
  mulli     r4, r0, 0xC
  stfs      f8, 0x4(r5)
  stfs      f7, 0x8(r5)
  li        r0, 0x20
  add       r5, r3, r4
  addi      r4, r31, 0x2DC
  stw       r4, 0x0(r5)
  mulli     r4, r0, 0xC
  stfs      f6, 0x4(r5)
  li        r0, 0x21
  stfs      f5, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0x2EC
  stw       r4, 0x0(r5)
  mulli     r4, r0, 0xC
  stfs      f8, 0x4(r5)
  li        r0, 0x22
  stfs      f4, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0x2FC
  stw       r4, 0x0(r5)
  mulli     r4, r0, 0xC
  stfs      f3, 0x4(r5)
  li        r0, 0x23
  stfs      f2, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0x318
  stw       r4, 0x0(r5)
  mulli     r4, r0, 0xC
  stfs      f6, 0x4(r5)
  li        r0, 0x24
  stfs      f1, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0x334
  stw       r4, 0x0(r5)
  mulli     r4, r0, 0xC
  stfs      f6, 0x4(r5)
  li        r0, 0x25
  stfs      f0, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0x344
  stw       r4, 0x0(r5)
  mulli     r4, r0, 0xC
  stfs      f8, 0x4(r5)
  li        r0, 0x26
  stfs      f7, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0x35C
  stw       r4, 0x0(r5)
  mulli     r4, r0, 0xC
  stfs      f6, 0x4(r5)
  li        r0, 0x27
  stfs      f5, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0x374
  stw       r4, 0x0(r5)
  mulli     r4, r0, 0xC
  stfs      f8, 0x4(r5)
  li        r0, 0x28
  stfs      f4, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0x388
  stw       r4, 0x0(r5)
  mulli     r0, r0, 0xC
  stfs      f3, 0x4(r5)
  add       r4, r3, r0
  stfs      f2, 0x8(r5)
  addi      r0, r31, 0x3A8
  stw       r0, 0x0(r4)
  li        r0, 0x29
  stfs      f6, 0x4(r4)
  mulli     r0, r0, 0xC
  stfs      f1, 0x8(r4)
  add       r4, r3, r0
  addi      r0, r31, 0x3CC
  stw       r0, 0x0(r4)
  li        r0, 0x2A
  mulli     r0, r0, 0xC
  stfs      f6, 0x4(r4)
  stfs      f0, 0x8(r4)
  add       r6, r3, r0
  addi      r0, r31, 0x3E0
  stw       r0, 0x0(r6)
  li        r0, 0x2B
  mulli     r4, r0, 0xC
  lfs       f0, -0x5E8C(r2)
  stfs      f0, 0x4(r6)
  li        r0, 0x2C
  mulli     r5, r0, 0xC
  lfs       f2, -0x5E88(r2)
  stfs      f2, 0x8(r6)
  add       r6, r3, r4
  addi      r0, r31, 0x3F0
  stw       r0, 0x0(r6)
  li        r0, 0x2D
  mulli     r4, r0, 0xC
  stfs      f0, 0x4(r6)
  stfs      f2, 0x8(r6)
  add       r6, r3, r5
  addi      r0, r31, 0x404
  stw       r0, 0x0(r6)
  li        r0, 0x2E
  mulli     r5, r0, 0xC
  stfs      f6, 0x4(r6)
  stfs      f8, 0x8(r6)
  add       r6, r3, r4
  addi      r0, r31, 0x414
  stw       r0, 0x0(r6)
  li        r0, 0x2F
  mulli     r4, r0, 0xC
  stfs      f6, 0x4(r6)
  stfs      f8, 0x8(r6)
  add       r6, r3, r5
  addi      r0, r31, 0x428
  stw       r0, 0x0(r6)
  li        r0, 0x30
  mulli     r5, r0, 0xC
  stfs      f0, 0x4(r6)
  stfs      f2, 0x8(r6)
  add       r6, r3, r4
  addi      r0, r31, 0x440
  stw       r0, 0x0(r6)
  li        r0, 0x31
  mulli     r4, r0, 0xC
  lfs       f0, -0x5E84(r2)
  stfs      f0, 0x4(r6)
  li        r0, 0x32
  mulli     r0, r0, 0xC
  lfs       f1, -0x5E80(r2)
  stfs      f1, 0x8(r6)
  add       r6, r3, r5
  addi      r5, r31, 0x454
  stw       r5, 0x0(r6)
  add       r5, r3, r4
  addi      r4, r31, 0x46C
  stfs      f6, 0x4(r6)
  add       r7, r3, r0
  addi      r0, r31, 0x488
  lfs       f0, -0x5E7C(r2)
  stfs      f0, 0x8(r6)
  stw       r4, 0x0(r5)
  stfs      f6, 0x4(r5)
  stfs      f1, 0x8(r5)
  stw       r0, 0x0(r7)
  stfs      f6, 0x4(r7)
  li        r0, 0x33
  stfs      f2, 0x8(r7)
  mulli     r0, r0, 0xC
  add       r4, r3, r0
  addi      r0, r31, 0x49C
  stw       r0, 0x0(r4)
  li        r0, 0x34
  mulli     r0, r0, 0xC
  stfs      f6, 0x4(r4)
  stfs      f2, 0x8(r4)
  add       r5, r3, r0
  addi      r0, r31, 0x4B0
  stw       r0, 0x0(r5)
  li        r0, 0x35
  mulli     r4, r0, 0xC
  stfs      f6, 0x4(r5)
  lfs       f0, -0x5E78(r2)
  li        r0, 0x36
  mulli     r0, r0, 0xC
  stfs      f0, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0x4C8
  stw       r4, 0x0(r5)
  add       r4, r3, r0
  addi      r0, r31, 0x4DC
  stfs      f6, 0x4(r5)
  li        r3, 0xC
  stfs      f0, 0x8(r5)
  stw       r0, 0x0(r4)
  stfs      f6, 0x4(r4)
  lfs       f1, -0x1CA4(r13)
  lfs       f0, -0x5E74(r2)
  fmuls     f0, f1, f0
  stfs      f0, 0x8(r4)
  bl        -0xDE0E4
  addi      r27, r3, 0
  mr.       r3, r27
  beq-      .loc_0x748
  addi      r5, r30, 0
  addi      r7, r29, 0
  li        r4, 0x1
  li        r6, 0x37
  bl        -0x38B4

.loc_0x748:
  stw       r27, 0x24(r28)
  li        r0, 0
  lwz       r4, 0x24(r28)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x4(r4)
  lfs       f13, -0x5E70(r2)
  lwz       r3, 0x0(r3)
  stfs      f13, 0x0(r3)
  lwz       r3, 0x4(r4)
  lfs       f12, -0x5E6C(r2)
  lwz       r3, 0x0(r3)
  stfs      f12, 0x4(r3)
  lwz       r3, 0x4(r4)
  lfs       f11, -0x5EB0(r2)
  lwz       r3, 0x0(r3)
  stfs      f11, 0x8(r3)
  lwz       r3, 0x4(r4)
  lfs       f10, -0x5E68(r2)
  lwz       r3, 0x0(r3)
  stfs      f10, 0xC(r3)
  lwz       r3, 0x4(r4)
  lfs       f9, -0x5E94(r2)
  lwz       r3, 0x0(r3)
  stfs      f9, 0x10(r3)
  lwz       r3, 0x4(r4)
  lfs       f8, -0x5E64(r2)
  lwz       r3, 0x0(r3)
  stfs      f8, 0x14(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f13, 0x18(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f12, 0x1C(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5E60(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x20(r3)
  lwz       r3, 0x4(r4)
  lfs       f7, -0x5E5C(r2)
  lwz       r3, 0x0(r3)
  stfs      f7, 0x24(r3)
  lwz       r3, 0x4(r4)
  lfs       f6, -0x5E98(r2)
  lwz       r3, 0x0(r3)
  stfs      f6, 0x28(r3)
  lwz       r3, 0x4(r4)
  lfs       f5, -0x5E58(r2)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x2C(r3)
  lwz       r3, 0x4(r4)
  lfs       f4, -0x5E54(r2)
  lwz       r3, 0x0(r3)
  stfs      f4, 0x30(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f12, 0x34(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x38(r3)
  lwz       r3, 0x4(r4)
  lfs       f3, -0x5E50(r2)
  lwz       r3, 0x0(r3)
  stfs      f3, 0x3C(r3)
  lwz       r3, 0x4(r4)
  lfs       f2, -0x5E4C(r2)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x40(r3)
  lwz       r3, 0x4(r4)
  lfs       f1, -0x5E48(r2)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x44(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f13, 0x48(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f8, 0x4C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f11, 0x50(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f10, 0x54(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f9, 0x58(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f8, 0x5C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f13, 0x60(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f8, 0x64(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5E44(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x68(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f7, 0x6C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f6, 0x70(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x74(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f4, 0x78(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f8, 0x7C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x80(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f3, 0x84(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x88(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x8C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f13, 0x90(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f12, 0x94(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f11, 0x98(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5E40(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x9C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f12, 0xA0(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f1, 0xA4(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5E3C(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xA8(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xAC(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5E38(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xB0(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5E80(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xB4(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5E34(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xB8(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5E30(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xBC(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5E2C(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xC0(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5E28(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xC4(r3)
  lwz       r5, 0x4(r4)
  mr        r3, r28
  lwz       r5, 0x0(r5)
  stfs      f0, 0xC8(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5E24(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xCC(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f6, 0xD0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f6, 0xD4(r5)
  lfs       f1, -0x1CA4(r13)
  lfs       f0, -0x5E20(r2)
  lwz       r4, 0x4(r4)
  fmuls     f0, f1, f0
  lwz       r4, 0x0(r4)
  stfs      f0, 0xD8(r4)
  lwz       r0, 0x10C(r1)
  lmw       r27, 0xF4(r1)
  addi      r1, r1, 0x108
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012543C
 * Size:	000018
 */
void ParaParameterInfoF::ParaParameterInfoF()
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x0(r3)
  lfs       f0, -0x5EA8(r2)
  stfs      f0, 0x4(r3)
  stfs      f0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80125454
 * Size:	000014
 */
void ParaParameterInfoI::ParaParameterInfoI()
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x0(r3)
  stw       r0, 0x4(r3)
  stw       r0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80125468
 * Size:	0000D8
 */
void PcamCameraParameters::read(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  stw       r28, 0x10(r1)
  addi      r28, r4, 0
  addi      r3, r28, 0
  lwz       r12, 0x4(r28)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x20(r29)
  lwz       r0, 0x20(r29)
  lwz       r30, 0x24(r29)
  cmpwi     r0, 0x6
  bgt-      .loc_0xA0
  lwz       r3, 0x0(r30)
  mr        r4, r28
  lwz       r12, 0xC(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  li        r29, 0
  li        r31, 0

.loc_0x6C:
  mr        r3, r28
  lwz       r12, 0x4(r28)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x4(r30)
  addi      r29, r29, 0x1
  cmpwi     r29, 0x36
  lwz       r3, 0x0(r3)
  stfsx     f1, r3, r31
  addi      r31, r31, 0x4
  blt+      .loc_0x6C
  b         .loc_0xB8

.loc_0xA0:
  mr        r3, r30
  lwz       r12, 0x8(r30)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0xB8:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  lwz       r28, 0x10(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}