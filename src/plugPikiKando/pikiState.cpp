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

/*
 * --INFO--
 * Address:	800CF0E8
 * Size:	001428
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

/*
 * --INFO--
 * Address:	800D0510
 * Size:	00002C
 */
void PikiState::dump()
{
	PRINT("*** PikiState (%s)\n", mName);
	doDump();
}

/*
 * --INFO--
 * Address:	800D053C
 * Size:	000004
 */
void PikiState::doDump()
{
}

/*
 * --INFO--
 * Address:	800D0540
 * Size:	0000E0
 */
void PikiStateMachine::transit(Piki* piki, int stateID)
{
	if (getCurrID(piki) == PIKISTATE_Grow) {
		// just need something to spawn this properly
		PRINT("%s", getCurrID(piki) == PIKISTATE_Grow);
	}
	StateMachine::transit(piki, stateID);
}

/*
 * --INFO--
 * Address:	800D0620
 * Size:	000030
 */
void PikiState::transit(Piki* piki, int stateID)
{
	AState::transit(piki, stateID);
}

/*
 * --INFO--
 * Address:	800D0650
 * Size:	00004C
 */
PikiLookAtState::PikiLookAtState()
    : PikiState(PIKISTATE_LookAt, "LOOKAT")
{
}

/*
 * --INFO--
 * Address:	800D069C
 * Size:	0000A0
 */
void PikiLookAtState::init(Piki* piki)
{
	mTimer = (0.3f * gsys->getRand(1.0f));
	mState = 0;
	SeSystem::playPlayerSe(SE_PIKI_CALLED);
	seSystem->playPikiSound(SEF_PIKI_CALLED, piki->mPosition);
	piki->endStickObject();
	piki->endStick();
}

/*
 * --INFO--
 * Address:	800D073C
 * Size:	00020C
 */
void PikiLookAtState::exec(Piki* piki)
{
	Vector3f dir = piki->mPosition - piki->mNavi->mPosition;
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
		piki->mRotation.set(0.0f, mRotationStep, 0.0f);
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

/*
 * --INFO--
 * Address:	800D0948
 * Size:	00002C
 */
void PikiLookAtState::cleanup(Piki* piki)
{
	piki->changeMode(PikiMode::FormationMode, piki->mNavi);
}

/*
 * --INFO--
 * Address:	800D0974
 * Size:	0000B4
 */
void PikiLookAtState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		mState        = 2;
		Vector3f dir  = piki->mNavi->mPosition - piki->mPosition;
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

/*
 * --INFO--
 * Address:	800D0A28
 * Size:	000048
 */
PikiNormalState::PikiNormalState()
    : PikiState(PIKISTATE_Normal, "NORMAL")
{
}

/*
 * --INFO--
 * Address:	800D0A70
 * Size:	000088
 */
void PikiNormalState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
	_UNUSED10 = 0;
	_UNUSED14 = 0.0f;
	_UNUSED1C = C_PIKI_PROP(piki)._2CC();
	mPushPiki = 0;
}

/*
 * --INFO--
 * Address:	800D0AF8
 * Size:	00002C
 */
void PikiNormalState::restart(Piki* piki)
{
	init(piki);
}

/*
 * --INFO--
 * Address:	800D0B24
 * Size:	00006C
 */
void PikiNormalState::exec(Piki* piki)
{
	if (!piki->isAlive()) {
		transit(piki, PIKISTATE_Dead);
	}
}

/*
 * --INFO--
 * Address:	800D0B90
 * Size:	000004
 */
void PikiNormalState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D0B94
 * Size:	000004
 */
void PikiNormalState::procWallMsg(Piki*, MsgWall*)
{
}

/*
 * --INFO--
 * Address:	800D0B98
 * Size:	000014
 */
void PikiNormalState::procOffWallMsg(Piki*, MsgOffWall*)
{
	_UNUSED10 = 0;
	_UNUSED14 = 0.0f;
}

/*
 * --INFO--
 * Address:	800D0BAC
 * Size:	0000F4
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

/*
 * --INFO--
 * Address:	800D0CA0
 * Size:	00004C
 */
PikiAbsorbState::PikiAbsorbState()
    : PikiState(PIKISTATE_Absorb, "ABSORB")
{
}

/*
 * --INFO--
 * Address:	800D0CEC
 * Size:	0000A4
 */
void PikiAbsorbState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Mizunomi, piki), PaniMotionInfo(PIKIANIM_Mizunomi));
	mState             = 0;
	mNectar            = piki->mCurrNectar;
	mHasAbsorbedNectar = false;
	piki->turnTo(mNectar->mPosition);
}

/*
 * --INFO--
 * Address:	800D0D90
 * Size:	0000E8
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

/*
 * --INFO--
 * Address:	800D0E78
 * Size:	000110
 */
