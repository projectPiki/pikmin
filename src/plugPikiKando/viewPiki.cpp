#include "ViewPiki.h"
#include "AIPerf.h"
#include "DebugLog.h"
#include "Font.h"
#include "Graphics.h"
#include "ItemMgr.h"
#include "MapCode.h"
#include "MemStat.h"
#include "MoviePlayer.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "Shape.h"
#include "UfoItem.h"
#include "gameflow.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(31)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("viewPiki")

PikiShapeObject* PikiShapeObject::_instances[4];
bool PikiShapeObject::firstTime = true;

/**
 * @todo: Documentation
 */
void PikiShapeObject::exitCourse()
{
	firstTime     = true;
	_instances[0] = _instances[1] = _instances[2] = _instances[3] = nullptr;
}

/**
 * @todo: Documentation
 */
void PikiShapeObject::init()
{
	firstTime     = true;
	_instances[0] = _instances[1] = _instances[2] = _instances[3] = nullptr;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00006C
 */
PikiShapeObject* PikiShapeObject::create(int index)
{
	memStat->start("piki animmgr");
	if (firstTime) {
		initOnce();
	}
	memStat->end("piki animmgr");
	if (index < 0 || index >= 4) {
		ERROR("illegal index %d\n", index);
	}
	return _instances[index];
}

/**
 * @todo: Documentation
 */
AnimMgr* PikiShapeObject::getAnimMgr()
{
	if (firstTime) {
		initOnce();
	}

	return _instances[0]->mAnimMgr;
}

/**
 * @todo: Documentation
 */
void PikiShapeObject::initOnce()
{
	_instances[Blue]           = new PikiShapeObject(gameflow.loadShape("pikis/bluModel.mod", true));
	_instances[Blue]->mAnimMgr = new AnimMgr(_instances[Blue]->mShape, "pikis/animMgr.bin", ANIMMGR_LOAD_BUNDLE, nullptr);

	gameflow.addGenNode("pikiAnimMgr", _instances[Blue]->mAnimMgr);

	_instances[Red]                   = new PikiShapeObject(gameflow.loadShape("pikis/redModel.mod", true));
	_instances[Red]->mAnimMgr         = _instances[Blue]->mAnimMgr;
	_instances[Yellow]                = new PikiShapeObject(gameflow.loadShape("pikis/yelModel.mod", true));
	_instances[Yellow]->mAnimMgr      = _instances[Blue]->mAnimMgr;
	_instances[PIKI_Kinoko]           = new PikiShapeObject(gameflow.loadShape("pikis/kinModel.mod", true));
	_instances[PIKI_Kinoko]->mAnimMgr = _instances[Blue]->mAnimMgr;

	firstTime = false;
}

/**
 * @todo: Documentation
 */
PikiShapeObject::PikiShapeObject(Shape* shape)
{
	mShape               = shape;
	mShape->mFrameCacher = gameflow.mFrameCacher;
	mAnimMgr             = nullptr;
	mShape->overrideAnim(0, &mAnimatorA);
	mShape->overrideAnim(1, &mAnimatorB);
}

/**
 * @todo: Documentation
 */
bool ViewPiki::isKinoko()
{
	return mPikiShape == PikiShapeObject::_instances[PIKI_Kinoko];
}

/**
 * @todo: Documentation
 */
void ViewPiki::changeShape(int index)
{
	if (index == -1) {
		index = mFormationPriority;
	}

	mPikiShape = PikiShapeObject::create(index);
	mPikiAnimMgr.changeContext(&mPikiShape->mAnimatorB, &mPikiShape->mAnimatorA);
	mCollInfo->initInfo(mPikiShape->mShape, nullptr, nullptr);

	if (isKinoko()) {
		setColor(mColor);
		mHappaModel = nullptr;
	} else {
		setFlower(mHappa);
	}

	f32 scale = 1.0f;
	mSRT.s.set(scale, scale, scale);
	setLeaves(index + 1);
}

/**
 * @todo: Documentation
 */
ViewPiki::ViewPiki(CreatureProp* prop)
    : Piki(prop)
{
	mPikiShape = nullptr;
	mHappa     = 0;
}

/**
 * @todo: Documentation
 */
void ViewPiki::initBirth()
{
	mHappaModel = nullptr;
	mPikiShape  = PikiShapeObject::create(0);
	mPikiAnimMgr.init(mPikiShape->mAnimMgr, &mPikiShape->mAnimatorB, &mPikiShape->mAnimatorA, pikiMgr->mMotionTable);

	f32 scale = 1.0f;
	mSRT.s.set(scale, scale, scale);
	setFlower(0);

#if defined(VERSION_GPIJ01_01)
	STACK_PAD_VAR(2);
#else
	STACK_PAD_VAR(4);
#endif
}

/**
 * @todo: Documentation
 */
void ViewPiki::init(Shape* shp, MapMgr*, Navi* navi)
{
	mPikiShape  = PikiShapeObject::create(0);
	mHappaModel = nullptr;

	mCollInfo = new CollInfo(4);
	mCollInfo->initInfo(mPikiShape->mShape, nullptr, nullptr);
	mPikiAnimMgr.init(mPikiShape->mAnimMgr, &mPikiShape->mAnimatorB, &mPikiShape->mAnimatorA, pikiMgr->mMotionTable);

	f32 scale = 1.0f;
	scale *= pikiMgr->mPikiParms->mPikiParms.mPluckStrength0();
	mSRT.s.set(scale, scale, scale);
	setLeaves(1);

	mPikiAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_StillJump, this), PaniMotionInfo(PIKIANIM_StillJump));

	mSRT.s.set(1.0f, 1.0f, 1.0f);
	mSRT.r.set(0.0f, 0.0f, 0.0f);
	mSRT.t.set((gsys->getRand(1.0f) - 0.5f) * 300.0f, 0.0f, (gsys->getRand(1.0f) - 0.5f) * 300.0f);

	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	_268 = 0.0f;
	Piki::init(navi);
	mLastPosition       = mSRT.t;
	mLastEffectPosition = mSRT.t;
}

