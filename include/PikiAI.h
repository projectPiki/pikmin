#ifndef _PIKIAI_H
#define _PIKIAI_H

#include "types.h"
#include "PaniAnimator.h"
#include "Piki.h"
#include "Receiver.h"
#include "SlotChangeListner.h"
#include "stl/stdio.h"

struct BombGenItem;
struct Bridge;
struct BuildingItem;
struct Suckable;
struct Pebble;
struct RockGen;

namespace zen {
struct particleGenerator;
} // namespace zen

/**
 * @brief TODO
 */
enum ActionResults {
	ACTOUT_Continue = 0,
	ACTOUT_Fail     = 1,
	ACTOUT_Success  = 2,
};

namespace Reaction {
extern char* info[9];
} // namespace Reaction

// clang-format off
DEFINE_ENUM_TYPE(
	PikiAction,

	NOACTION = -1,  // -1
	RandomBoid = 0, // 0
	Watch,          // 1
	Escape,         // 2
	Chase,          // 3
	Goto,           // 4
	PickCreature,   // 5
	PutItem,        // 6
	Formation,      // 7
	Attack,         // 8
	Shoot,          // 9
	Guard,          // 10
	Pullout,        // 11
	PickItem,       // 12
	Decoy,          // 13
	Crowd,          // 14
	Free,           // 15
	Rope,           // 16
	Enter,          // 17
	Exit,           // 18
	BreakWall,      // 19
	Mine,           // 20
	Transport,      // 21
	Kinoko,         // 22
	Bridge,         // 23
	Push,           // 24
	PutBomb,        // 25
	Rescue,         // 26
	Weed,           // 27
	Stone,          // 28
	BoMake,         // 29
	Bou,            // 30
	COUNT,          // 31
);
// clang-format on

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct Action : public Receiver<Piki> {

	/**
	 * @brief TODO
	 */
	struct Initialiser {
		virtual void initialise(Action*) { } // _08 (weak)

		// _00 = VTBL
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct Child {
		Child()
		{
			mAction      = nullptr;
			mInitialiser = nullptr;
		}

		~Child()
		{
			if (mAction) {
				delete mAction;
			}

			if (mInitialiser) {
				delete mInitialiser;
			}
		}

		void initialise(Creature*);

		// TODO: members
		Action* mAction;           // _00
		Initialiser* mInitialiser; // _04
	};

	Action(Piki*, bool);

	virtual void defaultInitialiser() { }                  // _38 (weak)
	virtual void dump() { }                                // _3C (weak)
	virtual void draw(struct Graphics&) { }                // _40 (weak)
	virtual ~Action();                                     // _44
	virtual void init(Creature*);                          // _48
	virtual int exec();                                    // _4C
	virtual void cleanup();                                // _50
	virtual void resume() { }                              // _54 (weak)
	virtual void restart() { }                             // _58 (weak)
	virtual bool resumable() { return false; }             // _5C (weak)
	virtual void getInfo(char* out) { sprintf(out, "-"); } // _60 (weak)

	void procMsg(Msg*);
	void setChildren(int, ...);

	// only DLL inlines:
	char* getName() { return mName; }
	void setName(char* name) { mName = name; }

	// _00 = VTBL
	Child* mChildActions; // _04, array of mChildCount Children
	s16 mCurrActionIdx;   // _08
	s16 mChildCount;      // _0A
	Piki* mPiki;          // _0C
	char* mName;          // _10
};

/**
 * @brief TODO
 */
struct AndAction : public Action {
	AndAction(Piki* piki)
	    : Action(piki, true)
	{
		mOtherCreature = nullptr;
	}

	virtual ~AndAction() { }      // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C

	// _00     = VTBL
	// _00-_14 = Action
	Creature* mOtherCreature; // _14
};

/**
 * @brief TODO
 */
struct OrAction : public Action {
	inline OrAction(); // TODO: probably

	virtual ~OrAction() { }       // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C

	// _00     = VTBL
	// _00-_14 = Action
	Creature* mOtherCreature; // _14
};

/**
 * @brief TODO
 */
struct TopAction : public Action {

	/**
	 * @brief TODO
	 *
	 * @note Size: 0x8.
	 */
	struct MotionListener : public PaniAnimKeyListener {
		MotionListener(TopAction* action)
		    : mAction(action)
		{
		}

		virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

		// _00 = VTBL
		TopAction* mAction; // _04
	};

	/**
	 * @brief TODO
	 */
	struct ObjBore {
		ObjBore();

		int getIndex(int);
		void addBoredom(int, f32);
		void update();

		f32* mBoredomLevels; // _00
		int* mObjectIds;     // _04
		bool* mIsMaxBored;   // _08
		u32 mCurrentCount;   // _0C
		int mMaxCount;       // _10
	};

	/**
	 * @brief TODO
	 */
	struct Boredom {
		Boredom();

		// unused/inlined:
		int getIndex(int);
		f32 getBoredom(int, int);
		void addBoredom(int, int, f32);
		void update();
		void draw2d(Graphics&, int);

		ObjBore* mBoredomCollectors; // _00
		int* mBoredomIds;            // _04
		int mCurrentBoredomCount;    // _08
		int mMaxBoredomCollectors;   // _0C
		int mNextAvailableIndex;     // _10
	};

	TopAction(Piki*);

	virtual void getInfo(char* out) // _60
	{
		mChildActions[mCurrActionIdx].mAction->getInfo(out);
	}
	virtual void draw(Graphics& gfx) // _40
	{
		if (mIsDebugDraw) {
			mChildActions[mCurrActionIdx].mAction->draw(gfx);
		}
	}
	virtual ~TopAction();         // _44
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void resume();        // _54
	virtual void restart();       // _58
	virtual bool resumable();     // _5C

	void abandon(zen::particleGenerator*);

	// unused/inlined:
	void knowledgeCheck();

	Action* getCurrAction() { return (mCurrActionIdx == -1) ? nullptr : mChildActions[mCurrActionIdx].mAction; }

	void startAction(int actionID, Creature* target)
	{
		mCurrActionIdx = actionID;
		mChildActions[mCurrActionIdx].initialise(target);
	}

	// _00     = VTBL
	// _00-_14 = Action
	MotionListener* mListener; // _14
	u8 mIsDebugDraw;           // _18
	bool mIsSuspended;         // _19
	u8 _1A;                    // _1A
	int _1C;                   // _1C
	Creature* _20;             // _20
	int _24;                   // _24
	u32 _28;                   // _28, unknown
	f32 _2C;                   // _2C
	Boredom _30;               // _30
};

/**
 * @brief TODO
 */
struct ActAdjust : public Action {

	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		f32 _04;              // _04, same as _14 in ActAdjust
		int mAdjustTimeLimit; // _08, same as _18 in ActAdjust
	};

	ActAdjust(Piki*);

	virtual ~ActAdjust() { }          // _44 (weak)
	virtual void defaultInitialiser() // _38 (weak)
	{
		_14              = 10.0f;
		mAdjustTimeLimit = 8;
	}
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	f32 _14;              // _14
	int mAdjustTimeLimit; // _18
	Vector3f _1C;         // _1C
	f32 mAdjustTimer;     // _28
	f32 mTurnSpeed;       // _2C
	Vector3f mVelocity;   // _30
	u8 mForceFail;        // _3C
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct ActAttack : public AndAction, public PaniAnimKeyListener {
	ActAttack(Piki*);

	virtual ~ActAttack() { }                             // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void resume();                               // _54
	virtual void restart();                              // _58
	virtual bool resumable();                            // _5C
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	Creature* findTarget();

	// unused/inlined:
	Creature* decideTarget();
	void startLost();

	// _00     = VTBL
	// _00-_18 = AndAction
	// _18     = PaniAnimKeyListener
	u8 _1C;                 // _1C
	u8 _1D;                 // _1D
	u8 _1E;                 // _1E
	u8 _1F;                 // _1F
	Traversable* _20;       // _20, idk what this is but it's something inheriting from this
	SmartPtr<Creature> _24; // _24
	Creature* _28;          // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActBoMake : public Action, public PaniAnimKeyListener {

	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Approach = 0,
		STATE_Work     = 1,
	};

	ActBoMake(Piki*);

	virtual ~ActBoMake() { }                             // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	void initApproach();
	int exeApproach();
	void initWork();
	int exeWork();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u16 mState;             // _18, see StateID enum
	Creature* mBuildObject; // _1C
	u8 _20[0x24 - 0x20];    // _20, unknown
};

