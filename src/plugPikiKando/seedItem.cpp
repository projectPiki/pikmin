#include "SeedItem.h"
#include "DebugLog.h"
#include "ItemMgr.h"
#include "NaviMgr.h"
#include "AIConstant.h"
#include "Graphics.h"
#include "Interactions.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

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
	mShape        = shapes[0];
	mShape2       = shapes[1];
	mCurrentShape = mShape;

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
	mCurrentShape = mShape;
	resetCreatureFlag(CF_GravityEnabled);
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
	_2E0          = 200.0f;
	mCurrentShape = mShape2;
	setCreatureFlag(CF_GravityEnabled);
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
		Navi* navi    = naviMgr->getNavi();
		Vector3f diff = navi->mPosition - mPosition;
		diff.y        = 0.0f;
		f32 dist      = diff.length();

		f32 mult, vel, y;
		if (dist < 20.0f) {
			y    = 30.0f;
			vel  = 200.0f;
			mult = 1.0f;
		} else if (dist < 200.0f) {
			y    = ((dist - 20.0f) / 180.0f) * 70.0f + 30.0f;
			vel  = ((dist - 20.0f) / 180.0f) * 150.0f + 200.0f;
			mult = ((dist - 20.0f) / 180.0f) * 5.0f + 1.0f;
		} else {
			y    = 100.0f;
			vel  = 350.0f;
			mult = 6.0f;
		}
		mDirection += gsys->getFrameTime() * PI * mult;
		mDirection = roundAng(mDirection);

		mRotation.set(0.0f, mDirection, 0.0f);

		diff        = diff * (1.0f / dist);
		mVelocity.x = vel * diff.x;
		mVelocity.z = vel * diff.z;
		if (mPosition.y < y && mVelocity.y < 100.0f) {
			mVelocity.y += AIConstant::_instance->mConstants.mGravity() * gsys->getFrameTime() * 2.5f;
		}
		if (dist < 8.0f) {
			navi->_72C++;
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
		PRINT("idek man", _2E0);
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
		mTransformMatrix.makeSRT(mScale, mRotation, mPosition);

		Matrix4f mtx;
		gfx.calcViewMatrix(mTransformMatrix, mtx);
		gfx.useMatrix(mtx, 0);
		gfx.mCamera->setBoundOffset(&mPosition);
		mapMgr->getLight(mPosition.x, mPosition.z);
		bool l = gfx.setLighting(true, nullptr);
		mCurrentShape->drawshape(gfx, *gfx.mCamera, nullptr);
		gfx.mCamera->setBoundOffset(nullptr);
	}
}
