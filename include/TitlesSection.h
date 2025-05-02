#ifndef _TITLESECTION_H
#define _TITLESECTION_H

#include "types.h"
#include "Section.h"
#include "Camera.h"
#include "Light.h"
#include "Font.h"
#include "sysNew.h"
#include "CinematicPlayer.h"
#include "gameflow.h"
#include "Interface.h"
#include "zen/ogStart.h"
#include "zen/DrawHiScore.h"
#include "zen/ogTitle.h"
#include "Menu.h"
#include "DayMgr.h"

extern zen::ogScrStartMgr* startWindow;
extern zen::ogScrTitleMgr* titleWindow;
extern zen::DrawHiScore* totalWindow;
extern bool startWindowOn;
extern bool titleWindowOn;
extern bool totalWindowOn;

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct TitlesSection : public Section {
	virtual void init(); // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

/**
 * @brief TODO
 */
struct TitleSetupSection : public Node {
	TitleSetupSection()
	    : _A4C("CoreNode")
	    , _A60("CoreNode")
	{
		mLightPool.setName("Titles section");
		_A40.set(0.0f, 20.0f, 0.0f);
		gameflow.mGameInterface = (GameMovieInterface*)(new TitlesMovieInterface);
		_30                     = new Controller;
		_20                     = 0;
		titleWindow             = new zen::ogScrTitleMgr;
		titleWindowOn           = false;
		_A3C                    = new DayMgr(nullptr, _30);
		gameflow.mDemoFlags     = 0;
		_50                     = new CinematicPlayer("cinemas/opening.cin");
		_50->mMtx.makeIdentity();
		_50->_2E4 = 1;

		RandomAccessStream* data = gsys->openFile("cinemas/opening.ini", true, true);
		if (data) {
			CmdStream* stream = new CmdStream(data);
			while (!stream->endOfCmds() && !stream->endOfSection()) {
				stream->getToken(true);
				if (stream->isToken("dayMgr")) {
					stream->getToken(true);
					_A3C->init(stream);
				}
			}
			if (!stream->endOfCmds()) {
				stream->getToken(true);
			}
			data->close();
		}
		_4C  = 0.45f;
		_39C = 1.0f;
		// PRINT("big font!\n");
		// mFont = new Font();
		// mFont->setTexture(gsys->loadTexture("bigFont.bti", true), 21, 42); // DLL exclusive

		mLightPool.initCore("lightPools");
		for (int i = 0; i < 0; i++) {
			LightPool* light = new LightPool;
			light->mFlags    = 0;
			light->mColour.set(255, 255, 64, 64);
			light->mParticleTexture = gsys->loadTexture("effects/halowhit.txe", true);
			light->_65C             = i * 0.7853f;

			switch (i) {
			case 0:
				light->mCamera.mPosition.set(500.0f, 300.0f, -25.0f);
				break;
			case 1:
				light->mCamera.mPosition.set(25.0f, 300.0f, -12.0f);
				break;
			case 2:
				light->mCamera.mPosition.set(500.0f, 300.0f, 500.0f);
				break;
			case 3:
				light->mCamera.mPosition.set(500.0f, 300.0f, -25.0f);
				break;
			case 4:
				light->mCamera.mPosition.set(500.0f, 300.0f, -25.0f);
				break;
			}
			light->mCamera.mPosition.set(0.0f, 0.0f, 0.0f);
			light->mCamera.mFov = 10.0f;
			light->mCamera.mNear += 0.000001f;
			light->mCamera.mFar = 40.0f;
			light->mCamera.mPosition.normalise();

			gameflow.addGenNode("lightPool", light);
			mLightPool.add(light);
		}

		_2C              = 0;
		mMenu            = new Menu(_30, gsys->mConsFont, true);
		mMenu->_48.mMinX = glnWidth / 2;
		mMenu->_48.mMinY = glnHeight / 2 + 30;
		mMenu->addKeyEvent(0x10, 0x1001000, new Delegate1<TitleSetupSection, Menu&>(this, menuSelectOption));
		mMenu->addKeyEvent(0x20, 0x2000, new Delegate1<Menu, Menu&>(mMenu, Menu::menuCloseMenu));

		gameflow.mFrameCacher = new AnimFrameCacher(8000);

		mCamera.mPosition.set(200.0f, 200.0f, 50.0f);
		GameQuickInfo info;
		info.mDay       = 30;
		info.mDeadPikis = 0;
		info.mBornPikis = 0;
		info.mParts     = 0;
		gameflow.mGamePrefs.checkIsHiscore(info);

		// totalWindowOn = false;
		totalWindow   = new zen::DrawHiScore;
		startWindowOn = false;
		startWindow   = new zen::ogScrStartMgr;
		startWindowOn = false;

		gsys->setFade(1.0f, 3.0f);
	}

	virtual void update();        // _10
	virtual void draw(Graphics&); // _14

	void menuSelectOption(Menu&);
	void drawMenu(Graphics&, Menu*, f32);

	// _00     = VTBL
	// _00-_20 = Node (TODO, this struct is still very scuffed)
	int _20;              // _20
	int _24;              // _24
	Menu* mMenu;          // _28
	int _2C;              // _2C
	Controller* _30;      // _30
	Font* mFont;          // _34
	u8 _38[0x14];         // _38
	f32 _4C;              // _4C
	CinematicPlayer* _50; // _50
	Camera mCamera;       // _54
	f32 _39C;             // _39C
	Vector3f _3B4;        // _3B4
	LightPool mLightPool; // _3C4
	DayMgr* _A3C;         // _A3C
	Vector3f _A40;        // _A40
	CoreNode _A4C;        // _A40
	CoreNode _A60;        // _A60
};

#endif
