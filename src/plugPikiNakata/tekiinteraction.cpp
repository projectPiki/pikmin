#include "Interactions.h"
#include "teki.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

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
TekiInteractionKey::TekiInteractionKey(int type, Interaction* interaction)
{
	mInteractionType = type;
	mInteraction     = interaction;
}

/*
 * --INFO--
 * Address:	8014A40C
 * Size:	000044
 */
bool InteractAttack::actTeki(Teki* teki)
{
	return teki->interact(TekiInteractionKey(0, this));
}

/*
 * --INFO--
 * Address:	8014A450
 * Size:	000090
 */
bool InteractBomb::actTeki(Teki* teki)
{
	f32 bombFactor = teki->getParameterF(TPF_BombDamageRate);
	return teki->interact(TekiInteractionKey(0, &InteractAttack(mOwner, nullptr, mDamage * bombFactor, false)));
}

/*
 * --INFO--
 * Address:	8014A4E0
 * Size:	000044
 */
bool InteractHitEffect::actTeki(Teki* teki)
{
	return teki->interact(TekiInteractionKey(1, this));
}

/*
 * --INFO--
 * Address:	8014A524
 * Size:	000008
 */
bool InteractSwallow::actTeki(Teki*)
{
	return true;
}

/*
 * --INFO--
 * Address:	8014A52C
 * Size:	000058
 */
bool InteractPress::actTeki(Teki* teki)
{
	teki->eventPerformed(TekiEvent(3, teki, mOwner));
	return true;
}

/*
 * --INFO--
 * Address:	8014A584
 * Size:	000008
 */
bool InteractFlick::actTeki(Teki*)
{
	return true;
}
