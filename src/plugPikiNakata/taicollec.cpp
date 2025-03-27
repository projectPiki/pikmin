#include "TAI/Collec.h"
#include "TAI/MoveActions.h"
#include "TAI/ReactionActions.h"
#include "TAI/AttackActions.h"
#include "TAI/BasicActions.h"
#include "teki.h"
#include "TekiConditions.h"
#include "Pellet.h"
#include "PelletState.h"
#include "Stickers.h"
#include "MapMgr.h"
#include "MapCode.h"
#include "SoundMgr.h"
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
DEFINE_PRINT("taicollec")

/*
 * --INFO--
 * Address:	8012AAC0
 * Size:	000084
 */
TaiCollecSoundTable::TaiCollecSoundTable()
    : PaniSoundTable(8)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_COLLEC_BREATH);
	}
}

/*
 * --INFO--
 * Address:	8012AB44
 * Size:	000484
 */
TaiCollecParameters::TaiCollecParameters()
    : TekiParameters(COLLECPI_COUNT, COLLECPF_COUNT)
{
	int j                           = TPI_COUNT;
	ParaParameterInfo<int>* iParams = mParameters->mIntParams->mParaInfo;
	iParams[j++].init("CARRY_POWER", 0, 20);

	j                               = TPF_COUNT;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("BOUNCING_DAMAGE", 0.0f, 10000.0f);
	fParams[j++].init("PRESSED_DAMAGE", 0.0f, 10000.0f);
	fParams[j++].init("GOING_UNDERGROUND_DISTANCE", 0.0f, 100.0f);
	fParams[j++].init("UNDERGROUND_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("UNDERGROUND_PERIOD_RANDOM_RATE", 0.0f, 1.0f);
	fParams[j++].init("FALLING_ROTATION_VELOCITY", 0.0f, 10.0f * NMathF::pi);
	fParams[j++].init("DANGER_LIFE", 0.0f, 1000.0f);
	fParams[j++].init("RUNNING_AWAY_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("IMPASSABLE_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("IMPASSABLE_DISTANCE", 0.0f, 1000.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CullingType, CULLAI_NeverCullAI);
	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
	multiP->setI(TPI_CarcassSize, 1);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_FlickPikiCount1, 1);
	multiP->setI(TPI_FlickPikiCount2, 2);
	multiP->setI(TPI_FlickPikiCount3, 3);
	multiP->setI(TPI_FlickDamageCount1, 3);
	multiP->setI(TPI_FlickDamageCount2, 3);
	multiP->setI(TPI_FlickDamageCount3, 3);
	multiP->setI(TPI_FlickDamageCount4, 3);

	multiP->setF(TPF_Life, 5000.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Weight, 1.0f);
	multiP->setF(TPF_WalkVelocity, 70.0f);
	multiP->setF(TPF_RunVelocity, 85.0f);
	multiP->setF(TPF_TurnVelocity, NMathF::pi);
	multiP->setF(TPF_VisibleRange, 500.0f);
	multiP->setF(TPF_VisibleAngle, 360.0f);
	multiP->setF(TPF_VisibleHeight, 30.0f);
	multiP->setF(TPF_DangerTerritoryRange, 500.0f);
	multiP->setF(TPF_LifeGaugeOffset, 30.0f);
	multiP->setF(TPF_ShadowSize, 30.0f);
	multiP->setF(TPF_RippleScale, 2.5f);
	multiP->setF(TPF_CorpseSize, 15.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_LowerRange, 30.0f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 60.0f);
	multiP->setF(TPF_LowerFlickPower, 50.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);
	multiP->setF(TPF_LifeRecoverRate, 0.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 50.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 400.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 32.0f);

	multiP->setI(COLLECPI_CarryPower, 2);

	multiP->setF(COLLECPF_BouncingDamage, 4000.0f);
	multiP->setF(COLLECPF_PressedDamage, 400.0f);
	multiP->setF(COLLECPF_GoingUndergroundDistance, 6.0f);
	multiP->setF(COLLECPF_UndergroundPeriod, 3.0f);
	multiP->setF(COLLECPF_UndergroundPeriodRandomRate, 0.3f);
	multiP->setF(COLLECPF_FallingRotationVelocity, 4.0f * NMathF::pi);
	multiP->setF(COLLECPF_DangerLife, 0.0f);
	multiP->setF(COLLECPF_RunningAwayPeriod, 6.0f);
	multiP->setF(COLLECPF_ImpassablePeriod, 8.0f);
	multiP->setF(COLLECPF_ImpassableDistance, 50.0f);
}

/*
 * --INFO--
 * Address:	8012AFC8
 * Size:	00179C
 */
TaiCollecStrategy::TaiCollecStrategy(TekiParameters* params)
    : TaiStrategy(COLLECSTATE_COUNT, COLLECSTATE_Unk3)
{
	TaiStopMoveAction* stopMove                                   = new TaiStopMoveAction();
	TaiDeadAction* dead                                           = new TaiDeadAction(COLLECSTATE_Unk0);
	TaiFlickAction* flick                                         = new TaiFlickAction(COLLECSTATE_Unk2);
	TaiSmashedAction* smashed                                     = new TaiSmashedAction(COLLECSTATE_Unk1);
	TaiSimultaneousDamageAction* simDamage                        = new TaiSimultaneousDamageAction(TAI_NO_TRANSIT);
	TaiCollecLegEffectAction* legEffect                           = new TaiCollecLegEffectAction(-0.5f);
	TaiTypeNaviWatchResultOnAction* naviWatchResult               = new TaiTypeNaviWatchResultOnAction();
	TaiCollecPelletDisappearedAction* pelletDisappeared           = new TaiCollecPelletDisappearedAction(COLLECSTATE_Unk3);
	TaiCollecPelletStartContainerizedAction* pelletStartContainer = new TaiCollecPelletStartContainerizedAction(COLLECSTATE_Unk11);
	TaiCollecImpassableAction* impassable = new TaiCollecImpassableAction(COLLECSTATE_Unk8, 0, params->getF(COLLECPF_ImpassablePeriod),
	                                                                      params->getF(COLLECPF_ImpassableDistance));
	TaiCollecLetGoOfPelletAction* letGo   = new TaiCollecLetGoOfPelletAction(TAI_NO_TRANSIT);
	TaiDependenceAction* deadLetGo        = new TaiDependenceAction(COLLECSTATE_Unk0, letGo, dead);
	TaiDependenceAction* smashedLetGo     = new TaiDependenceAction(COLLECSTATE_Unk1, letGo, smashed);
	TaiDependenceAction* flickLetGo       = new TaiDependenceAction(COLLECSTATE_Unk2, letGo, flick);
	TaiDependenceAction* disappearLetGo   = new TaiDependenceAction(COLLECSTATE_Unk3, letGo, pelletDisappeared);
	TaiDependenceAction* impassableLetGo  = new TaiDependenceAction(COLLECSTATE_Unk8, letGo, impassable);
	TaiDyingAction* dying                 = new TaiDyingAction(0);
	TaiStartDyingAction* startDying       = new TaiStartDyingAction();

	//  STATE -
	TaiState* state = new TaiState(3);
	int j           = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, startDying);
	state->setAction(j++, dying);
	setState(COLLECSTATE_Unk0, state);

	TaiDamagingAction* damaging      = new TaiDamagingAction(COLLECSTATE_Unk3, 1);
	TaiLifeDamageAction* lifeDamage1 = new TaiLifeDamageAction(params->getF(COLLECPF_PressedDamage));

	//  STATE -
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, lifeDamage1);
	state->setAction(j++, damaging);
	setState(COLLECSTATE_Unk1, state);

	TaiFlickingAction* flicking = new TaiFlickingAction(COLLECSTATE_Unk3, 9);

	//  STATE -
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, dead);
	state->setAction(j++, simDamage);
	state->setAction(j++, flicking);
	setState(COLLECSTATE_Unk2, state);

	TaiCollecTargetPelletAction* targetPellet1     = new TaiCollecTargetPelletAction(COLLECSTATE_Unk4);
	TaiRandomWanderingRouteAction* randomWandering = new TaiRandomWanderingRouteAction(6, params->getF(TPF_WalkVelocity));
	TaiHeadOnCollisionAvoidanceAction* headOnAvoid = new TaiHeadOnCollisionAvoidanceAction(50.0f);
	TaiCollecVisibleHeightPelletLostTimerAction* visibleHeightLostTimer = new TaiCollecVisibleHeightPelletLostTimerAction(1, 15.0f);

	//  STATE -
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, smashed);
	state->setAction(j++, flick);
	state->setAction(j++, simDamage);
	state->setAction(j++, targetPellet1);
	state->setAction(j++, randomWandering);
	state->setAction(j++, headOnAvoid);
	state->setAction(j++, impassable);
	state->setAction(j++, legEffect);
	state->setAction(j++, visibleHeightLostTimer);
	setState(COLLECSTATE_Unk3, state);

	TaiCollecPelletLostAction* pelletLost                     = new TaiCollecPelletLostAction(COLLECSTATE_Unk3);
	TaiCollecTargetPelletAction* targetPellet2                = new TaiCollecTargetPelletAction(TAI_NO_TRANSIT);
	TaiCollecHoldPelletAction* holdPellet                     = new TaiCollecHoldPelletAction(COLLECSTATE_Unk5);
	TaiTracingAction* tracing                                 = new TaiTracingAction(6, params->getF(TPF_RunVelocity));
	TaiCollecVisibleHeightPelletLostAction* visibleHeightLost = new TaiCollecVisibleHeightPelletLostAction(COLLECSTATE_Unk3);

	//  STATE -
	state = new TaiState(11);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, smashed);
	state->setAction(j++, flick);
	state->setAction(j++, simDamage);
	state->setAction(j++, visibleHeightLost);
	state->setAction(j++, pelletLost);
	state->setAction(j++, targetPellet2);
	state->setAction(j++, tracing);
	state->setAction(j++, legEffect);
	state->setAction(j++, impassable);
	state->setAction(j++, holdPellet);
	setState(COLLECSTATE_Unk4, state);

	TaiMotionAction* motion1          = new TaiMotionAction(TAI_NO_TRANSIT, 7);
	TaiAnimationKeyAction* animKey    = new TaiAnimationKeyAction(COLLECSTATE_Unk6, BTeki::ANIMATION_KEY_OPTION_LOOPSTART);
	TaiCollecCatchingAction* catching = new TaiCollecCatchingAction();

	//  STATE -
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, deadLetGo);
	state->setAction(j++, smashedLetGo);
	state->setAction(j++, flickLetGo);
	state->setAction(j++, disappearLetGo);
	state->setAction(j++, simDamage);
	state->setAction(j++, animKey);
	state->setAction(j++, motion1);
	state->setAction(j++, catching);
	state->setAction(j++, naviWatchResult);
	setState(COLLECSTATE_Unk5, state);

	TaiCollecCarryingToNestAction* carryingToNest   = new TaiCollecCarryingToNestAction(COLLECSTATE_Unk8, 7, 3);
	TaiCollecRouteImpassableAction* routeImpassable = new TaiCollecRouteImpassableAction(COLLECSTATE_Unk14);
	TaiCollecPutAction* put                         = new TaiCollecPutAction(COLLECSTATE_Unk8);
	TaiCollecDefeatCarryingAction* defeatCarrying   = new TaiCollecDefeatCarryingAction(COLLECSTATE_Unk7);
	TaiCollecCarryingAction* carrying               = new TaiCollecCarryingAction(TAI_NO_TRANSIT);

	//  STATE -
	state = new TaiState(13);
	j     = 0;
	state->setAction(j++, pelletStartContainer);
	state->setAction(j++, deadLetGo);
	state->setAction(j++, smashedLetGo);
	state->setAction(j++, flickLetGo);
	state->setAction(j++, disappearLetGo);
	state->setAction(j++, simDamage);
	state->setAction(j++, defeatCarrying);
	state->setAction(j++, put);
	state->setAction(j++, carryingToNest);
	state->setAction(j++, routeImpassable);
	state->setAction(j++, carrying);
	state->setAction(j++, impassableLetGo);
	state->setAction(j++, naviWatchResult);
	setState(COLLECSTATE_Unk6, state);

	TaiCollecWinCarryingAction* winCarrying = new TaiCollecWinCarryingAction(TAI_NO_TRANSIT);
	TaiDependenceAction* winCarryingLetGo   = new TaiDependenceAction(COLLECSTATE_Unk4, letGo, winCarrying);
	TaiMotionAction* motion2                = new TaiMotionAction(TAI_NO_TRANSIT, 10);
	TaiCollecBeingDraggedAction* dragged    = new TaiCollecBeingDraggedAction();

	//  STATE -
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, pelletStartContainer);
	state->setAction(j++, deadLetGo);
	state->setAction(j++, smashedLetGo);
	state->setAction(j++, flickLetGo);
	state->setAction(j++, disappearLetGo);
	state->setAction(j++, simDamage);
	state->setAction(j++, winCarryingLetGo);
	state->setAction(j++, dragged);
	state->setAction(j++, motion2);
	setState(COLLECSTATE_Unk7, state);

	TaiMotionAction* motion3                    = new TaiMotionAction(COLLECSTATE_Unk9, 12);
	TaiCollecPuttingPelletAction* puttingPellet = new TaiCollecPuttingPelletAction(TAI_NO_TRANSIT);

	//  STATE -
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, puttingPellet);
	state->setAction(j++, motion3);
	state->setAction(j++, naviWatchResult);
	setState(COLLECSTATE_Unk8, state);

	TaiTimerAction* timer1 = new TaiTimerAction(COLLECSTATE_Unk10, 1, params->getF(COLLECPF_UndergroundPeriod),
	                                            params->getF(COLLECPF_UndergroundPeriodRandomRate));
	TaiSetOptionAction* setOption1
	    = new TaiSetOptionAction(BTeki::TEKI_OPTION_VISIBLE | BTeki::TEKI_OPTION_ATARI | BTeki::TEKI_OPTION_SHADOW_VISIBLE, false);
	TaiMoveNestPositionAction* moveNestPos = new TaiMoveNestPositionAction();

	//  STATE -
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, moveNestPos);
	state->setAction(j++, stopMove);
	state->setAction(j++, setOption1);
	state->setAction(j++, timer1);
	setState(COLLECSTATE_Unk9, state);

	TaiMotionAction* motion4 = new TaiMotionAction(COLLECSTATE_Unk3, 11);
	TaiSetOptionAction* setOption2
	    = new TaiSetOptionAction(BTeki::TEKI_OPTION_VISIBLE | BTeki::TEKI_OPTION_ATARI | BTeki::TEKI_OPTION_SHADOW_VISIBLE, true);
	TaiCollecGetOutAction* getOut = new TaiCollecGetOutAction();

	//  STATE -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, dead);
	state->setAction(j++, motion4);
	state->setAction(j++, getOut);
	state->setAction(j++, setOption2);
	setState(COLLECSTATE_Unk10, state);

	TaiCollecPelletFinishContainerizedAction* finishContainer = new TaiCollecPelletFinishContainerizedAction(COLLECSTATE_Unk12);

	//  STATE -
	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, finishContainer);
	setState(COLLECSTATE_Unk11, state);

	TaiFinishMotionAction* finishMotion     = new TaiFinishMotionAction(TAI_NO_TRANSIT);
	TaiRotatingAction* rotating             = new TaiRotatingAction(params->getF(COLLECPF_FallingRotationVelocity));
	TaiCollecDeadFallingAction* deadFalling = new TaiCollecDeadFallingAction(COLLECSTATE_Unk0);
	TaiCollecFallingAction* falling         = new TaiCollecFallingAction(COLLECSTATE_Unk13);
	TaiPlaySoundAction* playSound           = new TaiPlaySoundAction(SE_COLLEC_CRY);

	//  STATE -
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, finishMotion);
	state->setAction(j++, rotating);
	state->setAction(j++, deadFalling);
	state->setAction(j++, falling);
	state->setAction(j++, playSound);
	setState(COLLECSTATE_Unk12, state);

	TaiMotionAction* motion5         = new TaiMotionAction(COLLECSTATE_Unk3, 13);
	TaiLifeDamageAction* lifeDamage2 = new TaiLifeDamageAction(params->getF(COLLECPF_BouncingDamage));

	//  STATE -
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, lifeDamage2);
	state->setAction(j++, motion5);
	setState(COLLECSTATE_Unk13, state);

	TaiTimerAction* timer2                = new TaiTimerAction(COLLECSTATE_Unk10, 1, params->getF(COLLECPF_ImpassablePeriod), 0.0f);
	TaiDependenceAction* timerLetGo       = new TaiDependenceAction(COLLECSTATE_Unk8, letGo, timer2);
	TaiCollecRoundCarryAction* roundCarry = new TaiCollecRoundCarryAction();

	//  STATE -
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, pelletStartContainer);
	state->setAction(j++, deadLetGo);
	state->setAction(j++, smashedLetGo);
	state->setAction(j++, flickLetGo);
	state->setAction(j++, disappearLetGo);
	state->setAction(j++, simDamage);
	state->setAction(j++, defeatCarrying);
	state->setAction(j++, roundCarry);
	state->setAction(j++, carrying);
	state->setAction(j++, timerLetGo);
	setState(COLLECSTATE_Unk14, state);
}

