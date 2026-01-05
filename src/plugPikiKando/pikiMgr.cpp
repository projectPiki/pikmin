#include "PikiMgr.h"
#include "AIConstant.h"
#include "DebugLog.h"
#include "GameStat.h"
#include "ItemMgr.h"
#include "MemStat.h"
#include "Navi.h"
#include "PikiAI.h"
#include "gameflow.h"
#include "sysNew.h"

PikiMgr* pikiMgr;
bool PikiMgr::containerDebug;
bool PikiMgr::meBirthMode;
bool PikiMgr::meNukiMode;
bool PikiMgr::containerExitMode;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("pikiMgr");

/**
 * @todo: Documentation
 */
Creature* PikiMgr::birth()
{
	int totalPikis = GameStat::mapPikis;
	if (itemMgr) {
		totalPikis += itemMgr->getContainerExitCount();
	}

	if (containerExitMode) {
		totalPikis--;
	}

	if (meBirthMode) {
		if (totalPikis >= AIConstant::_instance->mConstants.mMaxPikisOnField() + 1) {
			return nullptr;
		}
	} else if (totalPikis >= AIConstant::_instance->mConstants.mMaxPikisOnField()) {
		return nullptr;
	}

	return MonoObjectMgr::birth();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C
 */
CPlate* PikiMgr::getFormationPikis()
{
	if (mNavi) {
		return mNavi->mPlateMgr;
	}

	return nullptr;
}

/**
 * @todo: Documentation
 */
PikiMgr::PikiMgr(Navi* navi)
{
	mNavi      = navi;
	mPikiParms = new PikiProp();

	mLeafModel[0] = gameflow.loadShape("pikis/happas/leaf.mod", true);
	mLeafModel[1] = gameflow.loadShape("pikis/happas/bud.mod", true);
	mLeafModel[2] = gameflow.loadShape("pikis/happas/flower.mod", true);

	PRINT("loading pikiMgr.bin ...\n");
	load("parms/", "pikiMgr.bin", 1);
	PRINT("done\n");

	memStat->start("piki mtable");
	mMotionTable = PaniPikiAnimator::createMotionTable();
	memStat->end("piki mtable");

	_58          = 0;
	_54          = 0;
	_5C          = 0;
	mUpdateFlag  = 0x1 | 0x2 | 0x4;
	mRefreshFlag = 0x1 | 0x2 | 0x4;
}

/**
 * @todo: Documentation
 */
void PikiMgr::init()
{
	AiTable::init();
	mDeadPikis           = 0;
	PikiMgr::meNukiMode  = false;
	PikiMgr::meBirthMode = false;
}

/**
 * @todo: Documentation
 */
Creature* PikiMgr::createObject()
{
	memStat->start("pikiNew");
	ViewPiki* piki = new ViewPiki(mPikiParms);
	piki->init(mPikiShape, mMapMgr, mNavi);
	memStat->end("pikiNew");
	return piki;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000054
 */
bool PikiMgr::lostAllPikis()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void PikiMgr::update()
{
	MonoObjectMgr::update();
}

/**
 * @todo: Documentation
 */
void PikiMgr::refresh(Graphics& graphics)
{
	MonoObjectMgr::refresh(graphics);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000114
 */
void PikiMgr::refresh2d(Graphics& gfx)
{
	Iterator iter(this);
	CI_LOOP(iter)
	{
		ViewPiki* piki = static_cast<ViewPiki*>(*iter);
		piki->refresh2d(gfx, 0);
	}
}

/**
 * @todo: Documentation
 */
void PikiMgr::read(RandomAccessStream& input)
{
	mPikiParms->read(input);
}

#if 0
void PikiMgr::write(RandomAccessStream& output)
{
	PRINT("writing pikiProp\n");
	mPikiParms->write(output);
	PRINT("done\n");
}
#endif

/**
 * @todo: Documentation
 */
void PikiMgr::dumpAll()
{
	Iterator iter(this);
	int pikiNum = 0;
	CI_LOOP(iter)
	{
		Creature* piki        = *iter;
		Matrix4f transformMtx = piki->mWorldMtx;
		PRINT("[%x] piki %d --------------------------\n", piki, pikiNum);
		for (int i = 0; i < 4; i++) {
			PRINT("   ( %.1f %.1f %.1f %.1f )\n", transformMtx.mMtx[i][0], transformMtx.mMtx[i][1], transformMtx.mMtx[i][2],
			      transformMtx.mMtx[i][3]);
		}
		piki->dump();
		pikiNum++;
	}
}
