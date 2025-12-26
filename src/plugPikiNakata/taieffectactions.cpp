#include "DebugLog.h"
#include "Dolphin/os.h"
#include "EffectMgr.h"
#include "TAI/EffectActions.h"
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
DEFINE_PRINT("taieffectactions")

/**
 * @todo: Documentation
 */
void TaiEffectAction::start(Teki& teki)
{
	effectMgr->create(static_cast<EffectMgr::effTypeTable>(mEffectType), teki.getPosition(), nullptr, nullptr);
}

/**
 * @todo: Documentation
 */
void TaiStartGenParticleGeneratorAction::start(Teki& teki)
{
	teki.startParticleGenerator(_08);
}

/**
 * @todo: Documentation
 */
void TaiStopGenParticleGeneratorAction::start(Teki& teki)
{
	teki.stopParticleGenerator(mGenIndex);
}

/**
 * @todo: Documentation
 */
TaiJointEffectAction::TaiJointEffectAction(f32 sinkThreshold, int footNum, int jointID0, int jointID1, int jointID2, int jointID3)
    : TAIAeffCloudOfDust(TAI_NO_TRANSIT, EffectMgr::EFF_NULL, sinkThreshold, footNum, jointID0, jointID1, jointID2, jointID3)
{
	_20 = false;
}

/**
 * @todo: Documentation
 */
void TaiJointEffectAction::setType(Vector3f&, int, int)
{
}
