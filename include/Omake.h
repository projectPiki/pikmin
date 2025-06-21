#ifndef _OMAKE_H
#define _OMAKE_H

#include "types.h"
#include "Vector.h"
#include "system.h"
#include "Graphics.h"
#include "MapMgr.h"

struct Creature;
struct Graphics;

/**
 * @brief TODO
 */
struct AttentionCamera {

	/**
	 * @brief TODO
	 */
	struct Fader {
		Fader(u32 tag)
		    : mTag(tag)
		{
		}

		// _04 = VTBL
		u32 mTag; // _04

		virtual void initFadeIn() { }                 // _08
		virtual bool updateFadeIn() { return true; }  // _0C
		virtual void drawFadeIn(Graphics&) { }        // _10
		virtual void initFadeOut() { }                // _14
		virtual bool updateFadeOut() { return true; } // _18
		virtual void drawFadeOut(Graphics&) { }       // _1C
	};

	AttentionCamera();

	void finish();
	void update();
	void refresh(Graphics&);

	// unused/inlined:
	void start(u32, Creature*, f32, f32);
	void setFader(u32);

	Fader** mFaders;     // _00
	int mMaxFaders;      // _04
	int mFaderCount;     // _08
	u16 mFadeState;      // _0C
	Creature* mTarget;   // _10
	Fader* mActiveFader; // _14
	f32 _UNUSED18;       // _18
	f32 _UNUSED1C;       // _1C
	u8 _UNUSED20[0x4];   // _20
};

/**
 * @brief FABRICATED
 *
 * @note Probably corresponds to some other struct, just not sure what.
 */
struct FaderSpring {
	u16 mPtclIndexA; // _00
	u16 mPtclIndexB; // _02
	f32 mRestLength; // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct ClothFader : public AttentionCamera::Fader {

	/**
	 * @brief TODO
	 */
	struct Particle {
		Vector3f mPosition; // _00
		Vector3f mVelocity; // _0C
		Vector3f mForce;    // _18
	};

	ClothFader()
	    : AttentionCamera::Fader('clot')
	{
		mGridWidth     = 32;
		mGridHeight    = 16;
		mParticleCount = mGridWidth * mGridHeight;
		mParticles     = new Particle[mParticleCount];
		mSpringCount   = (mGridWidth - 1) * (mGridHeight - 1) << 2;
		mSprings       = new FaderSpring[mSpringCount];
		reset();
	}

	virtual void initFadeIn() // _08
	{
		mFadeDuration = 1.5f;
		mFadeTimer    = mFadeDuration;
		reset();
		gsys->mToggleBlur = 0;

		STACK_PAD_VAR(2);
	}
	virtual void initFadeOut() // _14
	{
		mFadeDuration = 1.5f;
		mFadeTimer    = mFadeDuration;
		reset();
		gsys->mToggleBlur = 0;

		STACK_PAD_VAR(2);
	}
	virtual bool updateFadeIn() // _0C
	{
		mFadeTimer -= gsys->getFrameTime();
		if (mFadeTimer <= 0.0f) {
			mFadeTimer        = 0.0f;
			gsys->mToggleBlur = 1;
			return true;
		}

		simulate();
		return false;
	}
	virtual bool updateFadeOut() // _18
	{
		mFadeTimer -= gsys->getFrameTime();
		if (mFadeTimer <= 0.0f) {
			mFadeTimer        = 0.0f;
			gsys->mToggleBlur = 1;
			return true;
		}

		simulate();
		return false;
	}
	virtual void drawFadeOut(Graphics& gfx) { draw(gfx); } // _1C
	virtual void drawFadeIn(Graphics& gfx) { draw(gfx); }  // _10

	void makeSprings()
	{
		int i, j, k;

		k = 0;
		for (i = 0; i < mGridWidth - 1; i++) {
			for (j = 0; j < mGridHeight - 1; j++) {
				Vector3f vec;
				int a                   = i + j * mGridWidth;
				int b                   = a;
				int c                   = a + 1;
				mSprings[k].mPtclIndexA = a;
				mSprings[k].mPtclIndexB = c;
				vec                     = mParticles[c].mPosition - mParticles[b].mPosition;
				mSprings[k].mRestLength = vec.length();
				k++;

				b                       = a;
				c                       = a + mGridWidth;
				mSprings[k].mPtclIndexA = a;
				mSprings[k].mPtclIndexB = c;
				vec                     = mParticles[c].mPosition - mParticles[b].mPosition;
				mSprings[k].mRestLength = vec.length();
				k++;

				b                       = a;
				c                       = a + 1 + mGridWidth;
				mSprings[k].mPtclIndexA = a;
				mSprings[k].mPtclIndexB = c;
				vec                     = mParticles[c].mPosition - mParticles[b].mPosition;
				mSprings[k].mRestLength = vec.length();
				k++;

				b                       = a + 1;
				c                       = a + mGridWidth;
				mSprings[k].mPtclIndexA = b;
				mSprings[k].mPtclIndexB = c;
				vec                     = mParticles[c].mPosition - mParticles[b].mPosition;
				mSprings[k].mRestLength = vec.length();
				k++;
			}
		}
	}

