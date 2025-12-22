#include "Dolphin/ar.h"
#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"

static ARCallback __AR_Callback;
static u32 __AR_Size;
static u32 __AR_StackPointer;
static u32 __AR_FreeBlocks;
static u32* __AR_BlockLength;

static volatile BOOL __AR_init_flag = FALSE;

static void __ARHandler(__OSInterrupt interrupt, OSContext* context);
static void __ARChecksize(void);

/**
 * @TODO: Documentation
 */
ARCallback ARRegisterDMACallback(ARCallback callback)
{
	ARCallback oldCb;
	BOOL enabled;
	oldCb         = __AR_Callback;
	enabled       = OSDisableInterrupts();
	__AR_Callback = callback;
	OSRestoreInterrupts(enabled);
	return oldCb;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void ARGetDMAStatus(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void ARStartDMA(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length)
{
	BOOL enabled;

	enabled = OSDisableInterrupts();

	// Set main mem address
	__DSPRegs[DSP_ARAM_DMA_MM_HI] = (u16)(__DSPRegs[DSP_ARAM_DMA_MM_HI] & ~0x3ff) | (u16)(mainmem_addr >> 16);
	__DSPRegs[DSP_ARAM_DMA_MM_LO] = (u16)(__DSPRegs[DSP_ARAM_DMA_MM_LO] & ~0xffe0) | (u16)(mainmem_addr & 0xffff);

	// Set ARAM address
	__DSPRegs[DSP_ARAM_DMA_ARAM_HI] = (u16)(__DSPRegs[DSP_ARAM_DMA_ARAM_HI] & ~0x3ff) | (u16)(aram_addr >> 16);
	__DSPRegs[DSP_ARAM_DMA_ARAM_LO] = (u16)(__DSPRegs[DSP_ARAM_DMA_ARAM_LO] & ~0xffe0) | (u16)(aram_addr & 0xffff);

	// Set DMA buffer size
	__DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_HI] & ~0x8000) | (type << 15));
	__DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)(__DSPRegs[DSP_ARAM_DMA_SIZE_HI] & ~0x3ff) | (u16)(length >> 16);
	__DSPRegs[DSP_ARAM_DMA_SIZE_LO] = (u16)(__DSPRegs[DSP_ARAM_DMA_SIZE_LO] & ~0xffe0) | (u16)(length & 0xffff);

	OSRestoreInterrupts(enabled);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void ARAlloc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void ARFree(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void ARCheckInit(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
u32 ARInit(u32* stack_index_addr, u32 num_entries)
{
	BOOL old;
	u16 refresh;

	if (__AR_init_flag == TRUE) {
		return __AR_ARAM_USR_BASE_ADDR;
	}

	old = OSDisableInterrupts();

	__AR_Callback = NULL;

	__OSSetInterruptHandler(__OS_INTERRUPT_DSP_ARAM, __ARHandler);
	__OSUnmaskInterrupts(OS_INTERRUPTMASK_DSP_ARAM);

	__AR_StackPointer = __AR_ARAM_USR_BASE_ADDR;
	__AR_FreeBlocks   = num_entries;
	__AR_BlockLength  = stack_index_addr;

	refresh = 196.0f * (OS_BUS_CLOCK / 202500000.0f);

	__DSPRegs[DSP_ARAM_REFRESH] = (u16)((__DSPRegs[DSP_ARAM_REFRESH] & ~0xFF) | (refresh & 0xFF));

	__ARChecksize();

	__AR_init_flag = TRUE;

	OSRestoreInterrupts(old);

	return __AR_StackPointer;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void ARReset(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void ARSetSize(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
u32 ARGetBaseAddress()
{
	return __AR_ARAM_USR_BASE_ADDR;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void ARGetSize(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void __ARHandler(__OSInterrupt interrupt, OSContext* context)
{
	OSContext exceptionContext;
	u16 tmp;

	tmp                           = __DSPRegs[DSP_CONTROL_STATUS];
	tmp                           = (u16)((tmp & ~(0x80 | 0x8)) | 0x20);
	__DSPRegs[DSP_CONTROL_STATUS] = tmp;

	OSClearContext(&exceptionContext);
	OSSetCurrentContext(&exceptionContext);

	if (__AR_Callback) {
		(*__AR_Callback)();
	}

	OSClearContext(&exceptionContext);
	OSSetCurrentContext(context);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void __ARWaitForDMA(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void __ARWriteDMA(u32 mmem_addr, u32 aram_addr, u32 length)
{
	// Main mem address
	__DSPRegs[DSP_ARAM_DMA_MM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_HI] & ~0x03ff) | (u16)(mmem_addr >> 16));
	__DSPRegs[DSP_ARAM_DMA_MM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_LO] & ~0xffe0) | (u16)(mmem_addr & 0xffff));

	// ARAM address
	__DSPRegs[DSP_ARAM_DMA_ARAM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_HI] & ~0x03ff) | (u16)(aram_addr >> 16));
	__DSPRegs[DSP_ARAM_DMA_ARAM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_LO] & ~0xffe0) | (u16)(aram_addr & 0xffff));

	// DMA buffer size
	__DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)(__DSPRegs[DSP_ARAM_DMA_SIZE_HI] & ~0x8000);

	__DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_HI] & ~0x03ff) | (u16)(length >> 16));
	__DSPRegs[DSP_ARAM_DMA_SIZE_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_LO] & ~0xffe0) | (u16)(length & 0xffff));

	__ARWaitForDMA();

	do {
	} while ((__DSPRegs[DSP_CONTROL_STATUS] & 0x200));
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void __ARReadDMA(u32 mmem_addr, u32 aram_addr, u32 length)
{
	// Main mem address
	__DSPRegs[DSP_ARAM_DMA_MM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_HI] & ~0x03ff) | (u16)(mmem_addr >> 16));
	__DSPRegs[DSP_ARAM_DMA_MM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_LO] & ~0xffe0) | (u16)(mmem_addr & 0xffff));

	// ARAM address
	__DSPRegs[DSP_ARAM_DMA_ARAM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_HI] & ~0x03ff) | (u16)(aram_addr >> 16));
	__DSPRegs[DSP_ARAM_DMA_ARAM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_LO] & ~0xffe0) | (u16)(aram_addr & 0xffff));

	// DMA buffer size
	__DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)(__DSPRegs[DSP_ARAM_DMA_SIZE_HI] | 0x8000);

	__DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_HI] & ~0x03ff) | (u16)(length >> 16));
	__DSPRegs[DSP_ARAM_DMA_SIZE_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_LO] & ~0xffe0) | (u16)(length & 0xffff));

	__ARWaitForDMA();

	do {
	} while ((__DSPRegs[DSP_CONTROL_STATUS] & 0x200));
}

