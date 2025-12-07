#ifndef _TAI_SHELL_H
#define _TAI_SHELL_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Action.h"
#include "TekiParameters.h"

/////////// Pearly Clamclamp (Shell) AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiShellIntParams {
	SHELLPI_ClosingLoopCount = TPI_COUNT,
	SHELLPI_COUNT, // 21
};

/**
 * @brief TODO
 */
enum TaiShellFloatParams {
	SHELLPF_OpeningPeriod = TPF_COUNT,
	SHELLPF_COUNT, // 51
};

/**
 * @brief TODO
 */
enum TaiShellStateID {
	SHELLSTATE_Normal = 0,
	SHELLSTATE_Open   = 1,
	SHELLSTATE_Warn   = 2,
	SHELLSTATE_Close  = 3,
	SHELLSTATE_Eat    = 4,
	SHELLSTATE_COUNT, // 5
};

/**
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

/**
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

/////////// Pearly Clamclamp (Pearl/Treasure) AI Actions ///////////

/**
 * @brief TODO
 */
enum TaiPearlStateID {
	PEARLSTATE_Die    = 0,
	PEARLSTATE_Damage = 1,
	PEARLSTATE_Normal = 2,
	PEARLSTATE_COUNT, // 3
};

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

#endif
