#include "Actor.h"
#include "DebugLog.h"

ActorMgr* actorMgr;

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
DEFINE_PRINT("genActor");

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
ActorMgr::ActorMgr(MapMgr*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
Creature* ActorMgr::createObject()
{
	return nullptr;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80119AB4
 * Size:	00007C
 */
Actor* ActorMgr::newActor(int p1)
{
	Actor* actor = (Actor*)birth();

	if (actor) {
		actor->setType(p1, mShapeObjectList[0], mCreaturePropertyList[0], mAiManagerList[0]);
	}

	return actor;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
ActorMgr::~ActorMgr()
{
	// UNUSED FUNCTION
}
