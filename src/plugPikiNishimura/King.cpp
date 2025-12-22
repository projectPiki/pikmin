#include "King.h"
#include "DayMgr.h"
#include "DebugLog.h"
#include "Graphics.h"

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
DEFINE_PRINT("King");

/**
 * @TODO: Documentation
 */
KingProp::KingProp()
{
	mCreatureProps.mFriction(1.0f);
	mCreatureProps.mFaceDirAdjust(0.0f);
	mCreatureProps.mAcceleration(1.0f);
}

/**
 * @TODO: Documentation
 */
King::King(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(38);
	mKingAi   = new KingAi(this);
	mKingBody = new KingBody(this);
	mShadowCaster.initCore("");
	mShadowCaster.initShadow();
	mShadowCaster.mDrawer = new KingDrawer(this);
}

/**
 * @TODO: Documentation
 */
f32 King::getiMass()
{
	return 0.0001f;
}

/**
 * @TODO: Documentation
 */
void King::bombDamageCounter(CollPart*)
{
	if (getCurrentState() == KINGAI_Attack) {
		mKingAi->mBombDamageCounter++;
	}
}

/**
 * @TODO: Documentation
 */
void King::init(immut Vector3f&)
{
	mCollisionRadius = 50.0f;
	setInvincible(true);
	setIsOrganic(0);
	setShadowSize(150.0f);
	mIsBossBgm = false;
	mKingAi->initAI(this);
	mKingBody->init(this);
	mShadowCaster.mLightCamera.mFov = 35.0f;
	mPlatMgr.init(this, mapMgr, mShapeObject->mShape);
}

/**
 * @TODO: Documentation
 */
void King::doKill()
{
	setIsAlive(0);
	setIsAtari(0);
	mIsBossBgm = false;
	mKingBody->killCallBackEffect(false);
	mPlatMgr.release();
	mShadowCaster.del();
	bossMgr->kill(this);
}

/**
 * @TODO: Documentation
 */
void King::exitCourse()
{
	mKingBody->killCallBackEffect(true);
}

/**
 * @TODO: Documentation
 */
void King::update()
{
	doAI();
	moveVelocity();
	moveNew(gsys->getFrameTime());
	doAnimation();
}

/**
 * @TODO: Documentation
 */
void King::draw(Graphics& gfx)
{
	Vector3f lightDirection = mapMgr->mDayMgr->mSunPosition - mSRT.t;
	lightDirection.y        = 0.0f;
	lightDirection.normalise();
	lightDirection.multiply(150.0f);

	Vector3f centre = mCollInfo->getBoundingSphere()->mCentre;
	f32 yDiff       = centre.y - mSRT.t.y;
	if (yDiff > 0.0f) {
		centre.y += yDiff * 3.0f;
	}

	mShadowCaster.mSourcePosition.set(centre.x + lightDirection.x, centre.y + 1000.0f, centre.z + lightDirection.z);
	mShadowCaster.mTargetPosition.set(mSRT.t.x, mSRT.t.y + 50.0f, mSRT.t.z);

	Matrix4f viewMatrix;
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, viewMatrix);

	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, viewMatrix, nullptr);
	mKingBody->refresh(mShapeObject, gfx);
}

/**
 * @TODO: Documentation
 */
void King::refresh(Graphics& gfx)
{
	draw(gfx);
	mCollInfo->updateInfo(gfx, false);
	mPlatMgr.update(gfx);
}

/**
 * @TODO: Documentation
 */
void King::drawShape(Graphics& gfx)
{
	mShapeObject->mShape->calcWeightedMatrices();
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/**
 * @TODO: Documentation
 */
void King::doAI()
{
	mKingAi->update();
}

/**
 * @TODO: Documentation
 */
void King::doAnimation()
{
	mKingBody->update();
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/**
 * @TODO: Documentation
 */
void KingDrawer::draw(Graphics& gfx)
{
	mKing->draw(gfx);
	mKing->drawShape(gfx);
}
