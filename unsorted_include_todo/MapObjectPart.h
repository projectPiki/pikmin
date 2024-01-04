#ifndef _MAPOBJECTPART_H
#define _MAPOBJECTPART_H

/**
 * .obj __vt__13MapObjectPart, weak
 * .4byte __RTTI__13MapObjectPart
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte update__13MapObjectPartFv
 * .4byte draw__4NodeFR8Graphics
 * .4byte render__4NodeFR8Graphics
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 * .4byte adjust__12DynCollShapeFP8Creature
 * .4byte applyVelocity__13DynCollObjectFR5PlaneR8Vector3fR8Vector3f
 * .4byte touchCallback__13MapObjectPartFR5PlaneR8Vector3fR8Vector3f
 * .4byte getShape__12DynCollShapeFv
 * .4byte jointVisible__12DynCollShapeFii
 * .4byte refresh__13MapObjectPartFR8Graphics
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

struct DynCollShape {
	virtual void _08() = 0;                                   // _08
	virtual void _0C() = 0;                                   // _0C
	virtual void update();                                    // _10
	virtual void _14() = 0;                                   // _14
	virtual void _18() = 0;                                   // _18
	virtual void _1C() = 0;                                   // _1C
	virtual void _20() = 0;                                   // _20
	virtual void _24() = 0;                                   // _24
	virtual void _28() = 0;                                   // _28
	virtual void _2C() = 0;                                   // _2C
	virtual void adjust(Creature*);                           // _30
	virtual void _34() = 0;                                   // _34
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _38
	virtual void getShape();                                  // _3C
	virtual void jointVisible(int, int);                      // _40
};

struct DynCollObject {
	virtual void _08() = 0;                                   // _08
	virtual void _0C() = 0;                                   // _0C
	virtual void update();                                    // _10
	virtual void _14() = 0;                                   // _14
	virtual void _18() = 0;                                   // _18
	virtual void _1C() = 0;                                   // _1C
	virtual void _20() = 0;                                   // _20
	virtual void _24() = 0;                                   // _24
	virtual void _28() = 0;                                   // _28
	virtual void _2C() = 0;                                   // _2C
	virtual void _30() = 0;                                   // _30
	virtual void applyVelocity(Plane&, Vector3f&, Vector3f&); // _34
};

/**
 * @brief TODO
 */
struct MapObjectPart : public ANode, public CoreNode, public Node, public DynCollShape, public DynCollObject {
	virtual void update();                                    // _10
	virtual void touchCallback(Plane&, Vector3f&, Vector3f&); // _38
	virtual void refresh(Graphics&);                          // _44
};

#endif
