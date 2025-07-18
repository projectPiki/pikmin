#include "NaviState.h"
#include "AIConstant.h"
#include "Dolphin/os.h"
#include "EffectMgr.h"
#include "FlowController.h"
#include "GameCoreSection.h"
#include "GameStat.h"
#include "Interactions.h"
#include "Interface.h"
#include "KMath.h"
#include "KeyConfig.h"
#include "Kontroller.h"
#include "MapCode.h"
#include "MoviePlayer.h"
#include "NaviMgr.h"
#include "Pcam/Camera.h"
#include "Pcam/CameraManager.h"
#include "Pellet.h"
#include "PikiAI.h"
#include "PikiHeadItem.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "Stickers.h"
#include "UfoItem.h"
#include "UtilityKando.h"
#include "gameflow.h"
#include "sysNew.h"
#include "teki.h"
#include "zen/DrawContainer.h"

#include "CPlate.h"
#include "DebugLog.h"
#include "GoalItem.h"
#include "UtEffect.h"
#include "jaudio/pikidemo.h"

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
DEFINE_PRINT("naviState");

/*
 * --INFO--
 * Address:	80101140
 * Size:	000008
 */
NaviState* NaviStateMachine::getNaviState(Navi* navi)
{
	return static_cast<NaviState*>(navi->mCurrState);
}

/*
 * --INFO--
 * Address:	80101148
 * Size:	0015D4
 */
void NaviStateMachine::init(Navi* navi)
{
	create(NAVISTATE_Count);
	registerState(new NaviWalkState());
	registerState(new NaviStuckState());
	registerState(new NaviFlickState());
	registerState(new NaviGeyzerState());
	registerState(new NaviContainerState());
	registerState(new NaviUfoState());
	registerState(new NaviPartsAccessState());
	registerState(new NaviUfoAccessState());
	registerState(new NaviPikiZeroState());
	registerState(new NaviPickState());
	registerState(new NaviRopeState());
	registerState(new NaviRopeExitState());
	registerState(new NaviGatherState());
	registerState(new NaviReleaseState());
	registerState(new NaviThrowWaitState());
	registerState(new NaviThrowState());
	registerState(new NaviFunbariState());
	registerState(new NaviPushState());
	registerState(new NaviPushPikiState());
	registerState(new NaviBuryState());
	registerState(new NaviNukuState());
	registerState(new NaviNukuAdjustState());
	registerState(new NaviWaterState());
	registerState(new NaviSowState());
	registerState(new NaviPressedState());
	registerState(new NaviClearState());
	registerState(new NaviLockState());
	registerState(new NaviAttackState());
	registerState(new NaviIroIroState());
	registerState(new NaviDeadState());
	registerState(new NaviIdleState());
	registerState(new NaviStartingState());
	registerState(new NaviDemoWaitState());
	registerState(new NaviDemoInfState());
	registerState(new NaviPelletState());
	registerState(new NaviDemoSunsetState());
}

/*
 * --INFO--
 * Address:	8010271C
 * Size:	000044
 */
NaviPelletState::NaviPelletState()
    : NaviState(NAVISTATE_Pellet)
{
}

/*
 * --INFO--
 * Address:	80102760
 * Size:	00006C
 */
void NaviPelletState::init(Navi* navi)
{
	navi->becomePellet('navi', navi->mPosition, navi->mFaceDirection);
	navi->mIsPellet = true;
	mIsFinished     = false;
	seMgr->playNaviSound(0, 0);
}

/*
 * --INFO--
 * Address:	801027CC
 * Size:	000200
 */
void NaviPelletState::exec(Navi* navi)
{
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	if (!mIsFinished && navi->mPellet) {
		navi->mPosition = navi->mPellet->mPosition;
	}

	if (!mIsFinished && (!navi->mPellet || !navi->mPellet->isAlive())) {
		if (navi->mPellet) {
			navi->mPellet->kill(false);
		}
		mIsFinished = true;
		navi->setPellet(false);
		navi->startMotion(PaniMotionInfo(PIKIANIM_GetUp, navi), PaniMotionInfo(PIKIANIM_GetUp));
	}

	if (!mIsFinished
	    && (navi->mKontroller->keyDown(KBBTN_A) || navi->mKontroller->keyDown(KBBTN_B) || navi->mKontroller->keyDown(KBBTN_X)
	        || navi->mKontroller->keyDown(KBBTN_L) || navi->mKontroller->keyDown(KBBTN_R) || navi->mKontroller->keyDown(KBBTN_MSTICK_LEFT)
	        || navi->mKontroller->keyDown(KBBTN_MSTICK_RIGHT) || navi->mKontroller->keyDown(KBBTN_MSTICK_UP)
	        || navi->mKontroller->keyDown(KBBTN_MSTICK_DOWN) || navi->mKontroller->keyDown(KBBTN_CSTICK_LEFT)
	        || navi->mKontroller->keyDown(KBBTN_CSTICK_RIGHT) || navi->mKontroller->keyDown(KBBTN_CSTICK_UP)
	        || navi->mKontroller->keyDown(KBBTN_CSTICK_DOWN))) {
		mIsFinished = true;
		if (navi->mPellet) {
			navi->mPellet->kill(false);
		}

		PRINT("GETUP MOTION START\n");

		navi->setPellet(false);
		navi->startMotion(PaniMotionInfo(PIKIANIM_GetUp, navi), PaniMotionInfo(PIKIANIM_GetUp));
	}
}

/*
 * --INFO--
 * Address:	801029CC
 * Size:	000050
 */
