#include "DebugLog.h"
#include "jaudio/piki_player.h"
#include "jaudio/verysimple.h"
#include "SoundMgr.h"
#include "stdio.h"
#include "sysNew.h"
#include "system.h"
#include "zen/Math.h"

/**
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(7)

/**
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("seMgr");

/// Global sound effect manager object.
SeMgr* seMgr;

/**
 * --INFO--
 * Address:	800A3428
 * Size:	000180
 */
SeMgr::SeMgr()
{
	mBattleCount = 0;
	mSENum       = 0;
	mMaxInfos    = MAX_SOUND_EFFECTS;
	mSeInfos     = new SeInfo[mMaxInfos];
	addInfo(JACORIMA_Breakup, "Breakup");
	addInfo(JACORIMA_Gather, "Gather");
	addInfo(JACORIMA_Throw, "Throw");
	addInfo(JACORIMA_PikiHit, "Piki Hit");
	addInfo(JACORIMA_PikiFly, "Piki Fly");
	addInfo(JACORIMA_PikiPulling, "Piki Pulling");
	addInfo(JACORIMA_PikiPulled, "Piki Pulled");
	addInfo(JACORIMA_PikiBreakupVoice, "Piki Breakup Voice");
	addInfo(JACORIMA_PikiLift, "Piki Lift");
	addInfo(JACORIMA_PikiFind, "Piki Find");
	addInfo(JACORIMA_PikiFlyReady, "Piki Flyready");
	addInfo(JACORIMA_PikiCalled, "Piki Called");
}

/**
 * --INFO--
 * Address:	800A35A8
 * Size:	000028
 */
void SeMgr::playNaviSound(s32 stickX, s32 stickY)
{
	Jac_Orima_Formation(stickX, stickY);
}

/**
 * --INFO--
 * Address:	........ in DOL, 10126280 in DLL
 * Size:	000048
 */
SeInfo* SeMgr::findInfo(int jacSeID)
{
	for (int i = 0; i < mSENum; i++) {
		if (mSeInfos[i].mJacPlayerSeID == jacSeID) {
			return &mSeInfos[i];
		}
	}

	return nullptr;
}

/**
 * --INFO--
 * Address:	800A35D0
 * Size:	000034
 */
void SeMgr::addInfo(int jacSeID, char* seName)
{
	if (mSENum >= mMaxInfos) {
		PRINT("maxInfos !\n");
		ERROR("mail to me\n");
	}

	mSeInfos[mSENum].mJacPlayerSeID = jacSeID;
	mSeInfos[mSENum].mSeName        = seName;
	mSENum++;
}

/**
 * --INFO--
 * Address:	800A3604
 * Size:	000004
 */
void SeMgr::update()
{
}

/**
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SeMgr::play(u32)
{
}

/**
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SeMgr::stop(u32 jacSeID)
{
	Jac_StopSe(jacSeID);
}

/**
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SeMgr::playBGM(u32)
{
}

/**
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SeMgr::stopBGM()
{
}

/**
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void SeMgr::stopSoundAll()
{
	// UNUSED FUNCTION
}

/**
 * --INFO--
 * Address:	800A3608
 * Size:	000010
 */
void SeMgr::joinBattle()
{
	mBattleCount++;
}

/**
 * --INFO--
 * Address:	800A3618
 * Size:	000024
 */
void SeMgr::leaveBattle()
{
	mBattleCount--;
	if (mBattleCount <= 0) {
		mBattleCount = 0;
	}
}

/**
 * @note This function is never passed anything except 0 in retail.
 *
 * --INFO--
 * Address:	800A363C
 * Size:	000038
 */
void SeMgr::setPikiNum(int pikiNum)
{
	if (pikiNum == 0) {
		// idk why we need this check but whatever.
		Jac_Piki_Number(0);
	} else {
		Jac_Piki_Number(pikiNum);
	}
}

/**
 * --INFO--
 * Address:	800A3674
 * Size:	0000E4
 */
