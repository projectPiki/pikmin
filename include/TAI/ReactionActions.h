#ifndef _TAI_REACTIONACTIONS_H
#define _TAI_REACTIONACTIONS_H

#include "TAI/MotionActions.h"

/**
 * @brief TODO
 */
struct TaiDeadAction : public TaiAction {
	TaiDeadAction(int nextState)
	    : TaiAction(nextState)
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
struct TaiLifeZeroAction : public TaiAction {
	inline TaiLifeZeroAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiLifeDamageAction : public TaiAction {
	inline TaiLifeDamageAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiDyeAction : public TaiAction {
	TaiDyeAction()
	    : TaiAction(TAI_NO_TRANSIT)
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
struct TaiStartDyingAction : public TaiAction {
	TaiStartDyingAction()
	    : TaiAction(TAI_NO_TRANSIT)
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
struct TaiSpawnItemsAction : public TaiAction {
	TaiSpawnItemsAction()
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
struct TaiCreateDeadEffectAction : public TaiAction {
	inline TaiCreateDeadEffectAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiDyingAction : public TaiMotionAction {
	TaiDyingAction(int p1)
	    : TaiMotionAction(TAI_NO_TRANSIT, p1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiMotionAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiDamageCountResetAction : public TaiAction {
	TaiDamageCountResetAction()
	    : TaiAction(TAI_NO_TRANSIT)
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
struct TaiDamageCountAction : public TaiAction {
	TaiDamageCountAction(int nextState, int p2)
	    : TaiAction(nextState)
	{
		_08 = p2;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int _08; // _08
};

/**
 * @brief TODO
 */
struct TaiDamageScaleAction : public TaiAction {
	TaiDamageScaleAction(f32 p1)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		_08 = p1;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	f32 _08; // _08
};

/**
 * @brief TODO
 */
struct TaiDamageAction : public TaiAction {
	TaiDamageAction(int nextState)
	    : TaiAction(nextState)
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
struct TaiSimultaneousDamageAction : public TaiAction {
	TaiSimultaneousDamageAction(int nextState)
	    : TaiAction(nextState)
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
struct TaiCounterattackSimultaneousDamageAction : public TaiAction {
	TaiCounterattackSimultaneousDamageAction(int nextState)
	    : TaiAction(nextState)
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
struct TaiDamagingAction : public TaiMotionAction {
	TaiDamagingAction(int nextState, int motionIdx)
	    : TaiMotionAction(nextState, motionIdx)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiMotionAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiTargetNearestAssailantAction : public TaiAction {
	inline TaiTargetNearestAssailantAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiTargetNearestCollisionAction : public TaiAction {
	inline TaiTargetNearestCollisionAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiStickedAction : public TaiAction {
	inline TaiStickedAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiSmashedAction : public TaiAction {
	inline TaiSmashedAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiBeingPressedAction : public TaiAction {
	inline TaiBeingPressedAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiPressedAction : public TaiAction {
	inline TaiPressedAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiWarnAction : public TaiAction {
	inline TaiWarnAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
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
struct TaiDangerLifeAction : public TaiAction {
	inline TaiDangerLifeAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
