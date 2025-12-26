#include "DebugLog.h"
#include "Interactions.h"
#include "teki.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("tekiinteraction");

/**
 * @todo: Documentation
 * @note UNUSED Size: 00000C
 */
TekiInteractionKey::TekiInteractionKey(int type, immut Interaction* interaction)
{
	mInteractionType = type;
	mInteraction     = interaction;
}

/**
 * @todo: Documentation
 */
bool InteractAttack::actTeki(Teki* teki) immut
{
	return teki->interact(TekiInteractionKey(TekiInteractType::Attack, this));
}

/**
 * @todo: Documentation
 */
bool InteractBomb::actTeki(Teki* teki) immut
{
	f32 bombFactor = teki->getParameterF(TPF_BombDamageRate);
	return teki->interact(TekiInteractionKey(TekiInteractType::Attack, &InteractAttack(mOwner, nullptr, mDamage * bombFactor, false)));
}

/**
 * @todo: Documentation
 */
bool InteractHitEffect::actTeki(Teki* teki) immut
{
	return teki->interact(TekiInteractionKey(TekiInteractType::HitEffect, this));
}

/**
 * @todo: Documentation
 */
bool InteractSwallow::actTeki(Teki*) immut
{
	return true;
}

/**
 * @todo: Documentation
 */
bool InteractPress::actTeki(Teki* teki) immut
{
	teki->eventPerformed(TekiEvent(TekiEventType::Pressed, teki, mOwner));
	return true;
}

/**
 * @todo: Documentation
 */
bool InteractFlick::actTeki(Teki*) immut
{
	return true;
}
