#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80053C5C
 * Size:	000040
 */
void PlayState::openStage(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  bltlr-
	  cmpwi     r4, 0x5
	  bgtlr-
	  li        r0, 0x1
	  lwz       r5, 0x24(r3)
	  slw       r6, r0, r4
	  and.      r0, r5, r6
	  bne-      .loc_0x30
	  lis       r5, 0x803A
	  subi      r5, r5, 0x2848
	  stw       r4, 0x1D0(r5)

	.loc_0x30:
	  lwz       r0, 0x24(r3)
	  or        r0, r0, r6
	  stw       r0, 0x24(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80053C9C
 * Size:	000040
 */
void GamePrefs::setBgmVol(unsigned char)
{
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm    r5,r4,0,24,31
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x1C(r3)
	  cmplw     r5, r0
	  beq-      .loc_0x24
	  li        r0, 0x1
	  stb       r0, 0x14(r3)

	.loc_0x24:
	  stb       r4, 0x1C(r3)
	  lbz       r3, 0x1C(r3)
	  bl        -0x3D3A8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80053CDC
 * Size:	000040
 */
void GamePrefs::setSfxVol(unsigned char)
{
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm    r5,r4,0,24,31
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x1D(r3)
	  cmplw     r5, r0
	  beq-      .loc_0x24
	  li        r0, 0x1
	  stb       r0, 0x14(r3)

	.loc_0x24:
	  stb       r4, 0x1D(r3)
	  lbz       r3, 0x1D(r3)
	  bl        -0x3D3C8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80053D1C
 * Size:	00009C
 */
void GamePrefs::setStereoMode(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm    r5,r4,0,24,31
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  lwz       r0, 0x18(r3)
	  rlwinm    r0,r0,0,30,30
	  neg       r4, r0
	  subic     r0, r4, 0x1
	  subfe     r0, r0, r4
	  rlwinm    r0,r0,0,24,31
	  cmplw     r5, r0
	  beq-      .loc_0x40
	  li        r0, 0x1
	  stb       r0, 0x14(r3)

	.loc_0x40:
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x50
	  li        r4, 0x2
	  b         .loc_0x54

	.loc_0x50:
	  li        r4, 0

	.loc_0x54:
	  lwz       r0, 0x18(r3)
	  rlwinm    r0,r0,0,31,29
	  or        r0, r0, r4
	  stw       r0, 0x18(r3)
	  lwz       r0, 0x18(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x78
	  li        r3, 0x1
	  b         .loc_0x7C

	.loc_0x78:
	  li        r3, 0

	.loc_0x7C:
	  bl        -0x3D498
	  rlwinm    r3,r31,0,24,31
	  bl        0x1A7040
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80053DB8
 * Size:	0000B8
 */
void GamePrefs::setVibeMode(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  rlwinm    r4,r4,0,24,31
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r0, 0x18(r3)
	  rlwinm    r0,r0,0,31,31
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  rlwinm    r0,r0,0,24,31
	  cmplw     r4, r0
	  beq-      .loc_0x70
	  cmplwi    r4, 0
	  beq-      .loc_0x60
	  lwz       r3, 0x3178(r13)
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  bl        0x128F38
	  b         .loc_0x68

	.loc_0x60:
	  lwz       r3, 0x3178(r13)
	  bl        0x1290D8

	.loc_0x68:
	  li        r0, 0x1
	  stb       r0, 0x14(r30)

	.loc_0x70:
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x80
	  li        r3, 0x1
	  b         .loc_0x84

	.loc_0x80:
	  li        r3, 0

	.loc_0x84:
	  lwz       r0, 0x18(r30)
	  addi      r4, r31, 0
	  rlwinm    r0,r0,0,0,30
	  or        r0, r0, r3
	  stw       r0, 0x18(r30)
	  lwz       r3, 0x3178(r13)
	  bl        0x129510
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
 * Address:	80053E70
 * Size:	000054
 */
void GamePrefs::setChildMode(bool)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x18(r3)
	  rlwinm    r6,r4,0,24,31
	  rlwinm    r0,r0,0,29,29
	  neg       r5, r0
	  subic     r0, r5, 0x1
	  subfe     r0, r0, r5
	  rlwinm    r0,r0,0,24,31
	  cmplw     r6, r0
	  beq-      .loc_0x2C
	  li        r0, 0x1
	  stb       r0, 0x14(r3)

	.loc_0x2C:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x3C
	  li        r4, 0x4
	  b         .loc_0x40

	.loc_0x3C:
	  li        r4, 0

	.loc_0x40:
	  lwz       r0, 0x18(r3)
	  rlwinm    r0,r0,0,30,28
	  or        r0, r0, r4
	  stw       r0, 0x18(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80053EC4
 * Size:	000068
 */
void GamePrefs::getChallengeScores(GameChalQuickInfo&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  mulli     r0, r0, 0x14
	  add       r5, r3, r0
	  lwz       r0, 0x78(r5)
	  stw       r0, 0xC(r4)
	  lwz       r0, 0x0(r4)
	  mulli     r0, r0, 0x14
	  add       r5, r3, r0
	  lwz       r0, 0x7C(r5)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0x0(r4)
	  mulli     r0, r0, 0x14
	  add       r5, r3, r0
	  lwz       r0, 0x80(r5)
	  stw       r0, 0x14(r4)
	  lwz       r0, 0x0(r4)
	  mulli     r0, r0, 0x14
	  add       r5, r3, r0
	  lwz       r0, 0x84(r5)
	  stw       r0, 0x18(r4)
	  lwz       r0, 0x0(r4)
	  mulli     r0, r0, 0x14
	  add       r3, r3, r0
	  lwz       r0, 0x88(r3)
	  stw       r0, 0x1C(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80053F2C
 * Size:	000174
 */
void GamePrefs::checkIsHiscore(GameChalQuickInfo&)
{
	/*
	.loc_0x0:
	  li        r0, -0x1
	  stw       r0, 0x8(r4)
	  li        r0, 0x1
	  li        r7, 0
	  lwz       r5, 0x2DEC(r13)
	  stw       r0, 0x1C(r5)
	  lwz       r0, 0x0(r4)
	  lwz       r5, 0x4(r4)
	  mulli     r0, r0, 0x14
	  add       r6, r3, r0
	  lwz       r0, 0x78(r6)
	  cmplw     r5, r0
	  ble-      .loc_0x3C
	  stw       r7, 0x8(r4)
	  b         .loc_0x98

	.loc_0x3C:
	  lwz       r0, 0x7C(r6)
	  li        r7, 0x1
	  cmplw     r5, r0
	  ble-      .loc_0x54
	  stw       r7, 0x8(r4)
	  b         .loc_0x98

	.loc_0x54:
	  lwz       r0, 0x80(r6)
	  li        r7, 0x2
	  cmplw     r5, r0
	  ble-      .loc_0x6C
	  stw       r7, 0x8(r4)
	  b         .loc_0x98

	.loc_0x6C:
	  lwz       r0, 0x84(r6)
	  li        r7, 0x3
	  cmplw     r5, r0
	  ble-      .loc_0x84
	  stw       r7, 0x8(r4)
	  b         .loc_0x98

	.loc_0x84:
	  lwz       r0, 0x88(r6)
	  li        r7, 0x4
	  cmplw     r5, r0
	  ble-      .loc_0x98
	  stw       r7, 0x8(r4)

	.loc_0x98:
	  lwz       r0, 0x8(r4)
	  cmpwi     r0, 0
	  blt-      .loc_0x100
	  cmpwi     r0, 0x5
	  bge-      .loc_0x100
	  li        r7, 0x4
	  li        r5, 0x10
	  b         .loc_0xD8

	.loc_0xB8:
	  lwz       r0, 0x0(r4)
	  subi      r7, r7, 0x1
	  mulli     r0, r0, 0x14
	  add       r6, r0, r5
	  add       r6, r3, r6
	  lwz       r0, 0x74(r6)
	  subi      r5, r5, 0x4
	  stw       r0, 0x78(r6)

	.loc_0xD8:
	  lwz       r0, 0x8(r4)
	  cmpw      r7, r0
	  bgt+      .loc_0xB8
	  lwz       r5, 0x0(r4)
	  rlwinm    r0,r0,2,0,29
	  lwz       r6, 0x4(r4)
	  mulli     r5, r5, 0x14
	  add       r5, r3, r5
	  add       r5, r5, r0
	  stw       r6, 0x78(r5)

	.loc_0x100:
	  lwz       r5, 0x2DEC(r13)
	  li        r0, 0
	  stw       r0, 0x1C(r5)
	  lwz       r0, 0x0(r4)
	  mulli     r0, r0, 0x14
	  add       r5, r3, r0
	  lwz       r0, 0x78(r5)
	  stw       r0, 0xC(r4)
	  lwz       r0, 0x0(r4)
	  mulli     r0, r0, 0x14
	  add       r5, r3, r0
	  lwz       r0, 0x7C(r5)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0x0(r4)
	  mulli     r0, r0, 0x14
	  add       r5, r3, r0
	  lwz       r0, 0x80(r5)
	  stw       r0, 0x14(r4)
	  lwz       r0, 0x0(r4)
	  mulli     r0, r0, 0x14
	  add       r5, r3, r0
	  lwz       r0, 0x84(r5)
	  stw       r0, 0x18(r4)
	  lwz       r0, 0x0(r4)
	  mulli     r0, r0, 0x14
	  add       r3, r3, r0
	  lwz       r0, 0x88(r3)
	  stw       r0, 0x1C(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800540A0
 * Size:	00034C
 */
void GamePrefs::checkIsHiscore(GameQuickInfo&)
{
	/*
	.loc_0x0:
	  li        r0, -0x1
	  stw       r0, 0x14(r4)
	  li        r7, 0
	  stw       r0, 0x18(r4)
	  stw       r0, 0x10(r4)
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x28(r3)
	  cmplw     r5, r0
	  ble-      .loc_0x2C
	  stw       r7, 0x10(r4)
	  b         .loc_0x134

	.loc_0x2C:
	  bne-      .loc_0x48
	  lwz       r5, 0x4(r4)
	  lwz       r0, 0x2C(r3)
	  cmplw     r5, r0
	  bgt-      .loc_0x48
	  stw       r7, 0x10(r4)
	  b         .loc_0x134

	.loc_0x48:
	  addi      r6, r3, 0x8
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x30(r3)
	  li        r7, 0x1
	  cmplw     r5, r0
	  ble-      .loc_0x68
	  stw       r7, 0x10(r4)
	  b         .loc_0x134

	.loc_0x68:
	  bne-      .loc_0x84
	  lwz       r5, 0x4(r4)
	  lwz       r0, 0x2C(r6)
	  cmplw     r5, r0
	  bgt-      .loc_0x84
	  stw       r7, 0x10(r4)
	  b         .loc_0x134

	.loc_0x84:
	  lwz       r0, 0x30(r6)
	  li        r7, 0x2
	  lwz       r5, 0x0(r4)
	  addi      r6, r6, 0x8
	  cmplw     r5, r0
	  ble-      .loc_0xA4
	  stw       r7, 0x10(r4)
	  b         .loc_0x134

	.loc_0xA4:
	  bne-      .loc_0xC0
	  lwz       r5, 0x4(r4)
	  lwz       r0, 0x2C(r6)
	  cmplw     r5, r0
	  bgt-      .loc_0xC0
	  stw       r7, 0x10(r4)
	  b         .loc_0x134

	.loc_0xC0:
	  lwz       r0, 0x30(r6)
	  li        r7, 0x3
	  lwz       r5, 0x0(r4)
	  addi      r6, r6, 0x8
	  cmplw     r5, r0
	  ble-      .loc_0xE0
	  stw       r7, 0x10(r4)
	  b         .loc_0x134

	.loc_0xE0:
	  bne-      .loc_0xFC
	  lwz       r5, 0x4(r4)
	  lwz       r0, 0x2C(r6)
	  cmplw     r5, r0
	  bgt-      .loc_0xFC
	  stw       r7, 0x10(r4)
	  b         .loc_0x134

	.loc_0xFC:
	  lwz       r0, 0x30(r6)
	  li        r7, 0x4
	  lwz       r5, 0x0(r4)
	  addi      r6, r6, 0x8
	  cmplw     r5, r0
	  ble-      .loc_0x11C
	  stw       r7, 0x10(r4)
	  b         .loc_0x134

	.loc_0x11C:
	  bne-      .loc_0x134
	  lwz       r5, 0x4(r4)
	  lwz       r0, 0x2C(r6)
	  cmplw     r5, r0
	  bgt-      .loc_0x134
	  stw       r7, 0x10(r4)

	.loc_0x134:
	  lwz       r0, 0x10(r4)
	  cmpwi     r0, 0
	  blt-      .loc_0x19C
	  cmpwi     r0, 0x5
	  bge-      .loc_0x19C
	  addi      r5, r3, 0x20
	  li        r6, 0x4
	  b         .loc_0x16C

	.loc_0x154:
	  lwz       r0, 0x24(r5)
	  subi      r6, r6, 0x1
	  stw       r0, 0x2C(r5)
	  lwz       r0, 0x20(r5)
	  stw       r0, 0x28(r5)
	  subi      r5, r5, 0x8

	.loc_0x16C:
	  lwz       r0, 0x10(r4)
	  cmpw      r6, r0
	  bgt+      .loc_0x154
	  rlwinm    r0,r0,3,0,28
	  lwz       r6, 0x4(r4)
	  add       r5, r3, r0
	  stw       r6, 0x2C(r5)
	  lwz       r0, 0x10(r4)
	  lwz       r6, 0x0(r4)
	  rlwinm    r0,r0,3,0,28
	  add       r5, r3, r0
	  stw       r6, 0x28(r5)

	.loc_0x19C:
	  lwz       r5, 0x8(r4)
	  li        r7, 0
	  lwz       r0, 0x50(r3)
	  cmplw     r5, r0
	  ble-      .loc_0x1B8
	  stw       r7, 0x14(r4)
	  b         .loc_0x220

	.loc_0x1B8:
	  addi      r6, r3, 0x4
	  lwz       r0, 0x54(r3)
	  li        r7, 0x1
	  cmplw     r5, r0
	  ble-      .loc_0x1D4
	  stw       r7, 0x14(r4)
	  b         .loc_0x220

	.loc_0x1D4:
	  lwz       r0, 0x54(r6)
	  li        r7, 0x2
	  addi      r6, r6, 0x4
	  cmplw     r5, r0
	  ble-      .loc_0x1F0
	  stw       r7, 0x14(r4)
	  b         .loc_0x220

	.loc_0x1F0:
	  lwz       r0, 0x54(r6)
	  li        r7, 0x3
	  addi      r6, r6, 0x4
	  cmplw     r5, r0
	  ble-      .loc_0x20C
	  stw       r7, 0x14(r4)
	  b         .loc_0x220

	.loc_0x20C:
	  lwz       r0, 0x54(r6)
	  li        r7, 0x4
	  cmplw     r5, r0
	  ble-      .loc_0x220
	  stw       r7, 0x14(r4)

	.loc_0x220:
	  lwz       r0, 0x14(r4)
	  cmpwi     r0, 0
	  blt-      .loc_0x26C
	  cmpwi     r0, 0x5
	  bge-      .loc_0x26C
	  addi      r5, r3, 0x10
	  li        r6, 0x4
	  b         .loc_0x250

	.loc_0x240:
	  lwz       r0, 0x4C(r5)
	  subi      r6, r6, 0x1
	  stw       r0, 0x50(r5)
	  subi      r5, r5, 0x4

	.loc_0x250:
	  lwz       r0, 0x14(r4)
	  cmpw      r6, r0
	  bgt+      .loc_0x240
	  rlwinm    r0,r0,2,0,29
	  lwz       r6, 0x8(r4)
	  add       r5, r3, r0
	  stw       r6, 0x50(r5)

	.loc_0x26C:
	  lwz       r0, 0x0(r4)
	  cmplwi    r0, 0x1E
	  bne-      .loc_0x2FC
	  lwz       r5, 0xC(r4)
	  li        r7, 0
	  lwz       r0, 0x64(r3)
	  cmplw     r5, r0
	  bge-      .loc_0x294
	  stw       r7, 0x18(r4)
	  b         .loc_0x2FC

	.loc_0x294:
	  addi      r6, r3, 0x4
	  lwz       r0, 0x68(r3)
	  li        r7, 0x1
	  cmplw     r5, r0
	  bge-      .loc_0x2B0
	  stw       r7, 0x18(r4)
	  b         .loc_0x2FC

	.loc_0x2B0:
	  lwz       r0, 0x68(r6)
	  li        r7, 0x2
	  addi      r6, r6, 0x4
	  cmplw     r5, r0
	  bge-      .loc_0x2CC
	  stw       r7, 0x18(r4)
	  b         .loc_0x2FC

	.loc_0x2CC:
	  lwz       r0, 0x68(r6)
	  li        r7, 0x3
	  addi      r6, r6, 0x4
	  cmplw     r5, r0
	  bge-      .loc_0x2E8
	  stw       r7, 0x18(r4)
	  b         .loc_0x2FC

	.loc_0x2E8:
	  lwz       r0, 0x68(r6)
	  li        r7, 0x4
	  cmplw     r5, r0
	  bge-      .loc_0x2FC
	  stw       r7, 0x18(r4)

	.loc_0x2FC:
	  lwz       r0, 0x18(r4)
	  cmpwi     r0, 0
	  bltlr-
	  cmpwi     r0, 0x5
	  bgelr-
	  addi      r5, r3, 0x10
	  li        r6, 0x4
	  b         .loc_0x32C

	.loc_0x31C:
	  lwz       r0, 0x60(r5)
	  subi      r6, r6, 0x1
	  stw       r0, 0x64(r5)
	  subi      r5, r5, 0x4

	.loc_0x32C:
	  lwz       r0, 0x18(r4)
	  cmpw      r6, r0
	  bgt+      .loc_0x31C
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0xC(r4)
	  add       r3, r3, r0
	  stw       r4, 0x64(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800543EC
 * Size:	000178
 */
void GamePrefs::write(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r24, 0x10(r1)
	  addi      r25, r4, 0
	  addi      r24, r3, 0
	  addi      r3, r25, 0
	  lwz       r12, 0x4(r25)
	  lwz       r4, 0x18(r24)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r25
	  lbz       r4, 0x1C(r24)
	  lwz       r12, 0x4(r25)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r25
	  lbz       r4, 0x1D(r24)
	  lwz       r12, 0x4(r25)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r25
	  lbz       r4, 0x22(r24)
	  lwz       r12, 0x4(r25)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r25
	  lwz       r4, 0x24(r24)
	  lwz       r12, 0x4(r25)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  addi      r26, r24, 0x24
	  addi      r28, r26, 0
	  addi      r27, r26, 0
	  li        r31, 0

	.loc_0xA0:
	  mr        r3, r25
	  lwz       r12, 0x4(r25)
	  addi      r30, r26, 0x4
	  lwz       r4, 0x4(r26)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r25
	  lwz       r4, 0x4(r30)
	  lwz       r12, 0x4(r25)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r25
	  lwz       r12, 0x4(r25)
	  addi      r4, r28, 0x2C
	  lwz       r4, 0x0(r4)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r25
	  lwz       r12, 0x4(r25)
	  addi      r4, r28, 0x40
	  lwz       r4, 0x0(r4)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  li        r30, 0
	  addi      r3, r27, 0x54
	  rlwinm    r0,r30,2,0,29
	  add       r29, r3, r0

	.loc_0x11C:
	  mr        r3, r25
	  lwz       r4, 0x0(r29)
	  lwz       r12, 0x4(r25)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x5
	  addi      r29, r29, 0x4
	  blt+      .loc_0x11C
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x5
	  addi      r26, r26, 0x8
	  addi      r28, r28, 0x4
	  addi      r27, r27, 0x14
	  blt+      .loc_0xA0
	  li        r0, 0
	  stb       r0, 0x14(r24)
	  lmw       r24, 0x10(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80054564
 * Size:	0000B8
 */
void GamePrefs::fixSoundMode()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  bl        0x1A67E4
	  bl        0x1A67E0
	  lwz       r0, 0x18(r30)
	  neg       r4, r3
	  subic     r3, r4, 0x1
	  rlwinm    r0,r0,0,30,30
	  subfe     r4, r3, r4
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  rlwinm    r31,r4,0,24,31
	  rlwinm    r0,r0,0,24,31
	  cmplw     r31, r0
	  beq-      .loc_0x58
	  li        r0, 0x1
	  stb       r0, 0x14(r30)

	.loc_0x58:
	  cmplwi    r31, 0
	  beq-      .loc_0x68
	  li        r3, 0x2
	  b         .loc_0x6C

	.loc_0x68:
	  li        r3, 0

	.loc_0x6C:
	  lwz       r0, 0x18(r30)
	  rlwinm    r0,r0,0,31,29
	  or        r0, r0, r3
	  stw       r0, 0x18(r30)
	  lwz       r0, 0x18(r30)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x90
	  li        r3, 0x1
	  b         .loc_0x94

	.loc_0x90:
	  li        r3, 0

	.loc_0x94:
	  bl        -0x3DCF8
	  mr        r3, r31
	  bl        0x1A67E0
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
 * Address:	8005461C
 * Size:	000330
 */
void GamePrefs::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r24, 0x30(r1)
	  addi      r24, r4, 0
	  addi      r31, r3, 0
	  addi      r3, r24, 0
	  lwz       r12, 0x4(r24)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x18(r31)
	  mr        r3, r24
	  lwz       r12, 0x4(r24)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x1C(r31)
	  mr        r3, r24
	  lwz       r12, 0x4(r24)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x1D(r31)
	  mr        r3, r24
	  lwz       r12, 0x4(r24)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x22(r31)
	  mr        r3, r24
	  lwz       r12, 0x4(r24)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r25, r31, 0x24
	  stw       r3, 0x24(r31)
	  addi      r27, r31, 0
	  addi      r26, r25, 0
	  li        r30, 0

	.loc_0xA0:
	  mr        r3, r24
	  lwz       r12, 0x4(r24)
	  addi      r29, r25, 0x4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r29)
	  mr        r3, r24
	  lwz       r12, 0x4(r24)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x4(r29)
	  mr        r3, r24
	  lwz       r12, 0x4(r24)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x50(r27)
	  mr        r3, r24
	  lwz       r12, 0x4(r24)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x64(r27)
	  addi      r28, r26, 0x54
	  li        r29, 0

	.loc_0x10C:
	  mr        r3, r24
	  lwz       r12, 0x4(r24)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r29, 0x1
	  stw       r3, 0x0(r28)
	  cmpwi     r29, 0x5
	  addi      r28, r28, 0x4
	  blt+      .loc_0x10C
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x5
	  addi      r25, r25, 0x8
	  addi      r27, r27, 0x4
	  addi      r26, r26, 0x14
	  blt+      .loc_0xA0
	  bl        0x1A65F8
	  bl        0x1A65F4
	  lwz       r0, 0x18(r31)
	  neg       r4, r3
	  subic     r3, r4, 0x1
	  rlwinm    r0,r0,0,30,30
	  subfe     r4, r3, r4
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  rlwinm    r30,r4,0,24,31
	  rlwinm    r0,r0,0,24,31
	  cmplw     r30, r0
	  beq-      .loc_0x18C
	  li        r0, 0x1
	  stb       r0, 0x14(r31)

	.loc_0x18C:
	  cmplwi    r30, 0
	  beq-      .loc_0x19C
	  li        r3, 0x2
	  b         .loc_0x1A0

	.loc_0x19C:
	  li        r3, 0

	.loc_0x1A0:
	  lwz       r0, 0x18(r31)
	  rlwinm    r0,r0,0,31,29
	  or        r0, r0, r3
	  stw       r0, 0x18(r31)
	  lwz       r0, 0x18(r31)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x1C4
	  li        r3, 0x1
	  b         .loc_0x1C8

	.loc_0x1C4:
	  li        r3, 0

	.loc_0x1C8:
	  bl        -0x3DEE4
	  mr        r3, r30
	  bl        0x1A65F4
	  lbz       r3, 0x1C(r31)
	  cmplw     r3, r3
	  beq-      .loc_0x1E8
	  li        r0, 0x1
	  stb       r0, 0x14(r31)

	.loc_0x1E8:
	  stb       r3, 0x1C(r31)
	  lbz       r3, 0x1C(r31)
	  bl        -0x3DEEC
	  lbz       r3, 0x1D(r31)
	  cmplw     r3, r3
	  beq-      .loc_0x208
	  li        r0, 0x1
	  stb       r0, 0x14(r31)

	.loc_0x208:
	  stb       r3, 0x1D(r31)
	  lbz       r3, 0x1D(r31)
	  bl        -0x3DEEC
	  lwz       r0, 0x18(r31)
	  rlwinm    r0,r0,0,30,30
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r29, r0, r3
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  rlwinm    r3,r29,0,24,31
	  rlwinm    r0,r0,0,24,31
	  cmplw     r3, r0
	  beq-      .loc_0x248
	  li        r0, 0x1
	  stb       r0, 0x14(r31)

	.loc_0x248:
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x258
	  li        r3, 0x2
	  b         .loc_0x25C

	.loc_0x258:
	  li        r3, 0

	.loc_0x25C:
	  lwz       r0, 0x18(r31)
	  rlwinm    r0,r0,0,31,29
	  or        r0, r0, r3
	  stw       r0, 0x18(r31)
	  lwz       r0, 0x18(r31)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x280
	  li        r3, 0x1
	  b         .loc_0x284

	.loc_0x280:
	  li        r3, 0

	.loc_0x284:
	  bl        -0x3DFA0
	  rlwinm    r3,r29,0,24,31
	  bl        0x1A6538
	  lwz       r0, 0x18(r31)
	  rlwinm    r0,r0,0,31,31
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r29, r0, r3
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  rlwinm    r3,r29,0,24,31
	  rlwinm    r0,r0,0,24,31
	  cmplw     r3, r0
	  beq-      .loc_0x2EC
	  cmplwi    r3, 0
	  beq-      .loc_0x2DC
	  lwz       r3, 0x3178(r13)
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  bl        0x128458
	  b         .loc_0x2E4

	.loc_0x2DC:
	  lwz       r3, 0x3178(r13)
	  bl        0x1285F8

	.loc_0x2E4:
	  li        r0, 0x1
	  stb       r0, 0x14(r31)

	.loc_0x2EC:
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x2FC
	  li        r3, 0x1
	  b         .loc_0x300

	.loc_0x2FC:
	  li        r3, 0

	.loc_0x300:
	  lwz       r0, 0x18(r31)
	  addi      r4, r29, 0
	  rlwinm    r0,r0,0,0,30
	  or        r0, r0, r3
	  stw       r0, 0x18(r31)
	  lwz       r3, 0x3178(r13)
	  bl        0x128A30
	  lmw       r24, 0x30(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005494C
 * Size:	0000F4
 */
void PlayState::write(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x4(r31)
	  lbz       r4, 0x20(r30)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x23(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x21(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x22(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x14(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x18(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x1C(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x24(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
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
 * Address:	80054A40
 * Size:	0000F4
 */
void PlayState::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x20(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x23(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x21(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x22(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x14(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x18(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x1C(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x24(r30)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
