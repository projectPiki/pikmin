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

/**
 * @TODO: Documentation
 */
bool InteractAttack::actTeki(Teki* teki) immut
{
	return teki->interact(TekiInteractionKey(TekiInteractType::Attack, this));
}

/**
 * @TODO: Documentation
 */
bool InteractBomb::actTeki(Teki* teki) immut
{
	f32 bombFactor = teki->getParameterF(TPF_BombDamageRate);
	return teki->interact(TekiInteractionKey(TekiInteractType::Attack, &InteractAttack(mOwner, nullptr, mDamage * bombFactor, false)));
}

/**
 * @TODO: Documentation
 */
bool InteractHitEffect::actTeki(Teki* teki) immut
{
	return teki->interact(TekiInteractionKey(TekiInteractType::HitEffect, this));
}

/**
 * @TODO: Documentation
 */
bool InteractSwallow::actTeki(Teki*) immut
{
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractPress::actTeki(Teki* teki) immut
{
	teki->eventPerformed(TekiEvent(TekiEventType::Pressed, teki, mOwner));
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractFlick::actTeki(Teki*) immut
{
	return true;
}
