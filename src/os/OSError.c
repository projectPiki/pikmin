#include "Dolphin/PPCArch.h"
#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#if OS_BUILD_VERSION >= 20011112L
OSErrorHandler __OSErrorTable[OS_ERROR_MAX];
// For ease of implementing revisional differences.
#define OSErrorTable __OSErrorTable
#else
static OSErrorHandler OSErrorTable[OS_ERROR_MAX];
#endif
/**
 * @TODO: Documentation
 */
void OSReport(const char* msg, ...)
{
	va_list args;

	va_start(args, msg);
	vprintf(msg, args);
	va_end(args);
}

/**
 * @TODO: Documentation
 */
void OSPanic(const char* file, int line, const char* msg, ...)
{
	va_list args;
	u32 i;
	u32* sp;

	OSDisableInterrupts();

	va_start(args, msg);
	vprintf(msg, args);
	va_end(args);
	OSReport(" in \"%s\" on line %d.\n", file, line);

	// Print stack trace
	OSReport("\nAddress:      Back Chain    LR Save\n");
	i  = 0;
	sp = (u32*)OSGetStackPointer();
	while (sp != NULL && (u32)sp != 0xFFFFFFFF && i++ < 16) {
		OSReport("0x%08x:   0x%08x    0x%08x\n", (u32)sp, sp[0], sp[1]);
		sp = (u32*)sp[0];
	}
	PPCHalt();
}

/**
 * @TODO: Documentation
 */
OSErrorHandler OSSetErrorHandler(OSError error, OSErrorHandler handler)
{
	OSErrorHandler prevHandler = OSErrorTable[error];

	OSErrorTable[error] = handler;
	return prevHandler;
}

/**
 * @TODO: Documentation
 */
void __OSUnhandledException(__OSException exception, OSContext* context, u32 dsisr, u32 dar)
{
	if (!(context->srr1 & MSR_RI)) {
		OSReport("Non-recoverable Exception %d", exception);
	} else {
		if (OSErrorTable[exception] != NULL) {
#if OS_BUILD_VERSION >= 20011112L
			OSDisableScheduler();
#endif
			OSErrorTable[exception](exception, context, dsisr, dar);
#if OS_BUILD_VERSION >= 20011112L
			OSEnableScheduler();
			__OSReschedule();
#endif
			OSLoadContext(context);
		}

		if (exception == OS_ERROR_DECREMENTER) {
			OSLoadContext(context);
		}

		OSReport("Unhandled Exception %d", exception);
	}

	OSReport("\n");
	OSDumpContext(context);
#if OS_BUILD_VERSION >= 20011112L
	OSReport("\nDSISR = 0x%08x                   DAR  = 0x%08x\n", dsisr, dar);
	OSReport("TB = 0x%016llx\n", OSGetTime());
#else
	OSReport("\nDSISR= 0x%08x                   DAR  = 0x%08x\n", dsisr, dar);
#endif

	switch (exception) {
	case OS_ERROR_DSI:
	{
		OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access invalid address 0x%x (read from DAR)\n", context->srr0, dar);
		break;
	}
	case OS_ERROR_ISI:
	{
		OSReport("\nAttempted to fetch instruction from invalid address 0x%x (read from SRR0)\n", context->srr0);
		break;
	}
	case OS_ERROR_ALIGNMENT:
	{
		OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access unaligned address 0x%x (read from DAR)\n", context->srr0, dar);
		break;
	}
	case OS_ERROR_PROGRAM:
	{
		OSReport("\nProgram exception : Possible illegal instruction/operation at or around 0x%x (read from SRR0)\n", context->srr0, dar);
		break;
	}
#if OS_BUILD_VERSION >= 20011112L
	case OS_ERROR_PROTECTION:
	{
		OSReport("\n");
		OSReport("AI DMA Address =   0x%04x%04x\n", __DSPRegs[DSP_DMA_START_HI], __DSPRegs[DSP_DMA_START_LO]);
		OSReport("ARAM DMA Address = 0x%04x%04x\n", __DSPRegs[DSP_ARAM_DMA_MM_HI], __DSPRegs[DSP_ARAM_DMA_MM_LO]);
		OSReport("DI DMA Address =   0x%08x\n", __DIRegs[DI_DMA_MEM_ADDR]);
		break;
	}
#endif
	}

#if OS_BUILD_VERSION >= 20011112L
	OSReport("\nLast interrupt (%d): SRR0 = 0x%08x  TB = 0x%016llx\n", __OSLastInterrupt, __OSLastInterruptSrr0, __OSLastInterruptTime);
#endif

	PPCHalt();
}
