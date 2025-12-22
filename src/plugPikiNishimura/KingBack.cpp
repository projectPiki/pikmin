#include "Collision.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Graphics.h"
#include "King.h"
#include "MapMgr.h"

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
DEFINE_PRINT("KingBack");

KingBackProp::KingBackProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

KingBack::KingBack(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(4);
}

f32 KingBack::getiMass()
{
	return 0.0001f;
}

void KingBack::init(immut Vector3f&)
{
	mCollisionRadius = 20.0f;
	mIsOrganic       = false;
	mIsInvincible    = true;
	mPlatMgr.init(this, mapMgr, mShapeObject->mShape);
}

void KingBack::doKill()
{
	mPlatMgr.release();
	bossMgr->kill(this);
}

void KingBack::exitCourse()
{
}

void KingBack::update()
{
	doAI();
	doAnimation();
}

void KingBack::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);

	Matrix4f mtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
	mCollInfo->updateInfo(gfx, false);
	mPlatMgr.update(gfx);
}

void KingBack::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

void KingBack::doAI()
{
	mSRT.t.set(mInitPosition);
}

void KingBack::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}
