#ifndef _PCAM_CAMERA_H
#define _PCAM_CAMERA_H

#include "types.h"
#include "nlib/Graphics.h"
#include "nlib/Array.h"
#include "Camera.h"
#include "Pcam/CameraParameters.h"

struct Controller;
struct Creature;
struct Font;
struct Graphics;
struct Navi;
struct NVector3f;
struct PcamCameraParameters;

/**
 * @brief TODO
 */
enum PcamZoomLevels {
	PCAMZOOM_Near   = 0,
	PCAMZOOM_Middle = 1,
	PCAMZOOM_Far    = 2,
	PCAMZOOM_COUNT, // 3
};

/**
 * @brief TODO
 */
enum PcamAngleLevels {
	PCAMANGLE_Low  = 0,
	PCAMANGLE_High = 1,
	PCAMANGLE_COUNT, // 2
};

/**
 * @brief Camera attention states
 */
DEFINE_ENUM_TYPE(AttentionState,
                 Inactive = 0, // Camera is not in attention mode
                 Active   = 1, // Camera is actively tracking attention target
);

/**
 * @brief Radius calculation modes for camera
 */
DEFINE_ENUM_TYPE(RadiusMode,
                 Dynamic = 0, // Use calculated goal distance
                 Stored  = 1, // Use stored previous radius value
);

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct PcamMotionInfo {
	PcamMotionInfo();

	// unused/inlined:
	void init(f32 dist, f32 angle, f32 fov, f32 watchAdjust, f32 naviWatchWeight, f32 blur);
	void println();

	f32 mDistance;        // _00
	f32 mAngle;           // _04
	f32 mFov;             // _08
	f32 mWatchAdjustment; // _0C
	f32 mNaviWatchWeight; // _10
	f32 mBlur;            // _14
};

/**
 * @brief TODO
 */
struct PcamControlInfo {
	PcamControlInfo();

	void init(bool, bool, bool, bool, bool, bool, bool, f32, f32, f32);

	bool mIsActive;           // _00
	bool mDoRotate;           // _01, slow tracking left/right when partially holding L
	bool mDoAttentionCamera;  // _02, front-facing snap when clicking L
	bool mDoToggleZoom;       // _03, toggle zoom level with R
	bool mDoAdjustAngle;      // _04, toggle inclination/angle with Z
	bool mDoAdjustAngleDown;  // _05
	bool _UNUSED06;           // _06
	f32 mAzimuthRotIntensity; // _08
	f32 mSubStickInput;       // _0C
	f32 mSubStickY;           // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x170.
 */
struct PcamCamera : public NCamera {
	PcamCamera(Camera*);

	void startCamera(Creature*);
	void startCamera(Creature*, int, int);
	void makeCurrentPosition(f32);
	void parameterUpdated();
	void control(Controller&);
	void control(PcamControlInfo&);
	void startAttention();
	void makePosture();
	void makePolarRadius();
	void makeWatchObjectViewpoint(NVector3f&, NVector3f&);
	void updateTimers();
	void startMotion(int, int);
	void startMotion(PcamMotionInfo&);
	void finishMotion();
	f32 getGoalDistance();
	f32 getCurrentAngle();
	f32 getCurrentFov();
	f32 getCurrentHomingSpeed();
	f32 getCurrentBlur();
	f32 calcCurrentDistance();
	f32 getCursorDirection();
	void outputTargetPosition(NVector3f&);
	void outputCursorPosition(NVector3f&);
	void outputFormationWatchpoint(Navi*, NVector3f&);
	void outputTargetWatchpoint(NVector3f&);

	// unused/inlined:
	void playCameraSound(int);
	f32 getChangingMotionRate();
	f32 getCurrentWatchAdjustment();
	f32 getCurrentNaviWatchWeight();
	f32 calcCurrentDirection();
	f32 calcTargetDistance();
	f32 getTargetDirection();
	void makePolar();
	void printInfo(Graphics&, Font*);

	void setTarget(Creature* target) { mTargetCreature = target; }
	PcamMotionInfo& getBasicMotionInfo(int zoom, int incl) { return mBasicMotionInfos[incl][zoom]; }
	f32 getParameterF(int idx) { return mParameters->getF(idx); }

	bool timerElapsed(int idx) { return mTimers[idx] <= 0.0f; }
	NPolar3f& getPolar() { return mPolarDir; }
	void setBlur(f32 blur) { mCamera->mBlur = blur; }

	// DLL inlines to do:
	f32 getDirection();

	static f32 angleToMeridian(f32 angle) { return NMathF::d2r(90.0f - angle); }
	static f32 calcDirection(Vector3f& vec) { return NMathF::atan2(vec.x, vec.z); }

	// _50     = VTBL
	// _00-_20 = NCamera
	u8 mIsActive;                  // _20
	u8 _21[0x28 - 0x21];           // _21, unknown
	u8 mAttentionEnabled;          // _28
	u8 _29[0x30 - 0x29];           // _29, unknown
	u8 mControlsEnabled;           // _30
	u8 _31[0x38 - 0x31];           // _31, unknown
	PcamMotionInfo mAttentionInfo; // _38

	// why is this in the middle. this is all one struct according to the DLL, just bizarre.
	virtual void update(); // _08

	PcamMotionInfo mPrevMotionInfo;         // _54
	PcamMotionInfo mTargetMotionInfo;       // _6C
	NArray<Creature>* mCreatureArray;       // _84
	int mZoomLevel;                         // _88
	BOOL mToggleZoomPending;                // _8C
	int mInclinationLevel;                  // _90
	int mAdjustInclinationPending;          // _94, not a BOOL bc it can be 2, but never actually used beyond 0/1
	u32 _UNUSED98;                          // _98
	int mAttentionState;                    // _9C, see AttentionState enum
	int mRadiusMode;                        // _A0, see RadiusMode enum
	f32 mDistanceMultiplier;                // _A4
	f32 mStoredRadius;                      // _A8
	f32 mCurrDistance;                      // _AC
	f32 mCurrentAzimuth;                    // _B0
	f32 mDefaultDistance;                   // _B4
	f32 mMinAngleThreshold;                 // _B8
	f32 mMaxAngleThreshold;                 // _BC
	NPolar3f mPolarDir;                     // _C0
	Creature* mTargetCreature;              // _CC
	PcamCameraParameters* mParameters;      // _D0
	f32 mTimers[3];                         // _D4
	PcamMotionInfo mBasicMotionInfos[2][3]; // _E0, 2 inclination angles, 3 zoom levels
};

#endif
