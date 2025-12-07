#ifndef _TAI_MIURIN_H
#define _TAI_MIURIN_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"

BEGIN_ENUM_TYPE(TAImiurinFloatParams)
enum {
	RelaxTime = TPF_COUNT, // 50
	EyeRollTime,           // 51
	CheckNaviChance,       // 52
	AngryRotationSpeed,    // 53
	COUNT,                 // 54
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAImiurinIntParams)
enum {
	MaxStickPiki = TPI_COUNT, // 20
	ShakeOffHitCount,         // 21
	RelaxingFlowerNum,        // 22
	COUNT,                    // 23
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAImiurinStateID)
enum {
	Dead   = 0,
	Init   = 1,
	Unk2   = 2,
	Unk3   = 3,
	Unk4   = 4,
	Unk5   = 5,
	Unk6   = 6,
	Angry  = 7,
	Unk8   = 8,
	Unk9   = 9,
	Unk10  = 10,
	Unk11  = 11,
	Unk12  = 12,
	Unk13  = 13,
	Unk14  = 14,
	Unk15  = 15,
	Unk16  = 16,
	Unk17  = 17,
	Unk18  = 18,
	Unk19  = 19,
	Unk20  = 20,
	Unk21  = 21,
	Unk22  = 22,
	Groggy = 23,
	COUNT, // 24
} END_ENUM_TYPE;

/////////// Mamuta AI Actions ///////////

/**
 * @brief TODO
 */
struct TAImiurinSoundTable : public PaniSoundTable {
	TAImiurinSoundTable();

	// _00-_08 = PaniSoundTable
};

/**
 * @brief TODO
 */
struct TAImiurinParameters : public TekiParameters {
	TAImiurinParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TAImiurinStrategy : public YaiStrategy {
	TAImiurinStrategy();

	virtual bool interact(Teki&, TekiInteractionKey&); // _20

	// _00     = VTBL
	// _00-_10 = YaiStrategy
};

/**
 * @brief TODO
 */
struct TAImiurinAnimation : public TAIanimation {
	TAImiurinAnimation()
	    : TAIanimation(TEKI_KabekuiB, "tekis/miurin/anims.bun") // yep, really had this.
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
};

#endif
