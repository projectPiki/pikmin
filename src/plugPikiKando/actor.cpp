#include "Actor.h"
#include "DebugLog.h"
#include "SimpleAI.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000074
 */
Actor::Actor()
    : AICreature(nullptr)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void Actor::setType(int, PikiShapeObject* shape, CreatureProp* props, SimpleAI* ai)
{
	mProps               = props;
	mPikiShape           = shape;
	mPikiShape->mAnimMgr = PikiShapeObject::getAnimMgr();
	mPikiAnimMgr.init(mPikiShape->mAnimMgr, &mPikiShape->mAnimatorB, &mPikiShape->mAnimatorA, actorMgr->mMotionTable);

	mPikiAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Wait, nullptr), PaniMotionInfo(PIKIANIM_Wait));

	mStateMachine = ai;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00002C
 */
void Actor::startAI(int state)
{
	((SimpleAI*)mStateMachine)->start(this, state);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000E0
 */
void Actor::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	gfx.useMatrix(Matrix4f::ident, 0);

	Matrix4f mtx;
	mtx.multiplyTo(gfx.mCamera->mLookAtMtx, mWorldMtx);

	mPikiAnimMgr.updateContext();
	mapMgr->getLight(mSRT.t.x, mSRT.t.z);

	gfx.initRender(1, 0);

	mPikiShape->mShape->updateAnim(gfx, mtx, nullptr);
	mPikiShape->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void Actor::update()
{
	doAnimation();
	updateAI();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void Actor::doAnimation()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void Actor::doAI()
{
	if (mStateMachine) {
		mStateMachine->exec(this);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void Actor::doKill()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000080
 */
void Actor::startMotion(int)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000094
 */
void Actor::startMotion(int, f32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void Actor::finishMotion()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000050
 */
void Actor::finishMotion(f32)
{
	// UNUSED FUNCTION
}
