#include "Condition.h"
#include "Creature.h"

bool CndIsVisible::satisfy(Creature* creature) immut
{
	return creature->isVisible();
}

bool CndIsAtari::satisfy(Creature* creature) immut
{
	return creature->isAtari();
}

bool CndStickMouth::satisfy(Creature* creature) immut
{
	if (creature->isCreatureFlag(CF_StuckToMouth) && creature->mStickTarget == mMouthOwner) {
		return true;
	}
	return false;
}
