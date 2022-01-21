#include "types.h"
#include "stdio.h"
#include "Dolphin/OSError.h"

extern OSErrorHandler OSErrorTable[16];
/*
 * --INFO--
 * Address:	801F7890
 * Size:	000080
 */
void OSReport(char *msg, ...)
{
    va_list args;

    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
}

/*
 * --INFO--
 * Address:	801F7910
 * Size:	00012C
 */
void OSPanic(char *file, int line, char *msg, ...)
{
    va_list args;
    u32 i;
    u32 *sp;

    OSDisableInterrupts();

    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    OSReport(" in \"%s\" on line %d.\n", file, line);

    // Print stack trace
    OSReport("\nAddress:      Back Chain    LR Save\n");
    i = 0;
    sp = (u32 *)OSGetStackPointer();
    while (sp != NULL && (u32)sp != 0xFFFFFFFF && i++ < 16)
    {
        OSReport("0x%08x:   0x%08x    0x%08x\n", (u32)sp, sp[0], sp[1]);
        sp = (u32 *)sp[0];
    }
    PPCHalt();
}

/*
 * --INFO--
 * Address:	801F7A3C
 * Size:	00001C
 */
OSErrorHandler OSSetErrorHandler(OSError error, OSErrorHandler handler)
{
    OSErrorHandler prevHandler = OSErrorTable[error];

    OSErrorTable[error] = handler;
    return prevHandler;
}

/*
 * --INFO--
 * Address:	801F7A58
 * Size:	000174
 */
void __OSUnhandledException(u8 error, OSContext *context, u32 dsisr, u32 dar)
{
    if (!(context->srr1 & (1 << 1)))
        OSReport("Non-recoverable Exception %d", error);
    else
    {
        if (OSErrorTable[error] != NULL)
        {
            OSErrorTable[error](error, context, dsisr, dar);
            OSLoadContext(context);
        }
        if (error == OS_ERROR_DECREMENTER)
            OSLoadContext(context);
        OSReport("Unhandled Exception %d", error);
    }

    OSReport("\n");
    OSDumpContext(context);
    OSReport("\nDSISR= 0x%08x                   DAR  = 0x%08x\n", dsisr, dar);
    switch(error)
    {
    case OS_ERROR_DSI:
        OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access invalid address 0x%x (read from DAR)\n", context->srr0, dar);
        break;
    case OS_ERROR_ISI:
        OSReport("\nAttempted to fetch instruction from invalid address 0x%x (read from SRR0)\n", context->srr0);
        break;
    case OS_ERROR_ALIGNMENT:
        OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access unaligned address 0x%x (read from DAR)\n", context->srr0, dar);
        break;
    case OS_ERROR_PROGRAM:
        OSReport("\nProgram exception : Possible illegal instruction/operation at or around 0x%x (read from SRR0)\n", context->srr0, dar);
        break;
    }
    PPCHalt();
}
