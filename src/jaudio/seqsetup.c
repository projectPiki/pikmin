#include "jaudio/seqsetup.h"

#include "jaudio/jammain_2.h"
#include "jaudio/noteon.h"
#include "jaudio/fat.h"
#include "jaudio/playercall.h"
#include "jaudio/jamosc.h"
#include "jaudio/driverinterface.h"
#include "jaudio/oneshot.h"
#include "jaudio/fat.h"

#include "Dolphin/OS/OSInterrupt.h"

#define SEQ_SIZE             (256)
#define ROOT_OUTER_SIZE      (16)
#define ROOTSEQ_SIZE         (16)
#define FREE_SEQP_QUEUE_SIZE (256)

static seqp_ seq[SEQ_SIZE];
static OuterParam_ ROOT_OUTER[ROOT_OUTER_SIZE];
static seqp_* rootseq[ROOTSEQ_SIZE];
static seqp_* FREE_SEQP_QUEUE[FREE_SEQP_QUEUE_SIZE];

static u32 BACK_P;
static u32 GET_P;
static u32 SEQ_REMAIN;

/*
 * --INFO--
 * Address:	80013DA0
 * Size:	0000A0
 */
void Jaq_Reset(void)
{
	int i;

	for (i = 0; i < SEQ_SIZE; ++i) {
		seq[i]._3C         = 0;
		seq[i]._3A0        = 0;
		seq[i]._39E        = 0;
		FREE_SEQP_QUEUE[i] = &seq[i];
	}

	BACK_P     = 0;
	GET_P      = 0;
	SEQ_REMAIN = FREE_SEQP_QUEUE_SIZE;

	for (i = 0; i < ROOTSEQ_SIZE; ++i) {
		rootseq[i] = NULL;
	}

	Jam_InitRegistTrack();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Jaq_GetRemainFreeTracks(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80013E40
 * Size:	000088
 */
static BOOL BackTrack(seqp_* track)
{
	seqp_** REF_track;

	REF_track  = &track;
	track->_3C = 0;
	if (track->_3E4 == 1) {
		if (SEQ_REMAIN == FREE_SEQP_QUEUE_SIZE) {
			return FALSE;
		}

		FREE_SEQP_QUEUE[BACK_P] = track;
		++SEQ_REMAIN;
		++BACK_P;

		if (BACK_P == FREE_SEQP_QUEUE_SIZE) {
			BACK_P = 0;
		}
		return TRUE;
	}
	return FALSE;
}

/*
 * --INFO--
 * Address:	80013EE0
 * Size:	000064
 */
static seqp_* GetNewTrack()
{
	seqp_* track;

	if (SEQ_REMAIN == 0) {
		return NULL;
	}

	track = FREE_SEQP_QUEUE[GET_P];
	++GET_P;
	--SEQ_REMAIN;

	if (GET_P == FREE_SEQP_QUEUE_SIZE) {
		GET_P = 0;
	}

	track->_3C  = 2;
	track->_3E4 = 1;
	return track;
}

/*
 * --INFO--
 * Address:	80013F60
 * Size:	000048
 */
int AllocNewRoot(seqp_* track)
{
	int i;

	for (i = 0; i < ROOTSEQ_SIZE; ++i) {
		if (!rootseq[i]) {
			rootseq[i] = track;
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	80013FC0
 * Size:	00004C
 */
int DeAllocRoot(seqp_* track)
{
	int i;

	for (i = 0; i < ROOTSEQ_SIZE; ++i) {
		if (rootseq[i] == track) {
			rootseq[i] = NULL;
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	80014020
 * Size:	000018
 */
seqp_* Jaq_HandleToSeq(u32 handle)
{
	return rootseq[handle];
}

/*
 * --INFO--
 * Address:	80014040
 * Size:	000368
 */
static void Init_Track(seqp_* track, u32 param_2, seqp_* otherSeq)
{
	int i;

	if (!otherSeq) {
		track->_00  = (u8*)param_2;
		track->_04  = 0;
		track->_33A = 0x78;
		track->_338 = 0x30;
		track->_33C = 1;
		track->_39C = 0;
		track->_39D = 10;
		track->_3A0 = 0;
		track->_39E = 0;
	} else {
		track->_00  = otherSeq->_00;
		track->_04  = param_2;
		track->_3E  = otherSeq->_3E;
		track->_33A = otherSeq->_33A;
		track->_3E3 = 0;
		track->_334 = otherSeq->_334;
		track->_338 = otherSeq->_338;
		track->_33C = otherSeq->_33C;
		track->_39C = otherSeq->_39C;
		track->_39D = otherSeq->_39D;
		track->_3A0 = 0;
	}
	track->_08    = 0;
	track->_D0    = 0;
	track->_8C    = 0;
	track->_3C    = 1;
	track->parent = otherSeq;
	track->_3A6   = 0;
	track->_3A4   = 0;
	track->_3D0   = 0;

	// Initialize all MoveParams with default values.
	for (i = 0; i < 18; ++i) {
		track->timedParam.move[i].moveTime  = 0.0f;
		track->timedParam.move[i].currValue = 1.0f;
		track->timedParam.move[i].targValue = 1.0f;
	}

	track->timedParam.inner.pitch.currValue = 0.0f;
	track->timedParam.inner.pitch.targValue = 0.0f;
	track->timedParam.inner.pitch.currValue = 0.0f; // Just to be sure.
	track->timedParam.inner.pitch.targValue = 0.0f; // Just to be sure.
	track->timedParam.inner.pan.currValue   = 0.5f;
	track->timedParam.inner.pan.targValue   = 0.5f;

	track->timedParam.inner._100.currValue = 0.5f;
	track->timedParam.inner._100.targValue = 0.5f;
	track->timedParam.inner._110.currValue = 0.0f;
	track->timedParam.inner._110.targValue = 0.0f;

	track->timedParam.inner.fxmix.currValue = 0.0f;
	track->timedParam.inner.fxmix.targValue = 0.0f;
	track->timedParam.inner.dolby.currValue = 0.0f;
	track->timedParam.inner.dolby.targValue = 0.0f;

	// Initialize IIRs (skipping the first one)
	for (i = 1; i < 4; ++i) {
		track->timedParam.inner.IIRs[i].currValue = 0.0f;
		track->timedParam.inner.IIRs[i].targValue = 0.0f;
	}

	track->timedParam.inner._50.currValue = 0.0f;
	track->timedParam.inner._50.targValue = 0.0f;

	for (i = 0; i < 32; ++i) {
		track->regParam.reg[i] = 0;
	}

	if ((track->_3F & 2) || !track->parent) {
		track->regParam.param._10[0] = 0;
		track->regParam.param._10[1] = 1;
		track->regParam.param._10[2] = 1;
		track->regParam.param._10[3] = 0x7fff;
		track->regParam.param._10[4] = 0x4000;
		for (i = 0; i < 3; ++i) {
			track->_3DC[i]    = 2;
			track->_3DF[i]    = 2;
			track->_D8._62[i] = 26;
		}
		track->regParam.param._0C = 0xf0;
		track->regParam.param._0E = 0x0c;
		track->regParam.param._1A = 0x40;
	} else {
		for (i = 0; i < 5; ++i) {
			track->regParam.param._10[i] = track->parent->regParam.param._10[i];
		}
		track->regParam.param._0C = track->parent->regParam.param._0C;
		track->regParam.param._0E = track->parent->regParam.param._0E;
		track->regParam.param._1A = track->parent->regParam.param._1A;
		for (i = 0; i < 3; ++i) {
			track->_3DC[i]    = track->parent->_3DC[i];
			track->_3DF[i]    = track->parent->_3DF[i];
			track->_D8._62[i] = track->parent->_D8._62[i];
		}
	}

	for (i = 0; i < 16; ++i) {
		track->_2B0[i]     = NULL;
		track->children[i] = 0;
	}

	for (i = 0; i < 8; ++i) {
		track->_94[i] = -1;
		track->_9C[i] = NULL;
		track->_BC[i] = 0;
	}
	track->_D4 = 0;
	track->_D5 = 0;
	track->_90 = 0;
	track->_D6 = 0;
	Osc_Init_Env(track);
	track->_396 = 0;
	track->_397 = 0;
	track->_398 = -1;

	for (i = 0; i < 16; ++i) {
		track->trackPort[i].importFlag = 0;
		track->trackPort[i].exportFlag = 0;
	}

	track->isRegistered = 0;
}

/*
 * --INFO--
 * Address:	800143C0
 * Size:	0000A0
 */
BOOL Jaq_StopSeq(s32 index)
{
	seqp_* track;

	if (index == -1) {
		return FALSE;
	}
	track = rootseq[index];
	if (!track) {
		return FALSE;
	}

	switch (track->_3C) {
	case 0:
		break;
	case 2:
		BackTrack(track);
		DeAllocRoot(track);
		break;
	default:
		track->_3C = 3;
		break;
	}
	return TRUE;
}

/*
 * --INFO--
 * Address:	80014460
 * Size:	000054
 */
static void __StopSeq(seqp_* track)
{
	SeqUpdate(track, 0);
	Jaq_CloseTrack(track);
	DeAllocRoot(track);
	if (track->_3D == 1) {
		FAT_FreeMemory(track->_3E);
	}
}

/*
 * --INFO--
 * Address:	800144C0
 * Size:	000024
 */
s32 Jaq_SetSeqData(seqp_* param_1, u8* param_2, u32 param_3, u32 param_4)
{
	return Jaq_SetSeqData_Limit(param_1, param_2, param_3, param_4, 0);
}

/*
 * --INFO--
 * Address:	80014500
 * Size:	000170
 */
s32 Jaq_SetSeqData_Limit(seqp_* track, u8* param_2, u32 param_3, u32 param_4, u8 param_5)
{
	s32 root;
	BOOL level;
	u8* puVar2;

	if (!track) {
		level = OSDisableInterrupts();
		track = GetNewTrack();
		OSRestoreInterrupts(level);
		if (!track) {
			return -1;
		}
	} else {
		track->_3E4 = 0;
	}

	root = AllocNewRoot(track);
	if (root == -1) {
		return -1;
	}

	track->_3D = param_4;
	switch (param_4) {
	case 0:
		puVar2 = param_2;
		break;
	case 1:
		track->_3E = FAT_AllocateMemory(param_3);
		if (track->_3E == 0xffff) { // Isn't this literally impossible?
			return -1;
		}
		FAT_StoreBlock(param_2, track->_3E, 0, param_3);
		puVar2 = NULL;
		break;
	case 2:
		track->_3E = (u8)param_2;
		puVar2     = NULL;
		break;
	}
	track->_88 = root;
	track->_3F = 3;
	Init_Track(track, (u32)puVar2, NULL);
	Jam_InitExtBuffer(&ROOT_OUTER[root]);
	Jam_AssignExtBuffer(track, &ROOT_OUTER[root]);
	Init_1shot(&track->_D8, param_5);
	track->_330 = 0.0f;
	track->_334 = 1.0f;
	Jam_UpdateTrackAll(track);
	track->_3C = 2;
	return root;
}

/*
 * --INFO--
 * Address:	80014680
 * Size:	00002C
 */
BOOL Jaq_SetBankNumber(seqp_* track, u8 bankNum)
{
	u8 lo;

	// Let's get ahead of ourselves here.
	lo = track->regParam.param._0C & 0xFF;
	if (!track) {
		return FALSE;
	}
	track->regParam.param._0C = (bankNum << 8) | lo;
	return TRUE;
}

static s32 Jaq_RootCallback(void* track);

/*
 * --INFO--
 * Address:	800146C0
 * Size:	0000B4
 */
BOOL Jaq_StartSeq(u32 param_1)
{
	seqp_* track;
	u8* lbzu;

	if (param_1 == -1) {
		return FALSE;
	}

	track = rootseq[param_1];
	if (!track) {
		return FALSE;
	};

	// This feels like a fakematch, but oh well.
	switch (*(lbzu = &track->_3C)) {
	case 0:
		return FALSE;
	case 1:
		return FALSE;
	case 3:
		return FALSE;
	case 2:
		*lbzu = 1;
	}
	Jac_RegisterDspPlayerCallback(&Jaq_RootCallback, rootseq[param_1]);
	return TRUE;
}

/*
 * --INFO--
 * Address:	80014780
 * Size:	00014C
 */
s32 Jaq_OpenTrack(seqp_* track, u32 param_2, u32 param_3)
{
	seqp_* psVar1;
	seqp_* psVar2;
	u8 index;
	u8 bVar5;
	// u8 bit_5;

	u8* REF_index;

	index = (param_2 & 0b00001111);
	bVar5 = (param_2 & 0b11000000) >> 6;
	if ((param_2 & 0b00100000) != 0) {
		bVar5 = 4;
	}
	if ((u8)(param_2 & 0b00100000) != 0) { // But why cast it...?
		index = Jam_ReadRegDirect(track, index);
	}
	REF_index = &index;
	if (index >= 16) {
		return -1;
	}
	psVar1 = track->children[index];
	if (psVar1) {
		Jaq_CloseTrack(psVar1);
	}
	psVar2 = GetNewTrack();
	if (!psVar2) {
		return -1;
	}
	track->children[index] = psVar2;
	psVar2->_88            = ((track->_88 << 4 | index) & 0xFFFFFFF) | ((track->_88 & 0xF0000000) + 0x10000000);
	psVar2->_84            = 0;
	psVar2->_3D            = track->_3D;
	psVar2->_3F            = bVar5;
	Init_Track(psVar2, param_3, track);
	// Dev rolls "worst bit extraction method", asked to leave Nintendo EAD.
	psVar2->_39E = psVar2->parent->_39E | ((psVar2->parent->_3A0 & (1 << index)) >> (index));
	psVar2->_2AC = psVar2->parent->_2B0[index];
	if (psVar2->_2AC) {
		++psVar2->_2AC->_04;
	}
	Init_1shot(&psVar2->_D8, 0);
	Jam_UpdateTrackAll(psVar2);
	return 0;
}

/*
 * --INFO--
 * Address:	800148E0
 * Size:	0000B4
 */
void __AllNoteOff(seqp_* track)
{
	u32 i;

	if (!track->parent) {
		for (i = 0; i < 8; ++i) {
			NoteOFF_R(track, i, 10);
			track->_94[i] = -1;
			track->_9C[i] = NULL;
		}
	} else {
		for (i = 0; i < 8; ++i) {
			NoteOFF(track, i);
			track->_94[i] = -1;
			track->_9C[i] = NULL;
		}
	}
}

/*
 * --INFO--
 * Address:	800149A0
 * Size:	000120
 */
unknown Jaq_CloseTrack(seqp_* track)
{
	size_t i;

	// Specifically two separate conditional blocks, because why not.
	if (!track) {
		return 0;
	}
	if (track->_3C == 0) {
		return 0;
	}

	__AllNoteOff(track);
	BackTrack(track);

	for (i = 0; i < 16; ++i) {
		if (track->children[i]) {
			Jaq_CloseTrack(track->children[i]);
			track->children[i] = NULL;
		}
	}

	if (track->_2AC) {
		// This smells like refcounting.
		track->_2AC->_04 -= 1;
		track->_2AC = NULL;
	}

	for (i = 0; i < 16; ++i) {
		if (track->_2B0[i]) {
			track->_2B0[i]->_00 = 0; // Probably also NULL if we're being real here.
			track->_2B0[i]      = NULL;
		}
	}
	track->_39E = 0;
	track->_3A0 = 0;
	if (track->parent) {
		FixMoveChannelAll(&track->_D8, &track->parent->_D8);
	} else {
		FixReleaseChannelAll(&track->_D8);
	}
	Jam_UnRegistTrack(track);
	return 0;
}

/*
 * --INFO--
 * Address:	80014AC0
 * Size:	0000E8
 *
 * Note: While this function accepts `void*`, it really expects `seqp_*`.
 */
static s32 Jaq_RootCallback(void* VOID_track)
{
	seqp_* track;

	track = (seqp_*)VOID_track;
	if (track && track->_3C != 0) {
		if (track->_3C == 3) {
			__StopSeq(track);
			return -1;
		}

		track->_330 += track->_334;
		if (track->_330 < 1.0f) {
			SeqUpdate(track, 0);
		} else {
			while (track->_330 >= 1.0f) {
				track->_330 -= 1.0f;
				if (Jam_SeqmainNote(track, 0) == -1) {
					__StopSeq(track);
					return -1;
				}
			}
			SeqUpdate(track, 0);
		}
	} else {
		return -1;
	}
	return 0;
}
