#include "YaiStrategy.h"
#include "teki.h"
#include "TAI/Action.h"
#include "sysNew.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	801E9654
 * Size:	000064
 */
YaiStrategy::YaiStrategy(int stateCount, int stateID)
{
	init(stateCount, stateID);
}

/*
 * --INFO--
 * Address:	801E96B8
 * Size:	00004C
 */
void YaiStrategy::init(int stateCount, int stateID)
{
	mStateCount = stateCount;
	mStateList  = new TaiState*[mStateCount];
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
	int startState = teki.mStateID;
	if (mStateList[teki.mStateID]->act(teki)) {
		mStateList[startState]->finish(teki);
		mStateList[teki.mStateID]->start(teki);
	}
}

/*
 * --INFO--
 * Address:	801E97F4
 * Size:	0000AC
 */
void YaiStrategy::eventPerformed(TekiEvent& event)
{
	Teki* teki     = event.mTeki;
	int startState = teki->mStateID;
	if (mStateList[teki->mStateID]->eventPerformed(event)) {
		mStateList[startState]->finish(*teki);
		mStateList[teki->mStateID]->start(*teki);
	}
}

/*
 * --INFO--
 * Address:	801E98A0
 * Size:	000020
 */
void YaiStrategy::draw(Teki& teki, Graphics& gfx)
{
	TekiStrategy::draw(teki, gfx);
}
