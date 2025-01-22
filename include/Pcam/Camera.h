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

/**
 * @brief TODO
 */
struct PcamMotionInfo {
	PcamMotionInfo();

	// unused/inlined:
	void init(f32, f32, f32, f32, f32, f32);
	void println();

	// TODO: members
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

	virtual void update(); // _08

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

	// _20     = VTBL
	// _00-_20 = NCamera
	u8 _24[0x30 - 0x24];  // _24, unknown
	u8 _30;               // _30
	u8 _31[0x16C - 0x31]; // _31, unknown
};

#endif
