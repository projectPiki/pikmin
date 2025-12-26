#include "DebugLog.h"
#include "NaviMgr.h"
#include "PikiMgr.h"
#include "TAI/EffectAttack.h"
#include "Vector.h"
#include "teki.h"
#include "zen/Math.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(19)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("TAIeffectAttack")

/**
 * @todo: Documentation
 */
bool EventTypeCallBack::invoke(zen::particleGenerator* ptclGen)
{
	mParam->mCallBackRef->ptclHitMap(ptclGen, mParam);
	return true;
}

/**
 * @todo: Documentation
 */
void CylinderTypeCallBack::init(TAIeffectAttackParam* attackParam, Teki* teki, immut Vector3f& startPos, Vector3f velocity, f32 duration,
                                f32 damage, f32 maxRange, f32 radius, TAIeffectAttackEventCallBack* eventCB)
{
	mParam = attackParam;
	mParam->init();
	mParam->mTeki        = teki;
	mParam->mCurrentTime = 0.0f;
	mParam->mDuration    = duration;
	mParam->mMaxRange    = maxRange;
	mParam->mVelocity    = velocity;
	mParam->mPosition    = startPos;
	mParam->mDirection   = velocity;
	mParam->mDirection.normalize();
	mParam->mDamage = damage;
	mParam->mRadius = radius;
	if (eventCB) {
		mParam->mCallBackRef = eventCB;
	}

	mParam->mState.mIsMoving = 1;
}

/**
 * @todo: Documentation
 */
