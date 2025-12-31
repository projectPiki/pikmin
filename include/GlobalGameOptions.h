#ifndef _GLOBALGAMEOPTIONS_H
#define _GLOBALGAMEOPTIONS_H

#include "types.h"

// NB: raising parts or days over 99 (or field pikis over 999) will cause number display errors
// you'll have to more seriously edit some of the ogawa and yamashita screens if you wanna do that

#define MAX_UFO_PARTS       (30)
#define MAX_PIKI_ON_FIELD   (100)
#define MAX_DAYS            (30)
#define MAX_HI_SCORES       (5)
#define MIN_HAPPY_END_PARTS (25) // NB: also need to edit the hard-coded IDs in PlayerState::getUfoParts

/**
 * @brief IDs for each stage, as per stages.ini.
 *
 * @note There are also test maps and teki stages, but these don't have IDs.
 */
enum StageID {
	STAGE_START,
	STAGE_Practice  = STAGE_START, // Impact Site
	STAGE_Forest    = 1,           // Forest of Hope
	STAGE_Cave      = 2,           // Forest Navel
	STAGE_Yakushima = 3,           // Distant Spring
	STAGE_Last      = 4,           // Final Trial
	STAGE_INVALID   = 5,           // default set on load, invalid
	STAGE_END       = STAGE_INVALID,
	STAGE_COUNT     = STAGE_INVALID,
	STAGE_LASTVALID = STAGE_Last, // last valid loadable stage

	// all challenge mode stages share a stage ID with their story mode counterparts
	// having these is lexically clearer though when reading code around unlocking or checking stages.
	STAGE_ChalPractice  = STAGE_Practice,  // Challenge Mode Impact Site
	STAGE_ChalForest    = STAGE_Forest,    // Challenge Mode Forest of Hope
	STAGE_ChalCave      = STAGE_Cave,      // Challenge Mode Forest Navel
	STAGE_ChalYakushima = STAGE_Yakushima, // Challenge Mode Distant Spring
	STAGE_ChalLast      = STAGE_Last,      // Challenge Mode Final Trial
	STAGE_CHALINVALID   = 7,               // Invalid challenge mode option.

	STAGE_CHALSTART = STAGE_START, // first valid challenge mode level ID
	STAGE_CHALEND   = STAGE_END,
	STAGE_CHALCOUNT = STAGE_COUNT, // number of challenge mode levels
};

/**
 * @brief Identifies the specific color types of Pikmin.
 */
enum PikiColor {
	Blue   = 0,
	Red    = 1,
	Yellow = 2,
	PikiColorCount, // 3 - the total number of distinct Pikmin colors

	PikiMinColor = Blue,
	PikiMaxColor = Yellow,
	PIKI_Kinoko  = 3,
};

/**
 * @brief TODO
 */
enum PikiHappa {
	Leaf   = 0,
	Bud    = 1,
	Flower = 2,
	PikiHappaCount, // 3

	PikiMinHappa = Leaf,
	PikiMaxHappa = Flower,
};

#endif
