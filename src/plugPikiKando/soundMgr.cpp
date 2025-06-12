#include "SoundMgr.h"
#include "Boss.h"
#include "Font.h"
#include "sysNew.h"
#include "NaviMgr.h"
#include "gameflow.h"
#include "Graphics.h"
#include "jaudio/verysimple.h"
#include "jaudio/pikiinter.h"
#include "jaudio/piki_bgm.h"
#include "jaudio/piki_player.h"
#include "DebugLog.h"

/// Global sound effect system manager object.
SeSystem* seSystem;

/**
 * @brief Error function for soundMgr.cpp, stripped in retail.
 *
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/**
 * @brief Print function for soundMgr.cpp, stripped in retail.
 *
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("soundMgr")

/**
 * @brief Sound effect information object, for use primarily in soundTable object.
 *
 * @note Size: 0x14.
 */
struct SoundTableInfo {
	int mSeID;      ///< _00, game-code sound ID, see PikiSoundID enum.
	int mJacID;     ///< _04, jaudio-code sound IDs, enums split mainly by event type.
	char* mSeName;  ///< _08, sound effect name.
	BOOL mLoopType; ///< _0C, whether to loop the sound effect.
	int mEventType; ///< _10, jaudio-related event type, see JacEventType enum.
};

/// Global sound effect information object, to convert between game code and jaudio code requirements.
SoundTableInfo soundTable[] = {
	// TEKI AND BOSS SOUNDS
	{ 0, 0, "SE_BATTLE_START", TRUE, JACEVENT_Battle },
	{ 1, 1, "SE_CHAPPY_WALK", FALSE, JACEVENT_Battle },
	{ 2, 2, "SE_CHAPPY_DIE", FALSE, JACEVENT_Battle },
	{ 3, 3, "SE_CHAPPY_SWING", FALSE, JACEVENT_Battle },
	{ 4, 4, "SE_CHAPPY_SLEEP", FALSE, JACEVENT_Battle },
	{ 5, 5, "SE_CHAPPY_BITE", FALSE, JACEVENT_Battle },
	{ 6, 6, "SE_CHAPPY_EAT", FALSE, JACEVENT_Battle },
	{ 7, 7, "SE_CHAPPY_DOWN", FALSE, JACEVENT_Battle },
	{ 8, 8, "SE_CHAPPY_FOOTDAMAGE", FALSE, JACEVENT_Battle },
	{ 9, 9, "SE_CHAPPY_BITE2", FALSE, JACEVENT_Battle },
	{ 10, 10, "SE_FLOG_WALK", FALSE, JACEVENT_Battle },
	{ 11, 11, "SE_FLOG_DIE", FALSE, JACEVENT_Battle },
	{ 12, 12, "SE_FLOG_FALL", FALSE, JACEVENT_Battle },
	{ 13, 13, "SE_FLOG_HIJUMP", FALSE, JACEVENT_Battle },
	{ 14, 14, "SE_FLOG_JUMP", FALSE, JACEVENT_Battle },
	{ 15, 15, "SE_FLOG_DOWN", FALSE, JACEVENT_Battle },
	{ 16, 16, "SE_FLOG_LAND", FALSE, JACEVENT_Battle },
	{ 17, 17, "SE_FLOG_VOICE", FALSE, JACEVENT_Battle },
	{ 18, 18, "SE_FLOG_ATTACK", FALSE, JACEVENT_Battle },
	{ 19, 19, "SE_FLOG_EAT", FALSE, JACEVENT_Battle },
	{ 20, 20, "SE_FLOG_WATERJUMP", FALSE, JACEVENT_Battle },
	{ 21, 21, "SE_FLOG_WATERLAND", FALSE, JACEVENT_Battle },
	{ 22, 22, "SE_PIKI_EATEN", FALSE, JACEVENT_Battle },
	{ 23, 23, "SE_PIKI_ATTACK_VOICE", FALSE, JACEVENT_Battle },
	{ 24, 24, "SE_MISSHIT", FALSE, JACEVENT_Battle },
	{ 25, 25, "SE_PIKI_ATTACK_HIT", FALSE, JACEVENT_Battle },
	{ 26, 26, "SE_PIKI_DAMAGED", FALSE, JACEVENT_Battle },
	{ 27, 27, "SE_PIKI_PRESSED", FALSE, JACEVENT_Battle },
	{ 28, 30, "SE_WALL_HIT", FALSE, JACEVENT_Battle },
	{ 29, 46, "SE_SOFTWALL_HIT", FALSE, JACEVENT_Battle },
	{ 30, 47, "SE_WALL_DOWN", FALSE, JACEVENT_Battle },
	{ 31, 31, "SE_BOMB", FALSE, JACEVENT_Battle },
	{ 32, 32, "SE_MINIC_WALK", FALSE, JACEVENT_Battle },
	{ 33, 33, "SE_MINIC_FOOTDAMAGE", FALSE, JACEVENT_Battle },
	{ 34, 34, "SE_MINIC_DIE", FALSE, JACEVENT_Battle },
	{ 35, 35, "SE_MINIC_SWING", FALSE, JACEVENT_Battle },
	{ 36, 36, "SE_MINIC_BITE", FALSE, JACEVENT_Battle },
	{ 37, 37, "SE_MINIC_EAT", FALSE, JACEVENT_Battle },
	{ 38, 38, "SE_MINIC_DOWN", FALSE, JACEVENT_Battle },
	{ 39, 39, "SE_MINIC_ALERT", FALSE, JACEVENT_Battle },
	{ 40, 53, "SE_SNAKE_APPEAR", FALSE, JACEVENT_Battle },
	{ 41, 48, "SE_SPIDER_WALK", FALSE, JACEVENT_Battle },
	{ 42, 49, "SE_SPIDER_LAND", FALSE, JACEVENT_Battle },
	{ 43, 50, "SE_SPIDER_SWING", FALSE, JACEVENT_Battle },
	{ 44, 51, "SE_SPIDER_DEAD", FALSE, JACEVENT_Battle },
	{ 45, 52, "SE_SPIDER_BOMB", FALSE, JACEVENT_Battle },
	{ 46, 41, "SE_FLOWER_DOWN", FALSE, JACEVENT_Battle },
	{ 47, 42, "SE_FLOWER_CONVULSION", FALSE, JACEVENT_Battle },
	{ 48, 43, "SE_FLOWER_GROW0", FALSE, JACEVENT_Battle },
	{ 49, 44, "SE_FLOWER_GROW1", FALSE, JACEVENT_Battle },
	{ 50, 45, "SE_FLOWER_GROW2", FALSE, JACEVENT_Battle },
	{ 51, 28, "SE_PIKI_DEAD", FALSE, JACEVENT_Battle },
	{ 52, 54, "SE_SNAKE_DIG", FALSE, JACEVENT_Battle },
	{ 53, 55, "SE_SNAKE_SHOUT", FALSE, JACEVENT_Battle },
	{ 54, 56, "SE_SNAKE_EAT", FALSE, JACEVENT_Battle },
	{ 55, 57, "SE_SNAKE_DRINK", FALSE, JACEVENT_Battle },
	{ 56, 58, "SE_SNAKE_TURN", FALSE, JACEVENT_Battle },
	{ 57, 59, "SE_SNAKE_MOGAKU", FALSE, JACEVENT_Battle },
	{ 58, 60, "SE_SNAKE_DEAD1", FALSE, JACEVENT_Battle },
	{ 59, 61, "SE_SNAKE_DEAD2", FALSE, JACEVENT_Battle },
	{ 60, 62, "SE_TANK_FIRE", FALSE, JACEVENT_Battle },
	{ 61, 63, "SE_TANK_BREATH", FALSE, JACEVENT_Battle },
	{ 62, 64, "SE_TANK_WALK", FALSE, JACEVENT_Battle },
	{ 63, 65, "SE_TANK_SWING", FALSE, JACEVENT_Battle },
	{ 64, 66, "SE_TANK_DAMAGE", FALSE, JACEVENT_Battle },
	{ 65, 67, "SE_TANK_DEAD1", FALSE, JACEVENT_Battle },
	{ 66, 68, "SE_TANK_DEAD2", FALSE, JACEVENT_Battle },
	{ 67, 69, "SE_MUSH_WALK", FALSE, JACEVENT_Battle },
	{ 68, 70, "SE_MUSH_FLIP", FALSE, JACEVENT_Battle },
	{ 69, 71, "SE_MUSH_TUMBLE", FALSE, JACEVENT_Battle },
	{ 70, 72, "SE_MUSH_GETUP", FALSE, JACEVENT_Battle },
	{ 71, 73, "SE_MUSH_LAND", FALSE, JACEVENT_Battle },
	{ 72, 74, "SE_MUSH_TAME", FALSE, JACEVENT_Battle },
	{ 73, 75, "SE_MUSH_SPORE", FALSE, JACEVENT_Battle },
	{ 74, 76, "SE_MUSH_DAMAGE", FALSE, JACEVENT_Battle },
	{ 75, 77, "SE_MUSH_DEAD1", FALSE, JACEVENT_Battle },
	{ 76, 78, "SE_MUSH_DEAD2", FALSE, JACEVENT_Battle },
	{ 77, 79, "SE_KING_WALK", FALSE, JACEVENT_Battle },
	{ 78, 80, "SE_KING_READY", FALSE, JACEVENT_Battle },
	{ 79, 81, "SE_KING_BERO1", FALSE, JACEVENT_Battle },
	{ 80, 82, "SE_KING_BERO2", FALSE, JACEVENT_Battle },
	{ 81, 83, "SE_KING_GEPPU", FALSE, JACEVENT_Battle },
	{ 82, 84, "SE_KING_DRINK", FALSE, JACEVENT_Battle },
	{ 83, 85, "SE_KING_EAT", FALSE, JACEVENT_Battle },
	{ 84, 86, "SE_KING_CHEEK", FALSE, JACEVENT_Battle },
	{ 85, 87, "SE_KING_NAME", FALSE, JACEVENT_Battle },
	{ 86, 88, "SE_KING_HIP", FALSE, JACEVENT_Battle },
	{ 87, 89, "SE_KING_DEAD1", FALSE, JACEVENT_Battle },
	{ 88, 90, "SE_KING_DEAD2", FALSE, JACEVENT_Battle },
	{ 89, 91, "SE_KING_APPEAR", FALSE, JACEVENT_Battle },
	{ 90, 92, "SE_KING_SINK", FALSE, JACEVENT_Battle },
	{ 91, 93, "SE_KABUTO_BREATH", FALSE, JACEVENT_Battle },
	{ 92, 94, "SE_KABUTO_TUMARI", FALSE, JACEVENT_Battle },
	{ 93, 95, "SE_KABUTO_OPEN", FALSE, JACEVENT_Battle },
	{ 94, 96, "SE_KABUTO_SHOT", FALSE, JACEVENT_Battle },
	{ 95, 97, "SE_KABUTO_FLIP", FALSE, JACEVENT_Battle },
	{ 96, 98, "SE_KABUTO_WALK", FALSE, JACEVENT_Battle },
	{ 97, 99, "SE_KABUTO_COOLDOWN", FALSE, JACEVENT_Battle },
	{ 98, 100, "SE_KABUTO_OVERHEAT", FALSE, JACEVENT_Battle },
	{ 99, 101, "SE_KABUTO_DEAD", FALSE, JACEVENT_Battle },
	{ 100, 102, "SE_ROCK_ROLL", FALSE, JACEVENT_Battle },
	{ 101, 103, "SE_ROCK_BREAK", FALSE, JACEVENT_Battle },
	{ 102, 104, "SE_ROCK_GENERATOR", FALSE, JACEVENT_Battle },
	{ 103, 105, "SE_SHELL_CLOSE", FALSE, JACEVENT_Battle },
	{ 104, 106, "SE_SHELL_READY", FALSE, JACEVENT_Battle },
	{ 105, 107, "SE_SHELL_TRESURE", FALSE, JACEVENT_Battle },
	{ 106, 108, "SE_SHELL_OPEN", FALSE, JACEVENT_Battle },
	{ 107, 109, "SE_SHELL_EAT", FALSE, JACEVENT_Battle },
	{ 108, 110, "SE_KINOKOPIKI_MORPH", FALSE, JACEVENT_Battle },
	{ 109, 111, "SE_KINOKOPIKI_DANCE", FALSE, JACEVENT_Battle },
	{ 110, 112, "SE_COLLEC_BREATH", FALSE, JACEVENT_Battle },
	{ 111, 113, "SE_COLLEC_PULL", FALSE, JACEVENT_Battle },
	{ 112, 114, "SE_COLLEC_WALK", FALSE, JACEVENT_Battle },
	{ 113, 115, "SE_COLLEC_SWING", FALSE, JACEVENT_Battle },
	{ 114, 116, "SE_COLLEC_DEAD", FALSE, JACEVENT_Battle },
	{ 115, 117, "SE_COLLEC_DOWN", FALSE, JACEVENT_Battle },
	{ 116, 118, "SE_COLLEC_CRY", FALSE, JACEVENT_Battle },
	{ 117, 119, "SE_COLLEC_DAMAGE", FALSE, JACEVENT_Battle },
	{ 118, 120, "SE_KOGANE_WALK", FALSE, JACEVENT_Battle },
	{ 119, 121, "SE_KOGANE_DAMAGE", FALSE, JACEVENT_Battle },
	{ 120, 122, "SE_SARAI_HOVER", FALSE, JACEVENT_Battle },
	{ 121, 123, "SE_SARAI_DAMAGE", FALSE, JACEVENT_Battle },
	{ 122, 124, "SE_SARAI_ATTACK", FALSE, JACEVENT_Battle },
	{ 123, 125, "SE_SARAI_DEAD", FALSE, JACEVENT_Battle },
	{ 124, 126, "SE_WALLEAT_WALK", FALSE, JACEVENT_Battle },
	{ 125, 127, "SE_WALLEAT_NIP", FALSE, JACEVENT_Battle },
	{ 126, 128, "SE_WALLEAT_EAT", FALSE, JACEVENT_Battle },
	{ 127, 129, "SE_WALLEAT_APPEAR", FALSE, JACEVENT_Battle },
	{ 128, 130, "SE_MAR_FLY", FALSE, JACEVENT_Battle },
	{ 129, 131, "SE_MAR_BREATH", FALSE, JACEVENT_Battle },
	{ 130, 132, "SE_MAR_WIND", FALSE, JACEVENT_Battle },
	{ 131, 133, "SE_MAR_DROP", FALSE, JACEVENT_Battle },
	{ 132, 134, "SE_MAR_DEAD1", FALSE, JACEVENT_Battle },
	{ 133, 135, "SE_MAR_DEAD2", FALSE, JACEVENT_Battle },
	{ 134, 136, "SE_MIURIN_WALK", FALSE, JACEVENT_Battle },
	{ 135, 137, "SE_MIURIN_PUNCH", FALSE, JACEVENT_Battle },
	{ 136, 138, "SE_MIURIN_SING", FALSE, JACEVENT_Battle },
	{ 137, 139, "SE_KURIONE_HIT", FALSE, JACEVENT_Battle },
	{ 138, 140, "SE_KURIONE_ESCAPE", FALSE, JACEVENT_Battle },
	{ 139, 141, "SE_KURIONE_WATER", FALSE, JACEVENT_Battle },
	{ 140, 142, "SE_KURIONE_FLYING", FALSE, JACEVENT_Battle },
	{ 141, 143, "SE_SLIME_WALK", FALSE, JACEVENT_Battle },
	{ 142, 144, "SE_SLIME_HIT_SMALL", FALSE, JACEVENT_Battle },
	{ 143, 145, "SE_SLIME_HIT_MID", FALSE, JACEVENT_Battle },
	{ 144, 146, "SE_SLIME_HIT_LARGE", FALSE, JACEVENT_Battle },
	{ 145, 147, "SE_SLIME_DEAD", FALSE, JACEVENT_Battle },
	{ 146, 148, "SE_SLIME_EXT1", FALSE, JACEVENT_Battle },
	{ 147, 149, "SE_SLIME_EXT2", FALSE, JACEVENT_Battle },
	{ 148, 150, "SE_SLIME_EXT3", FALSE, JACEVENT_Battle },
	{ 149, 151, "SE_SLIME_DISAPPEAR", FALSE, JACEVENT_Battle },
	{ 150, 152, "SE_DORORO_WALK", FALSE, JACEVENT_Battle },
	{ 151, 153, "SE_DORORO_CRY", FALSE, JACEVENT_Battle },
	{ 152, 154, "SE_DORORO_DEAD", FALSE, JACEVENT_Battle },
	{ 153, 155, "SE_DORORO_SWING", FALSE, JACEVENT_Battle },
	{ 154, 156, "SE_DORORO_EGG_CRASH", FALSE, JACEVENT_Battle },
	{ 155, 157, "SE_DORORO_CRASH", FALSE, JACEVENT_Battle },
	{ 156, 158, "SE_PONGASHI_THROWIN", FALSE, JACEVENT_Battle },
	{ 157, 159, "SE_PONGASHI_CLOSE", FALSE, JACEVENT_Battle },
	{ 158, 160, "SE_PONGASHI_EAT", FALSE, JACEVENT_Battle },
	{ 159, 161, "SE_PONGASHI_SHOT", FALSE, JACEVENT_Battle },
	{ 160, 162, "SE_PONGASHI_DEAD", FALSE, JACEVENT_Battle },
	{ 161, 163, "SE_PONGASHI_TOUCH", FALSE, JACEVENT_Battle },
	{ 162, 164, "SE_NAMAZU_WALK", FALSE, JACEVENT_Battle },
	{ 163, 165, "SE_NAMAZU_EAT", FALSE, JACEVENT_Battle },
	{ 164, 166, "SE_NAMAZU_DEAD", FALSE, JACEVENT_Battle },
	{ 165, 167, "SE_OTAMA_JUMP", FALSE, JACEVENT_Battle },
	{ 166, 168, "SE_OTAMA_DEAD", FALSE, JACEVENT_Battle },
	{ 167, 169, "SE_OTAMA_WATERJUMP", FALSE, JACEVENT_Battle },
	{ 168, 170, "SE_GEYSER_NORMAL", FALSE, JACEVENT_Battle },
	{ 169, 171, "SE_GEYSER_SPOUT", FALSE, JACEVENT_Battle },

	// WORK OBJECT SOUNDS
	{ 170, 0, "SEB_SOFTWALL_HIT", FALSE, JACEVENT_Build },
	{ 171, 1, "SEB_WALL_DOWN", FALSE, JACEVENT_Build },
	{ 172, 2, "SEB_HARDESTWALL_HIT", FALSE, JACEVENT_Build },
	{ 173, 3, "SEB_CONSTRUCTION", FALSE, JACEVENT_Build },
	{ 174, 4, "SEB_BOXMOVE", FALSE, JACEVENT_Build },
	{ 175, 5, "SEB_HARDWALL_HIT", FALSE, JACEVENT_Build },
	{ 176, 6, "SEB_STONE_HIT", FALSE, JACEVENT_Build },
	{ 177, 7, "SEB_STONE_BREAK", FALSE, JACEVENT_Build },
	{ 178, 8, "SEB_GRASS_PULL", FALSE, JACEVENT_Build },
	{ 179, 9, "SEB_BRIDGE_EXTEND", FALSE, JACEVENT_Build },

	// SOME PIKI SOUNDS
	{ 180, 0, "SEW_PIKI_WATERDROP", FALSE, JACEVENT_PikiWater },
	{ 181, 1, "SEW_PIKI_DROWN", FALSE, JACEVENT_PikiWater },
	{ 182, 2, "SEW_PIKI_DEAD", FALSE, JACEVENT_PikiWater },
	{ 183, 3, "SEW_PIKI_SINK", FALSE, JACEVENT_PikiWater },

	// SHIP PART SOUNDS
	{ 184, 0, "SE_LIFT_TRY", TRUE, JACEVENT_Pellet },
	{ 185, 1, "SE_LIFT_MOVE", TRUE, JACEVENT_Pellet },
	{ 186, 2, "SE_PIKI_LIFT", TRUE, JACEVENT_Pellet },
	{ 187, 3, "SE_PELLET_BORN", FALSE, JACEVENT_Pellet },
	{ 188, 4, "SE_PELLET_BOUND", FALSE, JACEVENT_Pellet },
	{ 189, 5, "SE_UFOPARTS_BOUND", FALSE, JACEVENT_Pellet },
	{ 190, 6, "SE_UFOPARTS_OTHER", TRUE, JACEVENT_Pellet },
	{ 191, 7, "SE_UFOPARTS_ENGINE", TRUE, JACEVENT_Pellet },
	{ 192, 8, "SE_UFOPARTS_GEAR", TRUE, JACEVENT_Pellet },
	{ 193, 9, "SE_UFOPARTS_RADER", TRUE, JACEVENT_Pellet },
	{ 194, 10, "SE_UFOPARTS_SPRING", TRUE, JACEVENT_Pellet },
	{ 195, 11, "SE_UFOPARTS_BATTERY", TRUE, JACEVENT_Pellet },
	{ 196, 12, "SE_UFOPARTS_ZENMAI", TRUE, JACEVENT_Pellet },
	{ 197, 13, "SE_UFOPARTS_MONEYBOX", TRUE, JACEVENT_Pellet },

	{ 198, 7, "dummy 1", TRUE, JACEVENT_Pellet },
	{ 199, 7, "dummy 2", TRUE, JACEVENT_Pellet },
	{ 200, 7, "dummy 3", TRUE, JACEVENT_Pellet },
	{ 201, 7, "dummy 4", TRUE, JACEVENT_Pellet },
	{ 202, 7, "dummy 5", TRUE, JACEVENT_Pellet },

	// ONION SOUNDS
	{ 203, 0, "SE_CONTAINER_PELLETIN", FALSE, JACEVENT_Onyon },
	{ 204, 1, "SE_CONTAINER_PIKIBORN", FALSE, JACEVENT_Onyon },
	{ 205, 2, "SE_PIKI_GROW1", FALSE, JACEVENT_Onyon },
	{ 206, 3, "SE_PIKI_GROW2", FALSE, JACEVENT_Onyon },
	{ 207, 4, "SE_PIKI_GROW3", FALSE, JACEVENT_Onyon },
	{ 208, 5, "SE_PIKI_GROW4", FALSE, JACEVENT_Onyon },
	{ 209, 6, "SE_PIKI_GROW5", FALSE, JACEVENT_Onyon },
	{ 210, 7, "SE_PIKI_GOHOME", FALSE, JACEVENT_Onyon },
	{ 211, 8, "SE_PIKI_OUTHOME", FALSE, JACEVENT_Onyon },
	{ 212, 9, "SE_PIKI_GROW0", FALSE, JACEVENT_Onyon },
	{ 213, 10, "SE_PIKI_GROW0_WATER", FALSE, JACEVENT_Onyon },
	{ 214, 11, "SE_CONTAINER_PELLETIN2", FALSE, JACEVENT_Onyon },
	{ 215, 12, "SE_CONTAINER_PIKI", FALSE, JACEVENT_Onyon },
	{ 216, 13, "SE_CONTAINER_HANABI", FALSE, JACEVENT_Onyon },
	{ 217, 14, "SE_CONTAINER_CLIMB", FALSE, JACEVENT_Onyon },

	// UFO SOUNDS
	{ 218, 0, "SE_UFO_PARTSIN", FALSE, JACEVENT_Ufo },
	{ 219, 1, "SE_UFO_PARTSSET1", FALSE, JACEVENT_Ufo },
	{ 220, 2, "SE_UFO_PARTSSET2", FALSE, JACEVENT_Ufo },
	{ 221, 3, "SE_UFO_PARTSSET3", FALSE, JACEVENT_Ufo },
	{ 222, 4, "SE_UFO_IDLING", FALSE, JACEVENT_Ufo },
	{ 223, 5, "SE_UFO_SPARK", FALSE, JACEVENT_Ufo },
	{ 224, 6, "SE_UFO_DESTROY", TRUE, JACEVENT_Ufo },
	{ 225, 7, "SE_UFO_SATELLITE", TRUE, JACEVENT_Ufo },
	{ 226, 8, "SE_UFO_LIGHT", TRUE, JACEVENT_Ufo },
	{ 227, 9, "SE_UFO_ANTENNA", TRUE, JACEVENT_Ufo },
	{ 228, 10, "SE_UFO_RADER", TRUE, JACEVENT_Ufo },
	{ 229, 11, "SE_UFO_LIGHT2", TRUE, JACEVENT_Ufo },
	{ 230, 12, "SE_UFO_ENGINE", TRUE, JACEVENT_Ufo },

	// PIKI SOUNDS
	{ 231, 0, "SEF_PIKI_KINOKO2", FALSE, JACEVENT_Piki },
	{ 232, 1, "SEF_PIKI_AKUBI", FALSE, JACEVENT_Piki },
	{ 233, 2, "SEF_PIKI_BURUBURU", FALSE, JACEVENT_Piki },
	{ 234, 3, "SEF_PIKI_CRASH", FALSE, JACEVENT_Piki },
	{ 235, 4, "SEF_PIKI_DEAD1", FALSE, JACEVENT_Piki },
	{ 236, 5, "SEF_PIKI_DEAD2", FALSE, JACEVENT_Piki },
	{ 237, 6, "SEF_PIKI_DEAD3", FALSE, JACEVENT_Piki },
	{ 238, 7, "SEF_PIKI_FALL", FALSE, JACEVENT_Piki },
	{ 239, 8, "SEF_PIKI_GAKKARI", FALSE, JACEVENT_Piki },
	{ 240, 9, "SEF_PIKI_HANG", FALSE, JACEVENT_Piki },
	{ 241, 10, "SEF_PIKI_JUMP1", FALSE, JACEVENT_Piki },
	{ 242, 11, "SEF_PIKI_JUMP2", FALSE, JACEVENT_Piki },
	{ 243, 12, "SEF_PIKI_JUMP3", FALSE, JACEVENT_Piki },
	{ 244, 13, "SEF_PIKI_SNEEZE", FALSE, JACEVENT_Piki },
	{ 245, 14, "SEF_PIKI_SLEEP", FALSE, JACEVENT_Piki },
	{ 246, 15, "SEF_PIKI_NOBI", FALSE, JACEVENT_Piki },
	{ 247, 16, "SEF_PIKI_ANGRY1", FALSE, JACEVENT_Piki },
	{ 248, 17, "SEF_PIKI_ANGRY2", FALSE, JACEVENT_Piki },
	{ 249, 18, "SEF_PIKI_OTTOTTO", FALSE, JACEVENT_Piki },
	{ 250, 19, "SEF_PIKI_SKIP", FALSE, JACEVENT_Piki },
	{ 251, 20, "SEF_PIKI_SLIP1", FALSE, JACEVENT_Piki },
	{ 252, 21, "SEF_PIKI_SLIP2", FALSE, JACEVENT_Piki },
	{ 253, 22, "SEF_PIKI_LAND", FALSE, JACEVENT_Piki },
	{ 254, 23, "SEF_PIKI_YATTA", FALSE, JACEVENT_Piki },
	{ 255, 24, "SEF_PIKI_BREAKUP", FALSE, JACEVENT_Piki },
	{ 256, 25, "SEF_PIKI_CALLED", FALSE, JACEVENT_Piki },
	{ 257, 26, "SEF_PIKI_FIND", FALSE, JACEVENT_Piki },
	{ 258, 27, "SEF_PIKI_FIRED", FALSE, JACEVENT_Piki },
	{ 259, 28, "SEF_PIKI_DRINK", FALSE, JACEVENT_Piki },
	{ 260, 29, "SEF_PIKI_WATERED", FALSE, JACEVENT_Piki },
	{ 261, 31, "SEF_PIKI_ATTACK_VOICE", FALSE, JACEVENT_Piki },
	{ 262, 32, "SEF_PIKI_MISSHIT", FALSE, JACEVENT_Piki },
	{ 263, 33, "SEF_PIKI_ATTACK_HIT", FALSE, JACEVENT_Piki },
	{ 264, 34, "SEF_PIKI_DAMAGED", FALSE, JACEVENT_Piki },
	{ 265, 35, "SEF_PIKI_GROW1", FALSE, JACEVENT_Piki },
	{ 266, 36, "SEF_PIKI_GROW2", FALSE, JACEVENT_Piki },
	{ 267, 37, "SEF_PIKI_GROW3", FALSE, JACEVENT_Piki },
	{ 268, 30, "SEF_PIKI_GROW4", FALSE, JACEVENT_Piki },
	{ 269, 38, "SEF_PIKI_GROW5", FALSE, JACEVENT_Piki },
	{ 270, 39, "SEF_PIKI_GROW0", FALSE, JACEVENT_Piki },
	{ 271, 40, "SEF_PIKI_GROW0_WATER", FALSE, JACEVENT_Piki },

	// SYSTEM SOUNDS
	{ 272, 0, "SYSSE_ALLSTOP", FALSE, JACEVENT_System },
	{ 273, 1, "SYSSE_DECIDE1", FALSE, JACEVENT_System },
	{ 274, 2, "SYSSE_MOVE1", FALSE, JACEVENT_System },
	{ 275, 3, "SYSSE_PAUSE", FALSE, JACEVENT_System },
	{ 276, 4, "SYSSE_EVENING_ALERT", FALSE, JACEVENT_System },
	{ 277, 5, "SYSSE_COUNTDOWN", FALSE, JACEVENT_System },
	{ 278, 6, "SYSSE_CMENU_ON", FALSE, JACEVENT_System },
	{ 279, 7, "SYSSE_CMENU_OFF", FALSE, JACEVENT_System },
	{ 280, 8, "SYSSE_CMENU_SELECT", FALSE, JACEVENT_System },
	{ 281, 9, "SYSSE_CMENU_ERROR", FALSE, JACEVENT_System },
	{ 282, 10, "SYSSE_ORIMA_LIFEDIM", FALSE, JACEVENT_System },
	{ 283, 11, "SYSSE_WORK_FINISH", FALSE, JACEVENT_System },
	{ 284, 12, "SYSSE_VIEW_CHANGE", FALSE, JACEVENT_System },
	{ 285, 13, "SYSSE_CANCEL", FALSE, JACEVENT_System },
	{ 286, 14, "SYSSE_TYPEWRITER", FALSE, JACEVENT_System },
	{ 287, 15, "SYSSE_UNPAUSE", FALSE, JACEVENT_System },
	{ 288, 16, "SYSSE_CONTAINER_OK", FALSE, JACEVENT_System },
	{ 289, 17, "SYSSE_JUNGLE", FALSE, JACEVENT_System },
	{ 290, 18, "SYSSE_PARTS_APPEAR", FALSE, JACEVENT_System },
	{ 291, 19, "SYSSE_SELECT_MOVE", FALSE, JACEVENT_System },
	{ 292, 20, "SYSSE_SELECT_DECIDE", FALSE, JACEVENT_System },
	{ 293, 21, "SYSSE_TIME_SIGNAL", FALSE, JACEVENT_System },
	{ 294, 22, "SYSSE_SELECT_COURSEOPEN", FALSE, JACEVENT_System },
	{ 295, 23, "SYSSE_MESSAGE_CLOSE", FALSE, JACEVENT_System },
	{ 296, 26, "SYSSE_CARDACCESS", FALSE, JACEVENT_System },
	{ 297, 27, "SYSSE_CARDOK", FALSE, JACEVENT_System },
	{ 298, 28, "SYSSE_CARDERROR", FALSE, JACEVENT_System },
	{ 299, 29, "SYSSE_TIME_SMALLSIGNAL", FALSE, JACEVENT_System },
	{ 300, 32, "SYSSE_CHG_HISCORE", FALSE, JACEVENT_System },
	{ 301, 6, "YMENU ON", FALSE, JACEVENT_System },
	{ 302, 7, "YMENU OFF", FALSE, JACEVENT_System },
	{ 303, 8, "YMENU SELECT", FALSE, JACEVENT_System },
	{ 304, 33, "SYSSE_YMENU_ZOOMIN", FALSE, JACEVENT_System },
	{ 305, 34, "SYSSE_YMENU_ZOOMOUT", FALSE, JACEVENT_System },
	{ 306, 35, "SYSSE_YMENU_SCROLL", FALSE, JACEVENT_System },
	{ 307, 37, "Sound Config", FALSE, JACEVENT_System },
	{ 308, 23, "YMENU SELECT", FALSE, JACEVENT_System },

	// PLAYER sounds
	{ 309, 2, "SE_ORIMA_TOUCHPLANTS", FALSE, JACEVENT_Player },
	{ 310, 3, "SE_PIKI_PULLING", FALSE, JACEVENT_Player },
	{ 311, 4, "SE_PIKI_PULLED2", FALSE, JACEVENT_Player },
	{ 312, 5, "SE_PLAYER_PUNCH", FALSE, JACEVENT_Player },
	{ 313, 6, "SE_THROW", FALSE, JACEVENT_Player },
	{ 314, 7, "SE_BREAKUP", FALSE, JACEVENT_Player },
	{ 315, 8, "SE_GATHER", FALSE, JACEVENT_Player },
	{ 316, 9, "SE_MOVEOBJ", FALSE, JACEVENT_Player },
	{ 317, 10, "SE_DAMAGED", FALSE, JACEVENT_Player },
	{ 318, 11, "SE_FIRED", FALSE, JACEVENT_Player },
	{ 319, 12, "SE_PLAYER_DOWN", FALSE, JACEVENT_Player },
	{ 320, 13, "SE_PLAYER_TOUCHHONEY", FALSE, JACEVENT_Player },

	// MISC PIKI SOUNDS?
	{ 321, 0x8001, "SE_THROWHIT", FALSE, JACEVENT_Player },
	{ 322, 0x8002, "SE_PIKI_FLY", FALSE, JACEVENT_Player },
	{ 323, 0x8003, "SE_BREAKUP_PIKI_VOICE", FALSE, JACEVENT_Player },
	{ 324, 0x8004, "SE_PIKI_FLYREADY", FALSE, JACEVENT_Player },
	{ 325, 0x8005, "SE_PIKI_CALLED", FALSE, JACEVENT_Player },
	{ 326, 0x8006, "SE_PIKI_FIND", FALSE, JACEVENT_Player },
	{ 327, 0x8007, "SE_PIKI_PULLED", FALSE, JACEVENT_Player },
	{ 328, 0x8008, "SE_PIKI_WATERDROP", FALSE, JACEVENT_Player },
	{ 329, 0x8009, "SE_PIKI_ATTACHENEMY", FALSE, JACEVENT_Player },
	{ 330, 0x800a, "SE_KINOKOPIKI_ATTACK", FALSE, JACEVENT_Player },
};

