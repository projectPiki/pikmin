#include "zen/ogSave.h"
#include "P2D/Screen.h"
#include "P2D/Picture.h"
#include "P2D/TextBox.h"
#include "P2D/Graph.h"
#include "zen/ogFileChkSel.h"
#include "zen/DrawSave.h"
#include "zen/ogMemChk.h"
#include "zen/ogNitaku.h"
#include "zen/ogSub.h"
#include "SoundMgr.h"
#include "sysNew.h"
#include "gameflow.h"
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
DEFINE_PRINT("OgSaveSection")

/*
 * --INFO--
 * Address:	80195740
 * Size:	00073C
 */
zen::ogSaveMgr::ogSaveMgr()
{
	_30     = 0;
	mScreen = new P2DScreen;
	mScreen->set("screen/blo/ac_save.blo", true, true, true);
	mStatus = Status_NULL;

	_34 = (P2DTextBox*)mScreen->search('he00', true);
	_38 = (P2DTextBox*)mScreen->search('he01', true);
	_3C = mScreen->search('hs00', true);
	_40 = mScreen->search('hs01', true);
	_4C = (P2DTextBox*)mScreen->search('se_c', true);
	_70 = (P2DPicture*)mScreen->search('back', true);
	_50 = (P2DTextBox*)mScreen->search('sa_c', true);
	_54 = (P2DTextBox*)mScreen->search('sa_s', true);
	_58 = mScreen->search('sakc', true);
	_5C = mScreen->search('saks', true);

	_34->show();
	_38->show();
	_3C->show();
	_40->show();
	_70->setAlpha(0);
	_78 = mScreen->search('1win', true);
	_78->show();
	_78->setOffset(_78->getWidth() / 2, _78->getHeight() / 2);
	_78->setScale(0.0f);

	_18 = new ogNitakuMgr(mScreen, _34, _38, _4C, true, true);

	_80 = mScreen->search('chui', true);
	_80->show();
	_80->setOffset(_80->getWidth() / 2, _80->getHeight() / 2);
	_80->setScale(0.0f);

	_60 = new ogFadeMgr(_50, _50->getAlphaChar());
	_64 = new ogFadeMgr(_54, _54->getAlphaChar());
	_68 = new ogFadeMgr(_58, 255);
	_6C = new ogFadeMgr(_5C, 255);

	_24 = new P2DScreen;
	_24->set("screen/blo/black.blo", false, false, true);
	_28 = (P2DPicture*)_24->search('blck', true);
	_28->setAlpha(255);

	_0C = new P2DScreen;
	_0C->set("screen/blo/ac_save2.blo", true, true, true);
	_44 = (P2DTextBox*)_0C->search('he00', true);
	_48 = (P2DTextBox*)_0C->search('he01', true);

	_7C = _0C->search('2win', true);
	_7C->show();
	_7C->setOffset(_7C->getWidth() / 2, _7C->getHeight() / 2);
	_7C->setScale(0.0f);

	_74 = (P2DPicture*)_0C->search('back', true);
	_74->setAlpha(0);

	_1C          = new ogNitakuMgr(_0C, _44, _48, _4C, true, true);
	mMemCheckMgr = new ogScrMemChkMgr;
	mSaveFail    = new DrawSaveFailure;
	mSaveFail->init();
	_84 = new ogScrFileChkSelMgr;

	_10 = 0.0f;
	_04 = Status_NULL;
	_14 = 0;
}

/*
 * --INFO--
 * Address:	80195E7C
 * Size:	0000C0
 */
