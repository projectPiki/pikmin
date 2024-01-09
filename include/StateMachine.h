#ifndef _STATEMACHINE_H
#define _STATEMACHINE_H

#include "types.h"
#include "Receiver.h"

struct Msg;

/**
 * @brief TODO
 */
template <typename T>
struct AState : public Receiver<T> {
	inline AState(int p1)
	    : _04(p1)
	    , _08(0)
	{
	}

	virtual void init(T*);         // _38
	virtual void exec(T*);         // _3C
	virtual void cleanup(T*);      // _40
	virtual void resume(T*);       // _44
	virtual void restart(T*);      // _48
	virtual void transit(T*, int); // _4C

	// _00 = VTBL
	int _04; // _04
	u32 _08; // _08, unknown
};

/**
 * @brief TODO
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

	// _00 = VTBL
	u8 _04[0x18 - 0x4]; // _04, unknown
	int _18;            // _18, state ID?
};

#endif
