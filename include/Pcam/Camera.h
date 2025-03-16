#ifndef _PCAM_CAMERA_H
#define _PCAM_CAMERA_H

#include "types.h"
#include "nlib/Graphics.h"
#include "nlib/Array.h"

struct Controller;
struct Creature;
struct Font;
struct Graphics;
struct Navi;
struct NVector3f;
struct PcamCameraParameters;

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct PcamMotionInfo {
	PcamMotionInfo();

	// unused/inlined:
	void init(f32, f32, f32, f32, f32, f32);
	void println();

	u8 _00[0x18]; // _18, unknown
};

/**
 * @brief TODO
 */
struct PcamControlInfo {
	PcamControlInfo();

	void init(bool, bool, bool, bool, bool, bool, bool, f32, f32, f32);

	// TODO: members
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

	// _50     = VTBL
	// _00-_20 = NCamera
	u8 _20;                     // _20
	u8 _21[0x30 - 0x21];        // _20, unknown
	u8 _30;                     // _30
	u8 _31[0x38 - 0x31];        // _31, unknown
	PcamMotionInfo mMotionInfo; // _38

	// why is this in the middle. this is all one struct according to the DLL, just bizarre.
	virtual void update(); // _08

	PcamMotionInfo _54;                // _54
	PcamMotionInfo _6C;                // _6C
	u8 _84[0xC8 - 0x84];               // _54
	NPolar3f _C0;                      // _C0
	u8 _CC[0x4];                       // _CC, unknown
	PcamCameraParameters* mParameters; // _D0
	u8 _D4[0xE0 - 0xD4];               // _D4, unknown
	PcamMotionInfo _E0[6];
};

#endif
