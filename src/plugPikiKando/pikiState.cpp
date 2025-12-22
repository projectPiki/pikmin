#include "PikiState.h"
#include "AIConstant.h"
#include "BombItem.h"
#include "CPlate.h"
#include "DebugLog.h"
#include "GameStat.h"
#include "Interactions.h"
#include "Interface.h"
#include "ItemMgr.h"
#include "MapCode.h"
#include "MemStat.h"
#include "MizuItem.h"
#include "MoviePlayer.h"
#include "Navi.h"
#include "NaviMgr.h"
#include "NaviState.h"
#include "Pellet.h"
#include "PikiAI.h"
#include "PikiHeadItem.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "UtilityKando.h"
#include "WorkObject.h"
#include "gameflow.h"
#include "teki.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(46)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("pikiState")

/**
 * @TODO: Documentation
 */
void PikiStateMachine::init(Piki* piki)
{
	memStat->start("pikistate");
	create(PIKISTATE_Count);

	registerState(new PikiNormalState());
	registerState(new PikiFlickState());
	registerState(new PikiFlownState());
	registerState(new PikiEmitState());
	registerState(new PikiFallState());
	registerState(new PikiCliffState());
	registerState(new PikiLookAtState());
	registerState(new PikiBulletState());
	registerState(new PikiBubbleState());
	registerState(new PikiFiredState());
	registerState(new PikiSwallowedState());
	registerState(new PikiHangedState());
	registerState(new PikiWaterHangedState());
	registerState(new PikiGoHangState());
	registerState(new PikiFlyingState());
	registerState(new PikiGrowState());
	registerState(new PikiGrowupState());
	registerState(new PikiBuryState());
	registerState(new PikiWaveState());
	registerState(new PikiPushState());
	registerState(new PikiPushPikiState());
	registerState(new PikiNukareState());
	registerState(new PikiNukareWaitState());
	registerState(new PikiAutoNukiState());
	registerState(new PikiPressedState());
	registerState(new PikiAbsorbState());
	registerState(new PikiDyingState());
	registerState(new PikiDeadState());
	registerState(new PikiKinokoState());
	registerState(new PikiDrownState());
	registerState(new PikiEmotionState());
	registerState(new PikiKinokoChangeState());
	registerState(new PikiFallMeckState());

	memStat->end("pikistate");
}

/**
 * @TODO: Documentation
 */
void PikiState::dump()
{
	PRINT("*** PikiState (%s)\n", mName);
	doDump();
}

/**
 * @TODO: Documentation
 */
void PikiState::doDump()
{
}

/**
 * @TODO: Documentation
 */
void PikiStateMachine::transit(Piki* piki, int stateID)
{
	if (getCurrID(piki) == PIKISTATE_Grow) {
		// just need something to spawn this properly
		(getCurrID(piki) == PIKISTATE_Grow);
	}
	StateMachine::transit(piki, stateID);
}

/**
 * @TODO: Documentation
 */
void PikiState::transit(Piki* piki, int stateID)
{
	AState::transit(piki, stateID);
}

/**
 * @TODO: Documentation
 */
PikiLookAtState::PikiLookAtState()
    : PikiState(PIKISTATE_LookAt, "LOOKAT")
{
}

/**
 * @TODO: Documentation
 */
void PikiLookAtState::init(Piki* piki)
{
	mTimer = (0.3f * gsys->getRand(1.0f));
	mState = 0;
	SeSystem::playPlayerSe(SE_PIKI_CALLED);
	seSystem->playPikiSound(SEF_PIKI_CALLED, piki->mSRT.t);
	piki->endStickObject();
	piki->endStick();
}

/**
 * @TODO: Documentation
 */
void PikiLookAtState::exec(Piki* piki)
{
	Vector3f dir = piki->mSRT.t - piki->mNavi->mSRT.t;
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVelocity.x = piki->mVelocity.z = 0.0f;
	piki->mFaceDirection                  = roundAng(angDist(atan2f(dir.x, dir.z), piki->mFaceDirection) * 0.1f + piki->mFaceDirection);

	switch (mState) {
	case 0:
		mTimer -= gsys->getFrameTime();
		if (mTimer < 0.0f) {
			mTimer = 0.0f;
			piki->startMotion(PaniMotionInfo(PIKIANIM_Kizuku, piki), PaniMotionInfo(PIKIANIM_Kizuku));
			mState = 1;
		}
		break;

	case 1:
		break;

	case 2:
		piki->mFaceDirection += mRotationStep;
		piki->mSRT.r.set(0.0f, mRotationStep, 0.0f);
		break;

	case 3:
		break;

	default:
		mTimer -= gsys->getFrameTime();
		if (piki->mStickTarget) {
			piki->mFaceDirection = roundAng(piki->mFaceDirection + PI);
			transit(piki, PIKISTATE_Normal);
			return;
		}

		if (mTimer < 0.0f) {
			mTimer               = 0.0f;
			piki->mFaceDirection = roundAng(piki->mFaceDirection + PI);
			transit(piki, PIKISTATE_Normal);
		}
		break;
	}
}

/**
 * @TODO: Documentation
 */
void PikiLookAtState::cleanup(Piki* piki)
{
	piki->changeMode(PikiMode::FormationMode, piki->mNavi);
}

/**
 * @TODO: Documentation
 */
void PikiLookAtState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		mState        = 2;
		Vector3f dir  = piki->mNavi->mSRT.t - piki->mSRT.t;
		mRotationStep = angDist(atan2f(dir.x, dir.z), piki->mFaceDirection) / 7.0f;
		break;

	case KEY_Action1:
		mState = 3;
		break;

	case KEY_Finished:
		mState = 4;
		break;
	}
}

/**
 * @TODO: Documentation
 */
PikiNormalState::PikiNormalState()
    : PikiState(PIKISTATE_Normal, "NORMAL")
{
}

/**
 * @TODO: Documentation
 */
void PikiNormalState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
	_UNUSED10 = 0;
	_UNUSED14 = 0.0f;
	_UNUSED1C = C_PIKI_PROP(piki).mUnusedDynWallPushTime();
	mPushPiki = 0;
}

/**
 * @TODO: Documentation
 */
void PikiNormalState::restart(Piki* piki)
{
	init(piki);
}

/**
 * @TODO: Documentation
 */
void PikiNormalState::exec(Piki* piki)
{
	if (!piki->isAlive()) {
		transit(piki, PIKISTATE_Dead);
	}
}

/**
 * @TODO: Documentation
 */
void PikiNormalState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiNormalState::procWallMsg(Piki*, MsgWall*)
{
}

/**
 * @TODO: Documentation
 */
void PikiNormalState::procOffWallMsg(Piki*, MsgOffWall*)
{
	_UNUSED10 = 0;
	_UNUSED14 = 0.0f;
}

/**
 * @TODO: Documentation
 */
void PikiNormalState::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (!piki->isKinoko()) {
		Creature* collider = msg->mEvent.mCollider;
		int type           = collider->mObjType;
		mPushPiki          = 0;
		if (!piki->isDamaged() && piki->mMode != PikiMode::TransportMode) {
			switch (type) {
			case OBJTYPE_Water:
				if (piki->mHappa != Flower) {
					piki->changeMode(PikiMode::FreeMode, piki->mNavi);
					piki->mCurrNectar = collider;
					transit(piki, PIKISTATE_Absorb);
				}
				break;
			case OBJTYPE_Piki:
				if (static_cast<Piki*>(collider)->getState() == PIKISTATE_Push) {
					mPushPiki = static_cast<Piki*>(collider);
				}
				break;
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
PikiAbsorbState::PikiAbsorbState()
    : PikiState(PIKISTATE_Absorb, "ABSORB")
{
}

/**
 * @TODO: Documentation
 */
void PikiAbsorbState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Mizunomi, piki), PaniMotionInfo(PIKIANIM_Mizunomi));
	mState             = 0;
	mNectar            = piki->mCurrNectar;
	mHasAbsorbedNectar = false;
	piki->turnTo(mNectar->mSRT.t);
}

/**
 * @TODO: Documentation
 */
void PikiAbsorbState::exec(Piki* piki)
{
	piki->mVelocity.x = piki->mVelocity.z = 0.0f;
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	switch (mState) {
	case 1:
		if (mNectar->isAlive()) {
			MsgUser msg(0);
			MizuItem* nectar           = static_cast<MizuItem*>(mNectar);
			nectar->mCollidingCreature = piki;
			C_SAI(nectar)->procMsg(nectar, &msg);
		}

		mHasAbsorbedNectar = true;
		break;
	}

	if (piki->getUpperMotionIndex() != PIKIANIM_Mizunomi) {
		transit(piki, PIKISTATE_Normal);
		ERROR("mizunomi err!\n");
	}
}

/**
 * @TODO: Documentation
 */
void PikiAbsorbState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopStart:
		if (mState != 1) {
			seSystem->playPikiSound(SEF_PIKI_DRINK, piki->mSRT.t);
		}
		mState = 1;
		break;
	case KEY_LoopEnd:
		if (!mNectar->isAlive()) {
			piki->mPikiAnimMgr.finishMotion(piki);
			mState = 2;
		}
		break;
	case KEY_Finished:
		if (mHasAbsorbedNectar) {
			transit(piki, PIKISTATE_GrowUp);
		} else {
			transit(piki, PIKISTATE_Normal);
		}
		break;
	}
}

/**
 * @TODO: Documentation
 */
void PikiAbsorbState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
PikiDrownState::PikiDrownState()
    : PikiState(PIKISTATE_Drown, "DROWN")
{
}

/**
 * @TODO: Documentation
 */
void PikiDrownState::init(Piki* piki)
{
	if (piki->mFiredState != 0) {
		piki->endFire();
	}

	if (piki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() == PIKIANIM_TYakusui) {
		mState = 0;
	} else {
		mState = 1;
		piki->startMotion(PaniMotionInfo(PIKIANIM_Oboreru, piki), PaniMotionInfo(PIKIANIM_Oboreru));
	}

	mStruggleDuration = int(2.0f * gsys->getRand(1.0f)) + 6;
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	_UNUSED14 = int((2.0f * gsys->getRand(1.0f)));
	if (piki->isHolding()) {
		InteractRelease release(piki, 1.0f);
		piki->getHoldCreature()->stimulate(release);
	}

	seSystem->playSoundDirect(5, SEW_PIKI_DROWN, piki->mSRT.t);
	mOutOfWaterFrames = 0;

	// we already did this, but sure
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mActiveAction->abandon(nullptr);
	if (piki->isStickTo()) {
		piki->endStickObject();
		piki->endStick();
	}

	mIsBeingWhistled = false;
	STACK_PAD_TERNARY(mIsBeingWhistled, 1);
}

/**
 * @TODO: Documentation
 */
