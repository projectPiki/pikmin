#ifndef _RIGIDBODY_H
#define _RIGIDBODY_H

/**
 * .obj __vt__9RigidBody, global
 * .4byte __RTTI__9RigidBody
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte update__4NodeFv
 * .4byte draw__4NodeFR8Graphics
 * .4byte render__9RigidBodyFR8Graphics
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 * .4byte initDimensions__9RigidBodyFfff
 * .4byte computeForces__9RigidBodyFif
 * .4byte integrate__9RigidBodyFiif
 * .4byte resolveCollisions__9RigidBodyFiR9Collision
 * .4byte calculateVertices__9RigidBodyFi
 * .4byte initCollisions__9RigidBodyFi
 * .4byte checkForCollisions__9RigidBodyFiR9CollState
 * .4byte updateVecQuats__9RigidBodyFif
 * .4byte updateViewInfo__9RigidBodyFii
 * .4byte applyBodyFriction__9RigidBodyFiR8Vector3fR8Vector3fR8Vector3f
 * .4byte makeBodyQuat__9RigidBodyFR4Quat
 * .4byte initRender__9RigidBodyFi
 * .4byte shadrender__9RigidBodyFR8GraphicsP11LightCamera
 * .4byte getViewScale__9RigidBodyFv
 * .4byte updateCont__9RigidBodyFv
 * .4byte applyGroundForces__9RigidBodyFiP9CollGroup
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
	virtual void render(Graphics&); // _18
	virtual void concat();          // _1C (weak)
	virtual void concat(VQS&);      // _20 (weak)
	virtual void concat(SRT&);      // _24 (weak)
	virtual void concat(Matrix4f&); // _28 (weak)
	virtual void getModelMatrix();  // _2C (weak)
};

/**
 * @brief TODO
 */
struct RigidBody : public ANode, public CoreNode, public Node {
	virtual void render(Graphics&);                                       // _18
	virtual void initDimensions(f32, f32, f32);                           // _30
	virtual void computeForces(int, f32);                                 // _34
	virtual void integrate(int, int, f32);                                // _38
	virtual void resolveCollisions(int, Collision&);                      // _3C
	virtual void calculateVertices(int);                                  // _40
	virtual void initCollisions(int);                                     // _44
	virtual void checkForCollisions(int, CollState&);                     // _48
	virtual void updateVecQuats(int, f32);                                // _4C
	virtual void updateViewInfo(int, int);                                // _50
	virtual void applyBodyFriction(int, Vector3f&, Vector3f&, Vector3f&); // _54
	virtual void makeBodyQuat(Quat&);                                     // _58
	virtual void initRender(int);                                         // _5C
	virtual void shadrender(Graphics&, LightCamera*);                     // _60
	virtual void getViewScale();                                          // _64
	virtual void updateCont();                                            // _68
	virtual void applyGroundForces(int, CollGroup*);                      // _6C
};

#endif
