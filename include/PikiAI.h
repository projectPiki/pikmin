#ifndef _PIKIAI_H
#define _PIKIAI_H

#include "types.h"
#include "PaniAnimator.h"
#include "Piki.h"
#include "Receiver.h"
#include "SlotChangeListner.h"

namespace zen {
struct particleGenerator;
} // namespace zen

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct Action : public Receiver<Piki> {

	/**
	 * @brief TODO
	 */
	struct Child {
		Child();

		~Child();

		void initialise(Creature*);

		// TODO: members
		u32 _00; // _00, unknown
		u32 _04; // _04, unknown
	};

	/**
	 * @brief TODO
	 */
	struct Initialiser {
		virtual void initialise(Action*); // _08 (weak)

		// _00 = VTBL
		// TODO: members
	};

	Action(Piki*, bool);

	virtual void defaultInitialiser();   // _38 (weak)
	virtual void dump();                 // _3C (weak)
	virtual void draw(struct Graphics&); // _40 (weak)
	virtual ~Action();                   // _44
	virtual void init(Creature*);        // _48
	virtual void exec();                 // _4C
	virtual void cleanup();              // _50
	virtual void resume();               // _54 (weak)
	virtual void restart();              // _58 (weak)
	virtual void resumable();            // _5C (weak)
	virtual void getInfo(char*);         // _60 (weak)

	void procMsg(Msg*); // this isn't overridden in the vtable but it exists, idk.
	void setChildren(int, ...);

	// _00 = VTBL
	u8 _04[0x14 - 0x4]; // _04, TODO: work out members
};

/**
 * @brief TODO
 */
struct AndAction : public Action {
	inline AndAction(); // TODO: probably

	virtual ~AndAction();         // _44 (weak)
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C

	// _00     = VTBL
	// _00-_14 = Action
	u32 _14; // _14, unknown
};

/**
 * @brief TODO
 */
struct OrAction : public Action {
	inline OrAction(); // TODO: probably

