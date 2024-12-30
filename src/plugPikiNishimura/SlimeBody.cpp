#include "Slime.h"
#include "Shape.h"
#include "Graphics.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016A630
 * Size:	00013C
 */
SlimeBody::SlimeBody(Slime* slime)
{
	mSlime         = slime;
	mNormalIndexes = new u16[mSlime->mShapeObject->mShape->mVertexCount];
	_18            = new int[mSlime->mShapeObject->mShape->mJointCount - 1];
	_1C            = new Vector3f[mSlime->mShapeObject->mShape->mVertexCount];

	_08 = new Vector3f[bossMgr->mSlimeCreatureCount];
	_0C = new Vector3f[bossMgr->mSlimeCreatureCount];
	_10 = new Vector3f[bossMgr->mSlimeCreatureCount];
}

/*
 * --INFO--
 * Address:	8016A76C
 * Size:	0002A4
 */
void SlimeBody::init(Slime* slime)
{
	mSlime = slime;
	mSlime->mShapeObject->mShape->makeNormalIndexes(mNormalIndexes);

	int i;
	for (i = 1; i < mSlime->mShapeObject->mShape->mJointCount; i++) {
		f32 minDist = 12800.0f;
		Vector3f jointAnimPos;
		mSlime->mShapeObject->mShape->mJointList[i].mAnimMatrix.getColumn(3, jointAnimPos);

		for (int j = 0; j < mSlime->mShapeObject->mShape->mVertexCount; j++) {
			f32 dist = jointAnimPos.distance(mSlime->mShapeObject->mShape->mVertexList[j]);
			if (dist < minDist) {
				minDist    = dist;
				_18[i - 1] = j;
			}
		}
	}

	for (i = 0; i < mSlime->mShapeObject->mShape->mVertexCount; i++) {
		_1C[i].x = mSlime->mShapeObject->mShape->mVertexList[i].x;
		_1C[i].y = mSlime->mShapeObject->mShape->mVertexList[i].y;
		_1C[i].z = mSlime->mShapeObject->mShape->mVertexList[i].z;

		_1C[i].normalise();
	}

	for (i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		_08[i].set(0.0f, 0.0f, 0.0f);
		_0C[i] = mSlime->mPosition;
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
		_08[i].multiply(static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps._394());
		Vector3f diff = mSlime->mSlimeCreatures[i]->mPosition - _0C[i];
		diff.multiply(static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps._3A4());
		_08[i].add(diff);
		_0C[i].add(_08[i]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void SlimeBody::makeCentrePosition()
{
	mSlime->mPosition.set(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		mSlime->mPosition.add(mSlime->mSlimeCreatures[i]->mPosition);
	}

	mSlime->mPosition.multiply(0.25f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void SlimeBody::makeInnerPosition()
{
	for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
		_10[i].sub(_0C[i], mSlime->mPosition);
		_10[i].y += static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps._334();
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
		f32 distFromCentre = _10[i].length();
		if (distFromCentre > mMaxRadius) {
			mMaxRadius = distFromCentre;
		}
	}

	mMaxRadius += static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps._364();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void SlimeBody::setSpherePosition()
{
	for (int i = 0; i < mSlime->mShapeObject->mShape->mVertexCount; i++) {
		mSlime->mShapeObject->mShape->mVertexList[i].x = mMaxRadius * _1C[i].x;
		mSlime->mShapeObject->mShape->mVertexList[i].y = mMaxRadius * _1C[i].y;
		mSlime->mShapeObject->mShape->mVertexList[i].z = mMaxRadius * _1C[i].z;
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
		creatureNormals[i].x = vertex->x - _10[i].x;
		creatureNormals[i].y = (vertex->y - _10[i].y) * mSlime->_3D8;
		creatureNormals[i].z = vertex->z - _10[i].z;
		creatureScores[i]
		    = mSlime->_3D4 / std::sqrtf(SQUARE(creatureNormals[i].x) + SQUARE(creatureNormals[i].y) + SQUARE(creatureNormals[i].z));
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
	for (int i = 0; i < static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps.mMaxSortCount(); i++) {
		outVertex->x = (minNormal.x + targetNormal.x) / 2.0f;
		outVertex->y = (minNormal.y + targetNormal.y) / 2.0f;
		outVertex->z = (minNormal.z + targetNormal.z) / 2.0f;

		totalScore = calcVertexScore(outVertex, creatureNormals, creatureScores);
		if (totalScore > static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps._384()) {
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
	Vector3f up(0.0f, static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps._334(), 0.0f);
	for (int i = 0; i < mSlime->mShapeObject->mShape->mVertexCount; i++) {
		sortPosition(&mSlime->mShapeObject->mShape->mVertexList[i], &mSlime->mShapeObject->mShape->mNormals[mNormalIndexes[i]], &up);
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
	if (mSlime->aiCullable() && mSlime->_3D4 > 0.0f) {
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
	tmpAnimMtx.setColumn(3, mSlime->mPosition);
	gfx.mCamera->mLookAtMtx.multiplyTo(tmpAnimMtx, shape->mShape->getAnimMatrix(0));

	// do each slime creature
	for (int i = 0, j = 1; i < 4; i++, j++) {
		invLookAtMtx.multiplyTo(shape->mShape->getAnimMatrix(j), tmpAnimMtx);
		tmpAnimMtx.setColumn(3, mSlime->mSlimeCreatures[i]->mPosition);
		gfx.mCamera->mLookAtMtx.multiplyTo(tmpAnimMtx, shape->mShape->getAnimMatrix(j));
	}
}

/*
 * --INFO--
 * Address:	8016B160
 * Size:	000118
 */
void SlimeBody::refresh(BossShapeObject* shape, Graphics& gfx) { setJointPosition(shape, gfx); }
