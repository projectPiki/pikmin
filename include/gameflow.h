#ifndef _GAMEFLOW_H
#define _GAMEFLOW_H

#include "Ayu.h"
#include "Common/String.h"
#include "GlobalGameOptions.h"
#include "LoadIdler.h"
#include "MemoryCard.h"
#include "Node.h"
#include "OnePlayerSection.h"
#include "Parameters.h"
#include "WorldClock.h"
#include "system.h"
#include "types.h"

struct AnimFrameCacher;
struct BaseApp;
struct GameQuickInfo;
struct GameChalQuickInfo;
struct GameInterface;
struct GameGenFlow;
struct Menu;
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
	FILTER_Custom = 0, ///< 0, use the custom/editable values connected to the debug menu (7-tap filter).
	FILTER_DFOff  = 1, ///< 1, turn deflicker off and use the default values (3-tap filter).
	FILTER_COUNT,      ///< 2, number of vertical filter types.
};

/**
 * @brief HVQM4 movies to play when idling on the intro screen or during the credits.
 *
 * The first four options are cycled through on the title screen. The last two options are for the credits.
 */
enum MovSampleID {
	MOV_GrowDemo     = 0, ///< 0, `cntA_S.h4m` - tutorial video showing Olimar growing Pikmin.
	MOV_ThrowDemo    = 1, ///< 1, `cntB_S.h4m` - tutorial video showing Olimar throwing Pikmin at things.
	MOV_WorkDemo     = 2, ///< 2, `cntC_S.h4m` - tutorial video showing Pikmin doing tasks (building bridges and sticks, using bombs).
	MOV_DeathDemo    = 3, ///< 3, `cntD_S.h4m` - tutorial video about Pikmin deaths and hazards.
	MOV_NormalEnding = 4, ///< 4, `sr_S.h4m` - neutral ending credits.
	MOV_HappyEnding  = 5, ///< 5, `srhp_S.h4m` - happy (100%) ending credits.
	MOV_COUNT,            ///< 6 total HVQM4 movies.

	MOV_INTRO_CYCLE_MASK = 0x3, ///< 0x3, Cycles through CntA-CntD on title screen after idling for some time.
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

/**
 * @brief Game flow state flags for handling behaviour during cutscenes.
 */
enum GameflowDemoFlags {
	GFDEMO_None           = 0,         ///< 0x0, no flags set.
	GFDEMO_HideNavi       = (1 << 2),  ///< 0x4, hide the player.
	GFDEMO_HideBluePiki   = (1 << 3),  ///< 0x8, hide blue pikmin.
	GFDEMO_HideRedPiki    = (1 << 4),  ///< 0x10, hide red pikmin.
	GFDEMO_HideYellowPiki = (1 << 5),  ///< 0x20, hide yellow pikmin.
	GFDEMO_MovieMode      = (1 << 6),  ///< 0x40, disables the player control.
	GFDEMO_InMenu         = (1 << 7),  ///< 0x80, check for if a menu is open.
	GFDEMO_ShowTekis      = (1 << 10), ///< 0x400, show enemies even in demo mode.
};

/**
 * @brief Type of ship-related text cutscene to play.
 */
enum ShipTextType {
	SHIPTEXT_CollectEngine = -1, ///< -1, first part collection (delayed text).
	SHIPTEXT_PartCollect   = 0,  ///< 0, ship part collection text - also when player interacts with the Dolphin directly.
	SHIPTEXT_PartsAccess   = 1,  ///< 1, text when interacting with a ship part directly.
	SHIPTEXT_PowerUp       = 2,  ///< 2, text when ship upgrades and opens a new area.
	SHIPTEXT_PartDiscovery = 3,  ///< 3, text when approaching a part for the first time.
};

/**
 * @brief Quick-pass context for (story mode) hi-score related trackables.
 *
 * @note Size: 0x1C.
 */
struct GameQuickInfo {
	u32 mParts;         ///< _00, total number of ship parts collected.
	u32 mDay;           ///< _04, final in-game day.
	u32 mBornPikis;     ///< _08, total number of pikmin grown.
	u32 mDeadPikis;     ///< _0C, total number of pikmin killed.
	int mPartsDaysRank; ///< _10, rank for number of parts collected (0-4, 0 being the best).
	int mBornPikisRank; ///< _14, rank for number of pikmin grown (0-4, 0 being the best).
	int mDeadPikisRank; ///< _18, rank for number of pikmin killed (0-4, 0 being the least killed).
};

/**
 * @brief Quick-pass context for (challenge mode) hi-score related trackables.
 *
 * @note Size: 0x20.
 */
struct GameChalQuickInfo {
	int mCourseID;                    // _00, see StageID enum.
	u32 mScore;                       // _04, score for this entry.
	int mRank;                        // _08, rank of this score on this course (0-4, 0 being the best).
	u32 mCourseScores[MAX_HI_SCORES]; // _0C, all 5 top scores for mCourseID course.
};

/**
 * @brief Structure for handling language-specific file paths.
 *
 * @note Size: 0x14.
 */
struct LangMode {

