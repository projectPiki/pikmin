#include "DebugLog.h"
#include "Dolphin/os.h"
#include "TAI/CollisionActions.h"
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
DEFINE_PRINT("taicollisionactions")

/**
 * @todo: Documentation
 */
bool TaiBounceAction::actByEvent(immut TekiEvent& event)
{
	return event.mEventType == TekiEventType::Ground;
}

/**
 * @todo: Documentation
 */
bool TaiGroundCollisionAction::actByEvent(immut TekiEvent& event)
{
	return event.mEventType == TekiEventType::Ground;
}

/**
 * @todo: Documentation
 */
bool TaiWallCollisionAction::actByEvent(immut TekiEvent& event)
{
	PRINT_NAKATA("TaiWallCollisionAction::actByEvent:%08x,%d\n", event.mTeki, event.mEventType);
	return event.mEventType == TekiEventType::Wall;
}

/**
 * @todo: Documentation
 */
bool TaiCreatureCollisionAction::actByEvent(immut TekiEvent& event)
{
	return event.mEventType == TekiEventType::Entity;
}

/**
 * @todo: Documentation
 */
bool TaiPikiCollisionAction::actByEvent(immut TekiEvent& event)
{
	if (!TaiCreatureCollisionAction::actByEvent(event)) {
		return false;
	}

	if (!event.mOther) {
		PRINT_NAKATA("!TaiPikiCollisionAction::actByEvent:%08x\n", event.mTeki);
		return false;
	}

	return event.mOther->mObjType == OBJTYPE_Piki;
}

/**
 * @todo: Documentation
 */
bool TaiNaviCollisionAction::actByEvent(immut TekiEvent& event)
{
	if (!TaiCreatureCollisionAction::actByEvent(event)) {
		return false;
	}

	if (!event.mOther) {
		PRINT_NAKATA("!TaiNaviCollisionAction::actByEvent:%08x\n", event.mTeki);
		return false;
	}

	return event.mOther->mObjType == OBJTYPE_Navi;
}

/**
 * @todo: Documentation
 */
bool TaiTekiTypeCollisionAction::actByEvent(immut TekiEvent& event)
{
	if (!TaiCreatureCollisionAction::actByEvent(event)) {
		return false;
	}

	if (!event.mOther) {
		PRINT_NAKATA("!TaiTekiTypeCollisionAction::actByEvent:%08x\n", event.mTeki);
		return false;
	}

	if (event.mOther->mObjType != OBJTYPE_Teki) {
		return false;
	}

	return static_cast<Teki*>(event.mOther)->mTekiType == mTekiType;
}
