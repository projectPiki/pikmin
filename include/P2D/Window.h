#ifndef _P2D_WINDOW_H
#define _P2D_WINDOW_H

#include "Colour.h"
#include "P2D/Pane.h"
#include "P2D/Util.h"
#include "Texture.h"
#include "types.h"

struct Texture;

/**
 * @brief TODO
 *
 * @note Size: 0x12C.
 */
struct P2DWindow : public P2DPane {

	/**
	 * @brief TODO
	 *
	 * @note Size: 0x4.
	 */
	struct P2DWindowTexture {
		P2DWindowTexture(Texture* tex) { mTexture = tex; }

		void draw(int, int, int, int, u16, u16, u16, u16);
		void draw(int p1, int p2, bool p3, bool p4);
		void setTevMode();

		void setTexture(Texture* tex) { mTexture = tex; }

		void makeResident() { mTexture->makeResident(); }
		u16 getHeight() { return mTexture->mHeight; }
		u16 getWidth() { return mTexture->mWidth; }

		Texture* mTexture; // _00
	};

	P2DWindow(P2DPane*, RandomAccessStream*, u16);

	virtual void loadResource();                // _08
	virtual void makeResident();                // _0C
	virtual ~P2DWindow() { }                    // _10
	virtual void drawSelf(int, int);            // _2C
	virtual void drawSelf(int, int, Matrix4f*); // _30

	void draw_private(const PUTRect&, const PUTRect&, Matrix4f*);
	void drawContents(const PUTRect&);

	// unused/inlined:
	Texture* loadResource(char*);

	// DLL inlines:
	void setTexture(Texture* tex)
	{
		mTLCornerTexture->setTexture(tex);
		mTRCornerTexture->setTexture(tex);
		mBLCornerTexture->setTexture(tex);
		mBRCornerTexture->setTexture(tex);
	}

	// _00     = VTBL
	// _00-_EC = P2DPane
	char* mTLTexName;                   // _EC
	char* mTRTexName;                   // _F0
	char* mBLTexName;                   // _F4
	char* mBRTexName;                   // _F8
	PUTRect mWindowBounds;              // _FC
	P2DWindowTexture* mTLCornerTexture; // _104
	P2DWindowTexture* mTRCornerTexture; // _108
	P2DWindowTexture* mBLCornerTexture; // _10C
	P2DWindowTexture* mBRCornerTexture; // _110
	int mWindowFlag;                    // _114
	Colour mTLCornerColour;             // _118
	Colour mTRCornerColour;             // _11C
	Colour mBLCornerColour;             // _120
	Colour mBRCornerColour;             // _124
	s16 mMinWidth;                      // _128
	s16 mMinHeight;                     // _12A
};

#endif
