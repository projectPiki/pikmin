#ifndef _ZEN_SPECTRUMCURSORMGR_H
#define _ZEN_SPECTRUMCURSORMGR_H

#include "types.h"

struct P2DPane;
struct P2DScreen;

namespace zen {

/**
 * @brief TODO
 */
struct SpectrumCursorMgr {
	SpectrumCursorMgr()
	{
		_00 = 0;
		_04 = 0;
		_08 = _0C = 1.0f;
		_10 = _14 = _18 = _1C = 0.0f;
		_20 = _24 = 1.0f;
		_28 = _2C = 1.0f;
	}

	void update();
	void move(f32, f32, f32);
	void scale(f32, f32);
	void init(P2DScreen*, P2DPane*, u32, f32, f32);
	void initPos(f32, f32);
	void initScale(f32);
	u32 makeTag(u32, int);

	// unused/inlined:
	void setMirror(P2DPane*);

	// DLL inlines to do:
	bool checkFinish();

	u32 _00; // _00
	u32 _04; // _04
	f32 _08; // _08
	f32 _0C; // _0C
	f32 _10; // _10
	f32 _14; // _14
	f32 _18; // _18
	f32 _1C; // _1C
	f32 _20; // _20
	f32 _24; // _24
	f32 _28; // _28
	f32 _2C; // _2C
};

} // namespace zen

#endif
