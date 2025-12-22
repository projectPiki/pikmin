#include "DebugLog.h"
#include "Dolphin/os.h"
#include "SimpleAI.h"
#include "sysNew.h"

SAIMotionDoneEvent* saiMotionDoneEvent;
SAIBounceEvent* saiBounceEvent;
SAIMotionLoopStartEvent* saiMotionLoopStartEvent;
SAIMotionLoopEndEvent* saiMotionLoopEndEvent;
SAICollideEvent* saiCollideEvent;
SAIGroundEvent* saiGroundEvent;
SAIMotionAction0Event* saiMotionAction0Event;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("saiEvent");

/**
 * @TODO: Documentation
 */
void SAIEventInit()
{
	saiMotionDoneEvent    = new SAIMotionDoneEvent;
	saiBounceEvent        = new SAIBounceEvent;
	saiCollideEvent       = new SAICollideEvent;
	saiGroundEvent        = new SAIGroundEvent;
	saiMotionAction0Event = new SAIMotionAction0Event;
}

/**
 * @TODO: Documentation
 */
void SAIMotionDoneEvent::procAnimMsg(AICreature* creature, MsgAnim* msg)
{
	setFlag(creature, msg->mKeyEvent->mEventType == KEY_Finished);
}

/**
 * @TODO: Documentation
 */
void SAIMotionAction0Event::procAnimMsg(AICreature* creature, MsgAnim* msg)
{
	setFlag(creature, msg->mKeyEvent->mEventType == KEY_Action0);
}

/**
 * @TODO: Documentation
 */
void SAIMotionLoopStartEvent::procAnimMsg(AICreature* creature, MsgAnim* msg)
{
	setFlag(creature, msg->mKeyEvent->mEventType == KEY_LoopStart);
}

/**
 * @TODO: Documentation
 */
void SAIMotionLoopEndEvent::procAnimMsg(AICreature* creature, MsgAnim* msg)
{
	setFlag(creature, msg->mKeyEvent->mEventType == KEY_LoopEnd);
}

/**
 * @TODO: Documentation
 */
void SAIBounceEvent::procBounceMsg(AICreature* creature, MsgBounce*)
{
	setFlag(creature, true);
}

/**
 * @TODO: Documentation
 */
void SAICollideEvent::procCollideMsg(AICreature* creature, MsgCollide*)
{
	setFlag(creature, true);
}

/**
 * @TODO: Documentation
 */
void SAIGroundEvent::procGroundMsg(AICreature* creature, MsgGround*)
{
	setFlag(creature, true);
}

/**
 * @TODO: Documentation
 */
void SAIUserEvent::procUserMsg(AICreature* creature, MsgUser* msg)
{
	setFlag(creature, mUserID == msg->mUserID);
}
