#include "KMath.h"
#include "Dolphin/float.h"
#include "zen/Math.h"
#include "MapMgr.h"
#include "AIConstant.h"
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
DEFINE_PRINT("kmath")

/*
 * --INFO--
 * Address:	801126C4
 * Size:	00005C
 */
bool isNan(f32 value)
{
	if ((u32)value == (u32)NAN) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	80112720
 * Size:	00009C
 */
void makePostureMatrix(Vector3f& col0, Vector3f& col1, Vector3f& col2, Matrix4f& mtx)
{
	mtx.makeIdentity();

	mtx.mMtx[0][0] = col0.x;
	mtx.mMtx[1][0] = col0.y;
	mtx.mMtx[2][0] = col0.z;
	mtx.mMtx[0][1] = col1.x;
	mtx.mMtx[1][1] = col1.y;
	mtx.mMtx[2][1] = col1.z;
	mtx.mMtx[0][2] = col2.x;
	mtx.mMtx[1][2] = col2.y;
	mtx.mMtx[2][2] = col2.z;
}

/*
 * --INFO--
 * Address:	801127BC
 * Size:	0001B0
 */
f32 calcImpulse(Vector3f& relativePos, f32 mass, Vector3f& collisionNormal, Matrix4f& inertiaTensor, Vector3f& relativeVel,
                Vector3f& separationVel)
{
	f32 normalSpeed    = collisionNormal.DP(relativeVel);
	f32 normalSepSpeed = collisionNormal.DP(separationVel);
	f32 restitution    = -(normalSepSpeed / normalSpeed);

	Vector3f angularComponent;
	Vector3f unused;

	angularComponent = relativePos;
	angularComponent.CP(collisionNormal);
	angularComponent.multMatrix(inertiaTensor);
	angularComponent.CP(relativePos);
	f32 tmp = (-1.0f - restitution) * normalSpeed;
	return tmp / (angularComponent.DP(collisionNormal) + 1.0f / mass);
}

/*
 * --INFO--
 * Address:	8011296C
 * Size:	0001C0
 */
Vector3f CRSpline(f32 t, Vector3f* ctrlPts)
{
	f32 tSqr = t * t;
	f32 tCub = tSqr * t;
	f32 a    = -0.5f * tCub + tSqr - 0.5f * t;
	f32 b    = 1.5f * tCub - 2.5f * tSqr + 1.0f;
	f32 c    = -1.5f * tCub + 2.0f * tSqr + 0.5f * t;
	f32 d    = 0.5f * tCub - 0.5f * tSqr;
	Vector3f outVec;
	outVec = a * ctrlPts[0] + b * ctrlPts[1] + c * ctrlPts[2] + d * ctrlPts[3];
	return outVec;
}

/*
 * --INFO--
 * Address:	80112B2C
 * Size:	0001B8
 */
Vector3f CRSplineTangent(f32 t, Vector3f* ctrlPts)
{
	f32 tSqr = t * t;
	f32 tCub = tSqr * t; // unused but necessary?? CLEARLY copied from above and edited lol
	f32 a    = -1.5f * tSqr + 2.0f * t - 0.5f;
	f32 b    = 4.5f * tSqr - 5.0f * t;
	f32 c    = -4.5f * tSqr + 4.0f * t + 0.5f;
	f32 d    = 1.5f * tSqr - 1.0f * t;
	Vector3f outVec;
	outVec = a * ctrlPts[0] + b * ctrlPts[1] + c * ctrlPts[2] + d * ctrlPts[3];
	return outVec;
}

/*
 * --INFO--
 * Address:	80112CE4
 * Size:	00022C
 */
Vector3f getThrowVelocity(Vector3f& startPos, f32 horizSpeed, Vector3f& targetPos, Vector3f& targetDir)
{
	Vector3f displacement = startPos - targetPos;

	// approx time to reach target position at given speed
	f32 timeToTarget = displacement.length() / absF(horizSpeed);

	// flatten target direction
	targetDir.y = 0.0f;

	// modify target position to "follow"/"lead" the direction of the target
	// devs have this turned off - thrown objects don't home in on targets (but could if the 0.0f was modified)
	Vector3f predTargetPos = targetPos + targetDir * timeToTarget * 0.0f;

	// calculate y speed using projectile motion
	f32 vertDisplacement = -(predTargetPos.y - startPos.y);
	f32 initialYVel      = (vertDisplacement / timeToTarget) - AIConstant::_instance->mConstants.mGravity() * 0.5f * timeToTarget;

	// calculate throw velocity
	Vector3f throwVel;
	throwVel   = predTargetPos - startPos;
	throwVel.y = 0.0f;
	throwVel.normalise();
	throwVel.multiply(horizSpeed);
	throwVel.y = -initialYVel;

	return throwVel;
}

/*
 * --INFO--
 * Address:	80112F10
 * Size:	000254
 */
f32 getCameraSafeAngle(Vector3f& cameraPos, f32 checkDistance, f32 heightWeighting)
{
	f32 angleInc = QUARTER_PI;
	int scores[8]; // visibility scores
	f32 numPointsToCheck = 20.0f;
	for (int i = 0; i < 8; i++) {
		scores[i] = 0;
	}

	for (int i = 0; i < 8; i++) {
		f32 currentAngle = angleInc * f32(i);
		Vector3f dir(sinf(currentAngle), 0.0f, cosf(currentAngle));
		f32 distanceInc = checkDistance / numPointsToCheck;

		// check 20 points along direction vector
		for (int j = 0; j < 20; j++) {
			f32 heightThreshold = heightWeighting * f32(j) * distanceInc / checkDistance;
			Vector3f checkPos;
			checkPos        = cameraPos + dir * (distanceInc * f32(j));
			f32 checkHeight = mapMgr->getMinY(checkPos.x, checkPos.z, true);
			if (checkHeight >= heightThreshold) {
				scores[i] += int(checkHeight - heightThreshold);
			}
		}
		PRINT("score[%d] = %d\n", i, scores[i]);
	}

	// find angle with lowest score (best visibility):
	int minScore     = 128000;
	int bestAngleIdx = -1;
	for (int i = 0; i < 8; i++) {
		if (scores[i] < minScore) {
			bestAngleIdx = i;
			minScore     = scores[i];
		}
	}

	PRINT("minIndex = %d ang = %.1f\n", bestAngleIdx, f32(bestAngleIdx) * angleInc / PI * 180.0f);
	return f32(bestAngleIdx) * angleInc;
}
