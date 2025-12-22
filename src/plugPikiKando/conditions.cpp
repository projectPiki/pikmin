#include "Condition.h"
#include "Creature.h"

/**
 * @TODO: Documentation
 */
bool CndIsVisible::satisfy(Creature* creature) immut
{
	return creature->isVisible();
}

/**
 * @TODO: Documentation
 */
bool CndIsAtari::satisfy(Creature* creature) immut
{
	return creature->isAtari();
}

/**
 * @TODO: Documentation
 */
bool CndStickMouth::satisfy(Creature* creature) immut
{
	if (creature->isCreatureFlag(CF_StuckToMouth) && creature->mStickTarget == mMouthOwner) {
		return true;
	}
	return false;
}
