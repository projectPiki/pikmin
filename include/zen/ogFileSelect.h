#ifndef _ZEN_OGFILESELECT_H
#define _ZEN_OGFILESELECT_H

#include "Colour.h"
#include "MemoryCard.h"
#include "P2D/TextBox.h"
#include "Vector.h"
#include "stl/string.h"
#include "types.h"
#include "zen/SpectrumCursorMgr.h"
#include "zen/ogSub.h"

struct Controller;
struct CardQuickInfo;
struct Graphics;
struct P2DPicture;
struct P2DTextBox;

namespace zen {

struct EffectMgr2D;
struct ogNitakuMgr;
struct particleGenerator;

/**
 * @brief Converts special numeric codes within P2DTextBox strings. Used for dynamic text elements e.g. file numbers in prompts.
 *
 * @note Size: 0x108.
 */
struct ogCnvStringMgr {
	ogCnvStringMgr(P2DTextBox* tbox)
	{
		mTextBox = tbox;
		mTextPtr = tbox->getString();
	}

	// DLL inline
	void convert()
	{
		strcpy(mTextBuffer, mTextPtr);
		cnvSpecialNumber(mTextBuffer);
		mTextBox->setString(mTextBuffer);
	}

	P2DTextBox* mTextBox;    // _00
	char* mTextPtr;          // _04
	char mTextBuffer[0x100]; // _08
};

/**
 * @brief Manages the file selection screen, including display, user interaction,
 *		  and coordination of file operations (load, save, copy, delete).
 *
 * @note Size: 0x11A4.
 */
struct ogScrFileSelectMgr {

	/**
	 * @brief Defines the current operation mode for file management.
	 */
	enum FileOperateMode {
		Normal = 0, // Standard file selection mode
		Copy   = 1, // File copying mode
		Delete = 2  // File deletion mode
	};

	/**
	 * @brief Flags indicating which title message to display.
	 */
	enum titleMessageFlag {
		SelectDataToLoadOrSave = 0, // Message for selecting a file to load or save
		SelectDataToSave,           // Message for selecting a file to save
		DataCorrupted,              // Message indicating data is corrupted
		NoMemoryCardInserted,       // Message indicating no memory card is inserted
		MemoryCardErrorOccurred,    // Message indicating a memory card error
		SelectSourceFileForCopy,    // Message for selecting the source file for copying
		ConfirmFileCopy,            // Message to confirm file copy, possibly with overwrite
		SelectFileForDelete,        // Message for selecting a file to delete
		ConfirmFileDelete,          // Message to confirm file deletion
		FormattingInProgress,       // Message indicating memory card formatting is in progress
		FormatComplete,             // Message indicating memory card formatting is complete
		SaveFailedError,            // Message indicating save operation failed
		SaveSuccessful,             // Message indicating save operation was successful
		MemoryCardFullError,        // Message indicating the memory card is full
	};

	/**
	 * @brief Defines the return status of the file select manager's update function, indicating the next action for the game flow.
	 */
	enum FileSelectUpdateResult {
		Inactive = -1,  // No action required, or initial state
		Continue,       // Continue updating the file select screen
		FileChosen,     // A file has been chosen (e.g., for loading/saving)
		ExitRequested,  // User requested to exit the file select screen (e.g., cancel)
		OperationError, // An error occurred during a file operation
		// Missing 4
		// Missing 5
		PostSaveAction = 6, // Action after a save operation (e.g., refresh screen)
		PostDeleteAction,   // Action after a delete operation (e.g., refresh screen)
		PostCopyAction,     // Action after a copy operation (e.g., refresh screen)
		CardBusy,           // Memory card is busy, waiting for completion
		ReturnToIPL,        // Request to return to the Initial Program Loader (IPL) or title screen
	};

	ogScrFileSelectMgr();

