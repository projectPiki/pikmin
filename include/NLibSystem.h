#ifndef _NLIBSYSTEM_H
#define _NLIBSYSTEM_H

#include "types.h"

struct System;

namespace NSystem {
void initSystem(System*);
void randomInt(int);
void getFreeHeap();

extern System* system;
}; // namespace NSystem

#endif
