#include "DebugLog.h"
#include "MapCode.h"
#include "PikiState.h"
#include "SoundMgr.h"
#include "TAI/Areaction.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("TAIAreaction")

/**
 * @TODO: Documentation
 */
bool TAIAhitCheckFlyingPiki::actByEvent(immut TekiEvent& event)
{
	if (event.mEventType == TekiEventType::Entity && event.mOther->mObjType == OBJTYPE_Piki
	    && static_cast<Piki*>(event.mOther)->getState() == PIKISTATE_Flying) {
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
bool TAIAdeadCheck::act(Teki& teki)
{
	return teki.mHealth <= 0.0f;
}

/**
 * @TODO: Documentation
 */
void TAIAdie::start(Teki& teki)
{
	teki.die();
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void TAIAdyingKabekui::start(Teki& teki)
{
	TAIAdying::start(teki);
	teki.finishFlying();
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void TAIAdyingCrushKabekui::start(Teki& teki)
{
	TAIAdyingKabekui::start(teki);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
bool TAIAinWater::act(Teki& teki)
{
	bool isInWater = false;
	if (teki.mGroundTriangle && MapCode::getAttribute(teki.mGroundTriangle) == ATTR_Water) {
		isInWater = true;
	}
	return isInWater;
}

/**
 * @TODO: Documentation
 */
bool TAIAinWater::actByEvent(immut TekiEvent& event)
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
bool TAIAinWaterDamage::actByEvent(immut TekiEvent& event)
{
	bool res = TAIAinWater::actByEvent(event);
	if (res) {
		Teki* teki = event.mTeki;
		teki->mHealth -= gsys->getFrameTime() * mDamage;
	}

	return res;
}

/**
 * @TODO: Documentation
 */
void TAIAinWaterDamage::createEffect(Teki& teki)
{
	effectMgr->create(EffectMgr::EFF_P_Bubbles, teki.getPosition(), nullptr, nullptr);
	teki.playEventSound(&teki, SE_OTAMA_WATERJUMP);
}
