#include "zen/DrawMenu.h"
#include "DebugLog.h"
#include "P2D/TextBox.h"
#include "SoundMgr.h"
#include "nlib/Math.h"
#include "sysNew.h"
#include "zen/Math.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(17)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("drawMenu")

/*
 * --INFO--
 * Address:	801C277C
 * Size:	0000AC
 */
void zen::DrawMenuText::init(bool useNewColors, Colour& charColor, Colour& gradColor)
{
	if (useNewColors) {
		mBlendTimer = 0.5f;
		mTextPane->setCharColor(charColor);
		mTextPane->setGradColor(gradColor);
		if (mParentPane) {
			mParentPane->setCharColor(charColor);
			mParentPane->setGradColor(gradColor);
		}
	} else {
		mBlendTimer = 0.0f;
		mTextPane->setCharColor(mCharColor);
		mTextPane->setGradColor(mGradColor);
		if (mParentPane) {
			mParentPane->setCharColor(mCharColor);
			mParentPane->setGradColor(mGradColor);
		}
	}

	if (mParentPane) {
		mParentPane->setAlpha(80, 64);
	}
}

/*
 * --INFO--
 * Address:	801C2828
 * Size:	0000F4
 */
void zen::DrawMenuText::setPane(P2DPane* textPane, P2DPane* parentPane)
{
	if (textPane->getTypeID() == PANETYPE_TextBox) {
		mTextPane  = (P2DTextBox*)textPane;
		mCharColor = mTextPane->getCharColor();
		mGradColor = mTextPane->getGradColor();
		mTextPane->setOffset(mTextPane->getWidth() >> 1, mTextPane->getHeight() >> 1);
	} else {
		ERROR("This pane is not Text Box.\n");
	}

	if (parentPane) {
		if (parentPane->getTypeID() == PANETYPE_TextBox) {
			mParentPane = (P2DTextBox*)parentPane;
			mParentPane->setOffset(mParentPane->getWidth() >> 1, mParentPane->getHeight() >> 1);
		} else {
			ERROR("This pane is not Text Box.\n");
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void zen::DrawMenuText::setScale(f32 xScale, f32 yScale)
{
	mTextPane->setScale(Vector3f(xScale, yScale, 1.0f));
	if (mParentPane) {
		mParentPane->setScale(Vector3f(xScale, yScale, 1.0f));
	}
}

/*
 * --INFO--
 * Address:	801C291C
 * Size:	0005C4
 */
void zen::DrawMenuText::update(bool isIncreasing, Colour& charBlend, Colour& gradBlend)
{
	Colour newCharColor;
	Colour newGradColor;

	if (getActiveSw()) {
		if (isIncreasing) {
			mBlendTimer += gsys->getFrameTime();
		} else {
			mBlendTimer -= gsys->getFrameTime();
		}

		if (mBlendTimer < 0.0f) {
			mBlendTimer = 0.0f;
		}
		if (mBlendTimer > 0.5f) {
			mBlendTimer = 0.5f;
		}

		f32 t1         = mBlendTimer / 0.5f;
		newCharColor.r = colorBlend(charBlend.r, t1, mCharColor.r, 1.0f - t1);
		newCharColor.g = colorBlend(charBlend.g, t1, mCharColor.g, 1.0f - t1);
		newCharColor.b = colorBlend(charBlend.b, t1, mCharColor.b, 1.0f - t1);
		newCharColor.a = mTextPane->getAlpha();

		newGradColor.r = colorBlend(gradBlend.r, t1, mGradColor.r, 1.0f - t1);
		newGradColor.g = colorBlend(gradBlend.g, t1, mGradColor.g, 1.0f - t1);
		newGradColor.b = colorBlend(gradBlend.b, t1, mGradColor.b, 1.0f - t1);
		newGradColor.a = mTextPane->getAlpha();

	} else {
		mBlendTimer = 0.0f;
		newCharColor.set(100, 100, 100, mTextPane->getAlpha());
		newGradColor.set(50, 50, 50, mTextPane->getAlpha());
	}

	mTextPane->setCharColor(newCharColor);
	mTextPane->setGradColor(newGradColor);

	if (mParentPane) {
		newCharColor.a = mParentPane->getAlphaChar();
		newGradColor.a = mParentPane->getAlphaGrad();
		mParentPane->setCharColor(newCharColor);
		mParentPane->setGradColor(newGradColor);
	}
}

/*
 * --INFO--
 * Address:	801C2EE0
 * Size:	000088
 */
void zen::DrawMenuTitle::setPane(P2DScreen* screen, P2DPane* parent, u32 tag)
{
	mTitlePane = screen->search(tag, false);
	if (mTitlePane) {
		mMode = 0;
		mTitlePane->setScale(0.0f);
		P2DPaneLibrary::changeParent(mTitlePane, parent);
	}
}

/*
 * --INFO--
 * Address:	801C2F68
 * Size:	00000C
 */
void zen::DrawMenuTitle::start()
{
	mMode = MODE_Start;
}

/*
 * --INFO--
 * Address:	801C2F74
 * Size:	00000C
 */
void zen::DrawMenuTitle::wait()
{
	mMode = MODE_Wait;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void zen::DrawMenuTitle::operation()
{
	mMode = MODE_Operation;
}

/*
 * --INFO--
 * Address:	801C2F80
 * Size:	00000C
 */
void zen::DrawMenuTitle::end()
{
	mMode = MODE_End;
}

/*
 * --INFO--
 * Address:	801C2F8C
 * Size:	000170
 */
bool zen::DrawMenuTitle::update(f32 p1)
{
	f32 xScale, tmp;
	if (mTitlePane) {
		switch (mMode) {
		case MODE_Wait: {
			mTitlePane->setScale(0.0f);
		} break;
		case MODE_Start: {
			xScale = (1.0f - NMathF::sin(HALF_PI * p1)) * 3.0f + 1.0f;
			tmp    = (p1 - 0.65f) / 0.35f;
			if (tmp < 0.0f) {
				tmp = 0.0f;
			}
			mTitlePane->setScale(xScale, NMathF::sin(HALF_PI * tmp), 1.0f);
		} break;
		case MODE_Operation: {
			mTitlePane->setScale(1.0f);
		} break;
		case MODE_End: {
			p1     = 1.0f - p1;
			xScale = (1.0f - NMathF::sin(HALF_PI * p1)) * 3.0f + 1.0f;
			tmp    = (p1 - 0.65f) / 0.35f;
			if (tmp < 0.0f) {
				tmp = 0.0f;
			}
			mTitlePane->setScale(xScale, NMathF::sin(HALF_PI * tmp), 1.0f);
		} break;
		default: {
			ERROR("Unknown Status %d \n", mMode);
		} break;
		}
	}

	return mMode != MODE_Wait;
}

/*
 * --INFO--
 * Address:	801C30FC
 * Size:	000AFC
 */
zen::DrawMenu::DrawMenu(char* bloFileName, bool useAlphaMgr, bool useTexAnimMgr)
    : DrawScreen(bloFileName, nullptr, useAlphaMgr, useTexAnimMgr)
{
	mState         = STATUS_Unk0;
	_104           = 0.0f;
	_108           = 0.5f;
	mRatio         = 0.0f;
	mCurrentSelect = 0;
	mSelectCount   = 1;
	mKeyDecide     = KBBTN_START | KBBTN_A;
	mKeyCancel     = KBBTN_B;
	setCancelSE(SYSSE_CANCEL);
	mIsSelectMenuCancel = false;
	setCancelSelectMenuNo(-1);
	mParentPane = mScreen.search('pall', true);
	mParentPane->setOffset(mParentPane->getWidth() >> 1, mParentPane->getHeight() >> 1);

	// Why question why having two panes specifically works when you
	// Can just enjoy having the linked file?
	P2DPane* pane;
	P2DPane* paneAlso = mScreen.search('se_c', true);
	if (paneAlso->getTypeID() == PANETYPE_TextBox) {
		P2DTextBox* tBox = (P2DTextBox*)paneAlso;
		tBox->getFontColor(mCharColor, mGradColor);
	} else {
		ERROR("tag<se_c> pane is not text box.\n");
	}

	mMenuPanelMgr.setCallBack(&mScreen, mParentPane);
	mTitle.setPane(&mScreen, mParentPane, 'yoko');
	int i = 0;
	char buf[8];
	sprintf(buf, "he%02d", 0);
	while (mScreen.search(P2DPaneLibrary::makeTag(buf), false)) {
		sprintf(buf, "he%02d", ++i);
	}

	mSelectCount = i;

	if (i == 0) {
		PRINT("WARNING! no select icons. \n");
	}

	mMenuItems = new DrawMenuItem[mSelectCount];
	for (i = 0; i < mSelectCount; i++) {
		sprintf(buf, "hm%02d", i);
		pane = mScreen.search(P2DPaneLibrary::makeTag(buf), false);
		if (pane) {
			P2DPaneLibrary::changeParent(pane, mParentPane);
		}
		sprintf(buf, "he%02d", i);
		P2DPane* paneE = mScreen.search(P2DPaneLibrary::makeTag(buf), true);
		P2DPaneLibrary::changeParent(paneE, mParentPane);
		mMenuItems[i].setTextPane(paneE, pane);

		sprintf(buf, "i%02dl", i);
		pane = mScreen.search(P2DPaneLibrary::makeTag(buf), true);
		if (mMenuItems[i].setIconLPane(pane, mParentPane)) {
			ERROR("pane [%s] is not picture.\n", buf);
		}

		sprintf(buf, "i%02dr", i);
		pane = mScreen.search(P2DPaneLibrary::makeTag(buf), true);
		mMenuItems[i].setIconRPane(pane, mParentPane);
		if (mMenuItems[i].setIconRPane(pane, mParentPane)) {
			ERROR("pane [%s] is not picture.\n", buf);
		}
	}

	i = 0;
	sprintf(buf, "z%02dl", 0);
	while (mScreen.search(P2DPaneLibrary::makeTag(buf), false)) {
		sprintf(buf, "z%02dl", ++i);
	}

	mSpecCount = i;

	if (i == 0) {
		PRINT("No Spectrum Icons \n");
	}

	mLeftCursorIcons  = new P2DPicture*[mSpecCount];
	mRightCursorIcons = new P2DPicture*[mSpecCount];

	for (i = mSpecCount - 1; i >= 0; i--) {
		sprintf(buf, "z%02dl", i);
		pane = mScreen.search(P2DPaneLibrary::makeTag(buf), true);
		if (pane->getTypeID() == PANETYPE_Picture) {
			mLeftCursorIcons[i] = (P2DPicture*)pane;
			P2DPaneLibrary::changeParent(mLeftCursorIcons[i], mParentPane);
			mLeftCursorIcons[i]->move(mMenuItems[mCurrentSelect].getIconLPosH() - 640, mMenuItems[mCurrentSelect].getIconLPosV());
			mLeftCursorIcons[i]->show();
			mLeftCursorIcons[i]->setOffset(mLeftCursorIcons[i]->getWidth() >> 1, mLeftCursorIcons[i]->getHeight() >> 1);
			mLeftCursorIcons[i]->setScale(0.0f);
			if (i == 0) {
				P2DPaneLibrary::setFamilyAlpha(mLeftCursorIcons[i], 255);
			} else {
				P2DPaneLibrary::setFamilyAlpha(mLeftCursorIcons[i], RoundOff(100.0f * (1.0f - f32(i) / mSpecCount)));
			}
		}

		sprintf(buf, "z%02dr", i);
		pane = mScreen.search(P2DPaneLibrary::makeTag(buf), true);
		if (pane->getTypeID() == PANETYPE_Picture) {
			mRightCursorIcons[i] = (P2DPicture*)pane;
			P2DPaneLibrary::changeParent(mRightCursorIcons[i], mParentPane);
			mRightCursorIcons[i]->move(mMenuItems[mCurrentSelect].getIconRPosH() + 640, mMenuItems[mCurrentSelect].getIconRPosV());
			mRightCursorIcons[i]->show();
			mRightCursorIcons[i]->setOffset(mRightCursorIcons[i]->getWidth() >> 1, mRightCursorIcons[i]->getHeight() >> 1);
			mRightCursorIcons[i]->setScale(0.0f);
			if (i == 0) {
				P2DPaneLibrary::setFamilyAlpha(mRightCursorIcons[i], 255);
			} else {
				P2DPaneLibrary::setFamilyAlpha(mRightCursorIcons[i], RoundOff(100.0f * (1.0f - f32(i) / mSpecCount)));
			}
		}
	}

	_11C              = 0.0f;
	_120              = 0.5f;
	mLeftCursorPos.x  = mMenuItems[mCurrentSelect].getIconLPosH() - 640;
	mLeftCursorPos.y  = mMenuItems[mCurrentSelect].getIconLPosV();
	mRightCursorPos.x = mMenuItems[mCurrentSelect].getIconRPosH() + 640;
	mRightCursorPos.y = mMenuItems[mCurrentSelect].getIconRPosV();

	mLeftCursorMgr.init(&mScreen, mParentPane, 'z**l', mMenuItems[mCurrentSelect].getIconLPosH() - 640,
	                    mMenuItems[mCurrentSelect].getIconLPosV());
	mRightCursorMgr.init(&mScreen, mParentPane, 'z**r', mMenuItems[mCurrentSelect].getIconRPosH() + 640,
	                     mMenuItems[mCurrentSelect].getIconRPosV());

	updateMenuPanes();
}

/*
 * --INFO--
 * Address:	801C3CB8
 * Size:	00039C
 */
void zen::DrawMenu::start(int p1)
{
	mState = STATUS_Unk1;
	_104   = 0.0f;
	_108   = 0.5f;
	mRatio = 0.0f;
	if (p1 >= 0) {
		mCurrentSelect = p1;
	}

	mIsSelectMenuCancel = false;

	for (int i = 0; i < mSpecCount; i++) {
		mLeftCursorIcons[i]->move(mMenuItems[mCurrentSelect].getIconLPosH() - 640, mMenuItems[mCurrentSelect].getIconLPosV());
		mLeftCursorIcons[i]->setScale(0.0f);
		mRightCursorIcons[i]->move(mMenuItems[mCurrentSelect].getIconRPosH() + 640, mMenuItems[mCurrentSelect].getIconRPosV());
		mRightCursorIcons[i]->setScale(0.0f);
	}

	_11C = 0.0f;
	_120 = 0.5f;

	mLeftCursorPos.x  = mMenuItems[mCurrentSelect].getIconLPosH() - 640;
	mLeftCursorPos.y  = mMenuItems[mCurrentSelect].getIconLPosV();
	mRightCursorPos.x = mMenuItems[mCurrentSelect].getIconRPosH() + 640;
	mRightCursorPos.y = mMenuItems[mCurrentSelect].getIconRPosV();

	updateMenuPanes();
	mMenuPanelMgr.start(_120);
	mTitle.start();

	mLeftCursorMgr.init(&mScreen, mParentPane, 'z**l', mMenuItems[mCurrentSelect].getIconLPosH() - 640,
	                    mMenuItems[mCurrentSelect].getIconLPosV());
	mRightCursorMgr.init(&mScreen, mParentPane, 'z**r', mMenuItems[mCurrentSelect].getIconRPosH() + 640,
	                     mMenuItems[mCurrentSelect].getIconRPosV());

	mLeftCursorMgr.move(mMenuItems[mCurrentSelect].getIconLPosH(), mMenuItems[mCurrentSelect].getIconLPosV(), 0.5f);
	mRightCursorMgr.move(mMenuItems[mCurrentSelect].getIconRPosH(), mMenuItems[mCurrentSelect].getIconRPosV(), 0.5f);
}

/*
 * --INFO--
 * Address:	801C4054
 * Size:	00038C
 */
void zen::DrawMenu::updateMenuPanes()
{
	for (int i = 0; i < mSelectCount; i++) {
		if (i == mCurrentSelect) {
			mMenuItems[i].update(true, mCharColor, mGradColor);
		} else {
			mMenuItems[i].update(false, mCharColor, mGradColor);
		}

		switch (mState) {
		case STATUS_Unk1:
			f32 yScale = 2.0f * (mRatio - 0.5f);
			if (yScale < 0.0f) {
				yScale = 0.0f;
			}
			mMenuItems[i].setScale(2.0f - yScale, yScale);
			break;

		case STATUS_Unk2:
			mMenuItems[i].setScale(1.0f, 1.0f);
			break;

		case STATUS_Unk3:
			if (mCancelSelectMenuNo < 0 || i != mCurrentSelect) {
				yScale = 1.0f - (2.0f * mRatio);
				if (yScale < 0.0f) {
					yScale = 0.0f;
				}
				mMenuItems[i].setScale(mRatio + 1.0f, yScale);
			} else {
				mMenuItems[i].setScale(1.0f, NMathF::sin((3.0f * PI / 2.0f) * mRatio) + 1.0f);
			}
			break;
		}
	}

	mLeftCursorMgr.update();
	mRightCursorMgr.update();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void zen::DrawMenu::setMirror(P2DPane*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003E4
 */
void zen::DrawMenu::updateSpectPanes(P2DPane*, P2DPicture**, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801C43E0
 * Size:	0000F4
 */
void zen::DrawMenu::updateSelectMenuNo(Controller* controller)
{
	int selAdjust = controller->keyClick(KBBTN_MSTICK_DOWN) - controller->keyClick(KBBTN_MSTICK_UP);
	mCurrentSelect += selAdjust;
	if (mCurrentSelect < 0) {
		mCurrentSelect = mSelectCount - 1;
	}
	if (mCurrentSelect >= mSelectCount) {
		mCurrentSelect = 0;
	}
	do {
		if (!mMenuItems[mCurrentSelect].getActiveSw()) {
			if (selAdjust == 0) {
				selAdjust = 1;
			}
			mCurrentSelect += selAdjust;
		}
		if (mCurrentSelect < 0) {
			mCurrentSelect = mSelectCount - 1;
		}
		if (mCurrentSelect >= mSelectCount) {
			mCurrentSelect = 0;
		}
	} while (!mMenuItems[mCurrentSelect].getActiveSw());
}

/*
 * --INFO--
 * Address:	801C44D4
 * Size:	00040C
 */
bool zen::DrawMenu::update(Controller* controller)
{
	bool res      = false;
	int oldSelect = mCurrentSelect;
	if (mState != STATUS_Unk0) {
		_104 += gsys->getFrameTime();
		if (_104 > _108) {
			_104 = _108;
		}

		mRatio = _104 / _108;

		switch (mState) {
		case STATUS_Unk1:
			if (mRatio == 1.0f && mMenuPanelMgr.checkFinish()) {
				_104   = 0.0f;
				_108   = 0.1f;
				mRatio = 0.0f;
				mState = STATUS_Unk2;
				mMenuPanelMgr.operation();
				mTitle.operation();
			}
			break;
		case STATUS_Unk2:
			if (mRatio == 1.0f) {
				updateSelectMenuNo(controller);
				if (controller->keyClick(KBBTN_MSTICK_UP | KBBTN_MSTICK_DOWN)) {
					if (mCurrentSelect != oldSelect) {
						SeSystem::playSysSe(SYSSE_MOVE1);
						_11C              = 0.0f;
						mLeftCursorPos.x  = mLeftCursorIcons[0]->getPosH();
						mLeftCursorPos.y  = mLeftCursorIcons[0]->getPosV();
						mRightCursorPos.x = mRightCursorIcons[0]->getPosH();
						mRightCursorPos.y = mRightCursorIcons[0]->getPosV();
						mLeftCursorMgr.move(mMenuItems[mCurrentSelect].getIconLPosH(), mMenuItems[mCurrentSelect].getIconLPosV(), 0.5f);
						mRightCursorMgr.move(mMenuItems[mCurrentSelect].getIconRPosH(), mMenuItems[mCurrentSelect].getIconRPosV(), 0.5f);

					} else {
						SeSystem::playSysSe(SYSSE_CMENU_ERROR);
					}
				}

				if (controller->keyClick(mKeyDecide)) {
					SeSystem::playSysSe(SYSSE_DECIDE1);
					mState = STATUS_Unk3;
				}
				if (controller->keyClick(mKeyCancel)) {
					SeSystem::playSysSe(mCancelSoundID);
					mState              = STATUS_Unk3;
					mIsSelectMenuCancel = true;
					if (mCancelSelectMenuNo >= 0) {
						mCurrentSelect = mCancelSelectMenuNo;
					}
				}

				if (mState == STATUS_Unk3) {
					_104   = 0.0f;
					_108   = 0.5f;
					mRatio = 0.0f;
					mMenuPanelMgr.end(_108);
					mLeftCursorMgr.scale(0.0f, _108);
					mRightCursorMgr.scale(0.0f, _108);
					mTitle.end();
				}
			}
			break;
		case STATUS_Unk3:
			if (mRatio == 1.0f && mMenuPanelMgr.checkFinish() && mLeftCursorMgr.checkFinish() && mRightCursorMgr.checkFinish()) {
				mState = STATUS_Unk0;
				res    = true;
			}
			break;
		}

		updateMenuPanes();
		mMenuPanelMgr.update();
		DrawScreen::update();
		mTitle.update(mRatio);
	}

	return res;
}

/*
 * --INFO--
 * Address:	801C48E0
 * Size:	00002C
 */
void zen::DrawMenu::draw(Graphics&)
{
	if (mState) {
		DrawScreen::draw();
	}
}

/*
 * --INFO--
 * Address:	801C490C
 * Size:	00002C
 */
void zen::DrawMenu::setMenuItemActiveSw(int idx, bool set)
{
	if (idx < 0 || idx >= mSelectCount) {
		ERROR("illeagal menu item no %d [0,%d]\n", idx, mSelectCount - 1);
		return;
	}

	mMenuItems[idx].setActiveSw(set);
}

/*
 * --INFO--
 * Address:	801C4938
 * Size:	000028
 */
void zen::DrawMenu::setCancelSelectMenuNo(int menuNo)
{
	if (menuNo < 0) {
		mCancelSelectMenuNo = -1;
	} else if (menuNo < mSelectCount) {
		mCancelSelectMenuNo = menuNo;
	} else {
		ERROR("Illegal cancelSelectMenuNo %d / %d\n", menuNo, mSelectCount);
	}
}
