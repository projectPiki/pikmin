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
	u32 badCompiler[14];
	
	mMode = 0;
	mBlackScreen = new P2DScreen();
	mBlackScreen->set("screen/blo/black.blo", false, false, true);
	mBlackPane = mBlackScreen->search('blck', true);

	mDrawMenu1      = new DrawMenu("screen/blo/pause.blo", false, false);
	_14 = static_cast<P2DScreen*>(&mDrawMenu1->mPane);
	P2DTextBox* textBox4 = static_cast<P2DTextBox*>(_14->search('yame', true));
	mTextBox4 = textBox4;
	P2DTextBox* textBox5 = static_cast<P2DTextBox*>(_14->search('he02', true));
	mTextBox5 = textBox5;
	P2DTextBox* textBox6 = static_cast<P2DTextBox*>(_14->search('hm02', true));
	mTextBox6 = textBox6;

	_3c = mTextBox4->getText();
	_40 = mTextBox5->getText();

	mTextBox4->setFlag(0, 7, 1);

	mDrawMenu2      = new DrawMenu("screen/blo/pause_ok.blo", false, false);
	_18 = static_cast<P2DScreen*>(&mDrawMenu2->mPane);
	P2DTextBox* textBox1 = static_cast<P2DTextBox*>(_18->search('yame', true));
	mTextBox1 = textBox1;
	P2DTextBox* textBox2 = static_cast<P2DTextBox*>(_18->search('titl', true));
	mTextBox2 = textBox2;
	P2DTextBox* textBox3 = static_cast<P2DTextBox*>(_18->search('even', true));
	mTextBox3 = textBox3;

	mTextBox1->setFlag(0, 7, 1);
	mTextBox2->setFlag(0, 7, 1);
	mTextBox3->setFlag(0, 7, 1);

	mState = PAUSE_NULL;
	_00 = 0;

	mBackPane1 = _14->search('back', true);

	mBackPane1->setFlag(0, 7, 1);

	mBackPane2 = _18->search('back', true);

	mBackPane2->setFlag(0, 7, 1);


	
	

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  stw       r30, 0x70(r1)
	  addi      r30, r3, 0
	  lis       r3, 0x802D
	  stw       r29, 0x6C(r1)
	  addi      r31, r3, 0x30C0
	  li        r29, 0
	  stw       r28, 0x68(r1)
	  li        r3, 0xF8
	  stb       r29, 0x44(r30)
	  bl        -0x13B348
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x94
	  addi      r3, r1, 0x60
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x312B8
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x60
	  addi      r3, r28, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x2E63C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r28)
	  stb       r29, 0xEC(r28)
	  stw       r29, 0xF0(r28)
	  stw       r29, 0xF4(r28)

	.loc_0x94:
	  stw       r28, 0x1C(r30)
	  addi      r4, r31, 0x1C
	  li        r5, 0
	  lwz       r3, 0x1C(r30)
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x3083C
	  lwz       r3, 0x1C(r30)
	  lis       r4, 0x626C
	  addi      r4, r4, 0x636B
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x20(r30)
	  li        r0, 0
	  li        r3, 0x1D8
	  lwz       r4, 0x20(r30)
	  stb       r0, 0xF0(r4)
	  bl        -0x13B3F8
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x104
	  addi      r4, r31, 0x34
	  li        r5, 0
	  li        r6, 0
	  bl        0x40CE4

	.loc_0x104:
	  stw       r28, 0xC(r30)
	  lis       r3, 0x7961
	  addi      r4, r3, 0x6D65
	  lwz       r3, 0xC(r30)
	  li        r5, 0x1
	  addi      r0, r3, 0x4
	  stw       r0, 0x14(r30)
	  lwz       r3, 0x14(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x30(r30)
	  lis       r3, 0x6865
	  addi      r4, r3, 0x3032
	  lwz       r3, 0x14(r30)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x34(r30)
	  lis       r3, 0x686D
	  addi      r4, r3, 0x3032
	  lwz       r3, 0x14(r30)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x38(r30)
	  li        r5, 0
	  li        r3, 0x1D8
	  lwz       r4, 0x30(r30)
	  lwz       r0, 0x10C(r4)
	  stw       r0, 0x3C(r30)
	  lwz       r4, 0x34(r30)
	  lwz       r0, 0x10C(r4)
	  stw       r0, 0x40(r30)
	  lwz       r4, 0x30(r30)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  bl        -0x13B4C4
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x1D0
	  addi      r4, r31, 0x4C
	  li        r5, 0
	  li        r6, 0
	  bl        0x40C18

	.loc_0x1D0:
	  stw       r28, 0x10(r30)
	  lis       r3, 0x7961
	  addi      r4, r3, 0x6D65
	  lwz       r3, 0x10(r30)
	  li        r5, 0x1
	  addi      r0, r3, 0x4
	  stw       r0, 0x18(r30)
	  lwz       r3, 0x18(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x24(r30)
	  lis       r3, 0x7469
	  addi      r4, r3, 0x746C
	  lwz       r3, 0x18(r30)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x28(r30)
	  lis       r3, 0x6576
	  addi      r4, r3, 0x656E
	  lwz       r3, 0x18(r30)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x2C(r30)
	  lis       r31, 0x6261
	  li        r29, 0
	  lwz       r6, 0x24(r30)
	  li        r0, -0x1
	  addi      r4, r31, 0x636B
	  lbz       r3, 0xC(r6)
	  rlwimi    r3,r29,7,24,24
	  li        r5, 0x1
	  stb       r3, 0xC(r6)
	  lwz       r6, 0x28(r30)
	  lbz       r3, 0xC(r6)
	  rlwimi    r3,r29,7,24,24
	  stb       r3, 0xC(r6)
	  lwz       r6, 0x2C(r30)
	  lbz       r3, 0xC(r6)
	  rlwimi    r3,r29,7,24,24
	  stb       r3, 0xC(r6)
	  stw       r0, 0x4(r30)
	  stb       r29, 0x0(r30)
	  lwz       r3, 0x14(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x48(r30)
	  addi      r4, r31, 0x636B
	  li        r5, 0x1
	  lwz       r3, 0x48(r30)
	  stb       r29, 0xF0(r3)
	  lwz       r3, 0x48(r30)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x4C(r30)
	  mr        r3, r30
	  lwz       r4, 0x4C(r30)
	  stb       r29, 0xF0(r4)
	  lwz       r4, 0x4C(r30)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  lwz       r28, 0x68(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018263C
 * Size:	00008C
 */
void zen::ogScrPauseMgr::start(bool p1)
{
	u32 badCompiler[8];

	mMode = p1;

	if (mMode != 0){
		mTextBox5->mText = _3c;
		mTextBox6->mText = _3c;
	} else {
		mTextBox5->mText = _40;
		mTextBox6->mText = _40;
	}

	mDrawMenu1->start(-1);
	mState = PAUSE_Unk1;
	mFrameTimer = 0.0f;
	_00 = 1;
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

	


	int day = playerState->getCurrDay();

	if (day != 0){
		day = playerState->getTotalDays();
		int day2 = playerState->getCurrDay();
		if (day2 != --day ){
			mDrawMenu1->setMenuItemActiveSw(1, true);
		}

	}

	mDrawMenu1->setMenuItemActiveSw(1, false);
	mBlackScreen->update();
	mDrawMenu1->update(controller);
	mDrawMenu2->update(controller);
	mFrameTimer += gsys->getFrameTime();

	switch (mState) {
	case PAUSE_Unk2:
		if (0.5f < mFrameTimer) {
			
			mState = mState2;
			_00 = 0;
		} else {

		}
		break;
	case PAUSE_Unk1:
		
		if (mDrawMenu1->_1d0 < 0){
			if (mDrawMenu1->_1d4 == 0){

			} else {
				 
			}
		}


		if (mDrawMenu1->_100 == 0){
			if (mDrawMenu1->_110 == 0){
				mState2 = PAUSE_Unk5;
				mState = PAUSE_Unk2;
				mFrameTimer = 0.0f;

			}
			if (mDrawMenu1->_110 == 1){
				mState = PAUSE_Unk3;
				mDrawMenu2->start(0);
				mTextBox1->setFlag(0, 7, 1);
				mTextBox2->setFlag(0, 7, 1);
				mTextBox3->setFlag(0, 7, 1);

			}
			if (mDrawMenu1->_110 == 2){
				mState = PAUSE_Unk4;
				mDrawMenu2->start(0);
				mTextBox1->setFlag(0, 7, 1);
				mTextBox2->setFlag(0, 7, 1);
				mTextBox3->setFlag(0, 7, 1);
				if (mMode == 0){
					mTextBox2->setFlag(0, 7, 1);
				}else {
					mTextBox1->setFlag(0, 7, 1);
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stw       r31, 0xFC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xF8(r1)
	  mr        r30, r3
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x98
	  lfs       f1, -0x508C(r2)
	  addi      r3, r1, 0x10
	  lfs       f2, -0x5088(r2)
	  li        r4, 0
	  lfs       f3, -0x5084(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x2D6C0
	  addi      r3, r1, 0x10
	  bl        0x2D7C8
	  lwz       r3, 0x1C(r30)
	  addi      r6, r1, 0x10
	  li        r4, 0
	  li        r5, 0
	  bl        0x303E8
	  lwz       r3, 0xC(r30)
	  mr        r4, r31
	  bl        0x41DE8
	  lwz       r3, 0x10(r30)
	  mr        r4, r31
	  bl        0x41DDC
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x10(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x10(r1)

	.loc_0x98:
	  lwz       r0, 0x104(r1)
	  lwz       r31, 0xFC(r1)
	  lwz       r30, 0xF8(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}
