#include "Dolphin/os.h"
#include "Dolphin/PPCArch.h"
#include "Dolphin/hw_regs.h"
#include <stddef.h>
#include <string.h>

DECL_SECT(".init") extern char _db_stack_end[];

// memory locations for important stuff
#define OS_DBINTERFACE_ADDR     0x40
#define OS_BI2_DEBUG_ADDRESS    0x800000F4
#define OS_BI2_DEBUGFLAG_OFFSET 0xC
#define PAD3_BUTTON_ADDR        0x800030E4
#define OS_DVD_DEVICECODE       0x800030E6
#define DEBUGFLAG_ADDR          0x800030E8
#define OS_DEBUG_ADDRESS_2      0x800030E9
#define DB_EXCEPTIONRET_OFFSET  0xC
#define DB_EXCEPTIONDEST_OFFSET 0x8
#define MSR_RI_BIT              0x1E

extern u8 __ArenaHi[];
extern u8 __ArenaLo[];
extern u32 __DVDLongFileNameFlag;
extern u32 __PADSpec;

// main workhorse functions
void ClearArena();
void DVDInit();
void DVDInquiryAsync(void*, void*, void*);
void EXIInit();
void EnableMetroTRKInterrupts();
int OSEnableInterrupts();
void SIInit();
void __OSContextInit();
void __OSInitAudioSystem();
void __OSInitMemoryProtection();
void __OSInitSram();
void __OSInitSystemCall();
void __OSInterruptInit();
void __OSThreadInit();
OSTime __OSGetSystemTime();
void DBPrintf(const char*, ...);
BOOL __DBIsExceptionMarked(u8);
void __OSUnhandledException(__OSException exception, OSContext* context, u32 dsisr, u32 dar);
extern char* __OSResetSWInterruptHandler[];

// The exception table.  It points to a location in LoMem.  It is set by
// OSExceptionInit
// typedef u32 __OSExceptionHandler;
#define OS_EXCEPTIONTABLE_ADDR 0x3000
#define OS_DBJUMPPOINT_ADDR    0x60

vu16 __OSDeviceCode AT_ADDRESS(OS_BASE_CACHED | OS_DVD_DEVICECODE);

// flags and system info
static OSBootInfo* BootInfo;
static vu32* BI2DebugFlag;
static u32* BI2DebugFlagHolder;
WEAKFUNC BOOL __OSIsGcam = FALSE;
static f64 ZeroF;
static f32 ZeroPS[2];
static BOOL AreWeInitialized = FALSE;
static __OSExceptionHandler* OSExceptionTable;
OSTime __OSStartTime;
BOOL __OSInIPL;
void* __OSSavedRegionStart;
void* __OSSavedRegionEnd;

