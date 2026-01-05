#include "jaudio/fat.h"
#include "jaudio/aictrl.h"
#include "jaudio/sample.h"
#include <stddef.h>

static int ACTIVE_FATS;
static int USEFAT_TAIL;
static u8* fatheapptr;

typedef struct FATEntry FATEntry;

struct FATEntry {
	u16 ownerHandle; // _00
	u16 blockSize;   // _02
	u8* addr;        // _04
};

#define FAT_SIZE (256)

static struct FAT_info2 {
	u16 startBlock; // _00
	u16 blockCount; // _02
} FH_TO_FAT[FAT_SIZE];

static FATEntry FAT[FAT_SIZE];

// havent figured this out yet
static struct FATEntry fattmp[FAT_SIZE];

/**
 * @TODO: Documentation
 */
void Jac_FatMemory_Init(u32 size)
{
	fatheapptr = (u8*)OSAlloc2(size);

	if (fatheapptr) {
		FAT_InitSystem(fatheapptr, size);
	}
}

/**
 * @TODO: Documentation
 */
void FAT_InitSystem(u8* heap, u32 size)
{
	u32 i;

	int fats = 0;
	for (i = 0; i < FAT_SIZE; i++) {
		if (size < 0x1000) {
			break;
		}

		size -= 0x1000;
		FAT[i].addr = heap;
		fats++;
		heap += 0x1000;

		FAT[i].blockSize   = 0x1000;
		FAT[i].ownerHandle = 0xffff;
	}

	ACTIVE_FATS = fats;
	USEFAT_TAIL = 0;

	for (i = ACTIVE_FATS; i < FAT_SIZE; i++) {
		FAT[i].ownerHandle = 0xffff;
		FAT[i].blockSize   = 0;
	}

	for (i = 0; i < FAT_SIZE; i++) {
		FH_TO_FAT[i].startBlock = -1;
		FH_TO_FAT[i].blockCount = 0;
	}
}

/**
 * @TODO: Documentation
 */
int FAT_AllocateMemory(u32 size)
{
	u32 a = 0;

	for (int i = 0; i < FAT_SIZE; i++) {
		if (FH_TO_FAT[i].blockCount == 0) {
			break;
		}
		a++;
	}

	if (a == FAT_SIZE) {
		return 0xffff;
	}
	u16 res = a;

	if (size == 0) {
		return 0xffff;
	}

	int b = size + 0xfff >> 0xc;
	if (ACTIVE_FATS - USEFAT_TAIL < b) {
		return 0xffff;
	}

	for (u32 i = USEFAT_TAIL; i < USEFAT_TAIL + b; i++) {
		FAT[i].ownerHandle = res;
	}

	FH_TO_FAT[res].startBlock = USEFAT_TAIL;
	FH_TO_FAT[res].blockCount = b;

	USEFAT_TAIL += b;
	return res;
}

/**
 * @TODO: Documentation
 */
int FAT_FreeMemory(u16 size)
{
	STACK_PAD_VAR(2);
	u16 temp;
	u32 i;
	u32 start;
	u16 size2;
	u32 count;
	u16 tail;

	count                      = FH_TO_FAT[size].blockCount;
	start                      = FH_TO_FAT[size].startBlock;
	FH_TO_FAT[size].blockCount = 0;
	size2                      = start + count;
	tail                       = USEFAT_TAIL - size2;

	if (tail == 0) {
		USEFAT_TAIL -= count;
		for (i = 0; i < count; i++) {
			FAT[USEFAT_TAIL + i].ownerHandle = 0xffff;
		}
		return 0;
	}

	for (i = 0; i < count; i++) {
		fattmp[i] = FAT[start + i];

		fattmp[i].ownerHandle = 0xffff;
	}

	temp = 0xffff;
	for (i = 0; i < tail; i++) {
		FAT[start + i] = FAT[size2 + i];
		if (FAT[size2 + i].ownerHandle != temp) {
			FH_TO_FAT[FAT[size2 + i].ownerHandle].startBlock = start + i;
			temp                                             = FAT[size2 + i].ownerHandle;
		}
	}

	USEFAT_TAIL -= count;
	for (i = 0; i < count; i++) {
		FAT[USEFAT_TAIL + i] = fattmp[i];
	}
	return 0;
}

/**
 * @TODO: Documentation
 */
u8* FAT_GetPointer(u16 a, u32 b)
{
	u32 c = b >> 12;
	if (FH_TO_FAT[a].blockCount <= c) {
		return 0;
	}

	b &= 0xFFF;
	return FAT[c + FH_TO_FAT[a].startBlock].addr + b;
}

/**
 * @TODO: Documentation
 */
u8 FAT_ReadByte(u16 a, u32 b)
{
	u8* ptr = FAT_GetPointer(a, b);
	if (ptr == NULL) {
		return 0;
	}
	return *ptr;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
u16 FAT_ReadWord(u16 a, u32 b)
{
	// Guessing based on name/size

	u16* ptr = (u16*)FAT_GetPointer(a, b);
	if (ptr == NULL) {
		return 0;
	}
	return *ptr;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000050
 */
void FAT_ReadWordD(u16 a, u32 b)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
u32 FAT_ReadLong(u16 a, u32 b)
{
	// UNUSED FUNCTION

	// Guessing based on name/size
	return *(u32*)FAT_GetPointer(a, b);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000080
 */
void FAT_ReadLongD(u16 a1, u32 a2)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
int FAT_StoreBlock(u8* ptr, u16 a, u32 b, u32 c)
{
	STACK_PAD_VAR(2);
	u8* ptr2 = FAT_GetPointer(a, b);

	int size = b;
	b &= 0xFFF;
	size -= b;
	// this whole thing is wrong
	while (c != 0) {
		b++;
		*ptr2++ = *ptr++;
		c--;

		if (b == 0x1000) {
			size += 0x1000;

			ptr2 = FAT_GetPointer(a, size);
			break;
		}
	}

	for (; 0x1000 <= c;) {
		Jac_bcopy(ptr, ptr2, 0x1000);
		size += 0x1000;
		c -= 0x1000;
		ptr += 0x1000;
		ptr2 = FAT_GetPointer(a, size);
	}

	if (c != 0) {
		Jac_bcopy(ptr, ptr2, c);
	}
	return 0;
}
