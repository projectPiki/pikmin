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
		_00     = 0;
		_01     = 0;
		_02.all = 0;
		_03     = 0;
		_04     = 0;
		_08     = 0;
		_0C     = 0;
	}

	void set(u8*);

	// unused/inlined:
	~bBoardColourAnimData() { }

	u8 _00; // _00
	u8 _01; // _01
	union {
		struct {
			u8 _m0 : 1;
			u8 _m1 : 3;
			u8 _m4 : 1;
			u8 _m5 : 1;
			u8 _m6 : 1;
			u8 _m7 : 1;
		} bits;
		u8 all;
	} _02;   // _02
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
	void init(zen::bBoardColourAnimData* data, s16 p2)
	{
		_00       = 0.0f;
		_04       = 0;
		mAnimData = data;
		if (mAnimData) {
			if (mAnimData->_02.all) {
				_06 = p2;
			} else {
				_06 = mAnimData->_01;
			}
		} else {
			_06 = p2;
		}
	}

	f32 _00;                         // _00
	u8 _04;                          // _04
	s16 _06;                         // _06
	bBoardColourAnimData* mAnimData; // _08
};

} // namespace zen

#endif
