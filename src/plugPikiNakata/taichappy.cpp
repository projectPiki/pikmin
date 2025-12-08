#include "TAI/Chappy.h"

#include "DebugLog.h"
#include "MapMgr.h"
#include "SoundMgr.h"
#include "TAI/AttackActions.h"
#include "TAI/BasicActions.h"
#include "TAI/EffectActions.h"
#include "TAI/JudgementActions.h"
#include "TAI/MessageActions.h"
#include "TAI/MotionActions.h"
#include "TAI/MoveActions.h"
#include "TAI/ReactionActions.h"
#include "TAI/TimerActions.h"
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
DEFINE_PRINT("taichappy")

/**
 * @brief TODO
 */
struct TaiChappyCryAction : public TaiAction {
	TaiChappyCryAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiChappySmashedAction : public TaiSmashedAction {
	TaiChappySmashedAction(int nextState)
	    : TaiSmashedAction(nextState)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiSmashedAction?
};

/**
 * @brief TODO
 */
struct TaiChappyLegEffectAction : public TaiJointEffectAction {
	TaiChappyLegEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

/*
 * --INFO--
 * Address:	80128520
 * Size:	000084
 */
TaiChappySoundTable::TaiChappySoundTable()
    : PaniSoundTable(8)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_MINIC_WALK);
	}
}

/*
 * --INFO--
 * Address:	801285A4
 * Size:	0003A4
 */
TaiChappyParameters::TaiChappyParameters()
    : TekiParameters(CHAPPYPI_COUNT, CHAPPYPF_COUNT)
{
	int j                           = TPI_COUNT;
	ParaParameterInfo<int>* iParams = mParameters->mIntParams->mParaInfo;
	iParams[j++].init("SMASH_TYPE", 0, 1);

	j                               = TPF_COUNT;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("PRESSED_PERIOD", 0.0f, 10.0f);
	fParams[j++].init("CRYING_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("SMASH_DAMAGE", 0.0f, 10000.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
	multiP->setI(TPI_CarcassSize, 2);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_SwallowCount, 1);
	multiP->setI(TPI_FlickPikiCount1, 1);
	multiP->setI(TPI_FlickPikiCount2, 2);
	multiP->setI(TPI_FlickPikiCount3, 3);
	multiP->setI(TPI_FlickDamageCount1, 1);
	multiP->setI(TPI_FlickDamageCount2, 1);
	multiP->setI(TPI_FlickDamageCount3, 2);
	multiP->setI(TPI_FlickDamageCount4, 2);

	multiP->setF(TPF_Life, 100.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Weight, 1.0f);
	multiP->setF(TPF_WalkVelocity, 10.0f);
	multiP->setF(TPF_RunVelocity, 50.0f);
	multiP->setF(TPF_TurnVelocity, 1.8f);
	multiP->setF(TPF_VisibleRange, 95.0f);
	multiP->setF(TPF_VisibleAngle, 360.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 18.0f);
	multiP->setF(TPF_AttackableAngle, 40.0f);
	multiP->setF(TPF_AttackRange, 15.0f);
	multiP->setF(TPF_LowerRange, 20.0f);
	multiP->setF(TPF_AttackHitRange, 10.0f);
	multiP->setF(TPF_AttackPower, 10.0f);
	multiP->setF(TPF_DangerTerritoryRange, 500.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 80.0f);
	multiP->setF(TPF_LifeGaugeOffset, 30.0f);
	multiP->setF(TPF_ShadowSize, 25.0f);
	multiP->setF(TPF_RippleScale, 2.0f);
	multiP->setF(TPF_CorpseSize, 10.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_MessageRange, 300.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 60.0f);
	multiP->setF(TPF_LowerFlickPower, 50.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 50.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 400.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 16.0f);

	multiP->setI(CHAPPYPI_SmashType, 0);
	multiP->setF(CHAPPYPF_CryingPeriod, 3.0f);
	multiP->setF(CHAPPYPF_PressedPeriod, 1.0f);
	multiP->setF(CHAPPYPF_SmashDamage, 100.0f);
}

