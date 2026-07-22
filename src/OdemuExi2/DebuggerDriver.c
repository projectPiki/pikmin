#include "Dolphin/db.h"
#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"
#include "types.h"

static MTRCallbackType MTRCallback;
static void (*DBGCallback)(u32, OSContext*);

static u32 SendMailData;
static s32 RecvDataLeng;

static u8* pEXIInputFlag;
static u8 EXIInputFlag;

static u8 SendCount = 0x80;

#define IS_TRUE(x)         ((x) != FALSE)
#define IS_FALSE(x)        !IS_TRUE(x)
#define ROUND_UP(x, align) (((x) + (align) - 1) & (-(align)))

/**
 * @brief Initializes EXI channel 2 for debugger communication.
 * @note UNUSED Size: 000034
 */
void DBGEXIInit()
{
	__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_2);
	__EXIRegs[EXI_CHAN_2_STAT] = 0;
}

/**
 * @brief Selects EXI channel 2 with the provided selection bits.
 * @note UNUSED Size: 000028
 */

static u32 DBGEXISelect(u32 selectBits)
{
	u32 regs = __EXIRegs[EXI_CHAN_2_STAT];
	regs &= 0x405;
	regs |= 0x80 | (selectBits << 4);
	__EXIRegs[EXI_CHAN_2_STAT] = regs;
	return TRUE;
}

/**
 * @brief Deselects EXI channel 2.
 * @note UNUSED Size: 00001C
 */
BOOL DBGEXIDeselect(void)
{
	__EXIRegs[EXI_CHAN_2_STAT] &= 0x405;
	return TRUE;
}

/**
 * @brief Waits until the current EXI immediate transfer completes.
 * @note UNUSED Size: 00001C
 */
static BOOL DBGEXISync()
{
	while (__EXIRegs[EXI_CHAN_2_CONTROL] & 1)
		;

	return TRUE;
}

/**
 * @brief Performs an immediate EXI transfer on channel 2.
 */
static BOOL DBGEXIImm(void* buffer, s32 byteCount, u32 isWrite)
{
	u8* ioPtr;
	u32 transferWord;
	int byteIndex;

	if (isWrite) {
		ioPtr        = buffer;
		transferWord = 0;
		// Pack up to 4 bytes into the EXI immediate register word.
		for (byteIndex = 0; byteIndex < byteCount; byteIndex++) {
			u8* bytePtr = ((u8*)buffer) + byteIndex;
			transferWord |= *bytePtr << ((3 - byteIndex) << 3);
		}
		__EXIRegs[EXI_CHAN_2_IMM] = transferWord;
	}

	__EXIRegs[EXI_CHAN_2_CONTROL] = 1 | isWrite << 2 | (byteCount - 1) << 4;
	DBGEXISync();

	if (!isWrite) {
		transferWord = __EXIRegs[EXI_CHAN_2_IMM];
		ioPtr        = buffer;
		for (byteIndex = 0; byteIndex < byteCount; byteIndex++) {
			*ioPtr++ = transferWord >> ((3 - byteIndex) << 3);
		}
	}

	return TRUE;
}

/**
 * @brief Clears debugger EXI interrupt state.
 * @note UNUSED Size: 000018
 */
