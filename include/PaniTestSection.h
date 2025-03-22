#ifndef _PANITESTSECTION_H
#define _PANITESTSECTION_H

#include "types.h"
#include "Section.h"
#include "PaniAnimator.h"
#include "Camera.h"
#include "Light.h"

struct PaniAnimKeyEvent;
struct Teki;
struct ViewPiki;
struct Piki;
struct Font;
struct PcamCameraManager;

/**
 * @brief TODO
 */
enum PaniTestMode {
	PANITEST_Piki = 0,
	PANITEST_Teki = 1,
};

/**
 * @brief TODO
 *
 * @note Size: 0x694.
 */
struct PaniTestNode : public Node, public PaniAnimKeyListener {
	PaniTestNode();

	virtual void update();                               // _10
	virtual void draw(Graphics&);                        // _14
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _3C

	void setTestMode(int);
	void updatePikis();
	void updateTekis();
	void drawPiki(ViewPiki*, Graphics&);
	void drawTeki(Teki*, Graphics&);

	// _00     = VTBL
	// _00-_20 = Node
	// _20-_24 = PaniAnimKeyListener
	PcamCameraManager* mCamMgr; // _24
	u32 _28;                    // _28, unknown
	Controller* mController;    // _2C
	Font* mConsFont;            // _30, maybe an array if Font has members with ctors
	u8 _34[0x4];                // _34, unknown
	Camera mActiveCamera;       // _38
	u8 _380[0x8];               // _380, unknown (may be part of Camera)
	Texture* mShadowTexture;    // _388
	Colour _38C;                // _38C
	Light mMainLight;           // _390
	Piki** mTestPikiList;       // _664
	Teki** mTestTekiList;       // _668
	int mTestPikiCount;         // _66C, number of Piki* in _664 array
	int mFocusTekiType;         // _670, teki type to start camera on
	f32 _674;                   // _674
	u8 _678[0x4];               // _678, unknown
	int mAnimationEvent;        // _67C, unknown
	int mTestMode;              // _680
	int _684;                   // _684
	f32 _688;                   // _688
	u8 _68C;                    // _68C
	u32 _690;                   // _690, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct PaniTestSection : public Section {
	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
