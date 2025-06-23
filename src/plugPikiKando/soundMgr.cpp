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
	{ SE_BATTLE_START, 0, "SE_BATTLE_START", TRUE, JACEVENT_Battle },
	{ SE_CHAPPY_WALK, 1, "SE_CHAPPY_WALK", FALSE, JACEVENT_Battle },
	{ SE_CHAPPY_DIE, 2, "SE_CHAPPY_DIE", FALSE, JACEVENT_Battle },
	{ SE_CHAPPY_SWING, 3, "SE_CHAPPY_SWING", FALSE, JACEVENT_Battle },
	{ SE_CHAPPY_SLEEP, 4, "SE_CHAPPY_SLEEP", FALSE, JACEVENT_Battle },
	{ SE_CHAPPY_BITE, 5, "SE_CHAPPY_BITE", FALSE, JACEVENT_Battle },
	{ SE_CHAPPY_EAT, 6, "SE_CHAPPY_EAT", FALSE, JACEVENT_Battle },
	{ SE_CHAPPY_DOWN, 7, "SE_CHAPPY_DOWN", FALSE, JACEVENT_Battle },
	{ SE_CHAPPY_FOOTDAMAGE, 8, "SE_CHAPPY_FOOTDAMAGE", FALSE, JACEVENT_Battle },
	{ SE_CHAPPY_BITE2, 9, "SE_CHAPPY_BITE2", FALSE, JACEVENT_Battle },
	{ SE_FLOG_WALK, 10, "SE_FLOG_WALK", FALSE, JACEVENT_Battle },
	{ SE_FLOG_DIE, 11, "SE_FLOG_DIE", FALSE, JACEVENT_Battle },
	{ SE_FLOG_FALL, 12, "SE_FLOG_FALL", FALSE, JACEVENT_Battle },
	{ SE_FLOG_HIJUMP, 13, "SE_FLOG_HIJUMP", FALSE, JACEVENT_Battle },
	{ SE_FLOG_JUMP, 14, "SE_FLOG_JUMP", FALSE, JACEVENT_Battle },
	{ SE_FLOG_DOWN, 15, "SE_FLOG_DOWN", FALSE, JACEVENT_Battle },
	{ SE_FLOG_LAND, 16, "SE_FLOG_LAND", FALSE, JACEVENT_Battle },
	{ SE_FLOG_VOICE, 17, "SE_FLOG_VOICE", FALSE, JACEVENT_Battle },
	{ SE_FLOG_ATTACK, 18, "SE_FLOG_ATTACK", FALSE, JACEVENT_Battle },
	{ SE_FLOG_EAT, 19, "SE_FLOG_EAT", FALSE, JACEVENT_Battle },
	{ SE_FLOG_WATERJUMP, 20, "SE_FLOG_WATERJUMP", FALSE, JACEVENT_Battle },
	{ SE_FLOG_WATERLAND, 21, "SE_FLOG_WATERLAND", FALSE, JACEVENT_Battle },
	{ SE_PIKI_EATEN, 22, "SE_PIKI_EATEN", FALSE, JACEVENT_Battle },
	{ SE_PIKI_ATTACK_VOICE, 23, "SE_PIKI_ATTACK_VOICE", FALSE, JACEVENT_Battle },
	{ SE_MISSHIT, 24, "SE_MISSHIT", FALSE, JACEVENT_Battle },
	{ SE_PIKI_ATTACK_HIT, 25, "SE_PIKI_ATTACK_HIT", FALSE, JACEVENT_Battle },
	{ SE_PIKI_DAMAGED, 26, "SE_PIKI_DAMAGED", FALSE, JACEVENT_Battle },
	{ SE_PIKI_PRESSED, 27, "SE_PIKI_PRESSED", FALSE, JACEVENT_Battle },
	{ SE_WALL_HIT, 30, "SE_WALL_HIT", FALSE, JACEVENT_Battle },
	{ SE_SOFTWALL_HIT, 46, "SE_SOFTWALL_HIT", FALSE, JACEVENT_Battle },
	{ SE_WALL_DOWN, 47, "SE_WALL_DOWN", FALSE, JACEVENT_Battle },
	{ SE_BOMB, 31, "SE_BOMB", FALSE, JACEVENT_Battle },
	{ SE_MINIC_WALK, 32, "SE_MINIC_WALK", FALSE, JACEVENT_Battle },
	{ SE_MINIC_FOOTDAMAGE, 33, "SE_MINIC_FOOTDAMAGE", FALSE, JACEVENT_Battle },
	{ SE_MINIC_DIE, 34, "SE_MINIC_DIE", FALSE, JACEVENT_Battle },
	{ SE_MINIC_SWING, 35, "SE_MINIC_SWING", FALSE, JACEVENT_Battle },
	{ SE_MINIC_BITE, 36, "SE_MINIC_BITE", FALSE, JACEVENT_Battle },
	{ SE_MINIC_EAT, 37, "SE_MINIC_EAT", FALSE, JACEVENT_Battle },
	{ SE_MINIC_DOWN, 38, "SE_MINIC_DOWN", FALSE, JACEVENT_Battle },
	{ SE_MINIC_ALERT, 39, "SE_MINIC_ALERT", FALSE, JACEVENT_Battle },
	{ SE_SNAKE_APPEAR, 53, "SE_SNAKE_APPEAR", FALSE, JACEVENT_Battle },
	{ SE_SPIDER_WALK, 48, "SE_SPIDER_WALK", FALSE, JACEVENT_Battle },
	{ SE_SPIDER_LAND, 49, "SE_SPIDER_LAND", FALSE, JACEVENT_Battle },
	{ SE_SPIDER_SWING, 50, "SE_SPIDER_SWING", FALSE, JACEVENT_Battle },
	{ SE_SPIDER_DEAD, 51, "SE_SPIDER_DEAD", FALSE, JACEVENT_Battle },
	{ SE_SPIDER_BOMB, 52, "SE_SPIDER_BOMB", FALSE, JACEVENT_Battle },
	{ SE_FLOWER_DOWN, 41, "SE_FLOWER_DOWN", FALSE, JACEVENT_Battle },
	{ SE_FLOWER_CONVULSION, 42, "SE_FLOWER_CONVULSION", FALSE, JACEVENT_Battle },
	{ SE_FLOWER_GROW0, 43, "SE_FLOWER_GROW0", FALSE, JACEVENT_Battle },
	{ SE_FLOWER_GROW1, 44, "SE_FLOWER_GROW1", FALSE, JACEVENT_Battle },
	{ SE_FLOWER_GROW2, 45, "SE_FLOWER_GROW2", FALSE, JACEVENT_Battle },
	{ SE_PIKI_DEAD, 28, "SE_PIKI_DEAD", FALSE, JACEVENT_Battle },
	{ SE_SNAKE_DIG, 54, "SE_SNAKE_DIG", FALSE, JACEVENT_Battle },
	{ SE_SNAKE_SHOUT, 55, "SE_SNAKE_SHOUT", FALSE, JACEVENT_Battle },
	{ SE_SNAKE_EAT, 56, "SE_SNAKE_EAT", FALSE, JACEVENT_Battle },
	{ SE_SNAKE_DRINK, 57, "SE_SNAKE_DRINK", FALSE, JACEVENT_Battle },
	{ SE_SNAKE_TURN, 58, "SE_SNAKE_TURN", FALSE, JACEVENT_Battle },
	{ SE_SNAKE_MOGAKU, 59, "SE_SNAKE_MOGAKU", FALSE, JACEVENT_Battle },
	{ SE_SNAKE_DEAD1, 60, "SE_SNAKE_DEAD1", FALSE, JACEVENT_Battle },
	{ SE_SNAKE_DEAD2, 61, "SE_SNAKE_DEAD2", FALSE, JACEVENT_Battle },
	{ SE_TANK_FIRE, 62, "SE_TANK_FIRE", FALSE, JACEVENT_Battle },
	{ SE_TANK_BREATH, 63, "SE_TANK_BREATH", FALSE, JACEVENT_Battle },
	{ SE_TANK_WALK, 64, "SE_TANK_WALK", FALSE, JACEVENT_Battle },
	{ SE_TANK_SWING, 65, "SE_TANK_SWING", FALSE, JACEVENT_Battle },
	{ SE_TANK_DAMAGE, 66, "SE_TANK_DAMAGE", FALSE, JACEVENT_Battle },
	{ SE_TANK_DEAD1, 67, "SE_TANK_DEAD1", FALSE, JACEVENT_Battle },
	{ SE_TANK_DEAD2, 68, "SE_TANK_DEAD2", FALSE, JACEVENT_Battle },
	{ SE_MUSH_WALK, 69, "SE_MUSH_WALK", FALSE, JACEVENT_Battle },
	{ SE_MUSH_FLIP, 70, "SE_MUSH_FLIP", FALSE, JACEVENT_Battle },
	{ SE_MUSH_TUMBLE, 71, "SE_MUSH_TUMBLE", FALSE, JACEVENT_Battle },
	{ SE_MUSH_GETUP, 72, "SE_MUSH_GETUP", FALSE, JACEVENT_Battle },
	{ SE_MUSH_LAND, 73, "SE_MUSH_LAND", FALSE, JACEVENT_Battle },
	{ SE_MUSH_TAME, 74, "SE_MUSH_TAME", FALSE, JACEVENT_Battle },
	{ SE_MUSH_SPORE, 75, "SE_MUSH_SPORE", FALSE, JACEVENT_Battle },
	{ SE_MUSH_DAMAGE, 76, "SE_MUSH_DAMAGE", FALSE, JACEVENT_Battle },
	{ SE_MUSH_DEAD1, 77, "SE_MUSH_DEAD1", FALSE, JACEVENT_Battle },
	{ SE_MUSH_DEAD2, 78, "SE_MUSH_DEAD2", FALSE, JACEVENT_Battle },
	{ SE_KING_WALK, 79, "SE_KING_WALK", FALSE, JACEVENT_Battle },
	{ SE_KING_READY, 80, "SE_KING_READY", FALSE, JACEVENT_Battle },
	{ SE_KING_BERO1, 81, "SE_KING_BERO1", FALSE, JACEVENT_Battle },
	{ SE_KING_BERO2, 82, "SE_KING_BERO2", FALSE, JACEVENT_Battle },
	{ SE_KING_GEPPU, 83, "SE_KING_GEPPU", FALSE, JACEVENT_Battle },
	{ SE_KING_DRINK, 84, "SE_KING_DRINK", FALSE, JACEVENT_Battle },
	{ SE_KING_EAT, 85, "SE_KING_EAT", FALSE, JACEVENT_Battle },
	{ SE_KING_CHEEK, 86, "SE_KING_CHEEK", FALSE, JACEVENT_Battle },
	{ SE_KING_NAME, 87, "SE_KING_NAME", FALSE, JACEVENT_Battle },
	{ SE_KING_HIP, 88, "SE_KING_HIP", FALSE, JACEVENT_Battle },
	{ SE_KING_DEAD1, 89, "SE_KING_DEAD1", FALSE, JACEVENT_Battle },
	{ SE_KING_DEAD2, 90, "SE_KING_DEAD2", FALSE, JACEVENT_Battle },
	{ SE_KING_APPEAR, 91, "SE_KING_APPEAR", FALSE, JACEVENT_Battle },
	{ SE_KING_SINK, 92, "SE_KING_SINK", FALSE, JACEVENT_Battle },
	{ SE_KABUTO_BREATH, 93, "SE_KABUTO_BREATH", FALSE, JACEVENT_Battle },
	{ SE_KABUTO_TUMARI, 94, "SE_KABUTO_TUMARI", FALSE, JACEVENT_Battle },
	{ SE_KABUTO_OPEN, 95, "SE_KABUTO_OPEN", FALSE, JACEVENT_Battle },
	{ SE_KABUTO_SHOT, 96, "SE_KABUTO_SHOT", FALSE, JACEVENT_Battle },
	{ SE_KABUTO_FLIP, 97, "SE_KABUTO_FLIP", FALSE, JACEVENT_Battle },
	{ SE_KABUTO_WALK, 98, "SE_KABUTO_WALK", FALSE, JACEVENT_Battle },
	{ SE_KABUTO_COOLDOWN, 99, "SE_KABUTO_COOLDOWN", FALSE, JACEVENT_Battle },
	{ SE_KABUTO_OVERHEAT, 100, "SE_KABUTO_OVERHEAT", FALSE, JACEVENT_Battle },
	{ SE_KABUTO_DEAD, 101, "SE_KABUTO_DEAD", FALSE, JACEVENT_Battle },
	{ SE_ROCK_ROLL, 102, "SE_ROCK_ROLL", FALSE, JACEVENT_Battle },
	{ SE_ROCK_BREAK, 103, "SE_ROCK_BREAK", FALSE, JACEVENT_Battle },
	{ SE_ROCK_GENERATOR, 104, "SE_ROCK_GENERATOR", FALSE, JACEVENT_Battle },
	{ SE_SHELL_CLOSE, 105, "SE_SHELL_CLOSE", FALSE, JACEVENT_Battle },
	{ SE_SHELL_READY, 106, "SE_SHELL_READY", FALSE, JACEVENT_Battle },
	{ SE_SHELL_TRESURE, 107, "SE_SHELL_TRESURE", FALSE, JACEVENT_Battle },
	{ SE_SHELL_OPEN, 108, "SE_SHELL_OPEN", FALSE, JACEVENT_Battle },
	{ SE_SHELL_EAT, 109, "SE_SHELL_EAT", FALSE, JACEVENT_Battle },
	{ SE_KINOKOPIKI_MORPH, 110, "SE_KINOKOPIKI_MORPH", FALSE, JACEVENT_Battle },
	{ SE_KINOKOPIKI_DANCE, 111, "SE_KINOKOPIKI_DANCE", FALSE, JACEVENT_Battle },
	{ SE_COLLEC_BREATH, 112, "SE_COLLEC_BREATH", FALSE, JACEVENT_Battle },
	{ SE_COLLEC_PULL, 113, "SE_COLLEC_PULL", FALSE, JACEVENT_Battle },
	{ SE_COLLEC_WALK, 114, "SE_COLLEC_WALK", FALSE, JACEVENT_Battle },
	{ SE_COLLEC_SWING, 115, "SE_COLLEC_SWING", FALSE, JACEVENT_Battle },
	{ SE_COLLEC_DEAD, 116, "SE_COLLEC_DEAD", FALSE, JACEVENT_Battle },
	{ SE_COLLEC_DOWN, 117, "SE_COLLEC_DOWN", FALSE, JACEVENT_Battle },
	{ SE_COLLEC_CRY, 118, "SE_COLLEC_CRY", FALSE, JACEVENT_Battle },
	{ SE_COLLEC_DAMAGE, 119, "SE_COLLEC_DAMAGE", FALSE, JACEVENT_Battle },
	{ SE_KOGANE_WALK, 120, "SE_KOGANE_WALK", FALSE, JACEVENT_Battle },
	{ SE_KOGANE_DAMAGE, 121, "SE_KOGANE_DAMAGE", FALSE, JACEVENT_Battle },
	{ SE_SARAI_HOVER, 122, "SE_SARAI_HOVER", FALSE, JACEVENT_Battle },
	{ SE_SARAI_DAMAGE, 123, "SE_SARAI_DAMAGE", FALSE, JACEVENT_Battle },
	{ SE_SARAI_ATTACK, 124, "SE_SARAI_ATTACK", FALSE, JACEVENT_Battle },
	{ SE_SARAI_DEAD, 125, "SE_SARAI_DEAD", FALSE, JACEVENT_Battle },
	{ SE_WALLEAT_WALK, 126, "SE_WALLEAT_WALK", FALSE, JACEVENT_Battle },
	{ SE_WALLEAT_NIP, 127, "SE_WALLEAT_NIP", FALSE, JACEVENT_Battle },
	{ SE_WALLEAT_EAT, 128, "SE_WALLEAT_EAT", FALSE, JACEVENT_Battle },
	{ SE_WALLEAT_APPEAR, 129, "SE_WALLEAT_APPEAR", FALSE, JACEVENT_Battle },
	{ SE_MAR_FLY, 130, "SE_MAR_FLY", FALSE, JACEVENT_Battle },
	{ SE_MAR_BREATH, 131, "SE_MAR_BREATH", FALSE, JACEVENT_Battle },
	{ SE_MAR_WIND, 132, "SE_MAR_WIND", FALSE, JACEVENT_Battle },
	{ SE_MAR_DROP, 133, "SE_MAR_DROP", FALSE, JACEVENT_Battle },
	{ SE_MAR_DEAD1, 134, "SE_MAR_DEAD1", FALSE, JACEVENT_Battle },
	{ SE_MAR_DEAD2, 135, "SE_MAR_DEAD2", FALSE, JACEVENT_Battle },
	{ SE_MIURIN_WALK, 136, "SE_MIURIN_WALK", FALSE, JACEVENT_Battle },
	{ SE_MIURIN_PUNCH, 137, "SE_MIURIN_PUNCH", FALSE, JACEVENT_Battle },
	{ SE_MIURIN_SING, 138, "SE_MIURIN_SING", FALSE, JACEVENT_Battle },
	{ SE_KURIONE_HIT, 139, "SE_KURIONE_HIT", FALSE, JACEVENT_Battle },
	{ SE_KURIONE_ESCAPE, 140, "SE_KURIONE_ESCAPE", FALSE, JACEVENT_Battle },
	{ SE_KURIONE_WATER, 141, "SE_KURIONE_WATER", FALSE, JACEVENT_Battle },
	{ SE_KURIONE_FLYING, 142, "SE_KURIONE_FLYING", FALSE, JACEVENT_Battle },
	{ SE_SLIME_WALK, 143, "SE_SLIME_WALK", FALSE, JACEVENT_Battle },
	{ SE_SLIME_HIT_SMALL, 144, "SE_SLIME_HIT_SMALL", FALSE, JACEVENT_Battle },
	{ SE_SLIME_HIT_MID, 145, "SE_SLIME_HIT_MID", FALSE, JACEVENT_Battle },
	{ SE_SLIME_HIT_LARGE, 146, "SE_SLIME_HIT_LARGE", FALSE, JACEVENT_Battle },
	{ SE_SLIME_DEAD, 147, "SE_SLIME_DEAD", FALSE, JACEVENT_Battle },
	{ SE_SLIME_EXT1, 148, "SE_SLIME_EXT1", FALSE, JACEVENT_Battle },
	{ SE_SLIME_EXT2, 149, "SE_SLIME_EXT2", FALSE, JACEVENT_Battle },
	{ SE_SLIME_EXT3, 150, "SE_SLIME_EXT3", FALSE, JACEVENT_Battle },
	{ SE_SLIME_DISAPPEAR, 151, "SE_SLIME_DISAPPEAR", FALSE, JACEVENT_Battle },
	{ SE_DORORO_WALK, 152, "SE_DORORO_WALK", FALSE, JACEVENT_Battle },
	{ SE_DORORO_CRY, 153, "SE_DORORO_CRY", FALSE, JACEVENT_Battle },
	{ SE_DORORO_DEAD, 154, "SE_DORORO_DEAD", FALSE, JACEVENT_Battle },
	{ SE_DORORO_SWING, 155, "SE_DORORO_SWING", FALSE, JACEVENT_Battle },
	{ SE_DORORO_EGG_CRASH, 156, "SE_DORORO_EGG_CRASH", FALSE, JACEVENT_Battle },
	{ SE_DORORO_CRASH, 157, "SE_DORORO_CRASH", FALSE, JACEVENT_Battle },
	{ SE_PONGASHI_THROWIN, 158, "SE_PONGASHI_THROWIN", FALSE, JACEVENT_Battle },
	{ SE_PONGASHI_CLOSE, 159, "SE_PONGASHI_CLOSE", FALSE, JACEVENT_Battle },
	{ SE_PONGASHI_EAT, 160, "SE_PONGASHI_EAT", FALSE, JACEVENT_Battle },
	{ SE_PONGASHI_SHOT, 161, "SE_PONGASHI_SHOT", FALSE, JACEVENT_Battle },
	{ SE_PONGASHI_DEAD, 162, "SE_PONGASHI_DEAD", FALSE, JACEVENT_Battle },
	{ SE_PONGASHI_TOUCH, 163, "SE_PONGASHI_TOUCH", FALSE, JACEVENT_Battle },
	{ SE_NAMAZU_WALK, 164, "SE_NAMAZU_WALK", FALSE, JACEVENT_Battle },
	{ SE_NAMAZU_EAT, 165, "SE_NAMAZU_EAT", FALSE, JACEVENT_Battle },
	{ SE_NAMAZU_DEAD, 166, "SE_NAMAZU_DEAD", FALSE, JACEVENT_Battle },
	{ SE_OTAMA_JUMP, 167, "SE_OTAMA_JUMP", FALSE, JACEVENT_Battle },
	{ SE_OTAMA_DEAD, 168, "SE_OTAMA_DEAD", FALSE, JACEVENT_Battle },
	{ SE_OTAMA_WATERJUMP, 169, "SE_OTAMA_WATERJUMP", FALSE, JACEVENT_Battle },
	{ SE_GEYSER_NORMAL, 170, "SE_GEYSER_NORMAL", FALSE, JACEVENT_Battle },
	{ SE_GEYSER_SPOUT, 171, "SE_GEYSER_SPOUT", FALSE, JACEVENT_Battle },

	// WORK OBJECT SOUNDS
	{ SEB_SOFTWALL_HIT, 0, "SEB_SOFTWALL_HIT", FALSE, JACEVENT_Build },
	{ SEB_WALL_DOWN, 1, "SEB_WALL_DOWN", FALSE, JACEVENT_Build },
	{ SEB_HARDESTWALL_HIT, 2, "SEB_HARDESTWALL_HIT", FALSE, JACEVENT_Build },
	{ SEB_CONSTRUCTION, 3, "SEB_CONSTRUCTION", FALSE, JACEVENT_Build },
	{ SEB_BOXMOVE, 4, "SEB_BOXMOVE", FALSE, JACEVENT_Build },
	{ SEB_HARDWALL_HIT, 5, "SEB_HARDWALL_HIT", FALSE, JACEVENT_Build },
	{ SEB_STONE_HIT, 6, "SEB_STONE_HIT", FALSE, JACEVENT_Build },
	{ SEB_STONE_BREAK, 7, "SEB_STONE_BREAK", FALSE, JACEVENT_Build },
	{ SEB_GRASS_PULL, 8, "SEB_GRASS_PULL", FALSE, JACEVENT_Build },
	{ SEB_BRIDGE_EXTEND, 9, "SEB_BRIDGE_EXTEND", FALSE, JACEVENT_Build },

	// SOME PIKI SOUNDS
	{ SEW_PIKI_WATERDROP, 0, "SEW_PIKI_WATERDROP", FALSE, JACEVENT_PikiWater },
	{ SEW_PIKI_DROWN, 1, "SEW_PIKI_DROWN", FALSE, JACEVENT_PikiWater },
	{ SEW_PIKI_DEAD, 2, "SEW_PIKI_DEAD", FALSE, JACEVENT_PikiWater },
	{ SEW_PIKI_SINK, 3, "SEW_PIKI_SINK", FALSE, JACEVENT_PikiWater },

	// SHIP PART SOUNDS
	{ SE_LIFT_TRY, 0, "SE_LIFT_TRY", TRUE, JACEVENT_Pellet },
	{ SE_LIFT_MOVE, 1, "SE_LIFT_MOVE", TRUE, JACEVENT_Pellet },
	{ SE_PIKI_LIFT, 2, "SE_PIKI_LIFT", TRUE, JACEVENT_Pellet },
	{ SE_PELLET_BORN, 3, "SE_PELLET_BORN", FALSE, JACEVENT_Pellet },
	{ SE_PELLET_BOUND, 4, "SE_PELLET_BOUND", FALSE, JACEVENT_Pellet },
	{ SE_UFOPARTS_BOUND, 5, "SE_UFOPARTS_BOUND", FALSE, JACEVENT_Pellet },
	{ SE_UFOPARTS_OTHER, 6, "SE_UFOPARTS_OTHER", TRUE, JACEVENT_Pellet },
	{ SE_UFOPARTS_ENGINE, 7, "SE_UFOPARTS_ENGINE", TRUE, JACEVENT_Pellet },
	{ SE_UFOPARTS_GEAR, 8, "SE_UFOPARTS_GEAR", TRUE, JACEVENT_Pellet },
	{ SE_UFOPARTS_RADER, 9, "SE_UFOPARTS_RADER", TRUE, JACEVENT_Pellet },
	{ SE_UFOPARTS_SPRING, 10, "SE_UFOPARTS_SPRING", TRUE, JACEVENT_Pellet },
	{ SE_UFOPARTS_BATTERY, 11, "SE_UFOPARTS_BATTERY", TRUE, JACEVENT_Pellet },
	{ SE_UFOPARTS_ZENMAI, 12, "SE_UFOPARTS_ZENMAI", TRUE, JACEVENT_Pellet },
	{ SE_UFOPARTS_MONEYBOX, 13, "SE_UFOPARTS_MONEYBOX", TRUE, JACEVENT_Pellet },

	{ dummy1, 7, "dummy 1", TRUE, JACEVENT_Pellet },
	{ dummy2, 7, "dummy 2", TRUE, JACEVENT_Pellet },
	{ dummy3, 7, "dummy 3", TRUE, JACEVENT_Pellet },
	{ dummy4, 7, "dummy 4", TRUE, JACEVENT_Pellet },
	{ dummy5, 7, "dummy 5", TRUE, JACEVENT_Pellet },

	// ONION SOUNDS
	{ SE_CONTAINER_PELLETIN, 0, "SE_CONTAINER_PELLETIN", FALSE, JACEVENT_Onyon },
	{ SE_CONTAINER_PIKIBORN, 1, "SE_CONTAINER_PIKIBORN", FALSE, JACEVENT_Onyon },
	{ SE_PIKI_GROW1, 2, "SE_PIKI_GROW1", FALSE, JACEVENT_Onyon },
	{ SE_PIKI_GROW2, 3, "SE_PIKI_GROW2", FALSE, JACEVENT_Onyon },
	{ SE_PIKI_GROW3, 4, "SE_PIKI_GROW3", FALSE, JACEVENT_Onyon },
	{ SE_PIKI_GROW4, 5, "SE_PIKI_GROW4", FALSE, JACEVENT_Onyon },
	{ SE_PIKI_GROW5, 6, "SE_PIKI_GROW5", FALSE, JACEVENT_Onyon },
	{ SE_PIKI_GOHOME, 7, "SE_PIKI_GOHOME", FALSE, JACEVENT_Onyon },
	{ SE_PIKI_OUTHOME, 8, "SE_PIKI_OUTHOME", FALSE, JACEVENT_Onyon },
	{ SE_PIKI_GROW0, 9, "SE_PIKI_GROW0", FALSE, JACEVENT_Onyon },
	{ SE_PIKI_GROW0_WATER, 10, "SE_PIKI_GROW0_WATER", FALSE, JACEVENT_Onyon },
	{ SE_CONTAINER_PELLETIN2, 11, "SE_CONTAINER_PELLETIN2", FALSE, JACEVENT_Onyon },
	{ SE_CONTAINER_PIKI, 12, "SE_CONTAINER_PIKI", FALSE, JACEVENT_Onyon },
	{ SE_CONTAINER_HANABI, 13, "SE_CONTAINER_HANABI", FALSE, JACEVENT_Onyon },
	{ SE_CONTAINER_CLIMB, 14, "SE_CONTAINER_CLIMB", FALSE, JACEVENT_Onyon },

	// UFO SOUNDS
	{ SE_UFO_PARTSIN, 0, "SE_UFO_PARTSIN", FALSE, JACEVENT_Ufo },
	{ SE_UFO_PARTSSET1, 1, "SE_UFO_PARTSSET1", FALSE, JACEVENT_Ufo },
	{ SE_UFO_PARTSSET2, 2, "SE_UFO_PARTSSET2", FALSE, JACEVENT_Ufo },
	{ SE_UFO_PARTSSET3, 3, "SE_UFO_PARTSSET3", FALSE, JACEVENT_Ufo },
	{ SE_UFO_IDLING, 4, "SE_UFO_IDLING", FALSE, JACEVENT_Ufo },
	{ SE_UFO_SPARK, 5, "SE_UFO_SPARK", FALSE, JACEVENT_Ufo },
	{ SE_UFO_DESTROY, 6, "SE_UFO_DESTROY", TRUE, JACEVENT_Ufo },
	{ SE_UFO_SATELLITE, 7, "SE_UFO_SATELLITE", TRUE, JACEVENT_Ufo },
	{ SE_UFO_LIGHT, 8, "SE_UFO_LIGHT", TRUE, JACEVENT_Ufo },
	{ SE_UFO_ANTENNA, 9, "SE_UFO_ANTENNA", TRUE, JACEVENT_Ufo },
	{ SE_UFO_RADER, 10, "SE_UFO_RADER", TRUE, JACEVENT_Ufo },
	{ SE_UFO_LIGHT2, 11, "SE_UFO_LIGHT2", TRUE, JACEVENT_Ufo },
	{ SE_UFO_ENGINE, 12, "SE_UFO_ENGINE", TRUE, JACEVENT_Ufo },

	// PIKI SOUNDS
	{ SEF_PIKI_KINOKO2, 0, "SEF_PIKI_KINOKO2", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_AKUBI, 1, "SEF_PIKI_AKUBI", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_BURUBURU, 2, "SEF_PIKI_BURUBURU", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_CRASH, 3, "SEF_PIKI_CRASH", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_DEAD1, 4, "SEF_PIKI_DEAD1", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_DEAD2, 5, "SEF_PIKI_DEAD2", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_DEAD3, 6, "SEF_PIKI_DEAD3", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_FALL, 7, "SEF_PIKI_FALL", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_GAKKARI, 8, "SEF_PIKI_GAKKARI", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_HANG, 9, "SEF_PIKI_HANG", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_JUMP1, 10, "SEF_PIKI_JUMP1", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_JUMP2, 11, "SEF_PIKI_JUMP2", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_JUMP3, 12, "SEF_PIKI_JUMP3", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_SNEEZE, 13, "SEF_PIKI_SNEEZE", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_SLEEP, 14, "SEF_PIKI_SLEEP", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_NOBI, 15, "SEF_PIKI_NOBI", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_ANGRY1, 16, "SEF_PIKI_ANGRY1", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_ANGRY2, 17, "SEF_PIKI_ANGRY2", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_OTTOTTO, 18, "SEF_PIKI_OTTOTTO", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_SKIP, 19, "SEF_PIKI_SKIP", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_SLIP1, 20, "SEF_PIKI_SLIP1", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_SLIP2, 21, "SEF_PIKI_SLIP2", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_LAND, 22, "SEF_PIKI_LAND", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_YATTA, 23, "SEF_PIKI_YATTA", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_BREAKUP, 24, "SEF_PIKI_BREAKUP", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_CALLED, 25, "SEF_PIKI_CALLED", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_FIND, 26, "SEF_PIKI_FIND", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_FIRED, 27, "SEF_PIKI_FIRED", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_DRINK, 28, "SEF_PIKI_DRINK", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_WATERED, 29, "SEF_PIKI_WATERED", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_ATTACK_VOICE, 31, "SEF_PIKI_ATTACK_VOICE", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_MISSHIT, 32, "SEF_PIKI_MISSHIT", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_ATTACK_HIT, 33, "SEF_PIKI_ATTACK_HIT", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_DAMAGED, 34, "SEF_PIKI_DAMAGED", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_GROW1, 35, "SEF_PIKI_GROW1", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_GROW2, 36, "SEF_PIKI_GROW2", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_GROW3, 37, "SEF_PIKI_GROW3", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_GROW4, 30, "SEF_PIKI_GROW4", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_GROW5, 38, "SEF_PIKI_GROW5", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_GROW0, 39, "SEF_PIKI_GROW0", FALSE, JACEVENT_Piki },
	{ SEF_PIKI_GROW0_WATER, 40, "SEF_PIKI_GROW0_WATER", FALSE, JACEVENT_Piki },

	// SYSTEM SOUNDS
	{ SYSSE_ALLSTOP, 0, "SYSSE_ALLSTOP", FALSE, JACEVENT_System },
	{ SYSSE_DECIDE1, 1, "SYSSE_DECIDE1", FALSE, JACEVENT_System },
	{ SYSSE_MOVE1, 2, "SYSSE_MOVE1", FALSE, JACEVENT_System },
	{ SYSSE_PAUSE, 3, "SYSSE_PAUSE", FALSE, JACEVENT_System },
	{ SYSSE_EVENING_ALERT, 4, "SYSSE_EVENING_ALERT", FALSE, JACEVENT_System },
	{ SYSSE_COUNTDOWN, 5, "SYSSE_COUNTDOWN", FALSE, JACEVENT_System },
	{ SYSSE_CMENU_ON, 6, "SYSSE_CMENU_ON", FALSE, JACEVENT_System },
	{ SYSSE_CMENU_OFF, 7, "SYSSE_CMENU_OFF", FALSE, JACEVENT_System },
	{ SYSSE_CMENU_SELECT, 8, "SYSSE_CMENU_SELECT", FALSE, JACEVENT_System },
	{ SYSSE_CMENU_ERROR, 9, "SYSSE_CMENU_ERROR", FALSE, JACEVENT_System },
	{ SYSSE_ORIMA_LIFEDIM, 10, "SYSSE_ORIMA_LIFEDIM", FALSE, JACEVENT_System },
	{ SYSSE_WORK_FINISH, 11, "SYSSE_WORK_FINISH", FALSE, JACEVENT_System },
	{ SYSSE_VIEW_CHANGE, 12, "SYSSE_VIEW_CHANGE", FALSE, JACEVENT_System },
	{ SYSSE_CANCEL, 13, "SYSSE_CANCEL", FALSE, JACEVENT_System },
	{ SYSSE_TYPEWRITER, 14, "SYSSE_TYPEWRITER", FALSE, JACEVENT_System },
	{ SYSSE_UNPAUSE, 15, "SYSSE_UNPAUSE", FALSE, JACEVENT_System },
	{ SYSSE_CONTAINER_OK, 16, "SYSSE_CONTAINER_OK", FALSE, JACEVENT_System },
	{ SYSSE_JUNGLE, 17, "SYSSE_JUNGLE", FALSE, JACEVENT_System },
	{ SYSSE_PARTS_APPEAR, 18, "SYSSE_PARTS_APPEAR", FALSE, JACEVENT_System },
	{ SYSSE_SELECT_MOVE, 19, "SYSSE_SELECT_MOVE", FALSE, JACEVENT_System },
	{ SYSSE_SELECT_DECIDE, 20, "SYSSE_SELECT_DECIDE", FALSE, JACEVENT_System },
	{ SYSSE_TIME_SIGNAL, 21, "SYSSE_TIME_SIGNAL", FALSE, JACEVENT_System },
	{ SYSSE_SELECT_COURSEOPEN, 22, "SYSSE_SELECT_COURSEOPEN", FALSE, JACEVENT_System },
	{ SYSSE_MESSAGE_CLOSE, 23, "SYSSE_MESSAGE_CLOSE", FALSE, JACEVENT_System },
	{ SYSSE_CARDACCESS, 26, "SYSSE_CARDACCESS", FALSE, JACEVENT_System },
	{ SYSSE_CARDOK, 27, "SYSSE_CARDOK", FALSE, JACEVENT_System },
	{ SYSSE_CARDERROR, 28, "SYSSE_CARDERROR", FALSE, JACEVENT_System },
	{ SYSSE_TIME_SMALLSIGNAL, 29, "SYSSE_TIME_SMALLSIGNAL", FALSE, JACEVENT_System },
	{ SYSSE_CHG_HISCORE, 32, "SYSSE_CHG_HISCORE", FALSE, JACEVENT_System },
	{ YMENU_ON, 6, "YMENU ON", FALSE, JACEVENT_System },
	{ YMENU_OFF, 7, "YMENU OFF", FALSE, JACEVENT_System },
	{ YMENU_SELECT, 8, "YMENU SELECT", FALSE, JACEVENT_System },
	{ SYSSE_YMENU_ZOOMIN, 33, "SYSSE_YMENU_ZOOMIN", FALSE, JACEVENT_System },
	{ SYSSE_YMENU_ZOOMOUT, 34, "SYSSE_YMENU_ZOOMOUT", FALSE, JACEVENT_System },
	{ SYSSE_YMENU_SCROLL, 35, "SYSSE_YMENU_SCROLL", FALSE, JACEVENT_System },
	{ Sound_Config, 37, "Sound Config", FALSE, JACEVENT_System },
	{ YMENU_SELECT2, 23, "YMENU SELECT", FALSE, JACEVENT_System },

	// PLAYER sounds
	{ SE_ORIMA_TOUCHPLANTS, 2, "SE_ORIMA_TOUCHPLANTS", FALSE, JACEVENT_Player },
	{ SE_PIKI_PULLING, 3, "SE_PIKI_PULLING", FALSE, JACEVENT_Player },
	{ SE_PIKI_PULLED2, 4, "SE_PIKI_PULLED2", FALSE, JACEVENT_Player },
	{ SE_PLAYER_PUNCH, 5, "SE_PLAYER_PUNCH", FALSE, JACEVENT_Player },
	{ SE_THROW, 6, "SE_THROW", FALSE, JACEVENT_Player },
	{ SE_BREAKUP, 7, "SE_BREAKUP", FALSE, JACEVENT_Player },
	{ SE_GATHER, 8, "SE_GATHER", FALSE, JACEVENT_Player },
	{ SE_MOVEOBJ, 9, "SE_MOVEOBJ", FALSE, JACEVENT_Player },
	{ SE_DAMAGED, 10, "SE_DAMAGED", FALSE, JACEVENT_Player },
	{ SE_FIRED, 11, "SE_FIRED", FALSE, JACEVENT_Player },
	{ SE_PLAYER_DOWN, 12, "SE_PLAYER_DOWN", FALSE, JACEVENT_Player },
	{ SE_PLAYER_TOUCHHONEY, 13, "SE_PLAYER_TOUCHHONEY", FALSE, JACEVENT_Player },

	// MISC PIKI SOUNDS?
	{ SE_THROWHIT, 0x8001, "SE_THROWHIT", FALSE, JACEVENT_Player },
	{ SE_PIKI_FLY, 0x8002, "SE_PIKI_FLY", FALSE, JACEVENT_Player },
	{ SE_BREAKUP_PIKI_VOICE, 0x8003, "SE_BREAKUP_PIKI_VOICE", FALSE, JACEVENT_Player },
	{ SE_PIKI_FLYREADY, 0x8004, "SE_PIKI_FLYREADY", FALSE, JACEVENT_Player },
	{ SE_PIKI_CALLED, 0x8005, "SE_PIKI_CALLED", FALSE, JACEVENT_Player },
	{ SE_PIKI_FIND, 0x8006, "SE_PIKI_FIND", FALSE, JACEVENT_Player },
	{ SE_PIKI_PULLED, 0x8007, "SE_PIKI_PULLED", FALSE, JACEVENT_Player },
	{ SE_PIKI_WATERDROP, 0x8008, "SE_PIKI_WATERDROP", FALSE, JACEVENT_Player },
	{ SE_PIKI_ATTACHENEMY, 0x8009, "SE_PIKI_ATTACHENEMY", FALSE, JACEVENT_Player },
	{ SE_KINOKOPIKI_ATTACK, 0x800a, "SE_KINOKOPIKI_ATTACK", FALSE, JACEVENT_Player },
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
