#include "Pcam/Camera.h"
#include "Pcam/CameraParameters.h"
#include "Creature.h"
#include "ParaParameters.h"
#include "NaviMgr.h"
#include "CPlate.h"
#include "SoundMgr.h"
#include "nlib/System.h"
#include "nlib/Geometry3D.h"
#include "FlowController.h"
#include "sysNew.h"
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
DEFINE_PRINT("pcamcamera")

/*
 * --INFO--
 * Address:	80121BB8
 * Size:	000004
 */
PcamMotionInfo::PcamMotionInfo()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
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

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PcamMotionInfo::println()
{
}

/*
 * --INFO--
 * Address:	80121BBC
 * Size:	000024
 */
PcamControlInfo::PcamControlInfo()
{
	_00                = false;
	mDoRotate          = false;
	mDoAttentionCamera = false;
	mDoToggleZoom      = false;
	mDoAdjustAngle     = false;
	_05                = false;
	_06                = false;
}

/*
 * --INFO--
 * Address:	80121BE0
 * Size:	00002C
 */
void PcamControlInfo::init(bool p1, bool doRotate, bool doAttention, bool toggleZoom, bool adjustAngle, bool p6, bool p7, f32 azimuthRot,
                           f32 p9, f32 p10)
{
	_00                  = p1;
	mDoRotate            = doRotate;
	mDoAttentionCamera   = doAttention;
	mDoToggleZoom        = toggleZoom;
	mDoAdjustAngle       = adjustAngle;
	_05                  = p6;
	_06                  = p7;
	mAzimuthRotIntensity = azimuthRot;
	_0C                  = p9;
	_10                  = p10;
}

/*
 * --INFO--
 * Address:	80121C0C
 * Size:	000134
 */
PcamCamera::PcamCamera(Camera* camera)
    : NCamera(camera)
{
	mParameters = new PcamCameraParameters();
	mParameters->load("camera/", "camepara.bin", 1);
	mCreatureArray = new NArray<Creature>(4);
	_B4            = 2000.0f;
	_B8            = NMathF::d2r(2.0f);
	_BC            = NMathF::d2r(80.0f);
}

/*
 * --INFO--
 * Address:	80121D40
 * Size:	000028
 */
void PcamCamera::startCamera(Creature* target)
{
	startCamera(target, PCAMZOOM_Near, PCAMANGLE_Low);
}

/*
 * --INFO--
 * Address:	80121D68
 * Size:	00018C
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

	_A4 = 1.0f;
	_20 = 1;
	_28 = 1;
	_30 = 1;

	mToggleZoomPending        = FALSE;
	mAdjustInclinationPending = FALSE;
	_98                       = 0;
	_9C                       = 0;

	for (int i = 0; i < 3; i++) {
		mTimers[i] = 0.0f;
	}

	if (flowCont.mNaviOnMap == 1) {
		mCreatureArray->add(naviMgr->getNavi(0));
		mCreatureArray->add(naviMgr->getNavi(1));
	}

	makeCurrentPosition(target->mFaceDirection + NMathF::pi);
}

/*
 * --INFO--
 * Address:	80121F2C
 * Size:	0000DC
 */
void PcamCamera::makeCurrentPosition(f32 azimuth)
{
	mPolarDir.set(mTargetMotionInfo.mDistance, angleToMeridian(mTargetMotionInfo.mAngle), azimuth);
	_A8 = mPolarDir.mRadius;
	NVector3f watchPt;
	outputTargetWatchpoint(watchPt);

	NVector3f viewPt;
	mPolarDir.output(viewPt);

	viewPt.add(watchPt);
	inputViewpoint(viewPt);
	inputWatchpoint(watchPt);
}

/*
 * --INFO--
 * Address:	80122008
 * Size:	0004CC
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

/*
 * --INFO--
 * Address:	801224E4
 * Size:	000154
 */
