#ifndef _PIKISTATE_H
#define _PIKISTATE_H

#include "Piki.h"
#include "StateMachine.h"
#include "Vector.h"
#include "types.h"

/**
 * @brief Piki high-level state IDs.
 *
 * Gameplay: this governs the Piki's current "mode of existence" (normal AI,
 * hazards like fire/water, being held/thrown, growth/planting, etc.).
 */
enum PikiStateID {
	PIKISTATE_Normal       = 0,  // Default active behavior state.
	PIKISTATE_Grow         = 1,  // Growth animation before becoming a planted sprout.
	PIKISTATE_Bury         = 2,  // Converts the Piki into a planted sprout (PikiHeadItem) and removes the actor.
	PIKISTATE_Nukare       = 3,  // Being plucked from the ground by a captain.
	PIKISTATE_NukareWait   = 4,  // A planted sprout waiting to be plucked.
	PIKISTATE_AutoNuki     = 5,  // Plucking itself out of the ground (cursor nuki, dororo bark).
	PIKISTATE_Dying        = 6,  // Plays death sequence prior to becoming inert.
	PIKISTATE_Dead         = 7,  // Inert/dead; no regular AI.
	PIKISTATE_Swallowed    = 8,  // Captured inside an enemy (temporarily removed from play).
	PIKISTATE_Fired        = 9,  // Burning panic state; usually ends in death unless extinguished.
	PIKISTATE_Bubble       = 10, // Trapped in a bubble; panics until freed or time runs out.
	PIKISTATE_GoHang       = 11, // Running to a captain to be thrown.
	PIKISTATE_Hanged       = 12, // Held by a captain, ready for a throw.
	PIKISTATE_WaterHanged  = 13, // Held by a captain over water.
	PIKISTATE_Flying       = 14, // In the air after being thrown.
	PIKISTATE_Emit         = 15, // Being ejected from an Onion.
	PIKISTATE_Cliff        = 16, // Teetering on the edge of a cliff.
	PIKISTATE_Fall         = 17, // Falling from a height.
	PIKISTATE_Wave         = 18, // Stunned by a shockwave.
	PIKISTATE_GrowUp       = 19, // Maturing flower stage after drinking nectar.
	PIKISTATE_Push         = 20, // Local push/brace behavior (separation / unsticking).
	PIKISTATE_PushPiki     = 21, // Resolves Piki-on-Piki pushing.
	PIKISTATE_Flick        = 22, // Being knocked back by an attack.
	PIKISTATE_Kinoko       = 23, // Infected by a Puffstool (mushroom state).
	PIKISTATE_Drown        = 24, // Drowning struggle/sink/death sequence.
	PIKISTATE_Flown        = 25, // Blown/knocked into a long tumble flight (distinct from thrown flight).
	PIKISTATE_LookAt       = 26, // Called attention; turns to face the captain.
	PIKISTATE_Bullet       = 27, // Launched as a fast projectile.
	PIKISTATE_Absorb       = 28, // Drinks nectar/water object to trigger growth.
	PIKISTATE_KinokoChange = 29, // Transforming into or out of the mushroom state.
	PIKISTATE_FallMeck     = 30, // Special fall/impact handling from mechanical enemies.
	PIKISTATE_Emotion      = 31, // Performs an idle emotion animation (joy, sad, cheer, etc.).
	PIKISTATE_UNUSED32     = 32, // Unused
	PIKISTATE_Pressed      = 33, // Crushed/flattened; stun + temporary invulnerability.
	PIKISTATE_Unk34        = 34, // Unused
	PIKISTATE_Count,             // Total number of states.
};

/**
 * @brief Owns and routes a Piki's high-level state transitions.
 */
struct PikiStateMachine : public StateMachine<Piki> {
	virtual void init(Piki*);         // _08
	virtual void transit(Piki*, int); // _14

	// _00     = VTBL
	// _00-_1C = StateMachine
};

/**
 * @brief Base class for all Piki state handlers.
 */
