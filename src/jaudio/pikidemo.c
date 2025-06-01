#include "jaudio/pikidemo.h"
#include "jaudio/jammain_2.h"
#include "jaudio/cmdqueue.h"
#include "jaudio/piki_scene.h"
#include "jaudio/piki_player.h"
#include "jaudio/piki_bgm.h"
#include "jaudio/waveread.h"
#include "jaudio/interface.h"
#include "jaudio/verysimple.h"
#include "jaudio/dvdthread.h"
#include "GlobalGameOptions.h"

void __Prepare_BGM(u32);
void Jac_BgmAnimEndStop();
void Jac_BgmAnimEndRecover();

u32 now_loading;
u8 event_pause_counter;
u8 demo_parts_id;
u8 demo_onyon_num;
u8 demo_parts_num;
u32 demo_end_delay;
int current_demo_no = -1;
int demo_seq_active = -1;
int demo_mml_active = -1;
int parts_find_demo_state;
int text_demo_state;
seqp_* demo_bgm_seqp;
seqp_* demo_seqp;
BOOL demo_inited;
static CmdQueue demo_q;
int current_seq_bgm;

// table for which parts play the sparkle sound on collect
static u8 parts_bright_table[MAX_UFO_PARTS] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

typedef struct DemoStatus {
	u8 _00;  // _00
	u8 _01;  // _01
	u8 _02;  // _02
	u8 _03;  // _03
	u32 _04; // _04
	u8* _08; // _08
} DemoStatus;

// I gave up on about half of these
// it was probably meant to be a u16 array but I cant be assed now
static u8 demo1[]  = { 0, 4, 255, 250, 7, 208, 255, 255 };
static u8 demo2[]  = { 7, 208, 255, 255 };
static u8 demo3[]  = { 1, 124, 0, 1, 1, 188, 255, 255 };
static u8 demo4[]  = { 0, 0, 0, 0,  0, 2, 255, 250, 0, 5, 0, 1,   0, 15, 0, 2,   0, 25, 0, 1,  0,   30,
	                   0, 3, 0, 60, 0, 4, 0,   154, 0, 5, 0, 176, 0, 6,  0, 225, 0, 7,  1, 24, 255, 255 };
static u8 demo5[]  = { 0, 0,  0, 0, 0, 2,   255, 250, 0, 5,   0, 1, 0, 15,  0, 2, 0, 21, 0,   3,
	                   0, 60, 0, 4, 0, 128, 0,   5,   0, 150, 0, 6, 0, 200, 0, 7, 1, 24, 255, 255 };
static u8 demo9[]  = { 0, 4, 255, 250, 0, 200, 255, 251, 0, 201, 255, 253 };
static u8 demo12[] = { 0, 4, 0, 0, 2, 88, 255, 255 };
static u8 demo16[]
    = { 0, 4, 255, 250, 0, 10, 0, 1, 0, 19, 0, 2, 0, 31, 0, 1, 0, 42, 0, 2, 0, 52, 0, 2, 0, 64, 0, 3, 0, 120, 0, 6, 1, 44, 255, 255 };
static u8 demo17[]
    = { 0, 4, 255, 250, 0, 10, 0, 1, 0, 19, 0, 2, 0, 31, 0, 1, 0, 42, 0, 2, 0, 52, 0, 2, 0, 64, 0, 3, 0, 120, 0, 6, 1, 44, 255, 255 };
static u8 demo18[] = { 0, 8, 255, 250, 0, 140, 0, 8, 0, 200, 0, 0, 1, 109, 255, 254 };
static u8 demo19[] = { 0, 8,  255, 250, 0, 10, 0, 10,  0, 45, 0, 11,  0, 65, 0, 14,  0, 84, 0, 15,  0,   98,
	                   0, 16, 0,   102, 0, 12, 0, 108, 0, 13, 0, 140, 0, 8,  0, 200, 0, 0,  1, 109, 255, 254 };
static u8 demo20[] = { 0, 4,  255, 250, 0, 10, 0, 0, 0, 48,  0, 1, 0, 65,  0, 2, 0, 80, 0,   3,
	                   0, 92, 0,   4,   0, 96, 0, 5, 0, 120, 0, 7, 0, 185, 0, 6, 1, 44, 255, 255 };
static u8 demo21[] = { 0, 4,  255, 250, 0, 10, 0, 0, 0, 48,  0, 1, 0, 65,  0, 2, 0, 80, 0,   3,
	                   0, 92, 0,   4,   0, 96, 0, 5, 0, 100, 0, 7, 0, 148, 0, 6, 1, 44, 255, 255 };
static u8 demo24[] = { 0, 4,  255, 250, 0, 10, 0, 0, 0, 48,  0, 1, 0, 65,  0, 2, 0, 80, 0,   3,
	                   0, 92, 0,   4,   0, 96, 0, 5, 0, 100, 0, 7, 0, 148, 0, 6, 1, 44, 255, 255 };
static u8 demo25[]
    = { 0, 8, 255, 250, 0, 14, 0, 10, 0, 18, 0, 11, 0, 90, 0, 12, 0, 123, 0, 13, 0, 140, 0, 8, 0, 200, 0, 0, 1, 109, 255, 254 };
static u8 demo26[]
    = { 0, 8, 255, 250, 0, 14, 0, 10, 0, 18, 0, 11, 0, 90, 0, 12, 0, 123, 0, 13, 0, 140, 0, 8, 0, 200, 0, 0, 1, 109, 255, 254 };
