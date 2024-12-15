#include "YaiStrategy.h"
#include "teki.h"
#include "TAI/Action.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
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
 * Address:	801E9654
 * Size:	000064
 */
YaiStrategy::YaiStrategy(int stateCount, int stateID) { init(stateCount, stateID); }

/*
 * --INFO--
 * Address:	801E96B8
 * Size:	00004C
 */
void YaiStrategy::init(int stateCount, int stateID)
{
	mStateCount = stateCount;
	mStateList  = new TaiState*[mStateCount]; // TODO: work out type
	mStateID    = stateID;
}

/*
 * --INFO--
 * Address:	801E9704
 * Size:	000044
 */
void YaiStrategy::start(Teki& teki)
{
	teki.mStateID = mStateID;
	mStateList[teki.mStateID]->start(teki);
}

/*
 * --INFO--
 * Address:	801E9748
 * Size:	0000AC
 */
void YaiStrategy::act(Teki& teki)
{
	// what on earth did yamashita do
	int stateID = teki.mStateID;
	if (mStateList[teki.mStateID]->act(teki)) {
		mStateList[stateID]->finish(teki);
		mStateList[teki.mStateID]->start(teki);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  lwz       r0, 0x324(r4)
	  lwz       r3, 0x8(r3)
	  rlwinm    r0,r0,2,0,29
	  lwz       r31, 0x324(r30)
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x90
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r31,2,0,29
	  addi      r4, r30, 0
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x324(r30)
	  mr        r4, r30
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x90:
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
 * Address:	801E97F4
 * Size:	0000AC
 */
void YaiStrategy::eventPerformed(TekiEvent& event)
{
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
	  beq-      .loc_0x90
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r30,2,0,29
	  addi      r4, r31, 0
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x324(r31)
	  mr        r4, r31
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x90:
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
 * Address:	801E98A0
 * Size:	000020
 */
void YaiStrategy::draw(Teki& teki, Graphics& gfx) { TekiStrategy::draw(teki, gfx); }
