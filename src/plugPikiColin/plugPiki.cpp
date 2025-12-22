#include "App.h"
#include "AtxStream.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Interface.h"
#include "gameflow.h"
#include "sysNew.h"
#include "timers.h"

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
DEFINE_PRINT("plugPiki")

/**
 * @TODO: Documentation
 */
void PlugPikiApp::hardReset()
{
	useHeap(0);
	gsys->mTimer = new Timers;
	gameflow.hardReset(this);
	AyuHeap* heap = gsys->getHeap(SYSHEAP_Sys);
	int max       = heap->getMaxFree();
	int type      = heap->setAllocType(AYU_STACK_GROW_UP);
	u8* buf       = new u8[heap->getMaxFree()];
	heap->setAllocType(type);

	gsys->getHeap(SYSHEAP_Ovl)->init("ovl", AYU_STACK_GROW_UP, buf, max);

	gsys->resetHeap(SYSHEAP_Ovl, 1);
	gsys->getHeap(SYSHEAP_Ovl)->setAllocType(AYU_STACK_GROW_DOWN);
	useHeap(SYSHEAP_Ovl);
	gsys->softReset();
}

/**
 * @TODO: Documentation
 */
void PlugPikiApp::softReset()
{
	BaseApp::softReset();
	gameflow.softReset();
	mIsReadyToDraw = TRUE;
}

/**
 * @TODO: Documentation
 */
void PlugPikiApp::update()
{
	gameflow.mAppTickCounter++;
	gameflow.update();
	Node::update();
}

/**
 * @TODO: Documentation
 */
void PlugPikiApp::draw(Graphics& gfx)
{
	if (!mIsReadyToDraw) {
		return;
	}

	gsys->mTimer->start("cpu draw", true);
	gsys->mDispCount        = 0;
	gsys->mMaterialCount    = 0;
	gsys->mPolygonCount     = 0;
	gsys->mActiveLightCount = 0;
	gsys->mLightCount       = 0;
	gsys->mAnimatedPolygons = 0;
	gsys->mLightingSkips    = 0;
	gsys->mLightingSets     = 0;
	gsys->mLightSetNum      = 0;
	Node::draw(gfx);

	Matrix4f mtx;
	gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gfx.useTexture(nullptr, GX_TEXMAP0);

	if (gsys->mTimerState) {
		gfx.setColour(Colour(255, 255, 255, 255), true);
		gfx.texturePrintf(gsys->mConsFont, 32, 32, "%d polys = %d pps", gsys->mPolygonCount,
		                  int(gsys->mPolygonCount * gsys->getFrameRate()));
		gfx.texturePrintf(gsys->mConsFont, 32, 44, "%d anims", gsys->mAnimatedPolygons);
		gfx.texturePrintf(gsys->mConsFont, 32, 56, "%d mats", gsys->mMaterialCount);
		gfx.texturePrintf(gsys->mConsFont, 32, 68, "%d disps", gsys->mDispCount);
		gfx.texturePrintf(gsys->mConsFont, 32, 80, "%d mtxs", gsys->mDGXGfx->mActiveMatrixIdx);
		gfx.texturePrintf(gsys->mConsFont, 32, 92, "%d / %d lighting skips / sets", gsys->mLightingSkips, gsys->mLightingSets);
		gfx.texturePrintf(gsys->mConsFont, 32, 104, "%d light sets", gsys->mLightSetNum);
	}

	if (gameflow.mCurrentEffectAlpha > 0.0f || gameflow.mTargetEffectAlpha > 0.0f) {
		gameflow.mEffectDurationTimer -= gsys->getFrameTime();
		if (gameflow.mEffectDurationTimer < 0.0f) {
			gameflow.mTargetEffectAlpha = 0.0f;
		}

		gameflow.mCurrentEffectAlpha += gsys->getFrameTime() * 1.0f * (gameflow.mTargetEffectAlpha - gameflow.mCurrentEffectAlpha);
		if (quickABS(gameflow.mCurrentEffectAlpha - gameflow.mTargetEffectAlpha) < 0.1f) {
			gameflow.mCurrentEffectAlpha = gameflow.mTargetEffectAlpha;
		}

		gfx.setColour(Colour(192, 255, 255, gameflow.mCurrentEffectAlpha), true);
		gfx.setAuxColour(Colour(192, 192, 255, gameflow.mCurrentEffectAlpha));
		char buf[PATH_MAX];
		sprintf(buf, "load took %.1f secs", gameflow.mLoadTimeSeconds);
	}

	gfx.useTexture(nullptr, GX_TEXMAP0);
	if (gsys->mCurrentFade < gsys->mFadeStart) {
		gsys->mCurrentFade += gsys->getFrameTime() * gsys->mFadeEnd;
		if (gsys->mCurrentFade > gsys->mFadeStart) {
			gsys->mCurrentFade = gsys->mFadeStart;
		}
	} else if (gsys->mCurrentFade > gsys->mFadeStart) {
		gsys->mCurrentFade = gsys->mFadeStart;
		gsys->mCurrentFade -= gsys->getFrameTime() * gsys->mFadeEnd;
		if (gsys->mCurrentFade < gsys->mFadeStart) {
			gsys->mCurrentFade = gsys->mFadeStart;
		}
	}

	if (gsys->mTimerState) {
		gsys->mTimer->draw(gfx, gsys->mConsFont);
	}

	gsys->mTimer->stop("cpu draw");
}

/**
 * @TODO: Documentation
 */
int PlugPikiApp::idle()
{
	gsys->setHeap(mHeapIndex);
	gsys->mTimer->newFrame();
	gsys->mTimer->_start("all", false);

	gsys->mIsRendering; // lol
	if (gsys->mSysOpPending) {
		gsys->detachObjs();
		gsys->mTimer->reset();
		gsys->mSysOpPending = false;
		softReset();
		PRINT("idle attach\n");
		gsys->attachObjs();
		PRINT("done attaching objs!\n");
		return 1;
	}
	update();
	gsys->beginRender();
	renderall();
	if (gsys->mDvdErrorCallback) {
		gsys->mDvdErrorCallback->invoke(*gsys->mDGXGfx);
	}
	gsys->mTimer->start("render", true);
	gsys->doneRender();
	gsys->mTimer->stop("render");
	if (gameflow.mGameInterface) {
		gameflow.mGameInterface->parseMessages();
	}
	gsys->mTimer->_stop("all");
	gsys->waitRetrace();
	gsys->setHeap(-1);
	return 1;
}

/**
 * @TODO: Documentation
 */
PlugPikiApp::PlugPikiApp()
{
	setName("Piki the Game");
	gsys->setHeap(SYSHEAP_Sys);
	hardReset();
	mCommandStream = new AtxCommandStream(this);
	if (mCommandStream->open("app", 3)) {
		mCommandStream->mPath = Name();
	} else {
		mCommandStream = nullptr;
	}
	gsys->mTimerState = 1;
	gsys->hardReset();
	PRINT("*--------------- <%s> after all system setup %.2fk free \n", gsys->getHeap(gsys->mActiveHeapIdx)->mName,
	      gsys->getHeap(gsys->mActiveHeapIdx)->getFree() / 1024.0f);
	gsys->mForcePrint = FALSE;
	gsys->setHeap(-1);
}
