#include "zen/ogDiary.h"
#include "zen/ogResult.h"
#include "zen/ZenController.h"
#include "zen/DrawCommon.h"
#include "zen/ogMessage.h"
#include "zen/ogSub.h"
#include "zen/EffectMgr2D.h"
#include "P2D/Screen.h"
#include "P2D/Picture.h"
#include "P2D/Graph.h"
#include "PlayerState.h"
#include "Graphics.h"
#include "SoundMgr.h"
#include "Font.h"
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
DEFINE_PRINT("OgDiarySection")

namespace zen {
static char* bloFile_Diary_Table[10];
static char** bloFiles_default_Diary[2] = { &bloFile_Res_Table[1], nullptr };
static char** bloFiles_Diary[2]         = { bloFile_Diary_Table, nullptr };
}; // namespace zen

/*
 * --INFO--
 * Address:	8018F1F4
 * Size:	000150
 */
zen::ogScrDiaryMgr::ogScrDiaryMgr()
{
	Texture* tex = gsys->loadTexture("bigFont.bti", true);
	mFont        = new Font;
	mFont->setTexture(tex, 21, 42);

	mController = new ZenController(nullptr);
	mController->setRepeatTime(0.5f);

	mMesgMgr = new ogScrMessageMgr("screen/blo/tu_base.blo");
	mMesgMgr->MakeAndSetPageInfo(&bloFiles_default_Diary[0]);
	mMesgMgr->setLastPageAbutton(true);
	mMesgMgr->setSolidMode(false);
	P2DScreen* screen = mMesgMgr->getBaseScreenPtr();
	mPaneCapu         = screen->search('capu', true);
	screen->search('base', true)->hide();
	_08     = 0;
	_0C     = 0;
	mStatus = Status_Null;
}

/*
 * --INFO--
 * Address:	8018F344
 * Size:	0000FC
 */
zen::ogScrDiaryMgr::DiaryStatus zen::ogScrDiaryMgr::update(Controller* input)
{
	if (mStatus == Status_Null) {
		return mStatus;
	}

	int msgState = mMesgMgr->update(input);
	mController->setContPtr(input);
	mController->update();

	// controls for debug menu
	if (playerState == nullptr && mMesgMgr->checkDisp() && msgState == 0) {
		if (mController->keyRepeat(KBBTN_MSTICK_LEFT | KBBTN_DPAD_LEFT)) {
			backPage();
		} else if (mController->keyRepeat(KBBTN_MSTICK_RIGHT | KBBTN_DPAD_RIGHT)) {
			nextPage();
		} else if (input->keyClick(KBBTN_Y)) {
			typePage();
		} else if (input->keyClick(KBBTN_START)) {
			exit();
		}
	}

	return (DiaryStatus)msgState;
}

/*
 * --INFO--
 * Address:	8018F440
 * Size:	000178
 */
void zen::ogScrDiaryMgr::draw(Graphics& gfx)
{
	if (mStatus == Status_Null) {
		return;
	}
	mMesgMgr->draw(gfx);

	if (!playerState) {
		Matrix4f mtx;
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setColour(Colour(255, 255, 255, 255), true);
		gfx.setAuxColour(Colour(255, 255, 150, 255));

		char path[256];
		sprintf(path, "tx??の数(%d個)", mMesgMgr->getTxtLineMax());
		gfx.texturePrintf(mFont, 30, 20, mMesgMgr->getPageInfo()->mScreenResourcePath);
		gfx.texturePrintf(mFont, 30, 40, path);
	}
}

/*
 * --INFO--
 * Address:	8018F5B8
 * Size:	000294
 */
