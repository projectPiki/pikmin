#ifndef _AYUHEAP_H
#define _AYUHEAP_H

#include "AyuStack.h"

struct AyuHeap : public AyuStack {
	AyuHeap(void);

	void init(char*, int, void*, int);

	s32 _24; // _24
};

#endif