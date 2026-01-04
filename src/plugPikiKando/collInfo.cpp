#include "Collision.h"
#include "Creature.h"
#include "DynColl.h"
#include "Geometry.h"
#include "zen/Math.h"

#include "Dolphin/os.h"
#include "Graphics.h"
#include "Shape.h"
#include "sysNew.h"
#include "timers.h"

#include "DebugLog.h"

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(9)

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("collInfo");

Matrix4f invCamMat;

static immut char* _typeStr[] = {
	"COLLISION",   // PART_Collision
	"BOUNDSPHERE", // PART_BoundSphere
	"REFERENCE",   // PART_Reference
	"PLATFORM",    // PART_Platform
	"CYLINDER",    // PART_Cylinder
	"TUBE",        // PART_Tube
	"TUBE_CHILD",  // PART_TubeChild
};

/**
 * @brief Returns the XZ-plane distance from @p point to this cylinder segment.
 * @note Ignores Y; clamps to the end points when projected outside the segment.
 * Address:	100E7340 in DLL
 */
f32 Cylinder::get2dDist(immut Vector3f& point) immut
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

/**
 * @brief Sphere vs finite cylinder collision.
 *
 * @param sphere Sphere to test.
 * @param pushVector Output push direction/amount (from sphere out of cylinder).
 * @param depth Output axis ratio ($0..1$) where the sphere projects onto the cylinder.
 * Address:	100E7530 in DLL
 */
bool Cylinder::collide(const Sphere& sphere, Vector3f& pushVector, f32& depth) immut
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

/**
 * @brief Computes a linear ratio along the tube's Y span.
 * @return Ratio along Y, or -1 if start/end have identical Y.
 */
f32 Tube::getYRatio(f32 heightToCheck) immut
{
	const f32 r = mEndPoint.y - mStartPoint.y;
	if (r != 0.0f) {
		return (heightToCheck - mStartPoint.y) / (r);
	}

	return -1.0f;
}

/**
 * @brief Sphere vs tapered tube collision (radius linearly interpolates start->end).
 * @param depth Output axis ratio ($0..1$) where the sphere projects onto the tube.
 */
bool Tube::collide(const Sphere& sphere, Vector3f& pushVector, f32& depth) immut
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

/**
 * @brief Returns the axis ratio of @p vec projected onto the cylinder line.
 */
f32 Cylinder::getPosRatio(const Vector3f& vec) immut
{
	Vector3f axisVec = mEndPoint - mStartPoint;
	Vector3f dir     = axisVec;
	f32 len          = dir.normalise();
	return dir.DP(vec - mStartPoint) / len;
}

/**
 * @brief Returns the axis ratio of @p pos projected onto the tube line.
 */
f32 Tube::getPosRatio(const Vector3f& pos) immut
{
	Vector3f axisVec = mEndPoint - mStartPoint;
	Vector3f dir     = axisVec;
	f32 len          = dir.normalise();

	return dir.DP(pos - mStartPoint) / len;
}

/**
 * @brief Linearly interpolates tube radius at @p ratio.
 * @note UNUSED Size: 000020
 */
f32 Tube::getRatioRadius(f32 ratio) immut
{
	return (1.0f - ratio) * mStartRadius + ratio * mEndRadius;
}

/**
 * @brief Computes a point on the tube surface and a surface-gradient direction.
 */
void Tube::getPosGradient(immut Vector3f& inputPos, f32 t, Vector3f& surfacePos, Vector3f& surfaceGrad) immut
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

/**
 * @brief Returns the point at axis ratio @p t between start and end.
 */
Vector3f Tube::setPos(f32 t) immut
{
	Vector3f pos = mStartPoint;
	pos          = pos + t * (mEndPoint - mStartPoint);
	return pos;
}

/**
 * @brief Updates a part using the updater's position/size.
 * @note UNUSED Size: 00007C
 */
void CollPartUpdater::updateCollPart(CollPart* part)
{
	part->mCentre = getPos();
	part->mRadius = getSize();
}

/**
 * @brief Returns true if this part is eligible for sticking.
 * @note Uses ID32::match patterns like 's***'/'c***'; effectively checks the leading character.
 */
