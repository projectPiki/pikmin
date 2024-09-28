#ifndef _TAI_CHAPPY_H
#define _TAI_CHAPPY_H

#include "types.h"
#include "TAI/MotionActions.h"
#include "TekiParameters.h"
#include "TAI/ReactionActions.h"
#include "TAI/EffectActions.h"
#include "PaniAnimator.h"

/*
 * @brief TODO
 */
struct TaiChappySoundTable : public PaniSoundTable {
	TaiChappySoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiCatfishSoundTable : public PaniSoundTable {
	TaiCatfishSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiChappyParameters : public TekiParameters {
	TaiChappyParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiBlackChappyParameters : public TekiParameters {
	TaiBlackChappyParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiCatfishParameters : public TekiParameters {
	TaiCatfishParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiChappyStrategy : public TaiStrategy {
	TaiChappyStrategy(TekiParameters*);

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiChappyCryAction : public TaiAction {
	inline TaiChappyCryAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiChappySmashedAction : public TaiSmashedAction {
	inline TaiChappySmashedAction() // TODO: this is a guess
	    : TaiSmashedAction(0)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiSmashedAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiChappyLegEffectAction : public TaiJointEffectAction {
	TaiChappyLegEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

#endif
