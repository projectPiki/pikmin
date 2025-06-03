#include "jaudio/noteon.h"

#include "jaudio/audiostruct.h"
#include "jaudio/jammain_2.h"
#include "jaudio/oneshot.h"
#include "jaudio/connect.h"
#include "jaudio/driverinterface.h"

/*
 * --INFO--
 * Address:	80013840
 * Size:	000394
 */
s32 NoteON(seqp_* track, s32 channel, s32 flag1, s32 flag2, s32 playFlag)
{
	if (track->_39E && (track->_39D & 0x40)) {
		return -1;
	}

	jc_** chan1 = &track->_9C[channel];
	if (*chan1) {
		NoteOFF(track, channel);
	}

	seqp_* parent = track->parent;
	jcs_* jcs     = &track->_D8;

	seqp_* temp = parent;
	while (jcs->_00 == 0 || jcs->_08 == 0) {
		if (temp == NULL) {
			jcs = &track->_D8;
			break;
		}
		jcs  = &temp->_D8;
		temp = temp->parent;
	}

	if (track->_3F == 4) {
		if (parent == NULL) {
			return -1;
		}
		if (jcs != &parent->_D8) {
			jc_* chan = List_GetChannel(&jcs->_08);
			if (chan) {
				jcs->_00--;
				List_AddChannel(&track->_D8._08, chan);
				parent->_D8._00++;
				chan->mMgr = &parent->_D8;
			}
			jcs = &parent->_D8;
		}
	} else if (jcs != &track->_D8) {
		jc_* chan = List_GetChannel(&jcs->_08);
		if (chan) {
			jcs->_00--;
			List_AddChannel(&track->_D8._08, chan);
			track->_D8._00++;
			chan->mMgr = &track->_D8;
		}
		jcs = &track->_D8;
	}

	u16 reg  = Jam_ReadRegDirect(track, 6);
	u16 phys = Jac_BnkVirtualToPhysical(reg >> 8);
	u32 a    = flag2 | (reg & 0xff | (phys & 0xff) << 8) << 0x10 | flag1 << 8;
	u32* ptr = &a;

	jc_* sound;
	if (a >= 0xf0) {
		SOUNDID_ id;
		id.value = a;
		sound    = Play_1shot_Osc(jcs, id, playFlag);
	} else if (a >= 0xe4) {
		SOUNDID_ id;
		id.value = a;
		sound    = Play_1shot_Perc(jcs, id, playFlag);
	} else {
		SOUNDID_ id;
		id.value = a;
		sound    = Play_1shot(jcs, id, playFlag);
	}
	*chan1 = sound;
	if (sound == NULL) {
		return -1;
	}
	track->_BC[channel] = sound->_126;
	UpdatePanPower_1Shot(sound, track->regParam.param._10[0], track->regParam.param._10[1], track->regParam.param._10[2],
	                     track->regParam.param._10[3]);

	for (u32 i = 0; i < 2; i++) {
		u32 flag = track->_370[i];
		if (flag == 15 || flag == 14) {
			continue;
		}

		if (flag >= 8) {
			flag -= 8;
			if (sound->mOscillators[flag]) {
				track->oscillators[i] = *sound->mOscillators[flag];
			}
		} else if (flag >= 3) {
			flag -= 4;
			s16* prev = track->oscillators[0].mReleaseVecOffset;
			if (sound->mOscillators[flag]) {
				track->oscillators[i]                   = *sound->mOscillators[flag];
				track->oscillators[0].mReleaseVecOffset = prev;
			}
		}
		Effecter_Overwrite_1ShotD(sound, &track->oscillators[i], flag);
	}

	Jam_UpdateTrack(track, 3);
	ResetInitialVolume(sound);
	return 0;

	u32 badcompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stmw      r22, 0x68(r1)
	  addi      r31, r3, 0
	  addi      r25, r5, 0
	  addi      r26, r6, 0
	  addi      r27, r7, 0
	  stw       r4, 0xC(r1)
	  lbz       r0, 0x39E(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x44
	  lbz       r0, 0x39D(r31)
	  rlwinm.   r0,r0,0,25,25
	  beq-      .loc_0x44
	  li        r3, -0x1
	  b         .loc_0x380

	.loc_0x44:
	  lwz       r30, 0xC(r1)
	  rlwinm    r0,r30,2,0,29
	  add       r29, r31, r0
	  lwzu      r0, 0x9C(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x68
	  addi      r3, r31, 0
	  rlwinm    r4,r30,0,24,31
	  bl        0x3DC

	.loc_0x68:
	  lwz       r23, 0x40(r31)
	  addi      r28, r31, 0xD8
	  addi      r3, r23, 0
	  b         .loc_0x90

	.loc_0x78:
	  cmplwi    r3, 0
	  bne-      .loc_0x88
	  addi      r28, r31, 0xD8
	  b         .loc_0xA8

	.loc_0x88:
	  addi      r28, r3, 0xD8
	  lwz       r3, 0x40(r3)

	.loc_0x90:
	  lwz       r0, 0x0(r28)
	  cmplwi    r0, 0
	  beq+      .loc_0x78
	  lwz       r0, 0x8(r28)
	  cmplwi    r0, 0
	  beq+      .loc_0x78

	.loc_0xA8:
	  lbz       r0, 0x3F(r31)
	  cmplwi    r0, 0x4
	  bne-      .loc_0x110
	  cmplwi    r23, 0
	  bne-      .loc_0xC4
	  li        r3, -0x1
	  b         .loc_0x380

	.loc_0xC4:
	  addi      r24, r23, 0xD8
	  cmplw     r28, r24
	  beq-      .loc_0x158
	  addi      r3, r28, 0x8
	  bl        -0xA414
	  mr.       r22, r3
	  beq-      .loc_0x108
	  lwz       r5, 0x0(r28)
	  addi      r4, r22, 0
	  addi      r3, r31, 0xE0
	  subi      r0, r5, 0x1
	  stw       r0, 0x0(r28)
	  bl        -0xA394
	  lwz       r3, 0xD8(r23)
	  addi      r0, r3, 0x1
	  stw       r0, 0xD8(r23)
	  stw       r24, 0x4(r22)

	.loc_0x108:
	  addi      r28, r23, 0xD8
	  b         .loc_0x158

	.loc_0x110:
	  addi      r24, r31, 0xD8
	  cmplw     r28, r24
	  beq-      .loc_0x158
	  addi      r3, r28, 0x8
	  bl        -0xA460
	  mr.       r22, r3
	  beq-      .loc_0x154
	  lwz       r5, 0x0(r28)
	  addi      r4, r22, 0
	  addi      r3, r31, 0xE0
	  subi      r0, r5, 0x1
	  stw       r0, 0x0(r28)
	  bl        -0xA3E0
	  lwz       r3, 0xD8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0xD8(r31)
	  stw       r24, 0x4(r22)

	.loc_0x154:
	  addi      r28, r31, 0xD8

	.loc_0x158:
	  addi      r3, r31, 0
	  li        r4, 0x6
	  bl        -0x3900
	  rlwinm    r23,r3,0,16,31
	  rlwinm    r3,r3,24,24,31
	  bl        -0x6B0C
	  rlwinm    r3,r3,8,16,23
	  rlwimi    r3,r23,0,24,31
	  rlwinm    r0,r25,8,0,23
	  rlwinm    r3,r3,16,0,15
	  rlwinm    r4,r23,0,24,31
	  or        r0, r3, r0
	  or        r0, r26, r0
	  cmplwi    r4, 0xF0
	  stw       r0, 0x40(r1)
	  blt-      .loc_0x1B8
	  lwz       r0, 0x40(r1)
	  addi      r4, r1, 0x34
	  addi      r3, r28, 0
	  mr        r5, r27
	  stw       r0, 0x34(r1)
	  bl        0x2DD4
	  mr        r28, r3
	  b         .loc_0x1FC

	.loc_0x1B8:
	  cmplwi    r4, 0xE4
	  blt-      .loc_0x1E0
	  lwz       r0, 0x40(r1)
	  addi      r4, r1, 0x30
	  addi      r3, r28, 0
	  mr        r5, r27
	  stw       r0, 0x30(r1)
	  bl        0x2B8C
	  mr        r28, r3
	  b         .loc_0x1FC

	.loc_0x1E0:
	  lwz       r0, 0x40(r1)
	  addi      r4, r1, 0x2C
	  addi      r3, r28, 0
	  mr        r5, r27
	  stw       r0, 0x2C(r1)
	  bl        0x28EC
	  mr        r28, r3

	.loc_0x1FC:
	  cmplwi    r28, 0
	  stw       r28, 0x0(r29)
	  bne-      .loc_0x210
	  li        r3, -0x1
	  b         .loc_0x380

	.loc_0x210:
	  rlwinm    r0,r30,1,0,30
	  lhz       r4, 0x126(r28)
	  add       r3, r31, r0
	  lis       r6, 0x4330
	  sth       r4, 0xBC(r3)
	  mr        r3, r28
	  lhz       r7, 0x27C(r31)
	  lhz       r5, 0x27E(r31)
	  lhz       r4, 0x280(r31)
	  lhz       r0, 0x282(r31)
	  stw       r7, 0x64(r1)
	  lfd       f4, -0x7EE0(r2)
	  stw       r5, 0x5C(r1)
	  stw       r4, 0x54(r1)
	  stw       r0, 0x4C(r1)
	  stw       r6, 0x60(r1)
	  stw       r6, 0x58(r1)
	  lfd       f1, 0x60(r1)
	  stw       r6, 0x50(r1)
	  lfd       f0, 0x58(r1)
	  fsubs     f1, f1, f4
	  stw       r6, 0x48(r1)
	  lfd       f3, 0x50(r1)
	  fsubs     f2, f0, f4
	  lfd       f0, 0x48(r1)
	  fsubs     f3, f3, f4
	  fsubs     f4, f0, f4
	  bl        0x24E4
	  li        r29, 0
	  li        r25, 0

	.loc_0x288:
	  addi      r0, r29, 0x370
	  lbzx      r0, r31, r0
	  cmplwi    r0, 0xF
	  mr        r5, r0
	  beq-      .loc_0x358
	  cmplwi    r5, 0xE
	  beq-      .loc_0x358
	  cmplwi    r5, 0x8
	  blt-      .loc_0x2F4
	  subi      r5, r5, 0x8
	  rlwinm    r3,r5,2,0,29
	  addi      r0, r3, 0x38
	  lwzx      r4, r28, r0
	  cmplwi    r4, 0
	  beq-      .loc_0x348
	  addi      r3, r25, 0x340
	  li        r0, 0x3
	  add       r6, r31, r3
	  subi      r4, r4, 0x8
	  mtctr     r0
	  subi      r6, r6, 0x8

	.loc_0x2DC:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r6)
	  stw       r0, 0x4(r6)
	  bdnz+     .loc_0x2DC
	  b         .loc_0x348

	.loc_0x2F4:
	  cmplwi    r5, 0x4
	  blt-      .loc_0x348
	  subi      r5, r5, 0x4
	  add       r4, r31, r25
	  rlwinm    r3,r5,2,0,29
	  lwz       r8, 0x34C(r4)
	  addi      r0, r3, 0x38
	  addi      r7, r4, 0x34C
	  lwzx      r3, r28, r0
	  cmplwi    r3, 0
	  beq-      .loc_0x348
	  li        r0, 0x3
	  addi      r6, r4, 0x338
	  subi      r4, r3, 0x8
	  mtctr     r0

	.loc_0x330:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r6)
	  stw       r0, 0x4(r6)
	  bdnz+     .loc_0x330
	  stw       r8, 0x0(r7)

	.loc_0x348:
	  addi      r4, r25, 0x340
	  addi      r3, r28, 0
	  add       r4, r31, r4
	  bl        0x19AC

	.loc_0x358:
	  addi      r29, r29, 0x1
	  addi      r25, r25, 0x18
	  cmplwi    r29, 0x2
	  blt+      .loc_0x288
	  addi      r3, r31, 0
	  li        r4, 0x3
	  bl        -0x2D90
	  mr        r3, r28
	  bl        -0x92F8
	  li        r3, 0

	.loc_0x380:
	  lmw       r22, 0x68(r1)
	  lwz       r0, 0x94(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80013BE0
 * Size:	000090
 */
s32 NoteOFF_R(seqp_* track, u8 param_2, u16 param_3)
{
	u8* REF_param_2;
	jc_* jc;

	REF_param_2 = &param_2;
	if (jc = track->_9C[param_2]) {
		if (jc->_126 == track->_BC[param_2]) {
			if (param_3 == 0) {
				Stop_1Shot(jc);
			} else {
				Stop_1Shot_R(jc, param_3);
			}
		}
		track->_9C[param_2] = NULL;
		track->_BC[param_2] = 0;
		return 1;
	}
	return 0;
}

/*
 * --INFO--
 * Address:	80013C80
 * Size:	000024
 */
s32 NoteOFF(seqp_* track, u8 param_2)
{
	return NoteOFF_R(track, param_2, 0);
}

/*
 * --INFO--
 * Address:	80013CC0
 * Size:	000058
 */
s32 GateON(seqp_* track, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
	s32* REF_param_3 = &param_3;

	if (track->_9C[param_2]) {
		Gate_1Shot(track->_9C[param_2], param_3, param_4, param_5);
	} else {
		return -1;
	}
	return 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void ProgramChange(s32 chan)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80013D20
 * Size:	000064
 */
BOOL CheckNoteStop(seqp_* track, s32 param_2)
{
	jc_* jc;

	if (jc = track->_9C[param_2]) {
		if (jc->_126 != track->_BC[param_2]) {
			track->_9C[param_2] = NULL;
			track->_BC[param_2] = 0;
			return TRUE;
		}
		if (jc->_01 == 0xff) {
			return TRUE;
		}
		return FALSE;
	}
	return TRUE;
}
