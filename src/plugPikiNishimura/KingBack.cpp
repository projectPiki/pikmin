#include "Collision.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Graphics.h"
#include "King.h"
#include "MapMgr.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("KingBack");

/*
 * --INFO--
 * Address:	80179E08
 * Size:	000090
 */
KingBackProp::KingBackProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/*
 * --INFO--
 * Address:	80179E98
 * Size:	00006C
 */
KingBack::KingBack(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(4);
}

/*
 * --INFO--
 * Address:	80179F04
 * Size:	000008
 */
f32 KingBack::getiMass()
{
	return 0.0001f;
}

/*
 * --INFO--
 * Address:	80179F0C
 * Size:	00004C
 */
void KingBack::init(Vector3f&)
{
	mCollisionRadius = 20.0f;
	mIsOrganic       = false;
	mIsInvincible    = true;
	mPlatMgr.init(this, mapMgr, mShapeObject->mShape);
}

/*
 * --INFO--
 * Address:	80179F58
 * Size:	00003C
 */
void KingBack::doKill()
{
	mPlatMgr.release();
	bossMgr->kill(this);
}

/*
 * --INFO--
 * Address:	80179F94
 * Size:	000004
 */
void KingBack::exitCourse()
{
}

/*
 * --INFO--
 * Address:	80179F98
 * Size:	00004C
 */
void KingBack::update()
{
	doAI();
	doAnimation();
}

/*
 * --INFO--
 * Address:	80179FE4
 * Size:	0000A4
 */
void KingBack::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);

	Matrix4f mtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
	mCollInfo->updateInfo(gfx, false);
	mPlatMgr.update(gfx);
}

/*
 * --INFO--
 * Address:	8017A088
 * Size:	00006C
 */
void KingBack::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/*
 * --INFO--
 * Address:	8017A0F4
 * Size:	00001C
 */
void KingBack::doAI()
{
	mSRT.t.set(mInitPosition);
}

/*
 * --INFO--
 * Address:	8017A110
 * Size:	000044
 */
void KingBack::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}
}
