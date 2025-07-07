#include "jaudio/bankloader.h"

#include "jaudio/aictrl.h"
#include "jaudio/bankread.h"
#include "jaudio/dvdthread.h"
#include "jaudio/waveread.h"

typedef struct BXHeader BXHeader;
typedef struct AddrSize AddrSize;

/**
 * @brief This is an invented type of an unknown name. It represents a file structure.
 *
 * @note Size: 0x10. Based on https://github.com/XAYRGA/JaiSeqX/blob/sxlja-newenv/JaiSeqXLJA/libJAudio/Loaders/JA_BXLoader.cs
 */
struct BXHeader {
	u32 wsysPointerOffset;
	u32 wsysPointerCount;
	u32 ibnkPointerOffset;
	u32 ibnkPointerCount;
};

/**
 * @brief This is an invented type of an unknown name. It represents a file structure.
 *
 * @note Size: 0x8.
 */
struct AddrSize {
	u32 addr;
	u32 size;
};

/*
 * --INFO--
 * Address:	8001D9A0
 * Size:	0000E0
 */
void Bank_Setup(char* filename)
{
	u32 i;

	u8* mem;
	BXHeader* header;
	AddrSize* pairs;
	u32 pointerCount;

	Bank_Init();

	mem = (u8*)OSAlloc2(DVDT_CheckFile(filename));
	DVDT_LoadFile(filename, mem);
	header = (BXHeader*)mem;

	Wavegroup_Init();

	pointerCount = header->wsysPointerCount;
	pairs        = (AddrSize*)(mem + header->wsysPointerOffset);

	for (i = 0; i < pointerCount; ++i) {
		if (pairs[i].size != 0) {
			Wavegroup_Regist((void*)(mem + pairs[i].addr), i);
		}
	}

	pointerCount = header->ibnkPointerCount;
	pairs        = (AddrSize*)(mem + header->ibnkPointerOffset);

	for (i = 0; i < pointerCount; ++i) {
		if (pairs[i].size != 0) {
			Bank_Regist((void*)(mem + pairs[i].addr), i);
		}
	}
}
