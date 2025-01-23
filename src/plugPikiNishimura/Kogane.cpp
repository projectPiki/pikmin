#include "Kogane.h"
#include "Collision.h"
#include "Graphics.h"
#include "Shape.h"
#include "Piki.h"
#include "PikiState.h"
#include "sysNew.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("Kogane");

/*
 * --INFO--
 * Address:	80175A30
 * Size:	000330
 */
KoganeProp::KoganeProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/*
 * --INFO--
 * Address:	80175D60
 * Size:	000084
 */
Kogane::Kogane(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(3);
	mKoganeAi = new KoganeAi(this);
}

/*
 * --INFO--
 * Address:	80175DE4
 * Size:	000008
 */
f32 Kogane::getiMass()
{
	return 0.1f;
}

/*
 * --INFO--
 * Address:	80175DEC
 * Size:	000054
 */
void Kogane::init(Vector3f&)
{
	mCollisionRadius = 25.0f;
	mIsOrganic       = 0;
	mIsInvincible    = 1;
	mNeedShadow      = 0;
	mShadowSize      = 20.0f;
	_3B9             = 0;
	mIsAppear        = false;
	mKoganeAi->initAI(this);
}

/*
 * --INFO--
 * Address:	80175E40
 * Size:	00004C
 */
void Kogane::doKill()
{
	mIsAlive = 0;
	mIsAtari = 0;
	mKoganeAi->killCallBackEffect(false);
	bossMgr->kill(this);
}

/*
 * --INFO--
 * Address:	80175E8C
 * Size:	000028
 */
void Kogane::exitCourse()
{
	mKoganeAi->killCallBackEffect(true);
}

/*
 * --INFO--
 * Address:	80175EB4
 * Size:	000020
 */
void Kogane::update()
{
	Creature::update();
}

/*
 * --INFO--
 * Address:	80175ED4
 * Size:	000098
 */
void Kogane::refresh(Graphics& gfx)
{
	mTransformMatrix.makeSRT(mScale, mRotation, mPosition);
	Matrix4f mtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mTransformMatrix, mtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
	mCollInfo->updateInfo(gfx, false);
}

/*
 * --INFO--
 * Address:	80175F6C
 * Size:	00006C
 */
void Kogane::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/*
 * --INFO--
 * Address:	80175FD8
 * Size:	000038
 */
void Kogane::doAI()
{
	mKoganeAi->update();
	mIsOnWall = 0;
}

/*
 * --INFO--
 * Address:	80176010
 * Size:	000044
 */
void Kogane::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/*
 * --INFO--
 * Address:	80176054
 * Size:	000058
 */
void Kogane::collisionCallback(CollEvent& event)
{
	if (!_3B9 && event.mCollider->mObjType == OBJTYPE_Piki && static_cast<Piki*>(event.mCollider)->getState() == PIKISTATE_Flying) {
		_3B9 = 1;
	}
}