struct PikiState : public AState<Piki> {
	PikiState(int stateID, immut char* name)
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
 * @brief Drinks nectar and triggers flower-stage growth.
 *
 * @note Size: 0x1C.
 */
struct PikiAbsorbState : public PikiState {
public:
	PikiAbsorbState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	int mState;              // _10
	bool mHasAbsorbedNectar; // _14
	Creature* mNectar;       // _18
};

/**
 * @brief Self-plucks from the ground without direct captain interaction.
 *
 * @note Size: 0x14.
 */
struct PikiAutoNukiState : public PikiState {
public:
	PikiAutoNukiState();

	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	bool mToCreateEffect; // _10
};

/**
 * @brief Bubble-trap panic behavior.
 *
 * @note Size: 0x20.
 */
struct PikiBubbleState : public PikiState {
public:
	PikiBubbleState();

	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	f32 mSurvivalTimer;        // _10
	f32 mChangeDirectionTimer; // _14
	f32 mMoveDirection;        // _18
	f32 mSpeedRatio;           // _1C
};

/**
 * @brief Projectile flight state (fast launched movement + collisions).
 *
 * @note Size: 0x14.
 */
struct PikiBulletState : public PikiState {
public:
	PikiBulletState();

	virtual void procWallMsg(Piki*, MsgWall*); // _28
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	f32 mDistanceTravelled; // _10
};

/**
 * @brief Plants the Piki as a sprout and removes the actor.
 *
 * @note Size: 0x10.
 */
struct PikiBuryState : public PikiState {
public:
	PikiBuryState();

	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief Edge-slip and ledge-hang recovery (or transition into falling).
 *
 * @note Size: 0x2C.
 */
struct PikiCliffState : public PikiState {
public:
	PikiCliffState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

	void startFall(Piki*);

protected:
	bool nearEnough(Piki*);

	// _00     = VTBL
	// _00-_10 = PikiState
	u32 mState;                // _10, unknown
	int mLoopCounter;          // _14
	int mCliffHangType;        // _18, 0 = fall, 1 = hang
	Vector3f mInitialVelocity; // _1C
	f32 mInitialFaceDir;       // _28
};

/**
 * @brief Inert dead state (no look/AI updates).
 *
 * @note Size: 0x10.
 */
struct PikiDeadState : public PikiState {
public:
	PikiDeadState();

	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief Drowning sequence (struggle, sink, and death).
 *
 * @note Size: 0x2C.
 */
struct PikiDrownState : public PikiState {
	friend struct Navi;

public:
	PikiDrownState();

	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40
	virtual void procAnimMsg(Piki*, MsgAnim*); // _20

protected:
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
 * @brief Death animation/sequence prior to becoming fully dead.
 *
 * @note Size: 0x10.
 */
struct PikiDyingState : public PikiState {
public:
	PikiDyingState();

	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief Onion ejection (spawn-in bounce/land handling).
 *
 * @note Size: 0x14.
 */
struct PikiEmitState : public PikiState {
public:
	PikiEmitState();

	virtual void procBounceMsg(Piki*, MsgBounce*); // _0C
	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	bool mHasLanded; // _10
};

/**
 * @brief Plays an idle emotion animation with optional gaze/cheer behavior.
 *
 * @note Size: 0x24.
 */
struct PikiEmotionState : public PikiState {
	friend struct Navi;

public:
	PikiEmotionState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40
	virtual void doDump();                     // _5C

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	Vector3f mGazePosition; // _10
	u8 mGazeFlag;           // _1C
	u8 mCheerCount;         // _1D
	f32 mTimer;             // _20
};

/**
 * @brief Mechanical-enemy specific fall/impact handling.
 *
 * @note Size: 0x10.
 */
struct PikiFallMeckState : public PikiState {
public:
	PikiFallMeckState();

	virtual void procBounceMsg(Piki*, MsgBounce*); // _0C
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief Generic fall and landing recovery.
 *
 * @note Size: 0x14.
 */
struct PikiFallState : public PikiState {
public:
	PikiFallState();

