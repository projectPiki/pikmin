#ifndef _ID32_H
#define _ID32_H

#include "types.h"

struct ID32 {
	ID32(void);
	ID32(u32);
	class ID32& operator=(class ID32 const&);
	void operator       =(u32);
	bool operator==(u32);
	bool operator!=(u32);
	void ageChangeID(void);
	void genAge(class AgeServer&, char*);
	bool match(u32, char);
	void print(void);
	void read(class RandomAccessStream&);
	void setID(u32);
	void sprint(char*);
	void updateID(void);
	void updateString(void);
	void write(class RandomAccessStream&);

	u32 m_id;    // _0
	char sId[5]; // _4
};

#endif
