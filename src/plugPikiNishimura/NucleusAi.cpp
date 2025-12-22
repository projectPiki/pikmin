#include "DebugLog.h"
#include "EffectMgr.h"
#include "Nucleus.h"
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
DEFINE_PRINT("NucleusAi");

/**
 * @TODO: Documentation
 */
NucleusAi::NucleusAi(Nucleus* nucleus)
{
	mNucleus = nucleus;
}

/**
 * @TODO: Documentation
 */
void NucleusAi::initAI(Nucleus* nucleus)
{
	mNucleus = nucleus;
	mNucleus->setCurrentState(NUCLEUSAI_Follow);
	mNucleus->setNextState(NUCLEUSAI_Follow);
	mNucleus->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait1, this));
	mNucleus->setAnimTimer(30.0f);
	mStickPikiCount = 0;
}

/**
 * @TODO: Documentation
 */
void NucleusAi::animationKeyUpdated(immut PaniAnimKeyEvent& event)
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
void NucleusAi::keyAction0()
{
}

/**
 * @TODO: Documentation
 */
void NucleusAi::keyAction1()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void NucleusAi::keyAction2()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void NucleusAi::keyAction3()
{
}

/**
 * @TODO: Documentation
 */
void NucleusAi::keyLoopEnd()
{
	mNucleus->addLoopCounter(1);
}

/**
 * @TODO: Documentation
 */
void NucleusAi::keyFinished()
{
	mNucleus->setMotionFinish(true);
}

/**
 * @TODO: Documentation
 */
void NucleusAi::playSound(int)
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
void NucleusAi::setEveryFrame()
{
	mStickPikiCount = mNucleus->getStickPikiCount();
	setBossPosition();
	setSlimeDamagePoint();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void NucleusAi::setBossPosition()
{
	mNucleus->mSRT.t.x = mNucleus->mSlime->mNucleusPosition.x;
	mNucleus->mSRT.t.z = mNucleus->mSlime->mNucleusPosition.z;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
void NucleusAi::setSlimeDamagePoint()
{
	mNucleus->mSlime->mSlimeAi->addDamagePoint(mNucleus->getDamagePoint());
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
void NucleusAi::afterProcessing()
{
	mNucleus->setDamagePoint(0.0f);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
bool NucleusAi::dieTransit()
{
	return !mNucleus->getAlive();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
bool NucleusAi::isMotionFinishTransit()
{
	return mNucleus->getMotionFinish();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
bool NucleusAi::damageTransit()
{
	return (mNucleus->getDamagePoint() > 0.0f) ? true : false;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000D8
 */
void NucleusAi::initDie(int val)
{
	mNucleus->setNextState(val);
	mNucleus->setMotionFinish(false);
	mNucleus->setLoopCounter(0);
	mNucleus->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Damage, this));
	mNucleus->setAttackTimer(0.0f);
	effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeL, mNucleus->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Teki_DeathGlowL, mNucleus->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Teki_DeathWaveL, mNucleus->mSRT.t, nullptr, nullptr);
	mNucleus->doKill();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000064
 */
void NucleusAi::initDamage(int val)
{
	mNucleus->setNextState(val);
	mNucleus->setMotionFinish(false);
	mNucleus->setLoopCounter(0);
	mNucleus->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Damage, this));
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000064
 */
void NucleusAi::initFollow(int val)
{
	mNucleus->setNextState(val);
	mNucleus->setMotionFinish(false);
	mNucleus->setLoopCounter(0);
	mNucleus->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait1, this));
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void NucleusAi::dieState()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void NucleusAi::damageState()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void NucleusAi::followState()
{
}

/**
 * @TODO: Documentation
 */
void NucleusAi::update()
{
	setEveryFrame();

	switch (mNucleus->getCurrentState()) {
	case NUCLEUSAI_Die:
		dieState();
		break;

	case NUCLEUSAI_Damage:
		damageState();
		if (dieTransit()) {
			initDie(NUCLEUSAI_Die);
		} else if (isMotionFinishTransit()) {
			initFollow(NUCLEUSAI_Follow);
		}
		break;

	case NUCLEUSAI_Follow:
		followState();
		if (dieTransit()) {
			initDie(NUCLEUSAI_Die);
		} else if (damageTransit()) {
			initDamage(NUCLEUSAI_Damage);
		}
		break;
	}

	afterProcessing();
}