void DBGEXIClearInterrupts(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @brief Validates debugger device identity.
 * @note UNUSED Size: 0000AC
 */
void DBGCheckID(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @brief Sends a mailbox word to the debugger device.
 * @note UNUSED Size: 00008C
 */
static BOOL DBGWriteMailbox(u32 mailboxValue)
{
	BOOL hasError = FALSE;
	u32 commandWord;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	commandWord = (mailboxValue & 0x1fffffff) | (0xC0000000);
	hasError |= IS_FALSE(DBGEXIImm(&commandWord, sizeof(commandWord), 1));
	hasError |= IS_FALSE(DBGEXISync());
	hasError |= IS_FALSE(DBGEXIDeselect());

	return IS_FALSE(hasError);
}

/**
 * @brief Reads one mailbox word from the debugger device.
 */
static BOOL DBGReadMailbox(u32* mailboxValue)
{
	BOOL hasError = FALSE;
	u32 commandWord;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	commandWord = 0x60000000;
	hasError |= IS_FALSE(DBGEXIImm(&commandWord, 2, 1));
	hasError |= IS_FALSE(DBGEXISync());

	hasError |= IS_FALSE(DBGEXIImm(mailboxValue, 4, 0));
	hasError |= IS_FALSE(DBGEXISync());

	hasError |= IS_FALSE(DBGEXIDeselect());

	return IS_FALSE(hasError);
}

/**
 * @brief Reads a word stream from debugger EXI memory space.
 */
static BOOL DBGRead(u32 exiOffset, void* buffer, s32 remainingBytes)
{
	BOOL hasError = FALSE;
	u32* dstWord = (u32*)buffer;
	u32 commandWord;
	u32 dataWord;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	commandWord = (exiOffset & 0x1fffc) << 8 | 0x20000000;
	hasError |= IS_FALSE(DBGEXIImm(&commandWord, sizeof(commandWord), 1));
	hasError |= IS_FALSE(DBGEXISync());

	while (remainingBytes) {
		hasError |= IS_FALSE(DBGEXIImm(&dataWord, sizeof(dataWord), 0));
		hasError |= IS_FALSE(DBGEXISync());

		*dstWord++ = dataWord;

		remainingBytes -= 4;
		if (remainingBytes < 0) {
			remainingBytes = 0;
		}
	}

	hasError |= IS_FALSE(DBGEXIDeselect());
	return IS_FALSE(hasError);
}

/**
 * @brief Writes a word stream into debugger EXI memory space.
 */
static BOOL DBGWrite(u32 exiOffset, void* buffer, s32 remainingBytes)
{
	BOOL hasError = FALSE;
	u32* srcWord = (u32*)buffer;
	u32 commandWord;
	u32 dataWord;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	commandWord = (exiOffset & 0x1fffc) << 8 | 0xa0000000;
	hasError |= IS_FALSE(DBGEXIImm(&commandWord, sizeof(commandWord), 1));
	hasError |= IS_FALSE(DBGEXISync());

	while (remainingBytes != 0) {
		dataWord = *srcWord++;

		hasError |= IS_FALSE(DBGEXIImm(&dataWord, sizeof(dataWord), 1));
		hasError |= IS_FALSE(DBGEXISync());

		remainingBytes -= 4;
		if (remainingBytes < 0) {
			remainingBytes = 0;
		}
	}

	hasError |= IS_FALSE(DBGEXIDeselect());
	return IS_FALSE(hasError);
}

/**
 * @brief Reads debugger EXI status bits.
 */
static BOOL DBGReadStatus(u32* statusValue)
{
	BOOL hasError = FALSE;
	u32 commandWord;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	commandWord = 1 << 30;
	hasError |= IS_FALSE(DBGEXIImm((u8*)&commandWord, 2, 1));
	hasError |= IS_FALSE(DBGEXISync());

	hasError |= IS_FALSE(DBGEXIImm(statusValue, 4, 0));
	hasError |= IS_FALSE(DBGEXISync());

	hasError |= IS_FALSE(DBGEXIDeselect());

	return IS_FALSE(hasError);
}

/**
 * @brief Handles mailbox-ready interrupt notification.
 */
static void MWCallback(u32, OSContext*)
{
	EXIInputFlag = TRUE;
	if (MTRCallback) {
		MTRCallback(0);
	}
}

/**
 * @brief Dispatches PI debug interrupts to the active debugger callback.
 */
static void DBGHandler(s16 interruptType, OSContext* context)
{
	*__PIRegs = 0x1000;
	if (DBGCallback) {
		DBGCallback(interruptType, context);
	}
}

/**
 * @brief Initializes debugger communication state and callback wiring.
 */
void DBInitComm(vu8** inputFlagOut, MTRCallbackType callback)
{
	BOOL interrupts = OSDisableInterrupts();
	{
		pEXIInputFlag = (u8*)EXIInputFlag;
		pEXIInputFlag = &EXIInputFlag;

		*inputFlagOut = pEXIInputFlag;

		MTRCallback = callback;

		DBGEXIInit();
	}
	OSRestoreInterrupts(interrupts);
}

/**
 * @brief Installs debugger interrupt handlers and unmasks PI debug interrupts.
 */
void DBInitInterrupts(void)
{
	__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_2);
	__OSMaskInterrupts(OS_INTERRUPTMASK_PI_DEBUG);
	DBGCallback = &MWCallback;
	__OSSetInterruptHandler(__OS_INTERRUPT_PI_DEBUG, DBGHandler);
	__OSUnmaskInterrupts(OS_INTERRUPTMASK_PI_DEBUG);
}

/**
 * @brief Polls mailbox and latches incoming message metadata.
 * @note UNUSED Size: 000150
 */
static void CheckMailBox(void)
{
	u32 mailboxWord;
	DBGReadStatus(&mailboxWord);
	if (mailboxWord & 1) {
		DBGReadMailbox(&mailboxWord);
		mailboxWord &= 0x1fffffff;

		// Accept only mailbox payload words in the expected command range.
		if ((mailboxWord & 0x1f000000) == 0x1f000000) {
			SendMailData = mailboxWord;
			RecvDataLeng = mailboxWord & 0x7fff;
			EXIInputFlag = 1;
		}
	}
}

/**
 * @brief Returns pending debugger payload size, polling mailbox when needed.
 */
int DBQueryData(void)
{
	BOOL interrupts;

	EXIInputFlag = 0;
	if (RecvDataLeng == 0) {
		interrupts = OSDisableInterrupts();
		CheckMailBox();
	}
	// This is surely a bug...
	OSRestoreInterrupts(interrupts);
	return RecvDataLeng;
}

/**
 * @brief Reads pending debugger payload into the provided buffer.
 */
BOOL DBRead(void* buffer, int count)
{
	u32 interrupts = OSDisableInterrupts();
	u32 readOffset = SendMailData & 0x10000 ? 0x1000 : 0;

	DBGRead(readOffset + 0x1e000, buffer, ROUND_UP(count, 4));

	RecvDataLeng = 0;
	EXIInputFlag = 0;

	OSRestoreInterrupts(interrupts);

	return 0;
}

/**
 * @brief Writes a debugger payload and posts mailbox notification.
 */
BOOL DBWrite(const void* src, int size)
{
	u32 messageWord;
	u32 statusValue;
	BOOL interrupts;

	interrupts = OSDisableInterrupts();

	do {
		DBGReadStatus(&statusValue);
	} while (statusValue & 2);

	SendCount++;
	messageWord = ((SendCount & 1) ? 0x1000 : 0);

	while (!DBGWrite(messageWord | 0x1c000, (u32*)src, ROUND_UP(size, 4)))
		;

	do {
		DBGReadStatus(&statusValue);
	} while (statusValue & 2);

	messageWord = (SendCount << 0x10) | 0x1F000000 | size;
	while (!DBGWriteMailbox(messageWord))
		;

	do {
		while (!DBGReadStatus(&statusValue))
			;
	} while (statusValue & 2);

	OSRestoreInterrupts(interrupts);

	return 0;
}

/**
 * @brief Opens debugger communication endpoint (stubbed).
 */
void DBOpen(void)
{
	return;
}

/**
 * @brief Closes debugger communication endpoint (stubbed).
 */
void DBClose(void)
{
	return;
}
