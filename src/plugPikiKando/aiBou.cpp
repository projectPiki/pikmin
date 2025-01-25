#include "PikiAI.h"
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
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	800AC79C
 * Size:	00006C
 */
ActBou::ActBou(Piki* piki)
    : Action(piki, true)
{
	setName("Bou");
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
	} else {
		PRINT("TARGET IS %x : %d\n", creature, creature ? creature->mObjType : OBJTYPE_INVALID);
	}

	mState = STATE_GotoLeg;
	mActor->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));

	if (mActor->isHolding()) {
		mActor->_408 = 3;
	} else {
		mActor->_408 = 2;
	}

	_16 = 120;
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
		PRINT("START CLIMB !!\n");
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
		tube.getPosGradient(mActor->mPosition, mActor->mAttachPosition.x, vec1, vec2);
		_18 = vec2;
		return ACTOUT_Continue;
	}

	if (--_16 <= 0) {
		mActor->mEmotion = 1;
		return ACTOUT_Fail;
	}

	Vector3f direction = mClimbingStick->mPosition - mActor->mPosition;
	f32 dist           = direction.normalise();
	PRINT("d is %.1f\n", dist);
	mActor->setSpeed(0.5f, direction);
	return ACTOUT_Continue;
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

	if (mActor->isStickTo()) {
		return;
	}

	Vector3f centre = mActor->getCentre();
	f32 radius      = mActor->getCentreSize();

	Sphere sphere(centre, radius);
	Tube tube;

	msg->mEvent.mColliderPart->makeTube(tube);

	f32 gRatio = tube.getYRatio(10.0f + mClimbingStick->mPosition.y);

	Vector3f vec;
	f32 ratio;
	if (tube.collide(sphere, vec, ratio)) {
		PRINT("ground ratio = %f ratio = %f\n", gRatio, ratio);
		_16 = 120;
		mActor->startStickObject(msg->mEvent.mCollider, msg->mEvent.mColliderPart, -1, 0.0f);
		mActor->finishLook();

		mActor->mOdometer.start(1.0f, 5.0f);
		_28 = mActor->mPosition;
	}
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
		PRINT("======= BO ODOMETER FAILED\n");
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
	mActor->mCreatureFlags &= ~(CF_Unk8); // should use the inline, but stack
}
