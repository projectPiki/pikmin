#include "Pom.h"
#include "Collision.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "NsMath.h"
#include "Piki.h"
#include "Shape.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("Pom");

/**
 * @TODO: Documentation
 */
PomProp::PomProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/**
 * @TODO: Documentation
 */
Pom::Pom(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(16);
	mPomAi    = new PomAi(this);
}

/**
 * @TODO: Documentation
 */
f32 Pom::getiMass()
{
	return 0.0001f;
}

/**
 * @TODO: Documentation
 */
void Pom::init(immut Vector3f&)
{
	mCollisionRadius        = 20.0f;
	mIsOrganic              = false;
	mIsInvincible           = true;
	mNeedShadow             = true;
	mShadowSize             = 50.0f;
	mIsPikiOrPlayerTouching = false;
	mPomAi->initAI(this);
}

/**
 * @TODO: Documentation
 */
void Pom::setColor(int color)
{
	mColor = color;
	if (mColor < PikiMinColor || mColor > PikiMaxColor) {
		mColor = NsMathI::getRand(3);
	}

	mShapeObject->mShape->makeInstance(mDynMaterial, 0);
}

/**
 * @TODO: Documentation
 */
void Pom::doKill()
{
	mIsAlive = 0;
	mIsAtari = 0;
	mPomAi->killCallBackEffect(false);
	bossMgr->kill(this);
}

/**
 * @TODO: Documentation
 */
void Pom::exitCourse()
{
	mPomAi->killCallBackEffect(true);
}

/**
 * @TODO: Documentation
 */
void Pom::update()
{
	doAI();
	doAnimation();
}

/**
 * @TODO: Documentation
 */
void Pom::refresh(Graphics& gfx)
{
	if (isAlive()) {
		mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
		Matrix4f mtx;
		gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
		mAnimator.updateContext();

		f32 dynAnimType = mColor;
		mDynMaterial.animate(&dynAnimType);
		mShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
		mCollInfo->updateInfo(gfx, false);
	}
}

/**
 * @TODO: Documentation
 */
void Pom::drawShape(Graphics& gfx)
{
	if (isAlive()) {
		gfx.useMatrix(Matrix4f::ident, 0);
		mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, &mDynMaterial);
	}
}

/**
 * @TODO: Documentation
 */
void Pom::doAI()
{
	mPomAi->update();
}

/**
 * @TODO: Documentation
 */
void Pom::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/**
 * @TODO: Documentation
 */
void Pom::collisionCallback(immut CollEvent& event)
{
	if (event.mCollider->mObjType == OBJTYPE_Piki || event.mCollider->mObjType == OBJTYPE_Navi) {
		if (!mIsPikiOrPlayerTouching) {
			mIsPikiOrPlayerTouching = true;
		}

		mPomAi->collidePetal(event.mCollider);
	}
}
