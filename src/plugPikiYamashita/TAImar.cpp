#include "DebugLog.h"
#include "MapCode.h"
#include "NaviMgr.h"
#include "Pcam/CameraManager.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "TAI/Mar.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(31)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("TAImar")

/**
 * @brief TODO
 */
struct TAIeffectAttackEventCallBackMar : public TAIeffectAttackEventCallBack {
	virtual bool hitCreature(zen::particleGenerator* ptclGen, TAIeffectAttackParam* param, Creature* target, Vector3f p4) // _10
	{
		f32 force = zen::Rand(250.0f) + 150.0f;
		Iterator iter(naviMgr);
		CI_LOOP(iter)
		{
			if (target == *iter) {
				force = 300.0f;
				p4.y  = 0.0f;
			}
		}

		p4.multiply(force);
		if (!ptclGen->checkEmit()) {
			ERROR("before wind ITTE YOSI!!!!!!!!!");
		}
		InteractWind wind(param->mTeki, p4, 0.0f, ptclGen);
		target->stimulate(wind);
		if (!ptclGen->checkEmit()) {
			PRINT("type:%d \n", target->mObjType);
			target->dump();
			ERROR("after wind ITTE YOSI!!!!!!!!!");
		}
		return false;
	}
	virtual void playEventSound(zen::particleGenerator* ptclGen, TAIeffectAttackParam* param) // _18
	{
		if (param->mTeki && !ptclGen->checkEmit()) {
			param->mTeki->stopEventSound(param->mTeki, SE_MAR_WIND);
		}
	}
	virtual bool hitMap(TAIeffectAttackParam* param) // _14
	{
		bool res = false;
		Vector3f vec1;
		if (!param->mSubEmitter1 && !param->mSubEmitter2) {
			MoveTrace trace(param->mPosition, param->mVelocity, 10.0f, false);
			mapMgr->traceMove(nullptr, trace, gsys->getFrameTime());
			if (param->mVelocity.x != trace.mVelocity.x || param->mVelocity.y != trace.mVelocity.y
			    || param->mVelocity.z != trace.mVelocity.z) {
				Vector3f vec2;
				Vector3f vec3;
				param->mVelocity.normalize();
				trace.mVelocity.normalize();
				vec2.set(-(param->mVelocity.x + trace.mVelocity.x), -(param->mVelocity.y + trace.mVelocity.y),
				         -(param->mVelocity.z + trace.mVelocity.z));
				vec2.normalize();
				vec3.set(trace.mPosition.x, trace.mPosition.y + 10.0f, trace.mPosition.z);

				param->mSubEmitter1 = effectMgr->create(EffectMgr::EFF_Mar_WindSpray, vec3, nullptr, nullptr);
				if (param->mSubEmitter1) {
					vec3.set(vec3.x + vec2.x * 30.0f, vec3.y, vec3.z + vec2.z * 30.0f);
					param->mSubEmitter1->setNewtonField(vec3, -0.032f, true);
					param->mSubEmitter1->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
				}

				param->mSubEmitter2 = effectMgr->create(EffectMgr::EFF_Mar_WindDust, vec3, nullptr, nullptr);
				if (param->mSubEmitter2) {
					vec3.set(vec3.x + vec2.x * 120.0f, vec3.y, vec3.z + vec2.z * 120.0f);
					param->mSubEmitter2->setNewtonField(vec3, -0.005f, true);
					param->mSubEmitter2->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
				}

				res = true;
			}
		}

		return res;
	}

	// _00     = VTBL
	// _00-_04 = TAIeffectAttackEventCallBack?
	// TODO: members
};

/**
 * @brief TODO
 */