void NaviPelletState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mIsFinished) {
			PRINT("exit pellet state\n");
			transit(navi, NAVISTATE_Walk);
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	80102A4C
 * Size:	000044
 */
void NaviPelletState::cleanup(Navi* navi)
{
	if (navi->mPellet) {
		navi->mPellet->kill(false);
	}

	navi->setPellet(false);
}

/*
 * --INFO--
 * Address:	80102A90
 * Size:	000054
 */
NaviDemoWaitState::NaviDemoWaitState()
    : NaviState(NAVISTATE_DemoWait)
{
}

/*
 * --INFO--
 * Address:	80102AE4
 * Size:	0000C8
 */
void NaviDemoWaitState::init(Navi* navi)
{
	gameflow.mMoviePlayer->getLookAtPos(mLookAtPos);
	navi->startLook(&mLookAtPos);
	navi->startMotion(PaniMotionInfo(PIKIANIM_Wait), PaniMotionInfo(PIKIANIM_Wait));
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (navi->mGoalItem) {
		navi->mGoalItem->setSpotActive(false);
	}
	PRINT_GLOBAL("orima demo wait start");
}

/*
 * --INFO--
 * Address:	80102BAC
 * Size:	0000EC
 */
void NaviDemoWaitState::exec(Navi* navi)
{
	gameflow.mMoviePlayer->getLookAtPos(mLookAtPos);
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
	if (!gameflow.mMoviePlayer->mIsActive) {
		navi->mNaviLightEfx->restart();
		navi->mNaviLightGlowEfx->restart();

		PRINT("RETURN TO WALK : MOVIE END \n");
		if (navi->isDamaged()) {
			PRINT_GLOBAL("finish orima damage");
			navi->finishDamage();
		}

		transit(navi, NAVISTATE_Walk);
	}
}

/*
 * --INFO--
 * Address:	80102C98
 * Size:	000084
 */
void NaviDemoWaitState::cleanup(Navi* navi)
{
	PRINT("*** DEMOWAIT CLEANUP\n");
	navi->finishLook();
	f32 minY = mapMgr->getMinY(navi->mPosition.x, navi->mPosition.z, true);
	f32 maxY = mapMgr->getMaxY(navi->mPosition.x, navi->mPosition.z, true);

	PRINT("navi(%.1f %.1f %.1f) : map(%.1f %.1f %.1f)\n", navi->mPosition.x, navi->mPosition.y, navi->mPosition.z, navi->mPosition.x, minY,
	      navi->mPosition.z);

	PRINT("** %.1f ===> %.1f %.1f\n", navi->mPosition.y, minY, maxY);

	if (maxY > navi->mPosition.y || minY > navi->mPosition.y) {
		// don't clip navi into the ground
		navi->mPosition.y = maxY;
	} else {
		// don't have navi floating in the air
		navi->mPosition.y = minY;
	}
}

/*
 * --INFO--
 * Address:	80102D1C
 * Size:	000044
 */
NaviDemoInfState::NaviDemoInfState()
    : NaviState(NAVISTATE_DemoInf)
{
}

/*
 * --INFO--
 * Address:	80102D60
 * Size:	000004
 */
void NaviDemoInfState::init(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80102D64
 * Size:	00001C
 */
void NaviDemoInfState::exec(Navi* navi)
{
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80102D80
 * Size:	000004
 */
void NaviDemoInfState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80102D84
 * Size:	000054
 */
NaviStuckState::NaviStuckState()
    : NaviState(NAVISTATE_Stuck)
{
}

/*
 * --INFO--
 * Address:	80102DD8
 * Size:	000090
 */
void NaviStuckState::init(Navi* navi)
{
	mActionCount = 0;
	Vector3f stick(navi->mKontroller->getMainStickX(), 0.0f, navi->mKontroller->getMainStickY());
	mPrevStickDir = stick;
	mIdleTimer    = 0.45;
	navi->releasePikis();
}

/*
 * --INFO--
 * Address:	80102E68
 * Size:	000340
 */
void NaviStuckState::exec(Navi* navi)
{
	if (!navi->mStickListHead) {
		transit(navi, NAVISTATE_Walk);
		return;
	}

	navi->makeVelocity(false);
	Vector3f currStickDir(navi->mKontroller->getMainStickX(), 0.0f, navi->mKontroller->getMainStickY());

	/*
	    check if we've either:
	    - moved stick at least 107 degrees from last time we checked
	    - hit the A button
	    - hit the B button
	*/
	if (currStickDir.DP(mPrevStickDir) < -0.3f || navi->mKontroller->keyClick(KBBTN_A) || navi->mKontroller->keyClick(KBBTN_B)) {
		mActionCount++;

		// int minFlickActions = ;
		if (mActionCount > C_NAVI_PROP(navi).mMinKinokoFlickActions()) {
			// after a certain amount of recorded actions, try and flick a puffmin
			Stickers stickers(navi);
			Iterator iter(&stickers);
			CI_LOOP(iter)
			{
				Creature* stuck = *iter; // 50/50 chance to flick a given puffmin
				if (!stuck || !(gsys->getRand(1.0f) > 0.5f)) {
					continue;
				}

				if (stuck->stimulate(InteractFlick(navi, 220.0f, 5.0f, FLICK_BACKWARDS_ANGLE))) {
					playerState->mResultFlags.setOn(RESFLAG_Kinoko);
					iter.dec();
				}
			}

			// reset the action count after a flick attempt
			mActionCount = 0;
		}

		// update stick direction and reset timer
		mPrevStickDir = currStickDir;
		mIdleTimer    = 0.45f;
	}

	mIdleTimer -= gsys->getFrameTime();
	if (mIdleTimer < 0.0f) {
		// no recorded actions in too long; reset stick direction, action count and timer
		mPrevStickDir = currStickDir;
		mActionCount  = 0;
		mIdleTimer    = 0.45f;
	}
}

/*
 * --INFO--
 * Address:	801031A8
 * Size:	000004
 */
void NaviStuckState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	801031AC
 * Size:	000054
 */
NaviBuryState::NaviBuryState()
    : NaviState(NAVISTATE_Bury)
{
}

/*
 * --INFO--
 * Address:	80103200
 * Size:	00010C
 */
void NaviBuryState::init(Navi* navi)
{
	navi->startMotion(PaniMotionInfo(PIKIANIM_GWait1, navi), PaniMotionInfo(PIKIANIM_GWait1));
	mBuryState           = 0;
	mValidEscapeAttempts = 0;
	effectMgr->create(EffectMgr::EFF_SD_DirtCloud, navi->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_SD_DirtSpray, navi->mPosition, nullptr, nullptr);
	mPreviousStickInput.set(0.0f, 0.0f, 0.0f);
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mEscapeTimer = 150;
}

/*
 * --INFO--
 * Address:	8010330C
 * Size:	000310
 */
void NaviBuryState::exec(Navi* navi)
{
	Vector3f stickInput(navi->mKontroller->getMainStickX(), 0.0f, navi->mKontroller->getMainStickY());
	navi->reviseController(stickInput);

	f32 stickMag = std::sqrtf(stickInput.x * stickInput.x + stickInput.z * stickInput.z);

	switch (mBuryState) {
	case 0:
		if ((stickMag > 0.8f && mPreviousStickInput.dot(stickInput) < 0.5f) || navi->mKontroller->keyClick(KBBTN_A)
		    || navi->mKontroller->keyClick(KBBTN_B)) {
			mPreviousStickInput   = stickInput;
			mBuryState            = 1;
			mEscapeAttemptCounter = 0;
			mValidEscapeAttempts  = 0;
			navi->startMotion(PaniMotionInfo(PIKIANIM_GFuri1, navi), PaniMotionInfo(PIKIANIM_GFuri1));
		}
		break;
	case 1:
	case 2:
		if ((stickMag > 0.8f && mPreviousStickInput.dot(stickInput) < -0.6f) || navi->mKontroller->keyClick(KBBTN_A)
		    || navi->mKontroller->keyClick(KBBTN_B)) {
			mEscapeAttemptCounter++;
			mPreviousStickInput = stickInput;
			if (mBuryState == 1) {
				mBuryState    = 2;
				f32 frame1Val = navi->mNaviAnimMgr.getUpperAnimator().mAnimationCounter;
				navi->startMotion(PaniMotionInfo(PIKIANIM_GFuri2, navi), PaniMotionInfo(PIKIANIM_GFuri2));
				navi->mNaviAnimMgr.getUpperAnimator().mAnimationCounter = frame1Val;
				navi->mNaviAnimMgr.getLowerAnimator().mAnimationCounter = frame1Val;
			}
		}
		break;
	}

	if (mEscapeTimer) {
		mEscapeTimer--;
		if (mEscapeTimer == 0) {
			mBuryState = 3;
			navi->startMotion(PaniMotionInfo(PIKIANIM_GNuke, navi), PaniMotionInfo(PIKIANIM_GNuke));
		}
	}
}

/*
 * --INFO--
 * Address:	8010361C
 * Size:	0003D4
 */
void NaviBuryState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	STACK_PAD_VAR(2);
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
	case KEY_LoopEnd:
		switch (mBuryState) {
		case 0:
			if (gsys->getRand(1.0f) > 0.66f) {
				navi->startMotion(PaniMotionInfo(PIKIANIM_GWait2, navi), PaniMotionInfo(PIKIANIM_GWait2));
			} else {
				navi->startMotion(PaniMotionInfo(PIKIANIM_GWait1, navi), PaniMotionInfo(PIKIANIM_GWait1));
			}
			break;
		case 1:
		case 2:
			if (mEscapeAttemptCounter == 0) {
				navi->startMotion(PaniMotionInfo(PIKIANIM_GWait1, navi), PaniMotionInfo(PIKIANIM_GWait1));
				mBuryState = 0;
			} else if (mEscapeAttemptCounter >= static_cast<NaviProp*>(navi->mProps)->mNaviProps._40C()) {
				mValidEscapeAttempts++;
				if (mValidEscapeAttempts >= static_cast<NaviProp*>(navi->mProps)->mNaviProps._41C()) {
					mBuryState = 3;
					navi->startMotion(PaniMotionInfo(PIKIANIM_GNuke, navi), PaniMotionInfo(PIKIANIM_GNuke));
				}
				mEscapeAttemptCounter = 0;
			} else {
				navi->startMotion(PaniMotionInfo(PIKIANIM_GWait1, navi), PaniMotionInfo(PIKIANIM_GWait1));
				mBuryState            = 0;
				mValidEscapeAttempts  = 0;
				mEscapeAttemptCounter = 0;
			}
			break;
		case 3:
			transit(navi, NAVISTATE_Walk);
			break;
		}
		break;
	case KEY_PlayEffect:
		switch (mBuryState) {
		case 2:
			f32 randAngle = 2.0f * (PI * gsys->getRand(1.0f));
			f32 height    = 80.0f;
			Vector3f dir(40.0f * sinf(randAngle), height, 40.0f * cosf(randAngle));
			EffectParm parm(navi->mPosition, dir);
			UtEffectMgr::cast(KandoEffect::SmokeSoil, parm);
			break;
		case 3:
			effectMgr->create(EffectMgr::EFF_SD_DirtCloud, navi->mPosition, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_SD_DirtSpray, navi->mPosition, nullptr, nullptr);
			break;
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	801039F0
 * Size:	000004
 */
void NaviBuryState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	801039F4
 * Size:	000040
 */
NaviWalkState::NaviWalkState()
    : NaviState(NAVISTATE_Walk)
{
}

/*
 * --INFO--
 * Address:	80103A34
 * Size:	000084
 */
void NaviWalkState::init(Navi* navi)
{
	navi->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
	_14 = 1.0f;
	_18 = 0;
	_1C = 0.0f;
	_10 = 0;
}

/*
 * --INFO--
 * Address:	80103AB8
 * Size:	00002C
 */
void NaviWalkState::restart(Navi* navi)
{
	init(navi);
}

/*
 * --INFO--
 * Address:	80103AE4
 * Size:	000DE8
 */
void NaviWalkState::exec(Navi* navi)
{
	STACK_PAD_VAR(1);
	if (navi->mStickListHead) {
		transit(navi, NAVISTATE_Stuck);
		return;
	}

	if (navi->demoCheck()) {
		return;
	}

	if (gameflow.mMoviePlayer->mIsActive) {
		return;
	}

	if (playerState->inDayEnd()) {
		return;
	}

	if (!(navi->mTargetVelocity.length() < 1.0f)) {
		navi->finishFixPosition();
	}

	for (int i = 0; i < 3; i++) {
		GoalItem* onyon = itemMgr->getContainer(i);
		if (!onyon) {
			continue;
		}
		CollPart* coll = onyon->mCollInfo->getSphere('cont');
		if (navi->roughCulling(onyon, (navi->getSize() + coll->mRadius) * 1.5f)) {
			onyon->setSpotActive(false);
			continue;
		}
		Vector3f diff = coll->mCentre - navi->getCentre();
		if (diff.length() <= navi->getSize() + coll->mRadius) {
			onyon->setSpotActive(true);
			if (navi->mKontroller->keyClick(KBBTN_A)) {
				navi->mGoalItem = onyon;
				rumbleMgr->start(RUMBLE_Unk2, 0, nullptr);
				transit(navi, NAVISTATE_Container);
				return;
			}
		} else {
			onyon->setSpotActive(false);
		}
	}

	UfoItem* ufo = itemMgr->getUfo();
	if (ufo && ufo->accessible()) {
		Vector3f goal = ufo->getGoalPos();
		f32 radius    = ufo->getGoalPosRadius();
		goal          = goal - navi->mPosition;
		if (goal.length() <= 40.0f) {
			ufo->setSpotTurn(true);
			if (navi->mKontroller->keyClick(KBBTN_A)) {
				PRINT("UFO ACCESS!\n");
				transit(navi, NAVISTATE_Ufo);
				return;
			}
		} else {
			ufo->setSpotTurn(false);
		}
	} else if (ufo) {
		ufo->setSpotTurn(false);
	}

	navi->findNextThrowPiki();
	if (navi->mGroundTriangle && navi->_AD0 && (navi->_AD0 != navi->mGroundTriangle)) {
		Vector3f vel(navi->mVelocity);
		vel.normalise();
		f32 nrm1   = navi->_AD0->mTriangle.mNormal.DP(vel);
		f32 nrm2   = navi->_AD0->mTriangle.mNormal.DP(Vector3f(0.0f, 1.0f, 0.0f));
		f32 nrm3   = navi->_AD0->mTriangle.mNormal.DP(navi->mGroundTriangle->mTriangle.mNormal);
		f32 y      = navi->mGroundTriangle->mTriangle.mNormal.y;
		f32 maxLen = -1.0f;
		int index  = -1;
		for (int i = 0; i < 3; i++) {
			f32 len = navi->mGroundTriangle->mEdgePlanes[i].mNormal.DP(vel);
			if (len > maxLen) {
				len   = maxLen; // nice one kando.
				index = i;
			}
		}

		(void)navi->mGroundTriangle->mEdgePlanes[index];
		if (quickABS(navi->_AD0->mTriangle.mNormal.y) <= 0.01f) {
			Plane* plane = &navi->mGroundTriangle->mEdgePlanes[index];
			PRINT(" cliff dist = %.1f\n", plane->dist(navi->mPosition) - navi->mCollisionRadius);
			navi->_AD8 = plane->dist(navi->mPosition);
		} else {
			navi->_AD8 = 0.0f;
		}

		STACK_PAD_TERNARY(navi->mGroundTriangle, 1);

		if (quickABS(y) > cosf(THIRD_PI) && nrm1 >= cosf(QUARTER_PI) && nrm3 < sinf(THIRD_PI)) {
			vel             = vel * 100.0f;
			vel.y           = 200.0f;
			navi->mVelocity = vel;
			PRINT("jump !!\n");
		}
	}
	STACK_PAD_VAR(1);
	navi->makeVelocity(false);

	if (!playerState->isTutorial() && navi->mGroundTriangle && navi->mKontroller->keyClick(KBBTN_DPAD_DOWN)) {
		navi->mStateMachine->transit(navi, NAVISTATE_Pellet);
		return;
	}

	if (navi->mKontroller->keyClick(KeyConfig::_instance->mDisbandKey.mBind)) {
		transit(navi, NAVISTATE_Release);
	}

	if (navi->mKontroller->keyClick(KBBTN_X)) {
		if (pikiMgr->findClosest(navi->mPosition, nullptr)) {
			PRINT("here is %s\n", navi->mNextThrowPiki->isSafeMePos(navi->mPosition) ? 'o' : 'x');
		}
		if (navi->mGroundTriangle && MapCode::isBald(navi->mGroundTriangle)) {
			PRINT("\tcurr polygon is bald\n");
		} else {
			PRINT("\tno teppe!\n");
		}
	}

	if (navi->mKontroller->keyClick(KeyConfig::_instance->mSetCursorKey.mBind)) {
		if (KeyConfig::_instance->mSetCursorKey.mBind == KeyConfig::_instance->mExtractKey.mBind) {
			if (navi->procActionButton() && navi->mIsCursorVisible) {
				transit(navi, NAVISTATE_Gather);
			}
		} else if (navi->mIsCursorVisible) {
			transit(navi, NAVISTATE_Gather);
			return;
		}
		return;
	}

	if (navi->mKontroller->keyClick(KeyConfig::_instance->mThrowKey.mBind)) {

		if (AIConstant::_instance->mConstants._E4()) {
			if (KeyConfig::_instance->mThrowKey.mBind == KeyConfig::_instance->mExtractKey.mBind) {
				if (!navi->procActionButton()) {
					transit(navi, NAVISTATE_ThrowWait);
					return;
				}
				return;
			}
			transit(navi, NAVISTATE_ThrowWait);
			return;
		}
		Piki* nearestPiki = nullptr;
		f32 maxDist       = C_NAVI_PROP(navi)._1BC();
		Iterator it(navi->mPlateMgr);
		CI_LOOP(it)
		{
			Piki* piki = (Piki*)*it;
			if (!roughCull(piki, navi, maxDist)) {
				f32 distance = qdist2(piki, navi);
				if (distance < maxDist && piki->getState() == 0 && !piki->isHolding()) {
					nearestPiki = piki;
					maxDist     = distance;
				}
			}
		}

		if (nearestPiki) {
			PRINT("roll over narita\n");
			Vector3f dir(sinf(navi->mFaceDirection), 0.0f, cosf(navi->mFaceDirection));
			nearestPiki->setSpeed(1.0f, dir);
			nearestPiki->mVelocity = nearestPiki->mTargetVelocity;
			nearestPiki->mPosition = navi->mPosition + navi->getCentreSize() * dir;
			nearestPiki->mFSM->transit(nearestPiki, PIKISTATE_Bullet);
			return;
		}
		if (KeyConfig::_instance->mThrowKey.mBind == KeyConfig::_instance->mAttackKey.mBind) {
			Iterator it(tekiMgr);
			CI_LOOP(it)
			{
				Creature* teki = *it;
				if (!roughCull(teki, navi, teki->getCentreSize() + navi->getCentreSize() + 10.0f) && teki->isAlive() && teki->isVisible()
				    && !teki->isFlying() && teki->isOrganic()) {
					Vector3f diff = teki->mPosition - navi->mPosition;
					f32 unused    = atan2f(diff.x, diff.z);
					if (diff.length() <= teki->getCentreSize() + navi->getCentreSize() + 10.0f) {
						transit(navi, NAVISTATE_Attack);
						return;
					}
				}
			}
		}
	}

	_10 = 0;
	if (navi->mNeutralTime > 10.0f) {
		transit(navi, NAVISTATE_Idle);
	}

	STACK_PAD_VAR(1);
	STACK_PAD_STRUCT(1);
	STACK_PAD_TERNARY(navi, 1);
}

/*
 * --INFO--
 * Address:	801048CC
 * Size:	000024
 */
void NaviWalkState::cleanup(Navi* navi)
{
	navi->finishFixPosition();
}

/*
 * --INFO--
 * Address:	801048F0
 * Size:	000060
 */
void NaviWalkState::procWallMsg(Navi* navi, MsgWall* msg)
{
	if (_18 == 0) {
		_18 = 1;
		_1C = 0.0f;
	}

	Vector3f nrm         = *msg->mWallNormal;
	navi->mFaceDirection = atan2f(-nrm.x, -nrm.z);
}

/*
 * --INFO--
 * Address:	80104950
 * Size:	000014
 */
void NaviWalkState::procOffWallMsg(Navi* navi, MsgOffWall* msg)
{
	_18 = 0;
	_1C = 0.0f;
}

/*
 * --INFO--
 * Address:	80104964
 * Size:	00000C
 */
void NaviWalkState::procCollideMsg(Navi* navi, MsgCollide* msg)
{
	_10 = msg->mEvent.mCollider;
}

/*
 * --INFO--
 * Address:	80104970
 * Size:	000054
 */
NaviUfoState::NaviUfoState()
    : NaviState(NAVISTATE_Ufo)
{
}

/*
 * --INFO--
 * Address:	801049C4
 * Size:	000088
 */
void NaviUfoState::init(Navi* navi)
{
	PRINT("*** UFO STATE GOT HERE !!\n");
	UfoItem* ufo = itemMgr->getUfo();
	if (ufo) {
		ufo->startAccess();
	}

	mState = 0;
	navi->mOdoMeter.start(0.5f, 8.0f);
	GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk2 | COREPAUSE_Unk16);
	Jac_StartPartsFindDemo(0, 1);
	_21                 = false;
	mPunchCooldownTimer = 0;
}

/*
 * --INFO--
 * Address:	80104A4C
 * Size:	0000B8
 */
void NaviUfoState::procCollideMsg(Navi* navi, MsgCollide* msg)
{
	if (mState != 1 && mState != 2) {
		navi->startMotion(PaniMotionInfo(PIKIANIM_Punch, navi), PaniMotionInfo(PIKIANIM_Punch));
		mState = 1;
		effectMgr->create(EffectMgr::EFF_Rocket_NaviRecover, navi->mPosition, nullptr, nullptr);
	}
}

/*
 * --INFO--
 * Address:	80104B04
 * Size:	000468
 */
void NaviUfoState::exec(Navi* navi)
{
	if (mState == 0) {
		UfoItem* onion      = itemMgr->getUfo();
		Vector3f goalPos    = onion->getGoalPos();
		goalPos             = goalPos - navi->mPosition;
		f32 distanceToOnion = goalPos.normalise();

		// Check if within valid range
		if (distanceToOnion < 10.0f) {
			if (!_21) {
				mPunchCooldownTimer = 20;
			}

			_21 = true;

			f32 rotDelta = angDist(roundAng(-onion->mFaceDirection), navi->mFaceDirection);
			navi->mVelocity.set(0.0f, 0.0f, 0.0f);
			navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

			if (absF(rotDelta) < (PI / 20.0f)) {
				navi->startMotion(PaniMotionInfo(PIKIANIM_Punch, navi), PaniMotionInfo(PIKIANIM_Punch));
				mState = 1;
				effectMgr->create(EffectMgr::EFF_Rocket_NaviRecover, navi->mPosition, nullptr, nullptr);
				PRINT("** ANG OK RECOVER!\n");
			} else {
				navi->mFaceDirection = roundAng(navi->mFaceDirection + 0.1f * rotDelta);
				if (--mPunchCooldownTimer <= 0) {
					PRINT_GLOBAL("ang timer done\n");
					navi->startMotion(PaniMotionInfo(PIKIANIM_Punch, navi), PaniMotionInfo(PIKIANIM_Punch));
					mState = 1;
					PRINT("ang time out recover !!\n");
					effectMgr->create(EffectMgr::EFF_Rocket_NaviRecover, navi->mPosition, nullptr, nullptr);
				}
			}

		} else if (!navi->mOdoMeter.moving(navi->mPosition, mLastPosition)) {
			PRINT("giveup using odometer!\n");
			PRINT_GLOBAL("giveup using odometer");
			navi->startMotion(PaniMotionInfo(PIKIANIM_Punch, navi), PaniMotionInfo(PIKIANIM_Punch));
			mState = 1;
			effectMgr->create(EffectMgr::EFF_Rocket_NaviRecover, navi->mPosition, nullptr, nullptr);
			navi->mVelocity.set(0.0f, 0.0f, 0.0f);
			navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			return;
		} else {
			PRINT("manda !\n");
			mLastPosition         = navi->mPosition;
			navi->mVelocity       = goalPos * 60.0f;
			navi->mTargetVelocity = goalPos * 60.0f;
		}
	}

	if (mState == 1) {
		navi->mVelocity.set(0.0f, 0.0f, 0.0f);
		navi->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}

	if (mState == 2 && --mRecoveryTimer == 0) {
		gameflow.mGameInterface->message(0, 25);
		mState = 3;
	}

	if (mState == 3 && !gameflow.mIsUiOverlayActive) {
		transit(navi, NAVISTATE_Walk);
	}
}

/*
 * --INFO--
 * Address:	80104F6C
 * Size:	000048
 */
void NaviUfoState::cleanup(Navi* navi)
{
	navi->mHealth = static_cast<NaviProp*>(navi->mProps)->mNaviProps.mHealth();
	UfoItem* ufo  = itemMgr->getUfo();
	if (ufo) {
		ufo->finishAccess();
	}

	GameCoreSection::finishPause();
	Jac_FinishPartsFindDemo();
	PRINT("UFO STATE CLEANUP!\n");
}

/*
 * --INFO--
 * Address:	80104FB4
 * Size:	000030
 */
void NaviUfoState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	PRINT("PROC ANIM MSG !!!\n");
	if (msg->mKeyEvent->mEventType == KEY_Finished && mState == 1) {
		PRINT("ANIM DONE ! JUMP!\n");
		mState         = 2;
		mRecoveryTimer = 10;
	}
}

/*
 * --INFO--
 * Address:	80104FE4
 * Size:	0000AC
 */
NaviContainerState::NaviContainerState()
    : NaviState(NAVISTATE_Container)
{
}

/*
 * --INFO--
 * Address:	80105090
 * Size:	000204
 */
void NaviContainerState::init(Navi* navi)
{
	navi->_70C = true;
	int store  = navi->mGoalItem->getTotalStorePikis() - navi->mGoalItem->mPikisToExit;
	rumbleMgr->stop();
	int pikisInParty = 0;

	Iterator iter(navi->mPlateMgr);
	CI_LOOP(iter)
	{
		Piki* piki = (Piki*)*iter;
		if (piki->mColor == navi->mGoalItem->mOnionColour) {
			pikisInParty++;
		}
	}

	int exitPikis = 0;
	for (int i = 0; i < 3; i++) {
		GoalItem* goal = itemMgr->getContainer(i);
		if (goal) {
			exitPikis += goal->mPikisToExit;
		}
	}

	GameStat::update();
	PRINT("START CONAINER WINDOW ***\n");
	gameflow.mGameInterface->message(3, 0);
	containerWindow->start((zen::DrawContainer::containerType)navi->mGoalItem->mOnionColour, store, 10000, pikisInParty,
	                       AIConstant::_instance->mConstants.mMaxPikisOnField(), exitPikis + GameStat::mapPikis,
	                       AIConstant::_instance->mConstants.mMaxPikisOnField());
	PRINT("FINISH START CONAINER WINDOW ***\n");
	gameflow._33C = TRUE;
	_18           = 0;
	_1C           = 0;
}

/*
 * --INFO--
 * Address:	80105294
 * Size:	000030
 */
void NaviContainerState::informWin(int p1)
{
	PRINT("GOT CONTAINER %d MESSAGE ****\n", p1);

	if (p1 > 0) {
		_18 = 1;
		_1C = p1;
		return;
	}

	if (p1 < 0) {
		_18 = 2;
		_1C = -p1;
	}
}

/*
 * --INFO--
 * Address:	801052C4
 * Size:	000018
 */
void NaviContainerState::onCloseWindow()
{
	PRINT("GOT CLOSE WIN MESSAGE ******\n");

	if (_18 == 0) {
		_18 = 3;
	}
}

/*
 * --INFO--
 * Address:	801052DC
 * Size:	0000E8
 */
void NaviContainerState::exec(Navi* navi)
{
	int a;
	if (containerWindow->update(a)) {
		gameflow.mGameInterface->message(4, 0);
		PRINT("result is %d\n", a);
		if (a > 0) {
			enterPikis(navi, a);
		} else if (a < 0) {
			exitPikis(navi, -a);
		}
		transit(navi, NAVISTATE_Walk);
	}

	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	801053C4
 * Size:	0001E8
 */
void NaviContainerState::enterPikis(Navi* navi, int max)
{
	PRINT("goal color = %d\n", navi->mGoalItem->mOnionColour);
	// This has a capacity of 200 in the vanilla game for some reason.
	Piki* pikiList[MAX_PIKI_ON_FIELD == 100 ? 200 : MAX_PIKI_ON_FIELD];
	int numPikis = 0;
	Iterator it(navi->mPlateMgr);

	CI_LOOP(it)
	{
		Piki* piki = static_cast<Piki*>(*it);
		int state  = piki->getState();
		if (state == PIKISTATE_FallMeck || state == PIKISTATE_Bury || state == PIKISTATE_Drown || state == PIKISTATE_Dead
		    || state == PIKISTATE_Dying || state == PIKISTATE_Absorb) {
			continue;
		}
		if (piki->mColor == navi->mGoalItem->mOnionColour) {
			pikiList[numPikis++] = piki;
			if (numPikis == max) {
				break;
			}
		}
	}

	PRINT("#### numPikis = %d : max = %d \n", numPikis, max);
	for (int i = 0; i < numPikis; i++) {
		PRINT("enter : %d\n", i);
		int state = pikiList[i]->getState();
		if (state == PIKISTATE_LookAt || state == PIKISTATE_Nukare) {
			pikiList[i]->mFSM->transit(pikiList[i], 0);
		}
		pikiList[i]->mFSM->transit(pikiList[i], 0);
		pikiList[i]->changeMode(11, nullptr);
	}
}

/*
 * --INFO--
 * Address:	801055AC
 * Size:	000028
 */
void NaviContainerState::exitPikis(Navi* navi, int p2)
{
	navi->mGoalItem->exitPikis(p2);
}

/*
 * --INFO--
 * Address:	801055D4
 * Size:	000038
 */
void NaviContainerState::cleanup(Navi* navi)
{
	PRINT("cleanup\n");
	gameflow._33C = FALSE;
	navi->mGoalItem->setSpotActive(true);
}

/*
 * --INFO--
 * Address:	8010560C
 * Size:	000044
 */
NaviPickState::NaviPickState()
    : NaviState(NAVISTATE_Pick)
{
}

/*
 * --INFO--
 * Address:	80105650
 * Size:	000004
 */
void NaviPickState::procAnimMsg(Navi* navi, MsgAnim*)
{
}

/*
 * --INFO--
 * Address:	80105654
 * Size:	000070
 */
void NaviPickState::init(Navi* navi)
{
	navi->startMotion(PaniMotionInfo(PIKIANIM_Pick), PaniMotionInfo(PIKIANIM_Run));
	navi->mNaviAnimMgr.getUpperAnimator().mAnimationCounter = 11.0f;
	navi->mNaviAnimMgr.getLowerAnimator().mAnimationCounter = 11.0f;
	navi->enableMotionBlend();
}

/*
 * --INFO--
 * Address:	801056C4
 * Size:	00004C
 */
void NaviPickState::exec(Navi* navi)
{
	if (!navi->isStickTo() || navi->mKontroller->keyClick(KBBTN_B)) {
		transit(navi, NAVISTATE_Walk);
	}
}

/*
 * --INFO--
 * Address:	80105710
 * Size:	000024
 */
void NaviPickState::cleanup(Navi* navi)
{
	navi->endStickObject();
}

/*
 * --INFO--
 * Address:	80105734
 * Size:	000044
 */
NaviRopeState::NaviRopeState()
    : NaviState(NAVISTATE_Rope)
{
}

/*
 * --INFO--
 * Address:	80105778
 * Size:	000074
 */
void NaviRopeState::init(Navi* navi)
{
	navi->startMotion(PaniMotionInfo(PIKIANIM_HNoboru, navi), PaniMotionInfo(PIKIANIM_HNoboru));
}

/*
 * --INFO--
 * Address:	801057EC
 * Size:	00025C
 */
void NaviRopeState::exec(Navi* navi)
{
	if (!navi->mRope) {
		transit(navi, NAVISTATE_RopeExit);
		return;
	}
	Vector3f dir(navi->mKontroller->getMainStickX(), 0.0f, -navi->mKontroller->getMainStickY());
	Vector3f pos = navi->mRope->mRopeDirection;
	Vector3f dir2(sinf(navi->mFaceDirection), 0.0f, cosf(navi->mFaceDirection));

	Vector3f temp = dir2;
	temp.CP(pos);
	temp.normalise();
	navi->mFaceDirection = roundAng((gsys->getFrameTime() * (dir.x * PI)) / 3.0f + navi->mFaceDirection);

	f32 z = absF(dir.z);
	if (z > 0.1f) {
		navi->mMotionSpeed = z * 45.0f;
	} else {
		navi->mMotionSpeed = 0.0f;
	}
	navi->mVelocity = pos * (dir.z * -40.0f) + temp * (dir.x * 2.0f);

	if (navi->mKontroller->keyClick(KBBTN_B) || navi->mKontroller->keyClick(KBBTN_Z)) {
		transit(navi, NAVISTATE_RopeExit);
	}
}

/*
 * --INFO--
 * Address:	80105A48
 * Size:	000004
 */
void NaviRopeState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80105A4C
 * Size:	000044
 */
NaviRopeExitState::NaviRopeExitState()
    : NaviState(NAVISTATE_RopeExit)
{
}

/*
 * --INFO--
 * Address:	80105A90
 * Size:	0000DC
 */
void NaviRopeExitState::init(Navi* navi)
{
	STACK_PAD_VAR(1);
	navi->endRope();
	navi->startMotion(PaniMotionInfo(PIKIANIM_Jump, navi), PaniMotionInfo(PIKIANIM_Jump));
	f32 angle = navi->mFaceDirection;
	navi->mVelocity.set(50.0f * sinf(angle), 200.0f, 50.0f * cosf(angle));
	navi->mTargetVelocity = navi->mVelocity;
}

/*
 * --INFO--
 * Address:	80105B6C
 * Size:	000004
 */
void NaviRopeExitState::exec(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80105B70
 * Size:	000004
 */
void NaviRopeExitState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80105B74
 * Size:	000030
 */
void NaviRopeExitState::procBounceMsg(Navi* navi, MsgBounce*)
{
	PRINT("got bounce msg!\n");
	transit(navi, NAVISTATE_Walk);
}

/*
 * --INFO--
 * Address:	80105BA4
 * Size:	000044
 */
NaviFunbariState::NaviFunbariState()
    : NaviState(NAVISTATE_Funbari)
{
}

/*
 * --INFO--
 * Address:	80105BE8
 * Size:	000094
 */
void NaviFunbariState::init(Navi* navi)
{
	navi->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, navi), PaniMotionInfo(PIKIANIM_Kuttuku));
	navi->mNaviAnimMgr.finishMotion(navi);
	navi->_ACC = true;
	PRINT("funbari start\n");
}

/*
 * --INFO--
 * Address:	80105C7C
 * Size:	00001C
 */
void NaviFunbariState::exec(Navi* navi)
{
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80105C98
 * Size:	000044
 */
void NaviFunbariState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		transit(navi, NAVISTATE_Walk);
		break;
	}
}

/*
 * --INFO--
 * Address:	80105CDC
 * Size:	000004
 */
void NaviFunbariState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80105CE0
 * Size:	000044
 */
NaviIdleState::NaviIdleState()
    : NaviState(NAVISTATE_Idle)
{
}

/*
 * --INFO--
 * Address:	80105D24
 * Size:	0000CC
 */
void NaviIdleState::init(Navi* navi)
{
	Choice motionIDs[4] = {
		{ PIKIANIM_Rinbow, 0.1f },
		{ PIKIANIM_Sagasu2, 0.1f },
		{ PIKIANIM_Wait, 0.5f },
		{ PIKIANIM_Furimuku, 0.3f },
	};

	int randID = selectRandomly(motionIDs, 4);

	navi->startMotion(PaniMotionInfo(randID, navi), PaniMotionInfo(randID));
	mStopBeingIdle = false;
}

/*
 * --INFO--
 * Address:	80105DF0
 * Size:	00013C
 */
void NaviIdleState::exec(Navi* navi)
{
	navi->makeVelocity(false);
	if ((!mStopBeingIdle && navi->mNeutralTime < 1.0f) || navi->mKontroller->keyDown(KBBTN_A) || navi->mKontroller->keyDown(KBBTN_B)
	    || navi->mKontroller->keyDown(KBBTN_X) || navi->mKontroller->keyDown(KBBTN_L) || navi->mKontroller->keyDown(KBBTN_R)
	    || navi->mKontroller->keyDown(KBBTN_MSTICK_LEFT) || navi->mKontroller->keyDown(KBBTN_MSTICK_RIGHT)
	    || navi->mKontroller->keyDown(KBBTN_MSTICK_UP) || navi->mKontroller->keyDown(KBBTN_MSTICK_DOWN)
	    || navi->mKontroller->keyDown(KBBTN_CSTICK_LEFT) || navi->mKontroller->keyDown(KBBTN_CSTICK_RIGHT)
	    || navi->mKontroller->keyDown(KBBTN_CSTICK_UP) || navi->mKontroller->keyDown(KBBTN_CSTICK_DOWN)) {
		navi->mNaviAnimMgr.finishMotion(navi);
		navi->enableMotionBlend();
		mStopBeingIdle = true;
		return;
	}

	if (!playerState->isTutorial() && navi->mNeutralTime > 140.0f) {
		PRINT("navi : neutral time = %.1fseconds\n", navi->mNeutralTime);
		navi->mNeutralTime = 1.0f;
		transit(navi, NAVISTATE_Pellet);
	}
}

/*
 * --INFO--
 * Address:	80105F2C
 * Size:	000064
 */
void NaviIdleState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mStopBeingIdle) {
			transit(navi, NAVISTATE_Walk);
		} else {
			init(navi);
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	80105F90
 * Size:	00000C
 */
void NaviIdleState::cleanup(Navi* navi)
{
	navi->mNeutralTime = 0.0f;
}

/*
 * --INFO--
 * Address:	80105F9C
 * Size:	000044
 */
NaviFlickState::NaviFlickState()
    : NaviState(NAVISTATE_Flick)
{
}

/*
 * --INFO--
 * Address:	80105FE0
 * Size:	000124
 */
void NaviFlickState::init(Navi* navi)
{
	mFlickState       = 0;
	mDirection        = navi->mFaceDirection;
	mRandVariation    = 0.1f * (PI * gsys->getRand(1.0f));
	navi->mVelocity.y = 0.0f;
	mIntensity        = navi->_704 + 0.1f * navi->_704 * gsys->getRand(1.0f);
	PRINT("** flick\n");
	navi->startMotion(PaniMotionInfo(PIKIANIM_JHit, navi), PaniMotionInfo(PIKIANIM_JHit));
}

/*
 * --INFO--
 * Address:	80106104
 * Size:	000178
 */
void NaviFlickState::exec(Navi* navi)
{
	if (mFlickState == 0) {
		f32 speed            = mIntensity;
		navi->mVelocity.x    = -speed * sinf(mDirection);
		navi->mVelocity.z    = -speed * cosf(mDirection);
		navi->mFaceDirection = roundAng(navi->mFaceDirection + mRandVariation);
		return;
	}

	if (mFlickState == 2) {
		mGetupAnimationTimer -= gsys->getFrameTime();
		if (mGetupAnimationTimer < 0.0f) {
			navi->startMotion(PaniMotionInfo(PIKIANIM_GetUp, navi), PaniMotionInfo(PIKIANIM_GetUp));
			mFlickState = 3;
		}
		navi->mVelocity.x = navi->mVelocity.x * 0.9f;
		navi->mVelocity.z = navi->mVelocity.z * 0.9f;
		navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	navi->mVelocity.x = navi->mVelocity.x * 0.9f;
	navi->mVelocity.z = navi->mVelocity.z * 0.9f;
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	8010627C
 * Size:	000150
 */
void NaviFlickState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mFlickState == 0) {
			navi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_JKoke, navi), PaniMotionInfo(PIKIANIM_JKoke));
			mFlickState = 1;
			break;
		}
		if (mFlickState == 1) {
			mFlickState          = 2;
			mGetupAnimationTimer = (0.1f * gsys->getRand(1.0f));
			break;
		}
		if (navi->mHealth <= 1.0f) {
			transit(navi, NAVISTATE_Dead);
			break;
		}

		transit(navi, NAVISTATE_Walk);
		break;
	}
}

