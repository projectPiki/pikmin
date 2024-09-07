#ifndef _P2DTEXTBOX_H
#define _P2DTEXTBOX_H

#include "types.h"
#include "Vector.h"
#include "Matrix4f.h"

/**
 * .obj __vt__10P2DTextBox, global
 * .4byte __RTTI__10P2DTextBox
 * .4byte 0
 * .4byte loadResource__10P2DTextBoxFv
 * .4byte makeResident__10P2DTextBoxFv
 * .4byte __dt__10P2DTextBoxFv
 * .4byte move__7P2DPaneFii
 * .4byte move__7P2DPaneFR8Vector3f
 * .4byte move__7P2DPaneFiif
 * .4byte moveZ__7P2DPaneFf
 * .4byte add__7P2DPaneFii
 * .4byte resize__7P2DPaneFii
 * .4byte drawSelf__10P2DTextBoxFii
 * .4byte drawSelf__10P2DTextBoxFiiP8Matrix4f
 * .4byte search__7P2DPaneFUlb
 * .4byte makeMatrix__7P2DPaneFii
 */

struct P2DPane {
	virtual void loadResource();                // _08
	virtual void makeResident();                // _0C
	virtual ~P2DPane();                         // _10 (weak)
	virtual void move(int, int);                // _14 (weak)
	virtual void move(Vector3f&);               // _18
	virtual void move(int, int, float);         // _1C
	virtual void moveZ(float);                  // _20
	virtual void add(int, int);                 // _24
	virtual void resize(int, int);              // _28
	virtual void drawSelf(int, int);            // _2C
	virtual void drawSelf(int, int, Matrix4f*); // _30
	virtual void search(unsigned long, bool);   // _34
	virtual void makeMatrix(int, int);          // _38
};

/**
 * @brief TODO
 */
struct P2DTextBox : public P2DPane {
	virtual void loadResource();                // _08
	virtual void makeResident();                // _0C
	virtual ~P2DTextBox();                      // _10 (weak)
	virtual void drawSelf(int, int);            // _2C
	virtual void drawSelf(int, int, Matrix4f*); // _30

	P2DTextBox(P2DPane*, RandomAccessStream*, u16);
};

#endif
