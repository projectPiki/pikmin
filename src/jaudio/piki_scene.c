#include "jaudio/piki_scene.h"

#include "jaudio/aramcall.h"
#include "jaudio/dvdthread.h"
#include "jaudio/interface.h"
#include "jaudio/jammain_2.h"
#include "jaudio/piki_bgm.h"
#include "jaudio/piki_player.h"
#include "jaudio/pikidemo.h"
#include "jaudio/pikiinter.h"
#include "jaudio/syncstream.h"
#include "jaudio/verysimple.h"
#include "jaudio/waveread.h"

#include "GlobalGameOptions.h"

static u32 current_bgm;
static u32 current_ready; // type
static vu32 now_loading;  // type
static volatile BOOL first_load;
static BOOL chgmode;

static u32 current_scene   = SCENE_NULL;
static u32 current_stage   = -1;
static u32 current_prepare = -1;
static u16 stream_level    = 8000;
static u16 stream_se_level = 8000;

static int tbl_scene_to_bgm[SCENE_COUNT] = {
	BGM_PikiSE,   // SCENE_BootUp
	BGM_Jungle,   // SCENE_Title
	BGM_Select,   // SCENE_FileSelect
	BGM_Map,      // SCENE_WorldMap
	BGM_PikiSE,   // unused
	BGM_SysEvent, // SCENE_Course
	BGM_PikiSE,   // SCENE_Results
	BGM_PikiSE,   // unused
	BGM_PikiSE,   // unused
	BGM_Dummy8,   // unused
	BGM_Char,     // SCENE_ChalSelect
	BGM_PikiSE,   // SCENE_Intro
	BGM_PikiSE,   // unused
	BGM_PikiSE,   // SCENE_Exit
};

static int tbl_scene_to_fadetime[SCENE_COUNT] = {
	0,   // SCENE_BootUp
	60,  // SCENE_Title
	15,  // SCENE_FileSelect
	120, // SCENE_WorldMap
	10,  // unused
	25,  // SCENE_Course
	10,  // SCENE_Results
	10,  // unused
	10,  // unused
	10,  // unused
	25,  // SCENE_ChalSelect
	0,   // SCENE_Intro
	0,   // unused
	0,   // SCENE_Exit
};

static int tbl_stage_to_bgm[STAGE_COUNT] = {
	BGM_Tutorial,  // STAGE_Practice (Impact Site)
	BGM_Play3,     // STAGE_Forest (Forest of Hope)
	BGM_Cave,      // STAGE_Cave (Forest Navel)
	BGM_Yakushima, // STAGE_Yakushima (Distant Spring)
	BGM_Flow,      // STAGE_Last (Final Trial)
};

char filelist[][32] = { "piki.stx",    "o_dead.stx",  "d_end1.stx",    "gyoku.stx",    "d_end3.stx",   "fanf5.stx",   "badend0.stx",
	                    "badend1.stx", "opening.stx", "happyend1.stx", "compend1.stx", "compend0.stx", "badend2.stx", "onion.stx" };

static u8 header[] = { 0x00, 0x64, 0x0C, 0x62, 0x00, 0x58, 0xEE, 0x80, 0xBB, 0x80, 0x00, 0x04, 0x00, 0x10, 0x00, 0x1e,
	                   0x00, 0x00, 0x00, 0x00, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 };

/**
 * @TODO: Documentation
 */
void Jac_Delete_CurrentBgmWave()
{
	Jac_StopBgm(0);
	Jac_StopBgm(1);
	WaveScene_Close(current_bgm, 0);
}

/**
 * @TODO: Documentation
 */
static void __Loaded(u32 a)
{
	STACK_PAD_VAR(1);
	u32* REF_a = &a;
	u32 hi     = a & 0xffff0000;
	a          = a & 0x0000ffff;

	switch (hi) {
	case 0x20000:
		first_load = 1;
		break;
	case 0:
		now_loading = 0;
		break;
	case 0x10000:
		if (current_bgm == a) {
			Collect_AramMotherHeap();
			Jac_PlayBgm(0, current_bgm);
		}
		break;
	}
}

/**
 * @TODO: Documentation
 */
u32 Jac_GetCurrentScene()
{
	return current_scene;
}

/**
 * @TODO: Documentation
 */
BOOL Jac_TellChgMode()
{
	return chgmode;
}

/**
 * @brief Sets up the audio environment to start playing a music track.
 *
 * @param sceneID Scene type to set up for - see `JacSceneID` enum.
 * @param stage Stage for `SCENE_Course` (see `StageID` enum) - also used as type of results screen for `SCENE_Results` (see
 * `JacResultsType` enum). Value irrelevant for everything else.
 */
