#include "jaudio/piki_player.h"
#include "jaudio/piki_bgm.h"
#include "jaudio/jammain_2.h"
#include "jaudio/pikidemo.h"
#include "jaudio/piki_scene.h"
#include "jaudio/verysimple.h"
#include "jaudio/ja_calc.h"
#include "jaudio/random.h"
#include "jaudio/cmdqueue.h"

static u32 gaya_timer;

/*
 * --INFO--
 * Address:	80018120
 * Size:	0000DC
 */
void Jac_Orima_Walk(s32 soundID, u32 p2)
{
	static seqp_* seqp = NULL;
	static u8 status   = 0;
	gaya_timer         = 0;

	if (seqp == NULL) {
		seqp = Jam_GetTrackHandle(0x10008);
		if (seqp == NULL) {
			return;
		}
	}

	if (Jac_DemoWalkCheck()) {
		if (status == FALSE) {
			Jam_WritePortAppDirect(seqp, 0, soundID);
			status = TRUE;
		} else {
			Jam_WritePortAppDirect(seqp, 0, soundID);
			status = FALSE;
		}
	}
}

/// Music manager for c-sticking/'formation' track.
static seqp_* stick_seqp;

/*
 * --INFO--
 * Address:	80018200
 * Size:	000190
 */
void Jac_Orima_Formation(s32 stickX, s32 stickY)
{
	static int flag = 0;

	if (stick_seqp == NULL) {
		stick_seqp = Jam_GetTrackHandle(0x10007);
		if (stick_seqp == NULL) {
			return;
		}
	}

	// don't make c-stick sound when in a cutscene
	if (Jac_DemoCheck() == TRUE) {
		stickX = 0;
		stickY = 0;
	}

	// don't make c-stick sound when paused
	if (Jac_PauseCheck() == TRUE) {
		stickX = 0;
		stickY = 0;
	}

	// bound stick values
	if (stickX < -127) {
		stickX = -127;
	}
	if (stickX > 127) {
		stickX = 127;
	}

	if (stickY < -127) {
		stickY = -127;
	}
	if (stickY > 127) {
		stickY = 127;
	}

	if (stickY < 0) {
		stickY = -stickY;
	}

	int stickMag = sqrtf2(stickX * stickX + stickY * stickY);
	Jam_WritePortAppDirect(stick_seqp, 2, stickX);
	Jam_WritePortAppDirect(stick_seqp, 3, stickMag);

	if (stickX == 0 && stickMag == 0) {
		if (flag) {
			// we were c-sticking, now we're not - switch it off
			Jam_WritePortAppDirect(stick_seqp, 0, 0);
			flag = FALSE;
		}
	} else {
		if (flag == FALSE) {
			// we've started c-sticking again, switch it on
			Jam_WritePortAppDirect(stick_seqp, 0, 1);
			flag = TRUE;
		}
		gaya_timer = 0;
	}

	f32 badcompiler[2];
}

static seqp_* orima_seqp;

/*
 * --INFO--
 * Address:	800183A0
 * Size:	000250
 */
void Jac_PlayOrimaSe(u32 id)
{
	static u8 status          = 0;
	static int cmdqueue_reset = 0;
	static CmdQueue player_se;

	if (orima_seqp == NULL) {
		orima_seqp = Jam_GetTrackHandle(0x1000a);
		if (orima_seqp == NULL) {
			return;
		}
	}

	if (cmdqueue_reset == 0) {
		Jal_AddCmdQueue(&player_se, orima_seqp, 0);
		cmdqueue_reset = 1;
	}

	if (id & JACORIMA_PIKISOUND) {
		static int flyready = FALSE;
		if (Jac_DemoCheck() != TRUE && (flyready == FALSE || id != JACORIMA_PikiFlyReady)) {
			Jam_WritePortAppDirect(orima_seqp, 1, id & 0x7fff);
			if (id == JACORIMA_PikiFly) {
				flyready = FALSE;
			}

			if (id == JACORIMA_PikiFlyReady) {
				flyready = TRUE;
			}
		}
	} else {
		Jal_SendCmdQueue_Noblock(&player_se, (u16)id);
		if (id == JACORIMA_PikiPulled2) {
			u32 randomVariationId = (u16)GetRandom_ulimit(4);
			u32 variantSoundId    = 0x800b;

			// Static variables to track the last three sound variations to avoid repetition
			static u16 old1 = 4;
			static u16 old2 = 5;
			static u16 old3 = 6;

			// Ensure the index is within the range [0, 3]
			vu16 maskId       = randomVariationId & 3;
			randomVariationId = maskId;

			// Select a different sound ID based on the random index
			if ((int)randomVariationId != 3) {
				variantSoundId = randomVariationId + 0x800d;
			}

			int badcompiler[1];

			if (old3 == old2 && old2 == old1) {
				if (old1 != randomVariationId) {
					variantSoundId = randomVariationId + 0x8010;
				} else {
					variantSoundId = 0x8014;
				}

				old1 = 5;
			} else {
				old3 = old2;
				old2 = old1;
				old1 = randomVariationId;
			}

			Jam_WritePortAppDirect(orima_seqp, 1, variantSoundId & 0x7fff);
		}

		if (id == JACORIMA_PlayerDown) {
			Jac_FadeOutBgm(0, 100);
			Jac_FadeOutBgm(1, 100);
			Jac_PlaySystemSe(JACSYS_Unk40);
		}
	}
}

