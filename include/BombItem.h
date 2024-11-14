#ifndef _BOMBITEM_H
#define _BOMBITEM_H

#include "types.h"
#include "ItemMgr.h"
#include "CreatureProp.h"
#include "SimpleAI.h"

struct InteractBikkuri;
struct InteractSwallow;

/**
 * @brief TODO
 */
struct BombItemProp : public CreatureProp {

	// _54     = VTBL
	// _00-_58 = CreatureProp
	// TODO: members
};

/**
 * @brief TODO
 */
struct BombItem : public ItemCreature {
	BombItem(CreatureProp*, ItemShapeObject*, SimpleAI*);

	virtual void startAI(int);                  // _34
	virtual f32 getiMass();                     // _38
	virtual f32 getSize();                      // _3C
	virtual bool isVisible();                   // _74
	virtual bool isAlive();                     // _88
	virtual bool needShadow();                  // _90
	virtual void collisionCallback(CollEvent&); // _A8
	virtual void dump();                        // _C8
	virtual void update();                      // _E0
	virtual void refresh(Graphics&);            // _EC
	virtual void refresh2d(Graphics&);          // _F0
	virtual void renderTimer(Graphics&);        // _15C
	virtual void renderBlast(Graphics&);        // _160

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	// TODO: members
};

/**
 * @brief TODO
 */
struct BombAI : public SimpleAI {

	/**
	 * @brief TODO
	 */
	struct BombExec : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct BombInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct DieExec : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct DieInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct MizuExec : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct MizuInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct SetExec : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct SetInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	BombAI();

	// _00     = VTBL
	// _00-_?? = SimpleAI
	// TODO: members
};

#endif
