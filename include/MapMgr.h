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

/**
 * @brief TODO
 */
struct MoveTrace {
	MoveTrace(Vector3f& position, Vector3f& velocity, f32 height, bool p4)
	{
		_20       = p4;
		mPosition = position;
		mVelocity = velocity;
		mHeight   = height;
		_24       = 0;
		_1C       = 1.0f;
	}

	Vector3f mPosition; // _00
	Vector3f mVelocity; // _0C
	f32 mHeight;        // _18
	f32 _1C;            // _1C
	bool _20;           // _20
	u32 _24;            // _24, unknown
};

/**
 * @brief TODO
 */
struct MapObjAnimator : public Animator {
	virtual void finishOneShot(); // _10

	// _30     = VTBL
	// _00-_34 = Animator
	// TODO: members
};

/**
 * @brief Stripped struct used in one ctor, but needed for genning a weak ctor
 */
struct MapAnimShapeObject : public Shape { };

/**
 * @brief TODO
 */
struct MapShadMatHandler : public MaterialHandler {
	virtual void setMaterial(Material*); // _08

	// _00     = VTBL?
	// _00-_?? = MaterialHandler?
	// TODO: members
};

/**
 * @brief TODO
 */
struct MapProjMatHandler : public MaterialHandler {
	virtual void setMaterial(Material*); // _08
	virtual void setTexMatrix(bool);     // _0C

	// _00     = VTBL?
	// _00-_?? = MaterialHandler?
	// TODO: members
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
struct DynMapObject : public DynCollShape {
	DynMapObject(MapMgr*, MapAnimShapeObject*);

	virtual void update();                                    // _10
	virtual void draw(Graphics&);                             // _14
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _38
	virtual void refresh(Graphics&);                          // _44

	void nextState();

	// _00     = VTBL
	// _00-_?? = DynCollShape
	// TODO: members
};

/**
 * @brief TODO
 */
struct MapObjectPart : public DynCollShape {
	MapObjectPart() // TODO: fix this, it's implicit but required/this is just a guess
	    : DynCollShape(nullptr)
	{
	}

	virtual void update();                                    // _10
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _38
	virtual void refresh(Graphics&);                          // _44

	// _00     = VTBL
	// _00-_?? = DynCollShape
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct MapPartsPart {
	// Fabricated.

	Vector3f mStartPosition; // _00
	Vector3f _0C;            // _0C
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
	int _160;                 // _160
	int _164;                 // _164
	f32 _168;                 // _168
	f32 _16C;                 // _16C
	f32 _170;                 // _170
	int _174;                 // _174
	int _178;                 // _178
	int _17C;                 // _17C
	f32 _180;                 // _180
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct MapRoom {
	MapRoom();

	f32 _00; // _00
	f32 _04; // _04
	u32 _08; // _08, unknown
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
	u8 _18[0x60 - 0x18];                   // _18, unknown
	Shape* _60;                            // _60
	ShapeDynMaterials mDynMaterials;       // _64
	BaseShape* mMapPartShapes[5];          // _74
	DynCollShape* mCollShape;              // _88
	u8 _8C[0x4];                           // _8C, unknown
	BoundBox _90;                          // _90
	u8 _A8[0xB4 - 0xA8];                   // _A8, unknown
	Vector3f _B4;                          // _B4
	BoundBox _C0;                          // _C0
	BoundBox _D8;                          // _D8
	u8 _F0[0x114 - 0xF0];                  // _F0, unknown
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
