#ifndef _GEMITEM_H
#define _GEMITEM_H

#include "types.h"
#include "ItemMgr.h"
#include "SimpleAI.h"
#include "SoundMgr.h"

/*
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
	bool _3C8;             // _3C8
	int _3CC;              // _3CC
	f32 _3D0;              // _3D0
	f32 _3D4;              // _3D4
	u8 _3D8;               // _3D8
	u8 _3D9;               // _3D9
	int mGemType;          // _3DC pellet size?
	int mColor;            // _3E0
	u8 _3E4;               // _3E4
	f32 _3E8;              // _3E8
	int _3EC;              // _3EC
	int _3F0;              // _3F0
	int _3F8;              // _3F8
	int _3FC;              // _3FC
	CollInfo mGemCollInfo; // _400
	CollPart mGemColl[10]; // _414
	SeContext mGemSe;      // _84C
};

/**
 * @brief TODO
 */
struct GemAI : public SimpleAI {

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
