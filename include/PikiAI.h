#ifndef _PIKIAI_H
#define _PIKIAI_H

#include "types.h"
#include "PaniAnimator.h"
#include "Piki.h"
#include "Receiver.h"
#include "SlotChangeListner.h"
#include "stl/stdio.h"

struct Pebble;
struct RockGen;

namespace zen {
struct particleGenerator;
} // namespace zen

/**
 * @brief TODO
 */
enum ActionResults {
	ACTOUT_Unk0    = 0,
	ACTOUT_Unk1    = 1,
	ACTOUT_Success = 2,
};

namespace Reaction {
extern char* info[9];
} // namespace Reaction

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

	inline Child* getChild(int idx) { return &mChildActions[idx]; }

	inline void initialiseChildAction(Creature* creature) { getChild(mChildActionIdx)->initialise(creature); }

	// _00 = VTBL
	Child* mChildActions; // _04, array of mChildCount Children
	s16 mChildActionIdx;  // _08
	s16 mChildCount;      // _0A
	Piki* mActor;         // _0C
	char* mName;          // _10
};

/**
 * @brief TODO
 */
struct AndAction : public Action {
	inline AndAction(Piki* piki) // TODO: probably
	    : Action(piki, false)
	{
	}

	virtual ~AndAction() { }      // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C

	// _00     = VTBL
	// _00-_14 = Action
	Creature* _14; // _14
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
	Creature* _14; // _14
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
		void getIndex(int);
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
		void getIndex(int);
		void getBoredom(int, int);
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
		mChildActions[mChildActionIdx].mAction->getInfo(out);
	}
	virtual void draw(Graphics& gfx) // _40
	{
		if (_18) {
			mChildActions[mChildActionIdx].mAction->draw(gfx);
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

	// _00     = VTBL
	// _00-_14 = Action
	MotionListener* mListener; // _14
	u8 _18;                    // _18
	u8 _19;                    // _19
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
		// TODO: members
	};

	ActAdjust(Piki*);

	virtual void defaultInitialiser(); // _38 (weak)
	virtual ~ActAdjust();              // _44 (weak)
	virtual void init(Creature*);      // _48
	virtual int exec();                // _4C
	virtual void cleanup();            // _50

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
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
	void decideTarget();

	// _00     = VTBL
	// _00-_18 = AndAction
	// _18     = PaniAnimKeyListener
	u8 _1C[0x2C - 0x1C]; // _14, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ActBoMake : public Action {
	ActBoMake(Piki*);

	virtual ~ActBoMake();                                // _44
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
	u8 _14[0x24 - 0x14]; // _14, unknown
};

/**
 * @brief TODO
 */
