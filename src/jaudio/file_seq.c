#include "jaudio/file_seq.h"

#include "jaudio/jammain_2.h"
#include "jaudio/seqsetup.h"
#include "jaudio/virload.h"

#include <stddef.h>
#include <string.h>

/**
 * @brief Invented struct of an unknown name.
 *
 * @note Size: 0x10
 * @note TODO: Is this invented struct namedropped somewhere?
 */
struct as_struct {
	u8 mInUse;  // _00
	u32 mSeqIndex; // _04
	u32 _08; // _08
	u8* mBuffer; // _0C
};
typedef struct as_struct as_struct;

#define SEQ_LOADBUFFER_SIZE 0x100
#define ROOTSEQ_SIZE        0x10
#define ROOTSEQHANDLE_SIZE  0x10
#define AS_SIZE             0x8

static u8* seq_loadbuffer[SEQ_LOADBUFFER_SIZE]; // TODO: Type unknown
static u32 seq_archandle;                       // TODO: Type unknown
static seqp_ rootseq[ROOTSEQ_SIZE];
static u32 rootseqhandle[ROOTSEQHANDLE_SIZE]; // TODO: Type unknown
static as_struct as[AS_SIZE];                 // TODO: Type unknown

static u32 first = TRUE;

/**
 * @TODO: Documentation
 */
void Jaf_InitSeqArchive2(immut char* barcFilepath, u8* barcData, u8* archiveWork)
{
	STACK_PAD_VAR(2);

	immut char** REF_barcFilepath;
	size_t i;

	REF_barcFilepath = &barcFilepath;
	for (i = strlen(barcFilepath); i != 0; --i) {
		if (barcFilepath[i - 1] == '/') {
			break;
		}
	}

	JV_InitHeader_M(barcFilepath, barcData, archiveWork);
	seq_archandle = JV_GetArchiveHandle(&barcFilepath[i]);

	for (i = 0; i < SEQ_LOADBUFFER_SIZE; ++i) {
		seq_loadbuffer[i] = NULL;
	}
	for (i = 0; i < ROOTSEQHANDLE_SIZE; ++i) {
		rootseqhandle[i] = -1;
	}
}

/**
 * @TODO: Documentation
 */
u32 Jaf_CheckSeqSize(u32 arcHandleMask)
{
	if (seq_archandle == -1) {
		return 0;
	}
	return JV_CheckSize(seq_archandle | arcHandleMask);
}

/**
 * @TODO: Documentation
 */
u32 Jaf_LoadSeq(u32 seqIndex, u8* seqBuffer)
{
	if (seq_archandle == -1) {
		return FALSE;
	}
	u32 size = Jaf_CheckSeqSize(seqIndex);
	if (size == 0) {
		return FALSE;
	}
	u32 seqArchiveHandle    = seq_archandle | seqIndex;
	BOOL result             = JV_LoadFile(seqArchiveHandle, seqBuffer, 0, size);
	seq_loadbuffer[seqIndex] = seqBuffer;
	return result;
}

/**
 * @TODO: Documentation
 */
void Jaf_ClearSeq(u32 index)
{
	seq_loadbuffer[index] = NULL;
}

/**
 * @TODO: Documentation
 */
u8* Jaf_CheckSeq(u32 index)
{
	return seq_loadbuffer[index];
}

/**
 * @TODO: Documentation
 */
u32 Jaf_ReadySeq(u32 rootTrackIndex, u32 seqIndex)
{
	STACK_PAD_VAR(1);
	seqp_* rootTrack = &rootseq[rootTrackIndex];
	if (seqIndex >= SEQ_LOADBUFFER_SIZE) {
		return 0;
	}
	if (!seq_loadbuffer[seqIndex]) {
		return 0;
	}

	u32 seqSize = Jaf_CheckSeqSize(seqIndex);
	if (seqSize == 0) {
		return 0;
	}

	rootseqhandle[rootTrackIndex] = Jaq_SetSeqData(rootTrack, seq_loadbuffer[seqIndex], seqSize, 0);
	return rootseqhandle[rootTrackIndex];
}

/**
 * @TODO: Documentation
 */
BOOL Jaf_PlaySeq(u32 rootTrackIndex)
{
	Jaq_StartSeq(rootseqhandle[rootTrackIndex]);
	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL Jaf_StartSeq(u32 rootTrackIndex, u32 seqIndex)
{
	Jaf_ReadySeq(rootTrackIndex, seqIndex);
	Jaf_PlaySeq(rootTrackIndex);
	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL Jaf_StopSeq(u32 index)
{
	STACK_PAD_VAR(2);

	if (rootseqhandle[index] == -1) {
		return FALSE;
	}
	BOOL result = Jaq_StopSeq(rootseqhandle[index]);
	while (Jaq_HandleToSeq(rootseqhandle[index])) { }
	rootseqhandle[index] = -1;
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000018
 */
void Jaf_GetJamHandle(u32 rootTrackIndex)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 */
seqp_* Jaf_HandleToSeq(u32 index)
{
	return &rootseq[index];
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000058
 */
void Jaf_LoadStartFinish(u32 asyncContext)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 */
static void Jaf_LoadFinish(u32 asyncContext)
{
	// Why is a (known) u32 parameter suddenly a pointer?
	seq_loadbuffer[*(int*)(asyncContext + 4)] = *(u8**)(asyncContext + 12);
	*(u8*)asyncContext                        = 0;
}

/**
 * @TODO: Documentation
 */
u32 __LoadSeqA(u32 callbackArg, u32 seqIndex, u8* seqBuffer, void (*finishCallback)(u32))
{
	u32* REF_callbackArg = &callbackArg;
	u32* REF_seqIndex    = &seqIndex;
	u8** REF_seqBuffer   = &seqBuffer;

	u32 slotIndex;
	u32 seqSize;
	u32 seqArchiveHandle;

	if (first) {
		for (slotIndex = 0; slotIndex < AS_SIZE; ++slotIndex) {
			as[slotIndex].mInUse = 0;
		}
		first = FALSE;
	}

	for (slotIndex = 0; slotIndex < AS_SIZE; ++slotIndex) {
		if (as[slotIndex].mInUse == 0) {
			break;
		}
	}
	if (slotIndex == AS_SIZE) {
		return 0;
	}
	if (seq_archandle == -1) {
		return 0;
	}

	seqSize = Jaf_CheckSeqSize(seqIndex);
	if (seqSize == 0) {
		return 0;
	}
	seqArchiveHandle       = seq_archandle | seqIndex;
	as[slotIndex].mInUse   = 1;
	as[slotIndex].mSeqIndex = seqIndex;
	as[slotIndex].mBuffer  = seqBuffer;
	as[slotIndex]._08      = callbackArg;

	seq_loadbuffer[seqIndex] = (u8*)1;
	return JV_LoadFile_Async2(seqArchiveHandle, seqBuffer, 0, seqSize, finishCallback, (u32)&as[slotIndex]);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
void Jaf_LoadStartSeqA(u32 callbackArg, u32 seqIndex, u8* seqBuffer)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 */
u32 Jaf_LoadSeqA(u32 seqIndex, u8* seqBuffer)
{
	return __LoadSeqA(0, seqIndex, seqBuffer, Jaf_LoadFinish);
}
