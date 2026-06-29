#include "Actor.h"
#include "DebugLog.h"
#include "SimpleAI.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C (Matching by size)
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0 (Matching by size)
 */
DEFINE_PRINT("actor") // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 000074 (Matching by size)
 */
Actor::Actor()
    : AICreature(nullptr)
{
	mSAICtx.mStateMachine = nullptr;
}

/**
 * @todo: Documentation
 */
void Actor::setType(int, PikiShapeObject* shape, CreatureProp* props, SimpleAI* ai)
{
	mProps               = props;
	mPikiShape           = shape;
	mPikiShape->mAnimMgr = PikiShapeObject::getAnimMgr();
	mPikiAnimMgr.init(mPikiShape->mAnimMgr, &mPikiShape->mAnimatorB, &mPikiShape->mAnimatorA, actorMgr->mMotionTable);

	mPikiAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Wait, nullptr), PaniMotionInfo(PIKIANIM_Wait));

	mSAICtx.mStateMachine = ai;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00002C (Matching by size)
 */
void Actor::startAI(int)
{
	C_SAI(this)->start(this, 0);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000E0 (Matching by size)
 */
void Actor::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	gfx.useMatrix(Matrix4f::ident, 0);

	Matrix4f mtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);

	mPikiAnimMgr.updateContext();
	f32 light = mapMgr->getLight(mSRT.t.x, mSRT.t.z);
	gfx.setLighting(true, nullptr);

	mPikiShape->mShape->updateAnim(gfx, mtx, nullptr);
	mPikiShape->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000040 (Matching by size)
 */
void Actor::update()
{
	doAnimation();
	updateAI();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000034 (Matching by size)
 */
void Actor::doAnimation()
{
	if (mPikiShape) {
		mPikiAnimMgr.updateAnimation(30.0f);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C (Matching by size)
 */
void Actor::doAI()
{
	if (mSAICtx.mStateMachine) {
		mSAICtx.mStateMachine->exec(this);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000034 (Matching by size)
 */
void Actor::doKill()
{
	mMgr->kill(this);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000080 (Matching by size)
 */
void Actor::startMotion(int motionIdx)
{
	mPikiAnimMgr.startMotion(PaniMotionInfo(motionIdx, this), PaniMotionInfo(motionIdx));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000094 (Matching by size)
 */
void Actor::startMotion(int motionIdx, f32 speed)
{
	mPikiAnimMgr.startMotion(PaniMotionInfo(motionIdx, this), PaniMotionInfo(motionIdx));
	mPikiAnimMgr.getUpperAnimator().mAnimationCounter = speed;
	mPikiAnimMgr.getLowerAnimator().mAnimationCounter = speed;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000034 (Matching by size)
 */
void Actor::finishMotion()
{
	mPikiAnimMgr.finishMotion(this);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000050 (Matching by size)
 */
void Actor::finishMotion(f32 speed)
{
	mPikiAnimMgr.finishMotion(this);
	mPikiAnimMgr.getUpperAnimator().mAnimationCounter = speed;
	mPikiAnimMgr.getLowerAnimator().mAnimationCounter = speed;
}
