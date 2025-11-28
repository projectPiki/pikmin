#include "NaviMgr.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "MemStat.h"
#include "gameflow.h"
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
 * Size:	0000F4
 */
DEFINE_PRINT("naviiMgr"); // epic typo

NaviMgr* naviMgr;

/*
 * --INFO--
 * Address:	801171C4
 * Size:	000180
 */
NaviMgr::NaviMgr()
{
	memStat->start("naviparms");
	mNaviParms = new NaviProp();
	load("parms/", "naviMgr.bin", 1);
	memStat->end("naviparms");

	memStat->start("navi shape anim");

	memStat->start("navi mtable");
	mMotionTable = PaniPikiAnimator::createMotionTable();
	memStat->end("navi mtable");

	memStat->start("navi shape");
	mNaviShape = gameflow.loadShape("pikis/nv3Model.mod", true);
	memStat->end("navi shape");

	memStat->start("navi shapeobject");
	mNaviShapeObject[0] = new PikiShapeObject(mNaviShape);
	memStat->end("navi shapeobject");

	memStat->start("navi animmgr");
	mNaviShapeObject[0]->mAnimMgr = PikiShapeObject::getAnimMgr();
	memStat->end("navi animmgr");

	mNaviID = 0;
	memStat->end("navi shape anim");
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NaviMgr::init()
{
}

/*
 * --INFO--
 * Address:	80117344
 * Size:	000060
 */
Creature* NaviMgr::createObject()
{
	Navi* navi = new Navi(mNaviParms, mNaviID);
	mNaviID++;
	return navi;
}

/*
 * --INFO--
 * Address:	801173A4
 * Size:	000020
 */
void NaviMgr::update()
{
	MonoObjectMgr::update();
}

/*
 * --INFO--
 * Address:	801173C4
 * Size:	000074
 */
Navi* NaviMgr::getNavi()
{
	Iterator iter(this);
	iter.first();
	return static_cast<Navi*>(*iter);
}

/*
 * --INFO--
 * Address:	80117438
 * Size:	000018
 */
Navi* NaviMgr::getNavi(int idx)
{
	if (idx >= mNumObjects) {
		// Given this is a bounds-check, this should probably be an `ERROR`...
		TERNARY_BUGFIX(ERROR, PRINT)("err : getNavi(%d) : numNavis=%d\n", idx, mNumObjects);
	}
	return static_cast<Navi*>(mObjectList[idx]);
}

/*
 * --INFO--
 * Address:	80117450
 * Size:	00011C
 */
void NaviMgr::refresh2d(Graphics& gfx)
{
	Iterator iter(this);
	CI_LOOP(iter)
	{
		(*iter)->refresh2d(gfx);
	}
}

/*
 * --INFO--
 * Address:	8011756C
 * Size:	000110
 */
void NaviMgr::renderCircle(Graphics& gfx)
{
	Iterator iter(this);
	CI_LOOP(iter)
	{
		static_cast<Navi*>(*iter)->renderCircle(gfx);
	}
}

/*
 * --INFO--
 * Address:	8011767C
 * Size:	00011C
 */
void NaviMgr::drawShadow(Graphics& gfx)
{
	Iterator iter(this);
	CI_LOOP(iter)
	{
		(*iter)->drawShadow(gfx);
	}
}

/*
 * --INFO--
 * Address:	80117798
 * Size:	000030
 */
void NaviMgr::read(RandomAccessStream& input)
{
	mNaviParms->read(input);
}

#if 0
void NaviMgr::write(RandomAccessStream& output)
{
	PRINT("writing naviProp\n");
	mNaviParms->write(output);
	PRINT("done\n");
}
#endif