/**
 * @todo: Documentation
 */
void ViewPiki::setFlower(int id)
{
	if (!isKinoko()) {
		mHappa      = id;
		mHappaModel = pikiMgr->mLeafModel[id];
	}
}

/**
 * @todo: Documentation
 */
void ViewPiki::setLeaves(int)
{
}

/**
 * @todo: Documentation
 */
void ViewPiki::postUpdate(int unused, f32 deltaTime)
{
	if (mMode == PikiMode::FreeMode && !pikiMgr->isUpdating(PMUPDATE_FreePiki)) {
		return;
	}

	if (mMode == PikiMode::FormationMode && !pikiMgr->isUpdating(PMUPDATE_FormationPiki)) {
		return;
	}

	if (!pikiMgr->isUpdating(PMUPDATE_WorkPiki)) {
		return;
	}

	if (gameflow.mMoviePlayer->mIsActive && pikiMgr->isUpdating(PMUPDATE_Unk4)) {
		Vector3f toShip = mSRT.t - itemMgr->getUfo()->getGoalPos();
		if (toShip.length() > 100.0f) {
			return;
		}
	}

	Creature::postUpdate(unused, deltaTime);

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 */
void ViewPiki::update()
{
	if (mMode == PikiMode::FreeMode && !pikiMgr->isUpdating(PMUPDATE_FreePiki)) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}
	if (mMode == PikiMode::FormationMode && !pikiMgr->isUpdating(PMUPDATE_FormationPiki)) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}
	if (!pikiMgr->isUpdating(PMUPDATE_WorkPiki)) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	if (gameflow.mMoviePlayer->mIsActive && pikiMgr->isUpdating(PMUPDATE_Unk4)) {
		Vector3f toShip = mSRT.t - itemMgr->getUfo()->getGoalPos();
		if (toShip.length() > 100.0f) {
			mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
			return;
		}
	}

	updateColor();
	mHasCollChangedVelocity = 0;
	Creature::update();
	realAI();

	if (mColor == Blue && gameflow.mDemoFlags & CinePlayerFlags::HideBluePiki) {
		return;
	}

	if (mColor == Red && gameflow.mDemoFlags & CinePlayerFlags::HideRedPiki) {
		return;
	}

	if (mColor == Yellow && gameflow.mDemoFlags & CinePlayerFlags::HideYellowPiki) {
		return;
	}

	if (AIPerf::optLevel == 0 && mGroundTriangle && gsys->getRand(1.0f) > 0.99f) {
		Vector3f toLastPosition = mLastEffectPosition - mSRT.t;

		// If we've moved enough, create an effect
		if (toLastPosition.length() > 40.0f) {
			Vector3f pos(mSRT.t.x, mSRT.t.y + 1.0f, mSRT.t.z);
			Vector3f rot(mVelocity.x * 0.01667f, 1.0f, mVelocity.z * 0.01667f);
			EffectParm parm(pos, rot);

			int attr = MapCode::getAttribute(mGroundTriangle);
			if (attr >= ATTR_Solid && attr <= ATTR_Wood) {
				utEffectMgr->cast(attr + KandoEffect::SmokeOffset, parm);
			}

			mLastEffectPosition = mSRT.t;
		}
	}
}

