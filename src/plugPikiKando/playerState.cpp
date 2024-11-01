#include "PlayerState.h"
#include "Generator.h"
#include "FlowController.h"
#include "gameflow.h"
#include "UtEffect.h"
#include "OnePlayerSection.h"
#include "Pellet.h"
#include "sysNew.h"
#include "Shape.h"
#include "Piki.h"

int PlayerState::totalUfoParts = 30;

bool preloadUFO = false;
PlayerState* playerState;

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
 * Address:	........
 * Size:	000014
 */
TimeGraph::TimeGraph()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void TimeGraph::create(u16, u16)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void TimeGraph::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void TimeGraph::set(u16, int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void TimeGraph::get(u16, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007F3B8
 * Size:	000058
 */

bool PlayerState::isEnding()
{
	if (getCurrDay() >= 29) {
		// we've hit our 30-day limit
		return true;

	} else if (getCurrParts() >= 30) {
		// we've collected every part
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8007F410
 * Size:	00019C
 */
bool PlayerState::existUfoParts(u32 p1)
{
	if (hasUfoParts(p1)) {
		return true;
	}

	if (generatorCache) {
		return true;
	}

	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r4
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  stw       r28, 0x28(r1)
	  bl        0x11D4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x34
	  li        r3, 0x1
	  b         .loc_0x17C

	.loc_0x34:
	  lwz       r3, 0x3098(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  lis       r4, 0x803A
	  subi      r4, r4, 0x24E0
	  lwz       r4, 0xA8(r4)
	  mr        r5, r31
	  lhz       r4, 0x26(r4)
	  bl        0x60308
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x68
	  li        r3, 0x1
	  b         .loc_0x17C

	.loc_0x68:
	  lwz       r29, 0x301C(r13)
	  cmplwi    r29, 0
	  beq-      .loc_0x178
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x11C

	.loc_0x90:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xB4
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xCC

	.loc_0xB4:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xCC:
	  mr        r28, r3
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x100
	  lwz       r3, 0x55C(r28)
	  lwz       r0, 0x2C(r3)
	  cmplw     r0, r31
	  bne-      .loc_0x100
	  li        r3, 0x1
	  b         .loc_0x17C

	.loc_0x100:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x11C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x144
	  li        r0, 0x1
	  b         .loc_0x170

	.loc_0x144:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x16C
	  li        r0, 0x1
	  b         .loc_0x170

	.loc_0x16C:
	  li        r0, 0

	.loc_0x170:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x90

	.loc_0x178:
	  li        r3, 0

	.loc_0x17C:
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
 * Address:	8007F5AC
 * Size:	0001CC
 */
void PlayerState::initGame()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x3
	  mtctr     r0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  li        r3, 0
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  stw       r28, 0x18(r1)

	.loc_0x30:
	  add       r4, r31, r6
	  stb       r3, 0x18(r4)
	  addi      r5, r4, 0x18
	  addi      r6, r6, 0x8
	  stbu      r3, 0x36(r4)
	  stb       r3, 0x1(r5)
	  stb       r3, 0x1(r4)
	  stb       r3, 0x2(r5)
	  stb       r3, 0x2(r4)
	  stb       r3, 0x3(r5)
	  stb       r3, 0x3(r4)
	  stb       r3, 0x4(r5)
	  stb       r3, 0x4(r4)
	  stb       r3, 0x5(r5)
	  stb       r3, 0x5(r4)
	  stb       r3, 0x6(r5)
	  stb       r3, 0x6(r4)
	  stb       r3, 0x7(r5)
	  stb       r3, 0x7(r4)
	  bdnz+     .loc_0x30
	  subfic    r0, r6, 0x1E
	  cmpwi     r6, 0x1E
	  mtctr     r0
	  bge-      .loc_0xA4

	.loc_0x90:
	  add       r4, r31, r6
	  stb       r3, 0x18(r4)
	  addi      r6, r6, 0x1
	  stb       r3, 0x36(r4)
	  bdnz+     .loc_0x90

	.loc_0xA4:
	  addi      r3, r31, 0x70
	  bl        0x40F4
	  addi      r3, r31, 0x54
	  bl        0x2BA8
	  li        r30, 0
	  stb       r30, 0x1B6(r31)
	  li        r0, 0x8
	  addi      r3, r31, 0
	  stw       r30, 0x8(r31)
	  li        r4, 0x1
	  stw       r30, 0x4(r31)
	  stw       r30, 0x0(r31)
	  stw       r30, 0xC(r31)
	  stw       r30, 0x1A0(r31)
	  stw       r30, 0x1A4(r31)
	  stb       r30, 0x1AC(r31)
	  stb       r0, 0x11(r31)
	  stw       r30, 0x170(r31)
	  lwz       r0, -0x6148(r13)
	  stw       r0, 0x174(r31)
	  stw       r30, 0x180(r31)
	  stw       r30, 0x17C(r31)
	  stw       r30, 0x14(r31)
	  stb       r30, 0x184(r31)
	  lbz       r0, 0x184(r31)
	  ori       r0, r0, 0x2
	  stb       r0, 0x184(r31)
	  bl        0xF30
	  stw       r30, 0x170(r31)
	  addi      r5, r30, 0
	  addi      r4, r30, 0
	  b         .loc_0x138

	.loc_0x124:
	  lwz       r3, 0x178(r31)
	  addi      r0, r4, 0xDC
	  addi      r5, r5, 0x1
	  stbx      r30, r3, r0
	  addi      r4, r4, 0xE0

	.loc_0x138:
	  lwz       r0, 0x174(r31)
	  cmpw      r5, r0
	  blt+      .loc_0x124
	  li        r0, 0x1
	  stb       r0, 0x185(r31)
	  li        r29, 0
	  lis       r3, 0x803A
	  stb       r29, 0x187(r31)
	  subi      r3, r3, 0x24E0
	  rlwinm    r30,r29,2,0,29
	  stb       r29, 0x188(r31)
	  stb       r29, 0x189(r31)
	  stb       r29, 0x18A(r31)
	  stb       r29, 0x18B(r31)
	  lwz       r28, 0x10(r3)

	.loc_0x174:
	  addi      r3, r28, 0x90
	  bl        -0x3F0A4
	  cmpwi     r3, 0
	  ble-      .loc_0x190
	  lwz       r3, 0x1B0(r31)
	  lwzx      r3, r3, r30
	  bl        0x96C24

	.loc_0x190:
	  addi      r29, r29, 0x1
	  lwz       r28, 0xC(r28)
	  cmpwi     r29, 0x5
	  addi      r30, r30, 0x4
	  blt+      .loc_0x174
	  li        r0, 0
	  stb       r0, 0x10(r31)
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
 * Address:	8007F778
 * Size:	000330
 */
PlayerState::PlayerState()
{
	mTotalParts = totalUfoParts;
	mUfoParts   = new UfoParts[mTotalParts];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r26, 0x30(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x54
	  bl        0x2480
	  addi      r3, r31, 0x70
	  bl        0x3DF4
	  addi      r3, r31, 0xC4
	  bl        0xA0100
	  li        r3, 0
	  stw       r3, 0x190(r31)
	  li        r0, 0x3
	  mtctr     r0
	  li        r6, 0
	  sth       r3, 0x18E(r31)
	  sth       r3, 0x18C(r31)
	  stw       r3, 0x19C(r31)
	  sth       r3, 0x19A(r31)
	  sth       r3, 0x198(r31)
	  lfs       f0, -0x7620(r2)
	  stfs      f0, 0x1C8(r31)
	  stfs      f0, 0x1C4(r31)
	  stfs      f0, 0x1C0(r31)

	.loc_0x64:
	  add       r4, r31, r6
	  stb       r3, 0x18(r4)
	  addi      r5, r4, 0x18
	  addi      r6, r6, 0x8
	  stbu      r3, 0x36(r4)
	  stb       r3, 0x1(r5)
	  stb       r3, 0x1(r4)
	  stb       r3, 0x2(r5)
	  stb       r3, 0x2(r4)
	  stb       r3, 0x3(r5)
	  stb       r3, 0x3(r4)
	  stb       r3, 0x4(r5)
	  stb       r3, 0x4(r4)
	  stb       r3, 0x5(r5)
	  stb       r3, 0x5(r4)
	  stb       r3, 0x6(r5)
	  stb       r3, 0x6(r4)
	  stb       r3, 0x7(r5)
	  stb       r3, 0x7(r4)
	  bdnz+     .loc_0x64
	  subfic    r0, r6, 0x1E
	  cmpwi     r6, 0x1E
	  mtctr     r0
	  bge-      .loc_0xD8

	.loc_0xC4:
	  add       r4, r31, r6
	  stb       r3, 0x18(r4)
	  addi      r6, r6, 0x1
	  stb       r3, 0x36(r4)
	  bdnz+     .loc_0xC4

	.loc_0xD8:
	  li        r30, 0
	  stb       r30, 0x1B6(r31)
	  li        r0, 0x8
	  stw       r30, 0x8(r31)
	  stw       r30, 0x4(r31)
	  stw       r30, 0x0(r31)
	  stw       r30, 0xC(r31)
	  stw       r30, 0x1A0(r31)
	  stw       r30, 0x1A4(r31)
	  stb       r30, 0x1AC(r31)
	  stb       r0, 0x11(r31)
	  stw       r30, 0x170(r31)
	  lwz       r0, -0x6148(r13)
	  stw       r0, 0x174(r31)
	  lwz       r29, 0x174(r31)
	  mulli     r3, r29, 0xE0
	  addi      r3, r3, 0x8
	  bl        -0x38890
	  lis       r4, 0x8008
	  subi      r4, r4, 0x52C
	  addi      r7, r29, 0
	  li        r5, 0
	  li        r6, 0xE0
	  bl        0x19537C
	  stw       r3, 0x178(r31)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  stw       r30, 0x180(r31)
	  stw       r30, 0x17C(r31)
	  stw       r30, 0x14(r31)
	  stb       r30, 0x184(r31)
	  lbz       r0, 0x184(r31)
	  ori       r0, r0, 0x2
	  stb       r0, 0x184(r31)
	  bl        0xD14
	  stw       r30, 0x170(r31)
	  addi      r5, r30, 0
	  addi      r4, r30, 0
	  b         .loc_0x188

	.loc_0x174:
	  lwz       r3, 0x178(r31)
	  addi      r0, r4, 0xDC
	  addi      r5, r5, 0x1
	  stbx      r30, r3, r0
	  addi      r4, r4, 0xE0

	.loc_0x188:
	  lwz       r0, 0x174(r31)
	  cmpw      r5, r0
	  blt+      .loc_0x174
	  mr        r3, r31
	  bl        0x12E4
	  rlwinm    r29,r3,0,16,31
	  addi      r3, r31, 0
	  bl        0x12B0
	  rlwinm    r0,r3,0,16,31
	  sth       r3, 0x18C(r31)
	  sub       r4, r29, r0
	  addi      r0, r4, 0x1
	  sth       r29, 0x18E(r31)
	  mulli     r3, r0, 0xC
	  bl        -0x38934
	  li        r29, 0
	  stw       r3, 0x190(r31)
	  mulli     r30, r29, 0xC
	  b         .loc_0x1F0

	.loc_0x1D4:
	  lwz       r0, 0x190(r31)
	  li        r4, -0x1
	  li        r5, -0x1
	  add       r3, r0, r30
	  bl        .loc_0x330
	  addi      r30, r30, 0xC
	  addi      r29, r29, 0x1

	.loc_0x1F0:
	  lhz       r3, 0x18C(r31)
	  lhz       r0, 0x18E(r31)
	  sub       r3, r0, r3
	  addi      r0, r3, 0x1
	  cmpw      r29, r0
	  blt+      .loc_0x1D4
	  mr        r3, r31
	  bl        0x1240
	  rlwinm    r4,r3,0,16,31
	  addi      r0, r4, 0x1
	  li        r29, 0
	  sth       r29, 0x198(r31)
	  mulli     r0, r0, 0xC
	  sth       r3, 0x19A(r31)
	  mr        r3, r0
	  bl        -0x389A0
	  mulli     r30, r29, 0xC
	  stw       r3, 0x19C(r31)
	  b         .loc_0x258

	.loc_0x23C:
	  lwz       r0, 0x19C(r31)
	  li        r4, -0x1
	  li        r5, -0x1
	  add       r3, r0, r30
	  bl        .loc_0x330
	  addi      r30, r30, 0xC
	  addi      r29, r29, 0x1

	.loc_0x258:
	  lhz       r3, 0x198(r31)
	  lhz       r0, 0x19A(r31)
	  sub       r3, r0, r3
	  addi      r0, r3, 0x1
	  cmpw      r29, r0
	  blt+      .loc_0x23C
	  li        r0, 0x1
	  stb       r0, 0x185(r31)
	  li        r27, 0
	  li        r3, 0x14
	  stb       r27, 0x187(r31)
	  stb       r27, 0x188(r31)
	  stb       r27, 0x189(r31)
	  stb       r27, 0x18A(r31)
	  stb       r27, 0x18B(r31)
	  bl        -0x38A08
	  lis       r4, 0x803A
	  stw       r3, 0x1B0(r31)
	  subi      r3, r4, 0x24E0
	  lwz       r26, 0x10(r3)
	  mr        r28, r27

	.loc_0x2AC:
	  addi      r3, r26, 0x90
	  bl        -0x3F3A8
	  mr.       r30, r3
	  ble-      .loc_0x2FC
	  li        r3, 0x8
	  bl        -0x38A34
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x2D4
	  bl        0x96778

	.loc_0x2D4:
	  lwz       r3, 0x1B0(r31)
	  rlwinm    r4,r30,0,16,31
	  li        r5, 0
	  stwx      r29, r3, r28
	  lwz       r3, 0x1B0(r31)
	  lwzx      r3, r3, r28
	  bl        0x968A4
	  lwz       r3, 0x1B0(r31)
	  lwzx      r3, r3, r28
	  bl        0x968EC

	.loc_0x2FC:
	  addi      r27, r27, 0x1
	  lwz       r26, 0xC(r26)
	  cmpwi     r27, 0x5
	  addi      r28, r28, 0x4
	  blt+      .loc_0x2AC
	  li        r0, 0
	  stb       r0, 0x10(r31)
	  mr        r3, r31
	  lwz       r0, 0x4C(r1)
	  lmw       r26, 0x30(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr

	.loc_0x330:
	*/
}

/*
 * --INFO--
 * Address:	8007FAA8
 * Size:	00002C
 */
void TimeGraph::PikiNum::set(int color, int num)
{
	if (color >= PikiMinColor && color <= PikiMaxColor) {
		mNum[color] = num;
		return;
	}

	mNum[Blue] = mNum[Red] = mNum[Yellow] = num;
}

/*
 * --INFO--
 * Address:	8007FAD4
 * Size:	000070
 */
PlayerState::UfoParts::UfoParts() { }

/*
 * --INFO--
 * Address:	8007FB44
 * Size:	000040
 */
bool PlayerState::courseOpen(int courseID)
{
	if (courseID >= 0 && courseID <= 5) {
		return (gameflow._1C8 & (1 << courseID)) != 0;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8007FB84
 * Size:	00001C
 */
bool PlayerState::happyEndable() { return _180 >= 25; }

/*
 * --INFO--
 * Address:	8007FBA0
 * Size:	000074
 */
void PlayerState::setChallengeMode()
{
	_1B6 = 1;
	for (int i = 0; i < 63; i++) {
		mDemoFlags.setFlagOnly(i);
	}

	_185 = 0;
	_184 = 255;
	_186 = 0;
	_1AC = 255;
	_11  = 1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void PlayerState::setDebugMode()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007FC14
 * Size:	00000C
 */
void PlayerState::getPartsGetCount(int)
{
	/*
	.loc_0x0:
	  add       r3, r3, r4
	  lbz       r3, 0x187(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void PlayerState::getCardPikiCount(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007FC20
 * Size:	000008
 */
int PlayerState::getCardUfoPartsCount() { return mCurrParts; }

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void PlayerState::getUfoPercentage()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007FC28
 * Size:	000084
 */
void PlayerState::getTotalPikiCount(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x1DF0
	  lis       r3, 0x803A
	  stwu      r1, -0x30(r1)
	  subi      r3, r3, 0x24E0
	  stmw      r27, 0x1C(r1)
	  addi      r27, r4, 0
	  mulli     r4, r27, 0xC
	  add       r4, r0, r4
	  li        r30, 0
	  li        r28, 0
	  lwz       r5, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  add       r31, r0, r5
	  lwz       r29, 0x10(r3)
	  add       r31, r4, r31

	.loc_0x4C:
	  addi      r3, r29, 0x2C
	  addi      r4, r27, 0
	  bl        0x46528
	  addi      r28, r28, 0x1
	  lwz       r29, 0xC(r29)
	  cmpwi     r28, 0x5
	  add       r30, r30, r3
	  blt+      .loc_0x4C
	  mr        r3, r31
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007FCAC
 * Size:	0003FC
 */
void PlayerState::saveCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  stb       r0, 0x185(r3)
	  addi      r3, r1, 0x14
	  bl        -0x3BE74
	  lis       r4, 0x636F
	  addi      r3, r1, 0x14
	  addi      r4, r4, 0x6E74
	  bl        -0x3BE1C
	  addi      r3, r1, 0x14
	  addi      r4, r31, 0
	  bl        -0x3BCE4
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  addi      r4, r31, 0
	  bl        0x45A00
	  lis       r4, 0x6361
	  addi      r3, r1, 0x14
	  addi      r4, r4, 0x6368
	  bl        -0x3BE48
	  addi      r3, r1, 0x14
	  addi      r4, r31, 0
	  bl        -0x3BD10
	  lwz       r3, 0x3098(r13)
	  mr        r4, r31
	  bl        0x5F338
	  lis       r4, 0x6D65
	  addi      r3, r1, 0x14
	  addi      r4, r4, 0x636B
	  bl        -0x3BE70
	  addi      r3, r1, 0x14
	  addi      r4, r31, 0
	  bl        -0x3BD38
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  addi      r28, r3, 0x10
	  lwz       r27, 0x10(r3)
	  li        r26, 0

	.loc_0xAC:
	  addi      r3, r27, 0x2C
	  addi      r4, r31, 0
	  bl        0x46718
	  addi      r26, r26, 0x1
	  lwz       r27, 0xC(r27)
	  cmpwi     r26, 0x5
	  blt+      .loc_0xAC
	  lis       r4, 0x7566
	  addi      r3, r1, 0x14
	  addi      r4, r4, 0x6F70
	  bl        -0x3BEBC
	  addi      r3, r1, 0x14
	  addi      r4, r31, 0
	  bl        -0x3BD84
	  mr        r3, r31
	  lbz       r4, 0x10(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x54
	  addi      r4, r31, 0
	  bl        0x25B8
	  addi      r3, r30, 0x70
	  addi      r4, r31, 0
	  bl        0x3B04
	  mr        r3, r31
	  lwz       r4, 0x170(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  li        r26, 0
	  mulli     r29, r26, 0xE0
	  b         .loc_0x160

	.loc_0x138:
	  mr        r3, r31
	  lwz       r4, 0x178(r30)
	  lwz       r12, 0x4(r31)
	  addi      r0, r29, 0xDC
	  lbzx      r4, r4, r0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r29, 0xE0
	  addi      r26, r26, 0x1

	.loc_0x160:
	  lwz       r0, 0x170(r30)
	  cmpw      r26, r0
	  blt+      .loc_0x138
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x0(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x4(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x8(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0xC(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x17C(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x180(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x184(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x185(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x186(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x11(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x1AC(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  li        r26, 0

	.loc_0x28C:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  addi      r0, r26, 0x187
	  lbzx      r4, r30, r0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x5
	  blt+      .loc_0x28C
	  mr        r3, r31
	  lwz       r4, 0x1A0(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x1A4(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lis       r4, 0x6C69
	  addi      r3, r1, 0x14
	  addi      r4, r4, 0x6D67
	  bl        -0x3C0D8
	  addi      r3, r1, 0x14
	  addi      r4, r31, 0
	  bl        -0x3BFA0
	  li        r26, 0
	  lwz       r27, 0x0(r28)
	  rlwinm    r29,r26,2,0,29

	.loc_0x30C:
	  addi      r3, r27, 0x90
	  bl        -0x3F93C
	  cmpwi     r3, 0
	  ble-      .loc_0x32C
	  lwz       r3, 0x1B0(r30)
	  mr        r4, r31
	  lwzx      r3, r3, r29
	  bl        0x962C4

	.loc_0x32C:
	  addi      r26, r26, 0x1
	  lwz       r27, 0xC(r27)
	  cmpwi     r26, 0x5
	  addi      r29, r29, 0x4
	  blt+      .loc_0x30C
	  lis       r4, 0x7669
	  addi      r3, r1, 0x14
	  addi      r4, r4, 0x7366
	  bl        -0x3C134
	  addi      r3, r1, 0x14
	  addi      r4, r31, 0
	  bl        -0x3BFFC
	  mr        r3, r31
	  lwz       r28, 0x0(r28)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  li        r27, 0

	.loc_0x378:
	  mr        r3, r31
	  lwz       r0, 0x20(r28)
	  lwz       r12, 0x4(r31)
	  rlwinm    r4,r0,0,24,31
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r27, r27, 0x1
	  lwz       r28, 0xC(r28)
	  cmpwi     r27, 0x5
	  blt+      .loc_0x378
	  li        r27, 0

	.loc_0x3A8:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  add       r28, r30, r27
	  lbz       r4, 0x18(r28)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x36(r28)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x1E
	  blt+      .loc_0x3A8
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800800A8
 * Size:	0003CC
 */
void PlayerState::loadCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r26, 0x28(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  addi      r3, r1, 0x18
	  bl        -0x3C268
	  addi      r3, r1, 0x18
	  addi      r4, r30, 0
	  bl        -0x3C034
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  addi      r4, r30, 0
	  bl        0x45694
	  addi      r3, r1, 0x18
	  addi      r4, r30, 0
	  bl        -0x3C050
	  lwz       r3, 0x3098(r13)
	  mr        r4, r30
	  bl        0x5F098
	  addi      r3, r1, 0x18
	  addi      r4, r30, 0
	  bl        -0x3C068
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  addi      r31, r3, 0x10
	  lwz       r27, 0x10(r3)
	  li        r26, 0

	.loc_0x74:
	  addi      r3, r27, 0x2C
	  addi      r4, r30, 0
	  bl        0x463DC
	  addi      r26, r26, 0x1
	  lwz       r27, 0xC(r27)
	  cmpwi     r26, 0x5
	  blt+      .loc_0x74
	  addi      r3, r1, 0x18
	  addi      r4, r30, 0
	  bl        -0x3C0A4
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x10(r29)
	  addi      r4, r30, 0
	  addi      r3, r29, 0x54
	  bl        0x2274
	  addi      r3, r29, 0x70
	  addi      r4, r30, 0
	  bl        0x37F4
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  li        r26, 0
	  addi      r27, r26, 0
	  b         .loc_0x12C

	.loc_0x104:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x178(r29)
	  addi      r0, r27, 0xDC
	  addi      r26, r26, 0x1
	  stbx      r3, r4, r0
	  addi      r27, r27, 0xE0

	.loc_0x12C:
	  cmpw      r26, r28
	  blt+      .loc_0x104
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x4(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x8(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x17C(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x180(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x184(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x185(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x186(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x11(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x1AC(r29)
	  li        r26, 0

	.loc_0x274:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r26, 0x187
	  addi      r26, r26, 0x1
	  stbx      r3, r29, r0
	  cmpwi     r26, 0x5
	  blt+      .loc_0x274
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x1A0(r29)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x1A4(r29)
	  addi      r4, r30, 0
	  addi      r3, r1, 0x18
	  bl        -0x3C2E0
	  li        r26, 0
	  lwz       r28, 0x0(r31)
	  rlwinm    r27,r26,2,0,29

	.loc_0x2E4:
	  addi      r3, r28, 0x90
	  bl        -0x3FD10
	  cmpwi     r3, 0
	  ble-      .loc_0x304
	  lwz       r3, 0x1B0(r29)
	  mr        r4, r30
	  lwzx      r3, r3, r27
	  bl        0x95E80

	.loc_0x304:
	  addi      r26, r26, 0x1
	  lwz       r28, 0xC(r28)
	  cmpwi     r26, 0x5
	  addi      r27, r27, 0x4
	  blt+      .loc_0x2E4
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x18
	  addi      r4, r30, 0
	  bl        -0x3C340
	  lwz       r27, 0x0(r31)
	  li        r28, 0

	.loc_0x340:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  stw       r0, 0x20(r27)
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x5
	  lwz       r27, 0xC(r27)
	  blt+      .loc_0x340
	  lwz       r3, 0x3098(r13)
	  bl        0x5FD48
	  li        r28, 0

	.loc_0x378:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  add       r27, r29, r28
	  stb       r3, 0x18(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r28, 0x1
	  stb       r3, 0x36(r27)
	  cmpwi     r28, 0x1E
	  blt+      .loc_0x378
	  lmw       r26, 0x28(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80080474
 * Size:	000044
 */
bool PlayerState::isTutorial()
{
	if (flowCont._A8 && flowCont._A8->_26) {
		return false;
	}

	if (_1B6) {
		return false;
	}

	return _185;
}

/*
 * --INFO--
 * Address:	800804B8
 * Size:	00002C
 */
bool PlayerState::isGameCourse()
{
	int val = flowCont._A8->_24;
	return (val >= 0 && val < 5);
}

/*
 * --INFO--
 * Address:	800804E4
 * Size:	000068
 */
void PlayerState::checkLimitGenFlag(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r5, r5, 0x24E0
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0xA8(r5)
	  lhz       r5, 0x24(r5)
	  cmpwi     r5, 0
	  blt-      .loc_0x34
	  cmpwi     r5, 0x5
	  bge-      .loc_0x34
	  li        r0, 0x1

	.loc_0x34:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x44
	  li        r3, 0x1
	  b         .loc_0x58

	.loc_0x44:
	  lwz       r3, 0x1B0(r3)
	  rlwinm    r0,r5,2,0,29
	  rlwinm    r4,r4,0,16,31
	  lwzx      r3, r3, r0
	  bl        0x95E7C

	.loc_0x58:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008054C
 * Size:	000080
 */
void PlayerState::setLimitGenFlag(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r5, r5, 0x24E0
	  li        r0, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r5, 0xA8(r5)
	  lhz       r5, 0x24(r5)
	  cmpwi     r5, 0
	  blt-      .loc_0x40
	  cmpwi     r5, 0x5
	  bge-      .loc_0x40
	  li        r0, 0x1

	.loc_0x40:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x68
	  lwz       r3, 0x1B0(r30)
	  rlwinm    r31,r5,2,0,29
	  rlwinm    r4,r4,0,16,31
	  lwzx      r3, r3, r31
	  bl        0x95DE0
	  lwz       r3, 0x1B0(r30)
	  lwzx      r3, r3, r31
	  bl        0x95C20

	.loc_0x68:
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
 * Address:	800805CC
 * Size:	000020
 */
void PlayerState::displayPikiCount(int)
{
	/*
	.loc_0x0:
	  li        r5, 0x1
	  lbz       r0, 0x1AC(r3)
	  slw       r3, r5, r4
	  and.      r4, r3, r0
	  neg       r3, r4
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800805EC
 * Size:	000018
 */
void PlayerState::setDisplayPikiCount(int)
{
	/*
	.loc_0x0:
	  li        r0, 0x1
	  lbz       r5, 0x1AC(r3)
	  slw       r0, r0, r4
	  or        r0, r5, r0
	  stb       r0, 0x1AC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void PlayerState::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80080604
 * Size:	00005C
 */
bool PlayerState::hasUfoParts(u32 idx)
{
	for (int i = 0; i < mTotalParts; i++) {
		if (idx == mUfoParts[i]._08) {
			return mUfoParts[i]._DC != 0;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	80080660
 * Size:	0000E4
 */
void PlayerState::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  stw       r30, 0x30(r1)
	  lbz       r30, 0x1B6(r3)
	  cmplwi    r30, 0
	  bne-      .loc_0x2C
	  addi      r3, r31, 0x54
	  bl        0x1BE8

	.loc_0x2C:
	  cmplwi    r30, 0
	  bne-      .loc_0x40
	  lbz       r0, 0x185(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xCC

	.loc_0x40:
	  lis       r3, 0x803A
	  lhz       r0, 0x194(r31)
	  subi      r3, r3, 0x2848
	  lwz       r30, 0x2F8(r3)
	  cmpw      r30, r0
	  beq-      .loc_0xCC
	  bl        0x91EA8
	  sth       r30, 0x194(r31)
	  lis       r3, 0x803D
	  addi      r4, r3, 0x1ED0
	  lhz       r3, 0x18C(r31)
	  addi      r5, r4, 0x4
	  lhz       r0, 0x194(r31)
	  addi      r6, r4, 0x8
	  lwz       r4, 0x0(r4)
	  sub       r0, r0, r3
	  lwz       r3, 0x190(r31)
	  mulli     r0, r0, 0xC
	  stwx      r4, r3, r0
	  lhz       r3, 0x18C(r31)
	  lhz       r0, 0x194(r31)
	  lwz       r5, 0x0(r5)
	  sub       r0, r0, r3
	  lwz       r4, 0x190(r31)
	  mulli     r3, r0, 0xC
	  addi      r0, r3, 0x4
	  stwx      r5, r4, r0
	  lhz       r3, 0x18C(r31)
	  lhz       r0, 0x194(r31)
	  lwz       r5, 0x0(r6)
	  sub       r0, r0, r3
	  lwz       r4, 0x190(r31)
	  mulli     r3, r0, 0xC
	  addi      r0, r3, 0x8
	  stwx      r5, r4, r0

	.loc_0xCC:
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
 * Address:	80080744
 * Size:	0001B0
 */
void PlayerState::initCourse()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x8
	  stw       r0, 0x4(r1)
	  subfic    r0, r4, 0xA
	  cmpwi     r4, 0xA
	  mtctr     r0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x20(r1)
	  bge-      .loc_0x30

	.loc_0x2C:
	  bdnz-     .loc_0x2C

	.loc_0x30:
	  li        r5, 0
	  addi      r6, r5, 0
	  li        r4, -0x1
	  b         .loc_0x5C

	.loc_0x40:
	  lwz       r0, 0x190(r31)
	  addi      r5, r5, 0x1
	  add       r3, r0, r6
	  stw       r4, 0x8(r3)
	  addi      r6, r6, 0xC
	  stw       r4, 0x4(r3)
	  stw       r4, 0x0(r3)

	.loc_0x5C:
	  lhz       r3, 0x18C(r31)
	  lhz       r0, 0x18E(r31)
	  sub       r3, r0, r3
	  addi      r0, r3, 0x1
	  cmpw      r5, r0
	  blt+      .loc_0x40
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x204
	  li        r0, 0
	  stb       r0, 0x1B5(r31)
	  li        r3, 0x10
	  stb       r0, 0xBC(r31)
	  bl        -0x397D0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA4
	  bl        0x93B84

	.loc_0xA4:
	  stw       r30, 0x1B8(r31)
	  li        r3, 0x10
	  bl        -0x397EC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xC0
	  bl        0x93B68

	.loc_0xC0:
	  stw       r30, 0x1BC(r31)
	  li        r4, 0x15
	  lwz       r3, 0x1B8(r31)
	  bl        0x93C4C
	  lwz       r3, 0x1BC(r31)
	  li        r4, 0x16
	  bl        0x93C40
	  lwz       r3, 0x1B8(r31)
	  bl        0x93CB8
	  lwz       r3, 0x1BC(r31)
	  bl        0x93CB0
	  lfs       f0, -0x6144(r13)
	  addi      r3, r31, 0x70
	  stfs      f0, 0x1C0(r31)
	  lfs       f0, -0x6140(r13)
	  stfs      f0, 0x1C4(r31)
	  lfs       f0, -0x613C(r13)
	  stfs      f0, 0x1C8(r31)
	  bl        0x3448
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r4, 0xA8(r3)
	  lis       r3, 0x1
	  subi      r0, r3, 0x1
	  lhz       r3, 0x24(r4)
	  cmpwi     r3, 0
	  sth       r0, 0x194(r31)
	  beq-      .loc_0x138
	  li        r0, 0
	  stb       r0, 0x185(r31)

	.loc_0x138:
	  lwz       r4, 0x3120(r13)
	  addi      r3, r31, 0xC4
	  lwz       r0, 0x48(r4)
	  stw       r0, 0xC0(r31)
	  lwz       r8, 0xC0(r31)
	  lwz       r6, 0x3120(r13)
	  lwz       r4, 0x24(r8)
	  addi      r5, r8, 0x14
	  lwz       r7, 0x50(r6)
	  addi      r6, r8, 0x4
	  bl        0x9F038
	  addi      r3, r1, 0x10
	  li        r4, 0x58
	  bl        0x9E6A8
	  addi      r30, r3, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x58
	  bl        0x9E698
	  addi      r4, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r31, 0xC4
	  bl        0x9F198
	  addi      r3, r31, 0x54
	  bl        0x1984
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800808F4
 * Size:	0000D0
 */
void PlayerState::exitCourse()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  addi      r4, r5, 0
	  li        r6, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  stw       r28, 0x18(r1)
	  addi      r28, r3, 0
	  b         .loc_0x44

	.loc_0x30:
	  lwz       r3, 0x178(r28)
	  addi      r0, r5, 0xD4
	  addi      r6, r6, 0x1
	  stwx      r4, r3, r0
	  addi      r5, r5, 0xE0

	.loc_0x44:
	  lwz       r0, 0x170(r28)
	  cmpw      r6, r0
	  blt+      .loc_0x30
	  li        r0, 0
	  stw       r0, 0x170(r28)
	  mr        r3, r28
	  bl        0x27C
	  mr        r30, r3
	  b         .loc_0x98

	.loc_0x68:
	  li        r29, 0
	  addi      r31, r1, 0xC

	.loc_0x70:
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  addi      r5, r29, 0
	  bl        0x2AC
	  addi      r29, r29, 0x1
	  stw       r3, 0x0(r31)
	  cmpwi     r29, 0x3
	  addi      r31, r31, 0x4
	  blt+      .loc_0x70
	  addi      r30, r30, 0x1

	.loc_0x98:
	  mr        r3, r28
	  bl        0x264
	  cmpw      r30, r3
	  ble+      .loc_0x68
	  li        r0, 0
	  stb       r0, 0x185(r28)
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
 * Address:	800809C4
 * Size:	000094
 */
void PlayerState::setNavi(bool p1)
{
	if (!p1) {
		_1B4 = 0;
		return;
	}

	if (_1B4 == 0) {
		_1B8->restart();
		_1BC->restart();
		_1B4 = 1;
		mPikiAnimMgr.startMotion(PaniMotionInfo(88), PaniMotionInfo(88));
	}
}

/*
 * --INFO--
 * Address:	80080A58
 * Size:	000008
 */
int PlayerState::getFinalDeadPikis() { return _1A0; }

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PlayerState::getFinalBornPikis()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80080A60
 * Size:	000150
 */
void PlayerState::updateFinalResult()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803D
	  stw       r0, 0x4(r1)
	  addi      r6, r4, 0x1E58
	  stwu      r1, -0x58(r1)
	  stmw      r22, 0x30(r1)
	  addi      r28, r3, 0
	  lis       r3, 0x803D
	  addi      r5, r3, 0x1EAC
	  lis       r3, 0x803D
	  addi      r31, r3, 0x1DF0
	  lis       r3, 0x803A
	  addi      r29, r5, 0x8
	  addi      r30, r5, 0x4
	  subi      r27, r3, 0x24E0
	  li        r22, 0
	  lwz       r4, 0x8(r6)
	  lwz       r0, 0x4(r6)
	  lwz       r7, 0x1A0(r28)
	  add       r0, r0, r4
	  lwz       r4, 0x0(r6)
	  add       r0, r0, r7
	  add       r0, r4, r0
	  stw       r0, 0x1A0(r28)
	  lwz       r4, 0x8(r5)
	  lwz       r0, 0x4(r5)
	  lwz       r6, 0x1A4(r28)
	  add       r0, r0, r4
	  lwz       r4, 0x0(r5)
	  add       r0, r0, r6
	  add       r0, r4, r0
	  stw       r0, 0x1A4(r28)
	  li        r0, 0
	  stw       r0, 0x1A8(r28)

	.loc_0x88:
	  lwz       r4, 0x8(r31)
	  li        r24, 0
	  lwz       r0, 0x4(r31)
	  mr        r26, r24
	  lwz       r3, 0x0(r31)
	  add       r23, r0, r4
	  lwz       r25, 0x10(r27)
	  add       r23, r3, r23

	.loc_0xA8:
	  addi      r3, r25, 0x2C
	  addi      r4, r22, 0
	  bl        0x45694
	  addi      r26, r26, 0x1
	  lwz       r25, 0xC(r25)
	  cmpwi     r26, 0x5
	  add       r24, r24, r3
	  blt+      .loc_0xA8
	  lwz       r0, 0x1A8(r28)
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x3
	  add       r0, r0, r23
	  stw       r0, 0x1A8(r28)
	  addi      r31, r31, 0xC
	  blt+      .loc_0x88
	  lis       r3, 0x803D
	  lwz       r7, 0x1A8(r28)
	  addi      r5, r3, 0x1EC4
	  lwz       r6, 0x8(r5)
	  lis       r4, 0x803A
	  lwz       r0, 0x4(r5)
	  lis       r3, 0x803D
	  lwz       r5, 0x0(r5)
	  add       r0, r0, r6
	  add       r0, r0, r7
	  add       r0, r5, r0
	  stw       r0, 0x1A8(r28)
	  subi      r6, r4, 0x2848
	  addi      r3, r3, 0x1EAC
	  lwz       r4, 0x0(r29)
	  lwz       r0, 0x0(r30)
	  lwz       r5, 0xB8(r6)
	  add       r0, r0, r4
	  lwz       r3, 0x0(r3)
	  add       r0, r0, r5
	  add       r0, r3, r0
	  stw       r0, 0xB8(r6)
	  lwz       r0, 0x5C(r1)
	  lmw       r22, 0x30(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80080BB0
 * Size:	000014
 */
int PlayerState::getCurrDay() { return gameflow._2FC - 1; }

/*
 * --INFO--
 * Address:	80080BC4
 * Size:	000008
 */
int PlayerState::getTotalDays() { return 30; }

/*
 * --INFO--
 * Address:	80080BCC
 * Size:	000028
 */
int PlayerState::getStartHour()
{
	return 0;
	/*
	.loc_0x0:
	  lis       r3, 0x803A
	  stwu      r1, -0x20(r1)
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x20(r3)
	  lfs       f0, 0x10(r3)
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r3, 0x1C(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80080BF4
 * Size:	000028
 */
int PlayerState::getEndHour()
{
	return 0;
	/*
	.loc_0x0:
	  lis       r3, 0x803A
	  stwu      r1, -0x20(r1)
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x20(r3)
	  lfs       f0, 0x20(r3)
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r3, 0x1C(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80080C1C
 * Size:	00004C
 */
int PlayerState::getPikiHourCount(int, int)
{
	return 0;
	/*
	.loc_0x0:
	  lhz       r6, 0x18C(r3)
	  rlwinm    r0,r4,0,16,31
	  cmpwi     r5, 0
	  lwz       r3, 0x190(r3)
	  sub       r0, r0, r6
	  mulli     r0, r0, 0xC
	  add       r4, r3, r0
	  blt-      .loc_0x34
	  cmpwi     r5, 0x2
	  bgt-      .loc_0x34
	  rlwinm    r0,r5,2,0,29
	  lwzx      r3, r4, r0
	  blr

	.loc_0x34:
	  lwz       r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  add       r3, r0, r3
	  add       r3, r4, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80080C68
 * Size:	000008
 */
int PlayerState::getTotalParts() { return mTotalParts; }

/*
 * --INFO--
 * Address:	80080C70
 * Size:	000008
 */
int PlayerState::getCurrParts() { return mCurrParts; }

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void PlayerState::getRestParts()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80080C78
 * Size:	000050
 */
bool PlayerState::isUfoBroken()
{
	if (_1B6) {
		return false;
	}

	if (mCurrParts > 0) {
		return false;
	}

	if (flowCont._A8->_26 == 0) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	80080CC8
 * Size:	0000C4
 */
void PlayerState::registerUfoParts(int p1, u32 p2, u32 p3)
{
	pelletMgr->_1F8 = PaniPelletAnimator::createMotionTable();
	if (_170 >= mTotalParts) {
		ID32 id1(p2);
		ID32 id2(p3);
	}

	UfoParts* part           = &mUfoParts[_170];
	part->_04                = p1;
	part->_0C                = p3;
	part->_08                = p2;
	PelletShapeObject* shape = pelletMgr->getShapeObject(p2);
	part->initAnim(shape);

	if (shape) {
		shape->mShape->makeInstance(part->_C4, 0);
	}

	_170++;
}

/*
 * --INFO--
 * Address:	80080D8C
 * Size:	000074
 */
void PlayerState::UfoParts::initAnim(PelletShapeObject* shape)
{
	mPelletShape = shape;
	if (!shape) {
		return;
	}

	mAnimator.init(&mPelletShape->_08, &mPelletShape->_18, mPelletShape->mAnimMgr, pelletMgr->_1F8);
	_D8 = 0.0f;
	mAnimator.startMotion(PaniMotionInfo(0));
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void PlayerState::UfoParts::startMotion(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void PlayerState::UfoParts::startMotion(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void PlayerState::UfoParts::stopMotion()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80080E00
 * Size:	0001F0
 */
void PlayerState::UfoParts::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  stw       r29, 0x44(r1)
	  mr        r29, r4
	  stw       r28, 0x40(r1)
	  mr        r28, r3
	  lwz       r3, 0x30AC(r13)
	  lwz       r31, 0x54(r28)
	  bl        0x71E0C
	  lwz       r0, 0x0(r29)
	  addi      r30, r3, 0
	  cmpwi     r0, 0x6
	  beq-      .loc_0x5C
	  bge-      .loc_0x50
	  cmpwi     r0, 0
	  beq-      .loc_0x124
	  b         .loc_0x1D0

	.loc_0x50:
	  cmpwi     r0, 0x8
	  beq-      .loc_0x178
	  b         .loc_0x1D0

	.loc_0x5C:
	  cmpwi     r31, 0x3
	  bne-      .loc_0xC8
	  lis       r3, 0x7566
	  lwz       r4, 0x8(r28)
	  addi      r0, r3, 0x3033
	  cmpw      r4, r0
	  beq-      .loc_0xB4
	  bge-      .loc_0x8C
	  addi      r0, r3, 0x3031
	  cmpw      r4, r0
	  beq-      .loc_0xA0
	  b         .loc_0x1D0

	.loc_0x8C:
	  lis       r3, 0x7573
	  addi      r0, r3, 0x7431
	  cmpw      r4, r0
	  beq-      .loc_0x1D0
	  b         .loc_0x1D0

	.loc_0xA0:
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0xE3
	  bl        0x9708
	  b         .loc_0x1D0

	.loc_0xB4:
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0xE1
	  bl        0x96F4
	  b         .loc_0x1D0

	.loc_0xC8:
	  addi      r3, r1, 0x2C
	  lwz       r4, 0x8(r28)
	  bl        -0x3D03C
	  lis       r3, 0x7573
	  lwz       r4, 0x8(r28)
	  addi      r0, r3, 0x7435
	  cmpw      r4, r0
	  beq-      .loc_0x100
	  bge-      .loc_0x1D0
	  lis       r3, 0x7566
	  addi      r0, r3, 0x3031
	  cmpw      r4, r0
	  beq-      .loc_0x110
	  b         .loc_0x1D0

	.loc_0x100:
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0xE6
	  bl        0x96A8

	.loc_0x110:
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0xE4
	  bl        0x9698
	  b         .loc_0x1D0

	.loc_0x124:
	  lwz       r0, 0xD4(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x160
	  addi      r3, r1, 0x18
	  li        r4, 0x2
	  bl        0x9E020
	  addi      r31, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x10
	  li        r4, 0x2
	  bl        0x9E040
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r28, 0x10
	  bl        0x18B0C

	.loc_0x160:
	  lfs       f0, -0x761C(r2)
	  addi      r3, r1, 0x20
	  stfs      f0, 0xD8(r28)
	  lwz       r4, 0x8(r28)
	  bl        -0x3D0DC
	  b         .loc_0x1D0

	.loc_0x178:
	  cmpwi     r31, 0x1
	  bne-      .loc_0x1D0
	  lwz       r0, 0x4(r29)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1B8
	  bge-      .loc_0x1D0
	  cmpwi     r0, 0
	  bge-      .loc_0x19C
	  b         .loc_0x1D0

	.loc_0x19C:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r28, 0xB8
	  li        r4, 0x124
	  li        r6, 0
	  li        r7, 0
	  bl        0x11BB88
	  b         .loc_0x1D0

	.loc_0x1B8:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r28, 0xB8
	  li        r4, 0x125
	  li        r6, 0
	  li        r7, 0
	  bl        0x11BB6C

	.loc_0x1D0:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  lwz       r28, 0x40(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80080FF0
 * Size:	0000D0
 */
void PlayerState::ufoAssignStart()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  mr        r29, r3
	  lwz       r0, 0x14(r3)
	  cmplwi    r0, 0
	  mr        r30, r0
	  beq-      .loc_0xB4
	  lwz       r3, 0xD4(r30)
	  lbz       r0, 0x28(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x80
	  cmplwi    r3, 0
	  beq-      .loc_0x74
	  addi      r3, r1, 0x1C
	  li        r4, 0x3
	  bl        0x9DF1C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x14
	  li        r4, 0x1
	  bl        0x9DF3C
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r30, 0x10
	  bl        0x18A08

	.loc_0x74:
	  lfs       f0, -0x761C(r2)
	  stfs      f0, 0xD8(r30)
	  b         .loc_0xAC

	.loc_0x80:
	  cmplwi    r3, 0
	  beq-      .loc_0xA4
	  addi      r5, r30, 0
	  addi      r3, r1, 0xC
	  li        r4, 0x1
	  bl        0x9DF08
	  addi      r4, r3, 0
	  addi      r3, r30, 0x10
	  bl        0x18A30

	.loc_0xA4:
	  lfs       f0, -0x761C(r2)
	  stfs      f0, 0xD8(r30)

	.loc_0xAC:
	  li        r0, 0
	  stw       r0, 0x14(r29)

	.loc_0xB4:
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
 * Address:	800810C0
 * Size:	000084
 */
void PlayerState::startSpecialMotions()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x7573
	  stw       r0, 0x4(r1)
	  addi      r4, r4, 0x7431
	  li        r5, 0x4
	  stwu      r1, -0x18(r1)
	  li        r6, 0
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        0x124
	  lis       r31, 0x7566
	  addi      r3, r30, 0
	  addi      r4, r31, 0x3031
	  li        r5, 0x4
	  li        r6, 0
	  bl        0x10C
	  addi      r3, r30, 0
	  addi      r4, r31, 0x3032
	  li        r5, 0x4
	  li        r6, 0
	  bl        0xF8
	  addi      r3, r30, 0
	  addi      r4, r31, 0x3033
	  li        r5, 0x4
	  li        r6, 0
	  bl        0xE4
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
 * Address:	80081144
 * Size:	0000C8
 */
void PlayerState::startAfterMotions()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stmw      r27, 0x2C(r1)
	  addi      r27, r3, 0
	  li        r29, 0
	  li        r30, 0
	  lfs       f31, -0x761C(r2)
	  b         .loc_0xA4

	.loc_0x28:
	  lwz       r0, 0x178(r27)
	  add.      r0, r0, r30
	  mr        r28, r0
	  beq-      .loc_0x9C
	  lbz       r0, 0xDC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x9C
	  lwz       r0, 0xD4(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x9C
	  addi      r3, r1, 0x1C
	  lwz       r4, 0x8(r28)
	  bl        -0x3D308
	  lwz       r0, 0xD4(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x98
	  addi      r3, r1, 0x14
	  li        r4, 0x2
	  bl        0x9DDA4
	  addi      r31, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0xC
	  li        r4, 0x2
	  bl        0x9DDC4
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r28, 0x10
	  bl        0x18890

	.loc_0x98:
	  stfs      f31, 0xD8(r28)

	.loc_0x9C:
	  addi      r30, r30, 0xE0
	  addi      r29, r29, 0x1

	.loc_0xA4:
	  lwz       r0, 0x170(r27)
	  cmpw      r29, r0
	  blt+      .loc_0x28
	  lmw       r27, 0x2C(r1)
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008120C
 * Size:	00010C
 */
void PlayerState::startUfoPartsMotion(u32, int, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r6, 0
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  addi      r29, r5, 0
	  bl        0x69C
	  mr.       r30, r3
	  beq-      .loc_0xF0
	  lwz       r3, 0xD4(r30)
	  lbz       r0, 0x28(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0xC4
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x80
	  cmplwi    r3, 0
	  beq-      .loc_0xB8
	  addi      r3, r1, 0x38
	  li        r4, 0x3
	  bl        0x9DCF8
	  addi      r31, r3, 0
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x30
	  bl        0x9DD18
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r30, 0x10
	  bl        0x187E4
	  b         .loc_0xB8

	.loc_0x80:
	  cmplwi    r3, 0
	  beq-      .loc_0xB8
	  addi      r3, r1, 0x28
	  addi      r4, r29, 0
	  bl        0x9DCBC
	  addi      r31, r3, 0
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x20
	  bl        0x9DCDC
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r30, 0x10
	  bl        0x187A8

	.loc_0xB8:
	  lfs       f0, -0x761C(r2)
	  stfs      f0, 0xD8(r30)
	  b         .loc_0xF0

	.loc_0xC4:
	  cmplwi    r3, 0
	  beq-      .loc_0xE8
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  bl        0x9DCA8
	  addi      r4, r3, 0
	  addi      r3, r30, 0x10
	  bl        0x187D0

	.loc_0xE8:
	  lfs       f0, -0x761C(r2)
	  stfs      f0, 0xD8(r30)

	.loc_0xF0:
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
 * Address:	80081318
 * Size:	000458
 */
void PlayerState::getUfoParts(u32, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stw       r31, 0x9C(r1)
	  stw       r30, 0x98(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x94(r1)
	  addi      r29, r3, 0
	  stw       r28, 0x90(r1)
	  addi      r28, r4, 0
	  bl        0x588
	  mr.       r31, r3
	  bne-      .loc_0x48
	  rlwinm.   r0,r30,0,24,31
	  bne-      .loc_0x48
	  addi      r3, r1, 0x84
	  addi      r4, r28, 0
	  bl        -0x3D4C8

	.loc_0x48:
	  subis     r0, r28, 0x756E
	  cmplwi    r0, 0x3034
	  beq-      .loc_0x80
	  cmplwi    r0, 0x3039
	  beq-      .loc_0x80
	  cmplwi    r0, 0x3130
	  beq-      .loc_0x80
	  cmplwi    r0, 0x3131
	  beq-      .loc_0x80
	  cmplwi    r0, 0x3134
	  beq-      .loc_0x80
	  lwz       r3, 0x180(r29)
	  addi      r0, r3, 0x1
	  stw       r0, 0x180(r29)

	.loc_0x80:
	  lis       r3, 0x7566
	  addi      r0, r3, 0x3130
	  cmpw      r28, r0
	  beq-      .loc_0xDC
	  bge-      .loc_0xA4
	  addi      r0, r3, 0x3031
	  cmpw      r28, r0
	  beq-      .loc_0xB4
	  b         .loc_0x128

	.loc_0xA4:
	  addi      r0, r3, 0x3132
	  cmpw      r28, r0
	  bge-      .loc_0x128
	  b         .loc_0x104

	.loc_0xB4:
	  lbz       r3, 0x11(r29)
	  li        r4, 0x8
	  subfic    r0, r4, 0xA
	  ori       r3, r3, 0x1
	  mtctr     r0
	  cmpwi     r4, 0xA
	  stb       r3, 0x11(r29)
	  bge-      .loc_0x128

	.loc_0xD4:
	  bdnz-     .loc_0xD4
	  b         .loc_0x128

	.loc_0xDC:
	  lbz       r3, 0x11(r29)
	  li        r4, 0x8
	  subfic    r0, r4, 0xA
	  ori       r3, r3, 0x2
	  mtctr     r0
	  cmpwi     r4, 0xA
	  stb       r3, 0x11(r29)
	  bge-      .loc_0x128

	.loc_0xFC:
	  bdnz-     .loc_0xFC
	  b         .loc_0x128

	.loc_0x104:
	  lbz       r3, 0x11(r29)
	  li        r4, 0x8
	  subfic    r0, r4, 0xA
	  ori       r3, r3, 0x4
	  mtctr     r0
	  cmpwi     r4, 0xA
	  stb       r3, 0x11(r29)
	  bge-      .loc_0x128

	.loc_0x124:
	  bdnz-     .loc_0x124

	.loc_0x128:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r3, 0xA8(r3)
	  rlwinm.   r0,r30,0,24,31
	  lhz       r0, 0x26(r3)
	  add       r4, r29, r0
	  lbz       r3, 0x187(r4)
	  addi      r0, r3, 0x1
	  stb       r0, 0x187(r4)
	  bne-      .loc_0x15C
	  li        r0, 0x1
	  stb       r0, 0xDC(r31)
	  b         .loc_0x164

	.loc_0x15C:
	  li        r0, 0x2
	  stb       r0, 0xDC(r31)

	.loc_0x164:
	  lwz       r3, 0x17C(r29)
	  li        r4, 0x20
	  subfic    r0, r4, 0x21
	  addi      r3, r3, 0x1
	  mtctr     r0
	  cmpwi     r4, 0x21
	  stw       r3, 0x17C(r29)
	  bge-      .loc_0x188

	.loc_0x184:
	  bdnz-     .loc_0x184

	.loc_0x188:
	  lwz       r4, 0x2F80(r13)
	  lwz       r5, 0x17C(r29)
	  lwz       r0, 0x190(r4)
	  cmpw      r5, r0
	  blt-      .loc_0x1A8
	  li        r0, 0x5
	  stb       r0, 0x10(r29)
	  b         .loc_0x2E0

	.loc_0x1A8:
	  lwz       r0, 0x180(r4)
	  cmpw      r5, r0
	  blt-      .loc_0x1FC
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x1A4
	  li        r4, 0x4
	  bl        -0x2D880
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x15
	  addi      r3, r3, 0x70
	  bl        0x2564
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x1F0

	.loc_0x1EC:
	  bdnz-     .loc_0x1EC

	.loc_0x1F0:
	  li        r0, 0x4
	  stb       r0, 0x10(r29)
	  b         .loc_0x2E0

	.loc_0x1FC:
	  lwz       r0, 0x170(r4)
	  cmpw      r5, r0
	  blt-      .loc_0x250
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x1A4
	  li        r4, 0x3
	  bl        -0x2D8D4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x7
	  addi      r3, r3, 0x70
	  bl        0x24C0
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x244

	.loc_0x240:
	  bdnz-     .loc_0x240

	.loc_0x244:
	  li        r0, 0x3
	  stb       r0, 0x10(r29)
	  b         .loc_0x2E0

	.loc_0x250:
	  lwz       r0, 0x160(r4)
	  cmpw      r5, r0
	  blt-      .loc_0x2A4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x5
	  addi      r3, r3, 0x70
	  bl        0x2480
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x1A4
	  li        r4, 0x2
	  bl        -0x2D938
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x298

	.loc_0x294:
	  bdnz-     .loc_0x294

	.loc_0x298:
	  li        r0, 0x2
	  stb       r0, 0x10(r29)
	  b         .loc_0x2E0

	.loc_0x2A4:
	  cmpwi     r5, 0x1
	  blt-      .loc_0x2E0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x1A4
	  li        r4, 0x1
	  bl        -0x2D978
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x2D8

	.loc_0x2D4:
	  bdnz-     .loc_0x2D4

	.loc_0x2D8:
	  li        r0, 0x1
	  stb       r0, 0x10(r29)

	.loc_0x2E0:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x2F4
	  li        r0, 0
	  stw       r0, 0x14(r29)
	  b         .loc_0x2F8

	.loc_0x2F4:
	  stw       r31, 0x14(r29)

	.loc_0x2F8:
	  lwz       r0, 0x17C(r29)
	  cmpwi     r0, 0xF
	  blt-      .loc_0x314
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x15
	  addi      r3, r3, 0x70
	  bl        0x23D8

	.loc_0x314:
	  lwz       r0, 0x17C(r29)
	  cmpwi     r0, 0xB
	  blt-      .loc_0x348
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x2FC(r3)
	  subi      r0, r3, 0x1
	  cmpwi     r0, 0x9
	  blt-      .loc_0x348
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1A
	  addi      r3, r3, 0x70
	  bl        0x23A4

	.loc_0x348:
	  rlwinm.   r0,r30,0,24,31
	  bne-      .loc_0x3D0
	  lwz       r3, 0xD4(r31)
	  lbz       r0, 0x28(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x3A4
	  cmplwi    r3, 0
	  beq-      .loc_0x398
	  addi      r3, r1, 0x64
	  li        r4, 0x3
	  bl        0x9D8D0
	  addi      r30, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x5C
	  li        r4, 0x1
	  bl        0x9D8F0
	  addi      r4, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r31, 0x10
	  bl        0x183BC

	.loc_0x398:
	  lfs       f0, -0x7620(r2)
	  stfs      f0, 0xD8(r31)
	  b         .loc_0x3D0

	.loc_0x3A4:
	  cmplwi    r3, 0
	  beq-      .loc_0x3C8
	  addi      r5, r31, 0
	  addi      r3, r1, 0x54
	  li        r4, 0x1
	  bl        0x9D8BC
	  addi      r4, r3, 0
	  addi      r3, r31, 0x10
	  bl        0x183E4

	.loc_0x3C8:
	  lfs       f0, -0x7620(r2)
	  stfs      f0, 0xD8(r31)

	.loc_0x3D0:
	  lwz       r0, 0x17C(r29)
	  cmpwi     r0, 0x1D
	  bne-      .loc_0x410
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xC
	  addi      r3, r3, 0x70
	  bl        0x2300
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xB
	  addi      r3, r3, 0x70
	  bl        0x2340
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x15
	  addi      r3, r3, 0x70
	  bl        0x2330
	  b         .loc_0x438

	.loc_0x410:
	  cmpwi     r0, 0x19
	  bne-      .loc_0x438
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xB
	  addi      r3, r3, 0x70
	  bl        0x22C4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x15
	  addi      r3, r3, 0x70
	  bl        0x2304

	.loc_0x438:
	  lwz       r0, 0xA4(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  lwz       r29, 0x94(r1)
	  lwz       r28, 0x90(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80081770
 * Size:	000058
 */
void PlayerState::getNextPowerupNumber()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x50(r1)
	  li        r0, 0x1
	  stw       r0, 0x38(r1)
	  li        r0, 0x1E
	  lwz       r6, 0x2F80(r13)
	  addi      r4, r1, 0x38
	  lwz       r5, 0x160(r6)
	  stw       r5, 0x3C(r1)
	  lwz       r5, 0x170(r6)
	  stw       r5, 0x40(r1)
	  lwz       r5, 0x180(r6)
	  stw       r5, 0x44(r1)
	  lwz       r5, 0x190(r6)
	  stw       r5, 0x48(r1)
	  stw       r0, 0x4C(r1)
	  lbz       r0, 0x10(r3)
	  lwz       r3, 0x17C(r3)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r4, r0
	  sub       r3, r0, r3
	  addi      r1, r1, 0x50
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800817C8
 * Size:	000100
 */
void PlayerState::preloadHenkaMovie()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  lwz       r4, 0x17C(r3)
	  lbz       r7, 0x10(r3)
	  addi      r5, r4, 0x1
	  cmpwi     r5, 0x1
	  bne-      .loc_0x28
	  li        r7, 0x1
	  b         .loc_0x74

	.loc_0x28:
	  lwz       r6, 0x2F80(r13)
	  lwz       r0, 0x160(r6)
	  cmpw      r5, r0
	  bne-      .loc_0x40
	  li        r7, 0x2
	  b         .loc_0x74

	.loc_0x40:
	  lwz       r0, 0x170(r6)
	  cmpw      r5, r0
	  bne-      .loc_0x54
	  li        r7, 0x3
	  b         .loc_0x74

	.loc_0x54:
	  lwz       r0, 0x180(r6)
	  cmpw      r5, r0
	  bne-      .loc_0x68
	  li        r7, 0x4
	  b         .loc_0x74

	.loc_0x68:
	  cmpwi     r5, 0x1E
	  bne-      .loc_0x74
	  li        r7, 0x5

	.loc_0x74:
	  lis       r4, 0x8022
	  addi      r5, r4, 0x23A0
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x2C(r1)
	  stw       r0, 0x30(r1)
	  lwz       r4, 0x8(r5)
	  lwz       r0, 0xC(r5)
	  stw       r4, 0x34(r1)
	  stw       r0, 0x38(r1)
	  lwz       r0, 0x10(r5)
	  stw       r0, 0x3C(r1)
	  lbz       r0, 0x10(r3)
	  cmpw      r7, r0
	  beq-      .loc_0xF0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  rlwinm    r0,r7,2,0,29
	  addi      r4, r1, 0x28
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwzx      r4, r4, r0
	  li        r6, 0
	  lwz       r12, 0xC(r12)
	  li        r7, 0
	  mtlr      r12
	  li        r8, 0
	  li        r9, -0x1
	  li        r10, 0x1
	  blrl

	.loc_0xF0:
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void PlayerState::lostUfoParts(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800818C8
 * Size:	00004C
 */
void PlayerState::findUfoParts(u32)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x170(r3)
	  li        r7, 0
	  li        r5, 0
	  cmpwi     r0, 0
	  mtctr     r0
	  ble-      .loc_0x44

	.loc_0x18:
	  lwz       r6, 0x178(r3)
	  addi      r0, r5, 0x8
	  lwzx      r0, r6, r0
	  cmplw     r4, r0
	  bne-      .loc_0x38
	  mulli     r0, r7, 0xE0
	  add       r3, r6, r0
	  blr

	.loc_0x38:
	  addi      r5, r5, 0xE0
	  addi      r7, r7, 0x1
	  bdnz+     .loc_0x18

	.loc_0x44:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80081914
 * Size:	0002FC
 */
void PlayerState::renderParts(Graphics&, Shape*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8022
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x160(r1)
	  stmw      r24, 0x140(r1)
	  addi      r24, r3, 0
	  addi      r25, r4, 0
	  addi      r26, r5, 0
	  addi      r30, r6, 0x23B4
	  li        r27, 0
	  li        r29, 0
	  b         .loc_0x1C8

	.loc_0x30:
	  lwz       r0, 0x178(r24)
	  add       r28, r0, r29
	  lbz       r0, 0xDC(r28)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x1C0
	  lwz       r0, 0x4(r28)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x1C0
	  lwz       r0, 0xD4(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x68
	  addi      r3, r1, 0x134
	  lwz       r4, 0x8(r28)
	  bl        -0x3DAE4

	.loc_0x68:
	  lbz       r0, 0x2FA8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xB0
	  lwz       r4, 0x0(r30)
	  addi      r3, r1, 0x10C
	  lwz       r0, 0x4(r30)
	  stw       r4, 0x11C(r1)
	  stw       r0, 0x120(r1)
	  lwz       r4, 0x8(r30)
	  lwz       r0, 0xC(r30)
	  stw       r4, 0x124(r1)
	  stw       r0, 0x128(r1)
	  lwz       r4, 0x10(r30)
	  lwz       r0, 0x14(r30)
	  stw       r4, 0x12C(r1)
	  stw       r0, 0x130(r1)
	  lwz       r4, 0x8(r28)
	  bl        -0x3DB2C

	.loc_0xB0:
	  lfs       f1, 0xD8(r28)
	  addi      r3, r28, 0x10
	  lfs       f2, -0x761C(r2)
	  bl        0x18118
	  addi      r3, r28, 0x10
	  bl        0x1816C
	  mr        r3, r26
	  lwz       r4, 0x4(r28)
	  bl        -0x4C9FC
	  lfs       f0, -0x610C(r13)
	  addi      r31, r3, 0
	  addi      r3, r26, 0
	  stfs      f0, 0xB8(r28)
	  addi      r4, r25, 0
	  addi      r6, r28, 0xB8
	  lfs       f0, -0x6108(r13)
	  stfs      f0, 0xBC(r28)
	  lfs       f0, -0x6104(r13)
	  stfs      f0, 0xC0(r28)
	  lwz       r5, 0x4(r28)
	  bl        -0x4C150
	  lwz       r3, 0x0(r31)
	  mr        r4, r25
	  lwz       r0, 0x4(r31)
	  addi      r5, r1, 0xC8
	  li        r6, 0
	  stw       r3, 0xC8(r1)
	  stw       r0, 0xCC(r1)
	  lwz       r3, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  stw       r3, 0xD0(r1)
	  stw       r0, 0xD4(r1)
	  lwz       r3, 0x10(r31)
	  lwz       r0, 0x14(r31)
	  stw       r3, 0xD8(r1)
	  stw       r0, 0xDC(r1)
	  lwz       r3, 0x18(r31)
	  lwz       r0, 0x1C(r31)
	  stw       r3, 0xE0(r1)
	  stw       r0, 0xE4(r1)
	  lwz       r3, 0x20(r31)
	  lwz       r0, 0x24(r31)
	  stw       r3, 0xE8(r1)
	  stw       r0, 0xEC(r1)
	  lwz       r3, 0x28(r31)
	  lwz       r0, 0x2C(r31)
	  stw       r3, 0xF0(r1)
	  stw       r0, 0xF4(r1)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x34(r31)
	  stw       r3, 0xF8(r1)
	  stw       r0, 0xFC(r1)
	  lwz       r3, 0x38(r31)
	  lwz       r0, 0x3C(r31)
	  stw       r3, 0x100(r1)
	  stw       r0, 0x104(r1)
	  lwz       r3, 0xD4(r28)
	  lwz       r3, 0x0(r3)
	  bl        -0x4C798
	  addi      r3, r28, 0xC4
	  li        r4, 0
	  bl        -0x52A1C
	  lwz       r3, 0xD4(r28)
	  mr        r4, r25
	  lwz       r5, 0x2E4(r25)
	  addi      r6, r28, 0xC4
	  lwz       r3, 0x0(r3)
	  bl        -0x51664

	.loc_0x1C0:
	  addi      r29, r29, 0xE0
	  addi      r27, r27, 0x1

	.loc_0x1C8:
	  lwz       r0, 0x170(r24)
	  cmpw      r27, r0
	  blt+      .loc_0x30
	  lbz       r0, 0x1B4(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x2E8
	  addi      r3, r24, 0xC4
	  lfs       f1, -0x761C(r2)
	  bl        0x9E048
	  addi      r3, r24, 0xC4
	  bl        0x9E100
	  addi      r3, r26, 0
	  li        r4, 0xB
	  bl        -0x4CB28
	  lfs       f2, -0x60E8(r13)
	  mr        r26, r3
	  lfs       f1, -0x60F4(r13)
	  addi      r6, r1, 0x24
	  lfs       f0, -0x6100(r13)
	  stfs      f2, 0x24(r1)
	  addi      r5, r1, 0x30
	  lfs       f2, -0x60E4(r13)
	  addi      r4, r1, 0x3C
	  stfs      f1, 0x30(r1)
	  lfs       f1, -0x60F0(r13)
	  addi      r3, r1, 0x88
	  stfs      f0, 0x3C(r1)
	  lfs       f0, -0x60FC(r13)
	  stfs      f2, 0x28(r1)
	  lfs       f2, -0x60E0(r13)
	  stfs      f1, 0x34(r1)
	  lfs       f1, -0x60EC(r13)
	  stfs      f0, 0x40(r1)
	  lfs       f0, -0x60F8(r13)
	  stfs      f2, 0x2C(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f0, 0x44(r1)
	  bl        -0x43A7C
	  addi      r3, r26, 0
	  addi      r4, r1, 0x88
	  addi      r5, r1, 0x48
	  bl        -0x43AAC
	  lwz       r3, 0xC0(r24)
	  addi      r4, r25, 0
	  addi      r5, r1, 0x48
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0x4C884
	  lwz       r3, 0xC0(r24)
	  mr        r4, r25
	  lwz       r5, 0x2E4(r25)
	  li        r6, 0
	  lwz       r3, 0x0(r3)
	  bl        -0x51744
	  lfs       f0, -0x60DC(r13)
	  addi      r4, r25, 0
	  addi      r6, r24, 0x1C0
	  stfs      f0, 0x1C0(r24)
	  li        r5, 0x6
	  lfs       f0, -0x60D8(r13)
	  stfs      f0, 0x1C4(r24)
	  lfs       f0, -0x60D4(r13)
	  stfs      f0, 0x1C8(r24)
	  lwz       r3, 0xC0(r24)
	  lwz       r3, 0x0(r3)
	  bl        -0x4C31C
	  lwz       r3, 0x1B8(r24)
	  addi      r4, r24, 0x1C0
	  bl        0x9283C
	  lwz       r3, 0x1BC(r24)
	  addi      r4, r24, 0x1C0
	  bl        0x92830

	.loc_0x2E8:
	  lmw       r24, 0x140(r1)
	  lwz       r0, 0x164(r1)
	  addi      r1, r1, 0x160
	  mtlr      r0
	  blr
	*/
}
