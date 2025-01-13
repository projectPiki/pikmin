#include "King.h"
#include "DayMgr.h"
#include "Graphics.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("King");

/*
 * --INFO--
 * Address:	8016B4A4
 * Size:	0007BC
 */
KingProp::KingProp()
{
	mCreatureProps.mFriction.setValue(1.0f);
	mCreatureProps.mFaceDirAdjust.setValue(0.0f);
	mCreatureProps.mAcceleration.setValue(1.0f);
}

/*
 * --INFO--
 * Address:	8016BC60
 * Size:	000148
 */
King::King(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(38);
	mKingAi   = new KingAi(this);
	mKingBody = new KingBody(this);
	mShadowCaster.initCore("");
	mShadowCaster.initShadow();
	mKingDrawer = new KingDrawer(this);
}

/*
 * --INFO--
 * Address:	8016BDA8
 * Size:	000008
 */
f32 King::getiMass()
{
	return 0.0001f;
}

/*
 * --INFO--
 * Address:	8016BDB0
 * Size:	000020
 */
void King::bombDamageCounter(CollPart*)
{
	if (getCurrentState() == KINGAI_Attack) {
		mKingAi->mBombDamageCounter++;
	}
}

/*
 * --INFO--
 * Address:	8016BDD0
 * Size:	000084
 */
void King::init(Vector3f&)
{
	mCollisionRadius = 50.0f;
	setInvincible(1);
	setIsOrganic(0);
	setShadowSize(150.0f);
	mIsBossBgm = false;
	mKingAi->initAI(this);
	mKingBody->init(this);
	mShadowCaster.mLightCamera.mFov = 35.0f;
	mPlatMgr.init(this, mapMgr, mShapeObject->mShape);
}

/*
 * --INFO--
 * Address:	8016BE54
 * Size:	000060
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

/*
 * --INFO--
 * Address:	8016BEB4
 * Size:	000028
 */
void King::exitCourse()
{
	mKingBody->killCallBackEffect(true);
}

/*
 * --INFO--
 * Address:	8016BEDC
 * Size:	000064
 */
void King::update()
{
	doAI();
	moveVelocity();
	moveNew(gsys->getFrameTime());
	doAnimation();
}

/*
 * --INFO--
 * Address:	8016BF40
 * Size:	000178
 */
void King::draw(Graphics& gfx)
{
	Vector3f lightDirection = mapMgr->mDayMgr->mSunPosition - mPosition;
	lightDirection.y        = 0.0f;
	lightDirection.normalise();
	lightDirection.multiply(150.0f);

	Vector3f centre = mCollInfo->getBoundingSphere()->mCentre;
	f32 yDiff       = centre.y - mPosition.y;
	if (yDiff > 0.0f) {
		centre.y += yDiff * 3.0f;
	}

	mShadowCaster.mSourcePosition.set(centre.x + lightDirection.x, centre.y + 1000.0f, centre.z + lightDirection.z);
	mShadowCaster.mTargetPosition.set(mPosition.x, mPosition.y + 50.0f, mPosition.z);

	Matrix4f viewMatrix;
	mTransformMatrix.makeSRT(mScale, mRotation, mPosition);
	gfx.mCamera->mLookAtMtx.multiplyTo(mTransformMatrix, viewMatrix);

	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, viewMatrix, nullptr);
	mKingBody->refresh(mShapeObject, gfx);
}

/*
 * --INFO--
 * Address:	8016C0B8
 * Size:	000054
 */
void King::refresh(Graphics& gfx)
{
	draw(gfx);
	mCollInfo->updateInfo(gfx, false);
	mPlatMgr.update(gfx);
}

/*
 * --INFO--
 * Address:	8016C10C
 * Size:	000078
 */
void King::drawShape(Graphics& gfx)
{
	mShapeObject->mShape->calcWeightedMatrices();
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/*
 * --INFO--
 * Address:	8016C184
 * Size:	000024
 */
void King::doAI()
{
	mKingAi->update();
}

/*
 * --INFO--
 * Address:	8016C1A8
 * Size:	000054
 */
void King::doAnimation()
{
	mKingBody->update();
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/*
 * --INFO--
 * Address:	8016C1FC
 * Size:	000054
 */
void KingDrawer::draw(Graphics& gfx)
{
	mKing->draw(gfx);
	mKing->drawShape(gfx);
}
