#include "zen/ogResult.h"
#include "DebugLog.h"
#include "GameStat.h"
#include "P2D/Graph.h"
#include "P2D/Picture.h"
#include "P2D/Screen.h"
#include "PlayerState.h"
#include "SoundMgr.h"
#include "jaudio/verysimple.h"
#include "zen/DrawCM.h"
#include "zen/ogMessage.h"
#include "zen/ogSave.h"
#include "zen/ogSub.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("OgResultSection")

namespace zen {
char* bloFile_Res_Table[] = {
	"END",
	"screen/blo/re_a_00.blo",
	"screen/blo/re_a_01.blo",
	"screen/blo/re_b_00.blo",
	"screen/blo/re_b_01.blo",
	"screen/blo/re_c_00.blo",
	"screen/blo/re_d_00.blo",
	"screen/blo/re_e_00.blo",
	"screen/blo/re_f_00.blo",
	"screen/blo/re_f_01.blo",
	"screen/blo/re_g_00.blo",
	"screen/blo/re_h_00.blo",
	"screen/blo/re_i_00.blo",
	"screen/blo/re_j_00.blo",
	"screen/blo/re_k_00.blo",
	"screen/blo/re_j2_00.blo",
	"screen/blo/re_j2_01.blo",
	"screen/blo/re_k2_00.blo",
	"screen/blo/re_s1_00.blo",
	"screen/blo/re_t1_00.blo",
	"screen/blo/re_u1_00.blo",
	"screen/blo/re_v1_00.blo",
	"screen/blo/re_v1_01.blo",
	"screen/blo/re_p2_00.blo",
	"screen/blo/re_q2_00.blo",
	"screen/blo/re_q2_01.blo",
	"screen/blo/re_r2_00.blo",
	"screen/blo/re_l_00.blo",
	"screen/blo/re_l_01.blo",
	"screen/blo/re_m_00.blo",
	"screen/blo/re_m_01.blo",
	"screen/blo/re_n_00.blo",
	"screen/blo/re_o_00.blo",
	"screen/blo/re_p_00.blo",
	"screen/blo/re_p_01.blo",
	"screen/blo/re_q_00.blo",
	"screen/blo/re_r_00.blo",
	"screen/blo/re_s_00.blo",
	"screen/blo/re_t_00.blo",
	"screen/blo/re_u_00.blo",
	"screen/blo/re_v_00.blo",
	"screen/blo/re_w_00.blo",
	"screen/blo/re_x_00.blo",
	"screen/blo/re_y_00.blo",
	"screen/blo/re_z_00.blo",
	"screen/blo/re_a1_00.blo",
	"screen/blo/re_b1_00.blo",
	"screen/blo/re_c1_00.blo",
	"screen/blo/re_d1_00.blo",
	"screen/blo/re_e1_00.blo",
	"screen/blo/re_f1_00.blo",
	"screen/blo/re_g1_00.blo",
	"screen/blo/re_h1_00.blo",
	"screen/blo/re_i1_00.blo",
	"screen/blo/re_j1_00.blo",
	"screen/blo/re_k1_00.blo",
	"screen/blo/re_l1_00.blo",
	"screen/blo/re_m1_00.blo",
	"screen/blo/re_n1_00.blo",
	"screen/blo/re_o1_00.blo",
	"screen/blo/re_p1_00.blo",
	"screen/blo/re_q1_00.blo",
	"screen/blo/re_r1_00.blo",
	"screen/blo/re_w1_00.blo",
	"screen/blo/re_x1_00.blo",
	"screen/blo/re_y1_00.blo",
	"screen/blo/re_z1_00.blo",
	"screen/blo/re_a2_00.blo",
	"screen/blo/re_b2_00.blo",
	"screen/blo/re_c2_00.blo",
	"screen/blo/re_d2_00.blo",
	"screen/blo/re_e2_00.blo",
	"screen/blo/re_f2_00.blo",
	"screen/blo/re_g2_00.blo",
	"screen/blo/re_h2_00.blo",
	"screen/blo/re_i2_00.blo",
	"screen/blo/re_l2_00.blo",
	"screen/blo/re_m2_00.blo",
	"screen/blo/re_n2_00.blo",
	"screen/blo/re_o2_00.blo",
	"screen/blo/re_s2_00.blo",
	"screen/blo/re_t2_00.blo",
	"screen/blo/re_u2_00.blo",
	"screen/blo/re_v2_00.blo",
	"screen/blo/re_w2_00.blo",
	"screen/blo/ufo_a_0.blo",
	"screen/blo/ufo_b_0.blo",
	"screen/blo/ufo_c_0.blo",
	"screen/blo/ufo_d_0.blo",
	"screen/blo/ufo_e_0.blo",
	"screen/blo/ufo_f_0.blo",
	"screen/blo/ufo_g_0.blo",
	"screen/blo/ufo_h_0.blo",
	"screen/blo/ufo_i_0.blo",
	"screen/blo/ufo_j_0.blo",
	"screen/blo/ufo_k_0.blo",
	"screen/blo/ufo_l_0.blo",
	"screen/blo/ufo_m_0.blo",
	"screen/blo/ufo_n_0.blo",
	"screen/blo/ufo_o_0.blo",
	"screen/blo/ufo_p_0.blo",
	"screen/blo/ufo_q_0.blo",
	"screen/blo/ufo_r_0.blo",
	"screen/blo/ufo_s_0.blo",
	"screen/blo/ufo_t_0.blo",
	"screen/blo/ufo_u_0.blo",
	"screen/blo/ufo_v_0.blo",
	"screen/blo/ufo_w_0.blo",
	"screen/blo/ufo_x_0.blo",
	"screen/blo/ufo_y_0.blo",
	"screen/blo/ufo_z_0.blo",
	"screen/blo/ufo_a1_0.blo",
	"screen/blo/ufo_b1_0.blo",
	"screen/blo/ufo_c1_0.blo",
	"screen/blo/auf_a_0.blo",
	"screen/blo/auf_b_0.blo",
	"screen/blo/auf_c_0.blo",
	"screen/blo/auf_d_0.blo",
	"screen/blo/auf_e_0.blo",
	"screen/blo/auf_f_0.blo",
	"screen/blo/auf_g_0.blo",
	"screen/blo/auf_h_0.blo",
	"screen/blo/auf_i_0.blo",
	"screen/blo/auf_j_0.blo",
	"screen/blo/auf_k_0.blo",
	"screen/blo/auf_l_0.blo",
	"screen/blo/auf_m_0.blo",
	"screen/blo/auf_n_0.blo",
	"screen/blo/auf_o_0.blo",
	"screen/blo/auf_p_0.blo",
	"screen/blo/auf_q_0.blo",
	"screen/blo/auf_r_0.blo",
	"screen/blo/auf_s_0.blo",
	"screen/blo/auf_t_0.blo",
	"screen/blo/auf_u_0.blo",
	"screen/blo/auf_v_0.blo",
	"screen/blo/auf_w_0.blo",
	"screen/blo/auf_x_0.blo",
	"screen/blo/auf_y_0.blo",
	"screen/blo/auf_z_0.blo",
	"screen/blo/auf_a1_0.blo",
	"screen/blo/auf_b1_0.blo",
	"screen/blo/auf_c1_0.blo",
	"screen/blo/auf_d1_0.blo",
	"END",
	"screen/blo/re_a_00.blo",
	"screen/blo/re_a_00.blo",
	"screen/blo/re_a_00.blo",
	"END",
};

EnumResult dummy_blo_num_table[] = { (EnumResult)0x91, (EnumResult)0 };
} // namespace zen

