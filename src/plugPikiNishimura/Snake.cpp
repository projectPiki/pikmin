#include "Snake.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Shape.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Snake");

/**
 * @TODO: Documentation
 */
SnakeProp::SnakeProp()
{
	mCreatureProps.mFriction(1.0f);
	mCreatureProps.mFaceDirAdjust(0.0f);
	mCreatureProps.mAcceleration(1.0f);
}

/**
 * @TODO: Documentation
 */
Snake::Snake(CreatureProp* props)
    : Boss(props)
{
	mCollInfo      = new CollInfo(24);
	mBoundsUpdater = new BoundSphereUpdater(this);
	mSnakeAi       = new SnakeAi(this);
	mSnakeBody     = new SnakeBody(this);
}

/**
 * @TODO: Documentation
 */
void Snake::setBossType(bool type)
{
	mBossType = type;
}

/**
 * @TODO: Documentation
 */
f32 Snake::getCentreSize()
{
	return mBoundsUpdater->mSize;
}

/**
 * @TODO: Documentation
 */
f32 Snake::getiMass()
{
	return 0.0001f;
}

/**
 * @TODO: Documentation
 */
void Snake::init(immut Vector3f& pos)
{
	mCollisionRadius = 15.0f;
	setShadowSize(30.0f);
	mBossType      = true;
	_3C0           = mSRT.r.y;
	_3C4           = 0.0f;
	mSpawnPosition = pos;
	mSnakeAi->initAI(this);
	mSnakeBody->init(pos, this);
	mCollInfo->setUpdater('bnds', mBoundsUpdater);
	mCollInfo->makeTubesChild('tube', 7);
}

/**
 * @TODO: Documentation
 */
void Snake::doKill()
{
	setIsAlive(0);
	setIsAtari(0);
	mSnakeBody->killCallBackEffect(false);
	bossMgr->kill(this);
}

/**
 * @TODO: Documentation
 */
void Snake::exitCourse()
{
	mSnakeBody->killCallBackEffect(true);
}

/**
 * @TODO: Documentation
 */
void Snake::update()
{
	doAI();
	moveVelocity();
	moveNew(gsys->getFrameTime());
	doAnimation();
}

/**
 * @TODO: Documentation
 */
void Snake::refresh(Graphics& gfx)
{
	Matrix4f onCamMtx;
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, onCamMtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, onCamMtx, nullptr);
	mSnakeBody->refresh(mShapeObject, gfx);
	mCollInfo->updateInfo(gfx, false);
}

/**
 * @TODO: Documentation
 */
void Snake::drawShape(Graphics& gfx)
{
	mShapeObject->mShape->calcWeightedMatrices();
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/**
 * @TODO: Documentation
 */
void Snake::refresh2d(Graphics& gfx)
{
	mLifeGauge.mPosition = mSRT.t;
	mLifeGauge.mPosition.y += BOSS_PROP.mLifeGaugeHeight();
	mLifeGauge.mScale = BOSS_PROP.mLifeGaugeScale() * _3C4 / gfx.mCamera->mNear;
	mLifeGauge.refresh(gfx);
}

/**
 * @TODO: Documentation
 */
void Snake::doAI()
{
	mSnakeAi->update();
}

/**
 * @TODO: Documentation
 */
void Snake::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}

	mSnakeBody->update();
}
