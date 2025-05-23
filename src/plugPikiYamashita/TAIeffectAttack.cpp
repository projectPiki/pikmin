#include "TAI/EffectAttack.h"
#include "teki.h"
#include "NaviMgr.h"
#include "PikiMgr.h"
#include "Vector.h"
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
 * Size:	0000F4
 */
DEFINE_PRINT("TAIeffectAttack")

/*
 * --INFO--
 * Address:	801C4960
 * Size:	000038
 */
bool EventTypeCallBack::invoke(zen::particleGenerator* ptclGen)
{
	mParam->_44->ptclHitMap(ptclGen, mParam);
	return true;
}

/*
 * --INFO--
 * Address:	801C4998
 * Size:	0001E0
 */
void CylinderTypeCallBack::init(TAIeffectAttackParam* param, Teki* teki, Vector3f& p3, Vector3f p4, f32 p5, f32 p6, f32 p7, f32 p8,
                                TAIeffectAttackEventCallBack* eventCB)
{
	mParam = param;
	mParam->init();
	mParam->mTeki     = teki;
	mParam->_00       = 0.0f;
	mParam->_04       = p5;
	mParam->_0C       = p7;
	mParam->mVelocity = p4;
	mParam->mPosition = p3;
	mParam->_28       = p4;
	mParam->_28.normalize();
	mParam->_34 = p6;
	mParam->_08 = p8;
	if (eventCB) {
		mParam->_44 = eventCB;
	}

	mParam->_4C.m0 = 1;
}

/*
 * --INFO--
 * Address:	801C4B78
 * Size:	00019C
 */
void CylinderTypeCallBack::hitCheckCommon(zen::particleGenerator* ptclGen, Creature* creature)
{
	f32 t;
	Vector3f vec1;
	Vector3f vec2;

	if (mParam->_44->hitCheckCulling(ptclGen, mParam, creature)) {
		f32 pointDist
		    = zen::getDistPointAndLine(creature->getPosition(), ptclGen->getEmitPos(), mParam->mPosition + mParam->_28 * mParam->_08, t);
		if (pointDist < creature->getCentreSize() + mParam->_08 && t >= 0.0f && t <= 1.0f) {
			mParam->_44->hitCreature(mParam, creature);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003E4
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

/*
 * --INFO--
 * Address:	801C4D14
 * Size:	000384
 */
bool CylinderTypeCallBack::invoke(zen::particleGenerator* ptclGen)
{
	mParam->_44->playEventSound(ptclGen, mParam);
	f32 nextTime = gsys->getFrameTime() + mParam->_00;
	mParam->_00  = nextTime;

	if (nextTime < mParam->_04 && mParam->mTeki->mHealth > 0.0f) {
		Vector3f vec1;

		if (mParam->_4C.m0) {
			mParam->mPosition.add(Vector3f(mParam->mVelocity * gsys->getFrameTime()));
			vec1 = mParam->mPosition - ptclGen->getEmitPos();
			if (vec1.length() > mParam->_0C) {
				mParam->_4C.m0 = 0;
				mParam->mVelocity.normalize();
			} else if (mParam->_44->hitMap(mParam)) {
				mParam->_4C.m0 = 0;
			}
		}

		hitCheck(ptclGen);
	}

	mParam->_44->ptclHitMap(ptclGen, mParam);
	return true;
}

/*
 * --INFO--
 * Address:	801C5098
 * Size:	0001E8
 */
void ConeTypeCallBack::init(TAIeffectAttackParam* param, Teki* teki, Vector3f& p3, Vector3f p4, f32 p5, f32 p6, f32 p7, f32 p8,
                            TAIeffectAttackEventCallBack* eventCB)
{
	mParam = param;
	mParam->init();
	mParam->mTeki     = teki;
	mParam->_00       = 0.0f;
	mParam->_04       = p5;
	mParam->_0C       = p7;
	mParam->mPosition = p3;
	mParam->_28       = p4;
	mParam->_28.normalize();
	mParam->mVelocity = p4;
	mParam->_34       = p8;
	if (mParam->_3C && !mParam->_3C->checkEmit()) {
		ERROR("EMIT IS ALIVE! ");
	}
	if (mParam->_40 && !mParam->_40->checkEmit()) {
		ERROR("EMIT IS ALIVE! ");
	}
	mParam->_3C = mParam->_40 = nullptr;
	if (eventCB) {
		mParam->_44 = eventCB;
	}
	_08 = p6;
}

/*
 * --INFO--
 * Address:	801C5280
 * Size:	000320
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
			val = mParam->_0C;
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
			f32 angle = NMathF::cos(_08);

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

				mParam->_44->hitCreature(ptclGen, mParam, creature, vec1);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000214
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

/*
 * --INFO--
 * Address:	801C55A0
 * Size:	000434
 */
bool ConeTypeCallBack::invoke(zen::particleGenerator* ptclGen)
{
	f32 nextTime = mParam->_00 + gsys->getFrameTime();
	mParam->_00  = nextTime;

	if (nextTime < mParam->_04 && mParam->mTeki->mHealth > 0.0f) {
		Vector3f vec1;

		mParam->mPosition.add(Vector3f(mParam->mVelocity * gsys->getFrameTime()));
		vec1 = mParam->mPosition - ptclGen->getEmitPos();
		if (vec1.length() > mParam->_0C) {
			mParam->mVelocity.set(0.0f, 0.0f, 0.0f);
		} else if (ptclGen->checkEmit()) {
			if (mParam->_44->hitMap(mParam)) {
				mParam->mVelocity.set(0.0f, 0.0f, 0.0f);
			}
		} else {
			ERROR("HEN! %f %f \n", mParam->_00, mParam->_04);
		}

		hitCheck(ptclGen);
	} else {
		ptclGen->finish();
		if (mParam->_3C) {
			mParam->_3C->finish();
		}
		if (mParam->_40) {
			mParam->_40->finish();
		}
	}

	mParam->_44->ptclHitMap(ptclGen, mParam);
	mParam->_44->playEventSound(ptclGen, mParam);
	return true;
}
