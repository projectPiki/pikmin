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
#include "sysNew.h"
#include <limits.h>

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("pcamcamera")

/**
 * @todo: Documentation
 */
PcamMotionInfo::PcamMotionInfo()
{
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void PcamMotionInfo::println()
{
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void PcamControlInfo::init(bool isActive, bool doRotate, bool doAttentionCamera, bool doToggleZoom, bool doAdjustAngle,
                           bool doAdjustAngleDown, bool unused06, f32 azimuthRotIntensity, f32 subStickInput, f32 subStickY)
{
	mIsActive            = isActive;
	mDoRotate            = doRotate;
	mDoAttentionCamera   = doAttentionCamera;
	mDoToggleZoom        = doToggleZoom;
	mDoAdjustAngle       = doAdjustAngle;
	mDoAdjustAngleDown   = doAdjustAngleDown;
	_UNUSED06            = unused06;
	mAzimuthRotIntensity = azimuthRotIntensity;
	mSubStickInput       = subStickInput;
	mSubStickY           = subStickY;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void PcamCamera::startCamera(Creature* target)
{
	startCamera(target, PCAMZOOM_Near, PCAMANGLE_Low);
}

/**
 * @todo: Documentation
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

	if (flowCont.mIsVersusMode == TRUE) {
		mCreatureArray->add(naviMgr->getNavi(0));
		mCreatureArray->add(naviMgr->getNavi(1));
	}

	makeCurrentPosition(target->mFaceDirection + NMathF::pi);
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
 */
void PcamCamera::startAttention()
{
	mTimers[1]      = getParameterF(PCAMF_AttentionPeriod);
	mAttentionState = AttentionState::Active;
	mCurrentAzimuth = mPolarDir.mAzimuth;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void PcamCamera::playCameraSound(int soundID)
{
	PRINT_NAKATA("playCameraSound:%d\n", soundID);
	SeSystem::playSysSe(soundID);
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
 */
void PcamCamera::makePolarRadius()
{
	mPolarDir.mRadius = (mRadiusMode == RadiusMode::Stored) ? mStoredRadius : getGoalDistance();
}

/**
 * @todo: Documentation
 */
void PcamCamera::makeWatchObjectViewpoint(NVector3f& watchPt, NVector3f& viewPt)
{
	if (mCreatureArray->getSize()) {
		NVector3f viewToWatchDir(viewPt, watchPt);
		viewToWatchDir.normalize();
		NLine viewLine(viewPt, viewToWatchDir);
		NOrientation viewOrient(viewToWatchDir);
		viewOrient.normalize();
		NPlane upPlane(viewOrient.getUp(), viewPt);
		NVector3f leftDir;
		viewOrient.outputLeft(leftDir);
		NPlane leftPlane(leftDir, viewPt);

		f32 invTanHalfFov = 1.0f / NMathF::tan(NMathF::d2r(getFov() / 2.0f) * 0.7f);
		f32 aspectRatio   = invTanHalfFov / getAspect();
		f32 minOffset     = f32(INT_MAX);
		for (int i = 0; i < mCreatureArray->getSize(); i++) {
			Creature* creature = mCreatureArray->get(i);
			NVector3f creaturePos;
			creature->outputPosition(creaturePos);
			NVector3f upPlanePos;
			upPlane.outputVerticalPosition(creaturePos, upPlanePos);

			f32 alongViewDir = 0.0f;
			f32 planeDist    = viewLine.calcDistance(upPlanePos, &alongViewDir);
			STACK_PAD_VAR(1);
			f32 horizOffset = alongViewDir - (planeDist * aspectRatio);
			NVector3f leftPlanePos;
			leftPlane.outputVerticalPosition(creaturePos, leftPlanePos);
			f32 alongViewDir2 = 0.0f;
			f32 planeDist2    = viewLine.calcDistance(leftPlanePos, &alongViewDir2);
			f32 vertOffset    = alongViewDir2 - (planeDist2 * invTanHalfFov);
			f32 offset        = NMath<f32>::minValue(horizOffset, vertOffset);
			if (offset < minOffset) {
				minOffset = offset;
			}
		}

		if (minOffset < 0.0f) {
			viewLine.outputPosition(minOffset, viewPt);
		}
	}

	STACK_PAD_VAR(1);
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void PcamCamera::startMotion(int zoom, int incl)
{
	mZoomLevel        = zoom;
	mInclinationLevel = incl;
	startMotion(getBasicMotionInfo(mZoomLevel, mInclinationLevel));
}

/**
 * @todo: Documentation
 */
void PcamCamera::startMotion(immut PcamMotionInfo& info)
{
	PRINT_NAKATA("startMotion\n");
	mPrevMotionInfo   = mTargetMotionInfo;
	mTargetMotionInfo = info;
	mTimers[0]        = getParameterF(PCAMF_ChangingMotionPeriod);
}

/**
 * @todo: Documentation
 */
void PcamCamera::finishMotion()
{
	PRINT_NAKATA("finishMotion\n");
	startMotion(PcamMotionInfo(mPrevMotionInfo));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000028
 */
f32 PcamCamera::getChangingMotionRate()
{
	f32 ratio = mTimers[0] / getParameterF(PCAMF_ChangingMotionPeriod);
	return 1.0f - ratio;
}

/**
 * @todo: Documentation
 */
f32 PcamCamera::getGoalDistance()
{
	return NMathF::interpolate(mPrevMotionInfo.mDistance, mTargetMotionInfo.mDistance, getChangingMotionRate()) * mDistanceMultiplier;
}

/**
 * @todo: Documentation
 */
f32 PcamCamera::getCurrentAngle()
{
	return NMathF::interpolate(mPrevMotionInfo.mAngle, mTargetMotionInfo.mAngle, getChangingMotionRate());
}

/**
 * @todo: Documentation
 */
f32 PcamCamera::getCurrentFov()
{
	f32 rate = getChangingMotionRate();
	return NMathF::interpolate(mPrevMotionInfo.mFov, mTargetMotionInfo.mFov, rate);
}

/**
 * @todo: Documentation
 */
f32 PcamCamera::getCurrentHomingSpeed()
{
	return getParameterF(PCAMF_HomingSpeed);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000060
 */
f32 PcamCamera::getCurrentWatchAdjustment()
{
	return NMathF::interpolate(mPrevMotionInfo.mWatchAdjustment, mTargetMotionInfo.mWatchAdjustment, getChangingMotionRate());
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000060
 */
f32 PcamCamera::getCurrentNaviWatchWeight()
{
	return NMathF::interpolate(mPrevMotionInfo.mNaviWatchWeight, mTargetMotionInfo.mNaviWatchWeight, getChangingMotionRate());
}

/**
 * @todo: Documentation
 */
f32 PcamCamera::getCurrentBlur()
{
	return NMathF::interpolate(mPrevMotionInfo.mBlur, mTargetMotionInfo.mBlur, getChangingMotionRate());
}

/**
 * @todo: Documentation
 */
f32 PcamCamera::calcCurrentDistance()
{
	return getWatchpoint().distance(getViewpoint());
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000074
 */
f32 PcamCamera::calcCurrentDirection()
{
	NPosture3D NRef posture = NPosture3D();
	outputPosture(posture);
	return posture.calcDirection() + NMathF::pi;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000074
 */
f32 PcamCamera::calcTargetDistance()
{
	NVector3f NRef targetPos = NVector3f(mTargetCreature->mSRT.t);
	return targetPos.distance(getViewpoint());
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00000C
 */
f32 PcamCamera::getTargetDirection()
{
	return mTargetCreature->mSRT.r.y;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void PcamCamera::outputTargetPosition(NVector3f& outPosition)
{
	outPosition.input(mTargetCreature->mSRT.t);
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
 * @note UNUSED Size: 00006C
 */
void PcamCamera::makePolar()
{
	NVector3f dir;
	dir.sub2(getViewpoint(), getWatchpoint());
	mPolarDir.input(dir);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000148
 */
void PcamCamera::printInfo(Graphics& gfx, Font* font)
{
	// UNUSED FUNCTION (It's way over-size and I don't know why)

	int x = 20, y = 400;

	NVector3f vec1(mCamera->mViewZAxis.x, 0.0f, mCamera->mViewZAxis.z);
	vec1.normalise();
	f32 angle1 = NMathF::atan2(vec1.x, -vec1.z);

	// This isn't even used for anything.
	NVector3f vec2(mTargetCreature->mVelocity.x, 0.0f, mTargetCreature->mVelocity.z);
	vec2.normalizeCheck();
	// Maybe they wanted a second `atan2` angle here and that explains the missing printf argument below?

	gfx.setColour(Colour(255, 255, 255, 255), true);
	// Why are there only 7 arguments for a format string with 8 conversion specifiers?  Ugh.
	gfx.texturePrintf(font, x, y, "%2d,%3d,%4.0f,%4.0f,%4.0f,%3.2f,%3.2f,%3.2f", 90 - int(NMathF::r2d(mPolarDir.mInclination)),
	                  int(getFov()), mCurrDistance, mPolarDir.mRadius, mStoredRadius, angle1,
	                  getTargetDirection() TERNARY_BUGFIX(MACRO_ARG(, 0.0f), ));
}