/*
 * --INFO--
 * Address:	80128948
 * Size:	0003A0
 */
TaiBlackChappyParameters::TaiBlackChappyParameters()
    : TekiParameters(CHAPPYPI_COUNT, CHAPPYPF_COUNT)
{
	int j                           = TPI_COUNT;
	ParaParameterInfo<int>* iParams = mParameters->mIntParams->mParaInfo;
	iParams[j++].init("SMASH_TYPE", 0, 1);

	j                               = TPF_COUNT;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("PRESSED_PERIOD", 0.0f, 10.0f);
	fParams[j++].init("CRYING_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("SMASH_DAMAGE", 0.0f, 10000.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
	multiP->setI(TPI_CarcassSize, 2);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_SwallowCount, 2);
	multiP->setI(TPI_FlickPikiCount1, 1);
	multiP->setI(TPI_FlickPikiCount2, 2);
	multiP->setI(TPI_FlickPikiCount3, 3);
	multiP->setI(TPI_FlickDamageCount1, 1);
	multiP->setI(TPI_FlickDamageCount2, 1);
	multiP->setI(TPI_FlickDamageCount3, 2);
	multiP->setI(TPI_FlickDamageCount4, 2);

	multiP->setF(TPF_Life, 1000.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Weight, 1.0f);
	multiP->setF(TPF_WalkVelocity, 10.0f);
	multiP->setF(TPF_RunVelocity, 50.0f);
	multiP->setF(TPF_TurnVelocity, 1.8f);
	multiP->setF(TPF_VisibleRange, 80.0f);
	multiP->setF(TPF_VisibleAngle, 360.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 18.0f);
	multiP->setF(TPF_AttackableAngle, 40.0f);
	multiP->setF(TPF_AttackRange, 15.0f);
	multiP->setF(TPF_LowerRange, 20.0f);
	multiP->setF(TPF_AttackHitRange, 10.0f);
	multiP->setF(TPF_AttackPower, 10.0f);
	multiP->setF(TPF_DangerTerritoryRange, 500.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 80.0f);
	multiP->setF(TPF_LifeGaugeOffset, 30.0f);
	multiP->setF(TPF_ShadowSize, 25.0f);
	multiP->setF(TPF_RippleScale, 2.0f);
	multiP->setF(TPF_CorpseSize, 10.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_MessageRange, 300.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 60.0f);
	multiP->setF(TPF_LowerFlickPower, 50.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 50.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 400.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 16.0f);

	multiP->setI(CHAPPYPI_SmashType, 0);
	multiP->setF(CHAPPYPF_CryingPeriod, 10.0f);
	multiP->setF(CHAPPYPF_PressedPeriod, 1.0f);
	multiP->setF(CHAPPYPF_SmashDamage, 100.0f);
}

/*
 * --INFO--
 * Address:	80128CE8
 * Size:	000084
 */
TaiCatfishSoundTable::TaiCatfishSoundTable()
    : PaniSoundTable(3)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_NAMAZU_WALK);
	}
}

/*
 * --INFO--
 * Address:	80128D6C
 * Size:	00039C
 */