void Jac_SceneSetup(u32 sceneID, u32 stage)
{
	STACK_PAD_VAR(4);
	u32* REF_sceneID = &sceneID;
	u32* REF_stage   = &stage;
	static int first = 1;
	BOOL closeScene, same;
	int bgm;
	u32 bgm2;
	OSTick tick;

	BOOL dvd = FALSE;
	Jac_SetProcessStatus(0);

	if (first_load == FALSE) {
		while (first_load == FALSE) {
			if (sceneID == SCENE_Title) {
				break;
			}
			if (sceneID == SCENE_BootUp) {
				break;
			}
		}
	}

	if (sceneID == SCENE_ChalSelect) {
		chgmode = 1;
	}

	if (sceneID == SCENE_WorldMap) {
		WaveScene_Close(13, 0);
		Jac_DemoSceneInit();
		chgmode = 0;
	}

	if (sceneID == SCENE_Title) {
		chgmode = 0;
	}

	if ((current_scene == SCENE_Course) || (sceneID == SCENE_Course)) {
		Jac_InitAllEvent();
		Jac_Piki_Number(0);
		Jac_UpdatePikiGaya();
		Jac_StopOrimaSe(8);
		Jac_FinishPartsFindDemo();
		Jac_FinishDemo();
	}

	Jac_PlaySystemSe(JACSYS_Unpause);
	Jac_PlaySystemSe(JACSYS_MenuOff);
	Jac_StopSystemSe(JACSYS_ContainerOK);
	Jac_StopSystemSe(JACSYS_MenuZoomIn);
	Jac_StopSystemSe(JACSYS_MenuScroll);
	Jac_UnPauseOrimaSe();

	if (current_scene == SCENE_Results) {
		Jac_DemoBGMForceStop();
	}

	if (current_scene == SCENE_NULL) {
		bgm = BGM_PikiSE;
	} else {
		bgm = tbl_scene_to_bgm[current_scene];
	}

	current_scene = sceneID;
	current_stage = stage;
	bgm2          = tbl_scene_to_bgm[sceneID];
	if (sceneID == SCENE_Results) {
		// interpret stage as results type
		if (chgmode != 0) {
			bgm2 = BGM_ChalResult;
		}
		if (stage == JACRES_FinalResult) {
			bgm2 = BGM_FinalResult;
		}
	}

	if (current_bgm != bgm2) {
		closeScene = TRUE;
		Jac_StopBgm(0);
		Jac_StopBgm(1);
		same = FALSE;
		if ((bgm2 == BGM_SysEvent) && (current_bgm == tbl_stage_to_bgm[stage])) {
			closeScene = FALSE;
		}
		if (current_bgm == BGM_PikiSE) {
			closeScene = FALSE;
		}
		if (bgm2 == BGM_PikiSE) {
			closeScene = FALSE;
		}
		if (closeScene) {
			WaveScene_Close(current_bgm, 0);
		}
	} else if (bgm2 == bgm) {
		same = TRUE;
	} else {
		same = FALSE;
	}

	closeScene = FALSE;

	switch (bgm2) {
	case BGM_PikiSE:
		break;
	case BGM_SysEvent:
		bgm2 = tbl_stage_to_bgm[stage];
		if (stage) {
			closeScene = TRUE;
		}
		Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);

	default:
		if (same != TRUE) {
			if (current_ready != bgm2) {
				Jac_ReadyBgm(bgm2);
				Collect_AramMotherHeap();
				WaveScene_Set(bgm2, 0);
				current_ready = bgm2;
				if (!closeScene) {
					DVDT_CheckPass(bgm2 + 0x10000, 0, __Loaded);
				} else {
					dvd = TRUE;
				}
			} else {
				while (now_loading) { }
				Collect_AramMotherHeap();
				Jac_PlayBgm(0, bgm2);
			}
		}
		break;
	}

	if (bgm2) {
		current_bgm = bgm2;
	}

	if (closeScene) {
		if (stage == STAGE_Last) {
			WaveScene_Close(BGM_Boss2, 0);
			WaveScene_Set(BGM_Boss3, 0);
			Jac_PlayBgm(1, BGM_Boss3);
		} else {
			WaveScene_Close(BGM_Boss3, 0);
			WaveScene_Set(BGM_Boss2, 0);
			Jac_PlayBgm(1, BGM_Boss2);
		}

		if (dvd != FALSE) {
			DVDT_CheckPass(bgm2 + 0x10000, 0, __Loaded);
		}
	}

	if (current_scene == SCENE_Title && first == 1) {
		first = 0;
		WaveScene_Load(0, 1);
		WaveScene_Load(0, 2);
		WaveScene_Load(0, 3);
		WaveScene_Set(BGM_Dummy14, 0);
		WaveScene_Set(BGM_Dummy15, 0);
		WaveScene_Set(BGM_Dummy2, 0);
		DVDT_CheckPass(0x20000, 0, __Loaded);
	}

	// decide on which PIKMIN sound effect to play over the Nintendo logo
	if (sceneID == SCENE_BootUp) {
		do {
			bgm = Jac_CheckBootOk();
		} while (bgm == BGM_PikiSE);

		// which sound effect we play is based on the current time tick
		tick = OSGetTick();
		if ((tick >> 2 & 0x1f) == 0x1f) {
			if ((tick >> 2 & 0x3f) == 0x3f) {
				Jac_PlayOrimaSe(JACORIMA_Unk8015); // hmmmm or yaaaay (1.5625% chance)
			} else {
				Jac_PlayOrimaSe(JACORIMA_Unk8016); // hmmmm or yaaaay (1.5625% chance)
			}
		} else if ((tick >> 2 & 0x7f) == 0x7e) {
			Jac_PlayOrimaSe(JACORIMA_Unk8017); // WEEEOUEUGH (0.78125% chance)
		} else {
			Jac_PlayOrimaSe(JACORIMA_Unk800C); // PIIIKMIIIIN (96.09375% chance)
		}
	}
	Jac_SetProcessStatus(1);
}

