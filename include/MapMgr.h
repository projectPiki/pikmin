#ifndef _MAPMGR_H
#define _MAPMGR_H

#include "types.h"
#include "Animator.h"
#include "Shape.h"
#include "DynColl.h"
#include "Material.h"

struct Controller;
struct CreatureCollPart;
struct DayMgr;
struct DynMapObject;
struct DynSimulator;
struct MapObjectPart;

/**
 * @brief TODO
 */
struct MoveTrace {
	MoveTrace(Vector3f& position, Vector3f& velocity, f32 radius, bool p4)
	{
		_20           = p4;
		mPosition     = position;
		mVelocity     = velocity;
		mRadius       = radius;
		mObject       = nullptr;
		mStepFraction = 1.0f;
	}

	Vector3f mPosition; // _00
	Vector3f mVelocity; // _0C
	f32 mRadius;        // _18
	f32 mStepFraction;  // _1C
	bool _20;           // _20
	Creature* mObject;  // _24, the thing moving
};

/**
 * @brief Stripped struct used in one ctor, but needed for genning a weak ctor
 */
struct MapAnimShapeObject {
	Shape* mShape;            // _00
	AnimContext mAnimContext; // _04
	AnimMgr* mMgr;            // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct MapShadMatHandler : public MaterialHandler {
	MapShadMatHandler()
	{
		mShadMat = new Material();
		mShadMat->Colour().set(255, 255, 255, 255);
	}

	virtual void setMaterial(Material*); // _08

	// _00     = VTBL
	// _00-_08 = MaterialHandler
	Material* mShadMat; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct MapProjMatHandler : public MaterialHandler {
	MapProjMatHandler(Texture* tex)
	{
		_0C           = nullptr;
		mProjMat      = new Material();
		mProjMat->_24 = tex;
		mProjMat->Colour().set(128, 128, 128, 32);
	}

	virtual void setMaterial(Material*); // _08
	virtual void setTexMatrix(bool);     // _0C

	// _00     = VTBL
	// _00-_08 = MaterialHandler
	Material* mProjMat; // _08
	u32 _0C;            // _0C, unknown
};

/**
 * @brief TODO
 */
struct SoftLight {
	void addLight(u32, LShortColour*, Shape*);
	void subLight(LShortColour*);

	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x394.
 */
struct ShadowCaster : public CoreNode {
	ShadowCaster();

	void initShadow();

	// _00     = VTBL
	// _00-_14 = CoreNode
	LightCamera mLightCamera; // _14
	Vector3f mSourcePosition; // _37C
	Vector3f mTargetPosition; // _388
};

/**
 * @brief TODO
 */
struct MapObjAnimator : public Animator {
	virtual void finishOneShot(); // _10

	// _30     = VTBL
	// _00-_34 = Animator
	DynMapObject* mMapObj; // _34
};

/**
 * @brief TODO
 */
struct DynMapObject : public DynCollShape {
	DynMapObject(MapMgr*, MapAnimShapeObject*);

	virtual void update();                                    // _10
	virtual void draw(Graphics&);                             // _14
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _38
	virtual void refresh(Graphics&);                          // _44

	void nextState();

	// _00     = VTBL
	// _00-_140 = DynCollShape
	MapAnimShapeObject* mShapeObject; // _140
	MapObjAnimator mAnimator;         // _144
	MapMgr* mMapMgr;                  // _17C
	ShadowCaster mShadowCaster;       // _180
	DynMapObject* _514;               // _514
	int mState;                       // _518
	f32 _51C;                         // _51C
	Vector3f mMapScale;               // _520, this is an SRT according to the DLL
	Vector3f mMapRotation;            // _52C
	Vector3f mMapTranslation;         // _538
	int mObjPartCount;                // _544
	MapObjectPart** mObjParts;        // _548
};

/**
 * @brief TODO
 */
struct MapObjectPart : public DynCollShape {
	MapObjectPart(Shape* shape)
	    : DynCollShape(shape)
	{
		_140 = 0;
		_144 = 0;
	}

	virtual void update();                                    // _10
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _38
	virtual void refresh(Graphics&);                          // _44

	// _00     = VTBL
	// _00-_140 = DynCollShape
	int _140;           // _140
	DynMapObject* _144; // _144 might be wrong
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct MapPartsPart {
	// Fabricated.

	Vector3f mStartPosition; // _00
	Vector3f mEndPosition;   // _0C
};

/**
 * @brief TODO
 */
struct MapParts : public DynCollShape {
	MapParts(Shape* shape)
	    : DynCollShape(shape)
	{
		mCurrentPart = nullptr;
	}

	virtual void read(RandomAccessStream&) { }                // _0C
	virtual void update() { }                                 // _10
	virtual void applyVelocity(Plane&, Vector3f&, Vector3f&); // _34
	virtual void init() { }                                   // _48

