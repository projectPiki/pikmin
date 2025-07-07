#ifndef _NAVISTATE_H
#define _NAVISTATE_H

#include "Navi.h"
#include "StateMachine.h"
#include "Vector.h"
#include "Win.h"
#include "types.h"

struct NaviState;

/**
 * @brief TODO
 */
enum NaviStateID {
	NAVISTATE_NULL        = -1,
	NAVISTATE_Walk        = 0,
	NAVISTATE_Throw       = 1,
	NAVISTATE_ThrowWait   = 2,
	NAVISTATE_Gather      = 3,
	NAVISTATE_Release     = 4,
	NAVISTATE_Nuku        = 5,
	NAVISTATE_NukuAdjust  = 6,
	NAVISTATE_Pressed     = 7,
	NAVISTATE_Flick       = 8,
	NAVISTATE_Funbari     = 9,
	NAVISTATE_Rope        = 10,
	NAVISTATE_RopeExit    = 11,
	NAVISTATE_Container   = 12,
	NAVISTATE_Ufo         = 13,
	NAVISTATE_UfoAccess   = 14,
	NAVISTATE_PartsAccess = 15,
	NAVISTATE_Pick        = 16,
	NAVISTATE_Idle        = 17,
	NAVISTATE_Stuck       = 18,
	NAVISTATE_Bury        = 19,
	NAVISTATE_Geyzer      = 20, // dev spelling
	NAVISTATE_DemoWait    = 21,
	NAVISTATE_DemoInf     = 22,
	NAVISTATE_Starting    = 23,
	NAVISTATE_Pellet      = 24,
	NAVISTATE_DemoSunset  = 25,
	NAVISTATE_Sow         = 26,
	NAVISTATE_Water       = 27,
	NAVISTATE_Attack      = 28,
	NAVISTATE_Dead        = 29,
	NAVISTATE_Push        = 30,
	NAVISTATE_PushPiki    = 31,
	NAVISTATE_Lock        = 32,
	NAVISTATE_PikiZero    = 33,
	NAVISTATE_Clear       = 34,
	NAVISTATE_IroIro      = 35,
	NAVISTATE_Count, // 36
};

/**
 * @brief TODO
 */
struct NaviState : public AState<Navi> {
	inline NaviState(int stateID)
	    : AState(stateID)
	{
	}

	virtual bool invincible(Navi*) { return false; } // _50 (weak)

	// _00     = VTBL
	// _00-_10 = AState
};

/**
 * @brief TODO
 */
struct NaviStateMachine : public StateMachine<Navi> {
	virtual void init(Navi*); // _08

	NaviState* getNaviState(Navi*);

