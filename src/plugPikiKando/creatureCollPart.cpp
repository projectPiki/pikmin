#include "CreatureCollPart.h"
#include "Dolphin/os.h"
#include "Shape.h"
#include "Graphics.h"
#include "MapMgr.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...) { OSPanic(__FILE__, __LINE__, fmt, "creatureCollPart"); }

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
 * Address:	8008E0BC
 * Size:	000004
 */
void CreatureCollPart::touchCallback(Plane&, Vector3f&, Vector3f&) { }

/*
 * --INFO--
 * Address:	8008E0C0
 * Size:	0000A0
 */
void CreaturePlatMgr::init(Creature* creature, MapMgr* map, Shape* shape)
{
	u32 badCompiler;
	u32 badCompiler2;
	u32 badCompiler3;

	mPartCount = 0;
	mPlatShape = shape;
	FOREACH_NODE(ObjCollInfo, mPlatShape->mCollisionInfo.mChild, collInfo)
	{
		if (collInfo->mIsEnabled) {
			CreatureCollPart* part   = map->requestCollPart(collInfo, creature);
			mPlatParts[mPartCount++] = part;
		}
	}
}

/*
 * --INFO--
 * Address:	8008E160
 * Size:	000068
 */
void CreaturePlatMgr::release()
{
	for (int i = 0; i < mPartCount; i++) {
		CreatureCollPart* part = mPlatParts[i];
		part->del();
	}

	mPartCount = 0;
}

/*
 * --INFO--
 * Address:	8008E1C8
 * Size:	0000FC
 */
void CreaturePlatMgr::update(Graphics& gfx)
{
	for (int i = 0; i < mPartCount; i++) {
		CreatureCollPart* part = mPlatParts[i];
		part->mTransformMtx.inverse(&part->mInverseMatrix);

		Matrix4f mat = mPlatShape->getAnimMatrix(part->mAnimMatrixID);
		gfx.mCamera->mInverseLookAtMtx.multiplyTo(mat, part->mTransformMtx);
	}
}
