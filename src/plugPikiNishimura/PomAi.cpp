#include "Pom.h"
#include "Piki.h"
#include "PikiState.h"
#include "EffectMgr.h"
#include "SoundMgr.h"
#include "Stickers.h"
#include "NaviMgr.h"
#include "Interactions.h"
#include "ItemMgr.h"
#include "NsMath.h"
#include "RumbleMgr.h"
#include "PikiHeadItem.h"
#include "PlayerState.h"
#include "DebugLog.h"

static u32 pomSE[] = {
	SE_KING_CHEEK, SE_PONGASHI_CLOSE, SE_PONGASHI_EAT, SE_PONGASHI_SHOT, SE_PONGASHI_DEAD, SE_PONGASHI_TOUCH,
};

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("PomAi");

/*
 * --INFO--
 * Address:	80178558
 * Size:	000074
 */
PomAi::PomAi(Pom* pom)
{
	mPom              = pom;
	mOpenStarCallBack = new PomGenOpenStarCallBack;
}

/*
 * --INFO--
 * Address:	801785CC
 * Size:	000194
 */
void PomAi::initAI(Pom* pom)
{
	mPom = pom;
	if (C_POM_PROP(mPom).mOpenOnInteractionOnly() < 2) {
		mPom->setCurrentState(2);
		mPom->setNextState(2);
		mPom->mAnimator.startMotion(PaniMotionInfo(10, this));
		mPom->enableStick();
		mPom->mAnimator.setCounter(28.0f);
	} else {
		mPom->setCurrentState(1);
		mPom->setNextState(1);
		mPom->mAnimator.startMotion(PaniMotionInfo(2, this));
		mPom->disableStick();
	}

	mPom->setAnimTimer(30.0f);
	mHasCollided        = 1;
	mPlaySound          = 0;
	mIsOpening          = 0;
	mPrevStickPikiCount = 0;
	mReleasedSeedCount  = 0;

	// splitting this monstrosity up into temps would be better. however, that destroys the stack :')
	mMaxSeedCount = C_POM_PROP(mPom).mMinCycles()
	              + NsMathI::getRand(NsLibMath<int>::abs(C_POM_PROP(mPom).mMaxCycles() - C_POM_PROP(mPom).mMinCycles() + 1));
	mCurrentDeform = 0.0f;
	mDeformAmount  = 0.0f;
}

/*
 * --INFO--
 * Address:	80178760
 * Size:	00007C
 */
void PomAi::animationKeyUpdated(PaniAnimKeyEvent& event)
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
 * Address:	801787DC
 * Size:	000044
 */
void PomAi::keyAction0()
{
	if (mPom->getCurrentState() == 5) {
		createPikiHead();
	} else if (mPom->getCurrentState() == 2) {
		mPom->enableStick();
	}
}

/*
 * --INFO--
 * Address:	80178820
 * Size:	00001C
 */
