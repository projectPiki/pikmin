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

	// TODO: members
};

/*
 * @brief TODO
 */
struct bBoardColourAnim {
	void update(f32, Colour*, Colour*);
	void init(zen::bBoardColourAnimData*, s16);

	// TODO: members
};

} // namespace zen

#endif