void PikiDrownState::exec(Piki* piki)
{
	if (mState != 2 && piki->mInWaterTimer == 0) {
		mOutOfWaterFrames++;
		if (mOutOfWaterFrames > 1) {
			piki->mSRT.t.y += 20.0f;
			Vector3f vel(sinf(piki->mFaceDirection), 0.0f, cosf(piki->mFaceDirection));
			vel.multiply(80.0f);
			piki->mVelocity = vel;
			if (piki->isKinoko()) {
				transit(piki, PIKISTATE_Kinoko);
			} else {
				piki->mEmotion = PikiEmotion::ShookDry;
				transit(piki, PIKISTATE_Emotion);
			}

			return;
		}
	} else {
		mOutOfWaterFrames = 0;
	}

	if (mState == 1) {
		Vector3f dir = piki->mNavi->mSRT.t - piki->mSRT.t;
		dir.normalise();
		mEscapeVelocity = piki->getSpeed(0.5f) * dir;
	} else {
		mEscapeVelocity.set(0.0f, 0.0f, 0.0f);
	}

	if (!mIsBeingWhistled || piki->isKinoko()) {
		piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	Vector3f velOffset = mEscapeVelocity - piki->mTargetVelocity;
	f32 diff           = velOffset.normalise();

	f32 speed = 15.0f;
	if (mIsBeingWhistled) {
		speed *= 2.0f;
	}

	f32 frame = gsys->getFrameTime();
	if (diff > speed * frame) {
		piki->mTargetVelocity = piki->mTargetVelocity + speed * velOffset * frame;
	} else {
		piki->mTargetVelocity = piki->mTargetVelocity + velOffset * frame;
	}

	piki->mVelocity = piki->mTargetVelocity;
}

/**
 * @TODO: Documentation
 */
void PikiDrownState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiDrownState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mState == 2) {
			seSystem->playSoundDirect(5, SEW_PIKI_DEAD, piki->mSRT.t);
			piki->kill(false);
			break;
		}

		if (mState == 1) {
			if (--mStruggleDuration == 0) {
				piki->startMotion(PaniMotionInfo(PIKIANIM_Sizumu, piki), PaniMotionInfo(PIKIANIM_Sizumu));
				seSystem->playSoundDirect(5, SEW_PIKI_SINK, piki->mSRT.t);
				mState = 2;
			} else {
				piki->startMotion(PaniMotionInfo(PIKIANIM_Oboreru, piki), PaniMotionInfo(PIKIANIM_Oboreru));
			}

			break;
		}

		if (mState == 0) {
			mState = 1;
			piki->startMotion(PaniMotionInfo(PIKIANIM_Oboreru, piki), PaniMotionInfo(PIKIANIM_Oboreru));
			seSystem->playSoundDirect(5, SEW_PIKI_DROWN, piki->mSRT.t);
		}

		break;
	}
}

/**
 * @TODO: Documentation
 */
PikiKinokoState::PikiKinokoState()
    : PikiState(PIKISTATE_Kinoko, "KINOKO")
{
}

/**
 * @TODO: Documentation
 */
void PikiKinokoState::init(Piki* piki)
{
	piki->startKinoko();
	mTarget = tekiMgr->findClosest(piki->mSRT.t, nullptr);
	initWalk(piki);
	piki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
	mState = 0;
}

/**
 * @TODO: Documentation
 */
void PikiKinokoState::initWalk(Piki* piki)
{
	mWalkTimer   = (2.0f * gsys->getRand(1.0f)) + 1.5f;
	Vector3f dir = mTarget->mSRT.t - piki->mSRT.t;
	f32 d        = dir.normalise();
	Vector3f orthoDir(dir.z, 0.0f, -dir.x);
	if (gsys->getRand(1.0f) > 0.5f) {
		orthoDir.multiply(-1.0f);
	}

	f32 r    = 0.2f * (gsys->getRand(1.0f) - 0.5f);
	orthoDir = orthoDir + r * dir;
	orthoDir.normalise();
	mTargetDir = orthoDir;
}

/**
 * @TODO: Documentation
 */
void PikiKinokoState::exec(Piki* piki)
{
	switch (mState) {
	case 0:
		exeBoid(piki);
		break;
	case 1:
		exeAttack(piki);
		break;
	}
}

/**
 * @TODO: Documentation
 */
void PikiKinokoState::exeAttack(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiKinokoState::exeBoid(Piki* piki)
{
	mWalkTimer -= gsys->getFrameTime();
	if (mWalkTimer < 0.0f) {
		initWalk(piki);
	}

	Iterator iter(&piki->mSearchBuffer);
	int count = 0;
	Vector3f boidPos(0.0f, 0.0f, 0.0f);
	Vector3f boidVel(0.0f, 0.0f, 0.0f);
	Vector3f dirNearest(0.0f, 0.0f, 0.0f);
	bool isNearest = false;
	f32 minDist    = 50.0f;

	CI_LOOP(iter)
	{
		Creature* c = *iter;
		if (c->mObjType != OBJTYPE_Piki) {
			continue;
		}
		Piki* other = static_cast<Piki*>(c);
		if (other == piki) {
			continue;
		}

		if (other->isKinoko()) {
			f32 dist = qdist2(other->mSRT.t.x, other->mSRT.t.z, piki->mSRT.t.x, piki->mSRT.t.z);
			if (dist < minDist) {
				minDist    = dist;
				dirNearest = piki->mSRT.t - other->mSRT.t;
				isNearest  = true;
			}

			boidPos = boidPos + other->mSRT.t;
			boidVel = boidVel + other->mVelocity;
			count++;
		}
	}

	if (count > 0) {
		dirNearest.normalise();
		boidPos.multiply(1.0f / f32(count));
		boidVel.multiply(1.0f / f32(count));
		boidVel.normalise();

		Vector3f dir = boidPos - piki->mSRT.t;
		Vector3f pikiDir(sinf(piki->mFaceDirection), 0.0f, cosf(piki->mFaceDirection));
		dir.normalise();
		Vector3f moveDir;

		if (isNearest) {
			moveDir = pikiDir * 0.01f + dirNearest * 0.99f;
		} else {
			moveDir = pikiDir * 0.4f + dir * 0.5f + mTargetDir * 0.1f;
		}

		moveDir.normalise();
		piki->setSpeed(0.3f, moveDir);
	} else {
		piki->setSpeed(0.3f, mTargetDir);
	}

	Vector3f targetDir = mTarget->mSRT.t - piki->mSRT.t;
	f32 dist           = targetDir.normalise();
	if (dist < 100.0f) {
		return;
	}
	piki->setSpeed(0.5f, targetDir);
}

/**
 * @TODO: Documentation
 */
void PikiKinokoState::cleanup(Piki* piki)
{
	piki->endKinoko();
}

/**
 * @TODO: Documentation
 */
PikiBubbleState::PikiBubbleState()
    : PikiState(PIKISTATE_Bubble, "BUBBLE")
{
}

/**
 * @TODO: Documentation
 */
void PikiBubbleState::init(Piki* piki)
{
	piki->changeMode(PikiMode::FreeMode, piki->mNavi);
	piki->startMotion(PaniMotionInfo(PIKIANIM_Moeru), PaniMotionInfo(PIKIANIM_Moeru));
	piki->enableMotionBlend();
	mSurvivalTimer = C_PIKI_PROP(piki).mPanicTime();
	mSurvivalTimer *= (0.1f * gsys->getRand(1.0f)) + 1.0f;
	mChangeDirectionTimer = 0.1f;
	mMoveDirection        = piki->mFaceDirection;
	mSpeedRatio           = 1.0f;
	EffectParm parm(piki);
	piki->mSlimeEffect->emit(parm);
	seSystem->playPikiSound(SEF_PIKI_WATERED, piki->mSRT.t);
}

/**
 * @TODO: Documentation
 */
void PikiBubbleState::exec(Piki* piki)
{
	piki->setSpeed(mSpeedRatio, mMoveDirection);
	mSurvivalTimer -= gsys->getFrameTime();
	mChangeDirectionTimer -= gsys->getFrameTime();
	if (mSurvivalTimer < 0.0f) {
		transit(piki, PIKISTATE_Dying);
		return;
	}

	if (mChangeDirectionTimer < 0.0f) {
		mChangeDirectionTimer = (0.2f * gsys->getRand(1.0f)) + 0.2f;
		mMoveDirection += (45.0f * gsys->getRand(1.0f)) / 180.0f * PI;
		mMoveDirection = roundAng(mMoveDirection);
		mSpeedRatio *= 0.99f;
	}
}

/**
 * @TODO: Documentation
 */
void PikiBubbleState::cleanup(Piki* piki)
{
	Vector3f centre = piki->getCentre();
	effectMgr->create(EffectMgr::EFF_Piki_BubbleRecover, centre, nullptr, nullptr);
	piki->mSlimeEffect->kill();
}

/**
 * @TODO: Documentation
 */
PikiFiredState::PikiFiredState()
    : PikiState(PIKISTATE_Fired, "FIRED")
{
}

/**
 * @TODO: Documentation
 */
void PikiFiredState::init(Piki* piki)
{
	piki->changeMode(PikiMode::FreeMode, piki->mNavi);
	piki->startMotion(PaniMotionInfo(PIKIANIM_Moeru), PaniMotionInfo(PIKIANIM_Moeru));
	piki->enableMotionBlend();
	mSurvivalTimer = C_PIKI_PROP(piki).mPanicTime();
	mSurvivalTimer *= (0.1f * gsys->getRand(1.0f)) + 1.0f;
	mChangeDirectionTimer = 0.1f;
	mMoveDirection        = piki->mFaceDirection;
	mSpeedRatio           = 1.0f;
}

/**
 * @TODO: Documentation
 */
void PikiFiredState::exec(Piki* piki)
{
	piki->setSpeed(mSpeedRatio, mMoveDirection);
	mSurvivalTimer -= gsys->getFrameTime();
	mChangeDirectionTimer -= gsys->getFrameTime();
	if (mSurvivalTimer < 0.0f) {
		transit(piki, PIKISTATE_Dying);
		return;
	}

	if (mChangeDirectionTimer < 0.0f) {
		mChangeDirectionTimer = (0.2f * gsys->getRand(1.0f)) + 0.2f;
		mMoveDirection += (45.0f * gsys->getRand(1.0f)) / 180.0f * PI;
		mMoveDirection = roundAng(mMoveDirection);
		mSpeedRatio *= 0.99f;
	}
}

/**
 * @TODO: Documentation
 */
void PikiFiredState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
PikiSwallowedState::PikiSwallowedState()
    : PikiState(PIKISTATE_Swallowed, "SWALLOWED")
{
}

/**
 * @TODO: Documentation
 */
void PikiSwallowedState::init(Piki* piki)
{
	PRINT_KANDO("swallowed init **** \n");
	piki->stopAI();
}

/**
 * @TODO: Documentation
 */
void PikiSwallowedState::exec(Piki* piki)
{
	if (!piki->isStickToMouth()) {
		PRINT(" piki wa TASUKATTA !\n"); // 'piki was HELPED'
		if (piki->mActiveAction->mIsSuspended && piki->isAlive() && piki->mActiveAction->resumable()) {
			piki->mActiveAction->restart();
		}
		transit(piki, PIKISTATE_Normal);
		return;
	}

	if (piki->getStickObject() && !piki->getStickObject()->isAlive()) {
		piki->endStickMouth();
		transit(piki, PIKISTATE_Normal);
	}
}

/**
 * @TODO: Documentation
 */
void PikiSwallowedState::cleanup(Piki* piki)
{
	piki->mSwallowMouthPart = nullptr;
	piki->restartAI();
}

/**
 * @TODO: Documentation
 */
PikiBulletState::PikiBulletState()
    : PikiState(PIKISTATE_Bullet, "BULLET")
{
}

/**
 * @TODO: Documentation
 */
void PikiBulletState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_RollJmp), PaniMotionInfo(PIKIANIM_RollJmp));
	mDistanceTravelled = 0.0f;
}