/**
 * @brief TODO
 */
struct ActBoreListen : public Action {
	ActBoreListen(Piki*);

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual ~ActBoreListen() { }               // _44
	virtual void init(Creature*);              // _48
	virtual int exec();                        // _4C
	virtual void cleanup();                    // _50

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActBoreOneshot : public Action, virtual PaniAnimKeyListener {
	ActBoreOneshot(Piki*);

	virtual ~ActBoreOneshot() { }                        // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void finish();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	bool mIsAnimFinished; // _18
	                      // _1C-_24 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActBoreRest : public Action, virtual PaniAnimKeyListener {
	ActBoreRest(Piki*);

	virtual ~ActBoreRest() { }                           // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void sitDown();

	// unused/inlined:
	void standUp();

	void finishRest() { _18 = 1; }

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	u8 _18;  // _18
	int _1C; // _1C
	f32 _20; // _20, unknown
	u8 _24;  // _24
	u8 _25;  // _25
	         // _28-_30 = PaniAnimKeyListener
};

/**
 * @brief TODO
 */
struct ActBoreSelect : public Action {

	/**
	 * @brief TODO
	 */
	enum ChildID {
		CHILD_NULL        = -1,
		CHILD_Watch       = 0,
		CHILD_BoreTalk    = 1,
		CHILD_BoreOneshot = 2,
		CHILD_BoreRest    = 3,
		CHILD_COUNT, // 4
	};