	virtual ~OrAction();          // _44 (weak)
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct TopAction : public Action {

	/**
	 * @brief TODO
	 */
	struct MotionListener : public PaniAnimKeyListener {
		virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

		// _00 = VTBL
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct ObjBore {
		ObjBore();

		u32 _00;  // _00, unknown (pointer?)
		u32 _04;  // _04, unknown (pointer?)
		u8* _08;  // _08, array of size _10, might be bools
		u32 _0C;  // _0C, unknown
		int mCnt; // _10, count of objects in _00, _04, _08 arrays
	};

	/**
	 * @brief TODO
	 */
	struct Boredom {
		Boredom();

		ObjBore* mObjects; // _00, array of mObjectCnt objects
		u32 _04;           // _04, unknown (pointer?)
		u32 _08;           // _08, unknown
		int mObjectCnt;    // _0C, number of mObjects
		u32 _10;           // _10, unknown
	};

	TopAction(Piki*);

	virtual void draw(Graphics&); // _40
	virtual ~TopAction();         // _44
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C
	virtual void resume();        // _54
	virtual void restart();       // _58
	virtual void resumable();     // _5C
	virtual void getInfo(char*);  // _60

	void abandon(zen::particleGenerator*);

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
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
	virtual void exec();               // _4C
	virtual void cleanup();            // _50

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActAttack : public AndAction, public PaniAnimKeyListener {
	ActAttack(Piki*);

	virtual ~ActAttack();                                // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void resume();                               // _54
	virtual void restart();                              // _58
	virtual void resumable();                            // _5C
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	void findTarget();

	// _00     = VTBL
	// _00-_18 = AndAction
	// _18     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActBoMake : public Action {
	ActBoMake(Piki*);

	virtual ~ActBoMake();                                // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	void initApproach();
	void exeApproach();
	void initWork();
	void exeWork();

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActBoreListen : public Action {
	ActBoreListen(Piki*);

	virtual void procAnimMsg(Piki*, MsgAnim*); // _20
	virtual ~ActBoreListen();                  // _44
	virtual void init(Creature*);              // _48
	virtual void exec();                       // _4C
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
	virtual void exec();                                 // _4C
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
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void sitDown();

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
	virtual void exec();                           // _4C
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
	virtual void exec();                                 // _4C
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
 */
struct ActBou : public Action {
	ActBou(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual ~ActBou();                               // _44 (weak)
	virtual void init(Creature*);                    // _48
	virtual void exec();                             // _4C
	virtual void cleanup();                          // _50

	void gotoLeg();
	void climb();

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActBreakWall : public Action, public PaniAnimKeyListener {
	ActBreakWall(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*);     // _1C
	virtual ~ActBreakWall();                             // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	void gotoWall();
	void initBreakWall();
	void startWorkMotion();
	void breakWall();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActBridge : public Action, public PaniAnimKeyListener {
	ActBridge(Piki*);

	virtual void procWallMsg(Piki*, MsgWall*);           // _28
	virtual void dump();                                 // _3C
	virtual ~ActBridge();                                // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void newExeApproach();
	void newInitGo();
	void newExeGo();
	void newInitWork();
	void newExeWork();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
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
	virtual void exec();          // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActCrowd : public Action, public SlotChangeListner {
	ActCrowd(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual void procAnimMsg(Piki*, MsgAnim*);       // _20
	virtual void procWallMsg(Piki*, MsgWall*);       // _28
	virtual ~ActCrowd();                             // _44
	virtual void init(Creature*);                    // _48
	virtual void exec();                             // _4C
	virtual void cleanup();                          // _50
	virtual void resumable();                        // _5C
	virtual void inform(int);                        // _64

	void startSort();
	void startZawatuki();
	void finishZawatuki();

	// _00     = VTBL
	// _00-_14 = Action
	// _18     = SlotChangeListner
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActDecoy : public Action, public PaniAnimKeyListener {
	ActDecoy(Piki*);

	virtual ~ActDecoy();                                 // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70 (weak)

	void findTeki();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
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
 */
struct ActEnter : public Action {
	ActEnter(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual ~ActEnter();                             // _44
	virtual void init(Creature*);                    // _48
	virtual void exec();                             // _4C
	virtual void cleanup();                          // _50

	void findLeg();
	void gotoLeg();
	void climb();

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
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
	virtual void exec();          // _4C
	virtual void cleanup();       // _50
	virtual void getInfo(char*);  // _60

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActExit : public Action {
	ActExit(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*); // _1C
	virtual ~ActExit();                              // _44
	virtual void init(Creature*);                    // _48
	virtual void exec();                             // _4C
	virtual void cleanup();                          // _50

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActFlower : public Action, public PaniAnimKeyListener {
	ActFlower(Piki*);

	virtual ~ActFlower();                                // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64 (weak)

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActFormation : public Action, public PaniAnimKeyListener {
	ActFormation(Piki*);

	virtual ~ActFormation();                             // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70 (weak)

	void getFormPoint();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActFree : public Action, public PaniAnimKeyListener {
	ActFree(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*);     // _1C
	virtual ~ActFree();                                  // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void resumable();                            // _5C
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void initBoid(struct Vector3f&, f32);
	void exeBoid();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActFreeSelect : public Action {
	ActFreeSelect(Piki*);

	virtual void procTargetMsg(Piki*, MsgTarget*); // _18
	virtual ~ActFreeSelect();                      // _44
	virtual void init(Creature*);                  // _48
	virtual void exec();                           // _4C
	virtual void cleanup();                        // _50

	void finishRest();
	void determine();

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
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
	virtual void exec();               // _4C
	virtual void cleanup();            // _50

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActGuard : public Action {
	ActGuard(Piki*);

	virtual void dump();          // _3C
	virtual ~ActGuard();          // _44 (weak)
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C
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
	// TODO: members
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
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	void attackHit();
	void doClimb();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActKinoko : public Action, public PaniAnimKeyListener {
	ActKinoko(Piki*);

	virtual ~ActKinoko();                                // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void exeStick();
	void exeJump();
	void initAttack();
	void exeAttack();
	void initBoid();
	void exeBoid();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActMine : public Action, public PaniAnimKeyListener {
	ActMine(Piki*);

	virtual ~ActMine();                                  // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64 (weak)

	void initWatch();
	void exeMine();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
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
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70 (weak)

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActPickCreature : public AndAction {
	ActPickCreature(Piki*);

	virtual ~ActPickCreature();   // _44 (weak)
	virtual void init(Creature*); // _48

	// _00     = VTBL
	// _00-_18 = AndAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActPickItem : public AndAction {
	ActPickItem(Piki*);

	virtual ~ActPickItem();       // _44 (weak)
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C
	virtual void cleanup();       // _50

	void findItem();

	// _00     = VTBL
	// _00-_18 = AndAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActPullout : public Action {
	ActPullout(Piki*);

	virtual ~ActPullout();        // _44 (weak)
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActPulloutCreature : public Action, public PaniAnimKeyListener {
	ActPulloutCreature(Piki*);

	virtual ~ActPulloutCreature();                       // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70 (weak)

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActPush : public Action, public PaniAnimKeyListener {
	ActPush(Piki*);

	virtual ~ActPush();                                  // _44 (weak)
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64 (weak)

	void exeApproach();
	void initGo();
	void exeGo();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
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
	virtual void exec();          // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActPutBomb : public Action, public PaniAnimKeyListener {
	ActPutBomb(Piki*);

	virtual void procCollideMsg(Piki*, MsgCollide*);     // _1C
	virtual ~ActPutBomb();                               // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
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

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActPutItem : public Action {
	ActPutItem(Piki*);

	virtual ~ActPutItem();        // _44
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C
	virtual void cleanup();       // _50

	void findPos();
	void findAdjacent(Creature*);

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
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
	virtual void exec();          // _4C
	virtual void cleanup();       // _50
	virtual void getInfo(char*);  // _60

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActRescue : public Action, public PaniAnimKeyListener {
	ActRescue(Piki*);

	virtual ~ActRescue();                                // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActRope : public Action {
	ActRope(Piki*);

	virtual ~ActRope();           // _44 (weak)
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C
	virtual void cleanup();       // _50

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActShoot : public AndAction {
	ActShoot(Piki*);

	virtual ~ActShoot();          // _44
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C
	virtual void cleanup();       // _50

	void findTarget();

	// _00     = VTBL
	// _00-_18 = AndAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActShootCreature : public Action, public PaniAnimKeyListener {
	ActShootCreature(Piki*);

	virtual ~ActShootCreature();                         // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActStone : public Action, public PaniAnimKeyListener {
	ActStone(Piki*);

	virtual ~ActStone();                                 // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	void initApproach();
	void exeApproach();
	void initAdjust();
	void exeAdjust();
	void initAttack();
	void exeAttack();

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActTransport : public Action, public PaniAnimKeyListener {
	ActTransport(Piki*);

	virtual void draw(Graphics&);                        // _40
	virtual ~ActTransport();                             // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _64

	void turnOver();
	bool isStickLeader();
	void getCarriers();
	void findPellet();
	void setSlotIndex();
	void execJump();
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

	// _00     = VTBL
	// _00-_14 = Action
	// _14     = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
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
	virtual void exec();          // _4C
	virtual void cleanup();       // _50
	virtual void getInfo(char*);  // _60

	// _00     = VTBL
	// _00-_14 = Action
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActWeed : public Action, public PaniAnimKeyListener {
	ActWeed(Piki*);

	virtual ~ActWeed();                                  // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
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
	// TODO: members
};

#endif
