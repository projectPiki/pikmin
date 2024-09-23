#ifndef _TAI_ACTION_H
#define _TAI_ACTION_H

#include "types.h"
#include "TekiStrategy.h"

struct Teki;

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
	inline TaiOnceAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual bool act(Teki&); // _10

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

	// _04 = VTBL
	// _00-_08 = TaiAction
	int mCount;               // _08
	TaiAction** mActionQueue; // _0C, array of actions, size mCount
};

/**
 * @brief TODO
 */
struct TaiAndAction : public TaiAction {
	inline TaiAndAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiNotAction : public TaiAction {
	inline TaiNotAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	// _04 = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiDependenceAction : public TaiAction {
	inline TaiDependenceAction() // TODO: this is a guess
	    : TaiAction(0)
	{
	}

	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual bool act(Teki&);             // _10
	virtual bool actByEvent(TekiEvent&); // _14

	// _04 = VTBL
	// _00-_08 = TaiAction
	// TODO: members
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

	// _00 = VTBL
	int mCount;           // _04, count of actions
	TaiAction** mActions; // _08, array of mCount actions
};

/**
 * @brief TODO
 */
struct TaiStrategy : public TekiStrategy {
	TaiStrategy(int, int);

	virtual void start(Teki& teki);                // _08
	virtual void act(Teki& teki);                  // _0C
	virtual void eventPerformed(TekiEvent& event); // _10

	void init(int, int);

	// _00 = VTBL
	// _00-_04 = TekiStrategy
	int mCount;         // _04, count of states
	TaiState** mStates; // _08, array of mCount states
	int _0C;            // _0C
};

#endif
