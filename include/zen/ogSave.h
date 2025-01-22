#ifndef _ZEN_OGSAVE_H
#define _ZEN_OGSAVE_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct ogSaveMgr {

	/**
	 * @brief TODO
	 */
	enum SaveStatus {
		// TODO: this
	};

	ogSaveMgr();

	void start();
	SaveStatus update(Controller*);
	void draw(Graphics&);

	// unused/inlined:
	void startDirectSave(s16);

	// TODO: members
};

} // namespace zen

#endif
