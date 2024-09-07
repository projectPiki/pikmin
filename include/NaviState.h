#ifndef _NAVISTATE_H
#define _NAVISTATE_H

#include "types.h"
#include "Win.h"
#include "Navi.h"
#include "StateMachine.h"
#include "Vector.h"

struct NaviState;

/**
 * @brief TODO
 */
enum NaviStateID {
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
struct NaviStateMachine : public StateMachine<Navi> {
	virtual void init(Navi*); // _08

	NaviState* getNaviState(Navi*);

	// _00     = VTBL
	// _00-_1C = StateMachine
	// TODO: members
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
	// _00-_0C = AState
	const char* mName; // _0C, unused?
};

/**
 * @brief TODO
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviBuryState : public NaviState {
	NaviBuryState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40
	virtual bool invincible(Navi*);            // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	Vector3f _10; // _10
};

/**
 * @brief TODO
 */
struct NaviClearState : public NaviState {
	NaviClearState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviContainerState : public NaviState, virtual public ContainerWin::Listener, virtual public GmWin::CloseListener {
	NaviContainerState();

	virtual void init(Navi*);       // _38
	virtual void exec(Navi*);       // _3C
	virtual void cleanup(Navi*);    // _40
	virtual bool invincible(Navi*); // _50
	virtual void informWin(int);    // _54
	virtual void onCloseWindow();   // _58

	void enterPikis(Navi*, int);
	void exitPikis(Navi*, int);

	// _00     = VTBL
	// _00-_10 = NaviState
	// _10     = ContainerWin::Listener ptr
	// _14     = GmWin::CloseListener ptr
	u8 _18[0x8]; // _18, TODO: members
	             // ContainerWin::Listener
	             // GmWin::CloseListener
};

/**
 * @brief TODO
 */
struct NaviDeadState : public NaviState {
	NaviDeadState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40
	virtual void restart(Navi*);               // _48
	virtual bool invincible(Navi*);            // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviDemoInfState : public NaviState {
	NaviDemoInfState();

	virtual void init(Navi*);       // _38
	virtual void exec(Navi*);       // _3C
	virtual void cleanup(Navi*);    // _40
	virtual bool invincible(Navi*); // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
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
		// _00-_0C = AState
		const char* mName; // _0C, unused?
	};

	/**
	 * @brief TODO
	 */
	struct GoState : public DemoState {
		inline GoState(); // probably

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
	struct LookState : public DemoState {
		inline LookState(); // probably

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
		inline SitState(); // probably

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
		inline WaitState(); // probably

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
		inline WhistleState(); // probably

		virtual void procAnimMsg(NaviDemoSunsetState*, MsgAnim*); // _20
		virtual void init(NaviDemoSunsetState*);                  // _38
		virtual void exec(NaviDemoSunsetState*);                  // _3C
		virtual void cleanup(NaviDemoSunsetState*);               // _40

		void enterAllPikis(NaviDemoSunsetState*);

		// _00     = VTBL
		// _00-_0C = AState
		// TODO: members
	};

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40

	void setActors(Navi*);

	// _00     = VTBL
	// _00-_10 = NaviState
	Navi* mNavi;                     // _10
	Vector3f _14;                    // _14
	Vector3f _20;                    // _20
	u8 _2C[0xC];                     // _2C, unknown
	DemoStateMachine* mStateMachine; // _38
};

/**
 * @brief TODO
 */
struct NaviDemoWaitState : public NaviState {
	NaviDemoWaitState();

