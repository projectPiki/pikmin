#include "Dolphin/os.h"
#include "Dolphin/hw_regs.h"
#include "types.h"
#include "Dolphin/dvd.h"
#include "mem.h"

// forward declarations for local functions, as needed:
static void AlarmHandler(OSAlarm* alarm, OSContext* context);
static void cbForCancelSync(s32 result, DVDCommandBlock* block);
static void cbForStateBusy(u32 p1);
static void cbForStateCheckID1(u32 p1);
static void cbForStateCheckID2(u32 p1);
static void cbForStateCheckID2a(u32 p1);
static void cbForStateCheckID3(u32 p1);
static void cbForStateCoverClosed(u32 p1);
static void cbForStateMotorStopped(u32 p1);
static void cbForStateReadingFST(u32 p1);
static void cbForStateGettingError(u32 p1);
static void cbForStateGoToRetry(u32 p1);
static void cbForUnrecoveredError(u32 p1);
static void cbForUnrecoveredErrorRetry(u32 p1);
static void cbForCancelStreamSync(s32 result, DVDCommandBlock* block);
static void defaultOptionalCommandChecker(DVDCommandBlock* block, DVDLowCallback cb);
static void stateBusy(DVDCommandBlock*);
static void stateCheckID2(DVDCommandBlock*);
static void stateCheckID2a(DVDCommandBlock*);
static void stateCheckID3(DVDCommandBlock*);
static void stateCoverClosed();
static void stateCoverClosed_CMD(DVDCommandBlock*);
static void stateGettingError();
static void stateGoToRetry();
static void stateMotorStopped();
static void stateReady();
static void stateTimeout();

// Functions from other files.
void __DVDInterruptHandler(__OSInterrupt interrupt, OSContext* context);
DVDCommandBlock* __DVDPopWaitingQueue();

typedef void (*stateFunc)(DVDCommandBlock* block);
stateFunc LastState;

static u8 tmpBuffer[0x80] ATTRIBUTE_ALIGN(32);
static DVDCommandBlock* executing;
static DVDDiskID* currID;
static OSBootInfo* bootInfo;
static BOOL autoInvalidation        = TRUE;
static volatile BOOL PauseFlag      = FALSE;
static volatile BOOL PausingFlag    = FALSE;
static volatile BOOL AutoFinishing  = FALSE;
static volatile BOOL FatalErrorFlag = FALSE;
static vu32 CurrCommand;
static vu32 Canceling = FALSE;
static DVDCBCallback CancelCallback;
static vu32 ResumeFromHere = 0;
static vu32 CancelLastError;
static vu32 LastError;
static vs32 NumInternalRetry = 0;
static volatile BOOL ResetRequired;
static volatile BOOL FirstTimeInBootrom = FALSE;

static DVDCommandBlock DummyCommandBlock;
static OSAlarm ResetAlarm;

static BOOL DVDInitialized = FALSE;

/*
 * --INFO--
 * Address:	801FF964
 * Size:	0000FC
 */
void DVDInit()
{
	if (DVDInitialized) {
		return;
	}

	OSInitAlarm();
	DVDInitialized = TRUE;
	__DVDFSInit();
	__DVDClearWaitingQueue();
	__DVDInitWA();
	bootInfo = (OSBootInfo*)OSPhysicalToCached(0x0000);
	currID   = &(bootInfo->DVDDiskID);
	__OSSetInterruptHandler(21, __DVDInterruptHandler);
	__OSUnmaskInterrupts(0x400);
	OSInitThreadQueue(&__DVDThreadQueue);
	__DIRegs[DI_STATUS]       = 42;
	__DIRegs[DI_COVER_STATUS] = 0;
	if (bootInfo->magic == OS_BOOTINFO_MAGIC_JTAG) {
		OSReport("app booted via JTAG\n");
		OSReport("load fst\n");
		__fstLoad();
	} else if (bootInfo->magic == 0xD15EA5E) {
		OSReport("app booted from bootrom\n");
	} else {
		FirstTimeInBootrom = TRUE;
		OSReport("bootrom\n");
	}
}

/*
 * --INFO--
 * Address:	801FFA60
 * Size:	000054
 */
static void stateReadingFST()
{
	LastState = (stateFunc)stateReadingFST;

	DVDLowRead(bootInfo->FSTLocation, OSRoundUp32B(((u32*)tmpBuffer)[2]), ((u32*)tmpBuffer)[1], cbForStateReadingFST);
}

/*
 * --INFO--
 * Address:	801FFAB4
 * Size:	000080
 */
