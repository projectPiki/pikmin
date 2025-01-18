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
DEFINE_ERROR();

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
	_20       = 0;
	mSENum    = 0;
	mMaxInfos = 128;
	mSeInfos  = new SeInfo[mMaxInfos];
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
 * Address:	........
 * Size:	000048
 */
SeInfo* SeMgr::findInfo(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A35D0
 * Size:	000034
 */
void SeMgr::addInfo(int p1, char* p2)
{
	if (mSENum >= mMaxInfos) {
		PRINT("maxInfos !\n");
		ERROR("mail to me\n");
	}

	mSeInfos[mSENum]._00 = p1;
	mSeInfos[mSENum]._04 = p2;
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
	_20++;
}

/*
 * --INFO--
 * Address:	800A3618
 * Size:	000024
 */
void SeMgr::leaveBattle()
{
	_20--;
	if (_20 <= 0) {
		_20 = 0;
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
	sprintf(buffer, "SE %d", _4C);
	printcentre(gfx, 80, buffer);
	sprintf(buffer, "%s", seMgr->getIndexInfo(_4C)->_04);
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
		_54--;
		mPosY += 32;
		if (!_54) {
			mStatus = 0x1001;
		}
		if (zen::Abs(mController->getMainStickY()) > 0.5f) {
			_60 = true;
		}
		return;
	}
	case 0x1002: {
		_54--;
		mPosY += 32;
		if (!_54) {
			mStatus = 0x1003;
		}
		return;
	}
	case 0x1001: {
		if (_60) {
			if (zen::Abs(mController->getMainStickY()) > 0.5f) {
				return;
			}
			_60 = false;
		}
		const f32 mainStickY = mController->getMainStickY();

		bool flag = true;
		if (mainStickY > 0.5f) {
			if (_58 <= 0) {
				_5C = 0.0f;
			} else if (_5C < 0.8f) {
				flag = false;
			}
			_5C += gsys->getFrameTime();
			if (_5C > 1.4f) {
				if (_58 < 6) {
					_58 += 1;
				}
			} else {
				_58 = 1;
			}
		} else if (mainStickY < -0.5f) {
			if (_58 >= 0) {
				_5C = 0.0f;
			} else if (_5C < 0.8f) {
				flag = false;
			}
			_5C += gsys->getFrameTime();
			if (_5C > 1.4f) {
				if (_58 > -6) {
					_58 -= 1;
				}
			} else {
				_58 = -1;
			}
		} else {
			_58 = 0;
			_5C = 0.0f;
		}
		if (_58 && flag) {
			if (_58 > 0) {
				_4C += (_58 + _4C >= seMgr->getSENum()) ? seMgr->getSENum() - _4C - 1 : _58;
				PRINT(" UP up is %d : curr became %d\n", _58, _4C);
			} else {
				_4C += (_58 + _4C < 0) ? 0 : _58;
				PRINT(" DOWN up is %d : curr became %d\n", _58, _4C);
			}
		}

		if (mController->isPressed(KBBTN_A)) {
			PRINT("stop %d sound ***********\n", _50);
			SeMgr::stop(_50);
			SeInfo* info = seMgr->getIndexInfo(_4C);
			_50          = info->_00;
			SeMgr::play(info->_00);
		} else if (mController->isPressed(KBBTN_B) || mController->isPressed(KBBTN_Z)) {
			SeMgr::stop(_4C);
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
	const int iVar1 = mPosY + 120;

	_54   = iVar1 / 32;
	mPosY = -120;
	_58   = 0;
	_50   = nullptr;
	_4C   = 0;
	_5C   = 0.0f;
	_60   = false;
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

	_54 = 15;
}
