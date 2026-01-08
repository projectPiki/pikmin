#include "Nucleus.h"
#include "Collision.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Shape.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Nucleus");

/**
 * @todo: Documentation
 */
NucleusProp::NucleusProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/**
 * @todo: Documentation
 */
Nucleus::Nucleus(CreatureProp* props)
    : Boss(props)
{
	mCollInfo  = new CollInfo(3);
	mNucleusAi = new NucleusAi(this);
}

/**
 * @todo: Documentation
 */
f32 Nucleus::getiMass()
{
	return 0.01f;
}

/**
 * @todo: Documentation
 */
void Nucleus::init(immut Vector3f&)
{
	mCollisionRadius = 20.0f;
	mSRT.s.set(0.0f, 0.0f, 0.0f);
	setIsAlive(false);
	setShadowNeed(true);
	setShadowSize(30.0f);
	mNucleusAi->initAI(this);
}

/**
 * @todo: Documentation
 */
void Nucleus::doKill()
{
	setIsAlive(false);
	setIsAtari(false);
	bossMgr->kill(this);
}

/**
 * @todo: Documentation
 */
void Nucleus::exitCourse()
{
}

/**
 * @todo: Documentation
 */
void Nucleus::update()
{
	Creature::update();
}

/**
 * @todo: Documentation
 */
void Nucleus::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	Matrix4f mtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
	mCollInfo->updateInfo(gfx, false);
}

/**
 * @todo: Documentation
 */
void Nucleus::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/**
 * @todo: Documentation
 */
void Nucleus::doAI()
{
	mNucleusAi->update();
}

/**
 * @todo: Documentation
 */
void Nucleus::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}
