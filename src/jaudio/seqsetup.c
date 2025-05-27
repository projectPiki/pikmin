#include "jaudio/seqsetup.h"

#include "jaudio/jammain_2.h"
#include "jaudio/noteon.h"
#include "jaudio/fat.h"
#include "jaudio/playercall.h"
#include "jaudio/jamosc.h"
#include "jaudio/driverinterface.h"

#define SEQ_SIZE             (256)
#define ROOT_OUTER_SIZE      (256)
#define ROOTSEQ_SIZE         (16)
#define FREE_SEQP_QUEUE_SIZE (256)

static seqp_ seq[SEQ_SIZE];
static seqp_* ROOT_OUTER[ROOT_OUTER_SIZE]; // TODO: Just a guess
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
	track->_08  = 0;
	track->_D0  = 0;
	track->_8C  = 0;
	track->_3C  = 1;
	track->_40  = otherSeq;
	track->_3A6 = 0;
	track->_3A4 = 0;
	track->_3D0 = 0;

	for (i = 0; i < 18; ++i) {
		track->_14C[i]._08 = 0.0f;
		track->_14C[i]._00 = 1.0f;
		track->_14C[i]._04 = 1.0f;
	}

	track->_14C[1]._00 = 0.0f;
	track->_14C[1]._04 = 0.0f;
	track->_14C[1]._00 = 0.0f; // Just to be sure.
	track->_14C[1]._04 = 0.0f; // Just to be sure.
	track->_14C[3]._00 = 0.5f;
	track->_14C[3]._04 = 0.5f;

	track->_14C[16]._00 = 0.5f;
	track->_14C[16]._04 = 0.5f;
	track->_14C[17]._00 = 0.0f;
	track->_14C[17]._04 = 0.0f;

	track->_14C[2]._00 = 0.0f;
	track->_14C[2]._04 = 0.0f;
	track->_14C[4]._00 = 0.0f;
	track->_14C[4]._04 = 0.0f;

	// Initialize 13 through 15.
	for (i = 1; i < 4; ++i) {
		track->_14C[i + 12]._00 = 0.0f;
		track->_14C[i + 12]._04 = 0.0f;
	}

	track->_14C[5]._00 = 0.0f;
	track->_14C[5]._04 = 0.0f;

	for (i = 0; i < 32; ++i) {
		track->_26C[i] = 0;
	}

	if ((track->_3F & 2) || !track->_40) {
		track->_26C[8]  = 0;
		track->_26C[9]  = 1;
		track->_26C[10] = 1;
		track->_26C[11] = 0x7fff;
		track->_26C[12] = 0x4000;
		for (i = 0; i < 3; ++i) {
			track->_3DC[i]    = 2;
			track->_3DF[i]    = 2;
			track->_D8._62[i] = 26;
		}
		track->_26C[6]  = 0xf0;
		track->_26C[7]  = 0x0c;
		track->_26C[13] = 0x40;
	} else {
		// Initialize 8 through 12.
		for (i = 0; i < 5; ++i) {
			track->_26C[i + 8] = track->_40->_26C[i + 8];
		}
		track->_26C[6]  = track->_40->_26C[6];
		track->_26C[7]  = track->_40->_26C[7];
		track->_26C[13] = track->_40->_26C[13];
		for (i = 0; i < 3; ++i) {
			track->_3DC[i]    = track->_40->_3DC[i];
			track->_3DF[i]    = track->_40->_3DF[i];
			track->_D8._62[i] = track->_40->_D8._62[i];
		}
	}

	for (i = 0; i < 16; ++i) {
		track->_2B0[i] = NULL;
		track->_44[i]  = 0;
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
		track->_2F0[i].cmdImport = 0;
		track->_2F0[i].cmdExport = 0;
	}

	track->_3E2 = 0;
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
unknown Jaq_SetSeqData(seqp_* param_1, u8* param_2, u32 param_3, unknown param_4)
{
	return Jaq_SetSeqData_Limit(param_1, param_2, param_3, param_4, 0);
}

/*
 * --INFO--
 * Address:	80014500
 * Size:	000170
 */
