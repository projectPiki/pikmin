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

	int getLength() immut;

	// unused/inlined:
	f32 toFloat();
	int toInt();
	char* dup(char*);
	bool contains(char*, char*);
	char* copy(char*, char*);
	bool copyUntil(char*, char*, char, char**);
	u32 calcHash(char*);
	u32 calcHash();
	int toInt(char*);
	bool isSame(immut char*);

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

	static bool isSame(char*, char*);
	static void concat(char*, char*);
	static int getLength(char*);

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
