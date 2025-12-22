#include "jaudio/hvqm_play.h"
#include "Dolphin/os.h"
#include "hvqm4.h"
#include "jaudio/dspbuf.h"
#include "jaudio/dvdthread.h"
#include "jaudio/interleave.h"
#include "jaudio/sample.h"
#include "jaudio/syncstream.h"
#include "stl/string.h"

static volatile BOOL dvd_loadfinish;
static u32 dvdcount;
static int arcoffset;
static int AUDIO_FRAME;
static u32 PIC_FRAME;
static int drop_picture_flag;
static u32 PIC_BUFFERS;
static int dvdload_size;
static u32 dvdfile_size;

static struct RecHeader {
	u16 mRecordType; // _00, 0=audio, 1=video
	u16 mFrameFlags; // _02
	u32 mDataSize;   // _04
} rec_header;

static int v_header;
static int gop_baseframe;
static u32 gop_frame;
static int vh_state;
static SeqObj* hvqm_obj;
static u32 dvd_active;
static u8* virtualfile_buf;
static BOOL record_ok;
static void* ref1;
static void* ref2;

static void InitPic();
static BOOL CheckDraw(u32 id);
static int Decode1(u8* data, u32 a1, u8 a2);

struct PICControl {
	void* mPicBuffer; // _00, pointer to the picture data
	u32 mFrameNumber; // _04, frame this picture belongs to
	u32 mBufferState; // _08, 0=free, 1=ready, 2=displayed
	int mMagicNumber; // _0C
} pic_ctrl[24];

struct DVDControl {
	int _00;         // _00
	u8 mState;       // _04
	int mFileOffset; // _08
	int mLoadedSize; // _0C
} dvd_ctrl[3];

static char filename[64] ATTRIBUTE_ALIGN(32);
static u8* dvd_buf[3];
static int gop_subframe         = -1;
static BOOL playback_first_wait = TRUE;
static BOOL hvqm_first          = TRUE;

typedef struct HVQM_FileHeader {
	int _00;             // _00, unused
	int _04;             // _04, unused
	int _08;             // _08, unused
	int _0C;             // _0C, unused
	int _10;             // _10, unused
	u8 _14[4];           // _14, unused
	u32 mTotalFrames;    // _18
	int _1C;             // _1C, unused
	u8 _20[0x30 - 0x20]; // _20, unused
	u32 mFileSize;       // _30
	VideoInfo mInfo;     // _34
	u8 mAudioFormat;     // _3C
	u32 mSampleRate;     // _40
} HVQM_FileHeader;

static HVQM_FileHeader file_header;
static u32 gop_header[5]; // TODO: struct?
static OSThread jac_hvqmThread;
static u8 hvqmStack[0x1000] ATTRIBUTE_ALIGN(32);

static void __ReLoad()
{
	int size = dvdfile_size;
	if (dvdfile_size == 0) {
		dvd_loadfinish = 1;
		return;
	}

	if (dvd_ctrl[(dvdcount % 3)].mState == 3) {
		dvd_ctrl[(dvdcount % 3)].mState = 1;
		if (dvdfile_size < 0x80000) {
			dvdload_size = size;
		} else {
			dvdload_size = 0x80000;
		}
		dvdfile_size -= dvdload_size;
		int inter = OSDisableInterrupts();
		dvd_active += 1;

		int num_bufs = 3;
		DVDT_LoadtoDRAM(dvdcount, filename, (u32)dvd_buf[dvdcount % num_bufs], dvdcount << 0x13, dvdload_size, NULL, __LoadFin);
		OSRestoreInterrupts(inter);
	}
}

static void __LoadFin(u32 a)
{
	dvd_active--;

	dvd_ctrl[dvdcount % 3].mState      = 2;
	dvd_ctrl[dvdcount % 3].mFileOffset = dvdcount << 0x13;
	dvd_ctrl[dvdcount % 3].mLoadedSize = dvdload_size;

	dvdcount++;
	__ReLoad();
}

