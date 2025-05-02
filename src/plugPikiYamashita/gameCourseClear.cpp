#include "GameCourseClearSection.h"
#include "zen/DrawHurryUp.h"
#include "zen/DrawContainer.h"
#include "zen/particle.h"
#include "zen/bBoardColourAnim.h"
#include "FlowController.h"
#include "Menu.h"
#include "Graphics.h"
#include "Font.h"
#include "Delegate.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("GameCourseClearSection")

/**
 * @brief TODO
 */
struct GameModeBase {
	GameModeBase(char* name)
	{
		mName = name;
		_04   = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = false;
		if (controller->keyUnClick(_04)) {
			SeSystem::playSysSe(SYSSE_CANCEL);
			res = true;
		}
		return res;
	}
	virtual void draw(Graphics& gfx) { } // _0C

	char* getModeName() { return mName; }

	// _00 = VTBL
	int _04;     // _04
	char* mName; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x10. In gameCourseClear.cpp for PRINT reasons.
 */
struct GameModeMgr {
	GameModeMgr(int count)
	{
		mModeCount = count;
		mModes     = new GameModeBase*[mModeCount];
		for (int i = 0; i < mModeCount; i++) {
			mModes[i] = nullptr;
		}
		mState         = 0;
		mCurrentSelect = 0;
	}

	bool updateSelect(Controller* controller)
	{
		bool res = false;
		mCurrentSelect += controller->keyUnClick(KBBTN_MSTICK_DOWN) - controller->keyUnClick(KBBTN_MSTICK_UP);
		if (mCurrentSelect < 0) {
			mCurrentSelect += mModeCount;
		}
		if (mCurrentSelect >= mModeCount) {
			mCurrentSelect -= mModeCount;
		}
		if (controller->keyUnClick(KBBTN_A)) {
			SeSystem::playSysSe(SYSSE_DECIDE1);
			res = true;
		}

		return res;
	}
	void drawSelect(Graphics& gfx, Font* font)
	{
		Matrix4f mtx;
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

		for (int i = 0; i < mModeCount; i++) {
			if (mCurrentSelect == i) {
				gfx.setColour(Colour(192, 64, 255, 255), true);
				gfx.setAuxColour(Colour(64, 64, 192, 255));
			} else {
				gfx.setColour(Colour(192, 255, 255, 255), true);
				gfx.setAuxColour(Colour(200, 215, 192, 255));
			}

			char* name = mModes[i]->getModeName();
			gfx.texturePrintf(font, 320 - font->stringWidth(name) / 2, i * font->stringHeight(name) + 70, name);
		}
	}

	// DLL inlines:
	bool update(Controller* controller)
	{
		switch (mState) {
		case 0:
			if (updateSelect(controller)) {
				mState = 1;
			}
			break;

		case 1:
			if (mModes[mCurrentSelect]->update(controller)) {
				mState = 0;
			}
			break;

		default:
			ERROR("ITTE YOSI!\n");
			break;
		}

		return false;
	}
	void draw(Graphics& gfx, Font* font)
	{
		switch (mState) {
		case 0:
			drawSelect(gfx, font);
			break;

		case 1:
			mModes[mCurrentSelect]->draw(gfx);
			break;

		default:
			ERROR("ITTE YOSI!\n");
			break;
		}
	}
	void setGameMode(int idx, GameModeBase* mode)
	{
		if (mModes[idx]) {
			ERROR("setup twice! \n");
			return;
		}

		mModes[idx] = mode;
	}

