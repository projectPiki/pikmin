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

static u32 current_bgm;
static u32 current_ready; // type
static vu32 now_loading;  // type
static volatile BOOL first_load;
static BOOL chgmode;

static u32 current_scene           = SCENE_NULL;
static u32 current_stage           = -1;
static u32 current_prepare         = -1;
static u16 stream_level            = 8000;
static u16 stream_se_level         = 8000;
static int tbl_scene_to_bgm[]      = { 0, 7, 18, 12, 0, 1, 0, 0, 0, 8, 19, 0, 0, 0 };
static int tbl_scene_to_fadetime[] = { 0, 60, 15, 120, 10, 25, 10, 10, 10, 10, 25, 0, 0, 0 };
static int tbl_stage_to_bgm[]      = { 4, 5, 10, 9, 17 };
char filelist[][32] = { "piki.stx",    "o_dead.stx",  "d_end1.stx",    "gyoku.stx",    "d_end3.stx",   "fanf5.stx",   "badend0.stx",
	                    "badend1.stx", "opening.stx", "happyend1.stx", "compend1.stx", "compend0.stx", "badend2.stx", "onion.stx" };

static u8 header[] = { 0x00, 0x64, 0x0C, 0x62, 0x00, 0x58, 0xEE, 0x80, 0xBB, 0x80, 0x00, 0x04, 0x00, 0x10, 0x00, 0x1e,
	                   0x00, 0x00, 0x00, 0x00, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 };

/*
 * --INFO--
 * Address:	80019760
 * Size:	000038
 */
void Jac_Delete_CurrentBgmWave()
{
	Jac_StopBgm(0);
	Jac_StopBgm(1);
	WaveScene_Close(current_bgm, 0);
}

/*
 * --INFO--
 * Address:	800197A0
 * Size:	000094
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

/*
 * --INFO--
 * Address:	80019840
 * Size:	000008
 */
u32 Jac_GetCurrentScene()
{
	return current_scene;
}

/*
 * --INFO--
 * Address:	80019860
 * Size:	000008
 */
BOOL Jac_TellChgMode()
{
	return chgmode;
}

/*
 * --INFO--
 * Address:	80019880
 * Size:	00045C
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
			if (sceneID == SCENE_Unk1) {
				break;
			}
			if (sceneID == SCENE_Unk0) {
				break;
			}
		}
	}

	if (sceneID == SCENE_Unk10) {
		chgmode = 1;
	}

	if (sceneID == SCENE_Unk3) {
		WaveScene_Close(13, 0);
		Jac_DemoSceneInit();
		chgmode = 0;
	}

	if (sceneID == SCENE_Unk1) {
		chgmode = 0;
	}

	if ((current_scene == SCENE_Unk5) || (sceneID == SCENE_Unk5)) {
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

	if (current_scene == SCENE_Unk6) {
		Jac_DemoBGMForceStop();
	}

	if (current_scene == SCENE_NULL) {
		bgm = 0;
	} else {
		bgm = tbl_scene_to_bgm[current_scene];
	}

	current_scene = sceneID;
	current_stage = stage;
	bgm2          = tbl_scene_to_bgm[sceneID];
	if (sceneID == SCENE_Unk6) {
		if (chgmode != 0) {
			bgm2 = 0x14;
		}
		if (stage == 1) {
			bgm2 = 0x15;
		}
	}

	if (current_bgm != bgm2) {
		closeScene = TRUE;
		Jac_StopBgm(0);
		Jac_StopBgm(1);
		same = FALSE;
		if ((bgm2 == 1) && (current_bgm == tbl_stage_to_bgm[stage])) {
			closeScene = FALSE;
		}
		if (current_bgm == 0) {
			closeScene = FALSE;
		}
		if (bgm2 == 0) {
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
	case 0:
		break;
	case 1:
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
		if (stage == 4) {
			WaveScene_Close(0xb, 0);
			WaveScene_Set(0x10, 0);
			Jac_PlayBgm(1, 0x10);
		} else {
			WaveScene_Close(0x10, 0);
			WaveScene_Set(0xb, 0);
			Jac_PlayBgm(1, 0xb);
		}

		if (dvd != FALSE) {
			DVDT_CheckPass(bgm2 + 0x10000, 0, __Loaded);
		}
	}

	if (current_scene == SCENE_Unk1 && first == 1) {
		first = 0;
		WaveScene_Load(0, 1);
		WaveScene_Load(0, 2);
		WaveScene_Load(0, 3);
		WaveScene_Set(0xe, 0);
		WaveScene_Set(0xf, 0);
		WaveScene_Set(2, 0);
		DVDT_CheckPass(0x20000, 0, __Loaded);
	}

	if (sceneID == SCENE_Unk0) {
		do {
			bgm = Jac_CheckBootOk();
		} while (bgm == 0);

		tick = OSGetTick();
		if ((tick >> 2 & 0x1f) == 0x1f) {
			if ((tick >> 2 & 0x3f) == 0x3f) {
				Jac_PlayOrimaSe(JACORIMA_Unk8015);
			} else {
				Jac_PlayOrimaSe(JACORIMA_Unk8016);
			}
		} else if ((tick >> 2 & 0x7f) == 0x7e) {
			Jac_PlayOrimaSe(JACORIMA_Unk8017);
		} else {
			Jac_PlayOrimaSe(JACORIMA_Unk800C);
		}
	}
	Jac_SetProcessStatus(1);
}

/*
 * --INFO--
 * Address:	80019CE0
 * Size:	0000FC
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
	}
	Jac_SetProcessStatus(3);
}

/*
 * --INFO--
 * Address:	80019DE0
 * Size:	00000C
 */
void Jac_SetStreamLevel(u16 streamLevel, u16 seLevel)
{
	stream_level    = streamLevel;
	stream_se_level = seLevel;
}

/*
 * --INFO--
 * Address:	80019E00
 * Size:	000064
 */
void Jac_UpdateStreamLevel()
{
	if (StreamCheckAudioFormat(0) == 5) {
		StreamChgVolume(0, 0x7fff, 0x7fff);
		StreamChgMixLevel(0, stream_level, stream_se_level);
	} else {
		StreamChgVolume(0, stream_level, stream_level);
	}
}

static u32 stop_flag;
static volatile u32 stop_ready;

/*
 * --INFO--
 * Address:	80019E80
 * Size:	00007C
 */
static int MovieSync(u32 a1, s32 a2)
{
	int sync;

	Jac_UpdateStreamLevel();

	if (a2 == -1) {
		stop_ready = 1;
		sync       = 0;
		stop_flag  = 0;
	} else if (stop_flag) {
		sync      = -1;
		stop_flag = 0;
	} else {
		if (a2 == 0) {
			stop_ready = 1;
		}
		sync = 0;
	}

	return sync;
}

/*
 * --INFO--
 * Address:	80019F00
 * Size:	000028
 */
void Jac_InitStreamSystem(void)
{
	RegisterStreamCallback(MovieSync);
}

/*
 * --INFO--
 * Address:	80019F40
 * Size:	000038
 */
void Jac_StopDemoSound(u32 id)
{
	if (StreamSyncCheckBusy(0, id) == 1) {
		stop_flag = 1;
	}
}

/*
 * --INFO--
 * Address:	80019F80
 * Size:	000098
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

/*
 * --INFO--
 * Address:	8001A020
 * Size:	0000A4
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

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void Jac_CheckReadyDemoSound(u32 a)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void Jac_StreamSetup(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void Jac_StreamUpdate(void)
{
	// UNUSED FUNCTION
}
