#include "jaudio/piki_bgm.h"

#include "jaudio/aictrl.h"
#include "jaudio/playercall.h"
#include "jaudio/file_seq.h"
#include "jaudio/seqsetup.h"
#include "jaudio/interface.h"
#include "jaudio/piki_scene.h"
#include "jaudio/jammain_2.h"
#include "Dolphin/os.h"

/**
 * @brief TODO
 *
 * @note Size: 0x468.
 */
typedef struct BgmControl_ {
	int _00;                     // _00
	int _04;                     // _04
	int _08;                     // _08
	u8 _0C;                      // _0C
	s8 trackHandle;              // _0D
	u8 _0E;                      // _0E
	u8 _0F;                      // _0F
	u8 _10;                      // _10
	u8 _11;                      // _11
	u32 _14;                     // _14
	u32 _18;                     // _18, unknown
	OuterParam_ trackParams[16]; // _1C
	f32 trackVolumes[16];        // _41C
	f32 _45C;                    // _45C, possibly gameVolume?
	f32 _460;                    // _460, possibly bossVolume?
	u32 _464;                    // _464, unknown
} BgmControl_;

static BgmControl_ bgm[3];

static u8 lastside;
static int last_crossmode;
static int call_counter;
static int bgm_semaphore;

static u8* buffer[2]       = { nullptr, nullptr };
static int buffer_mus[2]   = { -1, -1 };
static int fadeouttime     = 30;
static f32 game_bgm_volume = 1.0f;

static u16 bgm0_set[] = {
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
};
static u16 bgm1_set[] = {
	0x103C,
	0x17D8,
	0x8003,
	0x19C3,
};
static u16 bgm2_set[] = {
	0x33,
	0xF3,
	0x3C,
	0xFC,
};
static u16 bgm3_set[] = {
	0xC00F,
	0xF78D,
	0xC07C,
	0xFE2C,
};
static u16 bgm4_set[] = {
	0x47,
	0x297,
	0x2D,
	0x23D,
};
static u16 bgm5_set[] = {
	0x57D,
	0x5FB,
	0xA78,
	0xAFA,
};

static u16* bgm_mute_set[20] = {
	bgm0_set, bgm0_set, bgm1_set, bgm2_set, bgm0_set, bgm0_set, bgm0_set, bgm3_set, bgm4_set, bgm0_set,
	bgm0_set, bgm0_set, bgm0_set, bgm0_set, bgm0_set, bgm5_set, bgm0_set, bgm0_set, bgm0_set, bgm0_set,
};

static f32 bgm0_volset[] = {
	0.5f,
	0.15f,
};
static f32 bgm1_volset[] = {
	0.5f,
	0.15f,
};
static f32 bgm2_volset[] = {
	0.5f,
	0.15f,
};
static f32 bgm3_volset[] = {
	0.5f,
	0.15f,
};
static f32 bgm4_volset[] = {
	0.5f,
	0.15f,
};
static f32 bgm5_volset[] = {
	0.55f,
	0.15f,
};
static f32 cresult_volset[] = {
	0.35f,
	0.15f,
};

static f32* bgm_volume_set[20] = {
	bgm0_volset, bgm0_volset, bgm1_volset, bgm2_volset, bgm0_volset, bgm0_volset, bgm0_volset, bgm3_volset, bgm4_volset,    bgm0_volset,
	bgm0_volset, bgm0_volset, bgm0_volset, bgm0_volset, bgm0_volset, bgm5_volset, bgm0_volset, bgm0_volset, cresult_volset, bgm0_volset,
};

static f32 GAMEBGM_VOL_TABLE[]    = { 0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f };
static u16 GAMEDEMO_VOL_TABLE[]   = { 0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 10000, 12000 };
static u16 GAMESE_VOL_TABLE[]     = { 0, 1000, 2000, 4000, 7000, 10000, 13000, 16000, 20000, 25000, 0x7fff };
static u16 GAMESTREAM_VOL_TABLE[] = { 0, 600, 1000, 2000, 3000, 4000, 5000, 6000, 8000, 10000, 12000 };

