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

/*
 * --INFO--
 * Address:	8007D26C
 * Size:	0000A4
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

/*
 * --INFO--
 * Address:	8007D310
 * Size:	00006C
 */
void AICreature::collisionCallback(CollEvent& event)
{
	Creature* collider = event.mCollider;
	MsgCollide msg(event);
	mCollidingCreature = collider;
	if (mStateMachine) {
		static_cast<SimpleAI*>(mStateMachine)->procMsg(this, &msg);
	}
}

/*
 * --INFO--
 * Address:	8007D37C
 * Size:	000060
 */
void AICreature::bounceCallback()
{
	MsgBounce msg(Vector3f(0.0f, 1.0f, 0.0f));
	if (mStateMachine) {
		static_cast<SimpleAI*>(mStateMachine)->procMsg(this, &msg);
	}
}

/*
 * --INFO--
 * Address:	8007D3DC
 * Size:	0000B4
 */
void AICreature::animationKeyUpdated(PaniAnimKeyEvent& event)
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

/*
 * --INFO--
 * Address:	8007D498
 * Size:	000030
 */
void AICreature::clearEventFlags()
{
	for (int i = 0; i < mMaxEventCount; i++) {
		mEventFlags[i] = 0;
	}

	mCurrentEventCount = 0;
}

/*
 * --INFO--
 * Address:	8007D4C8
 * Size:	00001C
 */
void AICreature::setEventFlag(int flagID, bool value)
{
	if (mCurrentEventCount < mMaxEventCount) {
		if (flagID >= mMaxEventCount) {
			if (value) {
				ERROR("EVENT %d flag = %s\n", flagID, true);
			} else {
				ERROR("EVENT %d flag = %s\n", flagID, false);
			}
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

/*
 * --INFO--
 * Address:	8007D4E4
 * Size:	000024
 */
SimpleAI::SimpleAI()
{
}

/*
 * --INFO--
 * Address:	8007D508
 * Size:	000068
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

/*
 * --INFO--
 * Address:	8007D578
 * Size:	0000E8
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

/*
 * --INFO--
 * Address:	8007D660
 * Size:	0000F8
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

/*
 * --INFO--
 * Address:	8007D758
 * Size:	00002C
 */
void SimpleAI::start(AICreature* creature, int stateID)
{
	transit(creature, stateID);
}

/*
 * --INFO--
 * Address:	8007D86C
 * Size:	00007C
 */
void SimpleAI::exec(AICreature* creature)
{
	SAIState* state = static_cast<SAIState*>(creature->getCurrState());
	if (state) {
		checkEvent(creature);
		state->exec(creature);
	}
}

/*
 * --INFO--
 * Address:	8007D8E8
 * Size:	0000F8
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

/*
 * --INFO--
 * Address:	8007D9E8
 * Size:	00010C
 */
SAIState::SAIState(int stateID)
    : AState<AICreature>(stateID)
{
	mRootArrow.mCondition.initCore("saiCondition");
	mMotionIdx     = -1;
	mCleanupAction = nullptr;
	mExecAction    = nullptr;
	mInitAction    = nullptr;
	mRootArrow.initCore("rootArrow");
	mArrowCount = 0;
}

/*
 * --INFO--
 * Address:	8007DAF4
 * Size:	0000A4
 */
void SAIState::init(AICreature* creature)
{
	if (mMotionIdx != -1) {
		creature->startMotion(mMotionIdx);
	}

	if (mInitAction) {
		mInitAction->act(creature);
	}

	creature->clearEventFlags();
}

/*
 * --INFO--
 * Address:	8007DB9C
 * Size:	000074
 */
void SAIState::exec(AICreature* creature)
{
	if (mExecAction) {
		mExecAction->act(creature);
	}

	creature->clearEventFlags();
}

/*
 * --INFO--
 * Address:	8007DC10
 * Size:	0000A0
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

/*
 * --INFO--
 * Address:	8007DCB0
 * Size:	000038
 */
void SAIState::cleanup(AICreature* creature)
{
	if (mCleanupAction) {
		mCleanupAction->act(creature);
	}
}
