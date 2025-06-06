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
		u32 badCompiler;

		for (i = 0; i < 5; i++) {
			u32 size;
			u8* seqbuf;
			u32 badCompiler2;
			size            = Jaf_CheckSeqSize(vals1[i]);
			u32* REF_size   = &size;
			seqbuf          = (u8*)OSAlloc2(size);
			u8** REF_seqbuf = &seqbuf;
			if ((u32)Jaf_LoadSeq(vals1[i], seqbuf)) {
				int* pVals = &vals2[i];
				if (*pVals != -1) {
					Jaf_StartSeq(*pVals, vals1[i]);
				}
			}
		}

		buffer[0] = (u8*)OSAlloc2(0x8000);
		buffer[1] = (u8*)OSAlloc2(0x8000);
	}
	Jac_RegisterPlayerCallback(Jac_BgmFrameCallback, 0);
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
		int* idx = &buffer_mus[lastside];
		if (*idx != -1) {
			Jaf_ClearSeq(*idx);
		}
		Jaf_LoadSeqA(id, buffer[lastside]);

		buffer_mus[lastside] = id;
		lastside             = 1 - lastside;
	}
}

/*
 * --INFO--
 * Address:	80018C80
 * Size:	000244
 */
void Jac_PlayBgm(u32 a, u32 id)
{
	u32 badCompiler[4];
	u32* REF_b = &id;
	u32 check;
	seqp_* track;
	Jac_SetProcessStatus(8);
	if (bgm[a]._00) {
		Jac_StopBgm(a);
	}

	// this is nearly just Jac_ReadyBgm again
	if (id < 2) {
		id = 2;
	}
	check = (u32)Jaf_CheckSeq(id);
	if (check == 0) {
		int* idx = &buffer_mus[lastside];
		if (*idx != -1) {
			Jaf_ClearSeq(*idx);
		}
		Jaf_LoadSeq(id, buffer[lastside]);

		buffer_mus[lastside] = id;
		lastside             = 1 - lastside;
	} else if (check == 1) {
		while (check == 1) {
			check = (u32)Jaf_CheckSeq(id);
		}
	}

	track = Jaf_HandleToSeq(a + 3);

	bgm[a]._00         = 1;
	bgm[a]._04         = 1;
	bgm[a]._08         = 0;
	bgm[a]._18         = 0;
	bgm[a]._0C         = 0;
	bgm[a]._14         = id - 2;
	bgm[a].trackHandle = a + 3;

	Jac_SetBgmModeFlag(a, 2, 0);
	Jac_SetBgmModeFlag(a, 1, 0);
	Jac_SetBgmModeFlag(a, 4, 0);
	Jac_SetBgmModeFlag(a, 8, 0);
	Jaf_ReadySeq(a + 3, id);
	Jac_BgmFrameWork();
	Jaq_SetBankNumber(Jaf_HandleToSeq(a + 3), id);
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
	if (Jac_TellChgMode() == TRUE && Jac_GetCurrentScene() == SCENE_Unk5) {
		Jam_OnExtSwitch(track, 0x40);
		Jam_SetExtParam(1.2f, track, 0x40);
	} else {
		Jam_OffExtSwitch(track, 0x40);
	}
	track->pauseStatus = 74;
	Jaf_PlaySeq(a + 3);
	Jac_SetProcessStatus(9);
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
	Jac_ChangeBgmMode(a, thisBgm->_0F + (thisBgm->_10 << 2) + (thisBgm->_0E << 1) + (thisBgm->_11 << 3));
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
		Jam_SetExtParamP(control->trackParams[i].volume + (b - control->trackParams[i].volume) / a, track, i, 1);
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

	if (!track->outerParams) {
		return FALSE;
	}

	Jam_SetExtParam(track->outerParams->volume + (control->_45C - track->outerParams->volume) / a, track, 1);
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
void Jac_DemoFade(u8 type, u32 val, f32 multiplier)
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
