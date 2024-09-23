#ifndef _P2D_GRAPH_H
#define _P2D_GRAPH_H

#include "types.h"

struct Colour;
struct Matrix4f;
struct PUTRect;
struct PUTPoint;

/**
 * @brief TODO
 */
struct P2DGrafContext {
	P2DGrafContext(int, int, int, int);
	P2DGrafContext(const PUTRect&); // unused/inlined

	virtual ~P2DGrafContext();              // _08
	virtual void place(const PUTRect&);     // _0C
	virtual void place(int, int, int, int); // _10
	virtual void setPort();                 // _14
	virtual void setup2D();                 // _18
	virtual void setScissor();              // _1C
	virtual void setLookat();               // _20

	void scissor(const PUTRect&);
	void setColor(Colour&, Colour&, Colour&, Colour&);
	void setLineWidth(u8);

	// unused/inlined:
	void fillBox(const PUTRect&);
	void drawFrame(const PUTRect&);
	void line(PUTPoint, PUTPoint);
	void lineTo(PUTPoint);
	void polyline(PUTPoint*, int);
	void polyline(int*, int);
	void polylineTo(PUTPoint*, int);
	void polylineTo(int*, int);

	// TODO: members
};

/**
 * @brief TODO
 */
struct P2DPerspGraph : public P2DGrafContext {
	P2DPerspGraph(int, int, int, int, f32, f32, f32);
	P2DPerspGraph();                              // unused/inlined
	P2DPerspGraph(const PUTRect&, f32, f32, f32); // unused/inlined

	virtual ~P2DPerspGraph(); // _08 (weak)
	virtual void setPort();   // _14
	virtual void setLookat(); // _20

	void set(f32, f32, f32);
	void setFovy(f32);
	void makeLookat();

	// unused/inlined:
	void getMatrix(Matrix4f&);
	void setDistance(f32);

	// _00     = VTBL?
	// _00-_?? = P2DGrafContext
	// TODO: members
};

/**
 * @brief TODO
 */
struct P2DOrthoGraph : public P2DGrafContext {
	P2DOrthoGraph(int, int, int, int);
	P2DOrthoGraph();               // unused/inlined
	P2DOrthoGraph(const PUTRect&); // unused/inlined

	virtual ~P2DOrthoGraph(); // _08 (weak)
	virtual void setPort();   // _14
	virtual void setLookat(); // _20

	void scissorBounds(PUTRect*, PUTRect*);

	// unused/inlined:
	void setOrtho(const PUTRect&, int, int);
	void setOrigin(int, int);

	// _00     = VTBL?
	// _00-_?? = P2DGrafContext
	// TODO: members
};

#endif