TaiCatfishParameters::TaiCatfishParameters()
    : TekiParameters(CHAPPYPI_COUNT, CHAPPYPF_COUNT)
{
	int j                           = TPI_COUNT;
	ParaParameterInfo<int>* iParams = mParameters->mIntParams->mParaInfo;
	iParams[j++].init("SMASH_TYPE", 0, 1);

	j                               = TPF_COUNT;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("PRESSED_PERIOD", 0.0f, 10.0f);
	fParams[j++].init("CRYING_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("SMASH_DAMAGE", 0.0f, 10000.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
	multiP->setI(TPI_CarcassSize, 1);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_SwallowCount, 3);
	multiP->setI(TPI_FlickPikiCount1, 1);
	multiP->setI(TPI_FlickPikiCount2, 2);
	multiP->setI(TPI_FlickPikiCount3, 3);
	multiP->setI(TPI_FlickDamageCount1, 1);
	multiP->setI(TPI_FlickDamageCount2, 1);
	multiP->setI(TPI_FlickDamageCount3, 2);
	multiP->setI(TPI_FlickDamageCount4, 2);

	multiP->setF(TPF_Life, 200.0f);
	multiP->setF(TPF_Scale, 0.7f);
	multiP->setF(TPF_Weight, 1.0f);
	multiP->setF(TPF_WalkVelocity, 30.0f);
	multiP->setF(TPF_RunVelocity, 60.0f);
	multiP->setF(TPF_TurnVelocity, 1.8f);
	multiP->setF(TPF_VisibleRange, 200.0f);
	multiP->setF(TPF_VisibleAngle, 360.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 40.0f);
	multiP->setF(TPF_AttackableAngle, 40.0f);
	multiP->setF(TPF_AttackRange, 30.0f);
	multiP->setF(TPF_LowerRange, 35.0f);
	multiP->setF(TPF_AttackHitRange, 20.0f);
	multiP->setF(TPF_AttackPower, 10.0f);
	multiP->setF(TPF_DangerTerritoryRange, 300.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 80.0f);
	multiP->setF(TPF_LifeGaugeOffset, 40.0f);
	multiP->setF(TPF_ShadowSize, 25.0f);
	multiP->setF(TPF_RippleScale, 4.0f);
	multiP->setF(TPF_CorpseSize, 10.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_MessageRange, 300.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 60.0f);
	multiP->setF(TPF_LowerFlickPower, 50.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 50.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 400.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 16.0f);

	multiP->setI(CHAPPYPI_SmashType, 1);
	multiP->setF(CHAPPYPF_CryingPeriod, 10.0f);
	multiP->setF(CHAPPYPF_PressedPeriod, 1.0f);
	multiP->setF(CHAPPYPF_SmashDamage, 100.0f);
}

/*
 * --INFO--
 * Address:	80129108
 * Size:	00156C
 */
