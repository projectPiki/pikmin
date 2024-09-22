#ifndef _TAI_EFFECTACTIONS_H
#define _TAI_EFFECTACTIONS_H

#include "types.h"
#include "TAI/Aeffect.h"

struct Vector3f;

/**
 * @brief TODO
 */
struct TaiEffectAction : public TaiAction {
	inline TaiEffectAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiStopGenParticleGeneratorAction : public TaiAction {
	inline TaiStopGenParticleGeneratorAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
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
