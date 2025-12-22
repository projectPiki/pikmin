#include "Slime.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Interactions.h"
#include "PlayerState.h"
#include "Shape.h"
#include "sysNew.h"
#include "system.h"

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
DEFINE_PRINT("Slime");

/**
 * @TODO: Documentation
 */
SlimeProp::SlimeProp()
{
	mCreatureProps.mFriction(1.0f);
	mCreatureProps.mFaceDirAdjust(0.0f);
	mCreatureProps.mAcceleration(1.0f);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
f32 Slime::getCentreSize()
{
	return mCentreUpdater->mSize;
}

/**
 * @TODO: Documentation
 */
f32 Slime::getiMass()
{
	return 0.0001f;
}

/**
 * @TODO: Documentation
 */
void Slime::init(immut Vector3f& pos)
{
	mCollisionRadius = 20.0f;
	setIsOrganic(0);
	mIsMoveLeader          = true;
	mDoCrashContract       = false;
	mLeaderCreatureIndex   = SLIMECREATURE_CoreOuter;
	mFollowerCreatureIndex = bossMgr->mSlimeCreatureCount - 1;
	mLeaderSpeed           = 0.0f;
	mAppearanceScale       = 0.0f;
	mBodyThickness         = SLIME_PROP.mBodyThicknessContract(); // body thickness?
	mNucleusPosition       = pos;
	mCorePosition          = pos;

	for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		mSlimeCreatures[i]->init(pos, this);
	}

	mSlimeAi->init(this);
	mSlimeBody->init(this);
	mCollInfo->setUpdater('cent', mCentreUpdater);

	mCollideSphereUpdaters[SLIMECREATURE_CoreOuter].init(this, mSlimeCreatures[SLIMECREATURE_CoreOuter]);
	mCollideSphereUpdaters[SLIMECREATURE_CoreInner].init(this, mSlimeCreatures[SLIMECREATURE_CoreInner]);
	mCollideSphereUpdaters[SLIMECREATURE_NucleusInner].init(this, mSlimeCreatures[SLIMECREATURE_NucleusInner]);
	mCollideSphereUpdaters[SLIMECREATURE_NucleusOuter].init(this, mSlimeCreatures[SLIMECREATURE_NucleusOuter]);

	mCollInfo->setUpdater('stk1', &mCollideSphereUpdaters[SLIMECREATURE_CoreOuter]);
	mCollInfo->setUpdater('stk2', &mCollideSphereUpdaters[SLIMECREATURE_CoreInner]);
	mCollInfo->setUpdater('stk3', &mCollideSphereUpdaters[SLIMECREATURE_NucleusInner]);
	mCollInfo->setUpdater('stk4', &mCollideSphereUpdaters[SLIMECREATURE_NucleusOuter]);

	mTubeSphereUpdaters[SLIMECREATURE_CoreOuter].setSphere(mCollInfo->getSphere('stk1'));
	mTubeSphereUpdaters[SLIMECREATURE_CoreInner].setSphere(mCollInfo->getSphere('stk2'));
	mTubeSphereUpdaters[SLIMECREATURE_NucleusInner].setSphere(mCollInfo->getSphere('stk3'));
	mTubeSphereUpdaters[SLIMECREATURE_NucleusOuter].setSphere(mCollInfo->getSphere('stk4'));

	mCollInfo->setUpdater('tub1', &mTubeSphereUpdaters[SLIMECREATURE_CoreOuter]);
	mCollInfo->setUpdater('tub2', &mTubeSphereUpdaters[SLIMECREATURE_CoreInner]);
	mCollInfo->setUpdater('tub3', &mTubeSphereUpdaters[SLIMECREATURE_NucleusInner]);
	mCollInfo->setUpdater('tub4', &mTubeSphereUpdaters[SLIMECREATURE_NucleusOuter]);

	mCollInfo->makeTubesChild('tub1', 3);
}

/**
 * @TODO: Documentation
 */
void Slime::doKill()
{
	setIsAlive(0);
	setIsAtari(0);
	bossMgr->kill(this);
}

/**
 * @TODO: Documentation
 */
void Slime::exitCourse()
{
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void Slime::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	Matrix4f onCamMtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, onCamMtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, onCamMtx, nullptr);
	mSlimeBody->refresh(mShapeObject, gfx);
	mCollInfo->updateInfo(gfx, false);
}

/**
 * @TODO: Documentation
 */
void Slime::drawShape(Graphics& gfx)
{
	doAnimation();
	gfx.useMatrix(Matrix4f::ident, 0);
	if (mAppearanceScale > 0.0f) {
		mShapeObject->mShape->mVertexCacheFlags |= (VertexCacheFlags::VertexList | VertexCacheFlags::NormalList);
		mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
	}
}

/**
 * @TODO: Documentation
 */
void Slime::doAI()
{
	mSlimeAi->update();
}

/**
 * @TODO: Documentation
 */
void Slime::doAnimation()
{
	mSlimeBody->update();
}

/**
 * @TODO: Documentation
 */
void Slime::collisionCallback(immut CollEvent& event)
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
				playerState->mResultFlags.setOn(RESFLAG_Slime);
			}
		}
	}
}

// this SOMEHOW needs to be at the start of CollideSphereUpdater::getSize
// rather than the end, so this is the work around
static f32 fakeFunc()
{
	return 15.0f;
}
