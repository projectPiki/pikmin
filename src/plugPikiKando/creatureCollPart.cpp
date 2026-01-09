#include "CreatureCollPart.h"

#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "Shape.h"

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("creatureCollPart")

/**
 * @brief Does nothing - individual platform collision pieces do not have independent physics when touched.
 */
void CreatureCollPart::touchCallback(immut Plane&, immut Vector3f&, immut Vector3f&)
{
}

/**
 * @brief Initialises a creature's platform collision manager, including setting up sub-parts for any required pieces.
 *
 * @param parent Creature these platform collision pieces are attached to.
 * @param map Manager for the map we're currently on.
 * @param parentModel Model for the parent creature.
 */
void CreaturePlatMgr::init(Creature* parent, MapMgr* map, Shape* parentModel)
{
	STACK_PAD_VAR(3);

	mPartCount           = 0;
	mParentCreatureModel = parentModel;

	// find any sub-parts we need to set up from the parent model's collision info
	FOREACH_NODE(ObjCollInfo, mParentCreatureModel->mCollisionInfo.mChild, collInfo)
	{
		if (collInfo->mPlatShape) {
			CreatureCollPart* part   = map->requestCollPart(collInfo, parent);
			mPlatParts[mPartCount++] = part;
		}
	}
}

/**
 * @brief Removes all current platform sub-parts from the list, and resets the count back to 0.
 *
 * @warning Does not free the memory allocated to these parts, it just becomes orphaned.
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
 * @brief Updates the transform matrices of all sub-parts, to keep them in sync with the creature's animation.
 *
 * @param gfx Graphics context for rendering.
 */
void CreaturePlatMgr::update(Graphics& gfx)
{
	for (int i = 0; i < mPartCount; i++) {
		CreatureCollPart* part = mPlatParts[i];
		part->mTransformMtx.inverse(&part->mInverseMatrix);

		Matrix4f mat = mParentCreatureModel->getAnimMatrix(part->mJointIndex);
		gfx.mCamera->mInverseLookAtMtx.multiplyTo(mat, part->mTransformMtx);
	}
}
