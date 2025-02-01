#include "PikiAI.h"
#include "FormationMgr.h"
#include "Navi.h"
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
DEFINE_PRINT("aiFormation")

/*
 * --INFO--
 * Address:	800B98D8
 * Size:	00032C
 */
void ActFormation::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		break;

	case KEY_Finished:
		if (_29 || _2A) {
			if (_2A) {
				_1C = randFloat(15.0f) + 15.0f;
				_2A = 0;
			}
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait, this), PaniMotionInfo(PIKIANIM_Wait));
			break;
		}

		if (mHasTripped == 0) {
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Korobu, this), PaniMotionInfo(PIKIANIM_Korobu));
			Vector3f dir(sinf(mPiki->mFaceDirection), 0.0f, cosf(mPiki->mFaceDirection));
			f32 speed              = mPiki->mVelocity.length();
			mPiki->mVelocity       = speed * dir;
			mPiki->mTargetVelocity = speed * dir;
			_1C                    = unitRandFloat() + 0.8f;
			mHasTripped            = 1;
			break;
		}

		if (mHasTripped == 1) {
			_2B = 0;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
			break;
		}

		if (_2C) {
			_2C = 0;
			if (_24 > 5.0f) {
				mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
			}
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
	  stfd      f29, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xD0(r1)
	  stw       r29, 0xCC(r1)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x44
	  bge-      .loc_0x304
	  cmpwi     r0, 0
	  bge-      .loc_0x80
	  b         .loc_0x304

	.loc_0x44:
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4918(r13)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x4914(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4910(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x490C(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4908(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4904(r13)
	  stfs      f0, 0x8(r3)
	  b         .loc_0x304

	.loc_0x80:
	  lbz       r0, 0x29(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x98
	  lbz       r0, 0x2A(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x130

	.loc_0x98:
	  lbz       r0, 0x2A(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xEC
	  bl        0x15E6F4
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6D50(r2)
	  stw       r0, 0xC4(r1)
	  lis       r3, 0x4330
	  lfs       f2, -0x6D64(r2)
	  li        r0, 0
	  stw       r3, 0xC0(r1)
	  lfs       f0, -0x6D68(r2)
	  lfd       f3, 0xC0(r1)
	  lfs       f1, -0x6D60(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r31)
	  stb       r0, 0x2A(r31)

	.loc_0xEC:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0xFC
	  addi      r29, r29, 0x14

	.loc_0xFC:
	  addi      r3, r1, 0x9C
	  li        r4, 0x3
	  bl        0x6557C
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0xA4
	  li        r4, 0x3
	  bl        0x6559C
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x10FD8
	  b         .loc_0x304

	.loc_0x130:
	  lwz       r0, 0x30(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x274
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x14C
	  addi      r29, r29, 0x14

	.loc_0x14C:
	  addi      r3, r1, 0x8C
	  li        r4, 0x14
	  bl        0x6552C
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x94
	  li        r4, 0x14
	  bl        0x6554C
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x10F88
	  lwz       r3, 0xC(r31)
	  lfs       f1, 0xA0(r3)
	  bl        0x1620F8
	  lwz       r3, 0xC(r31)
	  fmr       f30, f1
	  lfs       f1, 0xA0(r3)
	  bl        0x16227C
	  lwz       r3, 0xC(r31)
	  fmr       f31, f1
	  lfsu      f1, 0x70(r3)
	  lfs       f29, -0x4900(r13)
	  lfs       f0, 0x4(r3)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r3)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xABE5C
	  fmuls     f2, f31, f1
	  fmuls     f3, f29, f1
	  fmuls     f1, f30, f1
	  stfs      f2, 0x48(r1)
	  lfs       f0, 0x48(r1)
	  stfs      f0, 0x80(r1)
	  stfs      f3, 0x84(r1)
	  stfs      f1, 0x88(r1)
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x80(r1)
	  lwz       r0, 0x84(r1)
	  stw       r3, 0x70(r4)
	  stw       r0, 0x74(r4)
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x78(r4)
	  stfs      f2, 0x74(r1)
	  stfs      f3, 0x78(r1)
	  stfs      f1, 0x7C(r1)
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x74(r1)
	  lwz       r0, 0x78(r1)
	  stw       r3, 0xA4(r4)
	  stw       r0, 0xA8(r4)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0xAC(r4)
	  bl        0x15E56C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6D50(r2)
	  stw       r0, 0xC4(r1)
	  lis       r3, 0x4330
	  lfs       f2, -0x6D64(r2)
	  li        r0, 0x1
	  stw       r3, 0xC0(r1)
	  lfs       f1, -0x6D68(r2)
	  lfd       f3, 0xC0(r1)
	  lfs       f0, -0x6D5C(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fadds     f0, f0, f1
	  stfs      f0, 0x1C(r31)
	  stw       r0, 0x30(r31)
	  b         .loc_0x304

	.loc_0x274:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x2B4
	  li        r0, 0
	  stb       r0, 0x2B(r31)
	  addi      r3, r1, 0x64
	  li        r4, 0
	  bl        0x653F4
	  addi      r30, r3, 0
	  addi      r3, r1, 0x6C
	  li        r4, 0
	  bl        0x653E4
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x10E54
	  b         .loc_0x304

	.loc_0x2B4:
	  lbz       r0, 0x2C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x304
	  li        r0, 0
	  stb       r0, 0x2C(r31)
	  lfs       f1, 0x24(r31)
	  lfs       f0, -0x6D58(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x304
	  addi      r3, r1, 0x54
	  li        r4, 0
	  bl        0x653A0
	  addi      r30, r3, 0
	  addi      r3, r1, 0x5C
	  li        r4, 0
	  bl        0x65390
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x10E00

	.loc_0x304:
	  lwz       r0, 0xF4(r1)
	  lfd       f31, 0xE8(r1)
	  lfd       f30, 0xE0(r1)
	  lfd       f29, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  lwz       r29, 0xCC(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B9C04
 * Size:	00005C
 */
ActFormation::ActFormation(Piki* piki)
    : Action(piki, true)
{
	mFormMgr = nullptr;
}

/*
 * --INFO--
 * Address:	800B9C60
 * Size:	000148
 */
void ActFormation::getFormPoint()
{
	mPiki->mFormPoint = mFormMgr->getFormPoint(mPiki);
	PRINT("piki %x got formPt %x owner is %x\n", mPiki, mPiki->mFormPoint, mPiki->mFormPoint->getOwner());

	Iterator iter(mFormMgr);
	CI_LOOP(iter)
	{
		Creature* member = *iter;
		if (member->mFormPoint == mPiki->mFormPoint && mPiki != member) {
			PRINT("########################################\n");
			PRINT(" creature %x and piki %x share same formPoint %x\n", member, mPiki, member->mFormPoint);
			PRINT(" owner is %x\n", member->mFormPoint->getOwner());
			while (true) {
				// bad code gets locked in the INFINITE WHILE LOOP
				;
			}
		}
	}
	_28 = 0;
}

/*
 * --INFO--
 * Address:	800B9DA8
 * Size:	0000F4
 */
void ActFormation::init(Creature* target)
{
	if (mPiki->isKinoko()) {
		ERROR("formation kinoko!");
	}

	mInFormation = 1;

	if (target->mObjType != OBJTYPE_Navi) {
		PRINT("target is not navi (%d)\n", target->mObjType);
	}

	Navi* navi = static_cast<Navi*>(target);
	mFormMgr   = navi->mFormMgr;
	_28        = 1;
	_1C        = randFloat(2.0f) + 4.0f;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
	mPiki->unsetPastel();
	_29         = 0;
	_2A         = 0;
	_2B         = 0;
	mHasTripped = 0;
}

/*
 * --INFO--
 * Address:	800B9E9C
 * Size:	00004C
 */
void ActFormation::cleanup()
{
	if (mFormMgr) {
		mFormMgr->exit(mPiki);
		mPiki->mFormPoint = nullptr;
		mFormMgr          = nullptr;
	}
}

/*
 * --INFO--
 * Address:	800B9EE8
 * Size:	0006A4
 */
int ActFormation::exec()
{
	if (_2B) {
		_1C -= gsys->getFrameTime();
		if (_1C < 0.0f) {
			mPiki->mPikiAnimMgr.finishMotion(this);
		}

		return ACTOUT_Continue;
	}

	Vector3f pos;
	if (_28) {
		pos = mFormMgr->getLastCentre();
	} else {
		pos = mPiki->mFormPoint->getPos();
	}

	Vector3f dir = pos - mPiki->mPosition;
	f32 dist     = dir.length();
	_24          = dist;
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	if (_28 && dist < 100.0f) {
		getFormPoint();
	} else if (!_28 && dist < 6.0f) {
		mInFormation = false;
		mPiki->mFaceDirection += 2.5f * (angDist(mPiki->mNavi->mFaceDirection, mPiki->mFaceDirection) * gsys->getFrameTime());

		if (!_29) {
			mPiki->mPikiAnimMgr.finishMotion(this);
			_29 = 1;
			_1C = randFloat(15.0f) + 15.0f;
			_2A = 0;
		} else {
			_1C -= gsys->getFrameTime();
			if (_1C < 0.0f && !_2A) {
				// this is set up for far more flexibility than it ended up having wtf
				int baseIdx[1]    = { PIKIANIM_Wait };
				int randOffsetIdx = int(randFloat(1.0f));
				if (randOffsetIdx >= 1) {
					randOffsetIdx = 0;
				}
				mPiki->startMotion(PaniMotionInfo(baseIdx[randOffsetIdx], this), PaniMotionInfo(baseIdx[randOffsetIdx]));
				_2A = 1;
			}
		}

		return ACTOUT_Continue;
	}

	if (!_29 && !_2B && unitRandFloat() > 0.99f && unitRandFloat() > 0.99f && mPiki->mVelocity.length() > mPiki->getSpeed(0.5f)) {
		mPiki->mPikiAnimMgr.finishMotion(this);
		mHasTripped = 0;
		_2B         = 1;
		return ACTOUT_Continue;
	}

	if (_29) {
		_29 = 0;
		_2C = 0;
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
	}
	u32 badCompiler;
	Vector3f zero(0.0f, 0.0f, 0.0f);
	Vector3f dir2 = pos - mPiki->mPosition;
	dir2.normalise();

	Vector3f sideDir(-dir2.z, 0.0f, dir2.x);
	bool unusedCheck = false;
	Vector3f dir3    = pos - mPiki->mPosition;
	dir3.y           = 0.0f;
	f32 dist3        = dir3.length();
	if (dist3 > 0.0f) {
		dir3 = (1.0f / dist3) * dir3;
	} else {
		f32 randAngle = 2.0f * randFloat(PI);
		dir3.set(cosf(randAngle), 0.0f, sinf(randAngle));
	}

	f32 speedRatio = 0.0f;
	if (dist3 > 30.0f) {
		speedRatio = (dist3 - 30.0f) / 10.0f;
		if (speedRatio > 1.0f) {
			speedRatio = 1.0f;
		}
	}

	mPiki->setSpeed(speedRatio, dir3);
	f32 factor = 1.0f;
	if (unusedCheck) {
		mPiki->mTargetVelocity = (1.0f - factor) * mPiki->mTargetVelocity + factor * zero;
	}

	return ACTOUT_Continue;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x230(r1)
	  stfd      f31, 0x228(r1)
	  stfd      f30, 0x220(r1)
	  stfd      f29, 0x218(r1)
	  stw       r31, 0x214(r1)
	  mr        r31, r3
	  stw       r30, 0x210(r1)
	  stw       r29, 0x20C(r1)
	  stw       r28, 0x208(r1)
	  lbz       r0, 0x2B(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x80
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x1C(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1C(r31)
	  lfs       f1, 0x1C(r31)
	  lfs       f0, -0x6D48(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x78
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x6C
	  addi      r4, r4, 0x14

	.loc_0x6C:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x65B64

	.loc_0x78:
	  li        r3, 0
	  b         .loc_0x678

	.loc_0x80:
	  lfs       f0, -0x6D48(r2)
	  stfs      f0, 0x1E8(r1)
	  stfs      f0, 0x1E4(r1)
	  stfs      f0, 0x1E0(r1)
	  lbz       r0, 0x28(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xAC
	  addi      r3, r1, 0x1E0
	  lwz       r4, 0x20(r31)
	  bl        -0x3BF14
	  b         .loc_0xBC

	.loc_0xAC:
	  lwz       r4, 0xC(r31)
	  addi      r3, r1, 0x1E0
	  lwz       r4, 0x28(r4)
	  bl        -0x3C008

	.loc_0xBC:
	  lwz       r3, 0xC(r31)
	  lfs       f3, 0x1E4(r1)
	  addi      r3, r3, 0x94
	  lfs       f1, 0x1E0(r1)
	  lfs       f2, 0x4(r3)
	  lfs       f0, 0x0(r3)
	  fsubs     f4, f3, f2
	  lfs       f2, 0x1E8(r1)
	  fsubs     f5, f1, f0
	  lfs       f1, 0x8(r3)
	  lfs       f0, -0x6D48(r2)
	  fsubs     f3, f2, f1
	  fmuls     f2, f5, f5
	  fmuls     f1, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x160
	  fsqrte    f1, f4
	  lfd       f3, -0x6D40(r2)
	  lfd       f2, -0x6D38(r2)
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

	.loc_0x160:
	  stfs      f4, 0x24(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x48FC(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x48F8(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x48F4(r13)
	  stfs      f0, 0x8(r3)
	  lbz       r0, 0x28(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A4
	  lfs       f0, -0x6D24(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x1A4
	  mr        r3, r31
	  bl        -0x424
	  b         .loc_0x35C

	.loc_0x1A4:
	  cmplwi    r0, 0
	  bne-      .loc_0x35C
	  lfs       f0, -0x6D20(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x35C
	  li        r0, 0
	  stb       r0, 0x18(r31)
	  lwz       r5, 0xC(r31)
	  lwz       r4, 0x2DEC(r13)
	  lwz       r3, 0x504(r5)
	  lfs       f30, 0x28C(r4)
	  lfs       f1, 0xA0(r3)
	  lfs       f2, 0xA0(r5)
	  bl        -0x81B0C
	  fmuls     f1, f1, f30
	  lfs       f0, -0x6D1C(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f1, f0, f1
	  lfs       f0, 0xA0(r3)
	  fadds     f0, f0, f1
	  stfs      f0, 0xA0(r3)
	  lbz       r0, 0x29(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x274
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x214
	  addi      r4, r4, 0x14

	.loc_0x214:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x659BC
	  li        r0, 0x1
	  stb       r0, 0x29(r31)
	  bl        0x15DF60
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6D50(r2)
	  stw       r0, 0x204(r1)
	  lis       r3, 0x4330
	  lfs       f2, -0x6D64(r2)
	  li        r0, 0
	  stw       r3, 0x200(r1)
	  lfs       f0, -0x6D68(r2)
	  lfd       f3, 0x200(r1)
	  lfs       f1, -0x6D60(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r31)
	  stb       r0, 0x2A(r31)
	  b         .loc_0x354

	.loc_0x274:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x1C(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1C(r31)
	  lfs       f1, 0x1C(r31)
	  lfs       f0, -0x6D48(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x354
	  lbz       r0, 0x2A(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x354
	  lwz       r0, -0x6D28(r2)
	  stw       r0, 0x1CC(r1)
	  bl        0x15DEDC
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x6D50(r2)
	  stw       r0, 0x204(r1)
	  lis       r0, 0x4330
	  lfs       f1, -0x6D64(r2)
	  stw       r0, 0x200(r1)
	  lfs       f0, -0x6D68(r2)
	  lfd       f2, 0x200(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f1, f0, f1
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x1F0(r1)
	  lwz       r0, 0x1F4(r1)
	  stfd      f0, 0x1F8(r1)
	  cmpwi     r0, 0x1
	  lwz       r0, 0x1FC(r1)
	  blt-      .loc_0x300
	  li        r0, 0

	.loc_0x300:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x310
	  addi      r29, r29, 0x14

	.loc_0x310:
	  rlwinm    r0,r0,2,0,29
	  addi      r3, r1, 0x1CC
	  lwzx      r28, r3, r0
	  addi      r3, r1, 0x170
	  addi      r4, r28, 0
	  bl        0x64D4C
	  addi      r30, r3, 0
	  addi      r4, r28, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x178
	  bl        0x64D6C
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x107A8
	  li        r0, 0x1
	  stb       r0, 0x2A(r31)

	.loc_0x354:
	  li        r3, 0
	  b         .loc_0x678

	.loc_0x35C:
	  lbz       r0, 0x29(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x45C
	  lbz       r0, 0x2B(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x45C
	  bl        0x15DE14
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6D50(r2)
	  stw       r0, 0x1F4(r1)
	  lis       r30, 0x4330
	  lfs       f2, -0x6D64(r2)
	  stw       r30, 0x1F0(r1)
	  lfs       f1, -0x6D68(r2)
	  lfd       f3, 0x1F0(r1)
	  lfs       f0, -0x6D18(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x45C
	  bl        0x15DDD8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6D50(r2)
	  stw       r0, 0x1F4(r1)
	  lfs       f2, -0x6D64(r2)
	  stw       r30, 0x1F0(r1)
	  lfs       f1, -0x6D68(r2)
	  lfd       f3, 0x1F0(r1)
	  lfs       f0, -0x6D18(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x45C
	  lwz       r3, 0xC(r31)
	  lfsu      f1, 0x70(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r3)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xAC6B4
	  fmr       f30, f1
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x6D14(r2)
	  bl        0x11A60
	  fcmpo     cr0, f30, f1
	  ble-      .loc_0x45C
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x438
	  addi      r4, r4, 0x14

	.loc_0x438:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x65798
	  li        r0, 0
	  stw       r0, 0x30(r31)
	  li        r0, 0x1
	  li        r3, 0
	  stb       r0, 0x2B(r31)
	  b         .loc_0x678

	.loc_0x45C:
	  lbz       r0, 0x29(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x4A0
	  li        r0, 0
	  stb       r0, 0x29(r31)
	  addi      r3, r1, 0x160
	  li        r4, 0
	  stb       r0, 0x2C(r31)
	  bl        0x64BF4
	  addi      r30, r3, 0
	  addi      r3, r1, 0x168
	  li        r4, 0
	  bl        0x64BE4
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x10654

	.loc_0x4A0:
	  lwz       r3, 0xC(r31)
	  lfsu      f1, 0x94(r3)
	  lfs       f3, 0x1E0(r1)
	  lfs       f2, 0x1E4(r1)
	  lfs       f0, 0x4(r3)
	  fsubs     f3, f3, f1
	  lfs       f1, 0x1E8(r1)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x8(r3)
	  fsubs     f4, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f3, f3
	  fmuls     f2, f4, f4
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xAC784
	  lwz       r3, 0xC(r31)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x1E0(r1)
	  lfs       f3, 0x1E4(r1)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x1E8(r1)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x194(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x198(r1)
	  stfs      f0, 0x19C(r1)
	  lfs       f3, -0x6D48(r2)
	  stfs      f3, 0x198(r1)
	  lfs       f1, 0x194(r1)
	  lfs       f0, 0x198(r1)
	  lfs       f2, 0x19C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f31, f2, f0
	  fcmpo     cr0, f31, f3
	  ble-      .loc_0x59C
	  fsqrte    f1, f31
	  lfd       f3, -0x6D40(r2)
	  lfd       f2, -0x6D38(r2)
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
	  stfs      f0, 0xE0(r1)
	  lfs       f31, 0xE0(r1)

	.loc_0x59C:
	  lfs       f0, -0x6D48(r2)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x5D8
	  lfs       f1, -0x6D68(r2)
	  lfs       f0, 0x194(r1)
	  fdivs     f3, f1, f31
	  lfs       f1, 0x198(r1)
	  lfs       f2, 0x19C(r1)
	  fmuls     f0, f0, f3
	  fmuls     f4, f1, f3
	  fmuls     f1, f2, f3
	  stfs      f0, 0x194(r1)
	  stfs      f4, 0x198(r1)
	  stfs      f1, 0x19C(r1)
	  b         .loc_0x63C

	.loc_0x5D8:
	  bl        0x15DBB0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6D50(r2)
	  stw       r0, 0x1F4(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x6D64(r2)
	  stw       r0, 0x1F0(r1)
	  lfs       f2, -0x6D68(r2)
	  lfd       f1, 0x1F0(r1)
	  lfs       f0, -0x6D10(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6D2C(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f29, f1, f0
	  fmr       f1, f29
	  bl        0x1617E4
	  fmr       f30, f1
	  fmr       f1, f29
	  bl        0x161644
	  stfs      f1, 0x194(r1)
	  lfs       f0, -0x48F0(r13)
	  stfs      f0, 0x198(r1)
	  stfs      f30, 0x19C(r1)

	.loc_0x63C:
	  lfs       f0, -0x6D0C(r2)
	  lfs       f1, -0x6D48(r2)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x668
	  fsubs     f2, f31, f0
	  lfs       f1, -0x6D08(r2)
	  lfs       f0, -0x6D68(r2)
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x668
	  fmr       f1, f0

	.loc_0x668:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x194
	  bl        0x11880
	  li        r3, 0

	.loc_0x678:
	  lwz       r0, 0x234(r1)
	  lfd       f31, 0x228(r1)
	  lfd       f30, 0x220(r1)
	  lfd       f29, 0x218(r1)
	  lwz       r31, 0x214(r1)
	  lwz       r30, 0x210(r1)
	  lwz       r29, 0x20C(r1)
	  lwz       r28, 0x208(r1)
	  addi      r1, r1, 0x230
	  mtlr      r0
	  blr
	*/
}
