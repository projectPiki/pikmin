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
	0x54, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1,
};

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

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
	if (static_cast<PomProp*>(mPom->mProps)->mPomProps.mOpenOnInteractionOnly() < 2) {
		mPom->setCurrentState(2);
		mPom->setNextState(2);
		mPom->mAnimator.startMotion(PaniMotionInfo(10, this));
		mPom->enableStick();
		mPom->mAnimator.setCurrentFrame(28.0f);
	} else {
		mPom->setCurrentState(1);
		mPom->setNextState(1);
		mPom->mAnimator.startMotion(PaniMotionInfo(2, this));
		mPom->disableStick();
	}

	mPom->setAnimTimer(30.0f);
	_08 = 1;
	_09 = 0;
	_0A = 0;
	_0C = 0;
	_10 = 0;

	// splitting this monstrosity up into temps would be better. however, that destroys the stack :')
	_14 = static_cast<PomProp*>(mPom->mProps)->mPomProps.mMinCycles()
	    + NsMathI::getRand(absVal(static_cast<PomProp*>(mPom->mProps)->mPomProps.mMaxCycles()
	                              - static_cast<PomProp*>(mPom->mProps)->mPomProps.mMinCycles() + 1));
	_1C = 0.0f;
	_18 = 0.0f;
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
	case KEY_Done:
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
		_0A = 0;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PomAi::keyAction2() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PomAi::keyAction3() { }

/*
 * --INFO--
 * Address:	8017883C
 * Size:	000014
 */