	virtual void procBounceMsg(Piki*, MsgBounce*); // _0C
	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	int mState; // _10
};

/**
 * @brief Burning panic state (runs and eventually dies unless extinguished).
 *
 * @note Size: 0x20.
 */
struct PikiFiredState : public PikiState {
public:
	PikiFiredState();

	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	f32 mSurvivalTimer;        // _10
	f32 mChangeDirectionTimer; // _14
	f32 mMoveDirection;        // _18
	f32 mSpeedRatio;           // _1C
};

/**
 * @brief Knockback/flick reaction with timed recovery.
 *
 * @note Size: 0x24.
 */
struct PikiFlickState : public PikiState {
	friend struct Navi;

public:
	PikiFlickState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	u16 mState;         // _10
	f32 mGetUpTimer;    // _14
	f32 mInitialAngle;  // _18
	f32 mRotationDelta; // _1C
	f32 mStrength;      // _20
};

/**
 * @brief Long tumble flight after being launched by an enemy.
 *
 * @note Size: 0x24.
 */
struct PikiFlownState : public PikiState {
	friend struct Navi;

public:
	PikiFlownState();

	virtual void procBounceMsg(Piki*, MsgBounce*); // _0C
	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	f32 _10;             // _10
	f32 mInitialAngle;   // _14
	f32 mRotationDelta;  // _18
	f32 mFlickIntensity; // _1C
	u16 mState;          // _20
};

/**
 * @brief Thrown-airborne flight (steering, collisions, and landing).
 *
 * @note Size: 0x44.
 */
struct PikiFlyingState : public PikiState {
public:
	PikiFlyingState();

	virtual void procBounceMsg(Piki*, MsgBounce*);   // _0C
	virtual void procStickMsg(Piki*, MsgStick*);     // _10
	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual void init(Piki*);                        // _38
	virtual void exec(Piki*);                        // _3C
	virtual void cleanup(Piki*);                     // _40
	virtual void stopEffect();                       // _50
	virtual void restartEffect();                    // _54

protected:
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
 * @brief Runs to the captain to be picked up for throwing.
 *
 * @note Size: 0x10.
 */
struct PikiGoHangState : public PikiState {
public:
	PikiGoHangState();

	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief Pre-sprout growth animation (leads into bury/planting).
 *
 * @note Size: 0x10.
 */
struct PikiGrowState : public PikiState {
public:
	PikiGrowState();

	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief Flower-stage upgrade after drinking nectar.
 *
 * @note Size: 0x10.
 */
struct PikiGrowupState : public PikiState {
public:
	PikiGrowupState();

	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief Held by a captain, ready to be thrown.
 *
 * @note Size: 0x10.
 */
struct PikiHangedState : public PikiState {
public:
	PikiHangedState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief Handles the Puffstool infection transform in/out.
 *
 * @note Size: 0x14.
 */
struct PikiKinokoChangeState : public PikiState {
public:
	PikiKinokoChangeState();

	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual void restart(Piki*);                   // _48
	virtual bool useLookUpdate() { return false; } // _60

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	bool mDoBecomeKinoko; // _10, if false, change back to normal piki
};

/**
 * @brief Mushroom-infected behavior (hostile wander/attack).
 *
 * @note Size: 0x28.
 */
struct PikiKinokoState : public PikiState {
public:
	PikiKinokoState();

	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40