	/**
	 * @brief Sets all file paths.
	 *
	 * @param dir Path to language's .dir BLO archive.
	 * @param arc Path to language's .arc BLO archive.
	 * @param bun Path to language's .bun screen bundle.
	 * @param blo Path to language's screen BLO directory.
	 * @param tex Path to language's screen texture directory.
	 */
	void set(immut char* dir, immut char* arc, immut char* bun, immut char* blo, immut char* tex)
	{
		mDirPath = dir;
		mArcPath = arc;
		mBunPath = bun;
		mBloPath = blo;
		mTexPath = tex;
	}

	immut char* mDirPath; ///< _00, path to language's .dir BLO archive.
	immut char* mArcPath; ///< _04, path to language's .arc BLO archive.
	immut char* mBunPath; ///< _08, path to language's .bun screen bundle.
	immut char* mBloPath; ///< _0C, path to language's screen BLO directory.
	immut char* mTexPath; ///< _10, path to language's screen texture directory.
};

/**
 * @brief Largely unused wrapper class for a node (list) to be handled by the game flow manager.
 *
 * The node wrapped by this class is never actually interacted with.
 *
 * @note Size: 0x24.
 */
struct GameGenNode : public Node {

	/// Constructs a generic node wrapper.
	inline GameGenNode(immut char* name, CoreNode* node)
	    : Node(name)
	{
		mNode = node;
	}

	// _00     = VTBL
	// _00-_20 = Node
	CoreNode* mNode; ///< _20, list being wrapped - never interacted with.
};

/**
 * @brief State of trackables (stage unlocks, pikmin counts, etc) that should be saved to memory card.
 *
 * @note Size: 0x24.
 */
struct PlayState : public CoreNode {

	/**
	 * @brief Whether we're initialised and ready to save or not.
	 */
	enum SaveStatus {
		Fresh       = 1, ///< 1, fresh file/save info not yet initialised.
		ReadyToSave = 2, ///< 2, save info initialised, will save play data to memory card on save.
	};

	/// Constructs a fresh play state - un-initialised.
	PlayState()
	    : CoreNode("playState")
	{
		mSaveSlot   = 0;
		mSaveStatus = Fresh;
	}

	virtual void read(RandomAccessStream&);  // _0C
	virtual void write(RandomAccessStream&); // _10

	void openStage(int stageID);

	/// Initialises a new play state with dummy counts, and only Impact Site unlocked.
	void Initialise()
	{
		mSaveStatus      = Fresh;
		mBluePikiCount   = -1;
		mYellowPikiCount = -1;
		mRedPikiCount    = -1;
		mSavedDay        = 1;
		mShipPartsCount  = 0;
		mCourseOpenFlags = (1 << STAGE_Practice);
	}

	/**
	 * @brief Checks if a given stage is "open" (unlocked).
	 * @param stageIdx Stage to check - see `StageID` enum.
	 * @return True if stage is valid and unlocked, false otherwise.
	 */
	bool isStageOpen(int stageIdx)
	{
		if (stageIdx >= STAGE_START && stageIdx <= STAGE_COUNT) {
			return (mCourseOpenFlags & (1 << stageIdx)) != 0;
		}
		return false;
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mRedPikiCount;    ///< _14, saved red pikmin count.
	int mYellowPikiCount; ///< _18, saved yellow pikmin count.
	int mBluePikiCount;   ///< _1C, saved blue pikmin count.
	u8 mSaveStatus;       ///< _20, whether play state can be saved or not - see `SaveStatus` enum.
	u8 mSavedDay;         ///< _21, saved in-game day count.
	u8 mShipPartsCount;   ///< _22, saved collected ship parts count.
	u8 mSaveSlot;         ///< _23, save file slot.
	u32 mCourseOpenFlags; ///< _24, bitflag of which courses are unlocked, packed as (1 << stageID).
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
		mScores[TERNARY_BUGFIX(0, MAX_HI_SCORES)] = 0;
		mScores[TERNARY_BUGFIX(1, MAX_HI_SCORES)] = 0;
		mScores[TERNARY_BUGFIX(2, MAX_HI_SCORES)] = 0;
		mScores[TERNARY_BUGFIX(3, MAX_HI_SCORES)] = 0;
		mScores[TERNARY_BUGFIX(4, MAX_HI_SCORES)] = 0;
	}

