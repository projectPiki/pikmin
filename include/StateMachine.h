#ifndef _STATEMACHINE_H
#define _STATEMACHINE_H

#include "types.h"
#include "Receiver.h"

template <typename T>
struct StateMachine;

struct Msg;

/**
 * @brief TODO
 */
template <typename T>
struct AState : public Receiver<T> {
	inline AState(int stateID)
	    : mStateID(stateID)
	    , mStateMachine(nullptr)
	{
	}

	virtual void init(T*);         // _38
	virtual void exec(T*);         // _3C
	virtual void cleanup(T*);      // _40
	virtual void resume(T*);       // _44
	virtual void restart(T*);      // _48
	virtual void transit(T*, int); // _4C

	inline int getStateID() const { return mStateID; }

	// _00 = VTBL
	int mStateID;                   // _04
	StateMachine<T>* mStateMachine; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
template <typename T>
struct StateMachine {
	inline StateMachine()
	    : _18(-1)
	{
	}

	virtual void init(T*);          // _08
	virtual void exec(T*);          // _0C
	virtual void procMsg(T*, Msg*); // _10
	virtual void transit(T*, int);  // _14

	inline bool isValidState(AState<T>* state)
	{
		if (state->mStateID < 0 || state->mStateID >= mStateLimit) {
			return false;
		}

		return true;
	}

	inline AState<T>* getState(int idx) { return mStates[idx]; }
	inline void setState(int idx, AState<T>* state) { mStates[idx] = state; }

	inline void appendState(AState<T>* state) { setState(mStateCount, state); }

	inline void initState(AState<T>* state)
	{
		state->mStateMachine           = this;
		mStateIDs[mStateCount]         = state->mStateID;
		mStateIndexes[state->mStateID] = mStateCount;
		mStateCount++;
	}

	inline bool isFull() { return mStateCount >= mStateLimit; }

	// _00 = VTBL
	AState<T>** mStates; // _04
	int mStateCount;     // _08
	int mStateLimit;     // _0C
	int* mStateIDs;      // _10, indexed by state index (load order)
	int* mStateIndexes;  // _14, indexed by state IDs
	int _18;             // _18, state ID?
};

#endif
