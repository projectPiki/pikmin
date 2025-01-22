#ifndef _ZEN_OGMAKEDEFAULT_H
#define _ZEN_OGMAKEDEFAULT_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct ogScrMakeDefaultMgr {

	/**
	 * @brief TODO
	 */
	enum MakeDefaultStatus {
		// TODO: this
	};

	ogScrMakeDefaultMgr();

	void start();
	MakeDefaultStatus update(Controller*);
	void draw(Graphics&);
	bool checkTypingAll();

	// unused/inlined:

	// TODO: members
};

} // namespace zen

#endif