struct BreathEffect : public zen::CallBack1<Teki&> {
public:
	virtual bool invoke(Teki& teki) // _08
	{
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			CollPart* mouth = teki.mCollInfo->getSphere('kuti');
			f32 dist        = NMathF::cos(-27.0f * PI / 180.0f);
			Vector3f dir1(NMathF::sin(teki.mFaceDirection) * dist, NMathF::sin(-27.0f * PI / 180.0f),
			              NMathF::cos(teki.mFaceDirection) * dist);
			f32 angle = 27.0f + 18.5f;
			dist      = NMathF::cos(-angle * PI / 180.0f);
			Vector3f dir2(NMathF::sin(teki.mFaceDirection) * dist, NMathF::sin(-angle * PI / 180.0f),
			              NMathF::cos(teki.mFaceDirection) * dist);
			teki.playEventSound(&teki, SE_MAR_WIND);

			teki.initConeTypePtclCallBack(&teki, mouth->mCentre, Vector3f(dir2 * 750.0f), 1.0f,
			                              teki.getParameterF(TAImarFloatParams::Unk51) * PI / 180.0f, 300.0f,
			                              teki.getParameterF(TPF_AttackPower), &BreathEffect::eventCallBack);

			zen::particleGenerator* ptclGen
			    = effectMgr->create(EffectMgr::EFF_Mar_WindJet, mouth->mCentre, teki.getConeTypePtclCallBack(), nullptr);
			teki.setPtclGenPtr(YTeki::PTCL_Unk0, ptclGen);
			if (ptclGen) {
				ptclGen->setEmitPos(mouth->mCentre);
				ptclGen->setEmitDir(dir1);
				ptclGen->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
			}

			rumbleMgr->start(RUMBLE_Unk11, 0, teki.getPosition());
		}

		return true;
	}

protected:
	static TAIeffectAttackEventCallBackMar eventCallBack;

	// _00     = VTBL
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

f32 TAIAdyingMar::effectScale0;
f32 TAIAdyingMar::effectScale1;
f32 TAIAdyingMar::effectStartCounter;
TAIeffectAttackEventCallBackMar BreathEffect::eventCallBack;

/*
 * --INFO--
 * Address:	801A5774
 * Size:	000084
 */
TAImarSoundTable::TAImarSoundTable()
    : PaniSoundTable(6)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_MAR_FLY);
	}
}

/*
 * --INFO--
 * Address:	801A57F8
 * Size:	000440
 */
