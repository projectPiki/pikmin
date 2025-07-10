#ifndef _PIKISTATE_H
#define _PIKISTATE_H

#include "Piki.h"
#include "StateMachine.h"
#include "Vector.h"
#include "types.h"

enum PikiStateID {
	PIKISTATE_Normal       = 0,
	PIKISTATE_Grow         = 1,
	PIKISTATE_Bury         = 2,
	PIKISTATE_Nukare       = 3, // Being plucked from the ground by a captain.
	PIKISTATE_NukareWait   = 4, // A planted sprout waiting to be plucked.
	PIKISTATE_AutoNuki     = 5, // Plucking itself out of the ground (cursor nuki, dororo bark).
	PIKISTATE_Dying        = 6,
	PIKISTATE_Dead         = 7,
	PIKISTATE_Swallowed    = 8,
	PIKISTATE_Fired        = 9,
	PIKISTATE_Bubble       = 10,
	PIKISTATE_GoHang       = 11, // Running to a captain to be thrown.
	PIKISTATE_Hanged       = 12, // Held by a captain, ready for a throw.
	PIKISTATE_WaterHanged  = 13, // Held by a captain over water.
	PIKISTATE_Flying       = 14, // In the air after being thrown.
	PIKISTATE_Emit         = 15, // Being ejected from an Onion.
	PIKISTATE_Cliff        = 16, // Teetering on the edge of a cliff.
	PIKISTATE_Fall         = 17, // Falling from a height.
	PIKISTATE_Wave         = 18, // Stunned by a shockwave.
	PIKISTATE_GrowUp       = 19, // Maturing flower stage after drinking nectar.
	PIKISTATE_Push         = 20,
	PIKISTATE_PushPiki     = 21,
	PIKISTATE_Flick        = 22, // Being knocked back by an attack.
	PIKISTATE_Kinoko       = 23, // Infected by a Puffstool (mushroom state).
	PIKISTATE_Drown        = 24,
	PIKISTATE_Flown        = 25,
	PIKISTATE_LookAt       = 26,
	PIKISTATE_Bullet       = 27,
	PIKISTATE_Absorb       = 28,
	PIKISTATE_KinokoChange = 29, // Transforming into or out of the mushroom state.
	PIKISTATE_FallMeck     = 30, // Special falling state from a mechanical enemy.
	PIKISTATE_Emotion      = 31, // Performing an idle emotional animation (e.g., joy).
	PIKISTATE_UNUSED32     = 32, // Unused
	PIKISTATE_Pressed      = 33, // Crushed or flattened by an object or enemy.
	PIKISTATE_Unk34        = 34, // Unused
	PIKISTATE_Count,             // 35?
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
	int mState;            // _10
	bool mHasAbsorbedNectar; // _14
	Creature* mNectar;     // _18
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
	bool mToCreateEffect; // _10
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
	f32 mSurvivalTimer;        // _10
	f32 mChangeDirectionTimer; // _14
	f32 mMoveDirection;        // _18
	f32 mSpeedRatio;           // _1C
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
	f32 mDistanceTravelled; // _10
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
	u32 mState;                // _10, unknown
	int mLoopCounter;          // _14
	int mCliffHangType;        // _18, 0 = fall, 1 = hang
	Vector3f mInitialVelocity; // _1C
	f32 mInitialFaceDir;       // _28
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

	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40
	virtual void procAnimMsg(Piki*, MsgAnim*); // _20

	// _00     = VTBL
	// _00-_10 = PikiState
	u16 mState;               // _10
	u16 mStruggleDuration;    // _12
	u16 _UNUSED14;            // _14
	u16 mOutOfWaterFrames;    // _16
	u8 _UNUSED18[0x4];        // _18
	Vector3f mEscapeVelocity; // _1C
	bool mIsBeingWhistled;    // _28, probably mIsCalled/mIsWhistled
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
	bool mHasLanded; // _10
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
	Vector3f mGazePosition; // _10
	u8 mGazeFlag;           // _1C
	u8 mCheerCount;         // _1D
	f32 mTimer;             // _20
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
	int mState; // _10
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
	f32 mSurvivalTimer;        // _10
	f32 mChangeDirectionTimer; // _14
	f32 mMoveDirection;        // _18
	f32 mSpeedRatio;           // _1C
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
	u16 mState;         // _10
	f32 mGetUpTimer;    // _14
	f32 mInitialAngle;  // _18
	f32 mRotationDelta; // _1C
	f32 mStrength;      // _20
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
	f32 mInitialAngle;   // _14
	f32 mRotationDelta;  // _18
	f32 mFlickIntensity; // _1C
	u16 mState;          // _20
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
	PermanentEffect mSparkleEffect; // _10
	f32 mGlideTimer;                // _20
	bool mIsFlowerGliding;          // _24
	bool mHasBounced;               // _25
	u8 _UNUSED26[0x2C - 0x26];      // _26
	Vector3f mHorizontalDirection;  // _2C
	f32 mInitialHorizontalSpeed;    // _38
	f32 mTargetHorizontalSpeed;     // _3C
	int mGroundTouchFrames;         // _40
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
	bool mDoBecomeKinoko; // _10, if false, change back to normal piki
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
	Creature* mTarget;   // _10, nearest target?
	f32 mWalkTimer;      // _14
	Vector3f mTargetDir; // _18
	int mState;          // _24
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
	f32 mTimer;        // _10
	int mState;        // _14
	f32 mRotationStep; // _18
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
	u32 _UNUSED10;   // _10
	f32 _UNUSED14;   // _14
	Piki* mPushPiki; // _18, unused
	f32 _UNUSED1C;   // _1C
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
	f32 mStunTimer;   // _10
	bool mIsInvincible; // _14
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
	int mCollisionFrameCount; // _10
	bool mIsFinishing;        // _14
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
	bool mIsFinishing; // _10
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
