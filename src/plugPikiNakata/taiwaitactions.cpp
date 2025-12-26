#include "DebugLog.h"
#include "Dolphin/os.h"
#include "TAI/WaitActions.h"
#include "nlib/Math.h"
#include "system.h"
#include "teki.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("taiwaitactions")

/**
 * @todo: Documentation
 */
void TaiWaitTurningAction::start(Teki& teki)
{
	TaiMotionAction::start(teki);
	teki.mTargetAngle = 2.0f * NSystem::random() * NMathF::pi;
}

/**
 * @todo: Documentation
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
