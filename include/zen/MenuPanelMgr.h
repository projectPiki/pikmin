#ifndef _ZEN_MENUPANELMGR_H
#define _ZEN_MENUPANELMGR_H

#include "P2D/Picture.h"
#include "nlib/Math.h"
#include "types.h"
#include "zen/DrawCommon.h"
#include "zen/Math.h"

struct P2DScreen;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct MenuPanelMgr {
public:
	enum statusFlag {
		STATE_Wait      = 0,
		STATE_Start     = 1,
		STATE_Operation = 2,
		STATE_End       = 3,
	};

	MenuPanelMgr()
	{
		changeState(STATE_Wait, 1.0f);
		updateRatio();
	}

	void setCallBack(P2DScreen*, P2DPane*);
	bool update();
	bool checkFinish();

	void wait() { changeState(STATE_Wait, 1.0f); }
	void start(f32 duration) { changeState(STATE_Start, duration); }
	void operation() { changeState(STATE_Operation, 1.0f); }
	void end(f32 duration) { changeState(STATE_End, duration); }

	// DLL inlines, to do:
	statusFlag getStatusFlag() { return mState; }
	f32 getRatio() { return mRatio; }

protected:
	void updateRatio() { mRatio = mTimer / mDuration; }

	void changeState(statusFlag state, f32 duration)
	{
		mState    = state;
		mTimer    = 0.0f;
		mDuration = duration;
	}

	statusFlag mState; // _00
	f32 mTimer;        // _04
	f32 mDuration;     // _08
	f32 mRatio;        // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0x64.
 */
struct MenuPanel : public P2DPaneCallBack {
public:
	MenuPanel(P2DPane* pane, P2DPane* centPane, MenuPanelMgr* mgr)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	{
		mRotationAngle    = 0.0f;
		mRotationSpeed    = (Rand(1.0f) + 1.0f) * ((Rand(10.0f) > 5.0f) ? 1.0f : -1.0f);
		mScaleSpeedFactor = Rand(0.1f) + 0.05f;
		mMoveSpeed        = Rand(10.0f) + 5.0f;
		mTimer            = 0.0f;
		mPanelMgr         = mgr;
		pane->setOffset(pane->getWidth() >> 1, pane->getHeight() >> 1);
		mDefaultPos.x = pane->getPosH();
		mDefaultPos.y = pane->getPosV();
		mDefaultPos.z = 0.0f;
		mCurrentPos.set(mDefaultPos.x, mDefaultPos.y, mDefaultPos.z);
		mOffset.set(0.0f, 0.0f, 0.0f);

		Vector3f coes[3];

		f32 x = centPane->getPosH() + (centPane->getWidth() >> 1);
		f32 y = centPane->getPosV() + (centPane->getHeight() >> 1);

		f32 signX = ((pane->getWidth() >> 1) + mDefaultPos.x < x) ? -1.0f : 1.0f;
		f32 signY = ((pane->getHeight() >> 1) + mDefaultPos.y < y) ? -1.0f : 1.0f;
		coes[0].set(mDefaultPos.x + signX * 640.0f - f32(pane->getWidth() >> 1), y - f32(pane->getHeight() >> 1), mDefaultPos.z);

		coes[1].set(mDefaultPos.x + signX * 150.0f - f32(pane->getWidth() >> 1), y - f32(pane->getHeight() >> 1), mDefaultPos.z);
		coes[2].set(mDefaultPos.x, mDefaultPos.y, mDefaultPos.z);

		setLagrangeFunction(coes);
		update(pane);
	}

	virtual bool invoke(P2DPane* pane) // _08 (weak)
	{
		update(pane);
		return true;
	}

