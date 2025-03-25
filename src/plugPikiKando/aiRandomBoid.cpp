#include "PikiAI.h"
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
DEFINE_PRINT("aiRandomBoid")

/*
 * --INFO--
 * Address:	800C0A10
 * Size:	0002F8
 */
void ActRandomBoid::AnimListener::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
		mAction->mIsAnimFinishing = 0;
		switch (mAction->mState) {
		case STATE_Boid:
			f32 angle = 2.0f * (PI * gsys->getRand(1.0f));
			if (gsys->getRand(1.0f) > 0.8f) {
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
				mPiki->setSpeed(-1.2f, Vector3f(cosf(angle), 0.0f, sinf(angle)));
				return;
			}

			if (gsys->getRand(1.0f) > 0.8f) {
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
				mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
				return;
			}

			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
			mPiki->setSpeed(0.0f, Vector3f(cosf(angle), 0.0f, sinf(angle)));
			break;
		case STATE_Stop:
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
			break;
		case STATE_Random:
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
			f32 angle2 = 2.0f * (PI * gsys->getRand(1.0f));
			mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			break;
		}
		break;
	case KEY_Action0:
		break;
	}
}

/*
 * --INFO--
 * Address:	800C0D08
 * Size:	00008C
 */
ActRandomBoid::ActRandomBoid(Piki* piki)
    : Action(piki, true)
{
	mListener = new AnimListener(this, piki);
}

/*
 * --INFO--
 * Address:	800C0D94
 * Size:	000004
 */
void ActRandomBoid::Initialiser::initialise(Action*)
{
}

/*
 * --INFO--
 * Address:	800C0D98
 * Size:	0000E8
 */
void ActRandomBoid::init(Creature*)
{
	mState      = STATE_Boid;
	mStateTimer = int((10.0f * gsys->getRand(1.0f))) + 20;
	f32 angle   = 2.0f * (PI * gsys->getRand(1.0f));
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, mListener), PaniMotionInfo(PIKIANIM_Run, mListener));
	mListener->_0C   = 0;
	mIsAnimFinishing = 0;
}

/*
 * --INFO--
 * Address:	800C0E80
 * Size:	000004
 */
void ActRandomBoid::cleanup()
{
}

/*
 * --INFO--
 * Address:	800C0E84
 * Size:	0003BC
 */
