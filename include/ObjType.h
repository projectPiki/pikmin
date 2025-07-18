#ifndef _OBJTYPE_H
#define _OBJTYPE_H

#include "types.h"

enum EObjType {
	OBJTYPE_INVALID      = -1, // Invalid object
	OBJTYPE_Piki         = 0,  // Pikmin
	OBJTYPE_Water        = 1,
	OBJTYPE_Seed         = 2,
	OBJTYPE_Key          = 3,
	OBJTYPE_Door         = 4,
	OBJTYPE_Gate         = 5,
	OBJTYPE_FallWater    = 6,
	OBJTYPE_Gem5         = 7,  // 5-pellet
	OBJTYPE_Gem10        = 8,  // 10-pellet
	OBJTYPE_Gem20        = 9,  // 20-pellet
	OBJTYPE_Gem50        = 10, // 50-pellet
	OBJTYPE_Gem1         = 11, // 1-pellet
	OBJTYPE_GemItem      = 12, // unused
	OBJTYPE_BombGen      = 13,
	OBJTYPE_Bomb         = 14,
	OBJTYPE_Pikihead     = 15,
	OBJTYPE_Goal         = 16,
	OBJTYPE_Fulcrum      = 17,
	OBJTYPE_Rope         = 18,
	OBJTYPE_Ivy          = 19,
	OBJTYPE_TestCylinder = 20,
	OBJTYPE_TestDual     = 21,

	// Sluice = Gate
	OBJTYPE_SluiceSoft     = 22,
	OBJTYPE_SluiceHard     = 23,
	OBJTYPE_SluiceBomb     = 24,
	OBJTYPE_SluiceBombHard = 25,

	OBJTYPE_Rocket      = 26,
	OBJTYPE_SunsetStart = 27,
	OBJTYPE_SunsetGoal  = 28,
	OBJTYPE_Kusa        = 29,
	OBJTYPE_Ufo         = 30,
	OBJTYPE_Weeds       = 31,
	OBJTYPE_Weed        = 32,
	OBJTYPE_RockGen     = 33,
	OBJTYPE_GrassGen    = 34,
	OBJTYPE_BoBase      = 35,
	OBJTYPE_Secret1     = 36,
	OBJTYPE_Fish        = 37,
	OBJTYPE_WorkObject  = 38,

	// Bosses
	OBJTYPE_BossBegin = 39,
	OBJTYPE_Spider    = OBJTYPE_BossBegin,
	OBJTYPE_Giant     = 40,
	OBJTYPE_Snake     = 41,
	OBJTYPE_TwSnake   = 42,
	OBJTYPE_King      = 43,
	OBJTYPE_Slime     = 44,
	OBJTYPE_Kogane    = 45,
	OBJTYPE_Pom       = 46,
	OBJTYPE_KingBack  = 47,
	OBJTYPE_Nucleus   = 48, // both Nucleus and CoreNucleus
	OBJTYPE_Mizu      = 49, // both Mizu and Geyzer
	OBJTYPE_XXX3      = 50,
	OBJTYPE_BossEnd   = OBJTYPE_XXX3,

	OBJTYPE_Plant  = 51, // Plant
	OBJTYPE_Pellet = 52, // Pellet
	OBJTYPE_Navi   = 54, // Captain
	OBJTYPE_Teki   = 55, // Enemy
	OBJTYPE_NULL   = 57,

};

struct ObjType {
	static char* getName(int);
	static int getIndex(char*);

	EObjType mIndex; // _00
	char* mName; // _04
};

#endif
