#ifndef _STICKERS_H
#define _STICKERS_H

#include "types.h"
#include "Traversable.h"

/**
 * @brief TODO
 */
struct Stickers : public Traversable {
	Stickers(Creature*);

	virtual Creature* getCreature(int); // _08
	virtual int getFirst();             // _0C
	virtual int getNext(int);           // _10
	virtual bool isDone(int);           // _14

	void calcNum();

	inline bool isEnd(int i)
	{
		if (isDone(i)) {
			return true;
		}
		if (!getCreature(i)) {
			return true;
		}
		return false;
	}

	inline int getCount() { return mCount; }

	// _00     = VTBL
	// _00-_08 = Traversable
	// TODO: members
	int mCount;       // _08
	Creature* mOwner; // _0C
};

#endif
