#ifndef _ZEN_OGTUTORIAL_H
#define _ZEN_OGTUTORIAL_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DTextBox;

namespace zen {

struct ogScrMessageMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct ogScrTutorialMgr {

	/**
	 * @brief TODO
	 */
	enum EnumTutorial {
		TUT_Awakening          = 0, ///< 0, 'Mezame' (awakening) - crash landing text.
		TUT_RedOnion           = 1, ///< 1, 'Oniyon' - red onion discovery.
		TUT_FirstSeed          = 2, ///< 2, 'FoundPikmin' - first seed made.
		TUT_PullHint           = 3, ///< 3,
		TUT_GetPikmin          = 4, ///< 4,
		TUT_ControlHint        = 5,
		TUT_Pelette            = 6,
		TUT_StoneHint2         = 7,
		TUT_FoundEngine        = 8,
		TUT_GetEngine          = 9,
		TUT_RirikuDemo         = 10,
		TUT_Camera             = 11,
		TUT_OnyonInOut         = 12,
		TUT_Zenmetu            = 13,
		TUT_YellowPikmin       = 14,
		TUT_BluePikmin         = 15,
		TUT_FoundBomb          = 16,
		TUT_GetParts           = 17,
		TUT_PowerUp            = 18,
		TUT_DayEnd             = 19,
		TUT_BombInfo           = 20,
		TUT_Limit100           = 21,
		TUT_Mitu               = 22,
		TUT_Rute               = 23,
		TUT_APunchUFO          = 24,
		TUT_LifeUp             = 25,
		TUT_HitUFO             = 26,
		TUT_FinishUFO          = 27,
		TUT_BadEnding          = 28,
		TUT_HappyEnding        = 29,
		TUT_NukiAndFree        = 30,
		TUT_InfoDisplay        = 31,
		TUT_PartsGetOnlyOffset = 32,
		/// ... [32-61] - discovery text for all 30 ship parts
		TUT_PartsInfoOffset = 62,
		/// ... [62-91] - info/interaction text for all 30 ship parts
		TUT_PartsGetOffset = 92,
		/// ... [92-121] - collection text for all 30 ship parts
		TUT_PartsPower = 122,
		/// ... [122-151] - power-up text for all 30 ship parts
		TUT_Test    = 152,
		TUT_INVALID = 153,
	};

	/**
	 * @brief TODO
	 */
	enum TutorialStatus {
		Status_Null = -1,
		Status_0    = 0,
		Status_1    = 1,
		Status_2    = 2,
		Status_3    = 3,
		Status_4    = 4,
	};

	ogScrTutorialMgr();

	TutorialStatus update(Controller*);
	void draw(Graphics&);
	void start(zen::ogScrTutorialMgr::EnumTutorial);

	// unused/inlined:
	void nextPage();
	void backPage();
	void setCursorXY(P2DTextBox*);

	// DLL inlines:
	ogScrMessageMgr* getScrMsgMgr() { return mMessageMgr; }

	ogScrMessageMgr* mMessageMgr;                  // _00
	zen::ogScrTutorialMgr::TutorialStatus mStatus; // _04
};

extern immut char** bloFiles_Tutorial[];

} // namespace zen

#endif
