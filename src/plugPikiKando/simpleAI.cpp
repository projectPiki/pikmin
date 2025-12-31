#include "SimpleAI.h"
#include "DebugLog.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(7)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("simpleAI");

/**
 * @todo: Documentation
 */
AICreature::AICreature(CreatureProp* props)
    : Creature(props)
{
	// this is all apparently the ctor of a struct
	mCollidingCreature = 0;
	_2C4.set(0.0f, 0.0f, 0.0f);
	mCurrAnimId = mCounter = 0;
	mCurrentState          = nullptr;
	mCurrentItemHealth     = 0.0f;

	// then this is THIS ctor
	mCurrentState  = nullptr; // hm.
	mMaxEventCount = 16;
	clearEventFlags();
}

/**
 * @todo: Documentation
 */
void AICreature::collisionCallback(immut CollEvent& event)
{
	Creature* collider = event.mCollider;
	MsgCollide msg(event);
	mCollidingCreature = collider;
	if (mStateMachine) {
		static_cast<SimpleAI*>(mStateMachine)->procMsg(this, &msg);
	}
}

/**
 * @todo: Documentation
 */
void AICreature::bounceCallback()
{
	MsgBounce msg(Vector3f(0.0f, 1.0f, 0.0f));
	if (mStateMachine) {
		static_cast<SimpleAI*>(mStateMachine)->procMsg(this, &msg);
	}
}

/**
 * @todo: Documentation
 */
void AICreature::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	(mObjType == OBJTYPE_Goal); // this isn't even in the DLL lol, but it's necessary

	MsgAnim msg(&event);

	if (mStateMachine) {
		static_cast<SimpleAI*>(mStateMachine)->procMsg(this, &msg);
	}

	if (event.mEventType == KEY_PlaySound) {
		playSound(event.mValue);
	}

	if (event.mEventType == KEY_PlayEffect) {
		playEffect(event.mValue);
	}
}

/**
 * @todo: Documentation
 */
void AICreature::clearEventFlags()
{
	for (int i = 0; i < mMaxEventCount; i++) {
		mEventFlags[i] = 0;
	}

	mCurrentEventCount = 0;
}

/**
 * @todo: Documentation
 */
void AICreature::setEventFlag(int flagID, bool value)
{
	if (mCurrentEventCount >= mMaxEventCount) {
		PRINT("############ too many events!\n");
		ERROR("too many events");
		return;
	}

	if (flagID >= mMaxEventCount) {
		ERROR("EVENT %d flag = %s\n", flagID, value ? "true" : "false");
	}
	mEventFlags[flagID] = value;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00000C
 */
bool AICreature::checkEventFlag(int flag)
{
	if (flag == -1) {
		PRINT("##### idx == -1 : checkEventFlag!\n");
		ERROR("checkEventFlg -1");
	}
	return mEventFlags[flag];
}

/**
 * @todo: Documentation
 */
SimpleAI::SimpleAI()
{
}

/**
 * @todo: Documentation
 */
void SimpleAI::procMsg(AICreature* creature, Msg* msg)
{
	SAIState* state = static_cast<SAIState*>(creature->getCurrState());

	if (state) {
		state->procMsg(creature, msg);
	} else {
		PRINT("no currState !\n");
	}
}

/**
 * @todo: Documentation
 */
void SimpleAI::addState(int stateID, int motionID, SAIAction* initAction, SAIAction* execAction, SAIAction* cleanupAction)
{
	SAIState* state       = new SAIState(stateID);
	state->mMotionIdx     = motionID;
	state->mInitAction    = initAction;
	state->mExecAction    = execAction;
	state->mCleanupAction = cleanupAction;

	registerState(state);
}

/**
 * @todo: Documentation
 */
SAIArrow* SimpleAI::addArrow(int stateIdId, SAIEvent* event, int nextStateId)
{
	SAIArrow* arrow = new SAIArrow(event, nextStateId);
	int stateIdx    = mStateIndexes[stateIdId];
	if (stateIdx == -1) {
		PRINT("addArrow(%d,%x,%d) : ILLEGAL STATE %d\n", stateIdId, event, nextStateId, stateIdx);
		return nullptr;
	}

	SAIState* state  = getState(stateIdx);
	arrow->mArrowIdx = state->mArrowCount;
	state->mRootArrow.add(arrow);
	state->mArrowCount++;
	return arrow;
}

/**
 * @todo: Documentation
 */
void SimpleAI::start(AICreature* creature, int stateID)
{
	transit(creature, stateID);
}

/**
 * @todo: Documentation
 */
void SimpleAI::exec(AICreature* creature)
{
	SAIState* state = static_cast<SAIState*>(creature->getCurrState());
	if (state) {
		checkEvent(creature);
		state->exec(creature);
	}
}

/**
 * @todo: Documentation
 */
void SimpleAI::checkEvent(AICreature* creature)
{
	SAIState* currState = static_cast<SAIState*>(creature->getCurrState());
	if (!currState) {
		return;
	}

	FOREACH_NODE(SAIArrow, currState->mRootArrow.mChild, arrow)
	{
		arrow->setEventContext();
		if (arrow->mEvent && !arrow->mEvent->satisfy(creature)) {
			continue;
		}

		bool condCheck = true;
		FOREACH_NODE(SAICondition, arrow->mCondition.mChild, cond)
		{
			if (!cond->satisfy(creature)) {
				condCheck = false;
				break;
			}
		}

		if (condCheck) {
			transit(creature, arrow->mNextStateID);
			return;
		}
	}
}

/**
 * @todo: Documentation
 */
SAIState::SAIState(int stateID)
    : AState<AICreature>(stateID)
{
	mRootArrow.mCondition.initCore("saiCondition");
	mMotionIdx     = PANI_NO_MOTION;
	mCleanupAction = nullptr;
	mExecAction    = nullptr;
	mInitAction    = nullptr;
	mRootArrow.initCore("rootArrow");
	mArrowCount = 0;
}

/**
 * @todo: Documentation
 */
void SAIState::init(AICreature* creature)
{
	if (mMotionIdx != PANI_NO_MOTION) {
		creature->startMotion(mMotionIdx);
	}

	if (mInitAction) {
		mInitAction->act(creature);
	}

	creature->clearEventFlags();
}

/**
 * @todo: Documentation
 */
void SAIState::exec(AICreature* creature)
{
	if (mExecAction) {
		mExecAction->act(creature);
	}

	creature->clearEventFlags();
}

/**
 * @todo: Documentation
 */
void SAIState::procMsg(AICreature* creature, Msg* msg)
{
	FOREACH_NODE(SAIArrow, mRootArrow.mChild, arrow)
	{
		arrow->setEventContext();
		if (arrow->mEvent) {
			arrow->mEvent->procMsg(creature, msg);
		}
	}

	static_cast<SimpleAI*>(mStateMachine)->checkEvent(creature);
}

/**
 * @todo: Documentation
 */
void SAIState::cleanup(AICreature* creature)
{
	if (mCleanupAction) {
		mCleanupAction->act(creature);
	}
}