/*
 * --INFO--
 * Address:	8012C764
 * Size:	000168
 */
void TaiCollecStrategy::start(Teki& teki)
{
	teki.mParticleGenerators[0] = effectMgr->create(EffectMgr::EFF_Collec_HmA, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	teki.stopParticleGenerator(0);
	teki.mParticleGenerators[1] = effectMgr->create(EffectMgr::EFF_Collec_HmB, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	teki.stopParticleGenerator(1);
	teki.mParticleGenerators[2] = effectMgr->create(EffectMgr::EFF_Collec_Hiki, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	teki.stopParticleGenerator(2);
	teki.mParticleGenerators[3] = effectMgr->create(EffectMgr::EFF_Collec_Ashi, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	teki.stopParticleGenerator(3);

	TaiStrategy::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ORGANIC);
}

/*
 * --INFO--
 * Address:	8012C8CC
 * Size:	000110
 */
void TaiCollecStrategy::draw(Teki& teki, Graphics& gfx)
{
	TekiStrategy::draw(teki, gfx);
	if (!teki.mParticleGenerators[0]) {
		return;
	}
	teki.setParticleGeneratorPosition(3, teki.getPosition());
	if (teki.getPositionMapCode() == ATTR_Water) {
		if (teki.mParticleGenerators[3]) {
			teki.mParticleGenerators[3]->invisible();
		}
	} else if (teki.mParticleGenerators[3]) {
		teki.mParticleGenerators[3]->visible();
	}

	Creature* pellet = teki.getCreaturePointer(2);
	if (pellet) {
		teki.setParticleGeneratorPosition(2, pellet->getPosition());
		if (teki.getPositionMapCode(pellet->getPosition()) == ATTR_Water) {
			if (teki.mParticleGenerators[2]) {
				teki.mParticleGenerators[2]->invisible();
			}
		} else if (teki.mParticleGenerators[2]) {
			teki.mParticleGenerators[2]->visible();
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void TaiCollecStrategy::outputUndergroundPosition(Teki& teki, NVector3f& outPosition)
{
	f32 dist = teki.getParameterF(COLLECPF_GoingUndergroundDistance);
	teki.outputDirectionVector(outPosition);
	outPosition.scale(dist);
	outPosition.add(teki.getNestPosition());
}

/*
 * --INFO--
 * Address:	8012C9DC
 * Size:	0001F0
 */
bool TekiCollecTargetPelletCondition::satisfy(Creature* target)
{
	if (target->mObjType != OBJTYPE_Pellet) {
		return false;
	}

	Pellet* pellet = (Pellet*)target;
	if (pellet->isUfoParts()) {
		return false;
	}

	if (!pellet->winnable(mCarryPower)) {
		return false;
	}

	if (pellet->mConfig->mCarryMinPikis() > mCarryPower) {
		return false;
	}

	u32 badCompiler;

	Stickers stuckList(pellet);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (!stuck) {
			PRINT("?TekiCollecTargetPelletCondition::satisfy:%08x:creature==null\n", target);
			break;
		}
		if (stuck->mObjType == OBJTYPE_Teki) {
			Teki* collec = (Teki*)stuck;
			if (collec != mCollec && collec->mTekiType == TEKI_Collec) {
				// pellet already has a breadbug! no ganging up on pikmin!
				return false;
			}
		}
	}

	if (pellet->getStickObject()) {
		return false;
	}
	return true;

	u32 badCompiler2[2];
}

/*
 * --INFO--
 * Address:	8012CBCC
 * Size:	000040
 */
void TaiCollecImpassableAction::start(Teki& teki)
{
	if (teki.mReturnStateID == COLLECSTATE_Unk3 || teki.mReturnStateID == COLLECSTATE_Unk4 || teki.mReturnStateID == COLLECSTATE_Unk6) {
		return;
	}

	resetPosition(teki);
}

/*
 * --INFO--
 * Address:	8012CC0C
 * Size:	0000AC
 */
bool TaiCollecImpassableAction::act(Teki& teki)
{
	f32 dist = teki.mTargetPosition.distanceXZ(teki.getPosition());
	if (dist >= mMaxDistance) {
		resetPosition(teki);
		return false;
	}

	if (!teki.timerElapsed(mTimerIdx)) {
		return false;
	}

	PRINT("TaiCollecImpassableAction::act:%08x:%f,%f,%f\n", &teki, dist, mMaxDistance, mTimerLength);
	return true;

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	8012CCB8
 * Size:	000030
 */
void TaiCollecImpassableAction::resetPosition(Teki& teki)
{
	teki.mTargetPosition.input(teki.getPosition());
	teki.mTimers[mTimerIdx] = mTimerLength;
}

/*
 * --INFO--
 * Address:	8012CCE8
 * Size:	000070
 */
bool TaiCollecLetGoOfPelletAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(2);
	if (!target) {
		PRINT("TaiCollecLetGoOfPelletAction::act:target==null:%08x\n", &teki);
		return true;
	}

	Pellet* pellet = (Pellet*)target;
	pellet->endStickTeki(&teki);
	teki.clearCreaturePointer(2);
	teki.stopParticleGenerator(2);
	PRINT("TaiCollecLetGoOfPelletAction::act:endStickTeki:%08x\n", &teki);
	return true;
}

/*
 * --INFO--
 * Address:	8012CD58
 * Size:	000074
 */
bool TaiCollecLetGoOfPelletAction::actByEvent(TekiEvent& event)
{
	Teki* teki       = event.mTeki;
	Creature* target = teki->getCreaturePointer(2);
	if (!target) {
		PRINT("TaiCollecLetGoOfPelletAction::actByEvent:target==null:%08x\n", teki);
		return true;
	}

	Pellet* pellet = (Pellet*)target;
	pellet->endStickTeki(teki);
	teki->clearCreaturePointer(2);
	teki->stopParticleGenerator(2);
	PRINT("TaiCollecLetGoOfPelletAction::actactByEvent:endStickTeki:%08x\n", teki);
	return true;
}

/*
 * --INFO--
 * Address:	8012CDCC
 * Size:	000158
 */
bool TaiCollecTargetPelletAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(3);
	int carryPower   = teki.getParameterI(COLLECPI_CarryPower);
	Pellet* nearest  = (Pellet*)pelletMgr->findClosest(
        teki.getPosition(),
        &TekiAndCondition(&TekiAndCondition(&TekiVisibleCondition(&teki), &TekiCollecTargetPelletCondition(&teki, carryPower)),
	                       &TekiNotCondition(&TekiCreaturePointerCondition(target))));
	if (!nearest) {
		return false;
	}

	teki.setCreaturePointer(0, nearest);
	PRINT("TaiCollecTargetPelletAction::act:%08x,%08x,%08x\n", &teki, target, nearest);
	return true;

	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	8012CF24
 * Size:	0000E0
 */
bool TaiCollecVisibleHeightPelletLostAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT("TaiCollecVisibleHeightPelletLostAction::act:target==null:%08x\n", &teki);
		return true;
	}

	TekiVisibleHeightCondition& cond = TekiVisibleHeightCondition(&teki);
	if (!cond.satisfy(target)) {
		PRINT("TaiCollecVisibleHeightPelletLostAction::act:!condition.satisfy:%08x,%08x\n", &teki, target);
		teki.setCreaturePointer(3, target);
		teki.clearCreaturePointer(0);
		return true;
	}
	return false;

	TekiVisibleHeightCondition(nullptr);
}

/*
 * --INFO--
 * Address:	8012D004
 * Size:	000064
 */
bool TaiCollecVisibleHeightPelletLostTimerAction::act(Teki& teki)
{
	if (teki.timerElapsed(mTimerIdx)) {
		teki.clearCreaturePointer(3);
	}
	return false;
}

/*
 * --INFO--
 * Address:	8012D068
 * Size:	0000FC
 */
bool TaiCollecPelletLostAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT("TaiCollecPelletLostAction::act:target==null:%08x\n", &teki);
		return true;
	}

	TekiAndCondition& cond
	    = TekiAndCondition(&TekiVisibleCondition(&teki), &TekiCollecTargetPelletCondition(&teki, teki.getParameterI(COLLECPI_CarryPower)));
	if (!cond.satisfy(target)) {
		teki.clearCreaturePointer(0);
		return true;
	}

	return false;

	TekiAndCondition(nullptr, nullptr);
	TekiVisibleCondition(nullptr);
}

/*
 * --INFO--
 * Address:	8012D164
 * Size:	0000BC
 */
bool TaiCollecPelletDisappearedAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(2);
	if (!target) {
		PRINT("TaiCollecPelletDisappearedAction::act:target==null:%08x\n", &teki);
		return true;
	}

	TekiVisibleCondition& cond = TekiVisibleCondition(&teki);
	if (!cond.satisfy(target)) {
		PRINT("!TaiCollecPelletDisappearedAction::act:!condition.satisfy:%08x,%d\n", &teki, teki.mStateID);
		teki.clearCreaturePointer(2);
		return true;
	}

	return false;

	TekiVisibleCondition(nullptr);
	TekiVisibleCondition(nullptr);
}