/**
 * --INFO--
 * Address:	800A3C5C
 * Size:	000070
 */
SeContext::SeContext()
{
	mEventHandle = -1;
	mGameObj     = nullptr;
	mEventType   = -1;
	mSourceListenerOffset.set(0.0f, 0.0f, 0.0f);
	mSourcePosition.set(0.0f, 0.0f, 0.0f);
	mClock = 0;
}

/**
 * --INFO--
 * Address:	800A3CCC
 * Size:	000068
 */
SeContext::SeContext(Creature* obj, int eventType)
{
	mEventHandle = -1;
	mGameObj     = obj;
	mEventType   = eventType;
	mSourceListenerOffset.set(0.0f, 0.0f, 0.0f);
	mSourcePosition.set(0.0f, 0.0f, 0.0f);
	mClock = 0;
}

/**
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
	mSourceListenerOffset.set(0.0f, 0.0f, 0.0f);
	mSourcePosition.set(0.0f, 0.0f, 0.0f);
	mClock = 0;
}

/**
 * --INFO--
 * Address:	........
 * Size:	000044
 */
Vector3f SeContext::getPos()
{
	if (mGameObj) {
		return mGameObj->mPosition;
	}
	return mSourcePosition;
}

/**
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

/**
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void SeContext::createEvent(int eventType)
{
	mEventType = eventType;
	seSystem->calcCameraPos(getPos(), mSourceListenerOffset);
	mEventHandle = seSystem->createEvent(this, mEventType, (SVector_*)&mSourceListenerOffset);
}

/**
 * --INFO--
 * Address:	800A3DD0
 * Size:	0000D4
 */
