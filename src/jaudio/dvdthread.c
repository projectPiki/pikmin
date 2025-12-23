#include "jaudio/dvdthread.h"
#include "Dolphin/ar.h"
#include "Dolphin/os.h"
#include "jaudio/aictrl.h"
#include "jaudio/sample.h"
#include <string.h>

static char audio_root_path[32] = "";

static OSMessageQueue mq;
static s32 msgbuf[0x80];
static u8 CALLSTACK[0x8000];

static u32 mq_init;
static size_t buffersize;
static u32 buffers;
static size_t next_buffersize;
static u8* next_buffertop;
static u32 next_buffers;
static u32 cur_q;
static OSThreadQueue dvdt_sleep;
static BOOL DVDT_PAUSE_FLAG;

static ErrorCallback error_callback;
static u8* ADVD_BUFFER[2];
static u32 buffer_load;

static vu32 buffer_full;

static void __Alloc_DVDBuffer();
static void __UpdateBuffer();
static void __WriteBufferSize(u8*, u32, u32);

/**
 * @TODO: Documentation
 */
static void* GetCallStack()
{
	void* ret;
	BOOL enable = OSDisableInterrupts();

	ret = &CALLSTACK[cur_q++ * 0x100];

	if (cur_q == 0x80) {
		cur_q = 0;
	}

	OSRestoreInterrupts(enable);

	return ret;
}

/**
 * @TODO: Documentation
 */
static s32 DVDReadMutex(DVDFileInfo* fileInfo, void* addr, s32 len, s32 offs, immut char* errorArg)
{
	if (DVDT_PAUSE_FLAG == TRUE) {
		OSSleepThread(&dvdt_sleep);
	}

	while (TRUE) {
		s32 readPrioStatus = DVDReadPrio(fileInfo, addr, len, offs, 2);
		if (readPrioStatus == -1 && error_callback) {
			error_callback(errorArg, (u8*)addr);
			continue;
		}

		return readPrioStatus;
	}
}

/**
 * @TODO: Documentation
 */
void DVDT_SetRootPath(immut char* path)
{
	// don't ask.
	immut char** REF_path = &path;
	if (strlen(path) < 31) {
		strcpy(audio_root_path, path);
	}
}

/**
 * @TODO: Documentation
 */
