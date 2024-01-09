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

	virtual Creature* getCreature(int); // _08
	virtual int getFirst();             // _0C
	virtual int getNext(int);           // _10
	virtual bool isDone(int);           // _14

	// _00 = VTBL
	u32 _04; // _04, unknown
};

#endif
