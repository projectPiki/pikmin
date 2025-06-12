#include "Piki.h"
#include "Route.h"
#include "PlayerState.h"
#include "PikiState.h"
#include "MapMgr.h"
#include "PikiMgr.h"
#include "PikiHeadItem.h"
#include "MapCode.h"
#include "EffectMgr.h"
#include "GameStat.h"
#include "SoundMgr.h"
#include "FlowController.h"
#include "DebugLog.h"
#include "PikiAI.h"

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
DEFINE_PRINT("pikidoKill");

/*
 * --INFO--
 * Address:	800CD950
 * Size:	000380
 */
void Piki::doKill()
{
	if (mRouteHandle) {
		routeMgr->getPathFinder('test')->releaseHandle(mRouteHandle);
		mRouteHandle         = 0;
		mUseAsyncPathfinding = 0;
	}

	mLookAtTarget.clear();

	if (mIsPanicked) {
		mPanickedEffect->kill();
		mIsPanicked = false;
	}

	mBurnEffect->kill();
	mRippleEffect->kill();
	mFreeLightEffect->kill();

	if (pikiUpdateMgr) {
		mPikiUpdateContext.exit();
	}
	if (pikiLookUpdateMgr) {
		mPikiLookUpdateContext.exit();
	}
	if (pikiOptUpdateMgr) {
		mOptUpdateContext.exit();
	}

	// Check if the lost pikmin should leave a seed behind
	int state = getState();
	if (!playerState->mInDayEnd && state != PIKISTATE_Swallowed && mHappa == Flower && mMode != PikiMode::EnterMode && !mEraseOnKill) {
		CollTriInfo* tri = mapMgr->getCurrTri(mPosition.x, mPosition.z, true);
		if (tri && !MapCode::isBald(tri) && isSafeMePos(mPosition) && MapCode::getAttribute(tri) != ATTR_Water) {
			if (gsys->getRand(1.0f) >= pikiMgr->mPikiParms->mPikiParms.mPikiLeaveSeedChance()) {
				PikiHeadItem* item = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead);
				if (item) {
					StageInf* inf = &flowCont.mCurrentStage->mStageInf;

					Vector3f pos = mPosition;
					pos.y        = mapMgr->getMinY(pos.x, pos.z, true);
					item->init(pos);

					item->setColor(mColor);
					BaseInf* binf = inf->mBPikiInfMgr.getFreeInf();
					if (binf) {
						PRINT("花ピキを残しました！\n"); // I left Hanapiki!
						binf->store(item);
					} else {
						PRINT("空きがないので残しません!\n"); // I won't leave it because there's no space left.
					}
					item->kill(false);
				}
			}
		}
	}

	if (!mEraseOnKill) {
		f32 max = mapMgr->getMaxY(mShadowPos.x, mShadowPos.z, true);
#if 0 // the DLL seems to do more here
		f32 y   = mShadowPos.y;
		if (max > mShadowPos.y) {
			y = max;
		}
		Vector3f pos(mShadowPos.x, y, mShadowPos.z);
		effectMgr->create(EffectMgr::EFF_Piki_DeadSoul, pos, nullptr, nullptr);
#else
		effectMgr->create(EffectMgr::EFF_Piki_DeadSoul, mShadowPos, nullptr, nullptr);
#endif
		seSystem->playSoundDirect(1, SE_PIKI_DEAD, mPosition);
		GameStat::deadPikis.inc(mColor);
	}

	if (mActiveAction) {
		mActiveAction->abandon(nullptr);
	}

	GameStat::workPikis.dec(mColor);
	GameStat::update();
	mFSM->transit(this, PIKISTATE_Dead);
	_500.clear();
	pikiMgr->mDeadPikis++;
	pikiMgr->kill(this);

	STACK_PAD_VAR(10);
}
