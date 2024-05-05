#include "TaiAction.h"
#include "teki.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80126E04
 * Size:	00005C
 */
TaiSerialAction::TaiSerialAction(int nextState, int count)
    : TaiAction(nextState)
    , mCount(count)
{
	mActionQueue = new TaiAction*[mCount];
}

/*
 * --INFO--
 * Address:	80126E60
 * Size:	000044
 */
void TaiSerialAction::start(Teki& teki)
{
	teki._334 = 0;
	mActionQueue[teki._334]->start(teki);
}

/*
 * --INFO--
 * Address:	80126EA8
 * Size:	000080
 */
void TaiSerialAction::finish(Teki& teki)
{
	for (int i = 0; i < mCount; i++) {
		mActionQueue[i]->finish(teki);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  b         .loc_0x54

	.loc_0x30:
	  lwz       r3, 0xC(r28)
	  mr        r4, r29
	  lwzx      r3, r3, r31
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x54:
	  lwz       r0, 0x8(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x30
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
 * Address:	80126F2C
 * Size:	0000A8
 */
bool TaiSerialAction::act(Teki& teki)
{
	if (mActionQueue[teki._334]->act(teki)) {
		if (teki._334 == mCount - 1) {
			return true;
		}
		teki._334++;
		mActionQueue[teki._334]->start(teki);
	}

	return false;
}

/*
 * --INFO--
 * Address:	80126FDC
 * Size:	0000B4
 */
bool TaiSerialAction::actByEvent(TekiEvent& event)
{
	Teki* teki = event.mTeki;
	if (mActionQueue[teki->_334]->actByEvent(event)) {
		if (teki->_334 == mCount - 1) {
			return true;
		}
		teki->_334++;
		mActionQueue[teki->_334]->start(*event.mTeki);
	}

	return false;
}

/*
 * --INFO--
 * Address:	80127098
 * Size:	00004C
 */
TaiState::TaiState(int count)
    : mCount(count)
{
	mActions = new TaiAction*[mCount];
}

/*
 * --INFO--
 * Address:	801270E4
 * Size:	000080
 */
void TaiState::start(Teki& teki)
{
	for (int i = 0; i < mCount; i++) {
		mActions[i]->start(teki);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  b         .loc_0x54

	.loc_0x30:
	  lwz       r3, 0x8(r28)
	  mr        r4, r29
	  lwzx      r3, r3, r31
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x54:
	  lwz       r0, 0x4(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x30
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
 * Address:	80127164
 * Size:	000080
 */
void TaiState::finish(Teki& teki)
{
	for (int i = 0; i < mCount; i++) {
		mActions[i]->finish(teki);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  b         .loc_0x54

	.loc_0x30:
	  lwz       r3, 0x8(r28)
	  mr        r4, r29
	  lwzx      r3, r3, r31
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x54:
	  lwz       r0, 0x4(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x30
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
 * Address:	801271E4
 * Size:	0000EC
 */
bool TaiState::act(Teki& teki)
{
	for (int i = 0; i < mCount; i++) {
		TaiAction* action = mActions[i];
		if (action->act(teki) && action->hasNextState()) {
			// something teki-related here
			teki._334 = 0;
			return true;
		}
	}

	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  li        r31, 0
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  stw       r28, 0x28(r1)
	  addi      r28, r3, 0
	  stw       r4, 0xC(r1)
	  lwz       r30, 0xC(r1)
	  stw       r31, 0x20(r1)
	  b         .loc_0xB8

	.loc_0x34:
	  lwz       r3, 0x8(r28)
	  mr        r4, r30
	  lwzx      r29, r3, r31
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA8
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA8
	  lwz       r0, 0x0(r29)
	  addi      r3, r30, 0x324
	  lwz       r4, 0x324(r30)
	  cmpwi     r0, -0x2
	  bne-      .loc_0x98
	  lwz       r0, 0x330(r30)
	  stw       r0, 0x0(r3)
	  b         .loc_0x9C

	.loc_0x98:
	  stw       r0, 0x0(r3)

	.loc_0x9C:
	  stw       r4, 0x330(r30)
	  li        r3, 0x1
	  b         .loc_0xCC

	.loc_0xA8:
	  lwz       r3, 0x20(r1)
	  addi      r31, r31, 0x4
	  addi      r0, r3, 0x1
	  stw       r0, 0x20(r1)

	.loc_0xB8:
	  lwz       r3, 0x20(r1)
	  lwz       r0, 0x4(r28)
	  cmpw      r3, r0
	  blt+      .loc_0x34
	  li        r3, 0

	.loc_0xCC:
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
 * Address:	801272F0
 * Size:	0000F4
 */
bool TaiState::eventPerformed(TekiEvent& event)
{
	for (int i = 0; i < mCount; i++) {
		TaiAction* action = mActions[i];
		if (action->actByEvent(event) && action->hasNextState()) {
			// some teki-related thing
			event.mTeki->_334 = 0;
			return true;
		}
	}

	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  li        r31, 0
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x28(r1)
	  addi      r28, r3, 0
	  stw       r31, 0x24(r1)
	  b         .loc_0xC0

	.loc_0x30:
	  lwz       r3, 0x8(r28)
	  mr        r4, r29
	  lwzx      r30, r3, r31
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB0
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB0
	  lwz       r3, 0x4(r29)
	  stw       r3, 0x20(r1)
	  addi      r4, r3, 0x324
	  lwz       r0, 0x0(r30)
	  lwz       r5, 0x324(r3)
	  cmpwi     r0, -0x2
	  bne-      .loc_0x9C
	  lwz       r0, 0x330(r3)
	  stw       r0, 0x0(r4)
	  b         .loc_0xA0

	.loc_0x9C:
	  stw       r0, 0x0(r4)

	.loc_0xA0:
	  lwz       r4, 0x4(r29)
	  li        r3, 0x1
	  stw       r5, 0x330(r4)
	  b         .loc_0xD4

	.loc_0xB0:
	  lwz       r3, 0x24(r1)
	  addi      r31, r31, 0x4
	  addi      r0, r3, 0x1
	  stw       r0, 0x24(r1)

	.loc_0xC0:
	  lwz       r3, 0x24(r1)
	  lwz       r0, 0x4(r28)
	  cmpw      r3, r0
	  blt+      .loc_0x30
	  li        r3, 0

	.loc_0xD4:
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
 * Address:	801273E4
 * Size:	000064
 */
TaiStrategy::TaiStrategy(int p1, int p2) { init(p1, p2); }

/*
 * --INFO--
 * Address:	80127448
 * Size:	00004C
 */
void TaiStrategy::init(int count, int p2)
{
	mCount  = count;
	mStates = new TaiState*[mCount];
	_0C     = p2;
}

/*
 * --INFO--
 * Address:	80127494
 * Size:	000014
 */
void TaiStrategy::start(Teki& teki)
{
	teki._324 = _0C;
	teki._328 = true;
}

/*
 * --INFO--
 * Address:	801274A8
 * Size:	0000CC
 */
void TaiStrategy::act(Teki& teki)
{
	if (teki._328) {
		mStates[teki._324]->start(teki);
		teki._328 = false;
	}

	int stateID = teki._324;
	if (mStates[teki._324]->act(teki)) {
		mStates[stateID]->finish(teki);
		teki._328 = true;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  lbz       r0, 0x328(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x58
	  lwz       r0, 0x324(r30)
	  mr        r4, r30
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stb       r0, 0x328(r30)

	.loc_0x58:
	  lwz       r0, 0x324(r30)
	  mr        r4, r30
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwz       r31, 0x324(r30)
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r31,2,0,29
	  addi      r4, r30, 0
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x1
	  stb       r0, 0x328(r30)

	.loc_0xB0:
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
 * Address:	80127574
 * Size:	000090
 */
void TaiStrategy::eventPerformed(TekiEvent& event)
{
	Teki* teki  = event.mTeki;
	int stateID = teki->_324;
	if (mStates[teki->_324]->eventPerformed(event)) {
		mStates[stateID]->finish(*teki);
		teki->_328 = true;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r31, 0x4(r4)
	  lwz       r3, 0x8(r3)
	  lwz       r0, 0x324(r31)
	  lwz       r30, 0x324(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r30,2,0,29
	  addi      r4, r31, 0
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x1
	  stb       r0, 0x328(r31)

	.loc_0x74:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
