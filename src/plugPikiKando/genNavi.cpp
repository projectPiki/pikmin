#include "DebugLog.h"
#include "FlowController.h"
#include "Generator.h"
#include "NaviMgr.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("genNavi");

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
// GenObjectNavi::GenObjectNavi()
//     : GenObject('navi', "プレイヤー２を生む")
// {
// }

/**
 * @TODO: Documentation
 */
GenObject* makeObjectNavi()
{
	return new GenObjectNavi();
}

/**
 * @TODO: Documentation
 */
void GenObjectNavi::initialise()
{
	GenObjectFactory::factory->registerMember('navi', &makeObjectNavi, "generate NAVI (player2)", 'v0.0');
}

/**
 * @TODO: Documentation
 */
void GenObjectNavi::doRead(RandomAccessStream&)
{
}

/**
 * @TODO: Documentation
 */
Creature* GenObjectNavi::birth(BirthInfo& info)
{
	Navi* newNavi = (Navi*)naviMgr->birth();

	if (newNavi) {
		PRINT("************ NAVI START POSITION ****************\n");
		PRINT("\tpos(%f,%f,%f) angle(%f)\n", info.mPosition.x, info.mPosition.y, info.mPosition.z, (info.mRotation.y / PI) * 180.0f);
		PRINT("*************************************************\n");

		newNavi->init(info.mPosition);
		newNavi->mSRT.r         = info.mRotation;
		newNavi->mFaceDirection = newNavi->mSRT.r.y;
		newNavi->reset();
		newNavi->mGenerator  = info.mGenerator;
		newNavi->mNaviCamera = naviMgr->getNavi()->mNaviCamera;
		flowCont.mNaviOnMap  = 1;
	}

	return newNavi;
}