TAImarParameters::TAImarParameters()
    : TekiParameters(TAImarIntParams::COUNT, TAImarFloatParams::COUNT)
{
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<int>* iParams = multiP->mIntParams->mParaInfo;
	ParaParameterInfo<f32>* fParams = multiP->mFloatParams->mParaInfo;
	int j                           = TPI_COUNT;
	iParams[j++].init("空中振り払いまでの打撃数", 0, 100); // 'num hits before being knocked out of the air'
	iParams[j++].init("降下する引っ付きピキ数", 0, 100);   // 'descending sticky piki num'
	iParams[j++].init("離陸する引っ付きピキ数", 0, 100);   // 'num sticky pikis taking off'

	j = TPF_COUNT;
	fParams[j++].init("攻撃位置オフセット", 0.0f, 300.0f);          // 'attack pos offset'
	fParams[j++].init("突風攻撃当たり円錐角度", 0.0f, 360.0f);      // 'gust attack hit cone angle'
	fParams[j++].init("突風攻撃モーション速度", 0.0f, 300.0f);      // 'gust attack motion speed'
	fParams[j++].init("空中振り払いまでの時間（秒）", 0.0f, 30.0f); // 'time to air shake off (sec)'
	fParams[j++].init("離陸までの時間（秒）", 0.0f, 30.0f);         // 'time until takeoff (sec)'
	fParams[j++].init("強制的に降下する時間（秒）", 0.0f, 30.0f);   // 'forced descent time (sec)'
	fParams[j++].init("上下移動の速度", 0.0f, 100.0f);              // 'up and down movement speed'

	multiP->setI(TAImarIntParams::Unk20, 30);
	multiP->setI(TAImarIntParams::Unk21, 10);
	multiP->setI(TAImarIntParams::Unk22, 10);

	multiP->setF(TAImarFloatParams::Unk50, 90.0f);
	multiP->setF(TAImarFloatParams::Unk51, 70.0f);
	multiP->setF(TAImarFloatParams::Unk52, 30.0f);
	multiP->setF(TAImarFloatParams::Unk53, 3.0f);
	multiP->setF(TAImarFloatParams::Unk54, 7.0f);
	multiP->setF(TAImarFloatParams::Unk55, 0.5f);
	multiP->setF(TAImarFloatParams::Unk56, 40.0f);

	multiP->setI(TPI_SpawnType, TEKI_NULL);
	multiP->setI(TPI_SwallowCount, 5);
	multiP->setI(TPI_FlickPikiCount1, 10);
	multiP->setI(TPI_FlickPikiCount2, 20);
	multiP->setI(TPI_FlickPikiCount3, 30);
	multiP->setI(TPI_FlickDamageCount1, 30);
	multiP->setI(TPI_FlickDamageCount2, 30);
	multiP->setI(TPI_FlickDamageCount3, 30);
	multiP->setI(TPI_FlickDamageCount4, 30);

	multiP->setF(TPF_Weight, 300.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 2000.0f);
	multiP->setF(TPF_WalkVelocity, 60.0f);
	multiP->setF(TPF_RunVelocity, 100.0f);
	multiP->setF(TPF_TurnVelocity, 5.0f * PI / 180.0f);
	multiP->setF(TPF_VisibleRange, 270.0f);
	multiP->setF(TPF_VisibleAngle, 180.0f);
	multiP->setF(TPF_VisibleHeight, 1000.0f);
	multiP->setF(TPF_AttackableRange, 0.01f);
	multiP->setF(TPF_AttackableAngle, 5.0f);
	multiP->setF(TPF_AttackRange, 30.0f);
	multiP->setF(TPF_AttackHitRange, 9.0f);
	multiP->setF(TPF_AttackPower, 0.0f);
	multiP->setF(TPF_DangerTerritoryRange, 300.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 120.0f);

	multiP->setF(TPF_LifeGaugeOffset, 40.0f);
	multiP->setF(TPF_ShadowSize, 60.0f);

	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);

	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 200.0f);
	multiP->setF(TPF_LowerFlickPower, 100.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);

	multiP->setF(TPF_LifeRecoverRate, 0.01f);
	multiP->setF(TPF_TraceAngle, 60.0f);
	multiP->setF(TPF_FlightHeight, 60.0f);

	multiP->setI(TPI_CullingType, CULLAI_CullAIOffCamera);
}

/*
 * --INFO--
 * Address:	801A5C38
 * Size:	000DE8
 */