	ActBoreSelect(Piki*);

	virtual void procTargetMsg(Piki*, MsgTarget*); // _18
	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual ~ActBoreSelect() { }                   // _44
	virtual void init(Creature*);                  // _48
	virtual int exec();                            // _4C
	virtual void cleanup();                        // _50

	void stop();
	void determine();

	// _00     = VTBL
	// _00-_14 = Action
	f32 mActionTimer;          // _14
	bool mIsTimerActive;       // _18
	bool mIsChildActionActive; // _19
	u8 _1A;                    // _1A
	f32 _1C;                   // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActBoreTalk : public Action, virtual PaniAnimKeyListener {
	ActBoreTalk(Piki*);

	virtual ~ActBoreTalk() { }                           // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void startTalk();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	int _18;              // _18
	Creature* mTarget;    // _1C
	f32 _20;              // _20
	bool mIsAnimFinished; // _24
	                      // _28-_30 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x34.
 */
struct ActBou : public Action {

	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_GotoLeg = 0,
		STATE_Climb   = 1,
	};

	ActBou(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual ~ActBou() { }                            // _44 (weak)
	virtual void init(Creature*);                    // _48
	virtual int exec();                              // _4C
	virtual void cleanup();                          // _50

	int gotoLeg();
	int climb();

	// _00     = VTBL
	// _00-_14 = Action
	u16 mState;               // _14
	s16 mTimeoutCounter;      // _16
	Vector3f mClimbDirection; // _18
	Creature* mTargetStick;   // _24
	Vector3f mLastPosition;   // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x34.
 */
struct ActBreakWall : public Action, public PaniAnimKeyListener {

	/**
	 * @brief TODO
	 *
	 * @note Size: 0x34.
	 */
	enum StateID {
		STATE_GotoWall  = 0,
		STATE_BreakWall = 1,
	};

	ActBreakWall(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*);     // _1C
	virtual ~ActBreakWall() { }                          // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	int gotoWall();
	void initBreakWall();
	void startWorkMotion();
	int breakWall();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	BuildingItem* mWall; // _18
	u16 mState;          // _1C
	Vector3f _20;        // _20
	int _2C;             // _2C, unknown, same as gameflow._300
	u8 _30;              // _30
	u8 _31;              // _31
	u8 _32;              // _32
};

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct ActBridge : public Action, virtual PaniAnimKeyListener {

	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Approach = 0,
		STATE_Detour   = 1,
		STATE_Go       = 2,
		STATE_Climb    = 3,
		STATE_Work     = 4,
	};

	ActBridge(Piki*);

	virtual void procWallMsg(Piki*, MsgWall*);           // _28
	virtual void dump();                                 // _3C
	virtual ~ActBridge() { }                             // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	int newExeApproach();
	void newInitGo();
	int newExeGo();
	void newInitWork();
	int newExeWork();

	// unused/inlined:
	bool collideBridgeSurface();
	bool collideBridgeBlocker();
	void initDetour();
	int exeDetour();
	void initClimb();
	int exeClimb();
	void initApproach();
	int exeApproach();
	void initGo();
	int exeGo();
	void initWork();
	int exeWork();
	void doWork(int);
	void newInitApproach();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	Bridge* mBridge;            // _18, unknown
	u16 mState;                 // _1C
	int _20;                    // _20, unknown - same as _300 in gameflow
	int _24;                    // _24
	u16 mCollisionCount;        // _28
	u16 _2A;                    // _2A
	f32 _2C;                    // _2C
	s16 mStageIdx;              // _30
	u8 _32;                     // _32
	u8 _33;                     // _33
	Vector3f _34;               // _34
	Vector3f mClimbingVelocity; // _40
	u8 mActionCounter;          // _4C
	u8 _4D;                     // _4D
	                            // _50-_58 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct ActChase : public Action {

	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
	};

