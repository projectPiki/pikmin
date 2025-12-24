#include "Actor.h"
#include "DebugLog.h"

ActorMgr* actorMgr;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("genActor");

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000E4
 */
ActorMgr::ActorMgr(MapMgr*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000050
 */
Creature* ActorMgr::createObject()
{
	// UNUSED FUNCTION (Matching by size)
	Actor* actor = new Actor();
	actor->mMgr  = this;
	return actor;
}

/**
 * @TODO: Documentation
 */
Actor* ActorMgr::newActor(int unused)
{
	Actor* actor = (Actor*)birth();

	if (actor) {
		actor->setType(unused, mShapeObjectList[0], mCreaturePropertyList[0], mAiManagerList[0]);
	}

	return actor;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000084
 */
ActorMgr::~ActorMgr()
{
	// UNUSED FUNCTION
}
