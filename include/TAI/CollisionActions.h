#ifndef _TAI_COLLISIONACTIONS_H
#define _TAI_COLLISIONACTIONS_H

#include "types.h"
#include "TAI/Action.h"

/**
 * @brief TODO
 */
struct TaiBounceAction : public TaiAction {
	inline TaiBounceAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiGroundCollisionAction : public TaiAction {
	inline TaiGroundCollisionAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiWallCollisionAction : public TaiAction {
	inline TaiWallCollisionAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiCreatureCollisionAction : public TaiAction {
	inline TaiCreatureCollisionAction() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiPikiCollisionAction : public TaiCreatureCollisionAction {
	inline TaiPikiCollisionAction() // TODO: this is a guess
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiCreatureCollisionAction?
};

/**
 * @brief TODO
 */
struct TaiNaviCollisionAction : public TaiCreatureCollisionAction {
	inline TaiNaviCollisionAction() // TODO: this is a guess
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiCreatureCollisionAction?
};

/**
 * @brief TODO
 */
struct TaiTekiTypeCollisionAction : public TaiCreatureCollisionAction {
	inline TaiTekiTypeCollisionAction() // TODO: this is a guess
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiCreatureCollisionAction?
	int mTekiType; // _08
};

#endif
