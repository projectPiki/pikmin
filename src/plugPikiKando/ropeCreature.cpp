#include "RopeCreature.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

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
	_2B8 = nullptr;
	_2BC = nullptr;
}

/*
 * --INFO--
 * Address:	800946FC
 * Size:	0001A8
 */
void RopeCreature::setRope(Creature* obj)
{
	Vector3f diff(obj->getCentre() - getCentre());
	mPosDifference = diff;
	mPosDifference.normalise();
	_2C0 = diff.length();
	_2B8 = obj;
	if (_2B8->mObjType == OBJTYPE_Rope) {
		((RopeItem*)_2B8)->_2BC = this;
	}
	_2C0 = 50.0f;
}

/*
 * --INFO--
 * Address:	800948A4
 * Size:	0000D4
 */
void RopeCreature::update()
{
	Creature::update();
	mPosDifference = _2B8->mPosition - mPosition;
	mPosDifference.normalise();
}

/*
 * --INFO--
 * Address:	80094978
 * Size:	0000B4
 */
Vector3f RopeCreature::getRopePos(f32 size)
{
	Vector3f pos(mPosition);
	pos = pos + (_2C0 * size) * mPosDifference;
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
