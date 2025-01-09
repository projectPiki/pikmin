#include "Slime.h"
#include "Graphics.h"
#include "Shape.h"
#include "Interactions.h"
#include "PlayerState.h"
#include "system.h"
#include "sysNew.h"
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
DEFINE_PRINT("Slime");

/*
 * --INFO--
 * Address:	80163714
 * Size:	000578
 */
SlimeProp::SlimeProp()
{
	mCreatureProps.mFriction.setValue(1.0f);
	mCreatureProps.mFaceDirAdjust.setValue(0.0f);
	mCreatureProps.mAcceleration.setValue(1.0f);
}

/*
 * --INFO--
 * Address:	80163C8C
 * Size:	0001D4
 */
Slime::Slime(CreatureProp* props, BossShapeObject* shape)
    : Boss(props)
{
	mShapeObject    = shape;
	mCollInfo       = new CollInfo(12);
	mSlimeCreatures = new SlimeCreature*[bossMgr->mSlimeCreatureCount];

	for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		mSlimeCreatures[i]           = new SlimeCreature(props);
		mSlimeCreatures[i]->mObjType = mObjType;
	}

	mCentreUpdater         = new BoundSphereUpdater(this);
	mCollideSphereUpdaters = new CollideSphereUpdater[bossMgr->mSlimeCreatureCount];
	mTubeSphereUpdaters    = new TubeSphereUpdater[bossMgr->mSlimeCreatureCount];

	mSlimeAi   = new SlimeAi(this);
	mSlimeBody = new SlimeBody(this);
}

/*
 * --INFO--
 * Address:	80163F08
 * Size:	00000C
 */
f32 Slime::getCentreSize() { return mCentreUpdater->mSize; }

/*
 * --INFO--
 * Address:	80163F14
 * Size:	000008
 */
f32 Slime::getiMass() { return 0.0001f; }

/*
 * --INFO--
 * Address:	80163F1C
 * Size:	00027C
 */
void Slime::init(Vector3f& pos)
{
	mCollisionRadius = 20.0f;
	setIsOrganic(0);
	_3C4 = 1;
	_3C5 = 0;
	_3C8 = 0;
	_3CC = bossMgr->mSlimeCreatureCount - 1;
	_3D0 = 0.0f;
	_3D4 = 0.0f;
	_3D8 = SLIME_PROP.mBodyThicknessContract(); // body thickness?
	_3DC = pos;
	_3E8 = pos;

	for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		mSlimeCreatures[i]->init(pos, this);
	}

	mSlimeAi->init(this);
	mSlimeBody->init(this);
	mCollInfo->setUpdater('cent', mCentreUpdater);

	mCollideSphereUpdaters[0].init(this, mSlimeCreatures[0]);
	mCollideSphereUpdaters[1].init(this, mSlimeCreatures[1]);
	mCollideSphereUpdaters[2].init(this, mSlimeCreatures[2]);
	mCollideSphereUpdaters[3].init(this, mSlimeCreatures[3]);

	mCollInfo->setUpdater('stk1', &mCollideSphereUpdaters[0]);
	mCollInfo->setUpdater('stk2', &mCollideSphereUpdaters[1]);
	mCollInfo->setUpdater('stk3', &mCollideSphereUpdaters[2]);
	mCollInfo->setUpdater('stk4', &mCollideSphereUpdaters[3]);

	mTubeSphereUpdaters[0].setSphere(mCollInfo->getSphere('stk1'));
	mTubeSphereUpdaters[1].setSphere(mCollInfo->getSphere('stk2'));
	mTubeSphereUpdaters[2].setSphere(mCollInfo->getSphere('stk3'));
	mTubeSphereUpdaters[3].setSphere(mCollInfo->getSphere('stk4'));

	mCollInfo->setUpdater('tub1', &mTubeSphereUpdaters[0]);
	mCollInfo->setUpdater('tub2', &mTubeSphereUpdaters[1]);
	mCollInfo->setUpdater('tub3', &mTubeSphereUpdaters[2]);
	mCollInfo->setUpdater('tub4', &mTubeSphereUpdaters[3]);

	mCollInfo->makeTubesChild('tub1', 3);
}

/*
 * --INFO--
 * Address:	80164198
 * Size:	000034
 */
void Slime::doKill()
{
	setIsAlive(0);
	setIsAtari(0);
	bossMgr->kill(this);
}

/*
 * --INFO--
 * Address:	801641CC
 * Size:	000004
 */
void Slime::exitCourse() { }

/*
 * --INFO--
 * Address:	801641D0
 * Size:	0000A4
 */
void Slime::update()
{
	doAI();
	for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		if (mSlimeCreatures[i]) {
			mSlimeCreatures[i]->update();
		}
	}

	moveVelocity();
	moveNew(gsys->getFrameTime());
}

/*
 * --INFO--
 * Address:	80164274
 * Size:	0000A8
 */
void Slime::refresh(Graphics& gfx)
{
	mTransformMatrix.makeSRT(mScale, mRotation, mPosition);
	Matrix4f onCamMtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mTransformMatrix, onCamMtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, onCamMtx, nullptr);
	mSlimeBody->refresh(mShapeObject, gfx);
	mCollInfo->updateInfo(gfx, false);
}

/*
 * --INFO--
 * Address:	8016431C
 * Size:	0000A0
 */
void Slime::drawShape(Graphics& gfx)
{
	doAnimation();
	gfx.useMatrix(Matrix4f::ident, 0);
	if (_3D4 > 0.0f) {
		mShapeObject->mShape->_13C |= 3;
		mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
	}
}

/*
 * --INFO--
 * Address:	801643BC
 * Size:	000024
 */
void Slime::doAI() { mSlimeAi->update(); }

/*
 * --INFO--
 * Address:	801643E0
 * Size:	000024
 */
void Slime::doAnimation() { mSlimeBody->update(); }

/*
 * --INFO--
 * Address:	80164404
 * Size:	000168
 */
void Slime::collisionCallback(CollEvent& event)
{
	if (event.mCollider->mObjType == OBJTYPE_Piki || event.mCollider->mObjType == OBJTYPE_Navi) {
		if (event.mCollider->isAlive() && event.mCollider->isVisible() && !event.mCollider->isBuried()) {
			if (event.mCollider->mObjType == OBJTYPE_Piki) {
				InteractBubble bubble(this, 200.0f);
				event.mCollider->stimulate(bubble);
			} else if (event.mCollider->mObjType == OBJTYPE_Navi) {
				InteractFlick flick(this, BOSS_PROP.mFlickKnockback(), BOSS_PROP.mFlickDamage(), FLICK_BACKWARDS_ANGLE);
				event.mCollider->stimulate(flick);
			}

			if (insideAndInSearch()) {
				playerState->mResultFlags.setOn(RESFLAG_Unk50);
			}
		}
	}
}

// this SOMEHOW needs to be at the start of CollideSphereUpdater::getSize
// rather than the end, so this is the work around
static f32 fakeFunc() { return 15.0f; }
