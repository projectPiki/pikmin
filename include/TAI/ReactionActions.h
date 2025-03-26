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
	TaiLifeZeroAction()
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
struct TaiLifeDamageAction : public TaiAction {
	TaiLifeDamageAction(f32 damage)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mDamage = damage;
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	f32 mDamage; // _08
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
	TaiDyingAction(int motionIdx)
	    : TaiMotionAction(TAI_NO_TRANSIT, motionIdx)
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
	TaiDamageCountAction(int nextState, int maxDamageCnt)
	    : TaiAction(nextState)
	{
		mMaxDamageCount = maxDamageCnt;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mMaxDamageCount; // _08
};

/**
 * @brief TODO
 */
struct TaiDamageScaleAction : public TaiAction {
	TaiDamageScaleAction(f32 scale)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mScale = scale;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	f32 mScale; // _08
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
	TaiSmashedAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
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
	TaiPressedAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool actByEvent(TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
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
	TaiDangerLifeAction(int nextState) // straight up never used
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	f32 mDangerHealth; // _08
};

#endif
