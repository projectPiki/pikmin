#include "ObjType.h"

#include "stl/string.h"

ObjType _info[] = {
	// index, name
	{ OBJTYPE_Piki, "piki" },
	{ OBJTYPE_Teki, "teki" },
	{ OBJTYPE_Navi, "navi" },
	{ OBJTYPE_Water, "water" },
	{ OBJTYPE_Seed, "seed" },
	{ OBJTYPE_Key, "key" },
	{ OBJTYPE_Door, "door" },
	{ OBJTYPE_Gate, "gate" },
	{ OBJTYPE_FallWater, "fall water" },
	{ OBJTYPE_Gem5, "gem5" },
	{ OBJTYPE_Gem10, "gem10" },
	{ OBJTYPE_Gem20, "gem20" },
	{ OBJTYPE_Gem50, "gem50" },
	{ OBJTYPE_Gem1, "gem1" },
	{ OBJTYPE_GemItem, "never use this" },
	{ OBJTYPE_BombGen, "bomb gen" },
	{ OBJTYPE_Bomb, "bomb" },
	{ OBJTYPE_Pikihead, "pikihead" },
	{ OBJTYPE_Goal, "goal" },
	{ OBJTYPE_Fulcrum, "fulcrum" },
	{ OBJTYPE_Rope, "rope" },
	{ OBJTYPE_Ivy, "ivy" },
	{ OBJTYPE_TestCylinder, "cylinder test" },
	{ OBJTYPE_SluiceSoft, "sluice soft" },
	{ OBJTYPE_SluiceHard, "sluice hard" },
	{ OBJTYPE_SluiceBomb, "sluice bomb" },
	{ OBJTYPE_SluiceBombHard, "sluice bombhard" },
	{ OBJTYPE_Rocket, "rocket" },
	{ OBJTYPE_TestDual, "dual test" },
	{ OBJTYPE_SunsetStart, "<demo:sunset> start" },
	{ OBJTYPE_SunsetGoal, "<demo:sunset> goal" },
	{ OBJTYPE_Kusa, "kusa" },
	{ OBJTYPE_Ufo, "ufo" },
	{ OBJTYPE_Weeds, "weeds" },
	{ OBJTYPE_Weed, "<weed>" },
	{ OBJTYPE_RockGen, "rockgen" },
	{ OBJTYPE_GrassGen, "grassgen" },
	{ OBJTYPE_Fish, "fish" },
	{ OBJTYPE_BoBase, "<bo base>" },
	{ OBJTYPE_Secret1, "secret1" },
	{ OBJTYPE_WorkObject, "workobject" },
	{ OBJTYPE_Spider, "boss:Spider" },
	{ OBJTYPE_Giant, "boss:Giant" },
	{ OBJTYPE_Snake, "boss:Snake" },
	{ OBJTYPE_TwSnake, "boss:TwSnake" },
	{ OBJTYPE_King, "boss:King" },
	{ OBJTYPE_Slime, "boss:Slime" },
	{ OBJTYPE_Kogane, "boss:Kogane" },
	{ OBJTYPE_Pom, "boss:Pom" },
	{ OBJTYPE_KingBack, "boss:KingBack" },
	// OBJTYPE_Nucleus is intentionally omitted here.  Well, maybe not by the original devs.
	{ OBJTYPE_Mizu, "boss:Mizu" },
	{ OBJTYPE_XXX3, "boss:XXX3" },
	{ OBJTYPE_Plant, "PLANT" },
	{ OBJTYPE_Pellet, "PELLET" },
	{ OBJTYPE_NULL, "" }
};

/*
 * --INFO--
 * Address:	80094A38
 * Size:	000048
 */
immut char* ObjType::getName(int index)
{
	for (int slot = 0; _info[slot].mIndex != OBJTYPE_NULL; slot++) {
		if (index == _info[slot].mIndex) {
			return _info[slot].mName;
		}
	}
	return "invalid objname";
}

/*
 * --INFO--
 * Address:	80094A80
 * Size:	000094
 */
int ObjType::getIndex(immut char* name)
{
	for (int slot = 0; _info[slot].mIndex != OBJTYPE_NULL; slot++) {
		if (strcmp(name, _info[slot].mName) == 0) {
			return _info[slot].mIndex;
		}
	}
	return OBJTYPE_INVALID;
}
