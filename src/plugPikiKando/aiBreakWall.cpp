#include "PikiAI.h"
#include "PikiState.h"
#include "BuildingItem.h"
#include "AIPerf.h"
#include "UtEffect.h"
#include "gameflow.h"
#include "Interactions.h"
#include "FlowController.h"
#include "Dolphin/os.h"
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
DEFINE_PRINT("aiBreakWall")

/*
 * --INFO--
 * Address:	800AE13C
 * Size:	000070
 */
ActBreakWall::ActBreakWall(Piki* piki)
    : Action(piki, true)
{
	setName("breakWall");
}

/*
 * --INFO--
 * Address:	800AE1AC
 * Size:	000154
 */
void ActBreakWall::init(Creature* creature)
{
	_31             = 0;
	mPiki->_408     = 2;
	mPiki->mEmotion = 0;

	if (creature->isSluice()) {
		mWall = static_cast<BuildingItem*>(creature);
	} else {
		mWall = nullptr;
	}

	mState              = STATE_GotoWall;
	_32                 = 0;
	mPiki->mWantToStick = 0;
	_30                 = randFloat(4.0f);
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	800AE300
 * Size:	0000C4
 */
void ActBreakWall::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (piki->getState() != PIKISTATE_LookAt) {
		// Creature* collider = msg->mEvent.mCollider;
		if (msg->mEvent.mCollider == mWall && mState != STATE_BreakWall && msg->mEvent.mColliderPart->getID() == 'gate'
		    && !piki->isStickTo()) {
			_20 = piki->mPosition;
			initBreakWall();
		}
		// msg->mEvent.mCollider->isPiki();
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r3, r29, 0
	  bl        0x1A228
	  cmpwi     r3, 0x1A
	  beq-      .loc_0xA4
	  lwz       r31, 0x4(r30)
	  lwz       r0, 0x18(r28)
	  cmplw     r31, r0
	  bne-      .loc_0xA4
	  lhz       r0, 0x1C(r28)
	  cmplwi    r0, 0x1
	  beq-      .loc_0xA4
	  addi      r3, r1, 0x14
	  lwz       r4, 0x8(r30)
	  bl        -0x264BC
	  lis       r4, 0x6761
	  addi      r3, r1, 0x14
	  addi      r4, r4, 0x7465
	  bl        -0x6A38C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA4
	  lwz       r0, 0x184(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0xA4
	  lwz       r4, 0x94(r29)
	  mr        r3, r28
	  lwz       r0, 0x98(r29)
	  stw       r4, 0x20(r28)
	  stw       r0, 0x24(r28)
	  lwz       r0, 0x9C(r29)
	  stw       r0, 0x28(r28)
	  bl        0x3E4

	.loc_0xA4:
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
 * Address:	800AE3C4
 * Size:	000190
 */
void ActBreakWall::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		_32 = 1;
		break;
	case KEY_Action1:
		_32 = 0;
		break;
	case KEY_Finished:
		_30 = randFloat(4.0f);
		startWorkMotion();
		_32 = 0;
		break;
	case KEY_PlayEffect:
		if (!mPiki->isCreatureFlag(CF_IsAICullingActive) && (AIPerf::optLevel <= 0 || mPiki->mOptUpdateContext.updatable())) {
			Vector3f vec = mPiki->mEffectPos;
			EffectParm parm(vec);
			if (mWall->mObjType == OBJTYPE_SluiceSoft) {
				UtEffectMgr::cast(11, parm);
			} else if (mWall->mObjType == OBJTYPE_SluiceHard) {
				UtEffectMgr::cast(13, parm);
			} else {
				UtEffectMgr::cast(14, parm);
			}
		}
		break;
	}

	u32 badCompiler;
}

/*
 * --INFO--
 * Address:	800AE554
 * Size:	000148
 */
int ActBreakWall::exec()
{
	if (!mWall || !mWall->isAlive()) {
		return ACTOUT_Fail;
	}

	switch (mState) {
	case STATE_GotoWall:
		return gotoWall();

	case STATE_BreakWall:
		Vector3f sep = _20 - mPiki->mPosition;
		if (sep.length() > 5.0f) {
			mState = STATE_GotoWall;
			break;
		}
		return breakWall();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AE6BC
 * Size:	0000C8
 */
int ActBreakWall::gotoWall()
{
	Vector3f direction = mWall->mPosition - mPiki->mPosition;
	direction.normalise();
	mPiki->setSpeed(1.0f, direction);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AE784
 * Size:	000090
 */
void ActBreakWall::initBreakWall()
{
	_30 = randFloat(4.0f);
	startWorkMotion();
	mState = STATE_BreakWall;
	_2C    = gameflow.mWorldClock.mMinutes;
}

/*
 * --INFO--
 * Address:	800AE814
 * Size:	0000F4
 */
void ActBreakWall::startWorkMotion()
{
	if (_30 == 0) {
		if (mPiki->getCollidePlatformCreature()) {
			Vector3f normal = mPiki->getCollidePlatformNormal();
			if (normal.y > 0.7f) {
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Job2, this), PaniMotionInfo(PIKIANIM_Job2));
				return;
			}
		}
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
	}
}

/*
 * --INFO--
 * Address:	800AE908
 * Size:	0002E4
 */
int ActBreakWall::breakWall()
{
	if (_30 != 0) {
		_30--;
		if (_30 == 0) {
			startWorkMotion();
		}
		return ACTOUT_Continue;
	}

	int val = (gameflow.mWorldClock.mMinutes - _2C + 60) % 60;
	if (flowCont.mCurrentStage->mStageID == STAGE_Practice) {
		val = 1;
	}

	if (val > 0 && _32) {
		InteractAttack attack(mPiki, nullptr, val / 60.0f, false);
		_32 = 0;
		if (!mWall->stimulate(attack)) {
			if (mWall->isCompleted()) {
				return ACTOUT_Success;
			}
			_31++;
			if (_31 >= int(randFloat(3.0f)) + 3) {
				mPiki->mEmotion = 1;
				mPiki->_408     = 0;
				return ACTOUT_Fail;
			}
		}

		_2C = gameflow.mWorldClock.mMinutes;
	}

	mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AEC08
 * Size:	000004
 */
void ActBreakWall::cleanup()
{
}