/*
 * --INFO--
 * Address:	801063CC
 * Size:	000034
 */
void NaviFlickState::cleanup(Navi* navi)
{
	if (navi->isAlive()) {
		(navi->mHealth);
	}
}

/*
 * --INFO--
 * Address:	80106400
 * Size:	000054
 */
NaviGeyzerState::NaviGeyzerState()
    : NaviState(NAVISTATE_Geyzer)
{
}

/*
 * --INFO--
 * Address:	80106454
 * Size:	000140
 */
void NaviGeyzerState::init(Navi* navi)
{
	mGeyserState     = 1; // why
	mPlayerDirection = navi->mFaceDirection;
	_1C              = 0.1f * (PI * gsys->getRand(1.0f));
	navi->startMotion(PaniMotionInfo(PIKIANIM_JHit, navi), PaniMotionInfo(PIKIANIM_JHit));
	_30 = false;
	navi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_OCarry, navi), PaniMotionInfo(PIKIANIM_OCarry));

	mGeyserState = 2; // does this
	_2C          = 69.0f + navi->mPosition.y;

	mGeyserState = 0; // get set like this
}

/*
 * --INFO--
 * Address:	80106594
 * Size:	000214
 */
void NaviGeyzerState::exec(Navi* navi)
{
	if (mGeyserState == 0) {
		Vector3f vel(0.0f, 200.0f, 0.0f);
		navi->mVelocity       = vel;
		navi->mTargetVelocity = vel;
		if (navi->mPosition.y >= _2C) {
			PRINT("**UP %.1f/%.1f!\n", navi->mPosition.y, _2C);
			mGeyserState = 2;
		} else {
			PRINT("** TO FLICK ** %.1f/%.1f!\n", navi->mPosition.y, _2C);
			return;
		}
	}

	if (!_30) {
		_30                   = true;
		Vector3f velocity     = getThrowVelocity(navi->mPosition, 100.0f, _20, Vector3f(0.0f, 0.0f, 0.0f));
		navi->mVelocity       = velocity;
		navi->mTargetVelocity = velocity;
		PRINT("GEYZER VEL SET!\n");
	}

	if (mGeyserState == 1) {
		navi->mFaceDirection = roundAng(navi->mFaceDirection + _1C);
		return;
	}

	if (mGeyserState == 3) {
		_14 -= gsys->getFrameTime();
		if (_14 < 0.0f) {
			navi->startMotion(PaniMotionInfo(PIKIANIM_GetUp, navi), PaniMotionInfo(PIKIANIM_GetUp));
			mGeyserState = 4;
		}
		navi->mVelocity.x = navi->mVelocity.x * 0.9f;
		navi->mVelocity.z = navi->mVelocity.z * 0.9f;
		navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}
}

