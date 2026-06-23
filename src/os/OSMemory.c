#include "types.h"

#include "Dolphin/OS/OSError.h"
#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"

#define TRUNC(n, a) (((u32)(n)) & ~((a) - 1))
#define ROUND(n, a) (((u32)(n) + (a) - 1) & ~((a) - 1))

static BOOL OnReset(BOOL final);

static OSResetFunctionInfo ResetFunctionInfo = {
	OnReset,
	127,
};
u32 OSGetPhysicalMemSize()
{
	return *(u32*)(OSPhysicalToCached(0x0028));
}

u32 OSGetConsoleSimulatedMemSize()
{
	return *(u32*)(OSPhysicalToCached(0x00F0));
}

static BOOL OnReset(BOOL final)
{
	if (final != FALSE) {
		__MEMRegs[MEM_PROT_TYPE] = 0xFF;
		__OSMaskInterrupts(OS_INTERRUPTMASK_MEM_RESET);
	}
	return TRUE;
}

static void MEMIntrruptHandler(__OSInterrupt interrupt, OSContext* context)
{
	u32 addr;
	u32 cause;

	cause                      = __MEMRegs[MEM_INTRPT_SRC];
	addr                       = (((u32)__MEMRegs[MEM_INTRPT_ADDR_HI] & 0x3ff) << 16) | __MEMRegs[MEM_INTRPT_ADDR_LO];
	__MEMRegs[MEM_INTRPT_FLAG] = 0;

#if OS_BUILD_VERSION >= 20011112L
	if (__OSErrorTable[OS_ERROR_PROTECTION]) {
		__OSErrorTable[OS_ERROR_PROTECTION](OS_ERROR_PROTECTION, context, cause, addr);
		return;
	}
#endif

	__OSUnhandledException(OS_ERROR_PROTECTION, context, cause, addr);
}

void OSProtectRange(u32 chan, void* addr, u32 nBytes, u32 control)
{
	BOOL enabled;
	u32 start;
	u32 end;
	u16 reg;
	if (4 <= chan) {
		return;
	}

	control &= OS_PROTECT_CONTROL_RDWR;

	end   = (u32)addr + nBytes;
	start = TRUNC(addr, 1u << 10);
	end   = ROUND(end, 1u << 10);

	DCFlushRange((void*)start, end - start);

	enabled = OSDisableInterrupts();

	__OSMaskInterrupts(OS_INTERRUPTMASK(__OS_INTERRUPT_MEM_0 + chan));

	__MEMRegs[0 + 2 * chan] = (u16)(start >> 10);
	__MEMRegs[1 + 2 * chan] = (u16)(end >> 10);

	reg = __MEMRegs[MEM_PROT_TYPE];
	reg &= ~(OS_PROTECT_CONTROL_RDWR << 2 * chan);
	reg |= control << 2 * chan;
	__MEMRegs[MEM_PROT_TYPE] = reg;

	if (control != OS_PROTECT_CONTROL_RDWR) {
		__OSUnmaskInterrupts(OS_INTERRUPTMASK(__OS_INTERRUPT_MEM_0 + chan));
	}

	OSRestoreInterrupts(enabled);
}

// Compiling the following functions when they didn't exist yet (`OS_BUILD_VERSION == 20011002L`) breaks `__OSInitMemoryProtection`.

#if OS_BUILD_VERSION >= 20011112L

