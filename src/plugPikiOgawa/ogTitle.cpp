#include "zen/ogTitle.h"
#include "zen/DrawMenu.h"
#include "gameflow.h"
#include "zen/ZenController.h"
#include "zen/ogSub.h"
#include "SoundID.h"
#include "sysNew.h"
#include "P2D/TextBox.h"
#include "SoundMgr.h"
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
DEFINE_PRINT("OgTitleSection")

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void zen::ogScrTitleMgr::getGamePrefs()
{
	mBgmVol = gameflow.mGamePrefs.getBgmVol();
	mSfxVol = gameflow.mGamePrefs.getSfxVol();

	_9C = gameflow.mGamePrefs.getStereoMode();
	_A2 = gameflow.mGamePrefs.getVibeMode();
	_A3 = gameflow.mGamePrefs.isChallengeOpen();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void zen::ogScrTitleMgr::setGamePrefs()
{
	gameflow.mGamePrefs.setBgmVol(mBgmVol);
	gameflow.mGamePrefs.setSfxVol(mSfxVol);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80181090
 * Size:	0004A8
 */
zen::ogScrTitleMgr::ogScrTitleMgr()
{
	mMenu1   = new DrawMenu("screen/blo/m_select.blo", false, false);
	mMenu2   = new DrawMenu("screen/blo/m_selec2.blo", false, false);
	mUseMenu = mMenu1;

	mOptionsMenu     = new DrawMenu("screen/blo/option.blo", false, false);
	mSoundSelectMenu = new DrawMenu("screen/blo/s_select.blo", false, false);
	mVSelectMenu     = new DrawMenu("screen/blo/v_select.blo", false, false);
	mMsSelectMenu    = new DrawMenu("screen/blo/ms_selec.blo", false, false);

	mInput = new ZenController(nullptr);
	mInput->setRepeatTime(0.2f);

	static_cast<P2DPicture*>(mMenu1->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mMenu2->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mOptionsMenu->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mSoundSelectMenu->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mVSelectMenu->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mMsSelectMenu->getScreenPtr()->search('back', true))->setAlpha(0);

	mSoundSelectScreen = mSoundSelectMenu->getScreenPtr();
	_30                = static_cast<P2DPicture*>(mSoundSelectScreen->search('on21', true));
	_34                = static_cast<P2DPicture*>(mSoundSelectScreen->search('on22', true));
	_38                = static_cast<P2DTextBox*>(mSoundSelectScreen->search('on_c', true));
	_3C                = static_cast<P2DTextBox*>(mSoundSelectScreen->search('offc', true));

	mAlphaMgr = new setTenmetuAlpha(_30, 0.5f, 0.0f, 0, 255);

	char path[12];
	for (int i = 0; i < 10; i++) {
		sprintf(path, "on%02d", i + 1);
		u32 test        = RGBA_TO_U32(path[0], path[1], path[2], path[3]);
		mBgmVolPanes[i] = (P2DPicture*)mSoundSelectScreen->search(test, true);
	}
	for (int i = 0; i < 10; i++) {
		sprintf(path, "on%02d", i + 11);
		u32 test        = RGBA_TO_U32(path[0], path[1], path[2], path[3]);
		mSfxVolPanes[i] = (P2DPicture*)mSoundSelectScreen->search(test, true);
	}

	mStatus          = Status_Null;
	_04              = mStatus;
	mCurentSelection = 0;
	mCurrentMenu     = 0;
	getGamePrefs();
	_A4           = 0;
	_A6           = 0;
	mNoInputTimer = 0.0f;
	_9A           = 3;

	mMsSelectMenu->setCancelSE(SYSSE_DECIDE1);
	mVSelectMenu->setCancelSE(SYSSE_DECIDE1);
	mSoundSelectMenu->setCancelSE(SYSSE_DECIDE1);

	mOptionsMenu->setMenuItemActiveSw(1, false);
	StereoOnOff(false);
	DispBarBGM(false);
	DispBarSE(false);
}

/*
 * --INFO--
 * Address:	80181538
 * Size:	0000E4
 */
void zen::ogScrTitleMgr::start(bool hasChallenge)
{
	getGamePrefs();
	if (hasChallenge) {
		mUseMenu = mMenu2;
	} else {
		mUseMenu = mMenu1;
	}
	SeSystem::playSysSe(YMENU_SELECT2);
	mUseMenu->start(-1);
	mCurrentMenu  = 0;
	_A4           = 0;
	_A6           = 0;
	mNoInputTimer = 0.0f;
	_04           = Status_3;
	mStatus       = Status_1;
	_9A           = 3;
}

/*
 * --INFO--
 * Address:	8018161C
 * Size:	0009F8
 */
zen::ogScrTitleMgr::TitleStatus zen::ogScrTitleMgr::update(Controller* input)
{
	int stat = mStatus;
	if (stat == -1) {
		return mStatus;
	}

	if (stat == 1) {
		_9A--;
		if (_9A <= 0) {
			mStatus = Status_0;
		}
		return mStatus;
	}

	if (stat == 2) {
		mStatus = _04;
		return mStatus;
	}

	if (stat >= 3) {
		mStatus = Status_Null;
		return mStatus;
	}

	mInput->setContPtr(input);
	mInput->update();
	if (input->keyDown(KBBTN_ANY)) {
		mNoInputTimer = 0.0f;
	}

	mNoInputTimer += gsys->getFrameTime();
	if (mNoInputTimer >= 60.0f) {
		input->updateCont(KBBTN_B);
		mMenu1->update(input);
	}

	int flag;
	switch (mCurrentMenu) {
	case 0:
		mUseMenu->update(input);
		flag             = mUseMenu->getStatusFlag();
		mCurentSelection = mUseMenu->getSelectMenu();
		if (flag == 0) {
			switch (mCurentSelection) {
			case 0:
				_04     = Status_4;
				mStatus = Status_2;
				return mStatus;
			case 1:
				mCurrentMenu = 1;
				mOptionsMenu->start(0);
				break;
			case 2:
				_04     = Status_6;
				mStatus = Status_2;
				return mStatus;
			default:
				if (mUseMenu->checkSelectMenuCancel()) {
					_04     = Status_3;
					mStatus = Status_2;
					return mStatus;
				}
			}
		}
		break;
	case 1:
		mOptionsMenu->update(input);
		flag             = mOptionsMenu->getStatusFlag();
		mCurentSelection = mOptionsMenu->getSelectMenu();
		if (flag == 0) {
			switch (mCurentSelection) {
			case 0:
				mCurrentMenu = 2;
				mSoundSelectMenu->start(0);
			case 1:
				mCurrentMenu = 4;
				if (_A3) {
					mMsSelectMenu->start(1);
				} else {
					mMsSelectMenu->start(0);
				}
				break;
			case 2:
				mCurrentMenu = 3;
				if (_A2) {
					mVSelectMenu->start(1);
				} else {
					mVSelectMenu->start(0);
				}
				break;
			case 3:
				_04     = Status_7;
				mStatus = Status_2;
				return mStatus;
			default:
				if (mUseMenu->checkSelectMenuCancel()) {
					getGamePrefs();
					setGamePrefs();
					mOptionsMenu->setCancelSelectMenuNo(-1);
					mUseMenu->start(-1);
					mCurrentMenu = 0;
				}
			}
		}
		break;
	case 2:
		mSoundSelectMenu->update(input);
		flag             = mOptionsMenu->getStatusFlag();
		mCurentSelection = mOptionsMenu->getSelectMenu();
		if (mInput->mController->keyDown(0x400000)) { }
		break;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stmw      r23, 0xA4(r1)
	  mr        r28, r3
	  addi      r29, r4, 0
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x28
	  b         .loc_0x9E4

	.loc_0x28:
	  cmpwi     r3, 0x1
	  bne-      .loc_0x58
	  lha       r3, 0x9A(r28)
	  subi      r0, r3, 0x1
	  sth       r0, 0x9A(r28)
	  lha       r0, 0x9A(r28)
	  cmpwi     r0, 0
	  bgt-      .loc_0x50
	  li        r0, 0
	  stw       r0, 0x0(r28)

	.loc_0x50:
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x58:
	  cmpwi     r3, 0x2
	  bne-      .loc_0x70
	  lwz       r0, 0x4(r28)
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x70:
	  cmpwi     r3, 0x3
	  blt-      .loc_0x88
	  li        r0, -0x1
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x88:
	  lwz       r3, 0x8(r28)
	  stw       r29, 0x0(r3)
	  lwz       r3, 0x8(r28)
	  bl        0x3ECF4
	  lwz       r0, 0x20(r29)
	  rlwinm.   r0,r0,0,0,31
	  beq-      .loc_0xAC
	  lfs       f0, -0x50A0(r2)
	  stfs      f0, 0x90(r28)

	.loc_0xAC:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x90(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x90(r28)
	  lfs       f1, 0x90(r28)
	  lfs       f0, -0x509C(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xEC
	  addi      r3, r29, 0
	  li        r4, 0x2000
	  bl        -0x140D24
	  lwz       r3, 0x14(r28)
	  mr        r4, r29
	  bl        0x42DD0

	.loc_0xEC:
	  lha       r0, 0x98(r28)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x3F4
	  bge-      .loc_0x10C
	  cmpwi     r0, 0
	  beq-      .loc_0x11C
	  bge-      .loc_0x1F4
	  b         .loc_0x9E0

	.loc_0x10C:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x900
	  bge-      .loc_0x9E0
	  b         .loc_0x7E4

	.loc_0x11C:
	  lwz       r3, 0x14(r28)
	  mr        r4, r29
	  bl        0x42D94
	  lwz       r4, 0x14(r28)
	  lwz       r0, 0x1D0(r4)
	  lwz       r3, 0x100(r4)
	  cmpwi     r0, 0
	  blt-      .loc_0x144
	  lwz       r0, 0x110(r4)
	  b         .loc_0x15C

	.loc_0x144:
	  lbz       r0, 0x1D4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x158
	  li        r0, -0x1
	  b         .loc_0x15C

	.loc_0x158:
	  lwz       r0, 0x110(r4)

	.loc_0x15C:
	  cmpwi     r3, 0
	  stw       r0, 0x94(r28)
	  bne-      .loc_0x9E0
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x18C
	  li        r0, 0x4
	  stw       r0, 0x4(r28)
	  li        r0, 0x2
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x18C:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1AC
	  li        r0, 0x1
	  sth       r0, 0x98(r28)
	  li        r4, 0
	  lwz       r3, 0x18(r28)
	  bl        0x424F8
	  b         .loc_0x9E0

	.loc_0x1AC:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x1CC
	  li        r0, 0x6
	  stw       r0, 0x4(r28)
	  li        r0, 0x2
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x1CC:
	  lwz       r3, 0x14(r28)
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x9E0
	  li        r0, 0x3
	  stw       r0, 0x4(r28)
	  li        r0, 0x2
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x1F4:
	  lwz       r3, 0x18(r28)
	  mr        r4, r29
	  bl        0x42CBC
	  lwz       r4, 0x18(r28)
	  lwz       r0, 0x1D0(r4)
	  lwz       r3, 0x100(r4)
	  cmpwi     r0, 0
	  blt-      .loc_0x21C
	  lwz       r0, 0x110(r4)
	  b         .loc_0x234

	.loc_0x21C:
	  lbz       r0, 0x1D4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x230
	  li        r0, -0x1
	  b         .loc_0x234

	.loc_0x230:
	  lwz       r0, 0x110(r4)

	.loc_0x234:
	  cmpwi     r3, 0
	  stw       r0, 0x94(r28)
	  bne-      .loc_0x9E0
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x264
	  li        r0, 0x2
	  sth       r0, 0x98(r28)
	  li        r4, 0
	  lwz       r3, 0x1C(r28)
	  bl        0x42440
	  b         .loc_0x9E0

	.loc_0x264:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x2A0
	  li        r0, 0x4
	  sth       r0, 0x98(r28)
	  lbz       r0, 0xA3(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x290
	  lwz       r3, 0x24(r28)
	  li        r4, 0x1
	  bl        0x42414
	  b         .loc_0x9E0

	.loc_0x290:
	  lwz       r3, 0x24(r28)
	  li        r4, 0
	  bl        0x42404
	  b         .loc_0x9E0

	.loc_0x2A0:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x2DC
	  li        r0, 0x3
	  sth       r0, 0x98(r28)
	  lbz       r0, 0xA2(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x2CC
	  lwz       r3, 0x20(r28)
	  li        r4, 0
	  bl        0x423D8
	  b         .loc_0x9E0

	.loc_0x2CC:
	  lwz       r3, 0x20(r28)
	  li        r4, 0x1
	  bl        0x423C8
	  b         .loc_0x9E0

	.loc_0x2DC:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x2FC
	  li        r0, 0x7
	  stw       r0, 0x4(r28)
	  li        r0, 0x2
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x2FC:
	  lwz       r3, 0x18(r28)
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x9E0
	  lis       r3, 0x803A
	  subi      r27, r3, 0x2848
	  lwz       r7, 0xAC(r27)
	  addi      r31, r27, 0x24
	  lbz       r30, 0xB0(r27)
	  addi      r3, r31, 0
	  rlwinm    r0,r7,0,31,31
	  neg       r6, r0
	  lbz       r29, 0xB1(r27)
	  subic     r5, r6, 0x1
	  rlwinm    r4,r7,0,30,30
	  rlwinm    r0,r7,0,29,29
	  subfe     r25, r5, r6
	  neg       r5, r4
	  subic     r4, r5, 0x1
	  subfe     r24, r4, r5
	  neg       r4, r0
	  subic     r0, r4, 0x1
	  subfe     r23, r0, r4
	  li        r4, 0x1
	  bl        -0x10DA88
	  cmpwi     r3, 0
	  bne-      .loc_0x37C
	  lwz       r0, 0x5C(r27)
	  cmpwi     r0, 0
	  blt-      .loc_0x37C
	  mr        r3, r31
	  bl        -0x10D6A4

	.loc_0x37C:
	  lis       r3, 0x803A
	  subi      r27, r3, 0x2848
	  addi      r26, r27, 0x94
	  addi      r3, r26, 0
	  addi      r4, r25, 0
	  bl        -0x12DBF4
	  addi      r3, r26, 0
	  addi      r4, r24, 0
	  bl        -0x12DC9C
	  addi      r3, r26, 0
	  addi      r4, r23, 0
	  bl        -0x12DB54
	  addi      r3, r26, 0
	  addi      r4, r30, 0
	  bl        -0x12DD34
	  addi      r3, r26, 0
	  addi      r4, r29, 0
	  bl        -0x12DD00
	  li        r29, 0
	  stb       r29, 0xA8(r27)
	  mr        r3, r31
	  bl        -0x10D658
	  lwz       r3, 0x18(r28)
	  li        r4, -0x1
	  bl        0x42F40
	  lwz       r3, 0x14(r28)
	  li        r4, -0x1
	  bl        0x422B4
	  sth       r29, 0x98(r28)
	  b         .loc_0x9E0

	.loc_0x3F4:
	  lwz       r3, 0x1C(r28)
	  mr        r4, r29
	  bl        0x42ABC
	  lwz       r3, 0x1C(r28)
	  lwz       r0, 0x1D0(r3)
	  lwz       r31, 0x100(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x41C
	  lwz       r0, 0x110(r3)
	  b         .loc_0x434

	.loc_0x41C:
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x430
	  li        r0, -0x1
	  b         .loc_0x434

	.loc_0x430:
	  lwz       r0, 0x110(r3)

	.loc_0x434:
	  stw       r0, 0x94(r28)
	  lwz       r3, 0x8(r28)
	  lwz       r0, 0x4(r3)
	  rlwinm.   r0,r0,0,9,9
	  beq-      .loc_0x5BC
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x4E0
	  bge-      .loc_0x464
	  cmpwi     r0, 0
	  bge-      .loc_0x470
	  b         .loc_0x5BC

	.loc_0x464:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x5BC
	  b         .loc_0x550

	.loc_0x470:
	  lbz       r0, 0x9C(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x5BC
	  li        r0, 0x1
	  stb       r0, 0x9C(r28)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x9E(r28)
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DE1C
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DDEC
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12DDB8
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12DD28
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12DC7C
	  li        r3, 0x133
	  bl        -0x16AF54
	  b         .loc_0x5BC

	.loc_0x4E0:
	  lha       r3, 0x9E(r28)
	  cmpwi     r3, 0
	  ble-      .loc_0x5BC
	  subi      r0, r3, 0x1
	  sth       r0, 0x9E(r28)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x9E(r28)
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DE8C
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DE5C
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12DE28
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12DD98
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12DCEC
	  li        r3, 0x133
	  bl        -0x16AFC4
	  b         .loc_0x5BC

	.loc_0x550:
	  lha       r3, 0xA0(r28)
	  cmpwi     r3, 0
	  ble-      .loc_0x5BC
	  subi      r0, r3, 0x1
	  sth       r0, 0xA0(r28)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x9E(r28)
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DEFC
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DECC
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12DE98
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12DE08
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12DD5C
	  li        r3, 0x133
	  bl        -0x16B034

	.loc_0x5BC:
	  lwz       r3, 0x8(r28)
	  lwz       r0, 0x4(r3)
	  rlwinm.   r0,r0,0,11,11
	  beq-      .loc_0x740
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x664
	  bge-      .loc_0x5E8
	  cmpwi     r0, 0
	  bge-      .loc_0x5F4
	  b         .loc_0x740

	.loc_0x5E8:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x740
	  b         .loc_0x6D4

	.loc_0x5F4:
	  lbz       r0, 0x9C(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x740
	  li        r0, 0
	  stb       r0, 0x9C(r28)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x9E(r28)
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DFA0
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DF70
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12DF3C
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12DEAC
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12DE00
	  li        r3, 0x133
	  bl        -0x16B0D8
	  b         .loc_0x740

	.loc_0x664:
	  lha       r3, 0x9E(r28)
	  cmpwi     r3, 0xA
	  bge-      .loc_0x740
	  addi      r0, r3, 0x1
	  sth       r0, 0x9E(r28)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x9E(r28)
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E010
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DFE0
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12DFAC
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12DF1C
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12DE70
	  li        r3, 0x133
	  bl        -0x16B148
	  b         .loc_0x740

	.loc_0x6D4:
	  lha       r3, 0xA0(r28)
	  cmpwi     r3, 0xA
	  bge-      .loc_0x740
	  addi      r0, r3, 0x1
	  sth       r0, 0xA0(r28)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x9E(r28)
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E080
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E050
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12E01C
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12DF8C
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12DEE0
	  li        r3, 0x133
	  bl        -0x16B1B8

	.loc_0x740:
	  lwz       r0, 0x94(r28)
	  addi      r3, r28, 0
	  neg       r0, r0
	  cntlzw    r0, r0
	  rlwinm    r4,r0,27,5,31
	  bl        0x33C
	  lwz       r0, 0x94(r28)
	  addi      r3, r28, 0
	  subfic    r0, r0, 0x1
	  cntlzw    r0, r0
	  rlwinm    r4,r0,27,5,31
	  bl        0x3E8
	  lwz       r0, 0x94(r28)
	  addi      r3, r28, 0
	  subfic    r0, r0, 0x2
	  cntlzw    r0, r0
	  rlwinm    r4,r0,27,5,31
	  bl        0x4A4
	  cmpwi     r31, 0
	  bne-      .loc_0x9E0
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0
	  blt-      .loc_0x7B4
	  lwz       r3, 0x18(r28)
	  li        r4, -0x1
	  bl        0x41EF8
	  li        r0, 0x1
	  sth       r0, 0x98(r28)
	  b         .loc_0x9E0

	.loc_0x7B4:
	  lwz       r3, 0x1C(r28)
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x9E0
	  li        r4, -0x1
	  bl        0x42B54
	  lwz       r3, 0x18(r28)
	  li        r4, -0x1
	  bl        0x41EC8
	  li        r0, 0x1
	  sth       r0, 0x98(r28)
	  b         .loc_0x9E0

	.loc_0x7E4:
	  lwz       r3, 0x20(r28)
	  mr        r4, r29
	  bl        0x426CC
	  lwz       r3, 0x20(r28)
	  lwz       r0, 0x1D0(r3)
	  lwz       r27, 0x100(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x80C
	  lwz       r0, 0x110(r3)
	  b         .loc_0x824

	.loc_0x80C:
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x820
	  li        r0, -0x1
	  b         .loc_0x824

	.loc_0x820:
	  lwz       r0, 0x110(r3)

	.loc_0x824:
	  stw       r0, 0x94(r28)
	  lwz       r0, 0x28(r29)
	  andis.    r0, r0, 0x28
	  beq-      .loc_0x8A4
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x84C
	  li        r0, 0x1
	  stb       r0, 0xA2(r28)
	  b         .loc_0x854

	.loc_0x84C:
	  li        r0, 0
	  stb       r0, 0xA2(r28)

	.loc_0x854:
	  lis       r3, 0x803A
	  lha       r0, 0x9E(r28)
	  subi      r3, r3, 0x2848
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E1EC
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E1BC
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12E188
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12E0F8
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12E04C

	.loc_0x8A4:
	  cmpwi     r27, 0
	  bne-      .loc_0x9E0
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0
	  blt-      .loc_0x8D0
	  lwz       r3, 0x18(r28)
	  li        r4, -0x1
	  bl        0x41DDC
	  li        r0, 0x1
	  sth       r0, 0x98(r28)
	  b         .loc_0x9E0

	.loc_0x8D0:
	  lwz       r3, 0x20(r28)
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x9E0
	  li        r4, -0x1
	  bl        0x42A38
	  lwz       r3, 0x18(r28)
	  li        r4, -0x1
	  bl        0x41DAC
	  li        r0, 0x1
	  sth       r0, 0x98(r28)
	  b         .loc_0x9E0

	.loc_0x900:
	  lwz       r3, 0x24(r28)
	  mr        r4, r29
	  bl        0x425B0
	  lwz       r3, 0x24(r28)
	  lwz       r0, 0x1D0(r3)
	  lwz       r27, 0x100(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x928
	  lwz       r0, 0x110(r3)
	  b         .loc_0x940

	.loc_0x928:
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x93C
	  li        r0, -0x1
	  b         .loc_0x940

	.loc_0x93C:
	  lwz       r0, 0x110(r3)

	.loc_0x940:
	  stw       r0, 0x94(r28)
	  lwz       r0, 0x28(r29)
	  andis.    r0, r0, 0x28
	  beq-      .loc_0x9C0
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x968
	  li        r0, 0
	  stb       r0, 0xA3(r28)
	  b         .loc_0x970

	.loc_0x968:
	  li        r0, 0x1
	  stb       r0, 0xA3(r28)

	.loc_0x970:
	  lis       r3, 0x803A
	  lha       r0, 0x9E(r28)
	  subi      r3, r3, 0x2848
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E308
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E2D8
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12E2A4
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12E214
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12E168

	.loc_0x9C0:
	  cmpwi     r27, 0
	  bne-      .loc_0x9E0
	  li        r0, 0x3
	  stw       r0, 0x4(r28)
	  li        r0, 0x2
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x9E0:
	  lwz       r3, 0x0(r28)

	.loc_0x9E4:
	  lmw       r23, 0xA4(r1)
	  lwz       r0, 0xCC(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80182014
 * Size:	000098
 */
void zen::ogScrTitleMgr::draw(Graphics& gfx)
{
	if (mStatus != Status_Null && mStatus != Status_1) {
		switch (mCurrentMenu) {
		case 0:
			mUseMenu->draw(gfx);
			break;
		case 1:
			mOptionsMenu->draw(gfx);
			break;
		case 2:
			mSoundSelectMenu->draw(gfx);
			break;
		case 3:
			mVSelectMenu->draw(gfx);
			break;
		case 4:
			mMsSelectMenu->draw(gfx);
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	801820AC
 * Size:	0000C4
 */
void zen::ogScrTitleMgr::StereoOnOff(bool set)
{
	if (_9C) {
		setTextColor(_38, _30);
		setTextColor(_3C, _34);
		if (set) {
			mAlphaMgr->update(_30);
		} else {
			_30->setAlpha(255);
		}
	} else {
		setTextColor(_3C, _30);
		setTextColor(_38, _34);
		if (set) {
			mAlphaMgr->update(_34);
		} else {
			_34->setAlpha(255);
		}
	}
}

/*
 * --INFO--
 * Address:	80182170
 * Size:	0000D4
 */
void zen::ogScrTitleMgr::DispBarBGM(bool set)
{
	for (int i = 0; i < 10; i++) {
		if (i < mBgmVol - 1) {
			setTextColor(_38, mBgmVolPanes[i]);
			mBgmVolPanes[i]->setAlpha(255);
		} else if (i == mBgmVol - 1) {
			setTextColor(_38, mBgmVolPanes[i]);
			if (set) {
				mAlphaMgr->update(mBgmVolPanes[i]);
			} else {
				mBgmVolPanes[i]->setAlpha(255);
			}
		} else {
			setTextColor(_3C, mBgmVolPanes[i]);
		}
	}
}

/*
 * --INFO--
 * Address:	80182244
 * Size:	0000D4
 */
void zen::ogScrTitleMgr::DispBarSE(bool set)
{
	for (int i = 0; i < 10; i++) {
		if (i < mSfxVol - 1) {
			setTextColor(_38, mSfxVolPanes[i]);
			mSfxVolPanes[i]->setAlpha(255);
		} else if (i == mSfxVol - 1) {
			setTextColor(_38, mSfxVolPanes[i]);
			if (set) {
				mAlphaMgr->update(mSfxVolPanes[i]);
			} else {
				mSfxVolPanes[i]->setAlpha(255);
			}
		} else {
			setTextColor(_3C, mSfxVolPanes[i]);
		}
	}
}
