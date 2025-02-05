#ifndef _TAI_EFFECTACTIONS_H
#define _TAI_EFFECTACTIONS_H

#include "types.h"
#include "TAI/Aeffect.h"

struct Vector3f;

/**
 * @brief TODO
 */
struct TaiEffectAction : public TaiAction {
	TaiEffectAction(int effID) // TODO: this is a guess
	    : TaiAction(-1)
	{
		mEffectType = effID;
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mEffectType; // _08
};

/**
 * @brief TODO
 */
struct TaiStartGenParticleGeneratorAction : public TaiAction {
	inline TaiStartGenParticleGeneratorAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	int _08; // _08
};

/**
 * @brief TODO
 */
struct TaiStopGenParticleGeneratorAction : public TaiAction {
	TaiStopGenParticleGeneratorAction(int p1)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		_08 = p1;
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	int _08; // _08
};

/**
 * @brief TODO
 */
struct TaiJointEffectAction : public TAIAeffCloudOfDust {
	TaiJointEffectAction(f32, int, int, int, int, int);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAeffCloudOfDust?
	// TODO: members
};

#endif
