#include "jaudio/PikiScene.h"

#include "jaudio/PikiBgm.h"
#include "jaudio/PikiInter.h"
#include "jaudio/PikiDemo.h"
#include "jaudio/PikiPlayer.h"
#include "jaudio/waveread.h"
#include "jaudio/aramcall.h"
#include "jaudio/interface.h"
#include "jaudio/jammain_2.h"
#include "jaudio/verysimple.h"
#include "jaudio/dvdthread.h"
#include "jaudio/syncstream.h"

static u32 current_bgm;
static u32 current_ready; // type
static vu32 now_loading;  // type
static u32 first_load;    // type
static BOOL chgmode;      // type

static u32 current_scene    = -1;
static u32 current_stage    = -1;
static u32 current_prepare  = -1;
static u16 stream_level     = 8000;
static u16 stream_se_level  = 8000;
int tbl_scene_to_bgm[]      = { 0, 7, 18, 12, 0, 1, 0, 0, 0, 8, 19, 0, 0, 0 };
int tbl_scene_to_fadetime[] = { 0, 60, 15, 120, 10, 25, 10, 10, 10, 10, 25, 0, 0, 0 };
int tbl_stage_to_bgm[]      = { 4, 5, 10, 9, 17 };
char filelist[][32]         = { "piki.stx",    "o_dead.stx",  "d_end1.stx",    "gyoku.stx",    "d_end3.stx",   "fanf5.stx",   "badend0.stx",
	                            "badend1.stx", "opening.stx", "happyend1.stx", "compend1.stx", "compend0.stx", "badend2.stx", "onion.stx" };

u8 header[] = { 0x00, 0x64, 0x0C, 0x62, 0x00, 0x58, 0xEE, 0x80, 0xBB, 0x80, 0x00, 0x04, 0x00, 0x10, 0x00, 0x1e,
	            0x00, 0x00, 0x00, 0x00, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 };

