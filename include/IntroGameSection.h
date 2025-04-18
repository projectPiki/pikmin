#ifndef _INTROGAMESECTION_H
#define _INTROGAMESECTION_H

#include "types.h"
#include "Section.h"
#include "Camera.h"
#include "DayMgr.h"
#include "system.h"
#include "gameflow.h"
#include "EffectMgr.h"
#include "MoviePlayer.h"
#include "Graphics.h"
#include "jaudio/PikiScene.h"
#include "ModeState.h"

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct IntroGameSection : public Section {
	IntroGameSection();

	virtual void init(); // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

/**
 * @brief TODO
 */
struct IntroGameSetupSection : public BaseGameSection {
	IntroGameSetupSection()
	{
		_34 = new IntroModeState(this);

		Vector3f v1(0.0f, 0.0f, 0.0f);
		Vector3f v2(0.0f, 0.0f, 0.0f);
		gameflow.mMoviePlayer->setGameCamInfo(false, 60.0f, v2, v1);

		_3A4          = true;
		gameflow._1E4 = 0;
		_44           = 0;
		_38           = 0;
		Jac_SceneSetup(11, 0);
		EffectMgr* mgr  = new EffectMgr;
		mgr->mDoCulling = 0;
		_39C            = new DayMgr(nullptr, mController);

		int size     = 0x500000;
		void* memory = System::alloc(size);
		gsys->mHeaps[SYSHEAP_Movie].init("movie", 2, memory, size);
		gameflow.mMoviePlayer->startMovie(1, 0, nullptr, nullptr, nullptr, -1, true);
		gameflow.mMoviePlayer->startMovie(2, 0, nullptr, nullptr, nullptr, -1, true);
		gsys->setFade(1.0f, 3.0f);
	}

	void mainRender(Graphics& gfx)
	{
		gfx.setViewport(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setScissor(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setClearColour(Colour(0, 0, 0, 0));
		gfx.clearBuffer(3, 0);
		gfx.setPerspective(gfx.mCamera->mPerspectiveMatrix.mMtx, gfx.mCamera->mFov, gfx.mCamera->mAspectRatio, gfx.mCamera->mNear,
		                   gfx.mCamera->mFar, 1.0f);
		gfx.useMatrix(Matrix4f::ident, 0);
		_39C->refresh(gfx, 25.0f, 8);
		_39C->setFog(gfx, nullptr);
		gfx.calcLighting(1.0f);
		gameflow.mMoviePlayer->refresh(gfx);
		gfx.useMatrix(Matrix4f::ident, 0);
		gfx.flushCachedShapes();
	}

	void postRender(Graphics& gfx)
	{
		gfx.setPerspective(gfx.mCamera->mLookAtMtx.mMtx, 60.0f, gfx.mCamera->mAspectRatio, 1.0f, gfx.mCamera->mFar, 1.0f);

		Matrix4f mtx;
		mtx.makeSRT(Vector3f(0.1f, 0.1f, 0.1f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
		Matrix4f mtx2;
		gfx.mRenderState = 0x700;
		_34->postRender(gfx);
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	}

	virtual void update();        // _10
	virtual void draw(Graphics&); // _14

	// _00     = VTBL
	// _00-_44 = BaseGameSection
	u32 _44;      // _44
	u32 _48;      // _48
	u32 _4C;      // _4C
	Camera _50;   // _50
	f32 _398;     // _398
	DayMgr* _39C; // _39C
	u32 _3A0;     // _3A0
	u8 _3A4;      // _3A4
};

#endif
