#include "Pom.h"
#include "Collision.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "NsMath.h"
#include "Piki.h"
#include "Shape.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 000098
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Pom");

/**
 * @todo: Documentation
 */
PomProp::PomProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/**
 * @todo: Documentation
 */
Pom::Pom(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(16);
	mPomAi    = new PomAi(this);
}

/**
 * @todo: Documentation
 */
f32 Pom::getiMass()
{
	return 0.0001f;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
 */
void Pom::doKill()
{
	setIsAlive(false);
	setIsAtari(false);
	mPomAi->killCallBackEffect(false);
	bossMgr->kill(this);
}

/**
 * @todo: Documentation
 */
void Pom::exitCourse()
{
	mPomAi->killCallBackEffect(true);
}

/**
 * @todo: Documentation
 */
void Pom::update()
{
	doAI();
	doAnimation();
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void Pom::drawShape(Graphics& gfx)
{
	if (isAlive()) {
		gfx.useMatrix(Matrix4f::ident, 0);
		mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, &mDynMaterial);
	}

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
void Pom::doAI()
{
	mPomAi->update();
}

/**
 * @todo: Documentation
 */
void Pom::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/**
 * @todo: Documentation
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