/**
 * @TODO: Documentation
 */
void __ARChecksize(void)
{
	u8 test_data_pad[63];
	u8 dummy_data_pad[63];
	u8 buffer_pad[63];
	u32* test_data;
	u32* dummy_data;
	u32* buffer;
	u16 ARAM_mode;
	u32 ARAM_size;
	u32 i;

	ARAM_mode = 0;
	ARAM_size = 0;

	test_data  = (u32*)(OSRoundUp32B((u32)(test_data_pad)));
	dummy_data = (u32*)(OSRoundUp32B((u32)(dummy_data_pad)));
	buffer     = (u32*)(OSRoundUp32B((u32)(buffer_pad)));

	for (i = 0; i < 8; i++) {
		test_data[i]  = 0xDEADBEEF;
		dummy_data[i] = 0xBAD0BAD0;
	}

	DCFlushRange(test_data, 0x20);
	DCFlushRange(dummy_data, 0x20);
	do {
	} while (!(__DSPRegs[DSP_ARAM_MODE] & 1));

	__DSPRegs[DSP_ARAM_SIZE] = ((__DSPRegs[DSP_ARAM_SIZE] & 0xFFFFFFC0) | 4) | 0x20;
	__ARWriteDMA((u32)dummy_data, 0U, 0x20U);
	__ARWriteDMA((u32)dummy_data, 0x200000U, 0x20U);
	__ARWriteDMA((u32)dummy_data, 0x200U, 0x20U);
	__ARWriteDMA((u32)dummy_data, 0x01000000U, 0x20U);
	__ARWriteDMA((u32)dummy_data, 0x400000U, 0x20U);

	memset(buffer, 0, 0x20);
	DCFlushRange(buffer, 0x20);
	__ARWriteDMA((u32)test_data, 0U, 0x20U);
	__ARReadDMA((u32)buffer, 0U, 0x20U);
	DCInvalidateRange(buffer, 0x20);

	if (*buffer == *test_data) {
		memset(buffer, 0, 0x20);
		DCFlushRange(buffer, 0x20);
		__ARReadDMA((u32)buffer, 0x200000U, 0x20U);
		DCInvalidateRange(buffer, 0x20);
		if (*buffer == *test_data) {
			ARAM_mode = 0;
			ARAM_size = 0x200000;
		} else {
			memset(buffer, 0, 0x20);
			DCFlushRange(buffer, 0x20);
			__ARReadDMA((u32)buffer, 0x01000000U, 0x20U);
			DCInvalidateRange(buffer, 0x20);

			if (*buffer == *test_data) {
				ARAM_mode = 1;
				ARAM_size = 0x400000;

			} else {
				memset(buffer, 0, 0x20);
				DCFlushRange(buffer, 0x20);
				__ARReadDMA((u32)buffer, 0x200U, 0x20U);
				DCInvalidateRange(buffer, 0x20);

				if (*buffer == *test_data) {
					ARAM_mode = 2;
					ARAM_size = 0x800000;

				} else {
					memset(buffer, 0, 0x20);
					DCFlushRange(buffer, 0x20);
					__ARReadDMA((u32)buffer, 0x400000U, 0x20U);
					DCInvalidateRange(buffer, 0x20);

					if (*buffer == *test_data) {
						ARAM_mode = 3;
						ARAM_size = 0x01000000;

					} else {
						ARAM_mode = 4;
						ARAM_size = 0x02000000;
					}
				}
			}
		}
	}

	__DSPRegs[DSP_ARAM_SIZE] = (u16)((__DSPRegs[DSP_ARAM_SIZE] & 0xFFFFFFC0) | 0x20) | ARAM_mode;
	__ARWriteDMA((u32)dummy_data, ARAM_size, 0x20U);
	__ARWriteDMA((u32)dummy_data, ARAM_size + 0x200000, 0x20U);
	__ARWriteDMA((u32)dummy_data, ARAM_size + 0x01000000, 0x20U);
	__ARWriteDMA((u32)dummy_data, ARAM_size + 0x200, 0x20U);
	__ARWriteDMA((u32)dummy_data, ARAM_size + 0x400000, 0x20U);

	memset(buffer, 0, 0x20);
	DCFlushRange(buffer, 0x20);
	__ARWriteDMA((u32)test_data, ARAM_size, 0x20U);
	__ARReadDMA((u32)buffer, ARAM_size, 0x20U);
	DCInvalidateRange(buffer, 0x20);

	if (*buffer == *test_data) {
		memset(buffer, 0, 0x20);
		DCFlushRange(buffer, 0x20);
		__ARReadDMA((u32)buffer, ARAM_size + 0x200000, 0x20U);
		DCInvalidateRange(buffer, 0x20);

		if (*buffer == *test_data) {
			ARAM_size += 0x200000;

		} else {
			memset(buffer, 0, 0x20);
			DCFlushRange(buffer, 0x20);
			__ARReadDMA((u32)buffer, ARAM_size + 0x01000000, 0x20U);
			DCInvalidateRange(buffer, 0x20);

			if (*buffer == *test_data) {
				ARAM_mode |= 8;
				ARAM_size += 0x400000;

			} else {
				memset(buffer, 0, 0x20);
				DCFlushRange(buffer, 0x20);
				__ARReadDMA((u32)buffer, ARAM_size + 0x200, 0x20U);
				DCInvalidateRange(buffer, 0x20);

				if (*buffer == *test_data) {
					ARAM_mode |= 0x10;
					ARAM_size += 0x800000;

				} else {
					memset(buffer, 0, 0x20);
					DCFlushRange(buffer, 0x20);
					__ARReadDMA((u32)buffer, ARAM_size + 0x400000, 0x20U);
					DCInvalidateRange(buffer, 0x20);

					if (*buffer == *test_data) {
						ARAM_mode |= 0x18;
						ARAM_size += 0x01000000;

					} else {
						ARAM_mode |= 0x20;
						ARAM_size += 0x02000000;
					}
				}
			}
		}

		__DSPRegs[DSP_ARAM_SIZE] = ((u16)(__DSPRegs[DSP_ARAM_SIZE] & 0xFFFFFFC0) | ARAM_mode);
	}

	*(u32*)OSPhysicalToUncached(0xD0) = ARAM_size;
	__AR_Size                         = ARAM_size;
}