	ActChase(Piki*);

	virtual ~ActChase() { }       // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	SmartPtr<Creature> mTarget; // _14
	f32 mChaseTimer;            // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x88.
 */
struct ActCrowd : public Action, virtual SlotChangeListner {
	ActCrowd(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual void procAnimMsg(Piki*, MsgAnim*);       // _20
	virtual void procWallMsg(Piki*, MsgWall*);       // _28
	virtual ~ActCrowd();                             // _44
	virtual void init(Creature*);                    // _48
	virtual int exec();                              // _4C
	virtual void cleanup();                          // _50
	virtual bool resumable();                        // _5C
	virtual void inform(int);                        // _64

	void startSort();
	void startZawatuki();
	void finishZawatuki();

	// unused/inlined:
	void initRouteMove();
	void exeRouteMove();
	void setFormed();
	void startBoredom();
	void startTalk();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = SlotChangeListner ptr
	u8 _18[0x2C - 0x18]; // _18, unknown
	u16 _2C;             // _2C, "md"?
	u16 _2E;             // _2E, "st"?
	u8 _30[0x58 - 0x30]; // _30, unknown
	int mCPlateSlotID;   // _58
	u8 _5C[0x64 - 0x5C]; // _5C, unknown
	u8 _64;              // _64, "koke"?
	u8 _65[0x7C - 0x65]; // _65, unknown
	u8 _7C;              // _7C
	u8 _7D;              // _7D, "wait"?
	u8 _7E;              // _7E
	u8 _7F;              // _7F, "route"?
	                     // _80-_88 = SlotChangeListner
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct ActDecoy : public Action, public PaniAnimKeyListener {
	ActDecoy(Piki*);

	virtual ~ActDecoy();                                 // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70 (weak)

	Creature* findTeki();

	// unused/inlined:
	Creature* update();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18[0x20 - 0x18]; // _18, unknown
};

/**
 * @brief TODO
 */
struct ActDeliver : public AndAction {

	/**
	 * @brief TODO
	 */
	enum ChildID {
		CHILD_NULL         = -1,
		CHILD_PickCreature = 0,
		CHILD_Goto         = 1,
		CHILD_Put          = 2,
		CHILD_COUNT, // 3
	};

	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		Creature* mObject; // _04
	};

	ActDeliver(Piki*);

	virtual ~ActDeliver() { }                              // _44 (weak)
	virtual void defaultInitialiser() { mObject.clear(); } // _38 (weak)
	virtual void init(Creature*);                          // _48
	virtual void cleanup() { mObject.reset(); }            // _50 (weak)

	// _00     = VTBL
	// _00-_18 = AndAction
	SmartPtr<Creature> mObject; // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActEnter : public Action {
	ActEnter(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual ~ActEnter();                             // _44
	virtual void init(Creature*);                    // _48
	virtual int exec();                              // _4C
	virtual void cleanup();                          // _50

	void findLeg();
	int gotoLeg();
	int climb();

	// unused/inlined:
	int routeMove();

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x30 - 0x14]; // _14, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActEscape : public Action {

	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Normal = 0,
		STATE_Avoid  = 1,
	};

	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
	};