static int __VirtualLoad(u32 currentOffs, u32 bytesToRead, u8* data)
{
	u32 bufIdx = 0;
	for (bufIdx = 0; bufIdx < 3; bufIdx++) {
		if (dvd_ctrl[bufIdx].mState == 2) {

			int fileOffs = dvd_ctrl[bufIdx].mFileOffset;
			if (fileOffs <= currentOffs && fileOffs + dvd_ctrl[bufIdx].mLoadedSize > currentOffs) {
				if (fileOffs + dvd_ctrl[bufIdx].mLoadedSize > currentOffs + bytesToRead) {
					Jac_bcopy((void*)(dvd_buf[bufIdx] + (currentOffs - dvd_ctrl[bufIdx].mFileOffset)), data, bytesToRead);
					break;
				}

				if (dvd_ctrl[(bufIdx + 1) % 3].mState == 2) {
					int fromNextBuffer    = (currentOffs + bytesToRead) - (dvd_ctrl[bufIdx].mFileOffset + dvd_ctrl[bufIdx].mLoadedSize);
					int fromCurrentBuffer = bytesToRead - fromNextBuffer;
					Jac_bcopy((void*)(dvd_buf[bufIdx] + (currentOffs - dvd_ctrl[bufIdx].mFileOffset)), data, fromCurrentBuffer);
					Jac_bcopy((void*)(dvd_buf[(bufIdx + 1) % 3]), data + fromCurrentBuffer, fromNextBuffer);
					dvd_ctrl[bufIdx].mState = 3;
					break;
				}

				if (dvd_loadfinish) {
					return -1;
				}

			} else if (fileOffs + 0x80000 <= currentOffs) {
				dvd_ctrl[bufIdx].mState = 3;
			}
		}
	}

	if (bufIdx == 3) {
		for (int i = 0; i < 3; i++) { }
		return 0;
	}

	return bytesToRead;
}

static void InitAudio1(StreamHeader_* header, u8* data, u32 size)
{
	Jac_InitStreamData(data, size);
	StreamAudio_Start(0, 0, 0, 1, 0, header);
}

