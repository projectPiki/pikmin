#include "jaudio/pikidemo.h"
#include "GlobalGameOptions.h"
#include "MoviePlayer.h"
#include "jaudio/cmdqueue.h"
#include "jaudio/dvdthread.h"
#include "jaudio/interface.h"
#include "jaudio/jammain_2.h"
#include "jaudio/piki_bgm.h"
#include "jaudio/piki_player.h"
#include "jaudio/piki_scene.h"
#include "jaudio/pikiinter.h"
#include "jaudio/verysimple.h"
#include "jaudio/waveread.h"

void __Prepare_BGM(u32);
void Jac_BgmAnimEndStop();
void Jac_BgmAnimEndRecover();
void Jac_FinishDemo_NoErase();

s32 current_demo_no = DEMOID_FINISHED; // uses CinDemoIDs enum
seqp_* demo_seqp;
seqp_* demo_bgm_seqp;
int current_seq_bgm;
int demo_seq_active = -1;
int demo_mml_active = -1;
BOOL demo_inited;
vu32 now_loading;
int parts_find_demo_state;
int text_demo_state;
u8 demo_parts_id;
u8 demo_onyon_num;
u8 demo_parts_num;
u8 event_pause_counter;
u32 demo_end_delay;
static CmdQueue demo_q;