/*
 * --INFO--
 * Address:	801067A8
 * Size:	000120
 */
void NaviGeyzerState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mGeyserState == 1) {
			navi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_JKoke, navi), PaniMotionInfo(PIKIANIM_JKoke));
			mGeyserState = 2;
			break;
		}

		if (mGeyserState == 2) {
			navi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_JKoke, navi), PaniMotionInfo(PIKIANIM_JKoke));
			break;
		}

		if (mGeyserState == 4) {
			transit(navi, NAVISTATE_Walk);
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	801068C8
 * Size:	000094
 */
void NaviGeyzerState::procBounceMsg(Navi* navi, MsgBounce* msg)
{
	if (mGeyserState != 0) {
		mGeyserState = 3;
		_14          = 0.3f + (0.2f * gsys->getRand(1.0f));
		rumbleMgr->start(RUMBLE_Unk10, 0, nullptr);
	}
}

/*
 * --INFO--
 * Address:	8010695C
 * Size:	000034
 */
void NaviGeyzerState::cleanup(Navi* navi)
{
	if (navi->isAlive()) {
		(navi->mPosition.y);
	}
}

/*
 * --INFO--
 * Address:	80106990
 * Size:	000044
 */
NaviGatherState::NaviGatherState()
    : NaviState(NAVISTATE_Gather)
{
}

/*
 * --INFO--
 * Address:	801069D4
 * Size:	00002C
 */
void NaviGatherState::resume(Navi* navi)
{
	cleanup(navi);
}

/*
 * --INFO--
 * Address:	80106A00
 * Size:	000030
 */
void NaviGatherState::restart(Navi* navi)
{
	transit(navi, NAVISTATE_Walk);
}

/*
 * --INFO--
 * Address:	80106A30
 * Size:	000138
 */
void NaviGatherState::init(Navi* navi)
{
	navi->mMotionSpeed = 30.0f;
	navi->startMotion(PaniMotionInfo(PIKIANIM_Fue, navi), PaniMotionInfo(PIKIANIM_Fue));
	navi->enableMotionBlend();
	navi->_AB8 = 0.0f;
	navi->_AC4 = 0.0f;
	navi->_ABC = 1;
	_10        = 0;
	SeSystem::playPlayerSe(SE_GATHER);

	int kEffID = (navi->mNaviID == 0) ? KandoEffect::NaviWhistle0 : KandoEffect::NaviWhistle1;
	EffectParm parm(navi->mPosition);
	UtEffectMgr::cast(kEffID, parm);
	UtEffectMgr::cast(KandoEffect::NaviFue0, parm);
	_18 = false;
	rumbleMgr->start(RUMBLE_Unk3, 0, nullptr);
}

/*
 * --INFO--
 * Address:	80106B68
 * Size:	0005EC
 */
void NaviGatherState::exec(Navi* navi)
{
	if (navi->demoCheck()) {
		return;
	}

	bool check = false;
	Iterator it(itemMgr);
	CI_LOOP(it)
	{
		Creature* item = *it;
		if (item->mObjType == OBJTYPE_Goal) {
			GoalItem* onyon = (GoalItem*)item;
			CollPart* coll  = item->mCollInfo->getSphere('cont');
			if (navi->roughCulling(item, (navi->getSize() + coll->mRadius) * 1.5f)) {
				continue;
			}
			STACK_PAD_TERNARY(coll, 6);
			Vector3f diff = coll->mCentre - navi->getCentre();
			f32 test      = diff.length();
			if (test <= navi->getSize() + coll->mRadius && navi->mKontroller->keyClick(KeyConfig::_instance->mSetCursorKey.mBind)) {
				navi->mGoalItem = onyon;
				transit(navi, NAVISTATE_Container);
				return;
			}
		}
	}

	STACK_PAD_INLINE(3);
	bool down = navi->mKontroller->keyDown(KeyConfig::_instance->mSetCursorKey.mBind);
	bool up   = navi->mKontroller->keyUp(KeyConfig::_instance->mSetCursorKey.mBind);
	navi->makeVelocity(false);

	if (_10 == 0) {
		return;
	}

	if (navi->mKontroller->keyClick(KeyConfig::_instance->mSetCursorKey.mBind)) {
		navi->_AB8 = 0.0f;
		navi->_ABC = 0;
		transit(navi, NAVISTATE_Gather);
		return;
	}

	if (_10 == 2) {
		transit(navi, NAVISTATE_Walk);
		return;
	}

	if (navi->_ABC == 1 && down) {
		navi->_AB8 += gsys->getFrameTime();
		if (navi->_AB8 > C_NAVI_PROP(navi)._AC()) {
			navi->_AB8 = C_NAVI_PROP(navi)._AC();

			if (!gameflow._33C) {
				navi->callPikis(C_NAVI_PROP(navi)._8C());
			} else {
				navi->callDebugs(C_NAVI_PROP(navi)._8C());
			}
			navi->_AC0 = navi->_AB8 / C_NAVI_PROP(navi)._AC();
			navi->_AB8 = 0.0f;
			navi->_ABC = 2;
		}
		return;
	}

	if (navi->_ABC == 1 && up) {
		f32 scale  = navi->_AB8 / C_NAVI_PROP(navi)._AC();
		navi->_AC0 = scale;
		scale *= (C_NAVI_PROP(navi)._8C() - C_NAVI_PROP(navi)._9C());
		scale += C_NAVI_PROP(navi)._9C();

		check      = true;
		navi->_AB8 = 0.0f;
		navi->_ABC = 2;
		_14        = scale;
		if (!gameflow._33C) {
			navi->callPikis(scale);
		} else {
			navi->callDebugs(scale);
		}
		return;
	}

	if (navi->_ABC != 2) {
		return;
	}
	if (!gameflow._33C) {
		navi->callPikis(_14);
	} else {
		navi->callDebugs(_14);
	}

	if (navi->mKontroller->keyClick(KeyConfig::_instance->mSetCursorKey.mBind)) {
		navi->_AB8 = 0.0f;
		navi->_ABC = 0;
		transit(navi, NAVISTATE_Gather);
		return;
	}

	navi->_AB8 += gsys->getFrameTime();

	if (!down) {
		check = true;
	}
	if (!_18 && navi->_AB8 > C_NAVI_PROP(navi)._BC() - 0.5f) {
		seSystem->stopPlayerSe(SE_GATHER);
		_18 = true;
		utEffectMgr->kill(navi->mNaviID == 0 ? KandoEffect::NaviWhistle0 : KandoEffect::NaviWhistle1);
		utEffectMgr->kill(KandoEffect::NaviFue0);
	}

	if (check || navi->_AB8 > C_NAVI_PROP(navi)._BC()) {
		navi->_AB8 = 0.0f;
		navi->_ABC = 0;
		navi->mNaviAnimMgr.getUpperAnimator().finishMotion(PaniMotionInfo(-1, navi));
		transit(navi, NAVISTATE_Walk);
	}

	STACK_PAD_TERNARY(navi, 3);
	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	80107154
 * Size:	000068
 */
void NaviGatherState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		break;
	case KEY_LoopStart:
		_10 = 1;
		break;
	case KEY_Finished:
		_10 = 2;
		transit(navi, NAVISTATE_Walk);
		break;
	}
}

