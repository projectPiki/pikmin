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

	inline void init()
	{
		_08 = 0;
		_04 = 12800.0f;
	}

	SmartPtr<Creature> _00; // _00
	f32 _04;                // _04
	u32 _08;                // _08, unknown
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
	void getIndex(Creature*);
	void reset();
	void update();

	// _00     = VTBL
	// _00-_08 = Traversable
	u8 _08[0x8];     // _08, unknown
	u32 _10;         // _10, unknown
	SearchData* _14; // _14, unknown
	s16 _18;         // _18
	s16 _1A;         // _1A
	u8 _1C[0x4];     // _1C, unknown
	u32 _20;         // _20, unknown
	u8 _24;          // _24
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
