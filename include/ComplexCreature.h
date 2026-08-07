#ifndef _COMPLEXCREATURE_H
#define _COMPLEXCREATURE_H

#include "types.h"

#include "SmartPtr.h"

class Creature;
class CreatureProp;

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
	void postUpdate(int unused, f32 deltaTime);

	// just here to spawn the right weak functions, who knows what this actually was lol
	SmartPtr<Creature> mCreatures[3]; // _00
};

#endif
