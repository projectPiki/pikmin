#ifndef _COLLISION_H
#define _COLLISION_H

#include "types.h"
#include "CoreNode.h"
#include "Vector.h"
#include "GfxObject.h"
#include "Geometry.h"
#include "Plane.h"
#include "Matrix4f.h"

struct CmdStream;
struct Creature;
struct DynCollObject;
struct DynCollShape;
struct ObjCollInfo;
struct CollInfo;
struct CollPart;
struct Shape;
struct BaseShape;
struct RoomInfo;
struct RigidBody;
struct Graphics;

/**
 * @brief TODO
 */
enum ObjCollType {
	OCT_Sphere   = 1,
	OCT_Platform = 2,
};

/**
 * @brief TODO
 */
enum ObjCollFlags {
	OCF_None    = 0,
	OCF_GetMinY = 1,
};

/**
 * @brief TODO
 */
enum CollPartType {
	PART_Collision   = 0,
	PART_BoundSphere = 1,
	PART_Reference   = 2,
	PART_Platform    = 3,
	PART_Cylinder    = 4,
	PART_Tube        = 5,
	PART_TubeChild   = 6,
};

/**
 * @brief TODO
 */
struct BaseRoomInfo {
	void read(RandomAccessStream& input) { _00 = input.readInt(); }

	int _00; // _00
};

/**
 * @brief TODO
 */
struct RoomInfo : public BaseRoomInfo {
	// _00-_04 = BaseRoomInfo
};

/**
 * @brief TODO
 *
 * @note Size: 0x54.
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
		mPlatShape    = 0;
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
	u32 mCollType;            // _2C, see ObjCollType enum
	s32 mJointIndex;          // _30
	Vector3f mCentrePosition; // _34
	f32 mRadius;              // _40
	BaseShape* mParentShape;  // _44
	Shape* mPlatShape;        // _48
	char* mPlatformName;      // _4C
	u32 mFlags;               // _50, see ObjCollFlags enum
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct CollPartUpdater {
	virtual Vector3f getPos() = 0; // _08
	virtual f32 getSize()     = 0; // _0C

	void updateCollPart(CollPart*);

	// _00 = VTBL
	ID32 _04; // _04
	ID32 _10; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x68.
 */
struct CollPart {
	CollPart();

	bool isStickable();
	bool isClimbable();
	bool isBouncy();
	int getChildCount();
	CollPart* getChild();
	CollPart* getChildAt(int);
	char* getTypeString();
	ID32 getID();
	ID32 getCode();
	Matrix4f getMatrix();
	void update(struct Graphics&, bool);
	bool collide(CollPart*, struct Vector3f&);
	void makeTube(struct Tube&);

	// unused/inlined:
	bool isDamagable();
	CollPart* getNext();
	bool collide(Creature*, Vector3f&);
	bool collide(Vector3f&, f32, Vector3f&);
	void makeSphere(struct Sphere&);
	void makeCylinder(struct Cylinder&);
	bool samePlatShape(Shape*);

	bool isTubeType() { return mPartType == PART_Tube || mPartType == PART_TubeChild; }
	bool isPlatformType() { return mPartType == PART_Platform; }
	bool isCollisionType() { return mPartType == PART_Collision; }
	bool isSphereType() { return mPartType == PART_BoundSphere; }
	bool isCylinderType() { return mPartType == PART_Cylinder; }
	bool isReferenceType() { return mPartType == PART_Reference; }
	bool isBouncySphereType() { return isSphereType() || isCollisionType(); }

	Matrix4f getJointMatrix() { return mJointMatrix; }

	/*
	    No more DLL inlines to make
	*/

	f32 mRadius;                   // _00
	Vector3f mCentre;              // _04
	Matrix4f mJointMatrix;         // _10
	bool mIsUpdateActive;          // _50
	bool mIsStickEnabled;          // _51
	s16 mNextIndex;                // _52, index of next sibling
	s16 mFirstChildIndex;          // _54, index of first child
	ObjCollInfo* mCollInfo;        // _58
	u8 mPartType;                  // _5C
	CollInfo* mParentInfo;         // _60
	CollPartUpdater* mPartUpdater; // _64
};

/**
 * @brief TODO
 */
struct CollEvent {
	CollEvent(Creature* collider, CollPart* colliderPart, CollPart* selfPart)
	{
		mCollider     = collider;
		mColliderPart = colliderPart;
		mSelfPart     = selfPart;
	}

	Creature* mCollider;     // _00
	CollPart* mColliderPart; // _04
	CollPart* mSelfPart;     // _08
};

/**
 * @brief TODO
 */
