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
	Font* _30;                  // _30, maybe an array if Font has members with ctors
	u8 _34[0x4];                // _34, unknown
	Camera _38;                 // _38
	u8 _380[0x8];               // _380, unknown (may be part of Camera)
	Texture* mShadowTexture;    // _388
	u8 _38C[0x4];               // _38C, unknown
	Light _390;                 // _390
	u8 _5DC[0x664 - 0x5DC];     // _5DC, unknown
	Piki** _664;                // _664
	Teki** _668;                // _668
	int _66C;                   // _66C, number of Piki* in _664 array
	int mFocusTekiType;         // _670, teki type to start camera on
	f32 _674;                   // _674
	u8 _678[0x4];               // _678, unknown
	int _67C;                   // _67C, unknown
	int mTestMode;              // _680
	u32 _684;                   // _684, unknown
	f32 _688;                   // _688
	u8 _68C;                    // _68C
	u32 _690;                   // _690, unknown
};

/**
 * @brief TODO
 */
struct PaniTestSection : public Section {
	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
	// TODO: members
};

#endif
