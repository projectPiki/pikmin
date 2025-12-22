#include "ItemObject.h"
#include "DebugLog.h"
#include "Dolphin/os.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("itemObject");

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000074
 */
ItemBall::ItemBall(Shape* shape, CreatureProp* props)
    : ItemCreature(0, props, shape)
    , mBallCollision(0)
{
}

/**
 * @TODO: Documentation
 */
void ItemBall::startAI(int)
{
	mCollInfo = &mBallCollision;
	mCollInfo->initInfo(mItemShape, mBallParts, mPartIDs);
}

/**
 * @TODO: Documentation
 */
bool ItemBall::isAlive()
{
	return true;
}

/**
 * @TODO: Documentation
 */
bool ItemBall::isVisible()
{
	return true;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00005C
 */
ItemObject::ItemObject(int objType, Shape* shape)
    : ItemCreature(objType, nullptr, shape)
{
	mObjType = (EObjType)objType;
}

/**
 * @TODO: Documentation
 */
void ItemObject::update()
{
}

/**
 * @TODO: Documentation
 */
BombGenItem::BombGenItem(Shape* shape)
    : ItemObject(OBJTYPE_BombGen, shape)
{
	_3C8 = -1;
	_3CA = 1;
}

/**
 * @TODO: Documentation
 */
bool BombGenItem::pickable()
{
	return isValid();
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
Fulcrum::Fulcrum()
    : ItemObject(OBJTYPE_Fulcrum, nullptr)
{
}

/**
 * @TODO: Documentation
 */
NaviDemoSunsetStart::NaviDemoSunsetStart()
    : ItemObject(OBJTYPE_SunsetStart, nullptr)
{
}

/**
 * @TODO: Documentation
 */
NaviDemoSunsetGoal::NaviDemoSunsetGoal()
    : ItemObject(OBJTYPE_SunsetGoal, nullptr)
{
}