void SeContext::playSound(int soundID)
{
	int jacID = seSystem->getJacID(soundID);
	if (mEventHandle == -1) {
		createEvent(mEventType);
	}

	if (mEventHandle != -1) {
		Jac_PlayEventAction(mEventHandle, jacID);
		mClock = seSystem->mClock;
	}
}

/**
 * --INFO--
 * Address:	800A3EA4
 * Size:	000048
 */
void SeContext::stopSound(int soundID)
{
	int jacID = seSystem->getJacID(soundID);
	if (mEventHandle != -1) {
		Jac_StopEventAction(mEventHandle, jacID);
	}
}

/**
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
	seSystem->calcCameraPos(getPos(), mSourceListenerOffset);
	Jac_UpdateEventPosition(mEventHandle, (SVector_*)&mSourceListenerOffset);
}

/**
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

/**
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void SeContext::dump()
{
	PRINT("\towner %x(%s) handle %d eventType %d pos( %.1f %.1f %.1f )\n", mGameObj,
	      mGameObj ? ObjType::getName(mGameObj->mObjType) : "<pos>", mEventHandle, mEventType, mSourceListenerOffset.x,
	      mSourceListenerOffset.y, mSourceListenerOffset.z);
}

/**
 * --INFO--
 * Address:	800A3FD8
 * Size:	000120
 */
