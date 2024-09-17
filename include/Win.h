#ifndef _WIN_H
#define _WIN_H

#include "types.h"
#include "CoreNode.h"

struct Texture;

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
	void render(struct Graphics&);
	void placeCentre();
	void print(Graphics&, int, int, char*);
	void printcentre(Graphics&, int, char*);
	void printright(Graphics&, int, char*);
	void printleft(Graphics&, int, char*);
	void printStart(Graphics&);
	void texture(Graphics&, Texture*, int, int, int, int, struct RectArea);
	void texturecentre(Graphics&, Texture*, int, int, int, struct RectArea);
	void textureleft(Graphics&, Texture*, int, int, int, struct RectArea);
	void textureright(Graphics&, Texture*, int, int, int, struct RectArea);

	// unused/inlined:
	void setRect(int, int);
	void moveHome(struct Vector2i&);
	void doRender(Graphics&);

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

	void open();

	// TODO: members
};

#endif
