#include "gameFlow.h"
#include "OnePlayerSection.h"
#include "jaudio/interface.h"
#include "Dolphin/os.h"
#include "RumbleMgr.h"
#include "system.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("GamePrefs")

/*
 * --INFO--
 * Address:	80053C5C
 * Size:	000040
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
		gameflow.mLastUnlockedStageId = stageId;
	}

	mCourseOpenFlags |= (1 << stageId);
}

// This is a weak inline in US but a full function in PAL
#if defined(VERSION_GPIP01_00)
void GamePrefs::Initialise()
{
	mFlags     = 3;
	gsys->_1A0 = 0;
	int ids[]  = { 0, 2, 1, 3, 4, 0 };
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

/*
 * --INFO--
 * Address:	80053C9C
 * Size:	000040
 */
void GamePrefs::setBgmVol(u8 vol)
{
	if (vol != mBgmVol) {
		mIsChanged = true;
	}
	mBgmVol = vol;
	Jac_SetBGMVolume(mBgmVol);
}

/*
 * --INFO--
 * Address:	80053CDC
 * Size:	000040
 */
void GamePrefs::setSfxVol(u8 vol)
{
	if (vol != mSfxVol) {
		mIsChanged = true;
	}
	mSfxVol = vol;
	Jac_SetSEVolume(mSfxVol);
}

/*
 * --INFO--
 * Address:	80053D1C
 * Size:	00009C
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

/*
 * --INFO--
 * Address:	80053DB8
 * Size:	0000B8
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

/*
 * --INFO--
 * Address:	80053E70
 * Size:	000054
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

/*
 * --INFO--
 * Address:	80053EC4
 * Size:	000068
 */
void GamePrefs::getChallengeScores(GameChalQuickInfo& info)
{
	for (int i = 0; i < MAX_HI_SCORES; i++) {
		info.mCourseScores[i] = mHiscores.mChalModeRecords[info.mCourseID].mScores[i];
	}
}

// the print statements in checkIsHiscore aren't emitted, but the strings somehow end up in .data
// not sure how, so this is just a bandaid fix.
#if defined(VERSION_G98E01_PIKIDEMO)
static char unusedUSADemo1[] = "checking challenge info for course %d, top scores are :-\n";
static char unusedUSADemo2[] = "\t[%d] ... %d\n";
#endif

/*
 * --INFO--
 * Address:	80053F2C
 * Size:	000174
 */
void GamePrefs::checkIsHiscore(GameChalQuickInfo& info)
{
	info.mRank         = -1;
	gsys->mTogglePrint = 1;
	PRINT("checking challenge info for course %d, top scores are :-\n", info.mCourseID);
	for (int i = 0; i < MAX_HI_SCORES; i++) {
		PRINT("\t[%d] ... %d\n", i, mHiscores.mChalModeRecords[info.mCourseID].mScores[i]);
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

/*
 * --INFO--
 * Address:	800540A0
 * Size:	00034C
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

/*
 * --INFO--
 * Address:	800543EC
 * Size:	000178
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

/*
 * --INFO--
 * Address:	80054564
 * Size:	0000B8
 */
void GamePrefs::fixSoundMode()
{
#if defined(VERSION_DPIJ01_PIKIDEMO) || defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_G98P01_PIKIDEMO)
	_Print("fixing stereo mode to %s\n", OSGetSoundMode() ? "Stereo" : "Mono");
#else
	PRINT("fixing stereo mode to %s\n", OSGetSoundMode() ? "Stereo" : "Mono");
#endif
	setStereoMode(OSGetSoundMode());
}

/*
 * --INFO--
 * Address:	8005461C
 * Size:	000330
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
#if defined(VERSION_G98E01_PIKIDEMO)
	STACK_PAD_VAR(1);
#endif
#if defined(VERSION_GPIP01_00)
	STACK_PAD_VAR(2);
	int lang = mFlags >> 2 & 0xf;
	if (lang < 0 || lang > 4) {
		lang = 0;
	}
	gsys->_1A0 = lang;
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

	if (set < 0 || set > 4) {
		OSReport("trying to set invalid language mode (%d)!!\n", set);
		set = 0;
	}

	STACK_PAD_VAR(1);

	gsys->_1A0 = set;
	mFlags     = mFlags & 0xffffffc3 | (set & 0xf) << 2;
}
#endif

/*
 * --INFO--
 * Address:	8005494C
 * Size:	0000F4
 */
void PlayState::write(RandomAccessStream& output)
{
	output.writeByte(mSaveStatus);
	output.writeByte(mSaveFlags);
	output.writeByte(mSavedDay);
	output.writeByte(mShipPartsCount);
	output.writeInt(mRedPikiCount);
	output.writeInt(mYellowPikiCount);
	output.writeInt(mBluePikiCount);
	output.writeInt(mCourseOpenFlags);
}

/*
 * --INFO--
 * Address:	80054A40
 * Size:	0000F4
 */
void PlayState::read(RandomAccessStream& input)
{
	mSaveStatus      = input.readByte();
	mSaveFlags       = input.readByte();
	mSavedDay        = input.readByte();
	mShipPartsCount  = input.readByte();
	mRedPikiCount    = input.readInt();
	mYellowPikiCount = input.readInt();
	mBluePikiCount   = input.readInt();
	mCourseOpenFlags = input.readInt();
}
