#include "MizuItem.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "ItemAI.h"
#include "SimpleAI.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("matoItem")

/**
 * @todo: Documentation
 */
MizuItem::MizuItem(int objType, CreatureProp* props, ItemShapeObject* shape, SimpleAI* ai)
    : ItemCreature(objType, props, nullptr)
{
	mItemShapeObject = shape;
	mStateMachine    = ai;
}

/**
 * @todo: Documentation
 */
void MizuItem::update()
{
	ItemCreature::update();
	if (mGroundTriangle && mObjType == OBJTYPE_FallWater) {
		MsgGround msg;
		if (static_cast<SimpleAI*>(mStateMachine)) {
			static_cast<SimpleAI*>(mStateMachine)->procMsg(this, &msg);
		}
	}
}

/**
 * @todo: Documentation
 */
bool MizuItem::needFlick(Creature*)
{
	return false;
}

/**
 * @todo: Documentation
 */
void MizuItem::startAI(int)
{
	STACK_PAD_VAR(1);
	mSRT.s.x = 1.0f;
	mSRT.s.y = 1.0f;
	mSRT.s.z = 1.0f;
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

/**
 * @todo: Documentation
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
