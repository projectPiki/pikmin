#include "Dolphin/dvd.h"
#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"
#include <stddef.h>

static BOOL FirstRead                    = TRUE;
static volatile BOOL StopAtNextInt       = FALSE;
static u32 LastLength                    = 0;
static DVDLowCallback Callback           = NULL;
static DVDLowCallback ResetCoverCallback = NULL;
static volatile OSTime LastResetEnd      = 0;
static vu32 ResetOccurred                = FALSE;
static volatile BOOL WaitingCoverClose   = FALSE;
static BOOL Breaking                     = FALSE;
static vu32 WorkAroundType               = 0;
static u32 WorkAroundSeekLocation        = 0;
static volatile OSTime LastReadFinished  = 0;
static OSTime LastReadIssued             = 0;
static volatile BOOL LastCommandWasRead  = FALSE;
static vu32 NextCommandNumber            = 0;

typedef struct DVDBuffer {
	void* addr;
	u32 length;
	u32 offset;
} DVDBuffer;

typedef struct DVDCommand {
	s32 cmd;
	void* addr;
	u32 length;
	u32 offset;
	DVDLowCallback callback;
} DVDCommand;

static DVDCommand CommandList[3];
static OSAlarm AlarmForWA;
static OSAlarm AlarmForTimeout;
static OSAlarm AlarmForBreak;
static DVDBuffer Prev;
static DVDBuffer Curr;

// forward declare some statics:
static void Read(void* addr, u32 length, u32 offset, DVDLowCallback callback);

/**
 * @brief Initializes read workaround state and alarm subsystem for low-level DVD commands.
 */
void __DVDInitWA(void)
{
	NextCommandNumber  = 0;
	CommandList[0].cmd = -1;
	__DVDLowSetWAType(0, 0);
	OSInitAlarm();
}

/**
 * @brief Dispatches next queued workaround command when a read sequence needs extra seek/read steps.
 * @note UNUSED Size: 000094 (Matching by size)
 */
static BOOL ProcessNextCommand(void)
{
	s32 commandIndex = NextCommandNumber;

	// Continue pending read/seek sequence queued by workaround path.
	if (CommandList[commandIndex].cmd == 1) {
		++NextCommandNumber;
		Read(CommandList[commandIndex].addr, CommandList[commandIndex].length, CommandList[commandIndex].offset, CommandList[commandIndex].callback);
		return TRUE;
	} else if (CommandList[commandIndex].cmd == 2) {
		++NextCommandNumber;
		DVDLowSeek(CommandList[commandIndex].offset, CommandList[commandIndex].callback);
		return TRUE;
	}

	return FALSE;
}

/**
 * @brief Handles DI interrupt causes, cover events, command chaining, and callback completion.
 */
