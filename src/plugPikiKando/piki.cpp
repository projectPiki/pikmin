#include "Piki.h"
#include "PikiState.h"

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
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C6558
 * Size:	000300
 */
bool Piki::isSafeMePos(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  li        r29, 0

	.loc_0x20:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r29
	  bl        0x2C438
	  cmplwi    r3, 0
	  beq-      .loc_0x58
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x58
	  li        r3, 0
	  b         .loc_0x2E4

	.loc_0x58:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x3
	  blt+      .loc_0x20
	  lwz       r3, 0x30AC(r13)
	  bl        0x2C678
	  cmplwi    r3, 0
	  beq-      .loc_0x98
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x98
	  li        r3, 0
	  b         .loc_0x2E4

	.loc_0x98:
	  lwz       r3, 0x30AC(r13)
	  lwz       r30, 0x68(r3)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x18C

	.loc_0xBC:
	  cmpwi     r29, -0x1
	  bne-      .loc_0xE0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xF8

	.loc_0xE0:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xF8:
	  lwz       r6, 0x6C(r3)
	  li        r4, 0x1
	  addi      r5, r4, 0
	  cmpwi     r6, 0x16
	  addi      r0, r4, 0
	  beq-      .loc_0x11C
	  cmpwi     r6, 0x17
	  beq-      .loc_0x11C
	  li        r0, 0

	.loc_0x11C:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x130
	  cmpwi     r6, 0x18
	  beq-      .loc_0x130
	  li        r5, 0

	.loc_0x130:
	  rlwinm.   r0,r5,0,24,31
	  bne-      .loc_0x144
	  cmpwi     r6, 0x19
	  beq-      .loc_0x144
	  li        r4, 0

	.loc_0x144:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x170
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x170
	  li        r3, 0
	  b         .loc_0x2E4

	.loc_0x170:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x18C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1B4
	  li        r0, 0x1
	  b         .loc_0x1E0

	.loc_0x1B4:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1DC
	  li        r0, 0x1
	  b         .loc_0x1E0

	.loc_0x1DC:
	  li        r0, 0

	.loc_0x1E0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xBC
	  lwz       r29, 0x3020(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x284

	.loc_0x208:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x22C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x244

	.loc_0x22C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x244:
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x268
	  li        r3, 0
	  b         .loc_0x2E4

	.loc_0x268:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x284:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2AC
	  li        r0, 0x1
	  b         .loc_0x2D8

	.loc_0x2AC:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2D4
	  li        r0, 0x1
	  b         .loc_0x2D8

	.loc_0x2D4:
	  li        r0, 0

	.loc_0x2D8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x208
	  li        r3, 0x1

	.loc_0x2E4:
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
 * Address:	800C6858
 * Size:	0000AC
 */
void Piki::startDemo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        0x140
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x98
	  lwz       r3, 0x434(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x42C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x438(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x430(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x428(r31)
	  bl        0x4DC10
	  lwz       r0, 0x52C(r31)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x98
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl

	.loc_0x98:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C6904
 * Size:	000004
 */
void PikiState::stopEffect() { }

/*
 * --INFO--
 * Address:	800C6908
 * Size:	0000A0
 */
void Piki::finishDemo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x434(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x42C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x438(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x430(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x428(r31)
	  bl        0x4DB88
	  lwz       r0, 0x52C(r31)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x8C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x54(r12)
	  mtlr      r12
	  blrl

	.loc_0x8C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C69A8
 * Size:	000004
 */
void PikiState::restartEffect() { }

/*
 * --INFO--
 * Address:	800C69AC
 * Size:	0000D4
 */
void Piki::appearDemo()
{
	/*
	.loc_0x0:
	  lhz       r5, 0x510(r3)
	  cmplwi    r5, 0
	  bne-      .loc_0x28
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  lwz       r0, 0x1D8(r4)
	  rlwinm.   r0,r0,0,28,28
	  beq-      .loc_0x28
	  li        r3, 0
	  blr

	.loc_0x28:
	  cmplwi    r5, 0x1
	  bne-      .loc_0x4C
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  lwz       r0, 0x1D8(r4)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0x4C
	  li        r3, 0
	  blr

	.loc_0x4C:
	  cmplwi    r5, 0x2
	  bne-      .loc_0x70
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  lwz       r0, 0x1D8(r4)
	  rlwinm.   r0,r0,0,26,26
	  beq-      .loc_0x70
	  li        r3, 0
	  blr

	.loc_0x70:
	  lhz       r4, 0x4FC(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x94
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x70(r3)
	  rlwinm.   r0,r0,0,31,31
	  bne-      .loc_0x94
	  li        r3, 0
	  blr

	.loc_0x94:
	  cmplwi    r4, 0x1
	  bne-      .loc_0xB4
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x70(r3)
	  rlwinm.   r0,r0,0,30,30
	  bne-      .loc_0xB4
	  li        r3, 0
	  blr

	.loc_0xB4:
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x70(r3)
	  rlwinm.   r0,r0,0,29,29
	  bne-      .loc_0xCC
	  li        r3, 0
	  blr

	.loc_0xCC:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C6A80
 * Size:	000008
 */
void Piki::getUpperMotionIndex()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x39C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C6A88
 * Size:	000030
 */
void Piki::addCntCallback()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C6AB8
 * Size:	000004
 */
void Piki::subCntCallback() { }

/*
 * --INFO--
 * Address:	800C6ABC
 * Size:	000044
 */
void Piki::getAttackPower()
{
	/*
	.loc_0x0:
	  lhz       r0, 0x510(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x1C
	  lwz       r3, 0x3068(r13)
	  lwz       r3, 0x68(r3)
	  lfs       f1, 0xE8(r3)
	  blr

	.loc_0x1C:
	  cmplwi    r0, 0x1
	  bne-      .loc_0x34
	  lwz       r3, 0x3068(r13)
	  lwz       r3, 0x68(r3)
	  lfs       f1, 0xF8(r3)
	  blr

	.loc_0x34:
	  lwz       r3, 0x3068(r13)
	  lwz       r3, 0x68(r3)
	  lfs       f1, 0x108(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Piki::getPikiState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C6B00
 * Size:	00035C
 */
void Piki::findRoute(int, int, bool, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stmw      r18, 0x38(r1)
	  addi      r28, r3, 0
	  addi      r29, r4, 0
	  addi      r30, r5, 0
	  addi      r31, r6, 0
	  addi      r18, r7, 0
	  li        r21, -0x1
	  li        r19, 0

	.loc_0x2C:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r19
	  bl        0x2BE84
	  cmplwi    r3, 0
	  beq-      .loc_0x54
	  lha       r0, 0x42A(r3)
	  cmpw      r0, r30
	  bne-      .loc_0x54
	  mr        r21, r19
	  b         .loc_0x60

	.loc_0x54:
	  addi      r19, r19, 0x1
	  cmpwi     r19, 0x3
	  blt+      .loc_0x2C

	.loc_0x60:
	  lwz       r3, 0x30AC(r13)
	  bl        0x2C0D4
	  cmplwi    r3, 0
	  beq-      .loc_0x80
	  lwz       r0, 0x558(r3)
	  cmpw      r0, r30
	  bne-      .loc_0x80
	  li        r21, 0x3

	.loc_0x80:
	  cmpwi     r21, -0x1
	  bne-      .loc_0x270
	  lwz       r24, 0x3068(r13)
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r23, r3, 0
	  rlwinm    r26,r31,0,24,31
	  lis       r27, 0x7465
	  b         .loc_0x214

	.loc_0xB0:
	  cmpwi     r23, -0x1
	  bne-      .loc_0xD8
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r25, r3
	  b         .loc_0xF4

	.loc_0xD8:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r23
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r25, r3

	.loc_0xF4:
	  lha       r0, 0x2D6(r25)
	  cmpw      r0, r29
	  bne-      .loc_0x1F8
	  lha       r0, 0x2D8(r25)
	  cmpw      r0, r30
	  bne-      .loc_0x1F8
	  lbz       r0, 0x2DA(r25)
	  cmplw     r26, r0
	  bne-      .loc_0x1F8
	  lwz       r3, 0x2CC(r25)
	  lwz       r0, 0x0(r3)
	  cmpw      r0, r29
	  bne-      .loc_0x1F8
	  li        r20, 0x1
	  li        r19, 0
	  li        r22, 0
	  b         .loc_0x1F0

	.loc_0x138:
	  lwz       r4, 0x2CC(r25)
	  addi      r0, r22, 0x4
	  lwz       r3, 0x2CC(r28)
	  addi      r19, r19, 0x1
	  lwzx      r4, r4, r22
	  stwx      r4, r3, r22
	  lwz       r4, 0x2CC(r28)
	  lwz       r3, 0x2CC(r25)
	  add       r4, r4, r22
	  lwz       r5, 0x0(r4)
	  lbzx      r0, r3, r0
	  cmpw      r5, r30
	  stb       r0, 0x4(r4)
	  bne-      .loc_0x18C
	  extsh     r0, r29
	  sth       r0, 0x2D6(r28)
	  extsh     r0, r30
	  addi      r3, r19, 0
	  sth       r0, 0x2D8(r28)
	  stb       r31, 0x2DA(r28)
	  b         .loc_0x348

	.loc_0x18C:
	  lwz       r3, 0x302C(r13)
	  addi      r4, r27, 0x7374
	  bl        -0x26B8C
	  cmpw      r3, r19
	  bgt-      .loc_0x1EC
	  cmpwi     r3, 0
	  li        r20, 0
	  li        r5, 0
	  ble-      .loc_0x1EC
	  cmpwi     r3, 0x8
	  subi      r4, r3, 0x8
	  ble-      .loc_0x1D8
	  addi      r0, r4, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r4, 0
	  mtctr     r0
	  ble-      .loc_0x1D8

	.loc_0x1D0:
	  addi      r5, r5, 0x8
	  bdnz+     .loc_0x1D0

	.loc_0x1D8:
	  sub       r0, r3, r5
	  cmpw      r5, r3
	  mtctr     r0
	  bge-      .loc_0x1EC

	.loc_0x1E8:
	  bdnz-     .loc_0x1E8

	.loc_0x1EC:
	  addi      r22, r22, 0x8

	.loc_0x1F0:
	  rlwinm.   r0,r20,0,24,31
	  bne+      .loc_0x138

	.loc_0x1F8:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r23
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r23, r3

	.loc_0x214:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r23
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x23C
	  li        r0, 0x1
	  b         .loc_0x268

	.loc_0x23C:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r23
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x264
	  li        r0, 0x1
	  b         .loc_0x268

	.loc_0x264:
	  li        r0, 0

	.loc_0x268:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xB0

	.loc_0x270:
	  extsh     r0, r29
	  sth       r0, 0x2D6(r28)
	  extsh     r0, r30
	  cmpwi     r21, -0x1
	  sth       r0, 0x2D8(r28)
	  stb       r31, 0x2DA(r28)
	  beq-      .loc_0x2B8
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  bl        -0x26D88
	  lwz       r5, 0x2CC(r28)
	  addi      r6, r29, 0
	  addi      r7, r21, 0
	  addi      r8, r31, 0
	  addi      r4, r28, 0x94
	  bl        -0x24DB0
	  b         .loc_0x334

	.loc_0x2B8:
	  rlwinm.   r0,r18,0,24,31
	  beq-      .loc_0x310
	  lbz       r0, -0x5F14(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x310
	  li        r0, 0x1
	  stb       r0, 0x2D4(r28)
	  lwz       r0, 0x2D0(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x308
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  bl        -0x26DDC
	  lwz       r4, 0x2CC(r28)
	  addi      r5, r29, 0
	  addi      r6, r30, 0
	  addi      r7, r31, 0
	  bl        -0x27808
	  stw       r3, 0x2D0(r28)

	.loc_0x308:
	  li        r3, -0x37
	  b         .loc_0x348

	.loc_0x310:
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  bl        -0x26E0C
	  lwz       r4, 0x2CC(r28)
	  addi      r5, r29, 0
	  addi      r6, r30, 0
	  addi      r7, r31, 0
	  bl        -0x27260

	.loc_0x334:
	  cmpwi     r3, 0
	  bne-      .loc_0x348
	  li        r0, -0x1
	  sth       r0, 0x2D8(r28)
	  sth       r0, 0x2D6(r28)

	.loc_0x348:
	  lmw       r18, 0x38(r1)
	  lwz       r0, 0x74(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void Piki::initRouteTraceDynamic(Creature*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C6E5C
 * Size:	0001CC
 */
void Piki::moveRouteTraceDynamic(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  mr        r30, r3
	  bl        0x674
	  cmpwi     r3, 0x2
	  beq-      .loc_0x28
	  b         .loc_0x1B4

	.loc_0x28:
	  lbz       r0, 0x2D4(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  li        r3, 0x2
	  b         .loc_0x1B4

	.loc_0x3C:
	  lwz       r4, 0x32C(r30)
	  addi      r3, r1, 0x24
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, 0x24(r1)
	  lfs       f1, 0x94(r30)
	  lfs       f3, 0x28(r1)
	  lfs       f0, 0x98(r30)
	  fsubs     f2, f2, f1
	  lfs       f4, 0x2C(r1)
	  fsubs     f3, f3, f0
	  lfs       f0, 0x9C(r30)
	  fmuls     f2, f2, f2
	  fsubs     f4, f4, f0
	  lfs       f0, -0x6A48(r2)
	  fmuls     f1, f3, f3
	  fmuls     f3, f4, f4
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xF0
	  fsqrte    f1, f4
	  lfd       f3, -0x6A40(r2)
	  lfd       f2, -0x6A38(r2)
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
	  stfs      f0, 0x14(r1)
	  lfs       f4, 0x14(r1)

	.loc_0xF0:
	  lfs       f0, -0x6A30(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x104
	  li        r3, 0
	  b         .loc_0x1B4

	.loc_0x104:
	  lha       r0, 0x328(r30)
	  cmpwi     r0, 0x4
	  blt-      .loc_0x1B0
	  lha       r3, 0x2DC(r30)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x4C(r1)
	  lis       r0, 0x4330
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x54(r1)
	  lfd       f3, -0x6A28(r2)
	  stw       r0, 0x50(r1)
	  lfs       f0, -0x6A2C(r2)
	  stw       r0, 0x48(r1)
	  lfd       f2, 0x50(r1)
	  lfd       f1, 0x48(r1)
	  fsubs     f2, f2, f3
	  fsubs     f1, f1, f3
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1B0
	  lwz       r31, 0x32C(r30)
	  addi      r3, r1, 0x18
	  addi      r4, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0
	  addi      r4, r1, 0x18
	  li        r5, 0x1
	  bl        .loc_0x1CC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x198
	  li        r0, 0
	  stw       r0, 0x32C(r30)
	  b         .loc_0x1A0

	.loc_0x198:
	  stw       r31, 0x32C(r30)
	  li        r0, 0x1

	.loc_0x1A0:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x1B0
	  li        r3, 0x1
	  b         .loc_0x1B4

	.loc_0x1B0:
	  li        r3, 0x2

	.loc_0x1B4:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr

	.loc_0x1CC:
	*/
}

/*
 * --INFO--
 * Address:	800C7028
 * Size:	0004C0
 */
void Piki::initRouteTrace(Vector3f&, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x188(r1)
	  stfd      f31, 0x180(r1)
	  stfd      f30, 0x178(r1)
	  stfd      f29, 0x170(r1)
	  stfd      f28, 0x168(r1)
	  stfd      f27, 0x160(r1)
	  stfd      f26, 0x158(r1)
	  stfd      f25, 0x150(r1)
	  stmw      r27, 0x13C(r1)
	  mr        r28, r3
	  addi      r29, r4, 0
	  addi      r30, r5, 0
	  lwz       r31, 0x2D0(r3)
	  cmplwi    r31, 0
	  beq-      .loc_0x64
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  bl        -0x27068
	  mr        r4, r31
	  bl        -0x2794C
	  li        r0, 0
	  stw       r0, 0x2D0(r28)

	.loc_0x64:
	  li        r0, 0
	  stb       r0, 0x2D4(r28)
	  li        r31, 0x1
	  lhz       r0, 0x510(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x80
	  li        r31, 0

	.loc_0x80:
	  lis       r6, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r8, r31, 0
	  addi      r4, r1, 0x130
	  addi      r5, r1, 0x12C
	  addi      r6, r6, 0x7374
	  addi      r7, r28, 0x94
	  li        r9, 0x1
	  li        r10, 0
	  bl        -0x2674C
	  lwz       r3, 0x130(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x204
	  lwz       r4, 0x12C(r1)
	  cmplwi    r4, 0
	  beq-      .loc_0x204
	  lfs       f1, 0x4(r3)
	  lfs       f7, 0x98(r28)
	  lfs       f0, 0x0(r3)
	  lfs       f8, 0x94(r28)
	  fsubs     f2, f1, f7
	  lfs       f1, 0x8(r3)
	  fsubs     f3, f0, f8
	  lfs       f6, 0x9C(r28)
	  fmuls     f0, f2, f2
	  fsubs     f2, f1, f6
	  lfs       f5, 0x8(r4)
	  fmuls     f1, f3, f3
	  lfs       f4, 0x4(r4)
	  fmuls     f2, f2, f2
	  fsubs     f5, f5, f6
	  lfs       f3, 0x0(r4)
	  fadds     f0, f1, f0
	  lfs       f1, -0x6A48(r2)
	  fsubs     f6, f4, f7
	  fsubs     f7, f3, f8
	  fadds     f0, f2, f0
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x174
	  fsqrte    f2, f0
	  lfd       f4, -0x6A40(r2)
	  lfd       f3, -0x6A38(r2)
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f0, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f0, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f0, f1
	  fsub      f1, f3, f1
	  fmul      f1, f2, f1
	  fmul      f0, f0, f1
	  frsp      f0, f0
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x50(r1)

	.loc_0x174:
	  fmuls     f3, f7, f7
	  lfs       f1, -0x6A48(r2)
	  fmuls     f2, f6, f6
	  fmuls     f4, f5, f5
	  fadds     f2, f3, f2
	  fadds     f5, f4, f2
	  fcmpo     cr0, f5, f1
	  ble-      .loc_0x1EC
	  fsqrte    f2, f5
	  lfd       f4, -0x6A40(r2)
	  lfd       f3, -0x6A38(r2)
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f5, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f5, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f5, f1
	  fsub      f1, f3, f1
	  fmul      f1, f2, f1
	  fmul      f1, f5, f1
	  frsp      f1, f1
	  stfs      f1, 0x4C(r1)
	  lfs       f5, 0x4C(r1)

	.loc_0x1EC:
	  fcmpo     cr0, f0, f5
	  ble-      .loc_0x1FC
	  lwz       r27, 0x12C(r1)
	  b         .loc_0x220

	.loc_0x1FC:
	  lwz       r27, 0x130(r1)
	  b         .loc_0x220

	.loc_0x204:
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r6, r31, 0
	  addi      r4, r4, 0x7374
	  addi      r5, r28, 0x94
	  bl        -0x26158
	  mr        r27, r3

	.loc_0x220:
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r5, r29, 0
	  addi      r4, r4, 0x7374
	  li        r6, 0
	  bl        -0x26174
	  lwz       r5, 0x94(r28)
	  rlwinm.   r0,r31,0,24,31
	  lwz       r4, 0x98(r28)
	  mr        r6, r3
	  stw       r5, 0x2E0(r28)
	  stw       r4, 0x2E4(r28)
	  lwz       r0, 0x9C(r28)
	  stw       r0, 0x2E8(r28)
	  lwz       r3, 0x0(r29)
	  lwz       r0, 0x4(r29)
	  stw       r3, 0x2EC(r28)
	  stw       r0, 0x2F0(r28)
	  lwz       r0, 0x8(r29)
	  stw       r0, 0x2F4(r28)
	  beq-      .loc_0x280
	  lhz       r0, 0x3028(r13)
	  ori       r0, r0, 0x1
	  sth       r0, 0x3028(r13)

	.loc_0x280:
	  lwz       r4, 0x10(r27)
	  mr        r3, r28
	  lwz       r5, 0x10(r6)
	  addi      r7, r30, 0
	  li        r6, 0
	  bl        -0x7BC
	  extsh     r3, r3
	  rlwinm.   r0,r31,0,24,31
	  sth       r3, 0x328(r28)
	  beq-      .loc_0x2B0
	  li        r0, 0
	  sth       r0, 0x3028(r13)

	.loc_0x2B0:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x2D8
	  lbz       r0, 0x2D4(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x2D8
	  lha       r0, 0x328(r28)
	  cmpwi     r0, -0x37
	  bne-      .loc_0x2D8
	  li        r3, 0x1
	  b         .loc_0x490

	.loc_0x2D8:
	  lha       r0, 0x328(r28)
	  cmpwi     r0, 0
	  bgt-      .loc_0x2EC
	  li        r3, 0
	  b         .loc_0x490

	.loc_0x2EC:
	  li        r0, -0x1
	  sth       r0, 0x2DC(r28)
	  addi      r4, r28, 0
	  addi      r3, r1, 0x98
	  lha       r5, 0x2DC(r28)
	  addi      r5, r5, 0x1
	  bl        0x8BC
	  lha       r5, 0x2DC(r28)
	  mr        r4, r28
	  lfs       f30, 0x98(r1)
	  addi      r3, r1, 0x8C
	  lfs       f29, 0x9C(r1)
	  lfs       f28, 0xA0(r1)
	  addi      r5, r5, 0x2
	  bl        0x89C
	  lha       r4, 0x2DC(r28)
	  mr        r3, r28
	  lfs       f27, 0x8C(r1)
	  lfs       f26, 0x90(r1)
	  addi      r4, r4, 0x2
	  lfs       f25, 0x94(r1)
	  bl        0x9A0
	  lha       r4, 0x2DC(r28)
	  fmr       f31, f1
	  addi      r3, r28, 0
	  addi      r4, r4, 0x1
	  bl        0x98C
	  stfs      f30, 0xDC(r1)
	  addi      r3, r1, 0xDC
	  lfs       f2, -0x6A48(r2)
	  addi      r4, r1, 0xBC
	  stfs      f29, 0xE0(r1)
	  addi      r5, r1, 0xCC
	  stfs      f28, 0xE4(r1)
	  addi      r6, r1, 0xD8
	  stfs      f27, 0xE8(r1)
	  stfs      f26, 0xEC(r1)
	  stfs      f25, 0xF0(r1)
	  stfs      f2, 0xD4(r1)
	  stfs      f1, 0xF4(r1)
	  stfs      f2, 0xD0(r1)
	  stfs      f31, 0xF8(r1)
	  stfs      f2, 0xCC(r1)
	  lfs       f0, 0x94(r28)
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0x98(r28)
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0x9C(r28)
	  stfs      f0, 0xC4(r1)
	  stfs      f2, 0xC8(r1)
	  bl        -0x40050
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x484
	  lha       r4, 0x2DC(r28)
	  addi      r3, r28, 0
	  addi      r4, r4, 0x2
	  bl        0x8AC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x484
	  li        r0, 0
	  sth       r0, 0x2DC(r28)
	  addi      r4, r28, 0
	  addi      r3, r1, 0x80
	  li        r5, -0x1
	  bl        0x7D4
	  lwz       r6, 0x80(r1)
	  mr        r4, r28
	  lwz       r0, 0x84(r1)
	  addi      r3, r1, 0x74
	  li        r5, -0x1
	  stw       r6, 0x2F8(r28)
	  stw       r0, 0x2FC(r28)
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x300(r28)
	  bl        0x7AC
	  lwz       r6, 0x74(r1)
	  mr        r4, r28
	  lwz       r0, 0x78(r1)
	  addi      r3, r1, 0x68
	  li        r5, 0x1
	  stw       r6, 0x304(r28)
	  stw       r0, 0x308(r28)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0x30C(r28)
	  bl        0x784
	  lwz       r6, 0x68(r1)
	  mr        r4, r28
	  lwz       r0, 0x6C(r1)
	  addi      r3, r1, 0x5C
	  li        r5, 0x2
	  stw       r6, 0x310(r28)
	  stw       r0, 0x314(r28)
	  lwz       r0, 0x70(r1)
	  stw       r0, 0x318(r28)
	  bl        0x75C
	  lwz       r3, 0x5C(r1)
	  lwz       r0, 0x60(r1)
	  stw       r3, 0x31C(r28)
	  stw       r0, 0x320(r28)
	  lwz       r0, 0x64(r1)
	  stw       r0, 0x324(r28)
	  b         .loc_0x48C

	.loc_0x484:
	  mr        r3, r28
	  bl        0x8B8

	.loc_0x48C:
	  li        r3, 0x1

	.loc_0x490:
	  lmw       r27, 0x13C(r1)
	  lwz       r0, 0x18C(r1)
	  lfd       f31, 0x180(r1)
	  lfd       f30, 0x178(r1)
	  lfd       f29, 0x170(r1)
	  lfd       f28, 0x168(r1)
	  lfd       f27, 0x160(r1)
	  lfd       f26, 0x158(r1)
	  lfd       f25, 0x150(r1)
	  addi      r1, r1, 0x188
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C74E8
 * Size:	000700
 */
void Piki::moveRouteTrace(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x250(r1)
	  stfd      f31, 0x248(r1)
	  stfd      f30, 0x240(r1)
	  stfd      f29, 0x238(r1)
	  stfd      f28, 0x230(r1)
	  stfd      f27, 0x228(r1)
	  stfd      f26, 0x220(r1)
	  stfd      f25, 0x218(r1)
	  stfd      f24, 0x210(r1)
	  fmr       f24, f1
	  stfd      f23, 0x208(r1)
	  stw       r31, 0x204(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x200(r1)
	  lbz       r0, -0x5F14(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x29C
	  lbz       r0, 0x2D4(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x29C
	  lwz       r30, 0x2D0(r31)
	  cmplwi    r30, 0
	  beq-      .loc_0x26C
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  bl        -0x27548
	  mr        r4, r30
	  bl        -0x27EB4
	  cmpwi     r3, -0x2
	  bne-      .loc_0x8C
	  li        r3, 0x1
	  b         .loc_0x6C4

	.loc_0x8C:
	  cmpwi     r3, -0x1
	  bne-      .loc_0x9C
	  li        r3, 0x2
	  b         .loc_0x6C4

	.loc_0x9C:
	  extsh     r0, r3
	  sth       r0, 0x328(r31)
	  li        r0, -0x1
	  addi      r4, r31, 0
	  sth       r0, 0x2DC(r31)
	  addi      r3, r1, 0x158
	  lha       r5, 0x2DC(r31)
	  addi      r5, r5, 0x1
	  bl        .loc_0x700
	  lha       r5, 0x2DC(r31)
	  mr        r4, r31
	  lfs       f25, 0x158(r1)
	  addi      r3, r1, 0x14C
	  lfs       f26, 0x15C(r1)
	  lfs       f27, 0x160(r1)
	  addi      r5, r5, 0x2
	  bl        .loc_0x700
	  lha       r4, 0x2DC(r31)
	  mr        r3, r31
	  lfs       f28, 0x14C(r1)
	  lfs       f29, 0x150(r1)
	  addi      r4, r4, 0x2
	  lfs       f30, 0x154(r1)
	  bl        0x728
	  lha       r4, 0x2DC(r31)
	  fmr       f23, f1
	  addi      r3, r31, 0
	  addi      r4, r4, 0x1
	  bl        0x714
	  stfs      f25, 0x1C4(r1)
	  addi      r3, r1, 0x1C4
	  lfs       f2, -0x6A48(r2)
	  addi      r4, r1, 0x1A4
	  stfs      f26, 0x1C8(r1)
	  addi      r5, r1, 0x1B4
	  stfs      f27, 0x1CC(r1)
	  addi      r6, r1, 0x1C0
	  stfs      f28, 0x1D0(r1)
	  stfs      f29, 0x1D4(r1)
	  stfs      f30, 0x1D8(r1)
	  stfs      f2, 0x1BC(r1)
	  stfs      f1, 0x1DC(r1)
	  stfs      f2, 0x1B8(r1)
	  stfs      f23, 0x1E0(r1)
	  stfs      f2, 0x1B4(r1)
	  lfs       f0, 0x94(r31)
	  stfs      f0, 0x1A4(r1)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x1A8(r1)
	  lfs       f0, 0x9C(r31)
	  stfs      f0, 0x1AC(r1)
	  stfs      f2, 0x1B0(r1)
	  bl        -0x402C8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x23C
	  lha       r4, 0x2DC(r31)
	  addi      r3, r31, 0
	  addi      r4, r4, 0x2
	  bl        0x634
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x23C
	  li        r0, 0
	  sth       r0, 0x2DC(r31)
	  addi      r4, r31, 0
	  addi      r3, r1, 0x140
	  li        r5, -0x1
	  bl        .loc_0x700
	  lwz       r6, 0x140(r1)
	  mr        r4, r31
	  lwz       r0, 0x144(r1)
	  addi      r3, r1, 0x134
	  li        r5, -0x1
	  stw       r6, 0x2F8(r31)
	  stw       r0, 0x2FC(r31)
	  lwz       r0, 0x148(r1)
	  stw       r0, 0x300(r31)
	  bl        .loc_0x700
	  lwz       r6, 0x134(r1)
	  mr        r4, r31
	  lwz       r0, 0x138(r1)
	  addi      r3, r1, 0x128
	  li        r5, 0x1
	  stw       r6, 0x304(r31)
	  stw       r0, 0x308(r31)
	  lwz       r0, 0x13C(r1)
	  stw       r0, 0x30C(r31)
	  bl        .loc_0x700
	  lwz       r6, 0x128(r1)
	  mr        r4, r31
	  lwz       r0, 0x12C(r1)
	  addi      r3, r1, 0x11C
	  li        r5, 0x2
	  stw       r6, 0x310(r31)
	  stw       r0, 0x314(r31)
	  lwz       r0, 0x130(r1)
	  stw       r0, 0x318(r31)
	  bl        .loc_0x700
	  lwz       r3, 0x11C(r1)
	  lwz       r0, 0x120(r1)
	  stw       r3, 0x31C(r31)
	  stw       r0, 0x320(r31)
	  lwz       r0, 0x124(r1)
	  stw       r0, 0x324(r31)
	  b         .loc_0x244

	.loc_0x23C:
	  mr        r3, r31
	  bl        0x640

	.loc_0x244:
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  bl        -0x27728
	  lwz       r4, 0x2D0(r31)
	  bl        -0x2800C
	  li        r0, 0
	  stw       r0, 0x2D0(r31)
	  stb       r0, 0x2D4(r31)
	  b         .loc_0x29C

	.loc_0x26C:
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r4, 0x7374
	  bl        -0x27750
	  lwz       r4, 0x2CC(r31)
	  li        r7, 0
	  lha       r5, 0x2D6(r31)
	  lha       r6, 0x2D8(r31)
	  bl        -0x2817C
	  stw       r3, 0x2D0(r31)
	  li        r3, 0x2
	  b         .loc_0x6C4

	.loc_0x29C:
	  lfs       f1, -0x42A8(r13)
	  mr        r4, r31
	  lfs       f0, -0x42A4(r13)
	  addi      r3, r1, 0x110
	  stfs      f1, 0x198(r1)
	  stfs      f0, 0x19C(r1)
	  lfs       f0, -0x42A0(r13)
	  stfs      f0, 0x1A0(r1)
	  lha       r5, 0x2DC(r31)
	  bl        .loc_0x700
	  lha       r5, 0x2DC(r31)
	  mr        r4, r31
	  lfs       f31, 0x110(r1)
	  addi      r3, r1, 0x104
	  lfs       f30, 0x114(r1)
	  lfs       f29, 0x118(r1)
	  addi      r5, r5, 0x1
	  bl        .loc_0x700
	  lfs       f1, 0x104(r1)
	  lfs       f0, 0x108(r1)
	  fsubs     f1, f1, f31
	  lfs       f2, 0x10C(r1)
	  fsubs     f0, f0, f30
	  stfs      f1, 0x174(r1)
	  fsubs     f1, f2, f29
	  stfs      f0, 0x178(r1)
	  stfs      f1, 0x17C(r1)
	  lfs       f1, 0x174(r1)
	  lfs       f0, 0x178(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x17C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xB9BD0
	  lfs       f0, -0x6A48(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x35C
	  lfs       f0, 0x174(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x174(r1)
	  lfs       f0, 0x178(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x178(r1)
	  lfs       f0, 0x17C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x17C(r1)

	.loc_0x35C:
	  lfs       f0, 0x94(r31)
	  lfs       f5, 0x174(r1)
	  fsubs     f2, f0, f31
	  lfs       f0, -0x6A48(r2)
	  stfs      f2, 0xB4(r1)
	  lfs       f2, 0x98(r31)
	  lfs       f4, 0x9C(r31)
	  fsubs     f2, f2, f30
	  lfs       f3, 0xB4(r1)
	  lfs       f27, 0x178(r1)
	  fsubs     f4, f4, f29
	  lfs       f28, 0x17C(r1)
	  fmuls     f3, f5, f3
	  fmuls     f2, f27, f2
	  fmuls     f4, f28, f4
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fdivs     f2, f2, f1
	  fcmpo     cr0, f2, f0
	  fmr       f26, f2
	  bge-      .loc_0x3B4
	  fmr       f26, f0

	.loc_0x3B4:
	  lfs       f0, -0x6A20(r2)
	  fcmpo     cr0, f26, f0
	  ble-      .loc_0x3C4
	  fmr       f26, f0

	.loc_0x3C4:
	  fmuls     f0, f26, f1
	  addi      r6, r1, 0x64
	  addi      r5, r1, 0x60
	  addi      r4, r1, 0x5C
	  fmuls     f2, f28, f0
	  fmuls     f1, f27, f0
	  addi      r3, r1, 0xE0
	  fmuls     f0, f5, f0
	  stfs      f2, 0x64(r1)
	  stfs      f1, 0x60(r1)
	  stfs      f0, 0x5C(r1)
	  bl        -0x907BC
	  lfs       f1, 0xE0(r1)
	  lfs       f0, 0xE8(r1)
	  fadds     f3, f1, f31
	  lfs       f2, 0x94(r31)
	  lfs       f30, -0x6A48(r2)
	  fadds     f1, f0, f29
	  lfs       f0, 0x9C(r31)
	  fsubs     f31, f3, f2
	  fsubs     f29, f1, f0
	  fmuls     f0, f30, f30
	  fmuls     f1, f31, f31
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xB9CD4
	  fmr       f23, f1
	  lfs       f0, -0x6A48(r2)
	  fcmpu     cr0, f0, f23
	  beq-      .loc_0x44C
	  fdivs     f31, f31, f23
	  fdivs     f30, f30, f23
	  fdivs     f29, f29, f23

	.loc_0x44C:
	  lha       r4, 0x2DC(r31)
	  addi      r3, r31, 0
	  addi      r4, r4, 0x1
	  bl        0x3C8
	  fmuls     f25, f26, f1
	  lha       r4, 0x2DC(r31)
	  mr        r3, r31
	  bl        0x3B8
	  lfs       f2, -0x6A20(r2)
	  fabs      f3, f23
	  fsubs     f0, f2, f26
	  fmuls     f0, f0, f1
	  fadds     f0, f0, f25
	  fdivs     f0, f3, f0
	  fcmpo     cr0, f0, f2
	  fmr       f25, f0
	  ble-      .loc_0x498
	  fmr       f25, f2
	  b         .loc_0x4A8

	.loc_0x498:
	  lfs       f0, -0x6A48(r2)
	  fcmpo     cr0, f25, f0
	  bge-      .loc_0x4A8
	  fmr       f25, f0

	.loc_0x4A8:
	  lfs       f0, -0x6A20(r2)
	  fcmpo     cr0, f26, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x564
	  lha       r3, 0x328(r31)
	  lha       r4, 0x2DC(r31)
	  subi      r0, r3, 0x2
	  cmpw      r4, r0
	  blt-      .loc_0x4D4
	  li        r3, 0
	  b         .loc_0x6C4

	.loc_0x4D4:
	  addi      r0, r4, 0x1
	  sth       r0, 0x2DC(r31)
	  mr        r3, r31
	  lfs       f23, -0x6A48(r2)
	  bl        0x39C
	  fmr       f1, f23
	  addi      r3, r1, 0x198
	  addi      r4, r31, 0x2F8
	  bl        0x4B150
	  lfs       f1, 0x198(r1)
	  lfs       f0, 0x19C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x1A0(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xB9DC0
	  lfs       f0, -0x6A48(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x54C
	  lfs       f0, 0x198(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x198(r1)
	  lfs       f0, 0x19C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x19C(r1)
	  lfs       f0, 0x1A0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x1A0(r1)

	.loc_0x54C:
	  fmr       f1, f24
	  addi      r3, r31, 0
	  addi      r4, r1, 0x198
	  bl        0x4398
	  li        r3, 0x2
	  b         .loc_0x6C4

	.loc_0x564:
	  fmr       f1, f26
	  addi      r3, r1, 0x198
	  addi      r4, r31, 0x2F8
	  bl        0x4B0D4
	  lfs       f1, 0x198(r1)
	  lfs       f0, 0x19C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x1A0(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xB9E3C
	  lfs       f0, -0x6A48(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x5C8
	  lfs       f0, 0x198(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x198(r1)
	  lfs       f0, 0x19C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x19C(r1)
	  lfs       f0, 0x1A0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x1A0(r1)

	.loc_0x5C8:
	  fmuls     f2, f29, f25
	  addi      r6, r1, 0x58
	  fmuls     f1, f30, f25
	  addi      r5, r1, 0x54
	  fmuls     f0, f31, f25
	  stfs      f2, 0x58(r1)
	  addi      r4, r1, 0x50
	  addi      r3, r1, 0xC8
	  stfs      f1, 0x54(r1)
	  stfs      f0, 0x50(r1)
	  bl        -0x909BC
	  lfs       f0, -0x6A20(r2)
	  addi      r6, r1, 0x4C
	  lfs       f1, 0x1A0(r1)
	  addi      r5, r1, 0x48
	  fsubs     f2, f0, f25
	  lfs       f0, 0x198(r1)
	  addi      r4, r1, 0x44
	  addi      r3, r1, 0xD4
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f2
	  stfs      f1, 0x4C(r1)
	  lfs       f1, 0x19C(r1)
	  fmuls     f1, f1, f2
	  stfs      f0, 0x44(r1)
	  stfs      f1, 0x48(r1)
	  bl        -0x909FC
	  lfs       f2, 0xD4(r1)
	  lfs       f0, 0xC8(r1)
	  lfs       f1, 0xD8(r1)
	  fadds     f2, f2, f0
	  lfs       f0, 0xCC(r1)
	  fadds     f0, f1, f0
	  stfs      f2, 0x198(r1)
	  stfs      f0, 0x19C(r1)
	  lfs       f1, 0xDC(r1)
	  lfs       f0, 0xD0(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1A0(r1)
	  lfs       f0, 0x19C(r1)
	  lfs       f4, 0x1A0(r1)
	  lfs       f3, 0x198(r1)
	  fmuls     f1, f0, f27
	  lfs       f2, 0x174(r1)
	  fmuls     f4, f4, f28
	  lfs       f0, -0x6A48(r2)
	  fmuls     f2, f3, f2
	  fadds     f1, f2, f1
	  fadds     f1, f4, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x6B0
	  lwz       r0, 0x174(r1)
	  lwz       r3, 0x178(r1)
	  stw       r0, 0x198(r1)
	  lwz       r0, 0x17C(r1)
	  stw       r3, 0x19C(r1)
	  stw       r0, 0x1A0(r1)

	.loc_0x6B0:
	  fmr       f1, f24
	  addi      r3, r31, 0
	  addi      r4, r1, 0x198
	  bl        0x4234
	  li        r3, 0x2

	.loc_0x6C4:
	  lwz       r0, 0x254(r1)
	  lfd       f31, 0x248(r1)
	  lfd       f30, 0x240(r1)
	  lfd       f29, 0x238(r1)
	  lfd       f28, 0x230(r1)
	  lfd       f27, 0x228(r1)
	  lfd       f26, 0x220(r1)
	  lfd       f25, 0x218(r1)
	  lfd       f24, 0x210(r1)
	  lfd       f23, 0x208(r1)
	  lwz       r31, 0x204(r1)
	  lwz       r30, 0x200(r1)
	  addi      r1, r1, 0x250
	  mtlr      r0
	  blr

	.loc_0x700:
	*/
}

/*
 * --INFO--
 * Address:	800C7BE8
 * Size:	0000B8
 */
void Piki::crGetPoint(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x30(r1)
	  addi      r30, r3, 0
	  bge-      .loc_0x40
	  lfs       f0, 0x2E0(r31)
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x2E4(r31)
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x2E8(r31)
	  stfs      f0, 0x8(r30)
	  b         .loc_0xA0

	.loc_0x40:
	  lha       r0, 0x328(r31)
	  cmpw      r5, r0
	  blt-      .loc_0x68
	  lfs       f0, 0x2EC(r31)
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x2F0(r31)
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x2F4(r31)
	  stfs      f0, 0x8(r30)
	  b         .loc_0xA0

	.loc_0x68:
	  lwz       r4, 0x2CC(r31)
	  rlwinm    r0,r5,3,0,28
	  lis       r6, 0x7465
	  lwz       r3, 0x302C(r13)
	  lwzx      r5, r4, r0
	  addi      r4, r6, 0x7374
	  bl        -0x265F0
	  cmplwi    r3, 0
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x8(r30)

	.loc_0xA0:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C7CA0
 * Size:	000068
 */
void Piki::crPointOpen(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  blt-      .loc_0x28
	  lha       r0, 0x328(r31)
	  cmpw      r4, r0
	  blt-      .loc_0x30

	.loc_0x28:
	  li        r3, 0x1
	  b         .loc_0x54

	.loc_0x30:
	  lwz       r5, 0x2CC(r31)
	  rlwinm    r0,r4,3,0,28
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  lwzx      r5, r5, r0
	  addi      r4, r4, 0x7374
	  bl        -0x26670
	  cmplwi    r3, 0
	  lbz       r3, 0x38(r3)

	.loc_0x54:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C7D08
 * Size:	000060
 */
void Piki::crGetRadius(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bge-      .loc_0x1C
	  lfs       f1, -0x6A1C(r2)
	  b         .loc_0x50

	.loc_0x1C:
	  lha       r0, 0x328(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x30
	  lfs       f1, -0x6A18(r2)
	  b         .loc_0x50

	.loc_0x30:
	  lwz       r5, 0x2CC(r3)
	  rlwinm    r0,r4,3,0,28
	  lis       r4, 0x7465
	  lwz       r3, 0x302C(r13)
	  lwzx      r5, r5, r0
	  addi      r4, r4, 0x7374
	  bl        -0x266D8
	  lfs       f1, 0xC(r3)

	.loc_0x50:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C7D68
 * Size:	000108
 */
void Piki::crMakeRefs()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  lis       r31, 0x7465
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  li        r29, 0
	  stw       r28, 0x38(r1)
	  addi      r28, r3, 0
	  addi      r30, r28, 0

	.loc_0x2C:
	  lha       r0, 0x2DC(r28)
	  subi      r3, r29, 0x1
	  add.      r3, r0, r3
	  bge-      .loc_0x5C
	  lfs       f0, 0x2E0(r28)
	  addi      r4, r1, 0x28
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x2E4(r28)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x2E8(r28)
	  stfs      f0, 0x30(r1)
	  b         .loc_0xC0

	.loc_0x5C:
	  lha       r0, 0x328(r28)
	  cmpw      r3, r0
	  blt-      .loc_0x88
	  lfs       f0, 0x2EC(r28)
	  addi      r4, r1, 0x28
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x2F0(r28)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x2F4(r28)
	  stfs      f0, 0x30(r1)
	  b         .loc_0xC0

	.loc_0x88:
	  lwz       r5, 0x2CC(r28)
	  rlwinm    r0,r3,3,0,28
	  lwz       r3, 0x302C(r13)
	  addi      r4, r31, 0x7374
	  lwzx      r5, r5, r0
	  bl        -0x2678C
	  cmplwi    r3, 0
	  lfs       f0, 0x0(r3)
	  addi      r4, r1, 0x28
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x30(r1)

	.loc_0xC0:
	  lwz       r3, 0x0(r4)
	  addi      r29, r29, 0x1
	  lwz       r0, 0x4(r4)
	  cmpwi     r29, 0x4
	  stw       r3, 0x2F8(r30)
	  stw       r0, 0x2FC(r30)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x300(r30)
	  addi      r30, r30, 0xC
	  blt+      .loc_0x2C
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C7E70
 * Size:	00001C
 */
bool Piki::hasBomb()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x2AC(r3)
	  neg       r0, r0
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,24,31
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C7E8C
 * Size:	000090
 */
void Piki::startFire()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x102
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  li        r31, 0x1
	  stw       r30, 0x38(r1)
	  addi      r30, r3, 0
	  addi      r5, r30, 0x94
	  sth       r31, 0x524(r3)
	  lwz       r3, 0x3038(r13)
	  bl        -0x23AB0
	  lfs       f1, -0x6A48(r2)
	  addi      r0, r30, 0x464
	  lfs       f0, -0x6A20(r2)
	  addi      r4, r1, 0xC
	  stfs      f1, 0x14(r1)
	  stfs      f1, 0x10(r1)
	  stfs      f1, 0xC(r1)
	  stfs      f1, 0x20(r1)
	  stfs      f1, 0x1C(r1)
	  stfs      f1, 0x18(r1)
	  stw       r0, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  lwz       r3, 0x42C(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  stb       r31, 0x424(r30)
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
 * Address:	........
 * Size:	0000A0
 */
void Piki::updateFire()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C7F1C
 * Size:	000064
 */
void Piki::endFire()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x42C(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stb       r0, 0x424(r31)
	  li        r0, 0x2
	  addi      r5, r31, 0x464
	  sth       r0, 0x524(r31)
	  li        r4, 0x1D
	  li        r6, 0
	  lwz       r3, 0x3180(r13)
	  li        r7, 0
	  bl        0xD4BD0
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C7F80
 * Size:	00013C
 */
bool Piki::isTeki(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  bl        0x5B0
	  addi      r31, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x88
	  cmpwi     r31, 0x1D
	  beq-      .loc_0x88
	  cmpwi     r31, 0x16
	  beq-      .loc_0x88
	  lwz       r0, 0x184(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x88
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x88
	  li        r3, 0x1
	  b         .loc_0x120

	.loc_0x88:
	  mr        r3, r29
	  bl        0x548
	  addi      r31, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xF0
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF0
	  lwz       r0, 0x184(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0xF0
	  cmpwi     r31, 0x1D
	  beq-      .loc_0xF0
	  cmpwi     r31, 0x16
	  beq-      .loc_0xF0
	  li        r3, 0x1
	  b         .loc_0x120

	.loc_0xF0:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r0, 0x230(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x11C
	  lwz       r3, 0x504(r30)
	  lwz       r0, 0x504(r29)
	  sub       r3, r0, r3
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  b         .loc_0x120

	.loc_0x11C:
	  li        r3, 0

	.loc_0x120:
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
 * Address:	800C80BC
 * Size:	000404
 */
void Piki::actOnSituaton()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r4, 0x2F6C(r13)
	  lbz       r0, 0x1B5(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x3F0
	  lwz       r0, 0x52C(r31)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x4C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x68(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3F0

	.loc_0x4C:
	  li        r0, 0
	  stw       r0, 0x14(r1)
	  addi      r3, r31, 0
	  addi      r4, r1, 0x14
	  bl        0x460
	  cmplwi    r3, 0xE
	  bgt-      .loc_0x3E0
	  lis       r4, 0x802C
	  subi      r4, r4, 0x7BCC
	  rlwinm    r0,r3,2,0,29
	  lwzx      r0, r4, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x23D40
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x2E10
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x8
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0x40
	  bl        -0x4450
	  li        r0, 0x2
	  sth       r0, 0x4FC(r31)
	  b         .loc_0x3F0
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x23D88
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x2E58
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x1E
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xF0
	  bl        -0x4498
	  li        r0, 0x17
	  sth       r0, 0x4FC(r31)
	  b         .loc_0x3F0
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x23DD0
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x2EA0
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x15
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xA8
	  bl        -0x44E0
	  li        r0, 0x9
	  sth       r0, 0x4FC(r31)
	  b         .loc_0x3F0
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x23E18
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x2EE8
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x1A
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xD0
	  bl        -0x4528
	  li        r0, 0x13
	  sth       r0, 0x4FC(r31)
	  b         .loc_0x3F0
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x23E60
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x2F30
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x1B
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xD8
	  bl        -0x4570
	  li        r0, 0x14
	  sth       r0, 0x4FC(r31)
	  b         .loc_0x3F0
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x23EA8
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x2F78
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x1D
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xE8
	  bl        -0x45B8
	  li        r0, 0x16
	  sth       r0, 0x4FC(r31)
	  b         .loc_0x3F0
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x23EF0
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x2FC0
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x1C
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xE0
	  bl        -0x4600
	  li        r0, 0x15
	  sth       r0, 0x4FC(r31)
	  b         .loc_0x3F0
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x23F38
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x3008
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x14
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xA0
	  bl        -0x4648
	  li        r0, 0xE
	  sth       r0, 0x4FC(r31)
	  b         .loc_0x3F0
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x23F80
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x3050
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0xC
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0x60
	  bl        -0x4690
	  li        r0, 0x5
	  sth       r0, 0x4FC(r31)
	  b         .loc_0x3F0
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x23FC8
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x3098
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x17
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xB8
	  bl        -0x46D8
	  li        r0, 0x10
	  sth       r0, 0x4FC(r31)
	  b         .loc_0x3F0
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x24010
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x30E0
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x18
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xC0
	  bl        -0x4720
	  li        r0, 0x11
	  sth       r0, 0x4FC(r31)
	  b         .loc_0x3F0
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x24058
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x3128
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x13
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0x98
	  bl        -0x4768
	  li        r0, 0xD
	  sth       r0, 0x4FC(r31)
	  b         .loc_0x3F0

	.loc_0x3E0:
	  lwz       r5, 0x504(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x4D24

	.loc_0x3F0:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C84C0
 * Size:	000008
 */
bool PikiState::freeAI() { return false; }

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Piki::getNaviID()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C84C8
 * Size:	00004C
 */
bool Piki::doDoAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x80
	  cmplwi    r3, 0x15
	  bgt-      .loc_0x38
	  lis       r4, 0x802C
	  subi      r4, r4, 0x7B90
	  rlwinm    r0,r3,2,0,29
	  lwzx      r0, r4, r0
	  mtctr     r0
	  bctr
	  li        r3, 0x1
	  b         .loc_0x3C

	.loc_0x38:
	  li        r3, 0

	.loc_0x3C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C8514
 * Size:	000024
 */
bool Piki::isRopable()
{
	/*
	.loc_0x0:
	  lhz       r0, 0x4FC(r3)
	  cmplwi    r0, 0xB
	  beq-      .loc_0x1C
	  cmplwi    r0, 0xC
	  beq-      .loc_0x1C
	  li        r3, 0
	  blr

	.loc_0x1C:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C8538
 * Size:	00001C
 */
Vector3f Piki::getCatchPos(Creature*)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x458(r4)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x45C(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x460(r4)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C8554
 * Size:	00000C
 */
int Piki::getState()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x52C(r3)
	  lwz       r3, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void Piki::getLastState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C8560
 * Size:	000018
 */
bool Piki::isBuried()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x52C(r3)
	  lwz       r0, 0x4(r3)
	  subfic    r0, r0, 0x2
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C8578
 * Size:	001300
 */
void Piki::graspSituation(Creature**)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x208(r1)
	  stfd      f31, 0x200(r1)
	  stfd      f30, 0x1F8(r1)
	  stfd      f29, 0x1F0(r1)
	  stfd      f28, 0x1E8(r1)
	  stfd      f27, 0x1E0(r1)
	  stfd      f26, 0x1D8(r1)
	  stmw      r16, 0x198(r1)
	  addi      r31, r3, 0
	  addi      r29, r4, 0
	  lwz       r20, 0x3160(r13)
	  cmplwi    r20, 0
	  bne-      .loc_0x44
	  li        r3, 0
	  b         .loc_0x12D4

	.loc_0x44:
	  lwz       r0, 0x3168(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x58
	  li        r3, 0
	  b         .loc_0x12D4

	.loc_0x58:
	  lwz       r0, 0x2AC(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x6C
	  li        r3, 0
	  b         .loc_0x12D4

	.loc_0x6C:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B5(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  li        r3, 0
	  b         .loc_0x12D4

	.loc_0x84:
	  lwz       r4, 0x3068(r13)
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  li        r24, 0
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0xC(r12)
	  li        r21, 0
	  lfs       f31, -0x6A14(r2)
	  lfs       f26, 0x308(r4)
	  mtlr      r12
	  blrl
	  mr        r19, r3
	  b         .loc_0x1EC

	.loc_0xB8:
	  cmpwi     r19, -0x1
	  bne-      .loc_0xE0
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3
	  b         .loc_0xFC

	.loc_0xE0:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r19
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0xFC:
	  lwz       r12, 0x0(r18)
	  mr        r3, r18
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f26, f1
	  addi      r3, r18, 0
	  addi      r4, r31, 0
	  bl        -0x3AE04
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1D0
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D0
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D0
	  lwz       r0, 0xC8(r18)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x1D0
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D0
	  lwz       r0, 0x184(r18)
	  cmplwi    r0, 0
	  bne-      .loc_0x1D0
	  addi      r3, r31, 0
	  addi      r4, r18, 0
	  bl        -0x3B898
	  lwz       r12, 0x0(r18)
	  fmr       f27, f1
	  mr        r3, r18
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x1D0
	  fmr       f26, f27
	  mr        r21, r18

	.loc_0x1D0:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r19
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r19, r3

	.loc_0x1EC:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r19
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x214
	  li        r0, 0x1
	  b         .loc_0x240

	.loc_0x214:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r19
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x23C
	  li        r0, 0x1
	  b         .loc_0x240

	.loc_0x23C:
	  li        r0, 0

	.loc_0x240:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xB8
	  lwz       r19, 0x3168(r13)
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3
	  b         .loc_0x37C

	.loc_0x268:
	  cmpwi     r20, -0x1
	  bne-      .loc_0x290
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3
	  b         .loc_0x2AC

	.loc_0x290:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0x2AC:
	  fmr       f1, f26
	  addi      r3, r18, 0
	  addi      r4, r31, 0
	  bl        -0x3AFA0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x360
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x360
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x360
	  lwz       r0, 0xC8(r18)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x360
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x360
	  addi      r3, r31, 0
	  addi      r4, r18, 0
	  bl        -0x3BA28
	  lwz       r12, 0x0(r18)
	  fmr       f27, f1
	  mr        r3, r18
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x360
	  fmr       f26, f27
	  mr        r21, r18

	.loc_0x360:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3

	.loc_0x37C:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3A4
	  li        r0, 0x1
	  b         .loc_0x3D0

	.loc_0x3A4:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x3CC
	  li        r0, 0x1
	  b         .loc_0x3D0

	.loc_0x3CC:
	  li        r0, 0

	.loc_0x3D0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x268
	  cmplwi    r21, 0
	  beq-      .loc_0x3F8
	  lfs       f0, -0x6A14(r2)
	  fcmpo     cr0, f0, f26
	  ble-      .loc_0x3F8
	  fmr       f31, f26
	  stw       r21, 0x0(r29)
	  li        r24, 0x1

	.loc_0x3F8:
	  lwz       r0, 0x504(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x644
	  lwz       r19, 0x3068(r13)
	  li        r21, 0
	  lfs       f26, -0x6A10(r2)
	  li        r22, 0
	  addi      r3, r19, 0
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3
	  b         .loc_0x5AC

	.loc_0x430:
	  cmpwi     r20, -0x1
	  bne-      .loc_0x454
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x46C

	.loc_0x454:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x46C:
	  fmr       f1, f26
	  addi      r23, r3, 0
	  addi      r4, r31, 0
	  bl        -0x3B160
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x590
	  lhz       r0, 0x510(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x4E0
	  lwz       r3, 0x52C(r23)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x18
	  bne-      .loc_0x4E0
	  addi      r3, r31, 0
	  addi      r4, r23, 0
	  bl        -0x3BBA4
	  lwz       r12, 0x0(r23)
	  fmr       f27, f1
	  mr        r3, r23
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x4E0
	  fmr       f26, f27
	  mr        r22, r23
	  b         .loc_0x590

	.loc_0x4E0:
	  addi      r3, r23, 0
	  addi      r4, r31, 0
	  bl        -0xAE0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x590
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x590
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x590
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x590
	  lwz       r0, 0xC8(r23)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x590
	  addi      r3, r31, 0
	  addi      r4, r23, 0
	  bl        -0x3BC58
	  lwz       r12, 0x0(r23)
	  fmr       f27, f1
	  mr        r3, r23
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x590
	  fmr       f26, f27
	  mr        r21, r23

	.loc_0x590:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3

	.loc_0x5AC:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5D4
	  li        r0, 0x1
	  b         .loc_0x600

	.loc_0x5D4:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x5FC
	  li        r0, 0x1
	  b         .loc_0x600

	.loc_0x5FC:
	  li        r0, 0

	.loc_0x600:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x430
	  cmplwi    r22, 0
	  beq-      .loc_0x628
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0x644
	  fmr       f31, f26
	  stw       r22, 0x0(r29)
	  li        r24, 0xA
	  b         .loc_0x644

	.loc_0x628:
	  cmplwi    r21, 0
	  beq-      .loc_0x644
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0x644
	  fmr       f31, f26
	  stw       r21, 0x0(r29)
	  li        r24, 0x1

	.loc_0x644:
	  lwz       r3, 0x30AC(r13)
	  li        r23, 0
	  lwz       r4, 0x3068(r13)
	  li        r30, 0
	  lwz       r27, 0x68(r3)
	  lwz       r4, 0x68(r4)
	  li        r25, 0
	  addi      r3, r27, 0
	  lwz       r12, 0x0(r27)
	  li        r26, 0
	  lfs       f26, 0x318(r4)
	  li        r28, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r4, 0x802C
	  lfs       f28, -0x6A48(r2)
	  lfd       f29, -0x6A40(r2)
	  addi      r20, r3, 0
	  lfd       f30, -0x6A38(r2)
	  subi      r22, r4, 0x7B38
	  lis       r21, 0x666C
	  b         .loc_0xA74

	.loc_0x6A0:
	  cmpwi     r20, -0x1
	  bne-      .loc_0x6C8
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r19, r3
	  b         .loc_0x6E4

	.loc_0x6C8:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r19, r3

	.loc_0x6E4:
	  lwz       r5, 0x6C(r19)
	  li        r3, 0x1
	  addi      r4, r3, 0
	  cmpwi     r5, 0x16
	  addi      r0, r3, 0
	  beq-      .loc_0x708
	  cmpwi     r5, 0x17
	  beq-      .loc_0x708
	  li        r0, 0

	.loc_0x708:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x71C
	  cmpwi     r5, 0x18
	  beq-      .loc_0x71C
	  li        r4, 0

	.loc_0x71C:
	  rlwinm.   r0,r4,0,24,31
	  bne-      .loc_0x730
	  cmpwi     r5, 0x19
	  beq-      .loc_0x730
	  li        r3, 0

	.loc_0x730:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8A4
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8A4
	  lwz       r3, 0x220(r19)
	  addi      r4, r21, 0x6167
	  bl        -0x3F5C4
	  mr.       r17, r3
	  beq-      .loc_0xA58
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x0(r17)
	  addi      r3, r19, 0
	  addi      r4, r31, 0
	  fadds     f1, f0, f1
	  bl        -0x3B474
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xA58
	  lfs       f1, -0x6A0C(r2)
	  addi      r4, r22, 0
	  addi      r3, r1, 0x160
	  bl        0x4D6D0
	  li        r16, 0
	  b         .loc_0x890

	.loc_0x7B0:
	  addi      r3, r1, 0x160
	  bl        0x4D6CC
	  addi      r3, r17, 0
	  addi      r4, r16, 0
	  bl        -0x40F4C
	  lfs       f2, 0x98(r31)
	  mr        r18, r3
	  lfs       f3, 0x8(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x94(r31)
	  fsubs     f3, f3, f2
	  lfs       f2, 0xC(r3)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x9C(r31)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f27, f2, f0
	  fcmpo     cr0, f27, f28
	  ble-      .loc_0x858
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f27, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f27, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f27, f0
	  fsub      f0, f30, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0xB4(r1)
	  lfs       f27, 0xB4(r1)

	.loc_0x858:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x0(r18)
	  fsubs     f0, f27, f0
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f0, f26
	  cror      2, 0, 0x2
	  bne-      .loc_0x88C
	  fmr       f26, f0
	  mr        r23, r19

	.loc_0x88C:
	  addi      r16, r16, 0x1

	.loc_0x890:
	  mr        r3, r17
	  bl        -0x4107C
	  cmpw      r16, r3
	  blt+      .loc_0x7B0
	  b         .loc_0xA58

	.loc_0x8A4:
	  lwz       r0, 0x6C(r19)
	  cmpwi     r0, 0x22
	  bne-      .loc_0x91C
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x91C
	  addi      r3, r31, 0
	  addi      r4, r19, 0
	  bl        -0x3D41C
	  lwz       r12, 0x0(r19)
	  fmr       f27, f1
	  mr        r3, r19
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xA58
	  mr        r3, r19
	  bl        0x1B850
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA58
	  fmr       f26, f27
	  mr        r30, r19
	  b         .loc_0xA58

	.loc_0x91C:
	  lwz       r0, 0x6C(r19)
	  cmpwi     r0, 0x21
	  bne-      .loc_0x994
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x994
	  addi      r3, r31, 0
	  addi      r4, r19, 0
	  bl        -0x3D494
	  lwz       r12, 0x0(r19)
	  fmr       f27, f1
	  mr        r3, r19
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xA58
	  mr        r3, r19
	  bl        0x1B788
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA58
	  fmr       f26, f27
	  mr        r25, r19
	  b         .loc_0xA58

	.loc_0x994:
	  lwz       r0, 0x6C(r19)
	  cmpwi     r0, 0x23
	  bne-      .loc_0x9FC
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9FC
	  addi      r3, r31, 0
	  addi      r4, r19, 0
	  bl        -0x3D50C
	  lwz       r12, 0x0(r19)
	  fmr       f27, f1
	  mr        r3, r19
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xA58
	  fmr       f26, f27
	  mr        r26, r19
	  b         .loc_0xA58

	.loc_0x9FC:
	  lwz       r0, 0x6C(r19)
	  cmpwi     r0, 0x1D
	  bne-      .loc_0xA58
	  lfs       f1, 0x58(r19)
	  lfs       f0, 0x5C(r19)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xA58
	  addi      r3, r31, 0
	  addi      r4, r19, 0
	  bl        -0x3D56C
	  lwz       r12, 0x0(r19)
	  fmr       f27, f1
	  mr        r3, r19
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xA58
	  fmr       f26, f27
	  mr        r28, r19

	.loc_0xA58:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r20
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3

	.loc_0xA74:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r20
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA9C
	  li        r0, 0x1
	  b         .loc_0xAC8

	.loc_0xA9C:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xAC4
	  li        r0, 0x1
	  b         .loc_0xAC8

	.loc_0xAC4:
	  li        r0, 0

	.loc_0xAC8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x6A0
	  cmplwi    r23, 0
	  beq-      .loc_0xAEC
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0xAEC
	  fmr       f31, f26
	  stw       r23, 0x0(r29)
	  li        r24, 0x6

	.loc_0xAEC:
	  lwz       r19, 0x301C(r13)
	  li        r20, 0
	  lwz       r4, 0x3068(r13)
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0xC(r12)
	  lfs       f27, 0x318(r4)
	  mtlr      r12
	  blrl
	  mr        r21, r3
	  b         .loc_0xC58

	.loc_0xB1C:
	  cmpwi     r21, -0x1
	  bne-      .loc_0xB44
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3
	  b         .loc_0xB60

	.loc_0xB44:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r21
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0xB60:
	  addi      r17, r18, 0
	  addi      r3, r17, 0
	  lwz       r12, 0x0(r17)
	  mr        r16, r18
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC3C
	  mr        r3, r17
	  bl        -0x32DA0
	  cmpwi     r3, -0x1
	  beq-      .loc_0xC3C
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  fmr       f26, f1
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f27, f1
	  addi      r3, r16, 0
	  addi      r4, r31, 0
	  fadds     f1, f0, f26
	  bl        -0x3B8B8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xC3C
	  cmplwi    r18, 0
	  beq-      .loc_0xC3C
	  addi      r3, r31, 0
	  addi      r4, r16, 0
	  bl        -0x3D734
	  lwz       r12, 0x0(r31)
	  fmr       f28, f1
	  mr        r3, r31
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r16
	  fmr       f26, f1
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f27, f1
	  fadds     f0, f0, f26
	  fcmpo     cr0, f28, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xC3C
	  fmr       f27, f28
	  mr        r20, r18

	.loc_0xC3C:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r21
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r21, r3

	.loc_0xC58:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r21
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC80
	  li        r0, 0x1
	  b         .loc_0xCAC

	.loc_0xC80:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r21
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xCA8
	  li        r0, 0x1
	  b         .loc_0xCAC

	.loc_0xCA8:
	  li        r0, 0

	.loc_0xCAC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xB1C
	  cmplwi    r20, 0
	  beq-      .loc_0xCD0
	  fcmpo     cr0, f27, f31
	  bge-      .loc_0xCD0
	  fmr       f31, f27
	  stw       r20, 0x0(r29)
	  li        r24, 0x9

	.loc_0xCD0:
	  lwz       r19, 0x30AC(r13)
	  li        r27, 0
	  lwz       r4, 0x3068(r13)
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0xC(r12)
	  lfs       f26, 0x318(r4)
	  mtlr      r12
	  blrl
	  mr        r20, r3
	  b         .loc_0xE78

	.loc_0xD00:
	  cmpwi     r20, -0x1
	  bne-      .loc_0xD28
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3
	  b         .loc_0xD44

	.loc_0xD28:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0xD44:
	  fmr       f1, f26
	  addi      r16, r18, 0
	  addi      r3, r16, 0
	  addi      r4, r31, 0
	  bl        -0x3BA3C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xE5C
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE5C
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE5C
	  lwz       r0, 0x2A8(r18)
	  cmplwi    r0, 0
	  bne-      .loc_0xE5C
	  lwz       r0, 0x6C(r18)
	  cmpwi     r0, 0x22
	  bne-      .loc_0xDF0
	  addi      r3, r31, 0
	  addi      r4, r16, 0
	  bl        -0x3D900
	  lwz       r12, 0x0(r16)
	  fmr       f27, f1
	  mr        r3, r16
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xE5C
	  fmr       f26, f27
	  mr        r30, r18
	  b         .loc_0xE5C

	.loc_0xDF0:
	  cmpwi     r0, 0xE
	  bne-      .loc_0xE5C
	  lhz       r0, 0x510(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0xE5C
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE5C
	  addi      r3, r31, 0
	  addi      r4, r16, 0
	  bl        -0x3D970
	  lwz       r12, 0x0(r16)
	  fmr       f27, f1
	  mr        r3, r16
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f26, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xE5C
	  fmr       f26, f27
	  mr        r27, r18

	.loc_0xE5C:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r20, r3

	.loc_0xE78:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xEA0
	  li        r0, 0x1
	  b         .loc_0xECC

	.loc_0xEA0:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r20
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xEC8
	  li        r0, 0x1
	  b         .loc_0xECC

	.loc_0xEC8:
	  li        r0, 0

	.loc_0xECC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xD00
	  cmplwi    r27, 0
	  beq-      .loc_0xEF4
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0xF70
	  fmr       f31, f26
	  stw       r27, 0x0(r29)
	  li        r24, 0x3
	  b         .loc_0xF70

	.loc_0xEF4:
	  cmplwi    r30, 0
	  beq-      .loc_0xF14
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0xF70
	  fmr       f31, f26
	  stw       r30, 0x0(r29)
	  li        r24, 0xB
	  b         .loc_0xF70

	.loc_0xF14:
	  cmplwi    r25, 0
	  beq-      .loc_0xF34
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0xF70
	  fmr       f31, f26
	  stw       r25, 0x0(r29)
	  li        r24, 0xC
	  b         .loc_0xF70

	.loc_0xF34:
	  cmplwi    r26, 0
	  beq-      .loc_0xF54
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0xF70
	  fmr       f31, f26
	  stw       r26, 0x0(r29)
	  li        r24, 0xD
	  b         .loc_0xF70

	.loc_0xF54:
	  cmplwi    r28, 0
	  beq-      .loc_0xF70
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0xF70
	  fmr       f31, f26
	  stw       r28, 0x0(r29)
	  li        r24, 0xE

	.loc_0xF70:
	  lwz       r19, 0x3020(r13)
	  li        r20, 0
	  lwz       r4, 0x3068(r13)
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0xC(r12)
	  lfs       f27, 0x308(r4)
	  mtlr      r12
	  blrl
	  lfs       f26, -0x6A08(r2)
	  mr        r18, r3
	  b         .loc_0x1090

	.loc_0xFA4:
	  cmpwi     r18, -0x1
	  bne-      .loc_0xFC8
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xFE0

	.loc_0xFC8:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r18
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xFE0:
	  addi      r16, r3, 0
	  addi      r4, r31, 0
	  bl        -0x3DA40
	  lwz       r12, 0x0(r16)
	  fmr       f28, f1
	  mr        r3, r16
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r16
	  fmr       f29, f27
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1028
	  fmuls     f29, f26, f27

	.loc_0x1028:
	  fcmpo     cr0, f28, f29
	  bge-      .loc_0x1074
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1074
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  addi      r4, r31, 0x94
	  lwz       r12, 0x168(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1074
	  fmr       f27, f28
	  mr        r20, r16

	.loc_0x1074:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r18
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0x1090:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r18
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10B8
	  li        r0, 0x1
	  b         .loc_0x10E4

	.loc_0x10B8:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  mr        r4, r18
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x10E0
	  li        r0, 0x1
	  b         .loc_0x10E4

	.loc_0x10E0:
	  li        r0, 0

	.loc_0x10E4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xFA4
	  cmplwi    r20, 0
	  beq-      .loc_0x117C
	  addi      r16, r20, 0
	  addi      r3, r16, 0
	  lwz       r12, 0x0(r16)
	  addi      r4, r31, 0x94
	  lwz       r12, 0x168(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x117C
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x114C
	  fcmpo     cr0, f27, f31
	  bge-      .loc_0x117C
	  fmr       f31, f27
	  stw       r20, 0x0(r29)
	  li        r24, 0x7
	  b         .loc_0x117C

	.loc_0x114C:
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0x160(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x117C
	  fcmpo     cr0, f27, f31
	  bge-      .loc_0x117C
	  fmr       f31, f27
	  stw       r20, 0x0(r29)
	  li        r24, 0x8

	.loc_0x117C:
	  lhz       r0, 0x510(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x12D0
	  lwz       r20, 0x30AC(r13)
	  li        r19, 0
	  lwz       r4, 0x3068(r13)
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0xC(r12)
	  lfs       f26, 0x308(r4)
	  mtlr      r12
	  blrl
	  mr        r21, r3
	  b         .loc_0x1254

	.loc_0x11B8:
	  cmpwi     r21, -0x1
	  bne-      .loc_0x11E0
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3
	  b         .loc_0x11FC

	.loc_0x11E0:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r21
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0x11FC:
	  lwz       r0, 0x6C(r18)
	  addi      r16, r18, 0
	  cmpwi     r0, 0xD
	  bne-      .loc_0x1238
	  addi      r3, r16, 0
	  addi      r4, r31, 0
	  bl        -0x3DC6C
	  fcmpo     cr0, f1, f26
	  bge-      .loc_0x1238
	  fmr       f26, f1
	  mr        r3, r16
	  bl        0x2E284
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1238
	  mr        r19, r18

	.loc_0x1238:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r21
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r21, r3

	.loc_0x1254:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r21
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x127C
	  li        r0, 0x1
	  b         .loc_0x12A8

	.loc_0x127C:
	  mr        r3, r20
	  lwz       r12, 0x0(r20)
	  mr        r4, r21
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x12A4
	  li        r0, 0x1
	  b         .loc_0x12A8

	.loc_0x12A4:
	  li        r0, 0

	.loc_0x12A8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x11B8
	  cmplwi    r19, 0
	  beq-      .loc_0x12D0
	  cmplwi    r27, 0
	  bne-      .loc_0x12D0
	  fcmpo     cr0, f26, f31
	  bge-      .loc_0x12D0
	  stw       r19, 0x0(r29)
	  li        r24, 0x4

	.loc_0x12D0:
	  mr        r3, r24

	.loc_0x12D4:
	  lmw       r16, 0x198(r1)
	  lwz       r0, 0x20C(r1)
	  lfd       f31, 0x200(r1)
	  lfd       f30, 0x1F8(r1)
	  lfd       f29, 0x1F0(r1)
	  lfd       f28, 0x1E8(r1)
	  lfd       f27, 0x1E0(r1)
	  lfd       f26, 0x1D8(r1)
	  addi      r1, r1, 0x208
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C9878
 * Size:	0000D8
 */
void Piki::initColor(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x803A
	  sth       r4, 0x510(r31)
	  subi      r3, r3, 0x24E0
	  lwz       r0, 0x230(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x68
	  cmpwi     r4, 0x1
	  beq-      .loc_0x50
	  bge-      .loc_0x5C
	  cmpwi     r4, 0
	  bge-      .loc_0x44
	  b         .loc_0x5C

	.loc_0x44:
	  li        r0, 0
	  stw       r0, 0x43C(r31)
	  b         .loc_0x70

	.loc_0x50:
	  li        r0, 0x1
	  stw       r0, 0x43C(r31)
	  b         .loc_0x70

	.loc_0x5C:
	  li        r0, -0x1
	  stw       r0, 0x43C(r31)
	  b         .loc_0x70

	.loc_0x68:
	  li        r0, 0
	  stw       r0, 0x43C(r31)

	.loc_0x70:
	  lhz       r4, 0x510(r31)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1E18
	  rlwinm    r3,r4,2,0,29
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  mr        r3, r31
	  stw       r0, 0x508(r31)
	  lwz       r12, 0x0(r31)
	  lhz       r4, 0x510(r31)
	  lwz       r12, 0x12C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x508(r31)
	  stw       r0, 0x50C(r31)
	  lwz       r0, 0x508(r31)
	  stw       r0, 0x534(r31)
	  lwz       r0, 0x534(r31)
	  stw       r0, 0x530(r31)
	  lfs       f0, -0x6A20(r2)
	  stfs      f0, 0x538(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C9950
 * Size:	000030
 */
void Piki::startKinoko()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x12C(r12)
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
 * Address:	800C9980
 * Size:	000050
 */
void Piki::endKinoko()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x4A8(r3)
	  lwz       r12, 0x0(r31)
	  lhz       r4, 0x510(r31)
	  lwz       r12, 0x12C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lhz       r4, 0x510(r31)
	  bl        .loc_0x50
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x50:
	*/
}

/*
 * --INFO--
 * Address:	800C99D0
 * Size:	000098
 */
void Piki::setColor(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  sth       r4, 0x510(r3)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x50
	  lhz       r4, 0x510(r31)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1E30
	  rlwinm    r3,r4,2,0,29
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x50C(r31)
	  b         .loc_0x6C

	.loc_0x50:
	  lhz       r4, 0x510(r31)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1E18
	  rlwinm    r3,r4,2,0,29
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x50C(r31)

	.loc_0x6C:
	  lwz       r0, 0x508(r31)
	  stw       r0, 0x530(r31)
	  lwz       r0, 0x50C(r31)
	  stw       r0, 0x534(r31)
	  lfs       f0, -0x6A48(r2)
	  stfs      f0, 0x538(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C9A68
 * Size:	00009C
 */
void Piki::setPastel()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x10(r1)
	  lis       r4, 0x803D
	  addi      r0, r4, 0x1E18
	  lhz       r5, 0x510(r3)
	  rlwinm    r4,r5,2,0,29
	  add       r4, r0, r4
	  lwz       r0, 0x0(r4)
	  stw       r0, 0x50C(r3)
	  lbz       r4, 0x50C(r3)
	  stb       r4, 0xC(r1)
	  addi      r4, r4, 0xA0
	  cmpwi     r4, 0xFF
	  lbz       r5, 0x50D(r3)
	  stb       r5, 0xD(r1)
	  lbz       r6, 0x50E(r3)
	  stb       r6, 0xE(r1)
	  lbz       r0, 0x50F(r3)
	  stb       r0, 0xF(r1)
	  blt-      .loc_0x50
	  li        r4, 0xFF

	.loc_0x50:
	  addi      r0, r5, 0xA0
	  stb       r4, 0xC(r1)
	  cmpwi     r0, 0xFF
	  blt-      .loc_0x64
	  li        r0, 0xFF

	.loc_0x64:
	  addi      r4, r6, 0xA0
	  stb       r0, 0xD(r1)
	  cmpwi     r4, 0xFF
	  blt-      .loc_0x78
	  li        r4, 0xFF

	.loc_0x78:
	  stb       r4, 0xE(r1)
	  lwz       r0, 0xC(r1)
	  stw       r0, 0x534(r3)
	  lwz       r0, 0x508(r3)
	  stw       r0, 0x530(r3)
	  lfs       f0, -0x6A48(r2)
	  stfs      f0, 0x538(r3)
	  addi      r1, r1, 0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C9B04
 * Size:	000098
 */
void Piki::unsetPastel()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lhz       r0, 0x510(r3)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x50
	  lhz       r4, 0x510(r31)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1E30
	  rlwinm    r3,r4,2,0,29
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x50C(r31)
	  b         .loc_0x6C

	.loc_0x50:
	  lhz       r4, 0x510(r31)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1E18
	  rlwinm    r3,r4,2,0,29
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x50C(r31)

	.loc_0x6C:
	  lwz       r0, 0x508(r31)
	  stw       r0, 0x530(r31)
	  lwz       r0, 0x50C(r31)
	  stw       r0, 0x534(r31)
	  lfs       f0, -0x6A48(r2)
	  stfs      f0, 0x538(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C9B9C
 * Size:	0001A8
 */
void Piki::updateColor()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x98(r1)
	  lfs       f3, 0x538(r3)
	  lfs       f2, -0x6A20(r2)
	  fcmpo     cr0, f3, f2
	  cror      2, 0x1, 0x2
	  beq-      .loc_0x1A0
	  lwz       r4, 0x2DEC(r13)
	  lfs       f0, -0x6A04(r2)
	  lfs       f1, 0x28C(r4)
	  fdivs     f0, f1, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x538(r3)
	  lfs       f0, 0x538(r3)
	  fcmpo     cr0, f0, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x44
	  stfs      f2, 0x538(r3)

	.loc_0x44:
	  lbz       r5, 0x530(r3)
	  lis       r4, 0x4330
	  lbz       r0, 0x534(r3)
	  stw       r5, 0x84(r1)
	  lfd       f0, -0x6A00(r2)
	  stw       r0, 0x8C(r1)
	  lfs       f1, 0x538(r3)
	  stw       r4, 0x88(r1)
	  stw       r4, 0x80(r1)
	  lfd       f3, 0x88(r1)
	  lfd       f2, 0x80(r1)
	  stw       r5, 0x94(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r4, 0x90(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x90(r1)
	  fsubs     f3, f3, f0
	  fmuls     f2, f1, f2
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x78(r1)
	  lwz       r0, 0x7C(r1)
	  stb       r0, 0x508(r3)
	  lbz       r5, 0x531(r3)
	  lbz       r0, 0x535(r3)
	  stw       r5, 0x64(r1)
	  stw       r0, 0x6C(r1)
	  stw       r4, 0x68(r1)
	  stw       r4, 0x60(r1)
	  lfd       f3, 0x68(r1)
	  lfd       f2, 0x60(r1)
	  stw       r5, 0x74(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r4, 0x70(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x70(r1)
	  fsubs     f3, f3, f0
	  fmuls     f2, f1, f2
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stb       r0, 0x509(r3)
	  lbz       r5, 0x532(r3)
	  lbz       r0, 0x536(r3)
	  stw       r5, 0x44(r1)
	  stw       r0, 0x4C(r1)
	  stw       r4, 0x48(r1)
	  stw       r4, 0x40(r1)
	  lfd       f3, 0x48(r1)
	  lfd       f2, 0x40(r1)
	  stw       r5, 0x54(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r4, 0x50(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x50(r1)
	  fsubs     f3, f3, f0
	  fmuls     f2, f1, f2
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  stb       r0, 0x50A(r3)
	  lbz       r5, 0x533(r3)
	  lbz       r0, 0x537(r3)
	  stw       r5, 0x24(r1)
	  stw       r0, 0x2C(r1)
	  stw       r4, 0x28(r1)
	  stw       r4, 0x20(r1)
	  lfd       f3, 0x28(r1)
	  lfd       f2, 0x20(r1)
	  stw       r5, 0x34(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r4, 0x30(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x30(r1)
	  fsubs     f3, f3, f0
	  fmuls     f0, f1, f2
	  fadds     f0, f3, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stb       r0, 0x50B(r3)

	.loc_0x1A0:
	  addi      r1, r1, 0x98
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C9D44
 * Size:	000078
 */
bool Piki::needShadow()
{
	/*
	.loc_0x0:
	  lhz       r4, 0x510(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x28
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,28,28
	  beq-      .loc_0x28
	  li        r3, 0
	  blr

	.loc_0x28:
	  cmplwi    r4, 0x1
	  bne-      .loc_0x4C
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0x4C
	  li        r3, 0
	  blr

	.loc_0x4C:
	  cmplwi    r4, 0x2
	  bne-      .loc_0x70
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,26,26
	  beq-      .loc_0x70
	  li        r3, 0
	  blr

	.loc_0x70:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C9DBC
 * Size:	000028
 */
bool Piki::isFixed()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x52C(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x14
	  bne-      .loc_0x20
	  lbz       r0, 0x10(r3)
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr

	.loc_0x20:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C9DE4
 * Size:	000098
 */
void Piki::sendMsg(Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  mr        r5, r31
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  addi      r4, r30, 0
	  lwz       r3, 0x490(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0x8
	  bne-      .loc_0x68
	  lwz       r3, 0x52C(r30)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x16
	  bne-      .loc_0x68
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xD8(r12)
	  mtlr      r12
	  blrl

	.loc_0x68:
	  lwz       r3, 0x4F8(r30)
	  lbz       r0, 0x19(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x80
	  mr        r4, r31
	  bl        -0x637C

	.loc_0x80:
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
 * Address:	800C9E7C
 * Size:	00003C
 */
void StateMachine<Piki>::procMsg(Piki*, Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x52C(r4)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x2C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C9EB8
 * Size:	000074
 */
bool Piki::stimulate(Interaction&)
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
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x58
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5C

	.loc_0x58:
	  li        r3, 0

	.loc_0x5C:
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
 * Address:	800C9F2C
 * Size:	000074
 */
int Piki::getFormationPri()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x504(r3)
	  lwz       r0, 0x80C(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x34
	  bge-      .loc_0x20
	  cmpwi     r0, 0
	  bge-      .loc_0x2C
	  b         .loc_0x6C

	.loc_0x20:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x6C
	  b         .loc_0x60

	.loc_0x2C:
	  lwz       r3, 0x4B8(r3)
	  blr

	.loc_0x34:
	  lwz       r0, 0x4B8(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x48
	  li        r3, 0
	  blr

	.loc_0x48:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x58
	  li        r3, 0x1
	  blr

	.loc_0x58:
	  li        r3, 0x2
	  blr

	.loc_0x60:
	  lwz       r0, 0x4B8(r3)
	  neg       r3, r0
	  blr

	.loc_0x6C:
	  lwz       r3, 0x4B8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C9FA0
 * Size:	00008C
 */
void Piki::startDamage()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lwz       r3, 0x52C(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0xE
	  bne-      .loc_0x3C
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x3C

	.loc_0x38:
	  bdnz-     .loc_0x38

	.loc_0x3C:
	  lwz       r3, 0x4F8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x54(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x1
	  stb       r0, 0x2B4(r31)
	  lwz       r3, 0x52C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x78
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl

	.loc_0x78:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CA02C
 * Size:	000004
 */
void AState<Piki>::resume(Piki*) { }

/*
 * --INFO--
 * Address:	800CA030
 * Size:	0000DC
 */
void Piki::finishDamage()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  stb       r0, 0x2B4(r3)
	  lwz       r3, 0x52C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x3C
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x3C:
	  lbz       r0, 0x4A0(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x88
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x88
	  lwz       r5, 0x504(r31)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        0x312C
	  mr        r3, r31
	  bl        -0x39830
	  li        r0, 0
	  stb       r0, 0x4A0(r31)
	  b         .loc_0xC8

	.loc_0x88:
	  lwz       r3, 0x4F8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xBC
	  lwz       r3, 0x4F8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xC8

	.loc_0xBC:
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x4DB0

	.loc_0xC8:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CA10C
 * Size:	000004
 */
void AState<Piki>::restart(Piki*) { }

/*
 * --INFO--
 * Address:	800CA110
 * Size:	0000DC
 */
void Piki::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x58(r1)
	  mr        r30, r3
	  lwz       r0, 0x39C(r3)
	  cmpwi     r0, 0x38
	  bne-      .loc_0x7C
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0x8
	  bne-      .loc_0x7C
	  lfs       f1, -0x6A48(r2)
	  addi      r4, r1, 0x28
	  lfs       f0, -0x6A20(r2)
	  li        r3, 0x11
	  stfs      f1, 0x30(r1)
	  stfs      f1, 0x2C(r1)
	  stfs      f1, 0x28(r1)
	  stfs      f1, 0x3C(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f1, 0x34(r1)
	  lwz       r5, 0x94(r30)
	  lwz       r0, 0x98(r30)
	  stw       r5, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x30(r1)
	  stfs      f0, 0x4C(r1)
	  bl        0x4A158

	.loc_0x7C:
	  lbz       r0, 0x2B4(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xA0
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0xA0
	  mr        r3, r30
	  bl        -0x178
	  b         .loc_0xC4

	.loc_0xA0:
	  li        r0, 0x4
	  stw       r0, 0x20(r1)
	  addi      r3, r30, 0
	  addi      r4, r1, 0x20
	  stw       r31, 0x24(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl

	.loc_0xC4:
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
 * Address:	........
 * Size:	000038
 */
void Piki::birthBuried()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800CA1EC
 * Size:	000064
 */
bool Piki::isAtari()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x2A8(r3)
	  lwz       r3, 0x52C(r3)
	  cmplwi    r0, 0
	  lwz       r3, 0x4(r3)
	  bne-      .loc_0x54
	  cmpwi     r3, 0x1C
	  beq-      .loc_0x54
	  cmpwi     r3, 0x13
	  beq-      .loc_0x54
	  cmpwi     r3, 0x21
	  beq-      .loc_0x54
	  subi      r0, r3, 0xC
	  cmplwi    r0, 0x1
	  ble-      .loc_0x54
	  cmpwi     r3, 0x8
	  beq-      .loc_0x54
	  subi      r0, r3, 0x1
	  cmplwi    r0, 0x4
	  ble-      .loc_0x54
	  cmpwi     r3, 0x10
	  bne-      .loc_0x5C

	.loc_0x54:
	  li        r3, 0
	  blr

	.loc_0x5C:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CA250
 * Size:	0000B8
 */
bool Piki::ignoreAtari(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x6C(r4)
	  cmpwi     r5, 0x2C
	  bne-      .loc_0x20
	  lhz       r0, 0x510(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x20
	  li        r3, 0x1
	  blr

	.loc_0x20:
	  lwz       r0, 0x184(r3)
	  cmplw     r0, r4
	  bne-      .loc_0x34
	  li        r3, 0x1
	  blr

	.loc_0x34:
	  lhz       r0, 0x4FC(r3)
	  cmplwi    r0, 0xB
	  beq-      .loc_0x48
	  cmplwi    r0, 0xC
	  bne-      .loc_0x58

	.loc_0x48:
	  cmpwi     r5, 0x37
	  bne-      .loc_0x58
	  li        r3, 0x1
	  blr

	.loc_0x58:
	  lwz       r3, 0x52C(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0xE
	  beq-      .loc_0x70
	  cmpwi     r0, 0xC
	  bne-      .loc_0x88

	.loc_0x70:
	  cmpwi     r5, 0
	  beq-      .loc_0x80
	  cmpwi     r5, 0x36
	  bne-      .loc_0xB0

	.loc_0x80:
	  li        r3, 0x1
	  blr

	.loc_0x88:
	  cmpwi     r5, 0
	  bne-      .loc_0xB0
	  lwz       r3, 0x52C(r4)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0xE
	  beq-      .loc_0xA8
	  cmpwi     r0, 0xC
	  bne-      .loc_0xB0

	.loc_0xA8:
	  li        r3, 0x1
	  blr

	.loc_0xB0:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CA308
 * Size:	000008
 */
bool Piki::needFlick(Creature*) { return true; }

/*
 * --INFO--
 * Address:	800CA310
 * Size:	000110
 */
bool Piki::isVisible()
{
	/*
	.loc_0x0:
	  lwz       r0, 0xC8(r3)
	  lwz       r3, 0x52C(r3)
	  rlwinm.   r0,r0,0,20,20
	  lwz       r4, 0x4(r3)
	  beq-      .loc_0x1C
	  li        r3, 0
	  blr

	.loc_0x1C:
	  cmpwi     r4, 0x7
	  li        r3, 0
	  addi      r5, r3, 0
	  addi      r6, r3, 0
	  addi      r7, r3, 0
	  addi      r8, r3, 0
	  addi      r9, r3, 0
	  addi      r10, r3, 0
	  addi      r11, r3, 0
	  addi      r12, r3, 0
	  addi      r0, r3, 0
	  beq-      .loc_0x58
	  cmpwi     r4, 0x6
	  beq-      .loc_0x58
	  li        r0, 0x1

	.loc_0x58:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x6C
	  cmpwi     r4, 0x3
	  beq-      .loc_0x6C
	  li        r12, 0x1

	.loc_0x6C:
	  rlwinm.   r0,r12,0,24,31
	  beq-      .loc_0x80
	  cmpwi     r4, 0x1
	  beq-      .loc_0x80
	  li        r11, 0x1

	.loc_0x80:
	  rlwinm.   r0,r11,0,24,31
	  beq-      .loc_0x94
	  cmpwi     r4, 0x20
	  beq-      .loc_0x94
	  li        r10, 0x1

	.loc_0x94:
	  rlwinm.   r0,r10,0,24,31
	  beq-      .loc_0xA8
	  cmpwi     r4, 0x13
	  beq-      .loc_0xA8
	  li        r9, 0x1

	.loc_0xA8:
	  rlwinm.   r0,r9,0,24,31
	  beq-      .loc_0xBC
	  cmpwi     r4, 0x1C
	  beq-      .loc_0xBC
	  li        r8, 0x1

	.loc_0xBC:
	  rlwinm.   r0,r8,0,24,31
	  beq-      .loc_0xD0
	  cmpwi     r4, 0x21
	  beq-      .loc_0xD0
	  li        r7, 0x1

	.loc_0xD0:
	  rlwinm.   r0,r7,0,24,31
	  beq-      .loc_0xE4
	  cmpwi     r4, 0x5
	  beq-      .loc_0xE4
	  li        r6, 0x1

	.loc_0xE4:
	  rlwinm.   r0,r6,0,24,31
	  beq-      .loc_0xF8
	  cmpwi     r4, 0x4
	  beq-      .loc_0xF8
	  li        r5, 0x1

	.loc_0xF8:
	  rlwinm.   r0,r5,0,24,31
	  beqlr-
	  cmpwi     r4, 0x8
	  beqlr-
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void Piki::isGrowable()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Piki::isTamable()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800CA420
 * Size:	0000C4
 */
bool Piki::isThrowable()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x40
	  lwz       r0, 0x184(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x40
	  li        r3, 0
	  b         .loc_0xB0

	.loc_0x40:
	  lwz       r3, 0x52C(r31)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0xA
	  beq-      .loc_0x60
	  cmpwi     r0, 0x9
	  beq-      .loc_0x60
	  cmpwi     r0, 0x18
	  bne-      .loc_0x68

	.loc_0x60:
	  li        r3, 0
	  b         .loc_0xB0

	.loc_0x68:
	  cmpwi     r0, 0x21
	  bne-      .loc_0x78
	  li        r3, 0
	  b         .loc_0xB0

	.loc_0x78:
	  cmpwi     r0, 0x17
	  bne-      .loc_0x88
	  li        r3, 0
	  b         .loc_0xB0

	.loc_0x88:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xAC
	  li        r3, 0
	  b         .loc_0xB0

	.loc_0xAC:
	  li        r3, 0x1

	.loc_0xB0:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void Piki::growup()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800CA4E4
 * Size:	000044
 */
void Piki::offwallCallback(DynCollObject*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x7
	  stwu      r1, -0x18(r1)
	  lfs       f0, -0x6A48(r2)
	  stfs      f0, 0x4F0(r3)
	  stw       r0, 0x10(r1)
	  stw       r4, 0x14(r1)
	  addi      r4, r1, 0x10
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CA528
 * Size:	000058
 */
void Piki::wallCallback(Plane&, DynCollObject*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x20(r1)
	  stw       r0, 0x4E8(r3)
	  li        r0, 0x6
	  stw       r4, 0x4E0(r3)
	  stw       r5, 0x4E4(r3)
	  lfs       f0, -0x69F8(r2)
	  stfs      f0, 0x4EC(r3)
	  stw       r0, 0x14(r1)
	  stw       r4, 0x18(r1)
	  addi      r4, r1, 0x14
	  stw       r5, 0x1C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CA580
 * Size:	000004
 */
void Piki::jumpCallback() { }

/*
 * --INFO--
 * Address:	800CA584
 * Size:	000080
 */
bool Piki::platAttachable()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x470(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x70

	.loc_0x20:
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x70

	.loc_0x34:
	  lwz       r4, 0x52C(r3)
	  lwz       r0, 0x4(r4)
	  cmpwi     r0, 0x16
	  bne-      .loc_0x4C
	  li        r3, 0
	  b         .loc_0x70

	.loc_0x4C:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x6C
	  li        r3, 0
	  b         .loc_0x70

	.loc_0x6C:
	  li        r3, 0x1

	.loc_0x70:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CA604
 * Size:	0000E0
 */
bool Piki::mayIstick()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  mr        r29, r3
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  li        r3, 0
	  b         .loc_0xC4

	.loc_0x30:
	  lwz       r3, 0x52C(r29)
	  lwz       r4, 0x490(r29)
	  lwz       r30, 0x4(r3)
	  lwz       r31, 0x18(r4)
	  cmpwi     r30, 0x1A
	  bne-      .loc_0x50
	  li        r3, 0
	  b         .loc_0xC4

	.loc_0x50:
	  cmpwi     r30, 0x16
	  bne-      .loc_0x60
	  li        r3, 0
	  b         .loc_0xC4

	.loc_0x60:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x84
	  li        r3, 0
	  b         .loc_0xC4

	.loc_0x84:
	  cmpwi     r30, 0xE
	  beq-      .loc_0x94
	  cmpwi     r31, 0xE
	  bne-      .loc_0x9C

	.loc_0x94:
	  li        r3, 0x1
	  b         .loc_0xC4

	.loc_0x9C:
	  lhz       r0, 0x4FC(r29)
	  cmplwi    r0, 0x8
	  bne-      .loc_0xB0
	  li        r3, 0x1
	  b         .loc_0xC4

	.loc_0xB0:
	  cmplwi    r0, 0x2
	  bne-      .loc_0xC0
	  li        r3, 0x1
	  b         .loc_0xC4

	.loc_0xC0:
	  li        r3, 0

	.loc_0xC4:
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
 * Address:	800CA6E4
 * Size:	000038
 */
void Piki::stickToCallback(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x8
	  stwu      r1, -0x18(r1)
	  stw       r0, 0x10(r1)
	  addi      r4, r1, 0x10
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CA71C
 * Size:	0002BC
 */
void Piki::bounceCallback()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0xC8(r1)
	  stw       r31, 0xC4(r1)
	  mr        r31, r3
	  addi      r4, r1, 0xA4
	  stw       r30, 0xC0(r1)
	  stw       r29, 0xBC(r1)
	  stw       r28, 0xB8(r1)
	  lfs       f0, -0x429C(r13)
	  stw       r0, 0xA4(r1)
	  lfs       f1, -0x4298(r13)
	  stfs      f0, 0xA8(r1)
	  lfs       f0, -0x4294(r13)
	  stfs      f1, 0xAC(r1)
	  stfs      f0, 0xB0(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x28C(r31)
	  li        r0, -0x1
	  cmplwi    r3, 0
	  beq-      .loc_0x6C
	  bl        0x4B900
	  mr        r0, r3

	.loc_0x6C:
	  lwz       r3, 0x52C(r31)
	  lwz       r30, 0x4(r3)
	  cmpwi     r30, 0x6
	  beq-      .loc_0x29C
	  cmpwi     r30, 0x7
	  bne-      .loc_0x88
	  b         .loc_0x29C

	.loc_0x88:
	  cmpwi     r0, 0x5
	  li        r28, 0
	  bne-      .loc_0xB4
	  lhz       r0, 0x426(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xB4
	  lhz       r0, 0x510(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xB4
	  li        r28, 0x1
	  b         .loc_0x118

	.loc_0xB4:
	  lwz       r29, 0x184(r31)
	  cmplwi    r29, 0
	  beq-      .loc_0x118
	  lhz       r0, 0x426(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x118
	  lhz       r0, 0x510(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x118
	  cmplwi    r29, 0
	  beq-      .loc_0x118
	  lwz       r3, 0x28C(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x118
	  bl        0x4B878
	  cmpwi     r3, 0x5
	  bne-      .loc_0x118
	  lfs       f2, 0x98(r29)
	  lfs       f1, 0x98(r31)
	  lfs       f0, -0x69F4(r2)
	  fsubs     f1, f2, f1
	  fabs      f1, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x118
	  li        r28, 0x1

	.loc_0x118:
	  rlwinm.   r0,r28,0,24,31
	  beq-      .loc_0x264
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x264
	  cmpwi     r30, 0x7
	  beq-      .loc_0x264
	  cmpwi     r30, 0x6
	  beq-      .loc_0x264
	  cmpwi     r30, 0x21
	  beq-      .loc_0x264
	  cmpwi     r30, 0xD
	  beq-      .loc_0x264
	  lwz       r3, 0x3038(r13)
	  addi      r6, r31, 0x94
	  li        r4, 0x5
	  li        r5, 0xB4
	  bl        -0x26454
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x180
	  addi      r29, r29, 0x2B8

	.loc_0x180:
	  addi      r3, r1, 0x2C
	  li        r4, 0x38
	  bl        0x546B4
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x34
	  li        r4, 0x38
	  bl        0x546D4
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  bl        .loc_0x2BC
	  lwz       r3, 0x490(r31)
	  addi      r4, r31, 0
	  li        r5, 0x18
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, -0x6A48(r2)
	  addi      r0, r31, 0x94
	  lfs       f1, -0x6A20(r2)
	  addi      r4, r1, 0x74
	  stfs      f2, 0x7C(r1)
	  stfs      f2, 0x78(r1)
	  stfs      f2, 0x74(r1)
	  stfs      f2, 0x88(r1)
	  stfs      f2, 0x84(r1)
	  stfs      f2, 0x80(r1)
	  stw       r0, 0x94(r1)
	  stfs      f1, 0x98(r1)
	  stfs      f2, 0x50(r1)
	  lfs       f0, -0x69F0(r2)
	  stfs      f2, 0x4C(r1)
	  stfs      f2, 0x48(r1)
	  stfs      f2, 0x5C(r1)
	  stfs      f2, 0x58(r1)
	  stfs      f2, 0x54(r1)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x48(r1)
	  stw       r0, 0x4C(r1)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x50(r1)
	  stfs      f1, 0x6C(r1)
	  stfs      f0, 0x98(r1)
	  lwz       r3, 0x430(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x11
	  addi      r4, r1, 0x48
	  bl        0x49970
	  li        r0, 0x1
	  sth       r0, 0x426(r31)
	  b         .loc_0x29C

	.loc_0x264:
	  lhz       r0, 0x4FC(r31)
	  cmplwi    r0, 0x4
	  bne-      .loc_0x29C
	  lfs       f0, -0x6A48(r2)
	  stfs      f0, 0x98(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x4
	  stw       r0, 0xC8(r31)
	  lfs       f0, -0x4290(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x428C(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x4288(r13)
	  stfs      f0, 0x78(r31)

	.loc_0x29C:
	  lwz       r0, 0xCC(r1)
	  lwz       r31, 0xC4(r1)
	  lwz       r30, 0xC0(r1)
	  lwz       r29, 0xBC(r1)
	  lwz       r28, 0xB8(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr

	.loc_0x2BC:
	*/
}

/*
 * --INFO--
 * Address:	800CA9D8
 * Size:	000234
 */
void Piki::startMotion(PaniMotionInfo&, PaniMotionInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r3
	  stw       r30, 0x60(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x5C(r1)
	  addi      r29, r4, 0
	  lwz       r3, 0x52C(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x8
	  bne-      .loc_0x5C
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0x46
	  beq-      .loc_0x5C
	  cmpwi     r0, 0x1D
	  beq-      .loc_0x5C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl

	.loc_0x5C:
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  addi      r3, r31, 0x354
	  bl        0x55028
	  li        r0, -0x1
	  stw       r0, 0x350(r31)
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B5(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x218
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0x29
	  beq-      .loc_0xB4
	  bge-      .loc_0xA8
	  cmpwi     r0, 0x4
	  bge-      .loc_0x210
	  cmpwi     r0, 0
	  bge-      .loc_0xB4
	  b         .loc_0x210

	.loc_0xA8:
	  cmpwi     r0, 0x32
	  beq-      .loc_0xB4
	  b         .loc_0x210

	.loc_0xB4:
	  lwz       r30, 0x338(r31)
	  mr        r3, r31
	  bl        0xEC48
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x184
	  cmplwi    r30, 0
	  bne-      .loc_0x144
	  bl        0x14D5C8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6A28(r2)
	  stw       r0, 0x54(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x69EC(r2)
	  stw       r0, 0x50(r1)
	  lfs       f1, -0x6A20(r2)
	  lfd       f3, 0x50(r1)
	  lfs       f0, -0x69F0(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  cmpwi     r0, 0
	  bne-      .loc_0x130
	  lwz       r4, 0x504(r31)
	  addi      r3, r31, 0
	  addi      r4, r4, 0x6F0
	  bl        0xEB24
	  b         .loc_0x218

	.loc_0x130:
	  lwz       r4, 0x504(r31)
	  addi      r3, r31, 0
	  addi      r4, r4, 0x784
	  bl        0xEB10
	  b         .loc_0x218

	.loc_0x144:
	  addi      r3, r31, 0
	  addi      r4, r30, 0x94
	  bl        0xEB00
	  lwz       r3, 0x338(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x16C
	  beq-      .loc_0x16C
	  bl        0x19834
	  li        r0, 0
	  stw       r0, 0x338(r31)

	.loc_0x16C:
	  stw       r30, 0x338(r31)
	  lwz       r3, 0x338(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x218
	  bl        0x19808
	  b         .loc_0x218

	.loc_0x184:
	  lbz       r0, 0x330(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x218
	  cmplwi    r30, 0
	  beq-      .loc_0x218
	  lwz       r3, 0x220(r30)
	  li        r4, 0
	  cmplwi    r3, 0
	  beq-      .loc_0x1B8
	  lis       r4, 0x2A2A
	  addi      r4, r4, 0x2A2A
	  bl        -0x4129C
	  mr        r4, r3

	.loc_0x1B8:
	  cmplwi    r4, 0
	  beq-      .loc_0x1D0
	  addi      r3, r31, 0
	  addi      r4, r4, 0x4
	  bl        0xEA84
	  b         .loc_0x1DC

	.loc_0x1D0:
	  addi      r3, r31, 0
	  addi      r4, r30, 0x94
	  bl        0xEA74

	.loc_0x1DC:
	  lwz       r3, 0x338(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1F8
	  beq-      .loc_0x1F8
	  bl        0x197A8
	  li        r0, 0
	  stw       r0, 0x338(r31)

	.loc_0x1F8:
	  stw       r30, 0x338(r31)
	  lwz       r3, 0x338(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x218
	  bl        0x1977C
	  b         .loc_0x218

	.loc_0x210:
	  mr        r3, r31
	  bl        0xEAD8

	.loc_0x218:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CAC0C
 * Size:	000048
 */
void Piki::enableMotionBlend()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0xB
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0x3AC
	  lwz       r0, 0x3F0(r3)
	  stw       r0, 0x350(r3)
	  addi      r3, r1, 0x18
	  bl        0x54328
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  bl        0x54584
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void Piki::doMotionBlend()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void Piki::swapMotion(PaniMotionInfo&, PaniMotionInfo&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800CAC54
 * Size:	000190
 */
void Piki::checkBridgeWall(Creature*, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  addi      r29, r5, 0
	  lwz       r0, 0x2AC(r3)
	  lwz       r3, 0x52C(r3)
	  cmplwi    r0, 0
	  lwz       r3, 0x4(r3)
	  bne-      .loc_0x174
	  lhz       r0, 0x4FC(r31)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x174
	  cmpwi     r3, 0x21
	  beq-      .loc_0x174
	  cmpwi     r3, 0x7
	  beq-      .loc_0x174
	  cmpwi     r3, 0x6
	  beq-      .loc_0x174
	  cmplwi    r4, 0
	  beq-      .loc_0x174
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x26
	  bne-      .loc_0x174
	  lwz       r3, 0x4F8(r31)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x84
	  li        r3, 0
	  b         .loc_0x90

	.loc_0x84:
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0

	.loc_0x90:
	  cmplwi    r3, 0
	  beq-      .loc_0x174
	  lhz       r0, 0x2C(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x174
	  addi      r30, r4, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x174
	  addi      r4, r30, 0
	  addi      r3, r1, 0x30
	  bl        -0x2C1C4
	  lfs       f3, 0x0(r29)
	  lfs       f2, 0x30(r1)
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x34(r1)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x8(r29)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x38(r1)
	  lbz       r0, 0x3C8(r30)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  cmplwi    r0, 0
	  fadds     f1, f1, f0
	  beq-      .loc_0x174
	  lfs       f0, -0x69E8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x174
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x174
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x101
	  bl        -0x26988
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0x5A58
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x17
	  addi      r4, r30, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xB8
	  bl        -0x7098
	  li        r0, 0x10
	  sth       r0, 0x4FC(r31)

	.loc_0x174:
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
 * Address:	800CADE4
 * Size:	000B78
 */
void Piki::collisionCallback(CollEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x190(r1)
	  stfd      f31, 0x188(r1)
	  stfd      f30, 0x180(r1)
	  stfd      f29, 0x178(r1)
	  stmw      r25, 0x15C(r1)
	  mr        r27, r3
	  mr        r28, r4
	  lwz       r3, 0x52C(r3)
	  lwz       r31, 0x0(r4)
	  lwz       r0, 0x4(r3)
	  lwz       r30, 0x4(r4)
	  cmpwi     r0, 0x1F
	  beq-      .loc_0xB58
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xB58
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B5(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xB58
	  lwz       r3, 0x504(r27)
	  li        r29, 0x1
	  lbz       r0, 0x830(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xAC
	  lfsu      f1, 0x764(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r3)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xBD23C
	  lfs       f0, -0x69E4(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xAC
	  li        r29, 0

	.loc_0xAC:
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x240
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x1D
	  bne-      .loc_0x240
	  lwz       r0, 0x184(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x240
	  lwz       r3, 0x52C(r27)
	  lwz       r26, 0x4(r3)
	  cmpwi     r26, 0
	  beq-      .loc_0xE4
	  cmpwi     r26, 0xE
	  bne-      .loc_0x240

	.loc_0xE4:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x240
	  lhz       r0, 0x4FC(r27)
	  li        r25, 0
	  cmplwi    r0, 0x1
	  bne-      .loc_0x14C
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x128
	  li        r3, 0
	  b         .loc_0x134

	.loc_0x128:
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0

	.loc_0x134:
	  cmplwi    r3, 0
	  beq-      .loc_0x14C
	  lhz       r0, 0x2C(r3)
	  cmplwi    r0, 0x1
	  beq-      .loc_0x14C
	  li        r25, 0x1

	.loc_0x14C:
	  mr        r4, r27
	  lwz       r12, 0x0(r27)
	  addi      r3, r1, 0xE4
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lfs       f31, 0xE4(r1)
	  lwz       r12, 0x0(r27)
	  lfs       f30, 0xE8(r1)
	  lwz       r12, 0x5C(r12)
	  lfs       f29, 0xEC(r1)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x6A48(r2)
	  mr        r3, r30
	  stfs      f31, 0x138(r1)
	  addi      r4, r1, 0x118
	  stfs      f0, 0x120(r1)
	  stfs      f0, 0x11C(r1)
	  stfs      f0, 0x118(r1)
	  stfs      f30, 0x13C(r1)
	  stfs      f0, 0x12C(r1)
	  stfs      f29, 0x140(r1)
	  stfs      f0, 0x128(r1)
	  stfs      f1, 0x144(r1)
	  stfs      f0, 0x124(r1)
	  bl        -0x42410
	  lfs       f0, -0x6A48(r2)
	  rlwinm.   r0,r25,0,24,31
	  stfs      f0, 0x114(r1)
	  stfs      f0, 0x110(r1)
	  stfs      f0, 0x10C(r1)
	  bne-      .loc_0x240
	  addi      r3, r1, 0x118
	  addi      r4, r1, 0x138
	  addi      r5, r1, 0x10C
	  addi      r6, r1, 0x108
	  bl        -0x43C3C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x240
	  cmpwi     r26, 0xE
	  bne-      .loc_0x214
	  lwz       r3, 0x490(r27)
	  addi      r4, r27, 0
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x214:
	  lfs       f1, -0x6A48(r2)
	  addi      r3, r27, 0
	  addi      r4, r31, 0
	  addi      r5, r30, 0
	  li        r6, -0x1
	  bl        -0x3A954
	  addi      r3, r27, 0
	  li        r4, 0xA
	  li        r5, 0
	  bl        0x21B0
	  b         .loc_0xB58

	.loc_0x240:
	  li        r0, 0x3
	  stw       r0, 0xF8(r1)
	  addi      r3, r27, 0
	  addi      r4, r1, 0xF8
	  lwz       r0, 0x0(r28)
	  stw       r0, 0xFC(r1)
	  lwz       r0, 0x4(r28)
	  stw       r0, 0x100(r1)
	  lwz       r0, 0x8(r28)
	  stw       r0, 0x104(r1)
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x2B4(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0xB58
	  lwz       r3, 0x52C(r27)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x1A
	  beq-      .loc_0xB58
	  cmpwi     r0, 0x16
	  beq-      .loc_0xB58
	  cmpwi     r0, 0x8
	  bne-      .loc_0x2A8
	  b         .loc_0xB58

	.loc_0x2A8:
	  cmplwi    r3, 0
	  beq-      .loc_0x2C8
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB58

	.loc_0x2C8:
	  lwz       r0, 0x2AC(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0xB58
	  lwz       r3, 0x2F80(r13)
	  lwz       r0, 0x80(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x3AC
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x37
	  beq-      .loc_0x300
	  mr        r3, r31
	  bl        -0x40E30
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3AC

	.loc_0x300:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3AC
	  lhz       r0, 0x4FC(r27)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x3AC
	  lwz       r3, 0x52C(r27)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x21
	  beq-      .loc_0x3AC
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x350
	  li        r4, 0
	  b         .loc_0x35C

	.loc_0x350:
	  lwz       r4, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r4, r4, r0

	.loc_0x35C:
	  cmplwi    r4, 0
	  beq-      .loc_0x3AC
	  lhz       r0, 0x2C(r4)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x3AC
	  li        r4, 0
	  bl        -0x5E14
	  lwz       r3, 0x4F8(r27)
	  li        r0, 0x8
	  addi      r4, r31, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x745C
	  li        r0, 0x2
	  sth       r0, 0x4FC(r27)
	  b         .loc_0xB58

	.loc_0x3AC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x478
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x478
	  lhz       r0, 0x4FC(r27)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x478
	  lwz       r3, 0x52C(r27)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x21
	  beq-      .loc_0x478
	  addi      r3, r31, 0
	  addi      r4, r27, 0
	  bl        -0x325C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x478
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x41C
	  li        r4, 0
	  b         .loc_0x428

	.loc_0x41C:
	  lwz       r4, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r4, r4, r0

	.loc_0x428:
	  cmplwi    r4, 0
	  beq-      .loc_0x478
	  lhz       r0, 0x2C(r4)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x478
	  li        r4, 0
	  bl        -0x5EE0
	  lwz       r3, 0x4F8(r27)
	  li        r0, 0x8
	  addi      r4, r31, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x7528
	  li        r0, 0x2
	  sth       r0, 0x4FC(r27)
	  b         .loc_0xB58

	.loc_0x478:
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x59C
	  lwz       r5, 0x6C(r31)
	  li        r3, 0x1
	  addi      r4, r3, 0
	  cmpwi     r5, 0x16
	  addi      r0, r3, 0
	  beq-      .loc_0x4A4
	  cmpwi     r5, 0x17
	  beq-      .loc_0x4A4
	  li        r0, 0

	.loc_0x4A4:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x4B8
	  cmpwi     r5, 0x18
	  beq-      .loc_0x4B8
	  li        r4, 0

	.loc_0x4B8:
	  rlwinm.   r0,r4,0,24,31
	  bne-      .loc_0x4CC
	  cmpwi     r5, 0x19
	  beq-      .loc_0x4CC
	  li        r3, 0

	.loc_0x4CC:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x59C
	  lhz       r0, 0x4FC(r27)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x59C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x59C
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x514
	  li        r28, 0
	  b         .loc_0x520

	.loc_0x514:
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r28, r3, r0

	.loc_0x520:
	  addi      r3, r1, 0xD8
	  addi      r4, r30, 0
	  bl        -0x4346C
	  lis       r4, 0x6761
	  addi      r3, r1, 0xD8
	  addi      r4, r4, 0x7465
	  li        r5, 0x2A
	  bl        -0x87438
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x59C
	  cmplwi    r28, 0
	  beq-      .loc_0x59C
	  lhz       r0, 0x2C(r28)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x59C
	  lwz       r3, 0x4F8(r27)
	  li        r4, 0
	  bl        -0x6004
	  lwz       r3, 0x4F8(r27)
	  li        r0, 0x13
	  addi      r4, r31, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x764C
	  li        r0, 0xD
	  sth       r0, 0x4FC(r27)
	  b         .loc_0xB58

	.loc_0x59C:
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x66C
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x26
	  bne-      .loc_0x66C
	  lhz       r0, 0x4FC(r27)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x66C
	  addi      r25, r31, 0
	  addi      r3, r25, 0
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x160(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x66C
	  lwz       r12, 0x0(r25)
	  mr        r3, r25
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x66C
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x610
	  li        r4, 0
	  b         .loc_0x61C

	.loc_0x610:
	  lwz       r4, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r4, r4, r0

	.loc_0x61C:
	  cmplwi    r4, 0
	  beq-      .loc_0x66C
	  lhz       r0, 0x2C(r4)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x66C
	  li        r4, 0
	  bl        -0x60D4
	  lwz       r3, 0x4F8(r27)
	  li        r0, 0x18
	  addi      r4, r31, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x771C
	  li        r0, 0x11
	  sth       r0, 0x4FC(r27)
	  b         .loc_0xB58

	.loc_0x66C:
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x730
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x34
	  bne-      .loc_0x730
	  lhz       r0, 0x4FC(r27)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x730
	  addi      r25, r31, 0
	  addi      r3, r25, 0
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x730
	  mr        r3, r25
	  bl        -0x35134
	  cmpwi     r3, -0x1
	  beq-      .loc_0x730
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x6D4
	  li        r4, 0
	  b         .loc_0x6E0

	.loc_0x6D4:
	  lwz       r4, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r4, r4, r0

	.loc_0x6E0:
	  cmplwi    r4, 0
	  beq-      .loc_0x730
	  lhz       r0, 0x2C(r4)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x730
	  li        r4, 0
	  bl        -0x6198
	  lwz       r3, 0x4F8(r27)
	  li        r0, 0x15
	  addi      r4, r31, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x77E0
	  li        r0, 0x9
	  sth       r0, 0x4FC(r27)
	  b         .loc_0xB58

	.loc_0x730:
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x7C0
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0xE
	  bne-      .loc_0x7C0
	  lhz       r0, 0x510(r27)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x7C0
	  lwz       r0, 0x2A8(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x7C0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7C0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7C0
	  lhz       r0, 0x4FC(r27)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x7C0
	  lwz       r0, 0x2AC(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x7C0
	  addi      r3, r27, 0
	  li        r4, 0x5
	  li        r5, 0
	  bl        0x1C30
	  b         .loc_0xB58

	.loc_0x7C0:
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x874
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0xD
	  bne-      .loc_0x874
	  lhz       r0, 0x510(r27)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x874
	  lwz       r0, 0x2A8(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x874
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x874
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x874
	  lhz       r0, 0x4FC(r27)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x874
	  lwz       r0, 0x2AC(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x874
	  lwz       r3, 0x4F8(r27)
	  li        r4, 0
	  bl        -0x62E4
	  lwz       r3, 0x4F8(r27)
	  li        r0, 0x14
	  addi      r4, r31, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r27)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xA0
	  bl        -0x7924
	  li        r0, 0xE
	  sth       r0, 0x4FC(r27)
	  b         .loc_0xB58

	.loc_0x874:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x960
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x22
	  bne-      .loc_0x960
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x960
	  lhz       r0, 0x4FC(r27)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x960
	  lwz       r0, 0x2AC(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x960
	  mr        r3, r31
	  bl        0x19014
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x960
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x8F8
	  li        r3, 0
	  b         .loc_0x904

	.loc_0x8F8:
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0

	.loc_0x904:
	  cmplwi    r3, 0
	  beq-      .loc_0x960
	  lhz       r0, 0x2C(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x960
	  lwz       r3, 0x3038(r13)
	  addi      r5, r27, 0x94
	  li        r4, 0x101
	  bl        -0x27300
	  lwz       r3, 0x4F8(r27)
	  li        r4, 0
	  bl        -0x63D0
	  lwz       r3, 0x4F8(r27)
	  li        r0, 0x1B
	  addi      r4, r31, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r27)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xD8
	  bl        -0x7A10
	  li        r0, 0x14
	  sth       r0, 0x4FC(r27)
	  b         .loc_0xB58

	.loc_0x960:
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0xA28
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA28
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x23
	  bne-      .loc_0xA28
	  lhz       r0, 0x4FC(r27)
	  cmplwi    r0, 0x1
	  bne-      .loc_0xA28
	  lwz       r0, 0x2AC(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0xA28
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x9C0
	  li        r3, 0
	  b         .loc_0x9CC

	.loc_0x9C0:
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0

	.loc_0x9CC:
	  cmplwi    r3, 0
	  beq-      .loc_0xA28
	  lhz       r0, 0x2C(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0xA28
	  lwz       r3, 0x3038(r13)
	  addi      r5, r27, 0x94
	  li        r4, 0x101
	  bl        -0x273C8
	  lwz       r3, 0x4F8(r27)
	  li        r4, 0
	  bl        -0x6498
	  lwz       r3, 0x4F8(r27)
	  li        r0, 0x1D
	  addi      r4, r31, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r27)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xE8
	  bl        -0x7AD8
	  li        r0, 0x16
	  sth       r0, 0x4FC(r27)
	  b         .loc_0xB58

	.loc_0xA28:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB14
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x21
	  bne-      .loc_0xB14
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB14
	  lhz       r0, 0x4FC(r27)
	  cmplwi    r0, 0x1
	  bne-      .loc_0xB14
	  lwz       r0, 0x2AC(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0xB14
	  mr        r3, r31
	  bl        0x18E10
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB14
	  lwz       r3, 0x4F8(r27)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0xAAC
	  li        r3, 0
	  b         .loc_0xAB8

	.loc_0xAAC:
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0

	.loc_0xAB8:
	  cmplwi    r3, 0
	  beq-      .loc_0xB14
	  lhz       r0, 0x2C(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0xB14
	  lwz       r3, 0x3038(r13)
	  addi      r5, r27, 0x94
	  li        r4, 0x101
	  bl        -0x274B4
	  lwz       r3, 0x4F8(r27)
	  li        r4, 0
	  bl        -0x6584
	  lwz       r3, 0x4F8(r27)
	  li        r0, 0x1C
	  addi      r4, r31, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r27)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xE0
	  bl        -0x7BC4
	  li        r0, 0x15
	  sth       r0, 0x4FC(r27)
	  b         .loc_0xB58

	.loc_0xB14:
	  mr        r3, r27
	  lwz       r4, 0x52C(r27)
	  lwz       r12, 0x0(r27)
	  lwz       r28, 0x4(r4)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB58
	  subi      r0, r28, 0x1
	  cmplwi    r0, 0x1
	  ble-      .loc_0xB58
	  lbz       r0, 0x2B4(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0xB58
	  lhz       r0, 0x4FC(r27)
	  cmplwi    r0, 0x1

	.loc_0xB58:
	  lmw       r25, 0x15C(r1)
	  lwz       r0, 0x194(r1)
	  lfd       f31, 0x188(r1)
	  lfd       f30, 0x180(r1)
	  lfd       f29, 0x178(r1)
	  addi      r1, r1, 0x190
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CB95C
 * Size:	000008
 */
bool PikiState::collideAI() { return false; }

/*
 * --INFO--
 * Address:	800CB964
 * Size:	000400
 */
Piki::Piki(CreatureProp* prop)
    : Creature(prop)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  stw       r30, 0x18(r1)
	  bl        -0x40AA4
	  lis       r3, 0x802B
	  subi      r0, r3, 0x246C
	  lis       r3, 0x802C
	  stw       r0, 0x2B8(r31)
	  subi      r3, r3, 0x76E8
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x114
	  addi      r3, r31, 0x2BC
	  stw       r0, 0x2B8(r31)
	  bl        0x1E60
	  lfs       f0, -0x6A48(r2)
	  lis       r3, 0x8003
	  addi      r4, r3, 0x5B24
	  stfs      f0, 0x2E8(r31)
	  addi      r3, r31, 0x2F8
	  li        r5, 0
	  stfs      f0, 0x2E4(r31)
	  li        r6, 0xC
	  li        r7, 0x4
	  stfs      f0, 0x2E0(r31)
	  stfs      f0, 0x2F4(r31)
	  stfs      f0, 0x2F0(r31)
	  stfs      f0, 0x2EC(r31)
	  bl        0x149094
	  li        r30, 0
	  stw       r30, 0x338(r31)
	  addi      r3, r31, 0x354
	  bl        0x53EB4
	  addi      r3, r31, 0x40C
	  bl        -0x265B0
	  addi      r3, r31, 0x418
	  bl        -0x265B8
	  lfs       f5, -0x6A48(r2)
	  lis       r3, 0x8009
	  subi      r4, r3, 0x5808
	  stfs      f5, 0x448(r31)
	  fmr       f4, f5
	  fmr       f3, f5
	  addi      r3, r31, 0x53C
	  stfs      f5, 0x444(r31)
	  fmr       f2, f5
	  stfs      f5, 0x440(r31)
	  fmr       f1, f5
	  li        r5, 0
	  stfs      f5, 0x454(r31)
	  fmr       f0, f5
	  li        r6, 0xC
	  stfs      f5, 0x450(r31)
	  li        r7, 0x6
	  stfs      f5, 0x44C(r31)
	  stfs      f4, 0x460(r31)
	  stfs      f4, 0x45C(r31)
	  stfs      f4, 0x458(r31)
	  stfs      f3, 0x46C(r31)
	  stfs      f3, 0x468(r31)
	  stfs      f3, 0x464(r31)
	  stfs      f2, 0x4B4(r31)
	  stfs      f2, 0x4B0(r31)
	  stfs      f2, 0x4AC(r31)
	  stfs      f1, 0x4C4(r31)
	  stfs      f1, 0x4C0(r31)
	  stfs      f1, 0x4BC(r31)
	  stfs      f0, 0x4D0(r31)
	  stfs      f0, 0x4CC(r31)
	  stfs      f0, 0x4C8(r31)
	  stw       r30, 0x500(r31)
	  bl        0x148FE8
	  stw       r30, 0x33C(r31)
	  lwz       r3, 0x302C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x178
	  lis       r4, 0x7465
	  addi      r4, r4, 0x7374
	  bl        -0x2B99C
	  cmpwi     r3, 0
	  ble-      .loc_0x178
	  addi      r30, r3, 0
	  rlwinm    r3,r3,3,0,28
	  addi      r3, r3, 0x8
	  bl        -0x84AB8
	  lis       r4, 0x800A
	  subi      r4, r4, 0xA1C
	  addi      r7, r30, 0
	  li        r5, 0
	  li        r6, 0x8
	  bl        0x149154
	  stw       r3, 0x2CC(r31)

	.loc_0x178:
	  li        r3, 0x18
	  bl        -0x84ADC
	  cmplwi    r3, 0
	  beq-      .loc_0x1F8
	  lis       r4, 0x802B
	  addi      r0, r4, 0x600
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x5F4
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5E8
	  lis       r4, 0x802B
	  stw       r0, 0x8(r3)
	  addi      r5, r4, 0x5AC
	  stw       r5, 0x0(r3)
	  addi      r0, r5, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x25F0
	  addi      r0, r5, 0x18
	  stw       r0, 0x8(r3)
	  addi      r6, r4, 0xC
	  addi      r5, r4, 0x18
	  stw       r4, 0x0(r3)
	  addi      r4, r31, 0x70
	  li        r0, 0
	  stw       r6, 0x4(r3)
	  stw       r5, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)
	  stw       r0, 0x14(r3)

	.loc_0x1F8:
	  stw       r3, 0x42C(r31)
	  li        r3, 0x18
	  bl        -0x84B60
	  cmplwi    r3, 0
	  beq-      .loc_0x278
	  lis       r4, 0x802B
	  addi      r0, r4, 0x600
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x5F4
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5E8
	  lis       r4, 0x802B
	  stw       r0, 0x8(r3)
	  addi      r5, r4, 0x5AC
	  stw       r5, 0x0(r3)
	  addi      r0, r5, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r6, r4, 0x2660
	  addi      r0, r5, 0x18
	  stw       r0, 0x8(r3)
	  addi      r5, r6, 0xC
	  addi      r4, r6, 0x18
	  stw       r6, 0x0(r3)
	  li        r0, 0
	  stw       r5, 0x4(r3)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  stw       r0, 0x14(r3)
	  stw       r0, 0x10(r3)

	.loc_0x278:
	  stw       r3, 0x430(r31)
	  li        r3, 0x18
	  bl        -0x84BE0
	  cmplwi    r3, 0
	  beq-      .loc_0x2F0
	  lis       r4, 0x802B
	  addi      r0, r4, 0x600
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x5F4
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5E8
	  lis       r4, 0x802B
	  stw       r0, 0x8(r3)
	  addi      r5, r4, 0x5AC
	  stw       r5, 0x0(r3)
	  addi      r0, r5, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r6, r4, 0x26D0
	  addi      r0, r5, 0x18
	  stw       r0, 0x8(r3)
	  addi      r5, r6, 0xC
	  addi      r4, r6, 0x18
	  stw       r6, 0x0(r3)
	  li        r0, 0
	  stw       r5, 0x4(r3)
	  stw       r4, 0x8(r3)
	  stw       r0, 0x10(r3)

	.loc_0x2F0:
	  stw       r3, 0x434(r31)
	  li        r3, 0x14
	  bl        -0x84C58
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x30C
	  bl        0x474F8

	.loc_0x30C:
	  stw       r30, 0x438(r31)
	  addi      r3, r31, 0x1B8
	  addi      r4, r31, 0x53C
	  lfs       f0, -0x6A48(r2)
	  li        r5, 0x6
	  stfs      f0, 0x48C(r31)
	  bl        0x17FF8
	  li        r0, 0x1
	  stw       r0, 0x68(r31)
	  li        r3, 0x10
	  bl        -0x84C94
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x348
	  bl        0x486C0

	.loc_0x348:
	  stw       r30, 0x428(r31)
	  li        r0, 0
	  li        r3, 0x44
	  stb       r0, 0x424(r31)
	  stw       r0, 0x4DC(r31)
	  stw       r0, 0x52C(r31)
	  lfs       f0, -0x69E0(r2)
	  stfs      f0, 0x270(r31)
	  stw       r0, 0x504(r31)
	  bl        -0x84CCC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x384
	  mr        r4, r31
	  bl        -0x76F4

	.loc_0x384:
	  stw       r30, 0x4F8(r31)
	  li        r3, 0
	  li        r0, 0x1
	  stw       r3, 0x6C(r31)
	  li        r3, 0x1C
	  sth       r0, 0x4FC(r31)
	  bl        -0x84CFC
	  cmplwi    r3, 0
	  beq-      .loc_0x3C8
	  lis       r4, 0x802C
	  subi      r0, r4, 0x788C
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  lis       r4, 0x802C
	  stw       r0, 0x18(r3)
	  subi      r0, r4, 0x5D24
	  stw       r0, 0x0(r3)

	.loc_0x3C8:
	  stw       r3, 0x490(r31)
	  mr        r4, r31
	  lwz       r3, 0x490(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
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
 * Size:	000078
 */
void Piki::setSpeed(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800CBD64
 * Size:	000074
 */
void Piki::getSpeed(f32)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x3068(r13)
	  lwz       r4, 0x2F80(r13)
	  lwz       r5, 0x68(r5)
	  lwz       r0, 0x110(r4)
	  addi      r6, r4, 0x110
	  lfs       f2, -0x6A20(r2)
	  lfs       f0, 0x78(r5)
	  cmpwi     r0, 0
	  fmuls     f3, f2, f0
	  beq-      .loc_0x3C
	  lwz       r0, 0x520(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x3C
	  lfs       f3, 0x88(r5)
	  b         .loc_0x58

	.loc_0x3C:
	  lwz       r0, 0x0(r6)
	  cmpwi     r0, 0
	  beq-      .loc_0x58
	  lwz       r0, 0x520(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x58
	  lfs       f3, 0x98(r5)

	.loc_0x58:
	  lfs       f2, -0x6A20(r2)
	  lfs       f0, 0x68(r5)
	  fmuls     f2, f2, f0
	  fsubs     f0, f3, f2
	  fmuls     f0, f1, f0
	  fadds     f1, f2, f0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CBDD8
 * Size:	0000C4
 */
void Piki::setSpeed(f32, Vector3f&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x78(r1)
	  lwz       r6, 0x3068(r13)
	  lwz       r5, 0x2F80(r13)
	  lwz       r6, 0x68(r6)
	  addi      r7, r5, 0x110
	  lfs       f3, -0x6A20(r2)
	  lfs       f0, 0x68(r6)
	  lwz       r0, 0x0(r7)
	  lfs       f2, 0x78(r6)
	  fmuls     f4, f3, f0
	  cmpwi     r0, 0
	  fmuls     f0, f3, f2
	  beq-      .loc_0x48
	  lwz       r0, 0x520(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x48
	  lfs       f0, 0x88(r6)
	  b         .loc_0x64

	.loc_0x48:
	  lwz       r0, 0x0(r7)
	  cmpwi     r0, 0
	  beq-      .loc_0x64
	  lwz       r0, 0x520(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x64
	  lfs       f0, 0x98(r6)

	.loc_0x64:
	  fsubs     f0, f0, f4
	  fmuls     f0, f1, f0
	  fadds     f0, f4, f0
	  stfs      f0, 0x488(r3)
	  lfs       f2, 0x488(r3)
	  lfs       f0, 0x0(r4)
	  lfs       f1, 0x8(r4)
	  fmuls     f0, f0, f2
	  fmuls     f1, f1, f2
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x48(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x4(r4)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x6C(r1)
	  stfs      f1, 0x70(r1)
	  lwz       r4, 0x68(r1)
	  lwz       r0, 0x6C(r1)
	  stw       r4, 0xA4(r3)
	  stw       r0, 0xA8(r3)
	  lwz       r0, 0x70(r1)
	  stw       r0, 0xAC(r3)
	  addi      r1, r1, 0x78
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CBE9C
 * Size:	0000DC
 */
void Piki::setSpeed(f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  fmr       f30, f2
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  lwz       r5, 0x3068(r13)
	  lwz       r4, 0x2F80(r13)
	  lwz       r5, 0x68(r5)
	  lwzu      r0, 0x110(r4)
	  lfs       f2, -0x6A20(r2)
	  lfs       f0, 0x78(r5)
	  cmpwi     r0, 0
	  fmuls     f3, f2, f0
	  beq-      .loc_0x58
	  lwz       r0, 0x520(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x58
	  lfs       f3, 0x88(r5)
	  b         .loc_0x74

	.loc_0x58:
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x74
	  lwz       r0, 0x520(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x74
	  lfs       f3, 0x98(r5)

	.loc_0x74:
	  lfs       f2, -0x6A20(r2)
	  lfs       f0, 0x68(r5)
	  fmuls     f2, f2, f0
	  fsubs     f0, f3, f2
	  fmuls     f0, f1, f0
	  fmr       f1, f30
	  fadds     f0, f2, f0
	  stfs      f0, 0x488(r31)
	  bl        0x14FDB8
	  lfs       f0, 0x488(r31)
	  fmuls     f31, f0, f1
	  fmr       f1, f30
	  bl        0x14FC14
	  lfs       f0, 0x488(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x4284(r13)
	  stfs      f0, 0xA8(r31)
	  stfs      f31, 0xAC(r31)
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CBF78
 * Size:	000020
 */
f32 Piki::getSize()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x52C(r3)
	  lwz       r0, 0x4(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x18
	  lfs       f1, -0x69F0(r2)
	  blr

	.loc_0x18:
	  lfs       f1, 0x4F4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CBF98
 * Size:	000044
 */
f32 Piki::getiMass()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x52C(r3)
	  lwz       r3, 0x4(r3)
	  cmpwi     r3, 0x14
	  beq-      .loc_0x18
	  cmpwi     r3, 0x15
	  bne-      .loc_0x20

	.loc_0x18:
	  lfs       f1, -0x69F0(r2)
	  blr

	.loc_0x20:
	  subi      r0, r3, 0x1
	  cmplwi    r0, 0x1
	  bgt-      .loc_0x34
	  lfs       f1, -0x6A48(r2)
	  blr

	.loc_0x34:
	  lwz       r3, 0x3068(r13)
	  lwz       r3, 0x68(r3)
	  lfs       f1, 0x268(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CBFDC
 * Size:	000068
 */
void Piki::resetPosition(Vector3f&)
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
	  bl        -0x41390
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x4(r31)
	  stw       r3, 0x44C(r30)
	  stw       r0, 0x450(r30)
	  lwz       r0, 0x8(r31)
	  stw       r0, 0x454(r30)
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x4(r31)
	  stw       r3, 0x464(r30)
	  stw       r0, 0x468(r30)
	  lwz       r0, 0x8(r31)
	  stw       r0, 0x46C(r30)
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
 * Address:	800CC044
 * Size:	0002EC
 */
void Piki::init(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x68(r1)
	  li        r30, 0
	  stw       r29, 0x64(r1)
	  stw       r28, 0x60(r1)
	  mr        r28, r4
	  lfs       f1, -0x6A48(r2)
	  stfs      f1, 0x344(r3)
	  stfs      f1, 0x348(r3)
	  lfs       f0, -0x4280(r13)
	  stfs      f0, 0x7C(r3)
	  lfs       f0, -0x427C(r13)
	  stfs      f0, 0x80(r3)
	  lfs       f0, -0x4278(r13)
	  stfs      f0, 0x84(r3)
	  stw       r30, 0x2D0(r3)
	  stb       r30, 0x2D4(r3)
	  stfs      f1, 0x528(r3)
	  stw       r30, 0x338(r3)
	  stw       r30, 0x33C(r3)
	  stb       r30, 0x330(r3)
	  stw       r30, 0x33C(r3)
	  stfs      f1, 0x348(r3)
	  stfs      f1, 0x344(r3)
	  stb       r30, 0x340(r3)
	  stb       r30, 0x330(r3)
	  lwz       r3, 0x338(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  bl        0x182A4
	  stw       r30, 0x338(r31)

	.loc_0x8C:
	  li        r0, 0xA
	  stb       r0, 0x400(r31)
	  li        r4, 0
	  li        r3, 0x1
	  stw       r4, 0x404(r31)
	  li        r0, -0x1
	  stw       r4, 0x4A8(r31)
	  sth       r4, 0x426(r31)
	  sth       r4, 0x524(r31)
	  stb       r3, 0x409(r31)
	  lfs       f0, -0x4274(r13)
	  stfs      f0, 0x440(r31)
	  lfs       f0, -0x4270(r13)
	  stfs      f0, 0x444(r31)
	  lfs       f0, -0x426C(r13)
	  stfs      f0, 0x448(r31)
	  stb       r4, 0x584(r31)
	  stw       r0, 0x484(r31)
	  stw       r4, 0x480(r31)
	  lwz       r4, 0x3040(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0xEC
	  addi      r3, r31, 0x40C
	  bl        -0x26C88

	.loc_0xEC:
	  lwz       r4, 0x3048(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x100
	  addi      r3, r31, 0x418
	  bl        -0x26C9C

	.loc_0x100:
	  lwz       r4, 0x304C(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x114
	  addi      r3, r31, 0x174
	  bl        -0x26CB0

	.loc_0x114:
	  li        r0, 0
	  stw       r0, 0x4A4(r31)
	  mr        r3, r31
	  stb       r0, 0x470(r31)
	  stw       r0, 0x474(r31)
	  lfs       f0, -0x6A48(r2)
	  stfs      f0, 0x478(r31)
	  stw       r0, 0x4D8(r31)
	  stb       r0, 0x4A0(r31)
	  stw       r0, 0x4E8(r31)
	  stw       r0, 0x4E4(r31)
	  stfs      f0, 0x4EC(r31)
	  stfs      f0, 0x4F0(r31)
	  stb       r0, 0x519(r31)
	  stw       r0, 0x51C(r31)
	  lfs       f0, -0x6A20(r2)
	  stfs      f0, 0x47C(r31)
	  stw       r28, 0x504(r31)
	  bl        -0x4171C
	  bl        0x14BECC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6A28(r2)
	  stw       r0, 0x5C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x69EC(r2)
	  stw       r0, 0x58(r1)
	  lfs       f1, -0x6A20(r2)
	  lfd       f3, 0x58(r1)
	  lfs       f0, -0x69DC(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  stfd      f0, 0x50(r1)
	  cmpwi     r0, 0x3
	  lwz       r4, 0x54(r1)
	  blt-      .loc_0x1B8
	  li        r4, 0

	.loc_0x1B8:
	  mr        r3, r31
	  bl        -0x2988
	  li        r30, 0
	  stw       r30, 0x520(r31)
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,27,25
	  stw       r0, 0xC8(r31)
	  lwz       r3, 0x500(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1E8
	  bl        0x18148
	  stw       r30, 0x500(r31)

	.loc_0x1E8:
	  li        r0, 0x1
	  sth       r0, 0x4FC(r31)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r3, 0x3068(r13)
	  lwz       r3, 0x68(r3)
	  lfs       f0, 0xB8(r3)
	  stfs      f0, 0x58(r31)
	  lwz       r3, 0x490(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r30, 0
	  stw       r30, 0x514(r31)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r3, 0x490(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3068(r13)
	  lwz       r28, 0x68(r3)
	  addi      r29, r28, 0x248
	  bl        0x14BDE0
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x3068(r13)
	  stw       r0, 0x4C(r1)
	  lis       r0, 0x4330
	  lwz       r4, 0x68(r3)
	  mr        r3, r31
	  stw       r0, 0x48(r1)
	  lfd       f1, -0x6A28(r2)
	  lfd       f0, 0x48(r1)
	  lfs       f2, -0x69EC(r2)
	  fsubs     f4, f0, f1
	  lfs       f3, -0x6A20(r2)
	  lfs       f1, 0x258(r28)
	  lfs       f0, 0x0(r29)
	  fdivs     f4, f4, f2
	  lfs       f2, 0x248(r4)
	  fmuls     f3, f3, f4
	  fsubs     f0, f1, f0
	  fmuls     f0, f3, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x4F4(r31)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x34C(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x128(r12)
	  mtlr      r12
	  blrl
	  li        r0, -0x1
	  sth       r0, 0x2D8(r31)
	  sth       r0, 0x2D6(r31)
	  stw       r30, 0x32C(r31)
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  lwz       r28, 0x60(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CC330
 * Size:	000004
 */
void Piki::initBirth() { }

/*
 * --INFO--
 * Address:	800CC334
 * Size:	000038
 */
bool Piki::isAlive()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x52C(r3)
	  lwz       r0, 0x4(r4)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x18
	  cmpwi     r0, 0x7
	  bne-      .loc_0x20

	.loc_0x18:
	  li        r3, 0
	  blr

	.loc_0x20:
	  lfs       f1, 0x58(r3)
	  lfs       f0, -0x6A48(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm    r3,r0,2,31,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CC36C
 * Size:	000014
 */
bool Piki::isFruit()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x520(r3)
	  subfic    r0, r0, 0x2
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CC380
 * Size:	00034C
 */
void Piki::updateLookCreature()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stfd      f30, 0x50(r1)
	  stmw      r26, 0x38(r1)
	  addi      r29, r3, 0
	  addi      r3, r29, 0x418
	  bl        -0x26F48
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x330
	  lwz       r0, 0x3160(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x330
	  lwz       r3, 0x52C(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x330
	  lwz       r0, 0x338(r29)
	  cmplwi    r0, 0
	  mr        r31, r0
	  beq-      .loc_0xB8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xB8

	.loc_0x9C:
	  lwz       r3, 0x338(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0xB4
	  bl        0x17F44
	  li        r0, 0
	  stw       r0, 0x338(r29)

	.loc_0xB4:
	  li        r31, 0

	.loc_0xB8:
	  cmplwi    r31, 0
	  lfs       f30, -0x69D8(r2)
	  beq-      .loc_0x120
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  fmr       f31, f1
	  lfs       f1, 0x94(r29)
	  lfs       f2, 0x9C(r29)
	  lfs       f3, 0x94(r31)
	  lfs       f4, 0x9C(r31)
	  bl        -0x93E44
	  fsubs     f30, f1, f31
	  lfs       f0, -0x69D4(r2)
	  fcmpo     cr0, f30, f0
	  ble-      .loc_0x120
	  lwz       r3, 0x338(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x118
	  bl        0x17EE0
	  li        r0, 0
	  stw       r0, 0x338(r29)

	.loc_0x118:
	  li        r31, 0
	  lfs       f30, -0x69D8(r2)

	.loc_0x120:
	  lwz       r27, 0x3160(r13)
	  li        r30, 0
	  addi      r3, r27, 0
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3
	  b         .loc_0x200

	.loc_0x144:
	  cmpwi     r26, -0x1
	  bne-      .loc_0x16C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x188

	.loc_0x16C:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x188:
	  lwz       r12, 0x0(r28)
	  mr        r3, r28
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1E4
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  fmr       f31, f1
	  lfs       f1, 0x94(r29)
	  lfs       f2, 0x9C(r29)
	  lfs       f3, 0x94(r28)
	  lfs       f4, 0x9C(r28)
	  bl        -0x93F24
	  fsubs     f0, f1, f31
	  fcmpo     cr0, f0, f30
	  bge-      .loc_0x1E4
	  mr        r30, r28
	  fmr       f30, f0

	.loc_0x1E4:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x200:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x228
	  li        r0, 0x1
	  b         .loc_0x254

	.loc_0x228:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x250
	  li        r0, 0x1
	  b         .loc_0x254

	.loc_0x250:
	  li        r0, 0

	.loc_0x254:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x144
	  cmplw     r31, r30
	  beq-      .loc_0x330
	  bl        0x14BA8C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6A28(r2)
	  stw       r0, 0x34(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x69EC(r2)
	  stw       r0, 0x30(r1)
	  lfs       f1, -0x6A20(r2)
	  lfd       f3, 0x30(r1)
	  lfs       f0, -0x69D0(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x330
	  cmplwi    r31, 0
	  beq-      .loc_0x2C0
	  lwz       r3, 0x338(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C0
	  bl        0x17D38
	  li        r0, 0
	  stw       r0, 0x338(r29)

	.loc_0x2C0:
	  bl        0x14BA30
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6A28(r2)
	  stw       r0, 0x34(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x69EC(r2)
	  stw       r0, 0x30(r1)
	  lfs       f1, -0x6A20(r2)
	  lfd       f3, 0x30(r1)
	  lfs       f0, -0x69D0(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x300
	  lwz       r30, 0x504(r29)

	.loc_0x300:
	  lwz       r3, 0x338(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x31C
	  beq-      .loc_0x31C
	  bl        0x17CDC
	  li        r0, 0
	  stw       r0, 0x338(r29)

	.loc_0x31C:
	  stw       r30, 0x338(r29)
	  lwz       r3, 0x338(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x330
	  bl        0x17CB0

	.loc_0x330:
	  lmw       r26, 0x38(r1)
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lfd       f30, 0x50(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CC6CC
 * Size:	000008
 */
bool PikiState::useLookUpdate() { return true; }

/*
 * --INFO--
 * Address:	800CC6D4
 * Size:	000050
 */
void Piki::doAnimation()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        .loc_0x50
	  lwz       r4, 0x94(r31)
	  addi      r3, r31, 0x354
	  lwz       r0, 0x98(r31)
	  stw       r4, 0x440(r31)
	  stw       r0, 0x444(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x448(r31)
	  lfs       f1, 0x47C(r31)
	  bl        0x53438
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x50:
	*/
}

/*
 * --INFO--
 * Address:	800CC724
 * Size:	000448
 */
void Piki::updateWalkAnimation()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F8(r1)
	  stfd      f31, 0x1F0(r1)
	  stfd      f30, 0x1E8(r1)
	  stfd      f29, 0x1E0(r1)
	  stw       r31, 0x1DC(r1)
	  stw       r30, 0x1D8(r1)
	  stw       r29, 0x1D4(r1)
	  stw       r28, 0x1D0(r1)
	  mr        r28, r3
	  lwz       r3, 0x52C(r3)
	  lwz       r3, 0x4(r3)
	  cmpwi     r3, 0x16
	  beq-      .loc_0x41C
	  cmpwi     r3, 0x8
	  beq-      .loc_0x41C
	  cmpwi     r3, 0x1F
	  beq-      .loc_0x41C
	  cmpwi     r3, 0x1C
	  beq-      .loc_0x41C
	  cmpwi     r3, 0x13
	  beq-      .loc_0x41C
	  cmpwi     r3, 0x1D
	  beq-      .loc_0x41C
	  lwz       r0, 0x2AC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x104
	  cmpwi     r3, 0
	  bne-      .loc_0x104
	  lhz       r0, 0x4FC(r28)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x104
	  addi      r31, r28, 0x358
	  lwz       r0, 0x39C(r28)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x104
	  cmplwi    r28, 0
	  addi      r30, r28, 0
	  beq-      .loc_0xA4
	  addi      r30, r30, 0x2B8

	.loc_0xA4:
	  addi      r3, r1, 0x194
	  li        r4, 0x4
	  bl        0x52788
	  addi      r29, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x19C
	  li        r4, 0x4
	  bl        0x527A8
	  addi      r4, r3, 0
	  addi      r3, r28, 0
	  addi      r5, r29, 0
	  bl        -0x1E1C
	  lfs       f0, -0x69CC(r2)
	  addi      r29, r28, 0x3AC
	  addi      r3, r1, 0x14C
	  stfs      f0, 0x2C(r31)
	  li        r4, 0xB
	  stfs      f0, 0x3D8(r28)
	  lwz       r0, 0x3F0(r28)
	  stw       r0, 0x350(r28)
	  bl        0x52740
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  bl        0x5299C

	.loc_0x104:
	  lfs       f1, 0x94(r28)
	  lfs       f0, 0x440(r28)
	  lfs       f2, 0x9C(r28)
	  fsubs     f3, f1, f0
	  lfs       f0, 0x448(r28)
	  lfs       f1, -0x6A48(r2)
	  fsubs     f2, f2, f0
	  fmuls     f0, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f0, f0, f1
	  fadds     f4, f2, f0
	  fcmpo     cr0, f4, f1
	  ble-      .loc_0x190
	  fsqrte    f1, f4
	  lfd       f3, -0x6A40(r2)
	  lfd       f2, -0x6A38(r2)
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
	  stfs      f0, 0xEC(r1)
	  lfs       f4, 0xEC(r1)

	.loc_0x190:
	  lwz       r3, 0x2DEC(r13)
	  addi      r31, r28, 0x3AC
	  lwz       r6, 0x3F0(r28)
	  lfs       f0, 0x28C(r3)
	  cmpwi     r6, 0x3
	  fdivs     f3, f4, f0
	  beq-      .loc_0x1D8
	  cmpwi     r6, 0x2
	  beq-      .loc_0x1D8
	  cmpwi     r6, 0xB
	  beq-      .loc_0x1D8
	  cmpwi     r6, 0
	  beq-      .loc_0x1D8
	  cmpwi     r6, 0x1
	  beq-      .loc_0x1D8
	  lfs       f0, -0x69C8(r2)
	  stfs      f0, 0x47C(r28)
	  b         .loc_0x41C

	.loc_0x1D8:
	  lwz       r3, 0x3068(r13)
	  addi      r30, r28, 0x358
	  lfs       f2, 0xA0(r28)
	  lwz       r5, 0x68(r3)
	  lfs       f1, 0x34C(r28)
	  lfs       f0, 0x1A8(r5)
	  fsubs     f1, f2, f1
	  lwz       r4, 0x39C(r28)
	  fcmpo     cr0, f3, f0
	  fabs      f1, f1
	  bge-      .loc_0x220
	  lfs       f0, -0x69C4(r2)
	  li        r29, 0x3
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x218
	  li        r29, 0xB

	.loc_0x218:
	  lfs       f29, -0x69C8(r2)
	  b         .loc_0x2A8

	.loc_0x220:
	  lfs       f0, 0x1B8(r5)
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x238
	  lfs       f29, -0x69C8(r2)
	  li        r29, 0xB
	  b         .loc_0x2A8

	.loc_0x238:
	  lfs       f1, 0x1C8(r5)
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0x26C
	  fsubs     f2, f3, f0
	  lfs       f3, 0x1E8(r5)
	  fsubs     f1, f1, f0
	  lfs       f0, 0x1F8(r5)
	  li        r29, 0x2
	  fdivs     f1, f2, f1
	  fsubs     f0, f0, f3
	  fmuls     f0, f1, f0
	  fadds     f29, f3, f0
	  b         .loc_0x2A8

	.loc_0x26C:
	  lfs       f0, 0x1D8(r5)
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x2A0
	  fsubs     f2, f3, f1
	  lfs       f3, 0x208(r5)
	  fsubs     f1, f0, f1
	  lfs       f0, 0x218(r5)
	  li        r29, 0
	  fdivs     f1, f2, f1
	  fsubs     f0, f0, f3
	  fmuls     f0, f1, f0
	  fadds     f29, f3, f0
	  b         .loc_0x2A8

	.loc_0x2A0:
	  li        r29, 0x1
	  lfs       f29, 0x228(r5)

	.loc_0x2A8:
	  cmpw      r29, r6
	  beq-      .loc_0x314
	  cmpwi     r6, 0x3
	  bne-      .loc_0x2C8
	  cmpwi     r29, 0xB
	  beq-      .loc_0x2C8
	  li        r0, 0x4
	  stw       r0, 0x480(r28)

	.loc_0x2C8:
	  cmpwi     r6, 0xB
	  beq-      .loc_0x2E0
	  cmpwi     r29, 0x3
	  bne-      .loc_0x2E0
	  li        r0, 0x4
	  stw       r0, 0x480(r28)

	.loc_0x2E0:
	  lwz       r0, 0x484(r28)
	  cmpw      r29, r0
	  beq-      .loc_0x2FC
	  li        r0, 0
	  stw       r0, 0x480(r28)
	  stw       r29, 0x484(r28)
	  b         .loc_0x308

	.loc_0x2FC:
	  lwz       r3, 0x480(r28)
	  addi      r0, r3, 0x1
	  stw       r0, 0x480(r28)

	.loc_0x308:
	  lwz       r0, 0x480(r28)
	  cmpwi     r0, 0x4
	  blt-      .loc_0x41C

	.loc_0x314:
	  cmpw      r6, r29
	  beq-      .loc_0x418
	  cmpwi     r6, 0x3
	  beq-      .loc_0x33C
	  cmpwi     r6, 0xB
	  beq-      .loc_0x33C
	  cmpwi     r29, 0x3
	  beq-      .loc_0x33C
	  cmpwi     r29, 0xB
	  bne-      .loc_0x394

	.loc_0x33C:
	  lwz       r0, 0x350(r28)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x378
	  addi      r3, r1, 0x178
	  addi      r4, r29, 0
	  bl        0x524E4
	  addi      r30, r3, 0
	  addi      r4, r29, 0
	  addi      r3, r1, 0x180
	  bl        0x524D4
	  addi      r4, r3, 0
	  addi      r3, r28, 0
	  addi      r5, r30, 0
	  bl        -0x20BC
	  b         .loc_0x418

	.loc_0x378:
	  addi      r4, r29, 0
	  addi      r3, r1, 0x170
	  bl        0x524B4
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  bl        0x52710
	  b         .loc_0x418

	.loc_0x394:
	  lwz       r0, 0x350(r28)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x3F4
	  cmpwi     r4, 0x3
	  beq-      .loc_0x3F4
	  cmpwi     r4, 0xB
	  beq-      .loc_0x3F4
	  addi      r3, r1, 0x160
	  addi      r4, r29, 0
	  bl        0x5247C
	  addi      r3, r1, 0x168
	  addi      r4, r29, 0
	  bl        0x52470
	  addi      r29, r30, 0x2C
	  addi      r30, r31, 0x2C
	  lfs       f30, 0x0(r29)
	  lfs       f31, 0x2C(r31)
	  addi      r3, r28, 0x354
	  addi      r4, r1, 0x168
	  addi      r5, r1, 0x160
	  bl        0x52F60
	  stfs      f30, 0x0(r29)
	  stfs      f31, 0x0(r30)
	  b         .loc_0x418

	.loc_0x3F4:
	  lfs       f30, 0x2C(r31)
	  addi      r30, r31, 0x2C
	  addi      r4, r29, 0
	  addi      r3, r1, 0x158
	  bl        0x52430
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  bl        0x5268C
	  stfs      f30, 0x0(r30)

	.loc_0x418:
	  stfs      f29, 0x47C(r28)

	.loc_0x41C:
	  lwz       r0, 0x1FC(r1)
	  lfd       f31, 0x1F0(r1)
	  lfd       f30, 0x1E8(r1)
	  lfd       f29, 0x1E0(r1)
	  lwz       r31, 0x1DC(r1)
	  lwz       r30, 0x1D8(r1)
	  lwz       r29, 0x1D4(r1)
	  lwz       r28, 0x1D0(r1)
	  addi      r1, r1, 0x1F8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CCB6C
 * Size:	00053C
 */
void Piki::realAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x170(r1)
	  stw       r31, 0x16C(r1)
	  stw       r30, 0x168(r1)
	  mr        r30, r3
	  stw       r29, 0x164(r1)
	  stw       r28, 0x160(r1)
	  bl        -0x80C
	  mr        r3, r30
	  bl        0xCB48
	  mr        r3, r30
	  bl        -0x49CAC
	  mr        r3, r30
	  bl        -0x4295C
	  mr.       r29, r3
	  beq-      .loc_0x78
	  addi      r3, r1, 0xC0
	  addi      r4, r30, 0
	  bl        -0x42954
	  lfs       f0, 0xC0(r1)
	  mr        r3, r30
	  lfs       f1, 0xC4(r1)
	  mr        r4, r29
	  stfs      f0, 0x13C(r1)
	  lfs       f0, 0xC8(r1)
	  addi      r5, r1, 0x13C
	  stfs      f1, 0x140(r1)
	  stfs      f0, 0x144(r1)
	  bl        -0x1F8C

	.loc_0x78:
	  lwz       r3, 0x2AC(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x188
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0xE
	  beq-      .loc_0x188
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl
	  lwz       r29, 0x3068(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3
	  b         .loc_0x12C

	.loc_0xD4:
	  cmpwi     r31, -0x1
	  bne-      .loc_0xF8
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x110

	.loc_0xF8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x110:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x12C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x154
	  li        r0, 0x1
	  b         .loc_0x180

	.loc_0x154:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x17C
	  li        r0, 0x1
	  b         .loc_0x180

	.loc_0x17C:
	  li        r0, 0

	.loc_0x180:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xD4

	.loc_0x188:
	  lwz       r3, 0x3068(r13)
	  li        r0, -0x1
	  lwz       r3, 0x68(r3)
	  lfs       f0, 0x278(r3)
	  stfs      f0, 0x270(r30)
	  lwz       r3, 0x28C(r30)
	  lwz       r4, 0x52C(r30)
	  cmplwi    r3, 0
	  lwz       r31, 0x4(r4)
	  beq-      .loc_0x1B8
	  bl        0x49364
	  mr        r0, r3

	.loc_0x1B8:
	  cmpwi     r0, 0x5
	  li        r28, 0
	  bne-      .loc_0x1CC
	  li        r28, 0x1
	  b         .loc_0x214

	.loc_0x1CC:
	  lwz       r29, 0x184(r30)
	  cmplwi    r29, 0
	  beq-      .loc_0x214
	  beq-      .loc_0x214
	  lwz       r3, 0x28C(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x214
	  bl        0x4932C
	  cmpwi     r3, 0x5
	  bne-      .loc_0x214
	  lfs       f2, 0x98(r29)
	  lfs       f1, 0x98(r30)
	  lfs       f0, -0x69F4(r2)
	  fsubs     f1, f2, f1
	  fabs      f1, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x214
	  li        r28, 0x1

	.loc_0x214:
	  rlwinm.   r0,r28,0,24,31
	  beq-      .loc_0x44C
	  lwz       r3, 0x52C(r30)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0xD
	  beq-      .loc_0x44C
	  lhz       r0, 0x426(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x2D0
	  lfs       f1, -0x6A48(r2)
	  addi      r0, r30, 0x44C
	  lfs       f0, -0x6A20(r2)
	  addi      r4, r1, 0xF8
	  stfs      f1, 0x100(r1)
	  stfs      f1, 0xFC(r1)
	  stfs      f1, 0xF8(r1)
	  stfs      f1, 0xD4(r1)
	  stfs      f1, 0x10C(r1)
	  stfs      f1, 0xD0(r1)
	  stfs      f1, 0x108(r1)
	  stfs      f1, 0xCC(r1)
	  stfs      f1, 0x104(r1)
	  stfs      f1, 0xE0(r1)
	  stw       r0, 0x118(r1)
	  stfs      f1, 0xDC(r1)
	  stfs      f0, 0x11C(r1)
	  stfs      f1, 0xD8(r1)
	  lwz       r3, 0x44C(r30)
	  lwz       r0, 0x450(r30)
	  stw       r3, 0xCC(r1)
	  stw       r0, 0xD0(r1)
	  lwz       r0, 0x454(r30)
	  stw       r0, 0xD4(r1)
	  stfs      f0, 0xF0(r1)
	  lwz       r3, 0x430(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x11
	  addi      r4, r1, 0xCC
	  bl        0x474BC
	  lwz       r3, 0x3038(r13)
	  addi      r6, r30, 0x94
	  li        r4, 0x5
	  li        r5, 0xB4
	  bl        -0x28A04

	.loc_0x2D0:
	  li        r0, 0x1
	  stb       r0, 0x424(r30)
	  lhz       r3, 0x426(r30)
	  addi      r0, r3, 0x1
	  sth       r0, 0x426(r30)
	  lhz       r0, 0x426(r30)
	  cmplwi    r0, 0x3E8
	  ble-      .loc_0x2F8
	  li        r0, 0x3E8
	  sth       r0, 0x426(r30)

	.loc_0x2F8:
	  lhz       r0, 0x510(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x314
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x26
	  addi      r3, r3, 0x70
	  bl        -0x4947C

	.loc_0x314:
	  cmpwi     r31, 0x8
	  beq-      .loc_0x480
	  cmpwi     r31, 0x7
	  beq-      .loc_0x480
	  cmpwi     r31, 0x6
	  beq-      .loc_0x480
	  cmpwi     r31, 0x21
	  beq-      .loc_0x480
	  cmpwi     r31, 0x18
	  beq-      .loc_0x480
	  cmpwi     r31, 0xE
	  beq-      .loc_0x480
	  lhz       r0, 0x510(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x480
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x480
	  lwz       r3, 0x3068(r13)
	  lwz       r3, 0x68(r3)
	  addi      r31, r3, 0x498
	  bl        0x14B18C
	  xoris     r3, r3, 0x8000
	  lwz       r0, 0x0(r31)
	  stw       r3, 0x15C(r1)
	  lis       r4, 0x4330
	  xoris     r0, r0, 0x8000
	  lwz       r3, 0x3068(r13)
	  stw       r4, 0x158(r1)
	  lwz       r3, 0x68(r3)
	  lfd       f3, -0x6A28(r2)
	  lfd       f0, 0x158(r1)
	  stw       r0, 0x154(r1)
	  fsubs     f2, f0, f3
	  lfs       f0, -0x69EC(r2)
	  stw       r4, 0x150(r1)
	  lfs       f1, -0x6A20(r2)
	  fdivs     f2, f2, f0
	  lfd       f0, 0x150(r1)
	  lwz       r3, 0x488(r3)
	  lhz       r4, 0x426(r30)
	  fmuls     f1, f1, f2
	  fsubs     f0, f0, f3
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x148(r1)
	  lwz       r0, 0x14C(r1)
	  add       r0, r3, r0
	  cmpw      r4, r0
	  blt-      .loc_0x480
	  cmplwi    r30, 0
	  addi      r29, r30, 0
	  beq-      .loc_0x3FC
	  addi      r29, r29, 0x2B8

	.loc_0x3FC:
	  addi      r3, r1, 0xB0
	  li        r4, 0x38
	  bl        0x51FE8
	  addi      r31, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0xB8
	  li        r4, 0x38
	  bl        0x52008
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  bl        -0x25BC
	  lwz       r3, 0x490(r30)
	  addi      r4, r30, 0
	  li        r5, 0x18
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x480

	.loc_0x44C:
	  lhz       r0, 0x426(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x478
	  li        r31, 0
	  sth       r31, 0x426(r30)
	  lwz       r3, 0x430(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  stb       r31, 0x424(r30)

	.loc_0x478:
	  li        r0, 0
	  sth       r0, 0x426(r30)

	.loc_0x480:
	  lfs       f0, 0xA0(r30)
	  stfs      f0, 0x34C(r30)
	  lhz       r0, 0x524(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x4FC
	  lwz       r3, 0x52C(r30)
	  cmplwi    r0, 0x2
	  lwz       r0, 0x4(r3)
	  beq-      .loc_0x4FC
	  cmpwi     r0, 0x6
	  beq-      .loc_0x4FC
	  cmpwi     r0, 0x7
	  beq-      .loc_0x4FC
	  cmpwi     r0, 0x9
	  beq-      .loc_0x4FC
	  cmpwi     r0, 0x18
	  beq-      .loc_0x4FC
	  lhz       r0, 0x510(r30)
	  cmplwi    r0, 0x1
	  beq-      .loc_0x4FC
	  lwz       r5, 0x504(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x184
	  lwz       r3, 0x490(r30)
	  addi      r4, r30, 0
	  li        r5, 0x9
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x4FC:
	  lwz       r3, 0x490(r30)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stw       r0, 0x4E8(r30)
	  lwz       r0, 0x174(r1)
	  lwz       r31, 0x16C(r1)
	  lwz       r30, 0x168(r1)
	  lwz       r29, 0x164(r1)
	  lwz       r28, 0x160(r1)
	  addi      r1, r1, 0x170
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CD0A8
 * Size:	00003C
 */
void StateMachine<Piki>::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x52C(r4)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x2C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CD0E4
 * Size:	000004
 */
void AState<Piki>::exec(Piki*) { }

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Piki::getCurrentMotionName()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800CD0E8
 * Size:	0000E4
 */
void Piki::doAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r3, 0x52C(r3)
	  lwz       r3, 0x4(r3)
	  cmpwi     r3, 0x22
	  bne-      .loc_0x58
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x69C0(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, -0x6A04(r2)
	  fmuls     f0, f1, f0
	  lfs       f1, 0xA0(r31)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0xA0(r31)
	  lfs       f1, 0xA0(r31)
	  bl        -0x94BAC
	  stfs      f1, 0xA0(r31)
	  b         .loc_0xD0

	.loc_0x58:
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,26,26
	  bne-      .loc_0xB8
	  cmpwi     r3, 0x1C
	  beq-      .loc_0x74
	  cmpwi     r3, 0x13
	  bne-      .loc_0x88

	.loc_0x74:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl

	.loc_0x88:
	  lwz       r0, -0x5F04(r13)
	  cmpwi     r0, 0x2
	  ble-      .loc_0xA4
	  addi      r3, r31, 0x174
	  bl        -0x27D28
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB8

	.loc_0xA4:
	  lwz       r3, 0x4F8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xB8:
	  lwz       r3, 0x500(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xD0
	  bl        0x171C0
	  li        r0, 0
	  stw       r0, 0x500(r31)

	.loc_0xD0:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CD1CC
 * Size:	00024C
 */
void Piki::changeMode(int, Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r4, 0
	  li        r4, 0
	  stw       r30, 0x30(r1)
	  mr        r30, r3
	  lwz       r3, 0x4F8(r3)
	  bl        -0x7EAC
	  cmplwi    r31, 0x12
	  bgt-      .loc_0x230
	  lis       r3, 0x802C
	  subi      r3, r3, 0x7B00
	  rlwinm    r0,r31,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0x4F8(r30)
	  li        r0, 0xF
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r30)
	  lwz       r4, 0x504(r30)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x9514
	  b         .loc_0x230
	  lwz       r3, 0x4F8(r30)
	  li        r0, 0xD
	  li        r4, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r30)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x9540
	  b         .loc_0x230
	  lwz       r3, 0x4F8(r30)
	  li        r0, 0xE
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r30)
	  lwz       r4, 0x504(r30)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x956C
	  b         .loc_0x230
	  lwz       r3, 0x4F8(r30)
	  li        r0, 0x19
	  li        r4, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r30)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x9598
	  b         .loc_0x230
	  lwz       r3, 0x4F8(r30)
	  li        r0, 0xB
	  li        r4, 0
	  sth       r0, 0x8(r3)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x95C0
	  b         .loc_0x230
	  lwz       r3, 0x4F8(r30)
	  li        r0, 0xC
	  li        r4, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r30)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x95EC
	  b         .loc_0x230
	  lwz       r3, 0x4F8(r30)
	  li        r0, 0x9
	  sth       r0, 0x8(r3)
	  b         .loc_0x230
	  lwz       r3, 0x4F8(r30)
	  li        r0, 0x10
	  li        r4, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r30)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x9628
	  b         .loc_0x230
	  lwz       r3, 0x4F8(r30)
	  li        r0, 0x11
	  sth       r0, 0x8(r3)
	  lwz       r4, 0x4F8(r30)
	  lwz       r3, 0x504(r30)
	  lha       r0, 0x8(r4)
	  lwz       r5, 0x4(r4)
	  rlwinm    r0,r0,3,0,28
	  lwz       r4, 0x708(r3)
	  add       r3, r5, r0
	  bl        -0x9658
	  b         .loc_0x230
	  lwz       r3, 0x4F8(r30)
	  li        r0, 0x12
	  sth       r0, 0x8(r3)
	  lwz       r4, 0x4F8(r30)
	  lwz       r3, 0x504(r30)
	  lha       r0, 0x8(r4)
	  lwz       r5, 0x4(r4)
	  rlwinm    r0,r0,3,0,28
	  lwz       r4, 0x708(r3)
	  add       r3, r5, r0
	  bl        -0x9688
	  b         .loc_0x230
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B5(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x234
	  lwz       r3, 0x4F8(r30)
	  li        r0, 0x8
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r30)
	  lwz       r4, 0x504(r30)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x96C4
	  b         .loc_0x230
	  lwz       r3, 0x4F8(r30)
	  li        r0, 0xA
	  sth       r0, 0x8(r3)

	.loc_0x230:
	  sth       r31, 0x4FC(r30)

	.loc_0x234:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CD418
 * Size:	000250
 */
void Piki::dump()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x168(r1)
	  stw       r31, 0x164(r1)
	  mr        r31, r3
	  stw       r30, 0x160(r1)
	  subi      r30, r4, 0x7BD8
	  lwz       r3, 0x3178(r13)
	  bl        0xAFAB8
	  lbz       r0, 0x3060(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x160
	  lwz       r0, 0x52C(r31)
	  cmplwi    r0, 0
	  lwz       r0, 0x39C(r31)
	  cmpwi     r0, 0
	  lwz       r0, 0x3F0(r31)
	  cmpwi     r0, 0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r0, 0x230(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x78
	  lwz       r0, 0x504(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x78
	  lwz       r3, 0x3120(r13)
	  li        r4, 0
	  bl        0x49FAC

	.loc_0x78:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x84(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x52C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x4F8(r31)
	  lha       r5, 0x8(r4)
	  cmpwi     r5, -0x1
	  bne-      .loc_0xF4
	  li        r0, 0
	  b         .loc_0x100

	.loc_0xF4:
	  lwz       r3, 0x4(r4)
	  rlwinm    r0,r5,3,0,28
	  lwzx      r0, r3, r0

	.loc_0x100:
	  cmplwi    r0, 0
	  beq-      .loc_0x118
	  lhz       r0, 0x4FC(r31)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x118
	  cmpwi     r5, -0x1

	.loc_0x118:
	  lwz       r3, 0x188(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x128
	  bl        -0x456B8

	.loc_0x128:
	  mr        r3, r31
	  bl        -0x42DB8
	  lwz       r3, 0x4F8(r31)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x238
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x238

	.loc_0x160:
	  lwz       r0, 0x52C(r31)
	  cmplwi    r0, 0
	  lwz       r0, 0x39C(r31)
	  cmpwi     r0, 0
	  lwz       r0, 0x3F0(r31)
	  cmpwi     r0, 0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r0, 0x230(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1A4
	  lwz       r0, 0x504(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A4
	  lwz       r3, 0x3120(r13)
	  li        r4, 0
	  bl        0x49E80

	.loc_0x1A4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x84(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x52C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x188(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x204
	  bl        -0x45794

	.loc_0x204:
	  mr        r3, r31
	  bl        -0x42E94
	  lwz       r3, 0x4F8(r31)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x238
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl

	.loc_0x238:
	  lwz       r0, 0x16C(r1)
	  lwz       r31, 0x164(r1)
	  lwz       r30, 0x160(r1)
	  addi      r1, r1, 0x168
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CD668
 * Size:	00001C
 */
Vector3f Piki::getShadowPos()
{
	/*
	.loc_0x0:
	  lfs       f0, 0x44C(r4)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x450(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x454(r4)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CD684
 * Size:	000004
 */
void Piki::setLeaves(int) { }

/*
 * --INFO--
 * Address:	800CD688
 * Size:	000004
 */
void StateMachine<Piki>::init(Piki*) { }

/*
 * --INFO--
 * Address:	800CD68C
 * Size:	0000B0
 */
void StateMachine<Piki>::transit(Piki*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r5,2,0,29
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  mr        r29, r4
	  stw       r28, 0x18(r1)
	  mr        r28, r3
	  lwz       r31, 0x52C(r4)
	  lwz       r3, 0x14(r3)
	  cmplwi    r31, 0
	  lwzx      r30, r3, r0
	  mr        r3, r31
	  beq-      .loc_0x5C
	  lwz       r12, 0x0(r3)
	  mr        r4, r29
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r31)
	  stw       r0, 0x18(r28)

	.loc_0x5C:
	  lwz       r0, 0xC(r28)
	  cmpw      r30, r0
	  blt-      .loc_0x6C

	.loc_0x68:
	  b         .loc_0x68

	.loc_0x6C:
	  lwz       r3, 0x4(r28)
	  rlwinm    r0,r30,2,0,29
	  addi      r4, r29, 0
	  lwzx      r3, r3, r0
	  stw       r3, 0x52C(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
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
 * Address:	800CD73C
 * Size:	000004
 */
void AState<Piki>::init(Piki*) { }

/*
 * --INFO--
 * Address:	800CD740
 * Size:	000004
 */
void AState<Piki>::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800CD744
 * Size:	0000B8
 */
void __sinit_piki_cpp(void)
{
	/*
	.loc_0x0:
	  lis       r3, 0x803D
	  addi      r8, r3, 0x1E18
	  li        r7, 0
	  stb       r7, 0x0(r8)
	  li        r0, 0x32
	  li        r6, 0xFF
	  stb       r0, 0x1(r8)
	  li        r5, 0x1E
	  li        r4, 0xD2
	  stb       r6, 0x2(r8)
	  li        r3, 0x28
	  li        r0, 0x50
	  stb       r6, 0x3(r8)
	  stb       r6, 0x4(r8)
	  stb       r5, 0x5(r8)
	  stb       r7, 0x6(r8)
	  stb       r6, 0x7(r8)
	  stb       r6, 0x8(r8)
	  stb       r4, 0x9(r8)
	  stb       r7, 0xA(r8)
	  stb       r6, 0xB(r8)
	  stb       r6, 0xC(r8)
	  stb       r6, 0xD(r8)
	  stb       r6, 0xE(r8)
	  stb       r7, 0xF(r8)
	  stb       r3, 0x18(r8)
	  stb       r7, 0x19(r8)
	  stb       r0, 0x1A(r8)
	  stb       r6, 0x1B(r8)
	  stb       r3, 0x1C(r8)
	  stb       r7, 0x1D(r8)
	  stb       r0, 0x1E(r8)
	  stb       r6, 0x1F(r8)
	  stb       r3, 0x20(r8)
	  stb       r7, 0x21(r8)
	  stb       r0, 0x22(r8)
	  stb       r6, 0x23(r8)
	  stb       r3, 0x24(r8)
	  stb       r7, 0x25(r8)
	  stb       r0, 0x26(r8)
	  stb       r6, 0x27(r8)
	  stb       r6, 0x28(r8)
	  stb       r6, 0x29(r8)
	  stb       r6, 0x2A(r8)
	  stb       r7, 0x2B(r8)
	  blr
	*/
}
