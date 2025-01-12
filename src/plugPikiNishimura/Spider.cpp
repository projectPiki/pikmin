#include "Spider.h"
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
DEFINE_PRINT("Spider");

/*
 * --INFO--
 * Address:	80152794
 * Size:	0009C8
 */
SpiderProp::SpiderProp()
{
	mCreatureProps.mFriction.setValue(1.0f);
	mCreatureProps.mFaceDirAdjust.setValue(0.0f);
	mCreatureProps.mAcceleration.setValue(1.0f);
}

/*
 * --INFO--
 * Address:	8015315C
 * Size:	000140
 */
Spider::Spider(CreatureProp* props)
    : Boss(props)
{
	mCollInfo  = new CollInfo(24);
	mSpiderAi  = new SpiderAi(this);
	mSpiderLeg = new SpiderLeg(this);
	mShadowCaster.initCore("");
	mShadowCaster.initShadow();
	mSpiderDrawer = new SpiderDrawer(this);
}

/*
 * --INFO--
 * Address:	8015329C
 * Size:	000008
 */
f32 Spider::getiMass()
{
	return 0.1f;
}

/*
 * --INFO--
 * Address:	801532A4
 * Size:	0000C4
 */
void Spider::init(Vector3f&)
{
	mCollisionRadius = 64.0f;
	setInvincible(1);
	setIsOrganic(0);
	mIsBossBgm = false;
	_3B9       = 1;
	_3BA       = 0;
	_3BB       = 1;
	_3BC       = 0;
	mSpiderAi->initAI(this);
	mSpiderLeg->init(this);
	mHasShadow                      = false;
	mShadowCaster.mLightCamera.mFov = 35.0f;
	mCollInfo->makeTubesChild('leg1', 3);
	mCollInfo->makeTubesChild('leg2', 3);
	mCollInfo->makeTubesChild('leg3', 3);
	mCollInfo->makeTubesChild('leg4', 3);
}

/*
 * --INFO--
 * Address:	80153368
 * Size:	000058
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

/*
 * --INFO--
 * Address:	801533C0
 * Size:	000028
 */
void Spider::exitCourse()
{
	mSpiderLeg->killCallBackEffect(true);
}

/*
 * --INFO--
 * Address:	801533E8
 * Size:	00006C
 */
void Spider::update()
{
	doAI();
	mSpiderLeg->update();
	moveVelocity();
	moveNew(gsys->getFrameTime());
	doAnimation();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void Spider::draw(Graphics& gfx)
{
	Vector3f daySep = mapMgr->mDayMgr->_1408 - mPosition;
	daySep.y        = 0.0f;
	daySep.normalise();
	daySep.multiply(500.0f);

	mShadowCaster._37C.set(mSpiderLeg->_264.x + daySep.x, mPosition.y + 1200.0f, mSpiderLeg->_264.z + daySep.z);
	mShadowCaster._388.set(mSpiderLeg->_264.x, mPosition.y + 50.0f, mSpiderLeg->_264.z);

	mSpiderLeg->refresh(mShapeObject, gfx);
}

/*
 * --INFO--
 * Address:	80153454
 * Size:	00014C
 */
void Spider::refresh(Graphics& gfx)
{
	draw(gfx);
	mCollInfo->updateInfo(gfx, false);
}

/*
 * --INFO--
 * Address:	801535A0
 * Size:	000078
 */
void Spider::drawShape(Graphics& gfx)
{
	mShapeObject->mShape->calcWeightedMatrices();
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/*
 * --INFO--
 * Address:	80153618
 * Size:	000024
 */
void Spider::doAI()
{
	mSpiderAi->update();
}

/*
 * --INFO--
 * Address:	8015363C
 * Size:	000044
 */
void Spider::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/*
 * --INFO--
 * Address:	80153680
 * Size:	000160
 */
void SpiderDrawer::draw(Graphics& gfx)
{
	mSpider->draw(gfx);
	mSpider->drawShape(gfx);
}
