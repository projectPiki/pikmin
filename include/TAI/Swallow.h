#ifndef _TAI_SWALLOW_H
#define _TAI_SWALLOW_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Action.h"
#include "TekiParameters.h"

/////////// Spotty Bulborb (チャッピー) / Spotty Bulbear (クマチャッピー) ///////////

/**
 * @brief TODO
 */
enum TaiSwallowFloatParams {
	SWALLOWPF_NoticeDistance = TPF_COUNT, // 50
	SWALLOWPF_LowerDamageRate,            // 51
	SWALLOWPF_LowerDamageCountRate,       // 52
	SWALLOWPF_TurnVelocityFuncMaxCount,   // 53
	SWALLOWPF_TurnVelocityFuncMaxRate,    // 54
	SWALLOWPF_FlickLowerAngle,            // 55
	SWALLOWPF_COUNT,                      // 56
};

/**
 * @brief TODO
 */
enum TaiSwallowStateID {
	SWALLOWSTATE_Unk0  = 0,
	SWALLOWSTATE_Unk1  = 1,
	SWALLOWSTATE_Unk2  = 2,
	SWALLOWSTATE_Unk3  = 3,
	SWALLOWSTATE_Unk4  = 4,
	SWALLOWSTATE_Unk5  = 5,
	SWALLOWSTATE_Unk6  = 6,
	SWALLOWSTATE_Unk7  = 7,
	SWALLOWSTATE_Unk8  = 8,
	SWALLOWSTATE_Unk9  = 9,
	SWALLOWSTATE_Unk10 = 10,
	SWALLOWSTATE_Unk11 = 11,
	SWALLOWSTATE_Unk12 = 12,
	SWALLOWSTATE_Unk13 = 13,
	SWALLOWSTATE_Unk14 = 14,
	SWALLOWSTATE_Unk15 = 15,
	SWALLOWSTATE_COUNT, // 16
};

/**
 * @brief TODO
 */
struct TaiSwallowSoundTable : public PaniSoundTable {
	TaiSwallowSoundTable();

	// _00-_08 = PaniSoundTable
};

/**
 * @brief TODO
 */
struct TaiSwallowParameters : public TekiParameters {
	TaiSwallowParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiBlackSwallowParameters : public TekiParameters {
	TaiBlackSwallowParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiSwallowStrategy : public TaiStrategy {
	TaiSwallowStrategy(TekiParameters*);

	virtual void start(Teki&);                         // _08
	virtual void draw(Teki&, Graphics&);               // _18
	virtual void drawDebugInfo(Teki&, Graphics&);      // _1C
	virtual bool interact(Teki&, TekiInteractionKey&); // _20

	bool isSleeping(Teki&);

	// _00     = VTBL
	// _00-_14 = TaiStrategy
};

#endif
