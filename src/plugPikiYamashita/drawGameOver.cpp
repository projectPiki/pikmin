#include "zen/DrawGameOver.h"
#include "zen/Math.h"
#include "P2D/Picture.h"
#include "sysNew.h"
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
DEFINE_PRINT("drawGameOver")

namespace zen {
/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct DrawGameOverLetter {
	DrawGameOverLetter()
	{
		_00        = 0;
		mLetterPic = 0;
		_10        = 0;
		_14        = 0;
		_18        = 0.0f;
		_1C        = 0.0f;
		_20        = 0.0f;
		_24        = 0.0f;
		_28        = 0.0f;
		_2C        = 0.0f;
		_04        = 0.0f;
		_08        = 0.0f;
	}

	// weak
	void init(P2DPane* pane)
	{
		if (pane->getTypeID() == PANETYPE_Picture) {
			mLetterPic = (P2DPicture*)pane;
			_10        = mLetterPic->getPosH();
			_14        = mLetterPic->getPosV();
			initParams();
		} else {
			PRINT("not picture pane.\n");
			ERROR("not picture pane.\n");
		}
	}
	void initParams()
	{
		_00 = 0;
		_04 = 0.0f;
		_08 = 0.0f;
		_18 = 320.0f;
		_1C = _14 - 480.0f;
		mLetterPic->move(RoundOff(_18), RoundOff(_1C));
		_20 = Rand(10.0f) - 5.0f;
		_24 = 0.0f;
		_28 = 0.0f;
		_2C = 0.0f;
	}
	bool update()
	{
		bool res = false;
		switch (_00) {
		case 0:
			break;
		case 1:
			_04 += gsys->getFrameTime();
			if (_04 > _08) {
				_04 = 0.0f;
				_00 = 2;
				mLetterPic->setScale(0.5f);
			}
			break;

		case 2:
			_24 += gsys->getFrameTime() * 7200.0f * gsys->getFrameTime();
			_1C += gsys->getFrameTime() * _24 * 30.0f;
			_18 += gsys->getFrameTime() * _20 * 30.0f;
			if (_1C > _14) {
				_20 = gsys->getFrameTime() * ((_10 - _18) / 3.0f) * 30.0f;
				if (_20 > 10.0f) {
					_20 = 10.0f;
				}
				if (_20 < -10.0f) {
					_20 = -10.0f;
				}
				_1C = _14;
				_24 *= Rand(0.2f) + -0.6f;
				_28 = gsys->getFrameTime() * (_20 * 0.1f) * 30.0f;
			}

			mLetterPic->move(RoundOff(_18), RoundOff(_1C));
			mLetterPic->rotateZ(mLetterPic->getWidth() >> 1, RoundOff(mLetterPic->getHeight() * 0.75f), mLetterPic->getRotate() + _28);
			_04 += gsys->getFrameTime();
			if (_04 > 1.7f) {
				_28 = 0.0f;
				_04 = 0.0f;
				_00 = 3;
				_2C = 0.0f;
			}
			break;

		case 3:
			_04 += gsys->getFrameTime();
			if (_04 > 5.0f) {
				_04 = 0.0f;
				_28 = PI / 10.0f;
				_2C = -0.2f;
			}

			if (mLetterPic->getRotate() < PI) {
				_28 += -mLetterPic->getRotate() * gsys->getFrameTime();
			} else {
				_28 += (TAU - mLetterPic->getRotate()) * gsys->getFrameTime();
			}

			_28 *= 0.95f;
			mLetterPic->rotateZ(mLetterPic->getWidth() >> 1, RoundOff(mLetterPic->getHeight() * 0.75f), mLetterPic->getRotate() + _28);
			Vector3f scale(mLetterPic->getScale());
			_2C += gsys->getFrameTime() * (1.0f - scale.x) * 4.0f;
			_2C *= 0.85f;
			mLetterPic->setScale(scale.x + _2C);
			break;
		}
		return res;
	}

	// DLL inlines to do:
	void start(f32 p1)
	{
		initParams();
		_00 = 1;
		_04 = 0.0f;
		_08 = p1;
	}

	int _00;                // _00
	f32 _04;                // _04
	f32 _08;                // _08
	P2DPicture* mLetterPic; // _0C
	int _10;                // _10
	int _14;                // _14
	f32 _18;                // _18
	f32 _1C;                // _1C
	f32 _20;                // _20
	f32 _24;                // _24
	f32 _28;                // _28
	f32 _2C;                // _2C
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct DrawGameOverScreen {
	DrawGameOverScreen(char* bloFileName)
	{
		mScreen      = new DrawScreen(bloFileName, nullptr, true, true);
		mLetterCount = 0;
		char buf[8];
		sprintf(buf, "go%02d", mLetterCount);
		while (mScreen->getScreenPtr()->search(P2DPaneLibrary::makeTag(buf), false)) {
			mLetterCount++;
			sprintf(buf, "go%02d", mLetterCount);
		}

		if (mLetterCount == 0) {
			PRINT("no letter Pane.\n");
			ERROR("no letter Pane.\n");
		}

		mLetters = new DrawGameOverLetter[mLetterCount];

		for (int i = 0; i < mLetterCount; i++) {
			sprintf(buf, "go%02d", i);
			P2DPane* pane = mScreen->getScreenPtr()->search(P2DPaneLibrary::makeTag(buf), true);
			mLetters[i].init(pane);
		}
	}

	// DLL inlines to do:
	void start()
	{
		for (int i = 0; i < mLetterCount; i++) {
			mLetters[i].start(f32(i) * 0.1f);
		}
	}
	bool update()
	{
		for (int i = 0; i < mLetterCount; i++) {
			mLetters[i].update();
		}
		mScreen->update();
		return false;
	}
	void draw(Graphics&) { mScreen->draw(); }

	DrawScreen* mScreen;          // _00
	int mLetterCount;             // _04
	DrawGameOverLetter* mLetters; // _08
};
} // namespace zen

/*
 * --INFO--
 * Address:	801E8900
 * Size:	000334
 */
zen::DrawGameOver::DrawGameOver()
{
	_04   = new DrawGameOverScreen("screen/blo/gameover.blo");
	_08   = new DrawGameOverScreen("screen/blo/gameove2.blo");
	_00   = 0;
	mMode = MODE_Unk0;
	_14   = 0.0f;
	_0C   = 0;
}

/*
 * --INFO--
 * Address:	801E8DCC
 * Size:	0000E8
 */
void zen::DrawGameOver::start(zen::DrawGameOver::modeFlag mode, f32 p2)
{
	_00   = 1;
	mMode = mode;
	_18   = p2;
	switch (mMode) {
	case MODE_Unk0:
		_0C = _04;
		break;

	case MODE_Unk1:
		_0C = _08;
		break;

	default:
		PRINT("Unknown mode %d \n", mMode);
		ERROR("Unknown mode %d \n", mMode);
		break;
	}

	_0C->start();
}

/*
 * --INFO--
 * Address:	801E8FE8
 * Size:	000118
 */
bool zen::DrawGameOver::update(Controller* controller)
{
	bool res = false;
	if (_00) {
		_14 += gsys->getFrameTime();
		switch (_00) {
		case 1:
			if (_14 > 2.0f) {
				_00 = 2;
				_14 = 0.0f;
			}
			break;

		case 2:
			if (controller->keyClick(KBBTN_START | KBBTN_A)) {
				res = true;
			}
			if (_14 > _18) {
				_14 = _18;
				res = true;
			}
			break;
		}
		_0C->update();
	}
	return res;
}

/*
 * --INFO--
 * Address:	801E9614
 * Size:	000040
 */
void zen::DrawGameOver::draw(Graphics& gfx)
{
	if (_00) {
		_0C->draw(gfx);
	}
}
