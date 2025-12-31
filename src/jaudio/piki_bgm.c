#include "jaudio/piki_bgm.h"

#include "Dolphin/os.h"
#include "jaudio/aictrl.h"
#include "jaudio/file_seq.h"
#include "jaudio/interface.h"
#include "jaudio/jammain_2.h"
#include "jaudio/piki_scene.h"
#include "jaudio/playercall.h"
#include "jaudio/seqsetup.h"

/**
 * @brief TODO
 *
 * @note Size: 0x468.
 */
typedef struct BgmControl_ {
	int isActive;                // _00
	int needsInit;               // _04
	int hasModeChanged;          // _08
	u8 currentMode;              // _0C, flag with 0x1/2/4/8 corresponding to _0F/_0E/_10/_11 below
	s8 trackHandle;              // _0D
	u8 battleMixEnabled;         // _0E, bool, this and _0F control the mute set
	u8 normalMixEnabled;         // _0F, bool
	u8 trackIntensity;           // _10, bool, controls volume set
	u8 isFadeOut;                // _11, bool
	u32 songId;                  // _14
	u32 transitionTimer;         // _18, unknown
	OuterParam_ trackParams[16]; // _1C
	f32 trackVolumes[16];        // _41C
	f32 gameVolume;              // _45C
	f32 prevVolume;              // _460
	u32 crossfade;               // _464, unknown
} BgmControl_;

static BgmControl_ bgm[3]; // 0 = normal, 1 = boss, 2 = unused?

static u8 lastside;
static int last_crossmode;
static u32 call_counter;
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

/**
 * @TODO: Documentation
 */
s32 Jac_BgmFrameCallback(void* a1)
{
	call_counter += 1;
	if ((call_counter & 7) == 0) {
		Jac_BgmFrameWork();
	}
	return 0;
}

/**
 * @TODO: Documentation
 */
