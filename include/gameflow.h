#ifndef _GAMEFLOW_H
#define _GAMEFLOW_H

#include "types.h"

typedef struct GameFlow;

struct GameFlow {
	char filler[0x355]; // _00
	void* loadShape(char*, bool);
};

extern GameFlow gameflow;

#endif