	int mState;            // _00
	int mCurrentSelect;    // _04
	int mModeCount;        // _08
	GameModeBase** mModes; // _0C, array of something
};

/**
 * @brief TODO
 */
struct CMcourseSelectMode : public GameModeBase {
	CMcourseSelectMode()
	    : GameModeBase("チャレンジモード・コースセレクト") // 'challenge mode course select'
	{
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			mCourseSelectScreen.start();
		}
		if (mCourseSelectScreen.update(controller)) {
			PRINT("returnStatus:%d \n", mCourseSelectScreen.getReturnStatusFlag());
		}
		return res;
	}
	virtual void draw(Graphics& gfx) { mCourseSelectScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawCMcourseSelect mCourseSelectScreen; // _0C
};

/**
 * @brief TODO
 */
struct CMresultMode : public GameModeBase {
	CMresultMode()
	    : GameModeBase("チャレンジモード・リザルト") // 'challenge mode results'
	{
		_04                    = KBBTN_Z;
		mInfo.mCourseID        = STAGE_Yakushima;
		mInfo.mScore           = 0;
		mInfo.mRank            = 2;
		mInfo.mCourseScores[0] = 982;
		mInfo.mCourseScores[1] = 432;
		mInfo.mCourseScores[2] = 353;
		mInfo.mCourseScores[3] = 221;
		mInfo.mCourseScores[4] = 123;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			mResultScreen.start(mInfo);
		}
		if (mResultScreen.update(controller)) {
			PRINT("finish \n");
		}
		return res;
	}
	virtual void draw(Graphics& gfx) { mResultScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawCMresult mResultScreen; // _0C
	GameChalQuickInfo mInfo;         // _AC
};

/**
 * @brief TODO
 */
struct ContainerMode : public GameModeBase {
	ContainerMode()
	    : GameModeBase("ピクミン出し入れ") // 'pikmin in and out'
	{
		mContainerColor = zen::DrawContainer::COLOR_Blue;
		mContainerMenu.start(zen::DrawContainer::COLOR_Blue, 0, 0, 0, 0, 0, 0);
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			if (++mContainerColor > zen::DrawContainer::COLOR_Yellow) {
				mContainerColor = zen::DrawContainer::COLOR_Blue;
			}
			switch (mContainerColor) {
			case 0:
				mContainerMenu.start(zen::DrawContainer::COLOR_Blue, 0, 0, 0, 0, 0, 0);
				break;

			case 1:
				mContainerMenu.start(zen::DrawContainer::COLOR_Red, 0, 0, 0, 0, 0, 0);
				break;

			case 2:
				mContainerMenu.start(zen::DrawContainer::COLOR_Yellow, 0, 0, 0, 0, 0, 0);
				break;
			}
		}
		int unused;
		mContainerMenu.update(unused);
		return res;
	}
	virtual void draw(Graphics& gfx) { mContainerMenu.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	u32 mContainerColor;               // _0C
	zen::DrawContainer mContainerMenu; // _10
};

/**
 * @brief TODO
 */
struct CountDownMode : public GameModeBase {
	CountDownMode()
	    : GameModeBase("カウントダウン") // 'countdown'
	{
		mDummyTimeOfDay = 0.0f;
		mCountDownScreen.init(0.0f, 1.0f, &mDummyTimeOfDay);
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_A)) {
			mDummyTimeOfDay = 0.0f;
		}
		if (controller->keyDown(KBBTN_Y)) {
			mDummyTimeOfDay += 0.001f;
		}
		if (controller->keyDown(KBBTN_X)) {
			mDummyTimeOfDay -= 0.001f;
		}
		if (mDummyTimeOfDay < 0.0f) {
			mDummyTimeOfDay = 1.0f;
		}
		if (mDummyTimeOfDay > 1.0f) {
			mDummyTimeOfDay = 0.0f;
		}
		mCountDownScreen.update();
		return res;
	}
	virtual void draw(Graphics& gfx) { mCountDownScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	f32 mDummyTimeOfDay;                 // _0C
	zen::DrawCountDown mCountDownScreen; // _10
};

/**
 * @brief TODO
 */
struct FinalResultMode : public GameModeBase {
	FinalResultMode()
	    : GameModeBase("ファイナルリザルト") // 'final result'
	{
		mFinalResultScreen = new zen::DrawFinalResult();
		mFinalResultScreen->start();
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			mFinalResultScreen->start();
		}
		if (mFinalResultScreen->update(controller)) {
			PRINT("Final Result Finish. \n");
		}
		return res;
	}
	virtual void draw(Graphics& gfx) { mFinalResultScreen->draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawFinalResult* mFinalResultScreen; // _0C
};

/**
 * @brief TODO
 */