	ActEscape(Piki*);

	virtual ~ActEscape() { }      // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50
	virtual void getInfo(char*);  // _60

	// _00     = VTBL
	// _00-_14 = Action
	SmartPtr<Creature> mTarget; // _14
	f32 mEscapeTimer;           // _18
	u8 _1C[0x4];                // _1C, unknown
	int mState;                 // _20
	Vector3f mAvoidDirection;   // _24
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActExit : public Action {
	ActExit(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual ~ActExit() { }                           // _44
	virtual void init(Creature*);                    // _48
	virtual int exec();                              // _4C
	virtual void cleanup();                          // _50

	// _00     = VTBL
	// _00-_14 = Action
	Vector3f mPrevPosition; // _14
	u8 mHasCollided;        // _20
};

/**
 * @brief TODO
 */
struct ActFlower : public Action, public PaniAnimKeyListener {
	ActFlower(Piki*);

	virtual ~ActFlower();                                // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64 (weak)

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x34.
 */
struct ActFormation : public Action, public PaniAnimKeyListener {
	ActFormation(Piki*);

	virtual ~ActFormation();                             // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70 (weak)

	void getFormPoint();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18;              // _18
	u8 _19[0x34 - 0x19]; // _19, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x50.
 */
struct ActFree : public Action, virtual PaniAnimKeyListener {
	ActFree(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*);     // _1C
	virtual ~ActFree();                                  // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual bool resumable();                            // _5C
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void initBoid(struct Vector3f&, f32);
	void exeBoid();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	u8 _18[0x48 - 0x18]; // _18
	                     // _48-_50 = PaniAnimKeyListener
};

/**
 * @brief TODO
 */
struct ActFreeSelect : public Action {

	/**
	 * @brief TODO
	 */
	enum ChildID {
		CHILD_NULL        = -1,
		CHILD_Watch       = 0,
		CHILD_BoreTalk    = 1,
		CHILD_BoreOneshot = 2,
		CHILD_BoreRest    = 3,
		CHILD_COUNT, // 4
	};

	ActFreeSelect(Piki*);

	virtual void procTargetMsg(Piki*, MsgTarget*); // _18
	virtual ~ActFreeSelect() { }                   // _44
	virtual void init(Creature*);                  // _48
	virtual int exec();                            // _4C
	virtual void cleanup();                        // _50

	void finishRest();
	void determine();

	// _00     = VTBL
	// _00-_14 = Action
	f32 mActionTimer;             // _14, timer?
	volatile bool mIsTimerActive; // _18
	bool mIsChildActionActive;    // _19
	u8 _1A;                       // _1A
	f32 _1C;                      // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActGoto : public Action {

	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		Initialiser(f32 p1, f32 p2, Creature* p3)
		{
			_04 = p3;
			_08 = p1;
			_0C = p2;
		}

		virtual void initialise(Action*); // _08

		// _00 = VTBL
		Creature* _04; // _04
		f32 _08;       // _08
		f32 _0C;       // _0C
	};

	ActGoto(Piki*);

	virtual ~ActGoto() { }            // _44 (weak)
	virtual void defaultInitialiser() // _38 (weak)
	{
		_18 = 0.0f;
		_14 = 9.0f;
	}
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	f32 _14;                // _14
	f32 _18;                // _18
	SmartPtr<Creature> _1C; // _1C
	f32 _20;                // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x4C.
 */
struct ActGuard : public Action {
	ActGuard(Piki*);

	virtual void dump();          // _3C
	virtual ~ActGuard();          // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	Piki* findFriend();
	int checkLoop(Piki*);
	Piki* findFriend(int);
	void setGoal();
	Piki* getLeft(Piki*);
	Piki* getRight(Piki*);
	bool setLeft();
	bool setRight();

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x4C - 0x14]; // _14, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActJumpAttack : public Action, public PaniAnimKeyListener {
	ActJumpAttack(Piki*);

	virtual void procBounceMsg(Piki*, MsgBounce*);       // _0C
	virtual void procStickMsg(Piki*, MsgStick*);         // _10
	virtual void procCollideMsg(Piki*, MsgCollide*);     // _1C
	virtual ~ActJumpAttack() { }                         // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	void attackHit();
	void doClimb();

	// unused/inlined:
	Vector3f getAttackPos();
	f32 getAttackSize();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	int _18;                // _18
	u8 _1C[0x20 - 0x1C];    // _1C, unknown
	int _20;                // _20
	SmartPtr<Creature> _24; // _24
	CollPart* _28;          // _28
	u8 _2C;                 // _2C
	u8 _2D;                 // _2D
};

/**
 * @brief TODO
 *
 * @note Size: 0x38.
 */
struct ActKinoko : public Action, virtual PaniAnimKeyListener {

	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Boid   = 0,
		STATE_Attack = 1,
		STATE_Jump   = 2,
		STATE_Stick  = 3,
	};

	ActKinoko(Piki*);

	virtual ~ActKinoko() { }                             // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	int exeStick();
	int exeJump();
	void initAttack();
	int exeAttack();
	void initBoid();
	int exeBoid();

	// unused/inlined:
	void initStick();
	void initJump();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	SmartPtr<Creature> _18; // _18
	int mState;             // _1C, unknown
	f32 _20;                // _20, unknown
	Vector3f _24;           // _24
	                        // _30-_38 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActMine : public Action, virtual PaniAnimKeyListener {

	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Go    = 0,
		STATE_Mine  = 1,
		STATE_Watch = 2,
	};

	ActMine(Piki*);

	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual ~ActMine() { }                               // _44 (weak)

	void initWatch();
	int exeMine();

	// unused/inlined:
	int exeWatch();
	int exeGo();
	void initMine();
	void initGo();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	BombGenItem* mBombGen;   // _18
	u16 mState;              // _1C
	u32 _20;                 // _20, unknown
	bool mIsMineActionReady; // _24
	                         // _28-_30 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct ActPick : public Action, public PaniAnimKeyListener {

	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
		Creature* mObject; // _04
	};

