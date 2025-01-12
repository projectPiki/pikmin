#include "Spider.h"
#include "RumbleMgr.h"
#include "Pcam/CameraManager.h"
#include "SoundMgr.h"
#include "ItemMgr.h"
#include "NaviMgr.h"
#include "PikiMgr.h"
#include "PikiHeadItem.h"
#include "GameStat.h"
#include "EffectMgr.h"
#include "PlayerState.h"
#include "NsMath.h"
#include "DebugLog.h"

static u32 spiderSE[] = { SE_SPIDER_WALK, SE_SPIDER_LAND, SE_SPIDER_SWING, SE_SPIDER_DEAD, SE_SPIDER_BOMB };

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
DEFINE_PRINT("SpiderAi");

/*
 * --INFO--
 * Address:	80153840
 * Size:	000020
 */
SpiderAi::SpiderAi(Spider* spider)
{
	mSpider = spider;
}

/*
 * --INFO--
 * Address:	80153860
 * Size:	0000A8
 */
void SpiderAi::initAI(Spider* spider)
{
	mSpider = spider;
	mSpider->setCurrentState(7);
	mSpider->setNextState(7);
	mSpider->mAnimator.startMotion(PaniMotionInfo(3, this));
	_08 = false;
	if (C_SPIDER_PROP(mSpider).mDoDropFromSky()) {
		// drop from sky, so don't fall yet
		mSpider->mIsAppear = false;
	} else {
		// start in place, so mark as fallen
		mSpider->mIsAppear = true;
		mSpider->setAnimTimer(C_SPIDER_PROP(mSpider).mDropTimer());
		mSpider->mAnimator.setCounter(20.0f);
	}
}

/*
 * --INFO--
 * Address:	80153908
 * Size:	00007C
 */
void SpiderAi::animationKeyUpdated(PaniAnimKeyEvent& event)
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
 * Address:	80153984
 * Size:	0000A8
 */
void SpiderAi::keyAction0()
{
	int currState = mSpider->getCurrentState();
	if (currState == SPIDERAI_Die) {
		mSpider->setIsAlive(false);
		CollPart* body           = mSpider->mCollInfo->getSphere('tama');
		body->mCollInfo->mRadius = 0.0f;
		mSpider->createPellet(body->mCentre, 200.0f, true);
		return;
	}

	if (currState == SPIDERAI_Appear) {
		rumbleMgr->start(5, 0, mSpider->mPosition);
		cameraMgr->startVibrationEvent(2, mSpider->mPosition);
	}
}

/*
 * --INFO--
 * Address:	80153A2C
 * Size:	000020
 */
