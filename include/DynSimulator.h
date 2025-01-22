#ifndef _DYNAMICS_H
#define _DYNAMICS_H

#include "types.h"
#include "Node.h"
#include "Matrix3f.h"
#include "BoundBox.h"

struct Collision;
struct CollGroup;
struct CollState;
struct RigidBody;
struct Shape;
struct LightCamera;

/**
 * @brief TODO
 *
 * @note Genuinely not sure where to put this, but here kind of makes sense?
 */
struct WorldSpring {
	WorldSpring() { }

	u8 _00[0x4];  // _00, unknown
	Vector3f _04; // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x132B4.
 */
struct RigidBody : public Node {

	/**
	 * @brief TODO
	 *
	 * @note Size: 0x308C.
	 */
	struct configuration {
		configuration() { }

		Matrix3f _00;        // _00
		Quat _24;            // _24
		Vector3f _34;        // _30
		Vector3f _40;        // _40
		Vector3f _4C;        // _4C
		Vector3f _58;        // _58
		Matrix3f _64;        // _64
		u32 _88;             // _88, unknown
		Vector3f _8C[0x400]; // _8C
	};

	RigidBody()
	    : Node("rigidBody")
	{
		_4118[1]._88 = 0;
		_4118[0]._88 = 0;
		_5C          = 0.0f;
		_90          = 0;
		_8C          = 0;
		_4094        = 0;
	}

	virtual void render(Graphics&);                                       // _18
	virtual void initDimensions(f32, f32, f32);                           // _30
	virtual void computeForces(int, f32);                                 // _34
	virtual void integrate(int, int, f32);                                // _38
	virtual bool resolveCollisions(int, Collision&);                      // _3C
	virtual void calculateVertices(int);                                  // _40
	virtual void initCollisions(int);                                     // _44
	virtual bool checkForCollisions(int, CollState&);                     // _48
	virtual void updateVecQuats(int, f32);                                // _4C
	virtual void updateViewInfo(int, int);                                // _50
	virtual void applyBodyFriction(int, Vector3f&, Vector3f&, Vector3f&); // _54
	virtual void makeBodyQuat(Quat&);                                     // _58
	virtual void initRender(int);                                         // _5C
	virtual void shadrender(Graphics&, LightCamera*);                     // _60
	virtual f32 getViewScale();                                           // _64
	virtual void updateCont();                                            // _68
	virtual void applyGroundForces(int, CollGroup*);                      // _6C

	void initializeBody();
	void applyCMForce(Vector3f&);

	// _00     = VTBL
	// _00-_20 = Node
	Vector3f _20;              // _20
	Vector3f _2C;              // _2C
	Vector3f _38;              // _38
	Vector3f _44;              // _44
	Vector3f _50;              // _50
	f32 _5C;                   // _5C
	u8 _60[0x4];               // _60, unknown
	Matrix3f _64;              // _64
	u8 _88[0x4];               // _88, unknown
	u32 _8C;                   // _8C, unknown
	u32 _90;                   // _90, unknown
	Vector3f _94[0x400];       // _94
	u8 _3094[0x4094 - 0x3094]; // _3094, unknown
	u32 _4094;                 // _4094, unknown
	WorldSpring _4098[0x8];    // _4098
	configuration _4118[0x2];  // _4118
	Vector3f _A230;            // _A230
	Vector3f _A23C;            // _A23C
	Vector3f _A248[0x800];     // _A248
	Vector3f _10248[0x400];    // _10248
	Vector3f _13248[2];        // _13248
	Vector3f _13260;           // _13260
	Quat _1326C[2];            // _1326C
	Quat _1328C;               // _1328C
	BoundBox _1329C;           // _1329C
};

/**
 * @brief TODO
 */
struct DynSimulator : public Node {
	void resetWorld();
	void doSimulation(f32, f32, Shape*);
	void updateVecQuats(f32);

	// unused/inlined:
	void evolveSimulation(f32, Shape*);
	void Integrate(f32);
	void CalculateVertices(int);
	int CheckForCollisions(int, Shape*);
	void ResolveCollisions(int);

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

#endif
