#ifndef _ZEN_DRAWGAMEINFO_H
#define _ZEN_DRAWGAMEINFO_H

#include "types.h"
#include "P2D/Pane.h"
#include "zen/Number.h"

struct Graphics;

// these can either go here or drawGameInfo.cpp, either way

namespace {

/**
 * @brief TODO
 */
struct DateCallBack : public P2DPaneCallBack, public zen::NumberTex {
	virtual bool invoke(P2DPane*); // _08

	void setTex();

	// TODO: members
};

/**
 * @brief TODO
 */
struct LifePinchCallBack : public P2DPaneCallBack {
	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct LifeIconCallBack : public P2DPaneCallBack {
	virtual bool invoke(P2DPane*); // _08
	virtual bool draw(P2DPane*);   // _0C

	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviTexCallBack : public P2DPaneCallBack {
	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviIconCallBack : public P2DPaneCallBack {
	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct SunMove {
	// TODO: members
	u8 _00[0x10]; // _00, unknown
};

/**
 * @brief TODO
 */
struct MoonIconCallBack : public P2DPaneCallBack, public SunMove {
	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct SunAnim {
	// TODO: members
};

/**
 * @brief TODO
 */
struct SunIcon2CallBack : public P2DPaneCallBack, public SunMove, public SunAnim {
	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct SunIcon1CallBack : public P2DPaneCallBack, public SunAnim {
	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct SunCapsuleCallBack : public P2DPaneCallBack {
	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct SunBaseCallBack : public SunMove, public P2DPaneCallBack {
	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct MapPikminWindowCallBack : public P2DPaneCallBack {
	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct PikiIconCallBack : public P2DPaneCallBack {
	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

} // namespace

namespace zen {

/**
 * @brief TODO
 */
struct DrawGameInfo {

	/**
	 * @brief TODO
	 */
	enum playModeFlag {
		// TODO: this
	};

	DrawGameInfo(playModeFlag);

	void update();
	void draw(Graphics&);
	void upperFrameIn(f32, bool);
	void upperFrameOut(f32, bool);
	void lowerFrameIn(f32, bool);
	void lowerFrameOut(f32, bool);

	// unused/inlined:
	void upperDisplayOn();
	void upperDisplayOff();
	void lowerDisplayOn();
	void lowerDisplayOff();
	void isUpperFrameIn();
	void isUpperFrameOut();
	void isLowerFrameIn();
	void isLowerFrameOut();

	// TODO: members
};

} // namespace zen

#endif
