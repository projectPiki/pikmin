#include "Snake.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Shape.h"

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
DEFINE_PRINT("Snake");

SnakeProp::SnakeProp()
{
	mCreatureProps.mFriction(1.0f);
	mCreatureProps.mFaceDirAdjust(0.0f);
	mCreatureProps.mAcceleration(1.0f);
}

Snake::Snake(CreatureProp* props)
    : Boss(props)
{
	mCollInfo      = new CollInfo(24);
	mBoundsUpdater = new BoundSphereUpdater(this);
	mSnakeAi       = new SnakeAi(this);
	mSnakeBody     = new SnakeBody(this);
}

void Snake::setBossType(bool type)
{
	mBossType = type;
}

f32 Snake::getCentreSize()
{
	return mBoundsUpdater->mSize;
}

f32 Snake::getiMass()
{
	return 0.0001f;
}

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

void Snake::doKill()
{
	setIsAlive(0);
	setIsAtari(0);
	mSnakeBody->killCallBackEffect(false);
	bossMgr->kill(this);
}

void Snake::exitCourse()
{
	mSnakeBody->killCallBackEffect(true);
}

void Snake::update()
{
	doAI();
	moveVelocity();
	moveNew(gsys->getFrameTime());
	doAnimation();
}

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

void Snake::drawShape(Graphics& gfx)
{
	mShapeObject->mShape->calcWeightedMatrices();
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

void Snake::refresh2d(Graphics& gfx)
{
	mLifeGauge.mPosition = mSRT.t;
	mLifeGauge.mPosition.y += BOSS_PROP.mLifeGaugeHeight();
	mLifeGauge.mScale = BOSS_PROP.mLifeGaugeScale() * _3C4 / gfx.mCamera->mNear;
	mLifeGauge.refresh(gfx);
}

void Snake::doAI()
{
	mSnakeAi->update();
}

void Snake::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}

	mSnakeBody->update();
}
