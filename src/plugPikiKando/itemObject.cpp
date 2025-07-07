#include "ItemObject.h"
#include "DebugLog.h"
#include "Dolphin/os.h"

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
DEFINE_PRINT("itemObject");

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
ItemBall::ItemBall(Shape* shape, CreatureProp* props)
    : ItemCreature(0, props, shape)
    , mBallCollision(0)
{
}

/*
 * --INFO--
 * Address:	800F7958
 * Size:	00003C
 */
void ItemBall::startAI(int)
{
	mCollInfo = &mBallCollision;
	mCollInfo->initInfo(mItemShape, mBallParts, mPartIDs);
}

/*
 * --INFO--
 * Address:	800F7994
 * Size:	000008
 */
bool ItemBall::isAlive()
{
	return true;
}

/*
 * --INFO--
 * Address:	800F799C
 * Size:	000008
 */
bool ItemBall::isVisible()
{
	return true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
ItemObject::ItemObject(int objType, Shape* shape)
    : ItemCreature(objType, nullptr, shape)
{
	mObjType = (EObjType)objType;
}

/*
 * --INFO--
 * Address:	800F79A4
 * Size:	000004
 */
void ItemObject::update()
{
}

/*
 * --INFO--
 * Address:	800F79A8
 * Size:	00007C
 */
BombGenItem::BombGenItem(Shape* shape)
    : ItemObject(OBJTYPE_BombGen, shape)
{
	_3C8 = -1;
	_3CA = 1;
}

/*
 * --INFO--
 * Address:	800F7A24
 * Size:	000030
 */
bool BombGenItem::pickable()
{
	return isValid();
}

/*
 * --INFO--
 * Address:	800F7A54
 * Size:	00006C
 */
bool BombGenItem::pick()
{
	if (!pickable()) {
		return false;
	}

	if (_3C8 > 0) {
		if (_3CA > 0) {
			PRINT("BOMB LEFT %d\n", _3CA--);
		} else {
			return false;
		}
	}

	return true;
}

/*
 * --INFO--
 * Address:	800F7AC0
 * Size:	00006C
 */
Fulcrum::Fulcrum()
    : ItemObject(OBJTYPE_Fulcrum, nullptr)
{
}

/*
 * --INFO--
 * Address:	800F7B2C
 * Size:	00006C
 */
NaviDemoSunsetStart::NaviDemoSunsetStart()
    : ItemObject(OBJTYPE_SunsetStart, nullptr)
{
}

/*
 * --INFO--
 * Address:	800F7B98
 * Size:	00006C
 */
NaviDemoSunsetGoal::NaviDemoSunsetGoal()
    : ItemObject(OBJTYPE_SunsetGoal, nullptr)
{
}