TAImarStrategy::TAImarStrategy()
    : YaiStrategy(TAImarStateID::COUNT, TAImarStateID::Unk2)
{
	TAIAdeadCheck* deadCheck1                = new TAIAdeadCheck(TAImarStateID::Unk0);
	TAIAdeadCheck* deadCheck2                = new TAIAdeadCheck(TAImarStateID::Unk1);
	TAIAdyingMar* dying1                     = new TAIAdyingMar(TAI_NO_TRANSIT, TekiMotion::Dead);
	TAIAdyingMar* dying2                     = new TAIAdyingMar(TAI_NO_TRANSIT, TekiMotion::Type3);
	TAIAstop* stop                           = new TAIAstop(TAI_NO_TRANSIT);
	TAIAdamage* damage                       = new TAIAdamage(TAI_NO_TRANSIT, true);
	TAIAflyingInTerritory* flyingInTerritory = new TAIAflyingInTerritory(TAI_NO_TRANSIT, 0.025f);
	TAIAflyingBaseMar* flying                = new TAIAflyingBaseMar(TAI_NO_TRANSIT);
	TAIAreserveMotion* motion1               = new TAIAreserveMotion(TAI_NO_TRANSIT, TekiMotion::Move1);
	TAIAflickCheckTimerMar* flickCheckTimer  = new TAIAflickCheckTimerMar(TAImarStateID::Unk4);
	TAIAflickingMar* flicking1               = new TAIAflickingMar(TAImarStateID::Unk3, TekiMotion::Damage);
	TAIAstickingPikiMarFly* stickingPikiFly  = new TAIAstickingPikiMarFly(TAImarStateID::Unk5);
	TAIAdescent* descent                     = new TAIAdescent(TAImarStateID::Unk6, TekiMotion::Type2);
	TAIAlandingMar* landing                  = new TAIAlandingMar(TAImarStateID::Unk7, TekiMotion::Move2);
	TAIAreserveMotion* motion2               = new TAIAreserveMotion(TAI_NO_TRANSIT, TekiMotion::Wait1);
	TAIAflickCheckMar* flickCheckMar         = new TAIAflickCheckMar(TAImarStateID::Unk8);
	TAIAflickingMar* flicking2               = new TAIAflickingMar(TAImarStateID::Unk9, TekiMotion::Flick);
	TAIAstickingPikiMar* stickingPiki        = new TAIAstickingPikiMar(TAImarStateID::Unk7);
	TAIAnoReaction* noReact                  = new TAIAnoReaction(TAImarStateID::Unk10);
	TAIAtakeOffMar* takeOff                  = new TAIAtakeOffMar(TAImarStateID::Unk3, TekiMotion::Type1);
	TAIAtimerTakeOffMar* timerTakeOff        = new TAIAtimerTakeOffMar(TAImarStateID::Unk10);
	TAIAvisibleNavi* visibleNavi             = new TAIAvisibleNavi(TAImarStateID::Unk11);
	TAIAvisiblePiki* visiblePiki             = new TAIAvisiblePiki(TAImarStateID::Unk11);
	TAIAflyingDistanceMar* flyingDistance    = new TAIAflyingDistanceMar(TAImarStateID::Unk12, 27.0f * PI / 180.0f, 0.1f);
	TAIAfireBreathMar* fireBreath            = new TAIAfireBreathMar(TAImarStateID::Unk3, TekiMotion::Attack, new BreathEffect());
	TAIAoutsideTerritory* outsideTerritory   = new TAIAoutsideTerritory(TAImarStateID::Unk13);
	TAIAflyingDistanceInTerritoryMar* flyingDistanceInTerritory
	    = new TAIAflyingDistanceInTerritoryMar(TAImarStateID::Unk3, TekiMotion::Move1, 27.0f * PI / 180.0f, 0.15f);
	TAIAflickCheck* flickCheck = new TAIAflickCheck(TAImarStateID::Unk14, 1);
	TAIAwatchNavi* watchNavi   = new TAIAwatchNavi(TAImarStateID::Unk11);
	TAIAinitMar* init          = new TAIAinitMar(TAImarStateID::Unk3);

	// STATE 0 - Unknown
	TaiState* state = new TaiState(2);
	int j           = 0;
	state->setAction(j++, dying1);
	state->setAction(j++, stop);
	setState(TAImarStateID::Unk0, state);

	// STATE 1 - Unknown
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, dying2);
	state->setAction(j++, stop);
	setState(TAImarStateID::Unk1, state);

	// STATE 2 - Unknown
	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, init);
	setState(TAImarStateID::Unk2, state);

	// STATE 3 - Unknown
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, deadCheck2);
	state->setAction(j++, flying);
	state->setAction(j++, flyingInTerritory);
	state->setAction(j++, stickingPikiFly);
	state->setAction(j++, damage);
	state->setAction(j++, visiblePiki);
	state->setAction(j++, visibleNavi);
	state->setAction(j++, flickCheck);
	state->setAction(j++, motion1);
	setState(TAImarStateID::Unk3, state);

	// STATE 14 - Unknown
	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, watchNavi);
	setState(TAImarStateID::Unk14, state);

	// STATE 4 - Unknown
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, deadCheck2);
	state->setAction(j++, damage);
	state->setAction(j++, flicking1);
	state->setAction(j++, flying);
	setState(TAImarStateID::Unk4, state);

	// STATE 5 - Unknown
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, deadCheck2);
	state->setAction(j++, descent);
	state->setAction(j++, damage);
	setState(TAImarStateID::Unk5, state);

	// STATE 6 - Unknown
	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, landing);
	setState(TAImarStateID::Unk6, state);

	// STATE 7 - Unknown
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, deadCheck1);
	state->setAction(j++, damage);
	state->setAction(j++, timerTakeOff);
	state->setAction(j++, flickCheckMar);
	state->setAction(j++, motion2);
	setState(TAImarStateID::Unk7, state);

	// STATE 8 - Unknown
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, deadCheck1);
	state->setAction(j++, damage);
	state->setAction(j++, flicking2);
	setState(TAImarStateID::Unk8, state);

	// STATE 9 - Unknown
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, stickingPiki);
	state->setAction(j++, noReact);
	setState(TAImarStateID::Unk9, state);

	// STATE 10 - Unknown
	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, takeOff);
	setState(TAImarStateID::Unk10, state);

	// STATE 11 - Unknown
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, deadCheck1);
	state->setAction(j++, flyingDistance);
	state->setAction(j++, flying);
	state->setAction(j++, stickingPikiFly);
	state->setAction(j++, damage);
	state->setAction(j++, flickCheckTimer);
	state->setAction(j++, outsideTerritory);
	setState(TAImarStateID::Unk11, state);

	// STATE 12 - Unknown
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, deadCheck1);
	state->setAction(j++, damage);
	state->setAction(j++, stop);
	state->setAction(j++, fireBreath);
	state->setAction(j++, flying);
	setState(TAImarStateID::Unk12, state);

	// STATE 13 - Unknown
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, deadCheck1);
	state->setAction(j++, flying);
	state->setAction(j++, flyingDistanceInTerritory);
	state->setAction(j++, stickingPikiFly);
	state->setAction(j++, damage);
	state->setAction(j++, flickCheckTimer);
	setState(TAImarStateID::Unk13, state);
}

