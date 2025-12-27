#include "DebugLog.h"
#include "Dolphin/os.h"
#include "OnePlayerSection.h"
#include "RumbleMgr.h"
#include "gameFlow.h"
#include "jaudio/interface.h"
#include "system.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GamePrefs")

/**
 * @todo: Documentation
 */
void PlayState::openStage(int stageId)
{
	if (stageId < STAGE_START) {
		return;
	}

	if (stageId > STAGE_END) {
		return;
	}

	if (!(mCourseOpenFlags & (1 << stageId))) {
		gameflow.mPendingStageUnlockID = stageId;
	}

	mCourseOpenFlags |= (1 << stageId);
}

// This is a weak inline in US but a full function in PAL
#if defined(VERSION_GPIP01_00)
void GamePrefs::Initialise()
{
	mFlags            = 3;
	gsys->mLanguageID = LANG_English;

	LanguageID ids[] = {
		LANG_English, // OS English
		LANG_German,  // OS German
		LANG_French,  // OS French
		LANG_Spanish, // OS Spanish
		LANG_Italian, // OS Italian
		LANG_English  // OS Dutch
	};

	STACK_PAD_VAR(3);
	setChildMode(ids[OSGetLanguage()]);
	mBgmVol             = 8;
	mSfxVol             = 8;
	mFileNum            = 0;
	mHasSaveGame        = 0;
	mSaveGameIndex      = 0;
	mSpareSaveGameIndex = 0;
	_1F                 = 0;
	mUnlockedStageFlags = 0;
	mIsChanged          = false;
	mHiscores.Initialise();
}
#endif

/**
 * @todo: Documentation
 */
void GamePrefs::setBgmVol(u8 vol)
{
	if (vol != mBgmVol) {
		mIsChanged = true;
	}
	mBgmVol = vol;
	Jac_SetBGMVolume(mBgmVol);
}

/**
 * @todo: Documentation
 */
void GamePrefs::setSfxVol(u8 vol)
{
	if (vol != mSfxVol) {
		mIsChanged = true;
	}
	mSfxVol = vol;
	Jac_SetSEVolume(mSfxVol);
}

/**
 * @todo: Documentation
 */
void GamePrefs::setStereoMode(bool set)
{
	if (set != getStereoMode()) {
		mIsChanged = true;
	}

	mFlags = (set ? GAMEPREF_Stereo : 0) | mFlags & ~GAMEPREF_Stereo;

	Jac_OutputMode((mFlags & GAMEPREF_Stereo) ? 1 : 0);
	OSSetSoundMode(set);
}

/**
 * @todo: Documentation
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
		mIsChanged = true;
	}

	mFlags = (set ? GAMEPREF_Vibe : 0) | mFlags & ~GAMEPREF_Vibe;
	PRINT("setting rumbleMgr : %s\n", set ? "ON" : "OFF");

	rumbleMgr->rumbleOption(set);
}

/**
 * @todo: Documentation
 */
#if defined(VERSION_GPIP01_00)
#else
void GamePrefs::setChildMode(bool set)
{
	if (set != getChildMode()) {
		mIsChanged = true;
	}

	mFlags = (set ? GAMEPREF_Child : 0) | mFlags & ~GAMEPREF_Child;
}
#endif

/**
 * @todo: Documentation
 */
void GamePrefs::getChallengeScores(GameChalQuickInfo& info)
{
	for (int i = 0; i < MAX_HI_SCORES; i++) {
		info.mCourseScores[i] = mHiscores.mChalModeRecords[info.mCourseID].mScores[i];
	}
}

/**
 * @todo: Documentation
 */
void GamePrefs::checkIsHiscore(GameChalQuickInfo& info)
{
	info.mRank         = -1;
	gsys->mTogglePrint = 1;
#if defined(VERSION_PIKIDEMO)
	// This somehow doesn't generate a function call.  How.
	_Print("checking challenge info for course %d, top scores are :-\n", info.mCourseID);
#else
	PRINT("checking challenge info for course %d, top scores are :-\n", info.mCourseID);
#endif
	for (int i = 0; i < MAX_HI_SCORES; i++) {
#if defined(VERSION_PIKIDEMO)
		// This somehow doesn't generate a function call.  How.
		_Print("\t[%d] ... %d\n", i, mHiscores.mChalModeRecords[info.mCourseID].mScores[i]);
#else
		PRINT("\t[%d] ... %d\n", i, mHiscores.mChalModeRecords[info.mCourseID].mScores[i]);
#endif
	}

	for (int i = 0; i < MAX_HI_SCORES; i++) {
		if (info.mScore > mHiscores.mChalModeRecords[info.mCourseID].mScores[i]) {
			info.mRank = i;
			break;
		}
	}

	if (info.mRank >= 0 && info.mRank < MAX_HI_SCORES) {
		for (int i = 4; i > info.mRank; i--) {
			mHiscores.mChalModeRecords[info.mCourseID].mScores[i] = mHiscores.mChalModeRecords[info.mCourseID].mScores[i - 1];
		}
		mHiscores.mChalModeRecords[info.mCourseID].mScores[info.mRank] = info.mScore;
	}

	gsys->mTogglePrint = 0;
	getChallengeScores(info);
}

