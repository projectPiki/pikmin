#include "Pcam/CameraManager.h"
#include "Pcam/Camera.h"
#include "Pcam/MotionEvents.h"
#include "Peve/Event.h"
#include "Peve/Condition.h"
#include "NaviMgr.h"
#include "sysNew.h"
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
DEFINE_PRINT("pcamcameramanager")

/*
 * --INFO--
 * Address:	80123C54
 * Size:	0001F8
 */
PcamCameraManager::PcamCameraManager(Camera* camera, Controller* controller)
    : Node("PcamCameraManager")
{
	mCamera          = new PcamCamera(camera);
	mController      = controller;
	mVibrationEvents = new PeveEvent*[PCAMVIB_VibrationCount];

	PcamVibrationEvent* vib1             = new PcamVibrationEvent(mCamera);
	vib1->_48                            = 0.6f;
	vib1->_4C                            = 0.2f;
	vib1->_50                            = 8.0f;
	mVibrationEvents[PCAMVIB_Vibration1] = vib1;

	PcamVibrationEvent* vib2             = new PcamVibrationEvent(mCamera);
	vib2->_48                            = 0.6f;
	vib2->_4C                            = 0.2f;
	vib2->_50                            = 4.0f;
	mVibrationEvents[PCAMVIB_Vibration2] = vib2;

	mVibrationEvents[PCAMVIB_LongVibration] = new PcamLongVibrationEvent(mCamera);

	PcamDamageEvent* damage = new PcamDamageEvent(mCamera);
	// nice typo.
	vib2->_48 = 0.6f;
	vib2->_4C = 0.2f;

	damage->_50                      = 30.0f;
	mVibrationEvents[PCAMVIB_Damage] = damage;

	PcamSideVibrationEvent* sideVib = new PcamSideVibrationEvent(mCamera);
	// nice typo.
	vib2->_48 = 0.6f;
	vib2->_4C = 0.2f;

	sideVib->_18                            = NMathF::pi / 48.0f;
	mVibrationEvents[PCAMVIB_SideVibration] = sideVib;
	mCurrEventIndex                         = -1;
}

/*
 * --INFO--
 * Address:	80123E4C
 * Size:	000024
 */
void PcamCameraManager::startCamera(Creature* target)
{
	mCamera->startCamera(target);
}

/*
 * --INFO--
 * Address:	80123E70
 * Size:	000050
 */
void PcamCameraManager::update()
{
	mCamera->control(*mController);
	mCamera->update();
	updateVibrationEvent();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void PcamCameraManager::startMotion(PcamMotionInfo& info)
{
	mCamera->startMotion(info);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void PcamCameraManager::finishMotion()
{
	mCamera->finishMotion();
}

/*
 * --INFO--
 * Address:	80123EC0
 * Size:	000098
 */
void PcamCameraManager::updateVibrationEvent()
{
	if (mCurrEventIndex < 0) {
		return;
	}

	PeveEvent* event = mVibrationEvents[mCurrEventIndex];
	if (event->isFinished()) {
		event->finish();
		mCurrEventIndex = PCAMVIB_NULL;
		return;
	}

	event->update();
}

/*
 * --INFO--
 * Address:	80123FD8
 * Size:	000148
 */
void PcamCameraManager::startVibrationEvent(int eventIdx, Vector3f& p2)
{
	PRINT("startVibrationEvent:%d,%d\n", mCurrEventIndex, eventIdx);
	if (mCurrEventIndex < 0 || mCurrEventIndex >= eventIdx) {
		NVector3f vec1;
		outputNaviPosition(vec1);
		f32 dist = vec1.distanceXZ(p2);
		if (dist > mCamera->getParameterF(53)) {
			PRINT("startVibrationEvent:distance>:%f\n", dist);
		} else {
			mCurrEventIndex  = eventIdx;
			PeveEvent* event = mVibrationEvents[mCurrEventIndex];
			if (mCurrEventIndex == PCAMVIB_Vibration1) {
				static_cast<PcamVibrationEvent*>(event)->makePcamVibrationEvent();
			} else if (mCurrEventIndex == PCAMVIB_Vibration2) {
				static_cast<PcamVibrationEvent*>(event)->makePcamVibrationEvent();
			} else if (mCurrEventIndex == PCAMVIB_LongVibration) {
				static_cast<PcamLongVibrationEvent*>(event)->makePcamLongVibrationEvent(0.4f, 0.6f, 0.2f, 3.0f);
			} else if (mCurrEventIndex == PCAMVIB_Damage) {
				static_cast<PcamDamageEvent*>(event)->makePcamDamageEvent();
			} else if (mCurrEventIndex == PCAMVIB_SideVibration) {
				static_cast<PcamSideVibrationEvent*>(event)->makePcamSideVibrationEvent();
			}
			event->reset();
		}
	}
}

/*
 * --INFO--
 * Address:	8012415C
 * Size:	00004C
 */
void PcamCameraManager::outputNaviPosition(Vector3f& naviPos)
{
	Navi* navi = naviMgr->getNavi(0);
	naviPos.input(navi->getPosition());
}