/*
 * --INFO--
 * Address:	801071BC
 * Size:	00006C
 */
void NaviGatherState::cleanup(Navi* navi)
{
	rumbleMgr->stop(3, 0);
	int id = (navi->mNaviID == 0) ? 1 : 2;
	seSystem->stopPlayerSe(SE_GATHER);
	utEffectMgr->kill(id);
	utEffectMgr->kill(7);
}

/*
 * --INFO--
 * Address:	80107228
 * Size:	000044
 */
NaviReleaseState::NaviReleaseState()
    : NaviState(NAVISTATE_Release)
{
}

/*
 * --INFO--
 * Address:	8010726C
 * Size:	0000A0
 */
void NaviReleaseState::init(Navi* navi)
{
	navi->mMotionSpeed = 30.0f;
	navi->startMotion(PaniMotionInfo(PIKIANIM_Fue, navi), PaniMotionInfo(PIKIANIM_Fue));
	navi->enableMotionBlend();
	seSystem->playPlayerSe(SE_BREAKUP);
	_10 = false;
}

/*
 * --INFO--
 * Address:	8010730C
 * Size:	000090
 */
void NaviReleaseState::exec(Navi* navi)
{
	if (navi->demoCheck()) {
		return;
	}

	navi->makeVelocity(false);

	if (_10 == true && navi->mKontroller->keyClick(KeyConfig::_instance->mSetCursorKey.mBind)) {
		transit(navi, NAVISTATE_Gather);
	}
}

/*
 * --INFO--
 * Address:	8010739C
 * Size:	000004
 */
void NaviReleaseState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	801073A0
 * Size:	000090
 */
void NaviReleaseState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopStart:
		_10 = true;
		navi->mNaviAnimMgr.finishMotion(navi);
		navi->releasePikis();
		break;
	case KEY_LoopEnd:
		break;
	case KEY_Finished:
		transit(navi, NAVISTATE_Walk);
		break;
	}
}

/*
 * --INFO--
 * Address:	80107430
 * Size:	000044
 */
NaviThrowWaitState::NaviThrowWaitState()
    : NaviState(NAVISTATE_ThrowWait)
{
}

/*
 * --INFO--
 * Address:	80107474
 * Size:	00002C
 */
void NaviThrowWaitState::resume(Navi* navi)
{
	cleanup(navi);
}

/*
 * --INFO--
 * Address:	801074A0
 * Size:	000030
 */
void NaviThrowWaitState::restart(Navi* navi)
{
	transit(navi, NAVISTATE_Walk);
}

/*
 * --INFO--
 * Address:	801074D0
 * Size:	0003CC
 */
void NaviThrowWaitState::init(Navi* navi)
{
	navi->_800 = 0.0f;
	_10        = nullptr;
	_14        = nullptr;
	Iterator it(navi->mPlateMgr);
	Piki* throwPiki = nullptr;
	f32 maxDist     = 80.0f;
	CI_LOOP(it)
	{
		Piki* piki = (Piki*)*it;
		if (!roughCull(piki, navi, maxDist)) {
			Vector3f diff = piki->mPosition - navi->mPosition;
			Vector3f dir(sinf(navi->mFaceDirection), 0.0f, cosf(navi->mFaceDirection));
			f32 length = diff.length();
			if (diff.DP(dir) > -0.1f) {
				length += 10.0f;
			}
			if (length < maxDist && piki->getState() == PIKISTATE_Normal && piki->isThrowable()) {
				throwPiki = piki;
				maxDist   = length;
			}
		}
	}

	if (maxDist <= C_NAVI_PROP(navi)._1BC()) {
		_10 = throwPiki;
	} else {
		_14 = throwPiki;
	}

	if (_10) {
		navi->mMotionSpeed = 30.0f;
		navi->startMotion(PaniMotionInfo(PIKIANIM_ThrowWait, navi), PaniMotionInfo(PIKIANIM_ThrowWait));
		navi->enableMotionBlend();
	} else {
		if (_14) {
			_14->mFSM->transit(_14, PIKISTATE_GoHang);
		}
	}
	_1C = false;
	_18 = 0;

	navi->_804 = C_NAVI_PROP(navi)._16C() + (_18 / 3.0f) * (C_NAVI_PROP(navi)._15C() - C_NAVI_PROP(navi)._16C());
	navi->_808 = C_NAVI_PROP(navi)._18C() + (_18 / 3.0f) * (C_NAVI_PROP(navi)._17C() - C_NAVI_PROP(navi)._18C());

	_24 = 3.0f;
	_28 = 0.1f;
}

/*
 * --INFO--
 * Address:	8010789C
 * Size:	00008C
 */
void NaviThrowWaitState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		_1C = true;
		_10->mFSM->transit(_10, PIKISTATE_Hanged);
		break;
	case KEY_LoopEnd:
		if (_18 < 3) {
			_18++;
		}
		break;
	}

	_20 = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void NaviThrowWaitState::lockHangPiki(Navi* navi)
{
	if (_10 && _1C) {
		CollPart* coll = navi->mCollInfo->getSphere('rhnd');
		_10->mPosition = coll->mCentre + Vector3f(0.0f, -10.0f, 0.0f);
	}
}

/*
 * --INFO--
 * Address:	80107928
 * Size:	00059C
 */