void zen::ogScrDiaryMgr::start(s16 a1, s16 day)
{
	if (playerState) {
		int max;
		int res = playerState->mResultFlags.getDayDocument(day, max);
		if (max == 0) {
			return;
		}
		if (max == 1) {
			mPaneCapu->hide();
		} else {
			mPaneCapu->show();
		}
		if (max >= 10) {
			max = 9;
		}

		for (int i = 0; i < max; i++) {
			bloFile_Diary_Table[i] = bloFile_Res_Table[res + i];
			PRINT("Diary blo[%d] = \'%s\' (%d)\n", i, bloFile_Diary_Table[i], res + i);
		}

		bloFile_Diary_Table[max] = "END";
		mMesgMgr->MakeAndSetPageInfo(bloFiles_Diary);
	}
	mStatus = Status_0;
	mMesgMgr->setLastPageAbutton(true);
	setSpecialNumber(1, day);
	mMesgMgr->start(-1);
	mMesgMgr->setPage(0);
	mMesgMgr->move(_08, _0C);
	mMesgMgr->dispAll();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void zen::ogScrDiaryMgr::setDiarySpecialNumber(s16 day)
{
	int partsDay = 77;
	int daysleft = 30 - day;
	int parts    = 77;
	int powerup  = 77;
	if (playerState) {
		partsDay = playerState->getDayCollectCount(day - 1);
		parts    = playerState->getTotalParts();
		parts -= partsDay;
		powerup = playerState->getDayPowerupCount(day - 1);
	}
	setSpecialNumber(1, day);
	setSpecialNumber(2, partsDay);
	setSpecialNumber(3, parts);
	setSpecialNumber(4, daysleft);
	setSpecialNumber(5, powerup);
}

/*
 * --INFO--
 * Address:	8018F84C
 * Size:	00009C
 */
void zen::ogScrDiaryMgr::typePage()
{
	mMesgMgr->setLastPageAbutton(false);
	mMesgMgr->start(-1);
	mMesgMgr->resetPage();
	mMesgMgr->move(_08, _0C);
}

/*
 * --INFO--
 * Address:	8018F8E8
 * Size:	0000C8
 */
bool zen::ogScrDiaryMgr::nextPage()
{
	if (mMesgMgr->getPageInfo()->mMsgSegmentCount <= 1) {
		return false;
	}

	mMesgMgr->setLastPageAbutton(true);
	mMesgMgr->nextPage();
	mMesgMgr->move(_08, _0C);
	mMesgMgr->dispAll();
	return true;
}

/*
 * --INFO--
 * Address:	8018F9B0
 * Size:	0000A0
 */
void zen::ogScrDiaryMgr::backPage()
{
	mMesgMgr->setLastPageAbutton(true);
	mMesgMgr->backPage();
	mMesgMgr->move(_08, _0C);
	mMesgMgr->dispAll();
}

/*
 * --INFO--
 * Address:	8018FA50
 * Size:	000024
 */
void zen::ogScrDiaryMgr::exit()
{
	mMesgMgr->fadeOut();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void zen::ogScrDiaryMgr::setCursorXY(P2DTextBox* textBox)
{
	mMesgMgr->setCursorXY(textBox);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void zen::ogScrDiaryMgr::updateDiary(Controller* input)
{
	_24     = 0;
	int res = _1C->update(input);
	if (res == 0) {
		int selRes = _20->update(input) + 1;
		if (selRes != 0) {
			s16 day = playerState->getCurrDay();
			if (day > 0) {
				f32 x = _20->getOpenX();
				f32 y = _20->getOpenY();
				_1C->open(x, y, day);
			}
		}
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018FA74
 * Size:	000158
 */
zen::ogDrawDiary::ogDrawDiary()
{
	mScreen = new P2DScreen();
	mScreen->set("screen/blo/m_menu_b.blo", true, true, true);
	mScreenScale = 0.0f;
	mStatus      = Status_0;
	mScreen->setScale(mScreenScale);
	mEfxMgr      = new EffectMgr2D(16, 0x400, 0x400);
	mDiaryMgr    = new ogScrDiaryMgr;
	mScreenScale = 0.0f;
	mStatus      = Status_0;
	_14          = 320.0f;
	_18          = 240.0f;
	mScreen->setOffset(320, 240);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void zen::ogDrawDiary::start()
{
	mScreenScale = 0.0f;
	mStatus      = Status_0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
void zen::ogDrawDiary::setOffset()
{
	mScreen->setOffset(_14, _18);
	mDiaryMgr->getScrMsgMgr()->getScreenPtr()->setOffset(_14, _18);
	mDiaryMgr->getScrMsgMgr()->getBaseScreenPtr()->setOffset(_14, _18);
}

/*
 * --INFO--
 * Address:	8018FBCC
 * Size:	000298
 */
void zen::ogDrawDiary::open(f32 a1, f32 a2, s16 day)
{
	mDiaryMgr->setDiarySpecialNumber(day);
	if (mStatus == Status_0) {
		mScreenScale = 0.01f;
		mStatus      = Status_1;
		_14          = a1;
		_18          = a2;
		_1C          = _14;
		_20          = _18;
		setOffset();
		mDiaryMgr->start(0, day);
		Vector3f pos;
		pos.set(320.0f, 240.0f, 0.0f);
		mEfxMgr->create(EFF2D_Unk4, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk5, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk6, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk7, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk8, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk9, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk10, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk11, pos, nullptr, nullptr);
	}
}

/*
 * --INFO--
 * Address:	8018FE64
 * Size:	0002B8
 */
zen::ogDrawDiary::DiaryStatus zen::ogDrawDiary::update(Controller* input)
{
	if (mStatus == Status_0) {
		return mStatus;
	}

	if (mStatus == 1) {
		mScreenScale *= 1.5f;
		if (mScreenScale >= 1.0f) {
			mScreenScale = 1.0f;
			mStatus      = Status_2;
		}
	}

	if (mStatus == 2) {
		if (input->keyClick(KBBTN_B)) {
			mStatus = Status_3;
			mEfxMgr->killAll(true);
			seSystem->playSysSe(SYSSE_CANCEL);
		} else if (input->keyClick(KBBTN_A)) {
			if (mDiaryMgr->nextPage()) {
				seSystem->playSysSe(YMENU_SELECT2);
			}
		}
	}

	if (mStatus == 3) {
		mScreenScale *= 0.6666667f;
		if (mScreenScale <= 0.01f) {
			mScreenScale = 0.0f;
			mStatus      = Status_0;
		}
	}

	setOffset();
	mScreen->setScale(mScreenScale);
	mScreen->update();
	mDiaryMgr->setScale(mScreenScale);
	mDiaryMgr->update(input);
	mEfxMgr->update();
	return mStatus;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A8
 */
void zen::ogDrawDiary::draw(Graphics& gfx)
{
	if (mStatus != Status_0) {
		mScreen->draw(0, 0, nullptr);
		mEfxMgr->draw(gfx);
		mDiaryMgr->draw(gfx);
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019011C
 * Size:	000430
 */
zen::ogDrawSelectDiary::ogDrawSelectDiary()
{
	mScreen = new P2DScreen;
	mScreen->set("screen/blo/m_menu_r.blo", true, true, true);
	_2C4 = new P2DScreen;
	_2C4->set("screen/blo/black.blo", false, false, true);
	_2C8 = (P2DPicture*)_2C4->search('blck', true);
	_2C8->setAlpha(255);
	mController = new ZenController(nullptr);
	mController->setRepeatTime(0.2f);
	_2CC = (P2DPicture*)mScreen->search('abtn', true);
	_2D0 = new setTenmetuAlpha(_2CC, 1.0f);
	_2D4 = new ogDrawDiary;
	mDay = 0;

	for (int i = 0; i < 30; i++) {
		char name[4];
		sprintf(name, "i%02du", i);
		_68[i] = mScreen->search(P2DPaneLibrary::makeTag(name), true);
		_68[i]->hide();

		sprintf(name, "i%02dd", i);
		_E0[i] = mScreen->search(P2DPaneLibrary::makeTag(name), true);
		_E0[i]->hide();

		sprintf(name, "pi%02d", i);
		_1D0[i] = mScreen->search(P2DPaneLibrary::makeTag(name), true);

		sprintf(name, "pk%02d", i + 14);
		_248[i] = (P2DPicture*)mScreen->search(P2DPaneLibrary::makeTag(name), true);
	}

	_2E0    = 0;
	_2E2    = 0;
	_2E4    = 0;
	_2E6    = 0;
	_2EC    = 0.0f;
	mStatus = SELECT_NULL;
	setCursorAlpha();
}

/*
 * --INFO--
 * Address:	8019054C
 * Size:	0001C8
 */
void zen::ogDrawSelectDiary::start()
{
	if (playerState) {
		mDay = playerState->getCurrDay() - 1;
		PRINT("ogDrawSelectDiary  currDay = (%d)\n", mDay);
	} else {
		mDay = 15;
	}
	if (mDay < 0) {
		return;
	}
	mStatus = SELECT_1;
	_2EC    = 0.0f;
	_2E0    = 0;
	_2E2    = 0;
	_2E4    = 0;
	_2E6    = 0;
	_2C8->setAlpha(255);

	for (int i = 0; i < 30; i++) {
		if (i > mDay) {
			P2DPaneLibrary::setFamilyAlpha(_1D0[i], 80);
		} else {
			P2DPaneLibrary::setFamilyAlpha(_1D0[i], 255);
		}
	}

	for (int i = mDay + 1; i < 30; i++) {
		P2DPicture* obj = (P2DPicture*)_248[i]->getPaneTree()->getParent()->getObject();
		obj->setAlpha(0);
	}
	_2D0->start();
	setCursorAlpha();
}

/*
 * --INFO--
 * Address:	80190714
 * Size:	00010C
 */
void zen::ogDrawSelectDiary::setCursorAlpha()
{
	P2DPane* pane = mScreen->search('root', true);
	f32 x         = _68[0]->getPosH();
	f32 y         = _68[0]->getPosV();
	_08.init(mScreen, pane, 'z00l', x, y);
	x = _E0[0]->getPosH();
	y = _E0[0]->getPosV();
	_38.init(mScreen, pane, 'z00r', x, y);
	MoveCursor();
}

/*
 * --INFO--
 * Address:	80190820
 * Size:	000104
 */
bool zen::ogDrawSelectDiary::MoveCursor()
{
	s16 sel = _2E0 + _2E2 * 10;
	if (sel > mDay) {
		return true;
	}
	_2E4 = sel;

	f32 x = _68[_2E4]->getPosH();
	f32 y = _68[_2E4]->getPosV();
	_08.move(x, y, 0.25f);

	x = _E0[_2E4]->getPosH();
	y = _E0[_2E4]->getPosV();
	_38.move(x, y, 0.25f);
	return false;
}

/*
 * --INFO--
 * Address:	80190924
 * Size:	000880
 */
zen::ogDrawSelectDiary::SelectDiaryStatus zen::ogDrawSelectDiary::update(Controller* input)
{
	if (mStatus == SELECT_NULL) {
		return mStatus;
	}
	_2EC += gsys->getFrameTime();
	if (mStatus == SELECT_4) {
		mStatus = SELECT_NULL;
		return mStatus;
	}
	mController->setContPtr(input);
	mController->update();
	if (mStatus == SELECT_1) {
		if (_2EC > 0.5f) {
			mStatus = SELECT_0;
			return mStatus;
		}
		_2C8->setAlpha((1.0f - _2EC / 0.5f) * 255.0f);
	}

	if (mStatus == SELECT_2) {
		if (_2EC > 0.5f) {
			mStatus = SELECT_4;
			return mStatus;
		}
		_2C8->setAlpha((_2EC / 0.5f) * 255.0f);
	}

	if (mStatus == SELECT_0) {
		if (input->keyClick(KBBTN_A | KBBTN_START)) {
			P2DPane* pane = _1D0[_2E4];
			f32 x         = pane->getPosH() + pane->getWidth() / 2;
			f32 y         = pane->getPosV() + pane->getHeight() / 2;
			_2D4->open(x, y, _2E4 + 1);
			seSystem->playSysSe(SYSSE_DECIDE1);
			mStatus = SELECT_3;
			return mStatus;
		}

		if (input->keyClick(KBBTN_B | KBBTN_Y)) {
			mStatus = SELECT_2;
			_2EC    = 0.0f;
			return mStatus;
		}

		if (mController->keyRepeat(KBBTN_MSTICK_LEFT) && _2E0 > 0) {
			_2E0--;
			if (MoveCursor()) {
				_2E0++;
			} else {
				seSystem->playSysSe(SYSSE_MOVE1);
			}
		} else if (mController->keyRepeat(KBBTN_MSTICK_RIGHT) && _2E0 < 9) {
			_2E0++;
			if (MoveCursor()) {
				_2E0--;
			} else {
				seSystem->playSysSe(SYSSE_MOVE1);
			}
		} else if (mController->keyRepeat(KBBTN_MSTICK_UP) && _2E2 > 0) {
			_2E2--;
			if (MoveCursor()) {
				_2E2++;
			} else {
				seSystem->playSysSe(SYSSE_MOVE1);
			}
		} else if (mController->keyRepeat(KBBTN_MSTICK_DOWN) && _2E2 < 2) {
			_2E2++;
			if (MoveCursor()) {
				_2E2--;
			} else {
				seSystem->playSysSe(SYSSE_MOVE1);
			}
		}
		_08.update();
		_38.update();
		_2D0->update();
	}

	mScreen->update();
	_2D8 = _2D4->update(input);
	_2C4->update();
	for (int i = mDay + 1; i < 30; i++) {
		P2DPicture* obj = (P2DPicture*)_248[i]->getPaneTree()->getParent()->getObject();
		obj->setAlpha(0);
	}

	for (int i = 0; i <= mDay; i++) {
		f32 a = _2EC;
		if (a >= 1.0f) {
			a -= 1.0f;
		}
		a -= f32(i) * 0.1f;
		f32 scale = 0.05f * sinf(TAU * a) + 1.0f;
		_1D0[i]->setOffset(_1D0[i]->getWidth() / 2, _1D0[i]->getHeight() / 2);
		_1D0[i]->setScale(scale);
	}

	if (mStatus == SELECT_3 && _2D8 == 0) {
		mStatus = SELECT_0;
	}

	return mStatus;
}

/*
 * --INFO--
 * Address:	801911A4
 * Size:	0000F0
 */
void zen::ogDrawSelectDiary::draw(Graphics& gfx)
{
	if (mStatus != SELECT_NULL) {
		P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
		graf.setPort();
		mScreen->draw(0, 0, &graf);
		_2D4->draw(gfx);
		_2C4->draw(0, 0, &graf);
	}
}
