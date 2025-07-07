#ifndef _STRING_H
#define _STRING_H

#include "stl/stdio.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct String {
	String() { init(64); }
	String(int length) { init(length); }
	String(char* str, int length) { init(str, length); }

	int getLength();

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
	bool isSame(char*);

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

#endif