void PikiAbsorbState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopStart:
		if (mState != 1) {
			seSystem->playPikiSound(SEF_PIKI_DRINK, piki->mPosition);
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

/*
 * --INFO--
 * Address:	800D0F88
 * Size:	000004
 */
void PikiAbsorbState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D0F8C
 * Size:	00005C
 */
PikiDrownState::PikiDrownState()
    : PikiState(PIKISTATE_Drown, "DROWN")
{
}

/*
 * --INFO--
 * Address:	800D0FE8
 * Size:	000208
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

	seSystem->playSoundDirect(5, SEW_PIKI_DROWN, piki->mPosition);
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

/*
 * --INFO--
 * Address:	800D11F0
 * Size:	0003DC
 */
void PikiDrownState::exec(Piki* piki)
{
	if (mState != 2 && piki->mInWaterTimer == 0) {
		mOutOfWaterFrames++;
		if (mOutOfWaterFrames > 1) {
			piki->mPosition.y += 20.0f;
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
		Vector3f dir = piki->mNavi->mPosition - piki->mPosition;
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

/*
 * --INFO--
 * Address:	800D15CC
 * Size:	000004
 */
void PikiDrownState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D15D0
 * Size:	0001AC
 */
void PikiDrownState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mState == 2) {
			seSystem->playSoundDirect(5, SEW_PIKI_DEAD, piki->mPosition);
			piki->kill(false);
			break;
		}

		if (mState == 1) {
			if (--mStruggleDuration == 0) {
				piki->startMotion(PaniMotionInfo(PIKIANIM_Sizumu, piki), PaniMotionInfo(PIKIANIM_Sizumu));
				seSystem->playSoundDirect(5, SEW_PIKI_SINK, piki->mPosition);
				mState = 2;
			} else {
				piki->startMotion(PaniMotionInfo(PIKIANIM_Oboreru, piki), PaniMotionInfo(PIKIANIM_Oboreru));
			}

			break;
		}

		if (mState == 0) {
			mState = 1;
			piki->startMotion(PaniMotionInfo(PIKIANIM_Oboreru, piki), PaniMotionInfo(PIKIANIM_Oboreru));
			seSystem->playSoundDirect(5, SEW_PIKI_DROWN, piki->mPosition);
		}

		break;
	}
}

/*
 * --INFO--
 * Address:	800D177C
 * Size:	00005C
 */
PikiKinokoState::PikiKinokoState()
    : PikiState(PIKISTATE_Kinoko, "KINOKO")
{
}

/*
 * --INFO--
 * Address:	800D17D8
 * Size:	0000A4
 */
void PikiKinokoState::init(Piki* piki)
{
	piki->startKinoko();
	mTarget = tekiMgr->findClosest(piki->mPosition, nullptr);
	initWalk(piki);
	piki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
	mState = 0;
}

/*
 * --INFO--
 * Address:	800D187C
 * Size:	000268
 */
void PikiKinokoState::initWalk(Piki* piki)
{
	mWalkTimer   = (2.0f * gsys->getRand(1.0f)) + 1.5f;
	Vector3f dir = mTarget->mPosition - piki->mPosition;
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

/*
 * --INFO--
 * Address:	800D1AE4
 * Size:	000044
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

/*
 * --INFO--
 * Address:	800D1B28
 * Size:	000004
 */
void PikiKinokoState::exeAttack(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D1B2C
 * Size:	0007B8
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
			f32 dist = qdist2(other->mPosition.x, other->mPosition.z, piki->mPosition.x, piki->mPosition.z);
			if (dist < minDist) {
				minDist    = dist;
				dirNearest = piki->mPosition - other->mPosition;
				isNearest  = true;
			}

			boidPos = boidPos + other->mPosition;
			boidVel = boidVel + other->mVelocity;
			count++;
		}
	}

	if (count > 0) {
		dirNearest.normalise();
		boidPos.multiply(1.0f / f32(count));
		boidVel.multiply(1.0f / f32(count));
		boidVel.normalise();

		Vector3f dir = boidPos - piki->mPosition;
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

	Vector3f targetDir = mTarget->mPosition - piki->mPosition;
	f32 dist           = targetDir.normalise();
	if (dist < 100.0f) {
		return;
	}
	piki->setSpeed(0.5f, targetDir);
}

/*
 * --INFO--
 * Address:	800D22E4
 * Size:	000024
 */
void PikiKinokoState::cleanup(Piki* piki)
{
	piki->endKinoko();
}

/*
 * --INFO--
 * Address:	800D2308
 * Size:	00004C
 */
PikiBubbleState::PikiBubbleState()
    : PikiState(PIKISTATE_Bubble, "BUBBLE")
{
}

/*
 * --INFO--
 * Address:	800D2354
 * Size:	00012C
 */
void PikiBubbleState::init(Piki* piki)
{
	piki->changeMode(PikiMode::FreeMode, piki->mNavi);
	piki->startMotion(PaniMotionInfo(PIKIANIM_Moeru), PaniMotionInfo(PIKIANIM_Moeru));
	piki->enableMotionBlend();
	mSurvivalTimer = C_PIKI_PROP(piki)._3DC();
	mSurvivalTimer *= (0.1f * gsys->getRand(1.0f)) + 1.0f;
	mChangeDirectionTimer = 0.1f;
	mMoveDirection        = piki->mFaceDirection;
	mSpeedRatio           = 1.0f;
	EffectParm parm(piki);
	piki->mSlimeEffect->emit(parm);
	seSystem->playPikiSound(SEF_PIKI_WATERED, piki->mPosition);
}

/*
 * --INFO--
 * Address:	800D2480
 * Size:	000154
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

/*
 * --INFO--
 * Address:	800D25D4
 * Size:	000080
 */
void PikiBubbleState::cleanup(Piki* piki)
{
	Vector3f centre = piki->getCentre();
	effectMgr->create(EffectMgr::EFF_Piki_BubbleRecover, centre, nullptr, nullptr);
	piki->mSlimeEffect->kill();
}

/*
 * --INFO--
 * Address:	800D2654
 * Size:	00004C
 */
PikiFiredState::PikiFiredState()
    : PikiState(PIKISTATE_Fired, "FIRED")
{
}

/*
 * --INFO--
 * Address:	800D26A0
 * Size:	0000E4
 */
void PikiFiredState::init(Piki* piki)
{
	piki->changeMode(PikiMode::FreeMode, piki->mNavi);
	piki->startMotion(PaniMotionInfo(PIKIANIM_Moeru), PaniMotionInfo(PIKIANIM_Moeru));
	piki->enableMotionBlend();
	mSurvivalTimer = C_PIKI_PROP(piki)._3DC();
	mSurvivalTimer *= (0.1f * gsys->getRand(1.0f)) + 1.0f;
	mChangeDirectionTimer = 0.1f;
	mMoveDirection        = piki->mFaceDirection;
	mSpeedRatio           = 1.0f;
}

/*
 * --INFO--
 * Address:	800D2784
 * Size:	000154
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

/*
 * --INFO--
 * Address:	800D28D8
 * Size:	000004
 */
void PikiFiredState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D28DC
 * Size:	000050
 */
PikiSwallowedState::PikiSwallowedState()
    : PikiState(PIKISTATE_Swallowed, "SWALLOWED")
{
}

/*
 * --INFO--
 * Address:	800D292C
 * Size:	000010
 */
void PikiSwallowedState::init(Piki* piki)
{
	PRINT("swallowed init **** \n");
	piki->stopAI();
}

/*
 * --INFO--
 * Address:	800D293C
 * Size:	000104
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

/*
 * --INFO--
 * Address:	800D2A40
 * Size:	000018
 */
void PikiSwallowedState::cleanup(Piki* piki)
{
	piki->mSwallowMouthPart = nullptr;
	piki->restartAI();
}

/*
 * --INFO--
 * Address:	800D2A58
 * Size:	00004C
 */
PikiBulletState::PikiBulletState()
    : PikiState(PIKISTATE_Bullet, "BULLET")
{
}

/*
 * --INFO--
 * Address:	800D2AA4
 * Size:	000070
 */
void PikiBulletState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_RollJmp), PaniMotionInfo(PIKIANIM_RollJmp));
	mDistanceTravelled = 0.0f;
}

/*
 * --INFO--
 * Address:	800D2B14
 * Size:	0003F0
 */
