#include "zen/DrawSave.h"
#include "zen/Math.h"
#include "P2D/Picture.h"
#include "P2D/TextBox.h"
#include "nlib/Math.h"
#include "SoundMgr.h"
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
DEFINE_PRINT("drawSaveMes")

/*
 * --INFO--
 * Address:	801F265C
 * Size:	000348
 */
zen::DrawSaveMes::DrawSaveMes()
{
	_08 = new DrawScreen("screen/blo/cha_sav2.blo", nullptr, true, true);
	_0C = new DrawScreen("screen/blo/ac_chui.blo", nullptr, true, true);

	P2DScreen* screen = _08->getScreenPtr();
	screen->setScale(0.0f);
	screen->setOffset(screen->getWidth() >> 1, screen->getHeight() >> 1);
	_18 = (P2DTextBox*)screen->search('savk', true);
	_1C = (P2DTextBox*)screen->search('save', true);
	_20 = (P2DTextBox*)screen->search('sakc', true);
	_24 = (P2DTextBox*)screen->search('sa_c', true);
	_28 = (P2DTextBox*)screen->search('saks', true);
	_2C = (P2DTextBox*)screen->search('sa_s', true);
	_30 = (P2DPicture*)screen->search('abtn', true);

	_18->show();
	_1C->show();
	_20->show();
	_24->show();
	_28->show();
	_2C->show();

	screen = _0C->getScreenPtr();
	screen->setOffset(screen->getWidth() >> 1, screen->getHeight() >> 1);
	mBackIcon = (P2DPicture*)screen->search('back', true);
	mBackIcon->show();
	mBackIcon->setAlpha(0);
	_14 = (P2DPicture*)screen->search('chui', true);
	_14->setOffset(_14->getWidth() >> 1, _14->getHeight() >> 1);
	_04 = 0.0f;

	_08->getScreenPtr()->hide();
	_0C->getScreenPtr()->hide();
	setMode(MODE_Sleep);
}

/*
 * --INFO--
 * Address:	801F29A4
 * Size:	000024
 */
void zen::DrawSaveMes::sleep()
{
	setMode(MODE_Sleep);
}

/*
 * --INFO--
 * Address:	801F29C8
 * Size:	000050
 */
void zen::DrawSaveMes::mesAppear()
{
	_04 = 0.0f;
	setMode(MODE_Unk0);
	_08->makeResident();
	_0C->makeResident();
}

/*
 * --INFO--
 * Address:	801F2A18
 * Size:	000048
 */
void zen::DrawSaveMes::saveFinish()
{
	setMode(MODE_Unk4);
	_08->makeResident();
	_0C->makeResident();
}

/*
 * --INFO--
 * Address:	801F2A60
 * Size:	000024
 */
