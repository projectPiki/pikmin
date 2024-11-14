#ifndef _ITEMMGR_H
#define _ITEMMGR_H

#include "types.h"
#include "AICreature.h"
#include "ObjectMgr.h"
#include "CreatureNode.h"

struct PelletShapeObject;

/**
 * @brief TODO.
 */
struct ItemShapeObject {
	ItemShapeObject(Shape*, char*, char*);

	// TODO: members -  this is a guess based on PelletShapeObject
	// + what gets accessed out of 0x3C0 in ItemCreature
	Shape* mShape;     // _00
	AnimMgr* mAnimMgr; // _04
	AnimContext _08;   // _08
};

/**
 * @brief TODO.
 */
struct ItemCreature : public AICreature {
	ItemCreature(int objType, CreatureProp*, Shape*);

	virtual void init(Vector3f&);          // _28
	virtual f32 getHeight();               // _40
	virtual bool stimulate(Interaction&);  // _A0
	virtual void update();                 // _E0
	virtual void refresh(Graphics&);       // _EC
	virtual void doAI();                   // _104
	virtual void doAnimation();            // _108
	virtual void doKill();                 // _10C
	virtual void startMotion(int);         // _130
	virtual void finishMotion();           // _134
	virtual void finishMotion(f32);        // _138
	virtual void startMotion(int, f32);    // _13C
	virtual char* getCurrentMotionName();  // _140
	virtual f32 getCurrentMotionCounter(); // _144
	virtual f32 getMotionSpeed();          // _148
	virtual void setMotionSpeed(f32);      // _14C
	virtual void stopMotion();             // _150
	virtual void finalSetup();             // _158 (weak)

	// _00      = VTBL
	// _00-_304 = AICreature?
	f32 mMotionSpeed;                  // _304
	Shape* mItemShape;                 // _308
	SearchData mItemSearchData[8];     // _30C
	PaniItemAnimator mItemAnimator;    // _36C
	ItemShapeObject* mItemShapeObject; // _3C0
	u8 _3C4;                           // _3C4
};

/**
 * @brief TODO.
 */
struct ItemMgr : public PolyObjectMgr {

	/**
	 * @brief TODO.
	 */
	struct UseNode : public CoreNode {
		// _00     = VTBL
		// _00-_14 = CoreNode
		// TODO: members
	};

	ItemMgr();

	virtual ~ItemMgr();                // _48 (weak)
	virtual void update();             // _4C (weak)
	virtual void refresh(Graphics&);   // _58
	virtual Creature* birth(int);      // _78
	virtual void kill(Creature*);      // _7C
	virtual void refresh2d(Graphics&); // _80

	void getContainer(int);
	void getNearestContainer(Vector3f&, f32);
	void getUfo();
	void addUseList(int);
	PelletShapeObject* getPelletShapeObject(int, int);
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
	// _00-_28 = PolyObjectMgr?
	u8 _28[0x90 - sizeof(PolyObjectMgr)]; // _28, unknown - fix offset when size of PolyObjectMgr is known
	PaniMotionTable* mMotionTable;        // _90
};

/**
 * @brief TODO.
 */
struct MeltingPotMgr : public CreatureNodeMgr {
	MeltingPotMgr(ItemMgr*);

	virtual ~MeltingPotMgr(); // _48 (weak)

	void finalSetup();
	void prepare(int);
	void birth(int);

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_28 = CreatureNodeMgr?
	// TODO: members
};

extern ItemMgr* itemMgr;

#endif
