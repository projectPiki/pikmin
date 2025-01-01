#ifndef _ZEN_BBOARDCOLOURANIM_H
#define _ZEN_BBOARDCOLOURANIM_H

#include "types.h"

struct Colour;

namespace zen {

/*
 * @brief TODO
 */
struct bBoardColourAnimData {
	void set(u8*);

	// unused/inlined:
	~bBoardColourAnimData();

	u8 _00; // _00
	u8 _01; // _01
	u8 _02; // _02
};

/**
 * @brief TODO
 */
struct bBoardColourAnim {
	void update(f32, Colour*, Colour*);
	void init(zen::bBoardColourAnimData*, s16);

	f32 _00;                         // _00
	u8 _04;                          // _04
	s16 _06;                         // _06
	bBoardColourAnimData* mAnimData; // _08
};

} // namespace zen

#endif
