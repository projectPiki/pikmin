#ifndef _INTERFACE_H
#define _INTERFACE_H

#include "types.h"

struct Creature;
struct Vector3f;

/**
 * @brief Game movie interface message commands.
 */
enum GameMovieCommand {
	MOVIECMD_TextDemo            = 0,  // Start tutorial window based on context
	MOVIECMD_Unused              = 1,  // Unused/error command
	MOVIECMD_ForceDayEnd         = 2,  // Force day to end
	MOVIECMD_HideHUD             = 3,  // Hide game HUD frames
	MOVIECMD_ShowHUD             = 4,  // Show game HUD frames
	MOVIECMD_GameEndCondition    = 5,  // Handle extinction or Olimar down
	MOVIECMD_ForceResults        = 6,  // Force results screen
	MOVIECMD_StartMovie          = 7,  // Start movie with navi visibility control
	MOVIECMD_EndMovie            = 8,  // End current movie
	MOVIECMD_FadeOut             = 9,  // Fade screen to black
	MOVIECMD_FadeIn              = 10, // Fade screen from black
	MOVIECMD_CleanupDayEnd       = 11, // Clean up day end state
	MOVIECMD_StartTotalResults   = 12, // Start final score screen
	MOVIECMD_SpecialDayEnd       = 13, // Special day end trigger
	MOVIECMD_SetInputEnabled     = 14, // Enable/disable gameplay input
	MOVIECMD_CountDownLastSecond = 15, // Signals the last second of the day
	MOVIECMD_StageFinish         = 16, // Forced day end (navi down or extinction)
	MOVIECMD_CreateMenuWindow    = 17, // Create radar and controls menu
};

/**
 * @brief TODO
 */
struct GameInterface {
	virtual void message(int, int) { }                                           // _08
	virtual void movie(int, int, Creature*, Vector3f*, Vector3f*, u32, bool) { } // _0C
	virtual void parseMessages() { }                                             // _10
	virtual void parse(int, int) { }                                             // _14

	// _00 = VTBL
	// TODO: members
};

#endif
