#include "TAI/KabekuiC.h"
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
DEFINE_PRINT("TAIkabekuiC")

/**
 * @brief TODO
 *
 * @note Lives here because it needs PRINT to match.
 */
struct TAIAtakeOffKabekuiC : public TAIAreserveMotion {
	TAIAtakeOffKabekuiC(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
		mTakeoffSpeed = 0.7f;
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAreserveMotion::start(teki);
		teki.setFlag400();
		teki.startFlying();
		teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		teki.mVelocity = teki.mTargetVelocity;

		teki.setDororoGravity(teki.getParameterF(TPF_FlightHeight) * 2.0f / SQUARE(mTakeoffSpeed));
		teki.setFlyingSwitch(false);
	}

	virtual bool act(Teki& teki) // _10
	{
		if (TAIAreserveMotion::act(teki)) {
			if (teki.mCurrentAnimEvent == KEY_Action0) {
				f32 walkSpeed = teki.getParameterF(TPF_WalkVelocity);

				teki.setFlyingSwitch(true);

				f32 flyVel = teki.getDororoGravity() * mTakeoffSpeed;
				f32 zVel   = cosf(teki.getDirection());
				f32 xVel   = sinf(teki.getDirection());
				teki.mTargetVelocity.set(walkSpeed * xVel, flyVel, walkSpeed * zVel);

				CollTriInfo* currTriInfo = mapMgr->getCurrTri(teki.getPosition().x, teki.getPosition().z, true);
				if (currTriInfo != nullptr && MapCode::getAttribute(currTriInfo) == ATTR_Water) {
					mRippleEffect.create(teki);
				}
			}

			if (teki.getFlyingSwitch()) {
				teki.mTargetVelocity.y += -teki.getDororoGravity() * gsys->getFrameTime();
				teki.mVelocity = teki.mTargetVelocity;
			}

			if (teki.mCurrentAnimEvent == KEY_Finished) {
				teki.mTargetVelocity.y *= 0.1f;
				teki.mVelocity = teki.mTargetVelocity;
				return true;
			}

			return false;
		}

		STACK_PAD_TERNARY(&teki, 2);
		return false;
	}

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	f32 mTakeoffSpeed;          // _0C
	rippleEffect mRippleEffect; // _10
};

/*
 * --INFO--
 * Address:	801CD720
 * Size:	000084
 */
TAIkabekuiCSoundTable::TAIkabekuiCSoundTable()
    : PaniSoundTable(3)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_WALLEAT_WALK);
	}
}

/*
 * --INFO--
 * Address:	801CD7A4
 * Size:	000478
 */
