#include "TAI/ReactionActions.h"
#include "teki.h"
#include "TekiConditions.h"
#include "PikiState.h"
#include "Stickers.h"
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
DEFINE_PRINT("taireactionactions")

/*
 * --INFO--
 * Address:	8013EBD8
 * Size:	00001C
 */
bool TaiDeadAction::act(Teki& teki)
{
	return teki.mHealth <= 0.0f;
}

/*
 * --INFO--
 * Address:	8013EBF4
 * Size:	00000C
 */
void TaiLifeZeroAction::start(Teki& teki)
{
	teki.mHealth = 0.0f;
}

/*
 * --INFO--
 * Address:	8013EC00
 * Size:	000014
 */
void TaiLifeDamageAction::start(Teki& teki)
{
	teki.mHealth -= mDamage;
}

/*
 * --INFO--
 * Address:	8013EC14
 * Size:	000030
 */
void TaiDyeAction::start(Teki& teki)
{
	teki.die();
}

/*
 * --INFO--
 * Address:	8013EC44
 * Size:	000058
 */
void TaiStartDyingAction::start(Teki& teki)
{
	teki.spawnItems();
	teki.createDeadEffect();
	teki.releasePlatCollisions();
	teki.clearTekiOption(BTeki::TEKI_OPTION_SHADOW_VISIBLE);
}

/*
 * --INFO--
 * Address:	8013EC9C
 * Size:	000024
 */
void TaiSpawnItemsAction::start(Teki& teki)
{
	teki.spawnItems();
}

/*
 * --INFO--
 * Address:	8013ECC0
 * Size:	000024
 */
void TaiCreateDeadEffectAction::start(Teki& teki)
{
	teki.createDeadEffect();
}

/*
 * --INFO--
 * Address:	8013ECE4
 * Size:	00004C
 */
void TaiDyingAction::start(Teki& teki)
{
	TaiMotionAction::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
	teki.mHealth = 0.0f;
}

/*
 * --INFO--
 * Address:	8013ED30
 * Size:	00004C
 */
bool TaiDyingAction::act(Teki& teki)
{
	if (teki.animationFinished()) {
		teki.die();
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8013ED7C
 * Size:	00000C
 */
void TaiDamageCountResetAction::start(Teki& teki)
{
	teki.mDamageCount = 0.0f;
}

/*
 * --INFO--
 * Address:	8013ED88
 * Size:	000040
 */
bool TaiDamageCountAction::act(Teki& teki)
{
	return (teki.mDamageCount >= mMaxDamageCount);
}

/*
 * --INFO--
 * Address:	8013EDC8
 * Size:	000018
 */
bool TaiDamageScaleAction::act(Teki& teki)
{
	teki.mStoredDamage *= mScale;
	return false;
}

/*
 * --INFO--
 * Address:	8013EDE0
 * Size:	000024
 */
bool TaiDamageAction::act(Teki& teki)
{
	if (teki.mStoredDamage <= 0.0f) {
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	8013EE04
 * Size:	000088
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

/*
 * --INFO--
 * Address:	8013EE8C
 * Size:	0000D8
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

/*
 * --INFO--
 * Address:	8013EF64
 * Size:	000040
 */
void TaiDamagingAction::start(Teki& teki)
{
	TaiMotionAction::start(teki);
	teki.makeDamaged();
}

/*
 * --INFO--
 * Address:	8013EFA4
 * Size:	000020
 */
bool TaiDamagingAction::act(Teki& teki)
{
	if (teki.animationFinished()) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8013EFC4
 * Size:	000098
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

/*
 * --INFO--
 * Address:	8013F05C
 * Size:	00013C
 */
bool TaiTargetNearestCollisionAction::actByEvent(TekiEvent& event)
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

/*
 * --INFO--
 * Address:	8013F198
 * Size:	000040
 */
bool TaiStickedAction::act(Teki& teki)
{
	Stickers stuckList(&teki);
	int count = stuckList.getCount();
	return count > 0;
}

/*
 * --INFO--
 * Address:	8013F1D8
 * Size:	000050
 */
bool TaiSmashedAction::actByEvent(TekiEvent& event)
{
	if (event.mEventType == TekiEventType::Entity) {
		Teki* teki      = event.mTeki;
		Creature* other = event.mOther;
		if (other->mObjType == OBJTYPE_Piki && static_cast<Piki*>(other)->getState() == PIKISTATE_Flying) {
			PRINT("TaiSmashedAction::actByEvent:FLYING:%08x\n", teki);
			return true;
		}
	}
	return false;
}

/*
 * --INFO--
 * Address:	8013F228
 * Size:	000070
 */
void TaiBeingPressedAction::start(Teki& teki)
{
	teki.setTekiOption(BTeki::TEKI_OPTION_PRESSED);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ATARI);
}

/*
 * --INFO--
 * Address:	8013F298
 * Size:	00001C
 */
bool TaiPressedAction::actByEvent(TekiEvent& event)
{
	if (event.mEventType == TekiEventType::Pressed) {
		PRINT("TaiPressedAction::actByEvent:EVENT_PRESSED:%08x\n", event.mTeki);
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8013F2B4
 * Size:	00001C
 */
void TaiWarnAction::start(Teki& teki)
{
	teki.mTimers[4] = teki.getParameterF(TPF_WarnPeriod);
}

/*
 * --INFO--
 * Address:	8013F2D0
 * Size:	000034
 */
bool TaiDangerLifeAction::act(Teki& teki)
{
	return teki.mStoredDamage > 0.0f && teki.mHealth <= mDangerHealth;
}
