#ifndef _MEMORYCARD_H
#define _MEMORYCARD_H

#include "types.h"
#include "CoreNode.h"

struct CARDStat;
struct PlayState;
struct RamStream;

extern u8 cardData[];

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct CardQuickInfo {
	CardQuickInfo() { mIsSelected = 0; }

	int mIndex;             // _00
	u32 mFlags;             // _04
	u32 mIsSelected;        // _08, guessed name, not entirely sure
	int mCurrentDay;        // _0C
	int mCurrentPartsCount; // _10
	int mRedPikiCount;      // _14
	int mYellowPikiCount;   // _18
	int mBluePikiCount;     // _1C
	int _20;                // _20
	u32 mCrc;               // _24
};

/**
 * @brief TODO
 */
struct MemoryCard : public CoreNode {
	inline MemoryCard()
	    : CoreNode("memoryCard")
	{
		mTempFileIndex     = -1;
		mCardChannel       = -1;
		mSaveFileIndex     = -1;
		mRequiredFreeSpace = 0x26000;
		mErrorCode         = 0;
	}

	int getOptionsOffset(int);
	int getGameFileOffset(int);
	u32 calcChecksum(void*, u32);
	bool hasCardFinished();
	bool attemptFormatCard(int);
	s32 waitWhileBusy(int);
	bool getCardStatus(int);
	void checkUseFile();
	s32 getMemoryCardState(bool);
	void loadCurrentFile();
	s32 getNewestOptionsIndex();
	void loadOptions();
	void saveOptions();
	void loadCurrentGame();
	void saveCurrentGame();
	void writeCurrentGame(RandomAccessStream*, PlayState&);
	void readCurrentGame(RandomAccessStream*);
	void initBannerArea(CARDStat&, char*);
	void initOptionsArea(int);
	s32 makeDefaultFile();
	void copyFile(CardQuickInfo&, CardQuickInfo&);
	void delFile(CardQuickInfo&);
	int doFormatCard();
	bool isCardInserted();
	bool hasCardChanged();
	u32 getOkSections();
	bool isFileBroken();
	void repairFile();
	bool didSaveFail();
	void getQuickInfos(CardQuickInfo*);
	void init();

	// unused/inlined:
	void GetBlockSize(s32);
	void* getBannerPtr();
	void* getOptionsPtr(int);
	void* getGameFilePtr(int);
	RamStream* getBannerStream();
	RamStream* getOptionsStream(int);
	RamStream* getGameFileStream(int);
	void waitPolling();
	void createFile(CARDStat&);
	void writeOneBanner();
	void writeOneOption(int);
	void writeOneGameFile(int);
	void initFileArea(int, int);
	void breakFile();

	// _00     = VTBL
	// _00-_14 = CoreNode
	char mFilePath[32];     // _14
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
	int _UNUSED6C;                // _6C
};

#endif
