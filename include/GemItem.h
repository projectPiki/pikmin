#ifndef _GEMITEM_H
#define _GEMITEM_H

#include "types.h"
#include "ItemMgr.h"

struct SimpleAI;

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

	void setColorType(int);
	void split();

	// unused/inlined:
	void setAtariFree();
	void reachCapacity();
	void updateLiftup();
	void startPick(f32);
	void finishPick();

	// _00      = VTBL
	// _00-_304 = ItemCreature?
	// TODO: members
};

#endif