void Jac_HVQM_Init(immut char* movieFilePath, u8* data, u32 bufferSize)
{
	// TODO: Use this in more places below instead of hardcoding 0x40000
	u32 audioBufferSize = 0x40000;
	playback_first_wait = TRUE;
	for (u32 i = 0; i < bufferSize; i++) {
		(void)&i;
		data[i] = 0;
	}
	STACK_PAD_VAR(1);

	dvdcount          = 0;
	dvd_active        = 0;
	vh_state          = 0;
	drop_picture_flag = 1;
	record_ok         = TRUE;
	PIC_FRAME         = 0;
	AUDIO_FRAME       = 0;

	if (bufferSize < 0x40000) {
		return;
	}

	u8* audioBuffer = data;
	if (bufferSize - 0x40000 < 0x60000) {
		return;
	}

	virtualfile_buf = data + 0x40000;

	u32 remainingMem = bufferSize - 0xa0000;
	data += 0xa0000;
	for (u32 dvdIndex = 0; dvdIndex < 3; dvdIndex++) {
		if (remainingMem < 0x80000) {
			return;
		}

		dvd_buf[dvdIndex] = data;
		data += 0x80000;
		remainingMem -= 0x80000;
	}

	for (u32 i = 0; i < 3; i++) {
		dvd_ctrl[i].mState = 3;
	}

	arcoffset      = 0;
	dvd_loadfinish = 0;
	dvdfile_size   = DVDT_CheckFile(movieFilePath);
	dvdfile_size -= 0x80000;
	volatile u32 status;
	DVDT_LoadtoDRAM(dvdcount, movieFilePath, (u32)dvd_buf[dvdcount % 3], 0, 0x80000, (u32*)&status, 0);
	while (status == 0) { }

	dvd_ctrl[0].mFileOffset = 0;
	dvd_ctrl[0].mState      = 2;
	dvd_ctrl[0].mLoadedSize = 0x80000;
	dvdcount++;
	strcpy(filename, movieFilePath);
	__ReLoad();

	file_header = *(HVQM_FileHeader*)dvd_buf[0];

	arcoffset += 0x44;
	gop_baseframe = 0;
	gop_frame     = 0;
	gop_subframe  = -1;

	STACK_PAD_VAR(2);
	StreamHeader_ header;
	u32 sampleRate;
	u32 audioFormat;
	u32 fileSize;
	u32 sampleCount;
	STACK_PAD_VAR(7);

	(void)&sampleRate;
	(void)&audioFormat;
	(void)&fileSize;
	(void)&sampleCount;

	audioFormat = file_header.mAudioFormat;
	sampleRate  = file_header.mSampleRate;
	fileSize    = file_header.mFileSize;
	switch (audioFormat) {
	case AUDIOFRMT_ADPCM:
		// 16 samples in 18 bytes
		sampleCount = fileSize * 16 / 18;
		break;
	case AUDIOFRMT_16BIT_PCM:
		// 2 bytes per sample
		sampleCount = fileSize / 2;
		break;
	case AUDIOFRMT_8BIT_PCM:
		// 1 byte per sample
		sampleCount = fileSize;
		break;
	case AUDIOFRMT_ADPCM4X:
		// 16 samples in 36 bytes
		sampleCount = fileSize * 16 / 36;
		break;
	}
	file_header.mFileSize = 0;

	header.fileSize    = fileSize;
	header.sampleCount = sampleCount;

	u16 sampleRate_2 = (u16)sampleRate;
	!sampleRate_2;
	header.sampleRate = sampleRate_2;

	header.audioFormat = audioFormat;
	header._0C         = 0x10;
	header.frameRate   = 30; // 30 FPS

	for (int i = 0; i < 4; i++) {
		header._10[i] = 0;
	}
	InitAudio1(&header, audioBuffer, audioBufferSize);

	hvqm_obj = (SeqObj*)data;
	data += 0x20;
	remainingMem -= 0x20;

	HVQM4InitDecoder();
	HVQM4InitSeqObj(hvqm_obj, &file_header.mInfo);

	u32 size = OSRoundUp32B(HVQM4BuffSize(hvqm_obj));
	if (remainingMem >= size) {
		void* buffer = data;
		data += size;
		remainingMem -= size;
		HVQM4SetBuffer(hvqm_obj, buffer);

		int i;
		for (i = 0; i < 0x18; i++) {
			if (remainingMem < 0x70800) {
				break;
			}
			pic_ctrl[i].mPicBuffer   = data;
			pic_ctrl[i].mMagicNumber = 0x12345678;
			data += 0x70800;
			remainingMem -= 0x70800;
		}
		PIC_BUFFERS = i;

		InitPic();
		int start = Jac_GetCurrentSCounter();
		while (start == Jac_GetCurrentSCounter()) { }
	}

	return;

	(void)&movieFilePath;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void hvqm_proc(void* data)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void OSInitFastCast(void)
{
	// UNUSED FUNCTION
}

static void hvqm_forcestop()
{
	if (hvqm_first == 0 && OSIsThreadTerminated(&jac_hvqmThread) == FALSE) {
		OSCancelThread(&jac_hvqmThread);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void Jac_HVQM_ThreadStart(void)
{
	// UNUSED FUNCTION
}

BOOL Jac_HVQM_Update(void)
{
	STACK_PAD_VAR(2);
	u8* data = virtualfile_buf;
	if (gop_frame == file_header.mTotalFrames) {
		return TRUE;
	}

	u32 i = 0;
	int time_delta;
	while (TRUE) {
		if (gop_subframe == -1) {
			if (__VirtualLoad(arcoffset, sizeof(gop_header), (u8*)gop_header) == 0) {
				return FALSE;
			}
			arcoffset += 0x14;
			gop_subframe++;
		}

		if (record_ok != 0) {
			if (__VirtualLoad(arcoffset, sizeof(rec_header), (u8*)&rec_header) == 0) {
				return 0;
			}
			arcoffset += 8;
		}

		switch (rec_header.mRecordType) {
		default:
			return -1;
		case 0:
			if (Jac_CheckStreamFree(rec_header.mDataSize) == 0) {
				record_ok = 0;
			} else {
				if (__VirtualLoad(arcoffset, rec_header.mDataSize, data) == 0) {
					record_ok = 0;
					return FALSE;
				}
				Jac_SendStreamData(data, rec_header.mDataSize);
				record_ok = 1;
				arcoffset += rec_header.mDataSize;
			}
			break;
		case 1:
			if (playback_first_wait && PIC_FRAME == PIC_BUFFERS) {
				if (StreamSyncCheckReady(0)) {
					StreamSyncPlayAudio(1.0f, 0, 0x3fff, 0x3fff);
					playback_first_wait = 0;
				} else {
					record_ok = 0;
					return FALSE;
				}
			}

			switch (vh_state) {
			case 0:
				if (__VirtualLoad(arcoffset, 4, (u8*)&v_header) == 0) {
					record_ok = 0;
					goto end;
				}
				vh_state += 1;
				// fallthrough
			case 1:
				if (__VirtualLoad(arcoffset + 4, rec_header.mDataSize - 4, data) == 0) {
					record_ok = 0;
					goto end;
				}
				vh_state += 1;
				// fallthrough
			case 2:
				if (CheckDraw(v_header + gop_baseframe) == 0) {
					record_ok = 0;
					goto end;
				}
				vh_state = 0;
				break;
			}

			record_ok = 1;
			arcoffset += rec_header.mDataSize;
			int start_time = OSGetTime();
			u32 dec        = Decode1(data, v_header + gop_baseframe, rec_header.mFrameFlags & 0xff);
			time_delta     = OSGetTime() - start_time;
			if (dec <= 1) {
				PIC_FRAME++;
				gop_subframe++;
				if (gop_subframe == gop_header[2]) {
					gop_baseframe += gop_subframe;
					gop_subframe = -1;
					gop_frame++;
				}
			}
			break;
		}

		if (gop_frame == file_header.mTotalFrames) {
			return TRUE;
		}

		for (int k = 0; k < 3; k++) {
			if (dvd_ctrl[k].mState == 3) {
				__ReLoad();
				break;
			}
		}

		if (i == 0 && time_delta >= 500000 && drop_picture_flag == 0) {
			break;
		}

		i++;
		if (i >= 2) {
			break;
		}
	}
end:
	return FALSE;
}

void Jac_HVQM_ForceStop(void)
{
	gop_frame = file_header.mTotalFrames;
	StreamSyncStopAudio(0);
	BOOL inter   = OSDisableInterrupts();
	dvdfile_size = 0;
	if (dvd_loadfinish != 1 && dvd_active != 0) {
		OSRestoreInterrupts(inter);
		while (dvd_loadfinish != 1) { }

	} else {
		OSRestoreInterrupts(inter);
	}
	hvqm_forcestop();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void Jac_CountReadyPictures(void)
{
	// UNUSED FUNCTION
}

int Jac_GetPicture(void* data, int* x, int* y)
{
	int offset = 0;
	int index  = -1;
	*x         = file_header.mInfo.width;
	*y         = file_header.mInfo.height;

	if (playback_first_wait) {
		*(int*)data = 0;
		return TRUE;
	}

	int frame = StreamGetCurrentFrame(0, 2);
	if (frame == -1) {
		hvqm_forcestop();
		*(int*)data = 0;
		return -1;
	}

	AUDIO_FRAME = frame;

	for (u32 i = 0; i < PIC_BUFFERS; i++) {
		if (pic_ctrl[i].mBufferState) {
			if (pic_ctrl[i].mFrameNumber <= frame) {
				if (offset < pic_ctrl[i].mFrameNumber) {
					offset = pic_ctrl[i].mFrameNumber;
					index  = i;
				}
				pic_ctrl[i].mBufferState = 0;
			} else {
				if (pic_ctrl[i].mBufferState == 2) {
					pic_ctrl[i].mBufferState = 0;
				}
			}
		}
	}

	if (index != -1) {
		pic_ctrl[index].mBufferState = 2;
	}

	for (u32 i = 0; i < PIC_BUFFERS; i++) {
		if (pic_ctrl[i].mBufferState && frame == pic_ctrl[i].mFrameNumber) {
			pic_ctrl[i].mBufferState = 2;
			*(void**)data            = pic_ctrl[i].mPicBuffer;
			drop_picture_flag        = 0;
			if (index != -1 && index != i) {
				pic_ctrl[index].mBufferState = 0;
			}
			if (frame < 3) {
				*(int*)data = NULL;
			}
			return frame + 1;
		}
	}

	drop_picture_flag = 1;

	if (index != -1) {
		*(void**)data = pic_ctrl[index].mPicBuffer;
		if (frame < 3) {
			*(int*)data = NULL;
		}
		return offset + 1;
	}

	if (gop_frame == file_header.mTotalFrames) {
		StreamSyncStopAudio(0);
	}
	*(int*)data = NULL;
	return FALSE;
}

static void InitPic()
{
	ref1 = NULL;
	ref2 = NULL;
	for (u32 i = 0; i < PIC_BUFFERS; i++) {
		pic_ctrl[i].mFrameNumber = 0;
		pic_ctrl[i].mBufferState = 0;
	}
}

static BOOL CheckDraw(u32 id)
{
	if (pic_ctrl[(id - pic_ctrl[0].mFrameNumber) % PIC_BUFFERS].mBufferState) {
		return FALSE;
	}
	return TRUE;
}

static int Decode1(u8* data, u32 frameId, u8 frameType)
{
	u32 id    = (frameId - pic_ctrl[0].mFrameNumber) % PIC_BUFFERS;
	void* ref = pic_ctrl[id].mPicBuffer;
	if (pic_ctrl[id].mBufferState) {
		return -1;
	}

	switch (frameType) {
	case 0x10: // IPIC chunk
		HVQM4DecodeIpic(hvqm_obj, data, (u8*)ref);
		ref2 = ref1;
		ref1 = ref;
		break;
	case 0x20: // PPIC chunk
		HVQM4DecodePpic(hvqm_obj, data, (u8*)ref, (u8*)ref1);
		ref2 = ref1;
		ref1 = ref;
		break;
	case 0x30: // BPIC chunk
		HVQM4DecodeBpic(hvqm_obj, data, (u8*)ref, (u8*)ref2, (u8*)ref1);
		break;
	}

	pic_ctrl[id].mFrameNumber = frameId;
	pic_ctrl[id].mBufferState = 1;
	return 0;
}
