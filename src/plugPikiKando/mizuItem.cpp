#include "MizuItem.h"
#include "SimpleAI.h"
#include "ItemAI.h"
#include "Dolphin/os.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("matoItem")

/*
 * --INFO--
 * Address:	800F7CB0
 * Size:	000068
 */
MizuItem::MizuItem(int objType, CreatureProp* props, ItemShapeObject* shape, SimpleAI* ai)
    : ItemCreature(objType, props, nullptr)
{
	mItemShapeObject = shape;
	mStateMachine    = ai;
}

/*
 * --INFO--
 * Address:	800F7D18
 * Size:	000070
 */
void MizuItem::update()
{
	ItemCreature::update();
	if (mFloorTri && mObjType == OBJTYPE_FallWater) {
		MsgGround msg;
		if (static_cast<SimpleAI*>(mStateMachine)) {
			static_cast<SimpleAI*>(mStateMachine)->procMsg(this, &msg);
		}
	}
}

/*
 * --INFO--
 * Address:	800F7D88
 * Size:	000008
 */
bool MizuItem::needFlick(Creature*)
{
	return false;
}

/*
 * --INFO--
 * Address:	800F7D90
 * Size:	000090
 */
void MizuItem::startAI(int)
{
	u32 badCompiler;
	mScale.x = 1.0f;
	mScale.y = 1.0f;
	mScale.z = 1.0f;
	mItemAnimator.startMotion(PaniMotionInfo(0));

	switch (mObjType) {
	case OBJTYPE_Water:
		C_SAI(this)->start(this, WaterAI::WATER_Unk3);
		break;
	case OBJTYPE_FallWater:
		C_SAI(this)->start(this, FallWaterAI::FALLWATER_Unk0);
		break;
	}
}

/*
 * --INFO--
 * Address:	800F7E20
 * Size:	00006C
 */
bool MizuItem::isAlive()
{
	int stateID = getCurrState()->getID();
	if (mObjType == OBJTYPE_FallWater) {
		return false;
	}

	if (stateID == WaterAI::WATER_Die || stateID == WaterAI::WATER_Unk2) {
		return false;
	}

	return true;
}
