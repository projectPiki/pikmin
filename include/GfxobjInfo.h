#ifndef _GFXOBJINFO_H
#define _GFXOBJINFO_H

#include "ID32.h"

struct GfxobjInfo {
	// May be inlined!
#ifdef _WIN32
	GfxobjInfo();

	void insertAfter(class GfxobjInfo*);
	void remove();
#endif
	virtual void attach(); // _08
	virtual void detach(); // _0C

	GfxobjInfo* mPrevious; // _04
	GfxobjInfo* mNext;     // _08
	s8* mString;           // _0C
	ID32 mId;              // _10
	s32 mAttached;         // _1C
};

#endif