	void reset()
	{
		int x = 640 / (mGridWidth - 1);
		int y = 480 / (mGridHeight - 1);
		int i, j;
		for (i = 0; i < mGridWidth; i++) {
			for (j = 0; j < mGridHeight; j++) {
				mParticles[i + j * mGridWidth].mPosition.set(x * i, y * j, 0.0f);
				mParticles[i + j * mGridWidth].mVelocity.set(0.0f, 0.0f, 0.0f);
			}
		}

		makeSprings();

		for (i = 0; i < mGridWidth; i++) {
			for (j = 0; j < mGridHeight; j++) {
				Vector3f vec(0.0f, 0.0f, 0.0f);
				if (i != 0 && j != 0 && i != mGridWidth - 1 && j != mGridHeight - 1) {
					vec.set(gsys->getRand(1.0f) - 2.0f, gsys->getRand(1.0f) - 2.0f, 0.0f);
					vec.multiply(8.0f);
					mParticles[i + j * mGridWidth].mPosition.add(vec);
				}
			}
		}
	}

	// DLL inlines:
	void draw(Graphics& gfx)
	{
		// this inline has some minor issues.
		gfx.useTexture(mapMgr->mBlurredTexture, 0);
		GXClearVtxDesc();
		GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
		GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
		GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
		GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
		GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);

		Colour col;
		col.set(255, 255, 255, 255);
		u32 uCol = *(u32*)&col;

