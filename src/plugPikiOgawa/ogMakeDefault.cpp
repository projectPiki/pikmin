#include "zen/ogMakeDefault.h"
#include "zen/ogSub.h"
#include "P2D/Screen.h"
#include "P2D/Picture.h"
#include "P2D/Graph.h"
#include "sysNew.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
// DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	8019399C
 * Size:	000360
 */
zen::ogScrMakeDefaultMgr::ogScrMakeDefaultMgr()
{
	mScreen = new P2DScreen;
	mScreen->set("screen/blo/data_pf.blo", true, true, true);
	mScreen2 = new P2DScreen;
	mScreen2->set("screen/blo/black.blo", false, false, true);

	_10 = (P2DPicture*)mScreen2->search('blck', true);
	_10->setAlpha(255);
	_1C = (P2DPicture*)mScreen->search('abtn', true);
	_24 = new setTenmetuAlpha(_1C, 1.0f);
	_1C->hide();

	_3C = (P2DTextBox*)mScreen->search('tx00', true);
	_40 = new TypingTextMgr(_3C);
	_28 = _40;

	_44 = mScreen->search('tx01', true);
	_48 = mScreen->search('tx02', true);
	_4C = mScreen->search('tx03', true);

	_18 = (P2DPicture*)mScreen->search('curs', true);
	_20 = new setTenmetuAlpha(_18, 0.5f);

	_2C = (P2DTextBox*)mScreen->search('pfok', true);
	_30 = new TypingTextMgr(_2C);

	_34 = (P2DTextBox*)mScreen->search('pfxx', true);
	_38 = new TypingTextMgr(_34);

	_50     = 0.0f;
	mStatus = Status_NULL;
}

/*
 * --INFO--
 * Address:	80193CFC
 * Size:	0000EC
 */
void zen::ogScrMakeDefaultMgr::start()
{
	mStatus = Status_2;
	_50     = 0.0f;
	_1C->hide();
	_44->hide();
	_48->hide();
	_4C->hide();
	_20->start();
	_28->off();
	_28 = _40;
	_28->start();
	_28->transCursor(_18);
}

/*
 * --INFO--
 * Address:	80193DE8
 * Size:	000354
 */
zen::ogScrMakeDefaultMgr::MakeDefaultStatus zen::ogScrMakeDefaultMgr::update(Controller* input)
{
	if (mStatus == Status_NULL) {
		return mStatus;
	}

	if (mStatus >= 4) {
		mStatus = Status_NULL;
		return mStatus;
	}

	_50 += gsys->getFrameTime();

	if (_50 > 1.0f) {
		_44->show();
	}
	if (_50 > 2.0f) {
		_48->show();
	}
	if (_50 > 3.0f) {
		_4C->show();
	}
	mScreen->update();
	mScreen2->update();
	_20->update();
	_24->update();
	_28->update();
	_28->transCursor(_18);

	if (mStatus == Status_2) {
		if (_50 < 0.5f) {
			_10->setAlpha(255 - (int)((_50 * 255.0f) / 0.5f));
		} else {
			mStatus = Status_0;
			_50     = 0.0f;
			gameflow.mMemoryCard.makeDefaultFile();
			_10->setAlpha(0);
		}
		return mStatus;
	} else if (mStatus == Status_3) {
		if (_50 < 0.5f) {
			_10->setAlpha((_50 * 255.0f) / 0.5f);
		} else {
			_10->setAlpha(255);
			mStatus = _04;
			_50     = 0.0f;
		}
		return mStatus;
	}

	switch (mStatus) {
	case Status_0:
		if (_50 > 2.0f && gameflow.mMemoryCard.hasCardFinished()) {
			BOOL save = !gameflow.mMemoryCard.didSaveFail();
			if (save) {
				_28->off();
				_28 = _30;
				_28->start();
				_04 = Status_4;
			} else {
				_28->off();
				_28 = _38;
				_28->start();
				_04 = Status_5;
			}
			_3C->hide();
			mStatus = Status_1;
			_50     = 0.0f;
			_24->start();
		}
		break;

	case Status_1:
		if (checkTypingAll()) {
			_1C->show();
			if (input->keyClick(KBBTN_A)) {
				seSystem->playSysSe(SYSSE_DECIDE1);
				mStatus = Status_3;
				_50     = 0.0f;
			}
		}
		break;
	}
	return mStatus;
}

/*
 * --INFO--
 * Address:	8019413C
 * Size:	0000A8
 */
void zen::ogScrMakeDefaultMgr::draw(Graphics& gfx)
{
	if (mStatus != Status_NULL && mStatus < Status_4) {
		P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
		graf.setPort();
		mScreen->draw(0, 0, &graf);
		mScreen2->draw(0, 0, &graf);
	}
}

/*
 * --INFO--
 * Address:	801941E4
 * Size:	000020
 */
bool zen::ogScrMakeDefaultMgr::checkTypingAll()
{
	if (_28->check() == 2) {
		return true;
	}
	return false;
}
