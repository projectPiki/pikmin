#include "CoreNucleus.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "Slime.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("CoreNucleusAi");

/**
 * @TODO: Documentation
 */
CoreNucleusAi::CoreNucleusAi(CoreNucleus* core)
{
	mCore = core;
}

/**
 * @TODO: Documentation
 */
void CoreNucleusAi::initAI(CoreNucleus* core)
{
	mCore = core;
	mCore->setCurrentState(COREAI_Follow);
	mCore->setNextState(COREAI_Follow);
	mCore->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait1, this));
	mCore->setAnimTimer(30.0f);
	mIsHit = false;
}

/**
 * @TODO: Documentation
 */
void CoreNucleusAi::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		keyAction0();
		break;
	case KEY_Action1:
		keyAction1();
		break;
	case KEY_LoopEnd:
		keyLoopEnd();
		break;
	case KEY_Finished:
		keyFinished();
		break;
	case KEY_PlaySound:
		playSound(event.mValue);
		break;
	}
}

/**
 * @TODO: Documentation
 */
void CoreNucleusAi::keyAction0()
{
}

/**
 * @TODO: Documentation
 */
void CoreNucleusAi::keyAction1()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void CoreNucleusAi::keyAction2()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void CoreNucleusAi::keyAction3()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void CoreNucleusAi::keyLoopEnd()
{
	mCore->addLoopCounter(1);
}

/**
 * @TODO: Documentation
 */
void CoreNucleusAi::keyFinished()
{
	mCore->setMotionFinish(true);
}

/**
 * @TODO: Documentation
 */
void CoreNucleusAi::playSound(int)
{
}

/**
 * @TODO: Documentation
 */
void CoreNucleusAi::setHitMotionStart()
{
	mIsHit = true;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void CoreNucleusAi::setEveryFrame()
{
	setBossPosition();
	setSlimeDamagePoint();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void CoreNucleusAi::setBossPosition()
{
	mCore->mSRT.t.x = mCore->mSlime->mCorePosition.x;
	mCore->mSRT.t.z = mCore->mSlime->mCorePosition.z;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
void CoreNucleusAi::setSlimeDamagePoint()
{
	mCore->mSlime->mSlimeAi->addDamagePoint(mCore->getDamagePoint());
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
void CoreNucleusAi::afterProcessing()
{
	mCore->setDamagePoint(0.0f);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
bool CoreNucleusAi::dieTransit()
{
	return !mCore->getAlive();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
bool CoreNucleusAi::isMotionFinishTransit()
{
	return mCore->getMotionFinish();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
bool CoreNucleusAi::damageTransit()
{
	return (mCore->getDamagePoint() > 0.0f) ? true : false;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
bool CoreNucleusAi::hitMotionStartTransit()
{
	return mIsHit;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000D8
 */
void CoreNucleusAi::initDie(int val)
{
	mCore->setNextState(val);
	mCore->setMotionFinish(false);
	mCore->setLoopCounter(0);
	mCore->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Damage, this));
	mCore->setAttackTimer(0.0f);
	effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeL, mCore->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Teki_DeathGlowL, mCore->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Teki_DeathWaveL, mCore->mSRT.t, nullptr, nullptr);
	mCore->doKill();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000064
 */
void CoreNucleusAi::initDamage(int val)
{
	mCore->setNextState(val);
	mCore->setMotionFinish(false);
	mCore->setLoopCounter(0);
	mCore->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Damage, this));
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000068
 */
void CoreNucleusAi::initFollow(int val)
{
	mCore->setNextState(val);
	mCore->setMotionFinish(false);
	mCore->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait1, this));
	mIsHit = 0;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000CC
 */
void CoreNucleusAi::initHit(int val)
{
	mCore->setNextState(val);
	mCore->setMotionFinish(false);
	mCore->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Type1, this));
	Vector3f ptclPos(sinf(mCore->mFaceDirection), 0.0f, cosf(mCore->mFaceDirection));
	zen::particleGenerator* ptcl = effectMgr->create(EffectMgr::EFF_Kogane_Hit, mCore->mSRT.t, nullptr, nullptr);
	if (ptcl) {
		ptcl->setEmitDir(ptclPos);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void CoreNucleusAi::dieState()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void CoreNucleusAi::damageState()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void CoreNucleusAi::followState()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void CoreNucleusAi::hitState()
{
}

/**
 * @TODO: Documentation
 */
void CoreNucleusAi::update()
{
	setEveryFrame();
	switch (mCore->getCurrentState()) {
	case COREAI_Die:
		dieState();
		break;

	case COREAI_Damage:
		damageState();
		if (dieTransit()) {
			initDie(COREAI_Die);
		} else if (mIsHit) {
			initHit(COREAI_Hit);
		} else if (isMotionFinishTransit()) {
			initFollow(COREAI_Follow);
		}
		break;

	case COREAI_Follow:
		followState();
		if (dieTransit()) {
			initDie(COREAI_Die);
		} else if (hitMotionStartTransit()) {
			initHit(COREAI_Hit);
		} else if (damageTransit()) {
			initDamage(COREAI_Damage);
		}
		break;

	case COREAI_Hit:
		hitState();
		if (dieTransit()) {
			initDie(COREAI_Die);
		} else if (isMotionFinishTransit()) {
			initFollow(COREAI_Follow);
		}
		break;
	}

	afterProcessing();
}
