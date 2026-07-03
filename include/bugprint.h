#ifndef _BUGPRINT_H
#define _BUGPRINT_H

#include "types.h"

/**
 * @todo Documentation
 */
struct BugPrintBuffer {
public:
	BugPrintBuffer();

	void clear(void);
	void update(void);
	void print(immut char*, int);

	int getFrame(void) { return mFrame; }

protected:
	int findLine(int);

	char* mBuffer; // _00
	int mBufPos;   // _04
	int mCapacity; // _08
	int mFrame;    // _0C
};

extern BugPrintBuffer* bugPrintBuffer;

// This symbol has no mangling in the ILK.  Maybe it was meant to be accessible to even C code?
extern "C" {
void _bugPrint(immut char* fmt, ...);
}

#if defined(WIN32)
#define BUGPRINT(...) _bugPrint(__VA_ARGS__);
#else
#define BUGPRINT(...) (__VA_ARGS__)
#endif

#endif
