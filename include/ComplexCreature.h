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
	SmartPtr(); // should be weak

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

	// TODO: members
};

#endif
