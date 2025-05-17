#include "types.h"
#include "jaudio/PikiBgm.h"
#include "jaudio/playercall.h"
#include "jaudio/file_seq.h"
#include "jaudio/seqsetup.h"
#include "jaudio/interface.h"
#include "jaudio/PikiScene.h"
#include "Dolphin/os.h"

// This struct might be something else entirely, not BgmControl
typedef struct BgmControl_ {
	int _00; // _00, BgmControl_* ?
	u8 _04[0x458];
	f32 _45C; // _45C
} BgmControl_;
BgmControl_ bgm[1]; // no idea how to handle this

int call_counter;
static int fadeouttime = 30;
u8* buffer[2];
int last_crossmode;
u8 lastside;
int bgm_semaphore;
int buffer_mus[2]   = { -1, -1 };
f32 game_bgm_volume = 1.0f;
int last_bgm_level  = -1;

f32 GAMEBGM_VOL_TABLE[]    = { 0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f };
u16 GAMEDEMO_VOL_TABLE[]   = { 0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 10000, 12000, 0 };
u16 GAMESE_VOL_TABLE[]     = { 0, 1000, 2000, 4000, 7000, 10000, 13000, 16000, 20000, 25000, 0x7fff };
u16 GAMESTREAM_VOL_TABLE[] = { 0, 600, 1000, 2000, 3000, 4000, 5000, 6000, 8000, 10000, 12000 };
/*
 * --INFO--
 * Address:	80018980
 * Size:	00003C
 */
s32 Jac_BgmFrameCallback(void* a1)
{
	call_counter += 1;
	if ((call_counter & 7) == 0) {
		Jac_BgmFrameWork();
	}
	return 0;
}

/*
 * --INFO--
 * Address:	800189C0
 * Size:	000180
 */
