#ifndef _PIKIAI_H
#define _PIKIAI_H

#include "PaniAnimator.h"
#include "Piki.h"
#include "Receiver.h"
#include "SlotChangeListner.h"
#include "types.h"
#include <stdio.h>

struct BombGenItem;
struct Bridge;
struct BuildingItem;
struct Suckable;
struct HinderRock;
struct Pebble;
struct RockGen;
struct Grass;
struct CPlate;
struct GrassGen;
struct GoalItem;
struct FormationMgr;

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

struct Reaction {
	struct Info { }; // TODO: The ILK says this exists.

	static immut char* info[9];
};

BEGIN_ENUM_TYPE(PikiAction)
enum {
	NOACTION   = -1, // -1
	RandomBoid = 0,  // 0
	Watch,           // 1
	Escape,          // 2
	Chase,           // 3
	Goto,            // 4
	PickCreature,    // 5
	PutItem,         // 6
	Formation,       // 7
	Attack,          // 8
	Shoot,           // 9
	Guard,           // 10
	Pullout,         // 11
	PickItem,        // 12
	Decoy,           // 13
	Crowd,           // 14
	Free,            // 15
	Rope,            // 16
	Enter,           // 17
	Exit,            // 18
	BreakWall,       // 19
	Mine,            // 20
	Transport,       // 21
	Kinoko,          // 22
	Bridge,          // 23
	Push,            // 24
	PutBomb,         // 25
	Rescue,          // 26
	Weed,            // 27
	Stone,           // 28
	BoMake,          // 29
	Bou,             // 30
	COUNT,           // 31
} END_ENUM_TYPE;

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct Action : public Receiver<Piki> {
public:
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
	virtual void draw(Graphics&) { }                       // _40 (weak)
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
	immut char* getName() { return mName; }
	void setName(immut char* name) { mName = name; }

	// _00 = VTBL
	Child* mChildActions; // _04, array of mChildCount Children
	s16 mCurrActionIdx;   // _08
	s16 mChildCount;      // _0A
	Piki* mPiki;          // _0C
	immut char* mName;    // _10
};

/**
 * @brief TODO
 */
struct AndAction : public Action {
public:
	AndAction(Piki* piki)
	    : Action(piki, true)
	{
		mOtherCreature = nullptr;
	}

	virtual ~AndAction() { }      // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C

protected:
	// _00     = VTBL
	// _00-_14 = Action
	Creature* mOtherCreature; // _14
};

/**
 * @brief TODO
 */
struct OrAction : public Action {
public:
	inline OrAction(); // TODO: probably

	virtual ~OrAction() { }       // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C

protected:
	// _00     = VTBL
	// _00-_14 = Action
	Creature* mOtherCreature; // _14
};

/**
 * @brief TODO
 */
struct TopAction : public Action {
	// Another encapsulation fail...  Write a getter for `mIsSuspended`, Kando!
	friend struct Piki;
	friend struct PikiSwallowedState;

public:
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

		virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _08

		// _00 = VTBL
		TopAction* mAction; // _04
	};
	friend struct MotionListener;

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

	Action* getCurrAction() { return (mCurrActionIdx == PikiAction::NOACTION) ? nullptr : mChildActions[mCurrActionIdx].mAction; }

	void startAction(int actionID, Creature* target)
	{
		mCurrActionIdx = actionID;
		mChildActions[mCurrActionIdx].initialise(target);
	}

protected:
	void knowledgeCheck();

	// _00     = VTBL
	// _00-_14 = Action
	MotionListener* mListener; // _14
	bool mIsDebugDraw;         // _18
	bool mIsSuspended;         // _19
	bool mIsAnimating;         // _1A
	int _1C;                   // _1C
	Creature* mTarget;         // _20
	int _24;                   // _24
	u32 _28;                   // _28, unknown
	f32 _2C;                   // _2C
	Boredom _30;               // _30
};

/**
 * @brief TODO
 */
struct ActAdjust : public Action {
public:
	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		f32 mAdjustDistance;  // _04, same as _14 in ActAdjust
		int mAdjustTimeLimit; // _08, same as _18 in ActAdjust
	};
	friend struct Initialiser;

	ActAdjust(Piki*);

	virtual ~ActAdjust() { }          // _44 (weak)
	virtual void defaultInitialiser() // _38 (weak)
	{
		mAdjustDistance  = 10.0f;
		mAdjustTimeLimit = 8;
	}
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

