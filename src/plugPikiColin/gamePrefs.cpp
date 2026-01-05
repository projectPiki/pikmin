#include "gameflow.h"

#include "DebugLog.h"
#include "Dolphin/os.h"
#include "OnePlayerSection.h"
#include "RumbleMgr.h"
#include "jaudio/interface.h"
#include "system.h"

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GamePrefs")

/**
 * @brief Unlocks a given story mode stage, including queueing up the relevant stage unlock animation on the map screen.
 *
 * @param stageID ID of the story mode stage to unlock - see `StageID` enum.
 */
void PlayState::openStage(int storyStageID)
{
	if (storyStageID < STAGE_START) {
		return;
	}

	if (storyStageID > STAGE_TESTMAP) {
		return;
	}

	if (!IS_STAGE_OPEN(mCourseOpenFlags, storyStageID)) {
		// we haven't opened this stage before, queue up the sparkly new area animation next world map screen
		gameflow.mPendingStageUnlockID = storyStageID;
	}

	SET_STAGE_OPEN(mCourseOpenFlags, storyStageID);
}

// This is a weak inline in US but a full function in PAL
#if defined(VERSION_GPIP01_00)
/**
 * @brief Initialises game preferences with basic default values.
 */
void GamePrefs::Initialise()
{
	mFlags            = GAMEPREF_Vibe | GAMEPREF_Stereo;
	gsys->mLanguageID = LANG_English;

	LanguageID ids[] = {
		LANG_English, // OS English
		LANG_German,  // OS German
		LANG_French,  // OS French
		LANG_Spanish, // OS Spanish
		LANG_Italian, // OS Italian
		LANG_English  // OS Dutch
	};

	setChildMode(ids[OSGetLanguage()]);
	mBgmVol                = 8;
	mSfxVol                = 8;
	mMostRecentFileSlot    = 0;
	mHasSaveGame           = false;
	mMemCardSaveIndex      = 0;
	mSpareMemCardSaveIndex = 0;
	_1F                    = 0;
	mChalCourseOpenFlags   = 0;
	mChangesPending        = false;
	mHiscores.Initialise();
}
#endif

/**
 * @brief Sets background music volume.
 *
 * @param vol Volume value to set.
 */
void GamePrefs::setBgmVol(u8 vol)
{
	if (vol != mBgmVol) {
		mChangesPending = true;
	}
	mBgmVol = vol;
	Jac_SetBGMVolume(mBgmVol);
}

/**
 * @brief Sets sound effects volume.
 *
 * @param vol Volume value to set.
 */
void GamePrefs::setSfxVol(u8 vol)
{
	if (vol != mSfxVol) {
		mChangesPending = true;
	}
	mSfxVol = vol;
	Jac_SetSEVolume(mSfxVol);
}

/**
 * @brief Sets sound to stereo or mono mode.
 *
 * @param set True = set to stereo, false = set to mono.
 */
void GamePrefs::setStereoMode(bool set)
{
	if (set != getStereoMode()) {
		mChangesPending = true;
	}

	mFlags = (set ? GAMEPREF_Stereo : 0) | mFlags & ~GAMEPREF_Stereo;

	Jac_OutputMode((mFlags & GAMEPREF_Stereo) ? 1 : 0);
	OSSetSoundMode(set);
}

/**
 * @brief Sets rumble on or off.
 *
 * @param set True = set to on, false = set to off.
 */
void GamePrefs::setVibeMode(bool set)
{
	if (set != getVibeMode()) {
		if (set) {
			PRINT("bbrrrrr\n"); // lol
			rumbleMgr->start(RUMBLE_Unk0, 0, nullptr);
		} else {
			rumbleMgr->stop();
		}
		mChangesPending = true;
	}

	mFlags = (set ? GAMEPREF_Vibe : 0) | mFlags & ~GAMEPREF_Vibe;
	PRINT("setting rumbleMgr : %s\n", set ? "ON" : "OFF");

	rumbleMgr->rumbleOption(set);
}

#if defined(VERSION_GPIP01_00)
/**
 * @brief Gets language preference - PAL exclusive version.
 *
 * @return Language mode - see `LanguageID` enum.
 */
int GamePrefs::getChildMode()
{
	int lang = UNPACK_LANG_FLAG(mFlags);
	if (lang < LANG_MIN || lang > LANG_MAX) {
		PRINT("trying to get invalid language mode!!\n");
		// default to English
		return LANG_English;
	}
	return lang;
}
/**
 * @brief Sets language preference - PAL exclusive version.
 *
 * @param lang Language mode to set - see `LanguageID` enum.
 */
void GamePrefs::setChildMode(int lang)
{
	if (lang != getChildMode()) {
		mChangesPending = true;
	}

	if (lang < LANG_MIN || lang > LANG_MAX) {
		OSReport("trying to set invalid language mode (%d)!!\n", lang);
		lang = LANG_English;
	}

	STACK_PAD_VAR(1);

	gsys->mLanguageID = (LanguageID)lang;
	mFlags            = PACK_LANG_FLAG(mFlags, lang);
}