void PikiBulletState::exec(Piki* piki)
{
	Iterator iter(tekiMgr);
	CI_LOOP(iter)
	{
		Creature* teki = *iter;
		if (teki->isAlive() && teki->isVisible() && !teki->isFlying()) {
			Vector3f dir = teki->mPosition - piki->mPosition;
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

/*
 * --INFO--
 * Address:	800D2F04
 * Size:	000060
 */
void PikiBulletState::procWallMsg(Piki* piki, MsgWall*)
{
	piki->changeMode(PikiMode::FormationMode, piki->mNavi);
	transit(piki, PIKISTATE_Normal);
}

/*
 * --INFO--
 * Address:	800D2F64
 * Size:	000004
 */
void PikiBulletState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D2F68
 * Size:	00004C
 */
PikiFlickState::PikiFlickState()
    : PikiState(PIKISTATE_Flick, "FLICK")
{
}

/*
 * --INFO--
 * Address:	800D2FB4
 * Size:	000168
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

/*
 * --INFO--
 * Address:	800D311C
 * Size:	0001A0
 */
void PikiFlickState::exec(Piki* piki)
{
	PaniAnimator& upper = piki->mPikiAnimMgr.getUpperAnimator();
	if (upper.getCurrentMotionIndex() == PIKIANIM_Kuttuku) {
		PRINT("piki %x motion KENKA!\n", piki);
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

/*
 * --INFO--
 * Address:	800D32BC
 * Size:	000294
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
			f32 min     = C_PIKI_PROP(piki)._32C();
			f32 max     = C_PIKI_PROP(piki)._31C();
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

/*
 * --INFO--
 * Address:	800D3550
 * Size:	0000F8
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

	piki->mActiveAction->abandon(nullptr);
}

/*
 * --INFO--
 * Address:	800D3648
 * Size:	00004C
 */
PikiFlownState::PikiFlownState()
    : PikiState(PIKISTATE_Flown, "FLOWN")
{
}

/*
 * --INFO--
 * Address:	800D3694
 * Size:	000124
 */
void PikiFlownState::init(Piki* piki)
{
	mState          = 0;
	mInitialAngle   = atan2f(piki->mVelocity.x, piki->mVelocity.z);
	mRotationDelta  = 0.1f * (PI * gsys->getRand(1.0f));
	mFlickIntensity = 0.1f * piki->mFlickIntensity * gsys->getRand(1.0f) + piki->mFlickIntensity;
	piki->startMotion(PaniMotionInfo(PIKIANIM_JHit, piki), PaniMotionInfo(PIKIANIM_JHit));
}

/*
 * --INFO--
 * Address:	800D37B8
 * Size:	000098
 */
void PikiFlownState::procBounceMsg(Piki* piki, MsgBounce*)
{
	if (mState == 0) {
		piki->startMotion(PaniMotionInfo(PIKIANIM_JKoke, piki), PaniMotionInfo(PIKIANIM_JKoke));
		mState = 1;
	}
}

/*
 * --INFO--
 * Address:	800D3850
 * Size:	000170
 */
void PikiFlownState::exec(Piki* piki)
{
	PaniAnimator& upper = piki->mPikiAnimMgr.getUpperAnimator();
	if (upper.getCurrentMotionIndex() == PIKIANIM_Kuttuku) {
		PRINT("piki %x motion KENKA!\n", piki);
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

/*
 * --INFO--
 * Address:	800D39C0
 * Size:	000230
 */
void PikiFlownState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mState == 1) {
			mState  = 2;
			f32 min = C_PIKI_PROP(piki)._32C();
			f32 max = C_PIKI_PROP(piki)._31C();
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

/*
 * --INFO--
 * Address:	800D3BF0
 * Size:	0000A0
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

/*
 * --INFO--
 * Address:	800D3C90
 * Size:	000050
 */
PikiFallMeckState::PikiFallMeckState()
    : PikiState(PIKISTATE_FallMeck, "FALLMECK")
{
}

/*
 * --INFO--
 * Address:	800D3CE0
 * Size:	000084
 */
void PikiFallMeckState::init(Piki* piki)
{
	PRINT("--- fall start\n");
	piki->startMotion(PaniMotionInfo(PIKIANIM_Fall, piki), PaniMotionInfo(PIKIANIM_Fall));
	piki->endStickMouth();
	piki->mSwallowMouthPart = nullptr;
}

/*
 * --INFO--
 * Address:	800D3D64
 * Size:	000004
 */
void PikiFallMeckState::exec(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D3D68
 * Size:	000288
 */
void PikiFallMeckState::procBounceMsg(Piki* piki, MsgBounce*)
{
	int attr = ATTR_NULL;
	if (piki->mGroundTriangle) {
		attr = MapCode::getAttribute(piki->mGroundTriangle);
	}

	if (!piki->hasBomb() && Piki::isSafeMePos(piki->mPosition) && !MapCode::isBald(piki->mGroundTriangle) && attr != ATTR_Water) {
		PikiHeadMgr::buryMode = true;
		PikiHeadItem* sprout  = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead);
		PikiHeadMgr::buryMode = false;

		if (sprout) {
			Vector3f pos(piki->mPosition);
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

/*
 * --INFO--
 * Address:	800D3FF0
 * Size:	000004
 */
void PikiFallMeckState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D3FF4
 * Size:	00004C
 */
PikiFallState::PikiFallState()
    : PikiState(PIKISTATE_Fall, "FALL")
{
}

/*
 * --INFO--
 * Address:	800D4040
 * Size:	000088
 */
void PikiFallState::init(Piki* piki)
{
	PRINT("--- fall start\n");
	piki->startMotion(PaniMotionInfo(PIKIANIM_Fall, piki), PaniMotionInfo(PIKIANIM_Fall));
	mState = 0;
}

/*
 * --INFO--
 * Address:	800D40C8
 * Size:	000004
 */
void PikiFallState::exec(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D40CC
 * Size:	00007C
 */
void PikiFallState::procBounceMsg(Piki* piki, MsgBounce*)
{
	PRINT("fall : got bounce\n");
	mState = 1;
	piki->startMotion(PaniMotionInfo(PIKIANIM_JKoke, piki), PaniMotionInfo(PIKIANIM_JKoke));
}

/*
 * --INFO--
 * Address:	800D4148
 * Size:	0000D4
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

/*
 * --INFO--
 * Address:	800D421C
 * Size:	000004
 */
void PikiFallState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D4220
 * Size:	00005C
 */
PikiCliffState::PikiCliffState()
    : PikiState(PIKISTATE_Cliff, "CLIFF")
{
}

/*
 * --INFO--
 * Address:	800D427C
 * Size:	000138
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
	PRINT("%x cliff start :: %s\n", piki, mCliffHangType ? "BURAN" : "OTIKAKE"); // 'hang' and 'fall' (i think)
	mInitialFaceDir = piki->mFaceDirection;
}

/*
 * --INFO--
 * Address:	800D43B4
 * Size:	00003C
 */
void PikiCliffState::exec(Piki* piki)
{
	if (!piki->mGroundTriangle) {
		PRINT("piki %x: no floor !\n", piki);
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

/*
 * --INFO--
 * Address:	800D43F0
 * Size:	0001A4
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

	f32 dist = piki->mGroundTriangle->mEdgePlanes[planeIdx].dist(piki->mPosition);
	if (dist < piki->mCollisionRadius + 0.2f) {
		f32 x     = piki->mPosition.x;
		f32 z     = piki->mPosition.z;
		f32 currY = piki->mPosition.y;
		x += dir.x * piki->mCollisionRadius * 1.5f;
		z += dir.z * piki->mCollisionRadius * 1.5f;
		f32 botY = mapMgr->getMinY(x, z, true);
		if (currY - botY >= 5.0f * piki->getCentreSize()) {
			return true;
		}

		PRINT("currY = %.1f botY = %.1f\n", currY, botY);
	}

	return false;
}

/*
 * --INFO--
 * Address:	800D4594
 * Size:	0004A4
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
			PRINT("otikake motion start\n");
			piki->startMotion(PaniMotionInfo(PIKIANIM_Otikake, piki), PaniMotionInfo(PIKIANIM_Otikake));
			break;

		case 3:
			if (!piki->mGroundTriangle) {
				PRINT("piki fall (otiru) %x\n", piki);
				transit(piki, PIKISTATE_Fall);
				return;
			}
			PRINT("otiru escaped\n");
			transit(piki, PIKISTATE_Normal);
			break;

		case 1:
			PRINT("goto normal !?\n");
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
						f32 dist = plane->dist(piki->mPosition);
						PRINT("dist is %.1f ( radius=%f : centresize=%f\n", dist, piki->mCollisionRadius, piki->getCentreSize());
						if (dist > -0.2f && dist < 3.0f) {
							PRINT("piki%x : ####### start buran motion :: floor = %s\n", piki, piki->mGroundTriangle ? "on floor" : "air");
							mState       = 2;
							mLoopCounter = int((2.0f * gsys->getRand(1.0f))) + 2;
							break;
						}
						PRINT("buran is not executable : dist is too far\n");
						transit(piki, PIKISTATE_Normal);
						break;
					}
					PRINT("buran is not executable : no plane\n");
					transit(piki, PIKISTATE_Normal);
					break;
				}
				PRINT("buran is not executable : no floorCollTri\n");
				startFall(piki);
				break;
			}

			if (piki->mGroundTriangle) {
				PRINT("piki escaped from falling!\n");
				transit(piki, PIKISTATE_Normal);
				break;
			}

			PRINT("fall start : \n");
			startFall(piki);
			break;

		case 2:
			mLoopCounter--;
			if (mLoopCounter > 0) {
				break;
			}

			piki->mPosition = piki->getCentre();
			PRINT("piki %x : do fall\n", piki);
			transit(piki, PIKISTATE_Fall);
			break;
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	800D4A38
 * Size:	000004
 */
void PikiCliffState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D4A3C
 * Size:	00004C
 */
PikiGoHangState::PikiGoHangState()
    : PikiState(PIKISTATE_GoHang, "GOHANG")
{
}

/*
 * --INFO--
 * Address:	800D4A88
 * Size:	00005C
 */
void PikiGoHangState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
}

/*
 * --INFO--
 * Address:	800D4AE4
 * Size:	000174
 */
void PikiGoHangState::exec(Piki* piki)
{
	CollPart* naviHand = piki->mNavi->mCollInfo->getSphere('rhnd');
	Vector3f dir       = naviHand->mCentre - piki->mPosition;
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

/*
 * --INFO--
 * Address:	800D4C58
 * Size:	000004
 */
void PikiGoHangState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D4C5C
 * Size:	00004C
 */
PikiHangedState::PikiHangedState()
    : PikiState(PIKISTATE_Hanged, "HANGED")
{
}

/*
 * --INFO--
 * Address:	800D4CA8
 * Size:	000038
 */
void PikiHangedState::procAnimMsg(Piki*, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		SeSystem::playPlayerSe(SE_PIKI_FLYREADY);
		break;
	}
}

/*
 * --INFO--
 * Address:	800D4CE0
 * Size:	0000B4
 */
void PikiHangedState::init(Piki* piki)
{
	piki->mMotionSpeed = 30.0f;
	piki->startMotion(PaniMotionInfo(PIKIANIM_Hang, piki), PaniMotionInfo(PIKIANIM_Hang));
	piki->mHasCollChangedVelocity = 0;
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	800D4D94
 * Size:	000044
 */
void PikiHangedState::exec(Piki* piki)
{
	if (piki->mNavi->getCurrState()->getID() != NAVISTATE_ThrowWait) {
		transit(piki, PIKISTATE_Normal);
	}
}

/*
 * --INFO--
 * Address:	800D4DD8
 * Size:	000024
 */
void PikiHangedState::cleanup(Piki* piki)
{
	SeSystem::stopPlayerSe(SE_PIKI_FLYREADY);
}

/*
 * --INFO--
 * Address:	800D4DFC
 * Size:	000050
 */
PikiWaterHangedState::PikiWaterHangedState()
    : PikiState(PIKISTATE_WaterHanged, "WATER_HANGED")
{
}

/*
 * --INFO--
 * Address:	800D4E4C
 * Size:	000038
 */
void PikiWaterHangedState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		SeSystem::playPlayerSe(SE_PIKI_FLYREADY);
		break;
	}
}

/*
 * --INFO--
 * Address:	800D4E84
 * Size:	0000B4
 */
void PikiWaterHangedState::init(Piki* piki)
{
	piki->mMotionSpeed = 30.0f;
	piki->startMotion(PaniMotionInfo(PIKIANIM_Hang, piki), PaniMotionInfo(PIKIANIM_Hang));
	piki->mHasCollChangedVelocity = 0;
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	800D4F38
 * Size:	000044
 */
void PikiWaterHangedState::exec(Piki* piki)
{
	if (piki->mNavi->getCurrState()->getID() != NAVISTATE_ThrowWait) {
		transit(piki, PIKISTATE_Normal);
	}
}

/*
 * --INFO--
 * Address:	800D4F7C
 * Size:	000024
 */
void PikiWaterHangedState::cleanup(Piki* piki)
{
	SeSystem::stopPlayerSe(SE_PIKI_FLYREADY);
}

/*
 * --INFO--
 * Address:	800D4FA0
 * Size:	00004C
 */
PikiEmitState::PikiEmitState()
    : PikiState(PIKISTATE_Emit, "EMIT")
{
}

/*
 * --INFO--
 * Address:	800D4FEC
 * Size:	0000A4
 */
void PikiEmitState::init(Piki* piki)
{
	piki->mMotionSpeed = 30.0f;
	piki->startMotion(PaniMotionInfo(PIKIANIM_WaveJmp, piki), PaniMotionInfo(PIKIANIM_WaveJmp));
	piki->stopAI();
	piki->mHasCollChangedVelocity = 0;
	mHasLanded                    = true;
}

/*
 * --INFO--
 * Address:	800D5090
 * Size:	000040
 */
void PikiEmitState::exec(Piki* piki)
{
	if (!mHasLanded) {
		piki->mVelocity.set(0.0f, 0.0f, 0.0f);
		piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}
}

/*
 * --INFO--
 * Address:	800D50D0
 * Size:	000010
 */
void PikiEmitState::cleanup(Piki* piki)
{
	piki->restartAI();
}

/*
 * --INFO--
 * Address:	800D50E0
 * Size:	00008C
 */
void PikiEmitState::procBounceMsg(Piki* piki, MsgBounce*)
{
	if (mHasLanded) {
		mHasLanded = false;
		piki->startMotion(PaniMotionInfo(PIKIANIM_Umaru, piki), PaniMotionInfo(PIKIANIM_Umaru));
	}
}

/*
 * --INFO--
 * Address:	800D516C
 * Size:	0000B4
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

/*
 * --INFO--
 * Address:	800D5220
 * Size:	00008C
 */
PikiFlyingState::PikiFlyingState()
    : PikiState(PIKISTATE_Flying, "FLYING")
{
}

/*
 * --INFO--
 * Address:	800D52AC
 * Size:	000024
 */
void PikiFlyingState::stopEffect()
{
	mSparkleEffect.stop();
}

/*
 * --INFO--
 * Address:	800D52D0
 * Size:	000024
 */
void PikiFlyingState::restartEffect()
{
	mSparkleEffect.restart();
}

/*
 * --INFO--
 * Address:	800D52F4
 * Size:	0000B0
 */
void PikiFlyingState::init(Piki* piki)
{
	PRINT("flying state init\n");
	PRINT("piki is %s\n", piki->isHolding() ? "holding" : "not holding");
	piki->mMotionSpeed = 30.0f;
	piki->startMotion(PaniMotionInfo(PIKIANIM_RollJmp), PaniMotionInfo(PIKIANIM_RollJmp));
	piki->stopAI();
	piki->mHasCollChangedVelocity = 0;
	SeSystem::playPlayerSe(SE_PIKI_FLY);
	piki->mWantToStick = true;
	mIsFlowerGliding   = false;
	mSparkleEffect.init(piki->mPosition, EffectMgr::EFF_SD_Sparkle);
	mGroundTouchFrames = 0;
	mHasBounced        = false;
}

/*
 * --INFO--
 * Address:	800D53A4
 * Size:	0003C0
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

	mSparkleEffect.updatePos(piki->mPosition);

	f32 val1 = AIConstant::_instance->mConstants.mGravity() * 0.8f;
	f32 val2 = AIConstant::_instance->mConstants.mGravity() * C_PIKI_PROP(piki)._37C();
	f32 f    = 0.15f;
	f32 val3 = val1 * f - 0.5f * 0.15f * (val1 - val2) - val2 * f;
	if (!mIsFlowerGliding && piki->mHappa == Flower && piki->mVelocity.y <= 0.0f) {
		mIsFlowerGliding = true;
		piki->startMotion(PaniMotionInfo(PIKIANIM_Hang), PaniMotionInfo(PIKIANIM_Hang));
		f32 val4;
		if (piki->mColor == Yellow) {
			val4 = C_NAVI_PROP(piki->mNavi)._19C();
		} else {
			val4 = C_NAVI_PROP(piki->mNavi)._17C();
		}

		f32 val5               = (speedy_sqrtf(val3 * val3 + 2.0f * val4 * val2) + -val3) / val2;
		f32 val6               = C_NAVI_PROP(piki->mNavi)._1AC() * 0.5f;
		f32 val7               = val6 / val5;
		mHorizontalDirection.x = piki->mVelocity.x;
		mHorizontalDirection.y = 0.0f;
		mHorizontalDirection.z = piki->mVelocity.z;
		mHorizontalDirection.normalise();
		f32 hSpeed              = speedy_sqrtf(piki->mVelocity.x * piki->mVelocity.x + piki->mVelocity.z * piki->mVelocity.z);
		mInitialHorizontalSpeed = hSpeed;
		f32 halfHorizSpeed      = hSpeed * 0.5f;
		mTargetHorizontalSpeed  = halfHorizSpeed;
		val5                    = ((hSpeed * val6) - (hSpeed - (hSpeed - halfHorizSpeed) * 0.5f - halfHorizSpeed) * 0.15f) / halfHorizSpeed;
		piki->mVelocity.x *= val7;
		piki->mVelocity.z *= val7;
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
	f32 rval = (gsys->getRand(1.0f) - 0.5f) * 0.01f;

	STACK_PAD_TERNARY(rval, 1);

	f32 val;
	if (mGlideTimer < 0.15f) {
		val = val1 - (val1 - val2) / 0.15f * mGlideTimer;
	} else {
		val = val2;
	}

	piki->mVelocity.y += ((AIConstant::_instance->mConstants.mGravity() - val) * (rval + 1.0f)) * gsys->getFrameTime();

	STACK_PAD_VAR(4);
}

/*
 * --INFO--
 * Address:	800D5764
 * Size:	000044
 */
void PikiFlyingState::cleanup(Piki* piki)
{
	mSparkleEffect.kill();
	piki->restartAI();
	piki->mWantToStick = false;
}

/*
 * --INFO--
 * Address:	800D57A8
 * Size:	0006DC
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
			PRINT("FLYING COLLIDE BRIDGE bridge is %s!!!\n", obj->workable(piki->mPosition) ? "workable" : "dame!");
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
		Vector3f effPos = collider->mPosition - piki->mPosition;
		effPos.normalise();
		Vector3f effDir(effPos);
		effPos.multiply(piki->getCentreSize() * 1.5f);
		effPos.add(piki->mPosition);
		InteractHitEffect hit(piki, effPos, effDir, msg->mEvent.mColliderPart);
		collider->stimulate(hit);
	}

	CollPart* part = msg->mEvent.mColliderPart;
	if (part && part->isBouncy()) {
		if (!mHasBounced) {
			Vector3f bounceDir = piki->mPosition - collider->mPosition;
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
		PRINT("FLYING .. collide\n");
		if (msg->mEvent.mColliderPart->isPlatformType()) {
			if (msg->mEvent.mColliderPart->isStickable()) {
				PRINT("flying ... stick to platform::%s(code %s)\n", msg->mEvent.mColliderPart->mCollInfo->mId.mStringID,
				      msg->mEvent.mColliderPart->mCollInfo->mCode.mStringID);
				piki->startStick(collider, msg->mEvent.mColliderPart);
				SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
			} else if (msg->mEvent.mColliderPart->isClimbable()) {
				PRINT("flying ... stick to platform::%s(code %s)\n", msg->mEvent.mColliderPart->mCollInfo->mId.mStringID,
				      msg->mEvent.mColliderPart->mCollInfo->mCode.mStringID);
				piki->startStick(collider, msg->mEvent.mColliderPart);
				SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
			}
		} else if ((msg->mEvent.mColliderPart->isCollisionType() || msg->mEvent.mColliderPart->isTubeType())
		           && msg->mEvent.mColliderPart->isStickable()) {
			PRINT("flying ... stick to sphere\n");
			piki->startStickObject(collider, msg->mEvent.mColliderPart, -1, 0.0f);
			SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
		}

		transit(piki, PIKISTATE_Normal);
		PRINT("++++++++++++++++++++++++++++++++\n");
		PRINT(" _stickPart = %x : %s\n", piki->mStickPart, piki->mStickPart ? piki->mStickPart->mCollInfo->mId.mStringID : "nothing!");
		PRINT(" _stickPart = %x\n", piki->mStickPart);
		piki->mActiveAction->mCurrActionIdx = PikiAction::Attack;
		PRINT("----------------\n");
		piki->mActiveAction->mChildActions[PikiAction::Attack].initialise(collider);
		PRINT("----------------\n");
		piki->mMode = PikiMode::AttackMode;
		PRINT(" _stickPart = %x\n", piki->mStickPart);
		PRINT("(%x) stick OBJECT attack start ? ########\n", piki);
		PRINT(" _stickPart = %x\n", piki->mStickPart); // this is excessive.
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
		PRINT("got here\n");
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
		PRINT("collide restart!!\n");
		piki->restartAI();
		transit(piki, PIKISTATE_Normal);
	}
}

/*
 * --INFO--
 * Address:	800D5E84
 * Size:	000004
 */
void PikiFlyingState::procStickMsg(Piki*, MsgStick*)
{
}

/*
 * --INFO--
 * Address:	800D5E88
 * Size:	0000E8
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
	seSystem->playPikiSound(SEF_PIKI_LAND, piki->mPosition);
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

/*
 * --INFO--
 * Address:	800D5F70
 * Size:	00004C
 */
PikiGrowState::PikiGrowState()
    : PikiState(PIKISTATE_Grow, "GROW")
{
}

/*
 * --INFO--
 * Address:	800D5FBC
 * Size:	00007C
 */
void PikiGrowState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp1, piki), PaniMotionInfo(PIKIANIM_GrowUp1));
	piki->mFormationPriority = 0;
}

/*
 * --INFO--
 * Address:	800D6038
 * Size:	000004
 */
void PikiGrowState::exec(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D603C
 * Size:	000004
 */
void PikiGrowState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D6040
 * Size:	000044
 */
void PikiGrowState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		transit(piki, PIKISTATE_Bury);
		break;
	}
}

/*
 * --INFO--
 * Address:	800D6084
 * Size:	000050
 */
PikiKinokoChangeState::PikiKinokoChangeState()
    : PikiState(PIKISTATE_KinokoChange, "KINOKO_CHANGE")
{
}

/*
 * --INFO--
 * Address:	800D60D4
 * Size:	0000AC
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

/*
 * --INFO--
 * Address:	800D6180
 * Size:	00002C
 */
void PikiKinokoChangeState::restart(Piki* piki)
{
	init(piki);
}

/*
 * --INFO--
 * Address:	800D61AC
 * Size:	000078
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

/*
 * --INFO--
 * Address:	800D6224
 * Size:	000004
 */
void PikiKinokoChangeState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D6228
 * Size:	000094
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

/*
 * --INFO--
 * Address:	800D62BC
 * Size:	00004C
 */
PikiGrowupState::PikiGrowupState()
    : PikiState(PIKISTATE_GrowUp, "GROWUP")
{
}

/*
 * --INFO--
 * Address:	800D6308
 * Size:	0000C8
 */
void PikiGrowupState::init(Piki* piki)
{
	if (piki->mFloweringTimer < 1) {
		piki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp1, piki), PaniMotionInfo(PIKIANIM_GrowUp1));
	} else {
		piki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp2, piki), PaniMotionInfo(PIKIANIM_GrowUp2));
	}
}

/*
 * --INFO--
 * Address:	800D63D0
 * Size:	000098
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

/*
 * --INFO--
 * Address:	800D6468
 * Size:	000004
 */
void PikiGrowupState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D646C
 * Size:	000134
 */
void PikiGrowupState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		piki->mFloweringTimer++;
		seSystem->playPikiSound(SEF_PIKI_GROW4, piki->mPosition);
		piki->setFlower(Flower);
		playerState->mResultFlags.setOn(RESFLAG_PikminSeeds);
		if (!playerState->mDemoFlags.isFlag(DEMOFLAG_FirstNectar) && !gameflow.mMoviePlayer->mIsActive && piki->aiCullable()) {
			playerState->mDemoFlags.setFlagOnly(DEMOFLAG_FirstNectar);
			gameflow.mGameInterface->message(0, 22);
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

/*
 * --INFO--
 * Address:	800D65A0
 * Size:	00004C
 */
PikiWaveState::PikiWaveState()
    : PikiState(PIKISTATE_Wave, "WAVE")
{
}

/*
 * --INFO--
 * Address:	800D65EC
 * Size:	000004
 */
void PikiWaveState::init(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D65F0
 * Size:	000004
 */
void PikiWaveState::exec(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D65F4
 * Size:	000004
 */
void PikiWaveState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D65F8
 * Size:	000030
 */
void PikiWaveState::resume(Piki* piki)
{
	transit(piki, PIKISTATE_Normal);
}

/*
 * --INFO--
 * Address:	800D6628
 * Size:	000004
 */
void PikiWaveState::restart(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D662C
 * Size:	000048
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

/*
 * --INFO--
 * Address:	800D6674
 * Size:	00004C
 */
PikiPushState::PikiPushState()
    : PikiState(PIKISTATE_Push, "PUSH")
{
}

/*
 * --INFO--
 * Address:	800D66C0
 * Size:	000088
 */
void PikiPushState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Push, piki), PaniMotionInfo(PIKIANIM_Run));
	mIsFinishing = false;
}

/*
 * --INFO--
 * Address:	800D6748
 * Size:	000150
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

/*
 * --INFO--
 * Address:	800D6898
 * Size:	00000C
 */
void PikiPushState::cleanup(Piki* piki)
{
	piki->mWallObj = nullptr;
}

/*
 * --INFO--
 * Address:	800D68A4
 * Size:	000030
 */
void PikiPushState::resume(Piki* piki)
{
	transit(piki, PIKISTATE_Normal);
}

/*
 * --INFO--
 * Address:	800D68D4
 * Size:	000004
 */
void PikiPushState::restart(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D68D8
 * Size:	000038
 */
void PikiPushState::procOffWallMsg(Piki* piki, MsgOffWall*)
{
	piki->mPikiAnimMgr.finishMotion(piki);
}

/*
 * --INFO--
 * Address:	800D6910
 * Size:	000078
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

/*
 * --INFO--
 * Address:	800D6988
 * Size:	000050
 */
PikiPushPikiState::PikiPushPikiState()
    : PikiState(PIKISTATE_PushPiki, "PUSHPIKI")
{
}

/*
 * --INFO--
 * Address:	800D69D8
 * Size:	000090
 */
void PikiPushPikiState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Push, piki), PaniMotionInfo(PIKIANIM_Push));
	mCollisionFrameCount = 1;
	mIsFinishing         = false;
}

/*
 * --INFO--
 * Address:	800D6A68
 * Size:	0000F4
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

/*
 * --INFO--
 * Address:	800D6B5C
 * Size:	00000C
 */
void PikiPushPikiState::cleanup(Piki* piki)
{
	piki->mPushTargetPiki = nullptr;
}

/*
 * --INFO--
 * Address:	800D6B68
 * Size:	000030
 */
void PikiPushPikiState::resume(Piki* piki)
{
	transit(piki, PIKISTATE_Normal);
}

/*
 * --INFO--
 * Address:	800D6B98
 * Size:	000004
 */
void PikiPushPikiState::restart(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D6B9C
 * Size:	0000A4
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

/*
 * --INFO--
 * Address:	800D6C40
 * Size:	000004
 */
void PikiPushPikiState::procWallMsg(Piki*, MsgWall*)
{
}

/*
 * --INFO--
 * Address:	800D6C44
 * Size:	000080
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

/*
 * --INFO--
 * Address:	800D6CC4
 * Size:	00004C
 */
PikiBuryState::PikiBuryState()
    : PikiState(PIKISTATE_Bury, "BURY")
{
}

/*
 * --INFO--
 * Address:	800D6D10
 * Size:	000004
 */
void PikiBuryState::init(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D6D14
 * Size:	000200
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
		Vector3f pos(piki->mPosition);
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

/*
 * --INFO--
 * Address:	800D6F14
 * Size:	000004
 */
void PikiBuryState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D6F18
 * Size:	000050
 */
PikiNukareWaitState::PikiNukareWaitState()
    : PikiState(PIKISTATE_NukareWait, "NUKARE_WAIT")
{
}

/*
 * --INFO--
 * Address:	800D6F68
 * Size:	00014C
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
		gameflow.mGameInterface->message(14, 0);
	}
}

/*
 * --INFO--
 * Address:	800D70B4
 * Size:	000078
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

/*
 * --INFO--
 * Address:	800D712C
 * Size:	000004
 */
void PikiNukareWaitState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D7130
 * Size:	00004C
 */
PikiNukareState::PikiNukareState()
    : PikiState(PIKISTATE_Nukare, "NUKARE")
{
}

/*
 * --INFO--
 * Address:	800D717C
 * Size:	0000AC
 */
void PikiNukareState::init(Piki* piki)
{
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
	playerState->mDemoFlags.setFlagOnly(DEMOFLAG_NoPikminTimeout);
	piki->finishLook();
	gameflow.mGameInterface->message(14, 0);
}

/*
 * --INFO--
 * Address:	800D7228
 * Size:	000004
 */
void PikiNukareState::exec(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D722C
 * Size:	000264
 */
void PikiNukareState::cleanup(Piki* piki)
{
	if (playerState->isTutorial() && !playerState->mDemoFlags.isFlag(DEMOFLAG_Pluck15thPikmin) && GameStat::allPikis >= 15) {
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_Pluck15thPikmin);
		gameflow.mGameInterface->message(0, 30);
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

	gameflow.mGameInterface->message(14, 1);
}

/*
 * --INFO--
 * Address:	800D7490
 * Size:	000190
 */
void PikiNukareState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		rumbleMgr->start(RUMBLE_Unk0, 0, nullptr);
		if (piki->mGroundTriangle && MapCode::getAttribute(piki->mGroundTriangle) == ATTR_Water) {
			effectMgr->create(EffectMgr::EFF_P_Bubbles, piki->mPosition, nullptr, nullptr);
		} else {
			effectMgr->create(EffectMgr::EFF_SD_DirtCloud, piki->mPosition, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_SD_DirtSpray, piki->mPosition, nullptr, nullptr);
		}
		break;
	case KEY_Finished:
		piki->mRotation.y    = piki->mNavi->mFaceDirection;
		piki->mFaceDirection = piki->mRotation.y;
		piki->mPosition      = piki->mShadowPos;
		f32 minY             = mapMgr->getMinY(piki->mPosition.x, piki->mPosition.z, true);
		if (minY > piki->mPosition.y) {
			PRINT("*** ABUNAI !!\n");
			piki->mPosition.y = minY + 1.0f;
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

/*
 * --INFO--
 * Address:	800D7620
 * Size:	000050
 */
PikiAutoNukiState::PikiAutoNukiState()
    : PikiState(PIKISTATE_AutoNuki, "AUTONUKI")
{
}

/*
 * --INFO--
 * Address:	800D7670
 * Size:	0000DC
 */
void PikiAutoNukiState::init(Piki* piki)
{
	Choice motionChoice[1] = { PIKIANIM_Kaifuku, 1.0f }; // lol
	int motionIdx          = selectRandomly(motionChoice, 1);
	piki->mPikiAnimMgr.startMotion(PaniMotionInfo(motionIdx, piki), PaniMotionInfo(motionIdx));
	mToCreateEffect = false;
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	800D774C
 * Size:	000078
 */
void PikiAutoNukiState::exec(Piki* piki)
{
	if (mToCreateEffect) {
		Vector3f pos(piki->mPosition); // lol
		effectMgr->create(EffectMgr::EFF_SD_DirtCloud, piki->mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_SD_DirtSpray, piki->mPosition, nullptr, nullptr);
		mToCreateEffect = false;
	}
}

/*
 * --INFO--
 * Address:	800D77C4
 * Size:	000004
 */
void PikiAutoNukiState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D77C8
 * Size:	00009C
 */
void PikiAutoNukiState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		mToCreateEffect = true;
		SeSystem::playPlayerSe(SE_PIKI_PULLED);
		break;
	case KEY_Finished:
		piki->mPosition = piki->mShadowPos;
		transit(piki, PIKISTATE_Normal);
		piki->changeMode(PikiMode::FormationMode, piki->mNavi);
		break;
	}
}

/*
 * --INFO--
 * Address:	800D7864
 * Size:	00004C
 */
PikiPressedState::PikiPressedState()
    : PikiState(PIKISTATE_Pressed, "PRESSED")
{
}

/*
 * --INFO--
 * Address:	800D78B0
 * Size:	000024
 */
void PikiPressedState::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (msg->mEvent.mCollider->mObjType == OBJTYPE_Teki) {
		mStunTimer    = 1.5f;
		mIsInvincible = true;
	}
}

/*
 * --INFO--
 * Address:	800D78D4
 * Size:	000034
 */
void PikiPressedState::init(Piki* piki)
{
	f32 scale = 2.0f * C_PIKI_PROP(piki).mPikiDisplayScale();
	piki->mScale.set(scale, 0.01f, scale);
	mStunTimer    = 1.5f;
	mIsInvincible = true;
	PRINT("pressed init !\n");
}

/*
 * --INFO--
 * Address:	800D7908
 * Size:	000140
 */
void PikiPressedState::exec(Piki* piki)
{
	if (!mIsInvincible) {
		piki->mDeathTimer -= gsys->getFrameTime();
	}

	if (piki->mDeathTimer > C_PIKI_PROP(piki)._15C() - C_PIKI_PROP(piki)._16C() && piki->mHealth <= 0.0f) {
		PRINT("*** PRESS DIE ! timer = %.1f\n", piki->mDeathTimer);
		transit(piki, PIKISTATE_Dead);
		return;
	}

	if (piki->mDeathTimer < 0.0f) {
		piki->mDeathTimer = 0.0f;
		transit(piki, PIKISTATE_Normal);
		f32 scale = C_PIKI_PROP(piki).mPikiDisplayScale();
		piki->mScale.set(scale, scale, scale);
	}

	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	if (mStunTimer > 0.0f) {
		mStunTimer -= gsys->getFrameTime();
	} else {
		mIsInvincible = false;
	}
}

/*
 * --INFO--
 * Address:	800D7A48
 * Size:	000004
 */
void PikiPressedState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D7A4C
 * Size:	00004C
 */
PikiDyingState::PikiDyingState()
    : PikiState(PIKISTATE_Dying, "DYING")
{
}

/*
 * --INFO--
 * Address:	800D7A98
 * Size:	00011C
 */
void PikiDyingState::init(Piki* piki)
{
	piki->mActiveAction->abandon(nullptr);
	Choice motionChoices[3] = {
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

/*
 * --INFO--
 * Address:	800D7BB4
 * Size:	000034
 */
void PikiDyingState::exec(Piki* piki)
{
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	800D7BE8
 * Size:	000004
 */
void PikiDyingState::cleanup(Piki* piki)
{
}

/*
 * --INFO--
 * Address:	800D7BEC
 * Size:	000090
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

/*
 * --INFO--
 * Address:	800D7C7C
 * Size:	00004C
 */
PikiDeadState::PikiDeadState()
    : PikiState(PIKISTATE_Dead, "DEAD")
{
}

/*
 * --INFO--
 * Address:	800D7CC8
 * Size:	000034
 */
void PikiDeadState::init(Piki* piki)
{
	piki->mDeathTimer = 1.5f;
	// this is probably some optimised OR check but i haven't figured out which. works for now.
	if (1 - piki->mMode == 0) { }
	piki->endStickObject();
}

/*
 * --INFO--
 * Address:	800D7CFC
 * Size:	00009C
 */
void PikiDeadState::exec(Piki* piki)
{
	f32 scale = piki->mDeathTimer / 1.5f;
	piki->mScale.set(scale, scale, scale);
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

/*
 * --INFO--
 * Address:	800D7D98
 * Size:	00001C
 */
void PikiDeadState::cleanup(Piki* piki)
{
	piki->mScale.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	800D7DB4
 * Size:	000060
 */
PikiEmotionState::PikiEmotionState()
    : PikiState(PIKISTATE_Emotion, "EMOTION")
    , mCheerCount(0)
{
}

/*
 * --INFO--
 * Address:	800D7E14
 * Size:	000784
 */
void PikiEmotionState::init(Piki* piki)
{
	mGazeFlag = 0;
	if (piki->mEmotion == PikiEmotion::None) {
		return;
	}

	switch (piki->mEmotion) {
	case PikiEmotion::Excited: {
		Choice motionChoices[2] = {
			{ PIKIANIM_Jump_B1, 0.5f },
			{ PIKIANIM_Gattu, 0.5f },
		};

		int soundChoices[2] = {
			SEF_PIKI_JUMP1,
			SEF_PIKI_ANGRY1,
		};

		int randIdx  = (2.0f * gsys->getRand(1.0f)) * 0.9999f;
		int motionID = motionChoices[randIdx].mValue;
		seSystem->playPikiSound(soundChoices[randIdx], piki->mPosition);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
		PRINT("play sound %d\n", motionID); // wrong variable kando
	} break;

	case PikiEmotion::Happy: {
		Choice motionChoices[3] = {
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
		seSystem->playPikiSound(soundChoices[randIdx], piki->mPosition);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
	} break;

	case PikiEmotion::Searching: {
		Choice motionChoices[2] = {
			{ PIKIANIM_Sagasu, 0.5f },
			{ PIKIANIM_Sagasu2, 0.5f },
		};

		int motionID = selectRandomly(motionChoices, 2);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
	} break;

	case PikiEmotion::Confused: {
		Choice motionChoices[2] = {
			{ PIKIANIM_Gakkari, 0.5f },
			{ PIKIANIM_Sagasu2, 0.5f },
		};

		int soundChoices[2] = {
			SEF_PIKI_GAKKARI,
			SEF_PIKI_SNEEZE,
		};

		int randIdx  = (2.0f * gsys->getRand(1.0f)) * 0.9999f;
		int motionID = motionChoices[randIdx].mValue;
		seSystem->playPikiSound(soundChoices[randIdx], piki->mPosition);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
	} break;

	case PikiEmotion::Sad: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Gakkari, piki), PaniMotionInfo(PIKIANIM_Gakkari));
		piki->mPikiAnimMgr.finishMotion(piki);
		seSystem->playPikiSound(SEF_PIKI_GAKKARI, piki->mPosition);
	} break;

	case PikiEmotion::ShookDry: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Mizuage, piki), PaniMotionInfo(PIKIANIM_Mizuage));
		piki->mPikiAnimMgr.finishMotion(piki);
		seSystem->playPikiSound(SEF_PIKI_BURUBURU, piki->mPosition);
	} break;

	case PikiEmotion::Victorious: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Jump_B1, piki), PaniMotionInfo(PIKIANIM_Jump_B1));
		piki->mPikiAnimMgr.finishMotion(piki);
		seSystem->playPikiSound(SEF_PIKI_YATTA, piki->mPosition);
	} break;

	case PikiEmotion::ShipPartGaze: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Wait, piki), PaniMotionInfo(PIKIANIM_Wait));
		piki->startLook(&piki->mCarryingShipPart->mPosition);
		mGazeFlag = 1;
	} break;

	case PikiEmotion::ShipPartCheer: {
		Choice motionChoices[5] = {
			{ PIKIANIM_Jump, 0.2f },   { PIKIANIM_Jump_B1, 0.2f }, { PIKIANIM_RotJump, 0.2f },
			{ PIKIANIM_Rinbow, 0.2f }, { PIKIANIM_Gattu, 0.2f },
		};

		int soundChoices[5] = {
			SEF_PIKI_JUMP1, SEF_PIKI_JUMP2, SEF_PIKI_JUMP3, SEF_PIKI_NOBI, SEF_PIKI_YATTA,
		};

		int randIdx  = (5.0f * gsys->getRand(1.0f)) * 0.9999f;
		int motionID = motionChoices[randIdx].mValue;
		seSystem->playPikiSound(soundChoices[randIdx], piki->mPosition);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
		if (mCheerCount == 0) {
			mCheerCount = 5;
			piki->startMotion(PaniMotionInfo(PIKIANIM_Wait, piki), PaniMotionInfo(PIKIANIM_Wait));
			piki->startLook(&piki->mCarryingShipPart->mPosition);
			mGazeFlag = 1;
		}
	} break;
	}
}

/*
 * --INFO--
 * Address:	800D8598
 * Size:	000004
 */
void PikiEmotionState::doDump()
{
	PRINT("gazeFlag=%d rapCnt=%d timer=%.1f gazePos(%.1f %.1f %.1f)\n", mGazeFlag, mCheerCount, mTimer, mGazePosition.x, mGazePosition.y,
	      mGazePosition.z);
}

/*
 * --INFO--
 * Address:	800D859C
 * Size:	0001B8
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
				mGazePosition = piki->mCarryingShipPart->mPosition;
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

/*
 * --INFO--
 * Address:	800D8754
 * Size:	000034
 */
void PikiEmotionState::cleanup(Piki* piki)
{
	piki->mEmotion          = PikiEmotion::None;
	piki->mCarryingShipPart = nullptr;
	piki->finishLook();
}

/*
 * --INFO--
 * Address:	800D8788
 * Size:	000084
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
