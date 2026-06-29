#include "Actor.h"
#include "DebugLog.h"
#include "NaviMgr.h"
#include "gameflow.h"

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
 * @note UNUSED Size: 0000E4 (Matching by size?)
 */
ActorMgr::ActorMgr(MapMgr* mapMgr)
    : mMapMgr(mapMgr)
{
	mListsLength = 1;

	mShapeObjectList = new PikiShapeObject*[mListsLength];
	mNaviPropList    = new NaviProp*[mListsLength];
	mPoliceAIList    = new PoliceAI*[mListsLength];

	// This function's size is way off when naively following the DLL.  Something has got to give.
#if !defined(BUILD_MATCHING) || defined(WIN32)
	mShapeObjectList[0] = new PikiShapeObject(gameflow.loadShape("pikis/bluModel.mod", false));
#endif
	mNaviPropList[0] = new NaviProp();
	mPoliceAIList[0] = new PoliceAI();

	mMotionTable = PaniPikiAnimator::createMotionTable();
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
	Actor* actor = static_cast<Actor*>(birth());

	if (actor) {
		actor->setType(unused, mShapeObjectList[0], mNaviPropList[0], mPoliceAIList[0]);
	}

	return actor;
}