void PomAi::keyAction1()
{
	if (mPom->getCurrentState() == 2) {
		mIsOpening = 0;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PomAi::keyAction2()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PomAi::keyAction3()
{
}

/*
 * --INFO--
 * Address:	8017883C
 * Size:	000014
 */
void PomAi::keyLoopEnd()
{
	mPom->addLoopCounter(1);
}

/*
 * --INFO--
 * Address:	80178850
 * Size:	0000C8
 */
void PomAi::keyFinished()
{
	if (mPom->getCurrentState() == 0) {
		mPom->setIsAlive(0);
		mPom->setIsAtari(0);
		effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeS, mPom->mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathGlowS, mPom->mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathWaveS, mPom->mPosition, nullptr, nullptr);

		playSound(0);
		mPom->createPellet(mPom->mPosition, 150.0f, true);
	}

	mPom->setMotionFinish(1);
}

/*
 * --INFO--
 * Address:	80178918
 * Size:	000044
 */
void PomAi::playSound(int pomSoundID)
{
	if (mPom->mSeContext) {
		mPom->mSeContext->playSound(pomSE[pomSoundID]);
	}
}

/*
 * --INFO--
 * Address:	8017895C
 * Size:	000038
 */
void PomAi::killCallBackEffect(bool p1)
{
	PomGenOpenStarCallBack* cb = mOpenStarCallBack;
	effectMgr->mPtclMgr.killGenerator(cb, nullptr, p1);
}

/*
 * --INFO--
 * Address:	80178994
 * Size:	0001B4
 */
void PomAi::collidePetal(Creature* collider)
{
	if (mHasCollided) {
		return;
	}

	if (mPom->getCurrentState() == 2 && mPom->mAnimator.mAnimationCounter > 27.0f && collider->mVelocity.length() > 75.0f) {
		setCollideSound(collider);
	}

	if (mPom->getMotionFinish() && mPom->getCurrentState() == 3 && collider->mVelocity.length() > 75.0f) {
		setCollideSound(collider);
	}
}

/*
 * --INFO--
 * Address:	80178B48
 * Size:	000060
 */
void PomAi::setCollideSound(Creature* collider)
{
	mHasCollided = 1;

	// don't trigger collision sound for pikis flying into flower
	if (collider->mObjType == OBJTYPE_Piki) {
		if (static_cast<Piki*>(collider)->getState() != PIKISTATE_Flying) {
			mPlaySound = 1;
		}
	} else {
		mPlaySound = 1;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void PomAi::setEveryFrame()
{
	checkSwayAndScale();
	calcSwayAndScale();
	setInitPosition();
	resultFlagOn();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void PomAi::checkSwayAndScale()
{
	int stickPikiCount = mPom->getStickPikiCount();
	if (stickPikiCount > mPrevStickPikiCount) {
		mDeformAmount -= C_POM_PROP(mPom).mSquashAmount();
		effectMgr->create(EffectMgr::EFF_CloudOfDust_1, mPom->mPosition, nullptr, nullptr);
		playSound(5);
		resultFlagSeen();
	}

	mPrevStickPikiCount = stickPikiCount;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void PomAi::calcSwayAndScale()
{
	mCurrentDeform += mDeformAmount;
	mPom->mScale.x = 1.0f - mCurrentDeform;
	mPom->mScale.y = 1.0f + mCurrentDeform;
	mPom->mScale.z = 1.0f - mCurrentDeform;

	mDeformAmount *= C_POM_PROP(mPom).mSquashPersistence();

	mDeformAmount += C_POM_PROP(mPom).mSquashMultiplier() * -mCurrentDeform;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void PomAi::setInitPosition()
{
	Vector3f* pos     = mPom->getInitPosition();
	mPom->mPosition.x = pos->x;
	mPom->mPosition.y = pos->y;
	mPom->mPosition.z = pos->z;
}

/*
 * --INFO--
 * Address:	80178BA8
 * Size:	0001D4
 */
int PomAi::killStickPiki()
{
	int seedCount = 0;
	Stickers stickers(mPom);

	Iterator iter(&stickers);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (stuck && stuck->isAlive() && stuck->mObjType == OBJTYPE_Piki) {
			Piki* piki = static_cast<Piki*>(*iter);
			if (C_POM_PROP(mPom).mDoKillSameColorPiki() && piki->mColor == mPom->mColor) {
				piki->kill(false);
			} else {
				piki->setEraseKill();
				piki->kill(false);
				seedCount++;
			}

			iter.dec();
		}
	}

	return seedCount;
}

/*
 * --INFO--
 * Address:	80178D7C
 * Size:	000228
 */
void PomAi::createPikiHead()
{
	int seedCount = killStickPiki();
	Navi* player  = naviMgr->getNavi();
	f32 baseAngle = atan2f(mPom->mPosition.x - player->mPosition.x, mPom->mPosition.z - player->mPosition.z);

	f32 spreadAngle = PI * (C_POM_PROP(mPom).mDischargeAngle() / 360.0f);
	f32 minAngle    = baseAngle - spreadAngle;
	f32 angleRange  = 2.0f * spreadAngle;

	for (int i = 0; i < seedCount; i++) {
		PikiHeadItem* sprout = static_cast<PikiHeadItem*>(itemMgr->birth(OBJTYPE_Pikihead));
		if (sprout) {
			Vector3f spawnPos = mPom->mPosition;
			spawnPos.y += 50.0f;
			sprout->init(spawnPos);

			sprout->setColor(mPom->mColor);

			f32 randAngle = NsMathF::getRand(angleRange) + minAngle;
			sprout->mVelocity.set(200.0f * sinf(randAngle), 800.0f, 200.0f * cosf(randAngle));

			sprout->startAI(0);
			C_SAI(sprout)->start(sprout, PikiHeadAI::PIKIHEAD_Flying);
		}
	}

	rumbleMgr->start(RUMBLE_Unk10, 0, mPom->mPosition);
	playSound(3);
	mReleasedSeedCount++;
	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void PomAi::emitPomOpenEffect(u32 collPartID)
{
	CollPart* part               = mPom->mCollInfo->getSphere(collPartID);
	zen::particleGenerator* ptcl = effectMgr->create(EffectMgr::EFF_SD_Sparkle, mPom->mPosition, mOpenStarCallBack, nullptr);
	if (ptcl) {
		ptcl->setEmitPosPtr(&part->mCentre);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000198
 */
void PomAi::createPomOpenEffect()
{
	mIsOpening = true;
	mOpenStarCallBack->set(&mIsOpening);
	emitPomOpenEffect('pom1');
	emitPomOpenEffect('pom2');
	emitPomOpenEffect('pom3');
	emitPomOpenEffect('pom4');
	emitPomOpenEffect('pom5');
}

/*
 * --INFO--
 * Address:	80178FA4
 * Size:	0001DC
 */
void PomAi::calcPetalStickers()
{
	if (mPom->mIsPikiOrPlayerTouching) {
		mPom->addWalkTimer(gsys->getFrameTime());
	}

	// if swallow setting is enabled
	if (C_POM_PROP(mPom).mStickOrSwallow()) {
		CollPart* slotPart = mPom->mCollInfo->getSphere('slot');
		Stickers stuckList(mPom);
		Iterator iter(&stuckList);
		CI_LOOP(iter)
		{
			Creature* stuck = *iter;
			if (stuck && stuck->isAlive() && !stuck->isStickToMouth()) {
				CollPart* childPart = slotPart->getChildAt(0);
				InteractSwallow swallow(mPom, childPart, 0);
				stuck->stimulate(swallow);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void PomAi::resultFlagOn()
{
	if (mPom->insideAndInSearch()) {
		playerState->mResultFlags.setOn(RESFLAG_Pom);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void PomAi::resultFlagSeen()
{
	playerState->mResultFlags.setSeen(RESFLAG_Pom);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
bool PomAi::isMotionFinishTransit()
{
	return mPom->getMotionFinish();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
bool PomAi::deadTransit()
{
	return (mReleasedSeedCount >= mMaxSeedCount) ? true : false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool PomAi::petalOpenTransit()
{
	if (C_POM_PROP(mPom).mOpenOnInteractionOnly()) {
		return mPom->mIsPikiOrPlayerTouching;
	}

	return true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
bool PomAi::petalShakeTransit()
{
	return mHasCollided;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
bool PomAi::petalCloseTransit()
{
	if (C_POM_PROP(mPom).mMaxPikiPerCycle() != 0) {
		if (mPrevStickPikiCount >= C_POM_PROP(mPom).mMaxPikiPerCycle()) {
			return true;
		}
		if (C_POM_PROP(mPom).mCloseWaitTime() > 0.0f && mPom->getWalkTimer() > (C_POM_PROP(mPom).mCloseWaitTime())) {
			return true;
		}
	} else if (mPom->getWalkTimer() > (C_POM_PROP(mPom).mCloseWaitTime())) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001BC
 */
bool PomAi::dischargeTransit()
{
	Stickers stuckList(mPom);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (stuck->isAlive() && stuck->mObjType == OBJTYPE_Piki) {
			Piki* stuckPiki = static_cast<Piki*>(*iter);
			if (!C_POM_PROP(mPom).mDoKillSameColorPiki() || stuckPiki->mColor != mPom->mColor) {
				return true;
			}
		}
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void PomAi::initDie(int nextState)
{
	mPom->setNextState(nextState);
	mPom->setMotionFinish(false);
	mPom->setAttackTimer(0.0f);
	mPom->mAnimator.startMotion(PaniMotionInfo(0, this));
}

/*
 * --INFO--
 * Address:	80179180
 * Size:	000200
 */
void PomAi::initWait(int nextState)
{
	mPom->setNextState(nextState);
	mPom->setMotionFinish(false);
	mPom->mAnimator.startMotion(PaniMotionInfo(2, this));

	Stickers stuckList(mPom);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (stuck && stuck->isAlive() && stuck->mObjType == OBJTYPE_Piki) {
			Piki* stuckPiki = static_cast<Piki*>(*iter);
			if (stuckPiki->mColor == mPom->mColor) {
				stuck->kill(false);
				iter.dec();
			}
		}
	}
	mPom->mIsPikiOrPlayerTouching = false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E4
 */
void PomAi::initPetalOpen(int nextState)
{
	mPom->setNextState(nextState);
	mPom->setMotionFinish(false);
	mPom->mAnimator.startMotion(PaniMotionInfo(10, this));
	createPomOpenEffect();
	mPom->setWalkTimer(0.0f);
	mHasCollided = false;
	mPlaySound   = false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void PomAi::initPetalShake(int nextState)
{
	mPom->setNextState(nextState);
	mPom->setMotionFinish(false);
	mPom->mAnimator.startMotion(PaniMotionInfo(13, this));
	mHasCollided = false;
	if (mPlaySound) {
		mPlaySound = false;
		playSound(0);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void PomAi::initPetalClose(int nextState)
{
	mPom->setNextState(nextState);
	mPom->setMotionFinish(false);
	mPom->setLoopCounter(0);
	mPom->mAnimator.startMotion(PaniMotionInfo(11, this));
	mPom->disableStick();
	mIsOpening = false;
}

/*
 * --INFO--
 * Address:	80179380
 * Size:	0001CC
 */
void PomAi::initDischarge(int nextState)
{
	mPom->setNextState(nextState);
	mPom->setMotionFinish(false);
	mPom->mAnimator.startMotion(PaniMotionInfo(12, this));

	CollPart* slotPart = mPom->mCollInfo->getSphere('slot');
	Stickers stuckList(mPom);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (stuck && stuck->isAlive()) {
			CollPart* childPart = slotPart->getChildAt(0);
			InteractSwallow swallow(mPom, childPart, 0);
			stuck->stimulate(swallow);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void PomAi::dieState()
{
	if (mPom->getMotionFinish()) {
		if (mPom->getAttackTimer() > 1.0f) {
			mPom->doKill();
		}
		mPom->addAttackTimer(gsys->getFrameTime());
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PomAi::waitState()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void PomAi::openState()
{
	calcPetalStickers();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void PomAi::shakeState()
{
	calcPetalStickers();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void PomAi::closeState()
{
	if (mPom->getLoopCounter() >= C_POM_PROP(mPom).mDoAnimLoopWhenClosed()) {
		mPom->mAnimator.finishMotion(PaniMotionInfo(-1, this));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PomAi::dischargeState()
{
}

/*
 * --INFO--
 * Address:	8017954C
 * Size:	000898
 */
void PomAi::update()
{
	setEveryFrame();
	switch (mPom->getCurrentState()) {
	case 0:
		dieState();
		break;
	case 1:
		waitState();
		if (petalOpenTransit()) {
			initPetalOpen(2);
		}
		break;
	case 2:
		openState();
		if (petalCloseTransit()) {
			initPetalClose(4);
		} else if (petalShakeTransit()) {
			initPetalShake(3);
		}
		break;
	case 3:
		shakeState();
		if (petalCloseTransit()) {
			initPetalClose(4);
		} else if (petalShakeTransit()) {
			initPetalShake(3);
		}
		break;
	case 4:
		closeState();
		if (isMotionFinishTransit()) {
			if (dischargeTransit()) {
				initDischarge(5);
			} else {
				initWait(1);
			}
		}
		break;
	case 5:
		dischargeState();
		if (isMotionFinishTransit()) {
			if (deadTransit()) {
				initDie(0);
			} else {
				initWait(1);
			}
		}
		break;
	}
}
