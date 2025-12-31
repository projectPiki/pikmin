#include "DebugLog.h"
#include "PlayerState.h"
#include "ResultFlags.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(5)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("resultFlag");

ResultFlags::FlagInfo ResultFlags::flagTable[] = {
	// .blo index, auto-enable, priority, store type
	{ zen::RESFLAG_EndFirstDay, false, 1, ResultFlags::FlagInfo::Store_Forget },               // End of Day 1
	{ zen::RESFLAG_FirstVisitForest, false, 3, ResultFlags::FlagInfo::Store_Forget },          // First Visit Forest of Hope
	{ zen::RESFLAG_UnlockCave, false, 9, ResultFlags::FlagInfo::Store_Forget },                // Open Forest Navel
	{ zen::RESFLAG_FirstVisitCave, false, 10, ResultFlags::FlagInfo::Store_Forget },           // First Visit Forest Navel
	{ zen::RESFLAG_UnlockYakushima, false, 11, ResultFlags::FlagInfo::Store_Forget },          // Open Distant Spring
	{ zen::RESFLAG_FirstVisitYakushima, false, 12, ResultFlags::FlagInfo::Store_Reset },       // First Visit Distant Spring
	{ zen::RESFLAG_FinalDay, false, 13, ResultFlags::FlagInfo::Store_Forget },                 // Final Day
	{ zen::RESFLAG_Collect25Parts, false, 14, ResultFlags::FlagInfo::Store_Forget },           // 25 parts
	{ zen::RESFLAG_Collect29Parts, false, 15, ResultFlags::FlagInfo::Store_Forget },           // 29 parts
	{ zen::RESFLAG_OlimarDown, false, 5, ResultFlags::FlagInfo::Store_Reset },                 // Olimar down
	{ zen::RESFLAG_PikminExtinction, false, 4, ResultFlags::FlagInfo::Store_Reset },           // Pikmin extinction
	{ zen::RESFLAG_CollectAllParts, false, 2, ResultFlags::FlagInfo::Store_Forget },           // All 30 parts (unused)
	{ zen::RESFLAG_YellowWithBomb, false, 6, ResultFlags::FlagInfo::Store_Reset },             // Yellow Pikmin with bomb
	{ zen::RESFLAG_MeetBluePikmin, false, 7, ResultFlags::FlagInfo::Store_Forget },            // Meet Blue Pikmin
	{ zen::RESFLAG_PikminRouting, false, 16, ResultFlags::FlagInfo::Store_Keep },              // Pikmin Routing
	{ zen::RESFLAG_OlimarDaydream, false, 19, ResultFlags::FlagInfo::Store_Reset },            // Olimar's Daydream
	{ zen::RESFLAG_Collect15Parts, false, 20, ResultFlags::FlagInfo::Store_Reset },            // 15 parts
	{ zen::RESFLAG_PikminLeftBehind, false, 8, ResultFlags::FlagInfo::Store_Reset },           // Pikmin left behind
	{ zen::RESFLAG_PikminBombDeath, false, 17, ResultFlags::FlagInfo::Store_Reset },           // Pikmin dies to bomb rock
	{ zen::RESFLAG_Collect10Parts, false, 18, ResultFlags::FlagInfo::Store_Keep },             // 10 parts
	{ zen::RESFLAG_UnusedControls1, true, 200, ResultFlags::FlagInfo::Store_Keep },            // Unused Controls log 1
	{ zen::RESFLAG_UnusedControls2, false, 201, ResultFlags::FlagInfo::Store_Keep },           // Unused Controls log 2
	{ zen::RESFLAG_UnusedControls3, true, 202, ResultFlags::FlagInfo::Store_Keep },            // Unused Controls log 3
	{ zen::RESFLAG_BrokenBridge, false, 203, ResultFlags::FlagInfo::Store_Forget },            // Broken Bridge
	{ zen::RESFLAG_PikminSeeds, false, 204, ResultFlags::FlagInfo::Store_Keep },               // Pikmin seeds
	{ zen::RESFLAG_PikminSeedStageUp, false, 205, ResultFlags::FlagInfo::Store_Keep },         // Pikmin seed grows up
	{ zen::RESFLAG_Onyons, false, 207, ResultFlags::FlagInfo::Store_Keep },                    // Pikmin onions
	{ zen::RESFLAG_MeetYellowPikminNoBomb, false, 206, ResultFlags::FlagInfo::Store_Forget },  // Meet Yellow Pikmin (no bombs)
	{ zen::RESFLAG_BluePikminWaterImmunity, false, 208, ResultFlags::FlagInfo::Store_Forget }, // Blue Pikmin touch water (unused)
	{ zen::RESFLAG_PikminOnFire, false, 209, ResultFlags::FlagInfo::Store_Forget },            // Pikmin on fire
	{ zen::RESFLAG_Dororo, false, 400, ResultFlags::FlagInfo::Store_Reset },                   // Smoky Progg
	{ zen::RESFLAG_Swallow, false, 401, ResultFlags::FlagInfo::Store_Reset },                  // Bulborb
	{ zen::RESFLAG_Kinoko, false, 402, ResultFlags::FlagInfo::Store_Reset },                   // Puffstool
	{ zen::RESFLAG_Kogane, false, 403, ResultFlags::FlagInfo::Store_Reset },                   // Flint Beetle
	{ zen::RESFLAG_Mizinko, false, 404, ResultFlags::FlagInfo::Store_Reset },                  // Honeywisp
	{ zen::RESFLAG_Pom, false, 405, ResultFlags::FlagInfo::Store_Reset },                      // Candypop Bud
	{ zen::RESFLAG_Spider, false, 406, ResultFlags::FlagInfo::Store_Reset },                   // Beady Long Legs
	{ zen::RESFLAG_Beatle, false, 407, ResultFlags::FlagInfo::Store_Reset },                   // Armored Cannon Beetle
	{ zen::RESFLAG_Snake, false, 408, ResultFlags::FlagInfo::Store_Reset },                    // Burrowing Snagret
	{ zen::RESFLAG_King, false, 409, ResultFlags::FlagInfo::Store_Reset },                     // Emperor Bulblax
	{ zen::RESFLAG_Slime, false, 410, ResultFlags::FlagInfo::Store_Reset },                    // Goolix
	{ zen::RESFLAG_Miurin, false, 411, ResultFlags::FlagInfo::Store_Reset },                   // Mamuta
	{ zen::RESFLAG_Kabekui, false, 412, ResultFlags::FlagInfo::Store_Reset },                  // Sheargrub
	{ zen::RESFLAG_Tank, false, 413, ResultFlags::FlagInfo::Store_Reset },                     // Fiery Blowhog
	{ zen::RESFLAG_Shell, false, 414, ResultFlags::FlagInfo::Store_Reset },                    // Pearly Clamclamp
	{ zen::RESFLAG_Collec, false, 415, ResultFlags::FlagInfo::Store_Reset },                   // Breadbug
	{ zen::RESFLAG_Mar, false, 416, ResultFlags::FlagInfo::Store_Reset },                      // Puffy Blowhog
	{ zen::RESFLAG_Otimoti, false, 417, ResultFlags::FlagInfo::Store_Reset },                  // Wollywog
	{ zen::RESFLAG_Misc1, true, 600, ResultFlags::FlagInfo::Store_Keep },                      // Misc 1
	{ zen::RESFLAG_Misc2, true, 601, ResultFlags::FlagInfo::Store_Keep },                      // Misc 2
	{ zen::RESFLAG_Misc3, true, 602, ResultFlags::FlagInfo::Store_Keep },                      // Misc 3
	{ zen::RESFLAG_Misc4, true, 603, ResultFlags::FlagInfo::Store_Keep },                      // Misc 4
	{ zen::RESFLAG_Misc5, true, 604, ResultFlags::FlagInfo::Store_Keep },                      // Misc 5
	{ zen::RESFLAG_Misc6, true, 605, ResultFlags::FlagInfo::Store_Keep },                      // Misc 6
	{ zen::RESFLAG_Misc7, true, 606, ResultFlags::FlagInfo::Store_Keep },                      // Misc 7
	{ zen::RESFLAG_Misc8, true, 607, ResultFlags::FlagInfo::Store_Keep },                      // Misc 8
	{ zen::RESFLAG_Misc9, true, 608, ResultFlags::FlagInfo::Store_Keep },                      // Misc 9
	{ zen::RESFLAG_Misc10, true, 609, ResultFlags::FlagInfo::Store_Keep },                     // Misc 10
	{ zen::RESFLAG_Misc11, true, 610, ResultFlags::FlagInfo::Store_Keep },                     // Misc 11
	{ zen::RESFLAG_Misc12, true, 611, ResultFlags::FlagInfo::Store_Keep },                     // Misc 12
	{ zen::RESFLAG_Misc13, true, 612, ResultFlags::FlagInfo::Store_Keep },                     // Misc 13
	{ zen::RESFLAG_Misc14, true, 613, ResultFlags::FlagInfo::Store_Keep },                     // Misc 14
	{ zen::RESFLAG_Misc15, true, 614, ResultFlags::FlagInfo::Store_Keep },                     // Misc 15
	{ zen::RESFLAG_Misc16, true, 615, ResultFlags::FlagInfo::Store_Keep },                     // Misc 16
	{ zen::RESFLAG_Misc17, true, 616, ResultFlags::FlagInfo::Store_Keep },                     // Misc 17
	{ zen::RESFLAG_Misc18, true, 617, ResultFlags::FlagInfo::Store_Keep },                     // Misc 18
	{ zen::RESFLAG_Misc19, true, 618, ResultFlags::FlagInfo::Store_Keep },                     // Misc 19
	{ zen::RESFLAG_Misc20, true, 619, ResultFlags::FlagInfo::Store_Keep },                     // Misc 20
	{ zen::RESFLAG_Misc21, true, 620, ResultFlags::FlagInfo::Store_Keep },                     // Misc 21
	{ zen::RESFLAG_Misc22, true, 621, ResultFlags::FlagInfo::Store_Keep },                     // Misc 22
	{ zen::RESFLAG_Misc23, true, 622, ResultFlags::FlagInfo::Store_Keep },                     // Misc 23
	{ zen::RESFLAG_Misc24, true, 623, ResultFlags::FlagInfo::Store_Keep },                     // Misc 24
	{ zen::RESFLAG_Misc25, true, 624, ResultFlags::FlagInfo::Store_Keep },                     // Misc 25
	{ zen::RESFLAG_Misc26, true, 625, ResultFlags::FlagInfo::Store_Keep },                     // Misc 26
	{ zen::RESFLAG_Misc27, true, 626, ResultFlags::FlagInfo::Store_Keep },                     // Misc 27
	{ zen::RESFLAG_NULL, 0, 0, 0 },                                                            // END
};

