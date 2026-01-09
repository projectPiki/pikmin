#include "Collision.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Graphics.h"
#include "King.h"
#include "MapMgr.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("KingBack");

/**
 * @todo: Documentation
 */
KingBackProp::KingBackProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/**
 * @todo: Documentation
 */
KingBack::KingBack(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(4);
}

/**
 * @todo: Documentation
 */
f32 KingBack::getiMass()
{
	return 0.0001f;
}

/**
 * @todo: Documentation
 */
void KingBack::init(immut Vector3f&)
{
	mCollisionRadius = 20.0f;
	mIsOrganic       = false;
	mIsInvincible    = true;
	mPlatMgr.init(this, mapMgr, mShapeObject->mShape);
}

/**
 * @todo: Documentation
 */
void KingBack::doKill()
{
	mPlatMgr.release();
	bossMgr->kill(this);
}

/**
 * @todo: Documentation
 */
void KingBack::exitCourse()
{
}

/**
 * @todo: Documentation
 */
void KingBack::update()
{
	doAI();
	doAnimation();
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void KingBack::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);

#if defined(DEVELOP) || defined(WIN32)
	Boss::drawShape(gfx);

	// This is really distracting to be enabled by default, so I've taken the liberty of adding a toggle.
#if !defined(BUILD_MATCHING)
	if (gsys->mToggleDebugInfo)
#endif
	{
		Matrix4f transformMtx;
		mWorldMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
		gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, transformMtx);
	}
#endif
}

/**
 * @todo: Documentation
 */
void KingBack::doAI()
{
	mSRT.t.set(mInitPosition);
}

/**
 * @todo: Documentation
 */
void KingBack::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}
