#include "RopeCreature.h"
#include "DebugLog.h"

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
DEFINE_PRINT("ropeCreature");

/**
 * @TODO: Documentation
 */
RopeCreature::RopeCreature(CreatureProp* prop)
    : Creature(prop)
{
	mParentRope  = nullptr;
	mAttachedObj = nullptr;
}

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
 */
void RopeCreature::update()
{
	Creature::update();
	mRopeDirection = mParentRope->mSRT.t - mSRT.t;
	mRopeDirection.normalise();
}

/**
 * @TODO: Documentation
 */
Vector3f RopeCreature::getRopePos(f32 size)
{
	Vector3f pos(mSRT.t);
	pos = pos + (mRopeLength * size) * mRopeDirection;
	return pos;
}

/**
 * @TODO: Documentation
 */
void RopeCreature::refresh(Graphics&)
{
}

/**
 * @TODO: Documentation
 */
bool RopeCreature::needShadow()
{
	return false;
}
