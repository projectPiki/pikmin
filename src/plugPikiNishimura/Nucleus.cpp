#include "Nucleus.h"
#include "Collision.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Shape.h"
#include "sysNew.h"

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
DEFINE_PRINT("Nucleus");

NucleusProp::NucleusProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

Nucleus::Nucleus(CreatureProp* props)
    : Boss(props)
{
	mCollInfo  = new CollInfo(3);
	mNucleusAi = new NucleusAi(this);
}

f32 Nucleus::getiMass()
{
	return 0.01f;
}

void Nucleus::init(immut Vector3f&)
{
	mCollisionRadius = 20.0f;
	mSRT.s.set(0.0f, 0.0f, 0.0f);
	setIsAlive(0);
	setShadowNeed(1);
	setShadowSize(30.0f);
	mNucleusAi->initAI(this);
}

void Nucleus::doKill()
{
	setIsAlive(0);
	setIsAtari(0);
	bossMgr->kill(this);
}

void Nucleus::exitCourse()
{
}

void Nucleus::update()
{
	Creature::update();
}

void Nucleus::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	Matrix4f mtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
	mCollInfo->updateInfo(gfx, false);
}

void Nucleus::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

void Nucleus::doAI()
{
	mNucleusAi->update();
}

void Nucleus::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}
