#ifndef _NAVIWHISTLE_H
#define _NAVIWHISTLE_H

#include "types.h"
#include "UtEffect.h"
#include "Navi.h"

// NB: had to split this out from UtEffect.h to prevent include looping

/**
 * @brief TODO
 */
struct NaviWhistle : public KEffect {
	NaviWhistle(Navi* navi)
	{
		mNavi = navi;
		mEfxC = 0;
		mEfxB = 0;
		mEfxA = 0;
	}
	virtual bool invoke(zen::particleGenerator* ptclGen, zen::particleMdl* ptcl) // _24
	{
		// NON-MATCHING
		Vector3f diff      = mNavi->mCursorWorldPos - mNavi->mNaviLightPosition;
		f32 ratio          = f32(ptcl->mAge) / f32(ptcl->mLifeTime);
		f32 compRatio      = 1.0f - ratio;
		ptcl->mLocalOffset = mNavi->mNaviLightPosition;
		ptcl->mPosition    = diff * ratio;

		if (mNavi->mCursorWorldPos.y < mNavi->getPosition().y + 15.0f) {
			CollTriInfo* tri = mapMgr->getCurrTri(mNavi->mCursorWorldPos.x, mNavi->mCursorWorldPos.z, true);
			if (!tri) {
				return false;
			}
			Matrix3f mtx1;
			Matrix3f mtx2;
			Quat q1;
			Quat q2;

			diff.normalise();
			zen::makeRotMatrix(diff, mtx1);
			// some really subtle stack issue here
			zen::makeRotMatrix(Vector3f(tri->mTriangle.mNormal * -1.0f), mtx2);

			q1.fromMat3f(mtx1);
			q2.fromMat3f(mtx2);
			q1.slerp(q2, ratio, 0);
			q1.genVectorY(ptcl->_5C);
			q1.genVectorX(ptcl->mVelocity);
			ptcl->mVelocity.multiply(0.01f);
		} else {
			ptcl->_5C.set(diff);
		}

		return false;
	}
	virtual void emit(EffectParm&) // _2C
	{
		if (mEfxA || mEfxB || mEfxC) {
			return;
		}
		mEfxA = effectMgr->create(EffectMgr::EFF_Navi_Whistle1, mNavi->mNaviLightPosition, this, nullptr);
		mEfxB = effectMgr->create(EffectMgr::EFF_Navi_Whistle2, mNavi->mNaviLightPosition, this, this);
		mEfxC = effectMgr->create(EffectMgr::EFF_Navi_Whistle3, mNavi->mNaviLightPosition, this, this);

		if (mEfxA) {
			mEfxA->setEmitPosPtr(&mNavi->mNaviLightPosition);
		}
		if (mEfxB) {
			mEfxB->setOrientedConstZAxis(true);
		}
	}
	virtual void kill() // _30
	{
		if (mEfxA) {
			effectMgr->mPtclMgr.killGenerator(mEfxA, false);
			mEfxA = nullptr;
		}

		if (mEfxB) {
			effectMgr->mPtclMgr.killGenerator(mEfxB, false);
			mEfxB = nullptr;
		}

		if (mEfxC) {
			effectMgr->mPtclMgr.killGenerator(mEfxC, false);
			mEfxC = nullptr;
		}
	}

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	// TODO: members
	Navi* mNavi;                   // _0C
	zen::particleGenerator* mEfxA; // _10
	zen::particleGenerator* mEfxB; // _14
	zen::particleGenerator* mEfxC; // _18
};

/**
 * @brief TODO
 */
struct NaviFue : public KEffect {
	NaviFue(Navi* navi)
	{
		mNavi     = navi;
		mEntryNum = 24;
		mEntries  = new zen::particleGenerator*[mEntryNum];
		if (navi) {
			for (int i = 0; i < mEntryNum; i++) {
				mEntries[i] = nullptr;
			}
		}
	}
	virtual bool invoke(zen::particleGenerator*) { return true; } // _08
	virtual void emit(EffectParm&)                                // _2C
	{
		if (mEntries[0]) {
			return;
		}

		for (int i = 0; i < mEntryNum; i++) {
			mEntries[i] = effectMgr->create(EffectMgr::EFF_Navi_WhistleCursor, mNavi->_938[i], this, nullptr);
			if (mEntries[i]) {
				mEntries[i]->setEmitPosPtr(&mNavi->_938[i]);
			}
		}
	}
	virtual void kill() // _30
	{
		if (!mEntries[0]) {
			return;
		}

		for (int i = 0; i < mEntryNum; i++) {
			if (mEntries[i]) {
				mEntries[i]->setFreqFrm(0.0f);
				effectMgr->mPtclMgr.killGenerator(mEntries[i], false);
			}
			mEntries[i] = nullptr;
		}
	}

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	Navi* mNavi;                       // _0C
	int mEntryNum;                     // _10
	zen::particleGenerator** mEntries; // _14
};

#endif