void zen::DrawSaveMes::saveError()
{
	setMode(MODE_Unk7);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void zen::DrawSaveMes::hide()
{
	_08->getScreenPtr()->hide();
	_0C->getScreenPtr()->hide();
}

/*
 * --INFO--
 * Address:	801F2A84
 * Size:	0008A4
 */
bool zen::DrawSaveMes::update(Controller* controller)
{
	bool res = false;
	switch (mMode) {
	case MODE_Sleep:
	case MODE_Unk6:
		res = true;
		break;

	case MODE_Unk5:
		_04 += gsys->getFrameTime();
		f32 tmp1;
		if (_04 > 0.5f) {
			tmp1 = 0.0f;
			setMode(MODE_Unk6);
		} else {
			tmp1 = 1.0f - NMathF::sin(_04 / 0.5f * HALF_PI);
		}
		_08->getScreenPtr()->setScale(tmp1);
		mBackIcon->setAlpha(RoundOff(200.0f * tmp1));
		_18->setAlpha(255);
		_1C->setAlpha(80);
		_20->setAlpha(0);
		_24->setAlpha(0);
		_28->setAlpha(0);
		_2C->setAlpha(0);
		_14->hide();
		_14->move(_14->getPosH(), _14->getPosV() + 480);
		break;

	case MODE_Unk0:
		_04 += gsys->getFrameTime();
		if (_04 > 0.5f) {
			tmp1 = 1.0f;
			setMode(MODE_Unk1);
		} else {
			tmp1 = NMathF::sin(_04 / 0.5f * HALF_PI);
		}
		_08->getScreenPtr()->setScale(tmp1);
		mBackIcon->setAlpha(RoundOff(200.0f * tmp1));
		_18->setAlpha(255);
		_1C->setAlpha(80);
		_20->setAlpha(0);
		_24->setAlpha(0);
		_28->setAlpha(0);
		_2C->setAlpha(0);
		P2DPaneLibrary::setFamilyAlpha(_30, 0);
		_14->hide();
		_14->move(_14->getPosH(), _14->getPosV() + 480);
		break;

	case MODE_Unk1:
		if (controller->keyClick(KBBTN_START | KBBTN_A)) {
#if defined(VERSION_G98E01_PIKIDEMO)
			SeSystem::playSysSe(SE_CHAPPY_WALK);
#else
			SeSystem::playSysSe(SYSSE_DECIDE1);
#endif
			setMode(MODE_Unk2);
		}
		if (controller->keyClick(KBBTN_B)) {
#if defined(VERSION_G98E01_PIKIDEMO)
			SeSystem::playSysSe(SE_FLOG_HIJUMP);
#else
			SeSystem::playSysSe(SYSSE_CANCEL);
#endif
			setMode(MODE_Unk5);
		} else {
			_04 += gsys->getFrameTime();
			if (_04 > 2.0f) {
				_04 -= 2.0f;
				tmp1 = 1.0f;
			} else {
				tmp1 = _04 / 2.0f;
			}

			P2DPaneLibrary::setFamilyAlpha(_30, RoundOff((1.0f - NMathF::cos(TAU * tmp1)) * 127.5f));
		}
		break;

	case MODE_Unk2:
		_04 += gsys->getFrameTime();
		tmp1 = 1.0f;
		f32 tmp2;
		if (_04 > tmp1) {
			tmp1 = 1.0f;
			tmp2 = 0.0f;
			setMode(MODE_Unk3);
		} else {
			tmp1 = NMathF::sin(_04 / tmp1 * HALF_PI);
			tmp2 = 1.0f - tmp1;
		}
		_18->setAlpha(RoundOff(255.0f * tmp2));
		_1C->setAlpha(RoundOff(80.0f * tmp2));
		_20->setAlpha(RoundOff(255.0f * tmp1));
		_24->setAlpha(RoundOff(80.0f * tmp1));
		_28->setAlpha(0);
		_2C->setAlpha(0);
		_14->move(_14->getPosH(), RoundOff(300.0f * tmp1 + 480.0f * tmp2));
		break;

	case MODE_Unk3:
		_04 += gsys->getFrameTime();
		if (_04 > 1.5f) {
			res = true;
		}
		break;

	case MODE_Unk4:
		_04 += gsys->getFrameTime();

		if (_04 > 0.5f) {
			tmp1 = 1.0f;
			tmp2 = 0.0f;
			setMode(MODE_Finish);
		} else {
			tmp2 = NMathF::cos(HALF_PI * _04 / 0.5f);
			tmp1 = 1.0f - tmp2;
		}
		_18->setAlpha(0);
		_1C->setAlpha(0);
		_20->setAlpha(RoundOff(255.0f * tmp2));
		_24->setAlpha(RoundOff(80.0f * tmp2));
		_28->setAlpha(RoundOff(255.0f * tmp1));
		_2C->setAlpha(RoundOff(80.0f * tmp1));
		_14->move(_14->getPosH(), RoundOff(300.0f * tmp2 + 480.0f * tmp1));
		break;

	case MODE_Finish:
		res = true;
		break;

	case MODE_Unk7:
		if (mSaveFailure.update(controller)) {
			_04 += gsys->getFrameTime();
			if (_04 > 0.5f) {
				tmp1 = 0.0f;
				setMode(MODE_Finish);
			} else {
				tmp1 = 1.0f - (_04 / 0.5f);
			}
			_08->getScreenPtr()->setScale(tmp1);
			mBackIcon->setAlpha(RoundOff(200.0f * tmp1));
			_14->setScale(tmp1);
		}
		break;
	}

	STACK_PAD_VAR(1);

	_08->update();
	_0C->update();
	return res;
}

/*
 * --INFO--
 * Address:	801F3328
 * Size:	000068
 */
void zen::DrawSaveMes::draw(Graphics& gfx)
{
	_0C->draw();
	_08->draw();
	mSaveFailure.draw(gfx);
}

/*
 * --INFO--
 * Address:	801F3390
 * Size:	0001D0
 */
void zen::DrawSaveMes::setMode(zen::DrawSaveMes::modeFlag mode)
{
	mMode = mode;
	switch (mMode) {
	case MODE_Sleep:
		_08->getScreenPtr()->hide();
		_0C->getScreenPtr()->hide();
		break;

	case MODE_Unk0:
		_04 = 0.0f;
		_08->getScreenPtr()->show();
		_08->getScreenPtr()->setScale(0.0f);
		_0C->getScreenPtr()->show();
		_14->hide();
		_14->move(_14->getPosH(), 480);
		mBackIcon->setAlpha(0);
		mSaveFailure.init();
		break;

	case MODE_Unk4:
		_04 = 0.0f;
		_08->getScreenPtr()->show();
		_0C->getScreenPtr()->show();
		_14->show();
		mSaveFailure.init();
		break;

	case MODE_Unk1:
		_04 = 0.0f;
		_14->hide();
		break;

	case MODE_Unk2:
		_04 = 0.0f;
		_14->setScale(1.0f);
		_14->show();
		break;

	case MODE_Unk5:
		_04 = 0.0f;
		break;

	case MODE_Unk7:
		_04 = 0.0f;
		mSaveFailure.open(1.0f);
		break;

	case MODE_Unk3:
		_04 = 0.0f;
		break;

	case MODE_Finish:
		PRINT("finish \n");
		break;

	default:
		PRINT("Unknown mode : %d \n", mMode);
		ERROR("Unknown mode : %d \n", mMode);
		break;
	}
}
