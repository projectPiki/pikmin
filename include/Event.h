#ifndef _EVENT_H
#define _EVENT_H

#include "CoreNode.h"
#include "types.h"

/**
 * @brief TODO
 */
struct Event {
	Event(int p1, u32 id)
	{
		_UNUSED00 = p1;
		mId       = id;
	}

	int _UNUSED00; // _00
	u32 mId;       // _04
};

/**
 * @brief TODO
 */
struct EventListener : public CoreNode {
	inline EventListener()
	{
		mParent = mNext = mChild = nullptr;
		mName                    = "eventListeners";
	}

	virtual void gotEvent(Event&) { } // _10 (weak)

	// _00     = VTBL
	// _00-_14 = CoreNode
};

/**
 * @brief TODO
 */
struct EventTalker {
	EventTalker();

	void informEvent(Event&);

	EventListener mListener; // _00
};

#endif
