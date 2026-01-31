#include "Dolphin/OS/OSError.h"

#include "Dolphin/OS/OSException.h"
#include "Dolphin/OS/OSInterrupt.h"
#include "Dolphin/PPCArch.h"
#include "Dolphin/hw_regs.h"

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_G98P01_PIKIDEMO) || defined(VERSION_GPIP01_00)
OSErrorHandler __OSErrorTable[OS_ERROR_MAX];
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
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_G98P01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	OSErrorHandler prevHandler = __OSErrorTable[error];

	__OSErrorTable[error] = handler;
#else
	OSErrorHandler prevHandler = OSErrorTable[error];

	OSErrorTable[error] = handler;
#endif
	return prevHandler;
}

/**
 * @TODO: Documentation
 */
void __OSUnhandledException(__OSException exception, OSContext* context, u32 dsisr, u32 dar)
{
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_G98P01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	if (!(context->srr1 & MSR_RI)) {
		OSReport("Non-recoverable Exception %d", exception);
	} else {
		if (__OSErrorTable[exception]) {
			OSDisableScheduler();
			__OSErrorTable[exception](exception, context, dsisr, dar);
			OSEnableScheduler();
			__OSReschedule();
			OSLoadContext(context);
		}

		if (exception == OS_ERROR_DECREMENTER) {
			OSLoadContext(context);
		}

		OSReport("Unhandled Exception %d", exception);
	}

	OSReport("\n");
	OSDumpContext(context);
	OSReport("\nDSISR = 0x%08x                   DAR  = 0x%08x\n", dsisr, dar);
	OSReport("TB = 0x%016llx\n", OSGetTime());

	switch (exception) {
	case __OS_EXCEPTION_DSI:
	{
		OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access invalid address 0x%x (read from DAR)\n", context->srr0, dar);
		break;
	}
	case __OS_EXCEPTION_ISI:
	{
		OSReport("\nAttempted to fetch instruction from invalid address 0x%x (read from SRR0)\n", context->srr0);
		break;
	}
	case __OS_EXCEPTION_ALIGNMENT:
	{
		OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access unaligned address 0x%x (read from DAR)\n", context->srr0, dar);
		break;
	}
	case __OS_EXCEPTION_PROGRAM:
	{
		OSReport("\nProgram exception : Possible illegal instruction/operation at or around 0x%x (read from SRR0)\n", context->srr0, dar);
		break;
	}
	case OS_ERROR_PROTECTION:
	{
		OSReport("\n");
		OSReport("AI DMA Address =   0x%04x%04x\n", __DSPRegs[0x00000018], __DSPRegs[0x00000018 + 1]);
		OSReport("ARAM DMA Address = 0x%04x%04x\n", __DSPRegs[0x00000010], __DSPRegs[0x00000010 + 1]);
		OSReport("DI DMA Address =   0x%08x\n", __DIRegs[0x00000005]);
		break;
	}
	}

	OSReport("\nLast interrupt (%d): SRR0 = 0x%08x  TB = 0x%016llx\n", __OSLastInterrupt, __OSLastInterruptSrr0, __OSLastInterruptTime);
#else
	if (!(context->srr1 & (1 << 1)))
		OSReport("Non-recoverable Exception %d", exception);
	else {
		if (OSErrorTable[exception] != NULL) {
			OSErrorTable[exception](exception, context, dsisr, dar);
			OSLoadContext(context);
		}
		if (exception == OS_ERROR_DECREMENTER)
			OSLoadContext(context);
		OSReport("Unhandled Exception %d", exception);
	}

	OSReport("\n");
	OSDumpContext(context);
	OSReport("\nDSISR= 0x%08x                   DAR  = 0x%08x\n", dsisr, dar);
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
	}
#endif
	PPCHalt();
}
