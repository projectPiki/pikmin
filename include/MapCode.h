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
 * @brief This used to be a struct, but these are all static methods, I don't think it's a struct.
 */
namespace MapCode {

int getAttribute(CollTriInfo*);
int getSlipCode(CollTriInfo*);
bool isBald(CollTriInfo*);

// unused/inlined
char* getAttributeName(int); // UNUSED
}; // namespace MapCode

#endif
