#include "teki.h"

TekiEvent::TekiEvent(int eventType, Teki* teki)
{
	init(eventType, teki, nullptr);
}

TekiEvent::TekiEvent(int eventType, Teki* teki, Creature* creature)
{
	init(eventType, teki, creature);
}

void TekiEvent::init(int eventType, Teki* teki, Creature* creature)
{
	mEventType = (TekiEventType::Type)eventType;
	mTeki      = teki;
	mOther     = creature;
}
