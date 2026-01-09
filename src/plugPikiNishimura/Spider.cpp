#include "Spider.h"
#include "DayMgr.h"
#include "DebugLog.h"
#include "Graphics.h"

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
	mShadowCaster.mDrawer = new SpiderDrawer(this);
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
	setIsAlive(false);
	setIsAtari(false);
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

#if defined(DEVELOP) || defined(WIN32)
	Boss::drawShape(gfx);

	// This is really distracting to be enabled by default, so I've taken the liberty of adding a toggle.
#if !defined(BUILD_MATCHING)
	if (gsys->mToggleDebugInfo)
#endif
	{
		Matrix4f transformMtx;
		// In the DLL, the red debug spheres specific to Beady Long Legs are wrongly rotated and translated due to this mistake.
		mWorldMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), TERNARY_BUGFIX(MACRO_ARG(Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f)),
		                                                             MACRO_ARG(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(1.0f, 1.0f, 1.0f))));
		gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, transformMtx);

		if (getCurrentState() == SPIDERAI_Start) {
			gfx.setColour(Colour(255, 0, 0, 255), true);
			gfx.drawSphere(*getInitPosition(), SPIDER_PROP.mSpawnTriggerDist(), transformMtx);
		}
		CollPart* body = mCollInfo->getSphere('tama');
		gfx.setColour(Colour(255, 0, 0, 255), true);
		gfx.drawSphere(body->mCentre, body->mRadius, transformMtx);

		for (int i = 0; i < 4; i++) {
			// Fabricated name
			static int matrixIndices[7][3] = {
				{ 12, 11, 10 }, { 15, 14, 13 }, { 6, 5, 4 }, { 9, 8, 7 }, { 3, 2, 0 }, { 1, -1, 2 }, { 3, 0, 1 },
			};

			Vector3f local_5c(0.0f, 0.0f, 0.0f);
			Vector3f local_68(0.0f, 0.0f, 0.0f);
			Vector3f local_74(0.0f, 0.0f, 0.0f);

			local_5c.multMatrix(mShapeObject->mShape->getAnimMatrix(matrixIndices[i][2]));
			local_68.multMatrix(mShapeObject->mShape->getAnimMatrix(matrixIndices[i][1]));
			local_74.multMatrix(mShapeObject->mShape->getAnimMatrix(matrixIndices[i][0]));

			// Why are these inside the for loop?
			gfx.useMatrix(Matrix4f::ident, 0);
			gfx.setLighting(false, nullptr);
			gfx.setFog(false);
			gfx.useTexture(nullptr, GX_TEXMAP0);

			gfx.setColour(Colour(255, 255, 255, 255), true);
			gfx.drawLine(local_5c, local_68);
			gfx.drawLine(local_68, local_74);
		}
	}
#endif
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
