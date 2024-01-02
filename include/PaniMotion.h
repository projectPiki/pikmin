#ifndef _PANIMOTION_H
#define _PANIMOTION_H

#include "types.h"

struct PaniAnimKeyListener;

/**
 * @brief TODO
 */
struct PaniMotionInfo {
	PaniMotionInfo(int);
	PaniMotionInfo(int, PaniAnimKeyListener*);

	void init(int, PaniAnimKeyListener*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniMotionTable {
	PaniMotionTable(int);

	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniMotion {
	PaniMotion(int);

	void init(int, int);

	// TODO: members
};

#endif
