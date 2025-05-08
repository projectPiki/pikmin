#ifndef _ZEN_OGGRAPH_H
#define _ZEN_OGGRAPH_H

#include "types.h"
#include "Piki.h"

struct Controller;
struct Graphics;
struct P2DScreen;
struct P2DPane;

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

	P2DPane* mPane;                 // _00
	int mMaxPikis;                  // _04
	int mMinPikis;                  // _08
	int _0C;                        // _0C
	bool mHasColor[PikiColorCount]; // _10
};

} // namespace zen

#endif
