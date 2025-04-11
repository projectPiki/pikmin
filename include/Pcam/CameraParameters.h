#ifndef _PCAM_CAMERAPARAMETERS_H
#define _PCAM_CAMERAPARAMETERS_H

#include "types.h"
#include "Node.h"
#include "ParaParameters.h"

/**
 * @brief TODO
 */
enum PcamCameraIntParams {
	PCAMI_CameraSwitch = 0,
	PCAMI_COUNT, // 1
};

/**
 * @brief TODO
 */
enum PcamCameraFloatParams {
	//// LOW
	// NEAR
	PCAMF_NearLowDistance        = 0,
	PCAMF_NearLowAngle           = 1,
	PCAMF_NearLowFov             = 2,
	PCAMF_NearLowWatchAdjust     = 3,
	PCAMF_NearLowNaviWatchWeight = 4,
	PCAMF_NearLowBlur            = 5,
	// MIDDLE
	PCAMF_MiddleLowDistance        = 6,
	PCAMF_MiddleLowAngle           = 7,
	PCAMF_MiddleLowFov             = 8,
	PCAMF_MiddleLowWatchAdjust     = 9,
	PCAMF_MiddleLowNaviWatchWeight = 10,
	PCAMF_MiddleLowBlur            = 11,
	// FAR
	PCAMF_FarLowDistance        = 12,
	PCAMF_FarLowAngle           = 13,
	PCAMF_FarLowFov             = 14,
	PCAMF_FarLowWatchAdjust     = 15,
	PCAMF_FarLowNaviWatchWeight = 16,
	PCAMF_FarLowBlur            = 17,

	//// HIGH
	// NEAR
	PCAMF_NearHighDistance        = 18,
	PCAMF_NearHighAngle           = 19,
	PCAMF_NearHighFov             = 20,
	PCAMF_NearHighWatchAdjust     = 21,
	PCAMF_NearHighNaviWatchWeight = 22,
	PCAMF_NearHighBlur            = 23,
	// MIDDLE
	PCAMF_MiddleHighDistance        = 24,
	PCAMF_MiddleHighAngle           = 25,
	PCAMF_MiddleHighFov             = 26,
	PCAMF_MiddleHighWatchAdjust     = 27,
	PCAMF_MiddleHighNaviWatchWeight = 28,
	PCAMF_MiddleHighBlur            = 29,
	// FAR
	PCAMF_FarHighDistance        = 30,
	PCAMF_FarHighAngle           = 31,
	PCAMF_FarHighFov             = 32,
	PCAMF_FarHighWatchAdjust     = 33,
	PCAMF_FarHighNaviWatchWeight = 34,
	PCAMF_FarHighBlur            = 35,

	// ATTENTION
	PCAMF_AttentionDistance        = 36,
	PCAMF_AttentionAngle           = 37,
	PCAMF_AttentionFov             = 38,
	PCAMF_AttentionWatchAdjust     = 39,
	PCAMF_AttentionNaviWatchWeight = 40,
	PCAMF_AttentionBlur            = 41,

	// OTHER PARAMS
	PCAMF_HomingSpeed             = 42,
	PCAMF_FovHomingSpeed          = 43,
	PCAMF_RotationSpeed           = 44,
	PCAMF_TranslationSpeed        = 45,
	PCAMF_AttentionHomingSpeed    = 46,
	PCAMF_AttentionPeriod         = 47,
	PCAMF_ChangingMotionPeriod    = 48,
	PCAMF_RotationButtonThreshold = 49,
	PCAMF_CameraReserved0         = 50,
	PCAMF_CameraReserved1         = 51,
	PCAMF_IgnoringPikiDistance    = 52,
	PCAMF_VibrationDistance       = 53,
	PCAMF_AttentionAngleMaxSpeed  = 54,

	PCAMF_COUNT, // 55
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct PcamCameraParameters : public Node {
	PcamCameraParameters();

	virtual void read(RandomAccessStream&); // _0C

	// DLL inlines:
	f32 getF(int idx) { return mParameters->getF(idx); }

	// _00     = VTBL
	// _00-_20 = Node
	int mVersion;                     // _20
	ParaMultiParameters* mParameters; // _24
};

#endif
