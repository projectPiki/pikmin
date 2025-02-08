#ifndef _MAPSELECT_H
#define _MAPSELECT_H

#include "types.h"
#include "Font.h"
#include "Section.h"
#include "Menu.h"
#include "Camera.h"
#include "system.h"
#include "zen/DrawWorldMap.h"
#include "zen/DrawCM.h"
#include "gameflow.h"
#include "Controller.h"

struct Menu;
struct Font;

extern zen::DrawWorldMap* mapWindow;
extern zen::DrawCMcourseSelect* selectWindow;

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct MapSelectSection : public Section {
	MapSelectSection();

	virtual void init(); // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

/**
 * @brief TODO
 */
struct MapSelectSetupSection : public Node {
	MapSelectSetupSection()
	{
		setName("MapSelect section");
		_30   = new Controller;
		_20   = 0;
		mFont = new Font;
		mFont->setTexture(gsys->loadTexture("consFont.bti", true), 16, 8);
		mBigFont = new Font;
		mBigFont->setTexture(gsys->loadTexture("bigFont.bti", true), 21, 42);
		makeMapsMenu();
		mMenu->addOption(0, nullptr, nullptr, true);
		Delegate1<MapSelectSetupSection, Menu&>* delegate;
		if (!gameflow.mIsChallengeMode) {
			delegate = new Delegate1<MapSelectSetupSection, Menu&>(this, openAllMaps);
		} else {
			delegate = new Delegate1<MapSelectSetupSection, Menu&>(this, openAllChMaps);
		}
		mMenu->addOption(0, "Open All Maps", delegate, true);
		_2C = nullptr;

		mapWindow    = nullptr;
		selectWindow = 0;
		if (!gameflow.mIsChallengeMode) {
			mapWindow = new zen::DrawWorldMap;

			bool old           = gsys->mTogglePrint != 0;
			gsys->mTogglePrint = true;
			// PRINT("opening map window with %d : %d\n");
			gsys->mTogglePrint = old;

			mapWindow->start(zen::DrawWorldMap::startModeFlag(gameflow.mLastUnlockedStageId == -1 ? 0 : gameflow.mLastUnlockedStageId),
			                 zen::DrawWorldMap::startPlaceFlag(gameflow._1CC == -1 ? 0 : gameflow._1CC));
		} else {
			gameflow.mWorldClock.mCurrentDay = 1;
			selectWindow                     = new zen::DrawCMcourseSelect;
			selectWindow->start();
		}
		gsys->setFade(1.0f, 3.0f);
		_24 = 0xb0000;
	}

	virtual void update();        // _10 (weak)
	virtual void draw(Graphics&); // _14 (weak)

	void openAllChMaps(Menu&);
	void openAllMaps(Menu&);
	void menuSelectOption(Menu&);
	void makeMapsMenu();

	// _00     = VTBL
	// _00-_20 = Node
	u32 _20;         // _20
	u32 _24;         // _24
	Menu* mMenu;     // _28
	Menu* _2C;       // _2C
	Controller* _30; // _30
	Font* mFont;     // _34
	Font* mBigFont;  // _38
	Camera mCamera;  // _3C
};

#endif
