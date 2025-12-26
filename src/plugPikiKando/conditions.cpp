#include "Condition.h"
#include "Creature.h"

/**
 * @todo: Documentation
 */
bool CndIsVisible::satisfy(Creature* creature) immut
{
	return creature->isVisible();
}

/**
 * @todo: Documentation
 */
bool CndIsAtari::satisfy(Creature* creature) immut
{
	return creature->isAtari();
}

/**
 * @todo: Documentation
 */
bool CndStickMouth::satisfy(Creature* creature) immut
{
	if (creature->isCreatureFlag(CF_StuckToMouth) && creature->mStickTarget == mMouthOwner) {
		return true;
	}
	return false;
}
