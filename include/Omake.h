#ifndef _OMAKE_H
#define _OMAKE_H

#include "types.h"
#include "Vector.h"

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
		virtual void initFadeIn();           // _08
		virtual bool updateFadeIn();         // _0C
		virtual void drawFadeIn(Graphics&);  // _10
		virtual void initFadeOut();          // _14
		virtual bool updateFadeOut();        // _18
		virtual void drawFadeOut(Graphics&); // _1C

		// _00 = VTBL?
		// TODO: work out members
	};

	AttentionCamera();

	void finish();
	void update();
	void refresh(Graphics&);

	// unused/inlined:
	void start(u32, Creature*, f32, f32);
	void setFader(u32);

	// TODO: work out members
};

/**
 * @brief TODO
 */
struct ClothFader : public AttentionCamera::Fader {

	/**
	 * @brief TODO
	 */
	struct Particle {
		Particle();

		Vector3f _00; // _00
		Vector3f _0C; // _0C
		Vector3f _18; // _18
	};

	void reset();

	virtual void initFadeIn();           // _08
	virtual bool updateFadeIn();         // _0C
	virtual void drawFadeIn(Graphics&);  // _10
	virtual void initFadeOut();          // _14
	virtual bool updateFadeOut();        // _18
	virtual void drawFadeOut(Graphics&); // _1C

	void makeSprings();

	// _00 = VTBL?
	// TODO: work out members
};

/**
 * @brief TODO
 */
struct SimpleFader : public AttentionCamera::Fader {
	void reset();

	virtual void initFadeIn();           // _08
	virtual bool updateFadeIn();         // _0C
	virtual void drawFadeIn(Graphics&);  // _10
	virtual void initFadeOut();          // _14
	virtual bool updateFadeOut();        // _18
	virtual void drawFadeOut(Graphics&); // _1C

	// _00 = VTBL?
	// TODO: work out members
};

/**
 * @brief TODO
 */
struct DefaultFader : public AttentionCamera::Fader {
	void reset();

	virtual void initFadeIn();           // _08
	virtual bool updateFadeIn();         // _0C
	virtual void drawFadeIn(Graphics&);  // _10
	virtual void initFadeOut();          // _14
	virtual bool updateFadeOut();        // _18
	virtual void drawFadeOut(Graphics&); // _1C

	// _00 = VTBL?
	// TODO: work out members
};

/**
 * @brief TODO
 *
 * @note Completely inlined struct, possibly needed in omake.cpp
 */
struct NoiseFunction {
	void init(int);
	f32 getValue(f32);
};

/**
 * @brief TODO
 *
 * @note Completely inlined struct, possibly needed in omake.cpp
 */
struct TurbulenceFun {
	void init(int, int);
	f32 getValue(f32);
};

extern AttentionCamera* attentionCamera;

#endif
