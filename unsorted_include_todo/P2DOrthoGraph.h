#ifndef _P2DORTHOGRAPH_H
#define _P2DORTHOGRAPH_H

/**
 * .obj __vt__13P2DOrthoGraph, global
 * .4byte __RTTI__13P2DOrthoGraph
 * .4byte 0
 * .4byte __dt__13P2DOrthoGraphFv
 * .4byte place__14P2DGrafContextFRC7PUTRect
 * .4byte place__14P2DGrafContextFiiii
 * .4byte setPort__13P2DOrthoGraphFv
 * .4byte setup2D__14P2DGrafContextFv
 * .4byte setScissor__14P2DGrafContextFv
 * .4byte setLookat__13P2DOrthoGraphFv
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
struct P2DOrthoGraph : public P2DGrafContext {
	virtual ~P2DOrthoGraph(); // _08 (weak)
	virtual void setPort();   // _14
	virtual void setLookat(); // _20

	P2DOrthoGraph(int, int, int, int);
	void scissorBounds(PUTRect*, PUTRect*);
};

#endif
