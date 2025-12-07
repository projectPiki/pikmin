#ifndef _TAI_DORORO_H
#define _TAI_DORORO_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"

struct CollPart;

/////////// Smoky Progg (ドドロ) ///////////

/**
 * @brief TODO
 */
enum TAIdororoStateID {
	DOROROSTATE_Dead         = 0,
	DOROROSTATE_Init         = 1,
	DOROROSTATE_Birth        = 2,
	DOROROSTATE_GoGoalPath   = 3,
	DOROROSTATE_Flick        = 4,
	DOROROSTATE_Wait         = 5,
	DOROROSTATE_LookAround   = 6,
	DOROROSTATE_GoTargetPiki = 7,
	DOROROSTATE_Transform    = 8,
	DOROROSTATE_BarkGoal     = 9,
	DOROROSTATE_Bark         = 10,
	DOROROSTATE_Idle         = 11,
	DOROROSTATE_COUNT, // 12
};

/**
 * @brief TODO
 */
enum TAIdororoIntParams {
	DOROROPI_MaxPikminKill = TPI_COUNT, // 20
	DOROROPI_COUNT,                     // 21
};

/**
 * @brief TODO
 */
enum TAIdororoFloatParams {
	DOROROPF_MinLifespan = TPF_COUNT, // 50
	DOROROPF_RandomLifespan,          // 51
	DOROROPF_PikiNumForMaxDrag,       // 52, bigger = need more pikis stuck to slow the progg down
	DOROROPF_WalkingSpeedDragFactor,  // 53, bigger = more overall drag when any pikis are stuck
	DOROROPF_WaitTime,                // 54
	DOROROPF_COUNT,                   // 55
};

/**
 * @brief TODO
 */
struct TAIdororoSoundTable : public PaniSoundTable {
	TAIdororoSoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIdororoParameters : public TekiParameters {
	TAIdororoParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct TAIdororoStrategy : public YaiStrategy {
public:
	TAIdororoStrategy();

	virtual void start(Teki&);             // _08
	virtual void act(Teki&);               // _0C
	virtual void createEffect(Teki&, int); // _14
	virtual void draw(Teki&, Graphics&);   // _18

protected:
	void createCloudOfDust(Teki&, CollPart*);

	// _00     = VTBL
	// _00-_10 = YaiStrategy
	CollPart* mLeftHand;  // _10
	CollPart* mRightHand; // _14
};

/**
 * @brief TODO
 */
struct TAIdororoAnimation : public TAIanimation {
	TAIdororoAnimation()
	    : TAIanimation(TEKI_Dororo, "tekis/dororo/anims.bun")
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

#endif
