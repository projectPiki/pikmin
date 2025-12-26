#include "teki.h"

/**
 * @todo: Documentation
 */
TekiEvent::TekiEvent(int eventType, Teki* teki)
{
	init(eventType, teki, nullptr);
}

/**
 * @todo: Documentation
 */
TekiEvent::TekiEvent(int eventType, Teki* teki, Creature* creature)
{
	init(eventType, teki, creature);
}

/**
 * @todo: Documentation
 */
void TekiEvent::init(int eventType, Teki* teki, Creature* creature)
{
	mEventType = (TekiEventType::Type)eventType;
	mTeki      = teki;
	mOther     = creature;
}
