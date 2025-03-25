#include "PikiAI.h"
#include "zen/Math.h"
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
 * Address:	800BAF68
 * Size:	00004C
 */
ActGoto::ActGoto(Piki* piki)
    : Action(piki, true)
{
	mTarget.clear();
}

/*
 * --INFO--
 * Address:	800BAFB4
 * Size:	00007C
 */
void ActGoto::Initialiser::initialise(Action* action)
{
	ActGoto* ai      = static_cast<ActGoto*>(action);
	ai->mMaxDistance = mMaxDistance;
	ai->mMinDistance = mMinDistance;
	if (mTarget) {
		ai->mTarget.set(mTarget);
	}
}

/*
 * --INFO--
 * Address:	800BB030
 * Size:	0000D4
 */
void ActGoto::init(Creature* target)
{
	mTimeoutDuration = (2.0f * gsys->getRand(1.0f)) + 4.0f;
	mTarget.set(target);
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
}

/*
 * --INFO--
 * Address:	800BB104
 * Size:	000040
 */
void ActGoto::cleanup()
{
	Creature* target = mTarget.getPtr();
	mTarget.reset();
}

/*
 * --INFO--
 * Address:	800BB144
 * Size:	000378
 */
int ActGoto::exec()
{
	Creature* target = mTarget.getPtr();
	if (!target || !target->isVisible()) {
		return ACTOUT_Fail;
	}

	mTimeoutDuration -= gsys->getFrameTime();

	f32 distanceToTarget = qdist2(target, mPiki);
	f32 verticalDistance = zen::Abs(target->mPosition.y - mPiki->mPosition.y);

	// If distance is within the range, return success
	if (distanceToTarget >= mMinDistance && distanceToTarget <= mMaxDistance + mPiki->getCentreSize() + target->getCentreSize()) {
		// Can't be too much of a difference vertically
		if (verticalDistance > 20.0f) {
			return ACTOUT_Fail;
		}

		return ACTOUT_Success;
	}

	if (mTimeoutDuration < 0.0f) {
		PRINT("time out\n");
		return ACTOUT_Fail;
	}

	// Calculate desired position maintaining minimum distance from target
	Vector3f targetPosition(target->mPosition);
	Vector3f directionToTarget = mPiki->mPosition - targetPosition;
	directionToTarget.normalise();
	directionToTarget = directionToTarget * mMinDistance;
	targetPosition    = targetPosition + directionToTarget;

	// Reset current target velocity
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	// Calculate movement direction, ignoring vertical component
	Vector3f moveDirection = targetPosition - mPiki->mPosition;
	moveDirection.y        = 0.0f;
	f32 horizontalDistance = moveDirection.length();

	// Normalize movement direction if possible, otherwise choose random direction
	if (horizontalDistance > 0.0f) {
		moveDirection = (1.0f / horizontalDistance) * moveDirection;
	} else {
		// If no clear direction, pick random angle in horizontal plane
		f32 randomAngle = 2.0f * (PI * gsys->getRand(1.0f));
		moveDirection.set(cosf(randomAngle), 0.0f, sinf(randomAngle));
	}

	// This entire code segment remains unused, except for mPiki->setSpeed
	// But it is some sort of smoothing algorithm for the movement direction
	// It is not clear what the purpose of this is, but it is likely to make the movement more natural
	Vector3f vec1(0.0f, 0.0f, 0.0f);
	Vector3f unitDirToTarget = targetPosition - mPiki->mPosition;
	unitDirToTarget.normalise();
	Vector3f perpDir(-unitDirToTarget.z, 0.0f, unitDirToTarget.x);
	bool velocityBlending = false;
	mPiki->setSpeed(1.0f, moveDirection);
	f32 factor = 1.0f;
	if (velocityBlending) {
		mPiki->mTargetVelocity = (1.0f - factor) * mPiki->mTargetVelocity + factor * vec1;
	}

	return ACTOUT_Continue;
}
