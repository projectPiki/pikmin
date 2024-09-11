#include "Dolphin/os.h"

static u32 serEnabled = 0;

/*
 * --INFO--
 * Address:	801FD7C4
 * Size:	000048
 */
u32 InitializeUART(u32 baudRate)
{
	if (!(OSGetConsoleType() & OS_CONSOLE_DEVELOPMENT)) {
		serEnabled = 0;
		return 2;
	}

	serEnabled = EXI_MAGIC;
	return 0;
}

/*
 * --INFO--
 * Address:	801FD80C
 * Size:	000008
 */
u32 ReadUARTN(void* bytes, u32 len) { return 4; }

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
static int QueueLength(void)
{
	u32 cmd;

	if (!EXISelect(0, 1, EXI_FREQ_8M))
		return -1;

	cmd = EXI_TX << 6;
	EXIImm(0, &cmd, 4, EXI_WRITE, NULL);
	EXISync(0);

	EXIImm(0, &cmd, 1, EXI_READ, NULL);
	EXISync(0);
	EXIDeselect(0);

	return 16 - (int)((cmd >> 24) & 0xff);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FD814
 * Size:	000200
 */
u32 WriteUARTN(const void* buf, u32 len)
{
	u32 cmd;
	int qLen;
	s32 xLen;
	u8* ptr;
	BOOL locked;
	u32 error;

	if (serEnabled != EXI_MAGIC)
		return 2;

	locked = EXILock(0, 1, 0);
	if (!locked) {
		return 0;
	}

	for (ptr = (u8*)buf; ptr - buf < len; ptr++) {
		if (*ptr == '\n')
			*ptr = '\r';
	}

	error = 0;
	cmd   = (EXI_TX | 0x2000000) << 6;
	while (len) {
		qLen = QueueLength();
		if (qLen < 0) {
			error = -1;
			break;
		}

		if (qLen < 12 && qLen < len)
			continue;

		if (!EXISelect(0, 1, EXI_FREQ_8M)) {
			error = -1;
			break;
		}

		EXIImm(0, &cmd, 4, EXI_WRITE, NULL);
		EXISync(0);

		while (qLen && len) {
			if (qLen < 4 && qLen < len)
				break;
			xLen = (len < 4) ? (s32)len : 4;
			EXIImm(0, (void*)buf, xLen, EXI_WRITE, NULL);
			(u8*)buf += xLen;
			len -= xLen;
			qLen -= xLen;
			EXISync(0);
		}
		EXIDeselect(0);
	}

	EXIUnlock(0);
	return error;
}
