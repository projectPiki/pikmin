#include "DebugLog.h"
#include "Dolphin/os.h"
#include "ItemMgr.h"
#include "RopeCreature.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("ropeItem")

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
 */
bool RopeItem::isAtari()
{
	return false;
}

/**
 * @TODO: Documentation
 */
f32 RopeItem::getSize()
{
	return 5.0f;
}

/**
 * @TODO: Documentation
 */
void RopeItem::init(immut Vector3f& pos)
{
	f32 scale = 1.0f;
	mSRT.s.set(scale, scale, scale);
	Creature::init(pos);
	mSearchBuffer.init(mSearch, 3);
}

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
 */
void RopeItem::startAI(int)
{
}

/**
 * @TODO: Documentation
 */
void RopeItem::doKill()
{
	PRINT("ROPE %x is killed ?\n", this);
	itemMgr->kill(this);
}

/**
 * @TODO: Documentation
 */
f32 RopeItem::getiMass()
{
	return 10.0f;
}
