#include "Event.h"
#include "DebugLog.h"

DEFINE_ERROR(__LINE__) // Never used in the DLL

DEFINE_PRINT("eventListener");

/*
 * --INFO--
 * Address:	80093FA8
 * Size:	000090
 */
EventTalker::EventTalker()
{
}

/*
 * --INFO--
 * Address:	80094038
 * Size:	00005C
 */
void EventTalker::informEvent(Event& event)
{
	FOREACH_NODE(EventListener, mListener.mChild, listener)
	{
		listener->gotEvent(event);
	}
}
