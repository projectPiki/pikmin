#ifndef _NLIB_SYSTEM_H
#define _NLIB_SYSTEM_H

#include "types.h"

struct System;

/**
 * @brief TODO
 */
struct NHeap {
	NHeap(int); // unused/inlined

	virtual void release();       // _08
	virtual void addHeap(NHeap*); // _0C

	// TODO: members
};

namespace NSystem {
void initSystem(System*);
void randomInt(int);
void getFreeHeap();

extern System* system;
}; // namespace NSystem

#endif
