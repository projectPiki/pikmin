#include "DebugLog.h"
#include "Dolphin/os.h"
#include "TAI/WaitActions.h"
#include "nlib/Math.h"
#include "system.h"
#include "teki.h"

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
DEFINE_PRINT("taiwaitactions")

/*
 * --INFO--
 * Address:	80143A9C
 * Size:	000070
 */
void TaiWaitTurningAction::start(Teki& teki)
{
	TaiMotionAction::start(teki);
	teki.mTargetAngle = 2.0f * NSystem::random() * NMathF::pi;
}

/*
 * --INFO--
 * Address:	80143B0C
 * Size:	0000E4
 */
bool TaiWaitTurningAction::act(Teki& teki)
{
	f32 faceDir        = teki.getDirection();
	f32 roundedFaceDir = NMathF::roundAngle(faceDir);
	if (NMath<f32>::absolute(NMathF::calcNearerDirection(roundedFaceDir, teki.mTargetAngle) - roundedFaceDir) <= 0.1f * NMathF::pi) {
		return true;
	}

	teki.turnToward(teki.mTargetAngle, teki.getParameterF(TPF_TurnVelocity));
	return false;
}
