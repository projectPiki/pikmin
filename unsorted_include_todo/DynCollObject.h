#ifndef _DYNCOLLOBJECT_H
#define _DYNCOLLOBJECT_H

/**
 * .obj __vt__13DynCollObject, weak
 * .4byte __RTTI__13DynCollObject
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte update__4NodeFv
 * .4byte draw__4NodeFR8Graphics
 * .4byte render__4NodeFR8Graphics
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 * .4byte adjust__13DynCollObjectFP8Creature
 * .4byte applyVelocity__13DynCollObjectFR5PlaneR8Vector3fR8Vector3f
 * .4byte touchCallback__13DynCollObjectFR5PlaneR8Vector3fR8Vector3f
 * .4byte getShape__13DynCollObjectFv
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                   // _08
	virtual void read(RandomAccessStream &);  // _0C (weak)
};

struct Node {
	virtual void _08() = 0;           // _08
	virtual void _0C() = 0;           // _0C
	virtual void update();            // _10
	virtual void draw(Graphics &);    // _14
	virtual void render(Graphics &);  // _18
	virtual void concat();            // _1C (weak)
	virtual void concat(VQS &);       // _20 (weak)
	virtual void concat(SRT &);       // _24 (weak)
	virtual void concat(Matrix4f &);  // _28 (weak)
	virtual void getModelMatrix();    // _2C (weak)
};

/**
 * @brief TODO
 */
struct DynCollObject : public ANode, public CoreNode, public Node {
	virtual void adjust(Creature *);                              // _30
	virtual void applyVelocity(Plane &, Vector3f &, Vector3f &);  // _34
	virtual void touchCallback(Plane &, Vector3f &, Vector3f &);  // _38
	virtual void getShape();                                      // _3C

};

#endif
