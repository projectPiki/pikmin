#ifndef _ZEN_OGGRAPH_H
#define _ZEN_OGGRAPH_H

#include "types.h"

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

	P2DPane* mPane;  // _00
	int mMinPikis;   // _04
	int mMaxPikis;   // _08
	int _0C;         // _0C
	bool mHasBlue;   // _10
	bool mHasRed;    // _11
	bool mHasYellow; // _12
};

} // namespace zen

#endif