/**
 * @TODO: Documentation
 */
void PikiBulletState::exec(Piki* piki)
{
	Iterator iter(tekiMgr);
	CI_LOOP(iter)
	{
		Creature* teki = *iter;
		if (teki->isAlive() && teki->isVisible() && !teki->isFlying()) {
			Vector3f dir = teki->mSRT.t - piki->mSRT.t;
			f32 dist     = dir.length();
			if (dist < 100.0f) {
				piki->mActiveAction->abandon(nullptr);
				piki->mActiveAction->mCurrActionIdx = PikiAction::Attack;
				piki->mActiveAction->mChildActions[piki->mActiveAction->mCurrActionIdx].initialise(teki);
				piki->mMode = PikiMode::AttackMode;
				transit(piki, PIKISTATE_Normal);
				return;
			}
		}
	}

	mDistanceTravelled += piki->mVelocity.length() * gsys->getFrameTime();

	if (mDistanceTravelled > 300.0f) {
		piki->changeMode(PikiMode::FormationMode, piki->mNavi);
		transit(piki, PIKISTATE_Normal);
		return;
	}

	piki->mVelocity.normalise();
	piki->mVelocity = piki->getSpeed(1.0f) * piki->mVelocity;
}

/**
 * @TODO: Documentation
 */
void PikiBulletState::procWallMsg(Piki* piki, MsgWall*)
{
	piki->changeMode(PikiMode::FormationMode, piki->mNavi);
	transit(piki, PIKISTATE_Normal);
}

/**
 * @TODO: Documentation
 */
void PikiBulletState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
PikiFlickState::PikiFlickState()
    : PikiState(PIKISTATE_Flick, "FLICK")
{
}

/**
 * @TODO: Documentation
 */
void PikiFlickState::init(Piki* piki)
{
	mState            = 0;
	mInitialAngle     = piki->mRotationAngle;
	mRotationDelta    = 0.1f * (PI * gsys->getRand(1.0f));
	piki->mVelocity.y = (50.0f * gsys->getRand(1.0f)) + 100.0f;
	mStrength         = piki->mFlickIntensity * 0.1f * gsys->getRand(1.0f) + piki->mFlickIntensity;
	piki->mActiveAction->resume();
	piki->startMotion(PaniMotionInfo(PIKIANIM_JHit, piki), PaniMotionInfo(PIKIANIM_JHit));
}

/**
 * @TODO: Documentation
 */
void PikiFlickState::exec(Piki* piki)
{
	PaniAnimator& upper = piki->mPikiAnimMgr.getUpperAnimator();
	if (upper.getCurrentMotionIndex() == PIKIANIM_Kuttuku) {
		PRINT_KANDO("piki %x motion KENKA!\n", piki);
	}

	if (mState == 0) {
		f32 rad              = mStrength;
		piki->mVelocity.x    = -rad * sinf(mInitialAngle);
		piki->mVelocity.z    = -rad * cosf(mInitialAngle);
		piki->mFaceDirection = roundAng(piki->mFaceDirection + mRotationDelta);
		return;
	}

	if (mState == 2) {
		mGetUpTimer -= gsys->getFrameTime();
		if ((mGetUpTimer < 0.0f || piki->mIsWhistlePending) && piki->isAlive()) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_GetUp, piki), PaniMotionInfo(PIKIANIM_GetUp));
			mState = 3;
		}

		piki->mVelocity.x = 0.9f * piki->mVelocity.x;
		piki->mVelocity.z = 0.9f * piki->mVelocity.z;
		piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	piki->mVelocity.x = 0.9f * piki->mVelocity.x;
	piki->mVelocity.z = 0.9f * piki->mVelocity.z;
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @TODO: Documentation
 */
void PikiFlickState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mState == 0) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_JKoke, piki), PaniMotionInfo(PIKIANIM_JKoke));
			mState = 1;
			break;
		}
		if (mState == 1) {
			mState      = 2;
			f32 min     = C_PIKI_PROP(piki).mMinFlickKnockDownTime();
			f32 max     = C_PIKI_PROP(piki).mMaxFlickKnockDownTime();
			mGetUpTimer = (max - min) * gsys->getRand(1.0f) + min;
			if (piki->mHealth <= 0.0f) {
				PRINT("piki died !\n");
				transit(piki, PIKISTATE_Dead);
			}
			break;
		}

		PRINT("done\n");
		if (gsys->getRand(1.0f) < 0.25f && piki->mHappa >= Bud) {
			piki->mHappa--;
			piki->setFlower(piki->mHappa);
			zen::particleGenerator* ptclGen = effectMgr->create(EffectMgr::EFF_Piki_DeflowerPetals, piki->mEffectPos, nullptr, nullptr);
			if (ptclGen) {
				ptclGen->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
			}
			effectMgr->create(EffectMgr::EFF_Piki_DeflowerSpores, piki->mEffectPos, nullptr, nullptr);
		}

		if (piki->isKinoko()) {
			piki->mActiveAction->abandon(nullptr);
			piki->changeMode(PikiMode::FormationMode, piki->mNavi);
			transit(piki, PIKISTATE_KinokoChange);
			break;
		}

		transit(piki, PIKISTATE_Normal);
		break;
	}
}

/**
 * @TODO: Documentation
 */
void PikiFlickState::cleanup(Piki* piki)
{
	PRINT("** flick cleanup %x\n", piki);
	if (piki->isKinoko()) {
		return;
	}
	if (piki->isStickToMouth()) {
		return;
	}

	if (piki->isAlive() && piki->mIsWhistlePending) {
		piki->changeMode(PikiMode::FormationMode, piki->mNavi);
		piki->endStickObject();
		piki->mIsWhistlePending = false;
		return;
	}

	if (piki->isAlive() && piki->mActiveAction->resumable()) {
		piki->mActiveAction->restart();
		return;
	}

	PRINT_KANDO("piki%x FLICK ** aiAction->curr = %d is not resumable!\n", piki, piki->mActiveAction->mCurrActionIdx);
	piki->mActiveAction->abandon(nullptr);
}

/**
 * @TODO: Documentation
 */
PikiFlownState::PikiFlownState()
    : PikiState(PIKISTATE_Flown, "FLOWN")
{
}

/**
 * @TODO: Documentation
 */
void PikiFlownState::init(Piki* piki)
{
	mState          = 0;
	mInitialAngle   = atan2f(piki->mVelocity.x, piki->mVelocity.z);
	mRotationDelta  = 0.1f * (PI * gsys->getRand(1.0f));
	mFlickIntensity = 0.1f * piki->mFlickIntensity * gsys->getRand(1.0f) + piki->mFlickIntensity;
	piki->startMotion(PaniMotionInfo(PIKIANIM_JHit, piki), PaniMotionInfo(PIKIANIM_JHit));
}

/**
 * @TODO: Documentation
 */
void PikiFlownState::procBounceMsg(Piki* piki, MsgBounce*)
{
	if (mState == 0) {
		piki->startMotion(PaniMotionInfo(PIKIANIM_JKoke, piki), PaniMotionInfo(PIKIANIM_JKoke));
		mState = 1;
	}
}

/**
 * @TODO: Documentation
 */
void PikiFlownState::exec(Piki* piki)
{
	PaniAnimator& upper = piki->mPikiAnimMgr.getUpperAnimator();
	if (upper.getCurrentMotionIndex() == PIKIANIM_Kuttuku) {
		PRINT_KANDO("piki %x motion KENKA!\n", piki);
	}

	if (mState == 0) {
		piki->mFaceDirection = roundAng(piki->mFaceDirection + mRotationDelta);
		return;
	}

	if (mState == 2) {
		_10 -= gsys->getFrameTime();
		if ((_10 < 0.0f || piki->mIsWhistlePending) && piki->isAlive()) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_GetUp, piki), PaniMotionInfo(PIKIANIM_GetUp));
			mState = 3;
		}
		piki->mVelocity.x = 0.9f * piki->mVelocity.x;
		piki->mVelocity.z = 0.9f * piki->mVelocity.z;
		piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	piki->mVelocity.x = 0.9f * piki->mVelocity.x;
	piki->mVelocity.z = 0.9f * piki->mVelocity.z;
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @TODO: Documentation
 */
void PikiFlownState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mState == 1) {
			mState  = 2;
			f32 min = C_PIKI_PROP(piki).mMinFlickKnockDownTime();
			f32 max = C_PIKI_PROP(piki).mMaxFlickKnockDownTime();
			_10     = (max - min) * gsys->getRand(1.0f) + min;
			if (piki->mHealth <= 0.0f) {
				PRINT("piki died !\n");
				transit(piki, PIKISTATE_Dead);
			}
			break;
		}

		PRINT("done\n");
		if (gsys->getRand(1.0f) < 0.25f && piki->mHappa >= Bud) {
			piki->mHappa--;
			piki->setFlower(piki->mHappa);
			zen::particleGenerator* ptclGen = effectMgr->create(EffectMgr::EFF_Piki_DeflowerPetals, piki->mEffectPos, nullptr, nullptr);
			if (ptclGen) {
				ptclGen->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
			}
			effectMgr->create(EffectMgr::EFF_Piki_DeflowerSpores, piki->mEffectPos, nullptr, nullptr);
		}

		if (piki->isKinoko()) {
			piki->mActiveAction->abandon(nullptr);
			piki->changeMode(PikiMode::FormationMode, piki->mNavi);
			transit(piki, PIKISTATE_KinokoChange);
			break;
		}

		transit(piki, PIKISTATE_Normal);
		break;
	}
}

/**
 * @TODO: Documentation
 */
void PikiFlownState::cleanup(Piki* piki)
{
	if (piki->isKinoko()) {
		return;
	}
	if (piki->isStickToMouth()) {
		return;
	}

	if (piki->isAlive() && piki->mIsWhistlePending) {
		piki->changeMode(PikiMode::FormationMode, piki->mNavi);
		piki->mIsWhistlePending = false;
		return;
	}

	piki->mActiveAction->abandon(nullptr);
}

/**
 * @TODO: Documentation
 */
PikiFallMeckState::PikiFallMeckState()
    : PikiState(PIKISTATE_FallMeck, "FALLMECK")
{
}

/**
 * @TODO: Documentation
 */
void PikiFallMeckState::init(Piki* piki)
{
	PRINT_KANDO("--- fall start\n");
	piki->startMotion(PaniMotionInfo(PIKIANIM_Fall, piki), PaniMotionInfo(PIKIANIM_Fall));
	piki->endStickMouth();
	piki->mSwallowMouthPart = nullptr;
}

/**
 * @TODO: Documentation
 */