/**
 * @TODO: Documentation
 */
void Jac_SceneExit(u32 nextSceneID, u32 stage)
{
	int fade;
	int newBgm;

	int* REF_fade;
	STACK_PAD_VAR(1);

	if (current_scene == nextSceneID) {
		return;
	}

	Jac_SetProcessStatus(2);
	fade     = tbl_scene_to_fadetime[current_scene];
	REF_fade = &fade;
	Jac_FadeOutBgm(0, fade);
	Jac_FadeOutBgm(1, fade);

	newBgm = tbl_scene_to_bgm[nextSceneID];
	switch (newBgm) {
	case 0:
		break;
	case 1:
		newBgm = tbl_stage_to_bgm[stage];
		// fallthrough
	default:
		if (now_loading) {
			do {
			} while (now_loading != 0);
		}

		WaveScene_Set(newBgm, 0);
		Jac_ReadyBgm(newBgm);
		DVDT_CheckPass(newBgm, 0, __Loaded);
		now_loading   = 1;
		current_ready = newBgm;
		break;
	}
	Jac_SetProcessStatus(3);
}

/**
 * @TODO: Documentation
 */
void Jac_SetStreamLevel(u16 streamLevel, u16 seLevel)
{
	stream_level    = streamLevel;
	stream_se_level = seLevel;
}

/**
 * @TODO: Documentation
 */
void Jac_UpdateStreamLevel()
{
	if (StreamCheckAudioFormat(0) == AUDIOFRMT_ADPCM4X) {
		StreamChgVolume(0, 0x7fff, 0x7fff);
		StreamChgMixLevel(0, stream_level, stream_se_level);
	} else {
		StreamChgVolume(0, stream_level, stream_level);
	}
}

static u32 stop_flag;
static volatile u32 stop_ready;

/**
 * cmd -1: stop, cmd 0: ready
 */
static int MovieSync(u32 a1, s32 cmd)
{
	int sync;

	Jac_UpdateStreamLevel();

	if (cmd == -1) {
		stop_ready = 1;
		sync       = 0;
		stop_flag  = 0;
	} else if (stop_flag) {
		sync      = -1;
		stop_flag = 0;
	} else {
		if (cmd == 0) {
			stop_ready = 1;
		}
		sync = 0;
	}

	return sync;
}

/**
 * @TODO: Documentation
 */
void Jac_InitStreamSystem(void)
{
	RegisterStreamCallback(MovieSync);
}

/**
 * @TODO: Documentation
 */
void Jac_StopDemoSound(u32 id)
{
	if (StreamSyncCheckBusy(0, id) == 1) {
		stop_flag = 1;
	}
}

/**
 * @TODO: Documentation
 */
void Jac_PrepareDemoSound(u32 id)
{
	char buffer[64];
	STACK_PAD_VAR(3);
	u32* REF_id = &id;

	if (StreamSyncCheckBusy(0, id) == 1) {
		stop_ready = 0;
		Jac_StopDemoSound(id);
		do {
		} while (stop_ready == 0);
	}
	DVDT_ExtendPath(buffer, filelist[id]);
	StreamAudio_Start(0, id, buffer, 1, 0, 0);
	Jac_UpdateStreamLevel();
	current_prepare = id;
}

/**
 * @TODO: Documentation
 */
void Jac_StartDemoSound(u32 id)
{

	if (current_prepare != id && StreamSyncCheckBusy(0, id) == 1) {
		stop_ready = 0;
		Jac_StopDemoSound(id);
		do {
		} while (stop_ready == 0);
	}
	current_prepare = 0xffffffff;

	if (StreamSyncCheckReadyID(0, id) == 0) {
		Jac_PrepareDemoSound(id);
	}
	do {
	} while (StreamSyncPlayAudio(1.0f, 0, stream_level, stream_level) != 1);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void Jac_CheckReadyDemoSound(u32 a)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000048
 */
void Jac_StreamSetup(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000020
 */
void Jac_StreamUpdate(void)
{
	// UNUSED FUNCTION
}
