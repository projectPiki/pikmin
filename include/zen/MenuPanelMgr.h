#ifndef _ZEN_MENUPANELMGR_H
#define _ZEN_MENUPANELMGR_H

#include "types.h"
#include "zen/DrawCommon.h"

struct P2DScreen;

namespace zen {

/**
 * @brief TODO
 */
struct MenuPanelMgr {

	enum statusFlag {
		STATE_Unk0 = 0,
	};

	MenuPanelMgr()
	{
		changeState(STATE_Unk0, 1.0f);
		updateRatio();
	}

	void setCallBack(P2DScreen*, P2DPane*);
	bool update();
	bool checkFinish();

	// unused/inlined:
	void operation();

	void changeState(statusFlag state, f32 p2)
	{
		mState = state;
		_04    = 0.0f;
		_08    = p2;
	}

	void updateRatio() { mRatio = _04 / _08; }

	// DLL inlines, to do:
	void wait();
	void start(f32);
	void end();
	statusFlag getStatusFlag();
	f32 getRatio();

	statusFlag mState; // _00
	f32 _04;           // _04
	f32 _08;           // _08
	f32 mRatio;        // _0C
};

/**
 * @brief TODO
 */
struct MenuPanel : public P2DPaneCallBack {
	MenuPanel(P2DPane*, P2DPane*, MenuPanelMgr*); // DLL, to do

	virtual bool invoke(P2DPane*); // _08 (weak)

	void update(P2DPane*);

	// TODO: members
};

} // namespace zen

#endif