	virtual void init(Navi*);       // _38
	virtual void exec(Navi*);       // _3C
	virtual void cleanup(Navi*);    // _40
	virtual bool invincible(Navi*); // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	Vector3f _10; // _10
};

/**
 * @brief TODO
 */
struct NaviFlickState : public NaviState {
	NaviFlickState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40
	virtual bool invincible(Navi*);            // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviFunbariState : public NaviState {
	NaviFunbariState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviGeyzerState : public NaviState {
	NaviGeyzerState();

	virtual void procBounceMsg(Navi*, MsgBounce*); // _0C
	virtual void procAnimMsg(Navi*, MsgAnim*);     // _20
	virtual void init(Navi*);                      // _38
	virtual void exec(Navi*);                      // _3C
	virtual void cleanup(Navi*);                   // _40
	virtual bool invincible(Navi*);                // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	u8 _10[0x10]; // _10, unknown
	Vector3f _20; // _20
};

/**
 * @brief TODO
 */
struct NaviIdleState : public NaviState {
	NaviIdleState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviIroIroState : public NaviState {
	NaviIroIroState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviLockState : public NaviState {
	NaviLockState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
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
	u8 _10[0x4];  // _10, unknown
	Vector3f _14; // _14
	u8 _20[0x4];  // _20, unknown
	Vector3f _24; // _24
};

/**
 * @brief TODO
 */
struct NaviNukuState : public NaviState {
	NaviNukuState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40
	virtual bool invincible(Navi*);            // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviPartsAccessState : public NaviState {
	NaviPartsAccessState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40
	virtual bool invincible(Navi*);            // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviPelletState : public NaviState {
	NaviPelletState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40
	virtual bool invincible(Navi*);            // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviPickState : public NaviState {
	NaviPickState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviPikiZeroState : public NaviState {
	NaviPikiZeroState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40
	virtual bool invincible(Navi*);            // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviPressedState : public NaviState {
	NaviPressedState();

	virtual void init(Navi*);       // _38
	virtual void exec(Navi*);       // _3C
	virtual void cleanup(Navi*);    // _40
	virtual bool invincible(Navi*); // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
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
	// TODO: members
};

/**
 * @brief TODO
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviReleaseState : public NaviState {
	NaviReleaseState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviRopeExitState : public NaviState {
	NaviRopeExitState();

	virtual void procBounceMsg(Navi*, MsgBounce*); // _0C
	virtual void init(Navi*);                      // _38
	virtual void exec(Navi*);                      // _3C
	virtual void cleanup(Navi*);                   // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviRopeState : public NaviState {
	NaviRopeState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviSowState : public NaviState {
	NaviSowState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
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
	u8 _10[0x4];  // _10, unknown
	Vector3f _14; // _14
	Vector3f _20; // _20
	u8 _2C[0x8];  // _2C, unknown
	Vector3f _34; // _34
};

/**
 * @brief TODO
 */
struct NaviStuckState : public NaviState {
	NaviStuckState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	Vector3f _10; // _10
};

/**
 * @brief TODO
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
	// TODO: members
};

/**
 * @brief TODO
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviUfoAccessState : public NaviState {
	NaviUfoAccessState();

	virtual void procAnimMsg(Navi*, MsgAnim*); // _20
	virtual void init(Navi*);                  // _38
	virtual void exec(Navi*);                  // _3C
	virtual void cleanup(Navi*);               // _40
	virtual bool invincible(Navi*);            // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviUfoState : public NaviState {
	NaviUfoState();

	virtual void procCollideMsg(Navi*, MsgCollide*); // _1C
	virtual void procAnimMsg(Navi*, MsgAnim*);       // _20
	virtual void init(Navi*);                        // _38
	virtual void exec(Navi*);                        // _3C
	virtual void cleanup(Navi*);                     // _40
	virtual bool invincible(Navi*);                  // _50

	// _00     = VTBL
	// _00-_10 = NaviState
	u8 _10[0x4];  // _10, unknown
	Vector3f _14; // _14
};

/**
 * @brief TODO
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviWaterState : public NaviState {
	NaviWaterState();

	virtual void init(Navi*);    // _38
	virtual void exec(Navi*);    // _3C
	virtual void cleanup(Navi*); // _40

	// _00     = VTBL
	// _00-_10 = NaviState
	// TODO: members
};

#endif
