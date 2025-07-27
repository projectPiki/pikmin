#ifndef _P2D_PICTURE_H
#define _P2D_PICTURE_H

#include "Colour.h"
#include "Dolphin/gx.h"
#include "P2D/Pane.h"
#include "P2D/Util.h"
#include "Texture.h"
#include "types.h"

struct Texture;

/**
 * @brief TODO
 *
 * @note Size: 0x114.
 */
struct P2DPicture : public P2DPane {
public:
	Texture* getTexture(u8 idx) const
	{
		if (idx < mTextureCount) {
			return mTextures[idx];
		}
		return nullptr;
	}
	void setTexture(Texture* texture, u8 idx)
	{
		if (idx < mTextureCount) {
			mTextures[idx] = texture;
		}
	}
	char* getTexName() { return mTexName; }

	u8 getAlpha() const { return mAlpha; }
	void setAlpha(u8 alpha) { mAlpha = alpha; }

	void initBlack() { mBlack.set(0, 0, 0, 0); }
	Colour getBlack() { return mBlack; }
	void setBlack(Colour black) { mBlack = black; }

	void initWhite() { mWhite.set(255, 255, 255, 255); }
	Colour getWhite() { return mWhite; }
	void setWhite(Colour white) { mWhite = white; }

	void setMirror(P2DMirror mirror) { mMirror = mirror; }
	void setBinding(P2DBinding binding) { mBinding = binding; }
	void setTumble(bool tumble) { mTumble = tumble; }
	void setWrapmode(P2DWrapmode wrapS, P2DWrapmode wrapT)
	{
		mWrapS = wrapS;
		mWrapT = wrapT;
	}

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

	P2DPicture(P2DPane*, RandomAccessStream*, u16);
	P2DPicture(Texture*);
	P2DPicture(); // unused/inlined

	virtual void loadResource(); // _08
	virtual void makeResident(); // _0C
	virtual ~P2DPicture();       // _10

	void draw(int, int, int, int, bool, bool, bool);
	void drawOut(const PUTRect&, const PUTRect&);
	void drawTest();

protected:
	bool insert(Texture*, u8, f32);
	void initinfo();

	virtual void drawSelf(int, int);            // _2C
	virtual void drawSelf(int, int, Matrix4f*); // _30
	void drawFullSet(int, int, int, int, P2DBinding, P2DMirror, bool, P2DWrapmode, P2DWrapmode, Matrix4f*);
	void drawTexCoord(int, int, int, int, f32, f32, f32, f32, f32, f32, f32, f32, Matrix4f*);

	void setTevMode();
	bool append(Texture* texture, f32 p2) { return insert(texture, mTextureCount, p2); }

private:
	void swap(f32&, f32&);

	// _00     = VTBL
	// _00-_EC = P2DPane
	Texture* mTextures[1]; // _EC
	u8 mAlpha;             // _F0
	u8 mTextureCount;      // _F1
	bool _F2[1];           // _F2
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
