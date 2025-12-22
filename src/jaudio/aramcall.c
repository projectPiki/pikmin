#include "jaudio/aramcall.h"

#include "jaudio/dummyrom.h"
#include "jaudio/dvdthread.h"
#include "jaudio/heapctrl.h"

#include "stl/string.h"

jaheap_ aram_mother;

ARAMCallback ARCALL    = &LoadAram_Default;
static char extdir[64] = "/Banks/";

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Jac_RegisterARAMCallback(ARAMCallback callback)
{
	ARCALL = callback;
}

u32 LoadAram(immut char* filepath, u32* status, u32 dst)
{
	immut char** REF_filepath = &filepath;
	u32* REF_dst              = &dst;

	if (DVDT_LoadtoARAM(0, filepath, dst, 0, 0, status, NULL) == -1) {
		return 0;
	}
	return dst;
}

u32 LoadAramSingle(immut char* filepath, u32 src, u32 length, u32* status, u32 dst)
{
	STACK_PAD_VAR(1);
	immut char** REF_filepath = &filepath;
	u32* REF_src              = &src;
	u32* REF_length           = &length;

	if (DVDT_LoadtoARAM(0, filepath, dst, src, length, status, NULL) == -1) {
		return 0;
	}
	return dst;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void Jac_WaveDirectorySet(immut char* directory)
{
	strcpy(extdir, directory);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
jaheap_* Get_AramMotherHeap(void)
{
	return &aram_mother;
}

void Show_AramMotherHeap(void)
{
	Jac_ShowHeap(&aram_mother, 0);
}

void Collect_AramMotherHeap(void)
{
	Jac_GarbageCollection_St(&aram_mother);
	Show_AramMotherHeap();
}

void Init_AramMotherHeap(void)
{
	void* alloc;
	u32 outSize;

	static BOOL inited = FALSE;
	if (!inited) {
		inited = TRUE;

		void* alloc = ARAllocFull(&outSize);
		Jac_InitMotherHeap(&aram_mother, (u32)alloc, outSize, 0);
	}
}

// Used only by `LoadAram_Default`.
static BOOL first = TRUE;

u32 LoadAram_Default(immut char* filename, u32 src, u32 length, u32* status, jaheap_* heap)
{
	char filepath[140];

	if (first) {
		Init_AramMotherHeap();
		first = FALSE;
	}

	strcpy(filepath, extdir);
	strcat(filepath, filename);

	if (src == 0 && length == 0) {
		if (!Jac_AllocHeap(heap, &aram_mother, DVDT_CheckFile(filepath))) {
			return 0;
		}
		return LoadAram(filepath, status, heap->startAddress);
	} else {
		if (!Jac_AllocHeap(heap, &aram_mother, length)) {
			return 0;
		}
		return LoadAramSingle(filepath, src, length, status, heap->startAddress);
	}
}

u32 LoadAram_All(immut char* filename, u32* status, jaheap_* heap)
{
	return ARCALL(filename, 0, 0, status, heap);
}

u32 LoadAram_One(immut char* filename, u32 src, u32 length, u32* status, jaheap_* heap)
{
	return ARCALL(filename, src, length, status, heap);
}
