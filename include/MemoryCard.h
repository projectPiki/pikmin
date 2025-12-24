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