unknown Jaq_SetSeqData_Limit(seqp_*, u8*, u32, unknown, unknown)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r25, 0x24(r1)
	  mr.       r25, r3
	  addi      r26, r4, 0
	  addi      r27, r5, 0
	  addi      r28, r6, 0
	  addi      r29, r7, 0
	  bne-      .loc_0x54
	  bl        0x1E4A54
	  mr        r30, r3
	  bl        -0x650
	  addi      r0, r3, 0
	  addi      r3, r30, 0
	  mr        r25, r0
	  bl        0x1E4A64
	  cmplwi    r25, 0
	  bne-      .loc_0x5C
	  li        r3, -0x1
	  b         .loc_0x15C

	.loc_0x54:
	  li        r0, 0
	  stb       r0, 0x3E4(r25)

	.loc_0x5C:
	  mr        r3, r25
	  bl        -0x600
	  addi      r30, r3, 0
	  cmpwi     r30, -0x1
	  bne-      .loc_0x78
	  li        r3, -0x1
	  b         .loc_0x15C

	.loc_0x78:
	  cmpwi     r28, 0x1
	  stb       r28, 0x3D(r25)
	  beq-      .loc_0xA8
	  bge-      .loc_0x94
	  cmpwi     r28, 0
	  bge-      .loc_0xA0
	  b         .loc_0xEC

	.loc_0x94:
	  cmpwi     r28, 0x3
	  bge-      .loc_0xEC
	  b         .loc_0xE4

	.loc_0xA0:
	  mr        r31, r26
	  b         .loc_0xEC

	.loc_0xA8:
	  mr        r3, r27
	  bl        -0x66AC
	  stb       r3, 0x3E(r25)
	  lbz       r4, 0x3E(r25)
	  addis     r0, r4, 0
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0xCC
	  li        r3, -0x1
	  b         .loc_0x15C

	.loc_0xCC:
	  addi      r3, r26, 0
	  addi      r6, r27, 0
	  li        r5, 0
	  bl        -0x63B8
	  li        r31, 0
	  b         .loc_0xEC

	.loc_0xE4:
	  li        r31, 0
	  stb       r26, 0x3E(r25)

	.loc_0xEC:
	  stw       r30, 0x88(r25)
	  li        r0, 0x3
	  addi      r3, r25, 0
	  addi      r4, r31, 0
	  stb       r0, 0x3F(r25)
	  li        r5, 0
	  bl        -0x5C4
	  lis       r3, 0x8036
	  rlwinm    r4,r30,6,0,25
	  addi      r0, r3, 0x2EA0
	  add       r31, r0, r4
	  addi      r3, r31, 0
	  bl        -0x3F5C
	  addi      r3, r25, 0
	  addi      r4, r31, 0
	  bl        -0x3F48
	  addi      r3, r25, 0xD8
	  rlwinm    r4,r29,0,24,31
	  bl        0x158C
	  lfs       f0, -0x7ED8(r2)
	  mr        r3, r25
	  stfs      f0, 0x330(r25)
	  lfs       f0, -0x7ED4(r2)
	  stfs      f0, 0x334(r25)
	  bl        -0x3B6C
	  li        r0, 0x2
	  addi      r3, r30, 0
	  stb       r0, 0x3C(r25)

	.loc_0x15C:
	  lmw       r25, 0x24(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
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
	lo = track->_26C[6] & 0xFF;
	if (!track) {
		return FALSE;
	}
	track->_26C[6] = (bankNum << 8) | lo;
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
void Jaq_OpenTrack(seqp_*, unknown, unknown)
{
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm.   r6,r4,0,26,26
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,0,28,31
	  stwu      r1, -0x40(r1)
	  stmw      r25, 0x24(r1)
	  addi      r27, r3, 0
	  addi      r25, r5, 0
	  rlwinm    r28,r4,26,30,31
	  stb       r0, 0x18(r1)
	  beq-      .loc_0x30
	  li        r28, 0x4

	.loc_0x30:
	  rlwinm.   r0,r6,0,24,31
	  beq-      .loc_0x48
	  mr        r3, r27
	  lbz       r4, 0x18(r1)
	  bl        -0x4720
	  stb       r3, 0x18(r1)

	.loc_0x48:
	  lbz       r31, 0x18(r1)
	  cmplwi    r31, 0x10
	  blt-      .loc_0x5C
	  li        r3, -0x1
	  b         .loc_0x138

	.loc_0x5C:
	  rlwinm    r30,r31,2,0,29
	  add       r26, r27, r30
	  lwzu      r0, 0x44(r26)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x78
	  bl        0x1AC

	.loc_0x78:
	  bl        -0x918
	  mr.       r29, r3
	  bne-      .loc_0x8C
	  li        r3, -0x1
	  b         .loc_0x138

	.loc_0x8C:
	  stw       r29, 0x0(r26)
	  li        r0, 0
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  lwz       r7, 0x88(r27)
	  addi      r5, r27, 0
	  rlwinm    r6,r7,4,0,27
	  rlwinm    r7,r7,0,0,3
	  or        r6, r6, r31
	  addis     r7, r7, 0x1000
	  rlwinm    r6,r6,0,4,31
	  or        r6, r7, r6
	  stw       r6, 0x88(r29)
	  stw       r0, 0x84(r29)
	  lbz       r0, 0x3D(r27)
	  stb       r0, 0x3D(r29)
	  stb       r28, 0x3F(r29)
	  bl        -0x810
	  lwz       r4, 0x40(r29)
	  li        r0, 0x1
	  slw       r0, r0, r31
	  lhz       r3, 0x3A0(r4)
	  lbz       r4, 0x39E(r4)
	  and       r0, r3, r0
	  sraw      r0, r0, r31
	  or        r0, r4, r0
	  stb       r0, 0x39E(r29)
	  lwz       r0, 0x40(r29)
	  add       r3, r0, r30
	  lwz       r0, 0x2B0(r3)
	  stw       r0, 0x2AC(r29)
	  lwz       r4, 0x2AC(r29)
	  cmplwi    r4, 0
	  beq-      .loc_0x120
	  lwz       r3, 0x4(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x4(r4)

	.loc_0x120:
	  addi      r3, r29, 0xD8
	  li        r4, 0
	  bl        0x1318
	  mr        r3, r29
	  bl        -0x3DD0
	  li        r3, 0

	.loc_0x138:
	  lmw       r25, 0x24(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800148E0
 * Size:	0000B4
 */
void __AllNoteOff(seqp_* track)
{
	u32 i;

	if (!track->_40) {
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
		if (track->_44[i]) {
			Jaq_CloseTrack(track->_44[i]);
			track->_44[i] = NULL;
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
	if (track->_40) {
		FixMoveChannelAll(&track->_D8, &track->_40->_D8);
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
