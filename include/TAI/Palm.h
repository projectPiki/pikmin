#ifndef _TAI_PALM_H
#define _TAI_PALM_H

#include "types.h"
#include "TAI/MotionActions.h"
#include "TAI/ReactionActions.h"
#include "TekiParameters.h"

/////////// Pellet Posy AI Actions ///////////

/*
 * @brief TODO
 */
struct TaiPalmSoundTable {
	TaiPalmSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiPalmParameters : public TekiParameters {
	TaiPalmParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiPalmStrategy : public TaiStrategy {
	TaiPalmStrategy(TekiParameters*);

	virtual void start(Teki&);             // _08
	virtual void createEffect(Teki&, int); // _14
	virtual void draw(Teki&, Graphics&);   // _18

	void translateMotionIndex(Teki&, int);

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiPalmMotionAction : public TaiMotionAction {
	inline TaiPalmMotionAction() // TODO: this is a guess
	    : TaiMotionAction(-1)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiMotionAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiPalmDyingAction : public TaiDyingAction {
	inline TaiPalmDyingAction() // TODO: this is a guess
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
struct TaiPalmDamagingAction : public TaiDamagingAction {
	inline TaiPalmDamagingAction() // TODO: this is a guess
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
struct TaiPalmGrowingAction : public TaiAction {
	inline TaiPalmGrowingAction() // TODO: this is a guess
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
struct TaiPalmGrowAction : public TaiAction {
	inline TaiPalmGrowAction() // TODO: this is a guess
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
struct TaiPalmFlowerDamageAction : public TaiAction {
	inline TaiPalmFlowerDamageAction() // TODO: this is a guess
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
struct TaiPalmSunflowerAction : public TaiAction {
	inline TaiPalmSunflowerAction() // TODO: this is a guess
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
struct TaiPalmSettingPelletAction : public TaiAction {
	inline TaiPalmSettingPelletAction() // TODO: this is a guess
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
struct TaiPalmChangingColorAction : public TaiAction {
	inline TaiPalmChangingColorAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void resetTimer(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
