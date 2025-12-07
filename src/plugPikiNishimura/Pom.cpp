#include "Pom.h"
#include "Collision.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "NsMath.h"
#include "Piki.h"
#include "Shape.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("Pom");

/*
 * --INFO--
 * Address:	80177DE0
 * Size:	0002B4
 */
PomProp::PomProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/*
 * --INFO--
 * Address:	80178094
 * Size:	000098
 */
Pom::Pom(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(16);
	mPomAi    = new PomAi(this);
}

/*
 * --INFO--
 * Address:	8017812C
 * Size:	000008
 */
f32 Pom::getiMass()
{
	return 0.0001f;
}

/*
 * --INFO--
 * Address:	80178134
 * Size:	000050
 */
void Pom::init(immut Vector3f&)
{
	mCollisionRadius        = 20.0f;
	mIsOrganic              = false;
	mIsInvincible           = true;
	mNeedShadow             = true;
	mShadowSize             = 50.0f;
	mIsPikiOrPlayerTouching = false;
	mPomAi->initAI(this);
}

/*
 * --INFO--
 * Address:	80178184
 * Size:	00009C
 */
void Pom::setColor(int color)
{
	mColor = color;
	if (mColor < PikiMinColor || mColor > PikiMaxColor) {
		mColor = NsMathI::getRand(3);
	}

	mShapeObject->mShape->makeInstance(mDynMaterial, 0);
}

/*
 * --INFO--
 * Address:	80178220
 * Size:	00004C
 */
void Pom::doKill()
{
	mIsAlive = 0;
	mIsAtari = 0;
	mPomAi->killCallBackEffect(false);
	bossMgr->kill(this);
}

/*
 * --INFO--
 * Address:	8017826C
 * Size:	000028
 */
void Pom::exitCourse()
{
	mPomAi->killCallBackEffect(true);
}

/*
 * --INFO--
 * Address:	80178294
 * Size:	00004C
 */
void Pom::update()
{
	doAI();
	doAnimation();
}

/*
 * --INFO--
 * Address:	801782E0
 * Size:	0000E0
 */
void Pom::refresh(Graphics& gfx)
{
	if (isAlive()) {
		mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
		Matrix4f mtx;
		gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
		mAnimator.updateContext();

		f32 dynAnimType = mColor;
		mDynMaterial.animate(&dynAnimType);
		mShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
		mCollInfo->updateInfo(gfx, false);
	}
}

/*
 * --INFO--
 * Address:	801783C0
 * Size:	000084
 */
void Pom::drawShape(Graphics& gfx)
{
	if (isAlive()) {
		gfx.useMatrix(Matrix4f::ident, 0);
		mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, &mDynMaterial);
	}
}

/*
 * --INFO--
 * Address:	80178444
 * Size:	000024
 */
void Pom::doAI()
{
	mPomAi->update();
}

/*
 * --INFO--
 * Address:	80178468
 * Size:	000044
 */
void Pom::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}

/*
 * --INFO--
 * Address:	801784AC
 * Size:	000054
 */
void Pom::collisionCallback(immut CollEvent& event)
{
	if (event.mCollider->mObjType == OBJTYPE_Piki || event.mCollider->mObjType == OBJTYPE_Navi) {
		if (!mIsPikiOrPlayerTouching) {
			mIsPikiOrPlayerTouching = true;
		}

		mPomAi->collidePetal(event.mCollider);
	}
}
