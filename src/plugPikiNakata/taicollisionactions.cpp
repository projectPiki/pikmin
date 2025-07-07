#include "DebugLog.h"
#include "Dolphin/os.h"
#include "TAI/CollisionActions.h"
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
DEFINE_PRINT("taicollisionactions")

/*
 * --INFO--
 * Address:	8012E48C
 * Size:	000014
 */
bool TaiBounceAction::actByEvent(TekiEvent& event)
{
	return event.mEventType == TekiEventType::Ground;
}

/*
 * --INFO--
 * Address:	8012E4A0
 * Size:	000014
 */
bool TaiGroundCollisionAction::actByEvent(TekiEvent& event)
{
	return event.mEventType == TekiEventType::Ground;
}

/*
 * --INFO--
 * Address:	8012E4B4
 * Size:	000014
 */
bool TaiWallCollisionAction::actByEvent(TekiEvent& event)
{
	return event.mEventType == TekiEventType::Wall;
}

/*
 * --INFO--
 * Address:	8012E4C8
 * Size:	000014
 */
bool TaiCreatureCollisionAction::actByEvent(TekiEvent& event)
{
	return event.mEventType == TekiEventType::Entity;
}

/*
 * --INFO--
 * Address:	8012E4DC
 * Size:	00003C
 */
bool TaiPikiCollisionAction::actByEvent(TekiEvent& event)
{
	if (event.mEventType != TekiEventType::Entity) {
		return false;
	}

	if (!event.mOther) {
		return false;
	}

	return event.mOther->mObjType == OBJTYPE_Piki;
}

/*
 * --INFO--
 * Address:	8012E518
 * Size:	00003C
 */
bool TaiNaviCollisionAction::actByEvent(TekiEvent& event)
{
	if (event.mEventType != TekiEventType::Entity) {
		return false;
	}

	if (!event.mOther) {
		return false;
	}

	return event.mOther->mObjType == OBJTYPE_Navi;
}

/*
 * --INFO--
 * Address:	8012E554
 * Size:	000054
 */
bool TaiTekiTypeCollisionAction::actByEvent(TekiEvent& event)
{
	if (event.mEventType != TekiEventType::Entity) {
		return false;
	}

	if (!event.mOther) {
		return false;
	}

	if (event.mOther->mObjType != OBJTYPE_Teki) {
		return false;
	}

	return static_cast<Teki*>(event.mOther)->mTekiType == mTekiType;
}
