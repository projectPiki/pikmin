#ifndef _P2D_GRAPH_H
#define _P2D_GRAPH_H

#include "Colour.h"
#include "Matrix4f.h"
#include "PUT/Geometry.h"
#include "types.h"

/**
 * @brief TODO
 */
enum P2DGrafType {
	P2DGRAF_Ortho = 1,
	P2DGRAF_Persp = 2,
};

/**
 * @brief TODO
 *
 * @note Size: 0xD4.
 */
struct P2DGrafContext {
	friend struct P2DPane;

public:
	P2DGrafContext(int x0, int y0, int width, int height);
	P2DGrafContext(const PUTRect&); // unused/inlined

	virtual ~P2DGrafContext() { }                             // _08
	virtual void place(const PUTRect& pos);                   // _0C
	virtual void place(int x0, int y0, int width, int height) // _10
	{
		place(PUTRect(x0, y0, x0 + width, y0 + height));
	}
	virtual void setPort();      // _14
	virtual void setup2D();      // _18
	virtual void setScissor();   // _1C

	void scissor(const PUTRect& pos);
	void setColor(Colour&, Colour&, Colour&, Colour&);
	void setLineWidth(u8 width);

	// unused/inlined:
	void fillBox(const PUTRect&);
	void drawFrame(const PUTRect&);
	void line(PUTPoint, PUTPoint);
	void lineTo(PUTPoint);
	void polyline(PUTPoint*, int);
	void polyline(int*, int);
	void polylineTo(PUTPoint*, int);
	void polylineTo(int*, int);

	void setColor(Colour& colour) { setColor(colour, colour, colour, colour); }

protected:
	virtual void setLookat() { } // _20

	// _00 = VTBL
	int mGrafType;           // _04, see P2DGrafType enum
	PUTRect mViewportBounds; // _08
	PUTRect mScissorBounds;  // _10
	Colour _18;              // _18
	Colour _1C;              // _1C
	Colour _20;              // _20
	Colour _24;              // _24
	u8 mLineWidth;           // _28
	PUTPoint _2A;            // _2A
	Matrix4f mProjectionMtx; // _30
	Matrix4f mViewMtx;       // _70
	int _B0[2];              // _B0
	int _B8;                 // _B8
	int _BC[2];              // _BC
	int _C4;                 // _C4
	int _C8[2];              // _C8
	int _D0;                 // _D0
};

/**
 * @brief TODO
 *
 * @note Size: 0xE4.
 */
struct P2DPerspGraph : public P2DGrafContext {
public:
	P2DPerspGraph(int x0, int y0, int width, int height, f32 fovy, f32, f32);
	P2DPerspGraph();                              // unused/inlined
	P2DPerspGraph(const PUTRect&, f32, f32, f32); // unused/inlined

	virtual ~P2DPerspGraph() { } // _08 (weak)
	virtual void setPort();      // _14

	void set(f32 fovy, f32, f32);
	void setFovy(f32 fovy);

	// unused/inlined:
	void getMatrix(Matrix4f&);
	void setDistance(f32);

	void setNearClip(f32 nearZ) { mNearClipZ = nearZ; }
	void setFarClip(f32 farZ) { mFarClipZ = farZ; }

protected:
	virtual void setLookat(); // _20

	void makeLookat();

	// _00     = VTBL
	// _00-_D4 = P2DGrafContext
	f32 mFovy;      // _D4
	f32 mNearClipZ; // _D8
	f32 mFarClipZ;  // _DC
	f32 mDistance;  // _E0
};

/**
 * @brief TODO
 */
struct P2DOrthoGraph : public P2DGrafContext {
	friend struct P2DPane; // Accesses `scissorBounds` (why is it protected)

public:
	P2DOrthoGraph(int, int, int, int);
	P2DOrthoGraph();               // unused/inlined
	P2DOrthoGraph(const PUTRect&); // unused/inlined

	virtual ~P2DOrthoGraph() { } // _08 (weak)
	virtual void setPort();      // _14

	// unused/inlined:
	void setOrtho(const PUTRect&, int, int);
	void setOrigin(int, int);

protected:
	virtual void setLookat(); // _20

	void scissorBounds(PUTRect*, PUTRect*);

	// DLL inlines:
	f32 getWidthPower() { return f32(mViewportBounds.getWidth()) / f32(mLogicalViewBounds.getWidth()); }
	f32 getHeightPower() { return f32(mViewportBounds.getHeight()) / f32(mLogicalViewBounds.getHeight()); }

	// _00     = VTBL
	// _00-_D4 = P2DGrafContext
	PUTRect mLogicalViewBounds; // _D4
	int mLogicalFarZ;           // _DC
	int mLogicalNearZ;          // _E0
};

#endif