	// _00     = VTBL
	// _00-_1C = StateMachine
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct NaviAttackState : public NaviState {
	NaviAttackState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40
	virtual void resume(Navi*);                // _44
	virtual void restart(Navi*);               // _48

	// _00     = VTBL
	// _00-_10 = NaviState
	u16 _10; // _10
	u8 _12;  // _12
	f32 _14; // _14
	f32 _18; // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct NaviBuryState : public NaviState {
	NaviBuryState();

	virtual void procAnimMsg(Navi*, MsgAnim*);      // _20
	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual bool invincible(Navi*) { return true; } // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	Vector3f mPreviousStickInput; // _10
	u8 mBuryState;                // _1C
	u8 mEscapeAttemptCounter;     // _1D
	u8 mValidEscapeAttempts;      // _1E
	u8 mEscapeTimer;              // _1F
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NaviClearState : public NaviState {
	NaviClearState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40

	// _00     = VTBL
	// _00-_10 = NaviState
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct NaviContainerState : public NaviState, virtual public ContainerWin::Listener, virtual public GmWin::CloseListener {
	NaviContainerState();

	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual bool invincible(Navi*) { return true; } // _50
	virtual void informWin(int);                    // _54
	virtual void onCloseWindow();                   // _58

	void enterPikis(Navi*, int);
	void exitPikis(Navi*, int);

	// _00     = VTBL
	// _00-_10 = NaviState
	// _10     = ContainerWin::Listener ptr
	// _14     = GmWin::CloseListener ptr
	int _18; // _18
	int _1C; // _1C
	         // ContainerWin::Listener
	         // GmWin::CloseListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NaviDeadState : public NaviState {
	NaviDeadState();

	virtual void procAnimMsg(Navi*, MsgAnim*);      // _20
	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual void restart(Navi*);                    // _48
	virtual bool invincible(Navi*) { return true; } // _50

	// _00     = VTBL
	// _00-_10 = NaviState
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NaviDemoInfState : public NaviState {
	NaviDemoInfState();

	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual bool invincible(Navi*) { return true; } // _50

	// _00     = VTBL
	// _00-_10 = NaviState
};

/**
 * @brief TODO
 *
 * @note Size: 0x40.
 */
struct NaviDemoSunsetState : public NaviState {
	NaviDemoSunsetState();

	/**
	 * @brief TODO
	 */
	enum DemoStateID {
		DEMOSTATE_Go      = 0,
		DEMOSTATE_Look    = 1,
		DEMOSTATE_Whistle = 2,
		DEMOSTATE_Wait    = 3,
		DEMOSTATE_Sit     = 4,
		DEMOSTATE_Count, // 5
	};

	/**
	 * @brief TODO
	 */
	struct DemoStateMachine : public StateMachine<NaviDemoSunsetState> {
		virtual void init(NaviDemoSunsetState*); // _08

		// _00     = VTBL
		// _00-_1C = StateMachine
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct DemoState : public AState<NaviDemoSunsetState> {
		inline DemoState(int stateID)
		    : AState(stateID)
		{
		}

		// _00     = VTBL
		// _00-_10 = AState
	};

	/**
	 * @brief TODO
	 */
	struct GoState : public DemoState {
		inline GoState()
		    : DemoState(DEMOSTATE_Go)
		{
		}

		virtual void procAnimMsg(NaviDemoSunsetState*, MsgAnim*); // _20
		virtual void init(NaviDemoSunsetState*);                  // _38
		virtual void exec(NaviDemoSunsetState*);                  // _3C
		virtual void cleanup(NaviDemoSunsetState*);               // _40

		// _00     = VTBL
		// _00-_0C = AState
		int _10;  // _10
		bool _14; // _14
	};

	/**
	 * @brief TODO
	 */
	struct LookState : public DemoState {
		inline LookState()
		    : DemoState(DEMOSTATE_Look)
		{
		}

		virtual void procAnimMsg(NaviDemoSunsetState*, MsgAnim*); // _20
		virtual void init(NaviDemoSunsetState*);                  // _38
		virtual void exec(NaviDemoSunsetState*);                  // _3C
		virtual void cleanup(NaviDemoSunsetState*);               // _40

		// _00     = VTBL
		// _00-_0C = AState
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct SitState : public DemoState {
		inline SitState()
		    : DemoState(DEMOSTATE_Sit)
		{
		}

		virtual void init(NaviDemoSunsetState*);    // _38
		virtual void exec(NaviDemoSunsetState*);    // _3C
		virtual void cleanup(NaviDemoSunsetState*); // _40

		// _00     = VTBL
		// _00-_0C = AState
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct WaitState : public DemoState {
		inline WaitState()
		    : DemoState(DEMOSTATE_Wait)
		{
		}

		virtual void init(NaviDemoSunsetState*);    // _38
		virtual void exec(NaviDemoSunsetState*);    // _3C
		virtual void cleanup(NaviDemoSunsetState*); // _40

		// _00     = VTBL
		// _00-_0C = AState
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct WhistleState : public DemoState {
		inline WhistleState()
		    : DemoState(DEMOSTATE_Whistle)
		{
		}

		virtual void procAnimMsg(NaviDemoSunsetState*, MsgAnim*); // _20
		virtual void init(NaviDemoSunsetState*);                  // _38
		virtual void exec(NaviDemoSunsetState*);                  // _3C
		virtual void cleanup(NaviDemoSunsetState*);               // _40

		void enterAllPikis(NaviDemoSunsetState*);

		// _00     = VTBL
		// _00-_0C = AState
		int _10; // _10
	};

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40

	void setActors(Navi*);

	AState<NaviDemoSunsetState>* getCurrState() { return mCurrentState; }

	void setCurrState(AState<NaviDemoSunsetState>* state) { mCurrentState = state; }

	// _00     = VTBL
	// _00-_10 = NaviState
	Navi* mNavi;                                // _10
	Vector3f mStartPos;                         // _14
	Vector3f mGoalPos;                          // _20
	f32 _2C;                                    // _2C
	f32 _30;                                    // _30
	bool mOpenedAccount;                        // _34
	DemoStateMachine* mStateMachine;            // _38
	AState<NaviDemoSunsetState>* mCurrentState; // _3C, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct NaviDemoWaitState : public NaviState {
	NaviDemoWaitState();

	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual bool invincible(Navi*) { return true; } // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	Vector3f mLookAtPos; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct NaviFlickState : public NaviState {
	NaviFlickState();

	virtual void procAnimMsg(Navi*, MsgAnim*);      // _20
	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual bool invincible(Navi*) { return true; } // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	u16 mFlickState;          // _10
	f32 mGetupAnimationTimer; // _14
	f32 mDirection;           // _18
	f32 mRandVariation;       // _1C
	f32 mIntensity;           // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NaviFunbariState : public NaviState {
	NaviFunbariState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40

	// _00     = VTBL
	// _00-_10 = NaviState
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct NaviGatherState : public NaviState {
	NaviGatherState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40
	virtual void resume(Navi*);                // _44
	virtual void restart(Navi*);               // _48

	// _00     = VTBL
	// _00-_10 = NaviState
	u16 _10; // _10
	f32 _14; // _14
	u8 _18;  // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x34.
 */
struct NaviGeyzerState : public NaviState {
	NaviGeyzerState();

	virtual void procBounceMsg(Navi*, MsgBounce*);  // _0C
	virtual void procAnimMsg(Navi*, MsgAnim*);      // _20
	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual bool invincible(Navi*) { return true; } // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	u16 mGeyserState;     // _10
	f32 _14;              // _14
	f32 mPlayerDirection; // _18
	f32 _1C;              // _1C
	Vector3f _20;         // _20
	f32 _2C;              // _2C
	u8 _30;               // _30
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct NaviIdleState : public NaviState {
	NaviIdleState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	u8 _10[0x4];         // _10, unknown
	bool mStopBeingIdle; // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NaviIroIroState : public NaviState {
	NaviIroIroState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40

	// _00     = VTBL
	// _00-_10 = NaviState
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NaviLockState : public NaviState {
	NaviLockState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40

	// _00     = VTBL
	// _00-_10 = NaviState
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct NaviNukuAdjustState : public NaviState {
	NaviNukuAdjustState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40
	virtual void resume(Navi*);  // _44
	virtual void restart(Navi*); // _48

	// _00     = VTBL
	// _00-_10 = NaviState
	f32 _10;      // _10
	Vector3f _14; // _14
	u8 _20;       // _20
	Vector3f _24; // _24
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct NaviNukuState : public NaviState {
	NaviNukuState();

	virtual void procAnimMsg(Navi*, MsgAnim*);      // _20
	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual bool invincible(Navi*) { return true; } // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	u16 _10; // _10
	u8 _12;  // _12
	u8 _13;  // _13
	u8 _14;  // _14
	u8 _15;  // _15
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct NaviPartsAccessState : public NaviState {
	NaviPartsAccessState();

	virtual void procAnimMsg(Navi*, MsgAnim*);      // _20
	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual bool invincible(Navi*) { return true; } // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	u8 _10; // _10
};

/**
 * @brief TODO
 *
 * @note Size; 0x14.
 */
struct NaviPelletState : public NaviState {
	NaviPelletState();

	virtual void procAnimMsg(Navi*, MsgAnim*);      // _20
	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual bool invincible(Navi*) { return true; } // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	bool mIsFinished; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NaviPickState : public NaviState {
	NaviPickState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40

	// _00     = VTBL
	// _00-_10 = NaviState
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct NaviPikiZeroState : public NaviState {
	NaviPikiZeroState();

	virtual void procAnimMsg(Navi*, MsgAnim*);      // _20
	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual bool invincible(Navi*) { return true; } // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	u8 _10;  // _10
	u8 _11;  // _11
	u16 _12; // _12
	u32 _14; // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NaviPressedState : public NaviState {
	NaviPressedState();

	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual bool invincible(Navi*) { return true; } // _50

	// _00     = VTBL
	// _00-_10 = NaviState
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct NaviPushPikiState : public NaviState {
	NaviPushPikiState();

	virtual void procCollideMsg(Navi*, MsgCollide*); // _1C
	virtual void procAnimMsg(Navi*, MsgAnim*);       // _20
	virtual void init(Navi*);                        // _38
	virtual void exec(Navi*);                        // _3C
	virtual void cleanup(Navi*);                     // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	int _10; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct NaviPushState : public NaviState {
	NaviPushState();

	virtual void procAnimMsg(Navi*, MsgAnim*);       // _20
	virtual void procOffWallMsg(Navi*, MsgOffWall*); // _2C
	virtual void init(Navi*);                        // _38
	virtual void exec(Navi*);                        // _3C
	virtual void cleanup(Navi*);                     // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	u8 _10; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct NaviReleaseState : public NaviState {
	NaviReleaseState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	u8 _10; // _10, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NaviRopeExitState : public NaviState {
	NaviRopeExitState();

	virtual void procBounceMsg(Navi*, MsgBounce*); // _0C
	virtual void init(Navi*);                      // _38
	virtual void exec(Navi*);                      // _3C
	virtual void cleanup(Navi*);                   // _40

	// _00     = VTBL
	// _00-_10 = NaviState
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NaviRopeState : public NaviState {
	NaviRopeState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40

	// _00     = VTBL
	// _00-_10 = NaviState
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NaviSowState : public NaviState {
	NaviSowState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40

	// _00     = VTBL
	// _00-_10 = NaviState
};

/**
 * @brief TODO
 *
 * @note Size: 0x40.
 */
struct NaviStartingState : public NaviState {
	NaviStartingState();

	virtual void procCollideMsg(Navi*, MsgCollide*); // _1C
	virtual void procAnimMsg(Navi*, MsgAnim*);       // _20
	virtual void init(Navi*);                        // _38
	virtual void exec(Navi*);                        // _3C
	virtual void cleanup(Navi*);                     // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	f32 _10;      // _10
	Vector3f _14; // _14
	Vector3f _20; // _20
	u32 _2C;      // _2C
	u16 _30;      // _30
	u8 _32;       // _32
	Vector3f _34; // _34
};

/**
 * @brief State when navi has puffmin stuck to it.
 *
 * @note Size: 0x24.
 */
struct NaviStuckState : public NaviState {
	NaviStuckState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	Vector3f mPrevStickDir; // _10, last recorded main joystick direction
	f32 mIdleTimer;         // _1C, resets recorded action attempts when this hits 0
	int mActionCount;       // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct NaviThrowState : public NaviState {
	NaviThrowState();

	virtual void procTargetMsg(Navi*, MsgTarget*); // _18
	virtual void procAnimMsg(Navi*, MsgAnim*);     // _20
	virtual void init(Navi*);                      // _38
	virtual void exec(Navi*);                      // _3C
	virtual void cleanup(Navi*);                   // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	u8 _10;    // _10
	u8 _11;    // _11
	Piki* _14; // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct NaviThrowWaitState : public NaviState {
	NaviThrowWaitState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40
	virtual void resume(Navi*);                // _44
	virtual void restart(Navi*);               // _48

	void sortPikis(Navi*);

	// unused/inlined:
	void lockHangPiki(Navi*);

	// _00     = VTBL
	// _00-_10 = NaviState
	Piki* _10; // _10
	Piki* _14; // _14
	int _18;   // _18
	u8 _1C;    // _1C
	u32 _20;   // _20
	f32 _24;   // _24
	f32 _28;   // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct NaviUfoAccessState : public NaviState {
	NaviUfoAccessState();

	virtual void procAnimMsg(Navi*, MsgAnim*);      // _20
	virtual void init(Navi*);                       // _38
	virtual void exec(Navi*);                       // _3C
	virtual void cleanup(Navi*);                    // _40
	virtual bool invincible(Navi*) { return true; } // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	u8 _10; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct NaviUfoState : public NaviState {
	NaviUfoState();

	virtual void procCollideMsg(Navi*, MsgCollide*); // _1C
	virtual void procAnimMsg(Navi*, MsgAnim*);       // _20
	virtual void init(Navi*);                        // _38
	virtual void exec(Navi*);                        // _3C
	virtual void cleanup(Navi*);                     // _40
	virtual bool invincible(Navi*) { return true; }  // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	u16 mState;             // _10
	u16 mRecoveryTimer;     // _12
	Vector3f mLastPosition; // _14
	s8 mPunchCooldownTimer; // _20
	u8 _21;                 // _21
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct NaviWalkState : public NaviState {
	NaviWalkState();

	virtual void procCollideMsg(Navi*, MsgCollide*); // _1C
	virtual void procWallMsg(Navi*, MsgWall*);       // _28
	virtual void procOffWallMsg(Navi*, MsgOffWall*); // _2C
	virtual void init(Navi*);                        // _38
	virtual void exec(Navi*);                        // _3C
	virtual void cleanup(Navi*);                     // _40
	virtual void restart(Navi*);                     // _48

	// _00     = VTBL
	// _00-_10 = NaviState
	Creature* _10; // _10, unknown
	f32 _14;       // _14
	int _18;       // _18
	f32 _1C;       // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NaviWaterState : public NaviState {
	NaviWaterState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40

	// _00     = VTBL
	// _00-_10 = NaviState
};

#endif