void PikiFallMeckState::exec(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiFallMeckState::procBounceMsg(Piki* piki, MsgBounce*)
{
	int attr = ATTR_NULL;
	if (piki->mGroundTriangle) {
		attr = MapCode::getAttribute(piki->mGroundTriangle);
	}

	if (!piki->hasBomb() && Piki::isSafeMePos(piki->mSRT.t) && !MapCode::isBald(piki->mGroundTriangle) && attr != ATTR_Water) {
		PikiHeadMgr::buryMode = true;
		PikiHeadItem* sprout  = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead);
		PikiHeadMgr::buryMode = false;

		if (sprout) {
			Vector3f pos(piki->mSRT.t);
			pos.y = mapMgr->getMinY(pos.x, pos.z, true);
			effectMgr->create(EffectMgr::EFF_SD_DirtCloud, pos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_SD_DirtSpray, pos, nullptr, nullptr);
			sprout->init(pos);
			sprout->setColor(piki->mColor);
			f32 randAngle = 2.0f * (PI * gsys->getRand(1.0f));
			sprout->mVelocity.set(220.0f * sinf(randAngle), 540.0f, 220.0f * cosf(randAngle));
			sprout->startAI(0);
			sprout->_3E0 = nullptr;
			C_SAI(sprout)->start(sprout, PikiHeadAI::PIKIHEAD_Unk5);
			piki->setEraseKill();
			piki->kill(true);
			STACK_PAD_VAR(1);
			return;
		}
	}

	transit(piki, PIKISTATE_Normal);
	if (piki->hasBomb()) {
		Creature* held = piki->getHoldCreature();
		held->resetStateGrabbed();
		if (held->mObjType == OBJTYPE_Bomb) {
			AICreature* ai = (AICreature*)held;
			if (ai->getCurrState()->getID() != 1) {
				MsgUser msg(1);
				BombItem* bomb    = (BombItem*)held;
				bomb->mCurrAnimId = 1;
				C_SAI(bomb)->procMsg(bomb, &msg);
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void PikiFallMeckState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
PikiFallState::PikiFallState()
    : PikiState(PIKISTATE_Fall, "FALL")
{
}

/**
 * @TODO: Documentation
 */
void PikiFallState::init(Piki* piki)
{
	PRINT_KANDO("--- fall start\n");
	piki->startMotion(PaniMotionInfo(PIKIANIM_Fall, piki), PaniMotionInfo(PIKIANIM_Fall));
	mState = 0;
}

/**
 * @TODO: Documentation
 */
void PikiFallState::exec(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiFallState::procBounceMsg(Piki* piki, MsgBounce*)
{
	PRINT_KANDO("fall : got bounce\n");
	mState = 1;
	piki->startMotion(PaniMotionInfo(PIKIANIM_JKoke, piki), PaniMotionInfo(PIKIANIM_JKoke));
}

/**
 * @TODO: Documentation
 */
void PikiFallState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mState == 1) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_GetUp, piki), PaniMotionInfo(PIKIANIM_GetUp));
			mState = 2;
			break;
		}

		if (mState == 2) {
			transit(piki, PIKISTATE_Normal);
		}
		break;
	}
}

/**
 * @TODO: Documentation
 */
void PikiFallState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
PikiCliffState::PikiCliffState()
    : PikiState(PIKISTATE_Cliff, "CLIFF")
{
}

/**
 * @TODO: Documentation
 */
void PikiCliffState::init(Piki* piki)
{
	mInitialVelocity = piki->mVelocity;

	f32 speed = mInitialVelocity.normalise();
	if (speed < 1.0f) {
		mCliffHangType = 0;
	} else {
		mCliffHangType = 1;
	}

	piki->startMotion(PaniMotionInfo(PIKIANIM_LSuberu, piki), PaniMotionInfo(PIKIANIM_LSuberu));
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mState = 0;
	PRINT_KANDO("%x cliff start :: %s\n", piki, mCliffHangType ? "BURAN" : "OTIKAKE"); // 'hang' and 'fall' (i think)
	mInitialFaceDir = piki->mFaceDirection;
}

/**
 * @TODO: Documentation
 */
void PikiCliffState::exec(Piki* piki)
{
	if (!piki->mGroundTriangle) {
		PRINT_KANDO("piki %x: no floor !\n", piki);
		transit(piki, PIKISTATE_Fall);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void PikiCliffState::startFall(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Otiru, piki), PaniMotionInfo(PIKIANIM_Otiru));
	mState = 3;
}

/**
 * @TODO: Documentation
 */
bool PikiCliffState::nearEnough(Piki* piki)
{
	Vector3f dir(sinf(piki->mFaceDirection), 0.0f, cosf(piki->mFaceDirection));
	f32 maxProj  = -1.0f;
	int planeIdx = -1;
	for (int i = 0; i < 3; i++) {
		f32 proj = piki->mGroundTriangle->mEdgePlanes[i].mNormal.DP(dir);
		if (proj > maxProj) {
			proj     = maxProj; // this is absolutely a typo
			planeIdx = i;
		}
	}

	f32 dist = piki->mGroundTriangle->mEdgePlanes[planeIdx].dist(piki->mSRT.t);
	if (dist < piki->mCollisionRadius + 0.2f) {
		f32 x     = piki->mSRT.t.x;
		f32 z     = piki->mSRT.t.z;
		f32 currY = piki->mSRT.t.y;
		x += dir.x * piki->mCollisionRadius * 1.5f;
		z += dir.z * piki->mCollisionRadius * 1.5f;
		f32 botY = mapMgr->getMinY(x, z, true);
		if (currY - botY >= 5.0f * piki->getCentreSize()) {
			return true;
		}

		PRINT_KANDO("currY = %.1f botY = %.1f\n", currY, botY);
	}

	return false;
}

/**
 * @TODO: Documentation
 */
void PikiCliffState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		switch (mState) {
		case 0:
			if (mCliffHangType >= 2 || mCliffHangType < 0) {
				return;
			}

			mState       = 1;
			mLoopCounter = int((2.0f * gsys->getRand(1.0f))) + 1;
			PRINT_KANDO("otikake motion start\n");
			piki->startMotion(PaniMotionInfo(PIKIANIM_Otikake, piki), PaniMotionInfo(PIKIANIM_Otikake));
			break;

		case 3:
			if (!piki->mGroundTriangle) {
				PRINT_KANDO("piki fall (otiru) %x\n", piki);
				transit(piki, PIKISTATE_Fall);
				return;
			}
			PRINT_KANDO("otiru escaped\n");
			transit(piki, PIKISTATE_Normal);
			break;

		case 1:
			PRINT_KANDO("goto normal !?\n");
			transit(piki, PIKISTATE_Normal);
			break;
		}
		break;

	case KEY_LoopEnd:
		switch (mState) {
		case 1:
			mLoopCounter--;
			if (mLoopCounter > 0) {
				break;
			}
			if (mCliffHangType == 1) {
				if (piki->mGroundTriangle && nearEnough(piki)) {
					piki->mFaceDirection = roundAng(mInitialFaceDir + PI);
					piki->startMotion(PaniMotionInfo(PIKIANIM_Hikakaru, piki), PaniMotionInfo(PIKIANIM_Hikakaru));
					Plane* plane = piki->getNearestPlane(piki->mGroundTriangle);
					if (plane) {
						f32 dist = plane->dist(piki->mSRT.t);
						PRINT_KANDO("dist is %.1f ( radius=%f : centresize=%f\n", dist, piki->mCollisionRadius, piki->getCentreSize());
						if (dist > -0.2f && dist < 3.0f) {
							PRINT_KANDO("piki%x : ####### start buran motion :: floor = %s\n", piki,
							            piki->mGroundTriangle ? "on floor" : "air");
							mState       = 2;
							mLoopCounter = int((2.0f * gsys->getRand(1.0f))) + 2;
							break;
						}
						PRINT_KANDO("buran is not executable : dist is too far\n");
						transit(piki, PIKISTATE_Normal);
						break;
					}
					PRINT_KANDO("buran is not executable : no plane\n");
					transit(piki, PIKISTATE_Normal);
					break;
				}
				PRINT_KANDO("buran is not executable : no floorCollTri\n");
				startFall(piki);
				break;
			}

			if (piki->mGroundTriangle) {
				PRINT_KANDO("piki escaped from falling!\n");
				transit(piki, PIKISTATE_Normal);
				break;
			}

			PRINT_KANDO("fall start : \n");
			startFall(piki);
			break;

		case 2:
			mLoopCounter--;
			if (mLoopCounter > 0) {
				break;
			}

			piki->mSRT.t = piki->getCentre();
			PRINT_KANDO("piki %x : do fall\n", piki);
			transit(piki, PIKISTATE_Fall);
			break;
		}
		break;
	}
}

/**
 * @TODO: Documentation
 */
void PikiCliffState::cleanup(Piki* piki)
{
	PRINT_KANDO("cliff cleanup\n");
}

/**
 * @TODO: Documentation
 */
PikiGoHangState::PikiGoHangState()
    : PikiState(PIKISTATE_GoHang, "GOHANG")
{
}

/**
 * @TODO: Documentation
 */
void PikiGoHangState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
}

/**
 * @TODO: Documentation
 */
void PikiGoHangState::exec(Piki* piki)
{
	CollPart* naviHand = piki->mNavi->mCollInfo->getSphere('rhnd');
	Vector3f dir       = naviHand->mCentre - piki->mSRT.t;
	f32 dist           = dir.normalise();
	f32 speedFactor    = 1.0f;
	if (dist > 2.0f * C_NAVI_PROP(piki->mNavi)._1BC()) {
		speedFactor = 2.0f;
	}
	piki->mTargetVelocity = dir * C_PIKI_PROP(piki).mMaxLeafMoveSpeed() * speedFactor;
	if (piki->mNavi->getCurrState()->getID() != NAVISTATE_ThrowWait) {
		transit(piki, PIKISTATE_Normal);
	}
}

/**
 * @TODO: Documentation
 */
void PikiGoHangState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
PikiHangedState::PikiHangedState()
    : PikiState(PIKISTATE_Hanged, "HANGED")
{
}

/**
 * @TODO: Documentation
 */
void PikiHangedState::procAnimMsg(Piki*, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		SeSystem::playPlayerSe(SE_PIKI_FLYREADY);
		break;
	}
}

/**
 * @TODO: Documentation
 */
void PikiHangedState::init(Piki* piki)
{
	piki->mMotionSpeed = 30.0f;
	piki->startMotion(PaniMotionInfo(PIKIANIM_Hang, piki), PaniMotionInfo(PIKIANIM_Hang));
	piki->mHasCollChangedVelocity = 0;
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @TODO: Documentation
 */
void PikiHangedState::exec(Piki* piki)
{
	if (piki->mNavi->getCurrState()->getID() != NAVISTATE_ThrowWait) {
		transit(piki, PIKISTATE_Normal);
	}
}

/**
 * @TODO: Documentation
 */
void PikiHangedState::cleanup(Piki* piki)
{
	SeSystem::stopPlayerSe(SE_PIKI_FLYREADY);
}

/**
 * @TODO: Documentation
 */
PikiWaterHangedState::PikiWaterHangedState()
    : PikiState(PIKISTATE_WaterHanged, "WATER_HANGED")
{
}

/**
 * @TODO: Documentation
 */
void PikiWaterHangedState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		SeSystem::playPlayerSe(SE_PIKI_FLYREADY);
		break;
	}
}

/**
 * @TODO: Documentation
 */
void PikiWaterHangedState::init(Piki* piki)
{
	piki->mMotionSpeed = 30.0f;
	piki->startMotion(PaniMotionInfo(PIKIANIM_Hang, piki), PaniMotionInfo(PIKIANIM_Hang));
	piki->mHasCollChangedVelocity = 0;
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	PRINT("water hang init!\n");
}

/**
 * @TODO: Documentation
 */