bool CollPart::isStickable()
{
	if (!mIsStickEnabled) {
		return false;
	}

	if (isPlatformType()) {
		if (getCode().match('c***')) {
			PRINT("collide with code c**** : code(%s) id(%s)\n", getCode().mStringID, getID().mStringID);
			return false;
		}

		if (!getCode().match('s***')) {
			return false;
		}

		return true;
	}

	if (isTubeType() || isCollisionType()) {
		if (getCode().match('s***')) {
			return true;
		}
	}

	return false;
}

/**
 * @brief Returns true if this platform part is climbable.
 * @note Climbable platforms are tagged with a code starting with 'c' ("c***").
 */
bool CollPart::isClimbable()
{
	if (isPlatformType() && getCode().match('c***')) {
		return true;
	}
	return false;
}

/**
 * @brief Returns true if this part can take damage.
 * @note UNUSED Size: 000008
 */
bool CollPart::isDamagable()
{
	return true;
}

/**
 * @brief Returns true if this part is bouncy.
 * @note Bouncy parts are tagged with a code starting with 'b' ("b***").
 */
bool CollPart::isBouncy()
{
	if (getCode().match('b***')) {
		return true;
	}
	return false;
}

/**
 * @brief Returns the number of children in the source ObjCollInfo, if present.
 */
int CollPart::getChildCount()
{
	if (mCollInfo) {
		return mCollInfo->getChildCount();
	}

	return -1;
}

/**
 * @brief Returns the first child CollPart in the built tree.
 */
CollPart* CollPart::getChild()
{
	if (mFirstChildIndex != -1) {
		return &mParentInfo->mCollParts[mFirstChildIndex];
	}
	return nullptr;
}

/**
 * @brief Returns the Nth child CollPart by following the sibling chain.
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

/**
 * @brief Returns the next sibling CollPart.
 * @note UNUSED Size: 000028
 */
CollPart* CollPart::getNext()
{
	if (mNextIndex != -1) {
		return &mParentInfo->mCollParts[mNextIndex];
	}
	return nullptr;
}

/**
 * @brief Constructs a CollPart with default flags and null pointers.
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

/**
 * @brief Returns a debug string for this part type.
 */
immut char* CollPart::getTypeString()
{
	return _typeStr[mPartType];
}

/**
 * @brief Returns the ID of the underlying ObjCollInfo.
 */
ID32 CollPart::getID()
{
	return mCollInfo->mId;
}

/**
 * @brief Returns the code/tag of the underlying ObjCollInfo.
 */
ID32 CollPart::getCode()
{
	return mCollInfo->mCode;
}

/**
 * @brief Returns the part's joint matrix transformed into camera space.
 * @note Translation is overridden with the current part centre.
 */
Matrix4f CollPart::getMatrix()
{
	Matrix4f collMat = mJointMatrix;
	Matrix4f outMat;
	invCamMat.multiplyTo(collMat, outMat);
	outMat.setTranslation(mCentre);
	return outMat;
}

/**
 * @brief Updates derived world-space centre/radius and optionally draws debug geometry.
 */
