#ifndef _ID32_H
#define _ID32_H

#include "types.h"

struct AgeServer;
struct RandomAccessStream;

/**
 * @brief A 32-bit identifier often treated as four characters.
 */
struct ID32 {
	ID32();
	ID32(u32 id);

	void operator=(u32 id);
	bool operator==(u32 id) immut;
	bool operator!=(u32 id) immut;

	bool match(u32 id, char wild = '*') immut;
	void print() immut;
	void read(RandomAccessStream& stream);
	void setID(u32 id);
	void sprint(char* str) immut;
	void updateID();
	void updateString();
	void write(RandomAccessStream& stream) immut;

	void genAge(AgeServer&, char*);
	void ageChangeID() { updateID(); }

	u32 mId;           // _00, 32-bit ID (often treated as 4 chars)
	char mStringID[5]; // _04, null-terminated string view of mId
};

#endif