void DVDT_ExtendPath(char* dst, immut char* ext)
{
	if (*audio_root_path != NULL) {
		strcpy(dst, audio_root_path);
		if (*ext == '/') {
			strcat(dst, ext + 1);
		} else {
			strcat(dst, ext);
		}
	} else {
		strcpy(dst, ext);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00007C
 */
s32 DVDT_AddTaskHigh(TaskCallback, void*, size_t)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
s32 DVDT_AddTask(TaskCallback callback, void* stack, size_t len)
{
	if (mq_init == FALSE) {
		return 0;
	}

	TaskCallback* cstack = (TaskCallback*)GetCallStack();

	Jac_bcopy(stack, cstack + 1, len);

	*cstack = callback;
	OSSendMessage(&mq, (OSMessage)cstack, OS_MESSAGE_BLOCK);

	return 1;
}

/**
 * @TODO: Documentation
 */
void jac_dvdproc_init()
{
	OSInitMessageQueue(&mq, (OSMessage*)msgbuf, ARRAY_SIZE(msgbuf));
	mq_init = 1;
}

/**
 * @TODO: Documentation
 */
void* jac_dvdproc(void*)
{
	__Alloc_DVDBuffer();
	TaskCallback* callback;

	u8* buf = (u8*)OSAlloc2(0x10000);

	OSInitThreadQueue(&dvdt_sleep);
	OSMessage msg;
	while (TRUE) {
		while (TRUE) {
			OSReceiveMessage(&mq, &msg, OS_MESSAGE_BLOCK);
			callback = (TaskCallback*)msg;
			__UpdateBuffer();

			if (buffersize == 0) {
				__WriteBufferSize(buf, 2, 0x8000);
			}
			if (callback != NULL) {
				break;
			};
		}
		(*callback)(callback + 1);
	}
}

/**
 * @TODO: Documentation
 */
static void __DoError(DVDCall* call, u32)
{
	if (call->callbackStatus != NULL) {
		*call->callbackStatus = -1;
	}

	if (call->callback != NULL) {
		call->callback(-1);
	}
}

/**
 * @TODO: Documentation
 */
static void __DoFinish(DVDCall* call, u32 status)
{
	if (call->callbackStatus != NULL) {
		*call->callbackStatus = status;
	}

	if (call->callback != NULL) {
		call->callback(call->owner);
	}
}

/**
 * @TODO: Documentation
 */
static void __DVDT_CheckBack(void* cb)
{
	DVDCall* callback = (DVDCall*)cb;

	__DoFinish(callback, callback->owner);
}

/**
 * @TODO: Documentation
 */
s32 DVDT_LoadtoDRAM_Main(void* dvdCall)
{
	s32 readStatus = 0;
	DVDCall* call  = (DVDCall*)dvdCall;
	DVDFileInfo info;
	if (Jac_DVDOpen(call->fileName, &info) == FALSE) {
		__DoError(call, 0);
		return -1;
	}

	u32 infoLength = info.length;
	if (infoLength == 0) {
		__DoError(call, 1);
		return -1;
	}

	if (call->length == 0) {
		call->length = infoLength;
		call->length -= call->src;
	}

	DCInvalidateRange((void*)call->dst, call->length);
	readStatus |= DVDReadMutex(&info, (void*)call->dst, call->length, call->src, call->fileName);
	DVDClose(&info);
	__DoFinish(call, readStatus);
	return 0;
}

/**
 * @TODO: Documentation
 */
s32 DVDT_LoadtoDRAM(u32 owner, immut char* name, u32 dst, u32 src, u32 length, u32* status, Jac_DVDCallback callback)
{
	DVDCall call;
	DVDCall* pCall = &call;
	pCall->owner   = owner;
	DVDT_ExtendPath(pCall->fileName, name);

	pCall->dst            = dst;
	pCall->callbackStatus = status;

	if (status) {
		*status = 0;
	}
	pCall->callback = callback;
	pCall->src      = src;
	pCall->length   = length;

	DVDT_AddTask(&DVDT_LoadtoDRAM_Main, (void*)pCall, sizeof(DVDCall));
	return 0;
}

/**
 * @TODO: Documentation
 */
static void __Alloc_DVDBuffer()
{
	if (buffersize == 0) {
		int i;

		for (i = 0; i < buffers; i++) {
			ADVD_BUFFER[i] = 0;
		}
	}
}

/**
 * @TODO: Documentation
 */
static void __WriteBufferSize(u8* buf, u32 numBuffers, u32 size)
{
	buffersize = size;
	buffers    = numBuffers;

	int i;
	int j = numBuffers;

	for (i = 0; i < numBuffers; i++, j--) {
		ADVD_BUFFER[i] = buf;
		buf += size;
	}
}

/**
 * @TODO: Documentation
 */
static void __UpdateBuffer()
{
	if (next_buffers != 0) {
		__WriteBufferSize(next_buffertop, next_buffers, next_buffersize);
		next_buffers   = 0;
		next_buffertop = NULL;
	}
}

/**
 * @TODO: Documentation
 */
void DVDT_SetBuffer(u8* buf, u32 numBuffers, u32 size)
{
	if (mq_init == 0) {
		__WriteBufferSize(buf, numBuffers, size);
		return;
	}

	next_buffertop  = buf;
	next_buffersize = size;
	next_buffers    = numBuffers;

	OSSendMessage(&mq, 0, OS_MESSAGE_NOBLOCK);
}

/**
 * @TODO: Documentation
 */
s32 DVDT_CloseBuffer(u8* buf)
{
	if (mq_init == 0) {
		__WriteBufferSize(NULL, 0, 0);
		return 1;
	}

	if (next_buffertop == buf) {
		next_buffers = 0;
		OSSendMessage(&mq, 0, OS_MESSAGE_NOBLOCK);
		return 1;
	}

	if (ADVD_BUFFER[0] == buf) {
		if (next_buffers == 0) {
			next_buffertop  = NULL;
			next_buffersize = 0;
			next_buffers    = 1;
			OSSendMessage(&mq, 0, OS_MESSAGE_NOBLOCK);
		}
		return 0;
	}

	return 1;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
void DVDT_GetCurrentBuffer(u8**)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
static void ARAM_DMAfinish(u32)
{
	buffer_full--;
}

/**
 * @TODO: Documentation
 */
s32 DVDT_LoadtoARAM_Main(void* dvdCall)
{
	STACK_PAD_VAR(2);

	DVDCall* call        = (DVDCall*)dvdCall;
	static int arq_index = 0;
	static DVDFileInfo finfo;
	static ARQRequest req[4];

	if (!Jac_DVDOpen(call->fileName, &finfo)) {
		__DoError(call, 0);
		return -1;
	}

	u32 len = finfo.length;
	if (len == 0) {
		__DoError(call, 1);
		return -1;
	}

	if (call->length == 0) {
		call->length = len;

		call->length -= call->src;
	}

	OSGetTick();

	while (call->length != 0) {
		u32 readSize;
		u8* buf     = ADVD_BUFFER[buffer_load];
		buffer_load = (buffer_load + 1) % buffers;
		while (buffer_full == buffers)
			;

		if (call->length < buffersize) {
			readSize = ALIGN_NEXT(call->length, 32);
			len      = DVDReadMutex(&finfo, buf, readSize, call->src, call->fileName);

			call->length = 0;
		} else {
			readSize = buffersize;
			len      = DVDReadMutex(&finfo, buf, readSize, call->src, call->fileName);

			call->src += buffersize;
			call->length -= buffersize;
		}

		ARQPostRequest(&req[arq_index], 0x12345678, ARQ_TYPE_MRAM_TO_ARAM, ARQ_PRIORITY_HIGH, (u32)buf, call->dst, readSize,
		               ARAM_DMAfinish);
		buffer_full++;
		arq_index++;
		arq_index &= 3;
		call->dst += readSize;
	}

	DVDClose(&finfo);

	while (buffer_full != 0)
		;

	OSGetTick();

	__DoFinish(call, len);

	return 0;
}

/**
 * @TODO: Documentation
 */
s32 DVDT_LoadtoARAM(u32 owner, immut char* path, u32 dst, u32 src, u32 length, u32* status, Jac_DVDCallback callback)
{
	DVDCall call;
	DVDCall* pCall = &call;

	pCall->owner = owner;
	DVDT_ExtendPath(pCall->fileName, path);

	pCall->dst            = dst;
	pCall->callbackStatus = status;
	if (status != 0) {
		*status = 0;
	}

	pCall->callback = callback;
	pCall->src      = src;
	pCall->length   = length;

	DVDT_AddTask(DVDT_LoadtoARAM_Main, pCall, 0x58);

	return 0;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
void ARAM_DMAfinish2(u32)
{
	static DVDFileInfo finfo;
	static ARQRequest req;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00007C
 */
void DVDT_ARAMtoDRAM_Main(void*)
{
	static DVDFileInfo finfo;
	static ARQRequest req;

	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00007C
 */
void DVDT_DRAMtoARAM_Main(void*)
{
	// static DVDFileInfo finfo;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000060
 */
void DVDT_ARAMtoDRAM(u32, u32, u32, u32, u32*, void (*)(u32))
{
	// static DVDFileInfo finfo;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000060
 */
void DVDT_DRAMtoARAM(u32, u32, u32, u32, u32*, void (*)(u32))
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
s32 DVDT_CheckFile(immut char* file)
{
	char path[64];
	immut char** REF_file = &file;
	static DVDFileInfo finfo;

	DVDT_ExtendPath(path, file);

	if (!Jac_DVDOpen(path, &finfo)) {
		return 0;
	}
	u32 len = finfo.length;

	DVDClose(&finfo);
	return len;
}

/**
 * @TODO: Documentation
 */
s32 DVDT_LoadFile(immut char* file, u8* p2)
{
	vu32 status           = 0;
	immut char** REF_file = &file;
	STACK_PAD_VAR(2);
	DVDT_LoadtoDRAM(0, file, (u32)p2, 0, 0, (u32*)&status, NULL);

	while (status == 0) { }

	if (status == -1) {
		return 0;
	}

	return status;
}

/**
 * @TODO: Documentation
 */
void DVDT_CheckPass(u32 owner, u32* status, Jac_DVDCallback callback)
{
	DVDCall call;
	void* cb = (void*)&call;

	call.owner          = owner;
	call.callbackStatus = status;
	call.callback       = callback;

	DVDT_AddTask((TaskCallback)__DVDT_CheckBack, cb, 0x58);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000064
 */
void Jac_CheckFile(immut char*)
{
	static DVDFileInfo finfo;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000B4
 */
void Jac_LoadFile(immut char*, u8*)
{
	static DVDFileInfo finfo;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
void DVDT_Pause()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000038
 */
void DVDT_UnPause()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void Jac_RegisterDVDErrorCallback(void (*)(immut char*, u8*))
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
s32 Jac_RegisterExtFastOpen(immut char* ext)
{
	char file[64];
	DVDT_ExtendPath(file, ext);
	Jac_RegisterFastOpen(file);
}

static u32 dvdfile_dics;
static char dvd_file[32][64];
static u32 dvd_entrynum[32];

/**
 * @TODO: Documentation
 */
s32 Jac_RegisterFastOpen(immut char* file)
{
	volatile int num;
	immut char** REF_file = &file;
	STACK_PAD_VAR(3);
	if (strlen(file) > 63) {
		return -1;
	}

	int i;
	for (i = 0; i < dvdfile_dics; i++) {
		if (!strcmp(dvd_file[i], file)) {
			return dvd_entrynum[i];
		}
	}
	if (dvdfile_dics == 32) {
		return -1;
	}

	num = DVDConvertPathToEntrynum(file);

	if (num != -1) {
		strcpy(dvd_file[dvdfile_dics], file);
		dvd_entrynum[dvdfile_dics] = num;
		dvdfile_dics++;
	}
	return num;
}

/**
 * @TODO: Documentation
 */
BOOL Jac_DVDOpen(immut char* name, DVDFileInfo* info)
{
	int entry = Jac_RegisterFastOpen(name);

	if (entry == -1) {
		return DVDOpen(name, info);
	} else {
		return DVDFastOpen(entry, info);
	}
}
