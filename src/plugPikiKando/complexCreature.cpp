#include "ComplexCreature.h"
#include "Creature.h"
#include "Collision.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
ComplexCreature::ComplexCreature(int, CreatureProp*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void ComplexCreature::join(Creature*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void ComplexCreature::leave(Creature*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void ComplexCreature::cleanup()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000EC
 */
void ComplexCreature::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void ComplexCreature::doAI()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void ComplexCreature::postUpdate(int, f32)
{
	// this is just here for the weak function generation
	mCreatures[0].mPtr->bounceCallback();
	mCreatures[0].mPtr->collisionCallback(CollEvent(nullptr, nullptr, nullptr));
	// UNUSED FUNCTION
}
