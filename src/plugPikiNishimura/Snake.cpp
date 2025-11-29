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

/*
 * --INFO--
 * Address:	8015A2C4
 * Size:	0008F0
 */
SnakeProp::SnakeProp()
{
	mCreatureProps.mFriction(1.0f);
	mCreatureProps.mFaceDirAdjust(0.0f);
	mCreatureProps.mAcceleration(1.0f);
}

/*
 * --INFO--
 * Address:	8015ABB4
 * Size:	000104
 */
Snake::Snake(CreatureProp* props)
    : Boss(props)
{
	mCollInfo      = new CollInfo(24);
	mBoundsUpdater = new BoundSphereUpdater(this);
	mSnakeAi       = new SnakeAi(this);
	mSnakeBody     = new SnakeBody(this);
}

/*
 * --INFO--
 * Address:	8015ACB8
 * Size:	000008
 */
void Snake::setBossType(bool type)
{
	mBossType = type;
}

/*
 * --INFO--
 * Address:	8015ACC0
 * Size:	00000C
 */
f32 Snake::getCentreSize()
{
	return mBoundsUpdater->mSize;
}

/*
 * --INFO--
 * Address:	8015ACCC
 * Size:	000008
 */
f32 Snake::getiMass()
{
	return 0.0001f;
}

/*
 * --INFO--
 * Address:	8015ACD4
 * Size:	0000B8
 */
void Snake::init(Vector3f& pos)
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

/*
 * --INFO--
 * Address:	8015AD8C
 * Size:	00004C
 */
void Snake::doKill()
{
	setIsAlive(0);
	setIsAtari(0);
	mSnakeBody->killCallBackEffect(false);
	bossMgr->kill(this);
}

/*
 * --INFO--
 * Address:	8015ADD8
 * Size:	000028
 */
void Snake::exitCourse()
{
	mSnakeBody->killCallBackEffect(true);
}

/*
 * --INFO--
 * Address:	8015AE00
 * Size:	000064
 */
void Snake::update()
{
	doAI();
	moveVelocity();
	moveNew(gsys->getFrameTime());
	doAnimation();
}

/*
 * --INFO--
 * Address:	8015AE64
 * Size:	0000A8
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

/*
 * --INFO--
 * Address:	8015AF0C
 * Size:	000078
 */
void Snake::drawShape(Graphics& gfx)
{
	mShapeObject->mShape->calcWeightedMatrices();
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/*
 * --INFO--
 * Address:	8015AF84
 * Size:	000074
 */
void Snake::refresh2d(Graphics& gfx)
{
	mLifeGauge.mPosition = mSRT.t;
	mLifeGauge.mPosition.y += BOSS_PROP.mLifeGaugeHeight();
	mLifeGauge.mScale = BOSS_PROP.mLifeGaugeScale() * _3C4 / gfx.mCamera->mNear;
	mLifeGauge.refresh(gfx);
}

/*
 * --INFO--
 * Address:	8015AFF8
 * Size:	000024
 */
void Snake::doAI()
{
	mSnakeAi->update();
}

/*
 * --INFO--
 * Address:	8015B01C
 * Size:	000054
 */
void Snake::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}

	mSnakeBody->update();
}
