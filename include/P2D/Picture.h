#ifndef _P2D_PICTURE_H
#define _P2D_PICTURE_H

#include "types.h"
#include "P2D/Pane.h"
#include "P2D/Util.h"
#include "Dolphin/gx.h"
#include "Colour.h"

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

	bool insert(Texture*, u8, f32);
	void initinfo();
	void drawFullSet(int, int, int, int, P2DBinding, P2DMirror, bool, P2DWrapmode, P2DWrapmode, Matrix4f*);
	void drawTexCoord(int, int, int, int, f32, f32, f32, f32, f32, f32, f32, f32, Matrix4f*);
	void setTevMode();
	void swap(f32&, f32&);

	// unused/inlined:
	void draw(int, int, int, int, bool, bool, bool);
	void drawOut(const PUTRect&, const PUTRect&);
	void drawTest();

	// NB: this is because of ogPause - might be wrong; if so, ogPause should use P2DTextBox inlines instead
	void setAlpha(u8 alpha) { _F0 = alpha; }

	// DLL inlines:
	char* getTexName();
	Colour getBlack();
	Colour getWhite();
	Texture* getTexture(u8) const;
	u8 getAlpha() const;
	void initBlack();
	void initWhite();
	void load(Texture*, GXTexMapID);
	void load(u8);
	void setBinding(P2DBinding);
	void setBlack(Colour);
	void setMirror(P2DMirror);
	void setTexture(Texture*, u8);
	void setTumble(bool);
	void setWhite(Colour);
	void setWrapmode(P2DWrapmode, P2DWrapmode);
	bool append(Texture*, f32);

	// _00     = VTBL
	// _00-_EC = P2DPane
	u8 _EC[0x4];          // _EC, unknown
	u8 _F0;               // _F0
	u8 _F1[0x114 - 0xF1]; // _F1, unknown
};

#endif
