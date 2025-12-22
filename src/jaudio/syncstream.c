#include "jaudio/syncstream.h"
#include "Dolphin/dvd.h"
#include "jaudio/aictrl.h"
#include "jaudio/audiostruct.h"
#include "jaudio/dspdriver.h"
#include "jaudio/dspinterface.h"
#include "jaudio/dvdthread.h"
#include "jaudio/interleave.h"
#include "jaudio/playercall.h"
#include "jaudio/rate.h"

// fabricated, size 0x14.
struct UNK_STRUCT {
	DVDFileInfo* fileinfo; // _00
	void* addr;            // _04
	s32 length;            // _08
	s32 offset;            // _0C
	DVDCallback callback;  // _10
};

typedef struct UNK_STRUCT UNK_STRUCT;

static StreamCtrl_ SC[1] ATTRIBUTE_ALIGN(32);
static UNK_STRUCT copyinfo;

static StreamCallback default_streamsync_call;

static UNK_STRUCT* copy = &copyinfo;

static s16 filter_table[16][2] = {
	{ 0, 0 },          { 0x800, 0 },       { 0, 0x800 },       { 0x400, 0x400 },   { 0x1000, 0xF800 }, { 0xE00, 0xFA00 },
	{ 0xC00, 0xFC00 }, { 0x1200, 0xF600 }, { 0x1068, 0xF738 }, { 0x12C0, 0xF704 }, { 0x1400, 0xF400 }, { 0x800, 0xF800 },
	{ 0x400, 0xFC00 }, { 0xFC00, 0x400 },  { 0xFC00, 0 },      { 0xF800, 0 },
};

