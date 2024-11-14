#ifndef _TRAVERSABLE_H
#define _TRAVERSABLE_H

#include "types.h"

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

		if (getCreature(idx) == nullptr) {
			return true;
		}

		return false;
	}

	inline Creature* getCreatureCheck(int idx) { return (idx == -1) ? getCreature(0) : getCreature(idx); }

	// _00 = VTBL
	u32 _04; // _04, unknown
};

#define TRAVERSELOOP(trav, idxname) for (int idxname = trav->getFirst(); !trav->isEnd(idxname); idxname = trav->getNext(idxname))

#endif
