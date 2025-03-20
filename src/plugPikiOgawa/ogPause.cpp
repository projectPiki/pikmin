#include "zen/ogPause.h"
#include "zen/DrawMenu.h"
#include "P2D/Screen.h"
#include "P2D/TextBox.h"
#include "P2D/Picture.h"
#include "P2D/Graph.h"
#include "DebugLog.h"
#include "sysNew.h"
#include "PlayerState.h"

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
DEFINE_PRINT("OgPauseSection")

/*
 * --INFO--
 * Address:	80182318
 * Size:	000324
 */
zen::ogScrPauseMgr::ogScrPauseMgr()
{
	mMode        = 0;
	mBlackScreen = new P2DScreen();
	mBlackScreen->set("screen/blo/black.blo", false, false, true);
	// this might be P2DTextBox instead, unsure
	mBlackPane = static_cast<P2DPicture*>(mBlackScreen->search('blck', true));
	mBlackPane->setAlpha(0);

	mDrawMenu1 = new DrawMenu("screen/blo/pause.blo", false, false);
	_14        = mDrawMenu1->getScreenPtr();
	mTextBox4  = static_cast<P2DTextBox*>(_14->search('yame', true));
	mTextBox5  = static_cast<P2DTextBox*>(_14->search('he02', true));
	mTextBox6  = static_cast<P2DTextBox*>(_14->search('hm02', true));

	_3C = mTextBox4->getString();
	_40 = mTextBox5->getString();

	mTextBox4->hide();

	mDrawMenu2 = new DrawMenu("screen/blo/pause_ok.blo", false, false);
	_18        = mDrawMenu2->getScreenPtr();
	mTextBox1  = static_cast<P2DTextBox*>(_18->search('yame', true));
	mTextBox2  = static_cast<P2DTextBox*>(_18->search('titl', true));
	mTextBox3  = static_cast<P2DTextBox*>(_18->search('even', true));

	mTextBox1->hide();
	mTextBox2->hide();
	mTextBox3->hide();

	mState = PAUSE_NULL;
	_00    = 0;

	// this might be P2DTextBox instead, unsure
	mBackPane1 = static_cast<P2DPicture*>(_14->search('back', true));
	mBackPane1->setAlpha(0);
	mBackPane1->hide();

	// this might be P2DTextBox instead, unsure
	mBackPane2 = static_cast<P2DPicture*>(_18->search('back', true));
	mBackPane2->setAlpha(0);
	mBackPane2->hide();
}

/*
 * --INFO--
 * Address:	8018263C
 * Size:	00008C
 */
void zen::ogScrPauseMgr::start(bool p1)
{
	mMode = p1;

	if (mMode != 0) {
		mTextBox5->setString(_3C);
		mTextBox6->setString(_3C);
	} else {
		mTextBox5->setString(_40);
		mTextBox6->setString(_40);
	}

	mDrawMenu1->start(-1);
	mState      = PAUSE_Unk1;
	mFrameTimer = 0.0f;
	_00         = 1;
}

/*
 * --INFO--
 * Address:	801826C8
 * Size:	0003C0
 */
