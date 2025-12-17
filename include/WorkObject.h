#ifndef _WORKOBJECT_H
#define _WORKOBJECT_H

#include "ItemMgr.h"
#include "ObjectMgr.h"
#include "Plane.h"
#include "Route.h"
#include "Shape.h"
#include "UtEffect.h"
#include "types.h"

struct DynBuildShape;

/**
 * @brief TODO
 */
struct WorkObject : public ItemCreature {
	WorkObject(); // unused/inlined

	virtual bool isVisible() { return true; }               // _74
	virtual bool isAlive() { return true; }                 // _88
	virtual void doKill();                                  // _10C
	virtual void finalSetup() { }                           // _158
	virtual bool isBridge() { return false; }               // _15C
	virtual bool isHinderRock() { return false; }           // _160
	virtual bool isFinished() { return false; }             // _164
	virtual bool workable(immut Vector3f&) { return true; } // _168

	// _00      = VTBL
	// _00-_3C8 = ItemCreature
};

/**
 * @brief TODO
 */
struct WorkObjectNode : public CoreNode {
	WorkObjectNode()
	    : CoreNode("wo")
	{
	}

	WorkObjectNode(WorkObject* object)
	    : mObject(object)
	{
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	WorkObject* mObject; // _14
};

/**
 * @brief TODO
 */
struct WorkObjectMgr : public ObjectMgr {
public:
	WorkObjectMgr();

	virtual Creature* getCreature(int);      // _08
	virtual int getFirst();                  // _0C
	virtual int getNext(int);                // _10
	virtual bool isDone(int);                // _14
	virtual ~WorkObjectMgr() { }             // _48
	virtual int getSize();                   // _60
	virtual int getMax() { return 0x10000; } // _64

	void finalSetup();
	void loadShapes();
	Creature* birth(int, int);

	// unused/inlined:
	static int getNameIndex(immut char*);
	static immut char* getName(int);
	static int getShapeNameIndex(immut char*);
	static immut char* getShapeName(int);
	void addUseList(int);

protected:
	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_28 = ObjectMgr
	WorkObjectNode mRootNode;   // _28
	Shape** mItemShapes;        // _40, array of 5 shapes
	bool* mShouldThisShapeLoad; // _44, array of 5 bools
};

/**
 * @brief TODO
 *
 * @note Size: 0x428.
 */
struct Bridge : public WorkObject {
public:
	Bridge(Shape*, bool);

	virtual bool insideSafeArea(immut Vector3f&);             // _10
	virtual void startAI(int);                                // _34
	virtual void doSave(RandomAccessStream&);                 // _50
	virtual void doLoad(RandomAccessStream&);                 // _54
	virtual bool stimulate(immut Interaction&);               // _A0
	virtual void dump();                                      // _C8
	virtual void update();                                    // _E0
	virtual void refresh(Graphics&);                          // _EC
	virtual bool isFinished();                                // _164
	virtual bool workable(immut Vector3f&);                   // _168
	virtual bool isBridge() { return true; }                  // _15C
	virtual bool alwaysUpdatePlatform() { return _424 != 0; } // _18
	virtual void finalSetup() { _424 = 3; }                   // _158

	int getStage() { return mStageCount; }

	int getFirstUnfinishedStage();
	int getFirstFinishedStage();
	bool isStageFinished(int);
	void flatten();
	void setStageFinished(int, bool);
	Vector3f getStagePos(int);
	f32 getStageZ(int);
	void getBridgePos(immut Vector3f&, f32&, f32&);
	Vector3f getBridgeZVec();
	Vector3f getBridgeXVec();
	Vector3f getStartPos();
	f32 getStageDepth();
	f32 getStageWidth();
	void startStageFinished(int, bool);

protected:
	int getJointIndex(int);

	// This class requires 7 friend classes in order for it to be "encapsulated".  Yeah, no.
public:
	// _00      = VTBL
	// _00-_3C8 = WorkObject
	bool mDoUseJointSegments;       // _3C8
	s16 _3CA;                       // _3CA
	u8 _3CC;                        // _3CC
	f32* mStageProgressList;        // _3D0, stage items?
	Joint** mStageJoints;           // _3D4, unknown
	PermanentEffect _3D8;           // _3D8
	PermanentEffect _3E8;           // _3E8
	WayPoint* mStartWaypoint;       // _3F8
	WayPoint* mEndWaypoint;         // _3FC
	u8 _400;                        // _400
	int mStageCount;                // _404
	DynBuildShape* mBuildShape;     // _408
	Shape* mBridgeShape;            // _40C
	CollPart* _410;                 // _410
	ShapeDynMaterials mDynMaterial; // _414
	u8 _424;                        // _424, flags (3 = final setup)
};

/**
 * @brief TODO
 *
 * @note Size: 0x478.
 */
struct HinderRock : public WorkObject {
public:
	HinderRock(Shape*);

	virtual bool insideSafeArea(immut Vector3f&); // _10
	virtual void startAI(int);                    // _34
	virtual void doSave(RandomAccessStream&);     // _50
	virtual void doLoad(RandomAccessStream&);     // _54
	virtual f32 getCentreSize();                  // _5C
	virtual bool stimulate(immut Interaction&);   // _A0
	virtual void update();                        // _E0
	virtual void refresh(Graphics&);              // _EC
	virtual bool isHinderRock() { return true; }  // _160
	virtual bool isFinished();                    // _164
	virtual bool workable(immut Vector3f&);       // _168

	void beginPush();
	void endPush();
	Vector3f getZVector();
	Vector3f getXVector();
	u8 getPlaneFlag(immut Vector3f&);
	Vector3f getVertex(int);

	// unused/inlined:
	int getPlaneIndex(immut Vector3f&);
	Vector3f getTangentPos(f32);

	bool isMoving() { return mIsMoving; }

protected:
	void updatePlanes();

	// This class only needs 2 friends but idc at this point.
public:
	// _00      = VTBL
	// _00-_3C8 = WorkObject
	u16 mPushingPikmin;            // _3C8
	Plane mPlanes[4];              // _3CC
	Vector3f mDestinationPosition; // _40C
	int mTotalPushStrength;        // _418
	int mAmountPushersToStart;     // _41C
	f32 mPushSpeed;                // _420
	WayPoint* mWayPoint;           // _424
	u8 _428;                       // _428
	f32 _42C;                      // _42C
	f32 mCentreSize;               // _430
	DynBuildShape* mBuildShape;    // _434
	Shape* mBoxShape;              // _438
	u8 mState;                     // _43C
	u8 mFxCooldownTimer;           // _43D
	f32 mPushMoveTimer;            // _440
	bool mIsMoving;                // _444
	bool mIsSoundPlaying;          // _445
	zen::particleGenerator* mEfxA; // _448
	zen::particleGenerator* mEfxB; // _44C
	zen::particleGenerator* mEfxC; // _450
	Vector3f mMoveFrontEfxPos;     // _454
	Vector3f mMoveSideEfxPos[2];   // _460
};

extern WorkObjectMgr* workObjectMgr;

#endif