#else
/**
 * @brief Sets language mode to child or adult - there's no difference outside of JP (and demo?).
 *
 * @param set True = set to child, false = set to adult.
 */
void GamePrefs::setChildMode(bool set)
{
	if (set != getChildMode()) {
		mChangesPending = true;
	}

	mFlags = (set ? GAMEPREF_Child : 0) | mFlags & ~GAMEPREF_Child;
}
#endif

/**
 * @brief Gets all existing challenge mode hiscores for a given course.
 *
 * @param info Challenge mode info to save hiscores to - must have its mStageID set to the right course.
 */
void GamePrefs::getChallengeScores(GameChalQuickInfo& info)
{
	for (int i = 0; i < MAX_HI_SCORES; i++) {
		info.mCourseScores[i] = mHiscores.mChalModeRecords[info.mStageID].mScores[i];
	}
}

/**
 * @brief Checks if a given challenge mode score is a hiscore for that course, and updates the info and hiscores if so.
 *
 * @param info Challenge mode info to check score of, and store rank to - must have its mStageID and mScore set.
 */
void GamePrefs::checkIsHiscore(GameChalQuickInfo& info)
{
	info.mRank         = -1;
	gsys->mTogglePrint = TRUE; // "you're gonna wanna hear about this"

#if defined(VERSION_PIKIDEMO)
	// This somehow doesn't generate a function call.  How.
	_Print("checking challenge info for course %d, top scores are :-\n", info.mStageID);
#else
	PRINT("checking challenge info for course %d, top scores are :-\n", info.mStageID);
#endif

	for (int i = 0; i < MAX_HI_SCORES; i++) {
#if defined(VERSION_PIKIDEMO)
		// This somehow doesn't generate a function call.  How.
		_Print("\t[%d] ... %d\n", i, mHiscores.mChalModeRecords[info.mStageID].mScores[i]);
#else
		PRINT("\t[%d] ... %d\n", i, mHiscores.mChalModeRecords[info.mStageID].mScores[i]);
#endif
	}

	// check if score is better than any existing hiscores - if so, store its appropriate rank
	for (int i = 0; i < MAX_HI_SCORES; i++) {
		if (info.mScore > mHiscores.mChalModeRecords[info.mStageID].mScores[i]) {
			info.mRank = i;
			break;
		}
	}

	// if we got a new hiscore, shift the current scores and store the new one
	if (info.mRank >= 0 && info.mRank < MAX_HI_SCORES) {
		for (int i = 4; i > info.mRank; i--) {
			mHiscores.mChalModeRecords[info.mStageID].mScores[i] = mHiscores.mChalModeRecords[info.mStageID].mScores[i - 1];
		}
		mHiscores.mChalModeRecords[info.mStageID].mScores[info.mRank] = info.mScore;
	}

	gsys->mTogglePrint = FALSE; // "back to scheduled programming"

	// update the leaderboard stored in the quick info
	getChallengeScores(info);
}

/**
 * @brief Checks if given story mode scores are a hiscore in any category, and updates the info and hiscores if so.
 *
 * @param info Story mode scores to check and store rank to - must have scores already filled out.
 */
void GamePrefs::checkIsHiscore(GameQuickInfo& info)
{
	PRINT("checking if (%d parts/ day %d) : born %d pikis, dead %d pikis is in hiscore\n", info.mParts, info.mDay, info.mBornPikis,
	      info.mDeadPikis);

	info.mBornPikisRank = -1;
	info.mDeadPikisRank = -1;
	info.mPartsDaysRank = -1;

	// check parts and days - priority is parts, then break ties with lower day count
	for (int i = 0; i < MAX_HI_SCORES; i++) {
		if (info.mParts > mHiscores.mMinDayRecords[i].mNumParts) {
			info.mPartsDaysRank = i;
			break;
		}

		if (info.mParts == mHiscores.mMinDayRecords[i].mNumParts && info.mDay <= mHiscores.mMinDayRecords[i].mNumDays) {
			info.mPartsDaysRank = i;
			break;
		}
	}

	// check if we got a new parts/days hiscore, if so update the hiscores!
	if (info.mPartsDaysRank >= 0 && info.mPartsDaysRank < MAX_HI_SCORES) {
		for (int i = (MAX_HI_SCORES - 1); i > info.mPartsDaysRank; i--) {
			mHiscores.mMinDayRecords[i].mNumDays  = mHiscores.mMinDayRecords[i - 1].mNumDays;
			mHiscores.mMinDayRecords[i].mNumParts = mHiscores.mMinDayRecords[i - 1].mNumParts;
		}
		mHiscores.mMinDayRecords[info.mPartsDaysRank].mNumDays  = info.mDay;
		mHiscores.mMinDayRecords[info.mPartsDaysRank].mNumParts = info.mParts;
	}

	// check born pikmin for a new hiscore
	for (int i = 0; i < MAX_HI_SCORES; i++) {
		if (info.mBornPikis > mHiscores.mBornPikminRecords[i].mNumBorn) {
			info.mBornPikisRank = i;
			break;
		}
	}

	// if we got a new born pikmin hiscore, update them!
	if (info.mBornPikisRank >= 0 && info.mBornPikisRank < MAX_HI_SCORES) {
		for (int i = (MAX_HI_SCORES - 1); i > info.mBornPikisRank; i--) {
			mHiscores.mBornPikminRecords[i].mNumBorn = mHiscores.mBornPikminRecords[i - 1].mNumBorn;
		}
		mHiscores.mBornPikminRecords[info.mBornPikisRank].mNumBorn = info.mBornPikis;
	}

	// NOTE: we only check/update dead pikmin ranking if we finish the ship!
	if (info.mParts == MAX_UFO_PARTS) {
		for (int i = 0; i < MAX_HI_SCORES; i++) {
			if (info.mDeadPikis < mHiscores.mDeadPikminRecords[i].mNumDead) {
				info.mDeadPikisRank = i;
				break;
			}
		}
	}

	// if we got a new dead pikmin hiscore (lowscore), update them!
	if (info.mDeadPikisRank >= 0 && info.mDeadPikisRank < MAX_HI_SCORES) {
		for (int i = (MAX_HI_SCORES - 1); i > info.mDeadPikisRank; i--) {
			mHiscores.mDeadPikminRecords[i].mNumDead = mHiscores.mDeadPikminRecords[i - 1].mNumDead;
		}
		mHiscores.mDeadPikminRecords[info.mDeadPikisRank].mNumDead = info.mDeadPikis;
	}
}

