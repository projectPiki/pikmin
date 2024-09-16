#ifndef _WORKOBJECT_H
#define _WORKOBJECT_H

#include "types.h"
#include "ItemMgr.h"
#include "ObjectMgr.h"

/**
 * @brief TODO
 */
struct WorkObject : public ItemCreature {
	WorkObject(); // unused/inlined

	virtual bool isVisible();         // _74
	virtual bool isAlive();           // _88
	virtual void doKill();            // _10C
	virtual void finalSetup();        // _158
	virtual bool isBridge();          // _15C
	virtual bool isHinderRock();      // _160
	virtual bool isFinished();        // _164
	virtual bool workable(Vector3f&); // _168

	// _00      = VTBL
	// _00-_??? = ItemCreature?
	// TODO: members
};

/**
 * @brief TODO
 */
struct WorkObjectMgr : public ObjectMgr {
	WorkObjectMgr();

	virtual Creature* getCreature(int); // _08
	virtual int getFirst();             // _0C
	virtual int getNext(int);           // _10
	virtual bool isDone(int);           // _14
	virtual ~WorkObjectMgr();           // _48
	virtual int getSize();              // _60
	virtual int getMax();               // _64

	void finalSetup();
	void loadShapes();
	void birth(int, int);

	// unused/inlined:
	void getNameIndex(char*);
	void getName(int);
	void getShapeNameIndex(char*);
	void getShapeName(int);
	void addUseList(int);

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_28 = ObjectMgr?
	// TODO: members
};

/**
 * @brief TODO
 */
struct WorkObjectNode : public CoreNode {

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct Bridge : public WorkObject {
	Bridge(Shape*, bool);

	virtual bool insideSafeArea(Vector3f&);   // _10
	virtual bool alwaysUpdatePlatform();      // _18
	virtual void startAI(int);                // _34
	virtual void doSave(RandomAccessStream&); // _50
	virtual void doLoad(RandomAccessStream&); // _54
	virtual void stimulate(Interaction&);     // _A0
	virtual void dump();                      // _C8
	virtual void update();                    // _E0
	virtual void refresh(Graphics&);          // _EC
	virtual void finalSetup();                // _158
	virtual bool isBridge();                  // _15C
	virtual bool isFinished();                // _164
	virtual bool workable(Vector3f&);         // _168

	void getFirstUnfinishedStage();
	void getFirstFinishedStage();
	void getJointIndex(int);
	bool isStageFinished(int);
	void flatten();
	void setStageFinished(int, bool);
	void getStagePos(int);
	void getStageZ(int);
	void getBridgePos(Vector3f&, f32&, f32&);
	void getBridgeZVec();
	void getBridgeXVec();
	void getStartPos();
	f32 getStageDepth();
	f32 getStageWidth();
	void startStageFinished(int, bool);

	// _00      = VTBL
	// _00-_??? = WorkObject?
	// TODO: members
};

/**
 * @brief TODO
 */
struct HinderRock : public WorkObject {
	HinderRock(Shape*);

	virtual bool insideSafeArea(Vector3f&);   // _10
	virtual void startAI(int);                // _34
	virtual void doSave(RandomAccessStream&); // _50
	virtual void doLoad(RandomAccessStream&); // _54
	virtual f32 getCentreSize();              // _5C
	virtual void stimulate(Interaction&);     // _A0
	virtual void update();                    // _E0
	virtual void refresh(Graphics&);          // _EC
	virtual bool isHinderRock();              // _160
	virtual bool isFinished();                // _164
	virtual bool workable(Vector3f&);         // _168

	void beginPush();
	void endPush();
	void getZVector();
	void getXVector();
	void getPlaneFlag(Vector3f&);
	void updatePlanes();
	void getVertex(int);

	// unused/inlined:
	void getPlaneIndex(Vector3f&);
	void getTangentPos(f32);

	// _00      = VTBL
	// _00-_??? = WorkObject?
	// TODO: members
};

#endif