SeSystem::SeSystem()
{
	mIsClosed            = true;
	mCurrentContextCount = 0;
	mMaxContextCount     = MAX_SOUND_EVENTS;
	mContexts            = new SeContext[mMaxContextCount];
	mMaxEventCount       = MAX_SOUND_EVENTS;
	mEvents              = new Event[mMaxEventCount];
	mMaxSoundID          = SE_COUNT;
	mCameraMtx.makeIdentity();
	mSoundParams = new SeConstant;
	gameflow.addGenNode("SE Constatns", mSoundParams); // nice typo.
	mUnusedDistance = 700.0f;
	initEvent();
	mIsBossBGMActive = false;
	mClock           = 0;
}

/**
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

/**
 * --INFO--
 * Address:	800A4184
 * Size:	000078
 */
void SeSystem::resetSystem()
{
	initEvent();
}

/**
 * --INFO--
 * Address:	800A41FC
 * Size:	00020C
 */
int SeSystem::createEvent(SeContext* context, int eventType, SVector_* soundOffset)
{
	if (mIsClosed) {
		return -1;
	}

	int newHandle = -1;
	if (mCurrentEventCount < mMaxEventCount) {
		// we have space for a new event, just make it.
		int handle = Jac_CreateEvent(eventType, soundOffset);
		if (handle == -1) {
			// we failed to make an event, better print everything.
			dumpEvents();
			for (int x = 0; x < 10; x++) { }
			newHandle = -1;

		} else {
			// set up a new event to store the information
			Event* evt = &mEvents[mCurrentEventCount];
			mCurrentEventCount++;
			evt->mHandle  = handle;
			evt->mContext = context;
			newHandle     = handle;
		}
	} else {
		// we have too many sound events happening, filter out the farthest one away.
		int farthestEventIdx = -1;
		f32 distance         = soundOffset->x * soundOffset->x + soundOffset->y * soundOffset->y + soundOffset->z * soundOffset->z;
		for (int i = 0; i < mMaxEventCount; i++) {
			SeContext* ctx = mEvents[i].mContext;
			if (ctx) {
				// active sound effect, check how far away it is
				f32 camDist = ctx->mSourceListenerOffset.x * ctx->mSourceListenerOffset.x
				            + ctx->mSourceListenerOffset.y * ctx->mSourceListenerOffset.y
				            + ctx->mSourceListenerOffset.z * ctx->mSourceListenerOffset.z;
				if (camDist > distance) {
					// new farthest sound effect, track the index
					distance         = camDist;
					farthestEventIdx = i;
				}
			}
		}

		if (farthestEventIdx != -1) {
			// another event is further away than our new one, release it and replace it
			bool isReleased = mEvents[farthestEventIdx].mContext->releaseEvent();
			int eventHandle = Jac_CreateEvent(eventType, soundOffset);
			if (eventHandle == -1 && isReleased) {
				// we freed up a handle but still didn't make a new one, panic and print everything.
				dumpEvents();
				for (int x = 0; x < 10; x++) { }
			}
			// add new event to our list
			mEvents[mCurrentEventCount].mHandle  = eventHandle;
			mEvents[mCurrentEventCount].mContext = context;
			mCurrentEventCount++;
			context->mEventHandle = eventHandle;
			context->mEventType   = eventType;
			newHandle             = eventHandle;
		}
	}

	STACK_PAD_VAR(1);
	return newHandle;
}