	void Initialise()
	{
		// This is illegal, you know.
		mScores[TERNARY_BUGFIX(0, MAX_HI_SCORES)] = 0;
		mScores[TERNARY_BUGFIX(1, MAX_HI_SCORES)] = 0;
		mScores[TERNARY_BUGFIX(2, MAX_HI_SCORES)] = 0;
		mScores[TERNARY_BUGFIX(3, MAX_HI_SCORES)] = 0;
		mScores[TERNARY_BUGFIX(4, MAX_HI_SCORES)] = 0;
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
		mFlags                 = 3;
		mBgmVol                = 8;
		mSfxVol                = 8;
		mFileNum               = 0;
		mHasSaveGame           = false;
		mMemCardSaveIndex      = 0;
		mSpareMemCardSaveIndex = 0;
		_1F                    = 0;
		mUnlockedStageFlags    = 0;
		mIsChanged             = false;
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
	bool mIsChanged;           ///< _14
	int mFlags;                ///< _18
	u8 mBgmVol;                ///< _1C
	u8 mSfxVol;                ///< _1D
	bool mHasSaveGame;         ///< _1E
	u8 _1F;                    ///< _1F
	u8 mMemCardSaveIndex;      ///< _20, index of save file on actual memory card + 1 (1-indexed).
	u8 mSpareMemCardSaveIndex; ///< _21, index of backup save file on actual memory card + 1 (1-indexed).
	u8 mUnlockedStageFlags;    ///< _22
	u8 _23;                    ///< _23
	GameHiscores mHiscores;    ///< _24
	u32 mSaveCount;            ///< _DC, unknown
	u32 _E0;                   ///< _E0
	u8 _E4[0x108 - 0xE4];      ///< _E4, unknown
	u32 mFileNum;              ///< _108, unknown
};

/**
 * @brief TODO
 */
struct GameFlow : public Node {

	/**
	 * @brief Global game state parameters, mostly around in-game time.
	 *
	 * This is gamePrms in Minty's Spreadsheet tm.
	 *
	 * @note Size: 0xD8.
	 */
	struct Parms : public Parameters {

		/// Constructs parameters - default values are overwritten on file read.
		inline Parms()
		    : mStartHour(this, 7.0f, 0.0f, 0.0f, "t00", "startHour")
		    , mEndHour(this, 19.0f, 0.0f, 0.0f, "t01", "endHour")
		    , mRealMinutesPerGameDay(this, 20.0f, 0.0f, 0.0f, "p00", "daySpeed")
		    , mMorningStart(this, 7.0f, 0.0f, 0.0f, "p01", "mornStart")
		    , mMorningMid(this, 8.0f, 0.0f, 0.0f, "s01", "mornMid")
		    , mMorningEnd(this, 9.0f, 0.0f, 0.0f, "p02", "mornEnd")
		    , mNightStart(this, 17.5f, 0.0f, 0.0f, "p03", "nightStart")
		    , mNightMid(this, 18.5f, 0.0f, 0.0f, "s03", "nightMid")
		    , mNightEnd(this, 19.5f, 0.0f, 0.0f, "p04", "nightEnd")
		    , mNightWarning(this, 16.0f, 0.0f, 0.0f, "p05", "nightWarning")
		    , mNightCountdown(this, 18.5f, 0.0f, 0.0f, "p06", "nightTimer")
		    , mTekiAbility(this, 1, 0, 0, "x99", "tekiAbility")
		    , mGameTitle(this, String("blah", 0), String("", 0), String("", 0), "x98", "gameTitle")
		{
		}