/*
 * --INFO--
 * Address:	801A6A20
 * Size:	0001CC
 */
void TAImarStrategy::act(Teki& teki)
{
	zen::particleGenerator* ptclGen;
	YaiStrategy::act(teki);
	CollPart* mouth = teki.mCollInfo->getSphere('kuti');
	if (mouth) {
		Matrix4f mtx = mouth->getMatrix();
		Vector3f dir;
		dir.set(mtx.mMtx[0][0], mtx.mMtx[1][0], mtx.mMtx[2][0]);
		ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk0);
		if (ptclGen) {
			if (!ptclGen->checkEmit()) {
				teki.setPtclGenPtr(YTeki::PTCL_Unk0, nullptr);
			} else {
				ptclGen->setEmitPos(mouth->mCentre);
				ptclGen->setEmitDir(dir);
			}
		}

		ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk1);
		if (ptclGen) {
			ptclGen->setEmitPos(mouth->mCentre);
			ptclGen->setEmitDir(dir);
		}

		ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk2);
		if (ptclGen) {
			ptclGen->setEmitPos(mouth->mCentre);
			ptclGen->setEmitDir(dir);
		}
	}
}

/*
 * --INFO--
 * Address:	801A6BEC
 * Size:	0000C4
 */
bool TAImarStrategy::interact(Teki& teki, TekiInteractionKey& key)
{
	switch (key.mInteractionType) {
	case TekiInteractType::Attack:
		InteractAttack* attack = (InteractAttack*)key.mInteraction;
		if (!teki.getTekiOption(BTeki::TEKI_OPTION_INVINCIBLE)) {
			teki.mStoredDamage += attack->mDamage;
			if (teki.getTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE)) {
				teki.mDamageCount++;
			}
		}

		teki.setCreaturePointer(1, attack->mOwner);
		return true;
	}

	STACK_PAD_VAR(2);
	return true;
}

/*
 * --INFO--
 * Address:	801A6CB0
 * Size:	00032C
 */
void TAImarAnimation::makeDefaultAnimations()
{
	if (!mAnimMgr) {
		return;
	}

	gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_Mar]->mShape;
	addAnimation("tekis/mar/motion/dead1.dca");

	addAnimation("tekis/mar/motion/damage.dca");

	addAnimation("tekis/mar/motion/wait1.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/mar/motion/wait2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/mar/motion/waitact1.dca");

	addAnimation("tekis/mar/motion/waitact2.dca");

	addAnimation("tekis/mar/motion/move1.dck");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/mar/motion/move2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/mar/motion/attack.dca");

	addAnimation("tekis/mar/motion/type1.dca");

	addAnimation("tekis/mar/motion/type2.dca");
}