/**
 * --INFO--
 * Address:	800A4408
 * Size:	00002C
 */
void SeSystem::playPikiSound(int id, Vector3f& sourcePos)
{
	playSoundDirect(JACEVENT_Piki, id, sourcePos);
}

/**
 * --INFO--
 * Address:	800A4434
 * Size:	000394
 */
void SeSystem::playSoundDirect(int eventType, int sound, Vector3f& sourcePos)
{
	if (mIsClosed) {
		PRINT("seSystem は閉店です!\n");
		ERROR("seSystem closed\n");
	}

	int index   = -1;
	f32 minDist = 200.0f;

	for (int i = 0; i < mCurrentEventCount; i++) {
		// check if we have an event of the same type within 200 units of the new sound that we can overwrite
		Event* event = &mEvents[i];
		if (event->mContext && event->mContext->mEventType == eventType) {
			Vector3f sep = event->mContext->getPos() - sourcePos;
			f32 dist     = sep.length();
			if (dist <= minDist) {
				index   = i;
				minDist = dist;
			}
		}
	}

	if (index != -1) {
		// change the nearest event of the same type to our new sound
		mEvents[index].mContext->playSound(sound);
		return;
	}

	SeContext& ctxToReuse = mContexts[mCurrentContextCount];
	int sysSeContext      = mCurrentContextCount;
	mCurrentContextCount  = (mCurrentContextCount + 1) % mMaxContextCount;
	ctxToReuse.releaseEvent();
	ctxToReuse.setContext(nullptr, eventType);
	ctxToReuse.setPosition(sourcePos);
	ctxToReuse.playSound(sound);

	PRINT(" ** [ReUse] sysSeContext %d\n", sysSeContext);
}

