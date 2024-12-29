#include "PikiAI.h"
#include "Interactions.h"
#include "system.h"
#include "Dolphin/os.h"
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
DEFINE_PRINT("aiActions");

/*
 * --INFO--
 * Address:	800A79F8
 * Size:	000080
 */
ActPick::ActPick(Piki* piki)
    : Action(piki, true)
{
	mObject = nullptr;
	resetCreature(mObject);
}

/*
 * --INFO--
 * Address:	800A7A78
 * Size:	000004
 */
void ActPick::Initialiser::initialise(Action* action)
{
#ifdef __MWERKS__
	ActPick* act = (ActPick*)action;
	PRINT(" initialiser called ###################### \n");
	act->mObject = mObject;
#endif
}

/*
 * --INFO--
 * Address:	800A7A7C
 * Size:	0000D4
 */
void ActPick::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		Creature* obj = mObject;
		if (obj && obj->isVisible() && qdist2(obj, mActor) < 20.0f) {
			obj->stimulate(InteractGrab(mActor));
		}
		break;

	case KEY_Done:
		_1C = 1;
		break;
	}
}

/*
 * --INFO--
 * Address:	800A7B50
 * Size:	0000B8
 */
void ActPick::init(Creature* object)
{
	_1C = 0;
	if (mObject) {
		resetCreature(mObject);
	}
	mObject = object;
	postSetCreature(mObject);

	mActor->startMotion(PaniMotionInfo(4, this), PaniMotionInfo(4));
	mActor->enableMotionBlend();
}

/*
 * --INFO--
 * Address:	800A7C08
 * Size:	000040
 */
void ActPick::cleanup()
{
	u32 badCompiler;
	u32 badCompiler2;
	resetCreature(mObject);
}

/*
 * --INFO--
 * Address:	800A7C48
 * Size:	0000B4
 */