/**
 * @todo: Documentation
 */
void GamePrefs::checkIsHiscore(GameQuickInfo& info)
{
	PRINT("checking if (%d parts/ day %d) : born %d pikis, dead %d pikis is in hiscore\n", info.mParts, info.mDay, info.mBornPikis,
	      info.mDeadPikis);
	info.mBornPikisRank = -1;
	info.mDeadPikisRank = -1;
	info.mPartsDaysRank = -1;

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

	if (info.mPartsDaysRank >= 0 && info.mPartsDaysRank < MAX_HI_SCORES) {
		for (int i = (MAX_HI_SCORES - 1); i > info.mPartsDaysRank; i--) {
			mHiscores.mMinDayRecords[i].mNumDays  = mHiscores.mMinDayRecords[i - 1].mNumDays;
			mHiscores.mMinDayRecords[i].mNumParts = mHiscores.mMinDayRecords[i - 1].mNumParts;
		}
		mHiscores.mMinDayRecords[info.mPartsDaysRank].mNumDays  = info.mDay;
		mHiscores.mMinDayRecords[info.mPartsDaysRank].mNumParts = info.mParts;
	}

	for (int i = 0; i < MAX_HI_SCORES; i++) {
		if (info.mBornPikis > mHiscores.mBornPikminRecords[i].mNumBorn) {
			info.mBornPikisRank = i;
			break;
		}
	}

	if (info.mBornPikisRank >= 0 && info.mBornPikisRank < MAX_HI_SCORES) {
		for (int i = (MAX_HI_SCORES - 1); i > info.mBornPikisRank; i--) {
			mHiscores.mBornPikminRecords[i].mNumBorn = mHiscores.mBornPikminRecords[i - 1].mNumBorn;
		}
		mHiscores.mBornPikminRecords[info.mBornPikisRank].mNumBorn = info.mBornPikis;
	}

	// only check/update dead pikmin ranking if we finish the ship
	if (info.mParts == MAX_UFO_PARTS) {
		for (int i = 0; i < MAX_HI_SCORES; i++) {
			if (info.mDeadPikis < mHiscores.mDeadPikminRecords[i].mNumDead) {
				info.mDeadPikisRank = i;
				break;
			}
		}
	}

	if (info.mDeadPikisRank >= 0 && info.mDeadPikisRank < 5) {
		for (int i = (MAX_HI_SCORES - 1); i > info.mDeadPikisRank; i--) {
			mHiscores.mDeadPikminRecords[i].mNumDead = mHiscores.mDeadPikminRecords[i - 1].mNumDead;
		}
		mHiscores.mDeadPikminRecords[info.mDeadPikisRank].mNumDead = info.mDeadPikis;
	}
}

/**
 * @todo: Documentation
 */
void GamePrefs::write(RandomAccessStream& output)
{
	PRINT("writing game prefs\n");
	output.writeInt(mFlags);
	output.writeByte(mBgmVol);
	output.writeByte(mSfxVol);
	output.writeByte(mUnlockedStageFlags);

	mHiscores.write(output);

	mIsChanged = false;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void GamePrefs::read(RandomAccessStream& input)
{
	PRINT("reading game prefs\n");
	mFlags              = input.readInt();
	mBgmVol             = input.readByte();
	mSfxVol             = input.readByte();
	mUnlockedStageFlags = input.readByte();
	mHiscores.read(input);

	fixSoundMode();

	PRINT("got hardFlags %08x : bgmVol %d : sfxVol %d\n", mFlags, mBgmVol, mSfxVol);
	PRINT("got total pikis = %d\n", mHiscores.mTotalPikis);
	setBgmVol(getBgmVol());
	setSfxVol(getSfxVol());
	setStereoMode(getStereoMode());
	setVibeMode(getVibeMode());
#if defined(VERSION_PIKIDEMO)
	STACK_PAD_VAR(1);
#endif
#if defined(VERSION_GPIP01_00)
	STACK_PAD_VAR(2);
	LanguageID lang = (LanguageID)(mFlags >> 2 & 0xF);
	if (lang < LANG_English || lang > LANG_Italian) {
		// invalid language choice
		lang = LANG_English;
	}
	gsys->mLanguageID = lang;
#endif
}

#if defined(VERSION_GPIP01_00)
int GamePrefs::getChildMode()
{
	int id = mFlags >> 2 & 0xf;
	if (id < 0 || id > 4) {
		PRINT("trying to get invalid language mode!!\n");
		return 0;
	}
	return id;
}
#endif

#if defined(VERSION_GPIP01_00)
void GamePrefs::setChildMode(int set)
{
	if (set != getChildMode()) {
		mIsChanged = true;
	}

	if (set < LANG_MIN || set > LANG_MAX) {
		OSReport("trying to set invalid language mode (%d)!!\n", set);
		set = LANG_English;
	}

	STACK_PAD_VAR(1);

	gsys->mLanguageID = (LanguageID)set;
	mFlags            = mFlags & 0xffffffc3 | (set & 0xf) << 2;
}
#endif

/**
 * @todo: Documentation
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
 * @todo: Documentation
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