static u8 demo27[] = { 0, 4, 0, 0, 2, 88, 255, 255 };
static u8 demo28[]
    = { 0, 8, 255, 250, 0, 14, 0, 10, 0, 18, 0, 11, 0, 90, 0, 12, 0, 123, 0, 13, 0, 140, 0, 8, 0, 200, 0, 0, 1, 109, 255, 254 };
static u8 demo29[]
    = { 0, 8, 255, 250, 0, 14, 0, 10, 0, 18, 0, 11, 0, 90, 0, 12, 0, 123, 0, 13, 0, 140, 0, 8, 0, 200, 0, 0, 1, 109, 255, 254 };
static u8 demo32[]  = { 0, 0, 0, 0, 0, 160, 0, 1, 2, 88, 255, 255 };
static u8 demo40[]  = { 0, 3, 0, 2, 0, 4, 0, 3, 0, 150, 0, 0, 0, 190, 0, 1, 1, 12, 255, 255 };
static u8 demo47[]  = { 0, 3, 0, 2, 0, 4, 0, 3, 0, 150, 0, 0, 0, 190, 0, 1, 1, 12, 255, 255 };
static u8 demo52[]  = { 0, 3, 0, 2, 0, 4, 0, 3, 0, 150, 0, 0, 0, 190, 0, 1, 1, 12, 255, 255 };
static u8 demo69[]  = { 0, 4, 255, 250, 0, 145, 0, 0, 0, 225, 0, 1, 1, 24, 0, 3, 4, 76, 255, 255 };
static u8 demo73[]  = { 0, 4, 255, 250, 0, 145, 0, 0, 0, 225, 0, 1, 1, 24, 0, 3, 4, 76, 255, 255 };
static u8 demo74[]  = { 0, 4, 255, 250, 0, 145, 0, 0, 0, 225, 0, 1, 1, 24, 0, 3, 4, 76, 255, 255 };
static u8 demo75[]  = { 0, 4, 255, 250, 0, 145, 0, 0, 0, 225, 0, 1, 1, 24, 0, 3, 4, 76, 255, 255 };
static u8 demo76[]  = { 0, 4, 255, 250, 0, 145, 0, 0, 0, 225, 0, 1, 1, 24, 0, 3, 4, 76, 255, 255 };
static u8 demo100[] = { 0, 3, 0, 2, 0, 4, 0, 3, 0, 150, 0, 0, 0, 190, 0, 1, 0, 204, 0, 1, 1, 12, 255, 255 };
static u8 demo101[] = { 0, 4, 255, 250, 0, 145, 0, 0, 0, 225, 0, 1, 1, 24, 0, 3, 4, 76, 255, 255 };
static u8 demo102[] = { 0, 160, 0, 1, 2, 88, 255, 255 };
static u8 demo113[] = { 0, 4, 255, 250, 0, 145, 0, 0, 0, 225, 0, 1, 1, 24, 0, 3, 4, 76, 255, 255 };
static u8 demo114[] = { 0, 3, 0, 0, 0, 4, 255, 250, 4, 76, 255, 255 };

