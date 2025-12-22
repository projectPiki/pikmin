#include "DebugLog.h"
#include "sysNew.h"
#include "zen/DrawCM.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("drawCMbest")

namespace zen {
/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct DrawCMBpicObj {
public:
	typedef bool (DrawCMBpicObj::*ModeFunc)();

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		MODE_Sleep  = 0,
		MODE_Appear = 1,
		MODE_Wait   = 2,
	};

	DrawCMBpicObj()
	{
		mRootPane = nullptr;
		_04 = _08     = 0.0f;
		mModeFunction = nullptr;
		mMode         = MODE_Sleep;
		_1C           = 0.0f;
	}

	// this is DLL, but has to be above the weak inlines for data ordering reasons.
	void setRootPane(P2DPane* pane)
	{
		mRootPane     = pane;
		mModeFunction = &modeSleep;
	}

	// DLL:
	void update() { (this->*mModeFunction)(); }
	void sleep() { setMode(MODE_Sleep); }
	void wait(f32 p1)
	{
		setMode(MODE_Wait);
		_04 = p1;
	}
	void appear(f32 p1)
	{
		setMode(MODE_Appear);
		_08 = p1;
	}

protected:
	// weak:
	bool modeSleep() { return false; }
	bool modeAppear()
	{
		_04 += gsys->getFrameTime();
		if (_04 > _08) {
			setMode(MODE_Wait);
		}

		return false;
	}
	bool modeWait()
	{
		_04 += gsys->getFrameTime();
		if (_04 > _08) {
			_04 -= _08;
			_1C += Rand(0.05f) + 0.02f;
		}
		_1C += (1.0f - mRootPane->getScale().x) * gsys->getFrameTime();
		_1C *= 0.95f;
		mRootPane->setScale(mRootPane->getScale().x + _1C);
		if (mRootPane->getScale().x < 0.0f) {
			mRootPane->setScale(0.0f);
		}
		if (mRootPane->getScale().x > 2.0f) {
			mRootPane->setScale(2.0f);
		}
		return false;
	}
	void setMode(modeFlag mode)
	{
		mMode = mode;
		switch (mMode) {
		case MODE_Sleep:
			mModeFunction = &modeSleep;
			mRootPane->setScale(0.0f);
			break;

		case MODE_Appear:
			_04 = 0.0f;
			_1C = 0.0f;
			mRootPane->setScale(0.0f);
			mModeFunction = &modeAppear;
			break;

		case MODE_Wait:
			_04           = 0.0f;
			_08           = 4.0f;
			mModeFunction = &modeWait;
			break;
		}
	}

	P2DPane* mRootPane;     // _00, unknown
	f32 _04;                // _04
	f32 _08;                // _08
	ModeFunc mModeFunction; // _0C
	modeFlag mMode;         // _18
	f32 _1C;                // _1C
};
} // namespace zen

void zen::DrawCMbest::init(P2DScreen* screen)
{
	_04 = screen->search('best', false);
	if (!_04) {
		_04 = screen->search('root', true);
	}

	_04->setOffset(_04->getWidth() >> 1, _04->getHeight() >> 1);
	char buf[8];
	_0C = 0;
	P2DPane* pane;
	do {
		sprintf(buf, "b_%02d", _0C);
		pane = screen->search(P2DPaneLibrary::makeTag(buf), false);
		if (pane) {
			_0C++;
		}
	} while (pane);

	mPicObjs = new DrawCMBpicObj[_0C];

	for (int i = 0; i < _0C; i++) {
		sprintf(buf, "b_%02d", i);
		pane = screen->search(P2DPaneLibrary::makeTag(buf), true);
		pane->setOffset(pane->getWidth() >> 1, pane->getHeight() >> 1);
		mPicObjs[i].setRootPane(pane);
	}

	setMode(MODE_Sleep);
}

void zen::DrawCMbest::sleep()
{
	setMode(MODE_Sleep);
}

void zen::DrawCMbest::update()
{
	for (int i = 0; i < _0C; i++) {
		mPicObjs[i].update();
	}
	(this->*mModeFunction)();
}

void zen::DrawCMbest::appear()
{
	setMode(MODE_Appear);
}

void zen::DrawCMbest::wait()
{
	setMode(MODE_Wait);
}

bool zen::DrawCMbest::modeSleep()
{
	return false;
}

bool zen::DrawCMbest::modeWait()
{
	return false;
}

bool zen::DrawCMbest::modeAppear()
{
	for (int i = 0; i < _0C; i++) {
		;
	}

	return false;
}

void zen::DrawCMbest::setMode(zen::DrawCMbest::modeFlag mode)
{
	int i;

	mMode = mode;
	switch (mMode) {
	case MODE_Sleep:
		mModeFunction = &modeSleep;
		for (i = 0; i < _0C; i++) {
			mPicObjs[i].sleep();
		}
		break;

	case MODE_Wait:
		mModeFunction = &modeWait;
		show();
		for (i = 0; i < _0C; i++) {
			mPicObjs[i].wait((_0C - i - 1) * 0.25f);
		}
		break;

	case MODE_Appear:
		mModeFunction = &modeAppear;
		show();
		for (i = 0; i < _0C; i++) {
			mPicObjs[i].appear(i * 0.25f);
		}
		break;
	}
}
