#include "Kogane.h"
#include "Collision.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Piki.h"
#include "PikiState.h"
#include "Shape.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("Kogane");

KoganeProp::KoganeProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

Kogane::Kogane(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(3);
	mKoganeAi = new KoganeAi(this);
}

f32 Kogane::getiMass()
{
	return 0.1f;
}

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

void Kogane::doKill()
{
	mIsAlive = 0;
	mIsAtari = 0;
	mKoganeAi->killCallBackEffect(false);
	bossMgr->kill(this);
}

void Kogane::exitCourse()
{
	mKoganeAi->killCallBackEffect(true);
}

void Kogane::update()
{
	Creature::update();
}

void Kogane::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	Matrix4f mtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
	mCollInfo->updateInfo(gfx, false);
}

void Kogane::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

void Kogane::doAI()
{
	mKoganeAi->update();
	mIsOnWall = 0;
}

void Kogane::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

void Kogane::collisionCallback(immut CollEvent& event)
{
	if (!_3B9 && event.mCollider->mObjType == OBJTYPE_Piki && static_cast<Piki*>(event.mCollider)->getState() == PIKISTATE_Flying) {
		_3B9 = true;
	}
}