void SeWin::doRender(Graphics& gfx)
{
	char buffer[60];
	STACK_PAD_VAR(1);
	printStart(gfx);
	printcentre(gfx, 32, "SE テスト"); // "SE Test"
	sprintf(buffer, "SE %d", mCurrSeIndex);
	printcentre(gfx, 80, buffer);
	sprintf(buffer, "%s", seMgr->getIndexInfo(mCurrSeIndex)->mSeName);
	printcentre(gfx, 140, buffer);
}

/**
 * --INFO--
 * Address:	800A3758
 * Size:	0002E4
 */
void SeWin::update()
{
	STACK_PAD_VAR(2); // sigh

	switch (mStatus) {
	case GMWIN_Opening: {
		mAnimFramesRemaining--;
		mPosY += 32;
		if (!mAnimFramesRemaining) {
			mStatus = GMWIN_Active;
		}
		if (absF(mController->getMainStickY()) > 0.5f) {
			mStickWasPushed = true;
		}
		return;
	}
	case GMWIN_Closing: {
		mAnimFramesRemaining--;
		mPosY += 32;
		if (!mAnimFramesRemaining) {
			mStatus = GMWIN_Inactive;
		}
		return;
	}
	case GMWIN_Active: {
		if (mStickWasPushed) {
			if (absF(mController->getMainStickY()) > 0.5f) {
				return;
			}
			mStickWasPushed = false;
		}
		const f32 mainStickY = mController->getMainStickY();

		bool flag = true;
		if (mainStickY > 0.5f) {
			if (mUp <= 0) {
				mScrollTime = 0.0f;
			} else if (mScrollTime < 0.8f) {
				flag = false;
			}
			mScrollTime += gsys->getFrameTime();
			if (mScrollTime > 1.4f) {
				if (mUp < 6) {
					mUp += 1;
				}
			} else {
				mUp = 1;
			}
		} else if (mainStickY < -0.5f) {
			if (mUp >= 0) {
				mScrollTime = 0.0f;
			} else if (mScrollTime < 0.8f) {
				flag = false;
			}
			mScrollTime += gsys->getFrameTime();
			if (mScrollTime > 1.4f) {
				if (mUp > -6) {
					mUp -= 1;
				}
			} else {
				mUp = -1;
			}
		} else {
			mUp         = 0;
			mScrollTime = 0.0f;
		}
		if (mUp && flag) {
			if (mUp > 0) {
				mCurrSeIndex += (mUp + mCurrSeIndex >= seMgr->getSENum()) ? seMgr->getSENum() - mCurrSeIndex - 1 : mUp;
				PRINT(" UP up is %d : curr became %d\n", mUp, mCurrSeIndex);
			} else {
				mCurrSeIndex += (mUp + mCurrSeIndex < 0) ? 0 : mUp;
				PRINT(" DOWN up is %d : curr became %d\n", mUp, mCurrSeIndex);
			}
		}

		if (mController->keyClick(KBBTN_A)) {
			PRINT("stop %d sound ***********\n", mCurrJacSoundID);
			SeMgr::stop(mCurrJacSoundID);
			SeInfo* info    = seMgr->getIndexInfo(mCurrSeIndex);
			mCurrJacSoundID = info->mJacPlayerSeID;
			SeMgr::play(info->mJacPlayerSeID);

		} else if (mController->keyClick(KBBTN_B) || mController->keyClick(KBBTN_Z)) {
			SeMgr::stop(mCurrSeIndex);
			close();
		}
		return;
	}
	}
}

/**
 * --INFO--
 * Address:	800A3A3C
 * Size:	00007C
 */
void SeWin::open()
{
	if (mStatus == GMWIN_Opening) {
		// already opening!
		return;
	}

	placeCentre();
	GmWin::open();

	mAnimFramesRemaining = (mPosY + 120) / 32;
	mPosY                = -120;
	mUp                  = 0;
	mCurrJacSoundID      = 0;
	mCurrSeIndex         = 0;
	mScrollTime          = 0.0f;
	mStickWasPushed      = false;

	seMgr->stopBGM();
}

/**
 * --INFO--
 * Address:	800A3AB8
 * Size:	00004C
 */
void SeWin::close()
{
	if (mStatus == GMWIN_Closing) {
		// already closing!
		return;
	}

	placeCentre();
	GmWin::close();

	mAnimFramesRemaining = 15;
}
