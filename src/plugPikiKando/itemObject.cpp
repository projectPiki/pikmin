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

void ItemBall::startAI(int)
{
	mCollInfo = &mBallCollision;
	mCollInfo->initInfo(mItemShape, mBallParts, mPartIDs);
}

bool ItemBall::isAlive()
{
	return true;
}

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

void ItemObject::update()
{
}

BombGenItem::BombGenItem(Shape* shape)
    : ItemObject(OBJTYPE_BombGen, shape)
{
	_3C8 = -1;
	_3CA = 1;
}

bool BombGenItem::pickable()
{
	return isValid();
}

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

Fulcrum::Fulcrum()
    : ItemObject(OBJTYPE_Fulcrum, nullptr)
{
}

NaviDemoSunsetStart::NaviDemoSunsetStart()
    : ItemObject(OBJTYPE_SunsetStart, nullptr)
{
}

NaviDemoSunsetGoal::NaviDemoSunsetGoal()
    : ItemObject(OBJTYPE_SunsetGoal, nullptr)
{
}
