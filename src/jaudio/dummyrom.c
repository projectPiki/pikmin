#include "jaudio/dummyrom.h"
#include "jaudio/memory.h"
#include "jaudio/audiocommon.h"
#include "Dolphin/ar.h"
#include "Dolphin/os.h"

ALHeap aram_hp;
u8* JAC_ARAM_DMA_BUFFER_TOP;

static u32 AUDIO_ARAM_TOP;
static u32 CARD_SECURITY_BUFFER;
static u32 SELECTED_ARAM_SIZE;

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GetNeosRomTop()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void mesg_finishcall(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void ARAMStartDMAmesg(u32, u32, u32, u32, s32, OSMesgQueue_s*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void ARAMStartDMA(u32, u32, u32, u32, s32, u32*, void (*)())
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800061A0
 * Size:	000008
 */
void Jac_SetAudioARAMSize(u32 size)
{
	SELECTED_ARAM_SIZE = size;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void ARAlloc2(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800061C0
 * Size:	000058
 */
void* ARAllocFull(u32* outSize)
{
	u32 freeSize = aram_hp.length - ((int)aram_hp.current - (int)aram_hp.base);

	void* alloc = Nas_HeapAlloc(&aram_hp, freeSize - 32);
	*outSize    = freeSize - 32;
	return alloc;
}

/*
 * --INFO--
 * Address:	80006220
 * Size:	000098
 */
void Jac_InitARAM(u32 loadAudiorom)
{
	volatile u32 audiorom_size;
	u32 aram_size;

	if (SELECTED_ARAM_SIZE) {
		aram_size = SELECTED_ARAM_SIZE;
	} else {
		aram_size = AUDIO_ARAM_SIZE;
	}

	AUDIO_ARAM_TOP = ARGetBaseAddress();
	audiorom_size  = 0;

	CARD_SECURITY_BUFFER = 0x40;
	audiorom_size += AUDIO_ARAM_TOP;
	JAC_ARAM_DMA_BUFFER_TOP = (u8*)audiorom_size;
	audiorom_size += AUDIO_ARAM_HEAP_SIZE;
	Nas_HeapInit(&aram_hp, (u8*)audiorom_size, aram_size - audiorom_size);

	/* Probably leftovers from some debug print statement */
	(void)audiorom_size;
	u32 badCompiler[6];
}
