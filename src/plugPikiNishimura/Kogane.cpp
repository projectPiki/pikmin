#include "Kogane.h"
#include "Collision.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Piki.h"
#include "PikiState.h"
#include "Shape.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Kogane");

/**
 * @todo: Documentation
 */
KoganeProp::KoganeProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/**
 * @todo: Documentation
 */
Kogane::Kogane(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(3);
	mKoganeAi = new KoganeAi(this);
}

/**
 * @todo: Documentation
 */
f32 Kogane::getiMass()
{
	return 0.1f;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void Kogane::doKill()
{
	mIsAlive = 0;
	mIsAtari = 0;
	mKoganeAi->killCallBackEffect(false);
	bossMgr->kill(this);
}

/**
 * @todo: Documentation
 */
void Kogane::exitCourse()
{
	mKoganeAi->killCallBackEffect(true);
}

/**
 * @todo: Documentation
 */
void Kogane::update()
{
	Creature::update();
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void Kogane::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/**
 * @todo: Documentation
 */
void Kogane::doAI()
{
	mKoganeAi->update();
	mIsOnWall = 0;
}

/**
 * @todo: Documentation
 */
void Kogane::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/**
 * @todo: Documentation
 */
void Kogane::collisionCallback(immut CollEvent& event)
{
	if (!_3B9 && event.mCollider->mObjType == OBJTYPE_Piki && static_cast<Piki*>(event.mCollider)->getState() == PIKISTATE_Flying) {
		_3B9 = true;
	}
}
