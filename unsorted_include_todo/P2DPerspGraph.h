#ifndef _P2DPERSPGRAPH_H
#define _P2DPERSPGRAPH_H

/**
 * .obj __vt__13P2DPerspGraph, global
 * .4byte __RTTI__13P2DPerspGraph
 * .4byte 0
 * .4byte __dt__13P2DPerspGraphFv
 * .4byte place__14P2DGrafContextFRC7PUTRect
 * .4byte place__14P2DGrafContextFiiii
 * .4byte setPort__13P2DPerspGraphFv
 * .4byte setup2D__14P2DGrafContextFv
 * .4byte setScissor__14P2DGrafContextFv
 * .4byte setLookat__13P2DPerspGraphFv
 */

struct P2DGrafContext {
	virtual ~P2DGrafContext();              // _08 (weak)
	virtual void place(const PUTRect&);     // _0C
	virtual void place(int, int, int, int); // _10
	virtual void setPort();                 // _14
	virtual void setup2D();                 // _18
	virtual void setScissor();              // _1C
};

/**
 * @brief TODO
 */
struct P2DPerspGraph : public P2DGrafContext {
	virtual ~P2DPerspGraph(); // _08 (weak)
	virtual void setPort();   // _14
	virtual void setLookat(); // _20

	P2DPerspGraph(int, int, int, int, float, float, float);
	void set(float, float, float);
	void setFovy(float);
	void makeLookat();
};

#endif
