#include "jaudio/pikidemo.h"
#include "jaudio/jammain_2.h"
#include "jaudio/cmdqueue.h"
#include "jaudio/pikiinter.h"
#include "jaudio/piki_scene.h"
#include "jaudio/piki_player.h"
#include "jaudio/piki_bgm.h"
#include "jaudio/waveread.h"
#include "jaudio/interface.h"
#include "jaudio/verysimple.h"
#include "jaudio/dvdthread.h"
#include "jaudio/pikiinter.h"
#include "GlobalGameOptions.h"
#include "MoviePlayer.h"

void __Prepare_BGM(u32);
void Jac_BgmAnimEndStop();
void Jac_BgmAnimEndRecover();
void Jac_FinishDemo_NoErase();

vu32 now_loading;
u8 event_pause_counter;
u8 demo_parts_id;
u8 demo_onyon_num;
u8 demo_parts_num;
u32 demo_end_delay;
s32 current_demo_no = DEMOID_FINISHED; // uses CinDemoIDs enum
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
	u8 _04;  // _04
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

// indexed by CinDemoIDs in MoviePlayer.h
static DemoStatus DEMO_STATUS[DEMOID_COUNT] = {
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

	if (current_demo_no == DEMOID_FINISHED && parts_find_demo_state == 0 && text_demo_state == 0) {
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

	if (current_demo_no == DEMOID_FINISHED && parts_find_demo_state == 0 && text_demo_state == 0) {
		return TRUE;
	}

	switch (current_demo_no) {
	case DEMOID_Unk89:
	case DEMOID_Unk100:
	case DEMOID_LandingTutorial:
	case DEMOID_LandingForest:
	case DEMOID_LandingCaveLast:
	case DEMOID_LandingYakushima:
		return TRUE;
	}
	return FALSE;
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
		case DEMOID_Unk87:
		case DEMOID_DayEndTutorial:
		case DEMOID_DayEndForest:
		case DEMOID_DayEndCaveLast:
		case DEMOID_DayEndYakushima:
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
static void DoSequence(u32 cinID, u32 a2)
{
	u32 flag;
	u16* REF_flag;
	u32* REF_a2 = &a2;
	u32* data   = (u32*)DEMO_STATUS[cinID]._08;
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
			switch (cinID) {
			case DEMOID_CollectFirstPartTutorial:
				__Prepare_BGM(DEMOID_ShipUpgradeTutorial);
				break;
			case DEMOID_Unk24:
				__Prepare_BGM(DEMOID_ShipUpgradeLast);
				break;
			}
		} else if (REF_flag[1] == 0xfffa) {
			if (DEMO_STATUS[cinID]._03 & 0x80) {
				Jac_StartDemoSound(DEMO_STATUS[cinID]._03 & 0xf);
			} else {
				demo_bgm_seqp = Jam_GetTrackHandle(0x30000);
				Jam_WritePortAppDirect(demo_bgm_seqp, 0, DEMO_STATUS[cinID]._03 & 0xf);
				current_seq_bgm = DEMO_STATUS[cinID]._03 & 0xf;
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
void Jac_StartDemo(u32 cinID)
{
	u32* REF_id        = &cinID;
	DemoStatus* status = &DEMO_STATUS[cinID];
	if (cinID >= DEMOID_CHECK_BGM_CAT) {
		switch (cinID) {
		case DEMOID_Unk80:
		case DEMOID_Unk87:
		case DEMOID_ChalDayEndLast:
		case DEMOID_Unk89:
		case DEMOID_Unk90:
		case DEMOID_Unk91:
		case DEMOID_Unk92:
		case DEMOID_Unk93:
		case DEMOID_Unk94:
		case DEMOID_GoodEndingTakeOff:
		case DEMOID_NeutralEndingLeaveOK:
			break;

		default:
			return;
		}
	}

	switch (cinID) {
	case DEMOID_TakeOffTutorial:
	case DEMOID_TakeOffForest:
	case DEMOID_TakeOffCaveLast:
	case DEMOID_TakeOffYakushima:
		return;
	}

	if (current_demo_no != -1 && cinID == current_demo_no) {
		return;
	}

	if (Jac_TellChgMode() == TRUE) {
		switch (cinID) {
		case DEMOID_EndOfDayResults:
		case DEMOID_Unk37:
		case DEMOID_Unk38:
		case DEMOID_Unk39:
			return;
		}
	}

	if (demo_inited == FALSE) {
		Jac_InitDemoSystem();
		if (demo_inited == FALSE) {
			return;
		}
	}

	Jac_SetProcessStatus(4);

	switch (cinID) {
	case DEMOID_ShipUpgradeForest:
	case DEMOID_ShipUpgradeCave:
	case DEMOID_ShipUpgradeYakushima:
	case DEMOID_Unk80:
		switch (demo_parts_num) {
		case 4:
			cinID = DEMOID_ShipUpgradeForest;
			break;
		case 7:
			cinID = DEMOID_ShipUpgradeCave;
			break;
		case 29:
			cinID = DEMOID_ShipUpgradeYakushima;
			break;
		}
		break;

	case DEMOID_CollectPartForest:
	case DEMOID_CollectPartCaveLast:
	case DEMOID_CollectPartYakushima:
	case DEMOID_Unk24:
	case DEMOID_CollectPartTutorial:
		if (parts_bright_table[demo_parts_id] == 0) {
			status = &DEMO_STATUS[DEMOID_Unk101];
			cinID  = DEMOID_Unk101;
		}
		break;

	case DEMOID_ChalDayEndTutorial:
	case DEMOID_ChalDayEndForest:
	case DEMOID_ChalDayEndCave:
	case DEMOID_ChalDayEndYakushima:
	case DEMOID_ChalDayEndLast:
		if (Jac_TellChgMode()) {
			status = &DEMO_STATUS[DEMOID_Unk102];
			cinID  = DEMOID_Unk102;
		}
		break;

	case DEMOID_LandingTutorial:
	case DEMOID_LandingForest:
	case DEMOID_LandingCaveLast:
	case DEMOID_LandingYakushima:
	case DEMOID_Unk89:
		if (demo_onyon_num == 3) {
			status = &DEMO_STATUS[DEMOID_Unk100];
			cinID  = DEMOID_Unk100;
		}
		break;

	case DEMOID_DayEndTutorial:
	case DEMOID_DayEndForest:
	case DEMOID_DayEndCaveLast:
	case DEMOID_DayEndYakushima:
	case DEMOID_Unk87:
		Jac_PlayOrimaSe(JACORIMA_PikiHit);
		Jac_Delete_CurrentBgmWave();
		break;
	}

	if (status->_00) {
		Jac_PlaySystemSe(JACSYS_Unk25);
	}

	if (current_demo_no != -1) {
		Jac_FinishDemo_NoErase();
		__Prepare_BGM(cinID);
	}

	current_demo_no = cinID;

	if (now_loading == 0) {
		Jac_PrepareDemo(cinID);
	}

	switch (status->_01) {
	case 0:
		Jac_StopBgm(0);
		Jac_StopBgm(1);
		break;
	case 1:
		break;
	case 2:
		Jac_DemoFade(1, 15, 0.01f);
		break;
	case 4:
		Jac_FadeOutBgm(0, 15);
		Jac_FadeOutBgm(1, 15);
		break;
	case 5:
		Jac_DemoFade(1, 30, 0.5f);
		break;
	case 3:
		Jac_DemoFade(1, 8, 0.0f);
		break;
	}

	switch (status->_02) {
	case 0:
		break;
	case 1:
		event_pause_counter = 0;
		seqp_* track        = Jam_GetTrackHandle(0x20000);
		seqp_** tp          = &track;
		Jam_PauseTrack(track, 1);
		break;
	case 2:
		Jac_InitAllEvent();
		Jac_Orima_Formation(0, 0);
		break;
	}

	switch (cinID) {
	case 0:
	case 1:
		break;

	default:
		while (now_loading < 3)
			;
	}

	now_loading = 0;

	if (cinID == DEMOID_CollectFirstPartTutorial) {
		now_loading = 1;
		__Prepare_BGM(DEMOID_ShipUpgradeTutorial);
		if (now_loading) {
			while (now_loading < 3)
				;
		}
	}

	if (cinID == DEMOID_Unk24) {
		now_loading = 1;
		__Prepare_BGM(DEMOID_ShipUpgradeLast);
		if (now_loading) {
			while (now_loading < 3)
				;
		}
	}

	s32 flag = status->_03 & 0x7f;
	if (flag != 0x40 && (flag >= 0x40 || flag != 0)) {
		if (status->_03 & 0x80) {
			if (status->_08 == NULL) {
				Jac_StartDemoSound(status->_03 & 0xf);
			}
		} else {
			if (status->_03 & 0xf && status->_08 == NULL) {
				demo_bgm_seqp = Jam_GetTrackHandle(0x30000);
				Jam_WritePortAppDirect(demo_bgm_seqp, 0, status->_03 & 0xf);
				current_seq_bgm = status->_03 & 0xf;
			}
		}
	}

	demo_mml_active = -1;
	demo_seq_active = 0;

	switch (status->_04) {
	case 0:
		break;
	case 1:
		demo_mml_active = 0;
		break;
	case 3:
		demo_mml_active = 0;
		break;
	}

	Jam_WritePortAppDirect(demo_seqp, 0, cinID);
	if (0 <= demo_mml_active) {
		Jam_WritePortAppDirect(demo_seqp, 1, cinID);
	}
	Jac_Orima_Formation(0, 0);
	Jac_SetProcessStatus(5);

	u32 badCompiler[14];
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

	if (current_demo_no != DEMOID_FINISHED) {
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
	if (current_demo_no == DEMOID_FINISHED) {
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
	DemoStatus* status = &DEMO_STATUS[current_demo_no];
	switch (status->_01) {
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
}

/*
 * --INFO--
 * Address:	8001AB40
 * Size:	00005C
 */
void Jac_BgmAnimEndStop()
{
	DemoStatus* status = &DEMO_STATUS[current_demo_no];
	int flag           = status->_03;
	if (flag && !(flag & 0x20)) {
		if (flag & 0x80) {
			Jac_StopDemoSound(flag & 0xf);
		} else {
			Jac_DemoBGMForceStop();
		}
	}
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
	if (current_demo_no == DEMOID_FINISHED) {
		return;
	}

	DemoStatus* status = &DEMO_STATUS[current_demo_no];
	switch (status->_01) {
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

	switch (status->_02) {
	case 2:
		Jac_Orima_Formation(0, 0);
		break;
	case 1:
		event_pause_counter = 6;
		break;
	case 0:
		break;
	}

	int flag = status->_03;
	if (flag && !(flag & 0x20)) {
		if (flag & 0x80) {
			Jac_StopDemoSound(flag & 0xf);
		} else {
			Jac_DemoBGMForceStop();
		}
	}

	Jam_WritePortAppDirect(demo_seqp, 0, 0);
	current_demo_no = DEMOID_FINISHED;
	demo_seq_active = -1;
}

/*
 * --INFO--
 * Address:	8001ADA0
 * Size:	0000A8
 */
void Jac_FinishDemo(void)
{
	int cinID     = current_demo_no;
	int* REF_demo = &cinID;
	u32 badCompiler;
	Jac_SetProcessStatus(6);
	__Jac_FinishDemo();

	if (cinID >= 0) {
		switch (cinID) {
		// these all require a demo to be loaded after them
		case DEMOID_OpeningIntroPt1:
		case DEMOID_ShipUpgradeTutorial:
		case DEMOID_CollectFirstPartTutorial:
		case DEMOID_Unk24: // collect final ship part?
			break;

		case DEMOID_Unk87:
		case DEMOID_DayEndTutorial:
		case DEMOID_DayEndForest:
		case DEMOID_DayEndCaveLast:
		case DEMOID_DayEndYakushima:
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
void __Prepare_BGM(u32 cinID)
{
	int set;
	u8 flag;
	DemoStatus* status = &DEMO_STATUS[cinID];

	if (cinID >= DEMOID_CHECK_BGM_CAT) {
		switch (cinID) {
		case DEMOID_Unk80:
		case DEMOID_Unk87:
		case DEMOID_ChalDayEndLast:
		case DEMOID_Unk89:
		case DEMOID_Unk90:
		case DEMOID_Unk91:
		case DEMOID_Unk92:
		case DEMOID_Unk93:
		case DEMOID_Unk94:
		case DEMOID_Unk100:
		case DEMOID_Unk101:
		case DEMOID_Unk102:
		case DEMOID_GoodEndingTakeOff:
		case DEMOID_NeutralEndingLeaveOK:
			break;

		default:
			return;
		}
	}

	switch (cinID) {
	// no BGM for take off cutscenes
	case DEMOID_TakeOffTutorial:
	case DEMOID_TakeOffForest:
	case DEMOID_TakeOffCaveLast:
	case DEMOID_TakeOffYakushima:
		return;
	}

	flag = status->_03;
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
void Jac_PrepareDemo(u32 cinID)
{
	u32 badCompiler;
	u32* REF_id = &cinID;
	if (cinID >= DEMOID_CHECK_BGM_CAT) {
		switch (cinID) {
		case DEMOID_Unk80:
		case DEMOID_Unk87:
		case DEMOID_ChalDayEndLast:
		case DEMOID_Unk89:
		case DEMOID_Unk90:
		case DEMOID_Unk91:
		case DEMOID_Unk92:
		case DEMOID_Unk93:
		case DEMOID_Unk94:
		case DEMOID_Unk100:
		case DEMOID_Unk101:
		case DEMOID_Unk102:
		case DEMOID_GoodEndingTakeOff:
		case DEMOID_NeutralEndingLeaveOK:
			break;

		default:
			return;
		}
	}

	switch (cinID) {
	case DEMOID_TakeOffTutorial:
	case DEMOID_TakeOffForest:
	case DEMOID_TakeOffCaveLast:
	case DEMOID_TakeOffYakushima:
		return;
	}

	if (now_loading == 0) {
		now_loading = 1;
	}
	__Prepare_BGM(cinID);
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
			Jac_PlaySystemSe(JACSYS_Unk30);
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
			Jac_PlaySystemSe(JACSYS_Unk36);
		} else {
			Jac_PlaySystemSe(JACSYS_Unk30);
		}
	} else {
		Jac_DemoFade(1, 0x1e, 0.5f);
		Jac_PlaySystemSe(JACSYS_Unk31);
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
	if (text_demo_state != 1 && current_demo_no == DEMOID_FINISHED) {
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
	if (text_demo_state != 0 && current_demo_no == DEMOID_FINISHED) {
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
