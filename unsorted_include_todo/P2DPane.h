#ifndef _P2DPANE_H
#define _P2DPANE_H

/**
 * .obj __vt__7P2DPane, global
 * .4byte __RTTI__7P2DPane
 * .4byte 0
 * .4byte loadResource__7P2DPaneFv
 * .4byte makeResident__7P2DPaneFv
 * .4byte __dt__7P2DPaneFv
 * .4byte move__7P2DPaneFii
 * .4byte move__7P2DPaneFR8Vector3f
 * .4byte move__7P2DPaneFiif
 * .4byte moveZ__7P2DPaneFf
 * .4byte add__7P2DPaneFii
 * .4byte resize__7P2DPaneFii
 * .4byte drawSelf__7P2DPaneFii
 * .4byte drawSelf__7P2DPaneFiiP8Matrix4f
 * .4byte search__7P2DPaneFUlb
 * .4byte makeMatrix__7P2DPaneFii
 */

/**
 * @brief TODO
 */
struct P2DPane {
	virtual void loadResource();                // _08
	virtual void makeResident();                // _0C
	virtual ~P2DPane();                         // _10
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

	void setCallBack(P2DPaneCallBack*);
};

#endif