static void cbForStateReadingFST(u32 p1)
{
	DVDCommandBlock* cmdBlock;
	if (p1 == 0x10) {
		executing->state = -1;
		stateTimeout();
	} else if ((p1 & 1) != 0) {
		NumInternalRetry = 0;
		cmdBlock         = executing;
		executing        = &DummyCommandBlock;
		cmdBlock->state  = 0;
		if (cmdBlock->callback) {
			(cmdBlock->callback)(0, cmdBlock);
		}
		stateReady();
	} else {
		stateGettingError();
	}
}

/*
 * --INFO--
 * Address:	801FFB34
 * Size:	0000A8
 */
static void cbForStateError(u32 intType)
{
	DVDCommandBlock* finished;

	if (intType == 16) {
		executing->state = -1;
		stateTimeout();
		return;
	}

	FatalErrorFlag = TRUE;
	finished       = executing;
	executing      = &DummyCommandBlock;
	if (finished->callback) {
		(finished->callback)(-1, finished);
	}

	if (Canceling) {
		Canceling = FALSE;
		if (CancelCallback)
			(CancelCallback)(0, finished);
	}

	stateReady();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
static void stateError(u32 error)
{
	__DVDStoreErrorCode(error);
	DVDLowStopMotor(cbForStateError);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FFBDC
 * Size:	00009C
 */
static void stateTimeout()
{
	__DVDStoreErrorCode(0x1234568);
	DVDReset();
	cbForStateError(0);
}

/*
 * --INFO--
 * Address:	801FFC78
 * Size:	000028
 */
static void stateGettingError() { DVDLowRequestError(cbForStateGettingError); }

/*
 * --INFO--
 * Address:	801FFCA0
 * Size:	0000B4
 */
static u32 CategorizeError(u32 error)
{
	if (error == 0x20400) {
		LastError = error;
		return 1;
	}

	error &= 0xffffff;

	if ((error == 0x62800) || (error == 0x23a00) || (error == 0xb5a01)) {
		return 0;
	}

	++NumInternalRetry;
	if (NumInternalRetry == 2) {
		if (error == LastError) {
			LastError = error;
			return 1;
		} else {
			LastError = error;
			return 2;
		}
	} else {
		LastError = error;

		if ((error == 0x31100) || (executing->command == 5)) {
			return 2;
		} else {
			return 3;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static BOOL CheckCancel(u32 resume)
{
	DVDCommandBlock* finished;

	if (Canceling) {
		ResumeFromHere = resume;
		Canceling      = FALSE;

		finished  = executing;
		executing = &DummyCommandBlock;

		finished->state = 10;
		if (finished->callback)
			(*finished->callback)(-3, finished);
		if (CancelCallback)
			(CancelCallback)(0, finished);
		stateReady();
		return TRUE;
	}
	return FALSE;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FFD54
 * Size:	000294
 */
static void cbForStateGettingError(u32 intType)
{
	u32 error;
	u32 status;
	u32 errorCategory;
	u32 resume;

	if (intType == 16) {
		executing->state = -1;
		stateTimeout();
		return;
	}

	if (intType & 2) {
		executing->state = -1;
		stateError(0x1234567);
		return;
	}

	error  = __DIRegs[DI_MM_BUF];
	status = error & 0xff000000;

	errorCategory = CategorizeError(error);

	if (errorCategory == 1) {
		executing->state = -1;
		stateError(error);
		return;
	}

	if ((errorCategory == 2) || (errorCategory == 3)) {
		resume = 0;
	} else {
		if (status == 0x01000000)
			resume = 4;
		else if (status == 0x02000000)
			resume = 6;
		else if (status == 0x03000000)
			resume = 3;
		else
			resume = 5;
	}

	if (CheckCancel(resume))
		return;

	if (errorCategory == 2) {
		__DVDStoreErrorCode(error);
		stateGoToRetry();
		return;
	}

	if (errorCategory == 3) {
		if ((error & 0x00ffffff) == 0x00031100) {
			DVDLowSeek(executing->offset, cbForUnrecoveredError);
		} else {
			LastState(executing);
		}
		return;
	}

	if (status == 0x01000000) {
		executing->state = 5;
		stateMotorStopped();
		return;
	} else if (status == 0x02000000) {
		executing->state = 3;
		stateCoverClosed();
		return;
	} else if (status == 0x03000000) {
		executing->state = 4;
		stateMotorStopped();
		return;
	} else {
		executing->state = -1;
		stateError(0x1234567);
		return;
	}
}

/*
 * --INFO--
 * Address:	801FFFE8
 * Size:	000068
 */
static void cbForUnrecoveredError(u32 p1)
{
	if (p1 == 16) {
		executing->state = -1;
		stateTimeout();
		return;
	}

	if (p1 & 1) {
		stateGoToRetry();
		return;
	}

	DVDLowRequestError(cbForUnrecoveredErrorRetry);
}

#pragma dont_inline on
/*
 * --INFO--
 * Address:	80200050
 * Size:	000098
 */
void cbForUnrecoveredErrorRetry(u32 p1)
{
	if (p1 == 0x10) {
		executing->state = -1;
		__DVDStoreErrorCode(0x1234568);
		DVDReset();
		cbForStateError(0);
		return;
	}

	executing->state = -1;

	if ((p1 & 2) != 0) {
		__DVDStoreErrorCode(0x1234567);
		DVDLowStopMotor(cbForStateError);
		return;
	}

	__DVDStoreErrorCode(__DIRegs[DI_MM_BUF]);
	DVDLowStopMotor(cbForStateError);
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bne-      .loc_0x3C
	  lwz       r4, 0x32B8(r13)
	  li        r0, -0x1
	  lis       r3, 0x123
	  stw       r0, 0xC(r4)
	  addi      r3, r3, 0x4568
	  bl        0x2084
	  bl        0x1850
	  li        r3, 0
	  bl        -0x550
	  b         .loc_0x88

	.loc_0x3C:
	  rlwinm.   r0,r3,0,30,30
	  lwz       r3, 0x32B8(r13)
	  li        r4, -0x1
	  stw       r4, 0xC(r3)
	  beq-      .loc_0x6C
	  lis       r3, 0x123
	  addi      r3, r3, 0x4567
	  bl        0x2054
	  lis       r3, 0x8020
	  subi      r3, r3, 0x4CC
	  bl        -0x15D4
	  b         .loc_0x88

	.loc_0x6C:
	  lis       r3, 0xCC00
	  addi      r3, r3, 0x6000
	  lwz       r3, 0x20(r3)
	  bl        0x2034
	  lis       r3, 0x8020
	  subi      r3, r3, 0x4CC
	  bl        -0x15F4

	.loc_0x88:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
#pragma dont_inline reset

/*
 * --INFO--
 * Address:	802000E8
 * Size:	000028
 */
void stateGoToRetry() { DVDLowStopMotor(cbForStateGoToRetry); }

/*
 * --INFO--
 * Address:	80200110
 * Size:	000158
 */
void cbForStateGoToRetry(u32 p1)
{
	if (p1 == 16) {
		executing->state = -1;
		stateTimeout();
		return;
	}

	if (p1 & 2) {
		executing->state = -1;
		stateError(0x1234567);
		return;
	}

	NumInternalRetry = 0;

	if ((CurrCommand == 4) || (CurrCommand == 5) || (CurrCommand == 13) || (CurrCommand == 15)) {
		ResetRequired = TRUE;
	}

	if (!CheckCancel(2)) {
		executing->state = 11;
		stateMotorStopped();
	}
}

/*
 * --INFO--
 * Address:	80200268
 * Size:	0000E4
 */
static void stateCheckID()
{
	switch (CurrCommand) {
	case 3:
		if (memcmp(tmpBuffer, executing->id, 0x1C) != FALSE) {
			DVDLowStopMotor(cbForStateCheckID1);
		} else {
			memcpy(currID, tmpBuffer, sizeof(DVDDiskID));
			executing->state = 1;
			DCInvalidateRange(tmpBuffer, sizeof(DVDBB2));
			LastState = stateCheckID2;
			stateCheckID2(executing);
		}
		break;
	default:
		if (memcmp(tmpBuffer, currID, sizeof(DVDDiskID)) != 0) {
			DVDLowStopMotor(cbForStateCheckID1);
		} else {
			LastState = stateCheckID3;
			stateCheckID3(executing);
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	8020034C
 * Size:	000034
 */
static void stateCheckID3(DVDCommandBlock* cmdBlock) { DVDLowAudioBufferConfig(currID->streaming, 10, cbForStateCheckID3); }

/*
 * --INFO--
 * Address:	80200380
 * Size:	000038
 */
static void stateCheckID2(DVDCommandBlock* block) { DVDLowRead(tmpBuffer, OSRoundUp32B(sizeof(DVDBB2)), 0x420, cbForStateCheckID2); }

/*
 * --INFO--
 * Address:	802003B8
 * Size:	000114
 */
void cbForStateCheckID1(u32 p1)
{
	if (p1 == 16) {
		executing->state = -1;
		stateTimeout();
		return;
	}

	if (p1 & 2) {
		executing->state = -1;
		stateError(0x1234567);
		return;
	}

	NumInternalRetry = 0;

	if (!CheckCancel(1)) {
		executing->state = 6;
		stateMotorStopped();
	}
}

/*
 * --INFO--
 * Address:	802004CC
 * Size:	0000A4
 */
void cbForStateCheckID2(u32 p1)
{
	if (p1 == 16) {
		executing->state = -1;
		stateTimeout();
		return;
	}

	if (p1 & 1) {
		NumInternalRetry = 0;
		stateReadingFST();

	} else {
		stateGettingError();
	}
}

/*
 * --INFO--
 * Address:	80200570
 * Size:	0000FC
 */
static void cbForStateCheckID3(u32 p1)
{
	if (p1 == 16) {
		executing->state = -1;
		stateTimeout();
		return;
	}

	if (p1 & 1) {
		NumInternalRetry = 0;

		if (!CheckCancel(0)) {
			executing->state = 1;
			stateBusy(executing);
		}

	} else {
		stateGettingError();
	}
}

/*
 * --INFO--
 * Address:	8020066C
 * Size:	000044
 */
static void AlarmHandler(OSAlarm* alarm, OSContext* context)
{
	DVDReset();
	DCInvalidateRange(tmpBuffer, sizeof(DVDDiskID));
	LastState = stateCoverClosed_CMD;
	stateCoverClosed_CMD(executing);
}

/*
 * --INFO--
 * Address:	802006B0
 * Size:	0000CC
 */
static void stateCoverClosed()
{
	DVDCommandBlock* cmdBlock;
	switch (CurrCommand) {
	case 4:
	case 5:
	case 13:
	case 15:
		__DVDClearWaitingQueue();
		cmdBlock  = executing;
		executing = &DummyCommandBlock;
		if (cmdBlock->callback) {
			(cmdBlock->callback)(-4, cmdBlock);
		}
		stateReady();
		break;
	default:
		DVDReset();
		OSCreateAlarm(&ResetAlarm);
		OSSetAlarm(&ResetAlarm, OSMillisecondsToTicks(1150), AlarmHandler);
		break;
	}
}

/*
 * --INFO--
 * Address:	8020077C
 * Size:	000030
 */
void stateCoverClosed_CMD(DVDCommandBlock* cmdBlock) { DVDLowReadDiskID(tmpBuffer, cbForStateCoverClosed); }

/*
 * --INFO--
 * Address:	802007AC
 * Size:	000070
 */
void cbForStateCoverClosed(u32 p1)
{
	if (p1 == 16) {
		executing->state = -1;
		stateTimeout();
		return;
	}

	if (p1 & 1) {
		NumInternalRetry = 0;
		stateCheckID();
	} else {
		stateGettingError();
	}
}

/*
 * --INFO--
 * Address:	8020081C
 * Size:	000028
 */
static void stateMotorStopped() { DVDLowWaitCoverClose(cbForStateMotorStopped); }

/*
 * --INFO--
 * Address:	80200844
 * Size:	0000E4
 */
void cbForStateMotorStopped(u32 p1)
{
	__DIRegs[DI_COVER_STATUS] = 0;
	executing->state          = 3;
	stateCoverClosed();
}

/*
 * --INFO--
 * Address:	80200928
 * Size:	000248
 */
void stateReady()
{
	DVDCommandBlock* finished;

	if (!__DVDCheckWaitingQueue()) {
		executing = (DVDCommandBlock*)nullptr;
		return;
	}

	if (PauseFlag) {
		PausingFlag = TRUE;
		executing   = (DVDCommandBlock*)nullptr;
		return;
	}

	executing = __DVDPopWaitingQueue();

	if (FatalErrorFlag) {
		executing->state = -1;
		finished         = executing;
		executing        = &DummyCommandBlock;
		if (finished->callback) {
			(finished->callback)(-1, finished);
		}
		stateReady();
		return;
	}

	CurrCommand = executing->command;

	if (ResumeFromHere) {
		switch (ResumeFromHere) {
		case 1:
			executing->state = 6;
			stateMotorStopped();
			break;

		case 2:
			executing->state = 11;
			stateMotorStopped();
			break;

		case 3:
			executing->state = 4;
			stateMotorStopped();
			break;

		case 7:
			executing->state = 7;
			stateMotorStopped();
			break;

		case 4:
			executing->state = 5;
			stateMotorStopped();
			break;

		case 6:
			executing->state = 3;
			stateCoverClosed();
			break;

		case 5:
			executing->state = -1;
			stateError(CancelLastError);
			break;
		}

		ResumeFromHere = 0;

	} else {
		executing->state = 1;
		stateBusy(executing);
	}
}

// idk why this file insists on doing this in the opposite order
#define DVDMIN(a, b) (((a) > (b)) ? (b) : (a))

/*
 * --INFO--
 * Address:	80200B70
 * Size:	0002C0
 */
void stateBusy(DVDCommandBlock* block)
{
	DVDCommandBlock* finished;
	LastState = stateBusy;
	switch (block->command) {
	case 5:
		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
		block->currTransferSize   = sizeof(DVDDiskID);
		DVDLowReadDiskID(block->addr, cbForStateBusy);
		break;
	case 1:
	case 4:
		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
		block->currTransferSize   = DVDMIN(block->length - block->transferredSize, 0x80000);
		DVDLowRead((void*)((u8*)block->addr + block->transferredSize), block->currTransferSize, block->offset + block->transferredSize,
		           cbForStateBusy);
		break;

	case 2:
		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
		DVDLowSeek(block->offset, cbForStateBusy);
		break;

	case 3:
		DVDLowStopMotor(cbForStateBusy);
		break;

	case 15:
		DVDLowStopMotor(cbForStateBusy);
		break;

	case 6:
		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
		if (AutoFinishing) {
			executing->currTransferSize = 0;
			DVDLowRequestAudioStatus(0, cbForStateBusy);
		} else {
			executing->currTransferSize = 1;
			DVDLowAudioStream(0, block->length, block->offset, cbForStateBusy);
		}
		break;

	case 7:
		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
		DVDLowAudioStream(0x10000, 0, 0, cbForStateBusy);
		break;

	case 8:
		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
		AutoFinishing             = TRUE;
		DVDLowAudioStream(0, 0, 0, cbForStateBusy);
		break;

	case 9:
		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
		DVDLowRequestAudioStatus(0, cbForStateBusy);
		break;

	case 10:
		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
		DVDLowRequestAudioStatus(0x10000, cbForStateBusy);
		break;

	case 11:
		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
		DVDLowRequestAudioStatus(0x20000, cbForStateBusy);
		break;

	case 12:
		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
		DVDLowRequestAudioStatus(0x30000, cbForStateBusy);
		break;

	case 13:
		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
		DVDLowAudioBufferConfig(block->offset, block->length, cbForStateBusy);
		break;

	case 14:
		__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
		block->currTransferSize   = sizeof(DVDDriveInfo);
		DVDLowInquiry(block->addr, cbForStateBusy);
		break;
	}
}

/*
 * --INFO--
 * Address:	80200E30
 * Size:	0005D4
 */
void cbForStateBusy(u32 p1)
{
	DVDCommandBlock* finished;

	if (p1 == 16) {
		executing->state = -1;
		stateTimeout();
		return;
	}

	if ((CurrCommand == 3) || (CurrCommand == 15)) {
		if (p1 & 2) {
			executing->state = -1;
			stateError(0x1234567);
			return;
		}

		NumInternalRetry = 0;

		if (CurrCommand == 15) {
			ResetRequired = TRUE;
		}

		if (CheckCancel(7)) {
			return;
		}

		executing->state = 7;
		stateMotorStopped();
		return;
	}

	if ((CurrCommand == 1) || (CurrCommand == 4) || (CurrCommand == 5) || (CurrCommand == 14)) {
		executing->transferredSize += executing->currTransferSize - __DIRegs[6];
	}

	if (p1 & 8) {
		Canceling = FALSE;
		finished  = executing;
		executing = &DummyCommandBlock;

		finished->state = 10;
		if (finished->callback) {
			(*finished->callback)(-3, finished);
		}
		if (CancelCallback) {
			(CancelCallback)(0, finished);
		}
		stateReady();

		return;
	}

	if (p1 & 1) {
		NumInternalRetry = 0;

		if (CheckCancel(0))
			return;

		if ((CurrCommand == 1) || (CurrCommand == 4) || (CurrCommand == 5) || (CurrCommand == 14)) {
			if (executing->transferredSize != executing->length) {
				stateBusy(executing);
				return;
			}

			finished  = executing;
			executing = &DummyCommandBlock;

			finished->state = 0;
			if (finished->callback) {
				(finished->callback)((s32)finished->transferredSize, finished);
			}
			stateReady();
		} else if ((CurrCommand == 9) || (CurrCommand == 10) || (CurrCommand == 11) || (CurrCommand == 12)) {
			s32 result;

			if ((CurrCommand == 11) || (CurrCommand == 10)) {
				result = (s32)(__DIRegs[DI_MM_BUF] << 2);
			} else {
				result = (s32)__DIRegs[DI_MM_BUF];
			}
			finished  = executing;
			executing = &DummyCommandBlock;

			finished->state = 0;
			if (finished->callback) {
				(finished->callback)(result, finished);
			}
			stateReady();
		} else if (CurrCommand == 6) {
			if (executing->currTransferSize == 0) {
				if (__DIRegs[DI_MM_BUF] & 1) {
					finished  = executing;
					executing = &DummyCommandBlock;

					finished->state = 9;
					if (finished->callback) {
						(finished->callback)(-2, finished);
					}
					stateReady();
				} else {
					AutoFinishing               = FALSE;
					executing->currTransferSize = 1;
					DVDLowAudioStream(0, executing->length, executing->offset, cbForStateBusy);
				}
			} else {
				finished  = executing;
				executing = &DummyCommandBlock;

				finished->state = 0;
				if (finished->callback) {
					(finished->callback)(0, finished);
				}
				stateReady();
			}
		} else {
			finished  = executing;
			executing = &DummyCommandBlock;

			finished->state = 0;
			if (finished->callback) {
				(finished->callback)(0, finished);
			}
			stateReady();
		}

	} else {
		if (CurrCommand == 14) {
			executing->state = -1;
			stateError(0x01234567);
			return;
		}

		if ((CurrCommand == 1 || CurrCommand == 4 || CurrCommand == 5 || CurrCommand == 14)
		    && (executing->transferredSize == executing->length)) {

			if (CheckCancel(0)) {
				return;
			}
			finished  = executing;
			executing = &DummyCommandBlock;

			finished->state = 0;
			if (finished->callback) {
				(finished->callback)((s32)finished->transferredSize, finished);
			}
			stateReady();
			return;
		}

		stateGettingError();
	}
}

/*
 * --INFO--
 * Address:	80201404
 * Size:	0000BC
 */
static BOOL issueCommand(s32 prio, DVDCommandBlock* block)
{
	BOOL level;
	BOOL result;

	if (autoInvalidation && (block->command == 1 || block->command == 4 || block->command == 5 || block->command == 14)) {
		DCInvalidateRange(block->addr, block->length);
	}

	level = OSDisableInterrupts();

	block->state = 2;
	result       = __DVDPushWaitingQueue(prio, block);

	if ((executing == (DVDCommandBlock*)nullptr) && (PauseFlag == FALSE)) {
		stateReady();
	}

	OSRestoreInterrupts(level);

	return result;
}

/*
 * --INFO--
 * Address:	802014C0
 * Size:	0000DC
 */
BOOL DVDReadAbsAsyncPrio(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback, s32 prio)
{
	BOOL idle;
	block->command         = 1;
	block->addr            = addr;
	block->length          = length;
	block->offset          = offset;
	block->transferredSize = 0;
	block->callback        = callback;

	idle = issueCommand(prio, block);
	return idle;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void DVDSeekAbsAsyncPrio(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020159C
 * Size:	0000D0
 */
BOOL DVDReadAbsAsyncForBS(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback)
{
	BOOL idle;
	block->command         = 4;
	block->addr            = addr;
	block->length          = length;
	block->offset          = offset;
	block->transferredSize = 0;
	block->callback        = callback;

	idle = issueCommand(2, block);
	return idle;
}

/*
 * --INFO--
 * Address:	8020166C
 * Size:	0000D4
 */
BOOL DVDReadDiskID(DVDCommandBlock* block, DVDDiskID* diskID, DVDCBCallback callback)
{
	BOOL idle;
	block->command = 5;
	block->addr    = diskID;
	block->length  = sizeof(DVDDiskID);

	block->offset          = 0;
	block->transferredSize = 0;
	block->callback        = callback;

	idle = issueCommand(2, block);
	return idle;
}

/*
 * --INFO--
 * Address:	80201740
 * Size:	0000C4
 */
BOOL DVDPrepareStreamAbsAsync(DVDCommandBlock* block, u32 length, u32 offset, DVDCBCallback callback)
{
	BOOL idle;
	block->command  = 6;
	block->length   = length;
	block->offset   = offset;
	block->callback = callback;

	idle = issueCommand(1, block);
	return idle;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
BOOL DVDCancelStreamAsync(DVDCommandBlock* block, DVDCBCallback callback)
{
	BOOL idle;
	block->command  = 7;
	block->callback = callback;
	idle            = issueCommand(1, block);
	return idle;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80201804
 * Size:	0000A0
 */
BOOL DVDCancelStream(DVDCommandBlock* block)
{
	BOOL result;
	s32 state;
	BOOL enabled;
	s32 retVal;

	result = DVDCancelStreamAsync(block, cbForCancelStreamSync);

	if (result == FALSE) {
		return -1;
	}

	enabled = OSDisableInterrupts();

	while (TRUE) {
		state = ((volatile DVDCommandBlock*)block)->state;

		if (state == 0 || state == -1 || state == 10) {
			retVal = (s32)block->transferredSize;
			break;
		}

		OSSleepThread(&__DVDThreadQueue);
	}

	OSRestoreInterrupts(enabled);
	return retVal;
}

/*
 * --INFO--
 * Address:	802018A4
 * Size:	000028
 */
static void cbForCancelStreamSync(s32 result, DVDCommandBlock* block)
{
	block->transferredSize = (u32)result;
	OSWakeupThread(&__DVDThreadQueue);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
static BOOL DVDStopStreamAtEndAsync(DVDCommandBlock* block, DVDCBCallback callback)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void DVDStopStreamAtEnd(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void cbForStopStreamAtEndSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void DVDGetStreamErrorStatusAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void DVDGetStreamErrorStatus(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void cbForGetStreamErrorStatusSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void DVDGetStreamPlayAddrAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void DVDGetStreamPlayAddr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void cbForGetStreamPlayAddrSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void DVDGetStreamStartAddrAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void DVDGetStreamStartAddr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void cbForGetStreamStartAddrSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void DVDGetStreamLengthAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void DVDGetStreamLength(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void cbForGetStreamLengthSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void __DVDAudioBufferConfig(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void DVDChangeDiskAsyncForBS(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
BOOL DVDChangeDiskAsync(DVDCommandBlock*, DVDDiskID*, DVDCBCallback)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
s32 DVDChangeDisk(DVDCommandBlock*, DVDDiskID*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void cbForChangeDiskSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
BOOL DVDInquiryAsync(DVDCommandBlock* block, DVDDriveInfo* info, DVDCBCallback callback)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void DVDInquiry(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void cbForInquirySync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802018CC
 * Size:	000044
 */
void DVDReset()
{
	DVDLowReset();
	__DIRegs[DI_STATUS]       = 42;
	__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
	ResetRequired             = FALSE;
	ResumeFromHere            = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DVDResetRequired(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
s32 DVDGetCommandBlockStatus(const DVDCommandBlock* block)
{
	int interrupts = OSDisableInterrupts();
	int result;
	if (block->state == 3) {
		result = 1;
	} else {
		result = block->state;
	}
	OSRestoreInterrupts(interrupts);
	return result;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80201910
 * Size:	0000AC
 */
s32 DVDGetDriveStatus()
{
	int interrupts = OSDisableInterrupts();
	int result;
	if (FatalErrorFlag != FALSE) {
		result = DVD_STATE_FATAL_ERROR;
	} else {
		if (PausingFlag != FALSE) {
			result = DVD_STATE_PAUSING;
		} else {
			if (executing == nullptr) {
				result = DVD_STATE_END;
			} else if (executing == &DummyCommandBlock) {
				result = DVD_STATE_END;
			} else {
				result = DVDGetCommandBlockStatus((struct DVDCommandBlock*)executing);
			}
		}
	}
	OSRestoreInterrupts(interrupts);
	return result;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
int DVDSetAutoInvalidation(int newValue)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
static void DVDPause()
{
	BOOL level;
	level     = OSDisableInterrupts();
	PauseFlag = TRUE;
	if (executing == (DVDCommandBlock*)NULL) {
		PausingFlag = TRUE;
	}
	OSRestoreInterrupts(level);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void DVDResume()
{
	BOOL level;
	level     = OSDisableInterrupts();
	PauseFlag = FALSE;
	if (PausingFlag) {
		PausingFlag = FALSE;
		stateReady();
	}
	OSRestoreInterrupts(level);
}

/*
 * --INFO--
 * Address:	802019BC
 * Size:	000270
 */
BOOL DVDCancelAsync(DVDCommandBlock* block, DVDCBCallback callback)
{
	BOOL enabled;
	DVDLowCallback old;

	enabled = OSDisableInterrupts();

	switch (block->state) {
	case -1:
	case 0:
	case 10:
		if (callback)
			(*callback)(0, block);
		break;

	case 1:
		if (Canceling) {
			OSRestoreInterrupts(enabled);
			return FALSE;
		}

		Canceling      = TRUE;
		CancelCallback = callback;
		if (block->command == 4 || block->command == 1) {
			DVDLowBreak();
		}
		break;

	case 2:
		__DVDDequeueWaitingQueue(block);
		block->state = 10;
		if (block->callback)
			(block->callback)(-3, block);
		if (callback)
			(*callback)(0, block);
		break;

	case 3:
		switch (block->command) {
		case 5:
		case 4:
		case 13:
		case 15:
			if (callback)
				(*callback)(0, block);
			break;

		default:
			if (Canceling) {
				OSRestoreInterrupts(enabled);
				return FALSE;
			}
			Canceling      = TRUE;
			CancelCallback = callback;
			break;
		}
		break;

	case 4:
	case 5:
	case 6:
	case 7:
	case 11:
		old = DVDLowClearCallback();
		if (old != cbForStateMotorStopped) {
			OSRestoreInterrupts(enabled);
			return FALSE;
		}

		if (block->state == 4)
			ResumeFromHere = 3;
		if (block->state == 5)
			ResumeFromHere = 4;
		if (block->state == 6)
			ResumeFromHere = 1;
		if (block->state == 11)
			ResumeFromHere = 2;
		if (block->state == 7)
			ResumeFromHere = 7;

		block->state = 10;
		if (block->callback) {
			(block->callback)(-3, block);
		}
		if (callback) {
			(callback)(0, block);
		}
		stateReady();
		break;
	}

	OSRestoreInterrupts(enabled);
	return TRUE;
}

/*
 * --INFO--
 * Address:	80201C2C
 * Size:	0000AC
 */
s32 DVDCancel(DVDCommandBlock* block)
{
	BOOL result;
	s32 state;
	u32 command;
	BOOL enabled;

	result = DVDCancelAsync(block, cbForCancelSync);

	if (result == FALSE) {
		return -1;
	}

	enabled = OSDisableInterrupts();

	for (;;) {
		state = ((volatile DVDCommandBlock*)block)->state;

		if ((state == 0) || (state == -1) || (state == 10)) {
			break;
		}

		if (state == 3) {
			command = ((volatile DVDCommandBlock*)block)->command;

			if ((command == 4) || (command == 5) || (command == 13) || (command == 15)) {
				break;
			}
		}

		OSSleepThread(&__DVDThreadQueue);
	}

	OSRestoreInterrupts(enabled);
	return 0;
}

/*
 * --INFO--
 * Address:	80201CD8
 * Size:	000024
 */
static void cbForCancelSync(s32 result, DVDCommandBlock* block) { OSWakeupThread(&__DVDThreadQueue); }

/*
 * --INFO--
 * Address:	........
 * Size:	0000EC
 */
static BOOL DVDCancelAllAsync(DVDCBCallback callback)
{
	BOOL enabled;
	DVDCommandBlock* p;
	BOOL retVal;

	enabled = OSDisableInterrupts();
	DVDPause();

	while ((p = __DVDPopWaitingQueue()) != 0) {
		DVDCancelAsync(p, NULL);
	}

	if (executing)
		retVal = DVDCancelAsync(executing, callback);
	else {
		retVal = TRUE;
		if (callback)
			(*callback)(0, NULL);
	}

	DVDResume();
	OSRestoreInterrupts(enabled);
	return retVal;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000138
 */
s32 DVDCancelAll()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void cbForCancelAllSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80201CFC
 * Size:	000008
 */
DVDDiskID* DVDGetCurrentDiskID() { return (DVDDiskID*)OSPhysicalToCached(0); }

/*
 * --INFO--
 * Address:	80201D04
 * Size:	0000E4
 */
BOOL DVDCheckDisk()
{
	BOOL enabled;
	s32 result;
	s32 state;
	u32 coverReg;

	enabled = OSDisableInterrupts();

	if (FatalErrorFlag) {
		state = -1;
	} else if (PausingFlag) {
		state = 8;
	} else {
		if (executing == (DVDCommandBlock*)NULL) {
			state = 0;
		} else if (executing == &DummyCommandBlock) {
			state = 0;
		} else {
			state = executing->state;
		}
	}

	switch (state) {
	case 1:
	case 9:
	case 10:
	case 2:
		result = TRUE;
		break;

	case -1:
	case 11:
	case 7:
	case 3:
	case 4:
	case 5:
	case 6:
		result = FALSE;
		break;

	case 0:
	case 8:
		coverReg = __DIRegs[1];
		if (((coverReg >> 2) & 1) || (coverReg & 1)) {
			result = FALSE;
		} else {
			result = TRUE;
		}
	}

	OSRestoreInterrupts(enabled);

	return result;
}

/*
 * --INFO--
 * Address:	80201DE8
 * Size:	00011C
 */
void __DVDPrepareResetAsync(DVDCBCallback callback)
{
	BOOL enabled;

	enabled = OSDisableInterrupts();

	__DVDClearWaitingQueue();

	if (Canceling) {
		CancelCallback = callback;
	} else {
		if (executing) {
			executing->callback = nullptr;
		}

		DVDCancelAllAsync(callback);
	}

	OSRestoreInterrupts(enabled);
}