void SpiderAi::keyAction1()
{
	if (mSpider->getCurrentState() == SPIDERAI_Appear) {
		mSpider->mSpiderLeg->_05 = 0;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SpiderAi::keyAction2()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SpiderAi::keyAction3()
{
}

/*
 * --INFO--
 * Address:	80153A4C
 * Size:	000014
 */
void SpiderAi::keyLoopEnd()
{
	mSpider->addLoopCounter(1);
}

/*
 * --INFO--
 * Address:	80153A60
 * Size:	000010
 */
void SpiderAi::keyFinished()
{
	mSpider->setMotionFinish(true);
}

/*
 * --INFO--
 * Address:	80153A70
 * Size:	000044
 */
void SpiderAi::playSound(int spiderSoundID)
{
	if (mSpider->mSeContext) {
		mSpider->mSeContext->playSound(spiderSE[spiderSoundID]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void SpiderAi::setEveryFrame()
{
	if (mSpider->getDamagePoint() > 0.0f) {
		mSpider->calcBossDamage();
	}

	checkFlickPiki();
	checkHalfDead();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void SpiderAi::checkFlickPiki()
{
	if (!_08 && mSpider->getAlive()) {
		_08 = mSpider->flickPikiTransit();
	}

	if (_08) {
		mSpider->addLoopCounter(1);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void SpiderAi::checkHalfDead()
{
	if (mSpider->getCurrentLife() < 0.35f * mSpider->getMaxLife()) {
		if (!mSpider->_3BA) {
			mSpider->_3BA = 1;
			mSpider->mSpiderLeg->createHalfDeadEffect();
		}
	} else {
		mSpider->_3BA = 0;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void SpiderAi::resultFlagOn()
{
	if (mSpider->insideAndInSearch()) {
		playerState->mResultFlags.setOn(RESFLAG_Unk46);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void SpiderAi::resultFlagSeen()
{
	playerState->mResultFlags.setSeen(RESFLAG_Unk46);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool SpiderAi::dieTransit()
{
	return !mSpider->getAlive();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
bool SpiderAi::isMotionFinishTransit()
{
	return mSpider->getMotionFinish();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool SpiderAi::outSideChaseRangeTransit()
{
	return mSpider->outSideChaseRangeTransit();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool SpiderAi::inSideWaitRangeTransit()
{
	return mSpider->inSideWaitRangeTransit();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool SpiderAi::chaseNaviTransit()
{
	return mSpider->chaseNaviTransit();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool SpiderAi::chasePikiTransit()
{
	return mSpider->chasePikiTransit();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
bool SpiderAi::shakeOffTransit()
{
	return mSpider->getMotionFinish() && _08;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool SpiderAi::targetLostTransit()
{
	return mSpider->targetLostTransit();
}

/*
 * --INFO--
 * Address:	80153AB4
 * Size:	0002FC
 */
bool SpiderAi::appearTransit()
{
	// if beady hasn't appeared yet, see if we should trigger him
	if (!mSpider->mIsAppear) {

		// grab his spawn position
		Vector3f* initPos = mSpider->getInitPosition();

		// loop through all captains on the field (just 1 in reality)
		Iterator iterNavi(naviMgr);
		CI_LOOP(iterNavi)
		{
			Creature* navi = *iterNavi;

			// if navi is alive, visible, not buried, and
			// within the trigger radius (only 2D, and roughly),
			// make beady drop + start the music
			if (navi->isAlive() && navi->isVisible() && !navi->isBuried()
			    && qdist2(initPos->x, initPos->z, navi->mPosition.x, navi->mPosition.z) < C_SPIDER_PROP(mSpider).mSpawnTriggerDist()) {
				mSpider->mIsAppear  = true;
				mSpider->mIsBossBgm = true;

				// check if we should get the easy-mode long fall timer
				Iterator iterPikiHead(itemMgr->getPikiHeadMgr());
				CI_LOOP(iterPikiHead)
				{
					// ARE YOU KIDDING ME - IT WAS A TYPO ALL ALONG
					// THIS SHOULD BE *iterPikiHead BUT NO, THEY USED THE WRONG ITERATOR
					// THIS LOOP ONLY RUNS AT ALL IF THERE'S A NON-NULL PIKIHEAD INDEX
					// SO YOU NEED A SPROUT.
					// BUT THE DISTANCE CHECK IS AGAINST THE CAPTAIN BY MISTAKE
					Creature* sproutButActuallyNavi = *iterNavi; // TYPO.

					// if sprout (!!NAVI!!) is within trigger radius, make beady fall slower.
					// because of the typo, if this loop runs, this is always true.
					if (sproutButActuallyNavi
					    && qdist2(initPos->x, initPos->z, sproutButActuallyNavi->mPosition.x, sproutButActuallyNavi->mPosition.z)
					           < C_SPIDER_PROP(mSpider).mSpawnTriggerDist()) {
						// change fall time from 0.05s to 5s
						C_SPIDER_PROP(mSpider).mDropTimer() = 5.0f;
						break;
					}
				}
				break;
			}
		}
	}

	// if we're falling, inc the anim timer
	if (mSpider->mIsAppear) {
		mSpider->addAnimTimer(gsys->getFrameTime());

		// if we've fallen for the allocated time (fast or slow), say we're on the ground
		if (mSpider->getAnimTimer() > C_SPIDER_PROP(mSpider).mDropTimer()) {
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void SpiderAi::initDie(int nextState)
{
	mSpider->setNextState(nextState);
	mSpider->setMotionFinish(true);
	mSpider->setTargetCreature(nullptr);
	mSpider->mAnimator.startMotion(PaniMotionInfo(0, this));
	mSpider->set2D4(0.0f);
	mSpider->mSpiderLeg->_07 = 1;
	resultFlagSeen();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void SpiderAi::initWalk(int nextState)
{
	mSpider->setNextState(nextState);
	if (mSpider->getMotionFinish()) {
		mSpider->setMotionFinish(false);
		mSpider->setTargetCreature(nullptr);
		mSpider->_3BC
		    = C_SPIDER_PROP(mSpider).mMinWalkCycles()
		    + NsMathI::getRand(NsLibMath<int>::abs(C_SPIDER_PROP(mSpider).mMaxWalkCycles() - C_SPIDER_PROP(mSpider).mMinWalkCycles()) + 1)
		    - 1;
		mSpider->mSpiderLeg->initParm(0);
		mSpider->setLoopCounter(0);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void SpiderAi::initShakeOff(int nextState)
{
	mSpider->setNextState(nextState);
	mSpider->setMotionFinish(false);
	mSpider->setTargetCreature(nullptr);
	mSpider->mSpiderLeg->initParm(NsMathI::getRand(2) + 1);
	mSpider->setLoopCounter(0);
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void SpiderAi::initAppear(int nextState)
{
	mSpider->setNextState(nextState);
	mSpider->setMotionFinish(false);
	mSpider->mIsBossBgm = true;
	mSpider->setInvincible(false);
	mSpider->setIsOrganic(true);
	mSpider->setAnimTimer(30.0f);
	mSpider->mRotation.y += NsMathF::getRand(PI) - HALF_PI;
	mSpider->mDirection = mSpider->mRotation.y;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void SpiderAi::initWait(int nextState)
{
	mSpider->setNextState(nextState);
	mSpider->_3BC
	    = C_SPIDER_PROP(mSpider).mMinWaitCycles()
	    + NsMathI::getRand(NsLibMath<int>::abs(C_SPIDER_PROP(mSpider).mMaxWaitCycles() - C_SPIDER_PROP(mSpider).mMinWaitCycles()) + 1) - 1;
	mSpider->setLoopCounter(0);
	mSpider->setMotionFinish(false);
	mSpider->setTargetCreature(nullptr);
	mSpider->mAnimator.startMotion(PaniMotionInfo(2, this));
}

/*
 * --INFO--
 * Address:	80153DB0
 * Size:	000260
 */
void SpiderAi::dieState()
{
	f32 timings[4];
	f32 timer = mSpider->get2D4();
	for (int i = 0; i < 4; i++) {
		timings[i] = C_SPIDER_PROP(mSpider).mDeadScaleStartDelay() + i * C_SPIDER_PROP(mSpider).mDeadScaleStageDelay();
	}

	if (timer < timings[3] && NsMathF::getRand(1.0f) < 0.2f) {
		mSpider->mSpiderLeg->createSmallSparkEffect(1);
	}

	if (timer > C_SPIDER_PROP(mSpider).mDeadBombEffectDelay() && mSpider->_3BB) {
		mSpider->mSpiderLeg->createDeadBombEffect();
		mSpider->_3BB = 0;
	}

	if (timer > timings[0]) {
		if (mSpider->_3B9) {
			mSpider->mSpiderLeg->createPerishEffect();
			mSpider->_3B9 = 0;
			mSpider->setIsAtari(false);
		}

		if (timer > C_SPIDER_PROP(mSpider).mDeadMotionDelay() + timings[3] + 0.5f) {
			mSpider->setMotionFinish(false);
		}
	}

	if (C_SPIDER_PROP(mSpider).mDoFinalKillEffects()) {
		for (int i = 0; i < 4; i++) {
			if (timer > timings[i]) {
				mSpider->mSpiderLeg->setLegScaleParam(i);
			}
		}
		if (timer > C_SPIDER_PROP(mSpider).mDeadMotionDelay() + timings[3] + 1.5f) {
			GameStat::killTekis.inc();
			mSpider->doKill();
		}
	}

	mSpider->add2D4(gsys->getFrameTime());
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void SpiderAi::walkRandomState()
{
	mSpider->makeTargetRandom(30.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void SpiderAi::walkGoHomeState()
{
	Vector3f* initPos = mSpider->getInitPosition();
	mSpider->setTargetPosition(*initPos);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderAi::chaseNaviState()
{
	mSpider->makeTargetCreature();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderAi::chasePikiState()
{
	mSpider->makeTargetCreature();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderAi::shakeOffState()
{
	mSpider->makeTargetCreature();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void SpiderAi::waitState()
{
	if (mSpider->getLoopCounter() >= mSpider->_3BC) {
		mSpider->mAnimator.finishMotion(PaniMotionInfo(-1, this));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void SpiderAi::appearState()
{
	if (!mSpider->mHasShadow) {
		if (mSpider->mCollInfo->getBoundingSphere()->mCentre.y < mSpider->mPosition.y + 1200.0f) {
			mSpider->mHasShadow = true;
			mapMgr->mShadowCaster.add(&mSpider->mShadowCaster);
		}
	}
}

/*
 * --INFO--
 * Address:	80154010
 * Size:	0019F8
 */
void SpiderAi::update()
{
	setEveryFrame();
	switch (mSpider->getCurrentState()) {
	case SPIDERAI_Die:
		dieState();
		break;

	case SPIDERAI_WalkRandom:
		walkRandomState();
		if (dieTransit()) {
			initDie(SPIDERAI_Die);
		} else if (shakeOffTransit()) {
			initShakeOff(SPIDERAI_ShakeOff);
		} else if (isMotionFinishTransit()) {
			initWait(SPIDERAI_Wait);
		} else if (chaseNaviTransit()) {
			initWalk(SPIDERAI_ChaseNavi);
		} else if (chasePikiTransit()) {
			initWalk(SPIDERAI_ChasePiki);
		}
		break;

	case SPIDERAI_ChaseNavi:
		chaseNaviState();
		if (dieTransit()) {
			initDie(SPIDERAI_Die);
		} else if (shakeOffTransit()) {
			initShakeOff(SPIDERAI_ShakeOff);
		} else if (isMotionFinishTransit()) {
			initWait(SPIDERAI_Wait);
		} else if (outSideChaseRangeTransit()) {
			initWalk(SPIDERAI_WalkGoHome);
		} else if (targetLostTransit()) {
			initWalk(SPIDERAI_WalkRandom);
		} else if (chasePikiTransit()) {
			initWalk(SPIDERAI_ChasePiki);
		}
		break;

	case SPIDERAI_ChasePiki:
		chasePikiState();
		if (dieTransit()) {
			initDie(SPIDERAI_Die);
		} else if (shakeOffTransit()) {
			initShakeOff(SPIDERAI_ShakeOff);
		} else if (isMotionFinishTransit()) {
			initWait(SPIDERAI_Wait);
		} else if (outSideChaseRangeTransit()) {
			initWalk(SPIDERAI_WalkGoHome);
		} else if (targetLostTransit()) {
			initWalk(SPIDERAI_WalkRandom);
		} else if (chaseNaviTransit()) {
			initWalk(SPIDERAI_ChaseNavi);
		} else if (chasePikiTransit()) {
			initWalk(SPIDERAI_ChasePiki);
		}
		break;

	case SPIDERAI_WalkGoHome:
		walkGoHomeState();
		if (dieTransit()) {
			initDie(SPIDERAI_Die);
		} else if (shakeOffTransit()) {
			initShakeOff(SPIDERAI_ShakeOff);
		} else if (isMotionFinishTransit()) {
			initWait(SPIDERAI_Wait);
		} else if (inSideWaitRangeTransit()) {
			initWalk(SPIDERAI_WalkRandom);
		}
		break;

	case SPIDERAI_ShakeOff:
		shakeOffState();
		if (isMotionFinishTransit()) {
			if (dieTransit()) {
				initDie(SPIDERAI_Die);
			} else {
				initWalk(SPIDERAI_WalkRandom);
			}
		}
		break;

	case SPIDERAI_Start:
		if (appearTransit()) {
			initAppear(SPIDERAI_Appear);
		}
		break;

	case SPIDERAI_Appear:
		appearState();
		if (dieTransit()) {
			initDie(SPIDERAI_Die);
		} else if (isMotionFinishTransit()) {
			initWalk(SPIDERAI_WalkRandom);
		}
		break;

	case SPIDERAI_Wait:
		waitState();
		if (dieTransit()) {
			initDie(SPIDERAI_Die);
		} else if (shakeOffTransit()) {
			initShakeOff(SPIDERAI_ShakeOff);
		} else if (isMotionFinishTransit()) {
			initWalk(SPIDERAI_WalkRandom);
		}
		break;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x6E8(r1)
	  stw       r31, 0x6E4(r1)
	  mr        r31, r3
	  stw       r30, 0x6E0(r1)
	  lwz       r3, 0x4(r3)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x30
	  bl        -0x5AF4

	.loc_0x30:
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x58
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x58
	  bl        -0x50CC
	  stb       r3, 0x8(r31)

	.loc_0x58:
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x74
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x2EC(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2EC(r4)

	.loc_0x74:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56D4(r2)
	  lfs       f2, 0x2C8(r3)
	  lfs       f1, 0x2C4(r3)
	  fmuls     f0, f0, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB4
	  lbzu      r0, 0x3BA(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xBC
	  li        r0, 0x1
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x1CAC
	  b         .loc_0xBC

	.loc_0xB4:
	  li        r0, 0
	  stb       r0, 0x3BA(r3)

	.loc_0xBC:
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x2E4(r3)
	  cmplwi    r0, 0x8
	  bgt-      .loc_0x19E0
	  lis       r4, 0x802D
	  subi      r4, r4, 0xB38
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r4, r0
	  mtctr     r0
	  bctr
	  mr        r3, r31
	  bl        -0x348
	  b         .loc_0x19E0
	  lfs       f1, -0x56B4(r2)
	  bl        -0x5B3C
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x17C
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x6B8
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x351C0
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x34F9C
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD0734
	  b         .loc_0x19E0

	.loc_0x17C:
	  lbz       r5, 0x2BD(r3)
	  li        r4, 0
	  cmplwi    r5, 0
	  beq-      .loc_0x19C
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x19C
	  li        r4, 0x1

	.loc_0x19C:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x240
	  li        r0, 0x5
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  lwz       r3, 0x4(r31)
	  stb       r30, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x318(r3)
	  bl        0xC3EA0
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x6DC(r1)
	  lis       r0, 0x4330
	  lfd       f3, -0x56C0(r2)
	  stw       r0, 0x6D8(r1)
	  lfs       f2, -0x56C8(r2)
	  lfd       f0, 0x6D8(r1)
	  lfs       f1, -0x56CC(r2)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x56B8(r2)
	  lwz       r3, 0x3C4(r3)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x6D0(r1)
	  lwz       r4, 0x6D4(r1)
	  addi      r4, r4, 0x1
	  bl        0x2C08
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x4E70
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2E
	  addi      r3, r3, 0x70
	  bl        -0xD0848
	  b         .loc_0x19E0

	.loc_0x240:
	  cmplwi    r5, 0
	  beq-      .loc_0x330
	  li        r0, 0x6
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x500
	  lwz       r0, 0x510(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x270
	  b         .loc_0x274

	.loc_0x270:
	  neg       r30, r30

	.loc_0x274:
	  bl        0xC3DEC
	  xoris     r0, r3, 0x8000
	  lwz       r8, 0x4(r31)
	  stw       r0, 0x6D4(r1)
	  lis       r4, 0x4330
	  addi      r0, r30, 0x1
	  lwz       r3, 0x224(r8)
	  stw       r4, 0x6D0(r1)
	  xoris     r0, r0, 0x8000
	  lfd       f4, -0x56C0(r2)
	  lfd       f0, 0x6D0(r1)
	  addi      r6, r3, 0x500
	  stw       r0, 0x6DC(r1)
	  li        r0, 0
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  mr        r5, r31
	  stw       r4, 0x6D8(r1)
	  addi      r3, r1, 0x6B0
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D8(r1)
	  lfs       f2, -0x56CC(r2)
	  li        r4, 0x2
	  lfs       f1, -0x56C4(r2)
	  fsubs     f0, f0, f4
	  lwz       r7, 0x0(r6)
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6C8(r1)
	  lwz       r6, 0x6CC(r1)
	  subi      r6, r6, 0x1
	  add       r6, r7, r6
	  stw       r6, 0x3BC(r8)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x3539C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x35178
	  b         .loc_0x19E0

	.loc_0x330:
	  bl        -0x5C34
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x424
	  lwz       r3, 0x4(r31)
	  li        r0, 0x2
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x388
	  b         .loc_0x38C

	.loc_0x388:
	  neg       r30, r30

	.loc_0x38C:
	  bl        0xC3CD4
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x2A08
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0

	.loc_0x424:
	  lwz       r3, 0x4(r31)
	  bl        -0x5A5C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x4(r31)
	  li        r0, 0x3
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x480
	  b         .loc_0x484

	.loc_0x480:
	  neg       r30, r30

	.loc_0x484:
	  bl        0xC3BDC
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x2910
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0
	  bl        -0x5F94
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x5A4
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x6A8
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x355E8
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x353C4
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD0B5C
	  b         .loc_0x19E0

	.loc_0x5A4:
	  lbz       r5, 0x2BD(r3)
	  li        r4, 0
	  cmplwi    r5, 0
	  beq-      .loc_0x5C4
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C4
	  li        r4, 0x1

	.loc_0x5C4:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x668
	  li        r0, 0x5
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  lwz       r3, 0x4(r31)
	  stb       r30, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x318(r3)
	  bl        0xC3A78
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r0, 0x4330
	  lfd       f3, -0x56C0(r2)
	  stw       r0, 0x6C8(r1)
	  lfs       f2, -0x56C8(r2)
	  lfd       f0, 0x6C8(r1)
	  lfs       f1, -0x56CC(r2)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x56B8(r2)
	  lwz       r3, 0x3C4(r3)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x6D0(r1)
	  lwz       r4, 0x6D4(r1)
	  addi      r4, r4, 0x1
	  bl        0x27E0
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x5298
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2E
	  addi      r3, r3, 0x70
	  bl        -0xD0C70
	  b         .loc_0x19E0

	.loc_0x668:
	  cmplwi    r5, 0
	  beq-      .loc_0x758
	  li        r0, 0x6
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x500
	  lwz       r0, 0x510(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x698
	  b         .loc_0x69C

	.loc_0x698:
	  neg       r30, r30

	.loc_0x69C:
	  bl        0xC39C4
	  xoris     r0, r3, 0x8000
	  lwz       r8, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r4, 0x4330
	  addi      r0, r30, 0x1
	  lwz       r3, 0x224(r8)
	  stw       r4, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfd       f4, -0x56C0(r2)
	  lfd       f0, 0x6C8(r1)
	  addi      r6, r3, 0x500
	  stw       r0, 0x6D4(r1)
	  li        r0, 0
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  mr        r5, r31
	  stw       r4, 0x6D0(r1)
	  addi      r3, r1, 0x6A0
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f2, -0x56CC(r2)
	  li        r4, 0x2
	  lfs       f1, -0x56C4(r2)
	  fsubs     f0, f0, f4
	  lwz       r7, 0x0(r6)
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r6, 0x6DC(r1)
	  subi      r6, r6, 0x1
	  add       r6, r7, r6
	  stw       r6, 0x3BC(r8)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x357C4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x355A0
	  b         .loc_0x19E0

	.loc_0x758:
	  bl        -0x58F8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x84C
	  lwz       r3, 0x4(r31)
	  li        r0, 0x4
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x7B0
	  b         .loc_0x7B4

	.loc_0x7B0:
	  neg       r30, r30

	.loc_0x7B4:
	  bl        0xC38AC
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x25E0
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0

	.loc_0x84C:
	  lwz       r3, 0x4(r31)
	  bl        -0x5BA8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x944
	  lwz       r3, 0x4(r31)
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x8A8
	  b         .loc_0x8AC

	.loc_0x8A8:
	  neg       r30, r30

	.loc_0x8AC:
	  bl        0xC37B4
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x24E8
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0

	.loc_0x944:
	  lwz       r3, 0x4(r31)
	  bl        -0x5F7C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x4(r31)
	  li        r0, 0x3
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x9A0
	  b         .loc_0x9A4

	.loc_0x9A0:
	  neg       r30, r30

	.loc_0x9A4:
	  bl        0xC36BC
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x23F0
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0
	  bl        -0x64B4
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0xAC4
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x698
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x35B08
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x358E4
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD107C
	  b         .loc_0x19E0

	.loc_0xAC4:
	  lbz       r5, 0x2BD(r3)
	  li        r4, 0
	  cmplwi    r5, 0
	  beq-      .loc_0xAE4
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xAE4
	  li        r4, 0x1

	.loc_0xAE4:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0xB88
	  li        r0, 0x5
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  lwz       r3, 0x4(r31)
	  stb       r30, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x318(r3)
	  bl        0xC3558
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r0, 0x4330
	  lfd       f3, -0x56C0(r2)
	  stw       r0, 0x6C8(r1)
	  lfs       f2, -0x56C8(r2)
	  lfd       f0, 0x6C8(r1)
	  lfs       f1, -0x56CC(r2)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x56B8(r2)
	  lwz       r3, 0x3C4(r3)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x6D0(r1)
	  lwz       r4, 0x6D4(r1)
	  addi      r4, r4, 0x1
	  bl        0x22C0
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x57B8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2E
	  addi      r3, r3, 0x70
	  bl        -0xD1190
	  b         .loc_0x19E0

	.loc_0xB88:
	  cmplwi    r5, 0
	  beq-      .loc_0xC78
	  li        r0, 0x6
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x500
	  lwz       r0, 0x510(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0xBB8
	  b         .loc_0xBBC

	.loc_0xBB8:
	  neg       r30, r30

	.loc_0xBBC:
	  bl        0xC34A4
	  xoris     r0, r3, 0x8000
	  lwz       r8, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r4, 0x4330
	  addi      r0, r30, 0x1
	  lwz       r3, 0x224(r8)
	  stw       r4, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfd       f4, -0x56C0(r2)
	  lfd       f0, 0x6C8(r1)
	  addi      r6, r3, 0x500
	  stw       r0, 0x6D4(r1)
	  li        r0, 0
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  mr        r5, r31
	  stw       r4, 0x6D0(r1)
	  addi      r3, r1, 0x690
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f2, -0x56CC(r2)
	  li        r4, 0x2
	  lfs       f1, -0x56C4(r2)
	  fsubs     f0, f0, f4
	  lwz       r7, 0x0(r6)
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r6, 0x6DC(r1)
	  subi      r6, r6, 0x1
	  add       r6, r7, r6
	  stw       r6, 0x3BC(r8)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x35CE4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x35AC0
	  b         .loc_0x19E0

	.loc_0xC78:
	  bl        -0x5E18
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD6C
	  lwz       r3, 0x4(r31)
	  li        r0, 0x4
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0xCD0
	  b         .loc_0xCD4

	.loc_0xCD0:
	  neg       r30, r30

	.loc_0xCD4:
	  bl        0xC338C
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x20C0
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0

	.loc_0xD6C:
	  lwz       r3, 0x4(r31)
	  bl        -0x60C8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE64
	  lwz       r3, 0x4(r31)
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0xDC8
	  b         .loc_0xDCC

	.loc_0xDC8:
	  neg       r30, r30

	.loc_0xDCC:
	  bl        0xC3294
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x1FC8
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0

	.loc_0xE64:
	  lwz       r3, 0x4(r31)
	  bl        -0x676C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF5C
	  lwz       r3, 0x4(r31)
	  li        r0, 0x2
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0xEC0
	  b         .loc_0xEC4

	.loc_0xEC0:
	  neg       r30, r30

	.loc_0xEC4:
	  bl        0xC319C
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x1ED0
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0

	.loc_0xF5C:
	  lwz       r3, 0x4(r31)
	  bl        -0x6594
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x4(r31)
	  li        r0, 0x3
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0xFB8
	  b         .loc_0xFBC

	.loc_0xFB8:
	  neg       r30, r30

	.loc_0xFBC:
	  bl        0xC30A4
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x1DD8
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0
	  lwz       r4, 0x300(r3)
	  lwz       r0, 0x304(r3)
	  stw       r4, 0x30C(r3)
	  stw       r0, 0x310(r3)
	  lwz       r0, 0x308(r3)
	  stw       r0, 0x314(r3)
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x10F0
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x688
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x36134
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x35F10
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD16A8
	  b         .loc_0x19E0

	.loc_0x10F0:
	  lbz       r5, 0x2BD(r3)
	  li        r4, 0
	  cmplwi    r5, 0
	  beq-      .loc_0x1110
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1110
	  li        r4, 0x1

	.loc_0x1110:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x11B4
	  li        r0, 0x5
	  stw       r0, 0x2E8(r3)
	  li        r30, 0
	  lwz       r3, 0x4(r31)
	  stb       r30, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x318(r3)
	  bl        0xC2F2C
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r0, 0x4330
	  lfd       f3, -0x56C0(r2)
	  stw       r0, 0x6C8(r1)
	  lfs       f2, -0x56C8(r2)
	  lfd       f0, 0x6C8(r1)
	  lfs       f1, -0x56CC(r2)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x56B8(r2)
	  lwz       r3, 0x3C4(r3)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x6D0(r1)
	  lwz       r4, 0x6D4(r1)
	  addi      r4, r4, 0x1
	  bl        0x1C94
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x5DE4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2E
	  addi      r3, r3, 0x70
	  bl        -0xD17BC
	  b         .loc_0x19E0

	.loc_0x11B4:
	  cmplwi    r5, 0
	  beq-      .loc_0x12A4
	  li        r0, 0x6
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x500
	  lwz       r0, 0x510(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x11E4
	  b         .loc_0x11E8

	.loc_0x11E4:
	  neg       r30, r30

	.loc_0x11E8:
	  bl        0xC2E78
	  xoris     r0, r3, 0x8000
	  lwz       r8, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r4, 0x4330
	  addi      r0, r30, 0x1
	  lwz       r3, 0x224(r8)
	  stw       r4, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfd       f4, -0x56C0(r2)
	  lfd       f0, 0x6C8(r1)
	  addi      r6, r3, 0x500
	  stw       r0, 0x6D4(r1)
	  li        r0, 0
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  mr        r5, r31
	  stw       r4, 0x6D0(r1)
	  addi      r3, r1, 0x680
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f2, -0x56CC(r2)
	  li        r4, 0x2
	  lfs       f1, -0x56C4(r2)
	  fsubs     f0, f0, f4
	  lwz       r7, 0x0(r6)
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r6, 0x6DC(r1)
	  subi      r6, r6, 0x1
	  add       r6, r7, r6
	  stw       r6, 0x3BC(r8)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2EC(r6)
	  lwz       r6, 0x4(r31)
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x36310
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x360EC
	  b         .loc_0x19E0

	.loc_0x12A4:
	  bl        -0x64A4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x4(r31)
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x12FC
	  b         .loc_0x1300

	.loc_0x12FC:
	  neg       r30, r30

	.loc_0x1300:
	  bl        0xC2D60
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x1A94
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0
	  bl        -0x6E10
	  lwz       r3, 0x4(r31)
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  lfs       f1, 0x2C4(r3)
	  lfs       f0, -0x56DC(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x142C
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x678
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x36470
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3624C
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD19E4
	  b         .loc_0x19E0

	.loc_0x142C:
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x1474
	  b         .loc_0x1478

	.loc_0x1474:
	  neg       r30, r30

	.loc_0x1478:
	  bl        0xC2BE8
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x191C
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0
	  mr        r3, r31
	  bl        -0x1A70
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x4(r31)
	  li        r0, 0x8
	  li        r4, 0
	  stw       r0, 0x2E8(r3)
	  li        r0, 0x1
	  lwz       r3, 0x4(r31)
	  stb       r4, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x3B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r4, 0x2BC(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BB(r3)
	  lfs       f0, -0x56B4(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D8(r3)
	  bl        0xC2B00
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r0, 0x4330
	  lfd       f1, -0x56C0(r2)
	  stw       r0, 0x6C8(r1)
	  lfs       f4, -0x56C8(r2)
	  lfd       f0, 0x6C8(r1)
	  lfs       f3, -0x56CC(r2)
	  fsubs     f5, f0, f1
	  lfs       f1, -0x56B0(r2)
	  lfs       f0, -0x56AC(r2)
	  lfs       f2, 0x8C(r3)
	  fdivs     f4, f5, f4
	  fmuls     f3, f3, f4
	  fmuls     f1, f1, f3
	  fsubs     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x8C(r3)
	  lwz       r3, 0x4(r31)
	  lfs       f0, 0x8C(r3)
	  stfs      f0, 0xA0(r3)
	  b         .loc_0x19E0
	  lbz       r0, 0x3C9(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x160C
	  lwz       r3, 0x220(r3)
	  bl        -0xCBED8
	  lwz       r4, 0x4(r31)
	  lfs       f1, -0x5694(r2)
	  lfs       f0, 0x98(r4)
	  lfs       f2, 0x8(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x160C
	  li        r0, 0x1
	  stb       r0, 0x3C9(r4)
	  lwz       r3, 0x2F00(r13)
	  lwz       r4, 0x4(r31)
	  addi      r3, r3, 0x114
	  addi      r4, r4, 0x3CC
	  bl        -0x115040

	.loc_0x160C:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x1690
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x670
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x366D4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x364B0
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD1C48
	  b         .loc_0x19E0

	.loc_0x1690:
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x16E4
	  b         .loc_0x16E8

	.loc_0x16E4:
	  neg       r30, r30

	.loc_0x16E8:
	  bl        0xC2978
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x16AC
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)
	  b         .loc_0x19E0
	  lwz       r4, 0x2EC(r3)
	  lwz       r0, 0x3BC(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x17B0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x668
	  li        r4, -0x1
	  bl        -0x36820
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3658C

	.loc_0x17B0:
	  lwz       r4, 0x4(r31)
	  lfs       f0, -0x56DC(r2)
	  lfs       f1, 0x2C4(r4)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x1834
	  li        r0, 0
	  stw       r0, 0x2E8(r4)
	  li        r30, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x660
	  li        r4, 0
	  stb       r30, 0x2BD(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x318(r6)
	  bl        -0x36878
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x36654
	  lfs       f0, -0x56DC(r2)
	  li        r4, 0x2E
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  stb       r30, 0x7(r3)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x70
	  bl        -0xD1DEC
	  b         .loc_0x19E0

	.loc_0x1834:
	  lbz       r5, 0x2BD(r4)
	  li        r3, 0
	  cmplwi    r5, 0
	  beq-      .loc_0x1854
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1854
	  li        r3, 0x1

	.loc_0x1854:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x18F8
	  li        r0, 0x5
	  stw       r0, 0x2E8(r4)
	  li        r30, 0
	  lwz       r3, 0x4(r31)
	  stb       r30, 0x2BD(r3)
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x318(r3)
	  bl        0xC27E8
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r0, 0x4330
	  lfd       f3, -0x56C0(r2)
	  stw       r0, 0x6C8(r1)
	  lfs       f2, -0x56C8(r2)
	  lfd       f0, 0x6C8(r1)
	  lfs       f1, -0x56CC(r2)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x56B8(r2)
	  lwz       r3, 0x3C4(r3)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x6D0(r1)
	  lwz       r4, 0x6D4(r1)
	  addi      r4, r4, 0x1
	  bl        0x1550
	  lwz       r3, 0x4(r31)
	  stw       r30, 0x2EC(r3)
	  lwz       r3, 0x4(r31)
	  bl        -0x6528
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19E0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2E
	  addi      r3, r3, 0x70
	  bl        -0xD1F00
	  b         .loc_0x19E0

	.loc_0x18F8:
	  cmplwi    r5, 0
	  beq-      .loc_0x19E0
	  li        r0, 0x1
	  stw       r0, 0x2E8(r4)
	  lwz       r3, 0x4(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19E0
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0x224(r3)
	  addi      r3, r4, 0x520
	  lwz       r0, 0x530(r4)
	  lwz       r3, 0x0(r3)
	  sub.      r30, r0, r3
	  ble-      .loc_0x1948
	  b         .loc_0x194C

	.loc_0x1948:
	  neg       r30, r30

	.loc_0x194C:
	  bl        0xC2714
	  xoris     r0, r3, 0x8000
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x6CC(r1)
	  lis       r5, 0x4330
	  addi      r0, r30, 0x1
	  lfd       f4, -0x56C0(r2)
	  stw       r5, 0x6C8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f2, -0x56CC(r2)
	  lfd       f0, 0x6C8(r1)
	  li        r4, 0
	  stw       r0, 0x6D4(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x56C8(r2)
	  stw       r5, 0x6D0(r1)
	  lwz       r3, 0x224(r6)
	  fdivs     f3, f1, f0
	  lfd       f0, 0x6D0(r1)
	  lfs       f1, -0x56C4(r2)
	  lwz       r5, 0x520(r3)
	  fsubs     f0, f0, f4
	  fmuls     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x6D8(r1)
	  lwz       r3, 0x6DC(r1)
	  subi      r0, r3, 0x1
	  add       r0, r5, r0
	  stw       r0, 0x3BC(r6)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x3C4(r3)
	  bl        0x1448
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x2EC(r3)

	.loc_0x19E0:
	  lwz       r0, 0x6EC(r1)
	  lwz       r31, 0x6E4(r1)
	  lwz       r30, 0x6E0(r1)
	  addi      r1, r1, 0x6E8
	  mtlr      r0
	  blr
	*/
}
