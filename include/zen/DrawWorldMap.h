#ifndef _ZEN_DRAWWORLDMAP_H
#define _ZEN_DRAWWORLDMAP_H

#include "OnePlayerSection.h"
#include "P2D/Pane.h"
#include "P2D/Picture.h"
#include "P2D/Screen.h"
#include "PlayerState.h"
#include "SoundMgr.h"
#include "nlib/Math.h"
#include "types.h"
#include "zen/DrawCommon.h"
#include "zen/DrawMenu.h"
#include "zen/DrawWMPause.h"
#include "zen/EffectMgr2D.h"
#include "zen/Number.h"
#include "zen/SpectrumCursorMgr.h"
#include "zen/ogDiary.h"

class Controller;
class Graphics;
class P2DScreen;

namespace zen {
struct EffectMgr2D;
} // namespace zen

namespace {

struct WorldMapTitleObj;

/**
 * @brief Enum for course point ordering in actual game - equivalent to StageID
 *
 * @note Use mapNoGame2Scr to convert to WorldMapScreenID
 */
enum WorldMapName {
	WM_NULL     = -1,
	WM_START    = 0,
	WM_Practice = WM_START, // 0, Impact Site
	WM_Forest,              // 1, Forest of Hope
	WM_Cave,                // 2, Forest Navel
	WM_Yakushima,           // 3, Distant Spring
	WM_Last,                // 4, Final Trial
	WM_COUNT,               // 5
};

/**
 * @brief Enum for course point ordering in WorldMap screen files.
 *
 * @note Use mapNoScr2Game to convert to WorldMapName
 */
enum WorldMapScreenID {
	WMSCR_START     = 0,
	WMSCR_Yakushima = WMSCR_START, // 0, Distant Spring
	WMSCR_Forest,                  // 1, Forest of Hope
	WMSCR_Practice,                // 2, Impact Site
	WMSCR_Cave,                    // 3, Forest Navel
	WMSCR_Last,                    // 4, Final Trial
	WMSCR_COUNT,                   // 5
};

/**
 * @brief Animation states for world map title objects
 */
BEGIN_ENUM_TYPE(TitleAnimState)
enum {
	Idle      = 0, // Title is stationary or hidden
	Appearing = 1, // Title is animating into view
	Hiding    = 2, // Title is animating out of view
} END_ENUM_TYPE;

/**
 * @brief Appearance states for course point animations
 */
BEGIN_ENUM_TYPE(CourseAppearState)
enum {
	Ready          = 0, // Course point is ready/idle
	RocketIncoming = 1, // Rocket is approaching (0.5s timer)
	Exploding      = 2, // Explosion effects playing (1.0s timer)
	Revealing      = 3, // Final reveal animation (1.0s timer)
} END_ENUM_TYPE;

} // namespace

namespace zen {

struct DrawScreen;

/**
 * @brief TODO
 *
 * @note Size: 0x138. In drawWorldMap.cpp.
 */
struct WorldMapCoursePointMgr;

struct WorldMapTitleMgr;

struct WorldMapShootingStarMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x88. In drawWorldMap.cpp.
 */
struct WorldMapConfirmMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x3C. In drawWorldMap.cpp.
 */
struct WorldMapCursorOnyon;

/**
 * @brief TODO
 *
 * @note Size: 0x12C. In drawWorldMap.cpp.
 */
struct WorldMapCursorMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x24. In drawWorldMap.cpp.
 */
struct WorldMapMapImageMgr;

/**
 * @brief TODO
 *
 * @note Size: 0xC. In drawWorldMap.cpp.
 */
struct WorldMapPartsInfoMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x28. In drawWorldMap.cpp.
 */
struct WorldMapWipe;

/**
 * @brief TODO
 *
 * @note Size: 0xB0. In drawWorldMap.cpp.
 */
struct WorldMapWipeMgr;

/**
 * @brief Main operational modes for the world map screen
 */
BEGIN_ENUM_TYPE(DrawWorldMapMode)
enum {
	Null         = -1, // Invalid or uninitialized mode
	Start        = 0,  // Initial setup and transition in
	Appear       = 1,  // Course unlock animation playing
	Operation    = 2,  // Normal user interaction mode
	Paused       = 3,  // Pause menu is open
	Confirm      = 4,  // Course selection confirmation dialog
	DiaryClosing = 5,  // Transitioning to diary
	Diary        = 6,  // Captain's diary is open
	DiaryOpening = 7,  // Returning from diary
	End          = 8,  // Transition out of world map
} END_ENUM_TYPE;

/**
 * @brief TODO
 */
struct DrawWorldMap {
public:
	/**
	 * @brief Type of course unlock animation to play
	 */
	enum startModeFlag {
		None         = 0, // No unlock animation
		ForestUnlock = 1, // Forest of Hope unlock
		CaveUnlock   = 2, // Forest Navel unlock
		SpringUnlock = 3, // Distant Spring unlock
		FinalUnlock  = 4, // Final Trial unlock
	};

