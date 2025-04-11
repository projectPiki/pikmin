#ifndef _TAI_ACTION_H
#define _TAI_ACTION_H

#include "types.h"
#include "TekiStrategy.h"

struct Teki;

#define TAI_NO_TRANSIT     (-1)
#define TAI_RETURN_TRANSIT (-2)

/**
 * @brief TODO
 */
struct TaiAction {
	inline TaiAction(int nextState)
	    : mNextState(nextState)
	{
	}

	// _04 = VTBL
	int mNextState; // _00

	virtual void start(Teki& teki) { }                                            // _08
	virtual void finish(Teki& teki) { }                                           // _0C
	virtual bool act(Teki& teki) { return 0; }                                    // _10
	virtual bool actByEvent(TekiEvent& event) { return 0; }                       // _14
	virtual bool hasNextState() { return (mNextState >= 0 || mNextState == -2); } // _18
};

/**
 * @brief TODO
 */
struct TaiOnceAction : public TaiAction {
	TaiOnceAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&) { return true; } // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSerialAction : public TaiAction {
	TaiSerialAction(int nextState, int count);

	virtual void start(Teki& teki);            // _08
	virtual void finish(Teki& teki);           // _0C
	virtual bool act(Teki& teki);              // _10
	virtual bool actByEvent(TekiEvent& event); // _14

	void setAction(int idx, TaiAction* action) { mActionQueue[idx] = action; }

	// _04 = VTBL
	// _00-_08 = TaiAction
	int mCount;               // _08
	TaiAction** mActionQueue; // _0C, array of actions, size mCount
};

/**
 * @brief TODO
 */
struct TaiAndAction : public TaiAction {
	TaiAndAction(int nextState, TaiAction* actionA, TaiAction* actionB)
	    : TaiAction(nextState)
	{
		mActionA = actionA;
		mActionB = actionB;
	}

	virtual void start(Teki& teki) // _08
	{
		mActionA->start(teki);
		mActionB->start(teki);
	}
	virtual void finish(Teki& teki) // _0C
	{
		mActionA->finish(teki);
		mActionB->finish(teki);
	}
	virtual bool act(Teki& teki) // _10
	{
		bool isA = mActionA->act(teki);
		bool isB = mActionB->act(teki);

		return isA && isB;
	}

	// _04 = VTBL
	// _00-_08 = TaiAction
	TaiAction* mActionA; // _08
	TaiAction* mActionB; // _0C
};

/**
 * @brief TODO
 */
struct TaiNotAction : public TaiAction {
	TaiNotAction(int nextState, TaiAction* notAction)
	    : TaiAction(nextState)
	{
		mNotAction = notAction;
	}

	virtual void start(Teki& teki) { mNotAction->start(teki); }     // _08
	virtual void finish(Teki& teki) { mNotAction->finish(teki); }   // _0C
	virtual bool act(Teki& teki) { return !mNotAction->act(teki); } // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
	TaiAction* mNotAction; // _08
};

/**
 * @brief TODO
 */
struct TaiDependenceAction : public TaiAction {
	TaiDependenceAction(int nextState, TaiAction* dependent, TaiAction* primary)
	    : TaiAction(nextState)
	{
		mDependentAction = dependent;
		mPrimaryAction   = primary;
	}

	virtual void start(Teki& teki) // _08
	{
		mDependentAction->start(teki);
		mPrimaryAction->start(teki);
	}
	virtual void finish(Teki& teki) // _0C
	{
		mDependentAction->finish(teki);
		mPrimaryAction->finish(teki);
	}
	virtual bool act(Teki& teki) // _10
	{
		if (mPrimaryAction->act(teki)) {
			return mDependentAction->act(teki);
		}
		return false;
	}
	virtual bool actByEvent(TekiEvent& event) // _14
	{
		if (mPrimaryAction->actByEvent(event)) {
			return mDependentAction->actByEvent(event);
		}
		return false;
	}

	// _04 = VTBL
	// _00-_08 = TaiAction
	TaiAction* mDependentAction; // _08
	TaiAction* mPrimaryAction;   // _0C
};

/**
 * @brief TODO
 */
struct TaiState {
	TaiState(int count);

	virtual void start(Teki& teki);                // _08
	virtual void finish(Teki& teki);               // _0C
	virtual bool act(Teki& teki);                  // _10
	virtual bool eventPerformed(TekiEvent& event); // _14

	void setAction(int idx, TaiAction* action) { mActions[idx] = action; }

	// _00 = VTBL
	int mCount;           // _04, count of actions
	TaiAction** mActions; // _08, array of mCount actions
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct TaiStrategy : public TekiStrategy {
	TaiStrategy(int, int);

	virtual void start(Teki& teki);                // _08
	virtual void act(Teki& teki);                  // _0C
	virtual void eventPerformed(TekiEvent& event); // _10

	void init(int, int);

	void setState(int idx, TaiState* state) { mStateList[idx] = state; }

	// _00 = VTBL
	// _00-_04 = TekiStrategy
	int mStateCount;       // _04, count of states
	TaiState** mStateList; // _08, array of mCount states
	int mStateID;          // _0C
	u8 _10[0x4];           // _10, unknown
};

#endif
