#include "DebugLog.h"
#include "jaudio/PikiPlayer.h"
#include "jaudio/verysimple.h"
#include "SoundMgr.h"
#include "stdio.h"
#include "sysNew.h"
#include "system.h"
#include "zen/Math.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr); // Must be nullptr to match the DOL, but is "seMgr" in the DLL.

SeMgr* seMgr;

/*
 * --INFO--
 * Address:	800A3428
 * Size:	000180
 */
SeMgr::SeMgr()
{
	mBattleCount = 0;
	mSENum       = 0;
	mMaxInfos    = 128;
	mSeInfos     = new SeInfo[mMaxInfos];
	addInfo(0x0007, "Breakup");
	addInfo(0x0008, "Gather");
	addInfo(0x0006, "Throw");
	addInfo(0x0000, "Piki Hit");
	addInfo(0x8002, "Piki Fly");
	addInfo(0x0003, "Piki Pulling");
	addInfo(0x8007, "Piki Pulled");
	addInfo(0x8003, "Piki Breakup Voice");
	addInfo(0x0002, "Piki Lift");
	addInfo(0x8006, "Piki Find");
	addInfo(0x8004, "Piki Flyready");
	addInfo(0x8005, "Piki Called");
}

/*
 * --INFO--
 * Address:	800A35A8
 * Size:	000028
 */
void SeMgr::playNaviSound(s32 p1, s32 p2)
{
	Jac_Orima_Formation(p1, p2);
}

/*
 * --INFO--
 * Address:	........ in DOL, 10126280 in DLL
 * Size:	000048
 */
SeInfo* SeMgr::findInfo(int seID)
{
	for (int i = 0;; i++) {
		if (mSENum <= i)
			return nullptr;
		if (mSeInfos[i].mSeID == seID)
			return &mSeInfos[i];
	}
}

/*
 * --INFO--
 * Address:	800A35D0
 * Size:	000034
 */
void SeMgr::addInfo(int seID, char* seName)
{
	if (mSENum >= mMaxInfos) {
		PRINT("maxInfos !\n");
		ERROR("mail to me\n");
	}

	mSeInfos[mSENum].mSeID   = seID;
	mSeInfos[mSENum].mSeName = seName;
	mSENum++;
}

/*
 * --INFO--
 * Address:	800A3604
 * Size:	000004
 */
void SeMgr::update()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SeMgr::play(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SeMgr::stop(u32 soundID)
{
	Jac_StopSe(soundID);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SeMgr::playBGM(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SeMgr::stopBGM()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void SeMgr::stopSoundAll()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A3608
 * Size:	000010
 */
void SeMgr::joinBattle()
{
	mBattleCount++;
}

/*
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

/*
 * --INFO--
 * Address:	800A363C
 * Size:	000038
 */
void SeMgr::setPikiNum(int p1)
{
	if (!p1) {
		Jac_Piki_Number(0);
	} else {
		Jac_Piki_Number(p1);
	}
}

/*
 * --INFO--
 * Address:	800A3674
 * Size:	0000E4
 */
void SeWin::doRender(Graphics& gfx)
{
	char buffer[60];
	u32 badCompiler;
	printStart(gfx);
	printcentre(gfx, 32, "SE テスト"); // "SE Test"
	sprintf(buffer, "SE %d", mCurrSeID);
	printcentre(gfx, 80, buffer);
	sprintf(buffer, "%s", seMgr->getIndexInfo(mCurrSeID)->mSeName);
	printcentre(gfx, 140, buffer);
}

/*
 * --INFO--
 * Address:	800A3758
 * Size:	0002E4
 */
void SeWin::update()
{
	u32 badCompiler[2]; // sigh

	switch (mStatus) {
	case 0x1000: {
		mAnimFramesRemaining--;
		mPosY += 32;
		if (!mAnimFramesRemaining) {
			mStatus = 0x1001;
		}
		if (zen::Abs(mController->getMainStickY()) > 0.5f) {
			mStickWasPushed = true;
		}
		return;
	}
	case 0x1002: {
		mAnimFramesRemaining--;
		mPosY += 32;
		if (!mAnimFramesRemaining) {
			mStatus = 0x1003;
		}
		return;
	}
	case 0x1001: {
		if (mStickWasPushed) {
			if (zen::Abs(mController->getMainStickY()) > 0.5f) {
				return;
			}
			mStickWasPushed = false;
		}
		const f32 mainStickY = mController->getMainStickY();

		bool flag = true;
		if (mainStickY > 0.5f) {
			if (mUp <= 0) {
				mTime = 0.0f;
			} else if (mTime < 0.8f) {
				flag = false;
			}
			mTime += gsys->getFrameTime();
			if (mTime > 1.4f) {
				if (mUp < 6) {
					mUp += 1;
				}
			} else {
				mUp = 1;
			}
		} else if (mainStickY < -0.5f) {
			if (mUp >= 0) {
				mTime = 0.0f;
			} else if (mTime < 0.8f) {
				flag = false;
			}
			mTime += gsys->getFrameTime();
			if (mTime > 1.4f) {
				if (mUp > -6) {
					mUp -= 1;
				}
			} else {
				mUp = -1;
			}
		} else {
			mUp   = 0;
			mTime = 0.0f;
		}
		if (mUp && flag) {
			if (mUp > 0) {
				mCurrSeID += (mUp + mCurrSeID >= seMgr->getSENum()) ? seMgr->getSENum() - mCurrSeID - 1 : mUp;
				PRINT(" UP up is %d : curr became %d\n", mUp, mCurrSeID);
			} else {
				mCurrSeID += (mUp + mCurrSeID < 0) ? 0 : mUp;
				PRINT(" DOWN up is %d : curr became %d\n", mUp, mCurrSeID);
			}
		}

		if (mController->keyClick(KBBTN_A)) {
			PRINT("stop %d sound ***********\n", mSound);
			SeMgr::stop(mSound);
			SeInfo* info = seMgr->getIndexInfo(mCurrSeID);
			mSound       = info->mSeID;
			SeMgr::play(info->mSeID);
		} else if (mController->keyClick(KBBTN_B) || mController->keyClick(KBBTN_Z)) {
			SeMgr::stop(mCurrSeID);
			close();
		}
		return;
	}
	}
}

/*
 * --INFO--
 * Address:	800A3A3C
 * Size:	00007C
 */
void SeWin::open()
{
	if (mStatus == 0x1000)
		return;
	placeCentre();
	GmWin::open();

	mAnimFramesRemaining = (mPosY + 120) / 32;
	mPosY                = -120;
	mUp                  = 0;
	mSound               = 0;
	mCurrSeID            = 0;
	mTime                = 0.0f;
	mStickWasPushed      = false;

	seMgr->stopBGM();
}

/*
 * --INFO--
 * Address:	800A3AB8
 * Size:	00004C
 */
void SeWin::close()
{
	if (mStatus == 0x1002)
		return;
	placeCentre();
	GmWin::close();

	mAnimFramesRemaining = 15;
}