	ActPick(Piki*);

	virtual ~ActPick() { }                               // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70 (weak)

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	SmartPtr<Creature> mObject; // _18, thing to be picked up
	u8 _1C;                     // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct ActPickCreature : public AndAction {

	/**
	 * @brief TODO
	 */
	enum ChildID {
		CHILD_NULL = -1,
		CHILD_Goto = 0,
		CHILD_Pick = 1,
		CHILD_COUNT, // 2
	};

	/**
	 * @brief TODO
	 */
	struct InitGoto {
		void initialise(Action*, Action*);
		// TODO: members
	};

	ActPickCreature(Piki*);

	virtual ~ActPickCreature() { } // _44 (weak)
	virtual void init(Creature*);  // _48

	// _00     = VTBL
	// _00-_18 = AndAction
	SmartPtr<Creature> _18; // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct ActPickItem : public AndAction {
	ActPickItem(Piki*);

	virtual ~ActPickItem();       // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	Creature* findItem();

	// _00     = VTBL
	// _00-_18 = AndAction
	u8 _18[0x1C - 0x18]; // _18, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct ActPullout : public Action {
	ActPullout(Piki*);

	virtual ~ActPullout();        // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x1C - 0x14]; // _14, unknown
};

/**
 * @brief TODO
 */
struct ActPulloutCreature : public Action, public PaniAnimKeyListener {
	ActPulloutCreature(Piki*);

