#ifndef _P2D_PICTURE_H
#define _P2D_PICTURE_H

#include "types.h"
#include "P2D/Pane.h"
#include "P2D/Util.h"

struct Texture;

/**
 * @brief TODO
 *
 * @note Size: 0x114.
 */
struct P2DPicture : public P2DPane {
	P2DPicture(P2DPane*, RandomAccessStream*, u16);
	P2DPicture(Texture*);
	P2DPicture(); // unused/inlined

	virtual void loadResource();                // _08
	virtual void makeResident();                // _0C
	virtual ~P2DPicture();                      // _10
	virtual void drawSelf(int, int);            // _2C
	virtual void drawSelf(int, int, Matrix4f*); // _30

	void insert(Texture*, u8, f32);
	void initinfo();
	void drawFullSet(int, int, int, int, P2DBinding, P2DMirror, bool, P2DWrapmode, P2DWrapmode, Matrix4f*);
	void drawTexCoord(int, int, int, int, f32, f32, f32, f32, f32, f32, f32, f32, Matrix4f*);
	void setTevMode();
	void swap(f32&, f32&);

	// unused/inlined:
	void draw(int, int, int, int, bool, bool, bool);
	void drawOut(const PUTRect&, const PUTRect&);
	void drawTest();

	// _00     = VTBL
	// _00-_?? = P2DPane
	// TODO: members
};

#endif
