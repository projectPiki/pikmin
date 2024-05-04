#ifndef _P2DSCREEN_H
#define _P2DSCREEN_H

#include "Vector3f.h"
#include "Matrix4f.h"

/**
 * .obj __vt__9P2DScreen, global
 * .4byte __RTTI__9P2DScreen
 * .4byte 0
 * .4byte loadResource__9P2DScreenFv
 * .4byte makeResident__7P2DPaneFv
 * .4byte __dt__9P2DScreenFv
 * .4byte move__7P2DPaneFii
 * .4byte move__7P2DPaneFR8Vector3f
 * .4byte move__7P2DPaneFiif
 * .4byte moveZ__7P2DPaneFf
 * .4byte add__7P2DPaneFii
 * .4byte resize__7P2DPaneFii
 * .4byte drawSelf__7P2DPaneFii
 * .4byte drawSelf__7P2DPaneFiiP8Matrix4f
 * .4byte search__9P2DScreenFUlb
 * .4byte makeMatrix__7P2DPaneFii
 * .4byte makeUserPane__9P2DScreenFUsP7P2DPaneP18RandomAccessStream
 */

struct P2DPane {
	virtual void loadResource();                // _08
	virtual void makeResident();                // _0C
	virtual ~P2DPane();                         // _10
	virtual void move(int, int);                // _14 (weak)
	virtual void move(Vector3f&);               // _18
	virtual void move(int, int, f32);         // _1C
	virtual void moveZ(f32);                  // _20
	virtual void add(int, int);                 // _24
	virtual void resize(int, int);              // _28
	virtual void drawSelf(int, int);            // _2C
	virtual void drawSelf(int, int, Matrix4f*); // _30
	virtual void search(u32, bool);   // _34
	virtual void makeMatrix(int, int);          // _38
};

/**
 * @brief TODO
 */
struct P2DScreen : public P2DPane {
	virtual void loadResource();                                              // _08
	virtual ~P2DScreen();                                                     // _10
	virtual void search(u32, bool);                                 // _34
	virtual void makeUserPane(u16, P2DPane*, RandomAccessStream*); // _3C
};

#endif
