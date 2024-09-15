#ifndef _KIO_H
#define _KIO_H

#include "types.h"

/*
 * @brief TODO
 */
struct KIOContext {
	void set(int, u8*, int);
	void write();

	int _00;   // _00
	void* _04; // _04
};

/**
 * @brief TODO
 */
struct KIO {
	KIO();

	void initialise();
	void readMailbox();
	void startWrite(int, u8*, int);
	void writeHeader();

	// unused/inlined:
	void copyEfb(u8*, u16, u16);

	static bool fbCopy;
	static char* haltMessage;
	static int kontMode;

	// TODO: members
	s32 mChannel;        // _00
	KIOContext mContext; // _04
	void* _0C;           // _0C, maybe an array of something?
	u8 _10;              // _10
	u8 _11;              // _11
};

extern KIO* kio;

#endif
