#ifndef _SAIEVENT_H
#define _SAIEVENT_H

#include "AICreature.h"
#include "StateMachine.h"

/**
 * @brief TODO
 */
class SAIAction {
public:
	virtual void act(AICreature*) = 0; // _08

	// _00 = VTBL?
	// TODO: members
};

/**
 * @brief TODO
 */
class SAICondition : public CoreNode {
public:
	inline SAICondition()
	    : CoreNode()
	{
	}

	virtual bool satisfy(AICreature*) { return true; } // _10 (weak)

	// _00     = VTBL
	// _00-_14 = CoreNode
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
class SAIEvent : public Receiver<AICreature> {
public:
	SAIEvent()
	    : mEventID(-1)
	{
	}

	void setFlag(AICreature* creature, bool value) { creature->setEventFlag(mEventID, value); }
	void setContext(int eventID) { mEventID = eventID; }

	// TODO: these are DLL inlines, need to make them
	bool satisfy(AICreature* creature) { return creature->checkEventFlag(mEventID); }
	void reset();

	// _00 = VTBL
	int mEventID; // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
class SAIBounceEvent : public SAIEvent {
public:
	virtual void procBounceMsg(AICreature*, MsgBounce*); // _0C

	// _00     = VTBL
	// _00-_08 = SAIEvent
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
class SAICollideEvent : public SAIEvent {
public:
	virtual void procCollideMsg(AICreature*, MsgCollide*); // _1C

	// _00     = VTBL
	// _00-_08 = SAIEvent
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
class SAIGroundEvent : public SAIEvent {
public:
	virtual void procGroundMsg(AICreature*, MsgGround*); // _34

	// _00     = VTBL
	// _00-_08 = SAIEvent
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
class SAIMotionAction0Event : public SAIEvent {
public:
	virtual void procAnimMsg(AICreature*, MsgAnim*); // _20

	// _00     = VTBL
	// _00-_08 = SAIEvent
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
class SAIMotionDoneEvent : public SAIEvent {
public:
	virtual void procAnimMsg(AICreature*, MsgAnim*); // _20

	// _00     = VTBL
	// _00-_08 = SAIEvent
};

/**
 * @brief TODO
 */
class SAIMotionLoopStartEvent : public SAIEvent {
public:
	virtual void procAnimMsg(AICreature*, MsgAnim*); // _20

	// _00     = VTBL
	// _00-_08 = SAIEvent
	// TODO: members
};

/**
 * @brief TODO
 */
class SAIMotionLoopEndEvent : public SAIEvent {
public:
	virtual void procAnimMsg(AICreature*, MsgAnim*); // _20

	// _00     = VTBL
	// _00-_08 = SAIEvent
	// TODO: members
};

/**
 * @brief TODO
 */
struct SAIUserEvent : public SAIEvent {
	SAIUserEvent(int id) { mUserID = id; }

	virtual void procUserMsg(AICreature*, MsgUser*); // _30

	// _00     = VTBL
	// _00-_08 = SAIEvent
	int mUserID; // _08
};

/**
 * @brief TODO
 */
class SAIArrow : public CoreNode {
public:
	SAIArrow(SAIEvent* event, int nextState)
	    : CoreNode("SAIArrow")
	{
		mEvent       = event;
		mNextStateID = nextState;
	}

	SAIArrow()
	    : CoreNode("SAIArrowRoot")
	{
		mNextStateID = -1;
		mEvent       = nullptr;
	}

	SAIArrow* addCondition(SAICondition* cond)
	{
		mCondition.add(cond);
		return this;
	}

	void setEventContext()
	{
		if (mEvent) {
			mEvent->setContext(mArrowIdx);
		}
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mNextStateID;        // _14
	SAIEvent* mEvent;        // _18
	int mArrowIdx;           // _1C
	SAICondition mCondition; // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct SAIState : public AState<AICreature> {
	SAIState(int);

	virtual void procMsg(AICreature*, Msg*); // _08
	virtual void exec(AICreature*);          // _3C
	virtual void init(AICreature*);          // _38
	virtual void cleanup(AICreature*);       // _40

	// _00     = VTBL
	// _00-_10 = AState
	SAIArrow mRootArrow;       // _10
	int mArrowCount;           // _44
	int mMotionIdx;            // _48
	SAIAction* mInitAction;    // _4C, action to perform on state init
	SAIAction* mExecAction;    // _50, action to perform on state exec
	SAIAction* mCleanupAction; // _54, action to perform on state exit
};

// Global functions and objects
void SAIEventInit();

extern SAIMotionDoneEvent* saiMotionDoneEvent;
extern SAIBounceEvent* saiBounceEvent;
extern SAIMotionLoopStartEvent* saiMotionLoopStartEvent;
extern SAIMotionLoopEndEvent* saiMotionLoopEndEvent;
extern SAICollideEvent* saiCollideEvent;
extern SAIGroundEvent* saiGroundEvent;
extern SAIMotionAction0Event* saiMotionAction0Event;

#endif
