#include "types.h"



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
 * Address:	8018F1F4
 * Size:	000150
 */
zen::ogScrDiaryMgr::ogScrDiaryMgr()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802D
  stw       r0, 0x4(r1)
  addi      r4, r4, 0x5DE8
  li        r5, 0x1
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r3, 0
  stw       r30, 0x28(r1)
  stw       r29, 0x24(r1)
  lwz       r3, 0x2DEC(r13)
  bl        -0x150118
  addi      r30, r3, 0
  li        r3, 0x10
  bl        -0x148228
  stw       r3, 0x14(r31)
  addi      r4, r30, 0
  li        r5, 0x15
  lwz       r3, 0x14(r31)
  li        r6, 0x2A
  bl        -0x16758C
  li        r3, 0x6C
  bl        -0x148248
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x70
  li        r4, 0
  bl        0x310B0

.loc_0x70:
  stw       r30, 0x10(r31)
  lis       r3, 0x1
  subi      r3, r3, 0x5A10
  lfs       f0, -0x4ED8(r2)
  stfs      f0, 0x31B0(r13)
  bl        -0x148274
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xA0
  lis       r4, 0x802D
  addi      r4, r4, 0x5DF4
  bl        -0x2CEC

.loc_0xA0:
  stw       r30, 0x4(r31)
  addi      r4, r13, 0xD88
  lwz       r3, 0x4(r31)
  bl        -0x2D44
  lwz       r4, 0x4(r31)
  li        r0, 0x1
  lis       r3, 0x6361
  stb       r0, 0x4DE(r4)
  li        r30, 0
  addi      r4, r3, 0x7075
  lwz       r3, 0x4(r31)
  li        r5, 0x1
  stb       r30, 0x4E0(r3)
  lwz       r3, 0x4(r31)
  lwz       r29, 0x0(r3)
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x18(r31)
  addi      r3, r29, 0
  lis       r4, 0x6261
  lwz       r12, 0x0(r29)
  addi      r4, r4, 0x7365
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lbz       r4, 0xC(r3)
  rlwimi    r4,r30,7,24,24
  li        r0, -0x1
  stb       r4, 0xC(r3)
  mr        r3, r31
  stw       r30, 0x8(r31)
  stw       r30, 0xC(r31)
  stw       r0, 0x0(r31)
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  lwz       r29, 0x24(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018F344
 * Size:	0000FC
 */
void zen::ogScrDiaryMgr::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  mr        r31, r3
  stw       r30, 0x28(r1)
  stw       r29, 0x24(r1)
  addi      r29, r4, 0
  lwz       r3, 0x0(r3)
  cmpwi     r3, -0x1
  bne-      .loc_0x30
  b         .loc_0xE0

.loc_0x30:
  lwz       r3, 0x4(r31)
  mr        r4, r29
  bl        -0x29B0
  lwz       r4, 0x10(r31)
  mr        r30, r3
  stw       r29, 0x0(r4)
  lwz       r3, 0x10(r31)
  bl        0x31014
  lwz       r0, 0x2F6C(r13)
  cmplwi    r0, 0
  bne-      .loc_0xDC
  lwz       r3, 0x4(r31)
  lbz       r0, 0x4DF(r3)
  cmplwi    r0, 0
  beq-      .loc_0xDC
  cmpwi     r30, 0
  bne-      .loc_0xDC
  lwz       r4, 0x10(r31)
  lis       r3, 0x40
  addi      r0, r3, 0x100
  lwz       r4, 0x4(r4)
  and.      r0, r4, r0
  beq-      .loc_0x98
  mr        r3, r31
  bl        0x5DC
  b         .loc_0xDC

.loc_0x98:
  lis       r3, 0x10
  addi      r0, r3, 0x200
  and.      r0, r4, r0
  beq-      .loc_0xB4
  mr        r3, r31
  bl        0x4F8
  b         .loc_0xDC

.loc_0xB4:
  lwz       r3, 0x28(r29)
  rlwinm.   r0,r3,0,16,16
  beq-      .loc_0xCC
  mr        r3, r31
  bl        0x444
  b         .loc_0xDC

.loc_0xCC:
  rlwinm.   r0,r3,0,7,7
  beq-      .loc_0xDC
  mr        r3, r31
  bl        0x634

.loc_0xDC:
  mr        r3, r30

.loc_0xE0:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  lwz       r29, 0x24(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018F440
 * Size:	000178
 */
void zen::ogScrDiaryMgr::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x188(r1)
  stw       r31, 0x184(r1)
  addi      r31, r4, 0
  stw       r30, 0x180(r1)
  mr        r30, r3
  stw       r29, 0x17C(r1)
  lwz       r0, 0x0(r3)
  cmpwi     r0, -0x1
  beq-      .loc_0x15C
  lwz       r3, 0x4(r30)
  mr        r4, r31
  bl        -0x252C
  lwz       r0, 0x2F6C(r13)
  cmplwi    r0, 0
  bne-      .loc_0x15C
  lwz       r7, 0x310(r31)
  li        r0, 0
  lwz       r6, 0x30C(r31)
  addi      r5, r1, 0x24
  addi      r3, r31, 0
  stw       r0, 0x24(r1)
  addi      r4, r1, 0x134
  stw       r0, 0x28(r1)
  stw       r6, 0x2C(r1)
  stw       r7, 0x30(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  li        r29, 0xFF
  stb       r29, 0x20(r1)
  addi      r4, r1, 0x20
  addi      r3, r31, 0
  stb       r29, 0x21(r1)
  li        r5, 0x1
  stb       r29, 0x22(r1)
  stb       r29, 0x23(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  stb       r29, 0x1C(r1)
  li        r0, 0x96
  addi      r4, r1, 0x1C
  stb       r29, 0x1D(r1)
  mr        r3, r31
  stb       r0, 0x1E(r1)
  stb       r29, 0x1F(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xAC(r12)
  mtlr      r12
  blrl      
  lwz       r5, 0x4(r30)
  lis       r3, 0x802D
  addi      r4, r3, 0x5E0C
  crclr     6, 0x6
  addis     r3, r5, 0x1
  lha       r5, -0x5A64(r3)
  addi      r3, r1, 0x34
  bl        0x87064
  lwz       r6, 0x4(r30)
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  crclr     6, 0x6
  lha       r0, 0x4D0(r6)
  lwz       r12, 0xEC(r12)
  li        r5, 0x1E
  rlwinm    r0,r0,2,0,29
  lwz       r4, 0x14(r30)
  add       r6, r6, r0
  lwz       r7, 0x1C(r6)
  mtlr      r12
  li        r6, 0x14
  lwz       r7, 0x0(r7)
  blrl      
  mr        r3, r31
  lwz       r4, 0x14(r30)
  lwz       r12, 0x3B4(r31)
  addi      r7, r1, 0x34
  crclr     6, 0x6
  li        r5, 0x1E
  lwz       r12, 0xEC(r12)
  li        r6, 0x28
  mtlr      r12
  blrl      

.loc_0x15C:
  lwz       r0, 0x18C(r1)
  lwz       r31, 0x184(r1)
  lwz       r30, 0x180(r1)
  lwz       r29, 0x17C(r1)
  addi      r1, r1, 0x188
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018F5B8
 * Size:	000294
 */
void zen::ogScrDiaryMgr::start(short, short)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  addi      r31, r4, 0x22E0
  stw       r30, 0x30(r1)
  addi      r30, r5, 0
  stw       r29, 0x2C(r1)
  addi      r29, r3, 0
  stw       r28, 0x28(r1)
  lwz       r6, 0x2F6C(r13)
  cmplwi    r6, 0
  beq-      .loc_0x1DC
  addi      r3, r6, 0x70
  extsh     r4, r30
  addi      r5, r1, 0x20
  bl        -0x10BB88
  lwz       r0, 0x20(r1)
  cmpwi     r0, 0
  beq-      .loc_0x274
  cmpwi     r0, 0x1
  bne-      .loc_0x74
  lwz       r4, 0x18(r29)
  li        r5, 0
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  b         .loc_0x88

.loc_0x74:
  lwz       r4, 0x18(r29)
  li        r5, 0x1
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)

.loc_0x88:
  lwz       r0, 0x20(r1)
  cmpwi     r0, 0xA
  blt-      .loc_0x9C
  li        r0, 0x9
  stw       r0, 0x20(r1)

.loc_0x9C:
  lwz       r4, 0x20(r1)
  li        r6, 0
  cmpwi     r4, 0
  ble-      .loc_0x1C0
  cmpwi     r4, 0x8
  subi      r5, r4, 0x8
  ble-      .loc_0x264
  addi      r0, r5, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r5, 0
  mtctr     r0
  lis       r4, 0x802D
  addi      r5, r31, 0
  addi      r0, r4, 0x4E10
  ble-      .loc_0x264

.loc_0xD8:
  add       r4, r3, r6
  rlwinm    r7,r4,2,0,29
  add       r7, r0, r7
  lwz       r8, 0x0(r7)
  addi      r7, r4, 0x1
  rlwinm    r7,r7,2,0,29
  stw       r8, 0x0(r5)
  add       r8, r0, r7
  addi      r7, r4, 0x2
  lwz       r9, 0x0(r8)
  rlwinm    r8,r7,2,0,29
  addi      r7, r4, 0x3
  stw       r9, 0x4(r5)
  add       r9, r0, r8
  rlwinm    r8,r7,2,0,29
  lwz       r10, 0x0(r9)
  addi      r7, r4, 0x4
  rlwinm    r9,r7,2,0,29
  stw       r10, 0x8(r5)
  add       r8, r0, r8
  add       r9, r0, r9
  lwz       r10, 0x0(r8)
  addi      r7, r4, 0x5
  rlwinm    r8,r7,2,0,29
  stw       r10, 0xC(r5)
  addi      r7, r4, 0x6
  rlwinm    r7,r7,2,0,29
  lwz       r9, 0x0(r9)
  addi      r4, r4, 0x7
  rlwinm    r4,r4,2,0,29
  stw       r9, 0x10(r5)
  add       r8, r0, r8
  add       r7, r0, r7
  lwz       r8, 0x0(r8)
  add       r4, r0, r4
  addi      r6, r6, 0x8
  stw       r8, 0x14(r5)
  lwz       r7, 0x0(r7)
  stw       r7, 0x18(r5)
  lwz       r4, 0x0(r4)
  stw       r4, 0x1C(r5)
  addi      r5, r5, 0x20
  bdnz+     .loc_0xD8
  b         .loc_0x264

.loc_0x188:
  sub       r0, r5, r6
  lis       r4, 0x802D
  mtctr     r0
  cmpw      r6, r5
  addi      r5, r4, 0x4E10
  bge-      .loc_0x1C0

.loc_0x1A0:
  add       r0, r3, r6
  rlwinm    r0,r0,2,0,29
  add       r4, r5, r0
  lwz       r0, 0x0(r4)
  addi      r6, r6, 0x1
  stw       r0, 0x0(r7)
  addi      r7, r7, 0x4
  bdnz+     .loc_0x1A0

.loc_0x1C0:
  lwz       r0, 0x20(r1)
  addi      r3, r13, 0xD98
  addi      r4, r13, 0xD90
  rlwinm    r0,r0,2,0,29
  stwx      r3, r31, r0
  lwz       r3, 0x4(r29)
  bl        -0x3234

.loc_0x1DC:
  li        r0, 0
  stw       r0, 0x0(r29)
  li        r0, 0x1
  extsh     r4, r30
  lwz       r5, 0x4(r29)
  li        r3, 0x1
  stb       r0, 0x4DE(r5)
  bl        -0xF664
  lwz       r3, 0x4(r29)
  li        r4, -0x1
  bl        -0x3B08
  lwz       r3, 0x4(r29)
  li        r4, 0
  bl        -0x3A94
  lwz       r30, 0x4(r29)
  lwz       r28, 0xC(r29)
  lwz       r3, 0x0(r30)
  lwz       r31, 0x8(r29)
  mr        r5, r28
  lwz       r12, 0x0(r3)
  mr        r4, r31
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x54F8(r30)
  addi      r4, r31, 0
  addi      r5, r28, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x4(r29)
  bl        -0x2FCC
  b         .loc_0x274

.loc_0x264:
  rlwinm    r0,r6,2,0,29
  lwz       r5, 0x20(r1)
  add       r7, r31, r0
  b         .loc_0x188

.loc_0x274:
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  lwz       r28, 0x28(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void zen::ogScrDiaryMgr::setDiarySpecialNumber(short)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018F84C
 * Size:	00009C
 */
void zen::ogScrDiaryMgr::typePage()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, -0x1
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr        r30, r3
  stw       r29, 0x14(r1)
  lwz       r3, 0x4(r3)
  stb       r0, 0x4DE(r3)
  lwz       r3, 0x4(r30)
  bl        -0x3BC8
  lwz       r3, 0x4(r30)
  bl        -0x3CEC
  lwz       r31, 0x4(r30)
  lwz       r29, 0xC(r30)
  lwz       r3, 0x0(r31)
  lwz       r30, 0x8(r30)
  mr        r5, r29
  lwz       r12, 0x0(r3)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x54F8(r31)
  addi      r4, r30, 0
  addi      r5, r29, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
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
 * Address:	8018F8E8
 * Size:	0000C8
 */
void zen::ogScrDiaryMgr::nextPage()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  stw       r28, 0x18(r1)
  mr        r28, r3
  lwz       r4, 0x4(r3)
  lha       r0, 0x4D0(r4)
  rlwinm    r0,r0,2,0,29
  add       r3, r4, r0
  lwz       r3, 0x1C(r3)
  lha       r0, 0x6(r3)
  cmpwi     r0, 0x1
  bgt-      .loc_0x48
  li        r3, 0
  b         .loc_0xA8

.loc_0x48:
  li        r0, 0x1
  stb       r0, 0x4DE(r4)
  lwz       r3, 0x4(r28)
  bl        -0x3BAC
  lwz       r31, 0x4(r28)
  lwz       r29, 0xC(r28)
  lwz       r3, 0x0(r31)
  lwz       r30, 0x8(r28)
  mr        r5, r29
  lwz       r12, 0x0(r3)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x54F8(r31)
  addi      r4, r30, 0
  addi      r5, r29, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x4(r28)
  bl        -0x3140
  li        r3, 0x1

.loc_0xA8:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  lwz       r28, 0x18(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018F9B0
 * Size:	0000A0
 */
void zen::ogScrDiaryMgr::backPage()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0x1
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  stw       r28, 0x10(r1)
  mr        r28, r3
  lwz       r3, 0x4(r3)
  stb       r0, 0x4DE(r3)
  lwz       r3, 0x4(r28)
  bl        -0x3BF8
  lwz       r31, 0x4(r28)
  lwz       r29, 0xC(r28)
  lwz       r3, 0x0(r31)
  lwz       r30, 0x8(r28)
  mr        r5, r29
  lwz       r12, 0x0(r3)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x54F8(r31)
  addi      r4, r30, 0
  addi      r5, r29, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x4(r28)
  bl        -0x31E4
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

/*
 * --INFO--
 * Address:	8018FA50
 * Size:	000024
 */
void zen::ogScrDiaryMgr::exit()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x4(r3)
  bl        -0x30A8
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void zen::ogScrDiaryMgr::setCursorXY(P2DTextBox *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void zen::ogScrDiaryMgr::updateDiary(Controller *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018FA74
 * Size:	000158
 */
zen::ogDrawDiary::ogDrawDiary()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  li        r3, 0xF8
  stw       r30, 0x18(r1)
  bl        -0x148A8C
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x80
  addi      r3, r1, 0xC
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x23B74
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0xC
  addi      r3, r30, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x20EF8
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r30)
  li        r0, 0
  stb       r0, 0xEC(r30)
  stw       r0, 0xF0(r30)
  stw       r0, 0xF4(r30)

.loc_0x80:
  stw       r30, 0x10(r31)
  lis       r3, 0x802D
  addi      r4, r3, 0x5E1C
  lwz       r3, 0x10(r31)
  li        r5, 0x1
  li        r6, 0x1
  li        r7, 0x1
  bl        0x230F0
  lfs       f0, -0x4EC8(r2)
  li        r0, 0
  li        r3, 0x4C4
  stfs      f0, 0xC(r31)
  stw       r0, 0x8(r31)
  lfs       f0, 0xC(r31)
  lwz       r4, 0x10(r31)
  stfs      f0, 0xC0(r4)
  stfs      f0, 0xC4(r4)
  stfs      f0, 0xC8(r4)
  bl        -0x148B38
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xE8
  li        r4, 0x10
  li        r5, 0x400
  li        r6, 0x400
  bl        0x59D68

.loc_0xE8:
  stw       r30, 0x4(r31)
  li        r3, 0x28
  bl        -0x148B60
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x104
  bl        -0x980

.loc_0x104:
  stw       r30, 0x0(r31)
  li        r5, 0
  li        r4, 0x140
  lfs       f0, -0x4EC8(r2)
  li        r0, 0xF0
  addi      r3, r31, 0
  stfs      f0, 0xC(r31)
  stw       r5, 0x8(r31)
  lfs       f0, -0x4EC4(r2)
  stfs      f0, 0x14(r31)
  lfs       f0, -0x4EC0(r2)
  stfs      f0, 0x18(r31)
  lwz       r5, 0x10(r31)
  sth       r4, 0xB8(r5)
  sth       r0, 0xBA(r5)
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void zen::ogDrawDiary::start()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
void zen::ogDrawDiary::setOffset()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018FBCC
 * Size:	000298
 */
void zen::ogDrawDiary::open(float, float, short)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xD8(r1)
  stfd      f31, 0xD0(r1)
  fmr       f31, f2
  stfd      f30, 0xC8(r1)
  fmr       f30, f1
  stmw      r25, 0xAC(r1)
  li        r27, 0x4D
  addi      r25, r4, 0
  extsh     r26, r25
  addi      r31, r3, 0
  addi      r29, r27, 0
  addi      r30, r27, 0
  subfic    r28, r26, 0x1E
  lwz       r0, 0x2F6C(r13)
  cmplwi    r0, 0
  beq-      .loc_0x68
  add       r3, r0, r26
  lbz       r27, 0x17(r3)
  mr        r3, r0
  bl        -0x10EFB8
  lwz       r0, 0x2F6C(r13)
  sub       r29, r3, r27
  add       r3, r0, r26
  lbz       r30, 0x35(r3)

.loc_0x68:
  li        r3, 0x1
  addi      r4, r26, 0
  bl        -0xFAF0
  li        r3, 0x2
  addi      r4, r27, 0
  bl        -0xFAFC
  li        r3, 0x3
  addi      r4, r29, 0
  bl        -0xFB08
  li        r3, 0x4
  addi      r4, r28, 0
  bl        -0xFB14
  li        r3, 0x5
  addi      r4, r30, 0
  bl        -0xFB20
  lwz       r0, 0x8(r31)
  cmpwi     r0, 0
  bne-      .loc_0x27C
  lfs       f0, -0x4EBC(r2)
  li        r0, 0x1
  addi      r5, r25, 0
  stfs      f0, 0xC(r31)
  li        r4, 0
  stw       r0, 0x8(r31)
  stfs      f30, 0x14(r31)
  stfs      f31, 0x18(r31)
  lfs       f0, 0x14(r31)
  stfs      f0, 0x1C(r31)
  lfs       f0, 0x18(r31)
  stfs      f0, 0x20(r31)
  lfs       f0, 0x14(r31)
  lfs       f1, 0x18(r31)
  fctiwz    f0, f0
  lwz       r3, 0x10(r31)
  fctiwz    f1, f1
  stfd      f0, 0x98(r1)
  stfd      f1, 0xA0(r1)
  lwz       r0, 0x9C(r1)
  lwz       r6, 0xA4(r1)
  extsh     r0, r0
  sth       r0, 0xB8(r3)
  extsh     r0, r6
  sth       r0, 0xBA(r3)
  lfs       f0, 0x14(r31)
  lfs       f1, 0x18(r31)
  fctiwz    f0, f0
  lwz       r3, 0x0(r31)
  fctiwz    f1, f1
  lwz       r3, 0x4(r3)
  stfd      f0, 0x88(r1)
  lwz       r6, 0x54F8(r3)
  stfd      f1, 0x90(r1)
  lwz       r0, 0x8C(r1)
  lwz       r3, 0x94(r1)
  extsh     r0, r0
  sth       r0, 0xB8(r6)
  extsh     r0, r3
  sth       r0, 0xBA(r6)
  lfs       f0, 0x14(r31)
  lfs       f1, 0x18(r31)
  fctiwz    f0, f0
  lwz       r3, 0x0(r31)
  fctiwz    f1, f1
  lwz       r3, 0x4(r3)
  stfd      f0, 0x78(r1)
  lwz       r6, 0x0(r3)
  stfd      f1, 0x80(r1)
  lwz       r0, 0x7C(r1)
  lwz       r3, 0x84(r1)
  extsh     r0, r0
  sth       r0, 0xB8(r6)
  extsh     r0, r3
  sth       r0, 0xBA(r6)
  lwz       r3, 0x0(r31)
  bl        -0x7A4
  lfs       f0, -0x4EC8(r2)
  addi      r5, r1, 0x68
  li        r4, 0x4
  stfs      f0, 0x70(r1)
  li        r6, 0
  li        r7, 0
  stfs      f0, 0x6C(r1)
  stfs      f0, 0x68(r1)
  lfs       f1, 0xD9C(r13)
  lfs       f0, 0xDA0(r13)
  stfs      f1, 0x68(r1)
  stfs      f0, 0x6C(r1)
  lfs       f0, 0xDA4(r13)
  stfs      f0, 0x70(r1)
  lwz       r3, 0x4(r31)
  bl        0x59DA0
  lwz       r3, 0x4(r31)
  addi      r5, r1, 0x68
  li        r4, 0x5
  li        r6, 0
  li        r7, 0
  bl        0x59D88
  lwz       r3, 0x4(r31)
  addi      r5, r1, 0x68
  li        r4, 0x6
  li        r6, 0
  li        r7, 0
  bl        0x59D70
  lwz       r3, 0x4(r31)
  addi      r5, r1, 0x68
  li        r4, 0x7
  li        r6, 0
  li        r7, 0
  bl        0x59D58
  lwz       r3, 0x4(r31)
  addi      r5, r1, 0x68
  li        r4, 0x8
  li        r6, 0
  li        r7, 0
  bl        0x59D40
  lwz       r3, 0x4(r31)
  addi      r5, r1, 0x68
  li        r4, 0x9
  li        r6, 0
  li        r7, 0
  bl        0x59D28
  lwz       r3, 0x4(r31)
  addi      r5, r1, 0x68
  li        r4, 0xA
  li        r6, 0
  li        r7, 0
  bl        0x59D10
  lwz       r3, 0x4(r31)
  addi      r5, r1, 0x68
  li        r4, 0xB
  li        r6, 0
  li        r7, 0
  bl        0x59CF8

.loc_0x27C:
  lmw       r25, 0xAC(r1)
  lwz       r0, 0xDC(r1)
  lfd       f31, 0xD0(r1)
  lfd       f30, 0xC8(r1)
  addi      r1, r1, 0xD8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018FE64
 * Size:	0002B8
 */
void zen::ogDrawDiary::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xC0(r1)
  stfd      f31, 0xB8(r1)
  stmw      r25, 0x9C(r1)
  mr        r30, r3
  addi      r31, r4, 0
  lwz       r3, 0x8(r3)
  cmpwi     r3, 0
  bne-      .loc_0x2C
  b         .loc_0x2A0

.loc_0x2C:
  cmpwi     r3, 0x1
  bne-      .loc_0x64
  lfs       f1, 0xC(r30)
  lfs       f0, -0x4EB8(r2)
  fmuls     f0, f1, f0
  stfs      f0, 0xC(r30)
  lfs       f1, 0xC(r30)
  lfs       f0, -0x4EB4(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x64
  stfs      f0, 0xC(r30)
  li        r0, 0x2
  stw       r0, 0x8(r30)

.loc_0x64:
  lwz       r0, 0x8(r30)
  cmpwi     r0, 0x2
  bne-      .loc_0x13C
  lwz       r3, 0x28(r31)
  rlwinm.   r0,r3,0,18,18
  beq-      .loc_0x9C
  li        r0, 0x3
  stw       r0, 0x8(r30)
  li        r4, 0x1
  lwz       r3, 0x4(r30)
  bl        0x59DE4
  li        r3, 0x11D
  bl        -0xEAB84
  b         .loc_0x13C

.loc_0x9C:
  rlwinm.   r0,r3,0,19,19
  beq-      .loc_0x13C
  lwz       r25, 0x0(r30)
  lwz       r4, 0x4(r25)
  lha       r0, 0x4D0(r4)
  rlwinm    r0,r0,2,0,29
  add       r3, r4, r0
  lwz       r3, 0x1C(r3)
  lha       r0, 0x6(r3)
  cmpwi     r0, 0x1
  bgt-      .loc_0xD0
  li        r29, 0
  b         .loc_0x12C

.loc_0xD0:
  li        r29, 0x1
  stb       r29, 0x4DE(r4)
  lwz       r3, 0x4(r25)
  bl        -0x41B0
  lwz       r28, 0x4(r25)
  lwz       r26, 0xC(r25)
  lwz       r3, 0x0(r28)
  lwz       r27, 0x8(r25)
  mr        r5, r26
  lwz       r12, 0x0(r3)
  mr        r4, r27
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x54F8(r28)
  addi      r4, r27, 0
  addi      r5, r26, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x4(r25)
  bl        -0x3744

.loc_0x12C:
  rlwinm.   r0,r29,0,24,31
  beq-      .loc_0x13C
  li        r3, 0x134
  bl        -0xEAC28

.loc_0x13C:
  lwz       r0, 0x8(r30)
  cmpwi     r0, 0x3
  bne-      .loc_0x17C
  lfs       f1, 0xC(r30)
  lfs       f0, -0x4EB0(r2)
  fmuls     f0, f1, f0
  stfs      f0, 0xC(r30)
  lfs       f1, 0xC(r30)
  lfs       f0, -0x4EBC(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0x17C
  lfs       f0, -0x4EC8(r2)
  li        r0, 0
  stfs      f0, 0xC(r30)
  stw       r0, 0x8(r30)

.loc_0x17C:
  lfs       f0, 0x14(r30)
  lfs       f1, 0x18(r30)
  fctiwz    f0, f0
  lwz       r3, 0x10(r30)
  fctiwz    f1, f1
  stfd      f0, 0x88(r1)
  stfd      f1, 0x90(r1)
  lwz       r0, 0x8C(r1)
  lwz       r4, 0x94(r1)
  extsh     r0, r0
  sth       r0, 0xB8(r3)
  extsh     r0, r4
  sth       r0, 0xBA(r3)
  lfs       f0, 0x14(r30)
  lfs       f1, 0x18(r30)
  fctiwz    f0, f0
  lwz       r3, 0x0(r30)
  fctiwz    f1, f1
  lwz       r3, 0x4(r3)
  stfd      f0, 0x78(r1)
  lwz       r4, 0x54F8(r3)
  stfd      f1, 0x80(r1)
  lwz       r0, 0x7C(r1)
  lwz       r3, 0x84(r1)
  extsh     r0, r0
  sth       r0, 0xB8(r4)
  extsh     r0, r3
  sth       r0, 0xBA(r4)
  lfs       f0, 0x14(r30)
  lfs       f1, 0x18(r30)
  fctiwz    f0, f0
  lwz       r3, 0x0(r30)
  fctiwz    f1, f1
  lwz       r3, 0x4(r3)
  stfd      f0, 0x68(r1)
  lwz       r4, 0x0(r3)
  stfd      f1, 0x70(r1)
  lwz       r0, 0x6C(r1)
  lwz       r3, 0x74(r1)
  extsh     r0, r0
  sth       r0, 0xB8(r4)
  extsh     r0, r3
  sth       r0, 0xBA(r4)
  lfs       f0, 0xC(r30)
  lwz       r3, 0x10(r30)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lwz       r3, 0x10(r30)
  bl        0x22AAC
  lwz       r3, 0x0(r30)
  addi      r4, r1, 0x34
  lfs       f31, 0xC(r30)
  mr        r5, r4
  lwz       r26, 0x4(r3)
  mr        r6, r4
  stfs      f31, 0x34(r1)
  lwz       r3, 0x0(r26)
  addi      r3, r3, 0xC0
  bl        -0x132A40
  stfs      f31, 0x30(r1)
  addi      r4, r1, 0x30
  addi      r5, r4, 0
  lwz       r3, 0x54F8(r26)
  addi      r6, r4, 0
  addi      r3, r3, 0xC0
  bl        -0x132A5C
  lwz       r3, 0x0(r30)
  mr        r4, r31
  bl        -0xDB0
  lwz       r3, 0x4(r30)
  bl        0x59A8C
  lwz       r3, 0x8(r30)

.loc_0x2A0:
  lmw       r25, 0x9C(r1)
  lwz       r0, 0xC4(r1)
  lfd       f31, 0xB8(r1)
  addi      r1, r1, 0xC0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A8
 */
void zen::ogDrawDiary::draw(Graphics &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019011C
 * Size:	000430
 */
zen::ogDrawSelectDiary::ogDrawSelectDiary()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  addi      r31, r3, 0
  stw       r30, 0x38(r1)
  stw       r29, 0x34(r1)
  stw       r28, 0x30(r1)
  li        r28, 0
  stw       r28, 0x8(r3)
  li        r3, 0xF8
  stw       r28, 0xC(r31)
  lfs       f4, -0x4EB4(r2)
  stfs      f4, 0x14(r31)
  fmr       f2, f4
  fmr       f1, f4
  stfs      f4, 0x10(r31)
  fmr       f0, f4
  lfs       f3, -0x4EC8(r2)
  stfs      f3, 0x24(r31)
  stfs      f3, 0x20(r31)
  stfs      f3, 0x1C(r31)
  stfs      f3, 0x18(r31)
  stfs      f4, 0x2C(r31)
  stfs      f4, 0x28(r31)
  stfs      f2, 0x34(r31)
  stfs      f2, 0x30(r31)
  stw       r28, 0x38(r31)
  stw       r28, 0x3C(r31)
  stfs      f1, 0x44(r31)
  stfs      f1, 0x40(r31)
  stfs      f3, 0x54(r31)
  stfs      f3, 0x50(r31)
  stfs      f3, 0x4C(r31)
  stfs      f3, 0x48(r31)
  stfs      f0, 0x5C(r31)
  stfs      f0, 0x58(r31)
  stfs      f4, 0x64(r31)
  stfs      f4, 0x60(r31)
  bl        -0x1491B4
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0xFC
  addi      r3, r1, 0x20
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x2344C
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x20
  addi      r3, r29, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x207D0
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r29)
  stb       r28, 0xEC(r29)
  stw       r28, 0xF0(r29)
  stw       r28, 0xF4(r29)

.loc_0xFC:
  stw       r29, 0x4(r31)
  lis       r3, 0x802D
  addi      r4, r3, 0x5E34
  lwz       r3, 0x4(r31)
  li        r5, 0x1
  li        r6, 0x1
  li        r7, 0x1
  bl        0x229CC
  li        r3, 0xF8
  bl        -0x149238
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x184
  addi      r3, r1, 0x18
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x233C8
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x18
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x2074C
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x184:
  stw       r28, 0x2C4(r31)
  lis       r3, 0x802D
  addi      r4, r3, 0x5E4C
  lwz       r3, 0x2C4(r31)
  li        r5, 0
  li        r6, 0
  li        r7, 0x1
  bl        0x22944
  lwz       r3, 0x2C4(r31)
  lis       r4, 0x626C
  addi      r4, r4, 0x636B
  lwz       r12, 0x0(r3)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2C8(r31)
  li        r0, 0xFF
  li        r3, 0x6C
  lwz       r4, 0x2C8(r31)
  stb       r0, 0xF0(r4)
  bl        -0x1492F0
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x1F0
  li        r4, 0
  bl        0x30008

.loc_0x1F0:
  stw       r28, 0x2DC(r31)
  lis       r3, 0x6162
  addi      r4, r3, 0x746E
  lfs       f0, -0x4EAC(r2)
  li        r5, 0x1
  stfs      f0, 0x31B0(r13)
  lwz       r3, 0x4(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2CC(r31)
  li        r3, 0x12C
  bl        -0x14933C
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x240
  lwz       r4, 0x2CC(r31)
  lfs       f1, -0x4EB4(r2)
  bl        -0x11134

.loc_0x240:
  stw       r28, 0x2D0(r31)
  li        r3, 0x24
  bl        -0x149360
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x25C
  bl        -0x900

.loc_0x25C:
  stw       r28, 0x2D4(r31)
  li        r0, 0
  addi      r29, r31, 0
  sth       r0, 0x2E8(r31)
  li        r28, 0

.loc_0x270:
  addi      r5, r28, 0
  crclr     6, 0x6
  addi      r3, r1, 0x28
  addi      r4, r13, 0xDA8
  bl        0x861FC
  lwz       r3, 0x4(r31)
  li        r5, 0x1
  lbz       r0, 0x29(r1)
  lwz       r12, 0x0(r3)
  lbz       r4, 0x28(r1)
  rlwinm    r0,r0,16,0,15
  lwz       r12, 0x34(r12)
  rlwimi    r0,r4,24,0,7
  lbz       r6, 0x2A(r1)
  lbz       r4, 0x2B(r1)
  mtlr      r12
  rlwimi    r0,r6,8,16,23
  or        r4, r4, r0
  blrl      
  stw       r3, 0x68(r29)
  li        r30, 0
  addi      r5, r28, 0
  crclr     6, 0x6
  lwz       r6, 0x68(r29)
  addi      r3, r1, 0x28
  lbz       r0, 0xC(r6)
  rlwimi    r0,r30,7,24,24
  addi      r4, r13, 0xDB0
  stb       r0, 0xC(r6)
  bl        0x86198
  lwz       r3, 0x4(r31)
  li        r5, 0x1
  lbz       r0, 0x29(r1)
  lwz       r12, 0x0(r3)
  lbz       r4, 0x28(r1)
  rlwinm    r0,r0,16,0,15
  lwz       r12, 0x34(r12)
  rlwimi    r0,r4,24,0,7
  lbz       r6, 0x2A(r1)
  lbz       r4, 0x2B(r1)
  mtlr      r12
  rlwimi    r0,r6,8,16,23
  or        r4, r4, r0
  blrl      
  stw       r3, 0xE0(r29)
  addi      r5, r28, 0
  addi      r3, r1, 0x28
  crclr     6, 0x6
  lwz       r6, 0xE0(r29)
  addi      r4, r13, 0xDB8
  lbz       r0, 0xC(r6)
  rlwimi    r0,r30,7,24,24
  stb       r0, 0xC(r6)
  bl        0x86138
  lwz       r3, 0x4(r31)
  li        r5, 0x1
  lbz       r0, 0x29(r1)
  lwz       r12, 0x0(r3)
  lbz       r4, 0x28(r1)
  rlwinm    r0,r0,16,0,15
  lwz       r12, 0x34(r12)
  rlwimi    r0,r4,24,0,7
  lbz       r6, 0x2A(r1)
  lbz       r4, 0x2B(r1)
  mtlr      r12
  rlwimi    r0,r6,8,16,23
  or        r4, r4, r0
  blrl      
  stw       r3, 0x1D0(r29)
  addi      r3, r1, 0x28
  addi      r5, r28, 0xE
  crclr     6, 0x6
  addi      r4, r13, 0xDC0
  bl        0x860E8
  lwz       r3, 0x4(r31)
  li        r5, 0x1
  lbz       r0, 0x29(r1)
  lwz       r12, 0x0(r3)
  lbz       r4, 0x28(r1)
  rlwinm    r0,r0,16,0,15
  lwz       r12, 0x34(r12)
  rlwimi    r0,r4,24,0,7
  lbz       r6, 0x2A(r1)
  lbz       r4, 0x2B(r1)
  mtlr      r12
  rlwimi    r0,r6,8,16,23
  or        r4, r4, r0
  blrl      
  addi      r28, r28, 0x1
  stw       r3, 0x248(r29)
  cmpwi     r28, 0x1E
  addi      r29, r29, 0x4
  blt+      .loc_0x270
  sth       r30, 0x2E0(r31)
  li        r0, -0x1
  addi      r3, r31, 0
  sth       r30, 0x2E2(r31)
  sth       r30, 0x2E4(r31)
  sth       r30, 0x2E6(r31)
  lfs       f0, -0x4EC8(r2)
  stfs      f0, 0x2EC(r31)
  stw       r0, 0x0(r31)
  bl        0x1F0
  mr        r3, r31
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  lwz       r29, 0x34(r1)
  lwz       r28, 0x30(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019054C
 * Size:	0001C8
 */
void zen::ogDrawSelectDiary::start()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  addi      r31, r3, 0
  stw       r30, 0x40(r1)
  stw       r29, 0x3C(r1)
  lwz       r0, 0x2F6C(r13)
  cmplwi    r0, 0
  beq-      .loc_0x3C
  mr        r3, r0
  bl        -0x10F9C8
  subi      r0, r3, 0x1
  sth       r0, 0x2E8(r31)
  b         .loc_0x44

.loc_0x3C:
  li        r0, 0xF
  sth       r0, 0x2E8(r31)

.loc_0x44:
  lha       r0, 0x2E8(r31)
  cmpwi     r0, 0
  blt-      .loc_0x1AC
  li        r0, 0x1
  stw       r0, 0x0(r31)
  li        r29, 0
  rlwinm    r0,r29,2,0,29
  lfs       f0, -0x4EC8(r2)
  li        r3, 0
  li        r4, 0xFF
  stfs      f0, 0x2EC(r31)
  add       r30, r31, r0
  sth       r3, 0x2E0(r31)
  sth       r3, 0x2E2(r31)
  sth       r3, 0x2E4(r31)
  sth       r3, 0x2E6(r31)
  lwz       r3, 0x2C8(r31)
  stb       r4, 0xF0(r3)

.loc_0x8C:
  lha       r0, 0x2E8(r31)
  cmpw      r29, r0
  ble-      .loc_0xA8
  lwz       r3, 0x1D0(r30)
  li        r4, 0x50
  bl        0x2F2EC
  b         .loc_0xB4

.loc_0xA8:
  lwz       r3, 0x1D0(r30)
  li        r4, 0xFF
  bl        0x2F2DC

.loc_0xB4:
  addi      r29, r29, 0x1
  cmpwi     r29, 0x1E
  addi      r30, r30, 0x4
  blt+      .loc_0x8C
  lha       r3, 0x2E8(r31)
  li        r5, 0
  addi      r3, r3, 0x1
  cmpwi     r3, 0x1E
  rlwinm    r0,r3,2,0,29
  add       r6, r31, r0
  subfic    r3, r3, 0x1E
  bge-      .loc_0x19C
  rlwinm.   r0,r3,29,3,31
  mtctr     r0
  beq-      .loc_0x180

.loc_0xF0:
  lwz       r4, 0x248(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x24C(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x250(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x254(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x258(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x25C(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x260(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x264(r6)
  addi      r6, r6, 0x20
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  bdnz+     .loc_0xF0
  andi.     r3, r3, 0x7
  beq-      .loc_0x19C

.loc_0x180:
  mtctr     r3

.loc_0x184:
  lwz       r4, 0x248(r6)
  addi      r6, r6, 0x4
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  bdnz+     .loc_0x184

.loc_0x19C:
  lwz       r3, 0x2D0(r31)
  bl        -0x11070
  mr        r3, r31
  bl        .loc_0x1C8

.loc_0x1AC:
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  lwz       r30, 0x40(r1)
  lwz       r29, 0x3C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr       

.loc_0x1C8:
*/
}

/*
 * --INFO--
 * Address:	80190714
 * Size:	00010C
 */
void zen::ogDrawSelectDiary::setCursorAlpha()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x726F
  stw       r0, 0x4(r1)
  addi      r4, r4, 0x6F74
  li        r5, 0x1
  stwu      r1, -0x68(r1)
  stw       r31, 0x64(r1)
  stw       r30, 0x60(r1)
  stw       r29, 0x5C(r1)
  stw       r28, 0x58(r1)
  mr        r28, r3
  lwz       r3, 0x4(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x68(r28)
  mr        r29, r3
  lis       r31, 0x7A30
  lfd       f2, -0x4ED0(r2)
  lha       r3, 0x18(r4)
  lha       r0, 0x1A(r4)
  lis       r30, 0x4330
  xoris     r3, r3, 0x8000
  lwz       r4, 0x4(r28)
  stw       r3, 0x54(r1)
  xoris     r0, r0, 0x8000
  stw       r0, 0x4C(r1)
  addi      r5, r29, 0
  addi      r3, r28, 0x8
  stw       r30, 0x50(r1)
  addi      r6, r31, 0x306C
  stw       r30, 0x48(r1)
  lfd       f1, 0x50(r1)
  lfd       f0, 0x48(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        0x4A494
  lwz       r6, 0xE0(r28)
  mr        r5, r29
  lfd       f2, -0x4ED0(r2)
  addi      r3, r28, 0x38
  lha       r4, 0x18(r6)
  lha       r0, 0x1A(r6)
  addi      r6, r31, 0x3072
  xoris     r7, r4, 0x8000
  lwz       r4, 0x4(r28)
  xoris     r0, r0, 0x8000
  stw       r7, 0x44(r1)
  stw       r0, 0x3C(r1)
  stw       r30, 0x40(r1)
  stw       r30, 0x38(r1)
  lfd       f1, 0x40(r1)
  lfd       f0, 0x38(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        0x4A448
  mr        r3, r28
  bl        .loc_0x10C
  lwz       r0, 0x6C(r1)
  lwz       r31, 0x64(r1)
  lwz       r30, 0x60(r1)
  lwz       r29, 0x5C(r1)
  lwz       r28, 0x58(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr       

.loc_0x10C:
*/
}

/*
 * --INFO--
 * Address:	80190820
 * Size:	000104
 */
void zen::ogDrawSelectDiary::MoveCursor()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stw       r31, 0x5C(r1)
  mr        r31, r3
  stw       r30, 0x58(r1)
  lha       r0, 0x2E2(r3)
  lha       r4, 0x2E0(r3)
  mulli     r3, r0, 0xA
  lha       r0, 0x2E8(r31)
  add       r3, r4, r3
  extsh     r3, r3
  cmpw      r3, r0
  ble-      .loc_0x40
  li        r3, 0x1
  b         .loc_0xEC

.loc_0x40:
  sth       r3, 0x2E4(r31)
  lis       r30, 0x4330
  addi      r3, r31, 0x8
  lha       r0, 0x2E4(r31)
  lfd       f2, -0x4ED0(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4EA8(r2)
  add       r4, r31, r0
  lwz       r5, 0x68(r4)
  lha       r4, 0x18(r5)
  lha       r0, 0x1A(r5)
  xoris     r4, r4, 0x8000
  xoris     r0, r0, 0x8000
  stw       r4, 0x54(r1)
  stw       r0, 0x4C(r1)
  stw       r30, 0x50(r1)
  stw       r30, 0x48(r1)
  lfd       f1, 0x50(r1)
  lfd       f0, 0x48(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        0x4A2F4
  lha       r0, 0x2E4(r31)
  addi      r3, r31, 0x38
  lfd       f2, -0x4ED0(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4EA8(r2)
  add       r4, r31, r0
  lwz       r5, 0xE0(r4)
  lha       r4, 0x18(r5)
  lha       r0, 0x1A(r5)
  xoris     r4, r4, 0x8000
  xoris     r0, r0, 0x8000
  stw       r4, 0x44(r1)
  stw       r0, 0x3C(r1)
  stw       r30, 0x40(r1)
  stw       r30, 0x38(r1)
  lfd       f1, 0x40(r1)
  lfd       f0, 0x38(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        0x4A2A4
  li        r3, 0

.loc_0xEC:
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
 * Address:	80190924
 * Size:	000880
 */
void zen::ogDrawSelectDiary::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x1A0(r1)
  stfd      f31, 0x198(r1)
  stfd      f30, 0x190(r1)
  stfd      f29, 0x188(r1)
  stfd      f28, 0x180(r1)
  stfd      f27, 0x178(r1)
  stw       r31, 0x174(r1)
  addi      r31, r4, 0
  stw       r30, 0x170(r1)
  mr        r30, r3
  stw       r29, 0x16C(r1)
  stw       r28, 0x168(r1)
  lwz       r3, 0x0(r3)
  cmpwi     r3, -0x1
  bne-      .loc_0x48
  b         .loc_0x84C

.loc_0x48:
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x2EC(r30)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x2EC(r30)
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0x4
  bne-      .loc_0x78
  li        r0, -0x1
  stw       r0, 0x0(r30)
  lwz       r3, 0x0(r30)
  b         .loc_0x84C

.loc_0x78:
  lwz       r3, 0x2DC(r30)
  stw       r31, 0x0(r3)
  lwz       r3, 0x2DC(r30)
  bl        0x2F9FC
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0x1
  bne-      .loc_0xDC
  lfs       f1, 0x2EC(r30)
  lfs       f0, -0x4ED8(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xB4
  li        r0, 0
  stw       r0, 0x0(r30)
  lwz       r3, 0x0(r30)
  b         .loc_0x84C

.loc_0xB4:
  fdivs     f0, f1, f0
  lfs       f1, -0x4EB4(r2)
  lfs       f2, -0x4EA4(r2)
  lwz       r3, 0x2C8(r30)
  fsubs     f0, f1, f0
  fmuls     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x160(r1)
  lwz       r0, 0x164(r1)
  stb       r0, 0xF0(r3)

.loc_0xDC:
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0x2
  bne-      .loc_0x128
  lfs       f1, 0x2EC(r30)
  lfs       f0, -0x4ED8(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x108
  li        r0, 0x4
  stw       r0, 0x0(r30)
  lwz       r3, 0x0(r30)
  b         .loc_0x84C

.loc_0x108:
  fdivs     f0, f1, f0
  lfs       f1, -0x4EA4(r2)
  lwz       r3, 0x2C8(r30)
  fmuls     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x160(r1)
  lwz       r0, 0x164(r1)
  stb       r0, 0xF0(r3)

.loc_0x128:
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0
  bne-      .loc_0x668
  lis       r3, 0x100
  lwz       r4, 0x28(r31)
  addi      r0, r3, 0x1000
  and.      r0, r4, r0
  beq-      .loc_0x1DC
  lha       r6, 0x2E4(r30)
  lis       r5, 0x4330
  lfd       f2, -0x4ED0(r2)
  rlwinm    r0,r6,2,0,29
  lwz       r3, 0x2D4(r30)
  add       r4, r30, r0
  lwz       r9, 0x1D0(r4)
  addi      r4, r6, 0x1
  lha       r7, 0x18(r9)
  lha       r0, 0x1C(r9)
  lha       r8, 0x1A(r9)
  sub       r6, r0, r7
  lha       r0, 0x1E(r9)
  srawi     r6, r6, 0x1
  addze     r6, r6
  sub       r0, r0, r8
  srawi     r0, r0, 0x1
  addze     r0, r0
  add       r6, r7, r6
  add       r0, r8, r0
  xoris     r6, r6, 0x8000
  xoris     r0, r0, 0x8000
  stw       r6, 0x164(r1)
  stw       r0, 0x15C(r1)
  stw       r5, 0x160(r1)
  stw       r5, 0x158(r1)
  lfd       f1, 0x160(r1)
  lfd       f0, 0x158(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        -0xF18
  li        r3, 0x111
  bl        -0xEB778
  li        r0, 0x3
  stw       r0, 0x0(r30)
  lwz       r3, 0x0(r30)
  b         .loc_0x84C

.loc_0x1DC:
  andi.     r0, r4, 0xA000
  beq-      .loc_0x1FC
  li        r0, 0x2
  stw       r0, 0x0(r30)
  lfs       f0, -0x4EC8(r2)
  stfs      f0, 0x2EC(r30)
  lwz       r3, 0x0(r30)
  b         .loc_0x84C

.loc_0x1FC:
  lwz       r3, 0x2DC(r30)
  lwz       r4, 0x4(r3)
  rlwinm.   r0,r4,0,9,9
  beq-      .loc_0x318
  lha       r3, 0x2E0(r30)
  cmpwi     r3, 0
  ble-      .loc_0x318
  subi      r0, r3, 0x1
  sth       r0, 0x2E0(r30)
  lha       r0, 0x2E2(r30)
  lha       r4, 0x2E0(r30)
  mulli     r3, r0, 0xA
  lha       r0, 0x2E8(r30)
  add       r3, r4, r3
  extsh     r3, r3
  cmpw      r3, r0
  ble-      .loc_0x248
  li        r0, 0x1
  b         .loc_0x2F4

.loc_0x248:
  sth       r3, 0x2E4(r30)
  lis       r29, 0x4330
  addi      r3, r30, 0x8
  lha       r0, 0x2E4(r30)
  lfd       f2, -0x4ED0(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4EA8(r2)
  add       r4, r30, r0
  lwz       r5, 0x68(r4)
  lha       r4, 0x18(r5)
  lha       r0, 0x1A(r5)
  xoris     r4, r4, 0x8000
  xoris     r0, r0, 0x8000
  stw       r4, 0x15C(r1)
  stw       r0, 0x164(r1)
  stw       r29, 0x158(r1)
  stw       r29, 0x160(r1)
  lfd       f1, 0x158(r1)
  lfd       f0, 0x160(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        0x49FE8
  lha       r0, 0x2E4(r30)
  addi      r3, r30, 0x38
  lfd       f2, -0x4ED0(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4EA8(r2)
  add       r4, r30, r0
  lwz       r5, 0xE0(r4)
  lha       r4, 0x18(r5)
  lha       r0, 0x1A(r5)
  xoris     r4, r4, 0x8000
  xoris     r0, r0, 0x8000
  stw       r4, 0x154(r1)
  stw       r0, 0x14C(r1)
  stw       r29, 0x150(r1)
  stw       r29, 0x148(r1)
  lfd       f1, 0x150(r1)
  lfd       f0, 0x148(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        0x49F98
  li        r0, 0

.loc_0x2F4:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x30C
  lha       r3, 0x2E0(r30)
  addi      r0, r3, 0x1
  sth       r0, 0x2E0(r30)
  b         .loc_0x650

.loc_0x30C:
  li        r3, 0x112
  bl        -0xEB8C0
  b         .loc_0x650

.loc_0x318:
  rlwinm.   r0,r4,0,11,11
  beq-      .loc_0x42C
  lha       r3, 0x2E0(r30)
  cmpwi     r3, 0x9
  bge-      .loc_0x42C
  addi      r0, r3, 0x1
  sth       r0, 0x2E0(r30)
  lha       r0, 0x2E2(r30)
  lha       r4, 0x2E0(r30)
  mulli     r3, r0, 0xA
  lha       r0, 0x2E8(r30)
  add       r3, r4, r3
  extsh     r3, r3
  cmpw      r3, r0
  ble-      .loc_0x35C
  li        r0, 0x1
  b         .loc_0x408

.loc_0x35C:
  sth       r3, 0x2E4(r30)
  lis       r29, 0x4330
  addi      r3, r30, 0x8
  lha       r0, 0x2E4(r30)
  lfd       f2, -0x4ED0(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4EA8(r2)
  add       r4, r30, r0
  lwz       r5, 0x68(r4)
  lha       r4, 0x18(r5)
  lha       r0, 0x1A(r5)
  xoris     r4, r4, 0x8000
  xoris     r0, r0, 0x8000
  stw       r4, 0x14C(r1)
  stw       r0, 0x154(r1)
  stw       r29, 0x148(r1)
  stw       r29, 0x150(r1)
  lfd       f1, 0x148(r1)
  lfd       f0, 0x150(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        0x49ED4
  lha       r0, 0x2E4(r30)
  addi      r3, r30, 0x38
  lfd       f2, -0x4ED0(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4EA8(r2)
  add       r4, r30, r0
  lwz       r5, 0xE0(r4)
  lha       r4, 0x18(r5)
  lha       r0, 0x1A(r5)
  xoris     r4, r4, 0x8000
  xoris     r0, r0, 0x8000
  stw       r4, 0x15C(r1)
  stw       r0, 0x164(r1)
  stw       r29, 0x158(r1)
  stw       r29, 0x160(r1)
  lfd       f1, 0x158(r1)
  lfd       f0, 0x160(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        0x49E84
  li        r0, 0

.loc_0x408:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x420
  lha       r3, 0x2E0(r30)
  subi      r0, r3, 0x1
  sth       r0, 0x2E0(r30)
  b         .loc_0x650

.loc_0x420:
  li        r3, 0x112
  bl        -0xEB9D4
  b         .loc_0x650

.loc_0x42C:
  rlwinm.   r0,r4,0,12,12
  beq-      .loc_0x540
  lha       r3, 0x2E2(r30)
  cmpwi     r3, 0
  ble-      .loc_0x540
  subi      r0, r3, 0x1
  sth       r0, 0x2E2(r30)
  lha       r0, 0x2E2(r30)
  lha       r4, 0x2E0(r30)
  mulli     r3, r0, 0xA
  lha       r0, 0x2E8(r30)
  add       r3, r4, r3
  extsh     r3, r3
  cmpw      r3, r0
  ble-      .loc_0x470
  li        r0, 0x1
  b         .loc_0x51C

.loc_0x470:
  sth       r3, 0x2E4(r30)
  lis       r29, 0x4330
  addi      r3, r30, 0x8
  lha       r0, 0x2E4(r30)
  lfd       f2, -0x4ED0(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4EA8(r2)
  add       r4, r30, r0
  lwz       r5, 0x68(r4)
  lha       r4, 0x18(r5)
  lha       r0, 0x1A(r5)
  xoris     r4, r4, 0x8000
  xoris     r0, r0, 0x8000
  stw       r4, 0x14C(r1)
  stw       r0, 0x154(r1)
  stw       r29, 0x148(r1)
  stw       r29, 0x150(r1)
  lfd       f1, 0x148(r1)
  lfd       f0, 0x150(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        0x49DC0
  lha       r0, 0x2E4(r30)
  addi      r3, r30, 0x38
  lfd       f2, -0x4ED0(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4EA8(r2)
  add       r4, r30, r0
  lwz       r5, 0xE0(r4)
  lha       r4, 0x18(r5)
  lha       r0, 0x1A(r5)
  xoris     r4, r4, 0x8000
  xoris     r0, r0, 0x8000
  stw       r4, 0x15C(r1)
  stw       r0, 0x164(r1)
  stw       r29, 0x158(r1)
  stw       r29, 0x160(r1)
  lfd       f1, 0x158(r1)
  lfd       f0, 0x160(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        0x49D70
  li        r0, 0

.loc_0x51C:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x534
  lha       r3, 0x2E2(r30)
  addi      r0, r3, 0x1
  sth       r0, 0x2E2(r30)
  b         .loc_0x650

.loc_0x534:
  li        r3, 0x112
  bl        -0xEBAE8
  b         .loc_0x650

.loc_0x540:
  rlwinm.   r0,r4,0,10,10
  beq-      .loc_0x650
  lha       r3, 0x2E2(r30)
  cmpwi     r3, 0x2
  bge-      .loc_0x650
  addi      r0, r3, 0x1
  sth       r0, 0x2E2(r30)
  lha       r0, 0x2E2(r30)
  lha       r4, 0x2E0(r30)
  mulli     r3, r0, 0xA
  lha       r0, 0x2E8(r30)
  add       r3, r4, r3
  extsh     r3, r3
  cmpw      r3, r0
  ble-      .loc_0x584
  li        r0, 0x1
  b         .loc_0x630

.loc_0x584:
  sth       r3, 0x2E4(r30)
  lis       r29, 0x4330
  addi      r3, r30, 0x8
  lha       r0, 0x2E4(r30)
  lfd       f2, -0x4ED0(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4EA8(r2)
  add       r4, r30, r0
  lwz       r5, 0x68(r4)
  lha       r4, 0x18(r5)
  lha       r0, 0x1A(r5)
  xoris     r4, r4, 0x8000
  xoris     r0, r0, 0x8000
  stw       r4, 0x14C(r1)
  stw       r0, 0x154(r1)
  stw       r29, 0x148(r1)
  stw       r29, 0x150(r1)
  lfd       f1, 0x148(r1)
  lfd       f0, 0x150(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        0x49CAC
  lha       r0, 0x2E4(r30)
  addi      r3, r30, 0x38
  lfd       f2, -0x4ED0(r2)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4EA8(r2)
  add       r4, r30, r0
  lwz       r5, 0xE0(r4)
  lha       r4, 0x18(r5)
  lha       r0, 0x1A(r5)
  xoris     r4, r4, 0x8000
  xoris     r0, r0, 0x8000
  stw       r4, 0x15C(r1)
  stw       r0, 0x164(r1)
  stw       r29, 0x158(r1)
  stw       r29, 0x160(r1)
  lfd       f1, 0x158(r1)
  lfd       f0, 0x160(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        0x49C5C
  li        r0, 0

.loc_0x630:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x648
  lha       r3, 0x2E2(r30)
  subi      r0, r3, 0x1
  sth       r0, 0x2E2(r30)
  b         .loc_0x650

.loc_0x648:
  li        r3, 0x112
  bl        -0xEBBFC

.loc_0x650:
  addi      r3, r30, 0x8
  bl        0x4989C
  addi      r3, r30, 0x38
  bl        0x49894
  lwz       r3, 0x2D0(r30)
  bl        -0x11840

.loc_0x668:
  lwz       r3, 0x4(r30)
  bl        0x21BC0
  lwz       r3, 0x2D4(r30)
  mr        r4, r31
  bl        -0x1138
  stw       r3, 0x2D8(r30)
  lwz       r3, 0x2C4(r30)
  bl        0x21BA8
  lha       r3, 0x2E8(r30)
  li        r5, 0
  addi      r3, r3, 0x1
  cmpwi     r3, 0x1E
  rlwinm    r0,r3,2,0,29
  add       r6, r30, r0
  subfic    r3, r3, 0x1E
  bge-      .loc_0x760
  rlwinm.   r0,r3,29,3,31
  mtctr     r0
  beq-      .loc_0x744

.loc_0x6B4:
  lwz       r4, 0x248(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x24C(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x250(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x254(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x258(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x25C(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x260(r6)
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  lwz       r4, 0x264(r6)
  addi      r6, r6, 0x20
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  bdnz+     .loc_0x6B4
  andi.     r3, r3, 0x7
  beq-      .loc_0x760

.loc_0x744:
  mtctr     r3

.loc_0x748:
  lwz       r4, 0x248(r6)
  addi      r6, r6, 0x4
  lwz       r4, 0xE0(r4)
  lwz       r4, 0xC(r4)
  stb       r5, 0xF0(r4)
  bdnz+     .loc_0x748

.loc_0x760:
  lfs       f27, -0x4EB4(r2)
  mr        r28, r30
  lfs       f28, -0x4EA0(r2)
  li        r31, 0
  lfd       f29, -0x4ED0(r2)
  lfs       f30, -0x4E98(r2)
  lis       r29, 0x4330
  lfs       f31, -0x4E9C(r2)
  b         .loc_0x81C

.loc_0x784:
  lfs       f0, 0x2EC(r30)
  fcmpo     cr0, f0, f27
  fmr       f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x79C
  fsubs     f1, f1, f27

.loc_0x79C:
  xoris     r0, r31, 0x8000
  stw       r0, 0x14C(r1)
  stw       r29, 0x148(r1)
  lfd       f0, 0x148(r1)
  fsubs     f0, f0, f29
  fmuls     f0, f28, f0
  fsubs     f1, f1, f0
  fmuls     f1, f30, f1
  bl        0x8AC08
  lwz       r5, 0x1D0(r28)
  fmuls     f0, f31, f1
  addi      r31, r31, 0x1
  lha       r3, 0x18(r5)
  lha       r0, 0x1C(r5)
  fadds     f0, f27, f0
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
  lwz       r3, 0x1D0(r28)
  addi      r28, r28, 0x4
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)

.loc_0x81C:
  lha       r0, 0x2E8(r30)
  cmpw      r31, r0
  ble+      .loc_0x784
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0x3
  bne-      .loc_0x848
  lwz       r0, 0x2D8(r30)
  cmpwi     r0, 0
  bne-      .loc_0x848
  li        r0, 0
  stw       r0, 0x0(r30)

.loc_0x848:
  lwz       r3, 0x0(r30)

.loc_0x84C:
  lwz       r0, 0x1A4(r1)
  lfd       f31, 0x198(r1)
  lfd       f30, 0x190(r1)
  lfd       f29, 0x188(r1)
  lfd       f28, 0x180(r1)
  lfd       f27, 0x178(r1)
  lwz       r31, 0x174(r1)
  lwz       r30, 0x170(r1)
  lwz       r29, 0x16C(r1)
  lwz       r28, 0x168(r1)
  addi      r1, r1, 0x1A0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801911A4
 * Size:	0000F0
 */
void zen::ogDrawSelectDiary::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x108(r1)
  stw       r31, 0x104(r1)
  stw       r30, 0x100(r1)
  addi      r30, r4, 0
  stw       r29, 0xFC(r1)
  mr        r29, r3
  lwz       r0, 0x0(r3)
  cmpwi     r0, -0x1
  beq-      .loc_0xD4
  lfs       f1, -0x4E94(r2)
  addi      r3, r1, 0x10
  lfs       f2, -0x4EB4(r2)
  li        r4, 0
  lfs       f3, -0x4E90(r2)
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x1EFA0
  addi      r3, r1, 0x10
  bl        0x1F0A8
  lwz       r3, 0x4(r29)
  addi      r6, r1, 0x10
  li        r4, 0
  li        r5, 0
  bl        0x21CC8
  lwz       r31, 0x2D4(r29)
  lwz       r0, 0x8(r31)
  cmpwi     r0, 0
  beq-      .loc_0xA8
  lwz       r3, 0x10(r31)
  li        r4, 0
  li        r5, 0
  li        r6, 0
  bl        0x21CA4
  lwz       r3, 0x4(r31)
  mr        r4, r30
  bl        0x58970
  lwz       r3, 0x0(r31)
  mr        r4, r30
  bl        -0x1E08

.loc_0xA8:
  lwz       r3, 0x2C4(r29)
  addi      r6, r1, 0x10
  li        r4, 0
  li        r5, 0
  bl        0x21C78
  lis       r3, 0x802E
  addi      r0, r3, 0x698
  lis       r3, 0x802E
  stw       r0, 0x10(r1)
  addi      r0, r3, 0x5D4
  stw       r0, 0x10(r1)

.loc_0xD4:
  lwz       r0, 0x10C(r1)
  lwz       r31, 0x104(r1)
  lwz       r30, 0x100(r1)
  lwz       r29, 0xFC(r1)
  addi      r1, r1, 0x108
  mtlr      r0
  blr
*/
}
