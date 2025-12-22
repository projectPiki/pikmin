#include "Kogane.h"
#include "Collision.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Piki.h"
#include "PikiState.h"
#include "Shape.h"
#include "sysNew.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Kogane");

/**
 * @TODO: Documentation
 */
KoganeProp::KoganeProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/**
 * @TODO: Documentation
 */
Kogane::Kogane(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(3);
	mKoganeAi = new KoganeAi(this);
}

/**
 * @TODO: Documentation
 */
f32 Kogane::getiMass()
{
	return 0.1f;
}

/**
 * @TODO: Documentation
 */
void Kogane::init(immut Vector3f&)
{
	mCollisionRadius = 25.0f;
	mIsOrganic       = false;
	mIsInvincible    = true;
	mNeedShadow      = false;
	mShadowSize      = 20.0f;
	_3B9             = false;
	mIsAppear        = false;
	mKoganeAi->initAI(this);
}

/**
 * @TODO: Documentation
 */
void Kogane::doKill()
{
	mIsAlive = 0;
	mIsAtari = 0;
	mKoganeAi->killCallBackEffect(false);
	bossMgr->kill(this);
}

/**
 * @TODO: Documentation
 */
void Kogane::exitCourse()
{
	mKoganeAi->killCallBackEffect(true);
}

/**
 * @TODO: Documentation
 */
void Kogane::update()
{
	Creature::update();
}

/**
 * @TODO: Documentation
 */
void Kogane::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	Matrix4f mtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
	mCollInfo->updateInfo(gfx, false);
}

/**
 * @TODO: Documentation
 */
void Kogane::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/**
 * @TODO: Documentation
 */
void Kogane::doAI()
{
	mKoganeAi->update();
	mIsOnWall = 0;
}

/**
 * @TODO: Documentation
 */
void Kogane::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/**
 * @TODO: Documentation
 */
void Kogane::collisionCallback(immut CollEvent& event)
{
	if (!_3B9 && event.mCollider->mObjType == OBJTYPE_Piki && static_cast<Piki*>(event.mCollider)->getState() == PIKISTATE_Flying) {
		_3B9 = true;
	}
}