TaiChappyStrategy::TaiChappyStrategy(TekiParameters* params)
    : TaiStrategy(CHAPPYSTATE_COUNT, CHAPPYSTATE_Unk15)
{
	TaiStopMoveAction* stopMove                     = new TaiStopMoveAction();
	TaiStoppingMoveAction* stoppingMove             = new TaiStoppingMoveAction(TekiMotion::Move1);
	TaiFinishStoppingMoveAction* finishStoppingMove = new TaiFinishStoppingMoveAction();
	TaiDeadAction* dead1                            = new TaiDeadAction(CHAPPYSTATE_Unk0);
	TaiPressedAction* pressed                       = new TaiPressedAction(CHAPPYSTATE_Unk2);
	TaiChappySmashedAction* chappySmashed           = new TaiChappySmashedAction(CHAPPYSTATE_Unk13);
	TaiResetTimerAction* resetTimer                 = new TaiResetTimerAction(0, params->getF(CHAPPYPF_CryingPeriod), 0.0f);
	TaiAndAction* timerElapsedAndCry
	    = new TaiAndAction(CHAPPYSTATE_Unk5, new TaiTimerElapsedAction(TAI_NO_TRANSIT, 0), new TaiChappyCryAction(TAI_NO_TRANSIT));
	TaiOutsideTerritoryAction* outsideTerritory1 = new TaiOutsideTerritoryAction(CHAPPYSTATE_Unk12, params->getF(TPF_DangerTerritoryRange));
	TaiFlickAction* flick                        = new TaiFlickAction(CHAPPYSTATE_Unk4);
	TaiAttackableNaviPikiAction* attackableNaviPiki                  = new TaiAttackableNaviPikiAction(CHAPPYSTATE_Unk8);
	TaiSimultaneousDamageAction* simDamage                           = new TaiSimultaneousDamageAction(TAI_NO_TRANSIT);
	TaiCounterattackSimultaneousDamageAction* counterAttackSimDamage = new TaiCounterattackSimultaneousDamageAction(CHAPPYSTATE_Unk10);
	TaiChappyLegEffectAction* legEffect                              = new TaiChappyLegEffectAction(-0.5f);
	TaiDyingAction* dying1                                           = new TaiDyingAction(TekiMotion::Dead);
	TaiStartDyingAction* startDying                                  = new TaiStartDyingAction();

	//  STATE -
	TaiState* state = new TaiState(4);
	int j           = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, pressed);
	state->setAction(j++, startDying);
	state->setAction(j++, dying1);
	setState(CHAPPYSTATE_Unk0, state);

	TaiLifeDamageAction* lifeDamage = new TaiLifeDamageAction(params->getF(CHAPPYPF_SmashDamage));
	TaiDeadAction* dead2            = new TaiDeadAction(CHAPPYSTATE_Unk1);
	TaiOnceAction* once1            = new TaiOnceAction(CHAPPYSTATE_Unk14);

	//  STATE -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, pressed);
	state->setAction(j++, lifeDamage);
	state->setAction(j++, dead2);
	state->setAction(j++, once1);
	setState(CHAPPYSTATE_Unk13, state);

	TaiMotionAction* motion1 = new TaiMotionAction(CHAPPYSTATE_Unk6, TekiMotion::Damage);

	//  STATE -
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, chappySmashed);
	state->setAction(j++, pressed);
	state->setAction(j++, motion1);
	setState(CHAPPYSTATE_Unk14, state);

	TaiDyingAction* dying2 = new TaiDyingAction(TekiMotion::Type1);

	//  STATE -
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, pressed);
	state->setAction(j++, startDying);
	state->setAction(j++, dying2);
	setState(CHAPPYSTATE_Unk1, state);

	TaiBeingPressedAction* beingPressed = new TaiBeingPressedAction(TAI_NO_TRANSIT);
	TaiTimerAction* timer               = new TaiTimerAction(CHAPPYSTATE_Unk3, 1, params->getF(CHAPPYPF_PressedPeriod), 0.0f);

	TaiFinishMotionAction* finishMotion = new TaiFinishMotionAction(TAI_NO_TRANSIT);
	TaiLifeZeroAction* lifeZero         = new TaiLifeZeroAction();

	//  STATE -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, finishMotion);
	state->setAction(j++, timer);
	state->setAction(j++, lifeZero);
	state->setAction(j++, beingPressed);
	setState(CHAPPYSTATE_Unk2, state);

	TaiDyeAction* dye = new TaiDyeAction();

	//  STATE -
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, startDying);
	state->setAction(j++, dye);
	setState(CHAPPYSTATE_Unk3, state);

	TaiFlickingAction* flicking = new TaiFlickingAction(TAI_RETURN_TRANSIT, TekiMotion::Flick);

	//  STATE -
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, dead1);
	state->setAction(j++, pressed);
	state->setAction(j++, chappySmashed);
	state->setAction(j++, simDamage);
	state->setAction(j++, flicking);
	setState(CHAPPYSTATE_Unk4, state);

	TaiKeySendMessageAction* keySendMessage = new TaiKeySendMessageAction(0, BTeki::ANIMATION_KEY_OPTION_ACTION_0);
	TaiContinuousMotionAction* contMotion1  = new TaiContinuousMotionAction(CHAPPYSTATE_Unk11, TekiMotion::Type2);

	//  STATE -
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, stoppingMove);
	state->setAction(j++, dead1);
	state->setAction(j++, pressed);
	state->setAction(j++, chappySmashed);
	state->setAction(j++, simDamage);
	state->setAction(j++, keySendMessage);
	state->setAction(j++, contMotion1);
	state->setAction(j++, resetTimer);
	setState(CHAPPYSTATE_Unk5, state);

	TaiOutsideTerritoryAction* outsideTerritory2 = new TaiOutsideTerritoryAction(CHAPPYSTATE_Unk12, params->getF(TPF_SafetyTerritoryRange));
	TaiTargetVisibleNaviPikiAction* targetVisNaviPiki1        = new TaiTargetVisibleNaviPikiAction(CHAPPYSTATE_Unk10);
	TaiWatchOffTerritoryCenterAction* watchOffTerritoryCenter = new TaiWatchOffTerritoryCenterAction(CHAPPYSTATE_Unk7);
	TaiContinuousMotionAction* contMotion2                    = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Wait1);
	TaiRandomSetAnimationCounterAction* randomAnimCounter     = new TaiRandomSetAnimationCounterAction(0, 1);

	//  STATE -
	state = new TaiState(11);
	j     = 0;
	state->setAction(j++, stoppingMove);
	state->setAction(j++, dead1);
	state->setAction(j++, pressed);
	state->setAction(j++, chappySmashed);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, counterAttackSimDamage);
	state->setAction(j++, targetVisNaviPiki1);
	state->setAction(j++, watchOffTerritoryCenter);
	state->setAction(j++, outsideTerritory2);
	state->setAction(j++, contMotion2);
	state->setAction(j++, randomAnimCounter);
	setState(CHAPPYSTATE_Unk15, state);

	//  STATE -
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, stoppingMove);
	state->setAction(j++, dead1);
	state->setAction(j++, pressed);
	state->setAction(j++, chappySmashed);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, counterAttackSimDamage);
	state->setAction(j++, targetVisNaviPiki1);
	state->setAction(j++, watchOffTerritoryCenter);
	state->setAction(j++, outsideTerritory2);
	state->setAction(j++, contMotion2);
	setState(CHAPPYSTATE_Unk6, state);

	TaiOnceAction* once2 = new TaiOnceAction(CHAPPYSTATE_Unk11);

	//  STATE -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, dead1);
	state->setAction(j++, pressed);
	state->setAction(j++, chappySmashed);
	state->setAction(j++, resetTimer);
	state->setAction(j++, once2);
	setState(CHAPPYSTATE_Unk10, state);

	TaiTurningToTargetPositionAction* turningToTargetPos
	    = new TaiTurningToTargetPositionAction(CHAPPYSTATE_Unk6, TekiMotion::WaitAct1, params->getF(TPF_TurnVelocity));
	TaiTargetNestAction* targetNest = new TaiTargetNestAction();

	//  STATE -
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, stoppingMove);
	state->setAction(j++, dead1);
	state->setAction(j++, pressed);
	state->setAction(j++, chappySmashed);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, counterAttackSimDamage);
	state->setAction(j++, targetVisNaviPiki1);
	state->setAction(j++, targetNest);
	state->setAction(j++, turningToTargetPos);
	setState(CHAPPYSTATE_Unk7, state);

	TaiTargetVisibleNaviPikiAction* targetVisNaviPiki2 = new TaiTargetVisibleNaviPikiAction(TAI_NO_TRANSIT);
	TaiTargetLostAction* targetLost                    = new TaiTargetLostAction(CHAPPYSTATE_Unk12);
	TaiTracingAction* tracing                          = new TaiTracingAction(TekiMotion::Move1, params->getF(TPF_RunVelocity));

	//  STATE -
	state = new TaiState(13);
	j     = 0;
	state->setAction(j++, finishStoppingMove);
	state->setAction(j++, tracing);
	state->setAction(j++, dead1);
	state->setAction(j++, pressed);
	state->setAction(j++, chappySmashed);
	state->setAction(j++, flick);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, counterAttackSimDamage);
	state->setAction(j++, outsideTerritory1);
	state->setAction(j++, targetVisNaviPiki2);
	state->setAction(j++, targetLost);
	state->setAction(j++, timerElapsedAndCry);
	state->setAction(j++, legEffect);
	setState(CHAPPYSTATE_Unk11, state);

	TaiMotionAction* motion2                     = new TaiMotionAction(TAI_RETURN_TRANSIT, TekiMotion::Attack);
	TaiAnimationSwallowingAction* animSwallowing = new TaiAnimationSwallowingAction(CHAPPYSTATE_Unk9);
	TaiActionStateAction* actionState            = new TaiActionStateAction(CHAPPYSTATE_Unk9, TekiMotion::Damage);

	//  STATE -
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, dead1);
	state->setAction(j++, pressed);
	state->setAction(j++, chappySmashed);
	state->setAction(j++, simDamage);
	state->setAction(j++, animSwallowing);
	state->setAction(j++, actionState);
	state->setAction(j++, motion2);
	setState(CHAPPYSTATE_Unk8, state);

	TaiSwitchMotionAction* switchMotion = new TaiSwitchMotionAction(CHAPPYSTATE_Unk11, TekiMotion::WaitAct2);

	//  STATE -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, dead1);
	state->setAction(j++, pressed);
	state->setAction(j++, chappySmashed);
	state->setAction(j++, simDamage);
	state->setAction(j++, switchMotion);
	setState(CHAPPYSTATE_Unk9, state);

	TaiGoingHomeAction* goingHome             = new TaiGoingHomeAction(TekiMotion::Move1, params->getF(TPF_RunVelocity));
	TaiInsideTerritoryAction* insideTerritory = new TaiInsideTerritoryAction(CHAPPYSTATE_Unk6, params->getF(TPF_SafetyTerritoryRange));

	//  STATE -
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, finishStoppingMove);
	state->setAction(j++, goingHome);
	state->setAction(j++, dead1);
	state->setAction(j++, pressed);
	state->setAction(j++, chappySmashed);
	state->setAction(j++, flick);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, counterAttackSimDamage);
	state->setAction(j++, insideTerritory);
	state->setAction(j++, legEffect);
	setState(CHAPPYSTATE_Unk12, state);
}

