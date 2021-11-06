#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void searchKanjiCode(unsigned short)
{
	// UNUSED FUNCTION
}

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
 * Address:	8018BB50
 * Size:	000048
 */
void zen::ogScrMessageMgr::SearchTopPage(int)
{
/*
.loc_0x0:
  lha       r5, 0x4F0(r3)
  li        r7, 0
  b         .loc_0x34

.loc_0xC:
  lwz       r6, 0x1C(r3)
  cmplwi    r6, 0
  beq-      .loc_0x2C
  lha       r0, 0x4(r6)
  cmpw      r0, r4
  bne-      .loc_0x2C
  mr        r3, r7
  blr       

.loc_0x2C:
  addi      r3, r3, 0x4
  addi      r7, r7, 0x1

.loc_0x34:
  extsh     r0, r7
  cmpw      r0, r5
  blt+      .loc_0xC
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void zen::ogScrMessageMgr::setMessagePage(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018BB98
 * Size:	00011C
 */
void zen::ogScrMessageMgr::resetPage()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  mr        r31, r3
  lbz       r0, 0x54F4(r3)
  cmplwi    r0, 0
  beq-      .loc_0x34
  lfs       f0, -0x4F48(r2)
  li        r0, 0
  stfs      f0, 0x4D4(r31)
  stb       r0, 0x54F4(r31)
  b         .loc_0x3C

.loc_0x34:
  lfs       f0, -0x4F44(r2)
  stfs      f0, 0x4D4(r31)

.loc_0x3C:
  li        r0, 0x5
  sth       r0, 0x54F2(r31)
  li        r3, 0
  li        r0, -0x1
  sth       r3, 0x4EA(r31)
  sth       r3, 0x4E8(r31)
  sth       r0, 0x4EC(r31)
  lwz       r4, 0x54FC(r31)
  cmplwi    r4, 0
  bne-      .loc_0x70
  sth       r3, 0x4E4(r31)
  sth       r3, 0x4E6(r31)
  b         .loc_0x84

.loc_0x70:
  lha       r0, 0x18(r4)
  sth       r0, 0x4E4(r31)
  lwz       r3, 0x54FC(r31)
  lha       r0, 0x1A(r3)
  sth       r0, 0x4E6(r31)

.loc_0x84:
  lwz       r3, 0xC(r31)
  lha       r4, 0x4E4(r31)
  lwz       r12, 0x0(r3)
  lha       r5, 0x4E6(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  li        r5, 0
  stb       r5, 0x4DD(r31)
  addi      r6, r31, 0
  addis     r3, r31, 0x1
  stb       r5, 0x4DC(r31)
  li        r8, 0
  addi      r4, r13, 0xD20
  b         .loc_0xFC

.loc_0xC0:
  lwz       r7, 0x54FC(r6)
  lhz       r0, 0x8(r7)
  cmpwi     r0, 0x13
  beq-      .loc_0xE0
  bge-      .loc_0xF4
  cmpwi     r0, 0x12
  bge-      .loc_0xE8
  b         .loc_0xF4

.loc_0xE0:
  stw       r4, 0x10C(r7)
  b         .loc_0xF4

.loc_0xE8:
  lbz       r0, 0xC(r7)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r7)

.loc_0xF4:
  addi      r6, r6, 0x4
  addi      r8, r8, 0x1

.loc_0xFC:
  lha       r0, -0x5A64(r3)
  cmpw      r8, r0
  blt+      .loc_0xC0
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018BCB4
 * Size:	000080
 */
void zen::ogScrMessageMgr::start(int)
{
/*
.loc_0x0:
  mflr      r0
  li        r6, 0x1
  stw       r0, 0x4(r1)
  li        r0, 0x3
  li        r5, 0
  stwu      r1, -0x20(r1)
  cmpwi     r4, 0
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  stw       r6, 0x4CC(r3)
  sth       r0, 0x4E2(r3)
  lfs       f0, -0x4F40(r2)
  stfs      f0, 0x4D8(r3)
  lwz       r3, 0x10(r3)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  stb       r6, 0x54F4(r31)
  blt-      .loc_0x6C
  mr        r3, r31
  bl        -0x1B4
  extsh     r0, r3
  sth       r0, 0x4D0(r31)
  mr        r3, r31
  bl        0x614
  mr        r3, r31
  bl        -0x184

.loc_0x6C:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018BD34
 * Size:	00005C
 */
void zen::ogScrMessageMgr::setPage(int)
{
/*
.loc_0x0:
  mflr      r0
  cmpwi     r4, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  bge-      .loc_0x20
  li        r4, 0

.loc_0x20:
  lha       r0, 0x4F0(r31)
  cmpw      r4, r0
  blt-      .loc_0x30
  li        r4, 0

.loc_0x30:
  extsh     r0, r4
  sth       r0, 0x4D0(r31)
  mr        r3, r31
  bl        0x5B8
  mr        r3, r31
  bl        -0x1E0
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018BD90
 * Size:	000058
 */
void zen::ogScrMessageMgr::nextPage()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lha       r3, 0x4D0(r3)
  lha       r0, 0x4F0(r31)
  addi      r3, r3, 0x1
  cmpw      r3, r0
  blt-      .loc_0x2C
  li        r3, 0

.loc_0x2C:
  extsh     r0, r3
  sth       r0, 0x4D0(r31)
  mr        r3, r31
  bl        0x560
  mr        r3, r31
  bl        -0x238
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018BDE8
 * Size:	000054
 */
void zen::ogScrMessageMgr::backPage()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lha       r0, 0x4D0(r3)
  subic.    r0, r0, 0x1
  bge-      .loc_0x28
  lha       r3, 0x4F0(r31)
  subi      r0, r3, 0x1

.loc_0x28:
  extsh     r0, r0
  sth       r0, 0x4D0(r31)
  mr        r3, r31
  bl        0x50C
  mr        r3, r31
  bl        -0x28C
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018BE3C
 * Size:	0001DC
 */
void zen::ogScrMessageMgr::makePageInfo(char ***)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stmw      r22, 0x18(r1)
  addi      r26, r3, 0
  addi      r31, r4, 0
  addi      r30, r26, 0
  li        r29, 0
  li        r28, 0

.loc_0x24:
  lwz       r0, 0x0(r31)
  li        r27, 0
  cmplwi    r0, 0
  beq-      .loc_0x1C4
  addi      r23, r30, 0
  extsh     r25, r28
  li        r24, 0

.loc_0x40:
  lwz       r3, 0x0(r31)
  addi      r4, r13, 0xD24
  lwzx      r22, r3, r24
  mr        r3, r22
  bl        0x8D338
  cmpwi     r3, 0
  beq-      .loc_0x8C
  li        r3, 0x8
  bl        -0x144E98
  stw       r3, 0x1C(r23)
  addi      r24, r24, 0x4
  addi      r27, r27, 0x1
  lwz       r3, 0x1C(r23)
  addi      r23, r23, 0x4
  addi      r30, r30, 0x4
  sth       r25, 0x4(r3)
  addi      r29, r29, 0x1
  stw       r22, 0x0(r3)
  b         .loc_0x40

.loc_0x8C:
  cmpwi     r27, 0x1
  li        r3, 0x1
  blt-      .loc_0x1B4
  cmpwi     r27, 0x8
  subi      r4, r27, 0x8
  ble-      .loc_0x180
  addi      r0, r4, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r4, 0x1
  mtctr     r0
  extsh     r0, r27
  blt-      .loc_0x180

.loc_0xBC:
  sub       r4, r29, r3
  rlwinm    r4,r4,2,0,29
  addi      r5, r4, 0x1C
  addi      r4, r3, 0x1
  lwzx      r5, r26, r5
  sub       r4, r29, r4
  rlwinm    r4,r4,2,0,29
  sth       r0, 0x6(r5)
  addi      r5, r4, 0x1C
  addi      r4, r3, 0x2
  lwzx      r5, r26, r5
  sub       r4, r29, r4
  rlwinm    r4,r4,2,0,29
  sth       r0, 0x6(r5)
  addi      r5, r4, 0x1C
  addi      r4, r3, 0x3
  lwzx      r5, r26, r5
  sub       r4, r29, r4
  rlwinm    r4,r4,2,0,29
  sth       r0, 0x6(r5)
  addi      r5, r4, 0x1C
  addi      r4, r3, 0x4
  lwzx      r5, r26, r5
  sub       r4, r29, r4
  rlwinm    r4,r4,2,0,29
  sth       r0, 0x6(r5)
  addi      r5, r4, 0x1C
  addi      r4, r3, 0x5
  lwzx      r5, r26, r5
  sub       r4, r29, r4
  rlwinm    r4,r4,2,0,29
  sth       r0, 0x6(r5)
  addi      r5, r4, 0x1C
  addi      r4, r3, 0x6
  lwzx      r5, r26, r5
  sub       r4, r29, r4
  rlwinm    r4,r4,2,0,29
  sth       r0, 0x6(r5)
  addi      r5, r4, 0x1C
  addi      r4, r3, 0x7
  lwzx      r5, r26, r5
  sub       r4, r29, r4
  rlwinm    r4,r4,2,0,29
  sth       r0, 0x6(r5)
  addi      r4, r4, 0x1C
  lwzx      r4, r26, r4
  addi      r3, r3, 0x8
  sth       r0, 0x6(r4)
  bdnz+     .loc_0xBC

.loc_0x180:
  addi      r0, r27, 0x1
  sub       r0, r0, r3
  cmpw      r3, r27
  mtctr     r0
  extsh     r5, r27
  bgt-      .loc_0x1B4

.loc_0x198:
  sub       r0, r29, r3
  rlwinm    r4,r0,2,0,29
  addi      r0, r4, 0x1C
  lwzx      r4, r26, r0
  addi      r3, r3, 0x1
  sth       r5, 0x6(r4)
  bdnz+     .loc_0x198

.loc_0x1B4:
  addi      r28, r28, 0x1
  cmpwi     r28, 0x99
  addi      r31, r31, 0x4
  blt+      .loc_0x24

.loc_0x1C4:
  extsh     r3, r29
  lmw       r22, 0x18(r1)
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018C018
 * Size:	00018C
 */
void zen::ogScrMessageMgr::cnvSingleMulti(char *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x530(r1)
  stmw      r27, 0x51C(r1)
  addi      r31, r4, 0
  addi      r30, r3, 0
  addi      r3, r31, 0
  li        r4, 0x1B
  bl        0x8D11C
  li        r28, 0
  mr.       r29, r3
  stb       r28, 0x14(r1)
  beq-      .loc_0x178
  sub.      r0, r29, r31
  mr        r27, r0
  ble-      .loc_0x58
  addi      r4, r31, 0
  addi      r5, r27, 0
  addi      r3, r1, 0x14
  bl        0x8D2B0
  addi      r3, r1, 0x14
  stbx      r28, r3, r27

.loc_0x58:
  lbzu      r0, 0x1(r29)
  cmplwi    r0, 0x44
  bne-      .loc_0x16C
  lbz       r3, 0x1(r29)
  subi      r0, r3, 0x30
  rlwinm    r0,r0,0,24,31
  mr.       r3, r0
  beq-      .loc_0x178
  cmplwi    r3, 0x5
  ble-      .loc_0x84
  b         .loc_0x178

.loc_0x84:
  bl        -0xBF80
  lbz       r0, 0x2(r29)
  cmplwi    r0, 0x5B
  bne-      .loc_0x178
  cmpwi     r3, 0x1
  bne-      .loc_0xF8
  addi      r3, r29, 0x3
  addi      r4, r13, 0xD28
  bl        0x8D02C
  addi      r28, r3, 0
  addi      r4, r29, 0x3
  sub.      r29, r28, r4
  ble-      .loc_0x178
  cmpwi     r29, 0xFF
  ble-      .loc_0xC4
  b         .loc_0x178

.loc_0xC4:
  addi      r5, r29, 0
  addi      r3, r1, 0x414
  bl        0x8D230
  addi      r4, r1, 0x414
  li        r0, 0
  stbx      r0, r4, r29
  addi      r3, r1, 0x14
  bl        0x8D1F0
  addi      r3, r28, 0x1
  addi      r4, r13, 0xD28
  bl        0x8CFE4
  addi      r4, r3, 0x1
  b         .loc_0x154

.loc_0xF8:
  addi      r3, r29, 0x3
  addi      r4, r13, 0xD2C
  bl        0x8CFD0
  addi      r28, r3, 0
  addi      r3, r28, 0x1
  addi      r4, r13, 0xD28
  bl        0x8CFC0
  addi      r29, r3, 0
  addi      r4, r28, 0x1
  sub.      r28, r29, r4
  ble-      .loc_0x178
  cmpwi     r28, 0xFF
  ble-      .loc_0x130
  b         .loc_0x178

.loc_0x130:
  addi      r5, r28, 0
  addi      r3, r1, 0x414
  bl        0x8D1C4
  addi      r4, r1, 0x414
  li        r0, 0
  stbx      r0, r4, r28
  addi      r3, r1, 0x14
  bl        0x8D184
  addi      r4, r29, 0x1

.loc_0x154:
  addi      r3, r1, 0x14
  bl        0x8D178
  addi      r3, r31, 0
  addi      r4, r1, 0x14
  bl        0x8D1DC
  mr        r29, r31

.loc_0x16C:
  addi      r3, r30, 0
  addi      r4, r29, 0
  bl        .loc_0x0

.loc_0x178:
  lmw       r27, 0x51C(r1)
  lwz       r0, 0x534(r1)
  addi      r1, r1, 0x530
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018C1A4
 * Size:	000184
 */
void zen::ogScrMessageMgr::cnvButtonIcon(char *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x548(r1)
  stw       r31, 0x544(r1)
  stw       r30, 0x540(r1)
  addi      r30, r3, 0
  stw       r29, 0x53C(r1)
  stw       r28, 0x538(r1)
  lbz       r0, 0x0(r4)
  cmplwi    r0, 0
  beq-      .loc_0x164
  addi      r3, r4, 0
  li        r4, 0x1B
  bl        0x8CF7C
  mr.       r31, r3
  beq-      .loc_0x164
  lbz       r29, 0x1(r31)
  cmplwi    r29, 0
  beq-      .loc_0x164
  addis     r3, r30, 0x1
  addi      r4, r29, 0
  subi      r3, r3, 0x5A62
  bl        0x8CF58
  cmplwi    r3, 0
  li        r28, 0x2
  beq-      .loc_0x130
  addis     r11, r30, 0x1
  subi      r0, r11, 0x5A62
  sub       r0, r3, r0
  cmpwi     r0, 0x8
  bge-      .loc_0x158
  rlwinm    r3,r0,1,0,30
  crclr     6, 0x6
  addis     r6, r3, 0x1
  subi      r6, r6, 0x5A56
  add       r6, r30, r6
  lbz       r3, 0x0(r6)
  addi      r5, r1, 0x528
  rlwinm    r0,r0,2,0,29
  stb       r3, 0x52C(r1)
  lis       r3, 0x802D
  addi      r4, r3, 0x5C60
  lbz       r6, 0x1(r6)
  li        r3, 0x1B
  li        r9, 0
  stb       r6, 0x52D(r1)
  add       r8, r11, r0
  mr        r6, r5
  stb       r3, 0x528(r1)
  addi      r7, r5, 0
  addi      r10, r5, 0
  stb       r9, 0x52E(r1)
  addi      r3, r1, 0x428
  stb       r9, 0x529(r1)
  addi      r9, r1, 0x52C
  lwz       r0, -0x5A34(r11)
  stw       r0, 0x8(r1)
  stw       r5, 0xC(r1)
  stw       r5, 0x10(r1)
  lwz       r8, -0x5A30(r8)
  bl        0x8A304
  addi      r3, r1, 0x428
  bl        0x8D170
  addi      r28, r3, 0
  crclr     6, 0x6
  addi      r3, r1, 0x28
  addi      r5, r1, 0x428
  addi      r6, r31, 0x2
  addi      r4, r13, 0xD30
  bl        0x8A2E0
  addi      r3, r31, 0
  crclr     6, 0x6
  addi      r5, r1, 0x28
  addi      r4, r13, 0xD38
  bl        0x8A2CC
  b         .loc_0x158

.loc_0x130:
  cmplwi    r29, 0x6D
  bne-      .loc_0x158
  lhz       r3, -0x4F3C(r2)
  lbz       r0, -0x4F3A(r2)
  sth       r3, 0x24(r1)
  stb       r0, 0x26(r1)
  lbz       r0, 0x24(r1)
  stb       r0, 0x0(r31)
  lbz       r0, 0x25(r1)
  stb       r0, 0x1(r31)

.loc_0x158:
  addi      r3, r30, 0
  add       r4, r31, r28
  bl        .loc_0x0

.loc_0x164:
  lwz       r0, 0x54C(r1)
  lwz       r31, 0x544(r1)
  lwz       r30, 0x540(r1)
  lwz       r29, 0x53C(r1)
  lwz       r28, 0x538(r1)
  addi      r1, r1, 0x548
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018C328
 * Size:	000234
 */
void zen::ogScrMessageMgr::setPageInfoSub()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stmw      r24, 0x40(r1)
  mr        r27, r3
  lha       r0, 0x4D0(r3)
  rlwinm    r0,r0,2,0,29
  add       r3, r27, r0
  lwz       r29, 0x1C(r3)
  cmplwi    r29, 0
  bne-      .loc_0x30
  b         .loc_0x220

.loc_0x30:
  lwz       r3, 0x2DEC(r13)
  li        r4, 0x6
  lwz       r30, 0x194(r3)
  bl        -0x14D344
  lbz       r0, 0x1D(r3)
  cmplwi    r0, 0
  beq-      .loc_0x68
  lwz       r3, 0x2DEC(r13)
  li        r4, 0x6
  bl        -0x14D314
  lwz       r3, 0x2DEC(r13)
  li        r4, 0x6
  li        r5, 0x2
  bl        -0x14D358

.loc_0x68:
  li        r3, 0xF8
  bl        -0x145390
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0xD4
  addi      r24, r28, 0
  addi      r3, r1, 0x28
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x2726C
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x28
  addi      r3, r24, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x245F0
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0xD4:
  stw       r28, 0x54F8(r27)
  li        r5, 0x1
  li        r6, 0x1
  lwz       r3, 0x54F8(r27)
  li        r7, 0x1
  lwz       r4, 0x0(r29)
  bl        0x267EC
  lwz       r3, 0x54F8(r27)
  bl        0x33388
  li        r0, 0x5
  sth       r0, 0x54F2(r27)
  addis     r31, r27, 0x1
  li        r0, 0
  sth       r0, -0x5A64(r31)
  li        r29, 0

.loc_0x110:
  addi      r5, r29, 0
  crclr     6, 0x6
  addi      r3, r1, 0x38
  addi      r4, r13, 0xD3C
  bl        0x8A150
  lwz       r3, 0x54F8(r27)
  li        r5, 0
  lbz       r0, 0x39(r1)
  lwz       r12, 0x0(r3)
  lbz       r4, 0x38(r1)
  rlwinm    r0,r0,16,0,15
  lwz       r12, 0x34(r12)
  rlwimi    r0,r4,24,0,7
  lbz       r6, 0x3A(r1)
  lbz       r4, 0x3B(r1)
  mtlr      r12
  rlwimi    r0,r6,8,16,23
  lha       r28, -0x5A64(r31)
  or        r4, r4, r0
  blrl      
  rlwinm    r0,r28,2,0,29
  add       r24, r27, r0
  addi      r26, r24, 0x54FC
  stw       r3, 0x54FC(r24)
  lwz       r4, 0x54FC(r24)
  cmplwi    r4, 0
  beq-      .loc_0x200
  lhz       r0, 0x8(r4)
  cmpwi     r0, 0x13
  beq-      .loc_0x198
  bge-      .loc_0x200
  cmpwi     r0, 0x12
  bge-      .loc_0x1EC
  b         .loc_0x200

.loc_0x198:
  rlwinm    r3,r28,10,0,21
  lwz       r5, 0x10C(r4)
  addi      r25, r3, 0x554C
  crclr     6, 0x6
  add       r25, r27, r25
  addi      r3, r25, 0
  addi      r4, r13, 0xD38
  bl        0x8A0BC
  addis     r24, r24, 0x1
  stw       r25, -0x5AB4(r24)
  mr        r3, r27
  lwzu      r4, -0x5AB4(r24)
  bl        -0x4D8
  mr        r3, r27
  lwz       r4, 0x0(r24)
  bl        -0x358
  lwz       r3, 0x0(r26)
  addi      r0, r13, 0xD20
  addi      r28, r28, 0x1
  stw       r0, 0x10C(r3)
  b         .loc_0x200

.loc_0x1EC:
  lbz       r0, 0xC(r4)
  li        r3, 0
  rlwimi    r0,r3,7,24,24
  stb       r0, 0xC(r4)
  addi      r28, r28, 0x1

.loc_0x200:
  addi      r29, r29, 0x1
  extsh     r0, r28
  cmpwi     r29, 0x14
  sth       r0, -0x5A64(r31)
  blt+      .loc_0x110
  lwz       r3, 0x2DEC(r13)
  mr        r4, r30
  bl        -0x14D4DC

.loc_0x220:
  lmw       r24, 0x40(r1)
  lwz       r0, 0x64(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void zen::ogScrMessageMgr::ReadAllScreen()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018C55C
 * Size:	000048
 */
void zen::ogScrMessageMgr::MakeAndSetPageInfo(char ***)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  bl        -0x734
  sth       r3, 0x4F0(r31)
  li        r0, 0
  addi      r3, r31, 0
  sth       r0, 0x4D0(r31)
  bl        -0x25C
  mr        r3, r31
  bl        -0x9F4
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018C5A4
 * Size:	0002A4
 */
zen::ogScrMessageMgr::ogScrMessageMgr(char *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x802D
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r5, 0x52E0
  stw       r30, 0x28(r1)
  addi      r30, r3, 0
  li        r3, 0xF8
  stw       r29, 0x24(r1)
  stw       r28, 0x20(r1)
  addi      r28, r4, 0
  bl        -0x1455D0
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x94
  addi      r3, r1, 0x14
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x27030
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x14
  addi      r3, r29, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x243B4
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r29)
  li        r0, 0
  stb       r0, 0xEC(r29)
  stw       r0, 0xF0(r29)
  stw       r0, 0xF4(r29)

.loc_0x94:
  stw       r29, 0x0(r30)
  addi      r4, r28, 0
  li        r5, 0x1
  lwz       r3, 0x0(r30)
  li        r6, 0x1
  li        r7, 0x1
  bl        0x265B0
  lwz       r3, 0x0(r30)
  bl        0x3314C
  li        r0, 0
  stb       r0, 0x4E0(r30)
  li        r3, 0x18
  bl        -0x145664
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0xD8
  bl        -0xC1E4

.loc_0xD8:
  stw       r29, 0x4(r30)
  li        r0, 0x5
  addi      r4, r31, 0x9B4
  sth       r0, 0x54F2(r30)
  li        r5, 0x1
  lwz       r3, 0x2DEC(r13)
  bl        -0x14D58C
  addi      r29, r3, 0
  li        r3, 0x10
  bl        -0x14569C
  stw       r3, 0x8(r30)
  addi      r4, r29, 0
  li        r5, 0x15
  lwz       r3, 0x8(r30)
  li        r6, 0x2A
  bl        -0x164A00
  li        r6, 0
  stw       r6, 0x54F8(r30)
  li        r0, -0x1
  lis       r3, 0x6375
  stw       r0, 0x4CC(r30)
  addi      r4, r3, 0x7273
  li        r5, 0x1
  stb       r6, 0x4DE(r30)
  stb       r6, 0x4DF(r30)
  sth       r6, 0x4D0(r30)
  sth       r6, 0x4EE(r30)
  lwz       r3, 0x0(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0xC(r30)
  lis       r3, 0x615F
  addi      r4, r3, 0x6274
  lwz       r3, 0x0(r30)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x10(r30)
  li        r3, 0x12C
  bl        -0x145724
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x1A0
  lwz       r4, 0xC(r30)
  lfs       f1, -0x4F38(r2)
  bl        -0xD51C

.loc_0x1A0:
  stw       r29, 0x14(r30)
  li        r3, 0x12C
  bl        -0x145748
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x1C4
  lwz       r4, 0x10(r30)
  lfs       f1, -0x4F34(r2)
  bl        -0xD540

.loc_0x1C4:
  stw       r29, 0x18(r30)
  lwz       r3, 0x14(r30)
  bl        -0xD0F4
  lwz       r3, 0x18(r30)
  bl        -0xD0FC
  lwz       r4, 0x10(r30)
  addis     r3, r30, 0x1
  li        r5, 0
  crclr     6, 0x6
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  li        r0, -0x1
  addi      r4, r31, 0x9C0
  stb       r5, 0x4DD(r30)
  subi      r3, r3, 0x5A62
  stb       r5, 0x4DC(r30)
  lfs       f0, -0x4F40(r2)
  stfs      f0, 0x4D4(r30)
  sth       r5, 0x4E8(r30)
  sth       r5, 0x4EA(r30)
  sth       r0, 0x4EC(r30)
  bl        0x89DD8
  addis     r3, r30, 0x1
  crclr     6, 0x6
  subi      r3, r3, 0x5A56
  addi      r4, r31, 0x9CC
  bl        0x89DC4
  addis     r6, r30, 0x1
  addi      r0, r13, 0xD44
  stw       r0, -0x5A34(r6)
  addi      r3, r13, 0xD4C
  addi      r0, r13, 0xD54
  stw       r3, -0x5A30(r6)
  addi      r5, r13, 0xD5C
  addi      r3, r13, 0xD64
  stw       r0, -0x5A2C(r6)
  addi      r0, r13, 0xD6C
  li        r4, 0
  stw       r5, -0x5A28(r6)
  stw       r3, -0x5A24(r6)
  stw       r3, -0x5A20(r6)
  stw       r0, -0x5A1C(r6)
  stw       r3, -0x5A18(r6)
  stw       r3, -0x5A14(r6)
  lwz       r3, 0x0(r30)
  bl        0x330B8
  mr        r3, r30
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  lwz       r29, 0x24(r1)
  lwz       r28, 0x20(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void zen::ogScrMessageMgr::setScreenAlpha(unsigned char)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018C848
 * Size:	000170
 */
void zen::ogScrMessageMgr::dispAll()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, -0x1
  stwu      r1, -0x48(r1)
  stmw      r26, 0x30(r1)
  addi      r31, r3, 0
  li        r27, 0
  addi      r29, r31, 0
  addis     r30, r31, 0x1
  sth       r0, 0x4EC(r3)
  rlwinm    r0,r27,10,0,21
  add       r28, r31, r0
  b         .loc_0xD8

.loc_0x34:
  lwz       r3, 0x54FC(r29)
  lhz       r0, 0x8(r3)
  cmpwi     r0, 0x13
  beq-      .loc_0xA0
  bge-      .loc_0xCC
  cmpwi     r0, 0x12
  bge-      .loc_0x54
  b         .loc_0xCC

.loc_0x54:
  mr        r26, r3
  lbz       r0, 0xC(r3)
  li        r3, 0x1
  rlwimi    r0,r3,7,24,24
  stb       r0, 0xC(r26)
  addi      r3, r26, 0
  li        r4, 0xFF
  bl        0x33020
  li        r3, 0xFF
  stb       r3, 0x108(r26)
  li        r0, 0
  stb       r3, 0x109(r26)
  stb       r3, 0x10A(r26)
  stb       r3, 0x10B(r26)
  stb       r0, 0x10C(r26)
  stb       r0, 0x10D(r26)
  stb       r0, 0x10E(r26)
  stb       r0, 0x10F(r26)
  b         .loc_0xCC

.loc_0xA0:
  addis     r3, r29, 0x1
  lwz       r4, -0x5AB4(r3)
  addi      r3, r28, 0x4F2
  bl        0x8CA64
  addi      r3, r28, 0x4F2
  bl        -0xC784
  lwz       r3, 0x54FC(r29)
  addi      r4, r28, 0x4F2
  extsh     r0, r27
  stw       r4, 0x10C(r3)
  sth       r0, 0x4EC(r31)

.loc_0xCC:
  addi      r29, r29, 0x4
  addi      r28, r28, 0x400
  addi      r27, r27, 0x1

.loc_0xD8:
  lha       r3, -0x5A64(r30)
  cmpw      r27, r3
  blt+      .loc_0x34
  subi      r0, r3, 0x1
  sth       r0, 0x4EA(r31)
  li        r0, 0x1
  stb       r0, 0x4DD(r31)
  stb       r0, 0x4DC(r31)
  lfs       f0, -0x4F30(r2)
  stfs      f0, 0x4D4(r31)
  lbz       r0, 0x4DE(r31)
  cmplwi    r0, 0
  beq-      .loc_0x120
  lwz       r3, 0xC(r31)
  li        r4, 0
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)

.loc_0x120:
  lha       r3, 0x4EC(r31)
  extsh.    r0, r3
  blt-      .loc_0x15C
  rlwinm    r0,r3,2,0,29
  add       r3, r31, r0
  lwz       r4, 0x54FC(r3)
  lha       r3, 0x18(r4)
  lha       r0, 0x114(r4)
  add       r0, r3, r0
  sth       r0, 0x4E4(r31)
  lha       r3, 0x116(r4)
  lha       r4, 0x1A(r4)
  subi      r0, r3, 0x18
  add       r0, r4, r0
  sth       r0, 0x4E6(r31)

.loc_0x15C:
  lmw       r26, 0x30(r1)
  lwz       r0, 0x4C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018C9B8
 * Size:	000014
 */
void zen::ogScrMessageMgr::fadeOut()
{
/*
.loc_0x0:
  lfs       f0, -0x4F40(r2)
  li        r0, 0x3
  stfs      f0, 0x4D8(r3)
  stw       r0, 0x4CC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8018C9CC
 * Size:	00057C
 */
void zen::ogScrMessageMgr::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x80(r1)
  stw       r31, 0x7C(r1)
  stw       r30, 0x78(r1)
  addi      r30, r4, 0
  stw       r29, 0x74(r1)
  mr        r29, r3
  lwz       r3, 0x4CC(r3)
  cmpwi     r3, -0x1
  bne-      .loc_0x30
  b         .loc_0x560

.loc_0x30:
  cmpwi     r3, 0x4
  bne-      .loc_0x48
  li        r0, -0x1
  stw       r0, 0x4CC(r29)
  lwz       r3, 0x4CC(r29)
  b         .loc_0x560

.loc_0x48:
  cmpwi     r3, 0x1
  bne-      .loc_0x80
  lha       r3, 0x4E2(r29)
  subi      r0, r3, 0x1
  sth       r0, 0x4E2(r29)
  lha       r0, 0x4E2(r29)
  cmpwi     r0, 0
  bgt-      .loc_0x78
  lfs       f0, -0x4F40(r2)
  li        r0, 0x2
  stfs      f0, 0x4D8(r29)
  stw       r0, 0x4CC(r29)

.loc_0x78:
  lwz       r3, 0x4CC(r29)
  b         .loc_0x560

.loc_0x80:
  lha       r0, 0x4D0(r29)
  rlwinm    r0,r0,2,0,29
  add       r4, r29, r0
  lwz       r31, 0x1C(r4)
  cmplwi    r31, 0
  bne-      .loc_0x9C
  b         .loc_0x560

.loc_0x9C:
  lwz       r3, 0x0(r29)
  bl        0x260E4
  lbz       r0, 0x4DE(r29)
  cmplwi    r0, 0
  bne-      .loc_0xB8
  lwz       r3, 0x14(r29)
  bl        -0xD338

.loc_0xB8:
  lwz       r3, 0x54F8(r29)
  bl        0x260C8
  lwz       r0, 0x4CC(r29)
  cmpwi     r0, 0x2
  bne-      .loc_0x138
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x4D8(r29)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x4D8(r29)
  lfs       f2, 0x4D8(r29)
  lfs       f1, -0x4F2C(r2)
  fcmpo     cr0, f2, f1
  cror      2, 0x1, 0x2
  bne-      .loc_0x100
  li        r0, 0
  stw       r0, 0x4CC(r29)
  b         .loc_0x130

.loc_0x100:
  lfs       f0, -0x4F28(r2)
  lwz       r3, 0x54F8(r29)
  fmuls     f0, f0, f2
  fdivs     f0, f0, f1
  fctiwz    f0, f0
  stfd      f0, 0x68(r1)
  lwz       r30, 0x6C(r1)
  mr        r4, r30
  bl        0x32DEC
  lwz       r3, 0x0(r29)
  mr        r4, r30
  bl        0x32DE0

.loc_0x130:
  lwz       r3, 0x4CC(r29)
  b         .loc_0x560

.loc_0x138:
  cmpwi     r0, 0x3
  bne-      .loc_0x1B0
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x4D8(r29)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x4D8(r29)
  lfs       f0, 0x4D8(r29)
  lfs       f2, -0x4F2C(r2)
  fcmpo     cr0, f0, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x174
  li        r0, 0x4
  stw       r0, 0x4CC(r29)
  b         .loc_0x1A8

.loc_0x174:
  fsubs     f0, f2, f0
  lfs       f1, -0x4F28(r2)
  lwz       r3, 0x54F8(r29)
  fmuls     f0, f1, f0
  fdivs     f0, f0, f2
  fctiwz    f0, f0
  stfd      f0, 0x68(r1)
  lwz       r30, 0x6C(r1)
  mr        r4, r30
  bl        0x32D74
  lwz       r3, 0x0(r29)
  mr        r4, r30
  bl        0x32D68

.loc_0x1A8:
  lwz       r3, 0x4CC(r29)
  b         .loc_0x560

.loc_0x1B0:
  lbz       r0, 0x4DC(r29)
  cmplwi    r0, 0
  bne-      .loc_0x210
  lbz       r0, 0x4DD(r29)
  cmplwi    r0, 0
  beq-      .loc_0x210
  lfs       f0, -0x4F24(r2)
  li        r0, 0
  addis     r3, r29, 0x1
  stfs      f0, 0x4D4(r29)
  sth       r0, 0x4E8(r29)
  lha       r4, 0x4EA(r29)
  addi      r0, r4, 0x1
  sth       r0, 0x4EA(r29)
  lha       r0, 0x4EA(r29)
  lha       r3, -0x5A64(r3)
  cmpw      r0, r3
  blt-      .loc_0x208
  subi      r0, r3, 0x1
  sth       r0, 0x4EA(r29)
  li        r0, 0x1
  stb       r0, 0x4DC(r29)

.loc_0x208:
  li        r0, 0
  stb       r0, 0x4DD(r29)

.loc_0x210:
  lha       r3, 0x4EC(r29)
  extsh.    r0, r3
  blt-      .loc_0x268
  rlwinm    r0,r3,2,0,29
  add       r3, r29, r0
  lwz       r4, 0x54FC(r3)
  lha       r3, 0x18(r4)
  lha       r0, 0x114(r4)
  add       r0, r3, r0
  sth       r0, 0x4E4(r29)
  lha       r3, 0x116(r4)
  lha       r4, 0x1A(r4)
  subi      r0, r3, 0x18
  add       r0, r4, r0
  sth       r0, 0x4E6(r29)
  lwz       r3, 0xC(r29)
  lha       r4, 0x4E4(r29)
  lwz       r12, 0x0(r3)
  lha       r5, 0x4E6(r29)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      

.loc_0x268:
  lbz       r3, 0x4DC(r29)
  cmplwi    r3, 0
  beq-      .loc_0x33C
  lha       r0, 0x6(r31)
  cmpwi     r0, 0x1
  bgt-      .loc_0x28C
  lbz       r0, 0x4E0(r29)
  cmplwi    r0, 0
  beq-      .loc_0x2A8

.loc_0x28C:
  lwz       r3, 0x10(r29)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x18(r29)
  bl        -0xD528

.loc_0x2A8:
  lbz       r0, 0x4DE(r29)
  cmplwi    r0, 0
  bne-      .loc_0x334
  lwz       r0, 0x28(r30)
  rlwinm.   r0,r0,0,18,19
  beq-      .loc_0x334
  lha       r3, 0x4EE(r29)
  addi      r0, r3, 0x1
  sth       r0, 0x4EE(r29)
  lha       r3, 0x4EE(r29)
  lha       r0, 0x6(r31)
  cmpw      r3, r0
  blt-      .loc_0x304
  li        r0, 0
  sth       r0, 0x4EE(r29)
  li        r0, 0x3
  li        r3, 0x127
  lfs       f0, -0x4F40(r2)
  stfs      f0, 0x4D8(r29)
  stw       r0, 0x4CC(r29)
  bl        -0xE7950
  lwz       r3, 0x4CC(r29)
  b         .loc_0x560

.loc_0x304:
  lha       r3, 0x4D0(r29)
  lha       r0, 0x4F0(r29)
  addi      r3, r3, 0x1
  cmpw      r3, r0
  blt-      .loc_0x31C
  li        r3, 0

.loc_0x31C:
  extsh     r0, r3
  sth       r0, 0x4D0(r29)
  mr        r3, r29
  bl        -0x9CC
  mr        r3, r29
  bl        -0x1164

.loc_0x334:
  lwz       r3, 0x4CC(r29)
  b         .loc_0x560

.loc_0x33C:
  lbz       r0, 0x4DE(r29)
  cmplwi    r0, 0
  bne-      .loc_0x364
  lwz       r0, 0x28(r30)
  rlwinm.   r0,r0,0,18,18
  beq-      .loc_0x364
  mr        r3, r29
  bl        -0x4DC
  lwz       r3, 0x4CC(r29)
  b         .loc_0x560

.loc_0x364:
  cmplwi    r3, 0
  bne-      .loc_0x540
  addis     r3, r29, 0x1
  lha       r4, 0x4EA(r29)
  lha       r0, -0x5A64(r3)
  cmpw      r4, r0
  bge-      .loc_0x540
  lwz       r0, 0x20(r30)
  lfs       f2, -0x4F34(r2)
  rlwinm.   r0,r0,0,19,19
  beq-      .loc_0x394
  lfs       f2, -0x4F20(r2)

.loc_0x394:
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x4D4(r29)
  lfs       f0, 0x28C(r3)
  fmuls     f0, f2, f0
  fadds     f0, f1, f0
  stfs      f0, 0x4D4(r29)
  lha       r5, 0x4EA(r29)
  rlwinm    r0,r5,2,0,29
  add       r3, r29, r0
  lwz       r4, 0x54FC(r3)
  lhz       r0, 0x8(r4)
  cmpwi     r0, 0x13
  beq-      .loc_0x448
  bge-      .loc_0x540
  cmpwi     r0, 0x12
  bge-      .loc_0x3D8
  b         .loc_0x540

.loc_0x3D8:
  lbz       r0, 0xC(r4)
  li        r3, 0x1
  rlwimi    r0,r3,7,24,24
  stb       r0, 0xC(r4)
  mr        r3, r4
  lfs       f1, 0x4D4(r29)
  lfs       f0, -0x4F34(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x428
  lfs       f0, -0x4F40(r2)
  li        r4, 0
  fcmpo     cr0, f1, f0
  ble-      .loc_0x420
  lfs       f0, -0x4F28(r2)
  fmuls     f0, f0, f1
  fctiwz    f0, f0
  stfd      f0, 0x68(r1)
  lwz       r4, 0x6C(r1)

.loc_0x420:
  bl        0x32AEC
  b         .loc_0x540

.loc_0x428:
  lfs       f0, -0x4F1C(r2)
  li        r0, 0
  stfs      f0, 0x4D4(r29)
  sth       r0, 0x4E8(r29)
  lha       r3, 0x4EA(r29)
  addi      r0, r3, 0x1
  sth       r0, 0x4EA(r29)
  b         .loc_0x540

.loc_0x448:
  lfs       f1, 0x4D4(r29)
  lfs       f0, -0x4F18(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x52C
  sth       r5, 0x4EC(r29)
  addis     r4, r29, 0x1
  addi      r5, r29, 0x4E8
  lfs       f0, -0x4F40(r2)
  addi      r6, r1, 0x60
  stfs      f0, 0x4D4(r29)
  lha       r0, 0x4EA(r29)
  lwz       r3, 0x4(r29)
  rlwinm    r0,r0,2,0,29
  add       r4, r4, r0
  lwz       r4, -0x5AB4(r4)
  bl        -0xC860
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x49C
  li        r0, 0x1
  stb       r0, 0x4DD(r29)

.loc_0x49C:
  lfs       f1, 0x60(r1)
  lfs       f0, -0x4F40(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x4B4
  fneg      f0, f1
  stfs      f0, 0x4D4(r29)

.loc_0x4B4:
  lha       r4, 0x4EA(r29)
  addis     r3, r29, 0x1
  lha       r5, 0x4E8(r29)
  rlwinm    r0,r4,2,0,29
  rlwinm    r6,r4,10,0,21
  add       r4, r3, r0
  addi      r3, r6, 0x4F2
  lwz       r4, -0x5AB4(r4)
  add       r3, r29, r3
  bl        0x8C470
  lha       r3, 0x4EA(r29)
  li        r4, 0
  lha       r0, 0x4E8(r29)
  rlwinm    r3,r3,10,0,21
  add       r3, r29, r3
  add       r3, r3, r0
  stb       r4, 0x4F2(r3)
  lha       r0, 0x4EA(r29)
  rlwinm    r3,r0,10,0,21
  addi      r3, r3, 0x4F2
  add       r3, r29, r3
  bl        -0xCD5C
  lha       r3, 0x4EA(r29)
  rlwinm    r0,r3,2,0,29
  rlwinm    r4,r3,10,0,21
  add       r3, r29, r0
  addi      r0, r4, 0x4F2
  lwz       r3, 0x54FC(r3)
  add       r0, r29, r0
  stw       r0, 0x10C(r3)

.loc_0x52C:
  lwz       r3, 0x10(r29)
  li        r4, 0
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)

.loc_0x540:
  addis     r3, r29, 0x1
  lha       r4, 0x4EA(r29)
  lha       r0, -0x5A64(r3)
  cmpw      r4, r0
  blt-      .loc_0x55C
  li        r0, 0x1
  stb       r0, 0x4DC(r29)

.loc_0x55C:
  lwz       r3, 0x4CC(r29)

.loc_0x560:
  lwz       r0, 0x84(r1)
  lwz       r31, 0x7C(r1)
  lwz       r30, 0x78(r1)
  lwz       r29, 0x74(r1)
  addi      r1, r1, 0x80
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018CF48
 * Size:	000104
 */
void zen::ogScrMessageMgr::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x108(r1)
  stw       r31, 0x104(r1)
  mr        r31, r3
  lwz       r0, 0x4CC(r3)
  cmpwi     r0, -0x1
  beq-      .loc_0xF0
  cmpwi     r0, 0x1
  beq-      .loc_0xF0
  lfs       f2, -0x4F34(r2)
  addi      r4, r1, 0x10
  lwz       r0, -0x4F14(r2)
  li        r3, 0
  fmr       f4, f2
  stw       r0, 0x10(r1)
  lfs       f1, -0x4F40(r2)
  lfs       f3, -0x4F10(r2)
  bl        0x86A08
  li        r3, 0
  li        r4, 0
  li        r5, 0
  bl        0x86BAC
  lfs       f1, -0x4F0C(r2)
  addi      r3, r1, 0x14
  lfs       f2, -0x4F34(r2)
  li        r4, 0
  lfs       f3, -0x4F08(r2)
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x231CC
  addi      r3, r1, 0x14
  bl        0x232D4
  lwz       r3, 0x0(r31)
  addi      r6, r1, 0x14
  li        r4, 0
  li        r5, 0
  bl        0x25EF4
  lha       r3, 0x54F2(r31)
  cmpwi     r3, 0
  ble-      .loc_0xBC
  subi      r0, r3, 0x1
  sth       r0, 0x54F2(r31)
  li        r0, 0
  stb       r0, 0x4DF(r31)
  b         .loc_0xD8

.loc_0xBC:
  lwz       r3, 0x54F8(r31)
  addi      r6, r1, 0x14
  li        r4, 0
  li        r5, 0
  bl        0x25EC0
  li        r0, 0x1
  stb       r0, 0x4DF(r31)

.loc_0xD8:
  lis       r3, 0x802E
  addi      r0, r3, 0x698
  lis       r3, 0x802E
  stw       r0, 0x14(r1)
  addi      r0, r3, 0x5D4
  stw       r0, 0x14(r1)

.loc_0xF0:
  lwz       r0, 0x10C(r1)
  lwz       r31, 0x104(r1)
  addi      r1, r1, 0x108
  mtlr      r0
  blr
*/
}