void __DVDInterruptHandler(__OSInterrupt interrupt, OSContext* context)
{
	DVDLowCallback callback;
	OSContext exceptionContext;
	u32 cause = 0;
	u32 regValue;
	u32 interruptBits;
	u32 enabledMask;

	OSCancelAlarm(&AlarmForTimeout);

	if (LastCommandWasRead) {
		LastReadFinished = __OSGetSystemTime();
		FirstRead        = FALSE;
		Prev.addr        = Curr.addr;
		Prev.length      = Curr.length;
		Prev.offset      = Curr.offset;
		if (StopAtNextInt == TRUE) {
			cause |= 8;
		}
	}

	LastCommandWasRead = FALSE;
	StopAtNextInt      = FALSE;
	regValue           = __DIRegs[DI_STATUS];
	enabledMask        = regValue & 0x2a;
	interruptBits      = (regValue & 0x54) & (enabledMask << 1);

	// Map drive-interface interrupt bits to callback cause bits.
	if (interruptBits & 0x40) {
		cause |= 8;
	}

	if (interruptBits & 0x10) {
		cause |= 1;
	}

	if (interruptBits & 4) {
		cause |= 2;
	}

	if (cause) {
		ResetOccurred = FALSE;
	}

	__DIRegs[DI_STATUS] = interruptBits | enabledMask;

	if (ResetOccurred && (__OSGetSystemTime() - LastResetEnd) < OSMillisecondsToTicks(200)) {
		regValue      = __DIRegs[DI_COVER_STATUS];
		enabledMask   = regValue & 0x2;
		interruptBits = (regValue & 4) & (enabledMask << 1);
		if (interruptBits & 4) {
			if (ResetCoverCallback) {
				ResetCoverCallback(4);
			}
			ResetCoverCallback = NULL;
		}

		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
	} else if (WaitingCoverClose) {
		regValue      = __DIRegs[DI_COVER_STATUS];
		enabledMask   = regValue & 2;
		interruptBits = (regValue & 4) & (enabledMask << 1);

		if (interruptBits & 4) {
			cause |= 4;
		}

		__DIRegs[DI_COVER_STATUS] = interruptBits | enabledMask;
		WaitingCoverClose         = FALSE;
	} else {
		__DIRegs[DI_COVER_STATUS] = 0;
	}

	if ((cause & 8) && !Breaking) {
		cause &= ~8;
	}

	if ((cause & 1)) {
		if (ProcessNextCommand()) {
			return;
		}
	} else {
		CommandList[0].cmd = -1;
		NextCommandNumber  = 0;
	}

	OSClearContext(&exceptionContext);
	OSSetCurrentContext(&exceptionContext);

	if (cause) {
		callback = Callback;
		Callback = NULL;
		if (callback) {
			callback(cause);
		}

		Breaking = FALSE;
	}

	OSClearContext(&exceptionContext);
	OSSetCurrentContext(context);
}

/**
 * @brief Alarm callback that resumes deferred read command sequencing.
 */
static void AlarmHandler(OSAlarm* alarm, OSContext* context)
{
	ProcessNextCommand();
}

/**
 * @brief Timeout handler that masks DI interrupts and reports timeout cause to pending callback.
 */
static void AlarmHandlerForTimeout(OSAlarm* alarm, OSContext* context)
{
	OSContext tmpContext;
	DVDLowCallback callback;
	__OSMaskInterrupts(OS_INTERRUPTMASK_PI_DI);
	OSClearContext(&tmpContext);
	OSSetCurrentContext(&tmpContext);
	callback = Callback;
	Callback = NULL;
	if (callback != NULL) {
		callback(0x10);
	}
	OSClearContext(&tmpContext);
	OSSetCurrentContext(context);
}

/**
 * @brief Arms timeout alarm used by low-level drive commands.
 * @note UNUSED Size: 000064 (Matching by size)
 */
static void SetTimeoutAlarm(OSTime timeout)
{
	OSCreateAlarm(&AlarmForTimeout);
	OSSetAlarm(&AlarmForTimeout, timeout, AlarmHandlerForTimeout);
}

/**
 * @brief Issues raw DVD read command through DI registers and starts command timeout tracking.
 */
static void Read(void* addr, u32 length, u32 offset, DVDLowCallback callback)
{
	StopAtNextInt      = FALSE;
	LastCommandWasRead = TRUE;
	Callback           = callback;
	LastReadIssued     = __OSGetSystemTime();

	__DIRegs[DI_CMD_BUF_0]    = 0xa8000000;
	__DIRegs[DI_CMD_BUF_1]    = offset / 4;
	__DIRegs[DI_CMD_BUF_2]    = length;
	__DIRegs[DI_DMA_MEM_ADDR] = (u32)addr;
	__DIRegs[DI_DMA_LENGTH]   = length;
	LastLength                = length;
	__DIRegs[DI_CONTROL]      = 3;

	if (length > 0xa00000) {
		SetTimeoutAlarm(OSSecondsToTicks(20));
	} else {
		SetTimeoutAlarm(OSSecondsToTicks(10));
	}
}

/**
 * @brief Unimplemented audio buffer enable helper.
 * @note UNUSED Size: 000038
 */