		// _00-_04 = Parameters
		Parm<f32> mStartHour;             ///< _04, t00 - time set to when entering stage at the start of the day.
		Parm<f32> mEndHour;               ///< _14, t01 - time when day ends and end-of-day sequence starts.
		Parm<f32> mRealMinutesPerGameDay; ///< _24, p00 - how many real-life minutes correspond to one (24-hr) in-game "day".
		Parm<f32> mMorningStart;          ///< _34, p01 - timesetting 0 end time (start blending from 0 to 1).
		Parm<f32> mMorningMid;            ///< _44, s01 - timesetting 1 time (start blending from 1 to 2).
		Parm<f32> mMorningEnd;            ///< _54, p02 - timesetting 2 start time (steady midday lighting).
		Parm<f32> mNightStart;            ///< _64, p03 - timesetting 2 end time (start blending from 2 to 3).
		Parm<f32> mNightMid;              ///< _74, s03 - timesetting 3 time (start blending from 3 to 0).
		Parm<f32> mNightEnd;              ///< _84, p04 - timesetting 0 start time.
		Parm<f32> mNightWarning;          ///< _94, p05 - Hurry Up! time.
		Parm<f32> mNightCountdown;        ///< _A4, p06 - time 10s countdown starts.
		Parm<int> mTekiAbility;           ///< _B4, x99 - unused.
		Parm<String> mGameTitle;          ///< _C4, x98 - P I K M I N (unused).
	};

	virtual void read(RandomAccessStream&); // _0C
	virtual void update();                  // _10

	void drawLoadLogo(Graphics& gfx, bool force60FPSSpin, Texture* logoTex, f32 alphaFactor);
	void menuToggleTimers(Menu& menu);
	void menuTogglePrint(Menu& menu);
	void menuToggleDInfo(Menu& menu);
	void menuToggleDExtra(Menu& menu);
	void menuToggleBlur(Menu& menu);
	void menuToggleInfo(Menu& menu);
	void menuToggleColls(Menu& menu);
	void menuChangeFilter(Menu& menu);
	void menuIncreaseFilter(Menu& menu);
	void menuDecreaseFilter(Menu& menu);
	Texture* setLoadBanner(immut char* texPath);
	void hardReset(BaseApp* baseApp);
	void softReset();
	Shape* loadShape(immut char* modelPath, bool checkCache);
	void addGenNode(immut char* name, CoreNode* node);

	// unused/inlined:

	void addOptionsMenu(Menu* parent);
	void addFilterMenu(Menu* parent);

