#include "RopeCreature.h"
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
DEFINE_PRINT("ropeCreature");

/*
 * --INFO--
 * Address:	800946A4
 * Size:	000058
 */
RopeCreature::RopeCreature(CreatureProp* prop)
    : Creature(prop)
{
	mParentRope  = nullptr;
	mAttachedObj = nullptr;
}

/*
 * --INFO--
 * Address:	800946FC
 * Size:	0001A8
 */
void RopeCreature::setRope(Creature* obj)
{
	Vector3f diff(obj->getCentre() - getCentre());
	mRopeDirection = diff;
	mRopeDirection.normalise();
	mRopeLength = diff.length();
	mParentRope = obj;
	if (mParentRope->mObjType == OBJTYPE_Rope) {
		((RopeItem*)mParentRope)->mAttachedObj = this;
	}
	mRopeLength = 50.0f;
}

/*
 * --INFO--
 * Address:	800948A4
 * Size:	0000D4
 */
void RopeCreature::update()
{
	Creature::update();
	mRopeDirection = mParentRope->mPosition - mPosition;
	mRopeDirection.normalise();
}

/*
 * --INFO--
 * Address:	80094978
 * Size:	0000B4
 */
Vector3f RopeCreature::getRopePos(f32 size)
{
	Vector3f pos(mPosition);
	pos = pos + (mRopeLength * size) * mRopeDirection;
	return pos;
}

/*
 * --INFO--
 * Address:	80094A2C
 * Size:	000004
 */
void RopeCreature::refresh(Graphics&)
{
}

/*
 * --INFO--
 * Address:	80094A30
 * Size:	000008
 */
bool RopeCreature::needShadow()
{
	return false;
}
