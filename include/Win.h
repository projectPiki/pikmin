#ifndef _WIN_H
#define _WIN_H

#include "types.h"
#include "CoreNode.h"

struct Graphics;
struct RectArea;
struct Texture;
struct Vector2i;

/**
 * @brief TODO
 *
 * @warning This is meant to inherit CoreNode according to RTTI. However, it doesn't seem to have a vtable? Unsure what its deal is.
 */
struct GmWin : public CoreNode {

	/**
	 * @brief TODO
	 */
	struct CloseListener {
		virtual void onCloseWindow(); // _08

		// _00 = VTBL?
		// TODO: members
	};

	GmWin(); // unused/inlined

	void open();
	void close();
	void render(Graphics&);
	void placeCentre();
	void print(Graphics&, int, int, char*);
	void printcentre(Graphics&, int, char*);
	void printright(Graphics&, int, char*);
	void printleft(Graphics&, int, char*);
	void printStart(Graphics&);
	void texture(Graphics&, Texture*, int, int, int, int, RectArea);
	void texturecentre(Graphics&, Texture*, int, int, int, RectArea);
	void textureleft(Graphics&, Texture*, int, int, int, RectArea);
	void textureright(Graphics&, Texture*, int, int, int, RectArea);

	// unused/inlined:
	void setRect(int, int);
	void moveHome(Vector2i&);
	void doRender(Graphics&);
	void update();

	// _00     = VTBL?
	// _00-_14 = CoreNode?
	// TODO: members
};

/**
 * @brief TODO
 */
struct ContainerWin {

	/**
	 * @brief TODO
	 */
	struct Listener {
		virtual void informWin(int) = 0; // _08

		// _00 = VTBL
	};

	// unused/inlined:
	void doRender(Graphics&);
	void setWin(int, int, Listener*);
	void update();
	void open();
	void close();

	// TODO: members
};

/**
 * @brief TODO
 */
struct ResultWin {
	// unused/inlined:
	void doRender(Graphics&);
	void update();

	// TODO: members
};

/**
 * @brief TODO
 */
struct GmWinMgr {
	GmWinMgr();

	void addWindow(GmWin*);
	void update();
	void render(Graphics&);
	void getWindow(u32);

	// TODO: members
};

#endif
