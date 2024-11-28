#ifndef _MAPMGR_H
#define _MAPMGR_H

#include "types.h"
#include "Animator.h"
#include "Shape.h"
#include "DynColl.h"
#include "Material.h"

struct Controller;
struct CreatureCollPart;
struct MoveTrace;

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
struct MapAnimShapeObject : public Shape {
};

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
 */
struct ShadowCaster : public CoreNode {
	ShadowCaster();

	void initShadow();

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
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
 */
struct MapParts : public DynCollShape {
	MapParts(Shape* shape)
	    : DynCollShape(shape)
	{
		_140 = nullptr;
	}

	virtual void read(RandomAccessStream&);                   // _0C
	virtual void update();                                    // _10
	virtual void applyVelocity(Plane&, Vector3f&, Vector3f&); // _34
	virtual void init();                                      // _48

	static char* getShapeFile(int);

	static char* shapeFiles[4];

	// _00      = VTBL
	// _00-_140 = DynCollShape
	Vector3f* _140; // _140, may also be a ptr to a struct with a Vector3f at _00.
	Vector3f _144;  // _144
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
	Vector3f _150; // _150
	f32 _15C;      // _15C
	int _160;      // _160
	int _164;      // _164
	f32 _168;      // _168
	f32 _16C;      // _16C
	f32 _170;      // _170
	int _174;      // _174
	int _178;      // _178
	int _17C;      // _17C
	f32 _180;      // _180
};

/**
 * @brief TODO
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
	void getLight(f32, f32);
	void getCollGroupList(f32, f32, bool);
	f32 getMinY(f32, f32, bool);
	void getMaxY(f32, f32, bool);
	void getCurrTri(f32, f32, bool);
	void findEdgePenetration(CollTriInfo&, Vector3f*, Vector3f&, f32, Vector3f&);
	void recTraceMove(CollGroup*, MoveTrace&, f32);
	void traceMove(Creature*, MoveTrace&, f32);
	void loadPlatshape(char*);
	CreatureCollPart* requestCollPart(ObjCollInfo*, Creature*);

	// unused/inlined:
	void closeCollTri(CollGroup*, CollTriInfo*);

	// TODO: members
	u8 _00[0x4D4]; // _4D4, unknown
};

extern MapMgr* mapMgr;

#endif
