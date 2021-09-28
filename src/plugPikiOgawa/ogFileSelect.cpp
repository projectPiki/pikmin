

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
 * Address:	80187790
 * Size:	000140
 */
void zen::ogScrFileSelectMgr::copyCardInfosSub()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803A
  stw       r0, 0x4(r1)
  li        r0, 0
  subi      r4, r4, 0x2848
  stwu      r1, -0xC0(r1)
  stw       r31, 0xBC(r1)
  addi      r31, r3, 0
  addi      r3, r4, 0x24
  stw       r0, 0x20(r1)
  addi      r4, r1, 0x18
  stw       r0, 0x48(r1)
  stw       r0, 0x70(r1)
  stw       r0, 0x98(r1)
  bl        -0x110D60
  lwz       r3, 0x18(r1)
  lwz       r0, 0x1C(r1)
  stw       r3, 0x2C(r31)
  stw       r0, 0x30(r31)
  lwz       r3, 0x20(r1)
  lwz       r0, 0x24(r1)
  stw       r3, 0x34(r31)
  stw       r0, 0x38(r31)
  lwz       r3, 0x28(r1)
  lwz       r0, 0x2C(r1)
  stw       r3, 0x3C(r31)
  stw       r0, 0x40(r31)
  lwz       r3, 0x30(r1)
  lwz       r0, 0x34(r1)
  stw       r3, 0x44(r31)
  stw       r0, 0x48(r31)
  lwz       r3, 0x38(r1)
  lwz       r0, 0x3C(r1)
  stw       r3, 0x4C(r31)
  stw       r0, 0x50(r31)
  lwz       r3, 0x40(r1)
  lwz       r0, 0x44(r1)
  stw       r3, 0x54(r31)
  stw       r0, 0x58(r31)
  lwz       r3, 0x48(r1)
  lwz       r0, 0x4C(r1)
  stw       r3, 0x5C(r31)
  stw       r0, 0x60(r31)
  lwz       r3, 0x50(r1)
  lwz       r0, 0x54(r1)
  stw       r3, 0x64(r31)
  stw       r0, 0x68(r31)
  lwz       r3, 0x58(r1)
  lwz       r0, 0x5C(r1)
  stw       r3, 0x6C(r31)
  stw       r0, 0x70(r31)
  lwz       r3, 0x60(r1)
  lwz       r0, 0x64(r1)
  stw       r3, 0x74(r31)
  stw       r0, 0x78(r31)
  lwz       r3, 0x68(r1)
  lwz       r0, 0x6C(r1)
  stw       r3, 0x7C(r31)
  stw       r0, 0x80(r31)
  lwz       r3, 0x70(r1)
  lwz       r0, 0x74(r1)
  stw       r3, 0x84(r31)
  stw       r0, 0x88(r31)
  lwz       r3, 0x78(r1)
  lwz       r0, 0x7C(r1)
  stw       r3, 0x8C(r31)
  stw       r0, 0x90(r31)
  lwz       r3, 0x80(r1)
  lwz       r0, 0x84(r1)
  stw       r3, 0x94(r31)
  stw       r0, 0x98(r31)
  lwz       r3, 0x88(r1)
  lwz       r0, 0x8C(r1)
  stw       r3, 0x9C(r31)
  stw       r0, 0xA0(r31)
  lwz       r0, 0xC4(r1)
  lwz       r31, 0xBC(r1)
  addi      r1, r1, 0xC0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801878D0
 * Size:	0001F4
 */
void zen::ogScrFileSelectMgr::getCardFileInfos()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803A
  stw       r0, 0x4(r1)
  stwu      r1, -0xE0(r1)
  stmw      r24, 0xC0(r1)
  subi      r28, r4, 0x2848
  addi      r27, r28, 0x24
  addi      r29, r3, 0
  addi      r3, r27, 0
  li        r4, 0x1
  bl        -0x113A08
  cmpwi     r3, 0
  bne-      .loc_0x1DC
  lwz       r0, 0x5C(r28)
  cmpwi     r0, 0
  blt-      .loc_0x1DC
  lwz       r7, 0xAC(r28)
  mr        r3, r27
  lbz       r31, 0xB0(r28)
  rlwinm    r0,r7,0,31,31
  lbz       r30, 0xB1(r28)
  neg       r6, r0
  subic     r5, r6, 0x1
  rlwinm    r4,r7,0,30,30
  rlwinm    r0,r7,0,29,29
  subfe     r26, r5, r6
  neg       r5, r4
  subic     r4, r5, 0x1
  subfe     r25, r4, r5
  neg       r4, r0
  subic     r0, r4, 0x1
  subfe     r24, r0, r4
  bl        -0x113660
  addi      r28, r28, 0x94
  addi      r3, r28, 0
  addi      r4, r26, 0
  bl        -0x133BA8
  addi      r3, r28, 0
  addi      r4, r25, 0
  bl        -0x133C50
  addi      r3, r28, 0
  addi      r4, r24, 0
  bl        -0x133B08
  addi      r3, r28, 0
  addi      r4, r31, 0
  bl        -0x133CE8
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        -0x133CB4
  li        r0, 0
  stw       r0, 0x20(r1)
  addi      r3, r27, 0
  addi      r4, r1, 0x18
  stw       r0, 0x48(r1)
  stw       r0, 0x70(r1)
  stw       r0, 0x98(r1)
  bl        -0x110F48
  lwz       r4, 0x18(r1)
  li        r3, 0x1
  lwz       r0, 0x1C(r1)
  stw       r4, 0x2C(r29)
  stw       r0, 0x30(r29)
  lwz       r4, 0x20(r1)
  lwz       r0, 0x24(r1)
  stw       r4, 0x34(r29)
  stw       r0, 0x38(r29)
  lwz       r4, 0x28(r1)
  lwz       r0, 0x2C(r1)
  stw       r4, 0x3C(r29)
  stw       r0, 0x40(r29)
  lwz       r4, 0x30(r1)
  lwz       r0, 0x34(r1)
  stw       r4, 0x44(r29)
  stw       r0, 0x48(r29)
  lwz       r4, 0x38(r1)
  lwz       r0, 0x3C(r1)
  stw       r4, 0x4C(r29)
  stw       r0, 0x50(r29)
  lwz       r4, 0x40(r1)
  lwz       r0, 0x44(r1)
  stw       r4, 0x54(r29)
  stw       r0, 0x58(r29)
  lwz       r4, 0x48(r1)
  lwz       r0, 0x4C(r1)
  stw       r4, 0x5C(r29)
  stw       r0, 0x60(r29)
  lwz       r4, 0x50(r1)
  lwz       r0, 0x54(r1)
  stw       r4, 0x64(r29)
  stw       r0, 0x68(r29)
  lwz       r4, 0x58(r1)
  lwz       r0, 0x5C(r1)
  stw       r4, 0x6C(r29)
  stw       r0, 0x70(r29)
  lwz       r4, 0x60(r1)
  lwz       r0, 0x64(r1)
  stw       r4, 0x74(r29)
  stw       r0, 0x78(r29)
  lwz       r4, 0x68(r1)
  lwz       r0, 0x6C(r1)
  stw       r4, 0x7C(r29)
  stw       r0, 0x80(r29)
  lwz       r4, 0x70(r1)
  lwz       r0, 0x74(r1)
  stw       r4, 0x84(r29)
  stw       r0, 0x88(r29)
  lwz       r4, 0x78(r1)
  lwz       r0, 0x7C(r1)
  stw       r4, 0x8C(r29)
  stw       r0, 0x90(r29)
  lwz       r4, 0x80(r1)
  lwz       r0, 0x84(r1)
  stw       r4, 0x94(r29)
  stw       r0, 0x98(r29)
  lwz       r4, 0x88(r1)
  lwz       r0, 0x8C(r1)
  stw       r4, 0x9C(r29)
  stw       r0, 0xA0(r29)
  b         .loc_0x1E0

.loc_0x1DC:
  li        r3, 0

