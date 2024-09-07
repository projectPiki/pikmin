#ifndef _COLLISION_H
#define _COLLISION_H

#include "types.h"
#include "CoreNode.h"
#include "Vector.h"
#include "GfxObject.h"

struct CmdStream;
struct Creature;
struct DynCollObject;
struct ObjCollInfo;
struct Shape;
struct BaseShape;
struct RoomInfo;

/**
 * @brief TODO
 */
struct CollPart {
	CollPart();

	bool isStickable();
	bool isClimbable();
	bool isBouncy();
	int getChildCount();
	CollPart* getChild();
	CollPart* getChildAt(int);
	void getTypeString();
	void getID();
	void getCode();
	void getMatrix();
	void update(struct Graphics&, bool);
	void collide(CollPart*, struct Vector3f&);
	void makeTube(struct Tube&);

	// unused/inlined:
	bool isDamagable();
	CollPart* getNext();
	void collide(Creature*, Vector3f&);
	void collide(Vector3f&, f32, Vector3f&);
	void makeSphere(struct Sphere&);
	void makeCylinder(struct Cylinder&);
	void samePlatShape(Shape*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct CollPartUpdater {
	virtual void getPos()  = 0; // _08
	virtual void getSize() = 0; // _0C

	void updateCollPart(CollPart*);

	// _00 = VTBL?
	// TODO: members
};

/**
 * @brief TODO
 */
struct CndCollPart {
	virtual bool satisfy(CollPart*); // _08

	// _00 = VTBL?
	// TODO: members
};

enum ObjCollType {
	OCT_Sphere   = 1,
	OCT_Platform = 2,
};

enum ObjCollFlags {
	OCF_None    = 0,
	OCF_GetMinY = 1,
};

/**
 * @brief TODO
 */
struct ObjCollInfo : public CoreNode {
	ObjCollInfo()
	    : CoreNode("")
	{
		mId.setID('none');
		mCode.setID('none');
		mJointIndex = -1;
		mCollType   = OCT_Sphere;
		mRadius     = 10.0f;
		mCentrePosition.set(0.0f, 0.0f, 0.0f);
		mParentShape  = nullptr;
		mPlatformName = nullptr;
		_48           = 0;
		mFlags        = OCF_None;
	}

	void loadini(CmdStream*);

	// unused/inlined:
	void getCentreSize(Vector3f&, f32&);
	void showInfo(Graphics&, struct Matrix4f&);
	void saveini(char*, RandomAccessStream&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	ID32 mId;                 // _14
	ID32 mCode;               // _20
	ObjCollType mCollType;    // _2C
	s32 mJointIndex;          // _30
	Vector3f mCentrePosition; // _34
	f32 mRadius;              // _40
	BaseShape* mParentShape;  // _44
	s32 _48;                  // _48
	char* mPlatformName;      // _4C
	ObjCollFlags mFlags;      // _50
};

struct ShpobjInfo : public GfxobjInfo {
	Shape* mTarget; // _20
};

/**
 * @brief TODO
 */
struct CollInfo {
	CollInfo(int);

	void enableStick();
	void disableStick();
	void checkCollisionSpecial(Vector3f&, f32, CndCollPart*);
	void checkCollision(Creature*, Vector3f&);
	void checkCollisionRec(Creature*, int, Vector3f&);
	void checkCollision(CollInfo*, CollPart**, CollPart**, Vector3f&);
	void checkCollisionRec(CollInfo*, int, int, CollPart**, CollPart**, Vector3f&);
	void getBoundingSphere();
	CollPart* getSphere(u32 id);
	void getNearestCollPart(Vector3f&, u32);
	void getRandomCollPart(u32);
	void getPlatform(DynCollObject*);
	void updateInfo(Graphics&, bool);
	bool hasInfo();
	void initInfo(Shape*, CollPart*, u32*);
	void makeTubesChild(u32, int);
	void setUpdater(u32, CollPartUpdater*);
	void createPart(ObjCollInfo*, int, bool);
	void getId2Index(u32);
	void makeTree();

	// unused/inlined:
	void startUpdate(u32);
	void startUpdateRec(int);
	void stopUpdate(u32);
	void stopUpdateRec(int);
	void checkCollisionSpecialRec(int, Vector3f&, f32, CndCollPart*);
	void dumpInfo();
	void makeTubes(u32, int);
	void getIndex(ObjCollInfo*);

	u8 _00[0x14]; // _00, TODO: work out members;
};

/**
 * @brief TODO
 */
struct CollGroup {
};

/**
 * @brief TODO
 */
struct CollTriInfo {
	CollTriInfo();

	void init(RoomInfo*, Vector3f*);
	void behindEdge(Vector3f&);

	// TODO: members
};

#endif
