#ifndef _ZEN_SYS_H
#define _ZEN_SYS_H

#include "types.h"

struct Texture;

namespace zen {

// global utility functions:
void makePathName(const char*, const char*, char*);
::Texture* loadTexExp(const char*, bool, bool);

} // namespace zen

#endif