	// _00     = VTBL
	// _00-_20 = Node
	Parms* mParameters;                 ///< _020, global (time-related) parameters, read from file.
	MemoryCard mMemoryCard;             ///< _024, active memory card.
	GamePrefs mGamePrefs;               ///< _094, global game preferences (options, save file, etc).
	u32 mSaveGameCrc;                   ///< _1A0, check-sum for save file.
	PlayState mPlayState;               ///< _1A4, basic trackable info to save to memory card.
	int mCurrentStageID;                ///< _1CC, current selected stage, to show ship at on next map screen - see `StageID` enum.
	int mPendingStageUnlockID;          ///< _1D0, unlock anim to play on next map screen - see `zen::DrawWorldMap::startModeFlag` enum.
	u32 _1D4;                           ///< _1D4, unused - set to 0 in hardReset but otherwise untouched.
	u32 mDemoFlags;                     ///< _1D8, game state flags during cutscenes - see `GameflowDemoFlags` enum.
	MoviePlayer* mMoviePlayer;          ///< _1DC, pointer to global movie/cutscene player.
	s16 mShipTextPartID;                ///< _1E0, ship part ID for the latest ship part collection or interaction text.
	s16 mShipTextType;                  ///< _1E2, type of ship-related text to display - see `ShipTextType` enum.
	s16 mIsDayEndActive;                ///< _1E4, is the end-of-day cutscene playing?
	s16 mIsDayEndTriggered;             ///< _1E6, is the end-of-day cutscene pending (for next time we're out of a menu etc)?
	GameInterface* mGameInterface;      ///< _1E8, message shuttle - upcast to `GameMovieInterface`/`TitlesMovieInterface` based on section.
	int mCurrGameSectionID;             ///< _1EC, see GameSectionID enum
	int mNextGameSectionID;             ///< _1F0, see GameSectionID enum
	s32 mNextOnePlayerSectionID;        ///< _1F4, see OnePlayerSectionID enum
	u8 _1F8[0x4];                       ///< _1F8, unknown/unused.
	int mLevelIndex;                    ///< _1FC, WHAT IS THIS???
	u32 _200;                           ///< _200, unknown/unused - set to zero then never referenced.
	Section* mGameSection;              ///< _204, pointer to current active game section.
	LangMode mLangModes[LANG_CAPACITY]; ///< _208, directories and paths for each language type - only 2 ever used (5 for PAL).
	int mLanguageIndex;                 ///< _2A8, current language mode selected (adult/child text mode for demo/JP).
	u32 mNextIntroMovieID;              ///< _2AC, idling title screen movie to play next - see `MovSampleID` enum.
	u32 mCurrIntroMovieID;              ///< _2B0, currently playing idling title screen movie - see `MovSampleID` enum.
	BOOL mIsChallengeMode;              ///< _2B4, whether we're in challenge mode (TRUE) or normal story mode (FALSE).
	u32 _2B8;                           ///< _2B8, unknown/unused - set to 0 and never touched.
	u32 mGenFlowUpdateTickCount;        ///< _2BC, counter for how many times the flow manager has been updated.
	f32 mLoadTimeSeconds;               ///< _2C0, how long the last load took, in seconds.
	f32 mCurrentEffectAlpha;            ///< _2C4, current load fade alpha when game state is "soft reset".
	vf32 mTargetEffectAlpha;            ///< _2C8, target load fade alpha when game state is "soft reset".
	f32 mEffectDurationTimer;           ///< _2CC, how long load fade should last, at most (unsure of this).
	int mAppTickCounter;                ///< _2D0, counter for number of frames game application has been active for.
	BOOL mIsNintendoLoadLogo;           ///< _2D4, is the load logo the Nintendo logo on bootup?
	WorldClock mWorldClock;             ///< _2D8, global in-game time tracker/calculator.
	f32 mTimeMultiplier;                ///< _304, multiplier for in-game time progression (always 1.0f).
	AnimFrameCacher* mFrameCacher;      ///< _308, global animation frame cacher, used primarily for pikmin animations.
	GameGenFlow* mFlowManager;          ///< _30C, flow manager that coordinates other global managers.
	Texture* mLevelBannerTex;           ///< _310, level banner texture to display when loading into a map.
	f32 mLevelBannerFadeValue;          ///< _314, factor to control the fade-in for the level banner.
	Texture* mLastLoadedBannerTex;      ///< _318, most recently loaded banner texture - ends up being a dupe of mLevelBannerTex.
	GameLoadIdler mGameLoadIdler;       ///< _31C, manager for drawing loading screens during gameplay.
	u8 _330[0x4];                       ///< _330, unknown/unused.
	BOOL mIsPauseAllowed;               ///< _334, whether pausing is enabled (false during cutscenes, end of day, etc).
	BOOL mIsUIOverlayActive;            ///< _338, whether a screen is active over the gameplay screen (ship text, menus, etc).
	BOOL mPauseAll;                     ///< _33C, whether gameplay is paused (due to cutscene or being in an onion menu).
	BOOL mIsTutorialTextActive;         ///< _340, whether a text ("tutorial") window is currently open.
	u8 _344[0x4];                       ///< _344, unknown/unused.
	u32 _348;                           ///< _348, unknown/unused - set to 0 and never touched.
	u32 _34C;                           ///< _34C, unknown/unused - set to 0 and never touched.
	int mFilterType;                    ///< _350, type of vertical filter values to apply - see `GameFilterType` enum.
	u8 mVFilters[FILTER_COUNT][8];      ///< _354, vertical filter values, indexed by `GameFilterType`. Only first 7 are used.
};

extern GameFlow gameflow;

/**
 * @brief Managing class for anything list-based that needs to update each frame (pikiMgr, naviMgr, etc).
 *
 * The nodes in this list are all managers of other lists.
 *
 * @note Size: 0x30.
 */
struct GameGenFlow : public Node {
	GameGenFlow(char* name)
	    : Node(name)
	{
		_24 = 332;
		_20 = 32;
		_28 = 1;
		_2C = 0;
	}

	/// Updates all nodes in its list (and enforces in-game time sync).
	virtual void update() // _10
	{
		gameflow.mGenFlowUpdateTickCount++;
		gameflow.mWorldClock.mRealSecsPerGameDay  = 60.0f * (gameflow.mTimeMultiplier * gameflow.mParameters->mRealMinutesPerGameDay());
		gameflow.mWorldClock.mRealSecsPerGameHour = gameflow.mWorldClock.mRealSecsPerGameDay / gameflow.mWorldClock.mHoursInDay;
		Node::update();
	}

	// _00     = VTBL
	// _00-_20 = Node
	int _20; ///< _20, unknown/unused - set to 32 on construction.
	int _24; ///< _24, unknown/unused - set to 332 on construction.
	int _28; ///< _28, unknown/unused - set to 1 on construction.
	u32 _2C; ///< _2C, unknown/unused - set to 0 on construction.
};

void preloadLanguage();

#endif
