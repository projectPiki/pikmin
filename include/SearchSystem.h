#ifndef _SEARCHSYSTEM_H
#define _SEARCHSYSTEM_H

#include "types.h"
#include "Traversable.h"

struct Creature;

/**
 * @brief TODO
 */
struct SearchData {
	SearchData();

	Creature* _00; // _00
	f32 _04;       // _04
	u32 _08;       // _08, unknown
};

/**
 * @brief TODO
 */
struct SearchBuffer : public Traversable {
	SearchBuffer();

	virtual Creature* getCreature(int); // _08
	virtual int getFirst();             // _0C
	virtual int getNext(int);           // _10
	virtual bool isDone(int);           // _14

	void init(SearchData*, int);
	void clear();
	void invalidate();
	void insertQuick(Creature*, f32);
	void insert(Creature*, f32);

	// unused/inlined:
	void operator=(SearchBuffer&);
	void getIndex(Creature*);
	void reset();
	void update();

	// _00     = VTBL
	// _00-_08 = Traversable
	// TODO: members
};

/**
 * @brief TODO
 */
struct SearchSystem {
	SearchSystem();

	void update();
	void updateLoopOptimised();

	// TODO: members
};

#endif
