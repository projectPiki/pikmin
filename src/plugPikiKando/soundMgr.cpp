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
	bool ret;
	if (false) { // flag not present in final
		PRINT("releaseEvent : %x : handle = %d\n", this, mEventHandle);
	}

	if (mEventHandle != -1) {
		ret = seSystem->destroyEvent(this, mEventHandle);
		PRINT("** destroyEvent %s\n", ret ? "succeeded" : "failed");
		mEventHandle = -1;
	} else {
		mEventHandle = -1;
		ret          = false;
	}

	return ret;
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
 * Address:	800A40F8
 * Size:	000014
 */
SeSystem::Event::Event()
{
	mHandle  = -1;
	mContext = nullptr;
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
int SeSystem::createEvent(SeContext* context, int a1, SVector_* a2)
{
	if (mIsClosed) {
		return -1;
	}

	int test = -1;
	int num  = mCurrentEventCount;
	if (mMaxEventCount < mCurrentEventCount) {
		test = Jac_CreateEvent(a1, a2);
		if (test == -1) {
			dumpEvents();
			for (int x = 0; x < 10; x++) { }
			return -1;
		} else {
			Event* evt    = &mEvents[mCurrentEventCount++];
			evt->mHandle  = test;
			evt->mContext = context;
		}
	} else {
		int index  = -1;
		f32 length = a2->x * a2->x + a2->y * a2->y + a2->z * a2->z;
		for (int i = 0; i < num; i++) {
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
			SeContext* ctx = mEvents[index].mContext;
			bool ev        = ctx->releaseEvent();
			test           = Jac_CreateEvent(a1, a2);
			if (test == -1 && ev) {
				dumpEvents();
				for (int x = 0; x < 10; x++) { }
			}
			mEvents[mCurrentEventCount].mHandle  = test;
			mEvents[mCurrentEventCount].mContext = context;
			mCurrentEventCount++;
			context->mEventHandle = test;
			context->mEventType   = a1;
			return test;
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r27, 0x34(r1)
	  mr        r28, r3
	  addi      r29, r4, 0
	  addi      r30, r5, 0
	  addi      r31, r6, 0
	  lbz       r0, 0x75(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  li        r3, -0x1
	  b         .loc_0x1F8

	.loc_0x34:
	  lwz       r0, 0x68(r28)
	  li        r3, -0x1
	  lwz       r4, 0x6C(r28)
	  cmpw      r0, r4
	  bge-      .loc_0xA8
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x8C8AC
	  cmpwi     r3, -0x1
	  bne-      .loc_0x84
	  mr        r3, r28
	  bl        0xB44
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x7C

	.loc_0x78:
	  bdnz-     .loc_0x78

	.loc_0x7C:
	  li        r3, -0x1
	  b         .loc_0x1F8

	.loc_0x84:
	  lwz       r4, 0x68(r28)
	  lwz       r5, 0x70(r28)
	  addi      r0, r4, 0x1
	  rlwinm    r4,r4,3,0,28
	  stw       r0, 0x68(r28)
	  add       r4, r5, r4
	  stw       r3, 0x0(r4)
	  stw       r29, 0x4(r4)
	  b         .loc_0x1F8

	.loc_0xA8:
	  lfs       f1, 0x0(r31)
	  cmpwi     r4, 0
	  lfs       f0, 0x4(r31)
	  mtctr     r4
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  lfs       f2, 0x8(r31)
	  li        r6, -0x1
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  li        r7, 0
	  li        r5, 0
	  fadds     f3, f2, f0
	  ble-      .loc_0x130

	.loc_0xE0:
	  lwz       r4, 0x70(r28)
	  addi      r0, r5, 0x4
	  lwzx      r4, r4, r0
	  cmplwi    r4, 0
	  beq-      .loc_0x124
	  lfs       f1, 0x10(r4)
	  lfs       f0, 0x14(r4)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x18(r4)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fcmpo     cr0, f0, f3
	  ble-      .loc_0x124
	  fmr       f3, f0
	  mr        r6, r7

	.loc_0x124:
	  addi      r5, r5, 0x8
	  addi      r7, r7, 0x1
	  bdnz+     .loc_0xE0

	.loc_0x130:
	  cmpwi     r6, -0x1
	  beq-      .loc_0x1F8
	  lwz       r3, 0x70(r28)
	  rlwinm    r0,r6,3,0,28
	  add       r3, r3, r0
	  lwz       r27, 0x4(r3)
	  lwz       r5, 0x8(r27)
	  cmpwi     r5, -0x1
	  beq-      .loc_0x170
	  lwz       r3, 0x3038(r13)
	  mr        r4, r27
	  bl        0x470
	  li        r0, -0x1
	  stw       r0, 0x8(r27)
	  mr        r27, r3
	  b         .loc_0x17C

	.loc_0x170:
	  li        r0, -0x1
	  stw       r0, 0x8(r27)
	  li        r27, 0

	.loc_0x17C:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x8C9E0
	  addi      r31, r3, 0
	  cmpwi     r31, -0x1
	  bne-      .loc_0x1BC
	  rlwinm.   r0,r27,0,24,31
	  beq-      .loc_0x1BC
	  mr        r3, r28
	  bl        0xA04
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x1BC

	.loc_0x1B8:
	  bdnz-     .loc_0x1B8

	.loc_0x1BC:
	  lwz       r0, 0x68(r28)
	  addi      r3, r31, 0
	  lwz       r4, 0x70(r28)
	  rlwinm    r0,r0,3,0,28
	  stwx      r31, r4, r0
	  lwz       r0, 0x68(r28)
	  lwz       r4, 0x70(r28)
	  rlwinm    r0,r0,3,0,28
	  add       r4, r4, r0
	  stw       r29, 0x4(r4)
	  lwz       r4, 0x68(r28)
	  addi      r0, r4, 0x1
	  stw       r0, 0x68(r28)
	  stw       r31, 0x8(r29)
	  sth       r30, 0xC(r29)

	.loc_0x1F8:
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
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

	SeContext* ctx       = mContext + mCurrentContextCount;
	int sysSeContext     = mCurrentContextCount;
	mCurrentContextCount = (mCurrentContextCount + 1) % mMaxContextCount;
	ctx->releaseEvent();
	ctx->setContext(nullptr, type);
	ctx->setPosition(pos);
	ctx->playSound(sound);

	PRINT(" ** [ReUse] sysSeContext %d\n", sysSeContext);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stfd      f29, 0xD0(r1)
	  stfd      f28, 0xC8(r1)
	  stmw      r25, 0xAC(r1)
	  mr        r27, r3
	  mr        r28, r4
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  li        r26, -0x1
	  li        r25, 0
	  li        r31, 0
	  lfs       f28, -0x7260(r2)
	  lfs       f29, -0x7268(r2)
	  lfd       f30, -0x7258(r2)
	  lfd       f31, -0x7250(r2)
	  b         .loc_0x144

	.loc_0x50:
	  lwz       r0, 0x70(r27)
	  add       r3, r0, r31
	  lwz       r5, 0x4(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0x13C
	  lhz       r0, 0xC(r5)
	  cmpw      r0, r28
	  bne-      .loc_0x13C
	  lwz       r4, 0x4(r5)
	  cmplwi    r4, 0
	  beq-      .loc_0x8C
	  addi      r3, r1, 0x7C
	  addi      r4, r4, 0x94
	  bl        -0x31374
	  b         .loc_0x98

	.loc_0x8C:
	  addi      r3, r1, 0x7C
	  addi      r4, r5, 0x1C
	  bl        -0x31384

	.loc_0x98:
	  lfs       f3, 0x80(r1)
	  lfs       f2, 0x4(r30)
	  lfs       f1, 0x7C(r1)
	  lfs       f0, 0x0(r30)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x84(r1)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x8(r30)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x128
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x70(r1)
	  lfs       f2, 0x70(r1)

	.loc_0x128:
	  fcmpo     cr0, f2, f28
	  cror      2, 0, 0x2
	  bne-      .loc_0x13C
	  mr        r26, r25
	  fmr       f28, f2

	.loc_0x13C:
	  addi      r31, r31, 0x8
	  addi      r25, r25, 0x1

	.loc_0x144:
	  lwz       r0, 0x68(r27)
	  cmpw      r25, r0
	  blt+      .loc_0x50
	  cmpwi     r26, -0x1
	  beq-      .loc_0x1FC
	  lwz       r5, 0x70(r27)
	  rlwinm    r0,r26,3,0,28
	  lwz       r3, 0x3038(r13)
	  addi      r4, r29, 0
	  add       r5, r5, r0
	  lwz       r28, 0x4(r5)
	  bl        0xD20
	  lwz       r0, 0x8(r28)
	  addi      r27, r3, 0
	  cmpwi     r0, -0x1
	  bne-      .loc_0x1D8
	  lwz       r4, 0x4(r28)
	  cmplwi    r4, 0
	  beq-      .loc_0x1A4
	  addi      r3, r1, 0x64
	  addi      r4, r4, 0x94
	  bl        -0x31488
	  addi      r4, r1, 0x64
	  b         .loc_0x1B4

	.loc_0x1A4:
	  addi      r3, r1, 0x64
	  addi      r4, r28, 0x1C
	  bl        -0x3149C
	  addi      r4, r1, 0x64

	.loc_0x1B4:
	  lwz       r3, 0x3038(r13)
	  addi      r5, r28, 0x10
	  bl        0xBD8
	  lwz       r3, 0x3038(r13)
	  mr        r4, r28
	  lhz       r5, 0xC(r28)
	  addi      r6, r28, 0x10
	  bl        -0x408
	  stw       r3, 0x8(r28)

	.loc_0x1D8:
	  lwz       r3, 0x8(r28)
	  cmpwi     r3, -0x1
	  beq-      .loc_0x370
	  mr        r4, r27
	  bl        -0x8CAFC
	  lwz       r3, 0x3038(r13)
	  lwz       r0, 0x64(r3)
	  stw       r0, 0x0(r28)
	  b         .loc_0x370

	.loc_0x1FC:
	  lwz       r6, 0x54(r27)
	  lwz       r3, 0x58(r27)
	  addi      r4, r6, 0x1
	  lwz       r5, 0x5C(r27)
	  divw      r0, r4, r3
	  mullw     r0, r0, r3
	  mulli     r3, r6, 0x28
	  sub       r0, r4, r0
	  add       r31, r5, r3
	  stw       r0, 0x54(r27)
	  mr        r4, r31
	  lwz       r5, 0x8(r31)
	  cmpwi     r5, -0x1
	  beq-      .loc_0x248
	  lwz       r3, 0x3038(r13)
	  bl        .loc_0x394
	  li        r0, -0x1
	  stw       r0, 0x8(r31)
	  b         .loc_0x250

	.loc_0x248:
	  li        r0, -0x1
	  stw       r0, 0x8(r31)

	.loc_0x250:
	  lwz       r5, 0x8(r31)
	  cmpwi     r5, -0x1
	  beq-      .loc_0x280
	  mr        r4, r31
	  beq-      .loc_0x278
	  lwz       r3, 0x3038(r13)
	  bl        .loc_0x394
	  li        r0, -0x1
	  stw       r0, 0x8(r31)
	  b         .loc_0x280

	.loc_0x278:
	  li        r0, -0x1
	  stw       r0, 0x8(r31)

	.loc_0x280:
	  li        r0, -0x1
	  stw       r0, 0x8(r31)
	  li        r0, 0
	  mr        r4, r29
	  stw       r0, 0x4(r31)
	  sth       r28, 0xC(r31)
	  lfs       f0, -0x5240(r13)
	  stfs      f0, 0x10(r31)
	  lfs       f0, -0x523C(r13)
	  stfs      f0, 0x14(r31)
	  lfs       f0, -0x5238(r13)
	  stfs      f0, 0x18(r31)
	  lfs       f0, -0x5234(r13)
	  stfs      f0, 0x1C(r31)
	  lfs       f0, -0x5230(r13)
	  stfs      f0, 0x20(r31)
	  lfs       f0, -0x522C(r13)
	  stfs      f0, 0x24(r31)
	  stw       r0, 0x0(r31)
	  lwz       r3, 0x0(r30)
	  lwz       r0, 0x4(r30)
	  stw       r3, 0x1C(r31)
	  stw       r0, 0x20(r31)
	  lwz       r0, 0x8(r30)
	  stw       r0, 0x24(r31)
	  lwz       r3, 0x3038(r13)
	  bl        0xBA8
	  lwz       r0, 0x8(r31)
	  addi      r27, r3, 0
	  cmpwi     r0, -0x1
	  bne-      .loc_0x350
	  lwz       r4, 0x4(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x31C
	  addi      r3, r1, 0x50
	  addi      r4, r4, 0x94
	  bl        -0x31600
	  addi      r4, r1, 0x50
	  b         .loc_0x32C

	.loc_0x31C:
	  addi      r3, r1, 0x50
	  addi      r4, r31, 0x1C
	  bl        -0x31614
	  addi      r4, r1, 0x50

	.loc_0x32C:
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x10
	  bl        0xA60
	  lwz       r3, 0x3038(r13)
	  mr        r4, r31
	  lhz       r5, 0xC(r31)
	  addi      r6, r31, 0x10
	  bl        -0x580
	  stw       r3, 0x8(r31)

	.loc_0x350:
	  lwz       r3, 0x8(r31)
	  cmpwi     r3, -0x1
	  beq-      .loc_0x370
	  mr        r4, r27
	  bl        -0x8CC74
	  lwz       r3, 0x3038(r13)
	  lwz       r0, 0x64(r3)
	  stw       r0, 0x0(r31)

	.loc_0x370:
	  lmw       r25, 0xAC(r1)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lfd       f29, 0xD0(r1)
	  lfd       f28, 0xC8(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr

	.loc_0x394:
	*/
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
		SeContext* ctx = mEvents[i].mContext;
		if (ctx) {
			sprintf(str, "(%d) : %s %d %s (%d)", i, ctx->mGameObj ? ObjType::getName(ctx->mGameObj->mObjType) : "<pos>", ctx->mEventHandle,
			        names[ctx->mEventType], mClock - ctx->mClock);
			gfx.texturePrintf(gsys->mConsFont, 55, y, str);
			y += 16;
		} else {
			sprintf(str, "(%d) : handle %d , seContext = %x", i, mEvents[i].mHandle, ctx);
			gfx.texturePrintf(gsys->mConsFont, 55, y, str);
			y += 16;
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x170(r1)
	  stmw      r24, 0x150(r1)
	  li        r25, 0xFF
	  addi      r27, r4, 0
	  addi      r26, r3, 0
	  addi      r31, r5, 0x1E10
	  addi      r4, r1, 0x18
	  mr        r3, r27
	  li        r5, 0x1
	  stb       r25, 0x18(r1)
	  stb       r25, 0x19(r1)
	  stb       r25, 0x1A(r1)
	  stb       r25, 0x1B(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r5, 0x37
	  stb       r5, 0x14(r1)
	  li        r0, 0x80
	  addi      r4, r1, 0x14
	  stb       r5, 0x15(r1)
	  mr        r3, r27
	  stb       r5, 0x16(r1)
	  li        r5, 0x1
	  stb       r0, 0x17(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x6C(r26)
	  li        r0, 0x14
	  li        r3, 0x3C
	  stw       r0, 0x40(r1)
	  rlwinm    r4,r4,4,0,27
	  li        r0, 0x226
	  stw       r3, 0x44(r1)
	  addi      r5, r4, 0x78
	  addi      r3, r27, 0
	  stw       r0, 0x48(r1)
	  addi      r4, r1, 0x40
	  stw       r5, 0x4C(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl
	  stb       r25, 0x10(r1)
	  addi      r4, r1, 0x10
	  addi      r3, r27, 0
	  stb       r25, 0x11(r1)
	  li        r5, 0x1
	  stb       r25, 0x12(r1)
	  stb       r25, 0x13(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x68(r26)
	  addi      r3, r1, 0x50
	  lwz       r6, 0x6C(r26)
	  addi      r4, r31, 0x2FB0
	  lfs       f1, 0x48(r26)
	  lfs       f2, 0x4C(r26)
	  crset     6, 0x6
	  lfs       f3, 0x50(r26)
	  lwz       r7, 0x64(r26)
	  bl        0x171998
	  mr        r3, r27
	  lwz       r4, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r27)
	  addi      r7, r1, 0x50
	  lwz       r4, 0x10(r4)
	  crclr     6, 0x6
	  lwz       r12, 0xEC(r12)
	  li        r5, 0x1E
	  mtlr      r12
	  li        r6, 0x46
	  blrl
	  lis       r3, 0x8022
	  addi      r4, r3, 0x2418
	  lwz       r3, 0x0(r4)
	  addi      r25, r1, 0x1C
	  lwz       r0, 0x4(r4)
	  li        r29, 0x5A
	  li        r28, 0
	  stw       r3, 0x1C(r1)
	  li        r30, 0
	  stw       r0, 0x20(r1)
	  lwz       r3, 0x8(r4)
	  lwz       r0, 0xC(r4)
	  stw       r3, 0x24(r1)
	  stw       r0, 0x28(r1)
	  lwz       r3, 0x10(r4)
	  lwz       r0, 0x14(r4)
	  stw       r3, 0x2C(r1)
	  stw       r0, 0x30(r1)
	  lwz       r3, 0x18(r4)
	  lwz       r0, 0x1C(r4)
	  stw       r3, 0x34(r1)
	  stw       r0, 0x38(r1)
	  lwz       r0, 0x20(r4)
	  stw       r0, 0x3C(r1)
	  b         .loc_0x2B0

	.loc_0x1C4:
	  lwz       r0, 0x70(r26)
	  add       r3, r0, r30
	  lwz       r24, 0x4(r3)
	  cmplwi    r24, 0
	  beq-      .loc_0x25C
	  lwz       r3, 0x4(r24)
	  cmplwi    r3, 0
	  beq-      .loc_0x1F0
	  lwz       r3, 0x6C(r3)
	  bl        -0x10280
	  b         .loc_0x1F4

	.loc_0x1F0:
	  subi      r3, r13, 0x51D8

	.loc_0x1F4:
	  lhz       r0, 0xC(r24)
	  mr        r5, r28
	  lwz       r9, 0x0(r24)
	  addi      r6, r3, 0
	  rlwinm    r8,r0,2,0,29
	  lwz       r0, 0x64(r26)
	  addi      r3, r1, 0x50
	  lwz       r7, 0x8(r24)
	  addi      r4, r31, 0x2FE4
	  lwzx      r8, r25, r8
	  sub       r9, r0, r9
	  crclr     6, 0x6
	  bl        0x1718A4
	  mr        r3, r27
	  lwz       r4, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r27)
	  mr        r6, r29
	  lwz       r4, 0x10(r4)
	  addi      r7, r1, 0x50
	  lwz       r12, 0xEC(r12)
	  crclr     6, 0x6
	  li        r5, 0x37
	  mtlr      r12
	  blrl
	  addi      r29, r29, 0x10
	  b         .loc_0x2A8

	.loc_0x25C:
	  lwz       r6, 0x0(r3)
	  addi      r5, r28, 0
	  addi      r7, r24, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x50
	  addi      r4, r31, 0x2FFC
	  bl        0x171854
	  mr        r3, r27
	  lwz       r4, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r27)
	  mr        r6, r29
	  lwz       r4, 0x10(r4)
	  addi      r7, r1, 0x50
	  lwz       r12, 0xEC(r12)
	  crclr     6, 0x6
	  li        r5, 0x37
	  mtlr      r12
	  blrl
	  addi      r29, r29, 0x10

	.loc_0x2A8:
	  addi      r30, r30, 0x8
	  addi      r28, r28, 0x1

	.loc_0x2B0:
	  lwz       r0, 0x6C(r26)
	  cmpw      r28, r0
	  blt+      .loc_0x1C4
	  lmw       r24, 0x150(r1)
	  lwz       r0, 0x174(r1)
	  addi      r1, r1, 0x170
	  mtlr      r0
	  blr
	*/
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
	if (max) {
		for (int i = max >> 3; i > 0; i--) { }
		max = max & 7;
		for (int i = max; i > 0; i--) { }
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  li        r31, 0
	  stw       r30, 0xA0(r1)
	  li        r30, 0
	  stw       r29, 0x9C(r1)
	  addi      r29, r3, 0
	  b         .loc_0x58

	.loc_0x28:
	  lwz       r0, 0x70(r29)
	  add       r3, r0, r31
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  lwz       r3, 0x6C(r3)
	  bl        -0x103B4

	.loc_0x50:
	  addi      r31, r31, 0x8
	  addi      r30, r30, 0x1

	.loc_0x58:
	  lwz       r0, 0x6C(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x28
	  addi      r3, r1, 0x14
	  bl        -0x8CD48
	  mr        r31, r3
	  bl        -0x8CD90
	  cmplwi    r31, 0
	  ble-      .loc_0x9C
	  rlwinm.   r0,r31,29,3,31
	  mtctr     r0
	  beq-      .loc_0x94

	.loc_0x88:
	  bdnz-     .loc_0x88
	  andi.     r31, r31, 0x7
	  beq-      .loc_0x9C

	.loc_0x94:
	  mtctr     r31

	.loc_0x98:
	  bdnz-     .loc_0x98

	.loc_0x9C:
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  lwz       r29, 0x9C(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
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
