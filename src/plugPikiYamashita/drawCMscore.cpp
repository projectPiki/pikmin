#include "DebugLog.h"
#include "nlib/Math.h"
#include "sysNew.h"
#include "zen/DrawCM.h"
#include "zen/Number.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(13)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("drawCMscore")

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x50.
 */
struct DrawCMscoreObj {
public:
	typedef bool (DrawCMscoreObj::*ModeFunc)();

	enum modeFlag {
		MODE_Wait   = 0,
		MODE_Appear = 1,
	};

	DrawCMscoreObj()
	{
		mScorePane          = nullptr;
		mScoreDigitOnes     = 0;
		mScoreDigitTens     = 0;
		mScoreDigitHundreds = 0;
		mScore              = 321;
		mMoveElapsedTime    = 0.0f;
		mMoveDuration       = 0.0f;
		mMode               = MODE_Wait;
		mModeFunction       = nullptr;
	}

	void init(P2DScreen* screen, int p2)
	{
		char buf[8];
		sprintf(buf, "%dban", p2);
		mScorePane = screen->search(P2DPaneLibrary::makeTag(buf), true);
		mScorePane->setOffset(mScorePane->getWidth() >> 1, mScorePane->getHeight() >> 1);
		mBasePosition.set(mScorePane->getPosH(), mScorePane->getPosV(), 0.0f);

		sprintf(buf, "%di_l", p2);
		P2DPane* pane = screen->search(P2DPaneLibrary::makeTag(buf), true);
		pane->setCallBack(new NumberPicCallBack<int>(pane, &mScore, 100, false));
		if (pane->getTypeID() == PANETYPE_Picture) {
			mScoreDigitHundreds = (P2DPicture*)pane;
		}

		sprintf(buf, "%di_c", p2);
		pane = screen->search(P2DPaneLibrary::makeTag(buf), true);
		pane->setCallBack(new NumberPicCallBack<int>(pane, &mScore, 10, false));
		if (pane->getTypeID() == PANETYPE_Picture) {
			mScoreDigitTens = (P2DPicture*)pane;
		}

		sprintf(buf, "%di_r", p2);
		pane = screen->search(P2DPaneLibrary::makeTag(buf), true);
		pane->setCallBack(new NumberPicCallBack<int>(pane, &mScore, 1, false));
		if (pane->getTypeID() == PANETYPE_Picture) {
			mScoreDigitOnes = (P2DPicture*)pane;
		}
		mMode         = MODE_Wait;
		mModeFunction = &DrawCMscoreObj::modeWait;
	}
	void appear(f32 p1)
	{
		mMoveElapsedTime = 0.0f;
		mMoveDuration    = p1;
		mMode         = MODE_Appear;
		mModeFunction = &DrawCMscoreObj::modeMove;
		mAppearStartPosition.set(mBasePosition);
		mAppearStartPosition.x += 640.0f;
		mAppearTargetPosition.set(mBasePosition);
	}

	void wait()
	{
		mMoveElapsedTime = 0.0f;
		mMode         = MODE_Wait;
		mModeFunction = &DrawCMscoreObj::modeWait;
	}

	void update() { (this->*mModeFunction)(); }
	void show() { mScorePane->show(); }
	void hide() { mScorePane->hide(); }

	modeFlag getModeFlag() { return mMode; }
	void setScore(int score) { mScore = score; }

protected:
	bool modeWait() { return false; }
	bool modeMove()
	{
		bool res = false;
		mMoveElapsedTime += gsys->getFrameTime();
		f32 t, tComp;
		if (mMoveElapsedTime > mMoveDuration) {
			mMoveElapsedTime = mMoveDuration;
			t     = 1.0f;
			tComp = 0.0f;
			wait();
			res = true;
		} else {
			t     = NMathF::sin(mMoveElapsedTime / mMoveDuration * HALF_PI);
			tComp = 1.0f - t;
		}

		mScorePane->move(RoundOff(mAppearTargetPosition.x * t + mAppearStartPosition.x * tComp),
		                 RoundOff(mAppearTargetPosition.y * t + mAppearStartPosition.y * tComp));

		return res;
	}

