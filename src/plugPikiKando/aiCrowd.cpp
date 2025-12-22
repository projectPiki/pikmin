#include "CPlate.h"
#include "DebugLog.h"
#include "GameStat.h"
#include "MoviePlayer.h"
#include "Navi.h"
#include "NaviMgr.h"
#include "PikiAI.h"
#include "PikiInfo.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/arith.h"
#include "ViewPiki.h"
#include "gameflow.h"

static bool newVer = true;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(20)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("aiCrowd")

/**
 * @TODO: Documentation
 */
ActCrowd::ActCrowd(Piki* piki)
    : Action(piki, true)
{
	setName("crowd");
	mPlateMgr     = nullptr;
	mCPlateSlotID = -1;
	mSelectAction = new ActBoreSelect(piki);
}

/**
 * @TODO: Documentation
 */
void ActCrowd::inform(int slotID)
{
	mCPlateSlotID = slotID;
}

/**
 * @TODO: Documentation
 */
void ActCrowd::startSort()
{
	mState = STATE_Sort;
	mSelectAction->stop();
}

/**
 * @TODO: Documentation
 */
void ActCrowd::init(Creature* target)
{
	mMode      = 5;
	_30        = 5;
	_32        = 0;
	mIsWaiting = false;
	_7E        = false;
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
	_34              = false;
	_35              = false;
	_36              = false;
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
	mLostChildTimer = 5.0f;
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

/**
 * @TODO: Documentation
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

		_36 = true;
	}
}

/**
 * @TODO: Documentation
 */
void ActCrowd::procWallMsg(Piki*, MsgWall* msg)
{
	if (mCPlateSlotID != -1) {
		_70 = msg->mWallPlane->mNormal;
		_35 = true;
	}
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
int ActCrowd::exec()
{
	_30   = mMode;
	mMode = 5;
	if (mHasRoute) {
		exeRouteMove();
		if (mPiki->mUseAsyncPathfinding) {
			mLostChildTimer -= gsys->getFrameTime();
			if (mLostChildTimer < 0.0f) {
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

	Vector3f effDir = static_cast<ViewPiki*>(mPiki)->mLastEffectPosition - mPiki->mSRT.t;
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
		if (gsys->getRand(1.0f) >= 0.9999f && gsys->getRand(1.0f) > 0.7f) {
			mIsTripping      = true;
			mTripLoopCounter = int((4.0f * gsys->getRand(1.0f))) + 3; // length of trip is a random number of anim loops, between 3 and 7
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Korobu, mPiki), PaniMotionInfo(PIKIANIM_Korobu));
			return ACTOUT_Continue;
		}

		_60 = 0.0f;
	}

	Vector3f plateDir = platePos - mPiki->mSRT.t;
	f32 plateDist2D   = std::sqrtf(plateDir.x * plateDir.x + plateDir.z * plateDir.z);
	plateDir.normalise();

	if (plateDist2D < 60.0f && mPiki->mNavi->_724 && mState != STATE_Sort) {
		if (!mIsWaiting && mPiki->mNavi->mNeutralTime - (2.0f * gsys->getRand(1.0f)) >= C_NAVI_PROP(mPiki->mNavi)._34C()) {
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
				platePos = minPiki->mSRT.t;
			} else {
				platePos = mPiki->mNavi->mSRT.t;
			}

			STACK_PAD_VAR(1);
			mIsWaiting       = false;
			Vector3f moveDir = platePos - mPiki->mSRT.t;
			f32 moveDist     = moveDir.normalise();
			moveDist         = qdist2(platePos.x, platePos.z, mPiki->mSRT.t.x, mPiki->mSRT.t.z);
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
		Vector3f naviDir = mPiki->mNavi->mSRT.t - mPiki->mSRT.t;
		f32 diff         = atan2f(naviDir.x, naviDir.z);
		mPiki->mFaceDirection += 0.3f * angDist(diff, mPiki->mFaceDirection);
		if (!gameflow.mMoviePlayer->mIsActive && !mIsWaiting
		    && mPiki->mNavi->mNeutralTime - (2.0f * gsys->getRand(1.0f)) >= C_NAVI_PROP(mPiki->mNavi)._34C()) {
			mIsWaiting = true;
			startZawatuki();
		}
		return ACTOUT_Continue;
	}

	if (plateDist2D <= 7.0f) {
		_32 = 0;
	} else if (plateDist2D < 15.0f) {
		_32++;
		if (_30 == 2 && mPiki->mNavi->mNeutralTime > 0.1f) {
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
		plateDir  = mPiki->mNavi->mSRT.t - mPiki->mSRT.t;
		f32 diff  = atan2f(plateDir.x, plateDir.z);
		f32 angle = angDist(diff, mPiki->mFaceDirection);
		mPiki->mFaceDirection += 0.3f * angle;
		if (mState != STATE_Formed) {
			pikiInfo->addFormationPiki();
			setFormed();
		}

		if (!gameflow.mMoviePlayer->mIsActive && !mIsWaiting
		    && mPiki->mNavi->mNeutralTime - (5.0f * gsys->getRand(1.0f)) >= C_NAVI_PROP(mPiki->mNavi)._34C()) {
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
			    && mPiki->mNavi->mNeutralTime - (5.0f * gsys->getRand(1.0f)) >= C_NAVI_PROP(mPiki->mNavi)._34C()) {
				mIsWaiting = true;
				startZawatuki();
			}
			plateDir  = mPiki->mNavi->mSRT.t - mPiki->mSRT.t;
			f32 diff  = atan2f(plateDir.x, plateDir.z);
			f32 angle = angDist(diff, mPiki->mFaceDirection);
			mPiki->mFaceDirection += 0.3f * angle;
		} else if (plateDist2D < val1) {
			f32 val3               = speed2 + 0.5f * speedy_sqrtf(speed2 * speed2 + 8.0f * factor * plateDist2D);
			mPiki->mTargetVelocity = plateDir * val3;
		} else {
			mPiki->setSpeed(1.0f, plateDir);
		}

		Vector3f pikiDir      = mPiki->mSRT.t - mPiki->mNavi->mSRT.t;
		Vector3f naviPlateDir = mPiki->mNavi->mSRT.t - mPlateMgr->mPlateOffset;
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

		Vector3f pikiDir      = mPiki->mSRT.t - mPiki->mNavi->mSRT.t;
		Vector3f naviPlateDir = mPiki->mNavi->mSRT.t - mPlateMgr->mPlateOffset;
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

	if (plateDist2D < C_PIKI_PROP(mPiki).mFormationSlipRange()) {
		mLostChildTimer = 0.0f;
		_34             = false;
	} else if (plateDist2D < C_PIKI_PROP(mPiki).mFormationBreakRange()) {
		mLostChildTimer += gsys->getFrameTime();
		if (!_34) {
			if (mCPlateSlotID != -1) {
				mPlateMgr->releaseSlot(mPiki, mCPlateSlotID);
				mCPlateSlotID = mPlateMgr->getSlot(mPiki, this);
			}

			_34 = true;
		}
		if (mCPlateSlotID == -1 || mLostChildTimer > C_PIKI_PROP(mPiki).mMaxLostChildTime()) {
			return ACTOUT_Fail;
		}
	} else {
		return ACTOUT_Fail;
	}

	STACK_PAD_STRUCT(3);
	STACK_PAD_VAR(4);
	STACK_PAD_TERNARY(mPiki, 11);

	if (_7E && !mIsWaiting) {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
		finishZawatuki();
	}

	return ACTOUT_Continue;
}

/**
 * @TODO: Documentation
 */
void ActCrowd::startZawatuki()
{
	if (!mPiki->hasBomb()) {
		mIsWaiting = true;
		mSelectAction->init(nullptr);
	}
}

/**
 * @TODO: Documentation
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
	switch (mBoredomMotion) {
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
	Vector3f dir          = closest->mSRT.t - mPiki->mSRT.t;
	mPiki->mFaceDirection = atan2f(dir.x, dir.z);
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Chatting), PaniMotionInfo(PIKIANIM_Chatting));
}
