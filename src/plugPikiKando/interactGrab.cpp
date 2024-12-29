#include "Creature.h"
#include "Interactions.h"

static char file[] = __FILE__;
static char name[] = "interactGrab";

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

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
 * Address:	8007C89C
 * Size:	00003C
 */
bool InteractGrab::actCommon(Creature* creature)
{
	bool result = creature->setStateGrabbed(mOwner);
	if (creature->mObjType == OBJTYPE_Bomb) {
		// probably commented out code here
		return result;
	}

	return result;
}

/*
 * --INFO--
 * Address:	8007C8D8
 * Size:	000120
 */
bool InteractRelease::actCommon(Creature* creature)
{
	creature->resetStateGrabbed();
	creature->mVelocity = mOwner->mVelocity + Vector3f(0.0f, 100.0f * _08, 0.0f);
	creature->mPosition = mOwner->getCatchPos(creature) + Vector3f(0.0f, 8.0f, 0.0f);
	return true;
}
