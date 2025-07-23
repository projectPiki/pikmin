#include "DebugLog.h"
#include "Dolphin/os.h"
#include "ItemMgr.h"
#include "RopeCreature.h"

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
DEFINE_PRINT("ropeItem")

/*
 * --INFO--
 * Address:	800ED9DC
 * Size:	0000B0
 */
RopeItem::RopeItem(CreatureProp* prop, Shape* shape)
    : RopeCreature(prop)
{
	mModel = shape;
	_68    = 4;
	resetCreatureFlag(CF_Unk10);
	setCreatureFlag(CF_Unk1);
	mSearchBuffer.init(mSearch, 3);
	mObjType         = OBJTYPE_Rope;
	mCollisionRadius = 5.0f;
	mOwner           = nullptr;
}

/*
 * --INFO--
 * Address:	800EDA8C
 * Size:	000008
 */
bool RopeItem::isAtari()
{
	return false;
}

/*
 * --INFO--
 * Address:	800EDA94
 * Size:	000008
 */
f32 RopeItem::getSize()
{
	return 5.0f;
}

/*
 * --INFO--
 * Address:	800EDA9C
 * Size:	00004C
 */
void RopeItem::init(Vector3f& pos)
{
	f32 scale = 1.0f;
	mScale.set(scale, scale, scale);
	Creature::init(pos);
	mSearchBuffer.init(mSearch, 3);
}

/*
 * --INFO--
 * Address:	800EDAE8
 * Size:	000290
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

/*
 * --INFO--
 * Address:	800EDD78
 * Size:	000004
 */
void RopeItem::startAI(int)
{
}

/*
 * --INFO--
 * Address:	800EDD7C
 * Size:	000034
 */
void RopeItem::doKill()
{
	PRINT("ROPE %x is killed ?\n", this);
	itemMgr->kill(this);
}

/*
 * --INFO--
 * Address:	800EDDB0
 * Size:	000008
 */
f32 RopeItem::getiMass()
{
	return 10.0f;
}
