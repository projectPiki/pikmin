

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
 * Address:	80128520
 * Size:	000084
 */
void TaiChappySoundTable::TaiChappySoundTable()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x8
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  bl        -0x94CC
  li        r30, 0
  li        r31, 0
  b         .loc_0x58

.loc_0x30:
  li        r3, 0x4
  bl        -0xE1550
  cmplwi    r3, 0
  beq-      .loc_0x48
  addi      r0, r30, 0x20
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
 * Address:	801285A4
 * Size:	0003A4
 */
void TaiChappyParameters::TaiChappyParameters()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802C
  stw       r0, 0x4(r1)
  li        r5, 0x35
  stwu      r1, -0xE0(r1)
  stw       r31, 0xDC(r1)
  addi      r31, r4, 0x6B70
  li        r4, 0x15
  stw       r30, 0xD8(r1)
  addi      r30, r3, 0
  bl        0x2377C
  lis       r3, 0x802C
  addi      r0, r3, 0x7030
  stw       r0, 0x0(r30)
  li        r0, 0x14
  li        r6, 0x32
  lwz       r4, 0x84(r30)
  li        r5, 0x33
  li        r3, 0x34
  lwz       r7, 0x0(r4)
  mulli     r4, r0, 0xC
  lwz       r7, 0x8(r7)
  addi      r0, r31, 0x1C
  add       r7, r7, r4
  stw       r0, 0x0(r7)
  li        r4, 0
  li        r0, 0x1
  stw       r4, 0x4(r7)
  mulli     r8, r6, 0xC
  stw       r0, 0x8(r7)
  addi      r7, r31, 0x28
  lwz       r9, 0x84(r30)
  mulli     r6, r5, 0xC
  lwz       r9, 0x4(r9)
  addi      r5, r31, 0x38
  lwz       r11, 0x8(r9)
  mulli     r3, r3, 0xC
  add       r9, r11, r8
  stw       r7, 0x0(r9)
  add       r10, r11, r6
  add       r11, r11, r3
  lfs       f6, -0x5DE0(r2)
  addi      r3, r31, 0x48
  li        r8, 0x2
  stfs      f6, 0x4(r9)
  li        r7, -0x1
  li        r6, 0x3
  lfs       f5, -0x5DDC(r2)
  stfs      f5, 0x8(r9)
  stw       r5, 0x0(r10)
  stfs      f6, 0x4(r10)
  lfs       f4, -0x5DD8(r2)
  stfs      f4, 0x8(r10)
  stw       r3, 0x0(r11)
  stfs      f6, 0x4(r11)
  lfs       f0, -0x5DD4(r2)
  stfs      f0, 0x8(r11)
  lwz       r5, 0x84(r30)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r8, 0x18(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r7, 0xC(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r0, 0x24(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r0, 0x28(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r8, 0x2C(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r6, 0x30(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r0, 0x34(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r0, 0x38(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r8, 0x3C(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r8, 0x40(r3)
  lwz       r3, 0x4(r5)
  lfs       f3, -0x5DD0(r2)
  lwz       r3, 0x0(r3)
  stfs      f3, 0x0(r3)
  lwz       r3, 0x4(r5)
  lfs       f2, -0x5DCC(r2)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x4(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x8(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f5, 0xC(r3)
  lwz       r3, 0x4(r5)
  lfs       f1, -0x5DC8(r2)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x10(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DC4(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x14(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DC0(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x18(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DBC(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x1C(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f3, 0x70(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DB8(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x20(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DB4(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x24(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DB0(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x28(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DAC(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xB4(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x2C(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x30(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DA8(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x3C(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DA4(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x40(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f4, 0x44(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DA0(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x48(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5D9C(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x4C(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x50(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x54(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5D98(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x68(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5D94(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x78(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5D90(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x7C(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x80(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5D8C(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x84(r3)
  lwz       r6, 0x4(r5)
  mr        r3, r30
  lwz       r6, 0x0(r6)
  stfs      f1, 0x88(r6)
  lwz       r6, 0x4(r5)
  lwz       r6, 0x0(r6)
  stfs      f6, 0x8C(r6)
  lwz       r6, 0x4(r5)
  lwz       r6, 0x0(r6)
  stfs      f6, 0x90(r6)
  lwz       r6, 0x4(r5)
  lwz       r6, 0x0(r6)
  stfs      f1, 0x9C(r6)
  lwz       r6, 0x4(r5)
  lfs       f0, -0x5D88(r2)
  lwz       r6, 0x0(r6)
  stfs      f0, 0xA0(r6)
  lwz       r6, 0x4(r5)
  lwz       r6, 0x0(r6)
  stfs      f2, 0xAC(r6)
  lwz       r6, 0x4(r5)
  lfs       f0, -0x5D84(r2)
  lwz       r6, 0x0(r6)
  stfs      f0, 0xB0(r6)
  lwz       r6, 0x0(r5)
  lwz       r6, 0x0(r6)
  stw       r4, 0x50(r6)
  lwz       r4, 0x4(r5)
  lfs       f0, -0x5D80(r2)
  lwz       r4, 0x0(r4)
  stfs      f0, 0xCC(r4)
  lwz       r4, 0x4(r5)
  lwz       r4, 0x0(r4)
  stfs      f2, 0xC8(r4)
  lwz       r4, 0x4(r5)
  lwz       r4, 0x0(r4)
  stfs      f3, 0xD0(r4)
  lwz       r0, 0xE4(r1)
  lwz       r31, 0xDC(r1)
  lwz       r30, 0xD8(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80128948
 * Size:	0003A0
 */
void TaiBlackChappyParameters::TaiBlackChappyParameters()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802C
  stw       r0, 0x4(r1)
  li        r5, 0x35
  stwu      r1, -0xE0(r1)
  stw       r31, 0xDC(r1)
  addi      r31, r4, 0x6B70
  li        r4, 0x15
  stw       r30, 0xD8(r1)
  addi      r30, r3, 0
  bl        0x233D8
  lis       r3, 0x802C
  addi      r0, r3, 0x6FC8
  stw       r0, 0x0(r30)
  li        r0, 0x14
  li        r6, 0x32
  lwz       r4, 0x84(r30)
  li        r5, 0x33
  li        r3, 0x34
  lwz       r7, 0x0(r4)
  mulli     r4, r0, 0xC
  lwz       r7, 0x8(r7)
  addi      r0, r31, 0x1C
  add       r7, r7, r4
  stw       r0, 0x0(r7)
  li        r4, 0
  li        r0, 0x1
  stw       r4, 0x4(r7)
  mulli     r8, r6, 0xC
  stw       r0, 0x8(r7)
  addi      r7, r31, 0x28
  lwz       r9, 0x84(r30)
  mulli     r6, r5, 0xC
  lwz       r9, 0x4(r9)
  addi      r5, r31, 0x38
  lwz       r11, 0x8(r9)
  mulli     r3, r3, 0xC
  add       r9, r11, r8
  stw       r7, 0x0(r9)
  add       r10, r11, r6
  add       r11, r11, r3
  lfs       f7, -0x5DE0(r2)
  addi      r3, r31, 0x48
  li        r8, 0x2
  stfs      f7, 0x4(r9)
  li        r7, -0x1
  li        r6, 0x3
  lfs       f6, -0x5DDC(r2)
  stfs      f6, 0x8(r9)
  stw       r5, 0x0(r10)
  stfs      f7, 0x4(r10)
  lfs       f5, -0x5DD8(r2)
  stfs      f5, 0x8(r10)
  stw       r3, 0x0(r11)
  stfs      f7, 0x4(r11)
  lfs       f0, -0x5DD4(r2)
  stfs      f0, 0x8(r11)
  lwz       r5, 0x84(r30)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r8, 0x18(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r7, 0xC(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r8, 0x24(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r0, 0x28(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r8, 0x2C(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r6, 0x30(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r0, 0x34(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r0, 0x38(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r8, 0x3C(r3)
  lwz       r3, 0x0(r5)
  lwz       r3, 0x0(r3)
  stw       r8, 0x40(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5D7C(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x0(r3)
  lwz       r3, 0x4(r5)
  lfs       f4, -0x5DCC(r2)
  lwz       r3, 0x0(r3)
  stfs      f4, 0x4(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f4, 0x8(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f6, 0xC(r3)
  lwz       r3, 0x4(r5)
  lfs       f3, -0x5DC8(r2)
  lwz       r3, 0x0(r3)
  stfs      f3, 0x10(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DC4(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x14(r3)
  lwz       r3, 0x4(r5)
  lfs       f2, -0x5DA4(r2)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x18(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DBC(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x1C(r3)
  lwz       r3, 0x4(r5)
  lfs       f1, -0x5DD0(r2)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x70(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DB8(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x20(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DB4(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x24(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DB0(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x28(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DAC(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xB4(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f6, 0x2C(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f6, 0x30(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DA8(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x3C(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x40(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x44(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5DA0(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x48(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5D9C(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x4C(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f6, 0x50(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f6, 0x54(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5D98(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x68(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5D94(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x78(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5D90(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x7C(r3)
  lwz       r3, 0x4(r5)
  lwz       r3, 0x0(r3)
  stfs      f4, 0x80(r3)
  lwz       r3, 0x4(r5)
  lfs       f0, -0x5D8C(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x84(r3)
  lwz       r6, 0x4(r5)
  mr        r3, r30
  lwz       r6, 0x0(r6)
  stfs      f3, 0x88(r6)
  lwz       r6, 0x4(r5)
  lwz       r6, 0x0(r6)
  stfs      f7, 0x8C(r6)
  lwz       r6, 0x4(r5)
  lwz       r6, 0x0(r6)
  stfs      f7, 0x90(r6)
  lwz       r6, 0x4(r5)
  lwz       r6, 0x0(r6)
  stfs      f3, 0x9C(r6)
  lwz       r6, 0x4(r5)
  lfs       f0, -0x5D88(r2)
  lwz       r6, 0x0(r6)
  stfs      f0, 0xA0(r6)
  lwz       r6, 0x4(r5)
  lwz       r6, 0x0(r6)
  stfs      f4, 0xAC(r6)
  lwz       r6, 0x4(r5)
  lfs       f0, -0x5D84(r2)
  lwz       r6, 0x0(r6)
  stfs      f0, 0xB0(r6)
  lwz       r6, 0x0(r5)
  lwz       r6, 0x0(r6)
  stw       r4, 0x50(r6)
  lwz       r4, 0x4(r5)
  lwz       r4, 0x0(r4)
  stfs      f6, 0xCC(r4)
  lwz       r4, 0x4(r5)
  lwz       r4, 0x0(r4)
  stfs      f4, 0xC8(r4)
  lwz       r4, 0x4(r5)
  lwz       r4, 0x0(r4)
  stfs      f1, 0xD0(r4)
  lwz       r0, 0xE4(r1)
  lwz       r31, 0xDC(r1)
  lwz       r30, 0xD8(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80128CE8
 * Size:	000084
 */
void TaiCatfishSoundTable::TaiCatfishSoundTable()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x3
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  bl        -0x9C94
  li        r30, 0
  li        r31, 0
  b         .loc_0x58

.loc_0x30:
  li        r3, 0x4
  bl        -0xE1D18
  cmplwi    r3, 0
  beq-      .loc_0x48
  addi      r0, r30, 0xA2
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
 * Address:	80128D6C
 * Size:	00039C
 */
void TaiCatfishParameters::TaiCatfishParameters()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802C
  stw       r0, 0x4(r1)
  li        r5, 0x35
  stwu      r1, -0xE0(r1)
  stw       r31, 0xDC(r1)
  addi      r31, r4, 0x6B70
  li        r4, 0x15
  stw       r30, 0xD8(r1)
  addi      r30, r3, 0
  bl        0x22FB4
  lis       r3, 0x802C
  addi      r0, r3, 0x6F58
  stw       r0, 0x0(r30)
  li        r0, 0x14
  li        r5, 0x32
  lwz       r6, 0x84(r30)
  li        r4, 0x33
  li        r3, 0x34
  lwz       r7, 0x0(r6)
  mulli     r6, r0, 0xC
  lwz       r7, 0x8(r7)
  addi      r0, r31, 0x1C
  add       r8, r7, r6
  stw       r0, 0x0(r8)
  li        r6, 0
  li        r0, 0x1
  stw       r6, 0x4(r8)
  mulli     r7, r5, 0xC
  stw       r0, 0x8(r8)
  addi      r6, r31, 0x28
  lwz       r8, 0x84(r30)
  mulli     r5, r4, 0xC
  lwz       r8, 0x4(r8)
  addi      r4, r31, 0x38
  lwz       r10, 0x8(r8)
  mulli     r3, r3, 0xC
  add       r8, r10, r7
  stw       r6, 0x0(r8)
  add       r9, r10, r5
  add       r10, r10, r3
  lfs       f8, -0x5DE0(r2)
  addi      r3, r31, 0x48
  li        r7, -0x1
  stfs      f8, 0x4(r8)
  li        r6, 0x3
  li        r5, 0x2
  lfs       f7, -0x5DDC(r2)
  stfs      f7, 0x8(r8)
  stw       r4, 0x0(r9)
  stfs      f8, 0x4(r9)
  lfs       f6, -0x5DD8(r2)
  stfs      f6, 0x8(r9)
  stw       r3, 0x0(r10)
  stfs      f8, 0x4(r10)
  lfs       f0, -0x5DD4(r2)
  stfs      f0, 0x8(r10)
  lwz       r4, 0x84(r30)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r0, 0x0(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r0, 0x18(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r7, 0xC(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r6, 0x24(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r0, 0x28(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r5, 0x2C(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r6, 0x30(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r0, 0x34(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r0, 0x38(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r5, 0x3C(r3)
  lwz       r3, 0x0(r4)
  lwz       r3, 0x0(r3)
  stw       r5, 0x40(r3)
  lwz       r3, 0x4(r4)
  lfs       f1, -0x5D78(r2)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x0(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5D74(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x4(r3)
  lwz       r3, 0x4(r4)
  lfs       f5, -0x5DCC(r2)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x8(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f6, 0xC(r3)
  lwz       r3, 0x4(r4)
  lfs       f4, -0x5D8C(r2)
  lwz       r3, 0x0(r3)
  stfs      f4, 0x10(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5DC4(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x14(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x18(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5DBC(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x1C(r3)
  lwz       r3, 0x4(r4)
  lfs       f3, -0x5DD0(r2)
  lwz       r3, 0x0(r3)
  stfs      f3, 0x70(r3)
  lwz       r3, 0x4(r4)
  lfs       f2, -0x5DB4(r2)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x20(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x24(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f6, 0x28(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5D70(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0xB4(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5DAC(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x2C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f7, 0x30(r3)
  lwz       r3, 0x4(r4)
  lfs       f1, -0x5D98(r2)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x3C(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5DA4(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x40(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f2, 0x44(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5DA0(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x48(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5D6C(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x4C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f7, 0x50(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f7, 0x54(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f1, 0x68(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5D94(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x78(r3)
  lwz       r3, 0x4(r4)
  lfs       f0, -0x5D90(r2)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x7C(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f5, 0x80(r3)
  lwz       r3, 0x4(r4)
  lwz       r3, 0x0(r3)
  stfs      f4, 0x84(r3)
  lwz       r5, 0x4(r4)
  mr        r3, r30
  lfs       f0, -0x5DC8(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x88(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f8, 0x8C(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f8, 0x90(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f0, 0x9C(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5D88(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xA0(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f5, 0xAC(r5)
  lwz       r5, 0x4(r4)
  lfs       f0, -0x5D84(r2)
  lwz       r5, 0x0(r5)
  stfs      f0, 0xB0(r5)
  lwz       r5, 0x0(r4)
  lwz       r5, 0x0(r5)
  stw       r0, 0x50(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f7, 0xCC(r5)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x0(r5)
  stfs      f5, 0xC8(r5)
  lwz       r4, 0x4(r4)
  lwz       r4, 0x0(r4)
  stfs      f3, 0xD0(r4)
  lwz       r0, 0xE4(r1)
  lwz       r31, 0xDC(r1)
  lwz       r30, 0xD8(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80129108
 * Size:	00156C
 */
void TaiChappyStrategy::TaiChappyStrategy(TekiParameters *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0xF
  stw       r0, 0x4(r1)
  stwu      r1, -0x220(r1)
  stmw      r14, 0x1D8(r1)
  addi      r16, r4, 0
  addi      r26, r3, 0
  li        r4, 0x10
  bl        -0x1D44
  lis       r3, 0x802C
  addi      r0, r3, 0x6E9C
  stw       r0, 0x0(r26)
  li        r3, 0x8
  bl        -0xE2138
  addi      r19, r3, 0
  mr.       r0, r19
  beq-      .loc_0x64
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r19)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r19)
  subi      r0, r3, 0x6140
  stw       r0, 0x4(r19)

.loc_0x64:
  li        r3, 0xC
  bl        -0xE216C
  addi      r20, r3, 0
  mr.       r0, r20
  beq-      .loc_0xA0
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r20)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r20)
  subi      r3, r3, 0x6C44
  li        r0, 0x6
  stw       r3, 0x4(r20)
  stw       r0, 0x8(r20)

.loc_0xA0:
  li        r3, 0x8
  bl        -0xE21A8
  stw       r3, 0x1D4(r1)
  lwz       r0, 0x1D4(r1)
  cmplwi    r0, 0
  beq-      .loc_0xE4
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  lwz       r3, 0x1D4(r1)
  lis       r4, 0x802D
  stw       r0, 0x4(r3)
  li        r0, -0x1
  lwz       r3, 0x1D4(r1)
  stw       r0, 0x0(r3)
  subi      r0, r4, 0x6C84
  lwz       r3, 0x1D4(r1)
  stw       r0, 0x4(r3)

.loc_0xE4:
  li        r3, 0x8
  bl        -0xE21EC
  addi      r21, r3, 0
  mr.       r0, r21
  beq-      .loc_0x118
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r21)
  li        r0, 0
  lis       r3, 0x802D
  stw       r0, 0x0(r21)
  subi      r0, r3, 0x42D8
  stw       r0, 0x4(r21)

.loc_0x118:
  li        r3, 0x8
  bl        -0xE2220
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x14C
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r24)
  li        r0, 0x2
  lis       r3, 0x802D
  stw       r0, 0x0(r24)
  subi      r0, r3, 0x486C
  stw       r0, 0x4(r24)

.loc_0x14C:
  li        r3, 0x8
  bl        -0xE2254
  addi      r23, r3, 0
  mr.       r0, r23
  beq-      .loc_0x18C
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r23)
  li        r0, 0xD
  lis       r3, 0x802D
  stw       r0, 0x0(r23)
  subi      r0, r3, 0x47F0
  lis       r3, 0x802C
  stw       r0, 0x4(r23)
  addi      r0, r3, 0x6CC4
  stw       r0, 0x4(r23)

.loc_0x18C:
  li        r3, 0x14
  bl        -0xE2294
  addi      r22, r3, 0
  mr.       r0, r22
  beq-      .loc_0x1E4
  lwz       r4, 0x84(r16)
  lis       r3, 0x802C
  lis       r5, 0x802D
  lwz       r4, 0x4(r4)
  addi      r3, r3, 0x6620
  li        r0, -0x1
  lwz       r4, 0x0(r4)
  subi      r6, r5, 0x35F4
  li        r5, 0
  lfs       f0, 0xCC(r4)
  stw       r3, 0x4(r22)
  stw       r0, 0x0(r22)
  stw       r6, 0x4(r22)
  stw       r5, 0x8(r22)
  stfs      f0, 0xC(r22)
  lfs       f0, -0x5DE0(r2)
  stfs      f0, 0x10(r22)

.loc_0x1E4:
  li        r3, 0xC
  bl        -0xE22EC
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x220
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r30)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r30)
  subi      r3, r3, 0x3630
  li        r0, 0
  stw       r3, 0x4(r30)
  stw       r0, 0x8(r30)

.loc_0x220:
  li        r3, 0x8
  bl        -0xE2328
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x254
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x1
  lis       r3, 0x802C
  stw       r0, 0x0(r28)
  addi      r0, r3, 0x6DA4
  stw       r0, 0x4(r28)

.loc_0x254:
  li        r3, 0x10
  bl        -0xE235C
  addi      r14, r3, 0
  mr.       r0, r14
  beq-      .loc_0x290
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r14)
  li        r0, 0x5
  lis       r3, 0x802C
  stw       r0, 0x0(r14)
  addi      r0, r3, 0x6E14
  stw       r0, 0x4(r14)
  stw       r30, 0x8(r14)
  stw       r28, 0xC(r14)

.loc_0x290:
  li        r3, 0xC
  bl        -0xE2398
  stw       r3, 0x1D0(r1)
  lwz       r0, 0x1D0(r1)
  cmplwi    r0, 0
  beq-      .loc_0x2EC
  lwz       r4, 0x84(r16)
  lis       r3, 0x802C
  lis       r5, 0x802D
  lwz       r4, 0x4(r4)
  addi      r3, r3, 0x6620
  li        r0, 0xC
  lwz       r4, 0x0(r4)
  subi      r5, r5, 0x7AD4
  lfs       f0, 0x3C(r4)
  lwz       r4, 0x1D0(r1)
  stw       r3, 0x4(r4)
  lwz       r3, 0x1D0(r1)
  stw       r0, 0x0(r3)
  lwz       r3, 0x1D0(r1)
  stw       r5, 0x4(r3)
  lwz       r3, 0x1D0(r1)
  stfs      f0, 0x8(r3)

.loc_0x2EC:
  li        r3, 0x8
  bl        -0xE23F4
  stw       r3, 0x1CC(r1)
  lwz       r0, 0x1CC(r1)
  cmplwi    r0, 0
  beq-      .loc_0x330
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  lwz       r3, 0x1CC(r1)
  lis       r4, 0x802C
  stw       r0, 0x4(r3)
  li        r0, 0x4
  lwz       r3, 0x1CC(r1)
  stw       r0, 0x0(r3)
  addi      r0, r4, 0x677C
  lwz       r3, 0x1CC(r1)
  stw       r0, 0x4(r3)

.loc_0x330:
  li        r3, 0x8
  bl        -0xE2438
  addi      r17, r3, 0
  mr.       r0, r17
  beq-      .loc_0x364
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r17)
  li        r0, 0x8
  lis       r3, 0x802C
  stw       r0, 0x0(r17)
  addi      r0, r3, 0x69A4
  stw       r0, 0x4(r17)

.loc_0x364:
  li        r3, 0x8
  bl        -0xE246C
  addi      r15, r3, 0
  mr.       r0, r15
  beq-      .loc_0x398
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r15)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r15)
  subi      r0, r3, 0x45B8
  stw       r0, 0x4(r15)

.loc_0x398:
  li        r3, 0x8
  bl        -0xE24A0
  addi      r18, r3, 0
  mr.       r0, r18
  beq-      .loc_0x3CC
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r18)
  li        r0, 0xA
  lis       r3, 0x802D
  stw       r0, 0x0(r18)
  subi      r0, r3, 0x45FC
  stw       r0, 0x4(r18)

.loc_0x3CC:
  li        r3, 0x24
  bl        -0xE24D4
  stw       r3, 0x1C8(r1)
  lwz       r3, 0x1C8(r1)
  cmplwi    r3, 0
  beq-      .loc_0x3EC
  lfs       f1, -0x5D68(r2)
  bl        0x1314

.loc_0x3EC:
  li        r3, 0xC
  bl        -0xE24F4
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x434
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r30)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r30)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r30)
  li        r0, 0
  subi      r3, r3, 0x447C
  stw       r0, 0x8(r30)
  stw       r3, 0x4(r30)

.loc_0x434:
  li        r3, 0x8
  bl        -0xE253C
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x468
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r25)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r25)
  subi      r0, r3, 0x43C0
  stw       r0, 0x4(r25)

.loc_0x468:
  li        r3, 0xC
  bl        -0xE2570
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x484
  li        r4, 0x4
  bl        -0x24F0

.loc_0x484:
  li        r0, 0
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  stwx      r19, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r4, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  li        r3, 0x3
  stwx      r24, r4, r0
  rlwinm    r0,r5,2,0,29
  rlwinm    r5,r3,2,0,29
  lwz       r4, 0x8(r29)
  li        r3, 0xC
  stwx      r25, r4, r0
  lwz       r4, 0x8(r29)
  stwx      r30, r4, r5
  lwz       r4, 0x8(r26)
  stw       r29, 0x0(r4)
  bl        -0xE25D4
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x514
  lwz       r5, 0x84(r16)
  lis       r4, 0x802C
  lis       r3, 0x802D
  lwz       r5, 0x4(r5)
  addi      r4, r4, 0x6620
  li        r0, -0x1
  lwz       r5, 0x0(r5)
  subi      r3, r3, 0x434C
  lfs       f0, 0xD0(r5)
  stw       r4, 0x4(r29)
  stw       r0, 0x0(r29)
  stw       r3, 0x4(r29)
  stfs      f0, 0x8(r29)

.loc_0x514:
  li        r3, 0x8
  bl        -0xE261C
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0x548
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, 0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x42D8
  stw       r0, 0x4(r27)

.loc_0x548:
  li        r3, 0x8
  bl        -0xE2650
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x57C
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, 0xE
  lis       r3, 0x802C
  stw       r0, 0x0(r28)
  addi      r0, r3, 0x6DDC
  stw       r0, 0x4(r28)

.loc_0x57C:
  li        r3, 0xC
  bl        -0xE2684
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x598
  li        r4, 0x5
  bl        -0x2604

.loc_0x598:
  li        r0, 0
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,2,0,29
  stwx      r19, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,2,0,29
  li        r4, 0x3
  stwx      r24, r3, r0
  li        r0, 0x4
  rlwinm    r5,r5,2,0,29
  lwz       r3, 0x8(r30)
  rlwinm    r4,r4,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r29, r3, r5
  li        r3, 0xC
  lwz       r5, 0x8(r30)
  stwx      r27, r5, r4
  lwz       r4, 0x8(r30)
  stwx      r28, r4, r0
  lwz       r4, 0x8(r26)
  stw       r30, 0x34(r4)
  bl        -0xE26F8
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x62C
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r29)
  li        r0, 0x6
  lis       r3, 0x802D
  stw       r0, 0x0(r29)
  subi      r3, r3, 0x6A6C
  li        r0, 0x1
  stw       r3, 0x4(r29)
  stw       r0, 0x8(r29)

.loc_0x62C:
  li        r3, 0xC
  bl        -0xE2734
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x648
  li        r4, 0x4
  bl        -0x26B4

.loc_0x648:
  li        r0, 0
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,2,0,29
  stwx      r19, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r4, 0x8(r30)
  rlwinm    r0,r0,2,0,29
  li        r3, 0x3
  stwx      r23, r4, r0
  rlwinm    r0,r5,2,0,29
  rlwinm    r5,r3,2,0,29
  lwz       r4, 0x8(r30)
  li        r3, 0xC
  stwx      r24, r4, r0
  lwz       r4, 0x8(r30)
  stwx      r29, r4, r5
  lwz       r4, 0x8(r26)
  stw       r30, 0x38(r4)
  bl        -0xE2798
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x6D8
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r30)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r30)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r30)
  li        r0, 0xA
  subi      r3, r3, 0x447C
  stw       r0, 0x8(r30)
  stw       r3, 0x4(r30)

.loc_0x6D8:
  li        r3, 0xC
  bl        -0xE27E0
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x6F4
  li        r4, 0x4
  bl        -0x2760

.loc_0x6F4:
  li        r0, 0
  lwz       r3, 0x8(r29)
  rlwinm    r0,r0,2,0,29
  stwx      r19, r3, r0
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
  stwx      r25, r4, r0
  lwz       r4, 0x8(r29)
  stwx      r30, r4, r5
  lwz       r4, 0x8(r26)
  stw       r29, 0x4(r4)
  bl        -0xE2844
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x770
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r0, r3, 0x482C
  stw       r0, 0x4(r28)

.loc_0x770:
  li        r3, 0x14
  bl        -0xE2878
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x7C8
  lwz       r4, 0x84(r16)
  lis       r3, 0x802C
  lis       r5, 0x802D
  lwz       r4, 0x4(r4)
  addi      r3, r3, 0x6620
  li        r0, 0x3
  lwz       r4, 0x0(r4)
  subi      r6, r5, 0x35D8
  li        r5, 0x1
  lfs       f0, 0xC8(r4)
  stw       r3, 0x4(r30)
  stw       r0, 0x0(r30)
  stw       r6, 0x4(r30)
  stw       r5, 0x8(r30)
  stfs      f0, 0xC(r30)
  lfs       f0, -0x5DE0(r2)
  stfs      f0, 0x10(r30)

.loc_0x7C8:
  li        r3, 0xC
  bl        -0xE28D0
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x810
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
  subi      r3, r3, 0x6AD8
  stw       r0, 0x8(r29)
  stw       r3, 0x4(r29)

.loc_0x810:
  li        r3, 0x8
  bl        -0xE2918
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0x844
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x4310
  stw       r0, 0x4(r27)

.loc_0x844:
  li        r3, 0xC
  bl        -0xE294C
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x860
  li        r4, 0x5
  bl        -0x28CC

.loc_0x860:
  li        r0, 0
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  stwx      r19, r3, r0
  li        r0, 0x1
  li        r4, 0x2
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  li        r6, 0x3
  stwx      r29, r3, r0
  li        r0, 0x4
  rlwinm    r5,r4,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r4,r6,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r30, r3, r5
  li        r3, 0x8
  lwz       r5, 0x8(r31)
  stwx      r27, r5, r4
  lwz       r4, 0x8(r31)
  stwx      r28, r4, r0
  lwz       r4, 0x8(r26)
  stw       r31, 0x8(r4)
  bl        -0xE29C0
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x8EC
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r0, r3, 0x4388
  stw       r0, 0x4(r28)

.loc_0x8EC:
  li        r3, 0xC
  bl        -0xE29F4
  addi      r27, r3, 0
  mr.       r3, r27
  beq-      .loc_0x908
  li        r4, 0x2
  bl        -0x2974

.loc_0x908:
  li        r0, 0
  lwz       r3, 0x8(r27)
  rlwinm    r0,r0,2,0,29
  stwx      r25, r3, r0
  li        r0, 0x1
  rlwinm    r0,r0,2,0,29
  lwz       r4, 0x8(r27)
  li        r3, 0xC
  stwx      r28, r4, r0
  lwz       r4, 0x8(r26)
  stw       r27, 0xC(r4)
  bl        -0xE2A38
  addi      r31, r3, 0
  mr.       r0, r31
  beq-      .loc_0x978
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r31)
  li        r0, -0x2
  lis       r3, 0x802D
  stw       r0, 0x0(r31)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802C
  stw       r0, 0x4(r31)
  li        r0, 0x9
  addi      r3, r3, 0x6704
  stw       r0, 0x8(r31)
  stw       r3, 0x4(r31)

.loc_0x978:
  li        r3, 0xC
  bl        -0xE2A80
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x994
  li        r4, 0x6
  bl        -0x2A00

.loc_0x994:
  li        r0, 0
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,2,0,29
  stwx      r19, r3, r0
  li        r0, 0x1
  li        r6, 0x2
  lwz       r3, 0x8(r30)
  rlwinm    r4,r0,2,0,29
  li        r0, 0x3
  stwx      r21, r3, r4
  li        r4, 0x4
  li        r5, 0x5
  lwz       r3, 0x8(r30)
  rlwinm    r6,r6,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r24, r3, r6
  rlwinm    r4,r4,2,0,29
  rlwinm    r6,r5,2,0,29
  lwz       r5, 0x8(r30)
  li        r3, 0x10
  stwx      r23, r5, r0
  lwz       r5, 0x8(r30)
  stwx      r15, r5, r4
  lwz       r4, 0x8(r30)
  stwx      r31, r4, r6
  lwz       r4, 0x8(r26)
  stw       r30, 0x10(r4)
  bl        -0xE2B04
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0xA40
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r29)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r29)
  subi      r3, r3, 0x7404
  li        r0, 0
  stw       r3, 0x4(r29)
  stw       r0, 0x8(r29)
  lwz       r0, -0x99C(r13)
  stw       r0, 0xC(r29)

.loc_0xA40:
  li        r3, 0xC
  bl        -0xE2B48
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0xA84
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r30)
  li        r0, 0xB
  lis       r3, 0x802D
  stw       r0, 0x0(r30)
  subi      r4, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r4, 0x4(r30)
  subi      r3, r3, 0x6A8C
  stw       r0, 0x8(r30)
  stw       r3, 0x4(r30)

.loc_0xA84:
  li        r3, 0xC
  bl        -0xE2B8C
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0xAA0
  li        r4, 0x8
  bl        -0x2B0C

.loc_0xAA0:
  li        r0, 0
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  stwx      r20, r3, r0
  li        r4, 0x1
  li        r0, 0x2
  lwz       r3, 0x8(r31)
  rlwinm    r4,r4,2,0,29
  li        r7, 0x3
  stwx      r21, r3, r4
  li        r6, 0x4
  li        r5, 0x5
  lwz       r3, 0x8(r31)
  rlwinm    r4,r0,2,0,29
  li        r0, 0x6
  stwx      r24, r3, r4
  li        r4, 0x7
  rlwinm    r7,r7,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r6,r6,2,0,29
  rlwinm    r5,r5,2,0,29
  stwx      r23, r3, r7
  rlwinm    r0,r0,2,0,29
  rlwinm    r7,r4,2,0,29
  lwz       r4, 0x8(r31)
  li        r3, 0xC
  stwx      r15, r4, r6
  lwz       r4, 0x8(r31)
  stwx      r29, r4, r5
  lwz       r4, 0x8(r31)
  stwx      r30, r4, r0
  lwz       r4, 0x8(r31)
  stwx      r22, r4, r7
  lwz       r4, 0x8(r26)
  stw       r31, 0x14(r4)
  bl        -0xE2C30
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0xB70
  lwz       r5, 0x84(r16)
  lis       r4, 0x802C
  lis       r3, 0x802D
  lwz       r5, 0x4(r5)
  addi      r4, r4, 0x6620
  li        r0, 0xC
  lwz       r5, 0x0(r5)
  subi      r3, r3, 0x7AD4
  lfs       f0, 0x40(r5)
  stw       r4, 0x4(r28)
  stw       r0, 0x0(r28)
  stw       r3, 0x4(r28)
  stfs      f0, 0x8(r28)

.loc_0xB70:
  li        r3, 0x8
  bl        -0xE2C78
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0xBA4
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r25)
  li        r0, 0xA
  lis       r3, 0x802D
  stw       r0, 0x0(r25)
  subi      r0, r3, 0x7B5C
  stw       r0, 0x4(r25)

.loc_0xBA4:
  li        r3, 0x8
  bl        -0xE2CAC
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0xBD8
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, 0x7
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x6968
  stw       r0, 0x4(r27)

.loc_0xBD8:
  li        r3, 0xC
  bl        -0xE2CE0
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0xC20
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r30)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r30)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r30)
  li        r0, 0x2
  subi      r3, r3, 0x6A8C
  stw       r0, 0x8(r30)
  stw       r3, 0x4(r30)

.loc_0xC20:
  li        r3, 0x10
  bl        -0xE2D28
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0xC64
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r29)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r29)
  subi      r0, r3, 0x6D08
  li        r3, 0
  stw       r0, 0x4(r29)
  li        r0, 0x1
  stw       r3, 0x8(r29)
  stw       r0, 0xC(r29)

.loc_0xC64:
  li        r3, 0xC
  bl        -0xE2D6C
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0xC80
  li        r4, 0xB
  bl        -0x2CEC

.loc_0xC80:
  li        r0, 0
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  stwx      r20, r3, r0
  li        r4, 0x1
  li        r0, 0x2
  lwz       r3, 0x8(r31)
  rlwinm    r4,r4,2,0,29
  li        r5, 0x3
  stwx      r21, r3, r4
  li        r4, 0x4
  li        r9, 0x5
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  li        r8, 0x6
  stwx      r24, r3, r0
  li        r6, 0x7
  li        r7, 0x8
  lwz       r3, 0x8(r31)
  rlwinm    r0,r5,2,0,29
  li        r10, 0x9
  stwx      r23, r3, r0
  li        r0, 0xA
  rlwinm    r4,r4,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r5,r9,2,0,29
  rlwinm    r9,r8,2,0,29
  stwx      r17, r3, r4
  rlwinm    r6,r6,2,0,29
  rlwinm    r7,r7,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r8,r10,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r18, r3, r5
  li        r3, 0xC
  lwz       r4, 0x8(r31)
  stwx      r25, r4, r9
  lwz       r4, 0x8(r31)
  stwx      r27, r4, r6
  lwz       r4, 0x8(r31)
  stwx      r28, r4, r7
  lwz       r4, 0x8(r31)
  stwx      r30, r4, r8
  lwz       r4, 0x8(r31)
  stwx      r29, r4, r0
  lwz       r4, 0x8(r26)
  stw       r31, 0x3C(r4)
  bl        -0xE2E40
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0xD54
  li        r4, 0xA
  bl        -0x2DC0

.loc_0xD54:
  li        r0, 0
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  stwx      r20, r3, r0
  li        r0, 0x1
  li        r5, 0x2
  lwz       r3, 0x8(r31)
  rlwinm    r4,r0,2,0,29
  li        r0, 0x3
  stwx      r21, r3, r4
  li        r3, 0x4
  li        r8, 0x5
  lwz       r4, 0x8(r31)
  rlwinm    r5,r5,2,0,29
  li        r9, 0x6
  stwx      r24, r4, r5
  li        r7, 0x7
  li        r4, 0x8
  lwz       r6, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  li        r5, 0x9
  stwx      r23, r6, r0
  rlwinm    r0,r3,2,0,29
  rlwinm    r8,r8,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r9,r9,2,0,29
  rlwinm    r7,r7,2,0,29
  stwx      r17, r3, r0
  rlwinm    r6,r4,2,0,29
  rlwinm    r0,r5,2,0,29
  lwz       r4, 0x8(r31)
  li        r3, 0x8
  stwx      r18, r4, r8
  lwz       r4, 0x8(r31)
  stwx      r25, r4, r9
  lwz       r4, 0x8(r31)
  stwx      r27, r4, r7
  lwz       r4, 0x8(r31)
  stwx      r28, r4, r6
  lwz       r4, 0x8(r31)
  stwx      r30, r4, r0
  lwz       r4, 0x8(r26)
  stw       r31, 0x18(r4)
  bl        -0xE2F04
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0xE30
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, 0xB
  lis       r3, 0x802C
  stw       r0, 0x0(r28)
  addi      r0, r3, 0x6DDC
  stw       r0, 0x4(r28)

.loc_0xE30:
  li        r3, 0xC
  bl        -0xE2F38
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xE4C
  li        r4, 0x5
  bl        -0x2EB8

.loc_0xE4C:
  li        r0, 0
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,2,0,29
  stwx      r21, r3, r0
  li        r0, 0x1
  li        r4, 0x2
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,2,0,29
  li        r5, 0x3
  stwx      r24, r3, r0
  li        r0, 0x4
  rlwinm    r4,r4,2,0,29
  lwz       r3, 0x8(r30)
  rlwinm    r5,r5,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r23, r3, r4
  li        r3, 0x10
  lwz       r4, 0x8(r30)
  stwx      r22, r4, r5
  lwz       r4, 0x8(r30)
  stwx      r28, r4, r0
  lwz       r4, 0x8(r26)
  stw       r30, 0x28(r4)
  bl        -0xE2FAC
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0xF0C
  lwz       r3, 0x84(r16)
  lis       r7, 0x802C
  lis       r6, 0x802D
  lwz       r3, 0x4(r3)
  lis       r5, 0x802D
  lis       r4, 0x802D
  lwz       r3, 0x0(r3)
  addi      r7, r7, 0x6620
  li        r0, 0x6
  lfs       f0, 0x14(r3)
  subi      r6, r6, 0x6A6C
  li        r3, 0x4
  stw       r7, 0x4(r30)
  subi      r5, r5, 0x6A8C
  subi      r4, r4, 0x67CC
  stw       r0, 0x0(r30)
  stw       r6, 0x4(r30)
  stw       r3, 0x8(r30)
  stw       r5, 0x4(r30)
  stw       r4, 0x4(r30)
  stfs      f0, 0xC(r30)

.loc_0xF0C:
  li        r3, 0x8
  bl        -0xE3014
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0xF40
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r0, r3, 0x69B4
  stw       r0, 0x4(r28)

.loc_0xF40:
  li        r3, 0xC
  bl        -0xE3048
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0xF5C
  li        r4, 0x9
  bl        -0x2FC8

.loc_0xF5C:
  li        r0, 0
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  stwx      r20, r3, r0
  li        r4, 0x1
  li        r0, 0x2
  lwz       r3, 0x8(r31)
  rlwinm    r5,r4,2,0,29
  li        r4, 0x3
  stwx      r21, r3, r5
  li        r5, 0x4
  li        r6, 0x5
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  li        r7, 0x6
  stwx      r24, r3, r0
  li        r0, 0x7
  li        r9, 0x8
  lwz       r3, 0x8(r31)
  rlwinm    r4,r4,2,0,29
  rlwinm    r8,r5,2,0,29
  stwx      r23, r3, r4
  rlwinm    r6,r6,2,0,29
  rlwinm    r5,r7,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  rlwinm    r7,r9,2,0,29
  stwx      r17, r3, r8
  li        r3, 0x8
  lwz       r4, 0x8(r31)
  stwx      r18, r4, r6
  lwz       r4, 0x8(r31)
  stwx      r25, r4, r5
  lwz       r4, 0x8(r31)
  stwx      r28, r4, r0
  lwz       r4, 0x8(r31)
  stwx      r30, r4, r7
  lwz       r4, 0x8(r26)
  stw       r31, 0x1C(r4)
  bl        -0xE30FC
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0x1028
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, -0x1
  lis       r3, 0x802D
  stw       r0, 0x0(r27)
  subi      r0, r3, 0x7B5C
  stw       r0, 0x4(r27)

.loc_0x1028:
  li        r3, 0x8
  bl        -0xE3130
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x105C
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, 0xC
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r0, r3, 0x7A98
  stw       r0, 0x4(r28)

.loc_0x105C:
  li        r3, 0x10
  bl        -0xE3164
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x10C4
  lwz       r3, 0x84(r16)
  lis       r7, 0x802C
  lis       r6, 0x802D
  lwz       r3, 0x4(r3)
  lis       r5, 0x802D
  lis       r4, 0x802D
  lwz       r3, 0x0(r3)
  addi      r7, r7, 0x6620
  li        r0, -0x1
  lfs       f0, 0x10(r3)
  subi      r6, r6, 0x6A6C
  li        r3, 0x6
  stw       r7, 0x4(r30)
  subi      r5, r5, 0x6A8C
  subi      r4, r4, 0x6574
  stw       r0, 0x0(r30)
  stw       r6, 0x4(r30)
  stw       r3, 0x8(r30)
  stw       r5, 0x4(r30)
  stw       r4, 0x4(r30)
  stfs      f0, 0xC(r30)

.loc_0x10C4:
  li        r3, 0xC
  bl        -0xE31CC
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x10E0
  li        r4, 0xD
  bl        -0x314C

.loc_0x10E0:
  li        r0, 0
  lwz       r3, 0x8(r31)
  rlwinm    r4,r0,2,0,29
  lwz       r0, 0x1D4(r1)
  li        r6, 0x2
  stwx      r0, r3, r4
  li        r0, 0x1
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r7,r6,2,0,29
  li        r0, 0x3
  stwx      r30, r3, r4
  li        r4, 0x4
  li        r9, 0x8
  lwz       r3, 0x8(r31)
  li        r8, 0x9
  rlwinm    r0,r0,2,0,29
  stwx      r21, r3, r7
  li        r7, 0x7
  rlwinm    r4,r4,2,0,29
  lwz       r3, 0x8(r31)
  li        r5, 0x5
  li        r6, 0x6
  stwx      r24, r3, r0
  rlwinm    r7,r7,2,0,29
  rlwinm    r9,r9,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r8,r8,2,0,29
  li        r0, 0xA
  stwx      r23, r3, r4
  rlwinm    r4,r5,2,0,29
  rlwinm    r3,r6,2,0,29
  lwz       r6, 0x1CC(r1)
  lwz       r5, 0x8(r31)
  li        r11, 0xB
  stwx      r6, r5, r4
  rlwinm    r5,r0,2,0,29
  li        r10, 0xC
  lwz       r6, 0x8(r31)
  rlwinm    r4,r11,2,0,29
  rlwinm    r0,r10,2,0,29
  stwx      r17, r6, r3
  li        r3, 0xC
  lwz       r6, 0x8(r31)
  stwx      r18, r6, r7
  lwz       r7, 0x1D0(r1)
  lwz       r6, 0x8(r31)
  stwx      r7, r6, r9
  lwz       r6, 0x8(r31)
  stwx      r27, r6, r8
  lwz       r6, 0x8(r31)
  stwx      r28, r6, r5
  lwz       r5, 0x8(r31)
  stwx      r14, r5, r4
  lwz       r5, 0x1C8(r1)
  lwz       r4, 0x8(r31)
  stwx      r5, r4, r0
  lwz       r4, 0x8(r26)
  stw       r31, 0x2C(r4)
  bl        -0xE32D0
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x1204
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r28)
  li        r0, -0x2
  lis       r3, 0x802D
  stw       r0, 0x0(r28)
  subi      r3, r3, 0x6A6C
  li        r0, 0x8
  stw       r3, 0x4(r28)
  stw       r0, 0x8(r28)

.loc_0x1204:
  li        r3, 0x8
  bl        -0xE330C
  addi      r27, r3, 0
  mr.       r0, r27
  beq-      .loc_0x1238
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r27)
  li        r0, 0x9
  lis       r3, 0x802C
  stw       r0, 0x0(r27)
  addi      r0, r3, 0x68C8
  stw       r0, 0x4(r27)

.loc_0x1238:
  li        r3, 0xC
  bl        -0xE3340
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x1274
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r29)
  li        r0, 0x9
  lis       r3, 0x802C
  stw       r0, 0x0(r29)
  addi      r3, r3, 0x6B54
  li        r0, 0x1
  stw       r3, 0x4(r29)
  stw       r0, 0x8(r29)

.loc_0x1274:
  li        r3, 0xC
  bl        -0xE337C
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x1290
  li        r4, 0x8
  bl        -0x32FC

.loc_0x1290:
  li        r0, 0
  lwz       r3, 0x8(r31)
  rlwinm    r0,r0,2,0,29
  stwx      r19, r3, r0
  li        r4, 0x1
  li        r0, 0x2
  lwz       r3, 0x8(r31)
  rlwinm    r4,r4,2,0,29
  li        r6, 0x3
  stwx      r21, r3, r4
  li        r5, 0x4
  li        r7, 0x5
  lwz       r3, 0x8(r31)
  rlwinm    r4,r0,2,0,29
  li        r0, 0x6
  stwx      r24, r3, r4
  li        r4, 0x7
  rlwinm    r6,r6,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r5,r5,2,0,29
  rlwinm    r7,r7,2,0,29
  stwx      r23, r3, r6
  rlwinm    r0,r0,2,0,29
  rlwinm    r6,r4,2,0,29
  lwz       r4, 0x8(r31)
  li        r3, 0xC
  stwx      r15, r4, r5
  lwz       r4, 0x8(r31)
  stwx      r27, r4, r7
  lwz       r4, 0x8(r31)
  stwx      r29, r4, r0
  lwz       r4, 0x8(r31)
  stwx      r28, r4, r6
  lwz       r4, 0x8(r26)
  stw       r31, 0x20(r4)
  bl        -0xE3420
  addi      r31, r3, 0
  mr.       r0, r31
  beq-      .loc_0x1360
  lis       r3, 0x802C
  addi      r0, r3, 0x6620
  stw       r0, 0x4(r31)
  li        r0, 0xB
  lis       r3, 0x802D
  stw       r0, 0x0(r31)
  subi      r0, r3, 0x6A6C
  lis       r3, 0x802D
  stw       r0, 0x4(r31)
  li        r0, 0x5
  subi      r3, r3, 0x6B9C
  stw       r0, 0x8(r31)
  stw       r3, 0x4(r31)

.loc_0x1360:
  li        r3, 0xC
  bl        -0xE3468
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x137C
  li        r4, 0x5
  bl        -0x33E8

.loc_0x137C:
  li        r0, 0
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,2,0,29
  stwx      r21, r3, r0
  li        r0, 0x1
  li        r4, 0x2
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,2,0,29
  li        r5, 0x3
  stwx      r24, r3, r0
  li        r0, 0x4
  rlwinm    r4,r4,2,0,29
  lwz       r3, 0x8(r30)
  rlwinm    r5,r5,2,0,29
  rlwinm    r0,r0,2,0,29
  stwx      r23, r3, r4
  li        r3, 0x10
  lwz       r4, 0x8(r30)
  stwx      r15, r4, r5
  lwz       r4, 0x8(r30)
  stwx      r31, r4, r0
  lwz       r4, 0x8(r26)
  stw       r30, 0x24(r4)
  bl        -0xE34DC
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x143C
  lwz       r3, 0x84(r16)
  lis       r7, 0x802C
  lis       r6, 0x802D
  lwz       r3, 0x4(r3)
  lis       r5, 0x802D
  lis       r4, 0x802D
  lwz       r3, 0x0(r3)
  addi      r7, r7, 0x6620
  li        r0, -0x1
  lfs       f0, 0x10(r3)
  subi      r6, r6, 0x6A6C
  li        r3, 0x6
  stw       r7, 0x4(r30)
  subi      r5, r5, 0x6A8C
  subi      r4, r4, 0x65C4
  stw       r0, 0x0(r30)
  stw       r6, 0x4(r30)
  stw       r3, 0x8(r30)
  stw       r5, 0x4(r30)
  stw       r4, 0x4(r30)
  stfs      f0, 0xC(r30)

.loc_0x143C:
  li        r3, 0xC
  bl        -0xE3544
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x1484
  lwz       r5, 0x84(r16)
  lis       r4, 0x802C
  lis       r3, 0x802D
  lwz       r5, 0x4(r5)
  addi      r4, r4, 0x6620
  li        r0, 0x6
  lwz       r5, 0x0(r5)
  subi      r3, r3, 0x7B18
  lfs       f0, 0x40(r5)
  stw       r4, 0x4(r28)
  stw       r0, 0x0(r28)
  stw       r3, 0x4(r28)
  stfs      f0, 0x8(r28)

.loc_0x1484:
  li        r3, 0xC
  bl        -0xE358C
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x14A0
  li        r4, 0xA
  bl        -0x350C

.loc_0x14A0:
  li        r0, 0
  lwz       r3, 0x8(r31)
  rlwinm    r4,r0,2,0,29
  lwz       r0, 0x1D4(r1)
  li        r5, 0x2
  stwx      r0, r3, r4
  li        r0, 0x1
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r7,r5,2,0,29
  li        r0, 0x3
  stwx      r30, r3, r4
  li        r8, 0x9
  rlwinm    r0,r0,2,0,29
  lwz       r6, 0x8(r31)
  li        r3, 0x4
  li        r4, 0x5
  stwx      r21, r6, r7
  li        r5, 0x6
  li        r6, 0x7
  lwz       r9, 0x8(r31)
  li        r7, 0x8
  rlwinm    r8,r8,2,0,29
  stwx      r24, r9, r0
  rlwinm    r0,r3,2,0,29
  rlwinm    r9,r4,2,0,29
  lwz       r3, 0x8(r31)
  rlwinm    r4,r5,2,0,29
  rlwinm    r5,r6,2,0,29
  stwx      r23, r3, r0
  rlwinm    r0,r7,2,0,29
  lwz       r7, 0x1CC(r1)
  mr        r3, r26
  lwz       r6, 0x8(r31)
  stwx      r7, r6, r9
  lwz       r6, 0x8(r31)
  stwx      r17, r6, r4
  lwz       r4, 0x8(r31)
  stwx      r18, r4, r5
  lwz       r4, 0x8(r31)
  stwx      r28, r4, r0
  lwz       r0, 0x1C8(r1)
  lwz       r4, 0x8(r31)
  stwx      r0, r4, r8
  lwz       r4, 0x8(r26)
  stw       r31, 0x30(r4)
  lmw       r14, 0x1D8(r1)
  lwz       r0, 0x224(r1)
  addi      r1, r1, 0x220
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012A674
 * Size:	000148
 */
void TaiChappyCryAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x802B
  stw       r0, 0x4(r1)
  lis       r11, 0x802C
  lis       r10, 0x802D
  stwu      r1, -0x128(r1)
  lis       r8, 0x802C
  lis       r7, 0x802C
  stmw      r23, 0x104(r1)
  subi      r24, r5, 0xF68
  addi      r25, r11, 0x6964
  subi      r26, r10, 0x29D8
  addi      r11, r7, 0x685C
  lis       r9, 0x802D
  subi      r27, r9, 0x2720
  addi      r30, r8, 0x6D60
  addi      r31, r1, 0xC8
  addi      r10, r1, 0xD0
  addi      r9, r1, 0xB4
  addi      r0, r1, 0xDC
  lwz       r6, 0x2C4(r4)
  li        r28, 0x1
  li        r29, 0xF
  lwz       r3, 0x3160(r13)
  lwz       r6, 0x84(r6)
  li        r7, 0x4
  lwz       r6, 0x4(r6)
  addi      r23, r4, 0x94
  addi      r5, r1, 0xF0
  lwz       r12, 0x0(r6)
  lis       r6, 0x802D
  subi      r8, r6, 0x2754
  lfs       f0, 0x68(r12)
  addi      r6, r1, 0xE8
  addi      r12, r1, 0xC0
  stw       r24, 0xB4(r1)
  stw       r24, 0xD0(r1)
  stw       r24, 0xDC(r1)
  stw       r24, 0xF0(r1)
  stw       r25, 0xB4(r1)
  stw       r24, 0xC0(r1)
  stw       r24, 0xC8(r1)
  stw       r25, 0xD0(r1)
  stw       r25, 0xDC(r1)
  stw       r24, 0xE8(r1)
  stw       r25, 0xF0(r1)
  stw       r26, 0xB4(r1)
  stw       r4, 0xB8(r1)
  mr        r4, r23
  stw       r25, 0xC0(r1)
  stw       r25, 0xC8(r1)
  stw       r30, 0xD0(r1)
  stw       r11, 0xDC(r1)
  stw       r25, 0xE8(r1)
  stw       r11, 0xF0(r1)
  stw       r27, 0xC0(r1)
  stw       r27, 0xC8(r1)
  stw       r31, 0xD4(r1)
  stw       r10, 0xE0(r1)
  stw       r8, 0xE8(r1)
  stw       r6, 0xF4(r1)
  stfs      f0, 0xBC(r1)
  stw       r28, 0xC4(r1)
  stw       r29, 0xCC(r1)
  stw       r12, 0xD8(r1)
  stw       r9, 0xE4(r1)
  stw       r7, 0xEC(r1)
  stw       r0, 0xF8(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x6C(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x130
  li        r3, 0
  b         .loc_0x134

.loc_0x130:
  li        r3, 0x1

.loc_0x134:
  lmw       r23, 0x104(r1)
  lwz       r0, 0x12C(r1)
  addi      r1, r1, 0x128
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012A7BC
 * Size:	000048
 */
void TaiChappySmashedAction::actByEvent(TekiEvent &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0x4(r4)
  lwz       r5, 0x2C4(r5)
  lwz       r5, 0x84(r5)
  lwz       r5, 0x0(r5)
  lwz       r5, 0x0(r5)
  lwz       r0, 0x50(r5)
  cmpwi     r0, 0x1
  bne-      .loc_0x34
  li        r3, 0
  b         .loc_0x38

.loc_0x34:
  bl        0x149E8

.loc_0x38:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012A804
 * Size:	000058
 */
void TaiChappyLegEffectAction::TaiChappyLegEffectAction(float)
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
  bl        0x3E04
  lis       r3, 0x802C
  addi      r0, r3, 0x6C58
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
 * Address:	8012A85C
 * Size:	000090
 */
void TaiChappyLegEffectAction::setType(Vector3f &, int, int)
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
  bl        -0xC298C
  cmpwi     r31, 0x5
  stfs      f1, 0x4(r30)
  bne-      .loc_0x50
  li        r0, 0xF
  stw       r0, 0x14(r29)
  b         .loc_0x6C

.loc_0x50:
  cmpwi     r31, -0x1
  bne-      .loc_0x64
  li        r0, -0x1
  stw       r0, 0x14(r29)
  b         .loc_0x6C

.loc_0x64:
  li        r0, 0x44
  stw       r0, 0x14(r29)

.loc_0x6C:
  li        r0, 0x20
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

/*
 * --INFO--
 * Address:	8012A8EC
 * Size:	000084
 */
void TekiOrCondition::satisfy(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  li        r31, 0x1
  stw       r30, 0x18(r1)
  mr        r30, r4
  stw       r29, 0x14(r1)
  mr        r29, r3
  lwz       r3, 0x4(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x64
  lwz       r3, 0x8(r29)
  mr        r4, r30
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x64
  li        r31, 0

.loc_0x64:
  mr        r3, r31
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
 * Address:	8012A970
 * Size:	000008
 */
void TaiOnceAction::act(Teki &)
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8012A978
 * Size:	000060
 */
void TaiAndAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r4
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r3, 0x8(r3)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0xC(r30)
  mr        r4, r31
  lwz       r12, 0x4(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
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
 * Address:	8012A9D8
 * Size:	000060
 */
void TaiAndAction::finish(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r4
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r3, 0x8(r3)
  lwz       r12, 0x4(r3)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0xC(r30)
  mr        r4, r31
  lwz       r12, 0x4(r3)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
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
 * Address:	8012AA38
 * Size:	000088
 */
void TaiAndAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr        r30, r4
  stw       r29, 0x14(r1)
  mr        r29, r3
  lwz       r3, 0x8(r3)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r31, r3
  lwz       r3, 0xC(r29)
  mr        r4, r30
  lwz       r12, 0x4(r3)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r31,0,24,31
  li        r4, 0
  beq-      .loc_0x68
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x68
  li        r4, 0x1

.loc_0x68:
  lwz       r0, 0x24(r1)
  mr        r3, r4
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}