#ifndef _TAI_OTIMOTI_H
#define _TAI_OTIMOTI_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Action.h"
#include "TekiParameters.h"

/////////// Frog (Yellow and White) AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiOtimotiIntParams {
	OTIMOTIPI_ReadyForJumpLoopCount = TPI_COUNT,
	OTIMOTIPI_COUNT, // 21
};

/**
 * @brief TODO
 */
enum TaiOtimotiFloatParams {
	OTIMOTIPF_DropVelocity = TPF_COUNT, // 50
	OTIMOTIPF_AttackStartHeight,        // 51
	OTIMOTIPF_WaitingWashPeriod,        // 52
	OTIMOTIPF_WaitingWashChance,        // 53
	OTIMOTIPF_WaitingTurnPeriod,        // 54
	OTIMOTIPF_WaitingTurnChance,        // 55
	OTIMOTIPF_ImpassablePeriod,         // 56
	OTIMOTIPF_ImpassableDistance,       // 57
	OTIMOTIPF_MissFuncMinCount,         // 58
	OTIMOTIPF_MissFuncMaxCount,         // 59
	OTIMOTIPF_MissFuncMinChance,        // 60
	OTIMOTIPF_MissFuncMaxChance,        // 61
	OTIMOTIPF_COUNT,                    // 62
};

/**
 * @brief TODO
 */
enum TaiOtimotiStateID {
	OTIMOTISTATE_Unk0  = 0,
	OTIMOTISTATE_Unk1  = 1,
	OTIMOTISTATE_Unk2  = 2,
	OTIMOTISTATE_Unk3  = 3,
	OTIMOTISTATE_Unk4  = 4,
	OTIMOTISTATE_Unk5  = 5,
	OTIMOTISTATE_Unk6  = 6,
	OTIMOTISTATE_Unk7  = 7,
	OTIMOTISTATE_Unk8  = 8,
	OTIMOTISTATE_Unk9  = 9,
	OTIMOTISTATE_Unk10 = 10,
	OTIMOTISTATE_Unk11 = 11,
	OTIMOTISTATE_Unk12 = 12,
	OTIMOTISTATE_Unk13 = 13,
	OTIMOTISTATE_Unk14 = 14,
	OTIMOTISTATE_Unk15 = 15,
	OTIMOTISTATE_Unk16 = 16,
	OTIMOTISTATE_COUNT, // 17
};

/**
 * @brief TODO
 */
struct TaiOtimotiSoundTable : public PaniSoundTable {
	TaiOtimotiSoundTable();

	// _00-_08 = PaniSoundTable
};

/**
 * @brief TODO
 */
struct TaiOtimotiParameters : public TekiParameters {
	TaiOtimotiParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiBlackFrogSoundTable : public PaniSoundTable {
	TaiBlackFrogSoundTable();

	// _00-_08 = PaniSoundTable
};

/**
 * @brief TODO
 */
struct TaiBlackFrogParameters : public TekiParameters {
	TaiBlackFrogParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiOtimotiStrategy : public TaiStrategy {
	TaiOtimotiStrategy(TekiParameters*);

	virtual void start(Teki&);                    // _08
	virtual void draw(Teki&, Graphics&);          // _18
	virtual void drawDebugInfo(Teki&, Graphics&); // _1C

	// _00     = VTBL
	// _00-_14 = TaiStrategy
};

#endif
