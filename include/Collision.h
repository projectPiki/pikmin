#ifndef _COLLISION_H
#define _COLLISION_H

#include "CoreNode.h"
#include "Geometry.h"
#include "GfxObject.h"
#include "Matrix4f.h"
#include "Plane.h"
#include "Vector.h"
#include "types.h"

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
 * @brief Collision-info node type.
 */
enum ObjCollType {
	OCT_Sphere   = 1, // sphere collision primitive
	OCT_Platform = 2, // platform collision (references an external Shape by name)
};

/**
 * @brief Collision-info flags.
 * @note In practice, any nonzero flag is used as a boolean when creating platform Shapes.
 */
enum ObjCollFlags {
	OCF_None    = 0,
	OCF_GetMinY = 1, // set by "getminy" token in ObjCollInfo ini
};

/**
 * @brief Runtime CollPart classification.
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
 * @brief Minimal room identifier parsed from a stream.
 */
struct BaseRoomInfo {
	void read(RandomAccessStream& input) { mIndex = input.readInt(); }

	int mIndex; // _00, room index
};

/**
 * @brief Room descriptor (currently identical to BaseRoomInfo).
 */
struct RoomInfo : public BaseRoomInfo {
	// _00-_04 = BaseRoomInfo
};

/**
 * @brief Collision description node attached to a Shape.
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

	void loadini(CmdStream* cmdStream);

	// unused/inlined:
	void getCentreSize(Vector3f& centre, f32& radius);
	void showInfo(Graphics& gfx, Matrix4f& mtx);
	void saveini(immut char* path, RandomAccessStream& output);

	// _00     = VTBL
	// _00-_14 = CoreNode
	ID32 mId;                  // _14, ID/tag
	ID32 mCode;                // _20, gameplay code/tag
	u32 mCollType;             // _2C, collision-info type (see ObjCollType)
	s32 mJointIndex;           // _30, joint index for parent-shape transforms (-1 for identity)
	Vector3f mCentrePosition;  // _34, local centre position
	f32 mRadius;               // _40, base radius (scaled by joint/world position)
	BaseShape* mParentShape;   // _44, owning shape used for joint matrices
	Shape* mPlatShape;         // _48, resolved platform shape (OCT_Platform)
	immut char* mPlatformName; // _4C, platform shape name (OCT_Platform)
	u32 mFlags;                // _50, flags (see ObjCollFlags; treated as bool)
};

/**
 * @brief Provides runtime position/size updates for a CollPart.
 *
 * @note Size: 0x1C.
 */
struct CollPartUpdater {
	virtual Vector3f getPos() = 0; // _08
	virtual f32 getSize()     = 0; // _0C

	void updateCollPart(CollPart* part);

	// _00 = VTBL
	ID32 _04; // _04, unused
	ID32 _10; // _10, unused
};

/**
 * @brief Runtime collision part built from an ObjCollInfo tree.
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
	immut char* getTypeString();
	ID32 getID();
	ID32 getCode();
	Matrix4f getMatrix();
	void update(Graphics& gfx, bool drawDebug);
	bool collide(CollPart* otherPart, Vector3f& pushVector);
	void makeTube(Tube& tube);

	// unused/inlined:
	bool isDamagable();
	CollPart* getNext();
	bool collide(Creature* collider, Vector3f& pushVector);
	bool collide(immut Vector3f& pos, f32 radius, Vector3f& pushVector);
	void makeSphere(Sphere& sphere);
	void makeCylinder(Cylinder& cylinder);
	bool samePlatShape(Shape* shape);

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

	f32 mRadius;                   // _00, world-space radius
	Vector3f mCentre;              // _04, world-space centre
	Matrix4f mJointMatrix;         // _10, joint matrix (from parent shape)
	bool mIsUpdateActive;          // _50, enables/disables update() for this part
	bool mIsStickEnabled;          // _51, global stick enable for this part
	s16 mNextIndex;                // _52, index of next sibling part (-1 if none)
	s16 mFirstChildIndex;          // _54, index of first child part (-1 if none)
	ObjCollInfo* mCollInfo;        // _58, source collision-info node
	u8 mPartType;                  // _5C, part type (see CollPartType)
	CollInfo* mParentInfo;         // _60, owning CollInfo (for resolving indices to pointers)
	CollPartUpdater* mPartUpdater; // _64, optional runtime updater (overrides shape-based update)
};

/**
 * @brief Collision event payload linking a collider to the parts involved.
 */
struct CollEvent {
	CollEvent(Creature* collider, CollPart* colliderPart, CollPart* selfPart)
	{
		mCollider     = collider;
		mColliderPart = colliderPart;
		mSelfPart     = selfPart;
	}

	Creature* mCollider;     // _00, colliding creature
	CollPart* mColliderPart; // _04, collider's colliding part (if applicable)
	CollPart* mSelfPart;     // _08, this object's colliding part
};

/**
 * @brief Predicate interface for filtering collision parts.
 */
struct CndCollPart {
	virtual bool satisfy(CollPart*) { return false; } // _08

	// _00 = VTBL
};

/**
 * @brief Condition that matches parts tagged as bombable.
 * @note Uses a code pattern of "**b*" (i.e. the 3rd character is 'b').
 */
struct CndBombable : public CndCollPart {
	virtual bool satisfy(CollPart* part) // _08 (weak)
	{
		if (part && part->getCode().match('**b*')) {
			return true;
		}
		return false;
	}

