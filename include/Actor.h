#ifndef _ACTOR_H
#define _ACTOR_H

#include "types.h"
#include "Creature.h"
#include "ObjectMgr.h"

struct CreatureProp;
struct MapMgr;
struct PikiShapeObject;
struct SimpleAI;

/**
 * @brief TODO
 *
 * @note This HAS to inherit creature to be spawned by ActorMgr::birth, but it doesn't have a vtable??
 */
struct Actor : public Creature {
	Actor(); // unused/inlined

	void setType(int, PikiShapeObject*, CreatureProp*, SimpleAI*);

	// unused/inlined:
	void startAI(int);
	void refresh(struct Graphics&);
	void update();
	void doAnimation();
	void doAI();
	void doKill();
	void startMotion(int);
	void startMotion(int, f32);
	void finishMotion();
	void finishMotion(f32);

	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Inheritance is a guess - it doesn't spawn a vtable, but it uses a virtual method?? MonoObjectMgr seems the best fit.
 */
struct ActorMgr : public MonoObjectMgr {
	ActorMgr(MapMgr*); // unused/inlined

	// how the hell doesn't this spawn a vtable.

	Actor* newActor(int);

	// unused/inlined:
	~ActorMgr();
	void createObject();

	// _00     = VTBL
	// _00-_1C = MonoObjectMgr?
	// TODO: members?
	u8 _1C[0x40 - 0x1C];   // _1C, unknown
	PikiShapeObject** _40; // _40
	CreatureProp** _44;    // _44
	SimpleAI** _48;        // _48
};

extern ActorMgr* actorMgr;

#endif
