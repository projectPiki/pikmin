#include "DebugLog.h"
#include "Interactions.h"
#include "teki.h"

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
DEFINE_PRINT("tekiinteraction");

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
TekiInteractionKey::TekiInteractionKey(int type, immut Interaction* interaction)
{
	mInteractionType = type;
	mInteraction     = interaction;
}

bool InteractAttack::actTeki(Teki* teki) immut
{
	return teki->interact(TekiInteractionKey(TekiInteractType::Attack, this));
}

bool InteractBomb::actTeki(Teki* teki) immut
{
	f32 bombFactor = teki->getParameterF(TPF_BombDamageRate);
	return teki->interact(TekiInteractionKey(TekiInteractType::Attack, &InteractAttack(mOwner, nullptr, mDamage * bombFactor, false)));
}

bool InteractHitEffect::actTeki(Teki* teki) immut
{
	return teki->interact(TekiInteractionKey(TekiInteractType::HitEffect, this));
}

bool InteractSwallow::actTeki(Teki*) immut
{
	return true;
}

bool InteractPress::actTeki(Teki* teki) immut
{
	teki->eventPerformed(TekiEvent(TekiEventType::Pressed, teki, mOwner));
	return true;
}

bool InteractFlick::actTeki(Teki*) immut
{
	return true;
}
