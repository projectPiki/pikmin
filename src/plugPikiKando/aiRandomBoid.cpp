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
			f32 angle = 2.0f * randFloat(PI);
			if (System::getRand(1.0f) > 0.8f) {
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
				mPiki->setSpeed(-1.2f, Vector3f(cosf(angle), 0.0f, sinf(angle)));
				return;
			}

			if (System::getRand(1.0f) > 0.8f) {
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
			f32 angle2 = 2.0f * randFloat(PI);
			mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			break;
		}
		break;
	case KEY_Action0:
		break;
	}

	u32 badCompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stfd      f31, 0xC0(r1)
	  stfd      f30, 0xB8(r1)
	  stw       r31, 0xB4(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xB0(r1)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2D8
	  bge-      .loc_0x2D8
	  cmpwi     r0, 0
	  bge-      .loc_0x3C
	  b         .loc_0x2D8

	.loc_0x3C:
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stb       r0, 0x1C(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x14(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x74
	  bge-      .loc_0x68
	  cmpwi     r0, 0
	  bge-      .loc_0x288
	  b         .loc_0x2D8

	.loc_0x68:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x2D8
	  b         .loc_0x254

	.loc_0x74:
	  bl        0x1575EC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0xAC(r1)
	  lis       r30, 0x4330
	  lfs       f3, -0x6BA4(r2)
	  stw       r30, 0xA8(r1)
	  lfs       f2, -0x6BA8(r2)
	  lfd       f1, 0xA8(r1)
	  lfs       f0, -0x6B9C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6BA0(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f31, f1, f0
	  bl        0x1575AC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0xA4(r1)
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0xA0(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0xA0(r1)
	  lfs       f0, -0x6B98(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x15C
	  addi      r3, r1, 0x8C
	  li        r4, 0
	  bl        0x5E454
	  addi      r30, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x94
	  li        r4, 0
	  bl        0x5E474
	  mr        r4, r3
	  lwz       r3, 0x8(r31)
	  mr        r5, r30
	  bl        0x9EB0
	  fmr       f1, f31
	  bl        0x15B1B8
	  fmr       f30, f1
	  fmr       f1, f31
	  bl        0x15B018
	  stfs      f1, 0x7C(r1)
	  addi      r4, r1, 0x80
	  lfs       f0, -0x4618(r13)
	  lfs       f2, 0x7C(r1)
	  lfs       f1, -0x6B94(r2)
	  stfs      f2, 0x80(r1)
	  stfs      f0, 0x84(r1)
	  stfs      f30, 0x88(r1)
	  lwz       r3, 0x8(r31)
	  bl        0xB274
	  b         .loc_0x2D8

	.loc_0x15C:
	  bl        0x157504
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0xA4(r1)
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0xA0(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0xA0(r1)
	  lfs       f0, -0x6B98(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1E4
	  addi      r3, r1, 0x6C
	  li        r4, 0
	  bl        0x5E3AC
	  addi      r30, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x74
	  li        r4, 0
	  bl        0x5E3CC
	  mr        r4, r3
	  lwz       r3, 0x8(r31)
	  mr        r5, r30
	  bl        0x9E08
	  lwz       r3, 0x8(r31)
	  lfs       f0, -0x4614(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4610(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x460C(r13)
	  stfs      f0, 0x8(r3)
	  b         .loc_0x2D8

	.loc_0x1E4:
	  addi      r3, r1, 0x5C
	  li        r4, 0
	  bl        0x5E35C
	  addi      r30, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x64
	  li        r4, 0
	  bl        0x5E37C
	  mr        r4, r3
	  lwz       r3, 0x8(r31)
	  mr        r5, r30
	  bl        0x9DB8
	  fmr       f1, f31
	  bl        0x15B0C0
	  fmr       f30, f1
	  fmr       f1, f31
	  bl        0x15AF20
	  stfs      f1, 0x4C(r1)
	  addi      r4, r1, 0x50
	  lfs       f0, -0x4608(r13)
	  lfs       f2, 0x4C(r1)
	  lfs       f1, -0x6B90(r2)
	  stfs      f2, 0x50(r1)
	  stfs      f0, 0x54(r1)
	  stfs      f30, 0x58(r1)
	  lwz       r3, 0x8(r31)
	  bl        0xB17C
	  b         .loc_0x2D8

	.loc_0x254:
	  addi      r3, r1, 0x3C
	  li        r4, 0
	  bl        0x5E2EC
	  addi      r30, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x44
	  li        r4, 0
	  bl        0x5E30C
	  mr        r4, r3
	  lwz       r3, 0x8(r31)
	  mr        r5, r30
	  bl        0x9D48
	  b         .loc_0x2D8

	.loc_0x288:
	  addi      r3, r1, 0x2C
	  li        r4, 0
	  bl        0x5E2B8
	  addi      r30, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x34
	  li        r4, 0
	  bl        0x5E2D8
	  mr        r4, r3
	  lwz       r3, 0x8(r31)
	  mr        r5, r30
	  bl        0x9D14
	  bl        0x1573A8
	  lwz       r3, 0x8(r31)
	  lfs       f0, -0x4604(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4600(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x45FC(r13)
	  stfs      f0, 0x8(r3)

	.loc_0x2D8:
	  lwz       r0, 0xCC(r1)
	  lfd       f31, 0xC0(r1)
	  lfd       f30, 0xB8(r1)
	  lwz       r31, 0xB4(r1)
	  lwz       r30, 0xB0(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
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
	mStateTimer = int(randFloat(10.0f)) + 20;
	f32 angle   = 2.0f * randFloat(PI);
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
		mStateTimer    = int(randFloat(12.0f)) + 38;
		int startState = mState;
		if (mState == STATE_Boid && System::getRand(1.0f) > 0.5f) {
			mState = STATE_Idle;
			mPiki->mPikiAnimMgr.finishMotion(mListener);
			mIsAnimFinishing = 1;
			mStateTimer += int(randFloat(50.0f)) + 30;
		} else if (System::getRand(1.0f) > 0.65f) {
			if (System::getRand(1.0f) > 0.75f) {
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

			f32 randomAngle = 2.0f * randFloat(PI);
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

	u32 badCompiler2[61];
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