void PcamCamera::control(Controller& controller)
{
	u32 badCompiler[2];

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

/*
 * --INFO--
 * Address:	80122638
 * Size:	00017C
 */
void PcamCamera::control(PcamControlInfo& info)
{
	u32 badCompiler;
	if (!_20) {
		return;
	}
	if (!info._00) {
		return;
	}

	if (_30) {
		if (info.mDoToggleZoom) {
			mToggleZoomPending = 1;
		}
		if (info.mDoAdjustAngle) {
			mAdjustInclinationPending = 1;
		} else if (info._05) {
			mAdjustInclinationPending = 2;
		}
	}

	if (_28 && info.mDoAttentionCamera && !_9C) {
		startAttention();
	}

	if (_9C == 1) {
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

/*
 * --INFO--
 * Address:	801227B4
 * Size:	00002C
 */
void PcamCamera::startAttention()
{
	mTimers[1] = getParameterF(PCAMF_AttentionPeriod);
	_9C        = 1;
	_B0        = mPolarDir.mAzimuth;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void PcamCamera::playCameraSound(int soundID)
{
	PRINT("playCameraSound:%d\n", soundID);
	SeSystem::playSysSe(soundID);
}

/*
 * --INFO--
 * Address:	801227E0
 * Size:	000110
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

/*
 * --INFO--
 * Address:	801228F0
 * Size:	0003A0
 */
void PcamCamera::makePosture()
{
	NVector3f& watchPt = NVector3f();
	NVector3f& polar   = NVector3f();
	outputTargetWatchpoint(watchPt);
	f32 homingSpeed = getCurrentHomingSpeed();
	NVector3f& vec  = NVector3f();
	vec.sub2(watchPt, getWatchpoint());
	vec.scale(homingSpeed);
	watchPt.add2(getWatchpoint(), vec);

	if (_9C == 1) {
		if (timerElapsed(1)) {
			_9C = 0;
		} else {
			f32 cursorDir = NMathF::roundAngle(NMathF::pi + getCursorDirection());
			cursorDir     = NMathF::calcNearerDirection(_B0, cursorDir);
			f32 a         = (cursorDir - _B0) * getParameterF(PCAMF_AttentionHomingSpeed);
			f32 b         = getParameterF(PCAMF_AttentionAngleMaxSpeed);
			if (a > b) {
				a = b;
			} else if (a < -b) {
				a = -b;
			}
			_B0 += a;
			mPolarDir.mAzimuth = _B0;
		}
	}

	makePolarRadius();
	mPolarDir.roundAzimuth();
	mPolarDir.mInclination = angleToMeridian(getCurrentAngle());
	mPolarDir.output(polar);
	polar.add(watchPt);
	vec.sub2(polar, getViewpoint());
	vec.scale(homingSpeed);
	polar.add2(getViewpoint(), vec);
	makeWatchObjectViewpoint(watchPt, polar);

	NPosture3D& posture = NPosture3D(polar, watchPt);
	inputPosture(posture);

	f32 fov = getFov();
	fov += (getCurrentFov() - fov) * getParameterF(PCAMF_FovHomingSpeed);
	setFov(fov);
	setBlur(getCurrentBlur());

	u32 badCompiler;
	PRINT("FAKE", fov > 0.0f ? "FAKE" : "FAKE");
}

/*
 * --INFO--
 * Address:	80122C90
 * Size:	000048
 */
void PcamCamera::makePolarRadius()
{
	mPolarDir.mRadius = (_A0 == 1) ? _A8 : getGoalDistance();
}

/*
 * --INFO--
 * Address:	80122CD8
 * Size:	000228
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
		f32 minVal = 2147483600.0f;
		for (int i = 0; i < mCreatureArray->getSize(); i++) {
			Creature* creature = mCreatureArray->get(i);
			NVector3f vec3;
			creature->outputPosition(vec3);
			NVector3f vec4;
			plane1.outputVerticalPosition(vec3, vec4);

			f32 vertProj = 0.0f;
			f32 dist     = line.calcDistance(vec4, &vertProj);
			u32 badCompiler;
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

	u32 badCompiler2;
}

/*
 * --INFO--
 * Address:	80122F30
 * Size:	000084
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

/*
 * --INFO--
 * Address:	80122FB4
 * Size:	000044
 */
void PcamCamera::startMotion(int zoom, int incl)
{
	mZoomLevel        = zoom;
	mInclinationLevel = incl;
	startMotion(getBasicMotionInfo(mZoomLevel, mInclinationLevel));
}

/*
 * --INFO--
 * Address:	80122FF8
 * Size:	00007C
 */
void PcamCamera::startMotion(PcamMotionInfo& info)
{
	PRINT("startMotion\n");
	mPrevMotionInfo   = mTargetMotionInfo;
	mTargetMotionInfo = info;
	mTimers[0]        = getParameterF(PCAMF_ChangingMotionPeriod);
}

/*
 * --INFO--
 * Address:	80123074
 * Size:	0000D0
 */
void PcamCamera::finishMotion()
{
	startMotion(PcamMotionInfo(mPrevMotionInfo));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
f32 PcamCamera::getChangingMotionRate()
{
	f32 ratio = mTimers[0] / getParameterF(PCAMF_ChangingMotionPeriod);
	return 1.0f - ratio;
}

/*
 * --INFO--
 * Address:	80123144
 * Size:	00006C
 */
f32 PcamCamera::getGoalDistance()
{
	return NMathF::interpolate(mPrevMotionInfo.mDistance, mTargetMotionInfo.mDistance, getChangingMotionRate()) * _A4;
}

/*
 * --INFO--
 * Address:	801231B0
 * Size:	000060
 */
f32 PcamCamera::getCurrentAngle()
{
	return NMathF::interpolate(mPrevMotionInfo.mAngle, mTargetMotionInfo.mAngle, getChangingMotionRate());
}

/*
 * --INFO--
 * Address:	80123224
 * Size:	000064
 */
f32 PcamCamera::getCurrentFov()
{
	f32 rate = getChangingMotionRate();
	return NMathF::interpolate(mPrevMotionInfo.mFov, mTargetMotionInfo.mFov, rate);
}

/*
 * --INFO--
 * Address:	80123288
 * Size:	000018
 */
f32 PcamCamera::getCurrentHomingSpeed()
{
	return getParameterF(PCAMF_HomingSpeed);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
f32 PcamCamera::getCurrentWatchAdjustment()
{
	return NMathF::interpolate(mPrevMotionInfo.mWatchAdjustment, mTargetMotionInfo.mWatchAdjustment, getChangingMotionRate());
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
f32 PcamCamera::getCurrentNaviWatchWeight()
{
	return NMathF::interpolate(mPrevMotionInfo.mNaviWatchWeight, mTargetMotionInfo.mNaviWatchWeight, getChangingMotionRate());
}

/*
 * --INFO--
 * Address:	801232A0
 * Size:	000060
 */
f32 PcamCamera::getCurrentBlur()
{
	return NMathF::interpolate(mPrevMotionInfo.mBlur, mTargetMotionInfo.mBlur, getChangingMotionRate());
}

/*
 * --INFO--
 * Address:	80123300
 * Size:	00005C
 */
f32 PcamCamera::calcCurrentDistance()
{
	return getWatchpoint().distance(getViewpoint());
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
f32 PcamCamera::calcCurrentDirection()
{
	NPosture3D& posture = NPosture3D();
	outputPosture(posture);
	return posture.calcDirection() + NMathF::pi;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
f32 PcamCamera::calcTargetDistance()
{
	NVector3f& targetPos = NVector3f(mTargetCreature->mPosition);
	return targetPos.distance(getViewpoint());
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
f32 PcamCamera::getTargetDirection()
{
	return mTargetCreature->mRotation.y;
}

/*
 * --INFO--
 * Address:	8012335C
 * Size:	000094
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

/*
 * --INFO--
 * Address:	801233F0
 * Size:	000020
 */
void PcamCamera::outputTargetPosition(NVector3f& outPosition)
{
	outPosition.input(mTargetCreature->mPosition);
}

/*
 * --INFO--
 * Address:	80123410
 * Size:	000048
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

/*
 * --INFO--
 * Address:	80123458
 * Size:	00026C
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

/*
 * --INFO--
 * Address:	801236C4
 * Size:	0000B4
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

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void PcamCamera::makePolar()
{
	NVector3f dir;
	dir.sub2(getViewpoint(), getWatchpoint());
	mPolarDir.input(dir);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
void PcamCamera::printInfo(Graphics& gfx, Font* font)
{
	// there's more to this, but this is enough to generate the right string for data
	gfx.texturePrintf(font, 20, 400, "%2d,%3d,%4.0f,%4.0f,%4.0f,%3.2f,%3.2f,%3.2f", 90 - NMathF::r2d(mPolarDir.mInclination), mCurrDistance,
	                  mPolarDir.mRadius, _A8);
	// UNUSED FUNCTION
}