TAIkabekuiCParameters::TAIkabekuiCParameters()
    : TekiParameters(TPI_COUNT, TAIkabekuiCFloatParms::COUNT)
{
	int j                           = TAIkabekuiCFloatParms::BridgeAttackRange;
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("壁食いポイントの大きさ", 0.0f, 1000.0f);              // 'Size of wall bite point'
	fParams[j++].init("壁食いダメージ", 0.0f, 100.0f);                       // 'wall eating damage'
	fParams[j++].init("空中に逃げる時のライフのパーセンテージ", 0.0f, 1.0f); // 'Life percentage when fleeing into the air'
	fParams[j++].init("地上に降りる時のライフのパーセンテージ", 0.0f, 1.0f); // 'Life percentage when descending to the ground'
	fParams[j++].init("滞空中のｙ軸方向の速度", 0.0f, 1000.0f);              // 'Y-axis velocity while airborne'
	fParams[j++].init("離陸する時のｙ軸方向の速度", 0.0f, 1000.0f);          // 'Velocity in the y-axis direction when taking off'
	fParams[j++].init("潜るまでの時間（秒）", 0.0f, 100.0f);                 // 'Time until diving (sec)'
	fParams[j++].init("スリープ時間（秒）", 0.0f, 100.0f);                   // 'Sleep Time (seconds)'
	fParams[j++].init("ピキ攻撃判定サイズ", 0.0f, 100.0f);                   // 'Piki attack detection size'
	fParams[j++].init("ナビ攻撃判定サイズ", 0.0f, 100.0f);                   // 'Navi attack detection size'

	multiP->setF(TAIkabekuiCFloatParms::BridgeAttackRange, 8.0f);
	multiP->setF(TAIkabekuiCFloatParms::BridgeDamage, 1.0f);
	multiP->setF(TAIkabekuiCFloatParms::FlightAlertLifePercent, 0.5f);
	multiP->setF(TAIkabekuiCFloatParms::MaxFlightLifePercent, 0.8f);
	multiP->setF(TAIkabekuiCFloatParms::FlightYVelocity, 20.0f);
	multiP->setF(TAIkabekuiCFloatParms::TakeoffYVelocity, 70.0f);
	multiP->setF(TAIkabekuiCFloatParms::TimeUntilBurrow, 3.0f);
	multiP->setF(TAIkabekuiCFloatParms::MaxSleepTime, 3.0f);
	multiP->setF(TAIkabekuiCFloatParms::PikiAttackRange, 15.0f);
	multiP->setF(TAIkabekuiCFloatParms::NaviAttackRange, 15.0f);

	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
	multiP->setI(TPI_SpawnType, TEKI_NULL);
	multiP->setI(TPI_SwallowCount, 5);
	multiP->setI(TPI_FlickPikiCount1, 2);
	multiP->setI(TPI_FlickPikiCount2, 5);
	multiP->setI(TPI_FlickPikiCount3, 10);
	multiP->setI(TPI_FlickDamageCount1, 3);
	multiP->setI(TPI_FlickDamageCount2, 3);
	multiP->setI(TPI_FlickDamageCount3, 3);
	multiP->setI(TPI_FlickDamageCount4, 3);
	multiP->setI(TPI_CullingType, CULLAI_NeverCullAI);
	multiP->setI(TPI_CarcassSize, 2);

	multiP->setF(TPF_Weight, 100.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 50.0f);

	multiP->setF(TPF_WalkVelocity, 50.0f);
	multiP->setF(TPF_RunVelocity, 120.0f);
	multiP->setF(TPF_TurnVelocity, 1.5009831f);

	multiP->setF(TPF_VisibleRange, 150.0f);
	multiP->setF(TPF_VisibleAngle, 360.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);

	multiP->setF(TPF_AttackableRange, 40.0f);
	multiP->setF(TPF_AttackableAngle, 60.0f);
	multiP->setF(TPF_AttackRange, 30.0f);
	multiP->setF(TPF_AttackHitRange, 9.0f);
	multiP->setF(TPF_AttackPower, 5.0f);

	multiP->setF(TPF_DangerTerritoryRange, 400.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 120.0f);

	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);

	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 300.0f);
	multiP->setF(TPF_LowerFlickPower, 300.0f);
	multiP->setF(TPF_UpperAttackPower, 20.0f);
	multiP->setF(TPF_LowerAttackPower, 10.0f);

	multiP->setF(TPF_LifeRecoverRate, 0.05f);
	multiP->setF(TPF_LifeGaugeOffset, 20.0f);

	multiP->setF(TPF_ShadowSize, 10.0f);
	multiP->setF(TPF_TraceAngle, 60.0f);

	multiP->setF(TPF_CorpseSize, 10.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);

	multiP->setF(TPF_FlightHeight, 50.0f);
	multiP->setF(TPF_RippleScale, 1.0f);

	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	801CDC1C
 * Size:	00129C
 */
