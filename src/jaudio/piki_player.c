#include "jaudio/PikiPlayer.h"
#include "jaudio/PikiBgm.h"
#include "jaudio/jammain_2.h"
#include "jaudio/PikiDemo.h"
#include "jaudio/PikiScene.h"
#include "jaudio/verysimple.h"
#include "jaudio/calc.h"
#include "jaudio/random.h"
#include "jaudio/cmdqueue.h"

u32 gaya_timer;
u32 pikis;
seqp_* stick_seqp;
seqp_* orima_seqp;

/*
 * --INFO--
 * Address:	80018120
 * Size:	0000DC
 */
void Jac_Orima_Walk(u16 soundID, u32 p2)
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
	Jam_WritePortAppDirect(stick_seqp, 2, (u16)a1);
	Jam_WritePortAppDirect(stick_seqp, 3, (u16)s);

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

			a &= 3;
			vu16 b = a;
			if ((int)b != 3) {
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

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lbz       r0, 0x2CAD(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x30
	  li        r3, 0
	  li        r0, 0x1
	  stb       r3, 0x2CAC(r13)
	  stb       r0, 0x2CAD(r13)

	.loc_0x30:
	  lbz       r0, 0x2CB4(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x4C
	  li        r3, 0
	  li        r0, 0x1
	  stw       r3, 0x2CB0(r13)
	  stb       r0, 0x2CB4(r13)

	.loc_0x4C:
	  lwz       r0, 0x2CA8(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x74
	  lis       r3, 0x1
	  addi      r3, r3, 0xA
	  bl        -0x7DA0
	  stw       r3, 0x2CA8(r13)
	  lwz       r0, 0x2CA8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x23C

	.loc_0x74:
	  lwz       r0, 0x2CB0(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x9C
	  lis       r3, 0x8036
	  lwz       r4, 0x2CA8(r13)
	  addi      r3, r3, 0x37C8
	  li        r5, 0
	  bl        0x3570
	  li        r0, 0x1
	  stw       r0, 0x2CB0(r13)

	.loc_0x9C:
	  rlwinm.   r0,r31,0,16,16
	  beq-      .loc_0x114
	  lbz       r0, 0x2CBC(r13)
	  extsb.    r0, r0
	  bne-      .loc_0xC0
	  li        r3, 0
	  li        r0, 0x1
	  stw       r3, 0x2CB8(r13)
	  stb       r0, 0x2CBC(r13)

	.loc_0xC0:
	  bl        0x1D20
	  cmpwi     r3, 0x1
	  beq-      .loc_0x23C
	  lwz       r0, 0x2CB8(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xE0
	  cmplwi    r31, 0x8004
	  beq-      .loc_0x23C

	.loc_0xE0:
	  lwz       r3, 0x2CA8(r13)
	  rlwinm    r5,r31,0,17,31
	  li        r4, 0x1
	  bl        -0x810C
	  cmplwi    r31, 0x8002
	  bne-      .loc_0x100
	  li        r0, 0
	  stw       r0, 0x2CB8(r13)

	.loc_0x100:
	  cmplwi    r31, 0x8004
	  bne-      .loc_0x23C
	  li        r0, 0x1
	  stw       r0, 0x2CB8(r13)
	  b         .loc_0x23C

	.loc_0x114:
	  lis       r3, 0x8036
	  rlwinm    r4,r31,0,16,31
	  addi      r3, r3, 0x37C8
	  bl        0x3540
	  cmplwi    r31, 0x4
	  bne-      .loc_0x214
	  li        r3, 0x4
	  bl        -0xACD0
	  lbz       r0, 0x2CC0(r13)
	  lis       r4, 0x1
	  rlwinm    r5,r3,0,16,31
	  subi      r6, r4, 0x7FF5
	  extsb.    r0, r0
	  bne-      .loc_0x15C
	  li        r3, 0x4
	  li        r0, 0x1
	  sth       r3, 0x2CBE(r13)
	  stb       r0, 0x2CC0(r13)

	.loc_0x15C:
	  lbz       r0, 0x2CC4(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x178
	  li        r3, 0x5
	  li        r0, 0x1
	  sth       r3, 0x2CC2(r13)
	  stb       r0, 0x2CC4(r13)

	.loc_0x178:
	  lbz       r0, 0x2CC8(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x194
	  li        r3, 0x6
	  li        r0, 0x1
	  sth       r3, 0x2CC6(r13)
	  stb       r0, 0x2CC8(r13)

	.loc_0x194:
	  rlwinm    r0,r5,0,30,31
	  sth       r0, 0x10(r1)
	  lhz       r4, 0x10(r1)
	  cmpwi     r4, 0x3
	  beq-      .loc_0x1B0
	  addis     r6, r4, 0x1
	  subi      r6, r6, 0x7FF3

	.loc_0x1B0:
	  lhz       r0, 0x2CC6(r13)
	  lhz       r3, 0x2CC2(r13)
	  cmplw     r0, r3
	  bne-      .loc_0x1F4
	  lhz       r0, 0x2CBE(r13)
	  cmplw     r3, r0
	  bne-      .loc_0x1F4
	  cmplw     r0, r4
	  beq-      .loc_0x1E0
	  addis     r6, r4, 0x1
	  subi      r6, r6, 0x7FF0
	  b         .loc_0x1E8

	.loc_0x1E0:
	  lis       r3, 0x1
	  subi      r6, r3, 0x7FEC

	.loc_0x1E8:
	  li        r0, 0x5
	  sth       r0, 0x2CBE(r13)
	  b         .loc_0x204

	.loc_0x1F4:
	  lhz       r0, 0x2CBE(r13)
	  sth       r3, 0x2CC6(r13)
	  sth       r0, 0x2CC2(r13)
	  sth       r4, 0x2CBE(r13)

	.loc_0x204:
	  lwz       r3, 0x2CA8(r13)
	  rlwinm    r5,r6,0,17,31
	  li        r4, 0x1
	  bl        -0x8230

	.loc_0x214:
	  cmplwi    r31, 0xC
	  bne-      .loc_0x23C
	  li        r3, 0
	  li        r4, 0x64
	  bl        0x57C
	  li        r3, 0x1
	  li        r4, 0x64
	  bl        0x570
	  li        r3, 0x28
	  bl        -0x1A38

	.loc_0x23C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
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
	static int init   = 0;
	static f32 volume = 0.0f;
	static CmdQueue outerparam; // this type is wrong, I have no idea yet
	static seqp_* seqp;

	if (Jac_GetCurrentScene() != 5) {
		Jam_SetExtParamD(0, (int*)&outerparam, 1);
		return;
	}

	if (Jac_DemoCheck() == TRUE) {
		Jam_SetExtParamD(0, (int*)&outerparam, 1);
		return;
	}

	if (init == FALSE) {
		seqp = Jam_GetTrackHandle(0x10003);
		Jam_InitExtBuffer((int*)&outerparam);
		init = Jam_AssignExtBuffer(seqp, (int*)&outerparam);
		if (init == FALSE) {
			return;
		}
		Jam_OnExtSwitchD((int*)&outerparam, 1);

		if (gaya_timer < 150 || pikis < 1) {
			Jam_SetExtParamD(volume, (int*)&outerparam, 1);
			volume -= 0.05f;
			if (volume < 0.0f) {
				volume = 0.0f;
			}
			if (pikis == 0) {
				Jam_WritePortAppDirect(seqp, 0, (u16)pikis);
			}
		} else if (240 <= gaya_timer) {
			Jam_WritePortAppDirect(seqp, 0, (u16)pikis);
			volume += 0.05f;
			if (1.0f > volume) {
				volume = 1.0f;
			}
			Jam_SetExtParamD(volume, (int*)&outerparam, 1);
		}
		gaya_timer++;
	}

	f32 badcompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8036
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0x37C8
	  lbz       r0, 0x2CE8(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x34
	  li        r3, 0
	  li        r0, 0x1
	  stw       r3, 0x2CE4(r13)
	  stb       r0, 0x2CE8(r13)

	.loc_0x34:
	  lbz       r0, 0x2CF0(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x50
	  lfs       f0, -0x7E40(r2)
	  li        r0, 0x1
	  stb       r0, 0x2CF0(r13)
	  stfs      f0, 0x2CEC(r13)

	.loc_0x50:
	  bl        0x1030
	  cmplwi    r3, 0x5
	  beq-      .loc_0x70
	  lfs       f1, -0x7E40(r2)
	  addi      r3, r31, 0xD8
	  li        r4, 0x1
	  bl        -0x8048
	  b         .loc_0x1A0

	.loc_0x70:
	  bl        0x1950
	  cmpwi     r3, 0x1
	  bne-      .loc_0x90
	  lfs       f1, -0x7E40(r2)
	  addi      r3, r31, 0xD8
	  li        r4, 0x1
	  bl        -0x8068
	  b         .loc_0x1A0

	.loc_0x90:
	  lwz       r0, 0x2CE4(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0xDC
	  lis       r3, 0x1
	  addi      r3, r3, 0x3
	  bl        -0x8204
	  stw       r3, 0x2CE0(r13)
	  addi      r3, r31, 0xD8
	  bl        -0x81B0
	  lwz       r3, 0x2CE0(r13)
	  addi      r4, r31, 0xD8
	  bl        -0x819C
	  stw       r3, 0x2CE4(r13)
	  lwz       r0, 0x2CE4(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x1A0
	  addi      r3, r31, 0xD8
	  li        r4, 0x1
	  bl        -0x7FF8

	.loc_0xDC:
	  lwz       r0, 0x2C90(r13)
	  cmplwi    r0, 0x96
	  blt-      .loc_0xF4
	  lwz       r4, 0x2CDC(r13)
	  cmplwi    r4, 0x1
	  bge-      .loc_0x148

	.loc_0xF4:
	  lfs       f1, 0x2CEC(r13)
	  addi      r3, r31, 0xD8
	  li        r4, 0x1
	  bl        -0x80E0
	  lfs       f2, 0x2CEC(r13)
	  lfs       f1, -0x7E3C(r2)
	  lfs       f0, -0x7E40(r2)
	  fsubs     f1, f2, f1
	  stfs      f1, 0x2CEC(r13)
	  lfs       f1, 0x2CEC(r13)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x128
	  stfs      f0, 0x2CEC(r13)

	.loc_0x128:
	  lwz       r0, 0x2CDC(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x194
	  lwz       r3, 0x2CE0(r13)
	  rlwinm    r5,r0,0,16,31
	  li        r4, 0
	  bl        -0x8580
	  b         .loc_0x194

	.loc_0x148:
	  cmplwi    r0, 0xF0
	  blt-      .loc_0x194
	  lwz       r3, 0x2CE0(r13)
	  rlwinm    r5,r4,0,16,31
	  li        r4, 0
	  bl        -0x859C
	  lfs       f2, 0x2CEC(r13)
	  lfs       f1, -0x7E3C(r2)
	  lfs       f0, -0x7E38(r2)
	  fadds     f1, f2, f1
	  stfs      f1, 0x2CEC(r13)
	  lfs       f1, 0x2CEC(r13)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x184
	  stfs      f0, 0x2CEC(r13)

	.loc_0x184:
	  lfs       f1, 0x2CEC(r13)
	  addi      r3, r31, 0xD8
	  li        r4, 0x1
	  bl        -0x8170

	.loc_0x194:
	  lwz       r3, 0x2C90(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2C90(r13)

	.loc_0x1A0:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
