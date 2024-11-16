#ifndef _GAMEFLOW_H
#define _GAMEFLOW_H

#include "types.h"
#include "Node.h"
#include "MemoryCard.h"
#include "LoadIdler.h"
#include "Parameters.h"
#include "string.h"
#include "Ayu.h"

struct BaseApp;
struct GameQuickInfo;
struct GameChalQuickInfo;
struct GameInterface;
struct MoviePlayer;
struct Section;
struct Shape;
struct Texture;

/**
 * @brief TODO
 */
enum GameSectionID {
	SECTION_NinLogo   = 0,
	SECTION_Titles    = 1,
	SECTION_MovSample = 2,
	SECTION_OnePlayer = 3,
	SECTION_PaniTest  = 4,
	SECTION_OgTest    = 5,
};

/**
 * @brief TODO
 */
struct GameGenNode : public Node {
	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct GameGenFlow : public Node {
	GameGenFlow()
	    : Node("GameGenFlow")
	{
		_24 = 332;
		_20 = 32;
		_28 = 1;
		_2C = 0;
	}

	virtual void update(); // _10

	// _00     = VTBL
	// _00-_20 = Node
	int _20; // _20
	int _24; // _24
	int _28; // _28
	u32 _2C; // _2C, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct PlayState : public CoreNode {
	inline PlayState()
	    : CoreNode("playState")
	{
		_23 = 0;
		_20 = 1;
	}

	virtual void read(RandomAccessStream&);  // _0C
	virtual void write(RandomAccessStream&); // _10

	void openStage(int);

	// _00     = VTBL
	// _00-_14 = CoreNode
	int _14;              // _14, might be u32
	int _18;              // _18, might be u32
	int _1C;              // _1C, might be u32
	u8 _20;               // _20
	u8 _21;               // _21
	u8 _22;               // _22
	u8 _23;               // _23
	u32 mCourseOpenFlags; // _24, bitflag
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct GameRecChalCourse {
	GameRecChalCourse()
	{
		// what on EARTH is going on here
		*(u32*)(this + 1) = 0;
		*(u32*)(this + 1) = 0;
		*(u32*)(this + 1) = 0;
		*(u32*)(this + 1) = 0;
		*(u32*)(this + 1) = 0;
	}

	inline void init()
	{
		*(u32*)(this + 1) = 0;
		*(u32*)(this + 1) = 0;
		*(u32*)(this + 1) = 0;
		*(u32*)(this + 1) = 0;
		*(u32*)(this + 1) = 0;
	}

	u8 _00[0x14]; // _00, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct GameRecDeadPikmin {
	GameRecDeadPikmin() { _00 = 9999; }

	inline void init() { _00 = 9999; }

	int _00; // _00
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct GameRecBornPikmin {
	GameRecBornPikmin() { _00 = 0; }

	inline void init() { _00 = 0; }

	u32 _00; // _00, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct GameRecMinDay {
	GameRecMinDay()
	{
		_00 = 0;
		_04 = 30;
	}

	inline void init()
	{
		_00 = 0;
		_04 = 30;
	}

	u32 _00; // _00, unknown
	int _04; // _04
};

/**
 * @brief TODO
 */
struct GameHiscores {
	void Initialise()
	{
		_00 = 0;
		for (int i = 0; i < 5; i++) {
			mMinDayRecords[i].init();
			mBornPikminRecords[i].init();
			mDeadPikminRecords[i].init();
			mChalModeRecords[i].init();
		}
	}

	int _00;                                 // _00
	GameRecMinDay mMinDayRecords[5];         // _04
	GameRecBornPikmin mBornPikminRecords[5]; // _1C
	GameRecDeadPikmin mDeadPikminRecords[5]; // _30
	GameRecChalCourse mChalModeRecords[5];   // _44
};

/**
 * @brief TODO
 */
struct GamePrefs : public CoreNode {
	inline GamePrefs()
	    : CoreNode("gamePrefs")
	{
		Initialise();
	}

	virtual void read(RandomAccessStream&);  // _0C
	virtual void write(RandomAccessStream&); // _10

	void Initialise()
	{
		_18        = 3;
		mBgmVol    = 8;
		mSfxVol    = 8;
		_108       = 0;
		_1E        = 0;
		_20        = 0;
		_21        = 0;
		_1F        = 0;
		_22        = 0;
		mIsChanged = false;
		mHiscores.Initialise();
	}
	void setBgmVol(u8);
	void setSfxVol(u8);
	void setStereoMode(bool);
	void setVibeMode(bool);
	void setChildMode(bool);
	void getChallengeScores(GameChalQuickInfo&);
	bool checkIsHiscore(GameChalQuickInfo&);
	bool checkIsHiscore(GameQuickInfo&);
	void fixSoundMode();

	// _00     = VTBL
	// _00-_14 = CoreNode
	bool mIsChanged;        // _14
	int _18;                // _18
	u8 mBgmVol;             // _1C
	u8 mSfxVol;             // _1D
	u8 _1E;                 // _1E
	u8 _1F;                 // _1F
	u8 _20;                 // _20
	u8 _21;                 // _21
	u8 _22;                 // _22
	u8 _23;                 // _23
	GameHiscores mHiscores; // _24
	u8 _DC[0x108 - 0xDC];   // _DC, unknown
	u32 _108;               // _108, unknown
};

/**
 * @brief TODO
 */
struct GameFlow : public Node {

	/**
	 * @brief Fabricated. This is gamePrms in Minty's Spreadsheet tm.
	 *
	 * @note Size: 0xD8.
	 */
	struct GamePrms : public Parameters {
		inline GamePrms()
		    : mStartHour(this, 7.0f, 0.0f, 0.0f, "t00", nullptr)
		    , mEndHour(this, 19.0f, 0.0f, 0.0f, "t01", nullptr)
		    , mDaySpeedFactor(this, 20.0f, 0.0f, 0.0f, "p00", nullptr)
		    , mMorningStart(this, 7.0f, 0.0f, 0.0f, "p01", nullptr)
		    , mMorningMid(this, 8.0f, 0.0f, 0.0f, "s01", nullptr)
		    , mMorningEnd(this, 9.0f, 0.0f, 0.0f, "p02", nullptr)
		    , mNightStart(this, 17.5f, 0.0f, 0.0f, "p03", nullptr)
		    , mNightMid(this, 18.5f, 0.0f, 0.0f, "s03", nullptr)
		    , mNightEnd(this, 19.5f, 0.0f, 0.0f, "p04", nullptr)
		    , mNightWarning(this, 16.0f, 0.0f, 0.0f, "p05", nullptr)
		    , mNightCountdown(this, 18.5f, 0.0f, 0.0f, "p06", nullptr)
		    , mTekiAbility(this, 1, 0, 0, "x99", nullptr)
		    , mGameTitle(this, *(String*)("blah"), *(String*)(0), *(String*)(0), "x98", nullptr)
		{
		}

		// _00-_04 = Parameters
		Parm<f32> mStartHour;      // _04, t00 - time set to when entering stage
		Parm<f32> mEndHour;        // _14, t01 - time when day ends
		Parm<f32> mDaySpeedFactor; // _24, p00 - (inverse of) speed day advances
		Parm<f32> mMorningStart;   // _34, p01 - timesetting 0 time
		Parm<f32> mMorningMid;     // _44, s01 - timesetting 1 time
		Parm<f32> mMorningEnd;     // _54, p02 - timesetting 2 start time
		Parm<f32> mNightStart;     // _64, p03 - timesetting 2 end time
		Parm<f32> mNightMid;       // _74, s03 - timesetting 3 time
		Parm<f32> mNightEnd;       // _84, p04 - timesetting 0 time
		Parm<f32> mNightWarning;   // _94, p05 - Hurry Up! time
		Parm<f32> mNightCountdown; // _A4, p06 - time 10s countdown starts
		Parm<int> mTekiAbility;    // _B4, x99 - no idea what this does yet
		Parm<String> mGameTitle;   // _C4, x98 - P I K M I N (unused?)
	};

	virtual void read(RandomAccessStream&); // _0C
	virtual void update();                  // _10

	void drawLoadLogo(Graphics&, bool, Texture*, f32);
	void menuToggleTimers(struct Menu&);
	void menuTogglePrint(Menu&);
	void menuToggleDInfo(Menu&);
	void menuToggleDExtra(Menu&);
	void menuToggleBlur(Menu&);
	void menuToggleInfo(Menu&);
	void menuToggleColls(Menu&);
	void menuChangeFilter(Menu&);
	void menuIncreaseFilter(Menu&);
	void menuDecreaseFilter(Menu&);
	void setLoadBanner(char*);
	void hardReset(BaseApp*);
	void softReset();
	Shape* loadShape(char*, bool);
	void addGenNode(char*, CoreNode*);

	// unused/inlined:
	void addOptionsMenu(Menu*);
	void addFilterMenu(Menu*);

	// _00     = VTBL
	// _00-_20 = Node
	GamePrms* mParameters;        // _20
	MemoryCard mMemoryCard;       // _24
	u8 _6C[0x94 - 0x6C];          // _6C, unknown
	GamePrefs mGamePrefs;         // _94
	u8 _1A0[0x4];                 // _1A0, unknown - might be part of GamePrefs
	PlayState mPlayState;         // _1A4
	u8 _1CC[0x1D0 - 0x1CC];       // _1CC, unknown
	u32 _1D0;                     // _1D0, most recently opened stage?
	u32 _1D4;                     // _1D4, unknown
	u8 _1D8[0x4];                 // _1D8, unknown
	MoviePlayer* mMoviePlayer;    // _1DC
	u8 _1E0[0x1E8 - 0x1E0];       // _1E0, unknown
	GameInterface* _1E8;          // _1E8
	int _1EC;                     // _1EC
	int mGameSectionID;           // _1F0, see GameSectionID enum
	int _1F4;                     // _1F4
	u8 _1F8[0x200 - 0x1F8];       // _1F8, unknown
	u32 _200;                     // _200, unknown
	Section* mGameSection;        // _204
	char* _208;                   // _208
	char* _20C;                   // _20C
	char* _210;                   // _210
	char* _214;                   // _214
	char* _218;                   // _218
	char* _21C;                   // _21C
	char* _220;                   // _220
	char* _224;                   // _224
	char* _228;                   // _228
	char* _22C;                   // _22C
	u8 _230[0x2A8 - 0x230];       // _230, unknown
	u32 _2A8;                     // _2A8, unknown
	u32 _2AC;                     // _2AC, unknown
	u32 _2B0;                     // _2B0, could be int
	u8 _2B4[0x2BC - 0x2B4];       // _2B4, unknown
	u32 _2BC;                     // _2BC, unknown
	u8 _2C0[0x2D8 - 0x2C0];       // _2C0, unknown
	f32 _2D8;                     // _2D8
	f32 _2DC;                     // _2DC
	f32 _2E0;                     // _2E0
	u8 _2E4[0x4];                 // _2E4, unknown
	f32 _2E8;                     // _2E8
	f32 _2EC;                     // _2EC
	u8 _2F0[0x8];                 // _2F0, unknown
	u32 _2F8;                     // _2F8, unknown
	u32 _2FC;                     // _2FC, unknown, but same as 0x30 in CreatureInf
	u32 _300;                     // _300, unknown
	f32 _304;                     // _304
	u8 _308[0x4];                 // _308, unknown
	GameGenFlow* mGenFlow;        // _30C
	Texture* _310;                // _310
	f32 _314;                     // _314
	u8 _318[0x31C - 0x318];       // _318, unknown
	GameLoadIdler mGameLoadIdler; // _31C
	u8 _330[0x338 - 0x330];       // _330, unknown
	int _338;                     // _338
	u8 _33C[0x350 - 0x33C];       // _33C, unknown
	u32 _350;                     // _350, unknown
	u8 _354[0x8];                 // _354, unknown
	u8 _35C;                      // _35C, maybe Colour?
	u8 _35D;                      // _35D
	u8 _35E;                      // _35E
	u8 _35F;                      // _35F
	u8 _360;                      // _360
	u8 _361;                      // _361
	u8 _362;                      // _362
};

extern GameFlow gameflow;

#endif
