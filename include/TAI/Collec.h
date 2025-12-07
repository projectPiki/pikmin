#ifndef _TAI_COLLEC_H
#define _TAI_COLLEC_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Action.h"
#include "TekiParameters.h"

struct NVector3f;

/////////// Breadbug AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiCollecIntParams {
	COLLECPI_CarryPower = TPI_COUNT,
	COLLECPI_COUNT, // 21
};

/**
 * @brief TODO
 */
enum TaiCollecFloatParams {
	COLLECPF_BouncingDamage = TPF_COUNT,  // 50
	COLLECPF_PressedDamage,               // 51
	COLLECPF_GoingUndergroundDistance,    // 52
	COLLECPF_UndergroundPeriod,           // 53
	COLLECPF_UndergroundPeriodRandomRate, // 54
	COLLECPF_FallingRotationVelocity,     // 55
	COLLECPF_DangerLife,                  // 56
	COLLECPF_RunningAwayPeriod,           // 57
	COLLECPF_ImpassablePeriod,            // 58
	COLLECPF_ImpassableDistance,          // 59
	COLLECPF_COUNT,                       // 60
};

/**
 * @brief TODO
 */
enum TaiCollecStateID {
	COLLECSTATE_Unk0  = 0,
	COLLECSTATE_Unk1  = 1,
	COLLECSTATE_Unk2  = 2,
	COLLECSTATE_Unk3  = 3,
	COLLECSTATE_Unk4  = 4,
	COLLECSTATE_Unk5  = 5,
	COLLECSTATE_Unk6  = 6,
	COLLECSTATE_Unk7  = 7,
	COLLECSTATE_Unk8  = 8,
	COLLECSTATE_Unk9  = 9,
	COLLECSTATE_Unk10 = 10,
	COLLECSTATE_Unk11 = 11,
	COLLECSTATE_Unk12 = 12,
	COLLECSTATE_Unk13 = 13,
	COLLECSTATE_Unk14 = 14,
	COLLECSTATE_COUNT, // 15
};

/**
 * @brief TODO
 */
struct TaiCollecSoundTable : public PaniSoundTable {
	TaiCollecSoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiCollecParameters : public TekiParameters {
	TaiCollecParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiCollecStrategy : public TaiStrategy {
	TaiCollecStrategy(TekiParameters*);

	virtual void start(Teki&);           // _08
	virtual void draw(Teki&, Graphics&); // _18

	// unused/inlined:
	void outputUndergroundPosition(Teki&, NVector3f&);

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/////////// Breadbug Nest AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiHollecStateID {
	HOLLECSTATE_Unk0 = 0,
	HOLLECSTATE_COUNT, // 1
};

/**
 * @brief TODO
 */
struct TaiHollecParameters : public TekiParameters {
	TaiHollecParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiHollecStrategy : public TaiStrategy {
	TaiHollecStrategy(TekiParameters*);

	virtual void start(Teki&);           // _08
	virtual void draw(Teki&, Graphics&); // _18

	// _00     = VTBL
	// _00-_14 = TaiStrategy
};

#endif
