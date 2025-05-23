#include "zen/ZenController.h"
#include "zen/EffectMgr2D.h"
#include "zen/DrawCommon.h"
#include "zen/ogResult.h"
#include "zen/ogDiary.h"
#include "PlayerState.h"
#include "zen/ogSub.h"
#include "P2D/Graph.h"
#include "SoundMgr.h"
#include "DebugLog.h"
#include "Font.h"

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

// Table of blo files used for diary entries
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

	mMessageMgrPosX = 0;
	mMessageMgrPosY = 0;
	mStatus         = Inactive;
}

/*
 * --INFO--
 * Address:	8018F344
 * Size:	0000FC
 */
zen::ogScrDiaryMgr::DiaryMgrStatus zen::ogScrDiaryMgr::update(Controller* input)
{
	if (mStatus == Inactive) {
		return mStatus;
	}

	ogScrMessageMgr::MessageStatus msgState = mMesgMgr->update(input);
	mController->setContPtr(input);
	mController->update();

	// Controls for debug menu
	if (playerState == nullptr && mMesgMgr->checkDisp() && msgState == ogScrMessageMgr::STATE_ActiveDisplay) {
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

	return (DiaryMgrStatus)msgState;
}

/*
 * --INFO--
 * Address:	8018F440
 * Size:	000178
 */
void zen::ogScrDiaryMgr::draw(Graphics& gfx)
{
	if (mStatus == Inactive) {
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
		int length;
		int screenId = playerState->mResultFlags.getDayDocument(day, length);
		if (length == 0) {
			return;
		}

		if (length == 1) {
			mPaneCapu->hide();
		} else {
			mPaneCapu->show();
		}

		if (length >= 10) {
			length = 9;
		}

		for (int i = 0; i < length; i++) {
			bloFile_Diary_Table[i] = bloFile_Res_Table[screenId + i];
			PRINT("Diary blo[%d] = \'%s\' (%d)\n", i, bloFile_Diary_Table[i], screenId + i);
		}

		bloFile_Diary_Table[length] = "END";
		mMesgMgr->MakeAndSetPageInfo(bloFiles_Diary);
	}

	mStatus = Active;
	mMesgMgr->setLastPageAbutton(true);
	setSpecialNumber(1, day);
	mMesgMgr->start(-1);
	mMesgMgr->setPage(0);
	mMesgMgr->move(mMessageMgrPosX, mMessageMgrPosY);
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
	int daysleft = MAX_DAYS - day;
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
	mMesgMgr->move(mMessageMgrPosX, mMessageMgrPosY);
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
	mMesgMgr->move(mMessageMgrPosX, mMessageMgrPosY);
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
	mMesgMgr->move(mMessageMgrPosX, mMessageMgrPosY);
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
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void zen::ogScrDiaryMgr::updateDiary(Controller* input)
{
	_UNUSED24 = 0;

	ogDrawDiary::DiaryStatus status = mDiaryInstance->update(input);
	if (status != ogDrawDiary::Closed) {
		return;
	}

	ogDrawSelectDiary::SelectDiaryStatus selectStatus
	    = static_cast<ogDrawSelectDiary::SelectDiaryStatus>(mSelectDiaryInstance->update(input) + 1);
	if (selectStatus == ogDrawSelectDiary::Active) {
		return;
	}

	s16 day = playerState->getCurrDay();
	if (day > 0) {
		f32 x = mSelectDiaryInstance->getOpenX();
		f32 y = mSelectDiaryInstance->getOpenY();
		mDiaryInstance->open(x, y, day);
	}
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
	mStatus      = Closed;
	mScreen->setScale(mScreenScale);
	mEfxMgr        = new EffectMgr2D(16, 0x400, 0x400);
	mDiaryMgr      = new ogScrDiaryMgr;
	mScreenScale   = 0.0f;
	mStatus        = Closed;
	mScreenCenterX = 320.0f;
	mScreenCenterY = 240.0f;
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
	mStatus      = Closed;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
void zen::ogDrawDiary::setOffset()
{
	mScreen->setOffset(mScreenCenterX, mScreenCenterY);
	mDiaryMgr->getScrMsgMgr()->getScreenPtr()->setOffset(mScreenCenterX, mScreenCenterY);
	mDiaryMgr->getScrMsgMgr()->getBaseScreenPtr()->setOffset(mScreenCenterX, mScreenCenterY);
}

/*
 * --INFO--
 * Address:	8018FBCC
 * Size:	000298
 */
void zen::ogDrawDiary::open(f32 a1, f32 a2, s16 day)
{
	mDiaryMgr->setDiarySpecialNumber(day);
	if (mStatus != Closed) {
		return;
	}

	mScreenScale    = 0.01f;
	mStatus         = Opening;
	mScreenCenterX  = a1;
	mScreenCenterY  = a2;
	mOpeningOriginX = mScreenCenterX;
	mOpeningOriginY = mScreenCenterY;
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

/*
 * --INFO--
 * Address:	8018FE64
 * Size:	0002B8
 */
zen::ogDrawDiary::DiaryStatus zen::ogDrawDiary::update(Controller* input)
{
	if (mStatus == Closed) {
		return mStatus;
	}

	if (mStatus == ogDrawDiary::Opening) {
		mScreenScale *= 1.5f;
		if (mScreenScale >= 1.0f) {
			mScreenScale = 1.0f;
			mStatus      = Active;
		}
	}

	if (mStatus == ogDrawDiary::Active) {
		if (input->keyClick(KBBTN_B)) {
			mStatus = Closing;
			mEfxMgr->killAll(true);
			seSystem->playSysSe(SYSSE_CANCEL);
		} else if (input->keyClick(KBBTN_A)) {
			if (mDiaryMgr->nextPage()) {
				seSystem->playSysSe(YMENU_SELECT2);
			}
		}
	}

	if (mStatus == ogDrawDiary::Closing) {
		mScreenScale *= (2.0f / 3.0f);
		if (mScreenScale <= 0.01f) {
			mScreenScale = 0.0f;
			mStatus      = Closed;
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
	if (mStatus != Closed) {
		mScreen->draw(0, 0, nullptr);
		mEfxMgr->draw(gfx);
		mDiaryMgr->draw(gfx);
	}
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
	mBlackFadeScreen = new P2DScreen;
	mBlackFadeScreen->set("screen/blo/black.blo", false, false, true);
	mBlackFadePicture = (P2DPicture*)mBlackFadeScreen->search('blck', true);
	mBlackFadePicture->setAlpha(255);
	mController = new ZenController(nullptr);
	mController->setRepeatTime(0.2f);
	mAButtonIcon          = (P2DPicture*)mScreen->search('abtn', true);
	mAButtonAlphaAnimator = new setTenmetuAlpha(mAButtonIcon, 1.0f);
	mDiaryInstance        = new ogDrawDiary;
	mCurrentDay           = 0;

	for (int i = 0; i < MAX_DAYS; i++) {
		char name[4];
		sprintf(name, "i%02du", i);
		mDayIconUpPanes[i] = mScreen->search(P2DPaneLibrary::makeTag(name), true);
		mDayIconUpPanes[i]->hide();

		sprintf(name, "i%02dd", i);
		mDayIconDownPanes[i] = mScreen->search(P2DPaneLibrary::makeTag(name), true);
		mDayIconDownPanes[i]->hide();

		sprintf(name, "pi%02d", i);
		mDayDisplayPanes[i] = mScreen->search(P2DPaneLibrary::makeTag(name), true);

		sprintf(name, "pk%02d", i + 14);
		_248[i] = (P2DPicture*)mScreen->search(P2DPaneLibrary::makeTag(name), true);
	}

	mSelectedColumnIndex = 0;
	mSelectedRowIndex    = 0;
	mSelectionIndex      = 0;
	_UNUSED2E6           = 0;
	mTransitionTimer     = 0.0f;
	mStatus              = Inactive;
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
		mCurrentDay = playerState->getCurrDay() - 1;
		PRINT("ogDrawSelectDiary  currDay = (%d)\n", mCurrentDay);
	} else {
		mCurrentDay = 15;
	}

	if (mCurrentDay < 0) {
		return;
	}

	mStatus              = FadingIn;
	mTransitionTimer     = 0.0f;
	mSelectedColumnIndex = 0;
	mSelectedRowIndex    = 0;
	mSelectionIndex      = 0;
	_UNUSED2E6           = 0;
	mBlackFadePicture->setAlpha(255);

	for (int i = 0; i < MAX_DAYS; i++) {
		if (i > mCurrentDay) {
			P2DPaneLibrary::setFamilyAlpha(mDayDisplayPanes[i], 80);
		} else {
			P2DPaneLibrary::setFamilyAlpha(mDayDisplayPanes[i], 255);
		}
	}

	for (int i = mCurrentDay + 1; i < MAX_DAYS; i++) {
		P2DPicture* obj = (P2DPicture*)_248[i]->getPaneTree()->getParent()->getObject();
		obj->setAlpha(0);
	}

	mAButtonAlphaAnimator->start();
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
	f32 x         = mDayIconUpPanes[0]->getPosH();
	f32 y         = mDayIconUpPanes[0]->getPosV();
	mLeftCursorMgr.init(mScreen, pane, 'z00l', x, y);
	x = mDayIconDownPanes[0]->getPosH();
	y = mDayIconDownPanes[0]->getPosV();
	mRightCursorMgr.init(mScreen, pane, 'z00r', x, y);
	MoveCursor();
}

/*
 * --INFO--
 * Address:	80190820
 * Size:	000104
 */
bool zen::ogDrawSelectDiary::MoveCursor()
{
	s16 idx = mSelectedColumnIndex + mSelectedRowIndex * 10;
	if (idx > mCurrentDay) {
		return true;
	}

	mSelectionIndex = idx;

	f32 x = mDayIconUpPanes[mSelectionIndex]->getPosH();
	f32 y = mDayIconUpPanes[mSelectionIndex]->getPosV();
	mLeftCursorMgr.move(x, y, 0.25f);

	x = mDayIconDownPanes[mSelectionIndex]->getPosH();
	y = mDayIconDownPanes[mSelectionIndex]->getPosV();
	mRightCursorMgr.move(x, y, 0.25f);
	return false;
}

/*
 * --INFO--
 * Address:	80190924
 * Size:	000880
 */
zen::ogDrawSelectDiary::SelectDiaryStatus zen::ogDrawSelectDiary::update(Controller* input)
{
	if (mStatus == Inactive) {
		return mStatus;
	}

	mTransitionTimer += gsys->getFrameTime();
	if (mStatus == Exited) {
		mStatus = Inactive;
		return mStatus;
	}

	mController->setContPtr(input);
	mController->update();
	if (mStatus == FadingIn) {
		if (mTransitionTimer > 0.5f) {
			mStatus = Active;
			return mStatus;
		}

		mBlackFadePicture->setAlpha((1.0f - mTransitionTimer / 0.5f) * 255.0f);
	}

	if (mStatus == FadingOut) {
		if (mTransitionTimer > 0.5f) {
			mStatus = Exited;
			return mStatus;
		}

		mBlackFadePicture->setAlpha((mTransitionTimer / 0.5f) * 255.0f);
	}

	if (mStatus == Active) {
		if (input->keyClick(KBBTN_A | KBBTN_START)) {
			P2DPane* pane = mDayDisplayPanes[mSelectionIndex];
			f32 x         = pane->getPosH() + pane->getWidth() / 2;
			f32 y         = pane->getPosV() + pane->getHeight() / 2;
			mDiaryInstance->open(x, y, mSelectionIndex + 1);
			seSystem->playSysSe(SYSSE_DECIDE1);
			mStatus = ViewingSingleDiary;
			return mStatus;
		}

		if (input->keyClick(KBBTN_B | KBBTN_Y)) {
			mStatus          = FadingOut;
			mTransitionTimer = 0.0f;
			return mStatus;
		}

		if (mController->keyRepeat(KBBTN_MSTICK_LEFT) && mSelectedColumnIndex > 0) {
			mSelectedColumnIndex--;
			if (MoveCursor()) {
				mSelectedColumnIndex++;
			} else {
				seSystem->playSysSe(SYSSE_MOVE1);
			}
		} else if (mController->keyRepeat(KBBTN_MSTICK_RIGHT) && mSelectedColumnIndex < 9) {
			mSelectedColumnIndex++;
			if (MoveCursor()) {
				mSelectedColumnIndex--;
			} else {
				seSystem->playSysSe(SYSSE_MOVE1);
			}
		} else if (mController->keyRepeat(KBBTN_MSTICK_UP) && mSelectedRowIndex > 0) {
			mSelectedRowIndex--;
			if (MoveCursor()) {
				mSelectedRowIndex++;
			} else {
				seSystem->playSysSe(SYSSE_MOVE1);
			}
		} else if (mController->keyRepeat(KBBTN_MSTICK_DOWN) && mSelectedRowIndex < 2) {
			mSelectedRowIndex++;
			if (MoveCursor()) {
				mSelectedRowIndex--;
			} else {
				seSystem->playSysSe(SYSSE_MOVE1);
			}
		}
		mLeftCursorMgr.update();
		mRightCursorMgr.update();
		mAButtonAlphaAnimator->update();
	}

	mScreen->update();
	mDiaryStatus = mDiaryInstance->update(input);
	mBlackFadeScreen->update();
	for (int i = mCurrentDay + 1; i < MAX_DAYS; i++) {
		P2DPicture* obj = (P2DPicture*)_248[i]->getPaneTree()->getParent()->getObject();
		obj->setAlpha(0);
	}

	for (int i = 0; i <= mCurrentDay; i++) {
		f32 phase = mTransitionTimer;
		if (phase >= 1.0f) {
			phase -= 1.0f;
		}

		phase -= f32(i) * 0.1f;
		f32 scale = 0.05f * sinf(TAU * phase) + 1.0f;
		mDayDisplayPanes[i]->setOffset(mDayDisplayPanes[i]->getWidth() / 2, mDayDisplayPanes[i]->getHeight() / 2);
		mDayDisplayPanes[i]->setScale(scale);
	}

	if (mStatus == ViewingSingleDiary && mDiaryStatus == ogDrawDiary::Closed) {
		mStatus = Active;
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
	if (mStatus == Inactive) {
		return;
	}

	P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	graf.setPort();
	mScreen->draw(0, 0, &graf);
	mDiaryInstance->draw(gfx);
	mBlackFadeScreen->draw(0, 0, &graf);
}
