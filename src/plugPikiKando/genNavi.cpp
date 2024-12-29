#include "Generator.h"
#include "sysNew.h"
#include "NaviMgr.h"
#include "FlowController.h"
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
 * Size:	0000F0
 */
DEFINE_PRINT("");

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
// GenObjectNavi::GenObjectNavi()
//     : GenObject('navi', "プレイヤー２を生む")
// {
// }

/*
 * --INFO--
 * Address:	800F8130
 * Size:	000070
 */
GenObject* makeObjectNavi() { return new GenObjectNavi(); }

/*
 * --INFO--
 * Address:	800F81A0
 * Size:	00008C
 */
void GenObjectNavi::initialise()
{
	GenObjectFactory* fact = GenObjectFactory::factory;
	if (fact->mSpawnerCount >= fact->mMaxSpawners) {
		return;
	}

	fact->mSpawnerInfo[fact->mSpawnerCount].mID          = 'navi';
	fact->mSpawnerInfo[fact->mSpawnerCount].mGenFunction = &makeObjectNavi;
	fact->mSpawnerInfo[fact->mSpawnerCount].mName        = "generate NAVI (player2)";
	fact->mSpawnerInfo[fact->mSpawnerCount].mVersion     = 'v0.0';

	fact->mSpawnerCount++;
}

/*
 * --INFO--
 * Address:	800F822C
 * Size:	000004
 */
void GenObjectNavi::doRead(RandomAccessStream&) { }

/*
 * --INFO--
 * Address:	800F8230
 * Size:	0000B8
 */
Creature* GenObjectNavi::birth(BirthInfo& info)
{
	Navi* newNavi = (Navi*)naviMgr->birth();

	if (newNavi) {
		PRINT("************ NAVI START POSITION ****************\n");
		PRINT("\tpos(%f,%f,%f) angle(%f)\n", info.mPosition.x, info.mPosition.y, info.mPosition.z, (info.mRotation.y / PI) * 180.0f);
		PRINT("*************************************************\n");

		newNavi->init(info.mPosition);
		newNavi->mRotation  = info.mRotation;
		newNavi->mDirection = newNavi->mRotation.y;
		newNavi->reset();
		newNavi->mGenerator  = info.mGenerator;
		newNavi->mNaviCamera = naviMgr->getNavi()->mNaviCamera;
		flowCont._230        = 1;
	}

	return newNavi;
}
