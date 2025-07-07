#include "jaudio/dvdthread.h"
#include "Dolphin/ar.h"
#include "Dolphin/os.h"
#include "jaudio/aictrl.h"
#include "jaudio/sample.h"
#include "stl/string.h"

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

/*
 * --INFO--
 * Address:	800073E0
 * Size:	000060
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

/*
 * --INFO--
 * Address:	80007440
 * Size:	00008C
 */
static s32 DVDReadMutex(DVDFileInfo* fileInfo, void* addr, s32 len, s32 offs, char* errorArg)
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

/*
 * --INFO--
 * Address:	800074E0
 * Size:	00004C
 */
void DVDT_SetRootPath(char* path)
{
	// don't ask.
	char** pPath = &path;
	char* p      = *pPath;
	if (strlen(p) < 31) {
		strcpy(audio_root_path, p);
	}
}

/*
 * --INFO--
 * Address:	80007540
 * Size:	000080
 */
void DVDT_ExtendPath(char* dst, char* ext)
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

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
s32 DVDT_AddTaskHigh(TaskCallback, void*, size_t)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800075C0
 * Size:	00007C
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

/*
 * --INFO--
 * Address:	80007640
 * Size:	00003C
 */
void jac_dvdproc_init()
{
	OSInitMessageQueue(&mq, (OSMessage*)msgbuf, ARRAY_SIZE(msgbuf));
	mq_init = 1;
}

/*
 * --INFO--
 * Address:	80007680
 * Size:	000088
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

/*
 * --INFO--
 * Address:	80007720
 * Size:	000048
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

/*
 * --INFO--
 * Address:	80007780
 * Size:	000044
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

/*
 * --INFO--
 * Address:	800077E0
 * Size:	000024
 */
static void __DVDT_CheckBack(void* cb)
{
	DVDCall* callback = (DVDCall*)cb;

	__DoFinish(callback, callback->owner);
}

/*
 * --INFO--
 * Address:	80007820
 * Size:	0000D0
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

/*
 * --INFO--
 * Address:	80007900
 * Size:	000084
 */
s32 DVDT_LoadtoDRAM(u32 owner, char* name, u32 dst, u32 src, u32 length, u32* status, Jac_DVDCallback callback)
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

/*
 * --INFO--
 * Address:	800079A0
 * Size:	000038
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

/*
 * --INFO--
 * Address:	800079E0
 * Size:	000030
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

/*
 * --INFO--
 * Address:	80007A20
 * Size:	000040
 */
static void __UpdateBuffer()
{
	if (next_buffers != 0) {
		__WriteBufferSize(next_buffertop, next_buffers, next_buffersize);
		next_buffers   = 0;
		next_buffertop = NULL;
	}
}

/*
 * --INFO--
 * Address:	80007A60
 * Size:	000058
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

/*
 * --INFO--
 * Address:	80007AC0
 * Size:	0000BC
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

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void DVDT_GetCurrentBuffer(u8**)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80007B80
 * Size:	000010
 */
static void ARAM_DMAfinish(u32)
{
	buffer_full--;
}

/*
 * --INFO--
 * Address:	80007BA0
 * Size:	00022C
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

/*
 * --INFO--
 * Address:	80007DE0
 * Size:	000084
 */
s32 DVDT_LoadtoARAM(u32 owner, char* path, u32 dst, u32 src, u32 length, u32* status, Jac_DVDCallback callback)
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

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void ARAM_DMAfinish2(u32)
{
	static DVDFileInfo finfo;
	static ARQRequest req;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void DVDT_ARAMtoDRAM_Main(void*)
{
	static DVDFileInfo finfo;
	static ARQRequest req;

	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void DVDT_DRAMtoARAM_Main(void*)
{
	// static DVDFileInfo finfo;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void DVDT_ARAMtoDRAM(u32, u32, u32, u32, u32*, void (*)(u32))
{
	// static DVDFileInfo finfo;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void DVDT_DRAMtoARAM(u32, u32, u32, u32, u32*, void (*)(u32))
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80007E80
 * Size:	000070
 */
s32 DVDT_CheckFile(char* file)
{
	char path[64];
	char** pFile = &file;
	char* f      = *pFile;
	static DVDFileInfo finfo;

	DVDT_ExtendPath(path, f);

	if (!Jac_DVDOpen(path, &finfo)) {
		return 0;
	}
	u32 len = finfo.length;

	DVDClose(&finfo);
	return len;
}

/*
 * --INFO--
 * Address:	80007F00
 * Size:	000070
 */
s32 DVDT_LoadFile(char* file, u8* p2)
{
	char** pFile = &file;
	vu32 status  = 0;
	STACK_PAD_VAR(3);
	DVDT_LoadtoDRAM(0, *pFile, (u32)p2, 0, 0, &status, NULL);

	while (status == 0) { }

	if (status == -1) {
		return 0;
	}

	return status;
}

/*
 * --INFO--
 * Address:	80007F80
 * Size:	000040
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

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void Jac_CheckFile(char*)
{
	static DVDFileInfo finfo;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void Jac_LoadFile(char*, u8*)
{
	static DVDFileInfo finfo;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void DVDT_Pause()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void DVDT_UnPause()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Jac_RegisterDVDErrorCallback(void (*)(char*, u8*))
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80007FC0
 * Size:	000030
 */
s32 Jac_RegisterExtFastOpen(char* ext)
{
	char file[64];
	DVDT_ExtendPath(file, ext);
	Jac_RegisterFastOpen(file);
}

static u32 dvdfile_dics;
static char dvd_file[32][64];
static u32 dvd_entrynum[32];

/*
 * --INFO--
 * Address:	80008000
 * Size:	000100
 */
s32 Jac_RegisterFastOpen(char* file)
{
	volatile int num;
	char** pFile = &file;
	char* f      = *pFile;
	STACK_PAD_VAR(3);
	if (strlen(f) > 63) {
		return -1;
	}

	int i;
	for (i = 0; i < dvdfile_dics; i++) {
		if (!strcmp(dvd_file[i], f)) {
			return dvd_entrynum[i];
		}
	}
	if (dvdfile_dics == 32) {
		return -1;
	}

	num = DVDConvertPathToEntrynum(f);

	if (num != -1) {
		strcpy(dvd_file[dvdfile_dics], f);
		dvd_entrynum[dvdfile_dics] = num;
		dvdfile_dics++;
	}
	return num;
}

/*
 * --INFO--
 * Address:	80008100
 * Size:	000050
 */
BOOL Jac_DVDOpen(char* name, DVDFileInfo* info)
{
	int entry = Jac_RegisterFastOpen(name);

	if (entry == -1) {
		return DVDOpen(name, info);
	} else {
		return DVDFastOpen(entry, info);
	}
}
