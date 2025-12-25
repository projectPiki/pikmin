#ifndef _TAI_EFFECTACTIONS_H
#define _TAI_EFFECTACTIONS_H

#include "TAI/Aeffect.h"
#include "types.h"

struct Vector3f;

/**
 * @brief TODO
 */
struct TaiEffectAction : public TaiAction {
	TaiEffectAction(int effID) // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
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
	TaiStopGenParticleGeneratorAction(int generatorIndex)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mGenIndex = generatorIndex;
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mGenIndex; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct TaiJointEffectAction : public TAIAeffCloudOfDust {
	TaiJointEffectAction(f32 sinkThreshold, int footNum, int jointID0, int jointID1, int jointID2, int jointID3);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_24 = TAIAeffCloudOfDust
};

#endif
