#ifndef _COMPLEXCREATURE_H
#define _COMPLEXCREATURE_H

#include "types.h"
#include "Creature.h"

/**
 * @brief TODO
 *
 * @note Mostly stripped, very few references left. Necessary for complexCreature.cpp though.
 */
template <typename T>
struct SmartPtr {
	SmartPtr() { mPtr = nullptr; }

	void set(T*);

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
