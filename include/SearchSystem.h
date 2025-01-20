#ifndef _SEARCHSYSTEM_H
#define _SEARCHSYSTEM_H

#include "types.h"
#include "Traversable.h"
#include "ComplexCreature.h"

struct Creature;

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct SearchData {
	SearchData();

	SmartPtr<Creature> mPtr; // _00
	f32 _04;                 // _04
	int _08;                 // _08, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
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
	int getIndex(Creature*);
	void reset();
	void update();

	// _00     = VTBL
	// _00-_08 = Traversable
	f32 mMaxDistance;      // _08
	int mLastEntry;        // _0C
	u32 _10;               // _10, unused
	SearchData* mDataList; // _14
	s16 mCurrentEntries;   // _18
	s16 mMaxEntries;       // _1A
	s16 _1C;               // _1C, unused
	u32 _20;               // _20, unused
	u8 _24;                // _24, unused
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
