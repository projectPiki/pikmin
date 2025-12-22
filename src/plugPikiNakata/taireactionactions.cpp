#include "DebugLog.h"
#include "PikiState.h"
#include "Stickers.h"
#include "TAI/ReactionActions.h"
#include "TekiConditions.h"
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
DEFINE_PRINT("taireactionactions")

/**
 * @TODO: Documentation
 */
bool TaiDeadAction::act(Teki& teki)
{
	return teki.mHealth <= 0.0f;
}

/**
 * @TODO: Documentation
 */
void TaiLifeZeroAction::start(Teki& teki)
{
	teki.mHealth = 0.0f;
}

/**
 * @TODO: Documentation
 */
void TaiLifeDamageAction::start(Teki& teki)
{
	teki.mHealth -= mDamage;
}

/**
 * @TODO: Documentation
 */
void TaiDyeAction::start(Teki& teki)
{
	teki.die();
}

/**
 * @TODO: Documentation
 */
void TaiStartDyingAction::start(Teki& teki)
{
	teki.spawnItems();
	teki.createDeadEffect();
	teki.releasePlatCollisions();
	teki.clearTekiOption(BTeki::TEKI_OPTION_SHADOW_VISIBLE);
}

/**
 * @TODO: Documentation
 */
void TaiSpawnItemsAction::start(Teki& teki)
{
	teki.spawnItems();
}

/**
 * @TODO: Documentation
 */
void TaiCreateDeadEffectAction::start(Teki& teki)
{
	teki.createDeadEffect();
}

/**
 * @TODO: Documentation
 */
void TaiDyingAction::start(Teki& teki)
{
	TaiMotionAction::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
	teki.mHealth = 0.0f;
}

/**
 * @TODO: Documentation
 */
bool TaiDyingAction::act(Teki& teki)
{
	if (teki.animationFinished()) {
		teki.die();
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
void TaiDamageCountResetAction::start(Teki& teki)
{
	teki.mDamageCount = 0.0f;
}

/**
 * @TODO: Documentation
 */
bool TaiDamageCountAction::act(Teki& teki)
{
	return (teki.mDamageCount >= mMaxDamageCount);
}

/**
 * @TODO: Documentation
 */
bool TaiDamageScaleAction::act(Teki& teki)
{
	teki.mStoredDamage *= mScale;
	return false;
}

/**
 * @TODO: Documentation
 */
bool TaiDamageAction::act(Teki& teki)
{
	if (teki.mStoredDamage <= 0.0f) {
		return false;
	}
	return true;
}

/**
 * @TODO: Documentation
 */
bool TaiSimultaneousDamageAction::act(Teki& teki)
{
	if (teki.mStoredDamage <= 0.0f) {
		return false;
	}

	teki.makeDamaged();
	teki.startDamageMotion(teki.getParameterF(TPF_DamageMotionPeriod), teki.getParameterF(TPF_DamageMotionAmplitude));
	return true;
}

/**
 * @TODO: Documentation
 */
bool TaiCounterattackSimultaneousDamageAction::act(Teki& teki)
{
	if (teki.mStoredDamage <= 0.0f) {
		return false;
	}

	Creature* maybeTarget = teki.getCreaturePointer(1);
	if (teki.nearestAngleTarget(maybeTarget)) {
		teki.setCreaturePointer(0, maybeTarget);
	}

	teki.makeDamaged();
	teki.startDamageMotion(teki.getParameterF(TPF_DamageMotionPeriod), teki.getParameterF(TPF_DamageMotionAmplitude));
	return true;
}

/**
 * @TODO: Documentation
 */
void TaiDamagingAction::start(Teki& teki)
{
	TaiMotionAction::start(teki);
	teki.makeDamaged();
}

/**
 * @TODO: Documentation
 */
bool TaiDamagingAction::act(Teki& teki)
{
	if (teki.animationFinished()) {
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
bool TaiTargetNearestAssailantAction::act(Teki& teki)
{
	if (teki.mStoredDamage <= 0.0f) {
		return false;
	}

	Creature* maybeTarget = teki.getCreaturePointer(1);
	if (teki.nearestAngleTarget(maybeTarget)) {
		teki.setCreaturePointer(0, maybeTarget);
	}
	return true;
}

/**
 * @TODO: Documentation
 */
bool TaiTargetNearestCollisionAction::actByEvent(immut TekiEvent& event)
{
	Teki* teki = event.mTeki;
	if (event.mEventType != TekiEventType::Entity) {
		return false;
	}
	Creature* target = event.mOther;
	TekiAndCondition cond(&TekiRecognitionCondition(event.mTeki), &TekiNaviPikiCondition());
	if (!cond.satisfy(target)) {
		return false;
	}
	if (teki->nearestAngleTarget(target)) {
		teki->setCreaturePointer(0, target);
	}
	return true;

	TekiRecognitionCondition(nullptr);
	TekiRecognitionCondition(nullptr);
}

/**
 * @TODO: Documentation
 */
bool TaiStickedAction::act(Teki& teki)
{
	Stickers stuckList(&teki);
	int count = stuckList.getNumStickers();
	return count > 0;
}

/**
 * @TODO: Documentation
 */
bool TaiSmashedAction::actByEvent(immut TekiEvent& event)
{
	if (event.mEventType == TekiEventType::Entity) {
		Teki* teki      = event.mTeki;
		Creature* other = event.mOther;
		if (other->mObjType == OBJTYPE_Piki && static_cast<Piki*>(other)->getState() == PIKISTATE_Flying) {
			PRINT_NAKATA("TaiSmashedAction::actByEvent:FLYING:%08x\n", &teki);
			return true;
		}
	}
	return false;
}

/**
 * @TODO: Documentation
 */
void TaiBeingPressedAction::start(Teki& teki)
{
	teki.setTekiOption(BTeki::TEKI_OPTION_PRESSED);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ATARI);
}

/**
 * @TODO: Documentation
 */
bool TaiPressedAction::actByEvent(immut TekiEvent& event)
{
	if (event.mEventType == TekiEventType::Pressed) {
		PRINT_NAKATA("TaiPressedAction::actByEvent:EVENT_PRESSED:%08x\n", event.mTeki);
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
void TaiWarnAction::start(Teki& teki)
{
	teki.mTimers[4] = teki.getParameterF(TPF_WarnPeriod);
}

/**
 * @TODO: Documentation
 */
bool TaiDangerLifeAction::act(Teki& teki)
{
	return teki.mStoredDamage > 0.0f && teki.mHealth <= mDangerHealth;
}
