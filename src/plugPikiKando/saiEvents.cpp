#include "SimpleAI.h"
#include "Dolphin/os.h"
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
static void _Error(char* fmt, ...) { OSPanic(__FILE__, __LINE__, fmt, "saiEvent"); }

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007CDFC
 * Size:	00015C
 */
void SAIEventInit()
{
	saiMotionDoneEvent    = new SAIMotionDoneEvent;
	saiBounceEvent        = new SAIBounceEvent;
	saiCollideEvent       = new SAICollideEvent;
	saiGroundEvent        = new SAIGroundEvent;
	saiMotionAction0Event = new SAIMotionAction0Event;
}

/*
 * --INFO--
 * Address:	8007CF58
 * Size:	000040
 */
void SAIMotionDoneEvent::procAnimMsg(AICreature* creature, MsgAnim* msg) { creature->setEventFlag(mEventID, *msg->_04 == 0); }

/*
 * --INFO--
 * Address:	8007CF98
 * Size:	000040
 */
void SAIMotionAction0Event::procAnimMsg(AICreature* creature, MsgAnim* msg) { creature->setEventFlag(mEventID, *msg->_04 == 1); }

/*
 * --INFO--
 * Address:	8007CFD8
 * Size:	000040
 */
void SAIMotionLoopStartEvent::procAnimMsg(AICreature* creature, MsgAnim* msg) { creature->setEventFlag(mEventID, *msg->_04 == 5); }

/*
 * --INFO--
 * Address:	8007D018
 * Size:	000040
 */
void SAIMotionLoopEndEvent::procAnimMsg(AICreature* creature, MsgAnim* msg) { creature->setEventFlag(mEventID, *msg->_04 == 6); }

/*
 * --INFO--
 * Address:	8007D058
 * Size:	000030
 */
void SAIBounceEvent::procBounceMsg(AICreature* creature, MsgBounce*) { creature->setEventFlag(mEventID, true); }

/*
 * --INFO--
 * Address:	8007D088
 * Size:	000030
 */
void SAICollideEvent::procCollideMsg(AICreature* creature, MsgCollide*) { creature->setEventFlag(mEventID, true); }

/*
 * --INFO--
 * Address:	8007D0B8
 * Size:	000030
 */
void SAIGroundEvent::procGroundMsg(AICreature* creature, MsgGround*) { creature->setEventFlag(mEventID, true); }

/*
 * --INFO--
 * Address:	8007D0E8
 * Size:	000040
 */
void SAIUserEvent::procUserMsg(AICreature* creature, MsgUser* msg) { creature->setEventFlag(mEventID, _08 == msg->_04); }
