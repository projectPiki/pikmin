#ifndef _BOMBITEM_H
#define _BOMBITEM_H

#include "CreatureProp.h"
#include "ItemMgr.h"
#include "SimpleAI.h"
#include "SoundMgr.h"
#include "types.h"

struct InteractBikkuri;
struct InteractSwallow;

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct BombItemProp : public CreatureProp {
	inline BombItemProp()
	{
		mCreatureProps.mFriction.mValue     = 0.1f;
		mCreatureProps.mBounceFactor.mValue = 0.8f;
	}

	// _54     = VTBL
	// _00-_58 = CreatureProp
};

/**
 * @brief TODO
 *
 * @note Size: 0x840.
 */
struct BombItem : public ItemCreature {
	BombItem(CreatureProp*, ItemShapeObject*, SimpleAI*);

	virtual void startAI(int);                        // _34
	virtual f32 getiMass();                           // _38
	virtual f32 getSize();                            // _3C
	virtual bool isVisible();                         // _74
	virtual bool isAlive();                           // _88
	virtual bool needShadow();                        // _90
	virtual void collisionCallback(immut CollEvent&); // _A8
	virtual void dump();                              // _C8
	virtual void update();                            // _E0
	virtual void refresh(Graphics&);                  // _EC
	virtual void refresh2d(Graphics&);                // _F0
	virtual void renderTimer(Graphics&);              // _15C
	virtual void renderBlast(Graphics&);              // _160

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	u8 _3C8[0x3CC - 0x3C8];  // _3C8
	SeContext mSound;        // _3CC
	CollInfo mBombColl;      // _3F4
	CollPart mCollParts[10]; // _408
	u32 mCollPartIdList[10]; // _818
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct BombAI : public SimpleAI {

	/**
	 * @brief TODO
	 */
	enum BombStateID {
		BOMB_Unk0 = 0,
		BOMB_Unk1 = 1,
		BOMB_Set  = 2,
		BOMB_Bomb = 3,
		BOMB_Mizu = 4,
		BOMB_Die  = 5,
		BOMB_COUNT, // 6
	};

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
	// _00-_1C = SimpleAI
};

#endif
