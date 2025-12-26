#include "DebugLog.h"
#include "Dolphin/os.h"
#include "ItemMgr.h"
#include "RopeCreature.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("ropeItem")

/**
 * @todo: Documentation
 */
RopeItem::RopeItem(CreatureProp* prop, Shape* shape)
    : RopeCreature(prop)
{
	mModel = shape;
	_68    = 4;
	resetCreatureFlag(CF_DisableAutoFaceDir);
	setCreatureFlag(CF_Unk1);
	mSearchBuffer.init(mSearch, 3);
	mObjType         = OBJTYPE_Rope;
	mCollisionRadius = 5.0f;
	mOwner           = nullptr;
}

/**
 * @todo: Documentation
 */
bool RopeItem::isAtari()
{
	return false;
}

/**
 * @todo: Documentation
 */
f32 RopeItem::getSize()
{
	return 5.0f;
}

/**
 * @todo: Documentation
 */
void RopeItem::init(immut Vector3f& pos)
{
	f32 scale = 1.0f;
	mSRT.s.set(scale, scale, scale);
	Creature::init(pos);
	mSearchBuffer.init(mSearch, 3);
}

/**
 * @todo: Documentation
 */
void RopeItem::autoInit()
{
	Iterator it(itemMgr);

	if (_2D0 == 0) {
		Creature* fulcrum = nullptr;
		f32 maxDist       = 12800.0f;
		CI_LOOP(it)
		{
			Creature* obj = *it;
			f32 dist      = qdist2(obj, this);
			if (obj->mObjType == OBJTYPE_Fulcrum && dist < maxDist) {
				fulcrum = obj;
				maxDist = dist;
			}
		}
		if (fulcrum) {
			setRope(fulcrum);
			PRINT("fulcrum found!\n");
		}
	} else {
		Creature* rope = nullptr;
		f32 maxDist    = 12800.0f;
		CI_LOOP(it)
		{
			Creature* obj = *it;
			f32 dist      = qdist2(obj, this);
			if (obj->mObjType == OBJTYPE_Rope && _2D0 - 1 == ((RopeItem*)obj)->_2D0 && dist < maxDist) {
				rope    = obj;
				maxDist = dist;
			}
		}
		if (rope) {
			setRope(rope);
			PRINT("rope found!\n");
		}
	}
}

/**
 * @todo: Documentation
 */
void RopeItem::startAI(int)
{
}

/**
 * @todo: Documentation
 */
void RopeItem::doKill()
{
	PRINT("ROPE %x is killed ?\n", this);
	itemMgr->kill(this);
}

/**
 * @todo: Documentation
 */
f32 RopeItem::getiMass()
{
	return 10.0f;
}
