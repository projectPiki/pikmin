#include "DebugLog.h"
#include "TAI/Action.h"
#include "YaiStrategy.h"
#include "sysNew.h"
#include "teki.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @TODO: Documentation
 */
YaiStrategy::YaiStrategy(int stateCount, int stateID)
{
	init(stateCount, stateID);
}

/**
 * @TODO: Documentation
 */
void YaiStrategy::init(int stateCount, int stateID)
{
	mStateCount = stateCount;
	mStateList  = new TaiState*[mStateCount];
	mStateID    = stateID;
}

/**
 * @TODO: Documentation
 */
void YaiStrategy::start(Teki& teki)
{
	teki.mStateID = mStateID;
	mStateList[teki.mStateID]->start(teki);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void YaiStrategy::eventPerformed(immut TekiEvent& event)
{
	Teki* teki     = event.mTeki;
	int startState = teki->mStateID;
	if (mStateList[teki->mStateID]->eventPerformed(event)) {
		mStateList[startState]->finish(*teki);
		mStateList[teki->mStateID]->start(*teki);
	}
}

/**
 * @TODO: Documentation
 */
void YaiStrategy::draw(Teki& teki, Graphics& gfx)
{
	TekiStrategy::draw(teki, gfx);
}
