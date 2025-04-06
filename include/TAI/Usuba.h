#ifndef _TAI_USUBA_H
#define _TAI_USUBA_H

#include "types.h"
#include "TAI/Areaction.h"
#include "TAI/Aattack.h"
#include "TAI/Amove.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "PaniAnimator.h"

/////////// Usuba (Unused Enemy) AI Actions ///////////

/**
 * @brief TODO
 */
enum TAIusubaStateID {
	USUBASTATE_Die = 0,
	USUBASTATE_Fly = 1,
	USUBASTATE_COUNT, // 2
};

/**
 * @brief TODO
 */
struct TAIusubaSoundTable : public PaniSoundTable {
	TAIusubaSoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIusubaParameters : public TekiParameters {
	TAIusubaParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIusubaStrategy : public YaiStrategy {
	TAIusubaStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIusubaAnimation : public TAIanimation {
	TAIusubaAnimation()
	    : TAIanimation(TEKI_KabekuiB, "tekis/usuba/anims.bun") // yep, really had this.
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
};

/**
 * @brief TODO
 */
struct TAIAflyUsuba : public TAIAmotion {
	TAIAflyUsuba(int nextState, int motionID)
	    : TAIAmotion(nextState, motionID)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAmotion::start(teki);
		teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		teki.mVelocity.set(0.0f, 0.0f, 0.0f);

		teki.setFlag400();
		teki.setFlyingSwitch(false);
		teki.startFlying();
	}
	virtual bool act(Teki& teki) // _10
	{
		bool isAtMaxHeight = false;
		Vector3f vec1;
		Vector3f vec2;
		Vector3f vec3;
		// NB: this struct was probably *in* TAIusuba.cpp - could move it eventually sometime if we want.
		// PRINT("Usuba is flying. %f\n", teki.mTargetVelocity.y);
		if (teki.mCurrentAnimEvent == 1) {
			teki.setFlyingSwitch(true);
		}

		if (teki.getFlyingSwitch()) {
			teki.mTargetVelocity.y += 50.0f * gsys->getFrameTime();
			if (teki.mTargetVelocity.y > 500.0f) {
				teki.mTargetVelocity.y = 500.0f;
			}
		}

		if (teki.getYFromSeaLevel() > 3000.0) {
			teki.mTargetVelocity.y = 0.0f;
			isAtMaxHeight          = true;
		}
		return isAtMaxHeight;
	}

	// _04     = VTBL
	// _00-_0C = TAIAmotion
};

#endif
