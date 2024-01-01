#ifndef _P2DGRAFCONTEXT_H
#define _P2DGRAFCONTEXT_H

/**
 * .obj __vt__14P2DGrafContext, global
 * .4byte __RTTI__14P2DGrafContext
 * .4byte 0
 * .4byte __dt__14P2DGrafContextFv
 * .4byte place__14P2DGrafContextFRC7PUTRect
 * .4byte place__14P2DGrafContextFiiii
 * .4byte setPort__14P2DGrafContextFv
 * .4byte setup2D__14P2DGrafContextFv
 * .4byte setScissor__14P2DGrafContextFv
 * .4byte setLookat__14P2DGrafContextFv
*/

/**
 * @brief TODO
 */
struct P2DGrafContext {
	virtual ~P2DGrafContext();               // _08
	virtual void place(const PUTRect &);     // _0C
	virtual void place(int, int, int, int);  // _10
	virtual void setPort();                  // _14
	virtual void setup2D();                  // _18
	virtual void setScissor();               // _1C
	virtual void setLookat();                // _20

};

#endif
