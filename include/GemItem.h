#ifndef _GEMITEM_H
#define _GEMITEM_H

#include "ItemMgr.h"
#include "SimpleAI.h"
#include "SoundMgr.h"
#include "types.h"

/**
 * @brief TODO
 */
struct GemTable {
	int mGemNumber;        // _00, Speculative; It counts 1, 5, 10, 20, 50.  Could just as easily be swapped with _08.
	int mMaxCarry;         // _04, See: `GemItem::mMaxStickers` and `GemItem::reachCapacity`.
	int mMinCarry;         // _08, Speculative, like `PelletConfig::mCarryMinPikis`?
	int mMatchingSeeds;    // _0C, See: `GemItem::mMatchingSeeds` and `GemAI::Die::act`.
	int mNonMatchingSeeds; // _10, See: `GemItem::mNonMatchingSeeds` and `GemAI::Die::act`.
	int mSplitAmount;      // _14, Gem 10 splits into two Gem 5s, Gem 5 splits into five Gem 1s.  Gem 1, Gem 20, and Gem 50 split not.
	f32 _18;               // _18, Could be a couple of things, and nothing reads it, so I won't speculate.
};

/**
 * @brief TODO
 *
 * @note Virtual table is stripped (so no RTTI) - inheritance is a guess.
 */
struct GemItem : public ItemCreature {
	GemItem(CreatureProp*, int, Shape**, Shape**, Shape**, SimpleAI*, f32, int, int);

	virtual void setRouteTracer(RouteTracer*); // _20, stripped
	virtual void initParam(int);               // _30, stripped
	virtual void startAI(int);                 // _34, stripped
	virtual f32 getiMass();                    // _38, stripped
	virtual f32 getSize();                     // _3C, stripped
	virtual void doStore(CreatureInf*);        // _48, stripped
	virtual void doRestore(CreatureInf*);      // _4C, stripped
	virtual bool isAlive();                    // _88, stripped
	virtual bool ignoreAtari(Creature*);       // _98, stripped
	virtual void bounceCallback();             // _AC, stripped
	virtual void update();                     // _E0, stripped
	virtual void refresh(Graphics&);           // _EC, stripped
	virtual void doKill();                     // _10C, stripped
	virtual void setAtariFree();               // _15C, stripped

	void setColorType(int);
	void split();

	// unused/inlined:
	bool reachCapacity();
	void updateLiftup();
	void startPick(f32);
	void finishPick();

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
	bool mIsFree;              // _3C8
	RouteTracer* mRouteTracer; // _3CC
	f32 mTargetHeight;         // _3D0
	f32 mCurrentHeight;        // _3D4
	bool mIsRising;            // _3D8
	bool mIsBeingLifted;       // _3D9
	int mGemType;              // _3DC pellet size?
	int mColor;                // _3E0
	bool mIsAlive;             // _3E4
	f32 mSizeScale;            // _3E8
	int mGemNumber;            // _3EC, speculative
	int mMaxStickers;          // _3F0
	int mMinStickers;          // _3F4, speculative
	int mMatchingSeeds;        // _3F8
	int mNonMatchingSeeds;     // _3FC
	CollInfo mGemCollInfo;     // _400
	CollPart mGemColl[10];     // _414
	u32 mCollInfoIDs[10];      // _824
	SeContext mGemSe;          // _84C
};

/**
 * @brief TODO
 */
struct GemAI : public SimpleAI {

	/**
	 * @brief TODO
	 */
	enum GemStateID {
		GEM_Unk0 = 0,
		GEM_Rise = 1,
		GEM_Die  = 2,
		GEM_COUNT, // 3
	};

	/**
	 * @brief TODO
	 */
	struct Die : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct RiseExec : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct RiseInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	GemAI();

	// _00     = VTBL
	// _00-_?? = SimpleAI
	// TODO: members
};

#endif
