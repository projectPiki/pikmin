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
DEFINE_ERROR()

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
TaiJointEffectAction::TaiJointEffectAction(f32 p1, int p2, int p3, int p4, int p5, int p6)
    : TAIAeffCloudOfDust(TAI_NO_TRANSIT, EffectMgr::EFF_NULL, p1, p2, p3, p4, p5, p6)
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
