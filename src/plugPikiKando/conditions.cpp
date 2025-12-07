#include "Condition.h"
#include "Creature.h"

/*
 * --INFO--
 * Address:	800DAC28
 * Size:	000030
 */
bool CndIsVisible::satisfy(Creature* creature) immut
{
	return creature->isVisible();
}

/*
 * --INFO--
 * Address:	800DAC58
 * Size:	000030
 */
bool CndIsAtari::satisfy(Creature* creature) immut
{
	return creature->isAtari();
}

/*
 * --INFO--
 * Address:	800DAC88
 * Size:	00002C
 */
bool CndStickMouth::satisfy(Creature* creature) immut
{
	if (creature->isCreatureFlag(CF_StuckToMouth) && creature->mStickTarget == mMouthOwner) {
		return true;
	}
	return false;
}