struct CndCollPart {
	virtual bool satisfy(CollPart*) { return false; } // _08

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct CndBombable : public CndCollPart {
	virtual bool satisfy(CollPart* part) // _08 (weak)
	{
		if (part && part->getCode().match('**b*', '*')) {
			return true;
		}
		return false;
	}

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct CollInfo {
	CollInfo(int);

	void enableStick();
	void disableStick();
	CollPart* checkCollisionSpecial(Vector3f&, f32, CndCollPart*);
	CollPart* checkCollision(Creature*, Vector3f&);
	CollPart* checkCollisionRec(Creature*, int, Vector3f&);
	bool checkCollision(CollInfo*, CollPart**, CollPart**, Vector3f&);
	bool checkCollisionRec(CollInfo*, int, int, CollPart**, CollPart**, Vector3f&);
	CollPart* getBoundingSphere();
	CollPart* getSphere(u32 id);
	CollPart* getNearestCollPart(Vector3f&, u32);
	CollPart* getRandomCollPart(u32);
	CollPart* getPlatform(DynCollObject*);
	void updateInfo(Graphics&, bool);
	bool hasInfo();
	void initInfo(Shape*, CollPart*, u32*);
	void makeTubesChild(u32, int);
	void setUpdater(u32, CollPartUpdater*);
	void createPart(ObjCollInfo*, int, bool);
	int getId2Index(u32);
	void makeTree();

	// unused/inlined:
	void startUpdate(u32);
	void startUpdateRec(int);
	void stopUpdate(u32);
	void stopUpdateRec(int);
	CollPart* checkCollisionSpecialRec(int, Vector3f&, f32, CndCollPart*);
	void dumpInfo();
	void makeTubes(u32, int);
	int getIndex(ObjCollInfo*);

	u8 mUseDefaultMaxParts; // _00
	CollPart* mCollParts;   // _04, array of size mMaxParts
	u32* mPartIDs;          // _08, array of size mMaxParts
	u16 mPartsCount;        // _0C, number of parts in array
	u16 mMaxParts;          // _0E, max size of arrays
	Shape* mShape;          // _10
};

/**
 * @brief TODO
 */
struct BaseCollTriInfo {

	void read(RandomAccessStream& input)
	{
		mMapCode               = input.readInt();
		mVertexIndices[0]      = input.readInt();
		mVertexIndices[1]      = input.readInt();
		mVertexIndices[2]      = input.readInt();
		mCollRoomId            = input.readShort();
		mAdjacentTriIndices[0] = input.readShort();
		mAdjacentTriIndices[1] = input.readShort();
		mAdjacentTriIndices[2] = input.readShort();
		mTriangle.read(input);
	}

	u32 mMapCode;               // _00
	u32 mVertexIndices[3];      // _04
	s16 mCollRoomId;            // _10
	s16 mAdjacentTriIndices[3]; // _12
	Plane mTriangle;            // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct CollTriInfo : public BaseCollTriInfo {
	CollTriInfo();

	void init(RoomInfo*, Vector3f*);
	int behindEdge(Vector3f&);

	bool inTriClampTo(Vector3f& pos)
	{
		pos.y      = -(pos.x * mTriangle.mNormal.x + pos.z * mTriangle.mNormal.z - mTriangle.mOffset) / mTriangle.mNormal.y;
		bool inTri = true;
		for (int i = 0; inTri && i < 3; i++) {
			f32 dist = mEdgePlanes[i].dist(pos);
			if (dist < 0.0f) {
				inTri = false;
			}
		}
		return inTri;
	}

	// _00-_28 = BaseCollTriInfo
	Plane mEdgePlanes[3]; // _28
};

/**
 * @brief TODO
 */
struct CollGroup {
	CollGroup()
	{
		mTriangleList = nullptr;
		mTriCount     = 0;
		mStateIndex   = 0;
		mFarCulledTriDistances           = nullptr;
	}

	u8 _00[0x4];                   // _00, unknown
	s16 mTriCount;                 // _04
	s16 mFarCulledTriCount;        // _06
	CollTriInfo** mTriangleList;   // _08
	u8* mFarCulledTriDistances;                       // _0C
	Shape* mShape;                 // _10
	Vector3f* mVertexList;         // _14
	int mStateIndex;               // _18
	DynCollShape* mSourceCollider; // _1C
	CollGroup* mNextCollider;      // _20
};

/**
 * @brief TODO
 */
struct Collision {
	Collision() { }

	u8 _00[0x4];            // _00, unknown
	Vector3f mNormal;       // _04
	Vector3f mContactPoint; // _10
	RigidBody* _1C;         // _1C
	u8 _20[0x4];            // _20, unknown
};

/**
 * @brief TODO
 */
struct CollState {
	CollState()
	{
		_00 = 2;
		_04 = 0.0001f;
		_08 = 0;
		_0C = 0;
	}

	// unused/inlined:
	void resetCollisions(Shape*);
	bool add(Vector3f&, Vector3f&, RigidBody*);

	int _00;                   // _00
	f32 _04;                   // _04
	u32 _08;                   // _08, unknown
	int _0C;                   // _0C
	int mCollisionCount;       // _10
	Collision mCollisions[10]; // _14
	Shape* mShape;             // _17C
};

#endif
