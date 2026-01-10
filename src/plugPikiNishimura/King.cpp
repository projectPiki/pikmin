#include "King.h"
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
DEFINE_PRINT("King");

/**
 * @todo: Documentation
 */
KingProp::KingProp()
{
	mCreatureProps.mFriction(1.0f);
	mCreatureProps.mFaceDirAdjust(0.0f);
	mCreatureProps.mAcceleration(1.0f);
}

/**
 * @todo: Documentation
 */
King::King(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(38);
	mKingAi   = new KingAi(this);
	mKingBody = new KingBody(this);
	mShadowCaster.initCore("");
	mShadowCaster.initShadow();
	mShadowCaster.mShadowDrawer = new KingDrawer(this);
}

/**
 * @todo: Documentation
 */
f32 King::getiMass()
{
	return 0.0001f;
}

/**
 * @todo: Documentation
 */
void King::bombDamageCounter(CollPart*)
{
	if (getCurrentState() == KINGAI_Attack) {
		mKingAi->mBombDamageCounter++;
	}
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void King::doKill()
{
	setIsAlive(false);
	setIsAtari(false);
	mIsBossBgm = false;
	mKingBody->killCallBackEffect(false);
	mPlatMgr.release();
	mShadowCaster.del();
	bossMgr->kill(this);
}

/**
 * @todo: Documentation
 */
void King::exitCourse()
{
	mKingBody->killCallBackEffect(true);
}

/**
 * @todo: Documentation
 */
void King::update()
{
	doAI();
	moveVelocity();
	moveNew(gsys->getFrameTime());
	doAnimation();
}

/**
 * @todo: Documentation
 */
void King::draw(Graphics& gfx)
{
	Vector3f lightDirection = mapMgr->mDayMgr->mCurrentSunPosition - mSRT.t;
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
 * @todo: Documentation
 */
void King::refresh(Graphics& gfx)
{
	draw(gfx);
	mCollInfo->updateInfo(gfx, false);
	mPlatMgr.update(gfx);
}

/**
 * @todo: Documentation
 */
void King::drawShape(Graphics& gfx)
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
		mWorldMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
		gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, transformMtx);

		// This is certainly *one* way of doing things.
		if (getCurrentState() != KINGAI_Stay) {
			gfx.setColour(Colour(255, 255, 0, 255), true);
			gfx.drawSphere(mSRT.t, KING_PROP.mHiddenUnderneathRadius(), transformMtx);
		}
		if (getCurrentState() == KINGAI_Attack && mKingAi->mIsTongueOut) {
			Vector3f a(mCollInfo->getSphere('slt2')->mCentre);
			Vector3f b(mCollInfo->getSphere('slt2')->mCentre);
			a.y -= KING_PROP.mTongueRangeY();
			b.y += KING_PROP.mTongueRangeY();

			gfx.setColour(Colour(0, 0, 255, 255), true);
			gfx.drawCylinder(a, b, KING_PROP.mTongueRangeXZ(), transformMtx);
		}
		if (getCurrentState() == KINGAI_Flick) {
			gfx.setColour(Colour(0, 0, 255, 255), true);
			gfx.drawSphere(mSRT.t, KING_PROP.mPressAttackRadius(), transformMtx);
		}
		if (getCurrentState() == KINGAI_Stay) {
			gfx.setColour(Colour(255, 0, 0, 255), true);
			gfx.drawSphere(mSRT.t, KING_PROP.mDetectionRadius(), transformMtx);
		}
		if (getCurrentState() == KINGAI_Stay) {
			gfx.setColour(Colour(0, 255, 255, 255), true);
			gfx.drawSphere(mSRT.t, KING_PROP.mDispelRadius(), transformMtx);
		}
		if (getCurrentState() != KINGAI_Stay) {
			Vector3f a(mKingAi->mAttackPosition.x, mKingAi->mAttackPosition.y + KING_PROP.mNormalAttackRangeY(),
			           mKingAi->mAttackPosition.z);
			Vector3f b(mKingAi->mAttackPosition.x, mKingAi->mAttackPosition.y - KING_PROP.mNormalAttackRangeY(),
			           mKingAi->mAttackPosition.z);

			gfx.setColour(Colour(255, 0, 0, 255), true);
			gfx.drawCylinder(a, b, KING_PROP.mNormalAttackRangeXZ(), transformMtx);
		}
		if (getCurrentState() != KINGAI_Stay) {
			gfx.setColour(Colour(255, 255, 255, 255), true);
			gfx.drawSphere(*getInitPosition(), KING_PROP.mAttackTerritoryRadius(), transformMtx);
		}
		if (getCurrentState() == KINGAI_Attack) {
			Vector3f centre(mCollInfo->getSphere('slt2')->mCentre);
			centre.x += sinf(mFaceDirection) * KING_PROP._314();
			centre.y += KING_PROP._324();
			centre.z += cosf(mFaceDirection) * KING_PROP._314();

			gfx.setColour(Colour(255, 255, 255, 255), true);
			gfx.drawSphere(centre, KING_PROP._334(), transformMtx);
		}
		if (getCurrentState() == KINGAI_Attack && !mKingAi->mIsTongueOut) {
			CollPart* collPart = mCollInfo->getSphere('slt3');

			Vector3f centre(collPart->mCentre);
			centre.x += sinf(mFaceDirection) * 30.0f;
			centre.y += 15.0f;
			centre.z += cosf(mFaceDirection) * 30.0f;

			gfx.setColour(Colour(0, 255, 0, 255), true);
			gfx.drawSphere(centre, collPart->mRadius, transformMtx);
		}
	}
#endif
}

/**
 * @todo: Documentation
 */
void King::doAI()
{
	mKingAi->update();
}

/**
 * @todo: Documentation
 */
void King::doAnimation()
{
	mKingBody->update();
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/**
 * @todo: Documentation
 */
void KingDrawer::draw(Graphics& gfx)
{
	mKing->draw(gfx);
	mKing->drawShape(gfx);
}
