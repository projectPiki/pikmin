#include "SimpleAI.h"
#include "DebugLog.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(7)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("simpleAI");

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
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
 * @TODO: Documentation
 */
void AICreature::bounceCallback()
{
	MsgBounce msg(Vector3f(0.0f, 1.0f, 0.0f));
	if (mStateMachine) {
		static_cast<SimpleAI*>(mStateMachine)->procMsg(this, &msg);
	}
}

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
 */
void AICreature::clearEventFlags()
{
	for (int i = 0; i < mMaxEventCount; i++) {
		mEventFlags[i] = 0;
	}

	mCurrentEventCount = 0;
}

/**
 * @TODO: Documentation
 */
void AICreature::setEventFlag(int flagID, bool value)
{
	if (mCurrentEventCount < mMaxEventCount) {
		if (flagID >= mMaxEventCount) {
			ERROR("EVENT %d flag = %s\n", flagID, value ? "true" : "false");
		}
		mEventFlags[flagID] = value;
	} else {
		PRINT("############ too many events!\n");
		ERROR("too many events");
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
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
 * @TODO: Documentation
 */
SimpleAI::SimpleAI()
{
}

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
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
 * @TODO: Documentation
 */
SAIArrow* SimpleAI::addArrow(int p1, SAIEvent* event, int p3)
{
	SAIArrow* arrow = new SAIArrow(event, p3);
	int stateIdx    = mStateIndexes[p1];
	if (stateIdx == -1) {
		PRINT("addArrow(%d,%x,%d) : ILLEGAL STATE %d\n", p1, event, p3, p1);
		return nullptr;
	}

	SAIState* state  = getState(stateIdx);
	arrow->mArrowIdx = state->mArrowCount;
	state->mRootArrow.add(arrow);
	state->mArrowCount++;
	return arrow;
}

/**
 * @TODO: Documentation
 */
void SimpleAI::start(AICreature* creature, int stateID)
{
	transit(creature, stateID);
}

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
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
 * @TODO: Documentation
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
 * @TODO: Documentation
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
 * @TODO: Documentation
 */
void SAIState::exec(AICreature* creature)
{
	if (mExecAction) {
		mExecAction->act(creature);
	}

	creature->clearEventFlags();
}

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
 */
void SAIState::cleanup(AICreature* creature)
{
	if (mCleanupAction) {
		mCleanupAction->act(creature);
	}
}