static u8 last_bgm_level = 0xFF;

// forward declarations
static BOOL Jac_UpdateBgmCrossVol(BgmControl_* control);

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
	u32 i;
	for (i = 0; i < 3; i++) {
		bgm[i]._00         = 0;
		bgm[i]._0E         = 0;
		bgm[i]._0F         = 0;
		bgm[i]._10         = 0;
		bgm[i]._11         = 0;
		bgm[i].trackHandle = -1;
	}

	u32* REF_i = &i;

	if (!buffer[0]) {
		int vals1[5] = { 0, 1, 11, 13, 16 };
		int vals2[5] = { 0, 1, -1, 2, -1 };

		for (i = 0; i < 5; i++) {
			u32 size;
			u8* seqbuf;
			size            = Jaf_CheckSeqSize(vals1[i]);
			u32* REF_size   = &size;
			seqbuf          = (u8*)OSAlloc2(size);
			u8** REF_seqbuf = &seqbuf;
			u32 badCompiler;
			if ((u32)Jaf_LoadSeq(vals1[i], seqbuf) && vals2[i] != -1) {
				Jaf_StartSeq(vals2[i], vals1[i]);
			}
		}

		buffer[0] = (u8*)OSAlloc2(0x8000);
		buffer[1] = (u8*)OSAlloc2(0x8000);
	}
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
		Jaf_StopSeq(bgm[id].trackHandle);
		bgm[id]._00 = 0;
	}
}

/*
 * --INFO--
 * Address:	80018BE0
 * Size:	0000A0
 */
