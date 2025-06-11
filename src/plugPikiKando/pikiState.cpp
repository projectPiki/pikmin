#include "PikiState.h"
#include "Navi.h"
#include "Interactions.h"
#include "AIConstant.h"
#include "MizuItem.h"
#include "PikiMgr.h"
#include "NaviState.h"
#include "gameflow.h"
#include "GameStat.h"
#include "CPlate.h"
#include "Interface.h"
#include "RumbleMgr.h"
#include "Pellet.h"
#include "PlayerState.h"
#include "WorkObject.h"
#include "NaviMgr.h"
#include "ItemMgr.h"
#include "teki.h"
#include "MoviePlayer.h"
#include "PikiHeadItem.h"
#include "BombItem.h"
#include "PikiAI.h"
#include "MapCode.h"
#include "UtilityKando.h"
#include "SoundMgr.h"
#include "MemStat.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

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
	_10 = (0.3f * gsys->getRand(1.0f));
	_14 = 0;
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

	switch (_14) {
	case 0:
		_10 -= gsys->getFrameTime();
		if (_10 < 0.0f) {
			_10 = 0.0f;
			piki->startMotion(PaniMotionInfo(PIKIANIM_Kizuku, piki), PaniMotionInfo(PIKIANIM_Kizuku));
			_14 = 1;
		}
		break;

	case 1:
		break;

	case 2:
		piki->mFaceDirection += _18;
		piki->mRotation.set(0.0f, _18, 0.0f);
		break;

	case 3:
		break;

	default:
		_10 -= gsys->getFrameTime();
		if (piki->mStickTarget) {
			piki->mFaceDirection = roundAng(piki->mFaceDirection + PI);
			transit(piki, PIKISTATE_Normal);
			return;
		}

		if (_10 < 0.0f) {
			_10                  = 0.0f;
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
		_14          = 2;
		Vector3f dir = piki->mNavi->mPosition - piki->mPosition;
		_18          = angDist(atan2f(dir.x, dir.z), piki->mFaceDirection) / 7.0f;
		break;

	case KEY_Action1:
		_14 = 3;
		break;

	case KEY_Finished:
		_14 = 4;
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
	_10 = 0;
	_14 = 0.0f;
	_1C = C_PIKI_PROP(piki)._2CC();
	_18 = 0;
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
	_10 = 0;
	_14 = 0.0f;
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
		_18                = 0;
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
					_18 = static_cast<Piki*>(collider);
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
	_10     = 0;
	mNectar = piki->mCurrNectar;
	_14     = 0;
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
	switch (_10) {
	case 1:
		if (mNectar->isAlive()) {
			MsgUser msg(0);
			MizuItem* nectar           = static_cast<MizuItem*>(mNectar);
			nectar->mCollidingCreature = piki;
			C_SAI(nectar)->procMsg(nectar, &msg);
		}
		_14 = 1;
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
		if (_10 != 1) {
			seSystem->playPikiSound(SEF_PIKI_DRINK, piki->mPosition);
		}
		_10 = 1;
		break;
	case KEY_LoopEnd:
		if (!mNectar->isAlive()) {
			piki->mPikiAnimMgr.finishMotion(piki);
			_10 = 2;
		}
		break;
	case KEY_Finished:
		if (_14) {
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
		_10 = 0;
	} else {
		_10 = 1;
		piki->startMotion(PaniMotionInfo(PIKIANIM_Oboreru, piki), PaniMotionInfo(PIKIANIM_Oboreru));
	}

	_12 = int(2.0f * gsys->getRand(1.0f)) + 6;
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	_14 = int((2.0f * gsys->getRand(1.0f)));
	if (piki->isHolding()) {
		InteractRelease release(piki, 1.0f);
		piki->getHoldCreature()->stimulate(release);
	}

	seSystem->playSoundDirect(5, SEW_PIKI_DROWN, piki->mPosition);
	_16 = 0;

	// we already did this, but sure
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mActiveAction->abandon(nullptr);
	if (piki->isStickTo()) {
		piki->endStickObject();
		piki->endStick();
	}

	_28 = false;
	PRINT("fake", _28 ? "fake" : "fake");
}

/*
 * --INFO--
 * Address:	800D11F0
 * Size:	0003DC
 */
void PikiDrownState::exec(Piki* piki)
{
	if (_10 != 2 && piki->mInWaterTimer == 0) {
		_16++;
		if (_16 > 1) {
			piki->mPosition.y += 20.0f;
			Vector3f vel(sinf(piki->mFaceDirection), 0.0f, cosf(piki->mFaceDirection));
			vel.multiply(80.0f);
			piki->mVelocity = vel;
			if (piki->isKinoko()) {
				transit(piki, PIKISTATE_Kinoko);
			} else {
				piki->mEmotion = PikiEmotion::Unk3;
				transit(piki, PIKISTATE_Emotion);
			}

			return;
		}
	} else {
		_16 = 0;
	}

	if (_10 == 1) {
		Vector3f dir = piki->mNavi->mPosition - piki->mPosition;
		dir.normalise();
		_1C = piki->getSpeed(0.5f) * dir;
	} else {
		_1C.set(0.0f, 0.0f, 0.0f);
	}

	if (!_28 || piki->isKinoko()) {
		piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	Vector3f velOffset = _1C - piki->mTargetVelocity;
	f32 diff           = velOffset.normalise();

	f32 speed = 15.0f;
	if (_28) {
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
		if (_10 == 2) {
			seSystem->playSoundDirect(5, SEW_PIKI_DEAD, piki->mPosition);
			piki->kill(false);
			break;
		}
		if (_10 == 1) {
			if (--_12 == 0) {
				piki->startMotion(PaniMotionInfo(PIKIANIM_Sizumu, piki), PaniMotionInfo(PIKIANIM_Sizumu));
				seSystem->playSoundDirect(5, SEW_PIKI_SINK, piki->mPosition);
				_10 = 2;
			} else {
				piki->startMotion(PaniMotionInfo(PIKIANIM_Oboreru, piki), PaniMotionInfo(PIKIANIM_Oboreru));
			}
			break;
		}
		if (_10 == 0) {
			_10 = 1;
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
	_10 = tekiMgr->findClosest(piki->mPosition, nullptr);
	initWalk(piki);
	piki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
	_24 = 0;
}

/*
 * --INFO--
 * Address:	800D187C
 * Size:	000268
 */
void PikiKinokoState::initWalk(Piki* piki)
{
	_14          = (2.0f * gsys->getRand(1.0f)) + 1.5f;
	Vector3f dir = _10->mPosition - piki->mPosition;
	f32 d        = dir.normalise();
	Vector3f orthoDir(dir.z, 0.0f, -dir.x);
	if (gsys->getRand(1.0f) > 0.5f) {
		orthoDir.multiply(-1.0f);
	}

	f32 r    = 0.2f * (gsys->getRand(1.0f) - 0.5f);
	orthoDir = orthoDir + r * dir;
	orthoDir.normalise();
	_18 = orthoDir;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stfd      f31, 0xB0(r1)
	  stfd      f30, 0xA8(r1)
	  stfd      f29, 0xA0(r1)
	  stw       r31, 0x9C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x98(r1)
	  addi      r30, r3, 0
	  bl        0x1467CC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x94(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  stw       r0, 0x90(r1)
	  lfs       f2, -0x68E8(r2)
	  lfd       f1, 0x90(r1)
	  lfs       f0, -0x68C0(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6898(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lwz       r3, 0x10(r30)
	  lfsu      f3, 0x94(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x98(r31)
	  lfs       f2, 0x4(r3)
	  fsubs     f31, f3, f1
	  lfs       f1, 0x8(r3)
	  fsubs     f30, f2, f0
	  lfs       f0, 0x9C(r31)
	  fsubs     f29, f1, f0
	  fmuls     f1, f31, f31
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC3CE4
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xC4
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0xC4:
	  stfs      f29, 0x74(r1)
	  fneg      f0, f31
	  lfs       f1, -0x3F64(r13)
	  stfs      f1, 0x78(r1)
	  stfs      f0, 0x7C(r1)
	  bl        0x14671C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x94(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x68E4(r2)
	  stw       r0, 0x90(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f3, 0x90(r1)
	  lfs       f0, -0x68B4(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x13C
	  lfs       f0, 0x74(r1)
	  lfs       f1, -0x6894(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x7C(r1)

	.loc_0x13C:
	  bl        0x1466B8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x94(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  addi      r6, r1, 0x30
	  stw       r0, 0x90(r1)
	  lfs       f2, -0x68E8(r2)
	  addi      r5, r1, 0x2C
	  lfd       f1, 0x90(r1)
	  addi      r4, r1, 0x28
	  lfs       f0, -0x68B4(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6890(r2)
	  addi      r3, r1, 0x58
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f2, f29, f0
	  fmuls     f1, f30, f0
	  fmuls     f0, f31, f0
	  stfs      f2, 0x30(r1)
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x28(r1)
	  bl        -0x9A904
	  lfs       f1, 0x74(r1)
	  lfs       f0, 0x58(r1)
	  lfs       f3, 0x78(r1)
	  lfs       f2, 0x5C(r1)
	  fadds     f0, f1, f0
	  lfs       f4, 0x7C(r1)
	  lfs       f1, 0x60(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x74(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x78(r1)
	  stfs      f0, 0x7C(r1)
	  lfs       f1, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  lfs       f2, 0x7C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC3E34
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x22C
	  lfs       f0, 0x74(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x7C(r1)

	.loc_0x22C:
	  lwz       r3, 0x74(r1)
	  lwz       r0, 0x78(r1)
	  stw       r3, 0x18(r30)
	  stw       r0, 0x1C(r30)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0x20(r30)
	  lwz       r0, 0xBC(r1)
	  lfd       f31, 0xB0(r1)
	  lfd       f30, 0xA8(r1)
	  lfd       f29, 0xA0(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D1AE4
 * Size:	000044
 */
void PikiKinokoState::exec(Piki* piki)
{
	switch (_24) {
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
	_14 -= gsys->getFrameTime();
	if (_14 < 0.0f) {
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
			moveDir = pikiDir * 0.4f + dir * 0.5f + _18 * 0.1f;
		}

		moveDir.normalise();
		piki->setSpeed(0.3f, moveDir);
	} else {
		piki->setSpeed(0.3f, _18);
	}

	Vector3f targetDir = _10->mPosition - piki->mPosition;
	f32 dist           = targetDir.normalise();
	if (dist < 100.0f) {
		return;
	}
	piki->setSpeed(0.5f, targetDir);

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2D8(r1)
	  stfd      f31, 0x2D0(r1)
	  stfd      f30, 0x2C8(r1)
	  stfd      f29, 0x2C0(r1)
	  stfd      f28, 0x2B8(r1)
	  stfd      f27, 0x2B0(r1)
	  stfd      f26, 0x2A8(r1)
	  stfd      f25, 0x2A0(r1)
	  stfd      f24, 0x298(r1)
	  stfd      f23, 0x290(r1)
	  stfd      f22, 0x288(r1)
	  stmw      r25, 0x26C(r1)
	  mr        r30, r3
	  mr        r31, r4
	  lwz       r5, 0x2DEC(r13)
	  lfs       f1, 0x14(r3)
	  lfs       f0, 0x28C(r5)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r3)
	  lfs       f1, 0x14(r3)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x2B0
	  bl        0x1464E0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x264(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  addi      r6, r1, 0xB4
	  stw       r0, 0x260(r1)
	  lfs       f2, -0x68E8(r2)
	  addi      r5, r1, 0xB0
	  lfd       f1, 0x260(r1)
	  addi      r4, r1, 0xAC
	  lfs       f0, -0x68C0(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6898(r2)
	  addi      r3, r1, 0x178
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lwz       r7, 0x10(r30)
	  lfs       f0, 0x9C(r31)
	  addi      r7, r7, 0x94
	  lfs       f1, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xB4(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x98(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xB0(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x94(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xAC(r1)
	  bl        -0x9AB00
	  lfs       f27, 0x178(r1)
	  lfs       f28, 0x17C(r1)
	  fmuls     f1, f27, f27
	  lfs       f29, 0x180(r1)
	  fmuls     f0, f28, f28
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC4000
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x130
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1
	  fdivs     f29, f29, f1

	.loc_0x130:
	  stfs      f29, 0x16C(r1)
	  fneg      f0, f27
	  lfs       f1, -0x3F64(r13)
	  stfs      f1, 0x170(r1)
	  stfs      f0, 0x174(r1)
	  bl        0x146400
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x264(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x68E4(r2)
	  stw       r0, 0x260(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f3, 0x260(r1)
	  lfs       f0, -0x68B4(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1A8
	  lfs       f0, 0x16C(r1)
	  lfs       f1, -0x6894(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x16C(r1)
	  lfs       f0, 0x170(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x170(r1)
	  lfs       f0, 0x174(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x174(r1)

	.loc_0x1A8:
	  bl        0x14639C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x264(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  addi      r6, r1, 0x88
	  stw       r0, 0x260(r1)
	  lfs       f2, -0x68E8(r2)
	  addi      r5, r1, 0x84
	  lfd       f1, 0x260(r1)
	  addi      r4, r1, 0x80
	  lfs       f0, -0x68B4(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6890(r2)
	  addi      r3, r1, 0x188
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f2, f29, f0
	  fmuls     f1, f28, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0x88(r1)
	  stfs      f1, 0x84(r1)
	  stfs      f0, 0x80(r1)
	  bl        -0x9AC20
	  lfs       f1, 0x16C(r1)
	  lfs       f0, 0x188(r1)
	  lfs       f3, 0x170(r1)
	  lfs       f2, 0x18C(r1)
	  fadds     f0, f1, f0
	  lfs       f4, 0x174(r1)
	  lfs       f1, 0x190(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x16C(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x170(r1)
	  stfs      f0, 0x174(r1)
	  lfs       f1, 0x16C(r1)
	  lfs       f0, 0x170(r1)
	  lfs       f2, 0x174(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC4150
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x298
	  lfs       f0, 0x16C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x16C(r1)
	  lfs       f0, 0x170(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x170(r1)
	  lfs       f0, 0x174(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x174(r1)

	.loc_0x298:
	  lwz       r3, 0x16C(r1)
	  lwz       r0, 0x170(r1)
	  stw       r3, 0x18(r30)
	  stw       r0, 0x1C(r30)
	  lwz       r0, 0x174(r1)
	  stw       r0, 0x20(r30)

	.loc_0x2B0:
	  addi      r28, r31, 0x1B8
	  lfs       f27, -0x3F60(r13)
	  mr        r3, r28
	  lfs       f28, -0x3F5C(r13)
	  lwz       r12, 0x0(r28)
	  li        r26, 0
	  lfs       f29, -0x3F58(r13)
	  li        r29, 0
	  lwz       r12, 0xC(r12)
	  lfs       f30, -0x3F54(r13)
	  mtlr      r12
	  lfs       f31, -0x3F50(r13)
	  lfs       f26, -0x3F4C(r13)
	  lfs       f25, -0x3F48(r13)
	  lfs       f24, -0x3F44(r13)
	  lfs       f23, -0x3F40(r13)
	  lfs       f22, -0x688C(r2)
	  blrl
	  mr        r27, r3
	  b         .loc_0x408

	.loc_0x300:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x324
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x33C

	.loc_0x324:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x33C:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x3EC
	  cmplw     r3, r31
	  addi      r25, r3, 0
	  beq-      .loc_0x3EC
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3EC
	  lfs       f1, 0x94(r25)
	  lfs       f2, 0x9C(r25)
	  lfs       f3, 0x94(r31)
	  lfs       f4, 0x9C(r31)
	  bl        -0x99884
	  fcmpo     cr0, f1, f22
	  bge-      .loc_0x3B8
	  lfs       f4, 0x94(r31)
	  fmr       f22, f1
	  lfs       f0, 0x94(r25)
	  li        r29, 0x1
	  lfs       f3, 0x98(r31)
	  lfs       f2, 0x98(r25)
	  lfs       f1, 0x9C(r31)
	  fsubs     f25, f4, f0
	  lfs       f0, 0x9C(r25)
	  fsubs     f24, f3, f2
	  fsubs     f23, f1, f0

	.loc_0x3B8:
	  lfs       f1, 0x94(r25)
	  addi      r26, r26, 0x1
	  lfs       f0, 0x98(r25)
	  lfs       f3, 0x9C(r25)
	  fadds     f27, f27, f1
	  lfs       f2, 0x70(r25)
	  fadds     f28, f28, f0
	  lfs       f1, 0x74(r25)
	  lfs       f0, 0x78(r25)
	  fadds     f29, f29, f3
	  fadds     f30, f30, f2
	  fadds     f31, f31, f1
	  fadds     f26, f26, f0

	.loc_0x3EC:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x408:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x430
	  li        r0, 0x1
	  b         .loc_0x45C

	.loc_0x430:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x458
	  li        r0, 0x1
	  b         .loc_0x45C

	.loc_0x458:
	  li        r0, 0

	.loc_0x45C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x300
	  cmpwi     r26, 0
	  ble-      .loc_0x6C8
	  fmuls     f1, f25, f25
	  fmuls     f0, f24, f24
	  fmuls     f2, f23, f23
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC436C
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x49C
	  fdivs     f25, f25, f1
	  fdivs     f24, f24, f1
	  fdivs     f23, f23, f1

	.loc_0x49C:
	  xoris     r0, r26, 0x8000
	  lfd       f1, -0x68D8(r2)
	  stw       r0, 0x264(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x68E8(r2)
	  stw       r0, 0x260(r1)
	  lfd       f0, 0x260(r1)
	  fsubs     f0, f0, f1
	  fdivs     f3, f2, f0
	  fmuls     f30, f30, f3
	  fmuls     f31, f31, f3
	  fmuls     f26, f26, f3
	  fmuls     f1, f30, f30
	  fmuls     f0, f31, f31
	  fmuls     f2, f26, f26
	  fmuls     f27, f27, f3
	  fadds     f0, f1, f0
	  fmuls     f28, f28, f3
	  fmuls     f29, f29, f3
	  fadds     f1, f2, f0
	  bl        -0xC43D8
	  lfs       f2, 0x94(r31)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0x9C(r31)
	  fsubs     f26, f27, f2
	  fsubs     f27, f28, f1
	  lfs       f1, 0xA0(r31)
	  fsubs     f28, f29, f0
	  bl        0x149B1C
	  fmr       f30, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x149CA4
	  fmuls     f2, f26, f26
	  lfs       f22, -0x3F3C(r13)
	  fmuls     f0, f27, f27
	  fmuls     f3, f28, f28
	  fmr       f31, f1
	  fadds     f0, f2, f0
	  fadds     f1, f3, f0
	  bl        -0xC4424
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x554
	  fdivs     f26, f26, f1
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1

	.loc_0x554:
	  lfs       f0, -0x68D0(r2)
	  rlwinm.   r0,r29,0,24,31
	  stfs      f0, 0x210(r1)
	  stfs      f0, 0x20C(r1)
	  stfs      f0, 0x208(r1)
	  beq-      .loc_0x5A8
	  lfs       f4, -0x3F34(r13)
	  lfs       f5, -0x3F38(r13)
	  fmuls     f2, f25, f4
	  fmuls     f3, f31, f5
	  fmuls     f1, f22, f5
	  fmuls     f0, f24, f4
	  fadds     f2, f3, f2
	  fmuls     f3, f23, f4
	  fmuls     f4, f30, f5
	  fadds     f1, f1, f0
	  stfs      f2, 0x208(r1)
	  fadds     f0, f4, f3
	  stfs      f1, 0x20C(r1)
	  stfs      f0, 0x210(r1)
	  b         .loc_0x660

	.loc_0x5A8:
	  lfs       f0, -0x3F2C(r13)
	  addi      r6, r1, 0xA0
	  lfs       f5, 0x20(r30)
	  addi      r5, r1, 0x9C
	  lfs       f6, -0x3F28(r13)
	  lfs       f4, 0x1C(r30)
	  fmuls     f2, f28, f0
	  lfs       f3, 0x18(r30)
	  fmuls     f1, f27, f0
	  fmuls     f0, f26, f0
	  fmuls     f29, f5, f6
	  fmuls     f28, f4, f6
	  stfs      f2, 0xA0(r1)
	  fmuls     f27, f3, f6
	  stfs      f1, 0x9C(r1)
	  addi      r4, r1, 0x98
	  stfs      f0, 0x98(r1)
	  addi      r3, r1, 0x1B0
	  bl        -0x9B000
	  lfs       f0, -0x3F30(r13)
	  addi      r6, r1, 0x94
	  addi      r5, r1, 0x90
	  fmuls     f2, f30, f0
	  addi      r4, r1, 0x8C
	  fmuls     f1, f22, f0
	  addi      r3, r1, 0x1BC
	  fmuls     f0, f31, f0
	  stfs      f2, 0x94(r1)
	  stfs      f1, 0x90(r1)
	  stfs      f0, 0x8C(r1)
	  bl        -0x9B030
	  lfs       f2, 0x1BC(r1)
	  lfs       f0, 0x1B0(r1)
	  lfs       f1, 0x1C0(r1)
	  fadds     f2, f2, f0
	  lfs       f0, 0x1B4(r1)
	  lfs       f3, 0x1C4(r1)
	  fadds     f0, f1, f0
	  lfs       f1, 0x1B8(r1)
	  fadds     f2, f2, f27
	  fadds     f3, f3, f1
	  fadds     f1, f0, f28
	  stfs      f2, 0x208(r1)
	  fadds     f0, f3, f29
	  stfs      f1, 0x20C(r1)
	  stfs      f0, 0x210(r1)

	.loc_0x660:
	  lfs       f1, 0x208(r1)
	  lfs       f0, 0x20C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x210(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC456C
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x6B4
	  lfs       f0, 0x208(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x208(r1)
	  lfs       f0, 0x20C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x20C(r1)
	  lfs       f0, 0x210(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x210(r1)

	.loc_0x6B4:
	  lfs       f1, -0x68E0(r2)
	  addi      r3, r31, 0
	  addi      r4, r1, 0x208
	  bl        -0x6414
	  b         .loc_0x6D8

	.loc_0x6C8:
	  lfs       f1, -0x68E0(r2)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x18
	  bl        -0x6428

	.loc_0x6D8:
	  lwz       r3, 0x10(r30)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x94(r31)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x98(r31)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0x9C(r31)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x1FC(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x200(r1)
	  stfs      f0, 0x204(r1)
	  lfs       f1, 0x1FC(r1)
	  lfs       f0, 0x200(r1)
	  lfs       f2, 0x204(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC4618
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x760
	  lfs       f0, 0x1FC(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x1FC(r1)
	  lfs       f0, 0x200(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x200(r1)
	  lfs       f0, 0x204(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x204(r1)

	.loc_0x760:
	  lfs       f0, -0x6888(r2)
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0x77C
	  lfs       f1, -0x68B4(r2)
	  addi      r3, r31, 0
	  addi      r4, r1, 0x1FC
	  bl        -0x64CC

	.loc_0x77C:
	  lmw       r25, 0x26C(r1)
	  lwz       r0, 0x2DC(r1)
	  lfd       f31, 0x2D0(r1)
	  lfd       f30, 0x2C8(r1)
	  lfd       f29, 0x2C0(r1)
	  lfd       f28, 0x2B8(r1)
	  lfd       f27, 0x2B0(r1)
	  lfd       f26, 0x2A8(r1)
	  lfd       f25, 0x2A0(r1)
	  lfd       f24, 0x298(r1)
	  lfd       f23, 0x290(r1)
	  lfd       f22, 0x288(r1)
	  addi      r1, r1, 0x2D8
	  mtlr      r0
	  blr
	*/
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
	_10 = 0.0f;
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

	_10 += piki->mVelocity.length() * gsys->getFrameTime();

	if (_10 > 300.0f) {
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
	_10               = 0;
	_18               = piki->mRotationAngle;
	_1C               = 0.1f * (PI * gsys->getRand(1.0f));
	piki->mVelocity.y = (50.0f * gsys->getRand(1.0f)) + 100.0f;
	_20               = piki->mFlickIntensity * 0.1f * gsys->getRand(1.0f) + piki->mFlickIntensity;
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

	if (_10 == 0) {
		f32 rad              = _20;
		piki->mVelocity.x    = -rad * sinf(_18);
		piki->mVelocity.z    = -rad * cosf(_18);
		piki->mFaceDirection = roundAng(piki->mFaceDirection + _1C);
		return;
	}

	if (_10 == 2) {
		_14 -= gsys->getFrameTime();
		if ((_14 < 0.0f || piki->mIsWhistlePending) && piki->isAlive()) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_GetUp, piki), PaniMotionInfo(PIKIANIM_GetUp));
			_10 = 3;
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
		if (_10 == 0) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_JKoke, piki), PaniMotionInfo(PIKIANIM_JKoke));
			_10 = 1;
			break;
		}
		if (_10 == 1) {
			_10     = 2;
			f32 min = C_PIKI_PROP(piki)._32C();
			f32 max = C_PIKI_PROP(piki)._31C();
			_14     = (max - min) * gsys->getRand(1.0f) + min;
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
	_20 = 0;
	_14 = atan2f(piki->mVelocity.x, piki->mVelocity.z);
	_18 = 0.1f * (PI * gsys->getRand(1.0f));
	_1C = 0.1f * piki->mFlickIntensity * gsys->getRand(1.0f) + piki->mFlickIntensity;
	piki->startMotion(PaniMotionInfo(PIKIANIM_JHit, piki), PaniMotionInfo(PIKIANIM_JHit));
}

/*
 * --INFO--
 * Address:	800D37B8
 * Size:	000098
 */
void PikiFlownState::procBounceMsg(Piki* piki, MsgBounce*)
{
	if (_20 == 0) {
		piki->startMotion(PaniMotionInfo(PIKIANIM_JKoke, piki), PaniMotionInfo(PIKIANIM_JKoke));
		_20 = 1;
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

	if (_20 == 0) {
		piki->mFaceDirection = roundAng(piki->mFaceDirection + _18);
		return;
	}

	if (_20 == 2) {
		_10 -= gsys->getFrameTime();
		if ((_10 < 0.0f || piki->mIsWhistlePending) && piki->isAlive()) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_GetUp, piki), PaniMotionInfo(PIKIANIM_GetUp));
			_20 = 3;
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
		if (_20 == 1) {
			_20     = 2;
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
			u32 badCompiler;
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
	_10 = 0;
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
	_10 = 1;
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
		if (_10 == 1) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_GetUp, piki), PaniMotionInfo(PIKIANIM_GetUp));
			_10 = 2;
			break;
		}

		if (_10 == 2) {
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
	_1C       = piki->mVelocity;
	f32 speed = _1C.normalise();
	if (speed < 1.0f) {
		_18 = 0;
	} else {
		_18 = 1;
	}
	piki->startMotion(PaniMotionInfo(PIKIANIM_LSuberu, piki), PaniMotionInfo(PIKIANIM_LSuberu));
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	_10 = 0;
	PRINT("%x cliff start :: %s\n", piki, _18 ? "BURAN" : "OTIKAKE"); // 'hang' and 'fall' (i think)
	_28 = piki->mFaceDirection;
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
	_10 = 3;
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
		switch (_10) {
		case 0:
			if (_18 >= 2 || _18 < 0) {
				return;
			}

			_10 = 1;
			_14 = int((2.0f * gsys->getRand(1.0f))) + 1;
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
		switch (_10) {
		case 1:
			_14--;
			if (_14 > 0) {
				break;
			}
			if (_18 == 1) {
				if (piki->mGroundTriangle && nearEnough(piki)) {
					piki->mFaceDirection = roundAng(_28 + PI);
					piki->startMotion(PaniMotionInfo(PIKIANIM_Hikakaru, piki), PaniMotionInfo(PIKIANIM_Hikakaru));
					Plane* plane = piki->getNearestPlane(piki->mGroundTriangle);
					if (plane) {
						f32 dist = plane->dist(piki->mPosition);
						PRINT("dist is %.1f ( radius=%f : centresize=%f\n", dist, piki->mCollisionRadius, piki->getCentreSize());
						if (dist > -0.2f && dist < 3.0f) {
							PRINT("piki%x : ####### start buran motion :: floor = %s\n", piki, piki->mGroundTriangle ? "on floor" : "air");
							_10 = 2;
							_14 = int((2.0f * gsys->getRand(1.0f))) + 2;
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
			_14--;
			if (_14 > 0) {
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
	_10                           = 1;
}

/*
 * --INFO--
 * Address:	800D5090
 * Size:	000040
 */
void PikiEmitState::exec(Piki* piki)
{
	if (_10 == 0) {
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
	if (_10) {
		_10 = 0;
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
		if (_10) {
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
	_10.stop();
}

/*
 * --INFO--
 * Address:	800D52D0
 * Size:	000024
 */
void PikiFlyingState::restartEffect()
{
	_10.restart();
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
	_24                = 0;
	_10.init(piki->mPosition, EffectMgr::EFF_SD_Sparkle);
	_40 = 0;
	_25 = 0;
}

/*
 * --INFO--
 * Address:	800D53A4
 * Size:	0003C0
 */
void PikiFlyingState::exec(Piki* piki)
{
	if (piki->isCreatureFlag(CF_IsOnGround)) {
		_40++;
		if (_40 >= 10) {
			for (int i = 0; i < 10; i++) {
				PRINT("** WARNING *** FLYING MIGHT LAST FOREVER !!!\n");
			}
			piki->dump();
			procBounceMsg(piki, nullptr);
			return;
		}
	} else {
		_40 = 0;
	}

	_10.updatePos(piki->mPosition);

	f32 val1 = AIConstant::_instance->mConstants.mGravity() * 0.8f;
	f32 val2 = AIConstant::_instance->mConstants.mGravity() * C_PIKI_PROP(piki)._37C();
	f32 f    = 0.15f;
	f32 val3 = val1 * f - 0.5f * 0.15f * (val1 - val2) - val2 * f;
	if (!_24 && piki->mHappa == Flower && piki->mVelocity.y <= 0.0f) {
		_24 = 1;
		piki->startMotion(PaniMotionInfo(PIKIANIM_Hang), PaniMotionInfo(PIKIANIM_Hang));
		f32 val4;
		if (piki->mColor == Yellow) {
			val4 = C_NAVI_PROP(piki->mNavi)._19C();
		} else {
			val4 = C_NAVI_PROP(piki->mNavi)._17C();
		}

		f32 val5 = (speedy_sqrtf(val3 * val3 + 2.0f * val4 * val2) + -val3) / val2;
		f32 val6 = C_NAVI_PROP(piki->mNavi)._1AC() * 0.5f;
		f32 val7 = val6 / val5;
		_2C.x    = piki->mVelocity.x;
		_2C.y    = 0.0f;
		_2C.z    = piki->mVelocity.z;
		_2C.normalise();
		f32 val8 = speedy_sqrtf(piki->mVelocity.x * piki->mVelocity.x + piki->mVelocity.z * piki->mVelocity.z);
		_38      = val8;
		f32 val9 = val8 * 0.5f;
		_3C      = val9;
		val5     = ((val8 * val6) - (val8 - (val8 - val9) * 0.5f - val9) * 0.15f) / val9;
		piki->mVelocity.x *= val7;
		piki->mVelocity.z *= val7;
		piki->mTargetVelocity.x = piki->mVelocity.x;
		piki->mTargetVelocity.z = piki->mVelocity.z;
		piki->mVelocity.y       = 0.0f;
		piki->mTargetVelocity.y = 0.0f;
		_20                     = 0.0f;
		return;
	}

	if (!_24) {
		return;
	}

	piki->mFaceDirection = roundAng(gsys->getFrameTime() * PI / 0.42f + piki->mFaceDirection);
	_20 += gsys->getFrameTime();
	f32 rval = (gsys->getRand(1.0f) - 0.5f) * 0.01f;

	PRINT("please save me fake stack fixing device", rval > 0.0f ? "yes" : "no");

	f32 val;
	if (_20 < 0.15f) {
		val = val1 - (val1 - val2) / 0.15f * _20;
	} else {
		val = val2;
	}

	piki->mVelocity.y += ((AIConstant::_instance->mConstants.mGravity() - val) * (rval + 1.0f)) * gsys->getFrameTime();

	u32 badCompiler[4];
}

/*
 * --INFO--
 * Address:	800D5764
 * Size:	000044
 */
void PikiFlyingState::cleanup(Piki* piki)
{
	_10.kill();
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
		if (!_25) {
			Vector3f bounceDir = piki->mPosition - collider->mPosition;
			bounceDir.normalise();
			bounceDir.multiply(140.0f);
			piki->mVelocity       = bounceDir;
			piki->mTargetVelocity = bounceDir;
		}

		_25 = 1;
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
	if (_25) {
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
	_10 = false;
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
		_10 = true;
	}

	if (!_10 && piki->mNavi->_764.length() <= 0.1f) {
		piki->mPikiAnimMgr.finishMotion(piki);
		_10 = true;
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
	_10 = 1;
	_14 = 0;
}

/*
 * --INFO--
 * Address:	800D6A68
 * Size:	0000F4
 */
void PikiPushPikiState::exec(Piki* piki)
{
	if (!_14 && piki->_4DC->getState() != PIKISTATE_Push && piki->_4DC->getState() != PIKISTATE_PushPiki) {
		piki->mPikiAnimMgr.finishMotion(piki);
		_14 = 1;
	}

	piki->mMotionSpeed = 30.0f;

	if (!_14 && piki->mNavi->_764.length() <= 0.1f) {
		piki->mPikiAnimMgr.finishMotion(piki);
		_14 = 1;
	}
	_10 = 0;
}

/*
 * --INFO--
 * Address:	800D6B5C
 * Size:	00000C
 */
void PikiPushPikiState::cleanup(Piki* piki)
{
	piki->_4DC = nullptr;
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
	u32 badCompiler;
	Creature* collider = msg->mEvent.mCollider;
	switch (collider->mObjType) {
	case OBJTYPE_Piki:
		Piki* other = (Piki*)collider;
		if (other->getState() == PIKISTATE_Push) {
			Vector3f pos(other->_4BC);
			piki->mFaceDirection = other->mFaceDirection;
			piki->_4BC           = pos;
			_10                  = 1;
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
	    && (PikiHeadMgr::buryMode = true, sprout = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead), PikiHeadMgr::buryMode = false,
	        sprout)) {
#else
	PikiHeadMgr::buryMode = true;
	PikiHeadItem* sprout  = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead);
	PikiHeadMgr::buryMode = false;
	int attr              = ATTR_NULL;
	if (piki->mGroundTriangle) {
		attr = MapCode::getAttribute(piki->mGroundTriangle);
	}

	if (sprout && attr != ATTR_Water) {
#endif
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
		u32 badCompiler;
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
	_10 = 0;
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
	if (_10) {
		Vector3f pos(piki->mPosition); // lol
		effectMgr->create(EffectMgr::EFF_SD_DirtCloud, piki->mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_SD_DirtSpray, piki->mPosition, nullptr, nullptr);
		_10 = 0;
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
		_10 = 1;
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
		_10 = 1.5f;
		_14 = 1;
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
	_10 = 1.5f;
	_14 = 1;
	PRINT("pressed init !\n");
}

/*
 * --INFO--
 * Address:	800D7908
 * Size:	000140
 */
void PikiPressedState::exec(Piki* piki)
{
	if (!_14) {
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

	if (_10 > 0.0f) {
		_10 -= gsys->getFrameTime();
	} else {
		_14 = 0;
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
    , mRapCnt(0)
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
	if (piki->mEmotion == PikiEmotion::Unk10) {
		return;
	}

	switch (piki->mEmotion) {
	case PikiEmotion::Unk5: {
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

	case PikiEmotion::Unk0: {
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

	case PikiEmotion::Unk7: {
		Choice motionChoices[2] = {
			{ PIKIANIM_Sagasu, 0.5f },
			{ PIKIANIM_Sagasu2, 0.5f },
		};

		int motionID = selectRandomly(motionChoices, 2);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
	} break;

	case PikiEmotion::Unk8: {
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

	case PikiEmotion::Unk1: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Gakkari, piki), PaniMotionInfo(PIKIANIM_Gakkari));
		piki->mPikiAnimMgr.finishMotion(piki);
		seSystem->playPikiSound(SEF_PIKI_GAKKARI, piki->mPosition);
	} break;

	case PikiEmotion::Unk3: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Mizuage, piki), PaniMotionInfo(PIKIANIM_Mizuage));
		piki->mPikiAnimMgr.finishMotion(piki);
		seSystem->playPikiSound(SEF_PIKI_BURUBURU, piki->mPosition);
	} break;

	case PikiEmotion::Unk6: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Jump_B1, piki), PaniMotionInfo(PIKIANIM_Jump_B1));
		piki->mPikiAnimMgr.finishMotion(piki);
		seSystem->playPikiSound(SEF_PIKI_YATTA, piki->mPosition);
	} break;

	case PikiEmotion::Unk4: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Wait, piki), PaniMotionInfo(PIKIANIM_Wait));
		piki->startLook(&piki->mCarryingShipPart->mPosition);
		mGazeFlag = 1;
	} break;

	case PikiEmotion::Unk9: {
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
		if (mRapCnt == 0) {
			mRapCnt = 5;
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
	PRINT("gazeFlag=%d rapCnt=%d timer=%.1f gazePos(%.1f %.1f %.1f)\n", mGazeFlag, mRapCnt, mTimer, mGazePosition.x, mGazePosition.y,
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
	if (piki->mEmotion == PikiEmotion::Unk10) {
		transit(piki, PIKISTATE_Normal);
	}

	if (piki->mEmotion == PikiEmotion::Unk4 || (piki->mEmotion == PikiEmotion::Unk9 && mRapCnt == 5)) {
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
	piki->mEmotion          = PikiEmotion::Unk10;
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
		if (piki->mEmotion == PikiEmotion::Unk9) {
			mRapCnt--;
			if (mRapCnt) {
				init(piki);
				break;
			}
		}

		mRapCnt = 0;
		transit(piki, PIKISTATE_Normal);
		break;
	}
}
