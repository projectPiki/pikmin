#include "Mizu.h"
#include "Collision.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "Graphics.h"
#include "Shape.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Mizu");

/**
 * @todo: Documentation
 */
MizuProp::MizuProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/**
 * @todo: Documentation
 */
Mizu::Mizu(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(3);
	mMizuAi   = new MizuAi(this);
}

/**
 * @todo: Documentation
 */
bool Mizu::attackDefaultPortion()
{
	effectMgr->create(EffectMgr::EFF_SD_DirtSpray, mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_SD_DirtCloud, mSRT.t, nullptr, nullptr);
	return true;
}

/**
 * @todo: Documentation
 */
f32 Mizu::getiMass()
{
	return 0.0001f;
}

/**
 * @todo: Documentation
 */
void Mizu::initMizu(immut Vector3f&)
{
	mCollisionRadius = 10.0f;
	setShadowNeed(1);
	setShadowSize(20.0f);
	mMizuAi->initMizu(this);
}

/**
 * @todo: Documentation
 */
void Mizu::initGeyzer(immut Vector3f&)
{
	mCollisionRadius = 10.0f;
	setShadowNeed(1);
	setShadowSize(20.0f);
	mMizuAi->initGeyzer(this);
}

/**
 * @todo: Documentation
 */
void Mizu::doKill()
{
	setIsAlive(false);
	setIsAtari(false);
	mMizuAi->killCallBackEffect(false);
	bossMgr->kill(this);
}

/**
 * @todo: Documentation
 */
void Mizu::exitCourse()
{
	mMizuAi->killCallBackEffect(true);
}

/**
 * @todo: Documentation
 */
void Mizu::update()
{
	doAI();
	doAnimation();
}

/**
 * @todo: Documentation
 */
void Mizu::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	Matrix4f onCamMtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, onCamMtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, onCamMtx, nullptr);
	mCollInfo->updateInfo(gfx, false);
}

/**
 * @todo: Documentation
 */
void Mizu::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/**
 * @todo: Documentation
 */
void Mizu::doAI()
{
	mMizuAi->update();
}

/**
 * @todo: Documentation
 */
void Mizu::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}
