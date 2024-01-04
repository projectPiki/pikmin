#ifndef _SHAPE_H
#define _SHAPE_H

/**
 * .obj __vt__5Shape, global
 * .4byte __RTTI__5Shape
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__9BaseShapeFR18RandomAccessStream
 * .4byte optimize__5ShapeFv
 * .4byte update__9BaseShapeFv
 * .4byte render__9BaseShapeFR8Graphics
 * .4byte render2d__9BaseShapeFR8Graphics
 * .4byte makeRouteGroup__9BaseShapeFv
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

struct BaseShape {
	virtual void _08() = 0;                 // _08
	virtual void read(RandomAccessStream&); // _0C
	virtual void optimize();                // _10
	virtual void update();                  // _14
	virtual void render(Graphics&);         // _18
	virtual void render2d(Graphics&);       // _1C
	virtual void makeRouteGroup();          // _20
};

/**
 * @brief TODO
 */
struct Shape : public ANode, public BaseShape {
	virtual void optimize(); // _10

	Shape();
};

#endif
