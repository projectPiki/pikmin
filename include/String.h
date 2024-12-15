#ifndef _STRING_H
#define _STRING_H

#include "types.h"
#include "stl/stdio.h"

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct String {
	String() { init(64); }
	String(char* str, int length) { init(str, length); }

	int getLength();

	// unused/inlined:
	bool isSame(char*);
	f32 toFloat();
	int toInt();
	int getLength(char*);
	bool isSame(char*, char*);
	void dup(char*);
	void contains(char*, char*);
	void copy(char*, char*);
	void copyUntil(char*, char*, char, char**);
	void concat(char*, char*);
	void calcHash(char*);
	void calcHash();
	void toInt(char*);

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

	int mLength;   // _00
	char* mString; // _04
};

#endif
