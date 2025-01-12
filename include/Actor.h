#ifndef _ACTOR_H
#define _ACTOR_H

#include "types.h"
#include "ObjectMgr.h"
#include "AICreature.h"
#include "PaniPikiAnimator.h"

struct CreatureProp;
struct MapMgr;
struct PikiShapeObject;
struct SimpleAI;

/**
 * @brief TODO
 *
 * @note Fun fact: The vtable for this does spawn, but then gets stripped :')
 */
struct Actor : public AICreature {
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

	// _00      = VTBL
	// _00-_304 = AICreature
	PaniPikiAnimMgr mPikiAnimMgr; // _304
	PikiShapeObject* mPikiShape;  // _3B0
};

/**
 * @brief TODO
 *
 * @note This also spawns a vtable but it gets stripped.
 */
struct ActorMgr : public MonoObjectMgr {
	ActorMgr(MapMgr*); // unused/inlined
	~ActorMgr();

	Actor* newActor(int);

	Creature* createObject();

	// _00     = VTBL
	// _08     = VTBL
	// _00-_3C = MonoObjectMgr
	PaniMotionTable* mMotionTable;        // _3C
	PikiShapeObject** mShapeObjectList;   // _40
	CreatureProp** mCreaturePropertyList; // _44
	SimpleAI** mAiManagerList;            // _48
};

extern ActorMgr* actorMgr;

#endif