static DemoStatus DEMO_STATUS[] = {
	{ 0, 2, 1, 131, 0, NULL },   { 0, 2, 1, 168, 0, demo1 },   { 0, 2, 1, 192, 0, demo2 },   { 0, 5, 1, 0, 0, demo3 },
	{ 1, 2, 1, 141, 0, demo4 },  { 1, 2, 1, 141, 0, demo5 },   { 1, 2, 1, 141, 0, demo5 },   { 2, 5, 0, 0, 0, NULL },
	{ 1, 1, 1, 0, 0, NULL },     { 3, 2, 1, 2, 0, demo9 },     { 3, 2, 1, 2, 0, demo9 },     { 3, 2, 1, 2, 0, demo9 },
	{ 3, 5, 1, 0, 0, demo12 },   { 1, 5, 1, 0, 0, NULL },      { 2, 1, 0, 0, 0, NULL },      { 2, 5, 0, 0, 0, NULL },
	{ 1, 2, 1, 7, 0, demo16 },   { 0, 4, 1, 9, 0, demo17 },    { 0, 2, 1, 1, 0, demo18 },    { 0, 2, 1, 1, 0, demo19 },
	{ 0, 2, 1, 6, 0, demo20 },   { 0, 2, 1, 6, 0, demo21 },    { 0, 2, 1, 6, 0, demo21 },    { 0, 2, 1, 6, 0, demo21 },
	{ 0, 2, 1, 6, 0, demo24 },   { 0, 2, 1, 1, 0, demo25 },    { 0, 4, 1, 10, 0, demo26 },   { 3, 5, 1, 0, 0, demo27 },
	{ 0, 4, 2, 162, 0, demo28 }, { 0, 4, 2, 162, 0, demo29 },  { 0, 4, 2, 162, 0, demo29 },  { 0, 4, 2, 162, 0, demo29 },
	{ 0, 1, 2, 192, 0, demo32 }, { 0, 1, 2, 192, 0, demo32 },  { 0, 1, 2, 192, 0, demo32 },  { 0, 1, 2, 192, 0, demo32 },
	{ 0, 1, 2, 37, 0, NULL },    { 0, 1, 2, 37, 0, NULL },     { 0, 1, 2, 37, 0, NULL },     { 0, 1, 2, 37, 0, NULL },
	{ 0, 5, 1, 0, 0, demo40 },   { 0, 5, 1, 0, 0, demo40 },    { 0, 5, 1, 0, 0, demo40 },    { 0, 5, 1, 0, 0, demo40 },
	{ 1, 5, 1, 0, 0, NULL },     { 1, 5, 1, 0, 0, NULL },      { 0, 4, 1, 129, 0, NULL },    { 0, 1, 2, 132, 0, demo47 },
	{ 0, 1, 2, 132, 0, demo47 }, { 0, 1, 2, 132, 0, demo47 },  { 0, 1, 2, 132, 0, demo47 },  { 0, 4, 1, 129, 0, NULL },
	{ 0, 4, 2, 132, 0, demo52 }, { 0, 4, 2, 132, 0, demo52 },  { 0, 4, 2, 132, 0, demo52 },  { 0, 4, 2, 132, 0, demo52 },
	{ 0, 2, 1, 0, 0, NULL },     { 0, 2, 1, 0, 0, NULL },      { 0, 2, 1, 0, 0, NULL },      { 0, 2, 1, 0, 0, NULL },
	{ 1, 5, 0, 0, 0, NULL },     { 1, 5, 0, 0, 0, NULL },      { 1, 5, 0, 0, 0, NULL },      { 1, 5, 0, 0, 0, NULL },
	{ 1, 5, 0, 0, 0, NULL },     { 1, 5, 0, 0, 0, NULL },      { 1, 5, 0, 0, 0, NULL },      { 1, 5, 0, 0, 0, NULL },
	{ 4, 5, 1, 0, 0, NULL },     { 0, 4, 2, 134, 0, demo69 },  { 0, 4, 2, 134, 0, demo69 },  { 0, 4, 2, 134, 0, demo69 },
	{ 0, 4, 2, 134, 0, demo69 }, { 0, 2, 1, 135, 0, demo73 },  { 0, 2, 1, 140, 0, demo74 },  { 0, 2, 1, 171, 0, demo75 },
	{ 0, 4, 2, 170, 0, demo76 }, { 0, 1, 1, 192, 0, NULL },    { 0, 2, 1, 6, 0, demo21 },    { 0, 2, 1, 6, 0, demo21 },
	{ 0, 2, 1, 1, 0, demo18 },   { 0, 2, 1, 0, 0, NULL },      { 0, 2, 1, 0, 0, NULL },      { 0, 2, 1, 0, 0, NULL },
	{ 0, 2, 1, 0, 0, NULL },     { 0, 2, 1, 0, 0, NULL },      { 0, 2, 1, 0, 0, NULL },      { 0, 4, 2, 162, 0, demo29 },
	{ 0, 1, 2, 192, 0, demo32 }, { 0, 5, 1, 0, 0, demo40 },    { 0, 1, 2, 132, 0, demo47 },  { 0, 4, 2, 132, 0, demo52 },
	{ 1, 5, 1, 0, 0, NULL },     { 1, 5, 0, 0, 0, NULL },      { 0, 4, 2, 134, 0, demo69 },  { 0, 2, 1, 0, 0, NULL },
	{ 0, 2, 1, 0, 0, NULL },     { 0, 2, 1, 0, 0, NULL },      { 0, 2, 1, 0, 0, NULL },      { 0, 2, 1, 0, 0, NULL },
	{ 0, 5, 1, 0, 0, demo100 },  { 0, 2, 1, 6, 0, demo101 },   { 0, 4, 2, 0, 0, demo102 },   { 0, 2, 1, 0, 0, NULL },
	{ 0, 2, 1, 0, 0, NULL },     { 0, 2, 1, 0, 0, NULL },      { 0, 2, 1, 0, 0, NULL },      { 0, 2, 1, 0, 0, NULL },
	{ 0, 2, 1, 0, 0, NULL },     { 0, 2, 1, 0, 0, NULL },      { 0, 2, 1, 0, 0, NULL },      { 0, 2, 1, 0, 0, NULL },
	{ 0, 2, 1, 0, 0, NULL },     { 0, 2, 2, 192, 0, demo113 }, { 0, 4, 2, 169, 0, demo114 },
};

/*
 * --INFO--
 * Address:	8001A0E0
 * Size:	000010
 */
void Jac_DemoSceneInit(void)
{
	now_loading         = 0;
	event_pause_counter = 0;
}

/*
 * --INFO--
 * Address:	8001A100
 * Size:	000018
 */
static void Jac_DemoCheckFrameCall()
{
	BUMP_REGISTER(r3);
	if (demo_end_delay != 0) {
		demo_end_delay--;
	}
}

/*
 * --INFO--
 * Address:	8001A120
 * Size:	000050
 */
void Jac_DemoEventUnPauseCheck()
{
	if (event_pause_counter) {
		event_pause_counter--;

		if (event_pause_counter == 0) {
			Jam_UnPauseTrack(Jam_GetTrackHandle(0x20000), 1);
		}
	}

	Jac_DemoCheckFrameCall();
}

/*
 * --INFO--
 * Address:	8001A180
 * Size:	000048
 */
BOOL Jac_DemoCheck()
{
	if (demo_end_delay) {
		return TRUE;
	}

	if (current_demo_no == -1 && parts_find_demo_state == 0 && text_demo_state == 0) {
		return FALSE;
	}

	return TRUE;
}

/*
 * --INFO--
 * Address:	8001A1E0
 * Size:	000080
 */
