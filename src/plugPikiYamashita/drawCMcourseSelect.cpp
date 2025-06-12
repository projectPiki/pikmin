#include "zen/DrawCM.h"
#include "zen/EffectMgr2D.h"
#include "gameflow.h"
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
DEFINE_PRINT("drawCMcourseSelect")

namespace zen {
/**
 * @brief TODO
 *
 * @note Size: 0x19C.
 */
struct DrawCMCSmenu : public DrawMenuBase {

	enum ModeCMCS {
		MODE_Unk2 = 2,
	};

	/**
	 * @brief TODO
	 *
	 * @note Size: 0x34.
	 */
	struct MenuExpansion {
		enum modeFlag {
			MODE_Unk0 = 0,
			MODE_Unk1 = 1,
		};

		MenuExpansion()
		{
			mRootPane = nullptr;
			_10.set(0.0f, 0.0f, 0.0f);
			_1C.set(0.0f, 0.0f, 0.0f);
			_28.set(0.0f, 0.0f, 0.0f);
			_04 = _08 = 0.0f;
			mMode     = MODE_Unk0;
		}

		void setRootPane(P2DPane* pane)
		{
			mRootPane = pane;
			_10.set(mRootPane->getPosH(), mRootPane->getPosV(), 0.0f);
		}
		modeFlag update()
		{
			switch (mMode) {
			case MODE_Unk1:
				_04 += gsys->getFrameTime();
				f32 t, tComp;
				if (_04 > _08) {
					_04   = _08;
					t     = 1.0f;
					tComp = 0.0f;
					mMode = MODE_Unk0;
				} else {
					t     = NMathF::sin(_04 / _08 * HALF_PI);
					tComp = 1.0f - t;
				}
				mRootPane->move(RoundOff(_1C.x * tComp + _28.x * t), RoundOff(_1C.y * tComp + _28.y * t));
				break;
			}
			return mMode;
		}

		void show() { mRootPane->show(); }
		void hide() { mRootPane->hide(); }
		void setPosition(int x, int y) { mRootPane->move(x, y); }
		void move(f32 x, f32 y, f32 p3)
		{
			mMode = MODE_Unk1;
			_04   = 0.0f;
			_08   = p3;
			_1C.set(mRootPane->getPosH(), mRootPane->getPosV(), 0.0f);
			_28.set(x, y, 0.0f);
		}
		Vector3f& getDefaultPos() { return _10; }

		modeFlag mMode;     // _00
		f32 _04;            // _04
		f32 _08;            // _08
		P2DPane* mRootPane; // _0C
		Vector3f _10;       // _10
		Vector3f _1C;       // _1C
		Vector3f _28;       // _28
	};

	DrawCMCSmenu(char* bloFileName)
	    : DrawMenuBase(bloFileName, true, true)
	{
		mMenuExpansions = new MenuExpansion[mOptionCount];

		char buf[8];
		P2DPane* pane;
		for (int i = 0; i < mOptionCount; i++) {
			sprintf(buf, "p_m%d", i);
			pane = mScreen.search(P2DPaneLibrary::makeTag(buf), true);
			mMenuExpansions[i].setRootPane(pane);
		}

		setKeyAssignDecide(KBBTN_START | KBBTN_A);
	}

	virtual bool update(Controller* controller) // _14
	{
		for (int i = 0; i < 5; i++) {
			mMenuExpansions[i].update();
		}

		return DrawMenuBase::update(controller);
	}
	virtual void start() // _18
	{
		DrawMenuBase::start();
		setModeFunc(2);
	}
	virtual void setModeFunc(int mode) // _28
	{
		DrawMenuBase::setModeFunc(mode);
		switch (mMode) {
		case MODE_Unk2:
			mModeFunction = (ModeFunc)&modeAppear;
			for (int i = 0; i < mOptionCount; i++) {
				Vector3f pos(mMenuExpansions[i].getDefaultPos());
				bool check = false;
				if (i < 3) {
					check = true;
				} else if (gameflow.mGamePrefs.isStageOpen(i)) {
					check = true;
				}
				if (check != 0) {
					mMenuItems[i].setActiveSw(true);
					mMenuExpansions[i].show();
					mMenuExpansions[i].setPosition(RoundOff(pos.x - 640.0f), RoundOff(pos.y));
					mMenuExpansions[i].move(pos.x, pos.y, f32(i) * 0.5f + 1.0f);
				} else {
					mMenuItems[i].setActiveSw(false);
					mMenuExpansions[i].hide();
				}
			}
			mLeftCursorMgr.initScale(0.0f);
			mRightCursorMgr.initScale(0.0f);
			break;
		}
	}

	bool modeAppear(Controller*)
	{
		int i;
		int numWaiting = 0;
		for (i = 0; i < mOptionCount; i++) {
			if (mMenuExpansions[i].update() == MenuExpansion::MODE_Unk0) {
				numWaiting++;
			}
		}

		if (numWaiting == mOptionCount) {
			mLeftCursorMgr.scale(1.0f, 1.0f);
			mRightCursorMgr.scale(1.0f, 1.0f);
			setModeFunc(MODE_Operation);
		}

		return false;
	}

	void hide()
	{
		for (int i = 0; i < 5; i++) {
			mMenuExpansions[i].hide();
		}
		mLeftCursorMgr.initScale(0.0f);
		mRightCursorMgr.initScale(0.0f);
	}

	// _00      = VTBL
	// _00-_198 = DrawMenuBase
	MenuExpansion* mMenuExpansions; // _198
};

} // namespace zen

/*
 * --INFO--
 * Address:	801EC8D8
 * Size:	0003A4
 */