void Jac_InitBgm(void)
{
	for (int i = 0; i < 3; i++) {
		bgm[i]._00 = 0;
	}

	buffer[0] = (u8*)OSAlloc(0x8000);
	buffer[1] = (u8*)OSAlloc(0x8000);
	Jac_RegisterPlayerCallback(Jac_BgmFrameCallback, 0);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8036
	  stw       r0, 0x4(r1)
	  li        r6, 0
	  addi      r5, r3, 0x38E0
	  li        r4, -0x1
	  stwu      r1, -0x60(r1)
	  stmw      r28, 0x50(r1)
	  stw       r6, 0x4C(r1)
	  b         .loc_0x54

	.loc_0x28:
	  mulli     r0, r0, 0x468
	  add       r3, r5, r0
	  stw       r6, 0x0(r3)
	  stb       r6, 0xE(r3)
	  stb       r6, 0xF(r3)
	  stb       r6, 0x10(r3)
	  stb       r6, 0x11(r3)
	  stb       r4, 0xD(r3)
	  lwz       r3, 0x4C(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x4C(r1)

	.loc_0x54:
	  lwz       r0, 0x4C(r1)
	  cmplwi    r0, 0x3
	  blt+      .loc_0x28
	  lwz       r0, -0x7FA8(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x15C
	  lis       r3, 0x8022
	  li        r0, 0x2
	  addi      r3, r3, 0x2278
	  addi      r5, r1, 0x2C
	  subi      r4, r3, 0x8
	  mtctr     r0

	.loc_0x84:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r5)
	  stw       r0, 0x4(r5)
	  bdnz+     .loc_0x84
	  lwz       r4, 0x8(r4)
	  lis       r3, 0x8022
	  addi      r3, r3, 0x228C
	  li        r0, 0x2
	  stw       r4, 0x8(r5)
	  addi      r5, r1, 0x18
	  subi      r4, r3, 0x8
	  mtctr     r0

	.loc_0xB8:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r5)
	  stw       r0, 0x4(r5)
	  bdnz+     .loc_0xB8
	  lwz       r0, 0x8(r4)
	  li        r28, 0
	  addi      r31, r28, 0
	  addi      r30, r1, 0x34
	  stw       r0, 0x8(r5)

	.loc_0xE0:
	  lwzx      r29, r30, r31
	  mr        r3, r29
	  bl        0x2A18
	  stw       r3, 0x18(r1)
	  lwz       r3, 0x18(r1)
	  bl        -0x13334
	  stw       r3, 0x14(r1)
	  mr        r3, r29
	  lwz       r4, 0x14(r1)
	  bl        0x2A3C
	  cmplwi    r3, 0
	  beq-      .loc_0x12C
	  addi      r3, r1, 0x20
	  add       r3, r3, r31
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  beq-      .loc_0x12C
	  mr        r4, r29
	  bl        0x2BD8

	.loc_0x12C:
	  addi      r28, r28, 0x1
	  addi      r31, r31, 0x4
	  cmplwi    r28, 0x5
	  blt+      .loc_0xE0
	  lis       r31, 0x1
	  subi      r3, r31, 0x8000
	  bl        -0x13384
	  stw       r3, -0x7FA8(r13)
	  subi      r3, r31, 0x8000
	  bl        -0x13390
	  subi      r4, r13, 0x7FA8
	  stw       r3, 0x4(r4)

	.loc_0x15C:
	  lis       r3, 0x8002
	  li        r4, 0
	  subi      r3, r3, 0x7680
	  bl        -0x11908
	  lmw       r28, 0x50(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80018B40
 * Size:	00002C
 */
void Jac_FadeOutBgm(u32 flag, u32 fade)
{
	fadeouttime = fade;
	Jac_SetBgmModeFlag(flag, 8, 1);
}

/*
 * --INFO--
 * Address:	80018B80
 * Size:	000054
 */
void Jac_StopBgm(u32 id)
{
	if (bgm[id]._00) {
		Jaf_StopSeq((s8)bgm[id]._04[9]);
		bgm[id]._00 = 0;
	}
}

/*
 * --INFO--
 * Address:	80018BE0
 * Size:	0000A0
 */
void Jac_ReadyBgm(int id)
{
	u32 bgm = id;
	if (id < 2) {
		bgm = 2;
	}
	if (Jaf_CheckSeq(bgm) == 0) {
		if (buffer_mus[lastside] != -1) {
			Jaf_ClearSeq(buffer_mus[lastside]);
		}
		Jaf_LoadSeqA(bgm, buffer[lastside]);

		buffer_mus[lastside] = bgm;
		lastside             = 1 - lastside;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r3, 0x8(r1)
	  lwz       r0, 0x8(r1)
	  cmplwi    r0, 0x2
	  bge-      .loc_0x28
	  li        r0, 0x2
	  stw       r0, 0x8(r1)

	.loc_0x28:
	  lwz       r31, 0x8(r1)
	  mr        r3, r31
	  bl        0x29B0
	  cmplwi    r3, 0
	  bne-      .loc_0x8C
	  lbz       r0, 0x2CF8(r13)
	  subi      r3, r13, 0x7FA0
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  beq-      .loc_0x5C
	  bl        0x2968

	.loc_0x5C:
	  lbz       r0, 0x2CF8(r13)
	  subi      r4, r13, 0x7FA8
	  addi      r3, r31, 0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r4, r0
	  bl        0x2CD0
	  lbz       r0, 0x2CF8(r13)
	  subi      r3, r13, 0x7FA0
	  rlwinm    r4,r0,2,0,29
	  subfic    r0, r0, 0x1
	  stwx      r31, r3, r4
	  stb       r0, 0x2CF8(r13)

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
 * Address:	80018C80
 * Size:	000244
 */
void Jac_PlayBgm(int a, int b)
{
	Jac_SetProcessStatus(8);
	if (bgm[a]._00) {
		Jac_StopBgm(a);
	}

	// this is nearly just Jac_ReadyBgm again
	u32 id = b;
	if (b < 2) {
		id = 2;
	}
	int check = (int)Jaf_CheckSeq(id);
	if (check == 0) {
		if (buffer_mus[lastside] != -1) {
			Jaf_ClearSeq(buffer_mus[lastside]);
		}
		Jaf_LoadSeq(id, buffer[lastside]);

		buffer_mus[lastside] = id;
		lastside             = 1 - lastside;
	} else if (check == 1) {
		int stop = 1;
		while (stop == 1) {
			stop = (int)Jaf_CheckSeq(id);
		}
	}

	int* seq = Jaf_HandleToSeq(a + 3);

	bgm[a]._04[0]  = 1;
	bgm[a]._04[1]  = 1;
	int id2        = a + 3;
	bgm[a]._04[2]  = 0;
	bgm[a]._04[6]  = 0;
	bgm[a]._04[3]  = 0;
	bgm[a]._04[5]  = id - 2;
	bgm[a]._04[13] = id2;

	Jac_SetBgmModeFlag(a, 2, 0);
	Jac_SetBgmModeFlag(a, 1, 0);
	Jac_SetBgmModeFlag(a, 4, 0);
	Jac_SetBgmModeFlag(a, 8, 0);
	Jaf_ReadySeq(id2, id);
	Jac_BgmFrameWork();
	Jaq_SetBankNumber(Jaf_HandleToSeq(id2), id);
	bgm[a]._00 = 0;

	if (a == 0) {
		bgm[a]._45C = game_bgm_volume;
		Jam_MuteTrack(seq, 0);
		last_crossmode = 0;
	} else {
		bgm[a]._45C = game_bgm_volume;
		Jam_MuteTrack(seq, 1);
	}

	Jam_SetExtParam(bgm[a]._45C, seq, 1);
	Jam_OnExtSwitch(seq, 1);

	// Challenge mode tempo speedup?
	if (Jac_TellChgMode() == TRUE && Jac_GetCurrentScene() == 5) {
		Jam_OnExtSwitch(seq, 0x40);
		Jam_SetExtParam(1.2f, seq, 0x40);
	} else {
		Jam_OffExtSwitch(seq, 0x40);
	}
	seq[100] = 74; // this is some struct
	Jaf_PlaySeq(a + 3);
	Jac_SetProcessStatus(9);

	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8036
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r24, 0x28(r1)
	  addi      r27, r3, 0
	  addi      r31, r5, 0x38E0
	  li        r3, 0x8
	  stw       r4, 0xC(r1)
	  bl        -0x22E4
	  mulli     r28, r27, 0x468
	  add       r29, r31, r28
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0
	  beq-      .loc_0x44
	  mr        r3, r27
	  bl        -0x140

	.loc_0x44:
	  lwz       r0, 0xC(r1)
	  cmplwi    r0, 0x2
	  bge-      .loc_0x58
	  li        r0, 0x2
	  stw       r0, 0xC(r1)

	.loc_0x58:
	  lwz       r30, 0xC(r1)
	  mr        r3, r30
	  bl        0x28E0
	  cmplwi    r3, 0
	  bne-      .loc_0xC0
	  lbz       r0, 0x2CF8(r13)
	  subi      r3, r13, 0x7FA0
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  beq-      .loc_0x8C
	  bl        0x2898

	.loc_0x8C:
	  lbz       r0, 0x2CF8(r13)
	  subi      r4, r13, 0x7FA8
	  addi      r3, r30, 0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r4, r0
	  bl        0x27E0
	  lbz       r0, 0x2CF8(r13)
	  subi      r3, r13, 0x7FA0
	  rlwinm    r4,r0,2,0,29
	  subfic    r0, r0, 0x1
	  stwx      r30, r3, r4
	  stb       r0, 0x2CF8(r13)
	  b         .loc_0xDC

	.loc_0xC0:
	  cmplwi    r3, 0x1
	  bne-      .loc_0xDC
	  b         .loc_0xD4

	.loc_0xCC:
	  mr        r3, r30
	  bl        0x2870

	.loc_0xD4:
	  cmplwi    r3, 0x1
	  beq+      .loc_0xCC

	.loc_0xDC:
	  addi      r3, r27, 0x3
	  bl        0x2A20
	  li        r4, 0x1
	  addi      r24, r3, 0
	  stw       r4, 0x0(r29)
	  add       r25, r31, r28
	  li        r26, 0
	  subi      r0, r30, 0x2
	  stw       r4, 0x4(r25)
	  addi      r29, r27, 0x3
	  addi      r3, r27, 0
	  li        r4, 0x2
	  stw       r26, 0x8(r25)
	  li        r5, 0
	  stw       r26, 0x18(r25)
	  stb       r26, 0xC(r25)
	  stw       r0, 0x14(r25)
	  stb       r29, 0xD(r25)
	  bl        0x19C
	  addi      r3, r27, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        0x18C
	  addi      r3, r27, 0
	  li        r4, 0x4
	  li        r5, 0
	  bl        0x17C
	  addi      r3, r27, 0
	  li        r4, 0x8
	  li        r5, 0
	  bl        0x16C
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x2800
	  bl        0x21C
	  mr        r3, r29
	  bl        0x2994
	  rlwinm    r4,r30,0,24,31
	  bl        -0x4774
	  cmplwi    r27, 0
	  stw       r26, 0x464(r25)
	  bne-      .loc_0x1A0
	  lfs       f0, -0x7F94(r13)
	  addi      r3, r24, 0
	  li        r4, 0
	  stfs      f0, 0x45C(r25)
	  bl        -0x7A14
	  stw       r26, 0x2CFC(r13)
	  b         .loc_0x1B4

	.loc_0x1A0:
	  lfs       f0, -0x7E30(r2)
	  addi      r3, r24, 0
	  li        r4, 0x1
	  stfs      f0, 0x45C(r25)
	  bl        -0x7A30

	.loc_0x1B4:
	  add       r4, r31, r28
	  addi      r3, r24, 0
	  lfs       f1, 0x45C(r4)
	  li        r4, 0x1
	  bl        -0x8524
	  addi      r3, r24, 0
	  li        r4, 0x1
	  bl        -0x84F0
	  bl        0xA0C
	  cmpwi     r3, 0x1
	  bne-      .loc_0x20C
	  bl        0x9E0
	  cmplwi    r3, 0x5
	  bne-      .loc_0x20C
	  addi      r3, r24, 0
	  li        r4, 0x40
	  bl        -0x8514
	  lfs       f1, -0x7E2C(r2)
	  addi      r3, r24, 0
	  li        r4, 0x40
	  bl        -0x8564
	  b         .loc_0x218

	.loc_0x20C:
	  addi      r3, r24, 0
	  li        r4, 0x40
	  bl        -0x84F4

	.loc_0x218:
	  li        r0, 0x4A
	  addi      r3, r27, 0x3
	  stb       r0, 0x39D(r24)
	  bl        0x27DC
	  li        r3, 0x9
	  bl        -0x24EC
	  lmw       r24, 0x28(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80018EE0
 * Size:	000058
 */
BOOL Jac_ChangeBgmMode(int id, int type)
{
	if (type == bgm[id]._04[0]) {
		return;
	}

	if (bgm[id]._00) {
		bgm[id]._04[3] = type;
		bgm[id]._04[2] = 1;
		return FALSE;
	}

	return TRUE;
	/*
	.loc_0x0:
	  mulli     r6, r3, 0x468
	  lis       r3, 0x8036
	  addi      r5, r3, 0x38E0
	  rlwinm    r3,r4,0,24,31
	  add       r7, r5, r6
	  lbzu      r0, 0xC(r7)
	  cmplw     r3, r0
	  bne-      .loc_0x28
	  li        r3, 0
	  blr

	.loc_0x28:
	  lwzx      r0, r5, r6
	  cmpwi     r0, 0
	  beq-      .loc_0x48
	  stb       r4, 0x0(r7)
	  add       r3, r5, r6
	  li        r0, 0x1
	  stw       r0, 0x8(r3)
	  b         .loc_0x50

	.loc_0x48:
	  li        r3, 0
	  blr

	.loc_0x50:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80018F40
 * Size:	0000A8
 */
void Jac_SetBgmModeFlag(u32 a, u32 b, u32 c)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mulli     r6, r3, 0x468
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,0,24,31
	  lis       r4, 0x8036
	  addi      r4, r4, 0x38E0
	  cmpwi     r0, 0x4
	  stwu      r1, -0x8(r1)
	  add       r7, r4, r6
	  beq-      .loc_0x60
	  bge-      .loc_0x44
	  cmpwi     r0, 0x2
	  beq-      .loc_0x50
	  bge-      .loc_0x6C
	  cmpwi     r0, 0x1
	  bge-      .loc_0x58
	  b         .loc_0x6C

	.loc_0x44:
	  cmpwi     r0, 0x8
	  beq-      .loc_0x68
	  b         .loc_0x6C

	.loc_0x50:
	  stb       r5, 0xE(r7)
	  b         .loc_0x6C

	.loc_0x58:
	  stb       r5, 0xF(r7)
	  b         .loc_0x6C

	.loc_0x60:
	  stb       r5, 0x10(r7)
	  b         .loc_0x6C

	.loc_0x68:
	  stb       r5, 0x11(r7)

	.loc_0x6C:
	  lbz       r4, 0xE(r7)
	  lbz       r0, 0x10(r7)
	  lbz       r6, 0x11(r7)
	  rlwinm    r4,r4,1,0,30
	  rlwinm    r0,r0,2,0,29
	  lbz       r5, 0xF(r7)
	  rlwinm    r6,r6,3,0,28
	  add       r0, r4, r0
	  add       r4, r0, r6
	  add       r4, r5, r4
	  bl        -0xF4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019000
 * Size:	000124
 */
void Jac_BgmFrameWork(void)
{
	if (bgm_semaphore == 0) {
		bgm_semaphore = TRUE;

		for (int i = 0; i < 3; i++) {
			if (bgm[i]._00) {
				if (bgm[i]._04[0]) {
					Jac_ChangeBgmTrackVol(bgm[i]._00);
					continue;
				}
				if (bgm[i]._04[1]) {
					Jac_ChangeBgmTrackVol(bgm[i]._00);
					bgm[i]._04[1] = 0;
				}
				if (bgm[i]._04[12]) {
					Jac_MoveBgmTrackVol(bgm[i]._00);
				}
			}
		}

		bgm_semaphore = FALSE;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r27, 0xC(r1)
	  lwz       r0, 0x2D04(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x110
	  li        r0, 0x1
	  lis       r3, 0x8036
	  stw       r0, 0x2D04(r13)
	  addi      r29, r3, 0x38E0
	  li        r31, 0
	  li        r30, 0

	.loc_0x34:
	  add       r28, r29, r30
	  lwz       r0, 0x0(r28)
	  cmpwi     r0, 0
	  beq-      .loc_0xF8
	  lwz       r0, 0x4(r28)
	  cmpwi     r0, 0
	  beq-      .loc_0x5C
	  mr        r3, r28
	  bl        0x1AC
	  b         .loc_0xF8

	.loc_0x5C:
	  addi      r27, r28, 0x8
	  lwz       r0, 0x8(r28)
	  cmpwi     r0, 0
	  beq-      .loc_0x7C
	  mr        r3, r28
	  bl        0x190
	  li        r0, 0
	  stw       r0, 0x0(r27)

	.loc_0x7C:
	  lwz       r0, 0x18(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x90
	  mr        r3, r28
	  bl        0xB4

	.loc_0x90:
	  addi      r27, r28, 0x464
	  lwz       r0, 0x464(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0xF8
	  mr        r3, r28
	  bl        0x2DC
	  cmpwi     r3, 0
	  bne-      .loc_0xBC
	  li        r0, 0
	  stw       r0, 0x0(r27)
	  b         .loc_0xF8

	.loc_0xBC:
	  lwz       r3, 0x0(r27)
	  subi      r0, r3, 0x1
	  stw       r0, 0x0(r27)
	  lwz       r0, 0x0(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0xF8
	  lwz       r0, 0x2CFC(r13)
	  subfic    r0, r0, 0x1
	  cmplw     r0, r31
	  bne-      .loc_0xF8
	  lbz       r3, 0xD(r28)
	  extsb     r3, r3
	  bl        0x2694
	  li        r4, 0x1
	  bl        -0x7CF4

	.loc_0xF8:
	  addi      r31, r31, 0x1
	  addi      r30, r30, 0x468
	  cmplwi    r31, 0x3
	  blt+      .loc_0x34
	  li        r0, 0
	  stw       r0, 0x2D04(r13)

	.loc_0x110:
	  lmw       r27, 0xC(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019140
 * Size:	0000BC
 */
void Jac_MoveBgmTrackVol(int seq)
{
	Jaf_HandleToSeq(seq);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  lis       r0, 0x4330
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r27, r3, 0
	  lwz       r4, 0x18(r3)
	  lbz       r3, 0xD(r3)
	  stw       r4, 0x14(r1)
	  lfd       f1, -0x7E28(r2)
	  extsb     r3, r3
	  stw       r0, 0x10(r1)
	  lfd       f0, 0x10(r1)
	  fsubs     f31, f0, f1
	  bl        0x2604
	  cmplwi    r3, 0
	  beq-      .loc_0xA4
	  lwz       r4, 0x18(r27)
	  addi      r29, r3, 0
	  li        r28, 0
	  li        r31, 0
	  subi      r0, r4, 0x1
	  li        r30, 0
	  stw       r0, 0x18(r27)

	.loc_0x64:
	  addi      r3, r30, 0x41C
	  addi      r0, r31, 0x28
	  lfsx      f0, r27, r3
	  mr        r3, r29
	  lfsx      f1, r27, r0
	  rlwinm    r4,r28,0,24,31
	  li        r5, 0x1
	  fsubs     f0, f0, f1
	  fdivs     f0, f0, f31
	  fadds     f1, f1, f0
	  bl        -0x87EC
	  addi      r28, r28, 0x1
	  addi      r30, r30, 0x4
	  cmplwi    r28, 0x10
	  addi      r31, r31, 0x40
	  blt+      .loc_0x64

	.loc_0xA4:
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019200
 * Size:	00017C
 */
void Jac_ChangeBgmTrackVol(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  mr        r31, r3
	  lbz       r3, 0xD(r3)
	  extsb     r3, r3
	  bl        0x2564
	  cmplwi    r3, 0
	  beq-      .loc_0x168
	  lwz       r0, 0x14(r31)
	  lis       r5, 0x8022
	  lis       r4, 0x8022
	  addi      r5, r5, 0x6130
	  rlwinm    r6,r0,2,0,29
	  addi      r0, r4, 0x6180
	  add       r5, r5, r6
	  lbz       r8, 0xC(r31)
	  add       r4, r0, r6
	  lwz       r7, 0x0(r5)
	  lwz       r5, 0x0(r4)
	  rlwinm    r6,r8,1,29,30
	  rlwinm    r4,r8,0,29,29
	  rlwinm.   r0,r8,0,28,28
	  lhzx      r6, r7, r6
	  lfsx      f1, r5, r4
	  beq-      .loc_0x70
	  lfs       f1, -0x7E30(r2)

	.loc_0x70:
	  li        r0, 0x10
	  addi      r26, r3, 0
	  lfs       f0, -0x7E30(r2)
	  li        r4, 0
	  li        r3, 0
	  mtctr     r0

	.loc_0x88:
	  sraw      r0, r6, r4
	  rlwinm    r0,r0,0,31,31
	  cmpwi     r0, 0x1
	  beq-      .loc_0xB4
	  bge-      .loc_0xBC
	  cmpwi     r0, 0
	  bge-      .loc_0xA8
	  b         .loc_0xBC

	.loc_0xA8:
	  addi      r0, r3, 0x41C
	  stfsx     f0, r31, r0
	  b         .loc_0xBC

	.loc_0xB4:
	  addi      r0, r3, 0x41C
	  stfsx     f1, r31, r0

	.loc_0xBC:
	  addi      r4, r4, 0x1
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0x88
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x148
	  li        r27, 0
	  li        r30, 0
	  li        r29, 0

	.loc_0xE0:
	  addi      r28, r29, 0x1C
	  add       r28, r31, r28
	  addi      r3, r28, 0
	  bl        -0x8C2C
	  addi      r3, r26, 0
	  addi      r5, r28, 0
	  rlwinm    r4,r27,0,24,31
	  bl        -0x8BDC
	  addi      r0, r30, 0x41C
	  addi      r3, r26, 0
	  lfsx      f1, r31, r0
	  rlwinm    r4,r27,0,24,31
	  li        r5, 0x1
	  bl        -0x8934
	  addi      r3, r26, 0
	  rlwinm    r4,r27,0,24,31
	  li        r5, 0x1
	  bl        -0x8904
	  addi      r27, r27, 0x1
	  addi      r29, r29, 0x40
	  cmplwi    r27, 0x10
	  addi      r30, r30, 0x4
	  blt+      .loc_0xE0
	  li        r0, 0
	  stw       r0, 0x4(r31)
	  b         .loc_0x168

	.loc_0x148:
	  lbz       r0, 0xC(r31)
	  rlwinm.   r0,r0,0,28,28
	  beq-      .loc_0x160
	  lwz       r0, -0x7F98(r13)
	  stw       r0, 0x18(r31)
	  b         .loc_0x168

	.loc_0x160:
	  li        r0, 0x3C
	  stw       r0, 0x18(r31)

	.loc_0x168:
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019380
 * Size:	00008C
 */
void Jac_UpdateBgmCrossVol(BgmControl_* control)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  lis       r0, 0x4330
	  stwu      r1, -0x28(r1)
	  stfd      f31, 0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lwz       r4, 0x464(r3)
	  lbz       r3, 0xD(r3)
	  stw       r4, 0x14(r1)
	  lfd       f1, -0x7E28(r2)
	  extsb     r3, r3
	  stw       r0, 0x10(r1)
	  lfd       f0, 0x10(r1)
	  fsubs     f31, f0, f1
	  bl        0x23C4
	  lwz       r4, 0x2AC(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x54
	  li        r3, 0
	  b         .loc_0x74

	.loc_0x54:
	  lfs       f1, 0xC(r4)
	  li        r4, 0x1
	  lfs       f0, 0x45C(r31)
	  fsubs     f0, f0, f1
	  fdivs     f0, f0, f31
	  fadds     f1, f1, f0
	  bl        -0x8ACC
	  li        r3, 0x1

	.loc_0x74:
	  lwz       r0, 0x2C(r1)
	  lfd       f31, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019420
 * Size:	0000C4
 */
void Jac_GameVolume(u8 bgmVol, u8 seVol)
{
	game_bgm_volume = GAMEBGM_VOL_TABLE[bgmVol];
	if (last_bgm_level != bgmVol) {
		Jac_EasyCrossFade(2, 10);
	}

	last_bgm_level = bgmVol;
	Jam_WritePortAppDirect(Jam_GetTrackHandle(0x30000), 2, GAMEDEMO_VOL_TABLE[bgmVol]);
	Jac_SetStreamLevel(GAMESTREAM_VOL_TABLE[bgmVol], GAMESTREAM_VOL_TABLE[bgmVol]);
	Jam_WritePortAppDirect(Jam_GetTrackHandle(0x10000), 0, GAMESE_VOL_TABLE[seVol]);
	Jam_WritePortAppDirect(Jam_GetTrackHandle(0x20000), 0, GAMESE_VOL_TABLE[seVol]);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r28, 0x10(r1)
	  addi      r29, r3, 0
	  lis       r3, 0x8022
	  rlwinm    r31,r29,0,24,31
	  addi      r30, r3, 0x6130
	  rlwinm    r3,r29,2,22,29
	  add       r3, r30, r3
	  mr        r28, r4
	  lbz       r0, -0x7F28(r13)
	  lfs       f0, 0xA0(r3)
	  cmplw     r0, r31
	  stfs      f0, -0x7F94(r13)
	  beq-      .loc_0x4C
	  li        r3, 0x2
	  li        r4, 0xA
	  bl        0x98

	.loc_0x4C:
	  rlwinm    r0,r31,1,0,30
	  stb       r29, -0x7F28(r13)
	  add       r31, r30, r0
	  lis       r3, 0x3
	  lhz       r29, 0xCC(r31)
	  bl        -0x8E20
	  addi      r5, r29, 0
	  li        r4, 0x2
	  bl        -0x910C
	  rlwinm    r0,r28,1,23,30
	  lhz       r3, 0xFC(r31)
	  add       r31, r30, r0
	  lhz       r4, 0xFC(r31)
	  bl        0x940
	  lhz       r30, 0xE4(r31)
	  lis       r3, 0x1
	  bl        -0x8E4C
	  addi      r5, r30, 0
	  li        r4, 0
	  bl        -0x9138
	  lis       r3, 0x2
	  bl        -0x8E60
	  addi      r5, r30, 0
	  li        r4, 0
	  bl        -0x914C
	  lmw       r28, 0x10(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019500
 * Size:	0000E4
 */
void Jac_EasyCrossFade(u32 type, u32 val)
{
	switch (type) {
	case 0:
		/* code */
		break;
	case 1:
		break;
	case 2:
		break;
	}

	last_crossmode = type;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r30, 0x18(r1)
	  stb       r3, 0x8(r1)
	  lis       r3, 0x8036
	  addi      r31, r3, 0x38E0
	  lbz       r30, 0x8(r1)
	  stw       r4, 0xC(r1)
	  cmpwi     r30, 0x1
	  beq-      .loc_0x78
	  bge-      .loc_0x3C
	  cmpwi     r30, 0
	  bge-      .loc_0x48
	  b         .loc_0xC0

	.loc_0x3C:
	  cmpwi     r30, 0x3
	  bge-      .loc_0xC0
	  b         .loc_0xA0

	.loc_0x48:
	  lfs       f0, -0x7F94(r13)
	  stfs      f0, 0x45C(r31)
	  lfs       f0, -0x7E30(r2)
	  stfs      f0, 0x8C4(r31)
	  lbz       r3, 0xD(r31)
	  extsb     r3, r3
	  bl        0x2220
	  li        r4, 0
	  bl        -0x8168
	  li        r0, 0
	  stw       r0, 0x2CFC(r13)
	  b         .loc_0xC0

	.loc_0x78:
	  lfs       f0, -0x7F94(r13)
	  stfs      f0, 0x8C4(r31)
	  lfs       f0, -0x7E30(r2)
	  stfs      f0, 0x45C(r31)
	  lbz       r3, 0x475(r31)
	  extsb     r3, r3
	  bl        0x21F0
	  li        r4, 0
	  bl        -0x8198
	  b         .loc_0xC0

	.loc_0xA0:
	  lwz       r0, 0x2CFC(r13)
	  lfs       f0, -0x7F94(r13)
	  mulli     r0, r0, 0x468
	  add       r3, r31, r0
	  stfs      f0, 0x45C(r3)
	  lwz       r0, 0xC(r1)
	  stw       r0, 0x464(r3)
	  b         .loc_0xD0

	.loc_0xC0:
	  lwz       r0, 0xC(r1)
	  stw       r0, 0x464(r31)
	  stw       r0, 0x8CC(r31)
	  stw       r30, 0x2CFC(r13)

	.loc_0xD0:
	  lwz       r0, 0x24(r1)
	  lmw       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019600
 * Size:	0000C8
 */
void Jac_DemoFade(f32, int, int)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  stb       r3, 0x8(r1)
	  lis       r3, 0x8036
	  addi      r3, r3, 0x38E0
	  lbz       r0, 0x8(r1)
	  stw       r4, 0xC(r1)
	  cmpwi     r0, 0x2
	  stfs      f1, 0x10(r1)
	  beq-      .loc_0x88
	  bge-      .loc_0x38
	  cmpwi     r0, 0
	  beq-      .loc_0x44
	  bge-      .loc_0x58
	  b         .loc_0xB4

	.loc_0x38:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xB4
	  b         .loc_0xA8

	.loc_0x44:
	  lfs       f0, 0x460(r3)
	  stfs      f0, 0x45C(r3)
	  lfs       f0, 0x8C8(r3)
	  stfs      f0, 0x8C4(r3)
	  b         .loc_0xB4

	.loc_0x58:
	  lfs       f0, 0x45C(r3)
	  stfs      f0, 0x460(r3)
	  lfs       f0, 0x8C4(r3)
	  stfs      f0, 0x8C8(r3)
	  lfs       f1, 0x10(r1)
	  lfs       f0, 0x45C(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x45C(r3)
	  lfs       f0, 0x8C4(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x8C4(r3)
	  b         .loc_0xB4

	.loc_0x88:
	  lfs       f1, 0x10(r1)
	  lfs       f0, 0x460(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x45C(r3)
	  lfs       f0, 0x8C8(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x8C4(r3)
	  b         .loc_0xB4

	.loc_0xA8:
	  lfs       f0, 0x10(r1)
	  stfs      f0, 0x45C(r3)
	  stfs      f0, 0x8C4(r3)

	.loc_0xB4:
	  lwz       r0, 0xC(r1)
	  stw       r0, 0x464(r3)
	  stw       r0, 0x8CC(r3)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800196E0
 * Size:	000028
 */
void Jac_EnterBossMode(void)
{
	Jac_EasyCrossFade(1, 100);
}

/*
 * --INFO--
 * Address:	80019720
 * Size:	000028
 */
void Jac_ExitBossMode(void)
{
	Jac_EasyCrossFade(0, 100);
}
