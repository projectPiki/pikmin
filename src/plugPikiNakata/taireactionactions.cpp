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

bool TaiDeadAction::act(Teki& teki)
{
	return teki.mHealth <= 0.0f;
}

void TaiLifeZeroAction::start(Teki& teki)
{
	teki.mHealth = 0.0f;
}

void TaiLifeDamageAction::start(Teki& teki)
{
	teki.mHealth -= mDamage;
}

void TaiDyeAction::start(Teki& teki)
{
	teki.die();
}

void TaiStartDyingAction::start(Teki& teki)
{
	teki.spawnItems();
	teki.createDeadEffect();
	teki.releasePlatCollisions();
	teki.clearTekiOption(BTeki::TEKI_OPTION_SHADOW_VISIBLE);
}

void TaiSpawnItemsAction::start(Teki& teki)
{
	teki.spawnItems();
}

void TaiCreateDeadEffectAction::start(Teki& teki)
{
	teki.createDeadEffect();
}

void TaiDyingAction::start(Teki& teki)
{
	TaiMotionAction::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
	teki.mHealth = 0.0f;
}

bool TaiDyingAction::act(Teki& teki)
{
	if (teki.animationFinished()) {
		teki.die();
		return true;
	}

	return false;
}

void TaiDamageCountResetAction::start(Teki& teki)
{
	teki.mDamageCount = 0.0f;
}

bool TaiDamageCountAction::act(Teki& teki)
{
	return (teki.mDamageCount >= mMaxDamageCount);
}

bool TaiDamageScaleAction::act(Teki& teki)
{
	teki.mStoredDamage *= mScale;
	return false;
}

bool TaiDamageAction::act(Teki& teki)
{
	if (teki.mStoredDamage <= 0.0f) {
		return false;
	}
	return true;
}

bool TaiSimultaneousDamageAction::act(Teki& teki)
{
	if (teki.mStoredDamage <= 0.0f) {
		return false;
	}

	teki.makeDamaged();
	teki.startDamageMotion(teki.getParameterF(TPF_DamageMotionPeriod), teki.getParameterF(TPF_DamageMotionAmplitude));
	return true;
}

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

void TaiDamagingAction::start(Teki& teki)
{
	TaiMotionAction::start(teki);
	teki.makeDamaged();
}

bool TaiDamagingAction::act(Teki& teki)
{
	if (teki.animationFinished()) {
		return true;
	}

	return false;
}

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

bool TaiStickedAction::act(Teki& teki)
{
	Stickers stuckList(&teki);
	int count = stuckList.getNumStickers();
	return count > 0;
}

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

void TaiBeingPressedAction::start(Teki& teki)
{
	teki.setTekiOption(BTeki::TEKI_OPTION_PRESSED);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ATARI);
}

bool TaiPressedAction::actByEvent(immut TekiEvent& event)
{
	if (event.mEventType == TekiEventType::Pressed) {
		PRINT_NAKATA("TaiPressedAction::actByEvent:EVENT_PRESSED:%08x\n", event.mTeki);
		return true;
	}

	return false;
}

void TaiWarnAction::start(Teki& teki)
{
	teki.mTimers[4] = teki.getParameterF(TPF_WarnPeriod);
}

bool TaiDangerLifeAction::act(Teki& teki)
{
	return teki.mStoredDamage > 0.0f && teki.mHealth <= mDangerHealth;
}
