#include "FormationMgr.h"
#include "DebugLog.h"
#include "GlobalShape.h"
#include "Graphics.h"
#include "system.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(8)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("formation")

/**
 * @TODO: Documentation
 */
Creature* FormationMgr::getCreature(int idx)
{
	return mFormMembers[idx];
}

/**
 * @TODO: Documentation
 */
int FormationMgr::getFirst()
{
	return 0;
}

/**
 * @TODO: Documentation
 */
int FormationMgr::getNext(int idx)
{
	return idx + 1;
}

/**
 * @TODO: Documentation
 */
bool FormationMgr::isDone(int idx)
{
	if (idx >= mCount) {
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
Vector3f FormPoint::getPos()
{
	f32 angle = mFormMgr->mRotationAngle;
	Vector3f pos(sinf(angle) * mLocalPosition.x + cosf(angle) * mLocalPosition.z, 0.0f,
	             cosf(angle) * mLocalPosition.x - sinf(angle) * mLocalPosition.z);
	pos = pos + mFormMgr->mCenterPosition;
	return pos + mOffset;
}

/**
 * @TODO: Documentation
 */
Vector3f FormationMgr::getLastCentre()
{
	f32 angle  = mRotationAngle;
	f32 radius = -mArranger->getLength(this);
	Vector3f centre(radius * sinf(angle), 0.0f, radius * cosf(angle));
	centre = centre + mCenterPosition;
	return centre;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000148
 */
FormationMgr::FormationMgr()
{
	mMax            = 300;
	mFormPointCount = 0;
	mRotationAngle  = 0.0f;
	mFormPoints     = new FormPoint[mMax];
	mFormMembers    = new Creature*[mMax];
	for (int i = 0; i < mMax; i++) {
		mFormPoints[i].setMgr(this);
		mFormMembers[i] = nullptr;
	}

	mCount = 0;
	clear();
	mCenterPosition.set(0.0f, 0.0f, 0.0f);
	mOffset.set(0.0f, 0.0f, 0.0f);
	mAngOffset = 0;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
FormPoint::FormPoint()
{
	mOwner.clear();
	mOffset.set(0.0f, 0.0f, 0.0f);
}

/**
 * @TODO: Documentation
 */
FormPoint* FormationMgr::getFormPoint(Creature* target)
{
	int replaceIdx      = -1;
	Creature* toReplace = nullptr;
	int i;
	for (i = 0; i < mFormPointCount; i++) {
		toReplace = mFormPoints[i].getOwner();
		if (!mFormPoints[i].isFree()) {
			if (toReplace->getFormationPri() > target->getFormationPri()) {
				replaceIdx = i;
				break;
			}
		}
	}

	int freeIdx = -1;
	for (i = 0; i < mMax; i++) {
		if (mFormPoints[i].isFree()) {
			freeIdx = i;
			break;
		}
	}

	if (replaceIdx != -1) {
		// replace member
		mFormPoints[replaceIdx].setOwner(target);
		for (int j = 0; j < mCount; j++) {
			if (mFormMembers[j] == toReplace) {
				mFormMembers[j] = target;
			}
		}
		// insert replaced member one over
		slide(toReplace, replaceIdx + 1);
		return &mFormPoints[replaceIdx];
	}

	if (freeIdx == -1) {
		ERROR("no empty index for formation : numClients=%d\n", mCount);
	}

	mFormPoints[freeIdx].setOwner(target);
	mFormMembers[mCount++] = target;
	return &mFormPoints[freeIdx];
}

/**
 * @TODO: Documentation
 */
void FormationMgr::slide(Creature* target, int idx)
{
	int replaceIdx      = -1;
	Creature* toReplace = nullptr;

	for (int i = 0; i < mCount; i++) {
		toReplace = mFormPoints[i].getOwner();
		if (!mFormPoints[i].isFree()) {
			if (toReplace->getFormationPri() > target->getFormationPri()) {
				replaceIdx = i;
				break;
			}
		}
	}

	if (replaceIdx != -1) {
		mFormPoints[replaceIdx].setOwner(target);
		for (int i = 0; i < mCount; i++) {
			if (mFormMembers[i] == toReplace) {
				mFormMembers[i] = target;
			}
		}

		target->mFormPoint    = &mFormPoints[replaceIdx];
		toReplace->mFormPoint = nullptr;
		slide(toReplace, idx + 1);
		return;
	}

	int freeIdx = -1;
	for (int i = 0; i < mFormPointCount; i++) {
		if (mFormPoints[i].isFree()) {
			freeIdx = i;
			break;
		}
	}

	mFormPoints[freeIdx].setOwner(target);
	mFormMembers[mCount++] = target;
	target->mFormPoint     = &mFormPoints[freeIdx];
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000CC
 */
void FormationMgr::add(immut Vector3f& localPos, immut Vector3f& color)
{
	Colour col;
	col.set(int(255.0f * color.x), int(255.0f * color.y), int(255.0f * color.z), 255);
	mFormPoints[mFormPointCount].reset();
	mFormPoints[mFormPointCount].mLocalPosition = localPos;
	mFormPoints[mFormPointCount].mDebugColor    = col;
	mFormPointCount++;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
int FormationMgr::getIndex(Creature* target)
{
	for (int i = 0; i < mCount; i++) {
		if (mFormMembers[i] == target) {
			return i;
		}
	}
	return -1;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
int FormationMgr::getFptIndex(FormPoint* point)
{
	for (int i = 0; i < mFormPointCount; i++) {
		if (point == &mFormPoints[i]) {
			return i;
		}
	}
	return -1;
}

/**
 * @TODO: Documentation
 */
void FormationMgr::exit(Creature* target)
{
	int i;
	int idx = getIndex(target);
	if (idx == -1) {
		return;
	}

	if (mCount == 1) {
		mFormMembers[0]->mFormPoint->reset();
		mCount = 0;
		return;
	}

	int ptIdx = getFptIndex(target->mFormPoint);
	for (i = idx; i < mCount - 1; i++) {
		mFormMembers[i]             = mFormMembers[i + 1];
		mFormMembers[i]->mFormPoint = &mFormPoints[ptIdx];
		mFormMembers[i]->mFormPoint->setOwner(mFormMembers[i]);
		ptIdx++;
	}

	mFormPoints[ptIdx].reset();
	mCount--;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00008C
 */
void FormationMgr::clear()
{
	for (int i = 0; i < mMax; i++) {
		mFormPoints[i].reset();
	}

	for (int i = 0; i < mCount; i++) {
		if (mFormMembers[i]) {
			mFormMembers[i]->mFormPoint = nullptr;
			mFormMembers[i]             = nullptr;
		}
	}

	mCount = 0;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void FormationMgr::rearrange()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000060
 */
void FormationMgr::setOffset(immut Vector3f& offset)
{
	mOffset = offset;
	for (int i = 0; i < mMax; i++) {
		mFormPoints[i].mOffset = mOffset;
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void FormationMgr::setAngOffset(f32 offset)
{
	mAngOffset = offset;
}

/**
 * @TODO: Documentation
 */
void CircleArranger::arrange(FormationMgr* mgr)
{
	Vector3f vec(1.0f, 0.0f, 0.0f);
	Vector3f vec2(1.0f, 1.0f, 0.0f);
	f32 val1 = 0.0f;
	f32 val2 = 40.0f;
	f32 val3 = HALF_PI;
	int i    = 0;
	while (i < 300) {
		f32 angle = val3;
		int j     = 0;
		while (j < 4) {
			Vector3f vec3;
			vec3.set(val2 * cosf(angle), 0.0f, val2 * sinf(angle));
			Vector3f vec4 = (1.0f - val1) * vec + val1 * vec2;
			mgr->add(vec3, vec4);
			angle += HALF_PI;
			j++;
			i++;
		}

		val3 *= 0.5f;
		if (val3 * val2 < 30.0f) {
			val2 = 30.0f + val2;
			val3 = HALF_PI;
			val1 += 0.1f;
			if (val1 >= 1.0f) {
				val1 = 1.0f;
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void PyramidArranger::arrange(FormationMgr* mgr)
{
	Vector3f vec(0.0f, 1.0f, 0.0f);
	Vector3f vec2(0.5f, 1.0f, 0.0f);
	f32 val1 = 0.0f;
	int j    = 1;
	f32 val2 = 26.0f;
	Vector3f vec3(-val2, 0.0f, 0.0f);
	int k   = 1;
	f32 dir = -1.0f;
	for (int i = 0; i < 300; i++) {
		Vector3f vec4 = (1.0f - val1) * vec + val1 * vec2;
		mgr->add(vec3, vec4);
		if (k >= j) {
			j++;
			vec3.x -= val2;
			vec3.z = dir * (j / 2) * val2;
			dir    = -dir;
			k      = 1;
			val1 += 0.1f;
			if (val1 >= 1.0f) {
				val1 = 1.0f;
			}
		} else {
			vec3.z += dir * val2;
			k++;
		}
	}
}

/**
 * @TODO: Documentation
 */
f32 PyramidArranger::getLength(FormationMgr* mgr)
{
	int count = mgr->mCount; // load bearing temp. try it.
	return (-1.0f + std::sqrtf(count * 8.0f + 1.0f)) / 2.0f * 26.0f;
}

/**
 * @TODO: Documentation
 */
void LineArranger::arrange(FormationMgr* mgr)
{
	Vector3f vec(1.0f, 1.0f, 1.0f);
	Vector3f vec2(0.0f, 1.0f, 0.0f);
	f32 val1 = 0.0f;
	f32 val2 = 25.0f;
	f32 val3 = 2 * val2;
	int j    = 0;
	Vector3f vec3(0.0f, 0.0f, val2);
	for (int i = 0; i < 300; i++) {
		vec3.z        = val3;
		Vector3f vec4 = (1.0f - val1) * vec + val1 * vec2;
		mgr->add(vec3, vec4);
		if (j == 0) {
			val3 = -val3;
			j    = 1;
		} else if (j == 1) {
			val3 = -val3 + val2;
			j    = 0;
			val1 += 0.1f;
			if (val1 >= 1.0f) {
				val1 = 1.0f;
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void WingArranger::arrange(FormationMgr* mgr)
{
	int a    = 0;
	int b    = 0;
	int c    = 1;
	int d    = 1;
	f32 val1 = 30.0f;
	f32 val2 = 80.0f;
	f32 val3 = -80.0f;
	for (int i = 0; i < 300; i++) {
		if (i % 2 == 0) {
			Vector3f vec(val2 / c * a, 0.0f, val2 - val2 * a / c);
			mgr->add(vec, Vector3f(1.0f, 0.0f, 1.0f));
			a++;
			if (a == c) {
				a = 0;
				c++;
				val2 += val1;
			}
		} else {
			Vector3f vec(-val3 / d * b, 0.0f, val3 - val3 * b / d);
			mgr->add(vec, Vector3f(1.0f, 1.0f, 0.0f));
			b++;
			if (b == d) {
				b = 0;
				d++;
				val3 -= val1;
			}
		}
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00005C
 */
Rope::Rope()
{
	mPrevLink = mNextLink = nullptr;
	mVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000A1C
 */
void Rope::move(immut Vector3f& targetPos, immut Vector3f& initialVel, immut Vector3f& p3)
{
	Vector3f projectedPos = targetPos + initialVel * gsys->getFrameTime();
	Vector3f vec2         = projectedPos - mPosition;
	f32 dist              = vec2.length();
	vec2                  = vec2 * (1.0f / dist) * (dist - mRadius);
	if (mNextLink) {
		mVelocity = mVelocity + (vec2 - mVelocity) * gsys->getFrameTime() / 0.1f;
		mNextLink->move(mPosition, mVelocity, p3);
	} else {
		mVelocity = mVelocity + (vec2 - mVelocity) * gsys->getFrameTime() / 0.1f + 10.0f * p3;
	}

	mPosition     = mPosition + mVelocity * gsys->getFrameTime();
	Vector3f vec3 = mPosition - projectedPos;
	vec3.normalise();
	mPosition = projectedPos + mRadius * vec3;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000170
 */
void Rope::refresh(Graphics& gfx)
{
	Matrix4f mtx1;
	Vector3f vec;
	Matrix4f mtx2;
	f32 scale = 0.15f;
	mtx1.makeSRT(Vector3f(scale, 2.0f * scale, scale), Vector3f(0.0f, 0.0f, 0.0f), mPosition);
	gfx.calcViewMatrix(mtx1, mtx2);
	gfx.useMatrix(mtx2, 0);
	GlobalShape::arrowShape->drawshape(gfx, *gfx.mCamera, nullptr);
	if (mNextLink) {
		mNextLink->refresh(gfx);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000020
 */
Spine::Spine()
{
	mTargetCreature.clear();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000340
 */
void Spine::init(Creature* target)
{
	Vector3f startPosition = target->mSRT.t;
	mTargetCreature.set(target);

	mRope          = new Rope();
	f32 rad        = 7.0f;
	mRope->mRadius = 7.0f;
	mLinkCount     = 10;

	f32 initialAngle = 2.0f * (PI * gsys->getRand(1.0f));
	startPosition    = startPosition + Vector3f(rad * sinf(initialAngle), 0.0f, rad * cosf(initialAngle));
	mRope->mPosition = startPosition;
	Rope* rope       = mRope;

	for (int i = 0; i < mLinkCount - 1; i++) {
		rope->mNextLink = new Rope();
		Rope* prev      = rope;
		rope            = rope->mNextLink;
		rope->mPrevLink = prev;

		f32 linkAngle   = 2.0f * (PI * gsys->getRand(1.0f));
		startPosition   = startPosition + Vector3f(rad * sinf(linkAngle), 0.0f, rad * cosf(linkAngle));
		rope->mPosition = startPosition;
		rope->mRadius   = rad;
	}

	_UNUSED10.set(0.0f, 0.0f, 0.0f);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000A8C
 */
void Spine::preMove()
{
	// i'm not strong enough to do this blind, it's a lot of vector math.
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void Spine::postMove()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000020
 */
void Spine::move()
{
	mTargetCreature.getPtr();
	preMove();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000DC
 */
void Spine::refresh(Graphics& gfx)
{
	if (mRope) {
		mRope->refresh(gfx);
	}
}
