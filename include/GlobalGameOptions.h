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
 * @brief In "stages.ini", the `id` field.  In the `StageInfo` class, the `mStageID` member.
 */
enum StageID {
	STAGE_Practice  = 0, // Impact Site
	STAGE_Forest    = 1, // Forest of Hope
	STAGE_Cave      = 2, // Forest Navel
	STAGE_Yakushima = 3, // Distant Spring
	STAGE_Last      = 4, // Final Trial
	STAGE_COUNT,         // Count of Story Mode stages (excluding test maps)

	STAGE_START   = STAGE_Practice, // First valid Story Mode stage
	STAGE_TESTMAP = STAGE_COUNT,    // Default value of `StageInfo::mStageID`; used to indicate test maps.
	STAGE_COUNT_INCLUDING_TESTMAPS, // Count of Story Mode stages (including test maps)
};

/**
 * @brief In "stages.ini", the `chid` field.  In the `StageInfo` class, the `mChalStageID` member.
 *
 * @note All challenge mode stages must share a stage ID with their story mode counterparts due to coding decisions.
 * However, having a separate enum is lexically clearer when reading code around unlocking or checking stages.
 */
enum ChalStageID {
	CHALSTAGE_Practice  = STAGE_Practice,  // Impact Site
	CHALSTAGE_Forest    = STAGE_Forest,    // Forest of Hope
	CHALSTAGE_Cave      = STAGE_Cave,      // Forest Navel
	CHALSTAGE_Yakushima = STAGE_Yakushima, // Distant Spring
	CHALSTAGE_Last      = STAGE_Last,      // Final Trial
	CHALSTAGE_COUNT,                       // Count of Challenge Mode stages

	CHALSTAGE_START = CHALSTAGE_Practice,  // First valid Challenge Mode stage
	CHALSTAGE_NOT   = CHALSTAGE_COUNT + 2, // Default value of `StageInfo::mChalStageID`; used to indicate it is not a Challenge Mode stage.
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
