#include "TAI/Usuba.h"

#include "DebugLog.h"
#include "SoundMgr.h"
#include "TAI/Aattack.h"
#include "TAI/Amove.h"
#include "TAI/Areaction.h"
#include "teki.h"
#include "zen/CallBack.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("TAIusuba")

/**
 * @brief TODO
 */
struct TAIAflyUsuba : public TAIAmotion {
	TAIAflyUsuba(int nextState, int motionID)
	    : TAIAmotion(nextState, motionID)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAmotion::start(teki);
		teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		teki.mVelocity.set(0.0f, 0.0f, 0.0f);

		teki.setFlag400();
		teki.setFlyingSwitch(false);
		teki.startFlying();
	}
	virtual bool act(Teki& teki) // _10
	{
		bool isAtMaxHeight = false;
		Vector3f vec1;
		Vector3f vec2;
		Vector3f vec3;
		PRINT("Usuba is flying. %f\n", teki.mTargetVelocity.y);
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			teki.setFlyingSwitch(true);
		}

		if (teki.getFlyingSwitch()) {
			teki.mTargetVelocity.y += 50.0f * gsys->getFrameTime();
			if (teki.mTargetVelocity.y > 500.0f) {
				teki.mTargetVelocity.y = 500.0f;
			}
		}

		if (teki.getYFromSeaLevel() > 3000.0) {
			teki.mTargetVelocity.y = 0.0f;
			isAtMaxHeight          = true;
		}
		return isAtMaxHeight;
	}

	// _04     = VTBL
	// _00-_0C = TAIAmotion
};

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000084
 */
TAIusubaSoundTable::TAIusubaSoundTable()
    : PaniSoundTable(7)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_TANK_FIRE);
	}
}

/**
 * @TODO: Documentation
 */
TAIusubaParameters::TAIusubaParameters()
    : TekiParameters(TPI_COUNT, TPF_COUNT)
{
	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_SpawnType, TEKI_Dororo); // ??????????!!!!!!!!!!!
	multiP->setI(TPI_SwallowCount, 5);
	multiP->setI(TPI_FlickPikiCount1, 2);
	multiP->setI(TPI_FlickPikiCount2, 5);
	multiP->setI(TPI_FlickPikiCount3, 10);
	multiP->setI(TPI_FlickDamageCount1, 3);
	multiP->setI(TPI_FlickDamageCount2, 3);
	multiP->setI(TPI_FlickDamageCount3, 3);
	multiP->setI(TPI_FlickDamageCount4, 3);
	multiP->setI(TPI_CullingType, 1); // do not cull

	multiP->setF(TPF_Weight, 100.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 5000.0f);
	multiP->setF(TPF_WalkVelocity, 20.0f);
	multiP->setF(TPF_RunVelocity, 120.0f);
	multiP->setF(TPF_TurnVelocity, 0.9948377f);
	multiP->setF(TPF_VisibleRange, 150.0f);
	multiP->setF(TPF_VisibleAngle, 180.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 40.0f);
	multiP->setF(TPF_AttackableAngle, 30.0f);
	multiP->setF(TPF_AttackRange, 30.0f);
	multiP->setF(TPF_AttackHitRange, 9.0f);
	multiP->setF(TPF_AttackPower, 5.0f);
	multiP->setF(TPF_DangerTerritoryRange, 150.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 120.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 200.0f);
	multiP->setF(TPF_LowerFlickPower, 200.0f);
	multiP->setF(TPF_UpperAttackPower, 20.0f);
	multiP->setF(TPF_LowerAttackPower, 10.0f);
	multiP->setF(TPF_LifeRecoverRate, 0.01f);
	multiP->setF(TPF_LifeGaugeOffset, 70.0f);
	multiP->setF(TPF_ShadowSize, 50.0f);
	multiP->setF(TPF_TraceAngle, 60.0f);
	multiP->setF(TPF_SpawnDistance, 0.0f);
	multiP->setF(TPF_SpawnHeight, 20.0f);
	multiP->setF(TPF_SpawnVelocity, 0.0f);

	STACK_PAD_VAR(2);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0001D8
 */
TAIusubaStrategy::TAIusubaStrategy()
    : YaiStrategy(USUBASTATE_COUNT, USUBASTATE_Fly)
{
	TAIAdeadCheck* dead = new TAIAdeadCheck(USUBASTATE_Die);
	TAIAdying* dying    = new TAIAdying(TAI_NO_TRANSIT, TekiMotion::Dead);
	TAIAdamage* damage  = new TAIAdamage(TAI_NO_TRANSIT, false);
	TAIAstop* stop      = new TAIAstop(TAI_NO_TRANSIT);
	TAIAflyUsuba* fly   = new TAIAflyUsuba(USUBASTATE_Die, TekiMotion::Move1);

	TaiState* state = new TaiState(2);
	int j           = 0;
	state->setAction(j++, dying);
	state->setAction(j++, stop);
	setState(USUBASTATE_Die, state);

	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, dead);
	state->setAction(j++, fly);
	setState(USUBASTATE_Fly, state);
}

/**
 * @TODO: Documentation
 */
void TAIusubaAnimation::makeDefaultAnimations()
{
	if (!mAnimMgr) {
		return;
	}

	gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_KabekuiB]->mShape; // hmm.

	addAnimation("tekis/usuba/motion/dead.dca");
	addAnimation("tekis/usuba/motion/damage.dca");
	addAnimation("tekis/usuba/motion/wait1.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/usuba/motion/wait2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/usuba/motion/waitact1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/usuba/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/usuba/motion/move1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/usuba/motion/move2.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/usuba/motion/attack.dca");
	addKeyFrame(58);
	addInfoKey(1, 2);

	addAnimation("tekis/usuba/motion/type1.dck");
	addKeyFrame(8);
	addKeyFrame(43);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/usuba/motion/type2.dca");
	addKeyFrame(32);
	addInfoKey(1, 2);
}
