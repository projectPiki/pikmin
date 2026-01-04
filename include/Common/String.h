#ifndef _COMMON_STRING_H
#define _COMMON_STRING_H

#include "types.h"
#include <stdio.h>

struct Stream;

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct String {
	String() { init(64); }
	String(int length) { init(length); }
	String(char* str, int length) { init(str, length); }

	void init(char* str)
	{
		mString = str;
		// `mLength` is uninitialized!
	}

	void init(int length)
	{
		mString = length ? new char[length + 1] : nullptr;
		mLength = length;
	}

	void init(char* str, int length)
	{
		mString = str;
		mLength = length;
	}

	static bool equals(immut char* lhs, immut char* rhs) { return isSame(lhs, rhs); }

	static bool isSame(immut char*, immut char*);
	bool isSame(immut char*) immut;
	bool isSame(immut String* other) immut { return isSame(other->mString); }

	static bool contains(immut char*, immut char*);
	static bool contains(immut char* str, char c)
	{
		immut char substr[] = { c, '\0' };
		return contains(str, substr);
	}
	bool contains(immut char* substr) immut { return contains(mString, substr); }

	static char* dup(immut char*);
	char* dup() immut { return dup(mString); }

	static bool isWhiteSpace(char c) { return c == ' ' || c == '\t' || c == '\r' || c == '\n' || c < ' '; }

	// There isn't a static version of this function (probably because it's unimplemented).
	float toFloat() immut;

	static int toInt(immut char*);
	int toInt() immut;

	static int getLength(immut char*);
	int getLength() immut;

	static u32 calcHash(immut char*);
	u32 calcHash() immut;

	static char* copy(char*, immut char*);
	static bool copyUntil(char*, immut char*, char, immut char**);
	static void concat(char*, immut char*);

	int mLength;   // _00
	char* mString; // _04
};

// in sysCore there are two unexported functions that use String like this:
// default String() ctor inits with 128 and 2048
// So is it this? who knows.
struct StringArray {
	void read(Stream&);
	void write(Stream&);

	int mSize;      // _00
	String* mElems; // _04
};

#endif
