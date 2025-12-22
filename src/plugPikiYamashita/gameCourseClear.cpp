#include "Controller.h"
#include "DebugLog.h"
#include "Delegate.h"
#include "FlowController.h"
#include "Font.h"
#include "GameCourseClearSection.h"
#include "Graphics.h"
#include "Menu.h"
#include "zen/DrawContainer.h"
#include "zen/DrawHurryUp.h"
#include "zen/bBoardColourAnim.h"
#include "zen/particle.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(64)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GameCourseClearSection")

/**
 * @brief TODO
 */
struct GameModeBase {
public:
	GameModeBase(immut char* name)
	{
		mName         = name;
		mCancelButton = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = false;
		if (controller->keyUnClick(mCancelButton)) {
			SeSystem::playSysSe(SYSSE_CANCEL);
			res = true;
		}
		return res;
	}
	virtual void draw(Graphics& gfx) { } // _0C

	immut char* getModeName() { return mName; }

protected:
	// _00 = VTBL
	int mCancelButton; // _04
	immut char* mName; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x10. In gameCourseClear.cpp for PRINT reasons.
 */
struct GameModeMgr {
public:
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

protected:
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

			immut char* name = mModes[i]->getModeName();
			gfx.texturePrintf(font, 320 - font->stringWidth(name) / 2, i * font->stringHeight(name) + 70, name);
		}
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
public:
	CMcourseSelectMode()
	    : GameModeBase("チャレンジモード・コースセレクト") // 'challenge mode course select'
	{
		mCancelButton = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawCMcourseSelect mCourseSelectScreen; // _0C
};

/**
 * @brief TODO
 */
struct CMresultMode : public GameModeBase {
public:
	CMresultMode()
	    : GameModeBase("チャレンジモード・リザルト") // 'challenge mode results'
	{
		mCancelButton          = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawCMresult mResultScreen; // _0C
	GameChalQuickInfo mInfo;         // _AC
};

/**
 * @brief TODO
 */
struct ContainerMode : public GameModeBase {
public:
	ContainerMode()
	    : GameModeBase("ピクミン出し入れ") // 'pikmin in and out'
	{
		mContainerColor = zen::DrawContainer::COLOR_Blue;
		mContainerMenu.start(zen::DrawContainer::COLOR_Blue, 0, 0, 0, 0, 0, 0);
		mCancelButton = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	u32 mContainerColor;               // _0C
	zen::DrawContainer mContainerMenu; // _10
};

/**
 * @brief TODO
 */
struct CountDownMode : public GameModeBase {
public:
	CountDownMode()
	    : GameModeBase("カウントダウン") // 'countdown'
	{
		mDummyTimeOfDay = 0.0f;
		mCountDownScreen.init(0.0f, 1.0f, &mDummyTimeOfDay);
		mCancelButton = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	f32 mDummyTimeOfDay;                 // _0C
	zen::DrawCountDown mCountDownScreen; // _10
};

/**
 * @brief TODO
 */
struct FinalResultMode : public GameModeBase {
public:
	FinalResultMode()
	    : GameModeBase("ファイナルリザルト") // 'final result'
	{
		mFinalResultScreen = new zen::DrawFinalResult();
		mFinalResultScreen->start();
		mCancelButton = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawFinalResult* mFinalResultScreen; // _0C
};

/**
 * @brief TODO
 */
struct GameInfoMode : public GameModeBase {
public:
	GameInfoMode()
	    : GameModeBase("ゲーム情報") // 'game info'
	    , mGameInfoScreen(zen::DrawGameInfo::MODE_Story)
	{
		mGameInfoScreen.upperFrameIn(0.5f, true);
		mGameInfoScreen.lowerFrameIn(0.5f, true);
		mCancelButton = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawGameInfo mGameInfoScreen; // _0C
};

/**
 * @brief TODO
 */
struct GameOverMode : public GameModeBase {
public:
	GameOverMode()
	    : GameModeBase("ゲームオーバー") // 'game over'
	{
		_0C = 0;
		mGameOverScreen.start(zen::DrawGameOver::MODE_Extinction, 40.0f);
		mCancelButton = KBBTN_Z;
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
				mGameOverScreen.start(zen::DrawGameOver::MODE_Extinction, 40.0f);
				break;
			case 1:
				mGameOverScreen.start(zen::DrawGameOver::MODE_NaviDown, 40.0f);
				break;
			}
		}
		mGameOverScreen.update(controller);
		return res;
	}
	virtual void draw(Graphics& gfx) { mGameOverScreen.draw(gfx); } // _0C

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	int _0C;                           // _0C
	zen::DrawGameOver mGameOverScreen; // _10
};

/**
 * @brief TODO
 */
struct HiScoreMode : public GameModeBase {
public:
	HiScoreMode()
	    : GameModeBase("ハイスコア") // 'high score'
	{
		mHiScoreScreen.start();
		mCancelButton = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawHiScore mHiScoreScreen; // _0C
};

/**
 * @brief TODO
 */
struct HurryUpMode : public GameModeBase {
public:
	HurryUpMode()
	    : GameModeBase("Hurry Up!")
	{
		mHurryUpScreen.start(zen::DrawHurryUp::MesgType1);
		mCancelButton = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawHurryUp mHurryUpScreen; // _0C
};

/**
 * @brief TODO
 */
struct ProgressiveMode : public GameModeBase {
public:
	ProgressiveMode()
	    : GameModeBase("プログレッシブモード") // 'progressive mode'
	{
		mProgressiveScreen.start();
		mCancelButton = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawProgre mProgressiveScreen; // _0C
};

/**
 * @brief TODO
 */
struct SaveFailureMode : public GameModeBase {
public:
	SaveFailureMode()
	    : GameModeBase("オプションセーブ") // 'options save'
	{
		mSaveScreen.start();
		mCancelButton = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawOptionSave mSaveScreen; // _0C
};

/**
 * @brief TODO
 */
struct SaveMesMode : public GameModeBase {
public:
	SaveMesMode()
	    : GameModeBase("セーブメッセージ") // 'save message'
	{
		mSaveMesScreen.mesAppear();
		mCancelButton = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawSaveMes mSaveMesScreen; // _0C
};

/**
 * @brief TODO
 */
struct UfoPartsMode : public GameModeBase {
public:
	UfoPartsMode()
	    : GameModeBase("ＵＦＯパーツ") // 'UFO parts'
	{
		mUfoPartsScreen.start();
		mCancelButton = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawUfoParts mUfoPartsScreen; // _0C
};

/**
 * @brief TODO
 */
struct WMPauseMode : public GameModeBase {
public:
	WMPauseMode()
	    : GameModeBase("ワールドマップポーズメニュー") // 'world map pause menu'
	{
		mWMPauseScreen.start();
		mCancelButton = KBBTN_Z;
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

protected:
	// _00     = VTBL
	// _00-_0C = GameModeBase
	zen::DrawWMPause mWMPauseScreen; // _0C
};

/**
 * @brief TODO
 */
struct WorldMapMode : public GameModeBase {
public:
	WorldMapMode()
	    : GameModeBase("ワールドマップ") // 'world map'
	{
		mWorldMapScreen.start(zen::DrawWorldMap::None, zen::DrawWorldMap::ImpactSite);
		mCancelButton = KBBTN_Z;
	}