	P2DPane* mScorePane;             // _00
	P2DPicture* mScoreDigitOnes;     // _04
	P2DPicture* mScoreDigitTens;     // _08
	P2DPicture* mScoreDigitHundreds; // _0C
	int mScore;                      // _10
	modeFlag mMode;                  // _14
	f32 mMoveElapsedTime;            // _18
	f32 mMoveDuration;               // _1C
	Vector3f mBasePosition;          // _20
	Vector3f mAppearStartPosition;   // _24
	Vector3f mAppearTargetPosition;  // _38
	ModeFunc mModeFunction;          // _44
};
} // namespace zen

/**
 * @todo: Documentation
 */
void zen::DrawCMscoreMgr::init(P2DScreen* screen)
{
	mScoreObjs = new DrawCMscoreObj[MEMORY_BEST_SCORE];

	for (int i = 0; i < MEMORY_BEST_SCORE; i++) {
		mScoreObjs[i].init(screen, i + 1);
	}

	mMode         = MODE_Sleep;
	mModeFunction = &DrawCMscoreMgr::modeSleep;
}

/**
 * @todo: Documentation
 */
void zen::DrawCMscoreMgr::update()
{
	mEventFlag = 0;
	(this->*mModeFunction)();
	for (int i = 0; i < MEMORY_BEST_SCORE; i++) {
		mScoreObjs[i].update();
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
void zen::DrawCMscoreMgr::show()
{
	for (int i = 0; i < MEMORY_BEST_SCORE; i++) {
		mScoreObjs[i].show();
	}
}

/**
 * @todo: Documentation
 */
void zen::DrawCMscoreMgr::hide()
{
	for (int i = 0; i < MEMORY_BEST_SCORE; i++) {
		mScoreObjs[i].hide();
	}
}

/**
 * @todo: Documentation
 */
void zen::DrawCMscoreMgr::sleep()
{
	hide();
	mMode         = MODE_Sleep;
	mModeFunction = &DrawCMscoreMgr::modeSleep;
}

/**
 * @todo: Documentation
 */
void zen::DrawCMscoreMgr::appear(f32 p1)
{
	mMode         = MODE_Appear;
	mModeFunction = &DrawCMscoreMgr::modeAppear;
	for (int i = 0; i < MEMORY_BEST_SCORE; i++) {
		mScoreObjs[i].show();
		mScoreObjs[i].appear(p1 + (MEMORY_BEST_SCORE - i - 1) * 0.25f);
	}
}

/**
 * @todo: Documentation
 */
bool zen::DrawCMscoreMgr::modeSleep()
{
	return false;
}

/**
 * @todo: Documentation
 */
bool zen::DrawCMscoreMgr::modeAppear()
{
	int scoresWaiting = 0;
	for (int i = 0; i < MEMORY_BEST_SCORE; i++) {
		if (mScoreObjs[i].getModeFlag() == DrawCMscoreObj::MODE_Wait) {
			scoresWaiting++;
		}
	}

	if (scoresWaiting == MEMORY_BEST_SCORE) {
		mMode         = MODE_Unk1;
		mModeFunction = &DrawCMscoreMgr::modeWait;
		mEventFlag |= 0x1;
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool zen::DrawCMscoreMgr::modeWait()
{
	mEventFlag |= 0x2;
	return false;
}

/**
 * @todo: Documentation
 */
void zen::DrawCMscoreMgr::setScore(int rank, int score)
{
	if (rank >= 0 && rank < MEMORY_BEST_SCORE) {
		mScoreObjs[rank].setScore(score);
	} else {
		PRINT("ERROR! rank No %d is Illegal. \n", rank);
		ERROR("ERROR! rank No %d is Illegal. \n", rank);
	}
}

const int zen::DrawCMscoreMgr::MEMORY_BEST_SCORE = 5;