/**
 * @todo: Documentation
 */
ResultFlags::ResultFlags()
{
	int max    = 38;
	mLength    = max;
	mTableSize = mLength << 2;

	mScreenToTableList = new u32[max + 110];
	mActiveCount       = 0;
	mStates            = new u8[mLength];
	for (int i = 0; i < mLength; i++) {
		mStates[i] = false;
	}

	for (int i = 0; i < mTableSize; i++) {
		if (flagTable[i].mScreenId == -1) {
			break;
		}

		mScreenToTableList[flagTable[i].mScreenId] = i;

		if (flagTable[i].mIsAutoSet) {
			setOn(flagTable[i].mScreenId);
		}

		mActiveCount++;
	}

	for (int i = 0; i < MAX_DAYS; i++) {
		mDaysSeen[i] = -1;
	}

	// don't display these ones
	setSeen(zen::RESFLAG_UnusedControls1);
	setSeen(zen::RESFLAG_UnusedControls2);
	setSeen(zen::RESFLAG_UnusedControls3);
	setSeen(zen::RESFLAG_BluePikminWaterImmunity);
}

/**
 * @todo: Documentation
 */
void ResultFlags::initGame()
{
	for (int i = 0; i < mLength; i++) {
		mStates[i] = false;
	}

	for (int i = 0; i < mTableSize; i++) {
		if (flagTable[i].mScreenId == -1) {
			break;
		}
		mScreenToTableList[flagTable[i].mScreenId] = i;

		if (flagTable[i].mIsAutoSet) {
			setOn(flagTable[i].mScreenId);
		}
	}

	for (int i = 0; i < MAX_DAYS; i++) {
		mDaysSeen[i] = -1;
	}

	setSeen(zen::RESFLAG_UnusedControls1);
	setSeen(zen::RESFLAG_UnusedControls2);
	setSeen(zen::RESFLAG_UnusedControls3);
	setSeen(zen::RESFLAG_BluePikminWaterImmunity);
}