void NaviThrowWaitState::exec(Navi* navi)
{
	if (navi->demoCheck()) {
		return;
	}
	navi->makeVelocity(false);

	if (!_10) {
		if (_14) {

			_24 -= gsys->getFrameTime();
			if (_24 < 0.0f) {
				transit(navi, NAVISTATE_Walk);
				return;
			}
			if (navi->mKontroller->keyClick(KeyConfig::_instance->mSetCursorKey.mBind)) {
				transit(navi, NAVISTATE_Walk);
				return;
			}
			if (!_14->isAlive()) {
				transit(navi, NAVISTATE_Walk);
			}
			Vector3f diff = _14->mPosition - navi->mPosition;
			f32 d         = diff.length();
			if (d <= C_NAVI_PROP(navi)._1BC()) {
				navi->mMotionSpeed = 30.0f;
				navi->startMotion(PaniMotionInfo(PIKIANIM_ThrowWait, navi), PaniMotionInfo(PIKIANIM_ThrowWait));
				navi->enableMotionBlend();
				_10 = _14;
				_14 = nullptr;
			} else {
				return;
			}
		} else {
			transit(navi, NAVISTATE_Attack);
			return;
		}
	}
	navi->mNextThrowPiki = _10;

	navi->_804 = C_NAVI_PROP(navi)._16C() + (_18 / 3.0f) * (C_NAVI_PROP(navi)._15C() - C_NAVI_PROP(navi)._16C());
	navi->_808 = C_NAVI_PROP(navi)._18C() + (_18 / 3.0f) * (C_NAVI_PROP(navi)._17C() - C_NAVI_PROP(navi)._18C());
	lockHangPiki(navi);

	if (_10) {
		int state = _10->getState();
		if (state != PIKISTATE_Hanged && state != PIKISTATE_GoHang) {
			transit(navi, NAVISTATE_Walk);
			return;
		}
	}

	if (navi->mKontroller->keyUp(KeyConfig::_instance->mThrowKey.mBind)) {
		sortPikis(navi);
		navi->_800 = _18 / 3.0f * C_NAVI_PROP(navi)._14C();
		transit(navi, NAVISTATE_Throw);
		MsgTarget target(_10);
		navi->sendMsg(&target);
		return;
	}

	navi->_800 += gsys->getFrameTime();
	if (navi->_800 > C_NAVI_PROP(navi)._14C()) {
		navi->_800 = C_NAVI_PROP(navi)._14C();
	}
	if (_28 > 0.0f) {
		_28 -= gsys->getFrameTime();
		if (_28 <= 0.0f) {
			sortPikis(navi);
		}
	} else {
		if (navi->mPlateMgr->mTotalSlotCount > 0) {
			Vector3f pos = navi->mPlateMgr->mSlotList[0].mOffsetFromCenter;
			pos.sub(navi->mPosition);
			if (pos.length() > 30.0f) {
				navi->mPlateMgr->setPos(navi->mPosition, navi->mFaceDirection + PI, navi->mVelocity);
				sortPikis(navi);
			}
		}
	}

	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	80107EC4
 * Size:	00016C
 */
void NaviThrowWaitState::sortPikis(Navi* navi)
{
	navi->mPlateMgr->sortByColor(_10);
	navi->mPlateMgr->setPos(navi->mPosition, navi->mFaceDirection + PI, navi->mVelocity);

	Iterator it(navi->mPlateMgr);
	CI_LOOP(it)
	{
		Piki* piki = (Piki*)*it;
		if (piki->mMode == 1) {
			ActCrowd* act = (ActCrowd*)piki->mActiveAction->getCurrAction();
			if (act) {
				act->startSort();
			}
		}
	}

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	80108030
 * Size:	000004
 */
void NaviThrowWaitState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80108034
 * Size:	000044
 */
NaviThrowState::NaviThrowState()
    : NaviState(NAVISTATE_Throw)
{
}

/*
 * --INFO--
 * Address:	80108078
 * Size:	0000A4
 */
void NaviThrowState::init(Navi* navi)
{
	navi->mMotionSpeed = 30.0f;
	navi->startMotion(PaniMotionInfo(PIKIANIM_Throw, navi), PaniMotionInfo(PIKIANIM_Throw));
	navi->enableMotionBlend();
	_10 = false;
	seSystem->playPlayerSe(SE_THROW);
	_11 = false;
}

/*
 * --INFO--
 * Address:	8010811C
 * Size:	00000C
 */
void NaviThrowState::procTargetMsg(Navi* navi, MsgTarget* msg)
{
	_14 = (Piki*)msg->mTarget;
}

/*
 * --INFO--
 * Address:	80108128
 * Size:	000148
 */
void NaviThrowState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		_14->mFSM->transit(_14, 14);
		rumbleMgr->start(RUMBLE_Unk2, 0, nullptr);

		// none of this is used for anything
		f32 test
		    = C_NAVI_PROP(navi)._16C() + (C_NAVI_PROP(navi)._15C() - C_NAVI_PROP(navi)._16C()) * (navi->_800 / C_NAVI_PROP(navi)._14C());
		Vector3f unused(sinf(navi->mFaceDirection) * test, 0.0f, cosf(navi->mFaceDirection) * test);
		Vector3f speed = unused + navi->mPosition;

		speed = navi->mCursorWorldPos;
		navi->throwPiki(_14, speed);
		_10 = true;
		break;
	case KEY_Finished:
		transit(navi, NAVISTATE_Walk);
		break;
	}
}

/*
 * --INFO--
 * Address:	80108270
 * Size:	0000F8
 */
void NaviThrowState::exec(Navi* navi)
{
	navi->makeVelocity(false);

	if (navi->mKontroller->keyDown(KeyConfig::_instance->mSetCursorKey.mBind)) {
		_11 = true;
	}

	navi->findNextThrowPiki();

	if (_10 && navi->mKontroller->keyClick(KeyConfig::_instance->mThrowKey.mBind)) {
		if (navi->procActionButton()) {
			return;
		}
		transit(navi, NAVISTATE_ThrowWait);
		return;
	}

	if (_10 && navi->mKontroller->keyClick(KeyConfig::_instance->mSetCursorKey.mBind)) {
		transit(navi, NAVISTATE_Gather);
	}
}

/*
 * --INFO--
 * Address:	80108368
 * Size:	000004
 */
void NaviThrowState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	8010836C
 * Size:	000044
 */
NaviPushState::NaviPushState()
    : NaviState(NAVISTATE_Push)
{
}

/*
 * --INFO--
 * Address:	801083B0
 * Size:	000090
 */
void NaviPushState::init(Navi* navi)
{
	navi->startMotion(PaniMotionInfo(PIKIANIM_Push, navi), PaniMotionInfo(PIKIANIM_Push));
	navi->mMotionSpeed = 30.0f;
	_10                = false;
	PRINT("push wall start ***\n");
}

/*
 * --INFO--
 * Address:	80108440
 * Size:	000248
 */
void NaviPushState::exec(Navi* navi)
{
	navi->makeVelocity(false);
	if (_10) {
		return;
	}

	Vector3f normal;
	normal = navi->mWallPlane->mNormal;
	normal = -1.0f * normal;
	f32 dp = navi->mTargetVelocity.DP(normal);
	if (dp < 0.0f) {
		dp = 0.0f;
	}
	navi->mTargetVelocity = dp * normal;

	Vector3f vec = navi->_74C;
	Vector3f dir(sinf(navi->mFaceDirection), 0.0f, cosf(navi->mFaceDirection));
	f32 len = vec.normalise();
	if (dir.DP(vec) <= 0.0f || len < 0.1f) {
		PRINT("navi finish pushing : ang %.1f len %.1f\n", dir.DP(vec), len);
		navi->mNaviAnimMgr.finishMotion(navi);
		_10 = true;
		return;
	}

	if (navi->mWallCollObj && AIConstant::_instance->mConstants._64()) {
		Vector3f dir(sinf(navi->mFaceDirection), 0.0f, cosf(navi->mFaceDirection));
		navi->mWallCollObj->applyVelocity(*navi->mWallPlane, navi->mPosition, dir);
	}
}

/*
 * --INFO--
 * Address:	80108688
 * Size:	000014
 */
void NaviPushState::cleanup(Navi* navi)
{
	PRINT("navi exits pushstate (finishing=%s)\n", _10 ? "true" : "false");
	PRINT("navi (%s/%s)\n", navi->mNaviAnimMgr.getUpperAnimator().getCurrentMotionName(),
	      navi->mNaviAnimMgr.getLowerAnimator().getCurrentMotionName());
}

/*
 * --INFO--
 * Address:	8010869C
 * Size:	0000F4
 */
void NaviPushState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		if (navi->mWallCollObj && !AIConstant::_instance->mConstants._64()) {
			Vector3f dir(sinf(navi->mFaceDirection), 0.0f, cosf(navi->mFaceDirection));
			dir = dir * 4.0f;
			navi->mWallCollObj->applyVelocity(*navi->mWallPlane, navi->mPosition, dir);
		}
		break;
	case KEY_Finished:
		PRINT("got anim finished\n");
		transit(navi, NAVISTATE_Walk);
		break;
	}
}

/*
 * --INFO--
 * Address:	80108790
 * Size:	000004
 */
void NaviPushState::procOffWallMsg(Navi* navi, MsgOffWall*)
{
}

/*
 * --INFO--
 * Address:	80108794
 * Size:	000044
 */
NaviPushPikiState::NaviPushPikiState()
    : NaviState(NAVISTATE_PushPiki)
{
}

/*
 * --INFO--
 * Address:	801087D8
 * Size:	000090
 */
void NaviPushPikiState::init(Navi* navi)
{
	navi->startMotion(PaniMotionInfo(PIKIANIM_Push, navi), PaniMotionInfo(PIKIANIM_Push));
	navi->mMotionSpeed = 30.0f;
	_10                = 1;
	PRINT("push piki start +++ \n");
}

/*
 * --INFO--
 * Address:	80108868
 * Size:	0001A8
 */
void NaviPushPikiState::exec(Navi* navi)
{
	navi->makeVelocity(false);

	if (!_10) {
		navi->mNaviAnimMgr.finishMotion(navi);
		return;
	}

	Vector3f dir(sinf(navi->mFaceDirection), 0.0f, cosf(navi->mFaceDirection));
	f32 dp                = navi->mTargetVelocity.DP(dir);
	navi->mTargetVelocity = dp * dir;
	navi->mVelocity       = navi->mTargetVelocity;
	if (navi->_74C.length() < 0.1f) {
		navi->mNaviAnimMgr.finishMotion(navi);
	}
	_10 = 0;
}

/*
 * --INFO--
 * Address:	80108A10
 * Size:	000004
 */
void NaviPushPikiState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80108A14
 * Size:	0000E4
 */
void NaviPushPikiState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		if (navi->mWallCollObj) {
			Vector3f dir(sinf(navi->mFaceDirection), 0.0f, cosf(navi->mFaceDirection));
			dir = dir * 4.0f;
			navi->mWallCollObj->applyVelocity(*navi->mWallPlane, navi->mPosition, dir);
		}
		break;
	case KEY_Finished:
		transit(navi, NAVISTATE_Walk);
		break;
	}
}

/*
 * --INFO--
 * Address:	80108AF8
 * Size:	00000C
 */
void NaviPushPikiState::procCollideMsg(Navi* navi, MsgCollide*)
{
	_10 = 1;
}

/*
 * --INFO--
 * Address:	80108B04
 * Size:	000044
 */
NaviNukuState::NaviNukuState()
    : NaviState(NAVISTATE_Nuku)
{
}

/*
 * --INFO--
 * Address:	80108B48
 * Size:	000184
 */
void NaviNukuState::init(Navi* navi)
{
	PRINT("NAVI NUKU INIT *\n");
	navi->mMotionSpeed = 30.0f;

	if (navi->mFastPluckKeyTaps > 0) {
		navi->startMotion(PaniMotionInfo(PIKIANIM_Nuku_Fast, navi), PaniMotionInfo(PIKIANIM_Nuku_Fast));
		PRINT("**** FAST NUKU\n");
	} else {
		navi->startMotion(PaniMotionInfo(PIKIANIM_Nuku, navi), PaniMotionInfo(PIKIANIM_Nuku));
		PRINT("---- SLOW NUKU\n");
	}

	navi->_814 = 0.0f;
	_10        = C_NAVI_PROP(navi)._1CC();
	if (navi->mIsCursorVisible && !playerState->isChallengeMode() && !navi->mIsPlucking && playerState->mTotalPluckedPikiCount < 100) {
		cameraMgr->mCamera->startMotion(cameraMgr->mCamera->mAttentionInfo);
		PRINT_GLOBAL("> camera START MOTION | NUKU");
		navi->mIsPlucking                    = true;
		cameraMgr->mCamera->mControlsEnabled = false;
	}

	if (!AIConstant::_instance->mConstants._54()) {
		navi->_930 = false;
	}
	navi->_930 = false;
	_12        = false;
	_14        = false;
	_13        = false;
	_15        = false;
	seSystem->playPlayerSe(SE_PIKI_PULLING);
}

