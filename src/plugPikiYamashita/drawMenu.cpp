#include "zen/DrawMenu.h"
#include "zen/Math.h"
#include "P2D/TextBox.h"
#include "SoundMgr.h"
#include "nlib/Math.h"
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

	//Why question why having two panes specifically works when you
	//Can just enjoy having the linked file? 
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
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r7, r6
	  stw       r0, 0x4(r1)
	  addi      r6, r5, 0
	  li        r5, 0
	  stwu      r1, -0x238(r1)
	  stfd      f31, 0x230(r1)
	  stfd      f30, 0x228(r1)
	  stfd      f29, 0x220(r1)
	  stfd      f28, 0x218(r1)
	  stfd      f27, 0x210(r1)
	  stmw      r27, 0x1FC(r1)
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        -0x3BC0
	  lwz       r29, 0x8(r1)
	  lis       r3, 0x802E
	  addi      r0, r3, 0x1768
	  stw       r0, 0x0(r29)
	  li        r8, 0
	  lis       r3, 0x100
	  stw       r8, 0x148(r29)
	  li        r7, 0x1
	  addi      r6, r3, 0x1000
	  stw       r8, 0x144(r29)
	  li        r5, 0x2000
	  li        r0, 0x11D
	  stw       r8, 0x14C(r29)
	  addi      r3, r29, 0
	  li        r4, -0x1
	  stw       r8, 0x150(r29)
	  lfs       f0, -0x4688(r2)
	  stfs      f0, 0x158(r29)
	  stfs      f0, 0x154(r29)
	  lfs       f2, -0x468C(r2)
	  stfs      f2, 0x168(r29)
	  stfs      f2, 0x164(r29)
	  stfs      f2, 0x160(r29)
	  stfs      f2, 0x15C(r29)
	  stfs      f0, 0x170(r29)
	  stfs      f0, 0x16C(r29)
	  stfs      f0, 0x178(r29)
	  stfs      f0, 0x174(r29)
	  stw       r8, 0x17C(r29)
	  stw       r8, 0x180(r29)
	  stfs      f0, 0x188(r29)
	  stfs      f0, 0x184(r29)
	  stfs      f2, 0x198(r29)
	  stfs      f2, 0x194(r29)
	  stfs      f2, 0x190(r29)
	  stfs      f2, 0x18C(r29)
	  stfs      f0, 0x1A0(r29)
	  stfs      f0, 0x19C(r29)
	  stfs      f0, 0x1A8(r29)
	  stfs      f0, 0x1A4(r29)
	  stw       r8, 0x1B4(r29)
	  stfs      f2, 0x1B8(r29)
	  stfs      f0, 0x1BC(r29)
	  lfs       f1, 0x1B8(r29)
	  lfs       f0, 0x1BC(r29)
	  fdivs     f0, f1, f0
	  stfs      f0, 0x1C0(r29)
	  stw       r8, 0x100(r29)
	  stfs      f2, 0x104(r29)
	  lfs       f0, -0x4690(r2)
	  stfs      f0, 0x108(r29)
	  stfs      f2, 0x10C(r29)
	  stw       r8, 0x110(r29)
	  stw       r7, 0x114(r29)
	  stw       r6, 0x1C4(r29)
	  stw       r5, 0x1C8(r29)
	  stw       r0, 0x1CC(r29)
	  stb       r8, 0x1D4(r29)
	  bl        0x1718
	  addi      r3, r29, 0x4
	  lwz       r12, 0x4(r29)
	  lis       r4, 0x7061
	  addi      r4, r4, 0x6C6C
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x134(r29)
	  lis       r4, 0x7365
	  addi      r3, r29, 0x4
	  lwz       r8, 0x134(r29)
	  addi      r4, r4, 0x5F63
	  li        r5, 0x1
	  lha       r6, 0x18(r8)
	  lha       r0, 0x1C(r8)
	  lha       r7, 0x1A(r8)
	  sub       r0, r0, r6
	  lha       r6, 0x1E(r8)
	  srawi     r0, r0, 0x1
	  sub       r7, r6, r7
	  extsh     r6, r0
	  srawi     r0, r7, 0x1
	  sth       r6, 0xB8(r8)
	  extsh     r0, r0
	  sth       r0, 0xBA(r8)
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x13
	  bne-      .loc_0x1BC
	  lwz       r0, 0xF4(r3)
	  stw       r0, 0x1AC(r29)
	  lwz       r0, 0xF8(r3)
	  stw       r0, 0x1B0(r29)

	.loc_0x1BC:
	  lwz       r29, 0x8(r1)
	  lwz       r5, 0x134(r29)
	  addi      r3, r29, 0x1B4
	  addi      r4, r29, 0x4
	  bl        0x6204
	  addi      r3, r29, 0x4
	  lwz       r28, 0x134(r29)
	  lwz       r12, 0x4(r29)
	  lis       r4, 0x796F
	  addi      r4, r4, 0x6B6F
	  lwz       r12, 0x34(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  stw       r3, 0x148(r29)
	  lwz       r0, 0x148(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x22C
	  li        r0, 0
	  stw       r0, 0x144(r29)
	  mr        r4, r28
	  lwz       r3, 0x148(r29)
	  lfs       f0, -0x468C(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x148(r29)
	  bl        -0x3784

	.loc_0x22C:
	  addi      r3, r1, 0x1B0
	  crclr     6, 0x6
	  li        r27, 0
	  addi      r4, r13, 0x1B70
	  li        r5, 0
	  bl        0x5325C
	  b         .loc_0x260

	.loc_0x248:
	  addi      r27, r27, 0x1
	  crclr     6, 0x6
	  addi      r5, r27, 0
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B70
	  bl        0x53240

	.loc_0x260:
	  lwz       r28, 0x8(r1)
	  li        r5, 0
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r28)
	  addi      r3, r28, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  cmplwi    r3, 0
	  bne+      .loc_0x248
	  stw       r27, 0x114(r28)
	  lwz       r29, 0x114(r28)
	  mulli     r3, r29, 0xC
	  addi      r3, r3, 0x8
	  bl        -0x17C3AC
	  lis       r4, 0x801C
	  lis       r5, 0x801C
	  addi      r4, r4, 0x3C4C
	  addi      r5, r5, 0x3BF8
	  addi      r7, r29, 0
	  li        r6, 0xC
	  bl        0x5185C
	  li        r31, 0
	  stw       r3, 0x138(r28)
	  mr        r30, r31
	  b         .loc_0x510

	.loc_0x2E4:
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B78
	  bl        0x531A8
	  lwz       r28, 0x8(r1)
	  li        r5, 0
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r28)
	  addi      r3, r28, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  mr.       r27, r3
	  beq-      .loc_0x348
	  mr        r3, r27
	  lwz       r4, 0x134(r28)
	  bl        -0x38A0

	.loc_0x348:
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B70
	  bl        0x53144
	  lwz       r29, 0x8(r1)
	  li        r5, 0x1
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r29)
	  addi      r3, r29, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  lwz       r4, 0x134(r29)
	  mr        r28, r3
	  bl        -0x38FC
	  lwz       r0, 0x138(r29)
	  addi      r4, r28, 0
	  addi      r5, r27, 0
	  add       r3, r0, r30
	  lwz       r3, 0x0(r3)
	  bl        -0xC8C
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B80
	  bl        0x530D0
	  lwz       r12, 0x4(r29)
	  addi      r3, r29, 0x4
	  lbz       r0, 0x1B1(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x1B2(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x1B3(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  lwz       r5, 0x138(r29)
	  cmplwi    r0, 0x12
	  lwz       r4, 0x134(r29)
	  add       r6, r5, r30
	  bne-      .loc_0x440
	  stw       r3, 0x4(r6)
	  li        r5, 0
	  lwz       r3, 0x4(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x4(r6)
	  bl        -0x3998

	.loc_0x440:
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B88
	  bl        0x5304C
	  lwz       r29, 0x8(r1)
	  li        r5, 0x1
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r29)
	  addi      r3, r29, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  mr        r28, r3
	  lwz       r3, 0x138(r29)
	  lhz       r0, 0x8(r28)
	  lwz       r4, 0x134(r29)
	  add       r6, r3, r30
	  cmplwi    r0, 0x12
	  bne-      .loc_0x4CC
	  stw       r28, 0x8(r6)
	  li        r5, 0
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x8(r6)
	  bl        -0x3A24

	.loc_0x4CC:
	  lwz       r4, 0x8(r1)
	  lhz       r0, 0x8(r28)
	  lwz       r3, 0x138(r4)
	  cmplwi    r0, 0x12
	  lwz       r4, 0x134(r4)
	  add       r6, r3, r30
	  bne-      .loc_0x508
	  stw       r28, 0x8(r6)
	  li        r5, 0
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x8(r6)
	  bl        -0x3A60

	.loc_0x508:
	  addi      r30, r30, 0xC
	  addi      r31, r31, 0x1

	.loc_0x510:
	  lwz       r3, 0x8(r1)
	  lwz       r0, 0x114(r3)
	  cmpw      r31, r0
	  blt+      .loc_0x2E4
	  addi      r3, r1, 0x1B0
	  crclr     6, 0x6
	  li        r29, 0
	  addi      r4, r13, 0x1B90
	  li        r5, 0
	  bl        0x52F68
	  b         .loc_0x554

	.loc_0x53C:
	  addi      r29, r29, 0x1
	  crclr     6, 0x6
	  addi      r5, r29, 0
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B90
	  bl        0x52F4C

	.loc_0x554:
	  lwz       r28, 0x8(r1)
	  li        r5, 0
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r28)
	  addi      r3, r28, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  cmplwi    r3, 0
	  bne+      .loc_0x53C
	  stw       r29, 0x118(r28)
	  lwz       r0, 0x118(r28)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x17C69C
	  stw       r3, 0x13C(r28)
	  lwz       r0, 0x118(r28)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x17C6AC
	  stw       r3, 0x140(r28)
	  lis       r30, 0x4330
	  lwz       r3, 0x118(r28)
	  lfs       f28, -0x4668(r2)
	  subi      r28, r3, 0x1
	  lfs       f29, -0x4688(r2)
	  lfd       f30, -0x4660(r2)
	  rlwinm    r29,r28,2,0,29
	  lfs       f31, -0x4690(r2)
	  lfs       f27, -0x468C(r2)
	  b         .loc_0x91C

	.loc_0x5E4:
	  addi      r5, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B90
	  bl        0x52EA8
	  lwz       r31, 0x8(r1)
	  li        r5, 0x1
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r31)
	  addi      r3, r31, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x77C
	  lwz       r4, 0x13C(r31)
	  stwx      r3, r4, r29
	  lwz       r3, 0x13C(r31)
	  lwz       r4, 0x134(r31)
	  lwzx      r3, r3, r29
	  bl        -0x3BB0
	  lwz       r0, 0x110(r31)
	  lwz       r3, 0x13C(r31)
	  mulli     r4, r0, 0xC
	  lwz       r5, 0x138(r31)
	  lwzx      r3, r3, r29
	  addi      r0, r4, 0x4
	  lwz       r12, 0x0(r3)
	  lwzx      r4, r5, r0
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  mtlr      r12
	  subi      r4, r4, 0x280
	  blrl
	  lwz       r3, 0x13C(r31)
	  li        r4, 0x1
	  cmpwi     r28, 0
	  lwzx      r3, r3, r29
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x13C(r31)
	  lwzx      r5, r3, r29
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x1
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)
	  lwz       r3, 0x13C(r31)
	  lwzx      r3, r3, r29
	  stfs      f27, 0xC0(r3)
	  stfs      f27, 0xC4(r3)
	  stfs      f27, 0xC8(r3)
	  bne-      .loc_0x710
	  lwz       r3, 0x13C(r31)
	  li        r4, 0xFF
	  lwzx      r3, r3, r29
	  bl        -0x3F2C
	  b         .loc_0x77C

	.loc_0x710:
	  lwz       r0, 0x118(r31)
	  xoris     r3, r28, 0x8000
	  stw       r3, 0x1F4(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1EC(r1)
	  stw       r30, 0x1F0(r1)
	  stw       r30, 0x1E8(r1)
	  lfd       f1, 0x1F0(r1)
	  lfd       f0, 0x1E8(r1)
	  fsubs     f1, f1, f30
	  fsubs     f0, f0, f30
	  fdivs     f0, f1, f0
	  fsubs     f0, f29, f0
	  fmuls     f0, f28, f0
	  fcmpo     cr0, f0, f27
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x75C
	  fadds     f0, f31, f0
	  b         .loc_0x760

	.loc_0x75C:
	  fsubs     f0, f0, f31

	.loc_0x760:
	  fctiwz    f0, f0
	  lwz       r3, 0x13C(r31)
	  lwzx      r3, r3, r29
	  stfd      f0, 0x1E8(r1)
	  lwz       r0, 0x1EC(r1)
	  rlwinm    r4,r0,0,24,31
	  bl        -0x3F9C

	.loc_0x77C:
	  addi      r5, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B98
	  bl        0x52D10
	  lwz       r31, 0x8(r1)
	  li        r5, 0x1
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r31)
	  addi      r3, r31, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x914
	  lwz       r4, 0x140(r31)
	  stwx      r3, r4, r29
	  lwz       r3, 0x140(r31)
	  lwz       r4, 0x134(r31)
	  lwzx      r3, r3, r29
	  bl        -0x3D48
	  lwz       r0, 0x110(r31)
	  lwz       r3, 0x140(r31)
	  mulli     r4, r0, 0xC
	  lwz       r5, 0x138(r31)
	  lwzx      r3, r3, r29
	  addi      r0, r4, 0x8
	  lwz       r12, 0x0(r3)
	  lwzx      r4, r5, r0
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  mtlr      r12
	  addi      r4, r4, 0x280
	  blrl
	  lwz       r3, 0x140(r31)
	  li        r4, 0x1
	  cmpwi     r28, 0
	  lwzx      r3, r3, r29
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x140(r31)
	  lwzx      r5, r3, r29
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x1
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)
	  lwz       r3, 0x140(r31)
	  lwzx      r3, r3, r29
	  stfs      f27, 0xC0(r3)
	  stfs      f27, 0xC4(r3)
	  stfs      f27, 0xC8(r3)
	  bne-      .loc_0x8A8
	  lwz       r3, 0x140(r31)
	  li        r4, 0xFF
	  lwzx      r3, r3, r29
	  bl        -0x40C4
	  b         .loc_0x914

	.loc_0x8A8:
	  lwz       r0, 0x118(r31)
	  xoris     r3, r28, 0x8000
	  stw       r3, 0x1EC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1F4(r1)
	  stw       r30, 0x1E8(r1)
	  stw       r30, 0x1F0(r1)
	  lfd       f1, 0x1E8(r1)
	  lfd       f0, 0x1F0(r1)
	  fsubs     f1, f1, f30
	  fsubs     f0, f0, f30
	  fdivs     f0, f1, f0
	  fsubs     f0, f29, f0
	  fmuls     f0, f28, f0
	  fcmpo     cr0, f0, f27
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x8F4
	  fadds     f0, f31, f0
	  b         .loc_0x8F8

	.loc_0x8F4:
	  fsubs     f0, f0, f31

	.loc_0x8F8:
	  fctiwz    f0, f0
	  lwz       r3, 0x140(r31)
	  lwzx      r3, r3, r29
	  stfd      f0, 0x1E8(r1)
	  lwz       r0, 0x1EC(r1)
	  rlwinm    r4,r0,0,24,31
	  bl        -0x4134

	.loc_0x914:
	  subi      r29, r29, 0x4
	  subi      r28, r28, 0x1

	.loc_0x91C:
	  cmpwi     r28, 0
	  bge+      .loc_0x5E4
	  lwz       r31, 0x8(r1)
	  lis       r28, 0x7A2A
	  lfs       f0, -0x468C(r2)
	  lis       r30, 0x4330
	  addi      r3, r31, 0x14C
	  stfs      f0, 0x11C(r31)
	  addi      r4, r31, 0x4
	  addi      r6, r28, 0x2A6C
	  lfs       f0, -0x4690(r2)
	  stfs      f0, 0x120(r31)
	  lwz       r0, 0x110(r31)
	  lwz       r7, 0x138(r31)
	  mulli     r5, r0, 0xC
	  lfd       f2, -0x4660(r2)
	  addi      r0, r5, 0x4
	  lwzx      r5, r7, r0
	  lha       r5, 0x18(r5)
	  subi      r0, r5, 0x280
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1EC(r1)
	  stw       r30, 0x1E8(r1)
	  lfd       f0, 0x1E8(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x124(r31)
	  lwz       r0, 0x110(r31)
	  lwz       r7, 0x138(r31)
	  mulli     r5, r0, 0xC
	  addi      r0, r5, 0x4
	  lwzx      r5, r7, r0
	  lha       r0, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1F4(r1)
	  stw       r30, 0x1F0(r1)
	  lfd       f0, 0x1F0(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x128(r31)
	  lwz       r0, 0x110(r31)
	  lwz       r7, 0x138(r31)
	  mulli     r5, r0, 0xC
	  addi      r0, r5, 0x8
	  lwzx      r5, r7, r0
	  lha       r5, 0x18(r5)
	  addi      r0, r5, 0x280
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1E4(r1)
	  stw       r30, 0x1E0(r1)
	  lfd       f0, 0x1E0(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x12C(r31)
	  lwz       r0, 0x110(r31)
	  lwz       r7, 0x138(r31)
	  mulli     r5, r0, 0xC
	  addi      r0, r5, 0x8
	  lwzx      r5, r7, r0
	  lha       r0, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1DC(r1)
	  stw       r30, 0x1D8(r1)
	  lfd       f0, 0x1D8(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x130(r31)
	  lwz       r0, 0x110(r31)
	  lwz       r8, 0x138(r31)
	  mulli     r7, r0, 0xC
	  lwz       r5, 0x134(r31)
	  addi      r0, r7, 0x4
	  lwzx      r8, r8, r0
	  lha       r7, 0x18(r8)
	  lha       r8, 0x1A(r8)
	  subi      r0, r7, 0x280
	  xoris     r7, r0, 0x8000
	  xoris     r0, r8, 0x8000
	  stw       r7, 0x1D4(r1)
	  stw       r0, 0x1CC(r1)
	  stw       r30, 0x1D0(r1)
	  stw       r30, 0x1C8(r1)
	  lfd       f1, 0x1D0(r1)
	  lfd       f0, 0x1C8(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x170DC
	  lwz       r0, 0x110(r31)
	  addi      r3, r31, 0x17C
	  lwz       r7, 0x138(r31)
	  addi      r4, r31, 0x4
	  mulli     r6, r0, 0xC
	  lfd       f2, -0x4660(r2)
	  lwz       r5, 0x134(r31)
	  addi      r0, r6, 0x8
	  lwzx      r8, r7, r0
	  addi      r6, r28, 0x2A72
	  lha       r7, 0x18(r8)
	  lha       r8, 0x1A(r8)
	  addi      r0, r7, 0x280
	  xoris     r7, r0, 0x8000
	  xoris     r0, r8, 0x8000
	  stw       r7, 0x1C4(r1)
	  stw       r0, 0x1BC(r1)
	  stw       r30, 0x1C0(r1)
	  stw       r30, 0x1B8(r1)
	  lfd       f1, 0x1C0(r1)
	  lfd       f0, 0x1B8(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x1707C
	  mr        r3, r31
	  bl        0x48C
	  mr        r3, r31
	  lmw       r27, 0x1FC(r1)
	  lwz       r0, 0x23C(r1)
	  lfd       f31, 0x230(r1)
	  lfd       f30, 0x228(r1)
	  lfd       f29, 0x220(r1)
	  lfd       f28, 0x218(r1)
	  lfd       f27, 0x210(r1)
	  addi      r1, r1, 0x238
	  mtlr      r0
	  blr
	*/
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