	static char* getShapeFile(int);

	static char* shapeFiles[4];

	// _00      = VTBL
	// _00-_140 = DynCollShape
	MapPartsPart* mCurrentPart; // _140
	Vector3f mVelocity;         // _144
};

/**
 * @brief TODO
 */
struct MapEntity : public MapParts {
	MapEntity(Shape*);

	virtual void update(); // _10

	// _00      = VTBL
	// _00-_150 = MapParts
	// TODO: members
};

/**
 * @brief TODO
 */
struct MapSlider : public MapParts {
	MapSlider(Shape*, int, int, f32, f32, f32, int);

	virtual void update();           // _10
	virtual void refresh(Graphics&); // _44
	virtual void init();             // _48

	// _00      = VTBL
	// _00-_150 = MapParts
	Vector3f mSliderPosition; // _150
	f32 mFaceDirection;       // _15C
	int mActivationCount;     // _160
	int mTriggerCount;        // _164
	f32 mHoldTime1;           // _168
	f32 mHoldTime2;           // _16C
	f32 mMoveSpeed;           // _170
	int mMoveMode;            // _174
	int mStateMode;           // _178
	int mDirectionMode;       // _17C
	f32 mCurrentTimer;        // _180
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct MapRoom {
	MapRoom()
	{
		_08 = 0;
		_04 = 1.0f;
		_00 = 1.0f;
	}

	f32 _00; // _00
	f32 _04; // _04
	u32 _08; // _08, unknown
};

/**
 * @brief TODO
 *
 * @note Fabricated. Has to be this structure, but no idea what it was called. Has no ctor.
 * @note Size: 0xC.
 */
struct MapColls {
	CollGroup* mCollisions; // _00
	CollTriInfo* mTriangle; // _04
	int _08;                // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x4D4.
 */
struct MapMgr {
	MapMgr(Controller*);

	void initEffects();
	void initShape();
	void createLights();
	void updateSimulation();
	void update();
	void preRender(Graphics&);
	void drawShadowCasters(Graphics&);
	void refresh(Graphics&);
	void showCollisions(Vector3f&);
	void drawXLU(Graphics&);
	void postrefresh(Graphics&);
	void updatePos(f32, f32);
	f32 getLight(f32, f32);
	CollGroup* getCollGroupList(f32, f32, bool);
	f32 getMinY(f32, f32, bool);
	f32 getMaxY(f32, f32, bool);
	CollTriInfo* getCurrTri(f32, f32, bool);
	f32 findEdgePenetration(CollTriInfo&, Vector3f*, Vector3f&, f32, Vector3f&);
	void recTraceMove(CollGroup*, MoveTrace&, f32);
	void traceMove(Creature*, MoveTrace&, f32);
	Shape* loadPlatshape(char*);
	CreatureCollPart* requestCollPart(ObjCollInfo*, Creature*);

	// unused/inlined:
	bool closeCollTri(CollGroup*, CollTriInfo*);

	Controller* mController;               // _00
	DayMgr* mDayMgr;                       // _04
	Vector3f _08;                          // _08
	MapRoom* mMapRooms;                    // _14, array of 256 MapRooms
	int _18;                               // _18
	int _1C;                               // _1C
	u8 _20[0x60 - 0x20];                   // _20, unknown
	Shape* mMapShape;                      // _60
	ShapeDynMaterials mDynMaterials;       // _64
	BaseShape* mMapPartShapes[5];          // _74
	DynCollShape* mCollShape;              // _88
	u32 _8C;                               // _8C, unknown
	BoundBox _90;                          // _90
	u32 _A8;                               // _A8, unknown
	u8 _AC[0x4];                           // _AC, unknown
	int _B0;                               // _B0
	Vector3f _B4;                          // _B4
	BoundBox _C0;                          // _C0
	BoundBox _D8;                          // _D8
	MapColls* mCollisions;                 // _F0
	f32 _F4;                               // _F4
	f32 _F8;                               // _F8
	f32 _FC;                               // _FC
	f32 _100;                              // _100
	u8 _104;                               // _104
	DynSimulator* mDynSimulator;           // _108
	int mCollisionCheckCount;              // _10C
	int _110;                              // _110, unknown
	ShadowCaster mShadowCaster;            // _114
	u8 _4A8[0x4];                          // _4A8, unknown
	MapShadMatHandler* mMapShadMatHandler; // _4AC
	MapProjMatHandler* mMapProjMatHandler; // _4B0
	Texture* _4B4;                         // _4B4
	Texture* _4B8;                         // _4B8
	int mBlur;                             // _4BC
	f32 _4C0;                              // _4C0
	f32 _4C4;                              // _4C4
	f32 _4C8;                              // _4C8
	f32 _4CC;                              // _4CC
	CreatureCollPart* _4D0;                // _4D0
};

extern MapMgr* mapMgr;

#endif
