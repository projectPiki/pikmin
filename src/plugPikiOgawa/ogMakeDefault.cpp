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
			if (gameflow.mMemoryCard.didSaveFail()) {
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

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x88(r1)
	  mr        r30, r3
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x2C
	  b         .loc_0x33C

	.loc_0x2C:
	  cmpwi     r3, 0x4
	  blt-      .loc_0x44
	  li        r0, -0x1
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x33C

	.loc_0x44:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x50(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x50(r30)
	  lfs       f1, 0x50(r30)
	  lfs       f0, -0x4E08(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x7C
	  lwz       r3, 0x44(r30)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x7C:
	  lfs       f1, 0x50(r30)
	  lfs       f0, -0x4DFC(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xA0
	  lwz       r3, 0x48(r30)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xA0:
	  lfs       f1, 0x50(r30)
	  lfs       f0, -0x4DF8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xC4
	  lwz       r3, 0x4C(r30)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xC4:
	  lwz       r3, 0x8(r30)
	  bl        0x1ECA0
	  lwz       r3, 0xC(r30)
	  bl        0x1EC98
	  lwz       r3, 0x20(r30)
	  bl        -0x14778
	  lwz       r3, 0x24(r30)
	  bl        -0x14780
	  lwz       r3, 0x28(r30)
	  bl        -0x13534
	  lwz       r4, 0x28(r30)
	  lwz       r3, 0x18(r30)
	  lwz       r7, 0x8(r4)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x116(r7)
	  lwz       r12, 0x14(r12)
	  subi      r5, r4, 0x18
	  lha       r0, 0x1A(r7)
	  lha       r6, 0x114(r7)
	  mtlr      r12
	  lha       r4, 0x18(r7)
	  add       r5, r0, r5
	  add       r4, r4, r6
	  blrl
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x198
	  lfs       f2, 0x50(r30)
	  lfs       f1, -0x4E04(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x168
	  lfs       f0, -0x4DF4(r2)
	  lwz       r3, 0x10(r30)
	  fmuls     f0, f0, f2
	  fdivs     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r0, 0x84(r1)
	  subfic    r0, r0, 0xFF
	  stb       r0, 0xF0(r3)
	  b         .loc_0x190

	.loc_0x168:
	  li        r31, 0
	  stw       r31, 0x0(r30)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lfs       f0, -0x4E00(r2)
	  addi      r3, r3, 0x24
	  stfs      f0, 0x50(r30)
	  bl        -0x11EEDC
	  lwz       r3, 0x10(r30)
	  stb       r31, 0xF0(r3)

	.loc_0x190:
	  lwz       r3, 0x0(r30)
	  b         .loc_0x33C

	.loc_0x198:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x1F8
	  lfs       f2, 0x50(r30)
	  lfs       f1, -0x4E04(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x1D4
	  lfs       f0, -0x4DF4(r2)
	  lwz       r3, 0x10(r30)
	  fmuls     f0, f0, f2
	  fdivs     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r0, 0x84(r1)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x1F0

	.loc_0x1D4:
	  lwz       r3, 0x10(r30)
	  li        r0, 0xFF
	  stb       r0, 0xF0(r3)
	  lwz       r0, 0x4(r30)
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x4E00(r2)
	  stfs      f0, 0x50(r30)

	.loc_0x1F0:
	  lwz       r3, 0x0(r30)
	  b         .loc_0x33C

	.loc_0x1F8:
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2F0
	  bge-      .loc_0x338
	  cmpwi     r0, 0
	  bge-      .loc_0x210
	  b         .loc_0x338

	.loc_0x210:
	  lfs       f1, 0x50(r30)
	  lfs       f0, -0x4DFC(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x338
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r31, r3, 0x24
	  addi      r3, r31, 0
	  bl        -0x1205BC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x338
	  mr        r3, r31
	  bl        -0x11D600
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm.   r0,r0,27,24,31
	  beq-      .loc_0x28C
	  lwz       r5, 0x28(r30)
	  li        r4, 0
	  lwz       r3, 0x8(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r5)
	  lwz       r0, 0x30(r30)
	  stw       r0, 0x28(r30)
	  lwz       r3, 0x28(r30)
	  bl        -0x13C44
	  li        r0, 0x4
	  stw       r0, 0x4(r30)
	  b         .loc_0x2C0

	.loc_0x28C:
	  lwz       r5, 0x28(r30)
	  li        r4, 0
	  lwz       r3, 0x8(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r5)
	  lwz       r0, 0x38(r30)
	  stw       r0, 0x28(r30)
	  lwz       r3, 0x28(r30)
	  bl        -0x13C7C
	  li        r0, 0x5
	  stw       r0, 0x4(r30)

	.loc_0x2C0:
	  lwz       r4, 0x3C(r30)
	  li        r5, 0
	  li        r0, 0x1
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x4E00(r2)
	  stfs      f0, 0x50(r30)
	  lwz       r3, 0x24(r30)
	  bl        -0x14A54
	  b         .loc_0x338

	.loc_0x2F0:
	  mr        r3, r30
	  bl        0x108
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x338
	  lwz       r3, 0x1C(r30)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x28(r31)
	  rlwinm.   r0,r0,0,19,19
	  beq-      .loc_0x338
	  li        r3, 0x111
	  bl        -0xEED98
	  li        r0, 0x3
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x4E00(r2)
	  stfs      f0, 0x50(r30)

	.loc_0x338:
	  lwz       r3, 0x0(r30)

	.loc_0x33C:
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
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
