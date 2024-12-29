#ifndef _TRAVERSABLE_H
#define _TRAVERSABLE_H

#include "types.h"
#include "Condition.h"

struct Creature;

/**
 * @brief TODO.
 */
struct Traversable {
	inline Traversable()
	    : _04(0)
	{
	}

	virtual Creature* getCreature(int) = 0; // _08
	virtual int getFirst()             = 0; // _0C
	virtual int getNext(int)           = 0; // _10
	virtual bool isDone(int)           = 0; // _14

	inline bool isEnd(int idx)
	{
		if (isDone(idx)) {
			return true;
		}

		if (!getCreature(idx)) {
			return true;
		}

		return false;
	}

	inline Creature* getCreatureCheck(int idx)
	{
		if (idx == -1) {
			return getCreature(0);
		}
		return getCreature(idx);
	}

	static inline void removeIndex(int& idx)
	{
		if (idx >= 0) {
			idx--;
		}
	}

	// _00 = VTBL
	u32 _04; // _04, unknown
};

/**
 * @brief TODO.
 */
struct Iterator {
	Iterator(Traversable* trav, Condition* condition)
	{
		mTrav      = trav;
		mCondition = condition;
	}

	bool isDone()
	{
		if (mTrav->isDone(mIndex)) {
			return true;
		}

		if (!mTrav->getCreature(mIndex)) {
			return true;
		}

		return false;
	}

	Creature* getCreature()
	{
		if (mIndex == -1) {
			return mTrav->getCreature(0);
		}

		return mTrav->getCreature(mIndex);
	}

	void removeFromSearch()
	{
		if (mIndex >= 0) {
			mIndex--;
		}
	}

	void first()
	{
		if (mCondition) {
			mIndex = mTrav->getFirst();
			while (!isDone()) {
				if (mCondition->satisfy(mTrav->getCreature(mIndex))) {
					break;
				}
				mIndex = mTrav->getNext(mIndex);
			}
			return;
		}

		mIndex = mTrav->getFirst();
	}

	void next()
	{
		if (mCondition) {
			mIndex = mTrav->getNext(mIndex);
			while (!isDone()) {
				if (mCondition->satisfy(mTrav->getCreature(mIndex))) {
					break;
				}
				mIndex = mTrav->getNext(mIndex);
			}
			return;
		}

		mIndex = mTrav->getNext(mIndex);
	}

	int mIndex;            // _00
	Traversable* mTrav;    // _04
	Condition* mCondition; // _08
};

#define CREATURE_ITERATOR(trav, idxname) for (int idxname = (trav)->getFirst(); !(trav)->isEnd(idxname); idxname = (trav)->getNext(idxname))

#define CI_LOOP(iter) for (iter.first(); !iter.isDone(); iter.next())

#endif
