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

	void update();
	void move(f32, f32, f32);
	void scale(f32, f32);
	void init(P2DScreen*, P2DPane*, u32, f32, f32);
	void initPos(f32, f32);
	void initScale(f32);
	void makeTag(u32, int);

	// unused/inlined:
	void setMirror(P2DPane*);

	// TODO: members
};

} // namespace zen

#endif