	/**
	 * @brief Starting course selection for world map
	 */
	enum startPlaceFlag {
		ImpactSite    = 0, // Start at Impact Site
		ForestHope    = 1, // Start at Forest of Hope
		ForestNavel   = 2, // Start at Forest Navel
		DistantSpring = 3, // Start at Distant Spring
		FinalTrial    = 4, // Start at Final Trial
	};

	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		RET_NULL = -1,      // Invalid or uninitialized flag
		RET_EnterPractice,  // See `DrawWorldMap::modeOperation`
		RET_EnterForest,    // ...
		RET_EnterCave,      // ...
		RET_EnterYakushima, // ...
		RET_EnterLast,      // ...
		RET_Active,         // See `DrawWorldMap::start`
		RET_ReturnToTitle,  // See `DrawWorldMap::update`
	};

	DrawWorldMap();

	bool update(Controller*);
	void draw(Graphics&);
	void start(startModeFlag, startPlaceFlag);

	// unused/inlined:
	~DrawWorldMap();

	// DLL inlines:
	returnStatusFlag getReturnStatusFlag() { return mReturnStatus; }

protected:
	void setCoursePoint(startPlaceFlag);
	bool modeStart(Controller*);
	bool modeAppear(Controller*);
	bool modeOperation(Controller*);
	bool modeConfirm(Controller*);
	bool modeEnd(Controller*);
	void updateScreens();
	void closeMapInfo();
	void openMapInfo();

	startModeFlag mStartMode;                  // _00
	int mCurrentMode;                          // _04
	returnStatusFlag mReturnStatus;            // _08
	f32 mModeTimer;                            // _0C
	DrawScreen* mWipeScreen;                   // _10
	DrawScreen* mIconScreen;                   // _14
	DrawScreen* mTitleScreen;                  // _18
	DrawScreen* mMoniScreen;                   // _1C
	DrawScreen* mData1Screen;                  // _20
	DrawScreen* mData2Screen;                  // _24
	DrawScreen* mPointScreen;                  // _28
	DrawScreen* mLineScreen;                   // _2C
	DrawScreen* mBackScreen;                   // _30
	WorldMapCursorMgr* mCursorMgr;             // _34
	WorldMapCoursePointMgr* mCoursePointMgr;   // _38
	int mTotalPartsNum;                        // _3C
	int mCurrentPartsNum;                      // _40
	int mTotalPikiCounts[PikiColorCount];      // _44, indexed by PikiColor
	EffectMgr2D* mEffectMgr2D;                 // _50
	WorldMapMapImageMgr* mMapImageMgr;         // _54
	WorldMapWipeMgr* mWipeMgr;                 // _58
	WorldMapTitleMgr* mTitleMgr;               // _5C
	WorldMapPartsInfoMgr* mPartsInfoMgr;       // _60
	DrawWMPause mPause;                        // _64
	WorldMapConfirmMgr* mConfirmMgr;           // _70
	ogDrawSelectDiary mSelectDiary;            // _74
	WorldMapShootingStarMgr* mShootingStarMgr; // _364
};

} // namespace zen

#endif