void CollPart::update(Graphics& gfx, bool drawDebug)
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

		if (!drawDebug) {
			return;
		}

		gfx.useTexture(nullptr, GX_TEXMAP0);
		bool light = gfx.setLighting(false, nullptr);

		switch (mPartType) {
		case PART_BoundSphere:
		{
			gfx.setColour(Colour(255, 180, 180, 255), true); // pink
			break;
		}
		case PART_Collision:
		{
			gfx.setColour(Colour(255, 0, 0, 255), true); // red
			break;
		}
		case PART_Tube:
		case PART_TubeChild:
		{
			gfx.setColour(Colour(255, 0, 255, 255), true); // purple
			break;
		}
		case PART_Reference:
		{
			gfx.setColour(Colour(255, 215, 20, 255), true); // yellow
			break;
		}
		case PART_Platform: // this is never called
		{
			gfx.setColour(Colour(50, 150, 255, 255), true); // blue
			break;
		}
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

/**
 * @brief Sphere-style collision against a creature's bounding sphere.
 * @note UNUSED Size: 0001A4
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

/**
 * @brief Sphere-style collision against a sphere at @p pos with radius @p radius.
 * @note UNUSED Size: 000158
 */
bool CollPart::collide(immut Vector3f& pos, f32 radius, Vector3f& pushVector)
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

/**
 * @brief Collides this part against another part (sphere/cylinder/tube combinations).
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

/**
 * @brief Fills @p tube from this part and its linked endpoint (next or child).
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

/**
 * @brief Fills @p sphere from this part's centre/radius.
 * @note UNUSED Size: 000024
 */
void CollPart::makeSphere(Sphere& sphere)
{
	sphere.mCentre = mCentre;
	sphere.mRadius = mRadius;
}

/**
 * @brief Cylinder construction helper (not implemented).
 * @note UNUSED Size: 000004
 */
void CollPart::makeCylinder(Cylinder&)
{
	PRINT("NOT YET !! DONT CALL ME NOW \n"); // lol
	ERROR("mail to saru\n");
}

/**
 * @brief True if this part represents @p shape as a platform.
 * @note UNUSED Size: 000048
 */
bool CollPart::samePlatShape(Shape* shape)
{
	return mPartType == PART_Platform && mCollInfo && mCollInfo->mPlatShape == shape;
	// UNUSED FUNCTION
}

/**
 * @brief Creates a CollInfo container for up to @p maxParts parts.
 * @note If @p maxParts is 0, external arrays are provided later via initInfo().
 */
CollInfo::CollInfo(int maxParts)
{
	mShape      = nullptr;
	mPartsCount = 0;
	if (maxParts == 0) {
		mMaxParts           = 10;
		mUseDefaultMaxParts = true;
	} else {
		mMaxParts           = maxParts;
		mUseDefaultMaxParts = false;
		mCollParts          = new CollPart[mMaxParts];
		mPartIDs            = new u32[mMaxParts];
	}
}

/**
 * @brief Enables sticking on all parts.
 */
void CollInfo::enableStick()
{
	for (int i = 0; i < mPartsCount; i++) {
		mCollParts[i].mIsStickEnabled = true;
	}
}

/**
 * @brief Disables sticking on all parts.
 */
void CollInfo::disableStick()
{
	for (int i = 0; i < mPartsCount; i++) {
		mCollParts[i].mIsStickEnabled = false;
	}
}

/**
 * @brief Enables updates starting at @p partID, including its descendants.
 * @note UNUSED Size: 000048
 */
void CollInfo::startUpdate(u32 partID)
{
	CollPart* part        = getSphere(partID);
	part->mIsUpdateActive = true;
	if (part->mFirstChildIndex != -1) {
		startUpdateRec(part->mFirstChildIndex);
	}
}

/**
 * @brief Recursively enables updates for the subtree rooted at @p childIdx.
 * @note UNUSED Size: 0001A8
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

/**
 * @brief Disables updates starting at @p partID, including its descendants.
 * @note UNUSED Size: 000048
 */
void CollInfo::stopUpdate(u32 partID)
{
	CollPart* part        = getSphere(partID);
	part->mIsUpdateActive = false;
	if (part->mFirstChildIndex != -1) {
		stopUpdateRec(part->mFirstChildIndex);
	}
}

/**
 * @brief Recursively disables updates for the subtree rooted at @p childIdx.
 * @note UNUSED Size: 0001A8
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

/**
 * @brief Tests @p pos/@p radius against reference parts that satisfy @p cond.
 */
CollPart* CollInfo::checkCollisionSpecial(immut Vector3f& pos, f32 radius, CndCollPart* cond)
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

/**
 * @brief Unused recursive special-collision helper.
 * @note UNUSED Size: 000008
 */
CollPart* CollInfo::checkCollisionSpecialRec(int, immut Vector3f&, f32, CndCollPart*)
{
	return nullptr;
}

/**
 * @brief Collides @p creature against this CollInfo's part tree.
 */
CollPart* CollInfo::checkCollision(Creature* creature, Vector3f& pushVec)
{
	return checkCollisionRec(creature, 0, pushVec);
}

/**
 * @brief Recursive creature collision; descends into child spheres and iterates siblings.
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

/**
 * @brief Collides this CollInfo against @p infoB and returns the colliding parts.
 */
bool CollInfo::checkCollision(CollInfo* infoB, CollPart** outPartA, CollPart** outPartB, Vector3f& pushVector)
{
	return checkCollisionRec(infoB, 0, 0, outPartA, outPartB, pushVector);
}

/**
 * @brief Recursive pairwise collision; when both sides are non-spheres, returns the hit parts.
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

/**
 * @brief Returns the root/bounding sphere part (index 0).
 */
CollPart* CollInfo::getBoundingSphere()
{
	return &mCollParts[0];
}

/**
 * @brief Returns the part with the given ID, or nullptr if not present.
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

/**
 * @brief Returns the nearest non-platform part whose code matches @p tag.
 */
CollPart* CollInfo::getNearestCollPart(immut Vector3f& pos, u32 tag)
{
	f32 minDist           = 1280000.0f;
	CollPart* nearestPart = nullptr;
	for (int i = 0; i < mPartsCount; i++) {
		CollPart* part = &mCollParts[i];
		if (part->isPlatformType()) {
			continue;
		}

		if (part->getCode().match(tag)) {
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

/**
 * @brief Picks a random non-platform part whose code matches @p tag.
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

		if (part->getCode().match(tag) && count < 128) {
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

/**
 * @brief Returns the platform part corresponding to @p obj's Shape, if any.
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

/**
 * @brief Updates all parts and optionally draws debug geometry.
 */
void CollInfo::updateInfo(Graphics& gfx, bool drawDebug)
{
	for (int i = 0; i < mPartsCount; i++) {
		mCollParts[i].update(gfx, drawDebug);
	}
}

/**
 * @brief True if any collision parts have been built.
 */
bool CollInfo::hasInfo()
{
	return mPartsCount != 0;
}

/**
 * @brief Initializes from @p shape and builds the part tree into the provided arrays.
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

/**
 * @brief Prints a debug dump of all parts (index/id/code/links/type).
 * @note UNUSED Size: 0000DC
 */
void CollInfo::dumpInfo()
{
	for (int i = 0; i < mPartsCount; i++) {
		PRINT("index %d id(%s) code(%s): next=%d child=%d %s\n", i, mCollParts[i].getID().mStringID, mCollParts[i].getCode().mStringID,
		      mCollParts[i].mNextIndex, mCollParts[i].mFirstChildIndex, mCollParts[i].getTypeString());
		if (mCollParts[i].getCode().match('***1')) {
			PRINT("***1 code FOUND!!\n");
		}
	}
}

/**
 * @brief Marks a chain of @p count parts (via next pointers) as tube segments.
 * @note UNUSED Size: 0000B0
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

/**
 * @brief Marks a chain of @p count parts (via child pointers) as tube-child segments.
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

/**
 * @brief Attaches a custom updater to the part with ID @p id.
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

/**
 * @brief Flattens an ObjCollInfo tree into the part arrays.
 * @note Uses IDs like "cyl*" to tag cylinders and codes like "s***"/"c***" for gameplay.
 * @param depth Current recursion depth (0=root).
 * @param forceCollision If true, marks all parts as collision types regardless of depth.
 */
void CollInfo::createPart(ObjCollInfo* objInfo, int depth, bool forceCollision)
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
			createPart(static_cast<ObjCollInfo*>(objInfo->mNext), depth, forceCollision);
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

	if (depth == 0 && mPartsCount > 1) {
		part->mPartType = PART_Reference;

	} else {
		if (objInfo->mChild) {
			if (objInfo->mId.match('cyl*')) {
				part->mPartType = PART_Cylinder;
			} else {
				part->mPartType = PART_BoundSphere;
			}
		} else if (depth > 0 || forceCollision) {
			part->mPartType = PART_Collision;
		}
	}

	if (objInfo->mChild) {
		if (part->mPartType == PART_Reference) {
			createPart(static_cast<ObjCollInfo*>(objInfo->mChild), depth, false);
		} else {
			createPart(static_cast<ObjCollInfo*>(objInfo->mChild), depth + 1, false);
		}
	}

	if (objInfo->mNext) {
		createPart(static_cast<ObjCollInfo*>(objInfo->mNext), depth, false);
	}
}

/**
 * @brief Maps a part ID to an array index.
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

/**
 * @brief Finds the array index for an ObjCollInfo pointer.
 * @note UNUSED Size: 000048
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

/**
 * @brief Builds sibling/child indices from the ObjCollInfo next/child pointers.
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
