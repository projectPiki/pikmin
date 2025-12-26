#include "RopeCreature.h"
#include "DebugLog.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("ropeCreature");

/**
 * @todo: Documentation
 */
RopeCreature::RopeCreature(CreatureProp* prop)
    : Creature(prop)
{
	mParentRope  = nullptr;
	mAttachedObj = nullptr;
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void RopeCreature::update()
{
	Creature::update();
	mRopeDirection = mParentRope->mSRT.t - mSRT.t;
	mRopeDirection.normalise();
}

/**
 * @todo: Documentation
 */
Vector3f RopeCreature::getRopePos(f32 size)
{
	Vector3f pos(mSRT.t);
	pos = pos + (mRopeLength * size) * mRopeDirection;
	return pos;
}

/**
 * @todo: Documentation
 */
void RopeCreature::refresh(Graphics&)
{
}

/**
 * @todo: Documentation
 */
bool RopeCreature::needShadow()
{
	return false;
}