// table for which parts play the sparkle sound on collect
static u8 parts_bright_table[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

typedef struct DemoStatus {
	u8 mPlayStartSound; // _00, Whether to play system sound when cutscene starts (0=no, 1=yes)

	/**
	 * - 0: Stop all BGM immediately
	 * - 1: Keep current BGM playing
	 * - 2: Fade in over 15 frames to 1% volume
	 * - 3: Fade in over 8 frames to 0% volume
	 * - 4: Fade out both BGM channels over 15 frames
	 * - 5: Fade in over 30 frames to 50% volume
	 */
	u8 mBgmFadeMode; // _01

	/**
	 * - 0: Normal gameplay events continue
	 * - 1: Pause main track, set pause counter for resuming later
	 * - 2: Initialize all events, reset formation sound, block certain demo events
	 */
	u8 mGameplayFlags; // _02

	/**
	 * - Bits 0-3 (0x0F): Audio/BGM ID number (1-10 map to different tracks)
	 * - Bit 5 (0x20): Special flag to prevent audio stopping
	 * - Bits 0-6 (0x7F): Combined ID field
	 * - Bit 7 (0x80): Demo sound vs BGM flag (1=demo sound, 0=BGM)
	 * - Special values: 0x40 = no audio, 0x00 = default
	 */
	u8 mAudioConfig; // _03

	u8 mSequenceFlags; // _04, Music sequence/MML activation mode
	s16* mTimedEvents; // _08, Pointer to timed event sequence data
} DemoStatus;

static s16 demo1[]  = { 4, -6, 2000, -1 };
static s16 demo2[]  = { 2000, -1 };
static s16 demo3[]  = { 380, 1, 444, -1 };
static s16 demo4[]  = { 0, 0, 2, -6, 5, 1, 15, 2, 25, 1, 30, 3, 60, 4, 154, 5, 176, 6, 225, 7, 280, -1 };
static s16 demo5[]  = { 0, 0, 2, -6, 5, 1, 15, 2, 21, 3, 60, 4, 128, 5, 150, 6, 200, 7, 280, -1 };
static s16 demo9[]  = { 4, -6, 200, -5, 201, -3 };
static s16 demo12[] = { 4, 0, 600, -1 };
static s16 demo16[] = { 4, -6, 10, 1, 19, 2, 31, 1, 42, 2, 52, 2, 64, 3, 120, 6, 300, -1 };
static s16 demo17[] = { 8, -6,  56, 10,  64, 11,  80, 12,  98, 13,  128, 14,  140, 8,   163, 1,   172, 2,   183, 1,   192,
	                    2, 200, 0,  203, 1,  213, 2,  224, 1,  232, 2,   250, 3,   270, 4,   294, 5,   310, 9,   365, -2 };
static s16 demo18[] = { 8, -6, 140, 8, 200, 0, 365, -2 };
static s16 demo19[] = { 8, -6, 10, 10, 45, 11, 65, 14, 84, 15, 98, 16, 102, 12, 108, 13, 140, 8, 200, 0, 365, -2 };
static s16 demo20[] = { 4, -6, 10, 0, 48, 1, 65, 2, 80, 3, 92, 4, 96, 5, 120, 7, 185, 6, 300, -1 };
static s16 demo21[] = { 4, -6, 10, 0, 48, 1, 65, 2, 80, 3, 92, 4, 96, 5, 100, 7, 148, 6, 300, -1 };
static s16 demo24[] = { 4, -6, 10, 0, 48, 1, 65, 2, 80, 3, 92, 4, 96, 5, 100, 7, 148, 6, 300, -1 };
static s16 demo25[] = { 8, -6, 14, 10, 18, 11, 90, 12, 123, 13, 140, 8, 200, 0, 365, -2 };
static s16 demo26[] = { 8, -6, 240, 0, 250, 9, 308, 1, 320, 2, 330, 1, 337, 2, 348, 1, 355, 3, 392, 4, 421, 5, 440, 8, 500, -2 };
static s16 demo27[] = { 4, 0, 600, -1 };
static s16 demo28[]
    = { 4,   -6, 30,  0, 41,  1, 53,  0, 65,  1, 77,  0, 89,  1, 101, 0, 111, 1, 122, 0, 131, 1, 143, 0, 150, 2, 215, 3, 310, 4, 320, 5,
	    330, 4,  342, 5, 350, 4, 362, 5, 372, 4, 381, 5, 391, 4, 403, 5, 413, 4, 423, 5, 433, 4, 443, 6, 490, 7, 561, 8, 600, -2 };
static s16 demo29[]
    = { 4,   -6, 30,  0, 41,  1, 53,  0, 65,  1, 77,  0, 89,  1, 101, 0, 111, 1, 122, 0, 131, 1, 143, 0, 150, 2, 215, 3, 310, 4, 320, 5,
	    330, 4,  342, 5, 350, 4, 362, 5, 372, 4, 381, 5, 391, 4, 403, 5, 413, 4, 423, 5, 433, 4, 443, 6, 490, 7, 561, 8, 600, -2 };
static s16 demo32[] = { 0, 0, 160, 1, 600, -1 };
static s16 demo40[] = { 3, 2, 4, 3, 150, 0, 190, 1, 268, -1 };
static s16 demo47[] = { 4, -6, 21, 0, 43, 1, 62, 0, 78, 1, 103, 2, 220, 0, 240, 1, 300, 3, 358, 4, 380, -1 };
static s16 demo52[] = { 4, -6, 104, 0, 122, 1, 205, 0, 224, 1, 244, 0, 262, 1, 282, 0, 306, 1, 326, 2, 360, 3, 420, 4, 450, -1 };
static s16 demo56[]
    = { 0, 0, 10, 7, 75, 1, 85, 6, 87, 2, 105, 1, 117, 2, 132, 1, 145, 7, 147, 2, 165, 3, 173, 4, 206, 5, 214, 5, 222, 5, 228, -1 };
static s16 demo69[]  = { 4, -6, 145, 0, 225, 1, 280, 3, 1100, -1 };
static s16 demo73[]  = { 2, -6, 3, 0, 43, 1, 72, 2, 135, 1, 148, 2, 172, 1, 210, 2, 270, 3, 320, 4, 350, 5, 411, 6, 1100, -1 };
static s16 demo74[]  = { 2, -6, 3, 0, 215, 1, 395, 2, 458, 3, 500, 4, 534, 5, 535, 6, 585, 7, 673, 8, 685, 9, 736, 10, 750, 11, 1100, -1 };
static s16 demo75[]  = { 4, -6, 150, 3, 160, 4, 170, 3, 180, 4, 190, 5, 900, 0, 945, 1, 993, 2, 1100, -1 };
static s16 demo76[]  = { 4, -6, 3, 0, 240, 1, 382, 2, 1100, -1 };
static s16 demo100[] = { 3, 2, 4, 3, 150, 0, 190, 1, 204, 1, 268, -1 };
static s16 demo101[] = { 4, -6, 10, 0, 48, 1, 65, 2, 80, 3, 92, 4, 96, 5, 300, -1 };
static s16 demo102[] = { 160, 1, 600, -1 };
static s16 demo113[] = { 34,  1, 41,  2, 50,  0, 53,  1,  83,  2, 85,  1, 286, 3,  400, 4, 462,  5,
	                     474, 6, 482, 5, 512, 6, 527, 11, 539, 9, 540, 7, 568, 10, 570, 8, 1200, -1 };
static s16 demo114[] = { 3, 0, 4, -6, 1100, -1 };

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

/**
 * @TODO: Documentation
 */
void Jac_DemoSceneInit(void)
{
	now_loading         = 0;
	event_pause_counter = 0;
}

/**
 * @TODO: Documentation
 */
static void Jac_DemoCheckFrameCall()
{
	BUMP_REGISTER(r3);
	if (demo_end_delay != 0) {
		demo_end_delay--;
	}
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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
	case DEMOID_GenericLanding:
	case DEMOID_Unk100:
	case DEMOID_LandingPractice:
	case DEMOID_LandingForest:
	case DEMOID_LandingCaveLast:
	case DEMOID_LandingYakushima:
		return TRUE;
	}
	return FALSE;
}

