#ifndef _TAI_SHELL_H
#define _TAI_SHELL_H

#include "types.h"
#include "TAI/MotionActions.h"
#include "TAI/EffectActions.h"
#include "TekiParameters.h"
#include "PaniAnimator.h"

struct Creature;

/////////// Pearly Clamclamp (Shell) AI Actions ///////////

/*
 * @brief TODO
 */
struct TaiShellSoundTable : public PaniSoundTable {
	TaiShellSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiShellParameters : public TekiParameters {
	TaiShellParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiShellStrategy : public TaiStrategy {
	TaiShellStrategy(TekiParameters*);

	virtual void start(Teki&);             // _08
	virtual void createEffect(Teki&, int); // _14
	virtual void draw(Teki&, Graphics&);   // _18

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiShellSetPositionAction : public TaiAction {
	inline TaiShellSetPositionAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&); // _10

	void setPosition(Teki&, Creature*);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiShellSaveItemPositionAction : public TaiAction {
	inline TaiShellSaveItemPositionAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&); // _10

	void setPosition(Teki&, Creature*);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiShellNaviPikiInsideAction : public TaiAction {
	inline TaiShellNaviPikiInsideAction() // TODO: this is a guess
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
struct TaiShellEatAction : public TaiAction {
	inline TaiShellEatAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/////////// Pearly Clamclamp (Pearl/Treasure) AI Actions ///////////

/*
 * @brief TODO
 */
struct TaiPearlSoundTable : public PaniSoundTable {
	TaiPearlSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiPearlParameters : public TekiParameters {
	TaiPearlParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiRocpearlParameters : public TekiParameters {
	TaiRocpearlParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiPearlStrategy : public TaiStrategy {
	TaiPearlStrategy(TekiParameters*);

	virtual void start(Teki&); // _08

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiPearlTresureSoundAction : public TaiAction {
	inline TaiPearlTresureSoundAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
