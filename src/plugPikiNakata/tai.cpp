#include "DebugLog.h"
#include "TAI/Action.h"
#include "sysNew.h"
#include "teki.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000098
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("tai");

/**
 * @TODO: Documentation
 */
TaiSerialAction::TaiSerialAction(int nextState, int count)
    : TaiAction(nextState)
    , mCount(count)
{
	mActionQueue = new TaiAction*[mCount];
}

/**
 * @TODO: Documentation
 */
void TaiSerialAction::start(Teki& teki)
{
	teki.mCurrentQueueId = 0;
	mActionQueue[teki.mCurrentQueueId]->start(teki);
}

/**
 * @TODO: Documentation
 */
void TaiSerialAction::finish(Teki& teki)
{
	for (int i = 0; i < mCount; i++) {
		TaiAction* action = mActionQueue[i];
		action->finish(teki);
	}
}

/**
 * @TODO: Documentation
 */
bool TaiSerialAction::act(Teki& teki)
{
	if (mActionQueue[teki.mCurrentQueueId]->act(teki)) {
		if (teki.mCurrentQueueId == mCount - 1) {
			return true;
		}
		teki.mCurrentQueueId++;
		mActionQueue[teki.mCurrentQueueId]->start(teki);
	}

	return false;
}

/**
 * @TODO: Documentation
 */
bool TaiSerialAction::actByEvent(immut TekiEvent& event)
{
	Teki* teki = event.mTeki;
	if (mActionQueue[teki->mCurrentQueueId]->actByEvent(event)) {
		if (teki->mCurrentQueueId == mCount - 1) {
			return true;
		}
		teki->mCurrentQueueId++;
		mActionQueue[teki->mCurrentQueueId]->start(*event.mTeki);
	}

	return false;
}

/**
 * @TODO: Documentation
 */
TaiState::TaiState(int count)
    : mCount(count)
{
	mActions = new TaiAction*[mCount];
}

/**
 * @TODO: Documentation
 */
void TaiState::start(Teki& teki)
{
	for (int i = 0; i < mCount; i++) {
		TaiAction* action = mActions[i];
		action->start(teki);
	}
}

/**
 * @TODO: Documentation
 */
void TaiState::finish(Teki& teki)
{
	for (int i = 0; i < mCount; i++) {
		TaiAction* action = mActions[i];
		action->finish(teki);
	}
}

/**
 * @TODO: Documentation
 */
bool TaiState::act(Teki& teki)
{
	for (int i = 0; i < mCount; i++) {
		TaiAction* action = mActions[i];
		if (action->act(teki) && action->hasNextState()) {
			PRINT_NAKATA("transit:%08x:i:%d:%d->%d(%d),t:%d,m:%d\n", &teki, i, teki.mStateID, action->mNextState, teki.mReturnStateID,
			             teki.mTekiType, teki.mTekiAnimator->getCurrentMotionIndex());

			volatile int& stateID = teki.mStateID;
			int startVal          = teki.mStateID;
			if (action->mNextState == TAI_RETURN_TRANSIT) {
				stateID = teki.mReturnStateID;
			} else {
				stateID = action->mNextState;
			}
			teki.mReturnStateID = startVal;
			return true;
		}
	}

	return false;
}

/**
 * @TODO: Documentation
 */
bool TaiState::eventPerformed(immut TekiEvent& event)
{
	// NON-MATCHING
	for (int i = 0; i < mCount; i++) {
		TaiAction* action = mActions[i];
		if (action->actByEvent(event) && action->hasNextState()) {
			PRINT_NAKATA("eventPerformed:%08x:i:%d:%d->%d(%d),t:%d,m:%d\n", event.mTeki, i, event.mTeki->mStateID, action->mNextState,
			             event.mTeki->mReturnStateID, event.mTeki->mTekiType, event.mTeki->mTekiAnimator->getCurrentMotionIndex());

			Teki* volatile teki = event.mTeki;
			int startVal        = event.mTeki->mStateID;
			int nextState       = action->mNextState;
			if (nextState == TAI_RETURN_TRANSIT) {
				event.mTeki->mStateID = event.mTeki->mReturnStateID;
			} else {
				event.mTeki->mStateID = nextState;
			}
			event.mTeki->mReturnStateID = startVal;
			return true;
		}
	}

	return false;
}

/**
 * @TODO: Documentation
 */
TaiStrategy::TaiStrategy(int stateCount, int stateID)
{
	init(stateCount, stateID);
}

/**
 * @TODO: Documentation
 */
void TaiStrategy::init(int stateCount, int stateID)
{
	mStateCount = stateCount;
	mStateList  = new TaiState*[mStateCount];
	mStateID    = stateID;
}

/**
 * @TODO: Documentation
 */
void TaiStrategy::start(Teki& teki)
{
	teki.mStateID      = mStateID;
	teki.mIsStateReady = true;
}

/**
 * @TODO: Documentation
 */
void TaiStrategy::act(Teki& teki)
{
	if (teki.mIsStateReady) {
		mStateList[teki.mStateID]->start(teki);
		teki.mIsStateReady = false;
	}

	int stateID = teki.mStateID;
	if (mStateList[teki.mStateID]->act(teki)) {
		mStateList[stateID]->finish(teki);
		teki.mIsStateReady = true;
	}
}

/**
 * @TODO: Documentation
 */
void TaiStrategy::eventPerformed(immut TekiEvent& event)
{
	Teki* teki  = event.mTeki;
	int stateID = teki->mStateID;
	if (mStateList[teki->mStateID]->eventPerformed(event)) {
		mStateList[stateID]->finish(*teki);
		teki->mIsStateReady = true;
	}
}