s16 table4[16] = {
	0, 1, 2, 3, 4, 5, 6, 7, -8, -7, -6, -5, -4, -3, -2, -1,
};

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

	ctrl->isLoadInProgress = 0;

	u32 idx = ctrl->buffCtrlMain.currentBufIdx;

	BufControl_* buff = &ctrl->buffCtrl[idx];

	if (ctrl->isFromFile == 1) {
		u8* data = (u8*)buff->mLength;
		DCInvalidateRange(data, 0x20);

		// what in tarnation
		if (data[0] == 0xff && data[1] == 0xad && data[2] == 0xbe && data[3] == 0xef && data[4] == 0xde && data[5] == 0xad
		    && data[6] == 0xbe && data[7] == 0xef) {
			__DVDReadAsyncRetry();
			return;
		}
	}

	buff->state = 2;

	ctrl->buffCtrlMain.currentBufIdx = (idx + 1) % ctrl->buffCtrlMain.maxBufCount;

	if (ctrl->remainingBytes == 0) {
		ctrl->isBufferingComplete = 1;
		return;
	}

	if (ctrl->isFromFile == 0) {
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
	u32 idx           = ctrl->buffCtrlMain.currentBufIdx;
	BufControl_* buff = &ctrl->buffCtrl[idx];
	u32 oldsize;
	STACK_PAD_VAR(2);

	if (ctrl->isLoadInProgress) {
		return;
	}

	if (buff->state) {
		return;
	}

	oldsize = ctrl->remainingBytes;
	!oldsize;
	if (oldsize == 0) {
		return;
	}

	size = ctrl->chunkSize;

	if (oldsize < size) {
		size = oldsize;
	}

	if (!ctrl->isFromFile) {
		if (!Jac_CheckStreamRemain(size)) {
			return;
		}
	}

	buff->usedSize = 0;
	buff->pos      = size;
	buff->state    = 1;

	if (r28) {
		ctrl->buffCtrlMain.mLength = size;
		ctrl->buffCtrlMain.pos     = 0;
	}

	u32 oldSize = ctrl->bytesRead;

	ctrl->bytesRead += size;
	ctrl->remainingBytes -= size;
	ctrl->lastLoadSize = size;

	switch (ctrl->isFromFile) {
	case 0:
		Jac_GetStreamData((u8*)buff->mLength, size);
		__LoadFin(size, &ctrl->fileinfo);
		break;
	case 1:
		u8* data = (u8*)buff->mLength;
		data[0]  = 0xff;
		data[1]  = 0xad;
		data[2]  = 0xbe;
		data[3]  = 0xef;
		data[4]  = 0xde;
		data[5]  = 0xad;
		data[6]  = 0xbe;
		data[7]  = 0xef;

		DCStoreRange((void*)buff->mLength, size);

		ctrl->isLoadInProgress = 1;

		DVDReadAsyncPrio2(&ctrl->fileinfo, (void*)buff->mLength, size, oldSize, __LoadFin, 1);

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
	ctrl->state         = a;
	ctrl->maxBufCount   = b;
	ctrl->currentBufIdx = c;
	ctrl->activeBufIdx  = d;
	ctrl->usedSize      = e;
	ctrl->pos           = f;
	ctrl->mLength       = g;
}

/*
 * --INFO--
 * Address:	8001C100
 * Size:	000030
 */
void Init_StreamAudio(void)
{
	for (int i = 0; i < ARRAY_SIZE(SC); i++) {
		SC[i].playbackState = 4;
		SC[i].controllerId  = i;
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
BOOL StreamAudio_Start(u32 ctrlID, int soundId, immut char* name, int r6, int r7, StreamHeader_* header)
{
	StreamCtrl_* ctrl = &SC[ctrlID];
	int i;
	STACK_PAD_VAR(2);

	ctrl->controllerId  = ctrlID;
	ctrl->streamId      = soundId;
	ctrl->stopRequested = 0;
	ctrl->isAtEnd       = 0;
	ctrl->isPaused      = FALSE;

	if (name) {
		Jac_DVDOpen(name, &ctrl->fileinfo);
		ctrl->isFromFile = 1;
	} else {
		ctrl->isFromFile = 0;
	}

	if (!header) {
		if (!ctrl->isFromFile) {
			return FALSE;
		}

		DVDReadPrio(&ctrl->fileinfo, &ctrl->data[0].header, 0x20, 0, 1);
		ctrl->header    = ctrl->data[0].header;
		ctrl->bytesRead = 0x20;
	} else {
		ctrl->header    = *header;
		ctrl->bytesRead = 0;
	}

	ctrl->remainingBytes      = ctrl->header.fileSize;
	ctrl->totalSamples        = ctrl->header.sampleCount;
	ctrl->samplesDecoded      = 0;
	ctrl->samplesLoaded       = 0;
	ctrl->isBufferingComplete = 0;
	ctrl->frameCounter        = 0;
	ctrl->playbackState       = 0;

	for (i = 0; i < 6; i++) {
		ctrl->buffCtrl[i].state   = 0;
		ctrl->buffCtrl[i].mLength = (u32)&ctrl->data[i]; // TODO: should be a pointer?
	}

	for (i = 0; i < 2; i++) {
		ctrl->buffCtrlExtra[i].state = 0;
	}

	ctrl->loopSize = 0x1000;

	BufContInit(&ctrl->buffCtrlMain, 1, 6, 0, 0, 0x2400, 0, 0);
	BufContInit(&ctrl->buffCtrlMain2, 2, 2, 0, 0, 0x2000, 0, 0);
	BufContInit(&ctrl->buffCtrlMain3, 2, 4, 0, 3, 0x400, 0, 0);

	switch (ctrl->header.audioFormat) {
	case AUDIOFRMT_16BIT_PCM:
		ctrl->chunkSize = 0x2400;
		break;
	case AUDIOFRMT_8BIT_PCM:
		ctrl->chunkSize = 0x1200;
		break;

	case AUDIOFRMT_ADPCM:
		ctrl->chunkSize = 0x2400;
		break;

	case AUDIOFRMT_ADPCM4X:
		ctrl->chunkSize = 0x2400;
		break;
	}

	ctrl->autoStart        = r6;
	ctrl->isLoadInProgress = 0;
	LoadADPCM(ctrl, 1);

	for (u32 i = 0; i < 2; i++) {
		DeAllocDSPchannel(ctrl->dspch[i], (u32)(&ctrl->dspch[i]));

		ctrl->dspch[i] = 0;
	}

	ctrl->pitchRatio = 1.0f;

	ctrl->volume[0] = 0x3fff;
	ctrl->volume[1] = 0x3fff;

	ctrl->mixLevel[0] = 0x5fff;
	ctrl->mixLevel[1] = 0x5fff;

	ctrl->syncCallback = default_streamsync_call;

	Jac_RegisterDspPlayerCallback(StreamAudio_Callback, ctrl);

	return TRUE;
}

static void __PcmToLoop(StreamCtrl_*);
static void __StreamChgVolume(StreamCtrl_* ctrl);
static void __StreamChgPitch(StreamCtrl_* ctrl);
static u32 __Decode(StreamCtrl_* ctrl);
/*
 * --INFO--
 * Address:	8001C460
 * Size:	0008A8
 */
static s32 StreamAudio_Callback(void* data)
{
	StreamCtrl_* ctrl       = (StreamCtrl_*)data;
	int bufferUpdatePending = 0;
	u32 channelIdx;
	STACK_PAD_VAR(2);

	if (!ctrl->dspch[0]) {
		for (channelIdx = 0; channelIdx < 2; channelIdx++) {
			ctrl->dspch[channelIdx]       = AllocDSPchannel(0, (u32)&ctrl->dspch[channelIdx]);
			ctrl->dspch[channelIdx]->prio = DSPCHAN_MAX_PRIO;
		}
	}

	if (ctrl->frameCounter) {
		DSPchannel_* buff = GetDspHandle(ctrl->dspch[0]->buffer_idx);
		if (buff->done) {
			ctrl->isAtEnd = 1;
		}

		if (ctrl->isAtEnd) {
			if (ctrl->buffCtrl[ctrl->buffCtrlMain.currentBufIdx].state == 1) {
				return 0;
			}

			for (channelIdx = 0; channelIdx < 2; channelIdx++) {
				Stop_DirectPCM(ctrl->dspch[channelIdx]);
				DeAllocDSPchannel(ctrl->dspch[channelIdx], (u32)&ctrl->dspch[channelIdx]);
				ctrl->dspch[channelIdx] = NULL;
			}

			if (ctrl->syncCallback) {
				ctrl->syncCallback(ctrl->controllerId, -1);
			}

			ctrl->playbackState = 4;
			ctrl->streamId      = -1;

			if (ctrl->isFromFile) {
				DVDClose(&ctrl->fileinfo);
			}
			return -1;
		}

		int r4 = ctrl->samplesDecoded * ctrl->header.frameRate / ctrl->header.sampleRate;

		if (ctrl->syncCallback) {
			int callbackResult = ctrl->syncCallback(ctrl->controllerId, r4);
			// TODO: Figure out what this -1 means
			if (callbackResult == -1) {
				ctrl->stopRequested = 1;
			}
		}

		ctrl->frameCounter++;

		u16 var_r3 = ctrl->loopSize - Get_DirectPCM_Counter(buff);
		if (var_r3 == 0) {
			var_r3 = ctrl->loopSize;
		}
		u32 var_r4                       = (ctrl->loopSize - var_r3) >> 10;
		ctrl->buffCtrlMain3.activeBufIdx = var_r4;
		if (ctrl->buffCtrlMain3.currentBufIdx != var_r4) {
			bufferUpdatePending = 1;
		} else {
			bufferUpdatePending = 0;
		}
	}

	if (ctrl->updateFlags) {
		if (ctrl->updateFlags & 1) {
			__StreamChgVolume(ctrl);
		}

		if (ctrl->updateFlags & 2) {
			__StreamChgPitch(ctrl);
		}

		ctrl->updateFlags = 0;

		DSP_FlushChannel(ctrl->dspch[0]->buffer_idx);
		DSP_FlushChannel(ctrl->dspch[1]->buffer_idx);
	}

	if (ctrl->isPaused) {
		DSP_SetPauseFlag(ctrl->dspch[0]->buffer_idx, 1);
		DSP_SetPauseFlag(ctrl->dspch[1]->buffer_idx, 1);

		DSP_FlushChannel(ctrl->dspch[0]->buffer_idx);
		DSP_FlushChannel(ctrl->dspch[1]->buffer_idx);

		ctrl->playbackState = 6;
		return 0;
	}

	if (ctrl->playbackState == 6) {
		if (!ctrl->isPaused) {
			ctrl->playbackState = 1;
			DSP_SetPauseFlag(ctrl->dspch[0]->buffer_idx, 0);
			DSP_SetPauseFlag(ctrl->dspch[1]->buffer_idx, 0);

			DSP_FlushChannel(ctrl->dspch[0]->buffer_idx);
			DSP_FlushChannel(ctrl->dspch[1]->buffer_idx);
		} else {
			return 0;
		}
	}

	if (ctrl->isBufferingComplete == 0 && ctrl->playbackState != 5 && ctrl->frameCounter != 0) {
		DSPchannel_* buff = GetDspHandle(ctrl->dspch[0]->buffer_idx);
		u32 size          = ctrl->totalSamples - Get_DirectPCM_Remain(buff);

		ctrl->bufferMargin = ctrl->samplesLoaded - size;
		if (ctrl->bufferMargin < 0x400) {
			DSP_SetPauseFlag(ctrl->dspch[0]->buffer_idx, 1);
			DSP_SetPauseFlag(ctrl->dspch[1]->buffer_idx, 1);

			DSP_FlushChannel(ctrl->dspch[0]->buffer_idx);
			DSP_FlushChannel(ctrl->dspch[1]->buffer_idx);

			ctrl->playbackState = 5;
		}
	}

	if (ctrl->playbackState == 5) {
		DSPchannel_* buff = GetDspHandle(ctrl->dspch[0]->buffer_idx);
		u32 size          = ctrl->totalSamples - Get_DirectPCM_Remain(buff);

		if (ctrl->samplesLoaded - size > 0xc00 || ctrl->isBufferingComplete == 1) {
			DSP_SetPauseFlag(ctrl->dspch[0]->buffer_idx, 0);
			DSP_SetPauseFlag(ctrl->dspch[1]->buffer_idx, 0);

			DSP_FlushChannel(ctrl->dspch[0]->buffer_idx);
			DSP_FlushChannel(ctrl->dspch[1]->buffer_idx);

			ctrl->playbackState = 1;
		} else {
			DSP_SetPauseFlag(ctrl->dspch[0]->buffer_idx, 1);
			DSP_SetPauseFlag(ctrl->dspch[1]->buffer_idx, 1);

			DSP_FlushChannel(ctrl->dspch[0]->buffer_idx);
			DSP_FlushChannel(ctrl->dspch[1]->buffer_idx);
		}
	}

	if (ctrl->buffCtrl[ctrl->buffCtrlMain.activeBufIdx].state == 2 && ctrl->buffCtrlExtra[ctrl->buffCtrlMain2.currentBufIdx].state == 0) {
		u32 size = __Decode(ctrl);

		ctrl->buffCtrl[ctrl->buffCtrlMain.activeBufIdx].state = 0;

		ctrl->buffCtrlExtra[ctrl->buffCtrlMain2.currentBufIdx].state    = 2;
		ctrl->buffCtrlExtra[ctrl->buffCtrlMain2.currentBufIdx].usedSize = 0;
		ctrl->buffCtrlExtra[ctrl->buffCtrlMain2.currentBufIdx].pos      = size;

		ctrl->buffCtrlMain.activeBufIdx = (ctrl->buffCtrlMain.activeBufIdx + 1) % 6;

		ctrl->buffCtrlMain2.currentBufIdx = (ctrl->buffCtrlMain2.currentBufIdx + 1) % 2;
		ctrl->buffCtrlMain2.mLength += size;
	}

	if (bufferUpdatePending == 1 || ctrl->frameCounter == 0) {
		if (ctrl->buffCtrlMain3.currentBufIdx != ctrl->buffCtrlMain3.activeBufIdx) {
			if (ctrl->buffCtrlExtra[ctrl->buffCtrlMain2.activeBufIdx].state == 2
			    && ctrl->buffCtrlMain2.mLength >= ctrl->buffCtrlMain3.usedSize) {
				__PcmToLoop(ctrl);
				ctrl->buffCtrlMain3.currentBufIdx = (ctrl->buffCtrlMain3.currentBufIdx + 1) % 4;
				ctrl->buffCtrlMain2.mLength -= ctrl->buffCtrlMain3.usedSize;
			}
		} else if (ctrl->frameCounter == 0) {
			if (ctrl->autoStart == 1) {
				if (ctrl->syncCallback != NULL) {
					int callbackResult = ctrl->syncCallback(ctrl->controllerId, 0);
					if (callbackResult == -1) {
						ctrl->stopRequested = 1;
					}
					if (callbackResult == 1) {
						ctrl->autoStart = 0;
					}
				}
				ctrl->playbackState = 2;
				if (ctrl->stopRequested == 0) {
					return 0;
				}
			} else {
				ctrl->playbackState = 1;
				ctrl->frameCounter++;
				u32 mode = Jac_GetOutputMode();
				for (channelIdx = 0; channelIdx < 2; channelIdx++) {
					u16 pitch = (4096.0f * ctrl->header.sampleRate * ctrl->pitchRatio) / JAC_DAC_RATE;
					Play_DirectPCM(ctrl->dspch[channelIdx], ctrl->loopBufs[channelIdx], ctrl->loopSize, ctrl->totalSamples);
					switch (mode) {
					case 0:
						DSP_SetMixerInitVolume(ctrl->dspch[channelIdx]->buffer_idx, channelIdx, ctrl->volume[channelIdx] * 0xBFFD / 0x10000,
						                       0);
						DSP_SetMixerInitVolume(ctrl->dspch[channelIdx]->buffer_idx, 1 - channelIdx,
						                       ctrl->volume[channelIdx] * 0xBFFD / 0x10000, 0);
						break;

					default:
						DSP_SetMixerInitVolume(ctrl->dspch[channelIdx]->buffer_idx, channelIdx, ctrl->volume[channelIdx], 0);
						DSP_SetMixerInitVolume(ctrl->dspch[channelIdx]->buffer_idx, 1 - channelIdx, 0, 0);
						break;
					}
					DSP_SetPitch(ctrl->dspch[channelIdx]->buffer_idx, pitch);
					DSP_FlushChannel(ctrl->dspch[channelIdx]->buffer_idx);
				}
			}
		}
	}

	if (ctrl->playbackState == 3) {
		return 0;
	}

	if (ctrl->stopRequested != 0) {
		if (ctrl->frameCounter == 0) {
			if (ctrl->buffCtrl[ctrl->buffCtrlMain.currentBufIdx].state == 1) {
				return 0;
			}
			ctrl->stopRequested = 0;
			if (ctrl->syncCallback != NULL) {
				ctrl->syncCallback(ctrl->controllerId, -1);
			}
			ctrl->playbackState = 4;
			ctrl->streamId      = -1;
			return -1;
		}
		ctrl->stopRequested = 0;
		ctrl->playbackState = 3;
		for (channelIdx = 0; channelIdx < 2; channelIdx++) {
			ForceStopDSPchannel(ctrl->dspch[channelIdx]);
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
void Jac_Decode_ADPCM(u8* src, s16* dst1, s16* dst2, u32 count, u8 arg4, s16* state)
{
	s16 sa = state[0];
	s16 sb = state[1];
	s16 sc = state[2];
	s16 sd = state[3];
	int output;
	s16 coef1, coef2;
	u8 header;
	u8 scale_factor;
	int i, j;
	u8 byte, samp1, samp2;
	for (i = 0; i < count; i++) {
		header       = *src++;
		scale_factor = (header >> 4) & 0xF;
		coef1        = filter_table[header & 0xF][0];
		coef2        = filter_table[header & 0xF][1];
		for (j = 0; j < 8; j++) {
			byte  = *src++;
			samp1 = byte >> 4;
			samp2 = byte & 0xF;

			output  = (table4[samp1] << scale_factor) + ((coef1 * sa + coef2 * sb) >> 11);
			*dst1++ = output;
			sb      = output;

			output  = (table4[samp2] << scale_factor) + ((coef1 * sb + coef2 * sa) >> 11);
			*dst1++ = output;
			sa      = output;
		}
		if (arg4) {
			header       = *src++;
			scale_factor = (header >> 4) & 0xF;
			coef1        = filter_table[header & 0xF][0];
			coef2        = filter_table[header & 0xF][1];
			for (j = 0; j < 8; j++) {
				byte  = *src++;
				samp1 = byte >> 4;
				samp2 = byte & 0xF;

				output  = (table4[samp1] << scale_factor) + ((coef1 * sc + coef2 * sd) >> 11);
				*dst2++ = output;
				sd      = output;

				output  = (table4[samp2] << scale_factor) + ((coef1 * sd + coef2 * sc) >> 11);
				*dst2++ = output;
				sc      = output;
			}
		}
	}
	state[0] = sa;
	state[1] = sb;
	state[2] = sc;
	state[3] = sd;
}

/*
 * --INFO--
 * Address:	8001CEE0
 * Size:	0000D0
 */
static u32 __DecodeADPCM(StreamCtrl_* ctrl)
{
	STACK_PAD_VAR(4);
	u32 a = ctrl->buffCtrlMain2.currentBufIdx;
	u32 b = ctrl->buffCtrlMain.activeBufIdx;

	if (ctrl->frameCounter == 0 && b == 0) {
		for (int i = 0; i < 4; i++) {
			ctrl->leftAdpcmState[i] = 0;
		}
	}

	s16* dst1 = ctrl->leftChanBufs[a];
	s16* dst2 = ctrl->rightChanBufs[a];

	u8* src = ctrl->data[b].data;
	src += ctrl->buffCtrl[b].usedSize;

	u32 count = (ctrl->buffCtrl[b].pos - ctrl->buffCtrl[b].usedSize) / 18;

	Jac_Decode_ADPCM(src, dst1, dst2, count, 1, ctrl->leftAdpcmState);

	u32 size = (count * 16) & 0x7FFFFFFF;
	ctrl->samplesDecoded += size;
	return size;
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

static u32 __DecodeADPCM4X(StreamCtrl_* ctrl)
{
	STACK_PAD_VAR(6);
	u32 a = ctrl->buffCtrlMain2.currentBufIdx;
	u32 b = ctrl->buffCtrlMain.activeBufIdx;
	u32 count;
	u32 i;
	u32 outpos = 0;

	if (ctrl->frameCounter == 0 && b == 0) {
		for (u32 i = 0; i < 4; i++) {
			ctrl->leftAdpcmState[i] = 0;
		}
		// Not clearing ctrl->_21A20 too?
	}

	s16* dst1 = ctrl->leftChanBufs[a];
	s16* dst2 = ctrl->rightChanBufs[a];

	u8* src = ctrl->data[b].data;
	src += ctrl->buffCtrl[b].usedSize;

	u32 j;

	u16 mixLevel0 = ctrl->mixLevel[0];
	u16 mixLevel1 = ctrl->mixLevel[1];

	count = (ctrl->buffCtrl[b].pos - ctrl->buffCtrl[b].usedSize) / 36;

	s16 sp6C[16];
	s16 sp4C[16];
	s16 sp2C[16];
	s16 sp0C[16];

	for (i = 0; i < count; i++) {
		Jac_Decode_ADPCM(src, sp6C, sp4C, 1, 1, ctrl->leftAdpcmState);
		src += 18;
		Jac_Decode_ADPCM(src, sp2C, sp0C, 1, 1, ctrl->rightAdpcmState);
		src += 18;
		for (j = 0; j < 16; j++) {
			dst1[outpos] = Clamp16((sp6C[j] * mixLevel0 >> 15) + (sp2C[j] * mixLevel1 >> 15));
			dst2[outpos] = Clamp16((sp4C[j] * mixLevel0 >> 15) + (sp0C[j] * mixLevel1 >> 15));
			outpos++;
		}
	}

	u32 size = (count << 4) & 0x7FFFFFFF;
	ctrl->samplesDecoded += size;
	return size;
}

/*
 * --INFO--
 * Address:	8001D1A0
 * Size:	000054
 */
static u32 __Decode(StreamCtrl_* ctrl)
{
	u32 size;
	switch (ctrl->header.audioFormat) {
	case AUDIOFRMT_ADPCM:
		size = __DecodeADPCM(ctrl);
		break;
	case AUDIOFRMT_ADPCM4X:
		size = __DecodeADPCM4X(ctrl);
		break;
	}
	return size;
}

/*
 * --INFO--
 * Address:	8001D200
 * Size:	00013C
 */
static void __PcmToLoop(StreamCtrl_* ctrl)
{
	int count  = ctrl->buffCtrlMain3.usedSize;
	s16* dst1  = &ctrl->loopBufs[0][ctrl->buffCtrlMain3.currentBufIdx * 0x400];
	s16* dst2  = &ctrl->loopBufs[1][ctrl->buffCtrlMain3.currentBufIdx * 0x400];
	s16* data1 = dst1;
	s16* data2 = dst2;

	while (count > 0) {
		int x   = ctrl->buffCtrlMain2.activeBufIdx;
		u32 pos = ctrl->buffCtrlMain2.pos + ctrl->buffCtrlExtra[x].usedSize;
		u32 end = ctrl->buffCtrlExtra[x].pos;
		while (pos < end && count > 0) {
			*dst1++ = ctrl->leftChanBufs[x][pos];
			*dst2++ = ctrl->rightChanBufs[x][pos];
			pos++;
			count--;
		}

		if (pos == end) {
			ctrl->buffCtrlExtra[x].state     = 0;
			ctrl->buffCtrlMain2.activeBufIdx = (x + 1) & 1;
			ctrl->buffCtrlMain2.pos          = 0;
		} else {
			ctrl->buffCtrlMain2.pos = pos - ctrl->buffCtrlExtra[x].usedSize;
		}
	}

	DCStoreRangeNoSync(data1, ctrl->buffCtrlMain3.usedSize << 1);
	DCStoreRangeNoSync(data2, ctrl->buffCtrlMain3.usedSize << 1);
	ctrl->samplesLoaded += ctrl->buffCtrlMain3.usedSize;
}

/*
 * --INFO--
 * Address:	8001D340
 * Size:	000038
 */
BOOL StreamSyncCheckReady(u32 ctrlID)
{
	StreamCtrl_* ctrl = &SC[ctrlID];

	if (ctrl->playbackState == 2) {
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

	if (ctrl->streamId == r4) {
		// why
		switch (ctrl->playbackState) {
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

	if (ctrl->playbackState == 4) {
		return FALSE;
	}
	if (ctrl->streamId == unk) {
		if (ctrl->playbackState == 2) {
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

	if (ctrl->playbackState == 2) {
		if (!ctrl->dspch[0]) {
			return FALSE;
		}

		ctrl->pitchRatio = f1;
		ctrl->volume[0]  = volumeL;
		ctrl->volume[1]  = volumeR;
		ctrl->autoStart  = 0;
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
	if (ctrl->playbackState == 4) {
		return FALSE;
	} else if (ctrl->playbackState == 3) {
		return FALSE;
	}

	// isStopped?
	ctrl->stopRequested = 1;

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

		u16 pitch = ctrl->header.sampleRate * 4096.0f * ctrl->pitchRatio / JAC_DAC_RATE;

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

	ctrl->updateFlags |= 1;
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
int StreamGetCurrentFrame(u32 streamId, u32 id2)
{
	StreamCtrl_* ctrl = &SC[streamId];
	dspch_* dspCh     = ctrl->dspch[0];

	if (dspCh == NULL) {
		return -1;
	}

	switch (id2) {
	case 0:
		return ctrl->samplesDecoded * ctrl->header.frameRate / ctrl->header.sampleRate;
	case 1:
		f32 subframeRate = JAC_DAC_RATE * JAC_SUBFRAMES / JAC_FRAMESAMPLES;
		return ctrl->header.frameRate / subframeRate * ctrl->frameCounter;
	case 2:
		if (ctrl->frameCounter == 0) {
			return 0;
		}
		u32 size = ctrl->totalSamples - Get_DirectPCM_Remain(GetDspHandle(dspCh->buffer_idx));
		return size * (f32)ctrl->header.frameRate / ctrl->header.sampleRate + 0.499f;
	}

	STACK_PAD_VAR(3);
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
