#ifndef _PELLET_H
#define _PELLET_H

#include "types.h"
#include "DualCreature.h"
#include "CreatureProp.h"
#include "ObjectMgr.h"
#include "Animator.h"

struct PaniAnimKeyEvent;
struct PaniMotionTable;
struct PelletShapeObject;
struct PelletView;
struct Shape;

/**
 * @brief TODO
 */
struct PelletProp : public CreatureProp {

	// _54     = VTBL
	// _00-_58 = CreatureProp
	// TODO: members
};

/**
 * @brief TODO
 */
struct PelletConfig : public Parameters, public CoreNode {
	PelletConfig();

	virtual void read(RandomAccessStream&); // _18 (weak)

	// _04     = VTBL
	// _00-_04 = Parameters
	// _04-_18 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct Pellet : public DualCreature {
	Pellet();

	virtual void init(Vector3f&);                        // _28
	virtual void startAI(int);                           // _34
	virtual f32 getiMass();                              // _38
	virtual f32 getSize();                               // _3C
	virtual f32 getCylinderHeight();                     // _44
	virtual void doSave(RandomAccessStream&);            // _50
	virtual void doLoad(RandomAccessStream&);            // _54
	virtual Vector3f getCentre();                        // _58
	virtual bool isVisible();                            // _74
	virtual bool isAtari();                              // _84
	virtual bool isAlive();                              // _88
	virtual bool ignoreAtari(Creature*);                 // _98
	virtual bool isFree();                               // _9C
	virtual bool stimulate(Interaction&);                // _A0
	virtual void collisionCallback(struct CollEvent&);   // _A8
	virtual void bounceCallback();                       // _AC
	virtual void startWaterEffect();                     // _CC
	virtual void finishWaterEffect();                    // _D0
	virtual void update();                               // _E0
	virtual void postUpdate(int, f32);                   // _E4
	virtual void refresh(Graphics&);                     // _EC
	virtual void doAnimation();                          // _108
	virtual void doKill();                               // _10C
	virtual void doRender(Graphics&, Matrix4f&);         // _118
	virtual void doCreateColls(Graphics&);               // _11C
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _12C (weak)

	void getState();
	void setTrySound(bool);
	void startPick();
	void finishPick();
	void startGoal();
	void doCarry(Creature*, Vector3f&, u16);
	void getBottomRadius();
	void startStickTeki(Creature*, f32);
	void endStickTeki(Creature*);
	void winnable(int);
	void stickSlot(int);
	void stickOffSlot(int);
	void getMinFreeSlotIndex();
	void getNearestFreeSlotIndex(Vector3f&);
	void getRandomFreeSlotIndex();
	void getSlotLocalPos(int, f32);
	void getSlotGlobalPos(int, f32);
	void setSlotFlag(int);
	void resetSlotFlag(int);
	void isSlotFlag(int);
	void initPellet(PelletShapeObject*, PelletConfig*);
	void startCarryMotion(f32);
	void finishMotion();

	// unused/inlined:
	void initSlotFlags();
	void initPellet(PelletView*, PelletConfig*);
	void stopMotion();
	void startAppear();

	static bool isUfoPartsID(u32);

	// _00      = VTBL
	// _00-_43C = DualCreature?
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x204.
 */
struct PelletMgr : public MonoObjectMgr {

	/**
	 * @brief TODO
	 */
	struct UseNode : public CoreNode {
		// _00     = VTBL
		// _00-_14 = CoreNode
		// TODO: members
	};

	PelletMgr(MapMgr*);

	virtual ~PelletMgr();                   // _48 (weak)
	virtual void refresh(Graphics&);        // _58
	virtual Pellet* createObject();         // _80
	virtual void read(RandomAccessStream&); // _84 (weak)

	void getUfoIndexFromID(u32);
	void getUfoIDFromIndex(int);
	void decomposeNumberPellet(u32, int&, int&);
	void registerUfoParts();
	void newNumberPellet(int, int);
	void newPellet(u32, PelletView*);
	PelletShapeObject* getShapeObject(u32);
	void addUseList(u32);
	void initShapeInfos();
	void getConfigIndex(u32);
	void getConfigFromIdx(int);
	void getConfig(u32);
	void readConfigs(RandomAccessStream&);
	void readAnimInfos(RandomAccessStream&);
	void initTekiNakaParts();
	void createShapeObjects();
	void refresh2d(Graphics&);

	// unused/inlined:
	void useShape(u32);
	void getConfigIdAt(int);

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_3C = MonoObjectMgr
	// TODO: members
	u8 _3C[0x1F8 - 0x3C];   // _3C, unknown
	PaniMotionTable* _1F8;  // _1F8
	u8 _1FC[0x204 - 0x1FC]; // _1FC, unknown
};

/**
 * @brief TODO
 */
struct PelletShapeObject {
	PelletShapeObject(char*, Shape*, char*, char*, int);

	Shape* mShape;     // _00
	AnimMgr* mAnimMgr; // _04
	AnimContext _08;   // _08
	AnimContext _18;   // _18
	                   // TODO: members
};

extern PelletMgr* pelletMgr;

#endif
