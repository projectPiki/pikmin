#ifndef _ITEMMGR_H
#define _ITEMMGR_H

#include "AICreature.h"
#include "CreatureNode.h"
#include "ObjectMgr.h"
#include "SimpleAI.h"
#include "types.h"

struct BuildingItemProp;
struct GoalAI;
struct GoalItem;
struct GoalItemProp;
struct KusaItemProp;
struct MeltingPotMgr;
struct PelletShapeObject;
struct PikiHeadMgr;
struct SluiceAI;
struct UfoItem;
struct UfoItemProp;
struct UfoShapeObject;

/**
 * @brief TODO.
 *
 * @note Size: 0x18.
 */
struct ItemShapeObject {
	ItemShapeObject(Shape*, char*, char*);

	Shape* mShape;            // _00
	AnimMgr* mAnimMgr;        // _04
	AnimContext mAnimContext; // _08
};

/**
 * @brief TODO.
 */
struct ItemCreature : public AICreature {
public:
	ItemCreature(int objType, CreatureProp*, Shape*);

	virtual void init(Vector3f&);            // _28
	virtual f32 getHeight() { return 0.0f; } // _40
	virtual bool stimulate(Interaction&);    // _A0
	virtual void update();                   // _E0
	virtual void refresh(Graphics&);         // _EC
	virtual void doAI();                     // _104
	virtual void doAnimation();              // _108
	virtual void startMotion(int);           // _130
	virtual void finishMotion();             // _134
	virtual void finishMotion(f32);          // _138
	virtual void startMotion(int, f32);      // _13C
	virtual char* getCurrentMotionName();    // _140
	virtual f32 getCurrentMotionCounter();   // _144
	virtual f32 getMotionSpeed();            // _148
	virtual void setMotionSpeed(f32);        // _14C
	virtual void stopMotion();               // _150
	virtual void finalSetup();               // _158 (weak)

protected:
	virtual void doKill(); // _10C

public:
	// _00      = VTBL
	// _00-_304 = AICreature
	f32 mMotionSpeed;                  // _304
	Shape* mItemShape;                 // _308
	SearchData mItemSearchData[8];     // _30C
	PaniItemAnimator mItemAnimator;    // _36C
	ItemShapeObject* mItemShapeObject; // _3C0
	bool _3C4;                         // _3C4
};

/**
 * @brief TODO.
 */
struct ItemMgr : public PolyObjectMgr {

	/**
	 * @brief TODO
	 *
	 * @note Size: 0x18.
	 */
	struct UseNode : public CoreNode {
		UseNode() { initCore("usageNode"); }

		// _00     = VTBL
		// _00-_14 = CoreNode
		int mType; // _14
	};

	ItemMgr();

	virtual ~ItemMgr() { }             // _48 (weak)
	virtual void update();             // _4C (weak)
	virtual void refresh(Graphics&);   // _58
	virtual Creature* birth(int);      // _78
	virtual void kill(Creature*);      // _7C
	virtual void refresh2d(Graphics&); // _80

	GoalItem* getContainer(int color);
	GoalItem* getNearestContainer(Vector3f&, f32);
	UfoItem* getUfo();
	void addUseList(int);
	ItemShapeObject* getPelletShapeObject(int, int);
	void initialise();
	int getContainerExitCount();

	// unused/inlined:
	ObjectMgr* getMgr(int);
	int getPikiNum();
	bool useObjType(int type);
	void showInfo();
	Shape* getUfoShape();

	MeltingPotMgr* getMeltingPotMgr() { return mMeltingPotMgr; }
	PikiHeadMgr* getPikiHeadMgr() { return mPikiHeadMgr; }

	// DLL inlines to make:
	Shape* getPebbleShape(int i) { return mPebbleShapeList[i]; }
	Shape* getGrassShape(int i) { return mGrassShapeList[i]; }

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_4C = PolyObjectMgr
	Shape* mPebbleShapeList[3];        // _4C
	Shape* mGrassShapeList[3];         // _58
	PikiHeadMgr* mPikiHeadMgr;         // _64
	MeltingPotMgr* mMeltingPotMgr;     // _68
	UseNode mRootUseNode;              // _6C
	u8 _84[0x4];                       // _84, unknown
	ItemShapeObject** mItemShapes;     // _88, array of 11 ItemShapeObject*
	UfoShapeObject* mUfoShape;         // _8C
	PaniMotionTable* mItemMotionTable; // _90
	PaniMotionTable* mUfoMotionTable;  // _94
};

/**
 * @brief TODO.
 *
 * @note Size: 0x64.
 */
struct MeltingPotMgr : public CreatureNodeMgr {
	MeltingPotMgr(ItemMgr*);

	virtual ~MeltingPotMgr() { } // _48 (weak)

	void finalSetup();
	void prepare(int objType);
	Creature* birth(int objType);

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_40 = CreatureNodeMgr
	ItemMgr* mItemMgr;             // _40
	GoalItemProp* mGoalProps;      // _44
	UfoItemProp* mUfoProps;        // _48
	KusaItemProp* mKusaProps;      // _4C
	BuildingItemProp* mBuildProps; // _50
	GoalAI* mGoalAI;               // _54
	SluiceAI* mSluiceAI;           // _58
	Shape* mBouShape;              // _5C
	Shape* mBoBaseShape;           // _60
};

extern ItemMgr* itemMgr;

#endif