	void copyCardInfosSub();
	bool getCardFileInfos();
	void paneOnOffXY(bool isVisible);
	void MovePaneXY();
	void OpenYesNoWindow();
	void CloseYesNoWindow();
	void setOperateMode(FileOperateMode mode);
	void getPane_FileTop1();
	void getPane_FileTop2();
	void setFileData(int fileSlotIndex);
	void getPane_FileIcon();
	void OnOffKetaNissuu(int fileSlotIndex);
	void getPane_CpyCurScreen();
	void SetTitleMsg(titleMessageFlag msgId);
	void setDataNumber(int fileSlotIndex);
	void chaseDataScale();
	void OnOffNewPane(int fileSlotIndex);
	void ChkOnyonOnOff();
	void ChkNewData();
	void start(bool isSaveMode, int fileSelectMode);
	void OperateSelect(Controller* pController);
	void KetteiEffectStart();
	void TailEffectStart();
	FileSelectUpdateResult update(Controller* pController, CardQuickInfo& outCardInfo);
	void draw(Graphics& gfx);

	void setOperateMode_Copy();
	void CopyEffectStart();
	void OperateCopy(Controller* pController);

	void setOperateMode_Delete();
	void OperateDelete(Controller* pController);

	// unused/inlined:
	void UpDateYesNoWindow();
	void setOperateMode_Normal();
	void set_SM_C();
	void ScaleAnimeTitle();
	void ScaleAnimeData();
	void init();
	void setDataScale();
	void BeginFadeOut();
	int CanToCopy(int sourceSlotIndex);
	void TailEffectMove(int x, int y);
	void TailEffectMoveM(int x, int y);
	void quit();
	void MoveCpyCursor(int targetSlotIndex, f32 animationSpeed);
	void DeleteEffectStart();