zen::ogScrPauseMgr::PauseStatus zen::ogScrPauseMgr::update(Controller* controller)
{
	if (mState == PAUSE_NULL) {
		return mState;
	}

	if (mState >= PAUSE_Unk5) {
		mState = PAUSE_NULL;
		return mState;
	}

	if (!playerState->getCurrDay() || playerState->getCurrDay() == playerState->getTotalDays() - 1) {
		mDrawMenu1->setMenuItemActiveSw(1, false);
	} else {
		mDrawMenu1->setMenuItemActiveSw(1, true);
	}

	mBlackScreen->update();
	mDrawMenu1->update(controller);
	mDrawMenu2->update(controller);
	mFrameTimer += gsys->getFrameTime();

	switch (mState) {
	case PAUSE_Unk2:
		if (0.5f < mFrameTimer) {

			mState = mState2;
			_00    = 0;
		} else {
		}
		break;
	case PAUSE_Unk1:

		if (mDrawMenu1->_1D0 < 0) {
			if (mDrawMenu1->_1D4 == 0) {

			} else {
			}
		}

		if (mDrawMenu1->_100 == 0) {
			if (mDrawMenu1->_110 == 0) {
				mState2     = PAUSE_Unk5;
				mState      = PAUSE_Unk2;
				mFrameTimer = 0.0f;
			}
			if (mDrawMenu1->_110 == 1) {
				mState = PAUSE_Unk3;
				mDrawMenu2->start(0);
				mTextBox1->hide();
				mTextBox2->hide();
				mTextBox3->show();
			}
			if (mDrawMenu1->_110 == 2) {
				mState = PAUSE_Unk4;
				mDrawMenu2->start(0);
				mTextBox1->hide();
				mTextBox2->hide();
				mTextBox3->hide();
				if (mMode) {
					mTextBox1->show();
				} else {
					mTextBox2->show();
				}
			}
		}

		break;
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stw       r31, 0x94(r1)
	  mr        r31, r3
	  stw       r30, 0x90(r1)
	  stw       r29, 0x8C(r1)
	  addi      r29, r4, 0
	  lwz       r3, 0x4(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x30
	  b         .loc_0x3A4

	.loc_0x30:
	  cmpwi     r3, 0x5
	  blt-      .loc_0x48
	  li        r0, -0x1
	  stw       r0, 0x4(r31)
	  lwz       r3, 0x4(r31)
	  b         .loc_0x3A4

	.loc_0x48:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x101B64
	  cmpwi     r3, 0
	  beq-      .loc_0x74
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x101B60
	  subi      r30, r3, 0x1
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x101B80
	  cmpw      r3, r30
	  bne-      .loc_0x88

	.loc_0x74:
	  lwz       r3, 0xC(r31)
	  li        r4, 0x1
	  li        r5, 0
	  bl        0x421C4
	  b         .loc_0x98

	.loc_0x88:
	  lwz       r3, 0xC(r31)
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x421B0

	.loc_0x98:
	  lwz       r3, 0x1C(r31)
	  bl        0x303EC
	  lwz       r3, 0xC(r31)
	  mr        r4, r29
	  bl        0x41D64
	  lwz       r3, 0x10(r31)
	  mr        r4, r29
	  bl        0x41D58
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x50(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x50(r31)
	  lwz       r6, 0x4(r31)
	  cmpwi     r6, 0x2
	  beq-      .loc_0x14C
	  bge-      .loc_0xEC
	  cmpwi     r6, 0
	  beq-      .loc_0x1A8
	  bge-      .loc_0xF8
	  b         .loc_0x3A0

	.loc_0xEC:
	  cmpwi     r6, 0x5
	  bge-      .loc_0x3A0
	  b         .loc_0x2EC

	.loc_0xF8:
	  lfs       f2, 0x50(r31)
	  lfs       f1, -0x5094(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x134
	  lfs       f0, -0x5090(r2)
	  fmuls     f0, f0, f2
	  fdivs     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r0, 0x84(r1)
	  stb       r0, 0x54(r31)
	  lbz       r0, 0x54(r31)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x3A0

	.loc_0x134:
	  lwz       r3, 0x20(r31)
	  li        r4, 0x80
	  li        r0, 0
	  stb       r4, 0xF0(r3)
	  stw       r0, 0x4(r31)
	  b         .loc_0x3A0

	.loc_0x14C:
	  lfs       f2, 0x50(r31)
	  lfs       f1, -0x5094(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x18C
	  lfs       f0, -0x5090(r2)
	  fmuls     f0, f0, f2
	  fdivs     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r0, 0x84(r1)
	  stb       r0, 0x54(r31)
	  lbz       r0, 0x54(r31)
	  lwz       r3, 0x20(r31)
	  subfic    r0, r0, 0x80
	  stb       r0, 0xF0(r3)
	  b         .loc_0x3A0

	.loc_0x18C:
	  lwz       r3, 0x20(r31)
	  li        r4, 0
	  stb       r4, 0xF0(r3)
	  lwz       r0, 0x8(r31)
	  stw       r0, 0x4(r31)
	  stb       r4, 0x0(r31)
	  b         .loc_0x3A0

	.loc_0x1A8:
	  lwz       r4, 0xC(r31)
	  lwz       r0, 0x1D0(r4)
	  lwz       r3, 0x100(r4)
	  cmpwi     r0, 0
	  blt-      .loc_0x1C4
	  lwz       r0, 0x110(r4)
	  b         .loc_0x1DC

	.loc_0x1C4:
	  lbz       r0, 0x1D4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x1D8
	  li        r0, -0x1
	  b         .loc_0x1DC

	.loc_0x1D8:
	  lwz       r0, 0x110(r4)

	.loc_0x1DC:
	  cmpwi     r3, 0
	  bne-      .loc_0x3A0
	  cmpwi     r0, 0
	  bgt-      .loc_0x208
	  li        r0, 0x5
	  stw       r0, 0x8(r31)
	  li        r0, 0x2
	  stw       r0, 0x4(r31)
	  lfs       f0, -0x5098(r2)
	  stfs      f0, 0x50(r31)
	  b         .loc_0x3A0

	.loc_0x208:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x260
	  li        r0, 0x3
	  stw       r0, 0x4(r31)
	  li        r4, 0
	  lwz       r3, 0x10(r31)
	  bl        0x413D0
	  lwz       r3, 0x24(r31)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x28(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x2C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x3A0

	.loc_0x260:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x3A0
	  li        r0, 0x4
	  stw       r0, 0x4(r31)
	  li        r4, 0
	  lwz       r3, 0x10(r31)
	  bl        0x41378
	  lwz       r3, 0x24(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x28(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x2C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lbz       r0, 0x44(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x2D4
	  lwz       r3, 0x24(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x3A0

	.loc_0x2D4:
	  lwz       r3, 0x28(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x3A0

	.loc_0x2EC:
	  lwz       r3, 0x10(r31)
	  lwz       r0, 0x1D0(r3)
	  lwz       r4, 0x100(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x308
	  lwz       r5, 0x110(r3)
	  b         .loc_0x320

	.loc_0x308:
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x31C
	  li        r5, -0x1
	  b         .loc_0x320

	.loc_0x31C:
	  lwz       r5, 0x110(r3)

	.loc_0x320:
	  cmpwi     r4, 0
	  bne-      .loc_0x3A0
	  cmpwi     r5, 0
	  bne-      .loc_0x370
	  cmpwi     r6, 0x4
	  beq-      .loc_0x354
	  bge-      .loc_0x35C
	  cmpwi     r6, 0x3
	  bge-      .loc_0x348
	  b         .loc_0x35C

	.loc_0x348:
	  li        r0, 0x6
	  stw       r0, 0x8(r31)
	  b         .loc_0x35C

	.loc_0x354:
	  li        r0, 0x7
	  stw       r0, 0x8(r31)

	.loc_0x35C:
	  li        r0, 0x2
	  stw       r0, 0x4(r31)
	  lfs       f0, -0x5098(r2)
	  stfs      f0, 0x50(r31)
	  b         .loc_0x3A0

	.loc_0x370:
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x384
	  cmpwi     r5, 0x1
	  bne-      .loc_0x3A0

	.loc_0x384:
	  li        r4, -0x1
	  bl        0x41EE8
	  lwz       r3, 0xC(r31)
	  li        r4, -0x1
	  bl        0x4125C
	  li        r0, 0
	  stw       r0, 0x4(r31)

	.loc_0x3A0:
	  lwz       r3, 0x4(r31)

	.loc_0x3A4:
	  lwz       r0, 0x9C(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  lwz       r29, 0x8C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80182A88
 * Size:	0000B0
 */
void zen::ogScrPauseMgr::draw(Graphics& gfx)
{
	if (mState == PAUSE_NULL) {
		return;
	}

	P2DPerspGraph perspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	perspGraph.setPort();
	mBlackScreen->draw(0, 0, &perspGraph);
	mDrawMenu1->draw(gfx);
	mDrawMenu2->draw(gfx);
}
