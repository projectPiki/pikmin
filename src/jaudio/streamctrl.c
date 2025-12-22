#include "jaudio/streamctrl.h"
#include "Dolphin/ai.h"
#include "Dolphin/dvd.h"
#include "jaudio/rate.h"

char J_STREAMNAME[8][16] = {
	"/stream00.adp", "/stream01.adp", "/stream02.adp", "/stream03.adp", "/stream04.adp", "/stream05.adp", "/stream06.adp", "/stream07.adp",
};

// clang-format off
JSTREAM J_STREAM = {
    JSTREAM_STATE_STOPPED,
    JSTREAM_NO_TRACK_ID, JSTREAM_NO_TRACK_ID,
    0.0f, 0,
    0,
    0,
    0.0f, 0,
    0.0f,
    0
};
// clang-format on

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void Jac_PlayStreamBGM(s32, s32, s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Jac_StopStreamBGM(s32, s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void Jac_VolMoveStreamBGM(s32 vol, s32)
{
	// this is just to make the magic int-to-float conversion double spawn earlier.
	J_STREAM.target_vol1 = vol;
	// UNUSED FUNCTION
}

void StreamMain()
{
	static DVDFileInfo finfo;
	static DVDCommandBlock cmd;
	volatile u32 streamed_samples;
	u32 trigger;

	switch (J_STREAM.state) {
	case JSTREAM_STATE_STOPPED:
		break;

	case JSTREAM_STATE_REQUEST_STREAM:
		J_STREAM.now_stream_id = J_STREAM.req_stream_id;
		J_STREAM.req_stream_id = JSTREAM_NO_TRACK_ID;
		if (J_STREAM.now_stream_id == JSTREAM_NO_TRACK_ID) {
			J_STREAM.state = JSTREAM_STATE_STOPPED;
		} else {
			if (DVDOpen(J_STREAMNAME[J_STREAM.now_stream_id], &finfo) == FALSE) {
				J_STREAM.now_stream_id = JSTREAM_NO_TRACK_ID;
				J_STREAM.state         = JSTREAM_STATE_STOPPED;
			} else {
				J_STREAM.total_samples = finfo.length;
				J_STREAM.total_samples = (J_STREAM.total_samples / 256) * 224; // TODO: should probably make these defines
				AISetStreamSampleRate(AI_SAMPLERATE_48KHZ);
				if (J_STREAM.fadein_vol_timer == 0) {
					J_STREAM.stream_vol = J_STREAM.fadein_vol;
				} else {
					J_STREAM.stream_vol = 0.0f;
				}

				AISetStreamVolLeft((s32)J_STREAM.stream_vol);
				AISetStreamVolRight((s32)J_STREAM.stream_vol);
				DVDPrepareStreamAsync(&finfo, 0, 0, NULL);
				J_STREAM.state = JSTREAM_STATE_START;
			}
		}
		break;

	case JSTREAM_STATE_START:
		if (DVDGetDriveStatus() == DVD_STATE_END) {
			AIResetStreamSampleCount();
			AISetStreamPlayState(AI_STREAM_START);
			J_STREAM.state = JSTREAM_STATE_PLAYING;
		}
		break;

	case JSTREAM_STATE_PLAYING:
		streamed_samples = AIGetStreamSampleCount();
		trigger          = AIGetStreamTrigger();

		if (J_STREAM.fadein_vol_timer != 0) {
			f32 vol = J_STREAM.fadein_vol;
			vol -= J_STREAM.stream_vol;
			vol /= (f32)J_STREAM.fadein_vol_timer;
			J_STREAM.stream_vol += vol;
			J_STREAM.fadein_vol_timer--;
			AISetStreamVolLeft((s32)J_STREAM.stream_vol);
			AISetStreamVolRight((s32)J_STREAM.stream_vol);
		}

		if (J_STREAM.change_vol_timer1 != 0) {
			f32 vol = J_STREAM.target_vol1;
			vol -= J_STREAM.stream_vol;
			vol /= (f32)J_STREAM.change_vol_timer1;
			J_STREAM.stream_vol += vol;
			J_STREAM.change_vol_timer1--;
			AISetStreamVolLeft((s32)J_STREAM.stream_vol);
			AISetStreamVolRight((s32)J_STREAM.stream_vol);
		}

		if ((J_STREAM.total_samples - streamed_samples) < (JAC_FRAMESAMPLES * JSTREAM_FADEOUT_TIMER)) {
			J_STREAM.state         = JSTREAM_STATE_FADEOUT;
			J_STREAM.fadeout_timer = JSTREAM_FADEOUT_TIMER;
		}
		break;

	case JSTREAM_STATE_CANCELLED:
	case JSTREAM_STATE_FADEOUT:
		u32 streamed_samples = AIGetStreamSampleCount();
		if (J_STREAM.fadeout_timer != 0 && (J_STREAM.total_samples - streamed_samples) != 0) {
			f32 vol = -J_STREAM.stream_vol;
			vol /= (f32)J_STREAM.fadeout_timer;
			J_STREAM.stream_vol += vol;
			J_STREAM.fadeout_timer--;
			AISetStreamVolLeft((s32)J_STREAM.stream_vol);
			AISetStreamVolRight((s32)J_STREAM.stream_vol);
		} else {
			DVDCancelStream(&cmd);
			J_STREAM.state = JSTREAM_STATE_STOP;
		}
		break;

	case JSTREAM_STATE_STOP:
		if (DVDGetDriveStatus() == DVD_STATE_END) {
			AISetStreamPlayState(AI_STREAM_STOP);
			J_STREAM.state = JSTREAM_STATE_CLEANUP;
		}
		break;

	case JSTREAM_STATE_CLEANUP:
		if (DVDGetDriveStatus() == DVD_STATE_END) {
			DVDClose(&finfo);
			J_STREAM.now_stream_id = -1;
			J_STREAM.state         = JSTREAM_STATE_REQUEST_STREAM;
			AISetStreamPlayState(AI_STREAM_STOP);
		}
		break;
	}

	STACK_PAD_VAR(4);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  lis       r4, 0x802F
	  stwu      r1, -0x48(r1)
	  stmw      r28, 0x38(r1)
	  addi      r31, r3, 0x2DE0
	  subi      r30, r4, 0x6940
	  lwz       r0, 0x80(r31)
	  cmplwi    r0, 0x7
	  bgt-      .loc_0x388
	  lis       r3, 0x8022
	  rlwinm    r0,r0,2,0,29
	  addi      r3, r3, 0x2E8C
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lwz       r0, 0x84(r31)
	  li        r29, -0x1
	  addi      r28, r31, 0x88
	  stw       r0, 0x88(r31)
	  stw       r29, 0x84(r31)
	  lwz       r0, 0x88(r31)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x70
	  li        r0, 0
	  stw       r0, 0x80(r31)
	  b         .loc_0x388

	.loc_0x70:
	  rlwinm    r0,r0,4,0,27
	  addi      r4, r30, 0
	  add       r3, r31, r0
	  bl        0x1F8AB0
	  cmpwi     r3, 0
	  bne-      .loc_0x98
	  stw       r29, 0x0(r28)
	  li        r0, 0
	  stw       r0, 0x80(r31)
	  b         .loc_0x388

	.loc_0x98:
	  lwz       r0, 0x34(r30)
	  li        r3, 0x1
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0xA8(r31)
	  rlwinm    r0,r0,24,8,31
	  mulli     r0, r0, 0xE0
	  stw       r0, 0xA8(r31)
	  bl        0x1FFA68
	  lwz       r0, 0x90(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0xD0
	  lfs       f0, 0x8C(r31)
	  stfs      f0, 0xA4(r31)
	  b         .loc_0xD8

	.loc_0xD0:
	  lfs       f0, -0x7FE0(r2)
	  stfs      f0, 0xA4(r31)

	.loc_0xD8:
	  addi      r28, r31, 0xA4
	  lfs       f0, 0xA4(r31)
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  rlwinm    r3,r0,0,24,31
	  bl        0x1FFB38
	  lfs       f0, 0x0(r28)
	  fctiwz    f0, f0
	  stfd      f0, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  rlwinm    r3,r0,0,24,31
	  bl        0x1FFB4C
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  bl        0x1F8F4C
	  li        r0, 0x2
	  stw       r0, 0x80(r31)
	  b         .loc_0x388
	  bl        0x1FB004
	  cmpwi     r3, 0
	  bne-      .loc_0x388
	  bl        0x1FF7E0
	  li        r3, 0x1
	  bl        0x1FF800
	  li        r0, 0x3
	  stw       r0, 0x80(r31)
	  b         .loc_0x388
	  bl        0x1FF7B8
	  stw       r3, 0x1C(r1)
	  bl        0x1FF7D8
	  addi      r4, r31, 0x90
	  lwz       r0, 0x90(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x1E0
	  xoris     r0, r0, 0x8000
	  addi      r28, r31, 0xA4
	  stw       r0, 0x2C(r1)
	  lis       r0, 0x4330
	  lfs       f3, 0x8C(r31)
	  stw       r0, 0x28(r1)
	  lfs       f2, 0xA4(r31)
	  lfd       f1, -0x7FE8(r2)
	  lfd       f0, 0x28(r1)
	  fsubs     f3, f3, f2
	  fsubs     f0, f0, f1
	  fdivs     f3, f3, f0
	  fadds     f0, f2, f3
	  stfs      f0, 0xA4(r31)
	  lwz       r3, 0x0(r4)
	  subi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  lfs       f0, 0xA4(r31)
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  rlwinm    r3,r0,0,24,31
	  bl        0x1FFA64
	  lfs       f0, 0x0(r28)
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  rlwinm    r3,r0,0,24,31
	  bl        0x1FFA78

	.loc_0x1E0:
	  addi      r4, r31, 0xA0
	  lwz       r0, 0xA0(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x264
	  xoris     r0, r0, 0x8000
	  addi      r28, r31, 0xA4
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lfs       f3, 0x9C(r31)
	  stw       r0, 0x20(r1)
	  lfs       f2, 0xA4(r31)
	  lfd       f1, -0x7FE8(r2)
	  lfd       f0, 0x20(r1)
	  fsubs     f3, f3, f2
	  fsubs     f0, f0, f1
	  fdivs     f3, f3, f0
	  fadds     f0, f2, f3
	  stfs      f0, 0xA4(r31)
	  lwz       r3, 0x0(r4)
	  subi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  lfs       f0, 0xA4(r31)
	  fctiwz    f0, f0
	  stfd      f0, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  rlwinm    r3,r0,0,24,31
	  bl        0x1FF9E0
	  lfs       f0, 0x0(r28)
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  rlwinm    r3,r0,0,24,31
	  bl        0x1FF9F4

	.loc_0x264:
	  lwz       r0, -0x7FF8(r13)
	  lwz       r4, 0x1C(r1)
	  lwz       r3, 0xA8(r31)
	  mulli     r0, r0, 0x78
	  sub       r3, r3, r4
	  cmplw     r3, r0
	  bge-      .loc_0x388
	  li        r3, 0x5
	  li        r0, 0x78
	  stw       r3, 0x80(r31)
	  stw       r0, 0x98(r31)
	  b         .loc_0x388
	  bl        0x1FF674
	  addi      r5, r31, 0x98
	  lwz       r4, 0x98(r31)
	  cmpwi     r4, 0
	  beq-      .loc_0x328
	  lwz       r0, 0xA8(r31)
	  sub.      r0, r0, r3
	  beq-      .loc_0x328
	  xoris     r0, r4, 0x8000
	  addi      r28, r31, 0xA4
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lfs       f2, 0xA4(r31)
	  stw       r0, 0x20(r1)
	  lfd       f1, -0x7FE8(r2)
	  fneg      f3, f2
	  lfd       f0, 0x20(r1)
	  fsubs     f0, f0, f1
	  fdivs     f3, f3, f0
	  fadds     f0, f2, f3
	  stfs      f0, 0xA4(r31)
	  lwz       r3, 0x0(r5)
	  subi      r0, r3, 0x1
	  stw       r0, 0x0(r5)
	  lfs       f0, 0xA4(r31)
	  fctiwz    f0, f0
	  stfd      f0, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  rlwinm    r3,r0,0,24,31
	  bl        0x1FF920
	  lfs       f0, 0x0(r28)
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  rlwinm    r3,r0,0,24,31
	  bl        0x1FF934
	  b         .loc_0x388

	.loc_0x328:
	  addi      r3, r30, 0x3C
	  bl        0x1FACF8
	  li        r0, 0x6
	  stw       r0, 0x80(r31)
	  b         .loc_0x388
	  bl        0x1FADF4
	  cmpwi     r3, 0
	  bne-      .loc_0x388
	  li        r3, 0
	  bl        0x1FF5F4
	  li        r0, 0x7
	  stw       r0, 0x80(r31)
	  b         .loc_0x388
	  bl        0x1FADD4
	  cmpwi     r3, 0
	  bne-      .loc_0x388
	  mr        r3, r30
	  bl        0x1F8888
	  li        r3, -0x1
	  li        r0, 0x1
	  stw       r3, 0x88(r31)
	  li        r3, 0
	  stw       r0, 0x80(r31)
	  bl        0x1FF5BC

	.loc_0x388:
	  lmw       r28, 0x38(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}