/*
 * --INFO--
 * Address:	8012D220
 * Size:	000110
 */
bool TaiCollecHoldPelletAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		PRINT("!TaiCollecHoldPelletAction::act:target==null:%08x\n", &teki);
		return false;
	}

	f32 collDist = teki.calcCollisionDistance(*target);
	f32 limit    = 1.0f;
	if (collDist > limit) {
		return false;
	}

	Pellet* pellet = (Pellet*)target;
	if (!pellet->startStickTeki(&teki, limit + teki.getTekiCollisionSize())) {
		PRINT("!TaiCollecHoldPelletAction::act:%08x:startStickTeki:!sticked\n", &teki);
		teki.clearCreaturePointer(0);
		return false;
	}

	teki.clearCreaturePointer(0);
	teki.setCreaturePointer(2, pellet);
	teki.startParticleGenerator(2);
	PRINT("TaiCollecHoldPelletAction::act:%08x:startStickTeki:target:%08x\n", &teki, pellet);
	return true;
}

/*
 * --INFO--
 * Address:	8012D330
 * Size:	000050
 */
void TaiCollecCatchingAction::start(Teki& teki)
{
	teki.setTekiOption(BTeki::TEKI_OPTION_MANUAL_ANIMATION);
	teki.mMotionSpeed = teki.mTekiAnimator->getAnimationSpeed();
}

