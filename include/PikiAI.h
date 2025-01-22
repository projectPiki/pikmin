#ifndef _PIKIAI_H
#define _PIKIAI_H

#include "types.h"
#include "PaniAnimator.h"
#include "Piki.h"
#include "Receiver.h"
#include "SlotChangeListner.h"
#include "stl/stdio.h"

struct Bridge;
struct BuildingItem;
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
		virtual void initialise(Action*); // _08 (weak)

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

	void procMsg(Msg*); // this isn't overridden in the vtable but it exists, idk.
	void setChildren(int, ...);

	char* getName() { return mName; }

	// ONLY DLL inlines to do:
	void setName(char*);

	// _00 = VTBL
	Child* mChildActions; // _04, array of mChildCount Children
	s16 mCurrActionIdx;   // _08
	s16 mChildCount;      // _0A
	Piki* mActor;         // _0C
	char* mName;          // _10
};

/**
 * @brief TODO
 */
struct AndAction : public Action {
	AndAction(Piki* piki)
	    : Action(piki, true)
	{
		mOtherCreature = nullptr; // this might be an argument in the ctor, who knows
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

		// unused/inlined:
		int getIndex(int);
		void addBoredom(int, f32);
		void update();

		u32* _00; // _00, unknown (pointer?)
		u32* _04; // _04, unknown (pointer?)
		u8* _08;  // _08, array of size _10, might be bools
		u32 _0C;  // _0C, unknown
		int mCnt; // _10, count of objects in _00, _04, _08 arrays
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

		ObjBore* mObjects; // _00, array of mObjectCnt objects
		u32* _04;          // _04, unknown (pointer?)
		u32 _08;           // _08, unknown
		int mObjectCnt;    // _0C, number of mObjects
		u32 _10;           // _10, unknown
	};

	TopAction(Piki*);

	virtual void getInfo(char* out) // _60
	{
		mChildActions[mCurrActionIdx].mAction->getInfo(out);
	}
	virtual void draw(Graphics& gfx) // _40
	{
		if (_18) {
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
	u8 _18;                    // _18
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
		f32 _04; // _04, same as _14 in ActAdjust
		int _08; // _08, same as _18 in ActAdjust
	};

	ActAdjust(Piki*);

	virtual ~ActAdjust() { }          // _44 (weak)
	virtual void defaultInitialiser() // _38 (weak)
	{
		_14 = 10.0f;
		_18 = 8;
	}
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	f32 _14;      // _14
	int _18;      // _18
	Vector3f _1C; // _1C
	f32 _28;      // _28
	f32 _2C;      // _2C
	Vector3f _30; // _30
	u8 _3C;       // _3C
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct ActAttack : public AndAction, public PaniAnimKeyListener {
	ActAttack(Piki*);

	virtual ~ActAttack();                                // _44
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

	inline Creature* getTarget() { return _24; } // name is a guess

	// _00     = VTBL
	// _00-_18 = AndAction
	// _18     = PaniAnimKeyListener
	u8 _1C;        // _1C
	u8 _1D;        // _1D
	u8 _1E;        // _1E
	u8 _1F;        // _1F
	u32 _20;       // _20, unknown
	Creature* _24; // _24
	Creature* _28; // _28
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
	f32 mActionTimer;        // _14
	u8 mIsTimerActive;       // _18
	u8 mIsChildActionActive; // _19
	u8 _1A;                  // _1A
	f32 _1C;                 // _1C
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
	s16 _16;                  // _16
	Vector3f _18;             // _18
	Creature* mClimbingStick; // _24
	Vector3f _28;             // _28
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
	u32 _2C;             // _2C, unknown, same as gameflow._300
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
		STATE_Unk1     = 1, // one of these is detour
		STATE_Go       = 2,
		STATE_Unk3     = 3, // and one is climb. both unused
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
	Bridge* mBridge;     // _18, unknown
	u16 mState;          // _1C
	u32 _20;             // _20, unknown - same as _300 in gameflow
	u32 _24;             // _24
	u16 mCollisionCount; // _28
	u16 _2A;             // _2A
	f32 _2C;             // _2C
	s16 mStageIdx;       // _30
	u8 _32;              // _32
	u8 _33;              // _33
	Vector3f _34;        // _34
	Vector3f _40;        // _40
	u8 mActionCounter;   // _4C
	u8 _4D;              // _4D
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

	virtual ~ActChase();          // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x1C - 0x14]; // _14, unknown
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
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
	};

	ActDeliver(Piki*);

	virtual void defaultInitialiser(); // _38 (weak)
	virtual ~ActDeliver();             // _44 (weak)
	virtual void init(Creature*);      // _48
	virtual void cleanup();            // _50 (weak)

	// _00     = VTBL
	// _00-_18 = AndAction
	// TODO: members
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
	struct Initialiser : public Action::Initialiser {
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
	};

	ActEscape(Piki*);

	virtual ~ActEscape();         // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50
	virtual void getInfo(char*);  // _60

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x30 - 0x14]; // _14, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActExit : public Action {
	ActExit(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual ~ActExit();                              // _44
	virtual void init(Creature*);                    // _48
	virtual int exec();                              // _4C
	virtual void cleanup();                          // _50

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x24 - 0x14]; // _14, unknown
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
	u8 _18[0x34 - 0x18]; // _18, unknown
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
	f32 mActionTimer;        // _14, timer?
	u8 mIsTimerActive;       // _18
	u8 mIsChildActionActive; // _19
	u8 _1A;                  // _1A
	f32 _1C;                 // _1C
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
		virtual void initialise(Action*); // _08

