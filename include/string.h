#ifndef _STRING_H
#define _STRING_H

#include "types.h"
#include "Stream.h"

struct String {
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

	u32 mLength; // _00
	char* mStr;  // _04
};

#endif
