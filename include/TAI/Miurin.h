#ifndef _TAI_MIURIN_H
#define _TAI_MIURIN_H

#include "types.h"
#include "TAI/Aattack.h"
#include "TAI/Areaction.h"
#include "TAI/Ajudge.h"
#include "TAI/Amove.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "PaniAnimator.h"

struct CollPart;

/////////// Mamuta AI Actions ///////////

/*
 * @brief TODO
 */
struct TAImiurinSoundTable : public PaniSoundTable {
	TAImiurinSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAImiurinParameters : public TekiParameters {
	TAImiurinParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAImiurinStrategy : public YaiStrategy {
	TAImiurinStrategy();

	virtual void interact(Teki&, TekiInteractionKey&); // _20

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAImiurinAnimation : public TAIanimation {
	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinitMiurin : public TaiAction {
	inline TAIAinitMiurin() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgroggyMiurin : public TAIAreserveMotion {
	inline TAIAgroggyMiurin() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAresetAnimSpeedMiurin : public TaiAction {
	inline TAIAresetAnimSpeedMiurin() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAangryMiurin : public TAIAmotion {
	inline TAIAangryMiurin() // TODO: this is a guess
	    : TAIAmotion(-1, -1)
	{
	}

	virtual void start(Teki&);            // _08
	virtual bool act(Teki&);              // _10
	virtual f32 getFlickDirection(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAmotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckNaviMiurin : public TAIAinsideTerritoryRangeNavi {
	inline TAIAcheckNaviMiurin() // TODO: this is a guess
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TAIAinsideTerritoryRangeNavi?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckFlowerPikmin : public TaiAction {
	inline TAIAcheckFlowerPikmin() // TODO: this is a guess
	    : TaiAction(-1)
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
struct TAIAsatisfyMiurin : public TAIAreserveMotion {
	inline TAIAsatisfyMiurin() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAwatchNaviMiurin : public TaiAction {
	inline TAIAwatchNaviMiurin() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&);             // _10
	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAoutsideTerritoryMiurin : public TAIAoutsideTerritory {
	inline TAIAoutsideTerritoryMiurin() // TODO: this is a guess
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TAIAoutsideTerritory?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickingMiurin : public TAIAflickingReserveMotion {
	inline TAIAflickingMiurin() // TODO: this is a guess
	{
	}

	virtual f32 getFlickDirection(Teki&); // _20

	// _04     = VTBL
	// _00-_0C = TAIAflickingReserveMotion?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickCheckMiurin : public TAIAflickCheck {
	inline TAIAflickCheckMiurin() // TODO: this is a guess
	{
	}

	virtual bool act(Teki&);                // _10
	virtual int getDamageCountLimit(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAflickCheck?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAstickingPikiMiurin : public TAIAstickingPiki {
	inline TAIAstickingPikiMiurin() // TODO: this is a guess
	{
	}

	virtual int getPikiNum(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAstickingPiki?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckSatisfyMiurin : public TaiAction {
	inline TAIAcheckSatisfyMiurin() // TODO: this is a guess
	    : TaiAction(-1)
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
struct TAIAattackMiurin : public TAIAreserveMotion {
	inline TAIAattackMiurin() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAattackPosture : public TAIAreserveMotion {
	inline TAIAattackPosture() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAattackableTargetMiurin : public TAIAattackableTarget {
	inline TAIAattackableTargetMiurin() // TODO: this is a guess
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TAIAattackableTarget?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAapproachTargetPriorityFaceDirMiurin : public TAIAapproachTargetPriorityFaceDir {
	inline TAIAapproachTargetPriorityFaceDirMiurin() // TODO: this is a guess
	{
	}

	virtual void start(Teki&);      // _08
	virtual f32 getVelocity(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAapproachTargetPriorityFaceDir?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAturnFocusCreatureMiurin : public TAIAturnFocusCreature {
	inline TAIAturnFocusCreatureMiurin() // TODO: this is a guess
	{
	}

	virtual void start(Teki&);          // _08
	virtual f32 getTurnVelocity(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAturnFocusCreature?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdyingMiurin : public TAIAdying {
	inline TAIAdyingMiurin() // TODO: this is a guess
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAdying?
	// TODO: members
};

#endif
