#include "DebugLog.h"
#include "EffectMgr.h"
#include "Nucleus.h"
#include "Slime.h"

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
DEFINE_PRINT("NucleusAi");

/*
 * --INFO--
 * Address:	8017A544
 * Size:	000020
 */
NucleusAi::NucleusAi(Nucleus* nucleus)
{
	mNucleus = nucleus;
}

/*
 * --INFO--
 * Address:	8017A564
 * Size:	000074
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

/*
 * --INFO--
 * Address:	8017A5D8
 * Size:	00007C
 */
void NucleusAi::animationKeyUpdated(PaniAnimKeyEvent& event)
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

/*
 * --INFO--
 * Address:	8017A654
 * Size:	000004
 */
void NucleusAi::keyAction0()
{
}

/*
 * --INFO--
 * Address:	8017A658
 * Size:	000004
 */
void NucleusAi::keyAction1()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::keyAction2()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::keyAction3()
{
}

/*
 * --INFO--
 * Address:	8017A65C
 * Size:	000014
 */
void NucleusAi::keyLoopEnd()
{
	mNucleus->addLoopCounter(1);
}

/*
 * --INFO--
 * Address:	8017A670
 * Size:	000010
 */
void NucleusAi::keyFinished()
{
	mNucleus->setMotionFinish(true);
}

/*
 * --INFO--
 * Address:	8017A680
 * Size:	000004
 */
void NucleusAi::playSound(int)
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void NucleusAi::setEveryFrame()
{
	mStickPikiCount = mNucleus->getStickPikiCount();
	setBossPosition();
	setSlimeDamagePoint();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NucleusAi::setBossPosition()
{
	mNucleus->mSRT.t.x = mNucleus->mSlime->mNucleusPosition.x;
	mNucleus->mSRT.t.z = mNucleus->mSlime->mNucleusPosition.z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NucleusAi::setSlimeDamagePoint()
{
	mNucleus->mSlime->mSlimeAi->addDamagePoint(mNucleus->getDamagePoint());
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void NucleusAi::afterProcessing()
{
	mNucleus->setDamagePoint(0.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool NucleusAi::dieTransit()
{
	return !mNucleus->getAlive();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
bool NucleusAi::isMotionFinishTransit()
{
	return mNucleus->getMotionFinish();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool NucleusAi::damageTransit()
{
	return (mNucleus->getDamagePoint() > 0.0f) ? true : false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
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

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void NucleusAi::initDamage(int val)
{
	mNucleus->setNextState(val);
	mNucleus->setMotionFinish(false);
	mNucleus->setLoopCounter(0);
	mNucleus->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Damage, this));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void NucleusAi::initFollow(int val)
{
	mNucleus->setNextState(val);
	mNucleus->setMotionFinish(false);
	mNucleus->setLoopCounter(0);
	mNucleus->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait1, this));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::dieState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::damageState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::followState()
{
}

/*
 * --INFO--
 * Address:	8017A684
 * Size:	0002D0
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
