#ifndef _DYNAMICS_H
#define _DYNAMICS_H

#include "types.h"
#include "Node.h"

struct Collision;
struct CollGroup;
struct CollState;
struct RigidBody;
struct Shape;
struct LightCamera;

/**
 * @brief TODO
 */
struct RigidBody : public Node {

	/**
	 * @brief TODO
	 */
	struct configuration {
		configuration();

		// TODO: members
	};

	RigidBody();

	virtual void render(Graphics&);                                       // _18
	virtual void initDimensions(f32, f32, f32);                           // _30
	virtual void computeForces(int, f32);                                 // _34
	virtual void integrate(int, int, f32);                                // _38
	virtual void resolveCollisions(int, Collision&);                      // _3C
	virtual void calculateVertices(int);                                  // _40
	virtual void initCollisions(int);                                     // _44
	virtual bool checkForCollisions(int, CollState&);                     // _48
	virtual void updateVecQuats(int, f32);                                // _4C
	virtual void updateViewInfo(int, int);                                // _50
	virtual void applyBodyFriction(int, Vector3f&, Vector3f&, Vector3f&); // _54
	virtual void makeBodyQuat(Quat&);                                     // _58
	virtual void initRender(int);                                         // _5C
	virtual void shadrender(Graphics&, LightCamera*);                     // _60
	virtual void getViewScale();                                          // _64
	virtual void updateCont();                                            // _68
	virtual void applyGroundForces(int, CollGroup*);                      // _6C

	void initializeBody();
	void applyCMForce(Vector3f&);

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
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
	void CheckForCollisions(int, Shape*);
	void ResolveCollisions(int);

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

#endif
