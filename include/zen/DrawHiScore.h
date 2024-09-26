#ifndef _ZEN_DRAWHISCORE_H
#define _ZEN_DRAWHISCORE_H

#include "types.h"

struct Graphics;
struct Controller;
struct P2DScreen;

namespace zen {

/**
 * @brief TODO
 */
struct DrawHiScore {
	DrawHiScore();

	void update(Controller*);
	void draw(Graphics&);
	void start();
	void rewriteNumber(P2DScreen*, u32, int, int, bool);

	// TODO: members
};

} // namespace zen

#endif