void PikiWaterHangedState::exec(Piki* piki)
{
	if (piki->mNavi->getCurrState()->getID() != NAVISTATE_ThrowWait) {
		PRINT("???\n");
		transit(piki, PIKISTATE_Normal);
	}
}

/**
 * @TODO: Documentation
 */
void PikiWaterHangedState::cleanup(Piki* piki)
{
	PRINT("water hang exit\n");
	SeSystem::stopPlayerSe(SE_PIKI_FLYREADY);
}

/**
 * @TODO: Documentation
 */
PikiEmitState::PikiEmitState()
    : PikiState(PIKISTATE_Emit, "EMIT")
{
}

/**
 * @TODO: Documentation
 */
void PikiEmitState::init(Piki* piki)
{
	piki->mMotionSpeed = 30.0f;
	piki->startMotion(PaniMotionInfo(PIKIANIM_WaveJmp, piki), PaniMotionInfo(PIKIANIM_WaveJmp));
	piki->stopAI();
	piki->mHasCollChangedVelocity = 0;
	mHasLanded                    = true;
}

/**
 * @TODO: Documentation
 */
void PikiEmitState::exec(Piki* piki)
{
	if (!mHasLanded) {
		piki->mVelocity.set(0.0f, 0.0f, 0.0f);
		piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}
}

/**
 * @TODO: Documentation
 */
void PikiEmitState::cleanup(Piki* piki)
{
	piki->restartAI();
}

/**
 * @TODO: Documentation
 */
void PikiEmitState::procBounceMsg(Piki* piki, MsgBounce*)
{
	if (mHasLanded) {
		mHasLanded = false;
		piki->startMotion(PaniMotionInfo(PIKIANIM_Umaru, piki), PaniMotionInfo(PIKIANIM_Umaru));
	}
}

/**
 * @TODO: Documentation
 */
void PikiEmitState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mHasLanded) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_WaveJmp, piki), PaniMotionInfo(PIKIANIM_WaveJmp));
		} else {
			transit(piki, PIKISTATE_Bury);
		}
		break;
	}
}

/**
 * @TODO: Documentation
 */
PikiFlyingState::PikiFlyingState()
    : PikiState(PIKISTATE_Flying, "FLYING")
{
}

/**
 * @TODO: Documentation
 */
void PikiFlyingState::stopEffect()
{
	mSparkleEffect.stop();
}

/**
 * @TODO: Documentation
 */
void PikiFlyingState::restartEffect()
{
	mSparkleEffect.restart();
}

/**
 * @TODO: Documentation
 */
void PikiFlyingState::init(Piki* piki)
{
	PRINT_KANDO("flying state init\n");
	PRINT_KANDO("piki is %s\n", piki->isHolding() ? "holding" : "not holding");
	piki->mMotionSpeed = 30.0f;
	piki->startMotion(PaniMotionInfo(PIKIANIM_RollJmp), PaniMotionInfo(PIKIANIM_RollJmp));
	piki->stopAI();
	piki->mHasCollChangedVelocity = 0;
	SeSystem::playPlayerSe(SE_PIKI_FLY);
	piki->mWantToStick = true;
	mIsFlowerGliding   = false;
	mSparkleEffect.init(piki->mSRT.t, EffectMgr::EFF_SD_Sparkle);
	mGroundTouchFrames = 0;
	mHasBounced        = false;
}

/**
 * @TODO: Documentation
 */
void PikiFlyingState::exec(Piki* piki)
{
	if (piki->isCreatureFlag(CF_IsOnGround)) {
		mGroundTouchFrames++;
		if (mGroundTouchFrames >= 10) {
			for (int i = 0; i < 10; i++) {
				PRINT("** WARNING *** FLYING MIGHT LAST FOREVER !!!\n");
			}
			piki->dump();
			procBounceMsg(piki, nullptr);
			return;
		}
	} else {
		mGroundTouchFrames = 0;
	}

	mSparkleEffect.updatePos(piki->mSRT.t);

	f32 startGrav          = AIConstant::_instance->mConstants.mGravity() * 0.8f;
	f32 glideGrav          = AIConstant::_instance->mConstants.mGravity() * C_PIKI_PROP(piki).mFlowerGravityScale();
	f32 gravTransitionTime = 0.15f;
	f32 gravInterp         = startGrav * gravTransitionTime - 0.5f * 0.15f * (startGrav - glideGrav) - glideGrav * gravTransitionTime;
	if (!mIsFlowerGliding && piki->mHappa == Flower && piki->mVelocity.y <= 0.0f) {
		mIsFlowerGliding = true;
		piki->startMotion(PaniMotionInfo(PIKIANIM_Hang), PaniMotionInfo(PIKIANIM_Hang));
		f32 glideDist;
		if (piki->mColor == Yellow) {
			glideDist = C_NAVI_PROP(piki->mNavi)._19C();
		} else {
			glideDist = C_NAVI_PROP(piki->mNavi)._17C();
		}

		f32 glideTime        = (speedy_sqrtf(gravInterp * gravInterp + 2.0f * glideDist * glideGrav) + -gravInterp) / glideGrav;
		f32 glideSpeedXZ     = C_NAVI_PROP(piki->mNavi)._1AC() * 0.5f;
		f32 glideSpeedFactor = glideSpeedXZ / glideTime;

		mHorizontalDirection.x = piki->mVelocity.x;
		mHorizontalDirection.y = 0.0f;
		mHorizontalDirection.z = piki->mVelocity.z;
		mHorizontalDirection.normalise();

		f32 startSpeedXZ        = speedy_sqrtf(piki->mVelocity.x * piki->mVelocity.x + piki->mVelocity.z * piki->mVelocity.z);
		mInitialHorizontalSpeed = startSpeedXZ;

		f32 targetSpeedXZ      = startSpeedXZ * 0.5f;
		mTargetHorizontalSpeed = targetSpeedXZ;

		// this calc is unused
		glideTime = ((startSpeedXZ * glideSpeedXZ) - (startSpeedXZ - (startSpeedXZ - targetSpeedXZ) * 0.5f - targetSpeedXZ) * 0.15f)
		          / targetSpeedXZ;

		piki->mVelocity.x *= glideSpeedFactor;
		piki->mVelocity.z *= glideSpeedFactor;

		piki->mTargetVelocity.x = piki->mVelocity.x;
		piki->mTargetVelocity.z = piki->mVelocity.z;

		piki->mVelocity.y       = 0.0f;
		piki->mTargetVelocity.y = 0.0f;
		mGlideTimer             = 0.0f;
		return;
	}

	if (!mIsFlowerGliding) {
		return;
	}

	piki->mFaceDirection = roundAng(gsys->getFrameTime() * PI / 0.42f + piki->mFaceDirection);
	mGlideTimer += gsys->getFrameTime();

	// for some natural variation in fall speed
	f32 randomFactor = (gsys->getRand(1.0f) - 0.5f) * 0.01f;

	STACK_PAD_TERNARY(randomFactor, 1);

	f32 gravAdjust;
	if (mGlideTimer < 0.15f) {
		gravAdjust = startGrav - (startGrav - glideGrav) / 0.15f * mGlideTimer;
	} else {
		gravAdjust = glideGrav;
	}

	piki->mVelocity.y += ((AIConstant::_instance->mConstants.mGravity() - gravAdjust) * (randomFactor + 1.0f)) * gsys->getFrameTime();

	STACK_PAD_VAR(4);
}

/**
 * @TODO: Documentation
 */
void PikiFlyingState::cleanup(Piki* piki)
{
	mSparkleEffect.kill();
	piki->restartAI();
	piki->mWantToStick = false;
}

/**
 * @TODO: Documentation
 */
void PikiFlyingState::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	Creature* collider = msg->mEvent.mCollider;
	int colliderType   = collider->mObjType;

	if (colliderType == OBJTYPE_WorkObject && piki->mVelocity.y >= 0.0f) {
		return;
	}

	if (colliderType == OBJTYPE_RockGen || colliderType == OBJTYPE_GrassGen) {
		return;
	}

	if (colliderType == OBJTYPE_Water && piki->mHappa != Flower) {
		return;
	}

	if (playerState->inDayEnd()) {
		return;
	}

	if (piki->isHolding()) {
		return;
	}

	if (colliderType == OBJTYPE_WorkObject) {
		WorkObject* obj = (WorkObject*)collider;
		if (obj->isBridge()) {
			PRINT("FLYING COLLIDE BRIDGE bridge is %s!!!\n", obj->workable(piki->mSRT.t) ? "workable" : "dame!");
			piki->mActiveAction->abandon(nullptr);
			piki->mActiveAction->mCurrActionIdx = PikiAction::Bridge;
			piki->mActiveAction->mChildActions[PikiAction::Bridge].initialise(collider);
			piki->mMode = PikiMode::BridgeMode;
			return;
		}

		if (obj->isHinderRock()) {
			piki->mActiveAction->abandon(nullptr);
			piki->mActiveAction->mCurrActionIdx = PikiAction::Push;
			piki->mActiveAction->mChildActions[PikiAction::Push].initialise(collider);
			piki->mMode = PikiMode::PushstoneMode;
			return;
		}

		ERROR("unknown work object!\n");
	}

	if (colliderType == OBJTYPE_Plant) {
		return;
	}

	if (colliderType == OBJTYPE_Weed) {
		return;
	}

	// kando we already did this check
	if (colliderType == OBJTYPE_RockGen || colliderType == OBJTYPE_GrassGen) {
		return;
	}

	// we also know this??? you checked this???
	if (colliderType != OBJTYPE_Plant) {
		SeSystem::playPlayerSe(SE_THROWHIT);
	}

	if (colliderType == OBJTYPE_Teki || collider->isBoss()) {
		Vector3f effPos = collider->mSRT.t - piki->mSRT.t;
		effPos.normalise();
		Vector3f effDir(effPos);
		effPos.multiply(piki->getCentreSize() * 1.5f);
		effPos.add(piki->mSRT.t);
		InteractHitEffect hit(piki, effPos, effDir, msg->mEvent.mColliderPart);
		collider->stimulate(hit);
	}

	CollPart* part = msg->mEvent.mColliderPart;
	if (part && part->isBouncy()) {
		if (!mHasBounced) {
			Vector3f bounceDir = piki->mSRT.t - collider->mSRT.t;
			bounceDir.normalise();
			bounceDir.multiply(140.0f);
			piki->mVelocity       = bounceDir;
			piki->mTargetVelocity = bounceDir;
		}

		mHasBounced = true;
		return;
	}

	if (colliderType == OBJTYPE_Teki && collider->isOrganic()) {
		piki->mActiveAction->abandon(nullptr);
		PRINT_KANDO("FLYING .. collide\n");
		if (msg->mEvent.mColliderPart->isPlatformType()) {
			if (msg->mEvent.mColliderPart->isStickable()) {
				PRINT_KANDO("flying ... stick to platform::%s(code %s)\n", msg->mEvent.mColliderPart->mCollInfo->mId.mStringID,
				            msg->mEvent.mColliderPart->mCollInfo->mCode.mStringID);
				piki->startStick(collider, msg->mEvent.mColliderPart);
				SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
			} else if (msg->mEvent.mColliderPart->isClimbable()) {
				PRINT_KANDO("flying ... stick to platform::%s(code %s)\n", msg->mEvent.mColliderPart->mCollInfo->mId.mStringID,
				            msg->mEvent.mColliderPart->mCollInfo->mCode.mStringID);
				piki->startStick(collider, msg->mEvent.mColliderPart);
				SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
			}
		} else if ((msg->mEvent.mColliderPart->isCollisionType() || msg->mEvent.mColliderPart->isTubeType())
		           && msg->mEvent.mColliderPart->isStickable()) {
			PRINT_KANDO("flying ... stick to sphere\n");
			piki->startStickObject(collider, msg->mEvent.mColliderPart, -1, 0.0f);
			SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
		}

		transit(piki, PIKISTATE_Normal);
		PRINT_KANDO("++++++++++++++++++++++++++++++++\n");
		PRINT_KANDO(" _stickPart = %x : %s\n", piki->mStickPart,
		            piki->mStickPart ? piki->mStickPart->mCollInfo->mId.mStringID : "nothing!");
		PRINT_KANDO(" _stickPart = %x\n", piki->mStickPart);
		piki->mActiveAction->mCurrActionIdx = PikiAction::Attack;
		PRINT_KANDO("----------------\n");
		piki->mActiveAction->mChildActions[PikiAction::Attack].initialise(collider);
		PRINT_KANDO("----------------\n");
		piki->mMode = PikiMode::AttackMode;
		PRINT_KANDO(" _stickPart = %x\n", piki->mStickPart);
		PRINT_KANDO("(%x) stick OBJECT attack start ? ########\n", piki);
		PRINT_KANDO(" _stickPart = %x\n", piki->mStickPart); // this is excessive.
		return;
	}

	if (collider->isBoss() && msg->mEvent.mColliderPart && msg->mEvent.mColliderPart->isStickable()) {
		if (msg->mEvent.mColliderPart->isPlatformType()) {
			piki->startStick(collider, msg->mEvent.mColliderPart);
			SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
		} else {
			piki->startStickObject(collider, msg->mEvent.mColliderPart, -1, 0.0f);
			SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
		}
		transit(piki, PIKISTATE_Normal);
		piki->mActiveAction->mCurrActionIdx = PikiAction::Attack;
		piki->mActiveAction->mChildActions[PikiAction::Attack].initialise(collider);
		piki->mMode = PikiMode::AttackMode;
		return;
	}

	if (collider->isSluice()) {
		PRINT_KANDO("got here\n");
		piki->mMode                         = PikiMode::BreakwallMode;
		piki->mActiveAction->mCurrActionIdx = PikiAction::BreakWall;
		piki->mActiveAction->mChildActions[PikiAction::BreakWall].initialise(collider);
		transit(piki, PIKISTATE_Normal);
		return;
	}

	if (colliderType == OBJTYPE_Pellet && ((Pellet*)collider)->getMinFreeSlotIndex() != -1) {
		piki->mActiveAction->abandon(nullptr);
		piki->mActiveAction->mCurrActionIdx = PikiAction::Transport;
		piki->mActiveAction->mChildActions[piki->mActiveAction->mCurrActionIdx].initialise(collider);
		piki->mMode = PikiMode::TransportMode;
		return;
	}

	if (colliderType != OBJTYPE_Navi) {
		PRINT_KANDO("collide restart!!\n");
		piki->restartAI();
		transit(piki, PIKISTATE_Normal);
	}
}

