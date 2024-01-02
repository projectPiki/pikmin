#ifndef _DYNOBJBRIDGE_H
#define _DYNOBJBRIDGE_H

/**
 * .obj __vt__12DynObjBridge, weak
 * .4byte __RTTI__12DynObjBridge
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte update__4NodeFv
 * .4byte draw__4NodeFR8Graphics
 * .4byte render__10DynObjBodyFR8Graphics
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 * .4byte initDimensions__10DynObjBodyFfff
 * .4byte computeForces__10DynObjBodyFif
 * .4byte integrate__10DynObjBodyFiif
 * .4byte resolveCollisions__9RigidBodyFiR9Collision
 * .4byte calculateVertices__9RigidBodyFi
 * .4byte initCollisions__9RigidBodyFi
 * .4byte checkForCollisions__9RigidBodyFiR9CollState
 * .4byte updateVecQuats__9RigidBodyFif
 * .4byte updateViewInfo__9RigidBodyFii
 * .4byte applyBodyFriction__9RigidBodyFiR8Vector3fR8Vector3fR8Vector3f
 * .4byte makeBodyQuat__9RigidBodyFR4Quat
 * .4byte initRender__10DynObjBodyFi
 * .4byte shadrender__9RigidBodyFR8GraphicsP11LightCamera
 * .4byte getViewScale__9RigidBodyFv
 * .4byte updateCont__9RigidBodyFv
 * .4byte applyGroundForces__12DynObjBridgeFiP9CollGroup
 * .4byte touchCallback__10DynObjBodyFR5PlaneR8Vector3fR8Vector3f
 * .4byte applyVelocity__10DynObjBodyFR5PlaneR8Vector3fR8Vector3f
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                 // _08
	virtual void read(RandomAccessStream&); // _0C (weak)
};

struct Node {
	virtual void _08() = 0;         // _08
	virtual void _0C() = 0;         // _0C
	virtual void update();          // _10
	virtual void draw(Graphics&);   // _14
	virtual void _18() = 0;         // _18
	virtual void concat();          // _1C (weak)
	virtual void concat(VQS&);      // _20 (weak)
	virtual void concat(SRT&);      // _24 (weak)
	virtual void concat(Matrix4f&); // _28 (weak)
	virtual void getModelMatrix();  // _2C (weak)
};

struct DynObjBody {
	virtual void _08() = 0;                                   // _08
	virtual void _0C() = 0;                                   // _0C
	virtual void _10() = 0;                                   // _10
	virtual void _14() = 0;                                   // _14
	virtual void render(Graphics&);                           // _18
	virtual void _1C() = 0;                                   // _1C
	virtual void _20() = 0;                                   // _20
	virtual void _24() = 0;                                   // _24
	virtual void _28() = 0;                                   // _28
	virtual void _2C() = 0;                                   // _2C
	virtual void initDimensions(f32, f32, f32);               // _30
	virtual void computeForces(int, f32);                     // _34
	virtual void integrate(int, int, f32);                    // _38
	virtual void _3C() = 0;                                   // _3C
	virtual void _40() = 0;                                   // _40
	virtual void _44() = 0;                                   // _44
	virtual void _48() = 0;                                   // _48
	virtual void _4C() = 0;                                   // _4C
	virtual void _50() = 0;                                   // _50
	virtual void _54() = 0;                                   // _54
	virtual void _58() = 0;                                   // _58
	virtual void initRender(int);                             // _5C
	virtual void _60() = 0;                                   // _60
	virtual void _64() = 0;                                   // _64
	virtual void _68() = 0;                                   // _68
	virtual void applyGroundForces(int, CollGroup*);          // _6C
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _70
	virtual void applyVelocity(Plane&, Vector3f&, Vector3f&); // _74
};

struct RigidBody {
	virtual void _08() = 0;                                               // _08
	virtual void _0C() = 0;                                               // _0C
	virtual void _10() = 0;                                               // _10
	virtual void _14() = 0;                                               // _14
	virtual void _18() = 0;                                               // _18
	virtual void _1C() = 0;                                               // _1C
	virtual void _20() = 0;                                               // _20
	virtual void _24() = 0;                                               // _24
	virtual void _28() = 0;                                               // _28
	virtual void _2C() = 0;                                               // _2C
	virtual void _30() = 0;                                               // _30
	virtual void _34() = 0;                                               // _34
	virtual void _38() = 0;                                               // _38
	virtual void resolveCollisions(int, Collision&);                      // _3C
	virtual void calculateVertices(int);                                  // _40
	virtual void initCollisions(int);                                     // _44
	virtual void checkForCollisions(int, CollState&);                     // _48
	virtual void updateVecQuats(int, f32);                                // _4C
	virtual void updateViewInfo(int, int);                                // _50
	virtual void applyBodyFriction(int, Vector3f&, Vector3f&, Vector3f&); // _54
	virtual void makeBodyQuat(Quat&);                                     // _58
	virtual void _5C() = 0;                                               // _5C
	virtual void shadrender(Graphics&, LightCamera*);                     // _60
	virtual void getViewScale();                                          // _64
	virtual void updateCont();                                            // _68
};

/**
 * @brief TODO
 */
struct DynObjBridge : public ANode, public CoreNode, public Node, public DynObjBody, public RigidBody {
	virtual void applyGroundForces(int, CollGroup*); // _6C
};

#endif