protected:
	// _00     = VTBL
	// _00-_14 = Action
	f32 mAdjustDistance;      // _14
	int mAdjustTimeLimit;     // _18
	Vector3f mTargetPosition; // _1C
	f32 mAdjustTimer;         // _28
	f32 mTurnSpeed;           // _2C
	Vector3f mVelocity;       // _30
	bool mForceFail;          // _3C
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct ActAttack : public AndAction, public PaniAnimKeyListener {
public:
	/**
	 * @brief TODO
	 */
	enum ChildID {
		CHILD_NULL       = -1,
		CHILD_JumpAttack = 0,
		CHILD_COUNT, // 1
	};

	ActAttack(Piki*);

	virtual ~ActAttack() { }                                   // _44
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void resume();                                     // _54
	virtual void restart();                                    // _58
	virtual bool resumable();                                  // _5C
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _70

protected:
	void startLost();
	Creature* findTarget();
	Creature* decideTarget();

	// _00     = VTBL
	// _00-_18 = AndAction
	// _18     = PaniAnimKeyListener
	bool mHasLost;             // _1C
	bool mIsAttackFinished;    // _1D
	bool mIsCriticalHit;       // _1E
	bool mTargetIsPlayer;      // _1F
	Traversable* _20;          // _20, idk what this is but it's something inheriting from this
	SmartPtr<Creature> mOther; // _24
	Creature* mPlayerObject;   // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActBoMake : public Action, private PaniAnimKeyListener {
public:
	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Approach = 0,
		STATE_Work     = 1,
	};

	ActBoMake(Piki*);

	virtual ~ActBoMake() { }                                   // _44
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _70

	void initApproach();
	int exeApproach();
	void initWork();
	int exeWork();

protected:
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
public:
	ActBoreListen(Piki*);

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual ~ActBoreListen() { }               // _44
	virtual void init(Creature*);              // _48
	virtual int exec();                        // _4C
	virtual void cleanup();                    // _50

protected:
	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActBoreOneshot : public Action, virtual PaniAnimKeyListener {
public:
	ActBoreOneshot(Piki*);

	virtual ~ActBoreOneshot() { }                              // _44
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _64

	void finish();

protected:
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
public:
	ActBoreRest(Piki*);

	virtual ~ActBoreRest() { }                                 // _44
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _64

	void sitDown();

	// unused/inlined:
	void standUp();

	void finishRest() { mIsFinished = true; }

protected:
	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	bool mIsFinished;     // _18
	int mRestState;       // _1C
	f32 mRestTimer;       // _20, unknown
	bool mIsAnimFinished; // _24
	bool mForceComplete;  // _25
	                      // _28-_30 = PaniAnimKeyListener
};

/**
 * @brief TODO
 */
struct ActBoreSelect : public Action {
public:
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

protected:
	void determine();

	// _00     = VTBL
	// _00-_14 = Action
	f32 mActionTimer;          // _14
	bool mIsTimerActive;       // _18
	bool mIsChildActionActive; // _19
	bool mStop;                // _1A
	f32 _1C;                   // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActBoreTalk : public Action, virtual PaniAnimKeyListener {
	// `mIsLookHandledElsewhere` and `mTarget` are altered by these two.
	friend struct ActFreeSelect;
	friend struct ActBoreSelect;

public:
	ActBoreTalk(Piki*);

	virtual ~ActBoreTalk() { }                                 // _44
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _64

	void startTalk();

protected:
	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	BOOL mIsLookHandledElsewhere; // _18
	Creature* mTarget;            // _1C
	f32 mTalkTimer;               // _20
	bool mIsAnimFinished;         // _24
	                              // _28-_30 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x34.
 */
struct ActBou : public Action {
public:
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

protected:
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
public:
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

	virtual void procCollideMsg(Piki*, MsgCollide*);           // _1C
	virtual ~ActBreakWall() { }                                // _44
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _70

