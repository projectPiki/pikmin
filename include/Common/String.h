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

	static bool equals(char* lhs, char* rhs) { return isSame(lhs, rhs); }

	static bool isSame(char*, char*);
	bool isSame(immut char*);
	bool isSame(String* other) { return isSame(other->mString); }

	static bool contains(char*, char*);
	static bool contains(char* str, char c)
	{
		char substr[] = { c, '\0' };
		return contains(str, substr);
	}
	bool contains(char* substr) { return contains(mString, substr); }

	static char* dup(char*);
	char* dup() { return dup(mString); }

	static bool isWhiteSpace(char c)
	{
		return c == ' ' || c == '\t' || c == '\r' || c == '\n' || c < ' ';
	}

	// There isn't a static version of this function (probably because it's unimplemented).
	float toFloat();

	static int toInt(char*);
	int toInt();

	static int getLength(char*);
	int getLength() immut;

	static u32 calcHash(char*);
	u32 calcHash();

	static char* copy(char*, char*);
	static bool copyUntil(char*, char*, char, char**);
	static void concat(char*, char*);

	int mLength;   // _00
	char* mString; // _04
};

// in sysCore there are two unexported functions that use String like this:
// default String() ctor inits with 128 and 2048
// So is it this? who knows.
struct StringArray {
	void read(Stream&);
	void write(Stream&);
};

#endif
