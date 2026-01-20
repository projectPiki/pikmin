#include "Actor.h"
#include "DebugLog.h"

ActorMgr* actorMgr;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("genActor");

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000E4
 */
ActorMgr::ActorMgr(MapMgr*)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000050 (Matching by size)
 */
Creature* ActorMgr::createObject()
{
	Actor* actor = new Actor();
	actor->mMgr  = this;
	return actor;
}

/**
 * @todo: Documentation
 */
Actor* ActorMgr::newActor(int unused)
{
	Actor* actor = (Actor*)birth();

	if (actor) {
		actor->setType(unused, mShapeObjectList[0], mCreaturePropertyList[0], mAiManagerList[0]);
	}

	return actor;
}
