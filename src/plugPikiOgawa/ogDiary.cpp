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
// DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT(nullptr)

namespace zen {
char** bloFiles_default_Diary = bloFile_Res_Table;
char* bloFile_Diary_Table[10];
char** bloFiles_Diary = bloFile_Diary_Table;
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
	mMesgMgr->MakeAndSetPageInfo(&bloFiles_default_Diary);
	mMesgMgr->setLastPageAbutton(true);
	mMesgMgr->setSolidMode(false);
	P2DScreen* screen = mMesgMgr->getScreenPtr();
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
		gfx.texturePrintf(mFont, 30, 20, mMesgMgr->getPageInfo()->_00);
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
		mMesgMgr->MakeAndSetPageInfo(&bloFiles_Diary);
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
	if (mMesgMgr->getPageInfo()->_06 <= 1) {
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
	_24 = 0;
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
	mDiaryMgr->getScrMsgMgr()->getBaseScreenPtr()->setOffset(_14, _18);
	mDiaryMgr->getScrMsgMgr()->getScreenPtr()->setOffset(_14, _18);
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
		_248[i]->setAlpha(0);
	}
	_2D0->start();
	setCursorAlpha();
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  lwz       r0, 0x2F6C(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  mr        r3, r0
	  bl        -0x10F9C8
	  subi      r0, r3, 0x1
	  sth       r0, 0x2E8(r31)
	  b         .loc_0x44

	.loc_0x3C:
	  li        r0, 0xF
	  sth       r0, 0x2E8(r31)

	.loc_0x44:
	  lha       r0, 0x2E8(r31)
	  cmpwi     r0, 0
	  blt-      .loc_0x1AC
	  li        r0, 0x1
	  stw       r0, 0x0(r31)
	  li        r29, 0
	  rlwinm    r0,r29,2,0,29
	  lfs       f0, -0x4EC8(r2)
	  li        r3, 0
	  li        r4, 0xFF
	  stfs      f0, 0x2EC(r31)
	  add       r30, r31, r0
	  sth       r3, 0x2E0(r31)
	  sth       r3, 0x2E2(r31)
	  sth       r3, 0x2E4(r31)
	  sth       r3, 0x2E6(r31)
	  lwz       r3, 0x2C8(r31)
	  stb       r4, 0xF0(r3)

	.loc_0x8C:
	  lha       r0, 0x2E8(r31)
	  cmpw      r29, r0
	  ble-      .loc_0xA8
	  lwz       r3, 0x1D0(r30)
	  li        r4, 0x50
	  bl        0x2F2EC
	  b         .loc_0xB4

	.loc_0xA8:
	  lwz       r3, 0x1D0(r30)
	  li        r4, 0xFF
	  bl        0x2F2DC

	.loc_0xB4:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x1E
	  addi      r30, r30, 0x4
	  blt+      .loc_0x8C
	  lha       r3, 0x2E8(r31)
	  li        r5, 0
	  addi      r3, r3, 0x1
	  cmpwi     r3, 0x1E
	  rlwinm    r0,r3,2,0,29
	  add       r6, r31, r0
	  subfic    r3, r3, 0x1E
	  bge-      .loc_0x19C
	  rlwinm.   r0,r3,29,3,31
	  mtctr     r0
	  beq-      .loc_0x180

	.loc_0xF0:
	  lwz       r4, 0x248(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x24C(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x250(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x254(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x258(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x25C(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x260(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x264(r6)
	  addi      r6, r6, 0x20
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  bdnz+     .loc_0xF0
	  andi.     r3, r3, 0x7
	  beq-      .loc_0x19C

	.loc_0x180:
	  mtctr     r3

	.loc_0x184:
	  lwz       r4, 0x248(r6)
	  addi      r6, r6, 0x4
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  bdnz+     .loc_0x184

	.loc_0x19C:
	  lwz       r3, 0x2D0(r31)
	  bl        -0x11070
	  mr        r3, r31
	  bl        .loc_0x1C8

	.loc_0x1AC:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr

	.loc_0x1C8:
	*/
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
			f32 x = _1D0[_2E4]->getPosH() + _1D0[_2E4]->getWidth() / 2;
			f32 y = _1D0[_2E4]->getPosV() + _1D0[_2E4]->getHeight() / 2;
			_2D4->open(x, y, _2E4 + 1);
			seSystem->playSysSe(SYSSE_DECIDE1);
			mStatus = SELECT_3;
			return mStatus;
		}

		if (input->keyClick(KBBTN_MSTICK_UP)) {
			mStatus = SELECT_3;
			_2EC    = 0.0f;
			return mStatus;
		}

		if (_2E0 > 0 && input->keyDown(KBBTN_MSTICK_LEFT)) {
			_2E0--;
			if (MoveCursor()) {
				_2E0++;
			} else {
				seSystem->playSysSe(SYSSE_MOVE1);
			}
		} else if (_2E0 > 8 && input->keyDown(KBBTN_MSTICK_RIGHT)) {
			_2E0--;
			if (MoveCursor()) {
				_2E0--;
			} else {
				seSystem->playSysSe(SYSSE_MOVE1);
			}
		} else if (_2E2 < 0 && input->keyDown(KBBTN_MSTICK_UP)) {
			_2E2--;
			if (MoveCursor()) {
				_2E2++;
			} else {
				seSystem->playSysSe(SYSSE_MOVE1);
			}
		} else if (_2E2 > 2 && input->keyDown(KBBTN_MSTICK_DOWN)) {
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
		_248[i]->setAlpha(0);
	}

	for (int i = 0; i <= mDay; i++) {
		f32 a = _2EC;
		if (a >= 1.0f) {
			a = a - 1.0f;
		}
		f32 scale = sinf((a - i * 0.1f) * TAU);
		_1D0[i]->setOffset(_1D0[i]->getWidth() / 2, _1D0[i]->getHeight() / 2);
		_1D0[i]->setScale(scale * 0.05f + 1.0f);
	}

	if (mStatus == SELECT_3 && _2D8 == 0) {
		mStatus = SELECT_0;
	}

	return mStatus;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1A0(r1)
	  stfd      f31, 0x198(r1)
	  stfd      f30, 0x190(r1)
	  stfd      f29, 0x188(r1)
	  stfd      f28, 0x180(r1)
	  stfd      f27, 0x178(r1)
	  stw       r31, 0x174(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x170(r1)
	  mr        r30, r3
	  stw       r29, 0x16C(r1)
	  stw       r28, 0x168(r1)
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x48
	  b         .loc_0x84C

	.loc_0x48:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2EC(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2EC(r30)
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x4
	  bne-      .loc_0x78
	  li        r0, -0x1
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x84C

	.loc_0x78:
	  lwz       r3, 0x2DC(r30)
	  stw       r31, 0x0(r3)
	  lwz       r3, 0x2DC(r30)
	  bl        0x2F9FC
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xDC
	  lfs       f1, 0x2EC(r30)
	  lfs       f0, -0x4ED8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xB4
	  li        r0, 0
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x84C

	.loc_0xB4:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x4EB4(r2)
	  lfs       f2, -0x4EA4(r2)
	  lwz       r3, 0x2C8(r30)
	  fsubs     f0, f1, f0
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x160(r1)
	  lwz       r0, 0x164(r1)
	  stb       r0, 0xF0(r3)

	.loc_0xDC:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x128
	  lfs       f1, 0x2EC(r30)
	  lfs       f0, -0x4ED8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x108
	  li        r0, 0x4
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x84C

	.loc_0x108:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x4EA4(r2)
	  lwz       r3, 0x2C8(r30)
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x160(r1)
	  lwz       r0, 0x164(r1)
	  stb       r0, 0xF0(r3)

	.loc_0x128:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x668
	  lis       r3, 0x100
	  lwz       r4, 0x28(r31)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0x1DC
	  lha       r6, 0x2E4(r30)
	  lis       r5, 0x4330
	  lfd       f2, -0x4ED0(r2)
	  rlwinm    r0,r6,2,0,29
	  lwz       r3, 0x2D4(r30)
	  add       r4, r30, r0
	  lwz       r9, 0x1D0(r4)
	  addi      r4, r6, 0x1
	  lha       r7, 0x18(r9)
	  lha       r0, 0x1C(r9)
	  lha       r8, 0x1A(r9)
	  sub       r6, r0, r7
	  lha       r0, 0x1E(r9)
	  srawi     r6, r6, 0x1
	  addze     r6, r6
	  sub       r0, r0, r8
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r6, r7, r6
	  add       r0, r8, r0
	  xoris     r6, r6, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r6, 0x164(r1)
	  stw       r0, 0x15C(r1)
	  stw       r5, 0x160(r1)
	  stw       r5, 0x158(r1)
	  lfd       f1, 0x160(r1)
	  lfd       f0, 0x158(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        -0xF18
	  li        r3, 0x111
	  bl        -0xEB778
	  li        r0, 0x3
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x84C

	.loc_0x1DC:
	  andi.     r0, r4, 0xA000
	  beq-      .loc_0x1FC
	  li        r0, 0x2
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x4EC8(r2)
	  stfs      f0, 0x2EC(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x84C

	.loc_0x1FC:
	  lwz       r3, 0x2DC(r30)
	  lwz       r4, 0x4(r3)
	  rlwinm.   r0,r4,0,9,9
	  beq-      .loc_0x318
	  lha       r3, 0x2E0(r30)
	  cmpwi     r3, 0
	  ble-      .loc_0x318
	  subi      r0, r3, 0x1
	  sth       r0, 0x2E0(r30)
	  lha       r0, 0x2E2(r30)
	  lha       r4, 0x2E0(r30)
	  mulli     r3, r0, 0xA
	  lha       r0, 0x2E8(r30)
	  add       r3, r4, r3
	  extsh     r3, r3
	  cmpw      r3, r0
	  ble-      .loc_0x248
	  li        r0, 0x1
	  b         .loc_0x2F4

	.loc_0x248:
	  sth       r3, 0x2E4(r30)
	  lis       r29, 0x4330
	  addi      r3, r30, 0x8
	  lha       r0, 0x2E4(r30)
	  lfd       f2, -0x4ED0(r2)
	  rlwinm    r0,r0,2,0,29
	  lfs       f3, -0x4EA8(r2)
	  add       r4, r30, r0
	  lwz       r5, 0x68(r4)
	  lha       r4, 0x18(r5)
	  lha       r0, 0x1A(r5)
	  xoris     r4, r4, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x15C(r1)
	  stw       r0, 0x164(r1)
	  stw       r29, 0x158(r1)
	  stw       r29, 0x160(r1)
	  lfd       f1, 0x158(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x49FE8
	  lha       r0, 0x2E4(r30)
	  addi      r3, r30, 0x38
	  lfd       f2, -0x4ED0(r2)
	  rlwinm    r0,r0,2,0,29
	  lfs       f3, -0x4EA8(r2)
	  add       r4, r30, r0
	  lwz       r5, 0xE0(r4)
	  lha       r4, 0x18(r5)
	  lha       r0, 0x1A(r5)
	  xoris     r4, r4, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x154(r1)
	  stw       r0, 0x14C(r1)
	  stw       r29, 0x150(r1)
	  stw       r29, 0x148(r1)
	  lfd       f1, 0x150(r1)
	  lfd       f0, 0x148(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x49F98
	  li        r0, 0

	.loc_0x2F4:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x30C
	  lha       r3, 0x2E0(r30)
	  addi      r0, r3, 0x1
	  sth       r0, 0x2E0(r30)
	  b         .loc_0x650

	.loc_0x30C:
	  li        r3, 0x112
	  bl        -0xEB8C0
	  b         .loc_0x650

	.loc_0x318:
	  rlwinm.   r0,r4,0,11,11
	  beq-      .loc_0x42C
	  lha       r3, 0x2E0(r30)
	  cmpwi     r3, 0x9
	  bge-      .loc_0x42C
	  addi      r0, r3, 0x1
	  sth       r0, 0x2E0(r30)
	  lha       r0, 0x2E2(r30)
	  lha       r4, 0x2E0(r30)
	  mulli     r3, r0, 0xA
	  lha       r0, 0x2E8(r30)
	  add       r3, r4, r3
	  extsh     r3, r3
	  cmpw      r3, r0
	  ble-      .loc_0x35C
	  li        r0, 0x1
	  b         .loc_0x408

	.loc_0x35C:
	  sth       r3, 0x2E4(r30)
	  lis       r29, 0x4330
	  addi      r3, r30, 0x8
	  lha       r0, 0x2E4(r30)
	  lfd       f2, -0x4ED0(r2)
	  rlwinm    r0,r0,2,0,29
	  lfs       f3, -0x4EA8(r2)
	  add       r4, r30, r0
	  lwz       r5, 0x68(r4)
	  lha       r4, 0x18(r5)
	  lha       r0, 0x1A(r5)
	  xoris     r4, r4, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x14C(r1)
	  stw       r0, 0x154(r1)
	  stw       r29, 0x148(r1)
	  stw       r29, 0x150(r1)
	  lfd       f1, 0x148(r1)
	  lfd       f0, 0x150(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x49ED4
	  lha       r0, 0x2E4(r30)
	  addi      r3, r30, 0x38
	  lfd       f2, -0x4ED0(r2)
	  rlwinm    r0,r0,2,0,29
	  lfs       f3, -0x4EA8(r2)
	  add       r4, r30, r0
	  lwz       r5, 0xE0(r4)
	  lha       r4, 0x18(r5)
	  lha       r0, 0x1A(r5)
	  xoris     r4, r4, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x15C(r1)
	  stw       r0, 0x164(r1)
	  stw       r29, 0x158(r1)
	  stw       r29, 0x160(r1)
	  lfd       f1, 0x158(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x49E84
	  li        r0, 0

	.loc_0x408:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x420
	  lha       r3, 0x2E0(r30)
	  subi      r0, r3, 0x1
	  sth       r0, 0x2E0(r30)
	  b         .loc_0x650

	.loc_0x420:
	  li        r3, 0x112
	  bl        -0xEB9D4
	  b         .loc_0x650

	.loc_0x42C:
	  rlwinm.   r0,r4,0,12,12
	  beq-      .loc_0x540
	  lha       r3, 0x2E2(r30)
	  cmpwi     r3, 0
	  ble-      .loc_0x540
	  subi      r0, r3, 0x1
	  sth       r0, 0x2E2(r30)
	  lha       r0, 0x2E2(r30)
	  lha       r4, 0x2E0(r30)
	  mulli     r3, r0, 0xA
	  lha       r0, 0x2E8(r30)
	  add       r3, r4, r3
	  extsh     r3, r3
	  cmpw      r3, r0
	  ble-      .loc_0x470
	  li        r0, 0x1
	  b         .loc_0x51C

	.loc_0x470:
	  sth       r3, 0x2E4(r30)
	  lis       r29, 0x4330
	  addi      r3, r30, 0x8
	  lha       r0, 0x2E4(r30)
	  lfd       f2, -0x4ED0(r2)
	  rlwinm    r0,r0,2,0,29
	  lfs       f3, -0x4EA8(r2)
	  add       r4, r30, r0
	  lwz       r5, 0x68(r4)
	  lha       r4, 0x18(r5)
	  lha       r0, 0x1A(r5)
	  xoris     r4, r4, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x14C(r1)
	  stw       r0, 0x154(r1)
	  stw       r29, 0x148(r1)
	  stw       r29, 0x150(r1)
	  lfd       f1, 0x148(r1)
	  lfd       f0, 0x150(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x49DC0
	  lha       r0, 0x2E4(r30)
	  addi      r3, r30, 0x38
	  lfd       f2, -0x4ED0(r2)
	  rlwinm    r0,r0,2,0,29
	  lfs       f3, -0x4EA8(r2)
	  add       r4, r30, r0
	  lwz       r5, 0xE0(r4)
	  lha       r4, 0x18(r5)
	  lha       r0, 0x1A(r5)
	  xoris     r4, r4, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x15C(r1)
	  stw       r0, 0x164(r1)
	  stw       r29, 0x158(r1)
	  stw       r29, 0x160(r1)
	  lfd       f1, 0x158(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x49D70
	  li        r0, 0

	.loc_0x51C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x534
	  lha       r3, 0x2E2(r30)
	  addi      r0, r3, 0x1
	  sth       r0, 0x2E2(r30)
	  b         .loc_0x650

	.loc_0x534:
	  li        r3, 0x112
	  bl        -0xEBAE8
	  b         .loc_0x650

	.loc_0x540:
	  rlwinm.   r0,r4,0,10,10
	  beq-      .loc_0x650
	  lha       r3, 0x2E2(r30)
	  cmpwi     r3, 0x2
	  bge-      .loc_0x650
	  addi      r0, r3, 0x1
	  sth       r0, 0x2E2(r30)
	  lha       r0, 0x2E2(r30)
	  lha       r4, 0x2E0(r30)
	  mulli     r3, r0, 0xA
	  lha       r0, 0x2E8(r30)
	  add       r3, r4, r3
	  extsh     r3, r3
	  cmpw      r3, r0
	  ble-      .loc_0x584
	  li        r0, 0x1
	  b         .loc_0x630

	.loc_0x584:
	  sth       r3, 0x2E4(r30)
	  lis       r29, 0x4330
	  addi      r3, r30, 0x8
	  lha       r0, 0x2E4(r30)
	  lfd       f2, -0x4ED0(r2)
	  rlwinm    r0,r0,2,0,29
	  lfs       f3, -0x4EA8(r2)
	  add       r4, r30, r0
	  lwz       r5, 0x68(r4)
	  lha       r4, 0x18(r5)
	  lha       r0, 0x1A(r5)
	  xoris     r4, r4, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x14C(r1)
	  stw       r0, 0x154(r1)
	  stw       r29, 0x148(r1)
	  stw       r29, 0x150(r1)
	  lfd       f1, 0x148(r1)
	  lfd       f0, 0x150(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x49CAC
	  lha       r0, 0x2E4(r30)
	  addi      r3, r30, 0x38
	  lfd       f2, -0x4ED0(r2)
	  rlwinm    r0,r0,2,0,29
	  lfs       f3, -0x4EA8(r2)
	  add       r4, r30, r0
	  lwz       r5, 0xE0(r4)
	  lha       r4, 0x18(r5)
	  lha       r0, 0x1A(r5)
	  xoris     r4, r4, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x15C(r1)
	  stw       r0, 0x164(r1)
	  stw       r29, 0x158(r1)
	  stw       r29, 0x160(r1)
	  lfd       f1, 0x158(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x49C5C
	  li        r0, 0

	.loc_0x630:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x648
	  lha       r3, 0x2E2(r30)
	  subi      r0, r3, 0x1
	  sth       r0, 0x2E2(r30)
	  b         .loc_0x650

	.loc_0x648:
	  li        r3, 0x112
	  bl        -0xEBBFC

	.loc_0x650:
	  addi      r3, r30, 0x8
	  bl        0x4989C
	  addi      r3, r30, 0x38
	  bl        0x49894
	  lwz       r3, 0x2D0(r30)
	  bl        -0x11840

	.loc_0x668:
	  lwz       r3, 0x4(r30)
	  bl        0x21BC0
	  lwz       r3, 0x2D4(r30)
	  mr        r4, r31
	  bl        -0x1138
	  stw       r3, 0x2D8(r30)
	  lwz       r3, 0x2C4(r30)
	  bl        0x21BA8
	  lha       r3, 0x2E8(r30)
	  li        r5, 0
	  addi      r3, r3, 0x1
	  cmpwi     r3, 0x1E
	  rlwinm    r0,r3,2,0,29
	  add       r6, r30, r0
	  subfic    r3, r3, 0x1E
	  bge-      .loc_0x760
	  rlwinm.   r0,r3,29,3,31
	  mtctr     r0
	  beq-      .loc_0x744

	.loc_0x6B4:
	  lwz       r4, 0x248(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x24C(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x250(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x254(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x258(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x25C(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x260(r6)
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  lwz       r4, 0x264(r6)
	  addi      r6, r6, 0x20
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  bdnz+     .loc_0x6B4
	  andi.     r3, r3, 0x7
	  beq-      .loc_0x760

	.loc_0x744:
	  mtctr     r3

	.loc_0x748:
	  lwz       r4, 0x248(r6)
	  addi      r6, r6, 0x4
	  lwz       r4, 0xE0(r4)
	  lwz       r4, 0xC(r4)
	  stb       r5, 0xF0(r4)
	  bdnz+     .loc_0x748

	.loc_0x760:
	  lfs       f27, -0x4EB4(r2)
	  mr        r28, r30
	  lfs       f28, -0x4EA0(r2)
	  li        r31, 0
	  lfd       f29, -0x4ED0(r2)
	  lfs       f30, -0x4E98(r2)
	  lis       r29, 0x4330
	  lfs       f31, -0x4E9C(r2)
	  b         .loc_0x81C

	.loc_0x784:
	  lfs       f0, 0x2EC(r30)
	  fcmpo     cr0, f0, f27
	  fmr       f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x79C
	  fsubs     f1, f1, f27

	.loc_0x79C:
	  xoris     r0, r31, 0x8000
	  stw       r0, 0x14C(r1)
	  stw       r29, 0x148(r1)
	  lfd       f0, 0x148(r1)
	  fsubs     f0, f0, f29
	  fmuls     f0, f28, f0
	  fsubs     f1, f1, f0
	  fmuls     f1, f30, f1
	  bl        0x8AC08
	  lwz       r5, 0x1D0(r28)
	  fmuls     f0, f31, f1
	  addi      r31, r31, 0x1
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  fadds     f0, f27, f0
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x1
	  sth       r3, 0xB8(r5)
	  addze     r0, r0
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)
	  lwz       r3, 0x1D0(r28)
	  addi      r28, r28, 0x4
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)

	.loc_0x81C:
	  lha       r0, 0x2E8(r30)
	  cmpw      r31, r0
	  ble+      .loc_0x784
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x848
	  lwz       r0, 0x2D8(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x848
	  li        r0, 0
	  stw       r0, 0x0(r30)

	.loc_0x848:
	  lwz       r3, 0x0(r30)

	.loc_0x84C:
	  lwz       r0, 0x1A4(r1)
	  lfd       f31, 0x198(r1)
	  lfd       f30, 0x190(r1)
	  lfd       f29, 0x188(r1)
	  lfd       f28, 0x180(r1)
	  lfd       f27, 0x178(r1)
	  lwz       r31, 0x174(r1)
	  lwz       r30, 0x170(r1)
	  lwz       r29, 0x16C(r1)
	  lwz       r28, 0x168(r1)
	  addi      r1, r1, 0x1A0
	  mtlr      r0
	  blr
	*/
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
