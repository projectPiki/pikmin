#include "SoundMgr.h"
#include "Boss.h"
#include "Font.h"
#include "sysNew.h"
#include "NaviMgr.h"
#include "gameflow.h"
#include "Graphics.h"
#include "jaudio/verysimple.h"
#include "jaudio/PikiInter.h"
#include "jaudio/PikiBgm.h"
#include "jaudio/PikiPlayer.h"
#include "DebugLog.h"

SeSystem* seSystem;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("soundMgr")

// struct SeInfo would make sense here, but its size is 0x8, this has more values
struct SoundTableInfo {
	int mSeID;      // _00
	int mJacID;     // _04
	char* mSeName;  // _08
	int mLoopType;  // _0C
	int mEventType; // _10
};

SoundTableInfo soundTable[] = {
	// TEKI AND BOSS SOUNDS
	{ 0, 0, "SE_BATTLE_START", 1, 1 },
	{ 1, 1, "SE_CHAPPY_WALK", 0, 1 },
	{ 2, 2, "SE_CHAPPY_DIE", 0, 1 },
	{ 3, 3, "SE_CHAPPY_SWING", 0, 1 },
	{ 4, 4, "SE_CHAPPY_SLEEP", 0, 1 },
	{ 5, 5, "SE_CHAPPY_BITE", 0, 1 },
	{ 6, 6, "SE_CHAPPY_EAT", 0, 1 },
	{ 7, 7, "SE_CHAPPY_DOWN", 0, 1 },
	{ 8, 8, "SE_CHAPPY_FOOTDAMAGE", 0, 1 },
	{ 9, 9, "SE_CHAPPY_BITE2", 0, 1 },
	{ 10, 10, "SE_FLOG_WALK", 0, 1 },
	{ 11, 11, "SE_FLOG_DIE", 0, 1 },
	{ 12, 12, "SE_FLOG_FALL", 0, 1 },
	{ 13, 13, "SE_FLOG_HIJUMP", 0, 1 },
	{ 14, 14, "SE_FLOG_JUMP", 0, 1 },
	{ 15, 15, "SE_FLOG_DOWN", 0, 1 },
	{ 16, 16, "SE_FLOG_LAND", 0, 1 },
	{ 17, 17, "SE_FLOG_VOICE", 0, 1 },
	{ 18, 18, "SE_FLOG_ATTACK", 0, 1 },
	{ 19, 19, "SE_FLOG_EAT", 0, 1 },
	{ 20, 20, "SE_FLOG_WATERJUMP", 0, 1 },
	{ 21, 21, "SE_FLOG_WATERLAND", 0, 1 },
	{ 22, 22, "SE_PIKI_EATEN", 0, 1 },
	{ 23, 23, "SE_PIKI_ATTACK_VOICE", 0, 1 },
	{ 24, 24, "SE_MISSHIT", 0, 1 },
	{ 25, 25, "SE_PIKI_ATTACK_HIT", 0, 1 },
	{ 26, 26, "SE_PIKI_DAMAGED", 0, 1 },
	{ 27, 27, "SE_PIKI_PRESSED", 0, 1 },
	{ 28, 30, "SE_WALL_HIT", 0, 1 },
	{ 29, 46, "SE_SOFTWALL_HIT", 0, 1 },
	{ 30, 47, "SE_WALL_DOWN", 0, 1 },
	{ 31, 31, "SE_BOMB", 0, 1 },
	{ 32, 32, "SE_MINIC_WALK", 0, 1 },
	{ 33, 33, "SE_MINIC_FOOTDAMAGE", 0, 1 },
	{ 34, 34, "SE_MINIC_DIE", 0, 1 },
	{ 35, 35, "SE_MINIC_SWING", 0, 1 },
	{ 36, 36, "SE_MINIC_BITE", 0, 1 },
	{ 37, 37, "SE_MINIC_EAT", 0, 1 },
	{ 38, 38, "SE_MINIC_DOWN", 0, 1 },
	{ 39, 39, "SE_MINIC_ALERT", 0, 1 },
	{ 40, 53, "SE_SNAKE_APPEAR", 0, 1 },
	{ 41, 48, "SE_SPIDER_WALK", 0, 1 },
	{ 42, 49, "SE_SPIDER_LAND", 0, 1 },
	{ 43, 50, "SE_SPIDER_SWING", 0, 1 },
	{ 44, 51, "SE_SPIDER_DEAD", 0, 1 },
	{ 45, 52, "SE_SPIDER_BOMB", 0, 1 },
	{ 46, 41, "SE_FLOWER_DOWN", 0, 1 },
	{ 47, 42, "SE_FLOWER_CONVULSION", 0, 1 },
	{ 48, 43, "SE_FLOWER_GROW0", 0, 1 },
	{ 49, 44, "SE_FLOWER_GROW1", 0, 1 },
	{ 50, 45, "SE_FLOWER_GROW2", 0, 1 },
	{ 51, 28, "SE_PIKI_DEAD", 0, 1 },
	{ 52, 54, "SE_SNAKE_DIG", 0, 1 },
	{ 53, 55, "SE_SNAKE_SHOUT", 0, 1 },
	{ 54, 56, "SE_SNAKE_EAT", 0, 1 },
	{ 55, 57, "SE_SNAKE_DRINK", 0, 1 },
	{ 56, 58, "SE_SNAKE_TURN", 0, 1 },
	{ 57, 59, "SE_SNAKE_MOGAKU", 0, 1 },
	{ 58, 60, "SE_SNAKE_DEAD1", 0, 1 },
	{ 59, 61, "SE_SNAKE_DEAD2", 0, 1 },
	{ 60, 62, "SE_TANK_FIRE", 0, 1 },
	{ 61, 63, "SE_TANK_BREATH", 0, 1 },
	{ 62, 64, "SE_TANK_WALK", 0, 1 },
	{ 63, 65, "SE_TANK_SWING", 0, 1 },
	{ 64, 66, "SE_TANK_DAMAGE", 0, 1 },
	{ 65, 67, "SE_TANK_DEAD1", 0, 1 },
	{ 66, 68, "SE_TANK_DEAD2", 0, 1 },
	{ 67, 69, "SE_MUSH_WALK", 0, 1 },
	{ 68, 70, "SE_MUSH_FLIP", 0, 1 },
	{ 69, 71, "SE_MUSH_TUMBLE", 0, 1 },
	{ 70, 72, "SE_MUSH_GETUP", 0, 1 },
	{ 71, 73, "SE_MUSH_LAND", 0, 1 },
	{ 72, 74, "SE_MUSH_TAME", 0, 1 },
	{ 73, 75, "SE_MUSH_SPORE", 0, 1 },
	{ 74, 76, "SE_MUSH_DAMAGE", 0, 1 },
	{ 75, 77, "SE_MUSH_DEAD1", 0, 1 },
	{ 76, 78, "SE_MUSH_DEAD2", 0, 1 },
	{ 77, 79, "SE_KING_WALK", 0, 1 },
	{ 78, 80, "SE_KING_READY", 0, 1 },
	{ 79, 81, "SE_KING_BERO1", 0, 1 },
	{ 80, 82, "SE_KING_BERO2", 0, 1 },
	{ 81, 83, "SE_KING_GEPPU", 0, 1 },
	{ 82, 84, "SE_KING_DRINK", 0, 1 },
	{ 83, 85, "SE_KING_EAT", 0, 1 },
	{ 84, 86, "SE_KING_CHEEK", 0, 1 },
	{ 85, 87, "SE_KING_NAME", 0, 1 },
	{ 86, 88, "SE_KING_HIP", 0, 1 },
	{ 87, 89, "SE_KING_DEAD1", 0, 1 },
	{ 88, 90, "SE_KING_DEAD2", 0, 1 },
	{ 89, 91, "SE_KING_APPEAR", 0, 1 },
	{ 90, 92, "SE_KING_SINK", 0, 1 },
	{ 91, 93, "SE_KABUTO_BREATH", 0, 1 },
	{ 92, 94, "SE_KABUTO_TUMARI", 0, 1 },
	{ 93, 95, "SE_KABUTO_OPEN", 0, 1 },
	{ 94, 96, "SE_KABUTO_SHOT", 0, 1 },
	{ 95, 97, "SE_KABUTO_FLIP", 0, 1 },
	{ 96, 98, "SE_KABUTO_WALK", 0, 1 },
	{ 97, 99, "SE_KABUTO_COOLDOWN", 0, 1 },
	{ 98, 100, "SE_KABUTO_OVERHEAT", 0, 1 },
	{ 99, 101, "SE_KABUTO_DEAD", 0, 1 },
	{ 100, 102, "SE_ROCK_ROLL", 0, 1 },
	{ 101, 103, "SE_ROCK_BREAK", 0, 1 },
	{ 102, 104, "SE_ROCK_GENERATOR", 0, 1 },
	{ 103, 105, "SE_SHELL_CLOSE", 0, 1 },
	{ 104, 106, "SE_SHELL_READY", 0, 1 },
	{ 105, 107, "SE_SHELL_TRESURE", 0, 1 },
	{ 106, 108, "SE_SHELL_OPEN", 0, 1 },
	{ 107, 109, "SE_SHELL_EAT", 0, 1 },
	{ 108, 110, "SE_KINOKOPIKI_MORPH", 0, 1 },
	{ 109, 111, "SE_KINOKOPIKI_DANCE", 0, 1 },
	{ 110, 112, "SE_COLLEC_BREATH", 0, 1 },
	{ 111, 113, "SE_COLLEC_PULL", 0, 1 },
	{ 112, 114, "SE_COLLEC_WALK", 0, 1 },
	{ 113, 115, "SE_COLLEC_SWING", 0, 1 },
	{ 114, 116, "SE_COLLEC_DEAD", 0, 1 },
	{ 115, 117, "SE_COLLEC_DOWN", 0, 1 },
	{ 116, 118, "SE_COLLEC_CRY", 0, 1 },
	{ 117, 119, "SE_COLLEC_DAMAGE", 0, 1 },
	{ 118, 120, "SE_KOGANE_WALK", 0, 1 },
	{ 119, 121, "SE_KOGANE_DAMAGE", 0, 1 },
	{ 120, 122, "SE_SARAI_HOVER", 0, 1 },
	{ 121, 123, "SE_SARAI_DAMAGE", 0, 1 },
	{ 122, 124, "SE_SARAI_ATTACK", 0, 1 },
	{ 123, 125, "SE_SARAI_DEAD", 0, 1 },
	{ 124, 126, "SE_WALLEAT_WALK", 0, 1 },
	{ 125, 127, "SE_WALLEAT_NIP", 0, 1 },
	{ 126, 128, "SE_WALLEAT_EAT", 0, 1 },
	{ 127, 129, "SE_WALLEAT_APPEAR", 0, 1 },
	{ 128, 130, "SE_MAR_FLY", 0, 1 },
	{ 129, 131, "SE_MAR_BREATH", 0, 1 },
	{ 130, 132, "SE_MAR_WIND", 0, 1 },
	{ 131, 133, "SE_MAR_DROP", 0, 1 },
	{ 132, 134, "SE_MAR_DEAD1", 0, 1 },
	{ 133, 135, "SE_MAR_DEAD2", 0, 1 },
	{ 134, 136, "SE_MIURIN_WALK", 0, 1 },
	{ 135, 137, "SE_MIURIN_PUNCH", 0, 1 },
	{ 136, 138, "SE_MIURIN_SING", 0, 1 },
	{ 137, 139, "SE_KURIONE_HIT", 0, 1 },
	{ 138, 140, "SE_KURIONE_ESCAPE", 0, 1 },
	{ 139, 141, "SE_KURIONE_WATER", 0, 1 },
	{ 140, 142, "SE_KURIONE_FLYING", 0, 1 },
	{ 141, 143, "SE_SLIME_WALK", 0, 1 },
	{ 142, 144, "SE_SLIME_HIT_SMALL", 0, 1 },
	{ 143, 145, "SE_SLIME_HIT_MID", 0, 1 },
	{ 144, 146, "SE_SLIME_HIT_LARGE", 0, 1 },
	{ 145, 147, "SE_SLIME_DEAD", 0, 1 },
	{ 146, 148, "SE_SLIME_EXT1", 0, 1 },
	{ 147, 149, "SE_SLIME_EXT2", 0, 1 },
	{ 148, 150, "SE_SLIME_EXT3", 0, 1 },
	{ 149, 151, "SE_SLIME_DISAPPEAR", 0, 1 },
	{ 150, 152, "SE_DORORO_WALK", 0, 1 },
	{ 151, 153, "SE_DORORO_CRY", 0, 1 },
	{ 152, 154, "SE_DORORO_DEAD", 0, 1 },
	{ 153, 155, "SE_DORORO_SWING", 0, 1 },
	{ 154, 156, "SE_DORORO_EGG_CRASH", 0, 1 },
	{ 155, 157, "SE_DORORO_CRASH", 0, 1 },
	{ 156, 158, "SE_PONGASHI_THROWIN", 0, 1 },
	{ 157, 159, "SE_PONGASHI_CLOSE", 0, 1 },
	{ 158, 160, "SE_PONGASHI_EAT", 0, 1 },
	{ 159, 161, "SE_PONGASHI_SHOT", 0, 1 },
	{ 160, 162, "SE_PONGASHI_DEAD", 0, 1 },
	{ 161, 163, "SE_PONGASHI_TOUCH", 0, 1 },
	{ 162, 164, "SE_NAMAZU_WALK", 0, 1 },
	{ 163, 165, "SE_NAMAZU_EAT", 0, 1 },
	{ 164, 166, "SE_NAMAZU_DEAD", 0, 1 },
	{ 165, 167, "SE_OTAMA_JUMP", 0, 1 },
	{ 166, 168, "SE_OTAMA_DEAD", 0, 1 },
	{ 167, 169, "SE_OTAMA_WATERJUMP", 0, 1 },
	{ 168, 170, "SE_GEYSER_NORMAL", 0, 1 },
	{ 169, 171, "SE_GEYSER_SPOUT", 0, 1 },

	// WORK OBJECT SOUNDS
	{ 170, 0, "SEB_SOFTWALL_HIT", 0, 4 },
	{ 171, 1, "SEB_WALL_DOWN", 0, 4 },
	{ 172, 2, "SEB_HARDESTWALL_HIT", 0, 4 },
	{ 173, 3, "SEB_CONSTRUCTION", 0, 4 },
	{ 174, 4, "SEB_BOXMOVE", 0, 4 },
	{ 175, 5, "SEB_HARDWALL_HIT", 0, 4 },
	{ 176, 6, "SEB_STONE_HIT", 0, 4 },
	{ 177, 7, "SEB_STONE_BREAK", 0, 4 },
	{ 178, 8, "SEB_GRASS_PULL", 0, 4 },
	{ 179, 9, "SEB_BRIDGE_EXTEND", 0, 4 },

	// SOME PIKI SOUNDS
	{ 180, 0, "SEW_PIKI_WATERDROP", 0, 5 },
	{ 181, 1, "SEW_PIKI_DROWN", 0, 5 },
	{ 182, 2, "SEW_PIKI_DEAD", 0, 5 },
	{ 183, 3, "SEW_PIKI_SINK", 0, 5 },

	// SHIP PART SOUNDS
	{ 184, 0, "SE_LIFT_TRY", 1, 2 },
	{ 185, 1, "SE_LIFT_MOVE", 1, 2 },
	{ 186, 2, "SE_PIKI_LIFT", 1, 2 },
	{ 187, 3, "SE_PELLET_BORN", 0, 2 },
	{ 188, 4, "SE_PELLET_BOUND", 0, 2 },
	{ 189, 5, "SE_UFOPARTS_BOUND", 0, 2 },
	{ 190, 6, "SE_UFOPARTS_OTHER", 1, 2 },
	{ 191, 7, "SE_UFOPARTS_ENGINE", 1, 2 },
	{ 192, 8, "SE_UFOPARTS_GEAR", 1, 2 },
	{ 193, 9, "SE_UFOPARTS_RADER", 1, 2 },
	{ 194, 10, "SE_UFOPARTS_SPRING", 1, 2 },
	{ 195, 11, "SE_UFOPARTS_BATTERY", 1, 2 },
	{ 196, 12, "SE_UFOPARTS_ZENMAI", 1, 2 },
	{ 197, 13, "SE_UFOPARTS_MONEYBOX", 1, 2 },

	{ 198, 7, "dummy 1", 1, 2 },
	{ 199, 7, "dummy 2", 1, 2 },
	{ 200, 7, "dummy 3", 1, 2 },
	{ 201, 7, "dummy 4", 1, 2 },
	{ 202, 7, "dummy 5", 1, 2 },

	// ONION SOUNDS
	{ 203, 0, "SE_CONTAINER_PELLETIN", 0, 3 },
	{ 204, 1, "SE_CONTAINER_PIKIBORN", 0, 3 },
	{ 205, 2, "SE_PIKI_GROW1", 0, 3 },
	{ 206, 3, "SE_PIKI_GROW2", 0, 3 },
	{ 207, 4, "SE_PIKI_GROW3", 0, 3 },
	{ 208, 5, "SE_PIKI_GROW4", 0, 3 },
	{ 209, 6, "SE_PIKI_GROW5", 0, 3 },
	{ 210, 7, "SE_PIKI_GOHOME", 0, 3 },
	{ 211, 8, "SE_PIKI_OUTHOME", 0, 3 },
	{ 212, 9, "SE_PIKI_GROW0", 0, 3 },
	{ 213, 10, "SE_PIKI_GROW0_WATER", 0, 3 },
	{ 214, 11, "SE_CONTAINER_PELLETIN2", 0, 3 },
	{ 215, 12, "SE_CONTAINER_PIKI", 0, 3 },
	{ 216, 13, "SE_CONTAINER_HANABI", 0, 3 },
	{ 217, 14, "SE_CONTAINER_CLIMB", 0, 3 },

	// UFO SOUNDS
	{ 218, 0, "SE_UFO_PARTSIN", 0, 7 },
	{ 219, 1, "SE_UFO_PARTSSET1", 0, 7 },
	{ 220, 2, "SE_UFO_PARTSSET2", 0, 7 },
	{ 221, 3, "SE_UFO_PARTSSET3", 0, 7 },
	{ 222, 4, "SE_UFO_IDLING", 0, 7 },
	{ 223, 5, "SE_UFO_SPARK", 0, 7 },
	{ 224, 6, "SE_UFO_DESTROY", 1, 7 },
	{ 225, 7, "SE_UFO_SATELLITE", 1, 7 },
	{ 226, 8, "SE_UFO_LIGHT", 1, 7 },
	{ 227, 9, "SE_UFO_ANTENNA", 1, 7 },
	{ 228, 10, "SE_UFO_RADER", 1, 7 },
	{ 229, 11, "SE_UFO_LIGHT2", 1, 7 },
	{ 230, 12, "SE_UFO_ENGINE", 1, 7 },

	// PIKI SOUNDS
	{ 231, 0, "SEF_PIKI_KINOKO2", 0, 6 },
	{ 232, 1, "SEF_PIKI_AKUBI", 0, 6 },
	{ 233, 2, "SEF_PIKI_BURUBURU", 0, 6 },
	{ 234, 3, "SEF_PIKI_CRASH", 0, 6 },
	{ 235, 4, "SEF_PIKI_DEAD1", 0, 6 },
	{ 236, 5, "SEF_PIKI_DEAD2", 0, 6 },
	{ 237, 6, "SEF_PIKI_DEAD3", 0, 6 },
	{ 238, 7, "SEF_PIKI_FALL", 0, 6 },
	{ 239, 8, "SEF_PIKI_GAKKARI", 0, 6 },
	{ 240, 9, "SEF_PIKI_HANG", 0, 6 },
	{ 241, 10, "SEF_PIKI_JUMP1", 0, 6 },
	{ 242, 11, "SEF_PIKI_JUMP2", 0, 6 },
	{ 243, 12, "SEF_PIKI_JUMP3", 0, 6 },
	{ 244, 13, "SEF_PIKI_SNEEZE", 0, 6 },
	{ 245, 14, "SEF_PIKI_SLEEP", 0, 6 },
	{ 246, 15, "SEF_PIKI_NOBI", 0, 6 },
	{ 247, 16, "SEF_PIKI_ANGRY1", 0, 6 },
	{ 248, 17, "SEF_PIKI_ANGRY2", 0, 6 },
	{ 249, 18, "SEF_PIKI_OTTOTTO", 0, 6 },
	{ 250, 19, "SEF_PIKI_SKIP", 0, 6 },
	{ 251, 20, "SEF_PIKI_SLIP1", 0, 6 },
	{ 252, 21, "SEF_PIKI_SLIP2", 0, 6 },
	{ 253, 22, "SEF_PIKI_LAND", 0, 6 },
	{ 254, 23, "SEF_PIKI_YATTA", 0, 6 },
	{ 255, 24, "SEF_PIKI_BREAKUP", 0, 6 },
	{ 256, 25, "SEF_PIKI_CALLED", 0, 6 },
	{ 257, 26, "SEF_PIKI_FIND", 0, 6 },
	{ 258, 27, "SEF_PIKI_FIRED", 0, 6 },
	{ 259, 28, "SEF_PIKI_DRINK", 0, 6 },
	{ 260, 29, "SEF_PIKI_WATERED", 0, 6 },
	{ 261, 31, "SEF_PIKI_ATTACK_VOICE", 0, 6 },
	{ 262, 32, "SEF_PIKI_MISSHIT", 0, 6 },
	{ 263, 33, "SEF_PIKI_ATTACK_HIT", 0, 6 },
	{ 264, 34, "SEF_PIKI_DAMAGED", 0, 6 },
	{ 265, 35, "SEF_PIKI_GROW1", 0, 6 },
	{ 266, 36, "SEF_PIKI_GROW2", 0, 6 },
	{ 267, 37, "SEF_PIKI_GROW3", 0, 6 },
	{ 268, 30, "SEF_PIKI_GROW4", 0, 6 },
	{ 269, 38, "SEF_PIKI_GROW5", 0, 6 },
	{ 270, 39, "SEF_PIKI_GROW0", 0, 6 },
	{ 271, 40, "SEF_PIKI_GROW0_WATER", 0, 6 },

	// SYSTEM SOUNDS
	{ 272, 0, "SYSSE_ALLSTOP", 0, -2 },
	{ 273, 1, "SYSSE_DECIDE1", 0, -2 },
	{ 274, 2, "SYSSE_MOVE1", 0, -2 },
	{ 275, 3, "SYSSE_PAUSE", 0, -2 },
	{ 276, 4, "SYSSE_EVENING_ALERT", 0, -2 },
	{ 277, 5, "SYSSE_COUNTDOWN", 0, -2 },
	{ 278, 6, "SYSSE_CMENU_ON", 0, -2 },
	{ 279, 7, "SYSSE_CMENU_OFF", 0, -2 },
	{ 280, 8, "SYSSE_CMENU_SELECT", 0, -2 },
	{ 281, 9, "SYSSE_CMENU_ERROR", 0, -2 },
	{ 282, 10, "SYSSE_ORIMA_LIFEDIM", 0, -2 },
	{ 283, 11, "SYSSE_WORK_FINISH", 0, -2 },
	{ 284, 12, "SYSSE_VIEW_CHANGE", 0, -2 },
	{ 285, 13, "SYSSE_CANCEL", 0, -2 },
	{ 286, 14, "SYSSE_TYPEWRITER", 0, -2 },
	{ 287, 15, "SYSSE_UNPAUSE", 0, -2 },
	{ 288, 16, "SYSSE_CONTAINER_OK", 0, -2 },
	{ 289, 17, "SYSSE_JUNGLE", 0, -2 },
	{ 290, 18, "SYSSE_PARTS_APPEAR", 0, -2 },
	{ 291, 19, "SYSSE_SELECT_MOVE", 0, -2 },
	{ 292, 20, "SYSSE_SELECT_DECIDE", 0, -2 },
	{ 293, 21, "SYSSE_TIME_SIGNAL", 0, -2 },
	{ 294, 22, "SYSSE_SELECT_COURSEOPEN", 0, -2 },
	{ 295, 23, "SYSSE_MESSAGE_CLOSE", 0, -2 },
	{ 296, 26, "SYSSE_CARDACCESS", 0, -2 },
	{ 297, 27, "SYSSE_CARDOK", 0, -2 },
	{ 298, 28, "SYSSE_CARDERROR", 0, -2 },
	{ 299, 29, "SYSSE_TIME_SMALLSIGNAL", 0, -2 },
	{ 300, 32, "SYSSE_CHG_HISCORE", 0, -2 },
	{ 301, 6, "YMENU ON", 0, -2 },
	{ 302, 7, "YMENU OFF", 0, -2 },
	{ 303, 8, "YMENU SELECT", 0, -2 },
	{ 304, 33, "SYSSE_YMENU_ZOOMIN", 0, -2 },
	{ 305, 34, "SYSSE_YMENU_ZOOMOUT", 0, -2 },
	{ 306, 35, "SYSSE_YMENU_SCROLL", 0, -2 },
	{ 307, 37, "Sound Config", 0, -2 },
	{ 308, 23, "YMENU SELECT", 0, -2 },

	// PLAYER sounds
	{ 309, 2, "SE_ORIMA_TOUCHPLANTS", 0, -1 },
	{ 310, 3, "SE_PIKI_PULLING", 0, -1 },
	{ 311, 4, "SE_PIKI_PULLED2", 0, -1 },
	{ 312, 5, "SE_PLAYER_PUNCH", 0, -1 },
	{ 313, 6, "SE_THROW", 0, -1 },
	{ 314, 7, "SE_BREAKUP", 0, -1 },
	{ 315, 8, "SE_GATHER", 0, -1 },
	{ 316, 9, "SE_MOVEOBJ", 0, -1 },
	{ 317, 10, "SE_DAMAGED", 0, -1 },
	{ 318, 11, "SE_FIRED", 0, -1 },
	{ 319, 12, "SE_PLAYER_DOWN", 0, -1 },
	{ 320, 13, "SE_PLAYER_TOUCHHONEY", 0, -1 },

	// MISC PIKI SOUNDS?
	{ 321, 0x8001, "SE_THROWHIT", 0, -1 },
	{ 322, 0x8002, "SE_PIKI_FLY", 0, -1 },
	{ 323, 0x8003, "SE_BREAKUP_PIKI_VOICE", 0, -1 },
	{ 324, 0x8004, "SE_PIKI_FLYREADY", 0, -1 },
	{ 325, 0x8005, "SE_PIKI_CALLED", 0, -1 },
	{ 326, 0x8006, "SE_PIKI_FIND", 0, -1 },
	{ 327, 0x8007, "SE_PIKI_PULLED", 0, -1 },
	{ 328, 0x8008, "SE_PIKI_WATERDROP", 0, -1 },
	{ 329, 0x8009, "SE_PIKI_ATTACHENEMY", 0, -1 },
	{ 330, 0x800a, "SE_KINOKOPIKI_ATTACK", 0, -1 },
};