		// _00 = VTBL
		// TODO: members
	};

	ActGoto(Piki*);

	virtual void defaultInitialiser(); // _38 (weak)
	virtual ~ActGoto();                // _44 (weak)
	virtual void init(Creature*);      // _48
	virtual int exec();                // _4C
	virtual void cleanup();            // _50

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x24 - 0x14]; // _14, unknown
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
	virtual ~ActJumpAttack();                            // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	void attackHit();
	void doClimb();

	// unused/inlined:
	Vector3f getAttackPos();
	f32 getAttackSize();

	inline Creature* getTarget() { return _24; } // name is a guess

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	int _18;             // _18
	u8 _1C[0x20 - 0x1C]; // _1C, unknown
	int _20;             // _20
	Creature* _24;       // _24
	CollPart* _28;       // _28
	u8 _2C;              // _2C
	u8 _2D;              // _2D
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
	Creature* _18; // _18, unknown
	int mState;    // _1C, unknown
	u8 _20[0x4];   // _20, unknown
	Vector3f _24;  // _24
	               // _30-_38 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActMine : public Action, virtual PaniAnimKeyListener {
	ActMine(Piki*);

	virtual ~ActMine();                                  // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64 (weak)

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
	u8 _18[0x28 - 0x18]; // _18, unknown
	                     // _28-_30 = PaniAnimKeyListener
};

/**
 * @brief TODO
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
	Creature* mObject; // _18, thing to be picked up
	u8 _1C;            // _1C
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
	struct InitGoto {
		void initialise(Action*, Action*);
		// TODO: members
	};

	ActPickCreature(Piki*);

	virtual ~ActPickCreature();   // _44 (weak)
	virtual void init(Creature*); // _48

	// _00     = VTBL
	// _00-_18 = AndAction
	u8 _18[0x1C - 0x18]; // _18, unknown
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

	virtual ~ActRope();           // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x24 - 0x14]; // _14, unknown
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

	/**
	 * @brief TODO
	 */
	enum State {
		STATE_Approach = 0,
		STATE_Adjust   = 1,
		STATE_Attack   = 2,
	};

	ActStone(Piki*);

	virtual ~ActStone();                                 // _44
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
	u8 _1A[0x20 - 0x1A]; // _18, unknown
	Pebble* mCurrPebble; // _20, unknown
	RockGen* mRockGen;   // _24
	u8 _28;              // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0xC0.
 */
struct ActTransport : public Action, virtual PaniAnimKeyListener {
	ActTransport(Piki*);

	virtual void draw(Graphics&);                        // _40
	virtual ~ActTransport();                             // _44
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

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener ptr
	Pellet* mPellet;     // _18
	u8 _1C[0x4];         // _1C, unknown
	OdoMeter mOdometer;  // _20
	Vector3f _30;        // _30
	u8 _3C[0x4C - 0x3C]; // _3C, unknown
	Vector3f _4C[4];     // _4C, probably CR spline points
	Vector3f _7C;        // _7C
	u32 _88;             // _88
	int mSlotIndex;      // _8C
	Vector3f _90;        // _90
	u8 _9C[0xA8 - 0x9C]; // _9C, unknown
	int _A8;             // _A8
	u8 _AC[0xB8 - 0xAC]; // _AC, unknown
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
		virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

		// _00 = VTBL
		// TODO: members
	};

	ActWatch(Piki* piki);

	virtual ~ActWatch();          // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50
	virtual void getInfo(char*);  // _60

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x2C - 0x14]; // _14, unknown
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