void PomAi::keyLoopEnd() { mPom->addLoopCounter(1); }

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
		effectMgr->create(EffectMgr::EFF_Unk63, mPom->mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Unk62, mPom->mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Unk61, mPom->mPosition, nullptr, nullptr);

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
	if (_08) {
		return;
	}

	if (mPom->getCurrentState() == 2 && mPom->mAnimator.mCurrentFrame > 27.0f && collider->mVelocity.length() > 75.0f) {
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
	_08 = 1;

	// don't trigger collision sound for pikis flying into flower
	if (collider->mObjType == OBJTYPE_Piki) {
		if (static_cast<Piki*>(collider)->getState() != PIKISTATE_Flying) {
			_09 = 1;
		}
	} else {
		_09 = 1;
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
	if (stickPikiCount > _0C) {
		_18 -= static_cast<PomProp*>(mPom->mProps)->mPomProps.mSquashAmount();
		effectMgr->create(EffectMgr::EFF_Unk121, mPom->mPosition, nullptr, nullptr);
		playSound(5);
		resultFlagSeen();
	}

	_0C = stickPikiCount;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void PomAi::calcSwayAndScale()
{
	_1C += _18;
	mPom->mScale.x = 1.0f - _1C;
	mPom->mScale.y = 1.0f + _1C;
	mPom->mScale.z = 1.0f - _1C;

	_18 *= static_cast<PomProp*>(mPom->mProps)->mPomProps.mSquashPersistence();

	_18 += static_cast<PomProp*>(mPom->mProps)->mPomProps.mSquashMultiplier() * -_1C;
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
			if (static_cast<PomProp*>(mPom->mProps)->mPomProps.mDoKillSameColorPiki() && piki->mColor == mPom->mColor) {
				piki->kill(false);
			} else {
				piki->set584();
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
	int seedCount      = killStickPiki();
	Navi* navi         = naviMgr->getNavi();
	f32 angle          = atan2f(mPom->mPosition.x - navi->mPosition.x, mPom->mPosition.z - navi->mPosition.z);
	f32 dischargeAngle = PI * (static_cast<PomProp*>(mPom->mProps)->mPomProps.mDischargeAngle() / 360.0f);
	f32 angleDiff      = angle - dischargeAngle;
	f32 outAngle       = 2.0f * dischargeAngle;

	for (int i = 0; i < seedCount; i++) {
		PikiHeadItem* sprout = static_cast<PikiHeadItem*>(itemMgr->birth(OBJTYPE_Pikihead));
		if (sprout) {
			Vector3f initPos = mPom->mPosition;
			initPos.y += 50.0f;
			sprout->init(initPos);
			sprout->setColor(mPom->mColor);
			f32 randAngle = NsMathF::getRand(outAngle) + angleDiff;
			sprout->mVelocity.set(200.0f * sinf(randAngle), 800.0f, 200.0f * cosf(randAngle));
			sprout->startAI(0);
			static_cast<SimpleAI*>(sprout->mStateMachine)->start(sprout, 0);
		}
	}

	rumbleMgr->start(10, 0, mPom->mPosition);
	playSound(3);
	_10++;

	// I cannot get getRand to match the stack and ordering in both this and Boss without doing this.
	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void PomAi::emitPomOpenEffect(u32 collPartID)
{
	CollPart* part               = mPom->mCollInfo->getSphere(collPartID);
	zen::particleGenerator* ptcl = effectMgr->create(EffectMgr::EFF_Unk49, mPom->mPosition, mOpenStarCallBack, nullptr);
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
	_0A = true;
	mOpenStarCallBack->set(&_0A);
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
	if (mPom->_3B8) {
		mPom->add2D0(gsys->getFrameTime());
	}

	// if swallow setting is enabled
	if (static_cast<PomProp*>(mPom->mProps)->mPomProps.mStickOrSwallow()) {
		CollPart* slotPart = mPom->mCollInfo->getSphere('slot');
		Stickers stuckList(mPom);
		Iterator iter(&stuckList);
		CI_LOOP(iter)
		{
			Creature* stuck = *iter;
			if (stuck && stuck->isAlive() && !stuck->isGrabbed()) {
				CollPart* childPart = slotPart->getChildAt(0);
				InteractSwallow swallow(mPom, childPart, 0);
				bool res = stuck->stimulate(swallow); // necessary for stack
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
		playerState->mResultFlags.setOn(RESFLAG_Unk45);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void PomAi::resultFlagSeen() { playerState->mResultFlags.setSeen(RESFLAG_Unk45); }

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
bool PomAi::isMotionFinishTransit() { return mPom->getMotionFinish(); }

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
bool PomAi::deadTransit() { return (_10 >= _14) ? true : false; }

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool PomAi::petalOpenTransit()
{
	if (static_cast<PomProp*>(mPom->mProps)->mPomProps.mOpenOnInteractionOnly()) {
		return mPom->_3B8;
	}
	return true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
bool PomAi::petalShakeTransit() { return _08; }

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
bool PomAi::petalCloseTransit()
{
	if (static_cast<PomProp*>(mPom->mProps)->mPomProps.mMaxPikiPerCycle() != 0) {
		if (_0C >= static_cast<PomProp*>(mPom->mProps)->mPomProps.mMaxPikiPerCycle()) {
			return true;
		}
		if (static_cast<PomProp*>(mPom->mProps)->mPomProps.mCloseWaitTime() > 0.0f
		    && mPom->get2D0() > (static_cast<PomProp*>(mPom->mProps)->mPomProps.mCloseWaitTime())) {
			return true;
		}
	} else if (mPom->get2D0() > (static_cast<PomProp*>(mPom->mProps)->mPomProps.mCloseWaitTime())) {
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
			if (!static_cast<PomProp*>(mPom->mProps)->mPomProps.mDoKillSameColorPiki() || stuckPiki->mColor != mPom->mColor) {
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
	mPom->set2D4(0.0f);
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
	mPom->_3B8 = false;
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
	mPom->set2D0(0.0f);
	_08 = false;
	_09 = false;
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
	_08 = false;
	if (_09) {
		_09 = false;
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
	_0A = false;
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
		if (mPom->get2D4() > 1.0f) {
			mPom->doKill();
		}
		mPom->add2D4(gsys->getFrameTime());
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PomAi::waitState() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void PomAi::openState() { calcPetalStickers(); }

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void PomAi::shakeState() { calcPetalStickers(); }

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void PomAi::closeState()
{
	if (mPom->getLoopCounter() >= static_cast<PomProp*>(mPom->mProps)->mPomProps.mDoAnimLoopWhenClosed()) {
		mPom->mAnimator.finishMotion(PaniMotionInfo(-1, this));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PomAi::dischargeState() { }

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
