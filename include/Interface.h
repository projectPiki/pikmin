#ifndef _INTERFACE_H
#define _INTERFACE_H

#include "types.h"

struct Creature;
struct Vector3f;

/**
 * @brief Game movie interface message commands.
 */
enum GameMovieCommand {
	MOVIECMD_TextDemo            = 0,  ///< 0, Open text window. Data should be an `EnumTutorial` value. Reads Part IDs from gameflow.
	MOVIECMD_Unused              = 1,  ///< 1, Unused/error command. No data.
	MOVIECMD_ForceDayEnd         = 2,  ///< 2, Force day to end. No data.
	MOVIECMD_HideHUD             = 3,  ///< 3, Hide game HUD. No data.
	MOVIECMD_ShowHUD             = 4,  ///< 4, Show game HUD. No data.
	MOVIECMD_GameEndCondition    = 5,  ///< 5, Handle extinction or Olimar down. Data should use `GameEndCause` enum.
	MOVIECMD_ForceResults        = 6,  ///< 6, Force results screen - in practice, does nothing. No data.
	MOVIECMD_StartMovie          = 7,  ///< 7, Start movie/cutscene. Data = CinePlayerFlags for movie/cutscene.
	MOVIECMD_EndMovie            = 8,  ///< 8, End current movie. Data should be `CinDemoIDs` value (movie index).
	MOVIECMD_FadeOut             = 9,  ///< 9, Fade screen to black. No data.
	MOVIECMD_FadeIn              = 10, ///< 10, Fade screen back in from black. No data.
	MOVIECMD_CleanupDayEnd       = 11, ///< 11, Clean up day end state - should never be hit. No data.
	MOVIECMD_StartTotalResults   = 12, ///< 12, Start final score screen. No data.
	MOVIECMD_SpecialDayEnd       = 13, ///< 13, Special day end trigger for collecting all the parts. No data.
	MOVIECMD_SetPauseAllowed     = 14, ///< 14, Enable/disable pausing. Data is BOOL for whether the enable pausing (TRUE = enabled).
	MOVIECMD_CountDownLastSecond = 15, ///< 15, Signals the last second of the day, does nothing. No data.
	MOVIECMD_StageFinish         = 16, ///< 16, Forced day end (navi down or extinction). No data.
	MOVIECMD_CreateMenuWindow    = 17, ///< 17, Open radar and controls menu. No data.

#if defined(VERSION_PIKIDEMO)
	MOVIECMD_DemoFinish = 18, ///< 18, Demo Forest of Hope ending - opens happy ending text. No data.
#endif
};

/**
 * @brief Shuttle for passing messages between different game state control structures.
 *
 * @note Size: 0x4.
 */
struct GameInterface {
	virtual void message(int, int) { }                                                       // _08
	virtual void movie(int, int, Creature*, immut Vector3f*, immut Vector3f*, u32, bool) { } // _0C
	virtual void parseMessages() { }                                                         // _10
	virtual void parse(int, int) { }                                                         // _14

	// _00 = VTBL
};

#endif