/**
 * @todo: Documentation
 */
void Piki::startHimaLook(immut Vector3f* pos)
{
	mLookatPosPtr = pos;
	mLookTimer    = false;
	mIsLooking    = false;
	mLookAtCreature.reset();
	mIsLooking = true;
	_334       = gsys->getRand(1.0f) * 3.0f + 4.0f;
}

/**
 * @todo: Documentation
 */
void Piki::finishLook()
{
	mLookatPosPtr = nullptr;
	mLookTimer    = 10;
	mIsLooking    = false;
}

/**
 * @todo: Documentation
 */
bool Piki::isLooking()
{
	return mLookatPosPtr != nullptr;
}

/**
 * @todo: Add documentation
 * Address:	100DE380 in DLL
 */
void Piki::updateLook()
{
	f32 horizontalAngle;
	f32 rotationSpeed = 0.05f;
	f32 horizontalDistance;
	f32 verticalAngle;
	if (mLookatPosPtr) {
		Vector3f targetOffset = *mLookatPosPtr - mSRT.t;
		horizontalAngle       = atan2f(targetOffset.x, targetOffset.z);
		horizontalDistance    = std::sqrtf(targetOffset.x * targetOffset.x + targetOffset.z * targetOffset.z);
		verticalAngle         = atan2f(targetOffset.y, horizontalDistance);
	} else {
		rotationSpeed       = 0.2f;
		f32 diffH           = angDist(0.0f, mHorizontalRotation);
		mHorizontalRotation = roundAng(diffH * rotationSpeed + mHorizontalRotation);
		f32 diffV           = angDist(0.0f, mVerticalRotation);
		mVerticalRotation   = roundAng(diffV * rotationSpeed + mVerticalRotation);
		if (absF(mHorizontalRotation) < 0.1f && absF(mVerticalRotation) < 0.1f) {
			forceFinishLook();
		}
		return;
	}

	f32 currentFacingAngle = roundAng(mHorizontalRotation + mFaceDirection);
	f32 targetAngleDiff    = roundAng(horizontalAngle - mFaceDirection);
	f32 angleAdjustment;

	if (targetAngleDiff < PI) {
		if (mHorizontalRotation > PI) {
			angleAdjustment = TAU - (mHorizontalRotation - targetAngleDiff);
		} else {
			angleAdjustment = angDist(horizontalAngle, currentFacingAngle);
		}
	} else if (mHorizontalRotation <= PI) {
		angleAdjustment = (mHorizontalRotation - targetAngleDiff);
		angleAdjustment = (TAU - angleAdjustment);
		angleAdjustment *= -1.0f;
	} else {
		angleAdjustment = angDist(horizontalAngle, currentFacingAngle);
	}

	if (absF(angleAdjustment) < PI / 20.0f) {
		angleAdjustment = 0.0f;
	}

	mHorizontalRotation = roundAng(angleAdjustment * rotationSpeed + mHorizontalRotation);
	if (mHorizontalRotation > (2.0f * THIRD_PI) && mHorizontalRotation < PI) {
		mHorizontalRotation = (2.0f * THIRD_PI);
	} else if (mHorizontalRotation < (4.0f * THIRD_PI) && mHorizontalRotation >= PI) {
		mHorizontalRotation = (4.0f * THIRD_PI);
	}

	angleAdjustment = angDist(verticalAngle, mVerticalRotation);
	if (absF(angleAdjustment) < PI / 20.0f) {
		angleAdjustment = 0.0f;
	}

	mVerticalRotation = roundAng(angleAdjustment * rotationSpeed + mVerticalRotation);
	if (mVerticalRotation > THIRD_PI && mVerticalRotation < PI) {
		mVerticalRotation = THIRD_PI;
	} else if (mVerticalRotation < (5.0f * THIRD_PI) && mVerticalRotation >= PI) {
		mVerticalRotation = 5.0f * THIRD_PI;
	}

	if (mLookTimer) {
		mLookTimer--;
		if (mLookTimer == 0) {
			forceFinishLook();
		}
	}
}