int ActPick::exec()
{
	u32 badCompiler;
	u32 badCompiler2;
	mActor->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (_1C) {
		if (!mActor->_2AC) {
			mActor->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
			mActor->mEmotion = 1;
			return ACTOUT_Fail;
		}

		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lfs       f0, -0x5090(r13)
	  lwz       r3, 0xC(r3)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x508C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x5088(r13)
	  stfs      f0, 0x8(r3)
	  lbz       r0, 0x1C(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x98
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x90
	  addi      r3, r1, 0x14
	  li        r4, 0x2
	  bl        0x772B8
	  addi      r31, r3, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x2
	  bl        0x772A8
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x22D18
	  lwz       r4, 0xC(r30)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x9C

	.loc_0x90:
	  li        r3, 0x2
	  b         .loc_0x9C

	.loc_0x98:
	  li        r3, 0

	.loc_0x9C:
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
 * Address:	........
 * Size:	000040
 */
ActPut::ActPut(Piki* piki)
    : Action(piki, false)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A7CFC
 * Size:	000004
 */
void ActPut::Initialiser::initialise(Action*) { }

/*
 * --INFO--
 * Address:	800A7D00
 * Size:	00000C
 */
void ActPut::init(Creature*) { mFailCountdownTimer = 0.5f; }

/*
 * --INFO--
 * Address:	800A7D0C
 * Size:	000004
 */
void ActPut::cleanup() { }

/*
 * --INFO--
 * Address:	800A7D10
 * Size:	0000D8
 */
int ActPut::exec()
{
	mActor->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	Creature* obj = mActor->get2AC();
	if (!obj) {
		return ACTOUT_Fail;
	}

	if (obj->stimulate(InteractRelease(mActor, 1.0f))) {
		PRINT("release ?\n");
		return ACTOUT_Success;
	}

	mFailCountdownTimer -= gsys->getFrameTime();
	if (mFailCountdownTimer < 0.0f) {
		return ACTOUT_Fail;
	}

	return ACTOUT_Continue;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lfs       f0, -0x5084(r13)
	  lwz       r3, 0xC(r3)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x5080(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x507C(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r6, 0xC(r31)
	  lwz       r0, 0x2AC(r6)
	  cmplwi    r0, 0
	  mr        r3, r0
	  bne-      .loc_0x4C
	  li        r3, 0x1
	  b         .loc_0xC4

	.loc_0x4C:
	  lis       r4, 0x802B
	  lfs       f0, -0x7198(r2)
	  subi      r0, r4, 0x3064
	  stw       r0, 0x2C(r1)
	  lis       r5, 0x802B
	  subi      r0, r5, 0x2E74
	  stw       r6, 0x30(r1)
	  addi      r4, r1, 0x2C
	  stw       r0, 0x2C(r1)
	  stfs      f0, 0x34(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x94
	  li        r3, 0x2
	  b         .loc_0xC4

	.loc_0x94:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x14(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r31)
	  lfs       f1, 0x14(r31)
	  lfs       f0, -0x7194(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xC0
	  li        r3, 0x1
	  b         .loc_0xC4

	.loc_0xC0:
	  li        r3, 0

	.loc_0xC4:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A7DE8
 * Size:	00006C
 */
ActAdjust::ActAdjust(Piki* piki)
    : Action(piki, true)
{
	_18 = 8;
	_14 = 5.0f;
}

/*
 * --INFO--
 * Address:	800A7E54
 * Size:	000014
 */
void ActAdjust::Initialiser::initialise(Action* action)
{
	static_cast<ActAdjust*>(action)->_14 = _04;
	static_cast<ActAdjust*>(action)->_18 = _08;
}

/*
 * --INFO--
 * Address:	800A7E68
 * Size:	000200
 */
void ActAdjust::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stfd      f31, 0xB0(r1)
	  stfd      f30, 0xA8(r1)
	  stfd      f29, 0xA0(r1)
	  stfd      f28, 0x98(r1)
	  stw       r31, 0x94(r1)
	  stw       r30, 0x90(r1)
	  addi      r30, r3, 0
	  beq-      .loc_0x1D0
	  li        r0, 0
	  stb       r0, 0x3C(r30)
	  lis       r0, 0x4330
	  lwz       r5, 0x94(r4)
	  lwz       r3, 0x98(r4)
	  stw       r5, 0x1C(r30)
	  stw       r3, 0x20(r30)
	  lwz       r3, 0x9C(r4)
	  stw       r3, 0x24(r30)
	  lwz       r31, 0xC(r30)
	  lwz       r3, 0x18(r30)
	  lfs       f1, 0x24(r30)
	  xoris     r3, r3, 0x8000
	  lfs       f0, 0x9C(r31)
	  stw       r3, 0x8C(r1)
	  fsubs     f29, f1, f0
	  lfs       f2, 0x1C(r30)
	  lfs       f0, 0x94(r31)
	  stw       r0, 0x88(r1)
	  fsubs     f30, f2, f0
	  lfd       f1, -0x7178(r2)
	  fmr       f2, f29
	  lfd       f0, 0x88(r1)
	  lfs       f5, 0x20(r30)
	  fsubs     f0, f0, f1
	  lfs       f4, 0x98(r31)
	  lfs       f3, -0x718C(r2)
	  fmr       f1, f30
	  fsubs     f31, f5, f4
	  fmuls     f28, f3, f0
	  bl        0x173AE8
	  lfs       f2, 0xA0(r31)
	  bl        -0x6F964
	  fdivs     f0, f1, f28
	  stfs      f0, 0x2C(r30)
	  fmuls     f2, f30, f30
	  fmuls     f1, f31, f31
	  fmuls     f3, f29, f29
	  lfs       f0, -0x7194(r2)
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x134
	  fsqrte    f1, f4
	  lfd       f3, -0x7188(r2)
	  lfd       f2, -0x7180(r2)
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
	  stfs      f0, 0x40(r1)
	  lfs       f4, 0x40(r1)

	.loc_0x134:
	  lfs       f1, -0x7198(r2)
	  addi      r3, r1, 0x48
	  lfs       f2, 0x14(r30)
	  li        r4, 0xB
	  fdivs     f0, f1, f4
	  fsubs     f2, f4, f2
	  fdivs     f1, f1, f28
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fmuls     f2, f30, f0
	  fmuls     f1, f31, f0
	  fmuls     f0, f29, f0
	  stfs      f2, 0x34(r1)
	  lfs       f2, 0x34(r1)
	  stfs      f2, 0x58(r1)
	  stfs      f1, 0x5C(r1)
	  stfs      f0, 0x60(r1)
	  lwz       r5, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r5, 0x30(r30)
	  stw       r0, 0x34(r30)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x38(r30)
	  lfs       f0, -0x7194(r2)
	  stfs      f0, 0x28(r30)
	  bl        0x76F58
	  addi      r31, r3, 0
	  addi      r3, r1, 0x50
	  li        r4, 0xB
	  bl        0x76F48
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x229B8
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0xC8(r3)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r3)
	  b         .loc_0x1D8

	.loc_0x1D0:
	  li        r0, 0x1
	  stb       r0, 0x3C(r30)

	.loc_0x1D8:
	  lwz       r0, 0xBC(r1)
	  lfd       f31, 0xB0(r1)
	  lfd       f30, 0xA8(r1)
	  lfd       f29, 0xA0(r1)
	  lfd       f28, 0x98(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A8068
 * Size:	000014
 */
void ActAdjust::cleanup() { mActor->resetCreatureFlag(CF_Unk11); }

/*
 * --INFO--
 * Address:	800A807C
 * Size:	00011C
 */
int ActAdjust::exec()
{
	if (_3C) {
		return ACTOUT_Fail;
	}

	mActor->mVelocity       = _30;
	mActor->mTargetVelocity = _30;
	mActor->mDirection += _2C * gsys->getFrameTime();
	mActor->mDirection = roundAng(mActor->mDirection);
	mActor->mRotation.set(0.0f, mActor->mDirection, 0.0f);
	_28 += gsys->getFrameTime();

	if (_28 > f32(_18) * (1 / 30.0f)) {
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}
