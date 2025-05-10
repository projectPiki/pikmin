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
DEFINE_ERROR()

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
			rumbleMgr->start(0, 0, 0);
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
void GamePrefs::setChildMode(bool set)
{
	if (set != getChildMode()) {
		mIsChanged = true;
	}

	mFlags = (set ? GAMEPREF_Child : 0) | mFlags & ~GAMEPREF_Child;
}

/*
 * --INFO--
 * Address:	80053EC4
 * Size:	000068
 */
void GamePrefs::getChallengeScores(GameChalQuickInfo& info)
{
	for (int i = 0; i < 5; i++) {
		info.mCourseScores[i] = mHiscores.mChalModeRecords[info.mCourseID].mScores[i];
	}
}

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
	for (int i = 0; i < 5; i++) {
		PRINT("\t[%d] ... %d\n", i, mHiscores.mChalModeRecords[info.mCourseID].mScores[i]);
	}

	for (int i = 0; i < 5; i++) {
		if (info.mScore > mHiscores.mChalModeRecords[info.mCourseID].mScores[i]) {
			info.mRank = i;
			break;
		}
	}

	if (info.mRank >= 0 && info.mRank < 5) {
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

	for (int i = 0; i < 5; i++) {
		if (info.mParts > mHiscores.mMinDayRecords[i].mNumParts) {
			info.mPartsDaysRank = i;
			break;
		}

		if (info.mParts == mHiscores.mMinDayRecords[i].mNumParts && info.mDay <= mHiscores.mMinDayRecords[i].mNumDays) {
			info.mPartsDaysRank = i;
			break;
		}
	}

	if (info.mPartsDaysRank >= 0 && info.mPartsDaysRank < 5) {
		for (int i = 4; i > info.mPartsDaysRank; i--) {
			mHiscores.mMinDayRecords[i].mNumDays  = mHiscores.mMinDayRecords[i - 1].mNumDays;
			mHiscores.mMinDayRecords[i].mNumParts = mHiscores.mMinDayRecords[i - 1].mNumParts;
		}
		mHiscores.mMinDayRecords[info.mPartsDaysRank].mNumDays  = info.mDay;
		mHiscores.mMinDayRecords[info.mPartsDaysRank].mNumParts = info.mParts;
	}

	for (int i = 0; i < 5; i++) {
		if (info.mBornPikis > mHiscores.mBornPikminRecords[i].mNumBorn) {
			info.mBornPikisRank = i;
			break;
		}
	}

	if (info.mBornPikisRank >= 0 && info.mBornPikisRank < 5) {
		for (int i = 4; i > info.mBornPikisRank; i--) {
			mHiscores.mBornPikminRecords[i].mNumBorn = mHiscores.mBornPikminRecords[i - 1].mNumBorn;
		}
		mHiscores.mBornPikminRecords[info.mBornPikisRank].mNumBorn = info.mBornPikis;
	}

	// only check/update dead pikmin ranking if we finish the ship
	if (info.mParts == 30) {
		for (int i = 0; i < 5; i++) {
			if (info.mDeadPikis < mHiscores.mDeadPikminRecords[i].mNumDead) {
				info.mDeadPikisRank = i;
				break;
			}
		}
	}

	if (info.mDeadPikisRank >= 0 && info.mDeadPikisRank < 5) {
		for (int i = 4; i > info.mDeadPikisRank; i--) {
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
	u32 mode = OSGetSoundMode(); // lol
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
}

/*
 * --INFO--
 * Address:	8005494C
 * Size:	0000F4
 */
void PlayState::write(RandomAccessStream& output)
{
	output.writeByte(_20);
	output.writeByte(mSaveFlags);
	output.writeByte(_21);
	output.writeByte(_22);
	output.writeInt(_14);
	output.writeInt(_18);
	output.writeInt(_1C);
	output.writeInt(mCourseOpenFlags);
}

/*
 * --INFO--
 * Address:	80054A40
 * Size:	0000F4
 */
void PlayState::read(RandomAccessStream& input)
{
	_20              = input.readByte();
	mSaveFlags       = input.readByte();
	_21              = input.readByte();
	_22              = input.readByte();
	_14              = input.readInt();
	_18              = input.readInt();
	_1C              = input.readInt();
	mCourseOpenFlags = input.readInt();
}