/*
 * --INFO--
 * Address:	8012D380
 * Size:	000034
 */
void TaiCollecCatchingAction::finish(Teki& teki)
{
	teki.clearTekiOption(BTeki::TEKI_OPTION_MANUAL_ANIMATION);
}

/*
 * --INFO--
 * Address:	8012D3B4
 * Size:	000034
 */
void TaiCollecCarryingAction::start(Teki& teki)
{
	PRINT("TaiCollecCarryingAction::start:%08x\n", &teki);
	teki.setTekiOption(BTeki::TEKI_OPTION_MANUAL_ANIMATION);
}

/*
 * --INFO--
 * Address:	8012D3E8
 * Size:	000034
 */
void TaiCollecCarryingAction::finish(Teki& teki)
{
	PRINT("TaiCollecCarryingAction::finish:%08x\n", &teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_MANUAL_ANIMATION);
}

/*
 * --INFO--
 * Address:	8012D41C
 * Size:	0000B8
 */
bool TaiCollecCarryingAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(2);
	if (!target) {
		PRINT("!TaiCollecCarryingAction::act:target==null:%08x\n", &teki);
		return false;
	}

	Pellet* pellet = (Pellet*)target;
	int carryPower = teki.getParameterI(COLLECPI_CarryPower);
	NVector3f drive(teki.getDrive());
	pellet->doCarry(&teki, drive, carryPower);
	teki.mMotionSpeed = teki.getVelocityAnimationSpeed(teki.getDriveLength());
	return false;
}

