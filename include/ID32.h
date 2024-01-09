#ifndef _ID32_H
#define _ID32_H

#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x9.
 */
struct ID32 {
	ID32(void);
	ID32(u32);

	ID32& operator=(ID32 const&);
	void operator =(u32);
	bool operator==(u32);
	bool operator!=(u32);

	void ageChangeID(void);
	void genAge(struct AgeServer&, char*);
	bool match(u32, char);
	void print(void);
	void read(struct RandomAccessStream&);
	void setID(u32);
	void sprint(char*);
	void updateID(void);
	void updateString(void);
	void write(RandomAccessStream&);

	u32 mId;           // _00
	char mStringID[5]; // _04
};

#endif