	void update(P2DPane* pane)
	{
		P2DPicture* pic = (P2DPicture*)pane;
		switch (mPanelMgr->getStatusFlag()) {
		case MenuPanelMgr::STATE_Wait:
		case MenuPanelMgr::STATE_Start:
			f32 t = mPanelMgr->getRatio();
			t     = (1.0f - NMathF::cos(PI * t)) * 0.5f;
			move(pane, mCurrentPos, t);

			if (t < 0.7f) {
				pic->setScale(1.0f, 0.02f, 1.0f);
			} else {
				pic->setScale(1.0f, (t - 0.7f) * 0.98f / 0.3f + 0.02f, 1.0f);
			}

			mOffset.set(0.0f, 0.0f, mOffset.z);
			mTimer = 0.0f;
			break;

		case MenuPanelMgr::STATE_Operation:
			mTimer += gsys->getFrameTime();
			if (mTimer > 1.0f) {
				mTimer = 1.0f;
			}

			mRotationAngle += gsys->getFrameTime() * mRotationSpeed;
			if (mRotationAngle > TAU) {
				mRotationAngle -= TAU;
			}

			t            = NMathF::sin(mRotationAngle);
			f32 cosTheta = NMathF::cos(mRotationAngle);
			pic->setAlpha(RoundOff(87.5f * cosTheta + 167.5f));
			pic->setScale(NMathF::sin(mRotationAngle) * (mTimer * mScaleSpeedFactor) + 1.0f);
			mOffset.set(mTimer * mMoveSpeed * t, mTimer * mMoveSpeed * cosTheta, mOffset.z);
			break;

		case MenuPanelMgr::STATE_End:
			t = 1.0f - mPanelMgr->getRatio();
			move(pane, mCurrentPos, t);
			if (t < 0.7f) {
				pic->setScale(1.0f, 0.02f, 1.0f);
			} else {
				pic->setScale(1.0f, (t - 0.7f) * 0.98f / 0.3f + 0.02f, 1.0f);
			}
			break;
		}

		pic->move(RoundOff(mCurrentPos.x + mOffset.x), RoundOff(mCurrentPos.y + mOffset.y));
	}

protected:
	void setLagrangeFunction(immut Vector3f* coes)
	{
		setLagrangeCoe(mLagrangeCoeffsX, coes[0].x, coes[1].x, coes[2].x);
		setLagrangeCoe(mLagrangeCoeffsY, coes[0].y, coes[1].y, coes[2].y);
		setLagrangeCoe(mLagrangeCoeffsZ, coes[0].z, coes[1].z, coes[2].z);
	}
	void setLagrangeCoe(f32* coes, f32 a1, f32 a2, f32 a3)
	{
		coes[0] = a1;
		coes[1] = (-0.75f * a1 + a2 - 0.25f * a3) / 0.25f;
		coes[2] = (0.5f * a1 - a2 + 0.5f * a3) / 0.25f;
	}
	void move(P2DPane*, Vector3f& outPos, f32 t)
	{
		outPos.set(mLagrangeCoeffsX[0] + mLagrangeCoeffsX[1] * t + mLagrangeCoeffsX[2] * t * t,
		           mLagrangeCoeffsY[0] + mLagrangeCoeffsY[1] * t + mLagrangeCoeffsY[2] * t * t,
		           mLagrangeCoeffsZ[0] + mLagrangeCoeffsZ[1] * t + mLagrangeCoeffsZ[2] * t * t);
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	f32 mRotationAngle;      // _04
	f32 mRotationSpeed;      // _08
	f32 mScaleSpeedFactor;   // _0C
	f32 mMoveSpeed;          // _10
	Vector3f mCurrentPos;    // _14
	Vector3f mOffset;        // _20
	Vector3f mDefaultPos;    // _2C
	f32 mTimer;              // _38
	MenuPanelMgr* mPanelMgr; // _3C
	f32 mLagrangeCoeffsX[3]; // _40
	f32 mLagrangeCoeffsY[3]; // _4C
	f32 mLagrangeCoeffsZ[3]; // _58
};

} // namespace zen

#endif