.loc_0x1E0:
  lmw       r24, 0xC0(r1)
  lwz       r0, 0xE4(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80187AC4
 * Size:	000020
 */
void zen::ogScrFileSelectMgr::paneOnOffXY(bool)
{
/*
.loc_0x0:
  lbz       r0, 0x28(r3)
  cmplwi    r0, 0
  beq-      .loc_0x18
  li        r0, 0
  stb       r0, 0x278(r3)
  blr       

.loc_0x18:
  stb       r4, 0x278(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80187AE4
 * Size:	0000E0
 */
void zen::ogScrFileSelectMgr::MovePaneXY()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  stw       r30, 0x40(r1)
  stw       r29, 0x3C(r1)
  mr        r29, r3
  lwz       r7, 0x2C8(r29)
  lwz       r3, 0x2C4(r3)
  lbz       r0, 0x278(r29)
  lha       r6, 0x18(r7)
  cmplwi    r0, 0
  lha       r4, 0x18(r3)
  lha       r5, 0x1A(r3)
  mr        r31, r6
  lha       r30, 0x1A(r7)
  beq-      .loc_0x80
  lwz       r0, 0x270(r29)
  cmpw      r4, r0
  ble-      .loc_0x60
  subi      r4, r4, 0x28
  cmpw      r4, r0
  bge-      .loc_0x60
  mr        r4, r0

.loc_0x60:
  lwz       r0, 0x274(r29)
  cmpw      r6, r0
  ble-      .loc_0x98
  subi      r31, r31, 0x14
  cmpw      r31, r0
  bge-      .loc_0x98
  mr        r31, r0
  b         .loc_0x98

.loc_0x80:
  cmpwi     r4, 0x28A
  bge-      .loc_0x8C
  addi      r4, r4, 0x28

.loc_0x8C:
  cmpwi     r6, 0x28A
  bge-      .loc_0x98
  addi      r31, r31, 0x14

.loc_0x98:
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x2C8(r29)
  addi      r4, r31, 0
  addi      r5, r30, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  lwz       r30, 0x40(r1)
  lwz       r29, 0x3C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80187BC4
 * Size:	0000B4
 */
void zen::ogScrFileSelectMgr::OpenYesNoWindow()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  li        r31, 0x1
  stw       r30, 0x38(r1)
  addi      r30, r3, 0
  stb       r31, 0x28D(r3)
  lfs       f0, -0x4FA0(r2)
  stfs      f0, 0x290(r3)
  lwz       r3, 0x26C(r3)
  bl        0xF058
  lwz       r3, 0x2D8(r30)
  li        r0, 0
  lfs       f0, -0x4FA0(r2)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lwz       r6, 0x2D8(r30)
  lha       r3, 0x18(r6)
  lha       r5, 0x1A(r6)
  srawi     r3, r3, 0x1
  addze     r3, r3
  extsh     r4, r3
  srawi     r3, r5, 0x1
  sth       r4, 0xB8(r6)
  addze     r3, r3
  extsh     r3, r3
  sth       r3, 0xBA(r6)
  lwz       r4, 0x2D8(r30)
  lbz       r3, 0xC(r4)
  rlwimi    r3,r31,7,24,24
  stb       r3, 0xC(r4)
  lwz       r4, 0x2D0(r30)
  lbz       r3, 0xC(r4)
  rlwimi    r3,r31,7,24,24
  stb       r3, 0xC(r4)
  lwz       r3, 0x2D0(r30)
  stb       r0, 0xF0(r3)
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80187C78
 * Size:	000014
 */
void zen::ogScrFileSelectMgr::CloseYesNoWindow()
{
/*
.loc_0x0:
  li        r0, 0
  stb       r0, 0x28D(r3)
  lfs       f0, -0x4FA0(r2)
  stfs      f0, 0x290(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void zen::ogScrFileSelectMgr::UpDateYesNoWindow()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void zen::ogScrFileSelectMgr::setOperateMode_Normal()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80187C8C
 * Size:	0000F0
 */
void zen::ogScrFileSelectMgr::setOperateMode(zen::ogScrFileSelectMgr::FileOperateMode)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  stw       r4, 0x24(r3)
  lwz       r0, 0x24(r3)
  cmpwi     r0, 0x1
  beq-      .loc_0xC8
  bge-      .loc_0x34
  cmpwi     r0, 0
  bge-      .loc_0x40
  b         .loc_0xDC

.loc_0x34:
  cmpwi     r0, 0x3
  bge-      .loc_0xDC
  b         .loc_0xD4

.loc_0x40:
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0x13E0
  lha       r0, 0x134(r31)
  add       r3, r31, r0
  lbz       r0, 0x1190(r3)
  cmplwi    r0, 0
  beq-      .loc_0x84
  lbz       r0, 0x28(r31)
  cmplwi    r0, 0
  beq-      .loc_0x78
  li        r0, 0
  stb       r0, 0x278(r31)
  b         .loc_0xA4

.loc_0x78:
  li        r0, 0
  stb       r0, 0x278(r31)
  b         .loc_0xA4

.loc_0x84:
  lbz       r0, 0x28(r31)
  cmplwi    r0, 0
  beq-      .loc_0x9C
  li        r0, 0
  stb       r0, 0x278(r31)
  b         .loc_0xA4

.loc_0x9C:
  li        r0, 0x1
  stb       r0, 0x278(r31)

.loc_0xA4:
  lfs       f1, -0x4FA0(r2)
  addi      r3, r31, 0xA4
  lfs       f2, -0x4F88(r2)
  bl        0x52EDC
  lfs       f1, -0x4FA0(r2)
  addi      r3, r31, 0xD4
  lfs       f2, -0x4F88(r2)
  bl        0x52ECC
  b         .loc_0xDC

.loc_0xC8:
  mr        r3, r31
  bl        0xF444
  b         .loc_0xDC

.loc_0xD4:
  mr        r3, r31
  bl        0xFD74

.loc_0xDC:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80187D7C
 * Size:	0004E0
 */
void zen::ogScrFileSelectMgr::getPane_FileTop1()
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stw       r31, 0x54(r1)
  mr        r31, r3
  stw       r30, 0x50(r1)
  stw       r29, 0x4C(r1)
  lis       r29, 0x705F
  addi      r4, r29, 0x636F
  lwz       r3, 0x2B4(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2C4(r31)
  addi      r4, r29, 0x7368
  li        r5, 0x1
  lwz       r3, 0x2B4(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2C8(r31)
  li        r0, 0
  addi      r4, r29, 0x6D61
  lwz       r3, 0x2C4(r31)
  li        r5, 0x1
  lha       r3, 0x18(r3)
  stw       r3, 0x270(r31)
  lwz       r3, 0x2C8(r31)
  lha       r3, 0x18(r3)
  stw       r3, 0x274(r31)
  stb       r0, 0x278(r31)
  lwz       r3, 0x2B4(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2DC(r31)
  lis       r3, 0x796E
  addi      r4, r3, 0x5F77
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2D8(r31)
  lis       r3, 0x6368
  addi      r4, r3, 0x7569
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2CC(r31)
  lis       r3, 0x6261
  addi      r4, r3, 0x636B
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2D0(r31)
  lis       r3, 0x7365
  addi      r4, r3, 0x5F63
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2D4(r31)
  lis       r3, 0x68
  addi      r4, r3, 0x6169
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2E0(r31)
  lis       r3, 0x69
  addi      r4, r3, 0x6965
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2E4(r31)
  lis       r29, 0x646F
  addi      r4, r29, 0x6E6F
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2E8(r31)
  lis       r3, 0x6873
  addi      r4, r3, 0x686F
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x310(r31)
  lis       r3, 0x73
  addi      r4, r3, 0x686F
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2EC(r31)
  lis       r3, 0x6473
  addi      r4, r3, 0x686F
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2F0(r31)
  addi      r4, r29, 0x6B6F
  li        r5, 0x1
  lwz       r3, 0x2B4(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2F4(r31)
  lis       r3, 0x6431
  addi      r4, r3, 0x636F
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x314(r31)
  lis       r3, 0x636F
  addi      r4, r3, 0x7063
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2F8(r31)
  lis       r30, 0x6463
  addi      r4, r30, 0x7878
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2FC(r31)
  addi      r4, r30, 0x6F70
  li        r5, 0x1
  lwz       r3, 0x2B4(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x300(r31)
  lis       r3, 0x6461
  addi      r4, r3, 0x7361
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x318(r31)
  addi      r4, r29, 0x7361
  li        r5, 0x1
  lwz       r3, 0x2B4(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x304(r31)
  lis       r3, 0x7361
  addi      r4, r3, 0x7663
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x308(r31)
  lis       r3, 0x6464
  addi      r4, r3, 0x7878
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x30C(r31)
  lis       r3, 0x7561
  addi      r4, r3, 0x7361
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x31C(r31)
  lis       r3, 0x7531
  addi      r4, r3, 0x636F
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x320(r31)
  lis       r3, 0x7573
  addi      r4, r3, 0x686F
  lwz       r3, 0x2B4(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x324(r31)
  li        r5, 0xFF
  li        r3, 0x108
  stb       r5, 0x44(r1)
  stb       r5, 0x45(r1)
  stb       r5, 0x46(r1)
  stb       r5, 0x47(r1)
  lwz       r4, 0x31C(r31)
  lwz       r0, 0x44(r1)
  stw       r0, 0xF4(r4)
  lwz       r4, 0x31C(r31)
  stb       r5, 0xF7(r4)
  stb       r5, 0xFB(r4)
  lwz       r4, 0x320(r31)
  stb       r5, 0xF7(r4)
  stb       r5, 0xFB(r4)
  lwz       r4, 0x324(r31)
  stb       r5, 0xF7(r4)
  stb       r5, 0xFB(r4)
  bl        -0x14116C
  cmplwi    r3, 0
  beq-      .loc_0x410
  lwz       r4, 0x310(r31)
  stw       r4, 0x0(r3)
  lwz       r0, 0x10C(r4)
  stw       r0, 0x4(r3)

.loc_0x410:
  stw       r3, 0x260(r31)
  li        r3, 0x108
  bl        -0x141190
  cmplwi    r3, 0
  beq-      .loc_0x434
  lwz       r4, 0x314(r31)
  stw       r4, 0x0(r3)
  lwz       r0, 0x10C(r4)
  stw       r0, 0x4(r3)

.loc_0x434:
  stw       r3, 0x264(r31)
  li        r3, 0x108
  bl        -0x1411B4
  cmplwi    r3, 0
  beq-      .loc_0x458
  lwz       r4, 0x318(r31)
  stw       r4, 0x0(r3)
  lwz       r0, 0x10C(r4)
  stw       r0, 0x4(r3)

.loc_0x458:
  stw       r3, 0x268(r31)
  li        r3, 0xC4
  bl        -0x1411D8
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x48C
  lwz       r4, 0x2B4(r31)
  li        r8, 0
  lwz       r5, 0x2E0(r31)
  li        r9, 0x1
  lwz       r6, 0x2E4(r31)
  lwz       r7, 0x2D4(r31)
  bl        0xE660

.loc_0x48C:
  stw       r29, 0x26C(r31)
  li        r4, 0
  lwz       r3, 0x2D0(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x2D8(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x2CC(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r0, 0x5C(r1)
  lwz       r31, 0x54(r1)
  lwz       r30, 0x50(r1)
  lwz       r29, 0x4C(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018825C
 * Size:	00032C
 */
void zen::ogScrFileSelectMgr::getPane_FileTop2()
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stmw      r27, 0x2C(r1)
  mr        r27, r3
  lis       r28, 0x6461
  addi      r4, r28, 0x5F31
  lwz       r3, 0x2B8(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x328(r27)
  addi      r4, r28, 0x5F32
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x32C(r27)
  addi      r4, r28, 0x5F33
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x330(r27)
  lis       r29, 0x726F
  addi      r4, r29, 0x5F6C
  lwz       r3, 0x2B8(r27)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x338(r27)
  addi      r4, r29, 0x5F72
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x33C(r27)
  lis       r29, 0x7274
  addi      r4, r29, 0x5F6C
  lwz       r3, 0x2B8(r27)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x340(r27)
  addi      r4, r29, 0x5F72
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x344(r27)
  lis       r29, 0x7263
  addi      r4, r29, 0x5F6C
  lwz       r3, 0x2B8(r27)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x348(r27)
  addi      r4, r29, 0x5F63
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x34C(r27)
  addi      r4, r29, 0x5F72
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x350(r27)
  lis       r30, 0x6263
  addi      r4, r30, 0x5F6C
  lwz       r3, 0x2B8(r27)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x354(r27)
  addi      r4, r30, 0x5F63
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x358(r27)
  addi      r4, r30, 0x5F72
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x35C(r27)
  lis       r31, 0x7963
  addi      r4, r31, 0x5F6C
  lwz       r3, 0x2B8(r27)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x360(r27)
  addi      r4, r31, 0x5F63
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x364(r27)
  addi      r4, r31, 0x5F72
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x368(r27)
  addi      r4, r29, 0x6F6E
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x36C(r27)
  addi      r4, r30, 0x6F6E
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x370(r27)
  addi      r4, r31, 0x6F6E
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x374(r27)
  addi      r4, r28, 0x6C6C
  li        r5, 0x1
  lwz       r3, 0x2B8(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x334(r27)
  lis       r3, 0x6E61
  addi      r4, r3, 0x7669
  lwz       r3, 0x2B8(r27)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x378(r27)
  lis       r3, 0x6E65
  addi      r4, r3, 0x7764
  lwz       r3, 0x2B8(r27)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x37C(r27)
  addi      r3, r27, 0
  li        r4, 0
  lwz       r5, 0x374(r27)
  lha       r0, 0x18(r5)
  stw       r0, 0x294(r27)
  lwz       r5, 0x374(r27)
  lha       r0, 0x1A(r5)
  stw       r0, 0x298(r27)
  bl        .loc_0x32C
  lmw       r27, 0x2C(r1)
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr       

.loc_0x32C:
*/
}

/*
 * --INFO--
 * Address:	80188588
 * Size:	000164
 */
void zen::ogScrFileSelectMgr::setFileData(int)
{
/*
.loc_0x0:
  mflr      r0
  li        r6, 0xA
  stw       r0, 0x4(r1)
  mulli     r0, r4, 0x28
  stwu      r1, -0x30(r1)
  stmw      r25, 0x14(r1)
  addi      r25, r3, 0
  add       r4, r25, r0
  addi      r26, r4, 0x3C
  li        r0, 0x1E
  lis       r31, 0x726F
  addi      r5, r26, 0
  addi      r29, r4, 0x40
  addi      r28, r4, 0x48
  addi      r27, r4, 0x44
  lwz       r30, 0x2B8(r3)
  addi      r4, r31, 0x5F6C
  stw       r0, 0x154(r3)
  addi      r3, r30, 0
  bl        -0x9CF0
  addi      r3, r30, 0
  addi      r5, r26, 0
  addi      r4, r31, 0x5F72
  li        r6, 0x1
  bl        -0x9D04
  lis       r31, 0x7274
  addi      r3, r30, 0
  addi      r4, r31, 0x5F6C
  addi      r5, r25, 0x154
  li        r6, 0xA
  bl        -0x9D1C
  addi      r3, r30, 0
  addi      r4, r31, 0x5F72
  addi      r5, r25, 0x154
  li        r6, 0x1
  bl        -0x9D30
  lis       r31, 0x7263
  addi      r3, r30, 0
  addi      r5, r29, 0
  addi      r4, r31, 0x5F6C
  li        r6, 0x64
  bl        -0x9D48
  addi      r3, r30, 0
  addi      r5, r29, 0
  addi      r4, r31, 0x5F63
  li        r6, 0xA
  bl        -0x9D5C
  addi      r3, r30, 0
  addi      r5, r29, 0
  addi      r4, r31, 0x5F72
  li        r6, 0x1
  bl        -0x9D70
  lis       r31, 0x6263
  addi      r3, r30, 0
  addi      r5, r28, 0
  addi      r4, r31, 0x5F6C
  li        r6, 0x64
  bl        -0x9D88
  addi      r3, r30, 0
  addi      r5, r28, 0
  addi      r4, r31, 0x5F63
  li        r6, 0xA
  bl        -0x9D9C
  addi      r3, r30, 0
  addi      r5, r28, 0
  addi      r4, r31, 0x5F72
  li        r6, 0x1
  bl        -0x9DB0
  lis       r31, 0x7963
  addi      r3, r30, 0
  addi      r5, r27, 0
  addi      r4, r31, 0x5F6C
  li        r6, 0x64
  bl        -0x9DC8
  addi      r3, r30, 0
  addi      r5, r27, 0
  addi      r4, r31, 0x5F63
  li        r6, 0xA
  bl        -0x9DDC
  addi      r3, r30, 0
  addi      r5, r27, 0
  addi      r4, r31, 0x5F72
  li        r6, 0x1
  bl        -0x9DF0
  lmw       r25, 0x14(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void zen::ogScrFileSelectMgr::set_SM_C()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801886EC
 * Size:	000520
 */
void zen::ogScrFileSelectMgr::getPane_FileIcon()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x6E6F
  stw       r0, 0x4(r1)
  addi      r4, r4, 0x5F63
  li        r5, 0x1
  stwu      r1, -0x1B0(r1)
  stfd      f31, 0x1A8(r1)
  stmw      r20, 0x178(r1)
  mr        r20, r3
  lwz       r3, 0x29C(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x440(r20)
  lis       r25, 0x6E65
  addi      r4, r25, 0x5F63
  lwz       r3, 0x29C(r20)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x444(r20)
  addi      r24, r20, 0
  addi      r23, r20, 0
  lfs       f31, -0x4F84(r2)
  li        r22, 0
  lis       r26, 0x726F
  lis       r27, 0x6670
  lis       r28, 0x6365
  lis       r29, 0x6566
  lis       r30, 0x6463
  lis       r31, 0x736D

.loc_0x88:
  lwz       r21, 0x29C(r24)
  addi      r4, r26, 0x6F74
  li        r5, 0x1
  addi      r3, r21, 0
  lwz       r12, 0x0(r21)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x38C(r24)
  addi      r3, r21, 0
  addi      r4, r25, 0x7769
  lwz       r12, 0x0(r21)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x398(r24)
  addi      r3, r21, 0
  addi      r4, r25, 0x6D69
  lwz       r12, 0x0(r21)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x3A4(r24)
  li        r7, 0
  addi      r3, r21, 0
  lwz       r6, 0x398(r24)
  li        r4, 0x6670
  li        r5, 0x1
  lbz       r0, 0xC(r6)
  rlwimi    r0,r7,7,24,24
  stb       r0, 0xC(r6)
  lwz       r6, 0x3A4(r24)
  lbz       r0, 0xC(r6)
  rlwimi    r0,r7,7,24,24
  stb       r0, 0xC(r6)
  lwz       r12, 0x0(r21)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x3B0(r24)
  addi      r3, r21, 0
  addi      r4, r27, 0x5F6D
  lwz       r12, 0x0(r21)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x3BC(r24)
  li        r4, 0x1
  lwz       r3, 0x3B0(r24)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x3BC(r24)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r5, 0x3B0(r24)
  lha       r3, 0x18(r5)
  lha       r0, 0x1C(r5)
  lha       r4, 0x1A(r5)
  sub       r0, r0, r3
  lha       r3, 0x1E(r5)
  srawi     r0, r0, 0x1
  addze     r0, r0
  sub       r4, r3, r4
  extsh     r3, r0
  srawi     r0, r4, 0x1
  sth       r3, 0xB8(r5)
  addze     r0, r0
  extsh     r0, r0
  sth       r0, 0xBA(r5)
  lwz       r5, 0x3BC(r24)
  lha       r3, 0x18(r5)
  lha       r0, 0x1C(r5)
  lha       r4, 0x1A(r5)
  sub       r0, r0, r3
  lha       r3, 0x1E(r5)
  srawi     r0, r0, 0x1
  addze     r0, r0
  sub       r4, r3, r4
  extsh     r3, r0
  srawi     r0, r4, 0x1
  sth       r3, 0xB8(r5)
  addze     r0, r0
  extsh     r0, r0
  sth       r0, 0xBA(r5)
  lwz       r5, 0x398(r24)
  lha       r3, 0x18(r5)
  lha       r0, 0x1C(r5)
  lha       r4, 0x1A(r5)
  sub       r0, r0, r3
  lha       r3, 0x1E(r5)
  srawi     r0, r0, 0x1
  addze     r0, r0
  sub       r4, r3, r4
  extsh     r3, r0
  srawi     r0, r4, 0x1
  sth       r3, 0xB8(r5)
  addze     r0, r0
  extsh     r0, r0
  sth       r0, 0xBA(r5)
  lwz       r5, 0x3A4(r24)
  lha       r3, 0x18(r5)
  lha       r0, 0x1C(r5)
  lha       r4, 0x1A(r5)
  sub       r0, r0, r3
  lha       r3, 0x1E(r5)
  srawi     r0, r0, 0x1
  addze     r0, r0
  sub       r4, r3, r4
  extsh     r3, r0
  srawi     r0, r4, 0x1
  sth       r3, 0xB8(r5)
  addze     r0, r0
  extsh     r0, r0
  sth       r0, 0xBA(r5)
  lwz       r3, 0x3B0(r24)
  lha       r0, 0x18(r3)
  stw       r0, 0x158(r24)
  lwz       r3, 0x3B0(r24)
  lha       r0, 0x1A(r3)
  stw       r0, 0x164(r24)
  lwz       r3, 0x3BC(r24)
  lha       r0, 0x18(r3)
  stw       r0, 0x170(r24)
  lwz       r3, 0x3BC(r24)
  lha       r0, 0x1A(r3)
  stw       r0, 0x17C(r24)
  lwz       r4, 0x3B0(r24)
  lwz       r3, 0xC0(r4)
  lwz       r0, 0xC4(r4)
  stw       r3, 0x188(r23)
  stw       r0, 0x18C(r23)
  lwz       r0, 0xC8(r4)
  stw       r0, 0x190(r23)
  lwz       r4, 0x3BC(r24)
  lwz       r3, 0xC0(r4)
  lwz       r0, 0xC4(r4)
  stw       r3, 0x1AC(r23)
  stw       r0, 0x1B0(r23)
  lwz       r0, 0xC8(r4)
  stw       r0, 0x1B4(r23)
  lwz       r5, 0x398(r24)
  addi      r3, r21, 0
  addi      r4, r28, 0x5F70
  lha       r0, 0x18(r5)
  li        r5, 0x1
  stw       r0, 0x200(r24)
  lwz       r6, 0x398(r24)
  lha       r0, 0x1A(r6)
  stw       r0, 0x20C(r24)
  lwz       r6, 0x3A4(r24)
  lha       r0, 0x18(r6)
  stw       r0, 0x230(r24)
  lwz       r6, 0x3A4(r24)
  lha       r0, 0x1A(r6)
  stw       r0, 0x23C(r24)
  lwz       r12, 0x0(r21)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x3C8(r24)
  addi      r3, r21, 0
  addi      r4, r29, 0x5F63
  lwz       r12, 0x0(r21)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x3D4(r24)
  addi      r3, r21, 0
  addi      r4, r29, 0x6D63
  lwz       r12, 0x0(r21)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x3E0(r24)
  addi      r3, r21, 0
  addi      r4, r30, 0x5F63
  lwz       r7, 0x3C8(r24)
  li        r5, 0x1
  lwz       r6, 0x29C(r24)
  lha       r0, 0x18(r7)
  lha       r7, 0x1A(r7)
  sth       r0, 0xB8(r6)
  sth       r7, 0xBA(r6)
  lwz       r6, 0x29C(r24)
  stfs      f31, 0xC0(r6)
  stfs      f31, 0xC4(r6)
  stfs      f31, 0xC8(r6)
  lwz       r6, 0x2A8(r24)
  sth       r0, 0xB8(r6)
  sth       r7, 0xBA(r6)
  lwz       r6, 0x2A8(r24)
  stfs      f31, 0xC0(r6)
  stfs      f31, 0xC4(r6)
  stfs      f31, 0xC8(r6)
  lwz       r12, 0x0(r21)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x3EC(r24)
  addi      r3, r21, 0
  addi      r4, r30, 0x6D63
  lwz       r12, 0x0(r21)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x3F8(r24)
  addi      r3, r21, 0
  addi      r4, r30, 0x5F6C
  lwz       r12, 0x0(r21)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x404(r24)
  addi      r3, r21, 0
  addi      r4, r30, 0x5F72
  lwz       r12, 0x0(r21)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x410(r24)
  addi      r3, r21, 0
  addi      r4, r30, 0x6D6C
  lwz       r12, 0x0(r21)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x41C(r24)
  addi      r3, r21, 0
  addi      r4, r30, 0x6D72
  lwz       r12, 0x0(r21)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x428(r24)
  addi      r3, r21, 0
  addi      r4, r31, 0x5F63
  lwz       r12, 0x0(r21)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x434(r24)
  addi      r3, r20, 0
  addi      r4, r22, 0
  lwz       r5, 0x434(r24)
  lbz       r6, 0x109(r5)
  lbz       r7, 0x10A(r5)
  lbz       r8, 0x10B(r5)
  lbz       r0, 0x108(r5)
  stb       r0, 0x168(r1)
  stb       r6, 0x169(r1)
  stb       r7, 0x16A(r1)
  stb       r8, 0x16B(r1)
  lwz       r6, 0x434(r24)
  lwz       r5, 0x3F8(r24)
  lbz       r6, 0xF0(r6)
  lwz       r0, 0x168(r1)
  stw       r0, 0x108(r5)
  lwz       r5, 0x3F8(r24)
  stb       r6, 0xF0(r5)
  lwz       r5, 0x41C(r24)
  lwz       r0, 0x168(r1)
  stw       r0, 0x108(r5)
  lwz       r5, 0x41C(r24)
  stb       r6, 0xF0(r5)
  lwz       r5, 0x428(r24)
  lwz       r0, 0x168(r1)
  stw       r0, 0x108(r5)
  lwz       r5, 0x428(r24)
  stb       r6, 0xF0(r5)
  bl        .loc_0x520
  addi      r22, r22, 0x1
  cmpwi     r22, 0x3
  addi      r24, r24, 0x4
  addi      r23, r23, 0xC
  blt+      .loc_0x88
  lmw       r20, 0x178(r1)
  lwz       r0, 0x1B4(r1)
  lfd       f31, 0x1A8(r1)
  addi      r1, r1, 0x1B0
  mtlr      r0
  blr       

.loc_0x520:
*/
}

/*
 * --INFO--
 * Address:	80188C0C
 * Size:	0001B8
 */
void zen::ogScrFileSelectMgr::OnOffKetaNissuu(int)
{
/*
.loc_0x0:
  mflr      r0
  mulli     r6, r4, 0x28
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  add       r5, r3, r6
  rlwinm    r4,r4,2,0,29
  stw       r31, 0x54(r1)
  add       r31, r3, r4
  stw       r30, 0x50(r1)
  stw       r29, 0x4C(r1)
  stw       r28, 0x48(r1)
  addi      r28, r6, 0x38
  add       r28, r3, r28
  lwz       r0, 0x38(r5)
  lwz       r29, 0x29C(r31)
  cmpwi     r0, 0xA
  bge-      .loc_0xDC
  lis       r30, 0x6463
  addi      r3, r29, 0
  addi      r5, r28, 0
  addi      r4, r30, 0x5F63
  li        r6, 0x1
  bl        -0xA380
  addi      r3, r29, 0
  addi      r5, r28, 0
  addi      r4, r30, 0x6D63
  li        r6, 0x1
  bl        -0xA394
  lwz       r3, 0x3EC(r31)
  li        r5, 0x1
  li        r4, 0
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x3F8(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x404(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x410(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x41C(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x428(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x198

.loc_0xDC:
  lis       r30, 0x6463
  addi      r3, r29, 0
  addi      r5, r28, 0
  addi      r4, r30, 0x5F6C
  li        r6, 0xA
  bl        -0xA418
  addi      r3, r29, 0
  addi      r5, r28, 0
  addi      r4, r30, 0x5F72
  li        r6, 0x1
  bl        -0xA42C
  addi      r3, r29, 0
  addi      r5, r28, 0
  addi      r4, r30, 0x6D6C
  li        r6, 0xA
  bl        -0xA440
  addi      r3, r29, 0
  addi      r5, r28, 0
  addi      r4, r30, 0x6D72
  li        r6, 0x1
  bl        -0xA454
  lwz       r3, 0x404(r31)
  li        r5, 0x1
  li        r4, 0
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x410(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x41C(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x428(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x3EC(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x3F8(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)

.loc_0x198:
  lwz       r0, 0x5C(r1)
  lwz       r31, 0x54(r1)
  lwz       r30, 0x50(r1)
  lwz       r29, 0x4C(r1)
  lwz       r28, 0x48(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80188DC4
 * Size:	0002F0
 */
void zen::ogScrFileSelectMgr::getPane_CpyCurScreen()
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0xC0(r1)
  stmw      r24, 0xA0(r1)
  mr        r26, r3
  lwz       r27, 0x2BC(r3)
  lis       r3, 0x726F
  addi      r4, r3, 0x6F74
  lwz       r12, 0x0(r27)
  addi      r3, r27, 0
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x448(r26)
  addi      r3, r27, 0
  lis       r24, 0x6930
  lwz       r12, 0x0(r27)
  addi      r4, r24, 0x3075
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r25, r3, 0
  addi      r3, r27, 0
  lwz       r12, 0x0(r27)
  addi      r4, r24, 0x3064
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r28, r3, 0
  addi      r3, r27, 0
  lwz       r12, 0x0(r27)
  addi      r4, r24, 0x3175
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r29, r3, 0
  addi      r3, r27, 0
  lwz       r12, 0x0(r27)
  addi      r4, r24, 0x3164
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r30, r3, 0
  addi      r3, r27, 0
  lwz       r12, 0x0(r27)
  addi      r4, r24, 0x3275
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r31, r3, 0
  addi      r3, r27, 0
  lwz       r12, 0x0(r27)
  addi      r4, r24, 0x3264
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0xC(r25)
  li        r5, 0
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r25)
  lis       r0, 0x4330
  lbz       r4, 0xC(r28)
  rlwimi    r4,r5,7,24,24
  stb       r4, 0xC(r28)
  lbz       r4, 0xC(r29)
  rlwimi    r4,r5,7,24,24
  stb       r4, 0xC(r29)
  lbz       r4, 0xC(r30)
  rlwimi    r4,r5,7,24,24
  stb       r4, 0xC(r30)
  lbz       r4, 0xC(r31)
  rlwimi    r4,r5,7,24,24
  stb       r4, 0xC(r31)
  lbz       r4, 0xC(r3)
  rlwimi    r4,r5,7,24,24
  stb       r4, 0xC(r3)
  lha       r4, 0x18(r25)
  lfd       f1, -0x4F80(r2)
  xoris     r4, r4, 0x8000
  stw       r4, 0x9C(r1)
  stw       r0, 0x98(r1)
  lfd       f0, 0x98(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x104(r26)
  lha       r4, 0x1A(r25)
  xoris     r4, r4, 0x8000
  stw       r4, 0x94(r1)
  stw       r0, 0x90(r1)
  lfd       f0, 0x90(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x11C(r26)
  lha       r4, 0x18(r29)
  xoris     r4, r4, 0x8000
  stw       r4, 0x8C(r1)
  stw       r0, 0x88(r1)
  lfd       f0, 0x88(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x108(r26)
  lha       r4, 0x1A(r29)
  xoris     r4, r4, 0x8000
  stw       r4, 0x84(r1)
  stw       r0, 0x80(r1)
  lfd       f0, 0x80(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x120(r26)
  lha       r4, 0x18(r31)
  xoris     r4, r4, 0x8000
  stw       r4, 0x7C(r1)
  stw       r0, 0x78(r1)
  lfd       f0, 0x78(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x10C(r26)
  lha       r4, 0x1A(r31)
  xoris     r4, r4, 0x8000
  stw       r4, 0x74(r1)
  stw       r0, 0x70(r1)
  lfd       f0, 0x70(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x124(r26)
  lha       r4, 0x18(r28)
  xoris     r4, r4, 0x8000
  stw       r4, 0x6C(r1)
  stw       r0, 0x68(r1)
  lfd       f0, 0x68(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x110(r26)
  lha       r4, 0x1A(r28)
  xoris     r4, r4, 0x8000
  stw       r4, 0x64(r1)
  stw       r0, 0x60(r1)
  lfd       f0, 0x60(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x128(r26)
  lha       r4, 0x18(r30)
  xoris     r4, r4, 0x8000
  stw       r4, 0x5C(r1)
  stw       r0, 0x58(r1)
  lfd       f0, 0x58(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x114(r26)
  lha       r5, 0x1A(r30)
  lis       r28, 0x7A30
  addi      r4, r27, 0
  xoris     r5, r5, 0x8000
  stw       r5, 0x54(r1)
  addi      r6, r28, 0x306C
  stw       r0, 0x50(r1)
  lfd       f0, 0x50(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x12C(r26)
  lha       r5, 0x18(r3)
  xoris     r5, r5, 0x8000
  stw       r5, 0x4C(r1)
  stw       r0, 0x48(r1)
  lfd       f0, 0x48(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x118(r26)
  lha       r5, 0x1A(r3)
  addi      r3, r26, 0xA4
  xoris     r5, r5, 0x8000
  stw       r5, 0x44(r1)
  stw       r0, 0x40(r1)
  lfd       f0, 0x40(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x130(r26)
  lwz       r5, 0x448(r26)
  lfs       f1, 0x104(r26)
  lfs       f2, 0x11C(r26)
  bl        0x51BBC
  lwz       r5, 0x448(r26)
  mr        r4, r27
  lfs       f1, 0x110(r26)
  addi      r3, r26, 0xD4
  lfs       f2, 0x128(r26)
  addi      r6, r28, 0x3072
  bl        0x51BA0
  lmw       r24, 0xA0(r1)
  lwz       r0, 0xC4(r1)
  addi      r1, r1, 0xC0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801890B4
 * Size:	000340
 */
void zen::ogScrFileSelectMgr::SetTitleMsg(zen::ogScrFileSelectMgr::titleMessageFlag)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0xD0(r1)
  stw       r31, 0xCC(r1)
  addi      r31, r4, 0
  stw       r30, 0xC8(r1)
  mr        r30, r3
  stw       r29, 0xC4(r1)
  lwz       r5, 0x2E8(r3)
  li        r3, 0x6
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r5, 0x310(r30)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r5, 0x2EC(r30)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r5, 0x2F0(r30)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r5, 0x2F4(r30)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r5, 0x314(r30)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r5, 0x2F8(r30)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r5, 0x2FC(r30)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r5, 0x300(r30)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r5, 0x318(r30)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r5, 0x304(r30)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r5, 0x308(r30)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lwz       r5, 0x30C(r30)
  lbz       r4, 0xC(r5)
  rlwimi    r4,r0,7,24,24
  stb       r4, 0xC(r5)
  lha       r4, 0x134(r30)
  addi      r4, r4, 0x1
  bl        -0x9068
  lwz       r4, 0x119C(r30)
  li        r3, 0x7
  addi      r4, r4, 0x1
  bl        -0x9078
  lwz       r29, 0x260(r30)
  lwz       r4, 0x4(r29)
  addi      r3, r29, 0x8
  bl        0x90184
  addi      r3, r29, 0x8
  bl        -0x9064
  lwz       r3, 0x0(r29)
  addi      r0, r29, 0x8
  stw       r0, 0x10C(r3)
  lwz       r29, 0x264(r30)
  lwz       r4, 0x4(r29)
  addi      r3, r29, 0x8
  bl        0x90160
  addi      r3, r29, 0x8
  bl        -0x9088
  lwz       r3, 0x0(r29)
  addi      r0, r29, 0x8
  stw       r0, 0x10C(r3)
  lwz       r29, 0x268(r30)
  lwz       r4, 0x4(r29)
  addi      r3, r29, 0x8
  bl        0x9013C
  addi      r3, r29, 0x8
  bl        -0x90AC
  lwz       r3, 0x0(r29)
  addi      r0, r29, 0x8
  stw       r0, 0x10C(r3)
  lwz       r4, 0x318(r30)
  lwz       r3, 0x31C(r30)
  lwz       r0, 0x10C(r4)
  stw       r0, 0x10C(r3)
  lwz       r4, 0x314(r30)
  lwz       r3, 0x320(r30)
  lwz       r0, 0x10C(r4)
  stw       r0, 0x10C(r3)
  lwz       r4, 0x310(r30)
  lwz       r3, 0x324(r30)
  lwz       r0, 0x10C(r4)
  stw       r0, 0x10C(r3)
  lwz       r0, 0x27C(r30)
  cmpw      r31, r0
  beq-      .loc_0x1D0
  stw       r31, 0x27C(r30)
  li        r0, 0x1
  lfs       f0, -0x4FA0(r2)
  stfs      f0, 0x280(r30)
  stb       r0, 0x284(r30)

.loc_0x1D0:
  cmplwi    r31, 0xD
  bgt-      .loc_0x324
  lis       r3, 0x802D
  addi      r3, r3, 0x51B0
  rlwinm    r0,r31,2,0,29
  lwzx      r0, r3, r0
  mtctr     r0
  bctr      
  lwz       r3, 0x2E8(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x324
  lwz       r3, 0x310(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x324
  lwz       r3, 0x2EC(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x324
  lwz       r3, 0x2F0(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x324
  lwz       r3, 0x2F4(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x324
  lwz       r3, 0x314(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x324
  lwz       r3, 0x2F8(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x324
  lwz       r3, 0x2FC(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x324
  lwz       r3, 0x300(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x324
  lwz       r3, 0x318(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x324
  lwz       r3, 0x304(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x324
  lwz       r3, 0x308(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x324
  lwz       r3, 0x30C(r30)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)

.loc_0x324:
  lwz       r0, 0xD4(r1)
  lwz       r31, 0xCC(r1)
  lwz       r30, 0xC8(r1)
  lwz       r29, 0xC4(r1)
  addi      r1, r1, 0xD0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
void zen::ogScrFileSelectMgr::ScaleAnimeTitle()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void zen::ogScrFileSelectMgr::ScaleAnimeData()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801893F4
 * Size:	0002C8
 */
void zen::ogScrFileSelectMgr::setDataNumber(int)
{
/*
.loc_0x0:
  mflr      r0
  li        r6, 0x1
  stw       r0, 0x4(r1)
  li        r5, 0
  cmpwi     r4, 0x1
  stwu      r1, -0x98(r1)
  stw       r31, 0x94(r1)
  addi      r31, r3, 0
  lfs       f0, -0x4FA0(r2)
  stfs      f0, 0x288(r3)
  stb       r6, 0x28C(r3)
  lwz       r3, 0x328(r3)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x32C(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x330(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  beq-      .loc_0x90
  bge-      .loc_0x70
  cmpwi     r4, 0
  bge-      .loc_0x7C
  b         .loc_0xB4

.loc_0x70:
  cmpwi     r4, 0x3
  bge-      .loc_0xB4
  b         .loc_0xA4

.loc_0x7C:
  lwz       r3, 0x328(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0xB4

.loc_0x90:
  lwz       r3, 0x32C(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0xB4

.loc_0xA4:
  lwz       r3, 0x330(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r3)

.loc_0xB4:
  mr        r3, r31
  bl        0xF3C
  mr        r3, r31
  bl        0xE7C
  lha       r0, 0x134(r31)
  lis       r4, 0x4330
  lfs       f0, -0x4FA0(r2)
  rlwinm    r0,r0,2,0,29
  add       r3, r31, r0
  lwz       r6, 0x3B0(r3)
  stfs      f0, 0x6C(r1)
  stfs      f0, 0x68(r1)
  stfs      f0, 0x64(r1)
  lfs       f1, 0xCD8(r13)
  lfs       f0, 0xCDC(r13)
  stfs      f1, 0x64(r1)
  stfs      f0, 0x68(r1)
  lfs       f0, 0xCE0(r13)
  stfs      f0, 0x6C(r1)
  lha       r5, 0x18(r6)
  lha       r0, 0x1C(r6)
  xoris     r3, r5, 0x8000
  lfd       f4, -0x4F80(r2)
  sub       r0, r0, r5
  stw       r3, 0x8C(r1)
  xoris     r0, r0, 0x8000
  lfs       f3, -0x4F74(r2)
  stw       r0, 0x84(r1)
  lfs       f2, -0x4F70(r2)
  stw       r4, 0x80(r1)
  lfd       f0, 0x80(r1)
  stw       r4, 0x88(r1)
  fsubs     f0, f0, f4
  lfd       f1, 0x88(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  stfs      f0, 0x64(r1)
  lha       r5, 0x1A(r6)
  lha       r0, 0x1E(r6)
  xoris     r3, r5, 0x8000
  sub       r0, r0, r5
  stw       r3, 0x7C(r1)
  xoris     r0, r0, 0x8000
  stw       r0, 0x74(r1)
  stw       r4, 0x70(r1)
  lfd       f0, 0x70(r1)
  stw       r4, 0x78(r1)
  fsubs     f0, f0, f4
  lfd       f1, 0x78(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  fsubs     f0, f2, f0
  stfs      f0, 0x68(r1)
  lwz       r3, 0x14(r31)
  cmplwi    r3, 0
  beq-      .loc_0x1A0
  bl        0x1766C

.loc_0x1A0:
  lwz       r3, 0x0(r31)
  addi      r5, r1, 0x64
  li        r4, 0x24
  li        r6, 0
  li        r7, 0
  bl        0x60594
  stw       r3, 0x14(r31)
  lis       r4, 0x4330
  lha       r0, 0x134(r31)
  lfs       f0, -0x4FA0(r2)
  rlwinm    r0,r0,2,0,29
  add       r3, r31, r0
  lwz       r6, 0x3BC(r3)
  stfs      f0, 0x60(r1)
  stfs      f0, 0x5C(r1)
  stfs      f0, 0x58(r1)
  lfs       f1, 0xCE4(r13)
  lfs       f0, 0xCE8(r13)
  stfs      f1, 0x58(r1)
  stfs      f0, 0x5C(r1)
  lfs       f0, 0xCEC(r13)
  stfs      f0, 0x60(r1)
  lha       r5, 0x18(r6)
  lha       r0, 0x1C(r6)
  xoris     r3, r5, 0x8000
  lfd       f4, -0x4F80(r2)
  sub       r0, r0, r5
  stw       r3, 0x74(r1)
  xoris     r0, r0, 0x8000
  lfs       f3, -0x4F74(r2)
  stw       r0, 0x7C(r1)
  lfs       f2, -0x4F70(r2)
  stw       r4, 0x78(r1)
  lfd       f0, 0x78(r1)
  stw       r4, 0x70(r1)
  fsubs     f0, f0, f4
  lfd       f1, 0x70(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  stfs      f0, 0x58(r1)
  lha       r5, 0x1A(r6)
  lha       r0, 0x1E(r6)
  xoris     r3, r5, 0x8000
  sub       r0, r0, r5
  stw       r3, 0x84(r1)
  xoris     r0, r0, 0x8000
  stw       r0, 0x8C(r1)
  stw       r4, 0x88(r1)
  lfd       f0, 0x88(r1)
  stw       r4, 0x80(r1)
  fsubs     f0, f0, f4
  lfd       f1, 0x80(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  fsubs     f0, f2, f0
  stfs      f0, 0x5C(r1)
  lwz       r3, 0x18(r31)
  cmplwi    r3, 0
  beq-      .loc_0x298
  bl        0x17574

.loc_0x298:
  lwz       r3, 0x0(r31)
  addi      r5, r1, 0x58
  li        r4, 0x23
  li        r6, 0
  li        r7, 0
  bl        0x6049C
  stw       r3, 0x18(r31)
  lwz       r0, 0x9C(r1)
  lwz       r31, 0x94(r1)
  addi      r1, r1, 0x98
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void zen::ogScrFileSelectMgr::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801896BC
 * Size:	0008F8
 */
void zen::ogScrFileSelectMgr::ogScrFileSelectMgr()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x8019
  stw       r0, 0x4(r1)
  subi      r4, r4, 0x604C
  li        r5, 0
  stwu      r1, -0x88(r1)
  li        r6, 0x28
  li        r7, 0x3
  stmw      r27, 0x74(r1)
  addi      r31, r3, 0
  lis       r3, 0x802D
  addi      r30, r3, 0x5188
  addi      r3, r31, 0x2C
  bl        0x8B380
  li        r28, 0
  stw       r28, 0xA4(r31)
  lis       r3, 0x8003
  addi      r29, r3, 0x5B24
  stw       r28, 0xA8(r31)
  addi      r4, r29, 0
  addi      r3, r31, 0x188
  lfs       f5, -0x4F98(r2)
  li        r5, 0
  li        r6, 0xC
  stfs      f5, 0xB0(r31)
  fmr       f3, f5
  fmr       f2, f5
  li        r7, 0x3
  stfs      f5, 0xAC(r31)
  fmr       f1, f5
  lfs       f4, -0x4FA0(r2)
  fmr       f0, f5
  stfs      f4, 0xC0(r31)
  stfs      f4, 0xBC(r31)
  stfs      f4, 0xB8(r31)
  stfs      f4, 0xB4(r31)
  stfs      f5, 0xC8(r31)
  stfs      f5, 0xC4(r31)
  stfs      f3, 0xD0(r31)
  stfs      f3, 0xCC(r31)
  stw       r28, 0xD4(r31)
  stw       r28, 0xD8(r31)
  stfs      f2, 0xE0(r31)
  stfs      f2, 0xDC(r31)
  stfs      f4, 0xF0(r31)
  stfs      f4, 0xEC(r31)
  stfs      f4, 0xE8(r31)
  stfs      f4, 0xE4(r31)
  stfs      f1, 0xF8(r31)
  stfs      f1, 0xF4(r31)
  stfs      f0, 0x100(r31)
  stfs      f0, 0xFC(r31)
  bl        0x8B2E4
  addi      r4, r29, 0
  addi      r3, r31, 0x1AC
  li        r5, 0
  li        r6, 0xC
  li        r7, 0x3
  bl        0x8B2CC
  stw       r28, 0x4BC(r31)
  li        r0, -0x1
  li        r3, 0x4C4
  stw       r28, 0x4C0(r31)
  lfs       f6, -0x4F98(r2)
  stfs      f6, 0x4C8(r31)
  fmr       f4, f6
  fmr       f3, f6
  stfs      f6, 0x4C4(r31)
  fmr       f2, f6
  fmr       f1, f6
  lfs       f5, -0x4FA0(r2)
  stfs      f5, 0x4D8(r31)
  fmr       f0, f5
  stfs      f5, 0x4D4(r31)
  stfs      f5, 0x4D0(r31)
  stfs      f5, 0x4CC(r31)
  stfs      f6, 0x4E0(r31)
  stfs      f6, 0x4DC(r31)
  stfs      f4, 0x4E8(r31)
  stfs      f4, 0x4E4(r31)
  stw       r28, 0x4FC(r31)
  stw       r28, 0x500(r31)
  stfs      f3, 0x508(r31)
  stfs      f3, 0x504(r31)
  stfs      f5, 0x518(r31)
  stfs      f5, 0x514(r31)
  stfs      f5, 0x510(r31)
  stfs      f5, 0x50C(r31)
  stfs      f2, 0x520(r31)
  stfs      f2, 0x51C(r31)
  stfs      f1, 0x528(r31)
  stfs      f1, 0x524(r31)
  stw       r0, 0x20(r31)
  stb       r28, 0x1193(r31)
  stb       r28, 0x1194(r31)
  stb       r28, 0x1195(r31)
  stb       r28, 0x1196(r31)
  stb       r28, 0x1198(r31)
  stb       r28, 0x28(r31)
  stfs      f0, 0x150(r31)
  stb       r28, 0x1180(r31)
  stw       r28, 0x294(r31)
  stw       r28, 0x298(r31)
  stw       r28, 0x14(r31)
  stw       r28, 0x18(r31)
  bl        -0x14285C
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x1C4
  li        r4, 0x10
  li        r5, 0x400
  li        r6, 0x400
  bl        0x60044

.loc_0x1C4:
  stw       r28, 0x0(r31)
  li        r3, 0xF8
  bl        -0x142884
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x234
  addi      r27, r28, 0
  addi      r3, r1, 0x68
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x29D78
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x68
  addi      r3, r27, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x270FC
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x234:
  stw       r28, 0x29C(r31)
  li        r3, 0xF8
  bl        -0x1428F4
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x2A4
  addi      r27, r28, 0
  addi      r3, r1, 0x60
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x29D08
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x60
  addi      r3, r27, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x2708C
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x2A4:
  stw       r28, 0x2A0(r31)
  li        r3, 0xF8
  bl        -0x142964
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x314
  addi      r27, r28, 0
  addi      r3, r1, 0x58
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x29C98
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x58
  addi      r3, r27, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x2701C
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x314:
  stw       r28, 0x2A4(r31)
  addi      r4, r30, 0x60
  li        r5, 0x1
  lwz       r3, 0x29C(r31)
  li        r6, 0x1
  li        r7, 0x1
  bl        0x29218
  lwz       r3, 0x2A0(r31)
  addi      r4, r30, 0x78
  li        r5, 0x1
  li        r6, 0x1
  li        r7, 0x1
  bl        0x29200
  lwz       r3, 0x2A4(r31)
  addi      r4, r30, 0x90
  li        r5, 0x1
  li        r6, 0x1
  li        r7, 0x1
  bl        0x291E8
  li        r3, 0xF8
  bl        -0x142A1C
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x3CC
  addi      r27, r28, 0
  addi      r3, r1, 0x50
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x29BE0
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x50
  addi      r3, r27, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x26F64
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x3CC:
  stw       r28, 0x2A8(r31)
  li        r3, 0xF8
  bl        -0x142A8C
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x43C
  addi      r27, r28, 0
  addi      r3, r1, 0x48
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x29B70
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x48
  addi      r3, r27, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x26EF4
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x43C:
  stw       r28, 0x2AC(r31)
  li        r3, 0xF8
  bl        -0x142AFC
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x4AC
  addi      r27, r28, 0
  addi      r3, r1, 0x40
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x29B00
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x40
  addi      r3, r27, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x26E84
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x4AC:
  stw       r28, 0x2B0(r31)
  addi      r4, r30, 0xA8
  li        r5, 0x1
  lwz       r3, 0x2A8(r31)
  li        r6, 0x1
  li        r7, 0x1
  bl        0x29080
  lwz       r3, 0x2AC(r31)
  addi      r4, r30, 0xC0
  li        r5, 0x1
  li        r6, 0x1
  li        r7, 0x1
  bl        0x29068
  lwz       r3, 0x2B0(r31)
  addi      r4, r30, 0xD8
  li        r5, 0x1
  li        r6, 0x1
  li        r7, 0x1
  bl        0x29050
  li        r27, 0
  rlwinm    r0,r27,2,0,29
  add       r28, r31, r0
  lis       r29, 0x726F

.loc_0x508:
  lwz       r3, 0x2A8(r28)
  addi      r4, r29, 0x6F74
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r27, r27, 0x1
  stw       r3, 0x380(r28)
  cmpwi     r27, 0x3
  addi      r28, r28, 0x4
  blt+      .loc_0x508
  li        r3, 0xF8
  bl        -0x142BF4
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x5A4
  addi      r27, r28, 0
  addi      r3, r1, 0x38
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x29A08
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x38
  addi      r3, r27, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x26D8C
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x5A4:
  stw       r28, 0x2B4(r31)
  addi      r4, r30, 0xF0
  li        r5, 0x1
  lwz       r3, 0x2B4(r31)
  li        r6, 0x1
  li        r7, 0x1
  bl        0x28F88
  li        r3, 0xF8
  bl        -0x142C7C
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x62C
  addi      r27, r28, 0
  addi      r3, r1, 0x30
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x29980
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x30
  addi      r3, r27, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x26D04
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x62C:
  stw       r28, 0x2B8(r31)
  addi      r4, r30, 0x108
  li        r5, 0x1
  lwz       r3, 0x2B8(r31)
  li        r6, 0x1
  li        r7, 0x1
  bl        0x28F00
  li        r3, 0xF8
  bl        -0x142D04
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x6B4
  addi      r27, r28, 0
  addi      r3, r1, 0x28
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x298F8
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x28
  addi      r3, r27, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x26C7C
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x6B4:
  stw       r28, 0x2BC(r31)
  addi      r4, r30, 0x120
  li        r5, 0x1
  lwz       r3, 0x2BC(r31)
  li        r6, 0x1
  li        r7, 0x1
  bl        0x28E78
  li        r3, 0xF8
  bl        -0x142D8C
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x73C
  addi      r27, r28, 0
  addi      r3, r1, 0x20
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x29870
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x20
  addi      r3, r27, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x26BF4
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x73C:
  stw       r28, 0x2C0(r31)
  addi      r4, r30, 0x138
  li        r5, 0
  lwz       r3, 0x2C0(r31)
  li        r6, 0
  li        r7, 0x1
  bl        0x28DF0
  lwz       r3, 0x2C0(r31)
  lis       r4, 0x626C
  addi      r4, r4, 0x636B
  lwz       r12, 0x0(r3)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x44C(r31)
  li        r0, 0xFF
  addi      r3, r31, 0
  lwz       r4, 0x44C(r31)
  stb       r0, 0xF0(r4)
  bl        -0x20CC
  mr        r3, r31
  bl        -0x1BF4
  mr        r3, r31
  bl        -0x176C
  mr        r3, r31
  bl        -0x109C
  addi      r3, r31, 0
  li        r4, 0x1
  bl        -0xDB8
  li        r30, 0
  stw       r30, 0x24(r31)
  lwz       r0, 0x24(r31)
  cmpwi     r0, 0x1
  beq-      .loc_0x860
  bge-      .loc_0x7D8
  cmpwi     r0, 0
  bge-      .loc_0x7E4
  b         .loc_0x874

.loc_0x7D8:
  cmpwi     r0, 0x3
  bge-      .loc_0x874
  b         .loc_0x86C

.loc_0x7E4:
  addi      r3, r31, 0
  li        r4, 0x1
  bl        -0xDF4
  lha       r0, 0x134(r31)
  add       r3, r31, r0
  lbz       r0, 0x1190(r3)
  cmplwi    r0, 0
  beq-      .loc_0x820
  lbz       r0, 0x28(r31)
  cmplwi    r0, 0
  beq-      .loc_0x818
  stb       r30, 0x278(r31)
  b         .loc_0x83C

.loc_0x818:
  stb       r30, 0x278(r31)
  b         .loc_0x83C

.loc_0x820:
  lbz       r0, 0x28(r31)
  cmplwi    r0, 0
  beq-      .loc_0x834
  stb       r30, 0x278(r31)
  b         .loc_0x83C

.loc_0x834:
  li        r0, 0x1
  stb       r0, 0x278(r31)

.loc_0x83C:
  lfs       f1, -0x4FA0(r2)
  addi      r3, r31, 0xA4
  lfs       f2, -0x4F88(r2)
  bl        0x50D14
  lfs       f1, -0x4FA0(r2)
  addi      r3, r31, 0xD4
  lfs       f2, -0x4F88(r2)
  bl        0x50D04
  b         .loc_0x874

.loc_0x860:
  mr        r3, r31
  bl        0xD27C
  b         .loc_0x874

.loc_0x86C:
  mr        r3, r31
  bl        0xDBAC

.loc_0x874:
  lfs       f2, -0x4F98(r2)
  mr        r3, r31
  lwz       r4, 0x29C(r31)
  fmr       f1, f2
  stfs      f2, 0xC0(r4)
  fmr       f0, f2
  stfs      f2, 0xC4(r4)
  stfs      f1, 0xC8(r4)
  lwz       r4, 0x2A8(r31)
  stfs      f0, 0xC0(r4)
  stfs      f2, 0xC4(r4)
  stfs      f2, 0xC8(r4)
  lwz       r4, 0x2A0(r31)
  stfs      f2, 0xC0(r4)
  stfs      f2, 0xC4(r4)
  stfs      f2, 0xC8(r4)
  lwz       r4, 0x2AC(r31)
  stfs      f2, 0xC0(r4)
  stfs      f2, 0xC4(r4)
  stfs      f2, 0xC8(r4)
  lwz       r4, 0x2A4(r31)
  stfs      f2, 0xC0(r4)
  stfs      f2, 0xC4(r4)
  stfs      f2, 0xC8(r4)
  lwz       r4, 0x2B0(r31)
  stfs      f2, 0xC0(r4)
  stfs      f2, 0xC4(r4)
  stfs      f2, 0xC8(r4)
  lmw       r27, 0x74(r1)
  lwz       r0, 0x8C(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80189FB4
 * Size:	00000C
 */
void CardQuickInfo::CardQuickInfo()
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void zen::ogScrFileSelectMgr::setDataScale()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80189FC0
 * Size:	0001B8
 */
void zen::ogScrFileSelectMgr::chaseDataScale()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stfd      f31, 0x38(r1)
  stfd      f30, 0x30(r1)
  stfd      f29, 0x28(r1)
  stfd      f28, 0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  li        r30, 0
  stw       r29, 0x14(r1)
  mr        r29, r3
  mr        r31, r29
  lfs       f28, -0x4F84(r2)
  lfs       f29, -0x4F6C(r2)
  lfs       f30, -0x4F9C(r2)
  lfs       f31, -0x4F98(r2)

.loc_0x44:
  lha       r0, 0x134(r29)
  cmpw      r0, r30
  bne-      .loc_0xAC
  lfs       f1, 0x138(r31)
  li        r4, 0xFF
  fsubs     f0, f31, f1
  fdivs     f0, f0, f29
  fadds     f0, f1, f0
  stfs      f0, 0x138(r31)
  lfs       f1, 0x144(r31)
  fsubs     f0, f31, f1
  fmuls     f0, f0, f30
  fadds     f0, f1, f0
  stfs      f0, 0x144(r31)
  lwz       r3, 0x3B0(r31)
  bl        0x35898
  lwz       r3, 0x3BC(r31)
  li        r4, 0x46
  bl        0x3588C
  lwz       r3, 0x398(r31)
  li        r4, 0xFF
  bl        0x35880
  lwz       r3, 0x3A4(r31)
  li        r4, 0xFF
  bl        0x35874
  b         .loc_0x104

.loc_0xAC:
  lfs       f1, 0x138(r31)
  li        r4, 0x80
  fsubs     f0, f28, f1
  fdivs     f0, f0, f29
  fadds     f0, f1, f0
  stfs      f0, 0x138(r31)
  lfs       f1, 0x144(r31)
  fsubs     f0, f28, f1
  fmuls     f0, f0, f30
  fadds     f0, f1, f0
  stfs      f0, 0x144(r31)
  lwz       r3, 0x3B0(r31)
  bl        0x3583C
  lwz       r3, 0x3BC(r31)
  li        r4, 0x40
  bl        0x35830
  lwz       r3, 0x398(r31)
  li        r4, 0x80
  bl        0x35824
  lwz       r3, 0x3A4(r31)
  li        r4, 0x80
  bl        0x35818

.loc_0x104:
  addi      r30, r30, 0x1
  cmpwi     r30, 0x3
  addi      r31, r31, 0x4
  blt+      .loc_0x44
  lfs       f0, 0x138(r29)
  lwz       r3, 0x38C(r29)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lfs       f0, 0x144(r29)
  lwz       r3, 0x380(r29)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lfs       f0, 0x13C(r29)
  lwz       r3, 0x390(r29)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lfs       f0, 0x148(r29)
  lwz       r3, 0x384(r29)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lfs       f0, 0x140(r29)
  lwz       r3, 0x394(r29)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lfs       f0, 0x14C(r29)
  lwz       r3, 0x388(r29)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lwz       r0, 0x44(r1)
  lfd       f31, 0x38(r1)
  lfd       f30, 0x30(r1)
  lfd       f29, 0x28(r1)
  lfd       f28, 0x20(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018A178
 * Size:	0001B8
 */
void zen::ogScrFileSelectMgr::OnOffNewPane(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stw       r31, 0x54(r1)
  stw       r30, 0x50(r1)
  addi      r30, r4, 0
  stw       r29, 0x4C(r1)
  addi      r29, r3, 0
  add       r3, r29, r30
  stw       r28, 0x48(r1)
  lbz       r0, 0x1190(r3)
  cmplwi    r0, 0
  beq-      .loc_0xDC
  rlwinm    r0,r30,2,0,29
  add       r5, r29, r0
  lwz       r3, 0x398(r5)
  li        r6, 0x1
  li        r4, 0
  lbz       r0, 0xC(r3)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x3A4(r5)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x3B0(r5)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x3BC(r5)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lha       r0, 0x134(r29)
  cmpw      r30, r0
  bne-      .loc_0x198
  lwz       r3, 0x334(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x378(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x37C(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r3)
  lbz       r0, 0x28(r29)
  cmplwi    r0, 0
  beq-      .loc_0xD4
  stb       r4, 0x278(r29)
  b         .loc_0x198

.loc_0xD4:
  stb       r4, 0x278(r29)
  b         .loc_0x198

.loc_0xDC:
  rlwinm    r0,r30,2,0,29
  add       r6, r29, r0
  lwz       r4, 0x398(r6)
  li        r31, 0
  li        r28, 0x1
  lbz       r0, 0xC(r4)
  rlwimi    r0,r31,7,24,24
  addi      r3, r29, 0
  stb       r0, 0xC(r4)
  mr        r4, r30
  lwz       r5, 0x3A4(r6)
  lbz       r0, 0xC(r5)
  rlwimi    r0,r31,7,24,24
  stb       r0, 0xC(r5)
  lwz       r5, 0x3B0(r6)
  lbz       r0, 0xC(r5)
  rlwimi    r0,r28,7,24,24
  stb       r0, 0xC(r5)
  lwz       r5, 0x3BC(r6)
  lbz       r0, 0xC(r5)
  rlwimi    r0,r28,7,24,24
  stb       r0, 0xC(r5)
  bl        -0x16A0
  lha       r0, 0x134(r29)
  cmpw      r30, r0
  bne-      .loc_0x198
  addi      r3, r29, 0
  addi      r4, r30, 0
  bl        -0x1D3C
  lwz       r3, 0x334(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r28,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x378(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r28,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x37C(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r31,7,24,24
  stb       r0, 0xC(r3)
  lbz       r0, 0x28(r29)
  cmplwi    r0, 0
  beq-      .loc_0x194
  stb       r31, 0x278(r29)
  b         .loc_0x198

.loc_0x194:
  stb       r28, 0x278(r29)

.loc_0x198:
  lwz       r0, 0x5C(r1)
  lwz       r31, 0x54(r1)
  lwz       r30, 0x50(r1)
  lwz       r29, 0x4C(r1)
  lwz       r28, 0x48(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018A330
 * Size:	0000B8
 */
void zen::ogScrFileSelectMgr::ChkOnyonOnOff()
{
/*
.loc_0x0:
  lha       r0, 0x134(r3)
  mulli     r0, r0, 0x28
  add       r4, r3, r0
  lwz       r0, 0x40(r4)
  lwz       r6, 0x48(r4)
  cmpwi     r0, 0
  lwz       r7, 0x44(r4)
  bge-      .loc_0x38
  lwz       r4, 0x36C(r3)
  li        r5, 0
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  b         .loc_0x4C

.loc_0x38:
  lwz       r4, 0x36C(r3)
  li        r5, 0x1
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)

.loc_0x4C:
  cmpwi     r6, 0
  bge-      .loc_0x6C
  lwz       r4, 0x370(r3)
  li        r5, 0
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  b         .loc_0x80

.loc_0x6C:
  lwz       r4, 0x370(r3)
  li        r5, 0x1
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)

.loc_0x80:
  cmpwi     r7, 0
  bge-      .loc_0xA0
  lwz       r3, 0x374(r3)
  li        r4, 0
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  blr       

.loc_0xA0:
  lwz       r3, 0x374(r3)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8018A3E8
 * Size:	000088
 */
void zen::ogScrFileSelectMgr::ChkNewData()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, 0
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r0, 0x34(r3)
  subfic    r0, r0, 0x1
  cntlzw    r0, r0
  rlwinm    r0,r0,27,5,31
  stb       r0, 0x1190(r3)
  lwz       r0, 0x5C(r3)
  subfic    r0, r0, 0x1
  cntlzw    r0, r0
  rlwinm    r0,r0,27,5,31
  stb       r0, 0x1191(r3)
  lwz       r0, 0x84(r3)
  subfic    r0, r0, 0x1
  cntlzw    r0, r0
  rlwinm    r0,r0,27,5,31
  stb       r0, 0x1192(r3)

.loc_0x58:
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        -0x2D0
  addi      r31, r31, 0x1
  cmpwi     r31, 0x3
  blt+      .loc_0x58
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
 * Address:	8018A470
 * Size:	000404
 */
void zen::ogScrFileSelectMgr::start(bool, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, -0x1
  stwu      r1, -0x58(r1)
  stfd      f31, 0x50(r1)
  stfd      f30, 0x48(r1)
  stw       r31, 0x44(r1)
  addi      r31, r3, 0
  stw       r30, 0x40(r1)
  stw       r29, 0x3C(r1)
  stw       r0, 0x20(r3)
  li        r0, 0
  stb       r0, 0x1193(r3)
  stb       r0, 0x1194(r3)
  stb       r0, 0x1195(r3)
  stb       r0, 0x1196(r3)
  stb       r0, 0x1198(r3)
  stb       r0, 0x28(r3)
  lfs       f0, -0x4FA0(r2)
  stfs      f0, 0x150(r3)
  stb       r0, 0x1180(r3)
  stw       r0, 0x294(r3)
  stw       r0, 0x298(r3)
  stw       r0, 0x14(r3)
  stw       r0, 0x18(r3)
  stb       r4, 0x28(r3)
  lbz       r0, 0x28(r3)
  cmplwi    r0, 0
  beq-      .loc_0x84
  addi      r3, r31, 0
  li        r4, 0xB
  bl        -0x1438
  b         .loc_0x90

.loc_0x84:
  addi      r3, r31, 0
  li        r4, 0x1
  bl        -0x1448

.loc_0x90:
  li        r30, 0
  stw       r30, 0x14(r31)
  mr        r3, r31
  stw       r30, 0x18(r31)
  bl        -0x2C40
  stb       r30, 0x1193(r31)
  li        r0, 0x1
  li        r3, 0
  stb       r30, 0x1194(r31)
  stb       r30, 0x1195(r31)
  stb       r30, 0x1196(r31)
  stb       r30, 0x1197(r31)
  lfs       f0, -0x4FA0(r2)
  stfs      f0, 0x54C(r31)
  stfs      f0, 0x1184(r31)
  stw       r0, 0x20(r31)
  lha       r0, 0x134(r31)
  cmpw      r3, r0
  beq-      .loc_0xE4
  stw       r3, 0x119C(r31)
  b         .loc_0x108

.loc_0xE4:
  li        r3, 0x1
  cmpw      r3, r0
  beq-      .loc_0xF8
  stw       r3, 0x119C(r31)
  b         .loc_0x108

.loc_0xF8:
  li        r3, 0x2
  cmpw      r3, r0
  beq-      .loc_0x108
  stw       r3, 0x119C(r31)

.loc_0x108:
  li        r29, 0
  sth       r29, 0x134(r31)
  mr        r3, r31
  lha       r4, 0x134(r31)
  bl        -0x1194
  lfs       f30, -0x4F98(r2)
  mr        r30, r31
  lfs       f31, -0x4F84(r2)

.loc_0x128:
  lha       r0, 0x134(r31)
  cmpw      r0, r29
  bne-      .loc_0x140
  stfs      f30, 0x138(r30)
  stfs      f30, 0x144(r30)
  b         .loc_0x148

.loc_0x140:
  stfs      f31, 0x138(r30)
  stfs      f31, 0x144(r30)

.loc_0x148:
  lwz       r0, 0x158(r30)
  stw       r0, 0x1D0(r30)
  lwz       r0, 0x164(r30)
  stw       r0, 0x1DC(r30)
  lwz       r0, 0x170(r30)
  stw       r0, 0x1E8(r30)
  lwz       r0, 0x17C(r30)
  stw       r0, 0x1F4(r30)
  lwz       r3, 0x3B0(r30)
  lwz       r4, 0x1D0(r30)
  lwz       r12, 0x0(r3)
  lwz       r5, 0x1DC(r30)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x3B0(r30)
  stfs      f30, 0xC0(r3)
  stfs      f30, 0xC4(r3)
  stfs      f30, 0xC8(r3)
  lwz       r3, 0x3BC(r30)
  lwz       r4, 0x1E8(r30)
  lwz       r12, 0x0(r3)
  lwz       r5, 0x1F4(r30)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x3BC(r30)
  li        r4, 0xFF
  stfs      f30, 0xC0(r3)
  stfs      f30, 0xC4(r3)
  stfs      f30, 0xC8(r3)
  lwz       r3, 0x3B0(r30)
  bl        0x352A0
  lwz       r0, 0x200(r30)
  stw       r0, 0x218(r30)
  lwz       r0, 0x20C(r30)
  stw       r0, 0x224(r30)
  lwz       r3, 0x398(r30)
  lwz       r4, 0x218(r30)
  lwz       r12, 0x0(r3)
  lwz       r5, 0x224(r30)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x398(r30)
  stfs      f30, 0xC0(r3)
  stfs      f30, 0xC4(r3)
  stfs      f30, 0xC8(r3)
  lwz       r0, 0x230(r30)
  stw       r0, 0x248(r30)
  lwz       r0, 0x23C(r30)
  stw       r0, 0x254(r30)
  lwz       r3, 0x3A4(r30)
  lwz       r4, 0x248(r30)
  lwz       r12, 0x0(r3)
  lwz       r5, 0x254(r30)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x3A4(r30)
  addi      r29, r29, 0x1
  cmpwi     r29, 0x3
  stfs      f30, 0xC0(r3)
  addi      r30, r30, 0x4
  stfs      f30, 0xC4(r3)
  stfs      f30, 0xC8(r3)
  blt+      .loc_0x128
  li        r3, 0
  stb       r3, 0x1180(r31)
  li        r0, 0xFF
  stw       r3, 0x27C(r31)
  stb       r3, 0x284(r31)
  stb       r3, 0x28C(r31)
  lwz       r3, 0x44C(r31)
  stb       r0, 0xF0(r3)
  lfs       f0, 0x138(r31)
  lwz       r3, 0x38C(r31)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lfs       f0, 0x144(r31)
  lwz       r3, 0x380(r31)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lfs       f0, 0x13C(r31)
  lwz       r3, 0x390(r31)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lfs       f0, 0x148(r31)
  lwz       r3, 0x384(r31)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lfs       f0, 0x140(r31)
  lwz       r3, 0x394(r31)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lfs       f0, 0x14C(r31)
  lwz       r3, 0x388(r31)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lbz       r0, 0x28(r31)
  cmplwi    r0, 0
  bne-      .loc_0x3E0
  lfs       f0, -0x4FA0(r2)
  addi      r5, r1, 0x28
  li        r4, 0x11
  stfs      f0, 0x30(r1)
  li        r6, 0
  li        r7, 0
  stfs      f0, 0x2C(r1)
  stfs      f0, 0x28(r1)
  lfs       f1, 0xCF0(r13)
  lfs       f0, 0xCF4(r13)
  stfs      f1, 0x28(r1)
  stfs      f0, 0x2C(r1)
  lfs       f0, 0xCF8(r13)
  stfs      f0, 0x30(r1)
  lwz       r3, 0x0(r31)
  bl        0x5F398
  lwz       r3, 0x0(r31)
  addi      r5, r1, 0x28
  li        r4, 0x12
  li        r6, 0
  li        r7, 0
  bl        0x5F380
  lwz       r3, 0x0(r31)
  addi      r5, r1, 0x28
  li        r4, 0x13
  li        r6, 0
  li        r7, 0
  bl        0x5F368
  lwz       r3, 0x0(r31)
  addi      r5, r1, 0x28
  li        r4, 0x14
  li        r6, 0
  li        r7, 0
  bl        0x5F350
  lwz       r3, 0x0(r31)
  addi      r5, r1, 0x28
  li        r4, 0x15
  li        r6, 0
  li        r7, 0
  bl        0x5F338
  lwz       r3, 0x0(r31)
  addi      r5, r1, 0x28
  li        r4, 0x16
  li        r6, 0
  li        r7, 0
  bl        0x5F320
  lwz       r3, 0x0(r31)
  addi      r5, r1, 0x28
  li        r4, 0x17
  li        r6, 0
  li        r7, 0
  bl        0x5F308
  lwz       r3, 0x0(r31)
  addi      r5, r1, 0x28
  li        r4, 0x18
  li        r6, 0
  li        r7, 0
  bl        0x5F2F0

.loc_0x3E0:
  lwz       r0, 0x5C(r1)
  lfd       f31, 0x50(r1)
  lfd       f30, 0x48(r1)
  lwz       r31, 0x44(r1)
  lwz       r30, 0x40(r1)
  lwz       r29, 0x3C(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void zen::ogScrFileSelectMgr::BeginFadeOut()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void zen::ogScrFileSelectMgr::CanToCopy(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018A874
 * Size:	00036C
 */
void zen::ogScrFileSelectMgr::OperateSelect(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  stw       r30, 0x10(r1)
  lwz       r4, 0x28(r4)
  rlwinm.   r0,r4,0,9,9
  beq-      .loc_0x54
  lha       r0, 0x134(r31)
  cmpwi     r0, 0
  ble-      .loc_0x54
  li        r3, 0x112
  bl        -0xE5534
  lha       r4, 0x134(r31)
  addi      r3, r31, 0
  subi      r0, r4, 0x1
  sth       r0, 0x134(r31)
  lha       r4, 0x134(r31)
  bl        -0x14CC
  b         .loc_0x354

.loc_0x54:
  rlwinm.   r0,r4,0,11,11
  beq-      .loc_0x8C
  lha       r0, 0x134(r31)
  cmpwi     r0, 0x2
  bge-      .loc_0x8C
  li        r3, 0x112
  bl        -0xE556C
  lha       r4, 0x134(r31)
  addi      r3, r31, 0
  addi      r0, r4, 0x1
  sth       r0, 0x134(r31)
  lha       r4, 0x134(r31)
  bl        -0x1504
  b         .loc_0x354

.loc_0x8C:
  rlwinm.   r0,r4,0,19,19
  beq-      .loc_0x110
  li        r3, 0x111
  bl        -0xE5598
  mr        r3, r31
  bl        .loc_0x36C
  lbz       r0, 0x28(r31)
  cmplwi    r0, 0
  beq-      .loc_0xCC
  li        r0, 0x2
  stw       r0, 0x20(r31)
  lfs       f0, -0x4FA0(r2)
  stfs      f0, 0x1184(r31)
  stw       r0, 0x20(r31)
  stfs      f0, 0x1184(r31)
  b         .loc_0x354

.loc_0xCC:
  lfs       f0, -0x4FA0(r2)
  li        r0, 0x3
  stfs      f0, 0x150(r31)
  stw       r0, 0x20(r31)
  lfs       f0, -0x4F68(r2)
  stfs      f0, 0x53C(r31)
  lwz       r3, 0x14(r31)
  cmplwi    r3, 0
  beq-      .loc_0xF4
  bl        0x16298

.loc_0xF4:
  lwz       r3, 0x18(r31)
  cmplwi    r3, 0
  beq-      .loc_0x104
  bl        0x16288

.loc_0x104:
  mr        r3, r31
  bl        0x460
  b         .loc_0x354

.loc_0x110:
  rlwinm.   r0,r4,0,18,18
  beq-      .loc_0x15C
  li        r0, 0x1
  stb       r0, 0x1193(r31)
  li        r0, 0x2
  li        r3, 0x11D
  stw       r0, 0x20(r31)
  lfs       f0, -0x4FA0(r2)
  stfs      f0, 0x1184(r31)
  bl        -0xE5634
  lwz       r3, 0x14(r31)
  cmplwi    r3, 0
  beq-      .loc_0x148
  bl        0x16244

.loc_0x148:
  lwz       r3, 0x18(r31)
  cmplwi    r3, 0
  beq-      .loc_0x354
  bl        0x16234
  b         .loc_0x354

.loc_0x15C:
  rlwinm.   r0,r4,0,16,16
  beq-      .loc_0x258
  lha       r0, 0x134(r31)
  add       r3, r31, r0
  lbz       r0, 0x1190(r3)
  cmplwi    r0, 0
  bne-      .loc_0x354
  lbz       r0, 0x28(r31)
  cmplwi    r0, 0
  bne-      .loc_0x354
  li        r3, 0x111
  bl        -0xE5688
  li        r30, 0x1
  stw       r30, 0x24(r31)
  lwz       r0, 0x24(r31)
  cmpwi     r0, 0x1
  beq-      .loc_0x240
  bge-      .loc_0x1B0
  cmpwi     r0, 0
  bge-      .loc_0x1BC
  b         .loc_0x354

.loc_0x1B0:
  cmpwi     r0, 0x3
  bge-      .loc_0x354
  b         .loc_0x24C

.loc_0x1BC:
  addi      r3, r31, 0
  li        r4, 0x1
  bl        -0x1984
  lha       r0, 0x134(r31)
  add       r3, r31, r0
  lbz       r0, 0x1190(r3)
  cmplwi    r0, 0
  beq-      .loc_0x200
  lbz       r0, 0x28(r31)
  cmplwi    r0, 0
  beq-      .loc_0x1F4
  li        r0, 0
  stb       r0, 0x278(r31)
  b         .loc_0x21C

.loc_0x1F4:
  li        r0, 0
  stb       r0, 0x278(r31)
  b         .loc_0x21C

.loc_0x200:
  lbz       r0, 0x28(r31)
  cmplwi    r0, 0
  beq-      .loc_0x218
  li        r0, 0
  stb       r0, 0x278(r31)
  b         .loc_0x21C

.loc_0x218:
  stb       r30, 0x278(r31)

.loc_0x21C:
  lfs       f1, -0x4FA0(r2)
  addi      r3, r31, 0xA4
  lfs       f2, -0x4F88(r2)
  bl        0x5017C
  lfs       f1, -0x4FA0(r2)
  addi      r3, r31, 0xD4
  lfs       f2, -0x4F88(r2)
  bl        0x5016C
  b         .loc_0x354

.loc_0x240:
  mr        r3, r31
  bl        0xC6E4
  b         .loc_0x354

.loc_0x24C:
  mr        r3, r31
  bl        0xD014
  b         .loc_0x354

.loc_0x258:
  rlwinm.   r0,r4,0,17,17
  beq-      .loc_0x354
  lha       r0, 0x134(r31)
  add       r3, r31, r0
  lbz       r0, 0x1190(r3)
  cmplwi    r0, 0
  bne-      .loc_0x354
  lbz       r0, 0x28(r31)
  cmplwi    r0, 0
  bne-      .loc_0x354
  li        r3, 0x111
  bl        -0xE5784
  li        r0, 0x2
  stw       r0, 0x24(r31)
  lwz       r0, 0x24(r31)
  cmpwi     r0, 0x1
  beq-      .loc_0x340
  bge-      .loc_0x2AC
  cmpwi     r0, 0
  bge-      .loc_0x2B8
  b         .loc_0x354

.loc_0x2AC:
  cmpwi     r0, 0x3
  bge-      .loc_0x354
  b         .loc_0x34C

.loc_0x2B8:
  addi      r3, r31, 0
  li        r4, 0x1
  bl        -0x1A80
  lha       r0, 0x134(r31)
  add       r3, r31, r0
  lbz       r0, 0x1190(r3)
  cmplwi    r0, 0
  beq-      .loc_0x2FC
  lbz       r0, 0x28(r31)
  cmplwi    r0, 0
  beq-      .loc_0x2F0
  li        r0, 0
  stb       r0, 0x278(r31)
  b         .loc_0x31C

.loc_0x2F0:
  li        r0, 0
  stb       r0, 0x278(r31)
  b         .loc_0x31C

.loc_0x2FC:
  lbz       r0, 0x28(r31)
  cmplwi    r0, 0
  beq-      .loc_0x314
  li        r0, 0
  stb       r0, 0x278(r31)
  b         .loc_0x31C

.loc_0x314:
  li        r0, 0x1
  stb       r0, 0x278(r31)

.loc_0x31C:
  lfs       f1, -0x4FA0(r2)
  addi      r3, r31, 0xA4
  lfs       f2, -0x4F88(r2)
  bl        0x5007C
  lfs       f1, -0x4FA0(r2)
  addi      r3, r31, 0xD4
  lfs       f2, -0x4F88(r2)
  bl        0x5006C
  b         .loc_0x354

.loc_0x340:
  mr        r3, r31
  bl        0xC5E4
  b         .loc_0x354

.loc_0x34C:
  mr        r3, r31
  bl        0xCF14

.loc_0x354:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr       

.loc_0x36C:
*/
}

/*
 * --INFO--
 * Address:	8018ABE0
 * Size:	0001FC
 */
void zen::ogScrFileSelectMgr::KetteiEffectStart()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x25
  stw       r0, 0x4(r1)
  li        r6, 0
  li        r7, 0
  stwu      r1, -0xC0(r1)
  stw       r31, 0xBC(r1)
  lis       r31, 0x4330
  addi      r5, r1, 0x6C
  stw       r30, 0xB8(r1)
  addi      r30, r3, 0
  lfs       f0, -0x4FA0(r2)
  stfs      f0, 0x74(r1)
  stfs      f0, 0x70(r1)
  stfs      f0, 0x6C(r1)
  lfs       f1, 0xCFC(r13)
  lfs       f0, 0xD00(r13)
  stfs      f1, 0x6C(r1)
  stfs      f0, 0x70(r1)
  lfs       f0, 0xD04(r13)
  stfs      f0, 0x74(r1)
  lha       r0, 0x134(r3)
  lfd       f4, -0x4F80(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4F74(r2)
  add       r3, r30, r0
  lfs       f2, -0x4F70(r2)
  lwz       r8, 0x3B0(r3)
  lha       r3, 0x18(r8)
  lha       r0, 0x1C(r8)
  lha       r8, 0x18(r8)
  sub       r0, r0, r3
  xoris     r0, r0, 0x8000
  stw       r0, 0xAC(r1)
  xoris     r0, r8, 0x8000
  stw       r31, 0xA8(r1)
  stw       r0, 0xB4(r1)
  lfd       f0, 0xA8(r1)
  stw       r31, 0xB0(r1)
  fsubs     f0, f0, f4
  lfd       f1, 0xB0(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  stfs      f0, 0x6C(r1)
  lha       r0, 0x134(r30)
  rlwinm    r0,r0,2,0,29
  add       r3, r30, r0
  lwz       r9, 0x3B0(r3)
  lha       r8, 0x1A(r9)
  lha       r3, 0x1A(r9)
  lha       r0, 0x1E(r9)
  xoris     r8, r8, 0x8000
  stw       r8, 0xA4(r1)
  sub       r0, r0, r3
  xoris     r0, r0, 0x8000
  stw       r31, 0xA0(r1)
  stw       r0, 0x9C(r1)
  lfd       f0, 0xA0(r1)
  stw       r31, 0x98(r1)
  fsubs     f1, f0, f4
  lfd       f0, 0x98(r1)
  fsubs     f0, f0, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  fsubs     f0, f2, f0
  stfs      f0, 0x70(r1)
  lwz       r3, 0x0(r30)
  bl        0x5EE4C
  lha       r0, 0x134(r30)
  addi      r5, r1, 0x6C
  lfd       f4, -0x4F80(r2)
  li        r4, 0x22
  rlwinm    r0,r0,2,0,29
  add       r3, r30, r0
  lfs       f3, -0x4F74(r2)
  lwz       r8, 0x3BC(r3)
  li        r6, 0
  lfs       f2, -0x4F70(r2)
  li        r7, 0
  lha       r3, 0x18(r8)
  lha       r0, 0x1C(r8)
  lha       r8, 0x18(r8)
  sub       r0, r0, r3
  xoris     r0, r0, 0x8000
  stw       r0, 0x8C(r1)
  xoris     r0, r8, 0x8000
  stw       r31, 0x88(r1)
  stw       r0, 0x94(r1)
  lfd       f0, 0x88(r1)
  stw       r31, 0x90(r1)
  fsubs     f0, f0, f4
  lfd       f1, 0x90(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  stfs      f0, 0x6C(r1)
  lha       r0, 0x134(r30)
  rlwinm    r0,r0,2,0,29
  add       r3, r30, r0
  lwz       r8, 0x3BC(r3)
  lha       r3, 0x1A(r8)
  lha       r0, 0x1E(r8)
  lha       r8, 0x1A(r8)
  sub       r0, r0, r3
  xoris     r0, r0, 0x8000
  stw       r0, 0x7C(r1)
  xoris     r0, r8, 0x8000
  stw       r31, 0x78(r1)
  stw       r0, 0x84(r1)
  lfd       f0, 0x78(r1)
  stw       r31, 0x80(r1)
  fsubs     f0, f0, f4
  lfd       f1, 0x80(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f0, f3
  fadds     f0, f1, f0
  fsubs     f0, f2, f0
  stfs      f0, 0x70(r1)
  lwz       r3, 0x0(r30)
  bl        0x5ED7C
  lwz       r0, 0xC4(r1)
  lwz       r31, 0xBC(r1)
  lwz       r30, 0xB8(r1)
  addi      r1, r1, 0xC0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018ADDC
 * Size:	0001D4
 */
void zen::ogScrFileSelectMgr::TailEffectStart()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x26
  stw       r0, 0x4(r1)
  li        r6, 0
  li        r7, 0
  stwu      r1, -0xB0(r1)
  stw       r31, 0xAC(r1)
  lis       r31, 0x4330
  addi      r5, r1, 0x6C
  stw       r30, 0xA8(r1)
  addi      r30, r3, 0
  lfs       f0, -0x4FA0(r2)
  stfs      f0, 0x74(r1)
  stfs      f0, 0x70(r1)
  stfs      f0, 0x6C(r1)
  lfs       f1, 0xD08(r13)
  lfs       f0, 0xD0C(r13)
  stfs      f1, 0x6C(r1)
  stfs      f0, 0x70(r1)
  lfs       f0, 0xD10(r13)
  stfs      f0, 0x74(r1)
  lha       r0, 0x134(r3)
  lfd       f4, -0x4F80(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f0, -0x4F74(r2)
  add       r3, r30, r0
  lfs       f1, -0x4F70(r2)
  lwz       r8, 0x3B0(r3)
  lha       r3, 0x18(r8)
  lha       r0, 0x1C(r8)
  lha       r8, 0x18(r8)
  sub       r0, r0, r3
  xoris     r0, r0, 0x8000
  stw       r0, 0x9C(r1)
  xoris     r0, r8, 0x8000
  stw       r31, 0x98(r1)
  stw       r0, 0xA4(r1)
  lfd       f2, 0x98(r1)
  stw       r31, 0xA0(r1)
  fsubs     f2, f2, f4
  lfd       f3, 0xA0(r1)
  fsubs     f3, f3, f4
  fmuls     f0, f2, f0
  fadds     f0, f3, f0
  stfs      f0, 0x6C(r1)
  lha       r0, 0x134(r30)
  rlwinm    r0,r0,2,0,29
  add       r3, r30, r0
  lwz       r8, 0x3B0(r3)
  lha       r3, 0x1A(r8)
  lha       r0, 0x1E(r8)
  lha       r8, 0x1A(r8)
  sub       r0, r0, r3
  add       r0, r8, r0
  xoris     r0, r0, 0x8000
  stw       r0, 0x94(r1)
  stw       r31, 0x90(r1)
  lfd       f0, 0x90(r1)
  fsubs     f0, f0, f4
  fsubs     f0, f1, f0
  stfs      f0, 0x70(r1)
  lwz       r3, 0x0(r30)
  bl        0x5EC68
  stw       r3, 0xC(r30)
  addi      r5, r1, 0x6C
  li        r4, 0x21
  lha       r0, 0x134(r30)
  li        r6, 0
  lfd       f4, -0x4F80(r2)
  li        r7, 0
  rlwinm    r0,r0,2,0,29
  add       r3, r30, r0
  lfs       f0, -0x4F74(r2)
  lwz       r8, 0x3BC(r3)
  lfs       f1, -0x4F70(r2)
  lha       r3, 0x18(r8)
  lha       r0, 0x1C(r8)
  lha       r8, 0x18(r8)
  sub       r0, r0, r3
  xoris     r0, r0, 0x8000
  stw       r0, 0x84(r1)
  xoris     r0, r8, 0x8000
  stw       r31, 0x80(r1)
  stw       r0, 0x8C(r1)
  lfd       f2, 0x80(r1)
  stw       r31, 0x88(r1)
  fsubs     f2, f2, f4
  lfd       f3, 0x88(r1)
  fsubs     f3, f3, f4
  fmuls     f0, f2, f0
  fadds     f0, f3, f0
  stfs      f0, 0x6C(r1)
  lha       r0, 0x134(r30)
  rlwinm    r0,r0,2,0,29
  add       r3, r30, r0
  lwz       r8, 0x3BC(r3)
  lha       r3, 0x1A(r8)
  lha       r0, 0x1E(r8)
  lha       r8, 0x1A(r8)
  sub       r0, r0, r3
  add       r0, r8, r0
  xoris     r0, r0, 0x8000
  stw       r0, 0x7C(r1)
  stw       r31, 0x78(r1)
  lfd       f0, 0x78(r1)
  fsubs     f0, f0, f4
  fsubs     f0, f1, f0
  stfs      f0, 0x70(r1)
  lwz       r3, 0x0(r30)
  bl        0x5EBAC
  stw       r3, 0x10(r30)
  lwz       r0, 0xB4(r1)
  lwz       r31, 0xAC(r1)
  lwz       r30, 0xA8(r1)
  addi      r1, r1, 0xB0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void zen::ogScrFileSelectMgr::TailEffectMove(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void zen::ogScrFileSelectMgr::TailEffectMoveM(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void zen::ogScrFileSelectMgr::quit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018AFB0
 * Size:	000A20
 */
void zen::ogScrFileSelectMgr::update(Controller *, CardQuickInfo &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x288(r1)
  stw       r31, 0x284(r1)
  stw       r30, 0x280(r1)
  stw       r29, 0x27C(r1)
  addi      r29, r4, 0
  stw       r28, 0x278(r1)
  mr        r28, r3
  lwz       r3, 0x20(r3)
  cmpwi     r3, -0x1
  bne-      .loc_0x34
  b         .loc_0xA00

.loc_0x34:
  lha       r0, 0x134(r28)
  mulli     r0, r0, 0x28
  add       r4, r28, r0
  lwz       r3, 0x2C(r4)
  lwz       r0, 0x30(r4)
  stw       r3, 0x0(r5)
  stw       r0, 0x4(r5)
  lwz       r3, 0x34(r4)
  lwz       r0, 0x38(r4)
  stw       r3, 0x8(r5)
  stw       r0, 0xC(r5)
  lwz       r3, 0x3C(r4)
  lwz       r0, 0x40(r4)
  stw       r3, 0x10(r5)
  stw       r0, 0x14(r5)
  lwz       r3, 0x44(r4)
  lwz       r0, 0x48(r4)
  stw       r3, 0x18(r5)
  stw       r0, 0x1C(r5)
  lwz       r3, 0x4C(r4)
  lwz       r0, 0x50(r4)
  stw       r3, 0x20(r5)
  stw       r0, 0x24(r5)
  lwz       r3, 0x0(r28)
  bl        0x5EB44
  li        r31, 0
  addi      r30, r28, 0

.loc_0xA0:
  lwz       r4, 0x434(r30)
  addi      r3, r1, 0x1EC
  addi      r4, r4, 0x108
  bl        .loc_0xA20
  lbz       r3, 0x1EC(r1)
  addi      r31, r31, 0x1
  lbz       r0, 0x1ED(r1)
  cmpwi     r31, 0x3
  stb       r3, 0x1E4(r1)
  lbz       r3, 0x1EE(r1)
  stb       r0, 0x1E5(r1)
  lbz       r0, 0x1EF(r1)
  stb       r3, 0x1E6(r1)
  stb       r0, 0x1E7(r1)
  lwz       r4, 0x434(r30)
  lwz       r3, 0x3F8(r30)
  lbz       r4, 0xF0(r4)
  lwz       r0, 0x1E4(r1)
  stw       r0, 0x108(r3)
  lwz       r3, 0x3F8(r30)
  stb       r4, 0xF0(r3)
  lwz       r3, 0x41C(r30)
  lwz       r0, 0x1E4(r1)
  stw       r0, 0x108(r3)
  lwz       r3, 0x41C(r30)
  stb       r4, 0xF0(r3)
  lwz       r3, 0x428(r30)
  lwz       r0, 0x1E4(r1)
  stw       r0, 0x108(r3)
  lwz       r3, 0x428(r30)
  addi      r30, r30, 0x4
  stb       r4, 0xF0(r3)
  blt+      .loc_0xA0
  mr        r3, r28
  bl        -0x35F4
  lbz       r0, 0x284(r28)
  cmplwi    r0, 0
  beq-      .loc_0x1BC
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x280(r28)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x280(r28)
  lfs       f1, 0x280(r28)
  lfs       f0, -0x4F78(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x164
  li        r0, 0
  stb       r0, 0x284(r28)

.loc_0x164:
  lfs       f1, 0x280(r28)
  bl        -0xC89C
  lwz       r3, 0x2DC(r28)
  stfs      f1, 0xC0(r3)
  stfs      f1, 0xC4(r3)
  lfs       f0, -0x4F98(r2)
  stfs      f0, 0xC8(r3)
  lwz       r5, 0x2DC(r28)
  lha       r3, 0x18(r5)
  lha       r0, 0x1C(r5)
  lha       r4, 0x1A(r5)
  sub       r0, r0, r3
  lha       r3, 0x1E(r5)
  srawi     r0, r0, 0x1
  addze     r0, r0
  sub       r4, r3, r4
  extsh     r3, r0
  srawi     r0, r4, 0x1
  sth       r3, 0xB8(r5)
  addze     r0, r0
  extsh     r0, r0
  sth       r0, 0xBA(r5)

.loc_0x1BC:
  lbz       r0, 0x28C(r28)
  cmplwi    r0, 0
  beq-      .loc_0x224
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x288(r28)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x288(r28)
  lfs       f1, 0x288(r28)
  lfs       f0, -0x4F78(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x1F4
  li        r0, 0
  stb       r0, 0x28C(r28)

.loc_0x1F4:
  lfs       f1, 0x288(r28)
  bl        -0xC92C
  lwz       r4, 0x2B8(r28)
  li        r3, 0x140
  li        r0, 0x190
  stfs      f1, 0xC0(r4)
  stfs      f1, 0xC4(r4)
  lfs       f0, -0x4F98(r2)
  stfs      f0, 0xC8(r4)
  lwz       r4, 0x2B8(r28)
  sth       r3, 0xB8(r4)
  sth       r0, 0xBA(r4)

.loc_0x224:
  lfs       f2, 0x290(r28)
  lfs       f1, -0x4F9C(r2)
  fcmpo     cr0, f2, f1
  bge-      .loc_0x2F4
  lwz       r3, 0x2DEC(r13)
  lfs       f0, 0x28C(r3)
  fadds     f0, f2, f0
  stfs      f0, 0x290(r28)
  lfs       f0, 0x290(r28)
  lbz       r0, 0x28D(r28)
  fdivs     f2, f0, f1
  cmplwi    r0, 0
  beq-      .loc_0x2A4
  lwz       r3, 0x2D8(r28)
  lis       r0, 0x4330
  stfs      f2, 0xC0(r3)
  stfs      f2, 0xC4(r3)
  stfs      f2, 0xC8(r3)
  lwz       r3, 0x2D4(r28)
  lfd       f1, -0x4F90(r2)
  lbz       r4, 0xF7(r3)
  lwz       r3, 0x2D0(r28)
  stw       r4, 0x274(r1)
  stw       r0, 0x270(r1)
  lfd       f0, 0x270(r1)
  fsubs     f0, f0, f1
  fmuls     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x268(r1)
  lwz       r0, 0x26C(r1)
  stb       r0, 0xF0(r3)
  b         .loc_0x2F4

.loc_0x2A4:
  lfs       f0, -0x4F98(r2)
  lis       r0, 0x4330
  lwz       r3, 0x2D8(r28)
  fsubs     f2, f0, f2
  stfs      f2, 0xC0(r3)
  stfs      f2, 0xC4(r3)
  stfs      f2, 0xC8(r3)
  lwz       r3, 0x2D4(r28)
  lfd       f1, -0x4F90(r2)
  lbz       r4, 0xF7(r3)
  lwz       r3, 0x2D0(r28)
  stw       r4, 0x26C(r1)
  stw       r0, 0x268(r1)
  lfd       f0, 0x268(r1)
  fsubs     f0, f0, f1
  fmuls     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x270(r1)
  lwz       r0, 0x274(r1)
  stb       r0, 0xF0(r3)

.loc_0x2F4:
  lfs       f1, 0x54C(r28)
  lfs       f0, -0x4F98(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x314
  lwz       r3, 0x2DEC(r13)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x54C(r28)

.loc_0x314:
  addi      r3, r28, 0xA4
  bl        0x4F54C
  addi      r3, r28, 0xD4
  bl        0x4F544
  lwz       r0, 0x20(r28)
  cmpwi     r0, 0x1
  bne-      .loc_0x3A8
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x1184(r28)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x1184(r28)
  lfs       f2, 0x1184(r28)
  lfs       f1, -0x4F74(r2)
  fcmpo     cr0, f2, f1
  cror      2, 0x1, 0x2
  bne-      .loc_0x364
  li        r0, 0
  stw       r0, 0x20(r28)
  b         .loc_0x390

.loc_0x364:
  lfs       f0, -0x4F64(r2)
  fmuls     f0, f0, f2
  fdivs     f0, f0, f1
  fctiwz    f0, f0
  stfd      f0, 0x268(r1)
  lwz       r0, 0x26C(r1)
  stb       r0, 0x1180(r28)
  lbz       r0, 0x1180(r28)
  lwz       r3, 0x44C(r28)
  subfic    r0, r0, 0xFF
  stb       r0, 0xF0(r3)

.loc_0x390:
  lfs       f1, 0x1184(r28)
  lfs       f0, -0x4F60(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x4CC
  lwz       r3, 0x20(r28)
  b         .loc_0xA00

.loc_0x3A8:
  cmpwi     r0, 0x2
  bne-      .loc_0x48C
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x1184(r28)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x1184(r28)
  lfs       f0, 0x1184(r28)
  lfs       f2, -0x4F74(r2)
  fcmpo     cr0, f0, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x454
  lwz       r3, 0x0(r28)
  li        r4, 0x1
  bl        0x5E944
  lbz       r0, 0x1193(r28)
  cmplwi    r0, 0
  beq-      .loc_0x3FC
  li        r0, 0x6
  stw       r0, 0x20(r28)
  b         .loc_0x484

.loc_0x3FC:
  lha       r0, 0x134(r28)
  cmpwi     r0, 0x1
  beq-      .loc_0x430
  bge-      .loc_0x418
  cmpwi     r0, 0
  bge-      .loc_0x424
  b         .loc_0x448

.loc_0x418:
  cmpwi     r0, 0x3
  bge-      .loc_0x448
  b         .loc_0x43C

.loc_0x424:
  li        r0, 0x7
  stw       r0, 0x20(r28)
  b         .loc_0x484

.loc_0x430:
  li        r0, 0x8
  stw       r0, 0x20(r28)
  b         .loc_0x484

.loc_0x43C:
  li        r0, 0x9
  stw       r0, 0x20(r28)
  b         .loc_0x484

.loc_0x448:
  li        r0, 0xA
  stw       r0, 0x20(r28)
  b         .loc_0x484

.loc_0x454:
  fsubs     f0, f2, f0
  lfs       f1, -0x4F64(r2)
  fmuls     f0, f1, f0
  fdivs     f0, f0, f2
  fctiwz    f0, f0
  stfd      f0, 0x268(r1)
  lwz       r0, 0x26C(r1)
  stb       r0, 0x1180(r28)
  lbz       r0, 0x1180(r28)
  lwz       r3, 0x44C(r28)
  subfic    r0, r0, 0xFF
  stb       r0, 0xF0(r3)

.loc_0x484:
  lwz       r3, 0x20(r28)
  b         .loc_0xA00

.loc_0x48C:
  cmpwi     r0, 0x6
  blt-      .loc_0x4CC
  li        r0, -0x1
  stw       r0, 0x20(r28)
  lwz       r3, 0x14(r28)
  cmplwi    r3, 0
  beq-      .loc_0x4AC
  bl        0x157A4

.loc_0x4AC:
  lwz       r3, 0x18(r28)
  cmplwi    r3, 0
  beq-      .loc_0x4BC
  bl        0x15794

.loc_0x4BC:
  li        r0, -0x1
  stw       r0, 0x20(r28)
  lwz       r3, 0x20(r28)
  b         .loc_0xA00

.loc_0x4CC:
  mr        r3, r28
  bl        -0x14C0
  li        r31, 0
  rlwinm    r0,r31,2,0,29
  add       r30, r28, r0

.loc_0x4E0:
  lwz       r3, 0x29C(r30)
  bl        0x276BC
  lwz       r3, 0x2A8(r30)
  bl        0x276B4
  addi      r31, r31, 0x1
  cmpwi     r31, 0x3
  addi      r30, r30, 0x4
  blt+      .loc_0x4E0
  lwz       r3, 0x2B4(r28)
  bl        0x2769C
  lwz       r3, 0x2B8(r28)
  bl        0x27694
  lwz       r3, 0x2BC(r28)
  bl        0x2768C
  lwz       r3, 0x2C0(r28)
  bl        0x27684
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x150(r28)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x150(r28)
  lwz       r0, 0x20(r28)
  cmpwi     r0, 0x3
  bne-      .loc_0x998
  lfs       f1, 0x53C(r28)
  lis       r31, 0x4330
  lfs       f0, -0x4F5C(r2)
  fadds     f0, f1, f0
  stfs      f0, 0x53C(r28)
  lha       r0, 0x134(r28)
  lfd       f2, -0x4F80(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f0, 0x53C(r28)
  add       r3, r28, r0
  lwz       r0, 0x1DC(r3)
  xoris     r0, r0, 0x8000
  stw       r0, 0x26C(r1)
  stw       r31, 0x268(r1)
  lfd       f1, 0x268(r1)
  fsubs     f1, f1, f2
  fsubs     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x270(r1)
  lwz       r0, 0x274(r1)
  stw       r0, 0x1DC(r3)
  lha       r0, 0x134(r28)
  lfs       f0, 0x53C(r28)
  rlwinm    r0,r0,2,0,29
  add       r3, r28, r0
  lwz       r0, 0x1F4(r3)
  xoris     r0, r0, 0x8000
  stw       r0, 0x264(r1)
  stw       r31, 0x260(r1)
  lfd       f1, 0x260(r1)
  fsubs     f1, f1, f2
  fadds     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x258(r1)
  lwz       r0, 0x25C(r1)
  stw       r0, 0x1F4(r3)
  lha       r0, 0x134(r28)
  rlwinm    r0,r0,2,0,29
  add       r5, r28, r0
  lwz       r3, 0x3B0(r5)
  lwz       r4, 0x1D0(r5)
  lwz       r12, 0x0(r3)
  lwz       r5, 0x1DC(r5)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lha       r0, 0x134(r28)
  rlwinm    r0,r0,2,0,29
  add       r5, r28, r0
  lwz       r3, 0x3BC(r5)
  lwz       r4, 0x1E8(r5)
  lwz       r12, 0x0(r3)
  lwz       r5, 0x1F4(r5)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lha       r0, 0x134(r28)
  lfd       f2, -0x4F80(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f0, 0x53C(r28)
  add       r3, r28, r0
  lwz       r0, 0x224(r3)
  xoris     r0, r0, 0x8000
  stw       r0, 0x254(r1)
  stw       r31, 0x250(r1)
  lfd       f1, 0x250(r1)
  fsubs     f1, f1, f2
  fsubs     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x248(r1)
  lwz       r0, 0x24C(r1)
  stw       r0, 0x224(r3)
  lha       r0, 0x134(r28)
  lfs       f0, 0x53C(r28)
  rlwinm    r0,r0,2,0,29
  add       r3, r28, r0
  lwz       r0, 0x254(r3)
  xoris     r0, r0, 0x8000
  stw       r0, 0x244(r1)
  stw       r31, 0x240(r1)
  lfd       f1, 0x240(r1)
  fsubs     f1, f1, f2
  fadds     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x238(r1)
  lwz       r0, 0x23C(r1)
  stw       r0, 0x254(r3)
  lha       r0, 0x134(r28)
  rlwinm    r0,r0,2,0,29
  add       r5, r28, r0
  lwz       r3, 0x398(r5)
  lwz       r4, 0x218(r5)
  lwz       r12, 0x0(r3)
  lwz       r5, 0x224(r5)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lha       r0, 0x134(r28)
  rlwinm    r0,r0,2,0,29
  add       r5, r28, r0
  lwz       r3, 0x3A4(r5)
  lwz       r4, 0x248(r5)
  lwz       r12, 0x0(r3)
  lwz       r5, 0x254(r5)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lfs       f1, -0x4FA0(r2)
  stfs      f1, 0x1A0(r1)
  stfs      f1, 0x19C(r1)
  stfs      f1, 0x198(r1)
  lfd       f2, -0x4F80(r2)
  lha       r0, 0x134(r28)
  rlwinm    r0,r0,2,0,29
  add       r6, r28, r0
  lwz       r7, 0x3B0(r6)
  lwz       r4, 0x1D0(r6)
  lha       r3, 0x18(r7)
  lha       r0, 0x1C(r7)
  lha       r5, 0x1A(r7)
  sub       r0, r0, r3
  lha       r3, 0x1E(r7)
  srawi     r0, r0, 0x1
  addze     r0, r0
  add       r0, r4, r0
  xoris     r0, r0, 0x8000
  stw       r0, 0x234(r1)
  sub       r3, r3, r5
  stw       r31, 0x230(r1)
  lfd       f0, 0x230(r1)
  fsubs     f0, f0, f2
  stfs      f0, 0x198(r1)
  lwz       r0, 0x1DC(r6)
  add       r0, r0, r3
  subfic    r0, r0, 0x1E0
  xoris     r0, r0, 0x8000
  stw       r0, 0x22C(r1)
  stw       r31, 0x228(r1)
  lfd       f0, 0x228(r1)
  fsubs     f0, f0, f2
  stfs      f0, 0x19C(r1)
  lfs       f0, 0xD14(r13)
  stfs      f0, 0x1A0(r1)
  lwz       r4, 0xC(r28)
  lwz       r3, 0x198(r1)
  lwz       r0, 0x19C(r1)
  stw       r3, 0xC(r4)
  stw       r0, 0x10(r4)
  lwz       r0, 0x1A0(r1)
  stw       r0, 0x14(r4)
  stfs      f1, 0x17C(r1)
  stfs      f1, 0x178(r1)
  stfs      f1, 0x174(r1)
  lha       r0, 0x134(r28)
  rlwinm    r0,r0,2,0,29
  add       r6, r28, r0
  lwz       r7, 0x3BC(r6)
  lwz       r4, 0x1E8(r6)
  lha       r3, 0x18(r7)
  lha       r0, 0x1C(r7)
  lha       r5, 0x1A(r7)
  sub       r0, r0, r3
  lha       r3, 0x1E(r7)
  srawi     r0, r0, 0x1
  addze     r0, r0
  add       r0, r4, r0
  xoris     r0, r0, 0x8000
  stw       r0, 0x224(r1)
  sub       r3, r3, r5
  stw       r31, 0x220(r1)
  lfd       f0, 0x220(r1)
  fsubs     f0, f0, f2
  stfs      f0, 0x174(r1)
  lwz       r0, 0x1F4(r6)
  add       r0, r0, r3
  subfic    r0, r0, 0x244
  xoris     r0, r0, 0x8000
  stw       r0, 0x21C(r1)
  stw       r31, 0x218(r1)
  lfd       f0, 0x218(r1)
  fsubs     f0, f0, f2
  stfs      f0, 0x178(r1)
  lfs       f0, 0xD18(r13)
  stfs      f0, 0x17C(r1)
  lwz       r4, 0x10(r28)
  lwz       r3, 0x174(r1)
  lwz       r0, 0x178(r1)
  stw       r3, 0xC(r4)
  stw       r0, 0x10(r4)
  lwz       r0, 0x17C(r1)
  stw       r0, 0x14(r4)
  lha       r0, 0x134(r28)
  lfs       f0, -0x4F58(r2)
  rlwinm    r0,r0,2,0,29
  add       r4, r28, r0
  lwz       r3, 0x1DC(r4)
  lwz       r0, 0x164(r4)
  sub       r0, r0, r3
  xoris     r0, r0, 0x8000
  stw       r0, 0x214(r1)
  stw       r31, 0x210(r1)
  lfd       f1, 0x210(r1)
  fsub      f1, f1, f2
  fabs      f1, f1
  frsp      f1, f1
  fcmpo     cr0, f1, f0
  ble-      .loc_0x880
  fmr       f1, f0

.loc_0x880:
  lha       r0, 0x134(r28)
  rlwinm    r0,r0,2,0,29
  add       r3, r28, r0
  lwz       r3, 0x3B0(r3)
  lfs       f0, 0xC0(r3)
  addi      r4, r3, 0xC0
  stfs      f0, 0x1FC(r1)
  lfs       f0, 0xC4(r3)
  stfs      f0, 0x200(r1)
  lfs       f0, -0x4F58(r2)
  lfs       f2, 0xC8(r3)
  fdivs     f0, f1, f0
  lfs       f1, -0x4F98(r2)
  stfs      f2, 0x204(r1)
  fsubs     f0, f1, f0
  stfs      f0, 0x1FC(r1)
  stfs      f0, 0x200(r1)
  lwz       r3, 0x1FC(r1)
  lwz       r0, 0x200(r1)
  stw       r3, 0x0(r4)
  stw       r0, 0x4(r4)
  lwz       r0, 0x204(r1)
  stw       r0, 0x8(r4)
  lha       r0, 0x134(r28)
  lwz       r3, 0x1FC(r1)
  rlwinm    r4,r0,2,0,29
  lwz       r0, 0x200(r1)
  add       r4, r28, r4
  lwz       r4, 0x3BC(r4)
  stw       r3, 0xC0(r4)
  stw       r0, 0xC4(r4)
  lwz       r0, 0x204(r1)
  stw       r0, 0xC8(r4)
  lha       r0, 0x134(r28)
  lwz       r3, 0x1FC(r1)
  rlwinm    r4,r0,2,0,29
  lwz       r0, 0x200(r1)
  add       r4, r28, r4
  lwz       r4, 0x398(r4)
  stw       r3, 0xC0(r4)
  stw       r0, 0xC4(r4)
  lwz       r0, 0x204(r1)
  stw       r0, 0xC8(r4)
  lha       r0, 0x134(r28)
  lwz       r3, 0x1FC(r1)
  rlwinm    r4,r0,2,0,29
  lwz       r0, 0x200(r1)
  add       r4, r28, r4
  lwz       r4, 0x3A4(r4)
  stw       r3, 0xC0(r4)
  stw       r0, 0xC4(r4)
  lwz       r0, 0x204(r1)
  stw       r0, 0xC8(r4)
  lfs       f0, 0x150(r28)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x990
  li        r0, 0x2
  stw       r0, 0x20(r28)
  lfs       f0, -0x4FA0(r2)
  stfs      f0, 0x1184(r28)
  lwz       r3, 0xC(r28)
  lwz       r0, 0x80(r3)
  ori       r0, r0, 0x2
  stw       r0, 0x80(r3)
  lwz       r3, 0x10(r28)
  lwz       r0, 0x80(r3)
  ori       r0, r0, 0x2
  stw       r0, 0x80(r3)

.loc_0x990:
  lwz       r3, 0x20(r28)
  b         .loc_0xA00

.loc_0x998:
  lfs       f1, 0x150(r28)
  lfs       f0, -0x4F98(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x9FC
  lwz       r0, 0x24(r28)
  cmpwi     r0, 0x1
  beq-      .loc_0x9E0
  bge-      .loc_0x9C4
  cmpwi     r0, 0
  bge-      .loc_0x9D0
  b         .loc_0x9FC

.loc_0x9C4:
  cmpwi     r0, 0x3
  bge-      .loc_0x9FC
  b         .loc_0x9F0

.loc_0x9D0:
  addi      r3, r28, 0
  addi      r4, r29, 0
  bl        -0x1114
  b         .loc_0x9FC

.loc_0x9E0:
  addi      r3, r28, 0
  addi      r4, r29, 0
  bl        0xBCB8
  b         .loc_0x9FC

.loc_0x9F0:
  addi      r3, r28, 0
  addi      r4, r29, 0
  bl        0xC194

.loc_0x9FC:
  lwz       r3, 0x20(r28)

.loc_0xA00:
  lwz       r0, 0x28C(r1)
  lwz       r31, 0x284(r1)
  lwz       r30, 0x280(r1)
  lwz       r29, 0x27C(r1)
  lwz       r28, 0x278(r1)
  addi      r1, r1, 0x288
  mtlr      r0
  blr       

.loc_0xA20:
*/
}

/*
 * --INFO--
 * Address:	8018B9D0
 * Size:	000024
 */
void Colour::Colour(const Colour &)
{
/*
.loc_0x0:
  lbz       r0, 0x0(r4)
  stb       r0, 0x0(r3)
  lbz       r0, 0x1(r4)
  stb       r0, 0x1(r3)
  lbz       r0, 0x2(r4)
  stb       r0, 0x2(r3)
  lbz       r0, 0x3(r4)
  stb       r0, 0x3(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8018B9F4
 * Size:	00015C
 */
void zen::ogScrFileSelectMgr::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x108(r1)
  stw       r31, 0x104(r1)
  stw       r30, 0x100(r1)
  stw       r29, 0xFC(r1)
  addi      r29, r4, 0
  stw       r28, 0xF8(r1)
  mr        r28, r3
  lwz       r0, 0x20(r3)
  cmpwi     r0, -0x1
  beq-      .loc_0x13C
  lfs       f1, -0x4F54(r2)
  addi      r3, r1, 0x10
  lfs       f2, -0x4F98(r2)
  li        r4, 0
  lfs       f3, -0x4F50(r2)
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x2474C
  addi      r3, r1, 0x10
  bl        0x24854
  li        r30, 0
  rlwinm    r0,r30,2,0,29
  add       r31, r28, r0

.loc_0x68:
  lwz       r3, 0x29C(r31)
  addi      r6, r1, 0x10
  li        r4, 0
  li        r5, 0
  bl        0x27468
  lwz       r3, 0x2A8(r31)
  addi      r6, r1, 0x10
  li        r4, 0
  li        r5, 0
  bl        0x27454
  addi      r30, r30, 0x1
  cmpwi     r30, 0x3
  addi      r31, r31, 0x4
  blt+      .loc_0x68
  lwz       r3, 0x0(r28)
  mr        r4, r29
  bl        0x5E110
  mr        r3, r29
  lwz       r12, 0x3B4(r29)
  li        r4, 0
  lwz       r12, 0xB8(r12)
  mtlr      r12
  blrl      
  li        r3, 0
  li        r4, 0x7
  li        r5, 0
  bl        0x8830C
  lwz       r3, 0x2BC(r28)
  addi      r6, r1, 0x10
  li        r4, 0
  li        r5, 0
  bl        0x273FC
  lwz       r3, 0x2B4(r28)
  addi      r6, r1, 0x10
  li        r4, 0
  li        r5, 0
  bl        0x273E8
  lwz       r3, 0x2B8(r28)
  addi      r6, r1, 0x10
  li        r4, 0
  li        r5, 0
  bl        0x273D4
  lwz       r3, 0x2C0(r28)
  addi      r6, r1, 0x10
  li        r4, 0
  li        r5, 0
  bl        0x273C0
  lis       r3, 0x802E
  addi      r0, r3, 0x698
  lis       r3, 0x802E
  stw       r0, 0x10(r1)
  addi      r0, r3, 0x5D4
  stw       r0, 0x10(r1)

.loc_0x13C:
  lwz       r0, 0x10C(r1)
  lwz       r31, 0x104(r1)
  lwz       r30, 0x100(r1)
  lwz       r29, 0xFC(r1)
  lwz       r28, 0xF8(r1)
  addi      r1, r1, 0x108
  mtlr      r0
  blr
*/
}