

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
 * Address:	8013A500
 * Size:	000084
 */
void TaiOtimotiSoundTable::TaiOtimotiSoundTable()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  bl        -0x1B4AC
  li        r30, 0
  li        r31, 0
  b         .loc_0x58

.loc_0x30:
  li        r3, 0x4
  bl        -0xF3530
  cmplwi    r3, 0
  beq-      .loc_0x48
  addi      r0, r30, 0xA
  stw       r0, 0x0(r3)

.loc_0x48:
  lwz       r4, 0x4(r29)
  addi      r30, r30, 0x1
  stwx      r3, r4, r31
  addi      r31, r31, 0x4

.loc_0x58:
  lwz       r0, 0x0(r29)
  cmpw      r30, r0
  blt+      .loc_0x30
  mr        r3, r29
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013A584
 * Size:	000540
 */
void TaiOtimotiParameters::TaiOtimotiParameters()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802D
  stw       r0, 0x4(r1)
  li        r5, 0x3E
  stwu      r1, -0x100(r1)
  stw       r31, 0xFC(r1)
  subi      r31, r4, 0x55F8
  li        r4, 0x15
  stw       r30, 0xF8(r1)
  addi      r30, r3, 0
  bl        0x1179C
  lis       r3, 0x802D
  subi      r0, r3, 0x4E9C
  stw       r0, 0x0(r30)
  li        r0, 0x14
  li        r3, 0x32
  lwz       r4, 0x84(r30)
  li        r10, 0x33
  li        r9, 0x34
  lwz       r4, 0x0(r4)
  li        r8, 0x35
  mulli     r0, r0, 0xC
  lwz       r4, 0x8(r4)
  add       r4, r4, r0
  addi      r0, r31, 0x1C
  stw       r0, 0x0(r4)
  li        r0, 0
  li        r7, 0x36
  stw       r0, 0x4(r4)
  li        r0, 0xA
  li        r6, 0x37
  stw       r0, 0x8(r4)
  li        r5, 0x38
  li        r4, 0x39
  lwz       r11, 0x84(r30)
  mulli     r12, r3, 0xC
  lwz       r3, 0x4(r11)
  addi      r11, r31, 0x38
  lwz       r3, 0x8(r3)
  mulli     r10, r10, 0xC
  add       r12, r3, r12
  stw       r11, 0x0(r12)
  mulli     r9, r9, 0xC
  lfs       f8, -0x5AE0(r2)
  mulli     r8, r8, 0xC
  stfs      f8, 0x4(r12)
  lfs       f1, -0x5ADC(r2)
  mulli     r7, r7, 0xC
  stfs      f1, 0x8(r12)
  add       r11, r3, r10
  addi      r10, r31, 0x48
  stw       r10, 0x0(r11)
  mulli     r6, r6, 0xC
  stfs      f8, 0x4(r11)
  add       r10, r3, r9
  stfs      f1, 0x8(r11)
  addi      r9, r31, 0x5C
  mulli     r5, r5, 0xC
  stw       r9, 0x0(r10)
  stfs      f8, 0x4(r10)
  mulli     r4, r4, 0xC
  lfs       f7, -0x5AD8(r2)
  add       r9, r3, r8
  stfs      f7, 0x8(r10)
  addi      r8, r31, 0x70
  add       r10, r3, r7
  stw       r8, 0x0(r9)
  addi      r7, r31, 0x8C
  add       r8, r3, r6
  stfs      f8, 0x4(r9)
  addi      r6, r31, 0xA0
  add       r11, r3, r5
  lfs       f6, -0x5AD4(r2)
  addi      r5, r31, 0xBC
  add       r12, r3, r4
  stfs      f6, 0x8(r9)
  addi      r4, r31, 0xD0
  stw       r7, 0x0(r10)
  stfs      f8, 0x4(r10)
  stfs      f7, 0x8(r10)
  stw       r6, 0x0(r8)
  stfs      f8, 0x4(r8)
  stfs      f6, 0x8(r8)
  stw       r5, 0x0(r11)
  stfs      f8, 0x4(r11)
  lfs       f2, -0x5AD0(r2)
  stfs      f2, 0x8(r11)
  stw       r4, 0x0(r12)
  stfs      f8, 0x4(r12)
  li        r4, 0x3A
  stfs      f7, 0x8(r12)
  mulli     r4, r4, 0xC
  add       r5, r3, r4
  addi      r4, r31, 0xE4
  stw       r4, 0x0(r5)
  li        r4, 0x3B
  mulli     r4, r4, 0xC
  stfs      f8, 0x4(r5)
  stfs      f7, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0xFC
  stw       r4, 0x0(r5)
  li        r4, 0x3C
  mulli     r4, r4, 0xC
  stfs      f8, 0x4(r5)
  stfs      f7, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0x114
  stw       r4, 0x0(r5)
  li        r4, 0x3D
  mulli     r4, r4, 0xC
  stfs      f8, 0x4(r5)
  stfs      f6, 0x8(r5)
  add       r4, r3, r4
  addi      r3, r31, 0x134
  stw       r3, 0x0(r4)
  li        r12, 0x1
  li        r11, -0x1
  stfs      f8, 0x4(r4)
  li        r10, 0x5
  li        r9, 0xF
  stfs      f6, 0x8(r4)
  li        r8, 0x19
  li        r7, 0x12
  lwz       r4, 0x84(r30)
  li        r6, 0x28
  li        r5, 0x46
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r12, 0x0(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r12, 0x18(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r11, 0xC(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r10, 0x28(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r9, 0x2C(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r8, 0x30(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r0, 0x34(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r7, 0x38(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r6, 0x3C(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r5, 0x40(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5ACC(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x0(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x8(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f6, 0x4(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f2, 0xC(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5AC8(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x10(r3)
  lfs       f1, -0x1CA4(r13)
  lfs       f0, -0x5AC4(r2)
  lwz       r3, 0x4(r4)
  fmuls     f0, f1, f0
  lwz       r3, 0x0(r3)
  stfs      f0, 0x14(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5AC0(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x18(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5ABC(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x1C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f7, 0x70(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5AB8(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x20(r3)
  lwz       r3, 0x4(r4)
  lfs       f1, -0x5AB4(r2)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x24(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5AB0(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x28(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5AAC(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xB4(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x30(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f6, 0x38(r3)
  lwz       r3, 0x4(r4)
  lfs       f5, -0x5AA8(r2)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x3C(r3)
  lwz       r3, 0x4(r4)
  lfs       f4, -0x5AA4(r2)
  lwz       r3, 0x0(r3)
  stfs      f4, 0x40(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5AA0(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x44(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5A9C(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x48(r3)
  lwz       r3, 0x4(r4)
  lfs       f3, -0x5A98(r2)
  lwz       r3, 0x0(r3)
  stfs      f3, 0x4C(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5A94(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x50(r3)
  lwz       r3, 0x4(r4)
  lfs       f2, -0x5A90(r2)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x54(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x6C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f7, 0x74(r3)
  lwz       r3, 0x4(r4)
  lfs       f1, -0x5A8C(r2)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x78(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5A88(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x7C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f6, 0x80(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5A84(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x84(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f8, 0x88(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f8, 0x8C(r3)
  lwz       r5, 0x4(r4)
  mr        r3, r30
  lwz       r5, 0x0(r5)
  stfs      f8, 0x90(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f8, 0x94(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f4, 0x9C(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f5, 0xA0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f6, 0xAC(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5A80(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xB0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f7, 0xC8(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5A7C(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xCC(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5A78(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xD0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f1, 0xD4(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f3, 0xD8(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5A74(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xDC(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f3, 0xE0(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5A70(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xE4(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5A6C(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xE8(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f2, 0xEC(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f8, 0xF0(r5)
  lwz       r4, 0x4(r4)
  lfs       f0, -0x5A68(r2)
  lwz       r4, 0x0(r4)
  stfs      f0, 0xF4(r4)
  lwz       r0, 0x104(r1)
  lwz       r31, 0xFC(r1)
  lwz       r30, 0xF8(r1)
  addi      r1, r1, 0x100
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013AAC4
 * Size:	000084
 */
void TaiBlackFrogSoundTable::TaiBlackFrogSoundTable()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0xA
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  bl        -0x1BA70
  li        r30, 0
  li        r31, 0
  b         .loc_0x58

.loc_0x30:
  li        r3, 0x4
  bl        -0xF3AF4
  cmplwi    r3, 0
  beq-      .loc_0x48
  addi      r0, r30, 0xA
  stw       r0, 0x0(r3)

.loc_0x48:
  lwz       r4, 0x4(r29)
  addi      r30, r30, 0x1
  stwx      r3, r4, r31
  addi      r31, r31, 0x4

.loc_0x58:
  lwz       r0, 0x0(r29)
  cmpw      r30, r0
  blt+      .loc_0x30
  mr        r3, r29
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013AB48
 * Size:	00053C
 */
void TaiBlackFrogParameters::TaiBlackFrogParameters()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802D
  stw       r0, 0x4(r1)
  li        r5, 0x3E
  stwu      r1, -0x100(r1)
  stw       r31, 0xFC(r1)
  subi      r31, r4, 0x55F8
  li        r4, 0x15
  stw       r30, 0xF8(r1)
  addi      r30, r3, 0
  bl        0x111D8
  lis       r3, 0x802D
  subi      r0, r3, 0x4F08
  stw       r0, 0x0(r30)
  li        r0, 0x14
  li        r3, 0x32
  lwz       r4, 0x84(r30)
  li        r10, 0x33
  li        r9, 0x34
  lwz       r4, 0x0(r4)
  li        r8, 0x35
  mulli     r0, r0, 0xC
  lwz       r4, 0x8(r4)
  add       r4, r4, r0
  addi      r0, r31, 0x1C
  stw       r0, 0x0(r4)
  li        r0, 0
  li        r7, 0x36
  stw       r0, 0x4(r4)
  li        r0, 0xA
  li        r6, 0x37
  stw       r0, 0x8(r4)
  li        r5, 0x38
  li        r4, 0x39
  lwz       r11, 0x84(r30)
  mulli     r12, r3, 0xC
  lwz       r3, 0x4(r11)
  addi      r11, r31, 0x38
  lwz       r3, 0x8(r3)
  mulli     r10, r10, 0xC
  add       r12, r3, r12
  stw       r11, 0x0(r12)
  mulli     r9, r9, 0xC
  lfs       f9, -0x5AE0(r2)
  mulli     r8, r8, 0xC
  stfs      f9, 0x4(r12)
  lfs       f1, -0x5ADC(r2)
  mulli     r7, r7, 0xC
  stfs      f1, 0x8(r12)
  add       r11, r3, r10
  addi      r10, r31, 0x48
  stw       r10, 0x0(r11)
  mulli     r6, r6, 0xC
  stfs      f9, 0x4(r11)
  add       r10, r3, r9
  stfs      f1, 0x8(r11)
  addi      r9, r31, 0x5C
  mulli     r5, r5, 0xC
  stw       r9, 0x0(r10)
  stfs      f9, 0x4(r10)
  mulli     r4, r4, 0xC
  lfs       f8, -0x5AD8(r2)
  add       r9, r3, r8
  stfs      f8, 0x8(r10)
  addi      r8, r31, 0x70
  add       r10, r3, r7
  stw       r8, 0x0(r9)
  addi      r7, r31, 0x8C
  add       r8, r3, r6
  stfs      f9, 0x4(r9)
  addi      r6, r31, 0xA0
  add       r11, r3, r5
  lfs       f7, -0x5AD4(r2)
  addi      r5, r31, 0xBC
  add       r12, r3, r4
  stfs      f7, 0x8(r9)
  addi      r4, r31, 0xD0
  stw       r7, 0x0(r10)
  stfs      f9, 0x4(r10)
  stfs      f8, 0x8(r10)
  stw       r6, 0x0(r8)
  stfs      f9, 0x4(r8)
  stfs      f7, 0x8(r8)
  stw       r5, 0x0(r11)
  stfs      f9, 0x4(r11)
  lfs       f2, -0x5AD0(r2)
  stfs      f2, 0x8(r11)
  stw       r4, 0x0(r12)
  stfs      f9, 0x4(r12)
  li        r4, 0x3A
  stfs      f8, 0x8(r12)
  mulli     r4, r4, 0xC
  add       r5, r3, r4
  addi      r4, r31, 0xE4
  stw       r4, 0x0(r5)
  li        r4, 0x3B
  mulli     r4, r4, 0xC
  stfs      f9, 0x4(r5)
  stfs      f8, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0xFC
  stw       r4, 0x0(r5)
  li        r4, 0x3C
  mulli     r4, r4, 0xC
  stfs      f9, 0x4(r5)
  stfs      f8, 0x8(r5)
  add       r5, r3, r4
  addi      r4, r31, 0x114
  stw       r4, 0x0(r5)
  li        r4, 0x3D
  mulli     r4, r4, 0xC
  stfs      f9, 0x4(r5)
  stfs      f7, 0x8(r5)
  add       r4, r3, r4
  addi      r3, r31, 0x134
  stw       r3, 0x0(r4)
  li        r12, 0x1
  li        r11, -0x1
  stfs      f9, 0x4(r4)
  li        r10, 0x5
  li        r9, 0xF
  stfs      f7, 0x8(r4)
  li        r8, 0x19
  li        r7, 0x12
  lwz       r4, 0x84(r30)
  li        r6, 0x28
  li        r5, 0x46
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r12, 0x0(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r12, 0x18(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r11, 0xC(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r10, 0x28(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r9, 0x2C(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r8, 0x30(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r0, 0x34(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r7, 0x38(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r6, 0x3C(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r5, 0x40(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5ACC(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x0(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x8(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f7, 0x4(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f2, 0xC(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5AC8(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x10(r3)
  lfs       f1, -0x1CA4(r13)
  lfs       f0, -0x5AC4(r2)
  lwz       r3, 0x4(r4)
  fmuls     f0, f1, f0
  lwz       r3, 0x0(r3)
  stfs      f0, 0x14(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5A64(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x18(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x1C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f8, 0x70(r3)
  lwz       r3, 0x4(r4)
  lfs       f6, -0x5AC0(r2)
  lwz       r3, 0x0(r3)
  stfs      f6, 0x20(r3)
  lwz       r3, 0x4(r4)
  lfs       f5, -0x5AB4(r2)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x24(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5AB0(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x28(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5AAC(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xB4(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x30(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f7, 0x38(r3)
  lwz       r3, 0x4(r4)
  lfs       f4, -0x5AA8(r2)
  lwz       r3, 0x0(r3)
  stfs      f4, 0x3C(r3)
  lwz       r3, 0x4(r4)
  lfs       f3, -0x5AA4(r2)
  lwz       r3, 0x0(r3)
  stfs      f3, 0x40(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5AA0(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x44(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5A9C(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x48(r3)
  lwz       r3, 0x4(r4)
  lfs       f2, -0x5A98(r2)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x4C(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5A94(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x50(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5A90(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x54(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x6C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f8, 0x74(r3)
  lwz       r3, 0x4(r4)
  lfs       f1, -0x5A8C(r2)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x78(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5A88(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x7C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f7, 0x80(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5A60(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x84(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f9, 0x88(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f9, 0x8C(r3)
  lwz       r5, 0x4(r4)
  mr        r3, r30
  lwz       r5, 0x0(r5)
  stfs      f9, 0x90(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5A5C(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x94(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f3, 0x9C(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f4, 0xA0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f7, 0xAC(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5A80(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xB0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f6, 0xC8(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5A7C(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xCC(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5A78(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xD0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f1, 0xD4(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f2, 0xD8(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5A74(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xDC(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f2, 0xE0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f3, 0xE4(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f5, 0xE8(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5A70(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xEC(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f9, 0xF0(r5)
  lwz       r4, 0x4(r4)
  lfs       f0, -0x5A58(r2)
  lwz       r4, 0x0(r4)
  stfs      f0, 0xF4(r4)
  lwz       r0, 0x104(r1)
  lwz       r31, 0xFC(r1)
  lwz       r30, 0xF8(r1)
  addi      r1, r1, 0x100
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013B084
 * Size:	00161C
 */
void TaiOtimotiStrategy::TaiOtimotiStrategy(TekiParameters *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x2
  stw       r0, 0x4(r1)
  stwu      r1, -0x298(r1)
  stmw      r14, 0x250(r1)
  mr        r26, r3
  stw       r4, 0x230(r1)
  li        r4, 0x11
  bl        -0x13CC0
  lis       r3, 0x802D
  subi      r0, r3, 0x5018
  stw       r0, 0x0(r26)
  li        r3, 0x8
  bl        -0xF40B4
  stw       r3, 0x244(r1)
  lwz       r0, 0x244(r1)
  cmplwi    r0, 0
  beq-      .loc_0x74
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  lwz       r3, 0x244(r1)
  lis       r4, 0x802C
  stw       r0, 0x4(r3)
  li        r0, -0x1
  lwz       r3, 0x244(r1)
  stw       r0, 0x0(r3)
  addi      r0, r4, 0x6A60
  lwz       r3, 0x244(r1)
  stw       r0, 0x4(r3)

.loc_0x74:
  li        r3, 0x8
  bl        -0xF40F8
  addi      r18, r3, 0
  mr.       r0, r18
  beq-      .loc_0xA8
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r18)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r18)
  subi      r0, r3, 0x6140
  stw       r0, 0x4(r18)

.loc_0xA8:
  li        r3, 0x8
  bl        -0xF412C
  stw       r3, 0x240(r1)
  lwz       r0, 0x240(r1)
  cmplwi    r0, 0
  beq-      .loc_0xEC
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  lwz       r3, 0x240(r1)
  lis       r4, 0x802D
  stw       r0, 0x4(r3)
  li        r0, -0x1
  lwz       r3, 0x240(r1)
  stw       r0, 0x0(r3)
  subi      r0, r4, 0x6318
  lwz       r3, 0x240(r1)
  stw       r0, 0x4(r3)

.loc_0xEC:
  li        r3, 0x8
  bl        -0xF4170
  stw       r3, 0x23C(r1)
  lwz       r0, 0x23C(r1)
  cmplwi    r0, 0
  beq-      .loc_0x130
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  lwz       r3, 0x23C(r1)
  lis       r4, 0x802D
  stw       r0, 0x4(r3)
  li        r0, -0x1
  lwz       r3, 0x23C(r1)
  stw       r0, 0x0(r3)
  subi      r0, r4, 0x6358
  lwz       r3, 0x23C(r1)
  stw       r0, 0x4(r3)

.loc_0x130:
  li        r3, 0x8
  bl        -0xF41B4
  stw       r3, 0x238(r1)
  lwz       r0, 0x238(r1)
  cmplwi    r0, 0
  beq-      .loc_0x174
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  lwz       r3, 0x238(r1)
  lis       r4, 0x802D
  stw       r0, 0x4(r3)
  li        r0, -0x1
  lwz       r3, 0x238(r1)
  stw       r0, 0x0(r3)
  subi      r0, r4, 0x6290
  lwz       r3, 0x238(r1)
  stw       r0, 0x4(r3)

.loc_0x174:
  li        r3, 0x8
  bl        -0xF41F8
  addi      r23, r3, 0
  mr.       r0, r23
  beq-      .loc_0x1A8
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r23)
  li        r0, 0
  lis       r3, 0x802D
  stw       r0, 0x0(r23)
  subi      r0, r3, 0x42D8
  stw       r0, 0x4(r23)

.loc_0x1A8:
  li        r3, 0x8
  bl        -0xF422C
  addi      r19, r3, 0
  mr.       r0, r19
  beq-      .loc_0x1DC
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r19)
  li        r0, 0x6
  lis       r3, 0x802D
  stw       r0, 0x0(r19)
  subi      r0, r3, 0x50D0
  stw       r0, 0x4(r19)

.loc_0x1DC:
  li        r3, 0x8
  bl        -0xF4260
  addi      r17, r3, 0
  mr.       r0, r17
  beq-      .loc_0x210
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r17)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r17)
  subi      r0, r3, 0x46B0
  stw       r0, 0x4(r17)

.loc_0x210:
  li        r3, 0x8
  bl        -0xF4294
  addi      r16, r3, 0
  mr.       r0, r16
  beq-      .loc_0x244
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r16)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r16)
  subi      r0, r3, 0x46F8
  stw       r0, 0x4(r16)

.loc_0x244:
  li        r3, 0x8
  bl        -0xF42C8
  stw       r3, 0x248(r1)
  lwz       r0, 0x248(r1)
  cmplwi    r0, 0
  beq-      .loc_0x288
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  lwz       r3, 0x248(r1)
  lis       r4, 0x802D
  stw       r0, 0x4(r3)
  li        r0, -0x1
  lwz       r3, 0x248(r1)
  stw       r0, 0x0(r3)
  subi      r0, r4, 0x7B5C
  lwz       r3, 0x248(r1)
  stw       r0, 0x4(r3)

.loc_0x288:
  li        r3, 0x8
  bl        -0xF430C
  addi      r20, r3, 0
  mr.       r0, r20
  beq-      .loc_0x2BC
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r20)
  li        r0, 0x5
  lis       r3, 0x802D
  stw       r0, 0x0(r20)
  subi      r0, r3, 0x7B5C
  stw       r0, 0x4(r20)

.loc_0x2BC:
  li        r3, 0x8
  bl        -0xF4340
  addi      r21, r3, 0
  mr.       r0, r21
  beq-      .loc_0x2F0
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r21)
  li        r0, 0x5
  lis       r3, 0x802D
  stw       r0, 0x0(r21)
  subi      r0, r3, 0x46F8
  stw       r0, 0x4(r21)

.loc_0x2F0:
  li        r3, 0x8
  bl        -0xF4374
  addi      r14, r3, 0
  mr.       r0, r14
  beq-      .loc_0x324
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r14)
  li        r0, 0x2
  lis       r3, 0x802D
  stw       r0, 0x0(r14)
  subi      r0, r3, 0x7A98
  stw       r0, 0x4(r14)

.loc_0x324:
  li        r3, 0x8
  bl        -0xF43A8
  addi      r15, r3, 0
  mr.       r0, r15
  beq-      .loc_0x358
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r15)
  li        r0, 0x6
  lis       r3, 0x802C
  stw       r0, 0x0(r15)
  addi      r0, r3, 0x69A4
  stw       r0, 0x4(r15)

.loc_0x358:
  li        r3, 0xC
  bl        -0xF43DC
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x3A4
  lwz       r3, 0x230(r1)
  lis       r4, 0x802C
  addi      r4, r4, 0x6620
  lwz       r5, 0x84(r3)
  lis       r3, 0x802D
  li        r0, 0xE
  lwz       r5, 0x4(r5)
  subi      r3, r3, 0x7AD4
  lwz       r5, 0x0(r5)
  lfs       f0, 0x3C(r5)
  stw       r4, 0x4(r25)
  stw       r0, 0x0(r25)
  stw       r3, 0x4(r25)
  stfs      f0, 0x8(r25)

.loc_0x3A4:
  li        r3, 0x8
  bl        -0xF4428
  cmplwi    r3, 0
  beq-      .loc_0x3D4
  lis       r4, 0x802C
  addi      r0, r4, 0x6620
  stw       r0, 0x4(r3)
  li        r0, 0x1
  lis       r4, 0x802D
  stw       r0, 0x0(r3)
  subi      r0, r4, 0x4580
  stw       r0, 0x4(r3)

.loc_0x3D4:
  li        r3, 0x8
  bl        -0xF4458
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x408
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r24)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r24)
  subi      r0, r3, 0x45B8
  stw       r0, 0x4(r24)

.loc_0x408:
  li        r3, 0x8
  bl        -0xF448C
  addi      r22, r3, 0
  mr.       r0, r22
  beq-      .loc_0x43C
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r22)
  li        r0, 0x5
  lis       r3, 0x802D
  stw       r0, 0x0(r22)
  subi      r0, r3, 0x45FC
  stw       r0, 0x4(r22)

.loc_0x43C:
  li        r3, 0x24
  bl        -0xF44C0
  stw       r3, 0x234(r1)
  lwz       r3, 0x234(r1)
  cmplwi    r3, 0
  beq-      .loc_0x45C
  lfs       f1, -0x5A54(r2)
  bl        0x2504

.loc_0x45C:
  li        r3, 0xC
  bl        -0xF44E0
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x4A4
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r29)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r29)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r29)
  li        r0, 0
  subi      r3, r3, 0x447C
  stw       r0, 0x8(r29)
  stw       r3, 0x4(r29)

.loc_0x4A4:
  li        r3, 0x8
  bl        -0xF4528
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0x4D8
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x43C0
  stw       r0, 0x4(r27)

.loc_0x4D8:
  li        r3, 0xC
  bl        -0xF455C
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x4F4
  li        r4, 0x3
  bl        -0x144DC

.loc_0x4F4:
  li        r0, 0
  lwz       r3, 0x8(r28)
  rlwinm    r0,r0,2,0,29
  stwx      r18, r3, r0
  li        r4, 0x1
  li        r0, 0x2
  lwz       r3, 0x8(r28)
  rlwinm    r4,r4,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r27, r3, r4
  li        r3, 0xC
  lwz       r4, 0x8(r28)
  stwx      r29, r4, r0
  lwz       r4, 0x8(r26)
  stw       r28, 0x0(r4)
  bl        -0xF45B0
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x574
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r29)
  li        r0, 0x2
  lis       r3, 0x802D
  stw       r0, 0x0(r29)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r29)
  li        r0, 0x1
  subi      r3, r3, 0x4650
  stw       r0, 0x8(r29)
  stw       r3, 0x4(r29)

.loc_0x574:
  li        r3, 0xC
  bl        -0xF45F8
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x590
  li        r4, 0x4
  bl        -0x14578

.loc_0x590:
  li        r0, 0
  lwz       r3, 0x8(r28)
  rlwinm    r0,r0,2,0,29
  stwx      r23, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r4, 0x8(r28)
  rlwinm    r0,r0,2,0,29
  li        r3, 0x3
  stwx      r19, r4, r0
  rlwinm    r0,r5,2,0,29
  rlwinm    r5,r3,2,0,29
  lwz       r4, 0x8(r28)
  li        r3, 0x18
  stwx      r24, r4, r0
  lwz       r4, 0x8(r28)
  stwx      r29, r4, r5
  lwz       r4, 0x8(r26)
  stw       r28, 0x4(r4)
  bl        -0xF465C
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x648
  lwz       r3, 0x230(r1)
  lis       r5, 0x802D
  subi      r6, r5, 0x35D8
  lwz       r4, 0x84(r3)
  lis       r3, 0x802C
  addi      r3, r3, 0x6620
  lwz       r4, 0x4(r4)
  li        r0, 0x4
  li        r5, 0
  lwz       r4, 0x0(r4)
  lis       r7, 0x802D
  lfs       f1, 0xD4(r4)
  lfs       f0, 0xD0(r4)
  subi      r4, r7, 0x3670
  stw       r3, 0x4(r29)
  stw       r0, 0x0(r29)
  stw       r6, 0x4(r29)
  stw       r5, 0x8(r29)
  stfs      f0, 0xC(r29)
  lfs       f0, -0x5AC4(r2)
  stfs      f0, 0x10(r29)
  stw       r4, 0x4(r29)
  stfs      f1, 0x14(r29)

.loc_0x648:
  li        r3, 0x18
  bl        -0xF46CC
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x6B8
  lwz       r3, 0x230(r1)
  lis       r5, 0x802C
  lis       r4, 0x802D
  lwz       r3, 0x84(r3)
  addi      r5, r5, 0x6620
  li        r6, 0x3
  lwz       r3, 0x4(r3)
  subi      r4, r4, 0x35D8
  li        r0, 0x1
  lwz       r3, 0x0(r3)
  lis       r7, 0x802D
  lfs       f1, 0xD4(r3)
  lfs       f0, 0xD8(r3)
  subi      r3, r7, 0x3670
  stw       r5, 0x4(r30)
  stw       r6, 0x0(r30)
  stw       r4, 0x4(r30)
  stw       r0, 0x8(r30)
  stfs      f0, 0xC(r30)
  lfs       f0, -0x5AC4(r2)
  stfs      f0, 0x10(r30)
  stw       r3, 0x4(r30)
  stfs      f1, 0x14(r30)

.loc_0x6B8:
  li        r3, 0xC
  bl        -0xF473C
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x6F4
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r3, r3, 0x6A6C
  li        r0, 0x2
  stw       r3, 0x4(r28)
  stw       r0, 0x8(r28)

.loc_0x6F4:
  li        r3, 0xC
  bl        -0xF4778
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x710
  li        r4, 0xA
  bl        -0x146F8

.loc_0x710:
  li        r0, 0
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  stwx      r18, r3, r0
  li        r3, 0x1
  li        r0, 0x2
  lwz       r4, 0x8(r31)
  rlwinm    r3,r3,2,0,29
  li        r7, 0x3
  stwx      r23, r4, r3
  li        r5, 0x4
  li        r6, 0x5
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  li        r8, 0x6
  stwx      r19, r3, r0
  li        r3, 0x7
  li        r10, 0x8
  lwz       r4, 0x8(r31)
  rlwinm    r0,r7,2,0,29
  li        r9, 0x9
  stwx      r25, r4, r0
  rlwinm    r0,r5,2,0,29
  rlwinm    r5,r6,2,0,29
  lwz       r4, 0x8(r31)
  rlwinm    r7,r8,2,0,29
  rlwinm    r8,r3,2,0,29
  stwx      r22, r4, r0
  rlwinm    r0,r10,2,0,29
  rlwinm    r6,r9,2,0,29
  lwz       r4, 0x8(r31)
  li        r3, 0xC
  stwx      r21, r4, r5
  lwz       r4, 0x8(r31)
  stwx      r20, r4, r7
  lwz       r4, 0x8(r31)
  stwx      r30, r4, r8
  lwz       r4, 0x8(r31)
  stwx      r29, r4, r0
  lwz       r4, 0x8(r31)
  stwx      r28, r4, r6
  lwz       r4, 0x8(r26)
  stw       r31, 0x8(r4)
  bl        -0xF483C
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x7F4
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, 0x2
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r3, r3, 0x6A6C
  li        r0, 0x5
  stw       r3, 0x4(r28)
  stw       r0, 0x8(r28)

.loc_0x7F4:
  li        r3, 0xC
  bl        -0xF4878
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x810
  li        r4, 0x6
  bl        -0x147F8

.loc_0x810:
  li        r0, 0
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  stwx      r23, r3, r0
  li        r0, 0x1
  li        r6, 0x2
  lwz       r3, 0x8(r29)
  rlwinm    r4,r0,2,0,29
  li        r0, 0x3
  stwx      r19, r3, r4
  li        r4, 0x4
  li        r5, 0x5
  lwz       r3, 0x8(r29)
  rlwinm    r6,r6,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r22, r3, r6
  rlwinm    r4,r4,2,0,29
  rlwinm    r6,r5,2,0,29
  lwz       r5, 0x8(r29)
  li        r3, 0xC
  stwx      r21, r5, r0
  lwz       r5, 0x8(r29)
  stwx      r20, r5, r4
  lwz       r4, 0x8(r29)
  stwx      r28, r4, r6
  lwz       r4, 0x8(r26)
  stw       r29, 0x10(r4)
  bl        -0xF48FC
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x8C0
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r30)
  li        r0, 0x2
  lis       r3, 0x802D
  stw       r0, 0x0(r30)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r30)
  li        r0, 0x4
  subi      r3, r3, 0x3540
  stw       r0, 0x8(r30)
  stw       r3, 0x4(r30)

.loc_0x8C0:
  li        r3, 0xC
  bl        -0xF4944
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x8DC
  li        r4, 0x6
  bl        -0x148C4

.loc_0x8DC:
  li        r0, 0
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  stwx      r23, r3, r0
  li        r0, 0x1
  li        r6, 0x2
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  li        r5, 0x3
  stwx      r19, r3, r0
  li        r0, 0x4
  li        r4, 0x5
  lwz       r3, 0x8(r29)
  rlwinm    r6,r6,2,0,29
  rlwinm    r5,r5,2,0,29
  stwx      r22, r3, r6
  rlwinm    r0,r0,2,0,29
  rlwinm    r6,r4,2,0,29
  lwz       r4, 0x8(r29)
  li        r3, 0x10
  stwx      r21, r4, r5
  lwz       r4, 0x8(r29)
  stwx      r20, r4, r0
  lwz       r4, 0x8(r29)
  stwx      r30, r4, r6
  lwz       r4, 0x8(r26)
  stw       r29, 0xC(r4)
  bl        -0xF49C8
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x9B0
  lwz       r3, 0x230(r1)
  lis       r7, 0x802C
  lis       r6, 0x802D
  lwz       r3, 0x84(r3)
  lis       r5, 0x802D
  lis       r4, 0x802D
  lwz       r3, 0x4(r3)
  addi      r7, r7, 0x6620
  li        r0, -0x1
  lwz       r3, 0x0(r3)
  subi      r6, r6, 0x6A6C
  subi      r5, r5, 0x6A8C
  lfs       f0, 0x14(r3)
  li        r3, 0x4
  subi      r4, r4, 0x6650
  stw       r7, 0x4(r29)
  stw       r0, 0x0(r29)
  stw       r6, 0x4(r29)
  stw       r3, 0x8(r29)
  stw       r5, 0x4(r29)
  stw       r4, 0x4(r29)
  stfs      f0, 0xC(r29)

.loc_0x9B0:
  li        r3, 0x8
  bl        -0xF4A34
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0x9E4
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x48A8
  stw       r0, 0x4(r27)

.loc_0x9E4:
  li        r3, 0xC
  bl        -0xF4A68
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0xA00
  li        r4, 0xB
  bl        -0x149E8

.loc_0xA00:
  li        r0, 0
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  stwx      r23, r3, r0
  li        r0, 0x1
  li        r4, 0x2
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  li        r5, 0x3
  stwx      r18, r3, r0
  li        r0, 0x4
  rlwinm    r4,r4,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r5,r5,2,0,29
  rlwinm    r6,r0,2,0,29
  stwx      r19, r3, r4
  li        r9, 0x5
  li        r3, 0x7
  lwz       r4, 0x8(r31)
  rlwinm    r0,r9,2,0,29
  li        r8, 0x6
  stwx      r27, r4, r5
  li        r7, 0x8
  li        r4, 0xA
  lwz       r5, 0x8(r31)
  rlwinm    r9,r8,2,0,29
  li        r10, 0x9
  stwx      r17, r5, r6
  rlwinm    r6,r3,2,0,29
  rlwinm    r5,r7,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r7,r4,2,0,29
  rlwinm    r8,r10,2,0,29
  stwx      r16, r3, r0
  li        r3, 0x8
  lwz       r0, 0x248(r1)
  lwz       r4, 0x8(r31)
  stwx      r0, r4, r9
  lwz       r4, 0x8(r31)
  stwx      r24, r4, r6
  lwz       r4, 0x8(r31)
  stwx      r15, r4, r5
  lwz       r4, 0x8(r31)
  stwx      r14, r4, r8
  lwz       r4, 0x8(r31)
  stwx      r29, r4, r7
  lwz       r4, 0x8(r26)
  stw       r31, 0x14(r4)
  bl        -0xF4B40
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0xAF0
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, 0x7
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x515C
  stw       r0, 0x4(r27)

.loc_0xAF0:
  li        r3, 0x8
  bl        -0xF4B74
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0xB24
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, 0x8
  lis       r3, 0x802C
  stw       r0, 0x0(r28)
  addi      r0, r3, 0x6DDC
  stw       r0, 0x4(r28)

.loc_0xB24:
  li        r3, 0xC
  bl        -0xF4BA8
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0xB40
  li        r4, 0x5
  bl        -0x14B28

.loc_0xB40:
  li        r0, 0
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  stwx      r18, r3, r0
  li        r0, 0x1
  li        r4, 0x2
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  li        r5, 0x3
  stwx      r23, r3, r0
  li        r0, 0x4
  rlwinm    r4,r4,2,0,29
  lwz       r3, 0x8(r29)
  rlwinm    r5,r5,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r24, r3, r4
  li        r3, 0xC
  lwz       r4, 0x8(r29)
  stwx      r27, r4, r5
  lwz       r4, 0x8(r29)
  stwx      r28, r4, r0
  lwz       r4, 0x8(r26)
  stw       r29, 0x18(r4)
  bl        -0xF4C1C
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0xBD4
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r29)
  li        r0, 0x2
  lis       r3, 0x802D
  stw       r0, 0x0(r29)
  subi      r3, r3, 0x6A6C
  li        r0, 0x1
  stw       r3, 0x4(r29)
  stw       r0, 0x8(r29)

.loc_0xBD4:
  li        r3, 0xC
  bl        -0xF4C58
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0xBF0
  li        r4, 0x3
  bl        -0x14BD8

.loc_0xBF0:
  li        r0, 0
  lwz       r3, 0x8(r28)
  rlwinm    r0,r0,2,0,29
  stwx      r23, r3, r0
  li        r4, 0x1
  li        r0, 0x2
  lwz       r3, 0x8(r28)
  rlwinm    r4,r4,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r24, r3, r4
  li        r3, 0xC
  lwz       r4, 0x8(r28)
  stwx      r29, r4, r0
  lwz       r4, 0x8(r26)
  stw       r28, 0x1C(r4)
  bl        -0xF4CAC
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0xC64
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, 0x9
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r0, r3, 0x6B20
  stw       r0, 0x4(r28)
  lwz       r0, -0x99C(r13)
  stw       r0, 0x8(r28)

.loc_0xC64:
  li        r3, 0xC
  bl        -0xF4CE8
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0xCA0
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r29)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r29)
  subi      r3, r3, 0x6A6C
  li        r0, 0x9
  stw       r3, 0x4(r29)
  stw       r0, 0x8(r29)

.loc_0xCA0:
  li        r3, 0xC
  bl        -0xF4D24
  addi      r27, r3, 0
  mr.       r3, r27
  beq-      .loc_0xCBC
  li        r4, 0x3
  bl        -0x14CA4

.loc_0xCBC:
  li        r0, 0
  lwz       r3, 0x8(r27)
  rlwinm    r0,r0,2,0,29
  stwx      r24, r3, r0
  li        r4, 0x1
  li        r0, 0x2
  lwz       r3, 0x8(r27)
  rlwinm    r4,r4,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r29, r3, r4
  li        r3, 0x8
  lwz       r4, 0x8(r27)
  stwx      r28, r4, r0
  lwz       r4, 0x8(r26)
  stw       r27, 0x20(r4)
  bl        -0xF4D78
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0xD28
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, 0xA
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x51A0
  stw       r0, 0x4(r27)

.loc_0xD28:
  li        r3, 0x8
  bl        -0xF4DAC
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0xD5C
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r0, r3, 0x5084
  stw       r0, 0x4(r28)

.loc_0xD5C:
  li        r3, 0xC
  bl        -0xF4DE0
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0xD78
  li        r4, 0x6
  bl        -0x14D60

.loc_0xD78:
  li        r0, 0
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  stwx      r24, r3, r0
  li        r4, 0x1
  rlwinm    r5,r4,2,0,29
  lwz       r4, 0x23C(r1)
  lwz       r3, 0x8(r29)
  li        r7, 0x3
  stwx      r4, r3, r5
  li        r0, 0x2
  rlwinm    r3,r0,2,0,29
  lwz       r0, 0x238(r1)
  lwz       r6, 0x8(r29)
  li        r5, 0x5
  stwx      r0, r6, r3
  li        r4, 0x4
  rlwinm    r0,r4,2,0,29
  lwz       r4, 0x8(r29)
  rlwinm    r7,r7,2,0,29
  rlwinm    r5,r5,2,0,29
  stwx      r27, r4, r7
  li        r3, 0x8
  lwz       r4, 0x8(r29)
  stwx      r28, r4, r0
  lwz       r0, 0x244(r1)
  lwz       r4, 0x8(r29)
  stwx      r0, r4, r5
  lwz       r4, 0x8(r26)
  stw       r29, 0x24(r4)
  bl        -0xF4E70
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0xE20
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, 0xB
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x51E0
  stw       r0, 0x4(r27)

.loc_0xE20:
  li        r3, 0xC
  bl        -0xF4EA4
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0xE5C
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r3, r3, 0x6A6C
  li        r0, 0x3
  stw       r3, 0x4(r28)
  stw       r0, 0x8(r28)

.loc_0xE5C:
  li        r3, 0xC
  bl        -0xF4EE0
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0xE78
  li        r4, 0x5
  bl        -0x14E60

.loc_0xE78:
  li        r0, 0
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  lwz       r6, 0x240(r1)
  stwx      r24, r3, r0
  li        r0, 0x1
  rlwinm    r5,r0,2,0,29
  lwz       r3, 0x8(r29)
  li        r0, 0x3
  li        r4, 0x2
  stwx      r28, r3, r5
  rlwinm    r3,r4,2,0,29
  li        r5, 0x4
  lwz       r4, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  rlwinm    r5,r5,2,0,29
  stwx      r6, r4, r3
  li        r3, 0x10
  lwz       r6, 0x238(r1)
  lwz       r4, 0x8(r29)
  stwx      r6, r4, r0
  lwz       r4, 0x8(r29)
  stwx      r27, r4, r5
  lwz       r4, 0x8(r26)
  stw       r29, 0x28(r4)
  bl        -0xF4F5C
  addi      r27, r3, 0
  mr.       r3, r27
  beq-      .loc_0xEF8
  li        r4, 0xC
  li        r5, 0x3
  bl        -0x15174

.loc_0xEF8:
  li        r3, 0x8
  bl        -0xF4F7C
  addi      r4, r3, 0
  mr.       r0, r4
  beq-      .loc_0xF2C
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r4)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r4)
  subi      r0, r3, 0x5224
  stw       r0, 0x4(r4)

.loc_0xF2C:
  lwz       r5, 0xC(r27)
  li        r3, 0x8
  stw       r4, 0x0(r5)
  bl        -0xF4FB8
  addi      r4, r3, 0
  mr.       r0, r4
  beq-      .loc_0xF68
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r4)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r4)
  subi      r0, r3, 0x5268
  stw       r0, 0x4(r4)

.loc_0xF68:
  lwz       r5, 0xC(r27)
  li        r3, 0x8
  stw       r4, 0x4(r5)
  bl        -0xF4FF4
  addi      r4, r3, 0
  mr.       r0, r4
  beq-      .loc_0xFA4
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r4)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r4)
  subi      r0, r3, 0x5340
  stw       r0, 0x4(r4)

.loc_0xFA4:
  lwz       r5, 0xC(r27)
  li        r3, 0xC
  stw       r4, 0x8(r5)
  bl        -0xF5030
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0xFE8
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r3, r3, 0x6A6C
  li        r0, 0xA
  stw       r3, 0x4(r28)
  stw       r0, 0x8(r28)

.loc_0xFE8:
  li        r3, 0xC
  bl        -0xF506C
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x1004
  li        r4, 0x4
  bl        -0x14FEC

.loc_0x1004:
  li        r0, 0
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  stwx      r18, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r4, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  li        r3, 0x3
  stwx      r24, r4, r0
  rlwinm    r0,r5,2,0,29
  rlwinm    r5,r3,2,0,29
  lwz       r4, 0x8(r29)
  li        r3, 0x8
  stwx      r28, r4, r0
  lwz       r4, 0x8(r29)
  stwx      r27, r4, r5
  lwz       r4, 0x8(r26)
  stw       r29, 0x2C(r4)
  bl        -0xF50D0
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0x1080
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, 0xD
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x5384
  stw       r0, 0x4(r27)

.loc_0x1080:
  li        r3, 0x8
  bl        -0xF5104
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x10B4
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r0, r3, 0x53C8
  stw       r0, 0x4(r28)

.loc_0x10B4:
  li        r3, 0xC
  bl        -0xF5138
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x10D0
  li        r4, 0x4
  bl        -0x150B8

.loc_0x10D0:
  li        r0, 0
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  stwx      r23, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r4, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  li        r3, 0x3
  stwx      r24, r4, r0
  rlwinm    r0,r5,2,0,29
  rlwinm    r5,r3,2,0,29
  lwz       r4, 0x8(r29)
  li        r3, 0x14
  stwx      r27, r4, r0
  lwz       r4, 0x8(r29)
  stwx      r28, r4, r5
  lwz       r4, 0x8(r26)
  stw       r29, 0x30(r4)
  bl        -0xF519C
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x1174
  lwz       r3, 0x230(r1)
  lis       r5, 0x802D
  subi      r6, r5, 0x35D8
  lwz       r4, 0x84(r3)
  lis       r3, 0x802C
  addi      r3, r3, 0x6620
  lwz       r4, 0x4(r4)
  li        r0, 0x2
  li        r5, 0
  lwz       r4, 0x0(r4)
  lfs       f0, 0x38(r4)
  stw       r3, 0x4(r29)
  stw       r0, 0x0(r29)
  stw       r6, 0x4(r29)
  stw       r5, 0x8(r29)
  stfs      f0, 0xC(r29)
  lfs       f0, -0x5AE0(r2)
  stfs      f0, 0x10(r29)

.loc_0x1174:
  li        r3, 0xC
  bl        -0xF51F8
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x11B0
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r3, r3, 0x6A6C
  li        r0, 0x2
  stw       r3, 0x4(r28)
  stw       r0, 0x8(r28)

.loc_0x11B0:
  li        r3, 0xC
  bl        -0xF5234
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x11CC
  li        r4, 0x5
  bl        -0x151B4

.loc_0x11CC:
  li        r0, 0
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,2,0,29
  stwx      r23, r3, r0
  li        r0, 0x1
  li        r4, 0x2
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,2,0,29
  li        r5, 0x3
  stwx      r19, r3, r0
  li        r0, 0x4
  rlwinm    r4,r4,2,0,29
  lwz       r3, 0x8(r30)
  rlwinm    r5,r5,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r24, r3, r4
  li        r3, 0x10
  lwz       r4, 0x8(r30)
  stwx      r29, r4, r5
  lwz       r4, 0x8(r30)
  stwx      r28, r4, r0
  lwz       r4, 0x8(r26)
  stw       r30, 0x34(r4)
  bl        -0xF52A8
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x1290
  lwz       r3, 0x230(r1)
  lis       r7, 0x802C
  lis       r6, 0x802D
  lwz       r3, 0x84(r3)
  lis       r5, 0x802D
  lis       r4, 0x802D
  lwz       r3, 0x4(r3)
  addi      r7, r7, 0x6620
  li        r0, 0xF
  lwz       r3, 0x0(r3)
  subi      r6, r6, 0x6A6C
  subi      r5, r5, 0x6A8C
  lfs       f0, 0x14(r3)
  li        r3, 0x4
  subi      r4, r4, 0x67CC
  stw       r7, 0x4(r30)
  stw       r0, 0x0(r30)
  stw       r6, 0x4(r30)
  stw       r3, 0x8(r30)
  stw       r5, 0x4(r30)
  stw       r4, 0x4(r30)
  stfs      f0, 0xC(r30)

.loc_0x1290:
  li        r3, 0x8
  bl        -0xF5314
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0x12C4
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x69B4
  stw       r0, 0x4(r27)

.loc_0x12C4:
  li        r3, 0xC
  bl        -0xF5348
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x12E0
  li        r4, 0x6
  bl        -0x152C8

.loc_0x12E0:
  li        r0, 0
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  stwx      r23, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r3, 0x8(r29)
  rlwinm    r4,r0,2,0,29
  li        r0, 0x3
  stwx      r18, r3, r4
  li        r3, 0x4
  li        r4, 0x5
  lwz       r6, 0x8(r29)
  rlwinm    r5,r5,2,0,29
  rlwinm    r7,r0,2,0,29
  stwx      r19, r6, r5
  rlwinm    r0,r3,2,0,29
  rlwinm    r5,r4,2,0,29
  lwz       r4, 0x8(r29)
  li        r3, 0x14
  stwx      r24, r4, r7
  lwz       r4, 0x8(r29)
  stwx      r27, r4, r0
  lwz       r4, 0x8(r29)
  stwx      r30, r4, r5
  lwz       r4, 0x8(r26)
  stw       r29, 0x38(r4)
  bl        -0xF53CC
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x13A4
  lwz       r3, 0x230(r1)
  lis       r4, 0x802C
  addi      r4, r4, 0x6620
  lwz       r5, 0x84(r3)
  lis       r3, 0x802D
  subi      r6, r3, 0x64D8
  lwz       r5, 0x4(r5)
  li        r0, 0x10
  li        r3, 0
  lwz       r5, 0x0(r5)
  lfs       f0, 0xE4(r5)
  lfs       f1, 0xE0(r5)
  stw       r4, 0x4(r30)
  stw       r0, 0x0(r30)
  stw       r6, 0x4(r30)
  stw       r3, 0x8(r30)
  stfs      f1, 0xC(r30)
  stfs      f0, 0x10(r30)

.loc_0x13A4:
  li        r3, 0xC
  bl        -0xF5428
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0x13F0
  lwz       r3, 0x230(r1)
  lis       r4, 0x802C
  addi      r4, r4, 0x6620
  lwz       r5, 0x84(r3)
  lis       r3, 0x802D
  li        r0, 0x10
  lwz       r5, 0x4(r5)
  subi      r3, r3, 0x7B18
  lwz       r5, 0x0(r5)
  lfs       f0, 0x40(r5)
  stw       r4, 0x4(r27)
  stw       r0, 0x0(r27)
  stw       r3, 0x4(r27)
  stfs      f0, 0x8(r27)

.loc_0x13F0:
  li        r3, 0x10
  bl        -0xF5474
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x145C
  lwz       r3, 0x230(r1)
  lis       r5, 0x802C
  addi      r0, r5, 0x6620
  lwz       r4, 0x84(r3)
  lis       r3, 0x802D
  li        r6, -0x1
  lwz       r4, 0x4(r4)
  subi      r5, r3, 0x6A6C
  lis       r7, 0x802D
  lwz       r4, 0x0(r4)
  subi      r3, r7, 0x6A8C
  lis       r8, 0x802D
  lfs       f0, 0x10(r4)
  li        r4, 0x6
  stw       r0, 0x4(r29)
  subi      r0, r8, 0x65C4
  stw       r6, 0x0(r29)
  stw       r5, 0x4(r29)
  stw       r4, 0x8(r29)
  stw       r3, 0x4(r29)
  stw       r0, 0x4(r29)
  stfs      f0, 0xC(r29)

.loc_0x145C:
  li        r3, 0x10
  bl        -0xF54E0
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x14A0
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r0, r3, 0x6C00
  li        r3, 0x2
  stw       r0, 0x4(r28)
  li        r0, 0x3
  stw       r3, 0x8(r28)
  stw       r0, 0xC(r28)

.loc_0x14A0:
  li        r3, 0xC
  bl        -0xF5524
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x14BC
  li        r4, 0x8
  bl        -0x154A4

.loc_0x14BC:
  li        r0, 0
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  stwx      r23, r3, r0
  li        r3, 0x1
  li        r0, 0x2
  lwz       r4, 0x8(r31)
  rlwinm    r3,r3,2,0,29
  li        r6, 0x4
  stwx      r19, r4, r3
  li        r5, 0x6
  rlwinm    r0,r0,2,0,29
  lwz       r3, 0x8(r31)
  li        r7, 0x3
  rlwinm    r6,r6,2,0,29
  stwx      r24, r3, r0
  rlwinm    r0,r7,2,0,29
  li        r8, 0x5
  lwz       r4, 0x8(r31)
  rlwinm    r7,r8,2,0,29
  rlwinm    r5,r5,2,0,29
  stwx      r27, r4, r0
  li        r3, 0x7
  rlwinm    r0,r3,2,0,29
  lwz       r4, 0x8(r31)
  li        r3, 0xC
  stwx      r29, r4, r6
  lwz       r4, 0x8(r31)
  stwx      r30, r4, r7
  lwz       r4, 0x8(r31)
  stwx      r28, r4, r5
  lwz       r5, 0x234(r1)
  lwz       r4, 0x8(r31)
  stwx      r5, r4, r0
  lwz       r4, 0x8(r26)
  stw       r31, 0x3C(r4)
  bl        -0xF55CC
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x1590
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r30)
  li        r0, 0x2
  lis       r3, 0x802D
  stw       r0, 0x0(r30)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r30)
  li        r4, 0
  subi      r0, r3, 0x6AD8
  stw       r4, 0x8(r30)
  stw       r0, 0x4(r30)

.loc_0x1590:
  li        r3, 0xC
  bl        -0xF5614
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x15AC
  li        r4, 0x5
  bl        -0x15594

.loc_0x15AC:
  li        r0, 0
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  stwx      r23, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r4, 0x8(r29)
  rlwinm    r3,r0,2,0,29
  li        r0, 0x3
  stwx      r19, r4, r3
  li        r6, 0x4
  rlwinm    r3,r5,2,0,29
  lwz       r5, 0x8(r29)
  rlwinm    r4,r0,2,0,29
  rlwinm    r0,r6,2,0,29
  stwx      r24, r5, r3
  mr        r3, r26
  lwz       r5, 0x8(r29)
  stwx      r30, r5, r4
  lwz       r4, 0x8(r29)
  stwx      r28, r4, r0
  lwz       r4, 0x8(r26)
  stw       r29, 0x40(r4)
  lwz       r0, 0x29C(r1)
  lmw       r14, 0x250(r1)
  addi      r1, r1, 0x298
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013C6A0
 * Size:	0000C8
 */
void TaiOtimotiStrategy::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  li        r6, 0
  stw       r0, 0x4(r1)
  li        r7, 0
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  mr        r31, r4
  addi      r5, r1, 0x1C
  stw       r30, 0x28(r1)
  addi      r30, r3, 0
  li        r4, 0x54
  lfs       f0, -0xF0C(r13)
  lfs       f1, -0xF08(r13)
  stfs      f0, 0x1C(r1)
  lfs       f0, -0xF04(r13)
  stfs      f1, 0x20(r1)
  lwz       r3, 0x3180(r13)
  stfs      f0, 0x24(r1)
  bl        0x60450
  lwz       r5, 0x3D8(r31)
  li        r4, 0
  stw       r3, 0x0(r5)
  mr        r3, r31
  bl        0xD320
  lfs       f0, -0xF00(r13)
  addi      r5, r1, 0x10
  lfs       f1, -0xEFC(r13)
  li        r4, 0x53
  stfs      f0, 0x10(r1)
  lfs       f0, -0xEF8(r13)
  li        r6, 0
  stfs      f1, 0x14(r1)
  li        r7, 0
  lwz       r3, 0x3180(r13)
  stfs      f0, 0x18(r1)
  bl        0x6040C
  lwz       r5, 0x3D8(r31)
  li        r4, 0x1
  stw       r3, 0x4(r5)
  mr        r3, r31
  bl        0xD2DC
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        -0x152B8
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013C768
 * Size:	00011C
 */
void TaiOtimotiStrategy::draw(Teki &, Graphics &)
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
  bl        0x10A40
  lwz       r3, 0x3D8(r31)
  lwz       r0, 0x0(r3)
  cmplwi    r0, 0
  beq-      .loc_0x100
  addi      r3, r1, 0x38
  bl        -0x1F948
  lfs       f30, 0xA0(r31)
  fmr       f1, f30
  bl        0xDF3AC
  fmr       f31, f1
  fmr       f1, f30
  bl        0xDF534
  stfs      f1, 0x38(r1)
  mr        r3, r31
  lfs       f0, -0xF10(r13)
  addi      r5, r1, 0x38
  li        r4, 0
  stfs      f0, 0x3C(r1)
  stfs      f31, 0x40(r1)
  bl        0xD29C
  addi      r3, r1, 0x2C
  bl        -0x1F988
  lwz       r6, 0x94(r31)
  mr        r3, r31
  lwz       r0, 0x98(r31)
  addi      r5, r1, 0x2C
  li        r4, 0
  stw       r6, 0x2C(r1)
  stw       r0, 0x30(r1)
  lwz       r0, 0x9C(r31)
  stw       r0, 0x34(r1)
  bl        0xD23C
  lfs       f30, 0xA0(r31)
  fmr       f1, f30
  bl        0xDF344
  fmr       f31, f1
  fmr       f1, f30
  bl        0xDF4CC
  stfs      f1, 0x38(r1)
  mr        r3, r31
  lfs       f0, -0xF10(r13)
  addi      r5, r1, 0x38
  li        r4, 0x1
  stfs      f0, 0x3C(r1)
  stfs      f31, 0x40(r1)
  bl        0xD234
  lwz       r6, 0x94(r31)
  mr        r3, r31
  lwz       r0, 0x98(r31)
  addi      r5, r1, 0x2C
  li        r4, 0x1
  stw       r6, 0x2C(r1)
  stw       r0, 0x30(r1)
  lwz       r0, 0x9C(r31)
  stw       r0, 0x34(r1)
  bl        0xD1DC

.loc_0x100:
  lwz       r0, 0x64(r1)
  lfd       f31, 0x58(r1)
  lfd       f30, 0x50(r1)
  lwz       r31, 0x4C(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013C884
 * Size:	0001C4
 */
void TaiOtimotiStrategy::drawDebugInfo(Teki &, Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xE8(r1)
  stfd      f31, 0xE0(r1)
  addi      r6, r1, 0xBC
  stfd      f30, 0xD8(r1)
  stmw      r26, 0xC0(r1)
  addi      r29, r4, 0
  li        r27, 0
  addi      r30, r5, 0
  addi      r31, r29, 0x94
  li        r28, 0xFF
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r5, r31, 0
  stb       r27, 0xBC(r1)
  stb       r27, 0xBD(r1)
  stb       r28, 0xBE(r1)
  stb       r28, 0xBF(r1)
  lwz       r7, 0x2C4(r29)
  lwz       r7, 0x84(r7)
  lwz       r7, 0x4(r7)
  lwz       r7, 0x0(r7)
  lfs       f1, 0x18(r7)
  bl        0xCA90
  stb       r28, 0xB8(r1)
  addi      r26, r1, 0xB8
  li        r4, 0
  stb       r28, 0xB9(r1)
  stb       r27, 0xBA(r1)
  stb       r28, 0xBB(r1)
  lwz       r3, 0x2C8(r29)
  lwz       r3, 0x34(r3)
  bl        -0x196F8
  lwz       r3, 0x2C4(r29)
  fmr       f31, f1
  li        r4, 0x1
  lwz       r3, 0x84(r3)
  bl        -0x1970C
  lwz       r3, 0x2C4(r29)
  fmr       f30, f1
  li        r4, 0x8
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  bl        -0x1A460
  fmuls     f0, f30, f31
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r5, r31, 0
  fmuls     f1, f1, f0
  addi      r6, r26, 0
  bl        0xCA24
  stb       r28, 0xB4(r1)
  addi      r26, r1, 0xB4
  li        r4, 0
  stb       r27, 0xB5(r1)
  stb       r27, 0xB6(r1)
  stb       r28, 0xB7(r1)
  lwz       r3, 0x2C8(r29)
  lwz       r3, 0x34(r3)
  bl        -0x19764
  lwz       r3, 0x2C4(r29)
  fmr       f31, f1
  li        r4, 0x1
  lwz       r3, 0x84(r3)
  bl        -0x19778
  lwz       r3, 0x2C4(r29)
  fmr       f30, f1
  li        r4, 0xA
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  bl        -0x1A4CC
  fmuls     f0, f30, f31
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r5, r31, 0
  fmuls     f1, f1, f0
  addi      r6, r26, 0
  bl        0xC9B8
  stb       r28, 0xB0(r1)
  addi      r26, r1, 0xB0
  li        r4, 0
  stb       r27, 0xB1(r1)
  stb       r28, 0xB2(r1)
  stb       r28, 0xB3(r1)
  lwz       r3, 0x2C8(r29)
  lwz       r3, 0x34(r3)
  bl        -0x197D0
  lwz       r3, 0x2C4(r29)
  fmr       f30, f1
  li        r4, 0x1
  lwz       r3, 0x84(r3)
  bl        -0x197E4
  lwz       r3, 0x2C4(r29)
  fmr       f31, f1
  li        r4, 0x2D
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  bl        -0x1A538
  fmuls     f0, f31, f30
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r5, r31, 0
  fmuls     f1, f1, f0
  addi      r6, r26, 0
  bl        0xC94C
  lmw       r26, 0xC0(r1)
  lwz       r0, 0xEC(r1)
  lfd       f31, 0xE0(r1)
  lfd       f30, 0xD8(r1)
  addi      r1, r1, 0xE8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013CA48
 * Size:	000054
 */
void TaiOtimotiStartDroppingWaterAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  addi      r3, r31, 0
  bl        0xCED4
  cmpwi     r3, 0x5
  bne-      .loc_0x34
  addi      r3, r31, 0
  li        r4, 0
  bl        0xCF84
  b         .loc_0x40

.loc_0x34:
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xCF74

.loc_0x40:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013CA9C
 * Size:	000128
 */
void TaiOtimotiFlickAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x802B
  stw       r0, 0x4(r1)
  subi      r5, r3, 0xF68
  lis       r3, 0x802C
  stwu      r1, -0x88(r1)
  addi      r0, r3, 0x6964
  lis       r3, 0x802C
  stw       r31, 0x84(r1)
  lis       r6, 0x802D
  addi      r31, r4, 0
  stw       r5, 0x68(r1)
  addi      r3, r3, 0x685C
  subi      r7, r6, 0x2A84
  stw       r5, 0x58(r1)
  addi      r4, r1, 0x68
  stw       r5, 0x60(r1)
  lis       r5, 0x802D
  subi      r6, r5, 0x295C
  stw       r0, 0x68(r1)
  addi      r5, r1, 0x60
  stw       r3, 0x68(r1)
  mr        r3, r31
  stw       r0, 0x58(r1)
  stw       r0, 0x60(r1)
  addi      r0, r1, 0x58
  stw       r7, 0x58(r1)
  stw       r6, 0x60(r1)
  stw       r5, 0x6C(r1)
  stw       r31, 0x5C(r1)
  stw       r31, 0x64(r1)
  stw       r0, 0x70(r1)
  bl        0xB944
  addi      r4, r3, 0
  addi      r3, r31, 0
  bl        0xBA80
  xoris     r0, r3, 0x8000
  lfd       f1, -0x5A50(r2)
  stw       r0, 0x7C(r1)
  lis       r0, 0x4330
  lfs       f2, 0x340(r31)
  stw       r0, 0x78(r1)
  lfd       f0, 0x78(r1)
  fsubs     f0, f0, f1
  fcmpo     cr0, f2, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x110
  lfs       f0, 0x94(r31)
  stfs      f0, 0x388(r31)
  lfs       f0, 0x98(r31)
  stfs      f0, 0x38C(r31)
  lfs       f0, 0x9C(r31)
  stfs      f0, 0x390(r31)
  lwz       r3, 0x418(r31)
  cmplwi    r3, 0
  beq-      .loc_0xF0
  beq-      .loc_0xF0
  bl        -0x58814
  li        r0, 0
  stw       r0, 0x418(r31)

.loc_0xF0:
  li        r0, 0
  stw       r0, 0x418(r31)
  lwz       r3, 0x418(r31)
  cmplwi    r3, 0
  beq-      .loc_0x108
  bl        -0x58844

.loc_0x108:
  li        r3, 0x1
  b         .loc_0x114

.loc_0x110:
  li        r3, 0

.loc_0x114:
  lwz       r0, 0x8C(r1)
  lwz       r31, 0x84(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013CBC4
 * Size:	000148
 */
void TaiOtimotiFailToJumpAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x802B
  stw       r0, 0x4(r1)
  subi      r5, r3, 0xF68
  lis       r3, 0x802C
  stwu      r1, -0x160(r1)
  addi      r0, r3, 0x6964
  lis       r3, 0x802C
  stfd      f31, 0x158(r1)
  lis       r6, 0x802D
  addi      r3, r3, 0x685C
  stw       r31, 0x154(r1)
  subi      r7, r6, 0x2B68
  stw       r30, 0x150(r1)
  addi      r30, r4, 0
  addi      r4, r1, 0x114
  stw       r5, 0x114(r1)
  stw       r5, 0x104(r1)
  stw       r5, 0x10C(r1)
  lis       r5, 0x802D
  subi      r6, r5, 0x295C
  stw       r0, 0x114(r1)
  addi      r5, r1, 0x10C
  stw       r3, 0x114(r1)
  mr        r3, r30
  stw       r0, 0x104(r1)
  stw       r0, 0x10C(r1)
  addi      r0, r1, 0x104
  stw       r7, 0x104(r1)
  stw       r6, 0x10C(r1)
  stw       r5, 0x118(r1)
  stw       r30, 0x108(r1)
  stw       r30, 0x110(r1)
  stw       r0, 0x11C(r1)
  bl        0xB814
  addi      r31, r3, 0
  addi      r3, r1, 0x120
  addi      r4, r1, 0x134
  bl        -0x213E4
  lwz       r4, 0x2C4(r30)
  addi      r3, r1, 0x120
  lwz       r4, 0x84(r4)
  lwz       r4, 0x4(r4)
  lwz       r4, 0x0(r4)
  lfs       f4, 0xF4(r4)
  lfs       f3, 0xEC(r4)
  lfs       f2, 0xF0(r4)
  lfs       f1, 0xE8(r4)
  bl        -0x21368
  xoris     r0, r31, 0x8000
  lfd       f1, -0x5A50(r2)
  stw       r0, 0x14C(r1)
  lis       r31, 0x4330
  addi      r3, r1, 0x120
  stw       r31, 0x148(r1)
  lfd       f0, 0x148(r1)
  fsubs     f1, f0, f1
  bl        -0x212FC
  fmr       f31, f1
  bl        0xDB3C0
  xoris     r0, r3, 0x8000
  lfd       f3, -0x5A50(r2)
  stw       r0, 0x144(r1)
  lfs       f1, -0x5A48(r2)
  stw       r31, 0x140(r1)
  lfs       f0, -0x5AD4(r2)
  lfd       f2, 0x140(r1)
  fsubs     f2, f2, f3
  fdivs     f1, f2, f1
  fmuls     f0, f0, f1
  fcmpo     cr0, f0, f31
  bge-      .loc_0x128
  li        r3, 0x1
  b         .loc_0x12C

.loc_0x128:
  li        r3, 0

.loc_0x12C:
  lwz       r0, 0x164(r1)
  lfd       f31, 0x158(r1)
  lwz       r31, 0x154(r1)
  lwz       r30, 0x150(r1)
  addi      r1, r1, 0x160
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013CD0C
 * Size:	000418
 */
void TaiOtimotiJumpingAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x140(r1)
  stfd      f31, 0x138(r1)
  stfd      f30, 0x130(r1)
  stfd      f29, 0x128(r1)
  stfd      f28, 0x120(r1)
  stfd      f27, 0x118(r1)
  stfd      f26, 0x110(r1)
  stw       r31, 0x10C(r1)
  mr        r31, r4
  addi      r3, r31, 0
  lwz       r0, 0xC8(r4)
  ori       r0, r0, 0x40
  stw       r0, 0xC8(r4)
  lwz       r0, 0xC8(r4)
  rlwinm    r0,r0,0,31,29
  stw       r0, 0xC8(r4)
  bl        0xB2AC
  lwz       r4, 0x418(r31)
  cmplwi    r4, 0
  beq-      .loc_0x70
  lwz       r3, 0x94(r4)
  lwz       r0, 0x98(r4)
  stw       r3, 0x388(r31)
  stw       r0, 0x38C(r31)
  lwz       r0, 0x9C(r4)
  stw       r0, 0x390(r31)

.loc_0x70:
  lfs       f30, 0x94(r31)
  addi      r3, r1, 0xEC
  lfs       f29, 0x98(r31)
  lfs       f28, 0x9C(r31)
  bl        -0x1FF38
  lfs       f0, 0x388(r31)
  li        r4, 0
  lfs       f1, 0x38C(r31)
  fsubs     f0, f0, f30
  lfs       f2, 0x390(r31)
  fsubs     f1, f1, f29
  stfs      f0, 0xEC(r1)
  fsubs     f0, f2, f28
  stfs      f1, 0xF0(r1)
  stfs      f0, 0xF4(r1)
  lfs       f0, -0x5AE0(r2)
  stfs      f0, 0xF0(r1)
  lwz       r3, 0x2C8(r31)
  lwz       r3, 0x34(r3)
  bl        -0x19BB8
  lwz       r3, 0x2C4(r31)
  fmr       f31, f1
  li        r4, 0x1
  lwz       r3, 0x84(r3)
  bl        -0x19BCC
  lwz       r3, 0x2C4(r31)
  fmr       f27, f1
  li        r4, 0x8
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  bl        -0x1A920
  lfs       f2, 0xEC(r1)
  fmuls     f5, f27, f31
  lfs       f0, 0xF0(r1)
  fmuls     f3, f2, f2
  lfs       f4, 0xF4(r1)
  fmuls     f2, f0, f0
  fmuls     f4, f4, f4
  lfs       f0, -0x5AE0(r2)
  fadds     f2, f3, f2
  fmuls     f31, f1, f5
  fadds     f4, f4, f2
  fcmpo     cr0, f4, f0
  ble-      .loc_0x178
  fsqrte    f1, f4
  lfd       f3, -0x5A40(r2)
  lfd       f2, -0x5A38(r2)
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
  stfs      f0, 0x88(r1)
  lfs       f4, 0x88(r1)

.loc_0x178:
  fcmpo     cr0, f4, f31
  ble-      .loc_0x1AC
  addi      r3, r1, 0xEC
  bl        -0x1FE78
  lfs       f0, 0xEC(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0xEC(r1)
  lfs       f0, 0xF0(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0xF0(r1)
  lfs       f0, 0xF4(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0xF4(r1)

.loc_0x1AC:
  lfs       f0, 0xEC(r1)
  mr        r3, r31
  lfs       f1, -0x5A58(r2)
  fmuls     f0, f0, f1
  stfs      f0, 0xEC(r1)
  lfs       f0, 0xF0(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0xF0(r1)
  lfs       f0, 0xF4(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0xF4(r1)
  bl        0xBA44
  lwz       r3, 0x2C4(r31)
  fmr       f27, f1
  lfs       f2, -0x5A30(r2)
  lwz       r3, 0x84(r3)
  fmuls     f2, f2, f27
  lfs       f0, -0x5AE0(r2)
  lwz       r3, 0x4(r3)
  lwz       r3, 0x0(r3)
  lfs       f1, 0x74(r3)
  fmuls     f31, f2, f1
  fcmpo     cr0, f31, f0
  ble-      .loc_0x264
  fsqrte    f1, f31
  lfd       f3, -0x5A40(r2)
  lfd       f2, -0x5A38(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f31, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f31, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f31, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f31, f0
  frsp      f0, f0
  stfs      f0, 0x80(r1)
  lfs       f31, 0x80(r1)

.loc_0x264:
  addi      r3, r1, 0xD4
  bl        -0x20120
  lfs       f0, 0xEC(r1)
  fadds     f0, f30, f0
  stfs      f0, 0xD4(r1)
  lfs       f0, 0xF0(r1)
  fadds     f0, f29, f0
  stfs      f0, 0xD8(r1)
  lfs       f0, 0xF4(r1)
  fadds     f0, f28, f0
  stfs      f0, 0xDC(r1)
  lfs       f1, -0x5AE0(r2)
  stfs      f1, 0xA0(r1)
  stfs      f1, 0x9C(r1)
  lfs       f0, 0xD4(r1)
  stfs      f1, 0x98(r1)
  fsubs     f0, f30, f0
  stfs      f0, 0x74(r1)
  lfs       f0, 0x74(r1)
  stfs      f0, 0x98(r1)
  lfs       f0, 0xD8(r1)
  fsubs     f0, f29, f0
  stfs      f0, 0x9C(r1)
  lfs       f0, 0xDC(r1)
  fsubs     f0, f28, f0
  stfs      f0, 0xA0(r1)
  lfs       f1, 0x98(r1)
  lfs       f0, 0x9C(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0xA0(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x12F3B8
  fdivs     f0, f31, f27
  addi      r3, r1, 0xC4
  fdivs     f26, f1, f0
  bl        -0x201B4
  lfs       f0, 0xD4(r1)
  addi      r3, r1, 0xC4
  fsubs     f0, f0, f30
  stfs      f0, 0xC4(r1)
  lfs       f0, 0xD8(r1)
  fsubs     f0, f0, f29
  stfs      f0, 0xC8(r1)
  lfs       f0, 0xDC(r1)
  fsubs     f0, f0, f28
  stfs      f0, 0xCC(r1)
  bl        -0x2001C
  lfs       f0, 0xC4(r1)
  addi      r4, r31, 0x94
  addi      r3, r1, 0xB8
  fmuls     f0, f0, f26
  stfs      f0, 0xC4(r1)
  lfs       f0, 0xC8(r1)
  fmuls     f0, f0, f26
  stfs      f0, 0xC8(r1)
  lfs       f0, 0xCC(r1)
  fmuls     f0, f0, f26
  stfs      f0, 0xCC(r1)
  stfs      f31, 0xC8(r1)
  bl        -0x201E8
  lwz       r12, 0x358(r31)
  addi      r4, r3, 0
  addi      r3, r31, 0x358
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  fmr       f2, f27
  lwz       r3, 0x45C(r31)
  lfs       f1, -0x5ADC(r2)
  addi      r5, r31, 0x358
  addi      r6, r1, 0xC4
  li        r4, 0
  bl        -0x16F54
  lwz       r3, 0x45C(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x20(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  bl        0xC8C4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x3D4
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0x14
  lwz       r12, 0x1C0(r12)
  mtlr      r12
  blrl      
  b         .loc_0x3EC

.loc_0x3D4:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0xD
  lwz       r12, 0x1C0(r12)
  mtlr      r12
  blrl      

.loc_0x3EC:
  lwz       r0, 0x144(r1)
  lfd       f31, 0x138(r1)
  lfd       f30, 0x130(r1)
  lfd       f29, 0x128(r1)
  lfd       f28, 0x120(r1)
  lfd       f27, 0x118(r1)
  lfd       f26, 0x110(r1)
  lwz       r31, 0x10C(r1)
  addi      r1, r1, 0x140
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D124
 * Size:	000084
 */
void TaiOtimotiJumpingAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r4, 0
  addi      r3, r1, 0x10
  bl        -0x202E8
  lwz       r3, 0x45C(r31)
  addi      r4, r1, 0x10
  lwzu      r12, 0x2C(r3)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lfs       f1, 0x14(r1)
  lfs       f0, -0x5AE0(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0x6C
  stfs      f0, 0x14(r1)
  li        r3, 0x1
  lfs       f0, 0x10(r1)
  stfs      f0, 0x398(r31)
  lfs       f0, 0x14(r1)
  stfs      f0, 0x39C(r31)
  lfs       f0, 0x18(r1)
  stfs      f0, 0x3A0(r31)
  b         .loc_0x70

.loc_0x6C:
  li        r3, 0

.loc_0x70:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D1A8
 * Size:	00012C
 */
void TaiOtimotiAirWaitingAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  addi      r31, r4, 0
  addi      r4, r31, 0x94
  addi      r3, r1, 0x20
  bl        -0x20344
  lwz       r12, 0x358(r31)
  addi      r4, r3, 0
  addi      r3, r31, 0x358
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lfs       f0, 0x398(r31)
  addi      r4, r1, 0x14
  addi      r3, r31, 0x368
  stfs      f0, 0x14(r1)
  lfs       f0, 0x39C(r31)
  stfs      f0, 0x18(r1)
  lfs       f0, 0x3A0(r31)
  stfs      f0, 0x1C(r1)
  lwz       r12, 0x368(r31)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lfs       f0, 0x398(r31)
  addi      r3, r1, 0x2C
  stfs      f0, 0x2C(r1)
  lfs       f0, 0x39C(r31)
  stfs      f0, 0x30(r1)
  lfs       f0, 0x3A0(r31)
  stfs      f0, 0x34(r1)
  bl        -0x20214
  lfs       f0, 0x2C(r1)
  addi      r3, r31, 0x378
  addi      r4, r1, 0x2C
  fneg      f0, f0
  stfs      f0, 0x2C(r1)
  lfs       f0, 0x30(r1)
  fneg      f0, f0
  stfs      f0, 0x30(r1)
  lfs       f0, 0x34(r1)
  fneg      f0, f0
  stfs      f0, 0x34(r1)
  lfs       f0, 0x2C(r1)
  lfs       f1, -0x5ADC(r2)
  fmuls     f0, f0, f1
  stfs      f0, 0x2C(r1)
  lfs       f0, 0x30(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x30(r1)
  lfs       f0, 0x34(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x34(r1)
  lwz       r12, 0x378(r31)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x460(r31)
  addi      r5, r31, 0x358
  addi      r6, r31, 0x368
  addi      r7, r31, 0x378
  li        r4, 0
  bl        -0x17364
  lwz       r3, 0x460(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x20(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D2D4
 * Size:	000164
 */
void TaiOtimotiAirWaitingAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stw       r31, 0x5C(r1)
  addi      r3, r1, 0x4C
  li        r31, 0x1
  stw       r30, 0x58(r1)
  mr        r30, r4
  lfs       f0, 0x398(r4)
  stfs      f0, 0x4C(r1)
  lfs       f0, 0x39C(r30)
  stfs      f0, 0x50(r1)
  lfs       f0, 0x3A0(r30)
  stfs      f0, 0x54(r1)
  bl        -0x202F4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xB0
  addi      r3, r1, 0x40
  bl        -0x204C8
  addi      r3, r30, 0x368
  lwz       r12, 0x368(r30)
  addi      r4, r1, 0x40
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  addi      r3, r1, 0x40
  bl        -0x20324
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xB0
  lfs       f3, 0x40(r1)
  lfs       f2, 0x4C(r1)
  lfs       f1, 0x44(r1)
  lfs       f0, 0x50(r1)
  fmuls     f2, f3, f2
  lfs       f4, 0x48(r1)
  fmuls     f1, f1, f0
  lfs       f3, 0x54(r1)
  lfs       f0, -0x5A2C(r2)
  fmuls     f3, f4, f3
  fadds     f1, f2, f1
  fadds     f1, f3, f1
  fcmpo     cr0, f1, f0
  ble-      .loc_0xB0
  li        r31, 0

.loc_0xB0:
  rlwinm.   r0,r31,0,24,31
  beq-      .loc_0x108
  addi      r3, r1, 0x28
  subi      r4, r13, 0xF1C
  subi      r5, r13, 0xF18
  subi      r6, r13, 0xF14
  bl        -0x106280
  addi      r3, r30, 0x70
  addi      r4, r1, 0x28
  addi      r5, r1, 0x2C
  addi      r6, r1, 0x30
  bl        -0xDFD24
  addi      r3, r1, 0x1C
  subi      r4, r13, 0xF28
  subi      r5, r13, 0xF24
  subi      r6, r13, 0xF20
  bl        -0x1062A8
  addi      r3, r30, 0xA4
  addi      r4, r1, 0x1C
  addi      r5, r1, 0x20
  addi      r6, r1, 0x24
  bl        -0xDFD4C

.loc_0x108:
  lwz       r3, 0x414(r30)
  lwz       r0, -0x99C(r13)
  and.      r0, r3, r0
  beq-      .loc_0x134
  addi      r3, r30, 0
  li        r4, 0
  bl        0xC628
  addi      r3, r30, 0
  li        r4, 0x1
  bl        0xC61C
  b         .loc_0x148

.loc_0x134:
  lwz       r0, -0x98C(r13)
  and.      r0, r3, r0
  beq-      .loc_0x148
  li        r3, 0x1
  b         .loc_0x14C

.loc_0x148:
  li        r3, 0

.loc_0x14C:
  lwz       r0, 0x64(r1)
  lwz       r31, 0x5C(r1)
  lwz       r30, 0x58(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D438
 * Size:	000084
 */
void TaiOtimotiDroppingAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  mr        r31, r4
  lwz       r0, 0xC8(r4)
  li        r4, 0x32
  rlwinm    r0,r0,0,26,24
  stw       r0, 0xC8(r31)
  lwz       r0, 0xC8(r31)
  ori       r0, r0, 0x2
  stw       r0, 0xC8(r31)
  lwz       r3, 0x2C4(r31)
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  bl        -0x1AFA0
  lfs       f2, -0xEF4(r13)
  fneg      f0, f1
  mr        r3, r31
  stfs      f2, 0x398(r31)
  stfs      f0, 0x39C(r31)
  lfs       f0, -0xEF0(r13)
  stfs      f0, 0x3A0(r31)
  lwz       r12, 0x0(r31)
  lwz       r4, -0x9B8(r13)
  lwz       r12, 0x1CC(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D4BC
 * Size:	00005C
 */
void TaiOtimotiDroppingAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  addi      r31, r4, 0
  addi      r3, r31, 0
  bl        0xB4C0
  lwz       r3, 0x2C4(r31)
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  lwz       r3, 0x0(r3)
  lfs       f0, 0xCC(r3)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0x44
  li        r3, 0x1
  b         .loc_0x48

.loc_0x44:
  li        r3, 0

.loc_0x48:
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D518
 * Size:	000060
 */
void TaiOtimotiDroppingAction::actByEvent(TekiEvent &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x0(r4)
  cmpwi     r0, 0
  bne-      .loc_0x4C
  lwz       r3, 0x4(r4)
  lwz       r0, 0xC8(r3)
  rlwinm    r0,r0,0,26,24
  stw       r0, 0xC8(r3)
  lwz       r0, 0xC8(r3)
  ori       r0, r0, 0x2
  stw       r0, 0xC8(r3)
  lwz       r3, 0x4(r4)
  lwz       r4, -0x9B8(r13)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x1D0(r12)
  mtlr      r12
  blrl      

.loc_0x4C:
  li        r3, 0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D578
 * Size:	000034
 */
void TaiOtimotiPressingAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  mr        r3, r4
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x0(r4)
  li        r4, 0x8
  lwz       r12, 0x174(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D5AC
 * Size:	00005C
 */
void TaiOtimotiPressingAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0
  addi      r3, r31, 0
  bl        0xB39C
  lfs       f0, -0x5AD4(r2)
  addi      r3, r31, 0x98
  lfs       f2, 0x98(r31)
  fadds     f0, f0, f1
  fcmpo     cr0, f2, f0
  cror      2, 0, 0x2
  bne-      .loc_0x44
  stfs      f1, 0x0(r3)
  li        r3, 0x1
  b         .loc_0x48

.loc_0x44:
  li        r3, 0

.loc_0x48:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D608
 * Size:	00021C
 */
void TaiOtimotiPressingAction::actByEvent(TekiEvent &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x148(r1)
  stfd      f31, 0x140(r1)
  stfd      f30, 0x138(r1)
  stw       r31, 0x134(r1)
  stw       r30, 0x130(r1)
  stw       r29, 0x12C(r1)
  stw       r28, 0x128(r1)
  mr        r28, r4
  lwz       r0, 0x0(r4)
  cmpwi     r0, 0
  bne-      .loc_0x1F0
  lwz       r3, 0x4(r28)
  lwz       r0, 0xC8(r3)
  rlwinm    r0,r0,0,26,24
  stw       r0, 0xC8(r3)
  lwz       r0, 0xC8(r3)
  ori       r0, r0, 0x2
  stw       r0, 0xC8(r3)
  lwz       r3, 0x4(r28)
  lwz       r4, -0x9B8(r13)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x1D0(r12)
  mtlr      r12
  blrl      
  lwz       r29, 0x4(r28)
  lis       r8, 0x802B
  lis       r6, 0x802B
  lwz       r3, 0x2C4(r29)
  lis       r5, 0x802C
  lis       r7, 0x802B
  lwz       r9, 0x84(r3)
  lis       r4, 0x802D
  lis       r3, 0x802C
  lwz       r9, 0x4(r9)
  subi      r0, r8, 0x3064
  subi      r30, r6, 0xF68
  lwz       r8, 0x0(r9)
  addi      r31, r5, 0x6964
  subi      r6, r7, 0x32D4
  lfs       f0, 0x30(r8)
  subi      r5, r4, 0x2A4C
  addi      r3, r3, 0x6890
  stw       r0, 0x11C(r1)
  addi      r0, r1, 0xE0
  addi      r28, r1, 0x11C
  stw       r30, 0xE0(r1)
  li        r4, 0
  stw       r30, 0xE8(r1)
  stw       r29, 0x120(r1)
  stw       r31, 0xE0(r1)
  stw       r31, 0xE8(r1)
  stw       r6, 0x11C(r1)
  stw       r5, 0xE0(r1)
  stw       r3, 0xE8(r1)
  stfs      f0, 0x124(r1)
  stw       r29, 0xE4(r1)
  stw       r0, 0xEC(r1)
  lwz       r3, 0x2C8(r29)
  lwz       r3, 0x34(r3)
  bl        -0x1A4EC
  lwz       r3, 0x2C4(r29)
  fmr       f30, f1
  li        r4, 0x1
  lwz       r3, 0x84(r3)
  bl        -0x1A500
  lwz       r3, 0x2C4(r29)
  fmr       f31, f1
  li        r4, 0xA
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  bl        -0x1B254
  stw       r30, 0xF0(r1)
  fmuls     f0, f31, f30
  lis       r3, 0x802D
  stw       r30, 0xFC(r1)
  lis       r4, 0x802C
  subi      r11, r3, 0x29D8
  stw       r30, 0x110(r1)
  addi      r10, r4, 0x685C
  lis       r3, 0x802D
  fmuls     f0, f1, f0
  stw       r31, 0xF0(r1)
  subi      r7, r3, 0x295C
  stw       r31, 0xFC(r1)
  addi      r9, r1, 0xF0
  addi      r6, r1, 0x108
  stw       r30, 0x108(r1)
  addi      r8, r1, 0xE8
  addi      r0, r1, 0xFC
  stw       r31, 0x110(r1)
  addi      r5, r1, 0x110
  addi      r3, r29, 0
  stw       r11, 0xF0(r1)
  mr        r4, r28
  stw       r10, 0xFC(r1)
  stw       r31, 0x108(r1)
  stw       r10, 0x110(r1)
  stw       r29, 0xF4(r1)
  stw       r9, 0x100(r1)
  stw       r7, 0x108(r1)
  stw       r6, 0x114(r1)
  stfs      f0, 0xF8(r1)
  stw       r8, 0x104(r1)
  stw       r29, 0x10C(r1)
  stw       r0, 0x118(r1)
  bl        0xA364
  mr        r3, r29
  bl        0xA630
  lfs       f0, -0x5AE0(r2)
  addi      r28, r29, 0x94
  addi      r5, r28, 0
  stfs      f0, 0x340(r29)
  li        r4, 0x3
  lwz       r3, 0x30D8(r13)
  bl        -0x19800
  lwz       r3, 0x3178(r13)
  addi      r6, r28, 0
  li        r4, 0x4
  li        r5, 0
  bl        0x3F5E8
  li        r3, 0x1
  b         .loc_0x1F4

.loc_0x1F0:
  li        r3, 0

.loc_0x1F4:
  lwz       r0, 0x14C(r1)
  lfd       f31, 0x140(r1)
  lfd       f30, 0x138(r1)
  lwz       r31, 0x134(r1)
  lwz       r30, 0x130(r1)
  lwz       r29, 0x12C(r1)
  lwz       r28, 0x128(r1)
  addi      r1, r1, 0x148
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D824
 * Size:	000008
 */
void TaiOtimotiBouncingAction::act(Teki &)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D82C
 * Size:	000008
 */
void TaiOtimotiBouncingAction::actByEvent(TekiEvent &)
{
/*
.loc_0x0:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D834
 * Size:	000004
 */
void TaiOtimotiAttackingAction::start(Teki &)
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D838
 * Size:	0000B0
 */
void TaiOtimotiAttackingAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stw       r31, 0x4C(r1)
  addi      r31, r4, 0
  addi      r3, r31, 0
  bl        0xB110
  lfs       f0, -0x5AD4(r2)
  addi      r3, r31, 0x98
  lfs       f2, 0x98(r31)
  fadds     f0, f0, f1
  fcmpo     cr0, f2, f0
  cror      2, 0, 0x2
  bne-      .loc_0x6C
  stfs      f1, 0x0(r3)
  mr        r3, r31
  lwz       r0, 0xC8(r31)
  rlwinm    r0,r0,0,26,24
  stw       r0, 0xC8(r31)
  lwz       r0, 0xC8(r31)
  ori       r0, r0, 0x2
  stw       r0, 0xC8(r31)
  lwz       r12, 0x0(r31)
  lwz       r4, -0x9B8(r13)
  lwz       r12, 0x1D0(r12)
  mtlr      r12
  blrl      

.loc_0x6C:
  lwz       r3, 0x2CC(r31)
  lwz       r0, 0x38(r3)
  cmpwi     r0, 0
  bge-      .loc_0x84
  li        r3, 0x1
  b         .loc_0x9C

.loc_0x84:
  lbz       r0, 0x48(r3)
  cmplwi    r0, 0
  beq-      .loc_0x98
  li        r3, 0x1
  b         .loc_0x9C

.loc_0x98:
  li        r3, 0

.loc_0x9C:
  lwz       r0, 0x54(r1)
  lwz       r31, 0x4C(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D8E8
 * Size:	000008
 */
void TaiOtimotiAttackingAction::actByEvent(TekiEvent &)
{
/*
.loc_0x0:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D8F0
 * Size:	0000F0
 */
void TaiOtimotiAttackingEffectAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  addi      r30, r4, 0
  addi      r3, r30, 0
  bl        0xC028
  lfs       f0, 0x94(r30)
  mr        r31, r3
  li        r4, 0x1
  stfs      f0, 0x1C(r1)
  lfs       f0, 0x98(r30)
  stfs      f0, 0x20(r1)
  lfs       f0, 0x9C(r30)
  stfs      f0, 0x24(r1)
  lwz       r3, 0x2F00(r13)
  lfs       f1, 0x1C(r1)
  lfs       f2, 0x24(r1)
  bl        -0xD5A38
  cmpwi     r31, 0x5
  stfs      f1, 0x20(r1)
  bne-      .loc_0x90
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x1C
  li        r4, 0x55
  li        r6, 0
  li        r7, 0
  bl        0x5F1D8
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0x15
  lwz       r12, 0x1C0(r12)
  mtlr      r12
  blrl      
  b         .loc_0xD8

.loc_0x90:
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x1C
  li        r4, 0x51
  li        r6, 0
  li        r7, 0
  bl        0x5F1A4
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x1C
  li        r4, 0x52
  li        r6, 0
  li        r7, 0
  bl        0x5F18C
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0x10
  lwz       r12, 0x1C0(r12)
  mtlr      r12
  blrl      

.loc_0xD8:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8013D9E0
 * Size:	000058
 */
void TaiOtimotiLegEffectAction::TaiOtimotiLegEffectAction(float)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x6C6C
  stw       r0, 0x4(r1)
  lis       r4, 0x726C
  addi      r6, r4, 0x6567
  stwu      r1, -0x18(r1)
  addi      r5, r5, 0x6567
  li        r4, 0x2
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  li        r7, 0
  li        r8, 0
  bl        -0xF3D8
  lis       r3, 0x802D
  subi      r0, r3, 0x5414
  stw       r0, 0x4(r31)
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
 * Address:	8013DA38
 * Size:	00007C
 */
void TaiOtimotiLegEffectAction::setType(Vector3f &, int, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r5
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r3, 0x2F00(r13)
  lfs       f1, 0x0(r4)
  lfs       f2, 0x8(r4)
  li        r4, 0x1
  bl        -0xD5B68
  cmpwi     r31, 0x5
  stfs      f1, 0x4(r30)
  bne-      .loc_0x50
  li        r0, 0xF
  stw       r0, 0x14(r29)
  b         .loc_0x58

.loc_0x50:
  li        r0, 0x44
  stw       r0, 0x14(r29)

.loc_0x58:
  li        r0, -0x1
  stw       r0, 0x18(r29)
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}