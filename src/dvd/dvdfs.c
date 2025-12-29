#include "Dolphin/dvd.h"
#include "Dolphin/os.h"

typedef struct FSTEntry FSTEntry;

struct FSTEntry {
	uint isDirAndStringOff;
	uint parentOrPosition;
	uint nextEntryOrLength;
};

static OSBootInfo* BootInfo;
static FSTEntry* FstStart;
static char* FstStringStart;
static u32 MaxEntryNum;
static u32 currentDirectory = 0;
OSThreadQueue __DVDThreadQueue;
u32 __DVDLongFileNameFlag = 0;

static void cbForReadAsync(s32 result, DVDCommandBlock* block);
static void cbForReadSync(s32 result, DVDCommandBlock* block);
static void cbForSeekAsync(s32 result, DVDCommandBlock* block);
static void cbForSeekSync(s32 result, DVDCommandBlock* block);
static void cbForPrepareStreamAsync(s32 result, DVDCommandBlock* block);
static void cbForPrepareStreamSync(s32 result, DVDCommandBlock* block);

#ifndef offsetof
#define offsetof(type, memb) ((u32) & ((type*)0)->memb)
#endif

/**
 * @TODO: Documentation
 */
void __DVDFSInit()
{
	BootInfo = (OSBootInfo*)OSPhysicalToCached(0);
	FstStart = (FSTEntry*)BootInfo->FSTLocation;

	if (FstStart) {
		MaxEntryNum    = FstStart[0].nextEntryOrLength;
		FstStringStart = (char*)&(FstStart[MaxEntryNum]);
	}
}