volatile u32 stop_ready;
u32 stop_flag;

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
	vu32 hi, lo;
	hi = a & 0xffff0000;
	lo = a & 0x0000ffff;

	switch (hi) {
	case 0x20000:
		first_load = 1;
		break;
	case 0:
		now_loading = 0;
		break;
	case 0x10000:
		if (current_bgm == lo) {
			Collect_AramMotherHeap();
			Jac_PlayBgm(0, current_bgm);
		}
		break;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  lis       r0, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  rlwinm    r4,r3,0,0,15
	  rlwinm    r3,r3,0,16,31
	  cmpw      r4, r0
	  stw       r3, 0x8(r1)
	  beq-      .loc_0x64
	  bge-      .loc_0x3C
	  cmpwi     r4, 0
	  beq-      .loc_0x58
	  b         .loc_0x84

	.loc_0x3C:
	  lis       r0, 0x2
	  cmpw      r4, r0
	  beq-      .loc_0x4C
	  b         .loc_0x84

	.loc_0x4C:
	  li        r0, 0x1
	  stw       r0, 0x2D14(r13)
	  b         .loc_0x84

	.loc_0x58:
	  li        r0, 0
	  stw       r0, 0x2D10(r13)
	  b         .loc_0x84

	.loc_0x64:
	  lwz       r3, 0x2D08(r13)
	  lwz       r0, 0x8(r1)
	  cmplw     r3, r0
	  bne-      .loc_0x84
	  bl        -0xBE34
	  li        r3, 0
	  lwz       r4, 0x2D08(r13)
	  bl        -0xBA0

	.loc_0x84:
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
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
	static int first = 1;
	BOOL dvd, closeScene, same;
	int bgm;
	u32 bgm2;
	OSTick tick;

	dvd = FALSE;
	Jac_SetProcessStatus(0);

	if (first_load == 0) {
		while (sceneID != 1) {
			if (first_load) {
				break;
			}
		}
	}

	if (sceneID == 10) {
		chgmode = 1;
	}

	if (sceneID == 3) {
		WaveScene_Close(13, 0);
		Jac_DemoSceneInit();
		chgmode = 0;
	}

	if (sceneID == 1) {
		chgmode = 0;
	}

	if ((current_scene == 5) || (sceneID == 5)) {
		Jac_InitAllEvent();
		Jac_Piki_Number(0);
		Jac_UpdatePikiGaya();
		Jac_StopOrimaSe(8);
		Jac_FinishPartsFindDemo();
		Jac_FinishDemo();
	}

	Jac_PlaySystemSe(0xf);
	Jac_PlaySystemSe(7);
	Jac_StopSystemSe(0x10);
	Jac_StopSystemSe(0x21);
	Jac_StopSystemSe(0x23);
	Jac_UnPauseOrimaSe();

	if (current_scene == 6) {
		Jac_DemoBGMForceStop();
	}

	if (current_scene == -1) {
		bgm = 0;
	} else {
		bgm = tbl_scene_to_bgm[current_scene];
	}

	bgm2 = tbl_scene_to_bgm[sceneID];
	if (sceneID == 6) {
		if (chgmode != 0) {
			bgm2 = 0x14;
		}
		if (stage == 1) {
			bgm2 = 0x15;
		}
	}

	current_scene = sceneID;
	current_stage = stage;

	if (current_bgm == bgm2) {
		if (bgm2 == bgm) {
			same = TRUE;
		} else {
			same = FALSE;
		}
	} else {
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
	}

	closeScene = FALSE;

	switch (bgm2) {
	case 1:
		closeScene = stage != 0;
		bgm2       = tbl_stage_to_bgm[stage];
		Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);
		break;

	case 0:
		break;

	default:
		if (!same) {
			Jac_ReadyBgm(bgm2);
			Collect_AramMotherHeap();
			WaveScene_Set(bgm2, 0);
			current_ready = bgm2;
			if (closeScene) {
				dvd = TRUE;
			} else {
				DVDT_CheckPass(bgm2 + 0x10000, 0, __Loaded);
			}
		} else {
			if (current_ready == bgm2) {
				while (now_loading) { }
				Collect_AramMotherHeap();
				Jac_PlayBgm(0, bgm2);
			}
		}
		break;
	}

	if (bgm2) {
		current_bgm = bgm;
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

		// if (dvd != FALSE) {
		DVDT_CheckPass(bgm2 + 0x10000, 0, __Loaded);
		//}
	}

	if (current_scene == 1 && first == 1) {
		first = 0;
		WaveScene_Load(0, 1);
		WaveScene_Load(0, 2);
		WaveScene_Load(0, 3);
		WaveScene_Set(0xe, 0);
		WaveScene_Set(0xf, 0);
		WaveScene_Set(2, 0);
		DVDT_CheckPass(0x20000, 0, __Loaded);
	}

	if (sceneID == 0) {
		do {
			bgm = Jac_CheckBootOk();
		} while (bgm == 0);

		tick = OSGetTick();
		if ((tick >> 2 & 0x1f) == 0x1f) {
			if ((tick >> 2 & 0x3f) == 0x3f) {
				Jac_PlayOrimaSe(0x8015);
			} else {
				Jac_PlayOrimaSe(0x8016);
			}
		} else if ((tick >> 2 & 0x7f) == 0x7e) {
			Jac_PlayOrimaSe(0x8017);
		} else {
			Jac_PlayOrimaSe(0x800c);
		}
	}
	Jac_SetProcessStatus(1);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8022
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r25, 0x2C(r1)
	  addi      r31, r5, 0x6248
	  lbz       r0, 0x2D20(r13)
	  stw       r3, 0x8(r1)
	  extsb.    r0, r0
	  stw       r4, 0xC(r1)
	  bne-      .loc_0x38
	  li        r0, 0x1
	  stw       r0, 0x2D1C(r13)
	  stb       r0, 0x2D20(r13)

	.loc_0x38:
	  li        r27, 0
	  li        r3, 0
	  bl        -0x2F00
	  lwz       r0, 0x2D14(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x74
	  lwz       r3, 0x8(r1)
	  b         .loc_0x68

	.loc_0x58:
	  cmplwi    r3, 0x1
	  beq-      .loc_0x74
	  cmplwi    r3, 0
	  beq-      .loc_0x74

	.loc_0x68:
	  lwz       r0, 0x2D14(r13)
	  cmpwi     r0, 0
	  beq+      .loc_0x58

	.loc_0x74:
	  lwz       r30, 0x8(r1)
	  cmplwi    r30, 0xA
	  bne-      .loc_0x88
	  li        r0, 0x1
	  stw       r0, 0x2D18(r13)

	.loc_0x88:
	  cmplwi    r30, 0x3
	  bne-      .loc_0xA8
	  li        r3, 0xD
	  li        r4, 0
	  bl        -0xD138
	  bl        0x7C4
	  li        r0, 0
	  stw       r0, 0x2D18(r13)

	.loc_0xA8:
	  cmplwi    r30, 0x1
	  bne-      .loc_0xB8
	  li        r0, 0
	  stw       r0, 0x2D18(r13)

	.loc_0xB8:
	  lwz       r0, -0x7F20(r13)
	  cmplwi    r0, 0x5
	  beq-      .loc_0xCC
	  cmplwi    r30, 0x5
	  bne-      .loc_0xEC

	.loc_0xCC:
	  bl        -0x190C
	  li        r3, 0
	  bl        -0x1214
	  bl        -0x1198
	  li        r3, 0x8
	  bl        -0x12E0
	  bl        0x189C
	  bl        0x1438

	.loc_0xEC:
	  li        r3, 0xF
	  bl        -0x2DD0
	  li        r3, 0x7
	  bl        -0x2DD8
	  li        r3, 0x10
	  bl        -0x2A40
	  li        r3, 0x21
	  bl        -0x2A48
	  li        r3, 0x23
	  bl        -0x2A50
	  bl        -0x1354
	  lwz       r0, -0x7F20(r13)
	  cmplwi    r0, 0x6
	  bne-      .loc_0x128
	  bl        0x11FC

	.loc_0x128:
	  lwz       r3, -0x7F20(r13)
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0x140
	  li        r3, 0
	  b         .loc_0x148

	.loc_0x140:
	  rlwinm    r0,r3,2,0,29
	  lwzx      r3, r31, r0

	.loc_0x148:
	  lwz       r29, 0xC(r1)
	  cmplwi    r30, 0x6
	  stw       r30, -0x7F20(r13)
	  rlwinm    r0,r30,2,0,29
	  stw       r29, -0x7F1C(r13)
	  lwzx      r28, r31, r0
	  bne-      .loc_0x180
	  lwz       r0, 0x2D18(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x174
	  li        r28, 0x14

	.loc_0x174:
	  cmplwi    r29, 0x1
	  bne-      .loc_0x180
	  li        r28, 0x15

	.loc_0x180:
	  lwz       r0, 0x2D08(r13)
	  cmplw     r0, r28
	  beq-      .loc_0x1F8
	  li        r26, 0x1
	  li        r3, 0
	  bl        -0xE94
	  li        r3, 0x1
	  bl        -0xE9C
	  cmplwi    r28, 0x1
	  li        r25, 0
	  bne-      .loc_0x1C8
	  rlwinm    r0,r29,2,0,29
	  lwz       r4, 0x2D08(r13)
	  add       r3, r31, r0
	  lwz       r0, 0x70(r3)
	  cmplw     r4, r0
	  bne-      .loc_0x1C8
	  li        r26, 0

	.loc_0x1C8:
	  lwz       r3, 0x2D08(r13)
	  cmplwi    r3, 0
	  bne-      .loc_0x1D8
	  li        r26, 0

	.loc_0x1D8:
	  cmplwi    r28, 0
	  bne-      .loc_0x1E4
	  li        r26, 0

	.loc_0x1E4:
	  cmpwi     r26, 0
	  beq-      .loc_0x20C
	  li        r4, 0
	  bl        -0xD290
	  b         .loc_0x20C

	.loc_0x1F8:
	  cmplw     r28, r3
	  bne-      .loc_0x208
	  li        r25, 0x1
	  b         .loc_0x20C

	.loc_0x208:
	  li        r25, 0

	.loc_0x20C:
	  cmpwi     r28, 0x1
	  li        r26, 0
	  beq-      .loc_0x228
	  bge-      .loc_0x250
	  cmpwi     r28, 0
	  bge-      .loc_0x2C4
	  b         .loc_0x250

	.loc_0x228:
	  rlwinm    r0,r29,2,0,29
	  cmplwi    r29, 0
	  add       r3, r31, r0
	  lwz       r28, 0x70(r3)
	  beq-      .loc_0x240
	  li        r26, 0x1

	.loc_0x240:
	  lis       r3, 0x2
	  bl        -0x9464
	  li        r4, 0x1
	  bl        -0x85EC

	.loc_0x250:
	  cmpwi     r25, 0x1
	  beq-      .loc_0x2C4
	  lwz       r0, 0x2D0C(r13)
	  cmplw     r0, r28
	  beq-      .loc_0x2A8
	  mr        r3, r28
	  bl        -0xF08
	  bl        -0xC10C
	  addi      r3, r28, 0
	  li        r4, 0
	  bl        -0xD418
	  cmpwi     r26, 0
	  stw       r28, 0x2D0C(r13)
	  bne-      .loc_0x2A0
	  lis       r4, 0x8002
	  addis     r3, r28, 0x1
	  subi      r5, r4, 0x6860
	  li        r4, 0
	  bl        -0x11B98
	  b         .loc_0x2C4

	.loc_0x2A0:
	  li        r27, 0x1
	  b         .loc_0x2C4

	.loc_0x2A8:
	  lwz       r0, 0x2D10(r13)
	  cmplwi    r0, 0
	  bne+      .loc_0x2A8
	  bl        -0xC154
	  li        r3, 0
	  addi      r4, r28, 0
	  bl        -0xEC0

	.loc_0x2C4:
	  cmplwi    r28, 0
	  beq-      .loc_0x2D0
	  stw       r28, 0x2D08(r13)

	.loc_0x2D0:
	  cmpwi     r26, 0
	  beq-      .loc_0x348
	  cmplwi    r29, 0x4
	  bne-      .loc_0x308
	  li        r3, 0xB
	  li        r4, 0
	  bl        -0xD388
	  li        r3, 0x10
	  li        r4, 0
	  bl        -0xD494
	  li        r3, 0x1
	  li        r4, 0x10
	  bl        -0xF00
	  b         .loc_0x32C

	.loc_0x308:
	  li        r3, 0x10
	  li        r4, 0
	  bl        -0xD3B0
	  li        r3, 0xB
	  li        r4, 0
	  bl        -0xD4BC
	  li        r3, 0x1
	  li        r4, 0xB
	  bl        -0xF28

	.loc_0x32C:
	  cmpwi     r27, 0
	  beq-      .loc_0x348
	  lis       r4, 0x8002
	  addis     r3, r28, 0x1
	  subi      r5, r4, 0x6860
	  li        r4, 0
	  bl        -0x11C44

	.loc_0x348:
	  lwz       r0, -0x7F20(r13)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x3C4
	  lwz       r0, 0x2D1C(r13)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x3C4
	  li        r0, 0
	  li        r3, 0
	  stw       r0, 0x2D1C(r13)
	  li        r4, 0x1
	  bl        -0xD4D0
	  li        r3, 0
	  li        r4, 0x2
	  bl        -0xD4DC
	  li        r3, 0
	  li        r4, 0x3
	  bl        -0xD4E8
	  li        r3, 0xE
	  li        r4, 0
	  bl        -0xD534
	  li        r3, 0xF
	  li        r4, 0
	  bl        -0xD540
	  li        r3, 0x2
	  li        r4, 0
	  bl        -0xD54C
	  lis       r4, 0x8002
	  lis       r3, 0x2
	  subi      r5, r4, 0x6860
	  li        r4, 0
	  bl        -0x11CC0

	.loc_0x3C4:
	  cmplwi    r30, 0
	  bne-      .loc_0x440

	.loc_0x3CC:
	  bl        -0x2AAC
	  cmpwi     r3, 0
	  beq+      .loc_0x3CC
	  bl        0x1E3760
	  rlwinm    r4,r3,30,2,31
	  rlwinm    r0,r3,30,27,31
	  cmplwi    r0, 0x1F
	  bne-      .loc_0x418
	  rlwinm    r0,r4,0,26,31
	  cmplwi    r0, 0x3F
	  bne-      .loc_0x408
	  lis       r3, 0x1
	  subi      r3, r3, 0x7FEB
	  bl        -0x18E0
	  b         .loc_0x440

	.loc_0x408:
	  lis       r3, 0x1
	  subi      r3, r3, 0x7FEA
	  bl        -0x18F0
	  b         .loc_0x440

	.loc_0x418:
	  rlwinm    r0,r4,0,25,31
	  cmplwi    r0, 0x7E
	  bne-      .loc_0x434
	  lis       r3, 0x1
	  subi      r3, r3, 0x7FE9
	  bl        -0x190C
	  b         .loc_0x440

	.loc_0x434:
	  lis       r3, 0x1
	  subi      r3, r3, 0x7FF4
	  bl        -0x191C

	.loc_0x440:
	  li        r3, 0x1
	  bl        -0x3304
	  lmw       r25, 0x2C(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019CE0
 * Size:	0000FC
 */
void Jac_SceneExit(u32 scene, u32 stage)
{
	int fade;
	int newScene;

	int* REF_fade;
	u32 badCompiler;

	if (current_scene == scene) {
		return;
	}

	Jac_SetProcessStatus(2);
	fade     = tbl_scene_to_fadetime[current_scene];
	REF_fade = &fade;
	Jac_FadeOutBgm(0, fade);
	Jac_FadeOutBgm(1, fade);

	newScene = tbl_scene_to_bgm[scene];
	switch (newScene) {
	case 0:
		break;
	case 1:
		newScene = tbl_stage_to_bgm[stage];
	default:
		if (now_loading) {
			do {
			} while (now_loading != 0);
		}

		WaveScene_Set(newScene, 0);
		Jac_ReadyBgm(newScene);
		DVDT_CheckPass(newScene, 0, __Loaded);
		now_loading   = 1;
		current_ready = newScene;
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
	if ((u8)StreamCheckAudioFormat(0) == 5) {
		StreamChgVolume(0, 0x7fff, 0x7fff);
		StreamChgMixLevel(0, stream_level, stream_se_level);
	} else {
		StreamChgVolume(0, stream_level, stream_level);
	}
}

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
	char buffer[78];

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

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r3, 0x8(r1)
	  li        r3, 0
	  lwz       r31, 0x8(r1)
	  mr        r4, r31
	  bl        0x3440
	  cmpwi     r3, 0x1
	  bne-      .loc_0x48
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0x2D28(r13)
	  bl        -0x78

	.loc_0x3C:
	  lwz       r0, 0x2D28(r13)
	  cmplwi    r0, 0
	  beq+      .loc_0x3C

	.loc_0x48:
	  lis       r3, 0x8022
	  rlwinm    r4,r31,5,0,26
	  addi      r0, r3, 0x62CC
	  addi      r3, r1, 0x1C
	  add       r4, r0, r4
	  bl        -0x12A9C
	  addi      r4, r31, 0
	  addi      r5, r1, 0x1C
	  li        r3, 0
	  li        r6, 0x1
	  li        r7, 0
	  li        r8, 0
	  bl        0x2148
	  bl        -0x1FC
	  stw       r31, -0x7F18(r13)
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
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

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lwz       r0, -0x7F18(r13)
	  cmplw     r0, r31
	  beq-      .loc_0x50
	  li        r3, 0
	  addi      r4, r31, 0
	  bl        0x3398
	  cmpwi     r3, 0x1
	  bne-      .loc_0x50
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0x2D28(r13)
	  bl        -0x120

	.loc_0x44:
	  lwz       r0, 0x2D28(r13)
	  cmplwi    r0, 0
	  beq+      .loc_0x44

	.loc_0x50:
	  li        r0, -0x1
	  addi      r4, r31, 0
	  stw       r0, -0x7F18(r13)
	  li        r3, 0
	  bl        0x3300
	  cmpwi     r3, 0
	  bne-      .loc_0x74
	  mr        r3, r31
	  bl        -0x110

	.loc_0x74:
	  lhz       r4, -0x7F14(r13)
	  li        r3, 0
	  lfs       f1, -0x7E20(r2)
	  mr        r5, r4
	  bl        0x339C
	  cmpwi     r3, 0x1
	  bne+      .loc_0x74
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
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
