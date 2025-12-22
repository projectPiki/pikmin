#include "CPlate.h"
#include "Creature.h"
#include "DebugLog.h"
#include "FlowController.h"
#include "Graphics.h"
#include "NaviMgr.h"
#include "ParaParameters.h"
#include "Pcam/Camera.h"
#include "Pcam/CameraParameters.h"
#include "SoundMgr.h"
#include "nlib/Geometry3D.h"
#include "nlib/System.h"
#include "stl/limits.h"
#include "sysNew.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("pcamcamera")

/**
 * @TODO: Documentation
 */
PcamMotionInfo::PcamMotionInfo()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00001C
 */
void PcamMotionInfo::init(f32 dist, f32 angle, f32 fov, f32 watchAdjust, f32 naviWatchWeight, f32 blur)
{
	mDistance        = dist;
	mAngle           = angle;
	mFov             = fov;
	mWatchAdjustment = watchAdjust;
	mNaviWatchWeight = naviWatchWeight;
	mBlur            = blur;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void PcamMotionInfo::println()
{
}

/**
 * @TODO: Documentation
 */
PcamControlInfo::PcamControlInfo()
{
	mIsActive          = false;
	mDoRotate          = false;
	mDoAttentionCamera = false;
	mDoToggleZoom      = false;
	mDoAdjustAngle     = false;
	mDoAdjustAngleDown = false;
	_UNUSED06          = false;
}

/**
 * @TODO: Documentation
 */
void PcamControlInfo::init(bool p1, bool doRotate, bool doAttention, bool toggleZoom, bool adjustAngle, bool p6, bool p7, f32 azimuthRot,
                           f32 p9, f32 p10)
{
	mIsActive            = p1;
	mDoRotate            = doRotate;
	mDoAttentionCamera   = doAttention;
	mDoToggleZoom        = toggleZoom;
	mDoAdjustAngle       = adjustAngle;
	mDoAdjustAngleDown   = p6;
	_UNUSED06            = p7;
	mAzimuthRotIntensity = azimuthRot;
	mSubStickInput       = p9;
	mSubStickY           = p10;
}

/**
 * @TODO: Documentation
 */
PcamCamera::PcamCamera(Camera* camera)
    : NCamera(camera)
{
	mParameters = new PcamCameraParameters();
	mParameters->load("camera/", "camepara.bin", 1);
	mCreatureArray     = new NArray<Creature>(4);
	mDefaultDistance   = 2000.0f;
	mMinAngleThreshold = NMathF::d2r(2.0f);
	mMaxAngleThreshold = NMathF::d2r(80.0f);
}

/**
 * @TODO: Documentation
 */
void PcamCamera::startCamera(Creature* target)
{
	startCamera(target, PCAMZOOM_Near, PCAMANGLE_Low);
}

/**
 * @TODO: Documentation
 */
void PcamCamera::startCamera(Creature* target, int zoom, int angle)
{
	PRINT("startCamera:%08x,%d,%d\n", this, zoom, angle);
	setTarget(target);
	parameterUpdated();
	mZoomLevel        = zoom;
	mInclinationLevel = angle;

	mTargetMotionInfo = getBasicMotionInfo(mZoomLevel, mInclinationLevel);
	startMotion(mTargetMotionInfo);
	setFov(getCurrentFov());
	setAspect(1.0f);
	setBlur(getCurrentBlur());

	mDistanceMultiplier = 1.0f;
	mIsActive           = true;
	mAttentionEnabled   = true;
	mControlsEnabled    = true;

	mToggleZoomPending        = FALSE;
	mAdjustInclinationPending = FALSE;
	_UNUSED98                 = 0;
	mAttentionState           = AttentionState::Inactive;

	for (int i = 0; i < 3; i++) {
		mTimers[i] = 0.0f;
	}

	if (flowCont.mNaviOnMap == 1) {
		mCreatureArray->add(naviMgr->getNavi(0));
		mCreatureArray->add(naviMgr->getNavi(1));
	}

	makeCurrentPosition(target->mFaceDirection + NMathF::pi);
}

/**
 * @TODO: Documentation
 */
void PcamCamera::makeCurrentPosition(f32 azimuth)
{
	mPolarDir.set(mTargetMotionInfo.mDistance, angleToMeridian(mTargetMotionInfo.mAngle), azimuth);
	mStoredRadius = mPolarDir.mRadius;
	NVector3f watchPt;
	outputTargetWatchpoint(watchPt);

	NVector3f viewPt;
	mPolarDir.output(viewPt);

	viewPt.add(watchPt);
	inputViewpoint(viewPt);
	inputWatchpoint(watchPt);
}

/**
 * @TODO: Documentation
 */
void PcamCamera::parameterUpdated()
{
	getBasicMotionInfo(PCAMZOOM_Near, PCAMANGLE_Low)
	    .init(getParameterF(PCAMF_NearLowDistance), getParameterF(PCAMF_NearLowAngle), getParameterF(PCAMF_NearLowFov),
	          getParameterF(PCAMF_NearLowWatchAdjust), getParameterF(PCAMF_NearLowNaviWatchWeight), getParameterF(PCAMF_NearLowBlur));
	getBasicMotionInfo(PCAMZOOM_Middle, PCAMANGLE_Low)
	    .init(getParameterF(PCAMF_MiddleLowDistance), getParameterF(PCAMF_MiddleLowAngle), getParameterF(PCAMF_MiddleLowFov),
	          getParameterF(PCAMF_MiddleLowWatchAdjust), getParameterF(PCAMF_MiddleLowNaviWatchWeight), getParameterF(PCAMF_MiddleLowBlur));
	getBasicMotionInfo(PCAMZOOM_Far, PCAMANGLE_Low)
	    .init(getParameterF(PCAMF_FarLowDistance), getParameterF(PCAMF_FarLowAngle), getParameterF(PCAMF_FarLowFov),
	          getParameterF(PCAMF_FarLowWatchAdjust), getParameterF(PCAMF_FarLowNaviWatchWeight), getParameterF(PCAMF_FarLowBlur));

	getBasicMotionInfo(PCAMZOOM_Near, PCAMANGLE_High)
	    .init(getParameterF(PCAMF_NearHighDistance), getParameterF(PCAMF_NearHighAngle), getParameterF(PCAMF_NearHighFov),
	          getParameterF(PCAMF_NearHighWatchAdjust), getParameterF(PCAMF_NearHighNaviWatchWeight), getParameterF(PCAMF_NearHighBlur));
	getBasicMotionInfo(PCAMZOOM_Middle, PCAMANGLE_High)
	    .init(getParameterF(PCAMF_MiddleHighDistance), getParameterF(PCAMF_MiddleHighAngle), getParameterF(PCAMF_MiddleHighFov),
	          getParameterF(PCAMF_MiddleHighWatchAdjust), getParameterF(PCAMF_MiddleHighNaviWatchWeight),
	          getParameterF(PCAMF_MiddleHighBlur));
	getBasicMotionInfo(PCAMZOOM_Far, PCAMANGLE_High)
	    .init(getParameterF(PCAMF_FarHighDistance), getParameterF(PCAMF_FarHighAngle), getParameterF(PCAMF_FarHighFov),
	          getParameterF(PCAMF_FarHighWatchAdjust), getParameterF(PCAMF_FarHighNaviWatchWeight), getParameterF(PCAMF_FarHighBlur));

	mAttentionInfo.init(getParameterF(PCAMF_AttentionDistance), getParameterF(PCAMF_AttentionAngle), getParameterF(PCAMF_AttentionFov),
	                    getParameterF(PCAMF_AttentionWatchAdjust), getParameterF(PCAMF_AttentionNaviWatchWeight),
	                    getParameterF(PCAMF_AttentionBlur));
}

/**
 * @TODO: Documentation
 */
void PcamCamera::control(Controller& controller)
{
	STACK_PAD_VAR(2);

	bool doRotate = controller.mTriggerL / 170.0f >= getParameterF(PCAMF_RotationButtonThreshold);
	bool isZClick = false;
	if (controller.keyClick(KBBTN_Z)) {
		isZClick = true;
	}
	f32 xSubY = 0.0f;
	if (controller.keyDown(KBBTN_X)) {
		xSubY = controller.getSubStickY();
	}
	PcamControlInfo info;
	info.init(true, doRotate, controller.keyClick(KBBTN_L) != 0, controller.keyClick(KBBTN_R) && !controller.keyDown(KBBTN_X), isZClick,
	          false, false, controller.getMainStickX(), xSubY, controller.getSubStickY());
	control(info);
}

/**
 * @TODO: Documentation
 */
void PcamCamera::control(PcamControlInfo& info)
{
	STACK_PAD_VAR(1);
	if (!mIsActive) {
		return;
	}
	if (!info.mIsActive) {
		return;
	}

	if (mControlsEnabled) {
		if (info.mDoToggleZoom) {
			mToggleZoomPending = 1;
		}
		if (info.mDoAdjustAngle) {
			mAdjustInclinationPending = 1;
		} else if (info.mDoAdjustAngleDown) {
			mAdjustInclinationPending = 2;
		}
	}

	if (mAttentionEnabled && info.mDoAttentionCamera && mAttentionState == AttentionState::Inactive) {
		startAttention();
	}

	if (mAttentionState == AttentionState::Active) {
		return;
	}

	f32 fTime = NSystem::getFrameTime();
	if (info.mDoRotate) {
		if (NMath<f32>::absolute(info.mAzimuthRotIntensity) <= 0.01f) {
			info.mAzimuthRotIntensity = 0.0f;
		}

		f32 p      = -getParameterF(PCAMF_RotationSpeed);
		f32 rotAmt = p * info.mAzimuthRotIntensity * fTime;
		mPolarDir.rotateAzimuth(rotAmt);
		mPolarDir.roundAzimuth();
	}
}

/**
 * @TODO: Documentation
 */
void PcamCamera::startAttention()
{
	mTimers[1]      = getParameterF(PCAMF_AttentionPeriod);
	mAttentionState = AttentionState::Active;
	mCurrentAzimuth = mPolarDir.mAzimuth;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void PcamCamera::playCameraSound(int soundID)
{
	PRINT_NAKATA("playCameraSound:%d\n", soundID);
	SeSystem::playSysSe(soundID);
}

/**
 * @TODO: Documentation
 */
void PcamCamera::update()
{
	mCurrDistance = calcCurrentDistance();
	if (mToggleZoomPending == TRUE) {
		mZoomLevel++;
		if (mZoomLevel >= PCAMZOOM_COUNT) {
			mZoomLevel = PCAMZOOM_Near;
		}
		startMotion(getBasicMotionInfo(mZoomLevel, mInclinationLevel));
		mToggleZoomPending = FALSE;
		playCameraSound(SYSSE_VIEW_CHANGE);
	}

	if (mAdjustInclinationPending == TRUE) {
		mInclinationLevel++;
		if (mInclinationLevel >= PCAMANGLE_COUNT) {
			mInclinationLevel = PCAMANGLE_Low;
		}
		startMotion(getBasicMotionInfo(mZoomLevel, mInclinationLevel));
		mAdjustInclinationPending = FALSE;
		playCameraSound(SYSSE_VIEW_CHANGE);
	}

	updateTimers();
	makePosture();
	makeMatrix();
	makeCamera();
}

/**
 * @TODO: Documentation
 */
void PcamCamera::makePosture()
{
	NVector3f NRef target = NVector3f();
	NVector3f NRef polar  = NVector3f();
	outputTargetWatchpoint(target);

	f32 homingSpeed        = getCurrentHomingSpeed();
	NVector3f NRef moveDir = NVector3f();
	moveDir.sub2(target, getWatchpoint());
	moveDir.scale(homingSpeed);
	target.add2(getWatchpoint(), moveDir);

	if (mAttentionState == AttentionState::Active) {
		if (timerElapsed(1)) {
			mAttentionState = AttentionState::Inactive;
		} else {
			f32 cursorDir       = NMathF::roundAngle(NMathF::pi + getCursorDirection());
			cursorDir           = NMathF::calcNearerDirection(mCurrentAzimuth, cursorDir);
			f32 azimuthDelta    = (cursorDir - mCurrentAzimuth) * getParameterF(PCAMF_AttentionHomingSpeed);
			f32 maxAzimuthSpeed = getParameterF(PCAMF_AttentionAngleMaxSpeed);

			if (azimuthDelta > maxAzimuthSpeed) {
				azimuthDelta = maxAzimuthSpeed;
			} else if (azimuthDelta < -maxAzimuthSpeed) {
				azimuthDelta = -maxAzimuthSpeed;
			}

			mCurrentAzimuth += azimuthDelta;
			mPolarDir.mAzimuth = mCurrentAzimuth;
		}
	}

	makePolarRadius();
	mPolarDir.roundAzimuth();
	mPolarDir.mInclination = angleToMeridian(getCurrentAngle());
	mPolarDir.output(polar);
	polar.add(target);
	moveDir.sub2(polar, getViewpoint());
	moveDir.scale(homingSpeed);
	polar.add2(getViewpoint(), moveDir);
	makeWatchObjectViewpoint(target, polar);

	NPosture3D NRef posture = NPosture3D(polar, target);
	inputPosture(posture);

	f32 fov = getFov();
	fov += (getCurrentFov() - fov) * getParameterF(PCAMF_FovHomingSpeed);
	setFov(fov);
	setBlur(getCurrentBlur());

	STACK_PAD_VAR(1);
	STACK_PAD_TERNARY(fov > 0.0f, 1);
}

/**
 * @TODO: Documentation
 */
void PcamCamera::makePolarRadius()
{
	mPolarDir.mRadius = (mRadiusMode == RadiusMode::Stored) ? mStoredRadius : getGoalDistance();
}

/**
 * @TODO: Documentation
 */
void PcamCamera::makeWatchObjectViewpoint(NVector3f& p1, NVector3f& p2)
{
	if (mCreatureArray->getSize()) {
		NVector3f vec1(p2, p1);
		vec1.normalize();
		NLine line(p2, vec1);
		NOrientation orient(vec1);
		orient.normalize();
		NPlane plane1(orient.getUp(), p2);
		NVector3f vec2;
		orient.outputLeft(vec2);
		NPlane plane2(vec2, p2);

		f32 invtan = 1.0f / NMathF::tan(NMathF::d2r(getFov() / 2.0f) * 0.7f);
		f32 ratio  = invtan / getAspect();
		f32 minVal = f32(INT_MAX);
		for (int i = 0; i < mCreatureArray->getSize(); i++) {
			Creature* creature = mCreatureArray->get(i);
			NVector3f vec3;
			creature->outputPosition(vec3);
			NVector3f vec4;
			plane1.outputVerticalPosition(vec3, vec4);

			f32 vertProj = 0.0f;
			f32 dist     = line.calcDistance(vec4, &vertProj);
			STACK_PAD_VAR(1);
			f32 b = vertProj - (dist * ratio);
			NVector3f vec5;
			plane2.outputVerticalPosition(vec3, vec5);
			f32 vertProj2 = 0.0f;
			f32 dist2     = line.calcDistance(vec5, &vertProj2);
			f32 c         = vertProj2 - (dist2 * invtan);
			f32 min       = NMath<f32>::minValue(b, c);
			if (min < minVal) {
				minVal = min;
			}
		}

		if (minVal < 0.0f) {
			line.outputPosition(minVal, p2);
		}
	}

	STACK_PAD_VAR(1);
}

/**
 * @TODO: Documentation
 */
void PcamCamera::updateTimers()
{
	f32 fTime = NSystem::getFrameTime();
	for (int i = 0; i < 3; i++) {
		if (mTimers[i] > 0.0f) {
			mTimers[i] -= fTime;
			if (mTimers[i] < 0.0f) {
				mTimers[i] = 0.0f;
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void PcamCamera::startMotion(int zoom, int incl)
{
	mZoomLevel        = zoom;
	mInclinationLevel = incl;
	startMotion(getBasicMotionInfo(mZoomLevel, mInclinationLevel));
}

/**
 * @TODO: Documentation
 */
void PcamCamera::startMotion(immut PcamMotionInfo& info)
{
	PRINT_NAKATA("startMotion\n");
	mPrevMotionInfo   = mTargetMotionInfo;
	mTargetMotionInfo = info;
	mTimers[0]        = getParameterF(PCAMF_ChangingMotionPeriod);
}

/**
 * @TODO: Documentation
 */
void PcamCamera::finishMotion()
{
	PRINT_NAKATA("finishMotion\n");
	startMotion(PcamMotionInfo(mPrevMotionInfo));
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
f32 PcamCamera::getChangingMotionRate()
{
	f32 ratio = mTimers[0] / getParameterF(PCAMF_ChangingMotionPeriod);
	return 1.0f - ratio;
}

/**
 * @TODO: Documentation
 */
f32 PcamCamera::getGoalDistance()
{
	return NMathF::interpolate(mPrevMotionInfo.mDistance, mTargetMotionInfo.mDistance, getChangingMotionRate()) * mDistanceMultiplier;
}

/**
 * @TODO: Documentation
 */
f32 PcamCamera::getCurrentAngle()
{
	return NMathF::interpolate(mPrevMotionInfo.mAngle, mTargetMotionInfo.mAngle, getChangingMotionRate());
}

/**
 * @TODO: Documentation
 */
f32 PcamCamera::getCurrentFov()
{
	f32 rate = getChangingMotionRate();
	return NMathF::interpolate(mPrevMotionInfo.mFov, mTargetMotionInfo.mFov, rate);
}

/**
 * @TODO: Documentation
 */
f32 PcamCamera::getCurrentHomingSpeed()
{
	return getParameterF(PCAMF_HomingSpeed);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000060
 */
f32 PcamCamera::getCurrentWatchAdjustment()
{
	return NMathF::interpolate(mPrevMotionInfo.mWatchAdjustment, mTargetMotionInfo.mWatchAdjustment, getChangingMotionRate());
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000060
 */
f32 PcamCamera::getCurrentNaviWatchWeight()
{
	return NMathF::interpolate(mPrevMotionInfo.mNaviWatchWeight, mTargetMotionInfo.mNaviWatchWeight, getChangingMotionRate());
}

/**
 * @TODO: Documentation
 */
f32 PcamCamera::getCurrentBlur()
{
	return NMathF::interpolate(mPrevMotionInfo.mBlur, mTargetMotionInfo.mBlur, getChangingMotionRate());
}

/**
 * @TODO: Documentation
 */
f32 PcamCamera::calcCurrentDistance()
{
	return getWatchpoint().distance(getViewpoint());
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000074
 */
f32 PcamCamera::calcCurrentDirection()
{
	NPosture3D NRef posture = NPosture3D();
	outputPosture(posture);
	return posture.calcDirection() + NMathF::pi;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000074
 */
f32 PcamCamera::calcTargetDistance()
{
	NVector3f NRef targetPos = NVector3f(mTargetCreature->mSRT.t);
	return targetPos.distance(getViewpoint());
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
f32 PcamCamera::getTargetDirection()
{
	return mTargetCreature->mSRT.r.y;
}

/**
 * @TODO: Documentation
 */
f32 PcamCamera::getCursorDirection()
{
	NVector3f targetPos;
	outputTargetPosition(targetPos);
	NVector3f cursorPos;
	outputCursorPosition(cursorPos);
	NVector3f dir;
	dir.sub(cursorPos, targetPos);
	return calcDirection(dir);
}

/**
 * @TODO: Documentation
 */
void PcamCamera::outputTargetPosition(NVector3f& outPosition)
{
	outPosition.input(mTargetCreature->mSRT.t);
}

/**
 * @TODO: Documentation
 */
void PcamCamera::outputCursorPosition(NVector3f& outPosition)
{
	if (mTargetCreature->mObjType == OBJTYPE_Navi) {
		Navi* navi = static_cast<Navi*>(mTargetCreature);
		outPosition.input(navi->mCursorWorldPos);
	} else {
		outPosition.input(mTargetCreature->getPosition());
	}
}

/**
 * @TODO: Documentation
 */
void PcamCamera::outputFormationWatchpoint(Navi* navi, NVector3f& outWatchPt)
{
	NVector3f pos(navi->getPosition());
	outWatchPt.input(pos);
	f32 naviWeight = getCurrentNaviWatchWeight();
	if (naviWeight > 0.0f) {
		outWatchPt.scale(naviWeight);
		int pikiCount    = 0;
		CPlate* plateMgr = navi->mPlateMgr;
		if (plateMgr) {
			Iterator iter(plateMgr);
			CI_LOOP(iter)
			{
				Creature* piki = *iter;
				f32 dist       = pos.distanceXZ(piki->getPosition());
				if (dist <= getParameterF(PCAMF_IgnoringPikiDistance)) {
					outWatchPt.add(piki->getPosition());
					pikiCount++;
				}
			}
		}

		outWatchPt.div(naviWeight + f32(pikiCount));
	}
}

/**
 * @TODO: Documentation
 */
void PcamCamera::outputTargetWatchpoint(NVector3f& outWatchPt)
{
	if (mTargetCreature->mObjType == OBJTYPE_Navi) {
		outputFormationWatchpoint(static_cast<Navi*>(mTargetCreature), outWatchPt);
	} else {
		outWatchPt.input(mTargetCreature->getPosition());
	}

	f32 adjust = getCurrentWatchAdjustment();
	outWatchPt.y += adjust;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
void PcamCamera::makePolar()
{
	NVector3f dir;
	dir.sub2(getViewpoint(), getWatchpoint());
	mPolarDir.input(dir);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000148
 */
void PcamCamera::printInfo(Graphics& gfx, Font* font)
{
	// there's more to this, but this is enough to generate the right string for data
	gfx.texturePrintf(font, 20, 400, "%2d,%3d,%4.0f,%4.0f,%4.0f,%3.2f,%3.2f,%3.2f", 90 - NMathF::r2d(mPolarDir.mInclination), mCurrDistance,
	                  mPolarDir.mRadius, mStoredRadius);
	// UNUSED FUNCTION
}
