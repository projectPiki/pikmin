#ifndef _PIKISTATE_H
#define _PIKISTATE_H

#include "types.h"
#include "Piki.h"
#include "StateMachine.h"
#include "Vector.h"

enum PikiStateID {
	PIKISTATE_Normal       = 0,
	PIKISTATE_Grow         = 1,
	PIKISTATE_Bury         = 2,
	PIKISTATE_Nukare       = 3,
	PIKISTATE_NukareWait   = 4,
	PIKISTATE_AutoNuki     = 5,
	PIKISTATE_Dying        = 6,
	PIKISTATE_Dead         = 7,
	PIKISTATE_Swallowed    = 8,
	PIKISTATE_Fired        = 9,
	PIKISTATE_Bubble       = 10,
	PIKISTATE_GoHang       = 11,
	PIKISTATE_Hanged       = 12,
	PIKISTATE_WaterHanged  = 13,
	PIKISTATE_Flying       = 14,
	PIKISTATE_Emit         = 15,
	PIKISTATE_Cliff        = 16,
	PIKISTATE_Fall         = 17,
	PIKISTATE_Wave         = 18,
	PIKISTATE_GrowUp       = 19,
	PIKISTATE_Push         = 20,
	PIKISTATE_PushPiki     = 21,
	PIKISTATE_Flick        = 22,
	PIKISTATE_Kinoko       = 23,
	PIKISTATE_Drown        = 24,
	PIKISTATE_Flown        = 25,
	PIKISTATE_LookAt       = 26,
	PIKISTATE_Bullet       = 27,
	PIKISTATE_Absorb       = 28,
	PIKISTATE_KinokoChange = 29,
	PIKISTATE_FallMeck     = 30,
	PIKISTATE_Emotion      = 31,
	PIKISTATE_UNUSED32     = 32, // unused
	PIKISTATE_Pressed      = 33,
	PIKISTATE_Unk34        = 34,
	PIKISTATE_Count, // 35?
};

/**
 * @brief TODO
 */
struct PikiStateMachine : public StateMachine<Piki> {
	virtual void init(Piki*);         // _08
	virtual void transit(Piki*, int); // _14

	// _00     = VTBL
	// _00-_1C = StateMachine
	// TODO: members
};

/**
 * @brief TODO
 */
struct PikiState : public AState<Piki> {
	PikiState(int stateID, char* name)
	    : AState(stateID)
	{
		setName(name);
	}

	virtual void transit(Piki*, int);             // _4C
	virtual void stopEffect() { }                 // _50
	virtual void restartEffect() { }              // _54
	virtual void dump();                          // _58
	virtual void doDump();                        // _5C
	virtual bool useLookUpdate() { return true; } // _60
	virtual bool collideAI() { return false; }    // _64
	virtual bool freeAI() { return false; }       // _68

