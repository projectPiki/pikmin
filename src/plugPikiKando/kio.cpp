#include "KIO.h"
#include "sysNew.h"
#include "Dolphin/os.h"
#include "Dolphin/hio.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

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
static void hioCallback() { kio->readMailbox(); }

/*
 * --INFO--
 * Address:	80084374
 * Size:	00005C
 */
KIO::KIO()
{
	_10         = 0;
	kio         = this;
	_0C         = new (0x20) u8[0x100]; // something goes here, probably not this
	fbCopy      = false;
	_11         = false;
	haltMessage = nullptr;
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
		_10 = 0;
	} else {
		_10 = 1;
		readMailbox();
		kontMode = 2;
	}
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
		kontMode = 0;
		_11      = 0;
		break;
	case 0x100002:
		kontMode = 1;
		_11      = 0;
		break;
	case 0x100001:
		kontMode = 2;
		_11      = 0;
		break;
	case 0x100006:
		mContext.write();
		break;
	case 0x100003:
		fbCopy = true;
		_11    = 1;
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
void KIO::startWrite(int p1, u8* p2, int p3)
{
	mContext.set(p1, p2, p3);
	writeHeader();
}

/*
 * --INFO--
 * Address:	80084558
 * Size:	000064
 */
void KIO::writeHeader()
{
	if (_10) {
		DCFlushRange(_0C, 0x100);

		if (HIOWrite(0x500, _0C, 0x100) != FALSE) {
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
void KIOContext::set(int p1, u8* p2, int p3)
{
	_00      = p3;
	int* buf = (int*)kio->_0C;
	buf[1]   = p3;
	buf[0]   = p1;
	_04      = p2;
}

/*
 * --INFO--
 * Address:	800845D8
 * Size:	0000E8
 */
void KIOContext::write()
{
	if (_00 <= 0) {
		if (KIO::haltMessage) {
			OSPanic(__FILE__, 166, KIO::haltMessage);
		}
		return;
	}

	s32 bufSize = _00;
	if (_00 > 0x1FA00) {
		bufSize = 0x1FA00;
	}

	s32 size = bufSize;
	if ((s32)bufSize % 32) {
		size = (bufSize >> 5) * 0x20 + 0x20;
	}

	DCFlushRange(_04, size);
	if (HIOWrite(0x600, _04, size) != FALSE) {
		HIOWriteMailbox(0x100004);
		_04 = (void*)((u32)_04 + bufSize);
		_00 -= bufSize;
	}
}