/**
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

	int eventIndex = getEvent(context);
	if (eventIndex != -1) {
		PRINT("♪♪♪♪♪♪♪♪ try to erase %d event\n", eventIndex);
		int before = Jac_CheckFreeEvents();
		Jac_DestroyEvent(handle);
		if (before == Jac_CheckFreeEvents()) {
			// bad! we should have more free events!
			// i'm so angry i'm gonna loop 10 times for nothing.
			for (int i = 0; i < 10; i++) { }
		}

		mCurrentEventCount--;

		for (int i = eventIndex; i < mCurrentEventCount; i++) {
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

	STACK_PAD_VAR(2);
}

/**
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

/**
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

/**
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

/**
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

	sprintf(str, "-- se events -- %d/%d (%.1f %.1f %.1f): clock %d", mCurrentEventCount, mMaxEventCount, mListenerPosition.x,
	        mListenerPosition.y, mListenerPosition.z, mClock);
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

/**
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

	u32 test[0x20];
	u32 max = Jac_GetActiveEvents(test);
	Jac_CheckFreeEvents();

	for (int i = 0; i < max; i++) {
		// probably something like this
		PRINT("%d", test[i]);
	}
}

/**
 * --INFO--
 * Address:	800A4E58
 * Size:	000368
 */
void SeSystem::update(Graphics& gfx, Vector3f& listenerPos)
{
	if (mIsClosed) {
		PRINT("... seSystem closed\n");
		return;
	}
	mListenerPosition = listenerPos;
	mCameraMtx        = gfx.mCamera->mLookAtMtx;

	Vector3f vec1, vec2;
	Jac_UpdateCamera((SVector_*)&vec1, (SVector_*)&vec2);
	for (int i = 0; i < mMaxContextCount; i++) {
		mContexts[i].update();
	}

	if (bossMgr && naviMgr && naviMgr->getNavi()) {
		Navi* navi = naviMgr->getNavi();
		Iterator it(bossMgr);
		Boss* nearestBoss = nullptr;
		f32 maxDist       = seSystem->mSoundParams->mParms.mBossBGMEndDist();
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

		if (mIsBossBGMActive) {
			if (!nearestBoss || maxDist >= seSystem->mSoundParams->mParms.mBossBGMEndDist()) {
				Jac_ExitBossMode();
				mIsBossBGMActive = false;
			}
		} else {
			if (nearestBoss && maxDist <= seSystem->mSoundParams->mParms.mBossBGMStartDist()) {
				Jac_EnterBossMode();
				mIsBossBGMActive = true;
			}
		}
	} else if (mIsBossBGMActive) {
		Jac_ExitBossMode();
		mIsBossBGMActive = false;
	}
}