/**
 * @todo: Documentation
 */
void ResultFlags::saveCard(RandomAccessStream& stream)
{
	int i = 0;
	for (i = 0; i < mLength; i++) {
		stream.writeByte(mStates[i]);
	}

	for (i = 0; i < MAX_DAYS; i++) {
		stream.writeShort(mDaysSeen[i]);
	}
}

/**
 * @todo: Documentation
 */
void ResultFlags::loadCard(RandomAccessStream& stream)
{
	int i = 0;
	for (i = 0; i < mLength; i++) {
		mStates[i] = stream.readByte();
	}

	for (i = 0; i < MAX_DAYS; i++) {
		mDaysSeen[i] = stream.readShort();
	}
}

/**
 * @todo: Documentation
 */
void ResultFlags::setOn(int flag)
{
	if (!getFlag(flag)) {
		setFlag(flag, 1);
	}
}

/**
 * @todo: Documentation
 */
void ResultFlags::setSeen(int flag)
{
	setFlag(flag, 2);
}

/**
 * @todo: Documentation
 */
int ResultFlags::getDayDocument(int dayIndex, int& length)
{
	int id = mDaysSeen[dayIndex];
	if (id == -1) {
		length = 0;
		return -1;
	}

	for (int i = 0; i < mActiveCount; i++) {
		int currentId = flagTable[i].mScreenId;

		if (currentId == id) {
			if (flagTable[i + 1].mScreenId == -1) {
				length = 1;
				return currentId;
			}

			length = flagTable[i + 1].mScreenId - flagTable[i].mScreenId;
			return currentId;
		}
	}

	length = 0;
	return -1;
}

