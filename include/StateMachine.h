#ifndef _STATEMACHINE_H
#define _STATEMACHINE_H

#include "Receiver.h"
#include "types.h"

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

	virtual void init(T*) { }                 // _38
	virtual void exec(T*) { }                 // _3C
	virtual void cleanup(T*) { }              // _40
	virtual void resume(T*) { }               // _44
	virtual void restart(T*) { }              // _48
	virtual void transit(T* obj, int stateID) // _4C
	{
		mStateMachine->transit(obj, stateID);
	}

	// only inlines according to the DLL
	int getID() { return mStateID; }
	void setMachine(StateMachine<T>* owner) { mStateMachine = owner; }
	char* getName() { return mName; }
	void setName(char* name) { mName = name; }

	// _00 = VTBL
	int mStateID;                   // _04
	StateMachine<T>* mStateMachine; // _08
	char* mName;                    // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
template <typename T>
struct StateMachine {
	inline StateMachine()
	    : mLastStateID(-1)
	{
	}

	virtual void init(T*) { }    // _08
	virtual void exec(T* target) // _0C
	{
		AState<T>* state = target->getCurrState();
		if (state) {
			state->exec(target);
		}
	}
	virtual void procMsg(T* target, Msg* msg) // _10
	{
		AState<T>* state = target->getCurrState();
		if (state) {
			state->procMsg(target, msg);
		}
	}
	virtual void transit(T* target, int nextStateID) // _14
	{
		isValidID(nextStateID);
		int nextStateIdx = mStateIndexes[nextStateID];
		AState<T>* state = target->getCurrState();
		if (state) {
			state->cleanup(target);
			mLastStateID = state->getID();
		}

		if (nextStateIdx >= mStateLimit) {
			// you were bad and sent a bad ID to transit to
			// time to get locked in the spinny wheel of death
			while (true) {
				;
			}
		}

		state = mStates[nextStateIdx];
		target->setCurrState(state);
		state->init(target);
	}

	// NB: this is ALL the inlines according to the DLL. No more.

	bool isValidID(int stateID)
	{
		if (stateID < 0 || stateID >= mStateLimit) {
			return false;
		}

		return true;
	}

	void registerState(AState<T>* state)
	{
		if (mStateCount < mStateLimit) {
			mStates[mStateCount] = state;

			if (isValidID(state->getID())) {
				state->setMachine(this);
				mStateIDs[mStateCount]        = state->getID();
				mStateIndexes[state->getID()] = mStateCount;
				mStateCount++;
			}
		}
	}

	void create(int limit)
	{
		mStateLimit   = limit;
		mStateCount   = 0;
		mStates       = new AState<T>*[mStateLimit];
		mStateIDs     = new int[mStateLimit];
		mStateIndexes = new int[mStateLimit];
	}

	int getLastStateID() { return mLastStateID; }

	char* getCurrName(T* target)
	{
		AState<T>* state = target->getCurrState();
		if (state) {
			return state->getName();
		}
		return "no name";
	}

	void resume(T* target)
	{
		AState<T>* state = target->getCurrState();
		if (state) {
			state->resume(target);
		}
	}

	void restart(T* target)
	{
		AState<T>* state = target->getCurrState();
		if (state) {
			state->restart(target);
		}
	}

	int getCurrID(T* target)
	{
		AState<T>* state = target->getCurrState();
		if (state) {
			return state->getID();
		}

		return -1;
	}

	// _00 = VTBL
	AState<T>** mStates; // _04
	int mStateCount;     // _08
	int mStateLimit;     // _0C
	int* mStateIDs;      // _10, indexed by state index (load order)
	int* mStateIndexes;  // _14, indexed by state IDs
	int mLastStateID;    // _18
};

#endif