	// _00 = VTBL
};

/**
 * @brief Collection of CollParts generated from a Shape's ObjCollInfo tree.
 *
 * @note Size: 0x14.
 */
struct CollInfo {
	friend struct CollPart; // Accesses `mCollParts` in `CollPart::getChild`/`getChildAt`/`getNext`.

public:
	CollInfo(int);

	void enableStick();
	void disableStick();
	CollPart* checkCollisionSpecial(immut Vector3f& pos, f32 radius, CndCollPart* condition);
	CollPart* checkCollision(Creature* creature, Vector3f& pushVector);
	bool checkCollision(CollInfo* otherInfo, CollPart** outPartA, CollPart** outPartB, Vector3f& pushVector);
	CollPart* getBoundingSphere();
	CollPart* getSphere(u32 id);
	CollPart* getNearestCollPart(immut Vector3f& pos, u32 tag);
	CollPart* getRandomCollPart(u32 tag);
	CollPart* getPlatform(DynCollObject*);
	void updateInfo(Graphics& gfx, bool drawDebug);
	bool hasInfo();
	void initInfo(Shape*, CollPart*, u32*);
	void makeTubesChild(u32, int);
	void setUpdater(u32, CollPartUpdater*);
	void dumpInfo();
	void makeTubes(u32, int);

	// unused/inlined:
	void startUpdate(u32);
	void stopUpdate(u32);

private:
	void startUpdateRec(int);
	void stopUpdateRec(int);
	CollPart* checkCollisionSpecialRec(int, immut Vector3f&, f32, CndCollPart*);
	CollPart* checkCollisionRec(Creature*, int, Vector3f&);
	bool checkCollisionRec(CollInfo*, int, int, CollPart**, CollPart**, Vector3f&);
	void createPart(ObjCollInfo* objInfo, int depth, bool forceCollision);
	int getId2Index(u32);
	int getIndex(ObjCollInfo*);
	void makeTree();

	bool mUseDefaultMaxParts; // _00, whether to use a default max parts count
	CollPart* mCollParts;     // _04, array of size mMaxParts
	u32* mPartIDs;            // _08, array of size mMaxParts
	u16 mPartsCount;          // _0C, number of parts in array
	u16 mMaxParts;            // _0E, max size of arrays
	Shape* mShape;            // _10, owning shape
};

/**
 * @brief Serialized triangle collision info.
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

	u32 mMapCode;               // _00, map attribute code (see MapAttributes in MapCode.h)
	u32 mVertexIndices[3];      // _04, indices into a vertex array
	s16 mCollRoomId;            // _10, room id associated with this triangle
	s16 mAdjacentTriIndices[3]; // _12, adjacency indices for triangle neighbors
	Plane mTriangle;            // _18, triangle plane
};

/**
 * @brief Triangle collision info with derived edge planes.
 *
 * @note Size: 0x58.
 */
struct CollTriInfo : public BaseCollTriInfo {
	CollTriInfo() { }

	void init(RoomInfo* roomInfo, immut Vector3f* vertices);
	int behindEdge(immut Vector3f& point);

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
	Plane mEdgePlanes[3]; // _28, edge half-space planes derived from triangle vertices
};

/**
 * @brief Group of collision triangles for a Shape.
 */
struct CollGroup {
	CollGroup()
	{
		mTriangleList          = nullptr;
		mTriCount              = 0;
		mRoomIndex             = 0;
		mFarCulledTriDistances = nullptr;
	}

	u8 _00[0x4];                   // _00, unknown
	s16 mTriCount;                 // _04, number of triangles
	s16 mFarCulledTriCount;        // _06, number of far-culled triangles
	CollTriInfo** mTriangleList;   // _08, list of triangle pointers
	u8* mFarCulledTriDistances;    // _0C, per-triangle distance metadata (far culling)
	Shape* mShape;                 // _10, owning shape
	Vector3f* mVertexList;         // _14, vertex array for triangle indices
	int mRoomIndex;                // _18, room index for this group
	DynCollShape* mSourceCollider; // _1C, source dynamic collider
	CollGroup* mNextCollider;      // _20, linked-list next
};

/**
 * @brief Single collision contact.
 */
struct Collision {
	Collision() { }

	u8 _00[0x4];            // _00, unknown
	Vector3f mNormal;       // _04, contact normal
	Vector3f mContactPoint; // _10, contact point
	RigidBody* mColliderRb; // _1C, collider rigid body
	u8 _20[0x4];            // _20, unknown
};

/**
 * @brief Fixed-size list of recent collision contacts.
 */
struct CollState {
	CollState()
	{
		mStatus     = 2;
		_04         = 0.0001f;
		_08         = 0;
		mResetCount = 0;
	}

	// unused/inlined:
	void resetCollisions(Shape* shape);
	bool add(immut Vector3f& normal, immut Vector3f& contactPt, RigidBody* collider);

	int mStatus;               // _00, state/status flag (set to 2 on reset, 1 when adding)
	f32 _04;                   // _04, unknown (initialized to 0.0001f)
	u32 _08;                   // _08, unknown 
	int mResetCount;           // _0C, number of times resetCollisions() has been called
	int mCollisionCount;       // _10, number of valid entries in mCollisions
	Collision mCollisions[10]; // _14, fixed-size contact list
	Shape* mShape;             // _17C, shape associated with the current collision set
};

#endif
