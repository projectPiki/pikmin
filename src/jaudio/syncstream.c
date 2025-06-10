#include "jaudio/syncstream.h"
#include "jaudio/audiostruct.h"
#include "jaudio/dspinterface.h"
#include "Dolphin/dvd.h"
#include "jaudio/aictrl.h"
#include "jaudio/rate.h"
#include "jaudio/interleave.h"
#include "jaudio/dvdthread.h"
#include "jaudio/dspdriver.h"
#include "jaudio/playercall.h"

// fabricated, size 0x14.
struct UNK_STRUCT {
	DVDFileInfo* fileinfo; // _00
	void* addr;            // _04
	s32 length;            // _08
	s32 offset;            // _0C
	DVDCallback callback;  // _10
};

typedef struct UNK_STRUCT UNK_STRUCT;

static StreamCtrl_ SC[1];
static UNK_STRUCT copyinfo;

static StreamCallback default_streamsync_call;

static UNK_STRUCT* copy = &copyinfo;

/*
 * --INFO--
 * Address:	8001BBE0
 * Size:	000038
 */
void Stop_DirectPCM(dspch_* dspch)
{
	DSP_PlayStop(dspch->buffer_idx);
	DSP_FlushChannel(dspch->buffer_idx);
}

/*
 * --INFO--
 * Address:	8001BC20
 * Size:	0000DC
 */