	virtual bool update(Controller* controller) // _08
	{
		bool res = GameModeBase::update(controller);
		if (controller->keyUnClick(KBBTN_X)) {
			mWorldMapScreen.start(zen::DrawWorldMap::FinalUnlock, zen::DrawWorldMap::ForestNavel);
		}
		mWorldMapScreen.update(controller);
		return res;
	}
	virtual void draw(Graphics& gfx) { mWorldMapScreen.draw(gfx); } // _0C

protected:
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
		    : mFloatTest(this, 300.0f, 0.0f, 1000.0f, "p00", "floatテストだぴょ−ン") // 'f32 test'
		    , mIntTest(this, 1, 0, 100, "i00", "intテストだぴょ−ン")                 // 'int test'
		{
		}

		// _20-_24 = Parameters
		Parm<f32> mFloatTest; // _24, p00
		Parm<int> mIntTest;   // _34, i00
	};

	GameCourseClearScreen()
	{
		setName("GameCourseClearScreen");
		mController  = new Controller(1);
		mState       = 0;
		Texture* tex = gsys->loadTexture("bigFont.bti", true);
		mFont        = new Font();
		mFont->setTexture(tex, 21, 42);
		mMainMenu                     = new Menu(mController, gsys->mConsFont, false);
		mMainMenu->mAnchorPoint.mMinX = glnWidth / 2;
		mMainMenu->mAnchorPoint.mMinY = glnHeight / 2;

		mMainMenu->addKeyEvent(Menu::KeyEventType::SpecialRelease, KBBTN_B, new Delegate1<Menu, Menu&>(mMainMenu, &Menu::menuCloseMenu));
		mMainMenu->addOption(0, "Quit", new Delegate1<GameCourseClearScreen, Menu&>(this, &menuQuitGame), true);
		mActiveMenu = 0;
		gsys->setFade(1.0f, 3.0f);
		mFlags = 0xB0000;

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
		if (mActiveMenu) {
			mActiveMenu = mActiveMenu->doUpdate(false);
		} else if (mState == 0) {
			gameflow._33C = FALSE;
			Node::update();
		} else if (mState == 1 && !mActiveMenu && gsys->getFade() == 0.0f) {
			mState                           = -1;
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
		gfx.useTexture(nullptr, GX_TEXMAP0);
		mGameModeMgr->draw(gfx, mFont);
		if (mActiveMenu) {
			mActiveMenu->draw(gfx, 1.0f);
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
		mState = 1;
		mFlags = 0xB;
		gsys->setFade(0.0f, 3.0f);
	}

	// _00     = VTBL
	// _00-_20 = Node
	Parms mCourseClearParms;           // _20
	zen::particleLoader mPtclLoader;   // _44
	zen::particleManager mPtclManager; // _54
	u8 _UNUSEDF0[0x4];                 // _F0, unknown
	P2DScreen mScreen;                 // _F4
	zen::PtclGenPack* mPtclGenPack;    // _1EC
	u32 mState;                        // _1F0, unknown
	u32 mFlags;                        // _1F4, unknown
	Menu* mMainMenu;                   // _1F8
	Menu* mActiveMenu;                 // _1FC
	Controller* mController;           // _200
	Font* mFont;                       // _204
	Camera mCamera;                    // _208
	GameModeMgr* mGameModeMgr;         // _550
};

/**
 * @TODO: Documentation
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
