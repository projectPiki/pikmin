#ifndef _PCAM_CAMERAMANAGER_H
#define _PCAM_CAMERAMANAGER_H

#include "Node.h"
#include "types.h"

struct Camera;
struct Controller;
struct Creature;
struct PcamCamera;
struct PcamMotionInfo;
struct PeveEvent;
struct Vector3f;

/**
 * @brief TODO
 */
enum PcamVibrationEventIDs {
	PCAMVIB_NULL          = -1,
	PCAMVIB_SideVibration = 0,
	PCAMVIB_Damage        = 1,
	PCAMVIB_Vibration1    = 2,
	PCAMVIB_Vibration2    = 3,
	PCAMVIB_LongVibration = 4,
	PCAMVIB_VibrationCount, // 5
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct PcamCameraManager : public Node {
	PcamCameraManager(Camera*, Controller*);

	virtual void update(); // _10

	void startCamera(Creature*);
	void updateVibrationEvent();
	void startVibrationEvent(int, Vector3f&);
	void outputNaviPosition(Vector3f&);

	// unused/inlined:
	void startMotion(PcamMotionInfo&);
	void finishMotion();

	// _00     = VTBL
	// _00-_20 = Node
	PcamCamera* mCamera;          // _20
	Controller* mController;      // _24
	int mCurrEventIndex;          // _28, see PcamVibrationEventIDs enum
	PeveEvent** mVibrationEvents; // _2C, array of events indexed by mCurrEventIndex
};

extern PcamCameraManager* cameraMgr;

#endif