	int gotoWall();
	void initBreakWall();
	void startWorkMotion();
	int breakWall();

protected:
	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	BuildingItem* mWall;         // _18
	u16 mState;                  // _1C
	Vector3f mHitPikminPosition; // _20
	int mStartAttackTime;        // _2C
	u8 mWorkTimer;               // _30
	u8 mFailAttackCounter;       // _31
	bool mIsAttackReady;         // _32
};

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct ActBridge : public Action, virtual PaniAnimKeyListener {
public:
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

	virtual ~ActBridge() { }      // _44
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

protected:
	virtual void procWallMsg(Piki*, MsgWall*);                 // _28
	virtual void dump();                                       // _3C
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _64

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
	int newExeApproach();
	void newInitGo();
	int newExeGo();
	void newInitWork();
	int newExeWork();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	Bridge* mBridge;            // _18, unknown
	u16 mState;                 // _1C
	int mStartWorkTime;         // _20, unknown - same as _300 in gameflow
	BOOL mIsAttackReady;        // _24
	u16 mCollisionCount;        // _28
	u16 _2A;                    // _2A
	f32 mRandomBridgeWidth;     // _2C
	s16 mStageID;               // _30
	bool mClimbingBridge;       // _32
	u8 _33;                     // _33
	Vector3f mBridgeWallNormal; // _34
	Vector3f mClimbingVelocity; // _40
	u8 mActionCounter;          // _4C
	bool mAnimationFinished;    // _4D
	                            // _50-_58 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct ActChase : public Action {
public:
	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
	};
	friend struct Initialiser;

	ActChase(Piki*);

