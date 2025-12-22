#include "CreatureCollPart.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "Shape.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("creatureCollPart")

/**
 * @TODO: Documentation
 */
void CreatureCollPart::touchCallback(immut Plane&, immut Vector3f&, immut Vector3f&)
{
}

/**
 * @TODO: Documentation
 */
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

/**
 * @TODO: Documentation
 */
void CreaturePlatMgr::release()
{
	for (int i = 0; i < mPartCount; i++) {
		CreatureCollPart* part = mPlatParts[i];
		part->del();
	}

	mPartCount = 0;
}

/**
 * @TODO: Documentation
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
