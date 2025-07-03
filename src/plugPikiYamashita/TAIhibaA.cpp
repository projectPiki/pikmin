#include "TAI/HibaA.h"
#include "TAI/Amove.h"
#include "SoundMgr.h"
#include "MapMgr.h"
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
DEFINE_PRINT("TAIhibaA")

/**
 * @brief TODO
 *
 * @note In TAIhibaA.cpp to match a function with a PRINT statement.
 */
struct TAIAfireAttackHibaA : public TAIAreserveMotion {
	TAIAfireAttackHibaA(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAreserveMotion::start(teki);
		teki.setFrameCounter(0.0f);
		teki.setPtclGenPtr(YTeki::PTCL_Unk0, nullptr);
	}
	virtual bool act(Teki& teki) // _10
	{
		bool res = false;
		zen::particleGenerator* ptclGen;
		if (TAIAreserveMotion::act(teki)) {
			teki.addFrameCounter(gsys->getFrameTime());
			if (teki.mCurrentAnimEvent == KEY_LoopStart && !teki.getPtclGenPtr(YTeki::PTCL_Unk0)) {
				CollPart* part = teki.mCollInfo->getSphere('hblp');
				if (part) {
					Matrix4f mtx = part->getMatrix();
					Vector3f vec1;
					vec1.set(mtx.mMtx[0][1], mtx.mMtx[1][1], mtx.mMtx[2][1]);
					Vector3f vec2;

					teki.initCylinderTYpePtclCallBack(&teki, part->mCentre, Vector3f(vec1 * 330.0f),
					                                  teki.getParameterF(TAIhibaAFloatParams::AttackTime),
					                                  teki.getParameterF(TPF_AttackPower), 70.0f, 18.0f, &eventCallBack);

					if (!teki.getPtclGenPtr(YTeki::PTCL_Unk0)) {
						ptclGen = effectMgr->create(EffectMgr::EFF_Hiba_Fire, part->mCentre, teki.getCylinderTypePtclCallBack(), nullptr);
						if (ptclGen) {
							ptclGen->setEmitDir(vec1);
							teki.playEventSound(&teki, SE_TANK_FIRE);
						}
						teki.setPtclGenPtr(YTeki::PTCL_Unk0, ptclGen);
					}
				}
			}

			if (teki.getFrameCounter() > teki.getParameterF(TAIhibaAFloatParams::AttackTime)) {
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
				ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk0);
				if (ptclGen) {
					ptclGen->finish();
					teki.setPtclGenPtr(YTeki::PTCL_Unk0, nullptr);
					teki.stopEventSound(&teki, SE_TANK_FIRE);
				}
			}
			if (teki.mCurrentAnimEvent == KEY_Finished) {
				res = true;
			}
		}

		STACK_PAD_TERNARY(res, 1);
		return res;
	}

	static TAIeffectAttackEventCallBackHibaA eventCallBack;

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
};

TAIeffectAttackEventCallBackHibaA TAIAfireAttackHibaA::eventCallBack;

/*
 * --INFO--
 * Address:	801D4800
 * Size:	000084
 */
TAIhibaASoundTable::TAIhibaASoundTable()
    : PaniSoundTable(7)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_TANK_FIRE);
	}
}

/*
 * --INFO--
 * Address:	801D4884
 * Size:	0002F8
 */
TAIhibaAParameters::TAIhibaAParameters()
    : TekiParameters(TPI_COUNT, TAIhibaAFloatParams::COUNT)
{
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	int j                           = TPF_COUNT;
	fParams[j++].init("待ち時間（秒）", 0.0f, 100.0f); // 'wait time (sec)'
	fParams[j++].init("攻撃時間（秒）", 0.0f, 100.0f); // 'attack time (sec)'

	multiP->setF(TAIhibaAFloatParams::WaitTime, 4.0f);
	multiP->setF(TAIhibaAFloatParams::AttackTime, 3.0f);

	multiP->setI(TPI_SpawnType, TEKI_NULL);
	multiP->setI(TPI_SwallowCount, 5);
	multiP->setI(TPI_FlickPikiCount1, 2);
	multiP->setI(TPI_FlickPikiCount2, 5);
	multiP->setI(TPI_FlickPikiCount3, 10);
	multiP->setI(TPI_FlickDamageCount1, 3);
	multiP->setI(TPI_FlickDamageCount2, 3);
	multiP->setI(TPI_FlickDamageCount3, 3);
	multiP->setI(TPI_FlickDamageCount4, 3);
	multiP->setI(TPI_CullingType, CULLAI_CullAIOffCamera);

	multiP->setF(TPF_Weight, 100.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 1000.0f);

	multiP->setF(TPF_WalkVelocity, 20.0f);
	multiP->setF(TPF_RunVelocity, 120.0f);
	multiP->setF(TPF_TurnVelocity, 57.0f * PI / 180.0f);

	multiP->setF(TPF_VisibleRange, 150.0f);
	multiP->setF(TPF_VisibleAngle, 180.0f);
	multiP->setF(TPF_VisibleHeight, 1000.0f);

	multiP->setF(TPF_AttackableRange, 40.0f);
	multiP->setF(TPF_AttackableAngle, 30.0f);
	multiP->setF(TPF_AttackRange, 30.0f);
	multiP->setF(TPF_AttackHitRange, 9.0f);
	multiP->setF(TPF_AttackPower, 30.0f);

	multiP->setF(TPF_DangerTerritoryRange, 150.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 120.0f);

	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);

	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 300.0f);
	multiP->setF(TPF_LowerFlickPower, 300.0f);
	multiP->setF(TPF_UpperAttackPower, 20.0f);
	multiP->setF(TPF_LowerAttackPower, 10.0f);

	multiP->setF(TPF_LifeRecoverRate, 0.01f);
	multiP->setF(TPF_LifeGaugeOffset, 200.0f);

	multiP->setF(TPF_ShadowSize, 15.0f);
	multiP->setF(TPF_TraceAngle, 60.0f);

	multiP->setF(TPF_SpawnDistance, 0.0f);
	multiP->setF(TPF_SpawnHeight, 20.0f);
	multiP->setF(TPF_SpawnVelocity, 0.0f);
}

