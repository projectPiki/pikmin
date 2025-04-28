#ifndef _P2D_WINDOW_H
#define _P2D_WINDOW_H

#include "types.h"
#include "P2D/Pane.h"
#include "P2D/Util.h"

struct Texture;

/**
 * @brief TODO
 *
 * @note Size: 0x12C.
 */
struct P2DWindow : public P2DPane {

	/**
	 * @brief TODO
	 */
	struct P2DWindowTexture {
		P2DWindowTexture(Texture*); // DLL, to do

		void draw(int, int, int, int, u16, u16, u16, u16);
		void draw(int, int, bool, bool);
		void setTevMode();

		void setTexture(Texture* tex) { mTexture = tex; }

		// DLL inlines:
		u16 getHeight();
		u16 getWidth();
		void makeResident();

		// TODO: members
		Texture* mTexture; // _00
	};

	P2DWindow(P2DPane*, RandomAccessStream*, u16);

	virtual void loadResource();                // _08
	virtual void makeResident();                // _0C
	virtual ~P2DWindow();                       // _10
	virtual void drawSelf(int, int);            // _2C
	virtual void drawSelf(int, int, Matrix4f*); // _30

	void draw_private(const PUTRect&, const PUTRect&, Matrix4f*);
	void drawContents(const PUTRect&);

	// unused/inlined:
	Texture* loadResource(char*);

	// DLL inlines:
	void setTexture(Texture* tex)
	{
		_104->setTexture(tex);
		_108->setTexture(tex);
		_10C->setTexture(tex);
		_110->setTexture(tex);
	}

	// _00     = VTBL
	// _00-_EC = P2DPane
	u8 _EC[0x104 - 0xEC];   // _EC, unknown
	P2DWindowTexture* _104; // _104
	P2DWindowTexture* _108; // _108
	P2DWindowTexture* _10C; // _10C
	P2DWindowTexture* _110; // _110
	u8 _114[0x12C - 0x114]; // _114, unknown
};

#endif