/*
 * --INFO--
 * Address:	80018600
 * Size:	000030
 */
void Jac_PauseOrimaSe()
{
	if (orima_seqp) {
		Jam_PauseTrack(orima_seqp, 1);
	}
}

/*
 * --INFO--
 * Address:	80018640
 * Size:	000030
 */
void Jac_UnPauseOrimaSe()
{
	if (orima_seqp) {
		Jam_UnPauseTrack(orima_seqp, 1);
	}
}

/*
 * --INFO--
 * Address:	80018680
 * Size:	0000B8
 */
void Jac_StopOrimaSe(s32 id)
{
	static seqp_* seqp        = NULL;
	static int cmdqueue_reset = 0;
	static CmdQueue player_se_stop;

	if (cmdqueue_reset == 0) {
		seqp = Jam_GetTrackHandle(0x1000a);
		if (seqp == NULL) {
			return;
		}
		Jal_AddCmdQueue(&player_se_stop, seqp, 2);
		cmdqueue_reset = 1;
	}

	if (!(id & JACORIMA_PIKISOUND)) {
		Jal_SendCmdQueue_Noblock(&player_se_stop, id);
	}
}
static u32 pikis;
/*
 * --INFO--
 * Address:	80018740
 * Size:	000078
 */
void Jac_Piki_Number(u32 pikiNum)
{
	if (pikiNum >= 100) {
		pikis = 29;
		return;
	}

	if (pikiNum >= 50) {
		pikis = (pikiNum - 50) / 10 + 25;
		return;
	}

	if (pikiNum >= 25) {
		pikis = (pikiNum - 25) / 5 + 20;
		return;
	}

	if (pikiNum >= 15) {
		pikis = (pikiNum - 15) / 2 + 15;
		return;
	}

	pikis = pikiNum;
}

/*
 * --INFO--
 * Address:	800187C0
 * Size:	0001B4
 */
void Jac_UpdatePikiGaya()
{
	static seqp_* seqp;
	static int init   = 0;
	static f32 volume = 0.0f;
	static OuterParam_ outerparam;

	if (Jac_GetCurrentScene() != SCENE_Unk5) {
		Jam_SetExtParamD(0, &outerparam, 1);
		return;
	}

	if (Jac_DemoCheck() == TRUE) {
		Jam_SetExtParamD(0, &outerparam, 1);
		return;
	}

	if (init == FALSE) {
		seqp = Jam_GetTrackHandle(0x10003);
		Jam_InitExtBuffer(&outerparam);
		init = Jam_AssignExtBuffer(seqp, &outerparam);
		if (init == FALSE) {
			return;
		}
		Jam_OnExtSwitchD(&outerparam, 1);
	}

	if (gaya_timer < 150 || pikis < 1) {
		Jam_SetExtParamD(volume, &outerparam, 1);
		volume -= 0.05f;
		if (volume < 0.0f) {
			volume = 0.0f;
		}
		if (pikis == 0) {
			Jam_WritePortAppDirect(seqp, 0, pikis);
		}
	} else if (gaya_timer >= 240) {
		Jam_WritePortAppDirect(seqp, 0, pikis);
		volume += 0.05f;
		if (volume > 1.0f) {
			volume = 1.0f;
		}
		Jam_SetExtParamD(volume, &outerparam, 1);
	}
	
	gaya_timer++;

	f32 badcompiler[2];
}