/**
 * @todo: Documentation
 */
void ViewPiki::demoDraw(Graphics& gfx, immut Matrix4f* mtx)
{
	Vector3f pos;
	if (AIPerf::optLevel <= 2 || mOptUpdateContext.updatable()) {
		pos.set(0.0f, 0.0f, 0.0f);
		mPikiShape->mShape->calcJointWorldPos(gfx, 0, pos);
		mShadowPos = pos;
		pos.set(0.0f, 4.0f, 0.0f);
		mPikiShape->mShape->calcJointWorldPos(gfx, 1, pos);
		mCatchPos = pos;
	}

	STACK_PAD_VAR(1);
	if (mHappa == Bud) {
		pos.set(4.0f, 0.0f, 0.0f);
	} else if (mHappa == Flower) {
		pos.set(3.0f, 0.0f, 0.0f);
	} else {
		pos.set(6.0f, 0.0f, 0.0f);
	}
	mPikiShape->mShape->calcJointWorldPos(gfx, 6, pos);
	mEffectPos = pos;

	if (isDamaged() && gsys->getRand(1.0f) > 0.5f) {
		mPikiShape->mShape->mMaterialList->setColour(COLOUR_WHITE);
	} else {
		mPikiShape->mShape->mMaterialList->setColour(mCurrentColour);
	}

	if (aiCullable()) {
		mPikiShape->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
	}

	if (mIsPanicked) {
		mPanickedEffect->updatePos(mShadowPos);
	}

	if (aiCullable() && AIPerf::optLevel < 3 && mHappaModel) {
		gfx.useMatrix(mPikiShape->mShape->getAnimMatrix(6), 0);
		mHappaModel->drawshape(gfx, *gfx.mCamera, nullptr);
	}

	if (mMode == PikiMode::FormationMode && AIPerf::kandoOnly) {
		gfx.useMatrix(Matrix4f::ident, 0);
		ActCrowd* act = (ActCrowd*)mActiveAction->getCurrAction();
		if (act) {
			Vector3f pos = mSRT.t;
			int slotID   = act->getSlotID();
			pos.y += 2.0f * f32(slotID) + 50.0f;
			bool light = gfx.setLighting(false, nullptr);
			gfx.useMatrix(Matrix4f::ident, 0);
			if (act->mState == ActCrowd::STATE_Sort) {
				gfx.setColour(Colour(255, 10, 50, 255), 1);
			} else if (act->mState == ActCrowd::STATE_Unk0) {
				gfx.setColour(Colour(200, 255, 255, 255), 1);
			} else {
				gfx.setColour(COLOUR_WHITE, 1);
			}

			const char* strs[6] = { "A", "B", "C", "D", "E", "F" };
			char buf[256];
			int formMode = act->mMode;
			int cb       = gfx.setCBlending(BLEND_Alpha);
			pos.multMatrix(gfx.mCamera->mLookAtMtx);
			sprintf(buf, "%s%d", strs[formMode], slotID);
			gfx.perspPrintf(gsys->mConsFont, pos, -(gsys->mConsFont->stringWidth(buf) / 2), 0, buf);
			gfx.setCBlending(cb);
			gfx.setLighting(light, nullptr);
		}
	}

	if (AIPerf::kandoOnly && mActiveAction) {
		if (mActiveAction->getCurrAction()) {
			gfx.useMatrix(Matrix4f::ident, 0);
			mActiveAction->getCurrAction()->draw(gfx);
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
static void printMatrix(immut char* name, immut Matrix4f& mat)
{
	// I can't find this function in the DLL at the moment and nothing in this decomp currently uses it.  See also: goalItem.cpp where this
	// implementation is copied from and dynCreature.cpp wherein the function has known uses but the DLL shows an empty implementation.
	PRINT("++++ MATRIX %s ++++\n", name);
	for (int i = 0; i < 4; ++i) {
		PRINT("  %f %f %f %f\n", mat.mMtx[i][0], mat.mMtx[i][1], mat.mMtx[i][2], mat.mMtx[i][3]);
	}
	PRINT("-------------------------\n");
}

/**
 * @todo: Documentation
 */
void ViewPiki::refresh(Graphics& gfx)
{
	STACK_PAD_VAR(2);
	u32 color = mColor;
	if (color == Blue && gameflow.mDemoFlags & CinePlayerFlags::HideBluePiki) {
		return;
	}
	if (color == Red && gameflow.mDemoFlags & CinePlayerFlags::HideRedPiki) {
		return;
	}
	if (color == Yellow && gameflow.mDemoFlags & CinePlayerFlags::HideYellowPiki) {
		return;
	}
	if (mMode == PikiMode::FreeMode && !pikiMgr->isUpdating(PMUPDATE_FreePiki)) {
		return;
	}
	if (mMode == PikiMode::FormationMode && !pikiMgr->isUpdating(PMUPDATE_FormationPiki)) {
		return;
	}
	if (!pikiMgr->isUpdating(PMUPDATE_WorkPiki)) {
		return;
	}

	if (gameflow.mMoviePlayer->mIsActive && pikiMgr->isUpdating(PMUPDATE_Unk4)) {
		Vector3f diff = mSRT.t - itemMgr->getUfo()->getGoalPos();
		if (diff.length() > 100.0f) {
			return;
		}
	}
	Matrix4f mtx;
	f32 size = getSize();
	if (!gfx.mCamera->isPointVisible(mSRT.t, size * 4.0f)) {
		enableAICulling();
	} else {
		disableAICulling();
		if (AIPerf::useLOD) {
			Vector3f diff = gfx.mCamera->mPosition - mSRT.t;
			_528          = diff.length();
		} else {
			_528 = 12800.0f;
		}
	}

	if (getState() == PIKISTATE_Pressed) {
		f32 scaleFactor = pikiMgr->mPikiParms->mPikiParms.mPikiDisplayScale();
		f32 scaleXZ, scaleY;
		f32 norm = pikiMgr->mPikiParms->mPikiParms.mPressDeathFactor() - pikiMgr->mPikiParms->mPikiParms.mNormalPikiPressFactor();
		if (mDeathTimer > pikiMgr->mPikiParms->mPikiParms.mPressDeathFactor() - pikiMgr->mPikiParms->mPikiParms.mNormalPikiPressFactor()) {
			scaleXZ = 2.0f;
			scaleY  = 0.01f;
		} else {
			scaleXZ = (mDeathTimer / norm) + 1.0f;
			scaleY  = (1.0f - (mDeathTimer / norm)) * 0.99f + 0.01f;
			if (scaleY < 0.0f) {
				ERROR("sacle minus!\n");
			}
		}
		mSRT.s.set(scaleFactor * scaleXZ, scaleFactor * scaleY, scaleFactor * scaleXZ);
	}

	if ((mStickTarget && isStickToPlatform()) || mRope || (mStickTarget && mStickPart && mStickPart->isTubeType())) {
		mWorldMtx = mConstrainedMoveMtx;
		for (int i = 0; i < 3; i++) {
			mWorldMtx.mMtx[i][0] *= mSRT.s.x;
			mWorldMtx.mMtx[i][1] *= mSRT.s.y;
			mWorldMtx.mMtx[i][2] *= mSRT.s.z;
		}

		mWorldMtx.setTranslation(mSRT.t.x, mSRT.t.y, mSRT.t.z);
	} else {
		mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
		mConstrainedMoveMtx = mWorldMtx;
	}

	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);

	if (getState() == PIKISTATE_Swallowed && mSwallowMouthPart) {
		Matrix4f mouthMtx = mSwallowMouthPart->getJointMatrix();
		f32 swallowScale  = 1.0f / reinterpret_cast<Vector3f&>(mouthMtx).length();
		if (swallowScale <= 0.0f) {
			PRINT_GLOBAL("swallow scale=%f", swallowScale);
			swallowScale = 1.0f;
		}

		Matrix4f mtx2;
		mtx2.makeSRT(Vector3f(swallowScale, swallowScale, swallowScale), Vector3f(0.0f, 0.0f, HALF_PI), Vector3f(0.0f, 0.0f, 0.0f));
		mouthMtx.multiplyTo(mtx2, mtx);
		mSRT.t = mSwallowMouthPart->mCentre;
	}

	mPikiAnimMgr.updateContext();
	mPikiShape->mShape->updateAnim(gfx, mtx, nullptr);

	if ((AIPerf::useLOD && _528 < 1200.0f && aiCullable()) || !AIPerf::useLOD) {
#if defined(VERSION_PIKIDEMO)
		if ((mLookatPosPtr || mLookTimer) && getState() != PIKISTATE_Swallowed)
#else
		if ((mLookatPosPtr || mLookTimer) && getState() != PIKISTATE_Swallowed && mMode != PikiMode::ExitMode)
#endif
		{
			updateLook();

			Matrix4f animMtx1 = mPikiShape->mShape->getAnimMatrix(2);
#if defined(VERSION_PIKIDEMO)
#else
			animMtx1.mMtx[3][0] = animMtx1.mMtx[3][1] = animMtx1.mMtx[3][2] = 0.0f;
			animMtx1.mMtx[3][3]                                             = 1.0f;
#endif

			Matrix4f mtx2;
			Matrix4f mtx3;
			animMtx1.inverse(&mtx2);
			Matrix4f mtx4;
			mtx4.makeIdentity();

			f32 sinV = sinf(-mVerticalRotation);
			f32 cosV = cosf(-mVerticalRotation);
			f32 sinH = sinf(mHorizontalRotation);
			f32 cosH = cosf(mHorizontalRotation);

			mtx4.mMtx[0][0] = cosV;
			mtx4.mMtx[0][1] = -sinV;
			mtx4.mMtx[0][2] = 0.0f;

			mtx4.mMtx[1][0] = cosH * sinV;
			mtx4.mMtx[1][1] = cosH * cosV;
			mtx4.mMtx[1][2] = -sinH;

			mtx4.mMtx[2][0] = sinH * sinV;
			mtx4.mMtx[2][1] = sinH * cosV;
			mtx4.mMtx[2][2] = cosH;

			animMtx1.multiplyTo(mtx4, mtx3);

			mPikiShape->mShape->getAnimMatrix(2) = mtx3;

			for (int j = 3; j <= 6; j++) {
				Matrix4f animMtx = mPikiShape->mShape->getAnimMatrix(j);
#if defined(VERSION_PIKIDEMO)
#else
				animMtx.mMtx[3][0] = animMtx.mMtx[3][1] = animMtx.mMtx[3][2] = 0.0f;
				animMtx.mMtx[3][3]                                           = 1.0f;
#endif

				Matrix4f tmp1;
				Matrix4f tmp2;
				mtx2.multiplyTo(animMtx, tmp1);
				mtx3.multiplyTo(tmp1, tmp2);
				mPikiShape->mShape->getAnimMatrix(j) = tmp2;
			}

			mPikiShape->mShape->calcWeightedMatrices();
		}
	}

	mCollInfo->updateInfo(gfx, false);
	demoDraw(gfx, nullptr);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C (Matching by size)
 */
void ViewPiki::refresh2d(Graphics&, int)
{
	mLifeGauge.mPosition = mSRT.t;
}
