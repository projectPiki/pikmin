#ifndef _BASESHAPE_H
#define _BASESHAPE_H

/**
 * .obj __vt__9BaseShape, global
 * .4byte __RTTI__9BaseShape
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__9BaseShapeFR18RandomAccessStream
 * .4byte optimize__9BaseShapeFv
 * .4byte update__9BaseShapeFv
 * .4byte render__9BaseShapeFR8Graphics
 * .4byte render2d__9BaseShapeFR8Graphics
 * .4byte makeRouteGroup__9BaseShapeFv
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

/**
 * @brief TODO
 */
struct BaseShape : public ANode {
	virtual void read(RandomAccessStream&); // _0C
	virtual void optimize();                // _10
	virtual void update();                  // _14
	virtual void render(Graphics&);         // _18
	virtual void render2d(Graphics&);       // _1C
	virtual void makeRouteGroup();          // _20
};

#endif