/**
 * --INFO--
 * Address:	800A51C8
 * Size:	0000FC
 */
void SeSystem::calcCameraPos(Vector3f& objectPos, Vector3f& normalisedCamDir)
{
	Vector3f tmpDir         = objectPos;
	Vector3f tmpListenerPos = mListenerPosition;

	// transform positions to camera coordinates
	tmpDir.multMatrix(mCameraMtx);
	tmpListenerPos.multMatrix(mCameraMtx);

	// get direction from listener to sound source
	tmpDir = tmpDir - tmpListenerPos;

	// normalise it to units of "per cutoff distance"
	tmpDir           = tmpDir * (1.0f / seSystem->mSoundParams->mParms.mSECutoffDist());
	normalisedCamDir = tmpDir;
}

/**
 * --INFO--
 * Address:	800A52C4
 * Size:	000018
 */
int SeSystem::getJacID(int soundID)
{
	if (soundID < 0 || soundID > mMaxSoundID) {
		PRINT("soundID = %d\n", soundID);
		ERROR("go to HELL!\n"); // rude.
	}
	return soundTable[soundID].mJacID;
}

/**
 * --INFO--
 * Address:	........
 * Size:	000018
 */
char* SeSystem::getSoundName(int soundID)
{
	if (soundID < 0 || soundID > mMaxSoundID) {
		PRINT("soundID = %d\n", soundID);
		ERROR("go to HELL!\n"); // rude.
	}
	return soundTable[soundID].mSeName;
}