	// _00     = VTBL
	// _00-_10 = AState
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct PikiAbsorbState : public PikiState {
	PikiAbsorbState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x1C - 0x10]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct PikiAutoNukiState : public PikiState {
	PikiAutoNukiState();

	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x4]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct PikiBubbleState : public PikiState {
	PikiBubbleState();

	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x20 - 0x10]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct PikiBulletState : public PikiState {
	PikiBulletState();

	virtual void procWallMsg(Piki*, MsgWall*); // _28
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x4]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PikiBuryState : public PikiState {
	PikiBuryState();

	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40

	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct PikiCliffState : public PikiState {
	PikiCliffState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

	bool nearEnough(Piki*);

	// unused/inlined:
	void startFall(Piki*);

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0xC];  // _10, unknown
	Vector3f _1C; // _1C
	u8 _28[0x4];  // _28, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PikiDeadState : public PikiState {
	PikiDeadState();

	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct PikiDrownState : public PikiState {
	PikiDrownState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0xC];  // _10, unknown
	Vector3f _1C; // _1C
	bool _28;     // _28, probably mIsCalled/mIsWhistled
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PikiDyingState : public PikiState {
	PikiDyingState();

	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct PikiEmitState : public PikiState {
	PikiEmitState();

	virtual void procBounceMsg(Piki*, MsgBounce*); // _0C
	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x4]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct PikiEmotionState : public PikiState {
	PikiEmotionState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40
	virtual void doDump();                     // _5C

	// _00     = VTBL
	// _00-_10 = PikiState
	Vector3f _10;        // _10
	u8 _1C;              // _1C
	u8 _1D;              // _1D
	u8 _1E[0x24 - 0x1E]; // _1E, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PikiFallMeckState : public PikiState {
	PikiFallMeckState();

	virtual void procBounceMsg(Piki*, MsgBounce*); // _0C
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40

	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct PikiFallState : public PikiState {
	PikiFallState();

	virtual void procBounceMsg(Piki*, MsgBounce*); // _0C
	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x4]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct PikiFiredState : public PikiState {
	PikiFiredState();

	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x20 - 0x10]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct PikiFlickState : public PikiState {
	PikiFlickState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x4];         // _10, unknown
	f32 _14;             // _14
	u8 _18[0x24 - 0x18]; // _18, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct PikiFlownState : public PikiState {
	PikiFlownState();

	virtual void procBounceMsg(Piki*, MsgBounce*); // _0C
	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40

	// _00     = VTBL
	// _00-_10 = PikiState
	f32 _10;             // _10
	u8 _14[0x24 - 0x14]; // _14, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x44.
 */
struct PikiFlyingState : public PikiState {
	PikiFlyingState();

	virtual void procBounceMsg(Piki*, MsgBounce*);   // _0C
	virtual void procStickMsg(Piki*, MsgStick*);     // _10
	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual void init(Piki*);                        // _38
	virtual void exec(Piki*);                        // _3C
	virtual void cleanup(Piki*);                     // _40
	virtual void stopEffect();                       // _50
	virtual void restartEffect();                    // _54

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x44 - 0x10]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PikiGoHangState : public PikiState {
	PikiGoHangState();

	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40

	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PikiGrowState : public PikiState {
	PikiGrowState();

	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PikiGrowupState : public PikiState {
	PikiGrowupState();

	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PikiHangedState : public PikiState {
	PikiHangedState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct PikiKinokoChangeState : public PikiState {
	PikiKinokoChangeState();

	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual void restart(Piki*);                   // _48
	virtual bool useLookUpdate() { return false; } // _60

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x4]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct PikiKinokoState : public PikiState {
	PikiKinokoState();

	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40

	void initWalk(Piki*);
	void exeAttack(Piki*);
	void exeBoid(Piki*);

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x8];  // _10, unknown
	Vector3f _18; // _18
	u8 _24[0x4];  // _24, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct PikiLookAtState : public PikiState {
	PikiLookAtState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

	// _00     = VTBL
	// _00-_10 = PikiState
	f32 _10;     // _10
	u32 _14;     // _14, unknown
	u8 _18[0x4]; // _18, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct PikiNormalState : public PikiState {
	PikiNormalState();

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual void procWallMsg(Piki*, MsgWall*);       // _28
	virtual void procOffWallMsg(Piki*, MsgOffWall*); // _2C
	virtual void init(Piki*);                        // _38
	virtual void exec(Piki*);                        // _3C
	virtual void cleanup(Piki*);                     // _40
	virtual void restart(Piki*);                     // _48
	virtual bool collideAI() { return true; }        // _64
	virtual bool freeAI() { return true; }           // _68

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x20 - 0x10]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PikiNukareState : public PikiState {
	PikiNukareState();

	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PikiNukareWaitState : public PikiState {
	PikiNukareWaitState();

	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct PikiPressedState : public PikiState {
	PikiPressedState();

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual void init(Piki*);                        // _38
	virtual void exec(Piki*);                        // _3C
	virtual void cleanup(Piki*);                     // _40
	virtual bool useLookUpdate() { return false; }   // _60

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x8]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct PikiPushPikiState : public PikiState {
	PikiPushPikiState();

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual void procAnimMsg(Piki*, MsgAnim*);       // _20
	virtual void procWallMsg(Piki*, MsgWall*);       // _28
	virtual void init(Piki*);                        // _38
	virtual void exec(Piki*);                        // _3C
	virtual void cleanup(Piki*);                     // _40
	virtual void resume(Piki*);                      // _44
	virtual void restart(Piki*);                     // _48

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x18 - 0x10]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct PikiPushState : public PikiState {
	PikiPushState();

	virtual void procAnimMsg(Piki*, MsgAnim*);       // _20
	virtual void procOffWallMsg(Piki*, MsgOffWall*); // _2C
	virtual void init(Piki*);                        // _38
	virtual void exec(Piki*);                        // _3C
	virtual void cleanup(Piki*);                     // _40
	virtual void resume(Piki*);                      // _44
	virtual void restart(Piki*);                     // _48

	// _00     = VTBL
	// _00-_10 = PikiState
	bool _10; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct PikiSwallowedState : public PikiState {
	PikiSwallowedState();

	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40

	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x4]; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PikiWaterHangedState : public PikiState {
	PikiWaterHangedState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PikiWaveState : public PikiState {
	PikiWaveState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40
	virtual void resume(Piki*);                // _44
	virtual void restart(Piki*);               // _48

	// unused/inlined:
	void waveAttack(Piki*);

	// _00     = VTBL
	// _00-_10 = PikiState
};

#endif
