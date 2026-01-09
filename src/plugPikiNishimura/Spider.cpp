#include "Spider.h"
#include "DayMgr.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "MapMgr.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Spider");

/**
 * @todo: Documentation
 */
SpiderProp::SpiderProp()
{
	mCreatureProps.mFriction(1.0f);
	mCreatureProps.mFaceDirAdjust(0.0f);
	mCreatureProps.mAcceleration(1.0f);
}

/**
 * @todo: Documentation
 */
Spider::Spider(CreatureProp* props)
    : Boss(props)
{
	mCollInfo  = new CollInfo(24);
	mSpiderAi  = new SpiderAi(this);
	mSpiderLeg = new SpiderLeg(this);
	mShadowCaster.initCore("");
	mShadowCaster.initShadow();
	mShadowCaster.mShadowDrawer = new SpiderDrawer(this);
}

/**
 * @todo: Documentation
 */
f32 Spider::getiMass()
{
	return 0.1f;
}

/**
 * @todo: Documentation
 */
void Spider::init(immut Vector3f&)
{
	mCollisionRadius = 64.0f;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
#else
	setInvincible(true);
#endif
	setIsOrganic(false);
	mIsBossBgm            = false;
	mCanCreatePerishFx    = true;
	mIsHalfDead           = false;
	mCanCreateDeadBombFx  = true;
	mActiveWalkCycleCount = 0;
	mSpiderAi->initAI(this);
	mSpiderLeg->init(this);
	mHasShadow                      = false;
	mShadowCaster.mLightCamera.mFov = 35.0f;
	mCollInfo->makeTubesChild('leg1', 3);
	mCollInfo->makeTubesChild('leg2', 3);
	mCollInfo->makeTubesChild('leg3', 3);
	mCollInfo->makeTubesChild('leg4', 3);
}

/**
 * @todo: Documentation
 */
void Spider::doKill()
{
	mIsBossBgm = false;
	setIsAlive(0);
	setIsAtari(0);
	mSpiderLeg->killCallBackEffect(false);
	mShadowCaster.del();
	bossMgr->kill(this);
}

/**
 * @todo: Documentation
 */
void Spider::exitCourse()
{
	mSpiderLeg->killCallBackEffect(true);
}

/**
 * @todo: Documentation
 */
void Spider::update()
{
	doAI();
	mSpiderLeg->update();
	moveVelocity();
	moveNew(gsys->getFrameTime());
	doAnimation();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000100
 */
void Spider::draw(Graphics& gfx)
{
	Vector3f lightDirection = mapMgr->mDayMgr->mSunPosition - mSRT.t;
	lightDirection.y        = 0.0f;
	lightDirection.normalise();
	lightDirection.multiply(500.0f);

	mShadowCaster.mSourcePosition.set(mSpiderLeg->mCurrentCentre.x + lightDirection.x, mSRT.t.y + 1200.0f,
	                                  mSpiderLeg->mCurrentCentre.z + lightDirection.z);
	mShadowCaster.mTargetPosition.set(mSpiderLeg->mCurrentCentre.x, mSRT.t.y + 50.0f, mSpiderLeg->mCurrentCentre.z);

	mSpiderLeg->refresh(mShapeObject, gfx);
}

/**
 * @todo: Documentation
 */
void Spider::refresh(Graphics& gfx)
{
	draw(gfx);
	mCollInfo->updateInfo(gfx, false);
}

/**
 * @todo: Documentation
 */
void Spider::drawShape(Graphics& gfx)
{
	mShapeObject->mShape->calcWeightedMatrices();
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/**
 * @todo: Documentation
 */
void Spider::doAI()
{
	mSpiderAi->update();
}

/**
 * @todo: Documentation
 */
void Spider::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/**
 * @todo: Documentation
 */
void SpiderDrawer::draw(Graphics& gfx)
{
	mSpider->draw(gfx);
	mSpider->drawShape(gfx);
}
