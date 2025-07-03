#include "zen/DrawAccount.h"
#include "zen/Number.h"
#include "zen/Math.h"
#include "nlib/Math.h"
#include "sysNew.h"
#include "DebugLog.h"

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
DEFINE_PRINT("DrawAccount")

/*
 * --INFO--
 * Address:	801C1140
 * Size:	001474
 */
zen::DrawAccount::DrawAccount()
    : DrawScreen("screen/blo/account.blo", nullptr, false, false)
{
	mIsVisible      = false;
	mAppearTimer    = 0.0f;
	mAppearDuration = 3.0f;
	mRootPane       = mScreen.search('root', true);
	mRootPane->move(0, -1000);
	mBlakPane = mScreen.search('blak', true);
	P2DPaneLibrary::setFamilyAlpha(mBlakPane, 0);

	P2DPane* pane = mScreen.search('cl_0', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mMinPikiNum, 100, false));
	pane = mScreen.search('cc_0', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mMinPikiNum, 10, false));
	pane = mScreen.search('cr_0', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mMinPikiNum, 1, false));

	pane = mScreen.search('cl_1', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mMaxPikiNum, 100, false));
	pane = mScreen.search('cc_1', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mMaxPikiNum, 10, false));
	pane = mScreen.search('cr_1', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mMaxPikiNum, 1, false));

	pane = mScreen.search('cl_2', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mDeadPikiNum, 100, false));
	pane = mScreen.search('cc_2', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mDeadPikiNum, 10, false));
	pane = mScreen.search('cr_2', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mDeadPikiNum, 1, false));

	pane = mScreen.search('cl_3', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mDeadTekiNum, 100, false));
	pane = mScreen.search('cc_3', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mDeadTekiNum, 10, false));
	pane = mScreen.search('cr_3', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mDeadTekiNum, 1, false));

	pane = mScreen.search('cl_4', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mPelletNum, 100, false));
	pane = mScreen.search('cc_4', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mPelletNum, 10, false));
	pane = mScreen.search('cr_4', true);
	pane->setCallBack(new NumberPicCallBack<s16>(pane, &mData.mPelletNum, 1, false));
}

/*
 * --INFO--
 * Address:	801C25B4
 * Size:	000124
 */
void zen::DrawAccount::update()
{
	if (mIsVisible) {
		mAppearTimer += gsys->getFrameTime();
		if (mAppearTimer > mAppearDuration) {
			mAppearTimer = mAppearDuration;
		}

		f32 t     = (1.0f - NMathF::cos(PI * mAppearTimer / mAppearDuration)) * 0.5f;
		f32 tComp = 1.0f - t;
		mRootPane->move(0, RoundOff(-1000.0f * tComp));
		P2DPaneLibrary::setFamilyAlpha(mBlakPane, RoundOff(64.0f * t));
		DrawScreen::update();
	}
}

/*
 * --INFO--
 * Address:	801C26D8
 * Size:	00002C
 */
void zen::DrawAccount::draw(Graphics&)
{
	if (mIsVisible) {
		DrawScreen::draw();
	}
}

/*
 * --INFO--
 * Address:	801C2704
 * Size:	000078
 */
void zen::DrawAccount::start(zen::AccountData& data)
{
	mIsVisible   = true;
	mAppearTimer = 0.0f;
	mRootPane->move(0, -1000);
	mData = data;
	PRINT("start\n");
}
