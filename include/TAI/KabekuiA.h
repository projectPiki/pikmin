#ifndef _TAI_KABEKUIA_H
#define _TAI_KABEKUIA_H

#include "types.h"
#include "TAI/Aattack.h"
#include "TAI/Areaction.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "PaniAnimator.h"

/////////// Female Sheargrub AI Actions ///////////

/**
 * @brief
 */
enum TAIkabekuiAFloatParms {
	KABEKUIAPF_Unk0 = TPF_COUNT,
	KABEKUIAPF_Unk1,
	KABEKUIAPF_Unk2,
	KABEKUIAPF_Unk3,
	KABEKUIAPF_COUNT,
};

/**
 * @brief
 */
enum TAIkabekuiAStateID {
	KABEKUIASTATE_Unk0,
	KABEKUIASTATE_Unk1,
	KABEKUIASTATE_Unk2,
	KABEKUIASTATE_Unk3,
	KABEKUIASTATE_Unk4,
	KABEKUIASTATE_Unk5,
	KABEKUIASTATE_Unk6,
	KABEKUIASTATE_Unk7,
	KABEKUIASTATE_Unk8,
	KABEKUIASTATE_Unk9,
	KABEKUIASTATE_Unk10,
	KABEKUIASTATE_COUNT,
};

/**
 * @brief
 */
enum TAIkabekuiAMotionID {
	KABEKUIAANIM_Unk0,
	KABEKUIAANIM_Unk1,
	KABEKUIAANIM_Unk2,
	KABEKUIAANIM_Unk3,
	KABEKUIAANIM_Unk4,
	KABEKUIAANIM_Unk5,
	KABEKUIAANIM_Unk6,
	KABEKUIAANIM_COUNT,
};

/*
 * @brief TODO
 */
struct TAIkabekuiASoundTable : public PaniSoundTable {
	TAIkabekuiASoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIkabekuiAParameters : public TekiParameters {
	TAIkabekuiAParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIkabekuiAStrategy : public YaiStrategy {
	TAIkabekuiAStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIkabekuiAAnimation : public TAIanimation {
	TAIkabekuiAAnimation()
	    : TAIanimation(TEKI_KabekuiA, "tekis/kabekuiA/anims.bun")
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAsleepKabekuiA : public TAIAtimerReaction {
	TAIAsleepKabekuiA(int nextState)
	    : TAIAtimerReaction(nextState, 3.0f)
	{
	}

	virtual f32 getFrameMax(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAtimerReaction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdiveKabekuiA : public TAIAtimerReaction {
	TAIAdiveKabekuiA(int nextState)
	    : TAIAtimerReaction(nextState, 3.0f)
	{
	}

	virtual f32 getFrameMax(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAtimerReaction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAattackWorkObjectKabekuiA : public TAIAattackWorkObject {
	inline TAIAattackWorkObjectKabekuiA(int nextState, int motionID, int p3) // TODO: this is a guess
		: TAIAattackWorkObject(nextState, motionID, p3)
	{
	}

	virtual void start(Teki&);               // _08
	virtual bool act(Teki&);                 // _10
	virtual f32 getDamage(Teki&);            // _1C
	virtual f32 getAttackPointRadius(Teki&); // _20
	virtual void attackEffect(Teki&);        // _24

	// _04     = VTBL
	// _00-_08 = TAIAattackWorkObject?
	// TODO: members
};

#endif
