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
	u16 _00; // _00
	u16 _02; // _02
	u32 _04; // _04
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
	void* _00; // _00
	u32 _04;   // _04
	u32 _08;   // _08
	int _0C;   // _0C
} pic_ctrl[24];

struct DVDControl {
	int _00;   // _00
	u8 mState; // _04
	int _08;   // _08
	int _0C;   // _0C
} dvd_ctrl[3];

static char filename[64] ATTRIBUTE_ALIGN(32);
static u8* dvd_buf[3];
static int gop_subframe         = -1;
static BOOL playback_first_wait = TRUE;
static BOOL hvqm_first          = TRUE;

typedef struct HVQM_FileHeader {
	int _00;             // _00
	int _04;             // _04
	int _08;             // _08
	int _0C;             // _0C
	int _10;             // _10
	u8 _14[4];           // _14
	u32 _18;             // _18
	int _1C;             // _1C
	u8 _20[0x30 - 0x20]; // _20, unknown
	u32 _30;             // _30
	VideoInfo _34;       // _34
	u8 _3C;              // _3C
	u32 _40;             // _40
} HVQM_FileHeader;

static HVQM_FileHeader file_header;
static u32 gop_header[5]; // TODO: struct?
static OSThread jac_hvqmThread;
static u8 hvqmStack[0x1000] ATTRIBUTE_ALIGN(32);

/*
 * --INFO--
 * Address:	8001DC80
 * Size:	000104
 */
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

/*
 * --INFO--
 * Address:	8001DDA0
 * Size:	000074
 */
static void __LoadFin(u32 a)
{
	dvd_active--;

	dvd_ctrl[dvdcount % 3].mState = 2;
	dvd_ctrl[dvdcount % 3]._08    = dvdcount << 0x13;
	dvd_ctrl[dvdcount % 3]._0C    = dvdload_size;

	dvdcount++;
	__ReLoad();
}

/*
 * --INFO--
 * Address:	8001DE20
 * Size:	000198
 */
static int __VirtualLoad(u32 a, u32 b, u8* data)
{
	u32 i = 0;
	for (i = 0; i < 3; i++) {
		if (dvd_ctrl[i].mState == 2) {
			int size = dvd_ctrl[i]._08;
			if (size <= a && size + dvd_ctrl[i]._0C > a) {
				if (size + dvd_ctrl[i]._0C > a + b) {
					Jac_bcopy((void*)(dvd_buf[i] + (a - dvd_ctrl[i]._08)), data, b);
					break;
				}

				if (dvd_ctrl[(i + 1) % 3].mState == 2) {
					int c = (a + b) - (dvd_ctrl[i]._08 + dvd_ctrl[i]._0C);
					int d = b - c;
					Jac_bcopy((void*)(dvd_buf[i] + (a - dvd_ctrl[i]._08)), data, d);
					Jac_bcopy((void*)(dvd_buf[(i + 1) % 3]), data + d, c);
					dvd_ctrl[i].mState = 3;
					break;
				}
				if (dvd_loadfinish) {
					return -1;
				}
			} else if (size + 0x80000 <= a) {
				dvd_ctrl[i].mState = 3;
			}
		}
	}

	if (i == 3) {
		for (int i = 0; i < 3; i++) { }
		return 0;
	}
	return b;
}

/*
 * --INFO--
 * Address:	8001DFC0
 * Size:	000050
 */
static void InitAudio1(StreamHeader_* header, u8* data, u32 size)
{
	Jac_InitStreamData(data, size);
	StreamAudio_Start(0, 0, 0, 1, 0, header);
}

/*
 * --INFO--
 * Address:	8001E020
 * Size:	0003BC
 */