/**
 * @todo: Documentation
 */
int ResultFlags::getDocument(int& pageCount)
{
	int minimumPriority = 128000;
	int index           = -1;

	for (int i = 0; i < mActiveCount; i++) {
		int id = flagTable[i].mScreenId;
		if (getFlag(id) == true && minimumPriority > flagTable[i].mPriority) {
			minimumPriority = flagTable[i].mPriority;
			index           = i;
		}
	}

	if (index != -1) {
		if (flagTable[index + 1].mScreenId == -1) {
			pageCount = 1;
		} else {
			pageCount = flagTable[index + 1].mScreenId - flagTable[index].mScreenId;
		}

		setFlag(flagTable[index].mScreenId, 2);

		for (int i = 0; i < mActiveCount; i++) {
			int id = flagTable[i].mScreenId;
			if (getFlag(id) == true) {
				switch (flagTable[i].mStore) {
				case FlagInfo::Store_Forget:
					setFlag(id, 2);
					break;
				case FlagInfo::Store_Reset:
					setFlag(id, 0);
					break;
				}
			}
		}

		mDaysSeen[playerState->getCurrDay()] = flagTable[index].mScreenId;
		return flagTable[index].mScreenId;

	} else {
		dump();
		ERROR("cannot happen !\n");
		return -1;
	}

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
int ResultFlags::FlagInfo::type()
{
	if (mPriority < 200) {
		return 0;
	}
	if (mPriority < 400) {
		return 200;
	}
	if (mPriority < 600) {
		return 400;
	}
	return 600;
}

/**
 * @todo: Documentation
 */
void ResultFlags::dump()
{
	int prev = 0;
	int p    = 0;
	PRINT("******* CURRENT RESULT FLAGS STATUS ***********\n");
	for (int i = 0; i < mTableSize; i++) {
		FlagInfo& info = flagTable[i];
		if (info.mScreenId == -1) {
			break;
		}

		// For some God-forsaken reason, the devs decided to micro-optimize this code to do different things between the DLL and the DOL.
#if defined(DEVELOP) || defined(WIN32)
		const char* strs[4];
		strs[3] = nullptr;

		switch (info.type()) {
		case 0:
			strs[3] = "GEN";
			break;
		case 200:
			strs[3] = "SET";
			break;
		case 400:
			strs[3] = "TEK";
			break;
		case 600:
			strs[3] = "ETC";
			break;
		}
#endif

		if (prev != flagTable[i].type()) {
			p    = 0;
			prev = flagTable[i].type();
		}
		prev = flagTable[i].type();

#if defined(DEVELOP) || defined(WIN32)
		strs[0] = "OFF";
		strs[1] = "ON";
		strs[2] = "SEEN";
#else
		// It genuinely has to be written this way to match retail.  Reusing the above char* array and preprocessor block does not work.
		const char* strs[3] = { "OFF", "ON", "SEEN" };
		STACK_PAD_INLINE(1);
#endif

		// So as a result of all that, the final game version this PRINT contains brazen (but stripped) undefined behavior (`strs[3]`).
		PRINT(" ENUM_RESULT_%s_G%02d_P00 = %s : %d pages\n", strs[3], p++, strs[getFlag(flagTable[i].mScreenId)],
		      (flagTable[i + 1].mScreenId == -1) ? 1 : flagTable[i + 1].mScreenId - info.mScreenId);
	}
	PRINT("*************************************************\n");
}

/**
 * @todo: Documentation
 */
u8 ResultFlags::getFlag(int index)
{
	int a = mScreenToTableList[index];
	int b = a >> 2;
	return mStates[b] >> ((a - b * 4) * 2) & 3;
}

/**
 * @todo: Documentation
 */
void ResultFlags::setFlag(int index, u8 flag)
{
	int tableIdx = mScreenToTableList[index];
	int b        = tableIdx >> 2;
	int c        = tableIdx - 4 * (b);
	u8 newFlag   = mStates[b];

	if (flag & 1) {
		newFlag |= (1 << c * 2);
	} else {
		newFlag &= ~(1 << c * 2);
	}

	if (flag & 2) {
		newFlag |= (1 << c * 2 + 1);
	} else {
		newFlag &= ~(1 << c * 2 + 1);
	}

	mStates[b] = newFlag;
}