// functions
static void OSExceptionInit(void);
static void OSDefaultExceptionHandler(__OSException exception, OSContext* context);

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
u32 __OSIsDebuggerPresent(void)
{
	return *(u32*)OSPhysicalToCached(0x40);
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000084
 */
static ASM void __OSInitFPRs(void) {
#ifdef __MWERKS__ // clang-format off
    nofralloc
    lfd     fp0, ZeroF
    fmr     fp1, fp0
    fmr     fp2, fp0
    fmr     fp3, fp0
    fmr     fp4, fp0
    fmr     fp5, fp0
    fmr     fp6, fp0
    fmr     fp7, fp0
    fmr     fp8, fp0
    fmr     fp9, fp0
    fmr     fp10, fp0
    fmr     fp11, fp0
    fmr     fp12, fp0
    fmr     fp13, fp0
    fmr     fp14, fp0
    fmr     fp15, fp0
    fmr     fp16, fp0
    fmr     fp17, fp0
    fmr     fp18, fp0
    fmr     fp19, fp0
    fmr     fp20, fp0
    fmr     fp21, fp0
    fmr     fp22, fp0
    fmr     fp23, fp0
    fmr     fp24, fp0
    fmr     fp25, fp0
    fmr     fp26, fp0
    fmr     fp27, fp0
    fmr     fp28, fp0
    fmr     fp29, fp0
    fmr     fp30, fp0
    fmr     fp31, fp0
    blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
u32 OSGetConsoleType(void)
{
	if (BootInfo == NULL || BootInfo->consoleType == 0) {
		return OS_CONSOLE_ARTHUR; // default console type
	}
	return BootInfo->consoleType;
}

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
extern void* BOOT_REGION_START : 0x812FDFF0; //(*(void *)0x812fdff0)
extern void* BOOT_REGION_END : 0x812FDFEC;   //(*(void *)0x812fdfec)

void ClearArena()
{
	void *start, *end;
	if ((u32)(OSGetResetCode() + 0x80000000) != 0U) {
		memset(OSGetArenaLo(), 0U, (char*)OSGetArenaHi() - (char*)OSGetArenaLo());
		return;
	}
	start = BOOT_REGION_START;
	end   = BOOT_REGION_END;
	if (BOOT_REGION_START == NULL) {
		memset(OSGetArenaLo(), 0U, (char*)OSGetArenaHi() - (char*)OSGetArenaLo());
		return;
	}

	if (OSGetArenaLo() < start) {
		if (OSGetArenaHi() <= start) {
			memset(OSGetArenaLo(), 0U, (char*)OSGetArenaHi() - (char*)OSGetArenaLo());
			return;
		}
		memset(OSGetArenaLo(), 0U, (char*)start - (char*)OSGetArenaLo());
		if (OSGetArenaHi() > end) {
			memset(end, 0, (char*)OSGetArenaHi() - (char*)end);
		}
	}
}
#endif
/**
 * @TODO: Documentation
 */
void OSInit(void)
{
	/*
	Initializes the Dolphin operating system.
	    - most of the main operations get farmed out to other functions
	    - loading debug info and setting up heap bounds largely happen here
	    - a lot of OS reporting also gets controlled here
	*/
	// pretty sure this is the min(/max) amount of pointers etc for the stack to match
	BI2Debug* DebugInfo;
	void* debugArenaLo;
	u32 inputConsoleType;
	u32 tdev;

	// check if we've already done all this or not
	if ((BOOL)AreWeInitialized == FALSE) { // fantastic name
		AreWeInitialized = TRUE;           // flag to make sure we don't have to do this again

// SYSTEM //
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		__OSStartTime = __OSGetSystemTime();
#endif

		OSDisableInterrupts();

		// DEBUG //
		// load some DVD stuff
		BI2DebugFlag = 0;                           // debug flag from the DVD BI2 header
		BootInfo     = (OSBootInfo*)OS_BASE_CACHED; // set pointer to BootInfo

		__DVDLongFileNameFlag = (u32)0; // flag to tell us whether we make it through the debug loading

		// time to grab a bunch of debug info from the DVD
		// the address for where the BI2 debug info is, is stored at OS_BI2_DEBUG_ADDRESS
		DebugInfo = (BI2Debug*)*((u32*)OS_BI2_DEBUG_ADDRESS);

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		// if the debug info address exists, grab some debug info
		if (DebugInfo != NULL) {
			BI2DebugFlag               = &DebugInfo->debugFlag;     // debug flag from DVD BI2
			__PADSpec                  = (u32)DebugInfo->padSpec;   // some other info from DVD BI2
			*((u8*)DEBUGFLAG_ADDR)     = (u8)*BI2DebugFlag;         // store flag in mem
			*((u8*)OS_DEBUG_ADDRESS_2) = (u8)__PADSpec;             // store other info in mem
		} else if (BootInfo->arenaHi) {                             // if the top of the heap is already set
			BI2DebugFlagHolder = (u32*)*((u8*)DEBUGFLAG_ADDR);      // grab whatever's stored at 0x800030E8
			BI2DebugFlag       = (u32*)&BI2DebugFlagHolder;         // flag is then address of flag holder
			__PADSpec          = (u32) * ((u8*)OS_DEBUG_ADDRESS_2); // pad spec is whatever's at 0x800030E9
		}

		__DVDLongFileNameFlag = (u32)1;
#else
		// if the debug info address exists, grab some debug info
		if (DebugInfo != NULL) {
			BI2DebugFlag          = &DebugInfo->debugFlag;          // debug flag from DVD BI2
			__DVDLongFileNameFlag = DebugInfo->dvdLongFileNameFlag; // we made it through debug!
			__PADSpec             = (u32)DebugInfo->padSpec;        // some other info from DVD BI2
		}
#endif
		// HEAP //
		// set up bottom of heap (ArenaLo)
		// grab address from BootInfo if it exists, otherwise use default __ArenaLo
		OSSetArenaLo((BootInfo->arenaLo == NULL) ? (void*)(__ArenaLo) : BootInfo->arenaLo);

		// if the input arenaLo is null, and debug flag location exists (and flag is < 2),
		//     set arenaLo to just past the end of the db stack
		if ((BootInfo->arenaLo == NULL) && (BI2DebugFlag != 0) && (*BI2DebugFlag < 2)) {
			debugArenaLo = (void*)_stack_addr;
			OSSetArenaLo((void*)ALIGN_NEXT((u32)debugArenaLo, 32));
		}

		// set up top of heap (ArenaHi)
		// grab address from BootInfo if it exists, otherwise use default __ArenaHi
		OSSetArenaHi((BootInfo->arenaHi == NULL) ? __ArenaHi : BootInfo->arenaHi);

		// OS INIT AND REPORT //
		// initialise a whole bunch of OS stuff
		OSExceptionInit();
		__OSInitSystemCall();
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		OSInitAlarm();
#endif
		__OSModuleInit();
		__OSInterruptInit();
		__OSSetInterruptHandler(__OS_INTERRUPT_PI_RSW, (void*)__OSResetSWInterruptHandler);
		__OSContextInit();
		__OSCacheInit();
		EXIInit();
		SIInit();
		__OSInitSram();
		__OSThreadInit();
		__OSInitAudioSystem();
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		PPCMthid2(PPCMfhid2() & 0xBFFFFFFF);
#endif
		if ((BootInfo->consoleType & OS_CONSOLE_DEVELOPMENT) != 0) {
			BootInfo->consoleType = OS_CONSOLE_DEVHW1;
		} else {
			BootInfo->consoleType = OS_CONSOLE_RETAIL1;
		}
		BootInfo->consoleType += (__PIRegs[11] & 0xF0000000) >> 28;
#if defined(VERSION_GPIP01_00)
		if (__OSInIPL == FALSE)
			__OSInitMemoryProtection();
		// begin OS reporting
		OSReport("\nDolphin OS $Revision: 49 $.\n");
		OSReport("Kernel built : %s %s\n", "Dec 17 2001", "18:46:45");
#elif defined(VERSION_G98E01_PIKIDEMO)
		__OSInitMemoryProtection();
		// begin OS reporting
		OSReport("\nDolphin OS $Revision: 47 $.\n");
		OSReport("Kernel built : %s %s\n", "Nov 12 2001", "01:46:17");
#else
		// begin OS reporting
		OSReport("\nDolphin OS $Revision: 37 $.\n");
		OSReport("Kernel built : %s %s\n", "Jul 19 2001", "05:43:42");
#endif
		OSReport("Console Type : ");
		if (BootInfo == NULL || (inputConsoleType = BootInfo->consoleType) == 0) {
			inputConsoleType = OS_CONSOLE_ARTHUR; // default console type
		} else {
			inputConsoleType = BootInfo->consoleType;
		}

		// work out what console type this corresponds to and report it
		inputConsoleType = OSGetConsoleType();
		if ((inputConsoleType & 0x10000000) == OS_CONSOLE_RETAIL) { // check "first" byte
			OSReport("Retail %d\n", inputConsoleType);
		} else {
			switch (inputConsoleType) { // if "first" byte is 2, check "the rest"
			case OS_CONSOLE_EMULATOR:
			{
				OSReport("Mac Emulator\n");
				break;
			}
			case OS_CONSOLE_PC_EMULATOR:
			{
				OSReport("PC Emulator\n");
				break;
			}
			case OS_CONSOLE_ARTHUR:
			{
				OSReport("EPPC Arthur\n");
				break;
			}
			case OS_CONSOLE_MINNOW:
			{
				OSReport("EPPC Minnow\n");
				break;
			}
			default: // if none of the above, just report the info we have
			{
				tdev = (u32)inputConsoleType - 0x10000000;
				OSReport("Development HW%d\n", tdev - 3);
				break;
			}
			}
		}

		// report memory size
		OSReport("Memory %d MB\n", (u32)BootInfo->memorySize >> 0x14U);
		// report heap bounds
		OSReport("Arena : 0x%x - 0x%x\n", OSGetArenaLo(), OSGetArenaHi());

		// if location of debug flag exists, and flag is >= 2, enable MetroTRKInterrupts
		if (BI2DebugFlag && ((*BI2DebugFlag) >= 2)) {
			EnableMetroTRKInterrupts();
		}

// free up memory and re-enable things
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		ClearArena();
#endif
		OSEnableInterrupts();
	}
}

static u32 __OSExceptionLocations[] = {
	0x00000100, // 0  System reset
	0x00000200, // 1  Machine check
	0x00000300, // 2  DSI - seg fault or DABR
	0x00000400, // 3  ISI
	0x00000500, // 4  External interrupt
	0x00000600, // 5  Alignment
	0x00000700, // 6  Program
	0x00000800, // 7  FP Unavailable
	0x00000900, // 8  Decrementer
	0x00000C00, // 9  System call
	0x00000D00, // 10 Trace
	0x00000F00, // 11 Performance monitor
	0x00001300, // 12 Instruction address breakpoint.
	0x00001400, // 13 System management interrupt
	0x00001700  // 14 Thermal interrupt
};

// dummy entry points to the OS Exception vector
void __OSEVStart(void);
void __OSEVEnd(void);
void __OSEVSetNumber(void);
void __OSExceptionVector(void);

void __DBVECTOR(void);
void __OSDBINTSTART(void);
void __OSDBINTEND(void);
void __OSDBJUMPSTART(void);
void __OSDBJUMPEND(void);

#define NOP 0x60000000

/**
 * @TODO: Documentation
 */
static void OSExceptionInit(void)
{
	__OSException exception;
	void* destAddr;

	// These two vars help us change the exception number embedded
	// in the exception handler code.
	u32* opCodeAddr;
	u32 oldOpCode;

	// Address range of the actual code to be copied.
	u8* handlerStart;
	u32 handlerSize;

	// Install the first level exception vector.
	opCodeAddr   = (u32*)__OSEVSetNumber;
	oldOpCode    = *opCodeAddr;
	handlerStart = (u8*)__OSEVStart;
	handlerSize  = (u32)((u8*)__OSEVEnd - (u8*)__OSEVStart);

	// Install the DB integrator, only if we are the first OSInit to be run
	destAddr = (void*)OSPhysicalToCached(OS_DBJUMPPOINT_ADDR);
	if (*(u32*)destAddr == 0) // Lomem should be zero cleared only once by BS2
	{
		DBPrintf("Installing OSDBIntegrator\n");
		memcpy(destAddr, (void*)__OSDBINTSTART, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
		DCFlushRangeNoSync(destAddr, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
		__sync();
		ICInvalidateRange(destAddr, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
	}

	// Copy the right vector into the table
	for (exception = 0; exception < __OS_EXCEPTION_MAX; exception++) {
		if (BI2DebugFlag && (*BI2DebugFlag >= 2) && __DBIsExceptionMarked(exception)) {
			// this DBPrintf is suspicious.
			DBPrintf(">>> OSINIT: exception %d commandeered by TRK\n", exception);
			continue;
		}

		// Modify the copy of code in text before transferring
		// to the exception table.
		*opCodeAddr = oldOpCode | exception;

		// Modify opcodes at __DBVECTOR if necessary
		if (__DBIsExceptionMarked(exception)) {
			DBPrintf(">>> OSINIT: exception %d vectored to debugger\n", exception);
			memcpy((void*)__DBVECTOR, (void*)__OSDBJUMPSTART, (u32)__OSDBJUMPEND - (u32)__OSDBJUMPSTART);
		} else {
			// make sure the opcodes are still nop
			u32* ops = (u32*)__DBVECTOR;
			int cb;

			for (cb = 0; cb < (u32)__OSDBJUMPEND - (u32)__OSDBJUMPSTART; cb += sizeof(u32)) {
				*ops++ = NOP;
			}
		}

		// Install the modified handler.
		destAddr = (void*)OSPhysicalToCached(__OSExceptionLocations[(u32)exception]);
		memcpy(destAddr, handlerStart, handlerSize);
		DCFlushRangeNoSync(destAddr, handlerSize);
		__sync();
		ICInvalidateRange(destAddr, handlerSize);
	}

	// initialize pointer to exception table
	OSExceptionTable = OSPhysicalToCached(OS_EXCEPTIONTABLE_ADDR);

	// install default exception handlers
	for (exception = 0; exception < __OS_EXCEPTION_MAX; exception++) {
		__OSSetExceptionHandler(exception, OSDefaultExceptionHandler);
	}

	// restore the old opcode, so that we can re-start an application without
	// downloading the text segments
	*opCodeAddr = oldOpCode;

	DBPrintf("Exceptions initialized...\n");
}

/**
 * @TODO: Documentation
 */
static ASM void __OSDBIntegrator(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
entry __OSDBINTSTART
	li      r5, OS_DBINTERFACE_ADDR
	mflr    r3
	stw     r3, DB_EXCEPTIONRET_OFFSET(r5)
	lwz     r3, DB_EXCEPTIONDEST_OFFSET(r5)
	oris    r3, r3, OS_CACHED_REGION_PREFIX
	mtlr    r3
	li      r3, 0x30 // MSR_IR | MSR_DR     // turn on memory addressing
	mtmsr   r3
	blr
entry __OSDBINTEND
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
static ASM void __OSDBJump(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
entry __OSDBJUMPSTART
	bla     OS_DBJUMPPOINT_ADDR
entry __OSDBJUMPEND
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
__OSExceptionHandler __OSSetExceptionHandler(__OSException exception, __OSExceptionHandler handler)
{
	__OSExceptionHandler oldHandler;
	oldHandler                  = OSExceptionTable[exception];
	OSExceptionTable[exception] = handler;
	return oldHandler;
}

/**
 * @TODO: Documentation
 */
__OSExceptionHandler __OSGetExceptionHandler(__OSException exception)
{
	return OSExceptionTable[exception];
}

/**
 * @TODO: Documentation
 */
static ASM void OSExceptionVector(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

entry __OSEVStart
	// Save r4 into SPRG0
	mtsprg  0, r4

	// Load current context physical address into r4
	lwz     r4, OS_CURRENTCONTEXT_PADDR

	// Save r3 - r5 into the current context
	stw     r3, OS_CONTEXT_R3(r4)
	mfsprg  r3, 0
	stw     r3, OS_CONTEXT_R4(r4)
	stw     r5, OS_CONTEXT_R5(r4)

	lhz     r3, OS_CONTEXT_STATE(r4)
	ori     r3, r3, OS_CONTEXT_STATE_EXC
	sth     r3, OS_CONTEXT_STATE(r4)

	// Save misc registers
	mfcr    r3
	stw     r3, OS_CONTEXT_CR(r4)
	mflr    r3
	stw     r3, OS_CONTEXT_LR(r4)
	mfctr   r3
	stw     r3, OS_CONTEXT_CTR(r4)
	mfxer   r3
	stw     r3, OS_CONTEXT_XER(r4)
	mfsrr0  r3
	stw     r3, OS_CONTEXT_SRR0(r4)
	mfsrr1  r3
	stw     r3, OS_CONTEXT_SRR1(r4)
	mr      r5, r3

entry __DBVECTOR
	nop

	// Set SRR1[IR|DR] to turn on address
	// translation at the next RFI
	mfmsr   r3
	ori     r3, r3, 0x30
	mtsrr1  r3

	// This lets us change the exception number based on the
	// exception we're installing.
entry __OSEVSetNumber
	addi    r3, 0, 0x0000

	// Load current context virtual address into r4
	lwz     r4, 0xD4

	// Check non-recoverable interrupt
	rlwinm. r5, r5, 0, MSR_RI_BIT, MSR_RI_BIT
	bne     recoverable
	addis   r5, 0,  OSDefaultExceptionHandler@ha
	addi    r5, r5, OSDefaultExceptionHandler@l
	mtsrr0  r5
	rfi
	// NOT REACHED HERE

recoverable:
	// Locate exception handler.
	rlwinm  r5, r3, 2, 22, 29               // r5 contains exception*4
	lwz     r5, OS_EXCEPTIONTABLE_ADDR(r5)
	mtsrr0  r5

	// Final state
	// r3 - exception number
	// r4 - pointer to context
	// r5 - garbage
	// srr0 - exception handler
	// srr1 - address translation enalbed, not yet recoverable

	rfi
	// NOT REACHED HERE
	// The handler will restore state

entry __OSEVEnd
	nop
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
static ASM void OSDefaultExceptionHandler(register __OSException exception, register OSContext* context)
{
#pragma unused(exception)
#ifdef __MWERKS__ // clang-format off
	nofralloc
	OS_EXCEPTION_SAVE_GPRS(context)
	// Load DSISR and DAR
	mfdsisr r5
	mfdar   r6

	b       __OSUnhandledException
	// NOT REACHED HERE
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
void __OSPSInit(void)
{
	PPCMthid2(PPCMfhid2() | 0xA0000000);
	ICFlashInvalidate();
	__sync();
#ifdef __MWERKS__
	asm {
		li      r3, 0
		mtspr   GQR0, r3
	}
#endif
}

#define DI_CONFIG_IDX         0x9
#define DI_CONFIG_CONFIG_MASK 0xFF

/**
 * @TODO: Documentation
 */
u32 __OSGetDIConfig(void)
{
	return (__DIRegs[DI_CONFIG_IDX] & DI_CONFIG_CONFIG_MASK);
}
