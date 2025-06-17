#include "ViewPiki.h"
#include "gameflow.h"
#include "Shape.h"
#include "sysNew.h"
#include "MemStat.h"
#include "ItemMgr.h"
#include "MoviePlayer.h"
#include "PikiMgr.h"
#include "UfoItem.h"
#include "AIPerf.h"
#include "MapCode.h"
#include "PikiAI.h"
#include "Font.h"
#include "PikiState.h"
#include "Graphics.h"
#include "DebugLog.h"

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
DEFINE_PRINT("viewPiki")

PikiShapeObject* PikiShapeObject::_instances[4];
bool PikiShapeObject::firstTime = true;

/*
 * --INFO--
 * Address:	800D8894
 * Size:	000028
 */
void PikiShapeObject::exitCourse()
{
	firstTime     = true;
	_instances[0] = _instances[1] = _instances[2] = _instances[3] = nullptr;
}

/*
 * --INFO--
 * Address:	800D88BC
 * Size:	000028
 */
void PikiShapeObject::init()
{
	firstTime     = true;
	_instances[0] = _instances[1] = _instances[2] = _instances[3] = nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
PikiShapeObject* PikiShapeObject::create(int index)
{
	memStat->start("piki animmgr");
	if (firstTime) {
		initOnce();
	}
	memStat->end("piki animmgr");
	if (index < 0 || index > 3) {
		ERROR("illegal index %d\n");
	}
	return _instances[index];
}

/*
 * --INFO--
 * Address:	800D88E4
 * Size:	00003C
 */
AnimMgr* PikiShapeObject::getAnimMgr()
{
	if (firstTime) {
		initOnce();
	}

	return _instances[0]->mAnimMgr;
}

/*
 * --INFO--
 * Address:	800D8920
 * Size:	0001B4
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

/*
 * --INFO--
 * Address:	800D8AD4
 * Size:	00009C
 */
PikiShapeObject::PikiShapeObject(Shape* shape)
{
	mShape               = shape;
	mShape->mFrameCacher = gameflow.mFrameCacher;
	mAnimMgr             = nullptr;
	mShape->overrideAnim(0, &mAnimatorA);
	mShape->overrideAnim(1, &mAnimatorB);
}

/*
 * --INFO--
 * Address:	800D8B70
 * Size:	000020
 */
bool ViewPiki::isKinoko()
{
	return mPikiShape == PikiShapeObject::_instances[PIKI_Kinoko];
}

/*
 * --INFO--
 * Address:	800D8B90
 * Size:	000128
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
	mScale.set(scale, scale, scale);
	setLeaves(index + 1);

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	800D8CB8
 * Size:	000060
 */
ViewPiki::ViewPiki(CreatureProp* prop)
    : Piki(prop)
{
	mPikiShape = nullptr;
	mHappa     = 0;
}

/*
 * --INFO--
 * Address:	800D8D18
 * Size:	0000B4
 */
void ViewPiki::initBirth()
{
	mHappaModel = nullptr;
	mPikiShape  = PikiShapeObject::create(0);
	mPikiAnimMgr.init(mPikiShape->mAnimMgr, &mPikiShape->mAnimatorB, &mPikiShape->mAnimatorA, pikiMgr->mMotionTable);

	f32 scale = 1.0f;
	mScale.set(scale, scale, scale);
	setFlower(0);

	STACK_PAD_VAR(4);
}

/*
 * --INFO--
 * Address:	800D8DCC
 * Size:	00026C
 */
void ViewPiki::init(Shape* shp, MapMgr*, Navi* navi)
{
	mPikiShape  = PikiShapeObject::create(0);
	mHappaModel = nullptr;

	mCollInfo = new CollInfo(4);
	mCollInfo->initInfo(mPikiShape->mShape, nullptr, nullptr);
	mPikiAnimMgr.init(mPikiShape->mAnimMgr, &mPikiShape->mAnimatorB, &mPikiShape->mAnimatorA, pikiMgr->mMotionTable);

	f32 scale = 1.0f;
	scale *= pikiMgr->mPikiParms->mPikiParms._12C();
	mScale.set(scale, scale, scale);
	setLeaves(1);

	mPikiAnimMgr.startMotion(PaniMotionInfo(22, this), PaniMotionInfo(22));

	mScale.set(1.0f, 1.0f, 1.0f);
	mRotation.set(0.0f, 0.0f, 0.0f);
	mPosition.set((gsys->getRand(1.0f) - 0.5f) * 300.0f, 0.0f, (gsys->getRand(1.0f) - 0.5f) * 300.0f);

	mWorldMtx.makeSRT(mScale, mRotation, mPosition);
	_268 = 0.0f;
	Piki::init(navi);
	mLastPosition       = mPosition;
	mLastEffectPosition = mPosition;

	STACK_PAD_TERNARY(_268, 1);
}

/*
 * --INFO--
 * Address:	800D9038
 * Size:	000064
 */
void ViewPiki::setFlower(int id)
{
	if (!isKinoko()) {
		mHappa      = id;
		mHappaModel = pikiMgr->mLeafModel[id];
	}
}

/*
 * --INFO--
 * Address:	800D909C
 * Size:	000004
 */
void ViewPiki::setLeaves(int)
{
}

/*
 * --INFO--
 * Address:	800D90A0
 * Size:	00017C
 */
void ViewPiki::postUpdate(int _, f32 __)
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
		Vector3f toShip = mPosition - itemMgr->getUfo()->getGoalPos();
		if (toShip.length() > 100.0f) {
			return;
		}
	}

	// Params are unused through all function calls
	Creature::postUpdate(_, __);

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	800D921C
 * Size:	000408
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
		Vector3f toShip = mPosition - itemMgr->getUfo()->getGoalPos();
		if (toShip.length() > 100.0f) {
			mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
			return;
		}
	}

	updateColor();
	mHasCollChangedVelocity = 0;
	Creature::update();
	realAI();

	if (mColor == Blue && gameflow.mDemoFlags & 8) {
		return;
	}

	if (mColor == Red && gameflow.mDemoFlags & 0x10) {
		return;
	}

	if (mColor == Yellow && gameflow.mDemoFlags & 0x20) {
		return;
	}

	if (AIPerf::optLevel == 0 && mGroundTriangle && gsys->getRand(1.0f) > 0.99f) {
		Vector3f toLastPosition = mLastEffectPosition - mPosition;

		// If we've moved enough, create an effect
		if (toLastPosition.length() > 40.0f) {
			Vector3f pos(mPosition.x, mPosition.y + 1.0f, mPosition.z);
			Vector3f rot(mVelocity.x * 0.01667f, 1.0f, mVelocity.z * 0.01667f);
			EffectParm parm(pos, rot);

			int attr = MapCode::getAttribute(mGroundTriangle);
			if (attr >= ATTR_Soil && attr <= ATTR_Tree) {
				utEffectMgr->cast(attr + KandoEffect::SmokeOffset, parm);
			}

			mLastEffectPosition = mPosition;
		}
	}
}