/**
 * --INFO--
 * Address:	........
 * Size:	000018
 */
int SeSystem::getEventType(int soundID)
{
	if (soundID < 0 || soundID > mMaxSoundID) {
		PRINT("soundID = %d\n", soundID);
		ERROR("go to HELL!\n"); // rude.
	}
	return soundTable[soundID].mEventType;
}

/**
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool SeSystem::isLoopType(int soundID)
{
	if (soundID < 0 || soundID > mMaxSoundID) {
		PRINT("soundID = %d\n", soundID);
		ERROR("go to HELL!\n"); // rude.
	}
	return soundTable[soundID].mLoopType == TRUE;
}

/**
 * --INFO--
 * Address:	800A52DC
 * Size:	000098
 */
void SeSystem::exitCourse()
{
	PRINT("*** BEFORE EXIT COUSE ***\n");
	mIsClosed = true;
	dumpEvents();
	mIsBossBGMActive = false;
	initEvent();
	mIsClosed = true;
}

/**
 * --INFO--
 * Address:	800A5374
 * Size:	000034
 */
void SeSystem::playSysSe(int soundID)
{
	Jac_PlaySystemSe(seSystem->getJacID(soundID));
}

/**
 * --INFO--
 * Address:	800A53A8
 * Size:	000034
 */
void SeSystem::stopSysSe(int soundID)
{
	Jac_StopSystemSe(seSystem->getJacID(soundID));
}

/**
 * --INFO--
 * Address:	800A53DC
 * Size:	000034
 */
void SeSystem::playPlayerSe(int soundID)
{
	Jac_PlayOrimaSe(seSystem->getJacID(soundID));
}

/**
 * --INFO--
 * Address:	800A5410
 * Size:	000034
 */
void SeSystem::stopPlayerSe(int soundID)
{
	Jac_StopOrimaSe(seSystem->getJacID(soundID));
}
