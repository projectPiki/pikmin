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

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("saiEvent");

void SAIEventInit()
{
	saiMotionDoneEvent    = new SAIMotionDoneEvent;
	saiBounceEvent        = new SAIBounceEvent;
	saiCollideEvent       = new SAICollideEvent;
	saiGroundEvent        = new SAIGroundEvent;
	saiMotionAction0Event = new SAIMotionAction0Event;
}

void SAIMotionDoneEvent::procAnimMsg(AICreature* creature, MsgAnim* msg)
{
	setFlag(creature, msg->mKeyEvent->mEventType == KEY_Finished);
}

void SAIMotionAction0Event::procAnimMsg(AICreature* creature, MsgAnim* msg)
{
	setFlag(creature, msg->mKeyEvent->mEventType == KEY_Action0);
}

void SAIMotionLoopStartEvent::procAnimMsg(AICreature* creature, MsgAnim* msg)
{
	setFlag(creature, msg->mKeyEvent->mEventType == KEY_LoopStart);
}

void SAIMotionLoopEndEvent::procAnimMsg(AICreature* creature, MsgAnim* msg)
{
	setFlag(creature, msg->mKeyEvent->mEventType == KEY_LoopEnd);
}

void SAIBounceEvent::procBounceMsg(AICreature* creature, MsgBounce*)
{
	setFlag(creature, true);
}

void SAICollideEvent::procCollideMsg(AICreature* creature, MsgCollide*)
{
	setFlag(creature, true);
}

void SAIGroundEvent::procGroundMsg(AICreature* creature, MsgGround*)
{
	setFlag(creature, true);
}

void SAIUserEvent::procUserMsg(AICreature* creature, MsgUser* msg)
{
	setFlag(creature, mUserID == msg->mUserID);
}
