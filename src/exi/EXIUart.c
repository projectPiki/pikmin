// This file also implements "OSUartExi.c" (`OS_BUILD_VERSION < 20011217L`). Don't break compatibility!

#include "Dolphin/exi.h"
#include "Dolphin/os.h"

// For ease of implementing multiple revisions, these magic numbers and variables that were turned
// into variables and renamed (respectively) go by their final name everywhere in this file and are
// silently replaced for older revisions via the below macros.
#if OS_BUILD_VERSION >= 20011217L
static s32 Chan;
static u32 Dev;
static u32 Enabled         = 0;
static u32 BarnacleEnabled = 0;
#else
#define Chan    0
#define Dev     1
#define Enabled serEnabled
static u32 serEnabled = 0;
#endif

/**
 * @TODO: Documentation
 */
u32 InitializeUART(u32 baudRate)
{
#if OS_BUILD_VERSION >= 20011217L
	if (BarnacleEnabled == EXI_MAGIC) {
		return 0;
	}
#endif

	if (!(OSGetConsoleType() & OS_CONSOLE_DEVELOPMENT)) {
		Enabled = 0;
		return 2;
	}

#if OS_BUILD_VERSION >= 20011217L
	Chan = 0;
	Dev  = 1;
#endif
	Enabled = EXI_MAGIC;
	return 0;
}

/**
 * @TODO: Documentation
 */
u32 ReadUARTN(void* bytes, u32 length)
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

	if (!EXISelect(Chan, Dev, EXI_FREQ_8M))
		return -1;

	cmd = EXI_TX << 6;
	EXIImm(Chan, &cmd, 4, EXI_WRITE, NULL);
	EXISync(Chan);

	EXIImm(Chan, &cmd, 1, EXI_READ, NULL);
	EXISync(Chan);
	EXIDeselect(Chan);

	return 16 - (int)((cmd >> 24) & 0xff);
}

/**
 * @TODO: Documentation
 */
u32 WriteUARTN(void* buf, u32 len)
{
	u32 cmd;
	int qLen;
	s32 xLen;
	char* ptr;
	BOOL locked;
	u32 error;

	if (Enabled != EXI_MAGIC)
		return 2;

	locked = EXILock(Chan, Dev, 0);
	if (!locked) {
		return 0;
	}

	for (ptr = (char*)buf; ptr - (char*)buf < len; ptr++) {
		if (*ptr == '\n')
			*ptr = '\r';
	}

	error = 0;
	cmd   = (EXI_TX | 0x2000000) << 6;
	while (len) {
		qLen = QueueLength();
		if (qLen < 0) {
#if OS_BUILD_VERSION >= 20011217L
			error = 3;
#else
			error = -1;
#endif
			break;
		}

		if (qLen < 12 && qLen < len)
			continue;

		if (!EXISelect(Chan, Dev, EXI_FREQ_8M)) {
#if OS_BUILD_VERSION >= 20011217L
			error = 3;
#else
			error = -1;
#endif
			break;
		}

		EXIImm(Chan, &cmd, 4, EXI_WRITE, NULL);
		EXISync(Chan);

		while (qLen && len) {
			if (qLen < 4 && qLen < len)
				break;
			xLen = (len < 4) ? (s32)len : 4;
			EXIImm(Chan, buf, xLen, EXI_WRITE, NULL);
			(char*)buf += xLen;
			len -= xLen;
			qLen -= xLen;
			EXISync(Chan);
		}
		EXIDeselect(Chan);
	}

	EXIUnlock(Chan);
	return error;
}
