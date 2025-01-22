#ifndef _PELLETSTATE_H
#define _PELLETSTATE_H

#include "types.h"
#include "StateMachine.h"
#include "Vector.h"

struct Pellet;

enum PelletStateID {
	PELSTATE_Normal    = 0,
	PELSTATE_Goal      = 1,
	PELSTATE_Appear    = 2,
	PELSTATE_Swallowed = 3,
	PELSTATE_Dead      = 4,
	PELSTATE_UfoLoad   = 5,
	PELSTATE_StateCount, // 6
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct PelletStateMachine : public StateMachine<Pellet> {
	virtual void init(Pellet*); // _08

	// _00     = VTBL
	// _00-_1C = StateMachine
};

/**
 * @brief TODO
 */
struct PelletState : public AState<Pellet> {
	inline PelletState(int stateID, char* name)
	    : AState(stateID)
	{
		mName = name;
	}

	// _00     = VTBL
	// _00-_10 = AState
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct PelletAppearState : public PelletState {
	PelletAppearState();

	virtual void procBounceMsg(Pellet*, MsgBounce*); // _0C
	virtual void init(Pellet*);                      // _38
	virtual void exec(Pellet*);                      // _3C
	virtual void cleanup(Pellet*);                   // _40

	// _00     = VTBL
	// _00-_10 = PelletState
	f32 _10; // _10
	f32 _14; // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PelletDeadState : public PelletState {
	PelletDeadState();

	virtual void init(Pellet*);    // _38
	virtual void exec(Pellet*);    // _3C
	virtual void cleanup(Pellet*); // _40

	// _00     = VTBL
	// _00-_10 = PelletState
};

/**
 * @brief TODO
 *
 * @note Size: 0x38.
 */
struct PelletGoalState : public PelletState {
	PelletGoalState();

	virtual void init(Pellet*);    // _38
	virtual void exec(Pellet*);    // _3C
	virtual void cleanup(Pellet*); // _40

	// _00     = VTBL
	// _00-_10 = PelletState
	f32 _10; // _10
	f32 _14;
	f32 _18;
	f32 _1C;
	f32 _20;
	Vector3f _24; // _24
	u8 _30;       // _30
	u8 _31;       // _31
	f32 _34;      // _34
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PelletNormalState : public PelletState {
	PelletNormalState();

	virtual void init(Pellet*);    // _38
	virtual void exec(Pellet*);    // _3C
	virtual void cleanup(Pellet*); // _40

	// _00     = VTBL
	// _00-_10 = PelletState
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PelletSwallowedState : public PelletState {
	PelletSwallowedState();

	virtual void init(Pellet*);    // _38
	virtual void exec(Pellet*);    // _3C
	virtual void cleanup(Pellet*); // _40

	// _00     = VTBL
	// _00-_10 = PelletState
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct PelletUfoLoadState : public PelletState {
	PelletUfoLoadState();

	virtual void init(Pellet*);    // _38
	virtual void exec(Pellet*);    // _3C
	virtual void cleanup(Pellet*); // _40

	// _00     = VTBL
	// _00-_10 = PelletState
	u8 mWaitTime; // _10
};

#endif
