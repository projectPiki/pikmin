#ifndef _PIKIHEADITEM_H
#define _PIKIHEADITEM_H

#include "types.h"
#include "ItemMgr.h"
#include "CreatureProp.h"
#include "SimpleAI.h"
#include "UtEffect.h"

struct InteractBikkuri;
struct InteractSwallow;
struct SimpleAI;

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct PikiHeadItemProp : public CreatureProp {
	inline PikiHeadItemProp()
	{
		mCreatureProps.mFriction.mValue     = 0.1f;
		mCreatureProps.mBounceFactor.mValue = 0.8f;
	}

	// _54     = VTBL
	// _00-_58 = CreatureProp
};

/**
 * @brief TODO
 */
struct PikiHeadItem : public ItemCreature {
	PikiHeadItem(CreatureProp*, ItemShapeObject*, SimpleAI*);

	virtual void startAI(int);               // _34
	virtual f32 getiMass();                  // _38
	virtual f32 getSize();                   // _3C
	virtual bool isVisible();                // _74
	virtual bool isAtari() { return false; } // _84
	virtual bool isAlive();                  // _88
	virtual bool needShadow();               // _90
	virtual void startWaterEffect();         // _CC
	virtual void finishWaterEffect();        // _D0
	virtual void refresh(Graphics&);         // _EC
	virtual void doKill();                   // _10C
	virtual void playSound(int);             // _128

	bool canPullout();
	void setPermanentEffects(bool);
	void setColor(int);
	bool interactBikkuri(InteractBikkuri&);
	bool interactSwallow(InteractSwallow&);

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	FreeLightEffect* mFreeLightEfx; // _3C8
	int mSeedColor;                 // _3CC
	int mFlowerStage;               // _3D0
	Vector3f _3D4;                  // _3D4
	Creature* _3E0;                 // _3E0
	PermanentEffect _3E4;           // _3E4
	RippleEffect* mRippleEfx;       // _3F4
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct PikiHeadAI : public SimpleAI {

	/**
	 * @brief TODO
	 */
	enum PikiHeadStateID {
		PIKIHEAD_Flying   = 0,
		PIKIHEAD_Unk1     = 1,
		PIKIHEAD_Bounce   = 2,
		PIKIHEAD_Bury     = 3,
		PIKIHEAD_Tane     = 4,
		PIKIHEAD_Unk5     = 5,
		PIKIHEAD_Wait     = 6,
		PIKIHEAD_Unk7     = 7,
		PIKIHEAD_Growuped = 8,
		PIKIHEAD_Grow     = 9,
		PIKIHEAD_Unk10    = 10,
		PIKIHEAD_Kareta   = 11,
		PIKIHEAD_Dead     = 12,
		PIKIHEAD_Unk13    = 13,
		PIKIHEAD_Bury2    = 14,
		PIKIHEAD_COUNT, // 15
	};

	/**
	 * @brief TODO
	 */
	struct BounceSound : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct BuryExec : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct BuryExec2 : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct BuryInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct BuryInit2 : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct Dead : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct FlyingCleanup : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct FlyingEffect : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct FlyingExec : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct GrowEffect : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct GrowupedExec : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct KaretaExec : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct KaretaInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct TaneExec : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct TaneInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct WaitExec : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct WaitInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	PikiHeadAI();

	// _00     = VTBL
	// _00-_1C = SimpleAI
};

/**
 * @brief TODO
 *
 * @note Size: 0x48.
 */
struct PikiHeadMgr : public MonoObjectMgr {
	PikiHeadMgr(ItemMgr*);

	virtual ~PikiHeadMgr();           // _48 (weak)
	virtual Creature* birth();        // _78
	virtual Creature* createObject(); // _80

	static u8 buryMode;

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_3C = MonoObjectMgr
	ItemMgr* mItemMgr;                // _3C
	PikiHeadItemProp* mPikiHeadProps; // _40
	PikiHeadAI* mPikiHeadAI;          // _44
};

#endif
