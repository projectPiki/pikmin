#include "DebugLog.h"
#include "Event.h"

DEFINE_ERROR(__LINE__) // Never used in the DLL

DEFINE_PRINT("eventListener");

/**
 * @TODO: Documentation
 */
EventTalker::EventTalker()
{
}

/**
 * @TODO: Documentation
 */
void EventTalker::informEvent(Event& event)
{
	FOREACH_NODE(EventListener, mListener.mChild, listener)
	{
		listener->gotEvent(event);
	}
}
