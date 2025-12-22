#include "DebugLog.h"
#include "Pcam/CameraParameters.h"
#include "nlib/Math.h"

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
DEFINE_PRINT("pcamcameraparameters")

PcamCameraParameters::PcamCameraParameters()
{
	ParaParameterInfoI* intParams = new ParaParameterInfoI[PCAMI_COUNT];
	int j                         = 0;
	intParams[j++].init("CAMERA_SWITCH", FALSE, TRUE);

	ParaParameterInfoF* f32Params = new ParaParameterInfoF[PCAMF_COUNT];
	j                             = 0;
	f32Params[j++].init("NEAR_LOW_DISTANCE", 10.0f, 2000.0f);
	f32Params[j++].init("NEAR_LOW_ANGLE", 0.0f, 80.0f);
	f32Params[j++].init("NEAR_LOW_FOV", 10.0f, 170.0f);
	f32Params[j++].init("NEAR_LOW_WATCH_ADJUSTMENT", -500.0f, 500.0f);
	f32Params[j++].init("NEAR_LOW_NAVI_WATCH_WEIGHT", 0.0f, 1000.0f);
	f32Params[j++].init("NEAR_LOW_BLUR", 0.0f, 255.0f);
	f32Params[j++].init("MIDDLE_LOW_DISTANCE", 10.0f, 2000.0f);
	f32Params[j++].init("MIDDLE_LOW_ANGLE", 0.0f, 80.0f);
	f32Params[j++].init("MIDDLE_LOW_FOV", 10.0f, 170.0f);
	f32Params[j++].init("MIDDLE_LOW_WATCH_ADJUSTMENT", -500.0f, 500.0f);
	f32Params[j++].init("MIDDLE_LOW_NAVI_WATCH_WEIGHT", 0.0f, 1000.0f);
	f32Params[j++].init("MIDDLE_LOW_BLUR", 0.0f, 255.0f);
	f32Params[j++].init("FAR_LOW_DISTANCE", 10.0f, 2000.0f);
	f32Params[j++].init("FAR_LOW_ANGLE", 0.0f, 80.0f);
	f32Params[j++].init("FAR_LOW_FOV", 10.0f, 170.0f);
	f32Params[j++].init("FAR_LOW_WATCH_ADJUSTMENT", -500.0f, 500.0f);
	f32Params[j++].init("FAR_LOW_NAVI_WATCH_WEIGHT", 0.0f, 1000.0f);
	f32Params[j++].init("FAR_LOW_BLUR", 0.0f, 255.0f);
	f32Params[j++].init("NEAR_HIGH_DISTANCE", 10.0f, 2000.0f);
	f32Params[j++].init("NEAR_HIGH_ANGLE", 0.0f, 80.0f);
	f32Params[j++].init("NEAR_HIGH_FOV", 10.0f, 170.0f);
	f32Params[j++].init("NEAR_HIGH_WATCH_ADJUSTMENT", -500.0f, 500.0f);
	f32Params[j++].init("NEAR_HIGH_NAVI_WATCH_WEIGHT", 0.0f, 1000.0f);
	f32Params[j++].init("NEAR_HIGH_BLUR", 0.0f, 255.0f);
	f32Params[j++].init("MIDDLE_HIGH_DISTANCE", 10.0f, 2000.0f);
	f32Params[j++].init("MIDDLE_HIGH_ANGLE", 0.0f, 80.0f);
	f32Params[j++].init("MIDDLE_HIGH_FOV", 10.0f, 170.0f);
	f32Params[j++].init("MIDDLE_HIGH_WATCH_ADJUSTMENT", -500.0f, 500.0f);
	f32Params[j++].init("MIDDLE_HIGH_NAVI_WATCH_WEIGHT", 0.0f, 1000.0f);
	f32Params[j++].init("MIDDLE_HIGH_BLUR", 0.0f, 255.0f);
	f32Params[j++].init("FAR_HIGH_DISTANCE", 10.0f, 2000.0f);
	f32Params[j++].init("FAR_HIGH_ANGLE", 0.0f, 80.0f);
	f32Params[j++].init("FAR_HIGH_FOV", 10.0f, 170.0f);
	f32Params[j++].init("FAR_HIGH_WATCH_ADJUSTMENT", -500.0f, 500.0f);
	f32Params[j++].init("FAR_HIGH_NAVI_WATCH_WEIGHT", 0.0f, 1000.0f);
	f32Params[j++].init("FAR_HIGH_BLUR", 0.0f, 255.0f);
	f32Params[j++].init("NAVI_ATTENTION_DISTANCE", 10.0f, 2000.0f);
	f32Params[j++].init("NAVI_ATTENTION_ANGLE", 0.0f, 80.0f);
	f32Params[j++].init("NAVI_ATTENTION_FOV", 10.0f, 170.0f);
	f32Params[j++].init("NAVI_ATTENTION_WATCH_ADJUSTMENT", -500.0f, 500.0f);
	f32Params[j++].init("NAVI_ATTENTION_NAVI_WATCH_WEIGHT", 0.0f, 1000.0f);
	f32Params[j++].init("NAVI_ATTENTION_BLUR", 0.0f, 255.0f);
	f32Params[j++].init("HOMING_SPEED", 0.05f, 1.0f);
	f32Params[j++].init("FOV_HOMING_SPEED", 0.05f, 1.0f);
	f32Params[j++].init("ROTATION_SPEED", 0.0f, 10.0f);
	f32Params[j++].init("TRANSLATION_SPEED", 0.0f, 10.0f);
	f32Params[j++].init("ATTENTION_HOMING_SPEED", 0.05f, 1.0f);
	f32Params[j++].init("ATTENTION_PERIOD", 0.2f, 2.0f);
	f32Params[j++].init("CHANGING_MOTION_PERIOD", 0.0f, 5.0f);
	f32Params[j++].init("ROTATION_BUTTON_THRESHOLD", 0.0f, 2.0f);
	f32Params[j++].init("CAMERA_RESERVED_0", 0.0f, 1.0f);
	f32Params[j++].init("CAMERA_RESERVED_1", 0.0f, 1.0f);
	f32Params[j++].init("IGNORING_PIKI_DISTANCE", 0.0f, 10000.0f);
	f32Params[j++].init("VIBRATION_DISTANCE", 0.0f, 10000.0f);
	f32Params[j++].init("ATTENTION_ANGLE_MAX_SPEED", 0.0f, NMathF::pi / 4.0f);

	mParameters = new ParaMultiParameters(PCAMI_COUNT, intParams, PCAMF_COUNT, f32Params);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(PCAMI_CameraSwitch, FALSE);

	multiP->setF(PCAMF_NearLowDistance, 700.0f);
	multiP->setF(PCAMF_NearLowAngle, 20.0f);
	multiP->setF(PCAMF_NearLowFov, 10.0f);
	multiP->setF(PCAMF_NearLowWatchAdjust, 40.0f);
	multiP->setF(PCAMF_NearLowNaviWatchWeight, 1000.0f);
	multiP->setF(PCAMF_NearLowBlur, 50.0f);

	multiP->setF(PCAMF_MiddleLowDistance, 700.0f);
	multiP->setF(PCAMF_MiddleLowAngle, 20.0f);
	multiP->setF(PCAMF_MiddleLowFov, 25.0f);
	multiP->setF(PCAMF_MiddleLowWatchAdjust, 70.0f);
	multiP->setF(PCAMF_MiddleLowNaviWatchWeight, 500.0f);
	multiP->setF(PCAMF_MiddleLowBlur, 95.0f);

	multiP->setF(PCAMF_FarLowDistance, 1200.0f);
	multiP->setF(PCAMF_FarLowAngle, 20.0f);
	multiP->setF(PCAMF_FarLowFov, 25.0f);
	multiP->setF(PCAMF_FarLowWatchAdjust, 100.0f);
	multiP->setF(PCAMF_FarLowNaviWatchWeight, 200.0f);
	multiP->setF(PCAMF_FarLowBlur, 110.0f);

	multiP->setF(PCAMF_NearHighDistance, 700.0f);
	multiP->setF(PCAMF_NearHighAngle, 50.0f);
	multiP->setF(PCAMF_NearHighFov, 10.0f);
	multiP->setF(PCAMF_NearHighWatchAdjust, 40.0f);
	multiP->setF(PCAMF_NearHighNaviWatchWeight, 1000.0f);
	multiP->setF(PCAMF_NearHighBlur, 50.0f);

	multiP->setF(PCAMF_MiddleHighDistance, 700.0f);
	multiP->setF(PCAMF_MiddleHighAngle, 50.0f);
	multiP->setF(PCAMF_MiddleHighFov, 30.0f);
	multiP->setF(PCAMF_MiddleHighWatchAdjust, 70.0f);
	multiP->setF(PCAMF_MiddleHighNaviWatchWeight, 500.0f);
	multiP->setF(PCAMF_MiddleHighBlur, 95.0f);

	multiP->setF(PCAMF_FarHighDistance, 1200.0f);
	multiP->setF(PCAMF_FarHighAngle, 50.0f);
	multiP->setF(PCAMF_FarHighFov, 30.0f);
	multiP->setF(PCAMF_FarHighWatchAdjust, 100.0f);
	multiP->setF(PCAMF_FarHighNaviWatchWeight, 200.0f);
	multiP->setF(PCAMF_FarHighBlur, 110.0f);

	multiP->setF(PCAMF_AttentionDistance, 700.0f);
	multiP->setF(PCAMF_AttentionAngle, 20.0f);
	multiP->setF(PCAMF_AttentionFov, 10.0f);
	multiP->setF(PCAMF_AttentionWatchAdjust, 15.0f);
	multiP->setF(PCAMF_AttentionNaviWatchWeight, 20.0f);
	multiP->setF(PCAMF_AttentionBlur, 110.0f);

	multiP->setF(PCAMF_HomingSpeed, 0.15f);
	multiP->setF(PCAMF_FovHomingSpeed, 0.15f);
	multiP->setF(PCAMF_RotationSpeed, 2.4f);
	multiP->setF(PCAMF_TranslationSpeed, 2.0f);
	multiP->setF(PCAMF_AttentionHomingSpeed, 0.3f);
	multiP->setF(PCAMF_AttentionPeriod, 0.6f);
	multiP->setF(PCAMF_ChangingMotionPeriod, 0.5f);
	multiP->setF(PCAMF_RotationButtonThreshold, 0.1f);
	multiP->setF(PCAMF_CameraReserved0, 0.1f);
	multiP->setF(PCAMF_CameraReserved1, 0.9f);
	multiP->setF(PCAMF_IgnoringPikiDistance, 500.0f);
	multiP->setF(PCAMF_VibrationDistance, 500.0f);
	multiP->setF(PCAMF_AttentionAngleMaxSpeed, NMathF::pi / 8.0f);
}

void PcamCameraParameters::read(RandomAccessStream& input)
{
	mVersion = input.readInt();
	PRINT_NAKATA("PcamCameraParameters::read>%d\n", mVersion);
	ParaMultiParameters* multiP = mParameters;
	if (mVersion <= 6) {
		multiP->mIntParams->read(input);
		for (int i = 0; i < 54; i++) {
			multiP->mFloatParams->mParameters[i] = input.readFloat();
		}
	} else {
		multiP->read(input);
	}

	PRINT_NAKATA("PcamCameraParameters::read<\n");
}

#if 0
void PcamCameraParameters::write(RandomAccessStream& output)
{
	PRINT_NAKATA("PcamCameraParameters::write>\n");
	output.writeInt(7);
	mParameters->write(output);
	PRINT_NAKATA("PcamCameraParameters::write<\n");
}
#endif
