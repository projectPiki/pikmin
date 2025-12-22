#include "teki.h"

/**
 * @TODO: Documentation
 */
TekiEvent::TekiEvent(int eventType, Teki* teki)
{
	init(eventType, teki, nullptr);
}

/**
 * @TODO: Documentation
 */
TekiEvent::TekiEvent(int eventType, Teki* teki, Creature* creature)
{
	init(eventType, teki, creature);
}

/**
 * @TODO: Documentation
 */
void TekiEvent::init(int eventType, Teki* teki, Creature* creature)
{
	mEventType = (TekiEventType::Type)eventType;
	mTeki      = teki;
	mOther     = creature;
}