/**
 * @TODO: Documentation
 */
void PikiFlyingState::procStickMsg(Piki*, MsgStick*)
{
}

/**
 * @TODO: Documentation
 */
void PikiFlyingState::procBounceMsg(Piki* piki, MsgBounce*)
{
	if (mHasBounced) {
		piki->restartAI();
		transit(piki, PIKISTATE_Normal);
		piki->mActiveAction->mCurrActionIdx = PikiAction::Crowd;
		piki->mActiveAction->mChildActions[PikiAction::Crowd].initialise(piki->mNavi);
		piki->mMode = PikiMode::FormationMode;
		return;
	}

	piki->restartAI();
	transit(piki, PIKISTATE_Normal);
	seSystem->playPikiSound(SEF_PIKI_LAND, piki->mSRT.t);
	if (piki->isHolding()) {
		if (piki->getHoldCreature()->mObjType != OBJTYPE_Bomb) {
			PRINT("*** HOLD CREATURE = %x\n", piki->getHoldCreature());
			PRINT("piki = %x : holdCreature->holder = %x\n", piki, piki->getHoldCreature()->getHolder());
			ERROR("piki holds ??\n");
		}

		piki->changeMode(PikiMode::PutbombMode, piki->mNavi);
	} else {
		piki->actOnSituaton();
	}
}

/**
 * @TODO: Documentation
 */
PikiGrowState::PikiGrowState()
    : PikiState(PIKISTATE_Grow, "GROW")
{
}

/**
 * @TODO: Documentation
 */
void PikiGrowState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp1, piki), PaniMotionInfo(PIKIANIM_GrowUp1));
	piki->mFormationPriority = 0;
}

/**
 * @TODO: Documentation
 */
void PikiGrowState::exec(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiGrowState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiGrowState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		transit(piki, PIKISTATE_Bury);
		break;
	}
}

/**
 * @TODO: Documentation
 */
PikiKinokoChangeState::PikiKinokoChangeState()
    : PikiState(PIKISTATE_KinokoChange, "KINOKO_CHANGE")
{
}

/**
 * @TODO: Documentation
 */
void PikiKinokoChangeState::init(Piki* piki)
{
	if (piki->isKinoko()) {
		mDoBecomeKinoko = false;
	} else {
		mDoBecomeKinoko = true;
	}

	piki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp1, piki), PaniMotionInfo(PIKIANIM_GrowUp1));
}

/**
 * @TODO: Documentation
 */
void PikiKinokoChangeState::restart(Piki* piki)
{
	init(piki);
}

/**
 * @TODO: Documentation
 */
void PikiKinokoChangeState::exec(Piki* piki)
{
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	if (piki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() != PIKIANIM_GrowUp1) {
		if (mDoBecomeKinoko) {
			piki->startKinoko();
		} else {
			piki->endKinoko();
		}
	}
}

/**
 * @TODO: Documentation
 */
void PikiKinokoChangeState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiKinokoChangeState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		if (mDoBecomeKinoko) {
			piki->startKinoko();
			piki->playEventSound(piki->mLeaderCreature, SE_KINOKOPIKI_MORPH);
		} else {
			piki->endKinoko();
		}
		break;
	case KEY_Finished:
		transit(piki, PIKISTATE_Normal);
		break;
	}
}

/**
 * @TODO: Documentation
 */
PikiGrowupState::PikiGrowupState()
    : PikiState(PIKISTATE_GrowUp, "GROWUP")
{
}

/**
 * @TODO: Documentation
 */
void PikiGrowupState::init(Piki* piki)
{
	if (piki->mFloweringTimer < 1) {
		piki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp1, piki), PaniMotionInfo(PIKIANIM_GrowUp1));
	} else {
		piki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp2, piki), PaniMotionInfo(PIKIANIM_GrowUp2));
	}
}

/**
 * @TODO: Documentation
 */
void PikiGrowupState::exec(Piki* piki)
{
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	int motionID = piki->getUpperMotionIndex();
	if (motionID != PIKIANIM_GrowUp1 && motionID != PIKIANIM_GrowUp2) {
		transit(piki, PIKISTATE_Normal);
	}
}

/**
 * @TODO: Documentation
 */
void PikiGrowupState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiGrowupState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		piki->mFloweringTimer++;
		seSystem->playPikiSound(SEF_PIKI_GROW4, piki->mSRT.t);
		piki->setFlower(Flower);
		playerState->mResultFlags.setOn(RESFLAG_PikminSeeds);
		if (!playerState->mDemoFlags.isFlag(DEMOFLAG_FirstNectar) && !gameflow.mMoviePlayer->mIsActive && piki->aiCullable()) {
			playerState->mDemoFlags.setFlagOnly(DEMOFLAG_FirstNectar);
			gameflow.mGameInterface->message(MOVIECMD_TextDemo, 22);
		}
		if (piki->mMode == PikiMode::FormationMode) {
			piki->mNavi->mPlateMgr->changeFlower(piki);
		}
		break;
	case KEY_Finished:
		transit(piki, PIKISTATE_Normal);
		break;
	}
}

/**
 * @TODO: Documentation
 */
PikiWaveState::PikiWaveState()
    : PikiState(PIKISTATE_Wave, "WAVE")
{
}

/**
 * @TODO: Documentation
 */
void PikiWaveState::init(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiWaveState::exec(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiWaveState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiWaveState::resume(Piki* piki)
{
	transit(piki, PIKISTATE_Normal);
}

/**
 * @TODO: Documentation
 */
void PikiWaveState::restart(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiWaveState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		transit(piki, PIKISTATE_Normal);
		break;
	case KEY_Action0:
	case KEY_Action1: // idk, nothing in the DLL about this
		break;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PikiWaveState::waveAttack(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
PikiPushState::PikiPushState()
    : PikiState(PIKISTATE_Push, "PUSH")
{
}

/**
 * @TODO: Documentation
 */
void PikiPushState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Push, piki), PaniMotionInfo(PIKIANIM_Run));
	mIsFinishing = false;
}

/**
 * @TODO: Documentation
 */
void PikiPushState::exec(Piki* piki)
{
	piki->mMotionSpeed = 30.0f;
	Vector3f vec(piki->mNavi->_74C);
	Vector3f dir(sinf(piki->mFaceDirection), 0.0f, cosf(piki->mFaceDirection));
	if (vec.DP(dir) < 0.4f) {
		piki->mPikiAnimMgr.finishMotion(piki);
		mIsFinishing = true;
	}

	if (!mIsFinishing && piki->mNavi->_764.length() <= 0.1f) {
		piki->mPikiAnimMgr.finishMotion(piki);
		mIsFinishing = true;
	} else if (piki->mWallObj && AIConstant::_instance->mConstants._64()) {
		piki->_4D8 = 1;
	}
}

/**
 * @TODO: Documentation
 */
void PikiPushState::cleanup(Piki* piki)
{
	piki->mWallObj = nullptr;
}

/**
 * @TODO: Documentation
 */
void PikiPushState::resume(Piki* piki)
{
	transit(piki, PIKISTATE_Normal);
}

/**
 * @TODO: Documentation
 */
void PikiPushState::restart(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiPushState::procOffWallMsg(Piki* piki, MsgOffWall*)
{
	piki->mPikiAnimMgr.finishMotion(piki);
}

/**
 * @TODO: Documentation
 */
void PikiPushState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		if (piki->mWallObj && !AIConstant::_instance->mConstants._64()) {
			piki->_4D8 = 1;
		}
		break;
	case KEY_Finished:
		transit(piki, PIKISTATE_Normal);
		break;
	}
}

/**
 * @TODO: Documentation
 */
PikiPushPikiState::PikiPushPikiState()
    : PikiState(PIKISTATE_PushPiki, "PUSHPIKI")
{
}

/**
 * @TODO: Documentation
 */
void PikiPushPikiState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Push, piki), PaniMotionInfo(PIKIANIM_Push));
	mCollisionFrameCount = 1;
	mIsFinishing         = false;
}

/**
 * @TODO: Documentation
 */
