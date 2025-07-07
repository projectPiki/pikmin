#include "SeedItem.h"
#include "AIConstant.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Interactions.h"
#include "ItemMgr.h"
#include "NaviMgr.h"

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
DEFINE_PRINT("seedItem")

/*
 * --INFO--
 * Address:	800EDDD0
 * Size:	0000DC
 */
SeedItem::SeedItem(CreatureProp* props, Shape** shapes)
    : Creature(props)
{
	mSeedShape    = shapes[0];
	mPlantedShape = shapes[1];
	mCurrentShape = mSeedShape;

	f32 scale = 0.2f;
	mScale.set(scale, scale, scale);

	_68 = 4;
	resetCreatureFlag(CF_Unk10);
	setCreatureFlag(CF_Unk1 | CF_Unk5);
	mSearchBuffer.init(mSearch, 3);
	mObjType = OBJTYPE_Seed;
	mStateId = 3;
}

/*
 * --INFO--
 * Address:	800EDEAC
 * Size:	000008
 */
f32 SeedItem::getSize()
{
	return 10.0f;
}

/*
 * --INFO--
 * Address:	800EDEB4
 * Size:	000044
 */
void SeedItem::init(Vector3f& pos)
{
	Creature::init(pos);
	mSearchBuffer.init(mSearch, 3);
	mStateId = 3;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void SeedItem::startBirth()
{
	mStateId      = 0;
	mCurrentShape = mSeedShape;
	resetCreatureFlag(CF_GravityEnabled); // Disable gravity for controlled drop
	setCreatureFlag(CF_Unk5);
	mVelocity.y = 10.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void SeedItem::startSown()
{
	mStateId      = 1;
	mGrowthTimer  = 200.0f;
	mCurrentShape = mPlantedShape;
	setCreatureFlag(CF_GravityEnabled); // Enable gravity
	resetCreatureFlag(CF_Unk5);
}

/*
 * --INFO--
 * Address:	800EDEF8
 * Size:	000014
 */
bool SeedItem::isVisible()
{
	return mStateId != 2;
}

/*
 * --INFO--
 * Address:	800EDF0C
 * Size:	000008
 */
bool SeedItem::isAtari()
{
	return false;
}

/*
 * --INFO--
 * Address:	800EDF14
 * Size:	00003C
 */
void SeedItem::doKill()
{
	PRINT("seed is killed ?\n");
	mStateId = 2;
	itemMgr->kill(this);
}

/*
 * --INFO--
 * Address:	800EDF50
 * Size:	00023C
 */
void SeedItem::update()
{
	if (mStateId == 0) {
		Navi* player = naviMgr->getNavi();

		Vector3f toPlayer    = player->mPosition - mPosition;
		toPlayer.y           = 0.0f;
		f32 distanceToPlayer = toPlayer.length();
		f32 rotationSpeed, moveSpeed, targetHeight;

		// Adjust movement speed and height based on distance to player
		if (distanceToPlayer < 20.0f) {
			// If the seed is close to the player, it will move towards the player at a fixed height and speed
			targetHeight  = 30.0f;
			moveSpeed     = 200.0f;
			rotationSpeed = 1.0f;
		} else if (distanceToPlayer < 200.0f) {
			// If the seed is within 200 units of the player, it will move towards the player at a height and speed that scales with
			// distance
			targetHeight  = ((distanceToPlayer - 20.0f) / 180.0f) * 70.0f + 30.0f;
			moveSpeed     = ((distanceToPlayer - 20.0f) / 180.0f) * 150.0f + 200.0f;
			rotationSpeed = ((distanceToPlayer - 20.0f) / 180.0f) * 5.0f + 1.0f;
		} else {
			// If the seed is more than 200 units away from the player, it will move towards the player at a fixed height and speed
			targetHeight  = 100.0f;
			moveSpeed     = 350.0f;
			rotationSpeed = 6.0f;
		}

		// Update rotation
		mFaceDirection += gsys->getFrameTime() * PI * rotationSpeed;
		mFaceDirection = roundAng(mFaceDirection);
		mRotation.set(0.0f, mFaceDirection, 0.0f);

		// Update velocity towards the player
		toPlayer    = toPlayer * (1.0f / distanceToPlayer);
		mVelocity.x = moveSpeed * toPlayer.x;
		mVelocity.z = moveSpeed * toPlayer.z;

		// Apply upward force if below target
		if (mPosition.y < targetHeight && mVelocity.y < 100.0f) {
			mVelocity.y += AIConstant::_instance->mConstants.mGravity() * gsys->getFrameTime() * 2.5f;
		}

		// Check if the seed is close enough to the player to be picked up
		if (distanceToPlayer < 8.0f) {
			player->_72C++;
			kill(nullptr);
		}
	}

	updateAI();
}

/*
 * --INFO--
 * Address:	800EE18C
 * Size:	000010
 */
void SeedItem::doAI()
{
	if (mStateId != 2 && !(mStateId == 2)) {
		PRINT("idek man", mGrowthTimer);
		return;
	}
}

/*
 * --INFO--
 * Address:	800EE19C
 * Size:	000138
 */
void SeedItem::refresh(Graphics& gfx)
{
	if (mStateId != 2) {
		Matrix4f unused;
		mWorldMtx.makeSRT(mScale, mRotation, mPosition);

		Matrix4f mtx;
		gfx.calcViewMatrix(mWorldMtx, mtx);
		gfx.useMatrix(mtx, 0);
		gfx.mCamera->setBoundOffset(&mPosition);
		mapMgr->getLight(mPosition.x, mPosition.z);
		bool l = gfx.setLighting(true, nullptr);
		mCurrentShape->drawshape(gfx, *gfx.mCamera, nullptr);
		gfx.mCamera->setBoundOffset(nullptr);
	}
}
