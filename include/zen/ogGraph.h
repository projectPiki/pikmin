#ifndef _ZEN_OGGRAPH_H
#define _ZEN_OGGRAPH_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DScreen;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct ogGraphMgr {
	ogGraphMgr(P2DScreen*);

	void SetDummyLineData();
	void MakeData();
	void draw(u8);

	u8 _00[0x14]; // _00, unknown
};

} // namespace zen

#endif
