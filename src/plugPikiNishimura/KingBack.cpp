#include "Collision.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Graphics.h"
#include "King.h"
#include "MapMgr.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("KingBack");

/**
 * @TODO: Documentation
 */
KingBackProp::KingBackProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/**
 * @TODO: Documentation
 */
KingBack::KingBack(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(4);
}

/**
 * @TODO: Documentation
 */
f32 KingBack::getiMass()
{
	return 0.0001f;
}

/**
 * @TODO: Documentation
 */
void KingBack::init(immut Vector3f&)
{
	mCollisionRadius = 20.0f;
	mIsOrganic       = false;
	mIsInvincible    = true;
	mPlatMgr.init(this, mapMgr, mShapeObject->mShape);
}

/**
 * @TODO: Documentation
 */
void KingBack::doKill()
{
	mPlatMgr.release();
	bossMgr->kill(this);
}

/**
 * @TODO: Documentation
 */
void KingBack::exitCourse()
{
}

/**
 * @TODO: Documentation
 */
void KingBack::update()
{
	doAI();
	doAnimation();
}

/**
 * @TODO: Documentation
 */
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

/**
 * @TODO: Documentation
 */
void KingBack::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/**
 * @TODO: Documentation
 */
void KingBack::doAI()
{
	mSRT.t.set(mInitPosition);
}

/**
 * @TODO: Documentation
 */
void KingBack::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}