void zen::ogSaveMgr::start()
{
	mStatus = Status_1;
	_10     = 0.0f;
	_78->setScale(0.0f);
	_78->show();
	_7C->setScale(0.0f);
	_7C->show();
	_34->show();
	_38->show();
	_3C->show();
	_40->show();
	_50->hide();
	_54->hide();
	_70->setAlpha(0);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000138
 */
void zen::ogSaveMgr::startDirectSave(s16 state)
{
	start();
	mStatus = Status_3;
	_10     = 0.0f;
	_32     = state;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80195F3C
 * Size:	000834
 */
zen::ogSaveMgr::SaveStatus zen::ogSaveMgr::update(Controller* input)
{
	if (mStatus == Status_NULL) {
		return mStatus;
	}

	if (mStatus >= 12) {
		mStatus = Status_NULL;
		return mStatus;
	}

	_24->update();
	bool savefail = mSaveFail->update(input);
	if (savefail == false) {
		return mStatus;
	}

	zen::ogScrFileChkSelMgr::returnStatusFlag res = _84->update(input, _88);
	if (res == 0) {
		gameflow.mPlayState._23              = _88._04;
		gameflow.mPlayState.mCourseOpenFlags = _88.mIndex + 1;
		mStatus                              = Status_3;
		_10                                  = 0.0f;
		_30                                  = 0;
	} else if (res == 5) {
		mStatus = Status_0;
		_30     = 0;
		return mStatus;
	} else if (res == 1) {
		mStatus = Status_0;
		_30     = 0;
		return mStatus;
	} else if (res != -1) {
		_30 = 1;
		return mStatus;
	}

	zen::ogScrMemChkMgr::MemChkStatus res2 = mMemCheckMgr->update(input);
	if (res2 == 21) {
		_84->startSave();
		_30     = 1;
		mStatus = Status_3;
		_10     = 0.0f;
	} else if (res2 == 20) {
		mStatus = Status_0;
		return mStatus;
	} else if (res2 == 19) {
		mStatus = Status_0;
		return mStatus;
	} else if (res2 != -1) {
		return mStatus;
	}

	_10 += gsys->getFrameTime();
	mScreen->update();
	int nikatu1 = _18->update(input);
	_0C->update();
	int nikatu2 = _1C->update(input);
	_60->update();
	_64->update();
	_68->update();
	_6C->update();

	switch (mStatus) {
	case Status_0:
		if (nikatu1 == 5) {
			mStatus = Status_4;
			_10     = 0.0f;
			_34->hide();
			_38->hide();
			_3C->show();
			_40->show();
			_50->show();
			_54->show();
			_60->start(ogFadeMgr::Status_1, 0.25f);
			_68->start(ogFadeMgr::Status_1, 0.25f);
			if (gameflow.mMemoryCard.hasCardChanged()) {
				PRINT("#############################\n");
				PRINT("#      NOT SAME FILE        #\n");
				PRINT("#############################\n");
				mMemCheckMgr->start();
				if (mMemCheckMgr->update(input) == 21) {
					_84->startSave();
					mStatus = Status_3;
					_10     = 0.0f;
				}
			} else {
				PRINT("#############################\n");
				PRINT("#         SAME FILE         #\n");
				PRINT("#############################\n");
			}
		} else if (nikatu1 == 6) {
			mStatus = Status_7;
			_10     = 0.0f;
		} else if (nikatu1 == 4) {
			seSystem->playSysSe(SYSSE_CANCEL);
			_04     = Status_7;
			mStatus = Status_2;
			_10     = 0.0f;
		}
		break;
	case Status_1:
		if (_10 > 0.25f) {
			_78->setScale(1.0f);
			_18->start();
		} else {
			_78->setScale(_10 / 0.25f);
			_70->setAlpha(_10 * _4C->getAlphaChar());
		}
		break;
	case Status_2:
		if (_10 > 0.25f) {
			mStatus = _04;
			_78->setScale(1.0f);
		} else {
			_78->setScale(1.0f - (_10 / 0.25f));
			_70->setAlpha(_10 * _4C->getAlphaChar());
		}
		break;
	case Status_3:
		if (_10 > 0.25f) {
			mStatus = Status_4;
			_10     = 0.0f;
			_78->setScale(1.0f);
			_50->show();
			_54->show();
			_60->start(ogFadeMgr::Status_1, 0.25f);
			_68->start(ogFadeMgr::Status_1, 0.25f);
			PRINT("######################\n");
			PRINT("##\tSAVE to (%d)   ##\n", _32);
			PRINT("######################\n");
		} else {
			_78->setScale(1.0f - (_10 / 0.25f));
			_70->setAlpha(_10 * _4C->getAlphaChar());
		}
		break;
	case Status_4:
		if (_10 > 0.25f) {
			f32 scale = _10 * 3.0f;
			if (scale > 1.0f) {
				scale = 1.0f;
			}
			_80->setScale(scale);
		} else {
			mStatus = Status_5;
			_10     = 0.0f;
			seSystem->playSysSe(SYSSE_CARDACCESS);
			gameflow.mMemoryCard.saveCurrentGame();
		}
		break;
	case Status_5:
		_80->setScale(1.0f);
		seSystem->playSysSe(SYSSE_CARDOK);
		if (gameflow.mMemoryCard.didSaveFail()) {
			mSaveFail->open(1.0f);
			_04     = Status_2;
			mStatus = Status_1;
			_10     = 0.0f;
		} else {
			mStatus = Status_6;
			_10     = 0.0f;
			_60->start(ogFadeMgr::Status_2, 0.25f);
			_68->start(ogFadeMgr::Status_2, 0.25f);
			_64->start(ogFadeMgr::Status_1, 0.25f);
			_6C->start(ogFadeMgr::Status_1, 0.25f);
		}
		break;
	case Status_6:
		if (_10 > 1.0f) {
			_04     = Status_5;
			mStatus = Status_2;
			_10     = 0.0f;
			_64->start(ogFadeMgr::Status_2, 0.25f);
			_6C->start(ogFadeMgr::Status_2, 0.25f);
		}
		break;
	case Status_7:
		if (_10 > 0.25f) {
			_78->setScale(0.0f);
			mStatus = Status_8;
			_10     = 0.0f;
		} else {
			_78->setScale(1.0f - (_10 / 0.25f));
		}
		break;
	case Status_8:
		if (_10 > 0.25f) {
			mStatus = Status_9;
			_7C->setScale(1.0f);
			_1C->start();
		} else {
			_7C->setScale((_10 / 0.25f));
		}
		break;
	case Status_9:
		if (nikatu2 == 5) {
			_04     = Status_11;
			mStatus = Status_10;
			_10     = 0.0f;
		} else if (nikatu2 == 6) {
			_04     = Status_11;
			mStatus = Status_10;
			_10     = 0.0f;
		} else if (nikatu2 == 4) {
			seSystem->playSysSe(SYSSE_CANCEL);
			_04     = Status_1;
			mStatus = Status_10;
			_10     = 0.0f;
		}
		break;
	case Status_10:
		if (_10 > 0.25f) {
			_7C->setScale(0.0f);
			mStatus = _04;
			_10     = 0.0f;
		} else {
			_7C->setScale(1.0f - (_10 / 0.25f));
		}
		break;
	case Status_11:
		if (!savefail) {
			_04     = Status_10;
			mStatus = Status_2;
			_10     = 0.0f;
		}
		break;
	}
	return mStatus;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stmw      r27, 0xBC(r1)
	  mr        r29, r3
	  addi      r30, r4, 0
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x28
	  b         .loc_0x820

	.loc_0x28:
	  cmpwi     r3, 0xC
	  blt-      .loc_0x40
	  li        r0, -0x1
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x0(r29)
	  b         .loc_0x820

	.loc_0x40:
	  lwz       r3, 0x24(r29)
	  bl        0x1CBD0
	  lwz       r3, 0x2C(r29)
	  mr        r4, r30
	  bl        0x5D6C8
	  rlwinm.   r0,r3,0,24,31
	  addi      r31, r3, 0
	  bne-      .loc_0x68
	  lwz       r3, 0x0(r29)
	  b         .loc_0x820

	.loc_0x68:
	  lwz       r3, 0x84(r29)
	  addi      r4, r30, 0
	  addi      r5, r29, 0x88
	  bl        -0x2868
	  subi      r0, r3, 0x2
	  cmplwi    r0, 0x2
	  bgt-      .loc_0xBC
	  lis       r3, 0x803A
	  lwz       r0, 0x8C(r29)
	  subi      r5, r3, 0x2848
	  stb       r0, 0x1C7(r5)
	  li        r3, 0x3
	  li        r0, 0
	  lwz       r4, 0x88(r29)
	  addi      r4, r4, 0x1
	  stb       r4, 0xB5(r5)
	  stw       r3, 0x0(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  stb       r0, 0x30(r29)
	  b         .loc_0x114

	.loc_0xBC:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xDC
	  li        r0, 0xD
	  stw       r0, 0x0(r29)
	  li        r0, 0
	  stb       r0, 0x30(r29)
	  lwz       r3, 0x0(r29)
	  b         .loc_0x820

	.loc_0xDC:
	  cmpwi     r3, 0x1
	  bne-      .loc_0xFC
	  li        r0, 0xC
	  stw       r0, 0x0(r29)
	  li        r0, 0
	  stb       r0, 0x30(r29)
	  lwz       r3, 0x0(r29)
	  b         .loc_0x820

	.loc_0xFC:
	  cmpwi     r3, -0x1
	  beq-      .loc_0x114
	  li        r0, 0x1
	  stb       r0, 0x30(r29)
	  lwz       r3, 0x0(r29)
	  b         .loc_0x820

	.loc_0x114:
	  lwz       r3, 0x20(r29)
	  mr        r4, r30
	  bl        -0x7F7C
	  cmpwi     r3, 0x15
	  bne-      .loc_0x14C
	  lwz       r3, 0x84(r29)
	  bl        -0x2974
	  li        r0, 0x1
	  stb       r0, 0x30(r29)
	  li        r0, 0x3
	  stw       r0, 0x0(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  b         .loc_0x18C

	.loc_0x14C:
	  cmpwi     r3, 0x14
	  bne-      .loc_0x164
	  li        r0, 0xD
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x0(r29)
	  b         .loc_0x820

	.loc_0x164:
	  cmpwi     r3, 0x13
	  bne-      .loc_0x17C
	  li        r0, 0xC
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x0(r29)
	  b         .loc_0x820

	.loc_0x17C:
	  cmpwi     r3, -0x1
	  beq-      .loc_0x18C
	  lwz       r3, 0x0(r29)
	  b         .loc_0x820

	.loc_0x18C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r29)
	  lwz       r3, 0x8(r29)
	  bl        0x1CA70
	  lwz       r3, 0x18(r29)
	  mr        r4, r30
	  bl        0xD6C
	  mr        r27, r3
	  lwz       r3, 0xC(r29)
	  bl        0x1CA58
	  lwz       r3, 0x1C(r29)
	  mr        r4, r30
	  bl        0xD54
	  mr        r28, r3
	  lwz       r3, 0x60(r29)
	  bl        -0x16510
	  lwz       r3, 0x64(r29)
	  bl        -0x16518
	  lwz       r3, 0x68(r29)
	  bl        -0x16520
	  lwz       r3, 0x6C(r29)
	  bl        -0x16528
	  lwz       r0, 0x0(r29)
	  cmplwi    r0, 0xB
	  bgt-      .loc_0x81C
	  lis       r3, 0x802D
	  addi      r3, r3, 0x60D4
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lfs       f1, 0x10(r29)
	  lfs       f0, -0x4DC4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x24C
	  li        r0, 0
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x78(r29)
	  lfs       f0, -0x4DC0(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x18(r29)
	  bl        0xAC8
	  b         .loc_0x81C

	.loc_0x24C:
	  fdivs     f2, f1, f0
	  lwz       r3, 0x78(r29)
	  lis       r0, 0x4330
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lwz       r3, 0x4C(r29)
	  lfd       f1, -0x4DB8(r2)
	  lbz       r4, 0xF7(r3)
	  lwz       r3, 0x70(r29)
	  stw       r4, 0xB4(r1)
	  stw       r0, 0xB0(r1)
	  lfd       f0, 0xB0(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0xA8(r1)
	  lwz       r0, 0xAC(r1)
	  stfd      f0, 0xA0(r1)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x81C
	  lfs       f0, 0x10(r29)
	  lfs       f1, -0x4DC4(r2)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x318
	  li        r0, 0x4
	  stw       r0, 0x0(r29)
	  li        r5, 0x1
	  li        r4, 0x1
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  lwz       r3, 0x78(r29)
	  lfs       f0, -0x4DC0(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x50(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x54(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x60(r29)
	  bl        -0x1671C
	  lwz       r3, 0x68(r29)
	  li        r4, 0x1
	  lfs       f1, -0x4DC4(r2)
	  bl        -0x1672C
	  b         .loc_0x81C

	.loc_0x318:
	  fdivs     f2, f0, f1
	  lwz       r3, 0x78(r29)
	  lis       r0, 0x4330
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lwz       r3, 0x4C(r29)
	  lfd       f1, -0x4DB8(r2)
	  lbz       r4, 0xF7(r3)
	  lwz       r3, 0x70(r29)
	  stw       r4, 0xA4(r1)
	  stw       r0, 0xA0(r1)
	  lfd       f0, 0xA0(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0xA8(r1)
	  lwz       r0, 0xAC(r1)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x81C
	  lfs       f1, 0x10(r29)
	  lfs       f0, -0x4DC4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x398
	  lwz       r0, 0x4(r29)
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x78(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  b         .loc_0x81C

	.loc_0x398:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x4DC0(r2)
	  lwz       r3, 0x78(r29)
	  lis       r0, 0x4330
	  fsubs     f2, f1, f0
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lwz       r3, 0x4C(r29)
	  lfd       f1, -0x4DB8(r2)
	  lbz       r4, 0xF7(r3)
	  lwz       r3, 0x70(r29)
	  stw       r4, 0xA4(r1)
	  stw       r0, 0xA0(r1)
	  lfd       f0, 0xA0(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0xA8(r1)
	  lwz       r0, 0xAC(r1)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x81C
	  cmpwi     r27, 0x5
	  bne-      .loc_0x4E8
	  li        r0, 0x4
	  stw       r0, 0x0(r29)
	  li        r6, 0
	  li        r5, 0x1
	  lfs       f0, -0x4DC8(r2)
	  li        r4, 0x1
	  stfs      f0, 0x10(r29)
	  lwz       r3, 0x34(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x38(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x3C(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x40(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x50(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x54(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x60(r29)
	  lfs       f1, -0x4DC4(r2)
	  bl        -0x16898
	  lwz       r3, 0x68(r29)
	  li        r4, 0x1
	  lfs       f1, -0x4DC4(r2)
	  bl        -0x168A8
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x24
	  bl        -0x12071C
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm.   r0,r0,27,24,31
	  bne-      .loc_0x81C
	  lwz       r3, 0x20(r29)
	  bl        -0x86C8
	  lwz       r3, 0x20(r29)
	  mr        r4, r30
	  bl        -0x8320
	  cmpwi     r3, 0x15
	  bne-      .loc_0x81C
	  lwz       r3, 0x84(r29)
	  bl        -0x2D18
	  li        r0, 0x3
	  stw       r0, 0x0(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  b         .loc_0x81C

	.loc_0x4E8:
	  cmpwi     r27, 0x6
	  bne-      .loc_0x504
	  li        r0, 0x7
	  stw       r0, 0x0(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  b         .loc_0x81C

	.loc_0x504:
	  cmpwi     r27, 0x4
	  bne-      .loc_0x81C
	  li        r3, 0x11D
	  bl        -0xF10D8
	  li        r0, 0xC
	  stw       r0, 0x4(r29)
	  li        r0, 0x2
	  stw       r0, 0x0(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  b         .loc_0x81C
	  lfs       f2, 0x10(r29)
	  lfs       f1, -0x4DC0(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x568
	  lfs       f0, -0x4DBC(r2)
	  fmuls     f0, f0, f2
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x554
	  fmr       f0, f1

	.loc_0x554:
	  lwz       r3, 0x80(r29)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  b         .loc_0x81C

	.loc_0x568:
	  li        r0, 0x5
	  stw       r0, 0x0(r29)
	  li        r3, 0x128
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  bl        -0xF1144
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x24
	  bl        -0x121FB4
	  b         .loc_0x81C
	  lwz       r4, 0x80(r29)
	  li        r3, 0x129
	  lfs       f0, -0x4DC0(r2)
	  stfs      f0, 0xC0(r4)
	  stfs      f0, 0xC4(r4)
	  stfs      f0, 0xC8(r4)
	  bl        -0xF1174
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x24
	  bl        -0x11FAD0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5F0
	  lwz       r3, 0x2C(r29)
	  lfs       f1, -0x4DC0(r2)
	  bl        0x5D374
	  li        r0, 0xC
	  stw       r0, 0x4(r29)
	  li        r0, 0x2
	  stw       r0, 0x0(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  b         .loc_0x81C

	.loc_0x5F0:
	  li        r0, 0x6
	  stw       r0, 0x0(r29)
	  li        r4, 0x2
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  lwz       r3, 0x60(r29)
	  lfs       f1, -0x4DC4(r2)
	  bl        -0x16A28
	  lwz       r3, 0x68(r29)
	  li        r4, 0x2
	  lfs       f1, -0x4DC4(r2)
	  bl        -0x16A38
	  lwz       r3, 0x64(r29)
	  li        r4, 0x1
	  lfs       f1, -0x4DC4(r2)
	  bl        -0x16A48
	  lwz       r3, 0x6C(r29)
	  li        r4, 0x1
	  lfs       f1, -0x4DC4(r2)
	  bl        -0x16A58
	  b         .loc_0x81C
	  lfs       f1, 0x10(r29)
	  lfs       f0, -0x4DC0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x81C
	  li        r0, 0xE
	  stw       r0, 0x4(r29)
	  li        r0, 0x2
	  li        r4, 0x2
	  stw       r0, 0x0(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  lwz       r3, 0x64(r29)
	  lfs       f1, -0x4DC4(r2)
	  bl        -0x16A94
	  lwz       r3, 0x6C(r29)
	  li        r4, 0x2
	  lfs       f1, -0x4DC4(r2)
	  bl        -0x16AA4
	  b         .loc_0x81C
	  lfs       f1, 0x10(r29)
	  lfs       f0, -0x4DC4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x6C4
	  lwz       r3, 0x78(r29)
	  li        r0, 0x8
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  stw       r0, 0x0(r29)
	  stfs      f0, 0x10(r29)
	  b         .loc_0x81C

	.loc_0x6C4:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x4DC0(r2)
	  lwz       r3, 0x78(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  b         .loc_0x81C
	  lfs       f1, 0x10(r29)
	  lfs       f0, -0x4DC4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x71C
	  li        r0, 0x9
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x7C(r29)
	  lfs       f0, -0x4DC0(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x1C(r29)
	  bl        0x5F8
	  b         .loc_0x81C

	.loc_0x71C:
	  fdivs     f0, f1, f0
	  lwz       r3, 0x7C(r29)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  b         .loc_0x81C
	  cmpwi     r28, 0x5
	  bne-      .loc_0x758
	  li        r0, 0xD
	  stw       r0, 0x4(r29)
	  li        r0, 0xA
	  stw       r0, 0x0(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  b         .loc_0x81C

	.loc_0x758:
	  cmpwi     r28, 0x6
	  bne-      .loc_0x77C
	  li        r0, 0xF
	  stw       r0, 0x4(r29)
	  li        r0, 0xA
	  stw       r0, 0x0(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  b         .loc_0x81C

	.loc_0x77C:
	  cmpwi     r28, 0x4
	  bne-      .loc_0x81C
	  li        r3, 0x11D
	  bl        -0xF1350
	  li        r0, 0x1
	  stw       r0, 0x4(r29)
	  li        r0, 0xA
	  stw       r0, 0x0(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)
	  b         .loc_0x81C
	  lfs       f1, 0x10(r29)
	  lfs       f0, -0x4DC4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x7DC
	  lwz       r3, 0x7C(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r0, 0x4(r29)
	  stw       r0, 0x0(r29)
	  stfs      f0, 0x10(r29)
	  b         .loc_0x81C

	.loc_0x7DC:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x4DC0(r2)
	  lwz       r3, 0x7C(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  b         .loc_0x81C
	  rlwinm.   r0,r31,0,24,31
	  bne-      .loc_0x81C
	  li        r0, 0xC
	  stw       r0, 0x4(r29)
	  li        r0, 0x2
	  stw       r0, 0x0(r29)
	  lfs       f0, -0x4DC8(r2)
	  stfs      f0, 0x10(r29)

	.loc_0x81C:
	  lwz       r3, 0x0(r29)

	.loc_0x820:
	  lmw       r27, 0xBC(r1)
	  lwz       r0, 0xD4(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80196770
 * Size:	0000F4
 */
void zen::ogSaveMgr::draw(Graphics& gfx)
{
	if (mStatus == -1) {
		return;
	}

	P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	graf.setPort();

	if (_30) {
		_24->draw(0, 0, &graf);
		_84->draw(gfx);
	} else {
		mScreen->draw(0, 0, &graf);
		_0C->draw(0, 0, &graf);
		mMemCheckMgr->draw(gfx);
		mSaveFail->draw(gfx);
	}
}
