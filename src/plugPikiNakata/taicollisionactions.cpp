#include "TAI/CollisionActions.h"
#include "teki.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...) { OSPanic(__FILE__, __LINE__, fmt, "taicollisionactions"); }

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8012E48C
 * Size:	000014
 */
bool TaiBounceAction::actByEvent(TekiEvent& event) { return event._00 == 0; }

/*
 * --INFO--
 * Address:	8012E4A0
 * Size:	000014
 */
bool TaiGroundCollisionAction::actByEvent(TekiEvent& event) { return event._00 == 0; }

/*
 * --INFO--
 * Address:	8012E4B4
 * Size:	000014
 */
bool TaiWallCollisionAction::actByEvent(TekiEvent& event) { return event._00 == 2; }

/*
 * --INFO--
 * Address:	8012E4C8
 * Size:	000014
 */
bool TaiCreatureCollisionAction::actByEvent(TekiEvent& event) { return event._00 == 1; }

/*
 * --INFO--
 * Address:	8012E4DC
 * Size:	00003C
 */
bool TaiPikiCollisionAction::actByEvent(TekiEvent& event)
{
	if (event._00 != 1) {
		return false;
	}
	if (!event._08) {
		return false;
	}
	return event._08->mObjType == OBJTYPE_Piki;
}

/*
 * --INFO--
 * Address:	8012E518
 * Size:	00003C
 */
bool TaiNaviCollisionAction::actByEvent(TekiEvent& event)
{
	if (event._00 != 1) {
		return false;
	}
	if (!event._08) {
		return false;
	}
	return event._08->mObjType == OBJTYPE_Navi;
}

/*
 * --INFO--
 * Address:	8012E554
 * Size:	000054
 */
bool TaiTekiTypeCollisionAction::actByEvent(TekiEvent& event)
{
	if (event._00 != 1) {
		return false;
	}
	if (!event._08) {
		return false;
	}
	if (event._08->mObjType != OBJTYPE_Teki) {
		return false;
	}

	return static_cast<Teki*>(event._08)->mTekiType == mTekiType;
}
