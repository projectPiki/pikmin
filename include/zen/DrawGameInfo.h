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
	DateCallBack(); // not in the DLL, but something's required here

	virtual bool invoke(P2DPane*); // _08

	void setTex();

	// TODO: members
};

/**
 * @brief TODO
 */
struct LifePinchCallBack : public P2DPaneCallBack {
	LifePinchCallBack(); // not in the DLL, but something's required here

	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct LifeIconCallBack : public P2DPaneCallBack {
	LifeIconCallBack(); // not in the DLL, but something's required here

	virtual bool invoke(P2DPane*); // _08
	virtual bool draw(P2DPane*);   // _0C

	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviTexCallBack : public P2DPaneCallBack {
	NaviTexCallBack(); // not in the DLL, but something's required here

	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviIconCallBack : public P2DPaneCallBack {
	NaviIconCallBack(); // not in the DLL, but something's required here

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
	MoonIconCallBack(); // not in the DLL, but something's required here

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
	SunIcon2CallBack(); // not in the DLL, but something's required here

	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct SunIcon1CallBack : public P2DPaneCallBack, public SunAnim {
	SunIcon1CallBack(); // not in the DLL, but something's required here

	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct SunCapsuleCallBack : public P2DPaneCallBack {
	SunCapsuleCallBack(); // not in the DLL, but something's required here

	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct SunBaseCallBack : public SunMove, public P2DPaneCallBack {
	SunBaseCallBack(); // not in the DLL, but something's required here

	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct MapPikminWindowCallBack : public P2DPaneCallBack {
	MapPikminWindowCallBack(); // not in the DLL, but something's required here

	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct PikiIconCallBack : public P2DPaneCallBack {
	PikiIconCallBack(); // not in the DLL, but something's required here

	virtual bool invoke(P2DPane*); // _08

	// TODO: members
};

} // namespace

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct DrawGameInfo {

	/**
	 * @brief TODO
	 */
	enum playModeFlag {
		MODE_Story     = 0,
		MODE_Challenge = 1,
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
	bool isUpperFrameIn();
	bool isUpperFrameOut();
	bool isLowerFrameIn();
	bool isLowerFrameOut();

	// TODO: members
	int mEncodedNextThrowType; // _00
	u16 mFormationPikiNum;     // _04
	u16 mMapPikiNum;           // _06
	u16 mTotalPikiNum;         // _08
	u8 _0A[0x1C - 0xC];        // _0A, unknown
};

extern DrawGameInfo* pGameInfo;

} // namespace zen

#endif
