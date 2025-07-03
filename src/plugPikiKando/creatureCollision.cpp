#include "Piki.h"
#include "PikiState.h"
#include "Collision.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("CreatureColl")

/*
 * --INFO--
 * Address:	8008D954
 * Size:	000768
 */
void Creature::respondColl(Creature* other, f32, CollPart* selfCollider, CollPart* otherCollider, const Vector3f& point)
{
	if (!ignoreAtari(other) && !other->ignoreAtari(this)) {

		CollEvent selfEvent(this, selfCollider, otherCollider);
		CollEvent otherEvent(other, otherCollider, selfCollider);
		other->collisionCallback(selfEvent);
		collisionCallback(otherEvent);

		if (!needFlick(other) || !other->needFlick(this)) {
			return;
		}

		if (!other->isAtari() || !isAtari()) {
			return;
		}

		if (!isAlive() || !other->isAlive()) {
			return;
		}

		if (!other->isObjType(OBJTYPE_Plant) && !isObjType(OBJTYPE_Plant) && other->mObjType != OBJTYPE_Plant) {
			// If the Pikmin has been thrown at something and hits it, print the name of the hit object
			if (mObjType == OBJTYPE_Piki && ((Piki*)this)->getState() == PIKISTATE_Flying) {
				PRINT("vs %s : \n", ObjType::getName(other->mObjType));
			}

			// Calculate collision response vectors
			Vector3f collisionNormal = point;
			if (collisionNormal.DP(collisionNormal) == 0.0f) {
				f32 angle = 0.0f;
				collisionNormal.set(sinf(angle), 0.0f, cosf(angle));
			}

			// Calculate relative velocity
			Vector3f relativeVelocity = mVelocity;
			relativeVelocity          = relativeVelocity - other->mVelocity;
			f32 impactSpeed           = relativeVelocity.DP(collisionNormal);

			// Get inverse masses for collision response
			f32 selfInvMass  = getiMass();
			f32 otherInvMass = other->getiMass();

			// Prevent division by zero in mass calculations
			if (selfInvMass + otherInvMass < 0.0001f) {
				selfInvMass  = 1e-05;
				otherInvMass = 1e-05;
			}

			// Calculate impulse scalar
			f32 restitution   = 1.35f; // Coefficient of restitution
			f32 impulseScalar = -restitution * impactSpeed;
			impulseScalar     = impulseScalar / ((selfInvMass + otherInvMass) * collisionNormal.DP(collisionNormal));
			collisionNormal   = impulseScalar * collisionNormal;

			// Apply impulse to self
			Vector3f impulse = collisionNormal;
			impulse          = selfInvMass * impulse;
			mVelocity        = mVelocity + impulse;

			// Apply impulse to other
			f32 unused;
			impulse          = collisionNormal;
			impulse          = -otherInvMass * impulse;
			other->mVelocity = other->mVelocity + impulse;

			// Calculate separation vector
			Vector3f separationVector = -1.0f * point;
			f32 distance              = separationVector.normalise();
			if (distance > 0.0f) {
				// Calculate mass ratios for separation
				f32 sepRatioSelf, sepRatioOther;
				f32 totalMass = getiMass() + other->getiMass();

				if (totalMass > 0) {
					sepRatioSelf  = getiMass() / totalMass;
					sepRatioOther = 1.0f - sepRatioSelf;
				} else {
					sepRatioOther = 0.5f;
					sepRatioSelf  = 0.5f;
				}

				// Adjust ratios based on fixed status
				if (isFixed() && !other->isFixed()) {
					sepRatioSelf  = 0.0f;
					sepRatioOther = 1.0f;
				} else if (!isFixed() && other->isFixed()) {
					sepRatioSelf  = 1.0f;
					sepRatioOther = 0.0f;
				} else if (isFixed() && other->isFixed()) {
					sepRatioOther = 0.0f;
					sepRatioSelf  = 0.0f;
				}

				// Separation velocity scaling factors
				f32 verticalScale   = 0.0f;
				f32 horizontalScale = 0.5f;

				// Calculate time-scaled separation velocities
				f32 sepSpeedSelf  = distance * sepRatioSelf / gsys->getFrameTime();
				f32 sepSpeedOther = distance * sepRatioOther / gsys->getFrameTime();

				if (mObjType != OBJTYPE_Navi) {
					mVolatileVelocity.x = sepSpeedSelf * separationVector.x * horizontalScale;
					mVolatileVelocity.z = sepSpeedSelf * separationVector.z * horizontalScale;
					mVolatileVelocity.y = sepSpeedSelf * separationVector.y * verticalScale;
				} else {
					mVolatileVelocity.x += sepSpeedSelf * separationVector.x * horizontalScale;
					mVolatileVelocity.z += sepSpeedSelf * separationVector.z * horizontalScale;
					mVolatileVelocity.y += sepSpeedSelf * separationVector.y * verticalScale;
				}

				if (other->mObjType != OBJTYPE_Navi) {
					other->mVolatileVelocity.x = -sepSpeedOther * separationVector.x * horizontalScale;
					other->mVolatileVelocity.z = -sepSpeedOther * separationVector.z * horizontalScale;
					other->mVolatileVelocity.y = -sepSpeedOther * separationVector.y * verticalScale;
				} else {
					other->mVolatileVelocity.x += -sepSpeedOther * separationVector.x * horizontalScale;
					other->mVolatileVelocity.z += -sepSpeedOther * separationVector.z * horizontalScale;
					other->mVolatileVelocity.y += -sepSpeedOther * separationVector.y * verticalScale;
				}

				if (!isFixed()) {
					mHasCollChangedVelocity = 1;
				}

				if (!other->isFixed()) {
					other->mHasCollChangedVelocity = 1;
				}

				return;
			}

			mHasCollChangedVelocity = 0;
		}
	}
}
