#ifndef _ZEN_DRAWHURRYUP_H
#define _ZEN_DRAWHURRYUP_H

#include "P2D/Graph.h"
#include "P2D/Picture.h"
#include "P2D/Screen.h"
#include "types.h"

struct Graphics;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x154.
 */
struct DrawHurryUp {
public:
	/**
	 * @brief TODO
	 */
	enum modeFlag {
		MODE_Start      = 0,
		MODE_Enlarge    = 1,
		MODE_BrightShot = 2,
		MODE_Bright     = 3,
		MODE_End        = 4,
	};

	/**
	 * @brief TODO
	 */
	enum messageTypeFlag {
		MesgType1 = 1,
		// TODO: this
	};

	DrawHurryUp();

	void start(messageTypeFlag);
	bool update();
	void draw(Graphics&);

	// unused/inlined:
	~DrawHurryUp() { }

protected:
	void initPanes();
	void startStatus();
	void enlargeStatus();
	void brightShotStatus();
	void brightStatus();
	bool endStatus();

	modeFlag mMode;                 // _00
	P2DScreen mScreen;              // _04
	P2DPerspGraph* mPerspGraph;     // _FC
	bool mIsVisible;                // _100
	f32 mModeTimer;                 // _104
	f32 mModeDuration;              // _108
	int _10C;                       // _10C
	P2DPane* mRootPane;             // _110
	P2DPicture* mMovingHurryUpPane; // _114
	P2DPicture* mMovingSundownPane; // _118
	P2DPicture* mFixedHurryUpPane;  // _11C
	P2DPicture* mFixedSundownPane;  // _120
	P2DPicture* mMsgHaloPane;       // _124
	P2DPicture* mMsgFillPane;       // _128
	f32 mRootScale;                 // _12C
	Vector3f mHurryUpDefaultPos;    // _130
	Vector3f mSundownDefaultPos;    // _13C
	Vector3f mHaloDefaultPos;       // _148
};

} // namespace zen

extern zen::DrawHurryUp* hurryupWindow;

#endif
