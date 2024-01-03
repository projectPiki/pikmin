#include "Event.h"

static char file[] = __FILE__;
static char name[] = "eventListener";

/*
 * --INFO--
 * Address:	80093FA8
 * Size:	000090
 */
EventTalker::EventTalker() { }

/*
 * --INFO--
 * Address:	80094038
 * Size:	00005C
 */
void EventTalker::informEvent(Event& event)
{
	FOREACH_NODE(EventListener, mListener.mChild, listener) { listener->gotEvent(event); }
}