struct ActBoreListen : public Action {
	ActBoreListen(Piki*);

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual ~ActBoreListen();                  // _44
	virtual void init(Creature*);              // _48
	virtual int exec();                        // _4C
	virtual void cleanup();                    // _50

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActBoreOneshot : public Action, public PaniAnimKeyListener {
	ActBoreOneshot(Piki*);

	virtual ~ActBoreOneshot();                           // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void finish();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActBoreRest : public Action, public PaniAnimKeyListener {
	ActBoreRest(Piki*);

	virtual ~ActBoreRest();                              // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void sitDown();

	// unused/inlined:
	void standUp();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActBoreSelect : public Action {
	ActBoreSelect(Piki*);

	virtual void procTargetMsg(Piki*, MsgTarget*); // _18
	virtual void procAnimMsg(Piki*, MsgAnim*);     // _20
	virtual ~ActBoreSelect();                      // _44
	virtual void init(Creature*);                  // _48
	virtual int exec();                            // _4C
	virtual void cleanup();                        // _50

	void stop();
	void determine();

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActBoreTalk : public Action, public PaniAnimKeyListener {
	ActBoreTalk(Piki*);

	virtual ~ActBoreTalk();                              // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void startTalk();

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
struct ActBou : public Action {
	ActBou(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual ~ActBou();                               // _44 (weak)
	virtual void init(Creature*);                    // _48
	virtual int exec();                              // _4C
	virtual void cleanup();                          // _50

	void gotoLeg();
	void climb();

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x34 - 0x14]; // _14, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x34.
 */
struct ActBreakWall : public Action, public PaniAnimKeyListener {
	ActBreakWall(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*);     // _1C
	virtual ~ActBreakWall();                             // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	void gotoWall();
	void initBreakWall();
	void startWorkMotion();
	void breakWall();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18[0x34 - 0x18]; // _18, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct ActBridge : public Action, public PaniAnimKeyListener {
	ActBridge(Piki*);

	virtual void procWallMsg(Piki*, MsgWall*);           // _28
	virtual void dump();                                 // _3C
	virtual ~ActBridge();                                // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void newExeApproach();
	void newInitGo();
	void newExeGo();
	void newInitWork();
	void newExeWork();

	// unused/inlined:
	void collideBridgeSurface();
	void collideBridgeBlocker();
	void initDetour();
	void exeDetour();
	void initClimb();
	void exeClimb();
	void initApproach();
	void exeApproach();
	void initGo();
	void exeGo();
	void initWork();
	void exeWork();
	void doWork(int);
	void newInitApproach();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18[0x58 - 0x18]; // _18, unknown
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
struct ActCrowd : public Action, public SlotChangeListner {
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
	// _14     = SlotChangeListner
	u8 _18[0x88 - 0x18]; // _18, unknown
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

	void findTeki();

	// unused/inlined:
	void update();

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
	void gotoLeg();
	void climb();

	// unused/inlined:
	void routeMove();

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
struct ActFree : public Action, public PaniAnimKeyListener {
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
	// _14     = PaniAnimKeyListener
	u8 _18[0x50 - 0x18]; // _18
};

/**
 * @brief TODO
 */
struct ActFreeSelect : public Action {
	ActFreeSelect(Piki*);

	virtual void procTargetMsg(Piki*, MsgTarget*); // _18
	virtual ~ActFreeSelect();                      // _44
	virtual void init(Creature*);                  // _48
	virtual int exec();                            // _4C
	virtual void cleanup();                        // _50

	void finishRest();
	void determine();

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
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

	void findFriend();
	void checkLoop(Piki*);
	void findFriend(int);
	void setGoal();
	void getLeft(Piki*);
	void getRight(Piki*);
	void setLeft();
	void setRight();

	// _00     = VTBL
	// _00-_14 = Action
	u8 _14[0x4C - 0x14]; // _14, unknown
};

/**
 * @brief TODO
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
	void getAttackPos();
	void getAttackSize();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x38.
 */
struct ActKinoko : public Action, public PaniAnimKeyListener {
	ActKinoko(Piki*);

	virtual ~ActKinoko();                                // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void exeStick();
	void exeJump();
	void initAttack();
	void exeAttack();
	void initBoid();
	void exeBoid();

	// unused/inlined:
	void initStick();
	void initJump();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18[0x38 - 0x18]; // _18, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActMine : public Action, public PaniAnimKeyListener {
	ActMine(Piki*);

	virtual ~ActMine();                                  // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64 (weak)

	void initWatch();
	void exeMine();

	// unused/inlined:
	void exeWatch();
	void exeGo();
	void initMine();
	void initGo();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18[0x30 - 0x18]; // _18, unknown
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
	};

	ActPick(Piki*);

	virtual ~ActPick();                                  // _44 (weak)
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

	void findItem();

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
struct ActPush : public Action, public PaniAnimKeyListener {
	ActPush(Piki*);

	virtual ~ActPush();                                  // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64 (weak)

	void exeApproach();
	void initGo();
	void exeGo();

	// unused/inlined:
	void collideRockSurface();
	void initApproach();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18[0x50 - 0x18]; // _18, unknown
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

	virtual ~ActPut();            // _44 (weak)
	virtual void init(Creature*); // _48
	virtual int exec();           // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ActPutBomb : public Action, public PaniAnimKeyListener {
	ActPutBomb(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*);     // _1C
	virtual ~ActPutBomb();                               // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void findTeki();
	void initSet();
	void exeSet();
	void warnPikis();
	void initAim();
	void exeAim();
	void initWait();
	void initThrow();
	void initPut();
	void exeThrow();

	// unused/inlined:
	void exeWait();
	void exePut();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18[0x30 - 0x18]; // _18, unknown
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
	void findAdjacent(Creature*);

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
struct ActRescue : public Action, public PaniAnimKeyListener {
	ActRescue(Piki*);

	virtual ~ActRescue();                                // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void initApproach();
	void exeApproach();
	void initRescue();
	void exeRescue();
	void initGo();
	void exeGo();
	void initThrow();
	void exeThrow();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18[0x3C - 0x18]; // _18, unknown
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

	void findTarget();

	// unused/inlined:
	void decideTarget();

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
struct ActTransport : public Action, public PaniAnimKeyListener {
	ActTransport(Piki*);

	virtual void draw(Graphics&);                        // _40
	virtual ~ActTransport();                             // _44
	virtual void init(Creature*);                        // _48
	virtual int exec();                                  // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void turnOver();
	bool isStickLeader();
	void getCarriers();
	void findPellet();
	void setSlotIndex();
	int execJump();
	void gotoLiftPos();
	void doLift();
	void useWaterRoute();
	void moveGuruGuru();
	void decideGoal(Creature*);
	void crGetPoint(int);
	void crPointOpen(int);
	void crInit();
	void crMakeRefs();
	void findObstacle();
	void crMove();
	void moveToWayPoint();

	// unused/inlined:
	void initWait();
	void exeWait();
	void getNumStickers();
	void calcNumStickers();
	void initJump();
	void crGetRadius(int);

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	u8 _18[0xC0 - 0x18]; // _18, unknown
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

	ActWatch(Piki*);

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
	void exeApproach();
	void initAdjust();
	void exeAdjust();
	void initNuking();
	void exeNuking();

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
		static u32 numInputs;

		// TODO: members
	};

	static AiTable* uniqueInstance;

	// TODO: members
};

#endif
