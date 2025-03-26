#ifndef _TAI_CHAPPY_H
#define _TAI_CHAPPY_H

#include "types.h"
#include "TAI/MotionActions.h"
#include "TekiParameters.h"
#include "TAI/ReactionActions.h"
#include "TAI/EffectActions.h"
#include "PaniAnimator.h"

/**
 * @brief TODO
 */
enum TaiChappyIntParams {
	CHAPPYPI_SmashType = TPI_COUNT, // 20
	CHAPPYPI_COUNT,                 // 21
};

/**
 * @brief TODO
 */
enum TaiChappyFloatParams {
	CHAPPYPF_PressedPeriod = TPF_COUNT, // _50
	CHAPPYPF_CryingPeriod,              // 51
	CHAPPYPF_SmashDamage,               // 52
	CHAPPYPF_COUNT,                     // 53
};

/**
 * @brief TODO
 */
enum TaiChappyStateID {
	CHAPPYSTATE_Unk0  = 0,
	CHAPPYSTATE_Unk1  = 1,
	CHAPPYSTATE_Unk2  = 2,
	CHAPPYSTATE_Unk3  = 3,
	CHAPPYSTATE_Unk4  = 4,
	CHAPPYSTATE_Unk5  = 5,
	CHAPPYSTATE_Unk6  = 6,
	CHAPPYSTATE_Unk7  = 7,
	CHAPPYSTATE_Unk8  = 8,
	CHAPPYSTATE_Unk9  = 9,
	CHAPPYSTATE_Unk10 = 10,
	CHAPPYSTATE_Unk11 = 11,
	CHAPPYSTATE_Unk12 = 12,
	CHAPPYSTATE_Unk13 = 13,
	CHAPPYSTATE_Unk14 = 14,
	CHAPPYSTATE_Unk15 = 15,
	CHAPPYSTATE_COUNT, // 16
};

/**
 * @brief TODO
 */
struct TaiChappySoundTable : public PaniSoundTable {
	TaiChappySoundTable();

	// _00-_08 = PaniSoundTable
};

/**
 * @brief TODO
 */
struct TaiCatfishSoundTable : public PaniSoundTable {
	TaiCatfishSoundTable();

	// _00-_08 = PaniSoundTable
};

/**
 * @brief TODO
 */
struct TaiChappyParameters : public TekiParameters {
	TaiChappyParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiBlackChappyParameters : public TekiParameters {
	TaiBlackChappyParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiCatfishParameters : public TekiParameters {
	TaiCatfishParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiChappyStrategy : public TaiStrategy {
	TaiChappyStrategy(TekiParameters*);

	// _00     = VTBL
	// _00-_14 = TaiStrategy
};

/**
 * @brief TODO
 */
struct TaiChappyCryAction : public TaiAction {
	TaiChappyCryAction(int nextState)
	    : TaiAction(nextState)
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
	TaiChappySmashedAction(int nextState)
	    : TaiSmashedAction(nextState)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiSmashedAction?
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