zen::DrawCMcourseSelect::DrawCMcourseSelect()
{
	mEffectMgr2D  = new EffectMgr2D(0x10, 0x400, 1);
	mSelectScreen = new DrawScreen("screen/blo/cha_sel.blo", nullptr, true, true);
	mScoreScreen  = new DrawScreen("screen/blo/cha_rank.blo", nullptr, true, true);
	mBestScreen   = new DrawScreen("screen/blo/cha_best.blo", nullptr, true, true);

	P2DScreen* selScreen   = mSelectScreen->getScreenPtr();
	P2DScreen* scoreScreen = mScoreScreen->getScreenPtr();
	P2DScreen* bestScreen  = mBestScreen->getScreenPtr();

	P2DPane* pane = scoreScreen->search('rank', true);
	pane->move(355, 234);
	pane = bestScreen->search('best', true);
	pane->move(405, 164);

	_8C = selScreen->search('abtn', true);
	_90 = 0;
	P2DPaneLibrary::setFamilyAlpha(_8C, _90);
	mMode        = MODE_Unk0;
	mReturnState = RETSTATE_UnkN3;

	mMenu = new DrawCMCSmenu("screen/blo/cha_map.blo");

	mTitleObj.init(selScreen);
	mScoreMgr.init(scoreScreen);
	mBest.init(bestScreen);
}

/*
 * --INFO--
 * Address:	801ECD04
 * Size:	000294
 */
void zen::DrawCMcourseSelect::start()
{
	mMode = MODE_Unk1;
	mEffectMgr2D->killAll(true);
	mReturnState = RETSTATE_UnkN1;
	mTitleObj.appear(2.5f);
	mMenu->hide();
	mScoreMgr.hide();
	mBest.hide();
	setBestScore();
	mEffectMgr2D->create(EFF2D_Unk25, Vector3f(320.0f, 240.0f, 0.0), nullptr, nullptr);
	mEffectMgr2D->create(EFF2D_Unk26, Vector3f(320.0f, 240.0f, 0.0), nullptr, nullptr);
	mEffectMgr2D->create(EFF2D_Unk27, Vector3f(320.0f, 240.0f, 0.0), nullptr, nullptr);
	mEffectMgr2D->create(EFF2D_Unk28, Vector3f(320.0f, 240.0f, 0.0), nullptr, nullptr);
	mEffectMgr2D->create(EFF2D_Unk29, Vector3f(320.0f, 240.0f, 0.0), nullptr, nullptr);
	mEffectMgr2D->create(EFF2D_Unk30, Vector3f(320.0f, 240.0f, 0.0), nullptr, nullptr);
	mEffectMgr2D->create(EFF2D_Unk31, Vector3f(320.0f, 240.0f, 0.0), nullptr, nullptr);
	mEffectMgr2D->create(EFF2D_Unk32, Vector3f(320.0f, 240.0f, 0.0), nullptr, nullptr);
	_90 = 0;
	P2DPaneLibrary::setFamilyAlpha(_8C, _90);
	PRINT("start! \n");
}

/*
 * --INFO--
 * Address:	801ECF98
 * Size:	000080
 */
void zen::DrawCMcourseSelect::setBestScore()
{
	GameChalQuickInfo info;
	info.mCourseID = mMenu->getSelectNo();
	gameflow.mGamePrefs.getChallengeScores(info);
	PRINT("stage : %d \n", info.mCourseID);
	for (int i = 0; i < 5; i++) {
		PRINT("score:%d\n", info.mCourseScores[i]);
		mScoreMgr.setScore(i, info.mCourseScores[i]);
	}
}

/*
 * --INFO--
 * Address:	801ED018
 * Size:	00011C
 */
bool zen::DrawCMcourseSelect::update(Controller* controller)
{
	bool res = false;
	switch (mMode) {
	case MODE_Unk1:
		if (mTitleObj.getEvent() & 0x1) {
			mMode = MODE_Unk2;
			mMenu->start();
			mScoreMgr.appear(0.5f);
			mBest.appear();
		}
		break;

	case MODE_Unk2:
		if (modeOperation(controller)) {
			mMode = MODE_Unk3;
		}
		break;

	case MODE_Unk3:
		res = true;
		break;
	}

	mTitleObj.update();
	mScoreMgr.update();
	mBest.update();
	mSelectScreen->update();
	mScoreScreen->update();
	mBestScreen->update();
	mEffectMgr2D->update();

	return res;
}

/*
 * --INFO--
 * Address:	801ED178
 * Size:	000090
 */
void zen::DrawCMcourseSelect::draw(Graphics& gfx)
{
	mEffectMgr2D->draw(gfx);
	mMenu->draw(gfx);
	mScoreScreen->draw();
	mBestScreen->draw();
	mSelectScreen->draw();
}

/*
 * --INFO--
 * Address:	801ED208
 * Size:	000008
 */
zen::DrawCMcourseSelect::returnStatusFlag zen::DrawCMcourseSelect::getReturnStatusFlag()
{
	return mReturnState;
}

/*
 * --INFO--
 * Address:	801ED210
 * Size:	000100
 */
bool zen::DrawCMcourseSelect::modeOperation(Controller* controller)
{
	bool res = mMenu->update(controller);
	if (mMenu->getEventFlag() & 0x1) {
		PRINT("change score! \n");
		setBestScore();
	}
	if (res) {
		int sel = mMenu->getSelectNo();
		if (sel == DrawMenuBase::SELECT_CANCEL) {
			mReturnState = RETSTATE_UnkN2;
		} else {
			mReturnState = (returnStatusFlag)sel;
		}
		res = true; // this is... already true if we're here.
	}

	if (_90 < 255) {
		_90++;
		P2DPaneLibrary::setFamilyAlpha(_8C, _90);
	}

	STACK_PAD_VAR(1);
	return res;
}
