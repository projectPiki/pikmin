#include "jaudio/file_seq.h"

#include "jaudio/virload.h"
#include "jaudio/seqsetup.h"

#include "stl/string.h"

/**
 * @brief Invented struct of an unknown name.
 *
 * @note Size: 0x10
 * @note TODO: Is this invented struct namedropped somewhere?
 */
struct as_struct {
	unknown8 _00; // _00
	u32 _04;      // _04
	u32 _08;      // _08
	u8* _0C;      // _0C
};
typedef struct as_struct as_struct;

#define SEQ_LOADBUFFER_SIZE 0x100
#define ROOTSEQHANDLE_SIZE  0x10
#define AS_SIZE             0x8

static u8* seq_loadbuffer[SEQ_LOADBUFFER_SIZE]; // TODO: Type unknown
static u32 seq_archandle;                       // TODO: Type unknown
static u32 rootseq[0x10D0];                     // TODO: Type unknown
static u32 rootseqhandle[ROOTSEQHANDLE_SIZE];   // TODO: Type unknown
static as_struct as[AS_SIZE];                   // TODO: Type unknown

static BOOL first = TRUE; // TODO: Type unknown

/*
 * --INFO--
 * Address:	8001B3E0
 * Size:	0000D0
 */
void Jaf_InitSeqArchive2(char* volatile barcFilepath, u8* barcData, u8* param_3)
{
	u32 badCompiler[2];

	char* barcFilepathNonVolatile;
	size_t basenameIdx;

	barcFilepathNonVolatile = barcFilepath;
	for (basenameIdx = strlen(barcFilepathNonVolatile); basenameIdx != 0; --basenameIdx) {
		if (barcFilepathNonVolatile[basenameIdx - 1] == '/') {
			break;
		}
	}

	JV_InitHeader_M(barcFilepathNonVolatile, barcData, param_3);
	seq_archandle = JV_GetArchiveHandle(barcFilepathNonVolatile + basenameIdx);

	for (int i = 0; i < SEQ_LOADBUFFER_SIZE; ++i) {
		seq_loadbuffer[i] = NULL;
	}
	for (int i = 0; i < ROOTSEQHANDLE_SIZE; ++i) {
		rootseqhandle[i] = -1;
	}
}

/*
 * --INFO--
 * Address:	8001B4C0
 * Size:	00003C
 */
u32 Jaf_CheckSeqSize(u32 arcHandleMask)
{
	if (seq_archandle == -1) {
		return 0;
	}
	return JV_CheckSize(seq_archandle | arcHandleMask);
}

/*
 * --INFO--
 * Address:	8001B500
 * Size:	000088
 */
BOOL Jaf_LoadSeq(u32 param_1, u8* param_2)
{
	if (seq_archandle == -1) {
		return FALSE;
	}
	u32 size = Jaf_CheckSeqSize(param_1);
	if (size == 0) {
		return FALSE;
	}
	u32 temp                = seq_archandle | param_1;
	BOOL result             = JV_LoadFile(temp, param_2, 0, size);
	seq_loadbuffer[param_1] = param_2;
	return result;
}

/*
 * --INFO--
 * Address:	8001B5A0
 * Size:	00001C
 */
void Jaf_ClearSeq(u32 index)
{
	seq_loadbuffer[index] = NULL;
}

/*
 * --INFO--
 * Address:	8001B5C0
 * Size:	000018
 */
u8* Jaf_CheckSeq(u32 index)
{
	return seq_loadbuffer[index];
}

/*
 * --INFO--
 * Address:	8001B5E0
 * Size:	0000A0
 */
unknown Jaf_ReadySeq(u32 param_1, u32 param_2)
{
	if ((param_2 < SEQ_LOADBUFFER_SIZE) && !seq_loadbuffer[param_2]) {

		u32 seqSize = Jaf_CheckSeqSize(param_2);
		if (seqSize != 0) {

			rootseqhandle[param_1] = Jaq_SetSeqData(rootseq[param_1 * 0x10d], seq_loadbuffer[param_2], seqSize, 0);
			return rootseqhandle[param_1];
		}
	}
	return 0;
}

/*
 * --INFO--
 * Address:	8001B680
 * Size:	000038
 */
BOOL Jaf_PlaySeq(u32 index)
{
	Jaq_StartSeq(rootseqhandle[index]);
	return TRUE;
}

/*
 * --INFO--
 * Address:	8001B6C0
 * Size:	000038
 */
BOOL Jaf_StartSeq(u32 param_1, u32 param_2)
{
	Jaf_ReadySeq(param_1, param_2);
	Jaf_PlaySeq(param_1);
	return TRUE;
}

/*
 * --INFO--
 * Address:	8001B700
 * Size:	000070
 */
BOOL Jaf_StopSeq(u32 index)
{
	u32 badCompiler[2];

	if (rootseqhandle[index] == -1) {
		return FALSE;
	}
	BOOL result = Jaq_StopSeq(rootseqhandle[index]);
	while (Jaq_HandleToSeq(rootseqhandle[index])) { }
	rootseqhandle[index] = -1;
	return result;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void Jaf_GetJamHandle(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001B780
 * Size:	000014
 */
void Jaf_HandleToSeq(u32)
{
	/*
	.loc_0x0:
	  mulli     r4, r3, 0x434
	  lis       r3, 0x8036
	  addi      r0, r3, 0x4A88
	  add       r3, r0, r4
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void Jaf_LoadStartFinish(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001B7A0
 * Size:	000028
 */
static void Jaf_LoadFinish(u32 param_1)
{
	// Why is a (known) u32 parameter suddenly a pointer?
	seq_loadbuffer[*(int*)(param_1 + 4)] = *(u8**)(param_1 + 12);
	*(unknown8*)param_1                  = 0;
}

/*
 * --INFO--
 * Address:	8001B7E0
 * Size:	000124
 */
unknown __LoadSeqA(volatile u32 param_1, volatile u32 param_2, u8* volatile param_3, void (*param_4)(u32))
{
	// This WIP is a mess. I hate volatile memes.
	u32 index;
	int seqSize;
	u32 seqArcHandle;

	if (first) {
		for (index = 0; index < AS_SIZE; ++index) {
			as[index]._00 = 0;
		}
		first = FALSE;
	}

	for (index = 0; index < AS_SIZE; ++index) {
		if (as[index]._00 == 0) {
			break;
		}
	}
	if (index == AS_SIZE) {
		return 0;
	}
	if (seq_archandle == -1) {
		return 0;
	}

	u32 param_2_NV = param_2;
	seqSize        = Jaf_CheckSeqSize(param_2_NV);
	if (seqSize == 0) {
		return 0;
	}
	seqArcHandle   = seq_archandle;
	u8* param_3_NV = param_3;
	as[index]._00  = 1;
	as[index]._04  = param_2_NV;
	as[index]._0C  = param_3_NV;
	as[index]._08  = param_1;

	seq_loadbuffer[param_2_NV] = (u8*)1;
	return JV_LoadFile_Async2(seqArcHandle | param_2_NV, param_3_NV, 0, seqSize, param_4, as[index]._00);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void Jaf_LoadStartSeqA(u32, u32, u8*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001B920
 * Size:	000034
 */
void Jaf_LoadSeqA(u32 param_1, u8* param_2)
{
	__LoadSeqA(0, param_1, param_2, Jaf_LoadFinish);
}
