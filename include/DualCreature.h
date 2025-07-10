#ifndef _DUALCREATURE_H
#define _DUALCREATURE_H

#include "Collision.h"
#include "DynCreature.h"
#include "PaniAnimator.h"
#include "types.h"

struct ItemShapeObject;
struct MapMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x440.
 */
struct DualCreature : public DynCreature {
	DualCreature();

	virtual void update();                           // _E0
	virtual void refresh(Graphics&);                 // _EC
	virtual void doKill();                           // _10C
	virtual bool onGround();                         // _114
	virtual void doRender(Graphics&, Matrix4f&) = 0; // _118
	virtual void doCreateColls(Graphics&)       = 0; // _11C

	bool isFrontFace();
	f32 getY();
	void useRealDynamics();
	void useSimpleDynamics();
	void rotateY(f32);

	// unused/inlined:
	void createCollisions(Graphics&);

	void setDynamicsSimpleFixed(bool isSimpleFixed) { mIsDynamicsSimpleFixed = isSimpleFixed; }

	// DLL inlines todo:
	bool isRealDynamics() { return mIsRealDynamics; }
	void invalidateCollisions() { mIsCollisionInitialised = false; }

	// _00      = VTBL
	// _00-_43C = DynCreature
	bool mIsRealDynamics;        // _43C
	bool mIsCollisionInitialised; // _43D
	bool _43E;                    // _43E
	bool mIsDynamicsSimpleFixed; // _43F
};

/**
 * @brief TODO
 */
struct PelCreature : public DualCreature {
	PelCreature(int, ItemShapeObject*, CreatureProp*, MapMgr*);

	virtual void init(Vector3f&);                // _28
	virtual void startAI(int);                   // _34
	virtual f32 getiMass();                      // _38
	virtual bool isAlive();                      // _88
	virtual void doRender(Graphics&, Matrix4f&); // _118
	virtual void doCreateColls(Graphics&);       // _11C

	// _00      = VTBL
	// _00-_440 = DualCreature
	PaniItemAnimator mItemAnimator; // _440
	ItemShapeObject* mItemShape;    // _494
	CollInfo mItemCollInfo;         // _498
	CollPart mItemParts[10];        // _4AC
	u32 mPartIDs[10];               // _8BC
};

#endif