	virtual ~ActChase() { }       // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

protected:
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
	// I want to believe in encapsulation so bad... it's probably to a fault.
	friend struct Navi;
	friend struct NaviDemoSunsetState;
	friend struct Piki;
	friend struct ViewPiki;

public:
	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Unk0   = 0,
		STATE_Formed = 1,
		STATE_Sort   = 2,
	};

	ActCrowd(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual void procAnimMsg(Piki*, MsgAnim*);       // _20
	virtual void procWallMsg(Piki*, MsgWall*);       // _28
	virtual ~ActCrowd() { }                          // _44
	virtual void init(Creature*);                    // _48
	virtual int exec();                              // _4C
	virtual void cleanup();                          // _50
	virtual bool resumable() { return true; }        // _5C
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

	int getSlotID() { return mCPlateSlotID; }

protected:
	// _00     = VTBL
	// _00-_14 = Action
	// _14     = SlotChangeListner ptr
	OdoMeter mOdometer;           // _18
	ActBoreSelect* mSelectAction; // _28
	u16 mState;                   // _2C
	u16 mMode;                    // _2E
	u16 _30;                      // _30
	u16 _32;                      // _32
	bool _34;                     // _34
	bool _35;                     // _35
	bool _36;                     // _36
	u32 _38;                      // _38, unknown
	Vector3f _3C;                 // _3C
	Vector3f _48;                 // _48
	u8 _54[0x4];                  // _54, unknown
	int mCPlateSlotID;            // _58
	int mTripLoopCounter;         // _5C
	f32 _60;                      // _60
	bool mIsTripping;             // _64
	f32 mLostChildTimer;          // _68
	CPlate* mPlateMgr;            // _6C
	Vector3f _70;                 // _70
	u8 mBoredomMotion;            // _7C, is never initialized to anything
	bool mIsWaiting;              // _7D
	bool _7E;                     // _7E
	bool mHasRoute;               // _7F
	                              // _80-_88 = SlotChangeListner
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct ActDecoy : public Action, public PaniAnimKeyListener {
public:
	ActDecoy(Piki*);

	virtual ~ActDecoy() { }                                    // _44 (weak)
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _70 (weak)

protected:
	Creature* findTeki();
	Creature* update();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	int mState;      // _18
	f32 mDecoyTimer; // _1C
};

/**
 * @brief TODO
 */
struct ActDeliver : public AndAction {
public:
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
	friend struct Initialiser;

	ActDeliver(Piki*);

	virtual ~ActDeliver() { }                              // _44 (weak)
	virtual void defaultInitialiser() { mObject.clear(); } // _38 (weak)
	virtual void init(Creature*);                          // _48
	virtual void cleanup() { mObject.reset(); }            // _50 (weak)

protected:
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
public:
	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_RouteMove = 0,
		STATE_GotoLeg   = 1,
		STATE_Climb     = 2,
	};

	ActEnter(Piki*);

	virtual ~ActEnter() { }                          // _44
	virtual void init(Creature*);                    // _48
	virtual int exec();                              // _4C
	virtual void cleanup();                          // _50
	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C

	void findLeg();
	int gotoLeg();
	int climb();

	// unused/inlined:
	int routeMove();

protected:
	// _00     = VTBL
	// _00-_14 = Action
	u16 mState;             // _14
	GoalItem* mOnyon;       // _18
	CollPart* mLeg;         // _1C
	Vector3f mLastPosition; // _20
	bool mHasCollided;      // _2C, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActEscape : public Action {
public:
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
	friend struct Initialiser;

	ActEscape(Piki*);

	virtual ~ActEscape() { }      // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50
	virtual void getInfo(char*);  // _60

protected:
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
public:
	ActExit(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual ~ActExit() { }                           // _44
	virtual void init(Creature*);                    // _48
	virtual int exec();                              // _4C
	virtual void cleanup();                          // _50

protected:
	// _00     = VTBL
	// _00-_14 = Action
	Vector3f mPrevPosition; // _14
	bool mHasCollided;      // _20
};

/**
 * @brief TODO
 */
struct ActFlower : public Action, virtual PaniAnimKeyListener {
public:
	ActFlower(Piki*);

	virtual ~ActFlower() { }                                   // _44 (weak)
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _64 (weak)

protected:
	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	f32 mElapsedTime;          // _18
	bool mIsAnimationComplete; // _1C
	bool mIsCarryEmpty;        // _1D
	                           // _20-_24 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x34.
 */
struct ActFormation : public Action, public PaniAnimKeyListener {
	friend struct TopAction; // Brazenly accesses `mInFormation`.

public:
	ActFormation(Piki*);

	virtual ~ActFormation() { }   // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

protected:
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _70 (weak)

	void getFormPoint();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	bool mInFormation;              // _18
	f32 mIdleTimer;                 // _1C
	FormationMgr* mFormMgr;         // _20
	f32 mDistanceToTarget;          // _24
	bool mUseLastFormationPosition; // _28
	bool mIsIdling;                 // _29
	bool mHasStartedIdleAnim;       // _2A
	bool mIsOnFloorTripped;         // _2B
	bool mHasStartedRunAnim;        // _2C
	BOOL mIsTripping;               // _30
};

/**
 * @brief TODO
 */
struct ActFreeSelect : public Action {
public:
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

protected:
	void determine();

	// _00     = VTBL
	// _00-_14 = Action
	f32 mActionTimer;          // _14, timer?
	bool mIsTimerActive;       // _18
	bool mIsChildActionActive; // _19
	bool mIsFinished;          // _1A
	f32 _1C;                   // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x50.
 */
struct ActFree : public Action, virtual PaniAnimKeyListener {
public:
	ActFree(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*);           // _1C
	virtual ~ActFree() { }                                     // _44
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual bool resumable() { return true; }                  // _5C
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _64

	void initBoid(immut Vector3f&, f32);
	void exeBoid();

protected:
	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	ActFreeSelect* mSelectAction; // _18
	u16 _1C;                      // _1C
	f32 _20;                      // _20
	f32 _24;                      // _24
	f32 mBoidTimer;               // _28
	f32 mFixedPositionTimer;      // _2C
	Vector3f mTargetPosition;     // _30
	f32 mArrivalRadius;           // _3C
	f32 mCollisionCooldownTimer;  // _40
	bool _44;                     // _44
	bool mTouchedPlayer;          // _45
	bool mIsBoidActive;           // _46
	                              // _48-_50 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActGoto : public Action {
public:
	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		Initialiser(f32 maxDistance, f32 minDistance, Creature* target)
		{
			mTarget      = target;
			mMaxDistance = maxDistance;
			mMinDistance = minDistance;
		}

		virtual void initialise(Action*); // _08

		// _00 = VTBL
		Creature* mTarget; // _04
		f32 mMaxDistance;  // _08
		f32 mMinDistance;  // _0C
	};
	friend struct Initialiser;

	ActGoto(Piki*);

	virtual ~ActGoto() { }            // _44 (weak)
	virtual void defaultInitialiser() // _38 (weak)
	{
		mMinDistance = 0.0f;
		mMaxDistance = 9.0f;
	}
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

protected:
	// _00     = VTBL
	// _00-_14 = Action
	f32 mMaxDistance;           // _14
	f32 mMinDistance;           // _18
	SmartPtr<Creature> mTarget; // _1C
	f32 mTimeoutDuration;       // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x4C.
 */
struct ActGuard : public Action {
public:
	enum FormationSide {
		Left,  // 0
		Right, // 1
	};

	ActGuard(Piki*);

	virtual void dump();          // _3C
	virtual ~ActGuard() { }       // _44 (weak)
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

protected:
	// _00     = VTBL
	// _00-_14 = Action
	SmartPtr<Creature> mTarget;     // _14
	SmartPtr<Creature> mLeftGuard;  // _18
	SmartPtr<Creature> mRightGuard; // _1C
	Vector3f _20;                   // _20
	f32 _2C;                        // _2C
	Vector3f mLandPosition;         // _30
	f32 mFormationSpacing;          // _3C
	f32 mTimer;                     // _40
	FormationSide mFormationSide;   // _44
	bool mIsWaiting;                // _48
	bool mIsGuardable;              // _49
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActJumpAttack : public Action, public PaniAnimKeyListener {
public:
	ActJumpAttack(Piki*);

	virtual void procBounceMsg(Piki*, MsgBounce*);             // _0C
	virtual void procStickMsg(Piki*, MsgStick*);               // _10
	virtual void procCollideMsg(Piki*, MsgCollide*);           // _1C
	virtual ~ActJumpAttack() { }                               // _44
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _70

	void attackHit();
	void doClimb();

	// unused/inlined:
	Vector3f getAttackPos();
	f32 getAttackSize();

protected:
	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	int mState;                 // _18
	u8 _1C[0x20 - 0x1C];        // _1C, unknown
	int mAttackState;           // _20
	SmartPtr<Creature> mTarget; // _24
	CollPart* mTargetCollider;  // _28
	bool _2C;                   // _2C
	bool mIsCriticalHit;        // _2D
};

/**
 * @brief TODO
 *
 * @note Size: 0x38.
 */
struct ActKinoko : public Action, virtual PaniAnimKeyListener {
public:
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

	virtual ~ActKinoko() { }      // _44
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

protected:
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _64

	void initStick();
	int exeStick();
	void initJump();
	int exeJump();
	void initAttack();
	int exeAttack();
	void initBoid();
	int exeBoid();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	SmartPtr<Creature> mTarget; // _18
	int mState;                 // _1C, unknown
	f32 mStateTimer;            // _20, unknown
	Vector3f mTargetDirection;  // _24
	                            // _30-_38 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActMine : public Action, virtual PaniAnimKeyListener {
public:
	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Go    = 0,
		STATE_Mine  = 1,
		STATE_Watch = 2,
	};

	ActMine(Piki*);

	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _64
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual ~ActMine() { }                                     // _44 (weak)

	void initWatch();
	int exeMine();

	// unused/inlined:
	int exeWatch();
	int exeGo();
	void initMine();
	void initGo();

protected:
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
public:
	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
		Creature* mObject; // _04
	};
	friend struct Initialiser;

	ActPick(Piki*);

	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _70 (weak)
	virtual ~ActPick() { }                                     // _44 (weak)
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50

protected:
	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	SmartPtr<Creature> mObject; // _18, thing to be picked up
	bool mIsAnimationFinished;  // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct ActPickCreature : public AndAction {
public:
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
	friend struct InitGoto;

	ActPickCreature(Piki*);

	virtual ~ActPickCreature() { } // _44 (weak)
	virtual void init(Creature*);  // _48

protected:
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
public:
	/**
	 * @brief TODO
	 */
	enum ChildID {
		CHILD_NULL = -1,
		CHILD_Goto = 0,
		CHILD_Pick = 1,
		CHILD_COUNT, // 2
	};

	ActPickItem(Piki*);

	virtual ~ActPickItem() { }    // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	Creature* findItem();

protected:
	// _00     = VTBL
	// _00-_18 = AndAction
	SmartPtr<Creature> mTargetItem; // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct ActPullout : public AndAction {
public:
	/**
	 * @brief TODO
	 */
	enum ChildID {
		CHILD_NULL            = -1,
		CHILD_Goto            = 0,
		CHILD_Adjust          = 1,
		CHILD_PulloutCreature = 2,
		CHILD_COUNT, // 3
	};

	ActPullout(Piki*);

	virtual ~ActPullout() { }     // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

protected:
	// _00     = VTBL
	// _00-_18 = AndAction
	SmartPtr<Creature> mTarget; // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct ActPulloutCreature : public Action, private PaniAnimKeyListener {
public:
	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Unk0 = 0,
		STATE_Unk1 = 1,
		STATE_Unk2 = 2,
	};

	ActPulloutCreature(Piki*);

	virtual ~ActPulloutCreature() { }                          // _44 (weak)
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _70

protected:
	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	int mState;                 // _18
	f32 mPulloutTimer;          // _1C
	SmartPtr<Creature> mTarget; // _20
	bool mPulloutSuccess;       // _24
};

/**
 * @brief TODO
 *
 * @note Size: 0x50.
 */
struct ActPush : public Action, virtual PaniAnimKeyListener {
public:
	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Approach = 0,
		STATE_Go       = 1,
	};

	ActPush(Piki*);

	virtual ~ActPush() { }        // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

protected:
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _64 (weak)

	bool collideRockSurface();

	void initApproach();
	int exeApproach();
	void initGo();
	int exeGo();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	HinderRock* mHinderRock; // _18
	u8 mPushAnimationState;  // _1C
	u16 mState;              // _1E
	u8 _20[0x4];             // _20, unknown
	int _24;                 // _24
	u8 _28[0x4];             // _28, unknown
	Vector3f _2C;            // _2C
	f32 _38;                 // _38
	bool mPushObjectStopped; // _3C
	f32 _40;                 // _40
	u8 _44;                  // _44
	s8 mPushCount;           // _45
	bool mIsPushReady;       // _46
	                         // _48-_50 = PaniAnimKeyListener
};

