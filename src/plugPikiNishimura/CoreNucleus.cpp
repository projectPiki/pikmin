#include "CoreNucleus.h"
#include "Collision.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Piki.h"
#include "PikiState.h"
#include "Shape.h"
#include "Slime.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("CoreNucleus");

/**
 * @todo: Documentation
 */
CoreNucleusProp::CoreNucleusProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/**
 * @todo: Documentation
 */
CoreNucleus::CoreNucleus(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(3);
	mCoreAi   = new CoreNucleusAi(this);
}

/**
 * @todo: Documentation
 */
f32 CoreNucleus::getiMass()
{
	return 0.01f;
}

/**
 * @todo: Documentation
 */
void CoreNucleus::init(immut Vector3f& pos)
{
	mCollisionRadius = 20.0f;
	mSRT.s.set(0.0f, 0.0f, 0.0f);
	setIsAlive(0);
	setIsOrganic(0);
	setShadowNeed(1);
	setShadowSize(40.0f);
	mCoreAi->initAI(this);
}

/**
 * @todo: Documentation
 */
void CoreNucleus::doKill()
{
	mIsAlive = 0;
	mIsAtari = 0;
	bossMgr->kill(this);
}

/**
 * @todo: Documentation
 */
void CoreNucleus::exitCourse()
{
}

/**
 * @todo: Documentation
 */
void CoreNucleus::update()
{
	Creature::update();
}

/**
 * @todo: Documentation
 */
void CoreNucleus::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	Matrix4f onCamMtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, onCamMtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, onCamMtx, nullptr);
	mCollInfo->updateInfo(gfx, false);
}

/**
 * @todo: Documentation
 */
void CoreNucleus::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/**
 * @todo: Documentation
 */
void CoreNucleus::doAI()
{
	mCoreAi->update();
}

/**
 * @todo: Documentation
 */
void CoreNucleus::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/**
 * @todo: Documentation
 */
void CoreNucleus::collisionCallback(immut CollEvent& event)
{
	if (event.mCollider->mObjType == OBJTYPE_Piki && static_cast<Piki*>(event.mCollider)->getState() == PIKISTATE_Flying) {
		mSlime->mDoCrashContract = true;
	}
}
