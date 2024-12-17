#ifndef _DOLPHIN_AMCEXI2_H
#define _DOLPHIN_AMCEXI2_H

#include "types.h"
#include "Dolphin/os.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

// EXI callback function pointer type
typedef __OSInterruptHandler AmcEXICallback;

// EXI ECB Struct
typedef struct ECB {
	EXICallback exiCallback;  // _00
	EXICallback exiCallback2; // _04
	u8 _08[0x4];              // _08
	volatile u32 state;       // _0C
	u32 length;               // _10
	u8* buffer;               // _14
} ECB;

// EXI error codes
typedef enum {
	AMC_EXI_NO_ERROR = 0,
	AMC_EXI_UNSELECTED

} AmcExiError;

// AmcExi Functions
s32 AmcEXIImm(void* buf, s32 len, u32 type, EXICallback cb);
void AmcEXISync();
void AmcEXIClearInterrupts(s32, s32);
void* AmcEXISetExiCallback(EXICallback cb);
s32 AmcEXISelect(u32 freq);
s32 AmcEXIDeselect();
void AmcDebugIntHandler(__OSInterrupt intr, OSContext* context);
void AmcEXIEnableInterrupts();
void AmcEXIInit();

// AmcExi2Comm Functions
void EXI2_Init(vu8**, EXICallback);
void EXI2_EnableInterrupts(void);
int EXI2_Poll(void);
AmcExiError EXI2_ReadN(void*, u32);
AmcExiError EXI2_WriteN(const void*, u32);
void EXI2_Reserve(void);
void EXI2_Unreserve(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
