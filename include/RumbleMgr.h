#ifndef _HMRUMBLE_H
#define _HMRUMBLE_H

#include "types.h"

struct Graphics;
struct Font;
struct Vector3f;

/**
 * @brief TODO
 */
struct RumbleSample {
	RumbleSample(int);

	void simpleStop();
	void simpleStart(f32);

	// unused/inlined:
	void init();

	f32 mCurrentIntensity; // _00
	f32 mTotalIntensity;   // _04
	int mChannel;          // _08
};

/**
 * @brief TODO
 */
struct RumbleTable {
	int _00; // _00
	int _04; // _04
};

/**
 * @brief TODO
 */
struct ChannelData {
	RumbleTable* mRumblePoint; // _00, maybe this type?
	f32* mRumbleFrame;         // _04
	f32* mRumblePower;         // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct ChannelDataMgr {
	ChannelDataMgr(); // unused/inlined

	// unused/inlined:
	void init();
	ChannelData* getChannelDataTbl(int row);

	ChannelData* mDataTbl; // _00
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct ChannelMgr {
	ChannelMgr();

	void start(int, f32*);
	f32 update();

	// unused/inlined:
	void init(ChannelDataMgr*);
	void reset();

	// DLL inlines:
	bool isFree();
	int getActiveType();
	void draw2d(Graphics&, Font*);

	f32 _00;                  // _00
	f32 _04;                  // _04
	f32 _08;                  // _08
	int mChannelIdx;          // _0C
	ChannelData* mData;       // _10
	ChannelDataMgr* mDataMgr; // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct ControlerMgr {
	ControlerMgr(); // unused/inlined

	void start(int, f32*);

	// unused/inlined:
	void init();
	void reset();
	void stop();
	void stop(int);
	f32 update();

	// DLL inline:
	void draw2d(Graphics&, Font*);

	static const int maxChannel;

	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct RumbleMgr {
	RumbleMgr(bool, bool, bool, bool);

	void reset();
	void start(int, int, f32*);
	void start(int, int, Vector3f&);
	void stop();
	void stop(int, int);
	void update();
	void rumbleOption(bool);

	// unused/inlined:
	void init();
	void rumblePause(bool);

	u8 _00[0x30]; // _00, unknown
};

extern RumbleMgr* rumbleMgr;
extern RumbleTable patternTable[64];
extern ChannelData channelDataTbl[80];

#endif
