#ifndef _WIN_H
#define _WIN_H

#include "Colour.h"
#include "CoreNode.h"
#include "ID32.h"
#include "types.h"

class Graphics;
class RectArea;
class Texture;
class Vector2i;

/**
 * @brief Status enum for GmWin and associated classes.
 */
enum GmWinState {
	GMWIN_Opening  = 0x1000,
	GMWIN_Active   = 0x1001,
	GMWIN_Closing  = 0x1002,
	GMWIN_Inactive = 0x1003,
};

/**
 * @brief Seemingly deprecated window drawing base class.
 */
class GmWin : public CoreNode {
public:
	/**
	 * @brief TODO
	 */
	struct CloseListener {
		virtual void onCloseWindow() { } // _08

		// _00 = VTBL
	};

	GmWin(); // unused/inlined

	virtual void open();                                                                                          // _10
	virtual void close();                                                                                         // _14
	virtual void update() { /* Matching by size */ }                                                              // _18 unused/inlined
	virtual void doRender(Graphics& gfx) { /* Matching by size */ }                                               // _1C unused/inlined
	virtual void render(Graphics& gfx);                                                                           // _20
	virtual void printStart(Graphics& gfx);                                                                       // _24
	virtual void print(Graphics& gfx, int posX, int posY, immut char* message);                                   // _28
	virtual void printcentre(Graphics& gfx, int posY, immut char* message);                                       // _2C
	virtual void printleft(Graphics& gfx, int posY, immut char* message);                                         // _30
	virtual void printright(Graphics& gfx, int posY, immut char* message);                                        // _34
	virtual void texture(Graphics& gfx, Texture* texture, int minX, int minY, int maxX, int maxY, RectArea area); // _38
	virtual void texturecentre(Graphics& gfx, Texture* texture, int minY, int width, int height, RectArea area);  // _3C
	virtual void textureleft(Graphics& gfx, Texture* texture, int minY, int width, int height, RectArea area);    // _40
	virtual void textureright(Graphics& gfx, Texture* texture, int minY, int width, int height, RectArea area);   // _44

	void placeCentre();
	void setRect(int, int);   // unused/inlined
	void moveHome(Vector2i&); // unused/inlined

	// _00     = VTBL
	// _00-_14 = CoreNode
	CloseListener* mCloseListener; // _14
	int mWidth;                    // _18
	int mHeight;                   // _1C
	Vector2i mHome;                // _20
	int mStatus;                   // _28
	ID32 _2C;                      // _2C
	Colour mColourA;               // _38
	Colour mAuxColourA;            // _3C
	Colour mColourB;               // _40
	Colour mAuxColourB;            // _44
};

/**
 * @brief TODO
 */
struct ContainerWin : public GmWin {

	/**
	 * @brief TODO
	 */
	class Listener {
	public:
		virtual void informWin(int) = 0; // _08

		// _00 = VTBL
	};

	virtual void open();              // _10
	virtual void close();             // _14
	virtual void update();            // _18
	virtual void doRender(Graphics&); // _1C

	void setWin(int, int, Listener*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	// _14-_48 = GmWin
	Controller* mController;      // _48
	Listener* mContainerListener; // _4C
	int mAnimFramesRemaining;     // _50
	int mUp;                      // _54
	f32 mScrollTime;              // _58
	int mToContainer;             // _5C
	int _60;                      // _60
	int _64;                      // _64
	int _68;                      // _68
	bool mStickWasPushed;         // _6C
};

/**
 * @brief TODO
 */
struct ResultWin : public GmWin {

	virtual void update();            // _18
	virtual void doRender(Graphics&); // _1C

	// _00     = VTBL
	// _00-_14 = CoreNode
	// _14-_48 = GmWin
};

/**
 * @brief TODO
 */
class GmWinMgr {
public:
	GmWinMgr();

	void addWindow(GmWin*);
	void update();
	void render(Graphics&);
	GmWin* getWindow(u32);

	GmWin mRoot;
};

extern GmWinMgr* gmWinMgr;

#endif
