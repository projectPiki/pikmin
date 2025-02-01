#include "PikiAI.h"
#include "Navi.h"
#include "CPlate.h"
#include "NaviMgr.h"
#include "gameflow.h"
#include "PikiInfo.h"
#include "PikiMgr.h"
#include "MoviePlayer.h"
#include "PlayerState.h"
#include "ViewPiki.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/arith.h"
#include "GameStat.h"
#include "DebugLog.h"

static bool newVer = true;

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
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	800B5AAC
 * Size:	0000FC
 */
ActCrowd::ActCrowd(Piki* piki)
    : Action(piki, true)
{
	setName("crowd");
	mPlateMgr     = nullptr;
	mCPlateSlotID = -1;
	mSelectAction = new ActBoreSelect(piki);
}

/*
 * --INFO--
 * Address:	800B5BA8
 * Size:	000008
 */
void ActCrowd::inform(int slotID)
{
	mCPlateSlotID = slotID;
}

/*
 * --INFO--
 * Address:	800B5BB0
 * Size:	00002C
 */
void ActCrowd::startSort()
{
	mState = STATE_Sort;
	mSelectAction->stop();
}

/*
 * --INFO--
 * Address:	800B5BDC
 * Size:	00015C
 */
void ActCrowd::init(Creature* target)
{
	mMode      = 5;
	_30        = 5;
	_32        = 0;
	mIsWaiting = false;
	_7E        = 0;
	if (target->mObjType != OBJTYPE_Navi) {
		PRINT("target is not navi (%d)\n", target->mObjType);
	}

	Navi* navi    = static_cast<Navi*>(target);
	mPlateMgr     = navi->mPlateMgr;
	mCPlateSlotID = mPlateMgr->getSlot(mPiki, this);
	if (mCPlateSlotID == -1) {
		PRINT("slot id is -1\n");
	} else {
		navi->incPlatePiki();
	}

	if (!mPiki->isHolding()) {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
	}
	mPiki->unsetPastel();
	_34              = 0;
	_35              = 0;
	_36              = 0;
	mState           = STATE_Unk0;
	mTripLoopCounter = 0;
	_60              = 0.0f;
	mIsTripping      = false;
	GameStat::formationPikis.inc(mPiki->mColor);
	GameStat::workPikis.dec(mPiki->mColor);
	GameStat::update();
	mHasRoute = false;
	mOdometer.start(2.0f, 20.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void ActCrowd::initRouteMove()
{
	mHasRoute = false;
	if (mPiki->initRouteTraceDynamic(mPiki->mNavi)) {
		PRINT("OKOK!\n");
		mHasRoute = true;
	}
	_68 = 5.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void ActCrowd::exeRouteMove()
{
	if (mPiki->moveRouteTraceDynamic(1.0f) != 2) {
		PRINT("THE END\n");
		mHasRoute = false;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void ActCrowd::setFormed()
{
	mState = STATE_Formed;
	if (mPiki->hasBomb() && !playerState->mDemoFlags.isFlag(DEMOFLAG_GrabFirstBomb)) {
		playerState->mDemoFlags.setFlag(DEMOFLAG_GrabFirstBomb, mPiki);
	}
}

/*
 * --INFO--
 * Address:	800B5D38
 * Size:	0000E4
 */
void ActCrowd::procCollideMsg(Piki*, MsgCollide* msg)
{
	if (mState == STATE_Sort) {
		return;
	}

	Piki* collider = static_cast<Piki*>(msg->mEvent.mCollider);
	if (collider->mObjType == OBJTYPE_Piki) {
		if (collider->mMode == PikiMode::FormationMode && mState == STATE_Unk0) {
			ActCrowd* colliderAction = static_cast<ActCrowd*>(collider->mActiveAction->getCurrAction());
			if (colliderAction && colliderAction->mState == STATE_Formed) {
				pikiInfo->addFormationPiki();
				setFormed();
			}
		}

		_36 = 1;
	}
}

/*
 * --INFO--
 * Address:	800B5E1C
 * Size:	000034
 */
void ActCrowd::procWallMsg(Piki*, MsgWall* msg)
{
	if (mCPlateSlotID != -1) {
		_70 = *msg->mWallNormal;
		_35 = 1;
	}
}

/*
 * --INFO--
 * Address:	800B5E50
 * Size:	00011C
 */
void ActCrowd::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action1:
		if (mIsTripping) {
			piki->mVelocity.set(0.0f, 0.0f, 0.0f);
			piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		}
		break;
	case KEY_LoopEnd:
		if (mIsTripping) {
			mTripLoopCounter--;
			if (mTripLoopCounter <= 0) {
				piki->mPikiAnimMgr.finishMotion(piki);
			}
		}
		break;
	case KEY_Finished:
		if (mIsTripping) {
			mIsTripping = false;
			piki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	800B5F6C
 * Size:	0000FC
 */
void ActCrowd::cleanup()
{
	if (mPiki->mRouteHandle) {
		routeMgr->getPathFinder('test')->releaseHandle(mPiki->mRouteHandle);
	}
	if (mCPlateSlotID != -1) {
		int count = mPiki->getCnt();
		mPiki->mNavi->decPlatePiki();
		mPlateMgr->releaseSlot(mPiki, mCPlateSlotID);
		if (count > 0 && count == mPiki->getCnt()) {
			ERROR("smart ptr err %d\n", mPiki->getCnt());
		}
	}
	pikiInfo->subFormationPiki();
	mPlateMgr     = nullptr;
	mCPlateSlotID = -1;
	GameStat::workPikis.inc(mPiki->mColor);
	GameStat::formationPikis.dec(mPiki->mColor);
	GameStat::update();
}

/*
 * --INFO--
 * Address:	800B6068
 * Size:	00164C
 */
int ActCrowd::exec()
{
	_30   = mMode;
	mMode = 5;
	if (mHasRoute) {
		exeRouteMove();
		if (mPiki->mUseAsyncPathfinding) {
			_68 -= gsys->getFrameTime();
			if (_68 < 0.0f) {
				mPiki->mActionState = 2;
				return ACTOUT_Fail;
			}
		}
		return ACTOUT_Continue;
	}

	if (mPiki->mNavi->isStickTo()) {
		mPiki->mActionState = 2;
		return ACTOUT_Fail;
	}

	if (mIsTripping) {
		if (mPiki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() != PIKIANIM_Korobu) {
			mIsTripping = false;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
		}
		mPiki->mTargetVelocity = mPiki->mTargetVelocity * 0.955f;
		return ACTOUT_Continue;
	}

	if (mIsWaiting && !mPiki->hasBomb()) {
		int boreRes = mSelectAction->exec();
		if (boreRes != ACTOUT_Continue) {
			mIsWaiting = false;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
		} else {
			if (mPiki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() == PIKIANIM_Wait) {
				mIsWaiting = false;
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
			} else {
				return boreRes;
			}
		}
	}

	_7E = mIsWaiting;
	if (!mPiki->mNavi) {
		ERROR("piki->navi 0!\n");
	}

	bool check = false;
	if (mPiki->mNavi->_764.length() <= C_NAVI_PROP(mPiki->mNavi).mNeutralStickThreshold()) {
		check = true;
	}

	if (!mPlateMgr->validSlot(mCPlateSlotID)) {
		ERROR("invalid slotId!\n");
	}

	Vector3f platePos = mPlateMgr->mSlotList[mCPlateSlotID].mOffsetFromCenter + mPlateMgr->mPlateCenter;

	Vector3f effDir = static_cast<ViewPiki*>(mPiki)->mLastEffectPosition - mPiki->mPosition;
	f32 travelDist  = effDir.length();

	if (mPiki->hasBomb() && !playerState->mDemoFlags.isFlag(DEMOFLAG_GrabFirstBomb) && travelDist < 100.0f) {
		playerState->mDemoFlags.setFlag(DEMOFLAG_GrabFirstBomb, mPiki);
	}

	_60 += travelDist;

	// - yellows with bombs cannot trip
	// - have to have moved a certain distance
	// - have to be moving at at least 110 units of speed
	if (!mPiki->hasBomb() && _60 >= 100.0f && mPiki->mVelocity.length() > 110.0f) {

		// idk why they did this in two rand checks, but go figure
		// approximately a 0.003% chance of tripping
		if (unitRandFloat() >= 0.9999f && unitRandFloat() > 0.7f) {
			mIsTripping      = true;
			mTripLoopCounter = int(randFloat(4.0f)) + 3; // length of trip is a random number of anim loops, between 3 and 7
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Korobu, mPiki), PaniMotionInfo(PIKIANIM_Korobu));
			return ACTOUT_Continue;
		}

		_60 = 0.0f;
	}

	Vector3f plateDir = platePos - mPiki->mPosition;
	f32 plateDist2D   = std::sqrtf(plateDir.x * plateDir.x + plateDir.z * plateDir.z);
	plateDir.normalise();

	if (plateDist2D < 60.0f && mPiki->mNavi->_724 && mState != STATE_Sort) {
		if (!mIsWaiting && mPiki->mNavi->_738 - randFloat(2.0f) >= C_NAVI_PROP(mPiki->mNavi)._34C()) {
			mIsWaiting = true;
			return ACTOUT_Continue;
		}

		if (mState == STATE_Unk0) {
			mMode           = 0;
			Piki* minPiki   = nullptr;
			int minSlotPrio = 256;
			int minSlotID;
			Iterator iter(mPiki->mNavi->mPlateMgr);
			CI_LOOP(iter)
			{
				Piki* piki = static_cast<Piki*>(*iter);
				if (piki->mMode != PikiMode::FormationMode) {
					piki->changeMode(PikiMode::FreeMode, piki->mNavi);
				} else {
					ActCrowd* action = static_cast<ActCrowd*>(piki->mActiveAction->getCurrAction());
					if (action && piki != mPiki && action->mState == STATE_Formed) {
						int slotPrio = abs(action->mCPlateSlotID - mCPlateSlotID);
						if (slotPrio < minSlotPrio) {
							minPiki     = piki;
							minSlotPrio = slotPrio;
							minSlotID   = action->mCPlateSlotID;
						}
					}
				}
			}

			if (minPiki) {
				platePos = minPiki->mPosition;
			} else {
				platePos = mPiki->mNavi->mPosition;
			}

			mIsWaiting       = false;
			Vector3f moveDir = platePos - mPiki->mPosition;
			f32 unused       = moveDir.normalise();
			f32 moveDist     = qdist2(platePos.x, platePos.z, mPiki->mPosition.x, mPiki->mPosition.z);
			if (moveDist <= 40.0f) {
				if (mState != STATE_Formed) {
					setFormed();
					pikiInfo->addFormationPiki();
					mOdometer.reset();
				}
			} else {
				mPiki->setSpeed(1.0f, moveDir);
				if (_7E && !mIsWaiting) {
					mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
					finishZawatuki();
				}
			}

			return ACTOUT_Continue;
		}

		mMode = 1;
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		Vector3f naviDir = mPiki->mNavi->mPosition - mPiki->mPosition;
		f32 diff         = atan2f(naviDir.x, naviDir.z);
		mPiki->mFaceDirection += 0.3f * angDist(diff, mPiki->mFaceDirection);
		if (!gameflow.mMoviePlayer->mIsActive && !mIsWaiting && mPiki->mNavi->_738 - randFloat(2.0f) >= C_NAVI_PROP(mPiki->mNavi)._34C()) {
			mIsWaiting = true;
			startZawatuki();
		}
		return ACTOUT_Continue;
	}

	if (plateDist2D <= 7.0f) {
		_32 = 0;
	} else if (plateDist2D < 15.0f) {
		_32++;
		if (_30 == 2 && mPiki->mNavi->_738 > 0.1f) {
			_32 = 0;
		}
		if (_32 >= 6) {
			_32 = 6;
		}
	} else {
		_32 = 0;
	}

	if (plateDist2D <= 7.0f || (_32 < 6 && plateDist2D <= 15.0f)) {
		mMode = 2;
		mOdometer.reset();
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		plateDir  = mPiki->mNavi->mPosition - mPiki->mPosition;
		f32 diff  = atan2f(plateDir.x, plateDir.z);
		f32 angle = angDist(diff, mPiki->mFaceDirection);
		mPiki->mFaceDirection += 0.3f * angle;
		if (mState != STATE_Formed) {
			pikiInfo->addFormationPiki();
			setFormed();
		}

		if (!gameflow.mMoviePlayer->mIsActive && !mIsWaiting && mPiki->mNavi->_738 - randFloat(2.0f) >= C_NAVI_PROP(mPiki->mNavi)._34C()) {
			mIsWaiting = true;
			startZawatuki();
		}
	} else if (plateDist2D < 15.0f) {
		mMode = 3;
		if (mIsWaiting && plateDist2D < 10.0f) {
			mIsWaiting = true;
		}

		mOdometer.reset();
		Vector3f vel(mPiki->mTargetVelocity);
		f32 factor = 10.0f / mPiki->mProps->mCreatureProps.mAcceleration();
		f32 speed  = mPiki->getSpeed(1.0f);
		f32 f1     = (speed / factor);
		f32 val1   = 0.5f * f1 * speed;
		f32 speed2 = mPiki->mVelocity.length();
		f32 f2     = (speed2 / factor);
		f32 val2   = 0.5f * f2 * speed2;

		if (plateDist2D < val2) {
			mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			if (!gameflow.mMoviePlayer->mIsActive && !mIsWaiting
			    && mPiki->mNavi->_738 - randFloat(2.0f) >= C_NAVI_PROP(mPiki->mNavi)._34C()) {
				mIsWaiting = true;
				startZawatuki();
			}
			plateDir  = mPiki->mNavi->mPosition - mPiki->mPosition;
			f32 diff  = atan2f(plateDir.x, plateDir.z);
			f32 angle = angDist(diff, mPiki->mFaceDirection);
			mPiki->mFaceDirection += 0.3f * angle;
		} else if (plateDist2D < val1) {
			f32 val3               = speed2 + 0.5f * speedy_sqrtf(speed2 * speed2 + 8.0f * factor * plateDist2D);
			mPiki->mTargetVelocity = plateDir * val3;
		} else {
			mPiki->setSpeed(1.0f, plateDir);
		}

		Vector3f pikiDir      = mPiki->mPosition - mPiki->mNavi->mPosition;
		Vector3f naviPlateDir = mPiki->mNavi->mPosition - mPlateMgr->mPlateOffset;
		naviPlateDir.normalise();
		if (naviPlateDir.DP(pikiDir) > 0.0f) {
			Vector3f sideDir(-pikiDir.z, 0.0f, pikiDir.x);
			if (!(mCPlateSlotID & 1)) {
				sideDir.multiply(-1.0f);
			}
			sideDir.normalise();

			if (newVer && !check) {
				sideDir.set(0.0f, 0.0f, 0.0f);
			}

			f32 prevSpeed          = mPiki->mTargetVelocity.length();
			mPiki->mTargetVelocity = mPiki->mTargetVelocity + sideDir * mPiki->getSpeed(0.5f);
			mPiki->mTargetVelocity.normalise();
			mPiki->mTargetVelocity = mPiki->mTargetVelocity * prevSpeed;
		}
	} else {
		mMode = 4;
		mPiki->setSpeed(1.0f, plateDir);

		Vector3f pikiDir      = mPiki->mPosition - mPiki->mNavi->mPosition;
		Vector3f naviPlateDir = mPiki->mNavi->mPosition - mPlateMgr->mPlateOffset;
		naviPlateDir.normalise();
		if (naviPlateDir.DP(pikiDir) > 0.0f) {
			Vector3f sideDir(-pikiDir.z, 0.0f, pikiDir.x);
			if (!(mCPlateSlotID & 1)) {
				sideDir.multiply(-1.0f);
			}
			sideDir.normalise();

			if (newVer && !check) {
				sideDir.set(0.0f, 0.0f, 0.0f);
			}

			f32 prevSpeed          = mPiki->mTargetVelocity.length();
			mPiki->mTargetVelocity = mPiki->mTargetVelocity + sideDir * mPiki->getSpeed(0.5f);
			mPiki->mTargetVelocity.normalise();
			mPiki->mTargetVelocity = mPiki->mTargetVelocity * prevSpeed;
		}
	}

	if (plateDist2D < C_PIKI_PROP(mPiki)._27C()) {
		_68 = 0.0f;
		_34 = 0;
	} else if (plateDist2D < C_PIKI_PROP(mPiki)._28C()) {
		_68 += gsys->getFrameTime();
		if (!_34) {
			if (mCPlateSlotID != -1) {
				mPlateMgr->releaseSlot(mPiki, mCPlateSlotID);
				mCPlateSlotID = mPlateMgr->getSlot(mPiki, this);
			}

			_34 = 1;
		}
		if (mCPlateSlotID == -1 || _68 > C_PIKI_PROP(mPiki)._29C()) {
			return ACTOUT_Fail;
		}
	} else {
		return ACTOUT_Fail;
	}

	if (_7E && !mIsWaiting) {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
		finishZawatuki();
	}

	// some of this needs to be from inlines still (like 0x30 worth lol)
	u32 badCompiler[20];

	return ACTOUT_Continue;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x5
	  stwu      r1, -0x5A0(r1)
	  stfd      f31, 0x598(r1)
	  stfd      f30, 0x590(r1)
	  stfd      f29, 0x588(r1)
	  stfd      f28, 0x580(r1)
	  stfd      f27, 0x578(r1)
	  stfd      f26, 0x570(r1)
	  stfd      f25, 0x568(r1)
	  stmw      r26, 0x550(r1)
	  mr        r31, r3
	  lhz       r3, 0x2E(r3)
	  sth       r3, 0x30(r31)
	  sth       r0, 0x2E(r31)
	  lbz       r0, 0x7F(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xB8
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x6EE0(r2)
	  bl        0x10DA0
	  cmpwi     r3, 0x2
	  beq-      .loc_0x68
	  li        r0, 0
	  stb       r0, 0x7F(r31)

	.loc_0x68:
	  lwz       r3, 0xC(r31)
	  lbz       r0, 0x2D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xB0
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x68(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x68(r31)
	  lfs       f1, 0x68(r31)
	  lfs       f0, -0x6EF0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB0
	  lwz       r4, 0xC(r31)
	  li        r0, 0x2
	  li        r3, 0x1
	  stb       r0, 0x408(r4)
	  b         .loc_0x161C

	.loc_0xB0:
	  li        r3, 0
	  b         .loc_0x161C

	.loc_0xB8:
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x504(r3)
	  lwz       r0, 0x184(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xDC
	  li        r0, 0x2
	  stb       r0, 0x408(r3)
	  li        r3, 0x1
	  b         .loc_0x161C

	.loc_0xDC:
	  lbz       r0, 0x64(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x180
	  lwz       r0, 0x39C(r3)
	  cmpwi     r0, 0x14
	  beq-      .loc_0x128
	  li        r0, 0
	  stb       r0, 0x64(r31)
	  addi      r3, r1, 0x460
	  li        r4, 0x2
	  bl        0x68DEC
	  addi      r26, r3, 0
	  addi      r3, r1, 0x468
	  li        r4, 0x2
	  bl        0x68DDC
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r26
	  bl        0x1484C

	.loc_0x128:
	  lwz       r4, 0xC(r31)
	  li        r3, 0
	  lfs       f2, -0x4B34(r13)
	  addi      r5, r4, 0xA4
	  lfs       f0, 0xA4(r4)
	  lfs       f1, 0xAC(r4)
	  fmuls     f0, f0, f2
	  fmuls     f1, f1, f2
	  stfs      f0, 0x318(r1)
	  lfs       f0, 0x318(r1)
	  stfs      f0, 0x454(r1)
	  lfs       f0, 0xA8(r4)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x458(r1)
	  stfs      f1, 0x45C(r1)
	  lwz       r4, 0x454(r1)
	  lwz       r0, 0x458(r1)
	  stw       r4, 0x0(r5)
	  stw       r0, 0x4(r5)
	  lwz       r0, 0x45C(r1)
	  stw       r0, 0x8(r5)
	  b         .loc_0x161C

	.loc_0x180:
	  lbz       r0, 0x7D(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x238
	  bl        0x11C7C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x238
	  lwz       r3, 0x28(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r3, 0
	  beq-      .loc_0x1EC
	  li        r0, 0
	  stb       r0, 0x7D(r31)
	  addi      r3, r1, 0x444
	  li        r4, 0x2
	  bl        0x68D2C
	  addi      r26, r3, 0
	  addi      r3, r1, 0x44C
	  li        r4, 0x2
	  bl        0x68D1C
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r26
	  bl        0x1478C
	  b         .loc_0x238

	.loc_0x1EC:
	  lwz       r4, 0xC(r31)
	  lwz       r0, 0x39C(r4)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x161C
	  li        r0, 0
	  stb       r0, 0x7D(r31)
	  addi      r3, r1, 0x434
	  li        r4, 0x2
	  bl        0x68CE4
	  addi      r26, r3, 0
	  addi      r3, r1, 0x43C
	  li        r4, 0x2
	  bl        0x68CD4
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r26
	  bl        0x14744
	  b         .loc_0x238
	  b         .loc_0x161C

	.loc_0x238:
	  lbz       r0, 0x7D(r31)
	  li        r29, 0
	  stb       r0, 0x7E(r31)
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x504(r3)
	  addi      r4, r3, 0x764
	  lwz       r3, 0x224(r3)
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0x4(r4)
	  addi      r26, r3, 0x368
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r4)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA86A0
	  lfs       f0, 0x0(r26)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x290
	  li        r29, 0x1

	.loc_0x290:
	  lwz       r3, 0x6C(r31)
	  lwz       r4, 0x58(r31)
	  bl        -0x103B4
	  lwz       r5, 0x6C(r31)
	  lwz       r0, 0x58(r31)
	  lwz       r4, 0x80(r5)
	  rlwinm    r3,r0,5,0,26
	  lfsu      f0, 0x94(r5)
	  addi      r3, r3, 0xC
	  add       r3, r4, r3
	  lfs       f2, 0x4(r5)
	  lfs       f1, 0x0(r3)
	  lfs       f3, 0x4(r3)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0x8(r5)
	  fadds     f2, f3, f2
	  stfs      f0, 0x530(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x534(r1)
	  stfs      f0, 0x538(r1)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x6EF0(r2)
	  addi      r4, r3, 0x94
	  addi      r3, r3, 0x58C
	  lfs       f3, 0x4(r4)
	  lfs       f4, 0x4(r3)
	  lfs       f2, 0x0(r3)
	  lfs       f1, 0x0(r4)
	  fsubs     f4, f4, f3
	  lfs       f3, 0x8(r3)
	  fsubs     f5, f2, f1
	  lfs       f2, 0x8(r4)
	  fmuls     f1, f4, f4
	  fsubs     f3, f3, f2
	  fmuls     f2, f5, f5
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f26, f3, f1
	  fcmpo     cr0, f26, f0
	  ble-      .loc_0x38C
	  fsqrte    f1, f26
	  lfd       f3, -0x6ED8(r2)
	  lfd       f2, -0x6ED0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f26, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f26, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f26, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f26, f0
	  frsp      f0, f0
	  stfs      f0, 0x250(r1)
	  lfs       f26, 0x250(r1)

	.loc_0x38C:
	  lwz       r3, 0xC(r31)
	  bl        0x11A78
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3D4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x12
	  addi      r3, r3, 0x54
	  bl        -0x33F4C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3D4
	  lfs       f0, -0x6EC8(r2)
	  fcmpo     cr0, f26, f0
	  bge-      .loc_0x3D4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x12
	  lwz       r5, 0xC(r31)
	  addi      r3, r3, 0x54
	  bl        -0x33F1C

	.loc_0x3D4:
	  lfs       f0, 0x60(r31)
	  fadds     f0, f0, f26
	  stfs      f0, 0x60(r31)
	  lwz       r3, 0xC(r31)
	  bl        0x11A24
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x550
	  lfs       f1, 0x60(r31)
	  lfs       f0, -0x6EC8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x550
	  lwz       r3, 0xC(r31)
	  lfsu      f1, 0x70(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r3)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA8850
	  lfs       f0, -0x6EC4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x550
	  bl        0x161BD0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6E88(r2)
	  stw       r0, 0x54C(r1)
	  lis       r26, 0x4330
	  lfs       f2, -0x6EC0(r2)
	  stw       r26, 0x548(r1)
	  lfs       f1, -0x6EE0(r2)
	  lfd       f3, 0x548(r1)
	  lfs       f0, -0x6EBC(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x548
	  bl        0x161B90
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6E88(r2)
	  stw       r0, 0x54C(r1)
	  lfs       f2, -0x6EC0(r2)
	  stw       r26, 0x548(r1)
	  lfs       f1, -0x6EE0(r2)
	  lfd       f3, 0x548(r1)
	  lfs       f0, -0x6EB8(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x548
	  li        r0, 0x1
	  stb       r0, 0x64(r31)
	  bl        0x161B50
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6E88(r2)
	  stw       r0, 0x54C(r1)
	  lfs       f2, -0x6EC0(r2)
	  stw       r26, 0x548(r1)
	  lfs       f1, -0x6EE0(r2)
	  lfd       f3, 0x548(r1)
	  lfs       f0, -0x6EB4(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x540(r1)
	  lwz       r3, 0x544(r1)
	  addi      r0, r3, 0x3
	  stw       r0, 0x5C(r31)
	  lwz       r27, 0xC(r31)
	  cmplwi    r27, 0
	  beq-      .loc_0x510
	  addi      r27, r27, 0x2B8

	.loc_0x510:
	  addi      r3, r1, 0x40C
	  li        r4, 0x14
	  bl        0x689D8
	  addi      r26, r3, 0
	  addi      r5, r27, 0
	  addi      r3, r1, 0x414
	  li        r4, 0x14
	  bl        0x689F8
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r26
	  bl        0x14434
	  li        r3, 0
	  b         .loc_0x161C

	.loc_0x548:
	  lfs       f0, -0x6EF0(r2)
	  stfs      f0, 0x60(r31)

	.loc_0x550:
	  lwz       r3, 0xC(r31)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x530(r1)
	  lfs       f3, 0x534(r1)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x538(r1)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x514(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x518(r1)
	  stfs      f0, 0x51C(r1)
	  lfs       f0, 0x514(r1)
	  lfs       f1, 0x51C(r1)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x6EF0(r2)
	  fmuls     f1, f1, f1
	  fadds     f31, f2, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x5FC
	  fsqrte    f1, f31
	  lfd       f3, -0x6ED8(r2)
	  lfd       f2, -0x6ED0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0x308(r1)
	  lfs       f31, 0x308(r1)

	.loc_0x5FC:
	  lfs       f1, 0x514(r1)
	  lfs       f0, 0x518(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x51C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA8A44
	  lfs       f0, -0x6EF0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x650
	  lfs       f0, 0x514(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x514(r1)
	  lfs       f0, 0x518(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x518(r1)
	  lfs       f0, 0x51C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x51C(r1)

	.loc_0x650:
	  lfs       f0, -0x6EB0(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0xB50
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x504(r3)
	  lbz       r0, 0x724(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xB50
	  lhz       r0, 0x2C(r31)
	  cmplwi    r0, 0x2
	  beq-      .loc_0xB50
	  lbz       r0, 0x7D(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x6F8
	  lwz       r3, 0x224(r3)
	  addi      r26, r3, 0x358
	  bl        0x161978
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0xC(r31)
	  stw       r0, 0x544(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x504(r3)
	  stw       r0, 0x540(r1)
	  lfd       f2, -0x6E88(r2)
	  lfd       f1, 0x540(r1)
	  lfs       f0, -0x6EC0(r2)
	  fsubs     f4, f1, f2
	  lfs       f3, -0x6EE0(r2)
	  lfs       f1, -0x6EEC(r2)
	  lfs       f2, 0x738(r3)
	  fdivs     f4, f4, f0
	  lfs       f0, 0x0(r26)
	  fmuls     f3, f3, f4
	  fmuls     f1, f1, f3
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x6F8
	  li        r0, 0x1
	  stb       r0, 0x7D(r31)
	  li        r3, 0
	  b         .loc_0x161C

	.loc_0x6F8:
	  lhz       r0, 0x2C(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xA44
	  li        r0, 0
	  sth       r0, 0x2E(r31)
	  li        r28, 0
	  li        r27, 0x100
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x504(r3)
	  lwz       r30, 0x710(r3)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x81C

	.loc_0x73C:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x760
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x778

	.loc_0x760:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x778:
	  lhz       r0, 0x4FC(r3)
	  addi      r26, r3, 0
	  cmplwi    r0, 0x1
	  beq-      .loc_0x79C
	  lwz       r5, 0x504(r26)
	  addi      r3, r26, 0
	  li        r4, 0
	  bl        0x169D0
	  b         .loc_0x800

	.loc_0x79C:
	  lwz       r3, 0x4F8(r26)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x7B4
	  li        r4, 0
	  b         .loc_0x7C0

	.loc_0x7B4:
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r4, r3, r0

	.loc_0x7C0:
	  cmplwi    r4, 0
	  beq-      .loc_0x800
	  lwz       r0, 0xC(r31)
	  cmplw     r26, r0
	  beq-      .loc_0x800
	  lhz       r0, 0x2C(r4)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x800
	  lwz       r3, 0x58(r31)
	  lwz       r0, 0x58(r4)
	  sub       r3, r0, r3
	  bl        0x15F44C
	  cmpw      r3, r27
	  bge-      .loc_0x800
	  addi      r28, r26, 0
	  addi      r27, r3, 0

	.loc_0x800:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x81C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x844
	  li        r0, 0x1
	  b         .loc_0x870

	.loc_0x844:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x86C
	  li        r0, 0x1
	  b         .loc_0x870

	.loc_0x86C:
	  li        r0, 0

	.loc_0x870:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x73C
	  cmplwi    r28, 0
	  beq-      .loc_0x89C
	  lwz       r3, 0x94(r28)
	  lwz       r0, 0x98(r28)
	  stw       r3, 0x530(r1)
	  stw       r0, 0x534(r1)
	  lwz       r0, 0x9C(r28)
	  stw       r0, 0x538(r1)
	  b         .loc_0x8BC

	.loc_0x89C:
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x504(r3)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x530(r1)
	  stw       r0, 0x534(r1)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x538(r1)

	.loc_0x8BC:
	  li        r0, 0
	  stb       r0, 0x7D(r31)
	  lwz       r3, 0xC(r31)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x530(r1)
	  lfs       f3, 0x534(r1)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f26, 0x538(r1)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x4F4(r1)
	  fsubs     f0, f26, f1
	  stfs      f2, 0x4F8(r1)
	  stfs      f0, 0x4FC(r1)
	  lfs       f1, 0x4F4(r1)
	  lfs       f0, 0x4F8(r1)
	  lfs       f2, 0x4FC(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA8D40
	  lfs       f0, -0x6EF0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x94C
	  lfs       f0, 0x4F4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4F4(r1)
	  lfs       f0, 0x4F8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4F8(r1)
	  lfs       f0, 0x4FC(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4FC(r1)

	.loc_0x94C:
	  lwz       r3, 0xC(r31)
	  fmr       f2, f26
	  lfs       f1, 0x530(r1)
	  lfs       f3, 0x94(r3)
	  lfs       f4, 0x9C(r3)
	  bl        -0x7E3A0
	  lfs       f0, -0x6EAC(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x9E0
	  lhz       r0, 0x2C(r31)
	  cmplwi    r0, 0x1
	  beq-      .loc_0xA3C
	  li        r0, 0x1
	  sth       r0, 0x2C(r31)
	  lwz       r3, 0xC(r31)
	  bl        0x1147C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9C4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x12
	  addi      r3, r3, 0x54
	  bl        -0x34548
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x9C4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x12
	  lwz       r5, 0xC(r31)
	  addi      r3, r3, 0x54
	  bl        -0x3450C

	.loc_0x9C4:
	  lwz       r3, 0x3138(r13)
	  bl        0x632D8
	  lfs       f0, -0x6EF0(r2)
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x24(r31)
	  stfs      f0, 0x1C(r31)
	  b         .loc_0xA3C

	.loc_0x9E0:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x4F4
	  lfs       f1, -0x6EE0(r2)
	  bl        0x15384
	  lbz       r0, 0x7E(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xA3C
	  lbz       r0, 0x7D(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xA3C
	  addi      r3, r1, 0x3E4
	  li        r4, 0x2
	  bl        0x684E0
	  addi      r26, r3, 0
	  addi      r3, r1, 0x3EC
	  li        r4, 0x2
	  bl        0x684D0
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r26
	  bl        0x13F40
	  mr        r3, r31
	  bl        0xC6C

	.loc_0xA3C:
	  li        r3, 0
	  b         .loc_0x161C

	.loc_0xA44:
	  li        r30, 0x1
	  sth       r30, 0x2E(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4B30(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4B2C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4B28(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x504(r4)
	  lfsu      f1, 0x94(r4)
	  lfsu      f3, 0x94(r3)
	  lfs       f0, 0x8(r4)
	  lfs       f2, 0x8(r3)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x164F08
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x7E548
	  lfs       f0, -0x6EA8(r2)
	  lis       r3, 0x803A
	  lwz       r4, 0xC(r31)
	  subi      r3, r3, 0x2848
	  fmuls     f1, f0, f1
	  lfs       f0, 0xA0(r4)
	  fadds     f0, f0, f1
	  stfs      f0, 0xA0(r4)
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xB48
	  lbz       r0, 0x7D(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xB48
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x504(r3)
	  lwz       r3, 0x224(r3)
	  addi      r26, r3, 0x358
	  bl        0x161524
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0xC(r31)
	  stw       r0, 0x544(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x504(r3)
	  stw       r0, 0x540(r1)
	  lfd       f2, -0x6E88(r2)
	  lfd       f1, 0x540(r1)
	  lfs       f0, -0x6EC0(r2)
	  fsubs     f4, f1, f2
	  lfs       f3, -0x6EE0(r2)
	  lfs       f1, -0x6EEC(r2)
	  lfs       f2, 0x738(r3)
	  fdivs     f4, f4, f0
	  lfs       f0, 0x0(r26)
	  fmuls     f3, f3, f4
	  fmuls     f1, f1, f3
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xB48
	  stb       r30, 0x7D(r31)
	  mr        r3, r31
	  bl        .loc_0x164C

	.loc_0xB48:
	  li        r3, 0
	  b         .loc_0x161C

	.loc_0xB50:
	  lfs       f0, -0x6EA4(r2)
	  fcmpo     cr0, f31, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xB6C
	  li        r0, 0
	  sth       r0, 0x32(r31)
	  b         .loc_0xBD0

	.loc_0xB6C:
	  lfs       f0, -0x6EA0(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0xBC8
	  lhz       r3, 0x32(r31)
	  addi      r0, r3, 0x1
	  sth       r0, 0x32(r31)
	  lhz       r0, 0x30(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0xBB0
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x6E9C(r2)
	  lwz       r3, 0x504(r3)
	  lfs       f1, 0x738(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xBB0
	  li        r0, 0
	  sth       r0, 0x32(r31)

	.loc_0xBB0:
	  lhz       r0, 0x32(r31)
	  cmplwi    r0, 0x6
	  blt-      .loc_0xBD0
	  li        r0, 0x6
	  sth       r0, 0x32(r31)
	  b         .loc_0xBD0

	.loc_0xBC8:
	  li        r0, 0
	  sth       r0, 0x32(r31)

	.loc_0xBD0:
	  lfs       f0, -0x6EA4(r2)
	  fcmpo     cr0, f31, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0xBFC
	  lhz       r0, 0x32(r31)
	  cmplwi    r0, 0x6
	  bge-      .loc_0xD90
	  lfs       f0, -0x6EA0(r2)
	  fcmpo     cr0, f31, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xD90

	.loc_0xBFC:
	  li        r0, 0x2
	  sth       r0, 0x2E(r31)
	  lfs       f0, -0x6EF0(r2)
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x24(r31)
	  stfs      f0, 0x1C(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4B24(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4B20(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4B1C(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x504(r4)
	  lfsu      f1, 0x94(r3)
	  lfsu      f0, 0x94(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x4(r4)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0x8(r4)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x514(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x518(r1)
	  stfs      f0, 0x51C(r1)
	  lfs       f1, 0x514(r1)
	  lfs       f2, 0x51C(r1)
	  bl        0x164D20
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x7E730
	  lfs       f0, -0x6EA8(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f0, f0, f1
	  lfs       f1, 0xA0(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA0(r3)
	  lhz       r0, 0x2C(r31)
	  cmplwi    r0, 0x1
	  beq-      .loc_0xCF0
	  lwz       r3, 0x3138(r13)
	  bl        0x62FF8
	  li        r0, 0x1
	  sth       r0, 0x2C(r31)
	  lwz       r3, 0xC(r31)
	  bl        0x11150
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCF0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x12
	  addi      r3, r3, 0x54
	  bl        -0x34874
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xCF0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x12
	  lwz       r5, 0xC(r31)
	  addi      r3, r3, 0x54
	  bl        -0x34838

	.loc_0xCF0:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x1504
	  lbz       r0, 0x7D(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x1504
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x504(r3)
	  lwz       r3, 0x224(r3)
	  addi      r26, r3, 0x358
	  bl        0x1612E4
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0xC(r31)
	  stw       r0, 0x544(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x504(r3)
	  stw       r0, 0x540(r1)
	  lfd       f2, -0x6E88(r2)
	  lfd       f1, 0x540(r1)
	  lfs       f0, -0x6EC0(r2)
	  fsubs     f4, f1, f2
	  lfs       f3, -0x6EE0(r2)
	  lfs       f1, -0x6EE4(r2)
	  lfs       f2, 0x738(r3)
	  fdivs     f4, f4, f0
	  lfs       f0, 0x0(r26)
	  fmuls     f3, f3, f4
	  fmuls     f1, f1, f3
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1504
	  li        r0, 0x1
	  stb       r0, 0x7D(r31)
	  mr        r3, r31
	  bl        .loc_0x164C
	  b         .loc_0x1504

	.loc_0xD90:
	  lfs       f0, -0x6EA0(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x127C
	  li        r0, 0x3
	  sth       r0, 0x2E(r31)
	  lbz       r0, 0x7D(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xDC4
	  lfs       f0, -0x6E98(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0xDC4
	  li        r0, 0x1
	  stb       r0, 0x7D(r31)

	.loc_0xDC4:
	  lfs       f0, -0x6EF0(r2)
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x24(r31)
	  stfs      f0, 0x1C(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f2, -0x6E98(r2)
	  lwz       r4, 0x224(r3)
	  lfs       f1, -0x6EE0(r2)
	  lfs       f0, 0x40(r4)
	  fdivs     f26, f2, f0
	  bl        0x14F10
	  fdivs     f0, f1, f26
	  lwz       r3, 0xC(r31)
	  lfsu      f5, 0x70(r3)
	  lfs       f2, -0x6E94(r2)
	  lfs       f3, 0x4(r3)
	  fmuls     f4, f2, f0
	  lfs       f6, 0x8(r3)
	  fmuls     f0, f3, f3
	  fmuls     f2, f5, f5
	  fmuls     f3, f6, f6
	  fmuls     f25, f4, f1
	  fadds     f0, f2, f0
	  fadds     f1, f3, f0
	  bl        -0xA924C
	  fdivs     f0, f1, f26
	  lfs       f2, -0x6E94(r2)
	  fmuls     f0, f2, f0
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0xF64
	  lwz       r4, 0xC(r31)
	  lis       r3, 0x803A
	  lfs       f0, -0x4B18(r13)
	  subi      r3, r3, 0x2848
	  stfsu     f0, 0xA4(r4)
	  lfs       f0, -0x4B14(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x4B10(r13)
	  stfs      f0, 0x8(r4)
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xEF8
	  lbz       r0, 0x7D(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xEF8
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x504(r3)
	  lwz       r3, 0x224(r3)
	  addi      r26, r3, 0x358
	  bl        0x161178
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0xC(r31)
	  stw       r0, 0x544(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x504(r3)
	  stw       r0, 0x540(r1)
	  lfd       f2, -0x6E88(r2)
	  lfd       f1, 0x540(r1)
	  lfs       f0, -0x6EC0(r2)
	  fsubs     f4, f1, f2
	  lfs       f3, -0x6EE0(r2)
	  lfs       f1, -0x6EE4(r2)
	  lfs       f2, 0x738(r3)
	  fdivs     f4, f4, f0
	  lfs       f0, 0x0(r26)
	  fmuls     f3, f3, f4
	  fmuls     f1, f1, f3
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xEF8
	  li        r0, 0x1
	  stb       r0, 0x7D(r31)
	  mr        r3, r31
	  bl        .loc_0x164C

	.loc_0xEF8:
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x504(r4)
	  lfsu      f1, 0x94(r3)
	  lfsu      f0, 0x94(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x4(r4)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0x8(r4)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x514(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x518(r1)
	  stfs      f0, 0x51C(r1)
	  lfs       f1, 0x514(r1)
	  lfs       f2, 0x51C(r1)
	  bl        0x164A58
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x7E9F8
	  lfs       f0, -0x6EA8(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f0, f0, f1
	  lfs       f1, 0xA0(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA0(r3)
	  b         .loc_0x1008

	.loc_0xF64:
	  fcmpo     cr0, f31, f25
	  bge-      .loc_0xFF8
	  lfs       f2, -0x6E90(r2)
	  fmuls     f3, f1, f1
	  lfs       f0, -0x6EF0(r2)
	  fmuls     f2, f2, f26
	  fmuls     f2, f2, f31
	  fadds     f3, f3, f2
	  fcmpo     cr0, f3, f0
	  ble-      .loc_0xFA0
	  fsqrte    f0, f3
	  fmul      f0, f3, f0
	  frsp      f0, f0
	  stfs      f0, 0x2D4(r1)
	  lfs       f3, 0x2D4(r1)

	.loc_0xFA0:
	  lfs       f2, -0x6E94(r2)
	  lfs       f0, 0x514(r1)
	  fmuls     f2, f2, f3
	  fadds     f1, f1, f2
	  fmuls     f0, f0, f1
	  stfs      f0, 0x2C8(r1)
	  lfs       f0, 0x2C8(r1)
	  stfs      f0, 0x3CC(r1)
	  lfs       f0, 0x518(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3D0(r1)
	  lfs       f0, 0x51C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3D4(r1)
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x3CC(r1)
	  lwz       r0, 0x3D0(r1)
	  stw       r3, 0xA4(r4)
	  stw       r0, 0xA8(r4)
	  lwz       r0, 0x3D4(r1)
	  stw       r0, 0xAC(r4)
	  b         .loc_0x1008

	.loc_0xFF8:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x514
	  lfs       f1, -0x6EE0(r2)
	  bl        0x14D6C

	.loc_0x1008:
	  lwz       r5, 0xC(r31)
	  lwz       r3, 0x6C(r31)
	  lwz       r4, 0x504(r5)
	  addi      r5, r5, 0x94
	  addi      r3, r3, 0x5C
	  lfs       f8, 0x8(r5)
	  addi      r4, r4, 0x94
	  lfs       f5, 0x4(r4)
	  lfs       f0, 0x4(r3)
	  lfs       f3, 0x0(r4)
	  lfs       f1, 0x0(r3)
	  fsubs     f28, f5, f0
	  lfs       f7, 0x8(r4)
	  fsubs     f29, f3, f1
	  lfs       f1, 0x8(r3)
	  fmuls     f0, f28, f28
	  fsubs     f27, f7, f1
	  lfs       f6, 0x4(r5)
	  fmuls     f1, f29, f29
	  lfs       f4, 0x0(r5)
	  fmuls     f2, f27, f27
	  fsubs     f30, f8, f7
	  fadds     f0, f1, f0
	  fsubs     f25, f6, f5
	  fsubs     f26, f4, f3
	  fadds     f1, f2, f0
	  bl        -0xA9498
	  lfs       f0, -0x6EF0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x108C
	  fdivs     f29, f29, f1
	  fdivs     f28, f28, f1
	  fdivs     f27, f27, f1

	.loc_0x108C:
	  fmuls     f2, f29, f26
	  lfs       f0, -0x6EF0(r2)
	  fmuls     f1, f28, f25
	  fmuls     f3, f27, f30
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1504
	  lwz       r0, 0x58(r31)
	  fneg      f25, f30
	  lfs       f27, -0x4B0C(r13)
	  rlwinm.   r0,r0,0,31,31
	  bne-      .loc_0x10D0
	  lfs       f0, -0x6E8C(r2)
	  fmuls     f25, f25, f0
	  fmuls     f27, f27, f0
	  fmuls     f26, f26, f0

	.loc_0x10D0:
	  fmuls     f1, f25, f25
	  fmuls     f0, f27, f27
	  fmuls     f2, f26, f26
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA950C
	  lfs       f0, -0x6EF0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1100
	  fdivs     f25, f25, f1
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1

	.loc_0x1100:
	  lbz       r0, -0x4B58(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x1120
	  rlwinm.   r0,r29,0,24,31
	  bne-      .loc_0x1120
	  lfs       f25, -0x4B08(r13)
	  lfs       f27, -0x4B04(r13)
	  lfs       f26, -0x4B00(r13)

	.loc_0x1120:
	  lwz       r3, 0xC(r31)
	  lfsu      f1, 0xA4(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r3)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA956C
	  fmr       f30, f1
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x6E94(r2)
	  bl        0x14BA8
	  fmuls     f3, f25, f1
	  fmuls     f2, f27, f1
	  fmuls     f0, f26, f1
	  stfs      f3, 0x2B4(r1)
	  lfs       f1, 0x2B4(r1)
	  stfs      f1, 0x398(r1)
	  stfs      f2, 0x39C(r1)
	  stfs      f0, 0x3A0(r1)
	  lwz       r3, 0xC(r31)
	  lfs       f0, 0x398(r1)
	  lfs       f1, 0xA4(r3)
	  addi      r4, r3, 0xA4
	  fadds     f0, f1, f0
	  stfs      f0, 0x2A8(r1)
	  lfs       f0, 0x2A8(r1)
	  stfs      f0, 0x3A4(r1)
	  lfs       f1, 0xA8(r3)
	  lfs       f0, 0x39C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3A8(r1)
	  lfs       f1, 0xAC(r3)
	  lfs       f0, 0x3A0(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3AC(r1)
	  lwz       r3, 0x3A4(r1)
	  lwz       r0, 0x3A8(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x3AC(r1)
	  stw       r0, 0x8(r4)
	  lwz       r3, 0xC(r31)
	  lfs       f1, 0xA4(r3)
	  addi      r26, r3, 0xA4
	  lfs       f0, 0xA8(r3)
	  lfs       f2, 0xAC(r3)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA9620
	  lfs       f0, -0x6EF0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x122C
	  lfs       f0, 0x0(r26)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r26)
	  lfs       f0, 0x4(r26)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r26)
	  lfs       f0, 0x8(r26)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r26)

	.loc_0x122C:
	  lwz       r3, 0xC(r31)
	  addi      r4, r3, 0xA4
	  lfs       f0, 0xA4(r3)
	  fmuls     f0, f0, f30
	  stfs      f0, 0x298(r1)
	  lfs       f0, 0x298(r1)
	  stfs      f0, 0x38C(r1)
	  lfs       f0, 0xA8(r3)
	  fmuls     f0, f0, f30
	  stfs      f0, 0x390(r1)
	  lfs       f0, 0xAC(r3)
	  fmuls     f0, f0, f30
	  stfs      f0, 0x394(r1)
	  lwz       r3, 0x38C(r1)
	  lwz       r0, 0x390(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x394(r1)
	  stw       r0, 0x8(r4)
	  b         .loc_0x1504

	.loc_0x127C:
	  li        r0, 0x4
	  sth       r0, 0x2E(r31)
	  addi      r4, r1, 0x514
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x6EE0(r2)
	  bl        0x14AE0
	  lwz       r5, 0xC(r31)
	  lwz       r3, 0x6C(r31)
	  lwz       r4, 0x504(r5)
	  addi      r5, r5, 0x94
	  addi      r3, r3, 0x5C
	  lfs       f8, 0x8(r5)
	  addi      r4, r4, 0x94
	  lfs       f5, 0x4(r4)
	  lfs       f0, 0x4(r3)
	  lfs       f3, 0x0(r4)
	  lfs       f1, 0x0(r3)
	  fsubs     f27, f5, f0
	  lfs       f7, 0x8(r4)
	  fsubs     f26, f3, f1
	  lfs       f1, 0x8(r3)
	  fmuls     f0, f27, f27
	  fsubs     f28, f7, f1
	  lfs       f6, 0x4(r5)
	  fmuls     f1, f26, f26
	  lfs       f4, 0x0(r5)
	  fmuls     f2, f28, f28
	  fsubs     f30, f8, f7
	  fadds     f0, f1, f0
	  fsubs     f25, f6, f5
	  fsubs     f29, f4, f3
	  fadds     f1, f2, f0
	  bl        -0xA9724
	  lfs       f0, -0x6EF0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1318
	  fdivs     f26, f26, f1
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1

	.loc_0x1318:
	  fmuls     f2, f26, f29
	  lfs       f0, -0x6EF0(r2)
	  fmuls     f1, f27, f25
	  fmuls     f3, f28, f30
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1504
	  lwz       r0, 0x58(r31)
	  fneg      f25, f30
	  lfs       f26, -0x4AFC(r13)
	  rlwinm.   r0,r0,0,31,31
	  bne-      .loc_0x135C
	  lfs       f0, -0x6E8C(r2)
	  fmuls     f25, f25, f0
	  fmuls     f26, f26, f0
	  fmuls     f29, f29, f0

	.loc_0x135C:
	  fmuls     f1, f25, f25
	  fmuls     f0, f26, f26
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA9798
	  lfs       f0, -0x6EF0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x138C
	  fdivs     f25, f25, f1
	  fdivs     f26, f26, f1
	  fdivs     f29, f29, f1

	.loc_0x138C:
	  lbz       r0, -0x4B58(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x13AC
	  rlwinm.   r0,r29,0,24,31
	  bne-      .loc_0x13AC
	  lfs       f25, -0x4AF8(r13)
	  lfs       f26, -0x4AF4(r13)
	  lfs       f29, -0x4AF0(r13)

	.loc_0x13AC:
	  lwz       r3, 0xC(r31)
	  lfsu      f1, 0xA4(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r3)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA97F8
	  fmr       f30, f1
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x6E94(r2)
	  bl        0x1491C
	  fmuls     f3, f25, f1
	  fmuls     f2, f26, f1
	  fmuls     f0, f29, f1
	  stfs      f3, 0x284(r1)
	  lfs       f1, 0x284(r1)
	  stfs      f1, 0x358(r1)
	  stfs      f2, 0x35C(r1)
	  stfs      f0, 0x360(r1)
	  lwz       r3, 0xC(r31)
	  lfs       f0, 0x358(r1)
	  lfs       f1, 0xA4(r3)
	  addi      r4, r3, 0xA4
	  fadds     f0, f1, f0
	  stfs      f0, 0x278(r1)
	  lfs       f0, 0x278(r1)
	  stfs      f0, 0x364(r1)
	  lfs       f1, 0xA8(r3)
	  lfs       f0, 0x35C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x368(r1)
	  lfs       f1, 0xAC(r3)
	  lfs       f0, 0x360(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x36C(r1)
	  lwz       r3, 0x364(r1)
	  lwz       r0, 0x368(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x36C(r1)
	  stw       r0, 0x8(r4)
	  lwz       r3, 0xC(r31)
	  lfs       f1, 0xA4(r3)
	  addi      r26, r3, 0xA4
	  lfs       f0, 0xA8(r3)
	  lfs       f2, 0xAC(r3)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA98AC
	  lfs       f0, -0x6EF0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x14B8
	  lfs       f0, 0x0(r26)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r26)
	  lfs       f0, 0x4(r26)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r26)
	  lfs       f0, 0x8(r26)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r26)

	.loc_0x14B8:
	  lwz       r3, 0xC(r31)
	  addi      r4, r3, 0xA4
	  lfs       f0, 0xA4(r3)
	  fmuls     f0, f0, f30
	  stfs      f0, 0x268(r1)
	  lfs       f0, 0x268(r1)
	  stfs      f0, 0x34C(r1)
	  lfs       f0, 0xA8(r3)
	  fmuls     f0, f0, f30
	  stfs      f0, 0x350(r1)
	  lfs       f0, 0xAC(r3)
	  fmuls     f0, f0, f30
	  stfs      f0, 0x354(r1)
	  lwz       r3, 0x34C(r1)
	  lwz       r0, 0x350(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x354(r1)
	  stw       r0, 0x8(r4)

	.loc_0x1504:
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x224(r3)
	  lfs       f0, 0x288(r4)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x152C
	  lfs       f0, -0x6EF0(r2)
	  li        r0, 0
	  stfs      f0, 0x68(r31)
	  stb       r0, 0x34(r31)
	  b         .loc_0x15CC

	.loc_0x152C:
	  lfs       f0, 0x298(r4)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x15C4
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x68(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x68(r31)
	  lbz       r0, 0x34(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x1598
	  lwz       r5, 0x58(r31)
	  cmpwi     r5, -0x1
	  beq-      .loc_0x1590
	  lwz       r3, 0x6C(r31)
	  lwz       r4, 0xC(r31)
	  bl        -0x117CC
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x1580
	  lwz       r5, 0x14(r31)

	.loc_0x1580:
	  lwz       r3, 0x6C(r31)
	  lwz       r4, 0xC(r31)
	  bl        -0x118E8
	  stw       r3, 0x58(r31)

	.loc_0x1590:
	  li        r0, 0x1
	  stb       r0, 0x34(r31)

	.loc_0x1598:
	  lwz       r0, 0x58(r31)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x15BC
	  lwz       r3, 0xC(r31)
	  lfs       f1, 0x68(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x2A8(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x15CC

	.loc_0x15BC:
	  li        r3, 0x1
	  b         .loc_0x161C

	.loc_0x15C4:
	  li        r3, 0x1
	  b         .loc_0x161C

	.loc_0x15CC:
	  lbz       r0, 0x7E(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1618
	  lbz       r0, 0x7D(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x1618
	  addi      r3, r1, 0x330
	  li        r4, 0x2
	  bl        0x67904
	  addi      r26, r3, 0
	  addi      r3, r1, 0x338
	  li        r4, 0x2
	  bl        0x678F4
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r26
	  bl        0x13364
	  mr        r3, r31
	  bl        0x90

	.loc_0x1618:
	  li        r3, 0

	.loc_0x161C:
	  lmw       r26, 0x550(r1)
	  lwz       r0, 0x5A4(r1)
	  lfd       f31, 0x598(r1)
	  lfd       f30, 0x590(r1)
	  lfd       f29, 0x588(r1)
	  lfd       f28, 0x580(r1)
	  lfd       f27, 0x578(r1)
	  lfd       f26, 0x570(r1)
	  lfd       f25, 0x568(r1)
	  addi      r1, r1, 0x5A0
	  mtlr      r0
	  blr

	.loc_0x164C:
	*/
}

/*
 * --INFO--
 * Address:	800B76B4
 * Size:	000058
 */
void ActCrowd::startZawatuki()
{
	if (!mPiki->hasBomb()) {
		mIsWaiting = true;
		mSelectAction->init(nullptr);
	}
}

/*
 * --INFO--
 * Address:	800B770C
 * Size:	000004
 */
void ActCrowd::finishZawatuki()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void ActCrowd::startBoredom()
{
	switch (_7C) {
	case 0:
		startTalk();
		break;
	case 2:
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Akubi), PaniMotionInfo(PIKIANIM_Akubi));
		break;
	case 3:
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Rinbow), PaniMotionInfo(PIKIANIM_Rinbow));
		break;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void ActCrowd::startTalk()
{
	Iterator iter(&mPiki->mSearchBuffer);
	iter.first();
	Creature* closest     = *iter;
	Vector3f dir          = closest->mPosition - mPiki->mPosition;
	mPiki->mFaceDirection = atan2f(dir.x, dir.z);
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Chatting), PaniMotionInfo(PIKIANIM_Chatting));
}
