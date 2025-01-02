#ifndef _ZEN_BBOARDCOLOURANIM_H
#define _ZEN_BBOARDCOLOURANIM_H

#include "types.h"

struct Colour;

namespace zen {

/*
 * @brief TODO
 */
struct bBoardColourAnimData {
	bBoardColourAnimData()
	{
		_00 = 0;
		_01 = 0;
		_02 = 0;
		_03 = 0;
		_04 = 0;
		_08 = 0;
		_0C = 0;
	}

	void set(u8*);

	// unused/inlined:
	~bBoardColourAnimData() { }

	u8 _00;  // _00
	u8 _01;  // _01
	u8 _02;  // _02
	u8 _03;  // _03
	u32 _04; // _04, unknown
	u32 _08; // _08, unknown
	u32 _0C; // _0C, unknown
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
