#include "Mizu.h"
#include "Collision.h"
#include "EffectMgr.h"
#include "Graphics.h"
#include "Shape.h"
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
DEFINE_PRINT("Mizu");

/*
 * --INFO--
 * Address:	8017B3D4
 * Size:	000090
 */
MizuProp::MizuProp()
{
	mCreatureProps.mFriction.mValue      = 1.0f;
	mCreatureProps.mFaceDirAdjust.mValue = 0.0f;
	mCreatureProps.mAcceleration.mValue  = 1.0f;
}

/*
 * --INFO--
 * Address:	8017B464
 * Size:	000084
 */
Mizu::Mizu(CreatureProp* props)
    : Boss(props)
{
	mCollInfo = new CollInfo(3);
	mMizuAi   = new MizuAi(this);
}

/*
 * --INFO--
 * Address:	8017B4E8
 * Size:	00005C
 */
bool Mizu::attackDefaultPortion()
{
	effectMgr->create(EffectMgr::EFF_Unk51, mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Unk50, mPosition, nullptr, nullptr);
	return true;
}

/*
 * --INFO--
 * Address:	8017B544
 * Size:	000008
 */
f32 Mizu::getiMass() { return 0.0001f; }

/*
 * --INFO--
 * Address:	8017B54C
 * Size:	000040
 */
void Mizu::initMizu(Vector3f&)
{
	mCollisionRadius = 10.0f;
	set2BE(1);
	set2E0(20.0f);
	mMizuAi->initMizu(this);
}

/*
 * --INFO--
 * Address:	8017B58C
 * Size:	000040
 */
void Mizu::initGeyzer(Vector3f&)
{
	mCollisionRadius = 10.0f;
	set2BE(1);
	set2E0(20.0f);
	mMizuAi->initGeyzer(this);
}

/*
 * --INFO--
 * Address:	8017B5CC
 * Size:	00004C
 */
void Mizu::doKill()
{
	set2B8(0);
	set2B9(0);
	mMizuAi->killCallBackEffect(false);
	bossMgr->kill(this);
}

/*
 * --INFO--
 * Address:	8017B618
 * Size:	000028
 */
void Mizu::exitCourse() { mMizuAi->killCallBackEffect(true); }

/*
 * --INFO--
 * Address:	8017B640
 * Size:	00004C
 */
void Mizu::update()
{
	doAI();
	doAnimation();
}

/*
 * --INFO--
 * Address:	8017B68C
 * Size:	000098
 */
void Mizu::refresh(Graphics& gfx)
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
 * Address:	8017B724
 * Size:	00006C
 */
void Mizu::drawShape(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/*
 * --INFO--
 * Address:	8017B790
 * Size:	000024
 */
void Mizu::doAI() { mMizuAi->update(); }

/*
 * --INFO--
 * Address:	8017B7B4
 * Size:	000044
 */
void Mizu::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getMotionSpeed());
	}
}