int ActRandomBoid::exec()
{
	if (mIsAnimFinishing) {
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		return ACTOUT_Continue;
	}

	if (--mStateTimer < 0) {
		mStateTimer    = int((12.0f * gsys->getRand(1.0f))) + 38;
		int startState = mState;
		if (mState == STATE_Boid && gsys->getRand(1.0f) > 0.5f) {
			mState = STATE_Idle;
			mPiki->mPikiAnimMgr.finishMotion(mListener);
			mIsAnimFinishing = 1;
			mStateTimer += int((50.0f * gsys->getRand(1.0f))) + 30;
		} else if (gsys->getRand(1.0f) > 0.65f) {
			if (gsys->getRand(1.0f) > 0.75f) {
				mState = STATE_Random;
				if (startState != STATE_Random) {
					mPiki->mPikiAnimMgr.finishMotion(mListener);
					mIsAnimFinishing = 1;
				}
			} else {
				mState = STATE_Boid;
				if (startState != STATE_Stop && startState != STATE_Boid) {
					mPiki->mPikiAnimMgr.finishMotion(mListener);
					mIsAnimFinishing = 1;
				}
			}

			f32 randomAngle = 2.0f * (PI * gsys->getRand(1.0f));
			mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			mStateTimer += 120;
		} else {
			mStateTimer += 120;
			mState = STATE_Stop;
			if (startState != STATE_Stop || startState != STATE_Boid) {
				mPiki->mPikiAnimMgr.finishMotion(mListener);
				mIsAnimFinishing = 1;
				return ACTOUT_Continue;
			}
		}

		return ACTOUT_Continue;
	}

	if (mState == STATE_Stop) {
		mStateTimer = 1;
	}

	if (mState == STATE_Idle) {
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}

	u32 badCompiler[15];
	Vector3f avoidVec;
	if (mPiki->getAvoid(mPiki->mTargetVelocity, avoidVec)) {
		mPiki->mTargetVelocity = mPiki->mTargetVelocity + mPiki->getSpeed(0.5f) * avoidVec;
	}

	return ACTOUT_Continue;

	u32 badCompiler2[58];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1C8(r1)
	  stw       r31, 0x1C4(r1)
	  mr        r31, r3
	  stw       r30, 0x1C0(r1)
	  stw       r29, 0x1BC(r1)
	  lbz       r0, 0x1C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lwz       r4, 0xC(r31)
	  li        r3, 0
	  lfs       f0, -0x45EC(r13)
	  stfsu     f0, 0xA4(r4)
	  lfs       f0, -0x45E8(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x45E4(r13)
	  stfs      f0, 0x8(r4)
	  b         .loc_0x3A0

	.loc_0x4C:
	  lwz       r3, 0x18(r31)
	  subic.    r0, r3, 0x1
	  stw       r0, 0x18(r31)
	  bge-      .loc_0x2A8
	  bl        0x157190
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0x1B4(r1)
	  lis       r30, 0x4330
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0x1B0(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0x1B0(r1)
	  lfs       f0, -0x6B7C(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x1A8(r1)
	  lwz       r3, 0x1AC(r1)
	  addi      r0, r3, 0x26
	  stw       r0, 0x18(r31)
	  lwz       r29, 0x14(r31)
	  cmpwi     r29, 0x1
	  bne-      .loc_0x160
	  bl        0x157138
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0x1AC(r1)
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0x1A8(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0x1A8(r1)
	  lfs       f0, -0x6B78(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x160
	  li        r0, 0x3
	  stw       r0, 0x14(r31)
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x24(r31)
	  addi      r3, r3, 0x354
	  bl        0x5EB3C
	  li        r0, 0x1
	  stb       r0, 0x1C(r31)
	  bl        0x1570E0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0x1AC(r1)
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0x1A8(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0x1A8(r1)
	  lfs       f0, -0x6B74(r2)
	  fsubs     f3, f3, f4
	  lwz       r3, 0x18(r31)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x1B0(r1)
	  lwz       r0, 0x1B4(r1)
	  add       r3, r0, r3
	  addi      r0, r3, 0x1E
	  stw       r0, 0x18(r31)
	  b         .loc_0x2A0

	.loc_0x160:
	  bl        0x15708C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0x1AC(r1)
	  lis       r30, 0x4330
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0x1A8(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0x1A8(r1)
	  lfs       f0, -0x6B70(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x25C
	  bl        0x157050
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0x1AC(r1)
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0x1A8(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0x1A8(r1)
	  lfs       f0, -0x6B6C(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x200
	  li        r0, 0
	  cmpwi     r29, 0
	  stw       r0, 0x14(r31)
	  beq-      .loc_0x22C
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x24(r31)
	  addi      r3, r3, 0x354
	  bl        0x5EA4C
	  li        r0, 0x1
	  stb       r0, 0x1C(r31)
	  b         .loc_0x22C

	.loc_0x200:
	  li        r30, 0x1
	  cmpwi     r29, 0x2
	  stw       r30, 0x14(r31)
	  beq-      .loc_0x22C
	  cmpwi     r29, 0x1
	  beq-      .loc_0x22C
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x24(r31)
	  addi      r3, r3, 0x354
	  bl        0x5EA18
	  stb       r30, 0x1C(r31)

	.loc_0x22C:
	  bl        0x156FC0
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x45E0(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x45DC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x45D8(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x18(r31)
	  addi      r0, r3, 0x78
	  stw       r0, 0x18(r31)
	  b         .loc_0x2A0

	.loc_0x25C:
	  lwz       r3, 0x18(r31)
	  cmpwi     r29, 0x2
	  li        r0, 0x2
	  addi      r3, r3, 0x78
	  stw       r3, 0x18(r31)
	  stw       r0, 0x14(r31)
	  bne-      .loc_0x280
	  cmpwi     r29, 0x1
	  beq-      .loc_0x2A0

	.loc_0x280:
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x24(r31)
	  addi      r3, r3, 0x354
	  bl        0x5E9B0
	  li        r0, 0x1
	  stb       r0, 0x1C(r31)
	  li        r3, 0
	  b         .loc_0x3A0

	.loc_0x2A0:
	  li        r3, 0
	  b         .loc_0x3A0

	.loc_0x2A8:
	  lwz       r0, 0x14(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x2BC
	  li        r0, 0x1
	  stw       r0, 0x18(r31)

	.loc_0x2BC:
	  lwz       r0, 0x14(r31)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x2E4
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x45D4(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x45D0(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x45CC(r13)
	  stfs      f0, 0x8(r3)

	.loc_0x2E4:
	  lfs       f0, -0x6B90(r2)
	  addi      r5, r1, 0x15C
	  stfs      f0, 0x164(r1)
	  stfs      f0, 0x160(r1)
	  stfs      f0, 0x15C(r1)
	  lwz       r3, 0xC(r31)
	  addi      r4, r3, 0xA4
	  bl        -0x33C48
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x39C
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x6B78(r2)
	  bl        0xABCC
	  lfs       f0, 0x15C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0x110(r1)
	  lfs       f0, 0x160(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x114(r1)
	  lfs       f0, 0x164(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x118(r1)
	  lwz       r3, 0xC(r31)
	  lfs       f0, 0x110(r1)
	  lfs       f1, 0xA4(r3)
	  addi      r4, r3, 0xA4
	  fadds     f0, f1, f0
	  stfs      f0, 0xF8(r1)
	  lfs       f0, 0xF8(r1)
	  stfs      f0, 0x11C(r1)
	  lfs       f1, 0xA8(r3)
	  lfs       f0, 0x114(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x120(r1)
	  lfs       f1, 0xAC(r3)
	  lfs       f0, 0x118(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x124(r1)
	  lwz       r3, 0x11C(r1)
	  lwz       r0, 0x120(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x124(r1)
	  stw       r0, 0x8(r4)

	.loc_0x39C:
	  li        r3, 0

	.loc_0x3A0:
	  lwz       r0, 0x1CC(r1)
	  lwz       r31, 0x1C4(r1)
	  lwz       r30, 0x1C0(r1)
	  lwz       r29, 0x1BC(r1)
	  addi      r1, r1, 0x1C8
	  mtlr      r0
	  blr
	*/
}

static char* stateName[] = {
	"ランダム", // 'random'
	"Boid",
	"停止", // 'stop'
};

/*
 * --INFO--
 * Address:	800C1240
 * Size:	000044
 */
void ActRandomBoid::getInfo(char* buf)
{
	sprintf(buf, "%s", stateName[mState]);
}