/*
 * --INFO--
 * Address:	8012D4D4
 * Size:	000028
 */
void TaiCollecBeingDraggedAction::start(Teki& teki)
{
	PRINT("TaiCollecBeingDraggedAction::start:%08x\n", &teki);
	teki.startParticleGenerator(3);
}

/*
 * --INFO--
 * Address:	8012D4FC
 * Size:	000028
 */
void TaiCollecBeingDraggedAction::finish(Teki& teki)
{
	PRINT("TaiCollecBeingDraggedAction::finish:%08x\n", &teki);
	teki.stopParticleGenerator(3);
}

/*
 * --INFO--
 * Address:	8012D524
 * Size:	0000A0
 */
bool TaiCollecWinCarryingAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(2);
	if (!target) {
		PRINT("!TaiCollecWinCarryingAction::act:target==null:%08x\n", &teki);
		return false;
	}

	TekiCollecTargetPelletCondition& cond = TekiCollecTargetPelletCondition(&teki, teki.getParameterI(COLLECPI_CarryPower));
	if (!cond.satisfy(target)) {
		return false;
	}

	PRINT("FAKE", target ? "fake" : "fake");
	return true;
}

/*
 * --INFO--
 * Address:	8012D5C4
 * Size:	0000A0
 */
bool TaiCollecDefeatCarryingAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(2);
	if (!target) {
		PRINT("!TaiCollecDefeatCarryingAction::act:target==null:%08x\n", &teki);
		return false;
	}

	TekiCollecTargetPelletCondition& cond = TekiCollecTargetPelletCondition(&teki, teki.getParameterI(COLLECPI_CarryPower));
	if (cond.satisfy(target)) {
		return false;
	}

	PRINT("FAKE", target ? "fake" : "fake");
	return true;
}