/*
 * --INFO--
 * Address:	80108CCC
 * Size:	000110
 */
void NaviNukuState::exec(Navi* navi)
{
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	if (!_13 && navi->mKontroller->keyUp(KeyConfig::_instance->mExtractKey.mBind)) {
		_13 = true;
	}

	if (_13 && navi->mKontroller->keyDown(KeyConfig::_instance->mExtractKey.mBind)) {
		_14 = true;
		navi->mIsPlucking;
		navi->mFastPluckKeyTaps++;
	}
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	navi->_814 += gsys->getFrameTime();
	navi->_814 = -1000.0f;
	navi->mNaviAnimMgr.finishMotion(navi);
	navi->_7BC->mNavi = navi;
}

/*
 * --INFO--
 * Address:	80108DDC
 * Size:	000038
 */
void NaviNukuState::cleanup(Navi* navi)
{
	if (!_14 && navi->mIsPlucking) {
		PRINT("renzoku %d + 1 nuki !!\n", navi->mFastPluckKeyTaps);
		navi->mFastPluckKeyTaps   = 0;
		navi->mNoPluckTimer       = 0;
	}
	playerState->mTotalPluckedPikiCount++;
	PRINT("** player pulled out %d pikmins so far\n", playerState->mTotalPluckedPikiCount);
}

/*
 * --INFO--
 * Address:	80108E14
 * Size:	00012C
 */
void NaviNukuState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		_15        = true;
		navi->_930 = false;
		seSystem->playPlayerSe(SE_PIKI_PULLED2);
		_10--;
		if (_10 == 0) {
			seSystem->playPlayerSe(SE_PIKI_PULLED);
			PRINT("PULLED2 ****\n");
			navi->mNaviAnimMgr.finishMotion(navi);
			_12 = true;
		}
		break;
	case KEY_Finished:
		navi->_810 = 0;
		if (_14) {
			if (!navi->procActionButton()) {
				_14 = false;
				transit(navi, NAVISTATE_Walk);
				navi->mFastPluckKeyTaps = 0;
			}
		} else {
			transit(navi, NAVISTATE_Walk);
			navi->mFastPluckKeyTaps = 0;
		}
		navi->_770 = 0;
		break;
	}
}

/*
 * --INFO--
 * Address:	80108F40
 * Size:	000060
 */
NaviNukuAdjustState::NaviNukuAdjustState()
    : NaviState(NAVISTATE_NukuAdjust)
{
}

/*
 * --INFO--
 * Address:	80108FA0
 * Size:	00002C
 */
void NaviNukuAdjustState::resume(Navi* navi)
{
	cleanup(navi);
}

/*
 * --INFO--
 * Address:	80108FCC
 * Size:	000030
 */
void NaviNukuAdjustState::restart(Navi* navi)
{
	transit(navi, NAVISTATE_Walk);
}

/*
 * --INFO--
 * Address:	80108FFC
 * Size:	0001E4
 */
void NaviNukuAdjustState::init(Navi* navi)
{
	playerState->mDemoFlags.setFlagOnly(DEMOFLAG_NoPikminTimeout);
	_20 = false;
	PRINT("NAVI ADJUST INIT *\n");

	Vector3f pos;
	if (DelayPikiBirth) {
		pos = navi->_7C0->mPosition - navi->mPosition;
	} else {
		pos = navi->_7BC->mPosition - navi->mPosition;
	}
	_10     = atan2f(pos.x, pos.z);
	f32 len = pos.normalise();
	if (DelayPikiBirth) {
		_14 = navi->_7C0->mPosition - (6.0f * pos);
	} else {
		_14 = navi->_7BC->mPosition - (6.0f * pos);
	}
	navi->mOdoMeter.start(0.4f, 4.0f);
}

/*
 * --INFO--
 * Address:	801091E0
 * Size:	00045C
 */
void NaviNukuAdjustState::exec(Navi* navi)
{
	if (navi->mKontroller->keyDown(KBBTN_B)) {
		navi->mFastPluckKeyTaps = 0;
		transit(navi, NAVISTATE_Walk);
		return;
	}

	if (!navi->mOdoMeter.moving(navi->mPosition, _24)) {
		navi->mFastPluckKeyTaps = 0;
		transit(navi, NAVISTATE_Walk);
		return;
	}
	_24 = navi->mPosition;
	navi->setCreatureFlag(CF_Unk11);
	Vector3f pos;
	if (DelayPikiBirth) {
		pos = navi->_7C0->mPosition - navi->mPosition;
	} else {
		pos = navi->_7BC->mPosition - navi->mPosition;
	}

	pos.normalise();
	pos     = _14 - navi->mPosition;
	f32 len = pos.normalise();
	f32 ang = angDist(_10, navi->mFaceDirection);
	if (quickABS(ang) < PI / 10.0f && len < 1.0f) {
		PRINT("dist = %f ang diff is %f\n", len, ang);
		if (DelayPikiBirth) {
			pikiMgr->meBirthMode = true;
			Piki* piki           = (Piki*)pikiMgr->birth();
			pikiMgr->meBirthMode = false;
			if (!piki) {
				transit(navi, NAVISTATE_Walk);
				PRINT("nuku failed\n");
				return;
			}
			piki->init(navi);
			piki->initColor(navi->_7C0->mSeedColor);
			piki->setFlower(navi->_7C0->mFlowerStage);
			piki->resetPosition(navi->_7C0->mPosition);

			pikiMgr->meNukiMode = true;
			piki->changeMode(PikiMode::FormationMode, navi);
			pikiMgr->meNukiMode = false;
			navi->_7C0->finishWaterEffect();
			navi->_7C0->kill(false);
			navi->_7C0 = nullptr;
			navi->_7BC = piki;
			navi->_7BC->stimulate(InteractPullout(navi));
		} else {
			navi->_7BC->stimulate(InteractPullout(navi));
		}
		transit(navi, NAVISTATE_Nuku);
	} else {
		f32 v = ang * 0.2f;
		if (quickABS(v) < PI / 20.0f) {
			v = (v > 0.0f) ? PI / 20.0f : -(PI / 20.0f);
		}
		navi->mFaceDirection = roundAng(navi->mFaceDirection + v);
		PRINT("d = %f faceDir = %f ang = %f\n", len, navi->mFaceDirection, _10);

		f32 fTime = gsys->getFrameTime();
		f32 mod   = 100.0f;
		if (fTime * 100.0f > len) {
			mod = 0.5f / fTime;
		}
		navi->mVelocity       = pos * mod;
		navi->mTargetVelocity = pos * mod;
		navi->setCreatureFlag(CF_Unk11);
		navi->mRotation.set(0.0f, navi->mFaceDirection, 0.0f);
	}
	STACK_PAD_STRUCT(1);
}

/*
 * --INFO--
 * Address:	8010963C
 * Size:	000010
 */
void NaviNukuAdjustState::cleanup(Navi* navi)
{
	navi->resetCreatureFlag(CF_Unk11);
}

/*
 * --INFO--
 * Address:	8010964C
 * Size:	000044
 */
NaviPressedState::NaviPressedState()
    : NaviState(NAVISTATE_Pressed)
{
}

/*
 * --INFO--
 * Address:	80109690
 * Size:	000010
 */
void NaviPressedState::init(Navi* navi)
{
	navi->_814 = C_NAVI_PROP(navi)._2DC();
	PRINT("pressed !\n");
}

/*
 * --INFO--
 * Address:	801096A0
 * Size:	0000F4
 */
void NaviPressedState::exec(Navi* navi)
{
	f32 ratio;
	f32 baseScale = C_NAVI_PROP(navi).mDisplayScale();
	navi->_814 -= gsys->getFrameTime();
	f32 y = navi->_814;

	if (y < 0.0f) {
		navi->_814 = 0.0f;
		navi->mScale.set(baseScale, baseScale, baseScale);
		if (navi->mHealth <= 1.0f) {
			transit(navi, NAVISTATE_Dead);
		} else {
			transit(navi, NAVISTATE_Walk);
		}
		return;
	}

	f32 xz = C_NAVI_PROP(navi)._2DC() - C_NAVI_PROP(navi)._2EC();
	if (y > xz) {
		xz = 2.0f;
		y  = 0.01f;
	} else {
		ratio = y / xz;
		xz    = ratio + 1.0f;
		y     = (1.0f - ratio) * 0.99f + 0.01f;
	}
	navi->mScale.set(baseScale * xz, baseScale * y, baseScale * xz);
}

/*
 * --INFO--
 * Address:	80109794
 * Size:	000004
 */
void NaviPressedState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80109798
 * Size:	000044
 */
NaviSowState::NaviSowState()
    : NaviState(NAVISTATE_Sow)
{
}

/*
 * --INFO--
 * Address:	801097DC
 * Size:	000074
 */
void NaviSowState::init(Navi* navi)
{
	navi->startMotion(PaniMotionInfo(PIKIANIM_Tanemaki, navi), PaniMotionInfo(PIKIANIM_Tanemaki));
}

/*
 * --INFO--
 * Address:	80109850
 * Size:	000004
 */