/**
 * @TODO: Documentation
 */
BOOL Jac_DemoCheckEvent(u8 evt)
{
	if (Jac_DemoCheck()) {
		switch (current_demo_no) {
		case DEMOID_GenericDayEnd:
		case DEMOID_DayEndPractice:
		case DEMOID_DayEndForest:
		case DEMOID_DayEndCaveLast:
		case DEMOID_DayEndYakushima:
			return FALSE;
		}

		if (DEMO_STATUS[current_demo_no].mGameplayFlags == 2) {
			return FALSE;
		}
	}
	return TRUE;
}

/**
 * @TODO: Documentation
 */
static void DoSequence(u32 cinID, u32 a2)
{
	u32 flag;
	u16* REF_flag;
	u32* REF_a2 = &a2;
	u32* data   = (u32*)DEMO_STATUS[cinID].mTimedEvents;
	STACK_PAD_VAR(2);
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
			case DEMOID_CollectFirstPartPractice:
				__Prepare_BGM(DEMOID_ShipUpgradePractice);
				break;
			case DEMOID_Unk24:
				__Prepare_BGM(DEMOID_ShipUpgradeLast);
				break;
			}
		} else if (REF_flag[1] == 0xfffa) {
			if (DEMO_STATUS[cinID].mAudioConfig & 0x80) {
				Jac_StartDemoSound(DEMO_STATUS[cinID].mAudioConfig & 0xf);
			} else {
				demo_bgm_seqp = Jam_GetTrackHandle(0x30000);
				Jam_WritePortAppDirect(demo_bgm_seqp, 0, DEMO_STATUS[cinID].mAudioConfig & 0xf);
				current_seq_bgm = DEMO_STATUS[cinID].mAudioConfig & 0xf;
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

/**
 * @TODO: Documentation
 */
void Jac_PlayDemoSequenceDirect(u32 id)
{
	demo_bgm_seqp = Jam_GetTrackHandle(0x30000);
	Jam_WritePortAppDirect(demo_bgm_seqp, 0, id);
}

/**
 * @TODO: Documentation
 */
void Jac_InitDemoSystem()
{
	demo_seqp = Jam_GetTrackHandle(0x1000f);
	if (demo_seqp) {
		Jal_AddCmdQueue(&demo_q, demo_seqp, 2);
		demo_inited = TRUE;
	}
}

/**
 * @TODO: Documentation
 */
void Jac_StartDemo(u32 cinID)
{
	u32* REF_id        = &cinID;
	DemoStatus* status = &DEMO_STATUS[cinID];
	if (cinID >= DEMOID_CHECK_BGM_CAT) {
		switch (cinID) {
		case DEMOID_Unk80:
		case DEMOID_GenericDayEnd:
		case DEMOID_ChalDayEndLast:
		case DEMOID_GenericLanding:
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
	case DEMOID_TakeOffPractice:
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
	case DEMOID_CollectPartPractice:
		if (parts_bright_table[demo_parts_id] == 0) {
			status = &DEMO_STATUS[DEMOID_ShipUpgradeNonSparkling];
			cinID  = DEMOID_ShipUpgradeNonSparkling;
		}
		break;

	case DEMOID_ChalDayEndPractice:
	case DEMOID_ChalDayEndForest:
	case DEMOID_ChalDayEndCave:
	case DEMOID_ChalDayEndYakushima:
	case DEMOID_ChalDayEndLast:
		if (Jac_TellChgMode()) {
			status = &DEMO_STATUS[DEMOID_GenericDayEndChal];
			cinID  = DEMOID_GenericDayEndChal;
		}
		break;

	case DEMOID_LandingPractice:
	case DEMOID_LandingForest:
	case DEMOID_LandingCaveLast:
	case DEMOID_LandingYakushima:
	case DEMOID_GenericLanding:
		if (demo_onyon_num == 3) {
			status = &DEMO_STATUS[DEMOID_Unk100];
			cinID  = DEMOID_Unk100;
		}
		break;

	case DEMOID_DayEndPractice:
	case DEMOID_DayEndForest:
	case DEMOID_DayEndCaveLast:
	case DEMOID_DayEndYakushima:
	case DEMOID_GenericDayEnd:
		Jac_PlayOrimaSe(JACORIMA_PikiHit);
		Jac_Delete_CurrentBgmWave();
		break;
	}

	if (status->mPlayStartSound) {
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

	switch (status->mBgmFadeMode) {
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

	switch (status->mGameplayFlags) {
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

	if (cinID == DEMOID_CollectFirstPartPractice) {
		now_loading = 1;
		__Prepare_BGM(DEMOID_ShipUpgradePractice);
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

	s32 flag = status->mAudioConfig & 0x7f;
	if (flag != 0x40 && (flag >= 0x40 || flag != 0)) {
		if (status->mAudioConfig & 0x80) {
			if (status->mTimedEvents == NULL) {
				Jac_StartDemoSound(status->mAudioConfig & 0xf);
			}
		} else {
			if (status->mAudioConfig & 0xf && status->mTimedEvents == NULL) {
				demo_bgm_seqp = Jam_GetTrackHandle(0x30000);
				Jam_WritePortAppDirect(demo_bgm_seqp, 0, status->mAudioConfig & 0xf);
				current_seq_bgm = status->mAudioConfig & 0xf;
			}
		}
	}

	demo_mml_active = -1;
	demo_seq_active = 0;

	switch (status->mSequenceFlags) {
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

	STACK_PAD_VAR(14);
}

/**
 * @TODO: Documentation
 */
void Jac_DemoSound(int id)
{
	STACK_PAD_VAR(1);
	int* REF_id;

	if (current_demo_no != DEMOID_FINISHED) {
		REF_id = &id;
		Jal_SendCmdQueue_Noblock(&demo_q, id);
	}
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void Jac_BgmAnimEndRecover()
{
	DemoStatus* status = &DEMO_STATUS[current_demo_no];
	switch (status->mBgmFadeMode) {
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

/**
 * @TODO: Documentation
 */
void Jac_BgmAnimEndStop()
{
	DemoStatus* status = &DEMO_STATUS[current_demo_no];
	int flag           = status->mAudioConfig;
	if (flag && !(flag & 0x20)) {
		if (flag & 0x80) {
			Jac_StopDemoSound(flag & 0xf);
		} else {
			Jac_DemoBGMForceStop();
		}
	}
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void __Jac_FinishDemo()
{
	STACK_PAD_VAR(2);
	if (current_demo_no == DEMOID_FINISHED) {
		return;
	}

	DemoStatus* status = &DEMO_STATUS[current_demo_no];
	switch (status->mBgmFadeMode) {
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

	switch (status->mGameplayFlags) {
	case 2:
		Jac_Orima_Formation(0, 0);
		break;
	case 1:
		event_pause_counter = 6;
		break;
	case 0:
		break;
	}

	int flag = status->mAudioConfig;
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

/**
 * @TODO: Documentation
 */
void Jac_FinishDemo(void)
{
	int cinID     = current_demo_no;
	int* REF_demo = &cinID;
	STACK_PAD_VAR(1);
	Jac_SetProcessStatus(6);
	__Jac_FinishDemo();

	if (cinID >= 0) {
		switch (cinID) {
		// these all require a demo to be loaded after them
		case DEMOID_OpeningIntroPt1:
		case DEMOID_ShipUpgradePractice:
		case DEMOID_CollectFirstPartPractice:
		case DEMOID_Unk24: // collect final ship part?
			break;

		case DEMOID_GenericDayEnd:
		case DEMOID_DayEndPractice:
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

/**
 * @TODO: Documentation
 */
void Jac_FinishDemo_NoErase()
{
	__Jac_FinishDemo();
}

/**
 * @TODO: Documentation
 */
void __Loaded(u32 a)
{
	if ((int)(a & 0xFFFF0000) < -0x7fffffff) {
		now_loading = 3;
	}
}

/**
 * @TODO: Documentation
 */
void __Prepare_BGM(u32 cinID)
{
	int set;
	u8 flag;
	DemoStatus* status = &DEMO_STATUS[cinID];

	if (cinID >= DEMOID_CHECK_BGM_CAT) {
		switch (cinID) {
		case DEMOID_Unk80:
		case DEMOID_GenericDayEnd:
		case DEMOID_ChalDayEndLast:
		case DEMOID_GenericLanding:
		case DEMOID_Unk90:
		case DEMOID_Unk91:
		case DEMOID_Unk92:
		case DEMOID_Unk93:
		case DEMOID_Unk94:
		case DEMOID_Unk100:
		case DEMOID_ShipUpgradeNonSparkling:
		case DEMOID_GenericDayEndChal:
		case DEMOID_GoodEndingTakeOff:
		case DEMOID_NeutralEndingLeaveOK:
			break;

		default:
			return;
		}
	}

	switch (cinID) {
	// no BGM for take off cutscenes
	case DEMOID_TakeOffPractice:
	case DEMOID_TakeOffForest:
	case DEMOID_TakeOffCaveLast:
	case DEMOID_TakeOffYakushima:
		return;
	}

	flag = status->mAudioConfig;
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

/**
 * @TODO: Documentation
 */
void Jac_PrepareDemo(u32 cinID)
{
	STACK_PAD_VAR(1);
	u32* REF_id = &cinID;
	if (cinID >= DEMOID_CHECK_BGM_CAT) {
		switch (cinID) {
		case DEMOID_Unk80:
		case DEMOID_GenericDayEnd:
		case DEMOID_ChalDayEndLast:
		case DEMOID_GenericLanding:
		case DEMOID_Unk90:
		case DEMOID_Unk91:
		case DEMOID_Unk92:
		case DEMOID_Unk93:
		case DEMOID_Unk94:
		case DEMOID_Unk100:
		case DEMOID_ShipUpgradeNonSparkling:
		case DEMOID_GenericDayEndChal:
		case DEMOID_GoodEndingTakeOff:
		case DEMOID_NeutralEndingLeaveOK:
			break;

		default:
			return;
		}
	}

	switch (cinID) {
	case DEMOID_TakeOffPractice:
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

/**
 * @TODO: Documentation
 */
void Jac_StartPartsFindDemo(u32 jingleType, BOOL hasAudio)
{
	STACK_PAD_VAR(2);
	u32* REF_p1;

	// we're already playing a part-related screen/cutscene!
	if (parts_find_demo_state == 1) {
		if (hasAudio) {
			Jac_PlaySystemSe(JACSYS_Unk30);
		}
		return;
	}

	event_pause_counter = 0;
	Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);
	Jac_Orima_Formation(0, 0);
	Jac_PauseOrimaSe();

	if (hasAudio) {
		Jac_DemoFade(1, 15, 0.1f);

		REF_p1 = &jingleType;
		if (jingleType == 0) {
			// captain accessing the ship jingle
			Jac_PlaySystemSe(JACSYS_Unk36);
		} else {
			// part discovery jingle
			Jac_PlaySystemSe(JACSYS_Unk30);
		}
	} else {
		// short "pling" sound
		Jac_DemoFade(1, 0x1e, 0.5f);
		Jac_PlaySystemSe(JACSYS_Unk31);
	}
	parts_find_demo_state = 1;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void Jac_StartTextDemo(int textID)
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void Jac_SetDemoPartsID(int id)
{
	int* REF_id;

	REF_id        = &id;
	demo_parts_id = id;
}

/**
 * @TODO: Documentation
 */
void Jac_SetDemoOnyons(int num)
{
	int* REF_num;

	REF_num        = &num;
	demo_onyon_num = num;
}

/**
 * @TODO: Documentation
 */
void Jac_SetDemoPartsCount(int count)
{
	int* REF_count;

	REF_count      = &count;
	demo_parts_num = count;
}