TAIkabekuiCStrategy::TAIkabekuiCStrategy()
    : YaiStrategy(TAIkabekuiCStateID::COUNT, TAIkabekuiCStateID::Waiting)
{
	TAIAdeadCheck* deadCheck       = new TAIAdeadCheck(TAIkabekuiCStateID::Dying);
	TAIAdyingKabekui* dyingKabekui = new TAIAdyingKabekui(TAI_NO_TRANSIT, TAIkabekuiCMotionID::Unk0, EffectMgr::EFF_SmokeRing_S);
	TAIAdamage* damage             = new TAIAdamage(TAI_NO_TRANSIT, 1);
	TAIAstop* stop                 = new TAIAstop(TAI_NO_TRANSIT);

	new TAIArandomWalk(TAI_NO_TRANSIT, TAIkabekuiCMotionID::Unk6); // unused

	TAIAsetMotionSpeed* setMotionSpeedAppear = new TAIAsetMotionSpeed(TAI_NO_TRANSIT, TAIkabekuiCMotionID::Unk4, 0.0f);
	TAIAvisibleNavi* visibleNaviThenAppear   = new TAIAvisibleNavi(TAIkabekuiCStateID::Appearing);

	new TAIAvisiblePiki(TAIkabekuiCStateID::Appearing); // unused

	TAIAappearKabekui* appearThenSetupMove = new TAIAappearKabekui(TAIkabekuiCStateID::MovingSetup, TAIkabekuiCMotionID::Unk4, 30.0f, 1);
	TAIAsetTargetPointCircleRandom* setTargetThenMove = new TAIAsetTargetPointCircleRandom(TAIkabekuiCStateID::MovingBridge);
	TAIAgoTargetPriorityFaceDir* turnToTargetThenSetup
	    = new TAIAgoTargetPriorityFaceDir(TAIkabekuiCStateID::MovingSetup, TAIkabekuiCMotionID::Unk6);

	TAIAvisibleNavi* visibleNavi2                     = new TAIAvisibleNavi(TAIkabekuiCStateID::MovingPiki);
	TAIAvisiblePiki* visiblePiki                      = new TAIAvisiblePiki(TAIkabekuiCStateID::MovingPiki);
	TAIAapproachTargetPriorityFaceDir* approachTarget = new TAIAapproachTargetPriorityFaceDir(TAI_NO_TRANSIT, TAIkabekuiCMotionID::Unk6);
	TAIAattackableTarget* attackableTarget            = new TAIAattackableTarget(TAIkabekuiCStateID::BiteAttack);
	TAIAunvisibleTarget* unvisibleTarget              = new TAIAunvisibleTarget(TAIkabekuiCStateID::MovingSetup);
	TAIAbiteForKabekuiC* kabekuiBite = new TAIAbiteForKabekuiC(TAIkabekuiCStateID::BiteChewing, 3, TAIkabekuiCMotionID::Unk10);
	TAIAeatPiki* eatPiki             = new TAIAeatPiki(TAIkabekuiCStateID::MovingSetup, TAIkabekuiCMotionID::Unk11);

	TAIAlessLifeKabekuiC* alertFlightLife = new TAIAlessLifeKabekuiC(TAIkabekuiCStateID::Takeoff);
	TAIAtakeOffKabekuiC* takeoff          = new TAIAtakeOffKabekuiC(TAIkabekuiCStateID::Flying, TAIkabekuiCMotionID::Unk12);

	TAIAflyingInTerritory* flyingInTerritory  = new TAIAflyingInTerritory(TAI_NO_TRANSIT, 0.25f);
	TAIAflyingBaseKabekuiC* flyingBase        = new TAIAflyingBaseKabekuiC(TAI_NO_TRANSIT);
	TAIAflyingMotionKabekuiC* flyingMotion    = new TAIAflyingMotionKabekuiC(TAI_NO_TRANSIT, TAIkabekuiCMotionID::Unk3);
	TAIAcheckPikiFlyKabekuiC* flyingHitCheck  = new TAIAcheckPikiFlyKabekuiC(TAIkabekuiCStateID::Dying);
	TAIAmoreLifeKabekuiC* flyingLifeThreshold = new TAIAmoreLifeKabekuiC(TAIkabekuiCStateID::Landing);
	TAIAlandingKabekuiC* landing              = new TAIAlandingKabekuiC(TAIkabekuiCStateID::MovingSetup, TAIkabekuiCMotionID::Unk13);

	TAIAhitCheckFlyingPiki* pressCheck = new TAIAhitCheckFlyingPiki(TAIkabekuiCStateID::CrushDying);
	TAIAdyingCrushKabekui* crushDying  = new TAIAdyingCrushKabekui(TAI_NO_TRANSIT, TAIkabekuiCMotionID::Unk1, EffectMgr::EFF_SmokeRing_S);
	TAIAsearchWorkObject* searchWorkObjectThenChase   = new TAIAsearchWorkObject(TAIkabekuiCStateID::ChasingSetup);
	TAIAinvincibleOn* invincibleOn                    = new TAIAinvincibleOn(TAI_NO_TRANSIT);
	TAIAinvincibleOff* invincibleOff                  = new TAIAinvincibleOff(TAI_NO_TRANSIT);
	TAIAsetTargetPointWorkObject* setTargetWorkObject = new TAIAsetTargetPointWorkObject(TAIkabekuiCStateID::Chasing);
	TAIAgoTargetPriorityFaceDir* targetFaceDirThenEat
	    = new TAIAgoTargetPriorityFaceDir(TAIkabekuiCStateID::EatingBridge, TAIkabekuiCMotionID::Unk6);

	TAIAattackWorkObjectKabekuiC* attackWorkObject
	    = new TAIAattackWorkObjectKabekuiC(TAIkabekuiCStateID::MovingBridge, TAIkabekuiCMotionID::Unk6, 8);

	TAIAsearchWorkObject* searchWorkObjectThenAppear = new TAIAsearchWorkObject(TAIkabekuiCStateID::Appearing);
	TAIAdiveKabekuiC* diveKabekuiC                   = new TAIAdiveKabekuiC(TAIkabekuiCStateID::Burrowing);
	TAIAappearKabekui* burrowKabekui = new TAIAappearKabekui(TAIkabekuiCStateID::WaitingSetup, TAIkabekuiCMotionID::Unk5, 30.0f, 0);
	TAIAsleepKabekuiC* sleepKabekuiC = new TAIAsleepKabekuiC(TAIkabekuiCStateID::Waiting);
	TAIAshadowOn* shadowOn           = new TAIAshadowOn(TAI_NO_TRANSIT);
	TAIAshadowOff* shadowOff         = new TAIAshadowOff(TAI_NO_TRANSIT);
	TAIAinWaterDamage* inWaterDamage = new TAIAinWaterDamage(TAI_NO_TRANSIT, 20.0f, 1);

	// STATE 0 - Dying
	TaiState* state = new TaiState(2);
	int j           = 0;
	state->setAction(j++, dyingKabekui);
	state->setAction(j++, stop);
	setState(TAIkabekuiCStateID::Dying, state);

	// STATE 1 - Waiting
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, shadowOff);
	state->setAction(j++, invincibleOn);
	state->setAction(j++, setMotionSpeedAppear);
	state->setAction(j++, visibleNaviThenAppear);
	state->setAction(j++, searchWorkObjectThenAppear);
	setState(TAIkabekuiCStateID::Waiting, state);

	// STATE 2 - Appearing
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, shadowOn);
	state->setAction(j++, appearThenSetupMove);
	setState(TAIkabekuiCStateID::Appearing, state);

	// STATE 3 - MovingSetup
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, invincibleOff);
	state->setAction(j++, setTargetThenMove);
	setState(TAIkabekuiCStateID::MovingSetup, state);

	// STATE 4 - MovingBridge
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, pressCheck);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, alertFlightLife);
	state->setAction(j++, turnToTargetThenSetup);
	state->setAction(j++, visiblePiki);
	state->setAction(j++, visibleNavi2);
	state->setAction(j++, searchWorkObjectThenChase);
	state->setAction(j++, diveKabekuiC);
	setState(TAIkabekuiCStateID::MovingBridge, state);

	// STATE 5 - MovingPiki
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, pressCheck);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, alertFlightLife);
	state->setAction(j++, approachTarget);
	state->setAction(j++, attackableTarget);
	state->setAction(j++, unvisibleTarget);
	state->setAction(j++, visiblePiki);
	state->setAction(j++, visibleNavi2);
	setState(TAIkabekuiCStateID::MovingPiki, state);

	// STATE 6 - BiteAttack
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, pressCheck);
	state->setAction(j++, kabekuiBite);
	setState(TAIkabekuiCStateID::BiteAttack, state);

	// STATE 7 - BiteChewing
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, stop);
	state->setAction(j++, pressCheck);
	state->setAction(j++, eatPiki);
	setState(TAIkabekuiCStateID::BiteChewing, state);

	// STATE 8 - Takeoff
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, flyingHitCheck);
	state->setAction(j++, takeoff);
	state->setAction(j++, inWaterDamage);
	setState(TAIkabekuiCStateID::Takeoff, state);

	// STATE 9 - Flying
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, flyingHitCheck);
	state->setAction(j++, flyingLifeThreshold);
	state->setAction(j++, flyingBase);
	state->setAction(j++, flyingInTerritory);
	state->setAction(j++, flyingMotion);
	state->setAction(j++, inWaterDamage);
	setState(TAIkabekuiCStateID::Flying, state);

	// STATE 10 - Landing
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, flyingHitCheck);
	state->setAction(j++, landing);
	state->setAction(j++, inWaterDamage);
	setState(TAIkabekuiCStateID::Landing, state);

	// STATE 11 - CrushDying
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, crushDying);
	state->setAction(j++, stop);
	setState(TAIkabekuiCStateID::CrushDying, state);

	// STATE 12 - ChasingSetup
	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, setTargetWorkObject);
	setState(TAIkabekuiCStateID::ChasingSetup, state);

	// STATE 13 - Chasing
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, alertFlightLife);
	state->setAction(j++, visiblePiki);
	state->setAction(j++, visibleNavi2);
	state->setAction(j++, pressCheck);
	state->setAction(j++, targetFaceDirThenEat); // after reaching the target, start eating the bridge
	setState(TAIkabekuiCStateID::Chasing, state);

	// STATE 14 - EatingBridge
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, alertFlightLife);
	state->setAction(j++, visiblePiki);
	state->setAction(j++, visibleNavi2);
	state->setAction(j++, pressCheck);
	state->setAction(j++, attackWorkObject); // eat that bridge!
	setState(TAIkabekuiCStateID::EatingBridge, state);

	// STATE 15 - Burrowing
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, invincibleOn);
	state->setAction(j++, burrowKabekui);
	state->setAction(j++, stop);
	setState(TAIkabekuiCStateID::Burrowing, state);

	// STATE 16 - WaitingSetup
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, shadowOff);
	state->setAction(j++, sleepKabekuiC);
	setState(TAIkabekuiCStateID::WaitingSetup, state);

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	801CEEB8
 * Size:	0006FC
 */
void TAIkabekuiCAnimation::makeDefaultAnimations()
{
	if (!mAnimMgr) {
		return;
	}

	// lol, these are so just copy pasted
	gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_KabekuiB]->mShape;
	addAnimation("tekis/kabekuiC/motion/dead.dca");

	addAnimation("tekis/kabekuiC/motion/damage.dca");

	addAnimation("tekis/kabekuiC/motion/wait1.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/kabekuiC/motion/wait2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/kabekuiC/motion/waitact1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiC/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiC/motion/move1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiC/motion/move2.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiC/motion/attack.dca");
	addKeyFrame(58);
	addInfoKey(1, 2);

	addAnimation("tekis/kabekuiC/motion/type1.dck");
	addKeyFrame(8);
	addKeyFrame(43);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiC/motion/type2.dca");
	addKeyFrame(32);
	addInfoKey(1, 2);
}
