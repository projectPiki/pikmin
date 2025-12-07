#ifndef _TAI_BEATLE_H
#define _TAI_BEATLE_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"

/////////// Armored Cannon Beetle (フタクチドックリ) ///////////

BEGIN_ENUM_TYPE(TAIbeatleFloatParms)
enum {
	FlickingTime = TPF_COUNT,
	AttackRange,
	Unk2,
	SuctionAngle,
	SuctionRadius,
	COUNT,
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAIbeatleStateID)
enum {
	Dying,
	Initializing,
	Unk2,
	Unk3,
	Unk4,
	Unk5,
	Unk6,
	Unk7,
	Unk8,
	Unk9,
	Unk10,
	Unk11,
	Unk12,
	Unk13,
	COUNT,
} END_ENUM_TYPE;

/*
 * @brief TODO
 */
struct TAIbeatleSoundTable : public PaniSoundTable {
	TAIbeatleSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIbeatleParameters : public TekiParameters {
	TAIbeatleParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIbeatleStrategy : public YaiStrategy {
	TAIbeatleStrategy();

	virtual void act(Teki&);                                 // _0C
	virtual bool interact(Teki&, immut TekiInteractionKey&); // _20

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIbeatleAnimation : public TAIanimation {
	TAIbeatleAnimation()
	    : TAIanimation(TEKI_Beatle, "tekis/beatle/anims.bun")
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

#endif
