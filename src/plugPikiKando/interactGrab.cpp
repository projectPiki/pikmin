#include "Creature.h"
#include "DebugLog.h"
#include "Interactions.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(6)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("interactGrab")

bool InteractGrab::actCommon(Creature* creature) immut
{
	bool result = creature->setStateGrabbed(mOwner);
	if (creature->mObjType != OBJTYPE_Bomb) {
		ERROR("try to grab objType %d\n", creature->mObjType);
	}
	if (result) {
		PRINT("grabbed %x\n", creature);
	}
	return result;
}

bool InteractRelease::actCommon(Creature* creature) immut
{
	PRINT("RELEASE CALLED\n");
	creature->resetStateGrabbed();
	creature->mVelocity = mOwner->mVelocity + Vector3f(0.0f, 100.0f * _08, 0.0f);
	creature->mSRT.t    = mOwner->getCatchPos(creature) + Vector3f(0.0f, 8.0f, 0.0f);
	return true;
}
