#ifndef _NEWPIKIGAME_H
#define _NEWPIKIGAME_H

#include "types.h"
#include "LifeGauge.h"
#include "MemStat.h"
#include "Section.h"
#include "MapMgr.h"
#include "jaudio/PikiScene.h"
#include "Interface.h"

extern bool dontShowFrame;
extern int movieIndex;
extern bool gameInfoOn;
extern bool gameInfoIn;

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct NewPikiGameSection : public Section {
	NewPikiGameSection();

	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
};

/**
 * @brief TODO
 */
struct NewPikiGameSetupSection : public BaseGameSection {
	NewPikiGameSetupSection()
	{
		_34 = new IntroGameModeState(this);

		Vector3f v1(0.0f, 0.0f, 0.0f);
		Vector3f v2(0.0f, 0.0f, 0.0f);
		gameflow.mMoviePlayer->setGameCamInfo(false, 60.0f, v2, v1);

		dontShowFrame = false;
		gameflow._340 = 0;
		_3D4          = true;

		lgMgr                   = new LifeGaugeMgr;
		movieIndex              = 0;
		gameflow._1E4           = 0;
		gameflow._1E6           = 0;
		_44                     = 0;
		_54                     = new Controller(2);
		_38                     = nullptr;
		gameInfoIn              = false;
		gameInfoOn              = false;
		gameflow.mGameInterface = new GameMovieInterface(this);

		memStat->start("animCacher");
		gameflow.mFrameCacher = new AnimFrameCacher(5000);
		memStat->end("animCacher");

		flowCont._240 = 0;
		flowCont._23C = 0;
		flowCont._238 = 0;

		gsys->mHeaps[4].init("teki", 2, System::alloc(0x280000), 0x280000); // size 0xa00000 in the DLL
		gsys->mHeaps[5].init("movie", 2, System::alloc(0x40000), 0x40000);

		memStat->start("mapMgr");
		memStat->start("constructor");
		mapMgr = new MapMgr(mController);
		memStat->end("constructor");

		memStat->start("shape");
		createMapObjects(mapMgr);
		memStat->end("shape");
		memStat->end("mapMgr");

		u32 id = flowCont.mCurrentStage->mStageID;
		if (id >= 5) {
			id = 0;
		}
		Jac_SceneSetup(5, id);
		init2Ddata();
		gamecore = new GameCoreSection(mController, mapMgr, _5C);
		add(gamecore);
		flowCont._254 = 0;
		flowCont._258 = 0;
		_3A8.set(96, 128, 255, 0);

		memStat->start("effects");
		mapMgr->initEffects();
		memStat->end("effects");

		memStat->start("mapMgr");
		mapMgr->createLights();
		memStat->end("mapMgr");

		gamecore->initStage();
		_3AC[0].set(0, 0, 48, 255);
		_3AC[1].set(48, 48, 48, 255);
		_3B4[0].set(0, 0, 0, 0);
		_3B4[1].set(64, 64, 192, 255);
		_3BC[0].set(0, 0, 0, 0);
		_3BC[1].set(192, 64, 0, 255);

		_3C4[0] = 150.0f;
		_3C4[1] = 750.0f;
		_3C4[2] = 1000.0f;
		_3C4[3] = 3000.0f;

		int old            = gsys->mTogglePrint != 0;
		gsys->mTogglePrint = 1;
		// PRINT("tekiHeap has %d bytes free\n", gsys->getHeap(4)->getFree());
		gsys->getHeap(4)->getFree();
		gsys->mTogglePrint = old;

		if (playerState->isTutorial()) {
			gameflow.mMoviePlayer->startMovie(3, 0, nullptr, nullptr, nullptr, -1, true);
		} else if (flowCont.mCurrentStage->mStageID < 5) {
			gameflow.mMoviePlayer->startMovie(40, 0, nullptr, nullptr, nullptr, -1, true);
		}
		gsys->setFade(1.0f, 3.0f);
	}

	virtual void update();        // _10
	virtual void draw(Graphics&); // _14
	virtual void openMenu();      // _30

	void init2Ddata();
	void createMapObjects(MapMgr*);

	// _00     = VTBL
	// _00-_44 = BaseGameSection
	int _44;         // _44
	u8 _48[8];       // _48
	Menu* _50;       // _50
	Controller* _54; // _54
	Font* _58;       // _58
	Camera _5C;      // _5C
	f32 _3A4;        // _3A4
	Colour _3A8;     // _3a8
	Colour _3AC[2];  // _3AC
	Colour _3B4[2];  // _3B4
	Colour _3BC[2];  // _3BC
	f32 _3C4[4];     // _3C4
	bool _3D4;       // _3D4
	int _3D8;        // _3D8
	int _3DC;        // _3DC
};

#endif
