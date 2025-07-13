#ifndef _GAMEFLOW_H
#define _GAMEFLOW_H

#include "Ayu.h"
#include "GlobalGameOptions.h"
#include "LoadIdler.h"
#include "MemoryCard.h"
#include "Node.h"
#include "OnePlayerSection.h"
#include "Parameters.h"
#include "String.h"
#include "WorldClock.h"
#include "types.h"

struct AnimFrameCacher;
struct BaseApp;
struct GameQuickInfo;
struct GameChalQuickInfo;
struct GameInterface;
struct GameGenFlow;
struct MoviePlayer;
struct Section;
struct Shape;
struct Texture;

/**
 * @brief TODO
 */
enum GamePrefsFlags {
	GAMEPREF_Vibe   = 0x1,
	GAMEPREF_Stereo = 0x2,
	GAMEPREF_Child  = 0x4,
};

/**
 * @brief TODO
 */
enum GameSectionID {
	SECTION_NinLogo   = 0,
	SECTION_Titles    = 1,
	SECTION_MovSample = 2,
	SECTION_PaniTest  = 3,
	SECTION_OnePlayer = 4,
	SECTION_OgTest    = 5,
};

/**
 * @brief TODO
 */
enum OnePlayerSectionID {
	ONEPLAYER_GameSetup       = 0,
	ONEPLAYER_CardSelect      = 1,
	ONEPLAYER_E3Tutorial      = 2,
	ONEPLAYER_E3ForestDay1    = 3,
	ONEPLAYER_E3ForestDay2    = 4,
	ONEPLAYER_IntroGame       = 5,
	ONEPLAYER_MapSelect       = 6,
	ONEPLAYER_NewPikiGame     = 7,
	ONEPLAYER_GameCourseClear = 8,
	ONEPLAYER_GameStageClear  = 9,
	ONEPLAYER_GameCredits     = 10,
	ONEPLAYER_GameExit        = 11,
};

/**
 * @brief TODO
 */
enum GameFilterType {
	FILTER_Custom = 0,
	FILTER_DFOff  = 1,
};

/**
 * @brief For accessing language file paths in gameflow.
 */
enum LanguageFileType {
	LANGFILE_Dir = 0,
	LANGFILE_Arc = 1,
	LANGFILE_Bun = 2,
	LANGFILE_Blo = 3,
	LANGFILE_Tex = 4,
	LANGFILE_COUNT, // 5
};

struct GameQuickInfo {
	// This struct has no ctor or any other functions

	u32 mParts;         // _00
	u32 mDay;           // _04
	u32 mBornPikis;     // _08
	u32 mDeadPikis;     // _0C
	int mPartsDaysRank; // _10
	int mBornPikisRank; // _14
	int mDeadPikisRank; // _18
};

struct GameChalQuickInfo {
	int mCourseID;                    // _00, see StageID enum
	u32 mScore;                       // _04, score for this entry
	int mRank;                        // _08, 0-4, 0 being the best
	u32 mCourseScores[MAX_HI_SCORES]; // _0C, all 5 top scores for mCourseID course
};

/**
 * @brief TODO
 */
struct LangMode {
	void set(char* dir, char* arc, char* bun, char* blo, char* tex)
	{
		mDirPath = dir;
		mArcPath = arc;
		mBunPath = bun;
		mBloPath = blo;
		mTexPath = tex;
	}