/*
 * --INFO--
 * Address:	8012D664
 * Size:	00015C
 */
bool TaiCollecPutAction::act(Teki& teki)
{
	if (!teki.getCreaturePointer(2)) {
		PRINT("!TaiCollecPutAction::act:target==null:%08x\n", &teki);
		return false;
	}

	NVector3f ugPos;
	TaiCollecStrategy* strat = (TaiCollecStrategy*)teki.getStrategy();
	strat->outputUndergroundPosition(teki, ugPos);
	f32 dist = ugPos.distanceXZ(teki.getPosition());
	if (!teki.arrivedAt(dist, teki.getParameterF(TPF_WalkVelocity))) {
		return false;
	}

	PRINT("fake", dist ? "fake" : "fake");
	PRINT("fake", dist ? "fake" : "fake");
	PRINT("fake", dist ? "fake" : "fake");
	return true;
}

/*
 * --INFO--
 * Address:	8012D7C0
 * Size:	0000E0
 */
void TaiCollecPuttingPelletAction::start(Teki& teki)
{
	teki.setParticleGeneratorPosition(0, teki.getPosition());
	teki.startParticleGenerator(0);

	teki.setParticleGeneratorPosition(1, teki.getPosition());
	teki.startParticleGenerator(1);

	Creature* target = teki.getCreaturePointer(2);
	if (!target) {
		PRINT("TaiCollecPuttingPelletAction::start:target==null:%08x\n", &teki);
		return;
	}

	Pellet* pellet = (Pellet*)target;
	pellet->endStickTeki(&teki);
	pellet->stimulate(InteractSwallow(&teki, teki.mCollInfo->getSphere('slot')->getChildAt(0), 0));
}