/*
 * --INFO--
 * Address:	800A3C5C
 * Size:	000070
 */
SeContext::SeContext()
{
	mEventHandle = -1;
	mGameObj     = nullptr;
	mEventType   = -1;
	mCameraPosition.set(0.0f, 0.0f, 0.0f);
	mPosition.set(0.0f, 0.0f, 0.0f);
	mClock = 0;
}

/*
 * --INFO--
 * Address:	800A3CCC
 * Size:	000068
 */
SeContext::SeContext(Creature* obj, int type)
{
	mEventHandle = -1;
	mGameObj     = obj;
	mEventType   = type;
	mCameraPosition.set(0.0f, 0.0f, 0.0f);
	mPosition.set(0.0f, 0.0f, 0.0f);
	mClock = 0;
}

/*
 * --INFO--
 * Address:	800A3D34
 * Size:	00009C
 */
void SeContext::setContext(Creature* obj, int type)
{
	if (mEventHandle != -1) {
		PRINT("*** context%x setContext :: releaseEvent !\n", this);
		releaseEvent();
	}

	mEventHandle = -1;
	mGameObj     = obj;
	mEventType   = type;
	mCameraPosition.set(0.0f, 0.0f, 0.0f);
	mPosition.set(0.0f, 0.0f, 0.0f);
	mClock = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
Vector3f SeContext::getPos()
{
	if (mGameObj) {
		return mGameObj->mPosition;
	}
	return mPosition;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
int SeContext::getObjType()
{
	if (mGameObj) {
		return mGameObj->mObjType;
	}
	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void SeContext::createEvent(int a)
{
	mEventType = a;
	seSystem->calcCameraPos(getPos(), mCameraPosition);
	mEventHandle = seSystem->createEvent(this, mEventType, (SVector_*)&mCameraPosition);
}

/*
 * --INFO--
 * Address:	800A3DD0
 * Size:	0000D4
 */
void SeContext::playSound(int id)
{
	int soundID = seSystem->getJacID(id);
	if (mEventHandle == -1) {
		createEvent(mEventType);
	}

	if (mEventHandle != -1) {
		Jac_PlayEventAction(mEventHandle, soundID);
		mClock = seSystem->mClock;
	}
}

/*
 * --INFO--
 * Address:	800A3EA4
 * Size:	000048
 */
void SeContext::stopSound(int id)
{
	int soundID = seSystem->getJacID(id);
	if (mEventHandle != -1) {
		Jac_StopEventAction(mEventHandle, soundID);
	}
}

/*
 * --INFO--
 * Address:	800A3EEC
 * Size:	000094
 */
void SeContext::update()
{
	// this function is empty in the DLL
	if (mEventHandle == -1) {
		return;
	}
	seSystem->calcCameraPos(getPos(), mCameraPosition);
	Jac_UpdateEventPosition(mEventHandle, &mCameraPosition);
}

/*
 * --INFO--
 * Address:	800A3F80
 * Size:	000058
 */
bool SeContext::releaseEvent()
{
	PRINT("releaseEvent : %x : handle = %d\n", this, mEventHandle);

	if (mEventHandle != -1) {
		bool ret = seSystem->destroyEvent(this, mEventHandle);
		PRINT("** destroyEvent %s\n", ret ? "succeeded" : "failed");
		mEventHandle = -1;
		return ret;
	}
	mEventHandle = -1;
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void SeContext::dump()
{
	PRINT("\towner %x(%s) handle %d eventType %d pos( %.1f %.1f %.1f )\n", mGameObj,
	      mGameObj ? ObjType::getName(mGameObj->mObjType) : "<pos>", mEventHandle, mEventType, mCameraPosition.x, mCameraPosition.y,
	      mCameraPosition.z);
}

/*
 * --INFO--
 * Address:	800A3FD8
 * Size:	000120
 */
SeSystem::SeSystem()
{
	mIsClosed            = true;
	mCurrentContextCount = 0;
	mMaxContextCount     = 16;
	mContext             = new SeContext[mMaxContextCount];
	mMaxEventCount       = 16;
	mEvents              = new Event[mMaxEventCount];
	mMaxSoundID          = SE_KINOKOPIKI_ATTACK + 1;
	mMtx.makeIdentity();
	mConstant = new SeConstant;
	gameflow.addGenNode("SE Constatns", mConstant);
	_44 = 700.0f;
	initEvent();
	mBossActive = false;
	mClock      = 0;
}

/*
 * --INFO--
 * Address:	800A410C
 * Size:	000078
 */
void SeSystem::initEvent()
{
	Jac_InitAllEvent();
	mCurrentEventCount = 0;

	for (int i = 0; i < mMaxEventCount; i++) {
		mEvents[i].mHandle  = -1;
		mEvents[i].mContext = nullptr;
	}

	mIsClosed = false;
	mClock    = 0;
}

/*
 * --INFO--
 * Address:	800A4184
 * Size:	000078
 */
void SeSystem::resetSystem()
{
	initEvent();
}

/*
 * --INFO--
 * Address:	800A41FC
 * Size:	00020C
 */
int SeSystem::createEvent(SeContext* context, int eventType, SVector_* a2)
{
	if (mIsClosed) {
		return -1;
	}

	int ret = -1;
	if (mCurrentEventCount < mMaxEventCount) {
		int test = Jac_CreateEvent(eventType, a2);
		if (test == -1) {
			dumpEvents();
			for (int x = 0; x < 10; x++) { }
			ret = -1;
		} else {
			Event* evt = &mEvents[mCurrentEventCount];
			mCurrentEventCount++;
			evt->mHandle  = test;
			evt->mContext = context;
			ret           = test;
		}
	} else {

		int index  = -1;
		f32 length = a2->x * a2->x + a2->y * a2->y + a2->z * a2->z;
		for (int i = 0; i < mMaxEventCount; i++) {
			SeContext* ctx = mEvents[i].mContext;
			if (ctx) {
				f32 cLen = ctx->mCameraPosition.x * ctx->mCameraPosition.x + ctx->mCameraPosition.y * ctx->mCameraPosition.y
				         + ctx->mCameraPosition.z * ctx->mCameraPosition.z;
				if (cLen > length) {
					length = cLen;
					index  = i;
				}
			}
		}

		if (index != -1) {
			bool ev         = mEvents[index].mContext->releaseEvent();
			int eventHandle = Jac_CreateEvent(eventType, a2);
			if (eventHandle == -1 && ev) {
				dumpEvents();
				for (int x = 0; x < 10; x++) { }
			}
			mEvents[mCurrentEventCount].mHandle  = eventHandle;
			mEvents[mCurrentEventCount].mContext = context;
			mCurrentEventCount++;
			context->mEventHandle = eventHandle;
			context->mEventType   = eventType;
			ret                   = eventHandle;
		}
	}

	u32 badCompiler;
	return ret;
}

/*
 * --INFO--
 * Address:	800A4408
 * Size:	00002C
 */
void SeSystem::playPikiSound(int id, Vector3f& pos)
{
	playSoundDirect(6, id, pos);
}

/*
 * --INFO--
 * Address:	800A4434
 * Size:	000394
 */
void SeSystem::playSoundDirect(int type, int sound, Vector3f& pos)
{
	if (mIsClosed) {
		PRINT("seSystem は閉店です!\n");
		ERROR("seSystem closed\n");
	}

	int index   = -1;
	f32 maxDist = 200.0f;

	for (int i = 0; i < mCurrentEventCount; i++) {
		Event* event = &mEvents[i];
		if (event->mContext && event->mContext->mEventType == type) {
			Vector3f diff = event->mContext->getPos() - pos;
			f32 length    = diff.length();
			if (length <= maxDist) {
				index   = i;
				maxDist = length;
			}
		}
	}

	if (index != -1) {
		mEvents[index].mContext->playSound(sound);
		return;
	}

	SeContext& ctx       = mContext[mCurrentContextCount];
	int sysSeContext     = mCurrentContextCount;
	mCurrentContextCount = (mCurrentContextCount + 1) % mMaxContextCount;
	ctx.releaseEvent();
	ctx.setContext(nullptr, type);
	ctx.setPosition(pos);
	ctx.playSound(sound);

	PRINT(" ** [ReUse] sysSeContext %d\n", sysSeContext);
}

/*
 * --INFO--
 * Address:	800A47C8
 * Size:	000108
 */
bool SeSystem::destroyEvent(SeContext* context, s32 handle)
{
	if (mIsClosed) {
		PRINT("destroyEvent\n");
		ERROR("seSystem closed\n");
	}

	int evt = getEvent(context);
	if (evt != -1) {
		PRINT("♪♪♪♪♪♪♪♪ try to erase %d event\n", evt);
		int before = Jac_CheckFreeEvents();
		Jac_DestroyEvent(handle);
		if (before == Jac_CheckFreeEvents()) {
			for (int i = 0; i < 10; i++) { }
		}
		mCurrentEventCount--;
		for (int i = evt; i < mCurrentEventCount; i++) {
			mEvents[i].mHandle  = mEvents[i + 1].mHandle;
			mEvents[i].mContext = mEvents[i + 1].mContext;
		}
		mEvents[mCurrentEventCount].mHandle  = -1;
		mEvents[mCurrentEventCount].mContext = nullptr;
		PRINT("++++destroy success ! handle %d\n", handle);
		PRINT("********************* NUM EVENTS = %d\n", mCurrentEventCount);
		return true;
	}
	PRINT("++++destroy FAILED ! handle %d\n", handle);
	if (handle != -1) {
		PRINT("WHYYYYYYYYYYYYYYYY?????\n");
		ERROR("meck!\n");
	}

	PRINT("---- destroy FAILED no handle\n");
	return false;

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
int SeSystem::getEvent(s32 handle)
{
	int index = 0;
	for (; index < mCurrentEventCount; index++) {
		if (mEvents[index].mContext && mEvents[index].mHandle != -1 && mEvents[index].mHandle == handle) {
			return index;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	800A48D0
 * Size:	000048
 */
int SeSystem::getEvent(SeContext* context)
{
	int index = 0;
	for (; index < mCurrentEventCount; index++) {
		if (mEvents[index].mContext == context) {
			return index;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	800A4918
 * Size:	0001B8
 */
void SeSystem::draw3d(Graphics& gfx)
{
	char str[PATH_MAX];

	gfx.setColour(Colour(255, 0, 0, 255), true);
	gfx.useTexture(nullptr, 0);
	gfx.setLighting(false, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);

	for (int i = 0; i < mMaxEventCount; i++) {
		SeContext* ctx = mEvents[i].mContext;
		if (ctx) {
			Vector3f pos = ctx->getPos();
			pos.y += 50.0f;
			pos.multMatrix(gfx.mCamera->mLookAtMtx);
			sprintf(str, "SE %d", i);
			gfx.perspPrintf(gsys->mConsFont, pos, -(gsys->mConsFont->stringWidth(str) / 2), 0, str);
		}
	}
}

/*
 * --INFO--
 * Address:	800A4AD0
 * Size:	0002D0
 */
void SeSystem::draw2d(Graphics& gfx)
{
	char str[PATH_MAX];

	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.useTexture(nullptr, 0);

	gfx.setColour(Colour(55, 55, 55, 128), true);

	RectArea rect(20, 60, 550, mMaxEventCount * 16 + 120);
	gfx.fillRectangle(rect);

	gfx.setColour(Colour(255, 255, 255, 255), true);

	sprintf(str, "-- se events -- %d/%d (%.1f %.1f %.1f): clock %d", mCurrentEventCount, mMaxEventCount, mPosition.x, mPosition.y,
	        mPosition.z, mClock);
	gfx.texturePrintf(gsys->mConsFont, 30, 70, str);

	int y                = 90;
	const char* names[9] = { "-----", "battle", "pellet", "onyon", "build", "water", "free", "????", "DAME" };
	for (int i = 0; i < mMaxEventCount; i++) {
		if (mEvents[i].mContext) {
			SeContext* ctx = mEvents[i].mContext;
			sprintf(str, "(%d) : %s %d %s (%d)", i, ctx->mGameObj ? ObjType::getName(ctx->mGameObj->mObjType) : "<pos>", ctx->mEventHandle,
			        names[ctx->mEventType], mClock - ctx->mClock);
			gfx.texturePrintf(gsys->mConsFont, 55, y, str);
			y += 16;
		} else {
			sprintf(str, "(%d) : handle %d , seContext = %x", i, mEvents[i].mHandle, mEvents[i].mContext);
			gfx.texturePrintf(gsys->mConsFont, 55, y, str);
			y += 16;
		}
	}
}

/*
 * --INFO--
 * Address:	800A4DA0
 * Size:	0000B8
 */
void SeSystem::dumpEvents()
{
	PRINT("***** SE EVENTS ****** %d / %d \n", mCurrentEventCount, mMaxEventCount);

	for (int i = 0; i < mMaxEventCount; i++) {
		PRINT("\t(%d) : handle %d , seContext = %x\n", i, mEvents[i].mHandle, mEvents[i].mContext);
		if (mEvents[i].mContext) {
			mEvents[i].mContext->dump();
		}
	}

	u8 test[0x80];
	u32 max = Jac_GetActiveEvents(test);
	Jac_CheckFreeEvents();

	// this is, uh...
	u8* ptr = test;
	for (int i = 0; i < max; i++) {
		// probably something like this
		PRINT("%d", *ptr);
		ptr++;
	}
}

/*
 * --INFO--
 * Address:	800A4E58
 * Size:	000368
 */
void SeSystem::update(Graphics& gfx, Vector3f& pos)
{
	if (mIsClosed) {
		PRINT("... seSystem closed\n");
		return;
	}
	mPosition = pos;
	mMtx      = gfx.mCamera->mLookAtMtx;

	Vector3f vec1, vec2;
	Jac_UpdateCamera(&vec1, &vec2);
	for (int i = 0; i < mMaxContextCount; i++) {
		mContext[i].update();
	}

	if (bossMgr && naviMgr && naviMgr->getNavi()) {
		Navi* navi = naviMgr->getNavi();
		Iterator it(bossMgr);
		Boss* nearestBoss = nullptr;
		f32 maxDist       = seSystem->mConstant->mParms._44();
		CI_LOOP(it)
		{
			Boss* boss = (Boss*)*it;
			if (boss->isBossBgm()) {
				f32 dist = qdist2(boss, navi);
				if (dist <= maxDist) {
					nearestBoss = boss;
					maxDist     = dist;
				}
			}
		}

		if (mBossActive) {
			if (!nearestBoss || maxDist >= seSystem->mConstant->mParms._44()) {
				Jac_ExitBossMode();
				mBossActive = false;
			}
		} else {
			if (nearestBoss && maxDist <= seSystem->mConstant->mParms._34()) {
				Jac_EnterBossMode();
				mBossActive = true;
			}
		}
	} else if (mBossActive) {
		Jac_ExitBossMode();
		mBossActive = false;
	}
}

/*
 * --INFO--
 * Address:	800A51C8
 * Size:	0000FC
 */
void SeSystem::calcCameraPos(Vector3f& in, Vector3f& out)
{
	Vector3f a = in;
	Vector3f b = mPosition;
	a.multMatrix(mMtx);
	b.multMatrix(mMtx);
	a   = a - b;
	a   = a * (1.0f / seSystem->mConstant->mParms._24());
	out = a;
}

/*
 * --INFO--
 * Address:	800A52C4
 * Size:	000018
 */
int SeSystem::getJacID(int index)
{
	if (index < 0 || index > mMaxSoundID) {
		PRINT("soundID = %d\n", index);
		ERROR("go to HELL!\n"); // rude...
	}
	return soundTable[index].mJacID;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
char* SeSystem::getSoundName(int index)
{
	if (index < 0 || index > mMaxSoundID) {
		PRINT("soundID = %d\n", index);
		ERROR("go to HELL!\n");
	}
	return soundTable[index].mSeName;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
int SeSystem::getEventType(int index)
{
	if (index < 0 || index > mMaxSoundID) {
		PRINT("soundID = %d\n", index);
		ERROR("go to HELL!\n");
	}
	return soundTable[index].mEventType;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool SeSystem::isLoopType(int index)
{
	if (index < 0 || index > mMaxSoundID) {
		PRINT("soundID = %d\n", index);
		ERROR("go to HELL!\n");
	}
	return soundTable[index].mLoopType == 1;
}

/*
 * --INFO--
 * Address:	800A52DC
 * Size:	000098
 */
void SeSystem::exitCourse()
{
	PRINT("*** BEFORE EXIT COUSE ***\n");
	mIsClosed = true;
	dumpEvents();
	mBossActive = false;
	initEvent();
	mIsClosed = true;
}

/*
 * --INFO--
 * Address:	800A5374
 * Size:	000034
 */
void SeSystem::playSysSe(int index)
{
	Jac_PlaySystemSe(seSystem->getJacID(index));
}

/*
 * --INFO--
 * Address:	800A53A8
 * Size:	000034
 */
void SeSystem::stopSysSe(int index)
{
	Jac_StopSystemSe(seSystem->getJacID(index));
}

/*
 * --INFO--
 * Address:	800A53DC
 * Size:	000034
 */
void SeSystem::playPlayerSe(int index)
{
	Jac_PlayOrimaSe(seSystem->getJacID(index));
}

/*
 * --INFO--
 * Address:	800A5410
 * Size:	000034
 */
void SeSystem::stopPlayerSe(int index)
{
	Jac_StopOrimaSe(seSystem->getJacID(index));
}
