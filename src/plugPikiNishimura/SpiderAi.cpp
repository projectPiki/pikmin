#include "DebugLog.h"
#include "EffectMgr.h"
#include "GameStat.h"
#include "ItemMgr.h"
#include "NaviMgr.h"
#include "NsMath.h"
#include "Pcam/CameraManager.h"
#include "PikiHeadItem.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "Spider.h"
#include "VersionGroups.h"

static u32 spiderSE[] = { SE_SPIDER_WALK, SE_SPIDER_LAND, SE_SPIDER_SWING, SE_SPIDER_DEAD, SE_SPIDER_BOMB };

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
	mCanFlick = false;
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
		rumbleMgr->start(RUMBLE_Unk5, 0, mSpider->mPosition);
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
		mSpider->mSpiderLeg->mInitialised = false;
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
	if (!mCanFlick && mSpider->getAlive()) {
		mCanFlick = mSpider->flickPikiTransit();
	}

	if (mCanFlick) {
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
		if (!mSpider->mIsHalfDead) {
			mSpider->mIsHalfDead = true;
			mSpider->mSpiderLeg->createHalfDeadEffect();
		}
	} else {
		mSpider->mIsHalfDead = false;
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
		playerState->mResultFlags.setOn(RESFLAG_Spider);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void SpiderAi::resultFlagSeen()
{
	playerState->mResultFlags.setSeen(RESFLAG_Spider);
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
	return mSpider->getMotionFinish() && mCanFlick;
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
	// Trigger appearance if not already visible
	if (!mSpider->mIsAppear) {
		Vector3f* initPos = mSpider->getInitPosition();

		// Check each captain to see if within spawn trigger distance
		Iterator iterNavi(naviMgr);
		CI_LOOP(iterNavi)
		{
			Creature* navi = *iterNavi;

			// If alive, visible and not buried, and within spawn trigger distance
			if (navi->isAlive() && navi->isVisible() && !navi->isBuried()
			    && qdist2(initPos->x, initPos->z, navi->mPosition.x, navi->mPosition.z) < C_SPIDER_PROP(mSpider).mSpawnTriggerDist()) {

				mSpider->mIsAppear = true;
#if defined(VERSION_PIKIDEMO)
#else
				mSpider->mIsBossBgm = true;

				// Adjust drop timer for "easy mode" if any PikiHead is present
				Iterator iterPikiHead(itemMgr->getPikiHeadMgr());
				CI_LOOP(iterPikiHead)
				{
					// BUG NOTE: This mistakenly reuses the captain iterator, so this condition
					// always evaluates against the last valid captain (not actual PikiHead).
					// However, since the loop only runs if a sprout exists, the condition ends up true.

					Creature* sprout = *iterNavi; // Not actually a sprout, it's the player (whoops!)

					if (sprout
					    && qdist2(initPos->x, initPos->z, sprout->mPosition.x, sprout->mPosition.z)
					           < C_SPIDER_PROP(mSpider).mSpawnTriggerDist()) {
						// change fall time from 0.05s to 5s
						C_SPIDER_PROP(mSpider).mDropTimer() = 5.0f;
						break;
					}
				}

				break;
#endif
			}
		}
	}

	// Handle falling animation once triggered
	if (mSpider->mIsAppear) {
		mSpider->addAnimTimer(gsys->getFrameTime());

		if (mSpider->getAnimTimer() > C_SPIDER_PROP(mSpider).mDropTimer()) {
			return true; // Completed the fall
		}
	}

	return false; // Still in transit or not triggered
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
	mSpider->setAttackTimer(0.0f);
	mSpider->mSpiderLeg->mMotionFinishFlag = true;
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
		mSpider->mActiveWalkCycleCount
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
#if defined(VERSION_PIKIDEMO)
#else
	// I don't think BLL is set to be invincible anywhere, so this does nothing?
	mSpider->setInvincible(false);
#endif
	mSpider->setIsOrganic(true);
	mSpider->setAnimTimer(30.0f);
	mSpider->mRotation.y += NsMathF::getRand(PI) - HALF_PI;
	mSpider->mFaceDirection = mSpider->mRotation.y;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void SpiderAi::initWait(int nextState)
{
	mSpider->setNextState(nextState);
	mSpider->mActiveWalkCycleCount
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
	int i;
	f32 timings[4];
	f32 timer = mSpider->getAttackTimer();
	for (i = 0; i < 4; i++) {
		timings[i] = C_SPIDER_PROP(mSpider).mDeadScaleStartDelay() + i * C_SPIDER_PROP(mSpider).mDeadScaleStageDelay();
	}

	if (timer < timings[3] && NsMathF::getRand(1.0f) < 0.2f) {
		mSpider->mSpiderLeg->createSmallSparkEffect(1);
	}

	if (timer > C_SPIDER_PROP(mSpider).mDeadBombEffectDelay() && mSpider->mCanCreateDeadBombFx) {
		mSpider->mSpiderLeg->createDeadBombEffect();
		mSpider->mCanCreateDeadBombFx = false;
	}

	if (timer > timings[0]) {
		if (mSpider->_3B9) {
			mSpider->mSpiderLeg->createPerishEffect();
			mSpider->_3B9 = false;
			mSpider->setIsAtari(false);
		}

		if (timer > C_SPIDER_PROP(mSpider).mDeadMotionDelay() + timings[3] + 0.5f) {
			mSpider->setMotionFinish(false);
		}
	}

	if (C_SPIDER_PROP(mSpider).mDoFinalKillEffects()) {
		for (i = 0; i < 4; i++) {
			if (timer > timings[i]) {
				mSpider->mSpiderLeg->setLegScaleParam(i);
			}
		}
		if (timer > C_SPIDER_PROP(mSpider).mDeadMotionDelay() + timings[3] + 1.5f) {
			GameStat::killTekis.inc();
			mSpider->doKill();
		}
	}

	mSpider->addAttackTimer(gsys->getFrameTime());
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
	mSpider->setTargetPosition(*mSpider->getInitPosition());
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
	if (mSpider->getLoopCounter() >= mSpider->mActiveWalkCycleCount) {
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
}