	EffectMgr2D* mFxMgr;                                   // _00
	particleGenerator* mFileCopyEffectOnyon;               // _04
	particleGenerator* mFileCopyEffectPikminGroup;         // _08
	particleGenerator* mSelectionConfirmEffectOnyon;       // _0C
	particleGenerator* mSelectionConfirmEffectPikminGroup; // _10
	particleGenerator* mCursorMoveEffectOnyon;             // _14
	particleGenerator* mCursorMoveEffectPikminGroup;       // _18
	u8 _UNUSED1C[0x4];                                     // _1C, unknown
	FileSelectUpdateResult mSelectState;                   // _20
	FileOperateMode mOperation;                            // _24
	bool mSaveMode;                                        // _28
	CardQuickInfo mCardInfo[3];                            // _2C
	SpectrumCursorMgr mCopyLeftCursor;                     // _A4
	SpectrumCursorMgr mCopyRightCursor;                    // _D4
	f32 mCopyCursorLPosX[3];                               // _104
	f32 mCopyCursorRPosX[3];                               // _110
	f32 mCopyCursorLPosY[3];                               // _11C
	f32 mCopyCursorRPosY[3];                               // _128
	s16 mCurrSlotIdx;                                      // _134
	f32 mIconDataScales[3];                                // _138
	f32 mIconNoDataScales[3];                              // _144
	f32 mMainInteractTimer;                                // _150
	int mMaxPartsNum;                                      // _154
	int mOnyonIconPositionsX[3];                           // _158
	int mOnyonIconPositionsY[3];                           // _164
	int mNewIconPositionsX[3];                             // _170
	int mNewIconPositionsY[3];                             // _17C
	Vector3f mOnyonIconScales[3];                          // _188
	Vector3f mNewIconScales[3];                            // _1AC
	int mOnyonIconCurrX[3];                                // _1D0
	int mOnyonIconCurrY[3];                                // _1DC
	int mPikminIconCurrX[3];                               // _1E8
	int mPikminIconCurrY[3];                               // _1F4
	int mNewIconInitX[3];                                  // _200
	int mNewIconInitY[3];                                  // _20C
	int mNewIconCurrX[3];                                  // _218
	int mNewIconCurrY[3];                                  // _224
	int mEmptyIconInitX[3];                                // _230
	int mEmptyIconInitY[3];                                // _23C
	int mEmptyIconCurrX[3];                                // _248
	int mEmptyIconCurrY[3];                                // _254
	ogCnvStringMgr* mStrCnvDataCorrupt;                    // _260
	ogCnvStringMgr* mStrCnvConfirmCopy;                    // _264
	ogCnvStringMgr* mStrCnvFormatComplete;                 // _268
	ogNitakuMgr* mNitaku;                                  // _26C
	int mMainRootPaneTargetPosX;                           // _270
	int mPositioningPaneTargetPosX;                        // _274
	bool mIsLayoutActive;                                  // _278
	titleMessageFlag mTitleMsg;                            // _27C
	f32 mFadeOutTimer;                                     // _280
	u8 mIsFadingOut;                                       // _284
	f32 mTitleAnimationTimer;                              // _288
	u8 mIsTitleAnimating;                                  // _28C
	u8 mIsDataAnimating;                                   // _28D
	f32 mDataAnimationTimer;                               // _290
	int mYesNoWindowChoice;                                // _294
	int mTailEffectCounter;                                // _298
	P2DScreen* mSlotScreensData[3];                        // _29C
	P2DScreen* mSlotScreensNoData[3];                      // _2A8
	P2DScreen* mMainUIScreen;                              // _2B4
	P2DScreen* mFileInfoScreen;                            // _2B8
	P2DScreen* mCopyCursorsScreen;                         // _2BC
	P2DScreen* mBlackOverlayScreen;                        // _2C0
	P2DPane* mRootPane;                                    // _2C4
	P2DPane* mPosPane;                                     // _2C8
	P2DPicture* mCardAccessIcon;                           // _2CC
	P2DPicture* mYesNoDialogImage;                         // _2D0
	P2DTextBox* mYesNoDialogPromptText;                    // _2D4
	P2DPane* mYesNoDialogPane;                             // _2D8
	P2DPane* mTitleTextBasePane;                           // _2DC
	P2DTextBox* mNitakuYesText;                            // _2E0
	P2DTextBox* mNitakuNoText;                             // _2E4
	P2DPane* mPromptSelectSavePane;                        // _2E8
	P2DPane* mPromptNoCardPane;                            // _2EC
	P2DPane* mPromptCardErrPane;                           // _2F0
	P2DPane* mPromptSelectCopySrcPane;                     // _2F4
	P2DPane* mOpInProgressPane;                            // _2F8
	P2DPane* mPromptConfirmDelPane;                        // _2FC
	P2DPane* mOpCompletePane;                              // _300
	P2DPane* mPromptSaveFailPane;                          // _304
	P2DPane* mPromptSaveOKPane;                            // _308
	P2DPane* mPromptCardFullPane;                          // _30C
	P2DTextBox* mCorruptText;                              // _310
	P2DTextBox* mConfirmCopyText;                          // _314
	P2DTextBox* mFormatDoneText;                           // _318
	P2DTextBox* mAltMsgText1;                              // _31C
	P2DTextBox* mAltMsgText2;                              // _320
	P2DTextBox* mAltMsgText3;                              // _324
	P2DPane* mFileInfoPane1;                               // _328
	P2DPane* mFileInfoPane2;                               // _32C
	P2DPane* mFileInfoPane3;                               // _330
	P2DPane* mAllFileInfoPane;                             // _334
	P2DPane* mPartsTensPane;                               // _338
	P2DPane* mPartsUnitsPane;                              // _33C
	P2DPane* mTotalPartsTensPane;                          // _340
	P2DPane* mTotalPartsUnitsPane;                         // _344
	P2DPane* mRedPikiHundPane;                             // _348
	P2DPane* mRedPikiTensPane;                             // _34C
	P2DPane* mRedPikiUnitsPane;                            // _350
	P2DPane* mBluePikiHundPane;                            // _354
	P2DPane* mBluePikiTensPane;                            // _358
	P2DPane* mBluePikiUnitsPane;                           // _35C
	P2DPane* mYellowPikiHundPane;                          // _360
	P2DPane* mYellowPikiTensPane;                          // _364
	P2DPane* mYellowPikiUnitsPane;                         // _368
	P2DPane* mRedPikiInfoPane;                             // _36C
	P2DPane* mBluePikiInfoPane;                            // _370
	P2DPane* mYellowPikiInfoPane;                          // _374
	P2DPane* mNavInfoPane;                                 // _378
	P2DPane* mTopNewDataIconPane;                          // _37C
	P2DPane* mIconNoDataRootPanes[3];                      // _380
	P2DPane* mIconDataRootPanes[3];                        // _38C
	P2DPane* mIconNewPanes[3];                             // _398
	P2DPane* mIconEmptyPanes[3];                           // _3A4
	P2DPane* mIconOnyonPanes[3];                           // _3B0
	P2DPane* mIconPikminPanes[3];                          // _3BC
	P2DPane* mIconFxAnchorPanes[3];                        // _3C8
	P2DPane* mIconOnyonDestPanes[3];                       // _3D4
	P2DPane* mIconPikminDestPanes[3];                      // _3E0
	P2DPane* mDayCount1DigitPane[3];                       // _3E0
	P2DPicture* mDayCount1DigitPic[3];                     // _3F8
	P2DPane* mDayCount2DigitLPane[3];                      // _404
	P2DPane* mDayCount2DigitRPane[3];                      // _410
	P2DPicture* mDayCount2DigitLPic[3];                    // _41C
	P2DPicture* mDayCount2DigitRPic[3];                    // _428
	P2DPicture* mDayCountColorSrcPic[3];                   // _434
	P2DPane* mSlotNormalPane;                              // _440
	P2DPane* mSlotNewPane;                                 // _444
	P2DPane* mOperationCursorsScreenPane;                  // _448
	P2DPicture* mDeleteCursorPicture;                      // _44C
	u8 _UNUSED450[0x6C];                                   // _450, unknown
	SpectrumCursorMgr mDeleteLeftCursor;                   // _4BC
	u8 _UNUSED4EC[0x10];                                   // _4EC, unknown
	SpectrumCursorMgr mDeleteRightCursor;                  // _4FC
	u8 _UNUSED52C[0x10];                                   // _52C, unknown
	f32 mTailEffectMoveTimer;                              // _53C
	u8 _UNUSED540[0xC];                                    // _540
	f32 mSelectionChangeTimer;                             // _54C
	Colour mColorNormalFile;                               // _550
	Colour mColorSelectedFile;                             // _554
	Colour mColorNoDataFile;                               // _558
	Colour mColorNoDataSelectedFile;                       // _55C
	u8 _UNUSED560[0xC20];                                  // _560, unknown
	u8 mIsSelectionConfirmEffectActive;                    // _1180
	f32 mSelectionConfirmEffectTimer;                      // _1184
	f32 mTailEffectSpawnTimer;                             // _1188
	f32 mCopyAnimTimer;                                    // _118C
	u8 mFileSlotSelectionStates[3];                        // _1190
	u8 mIsTailMoveEffectActive;                            // _1193
	u8 mActiveTailMoveEffectsCount;                        // _1194
	u8 mCanCreateNewFile;                                  // _1195
	u8 mMemoryCardCheckState;                              // _1196
	u8 mIsCopyingFileActive;                               // _1197
	u8 mIsCopyCompleteMessageActive;                       // _1198
	u8 mIsDeletingFileActive;                              // _1199
	int mCopyTargetFileIndex;                              // _119C
	u8 mIsCopyTargetSelectionActive;                       // _11A0
};

} // namespace zen

#endif
