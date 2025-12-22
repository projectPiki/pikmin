#include "DebugLog.h"
#include "Dolphin/os.h"
#include "PikiAI.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(18)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("Bou")

/**
 * @TODO: Documentation
 */
ActBou::ActBou(Piki* piki)
    : Action(piki, true)
{
	setName("Bou");
	mCurrActionIdx = PikiAction::NOACTION;
}

/**
 * @TODO: Documentation
 */
void ActBou::init(Creature* creature)
{
	if (creature && creature->mObjType == OBJTYPE_Kusa) {
		mTargetStick = creature;
	} else {
		PRINT("TARGET IS %x : %d\n", creature, creature ? creature->mObjType : OBJTYPE_INVALID);
		ERROR("karl caught a cold !\n");
	}

	mState = STATE_GotoLeg;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));

	if (mPiki->isHolding()) {
		mPiki->mActionState = 3;
	} else {
		mPiki->mActionState = 2;
	}

	mTimeoutCounter = 120;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
int ActBou::gotoLeg()
{
	if (mPiki->mStickPart) {
		PRINT("START CLIMB !!\n");
		mState = STATE_Climb;
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_HNoboru), PaniMotionInfo(PIKIANIM_HNoboru));

		mPiki->setCreatureFlag(CF_Unk8);
		mPiki->finishLook();

		Tube tube;
		mPiki->mStickPart->makeTube(tube);

		Vector3f pos;
		Vector3f gradient;
		tube.getPosGradient(mPiki->mSRT.t, mPiki->mAttachPosition.x, pos, gradient);
		mClimbDirection = gradient;
		return ACTOUT_Continue;
	}

	if (--mTimeoutCounter <= 0) {
		mPiki->mEmotion = PikiEmotion::Sad;
		return ACTOUT_Fail;
	}

	Vector3f direction = mTargetStick->mSRT.t - mPiki->mSRT.t;
	f32 dist           = direction.normalise();
	PRINT("d is %.1f\n", dist);
	mPiki->setSpeed(0.5f, direction);
	return ACTOUT_Continue;
}

/**
 * @TODO: Documentation
 */
void ActBou::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (msg->mEvent.mCollider != mTargetStick) {
		return;
	}

	if (!msg->mEvent.mColliderPart) {
		return;
	}

	if (mPiki->isStickTo()) {
		return;
	}

	Vector3f centre = mPiki->getCentre();
	f32 radius      = mPiki->getCentreSize();

	Sphere sphere(centre, radius);
	Tube tube;

	msg->mEvent.mColliderPart->makeTube(tube);

	f32 groundRatio = tube.getYRatio(10.0f + mTargetStick->mSRT.t.y);

	Vector3f collisionPoint;
	f32 ratio;
	if (tube.collide(sphere, collisionPoint, ratio)) {
		PRINT("ground ratio = %f ratio = %f\n", groundRatio, ratio);
		mTimeoutCounter = 120;
		mPiki->startStickObject(msg->mEvent.mCollider, msg->mEvent.mColliderPart, -1, 0.0f);
		mPiki->finishLook();

		mPiki->mOdometer.start(1.0f, 5.0f);
		mLastPosition = mPiki->mSRT.t;
	}
}

/**
 * @TODO: Documentation
 */
int ActBou::climb()
{
	if (!mPiki->mStickPart) {
		return ACTOUT_Fail;
	}

	if (!mPiki->mOdometer.moving(mPiki->mSRT.t, mLastPosition)) {
		PRINT("======= BO ODOMETER FAILED\n");
		return ACTOUT_Fail;
	}

	mLastPosition    = mPiki->mSRT.t;
	f32 mag          = (22.0f + 4.0f * gsys->getRand(1.0f));
	mPiki->mVelocity = mClimbDirection * mag;
	return ACTOUT_Continue;
}

/**
 * @TODO: Documentation
 */
void ActBou::cleanup()
{
	mPiki->mVelocity       = mClimbDirection * 150.0f;
	mPiki->mTargetVelocity = mPiki->mVelocity;
	mPiki->endStickObject();
	mPiki->mCreatureFlags &= ~(CF_Unk8); // should use the inline, but stack
}