struct GameInfoMode : public GameModeBase {
	GameInfoMode()
	    : GameModeBase("ゲーム情報") // 'game info'
	    , mGameInfoScreen(zen::DrawGameInfo::MODE_Story)
	{
		mGameInfoScreen.upperFrameIn(0.5f, true);
		mGameInfoScreen.lowerFrameIn(0.5f, true);
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			mGameInfoScreen.upperFrameIn(0.5f, true);
			mGameInfoScreen.lowerFrameIn(0.5f, true);
		}
		if (controller->keyUnClick(KBBTN_X)) {
			mGameInfoScreen.upperFrameOut(0.5f, true);
			mGameInfoScreen.lowerFrameOut(0.5f, true);
		}
		mGameInfoScreen.update();
		return res;
	}
	virtual void draw(Graphics& gfx) { mGameInfoScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawGameInfo mGameInfoScreen; // _0C
};

/**
 * @brief TODO
 */
struct GameOverMode : public GameModeBase {
	GameOverMode()
	    : GameModeBase("ゲームオーバー") // 'game over'
	{
		_0C = 0;
		mGameOverScreen.start(zen::DrawGameOver::MODE_Unk1, 40.0f);
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			if (++_0C > 1) {
				_0C = 0;
			}
			switch (_0C) {
			case 0:
				mGameOverScreen.start(zen::DrawGameOver::MODE_Unk1, 40.0f);
				break;
			case 1:
				mGameOverScreen.start(zen::DrawGameOver::MODE_Unk0, 40.0f);
				break;
			}
		}
		mGameOverScreen.update(controller);
		return res;
	}
	virtual void draw(Graphics& gfx) { mGameOverScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	int _0C;                           // _0C
	zen::DrawGameOver mGameOverScreen; // _10
};

/**
 * @brief TODO
 */
struct HiScoreMode : public GameModeBase {
	HiScoreMode()
	    : GameModeBase("ハイスコア") // 'high score'
	{
		mHiScoreScreen.start();
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			mHiScoreScreen.start();
		}
		mHiScoreScreen.update(controller);
		return res;
	}
	virtual void draw(Graphics& gfx) { mHiScoreScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawHiScore mHiScoreScreen; // _0C
};

/**
 * @brief TODO
 */
struct HurryUpMode : public GameModeBase {
	HurryUpMode()
	    : GameModeBase("Hurry Up!")
	{
		mHurryUpScreen.start(zen::DrawHurryUp::MesgType1);
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			mHurryUpScreen.start(zen::DrawHurryUp::MesgType1);
		}
		mHurryUpScreen.update();
		return res;
	}
	virtual void draw(Graphics& gfx) { mHurryUpScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawHurryUp mHurryUpScreen; // _0C
};

/**
 * @brief TODO
 */
struct ProgressiveMode : public GameModeBase {
	ProgressiveMode()
	    : GameModeBase("プログレッシブモード") // 'progressive mode'
	{
		mProgressiveScreen.start();
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			mProgressiveScreen.start();
		}
		mProgressiveScreen.update(controller);
		return res;
	}
	virtual void draw(Graphics& gfx) { mProgressiveScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawProgre mProgressiveScreen; // _0C
};

/**
 * @brief TODO
 */
struct SaveFailureMode : public GameModeBase {
	SaveFailureMode()
	    : GameModeBase("オプションセーブ") // 'options save'
	{
		mSaveScreen.start();
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			mSaveScreen.start();
		}
		mSaveScreen.update(controller);
		return res;
	}
	virtual void draw(Graphics& gfx) { mSaveScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawOptionSave mSaveScreen; // _0C
};

/**
 * @brief TODO
 */
struct SaveMesMode : public GameModeBase {
	SaveMesMode()
	    : GameModeBase("セーブメッセージ") // 'save message'
	{
		mSaveMesScreen.mesAppear();
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			switch (mSaveMesScreen.getModeFlag()) {
			case zen::DrawSaveMes::MODE_Unk3:
				mSaveMesScreen.saveFinish();
				break;
			default:
				mSaveMesScreen.mesAppear();
				break;
			}
		}

		if (controller->keyUnClick(KBBTN_X)) {
			mSaveMesScreen.saveError();
		}
		mSaveMesScreen.update(controller);
		return res;
	}
	virtual void draw(Graphics& gfx) { mSaveMesScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawSaveMes mSaveMesScreen; // _0C
};

/**
 * @brief TODO
 */