static ASM void Config24MB()
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

	li       r7,     0x00000000

	lis      r4,     0x00000002 @ha
	addi     r4, r4, 0x00000002 @l
	lis      r3,     0x800001ff @ha
	addi     r3, r3, 0x800001ff @l

	lis      r6,     0x01000002 @ha
	addi     r6, r6, 0x01000002 @l
	lis      r5,     0x810000ff @ha
	addi     r5, r5, 0x810000ff @l

	isync

	mtdbatu  0, r7
	mtdbatl  0, r4
	mtdbatu  0, r3
	isync

	mtibatu  0, r7
	mtibatl  0, r4
	mtibatu  0, r3
	isync

	mtdbatu  2, r7
	mtdbatl  2, r6
	mtdbatu  2, r5
	isync

	mtibatu  2, r7
	mtibatl  2, r6
	mtibatu  2, r5
	isync

	mfmsr    r3
	ori      r3, r3, MSR_IR | MSR_DR
	mtsrr1   r3

	mflr     r3
	mtsrr0   r3
	rfi
#endif // clang-format on
}

static ASM void Config48MB()
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

	li       r7,     0x00000000

	lis      r4,     0x00000002 @ha
	addi     r4, r4, 0x00000002 @l
	lis      r3,     0x800003ff @ha
	addi     r3, r3, 0x800003ff @l

	lis      r6,     0x02000002 @ha
	addi     r6, r6, 0x02000002 @l
	lis      r5,     0x820001ff @ha
	addi     r5, r5, 0x820001ff @l

	isync

	mtdbatu  0, r7
	mtdbatl  0, r4
	mtdbatu  0, r3
	isync

	mtibatu  0, r7
	mtibatl  0, r4
	mtibatu  0, r3
	isync

	mtdbatu  2, r7
	mtdbatl  2, r6
	mtdbatu  2, r5
	isync

	mtibatu  2, r7
	mtibatl  2, r6
	mtibatu  2, r5
	isync

	mfmsr    r3
	ori      r3, r3, MSR_IR | MSR_DR
	mtsrr1   r3

	mflr     r3
	mtsrr0   r3
	rfi
#endif // clang-format on
}

static ASM void RealMode(register u32 addr)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	clrlwi  addr, addr, 2
	mtsrr0  addr
	mfmsr   r3
	rlwinm  r3, r3, 0, 28, 25  // ~(MSR_IR | MSR_DR)
	mtsrr1  r3
	rfi
#endif // clang-format on
}

#endif

void __OSInitMemoryProtection()
{
#if OS_BUILD_VERSION >= 20011112L
	u32 simulatedSize;
	BOOL enabled;
	STACK_PAD_VAR(8);

	simulatedSize = OSGetConsoleSimulatedMemSize();
	enabled       = OSDisableInterrupts();
	if (simulatedSize <= 0x1800000) {
		RealMode((u32)&Config24MB);
	} else if (simulatedSize <= 0x3000000) {
		RealMode((u32)&Config48MB);
	}
#else
	STACK_PAD_VAR(4);
#endif

	__MEMRegs[MEM_INTRPT_FLAG] = 0;
	__MEMRegs[MEM_PROT_TYPE]   = 0xFF;

	__OSMaskInterrupts(OS_INTERRUPTMASK_MEM_RESET);
	__OSSetInterruptHandler(__OS_INTERRUPT_MEM_0, MEMIntrruptHandler);
	__OSSetInterruptHandler(__OS_INTERRUPT_MEM_1, MEMIntrruptHandler);
	__OSSetInterruptHandler(__OS_INTERRUPT_MEM_2, MEMIntrruptHandler);
	__OSSetInterruptHandler(__OS_INTERRUPT_MEM_3, MEMIntrruptHandler);
	__OSSetInterruptHandler(__OS_INTERRUPT_MEM_ADDRESS, MEMIntrruptHandler);
	OSRegisterResetFunction(&ResetFunctionInfo);

	if (OSGetConsoleSimulatedMemSize() < OSGetPhysicalMemSize() && OSGetConsoleSimulatedMemSize() == 0x1800000) {
		__MEMRegs[MEM_20] = 2;
	}

	__OSUnmaskInterrupts(OS_INTERRUPTMASK_MEM_ADDRESS);

#if OS_BUILD_VERSION >= 20011112L
	OSRestoreInterrupts(enabled);
#endif
}
