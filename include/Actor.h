#ifndef _ACTOR_H
#define _ACTOR_H

#include "AICreature.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "ObjectMgr.h"
#include "Piki.h"
#include "types.h"

struct ActorMgr;
struct SimpleAI;

/**
 * @brief TODO
 *
 * @note Fun fact: The vtable for this does spawn, but then gets stripped :')
 * @note Size: 0x3DC.
 */
struct Actor : public AICreature {
	friend struct ActorMgr;

public:
	Actor(); // unused/inlined

	void setType(int, PikiShapeObject*, CreatureProp*, SimpleAI*);

	// unused/inlined:
	virtual void startAI(int);          // _34
	virtual void refresh(Graphics&);    // _EC
	virtual void update();              // _E0
	virtual void doAnimation();         // _108
	virtual void doAI();                // _104
	virtual void startMotion(int);      // _130
	virtual void startMotion(int, f32); // _13C
	virtual void finishMotion();        // _134
	virtual void finishMotion(f32);     // _138

protected:
	virtual void doKill(); // _10C

	// _00      = VTBL
	// _00-_304 = AICreature
	PaniPikiAnimMgr mPikiAnimMgr; // _304
	PikiShapeObject* mPikiShape;  // _3B0
	u8 _3B4[0x3d8 - 0x3b4];       // _3B4
	ActorMgr* mMgr;               // _3D8
};

/**
 * @brief TODO
 *
 * @note This also spawns a vtable but it gets stripped.
 */
struct ActorMgr : public MonoObjectMgr {
	friend struct Actor;

public:
	ActorMgr(MapMgr*); // unused/inlined

	virtual ~ActorMgr() { } // _48

	Actor* newActor(int);

protected:
	virtual Creature* createObject(); // _80

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
