#ifndef _COMPLEXCREATURE_H
#define _COMPLEXCREATURE_H

#include "types.h"

struct Creature;
struct CreatureProp;

/**
 * @brief TODO
 *
 * @note Mostly stripped, but necessary. This is the complete set of inlines from the DLL.
 */
template <typename T>
struct SmartPtr {
	SmartPtr() { mPtr = nullptr; }

	void set(T* creature)
	{
		if (mPtr) {
			reset();
		}
		mPtr = creature;
		if (mPtr) {
			mPtr->addCnt();
		}
	}

	void reset()
	{
		if (mPtr) {
			mPtr->subCnt();
			mPtr = nullptr;
		}
	}

	T* getPtr() { return mPtr; }

	bool isNull() { return mPtr == nullptr; }

	void clear() { mPtr = nullptr; }

	T* mPtr; // _00
};

/**
 * @brief TODO
 *
 * @note Completely stripped, only created to generate weak functions in complexCreature.cpp.
 */
struct ComplexCreature {
	ComplexCreature(int, CreatureProp*);

	void join(Creature*);
	void leave(Creature*);
	void cleanup();
	void update();
	void doAI();
	void postUpdate(int, f32);

	// just here to spawn the right weak functions, who knows what this actually was lol
	SmartPtr<Creature> mCreatures[3]; // _00
};

#endif
