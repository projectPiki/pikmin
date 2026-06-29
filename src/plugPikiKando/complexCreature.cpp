#include "ComplexCreature.h"
#include "Collision.h"
#include "Creature.h"
#include "DebugLog.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("TODO: Replace")

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000B4
 */
ComplexCreature::ComplexCreature(int, CreatureProp*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000A0
 */
void ComplexCreature::join(Creature*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000114
 */
void ComplexCreature::leave(Creature*)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000070
 */
void ComplexCreature::cleanup()
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000EC
 */
void ComplexCreature::update()
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void ComplexCreature::doAI()
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
void ComplexCreature::postUpdate(int unused, f32 deltaTime)
{
	TRAP_UNIMPLEMENTED;
	// this is just here for the weak function generation
	mCreatures[0].mPtr->bounceCallback();
	mCreatures[0].mPtr->collisionCallback(CollEvent(nullptr, nullptr, nullptr));
}
