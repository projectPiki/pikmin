#include "DebugLog.h"
#include "Event.h"

DEFINE_ERROR(__LINE__) // Never used in the DLL

DEFINE_PRINT("eventListener");

/**
 * @todo: Documentation
 */
EventTalker::EventTalker()
{
}

/**
 * @todo: Documentation
 */
void EventTalker::informEvent(Event& event)
{
	FOREACH_NODE(EventListener, mListener.mChild, listener)
	{
		listener->gotEvent(event);
	}
}
