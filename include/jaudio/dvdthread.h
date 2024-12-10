#ifndef _JAUDIO_DVDTHREAD_H
#define _JAUDIO_DVDTHREAD_H

#include "types.h"
#include "jaudio/audiostruct.h"
#include "Dolphin/dvd.h"

/////////// JAUDIO DVD THREAD DEFINITIONS ///////////
// Callback function types.
typedef void (*Jac_DVDCallback)(u32);
typedef s32 (*TaskCallback)(void*);
typedef void (*ErrorCallback)(char*, u8* addr);

// Structs (maybe should go in src file?).
/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
typedef struct DVDCall_ {
	u32 owner;                // _00
	char fileName[64];        // _04
	u32 dst;                  // _44
	u32 src;                  // _48
	u32 length;               // _4C
	u32* callbackStatus;      // _50
	Jac_DVDCallback callback; // _54
} DVDCall;

// Global functions (all C++, so no extern C wrap).
void DVDT_SetRootPath(char* path);
void DVDT_ExtendPath(char* dst, char* ext);
s32 DVDT_AddTask(TaskCallback callback, void* stackp, size_t len);
void jac_dvdproc_init();
void* jac_dvdproc(void*);
s32 DVDT_LoadtoDRAM_Main(void*);
s32 DVDT_LoadtoDRAM(u32, char*, u32, u32, u32, u32*, Jac_DVDCallback);
void DVDT_SetBuffer(u8*, u32, u32);
s32 DVDT_CloseBuffer(u8*);
s32 DVDT_LoadtoARAM_Main(void*);
s32 DVDT_LoadtoARAM(u32, char*, u32, u32, u32, u32*, Jac_DVDCallback);
s32 DVDT_CheckFile(char*);
s32 DVDT_LoadFile(char*, u8*);
void DVDT_CheckPass(u32, u32*, Jac_DVDCallback);
s32 Jac_RegisterExtFastOpen(char*);
s32 Jac_RegisterFastOpen(char*);
BOOL Jac_DVDOpen(char*, DVDFileInfo*);

/////////////////////////////////////////////////////

#endif