	virtual ~ActPulloutCreature();                       // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70 (weak)

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x50.
 */
struct ActPush : public Action, virtual PaniAnimKeyListener {
	ActPush(Piki*);

	virtual ~ActPush();                                  // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64 (weak)

	int exeApproach();
	void initGo();
	int exeGo();

	// unused/inlined:
	bool collideRockSurface();
	void initApproach();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18[0x48 - 0x18]; // _18, unknown
	                     // _48-_50 = PaniAnimKeyListener
};

/**
 * @brief TODO
 */
struct ActPut : public Action {

	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
	};

	ActPut(Piki*);

	virtual ~ActPut() { }         // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	f32 mFailCountdownTimer; // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActPutBomb : public Action, virtual PaniAnimKeyListener {
	ActPutBomb(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*);     // _1C
	virtual ~ActPutBomb();                               // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	Creature* findTeki();
	void initSet();
	int exeSet();
	void warnPikis();
	void initAim();
	int exeAim();
	void initWait();
	void initThrow();
	void initPut();
	int exeThrow();

	// unused/inlined:
	int exeWait();
	int exePut();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18[0x28 - 0x18]; // _18, unknown
	                     // _28-_30 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActPutItem : public Action {
	ActPutItem(Piki*);

	virtual ~ActPutItem();        // _44
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	void findPos();
	bool findAdjacent(Creature*);

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x24 - 0x14]; // _14, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct ActRandomBoid : public Action {

	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct AnimListener : public PaniAnimKeyListener {
		virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

		// _00 = VTBL
		// TODO: members
	};

	ActRandomBoid(Piki*);

	virtual ~ActRandomBoid();     // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50
	virtual void getInfo(char*);  // _60

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x28 - 0x14]; // _14, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x3C.
 */
struct ActRescue : public Action, virtual PaniAnimKeyListener {
	ActRescue(Piki*);

	virtual ~ActRescue();                                // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void initApproach();
	int exeApproach();
	void initRescue();
	int exeRescue();
	void initGo();
	int exeGo();
	void initThrow();
	int exeThrow();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	u8 _18[0x34 - 0x18]; // _18, unknown
	                     // _34-_3C = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActRope : public Action {
	ActRope(Piki*);

	virtual ~ActRope() { }        // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	f32 mSpeed;              // _14
	Vector3f mRopeDirection; // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct ActShoot : public AndAction {
	ActShoot(Piki*);

	virtual ~ActShoot();          // _44
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	Creature* findTarget();

	// unused/inlined:
	Creature* decideTarget();

	// _00     = VTBL
	// _00-_18 = AndAction
	u8 _18[0x28 - 0x18]; // _18, unknown
};

/**
 * @brief TODO
 */
struct ActShootCreature : public Action, public PaniAnimKeyListener {
	ActShootCreature(Piki*);

	virtual ~ActShootCreature();                         // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct ActStone : public Action, public PaniAnimKeyListener {

#define STONE_NECTAR_CHANCE (0.08f)

	/**
	 * @brief TODO
	 */
	enum State {
		STATE_Approach = 0,
		STATE_Adjust   = 1,
		STATE_Attack   = 2,
	};

	ActStone(Piki*);

	virtual ~ActStone() { }                              // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	void initApproach();
	int exeApproach();
	void initAdjust();
	int exeAdjust();
	void initAttack();
	int exeAttack();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u16 mState;          // _18
	u8 _1A[0x20 - 0x1A]; // _1A, unknown
	Pebble* mCurrPebble; // _20, unknown
	RockGen* mRockGen;   // _24
	u8 mIsAttackReady;   // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0xC0.
 */
struct ActTransport : public Action, virtual PaniAnimKeyListener {

