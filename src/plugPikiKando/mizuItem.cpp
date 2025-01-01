#include "MizuItem.h"
#include "SimpleAI.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...) { OSPanic(__FILE__, __LINE__, fmt, "matoItem"); }

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

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
		if (getAI()) {
			getAI()->procMsg(this, &msg);
		}
	}
}

/*
 * --INFO--
 * Address:	800F7D88
 * Size:	000008
 */
bool MizuItem::needFlick(Creature*) { return false; }

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
		getAI()->start(this, 3);
		break;
	case OBJTYPE_FallWater:
		getAI()->start(this, 0);
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
	int stateID = getCurrState()->getStateID();
	if (mObjType == OBJTYPE_FallWater) {
		return false;
	}

	if (stateID == 4 || stateID == 2) {
		return false;
	}

	return true;
}
