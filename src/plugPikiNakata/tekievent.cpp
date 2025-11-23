#include "teki.h"

/*
 * --INFO--
 * Address:	8014A398
 * Size:	000034
 */
TekiEvent::TekiEvent(int eventType, Teki* teki)
{
	init(eventType, teki, nullptr);
}

/*
 * --INFO--
 * Address:	8014A3CC
 * Size:	000030
 */
TekiEvent::TekiEvent(int eventType, Teki* teki, Creature* creature)
{
	init(eventType, teki, creature);
}

/*
 * --INFO--
 * Address:	8014A3FC
 * Size:	000010
 */
void TekiEvent::init(int eventType, Teki* teki, Creature* creature)
{
	mEventType = (TekiEventType::Type)eventType;
	mTeki      = teki;
	mOther     = creature;
}
