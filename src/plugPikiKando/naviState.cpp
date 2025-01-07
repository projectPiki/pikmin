#include "NaviState.h"
#include "sysNew.h"
#include "Dolphin/os.h"
#include "Pellet.h"
#include "Interactions.h"
#include "SoundMgr.h"
#include "Kontroller.h"
#include "gameflow.h"
#include "UtilityKando.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "EffectMgr.h"
#include "UfoItem.h"
#include "MoviePlayer.h"
#include "Stickers.h"
#include "NaviMgr.h"
#include "Interface.h"
#include "GameCoreSection.h"

#include "jaudio/PikiDemo.h"
#include "GoalItem.h"
#include "UtEffect.h"
#include "CPlate.h"
#include "DebugLog.h"

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
DEFINE_PRINT("naviState");

/*
 * --INFO--
 * Address:	80101140
 * Size:	000008
 */
NaviState* NaviStateMachine::getNaviState(Navi* navi) { return navi->mCurrState; }

/*
 * --INFO--
 * Address:	80101148
 * Size:	0015D4
 */
void NaviStateMachine::init(Navi* navi)
{
	// this is probably from some debug stuff?
	u32 badCompiler[0x48];

	setup(NAVISTATE_Count);
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
	navi->becomePellet('navi', navi->mPosition, navi->mDirection);
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
		mIsFinished     = true;
		navi->mIsPellet = false;
		navi->startMotion(PaniMotionInfo(PIKIANIM_GetUp, navi), PaniMotionInfo(PIKIANIM_GetUp));
	}

	if (!mIsFinished
	    && (navi->mKontroller->isCurrentInput(KBBTN_A) || navi->mKontroller->isCurrentInput(KBBTN_B)
	        || navi->mKontroller->isCurrentInput(KBBTN_X) || navi->mKontroller->isCurrentInput(KBBTN_L)
	        || navi->mKontroller->isCurrentInput(KBBTN_R) || navi->mKontroller->isCurrentInput(KBBTN_MSTICK_LEFT)
	        || navi->mKontroller->isCurrentInput(KBBTN_MSTICK_RIGHT) || navi->mKontroller->isCurrentInput(KBBTN_MSTICK_UP)
	        || navi->mKontroller->isCurrentInput(KBBTN_MSTICK_DOWN) || navi->mKontroller->isCurrentInput(KBBTN_CSTICK_LEFT)
	        || navi->mKontroller->isCurrentInput(KBBTN_CSTICK_RIGHT) || navi->mKontroller->isCurrentInput(KBBTN_CSTICK_UP)
	        || navi->mKontroller->isCurrentInput(KBBTN_CSTICK_DOWN))) {
		mIsFinished = true;
		if (navi->mPellet) {
			navi->mPellet->kill(false);
		}

		PRINT("GETUP MOTION START\n");

		navi->mIsPellet = false;
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

	navi->mIsPellet = false;
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
	navi->mLookAtPosPtr = &mLookAtPos;
	navi->_2F0          = 0;
	navi->startMotion(PaniMotionInfo(PIKIANIM_Wait), PaniMotionInfo(PIKIANIM_Wait));
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (navi->mGoalItem) {
		navi->mGoalItem->setSpotActive(false);
	}
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
	if (!gameflow.mMoviePlayer->_124) {
		navi->_774->restart();
		navi->_778->restart();

		PRINT("RETURN TO WALK : MOVIE END \n");
		if (navi->mIsBeingDamaged) {
			// wtf do i even do here
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
void NaviDemoInfState::init(Navi* navi) { }

/*
 * --INFO--
 * Address:	80102D64
 * Size:	00001C
 */
void NaviDemoInfState::exec(Navi* navi) { navi->mVelocity.set(0.0f, 0.0f, 0.0f); }

/*
 * --INFO--
 * Address:	80102D80
 * Size:	000004
 */
void NaviDemoInfState::cleanup(Navi* navi) { }

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
	f32 stickMovement = currStickDir.dot(mPrevStickDir);
	if (stickMovement < -0.3f || navi->mKontroller->isPressed(KBBTN_A) || navi->mKontroller->isPressed(KBBTN_B)) {
		mActionCount++;

		NaviProp::NaviParms& naviParms = static_cast<NaviProp*>(navi->mProps)->mNaviProps;
		s32 minFlickActions            = naviParms.mMinKinokoFlickActions();
		if (mActionCount > minFlickActions) {
			// after a certain amount of recorded actions, try and flick a puffmin
			Stickers stickers(navi);
			Iterator iter(&stickers);
			CI_LOOP(iter)
			{
				Creature* stuck = *iter; // 50/50 chance to flick a given puffmin
				if (!stuck || !coinFlip()) {
					continue;
				}

				if (stuck->stimulate(InteractFlick(navi, 220.0f, 5.0f, FLICK_BACKWARDS_ANGLE))) {
					playerState->mResultFlags.setOn(RESFLAG_Unk42);

					if (iter.mIndex >= 0) {
						iter.mIndex--;
					}
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

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stfd      f29, 0xD0(r1)
	  stfd      f28, 0xC8(r1)
	  stfd      f27, 0xC0(r1)
	  stfd      f26, 0xB8(r1)
	  stfd      f25, 0xB0(r1)
	  stmw      r23, 0x8C(r1)
	  mr        r28, r4
	  addi      r27, r3, 0
	  lwz       r0, 0x180(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x60
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  addi      r4, r28, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x310

	.loc_0x60:
	  addi      r3, r28, 0
	  li        r4, 0
	  bl        -0x53E0
	  lwz       r3, 0x2E4(r28)
	  bl        -0xC2404
	  fmr       f25, f1
	  lwz       r3, 0x2E4(r28)
	  bl        -0xC2448
	  stfs      f1, 0x74(r1)
	  lfs       f0, -0x2A28(r13)
	  stfs      f0, 0x78(r1)
	  stfs      f25, 0x7C(r1)
	  lfs       f3, 0x74(r1)
	  lfs       f2, 0x10(r27)
	  lfs       f1, 0x78(r1)
	  lfs       f0, 0x14(r27)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x7C(r1)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x18(r27)
	  lfs       f0, -0x6260(r2)
	  fmuls     f3, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0xE0
	  lwz       r3, 0x2E4(r28)
	  lwz       r3, 0x28(r3)
	  rlwinm.   r0,r3,0,19,19
	  bne-      .loc_0xE0
	  rlwinm.   r0,r3,0,18,18
	  beq-      .loc_0x2C4

	.loc_0xE0:
	  lwz       r3, 0x20(r27)
	  addi      r0, r3, 0x1
	  stw       r0, 0x20(r27)
	  lwz       r3, 0x224(r28)
	  lwz       r4, 0x20(r27)
	  lwz       r0, 0x408(r3)
	  cmpw      r4, r0
	  ble-      .loc_0x2A4
	  addi      r3, r1, 0x64
	  addi      r4, r28, 0
	  bl        -0x722EC
	  addi      r30, r1, 0x64
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f29, -0x6250(r2)
	  lis       r4, 0x802B
	  lfs       f30, -0x624C(r2)
	  lfs       f31, -0x6248(r2)
	  mr        r29, r3
	  lfd       f25, -0x6240(r2)
	  subi      r25, r5, 0x3064
	  lfs       f26, -0x6258(r2)
	  lfs       f27, -0x625C(r2)
	  subi      r26, r4, 0x3168
	  lfs       f28, -0x6254(r2)
	  addi      r31, r1, 0x44
	  lis       r24, 0x4330
	  b         .loc_0x240

	.loc_0x160:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x184
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x19C

	.loc_0x184:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x19C:
	  cmplwi    r3, 0
	  addi      r23, r3, 0
	  beq-      .loc_0x224
	  bl        0x115060
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x84(r1)
	  stw       r24, 0x80(r1)
	  lfd       f0, 0x80(r1)
	  fsubs     f0, f0, f25
	  fdivs     f0, f0, f26
	  fmuls     f0, f27, f0
	  fcmpo     cr0, f0, f28
	  ble-      .loc_0x224
	  stw       r25, 0x44(r1)
	  addi      r3, r23, 0
	  addi      r4, r31, 0
	  stw       r28, 0x48(r1)
	  stw       r26, 0x44(r1)
	  stfs      f29, 0x4C(r1)
	  stfs      f30, 0x50(r1)
	  stfs      f31, 0x54(r1)
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x224
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2A
	  addi      r3, r3, 0x70
	  bl        -0x7F67C
	  cmpwi     r29, 0
	  blt-      .loc_0x224
	  subi      r29, r29, 0x1

	.loc_0x224:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x240:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x268
	  li        r0, 0x1
	  b         .loc_0x294

	.loc_0x268:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x290
	  li        r0, 0x1
	  b         .loc_0x294

	.loc_0x290:
	  li        r0, 0

	.loc_0x294:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x160
	  li        r0, 0
	  stw       r0, 0x20(r27)

	.loc_0x2A4:
	  lwz       r3, 0x74(r1)
	  lwz       r0, 0x78(r1)
	  stw       r3, 0x10(r27)
	  stw       r0, 0x14(r27)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0x18(r27)
	  lfs       f0, -0x6264(r2)
	  stfs      f0, 0x1C(r27)

	.loc_0x2C4:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x1C(r27)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1C(r27)
	  lfs       f1, 0x1C(r27)
	  lfs       f0, -0x6268(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x310
	  lwz       r4, 0x74(r1)
	  li        r0, 0
	  lwz       r3, 0x78(r1)
	  stw       r4, 0x10(r27)
	  stw       r3, 0x14(r27)
	  lwz       r3, 0x7C(r1)
	  stw       r3, 0x18(r27)
	  stw       r0, 0x20(r27)
	  lfs       f0, -0x6264(r2)
	  stfs      f0, 0x1C(r27)

	.loc_0x310:
	  lmw       r23, 0x8C(r1)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lfd       f29, 0xD0(r1)
	  lfd       f28, 0xC8(r1)
	  lfd       f27, 0xC0(r1)
	  lfd       f26, 0xB8(r1)
	  lfd       f25, 0xB0(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801031A8
 * Size:	000004
 */
void NaviStuckState::cleanup(Navi* navi) { }

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
	_1C = 0;
	_1E = 0;
	effectMgr->create(EffectMgr::EFF_Unk50, navi->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Unk51, navi->mPosition, nullptr, nullptr);
	_10.set(0.0f, 0.0f, 0.0f);
	navi->mVelocity.set(0.0f, 0.0f, 0.0f);
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	_1F = 150;
}

/*
 * --INFO--
 * Address:	8010330C
 * Size:	000310
 */
void NaviBuryState::exec(Navi* navi)
{
	Vector3f stick(navi->mKontroller->getMainStickX(), 0.0f, navi->mKontroller->getMainStickY());
	navi->reviseController(stick);

	f32 stickMag = stick.length();

	switch (_1C) {
	case 0:
		if ((stickMag > 0.8f && _10.dot(stick) < 0.5f) || navi->mKontroller->isPressed(KBBTN_A) || navi->mKontroller->isPressed(KBBTN_B)) {
			_10 = stick;
			_1C = 1;
			_1D = 0;
			_1E = 0;
			navi->startMotion(PaniMotionInfo(PIKIANIM_GFuri1, navi), PaniMotionInfo(PIKIANIM_GFuri1));
		}
		break;
	case 1:
	case 2:
		if ((stickMag > 0.8f && _10.dot(stick) < -0.6f) || navi->mKontroller->isPressed(KBBTN_A) || navi->mKontroller->isPressed(KBBTN_B)) {
			_1D++;
			_10 = stick;
			if (_1C == 1) {
				_1C           = 2;
				f32 frame1Val = navi->mNaviAnimMgr.getLowerAnimator().mAnimationCounter;
				navi->startMotion(PaniMotionInfo(PIKIANIM_GFuri2, navi), PaniMotionInfo(PIKIANIM_GFuri2));
				navi->mNaviAnimMgr.getLowerAnimator().mAnimationCounter = frame1Val;
				navi->mNaviAnimMgr.mUpperAnimator.mAnimationCounter     = frame1Val;
			}
		}
		break;
	}

	if (_1F) {
		_1F--;
		if (_1F == 0) {
			_1C = 3;
			navi->startMotion(PaniMotionInfo(PIKIANIM_GNuke, navi), PaniMotionInfo(PIKIANIM_GNuke));
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stmw      r27, 0x7C(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  lwz       r3, 0x2E4(r4)
	  bl        -0xC2858
	  fmr       f31, f1
	  lwz       r3, 0x2E4(r31)
	  bl        -0xC289C
	  stfs      f1, 0x6C(r1)
	  mr        r3, r31
	  lfs       f0, -0x2A00(r13)
	  addi      r4, r1, 0x6C
	  stfs      f0, 0x70(r1)
	  stfs      f31, 0x74(r1)
	  bl        -0x5A4C
	  lfs       f0, 0x6C(r1)
	  lfs       f1, 0x74(r1)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x6268(r2)
	  fmuls     f1, f1, f1
	  fadds     f4, f2, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xC4
	  fsqrte    f1, f4
	  lfd       f3, -0x6238(r2)
	  lfd       f2, -0x6230(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x34(r1)
	  lfs       f4, 0x34(r1)

	.loc_0xC4:
	  lbz       r0, 0x1C(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0xE0
	  blt-      .loc_0x290
	  cmpwi     r0, 0x3
	  bge-      .loc_0x290
	  b         .loc_0x1AC

	.loc_0xE0:
	  lfs       f0, -0x6228(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x124
	  lfs       f3, 0x10(r30)
	  lfs       f2, 0x6C(r1)
	  lfs       f1, 0x14(r30)
	  lfs       f0, 0x70(r1)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x18(r30)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x74(r1)
	  lfs       f0, -0x6254(r2)
	  fmuls     f3, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0x13C

	.loc_0x124:
	  lwz       r3, 0x2E4(r31)
	  lwz       r3, 0x28(r3)
	  rlwinm.   r0,r3,0,19,19
	  bne-      .loc_0x13C
	  rlwinm.   r0,r3,0,18,18
	  beq-      .loc_0x290

	.loc_0x13C:
	  lwz       r5, 0x6C(r1)
	  li        r3, 0x1
	  lwz       r4, 0x70(r1)
	  li        r0, 0
	  cmplwi    r31, 0
	  stw       r5, 0x10(r30)
	  mr        r28, r31
	  stw       r4, 0x14(r30)
	  lwz       r4, 0x74(r1)
	  stw       r4, 0x18(r30)
	  stb       r3, 0x1C(r30)
	  stb       r0, 0x1D(r30)
	  stb       r0, 0x1E(r30)
	  beq-      .loc_0x178
	  addi      r28, r28, 0x2B8

	.loc_0x178:
	  addi      r3, r1, 0x58
	  li        r4, 0x4E
	  bl        0x1BACC
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x60
	  li        r4, 0x4E
	  bl        0x1BAEC
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0x8C40
	  b         .loc_0x290

	.loc_0x1AC:
	  lfs       f0, -0x6228(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x1F0
	  lfs       f3, 0x10(r30)
	  lfs       f2, 0x6C(r1)
	  lfs       f1, 0x14(r30)
	  lfs       f0, 0x70(r1)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x18(r30)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x74(r1)
	  lfs       f0, -0x6224(r2)
	  fmuls     f3, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0x208

	.loc_0x1F0:
	  lwz       r3, 0x2E4(r31)
	  lwz       r3, 0x28(r3)
	  rlwinm.   r0,r3,0,19,19
	  bne-      .loc_0x208
	  rlwinm.   r0,r3,0,18,18
	  beq-      .loc_0x290

	.loc_0x208:
	  lbz       r3, 0x1D(r30)
	  addi      r0, r3, 0x1
	  stb       r0, 0x1D(r30)
	  lwz       r3, 0x6C(r1)
	  lwz       r0, 0x70(r1)
	  stw       r3, 0x10(r30)
	  stw       r0, 0x14(r30)
	  lwz       r0, 0x74(r1)
	  stw       r0, 0x18(r30)
	  lbz       r0, 0x1C(r30)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x290
	  li        r0, 0x2
	  stb       r0, 0x1C(r30)
	  addi      r27, r31, 0x864
	  cmplwi    r31, 0
	  lfs       f31, 0x864(r31)
	  mr        r28, r31
	  beq-      .loc_0x258
	  addi      r28, r28, 0x2B8

	.loc_0x258:
	  addi      r3, r1, 0x48
	  li        r4, 0x4F
	  bl        0x1B9EC
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x50
	  li        r4, 0x4F
	  bl        0x1BA0C
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0x8D20
	  stfs      f31, 0x0(r27)
	  stfs      f31, 0x8B8(r31)

	.loc_0x290:
	  lbz       r3, 0x1F(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F8
	  subi      r0, r3, 0x1
	  stb       r0, 0x1F(r30)
	  lbz       r0, 0x1F(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x2F8
	  li        r0, 0x3
	  cmplwi    r31, 0
	  stb       r0, 0x1C(r30)
	  mr        r28, r31
	  beq-      .loc_0x2C8
	  addi      r28, r28, 0x2B8

	.loc_0x2C8:
	  addi      r3, r1, 0x38
	  li        r4, 0x50
	  bl        0x1B97C
	  addi      r30, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x40
	  li        r4, 0x50
	  bl        0x1B99C
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  bl        -0x8D90

	.loc_0x2F8:
	  lmw       r27, 0x7C(r1)
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010361C
 * Size:	0003D4
 */
void NaviBuryState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
	case KEY_LoopEnd:
		switch (_1C) {
		case 0:
			if (coinFlip()) {
				navi->startMotion(PaniMotionInfo(PIKIANIM_GWait2, navi), PaniMotionInfo(PIKIANIM_GWait2));
			} else {
				navi->startMotion(PaniMotionInfo(PIKIANIM_GWait1, navi), PaniMotionInfo(PIKIANIM_GWait1));
			}
			break;
		case 1:
		case 2:
			if (_1D == 0) {
				navi->startMotion(PaniMotionInfo(PIKIANIM_GWait1, navi), PaniMotionInfo(PIKIANIM_GWait1));
				_1C = 0;
			} else if (_1D >= static_cast<NaviProp*>(navi->mProps)->mNaviProps._40C()) {
				_1E++;
				if (_1E >= static_cast<NaviProp*>(navi->mProps)->mNaviProps._41C()) {
					_1C = 3;
					navi->startMotion(PaniMotionInfo(PIKIANIM_GNuke, navi), PaniMotionInfo(PIKIANIM_GNuke));
				}
				_1D = 0;
			} else {
				navi->startMotion(PaniMotionInfo(PIKIANIM_GWait1, navi), PaniMotionInfo(PIKIANIM_GWait1));
				_1C = 0;
				_1E = 0;
				_1D = 0;
			}
			break;
		case 3:
			transit(navi, NAVISTATE_Walk);
			break;
		}
		break;
	case KEY_PlayEffect:
		switch (_1C) {
		case 2:
			f32 randAngle = 2.0f * randFloat(PI);
			Vector3f dir(40.0f * sinf(randAngle), 0.0f, 40.0f * cosf(randAngle));
			EffectParm parm;
			parm.mPosition  = navi->getPosition();
			parm.mDirection = dir;
			parm._24        = 80.0f;
			UtEffectMgr::cast(3, parm);
			break;
		case 3:
			effectMgr->create(EffectMgr::EFF_Unk50, navi->mPosition, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Unk51, navi->mPosition, nullptr, nullptr);
			break;
		}
		break;
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF0(r1)
	  stfd      f31, 0xE8(r1)
	  stfd      f30, 0xE0(r1)
	  stw       r31, 0xDC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xD8(r1)
	  addi      r30, r3, 0
	  stw       r29, 0xD4(r1)
	  stw       r28, 0xD0(r1)
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x58
	  bge-      .loc_0x4C
	  cmpwi     r0, 0
	  beq-      .loc_0x58
	  b         .loc_0x3AC

	.loc_0x4C:
	  cmpwi     r0, 0x8
	  beq-      .loc_0x28C
	  b         .loc_0x3AC

	.loc_0x58:
	  lbz       r0, 0x1C(r30)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x26C
	  bge-      .loc_0x3AC
	  cmpwi     r0, 0
	  beq-      .loc_0x78
	  bge-      .loc_0x13C
	  b         .loc_0x3AC

	.loc_0x78:
	  bl        0x1149DC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6240(r2)
	  stw       r0, 0xCC(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x6258(r2)
	  stw       r0, 0xC8(r1)
	  lfs       f1, -0x625C(r2)
	  lfd       f3, 0xC8(r1)
	  lfs       f0, -0x6220(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xF8
	  cmplwi    r31, 0
	  addi      r30, r31, 0
	  beq-      .loc_0xC4
	  addi      r30, r30, 0x2B8

	.loc_0xC4:
	  addi      r3, r1, 0x74
	  li        r4, 0x4D
	  bl        0x1B870
	  addi      r29, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x7C
	  li        r4, 0x4D
	  bl        0x1B890
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0x8E9C
	  b         .loc_0x3AC

	.loc_0xF8:
	  cmplwi    r31, 0
	  addi      r30, r31, 0
	  beq-      .loc_0x108
	  addi      r30, r30, 0x2B8

	.loc_0x108:
	  addi      r3, r1, 0x64
	  li        r4, 0x4C
	  bl        0x1B82C
	  addi      r29, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x6C
	  li        r4, 0x4C
	  bl        0x1B84C
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0x8EE0
	  b         .loc_0x3AC

	.loc_0x13C:
	  lbz       r4, 0x1D(r30)
	  cmplwi    r4, 0
	  bne-      .loc_0x194
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x158
	  addi      r28, r28, 0x2B8

	.loc_0x158:
	  addi      r3, r1, 0x54
	  li        r4, 0x4C
	  bl        0x1B7DC
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x5C
	  li        r4, 0x4C
	  bl        0x1B7FC
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0x8F30
	  li        r0, 0
	  stb       r0, 0x1C(r30)
	  b         .loc_0x3AC

	.loc_0x194:
	  lwz       r3, 0x224(r31)
	  lwz       r0, 0x418(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x218
	  lbz       r3, 0x1E(r30)
	  addi      r0, r3, 0x1
	  stb       r0, 0x1E(r30)
	  lwz       r3, 0x224(r31)
	  lbz       r4, 0x1E(r30)
	  lwz       r0, 0x428(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x20C
	  li        r0, 0x3
	  cmplwi    r31, 0
	  stb       r0, 0x1C(r30)
	  mr        r28, r31
	  beq-      .loc_0x1DC
	  addi      r28, r28, 0x2B8

	.loc_0x1DC:
	  addi      r3, r1, 0x44
	  li        r4, 0x50
	  bl        0x1B758
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x4C
	  li        r4, 0x50
	  bl        0x1B778
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0x8FB4

	.loc_0x20C:
	  li        r0, 0
	  stb       r0, 0x1D(r30)
	  b         .loc_0x3AC

	.loc_0x218:
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x228
	  addi      r28, r28, 0x2B8

	.loc_0x228:
	  addi      r3, r1, 0x34
	  li        r4, 0x4C
	  bl        0x1B70C
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x3C
	  li        r4, 0x4C
	  bl        0x1B72C
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0x9000
	  li        r0, 0
	  stb       r0, 0x1C(r30)
	  stb       r0, 0x1E(r30)
	  stb       r0, 0x1D(r30)
	  b         .loc_0x3AC

	.loc_0x26C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3AC

	.loc_0x28C:
	  lbz       r0, 0x1C(r30)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x37C
	  bge-      .loc_0x3AC
	  cmpwi     r0, 0x2
	  bge-      .loc_0x2A8
	  b         .loc_0x3AC

	.loc_0x2A8:
	  bl        0x1147AC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6240(r2)
	  stw       r0, 0xCC(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x6258(r2)
	  stw       r0, 0xC8(r1)
	  lfs       f2, -0x625C(r2)
	  lfd       f1, 0xC8(r1)
	  lfs       f0, -0x6218(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x621C(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f30, f1, f0
	  fmr       f1, f30
	  bl        0x11824C
	  lfs       f0, -0x6214(r2)
	  fmuls     f31, f0, f1
	  fmr       f1, f30
	  bl        0x1183D0
	  lfs       f0, -0x6268(r2)
	  addi      r4, r1, 0x84
	  lfs       f2, -0x6214(r2)
	  li        r3, 0x3
	  stfs      f0, 0x8C(r1)
	  fmuls     f2, f2, f1
	  lfs       f1, -0x6210(r2)
	  stfs      f0, 0x88(r1)
	  stfs      f2, 0xB0(r1)
	  stfs      f0, 0x84(r1)
	  stfs      f1, 0xB4(r1)
	  stfs      f0, 0x98(r1)
	  stfs      f31, 0xB8(r1)
	  stfs      f0, 0x94(r1)
	  stfs      f0, 0x90(r1)
	  lwz       r0, 0x94(r31)
	  lwz       r6, 0x98(r31)
	  lwz       r5, 0xB0(r1)
	  stw       r0, 0x84(r1)
	  lwz       r0, 0xB4(r1)
	  stw       r6, 0x88(r1)
	  lwz       r6, 0x9C(r31)
	  stw       r6, 0x8C(r1)
	  stw       r5, 0x90(r1)
	  stw       r0, 0x94(r1)
	  lwz       r0, 0xB8(r1)
	  stw       r0, 0x98(r1)
	  lfs       f0, -0x625C(r2)
	  stfs      f0, 0xA8(r1)
	  bl        0x10950
	  b         .loc_0x3AC

	.loc_0x37C:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x32
	  li        r6, 0
	  li        r7, 0
	  bl        0x9918C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x33
	  li        r6, 0
	  li        r7, 0
	  bl        0x99174

	.loc_0x3AC:
	  lwz       r0, 0xF4(r1)
	  lfd       f31, 0xE8(r1)
	  lfd       f30, 0xE0(r1)
	  lwz       r31, 0xDC(r1)
	  lwz       r30, 0xD8(r1)
	  lwz       r29, 0xD4(r1)
	  lwz       r28, 0xD0(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801039F0
 * Size:	000004
 */
void NaviBuryState::cleanup(Navi* navi) { }

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
void NaviWalkState::restart(Navi* navi) { init(navi); }

/*
 * --INFO--
 * Address:	80103AE4
 * Size:	000DE8
 */
void NaviWalkState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x288(r1)
	  stfd      f31, 0x280(r1)
	  stfd      f30, 0x278(r1)
	  stfd      f29, 0x270(r1)
	  stfd      f28, 0x268(r1)
	  stfd      f27, 0x260(r1)
	  stfd      f26, 0x258(r1)
	  stfd      f25, 0x250(r1)
	  stmw      r26, 0x238(r1)
	  mr        r30, r4
	  addi      r29, r3, 0
	  lwz       r0, 0x180(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  li        r5, 0x12
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xDB8

	.loc_0x60:
	  mr        r3, r30
	  bl        -0x81330
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xDB8
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xDB8
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B5(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xDB8
	  lfs       f1, 0xA4(r30)
	  lfs       f0, 0xA8(r30)
	  fmuls     f2, f1, f1
	  lfs       f3, 0xAC(r30)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x6268(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x11C
	  fsqrte    f1, f4
	  lfd       f3, -0x6238(r2)
	  lfd       f2, -0x6230(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0xF8(r1)
	  lfs       f4, 0xF8(r1)

	.loc_0x11C:
	  lfs       f0, -0x625C(r2)
	  fcmpo     cr0, f4, f0
	  blt-      .loc_0x130
	  mr        r3, r30
	  bl        -0x79BD0

	.loc_0x130:
	  lfs       f30, -0x6268(r2)
	  li        r27, 0
	  lfd       f29, -0x6238(r2)
	  lis       r28, 0x636F
	  lfd       f28, -0x6230(r2)
	  lfs       f31, -0x620C(r2)

	.loc_0x148:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r27
	  bl        -0x1127C
	  mr.       r26, r3
	  beq-      .loc_0x2E0
	  lwz       r3, 0x220(r26)
	  addi      r4, r28, 0x6E74
	  bl        -0x7A538
	  addi      r31, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x0(r31)
	  addi      r3, r30, 0x40
	  addi      r4, r26, 0x40
	  fadds     f0, f0, f1
	  fmuls     f1, f31, f0
	  bl        -0x6F888
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1B0
	  addi      r3, r26, 0
	  li        r4, 0
	  bl        -0x18D24
	  b         .loc_0x2E0

	.loc_0x1B0:
	  mr        r4, r30
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x1A0
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0x8(r31)
	  lfs       f2, 0x1A4(r1)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x1A0(r1)
	  fsubs     f3, f3, f2
	  lfs       f2, 0xC(r31)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x1A8(r1)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f27, f2, f0
	  fcmpo     cr0, f27, f30
	  ble-      .loc_0x258
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f27, f0
	  fsub      f0, f28, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f27, f0
	  fsub      f0, f28, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f27, f0
	  fsub      f0, f28, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0xF4(r1)
	  lfs       f27, 0xF4(r1)

	.loc_0x258:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x0(r31)
	  fadds     f0, f0, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x2D4
	  addi      r3, r26, 0
	  li        r4, 0x1
	  bl        -0x18E04
	  lwz       r3, 0x2E4(r30)
	  lwz       r0, 0x28(r3)
	  rlwinm.   r0,r0,0,19,19
	  beq-      .loc_0x2E0
	  stw       r26, 0x708(r30)
	  li        r4, 0x2
	  li        r5, 0
	  lwz       r3, 0x3178(r13)
	  li        r6, 0
	  bl        0x78FB4
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  li        r5, 0xC
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xDB8

	.loc_0x2D4:
	  addi      r3, r26, 0
	  li        r4, 0
	  bl        -0x18E58

	.loc_0x2E0:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x3
	  blt+      .loc_0x148
	  lwz       r3, 0x30AC(r13)
	  bl        -0x1119C
	  mr.       r26, r3
	  beq-      .loc_0x430
	  mr        r3, r26
	  bl        -0x1B144
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x430
	  mr        r4, r26
	  lwz       r12, 0x0(r26)
	  addi      r3, r1, 0x194
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lfs       f26, 0x194(r1)
	  lwz       r12, 0x0(r26)
	  lfs       f27, 0x198(r1)
	  lwz       r12, 0x160(r12)
	  lfs       f28, 0x19C(r1)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x94(r30)
	  fsubs     f4, f27, f1
	  lfs       f1, 0x9C(r30)
	  fsubs     f2, f26, f0
	  lfs       f0, -0x6268(r2)
	  fsubs     f3, f28, f1
	  fmuls     f2, f2, f2
	  fmuls     f1, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x3D4
	  fsqrte    f1, f4
	  lfd       f3, -0x6238(r2)
	  lfd       f2, -0x6230(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0xF0(r1)
	  lfs       f4, 0xF0(r1)

	.loc_0x3D4:
	  lfs       f0, -0x6214(r2)
	  fcmpo     cr0, f4, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x420
	  addi      r3, r26, 0
	  li        r4, 0x1
	  bl        -0x1CE04
	  lwz       r3, 0x2E4(r30)
	  lwz       r0, 0x28(r3)
	  rlwinm.   r0,r0,0,19,19
	  beq-      .loc_0x444
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  li        r5, 0xD
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xDB8

	.loc_0x420:
	  addi      r3, r26, 0
	  li        r4, 0
	  bl        -0x1CE40
	  b         .loc_0x444

	.loc_0x430:
	  cmplwi    r26, 0
	  beq-      .loc_0x444
	  addi      r3, r26, 0
	  li        r4, 0
	  bl        -0x1CE58

	.loc_0x444:
	  mr        r3, r30
	  bl        -0x9848
	  lwz       r0, 0x28C(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x6C0
	  lwz       r3, 0xAD0(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x6C0
	  cmplw     r3, r0
	  beq-      .loc_0x6C0
	  lfs       f0, 0x70(r30)
	  stfs      f0, 0x208(r1)
	  lfs       f0, 0x74(r30)
	  stfs      f0, 0x20C(r1)
	  lfs       f0, 0x78(r30)
	  stfs      f0, 0x210(r1)
	  lfs       f1, 0x208(r1)
	  lfs       f0, 0x20C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x210(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF6348
	  lfs       f0, -0x6268(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x4D8
	  lfs       f0, 0x208(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x208(r1)
	  lfs       f0, 0x20C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x20C(r1)
	  lfs       f0, 0x210(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x210(r1)

	.loc_0x4D8:
	  lwz       r6, 0x28C(r30)
	  li        r0, -0x1
	  lwz       r7, 0xAD0(r30)
	  lfs       f12, 0x208(r1)
	  lfs       f3, 0x28(r6)
	  lfs       f27, 0x20C(r1)
	  lfs       f2, 0x2C(r6)
	  fmuls     f3, f3, f12
	  lfs       f30, 0x210(r1)
	  fmuls     f2, f2, f27
	  lfs       f4, 0x30(r6)
	  lfs       f10, 0x18(r7)
	  lfs       f8, 0x1C(r7)
	  fmuls     f4, f4, f30
	  fadds     f2, f3, f2
	  lfs       f3, 0x1C(r6)
	  lfs       f5, 0x18(r6)
	  fmuls     f9, f10, f12
	  fmuls     f7, f8, f27
	  fadds     f2, f4, f2
	  lfs       f1, -0x6208(r2)
	  fmuls     f4, f10, f5
	  lfs       f11, 0x20(r7)
	  fmuls     f3, f8, f3
	  lfs       f6, 0x20(r6)
	  fmuls     f8, f11, f30
	  fadds     f7, f9, f7
	  lfs       f0, 0x1C(r6)
	  fmuls     f5, f11, f6
	  fadds     f3, f4, f3
	  fcmpo     cr0, f2, f1
	  fadds     f28, f8, f7
	  fadds     f29, f5, f3
	  ble-      .loc_0x564
	  li        r0, 0

	.loc_0x564:
	  lfs       f3, 0x38(r6)
	  lfs       f2, 0x3C(r6)
	  fmuls     f3, f3, f12
	  lfs       f4, 0x40(r6)
	  fmuls     f2, f2, f27
	  fmuls     f4, f4, f30
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x590
	  li        r0, 0x1

	.loc_0x590:
	  lfs       f3, 0x48(r6)
	  lfs       f2, 0x4C(r6)
	  fmuls     f3, f3, f12
	  lfs       f4, 0x50(r6)
	  fmuls     f2, f2, f27
	  fmuls     f4, f4, f30
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x5BC
	  li        r0, 0x2

	.loc_0x5BC:
	  lfs       f2, 0x1C(r7)
	  rlwinm    r3,r0,4,0,27
	  lfs       f1, -0x6204(r2)
	  stfs      f2, 0x144(r1)
	  lwz       r0, 0x144(r1)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x144(r1)
	  lfs       f2, 0x144(r1)
	  fcmpo     cr0, f2, f1
	  cror      2, 0, 0x2
	  bne-      .loc_0x630
	  lwz       r0, 0x28C(r30)
	  addi      r3, r3, 0x28
	  lfs       f3, 0x94(r30)
	  add       r3, r0, r3
	  lfs       f1, 0x98(r30)
	  lfs       f4, 0x0(r3)
	  lfs       f2, 0x4(r3)
	  fmuls     f3, f4, f3
	  lfs       f5, 0x8(r3)
	  fmuls     f2, f2, f1
	  lfs       f4, 0x9C(r30)
	  lfs       f1, 0xC(r3)
	  fmuls     f4, f5, f4
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fsubs     f1, f2, f1
	  stfs      f1, 0xAD8(r30)
	  b         .loc_0x638

	.loc_0x630:
	  lfs       f1, -0x6268(r2)
	  stfs      f1, 0xAD8(r30)

	.loc_0x638:
	  stfs      f0, 0x140(r1)
	  lfs       f1, -0x6200(r2)
	  lwz       r0, 0x140(r1)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x140(r1)
	  lfs       f26, 0x140(r1)
	  bl        0x117A20
	  fcmpo     cr0, f26, f1
	  ble-      .loc_0x6C0
	  lfs       f1, -0x61FC(r2)
	  bl        0x117A10
	  fcmpo     cr0, f28, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x6C0
	  lfs       f1, -0x6200(r2)
	  bl        0x117B90
	  fcmpo     cr0, f29, f1
	  bge-      .loc_0x6C0
	  lfs       f2, -0x29FC(r13)
	  lfs       f1, 0x208(r1)
	  fmuls     f0, f27, f2
	  fmuls     f1, f1, f2
	  fmuls     f2, f30, f2
	  stfs      f1, 0x208(r1)
	  stfs      f0, 0x20C(r1)
	  stfs      f2, 0x210(r1)
	  lfs       f0, -0x61F8(r2)
	  stfs      f0, 0x20C(r1)
	  lwz       r3, 0x208(r1)
	  lwz       r0, 0x20C(r1)
	  stw       r3, 0x70(r30)
	  stw       r0, 0x74(r30)
	  lwz       r0, 0x210(r1)
	  stw       r0, 0x78(r30)

	.loc_0x6C0:
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x66BC
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x83D40
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x718
	  lwz       r0, 0x28C(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x718
	  lwz       r3, 0x2E4(r30)
	  lwz       r0, 0x28(r3)
	  rlwinm.   r0,r0,0,20,20
	  beq-      .loc_0x718
	  lwz       r3, 0x320(r30)
	  addi      r4, r30, 0
	  li        r5, 0x18
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xDB8

	.loc_0x718:
	  lwz       r4, 0x2E4(r30)
	  lwz       r3, 0x2F98(r13)
	  lwz       r4, 0x28(r4)
	  lwz       r0, 0xF4(r3)
	  and.      r0, r4, r0
	  beq-      .loc_0x74C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  li        r5, 0x4
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x74C:
	  lwz       r3, 0x2E4(r30)
	  lwz       r0, 0x28(r3)
	  rlwinm.   r0,r0,0,17,17
	  beq-      .loc_0x798
	  lwz       r3, 0x3068(r13)
	  addi      r4, r30, 0x94
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  beq-      .loc_0x788
	  addi      r3, r30, 0x94
	  bl        -0x3DD10

	.loc_0x788:
	  lwz       r3, 0x28C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x798
	  bl        0x11E30

	.loc_0x798:
	  lwz       r3, 0x2E4(r30)
	  lwz       r4, 0x2F98(r13)
	  lwz       r5, 0x28(r3)
	  lwz       r3, 0x64(r4)
	  and.      r0, r5, r3
	  beq-      .loc_0x828
	  lwz       r0, 0x88(r4)
	  cmpw      r3, r0
	  bne-      .loc_0x7F8
	  mr        r3, r30
	  bl        -0x7AA8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDB8
	  lwz       r0, 0x310(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0xDB8
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  li        r5, 0x3
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xDB8

	.loc_0x7F8:
	  lwz       r0, 0x310(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0xDB8
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  li        r5, 0x3
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xDB8
	  b         .loc_0xDB8

	.loc_0x828:
	  lwz       r6, 0x40(r4)
	  and.      r0, r5, r6
	  beq-      .loc_0xD84
	  lwz       r3, 0x2F80(r13)
	  lwz       r0, 0xF0(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x8A4
	  lwz       r0, 0x88(r4)
	  cmpw      r6, r0
	  bne-      .loc_0x884
	  mr        r3, r30
	  bl        -0x7B3C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xDB8
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  li        r5, 0x2
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xDB8
	  b         .loc_0xDB8

	.loc_0x884:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  li        r5, 0x2
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xDB8

	.loc_0x8A4:
	  lwz       r28, 0x710(r30)
	  li        r31, 0
	  lwz       r4, 0x224(r30)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lfs       f25, 0x1C8(r4)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x97C

	.loc_0x8D0:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x8F4
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x90C

	.loc_0x8F4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x90C:
	  fmr       f1, f25
	  addi      r26, r3, 0
	  addi      r4, r30, 0
	  bl        -0x76B6C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x960
	  addi      r3, r26, 0
	  addi      r4, r30, 0
	  bl        -0x77594
	  fmr       f26, f1
	  fcmpo     cr0, f26, f25
	  bge-      .loc_0x960
	  mr        r3, r26
	  bl        -0x3BED0
	  cmpwi     r3, 0
	  bne-      .loc_0x960
	  lwz       r0, 0x2AC(r26)
	  cmplwi    r0, 0
	  bne-      .loc_0x960
	  mr        r31, r26
	  fmr       f25, f26

	.loc_0x960:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x97C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9A4
	  li        r0, 0x1
	  b         .loc_0x9D0

	.loc_0x9A4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x9CC
	  li        r0, 0x1
	  b         .loc_0x9D0

	.loc_0x9CC:
	  li        r0, 0

	.loc_0x9D0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x8D0
	  cmplwi    r31, 0
	  beq-      .loc_0xADC
	  lfs       f1, 0xA0(r30)
	  bl        0x11768C
	  fmr       f26, f1
	  lfs       f1, 0xA0(r30)
	  bl        0x117814
	  stfs      f1, 0x1D8(r1)
	  mr        r3, r31
	  lfs       f0, -0x29F8(r13)
	  addi      r4, r1, 0x1D8
	  stfs      f0, 0x1DC(r1)
	  stfs      f26, 0x1E0(r1)
	  lfs       f1, -0x625C(r2)
	  bl        -0x3871C
	  lwz       r4, 0xA4(r31)
	  mr        r3, r30
	  lwz       r0, 0xA8(r31)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x1D8(r1)
	  mr        r4, r31
	  li        r5, 0x1B
	  fmuls     f0, f0, f1
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0xDC(r1)
	  stfs      f0, 0x170(r1)
	  lfs       f0, 0x1DC(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x174(r1)
	  lfs       f0, 0x1E0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x178(r1)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x170(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x100(r1)
	  lfs       f0, 0x100(r1)
	  stfs      f0, 0x17C(r1)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x174(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x180(r1)
	  lfs       f1, 0x9C(r30)
	  lfs       f0, 0x178(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x184(r1)
	  lwz       r3, 0x17C(r1)
	  lwz       r0, 0x180(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x184(r1)
	  stw       r0, 0x9C(r31)
	  lwz       r3, 0x490(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xDB8

	.loc_0xADC:
	  lwz       r4, 0x2F98(r13)
	  lwz       r3, 0x40(r4)
	  lwz       r0, 0xAC(r4)
	  cmpw      r3, r0
	  bne-      .loc_0xD84
	  lwz       r27, 0x3160(r13)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f29, -0x6268(r2)
	  mr        r31, r3
	  lfd       f30, -0x6238(r2)
	  lfd       f31, -0x6230(r2)
	  lfs       f28, -0x61F4(r2)
	  b         .loc_0xD28

	.loc_0xB20:
	  cmpwi     r31, -0x1
	  bne-      .loc_0xB48
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0xB64

	.loc_0xB48:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0xB64:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r26, r28
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  fmr       f26, f1
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f1, f26
	  addi      r3, r26, 0
	  addi      r4, r30, 0
	  fadds     f1, f28, f0
	  bl        -0x76DF8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xD0C
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD0C
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD0C
	  lwz       r0, 0xC8(r28)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0xD0C
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD0C
	  lfs       f3, 0x9C(r28)
	  lfs       f2, 0x9C(r30)
	  lfs       f1, 0x94(r28)
	  lfs       f0, 0x94(r30)
	  fsubs     f25, f3, f2
	  lfs       f2, 0x98(r28)
	  fsubs     f27, f1, f0
	  lfs       f0, 0x98(r30)
	  fsubs     f26, f2, f0
	  fmr       f2, f25
	  fmr       f1, f27
	  bl        0x1172D8
	  fmuls     f1, f27, f27
	  fmuls     f0, f26, f26
	  fmuls     f2, f25, f25
	  fadds     f0, f1, f0
	  fadds     f27, f2, f0
	  fcmpo     cr0, f27, f29
	  ble-      .loc_0xCAC
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0xD4(r1)
	  lfs       f27, 0xD4(r1)

	.loc_0xCAC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  fmr       f26, f1
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f1, f26
	  fadds     f0, f28, f0
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xD0C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  li        r5, 0x1C
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xDB8

	.loc_0xD0C:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0xD28:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD50
	  li        r0, 0x1
	  b         .loc_0xD7C

	.loc_0xD50:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xD78
	  li        r0, 0x1
	  b         .loc_0xD7C

	.loc_0xD78:
	  li        r0, 0

	.loc_0xD7C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xB20

	.loc_0xD84:
	  li        r0, 0
	  stw       r0, 0x10(r29)
	  lfs       f1, 0x738(r30)
	  lfs       f0, -0x61F4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xDB8
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  li        r5, 0x11
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xDB8:
	  lmw       r26, 0x238(r1)
	  lwz       r0, 0x28C(r1)
	  lfd       f31, 0x280(r1)
	  lfd       f30, 0x278(r1)
	  lfd       f29, 0x270(r1)
	  lfd       f28, 0x268(r1)
	  lfd       f27, 0x260(r1)
	  lfd       f26, 0x258(r1)
	  lfd       f25, 0x250(r1)
	  addi      r1, r1, 0x288
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801048CC
 * Size:	000024
 */
void NaviWalkState::cleanup(Navi* navi) { navi->finishFixPosition(); }

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

	f32 x            = msg->mWallNormal->x;
	f32 z            = msg->mWallNormal->z;
	navi->mDirection = atan2f(-x, -z);
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
	/*
	.loc_0x0:
	  lwz       r0, 0x4(r5)
	  stw       r0, 0x10(r3)
	  blr
	*/
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
	UfoItem* ufo = itemMgr->getUfo();
	if (ufo) {
		ufo->startAccess();
	}

	_10 = 0;
	navi->mOdoMeter.start(0.5f, 8.0f);
	setCorePauseFlag(COREPAUSE_Unk1 | COREPAUSE_Unk2 | COREPAUSE_Unk16);
	Jac_StartPartsFindDemo(0, 1);
	_20 = _21 = 0;
}

/*
 * --INFO--
 * Address:	80104A4C
 * Size:	0000B8
 */
void NaviUfoState::procCollideMsg(Navi* navi, MsgCollide* msg)
{
	if (_10 != 1 && _10 != 2) {
		navi->startMotion(PaniMotionInfo(PIKIANIM_Punch, navi), PaniMotionInfo(PIKIANIM_Punch));
		_10 = 1;
		effectMgr->create(EffectMgr::EFF_Unk0, navi->mPosition, nullptr, nullptr);
	}
}

/*
 * --INFO--
 * Address:	80104B04
 * Size:	000468
 */
void NaviUfoState::exec(Navi* navi)
{
	if (_10 == 0) {
		UfoItem* ufo       = itemMgr->getUfo();
		Vector3f goalPos   = ufo->getGoalPos();
		Vector3f dirToGoal = goalPos - navi->mPosition;
		f32 dist           = dirToGoal.normalise();
		if (dist < 10.0f) {
			if (!_21) {
				_20 = 20;
			}
			_21     = 1;
			f32 rot = angDist(roundAng(-ufo->mDirection), navi->mDirection);
			navi->mVelocity.set(0.0f, 0.0f, 0.0f);
			navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			if (absF(rot) < 0.15707964f) {
				navi->startMotion(PaniMotionInfo(PIKIANIM_Punch, navi), PaniMotionInfo(PIKIANIM_Punch));
				_10 = 1;
				effectMgr->create(EffectMgr::EFF_Unk0, navi->mPosition, nullptr, nullptr);
			} else {
				navi->mDirection = roundAng(navi->mDirection + 0.1f * rot);
				if (--_20 <= 0) {
					navi->startMotion(PaniMotionInfo(PIKIANIM_Punch, navi), PaniMotionInfo(PIKIANIM_Punch));
					_10 = 1;
					effectMgr->create(EffectMgr::EFF_Unk0, navi->mPosition, nullptr, nullptr);
				}
			}

		} else if (!navi->mOdoMeter.moving(navi->mPosition, _14)) {
			navi->startMotion(PaniMotionInfo(PIKIANIM_Punch, navi), PaniMotionInfo(PIKIANIM_Punch));
			_10 = 1;
			effectMgr->create(EffectMgr::EFF_Unk0, navi->mPosition, nullptr, nullptr);
			navi->mVelocity.set(0.0f, 0.0f, 0.0f);
			navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			return;
		} else {
			_14                   = navi->mPosition;
			navi->mVelocity       = dirToGoal * 60.0f;
			navi->mTargetVelocity = dirToGoal * 60.0f;
		}
	}

	if (_10 == 1) {
		navi->mVelocity.set(0.0f, 0.0f, 0.0f);
		navi->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}

	if (_10 == 2 && --_12 == 0) {
		gameflow._1E8->message(0, 25);
		_10 = 3;
	}

	if (_10 == 3 && gameflow._338 == 0) {
		transit(navi, NAVISTATE_Walk);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stfd      f29, 0xD0(r1)
	  stw       r31, 0xCC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xC8(r1)
	  mr        r30, r3
	  stw       r29, 0xC4(r1)
	  stw       r28, 0xC0(r1)
	  lhz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x360
	  lwz       r3, 0x30AC(r13)
	  bl        -0x11F0C
	  addi      r28, r3, 0
	  lwz       r12, 0x0(r28)
	  addi      r4, r28, 0
	  addi      r3, r1, 0xA0
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0xA4(r1)
	  lfs       f0, 0x98(r31)
	  lfs       f2, 0xA0(r1)
	  lfs       f1, 0x94(r31)
	  fsubs     f31, f3, f0
	  lfs       f3, 0xA8(r1)
	  fsubs     f30, f2, f1
	  lfs       f1, 0x9C(r31)
	  fmuls     f0, f31, f31
	  fsubs     f29, f3, f1
	  fmuls     f1, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF6F5C
	  lfs       f0, -0x6268(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xB4
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1
	  fdivs     f29, f29, f1

	.loc_0xB4:
	  lfs       f0, -0x61F4(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x224
	  lbz       r0, 0x21(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0xD4
	  li        r0, 0x14
	  stb       r0, 0x20(r30)

	.loc_0xD4:
	  li        r0, 0x1
	  stb       r0, 0x21(r30)
	  lfs       f0, 0xA0(r28)
	  fneg      f1, f0
	  bl        -0xCC660
	  lfs       f2, 0xA0(r31)
	  bl        -0xCC63C
	  lfs       f0, -0x29F4(r13)
	  fabs      f2, f1
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x29F0(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x29EC(r13)
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x29E8(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x29E4(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x29E0(r13)
	  stfs      f0, 0xAC(r31)
	  lfs       f0, -0x61EC(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x194
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x140
	  addi      r28, r28, 0x2B8

	.loc_0x140:
	  addi      r3, r1, 0x90
	  li        r4, 0x19
	  bl        0x1A30C
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x98
	  li        r4, 0x19
	  bl        0x1A32C
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xA400
	  li        r0, 0x1
	  sth       r0, 0x10(r30)
	  addi      r5, r31, 0x94
	  li        r4, 0
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        0x97EA8
	  b         .loc_0x360

	.loc_0x194:
	  lfs       f0, -0x61E8(r2)
	  lfs       f2, 0xA0(r31)
	  fmuls     f0, f0, f1
	  fadds     f1, f2, f0
	  bl        -0xCC720
	  stfs      f1, 0xA0(r31)
	  lbz       r3, 0x20(r30)
	  subi      r3, r3, 0x1
	  extsb.    r0, r3
	  stb       r3, 0x20(r30)
	  bgt-      .loc_0x360
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x1D0
	  addi      r28, r28, 0x2B8

	.loc_0x1D0:
	  addi      r3, r1, 0x80
	  li        r4, 0x19
	  bl        0x1A27C
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x88
	  li        r4, 0x19
	  bl        0x1A29C
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xA490
	  li        r0, 0x1
	  sth       r0, 0x10(r30)
	  addi      r5, r31, 0x94
	  li        r4, 0
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        0x97E18
	  b         .loc_0x360

	.loc_0x224:
	  addi      r3, r31, 0x2C4
	  addi      r4, r31, 0x94
	  addi      r5, r30, 0x14
	  bl        -0x37508
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2D0
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x24C
	  addi      r28, r28, 0x2B8

	.loc_0x24C:
	  addi      r3, r1, 0x70
	  li        r4, 0x19
	  bl        0x1A200
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x78
	  li        r4, 0x19
	  bl        0x1A220
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xA50C
	  li        r0, 0x1
	  sth       r0, 0x10(r30)
	  addi      r5, r31, 0x94
	  li        r4, 0
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        0x97D9C
	  lfs       f0, -0x29DC(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x29D8(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x29D4(r13)
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x29D0(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x29CC(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x29C8(r13)
	  stfs      f0, 0xAC(r31)
	  b         .loc_0x43C

	.loc_0x2D0:
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x14(r30)
	  stw       r0, 0x18(r30)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x1C(r30)
	  lfs       f0, -0x29C4(r13)
	  fmuls     f2, f30, f0
	  fmuls     f1, f31, f0
	  fmuls     f0, f29, f0
	  stfs      f2, 0x38(r1)
	  lfs       f2, 0x38(r1)
	  stfs      f2, 0x64(r1)
	  stfs      f1, 0x68(r1)
	  stfs      f0, 0x6C(r1)
	  lwz       r3, 0x64(r1)
	  lwz       r0, 0x68(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0x78(r31)
	  lfs       f0, -0x29C0(r13)
	  fmuls     f2, f30, f0
	  fmuls     f1, f31, f0
	  fmuls     f0, f29, f0
	  stfs      f2, 0x2C(r1)
	  lfs       f2, 0x2C(r1)
	  stfs      f2, 0x58(r1)
	  stfs      f1, 0x5C(r1)
	  stfs      f0, 0x60(r1)
	  lwz       r3, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r3, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0xAC(r31)

	.loc_0x360:
	  lhz       r0, 0x10(r30)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x3B4
	  lfs       f0, -0x29BC(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x29B8(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x29B4(r13)
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x29B0(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x29AC(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x29A8(r13)
	  stfs      f0, 0xC4(r31)
	  lfs       f0, -0x29A4(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x29A0(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x299C(r13)
	  stfs      f0, 0xAC(r31)

	.loc_0x3B4:
	  lhz       r0, 0x10(r30)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x400
	  lhz       r3, 0x12(r30)
	  subi      r3, r3, 0x1
	  rlwinm.   r0,r3,0,16,31
	  sth       r3, 0x12(r30)
	  bne-      .loc_0x400
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0
	  li        r5, 0x19
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x3
	  sth       r0, 0x10(r30)

	.loc_0x400:
	  lhz       r0, 0x10(r30)
	  cmplwi    r0, 0x3
	  bne-      .loc_0x43C
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x338(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x43C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x43C:
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lfd       f29, 0xD0(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  lwz       r29, 0xC4(r1)
	  lwz       r28, 0xC0(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
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

	clearCorePauseFlag();
	Jac_FinishPartsFindDemo();
}

/*
 * --INFO--
 * Address:	80104FB4
 * Size:	000030
 */
void NaviUfoState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	if (msg->mKeyEvent->mEventType == KEY_Finished && _10 == 1) {
		_10 = 2;
		_12 = 10;
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
	navi->_70C = 1;
	rumbleMgr->stop();
	int pikisInParty = 0;

	Iterator iter(navi->mPlateMgr);
	CI_LOOP(iter)
	{
		Piki* piki = (Piki*)*iter;
		if (piki->mColor == navi->mGoalItem->_428) {
			pikisInParty++;
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x60(r1)
	  stmw      r26, 0x48(r1)
	  addi      r29, r4, 0
	  mr        r28, r3
	  stb       r0, 0x70C(r4)
	  lwz       r6, 0x708(r4)
	  lwz       r3, 0x3178(r13)
	  lwz       r5, 0x434(r6)
	  lwz       r0, 0x430(r6)
	  lwz       r4, 0x42C(r6)
	  add       r0, r0, r5
	  lwz       r5, 0x414(r6)
	  add       r0, r4, r0
	  sub       r31, r0, r5
	  bl        0x77E20
	  lwz       r27, 0x710(r29)
	  li        r30, 0
	  addi      r3, r27, 0
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3
	  b         .loc_0xDC

	.loc_0x6C:
	  cmpwi     r26, -0x1
	  bne-      .loc_0x90
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xA8

	.loc_0x90:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xA8:
	  lwz       r4, 0x708(r29)
	  lhz       r3, 0x510(r3)
	  lhz       r0, 0x428(r4)
	  cmplw     r3, r0
	  bne-      .loc_0xC0
	  addi      r30, r30, 0x1

	.loc_0xC0:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0xDC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x104
	  li        r0, 0x1
	  b         .loc_0x130

	.loc_0x104:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x12C
	  li        r0, 0x1
	  b         .loc_0x130

	.loc_0x12C:
	  li        r0, 0

	.loc_0x130:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x6C
	  li        r26, 0
	  li        r27, 0

	.loc_0x140:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r27
	  bl        -0x12820
	  cmplwi    r3, 0
	  beq-      .loc_0x15C
	  lwz       r0, 0x414(r3)
	  add       r26, r26, r0

	.loc_0x15C:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x3
	  blt+      .loc_0x140
	  bl        0xD368
	  lis       r3, 0x803A
	  subi      r27, r3, 0x2848
	  lwz       r3, 0x1E8(r27)
	  li        r4, 0x3
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x803D
	  lwz       r5, 0x2F80(r13)
	  addi      r6, r3, 0x1EC4
	  lwz       r4, 0x708(r29)
	  lwz       r3, 0x8(r6)
	  addi      r7, r5, 0x120
	  lwz       r0, 0x4(r6)
	  mr        r5, r31
	  lwz       r8, 0x0(r7)
	  lwz       r6, 0x0(r6)
	  add       r0, r0, r3
	  lwz       r3, 0x30DC(r13)
	  addi      r7, r30, 0
	  add       r0, r6, r0
	  lhz       r4, 0x428(r4)
	  addi      r10, r8, 0
	  add       r9, r26, r0
	  li        r6, 0x2710
	  bl        0xB836C
	  li        r0, 0x1
	  stw       r0, 0x33C(r27)
	  li        r0, 0
	  stw       r0, 0x18(r28)
	  stw       r0, 0x1C(r28)
	  lwz       r0, 0x64(r1)
	  lmw       r26, 0x48(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
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

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  addi      r4, r1, 0x10
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r3, 0x30DC(r13)
	  bl        0xB9548
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0x4
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x10(r1)
	  cmpwi     r5, 0
	  ble-      .loc_0x70
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0xE8
	  b         .loc_0x84

	.loc_0x70:
	  bge-      .loc_0x84
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  neg       r5, r5
	  bl        0x250

	.loc_0x84:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xA0:
	  lfs       f0, -0x2998(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x2994(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x2990(r13)
	  stfs      f0, 0xAC(r31)
	  lfs       f0, -0x298C(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x2988(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x2984(r13)
	  stfs      f0, 0x78(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0xE8:
	*/
}

/*
 * --INFO--
 * Address:	801053C4
 * Size:	0001E8
 */
void NaviContainerState::enterPikis(Navi* navi, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x370(r1)
	  stmw      r25, 0x354(r1)
	  mr        r27, r4
	  addi      r28, r5, 0
	  li        r29, 0
	  lwz       r31, 0x710(r4)
	  lwz       r12, 0x0(r31)
	  addi      r3, r31, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r3, 0
	  addi      r26, r1, 0x2C
	  b         .loc_0xF4

	.loc_0x40:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x64
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x7C

	.loc_0x64:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x7C:
	  mr        r25, r3
	  bl        -0x3CEF0
	  cmpwi     r3, 0x1E
	  beq-      .loc_0xD8
	  cmpwi     r3, 0x2
	  beq-      .loc_0xD8
	  cmpwi     r3, 0x18
	  beq-      .loc_0xD8
	  subi      r0, r3, 0x6
	  cmplwi    r0, 0x1
	  ble-      .loc_0xD8
	  cmpwi     r3, 0x1C
	  beq-      .loc_0xD8
	  lwz       r3, 0x708(r27)
	  lhz       r4, 0x510(r25)
	  lhz       r0, 0x428(r3)
	  cmplw     r4, r0
	  bne-      .loc_0xD8
	  rlwinm    r0,r29,2,0,29
	  addi      r29, r29, 0x1
	  stwx      r25, r26, r0
	  cmpw      r29, r28
	  beq-      .loc_0x150

	.loc_0xD8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xF4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x11C
	  li        r0, 0x1
	  b         .loc_0x148

	.loc_0x11C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x144
	  li        r0, 0x1
	  b         .loc_0x148

	.loc_0x144:
	  li        r0, 0

	.loc_0x148:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x40

	.loc_0x150:
	  li        r25, 0
	  rlwinm    r0,r25,2,0,29
	  addi      r26, r1, 0x2C
	  add       r26, r26, r0
	  b         .loc_0x1CC

	.loc_0x164:
	  lwz       r3, 0x0(r26)
	  bl        -0x3CFD8
	  cmpwi     r3, 0x1A
	  beq-      .loc_0x17C
	  cmpwi     r3, 0x3
	  bne-      .loc_0x198

	.loc_0x17C:
	  lwz       r4, 0x0(r26)
	  li        r5, 0
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x198:
	  lwz       r4, 0x0(r26)
	  li        r5, 0
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r26)
	  li        r4, 0xB
	  li        r5, 0
	  bl        -0x383B8
	  addi      r26, r26, 0x4
	  addi      r25, r25, 0x1

	.loc_0x1CC:
	  cmpw      r25, r29
	  blt+      .loc_0x164
	  lmw       r25, 0x354(r1)
	  lwz       r0, 0x374(r1)
	  addi      r1, r1, 0x370
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801055AC
 * Size:	000028
 */
void NaviContainerState::exitPikis(Navi* navi, int p2) { navi->mGoalItem->exitPikis(p2); }

/*
 * --INFO--
 * Address:	801055D4
 * Size:	000038
 */
void NaviContainerState::cleanup(Navi* navi)
{
	gameflow._33C = 0;
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
void NaviPickState::procAnimMsg(Navi* navi, MsgAnim*) { }

/*
 * --INFO--
 * Address:	80105654
 * Size:	000070
 */
void NaviPickState::init(Navi* navi)
{
	navi->startMotion(PaniMotionInfo(PIKIANIM_Pick), PaniMotionInfo(PIKIANIM_Run));
	navi->mNaviAnimMgr.getLowerAnimator().mAnimationCounter = 11.0f;
	navi->mNaviAnimMgr.getUpperAnimator().mAnimationCounter = 11.0f;
	navi->enableMotionBlend();
}

/*
 * --INFO--
 * Address:	801056C4
 * Size:	00004C
 */
void NaviPickState::exec(Navi* navi)
{
	if (!navi->mStickTarget || navi->mKontroller->isPressed(KBBTN_B)) {
		transit(navi, NAVISTATE_Walk);
	}
}

/*
 * --INFO--
 * Address:	80105710
 * Size:	000024
 */
void NaviPickState::cleanup(Navi* navi) { navi->endStickObject(); }

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
void NaviRopeState::init(Navi* navi) { navi->startMotion(PaniMotionInfo(PIKIANIM_HNoboru, navi), PaniMotionInfo(PIKIANIM_HNoboru)); }

/*
 * --INFO--
 * Address:	801057EC
 * Size:	00025C
 */
void NaviRopeState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x148(r1)
	  stfd      f31, 0x140(r1)
	  stfd      f30, 0x138(r1)
	  stfd      f29, 0x130(r1)
	  stfd      f28, 0x128(r1)
	  stfd      f27, 0x120(r1)
	  stfd      f26, 0x118(r1)
	  stfd      f25, 0x110(r1)
	  stfd      f24, 0x108(r1)
	  stw       r31, 0x104(r1)
	  mr        r31, r4
	  stw       r30, 0x100(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x158(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x68
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0xB
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x224

	.loc_0x68:
	  lwz       r3, 0x2E4(r31)
	  bl        -0xC4D84
	  fneg      f30, f1
	  lwz       r3, 0x2E4(r31)
	  bl        -0xC4DC8
	  lwz       r3, 0x158(r31)
	  fmr       f31, f1
	  lfsu      f29, 0x2C4(r3)
	  lfs       f1, 0xA0(r31)
	  lfs       f28, 0x4(r3)
	  lfs       f27, 0x8(r3)
	  bl        0x1162D4
	  fmr       f24, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x11645C
	  lfs       f6, -0x2980(r13)
	  fmuls     f4, f24, f28
	  fmuls     f2, f24, f29
	  fmuls     f5, f6, f27
	  fmuls     f0, f1, f27
	  fmuls     f3, f1, f28
	  fsubs     f26, f5, f4
	  fsubs     f25, f2, f0
	  fmuls     f2, f6, f29
	  fmuls     f1, f26, f26
	  fmuls     f0, f25, f25
	  fsubs     f24, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f24, f24
	  fadds     f1, f1, f0
	  bl        -0xF7C8C
	  lfs       f0, -0x6268(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xFC
	  fdivs     f26, f26, f1
	  fdivs     f25, f25, f1
	  fdivs     f24, f24, f1

	.loc_0xFC:
	  lfs       f0, -0x6218(r2)
	  lwz       r3, 0x2DEC(r13)
	  fmuls     f1, f0, f31
	  lfs       f0, -0x61E0(r2)
	  lfs       f3, 0x28C(r3)
	  lfs       f2, 0xA0(r31)
	  fmuls     f1, f1, f3
	  fdivs     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xCD384
	  stfs      f1, 0xA0(r31)
	  fabs      f1, f30
	  lfs       f0, -0x61E8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x148
	  lfs       f0, -0x61DC(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x6BC(r31)
	  b         .loc_0x150

	.loc_0x148:
	  lfs       f0, -0x6268(r2)
	  stfs      f0, 0x6BC(r31)

	.loc_0x150:
	  lfs       f0, -0x621C(r2)
	  fmuls     f0, f0, f31
	  fmuls     f2, f26, f0
	  fmuls     f1, f25, f0
	  fmuls     f0, f24, f0
	  stfs      f2, 0x7C(r1)
	  lfs       f2, 0x7C(r1)
	  stfs      f2, 0xA8(r1)
	  stfs      f1, 0xAC(r1)
	  stfs      f0, 0xB0(r1)
	  lfs       f0, -0x61D8(r2)
	  fmuls     f0, f0, f30
	  fmuls     f2, f29, f0
	  fmuls     f1, f28, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0x88(r1)
	  lfs       f2, 0x88(r1)
	  stfs      f2, 0xB4(r1)
	  stfs      f1, 0xB8(r1)
	  stfs      f0, 0xBC(r1)
	  lfs       f1, 0xB4(r1)
	  lfs       f0, 0xA8(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x70(r1)
	  stfs      f0, 0xC0(r1)
	  lfs       f1, 0xB8(r1)
	  lfs       f0, 0xAC(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC4(r1)
	  lfs       f1, 0xBC(r1)
	  lfs       f0, 0xB0(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC8(r1)
	  lwz       r3, 0xC0(r1)
	  lwz       r0, 0xC4(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xC8(r1)
	  stw       r0, 0x78(r31)
	  lwz       r3, 0x2E4(r31)
	  lwz       r3, 0x28(r3)
	  rlwinm.   r0,r3,0,18,18
	  bne-      .loc_0x208
	  rlwinm.   r0,r3,0,15,15
	  beq-      .loc_0x224

	.loc_0x208:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0xB
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x224:
	  lwz       r0, 0x14C(r1)
	  lfd       f31, 0x140(r1)
	  lfd       f30, 0x138(r1)
	  lfd       f29, 0x130(r1)
	  lfd       f28, 0x128(r1)
	  lfd       f27, 0x120(r1)
	  lfd       f26, 0x118(r1)
	  lfd       f25, 0x110(r1)
	  lfd       f24, 0x108(r1)
	  lwz       r31, 0x104(r1)
	  lwz       r30, 0x100(r1)
	  addi      r1, r1, 0x148
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80105A48
 * Size:	000004
 */
void NaviRopeState::cleanup(Navi* navi) { }

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
	u32 badCompiler;
	navi->endRope();
	navi->startMotion(PaniMotionInfo(PIKIANIM_Jump, navi), PaniMotionInfo(PIKIANIM_Jump));
	f32 angle = navi->mDirection;
	navi->mVelocity.set(50.0f * sinf(angle), 200.0f, 50.0f * cosf(angle));
	navi->mTargetVelocity = navi->mVelocity;
}

/*
 * --INFO--
 * Address:	80105B6C
 * Size:	000004
 */
void NaviRopeExitState::exec(Navi* navi) { }

/*
 * --INFO--
 * Address:	80105B70
 * Size:	000004
 */
void NaviRopeExitState::cleanup(Navi* navi) { }

/*
 * --INFO--
 * Address:	80105B74
 * Size:	000030
 */
void NaviRopeExitState::procBounceMsg(Navi* navi, MsgBounce*) { transit(navi, NAVISTATE_Walk); }

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
	navi->_ACC = 1;
}

/*
 * --INFO--
 * Address:	80105C7C
 * Size:	00001C
 */
void NaviFunbariState::exec(Navi* navi) { navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f); }

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
void NaviFunbariState::cleanup(Navi* navi) { }

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
	if ((!mStopBeingIdle && navi->_738 < 1.0f) || navi->mKontroller->isCurrentInput(KBBTN_A) || navi->mKontroller->isCurrentInput(KBBTN_B)
	    || navi->mKontroller->isCurrentInput(KBBTN_X) || navi->mKontroller->isCurrentInput(KBBTN_L)
	    || navi->mKontroller->isCurrentInput(KBBTN_R) || navi->mKontroller->isCurrentInput(KBBTN_MSTICK_LEFT)
	    || navi->mKontroller->isCurrentInput(KBBTN_MSTICK_RIGHT) || navi->mKontroller->isCurrentInput(KBBTN_MSTICK_UP)
	    || navi->mKontroller->isCurrentInput(KBBTN_MSTICK_DOWN) || navi->mKontroller->isCurrentInput(KBBTN_CSTICK_LEFT)
	    || navi->mKontroller->isCurrentInput(KBBTN_CSTICK_RIGHT) || navi->mKontroller->isCurrentInput(KBBTN_CSTICK_UP)
	    || navi->mKontroller->isCurrentInput(KBBTN_CSTICK_DOWN)) {
		navi->mNaviAnimMgr.finishMotion(navi);
		navi->enableMotionBlend();
		mStopBeingIdle = true;
		return;
	}

	if (!playerState->isTutorial() && navi->_738 > 140.0f) {
		navi->_738 = 1.0f;
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
void NaviIdleState::cleanup(Navi* navi) { navi->_738 = 0.0f; }

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
	_10               = 0;
	_18               = navi->mDirection;
	_1C               = 0.1f * randFloat(PI);
	navi->mVelocity.y = 0.0f;
	_20               = navi->_704 + 0.1f * navi->_704 * randFloat();
	navi->startMotion(PaniMotionInfo(PIKIANIM_JHit, navi), PaniMotionInfo(PIKIANIM_JHit));
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  mr        r29, r4
	  stw       r28, 0x38(r1)
	  addi      r28, r3, 0
	  sth       r0, 0x10(r3)
	  lfs       f0, 0xA0(r4)
	  stfs      f0, 0x18(r3)
	  bl        0x11205C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6240(r2)
	  stw       r0, 0x34(r1)
	  lis       r31, 0x4330
	  lfs       f3, -0x6258(r2)
	  stw       r31, 0x30(r1)
	  lfs       f2, -0x625C(r2)
	  lfd       f1, 0x30(r1)
	  lfs       f0, -0x6218(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x61E8(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  stfs      f0, 0x1C(r28)
	  lfs       f0, -0x6268(r2)
	  stfs      f0, 0x74(r29)
	  bl        0x112010
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x6240(r2)
	  stw       r0, 0x2C(r1)
	  cmplwi    r29, 0
	  lfs       f2, -0x6258(r2)
	  mr        r30, r29
	  stw       r31, 0x28(r1)
	  lfs       f1, -0x625C(r2)
	  lfd       f0, 0x28(r1)
	  lfs       f4, 0x704(r29)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x61E8(r2)
	  fmuls     f0, f0, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fadds     f0, f4, f0
	  stfs      f0, 0x20(r28)
	  beq-      .loc_0xD4
	  addi      r30, r30, 0x2B8

	.loc_0xD4:
	  addi      r3, r1, 0x18
	  li        r4, 0x1F
	  bl        0x18E9C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x20
	  li        r4, 0x1F
	  bl        0x18EBC
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xB870
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80106104
 * Size:	000178
 */
void NaviFlickState::exec(Navi* navi)
{
	if (_10 == 0) {
		f32 speed         = _20;
		navi->mVelocity.x = -speed * sinf(_18);
		navi->mVelocity.z = -speed * cosf(_18);
		navi->mDirection  = roundAng(navi->mDirection + _1C);
		return;
	}

	if (_10 == 2) {
		mGetupAnimationTimer -= gsys->getFrameTime();
		if (mGetupAnimationTimer < 0.0f) {
			navi->startMotion(PaniMotionInfo(PIKIANIM_GetUp, navi), PaniMotionInfo(PIKIANIM_GetUp));
			_10 = 3;
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
		if (_10 == 0) {
			navi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_JKoke, navi), PaniMotionInfo(PIKIANIM_JKoke));
			_10 = 1;
			break;
		}
		if (_10 == 1) {
			_10                  = 2;
			mGetupAnimationTimer = randFloat(0.1f);
			break;
		}
		if (navi->mHealth <= 0.0f) {
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
	_10 = 1; // why
	_18 = navi->mDirection;
	_1C = 0.1f * randFloat(PI);
	navi->startMotion(PaniMotionInfo(PIKIANIM_JHit, navi), PaniMotionInfo(PIKIANIM_JHit));
	_30 = 0;
	navi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_OCarry, navi), PaniMotionInfo(PIKIANIM_OCarry));

	_10 = 2; // does this
	_2C = 69.0f + navi->mPosition.y;

	_10 = 0; // get set like this
}

/*
 * --INFO--
 * Address:	80106594
 * Size:	000214
 */
void NaviGeyzerState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x68(r1)
	  mr        r30, r3
	  stw       r29, 0x64(r1)
	  stw       r28, 0x60(r1)
	  lhz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x9C
	  lfs       f0, -0x2954(r13)
	  lfs       f1, -0x2950(r13)
	  stfs      f0, 0x50(r1)
	  lfs       f0, -0x294C(r13)
	  stfs      f1, 0x54(r1)
	  stfs      f0, 0x58(r1)
	  lwz       r3, 0x50(r1)
	  lwz       r0, 0x54(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x58(r1)
	  stw       r0, 0x78(r31)
	  lwz       r3, 0x50(r1)
	  lwz       r0, 0x54(r1)
	  stw       r3, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x58(r1)
	  stw       r0, 0xAC(r31)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0x2C(r30)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1F4
	  li        r0, 0x2
	  sth       r0, 0x10(r30)
	  b         .loc_0x9C
	  b         .loc_0x1F4

	.loc_0x9C:
	  lbz       r0, 0x30(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x128
	  li        r0, 0x1
	  stb       r0, 0x30(r30)
	  addi      r6, r1, 0x2C
	  addi      r3, r1, 0x38
	  lfs       f0, -0x2948(r13)
	  addi      r4, r31, 0x94
	  lfs       f1, -0x2944(r13)
	  addi      r5, r30, 0x20
	  stfs      f0, 0x2C(r1)
	  lfs       f0, -0x2940(r13)
	  stfs      f1, 0x30(r1)
	  lfs       f1, -0x61C4(r2)
	  stfs      f0, 0x34(r1)
	  bl        0xC674
	  lfs       f0, 0x38(r1)
	  lfs       f1, 0x3C(r1)
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x40(r1)
	  stfs      f1, 0x48(r1)
	  stfs      f0, 0x4C(r1)
	  lwz       r3, 0x44(r1)
	  lwz       r0, 0x48(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x4C(r1)
	  stw       r0, 0x78(r31)
	  lwz       r3, 0x44(r1)
	  lwz       r0, 0x48(r1)
	  stw       r3, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x4C(r1)
	  stw       r0, 0xAC(r31)

	.loc_0x128:
	  lhz       r0, 0x10(r30)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x14C
	  lfs       f1, 0xA0(r31)
	  lfs       f0, 0x1C(r30)
	  fadds     f1, f1, f0
	  bl        -0xCE14C
	  stfs      f1, 0xA0(r31)
	  b         .loc_0x1F4

	.loc_0x14C:
	  cmplwi    r0, 0x3
	  bne-      .loc_0x1F4
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x14(r30)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lfs       f1, 0x14(r30)
	  lfs       f0, -0x6268(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1C0
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x188
	  addi      r28, r28, 0x2B8

	.loc_0x188:
	  addi      r3, r1, 0x1C
	  li        r4, 0x20
	  bl        0x18834
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x24
	  li        r4, 0x20
	  bl        0x18854
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xBED8
	  li        r0, 0x4
	  sth       r0, 0x10(r30)

	.loc_0x1C0:
	  lfs       f1, -0x61CC(r2)
	  lfs       f0, 0x70(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x70(r31)
	  lfs       f0, 0x78(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x293C(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x2938(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x2934(r13)
	  stfs      f0, 0xAC(r31)

	.loc_0x1F4:
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  lwz       r28, 0x60(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
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
		if (_10 == 1) {
			navi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_JKoke, navi), PaniMotionInfo(PIKIANIM_JKoke));
			_10 = 2;
			break;
		}

		if (_10 == 2) {
			navi->mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_JKoke, navi), PaniMotionInfo(PIKIANIM_JKoke));
			break;
		}

		if (_10 == 4) {
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
	if (_10 != 0) {
		_10 = 3;
		_14 = 0.3f + randFloat(0.2f);
		rumbleMgr->start(10, 0, nullptr);
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
void NaviGatherState::resume(Navi* navi) { cleanup(navi); }

/*
 * --INFO--
 * Address:	80106A00
 * Size:	000030
 */
void NaviGatherState::restart(Navi* navi) { transit(navi, NAVISTATE_Walk); }

/*
 * --INFO--
 * Address:	80106A30
 * Size:	000138
 */
void NaviGatherState::init(Navi* navi)
{
	navi->_6BC = 30.0f;
	navi->startMotion(PaniMotionInfo(PIKIANIM_Fue, navi), PaniMotionInfo(PIKIANIM_Fue));
	navi->enableMotionBlend();
	navi->_AB8 = 0.0f;
	navi->_AC4 = 0.0f;
	navi->_ABC = 1;
	_10        = 0;
	SeSystem::playPlayerSe(0x13B);

	int effIDMaybe = (navi->mNaviID == 0) ? 1 : 2;
	EffectParm parm;
	parm.mPosition = navi->mPosition;
	parm._24       = 1.0f;
	UtEffectMgr::cast(effIDMaybe, parm);
	UtEffectMgr::cast(7, parm);
	_18 = 0;
	rumbleMgr->start(3, 0, nullptr);
}

/*
 * --INFO--
 * Address:	80106B68
 * Size:	0005EC
 */
void NaviGatherState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1B8(r1)
	  stfd      f31, 0x1B0(r1)
	  stfd      f30, 0x1A8(r1)
	  stfd      f29, 0x1A0(r1)
	  stfd      f28, 0x198(r1)
	  stfd      f27, 0x190(r1)
	  stmw      r24, 0x170(r1)
	  addi      r27, r4, 0
	  addi      r26, r3, 0
	  addi      r3, r27, 0
	  bl        -0x84380
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x5C4
	  lwz       r30, 0x30AC(r13)
	  li        r28, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f29, -0x6268(r2)
	  mr        r29, r3
	  lfd       f30, -0x6238(r2)
	  lis       r31, 0x636F
	  lfd       f31, -0x6230(r2)
	  lfs       f28, -0x620C(r2)
	  b         .loc_0x230

	.loc_0x74:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x9C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3
	  b         .loc_0xB8

	.loc_0x9C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3

	.loc_0xB8:
	  lwz       r0, 0x6C(r24)
	  cmpwi     r0, 0x10
	  bne-      .loc_0x214
	  lwz       r3, 0x220(r24)
	  addi      r4, r31, 0x6E74
	  bl        -0x7D524
	  addi      r25, r3, 0
	  addi      r3, r27, 0
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x0(r25)
	  addi      r3, r27, 0x40
	  addi      r4, r24, 0x40
	  fadds     f0, f0, f1
	  fmuls     f1, f28, f0
	  bl        -0x72874
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x214
	  mr        r4, r27
	  lwz       r12, 0x0(r27)
	  addi      r3, r1, 0x130
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0x8(r25)
	  lfs       f2, 0x134(r1)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x130(r1)
	  fsubs     f3, f3, f2
	  lfs       f2, 0xC(r25)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x138(r1)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f27, f2, f0
	  fcmpo     cr0, f27, f29
	  ble-      .loc_0x1B0
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0xB4(r1)
	  lfs       f27, 0xB4(r1)

	.loc_0x1B0:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x0(r25)
	  fadds     f0, f0, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x214
	  lwz       r4, 0x2E4(r27)
	  lwz       r3, 0x2F98(r13)
	  lwz       r4, 0x28(r4)
	  lwz       r0, 0x64(r3)
	  and.      r0, r4, r0
	  beq-      .loc_0x214
	  stw       r24, 0x708(r27)
	  addi      r3, r26, 0
	  addi      r4, r27, 0
	  lwz       r12, 0x0(r26)
	  li        r5, 0xC
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5C4

	.loc_0x214:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x230:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x258
	  li        r0, 0x1
	  b         .loc_0x284

	.loc_0x258:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x280
	  li        r0, 0x1
	  b         .loc_0x284

	.loc_0x280:
	  li        r0, 0

	.loc_0x284:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x74
	  lwz       r6, 0x2E4(r27)
	  mr        r3, r27
	  lwz       r5, 0x2F98(r13)
	  li        r4, 0
	  lwz       r6, 0x20(r6)
	  lwz       r0, 0x64(r5)
	  and       r0, r6, r0
	  neg       r6, r0
	  subic     r5, r6, 0x1
	  cntlzw    r0, r6
	  subfe     r31, r5, r6
	  rlwinm    r24,r0,27,5,31
	  bl        -0x9334
	  lhz       r5, 0x10(r26)
	  cmplwi    r5, 0
	  beq-      .loc_0x5C4
	  lwz       r4, 0x2E4(r27)
	  lwz       r3, 0x2F98(r13)
	  lwz       r4, 0x28(r4)
	  lwz       r0, 0x64(r3)
	  and.      r0, r4, r0
	  beq-      .loc_0x314
	  lfs       f0, -0x6268(r2)
	  li        r0, 0
	  addi      r3, r26, 0
	  stfs      f0, 0xAB8(r27)
	  addi      r4, r27, 0
	  li        r5, 0x3
	  stw       r0, 0xABC(r27)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5C4

	.loc_0x314:
	  cmplwi    r5, 0x2
	  bne-      .loc_0x33C
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  addi      r4, r27, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5C4

	.loc_0x33C:
	  lwz       r3, 0xABC(r27)
	  cmpwi     r3, 0x1
	  bne-      .loc_0x3DC
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x3DC
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xAB8(r27)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xAB8(r27)
	  lwz       r3, 0x224(r27)
	  lfs       f1, 0xAB8(r27)
	  lfs       f0, 0xB8(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x5C4
	  lis       r3, 0x803A
	  stfs      f0, 0xAB8(r27)
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x33C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x3A4
	  lwz       r4, 0x224(r27)
	  mr        r3, r27
	  lfs       f1, 0x98(r4)
	  bl        -0xBB28
	  b         .loc_0x3B4

	.loc_0x3A4:
	  lwz       r4, 0x224(r27)
	  mr        r3, r27
	  lfs       f1, 0x98(r4)
	  bl        -0xB378

	.loc_0x3B4:
	  lwz       r3, 0x224(r27)
	  li        r0, 0x2
	  lfs       f1, 0xAB8(r27)
	  lfs       f0, 0xB8(r3)
	  fdivs     f0, f1, f0
	  stfs      f0, 0xAC0(r27)
	  lfs       f0, -0x6268(r2)
	  stfs      f0, 0xAB8(r27)
	  stw       r0, 0xABC(r27)
	  b         .loc_0x5C4

	.loc_0x3DC:
	  cmpwi     r3, 0x1
	  bne-      .loc_0x458
	  rlwinm.   r0,r24,0,24,31
	  beq-      .loc_0x458
	  lwz       r4, 0x224(r27)
	  lis       r3, 0x803A
	  lfs       f1, 0xAB8(r27)
	  li        r0, 0x2
	  lfs       f0, 0xB8(r4)
	  subi      r3, r3, 0x2848
	  fdivs     f1, f1, f0
	  stfs      f1, 0xAC0(r27)
	  lwz       r4, 0x224(r27)
	  lfs       f0, -0x6268(r2)
	  lfs       f2, 0x98(r4)
	  lfs       f3, 0xA8(r4)
	  fsubs     f2, f2, f3
	  stfs      f0, 0xAB8(r27)
	  stw       r0, 0xABC(r27)
	  fmuls     f1, f1, f2
	  fadds     f1, f1, f3
	  stfs      f1, 0x14(r26)
	  lwz       r0, 0x33C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x44C
	  mr        r3, r27
	  bl        -0xBBD0
	  b         .loc_0x5C4

	.loc_0x44C:
	  mr        r3, r27
	  bl        -0xB418
	  b         .loc_0x5C4

	.loc_0x458:
	  cmpwi     r3, 0x2
	  bne-      .loc_0x5C4
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x33C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x484
	  mr        r3, r27
	  lfs       f1, 0x14(r26)
	  bl        -0xBC08
	  b         .loc_0x490

	.loc_0x484:
	  mr        r3, r27
	  lfs       f1, 0x14(r26)
	  bl        -0xB454

	.loc_0x490:
	  lwz       r4, 0x2E4(r27)
	  lwz       r3, 0x2F98(r13)
	  lwz       r4, 0x28(r4)
	  lwz       r0, 0x64(r3)
	  and.      r0, r4, r0
	  beq-      .loc_0x4D8
	  lfs       f0, -0x6268(r2)
	  li        r0, 0
	  addi      r3, r26, 0
	  stfs      f0, 0xAB8(r27)
	  addi      r4, r27, 0
	  li        r5, 0x3
	  stw       r0, 0xABC(r27)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5C4

	.loc_0x4D8:
	  lwz       r3, 0x2DEC(r13)
	  rlwinm.   r0,r31,0,24,31
	  lfs       f1, 0xAB8(r27)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xAB8(r27)
	  bne-      .loc_0x4F8
	  li        r28, 0x1

	.loc_0x4F8:
	  lbz       r0, 0x18(r26)
	  cmplwi    r0, 0
	  bne-      .loc_0x550
	  lwz       r3, 0x224(r27)
	  lfs       f0, -0x6254(r2)
	  lfs       f1, 0xC8(r3)
	  lfs       f2, 0xAB8(r27)
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x550
	  li        r3, 0x13B
	  bl        -0x61C7C
	  li        r3, 0x1
	  stb       r3, 0x18(r26)
	  lwz       r0, 0x92C(r27)
	  cmpwi     r0, 0
	  bne-      .loc_0x540
	  b         .loc_0x544

	.loc_0x540:
	  li        r3, 0x2

	.loc_0x544:
	  bl        0xD278
	  li        r3, 0x7
	  bl        0xD270

	.loc_0x550:
	  rlwinm.   r0,r28,0,24,31
	  bne-      .loc_0x56C
	  lwz       r3, 0x224(r27)
	  lfs       f1, 0xAB8(r27)
	  lfs       f0, 0xC8(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x5C4

	.loc_0x56C:
	  lfs       f0, -0x6268(r2)
	  cmplwi    r27, 0
	  li        r0, 0
	  stfs      f0, 0xAB8(r27)
	  mr        r5, r27
	  stw       r0, 0xABC(r27)
	  beq-      .loc_0x58C
	  addi      r5, r5, 0x2B8

	.loc_0x58C:
	  addi      r24, r27, 0x838
	  addi      r3, r1, 0x128
	  li        r4, -0x1
	  bl        0x17E8C
	  addi      r4, r3, 0
	  addi      r3, r24, 0
	  bl        0x18124
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  addi      r4, r27, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x5C4:
	  lmw       r24, 0x170(r1)
	  lwz       r0, 0x1BC(r1)
	  lfd       f31, 0x1B0(r1)
	  lfd       f30, 0x1A8(r1)
	  lfd       f29, 0x1A0(r1)
	  lfd       f28, 0x198(r1)
	  lfd       f27, 0x190(r1)
	  addi      r1, r1, 0x1B8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80107154
 * Size:	000068
 */
void NaviGatherState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x5
	  beq-      .loc_0x30
	  bge-      .loc_0x58
	  cmpwi     r0, 0
	  beq-      .loc_0x3C
	  b         .loc_0x58
	  b         .loc_0x58

	.loc_0x30:
	  li        r0, 0x1
	  sth       r0, 0x10(r3)
	  b         .loc_0x58

	.loc_0x3C:
	  li        r0, 0x2
	  sth       r0, 0x10(r3)
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x58:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801071BC
 * Size:	00006C
 */
void NaviGatherState::cleanup(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  li        r4, 0x3
	  lwz       r3, 0x3178(r13)
	  bl        0x75EDC
	  lwz       r0, 0x92C(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x38
	  li        r0, 0x1
	  b         .loc_0x3C

	.loc_0x38:
	  li        r0, 0x2

	.loc_0x3C:
	  mr        r31, r0
	  li        r3, 0x13B
	  bl        -0x61DF0
	  mr        r3, r31
	  bl        0xD11C
	  li        r3, 0x7
	  bl        0xD114
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r30, r29, 0
	  lfs       f0, -0x61B8(r2)
	  stfs      f0, 0x6BC(r4)
	  beq-      .loc_0x38
	  addi      r30, r30, 0x2B8

	.loc_0x38:
	  addi      r3, r1, 0x10
	  li        r4, 0x31
	  bl        0x17CAC
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x31
	  bl        0x17CCC
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xCA60
	  mr        r3, r29
	  bl        -0xCA30
	  li        r3, 0x13A
	  bl        -0x61F04
	  li        r0, 0
	  stb       r0, 0x10(r28)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010730C
 * Size:	000090
 */
void NaviReleaseState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  bl        -0x84B14
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x78
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x9850
	  lbz       r0, 0x10(r30)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x78
	  lwz       r4, 0x2E4(r31)
	  lwz       r3, 0x2F98(r13)
	  lwz       r4, 0x28(r4)
	  lwz       r0, 0x64(r3)
	  and.      r0, r4, r0
	  beq-      .loc_0x78
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x3
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x78:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010739C
 * Size:	000004
 */
void NaviReleaseState::cleanup(Navi* navi) { }

/*
 * --INFO--
 * Address:	801073A0
 * Size:	000090
 */
void NaviReleaseState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x5
	  beq-      .loc_0x38
	  bge-      .loc_0x7C
	  cmpwi     r0, 0
	  beq-      .loc_0x64
	  b         .loc_0x7C
	  b         .loc_0x7C

	.loc_0x38:
	  li        r0, 0x1
	  cmplwi    r31, 0
	  stb       r0, 0x10(r3)
	  mr        r4, r31
	  beq-      .loc_0x50
	  addi      r4, r4, 0x2B8

	.loc_0x50:
	  addi      r3, r31, 0x834
	  bl        0x186CC
	  mr        r3, r31
	  bl        -0xB4E0
	  b         .loc_0x7C

	.loc_0x64:
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x7C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801074A0
 * Size:	000030
 */
void NaviThrowWaitState::restart(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801074D0
 * Size:	0003CC
 */
void NaviThrowWaitState::init(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x150(r1)
	  stfd      f31, 0x148(r1)
	  stfd      f30, 0x140(r1)
	  stfd      f29, 0x138(r1)
	  stfd      f28, 0x130(r1)
	  stfd      f27, 0x128(r1)
	  stfd      f26, 0x120(r1)
	  stfd      f25, 0x118(r1)
	  stfd      f24, 0x110(r1)
	  stfd      f23, 0x108(r1)
	  stfd      f22, 0x100(r1)
	  stmw      r26, 0xE8(r1)
	  addi      r31, r4, 0
	  addi      r30, r3, 0
	  li        r27, 0
	  lfs       f0, -0x6268(r2)
	  stfs      f0, 0x800(r4)
	  stw       r0, 0x10(r3)
	  stw       r0, 0x14(r3)
	  lwz       r28, 0x710(r4)
	  lfs       f24, -0x6210(r2)
	  lwz       r12, 0x0(r28)
	  mr        r3, r28
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f29, -0x6268(r2)
	  mr        r29, r3
	  lfd       f30, -0x6238(r2)
	  lfd       f31, -0x6230(r2)
	  lfs       f22, -0x61B4(r2)
	  lfs       f23, -0x61F4(r2)
	  b         .loc_0x1FC

	.loc_0x90:
	  cmpwi     r29, -0x1
	  bne-      .loc_0xB4
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xCC

	.loc_0xB4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xCC:
	  fmr       f1, f24
	  addi      r26, r3, 0
	  addi      r4, r31, 0
	  bl        -0x79D18
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1E0
	  lfs       f2, 0x9C(r26)
	  lfs       f0, 0x9C(r31)
	  lfs       f3, 0x98(r26)
	  lfs       f1, 0x98(r31)
	  fsubs     f27, f2, f0
	  lfs       f2, 0x94(r26)
	  lfs       f0, 0x94(r31)
	  fsubs     f26, f3, f1
	  lfs       f1, 0xA0(r31)
	  fsubs     f25, f2, f0
	  bl        0x114578
	  fmr       f28, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x114700
	  fmuls     f3, f25, f25
	  lfs       f0, -0x2930(r13)
	  fmuls     f2, f26, f26
	  fmuls     f4, f27, f27
	  fadds     f2, f3, f2
	  fadds     f4, f4, f2
	  fcmpo     cr0, f4, f29
	  ble-      .loc_0x18C
	  fsqrte    f3, f4
	  fmul      f2, f3, f3
	  fmul      f3, f30, f3
	  fmul      f2, f4, f2
	  fsub      f2, f31, f2
	  fmul      f3, f3, f2
	  fmul      f2, f3, f3
	  fmul      f3, f30, f3
	  fmul      f2, f4, f2
	  fsub      f2, f31, f2
	  fmul      f3, f3, f2
	  fmul      f2, f3, f3
	  fmul      f3, f30, f3
	  fmul      f2, f4, f2
	  fsub      f2, f31, f2
	  fmul      f2, f3, f2
	  fmul      f2, f4, f2
	  frsp      f2, f2
	  stfs      f2, 0x70(r1)
	  lfs       f4, 0x70(r1)

	.loc_0x18C:
	  fmuls     f1, f25, f1
	  fmuls     f0, f26, f0
	  fmuls     f2, f27, f28
	  fmr       f25, f4
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fcmpo     cr0, f0, f22
	  ble-      .loc_0x1B0
	  fadds     f25, f25, f23

	.loc_0x1B0:
	  fcmpo     cr0, f25, f24
	  bge-      .loc_0x1E0
	  mr        r3, r26
	  bl        -0x3F138
	  cmpwi     r3, 0
	  bne-      .loc_0x1E0
	  mr        r3, r26
	  bl        -0x3D27C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1E0
	  mr        r27, r26
	  fmr       f24, f25

	.loc_0x1E0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x1FC:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x224
	  li        r0, 0x1
	  b         .loc_0x250

	.loc_0x224:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x24C
	  li        r0, 0x1
	  b         .loc_0x250

	.loc_0x24C:
	  li        r0, 0

	.loc_0x250:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x90
	  lwz       r3, 0x224(r31)
	  lfs       f0, 0x1C8(r3)
	  fcmpo     cr0, f24, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x274
	  stw       r27, 0x10(r30)
	  b         .loc_0x278

	.loc_0x274:
	  stw       r27, 0x14(r30)

	.loc_0x278:
	  lwz       r0, 0x10(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x2D8
	  lfs       f0, -0x61B8(r2)
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  stfs      f0, 0x6BC(r31)
	  beq-      .loc_0x29C
	  addi      r28, r28, 0x2B8

	.loc_0x29C:
	  addi      r3, r1, 0x98
	  li        r4, 0x24
	  bl        0x177E4
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0xA0
	  li        r4, 0x24
	  bl        0x17804
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xCF28
	  mr        r3, r31
	  bl        -0xCEF8
	  b         .loc_0x2FC

	.loc_0x2D8:
	  lwz       r4, 0x14(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x2FC
	  lwz       r3, 0x490(r4)
	  li        r5, 0xB
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x2FC:
	  li        r0, 0
	  stb       r0, 0x1C(r30)
	  lis       r3, 0x4330
	  stw       r0, 0x18(r30)
	  lwz       r0, 0x18(r30)
	  lwz       r4, 0x224(r31)
	  xoris     r0, r0, 0x8000
	  lfd       f4, -0x6240(r2)
	  stw       r0, 0xE4(r1)
	  lfs       f3, -0x61E0(r2)
	  stw       r3, 0xE0(r1)
	  lfs       f2, 0x178(r4)
	  lfd       f1, 0xE0(r1)
	  lfs       f0, 0x168(r4)
	  fsubs     f1, f1, f4
	  fsubs     f0, f0, f2
	  fdivs     f1, f1, f3
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x804(r31)
	  lwz       r0, 0x18(r30)
	  lwz       r4, 0x224(r31)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xDC(r1)
	  lfs       f2, 0x198(r4)
	  stw       r3, 0xD8(r1)
	  lfs       f0, 0x188(r4)
	  lfd       f1, 0xD8(r1)
	  fsubs     f0, f0, f2
	  fsubs     f1, f1, f4
	  fdivs     f1, f1, f3
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x808(r31)
	  stfs      f3, 0x24(r30)
	  lfs       f0, -0x61E8(r2)
	  stfs      f0, 0x28(r30)
	  lmw       r26, 0xE8(r1)
	  lwz       r0, 0x154(r1)
	  lfd       f31, 0x148(r1)
	  lfd       f30, 0x140(r1)
	  lfd       f29, 0x138(r1)
	  lfd       f28, 0x130(r1)
	  lfd       f27, 0x128(r1)
	  lfd       f26, 0x120(r1)
	  lfd       f25, 0x118(r1)
	  lfd       f24, 0x110(r1)
	  lfd       f23, 0x108(r1)
	  lfd       f22, 0x100(r1)
	  addi      r1, r1, 0x150
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010789C
 * Size:	00008C
 */
void NaviThrowWaitState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r4, 0x4(r5)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x5C
	  bge-      .loc_0x70
	  cmpwi     r0, 0x1
	  beq-      .loc_0x34
	  b         .loc_0x70

	.loc_0x34:
	  li        r0, 0x1
	  stb       r0, 0x1C(r31)
	  li        r5, 0xC
	  lwz       r4, 0x10(r31)
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x70

	.loc_0x5C:
	  lwz       r3, 0x18(r31)
	  cmpwi     r3, 0x3
	  bge-      .loc_0x70
	  addi      r0, r3, 0x1
	  stw       r0, 0x18(r31)

	.loc_0x70:
	  li        r0, 0
	  stw       r0, 0x20(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void NaviThrowWaitState::lockHangPiki(Navi* navi)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80107928
 * Size:	00059C
 */
void NaviThrowWaitState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x180(r1)
	  stw       r31, 0x17C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x178(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  stw       r29, 0x174(r1)
	  stw       r28, 0x170(r1)
	  bl        -0x85138
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x57C
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x9E74
	  lwz       r0, 0x10(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x24C
	  lwz       r0, 0x14(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x22C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x24(r30)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x24(r30)
	  lfs       f1, 0x24(r30)
	  lfs       f0, -0x6268(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x9C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x57C

	.loc_0x9C:
	  lwz       r4, 0x2E4(r31)
	  lwz       r3, 0x2F98(r13)
	  lwz       r4, 0x28(r4)
	  lwz       r0, 0x64(r3)
	  and.      r0, r4, r0
	  beq-      .loc_0xD4
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x57C

	.loc_0xD4:
	  lwz       r3, 0x14(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x10C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x10C:
	  lwz       r3, 0x14(r30)
	  lfs       f2, 0x98(r31)
	  addi      r3, r3, 0x94
	  lfs       f0, 0x94(r31)
	  lfs       f3, 0x4(r3)
	  lfs       f1, 0x0(r3)
	  fsubs     f4, f3, f2
	  lfs       f2, 0x8(r3)
	  fsubs     f5, f1, f0
	  lfs       f1, 0x9C(r31)
	  lfs       f0, -0x6268(r2)
	  fsubs     f3, f2, f1
	  fmuls     f2, f5, f5
	  fmuls     f1, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x1B0
	  fsqrte    f1, f4
	  lfd       f3, -0x6238(r2)
	  lfd       f2, -0x6230(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0xB8(r1)
	  lfs       f4, 0xB8(r1)

	.loc_0x1B0:
	  lwz       r3, 0x224(r31)
	  lfs       f0, 0x1C8(r3)
	  fcmpo     cr0, f4, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x57C
	  lfs       f0, -0x61B8(r2)
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  stfs      f0, 0x6BC(r31)
	  beq-      .loc_0x1DC
	  addi      r28, r28, 0x2B8

	.loc_0x1DC:
	  addi      r3, r1, 0x118
	  li        r4, 0x24
	  bl        0x1744C
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x120
	  li        r4, 0x24
	  bl        0x1746C
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xD2C0
	  mr        r3, r31
	  bl        -0xD290
	  lwz       r3, 0x14(r30)
	  li        r0, 0
	  stw       r3, 0x10(r30)
	  stw       r0, 0x14(r30)
	  b         .loc_0x24C
	  b         .loc_0x57C

	.loc_0x22C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x1C
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x57C

	.loc_0x24C:
	  lwz       r0, 0x10(r30)
	  lis       r3, 0x4330
	  stw       r0, 0x7F8(r31)
	  lwz       r0, 0x18(r30)
	  lwz       r4, 0x224(r31)
	  xoris     r0, r0, 0x8000
	  lfd       f4, -0x6240(r2)
	  stw       r0, 0x16C(r1)
	  lfs       f3, -0x61E0(r2)
	  stw       r3, 0x168(r1)
	  lfs       f2, 0x178(r4)
	  lfd       f1, 0x168(r1)
	  lfs       f0, 0x168(r4)
	  fsubs     f1, f1, f4
	  fsubs     f0, f0, f2
	  fdivs     f1, f1, f3
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x804(r31)
	  lwz       r0, 0x18(r30)
	  lwz       r4, 0x224(r31)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x164(r1)
	  lfs       f2, 0x198(r4)
	  stw       r3, 0x160(r1)
	  lfs       f0, 0x188(r4)
	  lfd       f1, 0x160(r1)
	  fsubs     f0, f0, f2
	  fsubs     f1, f1, f4
	  fdivs     f1, f1, f3
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x808(r31)
	  lwz       r0, 0x10(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x34C
	  lbz       r0, 0x1C(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x34C
	  lis       r4, 0x7268
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x6E64
	  bl        -0x7E50C
	  lfs       f0, -0x292C(r13)
	  lfsu      f2, 0x4(r3)
	  lfs       f1, -0x2928(r13)
	  fadds     f2, f2, f0
	  lfs       f0, -0x2924(r13)
	  stfs      f2, 0xAC(r1)
	  lfs       f2, 0xAC(r1)
	  stfs      f2, 0xD8(r1)
	  lfs       f2, 0x4(r3)
	  fadds     f1, f2, f1
	  stfs      f1, 0xDC(r1)
	  lfs       f1, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE0(r1)
	  lwz       r4, 0x10(r30)
	  lwz       r3, 0xD8(r1)
	  lwz       r0, 0xDC(r1)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r0, 0xE0(r1)
	  stw       r0, 0x9C(r4)

	.loc_0x34C:
	  lwz       r3, 0x10(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x38C
	  bl        -0x3F72C
	  cmpwi     r3, 0xC
	  beq-      .loc_0x38C
	  cmpwi     r3, 0xB
	  beq-      .loc_0x38C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x57C

	.loc_0x38C:
	  lwz       r4, 0x2E4(r31)
	  lwz       r3, 0x2F98(r13)
	  lwz       r4, 0x20(r4)
	  lwz       r0, 0x40(r3)
	  and.      r0, r4, r0
	  bne-      .loc_0x430
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x59C
	  lwz       r4, 0x18(r30)
	  lis       r0, 0x4330
	  lwz       r6, 0x224(r31)
	  addi      r3, r30, 0
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x164(r1)
	  mr        r4, r31
	  lfd       f3, -0x6240(r2)
	  li        r5, 0x1
	  stw       r0, 0x160(r1)
	  lfs       f1, -0x61E0(r2)
	  lfd       f2, 0x160(r1)
	  lfs       f0, 0x158(r6)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f1, f0
	  stfs      f0, 0x800(r31)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x10(r30)
	  li        r0, 0x2
	  addi      r3, r31, 0
	  stw       r0, 0x144(r1)
	  addi      r4, r1, 0x144
	  stw       r5, 0x148(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x57C

	.loc_0x430:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x800(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x800(r31)
	  lwz       r3, 0x224(r31)
	  lfs       f1, 0x800(r31)
	  lfs       f0, 0x158(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x45C
	  stfs      f0, 0x800(r31)

	.loc_0x45C:
	  lfs       f1, 0x28(r30)
	  lfs       f3, -0x6268(r2)
	  fcmpo     cr0, f1, f3
	  ble-      .loc_0x49C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x28(r30)
	  lfs       f0, 0x28(r30)
	  fcmpo     cr0, f0, f3
	  cror      2, 0, 0x2
	  bne-      .loc_0x57C
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x59C
	  b         .loc_0x57C

	.loc_0x49C:
	  lwz       r3, 0x710(r31)
	  lwz       r0, 0x74(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x57C
	  lwz       r3, 0x80(r3)
	  lfsu      f2, 0xC(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x98(r31)
	  lfs       f4, 0x4(r3)
	  fsubs     f2, f2, f1
	  lfs       f5, 0x8(r3)
	  fsubs     f4, f4, f0
	  lfs       f0, 0x9C(r31)
	  fmuls     f1, f2, f2
	  fsubs     f5, f5, f0
	  fmuls     f0, f4, f4
	  fmuls     f2, f5, f5
	  fadds     f0, f1, f0
	  fadds     f4, f2, f0
	  fcmpo     cr0, f4, f3
	  ble-      .loc_0x548
	  fsqrte    f1, f4
	  lfd       f3, -0x6238(r2)
	  lfd       f2, -0x6230(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f4, 0xA8(r1)

	.loc_0x548:
	  lfs       f0, -0x61B8(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x57C
	  lfs       f1, -0x6218(r2)
	  addi      r4, r31, 0x94
	  lfs       f0, 0xA0(r31)
	  addi      r5, r31, 0x70
	  lwz       r3, 0x710(r31)
	  fadds     f1, f1, f0
	  bl        -0x62508
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x59C

	.loc_0x57C:
	  lwz       r0, 0x184(r1)
	  lwz       r31, 0x17C(r1)
	  lwz       r30, 0x178(r1)
	  lwz       r29, 0x174(r1)
	  lwz       r28, 0x170(r1)
	  addi      r1, r1, 0x180
	  mtlr      r0
	  blr

	.loc_0x59C:
	*/
}

/*
 * --INFO--
 * Address:	80107EC4
 * Size:	00016C
 */
void NaviThrowWaitState::sortPikis(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  mr        r30, r4
	  lwz       r4, 0x10(r3)
	  lwz       r3, 0x710(r30)
	  bl        -0x61F74
	  lfs       f1, -0x6218(r2)
	  addi      r4, r30, 0x94
	  lfs       f0, 0xA0(r30)
	  addi      r5, r30, 0x70
	  lwz       r3, 0x710(r30)
	  fadds     f1, f1, f0
	  bl        -0x62574
	  lwz       r31, 0x710(r30)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xF8

	.loc_0x60:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x84
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x9C

	.loc_0x84:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x9C:
	  lhz       r0, 0x4FC(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0xDC
	  lwz       r3, 0x4F8(r3)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0xC0
	  li        r0, 0
	  b         .loc_0xCC

	.loc_0xC0:
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r0, r3, r0

	.loc_0xCC:
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0xDC
	  bl        -0x523EC

	.loc_0xDC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xF8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x120
	  li        r0, 0x1
	  b         .loc_0x14C

	.loc_0x120:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x148
	  li        r0, 0x1
	  b         .loc_0x14C

	.loc_0x148:
	  li        r0, 0

	.loc_0x14C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x60
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108030
 * Size:	000004
 */
void NaviThrowWaitState::cleanup(Navi* navi) { }

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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r30, r29, 0
	  lfs       f0, -0x61B8(r2)
	  stfs      f0, 0x6BC(r4)
	  beq-      .loc_0x38
	  addi      r30, r30, 0x2B8

	.loc_0x38:
	  addi      r3, r1, 0x10
	  li        r4, 0x1B
	  bl        0x16EA0
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x1B
	  bl        0x16EC0
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xD86C
	  mr        r3, r29
	  bl        -0xD83C
	  li        r31, 0
	  stb       r31, 0x10(r28)
	  li        r3, 0x139
	  bl        -0x62D18
	  stb       r31, 0x11(r28)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010811C
 * Size:	00000C
 */
void NaviThrowState::procTargetMsg(Navi* navi, MsgTarget*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x4(r5)
	  stw       r0, 0x14(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108128
 * Size:	000148
 */
void NaviThrowState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stfd      f30, 0x88(r1)
	  stw       r31, 0x84(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x80(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x44
	  bge-      .loc_0x128
	  cmpwi     r0, 0
	  bge-      .loc_0x10C
	  b         .loc_0x128

	.loc_0x44:
	  lwz       r4, 0x14(r30)
	  li        r5, 0xE
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x2
	  li        r5, 0
	  li        r6, 0
	  bl        0x74BB0
	  lwz       r3, 0x224(r31)
	  lfs       f1, 0x800(r31)
	  lfs       f0, 0x158(r3)
	  lfs       f3, 0x178(r3)
	  fdivs     f2, f1, f0
	  lfs       f0, 0x168(r3)
	  lfs       f1, 0xA0(r31)
	  fsubs     f0, f0, f3
	  fmuls     f0, f2, f0
	  fadds     f30, f3, f0
	  bl        0x113990
	  fmuls     f31, f30, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x113B18
	  fmuls     f4, f30, f1
	  lfs       f0, 0x94(r31)
	  lfs       f3, 0x9C(r31)
	  mr        r3, r31
	  lfs       f2, -0x2920(r13)
	  lfs       f1, 0x98(r31)
	  fadds     f0, f4, f0
	  fadds     f3, f31, f3
	  addi      r5, r1, 0x68
	  fadds     f1, f2, f1
	  stfs      f0, 0x68(r1)
	  stfs      f1, 0x6C(r1)
	  stfs      f3, 0x70(r1)
	  lwz       r4, 0x6F0(r31)
	  lwz       r0, 0x6F4(r31)
	  stw       r4, 0x68(r1)
	  stw       r0, 0x6C(r1)
	  lwz       r0, 0x6F8(r31)
	  stw       r0, 0x70(r1)
	  lwz       r4, 0x14(r30)
	  bl        -0x7AF8
	  li        r0, 0x1
	  stb       r0, 0x10(r30)
	  b         .loc_0x128

	.loc_0x10C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x128:
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108270
 * Size:	0000F8
 */
void NaviThrowState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  li        r4, 0
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  bl        -0xA7A4
	  lwz       r4, 0x2E4(r31)
	  lwz       r3, 0x2F98(r13)
	  lwz       r4, 0x20(r4)
	  lwz       r0, 0x64(r3)
	  and.      r0, r4, r0
	  beq-      .loc_0x48
	  li        r0, 0x1
	  stb       r0, 0x11(r30)

	.loc_0x48:
	  mr        r3, r31
	  bl        -0xDBD8
	  lbz       r5, 0x10(r30)
	  cmplwi    r5, 0
	  beq-      .loc_0xA4
	  lwz       r4, 0x2E4(r31)
	  lwz       r3, 0x2F98(r13)
	  lwz       r4, 0x28(r4)
	  lwz       r0, 0x40(r3)
	  and.      r0, r4, r0
	  beq-      .loc_0xA4
	  mr        r3, r31
	  bl        -0xBAEC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xE0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x2
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE0

	.loc_0xA4:
	  cmplwi    r5, 0
	  beq-      .loc_0xE0
	  lwz       r4, 0x2E4(r31)
	  lwz       r3, 0x2F98(r13)
	  lwz       r4, 0x28(r4)
	  lwz       r0, 0x64(r3)
	  and.      r0, r4, r0
	  beq-      .loc_0xE0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x3
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xE0:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108368
 * Size:	000004
 */
void NaviThrowState::cleanup(Navi* navi) { }

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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x30
	  addi      r30, r30, 0x2B8

	.loc_0x30:
	  addi      r3, r1, 0x10
	  li        r4, 0x25
	  bl        0x16B70
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x25
	  bl        0x16B90
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xDB9C
	  lfs       f0, -0x61B8(r2)
	  li        r0, 0
	  stfs      f0, 0x6BC(r29)
	  stb       r0, 0x10(r28)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108440
 * Size:	000248
 */
void NaviPushState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stfd      f31, 0xC0(r1)
	  stfd      f30, 0xB8(r1)
	  stfd      f29, 0xB0(r1)
	  stfd      f28, 0xA8(r1)
	  stfd      f27, 0xA0(r1)
	  stfd      f26, 0x98(r1)
	  stw       r31, 0x94(r1)
	  addi      r31, r4, 0
	  li        r4, 0
	  stw       r30, 0x90(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  bl        -0xA98C
	  lbz       r0, 0x10(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x218
	  lfs       f3, -0x6268(r2)
	  stfs      f3, 0x8C(r1)
	  stfs      f3, 0x88(r1)
	  lwz       r4, 0x7AC(r31)
	  lfs       f5, -0x291C(r13)
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0x84(r1)
	  stw       r0, 0x88(r1)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x8C(r1)
	  lfs       f0, 0x84(r1)
	  lfs       f1, 0x88(r1)
	  fmuls     f0, f0, f5
	  lfs       f2, 0x8C(r1)
	  fmuls     f4, f1, f5
	  fmuls     f1, f2, f5
	  stfs      f0, 0x84(r1)
	  stfs      f4, 0x88(r1)
	  stfs      f1, 0x8C(r1)
	  lfs       f1, 0xA4(r31)
	  lfs       f6, 0x84(r1)
	  lfs       f0, 0xA8(r31)
	  lfs       f4, 0x88(r1)
	  fmuls     f1, f1, f6
	  lfs       f2, 0xAC(r31)
	  fmuls     f0, f0, f4
	  lfs       f5, 0x8C(r1)
	  fmuls     f2, f2, f5
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fcmpo     cr0, f0, f3
	  bge-      .loc_0xD4
	  fmr       f0, f3

	.loc_0xD4:
	  fmuls     f2, f6, f0
	  fmuls     f1, f4, f0
	  fmuls     f0, f5, f0
	  stfs      f2, 0x34(r1)
	  lfs       f2, 0x34(r1)
	  stfs      f2, 0x50(r1)
	  stfs      f1, 0x54(r1)
	  stfs      f0, 0x58(r1)
	  lwz       r3, 0x50(r1)
	  lwz       r0, 0x54(r1)
	  stw       r3, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x58(r1)
	  stw       r0, 0xAC(r31)
	  lfs       f29, 0x74C(r31)
	  lfs       f28, 0x750(r31)
	  lfs       f27, 0x754(r31)
	  lfs       f1, 0xA0(r31)
	  bl        0x1135F8
	  fmr       f30, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x113780
	  fmuls     f2, f29, f29
	  lfs       f26, -0x2918(r13)
	  fmuls     f0, f28, f28
	  fmuls     f3, f27, f27
	  fmr       f31, f1
	  fadds     f0, f2, f0
	  fadds     f1, f3, f0
	  bl        -0xFA948
	  lfs       f0, -0x6268(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x164
	  fdivs     f29, f29, f1
	  fdivs     f28, f28, f1
	  fdivs     f27, f27, f1

	.loc_0x164:
	  fmuls     f3, f31, f29
	  lfs       f0, -0x6268(r2)
	  fmuls     f2, f26, f28
	  fmuls     f4, f30, f27
	  fadds     f3, f3, f2
	  fadds     f2, f4, f3
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x194
	  lfs       f0, -0x61E8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1B8

	.loc_0x194:
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x1A4
	  addi      r4, r4, 0x2B8

	.loc_0x1A4:
	  addi      r3, r31, 0x834
	  bl        0x174D8
	  li        r0, 0x1
	  stb       r0, 0x10(r30)
	  b         .loc_0x218

	.loc_0x1B8:
	  lwz       r0, 0x7B0(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x218
	  lwz       r3, 0x2F80(r13)
	  lwz       r0, 0x70(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x218
	  lfs       f1, 0xA0(r31)
	  bl        0x11353C
	  fmr       f31, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x1136C4
	  stfs      f1, 0x5C(r1)
	  addi      r5, r31, 0x94
	  lfs       f0, -0x2914(r13)
	  addi      r6, r1, 0x5C
	  stfs      f0, 0x60(r1)
	  stfs      f31, 0x64(r1)
	  lwz       r3, 0x7B0(r31)
	  lwz       r4, 0x7AC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x218:
	  lwz       r0, 0xCC(r1)
	  lfd       f31, 0xC0(r1)
	  lfd       f30, 0xB8(r1)
	  lfd       f29, 0xB0(r1)
	  lfd       f28, 0xA8(r1)
	  lfd       f27, 0xA0(r1)
	  lfd       f26, 0x98(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108688
 * Size:	000014
 */
void NaviPushState::cleanup(Navi* navi)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x87C(r4)
	  cmpwi     r0, 0
	  lwz       r0, 0x8D0(r4)
	  cmpwi     r0, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010869C
 * Size:	0000F4
 */
void NaviPushState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r4
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x38
	  bge-      .loc_0xDC
	  cmpwi     r0, 0
	  beq-      .loc_0xC4
	  b         .loc_0xDC

	.loc_0x38:
	  lwz       r0, 0x7B0(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xDC
	  lwz       r3, 0x2F80(r13)
	  lwz       r0, 0x70(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xDC
	  lfs       f1, 0xA0(r31)
	  bl        0x113460
	  fmr       f31, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x1135E8
	  stfs      f1, 0x24(r1)
	  addi      r5, r31, 0x94
	  lfs       f0, -0x2910(r13)
	  addi      r6, r1, 0x24
	  stfs      f0, 0x28(r1)
	  stfs      f31, 0x2C(r1)
	  lfs       f4, -0x290C(r13)
	  lfs       f0, 0x24(r1)
	  lfs       f1, 0x28(r1)
	  fmuls     f0, f0, f4
	  lfs       f2, 0x2C(r1)
	  fmuls     f3, f1, f4
	  fmuls     f1, f2, f4
	  stfs      f0, 0x24(r1)
	  stfs      f3, 0x28(r1)
	  stfs      f1, 0x2C(r1)
	  lwz       r3, 0x7B0(r31)
	  lwz       r4, 0x7AC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xDC

	.loc_0xC4:
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xDC:
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108790
 * Size:	000004
 */
void NaviPushState::procOffWallMsg(Navi* navi, MsgOffWall*) { }

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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x30
	  addi      r30, r30, 0x2B8

	.loc_0x30:
	  addi      r3, r1, 0x10
	  li        r4, 0x25
	  bl        0x16748
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x25
	  bl        0x16768
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xDFC4
	  lfs       f0, -0x61B8(r2)
	  li        r0, 0x1
	  stfs      f0, 0x6BC(r29)
	  stw       r0, 0x10(r28)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108868
 * Size:	0001A8
 */
void NaviPushPikiState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  addi      r31, r4, 0
	  li        r4, 0
	  stw       r30, 0x58(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  bl        -0xADA0
	  lwz       r0, 0x10(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x54
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x48
	  addi      r4, r4, 0x2B8

	.loc_0x48:
	  addi      r3, r31, 0x834
	  bl        0x1720C
	  b         .loc_0x18C

	.loc_0x54:
	  lfs       f1, 0xA0(r31)
	  bl        0x113294
	  fmr       f31, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x11341C
	  lfs       f2, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  lfs       f4, -0x2908(r13)
	  fmuls     f2, f2, f1
	  lfs       f3, 0xAC(r31)
	  fmuls     f0, f0, f4
	  fmuls     f3, f3, f31
	  fadds     f0, f2, f0
	  fadds     f0, f3, f0
	  fmuls     f2, f1, f0
	  fmuls     f1, f4, f0
	  fmuls     f0, f31, f0
	  stfs      f2, 0x30(r1)
	  lfs       f2, 0x30(r1)
	  stfs      f2, 0x3C(r1)
	  stfs      f1, 0x40(r1)
	  stfs      f0, 0x44(r1)
	  lwz       r3, 0x3C(r1)
	  lwz       r0, 0x40(r1)
	  stw       r3, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x44(r1)
	  stw       r0, 0xAC(r31)
	  lwz       r3, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  lfs       f1, 0x74C(r31)
	  lfs       f3, 0x754(r31)
	  lfs       f0, 0x750(r31)
	  fmuls     f2, f1, f1
	  fmuls     f3, f3, f3
	  fmuls     f1, f0, f0
	  lfs       f0, -0x6268(r2)
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x160
	  fsqrte    f1, f4
	  lfd       f3, -0x6238(r2)
	  lfd       f2, -0x6230(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x2C(r1)
	  lfs       f4, 0x2C(r1)

	.loc_0x160:
	  lfs       f0, -0x61E8(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x184
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x17C
	  addi      r4, r4, 0x2B8

	.loc_0x17C:
	  addi      r3, r31, 0x834
	  bl        0x170D8

	.loc_0x184:
	  li        r0, 0
	  stw       r0, 0x10(r30)

	.loc_0x18C:
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108A10
 * Size:	000004
 */
void NaviPushPikiState::cleanup(Navi* navi) { }

/*
 * --INFO--
 * Address:	80108A14
 * Size:	0000E4
 */
void NaviPushPikiState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x38
	  bge-      .loc_0xCC
	  cmpwi     r0, 0
	  beq-      .loc_0xB4
	  b         .loc_0xCC

	.loc_0x38:
	  lwz       r0, 0x7B0(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xCC
	  lfs       f1, 0xA0(r31)
	  bl        0x1130F8
	  fmr       f31, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x113280
	  stfs      f1, 0x18(r1)
	  addi      r5, r31, 0x94
	  lfs       f0, -0x2904(r13)
	  addi      r6, r1, 0x18
	  stfs      f0, 0x1C(r1)
	  stfs      f31, 0x20(r1)
	  lfs       f4, -0x2900(r13)
	  lfs       f0, 0x18(r1)
	  lfs       f1, 0x1C(r1)
	  fmuls     f0, f0, f4
	  lfs       f2, 0x20(r1)
	  fmuls     f3, f1, f4
	  fmuls     f1, f2, f4
	  stfs      f0, 0x18(r1)
	  stfs      f3, 0x1C(r1)
	  stfs      f1, 0x20(r1)
	  lwz       r3, 0x7B0(r31)
	  lwz       r4, 0x7AC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xCC

	.loc_0xB4:
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xCC:
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108AF8
 * Size:	00000C
 */
void NaviPushPikiState::procCollideMsg(Navi* navi, MsgCollide*)
{
	// Generated from stw r0, 0x10(r3)
	// _10 = 1;
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x58(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x54(r1)
	  stw       r28, 0x50(r1)
	  lfs       f0, -0x61B8(r2)
	  stfs      f0, 0x6BC(r4)
	  lbz       r0, 0x7E5(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x7C
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x48
	  addi      r28, r28, 0x2B8

	.loc_0x48:
	  addi      r3, r1, 0x3C
	  li        r4, 0x52
	  bl        0x163C0
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x44
	  li        r4, 0x52
	  bl        0x163E0
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xE34C
	  b         .loc_0xBC

	.loc_0x7C:
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x8C
	  addi      r28, r28, 0x2B8

	.loc_0x8C:
	  addi      r3, r1, 0x2C
	  li        r4, 0x5
	  bl        0x1637C
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x34
	  li        r4, 0x5
	  bl        0x1639C
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xE390

	.loc_0xBC:
	  lfs       f0, -0x6268(r2)
	  stfs      f0, 0x814(r31)
	  lwz       r3, 0x224(r31)
	  lwz       r0, 0x1D8(r3)
	  sth       r0, 0x10(r30)
	  lwz       r0, 0x310(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x12C
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B6(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x12C
	  lbz       r0, 0x7E4(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x12C
	  lwz       r0, 0xC(r3)
	  cmpwi     r0, 0x64
	  bge-      .loc_0x12C
	  lwz       r3, 0x30D8(r13)
	  lwz       r3, 0x20(r3)
	  addi      r4, r3, 0x38
	  bl        0x1A3A0
	  li        r0, 0x1
	  stb       r0, 0x7E4(r31)
	  li        r0, 0
	  lwz       r3, 0x30D8(r13)
	  lwz       r3, 0x20(r3)
	  stb       r0, 0x30(r3)

	.loc_0x12C:
	  lwz       r3, 0x2F80(r13)
	  lwz       r0, 0x60(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x144
	  li        r0, 0
	  stb       r0, 0x930(r31)

	.loc_0x144:
	  li        r0, 0
	  stb       r0, 0x930(r31)
	  li        r3, 0x136
	  stb       r0, 0x12(r30)
	  stb       r0, 0x14(r30)
	  stb       r0, 0x13(r30)
	  stb       r0, 0x15(r30)
	  bl        -0x638CC
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  lwz       r28, 0x50(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108CCC
 * Size:	000110
 */
void NaviNukuState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r4
	  lfs       f0, -0x28FC(r13)
	  stfs      f0, 0x70(r4)
	  lfs       f0, -0x28F8(r13)
	  stfs      f0, 0x74(r4)
	  lfs       f0, -0x28F4(r13)
	  stfs      f0, 0x78(r4)
	  lfs       f0, -0x28F0(r13)
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x28EC(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x28E8(r13)
	  stfs      f0, 0xAC(r4)
	  lbz       r0, 0x13(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x70
	  lwz       r5, 0x2E4(r31)
	  lwz       r4, 0x2F98(r13)
	  lwz       r5, 0x20(r5)
	  lwz       r0, 0x88(r4)
	  and.      r0, r5, r0
	  bne-      .loc_0x70
	  li        r0, 0x1
	  stb       r0, 0x13(r3)

	.loc_0x70:
	  lbz       r0, 0x13(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xA8
	  lwz       r5, 0x2E4(r31)
	  lwz       r4, 0x2F98(r13)
	  lwz       r5, 0x20(r5)
	  lwz       r0, 0x88(r4)
	  and.      r0, r5, r0
	  beq-      .loc_0xA8
	  li        r0, 0x1
	  stb       r0, 0x14(r3)
	  lbz       r3, 0x7E5(r31)
	  addi      r0, r3, 0x1
	  stb       r0, 0x7E5(r31)

	.loc_0xA8:
	  lfs       f0, -0x28E4(r13)
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x28E0(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x28DC(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x814(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x814(r31)
	  lfs       f0, -0x6248(r2)
	  stfs      f0, 0x814(r31)
	  beq-      .loc_0xEC
	  addi      r4, r4, 0x2B8

	.loc_0xEC:
	  addi      r3, r31, 0x834
	  bl        0x16D04
	  lwz       r3, 0x7BC(r31)
	  stw       r31, 0x504(r3)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108DDC
 * Size:	000038
 */
void NaviNukuState::cleanup(Navi* navi)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x14(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x24
	  lbz       r0, 0x7E4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x24
	  li        r0, 0
	  stb       r0, 0x7E5(r4)
	  stb       r0, 0x7E6(r4)

	.loc_0x24:
	  lwz       r4, 0x2F6C(r13)
	  lwz       r3, 0xC(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0xC(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108E14
 * Size:	00012C
 */
void NaviNukuState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x40
	  bge-      .loc_0x110
	  cmpwi     r0, 0
	  bge-      .loc_0x9C
	  b         .loc_0x110

	.loc_0x40:
	  li        r0, 0x1
	  stb       r0, 0x15(r29)
	  li        r0, 0
	  li        r3, 0x137
	  stb       r0, 0x930(r30)
	  bl        -0x63A8C
	  lhz       r3, 0x10(r29)
	  subi      r0, r3, 0x1
	  sth       r0, 0x10(r29)
	  lhz       r0, 0x10(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x110
	  li        r3, 0x147
	  bl        -0x63AAC
	  cmplwi    r30, 0
	  addi      r4, r30, 0
	  beq-      .loc_0x88
	  addi      r4, r4, 0x2B8

	.loc_0x88:
	  addi      r3, r30, 0x834
	  bl        0x16C20
	  li        r0, 0x1
	  stb       r0, 0x12(r29)
	  b         .loc_0x110

	.loc_0x9C:
	  li        r31, 0
	  stw       r31, 0x810(r30)
	  lbz       r0, 0x14(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0xE8
	  mr        r3, r30
	  bl        -0xC6CC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x108
	  stb       r31, 0x14(r29)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  lwz       r12, 0x0(r29)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  stb       r31, 0x7E5(r30)
	  b         .loc_0x108

	.loc_0xE8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  stb       r31, 0x7E5(r30)

	.loc_0x108:
	  li        r0, 0
	  stw       r0, 0x770(r30)

	.loc_0x110:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108FCC
 * Size:	000030
 */
void NaviNukuAdjustState::restart(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80108FFC
 * Size:	0001E4
 */
void NaviNukuAdjustState::init(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stfd      f31, 0x100(r1)
	  stfd      f30, 0xF8(r1)
	  stfd      f29, 0xF0(r1)
	  stw       r31, 0xEC(r1)
	  addi      r31, r4, 0
	  li        r4, 0x7
	  stw       r30, 0xE8(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x2F6C(r13)
	  addi      r3, r5, 0x54
	  bl        -0x868E0
	  li        r0, 0
	  stb       r0, 0x20(r30)
	  lbz       r0, -0x2D80(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x78
	  lwz       r3, 0x7C0(r31)
	  lfsu      f4, 0x94(r3)
	  lfs       f0, 0x94(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f3, 0x4(r3)
	  fsubs     f29, f4, f0
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x9C(r31)
	  fsubs     f30, f3, f2
	  fsubs     f31, f1, f0
	  b         .loc_0xA0

	.loc_0x78:
	  lwz       r3, 0x7BC(r31)
	  lfsu      f4, 0x94(r3)
	  lfs       f0, 0x94(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f3, 0x4(r3)
	  fsubs     f29, f4, f0
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x9C(r31)
	  fsubs     f30, f3, f2
	  fsubs     f31, f1, f0

	.loc_0xA0:
	  fmr       f1, f29
	  fmr       f2, f31
	  bl        0x112954
	  fmuls     f2, f29, f29
	  stfs      f1, 0x10(r30)
	  fmuls     f0, f30, f30
	  fmuls     f1, f31, f31
	  fadds     f0, f2, f0
	  fadds     f1, f1, f0
	  bl        -0xFB480
	  lfs       f0, -0x6268(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xE0
	  fdivs     f29, f29, f1
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1

	.loc_0xE0:
	  lbz       r0, -0x2D80(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x150
	  lfs       f2, -0x28D8(r13)
	  fmuls     f1, f29, f2
	  fmuls     f0, f30, f2
	  fmuls     f3, f31, f2
	  stfs      f1, 0x60(r1)
	  lwz       r3, 0x7C0(r31)
	  lfs       f1, 0x60(r1)
	  lfsu      f2, 0x94(r3)
	  fsubs     f1, f2, f1
	  stfs      f1, 0x78(r1)
	  lfs       f1, 0x78(r1)
	  stfs      f1, 0xC8(r1)
	  lfs       f1, 0x4(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xCC(r1)
	  lfs       f0, 0x8(r3)
	  fsubs     f0, f0, f3
	  stfs      f0, 0xD0(r1)
	  lwz       r3, 0xC8(r1)
	  lwz       r0, 0xCC(r1)
	  stw       r3, 0x14(r30)
	  stw       r0, 0x18(r30)
	  lwz       r0, 0xD0(r1)
	  stw       r0, 0x1C(r30)
	  b         .loc_0x1B0

	.loc_0x150:
	  lfs       f2, -0x28D4(r13)
	  fmuls     f1, f29, f2
	  fmuls     f0, f30, f2
	  fmuls     f3, f31, f2
	  stfs      f1, 0x58(r1)
	  lwz       r3, 0x7BC(r31)
	  lfs       f1, 0x58(r1)
	  lfsu      f2, 0x94(r3)
	  fsubs     f1, f2, f1
	  stfs      f1, 0x6C(r1)
	  lfs       f1, 0x6C(r1)
	  stfs      f1, 0xB0(r1)
	  lfs       f1, 0x4(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xB4(r1)
	  lfs       f0, 0x8(r3)
	  fsubs     f0, f0, f3
	  stfs      f0, 0xB8(r1)
	  lwz       r3, 0xB0(r1)
	  lwz       r0, 0xB4(r1)
	  stw       r3, 0x14(r30)
	  stw       r0, 0x18(r30)
	  lwz       r0, 0xB8(r1)
	  stw       r0, 0x1C(r30)

	.loc_0x1B0:
	  lfs       f1, -0x61B0(r2)
	  addi      r3, r31, 0x2C4
	  lfs       f2, -0x61AC(r2)
	  bl        -0x3B9A4
	  lwz       r0, 0x10C(r1)
	  lfd       f31, 0x100(r1)
	  lfd       f30, 0xF8(r1)
	  lfd       f29, 0xF0(r1)
	  lwz       r31, 0xEC(r1)
	  lwz       r30, 0xE8(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801091E0
 * Size:	00045C
 */
void NaviNukuAdjustState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x120(r1)
	  stfd      f31, 0x118(r1)
	  stfd      f30, 0x110(r1)
	  stfd      f29, 0x108(r1)
	  stfd      f28, 0x100(r1)
	  stmw      r27, 0xEC(r1)
	  mr        r31, r4
	  mr        r30, r3
	  lwz       r4, 0x2E4(r4)
	  lwz       r0, 0x20(r4)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x60
	  li        r0, 0
	  stb       r0, 0x7E5(r31)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  lwz       r12, 0x0(r30)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x438

	.loc_0x60:
	  addi      r3, r31, 0x2C4
	  addi      r4, r31, 0x94
	  addi      r5, r30, 0x24
	  bl        -0x3BA20
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xA0
	  li        r0, 0
	  stb       r0, 0x7E5(r31)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  lwz       r12, 0x0(r30)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x438

	.loc_0xA0:
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x24(r30)
	  stw       r0, 0x28(r30)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x2C(r30)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  lbz       r0, -0x2D80(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xFC
	  lwz       r3, 0x7C0(r31)
	  lfsu      f4, 0x94(r3)
	  lfs       f0, 0x94(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f3, 0x4(r3)
	  fsubs     f4, f4, f0
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x9C(r31)
	  fsubs     f3, f3, f2
	  fsubs     f2, f1, f0
	  b         .loc_0x124

	.loc_0xFC:
	  lwz       r3, 0x7BC(r31)
	  lfsu      f4, 0x94(r3)
	  lfs       f0, 0x94(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f3, 0x4(r3)
	  fsubs     f4, f4, f0
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x9C(r31)
	  fsubs     f3, f3, f2
	  fsubs     f2, f1, f0

	.loc_0x124:
	  fmuls     f1, f4, f4
	  fmuls     f0, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xFB6D8
	  lfs       f3, 0x14(r30)
	  lfs       f2, 0x94(r31)
	  lfs       f1, 0x18(r30)
	  lfs       f0, 0x98(r31)
	  fsubs     f29, f3, f2
	  lfs       f2, 0x1C(r30)
	  fsubs     f30, f1, f0
	  lfs       f0, 0x9C(r31)
	  fmuls     f1, f29, f29
	  fsubs     f31, f2, f0
	  fmuls     f0, f30, f30
	  fmuls     f2, f31, f31
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xFB714
	  fmr       f28, f1
	  lfs       f0, -0x6268(r2)
	  fcmpu     cr0, f0, f28
	  beq-      .loc_0x194
	  fdivs     f29, f29, f28
	  fdivs     f30, f30, f28
	  fdivs     f31, f31, f28

	.loc_0x194:
	  lfs       f1, 0x10(r30)
	  lfs       f2, 0xA0(r31)
	  bl        -0xD0DC8
	  stfs      f1, 0x70(r1)
	  lfs       f0, -0x61A8(r2)
	  lwz       r0, 0x70(r1)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x70(r1)
	  lfs       f2, 0x70(r1)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x344
	  lfs       f0, -0x625C(r2)
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0x344
	  lbz       r0, -0x2D80(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x2F0
	  li        r28, 0x1
	  lwz       r3, 0x3068(r13)
	  stb       r28, 0x306D(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  li        r29, 0
	  mr.       r27, r3
	  stb       r29, 0x306D(r13)
	  bne-      .loc_0x224
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x438

	.loc_0x224:
	  addi      r3, r27, 0
	  addi      r4, r31, 0
	  bl        -0x3D3C8
	  lwz       r4, 0x7C0(r31)
	  mr        r3, r27
	  lwz       r4, 0x3CC(r4)
	  bl        -0x3FBA4
	  mr        r3, r27
	  lwz       r4, 0x7C0(r31)
	  lwz       r12, 0x0(r27)
	  lwz       r4, 0x3D0(r4)
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r4, 0x7C0(r31)
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x94
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  stb       r28, 0x306E(r13)
	  addi      r3, r27, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x3C29C
	  stb       r29, 0x306E(r13)
	  lwz       r3, 0x7C0(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x7C0(r31)
	  li        r4, 0
	  bl        -0x7E7AC
	  stw       r29, 0x7C0(r31)
	  lis       r4, 0x802B
	  subi      r0, r4, 0x3064
	  stw       r27, 0x7BC(r31)
	  lis       r3, 0x802B
	  addi      r4, r1, 0xCC
	  stw       r0, 0xCC(r1)
	  subi      r0, r3, 0x2CFC
	  stw       r31, 0xD0(r1)
	  stw       r0, 0xCC(r1)
	  lwz       r3, 0x7BC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x324

	.loc_0x2F0:
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  stw       r0, 0xC4(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x2CFC
	  stw       r31, 0xC8(r1)
	  addi      r4, r1, 0xC4
	  stw       r0, 0xC4(r1)
	  lwz       r3, 0x7BC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x324:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x5
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x438

	.loc_0x344:
	  lfs       f0, -0x61BC(r2)
	  lfs       f2, -0x61EC(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x6C(r1)
	  fmr       f1, f0
	  lwz       r0, 0x6C(r1)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x6C(r1)
	  lfs       f0, 0x6C(r1)
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x388
	  lfs       f0, -0x6268(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x380
	  b         .loc_0x384

	.loc_0x380:
	  lfs       f2, -0x61A4(r2)

	.loc_0x384:
	  fmr       f1, f2

	.loc_0x388:
	  lfs       f0, 0xA0(r31)
	  fadds     f1, f0, f1
	  bl        -0xD0FE8
	  stfs      f1, 0xA0(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f3, -0x61C4(r2)
	  lfs       f1, 0x28C(r3)
	  fmuls     f0, f3, f1
	  fcmpo     cr0, f0, f28
	  ble-      .loc_0x3B8
	  lfs       f0, -0x6254(r2)
	  fdivs     f3, f0, f1

	.loc_0x3B8:
	  fmuls     f1, f29, f3
	  fmuls     f2, f30, f3
	  fmuls     f3, f31, f3
	  stfs      f1, 0x5C(r1)
	  lfs       f0, 0x5C(r1)
	  stfs      f0, 0xB8(r1)
	  stfs      f2, 0xBC(r1)
	  stfs      f3, 0xC0(r1)
	  lwz       r3, 0xB8(r1)
	  lwz       r0, 0xBC(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xC0(r1)
	  stw       r0, 0x78(r31)
	  stfs      f1, 0xAC(r1)
	  stfs      f2, 0xB0(r1)
	  stfs      f3, 0xB4(r1)
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r3, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0xAC(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  lfs       f0, -0x28D0(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, -0x28CC(r13)
	  stfs      f0, 0x90(r31)

	.loc_0x438:
	  lmw       r27, 0xEC(r1)
	  lwz       r0, 0x124(r1)
	  lfd       f31, 0x118(r1)
	  lfd       f30, 0x110(r1)
	  lfd       f29, 0x108(r1)
	  lfd       f28, 0x100(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010963C
 * Size:	000010
 */
void NaviNukuAdjustState::cleanup(Navi* navi)
{
	/*
	.loc_0x0:
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0xC8(r4)
	  blr
	*/
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
	/*
	.loc_0x0:
	  lwz       r3, 0x224(r4)
	  lfs       f0, 0x2E8(r3)
	  stfs      f0, 0x814(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801096A0
 * Size:	0000F4
 */
void NaviPressedState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x2DEC(r13)
	  lwz       r6, 0x224(r4)
	  lfs       f1, 0x814(r4)
	  lfs       f0, 0x28C(r5)
	  lfs       f5, 0xF8(r6)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x814(r4)
	  lfs       f2, 0x814(r4)
	  lfs       f0, -0x6268(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x8C
	  stfs      f0, 0x814(r4)
	  stfs      f5, 0x7C(r4)
	  stfs      f5, 0x80(r4)
	  stfs      f5, 0x84(r4)
	  lfs       f1, 0x58(r4)
	  lfs       f0, -0x625C(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x74
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1D
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE4

	.loc_0x74:
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE4

	.loc_0x8C:
	  lwz       r5, 0x224(r4)
	  lfs       f1, 0x2E8(r5)
	  lfs       f0, 0x2F8(r5)
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xB0
	  lfs       f3, -0x621C(r2)
	  lfs       f0, -0x6204(r2)
	  b         .loc_0xD0

	.loc_0xB0:
	  fdivs     f4, f2, f0
	  lfs       f3, -0x625C(r2)
	  lfs       f1, -0x61A0(r2)
	  lfs       f2, -0x6204(r2)
	  fsubs     f0, f3, f4
	  fadds     f3, f3, f4
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0

	.loc_0xD0:
	  fmuls     f1, f5, f3
	  fmuls     f0, f5, f0
	  stfs      f1, 0x7C(r4)
	  stfs      f0, 0x80(r4)
	  stfs      f1, 0x84(r4)

	.loc_0xE4:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80109794
 * Size:	000004
 */
void NaviPressedState::cleanup(Navi* navi) { }

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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  addi      r30, r29, 0
	  beq-      .loc_0x28
	  addi      r30, r30, 0x2B8

	.loc_0x28:
	  addi      r3, r1, 0x10
	  li        r4, 0xF
	  bl        0x1574C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0xF
	  bl        0x1576C
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xEFC0
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80109850
 * Size:	000004
 */
void NaviSowState::exec(Navi* navi) { }

/*
 * --INFO--
 * Address:	80109854
 * Size:	000004
 */
void NaviSowState::cleanup(Navi* navi) { }

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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  lfs       f0, -0x28C8(r13)
	  mr        r30, r29
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x28C4(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x28C0(r13)
	  stfs      f0, 0xAC(r4)
	  lfs       f0, -0x28BC(r13)
	  stfs      f0, 0x70(r4)
	  lfs       f0, -0x28B8(r13)
	  stfs      f0, 0x74(r4)
	  lfs       f0, -0x28B4(r13)
	  stfs      f0, 0x78(r4)
	  beq-      .loc_0x58
	  addi      r30, r30, 0x2B8

	.loc_0x58:
	  addi      r3, r1, 0x10
	  li        r4, 0xF
	  bl        0x1565C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0xF
	  bl        0x1567C
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xF0B0
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80109940
 * Size:	000004
 */
void NaviWaterState::exec(Navi* navi) { }

/*
 * --INFO--
 * Address:	80109944
 * Size:	000004
 */
void NaviWaterState::cleanup(Navi* navi) { }

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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801099B8
 * Size:	000030
 */
void NaviAttackState::restart(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801099E8
 * Size:	0000CC
 */
void NaviAttackState::init(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  mr.       r29, r4
	  stw       r28, 0x30(r1)
	  addi      r28, r3, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x30
	  addi      r30, r30, 0x2B8

	.loc_0x30:
	  addi      r3, r1, 0x1C
	  li        r4, 0x19
	  bl        0x15538
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x24
	  li        r4, 0x19
	  bl        0x15558
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xF1D4
	  mr        r3, r29
	  bl        -0xF1A4
	  addi      r30, r29, 0x88C
	  addi      r3, r1, 0x14
	  li        r4, 0x1
	  bl        0x154FC
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  bl        0x15758
	  lfs       f0, -0x61F4(r2)
	  li        r31, 0
	  li        r3, 0x138
	  stfs      f0, 0x2C(r30)
	  sth       r31, 0x10(r28)
	  lfs       f0, -0x6268(r2)
	  stfs      f0, 0x18(r28)
	  stfs      f0, 0x14(r28)
	  bl        -0x646B0
	  stb       r31, 0x12(r28)
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  lwz       r28, 0x30(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80109AB4
 * Size:	000424
 */
void NaviAttackState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x120(r1)
	  stfd      f31, 0x118(r1)
	  stfd      f30, 0x110(r1)
	  stfd      f29, 0x108(r1)
	  stfd      f28, 0x100(r1)
	  stfd      f27, 0xF8(r1)
	  stfd      f26, 0xF0(r1)
	  stfd      f25, 0xE8(r1)
	  stmw      r24, 0xC8(r1)
	  addi      r29, r4, 0
	  addi      r28, r3, 0
	  addi      r3, r29, 0
	  bl        -0x872D4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3F4
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        -0xC010
	  lwz       r4, 0x2E4(r29)
	  lwz       r3, 0x2F98(r13)
	  lwz       r4, 0x28(r4)
	  lwz       r0, 0x64(r3)
	  and.      r0, r4, r0
	  beq-      .loc_0x70
	  li        r0, 0x1
	  stb       r0, 0x12(r28)

	.loc_0x70:
	  lhz       r0, 0x10(r28)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x3F4
	  lwz       r31, 0x3160(r13)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f28, -0x6268(r2)
	  lis       r4, 0x802B
	  lfd       f29, -0x6238(r2)
	  lfd       f30, -0x6230(r2)
	  addi      r30, r3, 0
	  lfs       f31, -0x619C(r2)
	  subi      r26, r5, 0x3064
	  subi      r27, r4, 0x31FC
	  b         .loc_0x398

	.loc_0xBC:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xE4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r25, r3
	  b         .loc_0x100

	.loc_0xE4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r25, r3

	.loc_0x100:
	  addi      r24, r25, 0
	  addi      r3, r24, 0
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x37C
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x37C
	  lwz       r0, 0xC8(r25)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x37C
	  lfs       f3, 0x9C(r25)
	  lfs       f2, 0x9C(r29)
	  lfs       f1, 0x94(r25)
	  lfs       f0, 0x94(r29)
	  fsubs     f27, f3, f2
	  lfs       f2, 0x98(r25)
	  fsubs     f26, f1, f0
	  lfs       f0, 0x98(r29)
	  fsubs     f25, f2, f0
	  fmr       f2, f27
	  fmr       f1, f26
	  bl        0x111DD0
	  fmuls     f2, f26, f26
	  fmuls     f0, f25, f25
	  fmuls     f3, f27, f27
	  fmr       f26, f1
	  fadds     f0, f2, f0
	  fadds     f27, f3, f0
	  fcmpo     cr0, f27, f28
	  ble-      .loc_0x1E8
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f27, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f27, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f27, f0
	  fsub      f0, f30, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0x54(r1)
	  lfs       f27, 0x54(r1)

	.loc_0x1E8:
	  mr        r3, r29
	  lwz       r4, 0x224(r29)
	  lwz       r12, 0x0(r29)
	  addi      r25, r4, 0x3E8
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r24
	  fmr       f25, f1
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f1, f25
	  lfs       f0, 0x0(r25)
	  fadds     f0, f0, f1
	  fcmpo     cr0, f27, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x37C
	  lfs       f1, 0xA0(r29)
	  fmr       f2, f26
	  bl        -0xD173C
	  fabs      f0, f1
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0x37C
	  lwz       r4, 0x224(r29)
	  li        r0, 0
	  addi      r3, r24, 0
	  lfs       f0, 0x3D8(r4)
	  addi      r4, r1, 0x94
	  stw       r26, 0x94(r1)
	  stw       r29, 0x98(r1)
	  stw       r27, 0x94(r1)
	  stfs      f0, 0x9C(r1)
	  stw       r0, 0xA0(r1)
	  stb       r0, 0xA4(r1)
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x354
	  lfs       f1, 0xA0(r29)
	  bl        0x111E0C
	  fmr       f26, f1
	  lfs       f1, 0xA0(r29)
	  bl        0x111F94
	  stfs      f1, 0x88(r1)
	  addi      r5, r1, 0x88
	  lfs       f0, -0x28B0(r13)
	  li        r4, 0x7
	  li        r6, 0
	  stfs      f0, 0x8C(r1)
	  li        r7, 0
	  stfs      f26, 0x90(r1)
	  lfs       f5, -0x28AC(r13)
	  lfs       f0, 0x88(r1)
	  lfs       f2, 0x8C(r1)
	  lfs       f4, 0x90(r1)
	  fmuls     f0, f0, f5
	  lfs       f1, 0x94(r29)
	  fmuls     f2, f2, f5
	  lfs       f3, 0x98(r29)
	  fadds     f0, f1, f0
	  lfs       f1, 0x9C(r29)
	  fmuls     f4, f4, f5
	  fadds     f2, f3, f2
	  stfs      f0, 0x88(r1)
	  fadds     f0, f1, f4
	  stfs      f2, 0x8C(r1)
	  stfs      f0, 0x90(r1)
	  lwz       r3, 0x3180(r13)
	  bl        0x92D7C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x88
	  li        r4, 0x8
	  li        r6, 0
	  li        r7, 0
	  bl        0x92D64
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x2
	  li        r5, 0
	  li        r6, 0
	  bl        0x72F60
	  addi      r3, r29, 0
	  addi      r4, r24, 0
	  li        r5, 0x19
	  bl        -0x7F844
	  li        r0, 0x2
	  sth       r0, 0x10(r28)
	  b         .loc_0x37C

	.loc_0x354:
	  lbz       r0, 0x12(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x37C
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  addi      r4, r29, 0
	  li        r5, 0x3
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x37C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x398:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C0
	  li        r0, 0x1
	  b         .loc_0x3EC

	.loc_0x3C0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x3E8
	  li        r0, 0x1
	  b         .loc_0x3EC

	.loc_0x3E8:
	  li        r0, 0

	.loc_0x3EC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xBC

	.loc_0x3F4:
	  lmw       r24, 0xC8(r1)
	  lwz       r0, 0x124(r1)
	  lfd       f31, 0x118(r1)
	  lfd       f30, 0x110(r1)
	  lfd       f29, 0x108(r1)
	  lfd       f28, 0x100(r1)
	  lfd       f27, 0xF8(r1)
	  lfd       f26, 0xF0(r1)
	  lfd       f25, 0xE8(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80109ED8
 * Size:	000004
 */
void NaviAttackState::cleanup(Navi* navi) { }

/*
 * --INFO--
 * Address:	80109EDC
 * Size:	000080
 */
void NaviAttackState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2C
	  bge-      .loc_0x70
	  cmpwi     r0, 0
	  bge-      .loc_0x38
	  b         .loc_0x70

	.loc_0x2C:
	  li        r0, 0x1
	  sth       r0, 0x10(r3)
	  b         .loc_0x70

	.loc_0x38:
	  lbz       r0, 0x12(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C
	  lwz       r12, 0x0(r3)
	  li        r5, 0x3
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x70

	.loc_0x5C:
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x70:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
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
void NaviLockState::init(Navi* navi) { }

/*
 * --INFO--
 * Address:	80109FA4
 * Size:	000004
 */
void NaviLockState::exec(Navi* navi) { }

/*
 * --INFO--
 * Address:	80109FA8
 * Size:	000004
 */
void NaviLockState::cleanup(Navi* navi) { }

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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  addi      r30, r29, 0
	  beq-      .loc_0x28
	  addi      r30, r30, 0x2B8

	.loc_0x28:
	  addi      r3, r1, 0x10
	  li        r4, 0x23
	  bl        0x14F38
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x23
	  bl        0x14F58
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xF7D4
	  lfs       f0, -0x28A8(r13)
	  stfs      f0, 0x70(r29)
	  lfs       f0, -0x28A4(r13)
	  stfs      f0, 0x74(r29)
	  lfs       f0, -0x28A0(r13)
	  stfs      f0, 0x78(r29)
	  lfs       f0, -0x289C(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x2898(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x2894(r13)
	  stfs      f0, 0xAC(r29)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010A094
 * Size:	000004
 */
void NaviClearState::exec(Navi* navi) { }

/*
 * --INFO--
 * Address:	8010A098
 * Size:	000050
 */
void NaviClearState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  lwz       r3, 0x4(r5)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x3C
	  lis       r3, 0x803A
	  subi      r31, r3, 0x24E0
	  li        r0, 0x3
	  stw       r0, 0x234(r31)
	  mr        r3, r4
	  bl        -0x11B74
	  stw       r3, 0x248(r31)

	.loc_0x3C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010A0E8
 * Size:	000004
 */
void NaviClearState::cleanup(Navi* navi) { }

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
void NaviIroIroState::init(Navi* navi) { }

/*
 * --INFO--
 * Address:	8010A134
 * Size:	00001C
 */
void NaviIroIroState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x2890(r13)
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x288C(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x2888(r13)
	  stfs      f0, 0xAC(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010A150
 * Size:	000004
 */
void NaviIroIroState::cleanup(Navi* navi) { }

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
void NaviDeadState::restart(Navi* navi) { }

/*
 * --INFO--
 * Address:	8010A19C
 * Size:	000154
 */
void NaviDeadState::init(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  li        r4, 0xD
	  lwz       r3, 0x2F6C(r13)
	  stb       r0, 0x3108(r13)
	  addi      r3, r3, 0x70
	  bl        -0x867CC
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r30, r3, 0x1E8
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0xE
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r30)
	  li        r4, 0x10
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x61B8(r2)
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  stfs      f0, 0x6BC(r29)
	  beq-      .loc_0x90
	  addi      r30, r30, 0x2B8

	.loc_0x90:
	  addi      r3, r1, 0x10
	  li        r4, 0x59
	  bl        0x14D24
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x59
	  bl        0x14D44
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xF9E8
	  li        r3, 0x13F
	  bl        -0x64E84
	  lfs       f0, -0x2884(r13)
	  stfs      f0, 0x70(r29)
	  lfs       f0, -0x2880(r13)
	  stfs      f0, 0x74(r29)
	  lfs       f0, -0x287C(r13)
	  stfs      f0, 0x78(r29)
	  lfs       f0, -0x2878(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x2874(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x2870(r13)
	  stfs      f0, 0xAC(r29)
	  lwz       r3, 0x30D8(r13)
	  lwz       r3, 0x20(r3)
	  addi      r4, r3, 0x38
	  bl        0x18D58
	  lwz       r3, 0x30D8(r13)
	  li        r0, 0
	  li        r4, 0
	  lwz       r3, 0x20(r3)
	  stb       r0, 0x20(r3)
	  lwz       r3, 0x3030(r13)
	  bl        -0x66C80
	  mr        r3, r29
	  bl        -0xE3A8
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010A2F0
 * Size:	00001C
 */
void NaviDeadState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x286C(r13)
	  stfs      f0, 0x70(r4)
	  lfs       f0, -0x2868(r13)
	  stfs      f0, 0x74(r4)
	  lfs       f0, -0x2864(r13)
	  stfs      f0, 0x78(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010A30C
 * Size:	000004
 */
void NaviDeadState::cleanup(Navi* navi) { }

/*
 * --INFO--
 * Address:	8010A310
 * Size:	000054
 */
void NaviDeadState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r5)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x20
	  b         .loc_0x44

	.loc_0x20:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0x5
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x44:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
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
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x2848
	  li        r5, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0x1E8
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lwz       r3, 0x1E8(r4)
	  li        r4, 0xE
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  li        r4, 0x10
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xE
	  addi      r3, r3, 0x70
	  bl        -0x86A10
	  li        r0, 0x1E
	  lis       r3, 0x1
	  sth       r0, 0x12(r30)
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010A440
 * Size:	000054
 */
void NaviPikiZeroState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lhz       r4, 0x12(r3)
	  subi      r4, r4, 0x1
	  rlwinm.   r0,r4,0,16,31
	  sth       r4, 0x12(r3)
	  bne-      .loc_0x44
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0x5
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x44:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010A494
 * Size:	000004
 */
void NaviPikiZeroState::cleanup(Navi* navi) { }

/*
 * --INFO--
 * Address:	8010A498
 * Size:	000004
 */
void NaviPikiZeroState::procAnimMsg(Navi* navi, MsgAnim*) { }

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
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r5, r5, 0x2848
	  stwu      r1, -0x110(r1)
	  stfd      f31, 0x108(r1)
	  stfd      f30, 0x100(r1)
	  stfd      f29, 0xF8(r1)
	  stw       r31, 0xF4(r1)
	  mr        r31, r4
	  li        r4, 0xE
	  stw       r30, 0xF0(r1)
	  addi      r30, r3, 0
	  stw       r29, 0xEC(r1)
	  stw       r28, 0xE8(r1)
	  lwz       r3, 0x1E8(r5)
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x64
	  addi      r28, r28, 0x2B8

	.loc_0x64:
	  addi      r3, r1, 0xC8
	  li        r4, 0x2
	  bl        0x149E4
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0xD0
	  li        r4, 0x2
	  bl        0x14A04
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xFD28
	  lwz       r3, 0x30AC(r13)
	  bl        -0x17968
	  mr.       r28, r3
	  beq-      .loc_0x1D8
	  lfs       f1, 0xA0(r28)
	  bl        0x1115A4
	  fmr       f30, f1
	  lfs       f1, 0xA0(r28)
	  bl        0x11172C
	  fmr       f31, f1
	  lfs       f0, -0x285C(r13)
	  lfs       f29, -0x2860(r13)
	  li        r4, 0x1
	  fmuls     f3, f30, f0
	  fmuls     f1, f31, f0
	  fmuls     f0, f29, f0
	  stfs      f1, 0x84(r1)
	  lfs       f2, 0x94(r28)
	  lfs       f1, 0x84(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x78(r1)
	  lfs       f1, 0x78(r1)
	  stfs      f1, 0xBC(r1)
	  lfs       f1, 0x98(r28)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0x9C(r28)
	  fadds     f0, f0, f3
	  stfs      f0, 0xC4(r1)
	  lwz       r3, 0xBC(r1)
	  lwz       r0, 0xC0(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0xC4(r1)
	  stw       r0, 0x9C(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0xA2730
	  stfs      f1, 0x98(r31)
	  li        r4, 0x1
	  lfs       f0, -0x6198(r2)
	  fmuls     f2, f31, f0
	  fmuls     f1, f29, f0
	  fmuls     f0, f30, f0
	  stfs      f2, 0x6C(r1)
	  lfs       f3, 0x94(r31)
	  lfs       f2, 0x6C(r1)
	  fadds     f2, f3, f2
	  stfs      f2, 0x60(r1)
	  lfs       f2, 0x60(r1)
	  stfs      f2, 0xA4(r1)
	  lfs       f2, 0x98(r31)
	  fadds     f1, f2, f1
	  stfs      f1, 0xA8(r1)
	  lfs       f1, 0x9C(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0xAC(r1)
	  lwz       r3, 0xA4(r1)
	  lwz       r0, 0xA8(r1)
	  stw       r3, 0x14(r30)
	  stw       r0, 0x18(r30)
	  lwz       r0, 0xAC(r1)
	  stw       r0, 0x1C(r30)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x14(r30)
	  lfs       f2, 0x1C(r30)
	  bl        -0xA27A4
	  stfs      f1, 0x18(r30)
	  addi      r4, r28, 0
	  addi      r3, r1, 0x8C
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x8C(r1)
	  lwz       r0, 0x90(r1)
	  stw       r3, 0x14(r30)
	  stw       r0, 0x18(r30)
	  lwz       r0, 0x94(r1)
	  stw       r0, 0x1C(r30)

	.loc_0x1D8:
	  li        r29, 0
	  sth       r29, 0x30(r30)
	  li        r4, 0
	  lfs       f0, -0x6194(r2)
	  stfs      f0, 0x10(r30)
	  lwz       r3, 0x30AC(r13)
	  bl        -0x17D40
	  cmplwi    r3, 0
	  beq-      .loc_0x230
	  lwz       r5, 0x94(r3)
	  addi      r0, r30, 0x20
	  lwz       r4, 0x98(r3)
	  stw       r5, 0x20(r30)
	  stw       r4, 0x24(r30)
	  lwz       r3, 0x9C(r3)
	  stw       r3, 0x28(r30)
	  lfs       f1, 0x24(r30)
	  lfs       f0, -0x61F8(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x24(r30)
	  stw       r0, 0x2EC(r31)
	  stb       r29, 0x2F0(r31)

	.loc_0x230:
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x34(r30)
	  stw       r0, 0x38(r30)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x3C(r30)
	  lwz       r0, 0x114(r1)
	  lfd       f31, 0x108(r1)
	  lfd       f30, 0x100(r1)
	  lfd       f29, 0xF8(r1)
	  lwz       r31, 0xF4(r1)
	  lwz       r30, 0xF0(r1)
	  lwz       r29, 0xEC(r1)
	  lwz       r28, 0xE8(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010A77C
 * Size:	0000DC
 */
void NaviStartingState::procCollideMsg(Navi* navi, MsgCollide*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x28(r1)
	  mr        r28, r3
	  lhz       r0, 0x30(r3)
	  cmplwi    r0, 0x2
	  beq-      .loc_0xBC
	  lwz       r3, 0x4(r5)
	  lwz       r3, 0x6C(r3)
	  bl        -0x75D7C
	  li        r0, 0x2
	  cmplwi    r29, 0
	  sth       r0, 0x30(r28)
	  mr        r30, r29
	  beq-      .loc_0x54
	  addi      r30, r30, 0x2B8

	.loc_0x54:
	  addi      r3, r1, 0x14
	  li        r4, 0x41
	  bl        0x14780
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x41
	  bl        0x147A0
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r29, 0x834
	  bl        0x1526C
	  lfs       f0, -0x2858(r13)
	  li        r0, 0
	  stfs      f0, 0x70(r29)
	  lfs       f0, -0x2854(r13)
	  stfs      f0, 0x74(r29)
	  lfs       f0, -0x2850(r13)
	  stfs      f0, 0x78(r29)
	  lfs       f0, -0x284C(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x2848(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x2844(r13)
	  stfs      f0, 0xAC(r29)
	  stb       r0, 0x32(r28)

	.loc_0xBC:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010A858
 * Size:	0002A4
 */
void NaviStartingState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stfd      f31, 0xC0(r1)
	  stfd      f30, 0xB8(r1)
	  stfd      f29, 0xB0(r1)
	  stfd      f28, 0xA8(r1)
	  stw       r31, 0xA4(r1)
	  mr        r31, r4
	  stw       r30, 0xA0(r1)
	  mr        r30, r3
	  stw       r29, 0x9C(r1)
	  stw       r28, 0x98(r1)
	  lwz       r3, 0x30AC(r13)
	  bl        -0x17C58
	  cmplwi    r3, 0
	  beq-      .loc_0x74
	  mr        r4, r3
	  lwz       r12, 0x0(r3)
	  addi      r3, r1, 0x80
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x80(r1)
	  lwz       r0, 0x84(r1)
	  stw       r3, 0x14(r30)
	  stw       r0, 0x18(r30)
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x1C(r30)

	.loc_0x74:
	  lhz       r0, 0x30(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xDC
	  bge-      .loc_0x90
	  cmpwi     r0, 0
	  bge-      .loc_0x9C
	  b         .loc_0x25C

	.loc_0x90:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x25C
	  b         .loc_0x234

	.loc_0x9C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r30)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r30)
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x6268(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x274
	  li        r0, 0x1
	  sth       r0, 0x30(r30)
	  addi      r3, r31, 0x2C4
	  lfs       f1, -0x625C(r2)
	  lfs       f2, -0x61F4(r2)
	  bl        -0x3D118
	  b         .loc_0x274

	.loc_0xDC:
	  lfs       f3, 0x14(r30)
	  lfs       f2, 0x94(r31)
	  lfs       f1, 0x18(r30)
	  lfs       f0, 0x98(r31)
	  fsubs     f31, f3, f2
	  lfs       f2, 0x1C(r30)
	  fsubs     f30, f1, f0
	  lfs       f0, 0x9C(r31)
	  fmuls     f1, f31, f31
	  fsubs     f29, f2, f0
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xFCD2C
	  lfs       f0, -0x6268(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x130
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x130:
	  lfs       f0, -0x2840(r13)
	  fmr       f28, f1
	  addi      r3, r31, 0x2C4
	  fmuls     f2, f31, f0
	  addi      r4, r31, 0x94
	  fmuls     f1, f30, f0
	  fmuls     f0, f29, f0
	  addi      r5, r30, 0x34
	  stfs      f2, 0x40(r1)
	  lfs       f2, 0x40(r1)
	  stfs      f2, 0x68(r1)
	  stfs      f1, 0x6C(r1)
	  stfs      f0, 0x70(r1)
	  lwz       r6, 0x68(r1)
	  lwz       r0, 0x6C(r1)
	  stw       r6, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x70(r1)
	  stw       r0, 0x78(r31)
	  lwz       r6, 0x70(r31)
	  lwz       r0, 0x74(r31)
	  stw       r6, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x78(r31)
	  stw       r0, 0xAC(r31)
	  bl        -0x3D1C0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1A4
	  lfs       f28, -0x6268(r2)

	.loc_0x1A4:
	  lfs       f0, -0x6190(r2)
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0x25C
	  li        r0, 0x2
	  cmplwi    r31, 0
	  sth       r0, 0x30(r30)
	  mr        r28, r31
	  beq-      .loc_0x1C8
	  addi      r28, r28, 0x2B8

	.loc_0x1C8:
	  addi      r3, r1, 0x58
	  li        r4, 0x41
	  bl        0x14530
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x60
	  li        r4, 0x41
	  bl        0x14550
	  addi      r4, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r31, 0x834
	  bl        0x1501C
	  lfs       f0, -0x283C(r13)
	  li        r0, 0
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x2838(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x2834(r13)
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x2830(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x282C(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x2828(r13)
	  stfs      f0, 0xAC(r31)
	  stb       r0, 0x32(r30)
	  b         .loc_0x25C

	.loc_0x234:
	  lbz       r0, 0x32(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x25C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x25C:
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x34(r30)
	  stw       r0, 0x38(r30)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x3C(r30)

	.loc_0x274:
	  lwz       r0, 0xCC(r1)
	  lfd       f31, 0xC0(r1)
	  lfd       f30, 0xB8(r1)
	  lfd       f29, 0xB0(r1)
	  lfd       f28, 0xA8(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  lwz       r29, 0x9C(r1)
	  lwz       r28, 0x98(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010AAFC
 * Size:	000034
 */
void NaviStartingState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x4(r5)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x1C
	  bgelr-
	  cmpwi     r0, 0
	  bnelr-

	.loc_0x1C:
	  lhz       r0, 0x30(r3)
	  cmplwi    r0, 0x2
	  bnelr-
	  li        r0, 0x1
	  stb       r0, 0x32(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010AB30
 * Size:	000084
 */
void NaviStartingState::cleanup(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r3, r3, 0x2848
	  li        r5, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  li        r4, 0xE
	  lwz       r3, 0x1E8(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x2824(r13)
	  mr        r3, r31
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x2820(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x281C(r13)
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x2818(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x2814(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x2810(r13)
	  stfs      f0, 0xAC(r31)
	  bl        -0xA1E0
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x30
	  addi      r30, r30, 0x2B8

	.loc_0x30:
	  addi      r3, r1, 0x10
	  li        r4, 0x19
	  bl        0x14328
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x19
	  bl        0x14348
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x103E4
	  lfs       f0, -0x280C(r13)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  stfs      f0, 0x70(r29)
	  li        r4, 0xE
	  li        r5, 0
	  lfs       f0, -0x2808(r13)
	  stfs      f0, 0x74(r29)
	  lfs       f0, -0x2804(r13)
	  stfs      f0, 0x78(r29)
	  lfs       f0, -0x2800(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x27FC(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x27F8(r13)
	  stfs      f0, 0xAC(r29)
	  lwz       r3, 0x1E8(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFF
	  sth       r0, 0x30C8(r13)
	  li        r0, 0
	  stb       r0, 0x10(r28)
	  lwz       r3, 0x304(r29)
	  lwz       r3, 0x55C(r3)
	  lwz       r3, 0x2C(r3)
	  bl        -0x761B8
	  addi      r3, r3, 0x1
	  li        r4, 0
	  bl        -0xEFBB8
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010ACFC
 * Size:	000050
 */
void NaviPartsAccessState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x40
	  lis       r5, 0x803A
	  subi      r5, r5, 0x2848
	  lwz       r0, 0x338(r5)
	  cmpwi     r0, 0
	  bne-      .loc_0x40
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x40:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010AD4C
 * Size:	00004C
 */
void NaviPartsAccessState::cleanup(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  sth       r0, 0x30C8(r13)
	  bl        -0xEFB60
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0xE
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010AD98
 * Size:	0000A8
 */
void NaviPartsAccessState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x2C
	  b         .loc_0x8C

	.loc_0x2C:
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x8C
	  li        r30, 0x1
	  stb       r30, 0x10(r3)
	  lwz       r29, 0x304(r4)
	  lwz       r3, 0x55C(r29)
	  lwz       r3, 0x2C(r3)
	  bl        -0x762D0
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  addi      r31, r3, 0
	  sth       r30, 0x1E2(r4)
	  extsh     r0, r31
	  sth       r0, 0x1E0(r4)
	  addi      r4, r31, 0x20
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x54
	  bl        -0x88918
	  lwz       r3, 0x2F6C(r13)
	  addi      r5, r29, 0
	  addi      r4, r31, 0x20
	  addi      r3, r3, 0x54
	  bl        -0x88904

	.loc_0x8C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x30
	  addi      r30, r30, 0x2B8

	.loc_0x30:
	  addi      r3, r1, 0x10
	  li        r4, 0x19
	  bl        0x1409C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x19
	  bl        0x140BC
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x10670
	  lfs       f0, -0x27F4(r13)
	  lis       r3, 0x1
	  subi      r5, r3, 0x7FFD
	  stfs      f0, 0x70(r29)
	  li        r0, 0
	  li        r3, 0
	  lfs       f0, -0x27F0(r13)
	  li        r4, 0
	  stfs      f0, 0x74(r29)
	  lfs       f0, -0x27EC(r13)
	  stfs      f0, 0x78(r29)
	  lfs       f0, -0x27E8(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x27E4(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x27E0(r13)
	  stfs      f0, 0xAC(r29)
	  sth       r5, 0x30C8(r13)
	  stb       r0, 0x10(r28)
	  bl        -0xEFE10
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010AF54
 * Size:	000050
 */
void NaviUfoAccessState::exec(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x40
	  lis       r5, 0x803A
	  subi      r5, r5, 0x2848
	  lwz       r0, 0x338(r5)
	  cmpwi     r0, 0
	  bne-      .loc_0x40
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x40:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010AFA4
 * Size:	000028
 */
void NaviUfoAccessState::cleanup(Navi* navi)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  sth       r0, 0x30C8(r13)
	  bl        -0xEFDB8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010AFCC
 * Size:	000078
 */
void NaviUfoAccessState::procAnimMsg(Navi* navi, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x4(r5)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x20
	  b         .loc_0x68

	.loc_0x20:
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x68
	  li        r0, 0x1
	  lis       r4, 0x803A
	  stb       r0, 0x10(r3)
	  subi      r3, r4, 0x2848
	  li        r0, 0
	  sth       r0, 0x1E2(r3)
	  li        r0, -0x1
	  li        r4, 0
	  sth       r0, 0x1E0(r3)
	  li        r5, 0x11
	  lwz       r3, 0x1E8(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x68:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010B044
 * Size:	000008
 */
bool NaviUfoAccessState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B04C
 * Size:	000008
 */
bool NaviPartsAccessState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B054
 * Size:	000008
 */
bool NaviPikiZeroState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B05C
 * Size:	000008
 */
bool NaviDeadState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B064
 * Size:	000008
 */
bool NaviPressedState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B06C
 * Size:	000008
 */
bool NaviNukuState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B074
 * Size:	000008
 */
bool NaviGeyzerState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B07C
 * Size:	000008
 */
bool NaviFlickState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B084
 * Size:	000008
 */
bool NaviContainerState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B08C
 * Size:	000004
 */
void GmWin::CloseListener::onCloseWindow() { }

/*
 * --INFO--
 * Address:	8010B090
 * Size:	000008
 */
bool NaviUfoState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B098
 * Size:	000008
 */
bool NaviBuryState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B0A0
 * Size:	000008
 */
bool NaviDemoInfState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B0A8
 * Size:	000008
 */
bool NaviDemoWaitState::invincible(Navi* navi) { return 0x1; }

/*
 * --INFO--
 * Address:	8010B0B0
 * Size:	000008
 */
bool NaviPelletState::invincible(Navi* navi) { return 0x1; }