void Jac_HVQM_Init(const char* filepath, u8* data, u32 a)
{
	// TODO: Use this in more places below instead of hardcoding 0x40000
	u32 var_r29         = 0x40000;
	playback_first_wait = TRUE;
	for (u32 i = 0; i < a; i++) {
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

	if (a < 0x40000) {
		return;
	}

	u8* var_r28 = data;

	if (a - 0x40000 < 0x60000) {
		return;
	}

	virtualfile_buf = data + 0x40000;

	u32 min = a - 0xa0000;
	data += 0xa0000;
	for (u32 i = 0; i < 3; i++) {
		if (min < 0x80000) {
			return;
		}
		dvd_buf[i] = data;
		data += 0x80000;
		min -= 0x80000;
	}

	for (u32 i = 0; i < 3; i++) {
		dvd_ctrl[i].mState = 3;
	}
	arcoffset      = 0;
	dvd_loadfinish = 0;
	dvdfile_size   = DVDT_CheckFile(filepath);
	dvdfile_size -= 0x80000;
	volatile u32 status;
	DVDT_LoadtoDRAM(dvdcount, filepath, (u32)dvd_buf[dvdcount % 3], 0, 0x80000, &status, 0);
	while (status == 0) { }

	dvd_ctrl[0]._08    = 0;
	dvd_ctrl[0].mState = 2;
	dvd_ctrl[0]._0C    = 0x80000;
	dvdcount++;
	strcpy(filename, filepath);
	__ReLoad();

	file_header = *(HVQM_FileHeader*)dvd_buf[0];

	arcoffset += 0x44;
	gop_baseframe = 0;
	gop_frame     = 0;
	gop_subframe  = -1;

	STACK_PAD_VAR(2);
	StreamHeader_ header;
	u32 sp3C;
	u32 sp38;
	u32 sp34;
	u32 sp30;
	STACK_PAD_VAR(7);

	(void)&sp3C;
	(void)&sp38;
	(void)&sp34;
	(void)&sp30;

	sp38 = file_header._3C;
	sp3C = file_header._40;
	sp34 = file_header._30;
	switch (sp38) {
	case AUDIOFRMT_ADPCM:
		// 16 samples in 18 bytes
		sp30 = sp34 * 16 / 18;
		break;
	case 2:
		// 2 bytes per sample
		sp30 = sp34 / 2;
		break;
	case 3:
		// 1 byte per sample
		sp30 = sp34;
		break;
	case AUDIOFRMT_ADPCM4X:
		// 16 samples in 36 bytes
		sp30 = sp34 * 16 / 36;
		break;
	}
	file_header._30 = 0;

	header._00 = sp34;
	header._04 = sp30;

	u16 sp3C_2 = (u16)sp3C;
	!sp3C_2;
	header._08 = sp3C_2;

	header.audioFormat = sp38;
	header._0C         = 0x10;
	header._0E         = 0x1e;

	for (int i = 0; i < 4; i++) {
		header._10[i] = 0;
	}
	InitAudio1(&header, var_r28, var_r29);

	hvqm_obj = (SeqObj*)data;
	data += 0x20;
	min -= 0x20;

	HVQM4InitDecoder();
	HVQM4InitSeqObj(hvqm_obj, &file_header._34);

	u32 size = OSRoundUp32B(HVQM4BuffSize(hvqm_obj));
	if (min >= size) {
		void* buffer = data;
		data += size;
		min -= size;
		HVQM4SetBuffer(hvqm_obj, buffer);

		int i;
		for (i = 0; i < 0x18; i++) {
			if (min < 0x70800) {
				break;
			}
			pic_ctrl[i]._00 = data;
			pic_ctrl[i]._0C = 0x12345678;
			data += 0x70800;
			min -= 0x70800;
		}
		PIC_BUFFERS = i;

		InitPic();
		int start = Jac_GetCurrentSCounter();
		while (start == Jac_GetCurrentSCounter()) { }
	}

	return;

	(void)&filepath;
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

/*
 * --INFO--
 * Address:	8001E3E0
 * Size:	000050
 */
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

/*
 * --INFO--
 * Address:	8001E440
 * Size:	000394
 */
BOOL Jac_HVQM_Update(void)
{
	STACK_PAD_VAR(2);
	u8* data = virtualfile_buf;
	if (gop_frame == file_header._18) {
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

		switch (rec_header._00) {
		default:
			return -1;
		case 0:
			if (Jac_CheckStreamFree(rec_header._04) == 0) {
				record_ok = 0;
			} else {
				if (__VirtualLoad(arcoffset, rec_header._04, data) == 0) {
					record_ok = 0;
					return FALSE;
				}
				Jac_SendStreamData(data, rec_header._04);
				record_ok = 1;
				arcoffset += rec_header._04;
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
				if (__VirtualLoad(arcoffset + 4, rec_header._04 - 4, data) == 0) {
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
			arcoffset += rec_header._04;
			int start_time = OSGetTime();
			u32 dec        = Decode1(data, v_header + gop_baseframe, rec_header._02 & 0xff);
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

		if (gop_frame == file_header._18) {
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

/*
 * --INFO--
 * Address:	8001E7E0
 * Size:	000074
 */
void Jac_HVQM_ForceStop(void)
{
	gop_frame = file_header._18;
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

/*
 * --INFO--
 * Address:	8001E860
 * Size:	000228
 */
int Jac_GetPicture(void* data, int* x, int* y)
{
	int offset = 0;
	int index  = -1;
	*x         = file_header._34.width;
	*y         = file_header._34.height;

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
		if (pic_ctrl[i]._08) {
			if (pic_ctrl[i]._04 <= frame) {
				if (offset < pic_ctrl[i]._04) {
					offset = pic_ctrl[i]._04;
					index  = i;
				}
				pic_ctrl[i]._08 = 0;
			} else {
				if (pic_ctrl[i]._08 == 2) {
					pic_ctrl[i]._08 = 0;
				}
			}
		}
	}

	if (index != -1) {
		pic_ctrl[index]._08 = 2;
	}

	for (u32 i = 0; i < PIC_BUFFERS; i++) {
		if (pic_ctrl[i]._08 && frame == pic_ctrl[i]._04) {
			pic_ctrl[i]._08   = 2;
			*(void**)data     = pic_ctrl[i]._00;
			drop_picture_flag = 0;
			if (index != -1 && index != i) {
				pic_ctrl[index]._08 = 0;
			}
			if (frame < 3) {
				*(int*)data = NULL;
			}
			return frame + 1;
		}
	}

	drop_picture_flag = 1;

	if (index != -1) {
		*(void**)data = pic_ctrl[index]._00;
		if (frame < 3) {
			*(int*)data = NULL;
		}
		return offset + 1;
	}

	if (gop_frame == file_header._18) {
		StreamSyncStopAudio(0);
	}
	*(int*)data = NULL;
	return FALSE;
}

/*
 * --INFO--
 * Address:	8001EAA0
 * Size:	000040
 */
static void InitPic()
{
	ref1 = NULL;
	ref2 = NULL;
	for (u32 i = 0; i < PIC_BUFFERS; i++) {
		pic_ctrl[i]._04 = 0;
		pic_ctrl[i]._08 = 0;
	}
}

/*
 * --INFO--
 * Address:	8001EAE0
 * Size:	000044
 */
static BOOL CheckDraw(u32 id)
{
	if (pic_ctrl[(id - pic_ctrl[0]._04) % PIC_BUFFERS]._08) {
		return FALSE;
	}
	return TRUE;
}

/*
 * --INFO--
 * Address:	8001EB40
 * Size:	0000FC
 */
static int Decode1(u8* data, u32 a1, u8 a2)
{
	u32 id    = (a1 - pic_ctrl[0]._04) % PIC_BUFFERS;
	void* ref = pic_ctrl[id]._00;
	if (pic_ctrl[id]._08) {
		return -1;
	}

	switch (a2) {
	case 0x10:
		HVQM4DecodeIpic(hvqm_obj, data, (u8*)ref);
		ref2 = ref1;
		ref1 = ref;
		break;
	case 0x20:
		HVQM4DecodePpic(hvqm_obj, data, (u8*)ref, (u8*)ref1);
		ref2 = ref1;
		ref1 = ref;
		break;
	case 0x30:
		HVQM4DecodeBpic(hvqm_obj, data, (u8*)ref, (u8*)ref2, (u8*)ref1);
		break;
	}

	pic_ctrl[id]._04 = a1;
	pic_ctrl[id]._08 = 1;
	return 0;
}
