#ifndef _TAI_TANK_H
#define _TAI_TANK_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"

/////////// Fiery Blowhog (ブタドックリ) ///////////

BEGIN_ENUM_TYPE(TAItankFloatParams)
enum {
	StepBackAttackDistance = TPF_COUNT, // 50
	FireAttackAnimSpeed,                // 51
	StepBackSpeed,                      // 52
	PatrolTimeout,                      // 53
	COUNT,                              // 54
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAItankStateID)
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
	COUNT, // 12
} END_ENUM_TYPE;

/**
 * @brief TODO
 */
struct TAItankSoundTable : public PaniSoundTable {
	TAItankSoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TAItankParameters : public TekiParameters {
	TAItankParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAItankStrategy : public YaiStrategy {
	TAItankStrategy();

	virtual void act(Teki&);                           // _0C
	virtual bool interact(Teki&, TekiInteractionKey&); // _20

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAItankAnimation : public TAIanimation {
	TAItankAnimation()
	    : TAIanimation(TEKI_Tank, "tekis/tank/anims.bun")
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

#endif
