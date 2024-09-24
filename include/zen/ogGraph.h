#ifndef _ZEN_OGGRAPH_H
#define _ZEN_OGGRAPH_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DScreen;

namespace zen {

/**
 * @brief TODO
 */
struct ogGraphMgr {
	ogGraphMgr(P2DScreen*);

	void SetDummyLineData();
	void MakeData();
	void draw(u8);

	// TODO: members
};

} // namespace zen

#endif