	char* mDirPath; // _00
	char* mArcPath; // _04
	char* mBunPath; // _08
	char* mBloPath; // _0C
	char* mTexPath; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct GameGenNode : public Node {
	inline GameGenNode(char* name, CoreNode* node)
	    : Node(name)
	{
		mNode = node;
	}

	// _00     = VTBL
	// _00-_20 = Node
	CoreNode* mNode; // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct PlayState : public CoreNode {
	PlayState()
	    : CoreNode("playState")
	{
		mSaveFlags  = 0;
		mSaveStatus = 1;
	}

	virtual void read(RandomAccessStream&);  // _0C
	virtual void write(RandomAccessStream&); // _10

	void openStage(int);

	void Initialise()
	{
		mSaveStatus      = 1;
		mBluePikiCount   = -1;
		mYellowPikiCount = -1;
		mRedPikiCount    = -1;
		mSavedDay        = 1;
		mShipPartsCount  = 0;
		mCourseOpenFlags = 1;
	}

	bool isStageOpen(int stageIdx)
	{
		if (stageIdx >= STAGE_START && stageIdx <= STAGE_COUNT) {
			return (mCourseOpenFlags & (1 << stageIdx)) != 0;
		}
		return false;
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mRedPikiCount;    // _14
	int mYellowPikiCount; // _18
	int mBluePikiCount;   // _1C
	u8 mSaveStatus;       // _20
	u8 mSavedDay;         // _21
	u8 mShipPartsCount;   // _22
	u8 mSaveFlags;        // _23
	u32 mCourseOpenFlags; // _24, bitflag
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct GameRecMinDay {
	GameRecMinDay()
	{
		mNumParts = 0;
		mNumDays  = MAX_DAYS;
	}

	void Initialise()
	{
		mNumParts = 0;
		mNumDays  = MAX_DAYS;
	}

	void read(RandomAccessStream& input)
	{
		mNumParts = input.readInt();
		mNumDays  = input.readInt();
	}
	void write(RandomAccessStream& output)
	{
		output.writeInt(mNumParts);
		output.writeInt(mNumDays);
	}

	int mNumParts; // _00
	int mNumDays;  // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct GameRecBornPikmin {
	GameRecBornPikmin() { mNumBorn = 0; }

	void Initialise() { mNumBorn = 0; }

	void read(RandomAccessStream& input) { mNumBorn = input.readInt(); }
	void write(RandomAccessStream& output) { output.writeInt(mNumBorn); }

	int mNumBorn; // _00, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct GameRecDeadPikmin {
	GameRecDeadPikmin() { mNumDead = 9999; }

	void Initialise() { mNumDead = 9999; }

	void read(RandomAccessStream& input) { mNumDead = input.readInt(); }
	void write(RandomAccessStream& output) { output.writeInt(mNumDead); }

	int mNumDead; // _00
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

	void Initialise()
	{
		*(u32*)(this + 1) = 0;
		*(u32*)(this + 1) = 0;
		*(u32*)(this + 1) = 0;
		*(u32*)(this + 1) = 0;
		*(u32*)(this + 1) = 0;
	}

	void read(RandomAccessStream& input)
	{
		for (int i = 0; i < 5; i++) {
			mScores[i] = input.readInt();
		}
	}
	void write(RandomAccessStream& output)
	{
		for (int i = 0; i < 5; i++) {
			output.writeInt(mScores[i]);
		}
	}

	int mScores[MAX_HI_SCORES]; // _00
};

/**
 * @brief TODO
 */
struct GameHiscores {
	void Initialise()
	{
		mTotalPikis = 0;
		for (int i = 0; i < MAX_HI_SCORES; i++) {
			mMinDayRecords[i].Initialise();
			mBornPikminRecords[i].Initialise();
			mDeadPikminRecords[i].Initialise();
			mChalModeRecords[i].Initialise();
		}
	}

	void read(RandomAccessStream& input)
	{
		mTotalPikis = input.readInt();
		for (int i = 0; i < MAX_HI_SCORES; i++) {
			mMinDayRecords[i].read(input);
			mBornPikminRecords[i].read(input);
			mDeadPikminRecords[i].read(input);
			mChalModeRecords[i].read(input);
		}
	}

	void write(RandomAccessStream& output)
	{
		output.writeInt(mTotalPikis);
		for (int i = 0; i < MAX_HI_SCORES; i++) {
			mMinDayRecords[i].write(output);
			mBornPikminRecords[i].write(output);
			mDeadPikminRecords[i].write(output);
			mChalModeRecords[i].write(output);
		}
	}

	int mTotalPikis;                                     // _00
	GameRecMinDay mMinDayRecords[MAX_HI_SCORES];         // _04
	GameRecBornPikmin mBornPikminRecords[MAX_HI_SCORES]; // _1C
	GameRecDeadPikmin mDeadPikminRecords[MAX_HI_SCORES]; // _30
	GameRecChalCourse mChalModeRecords[MAX_HI_SCORES];   // _44
};

/**
 * @brief TODO
 */
struct GamePrefs : public CoreNode {
	GamePrefs()
	    : CoreNode("gamePrefs")
	{
		Initialise();
	}

	virtual void read(RandomAccessStream&);  // _0C
	virtual void write(RandomAccessStream&); // _10

#if defined(VERSION_GPIP01_00)
	void Initialise();
#else
	void Initialise()
	{
		mFlags              = 3;
		mBgmVol             = 8;
		mSfxVol             = 8;
		mFileNum            = 0;
		mHasSaveGame        = false;
		mSaveGameIndex      = 0;
		mSpareSaveGameIndex = 0;
		_1F                 = 0;
		mUnlockedStageFlags = 0;
		mIsChanged          = false;
		mHiscores.Initialise();
	}
#endif

	void setBgmVol(u8);
	void setSfxVol(u8);
	void setStereoMode(bool);
	void setVibeMode(bool);
#if defined(VERSION_GPIP01_00)
	void setChildMode(int);
#else
	void setChildMode(bool);
#endif
	void getChallengeScores(GameChalQuickInfo&);
	void checkIsHiscore(GameChalQuickInfo&);
	void checkIsHiscore(GameQuickInfo&);
	void fixSoundMode();

	void addBornPikis(u32 count) { mHiscores.mTotalPikis += count; }

	void openStage(int stageIdx)
	{
		if (stageIdx >= STAGE_START && stageIdx <= STAGE_COUNT) {
			mUnlockedStageFlags |= (1 << stageIdx);
		}
	}

	bool isStageOpen(int stageIdx)
	{
		if (stageIdx >= STAGE_START && stageIdx <= STAGE_COUNT) {
			return (mUnlockedStageFlags & (1 << stageIdx)) != 0;
		}
		return false;
	}

	bool getVibeMode() { return (mFlags & GAMEPREF_Vibe) != 0; }
	bool getStereoMode() { return (mFlags & GAMEPREF_Stereo) != 0; }

#if defined(VERSION_GPIP01_00)
	int getChildMode();
#else
	bool getChildMode() { return (mFlags & GAMEPREF_Child) != 0; }
#endif

	u8 getBgmVol() { return mBgmVol; }
	u8 getSfxVol() { return mSfxVol; }

	bool isChallengeOpen() { return mUnlockedStageFlags != 0; }

	// _00     = VTBL
	// _00-_14 = CoreNode
	bool mIsChanged;        // _14
	int mFlags;             // _18
	u8 mBgmVol;             // _1C
	u8 mSfxVol;             // _1D
	bool mHasSaveGame;      // _1E
	u8 _1F;                 // _1F
	u8 mSaveGameIndex;      // _20
	u8 mSpareSaveGameIndex; // _21
	u8 mUnlockedStageFlags; // _22
	u8 _23;                 // _23
	GameHiscores mHiscores; // _24
	u32 _DC;                // _DC, unknown
	u32 _E0;                // _E0
	u8 _E4[0x108 - 0xE4];   // _E4, unknown
	u32 mFileNum;           // _108, unknown
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
	struct Parms : public Parameters {
		inline Parms()
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
		    , mGameTitle(this, String("blah", 0), String("", 0), String("", 0), "x98", nullptr)
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
	Texture* setLoadBanner(char*);
	void hardReset(BaseApp*);
	void softReset();
	Shape* loadShape(char*, bool);
	void addGenNode(char*, CoreNode*);

	// unused/inlined:
	void addOptionsMenu(Menu*);
	void addFilterMenu(Menu*);

	// _00     = VTBL
	// _00-_20 = Node
	Parms* mParameters;            // _20
	MemoryCard mMemoryCard;        // _24
	GamePrefs mGamePrefs;          // _94
	u32 mSaveGameCrc;              // _1A0
	PlayState mPlayState;          // _1A4
	int mCurrentStageId;           // _1CC
	int mLastUnlockedStageId;      // _1D0
	u32 _1D4;                      // _1D4, unknown
	u32 mDemoFlags;                // _1D8, bitflag of some description
	MoviePlayer* mMoviePlayer;     // _1DC
	s16 mMovieInfoNum;             // _1E0
	s16 mMovieType;                // _1E2
	s16 mIsDayEndActive;           // _1E4
	s16 mIsDayEndTriggered;        // _1E6
	GameInterface* mGameInterface; // _1E8
	int mNextSectionID;            // _1EC, see GameSectionID enum
	int mGameSectionID;            // _1F0, see GameSectionID enum
	s32 mNextOnePlayerSectionID;   // _1F4, see OnePlayerSectionID enum
	u8 _1F8[0x4];                  // _1F8, unknown
	int mLevelIndex;               // _1FC, WHAT IS THIS???
	u32 _200;                      // _200, unknown
	Section* mGameSection;         // _204
	LangMode mLangModes[2];        // _208
	u8 _230[0x2A8 - 0x230];        // _230, unknown
	int mLanguageIndex;            // _2A8
	u32 mIntroMovieIdCycle;        // _2AC
	u32 mIntroMovieId;             // _2B0, could be int
	BOOL mIsChallengeMode;         // _2B4
	u32 _2B8;                      // _2B8, unknown
	u32 mUpdateTickCount;          // _2BC
	f32 mLoadTimeSeconds;          // _2C0
	f32 mCurrentEffectAlpha;       // _2C4
	vf32 mTargetEffectAlpha;       // _2C8
	f32 mEffectDurationTimer;      // _2CC
	int mAppTickCounter;           // _2D0
	BOOL mRedLoadLogo;             // _2D4, makes the load logo red?
	WorldClock mWorldClock;        // _2D8
	f32 mTimeMultiplier;           // _304
	AnimFrameCacher* mFrameCacher; // _308
	GameGenFlow* mGenFlow;         // _30C
	Texture* mLevelBannerTexture;  // _310
	f32 mLevelBannerFadeValue;     // _314
	Texture* mLoadBannerTexture;   // _318
	GameLoadIdler mGameLoadIdler;  // _31C
	u8 _330[0x4];                  // _330
	BOOL mIsGameplayInputEnabled;  // _334
	BOOL mIsUiOverlayActive;       // _338
	BOOL _33C;                     // _33C
	BOOL mIsTutorialActive;        // _340
	u8 _344[0x4];                  // _344, unknown
	u32 _348;                      // _348, unknown
	u32 _34C;                      // _34C, unknown
	int mFilterType;               // _350
	u8 mFilters[8];                // _354
	u8 _35C;                       // _35C, maybe Colour?
	u8 _35D;                       // _35D
	u8 _35E;                       // _35E
	u8 _35F;                       // _35F
	u8 _360;                       // _360
	u8 _361;                       // _361
	u8 _362;                       // _362
};

extern GameFlow gameflow;

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

	virtual void update() // _10
	{
		gameflow.mUpdateTickCount++;
		gameflow.mWorldClock.mTicksPerHour = 60.0f * (gameflow.mTimeMultiplier * gameflow.mParameters->mDaySpeedFactor());
		gameflow.mWorldClock.mTimeScale    = gameflow.mWorldClock.mTicksPerHour / gameflow.mWorldClock.mHoursInDay;
		Node::update();
	}

	// _00     = VTBL
	// _00-_20 = Node
	int _20; // _20
	int _24; // _24
	int _28; // _28
	u32 _2C; // _2C, unknown
};

void preloadLanguage();

#endif