/*
 * --INFO--
 * Address:	8012A674
 * Size:	000148
 */
bool TaiChappyCryAction::act(Teki& teki)
{
	TekiAndCondition NRef cond = TekiAndCondition(&TekiTypeCondition(TEKI_Swallow),
	                                              &TekiAndCondition(&TekiOrCondition(&TekiStateCondition(15), &TekiStateCondition(1)),
	                                                                &TekiDistanceCondition(&teki, teki.getParameterF(TPF_MessageRange))));
	Creature* bulborb      = tekiMgr->findClosest(teki.getPosition(), &cond);
	if (!bulborb) {
		return false;
	}

	return true;

	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiTypeCondition(0);
}

/*
 * --INFO--
 * Address:	8012A7BC
 * Size:	000048
 */
bool TaiChappySmashedAction::actByEvent(TekiEvent& event)
{
	if (event.mTeki->getParameterI(CHAPPYPI_SmashType) == 1) {
		return false;
	}

	return TaiSmashedAction::actByEvent(event);
}

/*
 * --INFO--
 * Address:	8012A804
 * Size:	000058
 */
TaiChappyLegEffectAction::TaiChappyLegEffectAction(f32 p1)
    : TaiJointEffectAction(p1, 2, 'lleg', 'rleg', 0, 0)
{
}

/*
 * --INFO--
 * Address:	8012A85C
 * Size:	000090
 */
void TaiChappyLegEffectAction::setType(Vector3f& effectPos, int type, int id)
{
	effectPos.y = mapMgr->getMinY(effectPos.x, effectPos.z, true);
	if (type == 5) {
		mEffectType = EffectMgr::EFF_P_Bubbles;
	} else if (type == -1) {
		mEffectType = EffectMgr::EFF_NULL;
	} else {
		mEffectType = EffectMgr::EFF_SmokeRing_S;
	}

	mSoundID = 32;
}
