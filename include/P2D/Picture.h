#ifndef _P2D_PICTURE_H
#define _P2D_PICTURE_H

#include "types.h"
#include "P2D/Pane.h"
#include "P2D/Util.h"
#include "Dolphin/gx.h"
#include "Texture.h"
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

	u8 getAlpha() const { return mAlpha; }
	void setAlpha(u8 alpha) { mAlpha = alpha; }

	void initBlack() { mBlack.set(0, 0, 0, 0); }
	void initWhite() { mWhite.set(255, 255, 255, 255); }

	bool append(Texture* texture, f32 p2) { return insert(texture, mTextureCount, p2); }

	void setTumble(bool tumble) { mTumble = tumble; }
	void setWrapmode(P2DWrapmode wrapS, P2DWrapmode wrapT)
	{
		mWrapS = wrapS;
		mWrapT = wrapT;
	}
	void setBinding(P2DBinding binding) { mBinding = binding; }
	void setMirror(P2DMirror mirror) { mMirror = mirror; }

	void load(u8 idx)
	{
		if (idx < mTextureCount) {
			load(mTextures[idx], (GXTexMapID)idx);
		}
	}
	void load(Texture* texture, GXTexMapID texMapID)
	{
		texture->makeResident();
		GXLoadTexObj(texture->mTexObj, texMapID);
	}

	void setTexture(Texture* texture, u8 idx)
	{
		if (idx < mTextureCount) {
			mTextures[idx] = texture;
		}
	}

	char* getTexName() { return mTexName; }

	// DLL inlines:

	Colour getBlack();
	void setBlack(Colour);

	Colour getWhite();
	void setWhite(Colour);

	Texture* getTexture(u8) const;

	// _00     = VTBL
	// _00-_EC = P2DPane
	Texture* mTextures[1]; // _EC
	u8 mAlpha;             // _F0
	u8 mTextureCount;      // _F1
	u8 _F2[1];             // _F2
	P2DBinding mBinding;   // _F4
	P2DMirror mMirror;     // _F8
	bool mTumble;          // _FC
	P2DWrapmode mWrapS;    // _100
	P2DWrapmode mWrapT;    // _104
	Colour mWhite;         // _108
	Colour mBlack;         // _10C
	char* mTexName;        // _110
};

#endif