void Play_DirectPCM(dspch_* dspch, s16* baseAddr, u16 loopStart, u32 length)
{
	DSPchannel_* buff = GetDspHandle(dspch->buffer_idx); // r3

	buff->baseAddress       = (u32)baseAddr;
	buff->isLooping         = FALSE;
	buff->samplesSourceType = 0x21; // todo: find out what this is
	buff->remainingLength   = length;
	buff->loopAddress       = (u32)baseAddr;
	buff->loopStartPosition = loopStart << 16;

	DSP_SetMixerInitDelayMax(dspch->buffer_idx, 0);

	for (u32 i = 0; i < 6; i++) {

		if (i < 2) {
			DSP_SetMixerInitVolume(dspch->buffer_idx, i, 0x7fff, 0);
		} else {
			DSP_SetMixerInitVolume(dspch->buffer_idx, i, 0, 0);
		}

		DSP_SetBusConnect(dspch->buffer_idx, i, i + 1);
	}

	DSP_SetPitch(dspch->buffer_idx, 0x800);
	DSP_PlayStart(dspch->buffer_idx);
	DSP_FlushChannel(dspch->buffer_idx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void Get_DirectPCM_LoopRemain(DSPchannel_* channel)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001BD00
 * Size:	00000C
 */
u16 Get_DirectPCM_Counter(DSPchannel_* channel)
{
	return channel->currentPosition >> 16;
}

/*
 * --INFO--
 * Address:	8001BD20
 * Size:	000008
 */
u32 Get_DirectPCM_Remain(DSPchannel_* channel)
{
	return channel->remainingLength;
}

/*
 * --INFO--
 * Address:	8001BD40
 * Size:	00003C
 */
static void __DVDReadAsyncRetry()
{
	DVDReadAsyncPrio(copy->fileinfo, copy->addr, copy->length, copy->offset, copy->callback, 1);
}

/*
 * --INFO--
 * Address:	8001BD80
 * Size:	000048
 */
static void DVDReadAsyncPrio2(DVDFileInfo* info, void* addr, s32 length, s32 offs, DVDCallback callback, s32 prio)
{
	copy->fileinfo = info;
	copy->addr     = addr;
	copy->length   = length;
	copy->offset   = offs;
	copy->callback = callback;
	__DVDReadAsyncRetry();
}

static void LoadADPCM(StreamCtrl_*, int);

/*
 * --INFO--
 * Address:	8001BDE0
 * Size:	00014C
 */
static void __LoadFin(s32 size, DVDFileInfo* fileinfo)
{

	StreamCtrl_* ctrl;

	for (int i = 0; i < ARRAY_SIZE(SC); i++) {
		DVDFileInfo* info = &SC[i].fileinfo;

		if (fileinfo == info) {
			ctrl = &SC[i];
		}
	}

	ctrl->_21A48 = 0;

	u32 idx = ctrl->buffCtrlMain._02;

	// TODO: find the max value for ctrl->_21942 to resolve _218C0 size, and determine if really BufControl_
	BufControl_* buff = &ctrl->buffCtrl[idx];

	if (ctrl->_21A34 == 1) {
		u8* data = (u8*)buff->_0C;
		DCInvalidateRange(data, 0x20);

		// what in tarnation
		if (data[0] == 0xff && data[1] == 0xad && data[2] == 0xbe && data[3] == 0xef && data[4] == 0xde && data[5] == 0xad
		    && data[6] == 0xbe && data[7] == 0xef) {
			__DVDReadAsyncRetry();
			return;
		}
	}

	buff->_00 = 2;

	ctrl->buffCtrlMain._02 = (idx + 1) % ctrl->buffCtrlMain._01;

	if (ctrl->_21970 == 0) {
		ctrl->_21A44 = 1;
		return;
	}

	if (ctrl->_21A34 == 0) {
		return;
	}

	LoadADPCM(ctrl, 0);
}

/*
 * --INFO--
 * Address:	8001BF40
 * Size:	000190
 */
static void LoadADPCM(StreamCtrl_* ctrl, int r28)
{
	u32 size;
	u32 idx           = ctrl->buffCtrlMain._02;
	BufControl_* buff = &ctrl->buffCtrl[idx];
	u32 oldsize;
	u32 badCompiler[2];

	if (ctrl->_21A48) {
		return;
	}

	if (buff->_00) {
		return;
	}

	oldsize = ctrl->_21970;
	!oldsize;
	if (oldsize == 0) {
		return;
	}

	size = ctrl->_21978;

	if (oldsize < size) {
		size = oldsize;
	}

	if (!ctrl->_21A34) {
		if (!Jac_CheckStreamRemain(size)) {
			return;
		}
	}

	buff->_04 = 0;
	buff->_08 = size;
	buff->_00 = 1;

	if (r28) {
		ctrl->buffCtrlMain._0C = size;
		ctrl->buffCtrlMain._08 = 0;
	}

	u32 oldSize = ctrl->_21974;

	ctrl->_21974 += size;
	ctrl->_21970 -= size;
	ctrl->_2197C = size;

	switch (ctrl->_21A34) {
	case 0:
		Jac_GetStreamData((u8*)buff->_0C, size);
		__LoadFin(size, &ctrl->fileinfo);
		break;
	case 1:
		u8* data = (u8*)buff->_0C;
		data[0]  = 0xff;
		data[1]  = 0xad;
		data[2]  = 0xbe;
		data[3]  = 0xef;
		data[4]  = 0xde;
		data[5]  = 0xad;
		data[6]  = 0xbe;
		data[7]  = 0xef;

		DCStoreRange((void*)buff->_0C, size);

		ctrl->_21A48 = 1;

		DVDReadAsyncPrio2(&ctrl->fileinfo, (void*)buff->_0C, size, oldSize, __LoadFin, 1);

		break;
	}
}

/*
 * --INFO--
 * Address:	8001C0E0
 * Size:	000020
 */
static void BufContInit(BufControl_* ctrl, u8 a, u8 b, u8 c, u8 d, u32 e, u32 f, u32 g)
{
	ctrl->_00 = a;
	ctrl->_01 = b;
	ctrl->_02 = c;
	ctrl->_03 = d;
	ctrl->_04 = e;
	ctrl->_08 = f;
	ctrl->_0C = g;
}

/*
 * --INFO--
 * Address:	8001C100
 * Size:	000030
 */
void Init_StreamAudio(void)
{
	for (int i = 0; i < ARRAY_SIZE(SC); i++) {
		SC[i]._21984 = 4;
		SC[i]._21A0C = i;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Get_StreamAudio_Handle(void)
{
	// UNUSED FUNCTION
}

static s32 StreamAudio_Callback(void*);

/*
 * --INFO--
 * Address:	8001C140
 * Size:	000318
 */
BOOL StreamAudio_Start(u32 ctrlID, int r4, char* name, int r6, int r7, StreamHeader_* header)
{
	StreamCtrl_* ctrl = &SC[ctrlID];
	int i;
	u32 badCompiler[2];

	ctrl->_21A0C   = ctrlID;
	ctrl->_21A10   = r4;
	ctrl->_219AC   = 0;
	ctrl->_219B4   = 0;
	ctrl->isPaused = FALSE;

	if (name) {
		Jac_DVDOpen(name, &ctrl->fileinfo);
		ctrl->_21A34 = 1;
	} else {
		ctrl->_21A34 = 0;
	}

	if (!header) {
		if (!ctrl->_21A34) {
			return FALSE;
		}

		DVDReadPrio(&ctrl->fileinfo, &ctrl->_00[0].header, 0x20, 0, 1);
		ctrl->header = ctrl->_00[0].header;
		ctrl->_21974 = 0x20;
	} else {
		ctrl->header = *header;
		ctrl->_21974 = 0;
	}

	ctrl->_21970 = ctrl->header._00;
	ctrl->_219FC = ctrl->header._04;
	ctrl->_21980 = 0;
	ctrl->_21A40 = 0;
	ctrl->_21A44 = 0;
	ctrl->_21A08 = 0;
	ctrl->_21984 = 0;

	for (i = 0; i < 6; i++) {
		ctrl->buffCtrl[i]._00 = 0;
		ctrl->buffCtrl[i]._0C = (u32)&ctrl->_00[i]; // TODO: should be a pointer?
	}

	for (i = 0; i < 2; i++) {
		ctrl->buffCtrlExtra[i]._00 = 0;
	}

	ctrl->_21A00 = 0x1000;

	BufContInit(&ctrl->buffCtrlMain, 1, 6, 0, 0, 0x2400, 0, 0);
	BufContInit(&ctrl->buffCtrlMain2, 2, 2, 0, 0, 0x2000, 0, 0);
	BufContInit(&ctrl->buffCtrlMain3, 2, 4, 0, 3, 0x400, 0, 0);

	switch (ctrl->header.audioFormat) {
	case 2:
		ctrl->_21978 = 0x2400;
		break;

	case 3:
		ctrl->_21978 = 0x1200;
		break;
	case AUDIOFRMT_ADPCM:
		ctrl->_21978 = 0x2400;
		break;

	case AUDIOFRMT_ADPCM4X:
		ctrl->_21978 = 0x2400;
		break;
	}

	ctrl->_219A8 = r6;
	ctrl->_21A48 = 0;
	LoadADPCM(ctrl, 1);

	for (u32 i = 0; i < 2; i++) {
		DeAllocDSPchannel(ctrl->dspch[i], (u32)(&ctrl->dspch[i]));

		ctrl->dspch[i] = 0;
	}

	ctrl->_21A30 = 1.0f;

	ctrl->volume[0] = 0x3fff;
	ctrl->volume[1] = 0x3fff;

	ctrl->mixLevel[0] = 0x5fff;
	ctrl->mixLevel[1] = 0x5fff;

	ctrl->_21A14 = default_streamsync_call;

	Jac_RegisterDspPlayerCallback(StreamAudio_Callback, ctrl);

	return TRUE;
}

static void __PcmToLoop(StreamCtrl_*);
static void __StreamChgVolume(StreamCtrl_* ctrl);
static void __StreamChgPitch(StreamCtrl_* ctrl);
static void* __Decode(StreamCtrl_* ctrl);
/*
 * --INFO--
 * Address:	8001C460
 * Size:	0008A8
 */
static s32 StreamAudio_Callback(void* data)
{
	StreamCtrl_* ctrl = (StreamCtrl_*)data;
	int r25           = 0;
	u32 i;
	u32 badCompiler[2];

	if (!ctrl->dspch[0]) {
		for (i = 0; i < 2; i++) {
			ctrl->dspch[i]      = AllocDSPchannel(0, (u32)&ctrl->dspch[i]); // TODO: suspicious cast
			ctrl->dspch[i]->_03 = 0x7f;
		}
	}

	if (ctrl->_21A08) {
		DSPchannel_* buff = GetDspHandle(ctrl->dspch[0]->buffer_idx);
		if (buff->done) {
			ctrl->_219B4 = 1;
		}

		if (ctrl->_219B4) {
			if (ctrl->buffCtrl[ctrl->buffCtrlMain._02]._00 == 1) {
				return 0;
			}

			for (i = 0; i < 2; i++) {
				Stop_DirectPCM(ctrl->dspch[i]);
				DeAllocDSPchannel(ctrl->dspch[i], (u32)&ctrl->dspch[i]); // TODO: suspicious cast
				ctrl->dspch[i] = NULL;
			}

			if (ctrl->_21A14) {
				ctrl->_21A14(ctrl->_21A0C, -1);
			}

			ctrl->_21984 = 4;
			ctrl->_21A10 = -1;

			if (ctrl->_21A34) {
				DVDClose(&ctrl->fileinfo);
			}
			return -1;
		}

		int r4 = ctrl->_21980 * ctrl->header._0E / ctrl->header._08;

		if (ctrl->_21A14) {
			int callbackResult = ctrl->_21A14(ctrl->_21A0C, r4);
			// TODO: Figure out what this -1 means
			if (callbackResult == -1) {
				ctrl->_219AC = 1;
			}
		}

		ctrl->_21A08++;

		u16 var_r3 = ctrl->_21A00 - Get_DirectPCM_Counter(buff);
		if (var_r3 == 0) {
			var_r3 = ctrl->_21A00;
		}
		u32 var_r4              = (ctrl->_21A00 - var_r3) >> 10;
		ctrl->buffCtrlMain3._03 = var_r4;
		if (ctrl->buffCtrlMain3._02 != var_r4) {
			r25 = 1;
		} else {
			r25 = 0;
		}
	}

	if (ctrl->_21A38) {
		if (ctrl->_21A38 & 1) {
			__StreamChgVolume(ctrl);
		}

		if (ctrl->_21A38 & 2) {
			__StreamChgPitch(ctrl);
		}

		ctrl->_21A38 = 0;

		DSP_FlushChannel(ctrl->dspch[0]->buffer_idx);
		DSP_FlushChannel(ctrl->dspch[1]->buffer_idx);
	}

	if (ctrl->isPaused) {
		DSP_SetPauseFlag(ctrl->dspch[0]->buffer_idx, 1);
		DSP_SetPauseFlag(ctrl->dspch[1]->buffer_idx, 1);

		DSP_FlushChannel(ctrl->dspch[0]->buffer_idx);
		DSP_FlushChannel(ctrl->dspch[1]->buffer_idx);

		ctrl->_21984 = 6;
		return 0;
	}

	if (ctrl->_21984 == 6) {
		if (!ctrl->isPaused) {
			ctrl->_21984 = 1;
			DSP_SetPauseFlag(ctrl->dspch[0]->buffer_idx, 0);
			DSP_SetPauseFlag(ctrl->dspch[1]->buffer_idx, 0);

			DSP_FlushChannel(ctrl->dspch[0]->buffer_idx);
			DSP_FlushChannel(ctrl->dspch[1]->buffer_idx);
		} else {
			return 0;
		}
	}

	if (ctrl->_21A44 == 0 && ctrl->_21984 != 5 && ctrl->_21A08 != 0) {
		DSPchannel_* buff = GetDspHandle(ctrl->dspch[0]->buffer_idx);
		u32 size          = ctrl->_219FC - Get_DirectPCM_Remain(buff);

		ctrl->_21A4C = ctrl->_21A40 - size;
		if (ctrl->_21A4C < 0x400) {
			DSP_SetPauseFlag(ctrl->dspch[0]->buffer_idx, 1);
			DSP_SetPauseFlag(ctrl->dspch[1]->buffer_idx, 1);

			DSP_FlushChannel(ctrl->dspch[0]->buffer_idx);
			DSP_FlushChannel(ctrl->dspch[1]->buffer_idx);

			ctrl->_21984 = 5;
		}
	}

	if (ctrl->_21984 == 5) {
		DSPchannel_* buff = GetDspHandle(ctrl->dspch[0]->buffer_idx);
		u32 size          = ctrl->_219FC - Get_DirectPCM_Remain(buff);

		if (ctrl->_21A40 - size > 0xc00 || ctrl->_21A44 == 1) {
			DSP_SetPauseFlag(ctrl->dspch[0]->buffer_idx, 0);
			DSP_SetPauseFlag(ctrl->dspch[1]->buffer_idx, 0);

			DSP_FlushChannel(ctrl->dspch[0]->buffer_idx);
			DSP_FlushChannel(ctrl->dspch[1]->buffer_idx);

			ctrl->_21984 = 1;
		} else {
			DSP_SetPauseFlag(ctrl->dspch[0]->buffer_idx, 1);
			DSP_SetPauseFlag(ctrl->dspch[1]->buffer_idx, 1);

			DSP_FlushChannel(ctrl->dspch[0]->buffer_idx);
			DSP_FlushChannel(ctrl->dspch[1]->buffer_idx);
		}
	}

	if (ctrl->buffCtrl[ctrl->buffCtrlMain._03]._00 == 2 && ctrl->buffCtrlExtra[ctrl->buffCtrlMain2._02]._00 == 0) {
		void* data = __Decode(ctrl);

		ctrl->buffCtrl[ctrl->buffCtrlMain._03]._00 = 0;

		ctrl->buffCtrlExtra[ctrl->buffCtrlMain2._02]._00 = 2;
		ctrl->buffCtrlExtra[ctrl->buffCtrlMain2._02]._04 = 0;
		ctrl->buffCtrlExtra[ctrl->buffCtrlMain2._02]._08 = (u32)data; // TODO: suspicious cast

		ctrl->buffCtrlMain._03 = (ctrl->buffCtrlMain._03 + 1) % 6;

		ctrl->buffCtrlMain2._02 = (ctrl->buffCtrlMain2._02 + 1) % 2;
		ctrl->buffCtrlMain2._0C += (u32)data; // TODO: suspicious cast
	}

	if (r25 == 1 || ctrl->_21A08 == 0) {
		if (ctrl->buffCtrlMain3._02 != ctrl->buffCtrlMain3._03) {
			if (ctrl->buffCtrlExtra[ctrl->buffCtrlMain2._03]._00 == 2 && ctrl->buffCtrlMain2._0C >= ctrl->buffCtrlMain3._04) {
				__PcmToLoop(ctrl);
				ctrl->buffCtrlMain3._02 = (ctrl->buffCtrlMain3._02 + 1) % 4;
				ctrl->buffCtrlMain2._0C -= ctrl->buffCtrlMain3._04;
			}
		} else if (ctrl->_21A08 == 0) {
			if (ctrl->_219A8 == 1) {
				if (ctrl->_21A14 != NULL) {
					int callbackResult = ctrl->_21A14(ctrl->_21A0C, 0);
					if (callbackResult == -1) {
						ctrl->_219AC = 1;
					}
					if (callbackResult == 1) {
						ctrl->_219A8 = 0;
					}
				}
				ctrl->_21984 = 2;
				if (ctrl->_219AC == 0) {
					return 0;
				}
			} else {
				ctrl->_21984 = 1;
				ctrl->_21A08++;
				u32 mode = Jac_GetOutputMode();
				for (i = 0; i < 2; i++) {
					u16 pitch = (4096.0f * ctrl->header._08 * ctrl->_21A30) / JAC_DAC_RATE;
					Play_DirectPCM(ctrl->dspch[i], ctrl->_1D8C0[i], ctrl->_21A00, ctrl->_219FC);
					switch (mode) {
					case 0:
						DSP_SetMixerInitVolume(ctrl->dspch[i]->buffer_idx, i, ctrl->volume[i] * 0xBFFD / 0x10000, 0);
						DSP_SetMixerInitVolume(ctrl->dspch[i]->buffer_idx, 1 - i, ctrl->volume[i] * 0xBFFD / 0x10000, 0);
						break;

					default:
						DSP_SetMixerInitVolume(ctrl->dspch[i]->buffer_idx, i, ctrl->volume[i], 0);
						DSP_SetMixerInitVolume(ctrl->dspch[i]->buffer_idx, 1 - i, 0, 0);
						break;
					}
					DSP_SetPitch(ctrl->dspch[i]->buffer_idx, pitch);
					DSP_FlushChannel(ctrl->dspch[i]->buffer_idx);
				}
			}
		}
	}

	if (ctrl->_21984 == 3) {
		return 0;
	}

	if (ctrl->_219AC != 0) {
		if (ctrl->_21A08 == 0) {
			if (ctrl->buffCtrl[ctrl->buffCtrlMain._02]._00 == 1) {
				return 0;
			}
			ctrl->_219AC = 0;
			if (ctrl->_21A14 != NULL) {
				ctrl->_21A14(ctrl->_21A0C, -1);
			}
			ctrl->_21984 = 4;
			ctrl->_21A10 = -1;
			return -1;
		}
		ctrl->_219AC = 0;
		ctrl->_21984 = 3;
		for (i = 0; i < 2; i++) {
			ForceStopDSPchannel(ctrl->dspch[i]);
		}
	} else {
		LoadADPCM(ctrl, 0);
	}
	return 0;
}

/*
 * --INFO--
 * Address:	8001CD20
 * Size:	000008
 */
void RegisterStreamCallback(StreamCallback callback)
{
	default_streamsync_call = callback;
}

/*
 * --INFO--
 * Address:	8001CD40
 * Size:	000194
 */
void Jac_Decode_ADPCM(u8*, u16*, u16*, int, int, u16*)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x48(r1)
	  lis       r9, 0x8022
	  addi      r9, r9, 0x6F70
	  rlwinm    r0,r7,0,24,31
	  stmw      r24, 0x28(r1)
	  li        r27, 0
	  lha       r31, 0x0(r8)
	  lha       r30, 0x2(r8)
	  lha       r29, 0x4(r8)
	  lha       r28, 0x6(r8)
	  b         .loc_0x170

	.loc_0x2C:
	  lbz       r7, 0x0(r3)
	  li        r10, 0x8
	  rlwinm    r12,r7,28,28,31
	  rlwinm    r7,r7,2,26,29
	  add       r7, r9, r7
	  lha       r11, 0x0(r7)
	  lha       r7, 0x2(r7)
	  mtctr     r10
	  addi      r3, r3, 0x1

	.loc_0x50:
	  lbz       r25, 0x0(r3)
	  extsh     r10, r31
	  mullw     r31, r11, r10
	  extsh     r30, r30
	  srawi     r24, r25, 0x4
	  rlwinm    r25,r25,1,27,30
	  add       r26, r9, r25
	  rlwinm    r24,r24,1,23,30
	  mullw     r25, r7, r30
	  add       r24, r9, r24
	  lha       r24, 0x40(r24)
	  addi      r3, r3, 0x1
	  slw       r24, r24, r12
	  add       r25, r31, r25
	  srawi     r25, r25, 0xB
	  add       r24, r24, r25
	  extsh     r30, r24
	  sth       r30, 0x0(r4)
	  mullw     r25, r11, r30
	  lha       r26, 0x40(r26)
	  slw       r26, r26, r12
	  mullw     r10, r7, r10
	  add       r10, r25, r10
	  srawi     r10, r10, 0xB
	  add       r10, r26, r10
	  extsh     r10, r10
	  sth       r10, 0x2(r4)
	  addi      r31, r10, 0
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x50
	  cmplwi    r0, 0
	  beq-      .loc_0x16C
	  lbz       r7, 0x0(r3)
	  li        r10, 0x8
	  rlwinm    r11,r7,28,28,31
	  rlwinm    r7,r7,2,26,29
	  add       r7, r9, r7
	  lha       r12, 0x0(r7)
	  lha       r7, 0x2(r7)
	  mtctr     r10
	  addi      r3, r3, 0x1

	.loc_0xF4:
	  lbz       r24, 0x0(r3)
	  extsh     r10, r29
	  extsh     r28, r28
	  addi      r3, r3, 0x1
	  mullw     r29, r12, r10
	  srawi     r25, r24, 0x4
	  rlwinm    r25,r25,1,23,30
	  add       r25, r9, r25
	  lha       r25, 0x40(r25)
	  rlwinm    r26,r24,1,27,30
	  add       r26, r9, r26
	  mullw     r28, r7, r28
	  slw       r25, r25, r11
	  add       r28, r29, r28
	  srawi     r28, r28, 0xB
	  add       r24, r25, r28
	  extsh     r28, r24
	  sth       r28, 0x0(r5)
	  mullw     r29, r12, r28
	  lha       r26, 0x40(r26)
	  slw       r26, r26, r11
	  mullw     r10, r7, r10
	  add       r10, r29, r10
	  srawi     r10, r10, 0xB
	  add       r10, r26, r10
	  extsh     r10, r10
	  sth       r10, 0x2(r5)
	  addi      r29, r10, 0
	  addi      r5, r5, 0x4
	  bdnz+     .loc_0xF4

	.loc_0x16C:
	  addi      r27, r27, 0x1

	.loc_0x170:
	  cmplw     r27, r6
	  blt+      .loc_0x2C
	  sth       r31, 0x0(r8)
	  sth       r30, 0x2(r8)
	  sth       r29, 0x4(r8)
	  sth       r28, 0x6(r8)
	  lmw       r24, 0x28(r1)
	  addi      r1, r1, 0x48
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001CEE0
 * Size:	0000D0
 */
static void* __DecodeADPCM(StreamCtrl_* ctrl)
{
	u32 a = ctrl->buffCtrlMain2._02;
	u32 b = ctrl->buffCtrlMain._03;
	if (ctrl->_21A08 == 0 && b == 0) {
		for (int i = 0; i < 4; i++) {
			ctrl->_21A18[i] = 0;
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  addis     r4, r3, 0x2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r30, 0x20(r1)
	  lwz       r0, 0x1A08(r4)
	  lbz       r7, 0x1952(r4)
	  cmplwi    r0, 0
	  lbz       r8, 0x1943(r4)
	  bne-      .loc_0x54
	  cmplwi    r8, 0
	  bne-      .loc_0x54
	  li        r4, 0
	  li        r0, 0x4
	  addi      r6, r4, 0
	  mtctr     r0

	.loc_0x40:
	  addis     r5, r4, 0x2
	  addi      r4, r4, 0x2
	  addi      r5, r5, 0x1A18
	  sthx      r6, r3, r5
	  bdnz+     .loc_0x40

	.loc_0x54:
	  addis     r31, r3, 0x2
	  rlwinm    r0,r8,4,0,27
	  add       r4, r31, r0
	  rlwinm    r0,r7,14,0,17
	  lwz       r7, 0x18C4(r4)
	  add       r5, r3, r0
	  lwz       r4, 0x18C8(r4)
	  mulli     r6, r8, 0x2420
	  li        r0, 0x12
	  sub       r4, r4, r7
	  divwu     r30, r4, r0
	  addis     r4, r5, 0x1
	  add       r3, r3, r6
	  addis     r5, r5, 0x1
	  addi      r8, r31, 0
	  add       r3, r3, r7
	  subi      r4, r4, 0x2740
	  addi      r5, r5, 0x58C0
	  addi      r6, r30, 0
	  li        r7, 0x1
	  addi      r8, r8, 0x1A18
	  bl        -0x248
	  lwz       r0, 0x1980(r31)
	  rlwinm    r3,r30,4,1,27
	  add       r0, r0, r3
	  stw       r0, 0x1980(r31)
	  lmw       r30, 0x20(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001CFC0
 * Size:	000024
 */
static s16 Clamp16(s32 a)
{
	if (a >= 0x7fff) {
		a = 0x7fff;
	} else if (a < -0x8000) {
		a = -0x8000;
	}
	return a;
}

/*
 * --INFO--
 * Address:	8001D000
 * Size:	00019C
 */
static void* __DecodeADPCM4X(StreamCtrl_* ctrl)
{
}

/*
 * --INFO--
 * Address:	8001D1A0
 * Size:	000054
 */
static void* __Decode(StreamCtrl_* ctrl)
{
	void* data;
	switch (ctrl->header.audioFormat) {
	case AUDIOFRMT_ADPCM:
		data = __DecodeADPCM(ctrl);
		break;
	case AUDIOFRMT_ADPCM4X:
		data = __DecodeADPCM4X(ctrl);
		break;
	}
	return data;
}

/*
 * --INFO--
 * Address:	8001D200
 * Size:	00013C
 */
static void __PcmToLoop(StreamCtrl_* ctrl)
{
	int count        = ctrl->buffCtrlMain3._04;
	StreamCtrl_* ctr = &ctrl[ctrl->buffCtrlMain3._02 * 0x800];
	s16* data1       = (s16*)&ctr->_1D8C0[0];
	s16* data2       = (s16*)&ctr->_1D8C0[1];

	for (int i = 0; i < count; i) {
		int x             = ctrl->buffCtrlMain2._03;
		StreamCtrl_* ctr2 = &ctrl[x];
		int v1            = ctr2->buffCtrlExtra[0]._08;
		u32* v3           = (u32*)ctr2->buffCtrlExtra[0]._04;
		int v2            = ctrl->buffCtrlMain2._08 + *v3;
		for (u32 j = 0; j < count, v1 < v2; j++) {
			count--;
			StreamCtrl_* ctr3 = &ctrl[x * 0x4000 + j];
			data1[j]          = ctr3->_1D8C0[0][j];
			data2[j]          = ctr3->_1D8C0[1][j];
		}

		if (v1 == v2) {
			ctr2->buffCtrlExtra[0]._00 = 0;
			ctrl->buffCtrlMain2._03    = (x + 1) & 1;
			ctrl->buffCtrlMain2._08    = 0;
		} else {
			ctrl->buffCtrlMain2._08 = v2 - *v3;
		}
	}

	DCStoreRangeNoSync(data1, ctrl->buffCtrlMain3._04 << 1);
	DCStoreRangeNoSync(data2, ctrl->buffCtrlMain3._04 << 1);
	ctrl->_21A40 += ctrl->buffCtrlMain3._04;
	/*
	.loc_0x0:
	  mflr      r0
	  addis     r7, r3, 0x2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  lbz       r0, 0x1962(r7)
	  lwz       r4, 0x1964(r7)
	  rlwinm    r0,r0,11,0,20
	  add       r5, r3, r0
	  addis     r6, r5, 0x2
	  addis     r5, r5, 0x2
	  subi      r6, r6, 0x2740
	  subi      r5, r5, 0x740
	  addi      r11, r6, 0
	  addi      r12, r5, 0
	  addi      r29, r6, 0
	  addi      r31, r5, 0
	  b         .loc_0xEC

	.loc_0x48:
	  lbz       r30, 0x1953(r7)
	  lwz       r6, 0x1958(r7)
	  rlwinm    r5,r30,4,0,27
	  rlwinm    r0,r30,14,0,17
	  add       r9, r3, r5
	  add       r8, r3, r0
	  addis     r10, r9, 0x2
	  lwzu      r0, 0x1924(r10)
	  addis     r5, r9, 0x2
	  lwz       r27, 0x1928(r5)
	  add       r28, r6, r0
	  rlwinm    r5,r28,1,0,30
	  b         .loc_0xA8

	.loc_0x7C:
	  add       r6, r8, r5
	  addi      r28, r28, 0x1
	  addis     r6, r6, 0x1
	  addi      r5, r5, 0x2
	  lha       r0, -0x2740(r6)
	  subi      r4, r4, 0x1
	  sth       r0, 0x0(r11)
	  addi      r11, r11, 0x2
	  lha       r0, 0x58C0(r6)
	  sth       r0, 0x0(r12)
	  addi      r12, r12, 0x2

	.loc_0xA8:
	  cmplw     r28, r27
	  bge-      .loc_0xB8
	  cmpwi     r4, 0
	  bgt+      .loc_0x7C

	.loc_0xB8:
	  cmplw     r28, r27
	  bne-      .loc_0xE0
	  addis     r5, r9, 0x2
	  li        r6, 0
	  addi      r0, r30, 0x1
	  stb       r6, 0x1920(r5)
	  rlwinm    r0,r0,0,31,31
	  stb       r0, 0x1953(r7)
	  stw       r6, 0x1958(r7)
	  b         .loc_0xEC

	.loc_0xE0:
	  lwz       r0, 0x0(r10)
	  sub       r0, r28, r0
	  stw       r0, 0x1958(r7)

	.loc_0xEC:
	  cmpwi     r4, 0
	  bgt+      .loc_0x48
	  addis     r30, r3, 0x2
	  addi      r3, r29, 0
	  lwz       r0, 0x1964(r30)
	  rlwinm    r4,r0,1,0,30
	  bl        0x1D997C
	  lwz       r0, 0x1964(r30)
	  addi      r3, r31, 0
	  rlwinm    r4,r0,1,0,30
	  bl        0x1D996C
	  lwz       r3, 0x1A40(r30)
	  lwz       r0, 0x1964(r30)
	  add       r0, r3, r0
	  stw       r0, 0x1A40(r30)
	  lwz       r0, 0x2C(r1)
	  lmw       r27, 0x14(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001D340
 * Size:	000038
 */
BOOL StreamSyncCheckReady(u32 ctrlID)
{
	StreamCtrl_* ctrl = &SC[ctrlID];

	if (ctrl->_21984 == 2) {
		return TRUE;
	}
	return FALSE;
}

/*
 * --INFO--
 * Address:	8001D380
 * Size:	00005C
 */
BOOL StreamSyncCheckReadyID(u32 ctrlID, u32 r4)
{
	StreamCtrl_* ctrl = &SC[ctrlID];

	if (ctrl->_21A10 == r4) {
		// why
		switch (ctrl->_21984) {
		case 0:
		case 2:
			return TRUE;
		}
	}
	return FALSE;
}

/*
 * --INFO--
 * Address:	8001D3E0
 * Size:	000054
 */
BOOL StreamSyncCheckBusy(u32 ctrlID, u32 unk)
{
	StreamCtrl_* ctrl = &SC[ctrlID];

	if (ctrl->_21984 == 4) {
		return FALSE;
	}
	if (ctrl->_21A10 == unk) {
		if (ctrl->_21984 == 2) {
			return FALSE;
		}
	}
	return TRUE;
}

/*
 * --INFO--
 * Address:	8001D440
 * Size:	000060
 */
int StreamSyncPlayAudio(f32 f1, u32 ctrlID, int volumeL, int volumeR)
{
	StreamCtrl_* ctrl = &SC[ctrlID];

	if (ctrl->_21984 == 2) {
		if (!ctrl->dspch[0]) {
			return FALSE;
		}

		ctrl->_21A30    = f1;
		ctrl->volume[0] = volumeL;
		ctrl->volume[1] = volumeR;
		ctrl->_219A8    = 0;
		return TRUE;
	}

	return FALSE;
}

/*
 * --INFO--
 * Address:	8001D4A0
 * Size:	000050
 */
BOOL StreamSyncStopAudio(u32 ctrlID)
{
	StreamCtrl_* ctrl = &SC[ctrlID];

	// perhaps some state?
	if (ctrl->_21984 == 4) {
		return FALSE;
	} else if (ctrl->_21984 == 3) {
		return FALSE;
	}

	// isStopped?
	ctrl->_219AC = 1;

	return TRUE;
}

/*
 * --INFO--
 * Address:	8001D500
 * Size:	0000A8
 */
static void __StreamChgPitch(StreamCtrl_* ctrl)
{
	if (ctrl->dspch[0]) {

		u16 pitch = ctrl->header._08 * 4096.0f * ctrl->_21A30 / JAC_DAC_RATE;

		for (u32 i = 0; i < 2; i++) {
			DSP_SetPitch(ctrl->dspch[i]->buffer_idx, pitch);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void StreamChgPitch(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001D5C0
 * Size:	000124
 */
static void __StreamChgVolume(StreamCtrl_* ctrl)
{
	if (ctrl->dspch[0]) {
		u32 i;
		u8 mode = Jac_GetOutputMode();

		for (i = 0; i < 2; i++) {
			switch (mode) {
			case 0:
				DSP_SetMixerVolume(ctrl->dspch[i]->buffer_idx, i, ctrl->volume[i] * 0xBFFD / 0x10000, 0);
				DSP_SetMixerVolume(ctrl->dspch[i]->buffer_idx, 1 - i, ctrl->volume[i] * 0xBFFD / 0x10000, 0);
				break;

			default:
				DSP_SetMixerVolume(ctrl->dspch[i]->buffer_idx, i, ctrl->volume[i], 0);
				DSP_SetMixerVolume(ctrl->dspch[i]->buffer_idx, 1 - i, 0, 0);
				break;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8001D700
 * Size:	000034
 */
void StreamChgVolume(u32 ctrlID, int volumeL, int volumeR)
{
	StreamCtrl_* ctrl = &SC[ctrlID];

	ctrl->volume[0] = volumeL;
	ctrl->volume[1] = volumeR;

	ctrl->_21A38 |= 1;
}

/*
 * --INFO--
 * Address:	8001D740
 * Size:	000034
 */
void StreamChgMixLevel(u32 ctrlID, int mixLevelL, int mixLevelR)
{
	StreamCtrl_* ctrl = &SC[ctrlID];
	if (ctrl->dspch[0]) {
		ctrl->mixLevel[0] = mixLevelL;
		ctrl->mixLevel[1] = mixLevelR;
	}
}

/*
 * --INFO--
 * Address:	8001D780
 * Size:	000190
 */
int StreamGetCurrentFrame(u32 id1, u32 id2)
{
	StreamCtrl_* ctrl = &SC[id1];
	dspch_* ch        = ctrl->dspch[0];

	if (ch == NULL) {
		return -1;
	}

	switch (id2) {
	case 0:
		return ctrl->_21980 * ctrl->header._0E / ctrl->header._08;
	case 1:
		return JAC_SUBFRAMES / (f32)JAC_FRAMESAMPLES * ctrl->header._0E / JAC_DAC_RATE * ctrl->_21A08;
	case 2:
		if (ctrl->_21A08 == 0) {
			return 0;
		}
		return (ctrl->_219FC - Get_DirectPCM_Remain(GetDspHandle(ch->buffer_idx))) * (f32)ctrl->header._0E / ctrl->header._08 + 0.499f;
	}

	u32 badcompiler[3];
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x2
	  lis       r5, 0x8037
	  addi      r6, r6, 0x1A50
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0x7160
	  mullw     r5, r3, r6
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  add       r5, r0, r5
	  addis     r31, r5, 0x2
	  lwz       r5, 0x19F4(r31)
	  cmplwi    r5, 0
	  bne-      .loc_0x40
	  li        r3, -0x1
	  b         .loc_0x17C

	.loc_0x40:
	  cmpwi     r4, 0x1
	  beq-      .loc_0x7C
	  bge-      .loc_0x58
	  cmpwi     r4, 0
	  bge-      .loc_0x64
	  b         .loc_0x17C

	.loc_0x58:
	  cmpwi     r4, 0x3
	  bge-      .loc_0x17C
	  b         .loc_0xF8

	.loc_0x64:
	  lwz       r4, 0x1980(r31)
	  lhz       r3, 0x1996(r31)
	  lhz       r0, 0x1990(r31)
	  mullw     r3, r4, r3
	  divwu     r3, r3, r0
	  b         .loc_0x17C

	.loc_0x7C:
	  lwz       r3, -0x7FFC(r13)
	  lis       r4, 0x4330
	  lwz       r0, -0x7FF8(r13)
	  stw       r3, 0x34(r1)
	  lhz       r3, 0x1996(r31)
	  stw       r4, 0x30(r1)
	  lwz       r5, 0x1A08(r31)
	  stw       r0, 0x2C(r1)
	  lfd       f4, -0x7DF0(r2)
	  lfd       f0, 0x30(r1)
	  stw       r4, 0x28(r1)
	  fsubs     f1, f0, f4
	  lfs       f2, -0x8000(r13)
	  lfd       f0, 0x28(r1)
	  stw       r3, 0x3C(r1)
	  fmuls     f1, f2, f1
	  fsubs     f0, f0, f4
	  stw       r4, 0x38(r1)
	  lfd       f2, 0x38(r1)
	  fdivs     f0, f1, f0
	  stw       r5, 0x44(r1)
	  stw       r4, 0x40(r1)
	  lfd       f3, 0x40(r1)
	  fsubs     f1, f2, f4
	  fsubs     f2, f3, f4
	  fdivs     f0, f1, f0
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r3, 0x24(r1)
	  b         .loc_0x17C

	.loc_0xF8:
	  lwz       r0, 0x1A08(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x10C
	  li        r3, 0
	  b         .loc_0x17C

	.loc_0x10C:
	  lbz       r3, 0x0(r5)
	  bl        -0x12330
	  bl        -0x1B74
	  lwz       r0, 0x19FC(r31)
	  lis       r5, 0x4330
	  lhz       r4, 0x1996(r31)
	  sub       r3, r0, r3
	  lhz       r0, 0x1990(r31)
	  stw       r3, 0x24(r1)
	  lfd       f3, -0x7DF0(r2)
	  stw       r4, 0x2C(r1)
	  lfs       f4, -0x7DE8(r2)
	  stw       r5, 0x20(r1)
	  stw       r5, 0x28(r1)
	  lfd       f1, 0x20(r1)
	  stw       r0, 0x34(r1)
	  lfd       f0, 0x28(r1)
	  fsubs     f2, f1, f3
	  stw       r5, 0x30(r1)
	  fsubs     f1, f0, f3
	  lfd       f0, 0x30(r1)
	  fmuls     f1, f2, f1
	  fsubs     f0, f0, f3
	  fdivs     f0, f1, f0
	  fadds     f0, f4, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x38(r1)
	  lwz       r3, 0x3C(r1)

	.loc_0x17C:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001D920
 * Size:	00003C
 */
BOOL StreamSetDVDPause(u32 ctrlID, BOOL isPaused)
{
	StreamCtrl_* ctrl = &SC[ctrlID];

	if (!ctrl->dspch[0]) {
		return FALSE;
	}

	BOOL tmp = ctrl->isPaused;

	ctrl->isPaused = isPaused;

	return tmp;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void StreamCheckRemainBuffers(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001D960
 * Size:	000028
 */
u8 StreamCheckAudioFormat(u32 ctrlID)
{
	StreamCtrl_* ctrl = &SC[ctrlID];
	return ctrl->header.audioFormat;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void StreamCheckBufferEmpty(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void StreamCheckBufferRemainSize(void)
{
	// UNUSED FUNCTION
}