	/**
	 * @brief TODO
	 */
	enum State {
		STATE_Go   = 0,
		STATE_Wait = 1,
		STATE_Lift = 2,
		STATE_Move = 3,
		STATE_Guru = 4,
		STATE_Goal = 5,
		STATE_Put  = 6,
		STATE_Jump = 7,
	};

	ActTransport(Piki*);

	virtual void draw(Graphics&);                        // _40
	virtual ~ActTransport() { }                          // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void turnOver();
	bool isStickLeader();
	f32 getCarriers();
	Pellet* findPellet();
	void setSlotIndex();
	int execJump();
	bool gotoLiftPos();
	void doLift();
	bool useWaterRoute();
	int moveGuruGuru();
	void decideGoal(Creature*);
	Vector3f crGetPoint(int);
	bool crPointOpen(int);
	void crInit();
	void crMakeRefs();
	void findObstacle();
	bool crMove();
	int moveToWayPoint();

	// unused/inlined:
	void initWait();
	int exeWait();
	int getNumStickers();
	int calcNumStickers();
	void initJump();
	f32 crGetRadius(int);

	// not in the DLL, but necessary for doLift
	inline BOOL doLandOnly() { return useWaterRoute() ? FALSE : TRUE; }

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	SmartPtr<Pellet> mPellet;      // _18
	u16 mState;                    // _1C
	OdoMeter mOdometer;            // _20
	Vector3f mMoveDir;             // _30, calc'd from CRSplineTangent
	u16 mNumRoutePoints;           // _3C
	u8 mJumpRetryTimer;            // _3E
	u16 mStateProgress;            // _40
	int mNextPathIndex;            // _44
	u32 _48;                       // _48, unknown
	Vector3f mSplineControlPts[4]; // _4C
	Vector3f mRouteStartPos;       // _7C
	u8 mPathType;                  // _88
	int mSlotIndex;                // _8C
	Vector3f mSpinStartPosition;   // _90
	u8 mFinishPutting;             // _9C
	u8 mIsLiftActionDone;          // _9D
	int mLiftRetryCount;           // _A0
	f32 mWaitTimer;                // _A4
	int mPathIndex;                // _A8
	int mGoalWPIndex;              // _AC
	Suckable* mGoal;               // _B0, either GoalItem* or UfoItem*, depending
	u8 mCanCarry;                  // _B4
	                               // _B8-_C0 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct ActWatch : public Action {

	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct AnimListener : public PaniAnimKeyListener {
		AnimListener(ActWatch* owner, Piki* piki)
		{
			mOwnerAction = owner;
			mActor       = piki;
		}

		virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

		// _00 = VTBL
		ActWatch* mOwnerAction; // _04
		Piki* mActor;           // _08
	};

	ActWatch(Piki* piki);

	virtual ~ActWatch() { }       // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50
	virtual void getInfo(char*);  // _60

	// _00     = VTBL
	// _00-_14 = Action
	SmartPtr<Creature> mTarget; // _14
	int mWatchRetryTimer;       // _18
	AnimListener* mListener;    // _1C
	Vector3f mTargetPosition;   // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct ActWeed : public Action, public PaniAnimKeyListener {
	ActWeed(Piki*);

	virtual ~ActWeed();                                  // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	void initApproach();
	int exeApproach();
	void initAdjust();
	int exeAdjust();
	void initNuking();
	int exeNuking();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18[0x2C - 0x18]; // _18, unknown
};

/**
 * @brief Almost completely stripped, uniqueInstance gets set to nullptr in pikiMgr.
 */
struct AiTable {

	/**
	 * @brief Completely stripped. Static member shows up stripped in map.
	 */
	struct Row {
		static int numInputs;

		// TODO: members
	};

	static AiTable* uniqueInstance;

	static void init() { uniqueInstance = nullptr; }

	// TODO: members
};

#endif
