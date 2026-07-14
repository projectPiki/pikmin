#ifndef _BUGPRINT_H
#define _BUGPRINT_H

#include "types.h"

/**
 * @todo Documentation
 */
class BugPrintBuffer {
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

// MSVC appears to "mangle" symbols with C linkage, appending a '_' character like we see this symbol
// having the ILK, so that must be what happened.  Maybe it was meant to be accessible to even C code?
extern "C" {
void bugPrint(immut char* fmt, ...);
}

// DO NOT define this as a variadic macro (when matching).
// See the comment in "DebugLog.h" regarding `PRINT` and `ERROR` for the reason why.
#if defined(WIN32)
#define BUGPRINT bugPrint
#else
#define BUGPRINT
#endif

#endif
