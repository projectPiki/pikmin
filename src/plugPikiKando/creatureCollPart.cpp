#include "CreatureCollPart.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "Shape.h"

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
DEFINE_PRINT("creatureCollPart")

void CreatureCollPart::touchCallback(immut Plane&, immut Vector3f&, immut Vector3f&)
{
}

void CreaturePlatMgr::init(Creature* creature, MapMgr* map, Shape* shape)
{
	STACK_PAD_VAR(3);

	mPartCount = 0;
	mPlatShape = shape;
	FOREACH_NODE(ObjCollInfo, mPlatShape->mCollisionInfo.mChild, collInfo)
	{
		if (collInfo->mPlatShape) {
			CreatureCollPart* part   = map->requestCollPart(collInfo, creature);
			mPlatParts[mPartCount++] = part;
		}
	}
}

void CreaturePlatMgr::release()
{
	for (int i = 0; i < mPartCount; i++) {
		CreatureCollPart* part = mPlatParts[i];
		part->del();
	}

	mPartCount = 0;
}

void CreaturePlatMgr::update(Graphics& gfx)
{
	for (int i = 0; i < mPartCount; i++) {
		CreatureCollPart* part = mPlatParts[i];
		part->mTransformMtx.inverse(&part->mInverseMatrix);

		Matrix4f mat = mPlatShape->getAnimMatrix(part->mAnimMatrixID);
		gfx.mCamera->mInverseLookAtMtx.multiplyTo(mat, part->mTransformMtx);
	}
}