void PikiPushPikiState::exec(Piki* piki)
{
	if (!mIsFinishing && piki->mPushTargetPiki->getState() != PIKISTATE_Push && piki->mPushTargetPiki->getState() != PIKISTATE_PushPiki) {
		piki->mPikiAnimMgr.finishMotion(piki);
		mIsFinishing = true;
	}

	piki->mMotionSpeed = 30.0f;

	if (!mIsFinishing && piki->mNavi->_764.length() <= 0.1f) {
		piki->mPikiAnimMgr.finishMotion(piki);
		mIsFinishing = true;
	}

	mCollisionFrameCount = 0;
}

/**
 * @TODO: Documentation
 */
void PikiPushPikiState::cleanup(Piki* piki)
{
	piki->mPushTargetPiki = nullptr;
}

/**
 * @TODO: Documentation
 */
void PikiPushPikiState::resume(Piki* piki)
{
	transit(piki, PIKISTATE_Normal);
}

/**
 * @TODO: Documentation
 */
void PikiPushPikiState::restart(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiPushPikiState::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	STACK_PAD_VAR(1);
	Creature* collider = msg->mEvent.mCollider;
	switch (collider->mObjType) {
	case OBJTYPE_Piki:
		Piki* other = (Piki*)collider;
		if (other->getState() == PIKISTATE_Push) {
			Vector3f pos(other->mPushTargetPos);
			piki->mFaceDirection = other->mFaceDirection;
			piki->mPushTargetPos = pos;
			mCollisionFrameCount = 1;
		}
	}
}

/**
 * @TODO: Documentation
 */
void PikiPushPikiState::procWallMsg(Piki*, MsgWall*)
{
}

/**
 * @TODO: Documentation
 */
void PikiPushPikiState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		if (piki->mWallObj) {
			Vector3f dir(sinf(piki->mFaceDirection), 0.0f, cosf(piki->mFaceDirection));
			dir = dir * 2.0f;
			// this is just straight up how it is in the DLL, probably commented out code
		}
		break;
	case KEY_Finished:
		transit(piki, PIKISTATE_Normal);
		break;
	}
}

/**
 * @TODO: Documentation
 */
PikiBuryState::PikiBuryState()
    : PikiState(PIKISTATE_Bury, "BURY")
{
}

/**
 * @TODO: Documentation
 */
void PikiBuryState::init(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiBuryState::exec(Piki* piki)
{
	// The developers were averse to Pikmin sprouts being placed in water, but if this code used by Miurin (Mamuta) were to actually
	// encounter water, it would produce uninitialized PikiHeadItems.  If stale data is found, this results in Pikmin sprout duplication.
	// If zero-initialized data is found, the Pikmin sprout will be unpluckable and will cause a crash during end-of-day cleanup.  In
	// order to fit everything into one if-statement, I had to abuse the comma operator.  This bug fix respects the developers' original
	// intentions, but their intentions make the Mamuta worthless when in water and allow sprouts where there is no ground triangle, so
	// you might wish to change it anyway.
#ifdef BUGFIX
	PikiHeadItem* sprout;
	if ((!piki->mGroundTriangle || MapCode::getAttribute(piki->mGroundTriangle) != ATTR_Water)
	    && (PikiHeadMgr::buryMode = true, sprout = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead), PikiHeadMgr::buryMode = false, sprout))
#else
	PikiHeadMgr::buryMode = true;
	PikiHeadItem* sprout  = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead);
	PikiHeadMgr::buryMode = false;
	int attr              = ATTR_NULL;
	if (piki->mGroundTriangle) {
		attr = MapCode::getAttribute(piki->mGroundTriangle);
	}

	if (sprout && attr != ATTR_Water)
#endif
	{
		Vector3f pos(piki->mSRT.t);
		pos.y = mapMgr->getMinY(pos.x, pos.z, true);
		effectMgr->create(EffectMgr::EFF_SD_DirtCloud, pos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_SD_DirtSpray, pos, nullptr, nullptr);
		sprout->init(pos);
		sprout->setColor(piki->mColor);
		f32 angle = 2.0f * (PI * gsys->getRand(1.0f));
		sprout->mVelocity.set(220.0f * sinf(angle), 540.0f, 220.0f * cosf(angle));
		sprout->mFlowerStage = piki->mHappa;
		sprout->startAI(0);
		sprout->_3E0 = nullptr;
		C_SAI(sprout)->start(sprout, PikiHeadAI::PIKIHEAD_Unk5);
		piki->setEraseKill();
		piki->kill(true);
		STACK_PAD_VAR(1);
		return;
	}

	transit(piki, PIKISTATE_Normal);
}

/**
 * @TODO: Documentation
 */
void PikiBuryState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
PikiNukareWaitState::PikiNukareWaitState()
    : PikiState(PIKISTATE_NukareWait, "NUKARE_WAIT")
{
}

/**
 * @TODO: Documentation
 */
void PikiNukareWaitState::init(Piki* piki)
{
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mPikiAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Nukareru, piki), PaniMotionInfo(PIKIANIM_Nukareru));

	if ((piki->mColor == Red && !playerState->mDemoFlags.isFlag(DEMOFLAG_PluckRedPikmin))
	    || (piki->mColor == Yellow && !playerState->mDemoFlags.isFlag(DEMOFLAG_PluckYellowPikmin))
	    || (piki->mColor == Blue && !playerState->mDemoFlags.isFlag(DEMOFLAG_PluckBluePikmin))) {
		gameflow.mGameInterface->message(MOVIECMD_SetInputEnabled, FALSE);
	}
}

/**
 * @TODO: Documentation
 */
void PikiNukareWaitState::exec(Piki* piki)
{
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	if (piki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() != PIKIANIM_Nukareru) {
		piki->dump();
		ERROR("damedayo!");
	}

	piki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 0.0f;
	piki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 0.0f;
}

/**
 * @TODO: Documentation
 */
void PikiNukareWaitState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
PikiNukareState::PikiNukareState()
    : PikiState(PIKISTATE_Nukare, "NUKARE")
{
}

/**
 * @TODO: Documentation
 */
void PikiNukareState::init(Piki* piki)
{
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
	playerState->mDemoFlags.setFlagOnly(DEMOFLAG_NoPikminTimeout);
	piki->finishLook();
	gameflow.mGameInterface->message(MOVIECMD_SetInputEnabled, FALSE);
}

/**
 * @TODO: Documentation
 */
void PikiNukareState::exec(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiNukareState::cleanup(Piki* piki)
{
	if (playerState->isTutorial() && !playerState->mDemoFlags.isFlag(DEMOFLAG_Pluck15thPikmin) && GameStat::allPikis >= 15) {
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_Pluck15thPikmin);
		gameflow.mGameInterface->message(MOVIECMD_TextDemo, 30);
	}

	if (piki->mColor == Red && !playerState->mDemoFlags.isFlag(DEMOFLAG_PluckRedPikmin)) {
		PRINT("** NUKARE STATE CLEANUP !!!\n");
		playerState->mDemoFlags.setFlag(DEMOFLAG_PluckRedPikmin, piki);
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_NoPikminTimeout);
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_ApproachSeed);
		playerState->mDemoFlags.setTimer(demoParms->mParms._30(), DEMOFLAG_Unk9, naviMgr->getNavi());
		playerState->setDisplayPikiCount(Red);

	} else if (piki->mColor == Yellow && !playerState->mDemoFlags.isFlag(DEMOFLAG_PluckYellowPikmin)) {
		playerState->mDemoFlags.setFlag(DEMOFLAG_PluckYellowPikmin, piki);
		playerState->mResultFlags.setOn(RESFLAG_MeetYellowPikminNoBomb);
		playerState->mResultFlags.setOn(RESFLAG_Onyons);
		playerState->setContainer(Yellow);
		playerState->setDisplayPikiCount(Yellow);

	} else if (piki->mColor == Blue && !playerState->mDemoFlags.isFlag(DEMOFLAG_PluckBluePikmin)) {
		playerState->mDemoFlags.setFlag(DEMOFLAG_PluckBluePikmin, piki);
		playerState->mResultFlags.setOn(RESFLAG_MeetBluePikmin);
		playerState->setContainer(Blue);
		playerState->setDisplayPikiCount(Blue);

		// plucking a blue pikmin just. force unlocks the first 3 maps? sure.
		gameflow.mGamePrefs.openStage(STAGE_Practice);
		gameflow.mGamePrefs.openStage(STAGE_Forest);
		gameflow.mGamePrefs.openStage(STAGE_Cave);
	}

	gameflow.mGameInterface->message(MOVIECMD_SetInputEnabled, TRUE);
}

/**
 * @TODO: Documentation
 */
void PikiNukareState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		rumbleMgr->start(RUMBLE_Unk0, 0, nullptr);
		if (piki->mGroundTriangle && MapCode::getAttribute(piki->mGroundTriangle) == ATTR_Water) {
			effectMgr->create(EffectMgr::EFF_P_Bubbles, piki->mSRT.t, nullptr, nullptr);
		} else {
			effectMgr->create(EffectMgr::EFF_SD_DirtCloud, piki->mSRT.t, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_SD_DirtSpray, piki->mSRT.t, nullptr, nullptr);
		}
		break;
	case KEY_Finished:
		piki->mSRT.r.y       = piki->mNavi->mFaceDirection;
		piki->mFaceDirection = piki->mSRT.r.y;
		piki->mSRT.t         = piki->mShadowPos;
		f32 minY             = mapMgr->getMinY(piki->mSRT.t.x, piki->mSRT.t.z, true);
		if (minY > piki->mSRT.t.y) {
			PRINT("*** ABUNAI !!\n");
			piki->mSRT.t.y = minY + 1.0f;
		}
		transit(piki, PIKISTATE_Normal);
		piki->changeMode(PikiMode::FormationMode, piki->mNavi);
		if (piki->mNavi->mIsCursorVisible == FALSE) {
			piki->mNavi->_30C++;
			if (piki->mNavi->_30C >= C_NAVI_PROP(piki->mNavi)._3EC()) {
				piki->mNavi->mIsCursorVisible = TRUE;
			}
		}
		break;
	}
}

/**
 * @TODO: Documentation
 */
PikiAutoNukiState::PikiAutoNukiState()
    : PikiState(PIKISTATE_AutoNuki, "AUTONUKI")
{
}

/**
 * @TODO: Documentation
 */
void PikiAutoNukiState::init(Piki* piki)
{
	immut Choice motionChoice[1] = { PIKIANIM_Kaifuku, 1.0f }; // lol
	int motionIdx                = selectRandomly(motionChoice, 1);
	piki->mPikiAnimMgr.startMotion(PaniMotionInfo(motionIdx, piki), PaniMotionInfo(motionIdx));
	mToCreateEffect = false;
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @TODO: Documentation
 */
void PikiAutoNukiState::exec(Piki* piki)
{
	if (mToCreateEffect) {
		Vector3f pos(piki->mSRT.t); // lol
		effectMgr->create(EffectMgr::EFF_SD_DirtCloud, piki->mSRT.t, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_SD_DirtSpray, piki->mSRT.t, nullptr, nullptr);
		mToCreateEffect = false;
	}
}

/**
 * @TODO: Documentation
 */
void PikiAutoNukiState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiAutoNukiState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		mToCreateEffect = true;
		SeSystem::playPlayerSe(SE_PIKI_PULLED);
		break;
	case KEY_Finished:
		piki->mSRT.t = piki->mShadowPos;
		transit(piki, PIKISTATE_Normal);
		piki->changeMode(PikiMode::FormationMode, piki->mNavi);
		break;
	}
}

