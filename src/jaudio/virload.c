#include "jaudio/virload.h"

#include "jaudio/dvdthread.h"
#include "jaudio/aictrl.h"

#include "stl/string.h"

#define JV_DIR_NAME_LENGTH (16)
static char JV_DIR_NAME[JV_DIR_NAME_LENGTH][64];

#define JV_ARC_NAME_LENGTH (16)
static char JV_ARC_NAME[JV_ARC_NAME_LENGTH][32];

#define JV_ARC_LENGTH ()
static Barc* JV_ARC[16]; // Pointers to BARC metadata (*.hed). In practice, just the first element points to pikiseq.hed.

static u32 JV_CURRENT_ARCS = 0; // TODO: type unknown, init unclear

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void JV_InitHeader(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E580
 * Size:	000138
 */
BOOL JV_InitHeader_M(char* fileName, u8* barcData, u8* p3)
{
	STACK_PAD_VAR(1);
	char** REF_p1 = &fileName;
	if (!barcData) {
		// if no barc data, read from disk
		u32 size = DVDT_CheckFile(fileName);
		if (size == FALSE) {
			return FALSE;
		}

		barcData = (u8*)OSAlloc2(size);
		if (!barcData) {
			return FALSE;
		}

		u32 loadState = DVDT_LoadFile(fileName, barcData);
		if (loadState == FALSE) {
			return FALSE;
		}
	}

	u32 len = strlen(fileName) - 1;

	for (len; len > 0; len--) {
		if (fileName[len] == '/') {
			break;
		}
	}

	if (len == 0) {
		strcpy(JV_DIR_NAME[JV_CURRENT_ARCS], "/");
	} else {
		strncpy(JV_DIR_NAME[JV_CURRENT_ARCS], fileName, len);
	}

	strcpy(JV_ARC_NAME[JV_CURRENT_ARCS], &fileName[len + 1]);

	JV_ARC[JV_CURRENT_ARCS]           = (Barc*)barcData;
	JV_ARC[JV_CURRENT_ARCS]->meta._04 = (u32)p3;

	JV_CURRENT_ARCS++;
	return TRUE;
}

/*
 * --INFO--
 * Address:	8000E6C0
 * Size:	00007C
 */
u32 JV_GetArchiveHandle(char* name)
{
	u32 i;

	for (i = 0; i < JV_CURRENT_ARCS; ++i) {
		if (!strcmp(name, JV_ARC_NAME[i])) {
			break;
		}
	}
	if (i != JV_CURRENT_ARCS) {
		return i * 0x10000;
	}
	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void JV_GetLogicalHandleS(char*, char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000154
 */
void JV_GetLogicalHandle(char*)
{
	// idk what this is or where it's meant to be, but it's static, size 0x3C, and in a function.
	static struct {
		u8 pad[0x3C];
	} finfo;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void JV_GetHandle(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E740
 * Size:	000080
 */
BarcEntry* JV_GetRealHandle(u32 handle)
{
	u32 i;
	Barc* hed;
	u16 arcIdx;
	u16 seqIdx;

	seqIdx = (handle & 0x0000ffff);
	arcIdx = (handle & 0xffff0000) >> 16;

	if (arcIdx >= JV_CURRENT_ARCS) {
		return 0;
	}
	hed = JV_ARC[arcIdx];
	if (!hed) {
		return NULL;
	}
	if (seqIdx >= hed->meta.seqCount) {
		return NULL;
	}

	BarcEntry* entry = (&hed[seqIdx].entry) + 1; // skip header i guess?
	while (entry->isDummy != 0xFFFF) {
		// skip through any dummy tracks until we hit a real one (isDummy == 0xFFFF for real tracks)
		entry = (&hed[entry->isDummy].entry) + 1;
	}

	return entry;
}

/*
 * --INFO--
 * Address:	8000E7C0
 * Size:	000034
 */
u32 JV_CheckSize(u32 handle)
{
	BarcEntry* entry;

	entry = JV_GetRealHandle(handle);
	if (!entry)
		return 0;
	return entry->size;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void __JV_Callback(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E800
 * Size:	0000D0
 */
u32 JV_LoadFile(u32 handle, u8* dst, u32 param_3, u32 length)
{
	BarcEntry* entry;
	u32 src;
	char name[128];
	volatile u32 status;

	u32* REF_handle = &handle;
	u8** REF_dst    = &dst;
	u32* REF_length = &length;

	u32 idx = handle >> 16;
	status  = 0;

	src = JV_GetRealHandle(handle)->offset;
	src += param_3;
	u32* REF_src = &src;

	strcpy(name, JV_DIR_NAME[idx]);
	strcat(name, "/");
	strcat(name, JV_ARC[idx]->meta.arcName);
	DVDT_LoadtoDRAM(0, name, (u32)dst, src, length, &status, NULL);

	while (status == 0) {
		;
	}

	STACK_PAD_VAR(2);
	return status;
}

/*
 * --INFO--
 * Address:	8000E8E0
 * Size:	0000E0
 */
u32 JV_LoadFile_Async2(u32 handle, u8* dst, u32 p3, u32 length, void (*callback)(u32), u32 owner)
{
	static u32 first = TRUE;
	STACK_PAD_VAR(1);
	u32 idx;
	u32 src;
	char name[128];
	u32* REF_handle = &handle;
	u8** REF_dst    = &dst;
	u32* REF_length = &length;
	u32 badCompile2[3];

	idx = handle >> 16;
	src = JV_GetRealHandle(handle)->offset;
	src += p3;
	u32* REF_src = &src;

	strcpy(name, JV_DIR_NAME[idx]);
	strcat(name, "/");
	strcat(name, JV_ARC[idx]->meta.arcName);

	DVDT_LoadtoDRAM(owner, name, (u32)dst, src, length, NULL, callback);
	return length;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void JV_GetMemoryFile(u32)
{
	// UNUSED FUNCTION
}
