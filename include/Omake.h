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
	Creature* _10;       // _10
	Fader* mActiveFader; // _14
	f32 _18;             // _18
	f32 _1C;             // _1C
	u8 _20[0x4];         // _20, unknown
};

/**
 * @brief FABRICATED
 *
 * @note Probably corresponds to some other struct, just not sure what.
 */
struct FaderSpring {
	u16 _00; // _00
	u16 _02; // _02
	f32 _04; // _04
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
		Vector3f _00; // _00
		Vector3f _0C; // _0C
		Vector3f _18; // _18
	};

	ClothFader()
	    : AttentionCamera::Fader('clot')
	{
		_0E        = 32;
		_10        = 16;
		_0C        = _0E * _10;
		mParticles = new Particle[_0C];
		_18        = (_0E - 1) * (_10 - 1) << 2;
		mSprings   = new FaderSpring[_18];
		reset();
	}

	virtual void initFadeIn() // _08
	{
		_1C = 1.5f;
		_20 = _1C;
		reset();
		gsys->mToggleBlur = 0;
	}
	virtual void initFadeOut() // _14
	{
		_1C = 1.5f;
		_20 = _1C;
		reset();
		gsys->mToggleBlur = 0;
	}
	virtual bool updateFadeIn() // _0C
	{
		_20 -= gsys->getFrameTime();
		if (_20 <= 0.0f) {
			_20               = 0.0f;
			gsys->mToggleBlur = 1;
			return true;
		}

		simulate();
		return false;
	}
	virtual bool updateFadeOut() // _18
	{
		_20 -= gsys->getFrameTime();
		if (_20 <= 0.0f) {
			_20               = 0.0f;
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
		for (i = 0; i < _0E - 1; i++) {
			for (j = 0; j < _10 - 1; j++) {
				Vector3f vec;
				int a           = i + j * _0E;
				int b           = a;
				int c           = a + 1;
				mSprings[k]._00 = a;
				mSprings[k]._02 = c;
				vec             = mParticles[c]._00 - mParticles[b]._00;
				mSprings[k]._04 = vec.length();
				k++;

				b               = a;
				c               = a + _0E;
				mSprings[k]._00 = a;
				mSprings[k]._02 = c;
				vec             = mParticles[c]._00 - mParticles[b]._00;
				mSprings[k]._04 = vec.length();
				k++;

				b               = a;
				c               = a + 1 + _0E;
				mSprings[k]._00 = a;
				mSprings[k]._02 = c;
				vec             = mParticles[c]._00 - mParticles[b]._00;
				mSprings[k]._04 = vec.length();
				k++;

				b               = a + 1;
				c               = a + _0E;
				mSprings[k]._00 = b;
				mSprings[k]._02 = c;
				vec             = mParticles[c]._00 - mParticles[b]._00;
				mSprings[k]._04 = vec.length();
				k++;
			}
		}
	}

	void reset()
	{
		int x      = 640 / (_0E - 1);
		int y      = 480 / (_10 - 1);
		int unused = 0;
		int i, j;
		for (i = 0; i < _0E; i++) {
			for (j = 0; j < _10; j++) {
				int a = x * i;
				int b = y * j;
				mParticles[i + j * _0E]._00.set(a, b, 0.0f);
				mParticles[i + j * _0E]._0C.set(0.0f, 0.0f, 0.0f);
			}
		}

		makeSprings();

		for (i = 0; i < _0E; i++) {
			for (j = 0; j < _10; j++) {
				Vector3f vec(0.0f, 0.0f, 0.0f);
				if (i != 0 && j != 0 && i != _0E - 1 && j != _10 - 1) {
					vec.set(gsys->getRand(1.0f) - 2.0f, gsys->getRand(1.0f) - 2.0f, 0.0f);
					vec.multiply(8.0f);
					mParticles[i + j * _0E]._00.add(vec);
				}
			}
		}
	}

	// DLL inlines:
	void draw(Graphics& gfx)
	{
		// this inline has some minor issues.
		gfx.useTexture(mapMgr->mBlurredPreviousFrameTexture, 0);
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

		f32 width  = (640 / (_0E - 1)) / 640.0f;
		f32 height = (480 / (_10 - 1)) / 480.0f;

		for (int i = 0; i < _0E - 1; i++) {
			f32 x0 = width * f32(i);

			for (int j = 0; j < _10 - 1; j++) {
				f32 y0 = height * f32(j);

				int a         = i + j * _0E;
				int b         = i + (j + 1) * _0E;
				Vector3f vec1 = mParticles[i + j * _0E]._00;
				Vector3f vec2 = mParticles[i + 1 + j * _0E]._00;
				Vector3f vec3 = mParticles[i + (j + 1) * _0E]._00;
				Vector3f vec4 = mParticles[i + 1 + (j + 1) * _0E]._00;

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
		for (i = 0; i < _0C; i++) {
			mParticles[i]._18.set(0.0f, 400.0f, 0.0f);
		}

		for (i = 0; i < _18; i++) {
			FaderSpring* spring = &mSprings[i];
			int a               = spring->_00;
			int b               = spring->_02;
			Particle* ptcl0     = &mParticles[a];
			Particle* ptcl2     = &mParticles[b];
			Vector3f vec1       = ptcl0->_00 - ptcl2->_00;
			f32 dist            = vec1.normalise();
			f32 v               = spring->_04;
			ptcl0->_18          = ptcl0->_18 - ((dist - spring->_04) * 10.0f) * vec1;
			ptcl2->_18          = ptcl2->_18 + ((dist - spring->_04) * 10.0f) * vec1;
		}

		for (i = 0; i < _0C; i++) {
			Particle* ptcl = &mParticles[i];
			ptcl->_00      = ptcl->_00 + ptcl->_0C * fTime;
			ptcl->_0C      = ptcl->_0C + ptcl->_18 * fTime;
		}
	}

	// _04     = VTBL
	// _00-_08 = AttentionCamera::Fader
	Particle* mParticles;  // _08
	u16 _0C;               // _0C
	u16 _0E;               // _0E
	u16 _10;               // _10
	FaderSpring* mSprings; // _14
	u16 _18;               // _18
	f32 _1C;               // _1C
	f32 _20;               // _20
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
		_0C = 0.5f;
		_08 = _0C;
	}
	virtual void initFadeOut() // _14
	{
		_0C = 0.5f;
		_08 = _0C;
	}
	virtual bool updateFadeIn() // _0C
	{
		_08 -= gsys->getFrameTime();
		if (_08 <= 0.0f) {
			_08 = 0.0f;
			return true;
		}

		return false;
	}
	virtual bool updateFadeOut() // _18
	{
		_08 -= gsys->getFrameTime();
		if (_08 <= 0.0f) {
			_08 = 0.0f;
			return true;
		}

		return false;
	}
	virtual void drawFadeOut(Graphics& gfx) // _1C
	{
		int alpha = (1.0f - _08 / _0C) * 255.0f;
		gfx.setColour(Colour(255, 255, 255, alpha), true);
		u32 badCompiler[4];

		gfx.setAuxColour(Colour(255, 255, 255, alpha));
		gfx.useTexture(mapMgr->mBlurredPreviousFrameTexture, 0);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
		GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);

		RectArea area1(0, 0, 640, 480);
		gfx.drawRectangle(area1, RectArea(0, 0, 320, 240), nullptr);
	}
	virtual void drawFadeIn(Graphics& gfx) // _10
	{
		int alpha = (_08 / _0C) * 255.0f;
		gfx.setColour(Colour(255, 255, 255, alpha), true);
		u32 badCompiler[4];

		gfx.setAuxColour(Colour(255, 255, 255, alpha));
		gfx.useTexture(mapMgr->mBlurredPreviousFrameTexture, 0);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
		GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);

		RectArea area1(0, 0, 640, 480);
		gfx.drawRectangle(area1, RectArea(0, 0, 320, 240), nullptr);
	}

	// _04     = VTBL
	// _00-_08 = AttentionCamera::Fader
	f32 _08; // _08
	f32 _0C; // _0C
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
		_0C = 0.5f;
		_08 = _0C;
	}
	virtual bool updateFadeIn() // _0C
	{
		_08 -= gsys->getFrameTime();
		if (_08 <= 0.0f) {
			_08 = 0.0f;
			return true;
		}

		return false;
	}
	virtual void drawFadeOut(Graphics& gfx) // _1C
	{
		f32 t = (1.0f - _08 / _0C);
		int x = t * 320.0f;
		int y = t * 240.0f;
		RectArea area1(0, 0, 640, 480);
		gfx.setColour(Colour(0, 0, 0, 255), true);
		gfx.setAuxColour(Colour(0, 0, 0, 255));
		gfx.useTexture(nullptr, 0);
		gfx.fillRectangle(area1);

		gfx.setColour(Colour(255, 255, 255, 255), true);
		gfx.setAuxColour(Colour(255, 255, 255, 255));
		gfx.useTexture(mapMgr->mBlurredPreviousFrameTexture, 0);

		RectArea area2(x, y, 640 - x, 480 - y);
		gfx.drawRectangle(area2, RectArea(0, 0, 320, 240), nullptr);
	}
	virtual void initFadeOut() // _14
	{
		_0C = 0.5f;
		_08 = _0C;
	}
	virtual bool updateFadeOut() // _18
	{
		_08 -= gsys->getFrameTime();
		if (_08 <= 0.0f) {
			_08 = 0.0f;
			return true;
		}

		return false;
	}
	virtual void drawFadeIn(Graphics& gfx) // _10
	{
		f32 t = (_08 / _0C);
		int x = t * 320.0f;
		int y = t * 240.0f;
		RectArea area1(0, 0, 640, 480);
		gfx.setColour(Colour(0, 0, 0, 255), true);
		gfx.setAuxColour(Colour(0, 0, 0, 255));
		gfx.useTexture(nullptr, 0);
		gfx.fillRectangle(area1);

		gfx.setColour(Colour(255, 255, 255, 255), true);
		gfx.setAuxColour(Colour(255, 255, 255, 255));
		gfx.useTexture(mapMgr->mBlurredPreviousFrameTexture, 0);

		RectArea area2(x, y, 640 - x, 480 - y);
		gfx.drawRectangle(area2, RectArea(0, 0, 320, 240), nullptr);
	}

	// _04     = VTBL
	// _00-_08 = AttentionCamera::Fader
	f32 _08; // _08
	f32 _0C; // _0C
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
	int _08; // _08
	f32 _0C; // _0C
};

extern AttentionCamera* attentionCamera;

#endif
