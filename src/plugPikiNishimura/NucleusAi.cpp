#include "DebugLog.h"
#include "EffectMgr.h"
#include "Nucleus.h"
#include "Slime.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("NucleusAi");

/**
 * @todo: Documentation
 */
NucleusAi::NucleusAi(Nucleus* nucleus)
{
	mNucleus = nucleus;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
 */
void NucleusAi::keyAction0()
{
}

/**
 * @todo: Documentation
 */
void NucleusAi::keyAction1()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void NucleusAi::keyAction2()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void NucleusAi::keyAction3()
{
}

/**
 * @todo: Documentation
 */
void NucleusAi::keyLoopEnd()
{
	mNucleus->addLoopCounter(1);
}

/**
 * @todo: Documentation
 */
void NucleusAi::keyFinished()
{
	mNucleus->setMotionFinish(true);
}

/**
 * @todo: Documentation
 */
void NucleusAi::playSound(int)
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044
 */
void NucleusAi::setEveryFrame()
{
	mStickPikiCount = mNucleus->getStickPikiCount();
	setBossPosition();
	setSlimeDamagePoint();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void NucleusAi::setBossPosition()
{
	mNucleus->mSRT.t.x = mNucleus->mSlime->mNucleusPosition.x;
	mNucleus->mSRT.t.z = mNucleus->mSlime->mNucleusPosition.z;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030
 */
void NucleusAi::setSlimeDamagePoint()
{
	mNucleus->mSlime->mSlimeAi->addDamagePoint(mNucleus->getDamagePoint());
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000010
 */
void NucleusAi::afterProcessing()
{
	mNucleus->setDamagePoint(0.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
bool NucleusAi::dieTransit()
{
	return !mNucleus->getAlive();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00000C
 */
bool NucleusAi::isMotionFinishTransit()
{
	return mNucleus->getMotionFinish();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
bool NucleusAi::damageTransit()
{
	return (mNucleus->getDamagePoint() > 0.0f) ? true : false;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void NucleusAi::dieState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void NucleusAi::damageState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void NucleusAi::followState()
{
}

/**
 * @todo: Documentation
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
