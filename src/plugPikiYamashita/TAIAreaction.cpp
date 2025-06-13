#include "TAI/Areaction.h"
#include "PikiState.h"
#include "SoundMgr.h"
#include "MapCode.h"
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
DEFINE_PRINT("TAIAreaction")

/*
 * --INFO--
 * Address:	801A8490
 * Size:	000050
 */
bool TAIAhitCheckFlyingPiki::actByEvent(TekiEvent& event)
{
	if (event.mEventType == TekiEventType::Entity && event.mOther->mObjType == OBJTYPE_Piki
	    && static_cast<Piki*>(event.mOther)->getState() == PIKISTATE_Flying) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	801A84E0
 * Size:	00001C
 */
bool TAIAdeadCheck::act(Teki& teki)
{
	return teki.mHealth <= 0.0f;
}

/*
 * --INFO--
 * Address:	801A84FC
 * Size:	000030
 */
void TAIAdie::start(Teki& teki)
{
	teki.die();
}

/*
 * --INFO--
 * Address:	801A852C
 * Size:	0000F8
 */
void TAIAdying::start(Teki& teki)
{
	TAIAmotion::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
	teki.mHealth = 0.0f;
	switch (teki.mTekiType) {
	case TEKI_Mar:
		teki.clearTekiOption(BTeki::TEKI_OPTION_LIFE_GAUGE_VISIBLE);
		teki.createDeadEffect();
		break;
	case TEKI_Dororo:
		teki.clearTekiOption(BTeki::TEKI_OPTION_LIFE_GAUGE_VISIBLE);
		teki.clearTekiOption(BTeki::TEKI_OPTION_SHADOW_VISIBLE);
		teki.createDeadEffect();
		break;
	default:
		teki.clearTekiOption(BTeki::TEKI_OPTION_SHADOW_VISIBLE);
		teki.createDeadEffect();
		teki.spawnItems();
		break;
	}

	teki.releasePlatCollisions();
}

/*
 * --INFO--
 * Address:	801A8624
 * Size:	0000AC
 */
bool TAIAdying::act(Teki& teki)
{
	if (teki.animationFinished()) {
		switch (teki.mTekiType) {
		case TEKI_Mar:
			teki.clearTekiOption(BTeki::TEKI_OPTION_SHADOW_VISIBLE);
		case TEKI_Dororo:
			teki.spawnItems();
			break;

		case TEKI_Miurin:
			teki.createDeadEffect();
			break;
		}

		teki.die();
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	801A86D0
 * Size:	000044
 */
void TAIAdyingKabekui::start(Teki& teki)
{
	TAIAdying::start(teki);
	teki.finishFlying();
}

/*
 * --INFO--
 * Address:	801A8714
 * Size:	000144
 */
bool TAIAdyingKabekui::act(Teki& teki)
{
	Vector3f pos(teki.getPosition());
	if (zen::Abs(mapMgr->getMinY(pos.x, pos.z, true) - pos.y) < 1.0f) {
		if (teki.mVelocity.y < -2.0f * teki.getGravity() * gsys->getFrameTime() || teki.mCurrentAnimEvent == KEY_Action0) {
			effectMgr->create(mEffectType, teki.getPosition(), nullptr, nullptr);
		}
	}
	return TAIAdying::act(teki);
}

/*
 * --INFO--
 * Address:	801A8858
 * Size:	000044
 */
void TAIAdyingCrushKabekui::start(Teki& teki)
{
	TAIAdyingKabekui::start(teki);
}

/*
 * --INFO--
 * Address:	801A889C
 * Size:	0000E0
 */
bool TAIAdamage::act(Teki& teki)
{
	if (teki.mStoredDamage <= 0.0f) {
		return false;
	}

	if (judgeDamage(teki)) {
		teki.makeDamaged();
		if (_08) {
			teki.startDamageMotion(teki.getParameterF(TPF_DamageMotionPeriod), teki.getParameterF(TPF_DamageMotionAmplitude));
			switch (teki.mTekiType) {
			case TEKI_Tank:
				teki.playEventSound(&teki, SE_TANK_DAMAGE);
				break;
			}
		}
	}

	return true;
}

/*
 * --INFO--
 * Address:	801A8984
 * Size:	000048
 */
bool TAIAinWater::act(Teki& teki)
{
	bool isInWater = false;
	if (teki.mGroundTriangle && MapCode::getAttribute(teki.mGroundTriangle) == ATTR_Water) {
		isInWater = true;
	}
	return isInWater;
}

/*
 * --INFO--
 * Address:	801A89CC
 * Size:	000068
 */
bool TAIAinWater::actByEvent(TekiEvent& event)
{
	bool isWater = false;
	if (event.mEventType == TekiEventType::Ground) {
		Teki* teki       = event.mTeki;
		CollTriInfo* tri = mapMgr->getCurrTri(teki->getPosition().x, teki->getPosition().z, true);
		if (tri && MapCode::getAttribute(tri) == ATTR_Water) {
			isWater = true;
		}
	}

	return isWater;
}

/*
 * --INFO--
 * Address:	801A8A34
 * Size:	000100
 */
bool TAIAinWaterDamage::act(Teki& teki)
{
	bool res = TAIAinWater::act(teki);
	if (res) {
		teki.mHealth -= gsys->getFrameTime() * mDamage;
	}

	if (_0C) {
		if (teki.mGroundTriangle) {
			int attr = MapCode::getAttribute(teki.mGroundTriangle);
			switch (attr) {
			case ATTR_Water:
				if (teki.getMapCode() != ATTR_Water) {
					createEffect(teki);
				}
				break;
			default:
				if (teki.getMapCode() == ATTR_Water) {
					createEffect(teki);
				}
				break;
			}

			teki.setMapCode(attr);
		} else {
			teki.setMapCode(ATTR_NULL);
		}
	}

	return res;
}

/*
 * --INFO--
 * Address:	801A8B34
 * Size:	0000A8
 */
bool TAIAinWaterDamage::actByEvent(TekiEvent& event)
{
	bool res = TAIAinWater::actByEvent(event);
	if (res) {
		Teki* teki = event.mTeki;
		teki->mHealth -= gsys->getFrameTime() * mDamage;
	}

	return res;
}

/*
 * --INFO--
 * Address:	801A8BDC
 * Size:	000050
 */
void TAIAinWaterDamage::createEffect(Teki& teki)
{
	effectMgr->create(EffectMgr::EFF_P_Bubbles, teki.getPosition(), nullptr, nullptr);
	teki.playEventSound(&teki, SE_OTAMA_WATERJUMP);
}
