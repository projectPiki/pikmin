#include "jaudio/seqsetup.h"

#include "jaudio/jammain_2.h"
#include "jaudio/noteon.h"
#include "jaudio/fat.h"
#include "jaudio/playercall.h"
#include "jaudio/jamosc.h"

#define ROOT_OUTER_SIZE      (256)
#define ROOTSEQ_SIZE         (16)
#define FREE_SEQP_QUEUE_SIZE (256)

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
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  lis       r3, 0x8032
	  subi      r10, r3, 0x560
	  li        r0, 0x100
	  stwu      r1, -0x8(r1)
	  addi      r9, r4, 0
	  addi      r8, r4, 0
	  addi      r7, r4, 0
	  addis     r6, r10, 0x4
	  li        r3, 0
	  mtctr     r0

	.loc_0x34:
	  add       r11, r10, r4
	  add       r5, r6, r3
	  stb       r9, 0x3C(r11)
	  addi      r3, r3, 0x4
	  addi      r4, r4, 0x434
	  sth       r8, 0x3A0(r11)
	  stb       r7, 0x39E(r11)
	  stw       r11, 0x3840(r5)
	  bdnz+     .loc_0x34
	  li        r6, 0
	  li        r4, 0x100
	  li        r0, 0x10
	  stw       r6, 0x2C38(r13)
	  addis     r5, r10, 0x4
	  li        r3, 0
	  stw       r6, 0x2C3C(r13)
	  stw       r4, 0x2C40(r13)
	  mtctr     r0

	.loc_0x7C:
	  add       r4, r5, r3
	  addi      r3, r3, 0x4
	  stw       r6, 0x3800(r4)
	  bdnz+     .loc_0x7C
	  bl        -0x396C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
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
static BOOL BackTrack(seqp_* seq)
{
	seqp_** REF_seq;

	REF_seq  = &seq;
	seq->_3C = 0;
	if (seq->_3E4 == 1) {
		if (SEQ_REMAIN == FREE_SEQP_QUEUE_SIZE) {
			return FALSE;
		}

		FREE_SEQP_QUEUE[BACK_P] = seq;
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
	seqp_* seq;

	if (SEQ_REMAIN == 0) {
		return NULL;
	}

	seq = FREE_SEQP_QUEUE[GET_P];
	++GET_P;
	--SEQ_REMAIN;

	if (GET_P == FREE_SEQP_QUEUE_SIZE) {
		GET_P = 0;
	}

	seq->_3C  = 2;
	seq->_3E4 = 1;
	return seq;
}

/*
 * --INFO--
 * Address:	80013F60
 * Size:	000048
 */
int AllocNewRoot(seqp_* seq)
{
	int i;

	for (i = 0; i < ROOTSEQ_SIZE; ++i) {
		if (!rootseq[i]) {
			rootseq[i] = seq;
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
int DeAllocRoot(seqp_* seq)
{
	int i;

	for (i = 0; i < ROOTSEQ_SIZE; ++i) {
		if (rootseq[i] == seq) {
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
static void Init_Track(seqp_* seq, u32 param_2, seqp_* otherSeq)
{
	int i;

	if (!otherSeq) {
		seq->_00  = (u8*)param_2;
		seq->_04  = 0;
		seq->_33A = 0x78;
		seq->_338 = 0x30;
		seq->_33C = 1;
		seq->_39C = 0;
		seq->_39D = 10;
		seq->_3A0 = 0;
		seq->_39E = 0;
	} else {
		seq->_00  = otherSeq->_00;
		seq->_04  = param_2;
		seq->_3E  = otherSeq->_3E;
		seq->_33A = otherSeq->_33A;
		seq->_3E3 = 0;
		seq->_334 = otherSeq->_334;
		seq->_338 = otherSeq->_338;
		seq->_33C = otherSeq->_33C;
		seq->_39C = otherSeq->_39C;
		seq->_39D = otherSeq->_39D;
		seq->_3A0 = 0;
	}
	seq->_08  = 0;
	seq->_D0  = 0;
	seq->_8C  = 0;
	seq->_3C  = 1;
	seq->_40  = otherSeq;
	seq->_3A6 = 0;
	seq->_3A4 = 0;
	seq->_3D0 = 0;

	for (i = 0; i < 18; ++i) {
		seq->_14C[i]._08 = 0.0f;
		seq->_14C[i]._00 = 1.0f;
		seq->_14C[i]._04 = 1.0f;
	}

	seq->_14C[1]._00 = 0.0f;
	seq->_14C[1]._04 = 0.0f;
	seq->_14C[1]._00 = 0.0f; // Just to be sure.
	seq->_14C[1]._04 = 0.0f; // Just to be sure.
	seq->_14C[3]._00 = 0.5f;
	seq->_14C[3]._04 = 0.5f;

	seq->_14C[16]._00 = 0.5f;
	seq->_14C[16]._04 = 0.5f;
	seq->_14C[17]._00 = 0.0f;
	seq->_14C[17]._04 = 0.0f;

	seq->_14C[2]._00 = 0.0f;
	seq->_14C[2]._04 = 0.0f;
	seq->_14C[4]._00 = 0.0f;
	seq->_14C[4]._04 = 0.0f;

	// Initialize 13 through 15.
	for (i = 1; i < 4; ++i) {
		seq->_14C[i + 12]._00 = 0.0f;
		seq->_14C[i + 12]._04 = 0.0f;
	}

	seq->_14C[5]._00 = 0.0f;
	seq->_14C[5]._04 = 0.0f;

	for (i = 0; i < 32; ++i) {
		seq->_26C[i] = 0;
	}

	if ((seq->_3F & 2) || !seq->_40) {
		seq->_26C[8]  = 0;
		seq->_26C[9]  = 1;
		seq->_26C[10] = 1;
		seq->_26C[11] = 0x7fff;
		seq->_26C[12] = 0x4000;
		for (i = 0; i < 3; ++i) {
			seq->_3DC[i]    = 2;
			seq->_3DF[i]    = 2;
			seq->_D8._62[i] = 26;
		}
		seq->_26C[6]  = 0xf0;
		seq->_26C[7]  = 0x0c;
		seq->_26C[13] = 0x40;
	} else {
		// Initialize 8 through 12.
		for (i = 0; i < 5; ++i) {
			seq->_26C[i + 8] = seq->_40->_26C[i + 8];
		}
		seq->_26C[6]  = seq->_40->_26C[6];
		seq->_26C[7]  = seq->_40->_26C[7];
		seq->_26C[13] = seq->_40->_26C[13];
		for (i = 0; i < 3; ++i) {
			seq->_3DC[i]    = seq->_40->_3DC[i];
			seq->_3DF[i]    = seq->_40->_3DF[i];
			seq->_D8._62[i] = seq->_40->_D8._62[i];
		}
	}

	for (i = 0; i < 16; ++i) {
		seq->_2B0[i] = 0;
		seq->_44[i]  = 0;
	}

	for (i = 0; i < 8; ++i) {
		seq->_94[i] = -1;
		seq->_9C[i] = NULL;
		seq->_BC[i] = 0;
	}
	seq->_D4 = 0;
	seq->_D5 = 0;
	seq->_90 = 0;
	seq->_D6 = 0;
	Osc_Init_Env(seq);
	seq->_396 = 0;
	seq->_397 = 0;
	seq->_398 = -1;

	for (i = 0; i < 16; ++i) {
		seq->_2F0[i].cmdImport = 0;
		seq->_2F0[i].cmdExport = 0;
	}

	seq->_3E2 = 0;
}

/*
 * --INFO--
 * Address:	800143C0
 * Size:	0000A0
 */
BOOL Jaq_StopSeq(u32 index)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r3, -0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x8C

	.loc_0x20:
	  lis       r4, 0x8036
	  rlwinm    r3,r3,2,0,29
	  addi      r0, r4, 0x32A0
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  mr        r31, r0
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x8C

	.loc_0x48:
	  lbz       r0, 0x3C(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x80
	  bge-      .loc_0x64
	  cmpwi     r0, 0
	  bge-      .loc_0x88
	  b         .loc_0x80

	.loc_0x64:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x80
	  mr        r3, r31
	  bl        -0x5F0
	  mr        r3, r31
	  bl        -0x478
	  b         .loc_0x88

	.loc_0x80:
	  li        r0, 0x3
	  stb       r0, 0x3C(r31)

	.loc_0x88:
	  li        r3, 0x1

	.loc_0x8C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014460
 * Size:	000054
 */
static void __StopSeq(seqp_* seq)
{
	SeqUpdate(seq, 0);
	Jaq_CloseTrack(seq);
	DeAllocRoot(seq);
	if (seq->_3D == 1) {
		FAT_FreeMemory(seq->_3E);
	}
}

/*
 * --INFO--
 * Address:	800144C0
 * Size:	000024
 */
unknown Jaq_SetSeqData(unknown param_1, u8* param_2, u32 param_3, unknown param_4)
{
	return Jaq_SetSeqData_Limit(param_1, param_2, param_3, param_4, 0);
}

/*
 * --INFO--
 * Address:	80014500
 * Size:	000170
 */
unknown Jaq_SetSeqData_Limit(unknown, u8*, u32, unknown, unknown)
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
void Jaq_SetBankNumber(int*, u8)
{
	/*
	.loc_0x0:
	  lhz       r0, 0x278(r3)
	  cmplwi    r3, 0
	  rlwinm    r5,r0,0,24,31
	  bne-      .loc_0x18
	  li        r3, 0
	  blr

	.loc_0x18:
	  rlwinm    r0,r4,8,16,23
	  or        r0, r0, r5
	  sth       r0, 0x278(r3)
	  li        r3, 0x1
	  blr
	*/
}

static s32 Jaq_RootCallback(void*);

/*
 * --INFO--
 * Address:	800146C0
 * Size:	0000B4
 */
BOOL Jaq_StartSeq(u32 param_1)
{
	seqp_* seq;
	u8* lbzu;

	if (param_1 == -1) {
		return FALSE;
	}

	seq = rootseq[param_1];
	if (!seq) {
		return FALSE;
	};

	// This feels like a fakematch, but oh well.
	switch (*(lbzu = &seq->_3C)) {
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
void __AllNoteOff(seqp_* seq)
{
	u32 i;

	if (!seq->_40) {
		for (i = 0; i < 8; ++i) {
			NoteOFF_R(seq, i, 10);
			seq->_94[i] = -1;
			seq->_9C[i] = NULL;
		}
	} else {
		for (i = 0; i < 8; ++i) {
			NoteOFF(seq, i);
			seq->_94[i] = -1;
			seq->_9C[i] = NULL;
		}
	}
}

/*
 * --INFO--
 * Address:	800149A0
 * Size:	000120
 */
void Jaq_CloseTrack(seqp_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  mr.       r27, r3
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x10C

	.loc_0x20:
	  lbz       r0, 0x3C(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x10C

	.loc_0x34:
	  mr        r3, r27
	  bl        -0xF8
	  mr        r3, r27
	  bl        -0xBA0
	  li        r31, 0
	  li        r28, 0
	  addi      r30, r31, 0

	.loc_0x50:
	  addi      r29, r31, 0x44
	  add       r29, r27, r29
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x6C
	  bl        .loc_0x0
	  stw       r30, 0x0(r29)

	.loc_0x6C:
	  addi      r28, r28, 0x1
	  addi      r31, r31, 0x4
	  cmplwi    r28, 0x10
	  blt+      .loc_0x50
	  lwz       r4, 0x2AC(r27)
	  cmplwi    r4, 0
	  beq-      .loc_0x9C
	  lwz       r3, 0x4(r4)
	  li        r0, 0
	  subi      r3, r3, 0x1
	  stw       r3, 0x4(r4)
	  stw       r0, 0x2AC(r27)

	.loc_0x9C:
	  li        r0, 0x10
	  li        r6, 0
	  li        r3, 0
	  mtctr     r0

	.loc_0xAC:
	  addi      r5, r3, 0x2B0
	  add       r5, r27, r5
	  lwz       r4, 0x0(r5)
	  cmplwi    r4, 0
	  beq-      .loc_0xC8
	  stw       r6, 0x0(r4)
	  stw       r6, 0x0(r5)

	.loc_0xC8:
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0xAC
	  li        r0, 0
	  stb       r0, 0x39E(r27)
	  sth       r0, 0x3A0(r27)
	  lwz       r4, 0x40(r27)
	  cmplwi    r4, 0
	  beq-      .loc_0xF8
	  addi      r3, r27, 0xD8
	  addi      r4, r4, 0xD8
	  bl        -0xB2D0
	  b         .loc_0x100

	.loc_0xF8:
	  addi      r3, r27, 0xD8
	  bl        -0xB3DC

	.loc_0x100:
	  mr        r3, r27
	  bl        -0x44E4
	  li        r3, 0

	.loc_0x10C:
	  lmw       r27, 0x14(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014AC0
 * Size:	0000E8
 */
static s32 Jaq_RootCallback(void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stfd      f31, 0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0xC4
	  lbz       r0, 0x3C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xC4
	  cmplwi    r0, 0x3
	  bne-      .loc_0x44
	  mr        r3, r31
	  bl        -0x698
	  li        r3, -0x1
	  b         .loc_0xD0

	.loc_0x44:
	  lfs       f1, 0x330(r31)
	  lfs       f0, 0x334(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x330(r31)
	  lfs       f0, 0x330(r31)
	  lfs       f31, -0x7ED4(r2)
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0xA4
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x13AC
	  b         .loc_0xCC

	.loc_0x74:
	  lfs       f0, 0x330(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  fsubs     f0, f0, f31
	  stfs      f0, 0x330(r31)
	  bl        -0x1C88
	  cmpwi     r3, -0x1
	  bne-      .loc_0xA4
	  mr        r3, r31
	  bl        -0x6F8
	  li        r3, -0x1
	  b         .loc_0xD0

	.loc_0xA4:
	  lfs       f0, 0x330(r31)
	  fcmpo     cr0, f0, f31
	  cror      2, 0x1, 0x2
	  beq+      .loc_0x74
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x13FC
	  b         .loc_0xCC

	.loc_0xC4:
	  li        r3, -0x1
	  b         .loc_0xD0

	.loc_0xCC:
	  li        r3, 0

	.loc_0xD0:
	  lwz       r0, 0x24(r1)
	  lfd       f31, 0x18(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
