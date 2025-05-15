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
 * @brief Manages calculation and rendering of Pikmin population graphs, typically for result screens.
 *
 * @note Size: 0x14.
 */
struct ogGraphMgr {
	ogGraphMgr(P2DScreen* pParent);

	void SetDummyLineData();
	void MakeData();
	void draw(u8 alpha);

	P2DPane* mParent;               // _00
	int mMaxPikis;                  // _04
	int mMinPikis;                  // _08
	int mDefaultMaxPikmin;          // _0C
	bool mHasColor[PikiColorCount]; // _10
};

} // namespace zen

#endif