/**
 * @brief TODO
 */
struct ActPut : public Action {
public:
	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
	};
	friend struct Initialiser;

	ActPut(Piki*);

	virtual ~ActPut() { }         // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

protected:
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
public:
	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Throw = 0,
		STATE_Aim   = 1,
		STATE_Set   = 2,
		STATE_Put   = 3,
		STATE_Wait  = 4,
		STATE_Unk5  = 5,
	};

	ActPutBomb(Piki*);

	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _64
	virtual ~ActPutBomb() { }                                  // _44
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50

protected:
	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C

	void findTeki();
	void warnPikis();

	void initSet();
	int exeSet();
	void initAim();
	int exeAim();
	void initWait();
	int exeWait();
	void initThrow();
	int exeThrow();
	void initPut();
	int exePut();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u16 mState;              // _18
	bool mAnimationFinished; // _1A
	bool mTouchedPlayer;     // _1B
	f32 mAimTimer;           // _1C
	f32 mPlaceTimer;         // _20
	Creature* mTarget;       // _24
	                         // _28-_30 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActPutItem : public Action {
public:
	ActPutItem(Piki*);

	virtual ~ActPutItem() { }     // _44
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	void findPos();
	bool findAdjacent(Creature*);

protected:
	// _00     = VTBL
	// _00-_14 = Action
	Vector3f mItemPosition;   // _14
	SmartPtr<Creature> mItem; // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct ActRandomBoid : public Action {