void CylinderTypeCallBack::hitCheckCommon(zen::particleGenerator* ptclGen, Creature* creature)
{
	f32 t;
	Vector3f vec1;
	Vector3f vec2;

	if (mParam->mCallBackRef->hitCheckCulling(ptclGen, mParam, creature)) {
		f32 pointDist = zen::getDistPointAndLine(creature->getPosition(), ptclGen->getEmitPos(),
		                                         mParam->mPosition + mParam->mDirection * mParam->mRadius, t);
		if (pointDist < creature->getCentreSize() + mParam->mRadius && t >= 0.0f && t <= 1.0f) {
			mParam->mCallBackRef->hitCreature(mParam, creature);
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0003E4
 */
void CylinderTypeCallBack::hitCheck(zen::particleGenerator* ptclGen)
{
	Navi* navi = naviMgr->getNavi();
	hitCheckCommon(ptclGen, navi);

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		hitCheckCommon(ptclGen, *iter);
	}
}

/**
 * @todo: Documentation
 */
bool CylinderTypeCallBack::invoke(zen::particleGenerator* ptclGen)
{
	mParam->mCallBackRef->playEventSound(ptclGen, mParam);
	f32 nextTime         = gsys->getFrameTime() + mParam->mCurrentTime;
	mParam->mCurrentTime = nextTime;

	if (nextTime < mParam->mDuration && mParam->mTeki->mHealth > 0.0f) {
		Vector3f vec1;

		if (mParam->mState.mIsMoving) {
			mParam->mPosition.add(Vector3f(mParam->mVelocity * gsys->getFrameTime()));
			vec1 = mParam->mPosition - ptclGen->getEmitPos();
			if (vec1.length() > mParam->mMaxRange) {
				mParam->mState.mIsMoving = 0;
				mParam->mVelocity.normalize();
			} else if (mParam->mCallBackRef->hitMap(mParam)) {
				mParam->mState.mIsMoving = 0;
			}
		}

		hitCheck(ptclGen);
	}

	mParam->mCallBackRef->ptclHitMap(ptclGen, mParam);
	return true;
}

/**
 * @todo: Documentation
 */
void ConeTypeCallBack::init(TAIeffectAttackParam* param, Teki* teki, immut Vector3f& p3, Vector3f p4, f32 p5, f32 p6, f32 p7, f32 p8,
                            TAIeffectAttackEventCallBack* eventCB)
{
	mParam = param;
	mParam->init();
	mParam->mTeki        = teki;
	mParam->mCurrentTime = 0.0f;
	mParam->mDuration    = p5;
	mParam->mMaxRange    = p7;
	mParam->mPosition    = p3;
	mParam->mDirection   = p4;
	mParam->mDirection.normalize();
	mParam->mVelocity = p4;
	mParam->mDamage   = p8;
	if (mParam->mSubEmitter1 && !mParam->mSubEmitter1->checkEmit()) {
		ERROR("EMIT IS ALIVE! ");
	}
	if (mParam->mSubEmitter2 && !mParam->mSubEmitter2->checkEmit()) {
		ERROR("EMIT IS ALIVE! ");
	}
	mParam->mSubEmitter1 = mParam->mSubEmitter2 = nullptr;
	if (eventCB) {
		mParam->mCallBackRef = eventCB;
	}
	mConeHalfAngle = p6;
}

/**
 * @todo: Documentation
 */
void ConeTypeCallBack::hitCheckCommon(zen::particleGenerator* ptclGen, Creature* creature)
{
	Vector3f emitPos(ptclGen->getEmitPos());
	Vector3f cPos(creature->getPosition());
	Vector3f dir1 = mParam->mPosition - ptclGen->getEmitPos();
	Vector3f dir2(cPos.x - emitPos.x, cPos.y - emitPos.y, cPos.z - emitPos.z);

	if (dir1.DP(dir2) > 0.0f) {
		f32 dist1 = dir1.length();
		f32 dist2 = dir2.length();

		f32 val;
		if (mParam->mVelocity.x == 0.0f && mParam->mVelocity.y == 0.0f && mParam->mVelocity.z == 0.0f) {
			val = mParam->mMaxRange;
		} else {
			val = dist1;
		}

		if (dist2 < val) {
			if (dist1 != 0.0f) {
				dir1.div(dist1);
			}
			if (dist2 != 0.0f) {
				dir2.div(dist2);
			}

			// NMathF here fixes instruction order. Keep in mind for other functions.
			f32 dot12 = dir1.DP(dir2);
			f32 angle = NMathF::cos(mConeHalfAngle);

			if (dot12 > angle) {
				Vector3f vec1;
				f32 scale = (dot12 - angle) / (1.0f - angle);
				scale *= 1.005f;
				if (scale >= 1.0f) {
					scale = 3.0f;
				}

				vec1.set(dir2.x - dir1.x, 0.5f, dir2.z - dir1.z);
				vec1.normalize();
				vec1.multiply(scale);

				u32 flag = ptclGen->getControlFlag();

				mParam->mCallBackRef->hitCreature(ptclGen, mParam, creature, vec1);
			}
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000214
 */
void ConeTypeCallBack::hitCheck(zen::particleGenerator* ptclGen)
{
	Iterator iterN(naviMgr);
	CI_LOOP(iterN)
	{
		hitCheckCommon(ptclGen, *iterN);
	}

	Iterator iterP(pikiMgr);
	CI_LOOP(iterP)
	{
		hitCheckCommon(ptclGen, *iterP);
	}
}

/**
 * @todo: Documentation
 */
bool ConeTypeCallBack::invoke(zen::particleGenerator* ptclGen)
{
	f32 nextTime         = mParam->mCurrentTime + gsys->getFrameTime();
	mParam->mCurrentTime = nextTime;

	if (nextTime < mParam->mDuration && mParam->mTeki->mHealth > 0.0f) {
		Vector3f vec1;

		mParam->mPosition.add(Vector3f(mParam->mVelocity * gsys->getFrameTime()));
		vec1 = mParam->mPosition - ptclGen->getEmitPos();
		if (vec1.length() > mParam->mMaxRange) {
			mParam->mVelocity.set(0.0f, 0.0f, 0.0f);
		} else if (ptclGen->checkEmit()) {
			if (mParam->mCallBackRef->hitMap(mParam)) {
				mParam->mVelocity.set(0.0f, 0.0f, 0.0f);
			}
		} else {
			ERROR("HEN! %f %f \n", mParam->mCurrentTime, mParam->mDuration);
		}

		hitCheck(ptclGen);
	} else {
		ptclGen->finish();
		if (mParam->mSubEmitter1) {
			mParam->mSubEmitter1->finish();
		}
		if (mParam->mSubEmitter2) {
			mParam->mSubEmitter2->finish();
		}
	}

	mParam->mCallBackRef->ptclHitMap(ptclGen, mParam);
	mParam->mCallBackRef->playEventSound(ptclGen, mParam);
	return true;
}
