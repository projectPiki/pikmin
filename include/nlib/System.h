#ifndef _NLIB_SYSTEM_H
#define _NLIB_SYSTEM_H

#include "nlib/Array.h"
#include "types.h"
#include <system.h>

struct System;

/**
 * @brief TODO
 */
struct NHeap {
	NHeap(int); // unused/inlined

	virtual void release();           // _08
	virtual void addHeap(NHeap* heap) // _0C
	{
		mHeapArray->add(heap);
	}

	// _00 = VTBL
	NArray<NHeap>* mHeapArray; // _04
};

namespace NSystem {
extern ::System* system;

void initSystem(::System*);
int randomInt(int);
u32 getFreeHeap();

inline f32 getFrameTime()
{
	return system->getFrameTime();
}
inline f32 random()
{
	return system->getRand(1.0f);
}

}; // namespace NSystem

#endif
