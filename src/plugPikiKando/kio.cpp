#include "KIO.h"
#include "sysNew.h"
#include "Dolphin/os.h"
#include "Dolphin/hio.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

KIO* kio;
bool KIO::fbCopy;
char* KIO::haltMessage;
int KIO::kontMode = 2;

/*
 * --INFO--
 * Address:	80084340
 * Size:	000010
 */
static BOOL hioEnumCallback(s32 chan)
{
	kio->mChannel = chan;
	return FALSE;
}

/*
 * --INFO--
 * Address:	80084350
 * Size:	000024
 */
static void hioCallback()
{
	kio->readMailbox();
}

/*
 * --INFO--
 * Address:	80084374
 * Size:	00005C
 */
KIO::KIO()
{
	mIsReady      = false;
	kio           = this;
	mHeaderBuffer = new (0x20) u8[0x100]; // something goes here, probably not this
	fbCopy        = false;
	mIsActive     = false;
	haltMessage   = nullptr;
}

/*
 * --INFO--
 * Address:	800843D0
 * Size:	000074
 */
void KIO::initialise()
{
	HIOEnumDevices(hioEnumCallback);
	if (HIOInit(mChannel, hioCallback) == FALSE) {
		mIsReady = false;
		return;
	}

	mIsReady = true;
	readMailbox();
	kontMode = 2;
}

/*
 * --INFO--
 * Address:	80084444
 * Size:	0000DC
 */
void KIO::readMailbox()
{
	u32 mail = 0;
	if (HIOReadMailbox(&mail) == FALSE) {
		return;
	}

	switch (mail) {
	case 0x100000:
		kontMode  = 0;
		mIsActive = false;
		break;
	case 0x100002:
		kontMode  = 1;
		mIsActive = false;
		break;
	case 0x100001:
		kontMode  = 2;
		mIsActive = false;
		break;
	case 0x100006:
		mContext.write();
		break;
	case 0x100003:
		fbCopy    = true;
		mIsActive = true;
		break;
	default:
		kontMode = 2;
		break;
	}
}

/*
 * --INFO--
 * Address:	80084520
 * Size:	000038
 */
void KIO::startWrite(int p1, u8* bufferStart, int bufferSize)
{
	mContext.set(p1, bufferStart, bufferSize);
	writeHeader();
}

/*
 * --INFO--
 * Address:	80084558
 * Size:	000064
 */
void KIO::writeHeader()
{
	if (mIsReady) {
		// Set the header buffer
		DCFlushRange(mHeaderBuffer, 0x100);

		// Set the header buffer to the mailbox
		if (HIOWrite(0x500, mHeaderBuffer, 0x100) != FALSE) {
			// Signal the header is done
			HIOWriteMailbox(0x100003);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void KIO::copyEfb(u8*, u16, u16)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800845BC
 * Size:	00001C
 */
void KIOContext::set(int p1, u8* bufferStart, int bufferSize)
{
	mBufferSize  = bufferSize;
	int* header  = (int*)kio->mHeaderBuffer;
	header[1]    = bufferSize;
	header[0]    = p1;
	mBufferStart = bufferStart;
}

/*
 * --INFO--
 * Address:	800845D8
 * Size:	0000E8
 */
void KIOContext::write()
{
	// Check if there is data left to write
	if (mBufferSize <= 0) {
		if (KIO::haltMessage) {
			OSPanic(__FILE__, 166, KIO::haltMessage);
		}
		return;
	}

	// Limit the size of the write to 0x1FA00
	s32 writeSize = mBufferSize;
	if (mBufferSize > 0x1FA00) {
		writeSize = 0x1FA00;
	}

	// Align the size to 32 bytes
	s32 alignedSize = writeSize;
	if ((s32)writeSize % 32) {
		alignedSize = (writeSize >> 5) * 0x20 + 0x20;
	}

	// Flush the data cache and write the data
	DCFlushRange(mBufferStart, alignedSize);
	if (HIOWrite(0x600, mBufferStart, alignedSize) != FALSE) {
		// Signal the write is done
		HIOWriteMailbox(0x100000 | 0x4);

		// Move the buffer pointer and decrease the buffer size
		mBufferStart = (void*)((u32)mBufferStart + writeSize);
		mBufferSize -= writeSize;
	}
}
