#ifndef _TAI_MAR_H
#define _TAI_MAR_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"

/////////// Puffy Blowhog (フーセンドックリ) ///////////

BEGIN_ENUM_TYPE(TAImarFloatParams)
enum {
	Unk50 = TPF_COUNT, // 50
	Unk51,             // 51
	Unk52,             // 52
	Unk53,             // 53
	Unk54,             // 54
	Unk55,             // 55
	Unk56,             // 56
	COUNT,             // 57
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAImarIntParams)
enum {
	Unk20 = TPI_COUNT, // 20
	Unk21,             // 21
	Unk22,             // 22
	COUNT,             // 23
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAImarStateID)
enum {
	Unk0  = 0,
	Unk1  = 1,
	Unk2  = 2,
	Unk3  = 3,
	Unk4  = 4,
	Unk5  = 5,
	Unk6  = 6,
	Unk7  = 7,
	Unk8  = 8,
	Unk9  = 9,
	Unk10 = 10,
	Unk11 = 11,
	Unk12 = 12,
	Unk13 = 13,
	Unk14 = 14,
	COUNT, // 15
} END_ENUM_TYPE;

/*
 * @brief TODO
 */
struct TAImarSoundTable : public PaniSoundTable {
	TAImarSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAImarParameters : public TekiParameters {
	TAImarParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAImarStrategy : public YaiStrategy {
	TAImarStrategy();

	virtual void act(Teki&);                                 // _0C
	virtual bool interact(Teki&, immut TekiInteractionKey&); // _20

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAImarAnimation : public TAIanimation {
	TAImarAnimation()
	    : TAIanimation(TEKI_Mar, "tekis/mar/anims.bun")
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

#endif
