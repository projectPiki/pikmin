#include "Dolphin/os.h"

static u32 serEnabled = 0;

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
u32 ReadUARTN(void* bytes, u32 len)
{
	return 4;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000098
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

/**
 * @TODO: Documentation
 */
u32 WriteUARTN(const void* buf, u32 len)
{
	u32 cmd;
	int qLen;
	s32 xLen;
#if defined(VERSION_G98E01_PIKIDEMO)
	char* ptr;
#else
	u8* ptr;
#endif
	BOOL locked;
	u32 error;

	if (serEnabled != EXI_MAGIC)
		return 2;

	locked = EXILock(0, 1, 0);
	if (!locked) {
		return 0;
	}

#if defined(VERSION_G98E01_PIKIDEMO)
	for (ptr = (char*)buf; ptr - buf < len; ptr++) {
#else
	for (ptr = (u8*)buf; ptr - buf < len; ptr++) {
#endif
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
