#ifndef _PEVE_EVENT_H
#define _PEVE_EVENT_H

#include "Peve/Condition.h"
#include "nlib/Node.h"
#include "types.h"

/**
 * @brief TODO
 */
struct PeveEvent : public NNode {
	PeveEvent(int);

	virtual void reset() // _20 (weak)
	{
		if (mCondition) {
			mCondition->reset();
		}
	}
	virtual void update() // _24 (weak)
	{
		if (mCondition) {
			mCondition->update();
		}
	}
	virtual bool isFinished() // _28 (weak)
	{
		if (!mCondition) {
			return true;
		}

		return mCondition->isMet();
	}
	virtual void finish() { }            // _2C (weak)
	virtual void setEventOption(int opt) // _30
	{
		mEventOptions |= opt;
	}
	virtual void clearEventOption(int opt) // _34
	{
		mEventOptions &= ~opt;
	}
	virtual void setEventOptions(int opts) // _38
	{
		mEventOptions = opts;
	}

	// DLL inlines to do:
	PeveEvent* getEvent(int idx) { return (PeveEvent*)getChild(idx); }
	void makeEvent(PeveCondition* condition) { mCondition = condition; }

	// _00     = VTBL
	// _00-_08 = NNode
	PeveCondition* mCondition; // _08
	int mEventOptions;         // _0C, bitflag
};

/**
 * @brief TODO
 */
struct PeveParallelEvent : public PeveEvent {
	PeveParallelEvent(int count); // unused/inlined

	virtual void reset();      // _20
	virtual void update();     // _24
	virtual bool isFinished(); // _28

	// _00     = VTBL
	// _00-_10 = PeveEvent
	// TODO: members
};

/**
 * @brief TODO
 */
struct PeveSerialEvent : public PeveEvent {
	PeveSerialEvent(int count); // unused/inlined

	virtual void reset();      // _20
	virtual void update();     // _24
	virtual bool isFinished(); // _28

	// DLL inlines:
	PeveEvent* getCurrentEvent() { return getEvent(mEventIdx); }

	// _00     = VTBL
	// _00-_10 = PeveEvent
	int mEventIdx; // _10
};

#endif