void AudioBufferOn(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @brief Checks whether current read falls within block range considered contiguous with previous read.
 * @note UNUSED Size: 0000A0 (Matching by size)
 */
BOOL HitCache(DVDBuffer* cur, DVDBuffer* prev)
{
	u32 prevEndBlock      = (prev->offset + prev->length - 1) >> 15;
	u32 curStartBlock     = (cur->offset >> 15);
	u32 streamWindowLimit = (DVDGetCurrentDiskID()->streaming ? TRUE : FALSE) ? 5 : 15;

	// Treat nearby block requests as cache-friendly, with wider window for non-streaming discs.
	if ((curStartBlock > prevEndBlock - 2) || (curStartBlock < prevEndBlock + streamWindowLimit + 3)) {
		return TRUE;
	}
	return FALSE;
}

/**
 * @brief Clears queued workaround commands and performs immediate read.
 * @note UNUSED Size: 000034 (Matching by size)
 */
static void DoJustRead(void* addr, u32 length, u32 offset, DVDLowCallback callback)
{
	CommandList[0].cmd = -1;
	NextCommandNumber  = 0;
	Read(addr, length, offset, callback);
}

/**
 * @brief Queues seek then read sequence and starts first seek for workaround type requiring extra seek.
 */
static void SeekTwiceBeforeRead(void* addr, u32 length, u32 offset, DVDLowCallback callback)
{
	u32 newOffset = offset & ~0x7FFF;
	if (!newOffset) {
		newOffset = 0;
	} else {
		newOffset += WorkAroundSeekLocation;
	}
	CommandList[0].cmd      = 2;
	CommandList[0].offset   = newOffset;
	CommandList[0].callback = callback;
	CommandList[1].cmd      = 1;
	CommandList[1].addr     = addr;
	CommandList[1].length   = length;
	CommandList[1].offset   = offset;
	CommandList[1].callback = callback;
	CommandList[2].cmd      = -1;
	NextCommandNumber       = 0;
	DVDLowSeek(newOffset, callback);
}

/**
 * @brief Queues read command and delays it by alarm to enforce minimum gap between nearby reads.
 * @note UNUSED Size: 00008C (Matching by size)
 */
static void WaitBeforeRead(void* addr, u32 length, u32 offset, DVDLowCallback callback, OSTime timeout)
{
	CommandList[0].cmd      = 1;
	CommandList[0].addr     = addr;
	CommandList[0].length   = length;
	CommandList[0].offset   = offset;
	CommandList[0].callback = callback;
	CommandList[1].cmd      = -1;
	NextCommandNumber       = 0;
	OSCreateAlarm(&AlarmForWA);
	OSSetAlarm(&AlarmForWA, timeout, AlarmHandler);
}

/**
 * @brief Entry point for low-level reads, selecting direct path or timing/seek workaround sequence.
 */
BOOL DVDLowRead(void* addr, u32 length, u32 offset, DVDLowCallback callback)
{
	OSTime elapsedSinceRead;
	u32 prevEndBlock;

	__DIRegs[DI_DMA_LENGTH] = length;
	Curr.addr               = addr;
	Curr.length             = length;
	Curr.offset             = offset;

	if (WorkAroundType == 0) {
		DoJustRead(addr, length, offset, callback);
	} else if (WorkAroundType == 1) {
		// Workaround type 1 spaces nearby reads to avoid problematic immediate follow-ups.
		if (FirstRead) {
			SeekTwiceBeforeRead(addr, length, offset, callback);
		} else {
			if (!HitCache(&Curr, &Prev)) {
				DoJustRead(addr, length, offset, callback);
			} else {
				prevEndBlock = (Prev.offset + Prev.length - 1) >> 15;
				if (prevEndBlock == Curr.offset >> 15 || prevEndBlock + 1 == Curr.offset >> 15) {
					elapsedSinceRead = __OSGetSystemTime() - LastReadFinished;
					if (OSMillisecondsToTicks(5) < elapsedSinceRead) {
						DoJustRead(addr, length, offset, callback);
					} else {
						WaitBeforeRead(addr, length, offset, callback, OSMillisecondsToTicks(5) - elapsedSinceRead + OSMicrosecondsToTicks(500));
					}
				} else {
					SeekTwiceBeforeRead(addr, length, offset, callback);
				}
			}
		}
	}
	return TRUE;
}

/**
 * @brief Issues low-level seek command and sets timeout watchdog.
 */
BOOL DVDLowSeek(u32 offset, DVDLowCallback callback)
{
	StopAtNextInt          = FALSE;
	Callback               = callback;
	__DIRegs[DI_CMD_BUF_0] = 0xab000000;
	__DIRegs[DI_CMD_BUF_1] = offset / 4;
	__DIRegs[DI_CONTROL]   = 1;
	SetTimeoutAlarm(OSSecondsToTicks(10));
	return TRUE;
}

/**
 * @brief Enables waiting for cover-close interrupt and stores callback for completion signal.
 */
BOOL DVDLowWaitCoverClose(DVDLowCallback callback)
{
	Callback                  = callback;
	WaitingCoverClose         = TRUE;
	StopAtNextInt             = FALSE;
	__DIRegs[DI_COVER_STATUS] = 2;
	return TRUE;
}

/**
 * @brief Reads disc ID structure using DMA transfer and timeout protection.
 */
BOOL DVDLowReadDiskID(DVDDiskID* diskID, DVDLowCallback callback)
{
	StopAtNextInt             = FALSE;
	Callback                  = callback;
	__DIRegs[DI_CMD_BUF_0]    = 0xa8000040;
	__DIRegs[DI_CMD_BUF_1]    = 0;
	__DIRegs[DI_CMD_BUF_2]    = sizeof(DVDDiskID);
	__DIRegs[DI_DMA_MEM_ADDR] = (u32)diskID;
	__DIRegs[DI_DMA_LENGTH]   = sizeof(DVDDiskID);
	__DIRegs[DI_CONTROL]      = 3;
	SetTimeoutAlarm(OSSecondsToTicks(10));
	return TRUE;
}

/**
 * @brief Sends command to stop drive motor and waits for interrupt completion.
 */
BOOL DVDLowStopMotor(DVDLowCallback callback)
{
	StopAtNextInt          = FALSE;
	Callback               = callback;
	__DIRegs[DI_CMD_BUF_0] = 0xe3000000;
	__DIRegs[DI_CONTROL]   = 1;
	SetTimeoutAlarm(OSSecondsToTicks(10));
	return TRUE;
}

/**
 * @brief Requests drive error status via low-level command path.
 */
BOOL DVDLowRequestError(DVDLowCallback callback)
{
	StopAtNextInt          = FALSE;
	Callback               = callback;
	__DIRegs[DI_CMD_BUF_0] = 0xe0000000;
	__DIRegs[DI_CONTROL]   = 1;
	SetTimeoutAlarm(OSSecondsToTicks(10));
	return TRUE;
}

/**
 * @brief Requests drive inquiry data through DMA and timeout guard.
 */
BOOL DVDLowInquiry(DVDDriveInfo* info, DVDLowCallback callback)
{
	StopAtNextInt             = FALSE;
	Callback                  = callback;
	__DIRegs[DI_CMD_BUF_0]    = 0x12000000;
	__DIRegs[DI_CMD_BUF_2]    = sizeof(DVDDriveInfo);
	__DIRegs[DI_DMA_MEM_ADDR] = (u32)info;
	__DIRegs[DI_DMA_LENGTH]   = sizeof(DVDDriveInfo);
	__DIRegs[DI_CONTROL]      = 3;
	SetTimeoutAlarm(OSSecondsToTicks(10));
	return TRUE;
}

/**
 * @brief Issues audio stream control command with subcommand, length, and offset parameters.
 */
BOOL DVDLowAudioStream(u32 subcmd, u32 length, u32 offset, DVDLowCallback callback)
{
	StopAtNextInt          = FALSE;
	Callback               = callback;
	__DIRegs[DI_CMD_BUF_0] = subcmd | 0xe1000000;
	__DIRegs[DI_CMD_BUF_1] = offset >> 2;
	__DIRegs[DI_CMD_BUF_2] = length;
	__DIRegs[DI_CONTROL]   = 1;
	SetTimeoutAlarm(OSSecondsToTicks(10));
	return TRUE;
}

/**
 * @brief Requests current audio status from drive with given subcommand.
 */
BOOL DVDLowRequestAudioStatus(u32 subcmd, DVDLowCallback callback)
{
	StopAtNextInt          = FALSE;
	Callback               = callback;
	__DIRegs[DI_CMD_BUF_0] = subcmd | 0xe2000000;
	__DIRegs[DI_CONTROL]   = 1;
	SetTimeoutAlarm(OSSecondsToTicks(10));
	return TRUE;
}

/**
 * @brief Configures drive audio buffer mode and size, then waits for command completion.
 */
BOOL DVDLowAudioBufferConfig(BOOL enable, u32 size, DVDLowCallback callback)
{
	StopAtNextInt          = FALSE;
	Callback               = callback;
	__DIRegs[DI_CMD_BUF_0] = 0xe4000000 | (enable != 0 ? 0x10000 : 0) | size;
	__DIRegs[DI_CONTROL]   = 1;
	SetTimeoutAlarm(OSSecondsToTicks(10));
	return TRUE;
}

/**
 * @brief Pulses PI reset bits to reset DVD interface and records reset timing window.
 */
void DVDLowReset()
{
	u32 resetCode;
	OSTime resetStart;

	__DIRegs[DI_COVER_STATUS] = 2;
	resetCode                 = __PIRegs[PI_RESETCODE];
	__PIRegs[PI_RESETCODE]    = (resetCode & ~4) | 1;

	resetStart = __OSGetSystemTime();
	while ((__OSGetSystemTime() - resetStart) < OSMicrosecondsToTicks(12))
		;

	// Restore reset code bits and mark software reset window for cover interrupt handling.
	__PIRegs[PI_RESETCODE] = resetCode | 5;
	ResetOccurred          = TRUE;
	LastResetEnd           = __OSGetSystemTime();
}

/**
 * @brief Unimplemented reset-cover callback registration.
 * @note UNUSED Size: 000044
 */
void DVDLowSetResetCoverCallback(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @brief Unimplemented break command helper.
 * @note UNUSED Size: 00001C
 */
void DoBreak(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @brief Unimplemented break alarm callback.
 * @note UNUSED Size: 000074
 */
void AlarmHandlerForBreak(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @brief Unimplemented break alarm setup helper.
 * @note UNUSED Size: 000064
 */
void SetBreakAlarm(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @brief Marks next interrupt as break condition without issuing immediate hardware command.
 */
BOOL DVDLowBreak()
{
	StopAtNextInt = TRUE;
	Breaking      = TRUE;
	return TRUE;
}

/**
 * @brief Clears pending callback and returns previous callback pointer.
 */
DVDLowCallback DVDLowClearCallback()
{
	DVDLowCallback oldCallback;
	__DIRegs[DI_COVER_STATUS] = 0;
	oldCallback               = Callback;
	Callback                  = NULL;
	return oldCallback;
}

/**
 * @brief Unimplemented cover status query helper.
 * @note UNUSED Size: 000094
 */
void DVDLowGetCoverStatus(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @brief Updates workaround mode and seek offset atomically under interrupt disable.
 */
void __DVDLowSetWAType(u32 type, u32 location)
{
	BOOL interruptsEnabled;
	interruptsEnabled      = OSDisableInterrupts();
	WorkAroundType         = type;
	WorkAroundSeekLocation = location;
	OSRestoreInterrupts(interruptsEnabled);
}