struct UfoPartsMode : public GameModeBase {
	UfoPartsMode()
	    : GameModeBase("ＵＦＯパーツ") // 'UFO parts'
	{
		mUfoPartsScreen.start();
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			mUfoPartsScreen.start();
		}
		mUfoPartsScreen.update(controller);
		return res;
	}
	virtual void draw(Graphics& gfx) { mUfoPartsScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawUfoParts mUfoPartsScreen; // _0C
};

/**
 * @brief TODO
 */
struct WMPauseMode : public GameModeBase {
	WMPauseMode()
	    : GameModeBase("ワールドマップポーズメニュー") // 'world map pause menu'
	{
		mWMPauseScreen.start();
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_Y)) {
			mWMPauseScreen.start();
		}
		mWMPauseScreen.update(controller);
		return res;
	}
	virtual void draw(Graphics& gfx) { mWMPauseScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawWMPause mWMPauseScreen; // _0C
};

/**
 * @brief TODO
 */
struct WorldMapMode : public GameModeBase {
	WorldMapMode()
	    : GameModeBase("ワールドマップ") // 'world map'
	{
		mWorldMapScreen.start(zen::DrawWorldMap::START_Unk0, zen::DrawWorldMap::PLACE_Unk0);
		_04 = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_X)) {
			mWorldMapScreen.start(zen::DrawWorldMap::START_Unk4, zen::DrawWorldMap::PLACE_Unk2);
		}
		mWorldMapScreen.update(controller);
		return res;
	}
	virtual void draw(Graphics& gfx) { mWorldMapScreen.draw(gfx); } // _0C

	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawWorldMap mWorldMapScreen; // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0x554. In gameCourseClear.cpp because of PRINT usage.
 */
struct GameCourseClearScreen : public Node {

	/**
	 * @brief TODO
	 *
	 * @note Name according to the DLL list. Offsets relative to screen for convenience.
	 */
	struct Parms : public Parameters {
		Parms()
		    : _24(this, 300.0f, 0.0f, 1000.0f, "p00", "floatテストだぴょ−ン") // 'f32 test'
		    , _34(this, 1, 0, 100, "i00", "intテストだぴょ−ン")               // 'int test'
		{
		}

		// _20-_24 = Parameters
		Parm<f32> _24; // _24, p00
		Parm<int> _34; // _34, i00
	};

	GameCourseClearScreen()
	{
		setName("GameCourseClearScreen");
		mController  = new Controller(1);
		_1F0         = 0;
		Texture* tex = gsys->loadTexture("bigFont.bti", true);
		mFont        = new Font();
		mFont->setTexture(tex, 21, 42);
		_1F8            = new Menu(mController, gsys->mConsFont, false);
		_1F8->_48.mMinX = glnWidth / 2;
		_1F8->_48.mMinY = glnHeight / 2;

		_1F8->addKeyEvent(0x20, 0x2000, new Delegate1<Menu, Menu&>(_1F8, &Menu::menuCloseMenu));
		_1F8->addOption(0, "Quit", new Delegate1<GameCourseClearScreen, Menu&>(this, &menuQuitGame), true);
		_1FC = 0;
		gsys->setFade(1.0f, 3.0f);
		_1F4 = 0xB0000;

		PRINT("パーティクルパックのテスト開始\n");
		mPtclGenPack = new zen::PtclGenPack(3);

		for (int i = 0; i < 3; i++) {
			zen::particleGenerator* ptclGen = new zen::particleGenerator();
			PRINT("setPtclGenPtr:%08x\n", ptclGen);
			mPtclGenPack->setPtclGenPtr(i, ptclGen);
		}

		PRINT("startGen\n");
		mPtclGenPack->startGen();
		PRINT("OK\n");

		mGameModeMgr = new GameModeMgr(15);

		int j = 0;
		mGameModeMgr->setGameMode(j++, new FinalResultMode);
		mGameModeMgr->setGameMode(j++, new SaveFailureMode());
		mGameModeMgr->setGameMode(j++, new SaveMesMode());
		mGameModeMgr->setGameMode(j++, new UfoPartsMode());
		mGameModeMgr->setGameMode(j++, new HiScoreMode());
		mGameModeMgr->setGameMode(j++, new CMcourseSelectMode());
		mGameModeMgr->setGameMode(j++, new CMresultMode());
		mGameModeMgr->setGameMode(j++, new WorldMapMode());
		mGameModeMgr->setGameMode(j++, new WMPauseMode());
		mGameModeMgr->setGameMode(j++, new ContainerMode());
		mGameModeMgr->setGameMode(j++, new GameOverMode());
		mGameModeMgr->setGameMode(j++, new CountDownMode());
		mGameModeMgr->setGameMode(j++, new ProgressiveMode());
		mGameModeMgr->setGameMode(j++, new GameInfoMode());
		mGameModeMgr->setGameMode(j++, new HurryUpMode());
	}

