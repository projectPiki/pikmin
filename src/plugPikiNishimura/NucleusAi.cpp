#include "Nucleus.h"
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
DEFINE_PRINT("NucleusAi");

/*
 * --INFO--
 * Address:	8017A544
 * Size:	000020
 */
NucleusAi::NucleusAi(Nucleus* nucleus) { mNucleus = nucleus; }

/*
 * --INFO--
 * Address:	8017A564
 * Size:	000074
 */
void NucleusAi::initAI(Nucleus* nucleus)
{
	mNucleus = nucleus;
	mNucleus->setCurrentState(2);
	mNucleus->setNextState(2);
	mNucleus->mAnimator.startMotion(PaniMotionInfo(2, this));
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
void NucleusAi::keyAction0() { }

/*
 * --INFO--
 * Address:	8017A658
 * Size:	000004
 */
void NucleusAi::keyAction1() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::keyAction2() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::keyAction3() { }

/*
 * --INFO--
 * Address:	8017A65C
 * Size:	000014
 */
void NucleusAi::keyLoopEnd() { mNucleus->addLoopCounter(1); }

/*
 * --INFO--
 * Address:	8017A670
 * Size:	000010
 */
void NucleusAi::keyFinished() { mNucleus->setMotionFinish(1); }

/*
 * --INFO--
 * Address:	8017A680
 * Size:	000004
 */
void NucleusAi::playSound(int) { }

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
	mNucleus->mPosition.x = mNucleus->mSlime->_3DC.x;
	mNucleus->mPosition.z = mNucleus->mSlime->_3DC.z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NucleusAi::setSlimeDamagePoint() { mNucleus->mSlime->mSlimeAi->addDamagePoint(mNucleus->getDamagePoint()); }

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void NucleusAi::afterProcessing() { mNucleus->setDamagePoint(0.0f); }

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool NucleusAi::dieTransit() { return !mNucleus->getAlive(); }

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
bool NucleusAi::isMotionFinishTransit() { return mNucleus->getMotionFinish(); }

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool NucleusAi::damageTransit() { return (mNucleus->getDamagePoint() > 0.0f) ? true : false; }

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void NucleusAi::initDie(int val)
{
	mNucleus->setNextState(val);
	mNucleus->setMotionFinish(0);
	mNucleus->setLoopCounter(0);
	mNucleus->mAnimator.startMotion(PaniMotionInfo(1, this));
	mNucleus->set2D4(0.0f);
	effectMgr->create(EffectMgr::EFF_Unk57, mNucleus->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Unk56, mNucleus->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Unk55, mNucleus->mPosition, nullptr, nullptr);
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
	mNucleus->setMotionFinish(0);
	mNucleus->setLoopCounter(0);
	mNucleus->mAnimator.startMotion(PaniMotionInfo(1, this));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void NucleusAi::initFollow(int val)
{
	mNucleus->setNextState(val);
	mNucleus->setMotionFinish(0);
	mNucleus->setLoopCounter(0);
	mNucleus->mAnimator.startMotion(PaniMotionInfo(2, this));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::dieState() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::damageState() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::followState() { }

/*
 * --INFO--
 * Address:	8017A684
 * Size:	0002D0
 */
void NucleusAi::update()
{
	setEveryFrame();

	switch (mNucleus->getCurrentState()) {
	case 0: // dead?
		dieState();
		break;
	case 1: // damaged?
		damageState();
		if (dieTransit()) {
			initDie(0);
		} else if (isMotionFinishTransit()) {
			initFollow(2);
		}
		break;
	case 2: // following?
		followState();
		if (dieTransit()) {
			initDie(0);
		} else if (damageTransit()) {
			initDamage(1);
		}
		break;
	}

	afterProcessing();
}
