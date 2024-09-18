#include "GameCoreSection.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8010CE6C
 * Size:	000040
 */
void GameCoreSection::startTextDemo(Creature*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  mr        r5, r4
	  subi      r3, r3, 0x2848
	  stwu      r1, -0x8(r1)
	  li        r4, 0
	  lwz       r3, 0x1E8(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
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
 * Address:	8010CEAC
 * Size:	0000EC
 */
void GameCoreSection::updateTextDemo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  subi      r31, r3, 0x2848
	  lwz       r0, 0x338(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0xD8
	  lwz       r0, 0x30CC(r13)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x4C
	  bge-      .loc_0x40
	  cmpwi     r0, 0x1
	  bge-      .loc_0x68
	  b         .loc_0xD8

	.loc_0x40:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xD8
	  b         .loc_0xB0

	.loc_0x4C:
	  li        r0, 0x3C
	  lwz       r3, 0x2F20(r13)
	  sth       r0, 0x30D0(r13)
	  bl        -0x93AA0
	  li        r0, 0x3
	  stw       r0, 0x30CC(r13)
	  b         .loc_0xD8

	.loc_0x68:
	  lhz       r4, 0x30D0(r13)
	  lwz       r3, 0x2F20(r13)
	  subi      r0, r4, 0x1
	  sth       r0, 0x30D0(r13)
	  bl        -0x93A70
	  lhz       r0, 0x30D0(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0xD8
	  lwz       r3, 0x1E8(r31)
	  li        r4, 0
	  lwz       r5, 0x30D4(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x2
	  stw       r0, 0x30CC(r13)
	  b         .loc_0xD8

	.loc_0xB0:
	  lhz       r4, 0x30D0(r13)
	  lwz       r3, 0x2F20(r13)
	  subi      r0, r4, 0x1
	  sth       r0, 0x30D0(r13)
	  bl        -0x93AB8
	  lhz       r0, 0x30D0(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0xD8
	  li        r0, 0
	  stw       r0, 0x30CC(r13)

	.loc_0xD8:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010CF98
 * Size:	000464
 */
void GameCoreSection::startMovie(u32, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,11,11
	  stwu      r1, -0xC0(r1)
	  stmw      r25, 0xA4(r1)
	  addi      r31, r5, 0
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  stb       r31, 0x30(r3)
	  li        r3, 0
	  stb       r3, 0x30A0(r13)
	  beq-      .loc_0x38
	  li        r0, 0x2
	  stb       r0, 0x30A0(r13)

	.loc_0x38:
	  lwz       r3, 0x301C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  li        r0, 0x5
	  sth       r0, 0x200(r3)

	.loc_0x4C:
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  li        r4, 0
	  bl        0x3DF2C
	  lwz       r3, 0x3160(r13)
	  li        r4, 0x7
	  li        r5, 0x1
	  bl        0x3DFC4

	.loc_0x70:
	  lwz       r4, 0x3068(r13)
	  li        r3, 0
	  rlwinm.   r0,r30,0,20,20
	  sth       r3, 0x70(r4)
	  sth       r3, 0x72(r4)
	  beq-      .loc_0x98
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x72(r3)
	  ori       r0, r0, 0x1
	  sth       r0, 0x72(r3)

	.loc_0x98:
	  rlwinm.   r0,r30,0,19,19
	  beq-      .loc_0xB0
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x70(r3)
	  ori       r0, r0, 0x1
	  sth       r0, 0x70(r3)

	.loc_0xB0:
	  rlwinm.   r0,r30,0,18,18
	  beq-      .loc_0xC8
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x72(r3)
	  ori       r0, r0, 0x2
	  sth       r0, 0x72(r3)

	.loc_0xC8:
	  rlwinm.   r0,r30,0,17,17
	  beq-      .loc_0xE0
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x70(r3)
	  ori       r0, r0, 0x2
	  sth       r0, 0x70(r3)

	.loc_0xE0:
	  rlwinm.   r0,r30,0,16,16
	  beq-      .loc_0xF8
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x72(r3)
	  ori       r0, r0, 0x4
	  sth       r0, 0x72(r3)

	.loc_0xF8:
	  rlwinm.   r0,r30,0,15,15
	  beq-      .loc_0x110
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x70(r3)
	  ori       r0, r0, 0x4
	  sth       r0, 0x70(r3)

	.loc_0x110:
	  rlwinm.   r0,r30,0,10,10
	  beq-      .loc_0x128
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x70(r3)
	  ori       r0, r0, 0x8
	  sth       r0, 0x70(r3)

	.loc_0x128:
	  lwz       r28, 0x3068(r13)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x1C4

	.loc_0x148:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x16C
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x184

	.loc_0x16C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x184:
	  mr        r25, r3
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1A8
	  mr        r3, r25
	  bl        -0x468E4

	.loc_0x1A8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x1C4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1EC
	  li        r0, 0x1
	  b         .loc_0x218

	.loc_0x1EC:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x214
	  li        r0, 0x1
	  b         .loc_0x218

	.loc_0x214:
	  li        r0, 0

	.loc_0x218:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x148
	  lwz       r3, 0x3120(r13)
	  bl        0xA208
	  mr.       r25, r3
	  beq-      .loc_0x314
	  lwz       r3, 0x774(r25)
	  li        r4, 0x15
	  bl        0x728C
	  lwz       r3, 0x778(r25)
	  li        r4, 0x16
	  bl        0x7280
	  lwz       r3, 0x2D4(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x260
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)

	.loc_0x260:
	  lwz       r3, 0x2D8(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x278
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)

	.loc_0x278:
	  lwz       r3, 0x2DC(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x290
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)

	.loc_0x290:
	  lbz       r0, 0x2B4(r25)
	  cmplwi    r0, 0
	  beq-      .loc_0x2A4
	  mr        r3, r25
	  bl        -0x137D0

	.loc_0x2A4:
	  lwz       r3, 0xADC(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x2B8
	  lwz       r28, 0x4(r3)
	  b         .loc_0x2BC

	.loc_0x2B8:
	  li        r28, -0x1

	.loc_0x2BC:
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x2D4
	  lwz       r3, 0x774(r25)
	  bl        0x727C
	  lwz       r3, 0x778(r25)
	  bl        0x7274

	.loc_0x2D4:
	  lwz       r3, 0x318(r25)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r28, 0x16
	  beq-      .loc_0x314
	  cmpwi     r28, 0x17
	  beq-      .loc_0x314
	  lwz       r3, 0x320(r25)
	  addi      r4, r25, 0
	  li        r5, 0x15
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x314:
	  lwz       r27, 0x3068(r13)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r3, 0
	  rlwinm    r31,r30,0,28,28
	  rlwinm    r26,r30,0,27,27
	  rlwinm    r25,r30,0,26,26
	  b         .loc_0x3E0

	.loc_0x340:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x364
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x37C

	.loc_0x364:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x37C:
	  lhz       r0, 0x510(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x390
	  cmplwi    r31, 0
	  bne-      .loc_0x3B0

	.loc_0x390:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x3A0
	  cmplwi    r26, 0
	  bne-      .loc_0x3B0

	.loc_0x3A0:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x3C4
	  cmplwi    r25, 0
	  beq-      .loc_0x3C4

	.loc_0x3B0:
	  lwz       r3, 0x434(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x3C4:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x3E0:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x408
	  li        r0, 0x1
	  b         .loc_0x434

	.loc_0x408:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x430
	  li        r0, 0x1
	  b         .loc_0x434

	.loc_0x430:
	  li        r0, 0

	.loc_0x434:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x340
	  rlwinm.   r0,r30,0,21,21
	  beq-      .loc_0x450
	  lwz       r0, 0x2C(r29)
	  ori       r0, r0, 0x4
	  stw       r0, 0x2C(r29)

	.loc_0x450:
	  lmw       r25, 0xA4(r1)
	  lwz       r0, 0xC4(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010D3FC
 * Size:	000254
 */
void GameCoreSection::endMovie(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0xB0(r1)
	  stfd      f31, 0xA8(r1)
	  stfd      f30, 0xA0(r1)
	  stmw      r27, 0x8C(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  lwz       r5, 0x3160(r13)
	  stb       r0, 0x30A0(r13)
	  cmplwi    r5, 0
	  beq-      .loc_0x40
	  addi      r3, r5, 0
	  li        r4, 0x1
	  bl        0x3DAE8

	.loc_0x40:
	  lwz       r3, 0x301C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x54
	  li        r0, 0x7
	  sth       r0, 0x200(r3)

	.loc_0x54:
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x70(r3)
	  ori       r0, r0, 0x7
	  sth       r0, 0x70(r3)
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x72(r3)
	  ori       r0, r0, 0x7
	  sth       r0, 0x72(r3)
	  lwz       r29, 0x3068(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x10C

	.loc_0x94:
	  cmpwi     r28, -0x1
	  bne-      .loc_0xB8
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xD0

	.loc_0xB8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xD0:
	  mr        r27, r3
	  lwz       r3, 0x434(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  bl        -0x46BE0
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x10C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x134
	  li        r0, 0x1
	  b         .loc_0x160

	.loc_0x134:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x15C
	  li        r0, 0x1
	  b         .loc_0x160

	.loc_0x15C:
	  li        r0, 0

	.loc_0x160:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x94
	  lwz       r3, 0x58(r30)
	  lwz       r3, 0x774(r3)
	  bl        0x6F8C
	  lwz       r3, 0x58(r30)
	  lwz       r3, 0x778(r3)
	  bl        0x6F80
	  li        r0, 0
	  stw       r0, 0x2C(r30)
	  lwz       r0, 0x58(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x238
	  lwz       r3, 0x30D8(r13)
	  subi      r0, r31, 0x4
	  cmplwi    r0, 0x2
	  lwz       r3, 0x20(r3)
	  lfs       f1, 0xC8(r3)
	  ble-      .loc_0x1B4
	  cmpwi     r31, 0x10
	  bne-      .loc_0x218

	.loc_0x1B4:
	  lis       r3, 0x803A
	  lfs       f0, -0x6130(r2)
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  fmuls     f0, f0, f0
	  addi      r4, r3, 0x138
	  lfs       f1, 0x138(r3)
	  lfsu      f3, 0x12C(r3)
	  fsubs     f31, f3, f1
	  lfs       f2, 0x8(r3)
	  lfs       f1, 0x8(r4)
	  fsubs     f30, f2, f1
	  fmuls     f1, f31, f31
	  fmuls     f2, f30, f30
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xFF9B0
	  lfs       f0, -0x6130(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x20C
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1

	.loc_0x20C:
	  fmr       f1, f31
	  fmr       f2, f30
	  bl        0x10E3E8

	.loc_0x218:
	  lwz       r3, 0x30D8(r13)
	  lwz       r3, 0x20(r3)
	  bl        0x14910
	  lwz       r3, 0x30D8(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x238:
	  lmw       r27, 0x8C(r1)
	  lwz       r0, 0xB4(r1)
	  lfd       f31, 0xA8(r1)
	  lfd       f30, 0xA0(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GameCoreSection::hideTeki()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GameCoreSection::hideAllPellet()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GameCoreSection::hidePelletExceptSucked()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8010D650
 * Size:	000150
 */
void GameCoreSection::exitDayEnd()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  lwz       r31, 0x3068(r13)
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xD8

	.loc_0x38:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x5C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x74

	.loc_0x5C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  mr        r29, r3
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xBC
	  lwz       r3, 0x30AC(r13)
	  lhz       r4, 0x510(r29)
	  bl        -0x1AD30
	  cmplwi    r3, 0
	  beq-      .loc_0xB0
	  mr        r4, r29
	  bl        -0x224A0
	  b         .loc_0xBC

	.loc_0xB0:
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        -0x82A28

	.loc_0xBC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xD8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x100
	  li        r0, 0x1
	  b         .loc_0x12C

	.loc_0x100:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x128
	  li        r0, 0x1
	  b         .loc_0x12C

	.loc_0x128:
	  li        r0, 0

	.loc_0x12C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x38
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010D7A0
 * Size:	000188
 */
void GameCoreSection::forceDayEnd()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  stw       r28, 0x28(r1)
	  mr        r28, r3
	  lwz       r3, 0x3038(r13)
	  bl        -0x69644
	  lwz       r4, 0x2F6C(r13)
	  li        r0, 0x1
	  addi      r3, r28, 0
	  stb       r0, 0x1B5(r4)
	  stb       r0, 0x3A(r28)
	  stb       r0, 0x39(r28)
	  stb       r0, 0x38(r28)
	  stb       r0, 0x31(r28)
	  bl        .loc_0x188
	  mr        r3, r28
	  bl        0x2B0
	  lwz       r29, 0x3068(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x6130(r2)
	  mr        r28, r3
	  b         .loc_0x108

	.loc_0x7C:
	  cmpwi     r28, -0x1
	  bne-      .loc_0xA4
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xC0

	.loc_0xA4:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xC0:
	  li        r31, 0
	  stw       r31, 0x33C(r30)
	  stfs      f31, 0x348(r30)
	  stfs      f31, 0x344(r30)
	  stb       r31, 0x340(r30)
	  stb       r31, 0x330(r30)
	  lwz       r3, 0x338(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xEC
	  bl        -0x29518
	  stw       r31, 0x338(r30)

	.loc_0xEC:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x108:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x130
	  li        r0, 0x1
	  b         .loc_0x15C

	.loc_0x130:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x158
	  li        r0, 0x1
	  b         .loc_0x15C

	.loc_0x158:
	  li        r0, 0

	.loc_0x15C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x7C
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr

	.loc_0x188:
	*/
}

/*
 * --INFO--
 * Address:	8010D928
 * Size:	00017C
 */
void GameCoreSection::clearDeadlyPikmins()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r27, 0x2C(r1)
	  lwz       r30, 0x3068(r13)
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r4, 0x802C
	  addi      r29, r3, 0
	  addi      r31, r4, 0x21AC
	  b         .loc_0x10C

	.loc_0x38:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x5C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x74

	.loc_0x5C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  mr        r28, r3
	  bl        -0x4544C
	  subi      r0, r3, 0x6
	  cmplwi    r0, 0x12
	  li        r27, 0
	  bgt-      .loc_0xA0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r31, r0
	  mtctr     r0
	  bctr
	  li        r27, 0x1

	.loc_0xA0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC0
	  li        r27, 0x1

	.loc_0xC0:
	  rlwinm.   r0,r27,0,24,31
	  bne-      .loc_0xE4
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xF0

	.loc_0xE4:
	  addi      r3, r28, 0
	  li        r4, 0
	  bl        -0x82D34

	.loc_0xF0:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x10C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x134
	  li        r0, 0x1
	  b         .loc_0x160

	.loc_0x134:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x15C
	  li        r0, 0x1
	  b         .loc_0x160

	.loc_0x15C:
	  li        r0, 0

	.loc_0x160:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x38
	  lmw       r27, 0x2C(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010DAA4
 * Size:	000320
 */
void GameCoreSection::enterFreePikmins()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stmw      r26, 0x58(r1)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8E700
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x30C
	  lwz       r31, 0x3068(r13)
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x2B0

	.loc_0x40:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x64
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x7C

	.loc_0x64:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x7C:
	  mr        r27, r3
	  lwz       r12, 0x0(r27)
	  lhz       r28, 0x4FC(r27)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x294
	  lwz       r0, 0x2AC(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x294
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x294
	  cmpwi     r28, 0x1
	  beq-      .loc_0x294
	  subi      r0, r28, 0xB
	  cmplwi    r0, 0x1
	  ble-      .loc_0x294
	  mr        r3, r27
	  bl        -0x4562C
	  addi      r28, r3, 0
	  cmpwi     r28, 0x7
	  beq-      .loc_0x294
	  cmpwi     r28, 0x18
	  beq-      .loc_0x294
	  cmpwi     r28, 0
	  bne-      .loc_0x294
	  li        r26, 0

	.loc_0x100:
	  lwz       r3, 0x3120(r13)
	  bl        0x981C
	  mr        r29, r3
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r26
	  bl        -0x1B200
	  cmplwi    r3, 0
	  beq-      .loc_0x1C0
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x9C(r3)
	  lfs       f3, 0x94(r27)
	  lfs       f4, 0x9C(r27)
	  bl        -0xD55AC
	  lwz       r3, 0x3068(r13)
	  lwz       r3, 0x68(r3)
	  lfs       f0, 0x468(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x1C0
	  cmpwi     r28, 0x1A
	  beq-      .loc_0x164
	  cmpwi     r28, 0x3
	  beq-      .loc_0x164
	  cmpwi     r28, 0x1C
	  bne-      .loc_0x180

	.loc_0x164:
	  lwz       r3, 0x490(r27)
	  addi      r4, r27, 0
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x180:
	  lwz       r3, 0x490(r27)
	  addi      r4, r27, 0
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x30AC(r13)
	  lhz       r4, 0x510(r27)
	  bl        -0x1B290
	  stw       r3, 0x708(r29)
	  addi      r3, r27, 0
	  li        r4, 0xB
	  li        r5, 0
	  bl        -0x40A90
	  b         .loc_0x294

	.loc_0x1C0:
	  lwz       r3, 0x30AC(r13)
	  bl        -0x1B030
	  cmplwi    r3, 0
	  beq-      .loc_0x288
	  mr        r4, r3
	  lwz       r12, 0x0(r3)
	  addi      r3, r1, 0x34
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x34(r1)
	  lfs       f2, 0x3C(r1)
	  lfs       f3, 0x94(r27)
	  lfs       f4, 0x9C(r27)
	  bl        -0xD5674
	  lwz       r3, 0x3068(r13)
	  lwz       r3, 0x68(r3)
	  lfs       f0, 0x468(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x288
	  cmpwi     r28, 0x1A
	  beq-      .loc_0x22C
	  cmpwi     r28, 0x3
	  beq-      .loc_0x22C
	  cmpwi     r28, 0x1C
	  bne-      .loc_0x248

	.loc_0x22C:
	  lwz       r3, 0x490(r27)
	  addi      r4, r27, 0
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x248:
	  lwz       r3, 0x490(r27)
	  addi      r4, r27, 0
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x30AC(r13)
	  lhz       r4, 0x510(r27)
	  bl        -0x1B358
	  stw       r3, 0x708(r29)
	  addi      r3, r27, 0
	  li        r4, 0xB
	  li        r5, 0
	  bl        -0x40B58
	  b         .loc_0x294

	.loc_0x288:
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x3
	  blt+      .loc_0x100

	.loc_0x294:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x2B0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2D8
	  li        r0, 0x1
	  b         .loc_0x304

	.loc_0x2D8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x300
	  li        r0, 0x1
	  b         .loc_0x304

	.loc_0x300:
	  li        r0, 0

	.loc_0x304:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x40

	.loc_0x30C:
	  lmw       r26, 0x58(r1)
	  lwz       r0, 0x74(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010DDC4
 * Size:	000D94
 */
void GameCoreSection::cleanupDayEnd()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x1B8(r1)
	  stfd      f31, 0x1B0(r1)
	  stmw      r21, 0x184(r1)
	  addi      r31, r3, 0
	  sth       r0, 0x30C8(r13)
	  bl        -0x4BC
	  mr        r3, r31
	  bl        -0x348
	  lwz       r3, 0x3178(r13)
	  bl        0x6F100
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  addi      r30, r3, 0xA8
	  lwz       r3, 0xA8(r3)
	  lhz       r0, 0x26(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xBC
	  bge-      .loc_0x64
	  cmpwi     r0, 0
	  beq-      .loc_0x74
	  bge-      .loc_0x98
	  b         .loc_0xBC

	.loc_0x64:
	  cmpwi     r0, 0x4
	  beq-      .loc_0xBC
	  bge-      .loc_0xBC
	  b         .loc_0xAC

	.loc_0x74:
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1
	  addi      r3, r3, 0x70
	  bl        -0x8A444
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1D
	  addi      r3, r3, 0x70
	  bl        -0x8A454
	  b         .loc_0xBC

	.loc_0x98:
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x3
	  addi      r3, r3, 0x70
	  bl        -0x8A468
	  b         .loc_0xBC

	.loc_0xAC:
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x8
	  addi      r3, r3, 0x70
	  bl        -0x8A47C

	.loc_0xBC:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8D2C0
	  subi      r21, r3, 0x1
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8D2E0
	  addi      r0, r3, 0x1
	  cmpw      r0, r21
	  bne-      .loc_0xEC
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xA
	  addi      r3, r3, 0x70
	  bl        -0x8A4AC

	.loc_0xEC:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8D244
	  cmpwi     r3, 0xB
	  blt-      .loc_0x11C
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8D314
	  cmpwi     r3, 0x9
	  blt-      .loc_0x11C
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1A
	  addi      r3, r3, 0x70
	  bl        -0x8A4DC

	.loc_0x11C:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8D334
	  mr        r21, r3
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8D280
	  lwz       r0, 0x2F6C(r13)
	  add       r4, r0, r21
	  stb       r3, 0x18(r4)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8C794
	  lwz       r0, 0x2F6C(r13)
	  li        r22, 0
	  add       r4, r0, r21
	  stb       r3, 0x36(r4)

	.loc_0x154:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r22
	  bl        -0x1B568
	  cmplwi    r3, 0
	  beq-      .loc_0x170
	  li        r4, 0
	  bl        -0x22FC8

	.loc_0x170:
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x3
	  blt+      .loc_0x154
	  lwz       r3, 0x2F6C(r13)
	  li        r0, 0x1
	  stb       r0, 0x1B5(r3)
	  lwz       r3, 0x3120(r13)
	  bl        0x9474
	  cmplwi    r3, 0
	  beq-      .loc_0x1B4
	  lwz       r3, 0x3120(r13)
	  bl        0x9464
	  lwz       r3, 0x318(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x1B4:
	  lwz       r3, 0x3038(r13)
	  bl        -0x69DF8
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B6(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x1D8
	  bl        -0x8DAD8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD7C

	.loc_0x1D8:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B6(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x368
	  lwz       r4, 0x0(r30)
	  lwz       r3, 0x3098(r13)
	  lhz       r4, 0x24(r4)
	  bl        -0x2E588
	  lwz       r3, 0x3094(r13)
	  lwz       r3, 0x0(r3)
	  lwz       r21, 0x10(r3)
	  b         .loc_0x224

	.loc_0x208:
	  lwz       r0, 0x74(r21)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x220
	  lwz       r3, 0x3098(r13)
	  mr        r4, r21
	  bl        -0x2E4A0

	.loc_0x220:
	  lwz       r21, 0xC(r21)

	.loc_0x224:
	  cmplwi    r21, 0
	  bne+      .loc_0x208
	  lwz       r3, 0x3094(r13)
	  lwz       r3, 0x0(r3)
	  lwz       r21, 0x10(r3)
	  b         .loc_0x260

	.loc_0x23C:
	  lwz       r3, 0x74(r21)
	  rlwinm.   r0,r3,0,31,31
	  beq-      .loc_0x25C
	  rlwinm.   r0,r3,0,30,30
	  beq-      .loc_0x25C
	  lwz       r3, 0x3098(r13)
	  mr        r4, r21
	  bl        -0x2E024

	.loc_0x25C:
	  lwz       r21, 0xC(r21)

	.loc_0x260:
	  cmplwi    r21, 0
	  bne+      .loc_0x23C
	  lwz       r21, 0x301C(r13)
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3
	  b         .loc_0x2FC

	.loc_0x288:
	  cmpwi     r22, -0x1
	  bne-      .loc_0x2AC
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x2C4

	.loc_0x2AC:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C4:
	  lwz       r5, 0x55C(r3)
	  mr        r4, r3
	  lwz       r0, 0x5C(r5)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x2E0
	  lwz       r3, 0x3098(r13)
	  bl        -0x2E1CC

	.loc_0x2E0:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3

	.loc_0x2FC:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x324
	  li        r0, 0x1
	  b         .loc_0x350

	.loc_0x324:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x34C
	  li        r0, 0x1
	  b         .loc_0x350

	.loc_0x34C:
	  li        r0, 0

	.loc_0x350:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x288
	  lwz       r3, 0x3098(r13)
	  bl        -0x2E660
	  lwz       r3, 0x3098(r13)
	  bl        -0x2DFC8

	.loc_0x368:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B6(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x6F4
	  bl        -0x8DCC8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x6F4
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8ED94
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x6F4
	  lwz       r25, 0x3068(r13)
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x803D
	  lfs       f31, -0x612C(r2)
	  lis       r4, 0x803D
	  lis       r7, 0x802B
	  lis       r6, 0x802B
	  addi      r24, r3, 0
	  addi      r28, r5, 0x1EB8
	  addi      r29, r4, 0x1E58
	  subi      r26, r7, 0x3064
	  subi      r27, r6, 0x2E74
	  b         .loc_0x668

	.loc_0x3D8:
	  cmpwi     r24, -0x1
	  bne-      .loc_0x3FC
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x414

	.loc_0x3FC:
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  mr        r4, r24
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x414:
	  mr        r23, r3
	  lwz       r12, 0x0(r23)
	  lhz       r22, 0x4FC(r23)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x488
	  lhz       r4, 0x510(r23)
	  li        r0, 0x1
	  addi      r3, r23, 0
	  rlwinm    r4,r4,2,0,29
	  add       r6, r28, r4
	  lwz       r5, 0x0(r6)
	  li        r4, 0
	  addi      r5, r5, 0x1
	  stw       r5, 0x0(r6)
	  lhz       r5, 0x510(r23)
	  rlwinm    r5,r5,2,0,29
	  add       r6, r29, r5
	  lwz       r5, 0x0(r6)
	  addi      r5, r5, 0x1
	  stw       r5, 0x0(r6)
	  stb       r0, 0x584(r23)
	  bl        -0x83558
	  cmpwi     r24, 0
	  blt-      .loc_0x64C
	  subi      r24, r24, 0x1
	  b         .loc_0x64C

	.loc_0x488:
	  lwz       r0, 0x2AC(r23)
	  cmplwi    r0, 0
	  beq-      .loc_0x4D0
	  stw       r26, 0x158(r1)
	  addi      r4, r1, 0x158
	  stw       r23, 0x15C(r1)
	  stw       r27, 0x158(r1)
	  stfs      f31, 0x160(r1)
	  lwz       r21, 0x2AC(r23)
	  lwz       r12, 0x0(r21)
	  mr        r3, r21
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E8(r21)
	  mr        r4, r21
	  li        r5, 0x4
	  bl        -0x90B38

	.loc_0x4D0:
	  mr        r3, r23
	  bl        -0x45D44
	  cmpwi     r22, 0x1
	  addi      r21, r3, 0
	  bne-      .loc_0x51C
	  cmpwi     r21, 0x18
	  beq-      .loc_0x51C
	  subi      r0, r21, 0x6
	  cmplwi    r0, 0x4
	  ble-      .loc_0x51C
	  cmpwi     r21, 0x16
	  beq-      .loc_0x51C
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x64C

	.loc_0x51C:
	  subi      r0, r22, 0xB
	  cmplwi    r0, 0x1
	  ble-      .loc_0x64C
	  cmpwi     r21, 0x1A
	  beq-      .loc_0x64C
	  lhz       r0, 0x4FC(r23)
	  li        r21, 0
	  cmplwi    r0, 0
	  bne-      .loc_0x5F4
	  li        r22, 0

	.loc_0x544:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r22
	  bl        -0x1B958
	  cmplwi    r3, 0
	  beq-      .loc_0x58C
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x9C(r3)
	  lfs       f3, 0x94(r23)
	  lfs       f4, 0x9C(r23)
	  bl        -0xD5D04
	  lwz       r3, 0x3068(r13)
	  lwz       r3, 0x68(r3)
	  lfs       f0, 0x468(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x58C
	  li        r21, 0x1
	  b         .loc_0x5F4

	.loc_0x58C:
	  lwz       r3, 0x30AC(r13)
	  bl        -0x1B71C
	  cmplwi    r3, 0
	  beq-      .loc_0x5E8
	  mr        r4, r3
	  lwz       r12, 0x0(r3)
	  addi      r3, r1, 0x10C
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x10C(r1)
	  lfs       f2, 0x114(r1)
	  lfs       f3, 0x94(r23)
	  lfs       f4, 0x9C(r23)
	  bl        -0xD5D60
	  lwz       r3, 0x3068(r13)
	  lwz       r3, 0x68(r3)
	  lfs       f0, 0x468(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x5E8
	  li        r21, 0x1
	  b         .loc_0x5F4

	.loc_0x5E8:
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x3
	  blt+      .loc_0x544

	.loc_0x5F4:
	  rlwinm.   r0,r21,0,24,31
	  bne-      .loc_0x64C
	  lhz       r4, 0x510(r23)
	  li        r0, 0x1
	  addi      r3, r23, 0
	  rlwinm    r4,r4,2,0,29
	  add       r6, r28, r4
	  lwz       r5, 0x0(r6)
	  li        r4, 0
	  addi      r5, r5, 0x1
	  stw       r5, 0x0(r6)
	  lhz       r5, 0x510(r23)
	  rlwinm    r5,r5,2,0,29
	  add       r6, r29, r5
	  lwz       r5, 0x0(r6)
	  addi      r5, r5, 0x1
	  stw       r5, 0x0(r6)
	  stb       r0, 0x584(r23)
	  bl        -0x83720
	  cmpwi     r24, 0
	  blt-      .loc_0x64C
	  subi      r24, r24, 0x1

	.loc_0x64C:
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  mr        r4, r24
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3

	.loc_0x668:
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  mr        r4, r24
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x690
	  li        r0, 0x1
	  b         .loc_0x6BC

	.loc_0x690:
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  mr        r4, r24
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x6B8
	  li        r0, 0x1
	  b         .loc_0x6BC

	.loc_0x6B8:
	  li        r0, 0

	.loc_0x6BC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x3D8
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1EB8
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  add       r0, r0, r4
	  add.      r0, r3, r0
	  ble-      .loc_0x6F4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x17
	  addi      r3, r3, 0x70
	  bl        -0x8AAB4

	.loc_0x6F4:
	  lwz       r3, 0x3160(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3168(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x301C(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r21, 0x30AC(r13)
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3
	  b         .loc_0x7D4

	.loc_0x750:
	  cmpwi     r22, -0x1
	  bne-      .loc_0x774
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x78C

	.loc_0x774:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x78C:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0xF
	  beq-      .loc_0x7B8
	  cmpwi     r0, 0x10
	  beq-      .loc_0x7B8
	  cmpwi     r0, 0x11
	  beq-      .loc_0x7B8
	  cmpwi     r0, 0x12
	  beq-      .loc_0x7B8
	  li        r4, 0
	  bl        -0x83898

	.loc_0x7B8:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3

	.loc_0x7D4:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7FC
	  li        r0, 0x1
	  b         .loc_0x828

	.loc_0x7FC:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x824
	  li        r0, 0x1
	  b         .loc_0x828

	.loc_0x824:
	  li        r0, 0

	.loc_0x828:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x750
	  lwz       r3, 0x30AC(r13)
	  lwz       r21, 0x64(r3)
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3
	  b         .loc_0x8B4

	.loc_0x854:
	  cmpwi     r22, -0x1
	  bne-      .loc_0x878
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x890

	.loc_0x878:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x890:
	  li        r4, 0
	  bl        -0x21CE0
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3

	.loc_0x8B4:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8DC
	  li        r0, 0x1
	  b         .loc_0x908

	.loc_0x8DC:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x904
	  li        r0, 0x1
	  b         .loc_0x908

	.loc_0x904:
	  li        r0, 0

	.loc_0x908:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x854
	  lwz       r21, 0x3180(r13)
	  li        r4, 0x1
	  addi      r3, r21, 0x14
	  bl        0x92E48
	  mr        r3, r21
	  bl        0x8E5C0
	  addi      r21, r1, 0xF4
	  addi      r23, r1, 0x100
	  li        r24, 0

	.loc_0x934:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r24
	  bl        -0x1BD48
	  mr.       r22, r3
	  beq-      .loc_0x9B0
	  lwz       r4, 0x2F6C(r13)
	  li        r3, 0x1
	  lhz       r0, 0x428(r22)
	  lbz       r4, 0x184(r4)
	  slw       r0, r3, r0
	  and.      r0, r4, r0
	  beq-      .loc_0x9B0
	  lfs       f1, -0x25CC(r13)
	  mr        r4, r24
	  lfs       f0, -0x25D8(r13)
	  mr        r6, r23
	  stfs      f1, 0xF4(r1)
	  lfs       f1, -0x25C8(r13)
	  mr        r7, r21
	  stfs      f0, 0x100(r1)
	  addi      r5, r22, 0x94
	  lfs       f0, -0x25D4(r13)
	  stfs      f1, 0xF8(r1)
	  lfs       f1, -0x25C4(r13)
	  stfs      f0, 0x104(r1)
	  lfs       f0, -0x25D0(r13)
	  stfs      f1, 0xFC(r1)
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x108(r1)
	  bl        0x8E450
	  stw       r3, 0x40C(r22)

	.loc_0x9B0:
	  addi      r24, r24, 0x1
	  cmpwi     r24, 0x3
	  blt+      .loc_0x934
	  lwz       r3, 0x30AC(r13)
	  bl        -0x1BB4C
	  cmplwi    r3, 0
	  beq-      .loc_0x9DC
	  li        r0, 0
	  stw       r0, 0x3CC(r3)
	  li        r4, 0x1
	  bl        -0x275AC

	.loc_0x9DC:
	  lwz       r3, 0x30AC(r13)
	  lwz       r21, 0x64(r3)
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3
	  b         .loc_0xA60

	.loc_0xA00:
	  cmpwi     r22, -0x1
	  bne-      .loc_0xA24
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xA3C

	.loc_0xA24:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xA3C:
	  li        r4, 0x1
	  bl        -0x21E8C
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3

	.loc_0xA60:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA88
	  li        r0, 0x1
	  b         .loc_0xAB4

	.loc_0xA88:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xAB0
	  li        r0, 0x1
	  b         .loc_0xAB4

	.loc_0xAB0:
	  li        r0, 0

	.loc_0xAB4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xA00
	  li        r4, 0
	  stw       r4, 0x3160(r13)
	  subi      r0, r13, 0x25C0
	  stw       r4, 0x3168(r13)
	  lwz       r3, 0x64(r31)
	  lwz       r3, 0x88(r3)
	  stw       r4, 0x10(r3)
	  stw       r4, 0xC(r3)
	  stw       r4, 0x8(r3)
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B6(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xAF8
	  bl        -0x8E258

	.loc_0xAF8:
	  lwz       r3, 0x3120(r13)
	  bl        0x8B04
	  bl        -0x163CC
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B6(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xB1C
	  addi      r3, r3, 0x70
	  bl        -0x8AC48

	.loc_0xB1C:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B6(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xCC0
	  lwz       r3, 0x30AC(r13)
	  lwz       r4, 0x0(r30)
	  lwz       r21, 0x64(r3)
	  addi      r23, r4, 0x2C
	  addi      r3, r21, 0
	  lwz       r12, 0x0(r21)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3
	  b         .loc_0xC5C

	.loc_0xB58:
	  cmpwi     r22, -0x1
	  bne-      .loc_0xB7C
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xB94

	.loc_0xB7C:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xB94:
	  lwz       r0, 0x6C(r3)
	  addi      r24, r3, 0
	  cmpwi     r0, 0xF
	  bne-      .loc_0xC28
	  mr        r25, r3
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0xC28
	  cmpwi     r0, 0x1
	  beq-      .loc_0xC28
	  cmpwi     r0, 0xC
	  beq-      .loc_0xC28
	  cmpwi     r0, 0xD
	  beq-      .loc_0xC28
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  beq-      .loc_0xC00
	  mr        r4, r25
	  bl        -0x4912C

	.loc_0xC00:
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl

	.loc_0xC28:
	  addi      r3, r24, 0
	  li        r4, 0
	  bl        -0x83D14
	  cmpwi     r22, 0
	  blt-      .loc_0xC40
	  subi      r22, r22, 0x1

	.loc_0xC40:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3

	.loc_0xC5C:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC84
	  li        r0, 0x1
	  b         .loc_0xCB0

	.loc_0xC84:
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xCAC
	  li        r0, 0x1
	  b         .loc_0xCB0

	.loc_0xCAC:
	  li        r0, 0

	.loc_0xCB0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xB58
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8E020

	.loc_0xCC0:
	  lis       r3, 0x803D
	  lwz       r8, 0x2F6C(r13)
	  addi      r5, r3, 0x1EAC
	  lwz       r4, 0x8(r5)
	  lis       r3, 0x803D
	  lwz       r0, 0x4(r5)
	  addi      r6, r3, 0x1EB8
	  lwz       r7, 0x0(r8)
	  add       r0, r0, r4
	  lwz       r3, 0x0(r5)
	  add       r0, r0, r7
	  add       r0, r3, r0
	  stw       r0, 0x0(r8)
	  lis       r3, 0x803D
	  addi      r4, r3, 0x1E58
	  lwz       r3, 0x8(r4)
	  addi      r9, r6, 0x8
	  lwz       r0, 0x4(r4)
	  addi      r8, r6, 0x4
	  lwz       r7, 0x8(r6)
	  lwz       r5, 0x4(r6)
	  add       r0, r0, r3
	  lwz       r3, 0x0(r4)
	  lwz       r6, 0x0(r6)
	  add       r4, r5, r7
	  add       r0, r3, r0
	  add       r3, r6, r4
	  sub.      r0, r0, r3
	  bge-      .loc_0xD3C
	  li        r5, 0
	  b         .loc_0xD40

	.loc_0xD3C:
	  mr        r5, r0

	.loc_0xD40:
	  lwz       r4, 0x2F6C(r13)
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1EB8
	  lwz       r0, 0x4(r4)
	  add       r0, r0, r5
	  stw       r0, 0x4(r4)
	  lwz       r6, 0x2F6C(r13)
	  lwz       r4, 0x0(r9)
	  lwz       r0, 0x0(r8)
	  lwz       r5, 0x8(r6)
	  add       r0, r0, r4
	  lwz       r3, 0x0(r3)
	  add       r0, r0, r5
	  add       r0, r3, r0
	  stw       r0, 0x8(r6)

	.loc_0xD7C:
	  lmw       r21, 0x184(r1)
	  lwz       r0, 0x1BC(r1)
	  lfd       f31, 0x1B0(r1)
	  addi      r1, r1, 0x1B8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010EB58
 * Size:	000130
 */
void GameCoreSection::prepareBadEnd()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  lwz       r3, 0x30AC(r13)
	  lwz       r31, 0x64(r3)
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xB8

	.loc_0x3C:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x60
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x78

	.loc_0x60:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x78:
	  addi      r29, r3, 0
	  li        r4, 0
	  bl        -0x22260
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        -0x83F04
	  cmpwi     r30, 0
	  blt-      .loc_0x9C
	  subi      r30, r30, 0x1

	.loc_0x9C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xB8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE0
	  li        r0, 0x1
	  b         .loc_0x10C

	.loc_0xE0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x108
	  li        r0, 0x1
	  b         .loc_0x10C

	.loc_0x108:
	  li        r0, 0

	.loc_0x10C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x3C
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010EC88
 * Size:	000090
 */
void GameCoreSection::exitStage()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  lwz       r3, 0x2F6C(r13)
	  stw       r31, 0x2F78(r13)
	  stw       r31, 0x3120(r13)
	  bl        -0x8E3B4
	  lwz       r3, 0x3038(r13)
	  bl        -0x699D4
	  stw       r31, 0x3074(r13)
	  stw       r31, 0x3078(r13)
	  stw       r31, 0x307C(r13)
	  stw       r31, 0x2F80(r13)
	  stw       r31, 0x2F98(r13)
	  bl        -0x8FA14
	  bl        -0x36438
	  lwz       r3, 0x3030(r13)
	  li        r4, 0
	  bl        -0x6B69C
	  li        r3, 0
	  li        r4, 0
	  bl        0xF6A08
	  lwz       r3, 0x3180(r13)
	  bl        0x8DE1C
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x885E4
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  stw       r31, 0x230(r3)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void ps_vec3f_add(Vector3f&, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void ps_vec3f_sub(Vector3f&, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void ps_vec3f_multiply(Vector3f&, f32&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void asmTest(f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8010ED18
 * Size:	000CD4
 */
void GameCoreSection::initStage()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x288(r1)
	  stmw      r20, 0x258(r1)
	  mr        r31, r3
	  lwz       r3, 0x2F6C(r13)
	  li        r0, 0
	  lis       r4, 0x802C
	  stb       r0, 0x1B5(r3)
	  addi      r30, r4, 0x2188
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B6(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x44
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  bl        -0x49684

	.loc_0x44:
	  li        r0, 0
	  stb       r0, 0x30C0(r13)
	  stb       r0, 0x30C1(r13)
	  stw       r0, 0x30C4(r13)
	  stb       r0, 0x3A(r31)
	  stb       r0, 0x39(r31)
	  stb       r0, 0x38(r31)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8E908
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  li        r0, 0x1
	  stb       r0, 0x3A(r31)
	  stb       r0, 0x39(r31)
	  stb       r0, 0x38(r31)

	.loc_0x84:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  addi      r29, r3, 0xA8
	  lwz       r3, 0x0(r29)
	  lhz       r0, 0x26(r3)
	  cmpwi     r0, 0x3
	  beq-      .loc_0xD0
	  bge-      .loc_0xB4
	  cmpwi     r0, 0x2
	  bge-      .loc_0xBC
	  cmpwi     r0, 0
	  b         .loc_0xE0

	.loc_0xB4:
	  cmpwi     r0, 0x5
	  b         .loc_0xE0

	.loc_0xBC:
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x6
	  addi      r3, r3, 0x70
	  bl        -0x8B3E0
	  b         .loc_0xE0

	.loc_0xD0:
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x8
	  addi      r3, r3, 0x70
	  bl        -0x8B3F4

	.loc_0xE0:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r28, r3, 0x2FC
	  lwz       r0, 0x0(r28)
	  cmpwi     r0, 0xA
	  blt-      .loc_0x114
	  cmpwi     r0, 0x14
	  bgt-      .loc_0x114
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x14
	  addi      r3, r3, 0x70
	  bl        -0x8B424
	  b         .loc_0x12C

	.loc_0x114:
	  cmpwi     r0, 0x14
	  ble-      .loc_0x12C
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x14
	  addi      r3, r3, 0x70
	  bl        -0x8B3F0

	.loc_0x12C:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8E704
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x70
	  bl        -0x8871C
	  lwz       r4, 0x0(r29)
	  lwz       r3, 0x3098(r13)
	  lhz       r4, 0x24(r4)
	  bl        -0x2F858
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x70
	  bl        -0x88628
	  bl        0x3644
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x7C
	  bl        -0x88748
	  lis       r3, 0x803A
	  subi      r22, r3, 0x24E0
	  li        r0, 0
	  stw       r0, 0x230(r22)
	  li        r4, 0
	  lwz       r3, 0x3030(r13)
	  bl        -0x6B860
	  lwz       r0, 0x250(r22)
	  addi      r4, r30, 0x88
	  lwz       r3, 0x58(r31)
	  stw       r0, 0x730(r3)
	  lwz       r0, 0x24C(r22)
	  lwz       r3, 0x58(r31)
	  stw       r0, 0x72C(r3)
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x88788
	  li        r3, 0x30
	  bl        -0xC7EC4
	  mr        r22, r3
	  mr        r3, r22
	  cmplwi    r3, 0
	  beq-      .loc_0x1C8
	  bl        -0x6D808

	.loc_0x1C8:
	  stw       r22, 0x302C(r13)
	  lwz       r3, 0x302C(r13)
	  lwz       r4, 0x64(r31)
	  bl        -0x6D768
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  bl        -0x6EEEC
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x88
	  bl        -0x886C0
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x25A4
	  bl        -0x887DC
	  li        r3, 0x74
	  bl        -0xC7F18
	  mr        r22, r3
	  mr        r3, r22
	  cmplwi    r3, 0
	  beq-      .loc_0x220
	  lwz       r4, 0x58(r31)
	  bl        -0x411A8

	.loc_0x220:
	  stw       r22, 0x3068(r13)
	  lwz       r3, 0x3068(r13)
	  bl        -0x401CC
	  lwz       r0, 0x50(r31)
	  addi      r4, r30, 0x94
	  lwz       r3, 0x3068(r13)
	  stw       r0, 0x48(r3)
	  lwz       r0, 0x64(r31)
	  lwz       r3, 0x3068(r13)
	  stw       r0, 0x4C(r3)
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x8882C
	  lwz       r3, 0x3068(r13)
	  li        r4, 0x66
	  bl        -0x2DE80
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x94
	  bl        -0x88734
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x25A4
	  bl        -0x88740
	  lwz       r5, 0x3068(r13)
	  cmplwi    r5, 0
	  beq-      .loc_0x284
	  addi      r5, r5, 0x8

	.loc_0x284:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  subi      r4, r13, 0x259C
	  bl        -0xBC248
	  lis       r3, 0x803A
	  subi      r4, r3, 0x24E0
	  addi      r3, r1, 0x150
	  addi      r4, r4, 0x130
	  bl        0x10A39C
	  addi      r3, r1, 0x150
	  b         .loc_0x2B0

	.loc_0x2B0:
	  b         .loc_0x2B4

	.loc_0x2B4:
	  b         .loc_0x2BC

	.loc_0x2B8:
	  addi      r3, r3, 0x1

	.loc_0x2BC:
	  lbz       r0, 0x0(r3)
	  cmplwi    r0, 0x2E
	  bne+      .loc_0x2B8
	  addi      r3, r3, 0x1
	  li        r0, 0x67
	  stb       r0, 0x0(r3)
	  addi      r3, r3, 0x1
	  li        r0, 0x65
	  stb       r0, 0x0(r3)
	  addi      r3, r3, 0x1
	  li        r0, 0x6E
	  stb       r0, 0x0(r3)
	  addi      r3, r3, 0x1
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  addi      r3, r1, 0x150
	  b         .loc_0x300

	.loc_0x300:
	  b         .loc_0x304

	.loc_0x304:
	  b         .loc_0x30C

	.loc_0x308:
	  addi      r3, r3, 0x1

	.loc_0x30C:
	  lbz       r0, 0x0(r3)
	  cmplwi    r0, 0x2E
	  bne+      .loc_0x308
	  li        r0, 0x2F
	  crclr     6, 0x6
	  stb       r0, 0x0(r3)
	  addi      r3, r3, 0x1
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  addi      r3, r1, 0x50
	  addi      r4, r30, 0xA0
	  addi      r5, r1, 0x150
	  li        r27, 0
	  li        r26, 0
	  li        r25, 0
	  li        r24, 0
	  bl        0x107534
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x50
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3
	  cmplwi    r20, 0
	  beq-      .loc_0x3B0
	  lwz       r3, 0x3080(r13)
	  mr        r4, r20
	  li        r5, 0
	  bl        -0x31634
	  mr        r3, r20
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3080(r13)
	  bl        -0x31798
	  li        r27, 0x1
	  b         .loc_0x418

	.loc_0x3B0:
	  lwz       r3, 0x58(r31)
	  lfs       f0, -0x25BC(r13)
	  addi      r3, r3, 0x94
	  stfs      f0, 0x0(r3)
	  lfs       f0, -0x25B8(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x25B4(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r4, 0x58(r31)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x790(r4)
	  stw       r0, 0x794(r4)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x798(r4)
	  lfs       f0, -0x6130(r2)
	  lwz       r3, 0x58(r31)
	  stfs      f0, 0xA0(r3)
	  lwz       r3, 0x58(r31)
	  lfs       f0, -0x25B0(r13)
	  addi      r3, r3, 0x88
	  stfs      f0, 0x0(r3)
	  lfs       f0, -0x25AC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x25A8(r13)
	  stfs      f0, 0x8(r3)

	.loc_0x418:
	  lwz       r3, 0x58(r31)
	  bl        -0x14EAC
	  lwz       r4, 0x0(r28)
	  lis       r3, 0x8889
	  subi      r0, r3, 0x7777
	  crclr     6, 0x6
	  subi      r6, r4, 0x1
	  mulhw     r0, r0, r6
	  add       r0, r0, r6
	  srawi     r0, r0, 0x4
	  rlwinm    r3,r0,1,31,31
	  add       r0, r0, r3
	  mulli     r0, r0, 0x1E
	  addi      r3, r1, 0x50
	  addi      r4, r30, 0xB0
	  addi      r5, r1, 0x150
	  sub       r6, r6, r0
	  bl        0x107424
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x50
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3
	  cmplwi    r20, 0
	  beq-      .loc_0x4BC
	  lwz       r3, 0x3088(r13)
	  mr        r4, r20
	  li        r5, 0x1
	  bl        -0x31744
	  mr        r3, r20
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3088(r13)
	  bl        -0x318A8
	  li        r26, 0x1

	.loc_0x4BC:
	  lwz       r3, 0x0(r29)
	  addi      r3, r3, 0x20
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x548
	  li        r0, 0x1
	  crclr     6, 0x6
	  stw       r0, 0x0(r3)
	  addi      r3, r1, 0x50
	  addi      r4, r30, 0xBC
	  addi      r5, r1, 0x150
	  bl        0x107398
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x50
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3
	  cmplwi    r20, 0
	  beq-      .loc_0x548
	  lwz       r3, 0x308C(r13)
	  mr        r4, r20
	  li        r5, 0x1
	  bl        -0x317D0
	  mr        r3, r20
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x308C(r13)
	  bl        -0x31934
	  li        r25, 0x1

	.loc_0x548:
	  addi      r3, r1, 0x50
	  crclr     6, 0x6
	  addi      r4, r30, 0xC8
	  addi      r5, r1, 0x150
	  bl        0x107328
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x50
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3
	  cmplwi    r20, 0
	  beq-      .loc_0x5B8
	  lwz       r3, 0x3084(r13)
	  mr        r4, r20
	  li        r5, 0x1
	  bl        -0x31840
	  mr        r3, r20
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3084(r13)
	  bl        -0x319A4
	  li        r24, 0x1

	.loc_0x5B8:
	  lwz       r3, 0x0(r29)
	  li        r22, 0
	  lwz       r4, 0x0(r28)
	  lwz       r23, 0xA0(r3)
	  subi      r0, r4, 0x1
	  b         .loc_0x5D0

	.loc_0x5D0:
	  rlwinm    r28,r0,0,24,31
	  b         .loc_0x5D8

	.loc_0x5D8:
	  b         .loc_0x6D0

	.loc_0x5DC:
	  lbz       r0, 0x14(r23)
	  cmplw     r28, r0
	  blt-      .loc_0x6C8
	  lbz       r0, 0x15(r23)
	  cmplw     r28, r0
	  bgt-      .loc_0x6C8
	  lwz       r3, 0x2F6C(r13)
	  mr        r4, r22
	  bl        -0x8EE30
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x6C8
	  lwz       r6, 0x4(r23)
	  addi      r3, r1, 0x50
	  addi      r5, r1, 0x150
	  crclr     6, 0x6
	  subi      r4, r13, 0x2594
	  bl        0x107260
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x50
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3
	  cmplwi    r20, 0
	  beq-      .loc_0x6C8
	  li        r3, 0x60
	  bl        -0xC8368
	  mr        r21, r3
	  mr        r3, r21
	  cmplwi    r3, 0
	  beq-      .loc_0x66C
	  bl        -0x31FCC

	.loc_0x66C:
	  lwz       r0, 0x4(r23)
	  mr        r4, r21
	  stw       r0, 0x4(r21)
	  lwz       r3, 0x3090(r13)
	  bl        -0xCEDBC
	  mr        r3, r21
	  mr        r4, r20
	  li        r5, 0x1
	  bl        -0x31938
	  mr        r3, r20
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2F6C(r13)
	  mr        r4, r22
	  bl        -0x8EE78
	  lbz       r4, 0x16(r23)
	  mr        r3, r21
	  addi      r4, r4, 0x1
	  bl        -0x31ACC
	  mr        r3, r21
	  bl        -0x31AB8

	.loc_0x6C8:
	  addi      r22, r22, 0x1
	  lwz       r23, 0xC(r23)

	.loc_0x6D0:
	  cmplwi    r23, 0
	  bne+      .loc_0x5DC
	  lwz       r3, 0x3094(r13)
	  bl        -0x3075C
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x258C
	  bl        -0x88CC8
	  lwz       r3, 0x30AC(r13)
	  bl        -0x1B098
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x258C
	  bl        -0x88BCC
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2584
	  bl        -0x88CE8
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x257C
	  bl        -0x88CF4
	  lwz       r3, 0x3140(r13)
	  bl        0xB58C
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x257C
	  bl        -0x88BF8
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2584
	  bl        -0x88C04
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2574
	  bl        -0x88D20
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  bl        -0xD03FC
	  mr        r0, r3
	  lwz       r3, 0x3160(r13)
	  mr        r20, r0
	  bl        0x3B424
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r20
	  bl        -0xD0418
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2574
	  bl        -0x88C44
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x256C
	  bl        -0x88D60
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  bl        -0xD043C
	  mr        r0, r3
	  lwz       r3, 0x3168(r13)
	  mr        r20, r0
	  bl        0x40EEC
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r20
	  bl        -0xD0458
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x256C
	  bl        -0x88C84
	  lbz       r0, 0x2F68(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x7EC
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2564
	  bl        -0x88DAC
	  lwz       r3, 0x301C(r13)
	  bl        -0x768F8
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2564
	  bl        -0x88CB0
	  lwz       r3, 0x301C(r13)
	  bl        -0x77030

	.loc_0x7EC:
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2584
	  bl        -0x88DD4
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x255C
	  bl        -0x88DE0
	  lwz       r3, 0x3020(r13)
	  bl        -0x7415C
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x255C
	  bl        -0x88CE4
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2584
	  bl        -0x88CF0
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2554
	  bl        -0x88E0C
	  rlwinm    r0,r27,0,24,31
	  cmplwi    r0, 0
	  beq-      .loc_0x844
	  lwz       r3, 0x3080(r13)
	  bl        -0x31C90

	.loc_0x844:
	  lwz       r3, 0x3094(r13)
	  bl        -0x30938
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x70
	  bl        -0x88E34
	  lwz       r4, 0x0(r29)
	  lwz       r3, 0x3098(r13)
	  lhz       r4, 0x24(r4)
	  bl        -0x2FCE8
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x70
	  bl        -0x88D40
	  rlwinm    r0,r26,0,24,31
	  cmplwi    r0, 0
	  beq-      .loc_0x888
	  lwz       r3, 0x3088(r13)
	  bl        -0x31CD4

	.loc_0x888:
	  rlwinm    r0,r25,0,24,31
	  cmplwi    r0, 0
	  beq-      .loc_0x89C
	  lwz       r3, 0x308C(r13)
	  bl        -0x31CE8

	.loc_0x89C:
	  rlwinm    r0,r24,0,24,31
	  cmplwi    r0, 0
	  beq-      .loc_0x8B0
	  lwz       r3, 0x3084(r13)
	  bl        -0x31CFC

	.loc_0x8B0:
	  lwz       r3, 0x3090(r13)
	  lwz       r20, 0x10(r3)
	  b         .loc_0x8BC

	.loc_0x8BC:
	  b         .loc_0x8C0

	.loc_0x8C0:
	  b         .loc_0x8D0

	.loc_0x8C4:
	  mr        r3, r20
	  bl        -0x31D18
	  lwz       r20, 0xC(r20)

	.loc_0x8D0:
	  cmplwi    r20, 0
	  bne+      .loc_0x8C4
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2554
	  bl        -0x88DB0
	  lwz       r21, 0x3068(r13)
	  mr        r3, r21
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3
	  b         .loc_0x904

	.loc_0x904:
	  b         .loc_0x908

	.loc_0x908:
	  b         .loc_0x96C

	.loc_0x90C:
	  cmpwi     r22, -0x1
	  bne-      .loc_0x930
	  mr        r3, r21
	  lwz       r12, 0x0(r3)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x948

	.loc_0x930:
	  mr        r3, r21
	  lwz       r12, 0x0(r3)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x948:
	  lhz       r4, 0x510(r3)
	  bl        -0x45DEC
	  mr        r3, r21
	  lwz       r12, 0x0(r3)
	  mr        r4, r22
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3

	.loc_0x96C:
	  mr        r3, r21
	  lwz       r12, 0x0(r3)
	  mr        r4, r22
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0
	  beq-      .loc_0x998
	  li        r0, 0x1
	  b         .loc_0x9C4

	.loc_0x998:
	  mr        r3, r21
	  lwz       r12, 0x0(r3)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x9C0
	  li        r0, 0x1
	  b         .loc_0x9C4

	.loc_0x9C0:
	  li        r0, 0

	.loc_0x9C4:
	  rlwinm    r0,r0,0,24,31
	  cmplwi    r0, 0
	  beq+      .loc_0x90C
	  li        r3, 0x24
	  bl        -0xC86E8
	  mr        r21, r3
	  mr        r3, r21
	  cmplwi    r3, 0
	  beq-      .loc_0x9EC
	  bl        -0x96950

	.loc_0x9EC:
	  stw       r21, 0x2F20(r13)
	  lwz       r3, 0x3120(r13)
	  bl        0x7CB8
	  mr        r4, r3
	  lwz       r3, 0x30D8(r13)
	  bl        0x14734
	  lwz       r3, 0x30D8(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x58(r31)
	  li        r0, 0x1
	  stw       r0, 0x310(r3)
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B6(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xB5C
	  lwz       r3, 0x0(r29)
	  addi      r20, r3, 0x2C
	  mr        r3, r20
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r20
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r21, 0x1C(r20)
	  b         .loc_0xA6C

	.loc_0xA6C:
	  b         .loc_0xA70

	.loc_0xA70:
	  b         .loc_0xB54

	.loc_0xA74:
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0xF
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3
	  cmplwi    r22, 0
	  beq-      .loc_0xB50
	  mr        r3, r21
	  mr        r4, r22
	  bl        -0x49EC4
	  lwz       r3, 0x64(r31)
	  li        r4, 0x1
	  lfs       f1, 0x94(r22)
	  lfs       f2, 0x9C(r22)
	  bl        -0xA78C8
	  stfs      f1, 0x98(r22)
	  mr        r3, r22
	  addi      r4, r22, 0x94
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r22
	  lwz       r4, 0x3CC(r22)
	  bl        -0x22D54
	  mr        r3, r22
	  lwz       r12, 0x0(r3)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E8(r22)
	  mr        r4, r22
	  li        r5, 0x6
	  bl        -0x920C4
	  mr        r3, r20
	  lwz       r12, 0x0(r3)
	  mr        r4, r21
	  lwz       r21, 0xC(r21)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r20
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r20
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xB54

	.loc_0xB50:
	  lwz       r21, 0xC(r21)

	.loc_0xB54:
	  cmplwi    r21, 0
	  bne+      .loc_0xA74

	.loc_0xB5C:
	  lwz       r3, 0x301C(r13)
	  bl        -0x76960
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x7C
	  bl        -0x8903C
	  lis       r3, 0x803D
	  addi      r5, r3, 0x1DF0
	  lis       r4, 0x803D
	  lwz       r3, 0x8(r5)
	  addi      r6, r4, 0x1EA0
	  lwz       r0, 0x4(r5)
	  lwz       r4, 0x0(r6)
	  add       r0, r0, r3
	  lwz       r3, 0x0(r5)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  stw       r0, 0x0(r6)
	  lwz       r3, 0x14(r5)
	  lwz       r0, 0x10(r5)
	  lwz       r4, 0x4(r6)
	  add       r0, r0, r3
	  lwz       r3, 0xC(r5)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  stw       r0, 0x4(r6)
	  lwz       r3, 0x20(r5)
	  lwz       r0, 0x1C(r5)
	  lwz       r4, 0x8(r6)
	  add       r0, r0, r3
	  lwz       r3, 0x18(r5)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  stw       r0, 0x8(r6)
	  bl        0x2C68
	  lis       r4, 0x803D
	  lwz       r3, 0x2DEC(r13)
	  addi      r6, r4, 0x1ED0
	  lwz       r7, 0x8(r6)
	  addi      r4, r30, 0xD8
	  lwz       r0, 0x4(r6)
	  li        r5, 0x1
	  lwz       r6, 0x0(r6)
	  add       r0, r0, r7
	  add       r0, r6, r0
	  stw       r0, 0x3100(r13)
	  li        r6, 0x1
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3
	  cmplwi    r20, 0
	  beq-      .loc_0xCB0
	  mr        r3, r20
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r20
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3
	  lwz       r4, 0x3118(r13)
	  mr        r3, r20
	  lwz       r12, 0x4(r3)
	  lwz       r4, 0x8(r4)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r20
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r20
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x3118(r13)
	  mr        r4, r3
	  lwz       r3, 0x8(r5)
	  bl        0xE7224

	.loc_0xCB0:
	  lwz       r3, 0x3120(r13)
	  li        r4, 0
	  bl        0x7A68
	  bl        -0x157E0
	  lmw       r20, 0x258(r1)
	  lwz       r0, 0x28C(r1)
	  addi      r1, r1, 0x288
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010F9EC
 * Size:	000460
 */
void GameCoreSection::finalSetup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r30, 0x60(r1)
	  stw       r29, 0x5C(r1)
	  stw       r28, 0x58(r1)
	  mr        r31, r3
	  lwz       r3, 0x302C(r13)
	  bl        -0x6E004
	  lwz       r29, 0x301C(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x48

	.loc_0x48:
	  b         .loc_0x4C

	.loc_0x4C:
	  b         .loc_0xD0

	.loc_0x50:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x78
	  mr        r3, r29
	  lwz       r12, 0x0(r3)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x94

	.loc_0x78:
	  mr        r3, r29
	  lwz       r12, 0x0(r3)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x94:
	  cmplwi    r30, 0
	  beq-      .loc_0xB4
	  lwz       r3, 0x64(r31)
	  li        r4, 0x1
	  lfs       f1, 0x94(r30)
	  lfs       f2, 0x9C(r30)
	  bl        -0xA7B94
	  stfs      f1, 0x98(r30)

	.loc_0xB4:
	  mr        r3, r29
	  lwz       r12, 0x0(r3)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0xD0:
	  mr        r3, r29
	  lwz       r12, 0x0(r3)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0
	  beq-      .loc_0xFC
	  li        r0, 0x1
	  b         .loc_0x128

	.loc_0xFC:
	  mr        r3, r29
	  lwz       r12, 0x0(r3)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x124
	  li        r0, 0x1
	  b         .loc_0x128

	.loc_0x124:
	  li        r0, 0

	.loc_0x128:
	  rlwinm    r0,r0,0,24,31
	  cmplwi    r0, 0
	  beq+      .loc_0x50
	  li        r28, 0
	  b         .loc_0x13C

	.loc_0x13C:
	  lis       r3, 0x803D
	  addi      r30, r3, 0x1EA0
	  b         .loc_0x148

	.loc_0x148:
	  b         .loc_0x14C

	.loc_0x14C:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r28
	  bl        -0x1D188
	  cmplwi    r3, 0
	  beq-      .loc_0x188
	  lhz       r0, 0x428(r3)
	  lwz       r6, 0x434(r3)
	  lwz       r4, 0x430(r3)
	  rlwinm    r0,r0,2,0,29
	  lwz       r5, 0x42C(r3)
	  add       r3, r30, r0
	  add       r0, r4, r6
	  add       r0, r5, r0
	  stw       r0, 0x0(r3)
	  bl        0x29F0

	.loc_0x188:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x3
	  blt+      .loc_0x14C
	  bl        0x29E0
	  bl        0x2AA0
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0xBC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x2B8
	  bl        -0x8F724
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x2B8
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1ED0
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x1E4
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x184(r3)
	  rlwinm    r0,r0,0,31,31
	  cmpwi     r0, 0
	  bne-      .loc_0x234

	.loc_0x1E4:
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1ED0
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x20C
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x184(r3)
	  rlwinm    r0,r0,0,30,30
	  cmpwi     r0, 0
	  bne-      .loc_0x234

	.loc_0x20C:
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1ED0
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x2B8
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x184(r3)
	  rlwinm    r0,r0,0,29,29
	  cmpwi     r0, 0
	  beq-      .loc_0x2B8

	.loc_0x234:
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x11
	  addi      r3, r3, 0x54
	  bl        -0x8D768
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x274
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x11
	  li        r5, 0
	  addi      r3, r3, 0x54
	  bl        -0x8D730
	  lwz       r3, 0x2F6C(r13)
	  li        r0, 0x1
	  stb       r0, 0xBC(r3)
	  b         .loc_0x2B8

	.loc_0x274:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0x40
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  li        r6, 0
	  li        r7, 0
	  lwz       r12, 0xC(r12)
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2F6C(r13)
	  li        r0, 0x1
	  stb       r0, 0xBC(r3)

	.loc_0x2B8:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8F834
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x330
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B6(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x330
	  lwz       r3, 0x3120(r13)
	  bl        0x76F8
	  mr        r28, r3
	  cmplwi    r28, 0
	  beq-      .loc_0x3C0
	  lwz       r3, 0x320(r28)
	  mr        r4, r28
	  li        r5, 0x17
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x30AC(r13)
	  bl        -0x1D0C4
	  lwz       r3, 0x30D8(r13)
	  mr        r4, r28
	  li        r5, 0x1
	  lwz       r3, 0x20(r3)
	  li        r6, 0
	  bl        0x12054
	  b         .loc_0x3C0

	.loc_0x330:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8F8AC
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0
	  beq-      .loc_0x3A8
	  lwz       r3, 0x30D8(r13)
	  li        r5, 0
	  lwz       r4, 0x58(r31)
	  li        r6, 0
	  lwz       r3, 0x20(r3)
	  bl        0x12024
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8F8D8
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0
	  beq-      .loc_0x3C0
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x11(r3)
	  rlwinm    r0,r0,0,28,28
	  cmpwi     r0, 0
	  beq-      .loc_0x3C0
	  lwz       r3, 0x30D8(r13)
	  lwz       r3, 0x20(r3)
	  addi      r4, r3, 0x38
	  bl        0x1327C
	  lwz       r3, 0x30D8(r13)
	  li        r0, 0
	  lwz       r3, 0x20(r3)
	  stb       r0, 0x30(r3)
	  b         .loc_0x3C0

	.loc_0x3A8:
	  lwz       r3, 0x30D8(r13)
	  li        r5, 0x1
	  lwz       r4, 0x58(r31)
	  li        r6, 0
	  lwz       r3, 0x20(r3)
	  bl        0x11FC0

	.loc_0x3C0:
	  lwz       r3, 0x30AC(r13)
	  bl        -0x1D178
	  mr        r28, r3
	  cmplwi    r28, 0
	  beq-      .loc_0x404
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8F950
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x3F8
	  mr        r3, r28
	  li        r4, 0x1
	  bl        -0x28BEC
	  b         .loc_0x404

	.loc_0x3F8:
	  mr        r3, r28
	  li        r4, 0
	  bl        -0x28BFC

	.loc_0x404:
	  lwz       r3, 0x3168(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x414
	  bl        0x427F8

	.loc_0x414:
	  lwz       r3, 0x30AC(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x430
	  lwz       r3, 0x68(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x430
	  bl        -0x1CD0C

	.loc_0x430:
	  lwz       r3, 0x3020(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x440
	  bl        -0x74CFC

	.loc_0x440:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  lwz       r28, 0x58(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010FE4C
 * Size:	0009A4
 */
GameCoreSection::GameCoreSection(Controller*, MapMgr*, Camera&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r26, 0x38(r1)
	  mr        r31, r3
	  mr        r27, r4
	  mr        r28, r5
	  mr        r29, r6
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r31)
	  li        r26, 0
	  lis       r3, 0x802C
	  stw       r26, 0x10(r31)
	  addi      r30, r3, 0x2188
	  lis       r3, 0x8023
	  stw       r26, 0xC(r31)
	  subi      r0, r3, 0x71E0
	  addi      r4, r30, 0xEC
	  stw       r26, 0x8(r31)
	  mr        r3, r31
	  stw       r4, 0x4(r31)
	  stw       r0, 0x0(r31)
	  bl        -0xCF778
	  lis       r3, 0x802C
	  addi      r0, r3, 0x2474
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0x70
	  bl        -0xE6480
	  stw       r26, 0x28(r31)
	  li        r3, 0x1
	  stw       r26, 0x30CC(r13)
	  sth       r26, 0x30C8(r13)
	  stw       r26, 0x2C(r31)
	  bl        -0xC8EDC
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0xAC
	  bl        -0x8CDB8

	.loc_0xAC:
	  stw       r26, 0x2F78(r13)
	  li        r3, 0x30
	  bl        -0xC8EFC
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0xCC
	  bl        -0x949B0

	.loc_0xCC:
	  stw       r26, 0x2F28(r13)
	  li        r0, 0
	  addi      r4, r30, 0xEC
	  stw       r0, 0x34(r31)
	  stb       r0, 0x31(r31)
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x897F8
	  li        r3, 0x78
	  bl        -0xC8F34
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x104
	  bl        -0x6BF74

	.loc_0x104:
	  stw       r26, 0x3038(r13)
	  li        r3, 0x4
	  bl        -0xC8F54
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x124
	  bl        -0x313D4

	.loc_0x124:
	  stw       r26, 0x3094(r13)
	  subi      r4, r13, 0x254C
	  stw       r27, 0x20(r31)
	  stw       r28, 0x64(r31)
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x8984C
	  li        r3, 0x1E0
	  bl        -0xC8F88
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x158
	  bl        0xAA660

	.loc_0x158:
	  stw       r26, 0x30DC(r13)
	  li        r3, 0x154
	  bl        -0xC8FA8
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x178
	  bl        0xB04DC

	.loc_0x178:
	  stw       r26, 0x30E0(r13)
	  li        r3, 0x120
	  bl        -0xC8FC8
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x198
	  bl        0xB1160

	.loc_0x198:
	  stw       r26, 0x30E4(r13)
	  subi      r4, r13, 0x254C
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x897A8
	  li        r3, 0x7
	  bl        -0x7BF3C
	  lfs       f0, -0x6128(r2)
	  stfs      f0, 0x88(r31)
	  bl        0xB6A8
	  lbz       r0, 0x2F68(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x224
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2564
	  bl        -0x898E4
	  li        r3, 0x204
	  bl        -0xC9020
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x1F4
	  lwz       r4, 0x64(r31)
	  bl        -0x77850

	.loc_0x1F4:
	  cmplwi    r26, 0
	  stw       r26, 0x301C(r13)
	  beq-      .loc_0x204
	  addi      r26, r26, 0x8

	.loc_0x204:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  mr        r5, r26
	  addi      r4, r30, 0xF8
	  bl        -0xBD300
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2564
	  bl        -0x89824

	.loc_0x224:
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2584
	  bl        -0x89940
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x255C
	  bl        -0x8994C
	  li        r3, 0x48
	  bl        -0xC9088
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x258
	  bl        -0x74E40

	.loc_0x258:
	  cmplwi    r26, 0
	  stw       r26, 0x3020(r13)
	  beq-      .loc_0x268
	  addi      r26, r26, 0x8

	.loc_0x268:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  mr        r5, r26
	  addi      r4, r30, 0x10C
	  bl        -0xBD364
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x255C
	  bl        -0x89888
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2584
	  bl        -0x89894
	  li        r0, 0
	  stw       r0, 0x50(r31)
	  addi      r4, r30, 0x124
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  bl        -0xD0FEC
	  stw       r3, 0x68(r31)
	  li        r0, 0x105
	  li        r3, 0x10
	  lwz       r4, 0x68(r31)
	  sth       r0, 0x6(r4)
	  bl        -0xC9108
	  stw       r3, 0x6C(r31)
	  addi      r4, r30, 0x138
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  bl        -0xD1018
	  mr        r4, r3
	  lwz       r3, 0x6C(r31)
	  li        r5, 0x15
	  li        r6, 0x24
	  bl        -0xE847C
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x144
	  bl        -0x89A08
	  li        r3, 0x160
	  bl        -0xC9144
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x318
	  li        r4, 0x400
	  bl        -0x7D868

	.loc_0x318:
	  stw       r26, 0x3000(r13)
	  addi      r4, r30, 0x144
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x89928
	  li        r3, 0xB4
	  bl        -0xC9174
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x354
	  lwz       r5, 0x2DEC(r13)
	  li        r6, 0
	  lwz       r4, 0x20(r31)
	  lwz       r5, 0x10(r5)
	  bl        -0xB2AA4

	.loc_0x354:
	  stw       r26, 0x3C(r31)
	  addi      r3, r1, 0x30
	  lwz       r0, -0x7848(r13)
	  lwz       r4, 0x3C(r31)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  stw       r0, 0x48(r4)
	  lwz       r0, -0x7844(r13)
	  lwz       r4, 0x3C(r31)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  stw       r0, 0x4C(r4)
	  lwz       r4, 0x3C(r31)
	  bl        -0x8B7C0
	  bl        -0x90F04
	  li        r3, 0x18
	  bl        -0xC91DC
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x3AC
	  bl        -0x6ACD4

	.loc_0x3AC:
	  stw       r26, 0x3040(r13)
	  li        r4, 0xA
	  lwz       r3, 0x3040(r13)
	  bl        -0x6AC74
	  li        r3, 0x18
	  bl        -0xC9208
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x3D8
	  bl        -0x6AD00

	.loc_0x3D8:
	  stw       r26, 0x3044(r13)
	  li        r4, 0x9
	  lwz       r3, 0x3044(r13)
	  bl        -0x6ACA0
	  li        r3, 0x18
	  bl        -0xC9234
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x404
	  bl        -0x6AD2C

	.loc_0x404:
	  stw       r26, 0x3048(r13)
	  li        r4, 0x14
	  lwz       r3, 0x3048(r13)
	  bl        -0x6ACCC
	  li        r3, 0x18
	  bl        -0xC9260
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x430
	  bl        -0x6AD58

	.loc_0x430:
	  stw       r26, 0x304C(r13)
	  li        r4, 0x2
	  lwz       r3, 0x304C(r13)
	  bl        -0x6ACF8
	  li        r3, 0x18
	  bl        -0xC928C
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x45C
	  bl        -0x6AD84

	.loc_0x45C:
	  stw       r26, 0x3050(r13)
	  li        r4, 0x3
	  lwz       r3, 0x3050(r13)
	  bl        -0x6AD24
	  li        r3, 0x30
	  bl        -0xC92B8
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x488
	  bl        -0x6CEA8

	.loc_0x488:
	  stw       r26, 0x3030(r13)
	  bl        -0x8C478
	  lis       r3, 0x803A
	  lwz       r5, 0x2F80(r13)
	  subi      r27, r3, 0x2848
	  mr        r3, r27
	  subi      r4, r13, 0x2548
	  bl        -0xBD590
	  bl        -0x8BC34
	  lwz       r5, 0x2F98(r13)
	  mr        r3, r27
	  addi      r4, r30, 0x150
	  bl        -0xBD5A4
	  li        r3, 0x1
	  bl        -0xC9308
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x4D8
	  bl        -0x2D36C

	.loc_0x4D8:
	  stw       r26, 0x54(r31)
	  bl        -0x37A6C
	  bl        -0x93530
	  li        r3, 0x1C
	  bl        -0xC9330
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x500
	  bl        0x999C

	.loc_0x500:
	  stw       r26, 0x3138(r13)
	  subi      r4, r13, 0x2540
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x89C20
	  li        r3, 0x5C
	  bl        -0xC935C
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x52C
	  bl        0x6E50

	.loc_0x52C:
	  stw       r26, 0x3120(r13)
	  li        r4, 0x1
	  lwz       r3, 0x3120(r13)
	  bl        -0x2F294
	  lwz       r3, 0x3120(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x58(r31)
	  lwz       r5, 0x3120(r13)
	  cmplwi    r5, 0
	  beq-      .loc_0x564
	  addi      r5, r5, 0x8

	.loc_0x564:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  subi      r4, r13, 0x2538
	  bl        -0xBD65C
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2540
	  bl        -0x89B80
	  li        r3, 0x1
	  bl        -0xC93CC
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x59C
	  bl        0x2F98

	.loc_0x59C:
	  stw       r26, 0x3110(r13)
	  addi      r4, r30, 0x15C
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x89CBC
	  li        r3, 0x60
	  bl        -0xC93F8
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x5C8
	  bl        -0x3305C

	.loc_0x5C8:
	  stw       r26, 0x3080(r13)
	  subi      r0, r13, 0x2530
	  lis       r3, 0x803A
	  stw       r0, 0x4(r26)
	  subi      r3, r3, 0x2848
	  addi      r4, r30, 0x168
	  lwz       r5, 0x3080(r13)
	  bl        -0xBD6D0
	  bl        -0x89E60
	  bl        -0x21E70
	  bl        -0x766A0
	  bl        -0x74B10
	  bl        0xA900
	  lwz       r3, 0x64(r31)
	  bl        0x75D0
	  bl        0xAEBC
	  bl        0x3CF08
	  lwz       r3, 0x64(r31)
	  bl        -0xB32CC
	  bl        -0x182C0
	  bl        0x9744
	  li        r3, 0x60
	  bl        -0xC9468
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x638
	  bl        -0x330CC

	.loc_0x638:
	  stw       r26, 0x308C(r13)
	  subi      r0, r13, 0x2528
	  lis       r3, 0x803A
	  stw       r0, 0x4(r26)
	  subi      r3, r3, 0x2848
	  addi      r4, r30, 0x180
	  lwz       r5, 0x308C(r13)
	  bl        -0xBD740
	  li        r3, 0x60
	  bl        -0xC94A4
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x674
	  bl        -0x33108

	.loc_0x674:
	  stw       r26, 0x3088(r13)
	  subi      r0, r13, 0x2520
	  lis       r3, 0x803A
	  stw       r0, 0x4(r26)
	  subi      r3, r3, 0x2848
	  addi      r4, r30, 0x194
	  lwz       r5, 0x3088(r13)
	  bl        -0xBD77C
	  li        r3, 0x60
	  bl        -0xC94E0
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x6B0
	  bl        -0x33144

	.loc_0x6B0:
	  stw       r26, 0x3084(r13)
	  subi      r0, r13, 0x257C
	  lis       r3, 0x803A
	  stw       r0, 0x4(r26)
	  subi      r3, r3, 0x2848
	  addi      r4, r30, 0x1A8
	  lwz       r5, 0x3084(r13)
	  bl        -0xBD7B8
	  li        r3, 0x60
	  bl        -0xC951C
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x6EC
	  bl        -0x33180

	.loc_0x6EC:
	  stw       r26, 0x3090(r13)
	  li        r0, 0x1
	  lis       r3, 0x803A
	  stb       r0, 0x5C(r26)
	  subi      r0, r13, 0x2518
	  subi      r3, r3, 0x2848
	  lwz       r5, 0x3090(r13)
	  addi      r4, r30, 0x1C0
	  stw       r0, 0x4(r5)
	  lwz       r5, 0x3090(r13)
	  bl        -0xBD800
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x15C
	  bl        -0x89D24
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x256C
	  bl        -0x89E40
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  bl        -0xD151C
	  mr        r27, r3
	  li        r3, 0x54
	  bl        -0xC958C
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x75C
	  bl        0x3FAAC

	.loc_0x75C:
	  stw       r26, 0x3168(r13)
	  mr        r4, r27
	  lwz       r3, 0x2DEC(r13)
	  bl        -0xD154C
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x256C
	  bl        -0x89D78
	  lwz       r5, 0x3168(r13)
	  cmplwi    r5, 0
	  beq-      .loc_0x788
	  addi      r5, r5, 0x8

	.loc_0x788:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  subi      r4, r13, 0x2510
	  bl        -0xBD880
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2574
	  bl        -0x89EB4
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x4
	  bl        -0xD1590
	  mr        r27, r3
	  li        r3, 0x1B4
	  bl        -0xC9600
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x7D0
	  bl        0x39F80

	.loc_0x7D0:
	  stw       r26, 0x3160(r13)
	  mr        r4, r27
	  lwz       r3, 0x2DEC(r13)
	  bl        -0xD15C0
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2574
	  bl        -0x89DEC
	  lwz       r5, 0x3160(r13)
	  cmplwi    r5, 0
	  beq-      .loc_0x7FC
	  addi      r5, r5, 0x8

	.loc_0x7FC:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  subi      r4, r13, 0x2508
	  bl        -0xBD8F4
	  lbz       r0, 0x2F68(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x850
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x258C
	  bl        -0x89F34
	  li        r3, 0x98
	  bl        -0xC9670
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x840
	  bl        -0x1CCF8

	.loc_0x840:
	  stw       r26, 0x30AC(r13)
	  subi      r4, r13, 0x258C
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x89E50

	.loc_0x850:
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2584
	  bl        -0x89F6C
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x257C
	  bl        -0x89F78
	  li        r3, 0x70
	  bl        -0xC96B4
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x888
	  lwz       r4, 0x64(r31)
	  bl        0x9E78

	.loc_0x888:
	  stw       r26, 0x3140(r13)
	  subi      r4, r13, 0x257C
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x89E98
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x2584
	  bl        -0x89EA4
	  lwz       r3, 0x58(r31)
	  stw       r29, 0x2E8(r3)
	  lwz       r3, 0x58(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x320(r29)
	  bl        0x10B5D8
	  lfs       f0, -0x6128(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x164(r29)
	  lfs       f0, -0x6124(r2)
	  stfs      f0, 0x168(r29)
	  lfs       f1, 0x320(r29)
	  bl        0x10B428
	  lfs       f0, -0x6128(r2)
	  li        r3, 0x30
	  fmuls     f0, f0, f1
	  stfs      f0, 0x16C(r29)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f0, -0x612C(r2)
	  stfs      f0, 0x8(r4)
	  lfs       f0, -0x6120(r2)
	  stfs      f0, 0xC(r4)
	  bl        -0xC9750
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x92C
	  lwz       r5, 0x58(r31)
	  mr        r4, r29
	  lwz       r5, 0x2E4(r5)
	  bl        0x134E0

	.loc_0x92C:
	  stw       r26, 0x30D8(r13)
	  lis       r3, 0x803A
	  subi      r27, r3, 0x2848
	  lwz       r5, 0x30D8(r13)
	  mr        r3, r27
	  addi      r4, r30, 0x1D4
	  bl        -0xBDA30
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0xEC
	  bl        -0x89F54
	  li        r3, 0x1C
	  bl        -0xC97A0
	  mr        r26, r3
	  mr        r3, r26
	  cmplwi    r3, 0
	  beq-      .loc_0x988
	  lwz       r0, 0x2B4(r27)
	  cmpwi     r0, 0
	  bne-      .loc_0x980
	  li        r4, 0
	  b         .loc_0x984

	.loc_0x980:
	  li        r4, 0x1

	.loc_0x984:
	  bl        0xA5B68

	.loc_0x988:
	  stw       r26, 0x344(r31)
	  mr        r3, r31
	  lmw       r26, 0x38(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801107F0
 * Size:	0002B0
 */
void GameCoreSection::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  stw       r28, 0x48(r1)
	  mr        r28, r3
	  lis       r3, 0x803A
	  subi      r4, r3, 0x2848
	  addi      r31, r4, 0x1DC
	  lwz       r3, 0x0(r31)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x94
	  lbz       r0, 0x31(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x94
	  lwz       r3, 0x20(r4)
	  lfs       f1, 0x2F0(r4)
	  lfs       f0, 0xA0(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x94
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r0, 0x234(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x7C
	  cmpwi     r0, 0x2
	  beq-      .loc_0x94

	.loc_0x7C:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B5(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x94
	  mr        r3, r28
	  bl        0x22C

	.loc_0x94:
	  lwz       r3, 0x0(r31)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xAC
	  lwz       r3, 0x30E0(r13)
	  bl        0xB04EC

	.loc_0xAC:
	  lwz       r3, 0x30E4(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x302C(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x33C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xFC
	  lwz       r0, 0x338(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xFC
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x90288

	.loc_0xFC:
	  lis       r3, 0x803D
	  addi      r4, r3, 0x1ED0
	  addi      r29, r4, 0x8
	  lwz       r3, 0x0(r4)
	  addi      r30, r4, 0x4
	  lwz       r4, 0x0(r29)
	  lwz       r0, 0x0(r30)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  cmpwi     r0, 0
	  bne-      .loc_0x188
	  lwz       r0, 0x3104(r13)
	  cmpwi     r0, 0
	  ble-      .loc_0x188
	  lwz       r4, 0x58(r28)
	  lwz       r3, 0xADC(r4)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x21
	  beq-      .loc_0x188
	  cmpwi     r0, 0x19
	  beq-      .loc_0x188
	  cmpwi     r0, 0x15
	  beq-      .loc_0x188
	  cmpwi     r0, 0x16
	  beq-      .loc_0x188
	  lwz       r3, 0x320(r4)
	  li        r5, 0x21
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xE
	  addi      r3, r3, 0x70
	  bl        -0x8CF74

	.loc_0x188:
	  lwz       r3, 0x0(r31)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x1AC
	  lwz       r3, 0x30D8(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x1AC:
	  lwz       r3, 0x3120(r13)
	  bl        0x6A24
	  lwz       r3, 0x7F8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x210
	  lwz       r0, 0x2AC(r3)
	  lhz       r4, 0x510(r3)
	  cmplwi    r0, 0
	  lwz       r3, 0x520(r3)
	  beq-      .loc_0x1DC
	  li        r0, 0x1
	  b         .loc_0x1E0

	.loc_0x1DC:
	  li        r0, 0

	.loc_0x1E0:
	  cmpwi     r4, 0x2
	  ble-      .loc_0x1EC
	  li        r4, 0

	.loc_0x1EC:
	  cmpwi     r3, 0x2
	  ble-      .loc_0x1F8
	  li        r3, 0x2

	.loc_0x1F8:
	  mulli     r0, r0, 0x3
	  add       r3, r0, r3
	  mulli     r0, r4, 0x6
	  addi      r6, r3, 0x1
	  add       r6, r0, r6
	  b         .loc_0x214

	.loc_0x210:
	  li        r6, 0

	.loc_0x214:
	  lwz       r5, 0x31A0(r13)
	  lis       r3, 0x803D
	  lis       r4, 0x803D
	  stw       r6, 0x0(r5)
	  addi      r7, r3, 0x1ED0
	  lis       r3, 0x803D
	  lwz       r8, 0x0(r29)
	  addi      r6, r4, 0x1EC4
	  lwz       r0, 0x0(r30)
	  addi      r5, r3, 0x1E70
	  lwz       r4, 0x0(r7)
	  add       r0, r0, r8
	  lwz       r3, 0x31A0(r13)
	  add       r0, r4, r0
	  sth       r0, 0x8(r3)
	  mr        r3, r28
	  lwz       r4, 0x8(r6)
	  lwz       r0, 0x4(r6)
	  lwz       r6, 0x0(r6)
	  add       r0, r0, r4
	  lwz       r4, 0x31A0(r13)
	  add       r0, r6, r0
	  sth       r0, 0x6(r4)
	  lwz       r4, 0x8(r5)
	  lwz       r0, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  add       r0, r0, r4
	  lwz       r4, 0x31A0(r13)
	  add       r0, r5, r0
	  sth       r0, 0x4(r4)
	  bl        -0xD0318
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
 * Address:	80110AA0
 * Size:	00000C
 */
void GameCoreSection::startContainerDemo()
{
	// Generated from stw r0, 0x34(r3)
	// _34 = 2;
}

/*
 * --INFO--
 * Address:	80110AAC
 * Size:	000038
 */
void GameCoreSection::startSundownWarn()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  li        r0, 0x1
	  stb       r0, 0x31(r3)
	  li        r4, 0x1
	  lwz       r3, 0x30E0(r13)
	  bl        0xAFDEC
	  li        r3, 0x114
	  bl        -0x6B75C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80110AE4
 * Size:	000568
 */
void GameCoreSection::updateAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1EC4
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  cmpwi     r0, 0x32
	  ble-      .loc_0x4C
	  li        r0, 0x2
	  stw       r0, -0x5F04(r13)
	  b         .loc_0x68

	.loc_0x4C:
	  cmpwi     r0, 0x1E
	  ble-      .loc_0x60
	  li        r0, 0x1
	  stw       r0, -0x5F04(r13)
	  b         .loc_0x68

	.loc_0x60:
	  li        r0, 0
	  stw       r0, -0x5F04(r13)

	.loc_0x68:
	  lwz       r0, 0x30CC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x80
	  mr        r3, r30
	  bl        -0x3CB0
	  b         .loc_0x54C

	.loc_0x80:
	  lwz       r3, 0x2F20(r13)
	  bl        -0x976B4
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8FFA4
	  mr        r31, r3
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x8FF88
	  sub       r4, r3, r31
	  lbz       r0, 0x38(r30)
	  srawi     r5, r4, 0x2
	  addze     r5, r5
	  mulli     r3, r5, 0x3
	  srawi     r4, r4, 0x1
	  addze     r4, r4
	  cmplwi    r0, 0
	  add       r5, r31, r5
	  add       r4, r31, r4
	  add       r6, r31, r3
	  bne-      .loc_0xF4
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x2F8(r3)
	  cmpw      r0, r5
	  blt-      .loc_0xF4
	  li        r0, 0x1
	  stb       r0, 0x38(r30)
	  li        r3, 0x12B
	  bl        -0x6B85C
	  b         .loc_0x1A0

	.loc_0xF4:
	  lbz       r0, 0x39(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x170
	  lis       r3, 0x803A
	  subi      r31, r3, 0x2848
	  lwz       r0, 0x2F8(r31)
	  cmpw      r0, r4
	  blt-      .loc_0x170
	  li        r0, 0x1
	  stb       r0, 0x39(r30)
	  li        r3, 0x125
	  bl        -0x6B890
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1F
	  addi      r3, r3, 0x54
	  bl        -0x8E750
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x1A0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1F
	  addi      r3, r3, 0x54
	  bl        -0x8E4E0
	  lwz       r3, 0x1E8(r31)
	  li        r4, 0
	  li        r5, 0x1F
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1A0

	.loc_0x170:
	  lbz       r0, 0x3A(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x1A0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x2F8(r3)
	  cmpw      r0, r6
	  blt-      .loc_0x1A0
	  li        r0, 0x1
	  stb       r0, 0x3A(r30)
	  li        r3, 0x12B
	  bl        -0x6B90C

	.loc_0x1A0:
	  bl        -0x8C29C
	  lwz       r3, 0x3040(r13)
	  bl        -0x6B750
	  lwz       r3, 0x3044(r13)
	  bl        -0x6B758
	  lwz       r3, 0x3048(r13)
	  bl        -0x6B760
	  lwz       r3, 0x304C(r13)
	  bl        -0x6B768
	  lwz       r3, 0x3050(r13)
	  bl        -0x6B770
	  lwz       r3, 0x64(r30)
	  bl        -0xAB2EC
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r31, r3, 0x338
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x200
	  lwz       r3, 0x3120(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x200:
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x3B8
	  lwz       r0, 0x3160(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x28C
	  lbz       r0, -0x5F07(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x284
	  lwz       r3, 0x3120(r13)
	  bl        -0x309D8
	  lwz       r3, 0x3068(r13)
	  bl        -0x309E0
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x244
	  bl        -0x309F0

	.loc_0x244:
	  lwz       r3, 0x3168(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x254
	  bl        -0x30A00

	.loc_0x254:
	  lwz       r3, 0x30AC(r13)
	  bl        -0x30A08
	  lwz       r3, 0x3140(r13)
	  bl        -0x30A10
	  lwz       r3, 0x3020(r13)
	  bl        -0x30A18
	  lwz       r3, 0x30AC(r13)
	  lwz       r3, 0x68(r3)
	  bl        -0x30A24
	  lwz       r3, 0x54(r30)
	  bl        -0x2DDA8
	  b         .loc_0x28C

	.loc_0x284:
	  lwz       r3, 0x54(r30)
	  bl        -0x2DDB4

	.loc_0x28C:
	  lis       r3, 0x803A
	  subi      r4, r3, 0x2848
	  lwz       r0, 0x33C(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x3B8
	  lhz       r0, 0x30C8(r13)
	  rlwinm    r0,r0,0,16,16
	  cmpwi     r0, 0
	  bne-      .loc_0x300
	  lwz       r3, 0x3168(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x300
	  lwz       r4, 0x1DC(r4)
	  li        r5, 0
	  lbz       r0, 0x124(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x2E4
	  lwz       r0, 0x2C(r30)
	  rlwinm    r0,r0,0,29,29
	  cmplwi    r0, 0
	  bne-      .loc_0x2E4
	  li        r5, 0x1

	.loc_0x2E4:
	  rlwinm    r0,r5,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x300
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x300:
	  lhz       r0, 0x30C8(r13)
	  rlwinm    r0,r0,0,16,16
	  cmpwi     r0, 0
	  bne-      .loc_0x324
	  lwz       r3, 0x3068(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x324:
	  lwz       r3, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x30C8(r13)
	  rlwinm    r0,r0,0,16,16
	  cmpwi     r0, 0
	  bne-      .loc_0x3B8
	  lwz       r3, 0x3020(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3140(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x3A4
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  lwz       r4, 0x1DC(r4)
	  lbz       r0, 0x124(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x3A4
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x3A4:
	  lwz       r3, 0x301C(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x3B8:
	  lwz       r0, 0x3160(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x54C
	  lwz       r0, 0x0(r31)
	  lwz       r3, 0x2DEC(r13)
	  cmpwi     r0, 0
	  lfs       f31, 0x28C(r3)
	  bne-      .loc_0x3F4
	  lwz       r3, 0x3120(r13)
	  fmr       f1, f31
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl

	.loc_0x3F4:
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x54C
	  lhz       r0, 0x30C8(r13)
	  rlwinm    r0,r0,0,16,16
	  cmpwi     r0, 0
	  bne-      .loc_0x54C
	  lis       r3, 0x803A
	  subi      r31, r3, 0x2848
	  lwz       r0, 0x33C(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x54C
	  lwz       r3, 0x3068(r13)
	  fmr       f1, f31
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x30AC(r13)
	  fmr       f1, f31
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x301C(r13)
	  fmr       f1, f31
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3140(r13)
	  fmr       f1, f31
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x4EC
	  lwz       r4, 0x1DC(r31)
	  li        r5, 0
	  lbz       r0, 0x124(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C8
	  lwz       r0, 0x2C(r30)
	  rlwinm    r0,r0,0,29,29
	  cmplwi    r0, 0
	  bne-      .loc_0x4C8
	  li        r5, 0x1

	.loc_0x4C8:
	  rlwinm    r0,r5,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x4EC
	  lwz       r12, 0x0(r3)
	  fmr       f1, f31
	  li        r4, 0
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl

	.loc_0x4EC:
	  lwz       r3, 0x3168(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x54C
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  lwz       r4, 0x1DC(r4)
	  li        r5, 0
	  lbz       r0, 0x124(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x528
	  lwz       r0, 0x2C(r30)
	  rlwinm    r0,r0,0,29,29
	  cmplwi    r0, 0
	  bne-      .loc_0x528
	  li        r5, 0x1

	.loc_0x528:
	  rlwinm    r0,r5,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x54C
	  lwz       r12, 0x0(r3)
	  fmr       f1, f31
	  li        r4, 0
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl

	.loc_0x54C:
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011104C
 * Size:	0005A4
 */
void GameCoreSection::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  stw       r30, 0x70(r1)
	  stw       r29, 0x6C(r1)
	  stw       r28, 0x68(r1)
	  mr        r29, r3
	  mr        r30, r4
	  lwz       r4, 0x2E4(r30)
	  lwz       r3, 0x260(r4)
	  lwz       r0, 0x264(r4)
	  stw       r3, 0x2A0(r4)
	  stw       r0, 0x2A4(r4)
	  lwz       r3, 0x268(r4)
	  lwz       r0, 0x26C(r4)
	  stw       r3, 0x2A8(r4)
	  stw       r0, 0x2AC(r4)
	  lwz       r3, 0x270(r4)
	  lwz       r0, 0x274(r4)
	  stw       r3, 0x2B0(r4)
	  stw       r0, 0x2B4(r4)
	  lwz       r3, 0x278(r4)
	  lwz       r0, 0x27C(r4)
	  stw       r3, 0x2B8(r4)
	  stw       r0, 0x2BC(r4)
	  lwz       r3, 0x280(r4)
	  lwz       r0, 0x284(r4)
	  stw       r3, 0x2C0(r4)
	  stw       r0, 0x2C4(r4)
	  lwz       r3, 0x288(r4)
	  lwz       r0, 0x28C(r4)
	  stw       r3, 0x2C8(r4)
	  stw       r0, 0x2CC(r4)
	  lwz       r3, 0x290(r4)
	  lwz       r0, 0x294(r4)
	  stw       r3, 0x2D0(r4)
	  stw       r0, 0x2D4(r4)
	  lwz       r3, 0x298(r4)
	  lwz       r0, 0x29C(r4)
	  stw       r3, 0x2D8(r4)
	  stw       r0, 0x2DC(r4)
	  lwz       r4, 0x2E4(r30)
	  addi      r3, r4, 0x2A0
	  addi      r4, r4, 0x1E0
	  bl        -0xD31CC
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r31, r3, 0x1DC
	  lwz       r3, 0x0(r31)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x100
	  lfs       f0, -0x6130(r2)
	  addi      r4, r1, 0x58
	  stfs      f0, 0x60(r1)
	  stfs      f0, 0x5C(r1)
	  stfs      f0, 0x58(r1)
	  bl        -0x99434
	  lwz       r3, 0x3038(r13)
	  mr        r4, r30
	  addi      r5, r1, 0x58
	  bl        -0x6C2EC
	  b         .loc_0x114

	.loc_0x100:
	  lwz       r5, 0x58(r29)
	  mr        r4, r30
	  lwz       r3, 0x3038(r13)
	  addi      r5, r5, 0x94
	  bl        -0x6C304

	.loc_0x114:
	  mr        r3, r30
	  lwz       r12, 0x3B4(r3)
	  lis       r4, 0x803A
	  subi      r4, r4, 0x77C0
	  lwz       r12, 0x74(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lfs       f1, -0x612C(r2)
	  bl        -0xE79AC
	  lwz       r0, 0x28(r29)
	  cmpwi     r0, 0x8
	  beq-      .loc_0x158
	  lwz       r3, 0x64(r29)
	  mr        r4, r30
	  bl        -0xAB36C

	.loc_0x158:
	  lwz       r3, 0x64(r29)
	  mr        r4, r30
	  li        r5, 0
	  lwz       r3, 0x4(r3)
	  bl        -0xA2220
	  lbz       r0, 0x2FA1(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x1FC
	  lwz       r0, 0x28(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x1D8
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x1D8
	  lwz       r4, 0x0(r31)
	  li        r5, 0
	  lbz       r0, 0x124(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x1B8
	  lwz       r0, 0x2C(r29)
	  rlwinm    r0,r0,0,29,29
	  cmplwi    r0, 0
	  bne-      .loc_0x1B8
	  li        r5, 0x1

	.loc_0x1B8:
	  rlwinm    r0,r5,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x1D8
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x1D8:
	  lwz       r0, 0x28(r29)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1FC
	  lwz       r3, 0x3068(r13)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x1FC:
	  lwz       r3, 0x0(r31)
	  mr        r4, r30
	  bl        -0x993D4
	  lwz       r3, 0x3120(r13)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x2FA1(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x28C
	  lwz       r0, 0x28(r29)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x28C
	  lwz       r3, 0x3168(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x28C
	  lwz       r4, 0x0(r31)
	  li        r5, 0
	  lbz       r0, 0x124(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x26C
	  lwz       r0, 0x2C(r29)
	  rlwinm    r0,r0,0,29,29
	  cmplwi    r0, 0
	  bne-      .loc_0x26C
	  li        r5, 0x1

	.loc_0x26C:
	  rlwinm    r0,r5,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x28C
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x28C:
	  lwz       r0, 0x28(r29)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x2B0
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x2B0:
	  lwz       r0, 0x28(r29)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x2D4
	  lwz       r3, 0x3020(r13)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x2D4:
	  lbz       r0, 0x2FA1(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x328
	  lwz       r0, 0x28(r29)
	  cmpwi     r0, 0x5
	  beq-      .loc_0x304
	  lwz       r3, 0x301C(r13)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x304:
	  lwz       r0, 0x28(r29)
	  cmpwi     r0, 0x7
	  beq-      .loc_0x328
	  lwz       r3, 0x3140(r13)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x328:
	  lwz       r3, 0x3120(r13)
	  mr        r4, r30
	  bl        0x61F0
	  lwz       r3, 0x64(r29)
	  mr        r4, r30
	  bl        -0xAA89C
	  li        r0, 0
	  stb       r0, 0x14(r1)
	  addi      r5, r1, 0x14
	  mr        r4, r30
	  stb       r0, 0x15(r1)
	  stb       r0, 0x16(r1)
	  stb       r0, 0x17(r1)
	  lwz       r3, 0x64(r29)
	  lwz       r3, 0x4(r3)
	  bl        -0xA241C
	  mr        r3, r30
	  lwz       r12, 0x3B4(r3)
	  lis       r4, 0x803A
	  subi      r4, r4, 0x77C0
	  lwz       r12, 0x70(r12)
	  addi      r5, r1, 0x18
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r3)
	  addi      r4, r1, 0x18
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r3)
	  li        r4, 0x2
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3
	  mr        r3, r30
	  lwz       r12, 0x3B4(r3)
	  mr        r28, r0
	  li        r4, 0
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r3)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r4, 0x68(r29)
	  lwz       r12, 0x3B4(r3)
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r5, 0xFF
	  stb       r5, 0x10(r1)
	  li        r0, 0x80
	  mr        r3, r30
	  stb       r5, 0x11(r1)
	  addi      r4, r1, 0x10
	  stb       r5, 0x12(r1)
	  li        r5, 0x1
	  stb       r0, 0x13(r1)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, -0x5F04(r13)
	  cmpwi     r0, 0x1
	  bgt-      .loc_0x470
	  lwz       r3, 0x3068(r13)
	  mr        r4, r30
	  lwz       r5, 0x68(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl

	.loc_0x470:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r30
	  lwz       r5, 0x68(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x301C(r13)
	  mr        r4, r30
	  lwz       r5, 0x68(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x500
	  lwz       r4, 0x0(r31)
	  li        r5, 0
	  lbz       r0, 0x124(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x4DC
	  lwz       r0, 0x2C(r29)
	  rlwinm    r0,r0,0,29,29
	  cmplwi    r0, 0
	  bne-      .loc_0x4DC
	  li        r5, 0x1

	.loc_0x4DC:
	  rlwinm    r0,r5,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x500
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r5, 0x68(r29)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl

	.loc_0x500:
	  lwz       r3, 0x3120(r13)
	  mr        r4, r30
	  bl        0x6128
	  mr        r3, r30
	  lwz       r12, 0x3B4(r3)
	  mr        r4, r28
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r3)
	  li        r4, 0x1
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x64(r29)
	  mr        r4, r30
	  bl        -0xAA944
	  lbz       r0, 0x2FA9(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x560
	  lwz       r3, 0x3038(r13)
	  mr        r4, r30
	  bl        -0x6CC90

	.loc_0x560:
	  mr        r3, r29
	  mr        r4, r30
	  bl        -0xD0DE4
	  lbz       r0, 0x2FA0(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x584
	  lwz       r3, 0x302C(r13)
	  mr        r4, r30
	  bl        -0x6E8BC

	.loc_0x584:
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  lwz       r28, 0x68(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000374
 */
void drawRectangle(Graphics&, RectArea&, RectArea&, Vector3f*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801115F0
 * Size:	000260
 */
void GameCoreSection::draw1D(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x178(r1)
	  stw       r31, 0x174(r1)
	  stw       r30, 0x170(r1)
	  stw       r29, 0x16C(r1)
	  mr        r30, r3
	  mr        r31, r4
	  lwz       r0, 0x28(r30)
	  cmpwi     r0, 0x9
	  beq-      .loc_0x244
	  lwz       r6, 0x310(r31)
	  li        r29, 0
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  addi      r5, r1, 0x18
	  stw       r29, 0x18(r1)
	  addi      r4, r1, 0x128
	  stw       r29, 0x1C(r1)
	  stw       r0, 0x20(r1)
	  stw       r6, 0x24(r1)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x2FA1(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x10C
	  lwz       r3, 0x3168(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xBC
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  lwz       r4, 0x1DC(r4)
	  lbz       r0, 0x124(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xA8
	  lwz       r0, 0x2C(r30)
	  rlwinm    r0,r0,0,29,29
	  cmplwi    r0, 0
	  bne-      .loc_0xA8
	  li        r29, 0x1

	.loc_0xA8:
	  rlwinm    r0,r29,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0xBC
	  mr        r4, r31
	  bl        0x40EC8

	.loc_0xBC:
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x10C
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  lwz       r4, 0x1DC(r4)
	  li        r5, 0
	  lbz       r0, 0x124(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xF8
	  lwz       r0, 0x2C(r30)
	  rlwinm    r0,r0,0,29,29
	  cmplwi    r0, 0
	  bne-      .loc_0xF8
	  li        r5, 0x1

	.loc_0xF8:
	  rlwinm    r0,r5,0,24,31
	  cmplwi    r0, 0
	  bne-      .loc_0x10C
	  mr        r4, r31
	  bl        0x39664

	.loc_0x10C:
	  lwz       r3, 0x3120(r13)
	  mr        r4, r31
	  bl        0x5D4C
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x24(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x214
	  li        r30, 0xFF
	  stb       r30, 0x14(r1)
	  mr        r3, r31
	  addi      r4, r1, 0x14
	  stb       r30, 0x15(r1)
	  li        r5, 0x1
	  stb       r30, 0x16(r1)
	  stb       r30, 0x17(r1)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0x10(r1)
	  mr        r3, r31
	  addi      r4, r1, 0x10
	  stb       r30, 0x11(r1)
	  stb       r30, 0x12(r1)
	  stb       r30, 0x13(r1)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r3)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x1BC
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1C0

	.loc_0x1BC:
	  li        r3, 0

	.loc_0x1C0:
	  lis       r4, 0x802C
	  lwz       r5, 0x2FC8(r13)
	  mr        r9, r3
	  lwz       r6, 0x2FCC(r13)
	  lwz       r7, 0x2FD0(r13)
	  addi      r4, r4, 0x2368
	  lwz       r8, 0x2FD4(r13)
	  addi      r3, r1, 0x28
	  crclr     6, 0x6
	  bl        0x104DC4
	  mr        r3, r31
	  lwz       r4, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r3)
	  addi      r7, r1, 0x28
	  lwz       r4, 0x10(r4)
	  crclr     6, 0x6
	  lwz       r12, 0xEC(r12)
	  li        r5, 0x3C
	  li        r6, 0x5A
	  mtlr      r12
	  blrl

	.loc_0x214:
	  lwz       r3, 0x2F20(r13)
	  mr        r4, r31
	  bl        -0x98254
	  lwz       r3, 0x301C(r13)
	  mr        r4, r31
	  bl        -0x78540
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl

	.loc_0x244:
	  lwz       r0, 0x17C(r1)
	  lwz       r31, 0x174(r1)
	  lwz       r30, 0x170(r1)
	  lwz       r29, 0x16C(r1)
	  addi      r1, r1, 0x178
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80111850
 * Size:	0005C4
 */
void GameCoreSection::draw2D(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x3A0(r1)
	  stw       r31, 0x39C(r1)
	  stw       r30, 0x398(r1)
	  stw       r29, 0x394(r1)
	  mr        r30, r3
	  mr        r31, r4
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  mr        r3, r31
	  addi      r5, r1, 0x230
	  stw       r0, 0x230(r1)
	  addi      r4, r1, 0x310
	  stw       r0, 0x234(r1)
	  stw       r6, 0x238(r1)
	  stw       r7, 0x23C(r1)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  li        r29, 0xFF
	  stb       r29, 0x22C(r1)
	  mr        r3, r31
	  addi      r4, r1, 0x22C
	  stb       r29, 0x22D(r1)
	  li        r5, 0x1
	  stb       r29, 0x22E(r1)
	  stb       r29, 0x22F(r1)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r29, 0x228(r1)
	  mr        r3, r31
	  addi      r4, r1, 0x228
	  stb       r29, 0x229(r1)
	  stb       r29, 0x22A(r1)
	  stb       r29, 0x22B(r1)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r3)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x28(r30)
	  mr        r3, r31
	  lis       r5, 0x802C
	  lwz       r4, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r3)
	  rlwinm    r6,r0,2,0,29
	  lwz       r4, 0x10(r4)
	  addi      r0, r5, 0x23F4
	  lwz       r12, 0xEC(r12)
	  add       r5, r0, r6
	  crclr     6, 0x6
	  lwz       r7, 0x0(r5)
	  li        r5, 0x3C
	  li        r6, 0x78
	  mtlr      r12
	  blrl
	  lbz       r0, 0x2FA9(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x124
	  lwz       r3, 0x3038(r13)
	  mr        r4, r31
	  bl        -0x6CEA0

	.loc_0x124:
	  lwz       r0, 0x2FA4(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x504
	  mr        r3, r31
	  lwz       r4, 0x64(r30)
	  lwz       r12, 0x3B4(r3)
	  li        r5, 0
	  lwz       r4, 0x4B8(r4)
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0x1
	  li        r6, 0x2
	  li        r7, 0x3
	  bl        0x101C9C
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x3
	  bl        0x101C84
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x3
	  bl        0x101C6C
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x3
	  bl        0x101C54
	  li        r3, 0x4
	  bl        0x101F60
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x101DAC
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x101D98
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x101D84
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x101D70
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x101B94
	  li        r3, 0
	  li        r4, 0xF
	  li        r5, 0xF
	  li        r6, 0xF
	  li        r7, 0x8
	  bl        0x1016C4
	  li        r3, 0
	  li        r4, 0x7
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x6
	  bl        0x10172C
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x101794
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x101838
	  li        r3, 0x1
	  li        r4, 0x2
	  li        r5, 0x2
	  bl        0x101B1C
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0xF
	  li        r6, 0xF
	  li        r7, 0x8
	  bl        0x10164C
	  li        r3, 0x1
	  li        r4, 0x7
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x6
	  bl        0x1016B4
	  li        r3, 0x1
	  li        r4, 0xE
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x10171C
	  li        r3, 0x2
	  li        r4, 0x3
	  li        r5, 0x3
	  bl        0x101AC0
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0xF
	  li        r6, 0xF
	  li        r7, 0x8
	  bl        0x1015F0
	  li        r3, 0x2
	  li        r4, 0x7
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x6
	  bl        0x101658
	  li        r3, 0x2
	  li        r4, 0xE
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x1016C0
	  lbz       r0, 0x30EC(r13)
	  extsb     r0, r0
	  cmpwi     r0, 0
	  bne-      .loc_0x350
	  li        r0, 0x1
	  stb       r0, 0x30EC(r13)

	.loc_0x350:
	  li        r0, 0xDC
	  stb       r0, 0x30C(r1)
	  li        r4, 0xA0
	  li        r30, 0
	  stb       r4, 0x30D(r1)
	  li        r0, 0xFF
	  li        r3, 0x3
	  stb       r4, 0x30E(r1)
	  li        r4, 0xC
	  stw       r30, 0x30E8(r13)
	  stb       r0, 0x30F(r1)
	  bl        0x101954
	  lwz       r0, 0x30C(r1)
	  addi      r4, r1, 0x224
	  li        r3, 0
	  stw       r0, 0x224(r1)
	  bl        0x1018CC
	  li        r3, 0x3
	  li        r4, 0xF
	  li        r5, 0
	  li        r6, 0xE
	  li        r7, 0xF
	  bl        0x101548
	  li        r3, 0x3
	  li        r4, 0x7
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x6
	  bl        0x1015B0
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x101618
	  lwz       r0, 0x30C(r31)
	  lis       r8, 0x4330
	  lwz       r3, 0x310(r31)
	  addi      r5, r1, 0x204
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x37C(r1)
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x6118(r2)
	  mr        r3, r31
	  stw       r0, 0x38C(r1)
	  lfs       f4, -0x6110(r2)
	  addi      r4, r1, 0x214
	  stw       r8, 0x378(r1)
	  li        r6, 0
	  lfs       f1, -0x612C(r2)
	  stw       r8, 0x388(r1)
	  lfd       f0, 0x378(r1)
	  lfd       f2, 0x388(r1)
	  fsubs     f0, f0, f3
	  stw       r30, 0x204(r1)
	  fsubs     f2, f2, f3
	  stw       r30, 0x208(r1)
	  fmuls     f0, f4, f0
	  fmuls     f2, f4, f2
	  fctiwz    f0, f0
	  fctiwz    f2, f2
	  stfd      f0, 0x370(r1)
	  stfd      f2, 0x380(r1)
	  lwz       r0, 0x374(r1)
	  lwz       r7, 0x384(r1)
	  stw       r0, 0x20C(r1)
	  stw       r7, 0x210(r1)
	  lwz       r0, 0x30C(r31)
	  lwz       r7, 0x310(r31)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x35C(r1)
	  xoris     r0, r7, 0x8000
	  stw       r0, 0x36C(r1)
	  stw       r8, 0x358(r1)
	  stw       r8, 0x368(r1)
	  lfd       f0, 0x358(r1)
	  lfd       f2, 0x368(r1)
	  fsubs     f0, f0, f3
	  stw       r30, 0x214(r1)
	  fsubs     f2, f2, f3
	  stw       r30, 0x218(r1)
	  fmuls     f0, f0, f1
	  fmuls     f1, f2, f1
	  fctiwz    f0, f0
	  fctiwz    f1, f1
	  stfd      f0, 0x350(r1)
	  stfd      f1, 0x360(r1)
	  lwz       r0, 0x354(r1)
	  lwz       r7, 0x364(r1)
	  stw       r0, 0x21C(r1)
	  stw       r7, 0x220(r1)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  bl        0x1018CC
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  bl        0x1018BC
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0
	  bl        0x1018AC
	  b         .loc_0x5A8

	.loc_0x504:
	  lwz       r3, 0x3120(r13)
	  bl        0x566C
	  lwz       r3, 0xADC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x19
	  beq-      .loc_0x528
	  lwz       r3, 0x344(r30)
	  mr        r4, r31
	  bl        0xA6C60

	.loc_0x528:
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  mr        r3, r31
	  addi      r5, r1, 0x1F4
	  stw       r0, 0x1F4(r1)
	  addi      r4, r1, 0x310
	  stw       r0, 0x1F8(r1)
	  stw       r6, 0x1FC(r1)
	  stw       r7, 0x200(r1)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x30DC(r13)
	  mr        r4, r31
	  bl        0xAD380
	  lis       r3, 0x803A
	  subi      r4, r3, 0x2848
	  lwz       r3, 0x1DC(r4)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x59C
	  lwz       r0, 0x338(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x59C
	  lwz       r3, 0x30E0(r13)
	  mr        r4, r31
	  bl        0xAF25C

	.loc_0x59C:
	  lwz       r3, 0x30E4(r13)
	  mr        r4, r31
	  bl        0xB08E4

	.loc_0x5A8:
	  lwz       r0, 0x3A4(r1)
	  lwz       r31, 0x39C(r1)
	  lwz       r30, 0x398(r1)
	  lwz       r29, 0x394(r1)
	  addi      r1, r1, 0x3A0
	  mtlr      r0
	  blr
	*/
}
