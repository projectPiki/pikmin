#include "jaudio/virload.h"

#include "jaudio/aictrl.h"
#include "jaudio/dvdthread.h"

#include <stddef.h>
#include <string.h>

#define JV_DIR_NAME_LENGTH (16)
static char JV_DIR_NAME[JV_DIR_NAME_LENGTH][64];

#define JV_ARC_NAME_LENGTH (16)
static char JV_ARC_NAME[JV_ARC_NAME_LENGTH][32];

#define JV_ARC_LENGTH ()
static Barc* JV_ARC[16]; // Pointers to BARC metadata (*.hed). In practice, just the first element points to pikiseq.hed.

static u32 JV_CURRENT_ARCS = 0; // TODO: type unknown, init unclear

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
void JV_InitHeader(immut char* fileName)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 */
BOOL JV_InitHeader_M(immut char* fileName, u8* barcData, u8* archiveWork)
{
	STACK_PAD_VAR(1);
	immut char** REF_fileName = &fileName;
	if (!barcData) {
		// if no barc data, read from disk
		u32 fileSize = DVDT_CheckFile(fileName);
		if (fileSize == FALSE) {
			return FALSE;
		}

		barcData = (u8*)OSAlloc2(fileSize);
		if (!barcData) {
			return FALSE;
		}

		u32 loadStatus = DVDT_LoadFile(fileName, barcData);
		if (loadStatus == FALSE) {
			return FALSE;
		}
	}

	u32 dirSeparatorIndex = strlen(fileName) - 1;

	for (dirSeparatorIndex; dirSeparatorIndex > 0; dirSeparatorIndex--) {
		if (fileName[dirSeparatorIndex] == '/') {
			break;
		}
	}

	if (dirSeparatorIndex == 0) {
		strcpy(JV_DIR_NAME[JV_CURRENT_ARCS], "/");
	} else {
		strncpy(JV_DIR_NAME[JV_CURRENT_ARCS], fileName, dirSeparatorIndex);
	}

	strcpy(JV_ARC_NAME[JV_CURRENT_ARCS], &fileName[dirSeparatorIndex + 1]);

	JV_ARC[JV_CURRENT_ARCS]           = (Barc*)barcData;
	JV_ARC[JV_CURRENT_ARCS]->meta._04 = (u32)archiveWork;

	JV_CURRENT_ARCS++;
	return TRUE;
}

/**
 * @TODO: Documentation
 */
u32 JV_GetArchiveHandle(immut char* archiveName)
{
	u32 archiveIndex;

	for (archiveIndex = 0; archiveIndex < JV_CURRENT_ARCS; ++archiveIndex) {
		if (!strcmp(archiveName, JV_ARC_NAME[archiveIndex])) {
			break;
		}
	}
	if (archiveIndex != JV_CURRENT_ARCS) {
		return archiveIndex * 0x10000;
	}
	return -1;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000E8
 */
void JV_GetLogicalHandleS(immut char* dirName, immut char* fileName)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000154
 */
void JV_GetLogicalHandle(immut char* logicalPath)
{
	TRAP_UNIMPLEMENTED;
	// idk where this is meant to be, but it's static and in a function.
	static DVDFileInfo finfo;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000064
 */
void JV_GetHandle(u32 handle)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 */
BarcEntry* JV_GetRealHandle(u32 handle)
{
	u32 unusedIndex;
	Barc* archiveHeader;
	u16 arcIdx;
	u16 seqIdx;

	seqIdx = (handle & 0x0000ffff);
	arcIdx = (handle & 0xffff0000) >> 16;

	if (arcIdx >= JV_CURRENT_ARCS) {
		return 0;
	}
	archiveHeader = JV_ARC[arcIdx];
	if (!archiveHeader) {
		return NULL;
	}
	if (seqIdx >= archiveHeader->meta.seqCount) {
		return NULL;
	}

	BarcEntry* entry = (&archiveHeader[seqIdx].entry) + 1; // skip header i guess?
	while (entry->isDummy != 0xFFFF) {
		// skip through any dummy tracks until we hit a real one (isDummy == 0xFFFF for real tracks)
		entry = (&archiveHeader[entry->isDummy].entry) + 1;
	}

	return entry;
}

/**
 * @TODO: Documentation
 */
u32 JV_CheckSize(u32 handle)
{
	BarcEntry* entry;

	entry = JV_GetRealHandle(handle);
	if (!entry)
		return 0;
	return entry->size;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004 (Matching by size)
 */
void __JV_Callback(u32 callbackArg)
{
}

/**
 * @TODO: Documentation
 */
u32 JV_LoadFile(u32 handle, u8* dst, u32 offset, u32 length)
{
	BarcEntry* unusedEntry;
	u32 sourceOffset;
	char path[128];
	volatile u32 loadStatus;

	u32* REF_handle = &handle;
	u8** REF_dst    = &dst;
	u32* REF_length = &length;

	u32 archiveIndex = handle >> 16;
	loadStatus      = 0;

	sourceOffset = JV_GetRealHandle(handle)->offset;
	sourceOffset += offset;
	u32* REF_src = &sourceOffset;

	strcpy(path, JV_DIR_NAME[archiveIndex]);
	strcat(path, "/");
	strcat(path, JV_ARC[archiveIndex]->meta.arcName);
	DVDT_LoadtoDRAM(0, path, (u32)dst, sourceOffset, length, (u32*)&loadStatus, NULL);

	while (loadStatus == 0) {
		;
	}

	STACK_PAD_VAR(2);
	return loadStatus;
}

/**
 * @TODO: Documentation
 */
u32 JV_LoadFile_Async2(u32 handle, u8* dst, u32 offset, u32 length, void (*callback)(u32), u32 owner)
{
	static u32 isFirstCall = TRUE;
	STACK_PAD_VAR(1);
	u32 archiveIndex;
	u32 sourceOffset;
	char path[128];
	u32* REF_handle = &handle;
	u8** REF_dst    = &dst;
	u32* REF_length = &length;
	STACK_PAD_VAR(3);

	archiveIndex = handle >> 16;
	sourceOffset = JV_GetRealHandle(handle)->offset;
	sourceOffset += offset;
	u32* REF_src = &sourceOffset;

	strcpy(path, JV_DIR_NAME[archiveIndex]);
	strcat(path, "/");
	strcat(path, JV_ARC[archiveIndex]->meta.arcName);

	DVDT_LoadtoDRAM(owner, path, (u32)dst, sourceOffset, length, NULL, callback);
	return length;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
void JV_GetMemoryFile(u32 handle)
{
	TRAP_UNIMPLEMENTED;
}