/**
 * @brief Write global preferences to file stream (to memory card).
 *
 * @param output File stream (to memory card) to write preferences to.
 */
void GamePrefs::write(RandomAccessStream& output)
{
	PRINT("writing game prefs\n");
	output.writeInt(mFlags);
	output.writeByte(mBgmVol);
	output.writeByte(mSfxVol);
	output.writeByte(mChalCourseOpenFlags);

	mHiscores.write(output);

	mChangesPending = false;
}

/**
 * @brief Sync stereo/mono setting to GameCube OS setting.
 */
void GamePrefs::fixSoundMode()
{
#if defined(VERSION_PIKIDEMO)
	_Print("fixing stereo mode to %s\n", OSGetSoundMode() ? "Stereo" : "Mono");
#else
	PRINT("fixing stereo mode to %s\n", OSGetSoundMode() ? "Stereo" : "Mono");
#endif
	setStereoMode(OSGetSoundMode());
}

/**
 * @brief Read global preferences from file stream (from memory card).
 *
 * @param input File stream (from memory card) to read preferences from.
 */
void GamePrefs::read(RandomAccessStream& input)
{
	PRINT("reading game prefs\n");
	mFlags               = input.readInt();
	mBgmVol              = input.readByte();
	mSfxVol              = input.readByte();
	mChalCourseOpenFlags = input.readByte();
	mHiscores.read(input);

	// adjust stereo/mono based on OS (in case we don't have stereo)
	fixSoundMode();

	PRINT("got hardFlags %08x : bgmVol %d : sfxVol %d\n", mFlags, mBgmVol, mSfxVol);
	PRINT("got total pikis = %d\n", mHiscores.mTotalPikis);

	// force update all options
	setBgmVol(getBgmVol());
	setSfxVol(getSfxVol());
	setStereoMode(getStereoMode());
	setVibeMode(getVibeMode());

#if defined(VERSION_PIKIDEMO)
	STACK_PAD_VAR(1);
#endif

#if defined(VERSION_GPIP01_00)
	STACK_PAD_VAR(2);
	LanguageID lang = (LanguageID)(UNPACK_LANG_FLAG(mFlags));
	if (lang < LANG_English || lang > LANG_Italian) {
		// invalid language choice
		lang = LANG_English;
	}

	// sync with system language
	gsys->mLanguageID = lang;
#endif
}

/**
 * @brief Writes play information to file stream (memory card).
 *
 * @param output File stream (to memory card) to write to.
 */
void PlayState::write(RandomAccessStream& output)
{
	output.writeByte(mSaveStatus);
	output.writeByte(mSaveSlot);
	output.writeByte(mSavedDay);
	output.writeByte(mShipPartsCount);
	output.writeInt(mRedPikiCount);
	output.writeInt(mYellowPikiCount);
	output.writeInt(mBluePikiCount);
	output.writeInt(mCourseOpenFlags);
}

/**
 * @brief Reads play information from file stream (memory card).
 *
 * @param input File stream (from memory card) to read from.
 */
void PlayState::read(RandomAccessStream& input)
{
	mSaveStatus      = input.readByte();
	mSaveSlot        = input.readByte();
	mSavedDay        = input.readByte();
	mShipPartsCount  = input.readByte();
	mRedPikiCount    = input.readInt();
	mYellowPikiCount = input.readInt();
	mBluePikiCount   = input.readInt();
	mCourseOpenFlags = input.readInt();
}