void Jac_InitBgm(void)
{
	u32 i;
	for (i = 0; i < 3; i++) {
		bgm[i].isActive         = 0;
		bgm[i].battleMixEnabled = 0;
		bgm[i].normalMixEnabled = 0;
		bgm[i].trackIntensity   = 0;
		bgm[i].isFadeOut        = 0;
		bgm[i].trackHandle      = -1;
	}

	u32* REF_i = &i;

	if (!buffer[0]) {
		int vals1[5] = { 0, 1, 11, 13, 16 };
		int vals2[5] = { 0, 1, -1, 2, -1 };
		STACK_PAD_VAR(1);

		for (i = 0; i < 5; i++) {
			u32 size;
			u8* seqbuf;
			STACK_PAD_VAR(1);
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

/**
 * @TODO: Documentation
 */
void Jac_FadeOutBgm(u32 trackNo, u32 fade)
{
	fadeouttime = fade;
	Jac_SetBgmModeFlag(trackNo, 8, 1);
}

/**
 * @TODO: Documentation
 */
void Jac_StopBgm(u32 id)
{
	if (bgm[id].isActive) {
		Jaf_StopSeq(bgm[id].trackHandle);
		bgm[id].isActive = 0;
	}
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void Jac_PlayBgm(u32 trackNo, u32 bgmID)
{
	STACK_PAD_VAR(4);
	u32* REF_b = &bgmID;
	u32 check;
	seqp_* track;
	Jac_SetProcessStatus(8);
	if (bgm[trackNo].isActive) {
		Jac_StopBgm(trackNo);
	}

	// this is nearly just Jac_ReadyBgm again
	if (bgmID < 2) {
		bgmID = BGM_Dummy2;
	}
	check = (u32)Jaf_CheckSeq(bgmID);
	if (check == 0) {
		int* idx = &buffer_mus[lastside];
		if (*idx != -1) {
			Jaf_ClearSeq(*idx);
		}
		Jaf_LoadSeq(bgmID, buffer[lastside]);

		buffer_mus[lastside] = bgmID;
		lastside             = 1 - lastside;
	} else if (check == 1) {
		while (check == 1) {
			check = (u32)Jaf_CheckSeq(bgmID);
		}
	}

	track = Jaf_HandleToSeq(trackNo + 3);

	bgm[trackNo].isActive        = 1;
	bgm[trackNo].needsInit       = 1;
	bgm[trackNo].hasModeChanged  = 0;
	bgm[trackNo].transitionTimer = 0;
	bgm[trackNo].currentMode     = 0;
	bgm[trackNo].songId          = bgmID - 2;
	bgm[trackNo].trackHandle     = trackNo + 3;

#if defined(VERSION_GPIP01_00)
	call_counter = 6000;
#endif
	Jac_SetBgmModeFlag(trackNo, 2, 0);
	Jac_SetBgmModeFlag(trackNo, 1, 0);
	Jac_SetBgmModeFlag(trackNo, 4, 0);
	Jac_SetBgmModeFlag(trackNo, 8, 0);
#if defined(VERSION_GPIP01_00)
	call_counter = 0;
#endif
	Jaf_ReadySeq(trackNo + 3, bgmID);
	Jac_BgmFrameWork();
	Jaq_SetBankNumber(Jaf_HandleToSeq(trackNo + 3), bgmID);
	bgm[trackNo].crossfade = 0;

	if (trackNo == 0) {
		bgm[trackNo].gameVolume = game_bgm_volume;
		Jam_MuteTrack(track, 0);
		last_crossmode = 0;
	} else {
		bgm[trackNo].gameVolume = 0.0f;
		Jam_MuteTrack(track, 1);
	}

	Jam_SetExtParam(bgm[trackNo].gameVolume, track, 1);
	Jam_OnExtSwitch(track, 1);

	// Challenge mode tempo speedup?
	if (Jac_TellChgMode() == TRUE && Jac_GetCurrentScene() == SCENE_Course) {
		Jam_OnExtSwitch(track, 0x40);
		Jam_SetExtParam(1.2f, track, 0x40);
	} else {
		Jam_OffExtSwitch(track, 0x40);
	}
	track->pauseStatus = 74;
	Jaf_PlaySeq(trackNo + 3);
	Jac_SetProcessStatus(9);
}

/**
 * @TODO: Documentation
 */
BOOL Jac_ChangeBgmMode(u32 trackNo, u8 mode)
{
	if (mode == bgm[trackNo].currentMode) {
		return FALSE;
	}

	if (bgm[trackNo].isActive) {
		bgm[trackNo].currentMode    = mode;
		bgm[trackNo].hasModeChanged = 1;
	} else {
		return FALSE;
	}

	return TRUE;
}

/**
 * @TODO: Documentation
 */
void Jac_SetBgmModeFlag(u32 trackNo, u8 flag, u8 doSet)
{
#if defined(VERSION_GPIP01_00)
	int stack[2];
	if (call_counter < 6000 && Jac_GetCurrentScene() == SCENE_Course && flag != 8 && flag != 4) {
		return;
	}
#endif
	u32 x, y, z;
	BgmControl_* thisBgm = &bgm[trackNo];
	switch (flag) {
	case 2:
		thisBgm->battleMixEnabled = doSet;
		break;
	case 1:
		thisBgm->normalMixEnabled = doSet;
		break;
	case 4:
		thisBgm->trackIntensity = doSet;
		break;
	case 8:
		thisBgm->isFadeOut = doSet;
		break;
	}
	z = thisBgm->isFadeOut << 3;
	x = thisBgm->battleMixEnabled << 1;
	y = thisBgm->trackIntensity << 2;
	Jac_ChangeBgmMode(trackNo, (thisBgm->normalMixEnabled << 0) + (x) + (y) + (z));
}

/**
 * @TODO: Documentation
 */
void Jac_BgmFrameWork(void)
{
	if (bgm_semaphore == 0) {
		bgm_semaphore = TRUE;

		for (u32 i = 0; i < 3; i++) {
			if (!bgm[i].isActive) {
				continue;
			}
			if (bgm[i].needsInit) {
				Jac_ChangeBgmTrackVol(&bgm[i]);
				continue;
			}
			if (bgm[i].hasModeChanged) {
				Jac_ChangeBgmTrackVol(&bgm[i]);
				bgm[i].hasModeChanged = 0;
			}
			if (bgm[i].transitionTimer) {
				Jac_MoveBgmTrackVol(&bgm[i]);
			}

			if (bgm[i].crossfade) {
				if (!Jac_UpdateBgmCrossVol(&bgm[i])) {
					bgm[i].crossfade = 0;
					continue;
				}

				bgm[i].crossfade--;
				if (bgm[i].crossfade == 0 && 1 - last_crossmode == i) {
					Jam_MuteTrack(Jaf_HandleToSeq(bgm[i].trackHandle), 1);
				}
			}
		}

		bgm_semaphore = FALSE;
	}
}

/**
 * @TODO: Documentation
 */
void Jac_MoveBgmTrackVol(BgmControl_* control)
{
	seqp_* track2;
	seqp_* track;
	u32 i;
	f32 a  = control->transitionTimer;
	track2 = Jaf_HandleToSeq(control->trackHandle);
	if (!track2) {
		return;
	}
	track = track2;
	control->transitionTimer--;

	for (i = 0; i < 16; i++) {
		f32 b = control->trackVolumes[i];
		Jam_SetExtParamP(control->trackParams[i].volume + (b - control->trackParams[i].volume) / a, track, i, 1);
	}
}

/**
 * @TODO: Documentation
 */
void Jac_ChangeBgmTrackVol(BgmControl_* control)
{
	STACK_PAD_VAR(4);
	u32 i;
	seqp_* track2 = Jaf_HandleToSeq(control->trackHandle);
	if (!track2) {
		return;
	}

	u16 mute = bgm_mute_set[control->songId][control->currentMode & 0x3];
	f32 vol  = bgm_volume_set[control->songId][(control->currentMode >> 2) & 0x1];

	if (control->currentMode & 0x8) {
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

	if (control->needsInit) {
		for (i = 0; i < 16; i++) {
			Jam_InitExtBuffer(&control->trackParams[i]);
			Jam_AssignExtBufferP(track, i, &control->trackParams[i]);
			Jam_SetExtParamP(control->trackVolumes[i], track, i, 1);
			Jam_OnExtSwitchP(track, i, 1);
		}
		control->needsInit = 0;
	} else if (control->currentMode & 0x8) {
		control->transitionTimer = fadeouttime;
	} else {
		control->transitionTimer = 60;
	}
}

/**
 * @TODO: Documentation
 */
static BOOL Jac_UpdateBgmCrossVol(BgmControl_* control)
{
	f32 a        = control->crossfade;
	seqp_* track = Jaf_HandleToSeq(control->trackHandle);

	if (!track->outerParams) {
		return FALSE;
	}

	Jam_SetExtParam(track->outerParams->volume + (control->gameVolume - track->outerParams->volume) / a, track, 1);
	return TRUE;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void Jac_EasyCrossFade(u8 mode, u32 fadeTime)
{
	u8* REF_type = &mode;
	u32* REF_val = &fadeTime;
	switch (mode) {
	case 0: // exit boss mode
		bgm[0].gameVolume = game_bgm_volume;
		bgm[1].gameVolume = 0.0f;
		Jam_MuteTrack(Jaf_HandleToSeq(bgm[0].trackHandle), 0);
		last_crossmode = 0;
		break;

	case 1: // enter boss mode
		bgm[1].gameVolume = game_bgm_volume;
		bgm[0].gameVolume = 0.0f;
		Jam_MuteTrack(Jaf_HandleToSeq(bgm[1].trackHandle), 0);
		break;

	case 2: // volume changed
		bgm[last_crossmode].gameVolume = game_bgm_volume;
		bgm[last_crossmode].crossfade  = fadeTime;
		return;
	}

	bgm[0].crossfade = fadeTime;
	bgm[1].crossfade = fadeTime;

	last_crossmode = mode;
}

/**
 * @TODO: Documentation
 */
void Jac_DemoFade(u8 type, u32 val, f32 multiplier)
{
	u8* REF_type  = &type;
	u32* REF_val  = &val;
	f32* REF_mult = &multiplier;

	switch (type) {
	case 0:
		bgm[0].gameVolume = bgm[0].prevVolume;
		bgm[1].gameVolume = bgm[1].prevVolume;
		break;

	case 1:
		bgm[0].prevVolume = bgm[0].gameVolume;
		bgm[1].prevVolume = bgm[1].gameVolume;
		bgm[0].gameVolume = multiplier * bgm[0].gameVolume;
		bgm[1].gameVolume = multiplier * bgm[1].gameVolume;
		break;

	case 2:
		bgm[0].gameVolume = multiplier * bgm[0].prevVolume;
		bgm[1].gameVolume = multiplier * bgm[1].prevVolume;
		break;

	case 3:
		bgm[0].gameVolume = multiplier;
		bgm[1].gameVolume = multiplier;
		break;
	}

	bgm[0].crossfade = val;
	bgm[1].crossfade = val;
}

/**
 * @TODO: Documentation
 */
void Jac_EnterBossMode(void)
{
	Jac_EasyCrossFade(1, 100);
}

/**
 * @TODO: Documentation
 */
void Jac_ExitBossMode(void)
{
	Jac_EasyCrossFade(0, 100);
}
