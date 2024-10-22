#ifndef _MAPCODE_H
#define _MAPCODE_H

#include "types.h"

struct CollTriInfo;

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
