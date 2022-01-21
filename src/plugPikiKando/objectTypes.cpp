#include "types.h"
#include "string.h"
#include "ObjType.h"

ObjType _info[55] = {
	// index, name
	{ 0, "piki" },
	{ 55, "teki" },
	{ 54, "navi" },
	{ 1, "water" },
	{ 2, "seed" },
	{ 3, "key" },
	{ 4, "door" },
	{ 5, "gate" },
	{ 6, "fall water" },
	{ 7, "gem5" },
	{ 8, "gem10" },
	{ 9, "gem20" },
	{ 10, "gem50" },
	{ 11, "gem1" },
	{ 12, "never use this" },
	{ 13, "bomb gen" },
	{ 14, "bomb" },
	{ 15, "pikihead" },
	{ 16, "goal" },
	{ 17, "fulcrum" },
	{ 18, "rope" },
	{ 19, "ivy" },
	{ 20, "cylinder test" },
	{ 22, "sluice soft" },
	{ 23, "sluice hard" },
	{ 24, "sluice bomb" },
	{ 25, "sluice bombhard" },
	{ 26, "rocket" },
	{ 21, "dual test" },
	{ 27, "<demo:sunset> start" },
	{ 28, "<demo:sunset> goal" },
	{ 29, "kusa" },
	{ 30, "ufo" },
	{ 31, "weeds" },
	{ 32, "<weed>" },
	{ 33, "rockgen" },
	{ 34, "grassgen" },
	{ 37, "fish" },
	{ 35, "<bo base>" },
	{ 36, "secret1" },
	{ 38, "workobject" },
	{ 39, "boss:Spider" },
	{ 40, "boss:Giant" },
	{ 41, "boss:Snake" },
	{ 42, "boss:TwSnake" },
	{ 43, "boss:King" },
	{ 44, "boss:Slime" },
	{ 45, "boss:Kogane" },
	{ 46, "boss:Pom" },
	{ 47, "boss:KingBack" },
	{ 49, "boss:Mizu" },
	{ 50, "boss:XXX3" },
	{ 51, "PLANT" },
	{ 52, "PELLET" },
	{ 57, "" }
};

/*
 * --INFO--
 * Address:	80094A38
 * Size:	000048
 */
char* ObjType::getName(int index)
{
	for (int slot = 0; _info[slot].obj_index != 57; slot++) {

		if (index == _info[slot].obj_index) {
			return _info[slot].obj_name;
		}
	}
	return "invalid objname";
}

/*
 * --INFO--
 * Address:	80094A80
 * Size:	000094
 */
int ObjType::getIndex(char* name)
{
	for (int slot = 0; _info[slot].obj_index != 57; slot++) {

		if (strcmp(name, _info[slot].obj_name) == 0) {
			return _info[slot].obj_index;
		}
	}
	return -1;
}
