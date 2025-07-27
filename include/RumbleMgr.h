#ifndef _HMRUMBLE_H
#define _HMRUMBLE_H

#include "types.h"

struct Graphics;
struct Font;
struct Vector3f;

/**
 * @brief TODO
 */
enum RumbleType {
	RUMBLE_Unk0  = 0,
	RUMBLE_Unk1  = 1,
	RUMBLE_Unk2  = 2,
	RUMBLE_Unk3  = 3,
	RUMBLE_Unk4  = 4,
	RUMBLE_Unk5  = 5,
	RUMBLE_Unk6  = 6,
	RUMBLE_Unk7  = 7,
	RUMBLE_Unk8  = 8,
	RUMBLE_Unk9  = 9,
	RUMBLE_Unk10 = 10,
	RUMBLE_Unk11 = 11,
	RUMBLE_Unk12 = 12,
	RUMBLE_Unk13 = 13,
	RUMBLE_Unk14 = 14,
	RUMBLE_Unk15 = 15,
	RUMBLE_Unk16 = 16,
	RUMBLE_Unk17 = 17,
	RUMBLE_Unk18 = 18,
	RUMBLE_Unk19 = 19,
};

/**
 * @brief TODO
 */
struct RumbleSample {
public:
	RumbleSample(int);

	void simpleStop();
	void simpleStart(f32);

	// unused/inlined:
	void init();

private:
	f32 mCurrentIntensity; // _00
	f32 mTotalIntensity;   // _04
	int mChannel;          // _08
};

/**
 * @brief TODO
 */
struct RumbleTable {
	int mFrameLength; // _00
	int _04;          // _04
};

/**
 * @brief TODO
 */
struct ChannelData {
	int* mRumblePoint; // _00
	f32* mRumbleFrame; // _04
	f32* mRumblePower; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct ChannelDataMgr {
public:
	ChannelDataMgr(); // unused/inlined

	// unused/inlined:
	void init();
	ChannelData* getChannelDataTbl(int row);

private:
	ChannelData* mDataTbl; // _00
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct ChannelMgr {
public:
	ChannelMgr();

	void start(int, f32*);
	f32 update();

	// unused/inlined:
	void init(ChannelDataMgr*);
	void reset();

	bool isFree() { return mData == nullptr; }
	int getActiveType() { return mActiveType; }

	// DLL inlines:
	void draw2d(Graphics&, Font*);

private:
	f32 mRumbleTimer;         // _00
	f32 mRumbleIntensity;     // _04
	f32 mRumbleScale;         // _08
	int mActiveType;          // _0C
	ChannelData* mData;       // _10
	ChannelDataMgr* mDataMgr; // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct ControlerMgr {
public:
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

private:
	static const int maxChannel; // Unused

	f32 mRumbleIntensity;     // _00
	ChannelMgr* mChannelMgrs; // _04
	ChannelDataMgr* mDataMgr; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct RumbleMgr {
public:
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

private:
	static int maxControler;  // Unused
	static f32 pauseTimerMax; // Unused

	f32 mRumbleIntensity;            // _00
	f32 mRumbleFadeOutTimer;         // _04
	u8 mIsEnabled;                   // _08
	u8 mIsDisabled;                  // _09
	RumbleSample* mSamples[4];       // _0C
	ControlerMgr* mControlerMgrs[4]; // _1C
	ChannelDataMgr* mDataMgr;        // _2C
};

extern RumbleMgr* rumbleMgr;
extern RumbleTable patternTable[16];
extern ChannelData channelDataTbl[20];

#endif