void Jac_ReadyBgm(u32 id)
{
	u32* REF_id = &id;
	if (id < 2) {
		id = 2;
	}
	if (Jaf_CheckSeq(id) == 0) {
		if (buffer_mus[lastside] != -1) {
			Jaf_ClearSeq(buffer_mus[lastside]);
		}
		Jaf_LoadSeqA(id, buffer[lastside]);

		buffer_mus[lastside] = id;
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
void Jac_PlayBgm(u32 a, u32 id)
{
	u32* REF_b = &id;
	Jac_SetProcessStatus(8);
	if (bgm[a]._00) {
		Jac_StopBgm(a);
	}

	// this is nearly just Jac_ReadyBgm again
	if (id < 2) {
		id = 2;
	}
	u32 check = (u32)Jaf_CheckSeq(id);
	if (check == 0) {
		if (buffer_mus[lastside] != -1) {
			Jaf_ClearSeq(buffer_mus[lastside]);
		}
		Jaf_LoadSeq(id, buffer[lastside]);

		buffer_mus[lastside] = id;
		lastside             = 1 - lastside;
	} else if (check == 1) {
		while (check == 1) {
			check = (u32)Jaf_CheckSeq(id);
		}
	}

	seqp_* track = Jaf_HandleToSeq(a + 3);

	bgm[a]._00         = 1;
	bgm[a]._04         = 1;
	int id2            = a + 3;
	bgm[a]._08         = 0;
	bgm[a]._18         = 0;
	bgm[a]._0C         = 0;
	bgm[a]._14         = id - 2;
	bgm[a].trackHandle = a + 3;

	Jac_SetBgmModeFlag(a, 2, 0);
	Jac_SetBgmModeFlag(a, 1, 0);
	Jac_SetBgmModeFlag(a, 4, 0);
	Jac_SetBgmModeFlag(a, 8, 0);
	Jaf_ReadySeq(id2, id);
	Jac_BgmFrameWork();
	Jaq_SetBankNumber(Jaf_HandleToSeq(id2), id);
	bgm[a]._464 = 0;

	if (a == 0) {
		bgm[a]._45C = game_bgm_volume;
		Jam_MuteTrack(track, 0);
		last_crossmode = 0;
	} else {
		bgm[a]._45C = 0.0f;
		Jam_MuteTrack(track, 1);
	}

	Jam_SetExtParam(bgm[a]._45C, track, 1);
	Jam_OnExtSwitch(track, 1);

	// Challenge mode tempo speedup?
	if (Jac_TellChgMode() == TRUE && Jac_GetCurrentScene() == 5) {
		Jam_OnExtSwitch(track, 0x40);
		Jam_SetExtParam(1.2f, track, 0x40);
	} else {
		Jam_OffExtSwitch(track, 0x40);
	}
	track->_39D = 74;
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
BOOL Jac_ChangeBgmMode(u32 id, u8 type)
{
	if (type == bgm[id]._0C) {
		return FALSE;
	}

	if (bgm[id]._00) {
		bgm[id]._0C = type;
		bgm[id]._08 = 1;
	} else {
		return FALSE;
	}

	return TRUE;
}

/*
 * --INFO--
 * Address:	80018F40
 * Size:	0000A8
 */
void Jac_SetBgmModeFlag(u32 a, u8 b, u8 c)
{
	BgmControl_* thisBgm = &bgm[a];
	switch (b) {
	case 2:
		thisBgm->_0E = c;
		break;
	case 1:
		thisBgm->_0F = c;
		break;
	case 4:
		thisBgm->_10 = c;
		break;
	case 8:
		thisBgm->_11 = c;
		break;
	}
	Jac_ChangeBgmMode(a, thisBgm->_0F + (thisBgm->_0E << 1) + (thisBgm->_10 << 2) + (thisBgm->_11 << 3));
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

		for (u32 i = 0; i < 3; i++) {
			if (!bgm[i]._00) {
				continue;
			}
			if (bgm[i]._04) {
				Jac_ChangeBgmTrackVol(&bgm[i]);
				continue;
			}
			if (bgm[i]._08) {
				Jac_ChangeBgmTrackVol(&bgm[i]);
				bgm[i]._08 = 0;
			}
			if (bgm[i]._18) {
				Jac_MoveBgmTrackVol(&bgm[i]);
			}

			if (bgm[i]._464) {
				if (!Jac_UpdateBgmCrossVol(&bgm[i])) {
					bgm[i]._464 = 0;
					continue;
				}
				bgm[i]._464--;

				if (bgm[i]._464 == 0 && 1 - last_crossmode == i) {
					Jam_MuteTrack(Jaf_HandleToSeq(bgm[i].trackHandle), 1);
				}
			}
		}

		bgm_semaphore = FALSE;
	}
}

/*
 * --INFO--
 * Address:	80019140
 * Size:	0000BC
 */
void Jac_MoveBgmTrackVol(BgmControl_* control)
{
	seqp_* track2;
	seqp_* track;
	u32 i;
	f32 a  = control->_18;
	track2 = Jaf_HandleToSeq(control->trackHandle);
	if (!track2) {
		return;
	}
	track = track2;
	control->_18--;

	for (i = 0; i < 16; i++) {
		f32 b = control->trackVolumes[i];
		Jam_SetExtParamP(control->trackParams[i]._0C + (b - control->trackParams[i]._0C) / a, track, i, 1);
	}
}

/*
 * --INFO--
 * Address:	80019200
 * Size:	00017C
 */
void Jac_ChangeBgmTrackVol(BgmControl_* control)
{
	u32 badCompiler[4];
	u32 i;
	seqp_* track2 = Jaf_HandleToSeq(control->trackHandle);
	if (!track2) {
		return;
	}

	u16 mute = bgm_mute_set[control->_14][control->_0C & 0x3];
	f32 vol  = bgm_volume_set[control->_14][(control->_0C >> 2) & 0x1];

	if (control->_0C & 0x8) {
		vol = 0.0f;
	}
	seqp_* track = track2;

	for (i = 0; i < 16; i++) {
		switch ((mute >> i) & 0x1) {
		case 0:
			control->trackVolumes[i] = 0.0f;
			break;

		case 1:
			control->trackVolumes[i] = vol;
			break;
		}
	}

	if (control->_04) {
		for (i = 0; i < 16; i++) {
			Jam_InitExtBuffer(&control->trackParams[i]);
			Jam_AssignExtBufferP(track, i, &control->trackParams[i]);
			Jam_SetExtParamP(control->trackVolumes[i], track, i, 1);
			Jam_OnExtSwitchP(track, i, 1);
		}
		control->_04 = 0;
	} else if (control->_0C & 0x8) {
		control->_18 = fadeouttime;
	} else {
		control->_18 = 60;
	}
}

/*
 * --INFO--
 * Address:	80019380
 * Size:	00008C
 */
static BOOL Jac_UpdateBgmCrossVol(BgmControl_* control)
{
	f32 a        = control->_464;
	seqp_* track = Jaf_HandleToSeq(control->trackHandle);

	if (!track->_2AC) {
		return FALSE;
	}

	Jam_SetExtParam(track->_2AC->_0C + (control->_45C - track->_2AC->_0C) / a, track, 1);
	return TRUE;
}

/*
 * --INFO--
 * Address:	80019420
 * Size:	0000C4
 */
void Jac_GameVolume(u8 bgmVol, u8 seVol)
{
	u16 tmpSeVol;
	u16 tmpDemoVol;
	game_bgm_volume = GAMEBGM_VOL_TABLE[bgmVol];
	if (last_bgm_level != bgmVol) {
		Jac_EasyCrossFade(2, 10);
	}

	last_bgm_level = bgmVol;
	tmpDemoVol     = GAMEDEMO_VOL_TABLE[bgmVol];
	Jam_WritePortAppDirect(Jam_GetTrackHandle(0x30000), 2, tmpDemoVol);
	Jac_SetStreamLevel(GAMESTREAM_VOL_TABLE[bgmVol], GAMESTREAM_VOL_TABLE[seVol]);
	tmpSeVol = GAMESE_VOL_TABLE[seVol];
	Jam_WritePortAppDirect(Jam_GetTrackHandle(0x10000), 0, tmpSeVol);
	Jam_WritePortAppDirect(Jam_GetTrackHandle(0x20000), 0, tmpSeVol);
}

/*
 * --INFO--
 * Address:	80019500
 * Size:	0000E4
 */
void Jac_EasyCrossFade(u8 type, u32 val)
{
	u8* REF_type = &type;
	u32* REF_val = &val;
	switch (type) {
	case 0:
		bgm[0]._45C = game_bgm_volume;
		bgm[1]._45C = 0.0f;
		Jam_MuteTrack(Jaf_HandleToSeq(bgm[0].trackHandle), 0);
		last_crossmode = 0;
		break;

	case 1:
		bgm[1]._45C = game_bgm_volume;
		bgm[0]._45C = 0.0f;
		Jam_MuteTrack(Jaf_HandleToSeq(bgm[1].trackHandle), 0);
		break;

	case 2:
		bgm[last_crossmode]._45C = game_bgm_volume;
		bgm[last_crossmode]._464 = val;
		return;
	}

	bgm[0]._464 = val;
	bgm[1]._464 = val;

	last_crossmode = type;
}

/*
 * --INFO--
 * Address:	80019600
 * Size:	0000C8
 */
void Jac_DemoFade(f32 multiplier, u8 type, u32 val)
{
	u8* REF_type  = &type;
	u32* REF_val  = &val;
	f32* REF_mult = &multiplier;

	switch (type) {
	case 0:
		bgm[0]._45C = bgm[0]._460;
		bgm[1]._45C = bgm[1]._460;
		break;

	case 1:
		bgm[0]._460 = bgm[0]._45C;
		bgm[1]._460 = bgm[1]._45C;
		bgm[0]._45C = multiplier * bgm[0]._45C;
		bgm[1]._45C = multiplier * bgm[1]._45C;
		break;

	case 2:
		bgm[0]._45C = multiplier * bgm[0]._460;
		bgm[1]._45C = multiplier * bgm[1]._460;
		break;

	case 3:
		bgm[0]._45C = multiplier;
		bgm[1]._45C = multiplier;
		break;
	}

	bgm[0]._464 = val;
	bgm[1]._464 = val;
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