public:
	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Random = 0,
		STATE_Boid   = 1,
		STATE_Stop   = 2,
		STATE_Idle   = 3,
	};

	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
	};
	friend struct Initialiser;

	/**
	 * @brief TODO
	 */
	struct AnimListener : public PaniAnimKeyListener {
		AnimListener(ActRandomBoid* action, Piki* piki)
		{
			mAction = action;
			mPiki   = piki;
		}

		virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _08

		// _00 = VTBL
		ActRandomBoid* mAction; // _04
		Piki* mPiki;            // _08
		bool _0C;               // _0C
	};
	friend struct AnimListener;

	ActRandomBoid(Piki*);

	virtual ~ActRandomBoid() { }  // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50
	virtual void getInfo(char*);  // _60

protected:
	// _00     = VTBL
	// _00-_14 = Action
	int mState;              // _14
	int mStateTimer;         // _18
	bool mIsAnimFinishing;   // _1C
	u32 _20;                 // _20, unknown
	AnimListener* mListener; // _24
};

/**
 * @brief TODO
 *
 * @note Size: 0x3C.
 */
struct ActRescue : public Action, virtual PaniAnimKeyListener {
public:
	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Approach = 0,
		STATE_Rescue   = 1,
		STATE_Go       = 2,
		STATE_Throw    = 3,
	};

	ActRescue(Piki*);

	virtual ~ActRescue() { }      // _44
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	void initApproach();
	int exeApproach();
	void initRescue();
	int exeRescue();
	void initGo();
	int exeGo();
	void initThrow();
	int exeThrow();

