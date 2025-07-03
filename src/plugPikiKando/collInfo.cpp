#include "Collision.h"
#include "Creature.h"
#include "DynColl.h"
#include "Geometry.h"
#include "zen/Math.h"

#include "Shape.h"
#include "Dolphin/os.h"
#include "sysNew.h"
#include "Graphics.h"
#include "timers.h"

#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(9)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("collInfo");

Matrix4f invCamMat;

static char* _typeStr[] = {
	"COLLISION",   // PART_Collision
	"BOUNDSPHERE", // PART_BoundSphere
	"REFERENCE",   // PART_Reference
	"PLATFORM",    // PART_Platform
	"CYLINDER",    // PART_Cylinder
	"TUBE",        // PART_Tube
	"TUBE_CHILD",  // PART_TubeChild
};

/*
 * --INFO--
 * Address:	80086CC4 in DOL, 100E7340 in DLL
 * Size:	0002DC
 */
f32 Cylinder::get2dDist(Vector3f& point)
{
	// Calculate cylinder direction vector
	Vector3f cylinderDir = mEndPoint - mStartPoint;

	Vector3f normalised = cylinderDir;

	// Project point onto cylinder axis
	f32 length          = normalised.normalise();
	f32 projectionRatio = normalised.DP(point - mStartPoint) / length;

	if (projectionRatio < 0.0f) {
		// Before cylinder start - get 2D distance to start point
		Vector3f startToPoint = mStartPoint - point;
		return std::sqrtf(startToPoint.x * startToPoint.x + startToPoint.z * startToPoint.z);
	}

	if (projectionRatio > 1.0f) {
		// Past cylinder end - get 2D distance to end point
		Vector3f endToPoint = mEndPoint - point;
		return std::sqrtf(endToPoint.x * endToPoint.x + endToPoint.z * endToPoint.z);
	}

	// On cylinder body - get distance to projected point
	Vector3f projectedPoint = (cylinderDir * projectionRatio) + mStartPoint;
	projectedPoint          = projectedPoint - point;
	return std::sqrtf(projectedPoint.x * projectedPoint.x + projectedPoint.z * projectedPoint.z);
}

/*
 * --INFO--
 * Address:	80086FA0 in DOL, 100E7530 in DLL
 * Size:	0003C0
 */