BOOL Jac_DemoWalkCheck()
{
	if (demo_end_delay != 0) {
		return FALSE;
	}

	if (current_demo_no == -1 && parts_find_demo_state == 0 && text_demo_state == 0) {
		return TRUE;
	}

	switch (current_demo_no) {
	case 0x59:
	case 0x64:
	case 0x28:
	case 0x29:
	case 0x2A:
	case 0x2B:
		return TRUE;
	}
	return FALSE;
	/*
	.loc_0x0:
	  lwz       r0, 0x2D50(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x14
	  li        r3, 0
	  blr

	.loc_0x14:
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x40
	  lwz       r0, 0x2D44(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x40
	  lwz       r0, 0x2D48(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x40
	  li        r3, 0x1
	  blr

	.loc_0x40:
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, 0x59
	  beq-      .loc_0x70
	  bge-      .loc_0x64
	  cmpwi     r0, 0x2C
	  bge-      .loc_0x78
	  cmpwi     r0, 0x28
	  bge-      .loc_0x70
	  b         .loc_0x78

	.loc_0x64:
	  cmpwi     r0, 0x64
	  beq-      .loc_0x70
	  b         .loc_0x78

	.loc_0x70:
	  li        r3, 0x1
	  blr

	.loc_0x78:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001A260
 * Size:	00007C
 */
BOOL Jac_DemoCheckEvent(u8 evt)
{
	if (Jac_DemoCheck()) {
		switch (current_demo_no) {
		case 0x57:
		case 0x1C:
		case 0x1D:
		case 0x1E:
		case 0x1F:
			return FALSE;
		}

		if (DEMO_STATUS[current_demo_no]._02 == 2) {
			return FALSE;
		}
	}
	return TRUE;
}

/*
 * --INFO--
 * Address:	8001A2E0
 * Size:	00016C
 */
static void DoSequence(u32 id, u32 a2)
{
	u32 flag;
	u16* REF_flag;
	u32* REF_a2 = &a2;
	u32* data   = (u32*)DEMO_STATUS[id]._08;
	u32 badCompiler[2];
	if (data == NULL) {
		demo_seq_active = -1;
		return;
	}

	while (1) {
		flag     = data[demo_seq_active];
		REF_flag = (u16*)&flag;
		if (REF_flag[0] > a2) {
			break;
		}

		if (REF_flag[1] == 0xfff9) {
			switch (id) {
			case 0x14:
				__Prepare_BGM(0x11);
				break;
			case 0x18:
				__Prepare_BGM(0x1a);
				break;
			}
		} else if (REF_flag[1] == 0xfffa) {
			if (DEMO_STATUS[id]._03 & 0x80) {
				Jac_StartDemoSound(DEMO_STATUS[id]._03 & 0xf);
			} else {
				demo_bgm_seqp = Jam_GetTrackHandle(0x30000);
				Jam_WritePortAppDirect(demo_bgm_seqp, 0, DEMO_STATUS[id]._03 & 0xf);
				current_seq_bgm = DEMO_STATUS[id]._03 & 0xf;
			}
		} else {
			if (REF_flag[1] == 0xffff) {
				Jac_FinishDemo();
				return;
			}
			if (REF_flag[1] == 0xfffe) {
				demo_seq_active = -1;
				return;
			}
			if (REF_flag[1] == 0xfffd) {
				demo_seq_active = -1;
				return;
			}
			if (REF_flag[1] == 0xfffc) {
				Jac_BgmAnimEndStop();

			} else if (REF_flag[1] == 0xfffb) {
				Jac_BgmAnimEndRecover();
			} else {
				Jac_DemoSound(REF_flag[1]);
			}
		}

		demo_seq_active++;
	}
}

/*
 * --INFO--
 * Address:	8001A460
 * Size:	000044
 */
void Jac_PlayDemoSequenceDirect(u32 id)
{
	demo_bgm_seqp = Jam_GetTrackHandle(0x30000);
	Jam_WritePortAppDirect(demo_bgm_seqp, 0, id);
}

/*
 * --INFO--
 * Address:	8001A4C0
 * Size:	000050
 */
void Jac_InitDemoSystem()
{
	demo_seqp = Jam_GetTrackHandle(0x1000f);
	if (demo_seqp) {
		Jal_AddCmdQueue(&demo_q, demo_seqp, 2);
		demo_inited = TRUE;
	}
}

/*
 * --INFO--
 * Address:	8001A520
 * Size:	0004F0
 */
void Jac_StartDemo(int id)
{
	Jam_WritePortAppDirect(demo_seqp, 0, id);
	if (-1 < demo_mml_active) {
		Jam_WritePortAppDirect(demo_seqp, 1, id);
	}
	Jac_Orima_Formation(0, 0);
	Jac_SetProcessStatus(5);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r29, 0x54(r1)
	  stw       r3, 0x8(r1)
	  lis       r3, 0x8022
	  addi      r31, r3, 0x64B0
	  lwz       r29, 0x8(r1)
	  mulli     r0, r29, 0xC
	  cmplwi    r29, 0x50
	  add       r30, r31, r0
	  addi      r30, r30, 0x500
	  blt-      .loc_0x68
	  cmpwi     r29, 0x5F
	  bge-      .loc_0x54
	  cmpwi     r29, 0x50
	  beq-      .loc_0x68
	  blt-      .loc_0x4DC
	  cmpwi     r29, 0x57
	  bge-      .loc_0x68
	  b         .loc_0x4DC

	.loc_0x54:
	  cmpwi     r29, 0x73
	  bge-      .loc_0x4DC
	  cmpwi     r29, 0x71
	  bge-      .loc_0x68
	  b         .loc_0x4DC

	.loc_0x68:
	  cmpwi     r29, 0x3C
	  bge-      .loc_0x80
	  cmpwi     r29, 0x38
	  bge-      .loc_0x4DC
	  b         .loc_0x80
	  b         .loc_0x4DC

	.loc_0x80:
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x94
	  cmplw     r29, r0
	  beq-      .loc_0x4DC

	.loc_0x94:
	  bl        -0xD54
	  cmpwi     r3, 0x1
	  bne-      .loc_0xB8
	  cmpwi     r29, 0x28
	  bge-      .loc_0xB8
	  cmpwi     r29, 0x24
	  bge-      .loc_0x4DC
	  b         .loc_0xB8
	  b         .loc_0x4DC

	.loc_0xB8:
	  lwz       r0, 0x2D3C(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0xD4
	  bl        -0x124
	  lwz       r0, 0x2D3C(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x4DC

	.loc_0xD4:
	  li        r3, 0x4
	  bl        -0x3C38
	  cmpwi     r29, 0x28
	  bge-      .loc_0x128
	  cmpwi     r29, 0x19
	  beq-      .loc_0x168
	  bge-      .loc_0x108
	  cmpwi     r29, 0x14
	  beq-      .loc_0x218
	  bge-      .loc_0x1B4
	  cmpwi     r29, 0x12
	  bge-      .loc_0x168
	  b         .loc_0x218

	.loc_0x108:
	  cmpwi     r29, 0x20
	  bge-      .loc_0x11C
	  cmpwi     r29, 0x1C
	  bge-      .loc_0x20C
	  b         .loc_0x218

	.loc_0x11C:
	  cmpwi     r29, 0x24
	  bge-      .loc_0x218
	  b         .loc_0x1D4

	.loc_0x128:
	  cmpwi     r29, 0x57
	  beq-      .loc_0x20C
	  bge-      .loc_0x158
	  cmpwi     r29, 0x4F
	  beq-      .loc_0x1B4
	  bge-      .loc_0x14C
	  cmpwi     r29, 0x2C
	  bge-      .loc_0x218
	  b         .loc_0x1F0

	.loc_0x14C:
	  cmpwi     r29, 0x51
	  bge-      .loc_0x218
	  b         .loc_0x168

	.loc_0x158:
	  cmpwi     r29, 0x59
	  beq-      .loc_0x1F0
	  bge-      .loc_0x218
	  b         .loc_0x1D4

	.loc_0x168:
	  lbz       r0, 0x2D4E(r13)
	  cmpwi     r0, 0x7
	  beq-      .loc_0x19C
	  bge-      .loc_0x184
	  cmpwi     r0, 0x4
	  beq-      .loc_0x190
	  b         .loc_0x218

	.loc_0x184:
	  cmpwi     r0, 0x1D
	  beq-      .loc_0x1A8
	  b         .loc_0x218

	.loc_0x190:
	  li        r0, 0x12
	  stw       r0, 0x8(r1)
	  b         .loc_0x218

	.loc_0x19C:
	  li        r0, 0x13
	  stw       r0, 0x8(r1)
	  b         .loc_0x218

	.loc_0x1A8:
	  li        r0, 0x19
	  stw       r0, 0x8(r1)
	  b         .loc_0x218

	.loc_0x1B4:
	  lbz       r0, 0x2D4C(r13)
	  lbzx      r0, r31, r0
	  cmplwi    r0, 0
	  bne-      .loc_0x218
	  li        r0, 0x65
	  addi      r30, r31, 0x9BC
	  stw       r0, 0x8(r1)
	  b         .loc_0x218

	.loc_0x1D4:
	  bl        -0xE94
	  cmpwi     r3, 0
	  beq-      .loc_0x218
	  li        r0, 0x66
	  addi      r30, r31, 0x9C8
	  stw       r0, 0x8(r1)
	  b         .loc_0x218

	.loc_0x1F0:
	  lbz       r0, 0x2D4D(r13)
	  cmplwi    r0, 0x3
	  bne-      .loc_0x218
	  li        r0, 0x64
	  addi      r30, r31, 0x9B0
	  stw       r0, 0x8(r1)
	  b         .loc_0x218

	.loc_0x20C:
	  li        r3, 0
	  bl        -0x2390
	  bl        -0xFD4

	.loc_0x218:
	  lbz       r0, 0x0(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x22C
	  li        r3, 0x19
	  bl        -0x3BA8

	.loc_0x22C:
	  lwz       r0, -0x7F10(r13)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x244
	  bl        0x708
	  lwz       r3, 0x8(r1)
	  bl        0x740

	.loc_0x244:
	  lwz       r0, 0x2D40(r13)
	  lwz       r31, 0x8(r1)
	  cmplwi    r0, 0
	  stw       r31, -0x7F10(r13)
	  bne-      .loc_0x260
	  mr        r3, r31
	  bl        0x8E4

	.loc_0x260:
	  lbz       r0, 0x1(r30)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x2F0
	  bge-      .loc_0x288
	  cmpwi     r0, 0x1
	  beq-      .loc_0x300
	  bge-      .loc_0x2AC
	  cmpwi     r0, 0
	  bge-      .loc_0x298
	  b         .loc_0x300

	.loc_0x288:
	  cmpwi     r0, 0x5
	  beq-      .loc_0x2DC
	  bge-      .loc_0x300
	  b         .loc_0x2C0

	.loc_0x298:
	  li        r3, 0
	  bl        -0x1C3C
	  li        r3, 0x1
	  bl        -0x1C44
	  b         .loc_0x300

	.loc_0x2AC:
	  lfs       f1, -0x7E18(r2)
	  li        r3, 0x1
	  li        r4, 0xF
	  bl        -0x11D8
	  b         .loc_0x300

	.loc_0x2C0:
	  li        r3, 0
	  li        r4, 0xF
	  bl        -0x1CA8
	  li        r3, 0x1
	  li        r4, 0xF
	  bl        -0x1CB4
	  b         .loc_0x300

	.loc_0x2DC:
	  lfs       f1, -0x7E14(r2)
	  li        r3, 0x1
	  li        r4, 0x1E
	  bl        -0x1208
	  b         .loc_0x300

	.loc_0x2F0:
	  lfs       f1, -0x7E10(r2)
	  li        r3, 0x1
	  li        r4, 0x8
	  bl        -0x121C

	.loc_0x300:
	  lbz       r0, 0x2(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x320
	  bge-      .loc_0x314
	  b         .loc_0x354

	.loc_0x314:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x354
	  b         .loc_0x344

	.loc_0x320:
	  li        r0, 0
	  lis       r3, 0x2
	  stb       r0, 0x2D4F(r13)
	  bl        -0xA1EC
	  stw       r3, 0x48(r1)
	  li        r4, 0x1
	  lwz       r3, 0x48(r1)
	  bl        -0x937C
	  b         .loc_0x354

	.loc_0x344:
	  bl        -0x2824
	  li        r3, 0
	  li        r4, 0
	  bl        -0x2670

	.loc_0x354:
	  cmpwi     r31, 0x2
	  bge-      .loc_0x364
	  cmpwi     r31, 0
	  bge-      .loc_0x370

	.loc_0x364:
	  lwz       r0, 0x2D40(r13)
	  cmplwi    r0, 0x3
	  blt+      .loc_0x364

	.loc_0x370:
	  li        r0, 0
	  cmplwi    r31, 0x14
	  stw       r0, 0x2D40(r13)
	  bne-      .loc_0x3A8
	  li        r0, 0x1
	  li        r3, 0x11
	  stw       r0, 0x2D40(r13)
	  bl        0x5F4
	  lwz       r0, 0x2D40(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x3A8

	.loc_0x39C:
	  lwz       r0, 0x2D40(r13)
	  cmplwi    r0, 0x3
	  blt+      .loc_0x39C

	.loc_0x3A8:
	  cmplwi    r31, 0x18
	  bne-      .loc_0x3D8
	  li        r0, 0x1
	  li        r3, 0x1A
	  stw       r0, 0x2D40(r13)
	  bl        0x5C4
	  lwz       r0, 0x2D40(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x3D8

	.loc_0x3CC:
	  lwz       r0, 0x2D40(r13)
	  cmplwi    r0, 0x3
	  blt+      .loc_0x3CC

	.loc_0x3D8:
	  lbz       r3, 0x3(r30)
	  rlwinm    r0,r3,0,25,31
	  cmpwi     r0, 0x40
	  beq-      .loc_0x454
	  bge-      .loc_0x3F4
	  cmpwi     r0, 0
	  beq-      .loc_0x454

	.loc_0x3F4:
	  rlwinm.   r0,r3,0,24,24
	  beq-      .loc_0x414
	  lwz       r0, 0x8(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x454
	  rlwinm    r3,r3,0,28,31
	  bl        -0x90C
	  b         .loc_0x454

	.loc_0x414:
	  rlwinm.   r0,r3,0,28,31
	  beq-      .loc_0x454
	  lwz       r0, 0x8(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x454
	  lis       r3, 0x3
	  bl        -0xA2EC
	  stw       r3, 0x2D34(r13)
	  li        r4, 0
	  lbz       r0, 0x3(r30)
	  lwz       r3, 0x2D34(r13)
	  rlwinm    r5,r0,0,28,31
	  bl        -0xA5E4
	  lbz       r0, 0x3(r30)
	  rlwinm    r0,r0,0,28,31
	  stw       r0, 0x2D38(r13)

	.loc_0x454:
	  li        r0, -0x1
	  li        r3, 0
	  stw       r0, -0x7F08(r13)
	  stw       r3, -0x7F0C(r13)
	  lbz       r0, 0x4(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x49C
	  bge-      .loc_0x484
	  cmpwi     r0, 0
	  beq-      .loc_0x49C
	  bge-      .loc_0x490
	  b         .loc_0x49C

	.loc_0x484:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x49C
	  b         .loc_0x498

	.loc_0x490:
	  stw       r3, -0x7F08(r13)
	  b         .loc_0x49C

	.loc_0x498:
	  stw       r3, -0x7F08(r13)

	.loc_0x49C:
	  lwz       r3, 0x2D30(r13)
	  rlwinm    r5,r31,0,16,31
	  li        r4, 0
	  bl        -0xA648
	  lwz       r0, -0x7F08(r13)
	  cmpwi     r0, 0
	  blt-      .loc_0x4C8
	  lwz       r3, 0x2D30(r13)
	  rlwinm    r5,r31,0,16,31
	  li        r4, 0x1
	  bl        -0xA664

	.loc_0x4C8:
	  li        r3, 0
	  li        r4, 0
	  bl        -0x27F0
	  li        r3, 0x5
	  bl        -0x4038

	.loc_0x4DC:
	  lmw       r29, 0x54(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001AA20
 * Size:	000040
 */
void Jac_DemoSound(int id)
{
	u32 badCompiler;
	int* REF_id;

	if (current_demo_no != -1) {
		REF_id = &id;
		Jal_SendCmdQueue_Noblock(&demo_q, id);
	}
}

/*
 * --INFO--
 * Address:	8001AA60
 * Size:	00004C
 */
BOOL Jac_DemoFrame(int id)
{
	if (current_demo_no == -1) {
		return FALSE;
	}

	if (0 <= demo_seq_active) {
		DoSequence(current_demo_no, id);
	}

	return TRUE;
}

/*
 * --INFO--
 * Address:	8001AAC0
 * Size:	00007C
 */
void Jac_BgmAnimEndRecover()
{
	switch (DEMO_STATUS[current_demo_no]._01) {
	case 0:
	case 1:
		break;
	case 2:
	case 5:
		Jac_DemoFade(2, 70, 0.5);
		break;
	case 3:
		Jac_DemoFade(2, 70, 0.5);
		break;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x69B0
	  stwu      r1, -0x8(r1)
	  lwz       r4, -0x7F10(r13)
	  mulli     r3, r4, 0xC
	  add       r3, r0, r3
	  lbz       r0, 0x1(r3)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x5C
	  bge-      .loc_0x3C
	  cmpwi     r0, 0x2
	  bge-      .loc_0x48
	  b         .loc_0x6C

	.loc_0x3C:
	  cmpwi     r0, 0x5
	  beq-      .loc_0x48
	  b         .loc_0x6C

	.loc_0x48:
	  lfs       f1, -0x7E14(r2)
	  li        r3, 0x2
	  li        r4, 0x46
	  bl        -0x1514
	  b         .loc_0x6C

	.loc_0x5C:
	  lfs       f1, -0x7E14(r2)
	  li        r3, 0x2
	  li        r4, 0x46
	  bl        -0x1528

	.loc_0x6C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001AB40
 * Size:	00005C
 */
void Jac_BgmAnimEndStop()
{
	int flag;

	flag = DEMO_STATUS[current_demo_no]._03;
	if (flag && !(flag & 0x20)) {
		if (flag & 0x80) {
			Jac_StopDemoSound(flag & 0xf);
		} else {
			Jac_DemoBGMForceStop();
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x69B0
	  stwu      r1, -0x8(r1)
	  lwz       r4, -0x7F10(r13)
	  mulli     r3, r4, 0xC
	  add       r3, r0, r3
	  lbz       r3, 0x3(r3)
	  cmpwi     r3, 0
	  beq-      .loc_0x4C
	  rlwinm.   r0,r3,0,26,26
	  bne-      .loc_0x4C
	  rlwinm.   r0,r3,0,24,24
	  beq-      .loc_0x48
	  rlwinm    r3,r3,0,28,31
	  bl        -0xC40
	  b         .loc_0x4C

	.loc_0x48:
	  bl        0x18

	.loc_0x4C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001ABA0
 * Size:	0000D0
 */
void Jac_DemoBGMForceStop()
{
	demo_bgm_seqp = Jam_GetTrackHandle(0x30000);
	Jam_WritePortAppDirect(demo_bgm_seqp, 0, 0);

	switch (current_seq_bgm) {
	case 1:
		WaveScene_Erase(0xd, 7);
		break;
	case 5:
		WaveScene_Erase(0xd, 3);
		break;
	case 6:
		WaveScene_Erase(0xd, 4);
		break;
	case 7:
		WaveScene_Erase(0xd, 5);
		break;
	case 8:
		WaveScene_Erase(0xd, 6);
		break;
	case 9:
		WaveScene_Erase(0xd, 1);
		break;
	case 10:
		WaveScene_Erase(0xd, 8);
	}
	current_seq_bgm = 0;
}

/*
 * --INFO--
 * Address:	8001AC80
 * Size:	000108
 */
void __Jac_FinishDemo()
{
	u32 badCompiler[2];
	if (current_demo_no == -1) {
		return;
	}

	DemoStatus* state = &DEMO_STATUS[current_demo_no];
	switch (state->_01) {
	case 0:
	case 1:
		break;
	case 2:
	case 5:
		Jac_DemoFade(0, 70, 1.0f);
		break;
	case 3:
		Jac_DemoFade(0, 70, 1.0f);
		break;
	}

	switch (state->_02) {
	case 2:
		Jac_Orima_Formation(0, 0);
		break;
	case 1:
		event_pause_counter = 6;
		break;
	case 0:
		break;
	}

	int flag;

	flag = state->_03;
	if (flag && !(flag & 0x20)) {
		if (flag & 0x80) {
			Jac_StopDemoSound(flag & 0xf);
		} else {
			Jac_DemoBGMForceStop();
		}
	}

	Jam_WritePortAppDirect(demo_seqp, 0, 0);
	demo_seq_active = -1;
	current_demo_no = -1;
}

/*
 * --INFO--
 * Address:	8001ADA0
 * Size:	0000A8
 */
void Jac_FinishDemo(void)
{
	int demo      = current_demo_no;
	int* REF_demo = &demo;
	u32 badCompiler;
	Jac_SetProcessStatus(6);
	__Jac_FinishDemo();

	if (demo >= 0) {
		switch (demo) {
		case 0x18:
		case 0x11:
		case 0x1:
		case 0x14:
			break;

		case 0x57:
		case 0x1C:
		case 0x1D:
		case 0x1E:
		case 0x1F:
			demo_end_delay = 100;
			break;
		default:
			now_loading = 0;
			break;
		}
	}

	Jac_SetProcessStatus(7);
}

/*
 * --INFO--
 * Address:	8001AE60
 * Size:	000020
 */
void Jac_FinishDemo_NoErase()
{
	__Jac_FinishDemo();
}

/*
 * --INFO--
 * Address:	8001AE80
 * Size:	000020
 */
void __Loaded(u32 a)
{
	if ((int)(a & 0xFFFF0000) < -0x7fffffff) {
		now_loading = 3;
	}
}

/*
 * --INFO--
 * Address:	8001AEA0
 * Size:	0001AC
 */
void __Prepare_BGM(u32 a)
{
	int set;
	u8 flag;
	DemoStatus* state = &DEMO_STATUS[a];

	if (a >= 0x50) {
		switch (a) {
		case 0x50:
		case 0x57:
		case 0x58:
		case 0x59:
		case 0x5A:
		case 0x5B:
		case 0x5C:
		case 0x5D:
		case 0x5E:
		case 0x64:
		case 0x65:
		case 0x66:
		case 0x71:
		case 0x72:
			break;

		default:
			return;
		}
	}

	switch (a) {
	case 0x38:
	case 0x39:
	case 0x3A:
	case 0x3B:
		return;
	}

	flag = state->_03;
	switch (flag & 0x7F) {
	case 0x40:
	case 0x0:
		break;

	default:
		if (flag & 0x80) {
			Jac_PrepareDemoSound(flag & 0xf);
			now_loading = 3;
			return;
		}

		if (flag & 0x40) {
			now_loading = 3;
			return;
		}

		switch (flag & 0xf) {
		case 1:
			set = WaveScene_Set(0xd, 7);
			break;
		case 5:
			set = WaveScene_Set(0xd, 3);
			break;
		case 6:
			set = WaveScene_Set(0xd, 4);
			break;
		case 7:
			set = WaveScene_Set(0xd, 5);
			break;
		case 8:
			set = WaveScene_Set(0xd, 6);
			break;
		case 9:
			set = WaveScene_Set(0xd, 1);
			break;
		case 10:
			set = WaveScene_Set(0xd, 8);
			break;
		case 0:
			now_loading = 3;
			return;
		}

		if (set == FALSE) {
			now_loading = 0;
			return;
		}
	}

	DVDT_CheckPass(0x80000000, 0, __Loaded);
}

/*
 * --INFO--
 * Address:	8001B060
 * Size:	0000A8
 */
void Jac_PrepareDemo(u32 id)
{
	u32 badCompiler;
	u32* REF_id = &id;
	if (id >= 0x50) {
		switch (id) {
		case 0x50:
		case 0x57:
		case 0x58:
		case 0x59:
		case 0x5A:
		case 0x5B:
		case 0x5C:
		case 0x5D:
		case 0x5E:
		case 0x64:
		case 0x65:
		case 0x66:
		case 0x71:
		case 0x72:
			break;

		default:
			return;
		}
	}

	switch (id) {
	case 0x38:
	case 0x39:
	case 0x3A:
	case 0x3B:
		return;
	}

	if (now_loading == 0) {
		now_loading = 1;
	}
	__Prepare_BGM(id);
}

/*
 * --INFO--
 * Address:	8001B120
 * Size:	0000D0
 */
void Jac_StartPartsFindDemo(u32 p1, int p2)
{
	int badcompiler[2];
	u32* REF_p1;

	if (parts_find_demo_state == 1) {
		if (p2) {
			Jac_PlaySystemSe(0x1e);
		}
		return;
	}

	event_pause_counter = 0;
	Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);
	Jac_Orima_Formation(0, 0);
	Jac_PauseOrimaSe();

	if (p2) {
		Jac_DemoFade(1, 15, 0.1f);

		REF_p1 = &p1;
		if (p1 == 0) {
			Jac_PlaySystemSe(0x24);
		} else {
			Jac_PlaySystemSe(0x1e);
		}
	} else {
		Jac_DemoFade(1, 0x1e, 0.5f);
		Jac_PlaySystemSe(0x1f);
	}
	parts_find_demo_state = 1;
}

/*
 * --INFO--
 * Address:	8001B200
 * Size:	00004C
 */
void Jac_FinishPartsFindDemo(void)
{
	if (parts_find_demo_state) {
		event_pause_counter = 3;
		Jac_DemoFade(0, 0x46, 1.0f);
		Jac_UnPauseOrimaSe();
		parts_find_demo_state = 0;
	}
}

/*
 * --INFO--
 * Address:	8001B260
 * Size:	000084
 */
void Jac_StartTextDemo(int a)
{
	if (text_demo_state != 1 && current_demo_no == -1) {
		switch (parts_find_demo_state) {
		case 0:
			event_pause_counter = 0;
			Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);
			Jac_Orima_Formation(0, 0);
			Jac_PauseOrimaSe();
			Jac_DemoFade(1, 0x1e, 0.5f);
			text_demo_state = 1;
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	8001B300
 * Size:	000068
 */
void Jac_FinishTextDemo(void)
{
	if (text_demo_state && current_demo_no == -1) {
		switch (parts_find_demo_state) {
		case 0:
			event_pause_counter = 3;
			Jac_UnPauseOrimaSe();
			Jac_DemoFade(0, 0x46, 1.0f);
			text_demo_state = 0;
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	8001B380
 * Size:	000018
 */
void Jac_SetDemoPartsID(int id)
{
	int* REF_id;

	REF_id        = &id;
	demo_parts_id = id;
}

/*
 * --INFO--
 * Address:	8001B3A0
 * Size:	000018
 */
void Jac_SetDemoOnyons(int num)
{
	int* REF_num;

	REF_num        = &num;
	demo_onyon_num = num;
}

/*
 * --INFO--
 * Address:	8001B3C0
 * Size:	000018
 */
void Jac_SetDemoPartsCount(int count)
{
	int* REF_count;

	REF_count      = &count;
	demo_parts_num = count;
}
