#include "DebugLog.h"
#include "Event.h"

DEFINE_ERROR(__LINE__) // Never used in the DLL

DEFINE_PRINT("eventListener");

EventTalker::EventTalker()
{
}

void EventTalker::informEvent(Event& event)
{
	FOREACH_NODE(EventListener, mListener.mChild, listener)
	{
		listener->gotEvent(event);
	}
}
