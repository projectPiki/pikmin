#ifndef _MAPCODE_H
#define _MAPCODE_H

#include "types.h"

struct CollTriInfo;

/**
 * @brief TODO.
 */
enum MapAttributes {
	ATTR_Unk0 = 0,
	ATTR_Unk1 = 1,
	ATTR_Unk2 = 2,
	ATTR_Unk3 = 3,
	ATTR_Unk4 = 4,
	ATTR_Unk5 = 5,
};

/**
 * @brief This used to be a struct, but these are all static methods, I don't think it's a struct.
 */
namespace MapCode {

u32 getAttribute(CollTriInfo*);
u32 getSlipCode(CollTriInfo*);
bool isBald(CollTriInfo*);

// unused/inlined
char* getAttributeName(int); // UNUSED
};                           // namespace MapCode

#endif
