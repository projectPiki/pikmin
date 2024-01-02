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
 * Address:	........
 * Size:	000054
 */
void MovieInfo::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void MovieInfo::setCamera(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void MovieInfo::refresh(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80076E34
 * Size:	0000BC
 */
MoviePlayer::MoviePlayer()
{
	/*
	.loc_0x0:
	  lis       r4, 0x8022
	  addi      r8, r4, 0x738C
	  lis       r4, 0x8022
	  stw       r8, 0x0(r3)
	  addi      r7, r4, 0x737C
	  stw       r7, 0x0(r3)
	  li        r6, 0
	  lis       r4, 0x802B
	  stw       r6, 0x10(r3)
	  subi      r5, r13, 0x6500
	  subi      r0, r4, 0x3754
	  stw       r6, 0xC(r3)
	  stw       r6, 0x8(r3)
	  stw       r5, 0x4(r3)
	  stw       r0, 0x0(r3)
	  stw       r6, 0x18(r3)
	  stw       r8, 0x60(r3)
	  stw       r7, 0x60(r3)
	  stw       r6, 0x70(r3)
	  stw       r6, 0x6C(r3)
	  stw       r6, 0x68(r3)
	  stw       r5, 0x64(r3)
	  stw       r0, 0x60(r3)
	  stw       r6, 0x78(r3)
	  stw       r8, 0xC0(r3)
	  stw       r7, 0xC0(r3)
	  stw       r6, 0xD0(r3)
	  stw       r6, 0xCC(r3)
	  stw       r6, 0xC8(r3)
	  stw       r5, 0xC4(r3)
	  stw       r0, 0xC0(r3)
	  stw       r6, 0xD8(r3)
	  lfs       f0, -0x7754(r2)
	  stfs      f0, 0x134(r3)
	  stfs      f0, 0x130(r3)
	  stfs      f0, 0x12C(r3)
	  stfs      f0, 0x140(r3)
	  stfs      f0, 0x13C(r3)
	  stfs      f0, 0x138(r3)
	  stfs      f0, 0x150(r3)
	  stfs      f0, 0x14C(r3)
	  stfs      f0, 0x148(r3)
	  stfs      f0, 0x15C(r3)
	  stfs      f0, 0x158(r3)
	  stfs      f0, 0x154(r3)
	  stfs      f0, 0x168(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80076EF0
 * Size:	0000E0
 */
void MoviePlayer::resetMovieList()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8022
	  stw       r0, 0x4(r1)
	  lis       r4, 0x8022
	  stwu      r1, -0x30(r1)
	  stmw      r25, 0x14(r1)
	  li        r26, 0
	  addi      r31, r3, 0
	  addi      r27, r5, 0x738C
	  addi      r28, r4, 0x737C
	  li        r25, 0
	  subi      r29, r13, 0x6500
	  stw       r26, 0x10(r3)
	  lis       r3, 0x802B
	  subi      r7, r3, 0x42F8
	  stw       r26, 0xC(r31)
	  lis       r3, 0x802B
	  addi      r0, r7, 0x98C
	  stw       r26, 0x8(r31)
	  addi      r6, r7, 0x998
	  subi      r30, r3, 0x3754
	  stw       r0, 0x4(r31)
	  addi      r0, r7, 0x9A4
	  stw       r26, 0x70(r31)
	  stw       r26, 0x6C(r31)
	  stw       r26, 0x68(r31)
	  stw       r6, 0x64(r31)
	  stw       r26, 0xD0(r31)
	  stw       r26, 0xCC(r31)
	  stw       r26, 0xC8(r31)
	  stw       r0, 0xC4(r31)

	.loc_0x7C:
	  li        r3, 0x60
	  bl        -0x2FF6C
	  cmplwi    r3, 0
	  beq-      .loc_0xAC
	  stw       r27, 0x0(r3)
	  stw       r28, 0x0(r3)
	  stw       r26, 0x10(r3)
	  stw       r26, 0xC(r3)
	  stw       r26, 0x8(r3)
	  stw       r29, 0x4(r3)
	  stw       r30, 0x0(r3)
	  stw       r26, 0x18(r3)

	.loc_0xAC:
	  addi      r4, r3, 0
	  addi      r3, r31, 0x60
	  bl        -0x369CC
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0xA
	  blt+      .loc_0x7C
	  li        r0, 0
	  stb       r0, 0x124(r31)
	  lmw       r25, 0x14(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80076FD0
 * Size:	000090
 */
void MoviePlayer::fixMovieList()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  subi      r31, r13, 0x6500
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  b         .loc_0x60

	.loc_0x2C:
	  lwz       r29, 0x10(r28)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        0x81C
	  mr        r3, r29
	  bl        -0x36A00
	  stw       r30, 0x10(r29)
	  addi      r4, r29, 0
	  addi      r3, r28, 0x60
	  stw       r30, 0xC(r29)
	  stw       r30, 0x8(r29)
	  stw       r31, 0x4(r29)
	  bl        -0x36A54

	.loc_0x60:
	  mr        r3, r28
	  bl        -0x369B4
	  cmpwi     r3, 0
	  bne+      .loc_0x2C
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
 * Address:	........
 * Size:	00003C
 */
void MoviePlayer::findMovie(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80077060
 * Size:	000100
 */
void MoviePlayer::initMovie(MovieInfo*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x40(r1)
	  stmw      r26, 0x28(r1)
	  addi      r29, r3, 0
	  mr        r30, r4
	  lwz       r5, 0x2DEC(r13)
	  lwzu      r3, 0x2A4(r5)
	  stw       r0, 0x0(r5)
	  neg       r4, r3
	  subic     r0, r4, 0x1
	  lwz       r3, 0x2DEC(r13)
	  subfe     r0, r0, r4
	  rlwinm    r28,r0,0,24,31
	  lwz       r27, 0x194(r3)
	  cmpwi     r27, 0x2
	  bne-      .loc_0x68
	  li        r4, 0x5
	  bl        -0x38044
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  bl        -0x38098
	  lwz       r31, 0x0(r3)
	  li        r0, 0x1
	  stw       r0, 0x0(r3)

	.loc_0x68:
	  li        r3, 0x2E8
	  bl        -0x300C8
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x84
	  lwz       r4, 0x4(r30)
	  bl        -0x7508

	.loc_0x84:
	  stw       r26, 0x18(r30)
	  lbz       r0, 0x16C(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0xB4
	  lwz       r3, 0x18(r30)
	  lwz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,22,22
	  beq-      .loc_0xB4
	  lfs       f0, -0x7750(r2)
	  li        r0, 0
	  stfs      f0, 0x164(r29)
	  stb       r0, 0x16C(r29)

	.loc_0xB4:
	  cmpwi     r27, 0x2
	  beq-      .loc_0xD8
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x5
	  bl        -0x38104
	  stw       r31, 0x0(r3)
	  mr        r4, r27
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x380CC

	.loc_0xD8:
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0
	  stw       r0, 0x2A0(r3)
	  lwz       r3, 0x2DEC(r13)
	  stw       r28, 0x2A4(r3)
	  lwz       r0, 0x44(r1)
	  lmw       r26, 0x28(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void MoviePlayer::translateIndex(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80077160
 * Size:	00049C
 */
void MoviePlayer::startMovie(int, int, Creature*, Vector3f*, Vector3f*, u32, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stmw      r23, 0x74(r1)
	  mr.       r28, r4
	  addi      r31, r3, 0
	  addi      r23, r6, 0
	  addi      r24, r7, 0
	  addi      r25, r8, 0
	  addi      r26, r9, 0
	  addi      r27, r10, 0
	  bge-      .loc_0x40
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        0xABC
	  b         .loc_0x488

	.loc_0x40:
	  cmpwi     r28, 0xC
	  bne-      .loc_0x70
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0
	  li        r5, 0x11
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x488

	.loc_0x70:
	  cmpwi     r28, 0x4A
	  bne-      .loc_0x94
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0x1
	  bl        0x7B7D8
	  cmplwi    r3, 0
	  beq-      .loc_0x488
	  addi      r24, r3, 0x94
	  addi      r25, r3, 0x88

	.loc_0x94:
	  cmpwi     r28, 0x4F
	  bne-      .loc_0xB4
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x1E0(r3)
	  cmpwi     r0, 0x5
	  bne-      .loc_0xB4
	  li        r28, 0x4E

	.loc_0xB4:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r4, 0xA8(r3)
	  lis       r3, 0x802B
	  subi      r3, r3, 0x381C
	  lhz       r0, 0x26(r4)
	  b         .loc_0xEC

	.loc_0xD0:
	  cmplw     r4, r28
	  bne-      .loc_0xE8
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r30, r3, r0
	  b         .loc_0xFC

	.loc_0xE8:
	  addi      r3, r3, 0x8

	.loc_0xEC:
	  lwz       r4, 0x0(r3)
	  cmplwi    r4, 0
	  bne+      .loc_0xD0
	  mr        r30, r28

	.loc_0xFC:
	  lis       r3, 0x802B
	  subi      r3, r3, 0x3C24
	  li        r29, 0
	  b         .loc_0x124

	.loc_0x10C:
	  lwz       r0, 0x0(r3)
	  cmpw      r0, r30
	  bne-      .loc_0x120
	  mr        r29, r3
	  b         .loc_0x130

	.loc_0x120:
	  addi      r3, r3, 0x8

	.loc_0x124:
	  lwz       r0, 0x4(r3)
	  cmplwi    r0, 0
	  bne+      .loc_0x10C

	.loc_0x130:
	  cmplwi    r29, 0
	  beq-      .loc_0x488
	  lwz       r3, 0x3178(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x148
	  bl        0x105C50

	.loc_0x148:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x174
	  lwz       r12, 0x0(r3)
	  li        r4, 0x3
	  li        r5, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x174:
	  li        r0, 0x1
	  stb       r0, 0x124(r31)
	  addi      r3, r31, 0x60
	  bl        -0x36C60
	  lwz       r28, 0x70(r31)
	  mr        r3, r28
	  bl        -0x36CDC
	  lwz       r4, 0x4(r29)
	  li        r3, 0
	  subi      r0, r30, 0x2C
	  stw       r3, 0x10(r28)
	  cmplwi    r0, 0x1
	  stw       r3, 0xC(r28)
	  stw       r3, 0x8(r28)
	  stw       r4, 0x4(r28)
	  stw       r30, 0x14(r28)
	  stw       r26, 0x5C(r28)
	  bgt-      .loc_0x1E0
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x200

	.loc_0x1E0:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x3C
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl

	.loc_0x200:
	  mr        r3, r31
	  bl        -0x36CE4
	  cmpwi     r3, 0
	  bne-      .loc_0x21C
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  bl        .loc_0x49C

	.loc_0x21C:
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  addi      r5, r30, 0
	  bl        -0x328
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x37D18
	  cmplwi    r24, 0
	  beq-      .loc_0x2C4
	  lwz       r3, 0x18(r28)
	  lwz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x2C4
	  cmplwi    r24, 0
	  beq-      .loc_0x26C
	  cmplwi    r25, 0

	.loc_0x26C:
	  cmplwi    r25, 0
	  beq-      .loc_0x27C
	  mr        r5, r25
	  b         .loc_0x298

	.loc_0x27C:
	  lfs       f0, -0x64F0(r13)
	  addi      r5, r1, 0x48
	  lfs       f1, -0x64EC(r13)
	  stfs      f0, 0x48(r1)
	  lfs       f0, -0x64E8(r13)
	  stfs      f1, 0x4C(r1)
	  stfs      f0, 0x50(r1)

	.loc_0x298:
	  lfs       f0, -0x64FC(r13)
	  addi      r4, r1, 0x54
	  lfs       f1, -0x64F8(r13)
	  addi      r6, r24, 0
	  stfs      f0, 0x54(r1)
	  lfs       f0, -0x64F4(r13)
	  addi      r3, r28, 0x1C
	  stfs      f1, 0x58(r1)
	  stfs      f0, 0x5C(r1)
	  bl        -0x39328
	  b         .loc_0x2CC

	.loc_0x2C4:
	  addi      r3, r28, 0x1C
	  bl        -0x3966C

	.loc_0x2CC:
	  lwz       r5, 0x18(r28)
	  mr        r3, r31
	  lwz       r4, 0x1C(r28)
	  li        r29, 0
	  lwz       r0, 0x20(r28)
	  stw       r4, 0x8(r5)
	  stw       r0, 0xC(r5)
	  lwz       r4, 0x24(r28)
	  lwz       r0, 0x28(r28)
	  stw       r4, 0x10(r5)
	  stw       r0, 0x14(r5)
	  lwz       r4, 0x2C(r28)
	  lwz       r0, 0x30(r28)
	  stw       r4, 0x18(r5)
	  stw       r0, 0x1C(r5)
	  lwz       r4, 0x34(r28)
	  lwz       r0, 0x38(r28)
	  stw       r4, 0x20(r5)
	  stw       r0, 0x24(r5)
	  lwz       r4, 0x3C(r28)
	  lwz       r0, 0x40(r28)
	  stw       r4, 0x28(r5)
	  stw       r0, 0x2C(r5)
	  lwz       r4, 0x44(r28)
	  lwz       r0, 0x48(r28)
	  stw       r4, 0x30(r5)
	  stw       r0, 0x34(r5)
	  lwz       r4, 0x4C(r28)
	  lwz       r0, 0x50(r28)
	  stw       r4, 0x38(r5)
	  stw       r0, 0x3C(r5)
	  lwz       r4, 0x54(r28)
	  lwz       r0, 0x58(r28)
	  stw       r4, 0x40(r5)
	  stw       r0, 0x44(r5)
	  lwz       r4, 0x18(r28)
	  stw       r23, 0x48(r4)
	  lwz       r4, 0x18(r28)
	  stb       r27, 0x2E5(r4)
	  bl        -0x36E48
	  cmpwi     r3, 0
	  bne-      .loc_0x37C
	  li        r29, 0x1
	  b         .loc_0x3C8

	.loc_0x37C:
	  lwz       r3, 0x18(r28)
	  lwz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,23,23
	  beq-      .loc_0x3C8
	  lwz       r5, 0xD0(r31)
	  li        r4, 0
	  b         .loc_0x3B4

	.loc_0x398:
	  lwz       r3, 0x18(r5)
	  lwz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,23,23
	  bne-      .loc_0x3B0
	  li        r4, 0x1
	  b         .loc_0x3BC

	.loc_0x3B0:
	  lwz       r5, 0xC(r5)

	.loc_0x3B4:
	  cmplwi    r5, 0
	  bne+      .loc_0x398

	.loc_0x3BC:
	  rlwinm.   r0,r4,0,24,31
	  bne-      .loc_0x3C8
	  li        r29, 0x1

	.loc_0x3C8:
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x428
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  bl        0x1C8
	  lwz       r3, 0x18(r28)
	  lwz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x3FC
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0x1
	  stw       r0, 0x33C(r3)

	.loc_0x3FC:
	  lwz       r3, 0x18(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x418
	  lfs       f0, -0x7758(r2)
	  stfs      f0, 0x2A0(r3)
	  lwz       r3, 0x18(r28)
	  bl        -0x6BFC

	.loc_0x418:
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  bl        -0x36FA8
	  b         .loc_0x434

	.loc_0x428:
	  addi      r3, r31, 0xC0
	  addi      r4, r28, 0
	  bl        -0x36FB8

	.loc_0x434:
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0x1
	  li        r4, 0x2
	  addi      r5, r3, 0x1C
	  lwz       r3, 0x1C(r3)
	  stw       r0, 0x0(r5)
	  neg       r5, r3
	  subic     r0, r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  subfe     r23, r0, r5
	  bl        -0x3859C
	  lwz       r5, 0x8(r3)
	  lis       r4, 0x4330
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r23,0,24,31
	  sub       r3, r3, r5
	  xoris     r5, r3, 0x8000
	  lwz       r3, 0x2DEC(r13)
	  stw       r5, 0x6C(r1)
	  stw       r4, 0x68(r1)
	  stw       r0, 0x1C(r3)

	.loc_0x488:
	  lmw       r23, 0x74(r1)
	  lwz       r0, 0x9C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr

	.loc_0x49C:
	*/
}

/*
 * --INFO--
 * Address:	800775FC
 * Size:	000104
 */
void MoviePlayer::sndStartMovie(MovieInfo*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r3, r3, 0x2848
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lha       r3, 0x1E0(r3)
	  bl        -0x5C29C
	  lwz       r6, 0x2F6C(r13)
	  li        r3, 0
	  li        r0, 0
	  cmplwi    r6, 0
	  li        r4, 0x1
	  beq-      .loc_0x50
	  lbz       r5, 0x184(r6)
	  slw       r0, r4, r0
	  and.      r0, r5, r0
	  beq-      .loc_0x50
	  li        r3, 0x1

	.loc_0x50:
	  cmplwi    r6, 0
	  li        r0, 0x1
	  beq-      .loc_0x70
	  lbz       r5, 0x184(r6)
	  slw       r0, r4, r0
	  and.      r0, r5, r0
	  beq-      .loc_0x70
	  addi      r3, r3, 0x1

	.loc_0x70:
	  cmplwi    r6, 0
	  li        r0, 0x2
	  beq-      .loc_0x90
	  lbz       r5, 0x184(r6)
	  slw       r0, r4, r0
	  and.      r0, r5, r0
	  beq-      .loc_0x90
	  addi      r3, r3, 0x1

	.loc_0x90:
	  bl        -0x5C2EC
	  lwz       r3, 0x3180(r13)
	  li        r0, 0
	  stb       r0, 0x6B0(r3)
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xB4
	  bl        0x95C8
	  b         .loc_0xB8

	.loc_0xB4:
	  mr        r3, r0

	.loc_0xB8:
	  bl        -0x5C2F4
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0
	  addi      r4, r3, 0x2A4
	  lwz       r3, 0x2A4(r3)
	  stw       r0, 0x0(r4)
	  neg       r3, r3
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  lwz       r3, 0x14(r31)
	  rlwinm    r31,r0,0,24,31
	  bl        -0x5D1C0
	  lwz       r3, 0x2DEC(r13)
	  stw       r31, 0x2A4(r3)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80077700
 * Size:	000124
 */
void MoviePlayer::initMovieFlags(MovieInfo*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r4, 0x18(r4)
	  lwz       r5, 0x0(r4)
	  lwz       r4, 0xC4(r4)
	  rlwinm    r0,r5,0,29,29
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r29, r0, r3
	  b         .loc_0x70

	.loc_0x44:
	  lwz       r3, 0x38(r4)
	  b         .loc_0x64

	.loc_0x4C:
	  lwz       r0, 0x68(r3)
	  andi.     r0, r0, 0x21
	  beq-      .loc_0x60
	  li        r29, 0
	  b         .loc_0x6C

	.loc_0x60:
	  lwz       r3, 0xC(r3)

	.loc_0x64:
	  cmplwi    r3, 0
	  bne+      .loc_0x4C

	.loc_0x6C:
	  lwz       r4, 0xC(r4)

	.loc_0x70:
	  cmplwi    r4, 0
	  bne+      .loc_0x44
	  rlwinm.   r0,r5,0,24,24
	  beq-      .loc_0x98
	  lwz       r30, 0x3180(r13)
	  li        r4, 0x1
	  addi      r3, r30, 0x14
	  bl        0x129D9C
	  mr        r3, r30
	  bl        0x125514

	.loc_0x98:
	  lwz       r3, 0x18(r31)
	  lwz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,9,9
	  beq-      .loc_0xB0
	  lfs       f0, -0x7750(r2)
	  stfs      f0, 0x168(r28)

	.loc_0xB0:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x104
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0xD4
	  lis       r6, 0x8000
	  b         .loc_0xD8

	.loc_0xD4:
	  li        r6, 0

	.loc_0xD8:
	  lwz       r5, 0x18(r31)
	  lis       r4, 0x36
	  lwz       r12, 0x0(r3)
	  subi      r0, r4, 0x384
	  lwz       r5, 0x0(r5)
	  lwz       r12, 0x8(r12)
	  li        r4, 0x7
	  and       r0, r5, r0
	  mtlr      r12
	  or        r5, r0, r6
	  blrl

	.loc_0x104:
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
 * Address:	........
 * Size:	000024
 */
void MoviePlayer::sndFrameMovie(MovieInfo*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80077824
 * Size:	000064
 */
void MoviePlayer::sndStopMovie(MovieInfo*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  bl        -0x5CA98
	  lwz       r4, 0x3180(r13)
	  li        r0, 0x1
	  lis       r3, 0x803A
	  stb       r0, 0x6B0(r4)
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  lwz       r12, 0x0(r3)
	  li        r4, 0x8
	  lwz       r5, 0x14(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x50:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80077888
 * Size:	0003CC
 */
void MoviePlayer::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x2848
	  li        r0, 0
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stfd      f30, 0x68(r1)
	  stfd      f29, 0x60(r1)
	  stfd      f28, 0x58(r1)
	  stfd      f27, 0x50(r1)
	  stfd      f26, 0x48(r1)
	  stfd      f25, 0x40(r1)
	  stmw      r25, 0x24(r1)
	  mr        r26, r3
	  addi      r30, r4, 0x1D8
	  stw       r0, 0x1D8(r4)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x258(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x39C
	  lbz       r0, 0x124(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0x90
	  lbz       r0, 0x125(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0x90
	  lwz       r3, 0x10(r26)
	  lfs       f0, -0x7754(r2)
	  lwz       r3, 0x18(r3)
	  lfsu      f1, 0x2A4(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x90
	  lfs       f0, -0x7750(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r3)

	.loc_0x90:
	  lis       r3, 0x803A
	  lwz       r27, 0x10(r26)
	  subi      r31, r3, 0x2848
	  lfs       f31, -0x7758(r2)
	  lfs       f27, -0x7744(r2)
	  addi      r29, r31, 0x1E8
	  lfs       f28, -0x7740(r2)
	  lfs       f25, -0x7754(r2)
	  lfs       f26, -0x774C(r2)
	  lfs       f29, -0x7750(r2)
	  lfs       f30, -0x7748(r2)
	  b         .loc_0x394

	.loc_0xC0:
	  lwz       r3, 0x18(r27)
	  lwz       r4, 0x0(r30)
	  lwz       r0, 0x0(r3)
	  lwz       r28, 0xC(r27)
	  andi.     r0, r0, 0x4FC
	  or        r0, r4, r0
	  stw       r0, 0x0(r30)
	  lfs       f1, 0x164(r26)
	  fcmpo     cr0, f1, f25
	  ble-      .loc_0x11C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f26, f0
	  fsubs     f0, f1, f0
	  stfs      f0, 0x164(r26)
	  lfs       f0, 0x164(r26)
	  fcmpo     cr0, f0, f25
	  bge-      .loc_0x11C
	  stfs      f25, 0x164(r26)
	  lwz       r3, 0x18(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x11C
	  stfs      f25, 0x2E0(r3)

	.loc_0x11C:
	  lwz       r3, 0x18(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x194
	  lfs       f0, 0x164(r26)
	  fcmpo     cr0, f0, f25
	  ble-      .loc_0x194
	  lfs       f0, 0x160(r26)
	  stfs      f0, 0x2DC(r3)
	  lwz       r4, 0x18(r27)
	  lwz       r3, 0x148(r26)
	  lwz       r0, 0x14C(r26)
	  stw       r3, 0x2B8(r4)
	  stw       r0, 0x2BC(r4)
	  lwz       r0, 0x150(r26)
	  stw       r0, 0x2C0(r4)
	  lwz       r4, 0x18(r27)
	  lwz       r3, 0x154(r26)
	  lwz       r0, 0x158(r26)
	  stw       r3, 0x2C4(r4)
	  stw       r0, 0x2C8(r4)
	  lwz       r0, 0x15C(r26)
	  stw       r0, 0x2CC(r4)
	  lfs       f0, 0x164(r26)
	  fmuls     f0, f27, f0
	  fsubs     f1, f0, f28
	  bl        0x1A42E0
	  fadds     f0, f29, f1
	  lwz       r3, 0x18(r27)
	  fmuls     f0, f30, f0
	  stfs      f0, 0x2E0(r3)

	.loc_0x194:
	  lwz       r3, 0x18(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x1E0
	  lwz       r0, 0x48(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1E0
	  lwz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,14,14
	  beq-      .loc_0x1E0
	  li        r0, 0x1
	  stb       r0, 0x2E4(r3)
	  lwz       r5, 0x18(r27)
	  lwz       r4, 0x48(r5)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x2D0(r5)
	  stw       r0, 0x2D4(r5)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x2D8(r5)

	.loc_0x1E0:
	  lwz       r0, 0x5C(r27)
	  li        r3, 0
	  stw       r0, 0x128(r26)
	  lwz       r4, 0x18(r27)
	  cmplwi    r4, 0
	  beq-      .loc_0x210
	  stfs      f31, 0x2A0(r4)
	  lwz       r3, 0x18(r27)
	  bl        -0x7110
	  neg       r3, r3
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3

	.loc_0x210:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x388
	  bl        -0x5CD00
	  lwz       r3, 0x3180(r13)
	  li        r0, 0x1
	  stb       r0, 0x6B0(r3)
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x24C
	  lwz       r12, 0x0(r3)
	  li        r4, 0x8
	  lwz       r5, 0x14(r27)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x24C:
	  mr        r3, r27
	  bl        -0x374C8
	  li        r5, 0
	  stw       r5, 0x10(r27)
	  subi      r0, r13, 0x6500
	  addi      r4, r27, 0
	  stw       r5, 0xC(r27)
	  addi      r3, r26, 0x60
	  stw       r5, 0x8(r27)
	  stw       r0, 0x4(r27)
	  bl        -0x37524
	  b         .loc_0x2F0

	.loc_0x27C:
	  lwz       r25, 0xD0(r26)
	  mr        r3, r25
	  bl        -0x374FC
	  li        r27, 0
	  stw       r27, 0x10(r25)
	  addi      r3, r26, 0
	  mr        r4, r25
	  stw       r27, 0xC(r25)
	  stw       r27, 0x8(r25)
	  bl        -0x52C
	  addi      r3, r26, 0
	  addi      r4, r25, 0
	  bl        -0x434
	  addi      r3, r26, 0
	  addi      r4, r25, 0
	  bl        -0x37568
	  lwz       r3, 0x18(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x2D4
	  stfs      f31, 0x2A0(r3)
	  lwz       r3, 0x18(r25)
	  bl        -0x71E0

	.loc_0x2D4:
	  lwz       r3, 0xD0(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x300
	  lwz       r3, 0x18(r3)
	  lwz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,23,23
	  beq-      .loc_0x300

	.loc_0x2F0:
	  addi      r3, r26, 0xC0
	  bl        -0x374FC
	  cmpwi     r3, 0
	  bne+      .loc_0x27C

	.loc_0x300:
	  mr        r3, r26
	  bl        -0x3750C
	  cmpwi     r3, 0
	  bne-      .loc_0x390
	  li        r0, 0
	  stb       r0, 0x124(r26)
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x340
	  lwz       r12, 0x0(r3)
	  li        r4, 0x4
	  li        r5, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x340:
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0x1
	  li        r4, 0x5
	  addi      r6, r3, 0x1C
	  lwz       r3, 0x1C(r3)
	  li        r5, 0x1
	  stw       r0, 0x0(r6)
	  neg       r6, r3
	  subic     r0, r6, 0x1
	  lwz       r3, 0x2DEC(r13)
	  subfe     r25, r0, r6
	  bl        -0x38BC0
	  lwz       r3, 0x2DEC(r13)
	  rlwinm    r4,r25,0,24,31
	  li        r0, 0
	  stw       r4, 0x1C(r3)
	  stw       r0, 0x33C(r31)
	  b         .loc_0x390

	.loc_0x388:
	  lwz       r3, 0x120(r26)
	  bl        -0x5D1B4

	.loc_0x390:
	  mr        r27, r28

	.loc_0x394:
	  cmplwi    r27, 0
	  bne+      .loc_0xC0

	.loc_0x39C:
	  lmw       r25, 0x24(r1)
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lfd       f30, 0x68(r1)
	  lfd       f29, 0x60(r1)
	  lfd       f28, 0x58(r1)
	  lfd       f27, 0x50(r1)
	  lfd       f26, 0x48(r1)
	  lfd       f25, 0x40(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80077C54
 * Size:	0000AC
 */
void MoviePlayer::skipScene(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  cmpwi     r29, 0x3
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  bne-      .loc_0x68
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x34:
	  lwz       r30, 0xD0(r28)
	  mr        r3, r30
	  bl        -0x37680
	  stw       r31, 0x10(r30)
	  addi      r4, r30, 0
	  addi      r3, r28, 0x60
	  stw       r31, 0xC(r30)
	  stw       r31, 0x8(r30)
	  bl        -0x376D0

	.loc_0x58:
	  addi      r3, r28, 0xC0
	  bl        -0x37630
	  cmpwi     r3, 0
	  bne+      .loc_0x34

	.loc_0x68:
	  lwz       r3, 0x10(r28)
	  b         .loc_0x84

	.loc_0x70:
	  lwz       r30, 0xC(r3)
	  mr        r4, r29
	  lwz       r3, 0x18(r3)
	  bl        -0x73DC
	  mr        r3, r30

	.loc_0x84:
	  cmplwi    r3, 0
	  bne+      .loc_0x70
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
 * Address:	80077D00
 * Size:	00001C
 */
void MoviePlayer::getLookAtPos(Vector3f&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x138(r3)
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x13C(r3)
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0x140(r3)
	  stfs      f0, 0x8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80077D1C
 * Size:	000100
 */
void MoviePlayer::setCamera(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  stw       r30, 0x20(r1)
	  li        r30, 0
	  stw       r29, 0x1C(r1)
	  stw       r28, 0x18(r1)
	  addi      r28, r4, 0
	  lwz       r5, 0x10(r3)
	  b         .loc_0x88

	.loc_0x30:
	  lwz       r3, 0x18(r5)
	  li        r0, 0
	  lwz       r29, 0xC(r5)
	  lwz       r4, 0x7C(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x80
	  mr        r3, r28
	  lwz       r4, 0x1C(r4)
	  lwz       r12, 0x3B4(r28)
	  addi      r4, r4, 0xA8
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E4(r28)
	  lfs       f1, 0x1C4(r3)
	  lfs       f2, 0x1CC(r3)
	  lfs       f3, 0x1D0(r3)
	  lfs       f4, 0x1D4(r3)
	  bl        -0x35140
	  li        r0, 0x1

	.loc_0x80:
	  or        r30, r30, r0
	  addi      r5, r29, 0

	.loc_0x88:
	  cmplwi    r5, 0
	  bne+      .loc_0x30
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0xDC
	  lwz       r3, 0x2E4(r28)
	  lfs       f0, 0x1CC(r3)
	  stfs      f0, 0x144(r31)
	  lwz       r4, 0x2E4(r28)
	  lwz       r3, 0x164(r4)
	  lwz       r0, 0x168(r4)
	  stw       r3, 0x12C(r31)
	  stw       r0, 0x130(r31)
	  lwz       r0, 0x16C(r4)
	  stw       r0, 0x134(r31)
	  lwz       r4, 0x2E4(r28)
	  lwz       r3, 0x170(r4)
	  lwz       r0, 0x174(r4)
	  stw       r3, 0x138(r31)
	  stw       r0, 0x13C(r31)
	  lwz       r0, 0x178(r4)
	  stw       r0, 0x140(r31)

	.loc_0xDC:
	  mr        r3, r30
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
 * Address:	80077E1C
 * Size:	000060
 */
void MoviePlayer::addLights(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lwz       r5, 0x10(r3)
	  b         .loc_0x40

	.loc_0x20:
	  lwz       r3, 0x18(r5)
	  lwz       r31, 0xC(r5)
	  lwz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,24,24
	  beq-      .loc_0x3C
	  mr        r4, r30
	  bl        -0x6F68

	.loc_0x3C:
	  mr        r5, r31

	.loc_0x40:
	  cmplwi    r5, 0
	  bne+      .loc_0x20
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
 * Address:	80077E7C
 * Size:	000074
 */
void MoviePlayer::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r4, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0x1
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x10(r31)
	  b         .loc_0x54

	.loc_0x40:
	  lwz       r31, 0xC(r3)
	  mr        r4, r30
	  lwz       r3, 0x18(r3)
	  bl        -0x6F18
	  mr        r3, r31

	.loc_0x54:
	  cmplwi    r3, 0
	  bne+      .loc_0x40
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
 * Address:	........
 * Size:	00001C
 */
void MoviePlayer::nextFrame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void MoviePlayer::backFrame()
{
	// UNUSED FUNCTION
}
