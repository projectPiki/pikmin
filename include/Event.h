#ifndef _EVENT_H
#define _EVENT_H

#include "types.h"
#include "CoreNode.h"

/**
 * @brief TODO
 */
struct Event {
	// TODO: members
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
