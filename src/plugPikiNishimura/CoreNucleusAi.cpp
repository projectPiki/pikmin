#include "CoreNucleus.h"
#include "Slime.h"
#include "EffectMgr.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("CoreNucleusAi");

/*
 * --INFO--
 * Address:	8017AD44
 * Size:	000020
 */
CoreNucleusAi::CoreNucleusAi(CoreNucleus* core)
{
	mCore = core;
}

/*
 * --INFO--
 * Address:	8017AD64
 * Size:	000074
 */
void CoreNucleusAi::initAI(CoreNucleus* core)
{
	mCore = core;
	mCore->setCurrentState(COREAI_Follow);
	mCore->setNextState(COREAI_Follow);
	mCore->mAnimator.startMotion(PaniMotionInfo(2, this));
	mCore->setAnimTimer(30.0f);
	mIsHit = false;
}

/*
 * --INFO--
 * Address:	8017ADD8
 * Size:	00007C
 */
void CoreNucleusAi::animationKeyUpdated(PaniAnimKeyEvent& event)
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
 * Address:	8017AE54
 * Size:	000004
 */
void CoreNucleusAi::keyAction0()
{
}

/*
 * --INFO--
 * Address:	8017AE58
 * Size:	000004
 */
void CoreNucleusAi::keyAction1()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CoreNucleusAi::keyAction2()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CoreNucleusAi::keyAction3()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017AE5C
 * Size:	000014
 */
void CoreNucleusAi::keyLoopEnd()
{
	mCore->addLoopCounter(1);
}

/*
 * --INFO--
 * Address:	8017AE70
 * Size:	000010
 */
void CoreNucleusAi::keyFinished()
{
	mCore->setMotionFinish(true);
}

/*
 * --INFO--
 * Address:	8017AE80
 * Size:	000004
 */
void CoreNucleusAi::playSound(int)
{
}

/*
 * --INFO--
 * Address:	8017AE84
 * Size:	00000C
 */
void CoreNucleusAi::setHitMotionStart()
{
	mIsHit = true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void CoreNucleusAi::setEveryFrame()
{
	setBossPosition();
	setSlimeDamagePoint();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void CoreNucleusAi::setBossPosition()
{
	mCore->mPosition.x = mCore->mSlime->mCorePosition.x;
	mCore->mPosition.z = mCore->mSlime->mCorePosition.z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void CoreNucleusAi::setSlimeDamagePoint()
{
	mCore->mSlime->mSlimeAi->addDamagePoint(mCore->getDamagePoint());
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void CoreNucleusAi::afterProcessing()
{
	mCore->setDamagePoint(0.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool CoreNucleusAi::dieTransit()
{
	return !mCore->getAlive();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
bool CoreNucleusAi::isMotionFinishTransit()
{
	return mCore->getMotionFinish();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool CoreNucleusAi::damageTransit()
{
	return (mCore->getDamagePoint() > 0.0f) ? true : false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
bool CoreNucleusAi::hitMotionStartTransit()
{
	return mIsHit;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void CoreNucleusAi::initDie(int val)
{
	mCore->setNextState(val);
	mCore->setMotionFinish(false);
	mCore->setLoopCounter(0);
	mCore->mAnimator.startMotion(PaniMotionInfo(1, this));
	mCore->setAttackTimer(0.0f);
	effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeL, mCore->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Teki_DeathGlowL, mCore->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Teki_DeathWaveL, mCore->mPosition, nullptr, nullptr);
	mCore->doKill();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void CoreNucleusAi::initDamage(int val)
{
	mCore->setNextState(val);
	mCore->setMotionFinish(false);
	mCore->setLoopCounter(0);
	mCore->mAnimator.startMotion(PaniMotionInfo(1, this));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void CoreNucleusAi::initFollow(int val)
{
	mCore->setNextState(val);
	mCore->setMotionFinish(false);
	mCore->mAnimator.startMotion(PaniMotionInfo(2, this));
	mIsHit = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void CoreNucleusAi::initHit(int val)
{
	mCore->setNextState(val);
	mCore->setMotionFinish(false);
	mCore->mAnimator.startMotion(PaniMotionInfo(10, this));
	Vector3f ptclPos(sinf(mCore->mDirection), 0.0f, cosf(mCore->mDirection));
	zen::particleGenerator* ptcl = effectMgr->create(EffectMgr::EFF_Kogane_Hit, mCore->mPosition, nullptr, nullptr);
	if (ptcl) {
		ptcl->setEmitDir(ptclPos);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CoreNucleusAi::dieState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CoreNucleusAi::damageState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CoreNucleusAi::followState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CoreNucleusAi::hitState()
{
}

/*
 * --INFO--
 * Address:	8017AE90
 * Size:	000544
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
