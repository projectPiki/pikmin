#ifndef _ZEN_OGSTART_H
#define _ZEN_OGSTART_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct ogScrStartMgr {
	ogScrStartMgr();

	void start();
	void stop();
	int update(Controller*);
	void draw(Graphics&);

	u8 _00[0x14]; // _00, unknown
};

} // namespace zen

#endif