/*
 * --INFO--
 * Address:	801D4B7C
 * Size:	0001E8
 */
TAIhibaAStrategy::TAIhibaAStrategy()
    : YaiStrategy(TAIhibaAStateID::COUNT, TAIhibaAStateID::Init)
{
	TAIAinitHibaA* init             = new TAIAinitHibaA(TAIhibaAStateID::Wait);
	TAIAstop* stop                  = new TAIAstop(TAI_NO_TRANSIT);
	TAIAtimerReactionHibaA* timer   = new TAIAtimerReactionHibaA(TAIhibaAStateID::Attack);
	TAIAreserveMotion* unused       = new TAIAreserveMotion(TAI_NO_TRANSIT, TAIhibaAMotionID::Unk2);
	TAIAfireAttackHibaA* fireAttack = new TAIAfireAttackHibaA(TAIhibaAStateID::Wait, TAIhibaAMotionID::Unk8);

	// STATE 0 - Initialise
	TaiState* state = new TaiState(1);
	int j           = 0;
	state->setAction(j++, init);
	setState(TAIhibaAStateID::Init, state);

	// STATE 1 - Wait
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, stop);
	state->setAction(j++, timer);
	setState(TAIhibaAStateID::Wait, state);

	// STATE 2 - Attack
	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, fireAttack);
	setState(TAIhibaAStateID::Attack, state);
}

/*
 * --INFO--
 * Address:	801D4D64
 * Size:	000188
 */
void TAIhibaAStrategy::act(Teki& teki)
{
	teki.getPosition().set(teki.mPersonality->mNestPosition);
	YaiStrategy::act(teki);

	zen::particleGenerator* ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk0);
	if (ptclGen) {
		if (ptclGen->checkEmit()) {
			CollPart* part = teki.mCollInfo->getSphere('hblp');
			if (part) {
				Matrix4f mtx = part->getMatrix();
				ptclGen->setEmitPos(part->mCentre);
				ptclGen->setEmitDir(Vector3f(mtx.mMtx[0][1], mtx.mMtx[1][1], mtx.mMtx[2][1]));
			} else {
				ptclGen->finish();
				teki.setPtclGenPtr(YTeki::PTCL_Unk0, nullptr);
			}
		} else {
			teki.setPtclGenPtr(YTeki::PTCL_Unk0, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	801D4EEC
 * Size:	00003C
 */
void TAIhibaAStrategy::draw(Teki& teki, Graphics& gfx)
{
	teki.getPosition().set(teki.mPersonality->mNestPosition);
	YaiStrategy::draw(teki, gfx);
}

/*
 * --INFO--
 * Address:	801D4F28
 * Size:	0006FC
 */
void TAIhibaAAnimation::makeDefaultAnimations()
{
	if (!mAnimMgr) {
		return;
	}

	gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_KabekuiB]->mShape;
	addAnimation("tekis/hibaA/motion/dead.dca");

	addAnimation("tekis/hibaA/motion/damage.dca");

	addAnimation("tekis/hibaA/motion/wait1.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/hibaA/motion/wait2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/hibaA/motion/waitact1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/hibaA/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/hibaA/motion/move1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/hibaA/motion/move2.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/hibaA/motion/attack.dca");
	addKeyFrame(58);
	addInfoKey(1, 2);

	addAnimation("tekis/hibaA/motion/type1.dck");
	addKeyFrame(8);
	addKeyFrame(43);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/hibaA/motion/type2.dca");
	addKeyFrame(32);
	addInfoKey(1, 2);
}
