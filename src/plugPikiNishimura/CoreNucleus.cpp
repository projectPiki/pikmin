#include "CoreNucleus.h"
#include "Collision.h"
#include "Graphics.h"
#include "Piki.h"
#include "Shape.h"
#include "Slime.h"
#include "PikiState.h"
#include "DebugLog.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("CoreNucleus");

/*
 * --INFO--
 * Address:	8017A954
 * Size:	000090
 */
CoreNucleusProp::CoreNucleusProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/*
 * --INFO--
 * Address:	8017A9E4
 * Size:	000084
 */
CoreNucleus::CoreNucleus(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(3);
	mCoreAi   = new CoreNucleusAi(this);
}

/*
 * --INFO--
 * Address:	8017AA68
 * Size:	000008
 */
f32 CoreNucleus::getiMass()
{
	return 0.01f;
}

/*
 * --INFO--
 * Address:	8017AA70
 * Size:	000064
 */
void CoreNucleus::init(Vector3f& pos)
{
	mCollisionRadius = 20.0f;
	mScale.set(0.0f, 0.0f, 0.0f);
	setIsAlive(0);
	setIsOrganic(0);
	setShadowNeed(1);
	setShadowSize(40.0f);
	mCoreAi->initAI(this);
}

/*
 * --INFO--
 * Address:	8017AAD4
 * Size:	000034
 */
void CoreNucleus::doKill()
{
	mIsAlive = 0;
	mIsAtari = 0;
	bossMgr->kill(this);
}

/*
 * --INFO--
 * Address:	8017AB08
 * Size:	000004
 */
void CoreNucleus::exitCourse()
{
}

/*
 * --INFO--
 * Address:	8017AB0C
 * Size:	000020
 */
void CoreNucleus::update()
{
	Creature::update();
}

/*
 * --INFO--
 * Address:	8017AB2C
 * Size:	000098
 */
void CoreNucleus::refresh(Graphics& gfx)
{
	mTransformMatrix.makeSRT(mScale, mRotation, mPosition);
	Matrix4f onCamMtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mTransformMatrix, onCamMtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, onCamMtx, nullptr);
	mCollInfo->updateInfo(gfx, false);
}

/*
 * --INFO--
 * Address:	8017ABC4
 * Size:	00006C
 */
void CoreNucleus::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/*
 * --INFO--
 * Address:	8017AC30
 * Size:	000024
 */
void CoreNucleus::doAI()
{
	mCoreAi->update();
}

/*
 * --INFO--
 * Address:	8017AC54
 * Size:	000044
 */
void CoreNucleus::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/*
 * --INFO--
 * Address:	8017AC98
 * Size:	000054
 */
void CoreNucleus::collisionCallback(CollEvent& event)
{
	if (event.mCollider->mObjType == OBJTYPE_Piki && static_cast<Piki*>(event.mCollider)->getState() == PIKISTATE_Flying) {
		mSlime->mDoCrashContract = true;
	}
}
