#include "DebugLog.h"
#include "Graphics.h"
#include "Shape.h"
#include "Slime.h"
#include "sysNew.h"

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
DEFINE_PRINT("SlimeBody");

/*
 * --INFO--
 * Address:	8016A630
 * Size:	00013C
 */
SlimeBody::SlimeBody(Slime* slime)
{
	mSlime                     = slime;
	mVertexNormalIndices       = new u16[mSlime->mShapeObject->mShape->mVertexCount];
	mNearestVertexToJoint      = new int[mSlime->mShapeObject->mShape->mJointCount - 1];
	mNormalisedVertexPositions = new Vector3f[mSlime->mShapeObject->mShape->mVertexCount];

	mVelocities         = new Vector3f[bossMgr->mSlimeCreatureCount];
	mPrevVelocities     = new Vector3f[bossMgr->mSlimeCreatureCount];
	mRelativeVelocities = new Vector3f[bossMgr->mSlimeCreatureCount];
}

/*
 * --INFO--
 * Address:	8016A76C
 * Size:	0002A4
 */
void SlimeBody::init(Slime* slime)
{
	mSlime = slime;
	mSlime->mShapeObject->mShape->makeNormalIndexes(mVertexNormalIndices);

	int i;
	for (i = 1; i < mSlime->mShapeObject->mShape->mJointCount; i++) {
		f32 minDist = 12800.0f;
		Vector3f jointAnimPos;
		mSlime->mShapeObject->mShape->mJointList[i].mAnimMatrix.getColumn(3, jointAnimPos);

		for (int j = 0; j < mSlime->mShapeObject->mShape->mVertexCount; j++) {
			f32 dist = jointAnimPos.distance(mSlime->mShapeObject->mShape->mVertexList[j]);
			if (dist < minDist) {
				minDist                      = dist;
				mNearestVertexToJoint[i - 1] = j;
			}
		}
	}

	for (i = 0; i < mSlime->mShapeObject->mShape->mVertexCount; i++) {
		mNormalisedVertexPositions[i].x = mSlime->mShapeObject->mShape->mVertexList[i].x;
		mNormalisedVertexPositions[i].y = mSlime->mShapeObject->mShape->mVertexList[i].y;
		mNormalisedVertexPositions[i].z = mSlime->mShapeObject->mShape->mVertexList[i].z;

		mNormalisedVertexPositions[i].normalise();
	}

	for (i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		mVelocities[i].set(0.0f, 0.0f, 0.0f);
		mPrevVelocities[i] = mSlime->mSRT.t;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
void SlimeBody::traceCreaturePosition()
{
	for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		mVelocities[i].multiply(C_SLIME_PROP(mSlime).mTraceDrag());

		Vector3f displacement = mSlime->mSlimeCreatures[i]->mSRT.t - mPrevVelocities[i];
		displacement.multiply(C_SLIME_PROP(mSlime).mSpringForce());

		mVelocities[i].add(displacement);
		mPrevVelocities[i].add(mVelocities[i]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void SlimeBody::makeCentrePosition()
{
	mSlime->mSRT.t.set(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		mSlime->mSRT.t.add(mSlime->mSlimeCreatures[i]->mSRT.t);
	}

	mSlime->mSRT.t.multiply(0.25f); // Average of 4 parts
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void SlimeBody::makeInnerPosition()
{
	for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		mRelativeVelocities[i].sub(mPrevVelocities[i], mSlime->mSRT.t);
		mRelativeVelocities[i].y += C_SLIME_PROP(mSlime).mBodyHeight();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
void SlimeBody::makeMaxRadius()
{
	mMaxRadius = 0.0f;
	for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		f32 distFromCentre = mRelativeVelocities[i].length();
		if (distFromCentre > mMaxRadius) {
			mMaxRadius = distFromCentre;
		}
	}

	mMaxRadius += C_SLIME_PROP(mSlime).mMaxRadiusCompensation();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void SlimeBody::setSpherePosition()
{
	for (int i = 0; i < mSlime->mShapeObject->mShape->mVertexCount; i++) {
		mSlime->mShapeObject->mShape->mVertexList[i].x = mMaxRadius * mNormalisedVertexPositions[i].x;
		mSlime->mShapeObject->mShape->mVertexList[i].y = mMaxRadius * mNormalisedVertexPositions[i].y;
		mSlime->mShapeObject->mShape->mVertexList[i].z = mMaxRadius * mNormalisedVertexPositions[i].z;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000128
 */
f32 SlimeBody::calcVertexScore(Vector3f* vertex, Vector3f* creatureNormals, f32* creatureScores)
{
	f32 score = 0.0f;
	for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		creatureNormals[i].x = vertex->x - mRelativeVelocities[i].x;
		creatureNormals[i].y = (vertex->y - mRelativeVelocities[i].y) * mSlime->mBodyThickness;
		creatureNormals[i].z = vertex->z - mRelativeVelocities[i].z;
		creatureScores[i]    = mSlime->mAppearanceScale
		                  / std::sqrtf(SQUARE(creatureNormals[i].x) + SQUARE(creatureNormals[i].y) + SQUARE(creatureNormals[i].z));
		score += creatureScores[i];
	}
	return score;
}

/*
 * --INFO--
 * Address:	8016AA10
 * Size:	0002EC
 */
void SlimeBody::sortPosition(Vector3f* outVertex, Vector3f* outNormal, Vector3f* vertical)
{
	Vector3f creatureNormals[4];
	Vector3f minNormal(outVertex->x, outVertex->y, outVertex->z);
	Vector3f targetNormal(vertical->x, vertical->y, vertical->z);
	f32 totalScore; // fun fact: declaring this here is load bearing for stack placement.
	f32 creatureScores[4];
	for (int i = 0; i < C_SLIME_PROP(mSlime).mMaxSortCount(); i++) {
		outVertex->x = (minNormal.x + targetNormal.x) / 2.0f;
		outVertex->y = (minNormal.y + targetNormal.y) / 2.0f;
		outVertex->z = (minNormal.z + targetNormal.z) / 2.0f;

		totalScore = calcVertexScore(outVertex, creatureNormals, creatureScores);
		if (totalScore > C_SLIME_PROP(mSlime).mVertexPositionScore()) {
			targetNormal.set(*outVertex);
		} else {
			minNormal.set(*outVertex);
		}
	}

	outNormal->x = 0.0f;
	outNormal->y = 0.0f;
	outNormal->z = 0.0f;

	for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		outNormal->x += creatureScores[i] * creatureNormals[i].x;
		outNormal->y += creatureScores[i] * creatureNormals[i].y;
		outNormal->z += creatureScores[i] * creatureNormals[i].z;
	}

	outNormal->normalise();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void SlimeBody::makeSlimeBody()
{
	Vector3f up(0.0f, C_SLIME_PROP(mSlime).mBodyHeight(), 0.0f);
	for (int i = 0; i < mSlime->mShapeObject->mShape->mVertexCount; i++) {
		sortPosition(&mSlime->mShapeObject->mShape->mVertexList[i], &mSlime->mShapeObject->mShape->mNormalList[mVertexNormalIndices[i]],
		             &up);
	}
}

/*
 * --INFO--
 * Address:	8016ACFC
 * Size:	000464
 */
void SlimeBody::update()
{
	traceCreaturePosition();
	makeCentrePosition();
	makeInnerPosition();
	makeMaxRadius();
	if (mSlime->aiCullable() && mSlime->mAppearanceScale > 0.0f) {
		setSpherePosition();
		makeSlimeBody();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000118
 */
void SlimeBody::setJointPosition(BossShapeObject* shape, Graphics& gfx)
{
	Matrix4f invLookAtMtx;
	Matrix4f tmpAnimMtx;
	gfx.mCamera->mLookAtMtx.inverse(&invLookAtMtx);

	// do "centre" (main slime)
	invLookAtMtx.multiplyTo(shape->mShape->getAnimMatrix(0), tmpAnimMtx);
	tmpAnimMtx.setColumn(3, mSlime->mSRT.t);
	gfx.mCamera->mLookAtMtx.multiplyTo(tmpAnimMtx, shape->mShape->getAnimMatrix(0));

	// do each slime creature
	for (int i = 0, j = 1; i < 4; i++, j++) {
		invLookAtMtx.multiplyTo(shape->mShape->getAnimMatrix(j), tmpAnimMtx);
		tmpAnimMtx.setColumn(3, mSlime->mSlimeCreatures[i]->mSRT.t);
		gfx.mCamera->mLookAtMtx.multiplyTo(tmpAnimMtx, shape->mShape->getAnimMatrix(j));
	}
}

/*
 * --INFO--
 * Address:	8016B160
 * Size:	000118
 */
void SlimeBody::refresh(BossShapeObject* shape, Graphics& gfx)
{
	setJointPosition(shape, gfx);
}