/**
 * @TODO: Documentation
 */
PikiPressedState::PikiPressedState()
    : PikiState(PIKISTATE_Pressed, "PRESSED")
{
}

/**
 * @TODO: Documentation
 */
void PikiPressedState::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (msg->mEvent.mCollider->mObjType == OBJTYPE_Teki) {
		mStunTimer    = 1.5f;
		mIsInvincible = true;
	}
}

/**
 * @TODO: Documentation
 */
void PikiPressedState::init(Piki* piki)
{
	f32 scale = 2.0f * C_PIKI_PROP(piki).mPikiDisplayScale();
	piki->mSRT.s.set(scale, 0.01f, scale);
	mStunTimer    = 1.5f;
	mIsInvincible = true;
	PRINT_KANDO("pressed init !\n");
}

/**
 * @TODO: Documentation
 */
void PikiPressedState::exec(Piki* piki)
{
	if (!mIsInvincible) {
		piki->mDeathTimer -= gsys->getFrameTime();
	}

	if (piki->mDeathTimer > C_PIKI_PROP(piki).mPressDeathFactor() - C_PIKI_PROP(piki).mNormalPikiPressFactor() && piki->mHealth <= 0.0f) {
		PRINT("*** PRESS DIE ! timer = %.1f\n", piki->mDeathTimer);
		transit(piki, PIKISTATE_Dead);
		return;
	}

	if (piki->mDeathTimer < 0.0f) {
		piki->mDeathTimer = 0.0f;
		transit(piki, PIKISTATE_Normal);
		f32 scale = C_PIKI_PROP(piki).mPikiDisplayScale();
		piki->mSRT.s.set(scale, scale, scale);
	}

	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	if (mStunTimer > 0.0f) {
		mStunTimer -= gsys->getFrameTime();
	} else {
		mIsInvincible = false;
	}
}

/**
 * @TODO: Documentation
 */
void PikiPressedState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
PikiDyingState::PikiDyingState()
    : PikiState(PIKISTATE_Dying, "DYING")
{
}

/**
 * @TODO: Documentation
 */
void PikiDyingState::init(Piki* piki)
{
	piki->mActiveAction->abandon(nullptr);
	immut Choice motionChoices[3] = {
		{ PIKIANIM_Dead, 0.33f },
		{ PIKIANIM_Dead2, 0.33f },
		{ PIKIANIM_Dead3, 0.33f },
	};

	int motionID = selectRandomly(motionChoices, 3);
	piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
	if (piki->hasBomb()) {
		BombItem* bomb = (BombItem*)piki->getHoldCreature();
		MsgUser msg(0);
		C_SAI(bomb)->procMsg(bomb, &msg);
		bomb->resetStateGrabbed();
	}
}

/**
 * @TODO: Documentation
 */
void PikiDyingState::exec(Piki* piki)
{
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @TODO: Documentation
 */
void PikiDyingState::cleanup(Piki* piki)
{
}

/**
 * @TODO: Documentation
 */
void PikiDyingState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (piki->isFired()) {
			piki->endFire();
			effectMgr->create(EffectMgr::EFF_Piki_FireRecover, piki->mEffectPos, nullptr, nullptr);
		}
		transit(piki, PIKISTATE_Dead);
		break;
	}
}

/**
 * @TODO: Documentation
 */
PikiDeadState::PikiDeadState()
    : PikiState(PIKISTATE_Dead, "DEAD")
{
}

/**
 * @TODO: Documentation
 */
void PikiDeadState::init(Piki* piki)
{
	piki->mDeathTimer = 1.5f;
	// this is probably some optimised OR check but i haven't figured out which. works for now.
	if (1 - piki->mMode == 0) { }
	piki->endStickObject();
}

/**
 * @TODO: Documentation
 */
void PikiDeadState::exec(Piki* piki)
{
	f32 scale = piki->mDeathTimer / 1.5f;
	piki->mSRT.s.set(scale, scale, scale);
	if (piki->mDeathTimer > 8.0f) {
		// also not in the DLL, i assume it's commented out code
	}
	piki->mDeathTimer -= gsys->getFrameTime();

	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	if (piki->mDeathTimer < 0.0f) {
		piki->kill(false);
	}
}

/**
 * @TODO: Documentation
 */
void PikiDeadState::cleanup(Piki* piki)
{
	piki->mSRT.s.set(0.0f, 0.0f, 0.0f);
}

/**
 * @TODO: Documentation
 */
PikiEmotionState::PikiEmotionState()
    : PikiState(PIKISTATE_Emotion, "EMOTION")
    , mCheerCount(0)
{
}

/**
 * @TODO: Documentation
 */
void PikiEmotionState::init(Piki* piki)
{
	mGazeFlag = 0;
	if (piki->mEmotion == PikiEmotion::None) {
		return;
	}

	switch (piki->mEmotion) {
	case PikiEmotion::Excited: {
		immut Choice motionChoices[2] = {
			{ PIKIANIM_Jump_B1, 0.5f },
			{ PIKIANIM_Gattu, 0.5f },
		};

		int soundChoices[2] = {
			SEF_PIKI_JUMP1,
			SEF_PIKI_ANGRY1,
		};

		int randIdx  = (2.0f * gsys->getRand(1.0f)) * 0.9999f;
		int motionID = motionChoices[randIdx].mValue;
		seSystem->playPikiSound(soundChoices[randIdx], piki->mSRT.t);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
		PRINT("play sound %d\n", TERNARY_BUGFIX(soundChoices[randIdx], motionID)); // wrong variable kando
	} break;

	case PikiEmotion::Happy: {
		immut Choice motionChoices[3] = {
			{ PIKIANIM_Jump_B1, 0.33f },
			{ PIKIANIM_Jump, 0.33f },
			{ PIKIANIM_RotJump, 0.33f },
		};

		int soundChoices[3] = {
			SEF_PIKI_JUMP1,
			SEF_PIKI_JUMP2,
			SEF_PIKI_JUMP3,
		};

		int randIdx  = (3.0f * gsys->getRand(1.0f)) * 0.9999f;
		int motionID = motionChoices[randIdx].mValue;
		seSystem->playPikiSound(soundChoices[randIdx], piki->mSRT.t);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
	} break;

	case PikiEmotion::Searching: {
		immut Choice motionChoices[2] = {
			{ PIKIANIM_Sagasu, 0.5f },
			{ PIKIANIM_Sagasu2, 0.5f },
		};

		int motionID = selectRandomly(motionChoices, 2);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
	} break;

	case PikiEmotion::Confused: {
		immut Choice motionChoices[2] = {
			{ PIKIANIM_Gakkari, 0.5f },
			{ PIKIANIM_Sagasu2, 0.5f },
		};

		int soundChoices[2] = {
			SEF_PIKI_GAKKARI,
			SEF_PIKI_SNEEZE,
		};

		int randIdx  = (2.0f * gsys->getRand(1.0f)) * 0.9999f;
		int motionID = motionChoices[randIdx].mValue;
		seSystem->playPikiSound(soundChoices[randIdx], piki->mSRT.t);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
	} break;

	case PikiEmotion::Sad: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Gakkari, piki), PaniMotionInfo(PIKIANIM_Gakkari));
		piki->mPikiAnimMgr.finishMotion(piki);
		seSystem->playPikiSound(SEF_PIKI_GAKKARI, piki->mSRT.t);
	} break;

	case PikiEmotion::ShookDry: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Mizuage, piki), PaniMotionInfo(PIKIANIM_Mizuage));
		piki->mPikiAnimMgr.finishMotion(piki);
		seSystem->playPikiSound(SEF_PIKI_BURUBURU, piki->mSRT.t);
	} break;

	case PikiEmotion::Victorious: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Jump_B1, piki), PaniMotionInfo(PIKIANIM_Jump_B1));
		piki->mPikiAnimMgr.finishMotion(piki);
		seSystem->playPikiSound(SEF_PIKI_YATTA, piki->mSRT.t);
	} break;

	case PikiEmotion::ShipPartGaze: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Wait, piki), PaniMotionInfo(PIKIANIM_Wait));
		piki->startLook(&piki->mCarryingShipPart->mSRT.t);
		mGazeFlag = 1;
	} break;

	case PikiEmotion::ShipPartCheer: {
		immut Choice motionChoices[5] = {
			{ PIKIANIM_Jump, 0.2f },   { PIKIANIM_Jump_B1, 0.2f }, { PIKIANIM_RotJump, 0.2f },
			{ PIKIANIM_Rinbow, 0.2f }, { PIKIANIM_Gattu, 0.2f },
		};

		int soundChoices[5] = {
			SEF_PIKI_JUMP1, SEF_PIKI_JUMP2, SEF_PIKI_JUMP3, SEF_PIKI_NOBI, SEF_PIKI_YATTA,
		};

		int randIdx  = (5.0f * gsys->getRand(1.0f)) * 0.9999f;
		int motionID = motionChoices[randIdx].mValue;
		seSystem->playPikiSound(soundChoices[randIdx], piki->mSRT.t);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
		if (mCheerCount == 0) {
			mCheerCount = 5;
			piki->startMotion(PaniMotionInfo(PIKIANIM_Wait, piki), PaniMotionInfo(PIKIANIM_Wait));
			piki->startLook(&piki->mCarryingShipPart->mSRT.t);
			mGazeFlag = 1;
		}
	} break;
	}
}

/**
 * @TODO: Documentation
 */
void PikiEmotionState::doDump()
{
	PRINT("gazeFlag=%d rapCnt=%d timer=%.1f gazePos(%.1f %.1f %.1f)\n", mGazeFlag, mCheerCount, mTimer, mGazePosition.x, mGazePosition.y,
	      mGazePosition.z);
}

/**
 * @TODO: Documentation
 */
void PikiEmotionState::exec(Piki* piki)
{
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (piki->mEmotion == PikiEmotion::None) {
		transit(piki, PIKISTATE_Normal);
	}

	if (piki->mEmotion == PikiEmotion::ShipPartGaze || (piki->mEmotion == PikiEmotion::ShipPartCheer && mCheerCount == 5)) {
		switch (mGazeFlag) {
		case 1:
			if (!piki->mCarryingShipPart->isAlive()) {
				mGazeFlag     = 2;
				mGazePosition = piki->mCarryingShipPart->mSRT.t;
				piki->startLook(&mGazePosition);
				mTimer = (0.4f * gsys->getRand(1.0f)) + 1.5f;
			}
			break;
		case 2:
			mTimer -= gsys->getFrameTime();
			if (mTimer < 0.0f) {
				piki->finishLook();
				mGazeFlag = 3;
				piki->mPikiAnimMgr.finishMotion(piki);
			}
			break;
		case 3:
			break;
		}
	}
}

/**
 * @TODO: Documentation
 */
void PikiEmotionState::cleanup(Piki* piki)
{
	piki->mEmotion          = PikiEmotion::None;
	piki->mCarryingShipPart = nullptr;
	piki->finishLook();
}

/**
 * @TODO: Documentation
 */
void PikiEmotionState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (piki->mEmotion == PikiEmotion::ShipPartCheer) {
			mCheerCount--;
			if (mCheerCount) {
				init(piki);
				break;
			}
		}

		mCheerCount = 0;
		transit(piki, PIKISTATE_Normal);
		break;
	}
}