/*
 * --INFO--
 * Address:	80183408
 * Size:	000DE0
 */
void zen::ogScrResultMgr::ogScrResultMgrSub()
{
	mBlackScreen = new P2DScreen;
	mBlackScreen->set("screen/blo/black.blo", false, false, true);
	mBlackPane = (P2DPicture*)mBlackScreen->search('blck', true);
	mBlackPane->setAlpha(0);

	mMainScreen = new P2DScreen;
	mMainScreen->set("screen/blo/account2.blo", false, false, true);

	mCMBestData = new DrawCMbest;
	mCMBestData->init(mMainScreen);

	mPaneRoot        = mMainScreen->search('root', true);
	_38              = mMainScreen->search('po_1', true);
	_3C              = mMainScreen->search('po2u', true);
	_40              = mMainScreen->search('po2d', true);
	_44              = mMainScreen->search('po3u', true);
	_48              = mMainScreen->search('po3c', true);
	_4C              = mMainScreen->search('po3d', true);
	mPaneRedPikis    = mMainScreen->search('p_rc', true);
	mPaneBluePikis   = mMainScreen->search('p_bc', true);
	mPaneYellowPikis = mMainScreen->search('p_yc', true);
	_5C              = mMainScreen->search('g_sp', true);
	mPaneData        = mMainScreen->search('data', true);
	mPaneFileNum1    = mMainScreen->search('da_1', true);
	mPaneFileNum2    = mMainScreen->search('da_2', true);
	mPaneFileNum3    = mMainScreen->search('da_3', true);

	mPaneData->show();
	mPaneFileNum1->hide();
	mPaneFileNum2->hide();
	mPaneFileNum3->hide();

	switch (gameflow.mGamePrefs.mFileNum) {
	case 0:
		mPaneFileNum1->show();
		break;
	case 1:
		mPaneFileNum2->show();
		break;
	case 2:
		mPaneFileNum3->show();
		break;
	}

	_94 = (P2DTextBox*)mMainScreen->search('getp', true);
	mPaneRedPikis->hide();
	mPaneBluePikis->hide();
	mPaneYellowPikis->hide();

	P2DScreen* screen = mMainScreen;
	setNumberTag(screen, '4_rc', &mRedPikis, 1000);
	setNumberTag(screen, 'rc_l', &mRedPikis, 100);
	setNumberTag(screen, 'rc_c', &mRedPikis, 10);
	setNumberTag(screen, 'rc_r', &mRedPikis, 1);

	setNumberTag(screen, '4_bc', &mBluePikis, 1000);
	setNumberTag(screen, 'bc_l', &mBluePikis, 100);
	setNumberTag(screen, 'bc_c', &mBluePikis, 10);
	setNumberTag(screen, 'bc_r', &mBluePikis, 1);

	setNumberTag(screen, '4_yc', &mYellowsPikis, 1000);
	setNumberTag(screen, 'yc_l', &mYellowsPikis, 100);
	setNumberTag(screen, 'yc_c', &mYellowsPikis, 10);
	setNumberTag(screen, 'yc_r', &mYellowsPikis, 1);

	setNumberTag(screen, 'tp_4', &mTotalPikis, 1000);
	setNumberTag(screen, 'tp_l', &mTotalPikis, 100);
	setNumberTag(screen, 'tp_c', &mTotalPikis, 10);
	setNumberTag(screen, 'tp_r', &mTotalPikis, 1);

	setNumberTag(screen, '4_bo', &mBornPikis, 1000);
	setNumberTag(screen, 'bo_l', &mBornPikis, 100);
	setNumberTag(screen, 'bo_c', &mBornPikis, 10);
	setNumberTag(screen, 'bo_r', &mBornPikis, 1);

	setNumberTag(screen, '4_ba', &mDeadPikis, 1000);
	setNumberTag(screen, 'ba_l', &mDeadPikis, 100);
	setNumberTag(screen, 'ba_c', &mDeadPikis, 10);
	setNumberTag(screen, 'ba_r', &mDeadPikis, 1);

	setNumberTag(screen, '4_sd', &mVictimPikis, 1000);
	setNumberTag(screen, 'sd_l', &mVictimPikis, 100);
	setNumberTag(screen, 'sd_c', &mVictimPikis, 10);
	setNumberTag(screen, 'sd_r', &mVictimPikis, 1);

	setNumberTag(screen, '4bo2', &mSproutedPikis, 1000);
	setNumberTag(screen, 'bo2l', &mSproutedPikis, 100);
	setNumberTag(screen, 'bo2c', &mSproutedPikis, 10);
	setNumberTag(screen, 'bo2r', &mSproutedPikis, 1);

	setNumberTag(screen, '4ba2', &mPikisLostToBattle, 1000);
	setNumberTag(screen, 'ba2l', &mPikisLostToBattle, 100);
	setNumberTag(screen, 'ba2c', &mPikisLostToBattle, 10);
	setNumberTag(screen, 'ba2r', &mPikisLostToBattle, 1);

	setNumberTag(screen, '4sd2', &mLeftBehindPikis, 1000);
	setNumberTag(screen, 'sd2l', &mLeftBehindPikis, 100);
	setNumberTag(screen, 'sd2c', &mLeftBehindPikis, 10);
	setNumberTag(screen, 'sd2r', &mLeftBehindPikis, 1);

	_98 = mMainScreen->search('4_bo', true);
	_9C = mMainScreen->search('4_ba', true);
	_A0 = mMainScreen->search('4_sd', true);
	_BC = mMainScreen->search('4bo2', true);
	_C0 = mMainScreen->search('4ba2', true);
	_C4 = mMainScreen->search('4sd2', true);
	_C8 = mMainScreen->search('4_rc', true);
	_CC = mMainScreen->search('4_yc', true);
	_D0 = mMainScreen->search('4_bc', true);
	_D4 = mMainScreen->search('rc_r', true);
	_DC = mMainScreen->search('yc_r', true);
	_D8 = mMainScreen->search('bc_r', true);

	setNumberTag(screen, 'dc_l', &mCurrentDay, 10);
	setNumberTag(screen, 'dc_c', &mCurrentDay, 1);
	setNumberTag(screen, 'dc_r', &mCurrentDay, 1);

	setNumberTag(screen, 'ro_l', &mRemainingParts, 10);
	setNumberTag(screen, 'ro_c', &mRemainingParts, 1);
	setNumberTag(screen, 'ro_r', &mRemainingParts, 1);

	setNumberTag(screen, 'ti_l', &mRemainingDays, 10);
	setNumberTag(screen, 'ti_c', &mRemainingDays, 1);
	setNumberTag(screen, 'ti_r', &mRemainingDays, 1);

	mPaneDaysL = screen->search('dc_l', true);
	mPaneDaysC = screen->search('dc_c', true);
	mPaneDaysR = screen->search('dc_r', true);
	_A4        = screen->search('bo_r', true);
	_A8        = screen->search('ba_r', true);
	_AC        = screen->search('sd_r', true);
	_B0        = screen->search('bo2r', true);
	_B4        = screen->search('ba2r', true);
	_B8        = screen->search('sd2r', true);

	mPaneDaysLeftL  = screen->search('ti_l', true);
	mPaneDaysLeftC  = screen->search('ti_c', true);
	mPaneDaysLeftR  = screen->search('ti_r', true);
	mPanePartsLeftL = screen->search('ro_l', true);
	mPanePartsLeftC = screen->search('ro_c', true);
	mPanePartsLeftR = screen->search('ro_r', true);

	mBluePikis     = 111;
	mRedPikis      = 222;
	mYellowsPikis  = 333;
	mTotalPikis    = 444;
	mBornPikis     = 555;
	mDeadPikis     = 666;
	mVictimPikis   = 777;
	_114           = 999;
	_118           = 0;
	mCurrentDay    = 77;
	mRemainingDays = 88;
	mCurrentParts  = 99;
	mTotalDays     = MAX_DAYS;
	mTotalParts    = 55;

	if (playerState == nullptr) {
		mHasBlue   = true;
		mHasRed    = true;
		mHasYellow = true;
	} else {
		mHasBlue   = playerState->displayPikiCount(Blue);
		mHasRed    = playerState->displayPikiCount(Red);
		mHasYellow = playerState->displayPikiCount(Yellow);
	}

	if (mHasBlue) {
		mPaneBluePikis->show();
	}
	if (mHasRed) {
		mPaneRedPikis->show();
	}
	if (mHasYellow) {
		mPaneYellowPikis->show();
	}
	mPageInfoPtr = mDiaryPathList;
	_554         = 0;

	mMesgScreen = new ogScrMessageMgr("screen/blo/tu_base.blo");
	mGraphMgr   = new ogGraphMgr(mMainScreen);
	mAlphaMgr   = new PikaAlphaMgr(mMainScreen);
	mStatus     = Status_NULL;
	mBgAlpha    = 0;

	mSaveMgr = new ogSaveMgr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void zen::ogScrResultMgr::check1000(int val, P2DPane* pane1, P2DPane* pane2, int x)
{
	if (val >= 1000) {
		pane1->show();
		pane2->move(x + pane2->getPosH(), pane2->getPosV());
	} else {
		pane1->hide();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void zen::ogScrResultMgr::setEnumResultTable(EnumResult* result)
{
	for (int i = 0; i < 256; i++) {
		int res           = result[i];
		mDiaryPathList[i] = bloFile_Res_Table[res];
		if (res == 0) {
			break;
		}
	}
	PRINT("OVERFLOW in setEnumResultTable()\n");
}

/*
 * --INFO--
 * Address:	801841E8
 * Size:	00017C
 */
zen::ogScrResultMgr::ogScrResultMgr()
{
	playerState = nullptr;
	setEnumResultTable(dummy_blo_num_table);
	ogScrResultMgrSub();
}

/*
 * --INFO--
 * Address:	80184364
 * Size:	000170
 */
zen::ogScrResultMgr::ogScrResultMgr(EnumResult* table)
{
	setEnumResultTable(table);
	ogScrResultMgrSub();
}

/*
 * --INFO--
 * Address:	801844D4
 * Size:	000744
 */
void zen::ogScrResultMgr::start()
{
	if (playerState == nullptr) {
		setSpecialNumber(1, -123);
		mCurrentDay        = 1;
		mRemainingDays     = 2;
		mRemainingParts    = 3;
		mCurrentParts      = 77;
		mTotalParts        = MAX_UFO_PARTS;
		mTotalDays         = MAX_DAYS;
		mSproutedPikis     = 2345;
		mPikisLostToBattle = 3456;
		mLeftBehindPikis   = 4567;
		mBluePikis         = 1234;
		mRedPikis          = 2345;
		mYellowsPikis      = 3456;
		mTotalPikis        = 9876;
		mBornPikis         = 1234;
		mDeadPikis         = 2345;
		mVictimPikis       = 3456;
		mPowerupNum        = 77;
	} else {
		mCurrentDay        = playerState->getCurrDay();
		mTotalDays         = playerState->getTotalDays();
		mRemainingDays     = mTotalDays - mCurrentDay;
		mCurrentParts      = playerState->getCurrParts();
		mTotalParts        = playerState->getTotalParts();
		mRemainingParts    = mTotalParts - mCurrentParts;
		mSproutedPikis     = playerState->mSproutedNum;
		mPikisLostToBattle = playerState->mLostBattlePikis;
		mLeftBehindPikis   = playerState->mLeftBehindPikis;
		mBluePikis         = GameStat::containerPikis[Blue] + GameStat::formationPikis[Blue];
		mRedPikis          = GameStat::containerPikis[Red] + GameStat::formationPikis[Red];
		mYellowsPikis      = GameStat::containerPikis[Yellow] + GameStat::formationPikis[Yellow];
		mTotalPikis        = mRedPikis + mBluePikis + mYellowsPikis;
		mBornPikis         = GameStat::bornPikis;
		mDeadPikis         = GameStat::deadPikis - GameStat::victimPikis;
		mVictimPikis       = GameStat::victimPikis;
		mPowerupNum        = playerState->getNextPowerupNumber();
	}
	setSpecialNumber(1, mCurrentDay);
	setSpecialNumber(2, mCurrentParts);
	setSpecialNumber(3, mRemainingParts);
	setSpecialNumber(4, mRemainingDays);
	setSpecialNumber(5, mPowerupNum);

	strcpy(_13D, _94->getString());
	cnvSpecialNumber(_13D);
	_94->setString(_13D);
	mMesgScreen->MakeAndSetPageInfo(&mPageInfoPtr);
	mMesgScreen->setSolidMode(true);
	mStatus = Status_3;
	mMesgScreen->start(0);
	mBlackPane->setAlpha(0);
	mGraphAlpha = 0;
	mWaitTimer  = 0.0f;
	mBgAlpha    = 0;
	mPaneRoot->move(0, -480);

	if (mCurrentDay < 10) {
		mPaneDaysL->hide();
		mPaneDaysC->show();
		mPaneDaysR->hide();
	} else {
		mPaneDaysL->show();
		mPaneDaysC->hide();
		mPaneDaysR->show();
	}

	if (mRemainingDays < 10) {
		mPaneDaysLeftL->hide();
		mPaneDaysLeftC->show();
		mPaneDaysLeftR->hide();
	} else {
		mPaneDaysLeftL->show();
		mPaneDaysLeftC->hide();
		mPaneDaysLeftR->show();
	}

	if (mRemainingParts < 10) {
		mPanePartsLeftL->hide();
		mPanePartsLeftC->show();
		mPanePartsLeftR->hide();
	} else {
		mPanePartsLeftL->show();
		mPanePartsLeftC->hide();
		mPanePartsLeftR->show();
	}

	check1000(mBornPikis, _98, _A4, 14);
	check1000(mDeadPikis, _9C, _A8, 14);
	check1000(mVictimPikis, _A0, _AC, 14);
	check1000(mSproutedPikis, _BC, _B0, 14);
	check1000(mPikisLostToBattle, _C0, _B4, 14);
	check1000(mLeftBehindPikis, _C4, _B8, 14);
	check1000(mBluePikis, _D0, _D8, 12);
	check1000(mRedPikis, _C8, _D4, 12);
	check1000(mYellowsPikis, _CC, _DC, 12);
	mCMBestData->sleep();

	STACK_PAD_VAR(18);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void zen::ogScrResultMgr::StartRESULT()
{
	PRINT("--- StartRESULT !---\n");
	P2DPaneLibrary::makeResident(mMainScreen);
	mStartWaitDelay = 6;
}

/*
 * --INFO--
 * Address:	80184C18
 * Size:	000384
 */
zen::ogScrResultMgr::returnStatusFlag zen::ogScrResultMgr::update(Controller* input)
{
	if (mStatus == -1) {
		return mStatus;
	}

	if (mStatus == Status_4) {
		PRINT("--- RESULT_TEX_WAIT %d ---\n", mStartWaitDelay);
		mStartWaitDelay--;
		if (mStartWaitDelay <= 0) {
			mStatus = Status_5;
			mAlphaMgr->startFadeIn(1.0f);
			mWaitTimer = 0.0f;
		}
		return mStatus;
	}

	mMainScreen->update();
	mAlphaMgr->update();
	mCMBestData->update();

	if (mStatus == Status_5) {
		mWaitTimer += gsys->getFrameTime();
		if (mWaitTimer >= 1.0f) {
			mStatus = Status_0;
			mPaneRoot->move(0, 0);
			mCMBestData->appear();
		} else {
			mPaneRoot->move(0, f32((mWaitTimer + -1.0) * 480.0f));
			mBgAlpha = u8(mWaitTimer * 255.0f);
		}
		return mStatus;
	}

	if (mStatus == Status_6) {
		mWaitTimer += gsys->getFrameTime();
		if (mWaitTimer >= 0.5f) {
			mBgAlpha = 0;
			mBlackPane->setAlpha(255);
			mStatus = mStatus2;
		} else {
			mBgAlpha = u8((1.0f - mWaitTimer) * 255.0f);
			mBlackPane->setAlpha(255 - mBgAlpha);
		}
		return mStatus;
	}

	if (mStatus >= Status_7) {
		mStatus = Status_NULL;
		return mStatus;
	}

	if (mStatus == Status_3) {
		if (mMesgScreen->update(input) == ogScrMessageMgr::STATE_TransitionToInactive) {
			mStatus = Status_4;
			StartRESULT();
		}
		return mStatus;
	}

	if (mStatus == Status_0) {
		if (mGraphAlpha < 255) {
			mGraphAlpha += 8;
			if (mGraphAlpha > 255) {
				mGraphAlpha = 255;
			}
		}

		mSaveStatus = mSaveMgr->update(input);
		if (mSaveStatus == 14) {
			mWaitTimer = 0.0f;
			mStatus2   = Status_7;
			mStatus    = Status_6;
		} else if (mSaveStatus == 12) {
			mWaitTimer = 0.0f;
			mStatus    = Status_0;
		} else if (mSaveStatus == 13) {
			mStatus2 = Status_7;
			mStatus  = Status_6;
		} else if (mSaveStatus == 15) {
			mWaitTimer = 0.0f;
			mStatus2   = Status_8;
			mStatus    = Status_6;
		} else if (mSaveStatus == -1) {
			if (input->keyClick(KBBTN_START | KBBTN_A | KBBTN_B)) {
#if defined(VERSION_PIKIDEMO)
				seSystem->playSysSe(JACSYS_Decide1);
#else
				seSystem->playSysSe(SYSSE_DECIDE1);
#endif
				mWaitTimer = 0.0f;
				mSaveMgr->start();
				PRINT("<<<<<<<<< SAVE Mgr START! >>>>>>>>>>>\n");
			}
			mSaveWaitTimer += gsys->getFrameTime();
			if (mSaveWaitTimer > 1.0f) {
				mSaveWaitTimer = 0.0f;
			}
			sinf(mSaveWaitTimer * TAU);
		}
	}

	mBlackScreen->update();
	return mStatus;

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	80184F9C
 * Size:	000104
 */
void zen::ogScrResultMgr::draw(Graphics& gfx)
{
	if (mStatus != Status_NULL && mStatus != Status_4) {
		if (mStatus == Status_3) {
			mMesgScreen->draw(gfx);
			return;
		}

		P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
		graf.setPort();
#if defined(VERSION_PIKIDEMO)
		mMainScreen->draw(0, 0, &graf);
		mGraphMgr->draw(mGraphAlpha);
		mSaveMgr->draw(gfx);
		mBlackScreen->draw(0, 0, &graf);
#else
		if (mSaveMgr->isFileMode()) {
			mSaveMgr->draw(gfx);
		} else {
			mMainScreen->draw(0, 0, &graf);
			mGraphMgr->draw(mGraphAlpha);
			mSaveMgr->draw(gfx);
			mBlackScreen->draw(0, 0, &graf);
		}
#endif
	}
}