bool Cylinder::collide(const Sphere& sphere, Vector3f& pushVector, f32& depth)
{
	// Calculate cylinder direction and normalize it
	Vector3f cylinderDir = mEndPoint - mStartPoint;
	Vector3f normalised  = cylinderDir;
	f32 length           = normalised.normalise();

	// Project sphere center onto cylinder axis
	f32 projectionRatio = normalised.dot(sphere.mCentre - mStartPoint) / length;

	// Calculate distance from center projection to cylinder ends (0.5 = center)
	f32 distToEnds = absF(projectionRatio - 0.5f) * length;

	// Calculate penetration along cylinder length
	f32 endPenetration = (0.5f * length) - (distToEnds - sphere.mRadius);

	// Get actual point on cylinder axis where sphere is projected
	Vector3f projectedPoint;
	projectedPoint = (projectionRatio * cylinderDir) + mStartPoint - sphere.mCentre;

	f32 projLength = projectedPoint.length();
	// Vector from sphere center to projected point, and radial penetration
	f32 radialPenetration = sphere.mRadius + mRadius - projLength;

	// Resolve collision
	if (endPenetration >= 0.0f && endPenetration < radialPenetration && radialPenetration >= 0.0f) {
		// Handle end cap collision
		if (projectionRatio < 0.5f) {
			endPenetration = -endPenetration; // Flip direction for start cap
		}

		pushVector = cylinderDir * endPenetration;
		depth      = projectionRatio;
		return true;
	} else if (projectionRatio >= 0.0f && projectionRatio <= 1.0f && radialPenetration >= 0.0f) {
		// Handle radial collision only if within cylinder length bounds
		// Push along radial direction
		pushVector = projectedPoint;
		pushVector.normalise();
		pushVector = pushVector * -radialPenetration;
		depth      = projectionRatio;
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80087360
 * Size:	00002C
 */
f32 Tube::getYRatio(f32 heightToCheck)
{
	const f32 r = mEndPoint.y - mStartPoint.y;
	if (r != 0.0f) {
		return (heightToCheck - mStartPoint.y) / (r);
	}

	return -1.0f;
}

/*
 * --INFO--
 * Address:	8008738C
 * Size:	00033C
 */
bool Tube::collide(const Sphere& sphere, Vector3f& pushVector, f32& depth)
{
	Vector3f axisVec = mEndPoint - mStartPoint;
	Vector3f dir     = axisVec;
	f32 len          = dir.normalise();
	f32 tmpDepth     = dir.DP(sphere.mCentre - mStartPoint) / len;

	// this is completely unused lol
	f32 unused = 0.5f * len - (absF(tmpDepth - 0.5f) * len - sphere.mRadius);

	Vector3f pushDir;
	pushDir = tmpDepth * axisVec + mStartPoint - sphere.mCentre;

	STACK_PAD_VAR(2);

	f32 pushStrength = (1.0f - tmpDepth) * mStartRadius + mEndRadius * tmpDepth + sphere.mRadius - pushDir.length();

	if (tmpDepth >= 0.0f && tmpDepth <= 1.0f && pushStrength >= 0.0f) {
		pushVector = pushDir;
		pushVector.normalise();
		pushVector = pushVector * -pushStrength;
		depth      = tmpDepth;
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	800876C8
 * Size:	0000E4
 */
f32 Cylinder::getPosRatio(const Vector3f& vec)
{
	Vector3f axisVec = mEndPoint - mStartPoint;
	Vector3f dir     = axisVec;
	f32 len          = dir.normalise();
	return dir.DP(vec - mStartPoint) / len;
}

/*
 * --INFO--
 * Address:	800877AC
 * Size:	0000E4
 */
f32 Tube::getPosRatio(const Vector3f& pos)
{
	Vector3f axisVec = mEndPoint - mStartPoint;
	Vector3f dir     = axisVec;
	f32 len          = dir.normalise();

	return dir.DP(pos - mStartPoint) / len;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
f32 Tube::getRatioRadius(f32 ratio)
{
	return (1.0f - ratio) * mStartRadius + ratio * mEndRadius;
}

/*
 * --INFO--
 * Address:	80087890
 * Size:	000238
 */
void Tube::getPosGradient(Vector3f& inputPos, f32 t, Vector3f& surfacePos, Vector3f& surfaceGrad)
{
	Vector3f tubePos = setPos(t);
	Vector3f normal  = inputPos - tubePos;
	normal.normalise();
	f32 rad            = mStartRadius * (1.0f - t) + mEndRadius * t;
	Vector3f endOffset = mEndPoint + normal * mEndRadius;
	normal             = normal * rad;
	surfacePos         = tubePos + normal;

	Vector3f tmp(surfacePos);
	surfaceGrad = endOffset - tmp;
	surfaceGrad.normalise();
}

/*
 * --INFO--
 * Address:	80087AC8
 * Size:	0000F8
 */
Vector3f Tube::setPos(f32 t)
{
	Vector3f pos = mStartPoint;
	pos          = pos + t * (mEndPoint - mStartPoint);
	return pos;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void CollPartUpdater::updateCollPart(CollPart* part)
{
	part->mCentre = getPos();
	part->mRadius = getSize();
}

/*
 * --INFO--
 * Address:	80087BC0
 * Size:	000124
 */
bool CollPart::isStickable()
{
	if (!mIsStickEnabled) {
		return false;
	}

	if (mPartType == PART_Platform) {
		if (getCode().match('c***', '*')) {
			getCode();
			getID();
			return false;
		}

		if (!getCode().match('s***', '*')) {
			return false;
		}

		return true;
	}

	if (isTubeType() || mPartType == PART_Collision) {
		if (getCode().match('s***', '*')) {
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	80087CE4
 * Size:	00005C
 */
bool CollPart::isClimbable()
{
	if (mPartType == PART_Platform && getCode().match('c***', '*')) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
bool CollPart::isDamagable()
{
	return true;
}

/*
 * --INFO--
 * Address:	80087D40
 * Size:	000050
 */
bool CollPart::isBouncy()
{
	if (getCode().match('b***', '*')) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80087D90
 * Size:	000034
 */
int CollPart::getChildCount()
{
	if (mCollInfo) {
		return mCollInfo->getChildCount();
	}

	return -1;
}

/*
 * --INFO--
 * Address:	80087DC4
 * Size:	000028
 */
CollPart* CollPart::getChild()
{
	if (mFirstChildIndex != -1) {
		return &mParentInfo->mCollParts[mFirstChildIndex];
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	80087DEC
 * Size:	00005C
 */
CollPart* CollPart::getChildAt(int idx)
{
	int currIdx = mFirstChildIndex;
	for (int i = 0; i < idx; i++) {
		if (currIdx == -1) {
			return nullptr;
		}

		currIdx = mParentInfo->mCollParts[currIdx].mNextIndex;
	}

	if (currIdx == -1) {
		return nullptr;
	}

	return &mParentInfo->mCollParts[currIdx];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
CollPart* CollPart::getNext()
{
	if (mNextIndex != -1) {
		return &mParentInfo->mCollParts[mNextIndex];
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	80087E48
 * Size:	00003C
 */
CollPart::CollPart()
{
	mIsUpdateActive = true;
	mNextIndex = mFirstChildIndex = -1;
	mCollInfo                     = nullptr;
	mParentInfo                   = nullptr;
	mPartUpdater                  = nullptr;
	mIsStickEnabled               = true;
}

/*
 * --INFO--
 * Address:	80087E84
 * Size:	00001C
 */
char* CollPart::getTypeString()
{
	return _typeStr[mPartType];
}

/*
 * --INFO--
 * Address:	80087EA0
 * Size:	00003C
 */
ID32 CollPart::getID()
{
	return mCollInfo->mId;
}

/*
 * --INFO--
 * Address:	80087EDC
 * Size:	00003C
 */
ID32 CollPart::getCode()
{
	return mCollInfo->mCode;
}

/*
 * --INFO--
 * Address:	80087F18
 * Size:	000164
 */
Matrix4f CollPart::getMatrix()
{
	Matrix4f collMat = mJointMatrix;
	Matrix4f outMat;
	invCamMat.multiplyTo(collMat, outMat);
	outMat.setTranslation(mCentre);
	return outMat;
}

/*
 * --INFO--
 * Address:	8008807C
 * Size:	0004A4
 */
void CollPart::update(Graphics& gfx, bool p2)
{
	if (mIsUpdateActive && mPartType != PART_Platform) {
		gsys->mTimer->start("CollPart", true);
		if (mPartUpdater) {
			mPartUpdater->updateCollPart(this);
		} else {
			mCentre      = mCollInfo->mCentrePosition;
			f32 worldPos = mCollInfo->mParentShape->calcJointWorldPos(gfx, mCollInfo->mJointIndex, mCentre);
			mRadius      = worldPos * mCollInfo->mRadius;
			invCamMat    = gfx.mCamera->mInverseLookAtMtx;
			mJointMatrix = mCollInfo->mParentShape->getAnimMatrix(mCollInfo->mJointIndex);
		}
		gsys->mTimer->stop("CollPart");

		if (!p2) {
			return;
		}

		gfx.useTexture(nullptr, 0);
		bool light = gfx.setLighting(false, nullptr);

		switch (mPartType) {
		case PART_BoundSphere:
			gfx.setColour(Colour(255, 180, 180, 255), true); // pink
			break;
		case PART_Collision:
			gfx.setColour(Colour(255, 0, 0, 255), true); // red
			break;
		case PART_Tube:
		case PART_TubeChild:
			gfx.setColour(Colour(255, 0, 255, 255), true); // purple
			break;
		case PART_Reference:
			gfx.setColour(Colour(255, 215, 20, 255), true); // yellow
			break;
		case PART_Platform:                                 // this is never called
			gfx.setColour(Colour(50, 150, 255, 255), true); // blue
			break;
		}

		gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);

		if (mPartType == PART_Tube) {
			gfx.drawCylinder(mCentre, getNext()->mCentre, mRadius, gfx.mCamera->mLookAtMtx);
		} else if (mPartType == PART_TubeChild) {
			gfx.drawCylinder(mCentre, getChild()->mCentre, mRadius, gfx.mCamera->mLookAtMtx);
		} else {
			gfx.drawSphere(mCentre, mRadius, gfx.mCamera->mLookAtMtx);
		}

		gfx.setLighting(light, nullptr);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A4
 */
bool CollPart::collide(Creature* collider, Vector3f& pushVector)
{
	if (!isCylinderType()) {
		Vector3f sep = collider->getCentre() - mCentre;
		f32 dist     = sep.normalise();
		if (dist <= collider->getSize() + mRadius) {
			pushVector = sep;
			pushVector = pushVector * (collider->getSize() + mRadius - dist);
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000158
 */
bool CollPart::collide(Vector3f& pos, f32 radius, Vector3f& pushVector)
{
	if (!isCylinderType()) {
		Vector3f sep = pos - mCentre;
		f32 dist     = sep.normalise();
		if (dist <= mRadius + radius) {
			pushVector = sep;
			pushVector = pushVector * (radius + mRadius - dist);
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	80088520
 * Size:	00066C
 */
bool CollPart::collide(CollPart* collidePart, Vector3f& pushVector)
{
	if (isBouncySphereType() && collidePart->isBouncySphereType()) {
		Vector3f sep = collidePart->mCentre - mCentre;
		f32 dist     = sep.normalise();
		if (dist <= mRadius + collidePart->mRadius) {
			pushVector = sep;
			pushVector = pushVector * (mRadius + collidePart->mRadius - dist);
			return true;
		}

	} else if (isCylinderType() && collidePart->isBouncySphereType()) {
		CollPart* other = getChild();
		Cylinder cyl(mCentre, other->mCentre, mRadius);
		Sphere sphere(collidePart->mCentre, collidePart->mRadius);
		Vector3f push;
		f32 depth;
		if (cyl.collide(sphere, push, depth)) {
			pushVector = push;
			return true;
		}

	} else if (isBouncySphereType() && collidePart->isCylinderType()) {
		CollPart* other = collidePart->getChild();
		Cylinder cyl(collidePart->mCentre, other->mCentre, collidePart->mRadius);
		Sphere sphere(mCentre, mRadius);
		Vector3f push;
		f32 depth;
		if (cyl.collide(sphere, push, depth)) {
			pushVector = push * -1.0f;
			return true;
		}

	} else if (isTubeType() && collidePart->isBouncySphereType()) {
		CollPart* other;
		if (mPartType == PART_Tube) {
			other = getNext();
		} else {
			other = getChild();
		}

		Tube tube(mCentre, other->mCentre, mRadius, other->mRadius);
		Sphere sphere(collidePart->mCentre, collidePart->mRadius);
		Vector3f push;
		f32 depth;
		if (tube.collide(sphere, push, depth)) {
			pushVector = push;
			return true;
		}

	} else if (isBouncySphereType() && collidePart->isTubeType()) {
		CollPart* other;
		if (collidePart->mPartType == PART_Tube) {
			other = collidePart->getNext();
		} else {
			other = collidePart->getChild();
		}

		Tube tube(collidePart->mCentre, other->mCentre, collidePart->mRadius, other->mRadius);
		Sphere sphere(mCentre, mRadius);
		Vector3f push;
		f32 depth;
		if (tube.collide(sphere, push, depth)) {
			pushVector = push * -1.0f;
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	80088B8C
 * Size:	0000A4
 */
void CollPart::makeTube(Tube& tube)
{
	CollPart* other;
	if (mPartType == PART_Tube) {
		other = getNext();
	} else {
		other = getChild();
	}

	tube.mStartPoint  = mCentre;
	tube.mStartRadius = mRadius;
	tube.mEndPoint    = other->mCentre;
	tube.mEndRadius   = other->mRadius;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void CollPart::makeSphere(Sphere& sphere)
{
	sphere.mCentre = mCentre;
	sphere.mRadius = mRadius;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CollPart::makeCylinder(Cylinder&)
{
	PRINT("NOT YET !! DONT CALL ME NOW \n"); // lol
	ERROR("mail to saru\n");
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
bool CollPart::samePlatShape(Shape* shape)
{
	return mPartType == PART_Platform && mCollInfo && mCollInfo->mPlatShape == shape;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80088C30
 * Size:	0000A0
 */
CollInfo::CollInfo(int maxParts)
{
	mShape      = nullptr;
	mPartsCount = 0;
	if (maxParts == 0) {
		mMaxParts           = 10;
		mUseDefaultMaxParts = 1;
	} else {
		mMaxParts           = maxParts;
		mUseDefaultMaxParts = 0;
		mCollParts          = new CollPart[mMaxParts];
		mPartIDs            = new u32[mMaxParts];
	}
}

/*
 * --INFO--
 * Address:	80088CD0
 * Size:	000034
 */
void CollInfo::enableStick()
{
	for (int i = 0; i < mPartsCount; i++) {
		mCollParts[i].mIsStickEnabled = true;
	}
}

/*
 * --INFO--
 * Address:	80088D04
 * Size:	000034
 */
void CollInfo::disableStick()
{
	for (int i = 0; i < mPartsCount; i++) {
		mCollParts[i].mIsStickEnabled = false;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void CollInfo::startUpdate(u32 partID)
{
	CollPart* part        = getSphere(partID);
	part->mIsUpdateActive = true;
	if (part->mFirstChildIndex != -1) {
		startUpdateRec(part->mFirstChildIndex);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A8
 */
void CollInfo::startUpdateRec(int childIdx)
{
	CollPart* part        = &mCollParts[childIdx];
	part->mIsUpdateActive = true;
	if (part->mNextIndex != -1) {
		startUpdateRec(part->mNextIndex);
	}

	if (part->mFirstChildIndex != -1) {
		startUpdateRec(part->mFirstChildIndex);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void CollInfo::stopUpdate(u32 partID)
{
	CollPart* part        = getSphere(partID);
	part->mIsUpdateActive = false;
	if (part->mFirstChildIndex != -1) {
		stopUpdateRec(part->mFirstChildIndex);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A8
 */
void CollInfo::stopUpdateRec(int childIdx)
{
	CollPart* part        = &mCollParts[childIdx];
	part->mIsUpdateActive = false;
	if (part->mNextIndex != -1) {
		stopUpdateRec(part->mNextIndex);
	}

	if (part->mFirstChildIndex != -1) {
		stopUpdateRec(part->mFirstChildIndex);
	}
}

/*
 * --INFO--
 * Address:	80088D38
 * Size:	0001C0
 */
CollPart* CollInfo::checkCollisionSpecial(Vector3f& pos, f32 radius, CndCollPart* cond)
{
	Vector3f vec;
	for (int i = 0; i < mPartsCount; i++) {
		CollPart* part = &mCollParts[i];
		if (part->isReferenceType() && (!cond || cond->satisfy(part)) && part->collide(pos, radius, vec)) {
			return part;
		}
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
CollPart* CollInfo::checkCollisionSpecialRec(int, Vector3f&, f32, CndCollPart*)
{
	return nullptr;
}

/*
 * --INFO--
 * Address:	80088F00
 * Size:	000028
 */
CollPart* CollInfo::checkCollision(Creature* creature, Vector3f& p2)
{
	return checkCollisionRec(creature, 0, p2);
}

/*
 * --INFO--
 * Address:	80088F28
 * Size:	000624
 */
CollPart* CollInfo::checkCollisionRec(Creature* collider, int childIdx, Vector3f& pushVector)
{
	CollPart* part = &mCollParts[childIdx];
	if (part->collide(collider, pushVector)) {
		if (!part->isSphereType()) {
			return part;
		}
		if (part->mPartType == PART_Cylinder) {
			return nullptr;
		}
		return checkCollisionRec(collider, part->mFirstChildIndex, pushVector);
	}

	if (childIdx != 0 && part->mNextIndex != -1) {
		return checkCollisionRec(collider, part->mNextIndex, pushVector);
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	80089574
 * Size:	000034
 */
bool CollInfo::checkCollision(CollInfo* infoB, CollPart** outPartA, CollPart** outPartB, Vector3f& pushVector)
{
	return checkCollisionRec(infoB, 0, 0, outPartA, outPartB, pushVector);
}

/*
 * --INFO--
 * Address:	800895A8
 * Size:	000160
 */
bool CollInfo::checkCollisionRec(CollInfo* infoB, int partIdxA, int partIdxB, CollPart** outPartA, CollPart** outPartB,
                                 Vector3f& pushVector)
{
	CollPart* part  = &mCollParts[partIdxA];
	CollPart* other = &infoB->mCollParts[partIdxB];

	if (part->collide(other, pushVector)) {
		if (!part->isSphereType() && !other->isSphereType()) {
			*outPartA = part;
			*outPartB = other;
			return true;
		}

		if (part->isSphereType()) {
			return checkCollisionRec(infoB, part->mFirstChildIndex, partIdxB, outPartA, outPartB, pushVector);
		}

		return checkCollisionRec(infoB, partIdxA, other->mFirstChildIndex, outPartA, outPartB, pushVector);
	}

	if (partIdxA && part->mNextIndex != -1) {
		return checkCollisionRec(infoB, part->mNextIndex, partIdxB, outPartA, outPartB, pushVector);
	}

	if (partIdxB && other->mNextIndex != -1) {
		return checkCollisionRec(infoB, partIdxA, other->mNextIndex, outPartA, outPartB, pushVector);
	}

	*outPartA = nullptr;
	*outPartB = nullptr;
	return false;
}

/*
 * --INFO--
 * Address:	80089708
 * Size:	000008
 */
CollPart* CollInfo::getBoundingSphere()
{
	return &mCollParts[0];
}

/*
 * --INFO--
 * Address:	80089710
 * Size:	000060
 */
CollPart* CollInfo::getSphere(u32 id)
{
	int idx = getId2Index(id);
	if (idx == -1) {
		ID32 badID(id);
		return nullptr;
	}
	return &mCollParts[idx];
}

/*
 * --INFO--
 * Address:	80089770
 * Size:	00017C
 */
CollPart* CollInfo::getNearestCollPart(Vector3f& pos, u32 tag)
{
	f32 minDist           = 1280000.0f;
	CollPart* nearestPart = nullptr;
	for (int i = 0; i < mPartsCount; i++) {
		CollPart* part = &mCollParts[i];
		if (part->isPlatformType()) {
			continue;
		}

		if (part->getCode().match(tag, '*')) {
			Vector3f sep = pos - part->mCentre;
			f32 dist     = sep.length();
			if (minDist > dist) {
				minDist     = dist;
				nearestPart = part;
			}
		}
	}

	return nearestPart;
}

/*
 * --INFO--
 * Address:	800898EC
 * Size:	000130
 */
CollPart* CollInfo::getRandomCollPart(u32 tag)
{
	CollPart* partList[128];
	int count = 0;
	for (int i = 0; i < mPartsCount; i++) {
		CollPart* part = &mCollParts[i];
		if (part->isPlatformType()) {
			continue;
		}

		if (part->getCode().match(tag, '*') && count < 128) {
			partList[count++] = part;
		}
	}

	if (count > 0) {
		f32 r       = gsys->getRand(1.0f);
		int randIdx = count * r * 0.999f;
		return partList[randIdx];
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	80089A1C
 * Size:	0000D0
 */
CollPart* CollInfo::getPlatform(DynCollObject* obj)
{
	Shape* platShape = obj->getShape();
	if (!platShape) {
		return nullptr;
	}

	for (int i = 0; i < mPartsCount; i++) {
		if (mCollParts[i].samePlatShape(platShape)) {
			return &mCollParts[i];
		}
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	80089AEC
 * Size:	000064
 */
void CollInfo::updateInfo(Graphics& gfx, bool p2)
{
	for (int i = 0; i < mPartsCount; i++) {
		mCollParts[i].update(gfx, p2);
	}
}

/*
 * --INFO--
 * Address:	80089B50
 * Size:	000014
 */
bool CollInfo::hasInfo()
{
	return mPartsCount != 0;
}

/*
 * --INFO--
 * Address:	80089B64
 * Size:	0000A4
 */
void CollInfo::initInfo(Shape* shape, CollPart* parts, u32* ids)
{
	if (mUseDefaultMaxParts) {
		mCollParts = parts;
		mPartIDs   = ids;

		if (!mCollParts || !mPartIDs) {
			PRINT("inplae : initInfo(%x,%x,%x)\n", shape, mCollParts, mPartIDs);
			ERROR("sorry\n");
		}
	}

	for (int i = 0; i < mMaxParts; i++) {
		mCollParts[i].mParentInfo = this;
	}

	mShape            = shape;
	ObjCollInfo* info = static_cast<ObjCollInfo*>(shape->mCollisionInfo.mChild);
	mPartsCount       = 0;
	createPart(info, 0, true);
	makeTree();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void CollInfo::dumpInfo()
{
	for (int i = 0; i < mPartsCount; i++) {
		PRINT("index %d id(%s) code(%s): next=%d child=%d %s\n", i, mCollParts[i].getID().mStringID, mCollParts[i].getCode().mStringID,
		      mCollParts[i].mNextIndex, mCollParts[i].mFirstChildIndex, mCollParts[i].getTypeString());
		if (mCollParts[i].getCode().match('***1', '*')) {
			PRINT("***1 code FOUND!!\n");
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void CollInfo::makeTubes(u32 partID, int count)
{
	CollPart* part = getSphere(partID);
	if (!part) {
		PRINT("no CollPart for making tubes\n");
		ERROR("mail to nishimeck\n");
	}

	for (int i = 0; i < count; i++) {
		CollPart* next = part->getNext();
		if (!next) {
			PRINT("failed to make %d tube \n", i);
			ERROR("mail to nrta\n");
		}

		part->mPartType = PART_Tube;
		part            = next;
	}
}

/*
 * --INFO--
 * Address:	80089C08
 * Size:	0000B0
 */
void CollInfo::makeTubesChild(u32 partID, int count)
{
	CollPart* part = getSphere(partID);
	if (!part) {
		PRINT("no CollPart for making tubes\n");
		ERROR("mail to nishimeck\n");
	}

	for (int i = 0; i < count; i++) {
		CollPart* child = part->getChild();
		if (!child) {
			PRINT("failed to make %d tube \n", i);
			ERROR("mail to nrta\n");
		}

		part->mPartType = PART_TubeChild;
		part            = child;
	}
}

/*
 * --INFO--
 * Address:	80089CB8
 * Size:	000078
 */
void CollInfo::setUpdater(u32 id, CollPartUpdater* updater)
{
	CollPart* part = getSphere(id);
	if (part) {
		part->mPartUpdater = updater;
	} else {
		PRINT("setUpdater::no CollPart !\n");
		ERROR("mail to warata\n");
	}
}

/*
 * --INFO--
 * Address:	80089D30
 * Size:	0001BC
 */
void CollInfo::createPart(ObjCollInfo* objInfo, int p2, bool p3)
{
	if (!objInfo) {
		return;
	}

	if (objInfo->mCollType == OCT_Platform) {
		CollPart* part          = &mCollParts[mPartsCount];
		part->mCollInfo         = objInfo;
		mPartIDs[mPartsCount++] = objInfo->mId.mId;
		part->mPartType         = PART_Platform;
		if (objInfo->mNext) {
			createPart(static_cast<ObjCollInfo*>(objInfo->mNext), p2, p3);
		}
		return;
	}

	if (mPartsCount >= mMaxParts) {
		PRINT("### TOO MANY COLLINFOS ! (LIMIT=%d)\n", mMaxParts);
		return;
	}

	CollPart* part          = &mCollParts[mPartsCount];
	part->mCollInfo         = objInfo;
	mPartIDs[mPartsCount++] = objInfo->mId.mId;

	if (p2 == 0 && mPartsCount > 1) {
		part->mPartType = PART_Reference;

	} else {
		if (objInfo->mChild) {
			if (objInfo->mId.match('cyl*', '*')) {
				part->mPartType = PART_Cylinder;
			} else {
				part->mPartType = PART_BoundSphere;
			}
		} else if (p2 > 0 || p3) {
			part->mPartType = PART_Collision;
		}
	}

	if (objInfo->mChild) {
		if (part->mPartType == PART_Reference) {
			createPart(static_cast<ObjCollInfo*>(objInfo->mChild), p2, false);
		} else {
			createPart(static_cast<ObjCollInfo*>(objInfo->mChild), p2 + 1, false);
		}
	}

	if (objInfo->mNext) {
		createPart(static_cast<ObjCollInfo*>(objInfo->mNext), p2, false);
	}
}

/*
 * --INFO--
 * Address:	80089EEC
 * Size:	000044
 */
int CollInfo::getId2Index(u32 id)
{
	for (int i = 0; i < mPartsCount; i++) {
		if (id == mPartIDs[i]) {
			return i;
		}
	}

	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
int CollInfo::getIndex(ObjCollInfo* objInfo)
{
	for (int i = 0; i < mPartsCount; i++) {
		if (mCollParts[i].mCollInfo == objInfo) {
			return i;
		}
	}

	return -1;
}

/*
 * --INFO--
 * Address:	80089F30
 * Size:	0000F8
 */
void CollInfo::makeTree()
{
	for (int i = 0; i < mPartsCount; i++) {
		ObjCollInfo* objInfo = mCollParts[i].mCollInfo;
		if (objInfo->mNext) {
			mCollParts[i].mNextIndex = getIndex(static_cast<ObjCollInfo*>(objInfo->mNext));
		} else {
			mCollParts[i].mNextIndex = -1;
		}

		if (objInfo->mChild) {
			mCollParts[i].mFirstChildIndex = getIndex(static_cast<ObjCollInfo*>(objInfo->mChild));
		} else {
			mCollParts[i].mFirstChildIndex = -1;
		}
	}
}
