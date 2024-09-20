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
	void getGoalDistance();
	void getCurrentAngle();
	void getCurrentFov();
	void getCurrentHomingSpeed();
	void getCurrentBlur();
	void calcCurrentDistance();
	void getCursorDirection();
	void outputTargetPosition(NVector3f&);
	void outputCursorPosition(NVector3f&);
	void outputFormationWatchpoint(Navi*, NVector3f&);
	void outputTargetWatchpoint(NVector3f&);

	// unused/inlined:
	void playCameraSound(int);
	void getChangingMotionRate();
	void getCurrentWatchAdjustment();
	void getCurrentNaviWatchWeight();
	void calcCurrentDirection();
	void calcTargetDistance();
	void getTargetDirection();
	void makePolar();
	void printInfo(Graphics&, Font*);

	// TODO: members
	u8 _04[0x16C - sizeof(NCamera)]; // _00, unknown
};

#endif
