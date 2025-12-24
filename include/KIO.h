#ifndef _KIO_H
#define _KIO_H

#include "types.h"

/*
 * @brief TODO
 */
enum KontMode {
	KONT_Save = 0,
	KONT_Load = 1,
};

/*
 * @brief Identifies the kind of payload being sent via KIO/HIO.
 *
 * This value is written into the first word of the KIO header buffer.
 */
enum KIOWriteKind {
	KIOWRITE_MemoryCard       = 0,
	KIOWRITE_ControllerStream = 1,
};

/*
 * @brief TODO
 */
struct KIOContext {
	void set(int writeKind, u8* bufferStart, int bufferSize);
	void write();

	int mBufferSize;    // _00
	void* mBufferStart; // _04
};

/**
 * @brief TODO
 */
struct KIO {
	KIO();

	void initialise();
	void readMailbox();
	void startWrite(int writeKind, u8* bufferStart, int bufferSize);
	void writeHeader();

	// unused/inlined:
	void copyEfb(u8*, u16, u16);

	static bool fbCopy;
	static immut char* haltMessage;
	static int kontMode; // see KontMode enum

	s32 mChannel;        // _00
	KIOContext mContext; // _04
	void* mHeaderBuffer; // _0C, maybe an array of something?
	bool mIsReady;       // _10
	bool mIsActive;      // _11
};

extern KIO* kio;

#endif
