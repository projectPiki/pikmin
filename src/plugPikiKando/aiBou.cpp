#include "PikiAI.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AC79C
 * Size:	00006C
 */
ActBou::ActBou(Piki* piki)
    : Action(piki, true)
{
	mName          = "Bou";
	mCurrActionIdx = -1;
}

/*
 * --INFO--
 * Address:	800AC808
 * Size:	0000A8
 */
void ActBou::init(Creature* creature)
{
	if (creature && creature->mObjType == OBJTYPE_Kusa) {
		mClimbingStick = creature;
	}

	mState = STATE_GotoLeg;
	mActor->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));

	if (mActor->mGrabbedCreature.mPtr) {
		mActor->_408 = 3;
	} else {
		mActor->_408 = 2;
	}

	_16 = 120;
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  addi      r30, r3, 0
	  beq-      .loc_0x30
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x1D
	  bne-      .loc_0x30
	  stw       r4, 0x24(r30)

	.loc_0x30:
	  li        r0, 0
	  sth       r0, 0x14(r30)
	  addi      r3, r1, 0x1C
	  li        r4, 0x2
	  bl        0x72710
	  addi      r31, r3, 0
	  addi      r3, r1, 0x24
	  li        r4, 0x2
	  bl        0x72700
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x1E170
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x80
	  li        r0, 0x3
	  stb       r0, 0x408(r3)
	  b         .loc_0x88

	.loc_0x80:
	  li        r0, 0x2
	  stb       r0, 0x408(r3)

	.loc_0x88:
	  li        r0, 0x78
	  sth       r0, 0x16(r30)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AC8B0
 * Size:	00004C
 */
