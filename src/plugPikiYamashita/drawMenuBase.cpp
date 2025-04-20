#include "zen/DrawMenu.h"
#include "P2D/TextBox.h"
#include "DebugLog.h"
#include "SoundMgr.h"
#include "sysNew.h"

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
DEFINE_PRINT("drawMenuBase")

/*
 * --INFO--
 * Address:	801F014C
 * Size:	000438
 */
zen::DrawMenuBase::DrawMenuBase(char* bloFileName, bool useAlphaMgr, bool useTexAnimMgr)
    : DrawScreen(bloFileName, nullptr, useAlphaMgr, useTexAnimMgr)
{
	P2DPane* rootPane = mScreen.search('root', true);
	rootPane->setOffset(rootPane->getWidth() >> 1, rootPane->getHeight() >> 1);

	P2DPane* pane = mScreen.search('se_c', true);
	if (pane->getTypeID() == PANETYPE_TextBox) {
		P2DTextBox* tBox = (P2DTextBox*)pane;
		tBox->getFontColor(_178, _17C);
	} else {
		ERROR("tag<se_c> pane is not text box.\n");
	}

	int i = 0;
	char buf[8];
	sprintf(buf, "he%02d", 0);
	while (mScreen.search(P2DPaneLibrary::makeTag(buf), false)) {
		sprintf(buf, "he%02d", ++i);
	}

	mSelectCount = i;
	if (i == 0) {
		ERROR("セレクトアイコンペインがありませんなァ。逝ってよし"); // 'there is no select icon pane. good riddance' lol
	}

	mMenuItems = new DrawMenuItem[mSelectCount];

	for (i = 0; i < mSelectCount; i++) {
		sprintf(buf, "he%02d", i);
		P2DPane* ePane = mScreen.search(P2DPaneLibrary::makeTag(buf), true);
		sprintf(buf, "hm%02d", i);
		P2DPane* mPane = mScreen.search(P2DPaneLibrary::makeTag(buf), false);
		mMenuItems[i].setTextPane(ePane, mPane);

		sprintf(buf, "i%02dl", i);
		ePane = mScreen.search(P2DPaneLibrary::makeTag(buf), true);
		if (mMenuItems[i].setIconLPane(ePane, rootPane)) {
			ERROR("pane [%s] is not picture.\n", buf);
		}

		sprintf(buf, "i%02dr", i);
		ePane = mScreen.search(P2DPaneLibrary::makeTag(buf), true);
		if (mMenuItems[i].setIconRPane(ePane, rootPane)) {
			ERROR("pane [%s] is not picture.\n", buf);
		}
	}

	mLeftCursorMgr.init(&mScreen, rootPane, 'z**l', 10.0f, 100.0f);
	mRightCursorMgr.init(&mScreen, rootPane, 'z**r', 50.0f, 100.0f);

	setKeyAssignDecide(KBBTN_A);
	setKeyAssignCancel(KBBTN_B);
	init(MODE_Sleep);
}

/*
 * --INFO--
 * Address:	801F0584
 * Size:	000070
 */
bool zen::DrawMenuBase::update(Controller* controller)
{
	bool res = false;
	_18C     = 0;
	if ((this->*mModeFunction)(controller)) {
		res = true;
	}

	mScreen.update();
	mLeftCursorMgr.update();
	mRightCursorMgr.update();
	return res;
}

/*
 * --INFO--
 * Address:	801F05F4
 * Size:	000020
 */
void zen::DrawMenuBase::draw(Graphics&)
{
	DrawScreen::draw();
}

/*
 * --INFO--
 * Address:	801F0614
 * Size:	0001A0
 */
void zen::DrawMenuBase::init(int mode)
{
	setModeFunc(mode);
	_18C           = 0;
	mCurrentSelect = 0;
	_108           = 0;
	mScreen.move(0, 0);
	mScreen.setScale(1.0f);
	mScreen.show();
	mLeftCursorMgr.initPos(mMenuItems[mCurrentSelect].getIconLPosH(), mMenuItems[mCurrentSelect].getIconLPosV());
	mRightCursorMgr.initPos(mMenuItems[mCurrentSelect].getIconRPosH(), mMenuItems[mCurrentSelect].getIconRPosV());

	for (int i = 0; i < mSelectCount; i++) {
		mMenuItems[i].init(i == mCurrentSelect, _178, _17C);
	}

	setModeFunc(mode); // why are we doing this twice
}

/*
 * --INFO--
 * Address:	801F07B4
 * Size:	000034
 */
void zen::DrawMenuBase::start()
{
	mCurrentSelect = 0;
	_108           = mCurrentSelect;
	init(MODE_Operation);
}

/*
 * --INFO--
 * Address:	801F07E8
 * Size:	000008
 */
bool zen::DrawMenuBase::modeSleep(Controller*)
{
	return false;
}

/*
 * --INFO--
 * Address:	801F07F0
 * Size:	000214
 */
bool zen::DrawMenuBase::modeOperation(Controller* controller)
{
	bool res = false;
	DrawMenuItem* newItem;
	int startSel  = mCurrentSelect;
	int selAdjust = controller->keyClick(KBBTN_MSTICK_DOWN) - controller->keyClick(KBBTN_MSTICK_UP);
	if (selAdjust) {
		do {
			mCurrentSelect += selAdjust;
			if (mCurrentSelect < 0) {
				mCurrentSelect = mSelectCount - 1;
			}
			if (mCurrentSelect >= mSelectCount) {
				mCurrentSelect = 0;
			}
			newItem = &mMenuItems[mCurrentSelect];
		} while (!newItem->getActiveSw());
	}

	for (int i = 0; i < mSelectCount; i++) {
		mMenuItems[i].update(i == mCurrentSelect, _178, _17C);
	}

	if (startSel != mCurrentSelect) {
		SeSystem::playSysSe(SYSSE_MOVE1);
		mLeftCursorMgr.move(newItem->getIconLPosH(), newItem->getIconLPosV(), 0.5f);
		mRightCursorMgr.move(newItem->getIconRPosH(), newItem->getIconRPosV(), 0.5f);
		_18C |= 0x1;
	}
	if (controller->keyClick(mKeyCancel)) {
		SeSystem::playSysSe(SYSSE_CANCEL);
		_108 = SELECT_CANCEL;
		res  = true;
	} else if (controller->keyClick(mKeyDecide)) {
		SeSystem::playSysSe(SYSSE_DECIDE1);
		_108 = mCurrentSelect;
		res  = true;
	} else {
		_108 = mCurrentSelect;
	}

	return res;
}

const int zen::DrawMenuBase::SELECT_CANCEL = -1;

/*
 * --INFO--
 * Address:	801F0A04
 * Size:	00007C
 */
void zen::DrawMenuBase::setModeFunc(int mode)
{
	mMode = mode;
	switch (mMode) {
	case MODE_Sleep:
		mModeFunction = &modeSleep;
		break;
	case MODE_Operation:
		mModeFunction = &modeOperation;
		break;
	default:
		mModeFunction = &modeDefault;
		break;
	}
}
