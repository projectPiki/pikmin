#ifndef _MAPCODE_H
#define _MAPCODE_H

#include "types.h"

struct CollTriInfo;

/**
 * @brief TODO.
 */
enum MapAttributes {
	ATTR_NULL  = -1,
	ATTR_Solid = 0, // "solid"
	ATTR_Rock  = 1, // "rock"
	ATTR_Grass = 2, // "grass"
	ATTR_Wood  = 3, // "wood"
	ATTR_Mud   = 4, // "mud"
	ATTR_Water = 5, // "water"
	ATTR_Hole  = 6, // "hole"
};

/**
 * @brief TODO.
 */
struct MapCode {
	static int getAttribute(CollTriInfo*);
	static int getSlipCode(CollTriInfo*);
	static bool isBald(CollTriInfo*);

	// unused/inlined
	static immut char* getAttributeName(int); // UNUSED
};

#endif
