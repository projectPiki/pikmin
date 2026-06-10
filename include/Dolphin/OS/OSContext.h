#ifndef _DOLPHIN_OS_OSCONTEXT_H
#define _DOLPHIN_OS_OSCONTEXT_H

#include "Dolphin/OS/OSVersion.h"
#include "types.h"

BEGIN_SCOPE_EXTERN_C

////////// CONTEXT TYPES /////////
// Struct for holding register context info (size 0x2C8).
typedef struct OSContext {
	u32 gpr[32];   // _00, general purpose registers.
	u32 cr;        // _80
	u32 lr;        // _84
	u32 ctr;       // _88
	u32 xer;       // _8C
	f64 fpr[32];   // _90, floating point registers.
	f64 fpscr;     // _190
	u32 srr0;      // _198, exception handling 0.
	u32 srr1;      // _19C, exception handling 1.
	u16 mode;      // _1A0, context mode.
	u16 state;     // _1A2, |'d OS_CONTEXT_STATE_*
	u32 gqr[8];    // _1A4, Gekko additional registers.
#if OS_BUILD_VERSION >= 20011002L
	u32 psf_pad;
#endif
	f64 psf[32]; // _1C8, Gekko additional registers.
} OSContext;

// Memory address in physical lowmem containing the current context (physical) address
#define OS_CURRENTCONTEXT_PADDR 0x000000C0

// Context modes
#define OS_CONTEXT_MODE_FPU  (0x01U)
#define OS_CONTEXT_MODE_PSFP (0x02U)

// Context states
#define OS_CONTEXT_STATE_FPSAVED (0x01U)
#define OS_CONTEXT_STATE_EXC     (0x02U)

//////////////////////////////////

/////// CONTEXT FUNCTIONS ////////
// Context functions.
void OSLoadContext(OSContext* context);
void OSClearContext(OSContext* context);
void OSInitContext(OSContext* context, u32 pc, u32 stackPtr);
void OSDumpContext(OSContext* context);
u32 OSSaveContext(OSContext* context);

u32 OSGetStackPointer();

// Current context functions.
OSContext* OSGetCurrentContext();
void OSSetCurrentContext(OSContext* context);

// FPU functions.
void OSSaveFPUContext(OSContext* context);
void OSFillFPUContext(OSContext* context);

// Unused/inlined in P2.
u32 OSSwitchStack(u32 newStackPtr);
int OSSwitchFiber(u32 pc, u32 newStackPtr);

void OSLoadFPUContext(OSContext* context);

//////////////////////////////////

END_SCOPE_EXTERN_C

#endif