int ActBou::exec()
{
	switch (mState) {
	case STATE_GotoLeg:
		return gotoLeg();

	case STATE_Climb:
		return climb();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AC8FC
 * Size:	000210
 */
int ActBou::gotoLeg()
{
	if (mActor->mStickPart) {
		mState = STATE_Climb;
		mActor->mVelocity.set(0.0f, 0.0f, 0.0f);
		mActor->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mActor->startMotion(PaniMotionInfo(PIKIANIM_HNoboru), PaniMotionInfo(PIKIANIM_HNoboru));

		mActor->setCreatureFlag(CF_Unk8);
		mActor->finishLook();
		Tube tube;
		mActor->mStickPart->makeTube(tube);
		Vector3f vec1;
		Vector3f vec2;
		tube.getPosGradient(mActor->mPosition, mActor->_194.x, vec1, vec2);
		_18 = vec2;
		return ACTOUT_Continue;
	}

	if (--_16 <= 0) {
		mActor->mEmotion = 1;
		return ACTOUT_Fail;
	}

	Vector3f direction = mClimbingStick->mPosition - mActor->mPosition;
	direction.normalise();
	mActor->setSpeed(0.5f, direction);
	return ACTOUT_Continue;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stw       r31, 0x94(r1)
	  mr        r31, r3
	  stw       r30, 0x90(r1)
	  lwz       r3, 0xC(r3)
	  lwz       r0, 0x188(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x130
	  li        r0, 0x1
	  sth       r0, 0x14(r31)
	  addi      r3, r1, 0x38
	  li        r4, 0x3E
	  lwz       r5, 0xC(r31)
	  lfs       f0, -0x4EBC(r13)
	  stfsu     f0, 0x70(r5)
	  lfs       f0, -0x4EB8(r13)
	  stfs      f0, 0x4(r5)
	  lfs       f0, -0x4EB4(r13)
	  stfs      f0, 0x8(r5)
	  lwz       r5, 0xC(r31)
	  lfs       f0, -0x4EB0(r13)
	  stfsu     f0, 0xA4(r5)
	  lfs       f0, -0x4EAC(r13)
	  stfs      f0, 0x4(r5)
	  lfs       f0, -0x4EA8(r13)
	  stfs      f0, 0x8(r5)
	  bl        0x725EC
	  addi      r30, r3, 0
	  addi      r3, r1, 0x40
	  li        r4, 0x3E
	  bl        0x725DC
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x1E04C
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0xC8(r3)
	  ori       r0, r0, 0x80
	  stw       r0, 0xC8(r3)
	  lwz       r3, 0xC(r31)
	  bl        0x2CD20
	  lfs       f0, -0x70C0(r2)
	  addi      r4, r1, 0x70
	  stfs      f0, 0x78(r1)
	  stfs      f0, 0x74(r1)
	  stfs      f0, 0x70(r1)
	  stfs      f0, 0x84(r1)
	  stfs      f0, 0x80(r1)
	  stfs      f0, 0x7C(r1)
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x188(r3)
	  bl        -0x23E44
	  lfs       f0, -0x70C0(r2)
	  addi      r3, r1, 0x70
	  addi      r5, r1, 0x64
	  stfs      f0, 0x6C(r1)
	  addi      r6, r1, 0x58
	  stfs      f0, 0x60(r1)
	  stfs      f0, 0x68(r1)
	  stfs      f0, 0x5C(r1)
	  stfs      f0, 0x64(r1)
	  stfs      f0, 0x58(r1)
	  lwz       r4, 0xC(r31)
	  lfs       f1, 0x194(r4)
	  addi      r4, r4, 0x94
	  bl        -0x25178
	  lwz       r4, 0x58(r1)
	  li        r3, 0
	  lwz       r0, 0x5C(r1)
	  stw       r4, 0x18(r31)
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x20(r31)
	  b         .loc_0x1F8

	.loc_0x130:
	  lha       r3, 0x16(r31)
	  subi      r3, r3, 0x1
	  extsh.    r0, r3
	  sth       r3, 0x16(r31)
	  bgt-      .loc_0x158
	  lwz       r4, 0xC(r31)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x1F8

	.loc_0x158:
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x24(r31)
	  lfsu      f1, 0x94(r3)
	  lfsu      f0, 0x94(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x4(r4)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0x8(r4)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x4C(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x50(r1)
	  stfs      f0, 0x54(r1)
	  lfs       f1, 0x4C(r1)
	  lfs       f0, 0x50(r1)
	  lfs       f2, 0x54(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9EE6C
	  lfs       f0, -0x70C0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1E4
	  lfs       f0, 0x4C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x50(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x54(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x54(r1)

	.loc_0x1E4:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x4C
	  lfs       f1, -0x70BC(r2)
	  bl        0x1F2EC
	  li        r3, 0

	.loc_0x1F8:
	  lwz       r0, 0x9C(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800ACB0C
 * Size:	000180
 */
void ActBou::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (msg->mEvent.mCollider != mClimbingStick) {
		return;
	}

	if (!msg->mEvent.mColliderPart) {
		return;
	}

	if (mActor->mStickTarget) {
		return;
	}

	Vector3f centre = mActor->getCentre();
	f32 radius      = mActor->getCentreSize();

	Sphere sphere(centre, radius);
	Tube tube;

	msg->mEvent.mColliderPart->makeTube(tube);

	tube.getYRatio(10.0f + mClimbingStick->mPosition.y);

	Vector3f vec;
	f32 f;
	if (tube.collide(sphere, vec, f)) {
		_16 = 120;
		mActor->startStickObject(msg->mEvent.mCollider, msg->mEvent.mColliderPart, -1, 0.0f);
		mActor->finishLook();

		mActor->mOdometer.start(1.0f, 5.0f);
		_28 = mActor->mPosition;
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stfd      f30, 0x88(r1)
	  stfd      f29, 0x80(r1)
	  stw       r31, 0x7C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x78(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x24(r3)
	  lwz       r3, 0x4(r5)
	  cmplw     r3, r0
	  bne-      .loc_0x15C
	  lwz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x15C
	  lwz       r4, 0xC(r30)
	  lwz       r0, 0x184(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x15C
	  lwz       r12, 0x0(r4)
	  addi      r3, r1, 0x18
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r30)
	  lfs       f31, 0x18(r1)
	  lwz       r12, 0x0(r3)
	  lfs       f30, 0x1C(r1)
	  lwz       r12, 0x5C(r12)
	  lfs       f29, 0x20(r1)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x70C0(r2)
	  addi      r4, r1, 0x38
	  stfs      f31, 0x58(r1)
	  stfs      f0, 0x40(r1)
	  stfs      f0, 0x3C(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f30, 0x5C(r1)
	  stfs      f0, 0x4C(r1)
	  stfs      f29, 0x60(r1)
	  stfs      f0, 0x48(r1)
	  stfs      f1, 0x64(r1)
	  stfs      f0, 0x44(r1)
	  lwz       r3, 0x8(r31)
	  bl        -0x2403C
	  lwz       r4, 0x24(r30)
	  addi      r3, r1, 0x38
	  lfs       f1, -0x70B8(r2)
	  lfs       f0, 0x98(r4)
	  fadds     f1, f1, f0
	  bl        -0x25880
	  lfs       f0, -0x70C0(r2)
	  addi      r3, r1, 0x38
	  addi      r4, r1, 0x58
	  stfs      f0, 0x30(r1)
	  addi      r5, r1, 0x28
	  addi      r6, r1, 0x24
	  stfs      f0, 0x2C(r1)
	  stfs      f0, 0x28(r1)
	  bl        -0x25878
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x15C
	  li        r0, 0x78
	  sth       r0, 0x16(r30)
	  li        r6, -0x1
	  lwz       r3, 0xC(r30)
	  lwz       r4, 0x4(r31)
	  lwz       r5, 0x8(r31)
	  lfs       f1, -0x70C0(r2)
	  bl        -0x1C574
	  lwz       r3, 0xC(r30)
	  bl        0x2CA90
	  lwz       r3, 0xC(r30)
	  lfs       f1, -0x70B4(r2)
	  lfs       f2, -0x70B0(r2)
	  addi      r3, r3, 0x2BC
	  bl        0x20BCC
	  lwz       r4, 0xC(r30)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x28(r30)
	  stw       r0, 0x2C(r30)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x30(r30)

	.loc_0x15C:
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  lfd       f29, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800ACC8C
 * Size:	000108
 */
int ActBou::climb()
{
	if (!mActor->mStickPart) {
		return ACTOUT_Fail;
	}

	if (!mActor->mOdometer.moving(mActor->mPosition, _28)) {
		return ACTOUT_Fail;
	}

	_28               = mActor->mPosition;
	f32 mag           = (22.0f + randFloat(4.0f));
	mActor->mVelocity = _18 * mag;
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800ACD94
 * Size:	0000A8
 */
void ActBou::cleanup()
{
	mActor->mVelocity       = _18 * 150.0f;
	mActor->mTargetVelocity = mActor->mVelocity;
	mActor->endStickObject();
	mActor->resetCreatureFlag(CF_Unk8);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lfs       f2, -0x4EA4(r13)
	  lfs       f0, 0x18(r3)
	  lfs       f1, 0x20(r3)
	  fmuls     f0, f0, f2
	  fmuls     f1, f1, f2
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x18(r1)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x1C(r3)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x24(r1)
	  stfs      f1, 0x28(r1)
	  lwz       r4, 0xC(r3)
	  lwz       r3, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r3, 0x70(r4)
	  stw       r0, 0x74(r4)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x78(r4)
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x70(r4)
	  lwz       r0, 0x74(r4)
	  stw       r3, 0xA4(r4)
	  stw       r0, 0xA8(r4)
	  lwz       r0, 0x78(r4)
	  stw       r0, 0xAC(r4)
	  lwz       r3, 0xC(r31)
	  bl        -0x1C59C
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0xC8(r3)
	  rlwinm    r0,r0,0,25,23
	  stw       r0, 0xC8(r3)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}
