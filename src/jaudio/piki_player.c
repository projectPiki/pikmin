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
	static seqp_* seqp = nullptr;
	static u8 status   = 0;
	gaya_timer         = 0;

	if (seqp == nullptr) {
		seqp = Jam_GetTrackHandle(0x10008);
		if (seqp == nullptr) {
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

static seqp_* stick_seqp;

/*
 * --INFO--
 * Address:	80018200
 * Size:	000190
 */
void Jac_Orima_Formation(s32 a1, s32 a2)
{
	static int flag = 0;

	if (stick_seqp == nullptr) {
		stick_seqp = Jam_GetTrackHandle(0x10007);
		if (stick_seqp == nullptr) {
			return;
		}
	}

	if (Jac_DemoCheck() == TRUE) {
		a1 = 0;
		a2 = 0;
	}

	if (Jac_PauseCheck() == TRUE) {
		a1 = 0;
		a2 = 0;
	}

	if (a1 < -0x7f) {
		a1 = -0x7f;
	}
	if (a1 > 0x7f) {
		a1 = 0x7f;
	}

	if (a2 < -0x7f) {
		a2 = -0x7f;
	}
	if (a2 > 0x7f) {
		a2 = 0x7f;
	}

	if (a2 < 0) {
		a2 = -a2;
	}

	int s = sqrtf2(a1 * a1 + a2 * a2);
	Jam_WritePortAppDirect(stick_seqp, 2, a1);
	Jam_WritePortAppDirect(stick_seqp, 3, s);

	if (a1 == 0 && s == 0) {
		if (flag) {
			Jam_WritePortAppDirect(stick_seqp, 0, 0);
			flag = FALSE;
		}
	} else {
		if (flag == FALSE) {
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

	if (orima_seqp == nullptr) {
		orima_seqp = Jam_GetTrackHandle(0x1000a);
		if (orima_seqp == nullptr) {
			return;
		}
	}

	if (cmdqueue_reset == 0) {
		Jal_AddCmdQueue(&player_se, orima_seqp, 0);
		cmdqueue_reset = 1;
	}

	if (id & 0x8000) {
		static int flyready = FALSE;
		if (Jac_DemoCheck() != TRUE && (flyready == FALSE || id != 0x8004)) {
			Jam_WritePortAppDirect(orima_seqp, 1, id & 0x7fff);
			if (id == 0x8002) {
				flyready = FALSE;
			}
			if (id == 0x8004) {
				flyready = TRUE;
			}
		}
	} else {
		Jal_SendCmdQueue_Noblock(&player_se, (u16)id);
		if (id == 4) {
			u32 a           = (u16)GetRandom_ulimit(4);
			u32 id2         = 0x800b;
			static u16 old1 = 4;
			static u16 old2 = 5;
			static u16 old3 = 6;

			// a &= 3;
			vu16 b = a & 3;
			a      = b;
			if ((int)a != 3) {
				id2 = a + 0x800d;
			}
			int badcompiler[1];

			if (old3 == old2 && old2 == old1) {
				if (old1 != a) {
					id2 = a + 0x8010;
				} else {
					id2 = 0x8014;
				}
				old1 = 5;
			} else {
				old3 = old2;
				old2 = old1;
				old1 = a;
			}
			Jam_WritePortAppDirect(orima_seqp, 1, id2 & 0x7fff);
		}
		if (id == 12) {
			Jac_FadeOutBgm(0, 100);
			Jac_FadeOutBgm(1, 100);
			Jac_PlaySystemSe(0x28);
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
	static seqp_* seqp        = nullptr;
	static int cmdqueue_reset = 0;
	static CmdQueue player_se_stop;

	if (cmdqueue_reset == 0) {
		seqp = Jam_GetTrackHandle(0x1000a);
		if (seqp == nullptr) {
			return;
		}
		Jal_AddCmdQueue(&player_se_stop, seqp, 2);
		cmdqueue_reset = 1;
	}

	if (!(id & 0x8000)) {
		Jal_SendCmdQueue_Noblock(&player_se_stop, id);
	}
}
static u32 pikis;
/*
 * --INFO--
 * Address:	80018740
 * Size:	000078
 */
void Jac_Piki_Number(u32 id)
{
	if (id >= 100) {
		pikis = 29;
		return;
	}

	if (id >= 50) {
		pikis = (id - 50) / 10 + 25;
		return;
	}

	if (id >= 25) {
		pikis = (id - 25) / 5 + 20;
		return;
	}

	if (id >= 15) {
		pikis = (id - 15) / 2 + 15;
		return;
	}

	pikis = id;
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
	static int outerparam[16]; // this type is wrong, I have no idea yet

	if (Jac_GetCurrentScene() != 5) {
		Jam_SetExtParamD(0, outerparam, 1);
		return;
	}

	if (Jac_DemoCheck() == TRUE) {
		Jam_SetExtParamD(0, outerparam, 1);
		return;
	}

	if (init == FALSE) {
		seqp = Jam_GetTrackHandle(0x10003);
		Jam_InitExtBuffer(outerparam);
		init = Jam_AssignExtBuffer(seqp, outerparam);
		if (init == FALSE) {
			return;
		}
		Jam_OnExtSwitchD(outerparam, 1);
	}

	if (gaya_timer < 150 || pikis < 1) {
		Jam_SetExtParamD(volume, outerparam, 1);
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
		Jam_SetExtParamD(volume, outerparam, 1);
	}
	gaya_timer++;

	f32 badcompiler[2];
}
