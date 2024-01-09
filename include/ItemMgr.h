#ifndef _ITEMMGR_H
#define _ITEMMGR_H

#include "types.h"
#include "AICreature.h"
#include "ObjectMgr.h"

/**
 * @brief TODO.
 */
struct ItemCreature : public AICreature {
	ItemCreature(int, CreatureProp*, Shape*);

	virtual void init(Vector3f&);           // _28
	virtual void getHeight();               // _40
	virtual void stimulate(Interaction&);   // _A0
	virtual void update();                  // _E0
	virtual void refresh(Graphics&);        // _EC
	virtual void doAI();                    // _104
	virtual void doAnimation();             // _108
	virtual void doKill();                  // _10C
	virtual void startMotion(int);          // _130
	virtual void finishMotion();            // _134
	virtual void finishMotion(f32);         // _138
	virtual void startMotion(int, f32);     // _13C
	virtual void getCurrentMotionName();    // _140
	virtual void getCurrentMotionCounter(); // _144
	virtual void getMotionSpeed();          // _148
	virtual void setMotionSpeed(f32);       // _14C
	virtual void stopMotion();              // _150
	virtual void finalSetup();              // _158 (weak)

	// _00      = VTBL
	// _00-_304 = AICreature?
	// TODO: members
};

/**
 * @brief TODO.
 */
struct ItemObject : public ItemCreature {
	ItemObject(int, Shape*); // unused/inlined

	virtual bool isAtari();            // _84
	virtual bool needShadow();         // _90
	virtual void update();             // _E0
	virtual void postUpdate(int, f32); // _E4

	// _00      = VTBL
	// _00-_304 = ItemCreature?
	// TOD0: members
};

/**
 * @brief TODO.
 */
struct ItemMgr : public PolyObjectMgr {
	ItemMgr();

	virtual ~ItemMgr();                // _48 (weak)
	virtual void update();             // _4C (weak)
	virtual void refresh(Graphics&);   // _58
	virtual void birth(int);           // _78
	virtual void kill(Creature*);      // _7C
	virtual void refresh2d(Graphics&); // _80

	void getContainer(int);
	void getNearestContainer(Vector3f&, f32);
	void getUfo();
	void addUseList(int);
	void getPelletShapeObject(int, int);
	void initialise();
	void getContainerExitCount();

	// unused/inlined:
	void getMgr(int);
	void getPikiNum();
	void useObjType(int);
	void showInfo();
	void getUfoShape();

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_1C = PolyObjectMgr?
	// TODO: members
};

#endif