		f32 width  = (640 / (mGridWidth - 1)) / 640.0f;
		f32 height = (480 / (mGridHeight - 1)) / 480.0f;
		for (int i = 0; i < mGridWidth - 1; i++) {

			for (int j = 0; j < mGridHeight - 1; j++) {

				Vector3f vec1 = mParticles[j * mGridWidth + i].mPosition;
				Vector3f vec2 = mParticles[i + 1 + j * mGridWidth].mPosition;
				Vector3f vec3 = mParticles[(j + 1) * mGridWidth + i].mPosition;
				Vector3f vec4 = mParticles[i + 1 + (j + 1) * mGridWidth].mPosition;

				f32 x0 = width * i;
				f32 y0 = height * j;

				f32 a = x0;

				GXBegin(GX_QUADS, GX_VTXFMT0, 4);
				GXPosition3f32(vec1.x, vec1.y, vec1.z);
				GXColor1u32(uCol);
				GXPosition2f32(x0, y0);

				GXPosition3f32(vec2.x, vec2.y, vec2.z);
				GXColor1u32(uCol);
				GXPosition2f32(x0 + width, y0);

				GXPosition3f32(vec4.x, vec4.y, vec4.z);
				GXColor1u32(uCol);
				GXPosition2f32(x0 + width, y0 + height);

				GXPosition3f32(vec3.x, vec3.y, vec3.z);
				GXColor1u32(uCol);
				GXPosition2f32(x0, y0 + height);
			}
		}
	}

	void simulate()
	{
		int i;
		f32 fTime = gsys->getFrameTime();
		for (i = 0; i < mParticleCount; i++) {
			mParticles[i].mForce.set(0.0f, 400.0f, 0.0f);
		}

		for (i = 0; i < mSpringCount; i++) {
			FaderSpring* spring = &mSprings[i];
			int a               = spring->mPtclIndexA;
			int b               = spring->mPtclIndexB;
			Particle* ptcl0     = &mParticles[a];
			Particle* ptcl2     = &mParticles[b];
			Vector3f vec1       = ptcl0->mPosition - ptcl2->mPosition;
			f32 dist            = vec1.normalise();
			f32 v               = spring->mRestLength;
			ptcl0->mForce       = ptcl0->mForce - ((dist - spring->mRestLength) * 10.0f) * vec1;
			ptcl2->mForce       = ptcl2->mForce + ((dist - spring->mRestLength) * 10.0f) * vec1;
		}

		for (i = 0; i < mParticleCount; i++) {
			Particle* ptcl  = &mParticles[i];
			ptcl->mPosition = ptcl->mPosition + ptcl->mVelocity * fTime;
			ptcl->mVelocity = ptcl->mVelocity + ptcl->mForce * fTime;
		}
	}

	// _04     = VTBL
	// _00-_08 = AttentionCamera::Fader
	Particle* mParticles;  // _08
	u16 mParticleCount;    // _0C
	u16 mGridWidth;        // _0E
	u16 mGridHeight;       // _10
	FaderSpring* mSprings; // _14
	u16 mSpringCount;      // _18
	f32 mFadeDuration;     // _1C
	f32 mFadeTimer;        // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct SimpleFader : public AttentionCamera::Fader {
	SimpleFader()
	    : AttentionCamera::Fader('smpl')
	{
	}

	virtual void initFadeIn() // _08
	{
		mFadeDuration = 0.5f;
		mFadeTimer    = mFadeDuration;
	}
	virtual void initFadeOut() // _14
	{
		mFadeDuration = 0.5f;
		mFadeTimer    = mFadeDuration;
	}
	virtual bool updateFadeIn() // _0C
	{
		mFadeTimer -= gsys->getFrameTime();
		if (mFadeTimer <= 0.0f) {
			mFadeTimer = 0.0f;
			return true;
		}

		return false;
	}
	virtual bool updateFadeOut() // _18
	{
		mFadeTimer -= gsys->getFrameTime();
		if (mFadeTimer <= 0.0f) {
			mFadeTimer = 0.0f;
			return true;
		}

		return false;
	}
	virtual void drawFadeOut(Graphics& gfx) // _1C
	{
		int alpha = (1.0f - mFadeTimer / mFadeDuration) * 255.0f;
		gfx.setColour(Colour(255, 255, 255, alpha), true);
		STACK_PAD_VAR(4);

		gfx.setAuxColour(Colour(255, 255, 255, alpha));
		gfx.useTexture(mapMgr->mBlurredTexture, 0);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
		GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);

		RectArea area1(0, 0, 640, 480);
		gfx.drawRectangle(area1, RectArea(0, 0, 320, 240), nullptr);
	}
	virtual void drawFadeIn(Graphics& gfx) // _10
	{
		int alpha = (mFadeTimer / mFadeDuration) * 255.0f;
		gfx.setColour(Colour(255, 255, 255, alpha), true);
		STACK_PAD_VAR(4);

		gfx.setAuxColour(Colour(255, 255, 255, alpha));
		gfx.useTexture(mapMgr->mBlurredTexture, 0);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
		GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);

		RectArea area1(0, 0, 640, 480);
		gfx.drawRectangle(area1, RectArea(0, 0, 320, 240), nullptr);
	}

	// _04     = VTBL
	// _00-_08 = AttentionCamera::Fader
	f32 mFadeTimer;    // _08
	f32 mFadeDuration; // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct DefaultFader : public AttentionCamera::Fader {
	DefaultFader()
	    : AttentionCamera::Fader('dflt')
	{
	}

	virtual void initFadeIn() // _08
	{
		mFadeDuration = 0.5f;
		mFadeTimer    = mFadeDuration;
	}
	virtual bool updateFadeIn() // _0C
	{
		mFadeTimer -= gsys->getFrameTime();
		if (mFadeTimer <= 0.0f) {
			mFadeTimer = 0.0f;
			return true;
		}

		return false;
	}
	virtual void drawFadeOut(Graphics& gfx) // _1C
	{
		f32 t = (1.0f - mFadeTimer / mFadeDuration);
		int x = t * 320.0f;
		int y = t * 240.0f;
		RectArea area1(0, 0, 640, 480);
		gfx.setColour(Colour(0, 0, 0, 255), true);
		gfx.setAuxColour(Colour(0, 0, 0, 255));
		gfx.useTexture(nullptr, 0);
		gfx.fillRectangle(area1);

		gfx.setColour(Colour(255, 255, 255, 255), true);
		gfx.setAuxColour(Colour(255, 255, 255, 255));
		gfx.useTexture(mapMgr->mBlurredTexture, 0);

		RectArea area2(x, y, 640 - x, 480 - y);
		gfx.drawRectangle(area2, RectArea(0, 0, 320, 240), nullptr);
	}
	virtual void initFadeOut() // _14
	{
		mFadeDuration = 0.5f;
		mFadeTimer    = mFadeDuration;
	}
	virtual bool updateFadeOut() // _18
	{
		mFadeTimer -= gsys->getFrameTime();
		if (mFadeTimer <= 0.0f) {
			mFadeTimer = 0.0f;
			return true;
		}

		return false;
	}
	virtual void drawFadeIn(Graphics& gfx) // _10
	{
		f32 t = (mFadeTimer / mFadeDuration);
		int x = t * 320.0f;
		int y = t * 240.0f;
		RectArea area1(0, 0, 640, 480);
		gfx.setColour(Colour(0, 0, 0, 255), true);
		gfx.setAuxColour(Colour(0, 0, 0, 255));
		gfx.useTexture(nullptr, 0);
		gfx.fillRectangle(area1);

		gfx.setColour(Colour(255, 255, 255, 255), true);
		gfx.setAuxColour(Colour(255, 255, 255, 255));
		gfx.useTexture(mapMgr->mBlurredTexture, 0);

		RectArea area2(x, y, 640 - x, 480 - y);
		gfx.drawRectangle(area2, RectArea(0, 0, 320, 240), nullptr);
	}

	// _04     = VTBL
	// _00-_08 = AttentionCamera::Fader
	f32 mFadeTimer;    // _08
	f32 mFadeDuration; // _0C
};

/**
 * @brief TODO
 *
 * @note Completely inlined struct, possibly needed in omake.cpp
 */
struct NoiseFunction {
	void init(int);
	f32 getValue(f32);

	int mCount;   // _00
	f32* mValues; // _04
};

/**
 * @brief TODO
 *
 * @note Completely inlined struct, possibly needed in omake.cpp
 */
struct TurbulenceFun : public NoiseFunction {
	void init(int, int);
	f32 getValue(f32);

	// _00-_08 = NoiseFunction
	int _UNUSED08;  // _08
	f32 mFrequency; // _0C
};

extern AttentionCamera* attentionCamera;

#endif
