#include "TAI/EffectActions.h"
#include "teki.h"
#include "Dolphin/os.h"
#include "EffectMgr.h"
#include "DebugLog.h"

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
DEFINE_PRINT("taieffectactions")

/*
 * --INFO--
 * Address:	8012E5A8
 * Size:	000038
 */
void TaiEffectAction::start(Teki& teki)
{
	effectMgr->create(static_cast<EffectMgr::effTypeTable>(mEffectType), teki.getPosition(), nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	8012E5E0
 * Size:	00002C
 */
void TaiStartGenParticleGeneratorAction::start(Teki& teki)
{
	teki.startParticleGenerator(_08);
}

/*
 * --INFO--
 * Address:	8012E60C
 * Size:	00002C
 */
void TaiStopGenParticleGeneratorAction::start(Teki& teki)
{
	teki.stopParticleGenerator(_08);
}

/*
 * --INFO--
 * Address:	8012E638
 * Size:	00008C
 */
TaiJointEffectAction::TaiJointEffectAction(f32 sinkThreshold, int footNum, int jointID0, int jointID1, int jointID2, int jointID3)
    : TAIAeffCloudOfDust(TAI_NO_TRANSIT, EffectMgr::EFF_NULL, sinkThreshold, footNum, jointID0, jointID1, jointID2, jointID3)
{
	_20 = false;
}

/*
 * --INFO--
 * Address:	8012E6C4
 * Size:	000004
 */
void TaiJointEffectAction::setType(Vector3f&, int, int)
{
}