	void initWalk(Piki*);
	void exeAttack(Piki*);
	void exeBoid(Piki*);

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	Creature* mTarget;   // _10, nearest target?
	f32 mWalkTimer;      // _14
	Vector3f mTargetDir; // _18
	int mState;          // _24
};

/**
 * @brief Called attention: turns to face the captain.
 *
 * @note Size: 0x1C.
 */
struct PikiLookAtState : public PikiState {
public:
	PikiLookAtState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	f32 mTimer;        // _10
	int mState;        // _14
	f32 mRotationStep; // _18
};

/**
 * @brief Default active state (regular AI + interaction routing).
 *
 * @note Size: 0x20.
 */
struct PikiNormalState : public PikiState {
public:
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

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	u32 _UNUSED10;   // _10
	f32 _UNUSED14;   // _14
	Piki* mPushPiki; // _18, unused
	f32 _UNUSED1C;   // _1C
};

/**
 * @brief Pluck interaction (captain pulling sprout out).
 *
 * @note Size: 0x10.
 */
struct PikiNukareState : public PikiState {
public:
	PikiNukareState();

	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief Idle planted sprout waiting to be plucked.
 *
 * @note Size: 0x10.
 */
struct PikiNukareWaitState : public PikiState {
public:
	PikiNukareWaitState();

	virtual void init(Piki*);                      // _38
	virtual void exec(Piki*);                      // _3C
	virtual void cleanup(Piki*);                   // _40
	virtual bool useLookUpdate() { return false; } // _60

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief Crushed/flattened reaction with stun and invulnerability.
 *
 * @note Size: 0x18.
 */
struct PikiPressedState : public PikiState {
public:
	PikiPressedState();

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual void init(Piki*);                        // _38
	virtual void exec(Piki*);                        // _3C
	virtual void cleanup(Piki*);                     // _40
	virtual bool useLookUpdate() { return false; }   // _60

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	f32 mStunTimer;     // _10
	bool mIsInvincible; // _14
};

/**
 * @brief Piki-on-Piki pushing resolution.
 *
 * @note Size: 0x18.
 */
struct PikiPushPikiState : public PikiState {
public:
	PikiPushPikiState();

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual void procAnimMsg(Piki*, MsgAnim*);       // _20
	virtual void procWallMsg(Piki*, MsgWall*);       // _28
	virtual void init(Piki*);                        // _38
	virtual void exec(Piki*);                        // _3C
	virtual void cleanup(Piki*);                     // _40
	virtual void resume(Piki*);                      // _44
	virtual void restart(Piki*);                     // _48

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	int mCollisionFrameCount; // _10
	bool mIsFinishing;        // _14
};

/**
 * @brief Push/brace behavior during crowding or wall contact.
 *
 * @note Size: 0x14.
 */
struct PikiPushState : public PikiState {
	friend struct Piki;

public:
	PikiPushState();

	virtual void procAnimMsg(Piki*, MsgAnim*);       // _20
	virtual void procOffWallMsg(Piki*, MsgOffWall*); // _2C
	virtual void init(Piki*);                        // _38
	virtual void exec(Piki*);                        // _3C
	virtual void cleanup(Piki*);                     // _40
	virtual void resume(Piki*);                      // _44
	virtual void restart(Piki*);                     // _48

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	bool mIsFinishing; // _10
};

/**
 * @brief Inside-enemy swallowed handling.
 *
 * @note Size: 0x14.
 */
struct PikiSwallowedState : public PikiState {
public:
	PikiSwallowedState();

	virtual void init(Piki*);    // _38
	virtual void exec(Piki*);    // _3C
	virtual void cleanup(Piki*); // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
	u8 _10[0x4]; // _10, unknown
};

/**
 * @brief Held by a captain over water.
 *
 * @note Size: 0x10.
 */
struct PikiWaterHangedState : public PikiState {
public:
	PikiWaterHangedState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
};

/**
 * @brief Shockwave stun/reaction.
 *
 * @note Size: 0x10.
 */
struct PikiWaveState : public PikiState {
public:
	PikiWaveState();

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual void init(Piki*);                  // _38
	virtual void exec(Piki*);                  // _3C
	virtual void cleanup(Piki*);               // _40
	virtual void resume(Piki*);                // _44
	virtual void restart(Piki*);               // _48

	void waveAttack(Piki*);

protected:
	// _00     = VTBL
	// _00-_10 = PikiState
};

#endif
