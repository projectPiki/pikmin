#include "PikiMgr.h"
#include "sysNew.h"
#include "gameflow.h"
#include "MemStat.h"
#include "AIConstant.h"
#include "PikiAi.h"
#include "ItemMgr.h"
#include "Navi.h"
#include "GameStat.h"
#include "DebugLog.h"

PikiMgr* pikiMgr;
bool PikiMgr::containerDebug;
bool PikiMgr::meBirthMode;
bool PikiMgr::meNukiMode;
bool PikiMgr::containerExitMode;

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
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	800CDCD0
 * Size:	0000BC
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
		if (totalPikis >= AIConstant::_instance->mConstants._114() + 1) {
			return nullptr;
		}
	} else if (totalPikis >= AIConstant::_instance->mConstants._114()) {
		return nullptr;
	}

	return MonoObjectMgr::birth();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
CPlate* PikiMgr::getFormationPikis()
{
	if (mNavi) {
		return mNavi->mPlateMgr;
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	800CDD8C
 * Size:	000258
 */
PikiMgr::PikiMgr(Navi* navi)
{
	mNavi      = navi;
	mPikiParms = new PikiProp();

	mLeafModel   = gameflow.loadShape("pikis/happas/leaf.mod", true);
	mBudModel    = gameflow.loadShape("pikis/happas/bud.mod", true);
	mFlowerModel = gameflow.loadShape("pikis/happas/flower.mod", true);

	PRINT("loading pikiMgr.bin ...\n");
	load("parms/", "pikiMgr.bin", 1);
	PRINT("done\n");

	memStat->start("piki mtable");
	mMotionTable = PaniPikiAnimator::createMotionTable();
	memStat->end("piki mtable");

	_58 = 0;
	_54 = 0;
	_5C = 0;
	_70 = 0x1 | 0x2 | 0x4;
	_72 = 0x1 | 0x2 | 0x4;
}

/*
 * --INFO--
 * Address:	800CED74
 * Size:	000018
 */
void PikiMgr::init()
{
	AiTable::init();
	_60                  = 0;
	PikiMgr::meNukiMode  = 0;
	PikiMgr::meBirthMode = 0;
}

/*
 * --INFO--
 * Address:	800CED8C
 * Size:	00007C
 */
Creature* PikiMgr::createObject()
{
	memStat->start("pikiNew");
	ViewPiki* piki = new ViewPiki(mPikiParms);
	piki->init(mPikiShape, mMapMgr, mNavi);
	memStat->end("pikiNew");
	return piki;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
bool PikiMgr::lostAllPikis()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800CEE08
 * Size:	000020
 */
void PikiMgr::update()
{
	MonoObjectMgr::update();
}

/*
 * --INFO--
 * Address:	800CEE28
 * Size:	000020
 */
void PikiMgr::refresh(Graphics& graphics)
{
	MonoObjectMgr::refresh(graphics);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
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

/*
 * --INFO--
 * Address:	800CEE48
 * Size:	000030
 */
void PikiMgr::read(RandomAccessStream& input)
{
	mPikiParms->read(input);
}

/*
 * --INFO--
 * Address:	800CEEBC
 * Size:	000198
 */
void PikiMgr::dumpAll()
{
	Iterator iter(this);
	int pikiNum = 0;
	CI_LOOP(iter)
	{
		Creature* piki        = *iter;
		Matrix4f transformMtx = piki->mTransformMatrix;
		PRINT("[%x] piki %d --------------------------\n", piki, pikiNum);
		for (int i = 0; i < 4; i++) {
			PRINT("   ( %.1f %.1f %.1f %.1f )\n", transformMtx.mMtx[i][0], transformMtx.mMtx[i][1], transformMtx.mMtx[i][2],
			      transformMtx.mMtx[i][3]);
		}
		piki->dump();
		pikiNum++;
	}
}