	virtual void update() // _10
	{
		mController->update();
		mScreen.update();
		if (_1FC) {
			_1FC = _1FC->doUpdate(false);
		} else if (_1F0 == 0) {
			gameflow._33C = 0;
			Node::update();
		} else if (_1F0 == 1 && !_1FC && gsys->getFade() == 0.0f) {
			_1F0                             = -1;
			gameflow.mNextOnePlayerSectionID = gameflow.mLevelIndex;
			gsys->softReset();
		}

		mGameModeMgr->update(mController);
	}
	virtual void draw(Graphics& gfx) // _14
	{
		gfx.setViewport(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setScissor(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setClearColour(Colour(0, 0, 0, 255));
		gfx.clearBuffer(3, false);
		Matrix4f mtx;
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setColour(Colour(64, 64, 192, 255), true);
		gfx.setAuxColour(Colour(192, 64, 255, 255));
		gfx.fillRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

		Camera camera;
		Matrix4f mtx2;

		Vector3f eyePos(200.0f, 200.0f, 200.0f);
		Vector3f targetPos(0.0f, 0.0f, 0.0f);
		camera.calcVectors(eyePos, targetPos);
		camera.update(f32(gfx.mScreenWidth) / f32(gfx.mScreenHeight), 60.0f, 1.0f, 5000.0f);
		gfx.setCamera(&camera);
		gfx.calcViewMatrix(Matrix4f::ident, mtx2);
		gfx.setPerspective(camera.mPerspectiveMatrix.mMtx, camera.mFov, camera.mAspectRatio, camera.mNear, camera.mFar, 1.0f);
		gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
		gfx.setLighting(false, nullptr);
		gfx.useTexture(nullptr, 0);
		mGameModeMgr->draw(gfx, mFont);
		if (_1FC) {
			_1FC->draw(gfx, 1.0f);
		}
	}
	virtual void read(RandomAccessStream& input) // _0C
	{
		mCourseClearParms.read(input);
	}

	// weak
	void menuQuitGame(Menu& menu)
	{
		menu.close();
		PRINT("Chose quit menu!!\n");
		_1F0 = 1;
		_1F4 = 0xB;
		gsys->setFade(0.0f, 3.0f);
	}

	// _00     = VTBL
	// _00-_20 = Node
	Parms mCourseClearParms;           // _20
	zen::particleLoader mPtclLoader;   // _44
	zen::particleManager mPtclManager; // _54
	u8 _F0[0x4];                       // _F0, unknown
	P2DScreen mScreen;                 // _F4
	zen::PtclGenPack* mPtclGenPack;    // _1EC
	u32 _1F0;                          // _1F0, unknown
	u32 _1F4;                          // _1F4, unknown
	Menu* _1F8;                        // _1F8
	Menu* _1FC;                        // _1FC
	Controller* mController;           // _200
	Font* mFont;                       // _204
	Camera mCamera;                    // _208
	GameModeMgr* mGameModeMgr;         // _550
};

/*
 * --INFO--
 * Address:	80199474
 * Size:	000D38
 */
GameCourseClearSection::GameCourseClearSection()
{
	Node::init("<GameCourseClearSection>");
	gsys->setFrameClamp(1);
	flowCont._24C = 0;
	flowCont._250 = 0;

	GameCourseClearScreen* screen = new GameCourseClearScreen();
	screen->mPtclManager.init(10, 4081, 4081, 60.0f);
	screen->mPtclManager.createGenerator(screen->mPtclLoader.load("effects/pcr/pk_dead.pcr", true),
	                                     gsys->loadTexture("effects/tex/soulf3.bti", true),
	                                     gsys->loadTexture("effects/tex/soulf3.bti", true), Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	screen->mScreen.set("screen/blo/progre.blo", true, true, true);
	add(screen);
}