protected:
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _64

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	u16 mState;                     // _18
	Piki* mDrowningPiki;            // _1C
	u16 mTargetSurviveTimer;        // _20
	Vector3f mRescueTargetPosition; // _24
	bool mGotAnimationAction;       // _30
	bool mAnimationFinished;        // _31
	bool mThrowReady;               // _32
	                                // _34-_3C = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActRope : public Action {
public:
	ActRope(Piki*);

	virtual ~ActRope() { }        // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

protected:
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
public:
	/**
	 * @brief TODO
	 */
	enum ChildID {
		CHILD_NULL          = -1,
		CHILD_Goto          = 0,
		CHILD_ShootCreature = 1,
		CHILD_COUNT, // 2
	};

	ActShoot(Piki*);

	virtual ~ActShoot() { }       // _44
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

protected:
	Creature* findTarget();
	Creature* decideTarget();

	// _00     = VTBL
	// _00-_18 = AndAction
	bool mTargetIsPlayer;           // _18
	Traversable* mTargetObjectPool; // _1C, idk *what* but it inherits from Traversable
	SmartPtr<Creature> mTarget;     // _20
	Navi* mNavi;                    // _24
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActShootCreature : public Action, public PaniAnimKeyListener {
public:
	/**
	 * @brief The state of the action.
	 */
	enum StateID {
		STATE_Start        = 0,
		STATE_ReadyToShoot = 1, // Unused
		STATE_PrepareShoot = 2,
		STATE_Shooting     = 3, // Unused
		STATE_Chasing      = 4,
		STATE_Complete     = 5,
	};

	ActShootCreature(Piki*);

	virtual ~ActShootCreature() { }                            // _44
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _70

protected:
	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	int mState;                 // _18
	f32 mChaseTimer;            // _1C
	SmartPtr<Creature> mTarget; // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct ActStone : public Action, private PaniAnimKeyListener {

#define STONE_NECTAR_CHANCE (0.08f)

public:
	/**
	 * @brief The state of the action.
	 */
	enum State {
		STATE_Approach = 0,
		STATE_Adjust   = 1,
		STATE_Attack   = 2,
	};

	ActStone(Piki*);

	virtual ~ActStone() { }                                    // _44
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _70

	void initApproach();
	int exeApproach();
	void initAdjust();
	int exeAdjust();
	void initAttack();
	int exeAttack();

protected:
	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u16 mState;          // _18
	u8 _1A[0x20 - 0x1A]; // _1A, unknown
	Pebble* mCurrPebble; // _20, unknown
	RockGen* mRockGen;   // _24
	bool mIsAttackReady; // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0xC0.
 */
struct ActTransport : public Action, virtual PaniAnimKeyListener {
public:
	/**
	 * @brief The state of the action.
	 */
	enum State {
		STATE_Go   = 0, // Moving towards the pellet to pick it up
		STATE_Wait = 1, // Waiting for pellet to settle before carrying
		STATE_Lift = 2, // Lifting/grabbing the pellet
		STATE_Move = 3, // Moving along the path while carrying
		STATE_Guru = 4, // Spinning in place when path is blocked
		STATE_Goal = 5, // Moving towards the final goal position
		STATE_Put  = 6, // Putting down the pellet at destination
		STATE_Jump = 7,
	};

	ActTransport(Piki*);

	virtual void draw(Graphics&); // _40
	virtual ~ActTransport() { }   // _44
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	bool useWaterRoute();
	// not in the DLL, but necessary for doLift
	inline BOOL doLandOnly() { return useWaterRoute() ? FALSE : TRUE; }

protected:
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _64

	void initWait();
	int exeWait();
	void initJump();
	int execJump();

	void turnOver();
	bool isStickLeader();
	f32 getCarriers();
	int getNumStickers();
	int calcNumStickers();
	Pellet* findPellet();
	void setSlotIndex();
	bool gotoLiftPos();
	void doLift();
	int moveGuruGuru();
	void decideGoal(Creature*);
	Vector3f crGetPoint(int);
	bool crPointOpen(int);
	f32 crGetRadius(int);
	void crInit();
	void crMakeRefs();
	void findObstacle();
	bool crMove();
	int moveToWayPoint();

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
	bool mFinishPutting;           // _9C
	bool mIsLiftActionDone;        // _9D
	int mLiftRetryCount;           // _A0
	f32 mWaitTimer;                // _A4
	int mPathIndex;                // _A8
	int mGoalWPIndex;              // _AC
	Suckable* mGoal;               // _B0, either GoalItem* or UfoItem*
	bool mCanCarry;                // _B4
	                               // _B8-_C0 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct ActWatch : public Action {
public:
	/**
	 * @brief TODO
	 */
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
	};
	friend struct Initialiser;

	/**
	 * @brief TODO
	 */
	struct AnimListener : public PaniAnimKeyListener {
		AnimListener(ActWatch* owner, Piki* piki)
		{
			mOwnerAction = owner;
			mActor       = piki;
		}

		virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _08

		// _00 = VTBL
		ActWatch* mOwnerAction; // _04
		Piki* mActor;           // _08
	};
	friend struct AnimListener;

	ActWatch(Piki* piki);

	virtual ~ActWatch() { }       // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50
	virtual void getInfo(char*);  // _60

protected:
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
struct ActWeed : public Action, private PaniAnimKeyListener {

#define GRASS_NECTAR_CHANCE (0.08f)

public:
	/**
	 * @brief The state of the action.
	 */
	enum State {
		STATE_Approach = 0,
		STATE_Adjust   = 1,
		STATE_Attack   = 2,
	};

	ActWeed(Piki*);

	virtual ~ActWeed() { }                                     // _44
	virtual void init(Creature*);                              // _48
	virtual int exec();                                        // _4C
	virtual void cleanup();                                    // _50
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _70

	void initApproach();
	int exeApproach();
	void initAdjust();
	int exeAdjust();
	void initNuking();
	int exeNuking();

protected:
	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u16 mState;              // _18
	u8 _1A[0x6];             // _1A, unknown
	Grass* mCurrGrass;       // _20
	GrassGen* mGrassGen;     // _24
	u16 _28;                 // _28
	bool mAnimationFinished; // _2A
};

/**
 * @brief Completely stripped. This class shows up in the ILK.
 */
struct AbsStates {
public:
	AbsStates(Piki*);

	void init();
	void update(Creature*);
};

/**
 * @brief Almost completely stripped, uniqueInstance gets set to nullptr in pikiMgr.
 */
struct AiTable {
public:
	/**
	 * @brief Completely stripped. Static member shows up stripped in map.
	 */
	struct Row {
		Row();

		void print();

		static int numInputs;

		// TODO: members
	};

	struct Tables {
		// TODO: This class shows up in the ILK.
	};

	struct Output {
		// TODO: This class shows up in the ILK.
	};

	void addRows(int, Tables*, int);
	void addRow(int, ...); // __cdecl?
	Output* find(int, AbsStates*);

	static void init() { uniqueInstance = nullptr; }
	static AiTable* create(AbsStates*); // __cdecl?

protected:
	AiTable(AbsStates*);

	static AiTable* uniqueInstance;

	// TODO: members
};

#endif