void NaviSowState::exec(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80109854
 * Size:	000004
 */
void NaviSowState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80109858
 * Size:	000044
 */
NaviWaterState::NaviWaterState()
    : NaviState(NAVISTATE_Water)
{
}

/*
 * --INFO--
 * Address:	8010989C
 * Size:	0000A4
 */
void NaviWaterState::init(Navi* navi)
{
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->startMotion(PaniMotionInfo(PIKIANIM_Tanemaki, navi), PaniMotionInfo(PIKIANIM_Tanemaki));
}

/*
 * --INFO--
 * Address:	80109940
 * Size:	000004
 */
void NaviWaterState::exec(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80109944
 * Size:	000004
 */
void NaviWaterState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80109948
 * Size:	000044
 */
NaviAttackState::NaviAttackState()
    : NaviState(NAVISTATE_Attack)
{
}

/*
 * --INFO--
 * Address:	8010998C
 * Size:	00002C
 */
void NaviAttackState::resume(Navi* navi)
{
	cleanup(navi);
}

/*
 * --INFO--
 * Address:	801099B8
 * Size:	000030
 */
void NaviAttackState::restart(Navi* navi)
{
	transit(navi, NAVISTATE_Walk);
}

/*
 * --INFO--
 * Address:	801099E8
 * Size:	0000CC
 */
void NaviAttackState::init(Navi* navi)
{
	navi->startMotion(PaniMotionInfo(PIKIANIM_Punch, navi), PaniMotionInfo(PIKIANIM_Punch));
	navi->enableMotionBlend();
	navi->mNaviAnimMgr.getLowerAnimator().startMotion(PaniMotionInfo(1));
	navi->mNaviAnimMgr.getLowerAnimator().mAnimationCounter = 10.0f;
	_10                                                     = 0;
	_18                                                     = 0.0f;
	_14                                                     = 0.0f;
	seSystem->playPlayerSe(SE_PLAYER_PUNCH);
	_12 = false;
}

/*
 * --INFO--
 * Address:	80109AB4
 * Size:	000424
 */
void NaviAttackState::exec(Navi* navi)
{
	if (navi->demoCheck()) {
		return;
	}
	navi->makeVelocity(false);
	//_18 += gsys->getFrameTime();

	if (navi->mKontroller->keyClick(KeyConfig::_instance->mSetCursorKey.mBind)) {
		_12 = true;
	}

	if (_10 != 1) {
		return;
	}

	Iterator it(tekiMgr);
	CI_LOOP(it)
	{
		Creature* teki = *it;
		if (teki->isAlive() && teki->isVisible() && !teki->isFlying()) {
			Vector3f diff = teki->mPosition - navi->mPosition;
			f32 angle     = atan2f(diff.x, diff.z);
			if (diff.length() <= teki->getCentreSize() + navi->getCentreSize() + C_NAVI_PROP(navi)._3DC()) {
				f32 ang = absF(angDist(navi->mFaceDirection, angle));
				if (ang < 2.3561945f) {
					InteractAttack act(navi, nullptr, C_NAVI_PROP(navi)._3CC(), false);
					if (teki->stimulate(act)) {
						Vector3f dir(sinf(navi->mFaceDirection), 0.0f, cosf(navi->mFaceDirection));
						dir = navi->mPosition + dir * 11.0f;
						effectMgr->create(EffectMgr::EFF_Navi_PunchA, dir, nullptr, nullptr);
						effectMgr->create(EffectMgr::EFF_Navi_PunchB, dir, nullptr, nullptr);
						rumbleMgr->start(RUMBLE_Unk2, 0, nullptr);
						navi->playEventSound(teki, SE_PIKI_ATTACK_HIT);
						_10 = 2;
					} else {
						if (_12) {
							transit(navi, NAVISTATE_Gather);
						}
					}
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80109ED8
 * Size:	000004
 */
void NaviAttackState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80109EDC
 * Size:	000080
 */
void NaviAttackState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		_10 = 1;
		break;
	case KEY_Finished:
		if (_12) {
			transit(navi, NAVISTATE_Gather);
		} else {
			transit(navi, NAVISTATE_Walk);
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	80109F5C
 * Size:	000044
 */
NaviLockState::NaviLockState()
    : NaviState(NAVISTATE_Lock)
{
}

/*
 * --INFO--
 * Address:	80109FA0
 * Size:	000004
 */
void NaviLockState::init(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80109FA4
 * Size:	000004
 */
void NaviLockState::exec(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80109FA8
 * Size:	000004
 */
void NaviLockState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	80109FAC
 * Size:	000044
 */
NaviClearState::NaviClearState()
    : NaviState(NAVISTATE_Clear)
{
}

/*
 * --INFO--
 * Address:	80109FF0
 * Size:	0000A4
 */
void NaviClearState::init(Navi* navi)
{
	navi->startMotion(PaniMotionInfo(PIKIANIM_WaveJmp, navi), PaniMotionInfo(PIKIANIM_WaveJmp));
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	8010A094
 * Size:	000004
 */
void NaviClearState::exec(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	8010A098
 * Size:	000050
 */
void NaviClearState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	if (msg->mKeyEvent->mEventType == 0) {
		flowCont.mGameEndCondition = 3;
		flowCont._248              = navi->getPlatePikis();
	}
}

/*
 * --INFO--
 * Address:	8010A0E8
 * Size:	000004
 */
void NaviClearState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	8010A0EC
 * Size:	000044
 */
NaviIroIroState::NaviIroIroState()
    : NaviState(NAVISTATE_IroIro)
{
}

/*
 * --INFO--
 * Address:	8010A130
 * Size:	000004
 */
void NaviIroIroState::init(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	8010A134
 * Size:	00001C
 */
void NaviIroIroState::exec(Navi* navi)
{
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	8010A150
 * Size:	000004
 */
void NaviIroIroState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	8010A154
 * Size:	000044
 */
NaviDeadState::NaviDeadState()
    : NaviState(NAVISTATE_Dead)
{
}

/*
 * --INFO--
 * Address:	8010A198
 * Size:	000004
 */
void NaviDeadState::restart(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	8010A19C
 * Size:	000154
 */
void NaviDeadState::init(Navi* navi)
{
	GameStat::orimaDead = true;
	playerState->mResultFlags.setOn(RESFLAG_OlimarDown);
	gameflow.mGameInterface->message(14, 0);
	gameflow.mGameInterface->message(16, 1);
	navi->mMotionSpeed = 30.0f;
	navi->startMotion(PaniMotionInfo(PIKIANIM_ODead, navi), PaniMotionInfo(PIKIANIM_ODead));
	seSystem->playPlayerSe(SE_PLAYER_DOWN);

	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	cameraMgr->mCamera->startMotion(cameraMgr->mCamera->mAttentionInfo);
	cameraMgr->mCamera->mIsActive = false;
	seMgr->setPikiNum(0);
	navi->releasePikis();
	GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
}

/*
 * --INFO--
 * Address:	8010A2F0
 * Size:	00001C
 */
void NaviDeadState::exec(Navi* navi)
{
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	8010A30C
 * Size:	000004
 */
void NaviDeadState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	8010A310
 * Size:	000054
 */
void NaviDeadState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case 0:
		gameflow.mGameInterface->message(5, 1);
		break;
	}
}

/*
 * --INFO--
 * Address:	8010A364
 * Size:	000044
 */
NaviPikiZeroState::NaviPikiZeroState()
    : NaviState(NAVISTATE_PikiZero)
{
}

/*
 * --INFO--
 * Address:	8010A3A8
 * Size:	000098
 */
void NaviPikiZeroState::init(Navi* navi)
{
	// 'TOTAL ANNIHILATION!' etc lol
	PRINT("ZENMETSU! ZENMETSU! ZENMETSU! ZENMETSU! ZENMETSU! ZENMETSU! ZENMETSU! ZENMETSU! ZENMETSU! \n");
	gameflow.mGameInterface->message(14, 0);
	gameflow.mGameInterface->message(16, 1);
	playerState->mResultFlags.setOn(RESFLAG_PikminExtinction);
	_12 = 30;
	GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
}

/*
 * --INFO--
 * Address:	8010A440
 * Size:	000054
 */
void NaviPikiZeroState::exec(Navi* navi)
{
	if (--_12 == 0) {
		gameflow.mGameInterface->message(5, 0);
	}
}

/*
 * --INFO--
 * Address:	8010A494
 * Size:	000004
 */
void NaviPikiZeroState::cleanup(Navi* navi)
{
}

/*
 * --INFO--
 * Address:	8010A498
 * Size:	000004
 */
void NaviPikiZeroState::procAnimMsg(Navi* navi, MsgAnim*)
{
}

/*
 * --INFO--
 * Address:	8010A49C
 * Size:	00006C
 */
NaviStartingState::NaviStartingState()
    : NaviState(NAVISTATE_Starting)
{
}

/*
 * --INFO--
 * Address:	8010A508
 * Size:	000274
 */
void NaviStartingState::init(Navi* navi)
{
	gameflow.mGameInterface->message(14, 0);
	navi->startMotion(PaniMotionInfo(PIKIANIM_Walk, navi), PaniMotionInfo(PIKIANIM_Walk));

	UfoItem* ufo = itemMgr->getUfo();
	if (ufo) {
		f32 dist = 120.0f;
		Vector3f dir(sinf(ufo->mFaceDirection), 0.0f, cosf(ufo->mFaceDirection));

		// spawn navi 50 units in front of ship
		navi->mPosition = ufo->mPosition + dir * 50.0f;

		// make sure navi is on the ground
		navi->mPosition.y = mapMgr->getMinY(navi->mPosition.x, navi->mPosition.z, true);
		_14               = navi->mPosition + dir * dist;
		_14.y             = mapMgr->getMinY(_14.x, _14.z, true);
		_14               = ufo->getGoalPos();
	}
	_30 = 0;
	_10 = 1.7f;

	GoalItem* goal = itemMgr->getContainer(Blue); // lol?
	if (goal) {
		_20 = goal->mPosition;
		_20.y += 200.0f;
		navi->startLook(&_20);
	}
	_34 = navi->mPosition;
}

/*
 * --INFO--
 * Address:	8010A77C
 * Size:	0000DC
 */
void NaviStartingState::procCollideMsg(Navi* navi, MsgCollide* msg)
{
	if (_30 == 2) {
		return;
	}
	PRINT("collide cease !! : %s\n", ObjType::getName(msg->mEvent.mCollider->mObjType));
	_30 = 2;
	navi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Sagasu2, navi), PaniMotionInfo(PIKIANIM_Sagasu2));
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	_32 = false;
}

/*
 * --INFO--
 * Address:	8010A858
 * Size:	0002A4
 */
void NaviStartingState::exec(Navi* navi)
{
	UfoItem* ufo = itemMgr->getUfo();
	if (ufo) {
		_14 = ufo->getGoalPos();
	}

	switch (_30) {
	case 0:
		_10 -= gsys->getFrameTime();
		if (_10 < 0.0f) {
			_30 = 1;
			navi->mOdoMeter.start(1.0f, 10.0f);
		}

		return;

	case 1:
		Vector3f diff         = _14 - navi->mPosition;
		f32 len               = diff.normalise();
		navi->mVelocity       = diff * 25.0f;
		navi->mTargetVelocity = navi->mVelocity;
		if (!navi->mOdoMeter.moving(navi->mPosition, _34)) {
			PRINT("orima giveup!\n");
			len = 0.0f;
		}

		if (len < 6.0f) {
			_30 = 2;
			navi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Sagasu2, navi), PaniMotionInfo(PIKIANIM_Sagasu2));
			navi->mVelocity.set(0.0f, 0.0f, 0.0f);
			navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			_32 = false;
		}
		break;
	case 2:
		if (_32)
			transit(navi, NAVISTATE_Walk);
		break;
	}

	_34 = navi->mPosition;
}

/*
 * --INFO--
 * Address:	8010AAFC
 * Size:	000034
 */
void NaviStartingState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
	case KEY_LoopEnd:
		if (_30 == 2) {
			_32 = true;
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	8010AB30
 * Size:	000084
 */
void NaviStartingState::cleanup(Navi* navi)
{
	gameflow.mGameInterface->message(14, 1);
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	navi->finishLook();
}

/*
 * --INFO--
 * Address:	8010ABB4
 * Size:	000044
 */
NaviPartsAccessState::NaviPartsAccessState()
    : NaviState(NAVISTATE_PartsAccess)
{
}

/*
 * --INFO--
 * Address:	8010ABF8
 * Size:	000104
 */
void NaviPartsAccessState::init(Navi* navi)
{
	navi->startMotion(PaniMotionInfo(PIKIANIM_Punch, navi), PaniMotionInfo(PIKIANIM_Punch));
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	gameflow.mGameInterface->message(14, 0);
	GameCoreSection::startPause(0x8001);
	_10 = false;

	int id = PelletMgr::getUfoIndexFromID(((Pellet*)navi->_304)->mConfig->mModelId.mId) + 1;
	Jac_StartPartsFindDemo(id, 0);
}

/*
 * --INFO--
 * Address:	8010ACFC
 * Size:	000050
 */
void NaviPartsAccessState::exec(Navi* navi)
{
	if (_10 == true && !gameflow.mIsUiOverlayActive) {
		transit(navi, NAVISTATE_Walk);
	}
}

/*
 * --INFO--
 * Address:	8010AD4C
 * Size:	00004C
 */
void NaviPartsAccessState::cleanup(Navi* navi)
{
	GameCoreSection::finishPause();
	Jac_FinishPartsFindDemo();
	gameflow.mGameInterface->message(14, 1);
}

/*
 * --INFO--
 * Address:	8010AD98
 * Size:	0000A8
 */
void NaviPartsAccessState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case 0:
		if (!_10) {
			_10                    = true;
			Pellet* pelt           = (Pellet*)navi->_304;
			int id                 = PelletMgr::getUfoIndexFromID(pelt->mConfig->mModelId.mId);
			gameflow.mMovieType    = 1;
			gameflow.mMovieInfoNum = id;
			playerState->mDemoFlags.resetFlag(id + 32);
			playerState->mDemoFlags.setFlag(id + 32, pelt);
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	8010AE40
 * Size:	000044
 */
NaviUfoAccessState::NaviUfoAccessState()
    : NaviState(NAVISTATE_UfoAccess)
{
}

/*
 * --INFO--
 * Address:	8010AE84
 * Size:	0000D0
 */
void NaviUfoAccessState::init(Navi* navi)
{
	PRINT("** GOT HERE !!!!\n");
	navi->startMotion(PaniMotionInfo(PIKIANIM_Punch, navi), PaniMotionInfo(PIKIANIM_Punch));
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	GameCoreSection::startPause(0x8003);
	_10 = false;
	Jac_StartPartsFindDemo(0, 0);
	PRINT("UFO ACCESS INIT !\n");
}

/*
 * --INFO--
 * Address:	8010AF54
 * Size:	000050
 */
void NaviUfoAccessState::exec(Navi* navi)
{
	if (_10 == true && !gameflow.mIsUiOverlayActive) {
		PRINT("TRANSIT TO WALK !\n");
		transit(navi, NAVISTATE_Walk);
	}
}

/*
 * --INFO--
 * Address:	8010AFA4
 * Size:	000028
 */
void NaviUfoAccessState::cleanup(Navi* navi)
{
	GameCoreSection::finishPause();
	Jac_FinishPartsFindDemo();
	PRINT("UFO ACCESS CLEANUP!\n");
}

/*
 * --INFO--
 * Address:	8010AFCC
 * Size:	000078
 */
void NaviUfoAccessState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	PRINT("GOT ANIMATION ?\n");
	switch (msg->mKeyEvent->mEventType) {
	case 0:
		if (!_10) {
			_10                    = true;
			gameflow.mMovieType    = 0;
			gameflow.mMovieInfoNum = -1;
			gameflow.mGameInterface->message(0, 17);
		}
		break;
	}
}
