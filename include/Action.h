#ifndef _ACTION_H
#define _ACTION_H

#include "types.h"
#include "Receiver.h"
#include "Piki.h"

/**
 * @brief TODO
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

	virtual void defaultInitialiser(); // _38 (weak)
	virtual void dump();               // _3C (weak)
	virtual void draw(Graphics&);      // _40 (weak)
	virtual ~Action();                 // _44
	virtual void init(Creature*);      // _48
	virtual void exec();               // _4C
	virtual void cleanup();            // _50
	virtual void resume();             // _54 (weak)
	virtual void restart();            // _58 (weak)
	virtual void resumable();          // _5C (weak)
	virtual void getInfo(char*);       // _60 (weak)

	void procMsg(Msg*); // this isn't overridden in the vtable but it exists, idk.
	void setChildren(int, ...);

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct AndAction : public Action {
	virtual ~AndAction();         // _44 (weak)
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct OrAction : public Action {
	virtual ~OrAction();          // _44 (weak)
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct TopAction : public Action {

	/**
	 * @brief TODO
	 */
	struct MotionListener {
		virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

		// _00 = VTBL
		// TODO: members
	};

	virtual void draw(Graphics&); // _40
	virtual ~TopAction();         // _44
	virtual void init(Creature*); // _48
	virtual void exec();          // _4C
	virtual void resume();        // _54
	virtual void restart();       // _58
	virtual void resumable();     // _5C
	virtual void getInfo(char*);  // _60

	// _00 = VTBL
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

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActAttack : public AndAction, virtual public PaniAnimKeyEvent {
	ActAttack(Piki*);

	virtual ~ActAttack();                                // _44
	virtual void init(Creature*);                        // _48
	virtual void exec();                                 // _4C
	virtual void cleanup();                              // _50
	virtual void resume();                               // _54
	virtual void restart();                              // _58
	virtual void resumable();                            // _5C
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _70

	// _00 = VTBL
	// TODO: members
};

#endif