/*
 * --INFO--
 * Address:	800D9624
 * Size:	0000A0
 */
void Piki::startHimaLook(Vector3f* pos)
{
	mLookatTarget = pos;
	mLookTimer    = false;
	mIsLooking    = false;
	mLookAtTarget.reset();
	mIsLooking = 1;
	_334       = gsys->getRand(1.0f) * 3.0f + 4.0f;
}

/*
 * --INFO--
 * Address:	800D96C4
 * Size:	000018
 */
void Piki::finishLook()
{
	mLookatTarget = nullptr;
	mLookTimer    = 10;
	mIsLooking    = false;
}

/*
 * --INFO--
 * Address:	800D96DC
 * Size:	000014
 */
bool Piki::isLooking()
{
	return mLookatTarget != nullptr;
}

/*
 * --INFO--
 * Address:	800D96F0, 100DE380 in DLL
 * Size:	000378
 */
void Piki::updateLook()
{
	f32 horizontalAngle;
	f32 rotationSpeed = 0.05f;
	f32 horizontalDistance;
	f32 verticalAngle;
	if (mLookatTarget) {
		Vector3f targetOffset = *mLookatTarget - mPosition;
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

/*
 * --INFO--
 * Address:	800D9A68
 * Size:	000678
 */
void ViewPiki::demoDraw(Graphics& gfx, Matrix4f* mtx)
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
		mPikiShape->mShape->mMaterialList->setColour(Colour(255, 255, 255, 255));
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
			Vector3f pos = mPosition;
			int slotID   = act->mCPlateSlotID;
			pos.y += 2.0f * f32(slotID) + 50.0f;
			bool light = gfx.setLighting(false, nullptr);
			gfx.useMatrix(Matrix4f::ident, 0);
			if (act->mState == ActCrowd::STATE_Sort) {
				gfx.setColour(Colour(255, 10, 50, 255), 1);
			} else if (act->mState == ActCrowd::STATE_Unk0) {
				gfx.setColour(Colour(200, 255, 255, 255), 1);
			} else {
				gfx.setColour(Colour(255, 255, 255, 255), 1);
			}

			char* strs[6] = { "A", "B", "C", "D", "E", "F" };
			char buf[256];
			int formMode = act->mMode;
			int cb       = gfx.setCBlending(0);
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

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
static void printMatrix(char*, Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DA0E0
 * Size:	000B48
 */
void ViewPiki::refresh(Graphics& gfx)
{
	STACK_PAD_VAR(2);
	u32 color = mColor;
	if (color == Blue && gameflow.mDemoFlags & 8) {
		return;
	}
	if (color == Red && gameflow.mDemoFlags & 16) {
		return;
	}
	if (color == Yellow && gameflow.mDemoFlags & 32) {
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
		Vector3f diff = mPosition - itemMgr->getUfo()->getGoalPos();
		if (diff.length() > 100.0f) {
			return;
		}
	}
	Matrix4f mtx;
	f32 size = getSize();
	if (!gfx.mCamera->isPointVisible(mPosition, size * 4.0f)) {
		enableAICulling();
	} else {
		disableAICulling();
		if (AIPerf::useLOD) {
			Vector3f diff = gfx.mCamera->mPosition - mPosition;
			_528          = diff.length();
		} else {
			_528 = 12800.0f;
		}
	}

	if (getState() == PIKISTATE_Pressed) {
		f32 scaleFactor = pikiMgr->mPikiParms->mPikiParms.mPikiDisplayScale();
		f32 scaleXZ, scaleY;
		f32 norm = pikiMgr->mPikiParms->mPikiParms._15C() - pikiMgr->mPikiParms->mPikiParms._16C();
		if (mDeathTimer > pikiMgr->mPikiParms->mPikiParms._15C() - pikiMgr->mPikiParms->mPikiParms._16C()) {
			scaleXZ = 2.0f;
			scaleY  = 0.01f;
		} else {
			scaleXZ = (mDeathTimer / norm) + 1.0f;
			scaleY  = (1.0f - (mDeathTimer / norm)) * 0.99f + 0.01f;
			if (scaleY < 0.0f) {
				ERROR("sacle minus!\n");
			}
		}
		mScale.set(scaleFactor * scaleXZ, scaleFactor * scaleY, scaleFactor * scaleXZ);
	}

	if ((mStickTarget && isStickToPlatform()) || mRope || (mStickTarget && mStickPart && mStickPart->isTubeType())) {
		mWorldMtx = mConstrainedMoveMtx;
		for (int i = 0; i < 3; i++) {
			mWorldMtx.mMtx[i][0] *= mScale.x;
			mWorldMtx.mMtx[i][1] *= mScale.y;
			mWorldMtx.mMtx[i][2] *= mScale.z;
		}

		mWorldMtx.setTranslation(mPosition.x, mPosition.y, mPosition.z);
	} else {
		mWorldMtx.makeSRT(mScale, mRotation, mPosition);
		mConstrainedMoveMtx = mWorldMtx;
	}

	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);

	if (getState() == PIKISTATE_Swallowed && mSwallowMouthPart) {
		Matrix4f mouthMtx = mSwallowMouthPart->getJointMatrix();
		f32 swallowScale  = 1.0f / ((Vector3f*)&mouthMtx)->length();
		if (swallowScale <= 0.0f) {
			PRINT("swallow scale=%f", swallowScale);
			swallowScale = 1.0f;
		}

		Matrix4f mtx2;
		mtx2.makeSRT(Vector3f(swallowScale, swallowScale, swallowScale), Vector3f(0.0f, 0.0f, HALF_PI), Vector3f(0.0f, 0.0f, 0.0f));
		mouthMtx.multiplyTo(mtx2, mtx);
		mPosition = mSwallowMouthPart->mCentre;
	}

	mPikiAnimMgr.updateContext();
	mPikiShape->mShape->updateAnim(gfx, mtx, nullptr);

	if ((AIPerf::useLOD && _528 < 1200.0f && aiCullable()) || !AIPerf::useLOD) {
		if ((mLookatTarget || mLookTimer) && getState() != PIKISTATE_Swallowed && mMode != PikiMode::ExitMode) {
			updateLook();

			Matrix4f animMtx1   = mPikiShape->mShape->getAnimMatrix(2);
			animMtx1.mMtx[3][0] = animMtx1.mMtx[3][1] = animMtx1.mMtx[3][2] = 0.0f;
			animMtx1.mMtx[3][3]                                             = 1.0f;

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
				Matrix4f animMtx   = mPikiShape->mShape->getAnimMatrix(j);
				animMtx.mMtx[3][0] = animMtx.mMtx[3][1] = animMtx.mMtx[3][2] = 0.0f;
				animMtx.mMtx[3][3]                                           = 1.0f;

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

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void ViewPiki::refresh2d(Graphics&, int)
{
	// UNUSED FUNCTION
}