/*
 * --INFO--
 * Address:	8012D8A0
 * Size:	000040
 */
void TaiCollecPuttingPelletAction::finish(Teki& teki)
{
	teki.stopParticleGenerator(0);
	teki.stopParticleGenerator(1);
}

/*
 * --INFO--
 * Address:	8012D8E0
 * Size:	0000BC
 */
bool TaiCollecPuttingPelletAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(2);
	if (!target) {
		PRINT("TaiCollecPuttingPelletAction::act:target==null:%08x\n", &teki);
		return false;
	}

	if (teki.animationFinished()) {
		teki.flickUpper();
		Pellet* pellet = (Pellet*)target;
		pellet->stimulate(InteractKill(&teki, 0));
		teki.clearCreaturePointer(2);
		teki.stopParticleGenerator(2);
	}
	return false;
}

/*
 * --INFO--
 * Address:	8012D99C
 * Size:	000044
 */
void TaiCollecCarryingToNestAction::start(Teki& teki)
{
	TaiContinuousMotionAction::start(teki);
	makePositionRoute(teki);
}

/*
 * --INFO--
 * Address:	8012D9E0
 * Size:	000214
 */
bool TaiCollecCarryingToNestAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}

	if (teki.mRouteWayPointCount > teki.mRouteWayPointMax && teki.mCurrRouteWayPointID > teki.mRouteWayPointMax - 1) {
		PRINT("!TaiCollecCarryingToNestAction::act:too long route:%08x,%d/%d\n", &teki, teki.mCurrRouteWayPointID,
		      teki.mRouteWayPointCount);
		makePositionRoute(teki);
		return false;
	}

	f32 val = teki.getParameterF(_0C);
	if (teki.mRouteWayPointCount == 0 || teki.mCurrRouteWayPointID > teki.mRouteWayPointCount - 1) {
		PRINT("TaiCollecCarryingToNestAction::act:%08x:%f,%d/%d\n", &teki, teki.getDirection(), teki.mCurrRouteWayPointID,
		      teki.mRouteWayPointCount);
		NVector3f ugPos;
		TaiCollecStrategy* strat = (TaiCollecStrategy*)teki.getStrategy();
		strat->outputUndergroundPosition(teki, ugPos);
		if (BTeki::moveTowardStatic(teki.getPosition(), ugPos, val, teki.mTargetVelocity)) {
			return true;
		}
		return false;
	}

	WayPoint* wp = teki.getRouteWayPoint(teki.mCurrRouteWayPointID);
	if (!wp) {
		PRINT("?TaiCollecCarryingToNestAction::act:%08x:wayPoint==null:%d/%d\n", &teki, teki.mCurrRouteWayPointID,
		      teki.mRouteWayPointCount);
		return false;
	}

	Creature* target = teki.getCreaturePointer(2);
	if (!target) {
		PRINT("?TaiCollecCarryingToNestAction::act:target==null:%08x\n", &teki);
		return false;
	}

	if (BTeki::moveTowardStatic(target->getPosition(), wp->mPosition, val, teki.mTargetVelocity)) {
		PRINT("TaiCollecCarryingToNestAction::act2:%08x,%d/%d\n", &teki, teki.mCurrRouteWayPointID, teki.mRouteWayPointCount);
		teki.mCurrRouteWayPointID++;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8012DBF4
 * Size:	000054
 */
void TaiCollecCarryingToNestAction::makePositionRoute(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(2);
	if (!target) {
		PRINT("?TaiCollecCarryingToNestAction::makePositionRoute:target==null:%08x\n", &teki);
		return;
	}
	Pellet* pellet = (Pellet*)target;
	teki.makePositionRoute(pellet->getPosition(), teki.getNestPosition(), false);
	teki.mCurrRouteWayPointID = 0;

	u32 badCompiler;
}

/*
 * --INFO--
 * Address:	8012DC48
 * Size:	0000A0
 */
bool TaiCollecRouteImpassableAction::act(Teki& teki)
{
	if (teki.mRouteWayPointCount == 0) {
		// oops! no route!
		return true;
	}

	if (teki.mRouteWayPointCount > teki.mRouteWayPointMax && teki.mCurrRouteWayPointID > teki.mRouteWayPointMax - 1) {
		// this isn't impassable, this is just hopelessly cooked.
		return false;
	}

	if (teki.mCurrRouteWayPointID > teki.mRouteWayPointCount - 1) {
		// again, this isn't impassable, this is just hopelessly cooked.
		return false;
	}

	WayPoint* wp = teki.getRouteWayPoint(teki.mCurrRouteWayPointID);
	if (!wp) {
		PRINT("?TaiCollecRouteImpassableAction::act:%08x:wayPoint==null:%d/%d\n", &teki, teki.mCurrRouteWayPointID,
		      teki.mRouteWayPointCount);
		// no waypoint? that's a paddling.
		return true;
	}

	if (!wp->mIsOpen) {
		PRINT("TaiCollecRouteImpassableAction::act:%08x:!wayPoint->on:%d/%d\n", &teki, teki.mCurrRouteWayPointID, teki.mRouteWayPointCount);
		// blocked waypoint? that's a paddling.
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8012DCE8
 * Size:	000014
 */
void TaiCollecRoundCarryAction::start(Teki& teki)
{
	teki.mTargetAngle = teki.getDirection() + NMathF::pi;
}

/*
 * --INFO--
 * Address:	8012DCFC
 * Size:	0000E8
 */
bool TaiCollecRoundCarryAction::act(Teki& teki)
{
	f32 fTime = NSystem::getFrameTime();
	teki.mTargetAngle += teki.getParameterF(TPF_TurnVelocity) * fTime;
	NVector3f dir;
	BTeki::outputDirectionVector(teki.mTargetAngle, dir);
	f32 speed = teki.getParameterF(TPF_WalkVelocity);
	dir.scale(speed);
	teki.inputDrive(dir);
	return false;
}

/*
 * --INFO--
 * Address:	8012DDE4
 * Size:	000064
 */
bool TaiCollecPelletStartContainerizedAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(2);
	if (!target) {
		PRINT("!TaiCollecPelletStartContainerizedAction::act:target==null:%08x\n", &teki);
		return true;
	}
	Pellet* pellet = (Pellet*)target;
	if (pellet->getState() == PELSTATE_Goal) {
		teki.stopParticleGenerator(2);
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8012DE48
 * Size:	000058
 */
bool TaiCollecPelletFinishContainerizedAction::act(Teki& teki)
{
	if (!teki.getStickObject()) {
		PRINT("TaiCollecPelletFinishContainerizedAction::act:%08x\n", &teki);
		teki.clearCreaturePointer(2);
		return true;
	}
	return false;

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	8012DEA0
 * Size:	000078
 */
bool TaiCollecDeadFallingAction::act(Teki& teki)
{
	if (teki.mHealth > teki.getParameterF(COLLECPF_BouncingDamage)) {
		return false;
	}
	if (teki.getPosition().y < teki.getSeaLevel() + 10.0f) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8012DF18
 * Size:	000050
 */
bool TaiCollecFallingAction::act(Teki& teki)
{
	if (teki.getPosition().y < teki.getSeaLevel() + 10.0f) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8012DF68
 * Size:	00006C
 */
bool TaiCollecGetOutAction::act(Teki& teki)
{
	u32 badCompiler;
	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
		effectMgr->create(EffectMgr::EFF_Collec_StA, teki.getPosition(), nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Collec_StB, teki.getPosition(), nullptr, nullptr);
	}
	return false;
}

/*
 * --INFO--
 * Address:	8012DFD4
 * Size:	000058
 */
TaiCollecLegEffectAction::TaiCollecLegEffectAction(f32 p1)
    : TaiJointEffectAction(p1, 2, 'lleg', 'rleg', 0, 0)
{
}

/*
 * --INFO--
 * Address:	8012E02C
 * Size:	000090
 */
void TaiCollecLegEffectAction::setType(Vector3f& effectPos, int type, int id)
{
	effectPos.y = mapMgr->getMinY(effectPos.x, effectPos.z, true);
	if (type == 5) {
		mEffectType = EffectMgr::EFF_P_Bubbles;
	} else if (type == -1) {
		mEffectType = EffectMgr::EFF_NULL;
	} else {
		mEffectType = EffectMgr::EFF_SmokeRing_S;
	}

	_18 = 112;
}

/*
 * --INFO--
 * Address:	8012E0BC
 * Size:	000088
 */
TaiHollecParameters::TaiHollecParameters()
    : TekiParameters(TPI_COUNT, TPF_COUNT)
{
	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_SpawnType, -1);

	multiP->setF(TPF_Weight, 1000.0f);
	multiP->setF(TPF_Scale, 1.2f);
	multiP->setF(TPF_Life, 1.0f);
}

/*
 * --INFO--
 * Address:	8012E144
 * Size:	0000C4
 */
TaiHollecStrategy::TaiHollecStrategy(TekiParameters*)
    : TaiStrategy(HOLLECSTATE_COUNT, HOLLECSTATE_Unk0)
{
	TaiMotionAction* motion = new TaiMotionAction(TAI_NO_TRANSIT, 2);

	//  STATE -
	TaiState* state = new TaiState(1);
	int j           = 0;
	state->setAction(j++, motion);
	setState(HOLLECSTATE_Unk0, state);
}

/*
 * --INFO--
 * Address:	8012E208
 * Size:	000058
 */
void TaiHollecStrategy::draw(Teki& teki, Graphics& gfx)
{
	teki.moveNestPosition();
	TekiStrategy::draw(teki, gfx);
}

/*
 * --INFO--
 * Address:	8012E260
 * Size:	00008C
 */
void TaiHollecStrategy::start(Teki& teki)
{
	TaiStrategy::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_VISIBLE);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ORGANIC);
	teki.clearTekiOption(BTeki::TEKI_OPTION_SHADOW_VISIBLE);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ATARI);
}
