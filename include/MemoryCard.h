#ifndef _MEMORYCARD_H
#define _MEMORYCARD_H

#include "CoreNode.h"
#include "types.h"

struct CARDStat;
struct PlayState;
struct RamStream;

#define CARD_DATA_SIZE (0x26000)

extern u8 cardData[CARD_DATA_SIZE];

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct CardQuickInfo {
	CardQuickInfo() { mSaveStatus = 0; }

	int mMemCardSaveIndex;   ///< _00, index of save file on actual memory card (0-indexed).
	u32 mGameSaveSlot;       ///< _04, save slot used in game (0-2).
	u32 mSaveStatus;         ///< _08, whether a fresh file or used - see `PlayState::SaveStatus` enum.
	int mCurrentDay;         ///< _0C, current (saved) in-game day.
	int mCurrentPartsCount;  ///< _10, current (saved) collected ship parts count.
	int mRedPikiCount;       ///< _14, current (saved) red pikmin count.
	int mYellowPikiCount;    ///< _18, current (saved) yellow pikmin count.
	int mBluePikiCount;      ///< _1C, current (saved) blue pikmin count.
	int mMostRecentSaveSlot; ///< _20, latest created/saved slot (0-indexed).
	u32 mCrc;                ///< _24, checksum of save file.
};

/**
 * @brief TODO
 */
struct MemoryCard : public CoreNode {
public:
	inline MemoryCard()
	    : CoreNode("memoryCard")
	{
		mTempFileIndex     = -1;
		mCardChannel       = -1;
		mSaveFileIndex     = -1;
		mRequiredFreeSpace = CARD_DATA_SIZE;
		mErrorCode         = 0;
	}

	void init();
	bool hasCardFinished();
	s32 getMemoryCardState(bool);
	s32 getNewestOptionsIndex();

	void loadOptions();
	void saveOptions();
	void loadCurrentGame();
	void saveCurrentGame();

	s32 makeDefaultFile();
	void copyFile(CardQuickInfo&, CardQuickInfo&);
	void delFile(CardQuickInfo&);
	int doFormatCard();

	bool isCardInserted();
	bool hasCardChanged();
	bool isFileBroken();
	void breakFile();
	void repairFile();
	bool didSaveFail();
	void getQuickInfos(CardQuickInfo*);

protected:
	u32 calcChecksum(void*, u32);
	void waitPolling();
	void createFile(CARDStat&);
	void writeOneBanner();
	void writeOneOption(int);
	void writeOneGameFile(int);
	bool attemptFormatCard(int);
	s32 waitWhileBusy(int);
	bool getCardStatus(int);
	void checkUseFile();
	void loadCurrentFile();

	void writeCurrentGame(RandomAccessStream*, PlayState&);
	void readCurrentGame(RandomAccessStream*);

	void initBannerArea(CARDStat&, immut char*);
	void initFileArea(int, int);
	void initOptionsArea(int);

	u32 getOkSections();
	int getOptionsOffset(int);
	int getGameFileOffset(int);
	void GetBlockSize(s32);
	void* getBannerPtr();
	void* getOptionsPtr(int);
	void* getGameFilePtr(int);
	void* FAKE_getGameFilePtr(int); // FAKE FAKE FAKE FAKE IT SHOULDN'T NEED TO EXIST
	RamStream* getBannerStream();
	RamStream* getOptionsStream(int);
	RamStream* getGameFileStream(int);

public:
	// _00     = VTBL
	// _00-_14 = CoreNode
	char mFilePath[32];     // _14, Not present in the DLL.
	int mCardChannel;       // _34
	int mSaveFileIndex;     // _38
	int mTempFileIndex;     // _3C
	u32 mRequiredFreeSpace; // _40
	u32 mErrorCode;         // _44
	u32 mOkSectionsMask;    // _48
	BOOL mValidSlots[4];    // _4C
	int mValidBlockCount;   // _5C
	int mValidOptionsCount; // _60
	u32 mSectorSize;        // _64
	bool mDidSaveFail;      // _68
	int _UNUSED6C;          // _6C
};

#endif
