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
static BOOL Jac_UpdateBgmCrossVol(BgmControl_* bgmControl);

/**
 * @TODO: Documentation
 */
s32 Jac_BgmFrameCallback(void* callbackArg)
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
		int preloadSeqIds[5] = { 0, 1, 11, 13, 16 };
		int startTrackIds[5] = { 0, 1, -1, 2, -1 };
		STACK_PAD_VAR(1);

		for (i = 0; i < 5; i++) {
			u32 seqSize;
			u8* seqBuffer;
			STACK_PAD_VAR(1);
			seqSize   = Jaf_CheckSeqSize(preloadSeqIds[i]);
			u32* REF_size = &seqSize;
			seqBuffer = (u8*)OSAlloc2(seqSize);
			u8** REF_seqbuf = &seqBuffer;
			if ((u32)Jaf_LoadSeq(preloadSeqIds[i], seqBuffer)) {
				int* startTrackId = &startTrackIds[i];
				if (*startTrackId != -1) {
					Jaf_StartSeq(*startTrackId, preloadSeqIds[i]);
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
void Jac_FadeOutBgm(u32 trackIndex, u32 fadeFrames)
{
	fadeouttime = fadeFrames;
	Jac_SetBgmModeFlag(trackIndex, 8, 1);
}

/**
 * @TODO: Documentation
 */
void Jac_StopBgm(u32 trackIndex)
{
	if (bgm[trackIndex].isActive) {
		Jaf_StopSeq(bgm[trackIndex].trackHandle);
		bgm[trackIndex].isActive = 0;
	}
}

/**
 * @TODO: Documentation
 */
void Jac_ReadyBgm(u32 bgmID)
{
	u32* REF_id = &bgmID;

	if (bgmID < 2) {
		bgmID = 2;
	}
	if (Jaf_CheckSeq(bgmID) == 0) {
		int* bufferedSeqId = &buffer_mus[lastside];
		if (*bufferedSeqId != -1) {
			Jaf_ClearSeq(*bufferedSeqId);
		}
		Jaf_LoadSeqA(bgmID, buffer[lastside]);

		buffer_mus[lastside] = bgmID;
		lastside             = 1 - lastside;
	}
}

/**
 * @TODO: Documentation
 */
void Jac_PlayBgm(u32 trackIndex, u32 bgmID)
{
	STACK_PAD_VAR(4);
	u32* REF_b = &bgmID;
	u32 seqState;
	seqp_* track;
	Jac_SetProcessStatus(8);
	if (bgm[trackIndex].isActive) {
		Jac_StopBgm(trackIndex);
	}

	// this is nearly just Jac_ReadyBgm again
	if (bgmID < 2) {
		bgmID = BGM_Dummy2;
	}
	seqState = (u32)Jaf_CheckSeq(bgmID);
	if (seqState == 0) {
		int* bufferedSeqId = &buffer_mus[lastside];
		if (*bufferedSeqId != -1) {
			Jaf_ClearSeq(*bufferedSeqId);
		}
		Jaf_LoadSeq(bgmID, buffer[lastside]);

		buffer_mus[lastside] = bgmID;
		lastside             = 1 - lastside;
	} else if (seqState == 1) {
		while (seqState == 1) {
			seqState = (u32)Jaf_CheckSeq(bgmID);
		}
	}

	track = Jaf_HandleToSeq(trackIndex + 3);

	bgm[trackIndex].isActive        = 1;
	bgm[trackIndex].needsInit       = 1;
	bgm[trackIndex].hasModeChanged  = 0;
	bgm[trackIndex].transitionTimer = 0;
	bgm[trackIndex].currentMode     = 0;
	bgm[trackIndex].songId          = bgmID - 2;
	bgm[trackIndex].trackHandle     = trackIndex + 3;

#if defined(VERSION_GPIP01)
	call_counter = 6000;
#endif
	Jac_SetBgmModeFlag(trackIndex, 2, 0);
	Jac_SetBgmModeFlag(trackIndex, 1, 0);
	Jac_SetBgmModeFlag(trackIndex, 4, 0);
	Jac_SetBgmModeFlag(trackIndex, 8, 0);
#if defined(VERSION_GPIP01)
	call_counter = 0;
#endif
	Jaf_ReadySeq(trackIndex + 3, bgmID);
	Jac_BgmFrameWork();
	Jaq_SetBankNumber(Jaf_HandleToSeq(trackIndex + 3), bgmID);
	bgm[trackIndex].crossfade = 0;

	if (trackIndex == 0) {
		bgm[trackIndex].gameVolume = game_bgm_volume;
		Jam_MuteTrack(track, 0);
		last_crossmode = 0;
	} else {
		bgm[trackIndex].gameVolume = 0.0f;
		Jam_MuteTrack(track, 1);
	}

	Jam_SetExtParam(bgm[trackIndex].gameVolume, track, 1);
	Jam_OnExtSwitch(track, 1);

	// Challenge mode tempo speedup?
	if (Jac_TellChgMode() == TRUE && Jac_GetCurrentScene() == SCENE_Course) {
		Jam_OnExtSwitch(track, 0x40);
		Jam_SetExtParam(1.2f, track, 0x40);
	} else {
		Jam_OffExtSwitch(track, 0x40);
	}
	track->pauseStatus = 74;
	Jaf_PlaySeq(trackIndex + 3);
	Jac_SetProcessStatus(9);
}

/**
 * @TODO: Documentation
 */
BOOL Jac_ChangeBgmMode(u32 trackIndex, u8 modeFlags)
{
	if (modeFlags == bgm[trackIndex].currentMode) {
		return FALSE;
	}

	if (bgm[trackIndex].isActive) {
		bgm[trackIndex].currentMode    = modeFlags;
		bgm[trackIndex].hasModeChanged = 1;
	} else {
		return FALSE;
	}

	return TRUE;
}

/**
 * @TODO: Documentation
 */
void Jac_SetBgmModeFlag(u32 trackIndex, u8 flagMask, u8 enabled)
{
#if defined(VERSION_GPIP01)
	STACK_PAD_VAR(2);
	if (call_counter < 6000 && Jac_GetCurrentScene() == SCENE_Course && flagMask != 8 && flagMask != 4) {
		return;
	}
#endif
	u32 battleModeFlag;
	u32 intensityModeFlag;
	u32 fadeModeFlag;
	BgmControl_* currentBgm = &bgm[trackIndex];
	switch (flagMask) {
	case 2:
	{
		currentBgm->battleMixEnabled = enabled;
		break;
	}
	case 1:
	{
		currentBgm->normalMixEnabled = enabled;
		break;
	}
	case 4:
	{
		currentBgm->trackIntensity = enabled;
		break;
	}
	case 8:
	{
		currentBgm->isFadeOut = enabled;
		break;
	}
	}
	fadeModeFlag      = currentBgm->isFadeOut << 3;
	battleModeFlag    = currentBgm->battleMixEnabled << 1;
	intensityModeFlag = currentBgm->trackIntensity << 2;
	Jac_ChangeBgmMode(trackIndex, (currentBgm->normalMixEnabled << 0) + battleModeFlag + intensityModeFlag + fadeModeFlag);
}

/**
 * @TODO: Documentation
 */
void Jac_BgmFrameWork(void)
{
	if (bgm_semaphore == 0) {
		bgm_semaphore = TRUE;

		for (u32 trackIndex = 0; trackIndex < 3; trackIndex++) {
			if (!bgm[trackIndex].isActive) {
				continue;
			}
			if (bgm[trackIndex].needsInit) {
				Jac_ChangeBgmTrackVol(&bgm[trackIndex]);
				continue;
			}
			if (bgm[trackIndex].hasModeChanged) {
				Jac_ChangeBgmTrackVol(&bgm[trackIndex]);
				bgm[trackIndex].hasModeChanged = 0;
			}
			if (bgm[trackIndex].transitionTimer) {
				Jac_MoveBgmTrackVol(&bgm[trackIndex]);
			}

			if (bgm[trackIndex].crossfade) {
				if (!Jac_UpdateBgmCrossVol(&bgm[trackIndex])) {
					bgm[trackIndex].crossfade = 0;
					continue;
				}

				bgm[trackIndex].crossfade--;
				if (bgm[trackIndex].crossfade == 0 && 1 - last_crossmode == trackIndex) {
					Jam_MuteTrack(Jaf_HandleToSeq(bgm[trackIndex].trackHandle), 1);
				}
			}
		}

		bgm_semaphore = FALSE;
	}
}

/**
 * @TODO: Documentation
 */
void Jac_MoveBgmTrackVol(BgmControl_* bgmControl)
{
	seqp_* track2;
	seqp_* track;
	u32 i;
	f32 a  = bgmControl->transitionTimer;
	track2 = Jaf_HandleToSeq(bgmControl->trackHandle);
	if (!track2) {
		return;
	}
	track = track2;
	bgmControl->transitionTimer--;

	for (i = 0; i < 16; i++) {
		f32 b = bgmControl->trackVolumes[i];
		Jam_SetExtParamP(bgmControl->trackParams[i].volume + (b - bgmControl->trackParams[i].volume) / a, track, i, 1);
	}
}

/**
 * @TODO: Documentation
 */
void Jac_ChangeBgmTrackVol(BgmControl_* bgmControl)
{
	STACK_PAD_VAR(4);
	u32 i;
	seqp_* track2 = Jaf_HandleToSeq(bgmControl->trackHandle);
	if (!track2) {
		return;
	}

	u16 mute = bgm_mute_set[bgmControl->songId][bgmControl->currentMode & 0x3];
	f32 vol  = bgm_volume_set[bgmControl->songId][(bgmControl->currentMode >> 2) & 0x1];

	if (bgmControl->currentMode & 0x8) {
		vol = 0.0f;
	}
	seqp_* track = track2;

	for (i = 0; i < 16; i++) {
		switch ((mute >> i) & 0x1) {
		case 0:
		{
			bgmControl->trackVolumes[i] = 0.0f;
			break;
		}
		case 1:
		{
			bgmControl->trackVolumes[i] = vol;
			break;
		}
		}
	}

	if (bgmControl->needsInit) {
		for (i = 0; i < 16; i++) {
			Jam_InitExtBuffer(&bgmControl->trackParams[i]);
			Jam_AssignExtBufferP(track, i, &bgmControl->trackParams[i]);
			Jam_SetExtParamP(bgmControl->trackVolumes[i], track, i, 1);
			Jam_OnExtSwitchP(track, i, 1);
		}
		bgmControl->needsInit = 0;
	} else if (bgmControl->currentMode & 0x8) {
		bgmControl->transitionTimer = fadeouttime;
	} else {
		bgmControl->transitionTimer = 60;
	}
}

/**
 * @TODO: Documentation
 */
static BOOL Jac_UpdateBgmCrossVol(BgmControl_* bgmControl)
{
	f32 a        = bgmControl->crossfade;
	seqp_* track = Jaf_HandleToSeq(bgmControl->trackHandle);

	if (!track->outerParams) {
		return FALSE;
	}

	Jam_SetExtParam(track->outerParams->volume + (bgmControl->gameVolume - track->outerParams->volume) / a, track, 1);
	return TRUE;
}

/**
 * @TODO: Documentation
 */
void Jac_GameVolume(u8 bgmLevel, u8 seLevel)
{
	u16 soundEffectVolume;
	u16 demoVolume;
	game_bgm_volume = GAMEBGM_VOL_TABLE[bgmLevel];
	if (last_bgm_level != bgmLevel) {
		Jac_EasyCrossFade(2, 10);
	}

	last_bgm_level = bgmLevel;
	demoVolume     = GAMEDEMO_VOL_TABLE[bgmLevel];
	Jam_WritePortAppDirect(Jam_GetTrackHandle(0x30000), 2, demoVolume);
	Jac_SetStreamLevel(GAMESTREAM_VOL_TABLE[bgmLevel], GAMESTREAM_VOL_TABLE[seLevel]);
	soundEffectVolume = GAMESE_VOL_TABLE[seLevel];
	Jam_WritePortAppDirect(Jam_GetTrackHandle(0x10000), 0, soundEffectVolume);
	Jam_WritePortAppDirect(Jam_GetTrackHandle(0x20000), 0, soundEffectVolume);
}

/**
 * @TODO: Documentation
 */
void Jac_EasyCrossFade(u8 crossfadeMode, u32 fadeFrames)
{
	u8* REF_type = &crossfadeMode;
	u32* REF_val = &fadeFrames;

	switch (crossfadeMode) {
	case 0: // exit boss mode
	{
		bgm[0].gameVolume = game_bgm_volume;
		bgm[1].gameVolume = 0.0f;
		Jam_MuteTrack(Jaf_HandleToSeq(bgm[0].trackHandle), 0);
		last_crossmode = 0;
		break;
	}
	case 1: // enter boss mode
	{
		bgm[1].gameVolume = game_bgm_volume;
		bgm[0].gameVolume = 0.0f;
		Jam_MuteTrack(Jaf_HandleToSeq(bgm[1].trackHandle), 0);
		break;
	}
	case 2: // volume changed
	{
		bgm[last_crossmode].gameVolume = game_bgm_volume;
		bgm[last_crossmode].crossfade  = fadeFrames;
		return;
	}
	}

	bgm[0].crossfade = fadeFrames;
	bgm[1].crossfade = fadeFrames;

	last_crossmode = crossfadeMode;
}

/**
 * @TODO: Documentation
 */
void Jac_DemoFade(u8 fadeType, u32 fadeFrames, f32 volumeScale)
{
	u8* REF_type  = &fadeType;
	u32* REF_val  = &fadeFrames;
	f32* REF_mult = &volumeScale;

	switch (fadeType) {
	case 0:
	{
		bgm[0].gameVolume = bgm[0].prevVolume;
		bgm[1].gameVolume = bgm[1].prevVolume;
		break;
	}
	case 1:
	{
		bgm[0].prevVolume = bgm[0].gameVolume;
		bgm[1].prevVolume = bgm[1].gameVolume;
		bgm[0].gameVolume = volumeScale * bgm[0].gameVolume;
		bgm[1].gameVolume = volumeScale * bgm[1].gameVolume;
		break;
	}
	case 2:
	{
		bgm[0].gameVolume = volumeScale * bgm[0].prevVolume;
		bgm[1].gameVolume = volumeScale * bgm[1].prevVolume;
		break;
	}
	case 3:
	{
		bgm[0].gameVolume = volumeScale;
		bgm[1].gameVolume = volumeScale;
		break;
	}
	}

	bgm[0].crossfade = fadeFrames;
	bgm[1].crossfade = fadeFrames;
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
