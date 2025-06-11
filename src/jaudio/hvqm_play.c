#include "jaudio/hvqm_play.h"
#include "Dolphin/os.h"
#include "jaudio/sample.h"
#include "jaudio/interleave.h"
#include "jaudio/syncstream.h"
#include "jaudio/dvdthread.h"
#include "jaudio/dspbuf.h"
#include "stl/string.h"
#include "hvqm4.h"

volatile BOOL dvd_loadfinish;
u32 dvdcount;
int arcoffset;
int AUDIO_FRAME;
u32 PIC_FRAME;
int drop_picture_flag;
u32 PIC_BUFFERS;
int dvdload_size;
u32 dvdfile_size;
static struct RecHeader {
	u16 _00;
	u16 _02;
	u32 _04;
} rec_header;
int v_header;
int gop_baseframe;
u32 gop_frame;
int vh_state;
SeqObj* hvqm_obj;
u32 dvd_active;
u8* virtualfile_buf;
BOOL record_ok;
void* ref1;
void* ref2;

static void InitPic();
static BOOL CheckDraw(u32 id);
static int Decode1(u8* data, u32 a1, u8 a2);

struct PICControl {
	void* _00;
	int _04;
	u32 _08;
	int _0C;
} pic_ctrl[24];
struct DVDControl {
	int _00;
	u8 mState;
	int _08;
	int _0C;
} dvd_ctrl[3];
static char filename[64];
static u32 dvd_buf[3];
int gop_subframe         = -1;
BOOL playback_first_wait = TRUE;
BOOL hvqm_first          = TRUE;
static struct HVQM_FileHeader {
	int _00;
	int _04;
	int _08;
	int _0C;
	int _10;
	u8 _14[4];
	u32 _18;
	int _1C;
	u8 _20[0x24]; // TODO: unknown fields
} file_header;
static u32 gop_header[5]; // TODO: struct?
static OSThread jac_hvqmThread;
static u8 hvqmStack[0x1000];

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
		int inter;
		inter = OSDisableInterrupts();
		dvd_active += 1;

		DVDT_LoadtoDRAM(dvdcount, filename, dvd_buf[dvdcount % 3], dvdcount << 0x13, dvdload_size, NULL, __LoadFin);
		OSRestoreInterrupts(inter);
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  lwz       r6, 0x2D88(r13)
	  cmplwi    r6, 0
	  bne-      .loc_0x28
	  li        r0, 0x1
	  stw       r0, 0x2D68(r13)
	  b         .loc_0xF0

	.loc_0x28:
	  lwz       r4, 0x2D6C(r13)
	  li        r3, 0x3
	  lis       r5, 0x803E
	  divwu     r0, r4, r3
	  subi      r5, r5, 0x3320
	  mullw     r0, r0, r3
	  sub       r0, r4, r0
	  rlwinm    r0,r0,4,0,27
	  add       r4, r5, r0
	  lbzu      r0, 0x4(r4)
	  cmplwi    r0, 0x3
	  bne-      .loc_0xF0
	  lis       r0, 0x8
	  li        r3, 0x1
	  cmplw     r6, r0
	  stb       r3, 0x0(r4)
	  bge-      .loc_0x74
	  stw       r6, 0x2D84(r13)
	  b         .loc_0x78

	.loc_0x74:
	  stw       r0, 0x2D84(r13)

	.loc_0x78:
	  lwz       r3, 0x2D84(r13)
	  lwz       r0, 0x2D88(r13)
	  sub       r0, r0, r3
	  stw       r0, 0x2D88(r13)
	  bl        0x1DB274
	  lwz       r10, 0x2D6C(r13)
	  li        r8, 0x3
	  lwz       r4, 0x2DA8(r13)
	  addi      r31, r3, 0
	  divwu     r0, r10, r8
	  lis       r6, 0x8039
	  addi      r5, r4, 0x1
	  lwz       r7, 0x2D84(r13)
	  stw       r5, 0x2DA8(r13)
	  lis       r5, 0x8002
	  lis       r4, 0x8039
	  subi      r9, r5, 0x2260
	  mullw     r8, r0, r8
	  subi      r0, r6, 0x5680
	  subi      r4, r4, 0x56C0
	  addi      r3, r10, 0
	  rlwinm    r6,r10,19,0,12
	  sub       r5, r10, r8
	  li        r8, 0
	  rlwinm    r5,r5,2,0,29
	  add       r5, r0, r5
	  lwz       r5, 0x0(r5)
	  bl        -0x16464
	  mr        r3, r31
	  bl        0x1DB238

	.loc_0xF0:
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
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
void Jac_HVQM_Init(const char* filepath, u8* data, int a)
{
	playback_first_wait = TRUE;
	for (u32 i = 0; i < a; i++) {
		data[i] = 0;
	}
	dvdcount          = 0;
	dvd_active        = 0;
	vh_state          = 0;
	drop_picture_flag = 1;
	record_ok         = TRUE;
	PIC_FRAME         = 0;
	AUDIO_FRAME       = 0;

	if (0x40000 >= a || (0x60000 >= a - 0x40000)) {
		return;
	}

	virtualfile_buf = data + 0x40000;

	u32 ptr = (u32)data + 0xa0000;
	int min = a - 0xa0000;
	for (u32 i = 0; i < 3; i++) {
		if (min < 0x80000) {
			return;
		}
		dvd_buf[i] = ptr;
		ptr += 0x80000;
		min -= 0x80000;
	}

	for (u32 i = 0; i < 3; i++) {
		dvd_ctrl[i].mState = 3;
	}
	arcoffset      = 0;
	dvd_loadfinish = 0;
	dvdfile_size   = DVDT_CheckFile(filepath) - 0x80000;
	u32 status;
	DVDT_LoadtoDRAM(dvdcount, filepath, dvd_buf[dvdcount % 3], 0, 0x80000, &status, 0);
	while (status == 0) { }

	dvd_ctrl[0]._08    = 0;
	dvd_ctrl[0].mState = 1;
	dvd_ctrl[0]._0C    = 0x80000;
	dvdcount++;
	strcpy(filename, filepath);
	__ReLoad();

	for (int i = 0; i < 8; i++) {
		dvd_buf[i] = dvd_buf[i + 1];
	}

	int filed     = file_header._10;
	gop_baseframe = 0;
	arcoffset += 0x44;
	gop_frame    = 0;
	gop_subframe = -1;

	int test;
	switch (file_header._18) {
	case 4:
		test = (file_header._10 << 4) / 0x12;
		break;
	case 2:
		test = file_header._10 >> 1;
		break;
	case 3:
		test = file_header._10;
		break;
	case 5:
		test = (file_header._10 << 4) / 0x24;
		break;
	}
	file_header._10 = 0;

	StreamHeader_ header;
	header._00         = test;
	header._08         = file_header._1C;
	header.audioFormat = file_header._18;
	header._0C         = 0x10;
	header._0E         = 0x1e;

	for (int i = 0; i < 4; i++) {
		//	header._10[i] = 0;
	}
	InitAudio1(&header, data, 0x40000);
	hvqm_obj = (SeqObj*)(ptr + 0x80000);
	HVQM4InitDecoder();
	HVQM4InitSeqObj(hvqm_obj, (VideoInfo*)file_header._00);

	int size = OSRoundDown32B(HVQM4BuffSize(hvqm_obj));
	if (size < min - 0x80020) {
		ptr = ptr + 0x80020 + min;
		size -= (min - 0x80020);
		HVQM4SetBuffer(hvqm_obj, (void*)(ptr + 0x80020));
		PIC_BUFFERS = 0;

		for (int i = 0; i < 0x18; i++) {
			if (min < 0x70800) {
				break;
			}
			pic_ctrl[i]._00 = (void*)ptr;
			PIC_BUFFERS++;
			pic_ctrl[i]._0C = 0x12345678;
			ptr += 0x70800;
			min -= 0x70800;
		}
		InitPic();
		int start = Jac_GetCurrentSCounter();
		while (start == Jac_GetCurrentSCounter()) { }
	}
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  lis       r7, 0x8039
	  stwu      r1, -0x90(r1)
	  stmw      r26, 0x78(r1)
	  subi      r31, r7, 0x56C0
	  addi      r26, r4, 0
	  lis       r29, 0x4
	  stw       r3, 0x8(r1)
	  stw       r0, -0x7EBC(r13)
	  stw       r6, 0x70(r1)
	  b         .loc_0x48

	.loc_0x38:
	  stbx      r6, r26, r0
	  lwz       r3, 0x70(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x70(r1)

	.loc_0x48:
	  lwz       r0, 0x70(r1)
	  cmplw     r0, r5
	  blt+      .loc_0x38
	  lis       r0, 0x4
	  li        r6, 0
	  li        r3, 0x1
	  cmplw     r5, r0
	  stw       r6, 0x2D6C(r13)
	  stw       r6, 0x2DA8(r13)
	  stw       r6, 0x2DA0(r13)
	  stw       r3, 0x2D7C(r13)
	  stw       r3, 0x2DB0(r13)
	  stw       r6, 0x2D78(r13)
	  stw       r6, 0x2D74(r13)
	  blt-      .loc_0x3A8
	  subis     r3, r5, 0x4
	  lis       r0, 0x6
	  cmplw     r3, r0
	  addi      r28, r26, 0
	  blt-      .loc_0x3A8
	  addis     r3, r26, 0x4
	  li        r0, 0x3
	  stw       r3, 0x2DAC(r13)
	  subis     r27, r5, 0xA
	  addis     r26, r26, 0xA
	  lis       r4, 0x8
	  mtctr     r0

	.loc_0xB4:
	  cmplw     r27, r4
	  blt-      .loc_0x3A8
	  add       r3, r31, r6
	  subis     r27, r27, 0x8
	  stw       r26, 0x40(r3)
	  addis     r26, r26, 0x8
	  addi      r6, r6, 0x4
	  bdnz+     .loc_0xB4
	  lis       r3, 0x803E
	  li        r0, 0x3
	  subi      r5, r3, 0x3320
	  li        r3, 0
	  li        r6, 0x3
	  mtctr     r0

	.loc_0xEC:
	  add       r4, r5, r3
	  addi      r3, r3, 0x10
	  stb       r6, 0x4(r4)
	  bdnz+     .loc_0xEC
	  li        r0, 0
	  lwz       r30, 0x8(r1)
	  stw       r0, 0x2D70(r13)
	  mr        r3, r30
	  stw       r0, 0x2D68(r13)
	  bl        -0x162B0
	  lwz       r10, 0x2D6C(r13)
	  li        r5, 0x3
	  stw       r3, 0x2D88(r13)
	  addi      r4, r30, 0
	  divwu     r0, r10, r5
	  addi      r3, r10, 0
	  lwz       r7, 0x2D88(r13)
	  addi      r8, r1, 0x68
	  li        r6, 0
	  subis     r7, r7, 0x8
	  stw       r7, 0x2D88(r13)
	  lis       r7, 0x8
	  mullw     r0, r0, r5
	  li        r9, 0
	  sub       r0, r10, r0
	  rlwinm    r0,r0,2,0,29
	  add       r5, r31, r0
	  lwz       r5, 0x40(r5)
	  bl        -0x1687C

	.loc_0x160:
	  lwz       r0, 0x68(r1)
	  cmplwi    r0, 0
	  beq+      .loc_0x160
	  lis       r3, 0x803E
	  li        r0, 0
	  subi      r6, r3, 0x3320
	  li        r5, 0x2
	  stw       r0, 0x8(r6)
	  lis       r0, 0x8
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  stb       r5, 0x4(r6)
	  stw       r0, 0xC(r6)
	  lwz       r5, 0x2D6C(r13)
	  addi      r0, r5, 0x1
	  stw       r0, 0x2D6C(r13)
	  bl        0x1FB198
	  bl        -0x544
	  lwz       r3, 0x40(r31)
	  li        r0, 0x8
	  addi      r6, r31, 0x44
	  subi      r4, r3, 0x8
	  mtctr     r0

	.loc_0x1BC:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r6)
	  stw       r0, 0x4(r6)
	  bdnz+     .loc_0x1BC
	  lwz       r5, 0x8(r4)
	  li        r4, 0
	  li        r0, -0x1
	  addi      r3, r31, 0x7C
	  stw       r5, 0x8(r6)
	  lwz       r5, 0x2D70(r13)
	  stw       r4, 0x2D98(r13)
	  addi      r5, r5, 0x44
	  stw       r5, 0x2D70(r13)
	  stw       r4, 0x2D9C(r13)
	  stw       r0, -0x7EC0(r13)
	  lbz       r0, 0x88(r31)
	  stw       r0, 0x38(r1)
	  lwz       r4, 0x8C(r31)
	  lwz       r0, 0x38(r1)
	  stw       r4, 0x3C(r1)
	  cmpwi     r0, 0x4
	  lwz       r4, 0x7C(r31)
	  stw       r4, 0x34(r1)
	  beq-      .loc_0x240
	  bge-      .loc_0x234
	  cmpwi     r0, 0x2
	  beq-      .loc_0x258
	  bge-      .loc_0x268
	  b         .loc_0x288

	.loc_0x234:
	  cmpwi     r0, 0x6
	  bge-      .loc_0x288
	  b         .loc_0x274

	.loc_0x240:
	  lwz       r5, 0x34(r1)
	  li        r4, 0x12
	  rlwinm    r5,r5,4,0,27
	  divwu     r4, r5, r4
	  stw       r4, 0x30(r1)
	  b         .loc_0x288

	.loc_0x258:
	  lwz       r4, 0x34(r1)
	  rlwinm    r4,r4,31,1,31
	  stw       r4, 0x30(r1)
	  b         .loc_0x288

	.loc_0x268:
	  lwz       r4, 0x34(r1)
	  stw       r4, 0x30(r1)
	  b         .loc_0x288

	.loc_0x274:
	  lwz       r5, 0x34(r1)
	  li        r4, 0x24
	  rlwinm    r5,r5,4,0,27
	  divwu     r4, r5, r4
	  stw       r4, 0x30(r1)

	.loc_0x288:
	  li        r10, 0
	  li        r7, 0x10
	  stw       r10, 0x0(r3)
	  li        r6, 0x1E
	  li        r3, 0x4
	  addi      r5, r1, 0x40
	  lwz       r9, 0x34(r1)
	  li        r4, 0
	  lwz       r8, 0x3C(r1)
	  stw       r9, 0x40(r1)
	  lwz       r9, 0x30(r1)
	  stw       r9, 0x44(r1)
	  sth       r8, 0x48(r1)
	  sth       r0, 0x4A(r1)
	  sth       r7, 0x4C(r1)
	  sth       r6, 0x4E(r1)
	  mtctr     r3

	.loc_0x2CC:
	  addi      r0, r4, 0x10
	  addi      r4, r4, 0x4
	  stwx      r10, r5, r0
	  bdnz+     .loc_0x2CC
	  addi      r4, r28, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x40
	  bl        -0x348
	  stw       r26, 0x2DA4(r13)
	  addi      r26, r26, 0x20
	  subi      r27, r27, 0x20
	  bl        0x53D4
	  lwz       r3, 0x2DA4(r13)
	  addi      r4, r31, 0x80
	  bl        0x53E8
	  lwz       r3, 0x2DA4(r13)
	  bl        0x5404
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  cmplw     r27, r0
	  blt-      .loc_0x3A8
	  lwz       r3, 0x2DA4(r13)
	  mr        r4, r26
	  add       r26, r26, r0
	  sub       r27, r27, r0
	  bl        0x5454
	  lis       r5, 0x7
	  lis       r4, 0x803E
	  lis       r3, 0x1234
	  li        r0, 0x18
	  addi      r6, r5, 0x800
	  subi      r5, r4, 0x34D0
	  addi      r4, r3, 0x5678
	  li        r8, 0
	  li        r3, 0
	  mtctr     r0

	.loc_0x35C:
	  cmplw     r27, r6
	  blt-      .loc_0x38C
	  add       r7, r5, r3
	  subis     r27, r27, 0x7
	  stw       r26, 0x0(r7)
	  addis     r26, r26, 0x7
	  addi      r8, r8, 0x1
	  addi      r3, r3, 0x10
	  stw       r4, 0xC(r7)
	  addi      r26, r26, 0x800
	  subi      r27, r27, 0x800
	  bdnz+     .loc_0x35C

	.loc_0x38C:
	  stw       r8, 0x2D80(r13)
	  bl        0x6F0
	  bl        -0x17834
	  mr        r26, r3

	.loc_0x39C:
	  bl        -0x1783C
	  cmplw     r26, r3
	  beq+      .loc_0x39C

	.loc_0x3A8:
	  lmw       r26, 0x78(r1)
	  lwz       r0, 0x94(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
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
	u32 badCompiler[2];
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
	*x         = file_header._08;
	*y         = file_header._0C;

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

	for (int i = 0; i < PIC_BUFFERS; i++) {
		u32* data = &pic_ctrl[i]._08;
		if (pic_ctrl[i]._08) {
			if (frame < pic_ctrl[i]._04) {
				if (offset < pic_ctrl[i]._04) {
					index  = i;
					offset = pic_ctrl[i]._04;
				}
			} else {
				if (pic_ctrl[i]._08 == 2) {
					*data = 0;
				}
			}
		}
	}

	if (index != -1) {
		pic_ctrl[index]._08 = 2;
	}

	for (int i = 0; i < PIC_BUFFERS; i++) {
		if (pic_ctrl[i]._08 && frame == pic_ctrl[i]._04) {
			pic_ctrl[i]._08   = 2;
			*(void**)data     = pic_ctrl[i]._00;
			drop_picture_flag = 0;
			if (index != -1 && index != i) {
				pic_ctrl[i]._08 = 0;
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

	if (gop_frame == file_header._10) {
		StreamSyncStopAudio(0);
	}
	*(int*)data = NULL;
	return FALSE;
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8039
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r28, 0x18(r1)
	  subi      r31, r6, 0x56C0
	  addi      r28, r3, 0
	  li        r30, 0
	  li        r29, -0x1
	  lhz       r0, 0x80(r31)
	  stw       r0, 0x0(r4)
	  lhz       r0, 0x82(r31)
	  stw       r0, 0x0(r5)
	  lwz       r0, -0x7EBC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x50
	  li        r0, 0
	  li        r3, 0x1
	  stw       r0, 0x0(r28)
	  b         .loc_0x214

	.loc_0x50:
	  li        r3, 0
	  li        r4, 0x2
	  bl        -0x1138
	  cmpwi     r3, -0x1
	  bne-      .loc_0x78
	  bl        -0x4E4
	  li        r0, 0
	  li        r3, -0x1
	  stw       r0, 0x0(r28)
	  b         .loc_0x214

	.loc_0x78:
	  lwz       r10, 0x2D80(r13)
	  li        r4, 0
	  lis       r6, 0x803E
	  addi      r5, r4, 0
	  addi      r0, r4, 0
	  stw       r3, 0x2D74(r13)
	  subi      r6, r6, 0x34D0
	  li        r11, 0
	  mtctr     r10
	  cmplwi    r10, 0
	  ble-      .loc_0xF4

	.loc_0xA4:
	  add       r7, r6, r4
	  addi      r8, r7, 0x8
	  lwz       r9, 0x8(r7)
	  cmplwi    r9, 0
	  beq-      .loc_0xE8
	  lwz       r7, 0x4(r7)
	  cmplw     r7, r3
	  bgt-      .loc_0xDC
	  cmplw     r30, r7
	  bge-      .loc_0xD4
	  addi      r30, r7, 0
	  addi      r29, r11, 0

	.loc_0xD4:
	  stw       r5, 0x0(r8)
	  b         .loc_0xE8

	.loc_0xDC:
	  cmplwi    r9, 0x2
	  bne-      .loc_0xE8
	  stw       r0, 0x0(r8)

	.loc_0xE8:
	  addi      r11, r11, 0x1
	  addi      r4, r4, 0x10
	  bdnz+     .loc_0xA4

	.loc_0xF4:
	  cmpwi     r29, -0x1
	  beq-      .loc_0x114
	  lis       r4, 0x803E
	  rlwinm    r0,r29,4,0,27
	  subi      r4, r4, 0x34D0
	  li        r5, 0x2
	  add       r4, r4, r0
	  stw       r5, 0x8(r4)

	.loc_0x114:
	  lis       r4, 0x803E
	  li        r8, 0
	  subi      r5, r4, 0x34D0
	  li        r4, 0
	  mtctr     r10
	  cmplwi    r10, 0
	  ble-      .loc_0x1B0

	.loc_0x130:
	  add       r7, r5, r4
	  lwz       r0, 0x8(r7)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A4
	  lwz       r0, 0x4(r7)
	  cmplw     r3, r0
	  bne-      .loc_0x1A4
	  lis       r5, 0x803E
	  li        r0, 0x2
	  subi      r6, r5, 0x34D0
	  cmpwi     r29, -0x1
	  add       r4, r6, r4
	  li        r5, 0
	  stw       r0, 0x8(r4)
	  lwz       r0, 0x0(r7)
	  stw       r0, 0x0(r28)
	  stw       r5, 0x2D7C(r13)
	  beq-      .loc_0x18C
	  cmplw     r29, r8
	  beq-      .loc_0x18C
	  rlwinm    r0,r29,4,0,27
	  add       r4, r6, r0
	  stw       r5, 0x8(r4)

	.loc_0x18C:
	  cmpwi     r3, 0x3
	  bge-      .loc_0x19C
	  li        r0, 0
	  stw       r0, 0x0(r28)

	.loc_0x19C:
	  addi      r3, r3, 0x1
	  b         .loc_0x214

	.loc_0x1A4:
	  addi      r8, r8, 0x1
	  addi      r4, r4, 0x10
	  bdnz+     .loc_0x130

	.loc_0x1B0:
	  li        r0, 0x1
	  cmpwi     r29, -0x1
	  stw       r0, 0x2D7C(r13)
	  beq-      .loc_0x1F0
	  lis       r4, 0x803E
	  rlwinm    r5,r29,4,0,27
	  subi      r0, r4, 0x34D0
	  cmpwi     r3, 0x3
	  add       r3, r0, r5
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x0(r28)
	  bge-      .loc_0x1E8
	  li        r0, 0
	  stw       r0, 0x0(r28)

	.loc_0x1E8:
	  addi      r3, r30, 0x1
	  b         .loc_0x214

	.loc_0x1F0:
	  lwz       r3, 0x2D9C(r13)
	  lwz       r0, 0x64(r31)
	  cmplw     r3, r0
	  bne-      .loc_0x208
	  li        r3, 0
	  bl        -0x15C4

	.loc_0x208:
	  li        r0, 0
	  li        r3, 0
	  stw       r0, 0x0(r28)

	.loc_0x214:
	  lmw       r28, 0x18(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
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
