#include "DualCreature.h"
#include "Graphics.h"
#include "ItemMgr.h"
#include "MapMgr.h"
#include "NaviMgr.h"
#include "Kontroller.h"
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
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	80091EC0
 * Size:	000094
 */
DualCreature::DualCreature()
{
	_43D = 0;
	setCreatureFlag(CF_Unk1 | CF_Unk10);
	_D4.set(0.0f, 0.0f, 0.0f);
	_2B8.set(0.0f, 0.0f, 0.0f);
	useRealDynamics();
	setDynamicsSimpleFixed(false);
}

/*
 * --INFO--
 * Address:	80091F54
 * Size:	000034
 */
void DualCreature::doKill()
{
	DynCreature::doKill();
	_43D = 0;
}

/*
 * --INFO--
 * Address:	80091F88
 * Size:	000060
 */
bool DualCreature::isFrontFace()
{
	if (mIsRealDynamics) {
		Vector3f yVec;
		_E0.genVectorY(yVec);
		return yVec.y > 0.5f;
	}

	return true;
}

/*
 * --INFO--
 * Address:	80091FE8
 * Size:	000050
 */
f32 DualCreature::getY()
{
	if (mIsRealDynamics) {
		Vector3f yVec;
		_E0.genVectorY(yVec);
		return yVec.y;
	}

	return 1.0f;
}

/*
 * --INFO--
 * Address:	80092038
 * Size:	000054
 */
bool DualCreature::onGround()
{
	if (mIsRealDynamics) {
		if (isCreatureFlag(CF_IsOnGround)) {
			return true;
		}
		if (getGroundFlag()) {
			return true;
		}

		return false;
	}

	return isCreatureFlag(CF_IsOnGround) != 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void DualCreature::createCollisions(Graphics& gfx)
{
	if (!_43D) {
		releaseAllParticles();
		_43D = 1;
		_2F4 = 0.0f;
		doCreateColls(gfx);
		initialiseSystem();
	}
}

/*
 * --INFO--
 * Address:	8009208C
 * Size:	000050
 */
void DualCreature::useRealDynamics()
{
	if (!mIsDynamicsSimpleFixed) {
		_43E            = 1;
		mIsRealDynamics = true;
		_E0.fromEuler(mRotation);
	} else {
		useSimpleDynamics();
	}
}

/*
 * --INFO--
 * Address:	800920DC
 * Size:	000044
 */
void DualCreature::useSimpleDynamics()
{
	_43E            = 1;
	mIsRealDynamics = false;
	_D4.set(0.0f, 0.0f, 0.0f);
	_2B8.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80092120
 * Size:	0000C4
 */
void DualCreature::rotateY(f32 rotY)
{
	if (mIsRealDynamics) {
		Quat q1;
		q1.fromEuler(Vector3f(0.0f, rotY, 0.0f));
		q1.multiply(_E0);
		_E0 = q1;
		_E0.normalise();
	} else {
		mDirection = roundAng(mDirection + rotY);
		mRotation.set(0.0f, mDirection, 0.0f);
	}
}

/*
 * --INFO--
 * Address:	800921E4
 * Size:	000034
 */
void DualCreature::update()
{
	if (mIsRealDynamics) {
		DynCreature::update();
	} else {
		Creature::update();
	}
}

/*
 * --INFO--
 * Address:	80092218
 * Size:	00021C
 */
void DualCreature::refresh(Graphics& gfx)
{
	Matrix4f mtx;
	bool isPointVisible = gfx.mCamera->isPointVisible(mPosition, 2.0f * getBoundingSphereRadius());

	if (isPointVisible) {
		disableAICulling();
	} else {
		enableAICulling();
	}

	if (!_43E) {
		if (!mIsDynamicsSimpleFixed && isPointVisible) {
			if (!mIsRealDynamics) {
				useRealDynamics();
			}
		} else if (mIsRealDynamics) {
			useSimpleDynamics();
		}
	}

	if (mIsRealDynamics) {
		mTransformMatrix.makeVQS(mPosition, _E0, mScale);
	} else {
		mTransformMatrix.makeSRT(mScale, mRotation, mPosition);
	}

	gfx.mCamera->mLookAtMtx.multiplyTo(mTransformMatrix, mtx);
	doRender(gfx, mtx);
	if (mIsRealDynamics) {
		createCollisions(gfx);
	}

	_43E = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
PelCreature::PelCreature(int objType, ItemShapeObject* shape, CreatureProp* props, MapMgr* mgr)
    : mItemCollInfo(0)
{
	mObjType   = (EObjType)objType;
	mItemShape = shape;
	mProps     = props;
	mapMgr     = mgr;
}

/*
 * --INFO--
 * Address:	80092434
 * Size:	000050
 */
void PelCreature::init(Vector3f& pos)
{
	Creature::init(pos);
	if (mItemShape) {
		mItemAnimator.init(&mItemShape->mAnimContext, mItemShape->mAnimMgr, itemMgr->mItemMotionTable);
	}
}

/*
 * --INFO--
 * Address:	80092484
 * Size:	000008
 */
f32 PelCreature::getiMass() { return 10.0f; }

/*
 * --INFO--
 * Address:	8009248C
 * Size:	000008
 */
bool PelCreature::isAlive() { return true; }

/*
 * --INFO--
 * Address:	80092494
 * Size:	000060
 */
void PelCreature::startAI(int)
{
	mCollInfo = &mItemCollInfo;
	mCollInfo->initInfo(mItemShape->mShape, mItemParts, mPartIDs);
	mItemAnimator.startMotion(PaniMotionInfo(0));
}

/*
 * --INFO--
 * Address:	800924F4
 * Size:	0001C8
 */
void PelCreature::doRender(Graphics& gfx, Matrix4f& mtx)
{
	Navi* navi = naviMgr->getNavi();
	if (navi->mKontroller->isPressed(KBBTN_B)) {
		mVelocity.y += 400.0f;
		if (mIsRealDynamics) {
			useSimpleDynamics();
		} else {
			mRotation.set(PI / 10.0f, 0.0f, 0.0f);
			useRealDynamics();
		}
	}

	gfx.setLighting(true, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);
	mItemAnimator.updateContext();
	mItemShape->mShape->updateAnim(gfx, mtx, nullptr);
	mItemShape->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
	mCollInfo->updateInfo(gfx, false);
}

/*
 * --INFO--
 * Address:	800926BC
 * Size:	00014C
 */
void PelCreature::doCreateColls(Graphics& gfx)
{
	f32 size          = getCentreSize();
	f32 firstPtclSize = 4.0f;
	for (int i = 0; i < 4; i++) {
		f32 angle = HALF_PI * i;
		Vector3f particlePos(size * cosf(angle), 0.0f, size * sinf(angle));
		addParticle(firstPtclSize, particlePos);

		angle = HALF_PI * i + QUARTER_PI;
		particlePos.set(size * cosf(angle), 0.0f, size * sinf(angle));
		particlePos.y += 25.0f;
		addParticle(2.0f, particlePos);
	}
}