/* For convenience */
#define entryIsDir(i)   (((FstStart[i].isDirAndStringOff & 0xff000000) == 0) ? FALSE : TRUE)
#define stringOff(i)    (FstStart[i].isDirAndStringOff & ~0xff000000)
#define parentDir(i)    (FstStart[i].parentOrPosition)
#define nextDir(i)      (FstStart[i].nextEntryOrLength)
#define filePosition(i) (FstStart[i].parentOrPosition)
#define fileLength(i)   (FstStart[i].nextEntryOrLength)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
static BOOL isSame(const char* path, const char* string)
{
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	while (*string != '\0') {
		if (tolower(*path++) != tolower(*string++)) {
			return FALSE;
		}
	}

	if ((*path == '/') || (*path == '\0')) {
		return TRUE;
	}
#else
	while ((u8)*string != '\0') {
		if (tolower((u8)*path++) != tolower((u8)*string++)) {
			return FALSE;
		}
	}

	if (((u8)*path == '/') || ((u8)*path == '\0')) {
		return TRUE;
	}
#endif
	return FALSE;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
s32 DVDConvertPathToEntrynum(const char* pathPtr)
{
	const char* ptr;
	char* stringPtr;
	BOOL isDir;
	u32 length;
	u32 dirLookAt;
	u32 i;
	const char* origPathPtr = pathPtr;
	const char* extentionStart;
	BOOL illegal;
	BOOL extention;

	dirLookAt = currentDirectory;

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	while (1) {
		if (*pathPtr == '\0') {
			return (s32)dirLookAt;
		} else if (*pathPtr == '/') {
			dirLookAt = 0;
			pathPtr++;
			continue;
		} else if (*pathPtr == '.') {
			if (*(pathPtr + 1) == '.') {
				if (*(pathPtr + 2) == '/') {
					dirLookAt = parentDir(dirLookAt);
					pathPtr += 3;
					continue;
				} else if (*(pathPtr + 2) == '\0') {
					return (s32)parentDir(dirLookAt);
				}
			} else if (*(pathPtr + 1) == '/') {
				pathPtr += 2;
				continue;
			} else if (*(pathPtr + 1) == '\0') {
				return (s32)dirLookAt;
			}
		}

		if (__DVDLongFileNameFlag == 0) {
			extention = FALSE;
			illegal   = FALSE;

			for (ptr = pathPtr; (*ptr != '\0') && (*ptr != '/'); ptr++) {
				if (*ptr == '.') {
					if ((ptr - pathPtr > 8) || (extention == TRUE)) {
						illegal = TRUE;
						break;
					}
					extention      = TRUE;
					extentionStart = ptr + 1;

				} else if (*ptr == ' ') {
					illegal = TRUE;
				}
			}

			if ((extention == TRUE) && (ptr - extentionStart > 3)) {
				illegal = TRUE;
			}

			if (illegal) {
				OSPanic(__FILE__, 376,
				        "DVDConvertEntrynumToPath(possibly DVDOpen or "
				        "DVDChangeDir or DVDOpenDir): "
				        "specified directory or file (%s) doesn't match "
				        "standard 8.3 format. This is a "
				        "temporary restriction and will be removed soon\n",
				        origPathPtr);
			}
		} else {
			for (ptr = pathPtr; (*ptr != '\0') && (*ptr != '/'); ptr++)
				;
		}

		isDir  = (*ptr == '\0') ? FALSE : TRUE;
		length = (u32)(ptr - pathPtr);

		ptr = pathPtr;

		for (i = dirLookAt + 1; i < nextDir(dirLookAt); i = entryIsDir(i) ? nextDir(i) : (i + 1)) {
			if ((entryIsDir(i) == FALSE) && (isDir == TRUE)) {
				continue;
			}

			stringPtr = FstStringStart + stringOff(i);

			if (isSame(ptr, stringPtr) == TRUE) {
				goto next_hier;
			}
		}

		return -1;

	next_hier:
		if (!isDir) {
			return (s32)i;
		}

		dirLookAt = i;
		pathPtr += length + 1;
	}
#else
	while (1) {
		if ((u8)*pathPtr == '\0') {
			return (s32)dirLookAt;
		} else if ((u8)*pathPtr == '/') {
			dirLookAt = 0;
			pathPtr++;
			continue;
		} else if ((u8)*pathPtr == '.') {
			if ((u8) * (pathPtr + 1) == '.') {
				if ((u8) * (pathPtr + 2) == '/') {
					dirLookAt = parentDir(dirLookAt);
					pathPtr += 3;
					continue;
				} else if ((u8) * (pathPtr + 2) == '\0') {
					return (s32)parentDir(dirLookAt);
				}
			} else if ((u8) * (pathPtr + 1) == '/') {
				pathPtr += 2;
				continue;
			} else if ((u8) * (pathPtr + 1) == '\0') {
				return (s32)dirLookAt;
			}
		}

		if (__DVDLongFileNameFlag == 0) {
			extention = FALSE;
			illegal   = FALSE;

			for (ptr = pathPtr; ((u8)*ptr != '\0') && ((u8)*ptr != '/'); ptr++) {
				if ((u8)*ptr == '.') {
					if ((ptr - pathPtr > 8) || (extention == TRUE)) {
						illegal = TRUE;
						break;
					}
					extention      = TRUE;
					extentionStart = ptr + 1;

				} else if ((u8)*ptr == ' ')
					illegal = TRUE;
			}

			if ((extention == TRUE) && (ptr - extentionStart > 3))
				illegal = TRUE;

			if (illegal)
				OSErrorLine(373,
				            "DVDConvertEntrynumToPath(possibly DVDOpen or DVDChangeDir or DVDOpenDir): "
				            "specified directory or file (%s) doesn't match standard 8.3 format. This is a "
				            "temporary restriction and will be removed soon\n",
				            origPathPtr);
		} else {
			for (ptr = pathPtr; ((u8)*ptr != '\0') && ((u8)*ptr != '/'); ptr++)
				;
		}

		isDir  = ((u8)*ptr == '\0') ? FALSE : TRUE;
		length = (u32)(ptr - pathPtr);

		ptr = pathPtr;

		for (i = dirLookAt + 1; i < nextDir(dirLookAt); i = entryIsDir(i) ? nextDir(i) : (i + 1)) {
			if ((entryIsDir(i) == FALSE) && (isDir == TRUE)) {
				continue;
			}

			stringPtr = FstStringStart + stringOff(i);

			if (isSame(ptr, stringPtr) == TRUE) {
				goto next_hier;
			}
		}

		return -1;

	next_hier:
		if (!isDir) {
			return (s32)i;
		}

		dirLookAt = i;
		pathPtr += length + 1;
	}
#endif
}

/**
 * @TODO: Documentation
 */
BOOL DVDFastOpen(s32 entrynum, DVDFileInfo* fileInfo)
{
	if ((entrynum < 0) || (entrynum >= MaxEntryNum) || entryIsDir(entrynum)) {
		return FALSE;
	}

	fileInfo->startAddr    = filePosition(entrynum);
	fileInfo->length       = fileLength(entrynum);
	fileInfo->callback     = (DVDCallback)NULL;
	fileInfo->cBlock.state = DVD_STATE_END;

	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL DVDOpen(const char* fileName, DVDFileInfo* fileInfo)
{
	s32 entry;
	char currentDir[128];

	entry = DVDConvertPathToEntrynum(fileName);

	if (0 > entry) {
		DVDGetCurrentDir(currentDir, sizeof(currentDir));
		OSReport("Warning: DVDOpen(): file '%s' was not found under %s.\n", fileName, currentDir);
		return FALSE;
	}

	if (entryIsDir(entry)) {
		return FALSE;
	}

	fileInfo->startAddr    = filePosition(entry);
	fileInfo->length       = fileLength(entry);
	fileInfo->callback     = (DVDCallback)NULL;
	fileInfo->cBlock.state = DVD_STATE_END;

	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL DVDClose(DVDFileInfo* fileInfo)
{
	DVDCancel(&(fileInfo->cBlock));
	return TRUE;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000038
 */
static u32 myStrncpy(char* dest, const char* src, u32 maxlen)
{
	u32 i = maxlen;

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	while ((i > 0) && (*src != 0)) {
#else
	while ((i > 0) && ((u8)*src != 0)) {
#endif
		*dest++ = *src++;
		i--;
	}

	return (maxlen - i);
}

/**
 * @TODO: Documentation
 */
static u32 entryToPath(u32 entry, char* path, u32 maxlen)
{
	char* name;
	u32 loc;

	if (entry == 0) {
		return 0;
	}

	name = FstStringStart + stringOff(entry);

	loc = entryToPath(parentDir(entry), path, maxlen);

	if (loc == maxlen) {
		return loc;
	}

	*(path + loc++) = '/';

	loc += myStrncpy(path + loc, name, maxlen - loc);

	return loc;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000154
 */
static BOOL DVDConvertEntrynumToPath(s32 entrynum, char* path, u32 maxlen)
{
	u32 loc;

	loc = entryToPath((u32)entrynum, path, maxlen);

	if (loc == maxlen) {
		path[maxlen - 1] = '\0';
		return FALSE;
	}

	if (entryIsDir(entrynum)) {
		if (loc == maxlen - 1) {
			path[loc] = '\0';
			return FALSE;
		}

		path[loc++] = '/';
	}

	path[loc] = '\0';
	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL DVDGetCurrentDir(char* path, u32 maxlen)
{
	return DVDConvertEntrynumToPath((s32)currentDirectory, path, maxlen);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000060
 */
BOOL DVDChangeDir(const char* dirName)
{
	s32 entry;
	entry = DVDConvertPathToEntrynum(dirName);
	if ((entry < 0) || (entryIsDir(entry) == FALSE)) {
		return FALSE;
	}

	currentDirectory = (u32)entry;

	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL DVDReadAsyncPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, DVDCallback callback, s32 prio)
{
	if (!((0 <= offset) && (offset < fileInfo->length))) {
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		OSErrorLine(739, "DVDReadAsync(): specified area is out of the file  ");
#else
		OSErrorLine(735, "DVDReadAsync(): specified area is out of the file  ");
#endif
	}

	if (!((0 <= offset + length) && (offset + length < fileInfo->length + DVD_MIN_TRANSFER_SIZE))) {
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		OSErrorLine(745, "DVDReadAsync(): specified area is out of the file  ");
#else
		OSErrorLine(741, "DVDReadAsync(): specified area is out of the file  ");
#endif
	}

	fileInfo->callback = callback;
	DVDReadAbsAsyncPrio(&(fileInfo->cBlock), addr, length, (s32)(fileInfo->startAddr + offset), cbForReadAsync, prio);

	return TRUE;
}

/**
 * @TODO: Documentation
 */
static void cbForReadAsync(s32 result, DVDCommandBlock* block)
{
	DVDFileInfo* fileInfo;

	fileInfo = (DVDFileInfo*)((char*)block - offsetof(DVDFileInfo, cBlock));
	if (fileInfo->callback) {
		(fileInfo->callback)(result, fileInfo);
	}
}

/**
 * @TODO: Documentation
 */
s32 DVDReadPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, s32 prio)
{
	BOOL result;
	DVDCommandBlock* block;
	s32 state;
	BOOL enabled;
	s32 retVal;

	if (!((0 <= offset) && (offset < fileInfo->length))) {
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		OSErrorLine(809, "DVDRead(): specified area is out of the file  ");
#else
		OSErrorLine(805, "DVDRead(): specified area is out of the file  ");
#endif
	}

	if (!((0 <= offset + length) && (offset + length < fileInfo->length + DVD_MIN_TRANSFER_SIZE))) {
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		OSErrorLine(815, "DVDRead(): specified area is out of the file  ");
#else
		OSErrorLine(811, "DVDRead(): specified area is out of the file  ");
#endif
	}

	block = &(fileInfo->cBlock);

	result = DVDReadAbsAsyncPrio(block, addr, length, (s32)(fileInfo->startAddr + offset), cbForReadSync, prio);

	if (result == FALSE) {
		return -1;
	}

	enabled = OSDisableInterrupts();

	while (TRUE) {
		state = ((volatile DVDCommandBlock*)block)->state;

		if (state == DVD_STATE_END) {
			retVal = (s32)block->transferredSize;
			break;
		}
		if (state == DVD_STATE_FATAL_ERROR) {
			retVal = DVD_RESULT_FATAL_ERROR;
			break;
		}
		if (state == DVD_STATE_CANCELED) {
			retVal = DVD_RESULT_CANCELED;
			break;
		}

		OSSleepThread(&__DVDThreadQueue);
	}

	OSRestoreInterrupts(enabled);
	return retVal;
}

/**
 * @TODO: Documentation
 */
void cbForReadSync(s32 result, DVDCommandBlock* block)
{
	OSWakeupThread(&__DVDThreadQueue);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000098
 */
BOOL DVDSeekAsyncPrio(DVDFileInfo* fileInfo, s32 offset, DVDCallback callback, s32 prio)
{
	if (!((0 <= offset) && (offset < fileInfo->length))) {
		OSErrorLine(881, "DVDSeek(): offset is out of the file  ");
	}

	fileInfo->callback = callback;
	DVDSeekAbsAsyncPrio(&fileInfo->cBlock, (u32)(char*)fileInfo->startAddr + offset, cbForSeekAsync, prio);
	return TRUE;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
void cbForSeekAsync(s32 result, DVDCommandBlock* block)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000AC
 */
s32 DVDSeekPrio(DVDFileInfo* fileInfo, s32 offset, s32 prio)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void cbForSeekSync(s32 result, DVDCommandBlock* block)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000020
 */
s32 DVDGetFileInfoStatus(DVDFileInfo* fileInfo)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000084
 */
BOOL DVDOpenDir(const char* dirName, DVDDir* dir)
{
	// something is making this function in particular compile this warning string in demo, this probably isnt right but it gets the job
	// done
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)

	long entry;
	char currentDir[128];

	entry = DVDConvertPathToEntrynum(dirName);
	if (entry <= 0)
		OSErrorLine(0x409, "Warning: DVDOpenDir(): file '%s' was not found under %s.\n", dirName,
		            (DVDGetCurrentDir(currentDir, 128), currentDir));
	if (entry < 0 || !entryIsDir(entry)) {
		return 0;
	}
	dir->entryNum = entry;
	dir->location = entry + 1;
	dir->next     = nextDir(entry);
	return 1;
#endif
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000A4
 */
BOOL DVDReadDir(DVDDir* dir, DVDDirEntry* dirent)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
BOOL DVDCloseDir(DVDDir* dir)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
void* DVDGetFSTLocation()
{
	// UNUSED FUNCTION
}

#define RoundUp32KB(x)   (((u32)(x) + 32 * 1024 - 1) & ~(32 * 1024 - 1))
#define Is32KBAligned(x) (((u32)(x) & (32 * 1024 - 1)) == 0)

/**
 * @TODO: Documentation
 */
BOOL DVDPrepareStreamAsync(DVDFileInfo* fileInfo, u32 length, u32 offset, DVDCallback callback)
{
	u32 start;

	start = fileInfo->startAddr + offset;

	if (!Is32KBAligned(start)) {
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		OSErrorLine(1186,
		            "DVDPrepareStreamAsync(): Specified start address (filestart(0x%x) + offset(0x%x)) is "
		            "not 32KB aligned",
		            fileInfo->startAddr, offset);
#else
		OSErrorLine(1150,
		            "DVDPrepareStreamAsync(): Specified start address (filestart(0x%x) + offset(0x%x)) is "
		            "not 32KB aligned",
		            fileInfo->startAddr, offset);
#endif
	}

	if (length == 0)
		length = fileInfo->length - offset;

	if (!Is32KBAligned(length)) {
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		OSErrorLine(1196, "DVDPrepareStreamAsync(): Specified length (0x%x) is not a multiple of 32768(32*1024)", length);
#else
		OSErrorLine(1160, "DVDPrepareStreamAsync(): Specified length (0x%x) is not a multiple of 32768(32*1024)", length);
#endif
	}

	if (!((offset < fileInfo->length) && (offset + length <= fileInfo->length))) {

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		OSErrorLine(1204,
		            "DVDPrepareStreamAsync(): The area specified (offset(0x%x), length(0x%x)) is out of "
		            "the file",
		            offset, length);
#else
		OSErrorLine(1168,
		            "DVDPrepareStreamAsync(): The area specified (offset(0x%x), length(0x%x)) is out of "
		            "the file",
		            offset, length);
#endif
	}

	fileInfo->callback = callback;
	return DVDPrepareStreamAbsAsync(&(fileInfo->cBlock), length, fileInfo->startAddr + offset, cbForPrepareStreamAsync);
}

/**
 * @TODO: Documentation
 */
void cbForPrepareStreamAsync(s32 result, DVDCommandBlock* block)
{
	struct DVDFileInfo* fileInfo;

	fileInfo = (struct DVDFileInfo*)&block->next;
	if (fileInfo->callback) {
		(fileInfo->callback)(result, fileInfo);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000144
 */
s32 DVDPrepareStream(DVDFileInfo* fileInfo, u32 length, u32 offset)
{
	BOOL result;
	DVDCommandBlock* block;
	s32 state;
	BOOL enabled;
	s32 retVal;
	u32 start;

	start = fileInfo->startAddr + offset;

	if (!Is32KBAligned(start)) {
		OSErrorLine(0x4BF,
		            "DVDPrepareStream(): Specified start address (filestart(0x%x) + offset(0x%x)) is not "
		            "32KB aligned",
		            fileInfo->startAddr, offset);
	}

	if (length == 0)
		length = fileInfo->length - offset;

	if (!Is32KBAligned(length)) {
		OSErrorLine(0x4C9, "DVDPrepareStream(): Specified length (0x%x) is not a multiple of 32768(32*1024)", length);
	}

	if (!((offset < fileInfo->length) && (offset + length <= fileInfo->length))) {
		OSErrorLine(0x4D1, "DVDPrepareStream(): The area specified (offset(0x%x), length(0x%x)) is out of the file", offset, length);
	}

	block  = &(fileInfo->cBlock);
	result = DVDPrepareStreamAbsAsync(block, length, start, cbForPrepareStreamSync);

	if (result == FALSE) {
		return -1;
	}

	enabled = OSDisableInterrupts();

	while (1) {
		state = ((volatile DVDCommandBlock*)block)->state;

		if (state == DVD_STATE_END) {
			retVal = 0;
			break;
		}
		if (state == DVD_STATE_FATAL_ERROR) {
			retVal = DVD_RESULT_FATAL_ERROR;
			break;
		}
		if (state == DVD_STATE_CANCELED) {
			retVal = DVD_RESULT_CANCELED;
			break;
		}

		OSSleepThread(&__DVDThreadQueue);
	}

	OSRestoreInterrupts(enabled);
	return retVal;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void cbForPrepareStreamSync(s32 result, DVDCommandBlock* block)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
s32 DVDGetTransferredSize(DVDFileInfo* fileinfo)
{
	// UNUSED FUNCTION
}
